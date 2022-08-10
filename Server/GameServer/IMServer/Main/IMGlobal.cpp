// IMGlobal.cpp: implementation of the CIMGlobal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IMGlobal.h"
#include "IMIOCP.h"
#include "PreIMWinSocket.h"
#include "Config.h"

CIMGlobal *			g_pIMGlobal = NULL;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIMGlobal::CIMGlobal()
{
	if(g_pIMGlobal)
	{
		return;
	}
	g_pIMGlobal					= this;

	m_nTimerIDServerGroupInfo	= 0;

	m_pIM2PreWinSocket			= NULL;
	m_bArenaIMServerCheck		= FALSE;	// 2012-04-12 by jhseol, 아레나 추가개발 - 자동파티 : 아레나 서버인지 체크
}

CIMGlobal::~CIMGlobal()
{
	EndServerSocket();
	this->DestroyIM2PreWinSocket();

	g_pGlobalGameServer = NULL;
}




///////////////////////////////////////////////////////////////////////////
// Property
///////////////////////////////////////////////////////////////////////////
UINT CIMGlobal::GetTimerIDServerGroupInfo(void)
{
	return m_nTimerIDServerGroupInfo;
}

CIMIOCP * CIMGlobal::GetIMIOCPPtr(void)
{
	return (CIMIOCP*)m_pGIOCP;
}

CPreIMWinSocket * CIMGlobal::GetIM2PreWinSocket(void)
{
	return m_pIM2PreWinSocket;
}

CSystemLogManager * CIMGlobal::GetPtrChattingLogManager(void)
{
	return &m_ChattingLogManager;
}


///////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////

// 2007-11-13 by cmkwon, 관리자, 운영자 채팅 로그 저장하기 - 인자추가(, USHORT i_usRace)
BOOL CIMGlobal::WriteChattingLog(char * i_szChatting, USHORT i_usRace)
{
	// 2014-01-14 by jhseol, 한국 채팅로그 남기도록 수정 - 주석처리
//	//////////////////////////////////////////////////////////////////////////
// 	// 2007-06-05 by dhjin, 한국은 통신비밀보호법에 의해 채팅 로그를 남기지 않는다.
// 	switch(this->GetLanguageType())
// 	{
// 	case LANGUAGE_TYPE_KOREAN:
// 		{
// 			if(FALSE == COMPARE_RACE(i_usRace, RACE_OPERATION|RACE_GAMEMASTER))
// 			{// 2007-11-13 by cmkwon, 관리자, 운영자 채팅 로그 저장하기 - 관리자,운영자 관련 로그가 아니면 저장하지 않는다
// 				return FALSE;
// 			}
// 		}
// 		break;
// 	}
	// end 2014-01-14 by jhseol, 한국 채팅로그 남기도록 수정 - 주석처리

	return this->GetPtrChattingLogManager()->WriteSystemLog(i_szChatting);
}

BOOL CIMGlobal::CreateIM2PreWinSokcet(HWND i_hWnd)
{
	if(m_pIM2PreWinSocket){		return FALSE;}
	if(NULL == m_hMainWndHandle)
	{
		m_hMainWndHandle = i_hWnd;
	}
	m_pIM2PreWinSocket = new CPreIMWinSocket(m_hMainWndHandle, WM_PREIM_ASYNC_EVENT, WM_PREIM_PACKET_NOTIFY);
	return TRUE;
}

void CIMGlobal::DestroyIM2PreWinSocket(void)
{
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - IMServer 
	this->WriteSystemLogEX(TRUE, "  [Notify] CIMGlobal::DestroyIM2PreWinSocket# 0x%X IsConnected(%d) \r\n", m_pIM2PreWinSocket, (m_pIM2PreWinSocket)?m_pIM2PreWinSocket->IsConnected():FALSE);

	if(m_pIM2PreWinSocket && m_pIM2PreWinSocket->IsConnected())
	{
		m_pIM2PreWinSocket->CloseSocket();
	}
	SAFE_DELETE(m_pIM2PreWinSocket);
}

BOOL CIMGlobal::StartTimerSendServerGroupInfo(void)
{
	if(NULL == m_hMainWndHandle || m_nTimerIDServerGroupInfo)
	{
		return FALSE;
	}

	m_nTimerIDServerGroupInfo = ::SetTimer(m_hMainWndHandle, TIMERID_SERVER_GROUP_INFO, TIMERGAP_SERVER_GROUP_INFO, NULL);
	return TRUE;
}

void CIMGlobal::EndTimerSendServerGroupInfo(void)
{
	if(m_nTimerIDServerGroupInfo && m_hMainWndHandle)
	{
		::KillTimer(m_hMainWndHandle, TIMERID_SERVER_GROUP_INFO);
	}
	m_nTimerIDServerGroupInfo = 0;
}


///////////////////////////////////////////////////////////////////////////
// virtual Function
///////////////////////////////////////////////////////////////////////////
BOOL CIMGlobal::InitServerSocket(void)
{
	if(NULL == m_pIM2PreWinSocket || m_pIM2PreWinSocket->IsConnected() == FALSE)
	{
		return FALSE;
	}
	if(NULL != m_pGIOCP){ return FALSE;}

	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CIMGlobal::InitServerSocket# Starting... \r\n");

	m_pGIOCP = new CIMIOCP(m_nPortListening, m_szIPLocal);
	m_pIM2PreWinSocket->SetIMIOCP((CIMIOCP*)m_pGIOCP);
	((CIMIOCP*)m_pGIOCP)->m_pPreWinSocket = m_pIM2PreWinSocket;

	if(m_pGIOCP->IOCPInit() == FALSE)
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] IMServer IOCPInit Error\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
		return FALSE;
	}

	CGlobalGameServer::InitServerSocket();

	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CIMGlobal::InitServerSocket# Started \r\n");

	return TRUE;
}

BOOL CIMGlobal::EndServerSocket(void)
{
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CIMGlobal::EndServerSocket# \r\n");

	CGlobalGameServer::EndServerSocket();

	this->EndTimerSendServerGroupInfo();
	return TRUE;
}


BOOL CIMGlobal::LoadConfiguration(void)
{
	///////////////////////////////////////////////////////////////////////////////
	// 2009-01-21 by cmkwon, 유효한 여단명 체크시에 욕설, 금지어도 체크 추가 - IMServer도 욕설, 금지어 로딩하기
	this->LoadAbuseAndProhibitedName();

	const int SIZE_BUFF = 512;
	char		buff[SIZE_BUFF];
	char		buffBackup[SIZE_BUFF];	// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
	const char	*token;
	char		seps[] = " \t";
	ifstream	fin;
	CConfig		config;

	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	if (!config.LoadUserDefinedVariables(IM_SERVER_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, IM_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	fin.open(IM_SERVER_CONFIG_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...

		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, IM_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	while(TRUE)
	{
		memset(buff, 0x00, SIZE_BUFF);
		BOOL bFlagFileEnd = fin.getline(buff, SIZE_BUFF).eof();
		if(bFlagFileEnd == TRUE
			&& strcmp(buff, "") == 0)
		{
			break;
		}

		STRNCPY_MEMSET(buffBackup, buff, SIZE_BUFF);	// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 

		token = strtok(buff, seps);

		if (token == NULL
			|| strncmp(token, "#", 1) == 0
			|| strncmp(token, "$", 1) == 0)
		{	// ignore blank lines
			// ignore comments
			// ignore user defined variables

			continue;
		}

		if(stricmp(token, "LocalIPAddress") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			if(strcmp(token, "") == 0)
			{
				this->SetIPLocal("127.0.0.1");
			}
			else
			{
				this->SetIPLocal((char*)token);
			}
		}
		else if(stricmp(token, "LocalPublicIPAddress") == 0)
		{// 2006-05-23 by cmkwon,
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			this->SetPublicIPLocal((char*)token);
		}
		else if(stricmp(token, "LocalListenPort") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			if(strcmp(token, "") != 0)
			{
				this->SetPortListening(atoi(token));
			}
		}
		else if(stricmp(token, "LanguageType") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			this->m_nLanguageType = atoi(token);
			if(FALSE == IS_VALID_LANGUAGE_TYPE(this->m_nLanguageType))
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
		}
		else if(stricmp(token, "ODBCDSN") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed. ODBCDSN\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			if(strcmp(token, "") != 0)
			{
				strncpy((char*)m_szODBCDSN, token, SIZE_MAX_ODBC_CONN_STRING);
			}
		}
		else if(stricmp(token, "ODBCUID") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed. ODBCUID\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			if(strcmp(token, "") != 0)
			{
				strncpy((char*)m_szODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szODBCUID, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szODBCUID, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(stricmp(token, "ODBCPASSWD") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed. ODBCPASSWD\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			if(strcmp(token, "") != 0)
			{
				strncpy((char*)m_szODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szODBCPASSWORD, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szODBCPASSWORD, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(stricmp(token, "ServerGroupName") == 0)
		{
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetServerGroupName((char*)token);
			}
		}
		else if(stricmp(token, "PreServer") == 0)
		{
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetIPPreServer((char*)token);
			}
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetPortPreServer(atoi(token));
			}
		}
// 2008-09-24 by cmkwon, global.cfg 형식 수정 - ServerGroupInfo 로 수정 함.
// 		else if(stricmp(token, "ServerGroup") == 0)
// 		{// 2006-04-21 by cmkwon
// 			token = config.strtok(NULL, seps);
// 			if (token == NULL)
// 			{
// 				char	szSystemLog[256];
// 				sprintf(szSystemLog, "[Error] CIMGlobal::LoadConfiguration_ Config Initialization Error2: ServerGroup\r\n");
// 				WriteSystemLog(szSystemLog);
// 				DBGOUT(szSystemLog);
// 				return FALSE;
// 			}
// 
// 			char szGroupName[SIZE_MAX_SERVER_NAME];
// 			strncpy(szGroupName, token, SIZE_MAX_SERVER_NAME);
// 
// 			BOOL nServerIDforMGame = 10061;
// 			token = config.strtok(NULL, seps);
// 			if(token)
// 			{
// 				nServerIDforMGame = atoi(token);
// 			}
// 
// 			if (FALSE == InsertServerGroupforMGame(szGroupName, nServerIDforMGame))
// 			{				
// 				DBGOUT("[ERROR] Already ServerGroupName : %20s, ServerID(%5d)\n", szGroupName, nServerIDforMGame);
// 			}
//		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CIMGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_IP, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_PORT))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CIMGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_PORT, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			m_nDBServerPort = atoi(token);			
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_DATABASE_NAEE))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CIMGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_DATABASE_NAEE, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, "AllowedToolIP"))
		{// 2008-06-05 by cmkwon, AdminTool, Monitor 접근 가능 IP를 server config file 에 설정하기 - 
			
			token = config.strtok(NULL, seps);			
			if (token == NULL)
			{
				continue;
			}
			this->AddAllowedToolIP(token);
		}
		else if(stricmp(token, "ServerGroupInfo") == 0)
		{// 2008-09-24 by cmkwon, global.cfg 형식 수정 - ServerGroup 을 수정한 것임
			
			// 2008-09-24 by cmkwon, Syntax						= [ServerGroupName]			[ServerGroupID]		[Enable Flag]
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				continue;
			}
			char szTemp[CONFIG_SIZE_BUFF];
			STRNCPY_MEMSET(szTemp, token, CONFIG_SIZE_BUFF);
			vectstring tokenList;
			CConfig::GetTokenList(&tokenList, szTemp, seps);
			if(3 > tokenList.size())
			{
				if(0 != tokenList.size())
				{
					g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CIMGlobal::LoadConfiguration# error !! %s\r\n", buffBackup);
					return FALSE;
				}
				continue;
			}
			
			if(SIZE_MAX_SERVER_NAME <= strlen(tokenList[0].c_str()))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CIMGlobal::LoadConfiguration# longer than max servergroupname !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			char	szGroupName[SIZE_MAX_SERVER_NAME];
			STRNCPY_MEMSET(szGroupName, tokenList[0].c_str(), SIZE_MAX_SERVER_NAME);
			int		nMGameServerID		= atoi(tokenList[1].c_str());			
			BOOL	bEnableServerGroup	= FALSE;			
			if(0 == stricmp(tokenList[2].c_str(), "TRUE"))
			{
				bEnableServerGroup	= TRUE;
			}
			
			if(nMGameServerID < SERVERGROUP_START_ID)
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CIMGlobal::LoadConfiguration# smaller than min ServerGroupID !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			if (FALSE == InsertServerGroupforMGame(szGroupName, nMGameServerID))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CIMGlobal::LoadConfiguration# Same ServerGroupName registered already !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			g_pGlobal->WriteSystemLogEX(TRUE, "	ServerGroup: %20s, Enable(%d) MGameServerID(%5d)\r\n", szGroupName, bEnableServerGroup, nMGameServerID);
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////
		// 2012-04-12 by jhseol, 아레나 추가개발 - 자동파티 : 아레나 서버인지 체크
		else if(stricmp(token, "ArenaServerFlag") == 0)
		{
			token = config.strtok(NULL, seps);
			if(NULL == token)
			{
				char	szError[1024];
				sprintf(szError, "[Error] Loading Configuration File Failed: ArenaServerLoading\r\n");
				this->WriteSystemLog(szError);
				DBGOUT(szError);
				continue;
			}
			
			if(0 == stricmp(token, "TRUE"))
			{
				m_bArenaIMServerCheck	= TRUE;
			}
			else if(0 == stricmp(token, "FALSE"))
			{
				m_bArenaIMServerCheck	= FALSE;
			}
		}
		// end 2012-04-12 by jhseol, 아레나 추가개발 - 자동파티 : 아레나 서버인지 체크
		else
		{
			// configuration file error!
			assert(0);
		}
	}
	fin.close();

	// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	this->ReLoad_AllowedToolIPList();
#endif
	// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신

	m_nMGameServerID1 = GetServerIDforMGame(GetServerGroupName());

	if(strcmp(this->GetIPLocal(), "") == 0
		|| strcmp(this->GetServerGroupName(), "") == 0
		|| strcmp(this->GetIPPreServer(), "") == 0
		|| this->GetPortPreServer() == 0)
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration() Loading Configuration Failed, LocalIP[%s] ServerGroupName[%s] PreServer[%s:%d]\r\n"
			, this->GetIPLocal(), this->GetServerGroupName(), this->GetIPPreServer(),
			this->GetPortPreServer());
		this->WriteSystemLog(szError);
		DBGOUT(szError);

		MessageBox(NULL, szError, "ERROR", MB_OK);
		return FALSE;
	}
	return m_Localization.LoadConfiguration((char*)LOCALIZATION_CONFIG_DIRECTORY_PATH, this->m_nLanguageType);
}

// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
BOOL CIMGlobal::ReLoadConfiguration(void)
{
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	const int SIZE_BUFF = 512;
	char		buff[SIZE_BUFF];
	char		buffBackup[SIZE_BUFF];
	const char	*token;
	char		seps[] = " \t";
	ifstream	fin;
	CConfig		config;
	
	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	if (!config.LoadUserDefinedVariables(IM_SERVER_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, IM_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	fin.open(IM_SERVER_CONFIG_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...
		
		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, IM_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	while(TRUE)
	{
		memset(buff, 0x00, SIZE_BUFF);
		BOOL bFlagFileEnd = fin.getline(buff, SIZE_BUFF).eof();
		if(bFlagFileEnd == TRUE
			&& strcmp(buff, "") == 0)
		{
			break;
		}
		
		STRNCPY_MEMSET(buffBackup, buff, SIZE_BUFF);
		
		token = strtok(buff, seps);
		
		if (token == NULL
			|| strncmp(token, "#", 1) == 0
			|| strncmp(token, "$", 1) == 0)
		{
			continue;
		}
		if(0 == stricmp(token, "AllowedToolIP"))
		{
			token = config.strtok(NULL, seps);			
			if (token == NULL)
			{
				continue;
			}
			this->AddAllowedToolIP(token);
		}
	}
	fin.close();

	this->ReLoad_AllowedToolIPList();
	return TRUE;
#else
	char	szError[1024];
	sprintf(szError, "[Error] No defined [S_ALLOWED_IP_RELOAD_JHSEOL] \r\n");
	this->WriteSystemLog(szError);
	return FALSE;
#endif
}
// end 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
