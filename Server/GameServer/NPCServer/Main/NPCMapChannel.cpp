// NPCMapChannel.cpp: implementation of the CNPCMapChannel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NPCMapChannel.h"
#include "NPCMonster.h"
#include "NPCMapWorkspace.h"
#include "NPCMapProject.h"
#include "NPCGlobal.h"
#include "MonsterDBAccess.h"
#include "NPCIOCP.h"
#include "DebugCheckTime.h"
#include "SkinnedMesh.h"


#define MONSTER_CREATION_HEIGHTGAP_WITH_MAPHEIGHT			100
#define MONSTER_CREATION_MAX_HEIGHTGAP_WITH_MAPHEIGHT		500
#define MONSTER_MIN_SET_TARGET_INDEX_TIME					7000				// ���Ͱ� TargetIndex�� �����ϸ� �ֵ� �̽ð� ������ TargetIndex�� ������ �ʴ´�


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNPCMapChannel::CNPCMapChannel(CNPCMapWorkspace *i_pWorkspace,
							   CNPCMapProject *i_pProject,
							   ChannelIndex_t i_nChannelIndex)
	: CMapChannel(i_pWorkspace, i_pProject, i_nChannelIndex)
	, m_vectorMonsterCreateRegionInfoEX(i_pProject->m_vectorMONSTER_CREATE_REGION_INFO.size())
// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - CNPCIOCP �� �̵� ��.
//	, m_vectorClientInfo(SIZE_MAX_FIELDSERVER_SESSION)
{
	m_pNPCMapWorkspace			= i_pWorkspace;
	m_pNPCMapProject			= i_pProject;
	m_pNPCIOCPServer			= (CNPCIOCP*)i_pWorkspace->m_pIOCPServer;
	m_vectorObjectMonsterInfoCopy = m_pNPCMapProject->m_vectorObjectMonsterInfo;
	
	///////////////////////////////////////////////////////////////////////////////
	DWORD dwTick = timeGetTime();
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ� - �Ʒ��� ���� ������
//	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
//	{// 2006-11-22 by cmkwon, ������Ʈ ���� ���� ��ȯ���� �ð� ����
//		if(itr->m_EventInfo.m_byBossMonster)
//		{
//			itr->m_EventInfo.m_dwLastTimeObjectMonsterCreated	= dwTick;	// 2006-11-22 by cmkwon
//			itr->dwObjBossMonResTime	= (3 + itr->m_EventInfo.m_EventwParam3/3 + RANDI(1, itr->m_EventInfo.m_EventwParam3*2/3))*60*1000;
//		}
//	}
	while(itr != m_vectorObjectMonsterInfoCopy.end())
	{
		OBJECTINFOSERVER *pObjInfoServ = &*itr;
		pObjInfoServ->m_pMonsterInfo	= m_pNPCIOCPServer->GetMonsterInfo(pObjInfoServ->m_EventInfo.m_nObejctMonsterUnitKind);
		if(NULL == pObjInfoServ->m_pMonsterInfo)
		{// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ� - ���� ������ ã���� ������ �α� �����
			char	szError[1024];
			sprintf(szError, "[Error] CNPCMapChannel::CNPCMapChannel invalid MonsterType, MAP(%4d) ObjectMonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
				, this->m_MapChannelIndex.MapIndex, pObjInfoServ->m_EventInfo.m_EventwParam1, pObjInfoServ->m_EventInfo.m_nObejctMonsterUnitKind);
			g_pNPCGlobal->WriteSystemLog(szError);
			DbgOut(szError);

			itr = m_vectorObjectMonsterInfoCopy.erase(itr);
			continue;
		}

		if(itr->m_EventInfo.m_byBossMonster)
		{
			itr->m_EventInfo.m_dwLastTimeObjectMonsterCreated	= dwTick;	// 2006-11-22 by cmkwon
			// 2009-10-23 by cmkwon, NPCServer 0���� ������ ���� ���� - CNPCMapChannel::CNPCMapChannel#,
			itr->dwObjBossMonResTime	= (3 + itr->m_EventInfo.m_EventwParam3/3 + RANDI(1, max(1,itr->m_EventInfo.m_EventwParam3*2/3)))*60*1000;
		}
		
		itr++;
	}
	

	m_uiMissileUniqueIndex		= 0;
	m_uiAttackedItemUniqueIndex	= 0;
	m_CityWarOccupyGuildUID		= INVALID_GUILD_UID;

	m_dwWorkeredTick			= 0;		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 
	m_bExistUserInMapChannel	= FALSE;	// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 
	m_dwChangedTickforExistUser	= 0;		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 

// 	static int sTotalCount	= 0;
// 	static int sTotalByte	= 0;
// 	sTotalCount	+= m_nSizemtvectorMonsterPtr;
// 	sTotalByte	+= sizeof(CNPCMonster) * m_nSizemtvectorMonsterPtr;
// 	g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] 100408 CNPCMonster TotalCount(%8d) TotalBytes(%8d) \r\n", sTotalCount, sTotalByte);

	m_ArrNPCMonster				= new CNPCMonster[m_nSizemtvectorMonsterPtr];
	m_mtvectorMonsterPtr.lock();
	m_mtvectorMonsterPtr.reserve(m_nSizemtvectorMonsterPtr);
	int i;
	for(i = 0;i < m_nSizemtvectorMonsterPtr; i++)
	{
		m_ArrNPCMonster[i].SetMonsterIndex(i + MONSTER_CLIENT_INDEX_START_NUM);
		m_mtvectorMonsterPtr.push_back(&m_ArrNPCMonster[i]);
	}
	m_mtvectorMonsterPtr.unlock();

// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - CNPCIOCP �� �̵� ��.
//	for(i = 0; i < SIZE_MAX_FIELDSERVER_SESSION; i++)
//	{		
//		m_vectorClientInfo[i].ClientIndex	= i;
//		m_vectorClientInfo[i].ResetClientInfo();
//	}
	
	for( i = 0; i < m_vectorMonsterCreateRegionInfoEX.size(); i++)
	{
		m_vectorMonsterCreateRegionInfoEX[i].nCreatedCount		= 0;
		m_vectorMonsterCreateRegionInfoEX[i].nCurrentCount		= 0;
		m_vectorMonsterCreateRegionInfoEX[i].dwLastTimeMonsterCreate = dwTick;
		m_vectorMonsterCreateRegionInfoEX[i].dwBossMonResTime	= 5000;

		if(i_pProject->m_vectorMONSTER_CREATE_REGION_INFO[i].bMonType == MONSTER_CREATETYPE_BOSS)
		{
			// 2006-12-11 by cmkwon, �Ϲ� ���� ���ʹ� NPC ���� ���� �� 5�а�� �Ŀ� �ߵ��� ����
			m_vectorMonsterCreateRegionInfoEX[i].dwBossMonResTime = 5*60*1000;
		}

		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �ʿ��� ���� �ð��� ù ��ȯ�ð��̰� �� �� ��ȯ�� ���ʹ� �� �̻� ��ȯ��Ű�� �ʴ´�.
//		if(IS_MAP_INFLUENCE_INFINITY(this->GetMapInfluenceTypeW()))	{
//			if(i_pProject->m_vectorMONSTER_CREATE_REGION_INFO[i].bMonType == MONSTER_CREATETYPE_BOSS) { 
//				// ������ 1�� ����
//				m_vectorMonsterCreateRegionInfoEX[i].dwBossMonResTime = m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO[i].sResTime * 60 * TICK_CREATE_MONSTER_TERM;
//			}
//			else {
//				// ���� ���ܴ� �ʴ���
//				m_vectorMonsterCreateRegionInfoEX[i].dwBossMonResTime = m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO[i].sResTime * TICK_CREATE_MONSTER_TERM;
//			}
//		}

	}

	m_bNotCreateMonster	= FALSE;	// 2007-08-29 by dhjin

	m_bAutoCreateMonsterChannel = m_pNPCMapProject->m_bAutoCreateMonster;	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -  ä�� ���� Ȯ���Ѵ�.
	m_mtDeletedObjectInfoList.clear();		// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ, // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!!
	m_mtNewObjectInfoList.clear();			// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ, // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!!
	
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.reserve(10);
	m_mtvectorMSG_FN_MONSTER_CREATE_OKProcess.reserve(10);
	m_mtvectorMSG_FN_MONSTER_DELETE.reserve(10);
	m_mtvectorMSG_FN_MONSTER_DELETEProcess.reserve(10);
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.reserve(10);
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILLProcess.reserve(10);
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.reserve(10);
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTERProcess.reserve(10);
	m_mtvectorMSG_FN_CITYWAR_START_WAR.reserve(2);
	m_mtvectorMSG_FN_CITYWAR_END_WAR.reserve(2);
	m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.reserve(2);
	m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.reserve(1);		
	m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.reserve(1);		
	m_mtvectMSG_MONSTER_SUMMON_BY_BELL.reserve(1);			// 2007-09-19 by cmkwon, Bell�� ��ȯ ó��
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.reserve(10);	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Key���� ����
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.reserve(10);	// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.reserve(10);	// 2011-05-11 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
}

CNPCMapChannel::~CNPCMapChannel()
{
	SAFE_DELETE_ARRAY(m_ArrNPCMonster);
}

//////////////////////////////////////////////////////////////////////
// Method
//////////////////////////////////////////////////////////////////////

BOOL CNPCMapChannel::InitMapChannel(void)
{
	CMapChannel::InitMapChannel();
	
	
	ResetMapChannel();
	
	return TRUE;
}

CNPCMonster * CNPCMapChannel::GetNPCMonster(ClientIndex_t i_MonsterIndex)
{
	int mIdx = i_MonsterIndex - MONSTER_CLIENT_INDEX_START_NUM;
	if(FALSE == IS_VALID_ARRAY_INDEX(mIdx, m_nSizemtvectorMonsterPtr))
	{
		return NULL;
	}

	return &m_ArrNPCMonster[mIdx];
}

// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::GetClientInfo#
CLIENT_INFO* CNPCMapChannel::GetClientInfo(int i_Characteridx, MAP_CHANNEL_INDEX *i_pMapChann/*=NULL*/)
{
	// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
	//return m_pNPCIOCPServer->GetClientInfoO(i_Characteridx);		// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - 
	///////////////////////////////////////////////////////////////////////////////	
	// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
	CLIENT_INFO *pCliInfo = m_pNPCIOCPServer->GetClientInfoO(i_Characteridx);
	if(NULL == pCliInfo)
	{
		return NULL;
	}
	if(i_pMapChann
		&& FALSE == i_pMapChann->IsSameMapChannelIndex(pCliInfo->MapChannelIdx))
	{
		return NULL;
	}
	return pCliInfo;

// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - ���� ���� m_pNPCIOCPServer->GetClientInfoO()�� ȣ�� ��.
// 	if(FALSE == IS_VALID_ARRAY_INDEX(i_Characteridx, SIZE_MAX_FIELDSERVER_SESSION))
// 	{
// 		return NULL;
// 	}
// 
// 	return &m_vectorClientInfo[i_Characteridx];
}

MONSTER_CREATE_REGION_INFO_EX * CNPCMapChannel::GetMonsterCreateRegionInfoEXWidhIndex(int i_nCreateRegionIdex)
{
	if(FALSE == IS_VALID_ARRAY_INDEX(i_nCreateRegionIdex, m_vectorMonsterCreateRegionInfoEX.size()))
	{
		return NULL;
	}
	return &m_vectorMonsterCreateRegionInfoEX[i_nCreateRegionIdex];
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::CreateMonsterMapChannel(BYTE *pSendBuf, vector<D3DXVECTOR3> *pVECTOR2vector, DWORD i_dwCurrentTick)
/// \brief		
/// \author		cmkwon
/// \date		2004-03-26 ~ 2004-03-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::CreateMonstersAllCreateRegion(BYTE *pSendBuf, vector<D3DXVECTOR3> *pVECTOR2vector, DWORD i_dwCurrentTick)
{
	// check: Ʃ�丮�� ���̸� ���� ���� �� ��, �ӽ÷� �ڵ���, ö�ξ��� �ٽ� ���ľ� ��! 20040220, kelovon
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ذ� ���� ���� - ä�κ��� ���� �����ϰ�
//	if(FALSE == m_pNPCMapProject->m_bAutoCreateMonster
	if(FALSE == m_bAutoCreateMonsterChannel
		|| IS_TUTORIAL_MAP_INDEX(this->GetMapChannelIndex().MapIndex)
		|| IS_MAP_INFLUENCE_OUTPOST(this->GetMapInfluenceTypeW()) ) // 2007-08-24 by dhjin, �������� �ʵ� ���� �������� �ʴ´�.
	{
		return;
	}

	CNPCMonster					*pNMonster = NULL;
	MONSTER_CREATE_REGION_INFO	*pMonsterCreateRegionInfo = NULL;
	MONSTER_CREATE_REGION_INFO_EX *pRegionInfoEX;
	int							nMonsterInfoSize;
	D3DXVECTOR3					posVector3;

	///////////////////////////////////////////////////////////////////////////////
	// ������Ʈ ���� ���� ó��
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
		if( NULL != itr->m_pMonsterInfo )
		{
			if( COMPARE_MPOPTION_BIT(itr->m_pMonsterInfo->MPOption, MPOPTION_BIT_STOP_AUTO_CREATE) )
			{
				continue;		// �ڵ� ���� ����
			}
		}
		// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���

		this->CreateMonstersBYObject(pSendBuf, &*itr, i_dwCurrentTick);
// 2006-11-22 by cmkwon, ���� �Լ��� ó��
//		OBJECTINFOSERVER *pObjInfo = itr;
//		if(pObjInfo->m_EventInfo.m_byObjectMonsterCreated)
//		{// �̹� ������  ���
//			continue;
//		}
//		else if(pObjInfo->m_EventInfo.m_EventwParam3*1000 > i_dwCurrentTick - pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated)
//		{// ���� Ÿ���� ������ ����
//			continue;
//		}
//		else if(pObjInfo->m_EventInfo.m_byIsCityWarMonster && FALSE == this->m_bCityWarStarted)
//		{// ���������������̸鼭 ������������ �������� �ƴҶ�
//			continue;
//		}
//		else if(m_uiLimitMonsterCountsInChannel <= m_nCurMonsterCountInChannel && FALSE == pObjInfo->m_EventInfo.m_byIsCityWarMonster)
//		{// ���� �ִ� ���� ī��Ʈ ���� ũ�鼭 ���������� ���Ͱ� �ƴϴ�
//			continue;
//		}
//		
//		map<int, MONSTER_INFO>::iterator it = m_pNPCMapProject->m_pMapMonsterParameter->find(pObjInfo->m_EventInfo.m_nObejctMonsterUnitKind);
//		if(it == m_pNPCMapProject->m_pMapMonsterParameter->end())
//		{// ���� �Ϸ��� ���� ������ ����
//			char	szError[1024];
//			sprintf(szError, "[Error] CNPCMapProject::NPCMonsterCreate_1 invalid MonsterType, MAP(%4d) ObjectMonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
//				, this->m_MapChannelIndex.MapIndex, pObjInfo->m_EventInfo.m_EventwParam1, pObjInfo->m_EventInfo.m_nObejctMonsterUnitKind);
//			g_pNPCGlobal->WriteSystemLog(szError);
//			DbgOut(szError);
//			continue;
//		}
//
//		mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
//		pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = i_dwCurrentTick;
//		if(m_vectorUsableMonsterIndex.empty())
//		{
//			char	szError[1024];
//			sprintf(szError, "[Error] CNPCMapProject::NPCMonsterCreate_2 Monster is full. MaxMonsterCount[%d], CurrentMonsterCount(%d)\r\n"
//				, m_nMaxMonsterCountInChannel, m_nCurMonsterCountInChannel);
//			g_pNPCGlobal->WriteSystemLog(szError);
//			DbgOut(szError);
//			return;
//		}
//		ClientIndex_t nMonsterIndex = m_vectorUsableMonsterIndex.front();
//		m_vectorUsableMonsterIndex.pop_front();
//		pNMonster = GetNPCMonster(nMonsterIndex);
//		if(NULL == pNMonster 
//			|| pNMonster->m_enMonsterState != MS_NULL)
//		{
//			continue;
//		}
//		m_nCurMonsterCountInChannel++;				// Current Counts�� ����
//		pObjInfo->m_EventInfo.m_byObjectMonsterCreated = TRUE;
//
//// 2006-04-25 by cmkwon, ���������� �ý����� ������� �ʰ� ����
//// 		if(it->second.MonsterUnitKind == 2012000)
//// 		{
//// 			g_pNPCGlobal->WriteSystemLogEX(TRUE, STRMSG_S_N2NOTIFY_0001, it->second.MonsterName);
//// 		}
//
//		// ���� ����, �⺻�� ����
//		pNMonster->CreateNPCMonster(&it->second, &pObjInfo->m_vPos, i_dwCurrentTick, pObjInfo->m_EventInfo.m_EventwParam1
//			, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW(), 0, pObjInfo->m_EventInfo.m_bEventType, &pObjInfo->m_vVel);					
//		SetInitialPositionAndSendCreateMonster(pNMonster, pSendBuf);
	}// end_for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	// end_������Ʈ ���� ���� ó��
	///////////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////////
	// �Ϲ� ���� ���� ���� ó��
	nMonsterInfoSize = m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO.size();
	for(int i=0; i < nMonsterInfoSize; i++)
	{
		// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
		MONSTER_INFO *pMonInfo = m_pNPCIOCPServer->GetMonsterInfo(m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO[i].sMonType);

		if(NULL != pMonInfo)
		{
			if( COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_STOP_AUTO_CREATE) )
			{
				continue;		// �ڵ� ���� ����
			}
		}
		// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���

		pMonsterCreateRegionInfo	= &m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO[i];
		pRegionInfoEX				= &m_vectorMonsterCreateRegionInfoEX[i];
		this->CreateMonstersBYRegion(pSendBuf, pVECTOR2vector, i_dwCurrentTick, i, pMonsterCreateRegionInfo, pRegionInfoEX);
// 2006-11-20 by cmkwon, ���� �Լ��� ó��
//				
//		///////////////////////////////////////////////////////////////////////////////
//		// �������� ���� �ð������� �д����� ����Ѵ�.
//		// ������ ���Ͱ� �ƴϸ� ���� �ð��� �и� ������ ������ ó���ϸ�
//		DWORD dwTimeGap				= i_dwCurrentTick-pRegionInfoEX->dwLastTimeMonsterCreate;
//		if (MONSTER_CREATETYPE_BOSS == pMonsterCreateRegionInfo->bMonType)
//		{
//			if((0 == pRegionInfoEX->nCreatedCount && dwTimeGap < 3*60*1000)
//				|| (0 != pRegionInfoEX->nCreatedCount && dwTimeGap < pRegionInfoEX->dwBossMonResTime)
//				)
//			{// ���� ���ʹ� ó�� ���� Ÿ�� 3���� ������ �ʾҰų� ���� Ÿ���� ��� ���� ����
//				continue;
//			}
//			else if(pRegionInfoEX->nCurrentCount >= pMonsterCreateRegionInfo->sMaxMon)
//			{// ���� ���� �ִ�ī��Ʈ ���� Ŭ��
//				continue;
//			}
//		}
//		else
//		{// �������Ͱ� �ƴ�
//			
//			if(dwTimeGap < ((DWORD)pMonsterCreateRegionInfo->sResTime)*1000)
//			{// ���� Ÿ���� ��� ���� ���� ���
//				continue;
//			}
//			else if(m_uiLimitMonsterCountsInChannel <= m_nCurMonsterCountInChannel)
//			{// ���� �ִ� ���� ī��Ʈ ���� Ŭ��
//				continue;
//			}
//			else if(pRegionInfoEX->nCurrentCount >= (pMonsterCreateRegionInfo->sMaxMon+pMonsterCreateRegionInfo->sMaxMon/10)*m_nMaxMonsterCountInChannel/m_uiLimitMonsterCountsInChannel)
//			{// ���� ���� �ִ�ī��Ʈ ���� Ŭ��
//				continue;
//			}
//		}
//		
//		MONSTER_INFO *pMonInfo = m_pNPCIOCPServer->GetMonsterInfo(pMonsterCreateRegionInfo->sMonType);
//		if(NULL == pMonInfo)
//		{
//			char	szError[1024];
//			sprintf(szError, "[Error] CNPCMapProject::NPCMonsterCreate_3 invalid MonsterType, MAP(%4d) MonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
//				, this->m_MapChannelIndex.MapIndex, i, pMonsterCreateRegionInfo->sMonType);
//			g_pNPCGlobal->WriteSystemLog(szError);
//			DbgOut(szError);
//			continue;
//		}
//
//		///////////////////////////////////////////////////////////////////////////////
//		// 2006-04-18 by cmkwon, ���� �ð��� �����Ѵ�.
//		pRegionInfoEX->dwLastTimeMonsterCreate = i_dwCurrentTick;				// ���� �ð��� �����Ѵ�.
//
//		///////////////////////////////////////////////////////////////////////////////
//		// 2006-04-18 by cmkwon
//		if(FALSE == this->IsEnableCreateMonster(pMonInfo))
//		{
//			char szTest[1024];
//			wsprintf(szTest, "  CreateRegionInfo MapIndexChannel(%d,%d) InfoIdx(%d) Mon(%8d) ResTime(%d��), dwTimeGap(%d��)\r\n"
//				, this->GetMapChannelIndex().MapIndex, this->GetMapChannelIndex().ChannelIndex, i
//				, pMonsterCreateRegionInfo->sMonType, pMonsterCreateRegionInfo->sResTime, dwTimeGap/1000);
//			g_pNPCGlobal->WriteSystemLog(szTest);
//			DbgOut(szTest);
//			continue;
//		}
//
//		int curMonsters = NPCGetMonsterCountInRegion(pMonsterCreateRegionInfo->sStartx, pMonsterCreateRegionInfo->sStartz,
//			pMonsterCreateRegionInfo->sEndx, pMonsterCreateRegionInfo->sEndz, pMonsterCreateRegionInfo->sMonType,
//			pMonsterCreateRegionInfo->sMaxMon);
//		creatMonsters = pMonsterCreateRegionInfo->sMaxMon - curMonsters;
//		if(creatMonsters <= 0)
//		{// ���� ���� ���� ��ȿ���� ����
//
//			continue;
//		}
//
//		
//		creatMonsters = creatMonsters > pMonsterCreateRegionInfo->sResNum ? pMonsterCreateRegionInfo->sResNum : creatMonsters;
//		creatMonsters = rand()%creatMonsters + 1;
//		NPCGetCreatablePosition(pMonInfo->MonsterForm, pMonInfo->Size, pMonsterCreateRegionInfo->sStartx, pMonsterCreateRegionInfo->sStartz,
//			pMonsterCreateRegionInfo->sEndx, pMonsterCreateRegionInfo->sEndz, 
//			m_pNPCMapProject->m_sMinimumAltitude, m_pNPCMapProject->m_sMaximumAltitude
//			, *pVECTOR2vector, creatMonsters);
//
//		mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
//		while(creatMonsters > 0 && false == pVECTOR2vector->empty())
//		{
//			creatMonsters--;
//			if(m_vectorUsableMonsterIndex.empty())
//			{
//				char	szError[1024];
//				sprintf(szError, "[Error] CNPCMapProject::NPCMonsterCreate_4 Monster is full. MaxMonsterCount[%d], CurrentMonsterCount(%d)\r\n"
//					, m_nMaxMonsterCountInChannel, m_nCurMonsterCountInChannel);
//				g_pNPCGlobal->WriteSystemLog(szError);
//				DbgOut(szError);
//				return;
//			}
//			ClientIndex_t nMonsterIndex = m_vectorUsableMonsterIndex.front();
//			m_vectorUsableMonsterIndex.pop_front();
//			pNMonster = GetNPCMonster(nMonsterIndex);
//			if(NULL == pNMonster 
//				|| pNMonster->m_enMonsterState != MS_NULL)
//			{
//				continue;
//			}
//			m_nCurMonsterCountInChannel++;				// Current Counts�� ����
//			pRegionInfoEX->nCreatedCount++;				// ������ ���� ���� Counts�� ����
//			pRegionInfoEX->nCurrentCount++;				// ������ Current ���� Counts�� ����
//
//			posVector3 = pVECTOR2vector->back();
//			pVECTOR2vector->pop_back();
//		
//			// ���� ����, �⺻�� ����
//			pNMonster->CreateNPCMonster(pMonInfo, &posVector3, i_dwCurrentTick, i
//				, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW());
//			SetInitialPositionAndSendCreateMonster(pNMonster, pSendBuf);
//		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::CreateMonstersBYRegion(BYTE *pSendBuf, vector<D3DXVECTOR3> *pVECTOR2vector, DWORD i_dwCurrentTick, int i, MONSTER_CREATE_REGION_INFO *pMonsterCreateRegionInfo, MONSTER_CREATE_REGION_INFO_EX *pRegionInfoEX, BOOL i_bMustCreate/*=FALSE*/)
/// \brief		
/// \author		cmkwon
/// \date		2006-11-20 ~ 2006-11-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::CreateMonstersBYRegion(BYTE *pSendBuf, vector<D3DXVECTOR3> *pVECTOR2vector, DWORD i_dwCurrentTick
											, int i_nArrIdx, MONSTER_CREATE_REGION_INFO *pMonsterCreateRegionInfo, MONSTER_CREATE_REGION_INFO_EX *pRegionInfoEX
											, BOOL i_bMustCreate/*=FALSE*/)
{
	CNPCMonster			*pNMonster = NULL;
	int					creatMonsters;						// ������ ���� ��ü��
	D3DXVECTOR3			posVector3;

	DWORD dwTimeGap				= i_dwCurrentTick - pRegionInfoEX->dwLastTimeMonsterCreate;
	if(FALSE == i_bMustCreate)
	{
		///////////////////////////////////////////////////////////////////////////////
		// �������� ���� �ð������� �д����� ����Ѵ�.
		// ������ ���Ͱ� �ƴϸ� ���� �ð��� �и� ������ ������ ó���ϸ�
		if (MONSTER_CREATETYPE_BOSS == pMonsterCreateRegionInfo->bMonType)
		{
			if(dwTimeGap < pRegionInfoEX->dwBossMonResTime)
			{// ���� Ÿ���� ��� ���� ����
				return;
			}
			else if(pRegionInfoEX->nCurrentCount >= pMonsterCreateRegionInfo->sMaxMon)
			{// ���� ���� �ִ�ī��Ʈ ���� Ŭ��
				return;
			} 

			// 2006-12-11 by cmkwon, ���� ��ȯ �ð� ����
			// 2009-10-23 by cmkwon, NPCServer 0���� ������ ���� ���� - CNPCMapChannel::CreateMonstersBYRegion#
			//pRegionInfoEX->dwBossMonResTime = 
			//	(pMonsterCreateRegionInfo->sResTime/3 + RANDI(1, pMonsterCreateRegionInfo->sResTime*2/3))*60*TICK_CREATE_MONSTER_TERM;
			// 2009-10-23 by cmkwon, NPCServer 0���� ������ ���� ���� - CNPCMapChannel::CreateMonstersBYRegion#
			DWORD dwMinMinutes = max(  1, pMonsterCreateRegionInfo->sResTime/3 + RANDI(1, max(1,pMonsterCreateRegionInfo->sResTime*2/3))  );
			pRegionInfoEX->dwBossMonResTime = dwMinMinutes*60*TICK_CREATE_MONSTER_TERM;

////////////////////////////////////////////////////////////////////////////////
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - pMonsterCreateRegionInfo->sResTime ���� 1�� �� ���� ������ ���� �ذ� ���� �����Ѵ�.
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �ʿ��� ���� �ð��� ù ��ȯ�ð��̰� �� �� ��ȯ�� ���ʹ� �� �̻� ��ȯ��Ű�� �ʴ´�.
//			// 2006-12-11 by cmkwon, ���� ��ȯ �ð� ����
			// 2006-12-11 by cmkwon, ���� ��ȯ �ð� ����
			// 2009-10-23 by cmkwon, NPCServer 0���� ������ ���� ���� - CNPCMapChannel::CreateMonstersBYRegion#
//			pRegionInfoEX->dwBossMonResTime = 
//				(pMonsterCreateRegionInfo->sResTime/3 + RANDI(1, pMonsterCreateRegionInfo->sResTime*2/3))*60*TICK_CREATE_MONSTER_TERM;
			// 2009-10-23 by cmkwon, NPCServer 0���� ������ ���� ���� - CNPCMapChannel::CreateMonstersBYRegion#
//			if(IS_MAP_INFLUENCE_INFINITY(this->GetMapInfluenceTypeW()))	{
//				pRegionInfoEX->dwBossMonResTime = TICK_CREATE_MONSTER_TERM_ONLY_INFINITY;
//			}
//			else {
//        		DWORD dwMinMinutes = max(  1, pMonsterCreateRegionInfo->sResTime/3 + RANDI(1, max(1,pMonsterCreateRegionInfo->sResTime*2/3))  );
//		    	pRegionInfoEX->dwBossMonResTime = dwMinMinutes*60*TICK_CREATE_MONSTER_TERM;
//
//	    	}		
		}
		else
		{// �������Ͱ� �ƴ�
			
			if(dwTimeGap < ((DWORD)pMonsterCreateRegionInfo->sResTime)*TICK_CREATE_MONSTER_TERM)
			{// ���� Ÿ���� ��� ���� ���� ���
				return;
			}
			else if(m_uiLimitMonsterCountsInChannel <= m_nCurMonsterCountInChannel)
			{// ���� �ִ� ���� ī��Ʈ ���� Ŭ��
				return;
			}
			else if(pRegionInfoEX->nCurrentCount >= (pMonsterCreateRegionInfo->sMaxMon+pMonsterCreateRegionInfo->sMaxMon/10)*m_nMaxMonsterCountInChannel/m_uiLimitMonsterCountsInChannel)
			{// ���� ���� �ִ�ī��Ʈ ���� Ŭ��
				return;
			}
			////////////////////////////////////////////////////////////////////////////////
			// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �ʿ��� ���� �ð��� ù ��ȯ�ð��̰� �� �� ��ȯ�� ���ʹ� �� �̻� ��ȯ��Ű�� �ʴ´�.
//			if(IS_MAP_INFLUENCE_INFINITY(this->GetMapInfluenceTypeW()))	{
//				pRegionInfoEX->dwBossMonResTime = TICK_CREATE_MONSTER_TERM_ONLY_INFINITY;
//			}
		}
	}
	
	MONSTER_INFO *pMonInfo = m_pNPCIOCPServer->GetMonsterInfo(pMonsterCreateRegionInfo->sMonType);
	if(NULL == pMonInfo)
	{
		char	szError[1024];
		sprintf(szError, "[Error] CNPCMapChannel::CreateMonstersBYRegion_1 invalid MonsterType, MAP(%4d) MonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
			, this->m_MapChannelIndex.MapIndex, i_nArrIdx, pMonsterCreateRegionInfo->sMonType);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	// 2007-08-29 by dhjin, ���� ���� �����̸� �������� �ʴ´�. ����~!! ���� ���ʹ� �����̴�.
	if(m_bNotCreateMonster
		&& (BELL_INFLUENCE_VCN != pMonInfo->Belligerence
			|| BELL_INFLUENCE_ANI != pMonInfo->Belligerence))
	{
		pRegionInfoEX->dwLastTimeMonsterCreate = i_dwCurrentTick;				// 2009-10-15 by cmkwon, ���¸��� ����ä�ο� ���¸��� ��ȯ ���� - ���� �ð��� �����Ѵ�.
		return;
	}

	// 2009-10-15 by cmkwon, ���¸��� ����ä�ο� ���¸��� ��ȯ ���� - CNPCMapChannel::CreateMonstersBYRegion#, 
	if( (IS_MAP_INFLUENCE_VCN(GetMapInfluenceTypeW()) || IS_MAP_INFLUENCE_ANI(GetMapInfluenceTypeW()))
		&& 0 != m_MapChannelIndex.ChannelIndex
		&& IS_INFLWAR_MONSTER(pMonInfo->Belligerence))
	{
		pRegionInfoEX->dwLastTimeMonsterCreate = i_dwCurrentTick;				// ���� �ð��� �����Ѵ�.
		return;
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// 2006-04-18 by cmkwon, ���� �ð��� �����Ѵ�.
	pRegionInfoEX->dwLastTimeMonsterCreate = i_dwCurrentTick;				// ���� �ð��� �����Ѵ�.

	///////////////////////////////////////////////////////////////////////////////
	// 2006-04-18 by cmkwon
	if(FALSE == this->IsEnableCreateMonster(pMonInfo))
	{
// 2008-11-11 by cmkwon, �ʿ� ���� - 
//		char szTest[1024];
//		wsprintf(szTest, "  CreateRegionInfo MapIndexChannel(%d,%d) InfoIdx(%d) Mon(%8d) ResTime(%d��), dwTimeGap(%d��)\r\n"
//			, this->GetMapChannelIndex().MapIndex, this->GetMapChannelIndex().ChannelIndex, i_nArrIdx
//			, pMonsterCreateRegionInfo->sMonType, pMonsterCreateRegionInfo->sResTime, dwTimeGap/1000);
//		g_pNPCGlobal->WriteSystemLog(szTest);
//		DBGOUT(szTest);
		return;
	}

	int curMonsters = NPCGetMonsterCountInRegion(pMonsterCreateRegionInfo->sStartx, pMonsterCreateRegionInfo->sStartz,
		pMonsterCreateRegionInfo->sEndx, pMonsterCreateRegionInfo->sEndz, pMonsterCreateRegionInfo->sMonType,
		pMonsterCreateRegionInfo->sMaxMon);
	creatMonsters = pMonsterCreateRegionInfo->sMaxMon - curMonsters;
	if(creatMonsters <= 0)
	{// ���� ���� ���� ��ȿ���� ����

		return;
	}
	
	creatMonsters = creatMonsters > pMonsterCreateRegionInfo->sResNum ? pMonsterCreateRegionInfo->sResNum : creatMonsters;

	if(0 >= creatMonsters)
	{// 2010-05-28 by cmkwon, ��ȯ ������ 0�϶� NPCServer �״� ���� ���� - 
		return;
	}


	creatMonsters = rand()%creatMonsters + 1;
	NPCGetCreatablePosition(pMonInfo->MonsterForm, pMonInfo->Size, pMonsterCreateRegionInfo->sStartx, pMonsterCreateRegionInfo->sStartz,
		pMonsterCreateRegionInfo->sEndx, pMonsterCreateRegionInfo->sEndz, 
		m_pNPCMapProject->m_sMinimumAltitude, m_pNPCMapProject->m_sMaximumAltitude
		, *pVECTOR2vector, creatMonsters);

	mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
	while(creatMonsters > 0 && false == pVECTOR2vector->empty())
	{
		creatMonsters--;
		if(m_vectorUsableMonsterIndex.empty())
		{
			char	szError[1024];
			sprintf(szError, "[Error] CNPCMapChannel::CreateMonstersBYRegion_2 Monster is full. MaxMonsterCount[%d], CurrentMonsterCount(%d)\r\n"
				, m_nMaxMonsterCountInChannel, m_nCurMonsterCountInChannel);
			g_pNPCGlobal->WriteSystemLog(szError);
			DbgOut(szError);
			return;
		}
		ClientIndex_t nMonsterIndex = m_vectorUsableMonsterIndex.front();
		m_vectorUsableMonsterIndex.pop_front();
		pNMonster = GetNPCMonster(nMonsterIndex);
		if(NULL == pNMonster 
			|| pNMonster->m_enMonsterState != MS_NULL)
		{
			continue;
		}
		m_nCurMonsterCountInChannel++;				// Current Counts�� ����
		pRegionInfoEX->nCreatedCount++;				// ������ ���� ���� Counts�� ����
		pRegionInfoEX->nCurrentCount++;				// ������ Current ���� Counts�� ����

		posVector3 = pVECTOR2vector->back();
		pVECTOR2vector->pop_back();
	
		////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
		vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr(pMonInfo->HPActionIdx);
		if(NULL != pvectHPAction) {
			pNMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
		}
		// ���� ����, �⺻�� ����
		pNMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����
		pNMonster->CreateNPCMonster(pMonInfo, &posVector3, i_dwCurrentTick, i_nArrIdx
			, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW());
		SetInitialPositionAndSendCreateMonster(pNMonster, pSendBuf);

	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::CreateMonstersBYObject(BYTE *pSendBuf, OBJECTINFOSERVER *pObjInfo, DWORD i_dwCurrentTick, BOOL i_bMustCreate/*=FALSE*/)
/// \brief		
/// \author		cmkwon
/// \date		2006-11-22 ~ 2006-11-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::CreateMonstersBYObject(BYTE *pSendBuf, OBJECTINFOSERVER *pObjInfo, DWORD i_dwCurrentTick, BOOL i_bMustCreate/*=FALSE*/)
{
	if(pObjInfo->m_EventInfo.m_byObjectMonsterCreated)
	{// �̹� ������  ���
		return;
	}

	// start 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����
	MONSTER_BALANCE_DATA *pMonsterBalanceInfo = NULL;

	if( TRUE == IS_MAP_INFLUENCE_INFINITY(this->GetMapInfluenceTypeW()) )		// ���Ǵ�Ƽ �̰�
	{
		if( EVENT_TYPE_OBJECT_MONSTER == pObjInfo->m_EventInfo.m_bEventType )		// ObjectMonster Position Information Object �̸鼭
		{
			if( TRUE == pObjInfo->m_bNotCreateMonster )		// m_bNotCreateMonster TRUE ��
			{
				return ;		// ��ȯ ����
			}

			pMonsterBalanceInfo = &pObjInfo->MonsterBalanceInfo;
		}
	}	
	// end 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����

// 2007-09-19 by cmkwon, �Ʒ��� ���� ���� ���� ó���� �����Ѵ�.
//	if(pObjInfo->m_EventInfo.m_byBossMonster)
//	{// 2006-11-22 by cmkwon, ������Ʈ ���� ����
//		if(FALSE == i_bMustCreate
//			&& pObjInfo->dwObjBossMonResTime > i_dwCurrentTick - pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated)
//		{// ���� Ÿ���� ������ ����
//			return;
//		}
//
//		// 2006-11-22 by cmkwon, ���� ��ȯ �ð��� ���� �Ѵ�
//		pObjInfo->dwObjBossMonResTime = (pObjInfo->m_EventInfo.m_EventwParam3/3 + RANDI(1, pObjInfo->m_EventInfo.m_EventwParam3*2/3))*60*1000;
//
//		//////////////////////////////////////////////////////////////////////////
//		// 2007-02-28 by dhjin, FieldServer���� ��������Ʈ ���� �ֱ⿡ ���� �����ϰ� ��ȯ�ǵ��� ����.
//		if(FALSE == i_bMustCreate)
//		{// FieldServer���� ������ ��ȯ �� ���� ��ȯ �ǵ��� ����.
//			return;
//		}
//	}

// 2007-10-02 by cmkwon, �Ʒ��� ���� i_bMustCreate �� FALSE �϶����� ���ȯ�ð���  üũ�ϰ� ��ȯ �Ѵ�.
//	if(IS_STRATEGYPOINT_MONSTER(pObjInfo->m_pMonsterInfo->Belligerence)
//		|| IS_TELEPORT_MONSTER(pObjInfo->m_pMonsterInfo->Belligerence))
//	{
//		if(FALSE == i_bMustCreate)
//		{// 2007-09-19 by cmkwon, ���� ����/�ڷ���Ʈ FieldServer���� ������ ��ȯ�� �����ϴ� 
//			return;
//		}
//	}
//	else
//	{
//		if(pObjInfo->m_EventInfo.m_EventwParam3*TICK_CREATE_MONSTER_TERM > i_dwCurrentTick - pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated)
//		{// ���� Ÿ���� ������ ����
//			return;
//		}
//
//		if(m_uiLimitMonsterCountsInChannel <= m_nCurMonsterCountInChannel)
//		{// ���� �ִ� ���� ī��Ʈ ���� ũ��
//			return;
//		}
//	}
	if(FALSE == i_bMustCreate)
	{
		// 2007-10-04 by cmkwon, ��������Ʈ, �ڷ���Ʈ�� 
		if(IS_STRATEGYPOINT_MONSTER(pObjInfo->m_pMonsterInfo->Belligerence)
			|| IS_TELEPORT_MONSTER(pObjInfo->m_pMonsterInfo->Belligerence))
		{
			return;
		}

		if(pObjInfo->m_EventInfo.m_EventwParam3*TICK_CREATE_MONSTER_TERM > i_dwCurrentTick - pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated)
		{// ���� Ÿ���� ������ ����
			return;
		}

		if(m_uiLimitMonsterCountsInChannel <= m_nCurMonsterCountInChannel)
		{// ���� �ִ� ���� ī��Ʈ ���� ũ��
			return;
		}
	}
	

// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ� - �̸� �����Ͽ��� ������ NULL üũ�� �Ѵ�
//	MONSTER_INFO *pMonInfo = m_pNPCIOCPServer->GetMonsterInfo(pObjInfo->m_EventInfo.m_nObejctMonsterUnitKind);
	MONSTER_INFO *pMonInfo = pObjInfo->m_pMonsterInfo;	// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ�
	if(NULL == pMonInfo)
	{
		char	szError[1024];
		sprintf(szError, "[Error] CNPCMapChannel::CreateMonstersBYObject_1 invalid MonsterType, MAP(%4d) ObjectMonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
			, this->m_MapChannelIndex.MapIndex, pObjInfo->m_EventInfo.m_EventwParam1, pObjInfo->m_EventInfo.m_nObejctMonsterUnitKind);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	// 2007-08-29 by dhjin, ���� ���� �����̸� �������� �ʴ´�. ����~!! ���� ���ʹ� �����̴�.
	if(m_bNotCreateMonster
		&& (BELL_INFLUENCE_VCN != pMonInfo->Belligerence)
		&& (BELL_INFLUENCE_ANI != pMonInfo->Belligerence)
		&& (BELL_STRATEGYPOINT_VCN != pMonInfo->Belligerence)
		&& (BELL_STRATEGYPOINT_ANI != pMonInfo->Belligerence)
		&& (BELL_INFLUENCE_TELEPORT_VCN != pMonInfo->Belligerence)
		&& (BELL_INFLUENCE_TELEPORT_ANI != pMonInfo->Belligerence)
		&& !IS_ONEY_ATTACK_MONSTER(pMonInfo->Belligerence)) // 2010-07-06 by jskim, �⿩�� ���� ���� ���� �߰�
	{
		pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = i_dwCurrentTick;		// 2009-10-15 by cmkwon, ���¸��� ����ä�ο� ���¸��� ��ȯ ���� - ���� �ð��� �����Ѵ�.
		return;
	}

	// 2009-10-15 by cmkwon, ���¸��� ����ä�ο� ���¸��� ��ȯ ���� - CNPCMapChannel::CreateMonstersBYObject#, 
	if( (IS_MAP_INFLUENCE_VCN(GetMapInfluenceTypeW()) || IS_MAP_INFLUENCE_ANI(GetMapInfluenceTypeW()))
		&& 0 != m_MapChannelIndex.ChannelIndex
		&& IS_INFLWAR_MONSTER(pMonInfo->Belligerence))
	{
		pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = i_dwCurrentTick;		// 2009-10-15 by cmkwon, ���¸��� ����ä�ο� ���¸��� ��ȯ ���� - ���� �ð��� �����Ѵ�.
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2006-11-23 by cmkwon
	pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = i_dwCurrentTick;
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �ʿ��� ���� �ð��� ù ��ȯ�ð��̰� �� �� ��ȯ�� ���ʹ� �� �̻� ��ȯ��Ű�� �ʴ´�.
//	if(IS_MAP_INFLUENCE_INFINITY(this->GetMapInfluenceTypeW()))	{
//		pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = TICK_CREATE_MONSTER_TERM_ONLY_INFINITY;
//	}

	///////////////////////////////////////////////////////////////////////////////
	// 2006-04-18 by cmkwon
	if(FALSE == this->IsEnableCreateMonster(pMonInfo))
	{
// 2008-11-11 by cmkwon, �ʿ� ���� - 
//		char szTest[1024];
//		wsprintf(szTest, "  CreateRegionInfo MapChannel(%s) ObjectMonsterInfoIndex[%2d] MonsterType[%6d]\r\n"
//			, GET_MAP_STRING(this->GetMapChannelIndex()), pObjInfo->m_EventInfo.m_EventwParam1, pObjInfo->m_EventInfo.m_nObejctMonsterUnitKind);
//		g_pNPCGlobal->WriteSystemLog(szTest);
//		DBGOUT(szTest);
		return;
	}

	mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
	if(m_vectorUsableMonsterIndex.empty())
	{
		char	szError[1024];
		sprintf(szError, "[Error] CNPCMapChannel::CreateMonstersBYObject_2 Monster is full. MaxMonsterCount[%d], CurrentMonsterCount(%d)\r\n"
			, m_nMaxMonsterCountInChannel, m_nCurMonsterCountInChannel);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return;
	}
	ClientIndex_t nMonsterIndex = m_vectorUsableMonsterIndex.front();
	m_vectorUsableMonsterIndex.pop_front();
	CNPCMonster *pNMonster = GetNPCMonster(nMonsterIndex);
	if(NULL == pNMonster 
		|| pNMonster->m_enMonsterState != MS_NULL)
	{
		return;
	}
	m_nCurMonsterCountInChannel++;				// Current Counts�� ����
	pObjInfo->m_EventInfo.m_byObjectMonsterCreated = TRUE;

	////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
	vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr(pMonInfo->HPActionIdx);
	if(NULL != pvectHPAction) {
		pNMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
	}
	// ���� ����, �⺻�� ����
	pNMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����
	pNMonster->CreateNPCMonster(pMonInfo, &pObjInfo->m_vPos, i_dwCurrentTick, pObjInfo->m_EventInfo.m_EventwParam1
		, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW(), 0, pObjInfo->m_EventInfo.m_bEventType, &pObjInfo->m_vVel, pMonsterBalanceInfo);		// 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����				
	SetInitialPositionAndSendCreateMonster(pNMonster, pSendBuf);
	////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
}

void CNPCMapChannel::UpdateMonsterPositionAllMonster(BYTE *pSendBuf,
											  vector<ClientIndex_t> *pvecClientIndex,
											  DWORD i_dwCurrentTick)
{
	CNPCMonster		*ptmpNPCMonster = NULL;
	for (int nIdxMonsterArray = 0; nIdxMonsterArray < m_nSizemtvectorMonsterPtr; nIdxMonsterArray++)	
	{		
		ptmpNPCMonster = &m_ArrNPCMonster[nIdxMonsterArray];
		switch(ptmpNPCMonster->m_enMonsterState)
		{
		case MS_NULL:
			break;
		case MS_PLAYING:
			{
				///////////////////////////////////////////////////////////////////////////////
				// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
				ptmpNPCMonster->CheckExpireSkill();

				if(i_dwCurrentTick - ptmpNPCMonster->m_dwTimeLastMoved >= MONSTER_UPDATE_MOVE_TERM_TICK)
				{	// ������ �̵� Term�� ����

					ptmpNPCMonster->SetCurrentTick(i_dwCurrentTick);

					///////////////////////////////////////////////////////////
					// HP ȸ�� ó��
					if(ptmpNPCMonster->MonsterInfoPtr->HPRecoveryValue
						&& i_dwCurrentTick - ptmpNPCMonster->m_dwLastHPRecoveryTime > ptmpNPCMonster->MonsterInfoPtr->HPRecoveryTime)
					{
						ptmpNPCMonster->m_dwLastHPRecoveryTime = i_dwCurrentTick;

						// 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
						//if(ptmpNPCMonster->MonsterInfoPtr->MonsterHP > ptmpNPCMonster->CurrentHP)
						if ( ptmpNPCMonster->MonsterInfoExtend.fMaxHP > ptmpNPCMonster->CurrentHP )
						{
							INIT_MSG(MSG_FN_MONSTER_HPRECOVERY, T_FN_MONSTER_HPRECOVERY, pSendHPRecovery, pSendBuf);
							pSendHPRecovery->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
							pSendHPRecovery->MonsterIndex	= ptmpNPCMonster->MonsterIndex;

							// 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
							//pSendHPRecovery->RecoveryHP		= min(ptmpNPCMonster->MonsterInfoPtr->HPRecoveryValue, ptmpNPCMonster->MonsterInfoPtr->MonsterHP - ptmpNPCMonster->CurrentHP);

							// 2010. 05. 31 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (������Ʈ ���� �뷱�� ���� ���� ����.) - ���� HP ȸ���� �뷱�� ����.
							pSendHPRecovery->RecoveryHP		= min(ptmpNPCMonster->MonsterInfoPtr->HPRecoveryValue * ptmpNPCMonster->MonsterInfoBalance.fMaxHPRatio , ptmpNPCMonster->MonsterInfoExtend.fMaxHP - ptmpNPCMonster->CurrentHP);
							// End 2010. 05. 31 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (������Ʈ ���� �뷱�� ���� ���� ����.)
							// End 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )

							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_HPRECOVERY));
						}
					}

					///////////////////////////////////////////////////////////
					// ���� �̵� ó��
					// 1. �������� �̵� ó��
					//		- Target�� �ְų� Ȥ�� �����ǰ� �̵����� ���� �ð�(�Ϲ� ���Ϳ� �̺�Ʈ ���� �ΰ����� ����)�� ���� ����
					// 2. �̵����� Move�� ����
					if(ptmpNPCMonster->m_nTargetIndex != 0
						|| i_dwCurrentTick - ptmpNPCMonster->m_dwTimeCreated > ((COMPARE_MPOPTION_BIT(ptmpNPCMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_PATTERN_MONSTER))? MONSTER_EVENT_MON_NOT_MOVE_AFTER_CREATED_TERM_TICK : MONSTER_NOT_MOVE_AFTER_CREATED_TERM_TICK))
					{
						if(COMPARE_BODYCON_BIT(ptmpNPCMonster->BodyCondition, BODYCON_CREATION_MASK))
						{
							BodyCond_t tmBody = ptmpNPCMonster->BodyCondition;
							CLEAR_BODYCON_BIT(tmBody, BODYCON_CREATION_MASK);
							if(FORM_GROUND_MOVE == ptmpNPCMonster->CurrentMonsterForm)
							{
								SET_BODYCON_BIT(tmBody, BODYCON_LANDED_MASK);
							}
							else
							{
								SET_BODYCON_BIT(tmBody, BODYCON_FLY_MASK|BODYCON_BOOSTER1_MASK);	
							}
							ptmpNPCMonster->ChangeBodyCondition(&tmBody);

							INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
							pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
							pSeBody->ClientIndex	= ptmpNPCMonster->MonsterIndex;
							pSeBody->BodyCondition	= ptmpNPCMonster->BodyCondition;
							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
						}
						NPCMonsterMPOption(ptmpNPCMonster);						
						UpdateMonsterPositionHandler(ptmpNPCMonster, pSendBuf, pvecClientIndex, FALSE);
					}
					else
					{
						UpdateMonsterPositionHandler(ptmpNPCMonster, pSendBuf, pvecClientIndex, TRUE);
					}
				}// end_if(i_dwCurrentTick - ptmpNPCMonster->m_dwTimeLastMoved >= MONSTER_UPDATE_MOVE_TERM_TICK)


				if(i_dwCurrentTick - ptmpNPCMonster->m_dwTimeLastAttackRoutine > MONSTER_MIN_ATTACK_TERM_TICK
					&& ptmpNPCMonster->m_nTargetIndex >= CLIENT_INDEX_START_NUM)
				{	// ������ �ð��� �ּ� ���ݽð� �̻� ������ ���Ͱ� �����ϰ����ϴ� Ÿ���� ���� 
					
					ptmpNPCMonster->m_dwTimeLastAttackRoutine = i_dwCurrentTick;
					AttackMonster2Unit(ptmpNPCMonster, pSendBuf);					
				}

				///////////////////////////////////////////////////////////////////////////////
				// 2005-10-27 by cmkwon, �ڵ� �Ҹ� ���� üũ
				if(COMPARE_MPOPTION_BIT(ptmpNPCMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_AUTO_DESTROY))
				{
					DWORD dwLiveTime = ptmpNPCMonster->MonsterInfoPtr->MPOptionParam1*60*1000;
					if(dwLiveTime < i_dwCurrentTick-ptmpNPCMonster->m_dwTimeCreated)
					{
						BodyCond_t tmBodyCon;
						MEMSET_ZERO(&tmBodyCon, sizeof(tmBodyCon));
						SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_AUTODESTROYED_MASK);
						ptmpNPCMonster->ChangeBodyCondition(&tmBodyCon);

// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - �Ʒ��� ���� TCP�� ����
//						INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//						pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//						pSeBody->ClientIndex	= ptmpNPCMonster->MonsterIndex;
//						pSeBody->BodyCondition	= ptmpNPCMonster->BodyCondition;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//
//						///////////////////////////////////////////////////////////////////////////////
//						// 2006-04-17 by cmkwon, �ڵ� �Ҹ� ������ FieldServer�� �����Ѵ�.
//						INIT_MSG(MSG_FN_MONSTER_AUTO_DESTROYED, T_FN_MONSTER_AUTO_DESTROYED, pSDestroyed, pSendBuf);
//						pSDestroyed->ChannelIndex	= this->GetMapChannelIndex().ChannelIndex;
//						pSDestroyed->MonsterIndex	= ptmpNPCMonster->MonsterIndex;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_AUTO_DESTROYED));
//
//						///////////////////////////////////////////////////////////////////////////////
//						// 2006-11-20 by cmkwon, �ٷ� ����ó���Ѵ�.
//						INIT_MSG(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, pSendBuf);
//						pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//						pMonsterDelete->MonsterIndex	= ptmpNPCMonster->MonsterIndex;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));

						///////////////////////////////////////////////////////////////////////////////
						// 2006-04-17 by cmkwon, �ڵ� �Ҹ� ������ FieldServer�� �����Ѵ�.
						// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - �Ʒ��� �޽��� �ϳ��� ����, �������� FServer���� ó��
						INIT_MSG(MSG_FN_MONSTER_AUTO_DESTROYED, T_FN_MONSTER_AUTO_DESTROYED, pSDestroyed, pSendBuf);
						pSDestroyed->MapChannIdx	= this->GetMapChannelIndex();		// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - 
						pSDestroyed->MonsterIndex	= ptmpNPCMonster->MonsterIndex;
						pSDestroyed->BodyCondition	= ptmpNPCMonster->BodyCondition;	// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - 
#ifdef WARP_EVENT_SAMAEL
						pSDestroyed->MonsterUnitKind	= ptmpNPCMonster->MonsterInfoPtr->MonsterUnitKind;
#endif
						Send2FieldServerByTCPW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_AUTO_DESTROYED));

						DelelteMonsterHandler(ptmpNPCMonster);
					}
				}
			}
			break;
		case MS_DEAD:
			{
				ptmpNPCMonster->SetCurrentTick(i_dwCurrentTick);
				if(0 == ptmpNPCMonster->m_dwTimeDeath)
				{// 2005-12-17 by cmkwon, FieldServer�δ� ���� �޽����� �����Ѵ�.
					ptmpNPCMonster->m_dwTimeDeath	= ptmpNPCMonster->m_dwCurrentTick;

					///////////////////////////////////////////////////////////////////////////////
					// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
					mtvectSSUMMON_EVENT_MONSTER summonEvMonList;
					m_pNPCIOCPServer->GetSummonEventMonsterListAfterDead(&summonEvMonList, this->GetMapChannelIndex(), ptmpNPCMonster->MonsterInfoPtr);
					ptmpNPCMonster->SetSummonEventMonsterListAfterDead(&summonEvMonList);

					// Field Server�� ���� �޼����� ����
					INIT_MSG(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, pSendBuf);
					pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
					pMonsterDelete->MonsterIndex	= ptmpNPCMonster->MonsterIndex;
					pMonsterDelete->CinemaDelete	= FALSE;		// 2011-05-30 by hskim, ���Ǵ�Ƽ 3�� - ���� ���� Ŭ���̾�Ʈ �ݿ�
					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));

					////////////////////////////////////////////////////////////////////////////////
					// 2009-09-09 ~ 2010-01-27 by dhjin, ���Ǵ�Ƽ - Success, Fail�� ���� �ʱ�ȭ, ����ÿ��� ��� ����ϵ��� DelelteMonsterHandler�Լ����� �������� ��ġ ����
					// 2010-03-09 by cmkwon, ���� ����� ���۸޽��� ó�� ���� ���� - 1ȸ�� �߼۵ǰ� ó��
					if(ptmpNPCMonster->m_HPAction.CheckValidSizeTalkDead()) {
						HPACTION_TALK_HPRATE MsgTalk;
						MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
						if(ptmpNPCMonster->m_HPAction.GetTalkDead(&MsgTalk)) {
							// ������ ��ȭ�� �ִٸ� �����Ѵ�.
							this->SendFSvrHPTalk(ptmpNPCMonster, &MsgTalk);
						}
					}
				}

				BOOL bDeleteProcess = TRUE;
				_BattleAttackOnMonsterDead(&bDeleteProcess, ptmpNPCMonster);

// 2010-03-09 by cmkwon, ���� ����� ���۸޽��� ó�� ���� ���� - ���� �̵��ؼ� 1ȸ�� �߼۵ǰ� ó��
// 				////////////////////////////////////////////////////////////////////////////////
// 				// 2009-09-09 ~ 2010-01-27 by dhjin, ���Ǵ�Ƽ - Success, Fail�� ���� �ʱ�ȭ, ����ÿ��� ��� ����ϵ��� DelelteMonsterHandler�Լ����� �������� ��ġ ����
// 				if(ptmpNPCMonster->m_HPAction.CheckValidSizeTalkDead()) {
// 					HPACTION_TALK_HPRATE MsgTalk;
// 					MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
// 					if(ptmpNPCMonster->m_HPAction.GetTalkDead(&MsgTalk)) {
// 						// ������ ��ȭ�� �ִٸ� �����Ѵ�.
// 						this->SendFSvrHPTalk(ptmpNPCMonster, &MsgTalk);
// 					}
// 				}

				if(bDeleteProcess)
				{
//					char	szSystemLog[256];
//					sprintf(szSystemLog, "  %10s : => MonIndex[%4d] MonType[%d] CurMonCount[%d] TotalMonCount[%d]\r\n",
//						m_projectInfo.m_strProjectName, ptmpNPCMonster->MonsterIndex,
//						ptmpNPCMonster->MonsterUnitKind, m_nCurMonsterCount, m_nTotalMonsterCount);
//					g_pNPCGlobal->WriteSystemLog(szSystemLog);
//					DBGOUT(szSystemLog);


					// 2007-09-20 by cmkwon, �ڷ���Ʈ ��ȯ ���� ���� - ���� ó���ϱ� ���� ������ �˻��Ѵ�.
					OBJECTINFOSERVER *pTeleportObjMonSummonInfo = GetTeleportObjectMonsterSummonInfo(ptmpNPCMonster);
		
					// NPC Server���� ���͸� �����Ѵ�.
					DelelteMonsterHandler(ptmpNPCMonster);

					// 2007-09-20 by cmkwon, �ڷ���Ʈ ��ȯ ���� ���� - ���� �� �ٽ� ��ȯ ó���� �Ѵ�.
					if(pTeleportObjMonSummonInfo)
					{
						this->CreateMonstersBYObject(pSendBuf, pTeleportObjMonSummonInfo, i_dwCurrentTick, TRUE);
					}
				}
			}
			break;
		case MS_CREATED:
			{
				if(i_dwCurrentTick > ptmpNPCMonster->m_dwTimeCreated
					&& i_dwCurrentTick - ptmpNPCMonster->m_dwTimeCreated > MONSTER_DELETE_AFTER_CREATED_TERM_TICK)
				{	// NPC���� Field�� ���� ��û�� �������� ������ 10�ʰ� ���� ��� ���� ó��
					
// 2008-11-11 by cmkwon, �ʿ� ���� - 
// 					char	szSystemLog[256];
// 					sprintf(szSystemLog, "[ERROR] Monster Create Error,	MapName(%s) MonIndex[%4d] MonType[%d]\r\n"
// 						, GET_MAP_STRING(this->m_MapChannelIndex), ptmpNPCMonster->MonsterIndex
// 						, ptmpNPCMonster->MonsterInfoPtr->MonsterUnitKind);
// 					g_pNPCGlobal->WriteSystemLog(szSystemLog);
// 					DBGOUT(szSystemLog);
					

					if(IS_TUTORIAL_MAP_INDEX(this->m_MapChannelIndex.MapIndex)						// 2006-09-21 by cmkwon, Ʃ�丮�� ���� ��� ��� �õ�
						|| IS_MAP_INFLUENCE_OUTPOST(this->m_pMapProject->m_nMapInfluenceType)		// 2007-10-04 by cmkwon, �������� ���� ��� ��� �õ�
						|| COMPARE_MPOPTION_BIT(ptmpNPCMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_BOSS_MONSTER)
						|| IS_TELEPORT_MONSTER(ptmpNPCMonster->MonsterInfoPtr->Belligerence)			// 2007-10-01 by cmkwon, �ڷ���Ʈ ���� ��� �õ� �߰�
						|| IS_OUTPOST_MONSTER(ptmpNPCMonster->MonsterInfoPtr->Belligerence)				// 2007-10-01 by cmkwon, ���������� ���� ���� ��� �õ� �߰�
						|| IS_STRATEGYPOINT_MONSTER(ptmpNPCMonster->MonsterInfoPtr->Belligerence)		// 2006-11-21 by cmkwon, ��������Ʈ ���� ��� �õ�
						|| COMPARE_MPOPTION_BIT(ptmpNPCMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_KEY_MONSTER)		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ű ���͵� ���� �Ǿ�� �Ѵ�.
						|| COMPARE_MPOPTION_BIT(ptmpNPCMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_KEY_MONSTER_ALIVE_FOR_GAMECLEAR)		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
						)
					{// 2006-08-09 by cmkwon, ���� ������ ���� ���� �ð��� �ʱ�ȭ �ϰ� �ٽ� �����Ѵ�.
						ptmpNPCMonster->m_dwTimeCreated			= i_dwCurrentTick;

						INIT_MSG(MSG_FN_MONSTER_CREATE, T_FN_MONSTER_CREATE, pSMonsterCreate, pSendBuf);
						pSMonsterCreate->ChannelIndex			= this->m_MapChannelIndex.ChannelIndex;
						pSMonsterCreate->MonsterIndex			= ptmpNPCMonster->MonsterIndex;
						pSMonsterCreate->MonsterUnitKind		= ptmpNPCMonster->MonsterInfoPtr->MonsterUnitKind;
						pSMonsterCreate->MonsterTargetType1		= ptmpNPCMonster->m_byMonsterTargetType;
						pSMonsterCreate->TargetTypeData1		= ptmpNPCMonster->m_nTargetTypeData;
						pSMonsterCreate->CltIdxForTargetType1	= ptmpNPCMonster->GetClientIndexForTargetType();
						pSMonsterCreate->BodyCondition			= ptmpNPCMonster->BodyCondition;
						pSMonsterCreate->PositionVector			= ptmpNPCMonster->PositionVector;
						pSMonsterCreate->TargetVector			= ptmpNPCMonster->TargetVector*1000.0f;
						pSMonsterCreate->ObjectMonsterType		= ptmpNPCMonster->m_byObjectMonsterType;

						// 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
						pSMonsterCreate->MonsterBalanceData		= ptmpNPCMonster->MonsterInfoBalance;
						// End 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )

						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CREATE));
					}
					else
					{
						// Field Server�� ���� �޼����� ����
						INIT_MSG(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, pSendBuf);
						pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
						pMonsterDelete->MonsterIndex	= ptmpNPCMonster->MonsterIndex;
						pMonsterDelete->CinemaDelete	= FALSE;		// 2011-05-30 by hskim, ���Ǵ�Ƽ 3�� - ���� ���� Ŭ���̾�Ʈ �ݿ�
						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));
			
						// NPC Server���� ���͸� �����Ѵ�.
						DelelteMonsterHandler(ptmpNPCMonster);
					}
				}
			}
			break;
		}		
	}
}

void CNPCMapChannel::SetCityWarOccupyGuildUID(UID32_t i_guildUID)
{
	m_CityWarOccupyGuildUID = i_guildUID;
}
BOOL CNPCMapChannel::NPCOnMonsterCreateOK(MSG_FN_MONSTER_CREATE_OK * i_pCreateOK)
{
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.lock();
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.push_back(*i_pCreateOK);
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.unlock();
	return TRUE;
}

void CNPCMapChannel::ProcessNPCOnMonsterCreateOK(MSG_FN_MONSTER_CREATE_OK * i_pCreateOK)
{
	CNPCMonster *ptmNPCMonster = GetNPCMonster(i_pCreateOK->MonsterIndex);
	if(NULL == ptmNPCMonster
		|| ptmNPCMonster->m_enMonsterState != MS_CREATED)
	{
		return;
	}
	ptmNPCMonster->m_enMonsterState = MS_PLAYING;
	m_nTotalMonsterCountInChannel++;

	///////////////////////////////////////////////////////////////////////////////
	// 2010-05-17 by shcho - ���Ǵ�Ƽ ���� ���� �α� ����� 
	if(g_pNPCGlobal->GetIsArenaServer()
		&& 9201 == m_MapChannelIndex.MapIndex)	// �Ʒ��� ������ ���Ǵ�Ƽ 1��(9201����) �϶��� ��´�.
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "  %10s : <= CreateOK MonIndex[%4d] MonsterUnitKind[%8d] CurMonCount[%3d] TotalMonCount[%d]\r\n", // ���� �ε���, ���� ��ȣ, ��ȯ�� ���� ����, ������ ��� ���� ��
			GET_MAP_STRING(m_MapChannelIndex), i_pCreateOK->MonsterIndex,ptmNPCMonster->MonsterInfoPtr->MonsterUnitKind,m_nCurMonsterCountInChannel, m_nTotalMonsterCountInChannel);
	}

// 	if(2035200 == ptmNPCMonster->MonsterInfoPtr->MonsterUnitKind
// 		|| 2035900 == ptmNPCMonster->MonsterInfoPtr->MonsterUnitKind)
// 	{// 2006-04-25 by cmkwon, �ӽ÷�
// 		char	szSystemLog[256];
// 		sprintf(szSystemLog, "  %10s : <= CreateOK Monster[%8d] Position(%4d, %4d %4d) CurMonCount[%3d] TotalMonCount[%d]\r\n",
// 		GET_MAP_STRING(m_MapChannelIndex), ptmNPCMonster->MonsterInfoPtr->MonsterUnitKind, (int)ptmNPCMonster->PositionVector.x,
// 		(int)ptmNPCMonster->PositionVector.y, (int)ptmNPCMonster->PositionVector.z,
// 		m_nCurMonsterCountInChannel, m_nTotalMonsterCountInChannel);
// 		g_pNPCGlobal->WriteSystemLog(szSystemLog);
// 		DbgOut(szSystemLog);
// 	}
}


BOOL CNPCMapChannel::NPCOnMonsterDelete(MSG_FN_MONSTER_DELETE * i_pMonDelete)
{	
	m_mtvectorMSG_FN_MONSTER_DELETE.lock();
	m_mtvectorMSG_FN_MONSTER_DELETE.push_back(*i_pMonDelete);
	m_mtvectorMSG_FN_MONSTER_DELETE.unlock();
	return TRUE;
}

void CNPCMapChannel::ProcessNPCOnMonsterDelete(MSG_FN_MONSTER_DELETE * i_pMonDelete)
{
	CNPCMonster * ptmNMonster = GetNPCMonster(i_pMonDelete->MonsterIndex);
	if(NULL == ptmNMonster){			return;}

	DelelteMonsterHandler(ptmNMonster);
}

BOOL CNPCMapChannel::NPCOnMoveOK(MSG_FN_MOVE_OK	* i_pMoveOK)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pMoveOK->ClientIndex);
	if(NULL == ptmClient){					return FALSE;}

	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - ���� MapChannelIndex�� üũ�ؼ� �ٸ��� �ʱ�ȭ ó���Ѵ�.
	if(CS_NULL != ptmClient->ClientState
		&& FALSE == ptmClient->MapChannelIdx.IsSameMapChannelIndex(this->GetMapChannelIndex()))
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapChannel::NPCOnMoveOK# MapChannelIdex error !!, CliIdx(%4d) ClientMapChannelIdx(%s) NPCMapChannelIdx(%s)\r\n"
			, ptmClient->ClientIndex, GET_MAP_STRING(ptmClient->MapChannelIdx), GET_MAP_STRING(this->GetMapChannelIndex()));
		CNPCMapChannel *pNMapChann = m_pNPCMapWorkspace->GetNPCMapChannelByMapChannelIndex(ptmClient->MapChannelIdx);
		if(pNMapChann)
		{
			MSG_FN_CLIENT_GAMEEND_OK tmGameEndOK;
			tmGameEndOK.ChannelIndex	= ptmClient->MapChannelIdx.ChannelIndex;
			tmGameEndOK.ClientIndex		= ptmClient->ClientIndex;
			pNMapChann->NPCOnClientGameEndOK(&tmGameEndOK);
		}
		return FALSE;	// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - �ʱ�ȭ�� �ϰ� �����Ѵ�
	}

	this->SetExistUserInMapChannel(TRUE);		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - ������ ������ �����Ѵ�.

	if(ptmClient->ClientState == CS_NULL)
	{	// ĳ���� ������ ������ ������ ��û�Ѵ�.

		if(ptmClient->IsSendableReq_FN_GET_CHARACTER_INFO())
		{// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - ���� �ð��� �ѹ��� ��û�� �����Ѵ�.
			BYTE SendBuf[128];
			INIT_MSG(MSG_FN_GET_CHARACTER_INFO, T_FN_GET_CHARACTER_INFO, pSendCharacterInfo, SendBuf);
			pSendCharacterInfo->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
			pSendCharacterInfo->ClientIndex		= i_pMoveOK->ClientIndex;
			Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_GET_CHARACTER_INFO));
		}
	}
	else if(ptmClient->ClientState == CS_GAMESTARTED)
	{	// ĳ�� ������ �ְ� ���� ���°� �ƴϸ� Position�� Update�� ó���ȴ�.

		D3DXVECTOR3 tmVector3Pos = A2DX(i_pMoveOK->PositionVector);

		UpdateBlockPosition(ptmClient->PositionVector.x, ptmClient->PositionVector.z,
			tmVector3Pos.x, tmVector3Pos.z, ptmClient->ClientIndex);
		ptmClient->PositionVector	= tmVector3Pos;
		ptmClient->TargetVector		= A2DX(i_pMoveOK->TargetVector);
		D3DXVec3Normalize(&ptmClient->TargetVector, &ptmClient->TargetVector);
	}
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnAdminSummonMonster(MSG_FN_ADMIN_SUMMON_MONSTER * i_pSummonMonster, int i_nTargetIndex/*=0*/)
{
	char	szError[1024];
	D3DXVECTOR3	tmVector3Pos = A2DX(i_pSummonMonster->Position);
	
	if(FALSE == m_pNPCMapProject->m_bCreateNPCThread)
	{
		sprintf(szError, "[Error] CNPCMapProject::NPCAdminSummonMonster No Create Thread for NPCServer[%d]\r\n"
			, m_pNPCMapProject->m_bCreateNPCThread);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return FALSE;
	}

	if(i_pSummonMonster->NumOfMonster <= 0 
		|| i_pSummonMonster->NumOfMonster > COUNT_MAX_ADMIN_SUMMON_MONSTER
		|| FALSE == m_pNPCMapProject->IsValidPosition(tmVector3Pos.x, tmVector3Pos.z))
	{
		sprintf(szError, "[Error] CNPCMapProject::NPCAdminSummonMonster invalid parameter, NumMonster[%d], Position(%d, %d, %d)\r\n"
			, i_pSummonMonster->NumOfMonster, (int)tmVector3Pos.x, (int)tmVector3Pos.y, (int)tmVector3Pos.z);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return FALSE;
	}

	if(m_nSizemtvectorMonsterPtr <= m_nCurMonsterCountInChannel)
	{
		sprintf(szError, "[Error] CNPCMapProject::NPCAdminSummonMonster1 Monster is full. ArrayMonsterSize[%d], CurrentMonsterCount(%d)\r\n"
			, m_nSizemtvectorMonsterPtr, m_nCurMonsterCountInChannel);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return FALSE;
	}

	map<int, MONSTER_INFO>::iterator it = m_pNPCMapProject->m_pMapMonsterParameter->find(i_pSummonMonster->MonsterUnitKind);
	if(it == m_pNPCMapProject->m_pMapMonsterParameter->end())
	{
		sprintf(szError, "[Error] CNPCMapProject::NPCAdminSummonMonster invalid parameter, MonsterUnitKind[%d]\r\n"
			, i_pSummonMonster->MonsterUnitKind);
		g_pNPCGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return FALSE;
	}

	if(strnicmp(STRMSG_S_N2TESTMONNAME_0000, it->second.MonsterName, SIZE_MAX_MONSTER_NAME) == 0
		&& i_pSummonMonster->NumOfMonster > 10)
	{
		CMonsterDBAccess MonsterDBAccess;
		MonsterDBAccess.GetAllMonsters(m_pNPCIOCPServer->m_mapMonsterParameter,
			m_pNPCIOCPServer->GetPtrMapItemInfo(), MONSTER_LOAD_TYPE_SIZE_FOR_SERVER
			, &(g_pNPCGlobal->m_Localization));
		return FALSE;
	}

	int						nIdxMonsterArray;
	CNPCMonster				*ptmMonster = NULL;
	BYTE					SendBuf[SIZE_MAX_PACKET];
	DWORD					tick = timeGetTime();	
	///////////////////////////////////////////////////////////////////////////////
	// Object Monster ��ȯ ó��
	if(FORM_OBJECT_STOP == it->second.MonsterForm
		|| FORM_OBJECT_PLANE_ROTATE == it->second.MonsterForm
		|| FORM_OBJECT_CANNON == it->second.MonsterForm)
	{
		OBJECTINFOSERVER *pObjInfo = FindObjectMonsterInfoByMonsterUniqueNumberAndMinimumDistance(i_pSummonMonster->MonsterUnitKind, &A2DX(i_pSummonMonster->Position));
		if(NULL == pObjInfo)
		{// ������ ���͸� �����ϴ� Object�� ����
			return FALSE;
		}
		else if(pObjInfo->m_EventInfo.m_byObjectMonsterCreated)
		{// ���Ͱ� �̹� ���� �Ǿ� �ִ�
			return FALSE;
		}
		
		DWORD	dwTimeGap = tick - pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated;
		if(pObjInfo->m_EventInfo.m_EventwParam3*1000 - 1000 < dwTimeGap
			&& pObjInfo->m_EventInfo.m_EventwParam2*1000 + 1000 > dwTimeGap)
		{// ���� Ÿ�� ��,�� 1�� ���̿��� ���� �Ұ�
			return FALSE;
		}

		///////////////////////////////////////////////////////////////////////////////
		// 2007-09-21 by cmkwon, ���� ���� ��ȯ�� �ڵ� �Ҹ� �ð� ����
		if(IS_STRATEGYPOINT_MONSTER(pObjInfo->m_pMonsterInfo->Belligerence)
			&& COMPARE_MPOPTION_BIT(pObjInfo->m_pMonsterInfo->MPOption, MPOPTION_BIT_AUTO_DESTROY))
		{
			// 2007-09-21 by cmkwon, ������ ���� ���� ��ȯ�� �ƴϹǷ�  �ڵ� �Ҹ�ð��� STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2 �� �����Ѵ�. 
			pObjInfo->m_pMonsterInfo->MPOptionParam1	= STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2;
		}
			
		pObjInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = tick;
		mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
		if(m_vectorUsableMonsterIndex.empty())
		{
			char	szError[1024];
			sprintf(szError, "[Error] CNPCMapChannel::NPCOnAdminSummonMonster_ Monster is full. MaxMonsterCount[%d], CurrentMonsterCount(%d)\r\n"
				, m_nMaxMonsterCountInChannel, m_nCurMonsterCountInChannel);
			g_pNPCGlobal->WriteSystemLog(szError);
			DbgOut(szError);
			return FALSE;				
		}
		nIdxMonsterArray = m_vectorUsableMonsterIndex.front();
		m_vectorUsableMonsterIndex.pop_front();
		ptmMonster = GetNPCMonster(nIdxMonsterArray);
		if(NULL == ptmMonster
			|| ptmMonster->m_enMonsterState != MS_NULL)
		{
			return FALSE;
		}
		m_nCurMonsterCountInChannel++;				// Current Counts�� ����
		pObjInfo->m_EventInfo.m_byObjectMonsterCreated = TRUE;
		
		////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
		vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr((&it->second)->HPActionIdx);
		if(NULL != pvectHPAction) {
			ptmMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
		}
		// ���� ����, �⺻�� ����
		ptmMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����
		ptmMonster->CreateNPCMonster(&it->second, &pObjInfo->m_vPos, tick, pObjInfo->m_EventInfo.m_EventwParam1
			, i_pSummonMonster->MonsterTargetType1, i_pSummonMonster->TargetTypeData1, i_pSummonMonster->CltIdxForTargetType1
			, this->GetMonsterVisibleDiameterW(), 0, pObjInfo->m_EventInfo.m_bEventType, &pObjInfo->m_vVel , &i_pSummonMonster->MonsterBalanceData ); // 2010. 06. 08 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (�Ʊ� ���� �뷱�� ����.) - ���� �뷱�� ����.
		SetInitialPositionAndSendCreateMonster(ptmMonster, SendBuf);
		////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ

		return TRUE;		
	}
	// Object Monster ��ȯ ó��_end
	///////////////////////////////////////////////////////////////////////////////	

	int						nTemp, nStartx, nEndx, nStartz, nEndz;
	int						creatMonsters;						// ������ ���� ��ü��
	D3DXVECTOR3				posVector3;
	vector<D3DXVECTOR3>		vecD3DXVECTOR;						// Monster ������ Position Vecotr�� ����� vector
	vecD3DXVECTOR.reserve(i_pSummonMonster->NumOfMonster);

	int						nRegionTileCounts = SIZE_TILE_ADMIN_SUMMON_MONSTER_REGION;
	if(0 != i_nTargetIndex)
	{
		nRegionTileCounts = SIZE_TILE_ADMIN_SUMMON_MONSTER_REGION*4;
	}

	nTemp = (int)tmVector3Pos.x/SIZE_MAP_TILE_SIZE;
	nStartx = max(0, nTemp - nRegionTileCounts);
	nEndx = min(m_pNPCMapProject->m_sXSize - 1, nTemp + nRegionTileCounts);
	nTemp = (int)tmVector3Pos.z/SIZE_MAP_TILE_SIZE;
	nStartz = max(0, nTemp - nRegionTileCounts);
	nEndz = min(m_pNPCMapProject->m_sYSize - 1, nTemp + nRegionTileCounts);
	creatMonsters = min(i_pSummonMonster->NumOfMonster, m_nSizemtvectorMonsterPtr - m_nCurMonsterCountInChannel);
	NPCGetCreatablePosition(it->second.MonsterForm, it->second.Size, nStartx, nStartz, nEndx, nEndz
		, (int)(tmVector3Pos.y - 20), (int)(tmVector3Pos.y + 20)
		, vecD3DXVECTOR, creatMonsters, FALSE, TRUE);

	if(creatMonsters <= 0)
	{
		return FALSE;
	}

	sprintf(szError, "Admin Summon Master(%10s) ==> %s, MonType[%d], Position(%5d, %4d, %5d) ReqCount[%2d] SummonCount[%2d]\r\n"
		, i_pSummonMonster->CharacterName, GET_MAP_STRING(this->GetMapChannelIndex()), i_pSummonMonster->MonsterUnitKind
		, (int)tmVector3Pos.x, (int)tmVector3Pos.y, (int)tmVector3Pos.z
		, i_pSummonMonster->NumOfMonster, vecD3DXVECTOR.size());
	g_pNPCGlobal->WriteSystemLog(szError);
	DBGOUT(szError);
	mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
	while(creatMonsters > 0 && false == vecD3DXVECTOR.empty())
	{
		creatMonsters--;
		if(m_vectorUsableMonsterIndex.empty())
		{
			sprintf(szError, "[Error] CNPCMapProject::NPCAdminSummonMonster2 Monster is full. ArrayMonsterSize[%d], CurrentMonsterCount(%d)\r\n"
				, m_nSizemtvectorMonsterPtr, m_nCurMonsterCountInChannel);
			g_pNPCGlobal->WriteSystemLog(szError);
			DbgOut(szError);
			return FALSE;
		}
		nIdxMonsterArray = m_vectorUsableMonsterIndex.front();
		m_vectorUsableMonsterIndex.pop_front();
		ptmMonster = GetNPCMonster(nIdxMonsterArray);
		if(NULL == ptmMonster
			|| ptmMonster->m_enMonsterState != MS_NULL)
		{
			return FALSE;
		}
			// ���� ����, �⺻�� ����
		m_nCurMonsterCountInChannel++;			
		posVector3 = vecD3DXVECTOR.back();
		vecD3DXVECTOR.pop_back();

		////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
		vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr((&it->second)->HPActionIdx);
		if(NULL != pvectHPAction) {
			ptmMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
		}
		
		// ���� ����, �⺻�� ����
		ptmMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����
// 		ptmMonster->CreateNPCMonster(&it->second, &posVector3, tick, 0xFFFF, i_pSummonMonster->MonsterTargetType1
// 			, i_pSummonMonster->TargetTypeData1, i_pSummonMonster->CltIdxForTargetType1, this->GetMonsterVisibleDiameterW(), i_nTargetIndex );

		// 2010. 07. 06 by hsLee. ���Ǵ�Ƽ ���̵� ����. ( ���� ��ų - ��ȯ ������ �뷱�� ���� ������ �κ� ����. )
		ptmMonster->CreateNPCMonster(&it->second, &posVector3, tick, 0xFFFF, i_pSummonMonster->MonsterTargetType1
			, i_pSummonMonster->TargetTypeData1, i_pSummonMonster->CltIdxForTargetType1, this->GetMonsterVisibleDiameterW(), i_nTargetIndex , EVENT_TYPE_NO_OBJECT_MONSTER , NULL , &i_pSummonMonster->MonsterBalanceData );
		// End 2010. 07. 06 by hsLee. ���Ǵ�Ƽ ���̵� ����. ( ���� ��ų - ��ȯ ������ �뷱�� ���� ������ �κ� ����. )

		D3DXVECTOR3 tmUnitVec3Tar;
		D3DXVec3Normalize(&tmUnitVec3Tar, &(ptmMonster->PositionVector - tmVector3Pos));
		ptmMonster->SetMoveTargetVector(&tmUnitVec3Tar);
		ptmMonster->SetTargetVector(&tmUnitVec3Tar);
		SetInitialPositionAndSendCreateMonster(ptmMonster, SendBuf, &tmVector3Pos);
		////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
	}
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnClientGameStartOK(MSG_FN_CLIENT_GAMESTART_OK * i_pClientStartOK)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pClientStartOK->ClientIndex);
	if(NULL == ptmClient){					return FALSE;}

	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - ���� MapChannelIndex�� �ٸ��� �ʱ�ȭ �ϰ� �����Ѵ�.
	if(CS_NULL != ptmClient->ClientState
		&& FALSE == ptmClient->MapChannelIdx.IsSameMapChannelIndex(this->GetMapChannelIndex()))
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapChannel::NPCOnClientGameStartOK# MapChannelIdex error !!, CliIdx(%4d) ClientMapChannelIdx(%s) NPCMapChannelIdx(%s)\r\n"
			, ptmClient->ClientIndex, GET_MAP_STRING(ptmClient->MapChannelIdx), GET_MAP_STRING(this->GetMapChannelIndex()));
		CNPCMapChannel *pNMapChann = m_pNPCMapWorkspace->GetNPCMapChannelByMapChannelIndex(ptmClient->MapChannelIdx);
		if(pNMapChann)
		{
			MSG_FN_CLIENT_GAMEEND_OK tmGameEndOK;
			tmGameEndOK.ChannelIndex	= ptmClient->MapChannelIdx.ChannelIndex;
			tmGameEndOK.ClientIndex		= ptmClient->ClientIndex;
			pNMapChann->NPCOnClientGameEndOK(&tmGameEndOK);
		}
	}

	this->SetExistUserInMapChannel(TRUE);		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - ������ ������ �����Ѵ�.

	if(ptmClient->ClientState == CS_NULL)
	{
		ptmClient->ClientState				= CS_GAMESTARTED;
		*ptmClient							= i_pClientStartOK->mexCharacter;
		ptmClient->GuildMasterCharacterUID	= i_pClientStartOK->GuildMasterCharUID;
		ptmClient->bStealthState			= i_pClientStartOK->bStealthState1;
		ptmClient->bInvisible				= i_pClientStartOK->bInvisible;				// 2006-11-27 by dhjin
		D3DXVec3Normalize(&ptmClient->TargetVector, &ptmClient->PositionVector);
		ptmClient->MapChannelIdx			= this->GetMapChannelIndex();				// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� -

		if(FALSE == SetInitialPosition(ptmClient->PositionVector.x, ptmClient->PositionVector.z, ptmClient->ClientIndex))
		{
			char szTemp[256];
			sprintf(szTemp, "[Error] SetInitialPosition_3 Error, MapChannel(%s) UnitIndex(%5d) XZ(%5.0f, %5.0f) \r\n"
				, GET_MAP_STRING(this->m_MapChannelIndex), ptmClient->ClientIndex
				, ptmClient->PositionVector.x, ptmClient->PositionVector.z);
			DBGOUT(szTemp);
			g_pNPCGlobal->WriteSystemLog(szTemp);
		}
	}
	else
	{
		D3DXVECTOR3 tmVector3Pos = A2DX(i_pClientStartOK->mexCharacter.PositionVector);

		UpdateBlockPosition(ptmClient->PositionVector.x, ptmClient->PositionVector.z,
			tmVector3Pos.x, tmVector3Pos.z, ptmClient->ClientIndex);

		ptmClient->ClientState				= CS_GAMESTARTED;
		*ptmClient							= i_pClientStartOK->mexCharacter;
		ptmClient->GuildMasterCharacterUID	= i_pClientStartOK->GuildMasterCharUID;
		ptmClient->bStealthState			= i_pClientStartOK->bStealthState1;
		ptmClient->bInvisible				= i_pClientStartOK->bInvisible;			// 2006-11-27 by dhjin
	}

	return TRUE;
}

BOOL CNPCMapChannel::NPCOnClientGameEndOK(MSG_FN_CLIENT_GAMEEND_OK * i_pClientEndOK)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pClientEndOK->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){				return FALSE;}
	
	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - ���� MapChannelIndex�� üũ �Ŀ� ó��
	if(FALSE == ptmClient->MapChannelIdx.IsSameMapChannelIndex(this->GetMapChannelIndex()))
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapChannel::NPCOnClientGameEndOK# MapChannelIdex error !!, CliIdx(%4d) ClientMapChannelIdx(%s) NPCMapChannelIdx(%s)\r\n"
			, ptmClient->ClientIndex, GET_MAP_STRING(ptmClient->MapChannelIdx), GET_MAP_STRING(this->GetMapChannelIndex()));
		return FALSE;		// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - MSG_FN_CLIENT_GAMEEND_OK ������ä���� �ٸ��� �׳� �����Ѵ�.
	}

	this->SetExistUserInMapChannel(TRUE);		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - ������ ������ �����Ѵ�.

	if(FALSE == DeleteBlockPosition(ptmClient->PositionVector.x, ptmClient->PositionVector.z, ptmClient->ClientIndex))
	{
		char szTemp[256];
		sprintf(szTemp, "[Error] DeleteBlockPosition_1 Error, MapChannel(%s) UnitIndex(%5d) XZ(%5.0f, %5.0f)\n"
			, GET_MAP_STRING(this->m_MapChannelIndex), ptmClient->ClientIndex
			, ptmClient->PositionVector.x, ptmClient->PositionVector.z);
		DBGOUT(szTemp);
		g_pNPCGlobal->WriteSystemLog(szTemp);
	}
	ptmClient->ResetClientInfo();

	return TRUE;	
}

BOOL CNPCMapChannel::NPCOnCharacterChangeBodycondition(MSG_FN_CHARACTER_CHANGE_BODYCONDITION * i_pChange)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
		
	ptmClient->BodyCondition = i_pChange->BodyCondition;
	if(COMPARE_BODYCON_BIT(ptmClient->BodyCondition, BODYCON_DEAD_MASK))
	{
		ptmClient->ClientState = CS_DEAD;
	}
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnCharacterChangeStealthState(MSG_FN_CHARACTER_CHANGE_STEALTHSTATE * i_pChange)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
		
	ptmClient->bStealthState = i_pChange->bStealthState2;

	///////////////////////////////////////////////////////////////////////////////
	// 2006-11-27 by dhjin, ���ڽ� ���°� ������ ĳ���͸� Ÿ������ �ϴ� ������ TargetIndex�� �ʱ�ȭ �Ѵ�
	if(ptmClient->bStealthState)
	{
		mt_auto_lock mtA(&m_mtvectorMonsterPtr);
		for(int i=0; i < m_mtvectorMonsterPtr.size(); i++)
		{
			CNPCMonster *pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
			if(MS_PLAYING == pNMon->m_enMonsterState
				&& FALSE == COMPARE_BODYCON_BIT(pNMon->BodyCondition, BODYCON_DEAD_MASK)
				&& i_pChange->ClientIndex == pNMon->m_nTargetIndex)
			{
				pNMon->SetTargetIndex(0);
			}
		}
	}
	
	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnCharacterChangeInvisible(MSG_FN_CHARACTER_CHANGE_INVISIBLE * i_pChange)
/// \brief		
/// \author		dhjin
/// \date		2006-11-27 ~ 2006-11-27
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnCharacterChangeInvisible(MSG_FN_CHARACTER_CHANGE_INVISIBLE * i_pChange)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
		
	ptmClient->bInvisible = i_pChange->bInvisible;

	///////////////////////////////////////////////////////////////////////////////
	// 2006-11-27 by dhjin, ���� ��ų�� ������ ĳ���͸� Ÿ������ �ϴ� ������ TargetIndex�� �ʱ�ȭ �Ѵ�
	if(ptmClient->bInvisible)
	{
		mt_auto_lock mtA(&m_mtvectorMonsterPtr);
		for(int i=0; i < m_mtvectorMonsterPtr.size(); i++)
		{
			CNPCMonster *pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
			if(MS_PLAYING == pNMon->m_enMonsterState
				&& FALSE == COMPARE_BODYCON_BIT(pNMon->BodyCondition, BODYCON_DEAD_MASK)
				&& i_pChange->ClientIndex == pNMon->m_nTargetIndex)
			{
				pNMon->SetTargetIndex(0);
			}
		}
	}
	
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnCharacterChangeCurrentHPDPSPEP(MSG_FN_CHARACTER_CHANGE_CURRENTHPDPSPEP * i_pChange)
{
	if(i_pChange->ClientIndex < MONSTER_CLIENT_INDEX_START_NUM)
	{	// ĳ������ BodyCondition

		CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
		if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
		
		ptmClient->CurrentHP = i_pChange->CurrentHP;
	}
	else
	{
		CNPCMonster * ptmNMonster = GetNPCMonster(i_pChange->ClientIndex);
		if(NULL == ptmNMonster || ptmNMonster->m_enMonsterState == MS_NULL){		return FALSE;}

		ptmNMonster->CurrentHP = i_pChange->CurrentHP;
	}
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnCharacterChangeCharacterMode(MSG_FN_CHARACTER_CHANGE_CHARACTER_MODE_OK * i_pChange)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
	
	ptmClient->CharacterMode1 = i_pChange->CharacterMode0;
	return TRUE;	
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnCharacterChangeInfluenceType(MSG_FN_CHARACTER_CHANGE_INFLUENCE_TYPE * i_pChange)
/// \brief		
/// \author		cmkwon
/// \date		2005-12-03 ~ 2005-12-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnCharacterChangeInfluenceType(MSG_FN_CHARACTER_CHANGE_INFLUENCE_TYPE * i_pChange)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pChange->ClientIndex);
	if(NULL == ptmClient || ptmClient->ClientState == CS_NULL){		return FALSE;}
	
	// 2005-12-03 by cmkwon, ���� NPC �������� ���������� ����
	// 2005-12-27 by cmkwon
	ptmClient->InfluenceType1 = i_pChange->InfluenceType0;
	return TRUE;	
}

BOOL CNPCMapChannel::NPCOnMonsterChangeHP(MSG_FN_MONSTER_CHANGE_HP * i_pChange)
{
	CNPCMonster * ptmNMonster = GetNPCMonster(i_pChange->MonsterIndex);
	if(NULL == ptmNMonster){			return FALSE;}
	
	// ���� ���� ������Ʈ	
	ptmNMonster->CurrentHP = i_pChange->CurrentHP;	

	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
	if(ptmNMonster->m_HPAction.CheckValidSizeTalkHPRate()) {
		int CurrentMonHPRate = 1;
		if( 1 < ptmNMonster->CurrentHP ) 
		{
			// 2010. 07. 06 by hsLee. ���Ǵ�Ƽ ���̵� ����. ( ���� ��ų - HPȸ�� ��ų ���� �ٲ� HP���� ������ ����ϵ��� ����. )
			/*CurrentMonHPRate = (ptmNMonster->CurrentHP * 100) / ptmNMonster->MonsterInfoPtr->MonsterHP;*/
			CurrentMonHPRate = (ptmNMonster->CurrentHP * 100) / ptmNMonster->MonsterInfoExtend.fMaxHP;
			// End 2010. 07. 06 by hsLee. ���Ǵ�Ƽ ���̵� ����. ( ���� ��ų - HPȸ�� ��ų ���� �ٲ� HP���� ������ ����ϵ��� ����. )
		}

		HPACTION_TALK_HPRATE MsgTalk;
		MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
		if(ptmNMonster->m_HPAction.GetTalkHPRate(CurrentMonHPRate, &MsgTalk)) {
			// HP�� ���� ��ȭ�� �ִٸ� �����Ѵ�.
			this->SendFSvrHPTalk(ptmNMonster, &MsgTalk);
		}
	}

	return TRUE;
}



BOOL CNPCMapChannel::NPCOnGetCharacterInfoOK(MSG_FN_GET_CHARACTER_INFO_OK * i_pInfoOK)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pInfoOK->ClientIndex);
	if(NULL == ptmClient
		|| ptmClient->ClientState != CS_NULL)
	{	// ĳ�� �ε����� ��ȿ���� �ʰų� ĳ�� ������ �̹� ������

		return FALSE;
	}

	this->SetExistUserInMapChannel(TRUE);		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 

	ptmClient->ClientState				= CS_GAMESTARTED;
	*ptmClient							= i_pInfoOK->mexCharacter;
	ptmClient->GuildMasterCharacterUID	= i_pInfoOK->GuildMasterCharUID;
	ptmClient->bStealthState			= i_pInfoOK->bStealthState1;
	ptmClient->bInvisible				= i_pInfoOK->bInvisible;			// 2006-11-27 by dhjin
	D3DXVec3Normalize(&ptmClient->TargetVector, &ptmClient->PositionVector);
	ptmClient->MapChannelIdx			= this->m_MapChannelIndex;			// 2008-12-02 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ���� ���� - 

	if(FALSE == SetInitialPosition(ptmClient->PositionVector.x, ptmClient->PositionVector.z, ptmClient->ClientIndex))
	{
		char szTemp[256];
		sprintf(szTemp, "[Error] SetInitialPosition_4 Error, MapChannel(%s) UnitIndex(%5d) XZ(%5.0f, %5.0f)\n"
			, GET_MAP_STRING(this->m_MapChannelIndex), ptmClient->ClientIndex
			, ptmClient->PositionVector.x, ptmClient->PositionVector.z);
		DBGOUT(szTemp);
		g_pNPCGlobal->WriteSystemLog(szTemp);
	}
	return TRUE;
}


BOOL CNPCMapChannel::NPCOnSkillUseSkillOK(MSG_FN_SKILL_USE_SKILL_OK * i_pSkillOK)
{
	CLIENT_INFO * ptmClient = GetClientInfo(i_pSkillOK->AttackIndex);
	if(NULL == ptmClient
		|| ptmClient->ClientState == CS_NULL
		|| TRUE == COMPARE_BODYCON_BIT(ptmClient->BodyCondition, BODYCON_DEAD_MASK))
	{
		return FALSE;
	}

	ITEM *pItemSkill = m_pNPCIOCPServer->GetItemInfo(i_pSkillOK->SkillItemID.ItemNum);
	if(NULL == pItemSkill
		|| FALSE == IS_SKILL_ITEM(pItemSkill->Kind))
	{
		return FALSE;
	}

	// 2013-03-12 by jhseol, ��ų �ѹ��� �ý��� ����
#ifdef S_SKILL_NUMBERING_RENEWAL_JHSEOL
	switch(pItemSkill->NextSkill)
#else	// #ifdef S_SKILL_NUMBERING_RENEWAL_JHSEOL
	switch(SKILL_BASE_NUM(pItemSkill->ItemNum))
#endif	// #ifdef S_SKILL_NUMBERING_RENEWAL_JHSEOL
	// end 2013-03-12 by jhseol, ��ų �ѹ��� �ý��� ����
	{
	case BGEAR_SKILL_BASENUM_BACKMOVEMACH:
	case BGEAR_SKILL_BASENUM_TURNAROUND:
	case IGEAR_SKILL_BASENUM_BACKMOVEMACH:
	case IGEAR_SKILL_BASENUM_TURNAROUND:
		{
			ptmClient->TimeUseControlSkill	= timeGetTime();
			ptmClient->UseControlSkill		= TRUE;
		}
		break;
	}

	if(FALSE == IS_MONSTER_CLIENT_INDEX(i_pSkillOK->TargetIndex))
	{
		return TRUE;
	}

	CNPCMonster *ptmNMonster = GetNPCMonster(i_pSkillOK->TargetIndex);
	if(NULL == ptmNMonster
		|| ptmNMonster->m_enMonsterState == MS_NULL
		|| TRUE == COMPARE_BODYCON_BIT(ptmNMonster->BodyCondition, BODYCON_DEAD_MASK))
	{
		return FALSE;
	}
	
// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
// 	if(DES_SKILL_SLOWMOVING == pItemSkill->DestParameter1
// 		|| DES_SKILL_SLOWMOVING == pItemSkill->DestParameter2
// 		|| DES_SKILL_SLOWMOVING == pItemSkill->DestParameter3
// 		|| DES_SKILL_SLOWMOVING == pItemSkill->DestParameter4)
	if(pItemSkill->IsExistDesParam(DES_SKILL_SLOWMOVING))
	{
		AttackedItemInfo aItem;
		aItem.AttackIndex		= i_pSkillOK->AttackIndex;
		aItem.pAttackITEM		= pItemSkill;
		aItem.dwExpireTick		= timeGetTime() + pItemSkill->Time;
		aItem.AttackedItemIndex	= m_uiAttackedItemUniqueIndex++;
		ptmNMonster->InsertAttackedItemInfo(&aItem);
	}
	
	return TRUE;
}


BOOL CNPCMapChannel::NPCOnBattleSetAttackCharacter(MSG_FN_BATTLE_SET_ATTACK_CHARACTER * i_pAttackInfo)
{
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.lock();
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.push_back(*i_pAttackInfo);
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.unlock();
	return TRUE;
}

void CNPCMapChannel::ProcessNPCOnBattleSetAttackCharacter(MSG_FN_BATTLE_SET_ATTACK_CHARACTER * i_pAttackInfo)
{
// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - �Ʒ��� ���� ������.
// 	///////////////////////////////////////////////////////////////////////////////
// 	// ���� ���� ������ ��ȿ���� üũ�Ѵ�
// 	CNPCMonster * ptmNMonster = GetNPCMonster(i_pAttackInfo->TargetIndex);
// 	if(NULL == ptmNMonster 
// 		|| ptmNMonster->m_enMonsterState == MS_NULL
// 		|| TRUE == COMPARE_BODYCON_BIT(ptmNMonster->BodyCondition, BODYCON_DEAD_MASK)
// 		|| BELL_INFINITY_DEFENSE_MONSTER == ptmNMonster->MonsterInfoPtr->Belligerence) // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ������ �������� �ʴ´�.
// 	{
// 		return;
// 	}
// 
// 	////////////////////////////////////////////////////////////////////////////////
// 	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ϳ��Լ� Ÿ�� ���� �ȵǴ� �����̸� �����Ѵ�.
// 	if(BELL_INFINITY_ATTACK_MONSTER == ptmNMonster->MonsterInfoPtr->Belligerence
// 		&& FALSE == ptmNMonster->MonsterInfoPtr->ChangeTarget) {
// 		return;
// 	}
// 
// 	///////////////////////////////////////////////////////////////////////////////
// 	// ������ ĳ������ ��ȿ���� üũ�Ѵ�
// 	CLIENT_INFO * ptmClient = GetClientInfo(i_pAttackInfo->AttackIndex);
// 	if(NULL == ptmClient
// 		|| ptmClient->ClientState == CS_NULL
// 		|| TRUE == COMPARE_BODYCON_BIT(ptmClient->BodyCondition, BODYCON_DEAD_MASK))
// 	{
// 		return;
// 	}
// 	
// // 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::ProcessNPCOnBattleSetAttackCharacter#, �Ʒ��� ���� ������.
// // 	///////////////////////////////////////////////////////////////////////////////
// // 	// ������ ���� �������� ������ �����Ѵ�(������Ʈ �����϶�)
// // 	if(NULL == ptmNMonster->m_pUsingMonsterItem)
// // 	{
// // 		return;
// // 	}
// // 
// // 	D3DXVECTOR3						TargetVector3;
// // 	float							fDistanceGap;
// // 	vector<ClientIndex_t>			vecClientTemp;
// // 	vector<ClientIndex_t>::iterator	itr;
// // 	DWORD							dwCur = timeGetTime();
// // 	int								nBeforeTargetIndex = ptmNMonster->m_nTargetIndex;
// // 
// // 	vecClientTemp.reserve(10);
// // 	////////////////////////////////////////////////////////////////////////////////
// // 	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
// // 	if(0 < i_pAttackInfo->DamageAmount 
// // 		&& ptmNMonster->m_HPAction.CheckValidSizeTalkDamagedRadom()) {
// // 		int CurrentMonHPRate = 1;
// // 		if(1 < ptmNMonster->CurrentHP) {
// // 			CurrentMonHPRate = (ptmNMonster->CurrentHP * 100) / ptmNMonster->MonsterInfoPtr->MonsterHP;
// // 		}
// // 		
// // 		HPACTION_TALK_HPRATE MsgTalk;
// // 		MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
// // 		if(ptmNMonster->m_HPAction.GetTalkDamagedRandom(MsgTalk.HPTalk)) {
// // 			// �ǰݽ� ��ȭ�� �ִٸ� �����Ѵ�.
// // 			MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
// // 			this->SendFSvrHPTalk(ptmNMonster, &MsgTalk);
// // 		}
// // 	}	
// // 
// // 	if(i_pAttackInfo->ItemKind != ITEMKIND_MINE)
// // 	{	// ���� ���� ���Ⱑ ������ �ƴϴ�
// // 				
// // 		ptmNMonster->InserttoAttackedInfoList(&ActionInfo(i_pAttackInfo->AttackIndex, dwCur, i_pAttackInfo->DamageAmount));
// // 
// // 		///////////////////////////////////////////////////////////////////////////////
// // 		// ���� TargetIndex�� 0�̰� ���ݹ��� ���Ͱ� ���� ���� �������� �ƴѰ�� ó��
// // 		if(0 == nBeforeTargetIndex
// // 			&& ptmNMonster->m_pUsingMonsterItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
// // 		{
// // 			TargetVector3 = ptmClient->PositionVector - ptmNMonster->PositionVector;
// // 			fDistanceGap = D3DXVec3Length(&TargetVector3);
// // 			if(fDistanceGap > ptmNMonster->m_pUsingMonsterItem->pItemInfo->Range
// // 				&& dwCur%100 < 50)
// // 			{
// // 				ptmNMonster->SetEnforceTargetVector(&TargetVector3, ptmNMonster->GetSpeed()*1.5f, MSS_OUT_OF_ATTACK_RANGE);
// // 			}
// // 		}		
// // 
// // 		///////////////////////////////////////////////////////////////////////////////
// // 		// ���� TargetIndex�� �����ǰ� ���ݹ��� ���Ͱ� ���������̰ų� ��Ƽ���� �϶�
// // 		if(0 != ptmNMonster->m_nTargetIndex
// // 			&& ptmClient->IsTargetableCharacter()		// 2006-11-27 by dhjin, ������(FALSE == ptmClient->bStealthState -> ptmClient->IsTargetableCharacter())
// // 			&& (ptmNMonster->MonsterInfoPtr->AttackObject == ATTACKOBJ_SAMERACE || COMPARE_MPOPTION_BIT(ptmNMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_MOVE_PARTY))
// // 			)
// // 		{		
// // 			///////////////////////////////////////////////////////////////////////////////
// // 			// �������� ���͸� �˻��Ѵ�
// // 			NPCGetAdjacentMonsterIndexes(&ptmNMonster->PositionVector, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE<<1, &vecClientTemp);
// // 			itr = vecClientTemp.begin();
// // 			while(itr != vecClientTemp.end())
// // 			{
// // 				CNPCMonster *pMTemp = GetNPCMonster(*itr);
// // 				if(pMTemp
// // 					&& pMTemp->m_enMonsterState != MS_NULL
// // 					&& COMPARE_BODYCON_BIT(pMTemp->BodyCondition, BODYCON_DEAD_MASK) == FALSE
// // 					&& pMTemp->MonsterInfoPtr->MonsterUnitKind == ptmNMonster->MonsterInfoPtr->MonsterUnitKind
// // 					&& pMTemp->m_nTargetIndex == 0)
// // 				{
// // 					pMTemp->SetTargetIndex(ptmNMonster->m_nTargetIndex);
// // 					if(pMTemp->m_pUsingMonsterItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
// // 					{
// // 						TargetVector3 = ptmClient->PositionVector - pMTemp->PositionVector;
// // 						fDistanceGap = D3DXVec3Length(&TargetVector3);
// // 						if(fDistanceGap > ptmNMonster->m_pUsingMonsterItem->pItemInfo->Range
// // 							&& dwCur%100 < 50)
// // 						{
// // 							pMTemp->SetEnforceTargetVector(&TargetVector3, pMTemp->GetSpeed()*1.5f, MSS_OUT_OF_ATTACK_RANGE);
// // 						}
// // 					}
// // 				}
// // 				itr++;
// // 			}
// // 		}		
// // 	}
// // 	else if(0 == nBeforeTargetIndex)
// // 	{// ���� ���� ���Ⱑ �����̸� ���Ͱ� Ÿ���� ������, ���Ͱ� �������� Ÿ���� ã�´�
// // 		
// // 		///////////////////////////////////////////////////////////////////////////////
// // 		// �������� ĳ���͸� �˻��Ѵ�
// // 		if(0 != NPCGetAdjacentCharacterIndexes(&ptmNMonster->PositionVector, ptmNMonster->m_pUsingMonsterItem->pItemInfo->Range
// // 			, ptmNMonster->m_pUsingMonsterItem->pItemInfo->Range*2, &vecClientTemp))
// // 		{	
// // 			///////////////////////////////////////////////////////////////////////////////
// // 			// �˻��� ĳ�����߿��� Ÿ�� �ε����� �����Ѵ�. 
// // 			ptmNMonster->SelectTargetIndex(NPCGetTargetwithAttackObj(ATTACKOBJ_CLOSERANGE, ptmNMonster, vecClientTemp));
// // 
// // 			///////////////////////////////////////////////////////////////////////////////
// // 			// ���� TargetIndex�� �����ǰ� ���ݹ��� ���Ͱ� ���������̰ų� ��Ƽ���� �϶�
// // 			if( ptmNMonster->m_nTargetIndex != 0
// // 				&& ptmClient->IsTargetableCharacter()		// 2006-11-27 by dhjin, ������(FALSE == ptmClient->bStealthState -> ptmClient->IsTargetableCharacter())
// // 				&& (ptmNMonster->MonsterInfoPtr->AttackObject == ATTACKOBJ_SAMERACE || COMPARE_MPOPTION_BIT(ptmNMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_MOVE_PARTY)) )
// // 			{
// // 
// // 				///////////////////////////////////////////////////////////////////////////////
// // 				// �������� ���͸� �˻��Ѵ�
// // 				NPCGetAdjacentMonsterIndexes(&ptmNMonster->PositionVector, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE<<1, &vecClientTemp);
// // 				itr = vecClientTemp.begin();
// // 				while(itr != vecClientTemp.end())
// // 				{
// // 					
// // 					CNPCMonster *pMTemp = GetNPCMonster(*itr);
// // 					if(pMTemp
// // 						&& pMTemp->m_enMonsterState != MS_NULL
// // 						&& COMPARE_BODYCON_BIT(pMTemp->BodyCondition, BODYCON_DEAD_MASK) == FALSE
// // 						&& pMTemp->MonsterInfoPtr->MonsterUnitKind == ptmNMonster->MonsterInfoPtr->MonsterUnitKind
// // 						&& pMTemp->m_nTargetIndex == 0)
// // 					{
// // 						pMTemp->SetTargetIndex(ptmNMonster->m_nTargetIndex);
// // 						if(pMTemp->m_pUsingMonsterItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
// // 						{
// // 							TargetVector3 = ptmClient->PositionVector - pMTemp->PositionVector;
// // 							fDistanceGap = D3DXVec3Length(&TargetVector3);
// // 							if(fDistanceGap > pMTemp->m_pUsingMonsterItem->pItemInfo->Range
// // 								&& dwCur%100 < 50)
// // 							{
// // 								pMTemp->SetEnforceTargetVector(&TargetVector3, pMTemp->GetSpeed()*1.5f, MSS_OUT_OF_ATTACK_RANGE);
// // 							}
// // 						}
// // 					}
// // 					itr++;
// // 				}
// // 			}
// // 		}
// // 	}
// 	///////////////////////////////////////////////////////////////////////////////
// 	// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::ProcessNPCOnBattleSetAttackCharacter#
// 	MONSTER_INFO	*pAttMonsterInfo	= ptmNMonster->MonsterInfoPtr;
// 	MONSTER_ITEM	*pAttMonsterItem	= ptmNMonster->m_pUsingMonsterItem;
// 	if(NULL == pAttMonsterInfo
// 		|| NULL == pAttMonsterItem)
// 	{
// 		return;
// 	}
// 
// 	D3DXVECTOR3						TargetVector3;
// 	float							fDistanceGap;
// 	vector<ClientIndex_t>			vecClientTemp;
// 	vector<ClientIndex_t>::iterator	itr;
// 	DWORD							dwCur = timeGetTime();
// 	int								nBeforeTargetIndex = ptmNMonster->m_nTargetIndex;
// 
// 	vecClientTemp.reserve(10);
// 	////////////////////////////////////////////////////////////////////////////////
// 	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
// 	if(0 < i_pAttackInfo->DamageAmount 
// 		&& ptmNMonster->m_HPAction.CheckValidSizeTalkDamagedRadom()) {
// 		int CurrentMonHPRate = 1;
// 		if(1 < ptmNMonster->CurrentHP) {
// 			CurrentMonHPRate = (ptmNMonster->CurrentHP * 100) / pAttMonsterInfo->MonsterHP;
// 		}
// 		
// 		HPACTION_TALK_HPRATE MsgTalk;
// 		MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
// 		if(ptmNMonster->m_HPAction.GetTalkDamagedRandom(MsgTalk.HPTalk)) {
// 			// �ǰݽ� ��ȭ�� �ִٸ� �����Ѵ�.
// 			MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
// 			this->SendFSvrHPTalk(ptmNMonster, &MsgTalk);
// 		}
// 	}	
// 
// 	ptmNMonster->InserttoAttackedInfoList(&ActionInfo(i_pAttackInfo->AttackIndex, dwCur, i_pAttackInfo->DamageAmount));
// 
// 	///////////////////////////////////////////////////////////////////////////////
// 	// ���� TargetIndex�� 0�̰� ���ݹ��� ���Ͱ� ���� ���� �������� �ƴѰ�� ó��
// 	if(0 == nBeforeTargetIndex
// 		&& pAttMonsterItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
// 	{
// 		TargetVector3 = ptmClient->PositionVector - ptmNMonster->PositionVector;
// 		fDistanceGap = D3DXVec3Length(&TargetVector3);
// 		if(fDistanceGap > pAttMonsterItem->pItemInfo->Range
// 			&& dwCur%100 < 50)
// 		{
// 			ptmNMonster->SetEnforceTargetVector(&TargetVector3, ptmNMonster->GetSpeed()*1.5f, MSS_OUT_OF_ATTACK_RANGE);
// 		}
// 	}		
// 
// 	///////////////////////////////////////////////////////////////////////////////
// 	// ���� TargetIndex�� �����ǰ� ���ݹ��� ���Ͱ� ���������̰ų� ��Ƽ���� �϶�
// 	ClientIndex_t curTargetIdx = ptmNMonster->GetTargetIndex();
// 	if(0 != curTargetIdx
// 		&& ptmClient->IsTargetableCharacter()
// 		&& (pAttMonsterInfo->AttackObject == ATTACKOBJ_SAMERACE || COMPARE_MPOPTION_BIT(pAttMonsterInfo->MPOption, MPOPTION_BIT_MOVE_PARTY))
// 		)
// 	{		
// 		///////////////////////////////////////////////////////////////////////////////
// 		// �������� ���͸� �˻��Ѵ�
// 		NPCGetAdjacentMonsterIndexes(&ptmNMonster->PositionVector, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE<<1, &vecClientTemp);
// 		itr = vecClientTemp.begin();
// 		for(; itr != vecClientTemp.end(); itr++)
// 		{
// 			CNPCMonster *pNPCMon = GetNPCMonster(*itr);
// 			if(pNPCMon
// 				&& pNPCMon->IsValidMonster()				
// 				&& pNPCMon->MonsterInfoPtr->MonsterUnitKind == pAttMonsterInfo->MonsterUnitKind
// 				&& 0 == pNPCMon->GetTargetIndex())
// 			{
// 				pNPCMon->SelectTargetIndex(curTargetIdx);
// 			}		
// 		}
// 	}
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
	CLIENT_INFO *pAttackerCli = NULL;
	CNPCMonster	*pAttackerNMon = NULL;
	if(FALSE == this->GetUnitObject(i_pAttackInfo->AttackIndex, &pAttackerCli, &pAttackerNMon))
	{
		return;
	}
	CNPCMonster *pTargetNMon = GetNPCMonster(i_pAttackInfo->TargetIndex);
	if(NULL == pTargetNMon
		|| FALSE == pTargetNMon->IsValidMonster())
	{
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::ProcessNPCOnBattleSetAttackCharacter#
	MONSTER_INFO	*pTarMonsterInfo	= pTargetNMon->MonsterInfoPtr;
	MONSTER_ITEM	*pTarMonsterItem	= pTargetNMon->m_pUsingMonsterItem;
	if(NULL == pTarMonsterInfo
		|| NULL == pTarMonsterItem 
		|| NULL == pTarMonsterItem->pItemInfo )		// 2012-12-17 by hskim, NPC ���� �״� ���� ���� (���� ������ pItemInfo �� NULL �Ǵ� ����)
	{
		return;
	}

	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
	if(0 < i_pAttackInfo->DamageAmount 
		&& pTargetNMon->m_HPAction.CheckValidSizeTalkDamagedRadom())
	{
		int CurrentMonHPRate = 1;
		if(1 < pTargetNMon->CurrentHP)
		{
			CurrentMonHPRate = (pTargetNMon->CurrentHP * 100) / pTarMonsterInfo->MonsterHP;
		}
		
		HPACTION_TALK_HPRATE MsgTalk;
		MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
		if(pTargetNMon->m_HPAction.GetTalkDamagedRandom(MsgTalk.HPTalk)) {
			// �ǰݽ� ��ȭ�� �ִٸ� �����Ѵ�.
			MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
			this->SendFSvrHPTalk(pTargetNMon, &MsgTalk);
		}
	}
	int		nBeforeTargetIndex = pTargetNMon->GetTargetIndex();
	DWORD	dwCur = timeGetTime();
	pTargetNMon->InserttoAttackedInfoList(&ActionInfo(i_pAttackInfo->AttackIndex, dwCur, i_pAttackInfo->DamageAmount));

	///////////////////////////////////////////////////////////////////////////////
	// ���� TargetIndex�� 0�̰� ���ݹ��� ���Ͱ� ���� ���� �������� �ƴѰ�� ó��
	if(0 == nBeforeTargetIndex
		&& pTarMonsterItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
	{
		D3DXVECTOR3		TargetVector3;
		float			fDistanceGap = 0.0f;
		TargetVector3	= (pAttackerCli?pAttackerCli->PositionVector : pAttackerNMon->PositionVector) - pTargetNMon->PositionVector;
		fDistanceGap	= D3DXVec3Length(&TargetVector3);
		if(fDistanceGap > pTarMonsterItem->pItemInfo->Range
			&& dwCur%100 < 50)
		{
			pTargetNMon->SetEnforceTargetVector(&TargetVector3, pTargetNMon->GetSpeed()*1.5f, MSS_OUT_OF_ATTACK_RANGE);
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� TargetIndex�� �����ǰ� ���ݹ��� ���Ͱ� ���������̰ų� ��Ƽ���� �϶�
	ClientIndex_t curTargetIdx = pTargetNMon->GetTargetIndex();
	if(0 != curTargetIdx
		&& (pTarMonsterInfo->AttackObject == ATTACKOBJ_SAMERACE || COMPARE_MPOPTION_BIT(pTarMonsterInfo->MPOption, MPOPTION_BIT_MOVE_PARTY))
		)
	{		
		vector<ClientIndex_t>			vecClientTemp;				
		vecClientTemp.reserve(10);
		///////////////////////////////////////////////////////////////////////////////
		// �������� ���͸� �˻��Ѵ�
		NPCGetAdjacentMonsterIndexes(&pTargetNMon->PositionVector, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE, MONSTER_ATTACKOBJ_SAMERACE_MAX_DISTANCE<<1, &vecClientTemp, pTarMonsterInfo->MonsterUnitKind);
		vector<ClientIndex_t>::iterator	itr = vecClientTemp.begin();
		for(; itr != vecClientTemp.end(); itr++)
		{
			CNPCMonster *pNPCMon = GetNPCMonster(*itr);
			if(pNPCMon
				&& pNPCMon->IsValidMonster()
				&& 0 == pNPCMon->GetTargetIndex())
			{
				pNPCMon->SelectTargetIndex(curTargetIdx);
			}		
		}
	}
}

void CNPCMapChannel::ProcessNPCOnCityWarStartWar(MSG_FN_CITYWAR_START_WAR *i_pStartWar)
{
	m_bCityWarStarted = TRUE;			// CityWar�� ���۵�
}
void CNPCMapChannel::ProcessNPCOnCityWarEndWar(MSG_FN_CITYWAR_END_WAR *i_pEndWar)
{
	m_bCityWarStarted	= FALSE;		// CityWar�� �����
	this->SetCityWarOccupyGuildUID(i_pEndWar->OccupyGuildUID4);

	this->DeleteAllMonster();
// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰� - ���� ���� �Լ��� ����
//	///////////////////////////////////////////////////////////////////////////////
//	// �ʾ��� ��� ���͸� �����Ѵ�
//	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
//	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, SendBuf);
//	pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//	for(int i=0; i < m_mtvectorMonsterPtr.size(); i++)
//	{
//		CNPCMonster *pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
//		if(MS_PLAYING == pNMon->m_enMonsterState
//			&& FALSE == COMPARE_BODYCON_BIT(pNMon->BodyCondition, BODYCON_DEAD_MASK))
//		{	
//			pMonsterDelete->MonsterIndex	= pNMon->MonsterIndex;
//			Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));
//
//			this->DelelteMonsterHandler(pNMon);
//		}
//	}
}
void CNPCMapChannel::ProcessNPCOnCityWarChangeOccupyInfo(MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO *i_pChangeOccupyInfo)
{	
	this->SetCityWarOccupyGuildUID(i_pChangeOccupyInfo->OccupyGuildUID4);

	///////////////////////////////////////////////////////////////////////////////
	// �ʾ��� ��� ������ Ÿ���ε������� ���ɿ��ܿ��� �����Ѵ�
	for(int i=0; i < m_mtvectorMonsterPtr.size(); i++)
	{
		CNPCMonster *pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
		if(MS_PLAYING == pNMon->m_enMonsterState
			&& FALSE == COMPARE_BODYCON_BIT(pNMon->BodyCondition, BODYCON_DEAD_MASK)
			&& 0 != pNMon->m_nTargetIndex)
		{
			CLIENT_INFO *pCInfo = GetClientInfo(pNMon->m_nTargetIndex);
			if(pCInfo
				&& pCInfo->GuildUID10 == m_CityWarOccupyGuildUID)
			{
				pNMon->SetTargetIndex(0);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterStrategyPointInit(MSG_FN_MONSTER_STRATEGYPOINT_INIT *i_pMsg)
/// \brief		
/// \author		cmkwon
/// \date		2006-11-20 ~ 2006-11-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterStrategyPointInit(MSG_FN_MONSTER_STRATEGYPOINT_INIT *i_pMsg)
{
	///////////////////////////////////////////////////////////////////////////////
	// 1. �ʾ��� ��������Ʈ ���͸� �����Ѵ�
	// 2007-09-20 by cmkwon, �ڷ���Ʈ ���� - �ڷ���Ʈ�� ����ó���Ѵ�.
	this->DeleteAllMonster(FALSE, BELL_STRATEGYPOINT_VCN, BELL_STRATEGYPOINT_ANI);
	this->DeleteAllMonster(FALSE, BELL_INFLUENCE_TELEPORT_VCN, BELL_INFLUENCE_TELEPORT_ANI);	// 2007-09-20 by cmkwon, �ڷ���Ʈ ���� - �ڷ���Ʈ�� ����ó���Ѵ�.
// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰� - ���� ���� �Լ��� ��ü
//	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
//	for(int i=0; i < m_mtvectorMonsterPtr.size(); i++)
//	{
//		CNPCMonster *pNMon		= (CNPCMonster*)m_mtvectorMonsterPtr[i];
//		MONSTER_INFO *pMonInfo	= pNMon->MonsterInfoPtr;					// 2006-12-13 by cmkwon
//		if(MS_NULL != pNMon->m_enMonsterState
//			&& pMonInfo
//			&& IS_STRATEGYPOINT_MONSTER(pMonInfo->Belligerence))
//		{
//			///////////////////////////////////////////////////////////////////////////////
//			// 2006-11-20 by cmkwon, �ٷ� ����ó���Ѵ�.
//			INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, SendBuf);
//			pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//			pMonsterDelete->MonsterIndex	= pNMon->MonsterIndex;
//			Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));
//
//			DelelteMonsterHandler(pNMon);
//		}
//	}
//	mtA.auto_unlock_cancel();

	if(i_pMsg->bCreateFlag)
	{// 2006-11-20 by cmkwon, ���� �� �ٷ� ��������Ʈ ���͸� ��ȯ �Ѵ�
		
		BYTE					SendBuf[SIZE_MAX_PACKET];

		// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ� - �Ʒ��� ���� Belligerence �˻����� ����
		//OBJECTINFOSERVER *pObjBossMonsterObjInfo = FindObjectBossMonsterInfo();
		OBJECTINFOSERVER *pObjBossMonsterObjInfo = this->FindObjectMonsterInfoBYBelligerence(i_pMsg->bVCNMapInflTyforInit?BELL_STRATEGYPOINT_VCN:BELL_STRATEGYPOINT_ANI);
		if(NULL == pObjBossMonsterObjInfo)
		{
			return;
		}

		///////////////////////////////////////////////////////////////////////////////
		// 2007-10-18 by cmkwon, �������� �ڵ� �Ҹ� �ð� ���� ����
		if(COMPARE_MPOPTION_BIT(pObjBossMonsterObjInfo->m_pMonsterInfo->MPOption, MPOPTION_BIT_AUTO_DESTROY))
		{
			if(FALSE == i_pMsg->bInfluenceBoss)
			{
				// 2007-09-21 by cmkwon, ������ ���� ���� ��ȯ�� �ƴϹǷ�  �ڵ� �Ҹ�ð��� STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2 �� �����Ѵ�. 
				pObjBossMonsterObjInfo->m_pMonsterInfo->MPOptionParam1	= STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2;
			}
			else
			{
				// 2007-09-21 by cmkwon, ������ ���� ���� ��ȯ�̹Ƿ�  �ڵ� �Ҹ�ð��� STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS �� �����Ѵ�. 
				// 2007-12-07 by dhjin, �ڵ� �Ҹ� �ð� ���׷� �ذ� ���� ����, 130������ ����
				// pObjBossMonsterObjInfo->m_pMonsterInfo->MPOptionParam1	= STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS;
				pObjBossMonsterObjInfo->m_pMonsterInfo->MPOptionParam1	= STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS + 10;
			}
		}
		this->CreateMonstersBYObject(SendBuf, pObjBossMonsterObjInfo, timeGetTime(), TRUE);

// 2006-11-22 by cmkwon, �ϴ� ��������Ʈ ���ʹ� ������Ʈ ���ͷ� ���� ����
//		else
//		{
//			vector<D3DXVECTOR3>		vectVec3;
//			int nMonsterInfoSize = m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO.size();
//			for(int i=0; i < nMonsterInfoSize; i++)
//			{
//				MONSTER_CREATE_REGION_INFO *pMonsterCreateRegionInfo = &m_pNPCMapProject->m_vectorMONSTER_CREATE_REGION_INFO[i];
//				MONSTER_INFO *pMonInfo = m_pNPCIOCPServer->GetMonsterInfo(pMonsterCreateRegionInfo->sMonType);
//				if(pMonInfo
//					&& IS_STRATEGYPOINT_MONSTER(pMonInfo->Belligerence))
//				{
//					this->CreateMonstersBYRegion(SendBuf, &vectVec3, timeGetTime(), i, pMonsterCreateRegionInfo, &m_vectorMonsterCreateRegionInfoEX[i], TRUE);
//					break;
//				}
//			}
//		}
	}
	else if(FALSE == i_pMsg->bCreateFlag && FALSE == i_pMsg->bInfluenceBoss)
	{// 2007-09-16 by dhjin, ���� �ı��� ���� ���� ��ȯ�� ����Ѵ�.
		// 2009-12-04 by cmkwon, ���� �������� ���� �α� �߰� - �Ʒ��� ���� SetNotCreateMonsterValue()�Լ��� ����
		//m_bNotCreateMonster	= FALSE;
		this->SetNotCreateMonsterValue(FALSE);
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterDeleteMonsterInMapChannel(MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL *i_pMsg)
/// \brief		// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰�
/// \author		cmkwon
/// \date		2007-08-22 ~ 2007-08-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterDeleteMonsterInMapChannel(MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL *i_pMsg)
{
	if(i_pMsg->bNotCreateMonster)
	{// 2007-08-29 by dhjin, ���� ���� �����̸� m_bNotCreateMonster = TRUE�� �����Ͽ� ���Ϳ� ������ ���´�.
		// 2009-12-04 by cmkwon, ���� �������� ���� �α� �߰� - �Ʒ��� ���� SetNotCreateMonsterValue()�Լ��� ����
		//m_bNotCreateMonster = TRUE;
		this->SetNotCreateMonsterValue(TRUE);
	}

	this->DeleteAllMonster(i_pMsg->bAllFlag, i_pMsg->bell1, i_pMsg->bell2, i_pMsg->excludeBell1, i_pMsg->excludeBell2);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterOutPostInit(MSG_FN_MONSTER_OUTPOST_INIT *i_pMsg)
/// \brief		
/// \author		dhjin
/// \date		2007-08-24 ~ 2007-08-24
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterOutPostInit(MSG_FN_MONSTER_OUTPOST_INIT *i_pMsg)
{
	// 2007-10-02 by dhjin, �׽�Ʈ ��
	g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Notify]: OUTPOST_SUMMON bell 1 : [%6d], bell 2 : [%6d], bell 3 : [%6d]\r\n"
	, i_pMsg->bell1, i_pMsg->bell2, i_pMsg->bell3);
	
	///////////////////////////////////////////////////////////////////////////////
	// 1. �ʾ��� ��������Ʈ ���͸� �����Ѵ�
	this->DeleteAllMonster(TRUE);


	// 2. �������� �ʿ� �����ؾ� �Ǵ� ���� ���� ��ȯ
	BYTE	SendBuf[SIZE_MAX_PACKET];
	
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		if(itr->m_pMonsterInfo
			&& (itr->m_pMonsterInfo->Belligerence == i_pMsg->bell1 
				|| itr->m_pMonsterInfo->Belligerence == i_pMsg->bell2
				|| itr->m_pMonsterInfo->Belligerence == i_pMsg->bell3) )
		{
			OBJECTINFOSERVER *pObjBossMonsterObjInfo = &*itr;
			if(pObjBossMonsterObjInfo)
			{// 2006-11-22 by cmkwon
				this->CreateMonstersBYObject(SendBuf, pObjBossMonsterObjInfo, timeGetTime(), TRUE);
				
				// 2007-10-02 by dhjin, �׽�Ʈ ��
				g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Notify]: OUTPOST_SUMMON bell : [%6d]\r\n"
				, pObjBossMonsterObjInfo->m_pMonsterInfo->Belligerence);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterCreate(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE *i_pMsg)
/// \brief		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���Ǵ�Ƽ - Key���� ����
///				// 2010-03-31 by cmkwon, ����2�� �߰� ���� - 
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterCreate(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE *i_pMsg)
{

// 2010-03-31 by cmkwon, ����2�� �߰� ���� - �Ʒ��� ���� ����.	
// 	// ������Ʈ ���� ���� ��������
// 	OBJECTINFOSERVER CinemaObjectMonster;
// 	if(FALSE == this->GetObjectMonsterByMonsterIdx(i_pMsg->MonsterUnitKind, &CinemaObjectMonster)) {
// 		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Infinity]: CinemaMonsterCreate Fail!!!!! MapIdx : [%6d], MapChannel : [%6d], MonsterIdx : [%6d]\r\n"
// 					, i_pMsg->mapChann.MapIndex, i_pMsg->mapChann.ChannelIndex, i_pMsg->MonsterUnitKind);		
// 		return;
// 	}
// 
// 	CNPCMonster				*pCinemaMonster = NULL;
// 	BYTE					SendBuf[SIZE_MAX_PACKET];
// 	DWORD					tick = timeGetTime();
// 	D3DXVECTOR3				RandomposVector3;
// 	
// 	MONSTER_INFO * pCinemaMonInfo = m_pNPCIOCPServer->GetMonsterInfo(i_pMsg->MonsterUnitKind);
// 	if(NULL == pCinemaMonInfo)
// 	{
// 		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapProject::NPCAdminSummonMonster invalid parameter, MonsterUnitKind[%d]\r\n", i_pMsg->MonsterUnitKind);		
// 		return;
// 	}
// 
// 	mt_auto_lock mtMon(&m_mtvectorMonsterPtr);
// 	for(int i=0; i < i_pMsg->MonsterSummonCount; i++) 
// 	{	// ��ȯ �Ǿ�� �Ǵ� ����ŭ ��ȯ!
// 		
// 		if(m_vectorUsableMonsterIndex.empty())
// 		{
// 			g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapProject::ProcessNPCOnMonsterCinemaMonsterCreate Monster is full. ArrayMonsterSize[%d], CurrentMonsterCount(%d)\r\n"
// 				, m_nSizemtvectorMonsterPtr, m_nCurMonsterCountInChannel);		
// 			return;
// 		}
// 		
// 		pCinemaMonster = this->GetInitNPCMonster();
// 		if(NULL == pCinemaMonster
// 			|| pCinemaMonster->m_enMonsterState != MS_NULL)
// 		{
// 			return;
// 		}
// 		// ���� ����, �⺻�� ����
// 		m_nCurMonsterCountInChannel++;			
// 
// 		// ���� ��ǥ ����
// 		RandomposVector3.x	= CinemaObjectMonster.m_vPos.x + RANDI(0, i_pMsg->MaxRandomDistance);
// 		RandomposVector3.y	= CinemaObjectMonster.m_vPos.y + RANDI(0, i_pMsg->MaxRandomDistance);
// 		RandomposVector3.z	= CinemaObjectMonster.m_vPos.z + RANDI(0, i_pMsg->MaxRandomDistance);
// 		RandomposVector3.x	= min(RandomposVector3.x, this->GetSizeMapXW()-1.0f);
// 		RandomposVector3.z	= min(RandomposVector3.z, this->GetSizeMapZW()-1.0f);
// 
// 		////////////////////////////////////////////////////////////////////////
// 		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
// 		vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr(pCinemaMonInfo->HPActionIdx);
// 		if(NULL != pvectHPAction) {
// 			pCinemaMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
// 		}
// 		
// 		// ���� ����, �⺻�� ����
// 		pCinemaMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����
// 		pCinemaMonster->CreateNPCMonster(pCinemaMonInfo, &RandomposVector3, tick, 0xFFFF
// 			, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW(), 0, CinemaObjectMonster.m_EventInfo.m_bEventType, &CinemaObjectMonster.m_vVel);
// 		SetInitialPositionAndSendCreateMonster(pCinemaMonster, SendBuf);
// 		////////////////////////////////////////////////////////////////////////
// 		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
// 		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Infinity]: CinemaMonsterCreate MapIdx : [%6d], MapChannel : [%6d], MonsterIdx : [%6d]\r\n"
// 				, i_pMsg->mapChann.MapIndex, i_pMsg->mapChann.ChannelIndex, i_pMsg->MonsterUnitKind);
// 	}
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-31 by cmkwon, ����2�� �߰� ���� - 
	MONSTER_INFO * pCinemaMonInfo = m_pNPCIOCPServer->GetMonsterInfo(i_pMsg->MonsterUnitKind);
	if(NULL == pCinemaMonInfo)
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapProject::NPCAdminSummonMonster invalid parameter, MonsterUnitKind[%d]\r\n", i_pMsg->MonsterUnitKind);		
		return;
	}

	vectorObjectInfoServerPtr tmObjInfoServList;
	this->GetObjectMonsterByMonsterIdx(i_pMsg->MonsterUnitKind, &tmObjInfoServList);
	if(tmObjInfoServList.empty())
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Infinity]: CinemaMonsterCreate Fail!!!!! MapIdx : [%6d], MapChannel : [%6d], MonsterIdx : [%6d]\r\n"
					, i_pMsg->mapChann.MapIndex, i_pMsg->mapChann.ChannelIndex, i_pMsg->MonsterUnitKind);		
		return;
	}

	mt_auto_lock mtMon(&m_mtvectorMonsterPtr);

	OBJECTINFOSERVER *pObjInfo4Summon = NULL;
	vectorObjectInfoServerPtr::iterator itr(tmObjInfoServList.begin());
	for(; itr != tmObjInfoServList.end(); itr++)
	{
		pObjInfo4Summon	= *itr;

		BYTE					SendBuf[SIZE_MAX_PACKET];
		for(int i=0; i < i_pMsg->MonsterSummonCount; i++) 
		{	// ��ȯ �Ǿ�� �Ǵ� ����ŭ ��ȯ!
			
			if(m_vectorUsableMonsterIndex.empty())
			{
				g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Error] CNPCMapProject::ProcessNPCOnMonsterCinemaMonsterCreate Monster is full. ArrayMonsterSize[%d], CurrentMonsterCount(%d)\r\n"
					, m_nSizemtvectorMonsterPtr, m_nCurMonsterCountInChannel);		
				return;
			}
			
			CNPCMonster *pCinemaMonster = this->GetInitNPCMonster();
			if(NULL == pCinemaMonster
				|| pCinemaMonster->m_enMonsterState != MS_NULL)
			{
				return;
			}
			// ���� ����, �⺻�� ����
			m_nCurMonsterCountInChannel++;			
			
			// ���� ��ǥ ����
			D3DXVECTOR3				RandomposVector3;
			RandomposVector3.x	= pObjInfo4Summon->m_vPos.x + RANDI(0, i_pMsg->MaxRandomDistance);
			RandomposVector3.y	= pObjInfo4Summon->m_vPos.y + RANDI(0, i_pMsg->MaxRandomDistance);
			RandomposVector3.z	= pObjInfo4Summon->m_vPos.z + RANDI(0, i_pMsg->MaxRandomDistance);
			RandomposVector3.x	= min(RandomposVector3.x, this->GetSizeMapXW()-1.0f);
			RandomposVector3.z	= min(RandomposVector3.z, this->GetSizeMapZW()-1.0f);
			
			////////////////////////////////////////////////////////////////////////
			// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HPAction �ε�
			vectHPAction * pvectHPAction = m_pNPCIOCPServer->m_mapHPAction.findEZ_ptr(pCinemaMonInfo->HPActionIdx);
			if(NULL != pvectHPAction) {
				pCinemaMonster->m_HPAction.InitHPActionListByDB(pvectHPAction);
			}
			
			// ���� ����, �⺻�� ����
			pCinemaMonster->SetCurrentMapChannel(this);				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �� ä�� �̸� ����

			// 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) ) - ���� Ȯ������(�뷱��) �߰�.
			pCinemaMonster->CreateNPCMonster(pCinemaMonInfo, &RandomposVector3, timeGetTime(), 0xFFFF
				, MONSTER_TARGETTYPE_NORMAL, 0, 0, this->GetMonsterVisibleDiameterW(), 0, pObjInfo4Summon->m_EventInfo.m_bEventType, &pObjInfo4Summon->m_vVel , &i_pMsg->MonsterBalanceInfo );
			
			// End 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
			SetInitialPositionAndSendCreateMonster(pCinemaMonster, SendBuf);
			////////////////////////////////////////////////////////////////////////
			// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
//			g_pNPCGlobal->WriteSystemLogEX(TRUE, "[Infinity]: CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterCreate# Map(%s), MonNum(%6d) MonIdx(%d) Summon(%d/%d) ObjListCnt(%d) \r\n"
//				, GetMapString(i_pMsg->mapChann, string()), i_pMsg->MonsterUnitKind, pCinemaMonster->MonsterIndex, i, i_pMsg->MonsterSummonCount, tmObjInfoServList.size());
		}
	} // END - for(; itr != tmObjInfoServList.end(); itr++)
}

// start 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterDestroy(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE *i_pMsg)
/// \brief		// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		20110428
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterDestroy(MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY *i_pMsg)
{
	this->DeleteUnitKindMonster(i_pMsg->MonsterUnitKind);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterChange(MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE *i_pMsg)
/// \brief		// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		20110511
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterCinemaMonsterChange(MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE *i_pMsg)
{
	this->ChangeUnitKindMonster(i_pMsg->MonsterUnitKind, i_pMsg->ChangeMonsterUnitKind);
}
// end 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�

///////////////////////////////////////////////////////////////////////////////
/// \fn			CNPCMonster * CNPCMapChannel::GetInitNPCMonster() 
/// \brief		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
CNPCMonster * CNPCMapChannel::GetInitNPCMonster() 
{	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
	int		nIdxMonster;
	nIdxMonster = m_vectorUsableMonsterIndex.front();
	m_vectorUsableMonsterIndex.pop_front();
	return GetNPCMonster(nIdxMonster);
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::NPCOnSummonObjectMonsterBYBelligerence(int i_nbell)
/// \brief		
/// \author		dhjin
/// \date		2007-08-24 ~ 2007-08-24
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::NPCOnSummonObjectMonsterBYBelligerence(int i_nbell)
{
	BYTE					SendBuf[SIZE_MAX_PACKET];

	OBJECTINFOSERVER *pObjBossMonsterObjInfo = this->FindObjectMonsterInfoBYBelligerence(i_nbell);
	if(pObjBossMonsterObjInfo)
	{// 2006-11-22 by cmkwon

		if(IS_STRATEGYPOINT_MONSTER(pObjBossMonsterObjInfo->m_pMonsterInfo->Belligerence)
			&& COMPARE_MPOPTION_BIT(pObjBossMonsterObjInfo->m_pMonsterInfo->MPOption, MPOPTION_BIT_AUTO_DESTROY))
		{
			// 2007-09-21 by cmkwon, ������ ���� ���� ��ȯ�� �ƴϹǷ�  �ڵ� �Ҹ�ð��� STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2 �� �����Ѵ�. 
			pObjBossMonsterObjInfo->m_pMonsterInfo->MPOptionParam1	= STRATEGYPOINT_SUMMONTIME_BY_INFLUENCEBOSS/2;
		}
		this->CreateMonstersBYObject(SendBuf, pObjBossMonsterObjInfo, timeGetTime(), TRUE);
	}	
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ProcessNPCOnMonsterSummonByBell(MSG_MONSTER_SUMMON_BY_BELL *i_pMsg)
/// \brief		// 2007-09-19 by cmkwon, Bell�� ��ȯ ó��
/// \author		cmkwon
/// \date		2007-09-19 ~ 2007-09-19
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ProcessNPCOnMonsterSummonByBell(MSG_MONSTER_SUMMON_BY_BELL *i_pMsg)
{
	this->NPCOnSummonObjectMonsterBYBelligerence(i_pMsg->MonsterBell);
}

BOOL CNPCMapChannel::NPCOnMonsterChangeBodycondition(MSG_FN_MONSTER_CHANGE_BODYCONDITION * i_pChange)
{
	CNPCMonster * ptmNMonster = GetNPCMonster(i_pChange->ClientIndex);
	if(NULL == ptmNMonster || ptmNMonster->m_enMonsterState == MS_NULL){		return FALSE;}

	ptmNMonster->ChangeBodyCondition(&i_pChange->BodyCondition);
	if(COMPARE_BODYCON_BIT(ptmNMonster->BodyCondition, BODYCON_DEAD_MASK))
	{
		ptmNMonster->m_enMonsterState = MS_DEAD;

		// 2010-05-17 by shcho - ���Ǵ�Ƽ ���� ���� �α� ����� 
		if(g_pNPCGlobal->GetIsArenaServer()
			&& 9201 == m_MapChannelIndex.MapIndex)	// �Ʒ��� ������ ���Ǵ�Ƽ 1��(9201)�϶��� ��´�.
		{
			g_pNPCGlobal->WriteSystemLogEX(TRUE,"  %10s : <= DeadMonster MonsterUnitKind[%8d]\r\n",GET_MAP_STRING(m_MapChannelIndex),ptmNMonster->MonsterInfoPtr->MonsterUnitKind);
		}
	}
	
	return TRUE;
}


BOOL CNPCMapChannel::NPCOnBattleDropFixer(MSG_FN_BATTLE_DROP_FIXER * i_pFixer)
{
	CNPCMonster *pMON = this->GetNPCMonster(i_pFixer->TargetIndex);
	ITEM *pIT = m_pNPCIOCPServer->GetItemInfo(i_pFixer->ItemNum);
	if(pMON
		&& pMON->m_enMonsterState != MS_NULL
		&& pIT)
	{
		AttackedItemInfo aItem;
		aItem.AttackIndex = i_pFixer->AttackIndex;
		aItem.pAttackITEM = pIT;
		aItem.dwExpireTick = timeGetTime() + pIT->Time;
		aItem.AttackedItemIndex = m_uiAttackedItemUniqueIndex++;
		pMON->InsertAttackedItemInfo(&aItem);

		INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_DROP_FIXER_OK, T_FN_BATTLE_DROP_FIXER_OK, pSFixerOK, SendB);
		pSFixerOK->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
		pSFixerOK->AttackIndex		= i_pFixer->AttackIndex;
		pSFixerOK->TargetIndex		= i_pFixer->TargetIndex;
		pSFixerOK->ItemNum			= i_pFixer->ItemNum;
		pSFixerOK->ItemFieldIndex	= aItem.AttackedItemIndex;
		this->Send2FieldServerW(SendB, MSG_SIZE(MSG_FN_BATTLE_DROP_FIXER_OK));
	}
	return TRUE;
}

BOOL CNPCMapChannel::NPCOnMonsterSkillEndSkill(MSG_FN_MONSTER_SKILL_END_SKILL * i_pEndSkill)
{
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.lock();
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.push_back(*i_pEndSkill);
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.unlock();
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterStrategyPointInit(MSG_FN_MONSTER_STRATEGYPOINT_INIT * i_pMsg)
/// \brief		
/// \author		cmkwon
/// \date		2006-11-20 ~ 2006-11-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterStrategyPointInit(MSG_FN_MONSTER_STRATEGYPOINT_INIT * i_pMsg)
{
	mt_auto_lock mtA(&m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT);
	m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.push_back(*i_pMsg);	
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterOutPostInit(MSG_FN_MONSTER_OUTPOST_INIT * i_pMsg)
/// \brief		
/// \author		dhjin
/// \date		2007-08-24 ~ 2007-08-24
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterOutPostInit(MSG_FN_MONSTER_OUTPOST_INIT * i_pMsg)
{
	mt_auto_lock mtA(&m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT);
	m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.push_back(*i_pMsg);	
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterSummonByBell(MSG_MONSTER_SUMMON_BY_BELL * i_pMsg)
/// \brief		// 2007-09-19 by cmkwon, Bell�� ��ȯ ó��
/// \author		cmkwon
/// \date		2007-09-19 ~ 2007-09-19
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterSummonByBell(MSG_MONSTER_SUMMON_BY_BELL * i_pMsg)
{
	mt_auto_lock mtA(&m_mtvectMSG_MONSTER_SUMMON_BY_BELL);
	m_mtvectMSG_MONSTER_SUMMON_BY_BELL.push_back(*i_pMsg);	
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterCreate(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE * i_pMsg)
/// \brief		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���Ǵ�Ƽ - Key���� ���� 
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterCreate(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE * i_pMsg) {
	mt_auto_lock mtA(&m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE);
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.push_back(*i_pMsg);	
	return TRUE;
}

// start 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterDestroy(MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY * i_pMsg)
/// \brief		// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		2011-04-28
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterDestroy(MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY * i_pMsg) {
	mt_auto_lock mtA(&m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY);
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.push_back(*i_pMsg);	
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterChange(MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE * i_pMsg)
/// \brief		// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		2011-05-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterChange(MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE * i_pMsg) {
	mt_auto_lock mtA(&m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE);
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.push_back(*i_pMsg);	
	return TRUE;
}
// end 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�

// start 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterRegen(MSG_FN_NPCSERVER_CINEMA_MONSTER_REGEN * i_pMsg)
/// \brief		// 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����
/// \author		hskim
/// \date		2011-05-11
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCOnMonsterCinemaMonsterRegen(MSG_FN_NPCSERVER_CINEMA_MONSTER_REGEN * i_pMsg) 
{
	DWORD dwCurTick = timeGetTime();

	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		if( itr->m_pMonsterInfo->MonsterUnitKind == i_pMsg->iMonsterUnitKind )
		{
			if( TRUE == i_pMsg->bRegen )
			{
				itr->m_EventInfo.m_dwLastTimeObjectMonsterCreated = dwCurTick;
				itr->MonsterBalanceInfo = i_pMsg->MonsterBalanceInfo;
				itr->m_bNotCreateMonster = FALSE;
			}
			else
			{
				itr->m_bNotCreateMonster = TRUE;
			}
		}
	}

	return TRUE;
}
// end 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����

BOOL CNPCMapChannel::NPCOnCityWarStart(MSG_FN_CITYWAR_START_WAR *i_pCityWarStart)
{
	mt_auto_lock mtA(&m_mtvectorMSG_FN_CITYWAR_START_WAR);
	m_mtvectorMSG_FN_CITYWAR_START_WAR.push_back(*i_pCityWarStart);	
	return TRUE;
}
BOOL CNPCMapChannel::NPCOnCityWarEnd(MSG_FN_CITYWAR_END_WAR *i_pCityWarEnd)
{
	mt_auto_lock mtA(&m_mtvectorMSG_FN_CITYWAR_END_WAR);
	m_mtvectorMSG_FN_CITYWAR_END_WAR.push_back(*i_pCityWarEnd);	
	return TRUE;
}
BOOL CNPCMapChannel::NPCOnCityWarChangeOccupyInfo(MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO *i_pCityWarChangeOccupyInfo)
{
	mt_auto_lock mtA(&m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO);
	m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.push_back(*i_pCityWarChangeOccupyInfo);	
	return TRUE;
}


void CNPCMapChannel::ProcessNPCOnMonsterSkillEndSkill(MSG_FN_MONSTER_SKILL_END_SKILL * i_pEndSkill)
{
	CNPCMonster * ptmNMonster = GetNPCMonster(i_pEndSkill->MonsterIndex);
	if(NULL == ptmNMonster || ptmNMonster->m_enMonsterState == MS_NULL){		return;}

// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//	if(FALSE == COMPARE_BODYCON_BIT(ptmNMonster->BodyCondition, BODYCON_MON_ATTACK6_MASK))
	if(FALSE == COMPARE_BODYCON_BIT(ptmNMonster->BodyCondition, BODYCON_MON_CONTROLSKILL_MASK))
	{
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// BodyConditio Change and Send
	BodyCond_t tmBodyCon = ptmNMonster->BodyCondition;
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//	CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK6_MASK);
	CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_PRECONTROLSKILL_MASK);
	ptmNMonster->ChangeBodyCondition(&tmBodyCon);
	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, tmSendBuf);
	pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
	pSeBody->ClientIndex	= ptmNMonster->MonsterIndex;
	pSeBody->BodyCondition	= ptmNMonster->BodyCondition;
	Send2FieldServerW(tmSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
	
	ptmNMonster->m_BeforePosition = ptmNMonster->PositionVector;
	///////////////////////////////////////////////////////////////////////////////
	// Monster PositionVector and TargetVector Update
	ptmNMonster->PositionVector = A2DX(i_pEndSkill->PositionVector);
	ptmNMonster->SetTargetVector(&A2DX(i_pEndSkill->TargetVector));
	ptmNMonster->SetMoveTargetVector(&A2DX(i_pEndSkill->TargetVector));
	
	///////////////////////////////////////////////////////////////////////////////
	// Move State Change
	ptmNMonster->SetMoveState(MSS_NORMAL);
	
	///////////////////////////////////////////////////////////////////////////////
	// �̵� ��ǥ Block ó��
	UpdateBlockPosition(ptmNMonster->m_BeforePosition.x, ptmNMonster->m_BeforePosition.z,
		ptmNMonster->PositionVector.x, ptmNMonster->PositionVector.z, ptmNMonster->MonsterIndex);
	
	///////////////////////////////////////////////////////////////////////////////
	// Send EndSkill
	INIT_MSG(MSG_FN_MONSTER_SKILL_END_SKILL, T_FN_MONSTER_SKILL_END_SKILL, pSeSkill, tmSendBuf);
	pSeSkill->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
	pSeSkill->MonsterIndex	= ptmNMonster->MonsterIndex;
	pSeSkill->PositionVector= ptmNMonster->PositionVector;
	pSeSkill->TargetVector	= ptmNMonster->TargetVector*1000.0f;
	Send2FieldServerW(tmSendBuf, MSG_SIZE(MSG_FN_MONSTER_SKILL_END_SKILL));
}

void CNPCMapChannel::_UpdateAttackedItemInfo(CNPCMonster *i_pNMonster, BYTE *i_pSendBuf)
{
	if(i_pNMonster->m_mtvectorAttackedItemInfo.empty() == false)
	{	// ���Ͱ� �ȼ� �����۵ Ÿ���� �޾Ҵ�

		i_pNMonster->LockVectorAttackedItemInfo();
		AttackedItemInfo	*pAItemInfo;
		float				fSpeedPenalty = 0.0f;
		mtvectorAttackedItemInfo::iterator itr(i_pNMonster->m_mtvectorAttackedItemInfo.begin());
		while(itr != i_pNMonster->m_mtvectorAttackedItemInfo.end())
		{
			pAItemInfo = &*itr;
			if(i_pNMonster->m_dwCurrentTick > pAItemInfo->dwExpireTick)
			{
				if(ITEMKIND_FIXER == pAItemInfo->pAttackITEM->Kind)
				{
					//////////////////////////////////////////////////////////
					// �ȼ� �������� ����� Field Server�� �������ش�
					INIT_MSG(MSG_FN_BATTLE_ATTACK_HIDE_ITEM_W_KIND, T_FN_BATTLE_ATTACK_HIDE_ITEM_W_KIND, pSExplodeItem, i_pSendBuf);
					pSExplodeItem->ChannelIndex			= m_MapChannelIndex.ChannelIndex;
					pSExplodeItem->ItemKind				= pAItemInfo->pAttackITEM->Kind;
					pSExplodeItem->TargetIndex			= i_pNMonster->MonsterIndex;
					pSExplodeItem->TargetItemFieldIndex = pAItemInfo->AttackedItemIndex;
					Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_HIDE_ITEM_W_KIND));
				}
				itr = i_pNMonster->m_mtvectorAttackedItemInfo.erase(itr);

				continue;
			}

			if(ITEMKIND_FIXER == pAItemInfo->pAttackITEM->Kind)
			{
// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
// 				if(DES_TRANSPORT == pAItemInfo->pAttackITEM->DestParameter1)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue1;
// 				}
// 				if(DES_TRANSPORT == pAItemInfo->pAttackITEM->DestParameter2)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue2;
// 				}
// 				if(DES_TRANSPORT == pAItemInfo->pAttackITEM->DestParameter3)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue3;
// 				}
// 				if(DES_TRANSPORT == pAItemInfo->pAttackITEM->DestParameter4)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue4;
// 				}
				if(pAItemInfo->pAttackITEM->IsExistDesParam(DES_TRANSPORT))
				{
					fSpeedPenalty += pAItemInfo->pAttackITEM->GetParameterValue(DES_TRANSPORT);
				}
			}
			else if(IS_SKILL_ITEM(pAItemInfo->pAttackITEM->Kind))
			{
// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
// 				if(DES_SKILL_SLOWMOVING == pAItemInfo->pAttackITEM->DestParameter1)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue1;
// 				}
// 				if(DES_SKILL_SLOWMOVING == pAItemInfo->pAttackITEM->DestParameter2)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue2;
// 				}
// 				if(DES_SKILL_SLOWMOVING == pAItemInfo->pAttackITEM->DestParameter3)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue3;
// 				}
// 				if(DES_SKILL_SLOWMOVING == pAItemInfo->pAttackITEM->DestParameter4)
// 				{
// 					fSpeedPenalty += pAItemInfo->pAttackITEM->ParameterValue4;
// 				}
				if(pAItemInfo->pAttackITEM->IsExistDesParam(DES_SKILL_SLOWMOVING))
				{
					fSpeedPenalty += pAItemInfo->pAttackITEM->GetParameterValue(DES_SKILL_SLOWMOVING);
				}
			}
			
			itr++;			
		}// end_while(itr != i_pNMonster->m_mtvectorAttackedItemInfo.end())

		i_pNMonster->m_usSpeedPercent = (USHORT)(i_pNMonster->m_usSpeedPercent - max(i_pNMonster->m_usSpeedPercent, (USHORT)i_pNMonster->m_usSpeedPercent*fSpeedPenalty)); 
		i_pNMonster->UnlockVectorAttackedItemInfo();
	}// end_if(i_pNMonster->m_mtvectorAttackedItemInfo.empty() == false)
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::_BattleAttackOnMonsterDead(BOOL *i_bDeleteProcess, CNPCMonster * i_pNPCMon)
/// \brief		
/// \author		cmkwon
/// \date		2005-12-17 ~ 2005-12-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::_BattleAttackOnMonsterDead(BOOL *i_bDeleteProcess, CNPCMonster * i_pNPCMon)
{
	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
	SSUMMON_EVENT_MONSTER summonEvMon;
	MEMSET_ZERO(&summonEvMon, sizeof(SSUMMON_EVENT_MONSTER));
	*i_bDeleteProcess		= i_pNPCMon->CheckSummonEventMonsterListAfterDead(&summonEvMon);
	if(summonEvMon.SummonMonsterNum)
	{// 2008-04-16 by cmkwon, �ش� ������ ������ ��ȯ ó�� �Ѵ�.
		this->NPCMonsterAttackSkill(i_pNPCMon, &summonEvMon);
	}

// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - ���� ���� ������
//	*i_bDeleteProcess		= TRUE;
//
// 	MONSTER_INFO *pMonInfo	= i_pNPCMon->MonsterInfoPtr;
// 	int nMaxDelayTick		= 0;
// 	for(int i=0; i < ARRAY_SIZE_MONSTER_ITEM; i++)
// 	{
// 		// 2005-10-28 by cmkwon, ���� �� ��� ������ ���������� üũ
// 		ITEM *pMonItem = pMonInfo->ItemInfo[i].pItemInfo;
// 		if(NULL == pMonItem
// 			|| 0 != pMonItem->Charging					// Charging=0 �� �������� ���� �� ����ϴ� ���� ������
// 			|| DES_SUMMON != pMonItem->DestParameter1)	// ����� ��ȯ �����۸� ��� ����
// 		{
// 			continue;
// 		}
// 
// 		nMaxDelayTick = max(nMaxDelayTick, pMonItem->AttackTime);
// 	}
// 
// 	if(0 >= nMaxDelayTick
// 		|| nMaxDelayTick <= i_pNPCMon->m_dwCurrentTick - i_pNPCMon->m_dwTimeDeath)
// 	{
// 		for(int i=0; i < ARRAY_SIZE_MONSTER_ITEM; i++)
// 		{
// 			// 2005-10-28 by cmkwon, ��� ������ ���������� üũ
// 			ITEM *pMonItem = pMonInfo->ItemInfo[i].pItemInfo;
// 			if(NULL == pMonItem
// 				|| 0 != pMonItem->Charging					// Charging=0 �� �������� ���� �� ����ϴ� ���� ������
// 				|| DES_SUMMON != pMonItem->DestParameter1)	// ����� ��ȯ �����۸� ��� ����
// 			{
// 				continue;
// 			}
// 			// 2005-10-28 by cmkwon, ��� Ȯ�� üũ
// 			int nRand = RAND256();
// 			if(nRand > pMonItem->HitRate)
// 			{
// 				continue;
// 			}
// 
// 			this->NPCMonsterAttackSkill(i_pNPCMon, pMonItem);
// 		}
// 	}
// 	else
// 	{
// 		*i_bDeleteProcess = FALSE;				// 2005-12-17 by cmkwon, ���� �����ϸ� �ȵȴ�
// 	}
}


//////////////////////////////////////////////////////////////////
// 2���� ������ MonsterForm�� ���� ���� ó��
//   - �ϴ� ����� ���¸� MonsterForm�� ��ȭ�� �ִ�
BOOL CNPCMapChannel::_CheckMonsterChangeMonsterForm(CNPCMonster * i_pNMonster)
{
	if(i_pNMonster->MonsterInfoPtr->MonsterForm == FORM_FLYINGandGROUND_RIGHT
		|| i_pNMonster->MonsterInfoPtr->MonsterForm == FORM_FLYINGandGROUND_COPTER)
	{
		i_pNMonster->m_nTimeGapChangeMonsterForm -= (i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeLastMoved);
		if(i_pNMonster->m_nTimeGapChangeMonsterForm < 0)
		{
			i_pNMonster->m_nTimeGapChangeMonsterForm = 10000 + i_pNMonster->m_dwCurrentTick/5000;
			if(i_pNMonster->CurrentMonsterForm != FORM_GROUND_MOVE)
			{
				i_pNMonster->SetCurrentMonsterForm(FORM_GROUND_MOVE);
			}
			else if(i_pNMonster->MonsterInfoPtr->MonsterForm == FORM_FLYINGandGROUND_RIGHT)
			{
				i_pNMonster->SetCurrentMonsterForm(FORM_FLYING_RIGHT);
			}
			else if(i_pNMonster->MonsterInfoPtr->MonsterForm == FORM_FLYINGandGROUND_COPTER)
			{
				i_pNMonster->SetCurrentMonsterForm(FORM_FLYING_COPTER);
			}
			i_pNMonster->SetMonsterMoveInfo();
			
			BodyCond_t tmBody = 0;
			if(FORM_GROUND_MOVE == i_pNMonster->CurrentMonsterForm)
			{
				SET_BODYCON_BIT(tmBody, BODYCON_LANDED_MASK);
			}
			else
			{
				SET_BODYCON_BIT(tmBody, BODYCON_FLY_MASK|BODYCON_BOOSTER1_MASK);
			}
			i_pNMonster->ChangeBodyCondition(&tmBody);

			INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, tmSenBuf);
			pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
			pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
			pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
			Send2FieldServerW(tmSenBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
			return TRUE;
		}
	}

	return FALSE;
}

D3DXVECTOR3 CNPCMapChannel::GetFrontPosition(CNPCMonster * i_pNPCMon)
{
	return i_pNPCMon->PositionVector + i_pNPCMon->m_MoveTargetVector * m_pNPCMapProject->m_fFrontPositionDistance;
}


void CNPCMapChannel::UpdateMonsterPositionHandler(CNPCMonster *i_pNMonster
												  , BYTE *i_pSendBuf
												  , vector<ClientIndex_t> *i_pvecClientIndex
												  , BOOL i_bNotMove)
{
	if(i_bNotMove)
	{
		SendMonsterMove2FieldServer(i_pNMonster, i_pSendBuf);
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���Ͱ� ���ݹ��� �������� ó��
	_UpdateAttackedItemInfo(i_pNMonster, i_pSendBuf);
	
	///////////////////////////////////////////////////////////////////////////////
	// ������ CurrentSpeed�� Up or Down�� Update �Ѵ�
	i_pNMonster->UpdateCurrentSpeed();

	///////////////////////////////////////////////////////////////////////////////
	// ���Ͱ� ��ų�� ������̴�
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//	if(COMPARE_BODYCON_BIT(i_pNMonster->BodyCondition, BODYCON_MON_ATTACK6_MASK)
	if(COMPARE_BODYCON_BIT(i_pNMonster->BodyCondition, BODYCON_MON_CONTROLSKILL_MASK)
		&& i_pNMonster->MonsterInfoPtr->ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo)
	{
		i_pNMonster->m_dwTimeLastMoved	= i_pNMonster->m_dwCurrentTick;
		
		if(i_pNMonster->m_dwCurrentTick - i_pNMonster->m_ArrLastReattackTime[ARRAY_INDEX_MONSTER_SKILL_ITEM] > i_pNMonster->MonsterInfoPtr->ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo->Time)
		{
			///////////////////////////////////////////////////////////////////////////////
			// BodyConditio Change and Send
			BodyCond_t tmBodyCon = i_pNMonster->BodyCondition;
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//			CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK6_MASK);
			CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_PRECONTROLSKILL_MASK);
			i_pNMonster->ChangeBodyCondition(&tmBodyCon);			
			INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, i_pSendBuf);
			pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
			pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
			pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
			Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));

			///////////////////////////////////////////////////////////////////////////////
			// Move State Change
			i_pNMonster->SetMoveState(MSS_NORMAL);

			///////////////////////////////////////////////////////////////////////////////
			// Send EndSkill
			INIT_MSG(MSG_FN_MONSTER_SKILL_END_SKILL, T_FN_MONSTER_SKILL_END_SKILL, pSeSkill, i_pSendBuf);
			pSeSkill->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
			pSeSkill->MonsterIndex	= i_pNMonster->MonsterIndex;
			pSeSkill->PositionVector= i_pNMonster->PositionVector;
			pSeSkill->TargetVector	= i_pNMonster->TargetVector*1000.0f;
			Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_SKILL_END_SKILL));
		}
		
		// �̵��� ��ǥ�� Field Server�� �����Ѵ�.
		SendMonsterMove2FieldServer(i_pNMonster, i_pSendBuf);
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// Ÿ���� ���� �Ǿ� �ִ� ���� ó��
	if(0 != i_pNMonster->m_nTargetIndex
		&& NULL != i_pNMonster->m_pUsingMonsterItem)	// 2007-07-20 by cmkwon, Ÿ���� ������ ���� ������ �ȵǾ� �ִ� ����
	{
		_UpdateMonsterPositionHandlerAttack(i_pNMonster, i_pSendBuf, i_pvecClientIndex);
		return;
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// Ÿ���� ���� �Ǿ� ���� ���� ���� �̵�	
	float fMoveRate					= min(2.0f, (float)((i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeLastMoved)/MONSTER_UPDATE_MOVE_TERM_TICK));
	i_pNMonster->m_dwTimeLastMoved	= i_pNMonster->m_dwCurrentTick;
	i_pNMonster->m_BeforePosition	= i_pNMonster->PositionVector;
	

	//////////////////////////////////////////////////////////////////
	// 2���� ������ MonsterForm�� ���� ���� ó��, ����� �� ���ݽÿ��� Change�� �Ͼ��.		
	this->_CheckMonsterChangeMonsterForm(i_pNMonster);

	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - �Ʒ��� ���������� ��� �����Ѵ�. �ذ� ���� ����	
	//////////////////////////////////////////////////////////////////
	// ������ ĳ���� �־ ������ �̵� ������ Field Server�� �����ؾ� �ϴ���
//	BOOL bSendMoveFlag = NPCCharacterExistInRange(&i_pNMonster->PositionVector, i_pNMonster->SendMoveRange);
	BOOL bSendMoveFlag = TRUE;
	if(FALSE == g_pNPCGlobal->GetIsArenaServer()) 
	{
		bSendMoveFlag = NPCCharacterExistInRange(&i_pNMonster->PositionVector, i_pNMonster->SendMoveRange);
	}
		
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ذ� ���� ����
// 	//////////////////////////////////////////////////////////////////
// 	// ���� ���� ���Ͱ� �������� Ÿ���� �˻��Ѵ�.
// 	if(i_pNMonster->CheckEnableSearchTarget()		// 2007-06-26 by cmkwon, ���� Ÿ�� �˻� �ð� ���� - �˻� ���� ���� Ȯ��
// 		&& bSendMoveFlag
// 		&& (i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATATTACK
// 		|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATTACK_OUTPOST_PROTECTOR	// 2007-08-23 by cmkwon, BELL_ATATTACK�� �����ϰ� ����
// 		|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_TAGETATATTACK
// 		|| IS_INFLWAR_MONSTER(i_pNMonster->MonsterInfoPtr->Belligerence)		// 2006-11-20 by cmkwon
// 		|| (i_pNMonster->MonsterInfoPtr->Belligerence == BELL_RETREAT && i_pNMonster->CurrentHP < i_pNMonster->MonsterInfoPtr->MonsterHP*3/10))
// 		)
// 	{
// 		if(NPCGetAdjacentCharacterIndexes(&i_pNMonster->PositionVector, i_pNMonster->MonsterInfoPtr->AttackRange, i_pNMonster->MonsterInfoPtr->AttackRange*2, i_pvecClientIndex))
// 		{
// 			i_pNMonster->SelectTargetIndex(NPCGetTargetwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 		}
// 	}

// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - �Ʒ��� ���� ����
// 	//////////////////////////////////////////////////////////////////
// 	// ���� ���� ���Ͱ� �������� Ÿ���� �˻��Ѵ�.
// 	if(i_pNMonster->CheckEnableSearchTarget()) {	// 2007-06-26 by cmkwon, ���� Ÿ�� �˻� �ð� ���� - �˻� ���� ���� Ȯ��
// 		if(BELL_INFINITY_DEFENSE_MONSTER == i_pNMonster->MonsterInfoPtr->Belligerence) {
// 			// BELL_INFINITY_ATTACK_MONSTER ���͸� ����
// 			if(0 != NPCGetAdjacentMonsterIndexesByBell(&i_pNMonster->PositionVector, i_pNMonster->MonsterInfoPtr->AttackRange, i_pNMonster->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_ATTACK_MONSTER, i_pvecClientIndex)) {
// 				i_pNMonster->SelectTargetIndex(NPCGetTargetMonsterwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 			}
// 		}
// 		else if (BELL_INFINITY_ATTACK_MONSTER == i_pNMonster->MonsterInfoPtr->Belligerence) {
// 			// �ƹ��� �ָ� �־ ���ߵȴ�!!, �켱 MonsterTarget�� ���͸� ����, ������ BELL_INFINITY_DEFENSE_MONSTER ���� ����, ������ ���� ����
// 			if(0 != this->GetMonsterIndexesByTargetMonsterNum(i_pNMonster->MonsterInfoPtr->MonsterTarget, i_pvecClientIndex)) {
// 				i_pNMonster->SelectTargetIndex(NPCGetTargetMonsterwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 			}
// 			else if(0 != this->GetMonsterIndexesByBell(BELL_INFINITY_DEFENSE_MONSTER, i_pvecClientIndex)) {
// 				i_pNMonster->SelectTargetIndex(NPCGetTargetMonsterwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 			}
// 			else if(TRUE == i_pNMonster->MonsterInfoPtr->ChangeTarget
// 					&& NPCGetAdjacentCharacterIndexes(&i_pNMonster->PositionVector, i_pNMonster->MonsterInfoPtr->AttackRange, i_pNMonster->MonsterInfoPtr->AttackRange*2, i_pvecClientIndex, i_pNMonster->MonsterInfoPtr->Belligerence)) {
// 				i_pNMonster->SelectTargetIndex(NPCGetTargetwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 			}
// 		}
// 		else if (bSendMoveFlag
// 			&& (i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATATTACK
// 			|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATTACK_OUTPOST_PROTECTOR	// 2007-08-23 by cmkwon, BELL_ATATTACK�� �����ϰ� ����
// 			|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_TAGETATATTACK
// 			|| IS_INFLWAR_MONSTER(i_pNMonster->MonsterInfoPtr->Belligerence)		// 2006-11-20 by cmkwon
// 			|| (i_pNMonster->MonsterInfoPtr->Belligerence == BELL_RETREAT && i_pNMonster->CurrentHP < i_pNMonster->MonsterInfoPtr->MonsterHP*3/10))
// 			) {
// 			if(NPCGetAdjacentCharacterIndexes(&i_pNMonster->PositionVector, i_pNMonster->MonsterInfoPtr->AttackRange, i_pNMonster->MonsterInfoPtr->AttackRange*2, i_pvecClientIndex, i_pNMonster->MonsterInfoPtr->Belligerence)) {
// 				i_pNMonster->SelectTargetIndex(NPCGetTargetwithAttackObj(i_pNMonster->MonsterInfoPtr->AttackObject, i_pNMonster, *i_pvecClientIndex));
// 			}
// 		}
// 	}
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
	if(bSendMoveFlag
		&& i_pNMonster->CheckEnableSearchTarget())
	{
		if(i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATATTACK
			|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_ATTACK_OUTPOST_PROTECTOR
			|| i_pNMonster->MonsterInfoPtr->Belligerence == BELL_TAGETATATTACK
			|| IS_INFLWAR_MONSTER(i_pNMonster->MonsterInfoPtr->Belligerence)
 			|| (i_pNMonster->MonsterInfoPtr->Belligerence == BELL_RETREAT && i_pNMonster->CurrentHP < i_pNMonster->MonsterInfoPtr->MonsterHP*3/10)
			|| BELL_INFINITY_ATTACK_MONSTER == i_pNMonster->MonsterInfoPtr->Belligerence
			|| BELL_INFINITY_DEFENSE_MONSTER == i_pNMonster->MonsterInfoPtr->Belligerence)

		{
			ClientIndex_t tarIdx = this->SearchTarget(i_pNMonster);
			if(0 != tarIdx)
			{
				i_pNMonster->SelectTargetIndex(tarIdx);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� ĳ���߿� Ÿ���� �����ߴ�
	// �̵��� ���� �ʰ� �ٷ� �����Ѵ�.
	if(i_pNMonster->m_nTargetIndex != 0)
	{
		SendMonsterMove2FieldServer(i_pNMonster, i_pSendBuf);
		return;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 1. ��Ƽ���̸� ��Ƽ���� �������� ��ġ�� ������, ����� ����ݽø� ��Ƽ�� ������
	// 2. ���̿��� ��� ����
	if(i_pNMonster->m_nPartyManagerIndex != 0
		&& i_pNMonster->m_nPartyManagerIndex != i_pNMonster->MonsterIndex)
	{

		NPCSetPartyPosition(i_pNMonster);
	}
	else
	{		
		///////////////////////////////////////////////////////////////////////////////
		// ���� ��ġ�κ��� �̵� ������ üũ, �浹 �����̸� �׳� ���ϵȴ�
		if(TRUE == i_pNMonster->CheckMoveRange())
		{
			D3DXVECTOR3 tmVec3Tar(i_pNMonster->m_CreatedPosition - i_pNMonster->PositionVector);
			D3DXVec3Normalize(&tmVec3Tar, &tmVec3Tar);

			///////////////////////////////////////////////////////////////////////////////
			// 1. ���� ��ǥ���� �浹�� �߻��ϸ�
			//		- MoveTargetVector�� ���� �ø���
			// 2. ���� ��ǥ���� �浹�� �߻����� ������
			//		- tmVec3Tar�� �׳� �����
			if(TRUE == this->CheckImpactStraightLineMapAndObjects(&i_pNMonster->PositionVector, &i_pNMonster->m_CreatedPosition
				, DEFAULT_OBJECT_MONSTER_OBJECT+i_pNMonster->MonsterInfoPtr->MonsterUnitKind, FALSE))
			{
				GNPCRotateTargetVectorVertical(&tmVec3Tar, &tmVec3Tar, MSD_UP_10, 20);
			}
			i_pNMonster->SetEnforceTargetVector(&tmVec3Tar, i_pNMonster->GetSpeed(), MSS_RANGE_DISTANCE_IMPACT);
		}

		///////////////////////////////////////////////////////////////////////////////
		// 1. ���� ��ġ�� �̵� ������ üũ �� MoveState�� ��ȭ ������ 
		//		MoveTargetVector �������� ���� ������ �ʰ��� �浹�� �߻��Ұ��ΰ��� üũ
		D3DXVECTOR3 tmVec3(0, 0, 0);
		if(TRUE == CheckImpactFrontPositionMap(i_pNMonster, &tmVec3))
		{
			i_pNMonster->SetEnforceTargetVector(&tmVec3, i_pNMonster->GetSpeed(), MSS_MAP_IMPACT);
		}
		
		///////////////////////////////////////////////////////////////////////////////
		// �浹 ���¿��� Ÿ�� ������ ���� ó��, �浹 ���°� �ƴϸ� �׳� ���ϵȴ�
		if(MSS_NORMAL != i_pNMonster->m_enMoveState)
		{
			i_pNMonster->UpdateEnforceTargetVector();
		}		
		
		///////////////////////////////////////////////////////////////////////////////
		// ���� ���� �̵��� ó���ȴ�.
		i_pNMonster->UpdatePositionVector(fMoveRate);

		///////////////////////////////////////////////////////////////////////////////
		// ������ TargetVector�� ó���Ѵ�
		//		1. ������
		D3DXVECTOR3 tmVec3Tar(i_pNMonster->m_MoveTargetVector);
		if(FORM_GROUND_MOVE == i_pNMonster->CurrentMonsterForm)
		{
			if(i_pNMonster->PositionVector == i_pNMonster->m_BeforePosition)
			{
				tmVec3Tar = i_pNMonster->m_MoveTargetVector;
			}
			else
			{
				tmVec3Tar = i_pNMonster->PositionVector - i_pNMonster->m_BeforePosition;
			}			
		}
		i_pNMonster->SetTargetVector(&tmVec3Tar);
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� ��ǥ�� ���̸� üũ�Ѵ�.
	//		- ���� ���� ���̸� ����(������, �����̵� ���� ���� ����)
	//		- ������ ���� PositionVector�� ��ȿ�� üũ
	CheckMonsterPosition(i_pNMonster, fMoveRate);
	
	///////////////////////////////////////////////////////////////////////////////
	// �̵� ��ǥ Block ó��
	UpdateBlockPosition(i_pNMonster->m_BeforePosition.x, i_pNMonster->m_BeforePosition.z,
		i_pNMonster->PositionVector.x, i_pNMonster->PositionVector.z, i_pNMonster->MonsterIndex);

	///////////////////////////////////////////////////////////////////////////////
	// ���� MoveInfo ���� Update
	i_pNMonster->UpdateMoveInfoAllCurrentCount();
	
	if(bSendMoveFlag)
	{
		switch(i_pNMonster->m_enMoveState)
		{
		case MSS_QUICK_TURN_GENERAL:
		case MSS_QUICK_TURN_SKILL:
			{
				if(FALSE == COMPARE_BODYCON_BIT(i_pNMonster->BodyCondition, BODYCON_BOOSTER3_MASK))
				{
					BodyCond_t tmBody = i_pNMonster->BodyCondition;
					SET_BODYCON_BIT(tmBody, BODYCON_BOOSTER3_MASK);
					i_pNMonster->ChangeBodyCondition(&tmBody);
					
					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, i_pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
					Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
				}
			}
			break;
		default:
			{
				if(FORM_GROUND_MOVE != i_pNMonster->CurrentMonsterForm
					&& FALSE == COMPARE_BODYCON_BIT(i_pNMonster->BodyCondition, BODYCON_BOOSTER1_MASK))
				{
					BodyCond_t tmBody = i_pNMonster->BodyCondition;
					SET_BODYCON_BIT(tmBody, BODYCON_BOOSTER1_MASK);
					i_pNMonster->ChangeBodyCondition(&tmBody);

					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, i_pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
					Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
				}
			}
		}
		
		SendMonsterMove2FieldServer(i_pNMonster, i_pSendBuf);
	}

}	// MoveMonsterHander_end()

void CNPCMapChannel::_UpdateMonsterPositionHandlerAttack(CNPCMonster *i_pNMonster
														, BYTE *i_pSendBuf
														, vector<ClientIndex_t> *i_pvecClientIndex)
{
	// 2013-08-05 by jhseol, NPC���� ũ���� ����� �α�
	if (NULL == i_pNMonster || NULL == i_pSendBuf)
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE,"[DEBUG] CNPCMapChannel::_UpdateMonsterPositionHandlerAttack, i_pNMonster(%#010x), i_pSendBuf(%#010x) is NULL\r\n", i_pNMonster, i_pSendBuf);
	}
	// end 2013-08-05 by jhseol, NPC���� ũ���� ����� �α�
	float fMoveRate					= min(2.0f, (float)((i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeLastMoved)/MONSTER_UPDATE_MOVE_TERM_TICK));
	i_pNMonster->m_dwTimeLastMoved	= i_pNMonster->m_dwCurrentTick;
	i_pNMonster->m_BeforePosition	= i_pNMonster->PositionVector;

	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ÿ�� �ɸ��Ϳ� ���� ��ǥ���� �������� ��� - �ذ� ���� ����
// 	///////////////////////////////////////////////////////////////////////////////
// 	// Ÿ���� �����϶� ó��, ���߿� ����
// 	if(i_pNMonster->m_nTargetIndex >= MONSTER_CLIENT_INDEX_START_NUM)
// 	{
// 		// 2005-04-25 by cmkwon
// 		//		ASSERT_NEVER_GET_HERE();
// 		return;
// 	}
// 	
// 	///////////////////////////////////////////////////////////////////////////////
// 	// Ÿ���� ĳ�����϶� ó��
// 	///////////////////////////////////////////////////////////////////////////////
// 	
// 	///////////////////////////////////////////////////////////////////////////////
// 	// ĳ���Ͱ� ��ȿ���� üũ �Ѵ�.
// 	CLIENT_INFO	*pClientInfo = GetClientInfo(i_pNMonster->m_nTargetIndex);
// 	if(NULL == pClientInfo 
// 		|| FALSE == pClientInfo->IsEnbleTargeted(i_pNMonster->MonsterInfoPtr->Belligerence, COMPARE_MPOPTION_BIT(i_pNMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE), TRUE))
// 	{
// 		i_pNMonster->DeleteAttackedInfowithIndex();
// 		return;
// 	}
// 	
// 	D3DXVECTOR3			Vec3TarM2C;					// (���� --> ĳ����)���� ���⺤��
// 	D3DXVECTOR3			Vec3TarM2CPlane;			// (���� --> ĳ����)���� ��� ���� ����
// 	float				fDistanceM2CPlane;			// (���Ϳ� ĳ����)�� ��� ���� �Ÿ�	
// 	
// 	Vec3TarM2C			= pClientInfo->PositionVector - i_pNMonster->PositionVector;		// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.

// 2010-01-06 by cmkwon, ���� ���ݽ� Ÿ�� ���� ���� üũ �߰�(Ÿ�ٺ���) - �Ʒ��� ���� ����
// 	D3DXVECTOR3	TargetUnitPositionVector;
// 	D3DXVECTOR3	TargetUnitTargetVector;
// 	ClientIndex_t curTargetIdx	= i_pNMonster->GetTargetIndex();
// 	if(IS_MONSTER_CLIENT_INDEX(curTargetIdx)) {
// 		// ���� üũ
// 		CNPCMonster * pTargetMonster = GetNPCMonster(curTargetIdx);
// 		if(NULL == pTargetMonster || FALSE == pTargetMonster->IsValidMonster()) {	
// 			i_pNMonster->DeleteAttackedInfowithIndex();
// 			return;
// 		}
// 		TargetUnitPositionVector = pTargetMonster->PositionVector;
// 		TargetUnitTargetVector	 = pTargetMonster->TargetVector;
// 	}
// 	else {
// 		///////////////////////////////////////////////////////////////////////////////
// 		// ĳ���Ͱ� ��ȿ���� üũ �Ѵ�.
// 		CLIENT_INFO	*pClientInfo = GetClientInfo(curTargetIdx, &m_MapChannelIndex);
// 		if(NULL == pClientInfo 
// 			|| FALSE == pClientInfo->IsEnbleTargeted(i_pNMonster->MonsterInfoPtr->Belligerence, COMPARE_MPOPTION_BIT(i_pNMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE), TRUE))
// 		{
// 			i_pNMonster->DeleteAttackedInfowithIndex();
// 			return;
// 		}
// 		TargetUnitPositionVector = pClientInfo->PositionVector;
// 		TargetUnitTargetVector	= pClientInfo->TargetVector;
// 	}
// 
// 	D3DXVECTOR3			Vec3TarM2C;					// (���� --> ĳ����)���� ���⺤��
// 	D3DXVECTOR3			Vec3TarM2CPlane;			// (���� --> ĳ����)���� ��� ���� ����
// 	float				fDistanceM2CPlane;			// (���Ϳ� ĳ����)�� ��� ���� �Ÿ�	
// 
// 	Vec3TarM2C			= TargetUnitPositionVector - i_pNMonster->PositionVector;		// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.
// 	Vec3TarM2CPlane		= Vec3TarM2C;
// 	Vec3TarM2CPlane.y	= 0.0f;
// 	fDistanceM2CPlane	= D3DXVec3Length(&Vec3TarM2CPlane);		// ������ ���� ������ ���̸� ���Ѵ�.(���Ϳ� Ÿ�ٰ��� �Ÿ�, ������ �Ÿ��� ���Ѵ�)
// 
// // 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::_UpdateMonsterPositionHandlerAttack#
// // 	if(fDistanceM2CPlane > i_pNMonster->MonsterInfoPtr->Range
// // 		&& MONSTER_TARGETTYPE_TUTORIAL != i_pNMonster->m_byMonsterTargetType)	// 2007-07-19 by cmkwon, Ʃ�丮�� ���� ���� - Ʃ�丮����ʹ� �Ÿ� üũ���� �ʴ´�
// // 	{
// // 		if(i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwSetTargetIndexLastTick > MONSTER_MIN_SET_TARGET_INDEX_TIME
// // 			|| i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeMonsterLastAttack > 2*MONSTER_MIN_SET_TARGET_INDEX_TIME)
// // 		{
// // 			i_pNMonster->DeleteAttackedInfowithIndex();
// // 			return;
// // 		}
// // 	}
// 	///////////////////////////////////////////////////////////////////////////////	
// 	// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - CNPCMapChannel::_UpdateMonsterPositionHandlerAttack#
// 	if(fDistanceM2CPlane > i_pNMonster->MonsterInfoPtr->Range
// 		&& MONSTER_TARGETTYPE_TUTORIAL != i_pNMonster->m_byMonsterTargetType)	// 2007-07-19 by cmkwon, Ʃ�丮�� ���� ���� - Ʃ�丮����ʹ� �Ÿ� üũ���� �ʴ´�
// 	{
// 		int nElapsedTickAfterAttack = (int)((INT64)i_pNMonster->m_dwCurrentTick - (INT64)i_pNMonster->m_dwTimeMonsterLastAttack);
// 		if(TICK_MONSTER_DELETE_TARGET_TERM < nElapsedTickAfterAttack)
// 		{
// 			i_pNMonster->DeleteAttackedInfowithIndex();
// 			return;
// 		}
// 	}
	///////////////////////////////////////////////////////////////////////////////
	// 2010-01-06 by cmkwon, ���� ���ݽ� Ÿ�� ���� ���� üũ �߰�(Ÿ�ٺ���) - 
	BOOL bIsTargetCharacter = FALSE;
	CLIENT_INFO *pTargetCli	= NULL;
	CNPCMonster *pTargetMon	= NULL;
	
	if(FALSE == GetTargetObject(&bIsTargetCharacter, &pTargetCli, &pTargetMon, i_pNMonster))
	{// 2010-01-06 by cmkwon, Ÿ���� ��ȿ���� �ʴ�
		
		i_pNMonster->DeleteAttackedInfowithIndex();
		return;
	}
	D3DXVECTOR3	TargetUnitPositionVector;
	D3DXVECTOR3	TargetUnitTargetVector;
	if(bIsTargetCharacter)
	{
		TargetUnitPositionVector	= pTargetCli->PositionVector;
		TargetUnitTargetVector		= pTargetCli->TargetVector;
	}
	else
	{
		// start 2011-04-05 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		//////////
		// ���� //
		// TargetUnitPositionVector	= pTargetMon->PositionVector;

		//////////
		// ���� //
		if( pTargetMon->IsMultiTargetMonster() == TRUE )
		{
			int iMTCount = 0;
			TargetUnitPositionVector	= pTargetMon->GetNearMultiTarget(i_pNMonster->PositionVector, &iMTCount);
		}
		else
		{
			TargetUnitPositionVector	= pTargetMon->PositionVector;
		}
		// end 2011-04-05 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

		TargetUnitTargetVector		= pTargetMon->TargetVector;
	}
	D3DXVECTOR3	Vec3TarM2C = i_pNMonster->PositionVector - TargetUnitPositionVector;		// (���� --> ĳ����)���� ���⺤��, ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.

	// 2010-02-19 by cmkwon, ���� ���ݰ��� �Ÿ� ���Ŀ��� Ÿ�� �����Ǵ� ���� ���� - CheckValidTarget# �Լ����� FALSE�� ���Ͻ� ó����.
	if(FALSE == this->CheckValidTarget(i_pNMonster))
	{
		return;
	}
	// END - // 2010-01-06 by cmkwon, ���� ���ݽ� Ÿ�� ���� ���� üũ �߰�(Ÿ�ٺ���) - 
	///////////////////////////////////////////////////////////////////////////////
	

	if(i_pNMonster->IsChangeableTarget())
	{
		if(this->ChangeTarget(i_pNMonster))
		{// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - Ÿ���� ����Ǿ��� ���� return ó��
			return;
		}
	}
	
	D3DXVECTOR3			tmVec3;
	float				fDistanceM2C;

	///////////////////////////////////////////////////////////////////////////////
	// 1. MoveTargetVector �������� ���� ������ �ʰ��� �浹�� �߻��Ұ��ΰ��� üũ
	tmVec3 = D3DXVECTOR3(0, 0, 0);
	if(TRUE == CheckImpactFrontPositionMap(i_pNMonster, &tmVec3))
	{
		i_pNMonster->SetEnforceTargetVector(&tmVec3, i_pNMonster->GetSpeed(), MSS_MAP_IMPACT);		
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// 1. ���� Ÿ�� ���� �̵� �����϶� Ÿ�� ������ ���� ó���� �̵� ó��
	//		- 
	// 2. ���� Ÿ�� ���� �̵� ���� �ƴҶ� �̵� ó��
	//		- FORM_FLYING_RIGHT�� TargetVector�� Ÿ���� ���ϸ� MoveTargetVector�� TargetVector�� �Ҵ� �ȴ�
	//		- FORM_FLYING_COPTER�� TargetVector�� Ÿ���� ���ϸ� MoveTargetVector���� ���� ���۵ȴ�.	
	if(MSS_NORMAL != i_pNMonster->m_enMoveState)
	{
		i_pNMonster->m_MoveInfo.FBDirect		= MSD_FRONT;
		i_pNMonster->m_MoveInfo.FBCurrentCount	= 0;
		i_pNMonster->UpdateEnforceTargetVector();
		
		///////////////////////////////////////////////////////////////////////////////
		// ���� ���� �̵��� ó���ȴ�.
		i_pNMonster->UpdatePositionVector(fMoveRate);
		
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ÿ�� �ɸ��Ϳ� ���� ��ǥ���� �������� ��� - �ذ� ���� ����
//		Vec3TarM2C = pClientInfo->PositionVector - i_pNMonster->PositionVector;		// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.
		Vec3TarM2C = TargetUnitPositionVector - i_pNMonster->PositionVector;	// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.
		fDistanceM2C = D3DXVec3Length(&Vec3TarM2C);

		///////////////////////////////////////////////////////////////////////////////
		// ������ TargetVector�� ó���Ѵ�
		D3DXVECTOR3 tmVec3Tar(i_pNMonster->m_MoveTargetVector);
		if(FORM_GROUND_MOVE == i_pNMonster->CurrentMonsterForm)
		{
			if(i_pNMonster->PositionVector == i_pNMonster->m_BeforePosition)
			{
				tmVec3Tar = i_pNMonster->m_MoveTargetVector;
			}
			else
			{
				tmVec3Tar = i_pNMonster->PositionVector - i_pNMonster->m_BeforePosition;
			}
		}
		i_pNMonster->SetTargetVector(&tmVec3Tar);

		switch(i_pNMonster->m_enMoveState)
		{
		case MSS_QUICK_TURN_GENERAL:
		case MSS_QUICK_TURN_SKILL:
			{
				if(fDistanceM2C >= i_pNMonster->MonsterInfoPtr->Range*0.8f)
				{
					i_pNMonster->m_MoveInfo.FBDirect = MSD_FRONT;
					i_pNMonster->m_MoveInfo.FBCurrentCount = 0;
					i_pNMonster->SetMoveState(MSS_NORMAL);
				}
			}
			break;
		}
	}
	else
	{
		///////////////////////////////////////////////////////////////////////////////
		// MoveTargetVector�� ���� ���� ���� �̵��� ó���ȴ�.
		i_pNMonster->UpdatePositionVector(fMoveRate);
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ÿ�� �ɸ��Ϳ� ���� ��ǥ���� �������� ��� - �ذ� ���� ����
//		Vec3TarM2C = pClientInfo->PositionVector - i_pNMonster->PositionVector;			// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.
		Vec3TarM2C = TargetUnitPositionVector - i_pNMonster->PositionVector;		// ���Ϳ��� Ÿ�������� ���͸� ���Ѵ�.
		fDistanceM2C = D3DXVec3Length(&Vec3TarM2C);

		D3DXVECTOR3			UnitVec3TarM2C;				// (���� --> ĳ����)���� ���� ���� ����
		D3DXVec3Normalize(&UnitVec3TarM2C, &Vec3TarM2C);

		///////////////////////////////////////////////////////////////////////////////
		// ������ TargetVector�� Ÿ���� ���ϵ��� �Ѵ�.
		D3DXMATRIX tmMatrix;
		tmVec3 = i_pNMonster->TargetVector;		
		
		if(ORBIT_BODYSLAM == i_pNMonster->m_pUsingMonsterItem->pItemInfo->OrbitType)
		{
			if(i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeMonsterLastAttack > 3*i_pNMonster->m_pUsingMonsterItem->pItemInfo->ReAttacktime)
			{
				tmMatrix = GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, PI/2);
			}
			else
			{
				tmMatrix = GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, 2*i_pNMonster->MonsterInfoPtr->TurnAngle);
			}			
		}
		else if(i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeMonsterLastAttack > 4*i_pNMonster->m_pUsingMonsterItem->pItemInfo->ReAttacktime)
		{
			tmMatrix = GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, PI/2);
		}
		else if(i_pNMonster->m_MoveInfo.MoveCount < 5
			|| fDistanceM2C > i_pNMonster->MonsterInfoPtr->Range*0.7)
		{
			tmMatrix = GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, 2*i_pNMonster->MonsterInfoPtr->TurnAngle);
		}
		else
		{
			tmMatrix = GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, i_pNMonster->MonsterInfoPtr->TurnAngle);
		}
		i_pNMonster->SetTargetVector(&tmVec3);

		///////////////////////////////////////////////////////////////////////////////
		// ���� MoveTargetVector ó��
		//	1. ������ ����
		//		- ������, �����̵����� �ƴϰ� ������ ó���ô� MoveTargetVector�� Ÿ���� ���ϴ� ��� ���ͷ� �����Ѵ�.
		//	2. �������̸鼭 ������
		//		- ������ ó���ô� MoveTargetVector�� Ÿ���� ���ϵ��� �Ѵ�
		//		- ó���� �ƴϸ� TargetVector�� ȸ���ϴ� �� ��ŭ MoveTargetVector�� ȸ����Ų��.
		//	3. �������̸鼭 ������
		//		- TargetVector�� ���� ���ָ� �ȴ�
		if(FALSE == i_pNMonster->m_MoveInfo.MovableFlag)
		{
			i_pNMonster->SetMoveTargetVector(&i_pNMonster->TargetVector);
		}
		else if(FORM_GROUND_MOVE == i_pNMonster->CurrentMonsterForm)
		{
			if(FALSE == i_pNMonster->m_FlagNPCMonster.MoveTargetVectorSetAttack)
			{
				i_pNMonster->SetNPCMonsterFlagMoveTargetVectorSetAttack(TRUE);
				////////////////////////////////////////////////////////////////////////////////
				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ÿ�� �ɸ��Ϳ� ���� ��ǥ���� �������� ��� - �ذ� ���� ����
//				m_pNPCMapProject->ChangePlaneUnitVec3(&tmVec3, &i_pNMonster->TargetVector, &pClientInfo->TargetVector);
				m_pNPCMapProject->ChangePlaneUnitVec3(&tmVec3, &i_pNMonster->TargetVector, &TargetUnitTargetVector);
				i_pNMonster->SetMoveTargetVector(&tmVec3);
			}
		}
		else if(TRUE == i_pNMonster->m_MoveInfo.FBFlag)
		{
			if(FALSE == i_pNMonster->m_FlagNPCMonster.MoveTargetVectorSetAttack)
			{
				i_pNMonster->SetNPCMonsterFlagMoveTargetVectorSetAttack(TRUE);
				i_pNMonster->SetMoveTargetVector(&i_pNMonster->TargetVector);
			}
			else
			{
				CNPCMapProject::ChangePlaneUnitVec3(&tmVec3, &i_pNMonster->TargetVector, &i_pNMonster->TargetVector);
				float fPinPoint = ACOS(D3DXVec3Dot(&i_pNMonster->TargetVector, &tmVec3));
				if(fPinPoint <= MONSTER_COPTER_MAXTARGET_PINPOINT
// 2005-06-28 by cmkwon
//					|| i_pNMonster->m_dwCurrentTick - i_pNMonster->m_dwTimeMonsterLastAttack > i_pNMonster->m_pUsingMonsterItem->pItemInfo->ReAttacktime*3
					)
				{
					D3DXVec3TransformCoord(&tmVec3, &i_pNMonster->m_MoveTargetVector, &tmMatrix);
					i_pNMonster->SetMoveTargetVector(&tmVec3);
				}
				else
				{
					CNPCMapProject::ChangePlaneUnitVec3(&tmVec3, &UnitVec3TarM2C, &UnitVec3TarM2C);
					GNPCGetMaxTargetVector(&tmVec3, &UnitVec3TarM2C, MONSTER_COPTER_MAXMOVE_PINPOINT);
					i_pNMonster->SetEnforceTargetVector(&tmVec3, i_pNMonster->GetCurrentSpeed(), MSS_QUICK_TURN_GENERAL);
				}
			}
		}
		else
		{
			i_pNMonster->SetMoveTargetVector(&i_pNMonster->TargetVector);
		}

		///////////////////////////////////////////////////////////////////////////////
		// ���ݽ� MoveInfo ó��
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Ÿ�� �ɸ��Ϳ� ���� ��ǥ���� �������� ��� - �ذ� ���� ����
//		i_pNMonster->UpdateMoveInfoAttack(&pClientInfo->PositionVector, &pClientInfo->TargetVector);
		i_pNMonster->UpdateMoveInfoAttack(&TargetUnitPositionVector, &TargetUnitTargetVector);

		//////////////////////////////////////////////////////////////////////////////
		// 1. ��ų�� �ߵ� �Ǿ���
		// 2. QuickTurn�� �ߵ� �Ǿ���
		if(MSS_QUICK_TURN_SKILL == i_pNMonster->m_enMoveState)
		{
			i_pNMonster->m_ArrLastReattackTime[ARRAY_INDEX_MONSTER_SKILL_ITEM] = i_pNMonster->m_dwCurrentTick;
			
			BodyCond_t tmBodyCon = i_pNMonster->BodyCondition;
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//			SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK6_MASK);
			SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PRECONTROLSKILL_MASK);
			i_pNMonster->ChangeBodyCondition(&tmBodyCon);
			
			INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, i_pSendBuf);
			pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
			pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
			pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
			Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
			
			INIT_MSG(MSG_FN_MONSTER_SKILL_USE_SKILL, T_FN_MONSTER_SKILL_USE_SKILL, pSeSkill, i_pSendBuf);
			pSeSkill->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
			pSeSkill->MonsterIndex	= i_pNMonster->MonsterIndex;
			pSeSkill->ClientIndex	= i_pNMonster->m_nTargetIndex;
			pSeSkill->SkillItemNum	= i_pNMonster->MonsterInfoPtr->ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo->ItemNum;
			Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_SKILL_USE_SKILL));
			
//			DBGOUT("	Use Skill Pos(%d, %d, %d)\n"
//				, (int)i_pNMonster->PositionVector.x, (int)i_pNMonster->PositionVector.y
//				, (int)i_pNMonster->PositionVector.z);
		}
		else if(MSS_QUICK_TURN_GENERAL == i_pNMonster->m_enMoveState)
		{
			if(FALSE == COMPARE_BODYCON_BIT(i_pNMonster->BodyCondition, BODYCON_BOOSTER3_MASK))
			{
				BodyCond_t tmBodyCon = i_pNMonster->BodyCondition;
				SET_BODYCON_BIT(tmBodyCon, BODYCON_BOOSTER3_MASK);
				i_pNMonster->ChangeBodyCondition(&tmBodyCon);
				
				INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, i_pSendBuf);
				pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
				pSeBody->ClientIndex	= i_pNMonster->MonsterIndex;
				pSeBody->BodyCondition	= i_pNMonster->BodyCondition;
				Send2FieldServerW(i_pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
			}
		}			
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// ���� ��ǥ�� ���̸� üũ�Ѵ�.
	//		- ���� ���� ���̸� ����(������, �����̵� ���� ���� ����)
	//		- ������ ���� PositionVector�� ��ȿ�� üũ
	CheckMonsterPosition(i_pNMonster, fMoveRate);
	
	///////////////////////////////////////////////////////////////////////////////
	// �̵� ��ǥ Block ó��
	UpdateBlockPosition(i_pNMonster->m_BeforePosition.x, i_pNMonster->m_BeforePosition.z,
		i_pNMonster->PositionVector.x, i_pNMonster->PositionVector.z, i_pNMonster->MonsterIndex);

	///////////////////////////////////////////////////////////////////////////////
	// ���� MoveInfo ���� Update
	i_pNMonster->UpdateMoveInfoAllCurrentCount();
	
	SendMonsterMove2FieldServer(i_pNMonster, i_pSendBuf);
}


void CNPCMapChannel::AttackMonster2Unit(CNPCMonster *i_pnMonster, BYTE *pSendBuf)
{
	if(i_pnMonster->CheckDeadBodyCondition())
	{
		return;
	}

	if (i_pnMonster->m_nTargetIndex < MONSTER_CLIENT_INDEX_START_NUM)
	{
		AttackMonster2Character(i_pnMonster, pSendBuf);
	}
	else
	{
		AttackMonster2Monster(i_pnMonster, pSendBuf);
	}
}

void CNPCMapChannel::AttackMonster2Character(CNPCMonster *i_pnMonster, BYTE *pSendBuf)
{
	CLIENT_INFO			* ptmClientInfo = GetClientInfo(i_pnMonster->m_nTargetIndex);
	if(NULL == ptmClientInfo || ptmClientInfo->ClientState != CS_GAMESTARTED)
	{	// Ÿ����  ��ȿ���� ����
		// ��ȿ���� ���� Ÿ���� �����ϰ� ���ο� Ÿ������ �����Ѵ�.
		// LastAttackTime�� �ʱ�ȭ ���� �ʴ´�, 

		i_pnMonster->DeleteAttackedInfowithIndex();
		return;
	}

	if(NULL == i_pnMonster->m_pUsingMonsterItem
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
//		|| COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACK6_MASK))
		|| COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_CONTROLSKILL_MASK))
	{
		return;
	}

	if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACKALL_MASK)
		&& FALSE == CheckMonsterSelectedItem(i_pnMonster))
	{
		i_pnMonster->SelectUsingMonsterItem();
		return;
	}

	this->AttackMonster2Character(i_pnMonster, ptmClientInfo, pSendBuf);
}


void CNPCMapChannel::SendAttack2FieldServer(CNPCMonster *i_pnMonster
											 , CLIENT_INFO * i_pClientInfo
											 , BYTE *pSendBuf)
{
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
	if(NULL == i_pnMonster) {
		return;
	}
	
	// 2009-09-09 ~ 2010-01-13 by dhjin, ���Ǵ�Ƽ - �� ���������� ���� ��� �����ϰ� ����, �ذ� ���� ���� HPActionItem ���� ��� ī��Ʈ�� ���δ�.
	i_pnMonster->m_HPAction.SetSuccessAttackItemIdxHPRate();
	HPACTION_TALK_HPRATE MsgTalk;
	MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
	if(i_pnMonster->m_HPAction.GetHPTalkAttack(i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum, MsgTalk.HPTalk, &MsgTalk.HPCameraTremble)) {
		// Attack�� ����.
		MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
		this->SendFSvrHPTalk(i_pnMonster, &MsgTalk);
	}

	if(ITEMKIND_FOR_MON_SKILL == i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind) {
// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - �ذ� ���� ó�� CNPCMonster::UseSkill()���� ó���Ѵ�.
// 		INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_ATTACK_SKILL, T_FN_BATTLE_ATTACK_SKILL, pSendMsg, pSendBuf);
// 		pSendMsg->MapInfo			= m_MapChannelIndex;
// 		pSendMsg->MonsterIndex		= i_pnMonster->MonsterIndex;
// 		pSendMsg->ClientIndex		= i_pClientInfo->ClientIndex;	
// 		pSendMsg->SkillItemNum		= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
// 		if(DES_WARP == i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrDestParameter[0]) {
// 			// �����̵� ��ų�̸� ���͸� Ÿ�� ������ �����Ų��.
// 			i_pnMonster->SetUserPositionVector(&i_pClientInfo->PositionVector, &i_pClientInfo->TargetVector);
// 
// 			CheckMonsterPositionWarp(i_pnMonster, min(2.0f, (float)((i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwTimeLastMoved)/MONSTER_UPDATE_MOVE_TERM_TICK)) );
// 
// 			///////////////////////////////////////////////////////////////////////////////
// 			// �̵� ��ǥ Block ó��
// 			UpdateBlockPosition(i_pnMonster->m_BeforePosition.x, i_pnMonster->m_BeforePosition.z,
// 				i_pnMonster->PositionVector.x, i_pnMonster->PositionVector.z, i_pnMonster->MonsterIndex);
// 
// 			pSendMsg->PositionVector	= i_pClientInfo->PositionVector;
// 			pSendMsg->TargetVector		= i_pClientInfo->TargetVector*1000.0f;
// 
// 		}
// 		else if (DES_SKILL_INVINCIBLE == i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrDestParameter[0]) {
// 			// �踮�� Ȯ�� �����ϰ� �踮��� �� �� �ߵ��ϸ� ���������� �ߵ��̱� ������ HPAction���� ����������.
// 			i_pnMonster->m_HPAction.EraseHPActionByUseItemArrayIdx(i_pnMonster->m_BarrierUseItemArrayIdx);
// 		}
// 		else {
// 			pSendMsg->PositionVector	= i_pnMonster->PositionVector;	// ���Ϳ� ���� ��ġ ������ ��������!
// 		}
// 		Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SKILL));
// 		char szTemp[256];
// 		sprintf(szTemp, "[Check] T_FN_BATTLE_ATTACK_SKILL Test, SkillNum = (%d) \r\n", pSendMsg->SkillItemNum);
// 		g_pNPCGlobal->WriteSystemLog(szTemp);
// 		////////////////////////////////////////////////////////////////////////////////
// 		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��ų ��Ƽ Ÿ�� ó��, ���� ���� �����ϰ� ó��. �켱 ��׷δ� �������� �ʴ´�.
// 		if(1 < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget
// 			&& DES_WARP != i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrDestParameter[0]
// 			&& DES_SKILL_INVINCIBLE != i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrDestParameter[0]) {
// 			int		MultiTargetCount  = 0;
// 			vectorClientIndex tmClientIdxList;
// 			tmClientIdxList.reserve(10);
// 			if(1 >= NPCGetAdjacentCharacterIndexes(&i_pnMonster->PositionVector, i_pnMonster->m_pUsingMonsterItem->pItemInfo->Range
// 				, i_pnMonster->m_pUsingMonsterItem->pItemInfo->Range*2, &tmClientIdxList, i_pnMonster->MonsterInfoPtr->Belligerence)) {
// 				// �� ���� ó�� �߱� ������ �� �� �̻��̸� ó��
// 				return;
// 			}
// 			int CheckSize = i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget - 1;
// 			if(tmClientIdxList.size() < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget) {
// 				// �ټ� ������ ��׷� ����Ʈ ���� ���ٸ� ��׷� ����Ʈ ���� �ִ뷮 �Ҵ�.
// 				CheckSize = tmClientIdxList.size();
// 			}
// 			vectorClientIndex::iterator itr(tmClientIdxList.begin());
// 			for(; itr != tmClientIdxList.end(); itr++) {
// 				CLIENT_INFO		* ptmClientInfo = GetClientInfo(*itr);
// 				if(ptmClientInfo->ClientIndex == i_pClientInfo->ClientIndex) {
// 					// �̹� ó���� ������ ���� ���� ��������
// 					continue;
// 				}
// 				if(NULL != ptmClientInfo && ptmClientInfo->ClientState == CS_GAMESTARTED) {
// 					INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_ATTACK_SKILL, T_FN_BATTLE_ATTACK_SKILL, pSendMsg, pSendBuf);
// 					pSendMsg->MapInfo			= m_MapChannelIndex;
// 					pSendMsg->MonsterIndex		= i_pnMonster->MonsterIndex;
// 					pSendMsg->ClientIndex		= ptmClientInfo->ClientIndex;	
// 					pSendMsg->SkillItemNum		= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
// 					pSendMsg->PositionVector	= i_pnMonster->PositionVector;	// ���Ϳ� ���� ��ġ ������ ��������!
// 					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SKILL));
// 					MultiTargetCount++;
// 				}
// 				if(MultiTargetCount >= CheckSize) {
// 					break;
// 				}
// 			}			
// 		}		
//		////////////////////////////////////////////////////////////////////////////////
//		// 2009-09-09 ~ 2010-01-18 by dhjin, ���Ǵ�Ƽ - �ּ� ó��, ������ �̹� ������ �־���. 2�� �����ϴ� ���� ����.
//		// 2009-09-09 ~ 2010-01-14 by dhjin, ���Ǵ�Ƽ - ��ų ��Ƽ Ÿ�� ó���ϸ鼭 �ڱ� �ڽ� ��ų ó�� �ȵ� �κ� �߰�
// 		else if(0 == i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget) {
// 			INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_ATTACK_SKILL, T_FN_BATTLE_ATTACK_SKILL, pSendMsg, pSendBuf);
// 			pSendMsg->MapInfo			= m_MapChannelIndex;
// 			pSendMsg->MonsterIndex		= i_pnMonster->MonsterIndex;
// 			pSendMsg->ClientIndex		= 0;	
// 			pSendMsg->SkillItemNum		= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
// 			pSendMsg->PositionVector	= i_pnMonster->PositionVector;	// ���Ϳ� ���� ��ġ ������ ��������!
// 			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SKILL));
// 		}
		i_pnMonster->UseSkill(i_pClientInfo->ClientIndex);		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
		return;
	}

	if(IS_PRIMARY_WEAPON_MONSTER(i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind))
	{
		///////////////////////////////////////////////////////////////////////
		// MultiNum ó��
		for(int i = 0; i < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum; i++)
		{
			INIT_MSG(MSG_FN_BATTLE_ATTACK_PRIMARY, T_FN_BATTLE_ATTACK_PRIMARY, pSendBattleAttackPri, pSendBuf);
			pSendBattleAttackPri->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
			pSendBattleAttackPri->AttackIndex		= i_pnMonster->MonsterIndex;
			pSendBattleAttackPri->TargetIndex		= i_pClientInfo->ClientIndex;			
			pSendBattleAttackPri->WeaponItemNumber	= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
			pSendBattleAttackPri->WeaponIndex		= 0;
			pSendBattleAttackPri->TargetPosition	= i_pClientInfo->PositionVector;
			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_PRIMARY));
		}
	}
	else
	{
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ؿ� �Լ��� ����
		///////////////////////////////////////////////////////////////////////
		// MultiNum ó��
// 		BYTE byExplosionPos = 128 - i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum/2;		
// 		for(int i = 0; i < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum; i++)
// 		{
// 			INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_ATTACK_SECONDARY, T_FN_BATTLE_ATTACK_SECONDARY, pSendBattleAttackSec, pSendBuf);
// 			pSendBattleAttackSec->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
// 			pSendBattleAttackSec->AttackIndex		= i_pnMonster->MonsterIndex;
// 			pSendBattleAttackSec->TargetIndex		= i_pClientInfo->ClientIndex;
// 			pSendBattleAttackSec->WeaponIndex		= m_uiMissileUniqueIndex++;
// 			pSendBattleAttackSec->WeaponItemNumber	= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
// 			pSendBattleAttackSec->TargetPosition	= i_pClientInfo->PositionVector;
// 			pSendBattleAttackSec->Distance			= byExplosionPos;
// 			pSendBattleAttackSec->SecAttackType		= 0;
// 			pSendBattleAttackSec->AttackPosition	= i_pnMonster->PositionVector;		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ��ġ
// 			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SECONDARY));
// 			
// 			if(0 == i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum%2
// 				&& 127 == byExplosionPos)
// 			{
// 				byExplosionPos = 129;
// 			}
// 			else
// 			{
// 				byExplosionPos++;
// 			}
//		}
		this->SendFSvrBattleAttackSec(i_pnMonster, i_pClientInfo->ClientIndex, &i_pClientInfo->PositionVector);
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �̻��� ��Ƽ Ÿ�� ó��, ���� ���� �����ϰ� ó��. �켱 ��׷δ� �������� �ʴ´�.
		if(1 < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget) {
			int MultiTargetSize = i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget-1;
			if(BELL_INFINITY_ATTACK_MONSTER == i_pnMonster->MonsterInfoPtr->Belligerence) {
				// BELL_INFINITY_ATTACK_MONSTER ó��
				MultiTargetSize = (MultiTargetSize) - (this->BattleAttackSecMultiTargetUser(i_pnMonster, i_pClientInfo, MultiTargetSize));
				if(1 <= MultiTargetSize) {
					// ��Ƽ Ÿ���� ���� �ִٸ� ���� �˻�
					this->BattleAttackSecMultiTargetMonster(i_pnMonster, NULL, MultiTargetSize);
				}
				return;
			}
			else {
				this->BattleAttackSecMultiTargetUser(i_pnMonster, i_pClientInfo, MultiTargetSize);
			}	
		}
	}	
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::SendAttack2MonFieldServer(CNPCMonster *i_pnMonster, CNPCMonster *i_pTargetMonster, BYTE *pSendBuf)
/// \brief		���Ǵ�Ƽ - ���Ͱ� ���� 
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SendAttack2MonFieldServer(CNPCMonster *i_pnMonster, CNPCMonster *i_pTargetMonster, BYTE *pSendBuf) {
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ����� 2���� Bell���͸� ó���Ѵ�.
	if(BELL_INFINITY_DEFENSE_MONSTER != i_pnMonster->MonsterInfoPtr->Belligerence
		&& BELL_INFINITY_ATTACK_MONSTER != i_pnMonster->MonsterInfoPtr->Belligerence) {
		return;
	}

	// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
	int fMonsterMultiTargetIndex = 0;
  	D3DXVECTOR3 fMonsterMultiTargetVector = i_pTargetMonster->GetNearMultiTarget(i_pnMonster->PositionVector, &fMonsterMultiTargetIndex);
	// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
	// 2009-09-09 ~ 2010-01-13 by dhjin, ���Ǵ�Ƽ - �� ���������� ���� ��� �����ϰ� ����, �ذ� ���� ���� HPActionItem ���� ��� ī��Ʈ�� ���δ�.
	i_pnMonster->m_HPAction.SetSuccessAttackItemIdxHPRate();
	HPACTION_TALK_HPRATE MsgTalk;
	MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
	if(i_pnMonster->m_HPAction.GetHPTalkAttack(i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum, MsgTalk.HPTalk, &MsgTalk.HPCameraTremble)) {
		// Attack�� ����.
		MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
		this->SendFSvrHPTalk(i_pnMonster, &MsgTalk);
	}

	if(ITEMKIND_FOR_MON_SKILL == i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind) {
		i_pnMonster->UseSkill(i_pTargetMonster->MonsterIndex);		// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) -
		return;
	}
	
	if(IS_PRIMARY_WEAPON_MONSTER(i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind))
	{
		///////////////////////////////////////////////////////////////////////
		// MultiNum ó��
		for(int i = 0; i < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum; i++)
		{
			INIT_MSG(MSG_FN_BATTLE_ATTACK_PRIMARY, T_FN_BATTLE_ATTACK_PRIMARY, pSendBattleAttackPri, pSendBuf);
			pSendBattleAttackPri->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
			pSendBattleAttackPri->AttackIndex		= i_pnMonster->MonsterIndex;
			pSendBattleAttackPri->TargetIndex		= i_pTargetMonster->MonsterIndex;			
			pSendBattleAttackPri->WeaponItemNumber	= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
			pSendBattleAttackPri->WeaponIndex		= 0;

			// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			///////////////
			// ���� �ڵ� //
			//pSendBattleAttackPri->TargetPosition	= i_pTargetMonster->PositionVector;
			///////////////
			// ���� �ڵ� //
			pSendBattleAttackPri->TargetPosition	= fMonsterMultiTargetVector;
			pSendBattleAttackPri->MultiTargetIndex	= fMonsterMultiTargetIndex;
			// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_PRIMARY));
		}
	}
	else
	{
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ؿ� �Լ��� ����
// 		///////////////////////////////////////////////////////////////////////
// 		// MultiNum ó��
// 		BYTE byExplosionPos = 128 - i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum/2;		
// 		for(int i = 0; i < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum; i++)
// 		{
// 			INIT_MSG(MSG_FN_BATTLE_ATTACK_SECONDARY, T_FN_BATTLE_ATTACK_SECONDARY, pSendBattleAttackSec, pSendBuf);
// 			pSendBattleAttackSec->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
// 			pSendBattleAttackSec->AttackIndex		= i_pnMonster->MonsterIndex;
// 			pSendBattleAttackSec->TargetIndex		= i_pTargetMonster->MonsterIndex;
// 			pSendBattleAttackSec->WeaponIndex		= m_uiMissileUniqueIndex++;
// 			pSendBattleAttackSec->WeaponItemNumber	= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum;
// 			pSendBattleAttackSec->TargetPosition	= i_pTargetMonster->PositionVector;
// 			pSendBattleAttackSec->Distance			= byExplosionPos;
// 			pSendBattleAttackSec->SecAttackType		= 0;
// 			pSendBattleAttackSec->AttackPosition	= i_pnMonster->PositionVector;		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ��ġ
// 			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SECONDARY));
// 			
// 			if(0 == i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiNum%2
// 				&& 127 == byExplosionPos)
// 			{
// 				byExplosionPos = 129;
// 			}
// 			else
// 			{
// 				byExplosionPos++;
// 			}
// 		}

		// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		///////////////
		// ���� �ڵ� //
		// this->SendFSvrBattleAttackSec(i_pnMonster, i_pTargetMonster->MonsterIndex, &i_pTargetMonster->PositionVector);
		///////////////
		// ���� �ڵ� //
		this->SendFSvrBattleAttackSec(i_pnMonster, i_pTargetMonster->MonsterIndex, &fMonsterMultiTargetVector, fMonsterMultiTargetIndex);
		// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �̻��� ��Ƽ Ÿ�� ó��, ���� ���� �����ϰ� ó��. �켱 ��׷δ� �������� �ʴ´�.
		if(1 < i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget) {
			if(BELL_INFINITY_DEFENSE_MONSTER == i_pnMonster->MonsterInfoPtr->Belligerence) {
				// BELL_INFINITY_DEFENSE_MONSTER ó��
				this->BattleAttackSecMultiTargetMonster(i_pnMonster, i_pTargetMonster, i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget-1);
				return;
			}
			else if(BELL_INFINITY_ATTACK_MONSTER == i_pnMonster->MonsterInfoPtr->Belligerence) {
				// BELL_INFINITY_ATTACK_MONSTER ó��
				int MultiTargetSize = i_pnMonster->m_pUsingMonsterItem->pItemInfo->MultiTarget-1;
				MultiTargetSize = (MultiTargetSize) - (this->BattleAttackSecMultiTargetMonster(i_pnMonster, i_pTargetMonster, MultiTargetSize));
				if(1 <= MultiTargetSize) {
					// ��Ƽ Ÿ���� ���� �ִٸ� ������ �˻��Ͽ� ó��
					this->BattleAttackSecMultiTargetUser(i_pnMonster, NULL, MultiTargetSize);
				}
				return;
			}
		}
	}		
}


void CNPCMapChannel::SendMonsterMove2FieldServer(CNPCMonster *i_pnMonster, BYTE *i_SendBuf)
{
	// 2013-08-05 by jhseol, NPC���� ũ���� ����� �α�
	if (NULL == i_pnMonster || NULL == i_SendBuf)
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE,"[DEBUG] CNPCMapChannel::SendMonsterMove2FieldServer, i_pnMonster(%#010x), i_SendBuf(%#010x) is NULL\r\n", i_pnMonster, i_SendBuf);
	}
	// end 2013-08-05 by jhseol, NPC���� ũ���� ����� �α�
	INIT_MSG(MSG_FN_MONSTER_MOVE, T_FN_MONSTER_MOVE, pSendFNMonsterMove, i_SendBuf);
	pSendFNMonsterMove->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
	pSendFNMonsterMove->ClientIndex		= i_pnMonster->MonsterIndex;
	pSendFNMonsterMove->TargetIndex		= i_pnMonster->m_nTargetIndex;
	pSendFNMonsterMove->PositionVector	= i_pnMonster->PositionVector;
	pSendFNMonsterMove->TargetVector	= i_pnMonster->TargetVector*1000.0f;
	pSendFNMonsterMove->usSendRange		= i_pnMonster->SendMoveRange;

	Send2FieldServerW(i_SendBuf, MSG_SIZE(MSG_FN_MONSTER_MOVE));
}

void CNPCMapChannel::AttackMonster2Character(CNPCMonster *i_pnMonster
											 , CLIENT_INFO * i_pClientInfo
											 , BYTE *pSendBuf)
{
	BodyCond_t			tmBodyCon;
	MONSTER_ITEM		*pMonItem = i_pnMonster->m_pUsingMonsterItem;
	if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_FIREATTACK_ALL_MASK))
	{
		if(1 == pMonItem->pItemInfo->ShotNum
			|| i_pnMonster->m_nCurrentShotNumCount >= pMonItem->pItemInfo->ShotNum)
		{
			if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] >= pMonItem->pItemInfo->ReAttacktime)
			{				
				i_pnMonster->ResetAttackBodyCondition();
				i_pnMonster->SelectUsingMonsterItem();
			}
			return;
		}
	}
	
	BOOL bIsPrimaryWeapon = IS_PRIMARY_WEAPON_MONSTER(i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind)?TRUE:FALSE;

	if(i_pnMonster->m_nCurrentShotNumCount > 0)
	{
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ذ� ���� ����, ShotNum���� ���� ���� �� �� ���� ����
		if(i_pnMonster->m_nCurrentShotNumCount >= pMonItem->pItemInfo->ShotNum) {
			i_pnMonster->ResetAttackBodyCondition();
 			i_pnMonster->SelectUsingMonsterItem();
			return;
		}

		this->SendAttack2FieldServer(i_pnMonster, i_pClientInfo, pSendBuf);

		i_pnMonster->m_nCurrentShotNumCount++;									// ShotNum�� �����Ѵ�.
		i_pnMonster->m_dwTimeMonsterLastAttack	= i_pnMonster->m_dwCurrentTick;	// Monster�� ������ ������ �ð�
	}
	else if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] > pMonItem->pItemInfo->ReAttacktime)
	{
		float		fMaxItemRange = pMonItem->pItemInfo->Range;				
		if(FALSE == i_pnMonster->m_MoveInfo.MovableFlag
			|| EVENT_TYPE_NO_OBJECT_MONSTER != i_pnMonster->m_byObjectMonsterType
			|| FORM_GROUND_MOVE == i_pnMonster->CurrentMonsterForm)
		{// ������, ������Ʈ, ���� ����

			fMaxItemRange *= 1.5f;
		}
		else if(0 != pMonItem->pItemInfo->AttackTime 
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
		{// AttackTime�� 0�� �ƴϸ鼭 Attack�غ� �Ϸ�� ����

			fMaxItemRange *= 0.8f;
		}

		float fDisFromAttackPosToTargetPos = D3DXVec3Length(&(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));	// Ŭ���̾�Ʈ�� ������ �Ÿ��� ���Ѵ�.

		BOOL bNoCheck = FALSE;
		if(pMonItem->pItemInfo->AttackTime
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
		{
			bNoCheck = TRUE;
		}
		if(bNoCheck
			|| fDisFromAttackPosToTargetPos <= fMaxItemRange)
		{
			D3DXVECTOR3		tmUnitVec3M2C;
			D3DXVec3Normalize(&tmUnitVec3M2C, &(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));		// ���� ���Ϳ��� Ŭ���̾�Ʈ�� ���ϴ� Target Vector�� ���Ѵ�.
			float fPinPoint = ACOS(D3DXVec3Dot(&i_pnMonster->TargetVector, &tmUnitVec3M2C));						// ���Ϳ��� Target Vector�� ������ ���� ���� Target Vector ������ ���� ���Ѵ�
			if(bNoCheck
				||( fPinPoint <= pMonItem->pItemInfo->RangeAngle && FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &i_pClientInfo->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+i_pnMonster->MonsterInfoPtr->MonsterUnitKind) )
				)
			{
				if(pMonItem->pItemInfo->AttackTime == 0
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					|| (COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)) && i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
					|| (COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)) && i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime) // 2009-09-09 ~ 2010-01-18 by dhjin, ���Ǵ�Ƽ - ti_item -> AttackTime üũ ���� �κ� �߰�
					)
				{
					tmBodyCon = i_pnMonster->BodyCondition;
					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
					SET_BODYCON_BIT(tmBodyCon, this->GetFireAttackBodyCondMask(pMonItem->byBodyConArrayIndex));
					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
					
					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));

					if(FALSE == NPCMonsterAttackSkill(i_pnMonster, pMonItem->pItemInfo))
					{
						this->SendAttack2FieldServer(i_pnMonster, i_pClientInfo, pSendBuf);
					}
					
					i_pnMonster->m_dwTimeMonsterLastAttack	= i_pnMonster->m_dwCurrentTick;	// Monster�� ������ ������ �ð�
					i_pnMonster->m_nCurrentShotNumCount		= 1;							// ShotNum�� ������ ��Ÿ����, ShotNum == 1 �̾ �������
					i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] = i_pnMonster->m_dwCurrentTick;	// ReAttackTime�� Update�Ѵ�.
					
					///////////////////////////////////////////////////////////////////////////////
					// ���� ���� ���Ͱ� ���� �� ó��
					if(pMonItem->pItemInfo->OrbitType == ORBIT_BODYSLAM)
					{
						tmUnitVec3M2C.y = 0.0f;
						D3DXVec3Normalize(&tmUnitVec3M2C, &tmUnitVec3M2C);
						GNPCRotateTargetVectorHorizontal(&tmUnitVec3M2C, &tmUnitVec3M2C, i_pnMonster->m_MoveInfo.LRDirect*(MONSTER_MAX_QUICK_TURN_ANGLE - i_pnMonster->MonsterInfoPtr->QuickTurnAngle), i_pnMonster->MonsterInfoPtr->QuickTurnAngle);
						i_pnMonster->SetEnforceTargetVector(&tmUnitVec3M2C, i_pnMonster->GetSpeed(), MSS_QUICK_TURN_GENERAL);
						
						if(MSS_QUICK_TURN_GENERAL == i_pnMonster->m_enMoveState)
						{
							tmBodyCon = i_pnMonster->BodyCondition;
							SET_BODYCON_BIT(tmBodyCon, BODYCON_BOOSTER3_MASK);
							i_pnMonster->ChangeBodyCondition(&tmBodyCon);
							
							INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
							pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
							pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
							pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
						}
					}
				}
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//				else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
				else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
				{
					i_pnMonster->m_dwLastAttackTime = i_pnMonster->m_dwCurrentTick;
					
					tmBodyCon = i_pnMonster->BodyCondition;
					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
					SET_BODYCON_BIT(tmBodyCon, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex));
					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
					
					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
				}
			}
			else
			{
				i_pnMonster->ResetAttackBodyCondition();
			}
		}
		else
		{
			// 2007-01-15 by cmkwon, ��Ÿ� ������ �������� ���ϸ� ���⸦ ��ȯ�ϵ��� ó���Ѵ�
			i_pnMonster->SelectUsingMonsterItem();
			i_pnMonster->ResetAttackBodyCondition();
		}
	}
}


// 2005-01-19 by cmkwon
//
/////////////////////////////////////////////////////////////////////////////////
///// \fn			void CNPCMapChannel::AttackMonster2CharacterWithPrimaryItem(CNPCMonster *i_pnMonster
/////															, CLIENT_INFO * i_pClientInfo
/////															, MONSTER_ITEM *i_pItemInfo
/////															, BYTE *pSendBuf
/////															, DWORD dwCurrentTick)
///// \brief		���Ͱ� PrimaryItem���� ĳ���͸� �����ϴ� ó��
///// \author		cmkwon
///// \date		2004-04-02 ~ 2004-04-02
///// \warning	
/////
///// \param		
///// \return		
/////////////////////////////////////////////////////////////////////////////////
//void CNPCMapChannel::AttackMonster2CharacterWithPrimaryItem(CNPCMonster *i_pnMonster
//															, CLIENT_INFO * i_pClientInfo
//															, BYTE *pSendBuf)
//{	
//	float							fDisFromAttackPosToTargetPos;			// �����ڿ� �ǰ����ڿ��� Position �Ÿ�
//	D3DXVECTOR3						TempVector3;
//	float							fPinPoint=0.0f;
//	BodyCond_t						tmBodyCon;
//	MONSTER_ITEM					*pMonItem = i_pnMonster->m_pUsingMonsterItem;
//	float							fMaxItemRange = pMonItem->pItemInfo->Range;
//
//	///////////////////////////////////////////////////////////////////////////////
//	// 1�� ����� �����Ÿ����� ũ���� �߻� �Ѵ�
//	// ���� ���� ������ ���͸� �����ϰ�
//	if(FALSE == i_pnMonster->m_MoveInfo.MovableFlag
//		|| EVENT_TYPE_NO_OBJECT_MONSTER != i_pnMonster->m_byObjectMonsterType)
//	{
//		fMaxItemRange *= 2;
//	}
//	else if(pMonItem->pItemInfo->OrbitType != ORBIT_BODYSLAM)
//	{
//		fMaxItemRange *= 1.5f;
//	}
//
//	///////////////////////////////////////////////////////////////////////
//	// 1. ShotNum�� 2�̻��̰� ��� �����������
//	// 2. 1�� �ƴϸ鼭 ReAttack �ð��� �������
//	// 3. 1,2�� �ƴѰ��
//	if(pMonItem->pItemInfo->ShotNum > 1
//		&& i_pnMonster->m_nCurrentShotNumCount > 0)
//	{	// PrimaryItem�� ShotNum�� 1���� ũ�� AttackCount�� 0���� ũ�� ���縦 ������ ��� �̹Ƿ� �߻�
//
//		///////////////////////////////////////////////////////////////////////
//		// MultiNum ó��
//		for(int i = 0; i < pMonItem->pItemInfo->MultiNum; i++)
//		{
//			INIT_MSG(MSG_FN_BATTLE_ATTACK_PRIMARY, T_FN_BATTLE_ATTACK_PRIMARY, pSendBattleAttackPri, pSendBuf);
//			pSendBattleAttackPri->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
//			pSendBattleAttackPri->AttackIndex		= i_pnMonster->MonsterIndex;
//			pSendBattleAttackPri->TargetIndex		= i_pClientInfo->ClientIndex;			
//			pSendBattleAttackPri->WeaponItemNumber	= pMonItem->pItemInfo->ItemNum;
//			pSendBattleAttackPri->WeaponIndex		= 0;
//			pSendBattleAttackPri->TargetPosition	= i_pClientInfo->PositionVector;
//			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_PRIMARY));
//		}
//
//		///////////////////////////////////////////////////////////////////////
//		// Monster�� ������ ������ �ð�
//		i_pnMonster->m_dwTimeMonsterLastAttack = i_pnMonster->m_dwCurrentTick;
//
//		///////////////////////////////////////////////////////////////////////
//		// ShotNum�� �����Ѵ�.
//		i_pnMonster->m_nCurrentShotNumCount++;
//
//		///////////////////////////////////////////////////////////////////////
//		// ShotNum ��ŭ �߻簡 �Ǿ����� ShotNum Count�� �ʱ�ȭ �Ѵ�.	
//		if(pMonItem->pItemInfo->ShotNum <= i_pnMonster->m_nCurrentShotNumCount)
//		{
//			i_pnMonster->m_nCurrentShotNumCount	= 0;
//			i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex]		= i_pnMonster->m_dwCurrentTick;
//			
//			tmBodyCon = i_pnMonster->BodyCondition;
//			CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//			i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//		}
//	}
//	else if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] > pMonItem->pItemInfo->ReAttacktime)
//	{	//
//		if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//		{
//			tmBodyCon = i_pnMonster->BodyCondition;
//			CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);			
//			i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//		}
//		else
//		{
//			fDisFromAttackPosToTargetPos = D3DXVec3Length(&(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));	// Ŭ���̾�Ʈ�� ������ �Ÿ��� ���Ѵ�.
//
//			if(  (0 != pMonItem->pItemInfo->AttackTime && FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)) && fDisFromAttackPosToTargetPos < fMaxItemRange*2/3)
//				|| ( (0 == pMonItem->pItemInfo->AttackTime || COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON))) && fDisFromAttackPosToTargetPos < fMaxItemRange )  )
////			if(fDisFromAttackPosToTargetPos < pMonItem->pItemInfo->Range)
//			{	// Primary �������� ���� ��ȿ �Ÿ��� ����
//				
//				D3DXVec3Normalize(&TempVector3, &(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));		// ���� ���Ϳ��� Ŭ���̾�Ʈ�� ���ϴ� Target Vector�� ���Ѵ�.
//				fPinPoint = ACOS(D3DXVec3Dot(&i_pnMonster->TargetVector, &TempVector3));								// ���Ϳ��� Target Vector�� ������ ���� ���� Target Vector ������ ���� ���Ѵ�
//				if(fPinPoint <= pMonItem->pItemInfo->RangeAngle
//					&& FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &i_pClientInfo->PositionVector))
//				{	// �������� ���� ��ȿ���̸� Ÿ�ٱ��� �������� ���� �浹�� ����
//				
//					if(pMonItem->pItemInfo->AttackTime == 0
//						|| (COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON))
//						&& i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
//						)
//					{
//						tmBodyCon = i_pnMonster->BodyCondition;
//						CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//						SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
//						i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//						
//						INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//						pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//						pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//						pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//						
//						if(FALSE == NPCMonsterAttackSkill(i_pnMonster, pMonItem->pItemInfo))
//						{
//							///////////////////////////////////////////////////////////////////////////////
//							// ��Ƽ�� ó��
//							for(int i = 0; i < pMonItem->pItemInfo->MultiNum; i++)
//							{
//								INIT_MSG(MSG_FN_BATTLE_ATTACK_PRIMARY, T_FN_BATTLE_ATTACK_PRIMARY, pSendBattleAttackPri, pSendBuf);
//								pSendBattleAttackPri->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
//								pSendBattleAttackPri->AttackIndex		= i_pnMonster->MonsterIndex;
//								pSendBattleAttackPri->TargetIndex		= i_pClientInfo->ClientIndex;
//								pSendBattleAttackPri->WeaponItemNumber	= pMonItem->pItemInfo->ItemNum;
//								pSendBattleAttackPri->WeaponIndex		= 0;
//								pSendBattleAttackPri->TargetPosition	= i_pClientInfo->PositionVector;
//								Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_PRIMARY));
//							}
//						}
//						///////////////////////////////////////////////////////////////////////
//						// Monster�� ������ ������ �ð�
//						i_pnMonster->m_dwTimeMonsterLastAttack = i_pnMonster->m_dwCurrentTick;
//						
//						///////////////////////////////////////////////////////////////////////////////
//						// ShotNum�� ������ ��Ÿ����, ShotNum == 1 �̾ �������
//						i_pnMonster->m_nCurrentShotNumCount = 1;
//						
//						///////////////////////////////////////////////////////////////////////////////
//						// ReAttackTime�� Update�Ѵ�.
//						i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] = i_pnMonster->m_dwCurrentTick;
//						
//						///////////////////////////////////////////////////////////////////////////////
//						// ���� ���� ���Ͱ� ���� �� ó��
//						if(pMonItem->pItemInfo->OrbitType == ORBIT_BODYSLAM)
//						{
//							TempVector3.y = 0.0f;
//							D3DXVec3Normalize(&TempVector3, &TempVector3);
//							GNPCRotateTargetVectorHorizontal(&TempVector3, &TempVector3, i_pnMonster->m_MoveInfo.LRDirect*(MONSTER_MAX_QUICK_TURN_ANGLE - i_pnMonster->MonsterInfoPtr->QuickTurnAngle), i_pnMonster->MonsterInfoPtr->QuickTurnAngle);
//							i_pnMonster->SetEnforceTargetVector(&TempVector3, i_pnMonster->GetSpeed(), MSS_QUICK_TURN_GENERAL);
//							
//							if(MSS_QUICK_TURN_GENERAL == i_pnMonster->m_enMoveState)
//							{
//								tmBodyCon = i_pnMonster->BodyCondition;
//								SET_BODYCON_BIT(tmBodyCon, BODYCON_BOOSTER3_MASK);
//								i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//								
//								INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//								pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//								pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//								pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//								Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//							}
//						}
//					}
//					else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//					{
//						i_pnMonster->m_dwLastAttackTime = i_pnMonster->m_dwCurrentTick;
//						
//						tmBodyCon = i_pnMonster->BodyCondition;
//						CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//						SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
//						i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//						
//						INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//						pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//						pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//						pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//					}
//				}
//				else if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON))
//					&& i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
//				{
//					tmBodyCon = i_pnMonster->BodyCondition;
//					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//				}
//				else if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//				{	// Attack BodyCondition�� �ʱ�ȭ, Angle�� �ȵǰų� �����Ÿ��� �浹�� �ִ�
//					
//					tmBodyCon = i_pnMonster->BodyCondition;
//					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//				}
//			}
//			else
//			{	// Attack BodyCondition�� �ʱ�ȭ, ������ ��ȿ �Ÿ��� �����.
//				
//				if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//				{
//					tmBodyCon = i_pnMonster->BodyCondition;
//					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//				}
//			}
//		}		
//	}
//	else
//	{	// 
//
//	}
//}
//
//void CNPCMapChannel::AttackMonster2CharacterWithSecondaryItem(CNPCMonster *i_pnMonster
//															  , CLIENT_INFO * i_pClientInfo
//															  , BYTE *pSendBuf)
//{
//	float							fDisFromAttackPosToTargetPos;			// �����ڿ� �ǰ����ڿ��� Position �Ÿ�
//	D3DXVECTOR3						TempVector3;
//	float							fPinPoint=0.0f;
//	BodyCond_t						tmBodyCon;
//	MONSTER_ITEM					*pMonItem = i_pnMonster->m_pUsingMonsterItem;
//	float							fMaxItemRange = pMonItem->pItemInfo->Range;
//
//
//	///////////////////////////////////////////////////////////////////////////////
//	// 2004-12-06 by cmkwon, 2�� ���⵵ �����Ÿ����� ũ���� �߻� �Ѵ�
//	// ���� ���� ������ ���͸� �����ϰ�
//	if(FALSE == i_pnMonster->m_MoveInfo.MovableFlag
//		|| EVENT_TYPE_NO_OBJECT_MONSTER != i_pnMonster->m_byObjectMonsterType)
//	{
//		fMaxItemRange *= 2.0f;
//	}
//
//	///////////////////////////////////////////////////////////////////////
//	// 1. ShotNum�� 2�̻��̰� ��� �����������
//	// 2. 1�� �ƴϸ鼭 ReAttack �ð��� �������
//	// 3. 1,2�� �ƴѰ��
//	if(pMonItem->pItemInfo->ShotNum > 1
//		&& i_pnMonster->m_nCurrentShotNumCount > 0)
//	{	// PrimaryItem�� ShotNum�� 1���� ũ�� AttackCount�� 0���� ũ�� ���縦 ������ ��� �̹Ƿ� �߻�
//
//		///////////////////////////////////////////////////////////////////////
//		// MultiNum ó��
//		BYTE byExplosionPos = 128 - pMonItem->pItemInfo->MultiNum/2;		
//		for(int i = 0; i < pMonItem->pItemInfo->MultiNum; i++)
//		{
//			INIT_MSG(MSG_FN_BATTLE_ATTACK_SECONDARY, T_FN_BATTLE_ATTACK_SECONDARY, pSendBattleAttackSec, pSendBuf);
//			pSendBattleAttackSec->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
//			pSendBattleAttackSec->AttackIndex		= i_pnMonster->MonsterIndex;
//			pSendBattleAttackSec->TargetIndex		= i_pClientInfo->ClientIndex;
//			pSendBattleAttackSec->WeaponIndex		= m_uiMissileUniqueIndex++;
//			pSendBattleAttackSec->WeaponItemNumber	= pMonItem->pItemInfo->ItemNum;
//			pSendBattleAttackSec->TargetPosition	= i_pClientInfo->PositionVector;
//			pSendBattleAttackSec->Distance			= byExplosionPos;
//			pSendBattleAttackSec->SecAttackType		= 0;
//			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SECONDARY));
//
//			if(0 == pMonItem->pItemInfo->MultiNum%2
//				&& 127 == byExplosionPos)
//			{
//				byExplosionPos = 129;
//			}
//			else
//			{
//				byExplosionPos++;
//			}
//		}
//
//		///////////////////////////////////////////////////////////////////////
//		// Monster�� ������ ������ �ð�
//		i_pnMonster->m_dwTimeMonsterLastAttack = i_pnMonster->m_dwCurrentTick;
//
//		///////////////////////////////////////////////////////////////////////
//		// ShotNum�� �����Ѵ�.
//		i_pnMonster->m_nCurrentShotNumCount++;
//
//		///////////////////////////////////////////////////////////////////////
//		// ShotNum ��ŭ �߻簡 �Ǿ����� ShotNum Count�� �ʱ�ȭ �Ѵ�.	
//		if(pMonItem->pItemInfo->ShotNum <= i_pnMonster->m_nCurrentShotNumCount)
//		{
//			i_pnMonster->m_nCurrentShotNumCount	= 0;
//			i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex]		= i_pnMonster->m_dwCurrentTick;
//			
//			tmBodyCon = i_pnMonster->BodyCondition;
//			CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//			i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//		}
//	}// if_end
//	else if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] > pMonItem->pItemInfo->ReAttacktime)
//	{	//
//
//		fDisFromAttackPosToTargetPos = D3DXVec3Length(&(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));	// Ŭ���̾�Ʈ�� ������ �Ÿ��� ���Ѵ�.
//		if(fDisFromAttackPosToTargetPos < fMaxItemRange)
//		{	// Primary �������� ���� ��ȿ �Ÿ��� ����
//
//			D3DXVec3Normalize(&TempVector3, &(i_pClientInfo->PositionVector - i_pnMonster->PositionVector));		// ���� ���Ϳ��� Ŭ���̾�Ʈ�� ���ϴ� Target Vector�� ���Ѵ�.
//			fPinPoint = ACOS(D3DXVec3Dot(&i_pnMonster->TargetVector, &TempVector3));								// ���Ϳ��� Target Vector�� ������ ���� ���� Target Vector ������ ���� ���Ѵ�
//			if(fPinPoint <= pMonItem->pItemInfo->RangeAngle
//				&& FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &i_pClientInfo->PositionVector, FALSE))
//			{	// �������� ���� ��ȿ���̸� Ÿ�ٱ��� �������� ���� �浹�� ����
//
//				if(pMonItem->pItemInfo->AttackTime == 0
//					|| (COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON))
//					&& i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
//					)
//				{
//
//					tmBodyCon = i_pnMonster->BodyCondition;
//					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
//					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//					
//					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//
//					if(FALSE == NPCMonsterAttackSkill(i_pnMonster, pMonItem->pItemInfo))
//					{
//						///////////////////////////////////////////////////////////////////////////////
//						// ��Ƽ�� ó��
//						BYTE byExplosionPos = 128 - pMonItem->pItemInfo->MultiNum/2;
//						for(int i = 0; i < pMonItem->pItemInfo->MultiNum; i++)
//						{
//							INIT_MSG(MSG_FN_BATTLE_ATTACK_SECONDARY, T_FN_BATTLE_ATTACK_SECONDARY, pSendBattleAttackSec, pSendBuf);
//							pSendBattleAttackSec->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
//							pSendBattleAttackSec->AttackIndex		= i_pnMonster->MonsterIndex;
//							pSendBattleAttackSec->TargetIndex		= i_pClientInfo->ClientIndex;
//							pSendBattleAttackSec->WeaponIndex		= m_uiMissileUniqueIndex++;
//							pSendBattleAttackSec->WeaponItemNumber	= pMonItem->pItemInfo->ItemNum;
//							pSendBattleAttackSec->TargetPosition	= i_pClientInfo->PositionVector;
//							pSendBattleAttackSec->Distance			= byExplosionPos;
//							pSendBattleAttackSec->SecAttackType		= 0;
//							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SECONDARY));
//							
//							if(0 == pMonItem->pItemInfo->MultiNum%2
//								&& 127 == byExplosionPos)
//							{
//								byExplosionPos = 129;
//							}
//							else
//							{
//								byExplosionPos++;
//							}
//						}
//					}
//
//					///////////////////////////////////////////////////////////////////////
//					// Monster�� ������ ������ �ð�
//					i_pnMonster->m_dwTimeMonsterLastAttack = i_pnMonster->m_dwCurrentTick;
//
//					///////////////////////////////////////////////////////////////////////////////
//					// ShotNum�� ������ ��Ÿ����, ShotNum == 1 �̾ �������
//					i_pnMonster->m_nCurrentShotNumCount = 1;
//
//					///////////////////////////////////////////////////////////////////////////////
//					// ReAttackTime�� Update�Ѵ�.
//					i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] = i_pnMonster->m_dwCurrentTick;
//
//					///////////////////////////////////////////////////////////////////////////////
//					// ���� ���� ���Ͱ� ���� �� ó��
//					if(pMonItem->pItemInfo->OrbitType == ORBIT_BODYSLAM)
//					{						
//						TempVector3.y = 0.0f;
//						D3DXVec3Normalize(&TempVector3, &TempVector3);
//						GNPCRotateTargetVectorHorizontal(&TempVector3, &TempVector3, i_pnMonster->m_MoveInfo.LRDirect*(MONSTER_MAX_QUICK_TURN_ANGLE - i_pnMonster->MonsterInfoPtr->QuickTurnAngle), i_pnMonster->MonsterInfoPtr->QuickTurnAngle);
//						i_pnMonster->SetEnforceTargetVector(&TempVector3, i_pnMonster->GetSpeed(), MSS_QUICK_TURN_GENERAL);
//						
//						if(MSS_QUICK_TURN_GENERAL == i_pnMonster->m_enMoveState)
//						{
//							tmBodyCon = i_pnMonster->BodyCondition;
//							SET_BODYCON_BIT(tmBodyCon, BODYCON_BOOSTER3_MASK);
//							i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//							
//							INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//							pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//							pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//							pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//						}
//					}
//				}
//				else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//				{
//					i_pnMonster->m_dwLastAttackTime = i_pnMonster->m_dwCurrentTick;
//					
//					tmBodyCon = i_pnMonster->BodyCondition;
//					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
//					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//					
//					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
//					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
//					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
//					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
//					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
//				}
//			}
//			else if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON))
//				&& i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
//			{
//				tmBodyCon = i_pnMonster->BodyCondition;
//				CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//				i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//			}
//			else if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
//			{	// Attack BodyCondition�� �ʱ�ȭ, Angle�� �ȵǰų� �����Ÿ��� �浹�� �ִ�
//				
//				tmBodyCon = i_pnMonster->BodyCondition;
//				CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//				i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//			}
//		}// if_end
//		else
//		{	// Attack BodyCondition�� �ʱ�ȭ, �Ÿ��� �����.
//
//			if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACK1_MASK<<(pMonItem->byArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)) )
//			{
//				tmBodyCon = i_pnMonster->BodyCondition;
//				CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
//				i_pnMonster->ChangeBodyCondition(&tmBodyCon);
//			}
//		}
//	}// elseif_end
//	else
//	{	// 
//		
//	}
//}

void CNPCMapChannel::AttackMonster2Monster(CNPCMonster *i_pnMonster, BYTE *pSendBuf)
{
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ذ� ���� ���� ���� �ý��� ����!!!!
//	ASSERT_NEVER_GET_HERE();

	CNPCMonster * pTargetMonster = GetNPCMonster(i_pnMonster->m_nTargetIndex);
	if(NULL == pTargetMonster || pTargetMonster->m_enMonsterState != MS_PLAYING)
	{	// Ÿ����  ��ȿ���� ����
		// ��ȿ���� ���� Ÿ���� �����ϰ� ���ο� Ÿ������ �����Ѵ�.
		// LastAttackTime�� �ʱ�ȭ ���� �ʴ´�, 
		
		i_pnMonster->DeleteAttackedInfowithIndex();
		return;
	}
	
	if(NULL == i_pnMonster->m_pUsingMonsterItem
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ��Ʈ�ѽ�ų�� �̸� ����
		//		|| COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACK6_MASK))
		|| COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_CONTROLSKILL_MASK))
	{
		return;
	}
	
	if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_ATTACKALL_MASK)
		&& FALSE == CheckMonsterSelectedItem(i_pnMonster))
	{
		i_pnMonster->SelectUsingMonsterItem();
		return;
	}
	
//	this->AttackMonster2Character(i_pnMonster, pTargetMonster, pSendBuf);

	BodyCond_t			tmBodyCon;
	MONSTER_ITEM		*pMonItem = i_pnMonster->m_pUsingMonsterItem;
	if(COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_FIREATTACK_ALL_MASK))
	{
		if(1 == pMonItem->pItemInfo->ShotNum
			|| i_pnMonster->m_nCurrentShotNumCount >= pMonItem->pItemInfo->ShotNum)
		{
			if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] >= pMonItem->pItemInfo->ReAttacktime)
			{				
				i_pnMonster->ResetAttackBodyCondition();
				i_pnMonster->SelectUsingMonsterItem();
			}
			return;
		}
	}
	
	BOOL bIsPrimaryWeapon = IS_PRIMARY_WEAPON_MONSTER(i_pnMonster->m_pUsingMonsterItem->pItemInfo->Kind)?TRUE:FALSE;

	if(i_pnMonster->m_nCurrentShotNumCount > 0)
	{
		////////////////////////////////////////////////////////////////////////////////
		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ذ� ���� ����, ShotNum���� ���� ���� �� �� ���� ����
		if(i_pnMonster->m_nCurrentShotNumCount > pMonItem->pItemInfo->ShotNum) {
			i_pnMonster->ResetAttackBodyCondition();
			i_pnMonster->SelectUsingMonsterItem();
			return;
		}

		this->SendAttack2MonFieldServer(i_pnMonster, pTargetMonster, pSendBuf);

		i_pnMonster->m_nCurrentShotNumCount++;									// ShotNum�� �����Ѵ�.
		i_pnMonster->m_dwTimeMonsterLastAttack	= i_pnMonster->m_dwCurrentTick;	// Monster�� ������ ������ �ð�
	}
	else if(i_pnMonster->m_dwCurrentTick - i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] > pMonItem->pItemInfo->ReAttacktime)
	{
		float		fMaxItemRange = pMonItem->pItemInfo->Range;				
		if(FALSE == i_pnMonster->m_MoveInfo.MovableFlag
			|| EVENT_TYPE_NO_OBJECT_MONSTER != i_pnMonster->m_byObjectMonsterType
			|| FORM_GROUND_MOVE == i_pnMonster->CurrentMonsterForm)
		{// ������, ������Ʈ, ���� ����

			fMaxItemRange *= 1.5f;
		}
		else if(0 != pMonItem->pItemInfo->AttackTime 
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
		{// AttackTime�� 0�� �ƴϸ鼭 Attack�غ� �Ϸ�� ����

			fMaxItemRange *= 0.8f;
		}
		
		// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		//////////
		// ���� //
		// float fDisFromAttackPosToTargetPos = D3DXVec3Length(&(pTargetMonster->PositionVector - i_pnMonster->PositionVector));	// ���Ϳ� ������ �Ÿ��� ���Ѵ�.

		//////////////////////
		// ������ ���� ���� //
		int fMonsterMultiTargetIndex = 0;
		D3DXVECTOR3 fMonsterMultiTargetVector = pTargetMonster->GetNearMultiTarget(i_pnMonster->PositionVector, &fMonsterMultiTargetIndex);

		float fDisFromAttackPosToTargetPos = D3DXVec3Length(&(fMonsterMultiTargetVector - i_pnMonster->PositionVector));	// ���Ϳ� ������ �Ÿ��� ���Ѵ�.
		// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

		BOOL bNoCheck = FALSE;
		if(pMonItem->pItemInfo->AttackTime
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
			&& COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
		{
			bNoCheck = TRUE;
		}
		if(bNoCheck
			|| fDisFromAttackPosToTargetPos <= fMaxItemRange)
		{
			D3DXVECTOR3		tmUnitVec3M2C;

			// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			//////////
			// ���� //
			// D3DXVec3Normalize(&tmUnitVec3M2C, &(pTargetMonster->PositionVector - i_pnMonster->PositionVector));		// ���� ���Ϳ��� ���͸� ���ϴ� Target Vector�� ���Ѵ�.

			//////////////////////
			// ������ ���� ���� //
			D3DXVec3Normalize(&tmUnitVec3M2C, &(fMonsterMultiTargetVector - i_pnMonster->PositionVector));		// ���� ���Ϳ��� ���͸� ���ϴ� Target Vector�� ���Ѵ�.
			// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

			float fPinPoint = ACOS(D3DXVec3Dot(&i_pnMonster->TargetVector, &tmUnitVec3M2C));						// ���Ϳ��� Target Vector�� ������ ���� ���� Target Vector ������ ���� ���Ѵ�

			// start 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			//////////
			// ���� //
			//	if(bNoCheck
			//	||( fPinPoint <= pMonItem->pItemInfo->RangeAngle && FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &pTargetMonster->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+i_pnMonster->MonsterInfoPtr->MonsterUnitKind) )
			////	||( FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &pTargetMonster->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+i_pnMonster->MonsterInfoPtr->MonsterUnitKind) )
			//	)

			//////////////////////
			// ������ ���� ���� //
				if(bNoCheck
				||( fPinPoint <= pMonItem->pItemInfo->RangeAngle && FALSE == CheckImpactStraightLineMapAndObjects(&i_pnMonster->PositionVector, &fMonsterMultiTargetVector, DEFAULT_OBJECT_MONSTER_OBJECT+i_pnMonster->MonsterInfoPtr->MonsterUnitKind) ) )
			// end 2011-03-22 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			{
				if(pMonItem->pItemInfo->AttackTime == 0
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					|| (COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)) && i_pnMonster->m_dwCurrentTick - i_pnMonster->m_dwLastAttackTime > pMonItem->pItemInfo->AttackTime)
					|| COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex))
					)
				{
					tmBodyCon = i_pnMonster->BodyCondition;
					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_FIREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
					SET_BODYCON_BIT(tmBodyCon, this->GetFireAttackBodyCondMask(pMonItem->byBodyConArrayIndex));
					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
					
					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));

					if(FALSE == NPCMonsterAttackSkill(i_pnMonster, pMonItem->pItemInfo))
					{
						this->SendAttack2MonFieldServer(i_pnMonster, pTargetMonster, pSendBuf);
					}
					
					i_pnMonster->m_dwTimeMonsterLastAttack	= i_pnMonster->m_dwCurrentTick;	// Monster�� ������ ������ �ð�
					i_pnMonster->m_nCurrentShotNumCount		= 1;							// ShotNum�� ������ ��Ÿ����, ShotNum == 1 �̾ �������
					i_pnMonster->m_ArrLastReattackTime[pMonItem->byArrayIndex] = i_pnMonster->m_dwCurrentTick;	// ReAttackTime�� Update�Ѵ�.
					
					///////////////////////////////////////////////////////////////////////////////
					// ���� ���� ���Ͱ� ���� �� ó��
					if(pMonItem->pItemInfo->OrbitType == ORBIT_BODYSLAM)
					{
						tmUnitVec3M2C.y = 0.0f;
						D3DXVec3Normalize(&tmUnitVec3M2C, &tmUnitVec3M2C);
						GNPCRotateTargetVectorHorizontal(&tmUnitVec3M2C, &tmUnitVec3M2C, i_pnMonster->m_MoveInfo.LRDirect*(MONSTER_MAX_QUICK_TURN_ANGLE - i_pnMonster->MonsterInfoPtr->QuickTurnAngle), i_pnMonster->MonsterInfoPtr->QuickTurnAngle);
						i_pnMonster->SetEnforceTargetVector(&tmUnitVec3M2C, i_pnMonster->GetSpeed(), MSS_QUICK_TURN_GENERAL);
						
						if(MSS_QUICK_TURN_GENERAL == i_pnMonster->m_enMoveState)
						{
							tmBodyCon = i_pnMonster->BodyCondition;
							SET_BODYCON_BIT(tmBodyCon, BODYCON_BOOSTER3_MASK);
							i_pnMonster->ChangeBodyCondition(&tmBodyCon);
							
							INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
							pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
							pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
							pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
							Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
						}
					}
				}
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//				else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON)))
				else if(FALSE == COMPARE_BODYCON_BIT(i_pnMonster->BodyCondition, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex)))
				{
					i_pnMonster->m_dwLastAttackTime = i_pnMonster->m_dwCurrentTick;
					
					tmBodyCon = i_pnMonster->BodyCondition;
					CLEAR_BODYCON_BIT(tmBodyCon, BODYCON_MON_ATTACKALL_MASK);
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 6~15, ��Ʈ�ѽ�ų���� �߰��� �ٵ�����ǰ� ������ �κ� ����
//					SET_BODYCON_BIT(tmBodyCon, BODYCON_MON_PREATTACK1_MASK<<(pMonItem->byBodyConArrayIndex*COUNT_MONSTER_ATTACK_BODYCON));
					SET_BODYCON_BIT(tmBodyCon, this->GetPreAttackBodyCondMask(pMonItem->byBodyConArrayIndex));
					i_pnMonster->ChangeBodyCondition(&tmBodyCon);
					
					INIT_MSG(MSG_FN_MONSTER_CHANGE_BODYCONDITION, T_FN_MONSTER_CHANGE_BODYCONDITION, pSeBody, pSendBuf);
					pSeBody->ChannelIndex	= this->m_MapChannelIndex.ChannelIndex;
					pSeBody->ClientIndex	= i_pnMonster->MonsterIndex;
					pSeBody->BodyCondition	= i_pnMonster->BodyCondition;
					Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_BODYCONDITION));
				}
			}
			else
			{
				i_pnMonster->ResetAttackBodyCondition();
			}
		}
		else
		{
			// 2007-01-15 by cmkwon, ��Ÿ� ������ �������� ���ϸ� ���⸦ ��ȯ�ϵ��� ó���Ѵ�
			i_pnMonster->SelectUsingMonsterItem();
			i_pnMonster->ResetAttackBodyCondition();
		}
	}



}

void CNPCMapChannel::UpdateMissilePosition2Character(CNPCMonster *i_pMonster, BYTE *pSendBuf)
{
//	MISSILE						*pMissile = NULL;
//	MSG_FN_BATTLE_ATTACK_FIND	*pSendBattleAttackFind = NULL;
//	float						fDistanceGap;
//	CLIENT_INFO					*ptmClientInfo = NULL;
//	D3DXVECTOR3					TempVector3;
//
//	list<MISSILE*>::iterator itrMissile = i_pMonster->m_mtlistShootedMissile.begin();
//	while(itrMissile != i_pMonster->m_mtlistShootedMissile.end())
//	{
//		pMissile = *itrMissile;
//		if(dwCurrentTick - pMissile->m_dwTimeCreated > 4000)
//		{	// �ð� �������� ����
//
//			INIT_MSG(MSG_FN_BATTLE_ATTACK_FIND, T_FN_BATTLE_ATTACK_FIND, pSendBattleAttackFind, pSendBuf);
//			pSendBattleAttackFind->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//			pSendBattleAttackFind->AttackIndex	= i_pMonster->MonsterIndex;
//			pSendBattleAttackFind->TargetIndex	= 0;
////			pSendBattleAttackFind->WeaponType	= 1;		// by kelovon, 20030811
//			pSendBattleAttackFind->WeaponIndex	= pMissile->WeaponIndex;
//			Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_FIND));
//
//			SAFE_DELETE(pMissile);
//			i_pMonster->m_mtlistShootedMissile.erase(itrMissile);
//			break;
//		}
//		else if(dwCurrentTick - pMissile->m_dwTimeLastMoved > MONSTER_UPDATE_MOVE_TERM_TICK)
//		{	// �̵�
//
//			pMissile->m_dwTimeLastMoved = dwCurrentTick;
//			if(pMissile->m_TargetIndex < MONSTER_CLIENT_INDEX_START_NUM)
//			{
//				ptmClientInfo = GetClientInfo(pMissile->m_TargetIndex);
//				if(ptmClientInfo && ptmClientInfo->ClientState == CS_GAMESTARTED)
//				{
//					fDistanceGap = D3DXVec3Length(&(ptmClientInfo->PositionVector - pMissile->PositionVector));	// Ŭ���̾�Ʈ�� ������ �Ÿ��� ���Ѵ�.
//					if(fDistanceGap > pMissile->m_fSpeed)
//					{
//						pMissile->PositionVector = pMissile->PositionVector + pMissile->TargetVector * pMissile->m_fSpeed;
//					}
//					else
//					{
//						pMissile->PositionVector = pMissile->PositionVector + pMissile->TargetVector * fDistanceGap;
//					}
//
//					if(TRUE == CheckImpactPositionMapAndObjects(&pMissile->PositionVector))
//					{	// �ʰ��� �浹�� ����
//
//						INIT_MSG(MSG_FN_BATTLE_ATTACK_FIND, T_FN_BATTLE_ATTACK_FIND, pSendBattleAttackFind, pSendBuf);
//						pSendBattleAttackFind->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//						pSendBattleAttackFind->AttackIndex	= i_pMonster->MonsterIndex;
//						pSendBattleAttackFind->TargetIndex	= 0;
////						pSendBattleAttackFind->WeaponType	= 1;		// by kelovon, 20030811
//						pSendBattleAttackFind->WeaponIndex	= pMissile->WeaponIndex;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_FIND));
//
//						i_pMonster->m_mtlistShootedMissile.erase(itrMissile);
//						delete pMissile;
//						break;
//					}
//
//					fDistanceGap = D3DXVec3Length(&(ptmClientInfo->PositionVector - pMissile->PositionVector));	// Ŭ���̾�Ʈ�� ������ �Ÿ��� ���Ѵ�.
//					if (fDistanceGap < 5)
//					{
//						INIT_MSG(MSG_FN_BATTLE_ATTACK_FIND, T_FN_BATTLE_ATTACK_FIND, pSendBattleAttackFind, pSendBuf);
//						pSendBattleAttackFind->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
//						pSendBattleAttackFind->AttackIndex	= i_pMonster->MonsterIndex;
//						pSendBattleAttackFind->TargetIndex	= pMissile->m_TargetIndex;
//						pSendBattleAttackFind->TargetPosition = ptmClientInfo->PositionVector;
////						pSendBattleAttackFind->WeaponType = 1;		// by kelovon, 20030811
//						pSendBattleAttackFind->WeaponIndex	= pMissile->WeaponIndex;
//						Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_FIND));
//
//						SAFE_DELETE(pMissile);
//						i_pMonster->m_mtlistShootedMissile.erase(itrMissile);
//						break;
//					}
//					else
//					{
//						if(dwCurrentTick - pMissile->m_dwTimeCreated < MONSTER_UPDATE_MOVE_TERM_TICK * 3)
//						{
//							pMissile->PositionVector += pMissile->TargetVector * pMissile->m_fSpeed;
//						}
//						else
//						{
//							D3DXVec3Normalize(&pMissile->TargetVector, &(ptmClientInfo->PositionVector - pMissile->PositionVector));
//							if(fDistanceGap > pMissile->m_fSpeed)
//							{
//								pMissile->PositionVector += pMissile->TargetVector * pMissile->m_fSpeed;
//							}
//							else
//							{
//								pMissile->PositionVector += pMissile->TargetVector * fDistanceGap;
//							}
//
//						}
//						if(pMissile->m_fSpeed < 16.0f)
//						{
//							pMissile->m_fSpeed += 1.0f;
//						}
//					}
//				}
//				else
//				{
//					pMissile->PositionVector = pMissile->PositionVector + pMissile->TargetVector * pMissile->m_fSpeed;
//					if(pMissile->m_fSpeed < 16.0f)
//					{
//						pMissile->m_fSpeed += 1.0f;
//					}
//				}
//			}
//		}
//		itrMissile++;
//	}
}

void CNPCMapChannel::DelelteMonsterHandler(CNPCMonster * i_pNMonster)
{
	if(i_pNMonster->m_enMonsterState == MS_NULL){			return;}

	if(FALSE == DeleteBlockPosition(i_pNMonster->PositionVector.x, i_pNMonster->PositionVector.z, i_pNMonster->MonsterIndex))
	{
		char szTemp[256];
		sprintf(szTemp, "[Error] DeleteBlockPosition_2 Error, MapChannel(%s) UnitIndex(%5d) XZ(%5.0f, %5.0f)\n"
			, GET_MAP_STRING(this->m_MapChannelIndex), i_pNMonster->MonsterIndex
			, i_pNMonster->PositionVector.x, i_pNMonster->PositionVector.z);
		DBGOUT(szTemp);
		g_pNPCGlobal->WriteSystemLog(szTemp);
	}
	
	m_mtvectorMonsterPtr.lock();
	if(FALSE == i_pNMonster->m_byObjectMonsterType)
	{// ������Ʈ ���Ͱ� �ƴ�

		MONSTER_CREATE_REGION_INFO_EX	*pInfoEX 
			= GetMonsterCreateRegionInfoEXWidhIndex(i_pNMonster->m_dwIndexCreatedMonsterData);

		if(NULL != pInfoEX
			&& pInfoEX->nCurrentCount > 0)
		{
			pInfoEX->nCurrentCount--;
			pInfoEX->dwLastTimeMonsterCreate = timeGetTime();
		}
	}
	else
	{// ������Ʈ ������
		
		OBJECTINFOSERVER *pObjMonsterInfo = this->FindObjectMonsterInfoByObjectEventIndex(i_pNMonster->m_dwIndexCreatedMonsterData);
		if(pObjMonsterInfo)
		{
			pObjMonsterInfo->m_EventInfo.m_dwLastTimeObjectMonsterCreated = timeGetTime();
			pObjMonsterInfo->m_EventInfo.m_byObjectMonsterCreated = FALSE;
		}
	}
	if(m_nCurMonsterCountInChannel > 0)
	{
		m_nCurMonsterCountInChannel--;
	}

	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010-01-27 by dhjin, ���Ǵ�Ƽ - Success, Fail�� ���� �ʱ�ȭ, ����ÿ��� ��� ����ϵ��� ��ġ ���� �ּ� ó����
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
// 	if(i_pNMonster->m_HPAction.CheckValidSizeTalkDead()) {
// 		HPACTION_TALK_HPRATE MsgTalk;
// 		MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
// 		if(i_pNMonster->m_HPAction.GetTalkDead(&MsgTalk)) {
// 			// ������ ��ȭ�� �ִٸ� �����Ѵ�.
// 			this->SendFSvrHPTalk(i_pNMonster, &MsgTalk);
// 		}
// 	}

	i_pNMonster->ResetMonster();
	m_vectorUsableMonsterIndex.push_back(i_pNMonster->MonsterIndex);
	m_mtvectorMonsterPtr.unlock();
}


BOOL CNPCMapChannel::CheckImpactFrontPositionMap(CNPCMonster * i_pNMon, D3DXVECTOR3 *o_pTarVector3)
{
	///////////////////////////////////////////////////////////////////////////////
	// - MoveState�� (Object, ��)�浹 �����̸� FALSE�� �����Ѵ�.
	if(MSS_MAP_IMPACT == i_pNMon->m_enMoveState
		|| FALSE == i_pNMon->m_MoveInfo.MovableFlag)
	{

		return FALSE;
	}

	D3DXVECTOR3 tmVec3Front = this->GetFrontPosition(i_pNMon);
	if(FALSE == m_pNPCMapProject->IsValidPosition(&tmVec3Front))
	{
		// ���� �߽��� ���ϴ� Ÿ�� ���͸� �Ҵ�
		(*o_pTarVector3) = m_pNPCMapProject->GetTargetVectorForMapCenterPosition(&tmVec3Front);
		return TRUE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 1. (Front������ ���� + 20.0f)���� Front���Ϳ����� ���� ���̰� ������ �ʰ� �浹�� �߻��� ���̴�
	float	fMapHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&tmVec3Front);
#ifdef _DEBUG
//	if(tmVec3Front.y < fMapHeight)
//	{
//		DBGOUT("		�� �浹 üũ ���� ����(%d)\n", (int)(fMapHeight - tmVec3Front.y));
//	}
#endif // _DEBUG_endif

	if(tmVec3Front.y + MONSTER_MAP_IMPACK_HEIGHT_GAP < fMapHeight)
	{	// �浹�� �߻��Ͽ����Ƿ� ȸ���� ���͸� �������ش�.
							
		D3DXVECTOR3 tmVec3Nor = m_pNPCMapProject->GetNormalVectorWithMapTile(&tmVec3Front);
		CNPCMapProject::ChangePlaneUnitVec3(o_pTarVector3, &tmVec3Nor, &i_pNMon->m_MoveTargetVector);
		///////////////////////////////////////////////////////////////////////////////
		// Ÿ���� ���� ���͸� ���ϰ� ��� ���� ���ͷ� �����
		// 1. ���� ���Ͱ� �ƴϸ� ���͸� ���� �ø���.
		// 2. ���� ���ʹ� ��� ���� ���͸� ���ϴܴ�				
		if(FORM_GROUND_MOVE != i_pNMon->CurrentMonsterForm)
		{
			o_pTarVector3->y = RANDF2(0.20f, 0.50f);					// 0.1f ~ 0.3f �� ���� ������
			D3DXVec3Normalize(o_pTarVector3, o_pTarVector3);
		}
		return TRUE;
	}
	
	return FALSE;
}


BOOL CNPCMapChannel::CheckImpactStraightLineMapAndObjects(D3DXVECTOR3 *vMonPos
														  , D3DXVECTOR3 *vTarPos
														   , INT i_nExcludeObjNum
														   , BOOL bFlagObjectCheck/*=TRUE*/)
{
	D3DXVECTOR3	vVel, vPos;
	int			cont = 4;
	float		fLength;

	vVel = *vTarPos - *vMonPos;
	cont = (int)(D3DXVec3Length(&vVel)/SIZE_MAP_TILE_SIZE) + 1;
	fLength = D3DXVec3Length(&vVel)/cont;		// �ѹ��� üũ�� �Ÿ��� ���Ѵ�
	D3DXVec3Normalize(&vVel, &vVel);			// ���� ���͸� ���Ѵ�.
	int i=1;
	while(i < cont)
	{
		vPos = *vMonPos + i*fLength*vVel;
		if(FALSE == m_pNPCMapProject->IsValidPosition(&vPos)
			|| vPos.y < m_pNPCMapProject->GetMapHeightIncludeWater(&vPos))
		{// ��ȿ�� ��ǥ�� �ƴϰų� Ȥ�� ���� ���� ���� ����

			return TRUE;
		}
		i++;
	}
	if(bFlagObjectCheck
		&& TRUE == CheckImpactPositionObjects(vMonPos, vTarPos, i_nExcludeObjNum))
	{// ������Ʈ���� �浹 �߻���
		
		return TRUE;
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
// ���Ͱ� Attack�� Object���� �浹�� üũ
BOOL CNPCMapChannel::CheckImpactPositionObjects(D3DXVECTOR3 *i_pVec3Start, D3DXVECTOR3 *i_pVec3End, INT i_nExcludeObjNum)
{
	if(FALSE == m_pNPCMapProject->IsValidPosition(i_pVec3End->x, i_pVec3End->z))
	{// �������� ��ȿ�� üũ�� �ʿ����

		return TRUE;
	}

	D3DXVECTOR3 tmUnitVec3 = *i_pVec3End - *i_pVec3Start;
	float fLength = D3DXVec3Length(&tmUnitVec3);
	D3DXVec3Normalize(&tmUnitVec3, &tmUnitVec3);
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!! �ذ� ���� ����
//	D3DXVECTOR3 retedUnitVec3 = m_pNPCMapProject->CheckCollisionMesh(i_pVec3Start, &tmUnitVec3, fLength, i_nExcludeObjNum);
	D3DXVECTOR3 retedUnitVec3 = m_pNPCMapProject->CheckCollisionMesh(i_pVec3Start, &tmUnitVec3, fLength, i_nExcludeObjNum, &m_mtDeletedObjectInfoList, &m_mtNewObjectInfoList);	// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ
	if(retedUnitVec3 != D3DXVECTOR3(0,0,0)) 
	{
		return TRUE;
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// ���Ͱ� �̵��� Object ���� �浹 ó��
BOOL CNPCMapChannel::CheckAndModifyImpactPositionObjects(CNPCMonster *pMon)
{
	if(FALSE == pMon->m_MoveInfo.MovableFlag
		|| pMon->PositionVector == pMon->m_BeforePosition)
	{
		return FALSE;
	}

//	�浹�� ���� ���� ���͸� �޴´�. 2004.07.03 jschoi
	D3DXVECTOR3 tmUnitVec3, retedUnitVec3;
	D3DXVec3Normalize(&tmUnitVec3, &(pMon->PositionVector-pMon->m_BeforePosition));
	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!! �ذ� ���� ����
//	retedUnitVec3 = m_pNPCMapProject->CheckCollisionMesh(&pMon->m_BeforePosition, &tmUnitVec3
//		, pMon->MonsterInfoPtr->Size + pMon->GetCurrentSpeed(), DEFAULT_OBJECT_MONSTER_OBJECT+pMon->MonsterInfoPtr->MonsterUnitKind);
	retedUnitVec3 = m_pNPCMapProject->CheckCollisionMesh(&pMon->m_BeforePosition, &tmUnitVec3
		, pMon->MonsterInfoPtr->Size + pMon->GetCurrentSpeed(), DEFAULT_OBJECT_MONSTER_OBJECT+pMon->MonsterInfoPtr->MonsterUnitKind, &m_mtDeletedObjectInfoList, &m_mtNewObjectInfoList);	// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ
	if(retedUnitVec3 != D3DXVECTOR3(0,0,0)) 
	{
		///////////////////////////////////////////////////////////////////////////////
		// �浹 ���� �������Ϳ� �����̵� TargetVector�� �� ���̸� ���Ѵ�.		
		float fAngle = ACOS(D3DXVec3Dot(&tmUnitVec3, &retedUnitVec3));
		if(fAngle >= PI/4)
		{// �����̰� PI/4���� ũ�ٸ� ������Ʈ ������ ������ ��Ȳ�̹Ƿ� ������ǥ�� ������ ������ �������� �����Ѵ�.

			pMon->PositionVector = pMon->m_BeforePosition;		
			CNPCMonster::GetRandomVector(&tmUnitVec3);
			pMon->SetMoveTargetVector(&tmUnitVec3);
			if(pMon->m_nTargetIndex == 0)
			{// ���ݽð� �ƴϸ� ���� TargetVector�� �����Ѵ�
				
				pMon->SetEnforceTargetVector(&tmUnitVec3, pMon->GetSpeed(), MSS_MAP_IMPACT);
			}
			return TRUE;
		}
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
// �Լ��� Ŭ����
//	ĳ���Ͱ� �Ÿ��ȿ� �ְ� ��ȿ�ϸ� �����Ѵ�.
//
///////////////////////////////////////////////////////////////////////////////
class find_if_functor_NPCCharacterExistInRange
{
public:
	find_if_functor_NPCCharacterExistInRange(CNPCMapChannel *i_pNMapChann, D3DXVECTOR3 *i_pPos, float i_fBoundary)
		:m_pNMapChannel(i_pNMapChann), m_pVec3Pos(i_pPos), m_fBoundaryDistance(i_fBoundary)
	{
	};
	bool operator()(ClientIndex_t index)
	{
		CLIENT_INFO		*pClient = m_pNMapChannel->GetClientInfo(index);
		if(pClient
			&& pClient->ClientState != CS_NULL)
		{	// Ŭ���̾�Ʈ�� ��ȿ �� ���

			///////////////////////////////////////////////////////////////////////////////
			// ������ �Ÿ��� ���Ͽ� ���Ѵ�.
			D3DXVECTOR3	vec3Tm = *m_pVec3Pos - pClient->PositionVector;
			vec3Tm.y = 0.0f;
			if(m_fBoundaryDistance > D3DXVec3Length(&vec3Tm))
			{
				return true;
			}
		}
		return false;
	}

	CNPCMapChannel			*m_pNMapChannel;
	D3DXVECTOR3				*m_pVec3Pos;
	float					m_fBoundaryDistance;
};

// ������ ĳ���Ͱ� �ִ��� üũ�ϴ� �Լ�
BOOL CNPCMapChannel::NPCCharacterExistInRange(D3DXVECTOR3 *pPos, int nBlockGap)
{
	TWO_BLOCK_INDEXES	blockIdx;
	int					i, j;

	m_pNPCMapProject->GetBlockAdjacentToPositionHalfDistance(pPos->x, pPos->z, nBlockGap, blockIdx);

	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			CMapBlock	*pMapBlock = &m_arrMapBlock[i][j];
			if(false == pMapBlock->m_CharacterIndexMtlist.empty())
			{				
				pMapBlock->m_CharacterIndexMtlist.lock();
				{
					mtlistUnitIndex_t::iterator itr = find_if(pMapBlock->m_CharacterIndexMtlist.begin(), pMapBlock->m_CharacterIndexMtlist.end()
					, find_if_functor_NPCCharacterExistInRange(this, pPos, nBlockGap/2));
					if(itr != pMapBlock->m_CharacterIndexMtlist.end())
					{
						pMapBlock->m_CharacterIndexMtlist.unlock();
						return TRUE;
					}
				}
				pMapBlock->m_CharacterIndexMtlist.unlock();
			}		
			j++;
		}
		i++;
	}
	
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
// �Լ��� Ŭ����
//	ĳ���Ͱ� �Ÿ��ȿ� �ְ� ��ȿ�ϸ� �,������,������ ������ �ƴϸ� Vector�� �߰�
// 2010-04-01 by cmkwon, ����2�� �߰� ���� - ����/�Ʊ� ����Ʈ �������� �÷��� �߰�
//
///////////////////////////////////////////////////////////////////////////////
class for_each_functor_NPCGetAdjacentCharacterIndexes
{
public:
	for_each_functor_NPCGetAdjacentCharacterIndexes(CNPCMapChannel *i_pNMapChann, D3DXVECTOR3 *i_pPos, float i_fBoundary, vector<ClientIndex_t> *i_pIndexVector, BYTE i_AttMonsterBell, BOOL i_bGetEnemyList)
		:m_pNMapChannel(i_pNMapChann), m_pVec3Pos(i_pPos), m_fBoundaryDistance(i_fBoundary), m_pClientIndexVector(i_pIndexVector), m_attMonsterBell(i_AttMonsterBell), m_bGetEnemyList(i_bGetEnemyList)		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
	{
	};
	void operator()(ClientIndex_t index)
	{
		CLIENT_INFO		*pClient = m_pNMapChannel->GetClientInfo(index);
		if(NULL == pClient
			|| CS_GAMESTARTED != pClient->ClientState
			|| COMPARE_BODYCON_BIT(pClient->BodyCondition, BODYCON_DEAD_MASK))
		{// Ŭ���̾�Ʈ�� ��ȿ �� ���
			return;
		}

		if(IS_VALID_UNIQUE_NUMBER(m_pNMapChannel->m_CityWarOccupyGuildUID) 
			&& m_pNMapChannel->m_CityWarOccupyGuildUID == pClient->GuildUID10)
		{// ���� ���ܿ��� ��� ����
			return;
		}

// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - ���ڽ� ����üũ�� ���� ó���Ѵ�.
// 		///////////////////////////////////////////////////////////////////////////////
// 		// 2007-01-16 by cmkwon, �κ����� ������ ������ ����Ʈ�� �߰��ؾ���
// 		if(FALSE == m_pNMapChannel->m_bCityWarStarted
// 			&& FALSE == pClient->IsTargetableCharacter(TRUE))		// 2006-11-27 by dhjin, ������(pClient->bStealthState -> ptmClient->IsTargetableCharacter())
// 		{// ���������� �������� �ƴϰ� ���ڽ� ���¶�� ����
// 			return;
// 		}

		///////////////////////////////////////////////////////////////////////////////
		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
		if(m_bGetEnemyList)
		{
			///////////////////////////////////////////////////////////////////////////////
			// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - ���¸��� �� ��� ���� ������ ����
			if(IS_INFLWAR_MONSTER(m_attMonsterBell)
				&& IS_SAME_CHARACTER_MONSTER_INFLUENCE(pClient->InfluenceType1, m_attMonsterBell))
			{
				return;
			}

 			///////////////////////////////////////////////////////////////////////////////
 			// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - BELL_INFINITY_DEFENSE_MONSTER�� ĳ���Ͱ� �Ʊ���
 			if(BELL_INFINITY_DEFENSE_MONSTER == m_attMonsterBell)
 			{
 				return;
 			}
		}
		else
		{
			///////////////////////////////////////////////////////////////////////////////
			// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - ���¸��� �� ��� ���� ������ ����
			if(IS_INFLWAR_MONSTER(m_attMonsterBell)
				&& (INFLUENCE_TYPE_NORMAL != pClient->InfluenceType1 || FALSE == IS_SAME_CHARACTER_MONSTER_INFLUENCE(pClient->InfluenceType1, m_attMonsterBell)))
			{
				return;
			}

			if(BELL_INFINITY_ATTACK_MONSTER == m_attMonsterBell)
			{
				return;
 			}
		}
		
		if(m_fBoundaryDistance >= D3DXVec3Length(&(*m_pVec3Pos - pClient->PositionVector)))
		{
			m_pClientIndexVector->push_back(index);
		}				
	}

	CNPCMapChannel			*m_pNMapChannel;
	D3DXVECTOR3				*m_pVec3Pos;
	float					m_fBoundaryDistance;
	vector<ClientIndex_t>	*m_pClientIndexVector;
	BYTE					m_attMonsterBell;		// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
	BOOL					m_bGetEnemyList;		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
};

// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - �����߰�(, BYTE i_AttMonsterBell)
// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
int CNPCMapChannel::NPCGetAdjacentCharacterIndexes(D3DXVECTOR3 *pPos, int nDistance, int nBlockDistance, vector<ClientIndex_t> *pClientIndexVector, BYTE i_AttMonsterBell, BOOL i_bGetEnemyList/*=TRUE*/)
{
	TWO_BLOCK_INDEXES	blockIdx;
	int					i, j;

#ifdef _DEBUG
	int tmpCap = pClientIndexVector->capacity();
	pClientIndexVector->clear();
	int tmpCap2 = pClientIndexVector->capacity();
	assert( tmpCap == tmpCap2 );
#endif

	m_pNPCMapProject->GetBlockAdjacentToPositionHalfDistance(pPos->x, pPos->z, nBlockDistance, blockIdx);

	pClientIndexVector->clear();
	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			CMapBlock	*pMapBlock = &m_arrMapBlock[i][j];

			if (false == pMapBlock->m_CharacterIndexMtlist.empty())
			{
				mtlistUnitIndex_t vectorTemp;
				pMapBlock->m_CharacterIndexMtlist.lock();
				{
					vectorTemp.reserve(pMapBlock->m_CharacterIndexMtlist.size());
					vectorTemp.insert(vectorTemp.end()
						, pMapBlock->m_CharacterIndexMtlist.begin(), pMapBlock->m_CharacterIndexMtlist.end());
				}
				pMapBlock->m_CharacterIndexMtlist.unlock();
				
				for_each(vectorTemp.begin(), vectorTemp.end()
					, for_each_functor_NPCGetAdjacentCharacterIndexes(this, pPos, nDistance, pClientIndexVector, i_AttMonsterBell, i_bGetEnemyList));
			}
			j++;
		}
		i++;
	}

	return pClientIndexVector->size();
}


////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CNPCMapProject::NPCMonsterExistInRange
// ��ȯ�Ǵ� ��  : BOOL
// �� �� �� ��  : int nMonsterIdx
// �� �� �� ��  : D3DXVECTOR3 posVector3
// �� �� �� ��  : float fDisGap ==> �浹 ó�� ����� ���� �Ÿ�
// �� �� �� ��  : float fBlockGap ==> Block�� ������ �Ÿ�
// �� �� �� ��  : �Էµ� ��ǥ�� ���� �Ÿ� �ȿ� ���Ͱ� �ִ����� ����
//
CMonster* CNPCMapChannel::NPCMonsterExistInRange(int nMonsterIdx, const D3DXVECTOR3 *pPositionVector3, float fDisGap, float fBlockGap)
{
	TWO_BLOCK_INDEXES	blockIdx;
	CMonster			*pMonster = NULL;
	int					i, j;
	CMapBlock			*pMapBlock = NULL;

	m_pNPCMapProject->GetBlockAdjacentToPositionHalfDistance(pPositionVector3->x, pPositionVector3->z, fBlockGap, blockIdx);

	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			pMapBlock = &m_arrMapBlock[i][j];

			if (false == pMapBlock->m_MonsterIndexMtlist.empty())
			{
				mtlistUnitIndex_t	vectorTemp;				
				pMapBlock->m_MonsterIndexMtlist.lock();
				{
					vectorTemp.reserve(pMapBlock->m_MonsterIndexMtlist.size());
					vectorTemp.insert(vectorTemp.end()
						, pMapBlock->m_MonsterIndexMtlist.begin(), pMapBlock->m_MonsterIndexMtlist.end());					
				}
				pMapBlock->m_MonsterIndexMtlist.unlock();

				mtlistUnitIndex_t::iterator itr = vectorTemp.begin();
				while(itr != vectorTemp.end())
				{
					if(*itr != nMonsterIdx)
					{
						pMonster = GetMonster(*itr);
						if(pMonster && pMonster->m_enMonsterState != MS_NULL)
						{ // Ŭ���̾�Ʈ�� ��ȿ �� ���
							
							if(D3DXVec3Length(&(*pPositionVector3 - pMonster->PositionVector)) < fDisGap)
							{
								return pMonster;
							}
						}
					}
					itr++;
				}
			}
			j++;
		}
		i++;
	}

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
// �Լ��� Ŭ����
//	���Ͱ� �Ÿ��ȿ� �ְ� ��ȿ�ϸ� Vector�� �߰�
//
///////////////////////////////////////////////////////////////////////////////
class for_each_functor_NPCGetAdjacentMonsterIndexes
{
public:
	for_each_functor_NPCGetAdjacentMonsterIndexes(CNPCMapChannel *i_pNMapChann, D3DXVECTOR3 *i_pPos, float i_fBoundary, vector<ClientIndex_t> *i_pIndexVector, INT i_unitKind)
		:m_pNMapChannel(i_pNMapChann), m_pVec3Pos(i_pPos), m_fBoundaryDistance(i_fBoundary), m_pClientIndexVector(i_pIndexVector), m_MonUnitKind(i_unitKind)
	{
	};
	void operator()(ClientIndex_t index)
	{
		CMonster *pMonst = m_pNMapChannel->GetMonster(index);
		if( pMonst
			&& pMonst->m_enMonsterState != MS_NULL
			&& COMPARE_BODYCON_BIT(pMonst->BodyCondition, BODYCON_DEAD_MASK) == FALSE
			&& (0==m_MonUnitKind || m_MonUnitKind == pMonst->MonsterInfoPtr->MonsterUnitKind) )
		{	// ���Ͱ� ��ȿ �� ���
			
			if(m_fBoundaryDistance >= D3DXVec3Length(&(*m_pVec3Pos - pMonst->PositionVector)))
			{
				m_pClientIndexVector->push_back(index);
			}
		}
	}

	CNPCMapChannel			*m_pNMapChannel;
	D3DXVECTOR3				*m_pVec3Pos;
	float					m_fBoundaryDistance;
	vector<ClientIndex_t>	*m_pClientIndexVector;
	INT						m_MonUnitKind;
};

////////////////////////////////////////////////////////////////////////////////
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
///////////////////////////////////////////////////////////////////////////////
// �Լ��� Ŭ����
//	���Ͱ� �Ÿ��ȿ� �ְ� ��ȿ�ϸ� Vector�� �߰�
//
///////////////////////////////////////////////////////////////////////////////
class for_each_functor_NPCGetAdjacentMonsterIndexesByBell
{
public:
	for_each_functor_NPCGetAdjacentMonsterIndexesByBell(CNPCMapChannel *i_pNMapChann, D3DXVECTOR3 *i_pPos, float i_fBoundary, vector<ClientIndex_t> *i_pIndexVector, BYTE i_Bell)
		:m_pNMapChannel(i_pNMapChann), m_pVec3Pos(i_pPos), m_fBoundaryDistance(i_fBoundary), m_pClientIndexVector(i_pIndexVector), m_Bell(i_Bell)
	{
	};
	void operator()(ClientIndex_t index)
	{
		CMonster *pMonst = m_pNMapChannel->GetMonster(index);
		if( pMonst
			&& pMonst->m_enMonsterState != MS_NULL
			&& COMPARE_BODYCON_BIT(pMonst->BodyCondition, BODYCON_DEAD_MASK) == FALSE
			&& m_Bell == pMonst->MonsterInfoPtr->Belligerence)
		{	// ���Ͱ� ��ȿ �� ���
			
			if(m_fBoundaryDistance >= D3DXVec3Length(&(*m_pVec3Pos - pMonst->PositionVector)))
			{
				m_pClientIndexVector->push_back(index);
			}
		}
	}
	
	CNPCMapChannel			*m_pNMapChannel;
	D3DXVECTOR3				*m_pVec3Pos;
	float					m_fBoundaryDistance;
	vector<ClientIndex_t>	*m_pClientIndexVector;
	BYTE					m_Bell;
};


int CNPCMapChannel::NPCGetAdjacentMonsterIndexes(D3DXVECTOR3 *pPos
												 , int nDistance
												 , int nBlockDistance
												 , vector<ClientIndex_t> *pClientIndexVector
												 , INT i_MonsterUnitKind/*=0*/)
{
	TWO_BLOCK_INDEXES	blockIdx;
	int					i, j;

#ifdef _DEBUG
	int tmpCap = pClientIndexVector->capacity();
	pClientIndexVector->clear();
	int tmpCap2 = pClientIndexVector->capacity();
	assert( tmpCap == tmpCap2 );
#endif

	m_pNPCMapProject->GetBlockAdjacentToPositionHalfDistance(pPos->x, pPos->z, nBlockDistance, blockIdx);

	pClientIndexVector->clear();
	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			CMapBlock	*pMapBlock = &m_arrMapBlock[i][j];

			if (false == pMapBlock->m_MonsterIndexMtlist.empty())
			{
				mtlistUnitIndex_t vectorTemp;
				pMapBlock->m_MonsterIndexMtlist.lock();
				{
					vectorTemp.reserve(pMapBlock->m_MonsterIndexMtlist.size());
					vectorTemp.insert(vectorTemp.end()
						, pMapBlock->m_MonsterIndexMtlist.begin(), pMapBlock->m_MonsterIndexMtlist.end());
				}
				pMapBlock->m_MonsterIndexMtlist.unlock();

				for_each(vectorTemp.begin(), vectorTemp.end()
					, for_each_functor_NPCGetAdjacentMonsterIndexes(this, pPos, nDistance, pClientIndexVector, i_MonsterUnitKind));
			}
			j++;
		}
		i++;
	}

	return pClientIndexVector->size();
}

////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CNPCMapProject::NPCGetMonsterCountInRegion
// ��ȯ�Ǵ� ��  : int
// �� �� �� ��  : int tileStartXIdx
// �� �� �� ��  : int tileStartZIdx
// �� �� �� ��  : int tileEndXIdx
// �� �� �� ��  : int tileEndZIdx
// �� �� �� ��  : UINT nMonType
// �� �� �� ��  : ���ڷ� �־��� Ÿ�� ������ nMonType�� ������ Count�� �����Ѵ�
//
int CNPCMapChannel::NPCGetMonsterCountInRegion(int tileStartXIdx, int tileStartZIdx, int tileEndXIdx, int tileEndZIdx, int nMonType, int nMaxCount)
{
	TWO_BLOCK_INDEXES	blockIdx;
	int					i, j;
	int					nCount = 0;
	CMonster			*pMonster = NULL;

	m_pNPCMapProject->GetBlockIndexWithTileIndex(tileStartXIdx, tileStartZIdx, tileEndXIdx, tileEndZIdx, blockIdx);
	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			CMapBlock *pMapBlock = &(m_arrMapBlock[i][j]);
			// ���Ͱ� ������ �Ѿ
			if (false == pMapBlock->m_MonsterIndexMtlist.empty())
			{
				mtlistUnitIndex_t vectorTemp;
				pMapBlock->m_MonsterIndexMtlist.lock();
				{
					vectorTemp.reserve(pMapBlock->m_MonsterIndexMtlist.size());
					vectorTemp.insert(vectorTemp.end()
						, pMapBlock->m_MonsterIndexMtlist.begin(), pMapBlock->m_MonsterIndexMtlist.end());
				}
				pMapBlock->m_MonsterIndexMtlist.unlock();

				mtlistUnitIndex_t::iterator itr = vectorTemp.begin();
				while (itr != vectorTemp.end())
				{
					pMonster = GetMonster(*itr);
					if(NULL != pMonster 
						&& pMonster->MonsterInfoPtr->MonsterUnitKind == nMonType)
					{
						nCount++;
						if(nCount >= nMaxCount)
						{
							return nCount;
						}
					}
					itr++;
				}
			}
			j++;
		}
		i++;
	}

	return nCount;
}


////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CNPCMapProject::NPCGetCreatablePosition
// ��ȯ�Ǵ� ��  : int
// �� �� �� ��  : UINT nMonType
// �� �� �� ��  : int tileStartXIdx
// �� �� �� ��  : int tileStartZIdx
// �� �� �� ��  : int tileEndXIdx
// �� �� �� ��  : int tileEndZIdx
// �� �� �� ��  : vector<D3DXVECTOR3> &vecVECTOR2
// �� �� �� ��  : int nMaxCount
// �� �� �� ��  : ���ڷ� �־��� Ÿ�� �������� ���� Ÿ�Կ� �´� ���� ������ ��ǥ�� vecVector2�� �߰��ϰ� �� ����� �����Ѵ�
//
int CNPCMapChannel::NPCGetCreatablePosition(BYTE nMonsterForm, int nMonsterSize
											, int tileStartXIdx, int tileStartZIdx
											, int tileEndXIdx, int tileEndZIdx
											, int nMinHeight, int nMaxHeight
											, vector<D3DXVECTOR3> &vecVECTOR2, int nMaxCount
											, BOOL bCharCheckFlag/*=TRUE*/
											, BOOL i_bAbsoluteAltitude/*=FALSE*/)
{
	int			nCount = 0;
	float		fHeight = 0.0f;
	D3DXVECTOR3	tmpVector3;
	D3DXVECTOR3 tmUnitVec3(1, 0, 0);
	BOOL		bInsertFlag;

	vecVECTOR2.clear();
	while((int)vecVECTOR2.size() < nMaxCount 
		&& nCount < nMaxCount * 2)
	{
		bInsertFlag		= FALSE;
		int nRandx = rand();
		tmpVector3.x = (float)( tileStartXIdx*SIZE_MAP_TILE_SIZE + nRandx%((tileEndXIdx - tileStartXIdx)*SIZE_MAP_TILE_SIZE) );
		tmpVector3.z = (float)( tileStartZIdx*SIZE_MAP_TILE_SIZE + rand()%((tileEndZIdx - tileStartZIdx)*SIZE_MAP_TILE_SIZE) );
		tmpVector3.y = 0.0f;
		if(FALSE == m_pNPCMapProject->IsValidTileForCreateMonster(&tmpVector3)
			|| (TRUE == bCharCheckFlag && TRUE == NPCCharacterExistInRange(&tmpVector3, SIZE_MONSTER_CREATION_RANGE * 2)))
		{	// ���� �̵� �Ұ� �������� üũ
			// ������ ĳ���� �ִ��� üũ
			
			nCount++;
			continue;
		}
		fHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&tmpVector3);
		
		switch(nMonsterForm)
		{
		case FORM_FLYING_RIGHT:
		case FORM_FLYINGandGROUND_RIGHT:
		case FORM_FLYING_COPTER:
		case FORM_FLYINGandGROUND_COPTER:
			{
				if(FALSE == i_bAbsoluteAltitude)
				{
					tmpVector3.y	= fHeight + nMinHeight + nRandx%(nMaxHeight-nMinHeight);
					bInsertFlag		= TRUE;
				}
				else
				{
					if(fHeight < nMinHeight)
					{
						tmpVector3.y = nMinHeight + nRandx%(nMaxHeight - nMinHeight);						
						bInsertFlag	= TRUE;
					}
					else if(fHeight+5 < nMaxHeight)
					{
						tmpVector3.y = fHeight + nRandx%(int(nMaxHeight - fHeight));						
						bInsertFlag	= TRUE;
					}
				}
			}
			break;
		case FORM_GROUND_MOVE:
			{
				tmpVector3.y	= fHeight + nMonsterSize;
				bInsertFlag		= TRUE;
			}
			break;
		case FORM_SWIMMINGFLYING_RIGHT:
		case FORM_SWIMMINGFLYING_COPTER:
			{
				if(FALSE == i_bAbsoluteAltitude)
				{
					if(m_pNPCMapProject->IsWaterTile(&tmpVector3))
					{
						float fMapHeight = m_pNPCMapProject->GetMapHeightExcludeWater(&tmpVector3);
						if(fMapHeight+SIZE_MAP_TILE_SIZE < fHeight)
						{
							tmpVector3.y	= fHeight - SIZE_MAP_TILE_SIZE/2;							
						}
						else
						{
							tmpVector3.y	= fMapHeight + SIZE_MAP_TILE_SIZE/2;
						}
						bInsertFlag			= TRUE;	
					}
					else
					{
						tmpVector3.y	= fHeight + nMinHeight + nRandx%(nMaxHeight-nMinHeight);
						bInsertFlag		= TRUE;
					}
				}
				else
				{
					if(fHeight < nMinHeight)
					{
						tmpVector3.y	= nMinHeight + nRandx%(nMaxHeight - nMinHeight);						
						bInsertFlag		= TRUE;
					}
					else if(fHeight+5 < nMaxHeight)
					{
						tmpVector3.y	= fHeight + nRandx%(int(nMaxHeight - fHeight));						
						bInsertFlag		= TRUE;
					}
				}				
			}
			break;
		}// end_switch(nMonsterForm)

		if(bInsertFlag)
		{
			vecVECTOR2.push_back(tmpVector3);			
		}

		nCount++;
	}// end_while((int)vecVECTOR2.size() < nMaxCount && nCount < nMaxCount * 2)

	return vecVECTOR2.size();
}


int CNPCMapChannel::NPCGetTargetwithAttackObj(BYTE AttackObj, CMonster *pM, vector<ClientIndex_t> &ClientIndexVector)
{
	if(ClientIndexVector.empty()){				return 0;}

// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - �Ʒ��� ���� ������.
// 	///////////////////////////////////////////////////////////////////////////////
// 	// 2007-05-22 by cmkwon, ����-->Ÿ�ٿ��� ������Ʈ �浹üũ �߰���
// 	CLIENT_INFO		*pCli = NULL;
// 	BOOL			bRecognizeInvisible = COMPARE_MPOPTION_BIT(pM->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE);
// 	vectClientIndex_t::iterator itr(ClientIndexVector.begin());
// 	while(itr != ClientIndexVector.end())
// 	{
// 		pCli = GetClientInfo(*itr);
// 		if(NULL == pCli
// 			|| FALSE == pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible)
// 			|| FALSE != CheckImpactStraightLineMapAndObjects(&pM->PositionVector, &pCli->PositionVector
// 				, DEFAULT_OBJECT_MONSTER_OBJECT+pM->MonsterInfoPtr->MonsterUnitKind))
// 		{
// 			itr = ClientIndexVector.erase(itr);
// 			continue;
// 		}
// 		itr++;
// 	}
// 	if(ClientIndexVector.empty()){				return 0;}
// 
// 	int				nRetTarget = 0;
// 	if(ClientIndexVector.size() == 1)
// 	{
// 		pCli = GetClientInfo(ClientIndexVector[0]);
// 		if(pCli
// 			&& pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible))
// 		{
// 			return ClientIndexVector[0];
// 		}
// 		return 0;
// 	}
// 
// 	switch(AttackObj)
// 	{
// 	case ATTACKOBJ_CLOSERANGE:
// 		{
// 			float	fDistance;
// 			float	fMinDistance = this->GetMonsterVisibleDiameterW();
// 			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
// 			while(itr != ClientIndexVector.end())
// 			{
// 				pCli = GetClientInfo(*itr);
// 				if(pCli
// 					&& pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible)
// 					&& (fDistance = D3DXVec3Length(&(pCli->PositionVector - pM->PositionVector))) < fMinDistance)
// 				{
// 					nRetTarget = *itr;
// 					fMinDistance = fDistance;
// 				}
// 				itr++;
// 			}
// 		}
// 		break;
// 	case ATTACKOBJ_LOWHP:
// 		{
// 			float	fMinHP = 65535.0f;
// 			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
// 			while(itr != ClientIndexVector.end())
// 			{
// 				pCli = GetClientInfo(*itr);
// 				if(pCli
// 					&& pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible)
// 					&& pCli->CurrentHP < fMinHP)
// 				{
// 					nRetTarget = *itr;
// 					fMinHP = pCli->CurrentHP;
// 				}
// 				itr++;
// 			}
// 		}
// 		break;
// 	case ATTACKOBJ_HIGHHP:
// 		{
// 			float	fMaxHP = 0.0f;
// 			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
// 			while(itr != ClientIndexVector.end())
// 			{
// 				pCli = GetClientInfo(*itr);
// 				if(pCli
// 					&& pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible)
// 					&& pCli->CurrentHP > fMaxHP)
// 				{
// 					nRetTarget = *itr;
// 					fMaxHP = pCli->CurrentHP;
// 				}
// 				itr++;
// 			}
// 		}
// 		break;
// 	default:
// 		// ATTACKOBJ_FIRSTATTACK
// 		// ATTACKOBJ_SAMERACE
// 		// ATTACKOBJ_RANDOM
// 		// ATTACKOBJ_AGGRO			// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
// 		{
// 			for(int i=0; i < 5; i++)
// 			{
// 				nRetTarget = ClientIndexVector[GetTickCount()%ClientIndexVector.size()];
// 				pCli = GetClientInfo(nRetTarget);
// 				if(pCli
// 					&& pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible))
// 				{
// 					return nRetTarget;
// 				}
// 			}
// 			nRetTarget = 0;
// 		}
// 	}
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
	CLIENT_INFO		*pCli = NULL;
	CNPCMonster		*pNPCMon = NULL;
	BOOL			bRecognizeInvisible = COMPARE_MPOPTION_BIT(pM->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE);
	BOOL			bRecognizeStealth =	COMPARE_MPOPTION_BIT(pM->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_STEALTH);	// 2012-11-05 by jhseol, ���ڽ� ������ �ɸ��͸� �ν��Ѵ�.
	vectClientIndex_t::iterator itr(ClientIndexVector.begin());
	while(itr != ClientIndexVector.end())
	{
		pCli		= NULL;
		pNPCMon		= NULL;
		ClientIndex_t tarIdx = *itr;
		if(FALSE == this->GetUnitObject(tarIdx, &pCli, &pNPCMon))
		{
			itr = ClientIndexVector.erase(itr);
			continue;
		}
		
		if(pCli)
		{
			if(FALSE == pCli->IsValidClient()
				|| FALSE == pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible, bRecognizeStealth)	// 2012-11-05 by jhseol, ���ڽ� ������ �ɸ��͸� �ν��Ѵ�. bRecognizeStealth ���� �߰�
				|| FALSE != CheckImpactStraightLineMapAndObjects(&pM->PositionVector, &pCli->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+pM->MonsterInfoPtr->MonsterUnitKind))
			{
				itr = ClientIndexVector.erase(itr);
				continue;
			}
		}
		if(pNPCMon)
		{
			if(FALSE == pNPCMon->IsValidMonster()
				|| FALSE != CheckImpactStraightLineMapAndObjects(&pM->PositionVector, &pNPCMon->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+pM->MonsterInfoPtr->MonsterUnitKind))
			{
				itr = ClientIndexVector.erase(itr);
				continue;
			}

		}
		itr++;
	}
	if(ClientIndexVector.empty()){					return 0;}


	int				nRetTarget = 0;
	if(ClientIndexVector.size() == 1)
	{
		return ClientIndexVector[0];
	}

	switch(AttackObj)
	{
	case ATTACKOBJ_CLOSERANGE:
		{
			float	fDistance;
			float	fMinDistance = this->GetMonsterVisibleDiameterW();
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			for(;itr != ClientIndexVector.end(); itr++)
			{
				pCli		= NULL;
				pNPCMon		= NULL;
				ClientIndex_t tarIdx = *itr;
				if(FALSE == this->GetUnitObject(tarIdx, &pCli, &pNPCMon))
				{
					continue;
				}
				if(pCli && pCli->IsValidClient())
				{
					fDistance = D3DXVec3Length(&(pCli->PositionVector - pM->PositionVector));
					if(fDistance < fMinDistance)
					{
						nRetTarget		= tarIdx;
						fMinDistance	= fDistance;
					}
				}

				if(pNPCMon && pNPCMon->IsValidMonster())
				{
					fDistance = D3DXVec3Length(&(pNPCMon->PositionVector - pM->PositionVector));
					if(fDistance < fMinDistance)
					{
						nRetTarget		= tarIdx;
						fMinDistance	= fDistance;
					}
				}
			}
		}
		break;
	case ATTACKOBJ_LOWHP:
		{
			float	fMinHP = 65535.0f;
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			for(;itr != ClientIndexVector.end(); itr++)
			{
				pCli		= NULL;
				pNPCMon		= NULL;
				ClientIndex_t tarIdx = *itr;
				if(FALSE == this->GetUnitObject(tarIdx, &pCli, &pNPCMon))
				{
					continue;
				}				
				if(pCli && pCli->IsValidClient())
				{
					if(pCli->CurrentHP < fMinHP)
					{
						nRetTarget	= tarIdx;
						fMinHP		= pCli->CurrentHP;
					}
				}
				if(pNPCMon && pNPCMon->IsValidMonster())
				{
					if(pNPCMon->CurrentHP < fMinHP)
					{
						nRetTarget	= tarIdx;
						fMinHP		= pNPCMon->CurrentHP;
					}
				}
			}
		}
		break;
	case ATTACKOBJ_HIGHHP:
		{
			float	fMaxHP = 0.0f;
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			for(;itr != ClientIndexVector.end(); itr++)
			{
				pCli		= NULL;
				pNPCMon		= NULL;
				ClientIndex_t tarIdx = *itr;
				if(FALSE == this->GetUnitObject(tarIdx, &pCli, &pNPCMon))
				{
					continue;
				}				
				if(pCli && pCli->IsValidClient())
				{
					if(pCli->CurrentHP > fMaxHP)
					{
						nRetTarget	= tarIdx;
						fMaxHP		= pCli->CurrentHP;
					}
				}
				if(pNPCMon && pNPCMon->IsValidMonster())
				{
					if(pNPCMon->CurrentHP > fMaxHP)
					{
						nRetTarget	= tarIdx;
						fMaxHP		= pNPCMon->CurrentHP;
					}
				}
			}
		}
		break;
	default:
		// ATTACKOBJ_FIRSTATTACK
		// ATTACKOBJ_SAMERACE
		// ATTACKOBJ_RANDOM
		// ATTACKOBJ_AGGRO			// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
		{
			nRetTarget = ClientIndexVector[GetTickCount()%ClientIndexVector.size()];
		}
	}

	return nRetTarget;
}



void CNPCMapChannel::NPCSetPartyPosition(CNPCMonster *pMons)
{
	CNPCMonster *pManager = GetNPCMonster(pMons->m_nPartyManagerIndex);
	if(NULL == pManager
		|| pManager->m_enMonsterState == MS_NULL
		|| COMPARE_BODYCON_BIT(pManager->BodyCondition, BODYCON_DEAD_MASK)
		|| 0 != pManager->m_nTargetIndex)
	{
		pMons->ResetPartyVariable();
	}

	const float fFormationFBInterval = 20.0f;		// ��� ������ ���� ����
	D3DXVECTOR3	vec3NewPos;
	D3DXVECTOR3	vec3Left90;
	D3DXVECTOR3	vec3Right90;
	float		fDist;
	switch(pManager->MonsterInfoPtr->MPOptionParam1)
	{
	case FORMATION_COLUMN:
		{
			if(1 == pMons->m_byPartyFormationIndex%2)
			{
				vec3NewPos = pManager->PositionVector - pManager->TargetVector*pManager->MonsterInfoPtr->Size*3*(1 + (pMons->m_byPartyFormationIndex>>1))
					- pManager->TargetVector*fFormationFBInterval*(1 + (pMons->m_byPartyFormationIndex>>1));
			}
			else
			{
				GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
				vec3Right90 = pManager->PositionVector + vec3Right90*pManager->MonsterInfoPtr->Size + vec3Right90*fFormationFBInterval;
				vec3NewPos = vec3Right90 - pManager->TargetVector*pManager->MonsterInfoPtr->Size*3*(pMons->m_byPartyFormationIndex>>1)
					- pManager->TargetVector*fFormationFBInterval*(pMons->m_byPartyFormationIndex>>1);
			}
		}
		break;
	case FORMATION_LINE:
		{
			if(1 == pMons->m_byPartyFormationIndex%2)
			{
				GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
				vec3NewPos = pManager->PositionVector + vec3Right90*pManager->MonsterInfoPtr->Size*(1 + (pMons->m_byPartyFormationIndex>>1))
					+vec3Right90*fFormationFBInterval*(1 + (pMons->m_byPartyFormationIndex>>1));
			}
			else
			{
				GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
				vec3NewPos = pManager->PositionVector - pManager->TargetVector*pManager->MonsterInfoPtr->Size*3
					+ vec3Right90*pManager->MonsterInfoPtr->Size*(pMons->m_byPartyFormationIndex>>1) + vec3Right90*fFormationFBInterval*(pMons->m_byPartyFormationIndex>>1);
			}
		}
		break;
	case FORMATION_TRIANGLE:
		{
			switch(pMons->m_byPartyFormationIndex)
			{
			case 0:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 1:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 2:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 3:
				{
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2;
				}
				break;
			case 4:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 5:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
				break;
			case 6:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 7:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			default:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
			}
		}
		break;
	case FORMATION_INVERTED_TRIANGLE:
		{
			switch(pMons->m_byPartyFormationIndex)
			{
			case 0:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						+ vec3Right90*(pManager->MonsterInfoPtr->Size+fFormationFBInterval);
				}
				break;
			case 1:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 2:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2;
				}
				break;
			case 3:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
				break;
			case 4:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 5:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3;
				}
				break;
			case 6:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*5/2;
				}
				break;
			case 7:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2;
				}
				break;
			default:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
			}
		}
		break;
	case FORMATION_BELL:
		{
			switch(pMons->m_byPartyFormationIndex)
			{
			case 0:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 1:
				{
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 2:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 3:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
				break;
			case 4:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 5:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 6:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
				break;
			case 7:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*5/2
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			default:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*5/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
			}
		}
		break;
	case FORMATION_INVERTED_BELL:
		{
			switch(pMons->m_byPartyFormationIndex)
			{
			case 0:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 1:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 2:
				{
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 3:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval);
				}
				break;
			case 4:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*2;
				}
				break;
			case 5:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Left90, &pManager->TargetVector, MSD_RIGHT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Left90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 6:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
				break;
			case 7:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*3/2;
				}
				break;
			default:
				{
					GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
					vec3NewPos = pManager->PositionVector
						- pManager->TargetVector*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)*5/2
						+ vec3Right90*(pManager->MonsterInfoPtr->Size + fFormationFBInterval)/2;
				}
			}
		}
		break;
	default:
		{	// FORMATION_COLUMN�� ���� ó��
			if(1 == pMons->m_byPartyFormationIndex%2)
			{
				vec3NewPos = pManager->PositionVector - pManager->TargetVector*pManager->MonsterInfoPtr->Size*(1 + (pMons->m_byPartyFormationIndex>>1))
					- pManager->TargetVector*fFormationFBInterval*(1 + (pMons->m_byPartyFormationIndex>>1));
			}
			else
			{
				GNPCRotateTargetVectorHorizontal(&vec3Right90, &pManager->TargetVector, MSD_LEFT_90, 0);
				vec3Right90 = pManager->PositionVector + vec3Right90*pManager->MonsterInfoPtr->Size + vec3Right90*fFormationFBInterval;
				vec3NewPos = vec3Right90 - pManager->TargetVector*pManager->MonsterInfoPtr->Size*(pMons->m_byPartyFormationIndex>>1)
					- pManager->TargetVector*fFormationFBInterval*(pMons->m_byPartyFormationIndex>>1);
			}
		}
	}

	pMons->TargetVector = pManager->TargetVector;
	fDist = D3DXVec3Length(&(vec3NewPos - pMons->PositionVector));
	if(fDist > MONSTER_MAX_PARTY_DISTANCE/2)
	{
		D3DXVec3Normalize(&vec3Right90, &(vec3NewPos - pMons->PositionVector));
		pMons->PositionVector = pMons->PositionVector + vec3Right90 * fDist/2;
	}
	else
	{
		pMons->PositionVector = vec3NewPos;
	}
}

// 2009-09-09 ~ 2010-01-13 by dhjin, ���Ǵ�Ƽ - ��ȯ ���ݵ� HPAction��� �����ϰ� ����, �ذ� ���� CMonster -> CNPCMonster�� ����
// BOOL CNPCMapChannel::NPCMonsterAttackSkill(CMonster *pMonster, ITEM *pSkillItem)
BOOL CNPCMapChannel::NPCMonsterAttackSkill(CNPCMonster *pMonster, ITEM *pSkillItem)
{
// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
//	switch(pSkillItem->DestParameter1)
	switch(pSkillItem->ArrDestParameter[0])
	{
	case DES_SUMMON:
		{
			// 2009-09-09 ~ 2010-01-13 by dhjin, ���Ǵ�Ƽ - ��ȯ ���ݵ� HPAction��� �����ϰ� ����
			pMonster->m_HPAction.SetSuccessAttackItemIdxHPRate();
			HPACTION_TALK_HPRATE MsgTalk;
			MEMSET_ZERO(&MsgTalk, sizeof(HPACTION_TALK_HPRATE));
			if(pMonster->m_HPAction.GetHPTalkAttack(pSkillItem->ItemNum, MsgTalk.HPTalk, &MsgTalk.HPCameraTremble)) {
				// Attack�� ����.
				MsgTalk.HPTalkImportance	= HPACTION_TALK_IMPORTANCE_CHANNEL;
				this->SendFSvrHPTalk(pMonster, &MsgTalk);
			}

			// start 2011-03-30 by hskim, ���Ǵ�Ƽ 3�� - ���� Ȯ���� ��ȯ ��� �߰� - Ȯ�� �� ����
			//float nRandVal = RANDF1(0.0f, 100.0f);		// �Ҽ������� ó���� �ʿ䰡 ������?

			//DBGOUT("[%d][%s] ���� ��ȯ Ȯ�� [%4.2f > %4.2f]", pSkillItem->ItemNum, pSkillItem->ItemName, pSkillItem->HitRate, nRandVal);
			//if( nRandVal > pSkillItem->HitRate )
			//{		
			//	DBGOUT("==> ��ȯ ����\n");
			//	break;
			//}
			//DBGOUT("====================> ��ȯ ����\n");
			// end 2011-03-30 by hskim, ���Ǵ�Ƽ 3�� - ���� Ȯ���� ��ȯ ��� �߰�

			MSG_FN_ADMIN_SUMMON_MONSTER tmSummonMonster;
			tmSummonMonster.ChannelIndex			= m_MapChannelIndex.ChannelIndex;
			STRNCPY_MEMSET(tmSummonMonster.CharacterName, pMonster->MonsterInfoPtr->MonsterName, SIZE_MAX_CHARACTER_NAME);
// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
//			tmSummonMonster.MonsterUnitKind			= pSkillItem->ParameterValue1;
			tmSummonMonster.MonsterUnitKind			= pSkillItem->ArrParameterValue[0];
			tmSummonMonster.MonsterTargetType1		= MONSTER_TARGETTYPE_NORMAL;
			tmSummonMonster.TargetTypeData1			= 0;
			tmSummonMonster.CltIdxForTargetType1	= 0;

			// 2010. 06. 08 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (�Ʊ� ���� �뷱�� ����.) - ��ȯ�� ���� ���� �뷱�� ����.
			//tmSummonMonster.NumOfMonster			= max(1, pSkillItem->MultiNum);
			tmSummonMonster.NumOfMonster			= max( 1 , (INT)(pSkillItem->MultiNum * pMonster->MonsterInfoBalance.fSummonCountRatio) );

			// start 2011-05-02 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - Ư�� ��ǥ�� ��ȯ
			//////////
			// ���� //
			//tmSummonMonster.Position				= pMonster->PositionVector;

			//////////
			// ���� //
			D3DXVECTOR3 fSummonPosition(0.0f, 0.0f, 0.0f);

			fSummonPosition.x						= pSkillItem->GetParameterValue(DES_SUMMON_POSITION_X);
			fSummonPosition.y						= pSkillItem->GetParameterValue(DES_SUMMON_POSITION_Y);
			fSummonPosition.z						= pSkillItem->GetParameterValue(DES_SUMMON_POSITION_Z);

			tmSummonMonster.Position				= pMonster->PositionVector + fSummonPosition;
			// end 2011-05-02 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - Ư�� ��ǥ�� ��ȯ

			// 2010. 06. 08 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (�Ʊ� ���� �뷱�� ����.) - ������ ���� ��ȯ�� �뷱�� ����.
			tmSummonMonster.MonsterBalanceData		= pMonster->MonsterInfoBalance;

			NPCOnAdminSummonMonster(&tmSummonMonster, pMonster->m_nTargetIndex);
		}
		break;
	default:
		{
			return FALSE;
		}
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::NPCMonsterAttackSkill(CMonster *pMonster, SSUMMON_EVENT_MONSTER *i_pSummonEvMon)
/// \brief		// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - CNPCMapChannel::NPCMonsterAttackSkill() �߰�
/// \author		cmkwon
/// \date		2008-04-16 ~ 2008-04-16
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::NPCMonsterAttackSkill(CMonster *pMonster, SSUMMON_EVENT_MONSTER *i_pSummonEvMon)
{
	MSG_FN_ADMIN_SUMMON_MONSTER tmSummonMonster;
	tmSummonMonster.ChannelIndex			= m_MapChannelIndex.ChannelIndex;
	STRNCPY_MEMSET(tmSummonMonster.CharacterName, pMonster->MonsterInfoPtr->MonsterName, SIZE_MAX_CHARACTER_NAME);
	tmSummonMonster.MonsterUnitKind			= i_pSummonEvMon->SummonMonsterNum;
	tmSummonMonster.MonsterTargetType1		= MONSTER_TARGETTYPE_NORMAL;
	tmSummonMonster.TargetTypeData1			= 0;
	tmSummonMonster.CltIdxForTargetType1	= 0;
	tmSummonMonster.NumOfMonster			= max(1, i_pSummonEvMon->SummonMonsterCount);
	tmSummonMonster.Position				= pMonster->PositionVector;

	// 2010. 06. 08 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (�Ʊ� ���� �뷱�� ����.) - ������ ���� ��ȯ�� �뷱�� ����.
	tmSummonMonster.MonsterBalanceData		= pMonster->MonsterInfoBalance;

	return NPCOnAdminSummonMonster(&tmSummonMonster, pMonster->m_nTargetIndex);
}

void CNPCMapChannel::NPCMonsterMPOption(CNPCMonster *pMonster)
{
	if(COMPARE_MPOPTION_BIT(pMonster->MonsterInfoPtr->MPOption, MPOPTION_BIT_MOVE_PARTY))
	{	// ��Ƽ

		if(pMonster->MonsterInfoPtr->MPOptionParam2 > MONSTER_MAX_PARTY_MEMBER_COUNTS)
		{
			pMonster->MonsterInfoPtr->MPOptionParam2 = MONSTER_MAX_PARTY_MEMBER_COUNTS;
		}
		if(pMonster->m_nPartyManagerIndex)
		{
			CNPCMonster *pPartyMon = GetNPCMonster(pMonster->m_nPartyManagerIndex);
			if(NULL == pPartyMon
				|| pPartyMon->m_enMonsterState == MS_NULL
				|| COMPARE_BODYCON_BIT(pPartyMon->BodyCondition, BODYCON_DEAD_MASK)
				|| pPartyMon->m_byPartyMemberCounts <= 0
				|| MONSTER_MAX_PARTY_DISTANCE + 50.0f < D3DXVec3Length(&(pPartyMon->PositionVector - pMonster->PositionVector))
				|| pPartyMon->m_nPartyManagerIndex != pPartyMon->MonsterIndex)
			{
				pMonster->m_nPartyManagerIndex		= 0;
				pMonster->m_byPartyMemberCounts		= 0;
				pMonster->m_byPartyFormationIndex	= 0xFF;
			}
			else if(pMonster->m_nPartyManagerIndex == pMonster->MonsterIndex
				&& pMonster->m_byPartyMemberCounts < pMonster->MonsterInfoPtr->MPOptionParam2 - 1)
			{// �ڽ��� ��Ƽ���̸鼭 ��Ƽ���� ������ �ƴϴ�, �ʴ� ������

				vector<ClientIndex_t>	vecClientTemp;
				vecClientTemp.reserve(10);
				this->NPCGetAdjacentMonsterIndexes(&pMonster->PositionVector, MONSTER_MAX_PARTY_DISTANCE, ((int)MONSTER_MAX_PARTY_DISTANCE)<<1, &vecClientTemp);
				vector<ClientIndex_t>::iterator itr = vecClientTemp.begin();
				while(itr != vecClientTemp.end())
				{
					CNPCMonster *pMTemp = GetNPCMonster(*itr);
					if(pMTemp
						&& pMTemp->m_enMonsterState != MS_NULL
						&& pMTemp->m_nTargetIndex == 0					
						&& COMPARE_BODYCON_BIT(pMTemp->BodyCondition, BODYCON_DEAD_MASK) == FALSE
						&& pMTemp->MonsterInfoPtr->MonsterUnitKind == pMonster->MonsterInfoPtr->MonsterUnitKind
						&& pMTemp->m_nPartyManagerIndex == 0
						&& pMTemp->m_nTargetIndex == 0
						&& D3DXVec3Length(&(pMonster->PositionVector - pMTemp->PositionVector)) < MONSTER_MAX_PARTY_DISTANCE
						&& pMonster->m_dwCurrentTick%100 < 50)
					{
						pMTemp->m_nPartyManagerIndex = pMonster->m_nPartyManagerIndex;
						pMTemp->m_byPartyFormationIndex = pMonster->m_byPartyMemberCounts;
						pMonster->m_byPartyMemberCounts++;
						break;
					}
					itr++;
				}
			}
		}
		else if(0 == pMonster->m_nTargetIndex)
		{// ��Ƽ�� �������� �ƴϸ鼭 Ÿ���� ����, ��Ƽ ������ �����ϰ� �ʴ밡 �����ϴ�

			vector<ClientIndex_t>	vecClientTemp;
			vecClientTemp.reserve(10);
			this->NPCGetAdjacentMonsterIndexes(&pMonster->PositionVector, MONSTER_MAX_PARTY_DISTANCE, ((int)MONSTER_MAX_PARTY_DISTANCE)<<1, &vecClientTemp);
			vector<ClientIndex_t>::iterator itr = vecClientTemp.begin();
			while(itr != vecClientTemp.end())
			{
				CNPCMonster *pMTemp = this->GetNPCMonster(*itr);
				if(pMonster != pMTemp
					&& pMTemp
					&& pMTemp->m_enMonsterState != MS_NULL
					&& pMTemp->m_nTargetIndex == 0
					&& COMPARE_BODYCON_BIT(pMTemp->BodyCondition, BODYCON_DEAD_MASK) == FALSE
					&& pMTemp->MonsterInfoPtr->MonsterUnitKind == pMonster->MonsterInfoPtr->MonsterUnitKind
					&& pMTemp->m_nPartyManagerIndex == 0
					&& pMTemp->m_nTargetIndex == 0
					&& D3DXVec3Length(&(pMonster->PositionVector - pMTemp->PositionVector)) < MONSTER_MAX_PARTY_DISTANCE
					&& pMonster->m_dwCurrentTick%100 < 50)
				{
					//////////////////////////////////////////////////////
					// �׻� �ڽ��� ��Ƽ���� �ȴ�
					pMonster->m_nPartyManagerIndex = pMonster->MonsterIndex;
					pMTemp->m_nPartyManagerIndex = pMonster->m_nPartyManagerIndex;
					pMTemp->m_byPartyFormationIndex = 0;
					pMonster->m_byPartyMemberCounts = 1;
					break;
				}
				itr++;
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
// ȣ�Ͼ� �� ���ݰ��� ����
//	1 : �޽�����
//		�Ϲ����� ��Ȳ������ ���ٸ� ���� ���� ����
//	2 : ��ü����
//		���� ���� ���� 5�� �̻� �����ϴ� ���
//	3 : ��ȯ����
//		���͸� �����ϰ� �ִ� ������ 10�� �̻��� ��� , HP�� 50% �̻� ���� ���� 10% ���ҵ� ���
//
// ����ƾ ������ ���ݰ��� ����
//	1 : �Ұ���
//		�Ϲ����� ��Ȳ������ ���ٸ� ���� ���� ����
//	2 : ������
//		���� ���� ���� 5�� �̻� �����ϴ� ���
BOOL CNPCMapChannel::CheckMonsterSelectedItem(CNPCMonster * i_pnMonster)
{
	// 2010-06-09 by dhjin, NPC���� �״� ���� ���� - ����
	if(NULL == i_pnMonster->m_pUsingMonsterItem->pItemInfo)
	{
		g_pNPCGlobal->WriteSystemLogEX(TRUE,"[DEBUG] @CheckMonsterSelectedItem MonsterNum [%d] m_pUsingMonsterItem->pItemInfo is NULL!\r\n",i_pnMonster->MonsterInfoPtr->MonsterUnitKind);
		
		i_pnMonster->SelectUsingMonsterItem();		// 2012-12-17 by hskim, NPC ���� �״� ���� ���� (���� ������ pItemInfo �� NULL �Ǵ� ����)

		return FALSE;	
	}

	vector<ClientIndex_t>	vecClientTemp;
	vecClientTemp.reserve(10);

// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
//	if(DES_SUMMON == i_pnMonster->m_pUsingMonsterItem->pItemInfo->DestParameter1)
	if(DES_SUMMON == i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrDestParameter[0])
	{// ��ȯ ���� ���� ó��

// 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� ����
// 		NPCGetAdjacentMonsterIndexes(&i_pnMonster->PositionVector, i_pnMonster->MonsterInfoPtr->Range
// 			, i_pnMonster->MonsterInfoPtr->Range*2, &vecClientTemp, (INT)i_pnMonster->m_pUsingMonsterItem->pItemInfo->ParameterValue1);
		NPCGetAdjacentMonsterIndexes(&i_pnMonster->PositionVector, i_pnMonster->MonsterInfoPtr->Range
			, i_pnMonster->MonsterInfoPtr->Range*2, &vecClientTemp, (INT)i_pnMonster->m_pUsingMonsterItem->pItemInfo->ArrParameterValue[0]);
		
		if(vecClientTemp.size() >= i_pnMonster->m_pUsingMonsterItem->pItemInfo->ShotNum*2)
		{// ��ȯ �ɷ��� 2�躸�� ���� ��ȯ �Ǿ������� FALSE�� �����Ѵ�

			return FALSE;
		}
	}

// 2005-12-13 by cmkwon, ������
//	switch(i_pnMonster->m_pUsingMonsterItem->pItemInfo->ItemNum)
//	{
//	case 2004400:	// ����Ʈ������ ������
//		{
//			if(i_pnMonster->CurrentHP > i_pnMonster->MonsterInfoPtr->MonsterHP/5)
//			{// CurrentHP�� HP/5 ���� Ŭ���� ������ ĳ���� 5�� �̻��� ���� ��� ����	
//				
//				NPCGetAdjacentCharacterIndexes(&i_pnMonster->PositionVector, i_pnMonster->m_pUsingMonsterItem->pItemInfo->Range
//					, i_pnMonster->m_pUsingMonsterItem->pItemInfo->Range*2, &vecClientTemp);
//				if(vecClientTemp.size() < 5)
//				{// ������ ĳ���Ͱ� 5���̻��̾�� ��� ����
//
//					return FALSE;
//				}
//			}
//		}
//		break;
//	case 7500670:	// ȣ�Ͼ��� ��ü����
//		{
//			///////////////////////////////////////////////////////////////////////////////
//			// ���� HP�� 1/2���� �϶� ��� ����
//			if(i_pnMonster->CurrentHP > i_pnMonster->MonsterInfoPtr->MonsterHP/2)
//			{
//				return FALSE;
//			}
//		}
//	}

	return TRUE;
}


BOOL CNPCMapChannel::Send2FieldServerW(BYTE *pData, int nSize)
{
	return m_pNPCMapProject->Send2FieldServer(pData, nSize);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::Send2FieldServerByTCPW(BYTE *pData, int nSize)
/// \brief		// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - CNPCMapChannel::Send2FieldServerByTCPW() �߰�
/// \author		cmkwon
/// \date		2007-11-26 ~ 2007-11-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::Send2FieldServerByTCPW(BYTE *pData, int nSize)
{
	return m_pNPCMapProject->Send2FieldServerByTCP(pData, nSize);
}

BOOL CNPCMapChannel::SetInitialPositionAndSendCreateMonster(CNPCMonster *i_pMons, BYTE *i_pBufSend, D3DXVECTOR3 *i_pSummonPos/*=NULL*/)
{
	if(FALSE == SetInitialPosition(i_pMons->PositionVector.x, i_pMons->PositionVector.z, i_pMons->MonsterIndex))
	{
		char szTemp[256];
		sprintf(szTemp, "[Error] SetInitialPosition_1 Error, MapChannel(%s) UnitIndex(%5d) XZ(%5.0f, %5.0f)\n"
			, GET_MAP_STRING(this->m_MapChannelIndex), i_pMons->MonsterIndex
			, i_pMons->PositionVector.x, i_pMons->PositionVector.z);
		DBGOUT(szTemp);
		g_pNPCGlobal->WriteSystemLog(szTemp);
	}
	INIT_MSG(MSG_FN_MONSTER_CREATE, T_FN_MONSTER_CREATE, pSMonsterCreate, i_pBufSend);
	pSMonsterCreate->ChannelIndex		= this->m_MapChannelIndex.ChannelIndex;
	pSMonsterCreate->MonsterIndex		= i_pMons->MonsterIndex;
	pSMonsterCreate->MonsterUnitKind	= i_pMons->MonsterInfoPtr->MonsterUnitKind;
	pSMonsterCreate->MonsterTargetType1	= i_pMons->m_byMonsterTargetType;
	pSMonsterCreate->TargetTypeData1	= i_pMons->m_nTargetTypeData;
	i_pMons->m_mtvectClientIdxForTargetType.lock();
	if(false == i_pMons->m_mtvectClientIdxForTargetType.empty())
	{
		pSMonsterCreate->CltIdxForTargetType1	= i_pMons->m_mtvectClientIdxForTargetType[0];
	}
	i_pMons->m_mtvectClientIdxForTargetType.unlock();
	pSMonsterCreate->BodyCondition		= i_pMons->BodyCondition;
	pSMonsterCreate->PositionVector		= i_pMons->PositionVector;
	if(i_pSummonPos)
	{
		pSMonsterCreate->PositionVector	= *i_pSummonPos;
	}
	pSMonsterCreate->TargetVector		= i_pMons->TargetVector*1000.0f;
	pSMonsterCreate->ObjectMonsterType	= i_pMons->m_byObjectMonsterType;

	// 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
	pSMonsterCreate->MonsterBalanceData = i_pMons->MonsterInfoBalance;
	// End 2010. 05. 19 by hsLee ���Ǵ�Ƽ �ʵ� 2�� ���̵� ����. (��ȣó�� + ���� ó��(����) )
	
	return Send2FieldServerW(i_pBufSend, MSG_SIZE(MSG_FN_MONSTER_CREATE));
}

// ������Ʈ ���� ����
OBJECTINFOSERVER *CNPCMapChannel::FindObjectMonsterInfoByObjectEventIndex(int i_nObjectEventIndex)
{
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		if(itr->m_EventInfo.m_EventwParam1 == i_nObjectEventIndex)
		{
			return &*itr;
		}
	}
	return NULL;
}

// CityWar Object Monster
// 2006-11-22 by cmkwon, �Լ��� ����(FindCityWarObjectMonsterInfo->FindObjectBossMonsterInfo)
OBJECTINFOSERVER *CNPCMapChannel::FindObjectBossMonsterInfo(void)
{
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
// 2006-11-22 by cmkwon, �Ʒ��� ���� ������		if(itr->m_EventInfo.m_byIsCityWarMonster)
		if(itr->m_EventInfo.m_byBossMonster)		// 2006-11-22 by cmkwon, ������ ����(m_byIsCityWarMonster->m_byBossMonster) - ������������ ������
		{
			return &*itr;
		}
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			OBJECTINFOSERVER *CNPCMapChannel::FindObjectMonsterInfoBYBelligerence(BYTE i_byBellig)
/// \brief		// 2007-08-18 by cmkwon, ������Ʈ ���� ��ȯ ������ MONSTER_INFO * �����ϱ� - �Լ��߰�
/// \author		cmkwon
/// \date		2007-08-18 ~ 2007-08-18
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
OBJECTINFOSERVER *CNPCMapChannel::FindObjectMonsterInfoBYBelligerence(BYTE i_byBellig)
{
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		if(itr->m_pMonsterInfo
			&& itr->m_pMonsterInfo->Belligerence == i_byBellig)
		{
			return &*itr;
		}
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::GetObjectMonsterByMonsterIdx(INT i_nMonsterIdx, OBJECTINFOSERVER * o_pMonsterInfo)
/// \brief		���Ǵ�Ƽ(�������) - 
///				// 2010-03-31 by cmkwon, ����2�� �߰� ���� - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::GetObjectMonsterByMonsterIdx(INT i_nMonsterIdx, vectorObjectInfoServerPtr *o_pObjectInfoServList)
{
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		OBJECTINFOSERVER *pObjInfoServ = &*itr;
		if(pObjInfoServ->m_pMonsterInfo
			&& pObjInfoServ->m_pMonsterInfo->MonsterUnitKind == i_nMonsterIdx)
		{
			o_pObjectInfoServList->push_back(pObjInfoServ);
		}
	}	

	return o_pObjectInfoServList->size();
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::IsEnableCreateMonster(MONSTER_INFO *i_pMonInfo)
/// \brief		
/// \author		cmkwon
/// \date		2006-04-18 ~ 2006-04-18
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::IsEnableCreateMonster(MONSTER_INFO *i_pMonInfo)
{
	if(FALSE == IS_INFLWAR_MONSTER(i_pMonInfo->Belligerence))
	{
		return TRUE;
	}
	
	if(IS_MAP_INFLUENCE_ARENA(this->GetMapInfluenceTypeW()))
	{// 2007-05-16 by cmkwon, �Ʒ������̰�� �׻� TRUE
		return TRUE;
	}

	if(IS_STRATEGYPOINT_MONSTER(i_pMonInfo->Belligerence)
		&& 0 != this->GetMapChannelIndex().ChannelIndex)
	{// 2006-11-21 by cmkwon, ��������Ʈ ���ʹ� 0�� ä�ο��� �����ȴ�.
		return FALSE;
	}

	if(IS_BELL_VCN(i_pMonInfo->Belligerence)
		&& (IS_MAP_INFLUENCE_VCN(m_pNPCMapProject->m_nMapInfluenceType)
			|| IS_MAP_INFLUENCE_OUTPOST(m_pNPCMapProject->m_nMapInfluenceType)))
	{// 2007-09-07 by dhjin, �������� �ʿ��� ���� ���ʹ� �����Ѵ�.
		return TRUE;
	}
	else if(IS_BELL_ANI(i_pMonInfo->Belligerence)
		&& (IS_MAP_INFLUENCE_ANI(m_pNPCMapProject->m_nMapInfluenceType)
			|| IS_MAP_INFLUENCE_OUTPOST(m_pNPCMapProject->m_nMapInfluenceType)))
	{
		return TRUE;
	}

	if(IS_TELEPORT_MONSTER(i_pMonInfo->Belligerence))
	{// 2007-09-19 by dhjin, �ڷ���Ʈ�̸� ��ȯ
		return TRUE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2006-04-18 by cmkwon
	return m_pNPCIOCPServer->CheckSummonJacoMonster(i_pMonInfo->Belligerence);
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::DeleteAllMonster(BOOL i_bAll/*=TRUE*/, int i_byBell1/*=-1*/, int i_byBell2/*=-1*/, int i_byExcludeBell1/*=-1*/, int i_byExcludeBell2/*=-1*/)
/// \brief		// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰�
/// \author		cmkwon
/// \date		2007-08-22 ~ 2007-08-22
/// \warning	MapWorker �����忡�� ȣ�� �ؾ���
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::DeleteAllMonster(BOOL i_bAll/*=TRUE*/, int i_byBell1/*=-1*/, int i_byBell2/*=-1*/, int i_byExcludeBell1/*=-1*/, int i_byExcludeBell2/*=-1*/)
{
	///////////////////////////////////////////////////////////////////////////////
	// �ʾ��� ��� ���͸� �����Ѵ�
	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, SendBuf);
	pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
	pMonsterDelete->CinemaDelete	= FALSE;		// 2011-05-30 by hskim, ���Ǵ�Ƽ 3�� - ���� ���� Ŭ���̾�Ʈ �ݿ�

	int nSize = m_mtvectorMonsterPtr.size();
	for(int i=0; i < nSize; i++)
	{
		CNPCMonster		*pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
		if(NULL == pNMon
			|| MS_NULL == pNMon->m_enMonsterState)
		{
			continue;
		}

		MONSTER_INFO	*pMonInfo = pNMon->MonsterInfoPtr;
		if(NULL == pMonInfo)
		{
			continue;
		}

		if(FALSE == i_bAll)
		{// ��ü ���� ���� �÷��� üũ

			if(0 <= i_byExcludeBell1 || 0 <= i_byExcludeBell2)
			{// ���� Bell�� �����Ǿ� ����

				if(pMonInfo->Belligerence == i_byExcludeBell1
					|| pMonInfo->Belligerence == i_byExcludeBell2)
				{
					continue;
				}
			}

			if(0 <= i_byBell1 || 0 <= i_byBell2)
			{// 2007-08-22 by cmkwon, bell�� �ϳ��� ������ �Ǿ� �ִٸ� 

				if(pMonInfo->Belligerence != i_byBell1
					&& pMonInfo->Belligerence != i_byBell2)
				{
					continue;
				}
			}
		}
		
		pMonsterDelete->MonsterIndex	= pNMon->MonsterIndex;
		Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));

		this->DelelteMonsterHandler(pNMon);		
	}
}

// start 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::DeleteUnitKindMonster(INT iMonsterUnitKind)
/// \brief		// 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		2011-04-28
/// \warning	MapWorker �����忡�� ȣ�� �ؾ���
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::DeleteUnitKindMonster(INT iMonsterUnitKind)
{
	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_DELETE, T_FN_MONSTER_DELETE, pMonsterDelete, SendBuf);
	pMonsterDelete->ChannelIndex	= m_MapChannelIndex.ChannelIndex;
	pMonsterDelete->CinemaDelete	= TRUE;		// 2011-05-30 by hskim, ���Ǵ�Ƽ 3�� - ���� ���� Ŭ���̾�Ʈ �ݿ�
	
	int nSize = m_mtvectorMonsterPtr.size();
	for(int i=0; i < nSize; i++)
	{
		CNPCMonster		*pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
		if(NULL == pNMon
			|| MS_NULL == pNMon->m_enMonsterState)
		{
			continue;
		}
		
		MONSTER_INFO	*pMonInfo = pNMon->MonsterInfoPtr;
		if(NULL == pMonInfo)
		{
			continue;
		}

		if( pNMon->MonsterInfoPtr->MonsterUnitKind != iMonsterUnitKind ) 
		{
			continue;
		}

		pMonsterDelete->MonsterIndex	= pNMon->MonsterIndex;
		Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_MONSTER_DELETE));

		this->DelelteMonsterHandler(pNMon);		
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ChangeUnitKindMonster(INT iMonsterUnitKind, INT iChangeMonsterUnitKind)
/// \brief		// 2011-05-11 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
/// \author		hskim
/// \date		2011-05-11
/// \warning	MapWorker �����忡�� ȣ�� �ؾ���
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ChangeUnitKindMonster(INT iMonsterUnitKind, INT iChangeMonsterUnitKind)
{
	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_CHANGE_OK, T_FN_MONSTER_CHANGE_OK, pMonsterChange, SendBuf);
	pMonsterChange->ChannelIndex	= m_MapChannelIndex.ChannelIndex;

	MONSTER_INFO *pChangeMonInfo = m_pNPCIOCPServer->GetMonsterInfo(iChangeMonsterUnitKind);
	if(NULL == pChangeMonInfo) return ;

	int nSize = m_mtvectorMonsterPtr.size();
	for(int i=0; i < nSize; i++)
	{
		CNPCMonster		*pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
		if(NULL == pNMon
			|| MS_NULL == pNMon->m_enMonsterState)
		{
			continue;
		}

		MONSTER_INFO	*pMonInfo = pNMon->MonsterInfoPtr;
		if(NULL == pMonInfo)
		{
			continue;
		}
		
		if( pNMon->MonsterInfoPtr->MonsterUnitKind != iMonsterUnitKind ) 
		{
			continue;
		}
		
		// ���� ���� ��ü
		pNMon->MonsterInfoPtr = pChangeMonInfo;
		
		pMonsterChange->MonsterIndex	= pNMon->MonsterIndex;
		pMonsterChange->ChangeMonsterUnitKind	= iChangeMonsterUnitKind;
		Send2FieldServerW(SendBuf, MSG_SIZE(MSG_FN_MONSTER_CHANGE_OK));
		
		g_pNPCGlobal->WriteSystemLogEX(TRUE, "  %10s : <= ChangeOK MonIndex[%4d] MonsterUnitKind[%8d] ChangeMonsterUnitKind[%d]\r\n",
			GET_MAP_STRING(m_MapChannelIndex), pMonsterChange->MonsterIndex,pNMon->MonsterInfoPtr->MonsterUnitKind, iChangeMonsterUnitKind);
	}
}
// end 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::SetNotCreateMonsterValue(bool i_bNotCreateMonster)
/// \brief		���� ���� ���� ���� ����
/// \author		dhjin
/// \date		2007-08-29 ~ 2007-08-29
/// \warning	
///
/// \param		
/// \return		
/////////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SetNotCreateMonsterValue(bool i_bNotCreateMonster)
{
	// 2009-12-04 by cmkwon, ���� �������� ���� �α� �߰� - 
	g_pNPCGlobal->WriteSystemLogEX(TRUE, "  [Notify] MapChannel(%d:%d) CNPCMapChannel::SetNotCreateMonsterValue# CurValue(%d) NewValue(%d) \r\n"
		, this->GetMapChannelIndex().MapIndex, this->GetMapChannelIndex().ChannelIndex, m_bNotCreateMonster, i_bNotCreateMonster);

	m_bNotCreateMonster = i_bNotCreateMonster;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			OBJECTINFOSERVER *CNPCMapChannel::GetTeleportObjectMonsterSummonInfo(CNPCMonster *i_pNMon)
/// \brief		// 2007-09-20 by cmkwon, �ڷ���Ʈ ��ȯ ���� ����
/// \author		cmkwon
/// \date		2007-09-20 ~ 2007-09-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
OBJECTINFOSERVER *CNPCMapChannel::GetTeleportObjectMonsterSummonInfo(CNPCMonster *i_pNMon)
{
	if(FALSE == i_pNMon->m_byObjectMonsterType)
	{
		return NULL;
	}

	OBJECTINFOSERVER *pObjInfoServ = this->FindObjectMonsterInfoByObjectEventIndex(i_pNMon->m_dwIndexCreatedMonsterData);
	if(NULL == pObjInfoServ
		|| FALSE == IS_TELEPORT_MONSTER(pObjInfoServ->m_pMonsterInfo->Belligerence))
	{
		return NULL;
	}
	
	return pObjInfoServ;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
/// \author		cmkwon
/// \date		2009-12-16 ~ 2009-12-16
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::ChangeTarget(CNPCMonster *i_pNMon)
{
	MONSTER_INFO *pMonInfo = i_pNMon->MonsterInfoPtr;
	if(NULL == pMonInfo
		|| FALSE == i_pNMon->IsValidMonster())		// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - üũ �߰�
	{
		return FALSE;
	}

// 2009-12-10 by cmkwon, TEMP 
//	g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 10000 CNPCMapChannel::ChangeTarget# Map(%s) MonIdx(%d) MonsNum(%d) ChangeTarget(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d) nAttackerCnt(%d) ChangeTargetTime(%d) \r\n"
//		, GetMapString(this->GetMapChannelIndex(), string()), i_pNMon->MonsterIndex, i_pNMon->MonsterInfoPtr->MonsterUnitKind, i_pNMon->MonsterInfoPtr->ChangeTarget, i_pNMon->m_nTargetIndex, 0, i_pNMon->m_dwCurrentTick, i_pNMon->m_mtvectorAttackedInfoPtr.size(), i_pNMon->MonsterInfoPtr->ChangeTargetTime);

// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
// 	// 2009-12-16 by cmkwon, TargetIndex ������� �����Ѵ�.
// 	i_pNMon->SetChangedTargetIndexTick(i_pNMon->m_dwCurrentTick);		// 2009-12-11 by cmkwon, ������ ��׷η� Ÿ���� �����ϴ� ���� ���� - 
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - CNPCMapChannel::ChangeTarget#
	i_pNMon->SetTimeLastCheckChangeTarget(i_pNMon->m_dwCurrentTick);	

	ClientIndex_t newTargetIdx = 0;
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - �Ʊ� Ÿ�� ��ƾ� �Ǵ� ��ųŸ��Ÿ�Ծ������̸� ���⼭ Ÿ�� ó��~!!!
	newTargetIdx = this->GetOurTagetByUsingItem(i_pNMon);
	if(FALSE != newTargetIdx)
	{
		i_pNMon->SelectTargetIndex(newTargetIdx);
		return newTargetIdx;
	}

	if(ATTACKOBJ_AGGRO == pMonInfo->AttackObject)
	{
		newTargetIdx = i_pNMon->GetMaxDamageUser();
		i_pNMon->ResetSumDamageInAttackedInfoList();	// 2009-12-11 by cmkwon, ���� �������� �ʱ�ȭ �Ѵ�.

// 2009-12-10 by cmkwon, TEMP 
//		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 11000 CNPCMapChannel::ChangeTarget# Map(%s) MonIdx(%d) MonsNum(%d) ChangeTarget(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d) nAttackerCnt(%d) \r\n"
//			, GetMapString(this->GetMapChannelIndex(), string()), i_pNMon->MonsterIndex, i_pNMon->MonsterInfoPtr->MonsterUnitKind, i_pNMon->MonsterInfoPtr->ChangeTarget, i_pNMon->m_nTargetIndex, newTargetIdx, i_pNMon->m_dwCurrentTick, i_pNMon->m_mtvectorAttackedInfoPtr.size());
	}
	else
	{
		///////////////////////////////////////////////////////////////////////////////
		// 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ATTACKOBJ_RANDOM �̸� 30%�� ���� Ÿ�ٺ����� ó���Ѵ�.
		int nAttObjRandomVal = RAND100();
		if(ATTACKOBJ_RANDOM == pMonInfo->AttackObject
			&& 30 <= nAttObjRandomVal)
		{
// 2009-12-10 by cmkwon, TEMP 
//			g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 12000 CNPCMapChannel::ChangeTarget# Map(%s) MonIdx(%d) MonsNum(%d) ChangeTarget(%d) AttObj(%d) RandVal(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d)\r\n"
//				, GetMapString(this->GetMapChannelIndex(), string()), i_pNMon->MonsterIndex, i_pNMon->MonsterInfoPtr->MonsterUnitKind, i_pNMon->MonsterInfoPtr->ChangeTarget, i_pNMon->MonsterInfoPtr->AttackObject, nAttObjRandomVal, i_pNMon->m_nTargetIndex, newTargetIdx, i_pNMon->m_dwCurrentTick);

			return FALSE;
		}

		vectorClientIndex vectTargetableList;
		
		int tmClientCnt = 0;

		if(IS_BELL_ATTACK(pMonInfo->Belligerence))
		{
			// 2009-12-16 by cmkwon, ���� ĳ������ ����Ʈ �˻�
			this->NPCGetAdjacentCharacterIndexes(&i_pNMon->PositionVector, pMonInfo->AttackRange, pMonInfo->AttackRange*2, &vectTargetableList, pMonInfo->Belligerence);

			tmClientCnt = vectTargetableList.size();
		}

		// 2009-12-16 by cmkwon, ���͸� �˻��� ��Ʈ�� �˻�
		i_pNMon->GetAttackedInfoClientIndexList(&vectTargetableList);		

		newTargetIdx = this->NPCGetTargetwithAttackObj(pMonInfo->AttackObject, i_pNMon, vectTargetableList);

// 2009-12-10 by cmkwon, TEMP 
//		g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 13000 CNPCMapChannel::ChangeTarget# Map(%s) MonIdx(%d) MonsNum(%d) ChangeTarget(%d) AttObj(%d) RandVal(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d) nAttackerCnt(%d) ClientCnt(%d) \r\n"
//			, GetMapString(this->GetMapChannelIndex(), string()), i_pNMon->MonsterIndex, i_pNMon->MonsterInfoPtr->MonsterUnitKind, i_pNMon->MonsterInfoPtr->ChangeTarget, i_pNMon->MonsterInfoPtr->AttackObject, nAttObjRandomVal, i_pNMon->m_nTargetIndex, newTargetIdx, i_pNMon->m_dwCurrentTick, vectTargetableList.size(), tmClientCnt);
	}

	if(0 == newTargetIdx
		|| newTargetIdx == i_pNMon->GetTargetIndex())
	{
		return FALSE;
	}

	i_pNMon->SelectTargetIndex(newTargetIdx);

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			OBJECTINFOSERVER *FindObjectMonsterInfoByMonsterUniqueNumberAndMinimumDistance(DWORD i_dwMonsterUniqueNumber, D3DXVECTOR3 *i_pVec3Position)
/// \brief		
/// \author		cmkwon
/// \date		2004-11-26 ~ 2004-11-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
OBJECTINFOSERVER *CNPCMapChannel::FindObjectMonsterInfoByMonsterUniqueNumberAndMinimumDistance(INT i_nMonsterUniqueNumber
																							   , D3DXVECTOR3 *i_pVec3Position)
{
	OBJECTINFOSERVER	*pRetObj = NULL;
	float				fMinimumDistance = 300.0f;

	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		if(itr->m_EventInfo.m_nObejctMonsterUnitKind == i_nMonsterUniqueNumber)
		{
			// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
			if( D3DXVECTOR3(0.0, 0.0, 0.0) == *i_pVec3Position )
			{
				return &*itr;
			}
			// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���

			float ftmDist = D3DXVec3Length(&(*i_pVec3Position - itr->m_vPos));
			if(ftmDist < fMinimumDistance)
			{
				pRetObj = &*itr;
				ftmDist = fMinimumDistance;
			}
		}
	}

	return pRetObj;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::CheckMonsterPosition(CNPCMonster *pMon, float fTimeRate)
/// \brief		
/// \author		cmkwon
/// \date		2004-04-06 ~ 2004-04-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::CheckMonsterPosition(CNPCMonster *pMon, float fTimeRate)
{
	if(FALSE == pMon->m_MoveInfo.MovableFlag)
	{
		return TRUE;
	}

	if(FALSE == m_pNPCMapProject->IsValidPosition(pMon->PositionVector.x, pMon->PositionVector.z))
	{	// X��ǥ�� Y��ǥ�� map�� ������ ��������� ���� Ȯ���Ѵ�

		pMon->SetMoveState(MSS_NORMAL);
		pMon->PositionVector = pMon->m_BeforePosition;
		GNPCRotateTargetVectorHorizontal(&pMon->TargetVector, &pMon->TargetVector, pMon->m_MoveInfo.LRDirect * MSD_LEFT_90, 45);
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� Objec�� �浿 ó���� �Ѵ�.
	CheckAndModifyImpactPositionObjects(pMon);
	if(FALSE == m_pNPCMapProject->IsValidPosition(pMon->PositionVector.x, pMon->PositionVector.z))
	{// X��ǥ�� Y��ǥ�� map�� ������ ��������� ���� Ȯ���Ѵ�
			
		pMon->PositionVector = pMon->m_BeforePosition;
		GNPCRotateTargetVectorHorizontal(&pMon->TargetVector, &pMon->TargetVector, pMon->m_MoveInfo.LRDirect * MSD_LEFT_90, 45);
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 1. ���� ������ ���� ����
	// 2. ������ ������ ���� ����
	//		- ���� �������� �ʳ��̴� �����̸� �������� �ʴ� �����̴�
	//		- ������ ���̰� �ʳ��� ���� ������ �ʳ��̷� �����ش�.	
	if(pMon->CurrentMonsterForm == FORM_GROUND_MOVE)
	{	// ���� ������ ���� ����

		float fMapHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&pMon->PositionVector);			// ��ǥ�� ���� ���̸� ���Ѵ�.
		pMon->PositionVector.y = fMapHeight + pMon->MonsterInfoPtr->Size;

		///////////////////////////////////////////////////////////////////////////////
		// ���� ������ Position�� ����Ǿ����Ƿ� ������Ʈ �浹 ó���� �ѹ��� �Ѵ�
		CheckAndModifyImpactPositionObjects(pMon);
	}
	else
	{
		float fMapHeight;
		if(pMon->CurrentMonsterForm == FORM_SWIMMINGFLYING_RIGHT
			|| pMon->CurrentMonsterForm == FORM_SWIMMINGFLYING_COPTER)
		{
			fMapHeight = m_pNPCMapProject->GetMapHeightExcludeWater(&pMon->PositionVector);			// �����̰� ���ܵ� ��ǥ�� ���� ���̸� ���Ѵ�.
		}
		else
		{
			fMapHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&pMon->PositionVector);			// �����̰� ���Ե� ��ǥ�� ���� ���̸� ���Ѵ�.
		}

		float fTmMinHeight = fMapHeight + pMon->MonsterInfoPtr->Size;
		if(pMon->PositionVector.y-fTmMinHeight < 0.0f)
		{	// ���� ���� ��ǥ�� (�ʳ��� + ���� ������) ���� �۴�
		
			pMon->PositionVector.y = fTmMinHeight;
		
			///////////////////////////////////////////////////////////////////////////////
			// Position�� ����Ǿ����Ƿ� ������Ʈ �浹 ó���� �ѹ��� �Ѵ�
			CheckAndModifyImpactPositionObjects(pMon);
		}
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::CheckMonsterPositionWarp(CNPCMonster *pMon, float fTimeRate)
/// \brief		���Ǵ�Ƽ - 
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::CheckMonsterPositionWarp(CNPCMonster *pMon, float fTimeRate) {
	if(FALSE == m_pNPCMapProject->IsValidPosition(pMon->PositionVector.x, pMon->PositionVector.z))
	{	// X��ǥ�� Y��ǥ�� map�� ������ ��������� ���� Ȯ���Ѵ�
		
		pMon->SetMoveState(MSS_NORMAL);
		pMon->PositionVector = pMon->m_BeforePosition;
		GNPCRotateTargetVectorHorizontal(&pMon->TargetVector, &pMon->TargetVector, pMon->m_MoveInfo.LRDirect * MSD_LEFT_90, 45);
		return FALSE;
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// ���� Objec�� �浿 ó���� �Ѵ�.
	CheckAndModifyImpactPositionObjects(pMon);
	if(FALSE == m_pNPCMapProject->IsValidPosition(pMon->PositionVector.x, pMon->PositionVector.z))
	{// X��ǥ�� Y��ǥ�� map�� ������ ��������� ���� Ȯ���Ѵ�
		
		pMon->PositionVector = pMon->m_BeforePosition;
		GNPCRotateTargetVectorHorizontal(&pMon->TargetVector, &pMon->TargetVector, pMon->m_MoveInfo.LRDirect * MSD_LEFT_90, 45);
		return FALSE;
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// 1. ���� ������ ���� ����
	// 2. ������ ������ ���� ����
	//		- ���� �������� �ʳ��̴� �����̸� �������� �ʴ� �����̴�
	//		- ������ ���̰� �ʳ��� ���� ������ �ʳ��̷� �����ش�.	
	if(pMon->CurrentMonsterForm == FORM_GROUND_MOVE)
	{	// ���� ������ ���� ����
		
		float fMapHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&pMon->PositionVector);			// ��ǥ�� ���� ���̸� ���Ѵ�.
		pMon->PositionVector.y = fMapHeight + pMon->MonsterInfoPtr->Size;
		
		///////////////////////////////////////////////////////////////////////////////
		// ���� ������ Position�� ����Ǿ����Ƿ� ������Ʈ �浹 ó���� �ѹ��� �Ѵ�
		CheckAndModifyImpactPositionObjects(pMon);
	}
	else
	{
		float fMapHeight;
		if(pMon->CurrentMonsterForm == FORM_SWIMMINGFLYING_RIGHT
			|| pMon->CurrentMonsterForm == FORM_SWIMMINGFLYING_COPTER)
		{
			fMapHeight = m_pNPCMapProject->GetMapHeightExcludeWater(&pMon->PositionVector);			// �����̰� ���ܵ� ��ǥ�� ���� ���̸� ���Ѵ�.
		}
		else
		{
			fMapHeight = m_pNPCMapProject->GetMapHeightIncludeWater(&pMon->PositionVector);			// �����̰� ���Ե� ��ǥ�� ���� ���̸� ���Ѵ�.
		}
		
		float fTmMinHeight = fMapHeight + pMon->MonsterInfoPtr->Size;
		if(pMon->PositionVector.y-fTmMinHeight < 0.0f)
		{	// ���� ���� ��ǥ�� (�ʳ��� + ���� ������) ���� �۴�
			
			pMon->PositionVector.y = fTmMinHeight;
			
			///////////////////////////////////////////////////////////////////////////////
			// Position�� ����Ǿ����Ƿ� ������Ʈ �浹 ó���� �ѹ��� �Ѵ�
			CheckAndModifyImpactPositionObjects(pMon);
		}
	}
	
	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
// �Լ��� Ŭ����
//
///////////////////////////////////////////////////////////////////////////////
class for_each_functor_MSG_FN_MONSTER_CREATE_OK
{
public:
	for_each_functor_MSG_FN_MONSTER_CREATE_OK(CNPCMapChannel *i_pNMapChann)
		:m_pNMapChannel(i_pNMapChann)
	{
	};
	void operator()(MSG_FN_MONSTER_CREATE_OK createOK)
	{
		m_pNMapChannel->ProcessNPCOnMonsterCreateOK(&createOK);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

class for_each_functor_MSG_FN_MONSTER_DELETE
{
public:
	for_each_functor_MSG_FN_MONSTER_DELETE(CNPCMapChannel *i_pNMapChann)
		:m_pNMapChannel(i_pNMapChann)
	{
	};
	void operator()(MSG_FN_MONSTER_DELETE MonDel)
	{
		m_pNMapChannel->ProcessNPCOnMonsterDelete(&MonDel);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
class for_each_functor_MSG_FN_MONSTER_SKILL_END_SKILL
{
public:
	for_each_functor_MSG_FN_MONSTER_SKILL_END_SKILL(CNPCMapChannel *i_pNMapChann)
		:m_pNMapChannel(i_pNMapChann)
	{
	};
	void operator()(MSG_FN_MONSTER_SKILL_END_SKILL endSkill)
	{
		m_pNMapChannel->ProcessNPCOnMonsterSkillEndSkill(&endSkill);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
class for_each_functor_MSG_FN_BATTLE_SET_ATTACK_CHARACTER
{
public:
	for_each_functor_MSG_FN_BATTLE_SET_ATTACK_CHARACTER(CNPCMapChannel *i_pNMapChann)
		:m_pNMapChannel(i_pNMapChann)
	{
	};
	void operator()(MSG_FN_BATTLE_SET_ATTACK_CHARACTER i_SetAttack)
	{
		m_pNMapChannel->ProcessNPCOnBattleSetAttackCharacter(&i_SetAttack);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
struct for_each_functor_MSG_FN_CITYWAR_START_WAR
{
	for_each_functor_MSG_FN_CITYWAR_START_WAR(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_CITYWAR_START_WAR i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnCityWarStartWar(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
struct for_each_functor_MSG_FN_CITYWAR_END_WAR
{
	for_each_functor_MSG_FN_CITYWAR_END_WAR(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_CITYWAR_END_WAR i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnCityWarEndWar(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
struct for_each_functor_MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO
{
	for_each_functor_MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnCityWarChangeOccupyInfo(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
struct for_each_functor_MSG_FN_MONSTER_STRATEGYPOINT_INIT
{// 2006-11-20 by cmkwon
	for_each_functor_MSG_FN_MONSTER_STRATEGYPOINT_INIT(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_MONSTER_STRATEGYPOINT_INIT i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterStrategyPointInit(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

struct for_each_functor_MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL		// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰�
{
	for_each_functor_MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterDeleteMonsterInMapChannel(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

struct for_each_functor_MSG_FN_MONSTER_OUTPOST_INIT
{// 2007-08-24 by dhjin
	for_each_functor_MSG_FN_MONSTER_OUTPOST_INIT(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_MONSTER_OUTPOST_INIT i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterOutPostInit(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

struct for_each_functor_MSG_MONSTER_SUMMON_BY_BELL
{// 2007-09-19 by cmkwon, Bell�� ��ȯ ó��
	for_each_functor_MSG_MONSTER_SUMMON_BY_BELL(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_MONSTER_SUMMON_BY_BELL i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterSummonByBell(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

struct for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE
{// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Key���� ���� 
	for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterCinemaMonsterCreate(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

// start 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�
struct for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY
{
	for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterCinemaMonsterDestroy(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};

struct for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE
{
	for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE(CNPCMapChannel *i_pNMChann)
		:m_pNMapChannel(i_pNMChann)
	{
	};
	void operator()(MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE i_Msg)
	{
		m_pNMapChannel->ProcessNPCOnMonsterCinemaMonsterChange(&i_Msg);
	}
	CNPCMapChannel			*m_pNMapChannel;
};
// end 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ����/���� ��� �߰�

void CNPCMapChannel::ProcessReceivedAllProtocol(void)
{
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.lock();
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.swap(m_mtvectorMSG_FN_MONSTER_CREATE_OKProcess);	
	m_mtvectorMSG_FN_MONSTER_CREATE_OK.unlock();
	
	m_mtvectorMSG_FN_MONSTER_DELETE.lock();
	m_mtvectorMSG_FN_MONSTER_DELETE.swap(m_mtvectorMSG_FN_MONSTER_DELETEProcess);
	m_mtvectorMSG_FN_MONSTER_DELETE.unlock();

	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.lock();
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.swap(m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILLProcess);	
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILL.unlock();

	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.lock();
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.swap(m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTERProcess);
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTER.unlock();
	
	for_each(m_mtvectorMSG_FN_MONSTER_CREATE_OKProcess.begin(), m_mtvectorMSG_FN_MONSTER_CREATE_OKProcess.end()
		, for_each_functor_MSG_FN_MONSTER_CREATE_OK(this));
	m_mtvectorMSG_FN_MONSTER_CREATE_OKProcess.clear();
	
	for_each(m_mtvectorMSG_FN_MONSTER_DELETEProcess.begin(), m_mtvectorMSG_FN_MONSTER_DELETEProcess.end()
		, for_each_functor_MSG_FN_MONSTER_DELETE(this));
	m_mtvectorMSG_FN_MONSTER_DELETEProcess.clear();

	for_each(m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILLProcess.begin(), m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILLProcess.end()
		, for_each_functor_MSG_FN_MONSTER_SKILL_END_SKILL(this));
	m_mtvectorMSG_FN_MONSTER_SKILL_END_SKILLProcess.clear();
	
	for_each(m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTERProcess.begin(), m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTERProcess.end()
		, for_each_functor_MSG_FN_BATTLE_SET_ATTACK_CHARACTER(this));
	m_mtvectorMSG_FN_BATTLE_SET_ATTACK_CHARACTERProcess.clear();

	m_mtvectorMSG_FN_CITYWAR_START_WAR.lock();
	for_each(m_mtvectorMSG_FN_CITYWAR_START_WAR.begin(), m_mtvectorMSG_FN_CITYWAR_START_WAR.end()
		, for_each_functor_MSG_FN_CITYWAR_START_WAR(this));
	m_mtvectorMSG_FN_CITYWAR_START_WAR.clear();
	m_mtvectorMSG_FN_CITYWAR_START_WAR.unlock();

	m_mtvectorMSG_FN_CITYWAR_END_WAR.lock();
	for_each(m_mtvectorMSG_FN_CITYWAR_END_WAR.begin(), m_mtvectorMSG_FN_CITYWAR_END_WAR.end()
		, for_each_functor_MSG_FN_CITYWAR_END_WAR(this));
	m_mtvectorMSG_FN_CITYWAR_END_WAR.clear();
	m_mtvectorMSG_FN_CITYWAR_END_WAR.unlock();

	m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.lock();
	for_each(m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.begin(), m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.end()
		, for_each_functor_MSG_FN_CITYWAR_CHANGE_OCCUPY_INFO(this));
	m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.clear();
	m_mtvectorMSG_FN_CITYWAR_CHANGE_OCCUPY_INFO.unlock();	

	// 2006-11-20 by cmkwon
	m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.lock();
	for_each(m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.begin(), m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.end()
		, for_each_functor_MSG_FN_MONSTER_STRATEGYPOINT_INIT(this));
	m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.clear();
	m_mtvectorMSG_FN_MONSTER_STRATEGYPOINT_INIT.unlock();	
	
	// 2007-08-22 by cmkwon, �ش� ��ä�� ���� ��� �����ϱ� ��� �߰�
	m_mtvectMSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL.lock();
	for_each(m_mtvectMSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL.begin(), m_mtvectMSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL.end()
		, for_each_functor_MSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL(this));
	m_mtvectMSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL.clear();
	m_mtvectMSG_FN_NPCSERVER_DELETE_MONSTER_IN_MAPCHANNEL.unlock();	

	// 2007-08-24 by dhjin, �������� ���� ����
	m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.lock();
	for_each(m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.begin(), m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.end()
		, for_each_functor_MSG_FN_MONSTER_OUTPOST_INIT(this));
	m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.clear();
	m_mtvectorMSG_FN_MONSTER_OUTPOST_INIT.unlock();	

	// 2007-09-19 by cmkwon, Bell�� ��ȯ ó��
	m_mtvectMSG_MONSTER_SUMMON_BY_BELL.lock();
	for_each(m_mtvectMSG_MONSTER_SUMMON_BY_BELL.begin(), m_mtvectMSG_MONSTER_SUMMON_BY_BELL.end()
		, for_each_functor_MSG_MONSTER_SUMMON_BY_BELL(this));
	m_mtvectMSG_MONSTER_SUMMON_BY_BELL.clear();
	m_mtvectMSG_MONSTER_SUMMON_BY_BELL.unlock();	

	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Key���� ����
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.lock();
	for_each(m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.begin(), m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.end()
		, for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE(this));
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.clear();
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CREATE.unlock();	

	// start 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.lock();
	for_each(m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.begin(), m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.end()
		, for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY(this));
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.clear();
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_DESTROY.unlock();
	// end 2011-04-28 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�

	// start 2011-05-11 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.lock();
	for_each(m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.begin(), m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.end()
		, for_each_functor_MSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE(this));
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.clear();
	m_mtvectorMSG_FN_NPCSERVER_CINEMA_MONSTER_CHANGE.unlock();
	// end 2011-05-11 by hskim, ���Ǵ�Ƽ 3�� - �ó׸� ���� ��� �߰� - �ش� ��ä�� Ư�� ���� ���� ��� �߰�
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::IsProcessableWorker(DWORD i_dwCurTick)
/// \brief		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 
/// \author		cmkwon
/// \date		2008-12-03 ~ 2008-12-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::IsProcessableWorker(DWORD i_dwCurTick)
{
	if(FALSE == this->IsEnabled())
	{
		return FALSE;
	}

	if(FALSE == m_bExistUserInMapChannel)
	{
		// 2008-12-02 by cmkwon, ��ä�ο� ������ �������� ���� ������ 1�п� �ѹ����� Tick�� ó���Ѵ�.
		int nElapseTick = i_dwCurTick - m_dwWorkeredTick;
		if(60000 > nElapseTick)
		{
			return FALSE;
		}
	}
	else
	{
		// 2008-12-02 by cmkwon, ��ä�ο� ������ ���� ���� ������  1���̻� ��� �Ǿ��� ��쿡�� ������ �ִ��� üũ�� �Ѵ�.
		int nElapseTick = i_dwCurTick - m_dwChangedTickforExistUser;
		if(60000 < nElapseTick)
		{
			if(FALSE == m_pNPCIOCPServer->IsExistClient(this->GetMapChannelIndex()))
			{
				this->SetExistUserInMapChannel(FALSE);		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - ������ �������� ������ �����Ѵ�.
				return FALSE;
			}
			this->SetExistUserInMapChannel(TRUE);
		}
	}

	m_dwWorkeredTick	= i_dwCurTick;
	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::SetExistUserInMapChannel(BOOL i_bIsExistUser)
/// \brief		// 2008-12-03 by cmkwon, NPCServer Ŭ���̾�Ʈ ���� ��ä�� ó�� ���� - 
/// \author		cmkwon
/// \date		2008-12-04 ~ 2008-12-04
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SetExistUserInMapChannel(BOOL i_bIsExistUser)
{
	m_bExistUserInMapChannel	= i_bIsExistUser;
	m_dwChangedTickforExistUser	= timeGetTime();
}

BodyCond_t CNPCMapChannel::GetPreAttackBodyCondMask(INT i_nAttackItemIdx) {
	if(0 > i_nAttackItemIdx || ARRAY_SIZE_MONSTER_ITEM < i_nAttackItemIdx) {
		return NULL;
	}
	switch(i_nAttackItemIdx) {
		case 0 : return BODYCON_MON_PREATTACK1_MASK;
		case 1 : return BODYCON_MON_PREATTACK2_MASK;
		case 2 : return BODYCON_MON_PREATTACK3_MASK;
		case 3 : return BODYCON_MON_PREATTACK4_MASK;
		case 4 : return BODYCON_MON_PREATTACK5_MASK;
		case 5 : return BODYCON_MON_PREATTACK6_MASK;
		case 6 : return BODYCON_MON_PREATTACK7_MASK;
		case 7 : return BODYCON_MON_PREATTACK8_MASK;
		case 8 : return BODYCON_MON_PREATTACK9_MASK;
		case 9 : return BODYCON_MON_PREATTACK10_MASK;
		case 10 : return BODYCON_MON_PREATTACK11_MASK;
		case 11 : return BODYCON_MON_PREATTACK12_MASK;
		case 12 : return BODYCON_MON_PREATTACK13_MASK;
		case 13 : return BODYCON_MON_PREATTACK14_MASK;
		case 14 : return BODYCON_MON_PREATTACK15_MASK;
		case 15 : return BODYCON_MON_PRECONTROLSKILL_MASK;
	}
	return NULL;
}

BodyCond_t CNPCMapChannel::GetFireAttackBodyCondMask(INT i_nAttackItemIdx) {
	if(0 > i_nAttackItemIdx || ARRAY_SIZE_MONSTER_ITEM < i_nAttackItemIdx) {
		return NULL;
	}
	switch(i_nAttackItemIdx) {
		case 0 : return BODYCON_MON_FIREATTACK1_MASK;
		case 1 : return BODYCON_MON_FIREATTACK2_MASK;
		case 2 : return BODYCON_MON_FIREATTACK3_MASK;
		case 3 : return BODYCON_MON_FIREATTACK4_MASK;
		case 4 : return BODYCON_MON_FIREATTACK5_MASK;
		case 5 : return BODYCON_MON_FIREATTACK6_MASK;
		case 6 : return BODYCON_MON_FIREATTACK7_MASK;
		case 7 : return BODYCON_MON_FIREATTACK8_MASK;
		case 8 : return BODYCON_MON_FIREATTACK9_MASK;
		case 9 : return BODYCON_MON_FIREATTACK10_MASK;
		case 10 : return BODYCON_MON_FIREATTACK11_MASK;
		case 11 : return BODYCON_MON_FIREATTACK12_MASK;
		case 12 : return BODYCON_MON_FIREATTACK13_MASK;
		case 13 : return BODYCON_MON_FIREATTACK14_MASK;
		case 14 : return BODYCON_MON_FIREATTACK15_MASK;
		case 15 : return BODYCON_MON_FIRECONTROLSKILL_MASK;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::SendFSvrHPTalk(CNPCMonster *i_pMons, HPACTION_TALK_HPRATE * i_pTalkHPRate)
/// \brief		���Ǵ�Ƽ - ���� HP�� ���� ��� ����
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::SendFSvrHPTalk(CNPCMonster *i_pMons, HPACTION_TALK_HPRATE * i_pTalkHPRate) {
	INIT_MSG_WITH_BUFFER(MSG_FN_MONSTER_HPTALK, T_FN_MONSTER_HPTALK, pMonsterHPTalk, i_pBufSend);
	pMonsterHPTalk->ChannelIndex		= this->GetMapChannelIndex();
	pMonsterHPTalk->MonsterIndex		= i_pMons->MonsterIndex;
	pMonsterHPTalk->MonsterUnitKind		= i_pMons->MonsterInfoPtr->MonsterUnitKind;
	pMonsterHPTalk->HPValueRate			= i_pTalkHPRate->HPValueRate;
	pMonsterHPTalk->HPTalkImportance	= i_pTalkHPRate->HPTalkImportance;
	pMonsterHPTalk->HPCameraTremble		= i_pTalkHPRate->HPCameraTremble;
	pMonsterHPTalk->TargetIndex			= i_pTalkHPRate->TargetClientIdx;
	STRNCPY_MEMSET(pMonsterHPTalk->HPTalk, i_pTalkHPRate->HPTalk, SIZE_MAX_HPTALK_DESCRIPTION);

	return Send2FieldServerW(i_pBufSend, MSG_SIZE(MSG_FN_MONSTER_HPTALK));
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::SetAutoCreateMonsterChannel(BOOL i_bCreate)
/// \brief		���Ǵ�Ƽ - �� ������ ��������
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SetAutoCreateMonsterChannel(BOOL i_bCreate) {
	m_bAutoCreateMonsterChannel	= i_bCreate;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ChangeNewObject(ObjectIdx_t i_dwDeleteObjectUID, ObjectNum_t i_dwNewObject)
/// \brief		���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!!
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ChangeNewObject(ObjectIdx_t i_dwDeleteObjectUID, ObjectNum_t i_dwNewObject) {
	m_mtDeletedObjectInfoList.pushBackLock(i_dwDeleteObjectUID);		// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ
	m_pNPCMapProject->CreateNewObject(i_dwDeleteObjectUID, i_dwNewObject, &m_mtNewObjectInfoList);	// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::ResetChangeObject()
/// \brief		���Ǵ�Ƽ - ���� ������Ʈ�� ����!!!!
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::ResetChangeObject() {
	m_mtDeletedObjectInfoList.clearLock();	// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ
	m_mtNewObjectInfoList.clearLock();		// 2009-09-09 ~ 2010-01 by dhjin, ���Ǵ�Ƽ - �ҽ� üũ

	// start 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����
	vectorObjectInfoServer::iterator itr(m_vectorObjectMonsterInfoCopy.begin());
	for(; itr != m_vectorObjectMonsterInfoCopy.end(); itr++)
	{
		itr->m_bNotCreateMonster = TRUE;
		itr->m_EventInfo.m_dwLastTimeObjectMonsterCreated = 0;
	}
	// end 2011-06-02 ���Ǵ�Ƽ 3�� - ���� 6 - �ֱ��� ��ȯ ��� ����
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::GetMonsterIndexesByBell(BYTE i_byMonsterBell, vector<ClientIndex_t> *pClientIndexVector)
/// \brief		���Ǵ�Ƽ - �ʿ��� ����Bell���� ���� ã��
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::GetMonsterIndexesByBell(BYTE i_byMonsterBell, vector<ClientIndex_t> *pClientIndexVector) {
	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
	int nSize = m_mtvectorMonsterPtr.size();
	int returnSize = 0;
	for(int i=0; i < nSize; i++) {
		CNPCMonster		*pNMon = (CNPCMonster*)m_mtvectorMonsterPtr[i];
		if(NULL == pNMon
			|| MS_NULL == pNMon->m_enMonsterState) {
			continue;
		}
		
		MONSTER_INFO	*pMonInfo = pNMon->MonsterInfoPtr;
		if(NULL == pMonInfo) {
			continue;
		}

		if(i_byMonsterBell == pMonInfo->Belligerence) {
			pClientIndexVector->push_back(pNMon->MonsterIndex);
			returnSize++;
		}
	}

	return returnSize;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::NPCGetAdjacentMonsterIndexesByBell(D3DXVECTOR3 *pPos, int nDistance, int nBlockDistance, BYTE i_byMonsterBell, vector<ClientIndex_t> *pClientIndexVector)
/// \brief		���Ǵ�Ƽ - ���� ������ Bell���� ���� ã��
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::NPCGetAdjacentMonsterIndexesByBell(D3DXVECTOR3 *pPos, int nDistance, int nBlockDistance, BYTE i_byMonsterBell, vector<ClientIndex_t> *pClientIndexVector) {
	TWO_BLOCK_INDEXES	blockIdx;
	int					i, j;
	
#ifdef _DEBUG
	int tmpCap = pClientIndexVector->capacity();
	pClientIndexVector->clear();
	int tmpCap2 = pClientIndexVector->capacity();
	assert( tmpCap == tmpCap2 );
#endif
	
	m_pNPCMapProject->GetBlockAdjacentToPositionHalfDistance(pPos->x, pPos->z, nBlockDistance, blockIdx);
	
	pClientIndexVector->clear();
	i = blockIdx.sMinX;
	while(i <= blockIdx.sMaxX)
	{
		j = blockIdx.sMinZ;
		while(j <= blockIdx.sMaxZ)
		{
			CMapBlock	*pMapBlock = &m_arrMapBlock[i][j];
			
			if (false == pMapBlock->m_MonsterIndexMtlist.empty())
			{
				mtlistUnitIndex_t vectorTemp;
				pMapBlock->m_MonsterIndexMtlist.lock();
				{
					vectorTemp.reserve(pMapBlock->m_MonsterIndexMtlist.size());
					vectorTemp.insert(vectorTemp.end()
						, pMapBlock->m_MonsterIndexMtlist.begin(), pMapBlock->m_MonsterIndexMtlist.end());
				}
				pMapBlock->m_MonsterIndexMtlist.unlock();
				
				for_each(vectorTemp.begin(), vectorTemp.end()
					, for_each_functor_NPCGetAdjacentMonsterIndexesByBell(this, pPos, nDistance, pClientIndexVector, i_byMonsterBell));
			}
			j++;
		}
		i++;
	}

	return pClientIndexVector->size();
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::GetMonsterIndexesByTargetMonsterNum(INT i_nTargetMonsterNum, vector<ClientIndex_t> *pClientIndexVector)
/// \brief		���Ǵ�Ƽ - �ʿ��� TargetMonster ã��
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::GetMonsterIndexesByTargetMonsterNum(INT i_nTargetMonsterNum, vector<ClientIndex_t> *pClientIndexVector)
{
// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - �Ʒ��� ���� ����
// 	mt_auto_lock mtA(&m_mtvectorMonsterPtr);
// 	int nSize = m_mtvectorMonsterPtr.size();
// 	int returnSize = 0;
// 	for(int i=0; i < nSize; i++)
// 	{
// 		CNPCMonster		*pNMon = GetNPCMonster() (CNPCMonster*)m_mtvectorMonsterPtr[i];
// 		if(NULL == pNMon
// 			|| MS_NULL == pNMon->m_enMonsterState) {
// 			continue;
// 		}
// 		
// 		MONSTER_INFO	*pMonInfo = pNMon->MonsterInfoPtr;
// 		if(NULL == pMonInfo) {
// 			continue;
// 		}
// 		
// 		if(i_nTargetMonsterNum == pMonInfo->MonsterUnitKind) {
// 			pClientIndexVector->push_back(pNMon->MonsterIndex);
// 			returnSize++;
// 		}
// 	}
// 	
// 	return returnSize;
	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
	if(0 == i_nTargetMonsterNum){			return 0;}

 	int returnSize = 0;
	CNPCMonster		*pNPCMon = NULL;
	for (int nIdxMonsterArray = 0; nIdxMonsterArray < m_nSizemtvectorMonsterPtr; nIdxMonsterArray++)	
	{
		pNPCMon = &m_ArrNPCMonster[nIdxMonsterArray];
		if(NULL == pNPCMon
			|| FALSE == pNPCMon->IsValidMonster())
		{
			continue;
		}

		MONSTER_INFO *pMonInfo = pNPCMon->MonsterInfoPtr;
		if(NULL == pMonInfo)
		{
			continue;
		}
		
		if(i_nTargetMonsterNum == pMonInfo->MonsterUnitKind)
		{
			pClientIndexVector->push_back(pNPCMon->MonsterIndex);
			returnSize++;
		}
	}
	return returnSize;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::NPCGetTargetMonsterwithAttackObj(BYTE AttackObj, CMonster *pAttackMon, vector<ClientIndex_t> &ClientIndexVector)
/// \brief		���Ǵ�Ƽ - TargetMonster �����ϱ�
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::NPCGetTargetMonsterwithAttackObj(BYTE AttackObj, CMonster *pAttackMon, vector<ClientIndex_t> &ClientIndexVector)
{
	// start 2011-06-17 ���Ǵ�Ƽ 3�� - �� ���� ���ϴ� ���� ���� 
	int iMTCount = 0;
	D3DXVECTOR3 PositionMTVector(0.0f, 0.0f, 0.0f);
	// end 2011-06-17 ���Ǵ�Ƽ 3�� - �� ���� ���ϴ� ���� ���� 

	if(ClientIndexVector.empty()){				return 0;}

	///////////////////////////////////////////////////////////////////////////////
	// 2007-05-22 by cmkwon, ����-->Ÿ�ٿ��� ������Ʈ �浹üũ �߰���
	CNPCMonster		*pMonster = NULL;
	BOOL			bRecognizeInvisible = COMPARE_MPOPTION_BIT(pAttackMon->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE);
	vectClientIndex_t::iterator itr(ClientIndexVector.begin());
	while(itr != ClientIndexVector.end()) {
		pMonster = GetNPCMonster(*itr);

		// start 2011-06-17 ���Ǵ�Ƽ 3�� - �� ���� ���ϴ� ���� ���� 
			if( pMonster->IsMultiTargetMonster() == TRUE ) 
			{
			PositionMTVector = pMonster->GetNearMultiTarget(pAttackMon->PositionVector, &iMTCount);
		}
		else
		{
			PositionMTVector = pMonster->PositionVector;
		}
		// end 2011-06-17 ���Ǵ�Ƽ 3�� - �� ���� ���ϴ� ���� ���� 

		if(NULL == pMonster
			|| FALSE != CheckImpactStraightLineMapAndObjects(&pAttackMon->PositionVector, &PositionMTVector		// 2011-06-17 ���Ǵ�Ƽ 3�� - �� ���� ���ϴ� ���� ����
				, DEFAULT_OBJECT_MONSTER_OBJECT+pAttackMon->MonsterInfoPtr->MonsterUnitKind)) {

			itr = ClientIndexVector.erase(itr);
			continue;
		}
		itr++;
	}
	if(ClientIndexVector.empty()){				return 0;}

	int				nRetTarget = 0;
	if(ClientIndexVector.size() == 1) {
		pMonster = GetNPCMonster(ClientIndexVector[0]);
		if(pMonster) {
			return ClientIndexVector[0];
		}
		return 0;
	}

	switch(AttackObj)
	{
	case ATTACKOBJ_CLOSERANGE: {
			float	fDistance;
			float	fMinDistance = this->GetMonsterVisibleDiameterW();
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			while(itr != ClientIndexVector.end()) {
				pMonster = GetNPCMonster(*itr);
				if(pMonster					
					&& (fDistance = D3DXVec3Length(&(pMonster->PositionVector - pAttackMon->PositionVector))) < fMinDistance) {
					nRetTarget = *itr;
					fMinDistance = fDistance;
				}
				itr++;
			}
		}
		break;
	case ATTACKOBJ_LOWHP: {
			float	fMinHP = 65535.0f;
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			while(itr != ClientIndexVector.end()) {
				pMonster = GetNPCMonster(*itr);
				if(pMonster
					&& pMonster->CurrentHP < fMinHP) {
					nRetTarget = *itr;
					fMinHP = pMonster->CurrentHP;
				}
				itr++;
			}
		}
		break;
	case ATTACKOBJ_HIGHHP: {
			float	fMaxHP = 0.0f;
			vector<ClientIndex_t>::iterator itr = ClientIndexVector.begin();
			while(itr != ClientIndexVector.end()) {
				pMonster = GetNPCMonster(*itr); 
				if(pMonster
					&& pMonster->CurrentHP > fMaxHP) {
					nRetTarget = *itr;
					fMaxHP = pMonster->CurrentHP;
				}
				itr++;
			}
		}
		break;
	default:
		// ATTACKOBJ_FIRSTATTACK
		// ATTACKOBJ_SAMERACE
		// ATTACKOBJ_RANDOM
		{
			for(int i=0; i < 5; i++) {
				nRetTarget = ClientIndexVector[GetTickCount()%ClientIndexVector.size()];
				pMonster = GetNPCMonster(nRetTarget); // 2009-09-09 ~ 2010-01-11 by dhjin, ���Ǵ�Ƽ - ���Ͱ� Ÿ�� ������ ���� ����
				if(pMonster) {
					return nRetTarget;
				}
			}
			nRetTarget = 0;
		}
	}

	return nRetTarget;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::BattleAttackSecMultiTargetMonster(CNPCMonster *i_pAttackMon, CNPCMonster *i_pTargetMonster, int MultiTargetCheckSize)
/// \brief		���Ǵ�Ƽ - 2�� ���� ��Ƽ Ÿ�� ���� ó��
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		���� ���� ���� ��
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::BattleAttackSecMultiTargetMonster(CNPCMonster *i_pAttackMon, CNPCMonster *i_pTargetMonster, int MultiTargetCheckSize) {
	int		MultiTargetCount  = 0;
	vectorClientIndex tmClientIdxList;
	tmClientIdxList.reserve(10);
	if(BELL_INFINITY_DEFENSE_MONSTER == i_pAttackMon->MonsterInfoPtr->Belligerence) {
		if(0 >= NPCGetAdjacentMonsterIndexesByBell(&i_pAttackMon->PositionVector, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range
			, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range*2, BELL_INFINITY_ATTACK_MONSTER, &tmClientIdxList)) {
			return MultiTargetCount;
		}
	}
	else if(BELL_INFINITY_ATTACK_MONSTER == i_pAttackMon->MonsterInfoPtr->Belligerence) {
		if(0 >= NPCGetAdjacentMonsterIndexesByBell(&i_pAttackMon->PositionVector, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range
			, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range*2, BELL_INFINITY_DEFENSE_MONSTER, &tmClientIdxList)) {
			return MultiTargetCount;
		}
	}
	else {
		if(0 >= NPCGetAdjacentMonsterIndexes(&i_pAttackMon->PositionVector, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range
			, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range*2, &tmClientIdxList)) {
			return MultiTargetCount;
		}
	}
	int CheckSize = MultiTargetCheckSize;
	if(tmClientIdxList.size() < MultiTargetCheckSize) {
		// �ټ� ������ ��׷� ����Ʈ ���� ���ٸ� ��׷� ����Ʈ ���� �ִ뷮 �Ҵ�.
		CheckSize = tmClientIdxList.size();
	}
	vectorClientIndex::iterator itr(tmClientIdxList.begin());
	for(; itr != tmClientIdxList.end(); itr++) {
		CNPCMonster		* ptmMonsterInfo = GetNPCMonster(*itr);
		if(NULL != i_pTargetMonster
			&& NULL != ptmMonsterInfo
			&& ptmMonsterInfo->MonsterIndex == i_pTargetMonster->MonsterIndex) {
			// �̹� ó���� ����, ���� ���� ��������
			continue;
		}
		if(NULL != ptmMonsterInfo && ptmMonsterInfo->m_enMonsterState == MS_PLAYING) {

			// start 2011-03-24 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
			//////////
			// ���� //
			// this->SendFSvrBattleAttackSec(i_pAttackMon, ptmMonsterInfo->MonsterIndex, &ptmMonsterInfo->PositionVector);	

			//////////
			// ���� //
			int fMonsterMultiTargetIndex = 0;
			D3DXVECTOR3 fMonsterMultiTargetVector = ptmMonsterInfo->GetNearMultiTarget(i_pAttackMon->PositionVector, &fMonsterMultiTargetIndex);

			this->SendFSvrBattleAttackSec(i_pAttackMon, ptmMonsterInfo->MonsterIndex, &fMonsterMultiTargetVector, fMonsterMultiTargetIndex);
			// end 2011-03-24 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

			MultiTargetCount++;
		}
		if(MultiTargetCount >= CheckSize) {
			break;
		}
	}	
	
	return MultiTargetCount;

}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::BattleAttackSecMultiTargetUser(CNPCMonster *i_pAttackMon, CLIENT_INFO * i_pClientInfo, int MultiTargetCheckSize)
/// \brief		���Ǵ�Ƽ - 2�� ���� ��Ƽ Ÿ�� ó��
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		���� ���� ���� ��
///////////////////////////////////////////////////////////////////////////////
int CNPCMapChannel::BattleAttackSecMultiTargetUser(CNPCMonster *i_pAttackMon, CLIENT_INFO * i_pClientInfo, int MultiTargetCheckSize) {
	int		MultiTargetCount  = 0;
	vectorClientIndex tmClientIdxList;
	tmClientIdxList.reserve(10);
	if(0 >= NPCGetAdjacentCharacterIndexes(&i_pAttackMon->PositionVector, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range
		, i_pAttackMon->m_pUsingMonsterItem->pItemInfo->Range*2, &tmClientIdxList, i_pAttackMon->MonsterInfoPtr->Belligerence)) {
		return MultiTargetCount;
	}
	int CheckSize = MultiTargetCheckSize;
	if(tmClientIdxList.size() < MultiTargetCheckSize) {
		// �ټ� ������ ��׷� ����Ʈ ���� ���ٸ� ��׷� ����Ʈ ���� �ִ뷮 �Ҵ�.
		CheckSize = tmClientIdxList.size();
	}
	vectorClientIndex::iterator itr(tmClientIdxList.begin());
	for(; itr != tmClientIdxList.end(); itr++) {
		CLIENT_INFO		* ptmClientInfo = GetClientInfo(*itr);
		if(NULL != i_pClientInfo
			&& NULL != ptmClientInfo
			&& ptmClientInfo->ClientIndex == i_pClientInfo->ClientIndex) {
			// �̹� ó���� ����, ���� ���� ��������
			continue;
		}
		if(NULL != ptmClientInfo && ptmClientInfo->ClientState == CS_GAMESTARTED) {
			this->SendFSvrBattleAttackSec(i_pAttackMon, ptmClientInfo->ClientIndex, &ptmClientInfo->PositionVector);
			MultiTargetCount++;
		}
		if(MultiTargetCount >= CheckSize) {
			break;
		}
	}	

	return MultiTargetCount;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CNPCMapChannel::SendFSvrBattleAttackSec(CNPCMonster *i_pAttackMon, ClientIndex_t i_ClientIdx, D3DXVECTOR3 * i_pTargetPosition) 
/// \brief		���Ǵ�Ƽ - 2�� ���� ���� ��Ŷ
/// \author		dhjin
/// \date		2009-09-09 ~ 2010
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SendFSvrBattleAttackSec(CNPCMonster *i_pAttackMon, ClientIndex_t i_ClientIdx, D3DXVECTOR3 * i_pTargetPosition, int fMonsterMultiTargetIndex) // 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰� - fMonsterMultiTargetIndex �� �߰�
{
	///////////////////////////////////////////////////////////////////////
	// MultiNum ó��
	BYTE byExplosionPos = 128 - i_pAttackMon->m_pUsingMonsterItem->pItemInfo->MultiNum/2;		
	for(int i = 0; i < i_pAttackMon->m_pUsingMonsterItem->pItemInfo->MultiNum; i++)
	{
		INIT_MSG_WITH_BUFFER(MSG_FN_BATTLE_ATTACK_SECONDARY, T_FN_BATTLE_ATTACK_SECONDARY, pSendBattleAttackSec, pSendBuf);
		pSendBattleAttackSec->ChannelIndex		= m_MapChannelIndex.ChannelIndex;
		pSendBattleAttackSec->AttackIndex		= i_pAttackMon->MonsterIndex;
		pSendBattleAttackSec->TargetIndex		= i_ClientIdx;
		pSendBattleAttackSec->WeaponIndex		= m_uiMissileUniqueIndex++;
		pSendBattleAttackSec->WeaponItemNumber	= i_pAttackMon->m_pUsingMonsterItem->pItemInfo->ItemNum;
		pSendBattleAttackSec->TargetPosition	= *i_pTargetPosition;
		pSendBattleAttackSec->MultiTargetIndex  = fMonsterMultiTargetIndex;		// 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		pSendBattleAttackSec->Distance			= byExplosionPos;
		pSendBattleAttackSec->SecAttackType		= 0;
		pSendBattleAttackSec->AttackPosition	= i_pAttackMon->PositionVector;		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ��ġ
		Send2FieldServerW(pSendBuf, MSG_SIZE(MSG_FN_BATTLE_ATTACK_SECONDARY));
		
		if(0 == i_pAttackMon->m_pUsingMonsterItem->pItemInfo->MultiNum%2
			&& 127 == byExplosionPos)
		{
			byExplosionPos = 129;
		}
		else
		{
			byExplosionPos++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-01-06 by cmkwon, ���� ���ݽ� Ÿ�� ���� ���� üũ �߰�(Ÿ�ٺ���) - 
/// \author		cmkwon
/// \date		2010-01-06 ~ 2010-01-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::GetTargetObject(BOOL *o_pbIsTargetCharacter, CLIENT_INFO **o_ppClient, CNPCMonster **o_ppMonster, CNPCMonster *i_pNMon, BOOL i_bLiveCheck/*=TRUE*/)
{
	*o_pbIsTargetCharacter	= FALSE;
	*o_ppClient		= NULL;
	*o_ppMonster	= NULL;

	if(FALSE == i_pNMon->IsValidMonster())
	{
		return FALSE;
	}

	ClientIndex_t targetIdx = i_pNMon->GetTargetIndex();
	// 2009-09-09 ~ 2010-01-11 by dhjin, ���Ǵ�Ƽ - ���Ͱ� Ÿ�� ������ ���� ����, �ذ� ���� ����
//	if(FALSE == IS_VALID_CLIENT_INDEX(targetIdx))
	if(FALSE == IS_VALID_CHARACTER_AND_MONSTER_INDEX(targetIdx))
	{
		return FALSE;
	}

	if(IS_CHARACTER_CLIENT_INDEX(targetIdx))
	{
		CLIENT_INFO *pCli = this->GetClientInfo(targetIdx, &(this->GetMapChannelIndex()));
		if(NULL == pCli
			|| FALSE == pCli->IsValidClient(i_bLiveCheck))
		{
			return FALSE;
		}
		*o_pbIsTargetCharacter	= TRUE;
		*o_ppClient				= pCli;
	}
	else
	{
		CNPCMonster *pNMon = this->GetNPCMonster(targetIdx);
		if(NULL == pNMon
			|| FALSE == pNMon->IsValidMonster(i_bLiveCheck))
		{
			return FALSE;
		}
		*o_pbIsTargetCharacter	= FALSE;
		*o_ppMonster			= pNMon;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-01-06 by cmkwon, ���� ���ݽ� Ÿ�� ���� ���� üũ �߰�(Ÿ�ٺ���) - 
/// \author		cmkwon
/// \date		2010-01-06 ~ 2010-01-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::CheckValidTarget(CNPCMonster *i_pNMon)
{
	BOOL bIsTargetCharacter = FALSE;
	CLIENT_INFO *pTargetCli	= NULL;
	CNPCMonster *pTargetMon	= NULL;

	if(FALSE == GetTargetObject(&bIsTargetCharacter, &pTargetCli, &pTargetMon, i_pNMon))
	{// 2010-01-06 by cmkwon, Ÿ���� ��ȿ���� �ʴ�
		i_pNMon->DeleteAttackedInfowithIndex();
		return FALSE;
	}

	if(MONSTER_TARGETTYPE_TUTORIAL == i_pNMon->m_byMonsterTargetType)
	{// 2010-01-06 by cmkwon, Ʃ�丮�� ���ʹ� ��ȿ�� üũ �ʿ� ����.
		return TRUE;
	}

	int nElapsedTickCheckValidTarget = (int)((INT64)i_pNMon->m_dwCurrentTick - (INT64)i_pNMon->GetTimeCheckValidTarget());
	if(1000 > nElapsedTickCheckValidTarget)
	{// 2010-01-06 by cmkwon, 1�ʸ��� Ÿ�� ��ȿ�� üũ
		return TRUE;
	}
	i_pNMon->SetTimeCheckValidTarget(i_pNMon->m_dwCurrentTick);

	// start 2011-06-13 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
	int fMonsterMultiTargetIndex = 0;

	//////////
	// ����
	//D3DXVECTOR3	Vec3TargetPos		= (FALSE == bIsTargetCharacter) ? pTargetMon->PositionVector : pTargetCli->PositionVector;

	//////////
	// ����
	D3DXVECTOR3	Vec3TargetPos		= (FALSE == bIsTargetCharacter) ? pTargetMon->GetNearMultiTarget(i_pNMon->PositionVector, &fMonsterMultiTargetIndex) : pTargetCli->PositionVector;
	// end 2011-06-13 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

	D3DXVECTOR3 Vec3Me2Targ			= i_pNMon->PositionVector - Vec3TargetPos;
	D3DXVECTOR3	Vec3Me2TargPlane(Vec3Me2Targ.x, 0.0f, Vec3Me2Targ.z);
	float		fDistMe2TargPlane	= D3DXVec3Length(&Vec3Me2TargPlane);			// ��� �Ÿ��� ���Ѵ�.

	if(fDistMe2TargPlane > i_pNMon->MonsterInfoPtr->Range)
	{
		int nElapsedTickAfterAttack = (int)((INT64)i_pNMon->m_dwCurrentTick - (INT64)i_pNMon->m_dwTimeMonsterLastAttack);
		if(TICK_MONSTER_DELETE_TARGET_TERM < nElapsedTickAfterAttack)
		{
			i_pNMon->DeleteAttackedInfowithIndex();
			return FALSE;
		}
	}
	
	if(TRUE == this->CheckImpactStraightLineMapAndObjects(&i_pNMon->PositionVector, &Vec3TargetPos, DEFAULT_OBJECT_MONSTER_OBJECT+i_pNMon->MonsterInfoPtr->MonsterUnitKind, TRUE))
	{
		int nElapsedTick = (int)((INT64)i_pNMon->m_dwCurrentTick - (INT64)i_pNMon->GetTimeCheckedLastValidTarget());
		if(5000 < nElapsedTick)
		{// 2010-01-06 by cmkwon, 5���̻� Ÿ���� ��ȿ���� ������ Ÿ���� �����Ѵ�.
			i_pNMon->DeleteAttackedInfowithIndex();
		}
		return FALSE;
	}
	i_pNMon->SetTimeCheckedLastValidTarget(i_pNMon->m_dwCurrentTick);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
/// \author		cmkwon
/// \date		2010-03-16 ~ 2010-03-16
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::SearchTarget(CNPCMonster *i_pNMon)
{
	ClientIndex_t		retTarIdx = 0;
	vectClientIndex_t targetIdxList;
	targetIdxList.reserve(100);

	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - �Ʊ� Ÿ�� ��ƾ� �Ǵ� ��ųŸ��Ÿ�Ծ������̸� ���⼭ Ÿ�� ó��~!!!
	retTarIdx = this->GetOurTagetByUsingItem(i_pNMon);
	if(FALSE != retTarIdx)
	{
		return retTarIdx;
	}

	// 2010-03-16 by cmkwon, 1/3. BELL_INFINITY_DEFENSE_MONSTER : MtoM, ĳ���ʹ� �Ʊ�
	if(BELL_INFINITY_DEFENSE_MONSTER == i_pNMon->MonsterInfoPtr->Belligerence)
	{
		// �������� BELL_INFINITY_ATTACK_MONSTER�� ���͸� �˻�
		if(0 != NPCGetAdjacentMonsterIndexesByBell(&i_pNMon->PositionVector, i_pNMon->MonsterInfoPtr->AttackRange, i_pNMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_ATTACK_MONSTER, &targetIdxList))
		{
			retTarIdx = NPCGetTargetMonsterwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
		}

		// 2009-12-10 by cmkwon, TEMP 
		//g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 30000 CNPCMapChannel::SearchTarget# MonIdx(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d) nAttackerCnt(%d) \r\n"
		//	, i_pNMon->MonsterIndex, i_pNMon->m_nTargetIndex, retTarIdx, i_pNMon->m_dwCurrentTick, i_pNMon->m_mtvectorAttackedInfoPtr.size());		
		return retTarIdx;
	}

	// 2010-03-16 by cmkwon, 2/3. BELL_INFINITY_ATTACK_MONSTER : MtoM, MtoC, ĳ���ʹ� �ش� ������ ����
	if (BELL_INFINITY_ATTACK_MONSTER == i_pNMon->MonsterInfoPtr->Belligerence)
	{
		// 2010-03-16 by cmkwon, 2/3-1/4. MonsterTarget�� 1�� �켱 �˻��ؼ� üũ
		if(0 == retTarIdx
			&& 0 != this->GetMonsterIndexesByTargetMonsterNum(i_pNMon->MonsterInfoPtr->MonsterTarget, &targetIdxList))
		{
			retTarIdx = NPCGetTargetMonsterwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
		}

		// 2010-03-16 by cmkwon, 2/3-2/4. MonsterTarget2�� 2�� �켱 �˻��ؼ� üũ
		if(0 == retTarIdx
			&& 0 != this->GetMonsterIndexesByTargetMonsterNum(i_pNMon->MonsterInfoPtr->MonsterTarget2, &targetIdxList))
		{
			retTarIdx =  NPCGetTargetMonsterwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
		}

		// 2010-03-16 by cmkwon, 2/3-3/4. ������ ĳ���͸� 3�� �˻��ؼ� üũ
		if(0 == retTarIdx
			&& 0 != NPCGetAdjacentCharacterIndexes(&i_pNMon->PositionVector, i_pNMon->MonsterInfoPtr->AttackRange, i_pNMon->MonsterInfoPtr->AttackRange*2, &targetIdxList, i_pNMon->MonsterInfoPtr->Belligerence))
		{
			retTarIdx = NPCGetTargetwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
		}
		
		// 2010-03-17 by cmkwon, 2/3-4/4. �������� BELL_INFINITY_DEFENSE_MONSTER�� ���͸� 4�� �켱 �˻�
		if(0 == retTarIdx
			&& 0 != NPCGetAdjacentMonsterIndexesByBell(&i_pNMon->PositionVector, i_pNMon->MonsterInfoPtr->AttackRange, i_pNMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_DEFENSE_MONSTER, &targetIdxList))
		{
			retTarIdx = NPCGetTargetMonsterwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
		}

		// 2009-12-10 by cmkwon, TEMP 
		//g_pNPCGlobal->WriteSystemLogEX(TRUE, "[TEMP] infi2 100317 31000 CNPCMapChannel::SearchTarget# MonIdx(%d) CurTargetIndex(%d) NewTargetIdx(%d) CurTick(%d) nAttackerCnt(%d) \r\n"
		//	, i_pNMon->MonsterIndex, i_pNMon->m_nTargetIndex, targetIdxList, i_pNMon->m_dwCurrentTick, i_pNMon->m_mtvectorAttackedInfoPtr.size());

		return retTarIdx;
	}

	// 2010-03-16 by cmkwon, 3/3. ������ : M to C
	if(NPCGetAdjacentCharacterIndexes(&i_pNMon->PositionVector, i_pNMon->MonsterInfoPtr->AttackRange, i_pNMon->MonsterInfoPtr->AttackRange*2, &targetIdxList, i_pNMon->MonsterInfoPtr->Belligerence))
	{
		retTarIdx = NPCGetTargetwithAttackObj(i_pNMon->MonsterInfoPtr->AttackObject, i_pNMon, targetIdxList);
	}

	return retTarIdx;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-03-16 by cmkwon, ����2�� MtoM, MtoC Ÿ�� ���� ���� ���� - 
/// \author		cmkwon
/// \date		2010-03-16 ~ 2010-03-16
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::GetUnitObject(ClientIndex_t i_unitIdx, CLIENT_INFO **o_ppCliInfo, CNPCMonster **o_ppNPCMon)
{
	*o_ppCliInfo	= NULL;
	*o_ppNPCMon		= NULL;

	if(IS_CHARACTER_CLIENT_INDEX(i_unitIdx))
	{
		*o_ppCliInfo = this->GetClientInfo(i_unitIdx, &m_MapChannelIndex);
		return (BOOL)(*o_ppCliInfo);		// 2010-05-24 by cmkwon, ����2�� ���� NPC ���� �״� ���� ���� - 
	}
	
	if(IS_MONSTER_CLIENT_INDEX(i_unitIdx))
	{
		*o_ppNPCMon = this->GetNPCMonster(i_unitIdx);
		return (BOOL)(*o_ppNPCMon);			// 2010-05-24 by cmkwon, ����2�� ���� NPC ���� �״� ���� ���� - 
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::SetMultiTargetEnemy8CheckFullList(vector<ClientIndex_t> * i_pTargetIndexList, vector<ClientIndex_t> *o_pTargetIndexList, ClientIndex_t i_ExceptTargetIdx, int MultiTargetCheckSize)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::SetMultiTargetEnemy8CheckFullList(vector<ClientIndex_t> * i_pTargetIndexList, vector<ClientIndex_t> *o_pTargetIndexList, ClientIndex_t i_ExceptTargetIdx, int MultiTargetCheckSize)
{
	if(NULL == i_pTargetIndexList
		|| NULL == o_pTargetIndexList)
	{
		return FALSE;
	}

	vectorClientIndex::iterator itr = i_pTargetIndexList->begin();
	for(; itr != i_pTargetIndexList->end(); itr++)
	{
		if(MultiTargetCheckSize <= o_pTargetIndexList->size()) 
		{
			return TRUE;
		}
		
		if(i_ExceptTargetIdx != *itr) 
		{
			o_pTargetIndexList->push_back(*itr);
		}
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::GetMultiTargetEnemyList(CNPCMonster *i_pMon, ClientIndex_t i_TargetIdx,vector<ClientIndex_t> *o_pTargetIndexList, int MultiTargetCheckSize, BOOL i_bCheckDistance /*= TRUE*/)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::GetMultiTargetEnemyList(CNPCMonster *i_pMon, ClientIndex_t i_TargetIdx, vector<ClientIndex_t> *o_pTargetIndexList, int MultiTargetCheckSize, BOOL i_bCheckDistance /*= TRUE*/)
{
	if(NULL == i_pMon
		|| NULL == o_pTargetIndexList)
	{
		return;
	}

	int TargetListCount = 0;
	vectorClientIndex	targetIdxList;
	targetIdxList.reserve(100);
	
	// Ÿ�� ���� �༮ �ϴ� �ְ�
	o_pTargetIndexList->push_back(i_TargetIdx);	
		
	// 2010-03-16 by cmkwon, 1/3. BELL_INFINITY_DEFENSE_MONSTER : MtoM, ĳ���ʹ� �Ʊ�
	if(BELL_INFINITY_DEFENSE_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		// �������� BELL_INFINITY_ATTACK_MONSTER�� ���͸� �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_ATTACK_MONSTER, &targetIdxList);
		this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
		return;
	}

	// 2010-03-16 by cmkwon, 2/3. BELL_INFINITY_ATTACK_MONSTER : MtoM, MtoC, ĳ���ʹ� �ش� ������ ����
	if (BELL_INFINITY_ATTACK_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		// 2010-03-16 by cmkwon, 2/3-1/4. MonsterTarget�� 1�� �켱 �˻��ؼ� üũ
		this->GetMonsterIndexesByTargetMonsterNum(i_pMon->MonsterInfoPtr->MonsterTarget, &targetIdxList);
		if(MultiTargetCheckSize < targetIdxList.size())
		{
			this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
			return;
		}
			
		// 2010-03-16 by cmkwon, 2/3-2/4. MonsterTarget2�� 2�� �켱 �˻��ؼ� üũ
		this->GetMonsterIndexesByTargetMonsterNum(i_pMon->MonsterInfoPtr->MonsterTarget2, &targetIdxList);
		if(MultiTargetCheckSize < targetIdxList.size())
		{
			this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
			return;			
		}
		
		// 2010-03-16 by cmkwon, 2/3-3/4. ������ ĳ���͸� 3�� �˻��ؼ� üũ
		this->NPCGetAdjacentCharacterIndexes(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, &targetIdxList, i_pMon->MonsterInfoPtr->Belligerence);
		if(MultiTargetCheckSize < targetIdxList.size())
		{
			this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
			return;			
		}
		
		// 2010-03-17 by cmkwon, 2/3-4/4. �������� BELL_INFINITY_DEFENSE_MONSTER�� ���͸� 4�� �켱 �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_DEFENSE_MONSTER, &targetIdxList);
		if(MultiTargetCheckSize < targetIdxList.size())
		{
			this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
			return;			
		}
	}
	
	// 2010-03-16 by cmkwon, 3/3. ������ : M to C
	this->NPCGetAdjacentCharacterIndexes(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, &targetIdxList, i_pMon->MonsterInfoPtr->Belligerence);
	this->SetMultiTargetEnemy8CheckFullList(&targetIdxList, o_pTargetIndexList, i_TargetIdx, MultiTargetCheckSize);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::GetMultiTargetEnemyList(CNPCMonster *i_pMon, vector<ClientIndex_t> *o_pTargetIndexList, BOOL i_bExceptMe /*= TRUE*/, BOOL i_bCheckDistance /*= TRUE*/)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::GetTargetOurList(CNPCMonster *i_pMon, vector<ClientIndex_t> *o_pTargetIndexList, BOOL i_bExceptMe /*= TRUE*/, BOOL i_bCheckDistance /*= TRUE*/)
{
	if(NULL == i_pMon
		|| NULL == o_pTargetIndexList)
	{
		return;
	}

	// 1. BELL_INFINITY_DEFENSE_MONSTER �� ���Ϳ� �Ʊ��� ã��. ����, BELL_INFINITY_DEFENSE_MONSTER �Ʊ�
	if(BELL_INFINITY_DEFENSE_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		vectClientIndex_t tmCliIdxList;			// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
		tmCliIdxList.reserve(100);

		// �������� BELL_INFINITY_DEFENSE_MONSTER ���͸� �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_DEFENSE_MONSTER, &tmCliIdxList);
		o_pTargetIndexList->insert(o_pTargetIndexList->end(), tmCliIdxList.begin(), tmCliIdxList.end());		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 

		// �������� ���� �˻�
		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - �������� �Ʊ����� ����Ʈ�� �����´�.
		this->NPCGetAdjacentCharacterIndexes(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, &tmCliIdxList, i_pMon->MonsterInfoPtr->Belligerence, FALSE);
		o_pTargetIndexList->insert(o_pTargetIndexList->end(), tmCliIdxList.begin(), tmCliIdxList.end());		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
	}
	
	// 2. BELL_INFINITY_ATTACK_MONSTER �� ���Ϳ� �Ʊ��� ã��. BELL_INFINITY_ATTACK_MONSTER �Ʊ�
	else if (BELL_INFINITY_ATTACK_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		// �������� BELL_INFINITY_DEFENSE_MONSTER ���͸� �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_ATTACK_MONSTER, o_pTargetIndexList);
	}

	if(TRUE == i_bExceptMe)
	{	// �ڱ� �ڽ��� ����
		this->DeleteClientIdx(o_pTargetIndexList, i_pMon->MonsterIndex);
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::DeleteClientIdx(vector<ClientIndex_t> *o_pTargetIndexList, ClientIndex_t i_DeleteClientIdx)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::DeleteClientIdx(vector<ClientIndex_t> *o_pTargetIndexList, ClientIndex_t i_DeleteClientIdx)
{
	if(NULL == o_pTargetIndexList)
	{
		return FALSE;
	}

	vector<ClientIndex_t>::iterator itr = o_pTargetIndexList->begin();
	while(itr!=o_pTargetIndexList->end())
	{
		if(i_DeleteClientIdx == *itr)
		{
			itr = o_pTargetIndexList->erase(itr);
			return TRUE;
		}
		itr++;
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ClientIndex_t CNPCMapChannel::GetTargetOur(CNPCMonster *i_pMon, BOOL i_bRepair /*= FALSE*/, BOOL i_bExceptMe /*= TRUE*/, BOOL i_bCheckDistance /*= TRUE*/)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ClientIndex_t CNPCMapChannel::GetTargetOur(CNPCMonster *i_pMon, BOOL i_bRepair /*= FALSE*/, BOOL i_bExceptMe /*= TRUE*/, BOOL i_bCheckDistance /*= TRUE*/)
{
	if(NULL == i_pMon)
	{
		return FALSE;
	}
	
	vectorClientIndex	targetIdxList;
	targetIdxList.reserve(100);

	// 1. BELL_INFINITY_DEFENSE_MONSTER �� ���Ϳ� �Ʊ��� ã��. ����, BELL_INFINITY_DEFENSE_MONSTER �Ʊ�
	if(BELL_INFINITY_DEFENSE_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		vectClientIndex_t tmCliIdxList;			// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
		tmCliIdxList.reserve(100);

		// �������� BELL_INFINITY_DEFENSE_MONSTER ���͸� �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_DEFENSE_MONSTER, &tmCliIdxList);
		targetIdxList.insert(targetIdxList.end(), tmCliIdxList.begin(), tmCliIdxList.end());		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 

		// �������� ���� �˻�
		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - �Ʊ� ĳ���� �˻��ϱ�
		this->NPCGetAdjacentCharacterIndexes(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, &tmCliIdxList, i_pMon->MonsterInfoPtr->Belligerence, FALSE);
		targetIdxList.insert(targetIdxList.end(), tmCliIdxList.begin(), tmCliIdxList.end());		// 2010-04-01 by cmkwon, ����2�� �߰� ���� - 
	}
	
	// 2. BELL_INFINITY_ATTACK_MONSTER �� ���Ϳ� �Ʊ��� ã��. BELL_INFINITY_ATTACK_MONSTER �Ʊ�
	else if (BELL_INFINITY_ATTACK_MONSTER == i_pMon->MonsterInfoPtr->Belligerence)
	{
		// �������� BELL_INFINITY_DEFENSE_MONSTER ���͸� �˻�
		this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, BELL_INFINITY_ATTACK_MONSTER, &targetIdxList);
	}

	if(TRUE == i_bExceptMe)
	{	// �ڱ� �ڽ��� ����
		this->DeleteClientIdx(&targetIdxList, i_pMon->MonsterIndex);
	}
	
	// ����� ã��
	if(TRUE == i_bRepair)
	{
		return this->GetPossibleRepairTarget(i_pMon, targetIdxList);
	}
	else 
	{
		return this->NPCGetTargetwithAttackObj(i_pMon->MonsterInfoPtr->AttackObject, i_pMon, targetIdxList);
	}

}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CNPCMapChannel::SetMonsterTargetInRangeByBell(CNPCMonster *i_pMon)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CNPCMapChannel::SetMonsterTargetInRangeByBell(CNPCMonster *i_pMon)
{
	if(NULL == i_pMon)
	{
		return;
	}

	vectorClientIndex	targetIdxList;
	targetIdxList.reserve(100);
	
	ClientIndex_t ChangeTargetClientIdx = i_pMon->m_nTargetIndex;

	this->NPCGetAdjacentMonsterIndexesByBell(&i_pMon->PositionVector, i_pMon->MonsterInfoPtr->AttackRange, i_pMon->MonsterInfoPtr->AttackRange*2, i_pMon->MonsterInfoPtr->Belligerence, &targetIdxList);

	CNPCMonster * ChangeTargetMonster = NULL;
	vectorClientIndex::iterator itr = targetIdxList.begin();
	for(;itr != targetIdxList.end();itr++)
	{
		ChangeTargetMonster = this->GetNPCMonster(*itr);
		if(NULL == ChangeTargetMonster
			|| FALSE == ChangeTargetMonster->IsValidMonster(TRUE))
		{
			continue;
		}
		ChangeTargetMonster->SelectTargetIndex(ChangeTargetClientIdx);
	}

}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ClientIndex_t CNPCMapChannel::GetOurTagetByUsingItem(CNPCMonster *i_pMon)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ClientIndex_t CNPCMapChannel::GetOurTagetByUsingItem(CNPCMonster *i_pMon)
{
	if(NULL == i_pMon->m_pUsingMonsterItem)
	{
		return FALSE;
	}
	ITEM *pAttItemInfo = i_pMon->m_pUsingMonsterItem->pItemInfo;
	if(NULL == pAttItemInfo
		|| ITEMKIND_FOR_MON_SKILL != pAttItemInfo->Kind)
	{
		return FALSE;
	}

	ClientIndex_t TargetIdx = 0;
	switch(pAttItemInfo->SkillTargetType)
	{
	case SKILLTARGETTYPE_ONE_OURS_INRANGE_WITHOUT_ME:
		{
			TargetIdx = this->GetTargetOur(i_pMon, this->CheckRepairDesParam(pAttItemInfo->ArrDestParameter[0]));
		}
		break;
	case SKILLTARGETTYPE_ALL_OURS_INRANGE_WITHOUT_ME:
		{
			TargetIdx = this->GetTargetOur(i_pMon, this->CheckRepairDesParam(pAttItemInfo->ArrDestParameter[0]));
		}
		break;
	default:
		{
		}
	}	

	return TargetIdx;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCMapChannel::CheckRepairDesParam(DestParam_t i_DestParam)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCMapChannel::CheckRepairDesParam(DestParam_t i_DestParam)
{
	switch(i_DestParam)
	{
		case DES_IMMEDIATE_HP_UP:
		case DES_IMMEDIATE_DP_UP:
		case DES_IMMEDIATE_SP_UP:
		case DES_IMMEDIATE_EP_UP:
		case DES_IMMEDIATE_HP_OR_DP_UP:
		{
			return TRUE;
		}
		break;
	default:
		{
			return FALSE;
		}
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ClientIndex_t CNPCMapChannel::GetPossibleRepairTarget(CMonster *pM, vector<ClientIndex_t> &ClientIndexVector)
/// \brief		���Ǵ�Ƽ(�������) - 
/// \author		dhjin
/// \date		2010-03-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ClientIndex_t CNPCMapChannel::GetPossibleRepairTarget(CMonster *pM, vector<ClientIndex_t> &ClientIndexVector)
{
	CLIENT_INFO		*pCli = NULL;
	CNPCMonster		*pNPCMon = NULL;
	BOOL			bRecognizeInvisible = COMPARE_MPOPTION_BIT(pM->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_INVISIBLE);
	BOOL			bRecognizeStealth = COMPARE_MPOPTION_BIT(pM->MonsterInfoPtr->MPOption, MPOPTION_BIT_RECOGNIZE_STEALTH);	// 2012-11-05 by jhseol, ���ڽ� ������ �ɸ��͸� �ν��Ѵ�.
	int				nRetTarget = 0;
	float			fDistance;
	float			fMinDistance = this->GetMonsterVisibleDiameterW();
	float			fMinHPRate = 100.0f;
	vectClientIndex_t::iterator itr(ClientIndexVector.begin());
	while(itr != ClientIndexVector.end())
	{
		pCli		= NULL;
		pNPCMon		= NULL;
		ClientIndex_t tarIdx = *itr;
		
		if(FALSE == this->GetUnitObject(tarIdx, &pCli, &pNPCMon))
		{
			itr = ClientIndexVector.erase(itr);
			continue;
		}
		if(pCli)
		{	// 1. ���� �⺻ üũ
			if(FALSE == pCli->IsValidClient()
				|| FALSE == pCli->IsEnbleTargeted(pM->MonsterInfoPtr->Belligerence, bRecognizeInvisible, bRecognizeStealth)	// 2012-11-05 by jhseol, ���ڽ� ������ �ɸ��͸� �ν��Ѵ�. bRecognizeStealth ���� �߰�
				|| FALSE != CheckImpactStraightLineMapAndObjects(&pM->PositionVector, &pCli->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+pM->MonsterInfoPtr->MonsterUnitKind))
			{
				itr = ClientIndexVector.erase(itr);
				continue;
			}

			// ���� Ÿ��, �� �� �Ÿ� üũ
			fDistance = D3DXVec3Length(&(pCli->PositionVector - pM->PositionVector));
			if(tarIdx != pM->m_nTargetIndex
				&& fDistance < fMinDistance
				)
			{
				nRetTarget		= tarIdx;
				fMinDistance	= fDistance;
			}
		}
		if(pNPCMon)
		{	// 1. ���� �⺻ üũ
			if(FALSE == pNPCMon->IsValidMonster()
				|| FALSE != CheckImpactStraightLineMapAndObjects(&pM->PositionVector, &pNPCMon->PositionVector, DEFAULT_OBJECT_MONSTER_OBJECT+pM->MonsterInfoPtr->MonsterUnitKind))
			{
				itr = ClientIndexVector.erase(itr);
				continue;
			}

			// ���� Ÿ��,�� �� �Ÿ� üũ
			fDistance = D3DXVec3Length(&(pNPCMon->PositionVector - pM->PositionVector));
			if(tarIdx != pM->m_nTargetIndex
				&& fDistance < fMinDistance
				&& (pNPCMon->CurrentHP*100/pNPCMon->MonsterInfoPtr->MonsterHP) < fMinHPRate)
			{
				nRetTarget		= tarIdx;
				fMinDistance	= fDistance;
				fMinHPRate		= pNPCMon->CurrentHP;
			}
		}
		itr++;
	}
	if(ClientIndexVector.empty()){					return 0;}
	
	if(ClientIndexVector.size() == 1)
	{
		return ClientIndexVector[0];
	}

	return nRetTarget;
}

// start 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
CNPCIOCP *CNPCMapChannel::GetNPCIOCPServer()
{ 
	return m_pNPCIOCPServer; 
}
// end 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
