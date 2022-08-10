#include "stdafx.h"
#include "MonsterDBAccess.h"
#include "IOCP.h"
#include "AtumDBManager.h"
#include "Monster.h"
#define UNICODE
#include "odbcss.h"
#undef UNICODE
#include "Localization.h"

CMonsterDBAccess::CMonsterDBAccess()
{
	RETCODE		ret;

	henv = SQL_NULL_HENV;
	hdbc = SQL_NULL_HDBC;
	hstmt = SQL_NULL_HSTMT;

	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER);
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) {
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_ENV, hstmt,"GetMONSTER() Failed!\n", TRUE);
		return;
	}

	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - �Ʒ��� ���� ���� ��
//	ret = SQLConnect(hdbc, g_pGlobalGameServer->GetODBCDSN(), SQL_NTS, g_pGlobalGameServer->GetODBCUID(), SQL_NTS, g_pGlobalGameServer->GetODBCPASSWORD(), SQL_NTS);
	char szConnectionString[512];
	char szOutConnectionString[512]; SQLSMALLINT pcb;
#if defined(DB_SERVER_MYSQL)
	sprintf(szConnectionString, "DRIVER={MySQL ODBC 5.1 Driver};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
		, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), (char*)g_pGlobalGameServer->GetODBCUID(), (char*)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetDBServerDatabaseName());
#else
	sprintf(szConnectionString, "DRIVER={SQL Server};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
		, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), (char*)g_pGlobalGameServer->GetODBCUID(), (char*)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetDBServerDatabaseName());
#endif
	ret = SQLDriverConnect(hdbc, g_pGlobalGameServer->GetMainWndHandle(), (SQLCHAR*)szConnectionString, strlen(szConnectionString), (SQLCHAR*)szOutConnectionString, 512, &pcb, SQL_DRIVER_NOPROMPT);

	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) {

		// 2008-09-05 by cmkwon, DBServer ���� ���� �ý��� �α� ����� - 
		g_pGlobal->WriteSystemLogEX(TRUE, "[DB Error] fail to connect DBServer(CMonsterDBAccess::CMonsterDBAccess_) !! %s,%d %s %s %s\r\n"
			, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (CHAR*)g_pGlobalGameServer->GetODBCUID(), (CHAR*)g_pGlobalGameServer->GetODBCPASSWORD());
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_DBC, hstmt,"GetMONSTER() Failed!\n", TRUE);
		return;
	}

	// prints DB Info
	char DatabaseName[40];
	char DSN[40];
	SQLSMALLINT StrLen;
	SQLGetInfo(hdbc, SQL_DATABASE_NAME, (SQLPOINTER)DatabaseName, sizeof(DatabaseName), &StrLen);
	SQLGetInfo(hdbc, SQL_DATA_SOURCE_NAME, (SQLPOINTER)DSN, sizeof(DSN), &StrLen);

	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) {
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_STMT, hstmt,"GetMONSTER() Failed!\n", TRUE);
		return;
	}

}

CMonsterDBAccess::~CMonsterDBAccess()
{
	// cleanup odbc resources
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	SQLDisconnect(hdbc);
#ifndef _DEBUG
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
#endif
	SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

BOOL CMonsterDBAccess::MonsterMoveTypeCheck(MONSTER_INFO *pMon)
{
	switch(pMon->MonsterForm)
	{
	case FORM_FLYING_RIGHT:
	case FORM_SWIMMINGFLYING_RIGHT:
		switch(pMon->MovePattern)
		{
		//case MOVPAT_STOP:						// ������ ���ʹ� ���� �̵� Ÿ���� �ȵ�
		case MOVPAT_STRAIGHT:
		case MOVPAT_RIGHTANDLEFT:
		case MOVPAT_8RIGHTANDLEFT:
		case MOVPAT_PATROL:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_PARTY:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		case MOVPAT_UPANDDOWN:
		case MOVPAT_OBLIQUE:
		//case MOVPAT_OBLIQUEANDCURVE:			// �������� �������� ����
		case MOVPAT_TELEPORT:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		case MOVPAT_FOLLOWPATH:					// 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - FORM_FLYING_RIGHT / FORM_FLYING_COPTER �� ����
			return TRUE;
		}
		break;
	case FORM_FLYING_COPTER:
	case FORM_SWIMMINGFLYING_COPTER:					//
		switch(pMon->MovePattern)
		{
		case MOVPAT_STOP:
		case MOVPAT_STRAIGHT:
		case MOVPAT_RIGHTANDLEFT:
		case MOVPAT_8RIGHTANDLEFT:
		case MOVPAT_PATROL:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_PARTY:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		case MOVPAT_UPANDDOWN:
		case MOVPAT_OBLIQUE:
		case MOVPAT_OBLIQUEANDCURVE:
		case MOVPAT_TELEPORT:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		case MOVPAT_FOLLOWPATH:					// 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - FORM_FLYING_RIGHT / FORM_FLYING_COPTER �� ����
			return TRUE;
		}
		break;
	case FORM_GROUND_MOVE:
		switch(pMon->MovePattern)
		{
		case MOVPAT_STOP:
		case MOVPAT_STRAIGHT:
		case MOVPAT_RIGHTANDLEFT:
		case MOVPAT_8RIGHTANDLEFT:
		//case MOVPAT_PATROL:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_PARTY:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_UPANDDOWN:
		//case MOVPAT_OBLIQUE:
		//case MOVPAT_OBLIQUEANDCURVE:
		//case MOVPAT_TELEPORT:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_FOLLOWPATH:				// 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - FORM_FLYING_RIGHT / FORM_FLYING_COPTER �� ����
			return TRUE;
		}
		break;
	case FORM_FLYINGandGROUND_RIGHT:
		switch(pMon->MovePattern)
		{
		//case MOVPAT_STOP:						// ������ ���ʹ� ���� �̵� Ÿ���� �ȵ�
		case MOVPAT_STRAIGHT:
		case MOVPAT_RIGHTANDLEFT:
		case MOVPAT_8RIGHTANDLEFT:
		//case MOVPAT_PATROL:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_PARTY:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_UPANDDOWN:
		//case MOVPAT_OBLIQUE:
		//case MOVPAT_OBLIQUEANDCURVE:
		//case MOVPAT_TELEPORT:
		//case MOVPAT_FOLLOWPATH:				// 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - FORM_FLYING_RIGHT / FORM_FLYING_COPTER �� ����
			return TRUE;
		}
		break;
	case FORM_FLYINGandGROUND_COPTER:
		switch(pMon->MovePattern)
		{
		case MOVPAT_STOP:
		case MOVPAT_STRAIGHT:
		case MOVPAT_RIGHTANDLEFT:
		case MOVPAT_8RIGHTANDLEFT:
		//case MOVPAT_PATROL:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_PARTY:					// check cmkwon ���� ������ �ȵȰ�, ���� ���� �ؾ���
		//case MOVPAT_UPANDDOWN:
		//case MOVPAT_OBLIQUE:
		//case MOVPAT_OBLIQUEANDCURVE:
		//case MOVPAT_TELEPORT:
		//case MOVPAT_FOLLOWPATH:				// 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - FORM_FLYING_RIGHT / FORM_FLYING_COPTER �� ����
			return TRUE;
		}
		break;
	case FORM_OBJECT_STOP:
	case FORM_OBJECT_PLANE_ROTATE:
	case FORM_OBJECT_CANNON:
		if(pMon->MovePattern == MOVPAT_STOP)
		{
			return TRUE;
		}
		break;		
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CMonsterDBAccess::CheckMPOption(MONSTER_INFO *pMonInfo)
/// \brief		
/// \author		cmkwon
/// \date		2005-10-27 ~ 2005-10-27
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CMonsterDBAccess::CheckMPOption(MONSTER_INFO *pMonInfo)
{
	if( COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_MOVE_PARTY)
		&& COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_AUTO_DESTROY) )
	{
		return FALSE;
	}

	if(COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_MOVE_PARTY)
		&& 0 == pMonInfo->MPOptionParam2)
	{
		return FALSE;
	}

	if(COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_AUTO_DESTROY)
		&& 0 == pMonInfo->MPOptionParam1)
	{
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2010-03-26 by cmkwon, ����2�� ���� - �ΰ��� ������ �Ѵ� �ɼ��� ����
	if(COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_KEY_MONSTER)
		&& COMPARE_MPOPTION_BIT(pMonInfo->MPOption, MPOPTION_BIT_KEY_MONSTER_ALIVE_FOR_GAMECLEAR))
	{
		return FALSE;
	}


	///////////////////////////////////////////////////////////////////////////////
	// 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ��ȿ��(1�� ~ 15��)
	if(pMonInfo->ChangeTarget)
	{
		pMonInfo->ChangeTargetTime = max(1000, pMonInfo->ChangeTargetTime);
		pMonInfo->ChangeTargetTime = min(TICK_MONSTER_TARGET_UNCHANGE_TERM, pMonInfo->ChangeTargetTime);
	}
	return TRUE;
}

struct sort_MONSTER_INFO_By_MONSTER_ITEM_Charging
{
	bool operator()(MONSTER_ITEM op1, MONSTER_ITEM op2)
	{
		return op1.pItemInfo->Charging > op2.pItemInfo->Charging;				// �������� ����
	}
};

BOOL CMonsterDBAccess::GetAllMonsters(ez_map<int, MONSTER_INFO> &mapMonster, ez_map<INT, ITEM*> *pMapItemInfo, MonsterLoadType loadType, CLocalization *i_pLocalization)
{
	MONSTER_INFO retMonsterInfo;
	RETCODE ret;
	SQLINTEGER cb[CB_COUNT_MONSTER];

	// start 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
	MONSTER_MULTI_TARGET retMonsterTarget;
	vectorMonsterMultiTarget vectMonsterMultiTargetinfo;

	vectMonsterMultiTargetinfo.clear();
	
	ret = SQLExecDirect(hstmt, PROCEDURE_110317_0001, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) 
	{
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_STMT, hstmt,"CMonsterDBAccess::GetAllMonsterMultiTarget() Failed!\n", TRUE);
		
		return FALSE;
	}

	CAtumDBManager::BindColMonsterMultiTarget(hstmt, retMonsterTarget, cb);
	
	memset(&retMonsterTarget, 0x00, sizeof(MONSTER_MULTI_TARGET));
	while ( (ret = SQLFetch(hstmt)) != SQL_NO_DATA) 
	{
		vectMonsterMultiTargetinfo.push_back(retMonsterTarget);

		MEMSET_ZERO(&retMonsterTarget, sizeof(retMonsterTarget));
	}
	
	SQLFreeStmt(hstmt, SQL_CLOSE);
// end 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

	// 2013-08-28 by bckim, �������� ����ȭ
/*#ifndef _ATUM_NPC_SERVER
	BOSS_MONSTER_REWARD_INFO retBossMonsterReward;
	vectorBossMonsterReward vectBossMonsterRewardInfo;
	
	vectBossMonsterRewardInfo.clear();
	ret = SQLExecDirect(hstmt, PROCEDURE_130828_0001, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) 
	{
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_STMT, hstmt,"CMonsterDBAccess::GetBossMonsterRewardInfo() Failed!\n", TRUE);		
		return FALSE;
	}
	
	CAtumDBManager::BindColBossMonsterRewardInfo(hstmt, retBossMonsterReward, cb);

	memset(&retBossMonsterReward, 0x00, sizeof(BOSS_MONSTER_REWARD_INFO));
	while ( (ret = SQLFetch(hstmt)) != SQL_NO_DATA) 
	{
		vectBossMonsterRewardInfo.push_back(retBossMonsterReward);		
		MEMSET_ZERO(&retBossMonsterReward, sizeof(retBossMonsterReward));
	}	
	SQLFreeStmt(hstmt, SQL_CLOSE);	
	// End. 2013-08-28 by bckim, �������� ����ȭ
#endif*/

	// map�� reset�Ѵ�.
	mapMonster.clear();

	map <int, MONSTER_INFO> :: value_type mapValue;

	memset(&retMonsterInfo, 0x00, sizeof(MONSTER_INFO));

	if (loadType == MONSTER_LOAD_TYPE_SIZE_FOR_SERVER)
	{
		// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
		//ret = SQLExecDirect(hstmt, (UCHAR*)MONSTER_SQL_QUERY_FOR_SERVER, SQL_NTS);
		ret = SQLExecDirect(hstmt, PROCEDURE_080827_0063, SQL_NTS);
	}
	else if (loadType == MONSTER_LOAD_TYPE_SIZE_FOR_CLIENT)
	{
		// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
		//ret = SQLExecDirect(hstmt, (UCHAR*)MONSTER_SQL_QUERY_FOR_CLIENT, SQL_NTS);
		ret = SQLExecDirect(hstmt, PROCEDURE_080827_0062, SQL_NTS);
	}
	else
	{
		assert(0);
	}

	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) {
		CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_STMT, hstmt,"CMonsterDBAccess::GetAllMonsters() Failed!\n", TRUE);
		return FALSE;
	}

	// Parameter Binding
	CAtumDBManager::BindColMONSTER(hstmt, retMonsterInfo, cb);
	// initialize to 0x00
	memset(&retMonsterInfo, 0x00, sizeof(MONSTER_INFO));
	while ( (ret = SQLFetch(hstmt)) != SQL_NO_DATA)
	{
		if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO ) {
			CAtumDBHelper::ProcessLogMessagesStatic(SQL_HANDLE_STMT, hstmt,"CMonsterDBAccess::GetAllMonsters() Failed!\n", TRUE);
			return FALSE;
		}
		
		// 1. �����̸� ����ȭ ó��
		// 2005-05-23 by cmkwon, ����ȭ
		i_pLocalization->MonsterLocalization(retMonsterInfo.MonsterUnitKind, retMonsterInfo.MonsterName);

		// 2. ���� ������ �Ҵ�, ��Ʈ�� ��ų ����
		INT		nItemCount = 0;
		INT		nTmItemNum = 0;
		INT		nCommonItemCount = 0;		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �����۸� �����Ѵ�.
		int i{ 0 };
	
		for(i = 0; i < ARRAY_SIZE_MONSTER_ITEM-1; i++)
		{
			nTmItemNum								= (INT)(retMonsterInfo.ItemInfo[i].pItemInfo);
			retMonsterInfo.ItemInfo[i].pItemInfo	= NULL;			// ItemNum�� �������� NULL�� �Ҵ��Ѵ�.
			if(nTmItemNum)
			{
				////////////////////////////////////////////////////////////////////////////////
				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �����۸� �����Ѵ�. �ذ� ���� ����
//				retMonsterInfo.ItemInfo[nItemCount].pItemInfo = pMapItemInfo->findEZ(nTmItemNum);
//				if(retMonsterInfo.ItemInfo[nItemCount].pItemInfo)
//				{
//					nItemCount++;
//				}
//				else
//				{
//					char	szSystemLog[1024];
//					sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_1 Monster Item error, MonsterName[%20s: %6d] ItemNum[%d]\r\n"
//						, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, nTmItemNum);
//					g_pGlobal->WriteSystemLog(szSystemLog);
//					DBGOUT(szSystemLog);
//				}

				if(i < ARRAY_SIZE_MONSTER_ITEM - ARRAY_SIZE_MONSTER_SKILL_ITEM - 1) {
					retMonsterInfo.ItemInfo[nItemCount].pItemInfo = pMapItemInfo->findEZ(nTmItemNum);
					if(retMonsterInfo.ItemInfo[nItemCount].pItemInfo) {
						nItemCount++;
					}
					else
					{
						char	szSystemLog[1024];
						sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_1 Monster Item error, MonsterName[%20s: %6d] ItemNum[%d]\r\n"
							, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, nTmItemNum);
						g_pGlobal->WriteSystemLog(szSystemLog);
						DBGOUT(szSystemLog);
					}
				}
				else {
					retMonsterInfo.ItemInfo[i].pItemInfo = pMapItemInfo->findEZ(nTmItemNum);
					if(!retMonsterInfo.ItemInfo[i].pItemInfo) {
						char	szSystemLog[1024];
						sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_1 Monster Item error, MonsterName[%20s: %6d] ItemNum[%d]\r\n"
							, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, nTmItemNum);
						g_pGlobal->WriteSystemLog(szSystemLog);
						DBGOUT(szSystemLog);
					}
				}
			}
		}

		///////////////////////////////////////////////////////////////////////////////
		// 2006-12-15 by cmkwon, DB�� ������� �ε����� �����Ѵ�, ���� ���ݰ��� �ٵ� ����ǰ� ������ �ִ�
		for(i=0; i < ARRAY_SIZE_MONSTER_ITEM; i++)
		{
			retMonsterInfo.ItemInfo[i].byBodyConArrayIndex	= i;
		}
////////////////////////////////////////////////////////////////////////////////
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �����۸� �����Ѵ�. �ذ� ���� ����
		if(nItemCount > 1)
		{
			sort(retMonsterInfo.ItemInfo, &retMonsterInfo.ItemInfo[nItemCount], sort_MONSTER_INFO_By_MONSTER_ITEM_Charging());
		}
//		if(nCommonItemCount > 1) {
//			sort(retMonsterInfo.ItemInfo, &retMonsterInfo.ItemInfo[nCommonItemCount], sort_MONSTER_INFO_By_MONSTER_ITEM_Charging());
//		}

		// 3. byArrayIndex �Ҵ�, ���� ���� ó�� �� �Ҵ� �ؾ���
		// 2005-10-28 by cmkwon
		for(i=0; i < ARRAY_SIZE_MONSTER_ITEM; i++)
		{
			retMonsterInfo.ItemInfo[i].byArrayIndex	= i;
		}

		// 4. ���� �Ϲ� ��� ������ ���� ó��
		MONSTER_ITEM	*pLastItem = NULL;
		for(i = 0; i < ARRAY_SIZE_MONSTER_ITEM-1; i++)
		{
			MONSTER_ITEM *pMonsterItem = &(retMonsterInfo.ItemInfo[i]);
			if(pMonsterItem->pItemInfo)
			{
				if(pMonsterItem->pItemInfo->Charging > 0)
				{
					pMonsterItem->dwUsingPercent	= ((NULL==pLastItem)?0:pLastItem->dwUsingPercent) + pMonsterItem->pItemInfo->Charging;
					pLastItem						= pMonsterItem;
				}
			}
		}
// 2009-04-09 by cmkwon, ���� ������ üũ ��ƾ ���� - BELL_NOTATTACK �� �ƴϾ ���� ���Ⱑ ���� ���� ���� �� �ִ�.
// 		if( BELL_NOTATTACK != retMonsterInfo.Belligerence
// 			&& FALSE == IS_STRATEGYPOINT_MONSTER(retMonsterInfo.Belligerence)		// 2006-12-13 by cmkwon, ��������Ʈ ���͵� ���� �������� �ʴ´�
// 			&& (NULL == pLastItem || 100 < pLastItem->dwUsingPercent) )
// 		{
// 			char	szSystemLog[1024];
// 			sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_2 Monster Item error, MonsterName[%20s: %6d] TotalUsingPercent[%d]\r\n"
// 				, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, (NULL==pLastItem)?0:pLastItem->dwUsingPercent);
// 			g_pGlobal->WriteSystemLog(szSystemLog);
// 			DBGOUT(szSystemLog);
// 		}
		// 2009-04-09 by cmkwon, ���� ������ üũ ��ƾ ���� - �Ʒ��� ���� ���ݷ��� ���� 100%�� �ƴҶ��� üũ
		if(pLastItem && 100 != pLastItem->dwUsingPercent)
		{
			g_pGlobal->WriteSystemLogEX(TRUE, "[ERROR] CMonsterDBAccess::GetAllMonsters_2 Monster Item percent error !!, MonsterName[%20s: %6d] TotalUsingPercent[%d] \r\n"
				, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, pLastItem->dwUsingPercent);
		}

		// 5. ��Ʈ�� ��ų ������ �Ҵ�
		nTmItemNum = (INT)retMonsterInfo.ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo;
		if(nTmItemNum)
		{
			retMonsterInfo.ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo = pMapItemInfo->findEZ(nTmItemNum);
			if(NULL == retMonsterInfo.ItemInfo[ARRAY_INDEX_MONSTER_SKILL_ITEM].pItemInfo)
			{
				char	szSystemLog[1024];
				sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_1 Monster Item error, MonsterName[%20s: %6d] ItemNum[%d]\r\n"
					, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, nTmItemNum);
				g_pGlobal->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
			}
		}

		// 6. ���� üũ
		if(MonsterMoveTypeCheck(&retMonsterInfo) == FALSE)
		{
			char	szSystemLog[1024];
			sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_3 MoveTypeCheck error, MonsterName[%20s: %6d] MonsterForm[0x%2X] MovePattern[0x%X]\r\n"
				, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, retMonsterInfo.MonsterForm, retMonsterInfo.MovePattern);
			g_pGlobal->WriteSystemLog(szSystemLog);
			DBGOUT(szSystemLog);
		}

		// 7. MPOption üũ
		if(FALSE == CheckMPOption(&retMonsterInfo))
		{
			char	szSystemLog[1024];
			sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_4 MPOption error, Monster[%20s: %6d] MPOption[0x%X] MPParam1[%d] MPParam2[%d]\r\n"
				, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, retMonsterInfo.MPOption, retMonsterInfo.MPOptionParam1, retMonsterInfo.MPOptionParam2);
			g_pGlobal->WriteSystemLog(szSystemLog);
			DBGOUT(szSystemLog);
		}

// check_cmkwon, �ٸ� ���� �߰��ؾ� ��, 20040327
//		retMonsterInfo.HP = retMonsterInfo.CurrentHP;						// HP�� �Ҵ��Ѵ�.
		retMonsterInfo.Size			= retMonsterInfo.Size*retMonsterInfo.ScaleValue;	// �������� ����ϴ� ����� ����Ͽ� �����Ѵ�.
		retMonsterInfo.QuickSpeed	= retMonsterInfo.QuickSpeed/(1000/MONSTER_UPDATE_MOVE_TERM_TICK);			// DB���� 1�ʵ����� ���ǵ尡 ������ ���� ����� 200ms������ �ӵ��� ����ϹǷ� �ٽ� ����
		retMonsterInfo.TurnAngle	= retMonsterInfo.TurnAngle/(1000/MONSTER_UPDATE_MOVE_TERM_TICK);

		// start 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
		vectorMonsterMultiTarget::iterator itMT = vectMonsterMultiTargetinfo.begin();
		for(; itMT != vectMonsterMultiTargetinfo.end(); itMT++)
		{
			if( itMT->MonsterIndex == retMonsterInfo.MonsterUnitKind )
			{
				if( itMT->PointIndex < 1 || itMT->PointIndex > ARRAY_SIZE_MONSTER_TARGET )
				{
					char szSystemLog[1024];
					sprintf(szSystemLog, "[Error] CMonsterDBAccess::GetAllMonsters_5 MonsterMultiTarget Value Error !!!!!!, MonsterName[%20s: %6d] PointIndex[%2d] Position[%6.2f][%6.2f][%6.2f]\r\n"
						, retMonsterInfo.MonsterName, retMonsterInfo.MonsterUnitKind, itMT->PointIndex, itMT->TargetPosition.x, itMT->TargetPosition.y, itMT->TargetPosition.z);
					g_pGlobal->WriteSystemLog(szSystemLog);

					DBGOUT(szSystemLog);

					continue;		// �׳� �����Ű�°� ���� ������?
				}

				retMonsterInfo.MultiTargetInfo[itMT->PointIndex - 1].Position = itMT->TargetPosition;
			}
		}
		// end 2011-03-21 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�

		// 2013-08-28 by bckim, �������� ����ȭ
#/*ifndef _ATUM_NPC_SERVER
		vectorBossMonsterReward::iterator itBM = vectBossMonsterRewardInfo.begin();
		for(; itBM != vectBossMonsterRewardInfo.end(); itBM++)
		{
			if( itBM->MonsterIndex == retMonsterInfo.MonsterUnitKind )
			{
				retMonsterInfo.MonsterRewardInfo = itBM->BossMonsterReward;				
			}
		}
#endif*/
		// End. 2013-08-28 by bckim, �������� ����ȭ

		mapMonster.insert(map <int, MONSTER_INFO>::value_type(retMonsterInfo.MonsterUnitKind, retMonsterInfo));

		// initialize to 0x00
		memset(&retMonsterInfo, 0x00, sizeof(MONSTER_INFO));
	}

	SQLFreeStmt(hstmt, SQL_CLOSE);
	return TRUE;
}
