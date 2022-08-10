// SkillEffect.cpp: implementation of the CSkillEffect class.
//
//////////////////////////////////////////////////////////////////////

#include "SkillEffect.h"
#include "CharacterInfo.h"
#include "UnitData.h"
#include "AtumDatabase.h"
#include "dxutil.h"

extern CAtumDatabase	*	g_pDatabase;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkillEffect::CSkillEffect(CUnitData* pParent)
{
	m_pParent = pParent;
}

CSkillEffect::~CSkillEffect()
{

}

HRESULT	CSkillEffect::InitDeviceObjects()
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			it->pCharacterInfo->InitDeviceObjects();
		}
		it++;
	}
	return S_OK;
}

HRESULT	CSkillEffect::RestoreDeviceObjects()
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			it->pCharacterInfo->RestoreDeviceObjects();
		}
		it++;
	}
	return S_OK;
}

HRESULT	CSkillEffect::InvalidateDeviceObjects()
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			it->pCharacterInfo->InvalidateDeviceObjects();
		}
		it++;
	}
	return S_OK;
}

HRESULT	CSkillEffect::DeleteDeviceObjects()
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			it->pCharacterInfo->DeleteDeviceObjects();
			SAFE_DELETE(it->pCharacterInfo);
		}
		it++;
	}
	m_vecSkillEffect.clear();
	return S_OK;
}

void CSkillEffect::Tick(float fElapsedTime)
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			// 2004-10-12 by jschoi  ���⼭ ����Ʈ �Ҹ����ִ� �ڵ尡 �ʿ��ϴ�.
			if(it->pCharacterInfo->IsUsing() == FALSE)
			{
				if(it->pCharacterInfo)
				{
					it->pCharacterInfo->InvalidateDeviceObjects();
					it->pCharacterInfo->DeleteDeviceObjects();
					SAFE_DELETE(it->pCharacterInfo);
				}
				m_vecSkillEffect.erase(it);	
				continue;
			}
			else
			{
				it->pCharacterInfo->SetSingleBodyConditionMatrix(BODYCON_CHARGING_MASK,m_pParent->m_mMatrix);
				it->pCharacterInfo->SetSingleBodyConditionMatrix(BODYCON_USE_SKILL_MASK,m_pParent->m_mMatrix);
				it->pCharacterInfo->Tick(fElapsedTime);
			}
			
		}
		it++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::CreateSkillEffect(int nSkillNum)
/// \brief		nSkillNum�� �ش��ϴ� ��ų ����Ʈ�� �����Ͽ� m_vecSkillEffect�� �߰��Ѵ�.
/// \author		jschoi
/// \date		2004-10-11 ~ 2004-10-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::CreateSkillEffect(int nSkillNum, BodyCond_t hySingleBodyCondition)
{
	SkillEffectInfo SkillEffect;
	SkillEffect.nSkillNum = SKILL_BASE_NUM(nSkillNum);
	SkillEffect.pCharacterInfo = new CCharacterInfo();
	char strFileName[32];
	// 2005-08-23 by ispark
	ITEM* pItem = g_pDatabase->GetServerItemInfo(nSkillNum);
//	wsprintf(strFileName,"%08d",SKILL_BASE_NUM(nSkillNum));
	// 2013-03-13 by bhsohn ��ų ��ȣ ���� ����
//	wsprintf(strFileName,"%08d",SKILL_BASE_NUM(pItem->SourceIndex));
	wsprintf(strFileName,"%08d",SKILL_BASE_SOURCEINDEX(pItem->SourceIndex));
	// END 2013-03-13 by bhsohn ��ų ��ȣ ���� ����
	if(SkillEffect.pCharacterInfo->Load(strFileName))
	{
		SkillEffect.pCharacterInfo->InitDeviceObjects();
		// 2009. 11. 23 by jskim ���ҽ� �ε� ���� ����
		SkillEffect.pCharacterInfo->m_LoadingPriority = _NOTHING_STEP;
		//end 2009. 11. 23 by jskim ���ҽ� �ε� ���� ����
		SkillEffect.pCharacterInfo->RestoreDeviceObjects();
		SkillEffect.pCharacterInfo->SetAllBodyConditionMatrix(m_pParent->m_mMatrix);
		SkillEffect.pCharacterInfo->ChangeBodyCondition(hySingleBodyCondition);
	}
	else
	{
		SAFE_DELETE(SkillEffect.pCharacterInfo);	// ��ų ����Ʈ�� ���� ��ų
		DBGOUT("CSkillEffect::CreateSkillEffect, Can't Find Effect File.\n");
	}
	m_vecSkillEffect.push_back(SkillEffect);
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::DeleteSkillEffect(int nSKillNum)
/// \brief		m_vecSkillEffect���� nSkillNum�� �ش��ϴ� ��ų ����Ʈ�� �����Ѵ�.
/// \author		jschoi
/// \date		2004-10-11 ~ 2004-10-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::DeleteSkillEffect(int nSkillNum)
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->nSkillNum == SKILL_BASE_NUM(nSkillNum))
		{
			if(it->pCharacterInfo)
			{
				it->pCharacterInfo->InvalidateDeviceObjects();
				it->pCharacterInfo->DeleteDeviceObjects();
				SAFE_DELETE(it->pCharacterInfo);
			}
			it = m_vecSkillEffect.erase(it);
			continue;
			// 2007-04-05 by dgwoo ����Ʈ�� ���� ���׶����� ���Ŀ��� ��� �˻��Ѵ�.
			//break;
		}
		it++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::ChangeBodyCondition(int nSkillNum, BodyCond_t hySingleBodyCondition)
/// \brief		nSkillNum�� ��ų����Ʈ�� BodyCondition�� �����Ѵ�.
/// \author		jschoi
/// \date		2004-10-11 ~ 2004-10-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::ChangeBodyCondition(int nSkillNum, BodyCond_t hySingleBodyCondition)
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->nSkillNum == SKILL_BASE_NUM(nSkillNum))
		{
			if(it->pCharacterInfo)
			{
				it->pCharacterInfo->ChangeBodyCondition(hySingleBodyCondition);
			}
			break;
		}
		it++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::ChangeBodyConditionMatrix(int nSkillNum, BodyCond_t hySingleBodyCondition, D3DXMATRIX mat)
/// \brief		nSkillNum�� ��ų����Ʈ�� Single BodyCondition�� Matrix�� �����Ѵ�.
/// \author		jschoi
/// \date		2004-10-12 ~ 2004-10-12
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::SetBodyConditionMatrix(BodyCond_t hySingleBodyCondition, D3DXMATRIX mat)
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->pCharacterInfo)
		{
			it->pCharacterInfo->SetSingleBodyConditionMatrix(hySingleBodyCondition, mat);
		}
		it++;
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::FindSkillEffect(int nSkillNum)
/// \brief		nSkillNum�� �ش��ϴ� ����Ʈ CCharacterInfo*�� ã���ش�.
/// \author		jschoi
/// \date		2004-10-11 ~ 2004-10-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
CCharacterInfo* CSkillEffect::FindSkillEffect(int nSkillNum)
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		if(it->nSkillNum == SKILL_BASE_NUM(nSkillNum))
		{
			return it->pCharacterInfo;
		}
		it++;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CSkillEffect::DeleteChargingStateSkillEffect()
/// \brief		��¡ ����Ʈ �߿� ��¡���ΰͰ� ��¡�Ϸ��� �͸� ����
/// \author		dhkwon
/// \date		2004-10-21 ~ 2004-10-21
/// \warning	
///				
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::DeleteChargingStateSkillEffect()
{
 	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		ITEM* pSKILL = g_pDatabase->GetServerItemInfo(it->nSkillNum+1);

		if( pSKILL &&
			pSKILL->SkillType == SKILLTYPE_CHARGING &&
			it->pCharacterInfo &&
			(COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_CHARGING_MASK) ||
			COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_USE_SKILL_MASK)) &&
			(!COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_BULLET_MASK) &&
			!COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_HIT_MASK)))
		{
			it->pCharacterInfo->InvalidateDeviceObjects();
			it->pCharacterInfo->DeleteDeviceObjects();
			SAFE_DELETE(it->pCharacterInfo);
			m_vecSkillEffect.erase(it);
			continue;
		}
		it++;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			DeleteCastingStateSkillEffect()
/// \brief		ĳ���� Ÿ���� �ִ� ����Ʈ�� ��� �����.
/// \author		dgwoo
/// \date		2006-12-13 ~ 2006-12-13
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSkillEffect::DeleteCastingStateSkillEffect()
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		ITEM* pSKILL = g_pDatabase->GetServerItemInfo(it->nSkillNum+1);

		if( pSKILL &&
			pSKILL->AttackTime > 0 &&
			it->pCharacterInfo &&
			(COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_CHARGING_MASK) ||
			COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_USE_SKILL_MASK)) &&
			(!COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_BULLET_MASK) &&
			!COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_HIT_MASK)))
		{
			it->pCharacterInfo->InvalidateDeviceObjects();
			it->pCharacterInfo->DeleteDeviceObjects();
			SAFE_DELETE(it->pCharacterInfo);
			m_vecSkillEffect.erase(it);
			continue;
		}
		it++;
	}
}


// 2009. 09. 21 by ckPark ���Ǵ�Ƽ �ʵ� ���� ��ų ����
void	CSkillEffect::DeleteCastingStateMonsterSkillEffect( void )
{
	vector<SkillEffectInfo>::iterator it = m_vecSkillEffect.begin();
	while(it != m_vecSkillEffect.end())
	{
		ITEM* pSKILL = g_pDatabase->GetServerItemInfo(it->nSkillNum+1);	
// 2012-03-06 by jhahn ��� ����Ʈ ���� ����
		bool BigBoom = true;
		
		for (int i = 0 ; i < SIZE_MAX_DESPARAM_COUNT_IN_ITEM ; i++)
		{
			if(pSKILL->ArrParameterValue[i] == DES_SKILL_BIG_BOOM)	
				BigBoom = true;
		}
//end 2012-03-06 by jhahn ��� ����Ʈ ���� ����

		if( pSKILL
			&& pSKILL->AttackTime > 0
			&& it->pCharacterInfo
			&& (COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_CHARGING_MASK)
			|| COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_USE_SKILL_MASK))
			&& (!COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_BULLET_MASK)
			&& !COMPARE_BODYCON_BIT(it->pCharacterInfo->m_nCurrentBodyCondition,BODYCON_HIT_MASK))
			&& pSKILL->Kind == ITEMKIND_FOR_MON_SKILL
			|| BigBoom) // 2012-03-06 by jhahn ��� ����Ʈ ���� ����
		{
			it->pCharacterInfo->InvalidateDeviceObjects();
			it->pCharacterInfo->DeleteDeviceObjects();
			SAFE_DELETE(it->pCharacterInfo);
			m_vecSkillEffect.erase(it);
			continue;
		}
		it++;
	}
}
// end 2009. 09. 21 by ckPark ���Ǵ�Ƽ �ʵ� ���� ��ų ����

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSkillEffect::CheckTargetSkillEffect(INT ItemNum)
/// \brief		Ÿ�� ��ų ����Ʈ�� �ʿ��Ѱ�?
/// \author		ispark
/// \date		2006-12-08 ~ 2006-12-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSkillEffect::CheckTargetSkillEffect(INT ItemNum)
{
	ITEM *pSkillItem = g_pDatabase->GetServerItemInfo(ItemNum);

	// 2009-04-21 by bhsohn ������ DesParam�߰�
	// ��ĳ��
	//if(IS_EXIST_DES_PARAM(pSkillItem, DES_SKILL_SCANNING))
	if(pSkillItem->IsExistDesParam(DES_SKILL_SCANNING))
	{
		return TRUE;
	}

	return FALSE;
}
