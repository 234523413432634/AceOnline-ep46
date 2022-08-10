// LogGlobal.cpp: implementation of the CLogGlobal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
// 2008-11-21 by cmkwon, LogServer�� MFC���� Win32 ������Ʈ�� ���� - 
//#include "LogServer.h"
#include "LogGlobal.h"
#include "LogIOCP.h"
#include "Config.h"

// 2008-11-21 by cmkwon, LogServer�� MFC���� Win32 ������Ʈ�� ���� - 
//#ifdef _DEBUG
//#undef THIS_FILE
//static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
//#endif

CLogGlobal *					g_pLogGlobal = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogGlobal::CLogGlobal()
{
	if(g_pLogGlobal)
	{
		return;
	}
	g_pLogGlobal		= this;

	MEMSET_ZERO(m_szGamePublisherName, SIZE_MAX_GAME_PUBLISHER_NAME);	// 2010-06-01 by shcho, GLogDB ���� -

	GLogExec.Clean();						// 2011-12-12 by hskim, GLog 2��
	m_bArenaFieldServerCheck = FALSE;		// 2011-12-12 by hskim, GLog 2��
}

CLogGlobal::~CLogGlobal()
{
	GLogExec.Clean();		// 2011-12-12 by hskim, GLog 2��

	EndServerSocket();

	g_pGlobalGameServer = NULL;
}


BOOL CLogGlobal::InitServerSocket(void)
{
	if(m_pGIOCP)
	{
		return FALSE;
	}

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CLogGlobal::InitServerSocket# Starting... \r\n");

	m_pGIOCP = new CLogIOCP(m_nPortListening, m_szIPLocal);
	if(m_pGIOCP->IOCPInit() == FALSE)
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] LogServer IOCPInit Error\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
		return FALSE;
	}

	CGlobalGameServer::InitServerSocket();

	// start 2011-12-12 by hskim, GLog 2��
#if defined(S_GLOG_2ND_HSKIM) || defined(S_GLOG_3ND_KHK)		// 2012-10-19 by jhseol, Glog 3�� ����
	if(FALSE == g_pLogGlobal->IsArenaServer())
	{
		// GLogExec.Init();		// GLOG �ڵ� ���� ���� 2013.1.17
	}
#endif
	// end 2011-12-12 by hskim, GLog 2��

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CLogGlobal::InitServerSocket# Started \r\n");

	return TRUE;
}

BOOL CLogGlobal::EndServerSocket(void)
{
	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - �Ʒ��� ���� ����
	this->WriteSystemLogEX(TRUE, "  [Notify] CLogGlobal::EndServerSocket# \r\n");

	CGlobalGameServer::EndServerSocket();

	return TRUE;
}


BOOL CLogGlobal::LoadConfiguration(void)
{
	SetConfigRootPath();

	DBGOUT("========================================\n");
	DBGOUT("Loading Server Informations...\n");

	const int SIZE_BUFF = 512;
	string configFileName = string(CONFIG_ROOT) + string("./log.cfg");
	char buff[SIZE_BUFF];
	char buffBackup[SIZE_BUFF];		// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	const char *token;
	char seps[] = " \t";

	/////////////////////////////////////////////
	// load MapWorkspace file...
	ifstream fin;
	CConfig config;

	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, GLOBAL_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	if (!config.LoadUserDefinedVariables(configFileName.c_str()))
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error1\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		return FALSE;
	}

	fin.open(configFileName.c_str());
	if (! fin.is_open())
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Can't open config file\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
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

		STRNCPY_MEMSET(buffBackup, buff, SIZE_BUFF);	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 

		token = config.strtok(buff, seps);

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
				STRNCPY_MEMSET((char*)m_szODBCDSN, token, SIZE_MAX_ODBC_CONN_STRING);
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
				STRNCPY_MEMSET((char*)m_szODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg ���Ͽ� DB ID/PWD ��ȣȭ - 
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
				STRNCPY_MEMSET((char*)m_szODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg ���Ͽ� DB ID/PWD ��ȣȭ - 
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
// 2008-09-24 by cmkwon, global.cfg ���� ���� - ServerGroupInfo �� ���� ��.
// 		else if(stricmp(token, "ServerGroup") == 0)
// 		{
// 			token = config.strtok(NULL, seps);
// 			if (token == NULL)
// 			{
// 				char	szSystemLog[256];
// 				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: ServerGroup\r\n");
// 				WriteSystemLog(szSystemLog);
// 				DBGOUT(szSystemLog);
// 				return FALSE;
// 			}
// 
// 			char szGroupName[SIZE_MAX_SERVER_NAME];
// 			MEMSET_ZERO(szGroupName, SIZE_MAX_SERVER_NAME);
// 			STRNCPY_MEMSET(szGroupName, token, SIZE_MAX_SERVER_NAME);
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
// 		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CLogGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_IP, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_PORT))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CLogGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_PORT, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			m_nDBServerPort = atoi(token);			
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_DATABASE_NAEE))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CLogGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_DATABASE_NAEE, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, "AllowedToolIP"))
		{// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
			
			token = config.strtok(NULL, seps);			
			if (token == NULL)
			{
				continue;
			}
			this->AddAllowedToolIP(token);
		}
		else if(stricmp(token, "ServerGroupInfo") == 0)
		{// 2008-09-24 by cmkwon, global.cfg ���� ���� - ServerGroup �� ������ ����
			
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
					g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CLogGlobal::LoadConfiguration# error !! %s\r\n", buffBackup);
					return FALSE;
				}
				continue;
			}
			
			if(SIZE_MAX_SERVER_NAME <= strlen(tokenList[0].c_str()))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CLogGlobal::LoadConfiguration# longer than max servergroupname !! %s\r\n", buffBackup);
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
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CLogGlobal::LoadConfiguration# smaller than min ServerGroupID !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			if (FALSE == InsertServerGroupforMGame(szGroupName, nMGameServerID))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CLogGlobal::LoadConfiguration# Same ServerGroupName registered already !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			g_pGlobal->WriteSystemLogEX(TRUE, "	ServerGroup: %20s, Enable(%d) MGameServerID(%5d)\r\n", szGroupName, bEnableServerGroup, nMGameServerID);
		}
		else if(0 == stricmp(token, "GamePublisher"))
		{	// 2010-06-01 by shcho, GLogDB ���� -
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szGamePublisherName, token, SIZE_MAX_GAME_PUBLISHER_NAME);
			}
		}
		// start 2011-12-12 by hskim, GLog 2��
		else if(0 == stricmp(token, "ArenaServerFlag"))
		{
			token = config.strtok(NULL, seps);
			if(NULL == token)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "Loading Configuration File Failed: ArenaServerLoading\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			
			if(0 == stricmp(token, "TRUE"))
			{
				m_bArenaFieldServerCheck	= TRUE;
			}
			else if(0 == stricmp(token, "FALSE"))
			{
				m_bArenaFieldServerCheck	= FALSE;
			}
		}
		// end 2011-12-12 by hskim, GLog 2��
		else
		{
			// configuration file error!
			assert(0);
		}
	}
	fin.close();
	
	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	this->ReLoad_AllowedToolIPList();
#endif
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	DBGOUT("========================================\n");
	
	m_nMGameServerID1 = GetServerIDforMGame(GetServerGroupName());
	return TRUE;
}

// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
BOOL CLogGlobal::ReLoadConfiguration(void)
{
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	const int SIZE_BUFF = 512;
	string configFileName = string(CONFIG_ROOT) + string("./log.cfg");
	char buff[SIZE_BUFF];
	char buffBackup[SIZE_BUFF];
	const char *token;
	char seps[] = " \t";
	
	ifstream fin;
	CConfig config;
	
	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, GLOBAL_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	if (!config.LoadUserDefinedVariables(configFileName.c_str()))
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error1\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		return FALSE;
	}
	
	fin.open(configFileName.c_str());
	if (! fin.is_open())
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Can't open config file\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
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
// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����

char *CLogGlobal::GetGamePublisherName(void)
{	// 2010-06-01 by shcho, GLogDB ���� -
	return m_szGamePublisherName;
}
