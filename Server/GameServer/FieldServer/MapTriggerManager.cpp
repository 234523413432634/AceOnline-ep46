// MapTriggerManager.cpp: implementation of the CMapTriggerManager class.
//
// \brief		// 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
// \author		hskim
// \date		2011-10-28
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MapTriggerManager.h"
#include "FieldGlobal.h"
#include "AtumDBHelper.h"
#include "FieldMapChannel.h"
#include "TriggerFunction.h"
#include "TriggerFunctionCrystal.h"
#include "TriggerCrystalGroup.h"
#include "TriggerCrystalDestroyGroup.h"
#include "TriggerFunctionNGCInflWar.h"
#include "TriggerNGCInflWarMonsterGroup.h"
#include "TriggerFunctionNGOutPost.h"			// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMapTriggerManager::CMapTriggerManager(DWORD i_nTickInterval /* = 1000 */)
	: CTickManager(i_nTickInterval)
{
	Clear();
}

CMapTriggerManager::~CMapTriggerManager()
{
	Destroy();
}

void CMapTriggerManager::Clear()
{
	m_pFieldIOCP = NULL;

	m_vectorTriggerFunction.clear();

	m_vectTriggerMap.clear();
	m_vectTriggerFunctionCrystal.clear();
	m_vectTriggerCrystalGroup.clear();
	m_vectTriggerCrystalDestroyGroup.clear();

	m_vectTriggerFunctionNGCInflWar.clear();
	m_vectTriggerNGCInflWarMonsterGroup.clear();

	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
	m_vectTriggerFunctionNGCOutPost.clear();	// ���� ���� ���� ����ü ����
	m_vectTriggerOutPostBossKillInfo.clear();	// ���� ���� �������� ����ü ����
	m_vectTriggerCrystalBuff.clear();
	// end 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���

	CleanTickManager();
	// 2013-08-14 by jhseol, ������ ������ - NGC ����
	m_nPlayNGCSPWar = 0;
	m_bPlayingNGCSPWar = FALSE;
	m_bPlayingMSWar = FALSE;
	m_bPlayingOutPostWar = FALSE;
	m_nCountOutPostWar = 0;								// �������� ��������� ī����
	m_nCountMSWar = 0;										// �������� ���� ī����
	// end 2013-08-14 by jhseol, ������ ������ - NGC ����
}

BOOL CMapTriggerManager::Create(CFieldIOCP *pFieldIOCP, CODBCStatement *pOdbcStmt)
{
#ifdef S_EP4_HSKIM		// ON/OFF ��� ����
#else
	return TRUE;
#endif

	if( NULL == pFieldIOCP )
	{
		return FALSE;
	}

	if( FALSE == LoadDB(pOdbcStmt) )
	{
		return FALSE;
	}

	m_pFieldIOCP = pFieldIOCP;

	// �⺻ Ŭ���� ����
	if( FALSE == CreateSubClass() )
	{
		return FALSE;
	}
	
	// ��ũ ����	
	InitTickManager();

	return TRUE;
}

BOOL CMapTriggerManager::MixCrystal()
{
	// ũ����Ż ������ �������� ���´� (������ ON �ϰ��)

	vectorTriggerFunctionCrystal::iterator itrTFC = m_vectTriggerFunctionCrystal.begin();

	for(; itrTFC != m_vectTriggerFunctionCrystal.end(); itrTFC++)
	{
		if( TRUE != itrTFC->RandomSequence )
		{
			continue;
		}

		vectorTriggerMap::iterator itrTF = m_vectTriggerMap.begin();

		for(; itrTF != m_vectTriggerMap.end(); itrTF++)
		{
			if( itrTFC->FunctionID == itrTF->FunctionID )
			{
				// ũ����Ż �׷� ����

				vectorTriggerCrystalGroup::iterator itrTCG = m_vectTriggerCrystalGroup.begin();

				for(; itrTCG != m_vectTriggerCrystalGroup.end(); itrTCG++)
				{
					if( itrTCG->CrystalGroupID == itrTFC->CrystalGroupID )
					{
						vectorTriggerCrystalDestroyGroup::iterator itrTCDG = m_vectTriggerCrystalDestroyGroup.begin();
						
						// ���� ����� ���� ����

						vectorTriggerCrystalDestroyGroup m_vectDestoryGroupOrig;
						vectorTriggerCrystalDestroyGroup m_vectDestoryGroupRand;

						for(; itrTCDG != m_vectTriggerCrystalDestroyGroup.end(); itrTCDG++)
						{
							if( itrTCG->DestroyGroupID == itrTCDG->DestroyGroupID )
							{
								if( 0 == itrTCDG->SequenceNumber )
								{
									STRIGGER_CRYSTAL_DESTROY_GROUP TempDestroyGroup = *itrTCDG;
									
									m_vectDestoryGroupOrig.push_back(TempDestroyGroup);
									m_vectDestoryGroupRand.push_back(TempDestroyGroup);
								}
							}
						}

						int RandomCount = m_vectDestoryGroupOrig.size() * 5;

						if( 0 == RandomCount )
						{
							continue;
						}

						for(int i=0; i<RandomCount; i++)
						{
							int First = RANDI(0, m_vectDestoryGroupOrig.size() - 1);
							int Second = RANDI(0, m_vectDestoryGroupOrig.size() - 1);

							if( First == Second ) continue;

							STRIGGER_CRYSTAL_DESTROY_GROUP TempDestoryGroup;

							TempDestoryGroup = m_vectDestoryGroupRand[First];
							m_vectDestoryGroupRand[First] = m_vectDestoryGroupRand[Second];
							m_vectDestoryGroupRand[Second] = TempDestoryGroup;
						}

						itrTCDG = m_vectTriggerCrystalDestroyGroup.begin();

						for(; itrTCDG != m_vectTriggerCrystalDestroyGroup.end(); itrTCDG++)
						{
							int iCount = m_vectDestoryGroupOrig.size();

							for(int i=0; i<iCount; i++)
							{
								if( itrTCDG->TargetMonster == m_vectDestoryGroupOrig[i].TargetMonster )
								{
									itrTCDG->TargetMonster = m_vectDestoryGroupRand[i].TargetMonster;

									break;
								}
							}
						}

						itrTCDG = m_vectTriggerCrystalDestroyGroup.begin();

						for(; itrTCDG != m_vectTriggerCrystalDestroyGroup.end(); itrTCDG++)
						{
							int a = itrTCDG->DestroyGroupID;
						}

						return TRUE;
					}
				}
			}
		}
	}

	return TRUE;
}

BOOL CMapTriggerManager::CreateSubClass()
{
	// DB���� �о�� �ڷḦ ������ �⺻ ������ �����.


	// ũ����Ż ������ �������� ���´� (������ ON �ϰ��)

	MixCrystal();


	// ũ����Ż �ý���

	vectorTriggerFunctionCrystal::iterator itrTFC = m_vectTriggerFunctionCrystal.begin();

	for(; itrTFC != m_vectTriggerFunctionCrystal.end(); itrTFC++)
	{
		vectorTriggerMap::iterator itrTF = m_vectTriggerMap.begin();

		for(; itrTF != m_vectTriggerMap.end(); itrTF++)
		{
			if( itrTFC->FunctionID == itrTF->FunctionID )
			{
				// Ʈ���� ����

				CTriggerFunctionCrystal *pTriggerFnctionCrystal = new CTriggerFunctionCrystal;

				if( NULL == pTriggerFnctionCrystal )
				{
					Destroy();
					return FALSE;
				}

				if( FALSE == pTriggerFnctionCrystal->OnCreate(this, itrTF->MapTriggerID, itrTF->MapIndex, itrTF->MapChannel, itrTF->FunctionID, MAP_TRIGGER_CRYSTAL) )
				{
					SAFE_DELETE(pTriggerFnctionCrystal);
					Destroy();
										
					return FALSE;
				}

				pTriggerFnctionCrystal->SetCrystalInfo(itrTFC->CrystalGroupID, itrTFC->PeriodTime, itrTFC->RandomSequence);

				if( FALSE == InsertTrigger(pTriggerFnctionCrystal) )
				{
					SAFE_DELETE(pTriggerFnctionCrystal);
					Destroy();
					
					return FALSE;
				}

				// ũ����Ż �׷� ����

				vectorTriggerCrystalGroup::iterator itrTCG = m_vectTriggerCrystalGroup.begin();

				for(; itrTCG != m_vectTriggerCrystalGroup.end(); itrTCG++)
				{
					if( itrTCG->CrystalGroupID == itrTFC->CrystalGroupID )
					{
						CTriggerCrystalGroup *pTriggerCrystalGroup = new CTriggerCrystalGroup;

						if( NULL == pTriggerCrystalGroup )
						{
							Destroy();
							return FALSE;
						}

						if( FALSE == pTriggerCrystalGroup->Create(this, pTriggerFnctionCrystal, itrTCG->DestroyGroupID, itrTCG->EventID) )
						{
							SAFE_DELETE(pTriggerCrystalGroup);
							Destroy();
							
							return FALSE;
						}

						if( FALSE == pTriggerFnctionCrystal->InsertTriggerCrystal(pTriggerCrystalGroup) )
						{
							SAFE_DELETE(pTriggerCrystalGroup);
							Destroy();
							
							return FALSE;
						}

						// �ı� ���� �� ��ǥ ����

						vectorTriggerCrystalDestroyGroup::iterator itrTCDG = m_vectTriggerCrystalDestroyGroup.begin();

						for(; itrTCDG != m_vectTriggerCrystalDestroyGroup.end(); itrTCDG++)
						{
							if( itrTCG->DestroyGroupID == itrTCDG->DestroyGroupID )
							{
								CTriggerCrystalDestroyGroup *pTriggerCrystalDestroyGroup = new CTriggerCrystalDestroyGroup;
								
								if( NULL == pTriggerCrystalDestroyGroup )
								{
									Destroy();
									return FALSE;
								}

								if( FALSE == pTriggerCrystalDestroyGroup->Create(this, pTriggerFnctionCrystal, pTriggerCrystalGroup, itrTCDG->SequenceNumber, itrTCDG->TargetMonster) )
								{
									SAFE_DELETE(pTriggerCrystalDestroyGroup);
									Destroy();

									return FALSE;
								}

								if( FALSE == pTriggerCrystalGroup->InsertTriggerCrystalDestroy(pTriggerCrystalDestroyGroup) )
								{
									SAFE_DELETE(pTriggerCrystalDestroyGroup);
									Destroy();

									return FALSE;
								}
							}
						}

						pTriggerCrystalGroup->SortTriggerCrystalDestroy();
					}
				}
			}
		}
	}

	// NGC ������ �ý���

	vectorTriggerFunctionNGCInflWar::iterator itrTFNGC = m_vectTriggerFunctionNGCInflWar.begin();

	for(; itrTFNGC != m_vectTriggerFunctionNGCInflWar.end(); itrTFNGC++)
	{
		vectorTriggerMap::iterator itrTF = m_vectTriggerMap.begin();

		for(; itrTF != m_vectTriggerMap.end(); itrTF++)
		{
			if( itrTFNGC->FunctionID == itrTF->FunctionID )
			{
				// Ʈ���� ����

				CTriggerFunctionNGCInflWar *pTriggerFnctionNGCInflWar = new CTriggerFunctionNGCInflWar;

				if( NULL == pTriggerFnctionNGCInflWar )
				{
					Destroy();
					return FALSE;
				}

				if( FALSE == pTriggerFnctionNGCInflWar->OnCreate(this, itrTF->MapTriggerID, itrTF->MapIndex, itrTF->MapChannel, itrTF->FunctionID, MAP_TRIGGER_NGC_INFL_WAR) )
				{
					SAFE_DELETE(pTriggerFnctionNGCInflWar);
					Destroy();
										
					return FALSE;
				}

				pTriggerFnctionNGCInflWar->SetNGCInflWarInfo(itrTFNGC->NGCInflWarGroupID,  itrTFNGC->PeriodTime, itrTFNGC->BossMonster, itrTFNGC->WinInfluenceWP, itrTFNGC->LossInfluenceWP, itrTFNGC->FirstDamageGuildWP, itrTFNGC->FixedTimeType, itrTFNGC->DestroyCrystalcount);	// 2013-07-08 by jhseol, Ʈ���� �ý��� Ȯ��

				if( FALSE == InsertTrigger(pTriggerFnctionNGCInflWar) )
				{
					SAFE_DELETE(pTriggerFnctionNGCInflWar);
					Destroy();
					
					return FALSE;
				}

				// 2013-07-08 by jhseol, Ʈ���� �ý��� Ȯ�� - ���� ���� ���� ���� �� ũ����Ż ���� ���
				if ( 0 < pTriggerFnctionNGCInflWar->GetDestroyCrystalcount() )
				{
					vectorTriggerOutPostBossKillInfo::iterator itrBossKillInfo = m_vectTriggerOutPostBossKillInfo.begin();
					for(; itrBossKillInfo != m_vectTriggerOutPostBossKillInfo.end() ; itrBossKillInfo++ )
					{
						if ( itrTFNGC->BossMonster == itrBossKillInfo->BossMonster )
						{
							pTriggerFnctionNGCInflWar->InsertBossMonsterKillInfo(&*itrBossKillInfo);
						}
					}
					
					vectorTriggerCrystalBuff::iterator itrCrystalBuff = m_vectTriggerCrystalBuff.begin();
					for (; itrCrystalBuff != m_vectTriggerCrystalBuff.end() ; itrCrystalBuff++ )
					{
						if ( itrTFNGC->FunctionID == itrCrystalBuff->FunctionID )
						{
							pTriggerFnctionNGCInflWar->InsertCrystalBuff(&*itrCrystalBuff);
						}
					}
				}
				// end 2013-07-08 by jhseol, Ʈ���� �ý��� Ȯ�� - ���� ���� ���� ���� �� ũ����Ż ���� ���

				// NGC ������ ���� - ��ȯ ���� ����

				vectorTriggerNGCInflWarMonsterGroup::iterator itrNGCInflWarMonster = m_vectTriggerNGCInflWarMonsterGroup.begin();

				for(; itrNGCInflWarMonster != m_vectTriggerNGCInflWarMonsterGroup.end(); itrNGCInflWarMonster++)
				{
					if( itrTFNGC->NGCInflWarGroupID == itrNGCInflWarMonster->NGCInflWarGroupID )
					{
						CTriggerNGCInflWarMonsterGroup *pTriggerNGCInflWarMonster = new CTriggerNGCInflWarMonsterGroup;
						
						if( NULL == pTriggerNGCInflWarMonster )
						{
							Destroy();
							return FALSE;
						}

						if( FALSE == pTriggerNGCInflWarMonster->Create(this, pTriggerFnctionNGCInflWar, itrNGCInflWarMonster->Monster, itrNGCInflWarMonster->SummonCount, itrNGCInflWarMonster->SummonRandomPos) )
						{
							SAFE_DELETE(pTriggerNGCInflWarMonster);
							Destroy();

							return FALSE;
						}

						if( FALSE == pTriggerFnctionNGCInflWar->InsertNGCInflWarMonster(pTriggerNGCInflWarMonster) )
						{
							SAFE_DELETE(pTriggerNGCInflWarMonster);
							Destroy();

							return FALSE;
						}
					}
				}
			}
		}
	}

	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý��� - NGC Ʈ���� ���
#ifdef S_TRIGGER_OUTPOST_JHSEOL	// - NGC Ʈ���� ���
	vectorTriggerFunctionNGCOutPost::iterator	itrNGCOutPost = m_vectTriggerFunctionNGCOutPost.begin();
	for(; itrNGCOutPost != m_vectTriggerFunctionNGCOutPost.end(); itrNGCOutPost++)
	{
		vectorTriggerMap::iterator itrTF = m_vectTriggerMap.begin();
		
		for(; itrTF != m_vectTriggerMap.end(); itrTF++)
		{
			if( itrNGCOutPost->FunctionID == itrTF->FunctionID )
			{
				// Ʈ���� ������ Ʈ����ID�� ���������� Ʈ����ID�� ������ �������� Ŭ���� ��ü����
				CTriggerFunctionNGOutPost *pTriggerFnctionNGCOutPost = new CTriggerFunctionNGOutPost;
				
				if( NULL == pTriggerFnctionNGCOutPost )
				{
					Destroy();
					return FALSE;
				}
				
				if( FALSE == pTriggerFnctionNGCOutPost->OnCreate(this, itrTF->MapTriggerID, itrTF->MapIndex, itrTF->MapChannel, itrTF->FunctionID, MAP_TRIGGER_NGC_OUTPOST) )
				{
					SAFE_DELETE(pTriggerFnctionNGCOutPost);
					Destroy();
					
					return FALSE;
				}
				
				pTriggerFnctionNGCOutPost->SetNGCOutPostInfo(itrNGCOutPost->SummonMonsterGroupID, itrNGCOutPost->StandardOutPostMap, itrNGCOutPost->BossMonster, itrNGCOutPost->WinInfluenceWP, itrNGCOutPost->LossInfluenceWP, itrNGCOutPost->NextOutPostMap, itrNGCOutPost->DestroyCrystalcount);
				
				if( FALSE == InsertTrigger(pTriggerFnctionNGCOutPost) )
				{
					SAFE_DELETE(pTriggerFnctionNGCOutPost);
					Destroy();
					
					return FALSE;
				}

				vectorTriggerOutPostBossKillInfo::iterator itrBossKillInfo = m_vectTriggerOutPostBossKillInfo.begin();
				for(; itrBossKillInfo != m_vectTriggerOutPostBossKillInfo.end() ; itrBossKillInfo++ )
				{
					if ( itrNGCOutPost->BossMonster == itrBossKillInfo->BossMonster )
					{
						pTriggerFnctionNGCOutPost->InsertBossMonsterKillInfo(&*itrBossKillInfo);
					}
				}

				vectorTriggerCrystalBuff::iterator itrCrystalBuff = m_vectTriggerCrystalBuff.begin();
				for (; itrCrystalBuff != m_vectTriggerCrystalBuff.end() ; itrCrystalBuff++ )
				{
					if ( itrNGCOutPost->FunctionID == itrCrystalBuff->FunctionID )
					{
						pTriggerFnctionNGCOutPost->InsertCrystalBuff(&*itrCrystalBuff);
					}
				}

				// NGC �������� ��ȯ ���� ���� ���
				
				vectorTriggerNGCInflWarMonsterGroup::iterator itrNGCOutPostSummonMonster = m_vectTriggerNGCInflWarMonsterGroup.begin();
				
				for(; itrNGCOutPostSummonMonster != m_vectTriggerNGCInflWarMonsterGroup.end(); itrNGCOutPostSummonMonster++)
				{
					if( itrNGCOutPost->SummonMonsterGroupID == itrNGCOutPostSummonMonster->NGCInflWarGroupID )
					{
						CTriggerNGCInflWarMonsterGroup *pTriggerFnctionNGCOutPostSummonMonster = new CTriggerNGCInflWarMonsterGroup;
						
						if( NULL == pTriggerFnctionNGCOutPostSummonMonster )
						{
							Destroy();
							return FALSE;
						}
						
						if( FALSE == pTriggerFnctionNGCOutPostSummonMonster->Create(this, pTriggerFnctionNGCOutPost, itrNGCOutPostSummonMonster->Monster, itrNGCOutPostSummonMonster->SummonCount, itrNGCOutPostSummonMonster->SummonRandomPos) )
						{
							SAFE_DELETE(pTriggerFnctionNGCOutPostSummonMonster);
							Destroy();
							
							return FALSE;
						}
						
						if( FALSE == pTriggerFnctionNGCOutPost->InsertNGCOutPostSummonMonster(pTriggerFnctionNGCOutPostSummonMonster) )
						{
							SAFE_DELETE(pTriggerFnctionNGCOutPostSummonMonster);
							Destroy();
							
							return FALSE;
						}
					}
				}
			}
		}
	}
#endif	// #ifdef S_TRIGGER_OUTPOST_JHSEOL
	// end 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý��� - NGC Ʈ���� ���

	return TRUE;
}

BOOL CMapTriggerManager::LoadDB(CODBCStatement *pOdbcStmt)
{
	if ( NULL == pOdbcStmt )
	{
		return FALSE;
	}

	// �⺻ Ʈ���� ����

	if( FALSE == CAtumDBHelper::DBLoadTriggerMapInfo(pOdbcStmt , &m_vectTriggerMap, FALSE) )
	{
		return FALSE;
	}

	// ���Ϸ� �ý���

	if( FALSE == CAtumDBHelper::DBLoadTriggerFunctionCrystalInfo(pOdbcStmt , &m_vectTriggerFunctionCrystal, FALSE) )
	{
		return FALSE;
	}

	if( FALSE == CAtumDBHelper::DBLoadTriggerCrystalGroupInfo(pOdbcStmt , &m_vectTriggerCrystalGroup, FALSE) )
	{
		return FALSE;
	}

	if( FALSE == CAtumDBHelper::DBLoadTriggerCrystalDestroyGroupInfo(pOdbcStmt , &m_vectTriggerCrystalDestroyGroup, FALSE) )
	{
		return FALSE;
	}

	// NGC ������ �ý���

	if( FALSE == CAtumDBHelper::DBLoadTriggerFunctionNGCInflWarInfo(pOdbcStmt , &m_vectTriggerFunctionNGCInflWar, FALSE) )
	{
		return FALSE;
	}

	if( FALSE == CAtumDBHelper::DBLoadTriggerNGCInflWarMonsterGroupInfo(pOdbcStmt , &m_vectTriggerNGCInflWarMonsterGroup, FALSE) )
	{
		return FALSE;
	}

	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý��� - NGC Ʈ���� ���� DB�ε�
#ifdef S_TRIGGER_OUTPOST_JHSEOL	// - NGC Ʈ���� ���� DB�ε�
	if( FALSE == CAtumDBHelper::DBLoadTriggerFunctionNGCOutPostInfo(pOdbcStmt , &m_vectTriggerFunctionNGCOutPost, FALSE) )
	{
		return FALSE;
	}
	
	if( FALSE == CAtumDBHelper::DBLoadTriggerOutPostBossKillInfo(pOdbcStmt , &m_vectTriggerOutPostBossKillInfo, FALSE) )
	{
		return FALSE;
	}

	if( FALSE == CAtumDBHelper::DBLoadTriggerCrystalBuffInfo(pOdbcStmt, &m_vectTriggerCrystalBuff, FALSE) )
	{
		return FALSE;
	}
#endif	// #ifdef S_TRIGGER_OUTPOST_JHSEOL
	// end 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý��� - NGC Ʈ���� ���� DB�ε�

	// 2013-08-14 by jhseol, ������ ������ - NGC ���� : NGC������ �����ð� ��������
#ifdef SC_STRATEGYPOINTWAR_RENEWAL_JHSEOL_SSJUNG	// - NGC������ �����ð� ��������
	m_atNGCSPCreateTime.SetCurrentDateTime();
	CAtumDBHelper::DBLoadTriggerNGCSPCreateTime(&m_OdbcStmt, &m_atNGCSPCreateTime);
#endif
	// end 2013-08-14 by jhseol, ������ ������ - NGC ���� : NGC������ �����ð� ��������
	return TRUE;
}

void CMapTriggerManager::Destroy()
{
	for_each(m_vectorTriggerFunction.begin(), m_vectorTriggerFunction.end(), Delete_Object());

	Clear();
}

BOOL CMapTriggerManager::InsertTrigger(CTriggerFunction *pTriggerFunction)
{
	if( NULL == pTriggerFunction )
	{
		return FALSE;
	}

	m_vectorTriggerFunction.push_back(pTriggerFunction);

	return TRUE;
}

int CMapTriggerManager::LinkToTriggerFunction(MAP_CHANNEL_INDEX MapChannel, CFieldMapChannel *pFieldMapChannel, vector<CTriggerFunction *> *pvectorTriggerFunction)
{
	int iCount = 0;

	pvectorTriggerFunction->clear();

	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];

		if( pTriggerFunction->m_TriggerInfo.MapIndex == MapChannel.MapIndex 
			&& pTriggerFunction->m_TriggerInfo.MapChannel == MapChannel.ChannelIndex )
		{
			pTriggerFunction->LinkToFieldMapChannel(pFieldMapChannel);
			pvectorTriggerFunction->push_back(pTriggerFunction);
			iCount++;

			g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] MapTrigger Setting Successed !! (TriggerID %d) (MapIndex %d) (ChannelIndex %d) (FunctionID %d) (TriggerType %d)\r\n", 
				pTriggerFunction->m_TriggerInfo.MapTriggerID,
				pTriggerFunction->m_TriggerInfo.MapIndex,
				pTriggerFunction->m_TriggerInfo.MapChannel,
				pTriggerFunction->m_TriggerInfo.FunctionID,
				pTriggerFunction->m_TriggerType);
		}
	}

	return iCount;
}

BOOL CMapTriggerManager::SkipEventByTriggerID(INT iMapTriggerID)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];

		if( 0 == iMapTriggerID || iMapTriggerID == pTriggerFunction->m_TriggerInfo.MapTriggerID )
		{
			pTriggerFunction->OnEventSkip();

			g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] MapTrigger EventSkip !! (TriggerID %d) (MapIndex %d) (ChannelIndex %d) (FunctionID %d) (TriggerType %d)", 
				pTriggerFunction->m_TriggerInfo.MapTriggerID,
				pTriggerFunction->m_TriggerInfo.MapIndex,
				pTriggerFunction->m_TriggerInfo.MapChannel,
				pTriggerFunction->m_TriggerInfo.FunctionID,
				pTriggerFunction->m_TriggerType);
		}
	}	
	
	return TRUE;
}

BOOL CMapTriggerManager::SkipEventByMapChannelIndex(MAP_CHANNEL_INDEX MapChannelIndex)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];

		if( MapChannelIndex.MapIndex == pTriggerFunction->m_TriggerInfo.MapIndex &&
			MapChannelIndex.ChannelIndex == pTriggerFunction->m_TriggerInfo.MapChannel )
		{
			pTriggerFunction->OnEventSkip();

			g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] MapTrigger EventSkip !! (TriggerID %d) (MapIndex %d) (ChannelIndex %d) (FunctionID %d) (TriggerType %d)", 
				pTriggerFunction->m_TriggerInfo.MapTriggerID,
				pTriggerFunction->m_TriggerInfo.MapIndex,
				pTriggerFunction->m_TriggerInfo.MapChannel,
				pTriggerFunction->m_TriggerInfo.FunctionID,
				pTriggerFunction->m_TriggerType);
		}
	}	
	
	return TRUE;
}

// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���	- �׽�Ʈ�� ũ����Ż ���� ����
BOOL CMapTriggerManager::FixedBuffItemChannelIndex(MAP_CHANNEL_INDEX MapChannelIndex, INT i_nFixedBuffItem)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];
		
		if( MapChannelIndex.MapIndex == pTriggerFunction->m_TriggerInfo.MapIndex &&
			MapChannelIndex.ChannelIndex == pTriggerFunction->m_TriggerInfo.MapChannel )
		{
			pTriggerFunction->OnFixedBuffItem(i_nFixedBuffItem);
		}
	}	
	return TRUE;
}
// end 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���	- �׽�Ʈ�� ũ����Ż ���� ����

// 2012-12-17 by hskim, NPC ���� ����۽� - Ʈ���� �ý��� �ʱ�ȭ ����
BOOL CMapTriggerManager::ResetEventByMapChannel(MAP_CHANNEL_INDEX MapChannelIndex)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];

		if( MapChannelIndex.MapIndex == pTriggerFunction->m_TriggerInfo.MapIndex &&
			MapChannelIndex.ChannelIndex == pTriggerFunction->m_TriggerInfo.MapChannel )
		{
			pTriggerFunction->OnEventSkip(FALSE);

			g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] MapTrigger EventReset !! (TriggerID %d) (MapIndex %d) (ChannelIndex %d) (FunctionID %d) (TriggerType %d)", 
				pTriggerFunction->m_TriggerInfo.MapTriggerID,
				pTriggerFunction->m_TriggerInfo.MapIndex,
				pTriggerFunction->m_TriggerInfo.MapChannel,
				pTriggerFunction->m_TriggerInfo.FunctionID,
				pTriggerFunction->m_TriggerType);
		}
	}	
	
	return TRUE;
}
// end 2012-12-17 by hskim, NPC ���� ����۽� - Ʈ���� �ý��� �ʱ�ȭ ����

// 2013-08-14 by jhseol, ������ ������ - NGC ����
void CMapTriggerManager::InitOdbcStmt()
{
	m_OdbcStmt.Init(g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (LPCSTR)g_pGlobalGameServer->GetODBCUID(), (LPCSTR)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetMainWndHandle());
}

void CMapTriggerManager::CountChangeNGCSPWar(BOOL i_bCountPlus/* = FALSE*/)
{
#ifdef SC_STRATEGYPOINTWAR_RENEWAL_JHSEOL_SSJUNG
	BYTE tmBeforeCount = m_nPlayNGCSPWar;
	if ( TRUE == i_bCountPlus )
	{
		m_nPlayNGCSPWar = m_nPlayNGCSPWar + 1;
		m_bPlayingNGCSPWar = TRUE;
		if ( 0 == tmBeforeCount )
		{
			m_pFieldIOCP->m_InflWarManager.SetDoingInfluenceWar();
			m_atNGCSPWarStartTime.SetCurrentDateTime();
		}
	}
	else
	{
		m_nPlayNGCSPWar = max(m_nPlayNGCSPWar - 1, 0);
	}

	if ( 0 < tmBeforeCount && 0 == m_nPlayNGCSPWar )
	{
		// ��� NGC�������� ����Ȱ��� �ǹ�
		m_bPlayingNGCSPWar = FALSE;		// 2013-10-24 by jhseol, NGC������ ������ ũ����Ż �ı��ȵǴ� ���� ���� - m_bPlayingNGCSPWar üũ ����Ʈ ��ġ ����
		m_pFieldIOCP->m_InflWarManager.SetDoingInfluenceWar();
		SetNGCSPCreateTime();
		//m_bPlayingNGCSPWar = FALSE;		// 2013-10-24 by jhseol, NGC������ ������ ũ����Ż �ı��ȵǴ� ���� ���� - m_bPlayingNGCSPWar üũ ����Ʈ ��ġ ���� (�ּ�ó��)
		m_atNGCSPWarFinishTime.SetCurrentDateTime();
		for(int i=0; i<m_vectorTriggerFunction.size(); i++)
		{
			CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];
			pTriggerFunction->OnFinishTrigger();
		}	
	}
#endif
	return;
}

void CMapTriggerManager::SetNGCSPCreateTime()
{
	m_atNGCSPCreateTime.SetCurrentDateTime();
	ATUM_DATE_TIME CurrentTime;
	struct tm localStTime;
	INT nAddDay = 0;
	INT nAddMinute = RANDI(0, 120);		// 2�ð��� ���� (���� 7�� ~ 9�� ���� ���� : 2 �ð� * 60 ��  = 120 ��)
	CurrentTime.SetCurrentDateTime();
	CurrentTime.Convert(localStTime);

	switch(localStTime.tm_wday)					// �Ͽ��� ���� �����ϰ� ���۰� 0
	{
	case 0:	//��
	case 1:	//��
	case 2:	//ȭ
		nAddDay = 3 - (INT)localStTime.tm_wday;	// ���̳��� �ϼ���ŭ ���ϸ� ������
		break;
	case 3:	//��
		nAddDay = 3;							// 3���� ���ϸ� �����
		break;
	case 4:	//��
	case 5:	//��
		nAddDay = 6 - (INT)localStTime.tm_wday;	// ���̳��� �ϼ���ŭ ���ϸ� �����
		break;
	case 6:	//��
		nAddDay = 4;							// 4���� ���ϸ� ������
		break;
	}

	m_atNGCSPCreateTime.SetDateTime(CurrentTime.Year, CurrentTime.Month, CurrentTime.Day, 19, 0, 0);
	m_atNGCSPCreateTime.AddDateTime(0, 0, nAddDay, 0, nAddMinute, 0);			// ���̳��� �ϼ���ŭ ���ϱ� ���� 7�� ���� ���� �ð� �Ŀ� ���� NGC���� ����
	CAtumDBHelper::DBInsertTriggerNGCSPCreateTime(&m_OdbcStmt, m_atNGCSPCreateTime);
}

BOOL CMapTriggerManager::ISPossibleNGCSPCreate()
{
	ATUM_DATE_TIME atCurrentTime(true);
	if ( atCurrentTime >= m_atNGCSPCreateTime && FALSE == m_bPlayingOutPostWar && FALSE == m_bPlayingMSWar )
	{
		return TRUE;
	}
	return FALSE;
};

void CMapTriggerManager::SetMSWarState(BOOL i_bState)
{
	if ( TRUE == i_bState )
	{
		m_nCountMSWar = m_nCountMSWar + 1;
		m_bPlayingMSWar = TRUE;
	}
	else
	{
		m_nCountMSWar = max(m_nCountMSWar - 1, 0);
		if ( 0 == m_nCountMSWar )
		{
			m_bPlayingMSWar = FALSE;
		}
	}
}

void CMapTriggerManager::SetOutPostWarState(BOOL i_bState)
{
	if ( TRUE == i_bState )
	{
		m_nCountOutPostWar = m_nCountOutPostWar + 1;
		m_bPlayingOutPostWar = TRUE;
	}
	else
	{
		m_nCountOutPostWar = max(m_nCountOutPostWar - 1, 0);
		if ( 0 == m_nCountOutPostWar )
		{
			m_bPlayingOutPostWar = FALSE;
		}
	}
}

void CMapTriggerManager::DeleteContribute(MAP_CHANNEL_INDEX i_nMapChannelIndex, UID32_t i_nCUID, INT i_nMonsterNum)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];
		
		if( i_nMapChannelIndex.MapIndex == pTriggerFunction->m_TriggerInfo.MapIndex &&
			i_nMapChannelIndex.ChannelIndex == pTriggerFunction->m_TriggerInfo.MapChannel )
		{
			pTriggerFunction->OnDeleteContribute(i_nCUID, i_nMonsterNum);
		}
	}	
}

void CMapTriggerManager::StrategyPointDisPlayBySocket(CFieldIOCPSocket *pIOCPSocket)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];
		pTriggerFunction->OnStrategyPointDisPlayBySocket(pIOCPSocket);
	}	
}
// end 2013-08-14 by jhseol, ������ ������ - NGC ����

//////////////////////////////////////////////////////////////////////
// Tick Timer
//////////////////////////////////////////////////////////////////////

BOOL CMapTriggerManager::InitTickManager()
{
	return CTickManager::InitTickManager();
}

void CMapTriggerManager::CleanTickManager()
{
	CTickManager::CleanTickManager();
}

void CMapTriggerManager::DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent)
{
#ifdef _DEBUG
	DBGOUT(STRMSG_S_F2NOTIFY_0141, pDateTime->GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
#endif

	return;
}

void CMapTriggerManager::DoMonthlyWork(ATUM_DATE_TIME *pDateTime)
{
}

void CMapTriggerManager::DoEveryTickWork(ATUM_DATE_TIME *pDateTime)
{
}

void CMapTriggerManager::DoDailyWork(ATUM_DATE_TIME *pDateTime)
{
}

void CMapTriggerManager::DoHourlyWork(ATUM_DATE_TIME *pDateTime)
{
}

void CMapTriggerManager::DoMinutelyWork(ATUM_DATE_TIME *pDateTime)
{
	for(int i=0; i<m_vectorTriggerFunction.size(); i++)
	{
		CTriggerFunction *pTriggerFunction = m_vectorTriggerFunction[i];

		pTriggerFunction->DoMinutelyWork(pDateTime);
	}
}

void CMapTriggerManager::DoSecondlyWork(ATUM_DATE_TIME *pDateTime)
{
}