// Skill.cpp: implementation of the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Skill.h"
#include "CharacterChild.h"				// 2005-07-21 by ispark
#include "AtumApplication.h"
#include "ShuttleChild.h"
#include "Chat.h"
#include "AtumDatabase.h"
#include "SkillInfo.h"
#include "StoreData.h"
#include "FieldWinSocket.h"
#include "INFGameMain.h"
#include "INFSkill.h"
#include "SceneData.h"
#include "EnemyData.h"
#include "SkillEffect.h"
#include "ClientParty.h"
#include "StoreData.h"
#include "ItemInfo.h"
#include "dxutil.h"
#include "INFInvenExtend.h"
#include "QuestData.h"					// 2014-02-19 by ymjoo 퀘스트 스크립트 추가 - 아이템 사용

// 2008-12-29 by bhsohn 사망 시 버프 스킬 유지 시스템
#define		TERM_TICK_MUST_SERVER_CHECK_SKILL_DEADSTAT_REATTACK_TIME		60000	// (1000(1초)*60초(1분))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkill::CSkill()
{
	m_bSmartSpeed = FALSE;

	// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
	m_bMonsterHold	= FALSE;	// Hold상태?
	// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현

	m_nSkillPatternType = 0;
	m_nTargetIndex = 0;
	m_nCharacterUID = 0;
	m_bSkillTargetState = FALSE;
	m_nChargingShotState = SKILL_STATE_READY;
	m_pSecSkillInfo = NULL;
	m_pPriSkillInfo = NULL;
	m_bScan			= FALSE;
	//m_fScanRange	= 0.f;

	// 2007-04-05 by bhsohn 빅붐 버그 처리
	m_nPreSkillItemNum = 0;

	// 2007-04-19 by bhsohn 서치아이 아이템 추가
	m_nScanState = 0;
	for(int nCnt = 0;nCnt < MAX_SCAN;nCnt++)
	{
		m_fScanRange[nCnt]	= 0.f;
		memset(&m_vScanPosition[nCnt], 0x00, sizeof(D3DXVECTOR3));
	}
	
}

CSkill::~CSkill()
{
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.begin();
	while(itSkillInfo != m_mapSkill.end())
	{
		SAFE_DELETE(itSkillInfo->second);
		itSkillInfo++;
	}
	m_mapSkill.clear();

	itSkillInfo = m_mapEnemySkillInfo.begin();
	while(itSkillInfo != m_mapEnemySkillInfo.end())
	{
		SAFE_DELETE(itSkillInfo->second);
		itSkillInfo++;
	}
	m_mapEnemySkillInfo.clear();
	
}

CSkillInfo* CSkill::PutSkill(ITEM_SKILL* pItemSkill)
{
	CSkillInfo* pSkillInfo = FindItemSkill(pItemSkill->ItemNum);
	if(pSkillInfo)
	{// 2007-01-05 by dgwoo, 이미 스킬이 존재하는지 체크
		return pSkillInfo;
	}

	pSkillInfo = new CSkillInfo(pItemSkill);
	m_mapSkill[pItemSkill->ItemNum] = pSkillInfo;
	if(pSkillInfo->ItemInfo &&
		pSkillInfo->ItemInfo->SkillType == SKILLTYPE_PERMANENT)
	{	
		int i; for(i=0;i< SIZE_MAX_POS;i++)
		{
			CMapItemWindowInventoryIterator it = g_pStoreData->m_mapItemWindowPosition.find(i);
			if(	pItemSkill->ItemInfo->ReqItemKind == ITEMKIND_ALL_ITEM ||
				(it != g_pStoreData->m_mapItemWindowPosition.end() &&
				CAtumSJ::CheckReqItemKind(pItemSkill->ItemInfo->ReqItemKind,it->second->GetRealItemInfo()->Kind)) )
			{
				UseSkill(pSkillInfo);
				return pSkillInfo;
			}
		}
	}
	return pSkillInfo;
}

void CSkill::DeleteSkill(LONGLONG UniqueNumber)
{
	FLOG( "CSkill::DeleteSkill(LONGLONG UniqueNumber)" );
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.begin();
	for(; itSkillInfo != m_mapSkill.end(); itSkillInfo++)
	{
		if(itSkillInfo->second->UniqueNumber == UniqueNumber)
		{
			ReleaseSkill(itSkillInfo->second);

			// 2007-01-05 by dgwoo, 스킬 구입시 이기 때문에 모든 스킬을 취소 한다
			CancelSkillByBaseNum(itSkillInfo->second->ItemNum, TRUE);

			SAFE_DELETE(itSkillInfo->second);
			m_mapSkill.erase(itSkillInfo);
			break;
		}
	}	
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::ReleseSkill()
/// \brief		위장,인비지불 스킬이 발동줄일때 해제시킨다.
/// \author		dgwoo
/// \date		2006-11-28 ~ 2006-11-28
/// \warning	
///
/// \param		int nType : 취소할 스킬
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleseSkill(int nType, INT nAttackSkillItemNum)
{
	if(nType == DES_SKILL_SCANNING)
	{
		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
		while(itvecSkillInfo != m_vecUsingSkill.end())
		{
			if(SKILL_BASE_NUM((*itvecSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_CAMOUFLAGE ||
				SKILL_BASE_NUM((*itvecSkillInfo)->ItemNum) == BGEAR_SKILL_BASENUM_INVISIBLE )
			{
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK, nAttackSkillItemNum);
			}
			itvecSkillInfo++;
		}
	}
	else if(nType == DES_SKILL_CAMOUFLAGE)
	{
		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
		while(itvecSkillInfo != m_vecUsingSkill.end())
		{
			if(SKILL_BASE_NUM((*itvecSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_CAMOUFLAGE)
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			itvecSkillInfo++;
		}
	}
	else if(nType == DES_SKILL_CANCELALL)
	{
// 2007-01-29 by dgwoo 정화 스킬 사용시 재 사용시간까지 초기화 시킨기로 변경.
		// 내가 쓴 스킬.
		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
		while(itvecSkillInfo != m_vecUsingSkill.end())
		{
//			if((*itvecSkillInfo)->ItemInfo->AttackTime > 0)
//			{
//				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
//			}
			
			if((*itvecSkillInfo)->GetSkillState() <= SKILL_STATE_USING)
			{
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_USING);
				g_pShuttleChild->m_pSkillEffect->DeleteSkillEffect((*itvecSkillInfo)->ItemInfo->ItemNum);
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
				// 2007-03-06 by dgwoo 10분은 포함하지 않음.

				// 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
// 				if((*itvecSkillInfo)->ItemInfo->ReAttacktime < TERM_TICK_MUST_SERVER_CHECK_SKILL_REATTACK_TIME
// 					&& !(*itvecSkillInfo)->IsMustOneTargetSkill((*itvecSkillInfo)->ItemInfo->SkillTargetType))
				if( !COMPARE_BIT_FLAG((*itvecSkillInfo)->ItemInfo->ItemAttribute, SKILL_ATTR_STORE_USING_TIME)
					&& !(*itvecSkillInfo)->IsMustOneTargetSkill((*itvecSkillInfo)->ItemInfo->SkillTargetType))
				// end 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
					(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);
			}
			itvecSkillInfo++;
		}
		// 다른유저가 쓴 스킬.
		itvecSkillInfo = m_vecEnemyUsingSkillForMe.begin();
		while(itvecSkillInfo != m_vecEnemyUsingSkillForMe.end())
		{
			// 2009. 08. 11 by ckPark 편대 대형 스킬
			//if((*itvecSkillInfo)->GetSkillState() == SKILL_STATE_USING)
			if( (*itvecSkillInfo)->GetSkillState() == SKILL_STATE_USING
				&& !COMPARE_BIT_FLAG( (*itvecSkillInfo)->ItemInfo->ItemAttribute, SKILL_ATTR_PARTY_FORMATION_SKILL ) 
				&& !IS_INFUENCE_BUFF((*itvecSkillInfo)->ItemInfo)) // 2013-05-28 by bhsohn 세력버프가 [정화]에 다 날라가는 현상 처리
			// end 2009. 08. 11 by ckPark 편대 대형 스킬
			{
				if((*itvecSkillInfo)->ItemInfo->AttackTime > 0)
				{
					g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
				}
				// 다른 유저가 쓴 스킬을 삭제
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);

			}
			itvecSkillInfo++;
		}

// 2007-01-29 by dgwoo 정화 스킬 사용시 재사용시간을 유지.
//			if((*itvecSkillInfo)->GetSkillState() != SKILL_STATE_WAIT_REATTACK)
//			{
//				if((*itvecSkillInfo)->ItemInfo->AttackTime > 0)
//				{
//					g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
//				}
//				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
//			}
//			itvecSkillInfo++;
//		}
//		// 2006-12-28 by dgwoo 다른 유저가 쓴 스킬도 함께 삭제한다.
//		itvecSkillInfo = m_vecEnemyUsingSkillForMe.begin();
//		while(itvecSkillInfo != m_vecEnemyUsingSkillForMe.end())
//		{
//			if((*itvecSkillInfo)->GetSkillState() != SKILL_STATE_WAIT_REATTACK)
//			{
//				if((*itvecSkillInfo)->ItemInfo->AttackTime > 0)
//				{
//					g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
//				}
//				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
//
//			}
//			itvecSkillInfo++;
//		}
// 2007-02-01 by dgwoo 버서커스킬을 사용하여도 프렌지스킬을 취소시키지 않는다.
//	}else if(nType == IGEAR_SKILL_BASENUM_BERSERKER)
//	{
//		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
//		while(itvecSkillInfo != m_vecUsingSkill.end())
//		{
//			if(SKILL_BASE_NUM((*itvecSkillInfo)->ItemNum) == IGEAR_SKILL_BASENUM_FRENZY)
//				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
//			itvecSkillInfo++;
//		}
	}
	// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
	// 릴리즈시 디버프만 해제
	else if( nType == DES_SKILL_RELEASE )
	{
		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecEnemyUsingSkillForMe.begin();
		while(itvecSkillInfo != m_vecEnemyUsingSkillForMe.end())
		{
			if( IS_ORBIT_SKILL( (*itvecSkillInfo)->ItemInfo->OrbitType )
				&& (*itvecSkillInfo)->GetSkillState() == SKILL_STATE_USING )
			{
				if((*itvecSkillInfo)->ItemInfo->AttackTime > 0)
				{
					g_pShuttleChild->m_pSkillEffect->DeleteCastingStateMonsterSkillEffect();
				}
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
				(*itvecSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);
			}
			itvecSkillInfo++;
		}
	}
	// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
}

void CSkill::UseSkill(CSkillInfo* pItemSkill)
{
	FLOG( "CSkill::UseSkill(CSkillInfo* pItemSkill)" );
	if( pItemSkill->ItemInfo->SkillType != SKILLTYPE_PERMANENT &&
		g_pD3dApp->m_dwGameState == _CITY )
	{
		// 도시에서는 패시브 스킬을 제외하고 다른 스킬은 사용할 수 없다.
		return;
	}
	
	// 2004-11-26 by jschoi - 워프중에는 스킬을 사용할 수 없다.
	if( g_pShuttleChild->m_nCurrentPatternNumber == PATTERN_UNIT_WARP_OUT ||
		g_pShuttleChild->m_nCurrentPatternNumber == PATTERN_UNIT_WARP_IN)
	{
		return;
	}

	if(pItemSkill->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
	{
		vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
		while(itvecSkillInfo != m_vecUsingSkill.end())
		{
			if(((*itvecSkillInfo)->ItemNum == pItemSkill->ItemNum) &&
				((*itvecSkillInfo)->GetAttackIndex() == g_pShuttleChild->m_myShuttleInfo.ClientIndex))
			{
				if((*itvecSkillInfo)->IsEnableStateForReUsing())
				{
					// 시간형 스킬 재사용 : 시간형 스킬의 경우 ReattackTime이 지나면 재사용이 가능하다.
					//(*itvecSkillInfo)->ReUsingSkill();
					// 2012-08-09 by mspark, 시간형 스킬 발동 시간이 10초 이하로 남아있을 경우 인비지블 상태에서도 재발동되던 버그 재발동 안되도록 수정
					if(!IsUseSkill(pItemSkill))
					{
					(*itvecSkillInfo)->ReUsingSkill();
					}
					// end 2012-08-09 by mspark, 시간형 스킬 발동 시간이 10초 이하로 남아있을 경우 인비지블 상태에서도 재발동되던 버그 재발동 안되도록 수정
					// 2006-11-28 by dgwoo 현재 위장스킬을 스킬을 사용중이면 스킬을 푼다.
					if(g_pShuttleChild->GetUnitAlphaState())
						ReleseSkill(DES_SKILL_CAMOUFLAGE);
				}
				else
				{
					g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0008,COLOR_SKILL_CANCEL);//"재발동 시간이 남았습니다."
				}
				return;
			}

			itvecSkillInfo++;
		}
	}

	// 2005-11-26 by ispark, 스킬이 사용 가능한가?
	if(IsUseSkill(pItemSkill))
	{
		return;
	}
	// 2006-12-04 by dgwoo 위장시 스킬을 사용하면 자동으로 풀린다.
	if(g_pShuttleChild->GetUnitAlphaState())
		ReleseSkill(DES_SKILL_CAMOUFLAGE);
	// 현재 동일한 스킬이 사용중이 아니라면
	map<int,CSkillInfo*>::iterator itmapSkillInfo = m_mapSkill.find(pItemSkill->ItemNum);
	if(itmapSkillInfo != m_mapSkill.end())
	{
		// icon
		if(NULL == g_pShuttleChild->m_pSkill->FindUsingSkillInfo(itmapSkillInfo->second->ItemNum))
		{
			// 2007-04-05 by bhsohn 빅붐 버그 처리
			m_nPreSkillItemNum = pItemSkill->ItemNum;
			//DBGOUT("CSkill::UseSkill [%d]\n", pItemSkill->ItemNum);

			itmapSkillInfo->second->Init();
			
			if(itmapSkillInfo->second->ItemInfo->AttackTime > 0)
			{// 2007-01-06 by dgwoo AttackTime 있는것만 현재 사용하는 vector에 미리 등록한다.
				g_pGameMain->m_pInfSkill->InsertSkillInfo(itmapSkillInfo->second);
				
			}
			// 2009-02-17 by bhsohn 스캔 버그 수정
			itmapSkillInfo->second->SetSkillEnable(TRUE);
			// end 2009-02-17 by bhsohn 스캔 버그 수정
			m_vecUsingSkill.push_back(itmapSkillInfo->second);
			if(itmapSkillInfo->second->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
			{
				g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_SKILL_0001,COLOR_SKILL_USE,CHAT_TAB_SYSTEM);	//"스킬을 시전합니다."
			}			

			// 2008-03-04 by bhsohn 시즈모드후 게임종료면 멈추는 현상처리
			if(IS_DT(g_pShuttleChild->m_myShuttleInfo.UnitKind)
				&&(SKILL_BASE_NUM(itmapSkillInfo->second->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEMODE 
					||SKILL_BASE_NUM(itmapSkillInfo->second->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEDEFENSEMODE 
					||SKILL_BASE_NUM(itmapSkillInfo->second->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE) )
			{
				// 기술 스전시, 창을 닫는다.
				g_pGameMain->RightWindowShow(FALSE,g_pGameMain->m_nRightWindowInfo);				
				g_pGameMain->LeftWindowShow(FALSE,g_pGameMain->m_nLeftWindowInfo);
				
				// 2010-10-14 by jskim 롤링과 에어시즈 같이 사용했을시 타겟 안잡히는 버그 수정
				if( ( g_pShuttleChild->IsMyShuttleRolling() ) )
				{
					g_pShuttleChild->InitRolling();
					g_pShuttleChild->m_bMouseMoveLock = FALSE;				// 2005-08-05 by ispark		
					g_pShuttleChild->m_bIsCameraPattern = FALSE;
				}
				// end 2010-10-14 by jskim 롤링과 에어시즈 같이 사용했을시 타겟 안잡히는 버그 수정
			}
			// end 2008-03-04 by bhsohn 시즈모드후 게임종료면 멈추는 현상처리
			
			if(itmapSkillInfo->second->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE ||
				itmapSkillInfo->second->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
				itmapSkillInfo->second->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE ||
				itmapSkillInfo->second->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
				itmapSkillInfo->second->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS)
			{ // 타켓을 클릭해야하는 있는 스킬 타입
				SetPrimarySkill(itmapSkillInfo->second);
				SetSkillTargetState(TRUE);	// 스킬 마우스 타입 세팅
			}
		}

		// 2014-02-19 by ymjoo 퀘스트 스크립트 추가 - 아이템 사용
		CQuest* pProgressMission = g_pQuestData->GetProgressMission();
		if(pProgressMission)
		{
			vector<ITEM_W_COUNT>::iterator itUseItem = pProgressMission->TargetUseItemVector.begin();
			while(itUseItem != pProgressMission->TargetUseItemVector.end())
			{
				if(pItemSkill->ItemNum == itUseItem->ItemNum)
				{
					g_pD3dApp->SendMissionComplete();
				}
			itUseItem++;
		}
		}
		// END 2014-02-19 by ymjoo 퀘스트 스크립트 추가 - 아이템 사용
	}
	else
	{
		DBGOUT("Use Skill : Can't Find Skill Information .\n");
	}
}

void CSkill::ReleaseSkill(CSkillInfo* pItemSkill)
{
	FLOG( "CSkill::ReleaseSkill(CSkillInfo* pItemSkill)" );

	CSkillInfo *pSkillInfo = FindUsingSkillInfo(pItemSkill->ItemNum);
	if(NULL == pSkillInfo)
	{
		return;
	}

	pSkillInfo->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
}

void CSkill::Tick(float fElaspedTime)
{
	// 2007-02-13 by dgwoo 스킬은 실제 시간으로 계산.
	fElaspedTime = g_pD3dApp->GetCheckElapsedTime();
	if(GetSkillPatternType() != 0 && g_pShuttleChild->m_bSkillMoveIsUse == FALSE)	
	{// 스킬 패턴을 해제해 줘야함
		CSkillInfo* pSkillInfo = FindUsingSkillInfoByBaseNum(GetSkillPatternType());
		if(	pSkillInfo &&
			SKILL_KIND(pSkillInfo->ItemNum) == SKILL_KIND_CONTROL &&
			pSkillInfo->ItemInfo->SkillType == SKILLTYPE_CLICK )	// 패턴이 있는 스킬이다.(SKILL_KIND_CONTROL 이고, 클릭형이다. == 패턴이 있는 스킬이다.)
		{
			pSkillInfo->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
		}
	}
	
	vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
	while(itvecSkillInfo != m_vecUsingSkill.end())
	{
		if((*itvecSkillInfo)->GetSkillState() == SKILL_STATE_RELEASE)
		{
			// 2007-01-29 by dgwoo 정화스킬 재사용시간까지 초기화한다.
			(*itvecSkillInfo)->SetInitReattackTime();
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itvecSkillInfo, g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber);
			SafeDeleteSkillInfo(*itvecSkillInfo);
			m_vecUsingSkill.erase(itvecSkillInfo);
		}
		else
		{
			(*itvecSkillInfo)->Tick(fElaspedTime);
			itvecSkillInfo++;
		}
	}
	itvecSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itvecSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		if((*itvecSkillInfo)->GetSkillState() == SKILL_STATE_RELEASE)
		{
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itvecSkillInfo);
			SafeDeleteSkillInfo(*itvecSkillInfo);
			m_vecEnemyUsingSkillForMe.erase(itvecSkillInfo);
		}
		else
		{
			(*itvecSkillInfo)->Tick(fElaspedTime);
			itvecSkillInfo++;
		}
	}
}

char* CSkill::GetSkillName(int nSkillItemNumber)
{
	FLOG( "CSkill::GetSkillName(int nSkillItemNumber)" );
	ITEM* pItem = g_pDatabase->GetServerItemInfo( nSkillItemNumber );
	if(pItem == NULL)
	{
		return NULL;
	}
	return pItem->ItemName;
}

int	CSkill::FindSkillItemNum(LONGLONG UniqueNumber)
{
	FLOG( "CSkill::FindSkillItemNum(LONGLONG UniqueNumber)" );
	int nSkillItemNum = 0;
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.begin();	
	while(itSkillInfo != m_mapSkill.end())
	{
		if(itSkillInfo->second->UniqueNumber == UniqueNumber)
		{
			nSkillItemNum = itSkillInfo->second->ItemNum;
			break;
		}
		itSkillInfo++;
	}
	return nSkillItemNum;
}

ITEM* CSkill::FindItem(int nSkillItemNumber)
{
	FLOG( "CSkill::FindItem(int nSkillItemNumber)" );
	return g_pDatabase->GetServerItemInfo(nSkillItemNumber);
}

CSkillInfo* CSkill::FindItemSkill(int nSkillItemNumber)
{
	FLOG( "CSkill::FindItemSkill(int nSkillItemNumber)" );
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.find(nSkillItemNumber);
	if(itSkillInfo != m_mapSkill.end())
	{	
		return itSkillInfo->second;
	}
	return NULL;
}

int	CSkill::FindItemSkillLevelByBaseNum(int nSkillBaseNum)
{
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.begin();
	while(itSkillInfo != m_mapSkill.end())
	{	
		if(SKILL_BASE_NUM(itSkillInfo->second->ItemNum) == nSkillBaseNum)
		{
			return SKILL_LEVEL(itSkillInfo->second->ItemNum);
		}
		itSkillInfo++;
	}
	return NULL;
}

CSkillInfo* CSkill::FindUsingSkillInfo(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if((*itSkillInfo)->ItemNum == nSkillItemNum)
		{
			return (*itSkillInfo);
		}
		itSkillInfo++;
	}
	return NULL;
}

CSkillInfo* CSkill::FindEnemyUsingSkillForMeInfo(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		if((*itSkillInfo)->ItemNum == nSkillItemNum)
		{
			return (*itSkillInfo);
		}
		itSkillInfo++;
	}
	return NULL;

}

CSkillInfo* CSkill::FindEnemyUsingSkillForMeInfoByBaseNum(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == SKILL_BASE_NUM(nSkillItemNum))
		{
			return (*itSkillInfo);
		}
		itSkillInfo++;
	}
	return NULL;

}

CSkillInfo* CSkill::FindUsingSkillInfoByBaseNum(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == SKILL_BASE_NUM(nSkillItemNum))
		{
			if((*itSkillInfo)->GetSkillState() <= SKILL_STATE_USING)
				return (*itSkillInfo);
		}
		itSkillInfo++;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillInfo* CSkill::FindUsingSkillExistInfoByBaseNum(int nSkillItemNum)
/// \brief		m_vecUsingSkill에 존재하는 것을 찾아준다.(BaseNum)
/// \author		dgwoo
/// \date		2007-01-15 ~ 2007-01-15
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
CSkillInfo* CSkill::FindUsingSkillExistInfoByBaseNum(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == SKILL_BASE_NUM(nSkillItemNum))
		{
			return (*itSkillInfo);
		}
		itSkillInfo++;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			IsExistSingleSkill()
/// \brief		현재 사용중인 스킬중 단독으로만 사용가능한 스킬을 사용중인가?
/// \author		jschoi
/// \date		2004-10-04 ~ 2004-10-04
/// \warning	시즈 모드,그라운드 폭격, 모든 컨트롤 스킬과 차징샷 타입 스킬은 단독으로만 사용한다.
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsExistSingleSkill()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(	SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEMODE ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEDEFENSEMODE ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == BGEAR_SKILL_BASENUM_GROUNDBOMBINGMODE ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_GROUNDACCELERATOR ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == BGEAR_SKILL_BASENUM_AIRBOMBINGMODE ||
			(SKILL_KIND((*itSkillInfo)->ItemNum) == SKILL_KIND_CONTROL && (*itSkillInfo)->GetSkillState() <= SKILL_STATE_USING))
		{
			char strMessage[256];
			wsprintf(strMessage,STRERR_C_SKILL_0009,//"[%s] 스킬과 동시에 사용 할 수 없는 스킬입니다."
				g_pShuttleChild->m_pSkill->GetSkillName((*itSkillInfo)->ItemInfo->ItemNum));
			g_pD3dApp->m_pChat->CreateChatChild(strMessage,COLOR_SKILL_CANCEL);
			return TRUE;
			
		}
		itSkillInfo++;
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			IsSingleSkill(int nSkillItemNum)
/// \brief		nSkillItemNum의 스킬이 단독으로 사용하는 스킬인가?
/// \author		jschoi
/// \date		2004-10-04 ~ 2004-10-04
/// \warning	시즈 모드,그라운드 폭격, 모든 컨트롤 스킬과 차징샷 타입 스킬은 단독으로만 사용한다.
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsSingleSkill(int nSkillItemNum)
{
	CSkillInfo* pItemSkill = FindItemSkill(nSkillItemNum);
	if( pItemSkill == NULL )
	{
		return FALSE;
	}
	if(	
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEDEFENSEMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == BGEAR_SKILL_BASENUM_GROUNDBOMBINGMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_GROUNDACCELERATOR ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == BGEAR_SKILL_BASENUM_AIRBOMBINGMODE)
//		||SKILL_KIND(pItemSkill->ItemNum) == SKILL_KIND_CONTROL)// 2007-06-15 by dgwoo 토글스킬사용중 컨트롤스킬사용가능.
	{
		return TRUE;
	}
	return FALSE;
}

void CSkill::DeleteSkillFromWearItem(BYTE nItemKind)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		UINT fReAttackTime = (*itSkillInfo)->ItemInfo->ReAttacktime;
		
		// 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
// 		if( (*itSkillInfo)->ItemInfo->ReqItemKind != ITEMKIND_ALL_ITEM &&
// 			CAtumSJ::CheckReqItemKind((*itSkillInfo)->ItemInfo->ReqItemKind, nItemKind) &&
// 			fReAttackTime < TERM_TICK_MUST_SERVER_CHECK_SKILL_REATTACK_TIME)	// 2006-12-20 by ispark, 특정 시간 이상은 지우지 않는다.
		if( (*itSkillInfo)->ItemInfo->ReqItemKind != ITEMKIND_ALL_ITEM &&
			CAtumSJ::CheckReqItemKind((*itSkillInfo)->ItemInfo->ReqItemKind, nItemKind) &&
			!COMPARE_BIT_FLAG((*itSkillInfo)->ItemInfo->ItemAttribute, SKILL_ATTR_STORE_USING_TIME))	// 2006-12-20 by ispark, 특정 시간 이상은 지우지 않는다.
		// end 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
		{
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pShuttleChild->m_pSkillEffect->DeleteSkillEffect((*itSkillInfo)->ItemInfo->ItemNum);
			// 2006-12-21 by dgwoo 무기 해제로 인한 스킬은 reattacktime을 0으로 셋팅한다.
			(*itSkillInfo)->SetInitReattackTime();
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			m_vecUsingSkill.erase(itSkillInfo);
		}
		else
		{
			itSkillInfo++;
		}
	}
}

void CSkill::PutSkillFromWearItem(BYTE nItemKind)
{
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapSkill.begin();
	while(itSkillInfo != m_mapSkill.end())
	{
		if(	itSkillInfo->second->ItemInfo->SkillType == SKILLTYPE_PERMANENT &&
			(nItemKind == ITEMKIND_ALL_ITEM ||
			CAtumSJ::CheckReqItemKind(itSkillInfo->second->ItemInfo->ReqItemKind, nItemKind) ) )
		{
			UseSkill(itSkillInfo->second);
		}
		itSkillInfo++;
	}
}

BOOL CSkill::IsSatisfyReqItemKind(BYTE nReqItemKind, BYTE nItemKind)
{
	if(nReqItemKind == ITEMKIND_ALL_ITEM)
	{
		return TRUE;
	}
	
	switch(nReqItemKind)
	{
	case ITEMKIND_ALL_WEAPON:
		{
			return TRUE;
		}
		break;
	case ITEMKIND_PRIMARY_WEAPON_ALL:
		{
			if(IS_PRIMARY_WEAPON(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	case ITEMKIND_PRIMARY_WEAPON_1:
		{
			if(IS_PRIMARY_WEAPON_1(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	case ITEMKIND_PRIMARY_WEAPON_2:
		{
			if(IS_PRIMARY_WEAPON_2(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	case ITEMKIND_SECONDARY_WEAPON_ALL:
		{
			if(IS_SECONDARY_WEAPON(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	case ITEMKIND_SECONDARY_WEAPON_1:
		{
			if(IS_SECONDARY_WEAPON_1(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	case ITEMKIND_SECONDARY_WEAPON_2:
		{
			if(IS_SECONDARY_WEAPON_2(nItemKind))
				return TRUE;
			else
				return FALSE;
		}
		break;
	default:
		{
			if(nReqItemKind == nItemKind)
				return TRUE;
			else
				return FALSE;
		}
		break;
	}
	return FALSE;
}

void CSkill::CancelSkill(int nSkillItemNum, BOOL i_bEnemyUsingSkillCancel)
{
	CSkillInfo *pSkillInfo = FindUsingSkillInfo(nSkillItemNum);
	if(pSkillInfo)
	{
		if(0 < pSkillInfo->GetCheckEnableTime())
		{
			pSkillInfo->ChangeSkillState(SKILL_STATE_USING);
		}
		else
		{
			if(pSkillInfo->ItemInfo->AttackTime > 0)
			{
				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
			}

			g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo, g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber);
			DeleteUsingSkillInfo(nSkillItemNum);
		}
	}
	
	if(i_bEnemyUsingSkillCancel)
	{
		pSkillInfo = FindEnemyUsingSkillForMeInfo(nSkillItemNum);
		if(pSkillInfo)
		{
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo);
			DeleteEnemyUsingSkillInfo(nSkillItemNum);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::CancelSkillByBaseNum(int nSkillItemNum, BOOL i_bEnemyUsingSkillCancel)
/// \brief		스킬을 취소하며 vecUsing에서 삭제시킨다.
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::CancelSkillByBaseNum(int nSkillItemNum, BOOL i_bEnemyUsingSkillCancel)
{
	CSkillInfo *pSkillInfo = FindUsingSkillExistInfoByBaseNum(nSkillItemNum);
	if(pSkillInfo)
	{
// 2007-01-15 by dgwoo 스킬을 취소할때는 그냥 삭제시킨다.
//		if(0 < pSkillInfo->GetCheckEnableTime())
//		{
//			pSkillInfo->ChangeSkillState(SKILL_STATE_USING);
//		}
//		else
//		{
//			if(pSkillInfo->ItemInfo->SkillType == SKILLTYPE_CHARGING)
//			{
//				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
//			}
//
//			g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo, g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber);
//			DeleteUsingSkillInfoByBaseNum(nSkillItemNum);
//		}
		if(pSkillInfo->ItemInfo->AttackTime > 0)
		{
			g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
		}

		g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo, g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber);
		DeleteUsingSkillInfoByBaseNum(nSkillItemNum);
		
	}
	
	if(i_bEnemyUsingSkillCancel)
	{
		pSkillInfo = FindEnemyUsingSkillForMeInfoByBaseNum(nSkillItemNum);
		if(pSkillInfo)
		{
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo);
			DeleteEnemyUsingSkillInfoByBaseNum(nSkillItemNum);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::ReleaseAllUsingSkillWithOutPermanent()
/// \brief		유저가 죽었을 경우 파라미터 및 스킬 삭제.
/// \author		dgwoo
/// \date		2007-01-10 ~ 2007-01-10
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleaseAllUsingSkillWithOutPermanent()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if((*itSkillInfo)->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
		{
			// 2007-04-12 by dgwoo reattact상태일 경우 다시 reattact할 필요가 없다.
			if((*itSkillInfo)->GetSkillState() != SKILL_STATE_WAIT_REATTACK)
			{
				(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			}
			// 2007-01-24 by dgwoo 캐스팅 타임이 있는 모든 이펙트를 삭제한다.
			//if((*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_CHARGING)
			if((*itSkillInfo)->ItemInfo->AttackTime > 0)
			{
				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
			}


			// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
			if((*itSkillInfo)->ItemInfo->AttackTime > 0)
			{
				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateMonsterSkillEffect();
			}
			// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현

	
			// 2006-12-15 by dgwoo, 10분 미만일경우만 스킬 재사용시간을 지운다.
			// 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
			//if((*itSkillInfo)->ItemInfo->ReAttacktime < TERM_TICK_MUST_SERVER_CHECK_SKILL_REATTACK_TIME)				//5분 이하일 경우
			if(!COMPARE_BIT_FLAG((*itSkillInfo)->ItemInfo->ItemAttribute, SKILL_ATTR_STORE_USING_TIME))				//5분 이하일 경우
			// end 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
			{
				(*itSkillInfo)->SetCheckEnableTime();
				(*itSkillInfo)->SetInitReattackTime();
				g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
				SafeDeleteSkillInfo(*itSkillInfo);
 				m_vecUsingSkill.erase(itSkillInfo);	
			}
			else
			{
				itSkillInfo++;
			}
		}
		else
		{
			itSkillInfo++;
		}
	}

	itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		if((*itSkillInfo)->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
		{
			//(*itSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			m_vecEnemyUsingSkillForMe.erase(itSkillInfo);
		}
		else
		{
			itSkillInfo++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::ReleaseStatDEAD_AllUsingSkillWithOutPermanent()
/// \brief		유저가 죽었을 경우 파라미터 및 스킬 삭제.(사망 시 버프 스킬 유지 시스템)
/// \author		// 2008-12-29 by bhsohn 사망 시 버프 스킬 유지 시스템
/// \date		2008-12-29 ~ 2008-12-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleaseStatDEAD_AllUsingSkillWithOutPermanent()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(IsReleaseSkill_StatDEAD((*itSkillInfo))
			&&(*itSkillInfo)->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
		{
			// reattact상태일 경우 다시 reattact할 필요가 없다.
			if((*itSkillInfo)->GetSkillState() != SKILL_STATE_WAIT_REATTACK)
			{
				(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			}
			// 캐스팅 타임이 있는 모든 이펙트를 삭제한다.
			//if((*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_CHARGING)
			if((*itSkillInfo)->ItemInfo->AttackTime > 0)
			{
				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
			}


			// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
			if((*itSkillInfo)->ItemInfo->AttackTime > 0)
			{
				g_pShuttleChild->m_pSkillEffect->DeleteCastingStateMonsterSkillEffect();
			}
			// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현

			
			// 2006-12-15 by dgwoo, 10분 미만일경우만 스킬 재사용시간을 지운다.
			// 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
			//if((*itSkillInfo)->ItemInfo->ReAttacktime < TERM_TICK_MUST_SERVER_CHECK_SKILL_REATTACK_TIME)				//5분 이하일 경우
			if(!COMPARE_BIT_FLAG((*itSkillInfo)->ItemInfo->ItemAttribute, SKILL_ATTR_STORE_USING_TIME))				//5분 이하일 경우
			// end 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
			{
				(*itSkillInfo)->SetCheckEnableTime();
				(*itSkillInfo)->SetInitReattackTime();
				g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
				SafeDeleteSkillInfo(*itSkillInfo);
				m_vecUsingSkill.erase(itSkillInfo);	
			}
			else
			{
				itSkillInfo++;
			}
		}
		else
		{
			itSkillInfo++;
		}
	}
	
	itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		if(IsReleaseSkill_StatDEAD((*itSkillInfo))
			&& (*itSkillInfo)->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
		{
			//(*itSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			m_vecEnemyUsingSkillForMe.erase(itSkillInfo);
		}
		else
		{
			itSkillInfo++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::IsReleaseSkill_StatDEAD()
/// \brief		유저가 죽었을 경우 지울 스킬이냐?
/// \author		// 2008-12-29 by bhsohn 사망 시 버프 스킬 유지 시스템
/// \date		2008-12-29 ~ 2008-12-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsReleaseSkill_StatDEAD(CSkillInfo* i_pSkillInfo)
{
	if(NULL == i_pSkillInfo)
	{
		return FALSE;
	}


	// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현

	// 몬스터 스킬 죽었을때 풀린다
	if( i_pSkillInfo->ItemInfo->Kind == ITEMKIND_FOR_MON_SKILL )
		return TRUE;

	// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현


	switch(i_pSkillInfo->ItemInfo->SkillType)
	{
	case SKILLTYPE_PERMANENT:
		{
			return FALSE;
		}
	case SKILLTYPE_TIMELIMIT:	// 시간형 스킬은 지우면 안된다.
		{
			// 스킬 유지 시간 1분 이상인 스킬만 지우지 않는다.(1분미만만 삭제)
			if(i_pSkillInfo->ItemInfo->Time >= TERM_TICK_MUST_SERVER_CHECK_SKILL_DEADSTAT_REATTACK_TIME)				//5분 이하일 경우
			{
				return FALSE;
			}
		}
		break;	
		
	}		
	return TRUE;
}


void CSkill::ReleaseAllUsingToggleSkill()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if((*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_TOGGLE)
		{
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			m_vecUsingSkill.erase(itSkillInfo);	
		}
		else
		{
			itSkillInfo++;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::ReleaseGroundSkill()
/// \brief		Ground 스킬 해제
/// \author		dhkwon
/// \date		2004-10-04 ~ 2004-10-04
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleaseGroundSkill()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(	SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_GROUNDACCELERATOR ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == FLASH_ACCELERATOR ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEMODE ||				// 2006-05-29 by ispark
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_CAMOUFLAGE ||			// 2006-11-16 by dgwoo
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEDEFENSEMODE)		// 2006-05-29 by ispark
		{
			ReleaseSkill(*itSkillInfo);
//			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);// 2005-11-26 by ispark 두번 중복
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			itSkillInfo = m_vecUsingSkill.erase(itSkillInfo);
			continue;
		}
		itSkillInfo++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::ReleaseAllChargingSkill()
/// \brief		차징스킬 해제
/// \author		jschoi
/// \date		2004-10-25 ~ 2004-10-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleaseAllChargingSkill()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		//if((*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_CHARGING)
		if((*itSkillInfo)->ItemInfo->AttackTime > 0)
		{
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			g_pShuttleChild->m_pSkillEffect->DeleteCastingStateSkillEffect();
		}
		itSkillInfo++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::SendPrepareUseSkill()
/// \brief		서버로 스킬이 발동됨을 알려준다
/// \author		jschoi
/// \date		2004-10-05 ~ 2004-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::SendPrepareUseSkill(CSkillInfo* pSkillInfo)
{
	MSG_FC_SKILL_PREPARE_USE sMsg;
	sMsg.SkillItemID.ItemNum = pSkillInfo->ItemNum;
	sMsg.SkillItemID.ItemUID = pSkillInfo->UniqueNumber;
	g_pFieldWinSocket->SendMsg(T_FC_SKILL_PREPARE_USE, (char*)&sMsg, sizeof(sMsg) );

	g_pShuttleChild->m_myShuttleInfo.CurrentSP -= pSkillInfo->ItemInfo->ReqSP;
	char *strSkillName;
	char strMessage[256];
	strSkillName = GetSkillName(pSkillInfo->ItemNum);
	wsprintf(strMessage,STRMSG_C_SKILL_0002,strSkillName);	//"스킬 [%s] 을 발동합니다."
	g_pD3dApp->m_pChat->CreateChatChild(strMessage,COLOR_SKILL_USE,CHAT_TAB_SYSTEM);	
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::SendPrepareCancelSkill()
/// \brief		서버로 발동된 스킬이 취소됨을 알려준다.
/// \author		jschoi
/// \date		2004-10-05 ~ 2004-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::SendPrepareCancelSkill()
{
	char* strSkillName;
	char strMessage[256];
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if((*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_CHARGING)
		//if((*itSkillInfo)->ItemInfo->AttackTime > 0)
		{
			MSG_FC_SKILL_CANCEL_PREPARE sMsg;
			sMsg.SkillItemID.ItemNum = (*itSkillInfo)->ItemNum;
			sMsg.SkillItemID.ItemUID = (*itSkillInfo)->UniqueNumber;
			g_pFieldWinSocket->SendMsg(T_FC_SKILL_CANCEL_PREPARE, (char*)&sMsg, sizeof(sMsg) );
			
			strSkillName = GetSkillName((*itSkillInfo)->ItemNum);
			wsprintf(strMessage,STRERR_C_SKILL_0010,strSkillName);//"스킬 [%s] 의 발동을 취소합니다."	
			g_pD3dApp->m_pChat->CreateChatChild(strMessage,COLOR_SKILL_CANCEL);	
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			itSkillInfo = m_vecUsingSkill.erase(itSkillInfo);	
			continue;
		}
		itSkillInfo++;
	}
}

void CSkill::CheckChargingShotSkill()
{
//	UINT nSkillNum = 0;
	// 차징샷
	switch(GetChargingShotState())
	{
	case SKILL_STATE_WAITING_PREPARE:
	case SKILL_STATE_PREPARE:
	case SKILL_STATE_WAITING:
		{
			SendPrepareCancelSkill();
			SetChargingShotState(SKILL_STATE_READY);
		}
		break;
// 2007-01-10 by dgwoo 
//	case SKILL_STATE_WAITING:
//		{
//			CSkillInfo* pSkillInfo = GetPrimarySkill();
//			if(pSkillInfo)
//			{
//				pSkillInfo->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
//			}
//			else
//			{
//				SetChargingShotState(SKILL_STATE_READY);
//			}
//		}
//		break;
	case SKILL_STATE_USING:
		{
			CSkillInfo* pSkillInfo = GetPrimarySkill();
			if(pSkillInfo)
			{
				pSkillInfo->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			}
			else
			{
				SetChargingShotState(SKILL_STATE_READY);
			}
		}
		break;
	case SKILL_STATE_READY:
		break;
	case SKILL_STATE_RELEASE:
		SetChargingShotState(SKILL_STATE_READY);
	case SKILL_STATE_WAIT_REATTACK:
	default:
		SetPrimarySkill(NULL);
		break;
	}
//	return nSkillNum;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			UINT CSkill::GetChargingShotTypeSkillNum()
/// \brief		
/// \author		ispark
/// \date		2006-12-06 ~ 2006-12-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
UINT CSkill::GetChargingShotTypeSkillNum()
{
	UINT nSkillNum = 0;

	switch(GetChargingShotState())
	{
	case SKILL_STATE_WAITING_PREPARE:
	case SKILL_STATE_PREPARE:
	case SKILL_STATE_WAITING:
		{
			SendPrepareCancelSkill();
		}
		break;
	case SKILL_STATE_USING:

		{
			CSkillInfo* pSkillInfo = GetPrimarySkill();
			if(pSkillInfo)
			{
				nSkillNum = pSkillInfo->ItemNum;
			}
			else
			{
				SetChargingShotState(SKILL_STATE_READY);
			}
		}
		break;
//	case SKILL_STATE_USING:
//		{
//			CSkillInfo* pSkillInfo = GetPrimarySkill();
//			if(pSkillInfo)
//			{
//				pSkillInfo->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
//			}
//			else
//			{
//				SetChargingShotState(SKILL_STATE_READY);
//			}
//		}
//		break;
	case SKILL_STATE_READY:
		break;
	case SKILL_STATE_WAIT_REATTACK:
	case SKILL_STATE_RELEASE:
	default:
		SetPrimarySkill(NULL);
		break;
	}

	return nSkillNum;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsExistTargetOneSkill(CSkillInfo *pItemSkill)
/// \brief		타켓을 클릭해야 발동하는 스킬이 발동중인가?
/// \author		jschoi
/// \date		2004-10-14 ~ 2004-10-14
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsExistTargetOneSkill(CSkillInfo *pItemSkill)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		// 2006-10-26 by ispark, 스킬 타겟 타입을 스킬 타입으로 변경
		if(((*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS) &&
			//((*itSkillInfo)->ItemInfo->ItemNum == pItemSkill->ItemInfo->ItemNum) &&					// 2006-12-11 by ispark
//			((*itSkillInfo)->GetAttackIndex() == g_pShuttleChild->m_myShuttleInfo.ClientIndex ||
//			GetSkillTargetState() == TRUE))
			// 2006-12-27 by dgwoo 위에 두줄은 왜 그렇게 했을까요; 
			((*itSkillInfo)->GetSkillState() < SKILL_STATE_USING ))
		{
			return TRUE;
		}
		itSkillInfo++;
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::FindTargetForSkill()
/// \brief		마우스 포인터를 기준으로 가장 가까운 내 주변에 Unit을 구한다.(클릭)
/// \author		jschoi
/// \date		2004-10-14 ~ 2004-10-14
/// \warning	
///
/// \param		
/// \return		TRUE : 타겟을 잡았다. FALSE : 타겟을 못잡았다.	
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::FindTargetForSkill()
{
	float fLength = 50.0f;
	POINT pt;
	GetCursorPos(&pt);			
	ScreenToClient(g_pD3dApp->GetHwnd(), &pt);
	CheckMouseReverse(&pt);
	SetSkillTargetState(FALSE);		// 스킬 마우스 포인터 해제
	
	D3DXVECTOR2 vPos1 = D3DXVECTOR2(pt.x,pt.y);
	D3DXVECTOR2 vPos2;
	//////////////////////////////////////////////////////////////////////////
	// 먼저 내가 타겟인지 검사
	if(g_pShuttleChild->m_nObjScreenW > 0 && m_pPriSkillInfo)
	{
		vPos2 = D3DXVECTOR2(g_pShuttleChild->m_nObjScreenX, g_pShuttleChild->m_nObjScreenY);
		if(D3DXVec2Length(&(vPos1 - vPos2)) < fLength)
		{
			// 2005-12-05 by ispark, 자신에게 쓸 수 없는 스킬
			if(m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
				m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
				m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_WITHOUT_ME ||			// 2006-09-20 by ispark, 두 줄 포함
				m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_INRANGE_WITHOUT_ME ||
				m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS)
			{
				// 자기 자신 포함 안됌
				char strmsg[256];
				wsprintf(strmsg, STRMSG_C_051205_0001, m_pPriSkillInfo->ItemInfo->ItemName);// "[%s] 스킬은 자신에게 쓸 수 없는 스킬입니다."
				g_pD3dApp->m_pChat->CreateChatChild(strmsg, COLOR_SKILL_CANCEL);
				ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
				return FALSE;
			}
			else
			{
				SetTargetIndex(g_pShuttleChild->m_myShuttleInfo.ClientIndex);
				return TRUE;	
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// 2005-11-24 by ispark
	// 편대 리스트에서 클릭
	BOOL bFindTarget = FALSE;
	vector<PARTYENEMYINFO*>::iterator itParty = g_pShuttleChild->m_pClientParty->m_vecPartyEnemyInfo.begin();
	if(itParty != g_pShuttleChild->m_pClientParty->m_vecPartyEnemyInfo.end())
	{
		bFindTarget = FindListTargetForSkill(pt);
	}
	// 타겟을 못잡았으므로 스킬을 해제하고, 초기화 한다.
	// 아직 UseSkill상태도 아니므로 그냥 지운다.
	if(bFindTarget)
	{
		// 2010. 06. 18 by jskim 콜오브 히어로 시전시 SP 감소하는 버그 수정
		if(m_pPriSkillInfo->ItemInfo->AttackTime > 0 && 
			bFindTarget &&
			(m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME		||
			m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME  ||
			m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_WITHOUT_ME		||
			m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_INRANGE_WITHOUT_ME	||
			m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS))
		{
			m_pPriSkillInfo->ChangeSkillState(SKILL_STATE_WAITING_PREPARE);

			// 2010. 10. 11. 딜레이 타겟 시전형 스킬 버그 수정.
			m_pPriSkillInfo->SetClickTagetIndex ( g_pShuttleChild->m_pSkill->GetTargetIndex() );
			m_pPriSkillInfo->SetClickTargetUID ( g_pShuttleChild->m_pSkill->GetCharacterUID() );
			// End 2010. 10. 11. 딜레이 타겟 시전형 스킬 버그 수정.

		}
		//end 2010. 06. 18 by jskim 콜오브 히어로 시전시 SP 감소하는 버그 수정
		return TRUE;
	}
	//////////////////////////////////////////////////////////////////////////
	// 주변에 Enemy가 타겟인지 검사
	CEnemyData * pTargetEnemy = NULL;
	map<INT,CEnemyData *>::iterator itEnemy = g_pD3dApp->m_pScene->m_mapEnemyList.begin();
	while(itEnemy != g_pD3dApp->m_pScene->m_mapEnemyList.end())
	{
// 2007-02-16 by dgwoo 아래와 같은 방식으로 비교문이 들어갈 필요가 없음.
//		if( itEnemy->second->m_nObjScreenW > 0 &&
//			(itEnemy->second->m_bySkillStateFlag == CL_SKILL_NONE ||					// 2006-12-12 by ispark, 위장, 인비지블이 아니고
//			(itEnemy->second->m_bySkillStateFlag != CL_SKILL_NONE &&					// 2006-12-11 by ispark, 위장, 인비지블이라면
//			&& (IsInfluenceCharacter(g_pShuttleChild->m_myShuttleInfo.InfluenceType, itEnemy->second->m_infoCharacter.CharacterInfo.InfluenceType) || // 2006-12-12 by ispark, 같은 세력 이거나
//			!(itEnemy->second->IsPkEnable())))))										// 2006-12-12 by ispark, PK가 아닐때
		if(itEnemy->second->m_nObjScreenW > 0
			&& itEnemy->second->m_nAlphaValue != SKILL_OBJECT_ALPHA_OTHER_INFLUENCE)	// 2007-02-16 by dgwoo 투명상태가 아니라면.
		{
			vPos2 = D3DXVECTOR2(itEnemy->second->m_nObjScreenX,itEnemy->second->m_nObjScreenY);
			float fLengthTemp = D3DXVec2Length(&(vPos1-vPos2));
			if(fLengthTemp < fLength)
			{

				// 2011-03-28 by hsson, 이미 죽은 상태의 기체에게 힐링 타겟 써지던 버그 수정
				BodyCond_t tEnemyBodyCondition = itEnemy->second->m_pCharacterInfo->m_nCurrentBodyCondition;
				if( COMPARE_BODYCON_BIT( tEnemyBodyCondition, BODYCON_DEAD_MASK ) )
				{
					if( m_pPriSkillInfo )
						ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
					
					return FALSE;
				}
				// end 2011-03-28 by hsson, 이미 죽은 상태의 기체에게 힐링 타겟 써지던 버그 수정

				fLength = fLengthTemp;
				pTargetEnemy = itEnemy->second;
			}
		}
		itEnemy++;
	}

	//////////////////////////////////////////////////////////////////////////
	// 타겟 잡았다.
	if(pTargetEnemy && m_pPriSkillInfo)
	{ // 타겟을 잡았다. 스킬을 사용한다.
		// 2006-11-30 by ispark, 아군(일반 세력 포함)에게 쓸 수 없는 스킬
		if(m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS
			&&(IsInfluenceCharacter(g_pShuttleChild->m_myShuttleInfo.InfluenceType, pTargetEnemy->m_infoCharacter.CharacterInfo.InfluenceType)
			&& !(g_pShuttleChild->IsPkEnable() && g_pShuttleChild->GetPVPClientIndex() == pTargetEnemy->m_infoCharacter.CharacterInfo.ClientIndex)
			&& !(g_pShuttleChild->IsPkState(PK_FVF) && g_pShuttleChild->m_pClientParty->IsFVFEnemy(pTargetEnemy->m_infoCharacter.CharacterInfo.CharacterUniqueNumber))
			&& !(g_pShuttleChild->IsPkState(PK_GVG) && pTargetEnemy->m_infoCharacter.CharacterInfo.GuildUniqueNumber == g_pShuttleChild->m_pGuildWarInfo->PeerGuildUID)))

		{
			// 아군 포함 안됌
			char strmsg[256];
			wsprintf(strmsg, STRMSG_C_061130_0000, m_pPriSkillInfo->ItemInfo->ItemName);// "[%s] 스킬은 자신 세력에게 쓸 수 없는 스킬입니다."
			g_pD3dApp->m_pChat->CreateChatChild(strmsg, COLOR_SKILL_CANCEL);
			ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
			return FALSE;
		}

		// 2005-12-05 by ispark, 파티원에 해당하는 스킬 제외
		if(	m_pPriSkillInfo &&
			(m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE ||
			m_pPriSkillInfo->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME))
		{
			// 편대원들에게만 쓰는 타겟 스킬
			char strmsg[256];
			wsprintf(strmsg, STRMSG_C_051205_0002, m_pPriSkillInfo->ItemInfo->ItemName);// "[%s] 스킬은 자신에게 쓸 수 없는 스킬입니다."
			g_pD3dApp->m_pChat->CreateChatChild(strmsg, COLOR_SKILL_CANCEL);
			ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
			return FALSE;
		}

		CSkillInfo* pSkillInfo = NULL;
		if(pSkillInfo = CheckConfirmSkillUse())
		{
			// 사용허가가 필요한 스킬이다.
			SendConfirmSkillUse(pSkillInfo, pTargetEnemy->m_infoCharacter.CharacterInfo.CharacterUniqueNumber);
			return TRUE;
		}

		SetTargetIndex(pTargetEnemy->m_infoCharacter.CharacterInfo.ClientIndex);
		return TRUE;
	}

	//////////////////////////////////////////////////////////////////////////
	// 타겟 못 잡았다.
	g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0011,COLOR_SKILL_CANCEL);//"타겟을 잡지못하여 스킬을 취소합니다."

	// 2007-05-22 by bhsohn 타켓 관련 메모리 버그 처리
	//ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
	if(m_pPriSkillInfo)
	{
		ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
	}
	// 2007-05-23 by bhsohn 스킬 안나가는 문제 처리
	else
	{
		InitTargetState();	// 타켓형 스킬의 변수들을 초기화 한다.
	}
	
	return FALSE;
}

void CSkill::ReleaseAllPrepareTargetOneSkill()
{ // 현재 발동중인 Target이 있는 스킬을 모두 해제한다.
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if((*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
			(*itSkillInfo)->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS)
		{
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_RELEASE);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);
			m_vecUsingSkill.erase(itSkillInfo);	
		}
		else
		{
			itSkillInfo++;
		}
	}	
	SetTargetIndex(0);				// 초기화
	SetCharacterUID(0);				// 초기화
	SetSkillTargetState(FALSE);		// 스킬 마우스 포인터 해제
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::ReleasePrepareTargetOneSkill(int nSkillNumber)
/// \brief		타겟형 스킬을 삭제한다.
/// \author		dgwoo
/// \date		2007-01-06 ~ 2007-01-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleasePrepareTargetOneSkill(int nSkillNumber)
{ // 현재 발동중인 Target이 있는 스킬을 해제한다.
	CSkillInfo* pSkillInfo = FindUsingSkillInfo(nSkillNumber);
	if(pSkillInfo)
	{
		pSkillInfo->ChangeSkillState(SKILL_STATE_RELEASE);
		g_pGameMain->m_pInfSkill->DeleteSkillInfo(pSkillInfo);
		SafeDeleteSkillInfo(pSkillInfo);
		DeleteUsingSkillInfo(nSkillNumber);
	}
	
	// 2007-05-23 by bhsohn 스킬 안나가는 문제 처리
//	SetTargetIndex(0);				// 초기화
//	SetCharacterUID(0);				// 초기화
//	SetSkillTargetState(FALSE);		// 스킬 마우스 포인터 해제
	InitTargetState();	// 타켓형 스킬의 변수들을 초기화 한다.
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::InitPrepareTargetOneSkill()
/// \brief		타켓형 스킬의 변수들을 초기화 한다.
/// \author		// 2007-05-23 by bhsohn 스킬 안나가는 문제 처리
/// \date		2007-01-06 ~ 2007-01-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::InitTargetState()
{
	SetTargetIndex(0);				// 초기화
	SetCharacterUID(0);				// 초기화
	SetSkillTargetState(FALSE);		// 스킬 마우스 포인터 해제
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::SafeDeleteSkillInfo(CSkillInfo* pSkillInfo)
/// \brief		내가 사용가능한 스킬리스트에 있는 스킬정보인가 비교하여 내가 사용가능한 스킬리스트가 아니면 
///				해당 스킬 정보를 완전히 Clear한다.
/// \author		jschoi
/// \date		2004-10-15 ~ 2004-10-15
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::SafeDeleteSkillInfo(CSkillInfo* pSkillInfo)
{// 내가 사용가능한 스킬리스트에 있는 스킬정보인가 비교하여 내가 사용가능한 스킬리스트가 아니면 해당 스킬 정보를 완전히 Clear한다.

	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapEnemySkillInfo.begin();
	for(; itSkillInfo != m_mapEnemySkillInfo.end(); itSkillInfo++)
	{
		if(pSkillInfo == itSkillInfo->second)
		{ // 해당 스킬이 있다.

			SAFE_DELETE(pSkillInfo);
			m_mapEnemySkillInfo.erase(itSkillInfo);
			return;
		}
	}	
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::EraseUsingSkill(CSkillInfo* pSkillInfo)
/// \brief		스킬 정보를 m_vecUsingSkill리스트에서 즉시 지운다.
/// \author		jschoi
/// \date		2004-10-15 ~ 2004-10-15
/// \warning	
///
/// \param		pSkillInfo 삭제할 스킬의 주소. bType FALSE = 자신 TRUE = 다른 유저가 나에게.
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::EraseUsingSkill(CSkillInfo* pSkillInfo,BOOL bEnemyDelete/* = FALSE*/)
{
	if(!bEnemyDelete)
	{
		vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
		while(itSkillInfo != m_vecUsingSkill.end())
		{
			if((*itSkillInfo)->ItemNum == pSkillInfo->ItemNum)
			{
				SafeDeleteSkillInfo(pSkillInfo);
				m_vecUsingSkill.erase(itSkillInfo);
				return;
			}
			itSkillInfo++;
		}
	}
	else
	{
		vector<CSkillInfo*>::iterator itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
		while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
		{
			if((*itSkillInfo)->ItemNum == pSkillInfo->ItemNum)
			{
				SafeDeleteSkillInfo(pSkillInfo);
				m_vecEnemyUsingSkillForMe.erase(itSkillInfo);
				return;
			}
			itSkillInfo++;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		내 버프 보다 높은 레벨의 스킬이 들어온다면 내 버프를 지운다.
/// \author		// 2008-12-26 by bhsohn 엠기어 편대 버그 수정
/// \date		2004-10-15 ~ 2004-10-15
/// \warning	
///
/// \param		pSkillInfo 삭제할 스킬의 주소. bType FALSE = 자신 TRUE = 다른 유저가 나에게.
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::EraseLowLVUsingSkill(ClientIndex_t	i_AttackIndex, INT i_nSkillItemNum)
{
	if(i_AttackIndex == g_pShuttleChild->GetMyShuttleInfo().ClientIndex)
	{
		// 내가 쓴 버프는 지울 필요가없다.
		return;
	}
	INT nSkillItemNum = SKILL_BASE_NUM(i_nSkillItemNum);
	INT nSkillLevel = SKILL_LEVEL(i_nSkillItemNum);


	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		CSkillInfo* pSkillInfo = (*itSkillInfo);
		if(NULL == pSkillInfo)
		{			
			itSkillInfo++;
			continue;
		}
		INT nTmpSkillItemNum = SKILL_BASE_NUM(pSkillInfo->ItemNum);
		INT nTmpSkillLevel = SKILL_LEVEL(pSkillInfo->ItemNum);		
		
		if((nTmpSkillItemNum == nSkillItemNum)
			&&(nSkillLevel >= nTmpSkillLevel))
		{			
			pSkillInfo->SetSkillEnable(FALSE);
		}
		itSkillInfo++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::FindSkillEffect(CUnitData* pUnit, int nEffectNum)
/// \brief		해당 스킬 이펙트를 해제한다.
/// \author		jschoi
/// \date		2004-12-08 ~ 2004-12-08
/// \warning	g_pD3dApp->m_pEffectList에서 해당 이펙트를 찾는다.
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::DisableSkillEffect(CUnitData* pUnit, int nEffectNum)
{
	CAppEffectData* pEffect = (CAppEffectData*)g_pD3dApp->m_pEffectList->m_pChild;
	while(pEffect)
	{
		if( pEffect->m_pParent == (CAtumNode*)pUnit &&
			pEffect->m_nType == nEffectNum )		
		{
			pEffect->m_bUsing = FALSE;
			break;
		}
		pEffect = (CAppEffectData*)pEffect->m_pNext;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::DeleteUsingSkillInfo(int nSkillItemNum)
/// \brief		
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::DeleteUsingSkillInfo(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	for(; itSkillInfo != m_vecUsingSkill.end(); itSkillInfo++)
	{
		if((*itSkillInfo)->ItemNum == nSkillItemNum)
		{
			m_vecUsingSkill.erase(itSkillInfo);
			return TRUE;
		}		
	}

	return FALSE;
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::DeleteUsingSkillInfoByBaseNum(int nSkillItemNum)
/// \brief		
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::DeleteUsingSkillInfoByBaseNum(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	for(; itSkillInfo != m_vecUsingSkill.end(); itSkillInfo++)
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == SKILL_BASE_NUM(nSkillItemNum))
		{
			m_vecUsingSkill.erase(itSkillInfo);
			return TRUE;
		}		
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::DeleteEnemyUsingSkillInfo(int nSkillItemNum)
/// \brief		
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::DeleteEnemyUsingSkillInfo(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	for(; itSkillInfo != m_vecEnemyUsingSkillForMe.end(); itSkillInfo++)
	{
		if((*itSkillInfo)->ItemNum == nSkillItemNum)
		{
			m_vecEnemyUsingSkillForMe.erase(itSkillInfo);
			return TRUE;
		}		
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::DeleteEnemyUsingSkillInfoByBaseNum(int nSkillItemNum)
/// \brief		
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::DeleteEnemyUsingSkillInfoByBaseNum(int nSkillItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	for(; itSkillInfo != m_vecEnemyUsingSkillForMe.end(); itSkillInfo++)
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == SKILL_BASE_NUM(nSkillItemNum))
		{
			m_vecEnemyUsingSkillForMe.erase(itSkillInfo);
			return TRUE;
		}		
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::FindListTargetForSkill(POINT pt)
/// \brief		편대 리스트에서 찾기(클릭형만 가능)
/// \author		ispark
/// \date		2005-11-24 ~ 2005-11-24
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::FindListTargetForSkill(POINT pt)
{
	// 클릭형만 사용함
	int i = 0;
	D3DXVECTOR2 vPos1 = D3DXVECTOR2(pt.x,pt.y);
	vector<PARTYENEMYINFO*>::iterator itParty = g_pShuttleChild->m_pClientParty->m_vecPartyEnemyInfo.begin();
	while(itParty != g_pShuttleChild->m_pClientParty->m_vecPartyEnemyInfo.end())
	{
		// 리스트 클릭
		// 2008-07-10 by bhsohn 타켓힐이 안되는 문제 해결
//		if(pt.x > 0 && pt.x < 130 &&
//			pt.y > 170 + 34 * i &&
//			pt.y < 204 + 34 * i)
		if(pt.x > 0 && pt.x < 130 &&
			pt.y > FRAME_START_Y + PARTY_FRAME_SIZE_Y * i &&
			pt.y < (FRAME_START_Y + PARTY_FRAME_SIZE_Y) + (PARTY_FRAME_SIZE_Y * i))
		{
			// 같은맵에 존재함
			if((*itParty)->m_bPartyType == _PARTYMASTER ||
				(*itParty)->m_bPartyType == _PARTYMEMBER)
			{
				CSkillInfo* pSkillInfo = NULL;
				if(pSkillInfo = CheckConfirmSkillUse())
				{
					// 사용허가가 필요한 스킬이다.

					// 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연
					//SendConfirmSkillUse(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
					g_pGameMain->PushDelaySkill(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
					// end 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연



					return TRUE;
				}

				SetTargetIndex(0);
				SetCharacterUID((*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);

				return TRUE;
			}
			// 다른맵에 존재함
			else if((*itParty)->m_bPartyType == _PARTYOTHERMAPMASTER ||
				(*itParty)->m_bPartyType == _PARTYOTHERMAPMEMBER)
			{
				CSkillInfo* pSkillInfo = NULL;
				if(pSkillInfo = CheckConfirmSkillUse())
				{
					// 사용허가가 필요한 스킬이다.



					// 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연
					//SendConfirmSkillUse(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
					g_pGameMain->PushDelaySkill(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
					// end 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연



					return TRUE;
				}
				// 2010. 06. 18 by jskim 콜오브 히어로 시전시 SP 감소하는 버그 수정
				SetTargetIndex(0);
				SetCharacterUID((*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
				return TRUE;
				//end 2010. 06. 18 by jskim 콜오브 히어로 시전시 SP 감소하는 버그 수정
			}
			// 아직...
			else if((*itParty)->m_bPartyType == _PARTYRESTARTMEMBER)
			{

			}
		}
		else // 편대원 일반 타겟 클릭
		{
			// 같은맵에 존재함
			if((*itParty)->m_bPartyType == _PARTYMASTER ||
				(*itParty)->m_bPartyType == _PARTYMEMBER)
			{
			if((*itParty)->m_pEnemyData->m_nObjScreenW > 0)
			{
				float fLength = 50.0f;
				D3DXVECTOR2 vPos2 = D3DXVECTOR2((*itParty)->m_pEnemyData->m_nObjScreenX, (*itParty)->m_pEnemyData->m_nObjScreenY);
				float fLengthTemp = D3DXVec2Length(&(vPos1-vPos2));
				if(fLengthTemp < fLength)
				{
					CSkillInfo* pSkillInfo = NULL;
					if(pSkillInfo = CheckConfirmSkillUse())
					{
						// 사용허가가 필요한 스킬이다.



						// 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연
						//SendConfirmSkillUse(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
						g_pGameMain->PushDelaySkill(pSkillInfo, (*itParty)->m_ImPartyMemberInfo.CharacterUniqueNumber);
						// end 2008. 12. 23 by ckPark 스킬 사용 지연 사용 지연



						return TRUE;
					}
				}
				}
			}
			// 다른맵에 존재함
			else if((*itParty)->m_bPartyType == _PARTYOTHERMAPMASTER ||
				(*itParty)->m_bPartyType == _PARTYOTHERMAPMEMBER)
			{
				
			}
			// 아직...
			else if((*itParty)->m_bPartyType == _PARTYRESTARTMEMBER)
			{

			}
		}
		
		i++;
		itParty++;
	}

	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::ReleaseAllUsingControlSkill(int i_nExcludeSkillNum)
/// \brief		컨트롤 스킬 모두 삭제, m_vecUsingSkill에서는 지우지 않는다.
///				중복 사용시 재발동 시간이 중간에서 삭제된다.
/// \author		ispark
/// \date		2005-11-25 ~ 2005-11-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleaseAllUsingControlSkill(int i_nExcludeSkillNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{

		if((*itSkillInfo)->ItemNum != i_nExcludeSkillNum 
			&& (*itSkillInfo)->ItemInfo->SkillType == SKILLTYPE_CLICK
			&& SKILL_KIND((*itSkillInfo)->ItemNum) == SKILL_KIND_CONTROL)
		{
			(*itSkillInfo)->ChangeSkillState(SKILL_STATE_WAIT_REATTACK);
			g_pGameMain->m_pInfSkill->DeleteSkillInfo(*itSkillInfo);
			SafeDeleteSkillInfo(*itSkillInfo);

			g_pShuttleChild->DeletePattern();				
			g_pShuttleChild->m_pSkill->SetSkillPatternType(0);	// 패턴 초기화
			// 2013-03-13 by bhsohn 스킬 번호 구조 수정
//			g_pShuttleChild->m_pSkill->DisableSkillEffect(g_pShuttleChild,SKILL_BASE_NUM((*itSkillInfo)->ItemInfo->SourceIndex));
			g_pShuttleChild->m_pSkill->DisableSkillEffect(g_pShuttleChild,SKILL_BASE_SOURCEINDEX((*itSkillInfo)->ItemInfo->SourceIndex));

		}

		itSkillInfo++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsExistMultyNGround()
/// \brief		멀티타겟과 지상폭격은 같이 쓸 수 없음. 존재하는지 검색
/// \author		ispark
/// \date		2005-11-25 ~ 2005-11-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsExistMultyNGround()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == BGEAR_SKILL_BASENUM_GROUNDBOMBINGMODE ||
			SKILL_BASE_NUM((*itSkillInfo)->ItemNum) == BGEAR_SKILL_BASENUM_AIRBOMBINGMODE ||
			(FindDestParamUseSkill((*itSkillInfo)->ItemInfo, DES_MULTITAGET_01) ||
			FindDestParamUseSkill((*itSkillInfo)->ItemInfo, DES_MULTITAGET_02)))
		{
			return TRUE;
		}

		itSkillInfo++;
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::FindDestParamUseSkill(ITEM *pItem, BYTE byDestParameter)
/// \brief		아템 DestParameter에서 스킬 DestParameter랑 비교해서 같은것이 존재하면 BOOL형 리턴
/// \author		ispark
/// \date		2005-11-25 ~ 2005-11-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
// 2013-03-27 by bhsohn DestParam 자료형 수정
//BOOL CSkill::FindDestParamUseSkill(ITEM *pItem, BYTE byDestParameter)
BOOL CSkill::FindDestParamUseSkill(ITEM *pItem, DestParam_t byDestParameter)
{
	// 2009-04-21 by bhsohn 아이템 DesParam추가
// 	if(pItem->DestParameter1 == byDestParameter ||
// 	   pItem->DestParameter2 == byDestParameter ||
// 	   pItem->DestParameter3 == byDestParameter ||
// 	   pItem->DestParameter4 == byDestParameter)
// 	{
// 		return TRUE;
// 	}
	int nArrParamCnt = 0;
	for(nArrParamCnt = 0; nArrParamCnt < SIZE_MAX_DESPARAM_COUNT_IN_ITEM; nArrParamCnt++)
	{
		if(pItem->ArrDestParameter[nArrParamCnt] == byDestParameter)
		{
			return TRUE;
		}
	}
	// end 2009-04-21 by bhsohn 아이템 DesParam추가
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::IsGroundSkill(CSkillInfo *pItemSkill)
/// \brief		지상에서 사용하는 스킬이냐?
/// \author		dgwoo
/// \date		2007-01-09 ~ 2007-01-09
/// \warning	
///
/// \param		
/// \return		TRUE 지상용 스킬.
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsGroundSkill(CSkillInfo *pItemSkill)
{
	if((SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_GROUNDACCELERATOR ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == FLASH_ACCELERATOR ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_SIEGEDEFENSEMODE||
		FindDestParamUseSkill(pItemSkill->ItemInfo, DES_SKILL_BARRIER) ||
		FindDestParamUseSkill(pItemSkill->ItemInfo, DES_SKILL_CAMOUFLAGE)))
		return TRUE;
	return FALSE;
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsUseSkill(CSkillInfo *pItemSkill)
/// \brief		쓸려는 스킬이 사용 가능한가?
/// \author		ispark
/// \date		2005-11-26 ~ 2005-11-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsUseSkill(CSkillInfo *pItemSkill)
{
	// 2007-02-01 by dgwoo 도시 맵에선 스킬을 사용할수 없다.
	if(IS_CITY_MAP_INDEX(g_pShuttleChild->m_myShuttleInfo.MapChannelIndex.MapIndex)
		&& !IS_BAZAAR_SKILL(pItemSkill->ItemInfo))
	{
		return TRUE;
	}
	// 2010. 06. 29 by jskim 구입상점 열때 인벤 남은 개수 체크
	if(g_pGameMain->m_pInven->GetInvenFreeSize() <= 0 && pItemSkill->ItemInfo->IsExistDesParam(DES_BAZAAR_BUY))
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_100629_0401,COLOR_ERROR);
		return TRUE;
	}
	//end 2010. 06. 29 by jskim 구입상점 열때 인벤 남은 개수 체크
	if(((g_pShuttleChild->m_dwState != _NORMAL || g_pShuttleChild->m_bUnitStop == TRUE || g_pShuttleChild->m_bLandedMove == TRUE || g_pShuttleChild->m_bPenaltyUnitStop == TRUE) || // 2005-11-25 by ispark 캐릭터일 때와 유닛정지 스킬 쓰지 않기
		(IS_DT(g_pShuttleChild->m_myShuttleInfo.UnitKind) && g_pShuttleChild->m_bIsAir == FALSE)) &&
		pItemSkill->ItemInfo->SkillType == SKILLTYPE_CLICK &&
		SKILL_KIND(pItemSkill->ItemNum) == SKILL_KIND_CONTROL)	// 패턴이 있는 스킬은 m_dwState가 _NORMAL 상태에서 사용가능하다.
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0002,COLOR_SKILL_CANCEL);//"스킬을 사용할 수 없는 상태입니다."
		return TRUE;
	}

	// 2006-09-27 by ispark 패턴 중이면서 컨트롤 스킬은 사용 할 수 없다.
	if(g_pShuttleChild->m_bSkillMoveIsUse == TRUE && 
		SKILL_KIND(pItemSkill->ItemNum) == SKILL_KIND_CONTROL)
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0002,COLOR_SKILL_CANCEL);//"스킬을 사용할 수 없는 상태입니다."
		return TRUE;
	}

	if( pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ME &&
		pItemSkill->ItemInfo->ReqItemKind != ITEMKIND_ALL_ITEM &&
		g_pStoreData->IsWearItem( pItemSkill->ItemInfo->ReqItemKind ) == FALSE &&
		pItemSkill->ItemInfo->SkillType != SKILLTYPE_PERMANENT)
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0003,COLOR_SKILL_CANCEL);//"스킬을 적용할 무기가 장착되어있지 않습니다."
		return TRUE;
	}

	if(	g_pShuttleChild->m_bIsAir == TRUE && IsGroundSkill(pItemSkill))
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0004,COLOR_SKILL_CANCEL);//"지상에서만 사용가능한 스킬입니다."
		return TRUE;
	}
	// 2006-11-16 by dgwoo Air Siege
	if(	!g_pShuttleChild->m_bIsAir&&
		(SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE))
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_061206_0100,COLOR_SKILL_CANCEL);//"공중에서만 사용가능한 스킬입니다."
		return TRUE;
	}
	// 2006-11-27 by dgwoo 정지 상태에서 사용할수 없는 스킬들
	// 2009-01-12 by bhsohn A기어, 유닛 고정 상태에서 에어 시즈시 공격 안되는 문제 해결
// 	if((SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE) &&
// 		g_pShuttleChild->m_bUnitStop == TRUE)
// 	{
// 		char chMsg[512] = {0,};
// 		wsprintf(chMsg,STRMSG_C_061206_0101, pItemSkill->ItemInfo->ItemName);
// 		g_pD3dApp->m_pChat->CreateChatChild(chMsg,COLOR_SKILL_CANCEL);
// 		return TRUE;
// 	}
	if(SKILL_BASE_NUM(pItemSkill->ItemNum) == AGEAR_SKILL_BASENUM_AIRSIEGEMODE)
	{
		if((g_pShuttleChild->m_bUnitStop == TRUE)
			||(g_pD3dApp->m_bFixUnitDirMode))
		{
			char chMsg[512] = {0,};
			wsprintf(chMsg,STRMSG_C_061206_0101, pItemSkill->ItemInfo->ItemName);
			g_pD3dApp->m_pChat->CreateChatChild(chMsg,COLOR_SKILL_CANCEL);
			return TRUE;
		}
	}
	// end 2009-01-12 by bhsohn A기어, 유닛 고정 상태에서 에어 시즈시 공격 안되는 문제 해결

	// 파티 시에만 사용 가능한 스킬 (나를 제외하고 다른 파티원이 존재할 때 사용 가능)
	if( (pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_WITH_ME || 
		pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_WITHOUT_ME) &&
		//g_pShuttleChild->m_pClientParty->m_vecPartyEnemyInfo.size() == 0 )
		!g_pShuttleChild->m_pClientParty->IsParty())
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0005,COLOR_SKILL_CANCEL);//"편대시에만 사용가능한 스킬입니다."
		return TRUE;
	}
	
	if( IsSingleSkill(pItemSkill->ItemNum) && IsExistSingleSkill())
	{
		return TRUE;
	}
	
	// 2006-10-26 by ispark, 타겟형 스킬은 오직 하나만 작동
	if((pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE ||
			pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
			pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE ||
			pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
			pItemSkill->ItemInfo->SkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS) &&
		IsExistTargetOneSkill(pItemSkill))
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0006,COLOR_SKILL_CANCEL);//"다른 타켓형 스킬이 발동중입니다."
		return TRUE;
	}
	// 2006-12-21 by dgwoo 타겟형 스킬과 차징형 스킬을 동시에 사용할수없다.
	if(((GetChargingShotState() <= SKILL_STATE_USING) &&
		(GetChargingShotState() > SKILL_STATE_READY)) &&
		pItemSkill->IsMustOneTargetSkill(pItemSkill->ItemInfo->SkillTargetType))
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_061221_0100,COLOR_SKILL_CANCEL);
		return TRUE;
	}
	
	if( pItemSkill->ItemInfo->ReqSP > g_pShuttleChild->m_myShuttleInfo.CurrentSP )
	{	
		g_pD3dApp->m_pChat->CreateChatChild(STRERR_C_SKILL_0007,COLOR_SKILL_CANCEL);//"스킬포인트가 부족합니다."
		return TRUE;
	}

	// 편대비행 이면서 편대원인경우에는 패턴 스킬을 사용하면 편대대형에서 탈퇴된다.
	if( pItemSkill->ItemInfo->SkillType == SKILLTYPE_CLICK &&
		SKILL_KIND(pItemSkill->ItemNum) == SKILL_KIND_CONTROL &&
		g_pShuttleChild->m_pClientParty &&
		g_pShuttleChild->m_pClientParty->IsFormationFlightMove())
	{
		g_pShuttleChild->SendPacket(T_IC_PARTY_CANCEL_FLIGHT_POSITION);
		g_pShuttleChild->m_pClientParty->FormationFlightClear();
	}
	// 2005-12-17 by ispark
	// 편대장이면서 편대비행일 때 패턴 스킬 사용시 편대대형 자유비행으로 변경
	else if(pItemSkill->ItemInfo->SkillType == SKILLTYPE_CLICK &&
		SKILL_KIND(pItemSkill->ItemNum) == SKILL_KIND_CONTROL &&
		g_pShuttleChild->m_pClientParty &&
		g_pShuttleChild->m_pClientParty->GetPartyInfo().bPartyType == _PARTYMASTER &&
		g_pShuttleChild->m_pClientParty->IsFormationFlight())
	{
		// 2008-06-17 by bhsohn 편대 관련 처리
		//g_pShuttleChild->m_pClientParty->ISendPartyChangeFlightFormation(FLIGHT_FORM_NONE);
		g_pShuttleChild->m_pClientParty->TempPartyFormation(FLIGHT_FORM_NONE);
	}

	// 2005-11-25 by ispark
	// 멀티타겟과 지상폭격은 같이 사용 못하게 함
	if((SKILL_BASE_NUM(pItemSkill->ItemNum) == BGEAR_SKILL_BASENUM_GROUNDBOMBINGMODE ||
		SKILL_BASE_NUM(pItemSkill->ItemNum) == BGEAR_SKILL_BASENUM_AIRBOMBINGMODE ||
		(FindDestParamUseSkill(pItemSkill->ItemInfo, DES_MULTITAGET_01) ||
		FindDestParamUseSkill(pItemSkill->ItemInfo, DES_MULTITAGET_02))) &&
		IsExistMultyNGround())
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_051125_0002,COLOR_SKILL_CANCEL);// "멀티타겟과 지상폭격은 같이 쓸 수 없습니다."
		return TRUE;		
	}

	// 2006-07-28 by ispark
	// 개인상점 사용이 가능한 지역인지
// 2007-06-01 by dgwoo 바자를마을에서도 사용가능 하며 영역의 제한도 풀도록 변경.
	if(!g_pD3dApp->m_bCharacter && 
		IS_BAZAAR_SKILL(pItemSkill->ItemInfo))
//		&& !g_pCharacterChild->GetbBazaarEvent())
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_060728_0002,COLOR_SKILL_CANCEL);// "이곳에서는 상점을 개설 할 수 없습니다."
		return TRUE;
	}

	// 2006-08-01 by ispark
	// 편대 비행중이면 개인상점에서는 자동 탈퇴
	if(g_pShuttleChild->m_pClientParty->GetPartyInfo().bPartyType != _NOPARTY && 
		g_pD3dApp->m_bCharacter && 
		IS_BAZAAR_SKILL(pItemSkill->ItemInfo) &&
		g_pCharacterChild->GetbBazaarEvent())
	{
		g_pShuttleChild->m_pClientParty->ISendPartyLeave();
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_PARTY_0007, COLOR_SKILL_CANCEL);//"편대에서 탈퇴 하였습니다."
	}

	// 2006-11-17 by ispark
	// 이벤트맵에서는 사용 할 수 없는 스킬
	if(!IsUseEventMap(pItemSkill))
	{
		char chMsg[512] = {0,};
		wsprintf(chMsg, STRMSG_C_061117_0001, pItemSkill->ItemInfo->ItemName);	// "이벤트맵에서는 %s 스킬을 사용할 수 없습니다."
		g_pD3dApp->m_pChat->CreateChatChild(chMsg, COLOR_SKILL_CANCEL);
		return TRUE;
	}
	if(!IsSkillPossibility())
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_061206_0102, COLOR_SKILL_CANCEL);	// "[인비지블]스킬 사용중에는 스킬 발동을 할수 없습니다."
		return TRUE;
	}
// 2011-10110 by jhahn EP4 침묵 스킬 추가
	if(!IsSkillPossibilitySlience())
	{
		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_131115_0001, COLOR_SKILL_CANCEL);	//침묵 스킬의 영향으로 스킬을 사용 할 수 없습니다.
		// 2013-11-15 by ssjung 침묵 스킬영향으로 스킬을 사용할 수 없을 때 인비지블 스트링이 나오는 현상 수정 
		return TRUE;
	}									 
//end 2011-10110 by jhahn EP4 침묵 스킬 추가
// 2007-02-01 by dgwoo 프렌지스킬과 폭주스킬 중복사용이 가능하다.
//	if(	FindUsingSkillInfoByBaseNum(IGEAR_SKILL_BASENUM_BERSERKER) && 
//		SKILL_BASE_NUM(pItemSkill->ItemNum) == IGEAR_SKILL_BASENUM_FRENZY)
//	{
//		g_pD3dApp->m_pChat->CreateChatChild(STRMSG_C_061212_0100, COLOR_SKILL_CANCEL);	//"해당스킬은 프렌즈와 중복사용이 불가능합니다."
//		return TRUE;
//	}

	// 2009. 08. 20 by ckPark 죽은 상태에서 에어시즈 스킬 써지던 문제
	if( g_pShuttleChild->m_dwState == _FALLING || g_pShuttleChild->m_dwState == _FALLEN)
	{
		g_pD3dApp->m_pChat->CreateChatChild( STRERR_C_SKILL_0002, COLOR_SKILL_CANCEL );	//"스킬을 사용할 수 없는 상태입니다."
		return TRUE;
	}
	// end 2009. 08. 20 by ckPark 죽은 상태에서 에어시즈 스킬 써지던 문제

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsSkillPossibility()
/// \brief		스킬을 사용할수 있는가? 요소들에 의해 스킬 사용의 유무를 판단.
/// \author		dgwoo
/// \date		2006-11-28 ~ 2006-11-28
/// \warning	추가 되는 내용을 계속 삽입.
///
/// \param		
/// \return		TRUE: 스킬사용가능 FALSE : 스킬 사용을 못함.
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsSkillPossibility()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(BGEAR_SKILL_BASENUM_INVISIBLE == SKILL_BASE_NUM((*itSkillInfo)->ItemNum))
		{
			return FALSE;
		}
		itSkillInfo++;
	}	
	return TRUE;
}
// 2011-10110 by jhahn EP4 침묵 스킬 추가
///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsSkillPossibilitySlience()
/// \brief		
/// \author		jhahn
/// \date		2011-11-28 ~ 2011-11-28
/// \warning	
///
/// \param		
/// \return		TRUE: 스킬사용가능 FALSE : 스킬 사용을 못함.
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsSkillPossibilitySlience()
{
	if(g_pShuttleChild->GetSkillMissileWarning() == TRUE)
	{
		 return FALSE;
	}
	 return TRUE;
}										 
//end 2011-10110 by jhahn EP4 침묵 스킬 추가
///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsSkillPossibility()
/// \brief		
/// \author		dgwoo
/// \date		2008-01-08 ~ 2008-01-08
/// \warning	
///
/// \param		
/// \return		TRUE: 스킬사용가능 FALSE : 스킬 사용을 못함.
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsAttackPossibility()
{
	// 인비지블 상태는 공격이 불가능한 상태다
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(BGEAR_SKILL_BASENUM_INVISIBLE == SKILL_BASE_NUM((*itSkillInfo)->ItemNum) 
			|| MGEAR_SKILL_BASENUM_INVICIBLE == SKILL_BASE_NUM((*itSkillInfo)->ItemNum))
			// 2013-10-08 by ssjung 무적스킬 워프 통과 시, 공격이 되는 현상 추가 처리
		{
			return FALSE;
		}
		itSkillInfo++;
	}	
	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::IsSkillOverBooster()
/// \brief		오버부스터를 쓰는지 찾는다. 이유는 특별히 이펙트를 효과를 내기 위해서
/// \author		ispark
/// \date		2005-11-29 ~ 2005-11-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsSkillOverBooster()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(
			SKILL_KIND((*itSkillInfo)->ItemNum) == SKILL_KIND_CONTROL
			&& (*itSkillInfo)->ItemNum == 7832031						  // 오버부스터

// 2010-12-28 by hsson 오버부스터 스킬 버그
			&& (*itSkillInfo)->GetSkillState() == SKILL_STATE_USING       // 스킬이 사용중이면
// end 2010-12-28 by hsson 오버부스터 스킬 버그

			)
		{
			return TRUE;
		}
		itSkillInfo++;
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::UseSkillConfirm(int i)
/// \brief		사용 허가 확인
/// \author		ispark
/// \date		2005-12-03 ~ 2005-12-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::UseSkillConfirm(int i)
{
	MSG_FC_SKILL_CONFIRM_USE_ACK sMsg;
	// 2014-07-09 by ymjoo 빅붐 사용 후 콜 오브 히어로 승인 못하게 수정 (롤백)
	if(i == 0)
	//if(i == 0 && !(SKILL_BASE_NUM(g_pShuttleChild->m_pSkill->GetPreSkillItemNum()) == BGEAR_SKILL_BASENUM_BIG_BOOM))
	{
		sMsg.bYesOrNo = TRUE;				// 승인
		sMsg.AttackCharacterUID = m_stSkillConfirm.AttackCharacterUID;		// 스킬 사용자 CharacterUID
		sMsg.TargetCharacterUID = m_stSkillConfirm.TargetCharacterUID;		// 스킬 타겟 CharacterUID
		sMsg.UsingSkillItemNum = m_stSkillConfirm.UsingSkillItemNum;		// 사용 스킬 ItemNum
	}
	else
	{
		sMsg.bYesOrNo = FALSE;				// 거부
		sMsg.AttackCharacterUID = m_stSkillConfirm.AttackCharacterUID;		// 스킬 사용자 CharacterUID
		sMsg.TargetCharacterUID = m_stSkillConfirm.TargetCharacterUID;		// 스킬 타겟 CharacterUID
		sMsg.UsingSkillItemNum = m_stSkillConfirm.UsingSkillItemNum;		// 사용 스킬 ItemNum
	}

	// 2009. 04. 06 by ckPark 콜오브히어로시 다른 타겟팅 스킬 못쓰는 문제
	sMsg.SkillConfirmUseUID	= m_stSkillConfirm.SkillConfirmUseUID;
	// end 2009. 04. 06 by ckPark 콜오브히어로시 다른 타겟팅 스킬 못쓰는 문제

	g_pFieldWinSocket->SendMsg(T_FC_SKILL_CONFIRM_USE_ACK, (char*)&sMsg, sizeof(sMsg));
	memset(&m_stSkillConfirm, 0, sizeof(MSG_FC_SKILL_CONFIRM_USE));
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::SetSkillConfirmData(MSG_FC_SKILL_CONFIRM_USE *pMsg)
/// \brief		스킬 사용 여부 데이타 임시 저장
/// \author		ispark
/// \date		2005-12-03 ~ 2005-12-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::SetSkillConfirmData(MSG_FC_SKILL_CONFIRM_USE *pMsg)
{
	memcpy(&m_stSkillConfirm, pMsg, sizeof(MSG_FC_SKILL_CONFIRM_USE));
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::CheckConfirmSkillUse()
/// \brief		사용허가가 필요한 스킬인지 체크, 그렇다면 따로 처리
/// \author		ispark
/// \date		2005-12-03 ~ 2005-12-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
CSkillInfo* CSkill::CheckConfirmSkillUse()
{
	vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecUsingSkill.begin();
	while(itvecSkillInfo != m_vecUsingSkill.end())
	{
		// 2006-10-26 by ispark
		// 콜오브히어로
//		if(FindDestParamUseSkill((*itvecSkillInfo)->ItemInfo, DES_SKILL_SUMMON_FORMATION_MEMBER) &&
//			(*itvecSkillInfo)->GetCheckAckWaitingTime() == 0)
		// 2007-12-11 by dgwoo 콜오브 히어로 스킬이 사용 할수 없을때 다른 타겟형 스킬을 
		if(FindDestParamUseSkill((*itvecSkillInfo)->ItemInfo, DES_SKILL_SUMMON_FORMATION_MEMBER) &&
			(*itvecSkillInfo)->GetSkillState() == SKILL_STATE_PREPARE)
		{
			//DbgOut("CheckConfirmSkillUse() %d\n",(*itvecSkillInfo)->GetSkillState());
			return (*itvecSkillInfo);
		}
		itvecSkillInfo++;
	}

	return NULL;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillInfo* CSkill::FindItemEnemySkillInfo(int nSkillItemNumber)
/// \brief		
/// \author		dgwoo
/// \date		2007-01-05 ~ 2007-01-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
CSkillInfo* CSkill::FindItemEnemySkillInfo(int nSkillItemNumber)
{
	FLOG( "CSkill::FindItemSkill(int nSkillItemNumber)" );
	map<int, CSkillInfo*>::iterator itSkillInfo = m_mapEnemySkillInfo.find(nSkillItemNumber);
	if(itSkillInfo != m_mapEnemySkillInfo.end())
	{	
		if(nSkillItemNumber == itSkillInfo->second->ItemNum)
		{
			return itSkillInfo->second;
		}
	}
	return NULL;
}



///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkill::SendConfirmSkillUse(CSkillInfo* pSkillInfo, UID32_t TargetCharacterUniqueNumber)
/// \brief		사용허가 스킬 메세지 보내기
/// \author		ispark
/// \date		2005-12-06 ~ 2005-12-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::SendConfirmSkillUse(CSkillInfo* pSkillInfo, UID32_t TargetCharacterUniqueNumber)
{
	MSG_FC_SKILL_CONFIRM_USE sMsg;
	wsprintf(sMsg.szAttackCharacterName, "%s", g_pShuttleChild->m_myShuttleInfo.CharacterName);		// 스킬 사용자의 CharacterName;
	sMsg.AttackCharacterUID = g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber;				// 스킬 사용자 CharacterUID
	sMsg.TargetCharacterUID = TargetCharacterUniqueNumber;											// 스킬 타겟 CharacterUID
	sMsg.UsingSkillItemNum = pSkillInfo->ItemInfo->ItemNum;											// 사용 스킬 ItemNum
	sMsg.MapChannelIndex = g_pShuttleChild->m_myShuttleInfo.MapChannelIndex;						// 스킬 사용자의 MapChannelIndex
	g_pFieldWinSocket->SendMsg(T_FC_SKILL_CONFIRM_USE, (char*)&sMsg, sizeof(sMsg));
	pSkillInfo->SetCheckAckWaitingTime(12);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::IsUseEventMap(CSkillInfo* pItemSkill)
/// \brief		이벤트 맵에서 사용을 할 수 있는 스킬인가?
/// \author		ispark
/// \date		2006-11-17 ~ 2006-11-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsUseEventMap(CSkillInfo* pItemSkill)
{
	MAP_INFO* pMapInfo = g_pDatabase->GetMapInfo(g_pShuttleChild->m_myShuttleInfo.MapChannelIndex.MapIndex);
	
	// 2006-11-17 by ispark, 이벤트 맵에서는 제외
	if(IS_MAP_INFLUENCE_EVENT_AREA(pMapInfo->MapInfluenceType) &&
		FindDestParamUseSkill(pItemSkill->ItemInfo, DES_SKILL_SUMMON_FORMATION_MEMBER))
	{
		return FALSE;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::IsCancelSkill(CSkillInfo* pSkillInfo)
/// \brief		정화 스킬중에 취소될 스킬인가.
/// \author		dgwoo
/// \date		2007-01-29 ~ 2007-01-29
/// \warning	
///
/// \param		
/// \return		정화 스킬로 인한 취소될 스킬인지 알아온다.
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsCancelSkill(CSkillInfo* pSkillInfo)
{
	// 2007-01-29 by dgwoo 10분 미만인 스킬은 재발동시간까지 초기화한다.
	// 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
// 	if(pSkillInfo->GetSkillState() == SKILL_STATE_USING
// 		&& pSkillInfo->ItemInfo->ReAttacktime < TERM_TICK_MUST_SERVER_CHECK_SKILL_REATTACK_TIME)
	if(pSkillInfo->GetSkillState() == SKILL_STATE_USING
		&& !COMPARE_BIT_FLAG(pSkillInfo->ItemInfo->ItemAttribute, SKILL_ATTR_STORE_USING_TIME))
	// end 2009. 04. 06 by ckPark 재사용 스킬 저장 속성 추가
	{
		return TRUE;
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			INT	CSkill::GetPreSkillItemNum()
/// \brief		시전을 요청하는 중인 기술
/// \author		// 2007-04-05 by bhsohn 빅붐 버그 처리
/// \date		2007-04-05 ~ 2007-04-05
/// \warning	
///
/// \param		
/// \return		정화 스킬로 인한 취소될 스킬인지 알아온다.
///////////////////////////////////////////////////////////////////////////////
INT	CSkill::GetPreSkillItemNum()
{	
	return m_nPreSkillItemNum;
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::InitPreSkillItemNum()
/// \brief		기술정보 초기화
/// \author		// 2007-04-05 by bhsohn 빅붐 버그 처리
/// \date		2007-04-05 ~ 2007-04-05
/// \warning	
///
/// \param		
/// \return		정화 스킬로 인한 취소될 스킬인지 알아온다.
///////////////////////////////////////////////////////////////////////////////
void CSkill::InitPreSkillItemNum()
{
	m_nPreSkillItemNum = 0;
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::SetScanSkill(int nSkillIdx, BOOL bScan)
/// \brief		기술정보 초기화
/// \author		// 2007-04-19 by bhsohn 서치아이 아이템 추가
/// \date		2007-04-19 ~ 2007-04-19
/// \warning	
///
/// \param		
/// \return		정화 스킬로 인한 취소될 스킬인지 알아온다.
///////////////////////////////////////////////////////////////////////////////
void CSkill::SetScanSkill(int nIdx, BOOL bScan)
{
	if(nIdx >= MAX_SCAN )
	{
		return;
	}
	if(bScan)
	{
		m_nScanState |= (1<< nIdx);		
	}
	else
	{
		m_nScanState &= ~(1<< nIdx);
	}

	// 현재 스캔된 버프가 있냐?
	if(m_nScanState)
	{
		m_bScan	= TRUE;
	}
	else
	{
		m_bScan	= FALSE;
	}
}

void CSkill::SetScanPosition(int nIdx, D3DXVECTOR3	vScanPosition)
{
	if(nIdx >= MAX_SCAN )
	{
		return;
	}
	m_vScanPosition[nIdx] = vScanPosition;
}

float CSkill::GetScanRange(int nIdx)								
{
	if(nIdx >= MAX_SCAN )
	{
		return 0;
	}
	return m_fScanRange[nIdx];
}
void CSkill::SetScanRange(int nIdx, float ScanRange)				
{
	if(nIdx >= MAX_SCAN )
	{
		return;
	}
	m_fScanRange[nIdx] = ScanRange;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkillInfo::PrepareSkillFromServer()
/// \brief		
/// \author		// 2007-04-19 by bhsohn 서치아이 아이템 추가
/// \date		2007-04-20 ~ 2007-04-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsCanSeeInvisible(D3DXVECTOR3 vPos)
{
	BOOL bCanSeeInvisible = FALSE;
	if(FALSE == ISScanSkill())
	{
		// 스캔 상태가 아니면 못 본다. 
		return bCanSeeInvisible;
	}
	FLOAT fLength = 0;
	float fScanRange =0;
	for(int nIdx = 0;nIdx < MAX_SCAN;nIdx++)
	{
		fScanRange = GetScanRange(nIdx);
// 2012-11-29 by mspark, 서치아이 위치가 이동하는 캐릭터의 위치와 동일하도록 수정
#ifdef SC_SEARCHEYE_SHUTTLE_POSITION_JHSEOL_MSPARK
		if(SCAN_ITEM == nIdx || SCAN_ITEM2 == nIdx)
		{
			fLength = D3DXVec3Length(&(g_pShuttleChild->m_vPos - vPos));
		}
		else
		{
		fLength = D3DXVec3Length(&(m_vScanPosition[nIdx] - vPos));
		}		
#else
		fLength = D3DXVec3Length(&(m_vScanPosition[nIdx] - vPos));
#endif
// end 2012-11-29 by mspark, 서치아이 위치가 이동하는 캐릭터의 위치와 동일하도록 수정
		if(fLength <= fScanRange)
		{
			// 스캔 거리 안에 들어왔다
			bCanSeeInvisible= TRUE;
			return bCanSeeInvisible;
		}
	}
	return bCanSeeInvisible;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSkill::ReleasePrePareSkill()
/// \brief		
/// \author		// 2007-10-22 by bhsohn 타켓형 스킬 오류에 대한 처리
/// \date		2007-10-22 ~ 2007-10-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::ReleasePrePareSkill()
{
	if(NULL == m_pPriSkillInfo)
	{
		return;
	}
	ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		쉴드 마비 상태인지 체크
/// \author		// 2008-08-27 by bhsohn HP/DP동시에 차는 아이템 추가
/// \date		2008-08-27 ~ 2008-08-27
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsShieldParalyze()
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		CSkillInfo *pSkillInfo = (*itSkillInfo);		
		// 2009-04-21 by bhsohn 아이템 DesParam추가
		//if(IS_EXIST_DES_PARAM(pSkillInfo->ItemInfo,DES_SKILL_SHIELD_PARALYZE))
		if(pSkillInfo->ItemInfo->IsExistDesParam(DES_SKILL_SHIELD_PARALYZE))
		{
			return TRUE;
		}
		itSkillInfo++;
	}	
	return FALSE;

}


// 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현
// 해당 데스 파람이 존재하는 스킬이 걸려 있는가
BOOL	CSkill::IsExistDesParamSKill( BYTE nDesParam )
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		CSkillInfo *pSkillInfo = (*itSkillInfo);		
		if(pSkillInfo->ItemInfo->IsExistDesParam( nDesParam ) )
			return TRUE;
		itSkillInfo++;
	}

	itSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		CSkillInfo *pSkillInfo = (*itSkillInfo);		
		if(pSkillInfo->ItemInfo->IsExistDesParam( nDesParam ) )
			return TRUE;
		itSkillInfo++;
	}

	return FALSE;
}
// end 2009. 09. 21 by ckPark 인피니티 필드 몬스터 스킬 구현


///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		자기 자신에게 쓸수 있는 스킬이냐?
/// \author		// 2008-10-23 by bhsohn 자기 자신한테 힐 단축키 추가
/// \date		2008-10-23 ~ 2008-10-23
/// \warning	
///
/// \param		BYTE		SkillTargetType;				// 스킬 타켓 타입, SKILLTARGETTYPE_XXX
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsTargetToMyShuttle(BYTE	i_bySkillTargetType)
{
	// 자신에게 쓸 수 없는 스킬
	if(i_bySkillTargetType == SKILLTARGETTYPE_ONE_EXCLUDE_ME ||
		i_bySkillTargetType == SKILLTARGETTYPE_PARTY_ONE_EXCLUDE_ME ||
		i_bySkillTargetType == SKILLTARGETTYPE_PARTY_WITHOUT_ME ||			// 두 줄 포함
		i_bySkillTargetType == SKILLTARGETTYPE_INRANGE_WITHOUT_ME ||
		i_bySkillTargetType == SKILLTARGETTYPE_ONE_EXCEPT_OURS)
	{
		return FALSE;
	}
	return TRUE;		
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		자기 자신에게 쓸수 있는 스킬이냐?
/// \author		// 2008-10-23 by bhsohn 자기 자신한테 힐 단축키 추가
/// \date		2008-10-23 ~ 2008-10-23
/// \warning	
///
/// \param		BYTE		SkillTargetType;				// 스킬 타켓 타입, SKILLTARGETTYPE_XXX
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::FindTargetForSkill_ToMe()
{
	SetSkillTargetState(FALSE);		// 스킬 마우스 포인터 해제

	if(NULL == m_pPriSkillInfo)
	{
		return FALSE;
	}
	if(!IsTargetToMyShuttle(m_pPriSkillInfo->ItemInfo->SkillTargetType))
	{
		// 자기 자신 포함 안됌
		char strmsg[256];
		wsprintf(strmsg, STRMSG_C_051205_0001, m_pPriSkillInfo->ItemInfo->ItemName);// "[%s] 스킬은 자신에게 쓸 수 없는 스킬입니다."
		g_pD3dApp->m_pChat->CreateChatChild(strmsg, COLOR_SKILL_CANCEL);
		ReleasePrepareTargetOneSkill(m_pPriSkillInfo->ItemNum);
		return FALSE;		
	}
	else
	{
		SetTargetIndex(g_pShuttleChild->m_myShuttleInfo.ClientIndex);
		return TRUE;	
	}
	return TRUE;

}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkill::IsSkillUse(INT	ItemNum)
/// \brief		
/// \author		// 2009-03-30 by bhsohn 차징샷 이펙트 버그 수정
/// \date		2009-03-30 ~ 2009-03-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkill::IsSkillUse(INT	ItemNum)
{
	vector<CSkillInfo*>::iterator itSkillInfo = m_vecUsingSkill.begin();
	while(itSkillInfo != m_vecUsingSkill.end())
	{
		if(ItemNum == SKILL_BASE_NUM((*itSkillInfo)->ItemNum))
		{
			return TRUE;
		}
		itSkillInfo++;
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		
/// \author		// 2013-05-07 by bhsohn 세력포인트 개선안 시스템
/// \date		2013-05-07 ~ 2013-05-07
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkill::DisableTimeLimitSkill(INT ItemNum)
{
	vector<CSkillInfo*>::iterator itvecSkillInfo = m_vecEnemyUsingSkillForMe.begin();
	while(itvecSkillInfo != m_vecEnemyUsingSkillForMe.end())
	{
		CSkillInfo* pSkillInfo = (*itvecSkillInfo);
		if(pSkillInfo && ItemNum == pSkillInfo->ItemNum)
		{
			pSkillInfo->DisableTimelimitSkill();
		}
		itvecSkillInfo++;
	}
}