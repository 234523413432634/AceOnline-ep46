// AccountBlockManager.cpp: implementation of the CAccountBlockManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AccountBlockManager.h"
#include "PreIOCP.h"
#include "AtumPreDBManager.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAccountBlockManager::CAccountBlockManager(CAtumPreDBManager *i_pDBManager)
{
	m_pPreDBManager			= i_pDBManager;
}

CAccountBlockManager::~CAccountBlockManager()
{

}


void CAccountBlockManager::ResetAccountBlockManager(void)
{
	m_mtmapBlockedAccountList.clearLock();
}

mtmapBLOCKED_ACCOUNT_INFO * CAccountBlockManager::GetmapBLOCKED_ACCOUNT_INFOPtr(void)
{
	return &m_mtmapBlockedAccountList;
}

BOOL CAccountBlockManager::AddBlockedAccountList(SBLOCKED_ACCOUNT_INFO *i_pBlockedInfo)
{
	if(0 == strncmp("", i_pBlockedInfo->szBlockedAccountName, SIZE_MAX_ACCOUNT_NAME))
	{
		return FALSE;
	}
	mt_auto_lock mtA(&m_mtmapBlockedAccountList);
	SBLOCKED_ACCOUNT_INFO *pBlocked = m_mtmapBlockedAccountList.findLock_Ptr(i_pBlockedInfo->szBlockedAccountName);
	if(pBlocked)
	{
		*pBlocked = *i_pBlockedInfo;
		return TRUE;
	}
	return m_mtmapBlockedAccountList.insertNoLock(i_pBlockedInfo->szBlockedAccountName, *i_pBlockedInfo);	
}

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - CAccountBlockManager::DeleteBlockedAccountList() ����
BOOL CAccountBlockManager::DeleteBlockedAccountList(const char *i_szAccountName)
{
	return m_mtmapBlockedAccountList.deleteLock(i_szAccountName);
}

BOOL CAccountBlockManager::IsCheckBlockedAccountInfoByAccountName(SBLOCKED_ACCOUNT_INFO *o_pBlockedInfo
																  , char *i_szAccName
																  , CPreIOCPSocket *i_pNotifySock/*=NULL*/)
{

	
	// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
	g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] IsCheckBlockedAccountInfoByAccountName[%s] \r\n", i_szAccName);
	// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

	mt_auto_lock mtA(&m_mtmapBlockedAccountList);	
	SBLOCKED_ACCOUNT_INFO *pBlocked = m_mtmapBlockedAccountList.findLock_Ptr(i_szAccName);
	if(NULL == pBlocked)
	{
		// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] IsCheckBlockedAccountInfoByAccountName[%s] NOT BLOCKED_USER!! \r\n", i_szAccName);
		// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

		return FALSE;
	}

	ATUM_DATE_TIME atimeCur(true);
	if(atimeCur >= pBlocked->atimeEndTime)
	{// ���� �ð��� ����

		// 2008-04-04 by cmkwon, ���� Block/Unblock ���� ����
		SBLOCKED_ACCOUNT_INFO *pDBQuery	= new SBLOCKED_ACCOUNT_INFO;
		*pDBQuery						= *pBlocked;

		this->DeleteBlockedAccountList(i_szAccName);
		mtA.auto_unlock_cancel();

// 2008-04-04 by cmkwon, ���� Block/Unblock ���� ����
// 		char *szAccountName = new char[SIZE_MAX_ACCOUNT_NAME];
// 		STRNCPY_MEMSET(szAccountName, i_szAccName, SIZE_MAX_ACCOUNT_NAME);
// 		m_pPreDBManager->MakeAndEnqueueQuery(QT_UnblockUser, (CIOCPSocket*)i_pNotifySock, szAccountName);
		m_pPreDBManager->MakeAndEnqueueQuery(QT_UnblockUser, (CIOCPSocket*)i_pNotifySock, pDBQuery);		// 2008-04-04 by cmkwon, ���� Block/Unblock ���� ����

		// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] IsCheckBlockedAccountInfoByAccountName[%s] Unblock!! \r\n", i_szAccName);
		// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

		return FALSE;
	}

	*o_pBlockedInfo = *pBlocked;

	// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
	g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] IsCheckBlockedAccountInfoByAccountName[%s] BLOCKED_USER!! \r\n", i_szAccName);
	// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

	return TRUE;
}