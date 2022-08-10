#include "stdafx.h"
#include "AtumDBManager.h"
#include "IOCP.h"
#include "Global.h"
#include <assert.h>
#include "Monster.h"
#include "odbcstatement.h"
#define UNICODE
#include "odbcss.h"
#undef UNICODE
#include "AtumError.h"
#include "AtumProtocol.h"

#define	NUM_OF_SYNC_ODBC_STATEMENT 10	// Sync Exec.�� statement ����

struct ATUM_DB_THREAD_BEGIN_DATA
{
	CAtumDBManager	*pAtumDBManager;
	int				nAtumDBThreadIndex;
};

DWORD WINAPI DBWorkerThread(LPVOID lpParam)
{
	if(lpParam == NULL)
	{
		return 0x100;
	}

	ATUM_DB_THREAD_BEGIN_DATA *pTmpAtumDBThreadData
		= (ATUM_DB_THREAD_BEGIN_DATA*)lpParam;

	DWORD nRet = pTmpAtumDBThreadData->pAtumDBManager->AtumDBWorker(pTmpAtumDBThreadData->nAtumDBThreadIndex);

	SAFE_DELETE(pTmpAtumDBThreadData);

	return nRet;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			DWORD WINAPI DBDynamicWorkerThread(LPVOID lpParam)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
DWORD WINAPI DBDynamicWorkerThread(LPVOID lpParam)
{
	ATUM_DB_THREAD_BEGIN_DATA *pTmpAtumDBThreadData = (ATUM_DB_THREAD_BEGIN_DATA*)lpParam;

	DWORD nRet = pTmpAtumDBThreadData->pAtumDBManager->AtumDBDynamicWorker();	

	SAFE_DELETE(pTmpAtumDBThreadData);
	
	return nRet;
}

// constructor
CAtumDBManager::CAtumDBManager(DWORD i_dwWorkerCounts)
{
	m_dwCountDBWorker	= min(i_dwWorkerCounts, COUNT_MAX_DBWORKER_THREADS);	// 2008-04-11 by cmkwon, ����
	m_bShutDownFlag		= FALSE;
	m_ArrOdbcStmt		= NULL;	
	m_dwTlsIndex		= TLS_OUT_OF_INDEXES;
	m_bExtAuthDBConnect	= FALSE;				// 2006-05-17 by cmkwon

	MEMSET_ZERO(m_hDBWorkerThread, sizeof(m_hDBWorkerThread[0])*COUNT_MAX_DBWORKER_THREADS);

	for(int i=0; i < m_dwCountDBWorker; i++)
	{
		m_arrmtvectorInputDBQuery[i].reserve(100);
		m_arrmtvectorProcessDBQuery[i].reserve(100);
	}

	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
	m_mtvectInputQueryWithNewThread.reserve(100);
}

// destructor
CAtumDBManager::~CAtumDBManager()
{
	// Close event handle
}

void CAtumDBManager::Clean()
{
	DWORD dwRet;

	// Set ShutDownFlag
	m_bShutDownFlag = TRUE;

	// Wait for threads to quit
	dwRet = WaitForMultipleObjects(m_dwCountDBWorker, m_hDBWorkerThread, TRUE, INFINITE);

	if(WAIT_OBJECT_0 <= dwRet && dwRet <= WAIT_OBJECT_0 + m_dwCountDBWorker -1)
	{
		// ��� Thread�� signaled ���°� ��, ��� ���� ����
	}
	else if(WAIT_ABANDONED_0 <= dwRet && dwRet <= WAIT_ABANDONED_0 + m_dwCountDBWorker -1 )
	{
		// ��� Thread�� signaled ���°� ��, ��� �ϳ� �̻��� object�� ������
	}
	else if(WAIT_TIMEOUT == dwRet)
	{
		// ��� Thread�� signaled ���°� ���� ����, ������ Time�� ���
	}
	else
	{
		// ������ WAIT_FAILED��
		int nError = GetLastError();
	}
	auto i{ 0 };
	for(i= 0; i < COUNT_MAX_DBWORKER_THREADS; i++)
	{
		if(m_hDBWorkerThread[i])
		{
			CloseHandle(m_hDBWorkerThread[i]);
		}
		m_hDBWorkerThread[i] = 0;
	}

	if(m_dwTlsIndex != TLS_OUT_OF_INDEXES)
	{
		TlsFree(m_dwTlsIndex);
		m_dwTlsIndex = TLS_OUT_OF_INDEXES;
	}

	// For Synchronous Execution
	if (m_ArrOdbcStmt != NULL)
	{
		for (i = 0; i < NUM_OF_SYNC_ODBC_STATEMENT; i++)
		{
			m_ArrOdbcStmt[i].Clean();
		}
	}

	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - CAtumDBManager::Clean# ���� ���� üũ
	while(TRUE)
	{
		if(CheckAndCloseHandleDynamicDBThread())
		{
			break;
		}

		Sleep(1000);
	}
	SAFE_DELETE_ARRAY(m_ArrOdbcStmt);
}

BOOL CAtumDBManager::Init()
{
	// Allocate a TLS index
	if ((m_dwTlsIndex = TlsAlloc()) == TLS_OUT_OF_INDEXES)
	{
		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Init TlsAlloc(), LastError[%d] TlsIndex[%d]\r\n", nErr, m_dwTlsIndex);
		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	m_DBThreadCheck.SetCheckThreadCounts(m_dwCountDBWorker);
	// begin thread
	auto i{ 0 };
	for (i = 0; i < m_dwCountDBWorker; i++)
	{
		ATUM_DB_THREAD_BEGIN_DATA *pTmpAtumDBThreadBeginData
			= new ATUM_DB_THREAD_BEGIN_DATA;
		pTmpAtumDBThreadBeginData->pAtumDBManager = this;
		pTmpAtumDBThreadBeginData->nAtumDBThreadIndex = i;

		m_hDBWorkerThread[i] = chBEGINTHREADEX(NULL, 0, DBWorkerThread, (LPVOID)pTmpAtumDBThreadBeginData, 0, 0);
		if (m_hDBWorkerThread[i] == NULL )
		{
			int nErr = GetLastError();
			SetLastError(0);
			char	szError[1024];
			sprintf(szError, "[Error] CAtumDBManager::IOCPInit Worker thread create(), LastError[%d] WorkerCount[%d]\r\n"
				, nErr, m_dwCountDBWorker);
			g_pGlobal->WriteSystemLog(szError);
			DBGOUT(szError);
			return FALSE;
		}
		Sleep(100);
	}

	if(FALSE == this->IsReadyAtumDBManager())
	{
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Init IsReadyAtumDBManager() Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	// For Synchronous Execution
	m_ArrOdbcStmt = new CODBCStatement[NUM_OF_SYNC_ODBC_STATEMENT];
	for (i = 0; i < NUM_OF_SYNC_ODBC_STATEMENT; i++)
	{
		// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - �Ʒ��� ���� ���� ��
		//m_ArrOdbcStmt[i].Init((CHAR*)g_pGlobalGameServer->GetODBCDSN(), (CHAR*)g_pGlobalGameServer->GetODBCUID(), (CHAR*)g_pGlobalGameServer->GetODBCPASSWORD());
		BOOL bRet = m_ArrOdbcStmt[i].Init(g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (CHAR*)g_pGlobalGameServer->GetODBCUID(), (CHAR*)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetMainWndHandle());
		if(FALSE == bRet)
		{
			// 2008-09-05 by cmkwon, DBServer ���� ���� �ý��� �α� ����� - 
			g_pGlobal->WriteSystemLogEX(TRUE, "[DB Error] fail to connect DBServer(CAtumDBManager::Init_) !! %s,%d %s %s %s, Idx(%d)\r\n"
				, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (CHAR*)g_pGlobalGameServer->GetODBCUID(), (CHAR*)g_pGlobalGameServer->GetODBCPASSWORD()
				, i);
		}
	}

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::IsReadyAtumDBManager(void)
/// \brief		
/// \author		cmkwon
/// \date		2005-10-27 ~ 2005-10-27
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::IsReadyAtumDBManager(void)
{
	DWORD dwStartTick = timeGetTime();
	while(TRUE)
	{
		DWORD dwCurTick = timeGetTime();

		if(m_DBThreadCheck.GetSettingCompletionFlag())
		{
			return TRUE;
		}
		else if(dwCurTick-dwStartTick > 30000)
		{
			break;
		}
		Sleep(100);
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::Connect2DBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt, EN_DB_CONNECTION_TYPE i_connTy/*=EN_DB_CONNECTION_TYPE_AUTO_COMMIT*/)
/// \brief		
/// \author		cmkwon
/// \date		2006-05-17 ~ 2006-05-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::Connect2DBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt, EN_DBCONN_TYPE i_connTy/*=EN_DBCONN_AUTO_COMMIT*/)
{
	if(EN_DBCONN_EXT_AUTH == i_connTy
		&& FALSE == this->m_bExtAuthDBConnect)
	{// 2006-05-17 by cmkwon, 
		return FALSE;
	}
	RETCODE		ret;
	
	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, i_phenv);
	ret = SQLSetEnvAttr(*i_phenv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret = SQLAllocHandle(SQL_HANDLE_DBC, *i_phenv, i_phdbc);
// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - �Ʒ��� ���� ���� ��
// 	if(EN_DBCONN_EXT_AUTH == i_connTy)
// 	{
// 		ret = SQLConnect(*i_phdbc, g_pGlobalGameServer->GetExtAuthODBCDSN(), SQL_NTS, g_pGlobalGameServer->GetExtAuthODBCUID(), SQL_NTS, g_pGlobalGameServer->GetExtAuthODBCPASSWORD(), SQL_NTS);
// 	}
// 	else
// 	{
// 		ret = SQLConnect(*i_phdbc, g_pGlobalGameServer->GetODBCDSN(), SQL_NTS, g_pGlobalGameServer->GetODBCUID(), SQL_NTS, g_pGlobalGameServer->GetODBCPASSWORD(), SQL_NTS);
// 	}

	char szConnectionString[512];
	char szOutConnectionString[512]; SQLSMALLINT pcb;
#if defined(DB_SERVER_MYSQL)
	if(EN_DBCONN_EXT_AUTH == i_connTy)
	{
		sprintf(szConnectionString, "DRIVER={MySQL ODBC 5.1 Driver};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
			, g_pGlobalGameServer->GetExtAuthDBServerIP(), g_pGlobalGameServer->GetExtAuthDBServerIP(), g_pGlobalGameServer->GetExtAuthDBServerPort(), (char*)g_pGlobalGameServer->GetExtAuthODBCUID(), (char*)g_pGlobalGameServer->GetExtAuthODBCPASSWORD(), g_pGlobalGameServer->GetExtAuthDBServerDatabaseName());
	}
	else
	{
		sprintf(szConnectionString, "DRIVER={MySQL ODBC 5.1 Driver};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
			, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), (char*)g_pGlobalGameServer->GetODBCUID(), (char*)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetDBServerDatabaseName());
	}
	
#else
	if(EN_DBCONN_EXT_AUTH == i_connTy)
	{
		sprintf(szConnectionString, "DRIVER={SQL Server};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
			, g_pGlobalGameServer->GetExtAuthDBServerIP(), g_pGlobalGameServer->GetExtAuthDBServerIP(), g_pGlobalGameServer->GetExtAuthDBServerPort(), (char*)g_pGlobalGameServer->GetExtAuthODBCUID(), (char*)g_pGlobalGameServer->GetExtAuthODBCPASSWORD(), g_pGlobalGameServer->GetExtAuthDBServerDatabaseName());
	}
	// 2013-06-20 by jhseol,bckim GLog ����
	else if ( EN_DBCONN_GLOG_COMMIT == i_connTy )
	{
		sprintf(szConnectionString, "DRIVER={SQL Server};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=GLog"
			, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), (char*)g_pGlobalGameServer->GetODBCUID(), (char*)g_pGlobalGameServer->GetODBCPASSWORD());
	}
	// end 2013-06-20 by jhseol,bckim GLog ����
	else
	{
		sprintf(szConnectionString, "DRIVER={SQL Server};SERVER=%s;ADDRESS=%s,%d;NETWORK=DBMSSOCN;UID=%s;PWD=%s;DATABASE=%s"
			, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), (char*)g_pGlobalGameServer->GetODBCUID(), (char*)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetDBServerDatabaseName());
	}
#endif
	ret = SQLDriverConnect(*i_phdbc, g_pGlobalGameServer->GetMainWndHandle(), (SQLCHAR*)szConnectionString, strlen(szConnectionString), (SQLCHAR*)szOutConnectionString, 512, &pcb, SQL_DRIVER_NOPROMPT);


	if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO)
	{
		if(EN_DBCONN_EXT_AUTH == i_connTy)
		{
			// 2008-09-05 by cmkwon, DBServer ���� ���� �ý��� �α� ����� - 
			g_pGlobal->WriteSystemLogEX(TRUE, "[DB Error] fail to connect DBServer(CAtumDBManager::Connect2DBServer_) !! %s,%d %s %s %s\r\n"
				, g_pGlobalGameServer->GetExtAuthDBServerIP(), g_pGlobalGameServer->GetExtAuthDBServerPort(), g_pGlobalGameServer->GetExtAuthDBServerDatabaseName(), (char*)g_pGlobalGameServer->GetExtAuthODBCUID(), (char*)g_pGlobalGameServer->GetExtAuthODBCPASSWORD());
		}
		else
		{
			// 2008-09-05 by cmkwon, DBServer ���� ���� �ý��� �α� ����� - 
			g_pGlobal->WriteSystemLogEX(TRUE, "[DB Error] fail to connect DBServer(CAtumDBManager::Connect2DBServer_) !! %s,%d %s %s %s\r\n"
				, g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (CHAR*)g_pGlobalGameServer->GetODBCUID(), (CHAR*)g_pGlobalGameServer->GetODBCPASSWORD());
		}

		if(SQL_NULL_HDBC != *i_phdbc){		SQLDisconnect(*i_phdbc);}
	#ifndef _DEBUG
		if(SQL_NULL_HDBC != *i_phdbc){		SQLFreeHandle(SQL_HANDLE_DBC, *i_phdbc);}
	#endif
		if(SQL_NULL_HENV != *i_phenv){		SQLFreeHandle(SQL_HANDLE_ENV, *i_phenv);}

		*i_phdbc		= SQL_NULL_HDBC;
		*i_phenv		= SQL_NULL_HENV;
		return FALSE;
	}

	if(EN_DBCONN_MANUAL_COMMIT == i_connTy)
	{
		SQLSetConnectAttr(*i_phdbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)SQL_AUTOCOMMIT_OFF, SQL_NTS);	// set mannualcommit
	}

	// prints DB Info
	char DatabaseName[40];
	char DSN[40];
	SQLSMALLINT StrLen;
	SQLGetInfo(*i_phdbc, SQL_DATABASE_NAME, (SQLPOINTER)DatabaseName, sizeof(DatabaseName), &StrLen);
	SQLGetInfo(*i_phdbc, SQL_DATA_SOURCE_NAME, (SQLPOINTER)DSN, sizeof(DSN), &StrLen);

	ret = SQLAllocHandle(SQL_HANDLE_STMT, *i_phdbc, i_phstmt);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::Connect2DBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy)
/// \brief		
/// \author		cmkwon
/// \date		2006-05-17 ~ 2006-05-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::Connect2DBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy)
{
	switch(i_dbConnTy)
	{
	case EN_DBCONN_AUTO_COMMIT:
		return Connect2DBServer(&io_pDBTlsData->henv, &io_pDBTlsData->hdbc, &io_pDBTlsData->hstmt, i_dbConnTy);
	case EN_DBCONN_MANUAL_COMMIT:
		return Connect2DBServer(&io_pDBTlsData->henv_mc, &io_pDBTlsData->hdbc_mc, &io_pDBTlsData->hstmt_mc, i_dbConnTy);
	case EN_DBCONN_EXT_AUTH:
		return Connect2DBServer(&io_pDBTlsData->henv_ExtAuth, &io_pDBTlsData->hdbc_ExtAuth, &io_pDBTlsData->hstmt_ExtAuth, i_dbConnTy);
	case EN_DBCONN_GLOG_COMMIT:		// 2013-06-20 by jhseol,bckim GLog ����
		return Connect2DBServer(&io_pDBTlsData->henv_GLog, &io_pDBTlsData->hdbc_GLog, &io_pDBTlsData->hstmt_GLog, i_dbConnTy);
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CAtumDBManager::DisconnectDBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt)
/// \brief		
/// \author		cmkwon
/// \date		2006-05-17 ~ 2006-05-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CAtumDBManager::DisconnectDBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt)
{
	// cleanup odbc resources
	if(SQL_NULL_HSTMT != *i_phstmt){	SQLFreeHandle(SQL_HANDLE_STMT, *i_phstmt);}
	if(SQL_NULL_HDBC != *i_phdbc){		SQLDisconnect(*i_phdbc);}
#ifndef _DEBUG
	if(SQL_NULL_HDBC != *i_phdbc){		SQLFreeHandle(SQL_HANDLE_DBC, *i_phdbc);}
#endif
	if(SQL_NULL_HENV != *i_phenv){		SQLFreeHandle(SQL_HANDLE_ENV, *i_phenv);}

	*i_phstmt		= SQL_NULL_HSTMT;
	*i_phdbc		= SQL_NULL_HDBC;
	*i_phenv		= SQL_NULL_HENV;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CAtumDBManager::DisconnectDBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy)
/// \brief		
/// \author		cmkwon
/// \date		2006-05-17 ~ 2006-05-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CAtumDBManager::DisconnectDBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy)
{
	switch(i_dbConnTy)
	{
	case EN_DBCONN_AUTO_COMMIT:
		DisconnectDBServer(&io_pDBTlsData->henv, &io_pDBTlsData->hdbc, &io_pDBTlsData->hstmt);
		break;
	case EN_DBCONN_MANUAL_COMMIT:
		DisconnectDBServer(&io_pDBTlsData->henv_mc, &io_pDBTlsData->hdbc_mc, &io_pDBTlsData->hstmt_mc);
		break;
	case EN_DBCONN_EXT_AUTH:
		DisconnectDBServer(&io_pDBTlsData->henv_ExtAuth, &io_pDBTlsData->hdbc_ExtAuth, &io_pDBTlsData->hstmt_ExtAuth);
		break;
	case EN_DBCONN_GLOG_COMMIT:			// 2013-06-20 by jhseol,bckim GLog ����
		DisconnectDBServer(&io_pDBTlsData->henv_GLog, &io_pDBTlsData->hdbc_GLog, &io_pDBTlsData->hstmt_GLog);
		break;
	}
}


BOOL CAtumDBManager::TLSDataInit(LPVOID &lpvData)
{
	// Initialize the TLS index for this thread.
	lpvData = (LPVOID) LocalAlloc(LPTR, sizeof(DBWorkerTLSDATA*));
	if (!TlsSetValue(m_dwTlsIndex, lpvData) )
	{
		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::TLSDataInit TlsSetValue(), LastError[%d] TlsIndex[%d]\r\n"
			, nErr, m_dwTlsIndex);
		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	*(DBWorkerTLSDATA**)lpvData = new DBWorkerTLSDATA;

	return TRUE;
}

BOOL CAtumDBManager::TLSDataClean(LPVOID &lpvData)
{
	SAFE_DELETE( *(DBWorkerTLSDATA**)lpvData );

	// Release the dynamic memory before the thread returns.
	lpvData = TlsGetValue(m_dwTlsIndex);
	if (lpvData != 0)
	{
		LocalFree((HLOCAL) lpvData);
	}

	return TRUE;
}

DBWorkerTLSDATA* CAtumDBManager::GetDBWorkerTLSDATA()
{
	LPVOID lpvData;

	// Retrieve a data pointer for the current thread.
	lpvData = TlsGetValue(m_dwTlsIndex);
	if (NULL == lpvData)
	{
		// error
		return NULL;
	}

	return *(DBWorkerTLSDATA**)lpvData;
}

DWORD CAtumDBManager::AtumDBWorker(int i_nAtumDBThreadIndex)
{
	char	szTemp1[1024];
	sprintf(szTemp1, "CAtumDBManager::AtumDBWorker_ DWWorkerThread, \t ThreadID(%6d, 0x%X)\r\n", GetCurrentThreadId(), GetCurrentThreadId());
	g_pGlobal->WriteSystemLog(szTemp1);
	DBGOUT(szTemp1);

	// TLS
	LPVOID lpvData;
	if (!TLSDataInit(lpvData))
	{	// init error

		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Worker TLSDataInit Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		MessageBox(NULL, szError, "ERROR", MB_OK);
		return -1;
	}
	DBWorkerTLSDATA *tlsData = GetDBWorkerTLSDATA();

#if defined(SERVICE_TYPE_TAIWANESE_SERVER_1)
	// 2008-10-08 by cmkwon, �븸 Netpower_Tpe �ܺ����� ���� - 
	CoInitialize(NULL);			// COM �ʱ�ȭ
#endif

	////////////////////////////////////
	// Init DB
	////////////////////////////////////

	if(FALSE == Connect2DBServer(tlsData, EN_DBCONN_AUTO_COMMIT))
	{
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Worker Connect2DBServer_1 Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return -1;
	}
	if(FALSE == Connect2DBServer(tlsData, EN_DBCONN_MANUAL_COMMIT))
	{
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Worker Connect2DBServer_2 Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return -1;
	}

	if(m_bExtAuthDBConnect
		&& FALSE == Connect2DBServer(tlsData, EN_DBCONN_EXT_AUTH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Worker Connect2DBServer_3 Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return -1;
	}
	// 2013-06-20 by jhseol,bckim GLog ����
#ifdef S_GLOG_3ND_KHK
	if ( FALSE == Connect2DBServer(tlsData, EN_DBCONN_GLOG_COMMIT) )
	{
		char	szError[1024];
		sprintf(szError, "[Error] CAtumDBManager::Worker Connect2DBServer_GLOG Error\r\n");
		g_pGlobal->WriteSystemLog(szError);
		DbgOut(szError);
		return -1;
	}
#endif
	// end 2013-06-20 by jhseol,bckim GLog ����

	SThreadInfo *pstInfo = NULL;
	SThreadInfo	stInfo;
	memset(&stInfo, 0x00, sizeof(SThreadInfo));
	stInfo.dwThreadId			= GetCurrentThreadId();
	stInfo.enThreadCheckType	= THREAD_CHECK_TYPE_DB_WORKER;
	m_DBThreadCheck.AddThreadInfo(stInfo);
	while(TRUE)
	{
		pstInfo = m_DBThreadCheck.GetThreadInfo(stInfo.dwThreadId);
		if(pstInfo){		break;}
		Sleep(100);
	}

	srand(timeGetTime());			// 2007-04-03 by dhjin

	int i, nSize;
	////////////////////////////////////
	// start work
	////////////////////////////////////
	while (TRUE)
	{
		m_arrmtvectorInputDBQuery[i_nAtumDBThreadIndex].lock();
		if(m_arrmtvectorInputDBQuery[i_nAtumDBThreadIndex].empty())
		{
			m_arrmtvectorInputDBQuery[i_nAtumDBThreadIndex].unlock();
			if(m_bShutDownFlag)
			{
				break;
			}
			Sleep(100);
			continue;
		}		
		m_arrmtvectorInputDBQuery[i_nAtumDBThreadIndex].swap(m_arrmtvectorProcessDBQuery[i_nAtumDBThreadIndex]);
		m_arrmtvectorInputDBQuery[i_nAtumDBThreadIndex].unlock();

		pstInfo->dwLastUseStartTick	= timeGetTime();
		pstInfo->bThreadUseFlag		= TRUE;

		nSize = m_arrmtvectorProcessDBQuery[i_nAtumDBThreadIndex].size();
		pstInfo->nQueryArraySize = nSize;
		for(i = 0; i < nSize; i++)
		{
			DWORD	dwCurTick = timeGetTime();
			DB_QUERY &dbquery		= m_arrmtvectorProcessDBQuery[i_nAtumDBThreadIndex][i];
			pstInfo->dwSocketIndex	= i_nAtumDBThreadIndex;
			pstInfo->dwMessageType	= dbquery.enumQuryType;
			pstInfo->dwCharacterUID	= dbquery.nCharacterUID;			
			BOOL bRet = ProcessServerQuery(dbquery, tlsData->hstmt, tlsData->hstmt_mc, tlsData->hstmt_ExtAuth, tlsData->hstmt_GLog);	// 2013-06-20 by jhseol,bckim GLog ����	// Process each query
			dbquery.dwProcessedTick = timeGetTime() - dwCurTick;
		}
		DWORD dwEndTick = timeGetTime();

		if(nSize > 100)
		{
			char szTemp[512];
			sprintf(szTemp, "DB Index : %2d, Size(%4d) StartTick(%8d) TotalProcessedTime(%8d)\r\n"
				, i_nAtumDBThreadIndex, nSize, pstInfo->dwLastUseStartTick, dwEndTick - pstInfo->dwLastUseStartTick);
			g_pGlobalGameServer->WriteSystemLog(szTemp);
		}		

		if(pstInfo->bPrintOut)
		{
			char szTemp[1024];
			sprintf(szTemp, "DB Index : %2d, TotalProcessedTime(%8d)==================\r\n", i_nAtumDBThreadIndex, dwEndTick - pstInfo->dwLastUseStartTick);
			g_pGlobalGameServer->WriteSystemLog(szTemp);
			for(i = 0; i < nSize; i++)
			{
				DB_QUERY &dbquery		= m_arrmtvectorProcessDBQuery[i_nAtumDBThreadIndex][i];
				sprintf(szTemp, "	ArrayIndex(%4d) : %30s ProcessedTime(%4d) CharacterUID(%6d)\r\n"
					, i, GetDBQueryTypeString(dbquery.enumQuryType), dbquery.dwProcessedTick, dbquery.nCharacterUID);
				g_pGlobalGameServer->WriteSystemLog(szTemp);
			}
			sprintf(szTemp, "=======================================================\r\n");
			g_pGlobalGameServer->WriteSystemLog(szTemp);
			pstInfo->bPrintOut = FALSE;
		}

		m_arrmtvectorProcessDBQuery[i_nAtumDBThreadIndex].clear();
		pstInfo->bThreadUseFlag		= FALSE;
	} // end while

// 2006-05-17 by cmkwon, �Ʒ� �Լ��� ó��
// 	// cleanup odbc resources
// 	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
// 	SQLDisconnect(hdbc);
// #ifndef _DEBUG
// 	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
// #endif
// 	SQLFreeHandle(SQL_HANDLE_ENV, henv);
// 
// 	// for manual commit
// 	SQLFreeHandle(SQL_HANDLE_STMT, hstmt_mc);
// 	SQLDisconnect(hdbc_mc);
// #ifndef _DEBUG
// 	SQLFreeHandle(SQL_HANDLE_DBC, hdbc_mc);
// #endif
// 	SQLFreeHandle(SQL_HANDLE_ENV, henv_mc);

	DisconnectDBServer(tlsData, EN_DBCONN_AUTO_COMMIT);
	DisconnectDBServer(tlsData, EN_DBCONN_MANUAL_COMMIT);
	if(m_bExtAuthDBConnect)
	{
		DisconnectDBServer(tlsData, EN_DBCONN_EXT_AUTH);
	}
	DisconnectDBServer(tlsData, EN_DBCONN_GLOG_COMMIT);	// 2013-06-20 by jhseol,bckim GLog ����
	if (!TLSDataClean(lpvData))
	{
		// init error
		return -1;
	}

	return 5;
}

void CAtumDBManager::MakeAndEnqueueQuery(EnumQueryType type, CIOCPSocket* pIOCPSocket 
										 , void *pMsg, void* i_pGeneralParam/*=NULL*/
										 , INT64 i_nGeneralParam1/*=0*/, INT64 i_nGeneralParam2/*=0*/)
{
	// make query, enqueue
	DB_QUERY dbquery;

	dbquery.pIOCPSocket		= pIOCPSocket;
	dbquery.nCharacterUID	= 0;
	dbquery.enumQuryType	= type;
	dbquery.pQueryParam		= (void*)pMsg;
	dbquery.pGeneralParam	= i_pGeneralParam;
	dbquery.nGeneralParam1	= i_nGeneralParam1;
	dbquery.nGeneralParam2	= i_nGeneralParam2;

	int nDBThreadIndex = 0;
	if (pIOCPSocket)
	{
		nDBThreadIndex = pIOCPSocket->GetClientArrayIndex()%m_dwCountDBWorker;
	}
	else
	{
		nDBThreadIndex = RANDI(0, m_dwCountDBWorker-1);
	}

	m_arrmtvectorInputDBQuery[nDBThreadIndex].lock();
	m_arrmtvectorInputDBQuery[nDBThreadIndex].push_back(dbquery);
	m_arrmtvectorInputDBQuery[nDBThreadIndex].unlock();
}

BOOL CAtumDBManager::ExecuteQuery(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam /* = NULL */, INT64 i_nGeneralParam1 /* = 0 */, INT64 i_nGeneralParam2 /* = 0 */)
{
	BOOL		bRet = FALSE;
	DB_QUERY	dbquery;

	dbquery.pIOCPSocket = pIOCPSocket;
	dbquery.enumQuryType = type;
	dbquery.pQueryParam = (void*)pMsg;
	dbquery.pGeneralParam = i_pGeneralParam;
	dbquery.nGeneralParam1 = i_nGeneralParam1;
	dbquery.nGeneralParam2 = i_nGeneralParam2;

	int idx = 0;
	if (pIOCPSocket != NULL)
	{
		idx = pIOCPSocket->GetClientArrayIndex()%NUM_OF_SYNC_ODBC_STATEMENT;
	}
	else
	{
		idx = RANDI(0, NUM_OF_SYNC_ODBC_STATEMENT-1);
	}
	CODBCStatement *pOdbcStmt = &m_ArrOdbcStmt[idx];

	pOdbcStmt->Lock();
	SQLHSTMT	hstmt_ms = SQL_NULL_HSTMT;
	SQLHSTMT	hstmt_extAuth = SQL_NULL_HSTMT;
	SQLHSTMT	hstmt_GLog = SQL_NULL_HSTMT;		// 2013-06-20 by jhseol,bckim GLog ����
	bRet = ProcessServerQuery(dbquery, pOdbcStmt->m_hstmt, hstmt_ms, hstmt_extAuth, hstmt_GLog);	// 2013-06-20 by jhseol,bckim GLog ����
	pOdbcStmt->Unlock();
	return bRet;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::CheckAndCloseHandleDynamicDBThread(void)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::CheckAndCloseHandleDynamicDBThread(void)
{
	mt_auto_lock mtA(&m_mtvectQueryThreadHandleList);

	if(m_mtvectQueryThreadHandleList.empty())
	{
		return TRUE;
	}

	mtvectHANDLE::iterator itr(m_mtvectQueryThreadHandleList.begin());
	while(itr != m_mtvectQueryThreadHandleList.end())
	{
		HANDLE hThread = *itr;
		DWORD dwRet = WaitForSingleObject(hThread, 10);
		if(WAIT_OBJECT_0 == dwRet)
		{
			CloseHandle(hThread);
			itr = m_mtvectQueryThreadHandleList.erase(itr);
			continue;
		}
		itr++;
	}

	return m_mtvectQueryThreadHandleList.empty();
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::InsertDBQueryToDynamicQueryList(DB_QUERY *i_pDBQuery)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::InsertDBQueryToDynamicQueryList(DB_QUERY *i_pDBQuery)
{
	mt_auto_lock mtA(&m_mtvectInputQueryWithNewThread);
	m_mtvectInputQueryWithNewThread.push_back(*i_pDBQuery);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::GetDBQueryFromDynamicQueryList(DB_QUERY *o_pDBQuery)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::GetDBQueryFromDynamicQueryList(DB_QUERY *o_pDBQuery)
{
	mt_auto_lock mtA(&m_mtvectInputQueryWithNewThread);
	if(m_mtvectInputQueryWithNewThread.empty())
	{
		return FALSE;
	}

	mtvectorDB_QUERY::iterator itr(m_mtvectInputQueryWithNewThread.begin());
//	*o_pDBQuery		= *itr;
	memcpy(o_pDBQuery, &*itr, sizeof(DB_QUERY));		// 2013-11-25 by jhseol&bckim, �ŷ��� - �ŷ��� �۾��ϴ� ���������� ���� �״� ���� ����

	m_mtvectInputQueryWithNewThread.erase(itr);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CAtumDBManager::MakeQueryWithNewThread(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam/*=NULL*/, INT64 i_nGeneralParam1/*=0*/, INT64 i_nGeneralParam2/*=0*/)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CAtumDBManager::MakeQueryWithNewThread(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam/*=NULL*/, INT64 i_nGeneralParam1/*=0*/, INT64 i_nGeneralParam2/*=0*/)
{
	// make query, enqueue
	DB_QUERY dbquery;
	
	dbquery.pIOCPSocket		= pIOCPSocket;
	dbquery.nCharacterUID	= 0;
	dbquery.enumQuryType	= type;
	dbquery.pQueryParam		= (void*)pMsg;
	dbquery.pGeneralParam	= i_pGeneralParam;
	dbquery.nGeneralParam1	= i_nGeneralParam1;
	dbquery.nGeneralParam2	= i_nGeneralParam2;

	this->InsertDBQueryToDynamicQueryList(&dbquery);

	mt_auto_lock mtQTH(&m_mtvectQueryThreadHandleList);
	this->CheckAndCloseHandleDynamicDBThread();
	
	ATUM_DB_THREAD_BEGIN_DATA *pTmpAtumDBThreadBeginData = new ATUM_DB_THREAD_BEGIN_DATA;
	pTmpAtumDBThreadBeginData->pAtumDBManager		= this;
	pTmpAtumDBThreadBeginData->nAtumDBThreadIndex	= 0;
	HANDLE hNewThread = chBEGINTHREADEX(NULL, 0, DBDynamicWorkerThread, (LPVOID)pTmpAtumDBThreadBeginData, 0, 0);
	if (NULL == hNewThread)
	{
		g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CAtumDBManager::MakeQueryWithNewThread# create thread error !!, GetLastError(%d)\r\n", GetLastError());
		SetLastError(0);
		return FALSE;
	}
	m_mtvectQueryThreadHandleList.pushBackLock(hNewThread);

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			DWORD CAtumDBManager::AtumDBDynamicWorker(void)
/// \brief		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
/// \author		cmkwon
/// \date		2008-12-01 ~ 2008-12-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
DWORD CAtumDBManager::AtumDBDynamicWorker(void)
{

	DB_QUERY dbQuery;
	if(FALSE == this->GetDBQueryFromDynamicQueryList(&dbQuery))
	{
		return 60;
	}

	CODBCStatement odbcStmt;
	BOOL bRet = odbcStmt.Init(g_pGlobalGameServer->GetDBServerIP(), g_pGlobalGameServer->GetDBServerPort(), g_pGlobalGameServer->GetDBServerDatabaseName(), (LPCSTR)g_pGlobalGameServer->GetODBCUID(), (LPCSTR)g_pGlobalGameServer->GetODBCPASSWORD(), g_pGlobalGameServer->GetMainWndHandle());
	if(FALSE == bRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] CAtumDBManager::AtumDBDynamicWorker# connect db fail !! GetLastError(%d)\r\n", GetLastError());
		SetLastError(0);

		// 2008-12-19 by cmkwon, ����� ������ �߻��� ���� ������ ���Ϳ� �ٽ� �߰��Ѵ�.
		this->InsertDBQueryToDynamicQueryList(&dbQuery);
		return 61;
	}

	while(TRUE)
	{
		bRet = this->ProcessDinamicServerQuery(&dbQuery, &odbcStmt);
		if(FALSE == bRet)
		{// 2008-12-01 by cmkwon, ����ó�� ������, �ش� ������ ���Ϳ� �ٽ� �߰��Ѵ�.

			g_pGlobal->WriteSystemLogEX(TRUE, "[ERROR] CAtumDBManager::AtumDBDynamicWorker# call ProcessDinamicServerQuery() error !!, CurThreadID(%d) %d(%s)\r\n"
				, ::GetCurrentThreadId(), dbQuery.enumQuryType, GetDBQueryTypeString(dbQuery.enumQuryType));
			// 2008-12-19 by cmkwon, ������ �߻��ϸ� ������ �ٽ� �߰� �� �ʿ�� ����.
			//this->InsertDBQueryToDynamicQueryList(&dbQuery);
			break;
		}

		if(FALSE == this->GetDBQueryFromDynamicQueryList(&dbQuery))
		{
			break;
		}
	}

	return 62;
}

void CAtumDBManager::ProcessLogMessages(SQLSMALLINT plm_handle_type,
										SQLHANDLE &plm_handle,
										const char *logstring, BOOL ConnInd, CIOCPSocket *pIOCPSocket)
{
	g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] DBWorkerThreadID(%5d) hstmt(0x%X): %s\r\n", GetCurrentThreadId(), plm_handle, (char*)logstring);

	if(plm_handle == SQL_NULL_HSTMT)
	{
		DBWorkerTLSDATA *pTlsData = GetDBWorkerTLSDATA();
		BOOL bRet = Connect2DBServer(pTlsData, EN_DBCONN_AUTO_COMMIT);
		if(bRet)
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_3 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt, EN_DBCONN_AUTO_COMMIT);
		}
		else
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_3 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_AUTO_COMMIT);
		}
		bRet = Connect2DBServer(pTlsData, EN_DBCONN_MANUAL_COMMIT);
		if(bRet)
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_3 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_mc, EN_DBCONN_MANUAL_COMMIT);
		}
		else
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_3 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_MANUAL_COMMIT);
		}
		if(m_bExtAuthDBConnect)
		{
			bRet = Connect2DBServer(pTlsData, EN_DBCONN_EXT_AUTH);
			if(bRet)
			{
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_3 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_ExtAuth, EN_DBCONN_EXT_AUTH);
			}
			else
			{
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_3 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_EXT_AUTH);
			}
		}
		// 2013-06-20 by jhseol,bckim GLog ����
#ifdef S_GLOG_3ND_KHK
		bRet = Connect2DBServer(pTlsData, EN_DBCONN_GLOG_COMMIT);
		if(bRet)
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_3 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_GLog, EN_DBCONN_GLOG_COMMIT);
		}
		else
		{
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_3 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_GLOG_COMMIT);
		}
#endif
		// end 2013-06-20 by jhseol,bckim GLog ����
		return;
	}

	RETCODE		plm_retcode						= SQL_SUCCESS;
	UCHAR		plm_szSqlState[1024]			= "";
	UCHAR		plm_szErrorMsg[1024]			= "";
	SDWORD		plm_pfNativeError				= 0L;
	SWORD		plm_pcbErrorMsg					= 0;
	SQLSMALLINT	plm_cRecNmbr					= 1;
	SDWORD		plm_SS_MsgState = 0, plm_SS_Severity = 0;
	SQLINTEGER	plm_Rownumber					= 0;
	USHORT		plm_SS_Line;
	SQLSMALLINT	plm_cbSS_Procname, plm_cbSS_Srvname;
	SQLCHAR		plm_SS_Procname[MAXNAME], plm_SS_Srvname[MAXNAME];
	while (plm_retcode != SQL_NO_DATA_FOUND)
	{
		plm_retcode = SQLGetDiagRec(plm_handle_type, plm_handle, plm_cRecNmbr, plm_szSqlState, &plm_pfNativeError,
				plm_szErrorMsg, 1024 - 1, &plm_pcbErrorMsg);

		// Note that if the application has not yet made a
		// successful connection, the SQLGetDiagField
		// information has not yet been cached by ODBC
		// Driver Manager and these calls to SQLGetDiagField
		// will fail.
		if(SQL_INVALID_HANDLE == plm_retcode)
		{// 2006-05-18 by cmkwon
			break;
		}
		if (plm_retcode != SQL_NO_DATA_FOUND)
		{
			if (ConnInd)
			{
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_ROW_NUMBER, &plm_Rownumber, SQL_IS_INTEGER, NULL);
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_SS_LINE, &plm_SS_Line, SQL_IS_INTEGER, NULL);
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_SS_MSGSTATE, &plm_SS_MsgState, SQL_IS_INTEGER, NULL);
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_SS_SEVERITY, &plm_SS_Severity, SQL_IS_INTEGER, NULL);
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_SS_PROCNAME, &plm_SS_Procname, sizeof(plm_SS_Procname), &plm_cbSS_Procname);
				plm_retcode = SQLGetDiagField(plm_handle_type, plm_handle, plm_cRecNmbr, SQL_DIAG_SS_SRVNAME, &plm_SS_Srvname, sizeof(plm_SS_Srvname), &plm_cbSS_Srvname);
			}

			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	szSqlState    = %s\r\n",plm_szSqlState);
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	pfNativeError = %d\r\n",plm_pfNativeError);
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	szErrorMsg    = %s\r\n",plm_szErrorMsg);
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	pcbErrorMsg   = %d\r\n\r\n",plm_pcbErrorMsg);

			if ( strcmp((char*)plm_szSqlState, "2400") == 0	)	// �߸��� Ŀ�� ���� ����
			{
				DBWorkerTLSDATA *pTlsData = GetDBWorkerTLSDATA();
				
				// 2006-05-17 by cmkwon, AutoCommit
				SQLFreeHandle(SQL_HANDLE_STMT, pTlsData->hstmt);
				SQLAllocHandle(SQL_HANDLE_STMT, pTlsData->hdbc, &pTlsData->hstmt);

				// 2006-05-17 by cmkwon, ManualCommit
				SQLFreeHandle(SQL_HANDLE_STMT, pTlsData->hstmt_mc);
				SQLAllocHandle(SQL_HANDLE_STMT, pTlsData->hdbc_mc, &pTlsData->hstmt_mc);

				// 2006-05-17 by cmkwon
				if(m_bExtAuthDBConnect)
				{
					SQLFreeHandle(SQL_HANDLE_STMT, pTlsData->hstmt_ExtAuth);
					SQLAllocHandle(SQL_HANDLE_STMT, pTlsData->hdbc_ExtAuth, &pTlsData->hstmt_ExtAuth);
				}
			}
			else if ( strcmp((char*)plm_szSqlState, "08S01") == 0	// Communication link failure
				|| strcmp((char*)plm_szSqlState, "01000") == 0	// �Ϲ� ��Ʈ�p ����
			)
			{
				DBWorkerTLSDATA *pTlsData = GetDBWorkerTLSDATA();

				// start 2011-07-15 by hskim, ���� ���� ���� (DB ���� �ٿ�� �״� ���� ó��)
				if( NULL == pTlsData )
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) DBWorker TLSData is NULL!!\r\n", GetCurrentThreadId());
					
					// 2011-07-15 by hskim
					// DB ���� ���õǾ� ������ �����ߴٸ� �ٽ� ����(����)�ϴ°ͺ��� ���� ����� Ȯ�ΰ� �ļ� ��ġ �� ������� �ʿ��ϴٰ� �Ǵ��մϴ�.
					// ���� ����ϴ� �̻� �̷� ��å���� ó���� �����Դϴ�.

					exit(1);
				}
				// end 2011-07-15 by hskim, ���� ���� ���� (DB ���� �ٿ�� �״� ���� ó��)				

				DisconnectDBServer(pTlsData, EN_DBCONN_AUTO_COMMIT);
				DisconnectDBServer(pTlsData, EN_DBCONN_MANUAL_COMMIT);
				DisconnectDBServer(pTlsData, EN_DBCONN_EXT_AUTH);
				DisconnectDBServer(pTlsData, EN_DBCONN_GLOG_COMMIT);	// 2013-06-20 by jhseol,bckim GLog ����

				BOOL bRet = Connect2DBServer(pTlsData, EN_DBCONN_AUTO_COMMIT);
				if(bRet)
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_4 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt, EN_DBCONN_AUTO_COMMIT);
				}
				else
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_4 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_AUTO_COMMIT);
				}
				bRet = Connect2DBServer(pTlsData, EN_DBCONN_MANUAL_COMMIT);
				if(bRet)
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_4 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_mc, EN_DBCONN_MANUAL_COMMIT);
				}
				else
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_4 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_MANUAL_COMMIT);
				}
				if(m_bExtAuthDBConnect)
				{
					bRet = Connect2DBServer(pTlsData, EN_DBCONN_EXT_AUTH);
					if(bRet)
					{
						g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_4 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_ExtAuth, EN_DBCONN_EXT_AUTH);
					}
					else
					{
						g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_4 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_EXT_AUTH);
					}
				}
				// 2013-06-20 by jhseol,bckim GLog ����
#ifdef S_GLOG_3ND_KHK
				bRet = Connect2DBServer(pTlsData, EN_DBCONN_GLOG_COMMIT);
				if(bRet)
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Notify] ThreadID(%5d) Connect2DBServer_4 success !!, hstmt(0x%X) dbConnType(%d)\r\n", GetCurrentThreadId(), pTlsData->hstmt_GLog, EN_DBCONN_GLOG_COMMIT);
				}
				else
				{
					g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[DB Error] ThreadID(%5d) Connect2DBServer_4 error !!, dbConnType(%d)\r\n", GetCurrentThreadId(), EN_DBCONN_GLOG_COMMIT);
				}
#endif
				// end 2013-06-20 by jhseol,bckim GLog ����
				return;
			}

			if (ConnInd)
			{
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	ODBCRowNumber = %d\r\n", plm_Rownumber);
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	SSrvrLine     = %d\r\n", plm_Rownumber);
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	SSrvrMsgState = %d\r\n",plm_SS_MsgState);
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	SSrvrSeverity = %d\r\n",plm_SS_Severity);
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	SSrvrProcname = %s\r\n",plm_SS_Procname);
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "	SSrvrSrvname  = %s\r\n\r\n",plm_SS_Srvname);
			}
		}// End_if (plm_retcode != SQL_NO_DATA_FOUND)
		
		plm_cRecNmbr++;		// Increment to next diagnostic record.

	}// End_while (plm_retcode != SQL_NO_DATA_FOUND)
}

RETCODE CAtumDBManager::GetDBError(SQLHSTMT hstmt, UCHAR *sqlState)
{
	UCHAR plm_szErrorMsg[MAXDBMSGBUFLEN] = "";
	SDWORD plm_pfNativeError = 0L;
	SWORD plm_pcbErrorMsg = 0;
	RETCODE retcode = SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, 1, sqlState, &plm_pfNativeError, plm_szErrorMsg, MAXDBMSGBUFLEN - 1, &plm_pcbErrorMsg);

	return retcode;
}

char* CAtumDBManager::GetSqlPattern(const char* str, char* buf)
{
	///////////////////////////////////////////////////////////////////////////////	
	// 2009-01-28 by cmkwon, �Ϻ� ĳ���͸� ���� ���� ���� - 
	MEMSET_ZERO(buf, SIZE_MAX_SQL_PATTERN_BUFFER);

	int		nOffset		= 0;
	int		nLen		= strlen(str);
	char *	pCurStr		= (char*)(str);
	while(pCurStr && pCurStr < str + nLen)
	{
		switch (*pCurStr)
		{
		case '%':
		case '[':
		case '_':
			{
 				if (nOffset+3 >= SIZE_MAX_SQL_PATTERN_BUFFER)
 				{
 					strcpy(buf, '\0');
 					return buf;
 				}
				buf[nOffset++] = '[';
				buf[nOffset++] = *pCurStr;
				buf[nOffset++] = ']';
			}
			break;
		default:
			{
				BOOL bIsDBSLeadByte = IsDBCSLeadByte(*pCurStr);

				if(FALSE == bIsDBSLeadByte)
				{
					if (nOffset+1 >= SIZE_MAX_SQL_PATTERN_BUFFER)
					{
						strcpy(buf, '\0');
						return buf;
					}
					buf[nOffset++]		= *pCurStr;

				}
				else
				{
					if (nOffset+2 >= SIZE_MAX_SQL_PATTERN_BUFFER)
					{
						strcpy(buf, '\0');
						return buf;
					}
					buf[nOffset++]		= *pCurStr;
					buf[nOffset++]		= *(pCurStr+1);
				}
			}
		}
		pCurStr = CharNext(pCurStr);		// ���� ���ڷ� �̵�
	}
	return buf;
	

// 2009-01-28 by cmkwon, �Ϻ� ĳ���͸� ���� ���� ���� - ���� ���� ���� ��.
// 	int len = strlen(str);
// 	int offset = 0;
// 
// 	for (int i = 0; i < len; i++)
// 	{
// 		if (str[i] == '%')
// 		{
// 			if (offset+3 >= SIZE_MAX_SQL_PATTERN_BUFFER)
// 			{
// 				strcpy(buf, '\0');
// 				return buf;
// 			}
// 
// 			buf[offset++] = '[';
// 			buf[offset++] = '%';
// 			buf[offset++] = ']';
// 		}
// 		else if (str[i] == '[')
// 		{
// 			if (offset+3 >= SIZE_MAX_SQL_PATTERN_BUFFER)
// 			{
// 				strcpy(buf, '\0');
// 				return buf;
// 			}
// 
// 			buf[offset++] = '[';
// 			buf[offset++] = '[';
// 			buf[offset++] = ']';
// 		}
// 		else if (str[i] == '_')
// 		{
// 			if (offset+3 >= SIZE_MAX_SQL_PATTERN_BUFFER)
// 			{
// 				strcpy(buf, '\0');
// 				return buf;
// 			}
// 
// 			buf[offset++] = '[';
// 			buf[offset++] = '_';
// 			buf[offset++] = ']';
// 		}
// 		else
// 		{
// 			if (offset+1 >= SIZE_MAX_SQL_PATTERN_BUFFER)
// 			{
// 				strcpy(buf, '\0');
// 				return buf;
// 			}
// 
// 			buf[offset++] = str[i];
// 		}
// 	}
// 
// 	buf[offset] = '\0';
//
//	return buf;
}

const char* GetDBQueryTypeString(EnumQueryType qType)
{
	switch(qType)
	{
	case QT_CreateCharacter:						return "QT_CreateCharacter";
	case QT_DeleteCharacter:						return "QT_DeleteCharacter";
	case QT_GetCharacterInfoByName:					return "QT_GetCharacterInfoByName";
	case QT_GetAccountUniqueNumber:					return "QT_GetAccountUniqueNumber";
	case QT_ConnectGameStart:						return "QT_ConnectGameStart";
	case QT_GetAllCharacterInfoByID:				return "QT_GetAllCharacterInfoByID";
	case QT_SaveCharacterCriticalData:				return "QT_SaveCharacterCriticalData";
	case QT_ChangeUnitKind:							return "QT_ChangeUnitKind";
	case QT_ChangeStat:								return "QT_ChangeStat";
	case QT_ChangeBonusStatPoint:					return "QT_ChangeBonusStatPoint";
	case QT_ChangeGuild:							return "QT_ChangeGuild";
	case QT_ChangeFriendGroup:						return "QT_ChangeFriendGroup";
	case QT_ChangeExp:								return "QT_ChangeExp";
	case QT_ChangeLevel:							return "QT_ChangeLevel";
	case QT_ChangeBodyCondition:					return "QT_ChangeBodyCondition";
//	case QT_ChangePropensity:
//		return "QT_ChangePropensity";
	case QT_ChangeStatus:							return "QT_ChangeStatus";
	case QT_ChangePKPoint:							return "QT_ChangePKPoint";
// 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - ������� �����Ƿ� ����
//	case QT_ChangeRacingPoint:						return "QT_ChangeRacingPoint";
	case QT_UpdateTotalPlayTime:					return "QT_UpdateTotalPlayTime";
	case QT_UpdateLastStartedTime:					return "QT_UpdateLastStartedTime";
	case QT_ChangeHPDPSPEP:							return "QT_ChangeHPDPSPEP";
	case QT_ChangeCurrentHPDPSPEP:					return "QT_ChangeCurrentHPDPSPEP";
	case QT_ChangeMapChannel:						return "QT_ChangeMapChannel";
	case QT_ChangePetInfo:							return "QT_ChangePetInfo";
	case QT_ChangeDockingItem:						return "QT_ChangeDockingItem";
	case QT_ChangePosition:							return "QT_ChangePosition";

	case QT_AuthChatLogin:							return "QT_AuthChatLogin";
	case QT_SaveLastPartyID:						return "QT_SaveLastPartyID";
	case QT_EventWarpConnect:						return "QT_EventWarpConnect";
	case QT_PRE_Login:								return "QT_PRE_Login";
	case QT_BlockUser:								return "QT_BlockUser";
	case QT_UnblockUser:							return "QT_UnblockUser";
	case QT_MGameLogin:								return "QT_MGameLogin";
	case QT_LogTotalUser:							return "QT_LogTotalUser";			// 2007-03-16 by cmkwon
	case QT_InsertGlogAccount:						return "QT_InsertGlogAccount";		// 2010-06-01 by shcho, GLogDB ���� -
	case QT_UpdateAccountLastGameEndDate:			return "QT_UpdateAccountLastGameEndDate";		// 2012-01-13 by hskim, EP4 [������ 1ȸ ���]

	case QT_GetStoreItem:							return "QT_GetStoreItem";
	case QT_ReloadAllEnchant:						return "QT_ReloadAllEnchant";
	case QT_DeleteStoreItem:						return "QT_DeleteStoreItem";
	case QT_InsertStoreItem:						return "QT_InsertStoreItem";
	case QT_InsertStoreItemSkill:					return "QT_InsertStoreItemSkill";
	case QT_UpdateStoreItemSkillUseTime:			return "QT_UpdateStoreItemSkillUseTime";	// 2006-11-17 by dhjin
	case QT_UpdateItemCount:						return "QT_UpdateItemCount";
	case QT_UpdateItemNum:							return "QT_UpdateItemNum";
	case QT_UpdateEndurance:						return "QT_UpdateEndurance";
	case QT_StoreUpdateColorCode:					return "QT_StoreUpdateColorCode";
	case QT_UpdateShapeItemNum:						return "QT_UpdateShapeItemNum";		// 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - 

	case QT_UpdateItemUsingTimeStamp:				return "QT_UpdateItemUsingTimeStamp";
	case QT_UpdateItemRareFix:						return "QT_UpdateItemRareFix";
	case QT_InsertDefaultItems:						return "QT_InsertDefaultItems";
	case QT_ChangeItemPosition:						return "QT_ChangeItemPosition";
	case QT_UpdateWindowItemList:					return "QT_UpdateWindowItemList";
	case QT_UpdateItemPossess:						return "QT_UpdateItemPossess";
	case QT_UpdateItemStorage:						return "QT_UpdateItemStorage";
	case QT_LoadOneItem:							return "QT_LoadOneItem";
	case QT_INSERTLOGINITEMEVENT:					return "QT_INSERTLOGINITEMEVENT";		// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
	case QT_CheckEventItem:							return "QT_CheckEventItem";
	case QT_InsertEventItem:						return "QT_InsertEventItem";
	case QT_UpdateEventItemFixedPeriod:				return "QT_UpdateEventItemFixedPeriod";	// 2013-02-28 by bckim, �������� �����߰�
	case QT_CheckCouponEvent:						return "QT_CheckCouponEvent";			// 2008-01-10 by cmkwon, ������ �̺�Ʈ �ý��ۿ� �� ���� �ý��� �߰� - 
	case QT_GetGuildStoreItem:						return "QT_GetGuildStoreItem";	
	case QT_UpdateGuildStoreItem:					return "QT_UpdateGuildStoreItem";	
	case QT_InsertGuildStoreItem:					return "QT_InsertGuildStoreItem";	
	case QT_DeleteGuildStoreItem:					return "QT_DeleteGuildStoreItem";	
	case QT_GetLogGuildStoreItem:					return "QT_GetLogGuildStoreItem";	
	case QT_AllDeleteGuildStoreItem:				return "QT_AllDeleteGuildStoreItem";	
	case QT_Insert2WarpableUserList:				return "QT_Insert2WarpableUserList";	// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �����㰡 �߰�
	case QT_DeleteWarpableUser:						return "QT_DeleteWarpableUser";			// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �����㰡 ����
	case QT_UPDATE_ConnectingServerGroupID:			return "QT_UPDATE_ConnectingServerGroupID";			// 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ�
	case QT_GiveStoreItem:							return "QT_GiveStoreItem";			// 2007-11-13 by cmkwon, �����ϱ� ��� �߰� - 
	case QT_GetLetter:								return "QT_GetLetter";			// 2008-04-24 by dhjin, EP3 ���� �ý��� - DB���� ���� �������� 
	case QT_ReadLetter:								return "QT_ReadLetter";			// 2008-04-24 by dhjin, EP3 ���� �ý��� - ���� �б�
	case QT_DeleteLetter:							return "QT_DeleteLetter";		// 2008-04-24 by dhjin, EP3 ���� �ý��� - ���� ����
	case QT_SendLetter:								return "QT_SendLetter";			// 2008-05-08 by dhjin, EP3 ���� �ý��� - ���� ������
	case QT_GetAllLetter:							return "QT_GetAllLetter";		// 2008-05-09 by dhjin, EP3 ���� �ý��� - DB���� ��ü ���� ��������
	case QT_SendAllLetter:							return "QT_SendAllLetter";		// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� ������
	case QT_ReadAllLetter:							return "QT_ReadAllLetter";		// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� �б�
	case QT_DeleteAllLetter:						return "QT_DeleteAllLetter";	// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� ����
	case QT_DeleteOldAllLetter:						return "QT_DeleteOldAllLetter";	// 2008-05-09 by dhjin, EP3 ���� �ý��� - ������ ��ü ���� ����

	case QT_GuildCreate:							return "QT_GuildCreate";
	case QT_GuildAddMember:							return "QT_GuildAddMember";
	case QT_GuildAddOffMember:						return "QT_GuildAddOffMember";		// 2008-06-12 by dhjin, EP3 - ���� ���� ���� - �������� ���� ����
	case QT_GuildLeaveMember:						return "QT_GuildLeaveMember";
	case QT_GuildBanMember:							return "QT_GuildBanMember";
	case QT_GuildUpdateMemberCapacity:				return "QT_GuildUpdateMemberCapacity";
	case QT_GuildLoadGuild:							return "QT_GuildLoadGuild";
	case QT_GuildDismember:							return "QT_GuildDismember";
	case QT_GuildCancelDismember:					return "QT_GuildCancelDismember";
	case QT_GuildChangeGuildName:					return "QT_GuildChangeGuildName";
	case QT_GuildSetGuildMark:						return "QT_GuildSetGuildMark";
// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - ������� �ȴ� �Լ���
//	case QT_GuildGetGuildMark:						return "QT_GuildGetGuildMark";
	case QT_GuildSetRank:							return "QT_GuildSetRank";
	case QT_GuildDeleteGuild:						return "QT_GuildDeleteGuild";
	case QT_GuildSaveGuildWarPoint:					return "QT_GuildSaveGuildWarPoint";
	case QT_GuildDeleteGuildUIDOfCharacter:			return "QT_GuildDeleteGuildUIDOfCharacter";
	case QT_GuildAddGuildFame:						return "QT_GuildAddGuildFame";
	case QT_GuildUpdateCommander:					return "QT_GuildUpdateCommander";			// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - ������ ����
	case QT_GuildNotice:							return "QT_GuildNotice";					// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - ���� ����
	case QT_GuildGetApplicant:						return "QT_GuildGetApplicant";				// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	case QT_GuildGetIntroduction:					return "QT_GuildGetIntroduction";				// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	case QT_GuildDeleteIntroduction:				return "QT_GuildDeleteIntroduction";				// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	case QT_GetSelfIntroduction:					return "QT_GetSelfIntroduction";			// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� ������ �Ұ��� 
	case QT_GuildSearchIntroduction:				return "QT_GuildSearchIntroduction";			// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ� �˻�
	case QT_GuildUpdateIntroduction:				return "QT_GuildUpdateIntroduction";			// 2008-05-27 by dhjin,	EP3 - ���� ���� ���� - ���� �Ұ� �ۼ�
	case QT_GuildUpdateSelfIntroduction:			return "QT_GuildUpdateSelfIntroduction";		// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� �ۼ� 
	case QT_GuildDeleteSelfIntroduction:			return "QT_GuildDeleteSelfIntroduction";		// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� ����� 
	case QT_GuildDeleteSelfIntroductionOffUser:		return "QT_GuildDeleteSelfIntroductionOffUser";		// 2008-06-13 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� ����� 

	case QT_ExecuteTrade:							return "QT_ExecuteTrade";
	case QT_TradeMoveItem:							return "QT_TradeMoveItem";

	case QT_InsertEnchant:							return "QT_InsertEnchant";
	case QT_DeleteAllEnchant:						return "QT_DeleteAllEnchant";
	case QT_GetAllQuest:							return "QT_GetAllQuest";
	case QT_InsertQuest:							return "QT_InsertQuest";
	case QT_UpdateQuestState:						return "QT_UpdateQuestState";
	case QT_DeleteQuest:							return "QT_DeleteQuest";
	case QT_UpdateQuestMonsterCount:				return "QT_UpdateQuestMonsterCount";
	case QT_DeleteQuestMonsterCount:				return "QT_DeleteQuestMonsterCount";

	case QT_AuctionGetItemList:						return "QT_AuctionGetItemList";
	case QT_AuctionRegisterItem:					return "QT_AuctionRegisterItem";
	case QT_AuctionCancelRegister:					return "QT_AuctionCancelRegister";
	case QT_AuctionBuyItem:							return "QT_AuctionBuyItem";
	case QT_InsertCombatPowerLog:					return "QT_InsertCombatPowerLog";	// 2014-03-14 by jekim, ������ �α� �߰�
	case QT_GeneralExec:							return "QT_GeneralExec";
	case QT_FriendInsertFriend:						return "QT_FriendInsertFriend";
	case QT_FriendDeleteFriend:						return "QT_FriendDeleteFriend";
	case QT_FriendLoadFriends:						return "QT_FriendLoadFriends";
	case QT_CashInsertPremiumCard:					return "QT_CashInsertPremiumCard";
	case QT_CashUpdatePremiumCard:					return "QT_CashUpdatePremiumCard";
	case QT_CashDeletePremiumCard:					return "QT_CashDeletePremiumCard";

	case QT_LoadHappyHourEvent:						return "QT_LoadHappyHourEvent";
	case QT_LoadItemEvent:							return "QT_LoadItemEvent";	
// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList ���� - 
//	case QT_UpdatePCBangList:						return "QT_UpdatePCBangList";	
	case QT_Get_QuickSlot:							return "QT_Get_QuickSlot";			// 2006-09-04 by dhjin
	case QT_Delete_QuickSlot:						return "QT_Delete_QuickSlot";		// 2006-09-04 by dhjin
	case QT_Update_QuickSlot:						return "QT_Update_QuickSlot";		// 2006-09-04 by dhjin

	// 2007-02-28 by dhjin, ��������Ʈ ���� �ֱ� ���� ����.
	case QT_LoadStrategyPointSummonInfo:					return "QT_LoadStrategyPointSummonInfo";
	case QT_UpdateStrategyPointSummonInfoBySummon:			return "QT_UpdateStrategyPointSummonInfoBySummon";
	case QT_UpdateStrategyPointSummonInfoBySummonTime:		return "QT_UpdateStrategyPointSummonInfoBySummonTime";
	case QT_InsertStrategyPointSummonInfoBySummon:			return "QT_InsertStrategyPointSummonInfoBySummon";
	case QT_DeleteStrategyPointSummonInfoBySummon:			return "QT_DeleteStrategyPointSummonInfoBySummon";
	case QT_UpdateStrategyPointSummonInfoByNewSummonRange:	return "QT_UpdateStrategyPointSummonInfoByNewSummonRange";
	case QT_LoadStrategyPointSummonRange:					return "QT_LoadStrategyPointSummonRange";
	case QT_LoadStrategyPointNotSummonTime:					return "QT_LoadStrategyPointNotSummonTime";
	case QT_LoadStrategyPointNotSummonTimeByAdminTool:		return "QT_LoadStrategyPointNotSummonTimeByAdminTool";

	case QT_UpdateHappyHourEventDate:				return "QT_UpdateHappyHourEventDate";
	case QT_UpdateInfluenceWarData:					return "QT_UpdateInfluenceWarData";
	case QT_UpdateOwnerOfConflictArea:				return "QT_UpdateOwnerOfConflictArea";
	case QT_UpdateSubleader:						return "QT_UpdateSubleader";		// 2007-02-13 by dhjin

	case QT_JamboreeInit:							return "QT_JamboreeInit";			// 2007-04-10 by cmkwon
	case QT_JamboreeEntrants:						return "QT_JamboreeEntrants";		// 2007-04-10 by cmkwon

	case QT_UpdateWarPoint:							return "QT_UpdateWarPoint";			// 2007-04-25 by dhjin
	case QT_UpdateArenaResult:						return "QT_UpdateArenaResult";			// 2007-06-07 by dhjin
	case QT_UpdateArenaDisConnect:					return "QT_UpdateArenaDisConnect";			// 2007-06-07 by dhjin
	case QT_MF_Updata_CharacterArena:				return "QT_MF_Updata_CharacterArena";	// 2012-04-12 by jhseol, �Ʒ��� �߰����� - ���� : AS���� ���� CharacterArena ���� ������Ʈ


	case QT_LoadTutorialComplete:					return "QT_LoadTutorialComplete";			// 2007-07-06 by dhjin
	case QT_InsertTutorialComplete:					return "QT_InsertTutorialComplete";			// 2007-07-06 by dhjin

	case QT_SetNPCPossessionOutPost:				return "QT_SetNPCPossessionOutPost";			// 2007-08-21 by dhjin
	case QT_SetGuildPossessionOutPost:				return "QT_SetGuildPossessionOutPost";			// 2007-08-21 by dhjin
	case QT_SetOutPostNextWarTime:					return "QT_SetOutPostNextWarTime";			// 2007-08-21 by dhjin
	
	case QT_InitExpediencyFund:						return "QT_InitExpediencyFund";				// 2007-08-22 by dhjin
	case QT_SetExpediencyFund:						return "QT_SetExpediencyFund";				// 2007-08-22 by dhjin
	case QT_SetExpediencyFundPayBack:				return "QT_SetExpediencyFundPayBack";			// 2007-08-22 by dhjin
	case QT_SetExpediencyFundRate:					return "QT_SetExpediencyFundRate";			// 2007-08-22 by dhjin
	case QT_DeleteCityLeaderInfo:					return "QT_DeleteCityLeaderInfo";			// 2007-08-22 by dhjin
	case QT_RegNotice:								return "QT_RegNotice";						// 2007-08-22 by dhjin
	case QT_ModifyNotice:							return "QT_ModifyNotice";					// 2007-08-22 by dhjin
	case QT_UpdateSecondaryPassword:				return "QT_UpdateSecondaryPassword";		// 2007-09-12 by cmkwon

	case QT_LoadVoterList:							return "QT_LoadVoterList";		// 2007-10-29 by dhjin
	case QT_LoadLeaderCandidate:					return "LoadLeaderCandidate";		// 2007-10-29 by dhjin
	case QT_SelectLeaderCandidateInfoByRealTimeVariable:	return "QT_SelectLeaderCandidateInfoByRealTimeVariable";		// 2007-10-30 by dhjin
	case QT_InsertLeaderCandidate:					return "QT_InsertLeaderCandidate";		// 2007-10-30 by dhjin
	case QT_UpdateLeaderDeleteCandidate:			return "QT_UpdateLeaderDeleteCandidate";		// 2007-10-30 by dhjin
	case QT_UpdateLeaderPollCount:					return "QT_UpdateLeaderPollCount";		// 2007-10-31 by dhjin
	case QT_InsertVoterList:						return "QT_InsertVoterList";		// 2007-10-31 by dhjin
	case QT_CheckGiveTarget:						return "QT_CheckGiveTarget";		// 2007-11-13 by cmkwon, �����ϱ� ��� �߰� -
	case QT_UpdatePilotFace:						return "QT_UpdatePilotFace";		// 2007-11-21 by cmkwon, PilotFace ���� ī�� ���� - 

	case QT_InsertNotifyMsg:						return "QT_InsertNotifyMsg";		// 2007-11-28 by cmkwon, �����ý��� ���� -
	case QT_GetNotifyMsg:							return "QT_GetNotifyMsg";			// 2007-11-28 by cmkwon, �����ý��� ���� -
	case QT_DeleteNotifyMsg:						return "QT_DeleteNotifyMsg";		// 2007-11-28 by cmkwon, �����ý��� ���� -
		
	case QT_GetGuildMark:							return "QT_GetGuildMark";		// 2007-12-07 by dhjin
	
	//////////////////////////////////////////////////////////////////////////
	// 2007-12-28 by dhjin, �Ʒ��� ���� - 
	case QT_ArenaUpdateCharacterInfo:				return "QT_ArenaUpdateCharacterInfo";
	case QT_ArenaGetCharacter:						return "QT_ArenaGetCharacter";
	case QT_ArenaCopyDBInfo:						return "QT_ArenaCopyDBInfo";
	case QT_ArenaStartGetCharacter:					return "QT_ArenaStartGetCharacter";

	//////////////////////////////////////////////////////////////////////////
	// 2008-04-02 by dhjin,	����, ������ ����â ��ȹ�� -
	case QT_GetLogMSWarInfo:						return "QT_GetLogMSWarInfo";
	case QT_GetLogSPWarInfo:						return "QT_GetLogSPWarInfo";
	case QT_UpdateMSWarOptionType:					return "QT_UpdateMSWarOptionType";
	case QT_InsertMSWarLog:							return "QT_InsertMSWarLog";		// 2008-08-28 by dhjin, ���� ����, ����DB�� ���ܾ� Admintool�� �ʱ�ȭ�� �����ϴ�.
	case QT_InsertSPWarLog:							return "QT_InsertSPWarLog";		// 2008-08-28 by dhjin, ���� ����, ����DB�� ���ܾ� Admintool�� �ʱ�ȭ�� �����ϴ�.


	case QT_UpdateDBServerGroup:					return "QT_UpdateDBServerGroup";		// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	case QT_CheckConnectableAccount:				return "QT_CheckConnectableAccount";	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 

	case QT_GetUserInfo:							return "QT_GetUserInfo";					// 2008-06-23 by dhjin, EP3 ���������ɼ� - �ٸ� ���� ���� ��û

// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - DQT_DailyJob �� ���� ��.
//	//////////////////////////////////////////////////////////////////////////
//	// 2008-08-19 by dhjin, MySQL���� ������ MySQL���� �������� �ʴ� MSSQL�� Job���� �۾��� ���⼭ ó���Ѵ�.
//	case QT_DailyJob:								return "QT_DailyJob";

	// 2008-11-04 by dhjin, ��Ű�ӽ�
	case QT_UpdateLuckyItemDropCount:				return "QT_UpdateLuckyItemDropCount";
	case QT_UpdateLuckyItemStarttime:				return "QT_UpdateLuckyItemStarttime";
		
	//////////////////////////////////////////////////////////////////////////
	// 2009-01-12 by dhjin, ���� ����
	case QT_UpdateStartDeclarationOfWar:			return "QT_UpdateStartDeclarationOfWar";
	case QT_UpdateEndDeclarationOfWar:				return "QT_UpdateEndDeclarationOfWar";
	case QT_UpdateMSWarStartTime:					return "QT_UpdateMSWarStartTime";		
	case QT_UpdateNickName:							return "QT_UpdateNickName";			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	case QT_GetSelfRanking:							return "QT_GetSelfRanking";			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 

	case QT_ChangeItemWithItemMatching:				return "QT_ChangeItemWithItemMatching";		// 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 

	case QT_ChangeStartCityMapIndex:				return "QT_ChangeStartCityMapIndex";		// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
	case QT_ChangeAddedInventoryCount:				return "QT_ChangeAddedInventoryCount";		// 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - 

	case QT_LoadInfinityImpute:						return "QT_LoadInfinityImpute";		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �ͼ� ���� ��������
	case QT_InsertInfinityImpute:					return "QT_InsertInfinityImpute";	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �ͼ� ���� �߰�
	case QT_UpdateInfinityImpute:					return "QT_UpdateInfinityImpute";	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �Ϸ� 
	case QT_ResetInfinityImpute:					return "QT_ResetInfinityImpute";	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	�ش� ���� �������� ���� ����
	case QT_ArenaCopyInfinityDBInfo:				return "QT_ArenaCopyInfinityDBInfo";	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �Ʒ���DB�� �����ϱ�
	case QT_CharacterSaveDataInfinityFin:			return "QT_CharacterSaveDataInfinityFin";		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ �ɸ��� ���� ����
	case QT_InfinityFinUpdateItem:					return "QT_InfinityFinUpdateItem";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ ���� ����
	case QT_InfinityFinInsertItem:					return "QT_InfinityFinInsertItem";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ �߰���
	case QT_InfinityInsertLog:						return "QT_InfinityInsertLog";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �α�
	case QT_CharacterSaveDataInfinityFinByDisconnect:	return "QT_CharacterSaveDataInfinityFinByDisconnect";		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ �ɸ��� ���� ����
	case QT_InfinityFinUpdateItemByDisconnect:			return "QT_InfinityFinUpdateItemByDisconnect";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ ���� ����
	case QT_InfinityFinInsertItemByDisconnect:			return "QT_InfinityFinInsertItemByDisconnect";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ �߰���
	case QT_ResetInfinityImputeByServerStart:			return "QT_ResetInfinityImputeByServerStart";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���۽� ���� ����
	case QT_InfinityComBackPostWork:					return "QT_InfinityComBackPostWork";						// 2012-01-16 by hskim, ��� - ȭ��

// 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - 
//	case QT_LoadTenderInfo:							return "QT_LoadTenderInfo";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Tender

	case QT_CashLoadPremiumCard:					return "QT_CashLoadPremiumCard";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �����̾� ���� ��������
	case QT_LoadInfinityShopInfo:					return "QT_LoadInfinityShopInfo";				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ����
	case QT_InfinityUpdateUserMapInfo:				return "QT_InfinityUpdateUserMapInfo";			// 2010-04-06 by cmkwon, ����2�� �߰� ���� - 
	case QT_LoadBurningMap:							return "QT_LoadBurningMap";						// 2010-08-05 by dhjin, ���׸� -
	case QT_Log_UserGetTenderItem:					return "QT_Log_UserGetTenderItem";				// 2010-06-25 by shcho, ���Ǵ�Ƽ ���÷α� ��� - ���� ������ ���� DB����
	case QT_NA:										return "QT_NA";

	///////////////////////////////////////////////////////////////////////////////
	// 2011-08-22 by hskim, ��Ʈ�� �ý��� 2�� - ��� ����

	case QT_PetUpdateInfinityFin:					return "QT_PetUpdateInfinityFin";
	case QT_PetSetName:								return "QT_PetSetName";
	case QT_PetSetExpRatio:							return "QT_PetSetExpRatio";
	case QT_PetSetLevel:							return "QT_PetSetLevel";
	case QT_PetSetExp:								return "QT_PetSetExp";
	case QT_PetSetSocket:							return "QT_PetSetSocket";
	case QT_PetSetKitSlot:							return "QT_PetSetKitSlot";
	case QT_PetSetAutoSkillSlot:					return "QT_PetSetAutoSkillSlot";
	case QT_PetChangeSocketOwner:					return "QT_PetChangeSocketOwner";				// 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�
	case QT_StoreGetItemOne:						return "QT_StoreGetItemOne";				// 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�

	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
	case DQT_DailyJob:								return "DQT_DailyJob";
	case DQT_UpdatePCBangList:						return "DQT_UpdatePCBangList";		// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList ���� - 
	case DQT_ReloadWRKServiceList:					return "DQT_ReloadWRKServiceList";	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	case DQT_ReloadWRKLevel:						return "DQT_ReloadWRKLevel";		// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	case DQT_ReloadWRKFame:							return "DQT_ReloadWRKFame";			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	case DQT_ReloadWRKPVP:							return "DQT_ReloadWRKPVP";			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	case DQT_LoadInfluenceRate:						return "DQT_LoadInfluenceRate";				// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 

	case DQT_NA:									return "DQT_NA";			// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 		

	case QT_ArenaCharacterReset:					return "QT_ArenaCharacterReset";	// 2012-10-21 by jhseol, �Ʒ��� ���׼��� - �Ʒ��� ����� �ɸ��� ���� ����.

	//////////////////////////////////////////////////////////////////////////////
	// 2012-11-13 by jhseol, ���� �ý��� ������ - ������
	case QT_LoadRenewalStrategyPointSummonInfo:		return "QT_LoadRenewalStrategyPointSummonInfo";
	case QT_UpdateStrategyPointSummonInfo:			return "QT_UpdateStrategyPointSummonInfo";
	// end 2012-11-13 by jhseol, ���� �ý��� ������ - ������

	case QT_ArenaCharacterReload:					return "QT_ArenaCharacterReload";	// 2012-12-18 by jhseol, �Ʒ��� ĳ���� ���� �� ĳ���� ���� �ٽ� �ε��ϱ�.

	case QT_InsertStoreItemFromXMLRPC:				return "QT_InsertStoreItemFromXMLRPC";		// 2013-03-13 by hskim, �� ĳ�� ����
	case QT_DeleteStoreItemFromXMLRPC:				return "QT_DeleteStoreItemFromXMLRPC";		// 2013-03-13 by hskim, �� ĳ�� ����
	case QT_GetCharacterInfoFromXMLRPC:				return "QT_GetCharacterInfoFromXMLRPC";		// 2013-03-13 by hskim, �� ĳ�� ����
	case QT_LoadCashBuyDate:						return "QT_LoadCashBuyDate";		// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
	case QT_InsertCashBuyDate:						return "QT_InsertCashBuyDate";		// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������

	case QT_LoadMonthlyArmorEvent:					return "QT_LoadMonthlyArmorEvent";	// 2013-04-18 by jhseol,bckim �̴��� �Ƹ� - �̴��� �Ƹ� �̺�Ʈ �ε�

	case QT_UpdateInfluenceConsecutiveVictorites:	return "QT_UpdateInfluenceConsecutiveVictorites";	// 2013-05-09 by hskim, ���� ����Ʈ ����
		
	case QT_GetTemporarySystemInfomation:			return "QT_GetTemporarySystemInfomation";	// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	case QT_GetStoreExtension:						return "QT_GetStoreExtension";				// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	case QT_InsertStoreExtension:					return "QT_InsertStoreExtension";			// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	case QT_CollectionArmorListLoad:				return "QT_CollectionArmorListLoad";		// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �Ƹ� �÷��� �ε�
	case QT_CollectionArmorUpdate:					return "QT_CollectionArmorUpdate";			// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �Ƹ� �÷��� ����
	case QT_AccountInflChange:						return "QT_AccountInflChange";				// 2013-07-26 by jhseol, Ÿ ���� ���º���
	case QT_LoadSPWarInfoResult:					return "QT_LoadSPWarInfoResult";			// 2013-08-14 by jhseol, ������ ������ - ���� ���������� �ε�

	}
	return "QT_UNKNOWN";
}