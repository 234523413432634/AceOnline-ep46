// PreGlobal.cpp: implementation of the CPreGlobal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreGlobal.h"
#include "PreIOCP.h"
#include "PreIOCPSocket.h"
#include "Config.h"
#include "AtumSJ.h"
#include "SPToMPWinSocket.h"		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
#include "SecurityManager.h"		// 2011-06-22 by hskim, �缳 ���� ����
#include "SelectiveShutdown.h"		// 2012-07-11 by hskim, ������ �˴ٿ�
#include "NPlayPCBangModule.h"		// 2012-10-05 by jhseol, NPlay pc�� ���

CPreGlobal *		g_pPreGlobal = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPreGlobal::CPreGlobal()
{
	if(g_pPreGlobal)
	{
		return;
	}

	g_pPreGlobal = this;
	m_pSecurityManager = NULL;		// 2011-06-22 by hskim, �缳 ���� ����
	m_pSelectiveShutdown = NULL;	// 2012-07-11 by hskim, ������ �˴ٿ�

	// 2012-10-05 by jhseolm NPlay PC�� ���
	m_pNPlayPCBangModule	= NULL;
	MEMSET_ZERO(m_szNPlayServerIP_Real, sizeof(m_szNPlayServerIP_Real));		// ���󼭹�
	MEMSET_ZERO(m_szNPlayServerIP_BackUP, sizeof(m_szNPlayServerIP_BackUP));	// �������
	m_nNPlayConectServer	= NPLAY_CONNECT_SERVER_EMPTY;
	// end 2012-10-05 by jhseolm NPlay PC�� ���

	// reset all member variables
	Reset();
}

CPreGlobal::~CPreGlobal()
{
	// reset all member variables
	Reset();

	g_pGlobalGameServer = NULL;
}

void CPreGlobal::Reset()
{
	m_vectorDownloadFTPIP.clear();
	m_nDownloadFTPPort = 0;
	memset(m_szDownloadFTPAccount, 0x00, SIZE_MAX_ACCOUNT_NAME);
	memset(m_szDownloadFTPPassword, 0x00, SIZE_MAX_PASSWORD);

	memset(m_szUploadFTPIP, 0x00, SIZE_MAX_FTP_URL);
	m_nUploadFTPPort = 0;
	memset(m_szUploadFTPAccount, 0x00, SIZE_MAX_ACCOUNT_NAME);
	memset(m_szUploadFTPPassword, 0x00, SIZE_MAX_PASSWORD);

	m_AllowedIPList.clear();
	m_AllowedAccounts.clear();
	m_bRandomFieldSelect			= FALSE;			// Pre Server
	m_bIgnoreClientVersionUpdate	= FALSE;

	// reset m_AllServerGroupVectorForLoading
	vector<CServerGroup*>::iterator itr = m_AllServerGroupVectorForLoading.begin();
	for (; itr != m_AllServerGroupVectorForLoading.end(); itr++)
	{
		SAFE_DELETE(*itr);
	}
	m_AllServerGroupVectorForLoading.clear();

	m_nServerGroupLimiteUserCount		= 999;				// 2006-10-11 by cmkwon

	m_vectGameServerGroupList.clear();						// 2007-05-02 by cmkwon

	m_bIsOnlyChoiceServer				= FALSE;			// 2007-07-06 by cmkwon, OnlyChoiceServer �÷��� ���� �߰�
	m_pSPToMPWinsoc						= NULL;				// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 

	MEMSET_ZERO(m_szGamePublisherName, SIZE_MAX_GAME_PUBLISHER_NAME);	// 2010-06-01 by shcho, GLogDB ���� -

	SAFE_DELETE(m_pSecurityManager);	// 2011-06-22 by hskim, �缳 ���� ����
	SAFE_DELETE(m_pSelectiveShutdown);	// 2012-07-11 by hskim, ������ �˴ٿ�
	SAFE_DELETE(m_pNPlayPCBangModule);	// 2012-10-05 by jhseolm NPlay PC�� ���
}

// start 2011-06-22 by hskim, �缳 ���� ����
BOOL CPreGlobal::InitGlobal(char * i_szServerName)
{
	if( FALSE == CGlobal::InitGlobal(i_szServerName) ) 
	{
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// start 2011-06-22 by hskim, �缳 ���� ����
	m_pSecurityManager = new CSecurityManager();
	
	if( FALSE == m_pSecurityManager->InitSecurityManager() ) 
	{ 
		g_pGlobal->WriteSystemLogEX(TRUE, "[ERROR] SecurityManager_Init fail !! \r\n");
		
		MessageBox(NULL, "SecurityManager fail !!", "ERROR - FieldServer", NULL);
		
		return FALSE; 
	}
	// end 2011-06-22 by hskim, �缳 ���� ����

	// 2012-07-11 by hskim, ������ �˴ٿ�
#if defined(S_SELECTIVE_SHUTDOWN_HSKIM)
	m_pSelectiveShutdown = new CSelectiveShutdown();
	
	if( FALSE == m_pSelectiveShutdown->Init() ) 
	{ 
		g_pGlobal->WriteSystemLogEX(TRUE, "[ERROR] SelectiveShutdown Init fail !! \r\n");
		
		MessageBox(NULL, "SelectiveShutdown Init fail !!", "ERROR - FieldServer", NULL);
		
		return FALSE; 
	}
#endif
	// end 2012-07-11 by hskim, ������ �˴ٿ�

	return TRUE;
}
// end 2011-06-22 by hskim, �缳 ���� ����

//////////////////////////////////////////////////////////////////////
// Property
//////////////////////////////////////////////////////////////////////
void CPreGlobal::SetUploadFTPIP(char *i_szIP)
{
	STRNCPY_MEMSET(m_szUploadFTPIP, i_szIP, SIZE_MAX_FTP_URL);
}

char* CPreGlobal::GetUploadFTPIP(void)
{
	return m_szUploadFTPIP;
}

void CPreGlobal::SetUploadFTPPort(int i_nPort)
{
	m_nUploadFTPPort = i_nPort;
}

int CPreGlobal::GetUploadFTPPort(void)
{
	return m_nUploadFTPPort;
}

void CPreGlobal::SetUploadFTPAccount(char * i_szAccount)
{
	STRNCPY_MEMSET(m_szUploadFTPAccount, i_szAccount, SIZE_MAX_ACCOUNT_NAME);
}

char* CPreGlobal::GetUploadFTPAccount(void)
{
	return m_szUploadFTPAccount;
}

void CPreGlobal::SetUploadFTPPassword(char * i_szPassword)
{
	STRNCPY_MEMSET(m_szUploadFTPPassword, i_szPassword, SIZE_MAX_PASSWORD);
}

char* CPreGlobal::GetUploadFTPPassword(void)
{
	return m_szUploadFTPPassword;
}

void CPreGlobal::SetDownloadFTPPort(int i_nPort)
{
	m_nDownloadFTPPort = i_nPort;
}

int CPreGlobal::GetDownloadFTPPort(void)
{
	return m_nDownloadFTPPort;
}

void CPreGlobal::SetDownloadFTPAccount(char * i_szAccount)
{
	STRNCPY_MEMSET(m_szDownloadFTPAccount, i_szAccount, SIZE_MAX_ACCOUNT_NAME);
}

char* CPreGlobal::GetDownloadFTPAccount(void)
{
	return m_szDownloadFTPAccount;
}

void CPreGlobal::SetDownloadFTPPassword(char * i_szPassword)
{
	STRNCPY_MEMSET(m_szDownloadFTPPassword, i_szPassword, SIZE_MAX_PASSWORD);
}

char* CPreGlobal::GetDownloadFTPPassword(void)
{
	return m_szDownloadFTPPassword;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CPreGlobal::AddDownloadHttpIP(const char * i_szIP)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CPreGlobal::AddDownloadHttpIP(const char * i_szIP)
{
	m_vectDownloadHttpServer.push_back(i_szIP);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char * CPreGlobal::GetRandomDownloadHttpIP(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
const char * CPreGlobal::GetRandomDownloadHttpIP(void)
{
	if (m_vectDownloadHttpServer.size() <= 0)
	{
		return NULL;
	}
	else if (m_vectDownloadHttpServer.size() == 1)
	{
		return m_vectDownloadHttpServer[0].c_str();
	}

	int idx = RANDI(0, m_vectDownloadHttpServer.size() - 1);

	return m_vectDownloadHttpServer[idx].c_str();
}


void CPreGlobal::AddDownloadFTPIP(char * i_szIP)
{
	m_vectorDownloadFTPIP.push_back(i_szIP);
}

const char* CPreGlobal::GetRandomDownloadFTPIP(void)
{
	if (m_vectorDownloadFTPIP.size() <= 0)
	{
		return NULL;
	}
	else if (m_vectorDownloadFTPIP.size() == 1)
	{
		return m_vectorDownloadFTPIP[0].c_str();
	}

	int idx = RANDI(0, m_vectorDownloadFTPIP.size() - 1);

	return m_vectorDownloadFTPIP[idx].c_str();
}

VersionInfo CPreGlobal::GetClientReinstallVersion(void)
{
	return m_ClientReinstallVersion;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int		CPreGlobal::GetAutoUpdateServerType(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int		CPreGlobal::GetAutoUpdateServerType(void)
{
	return m_nAutoUpdateServerType;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			const char *	CPreGlobal::GetDownloadServerIP(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
const char *	CPreGlobal::GetDownloadServerIP(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return GetRandomDownloadHttpIP();
		}
	}
	return GetRandomDownloadFTPIP();
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int	CPreGlobal::GetDownloadServerPort(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int	CPreGlobal::GetDownloadServerPort(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_nDownloadHttpServerPort;
		}
	}
	return m_nDownloadFTPPort;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetDownloadServerAccountName(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetDownloadServerAccountName(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szDownloadHttpServerAccountName;
		}
	}
	return m_szDownloadFTPAccount;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetDownloadServerPassword(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetDownloadServerPassword(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szDownloadHttpServerPassword;
		}
	}
	return m_szDownloadFTPPassword;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetClientUpdateDownloadDir(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetClientUpdateDownloadDir(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szClientHttpUpdateDownloadDir;
		}
	}
	return m_szClientFTPUpdateDownloadDir;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetLauncherFileDownloadPath(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetLauncherFileDownloadPath(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szLauncherFileDownloadHttpPath;
		}
	}
	return m_szLauncherFileDownloadPath;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetDeleteFileListDownloadPath(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetDeleteFileListDownloadPath(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szDeleteFileListDownloadHttpPath;
		}
	}
	return m_szDeleteFileListDownloadPath;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *	CPreGlobal::GetNoticeFileDownloadPath(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *	CPreGlobal::GetNoticeFileDownloadPath(void)
{
	switch(GetAutoUpdateServerType())
	{
	case AU_SERVER_TYPE_HTTP:
		{
			return m_szNoticeFileDownloadHttpPath;
		}
	}

	return m_szNoticeFileDownloadPath;
}




//////////////////////////////////////////////////////////////////////
// Method
//////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::CheckAllowedList(CServerGroup *i_pGroupInfo, char * i_szAccountName, char * i_szPrivateIP, USHORT i_nAccountType)
{	
	if (m_AllowedAccounts.empty())
	{// 2007-10-19 by cmkwon, �㰡 ���� ����Ʈ�� ��� �ִٸ� ��� ���� ���
		return TRUE;
	}

	if (m_AllowedAccounts.find(i_szAccountName) != m_AllowedAccounts.end())
	{// 2007-10-19 by cmkwon, �㰡 ���� ����Ʈ�� �ִ��� üũ
		return TRUE;
	}

	if (COMPARE_RACE(i_nAccountType, RACE_OPERATION|RACE_GAMEMASTER))
	{// 2007-10-19 by cmkwon, ������,��� ���� üũ
		this->WriteSystemLogEX(TRUE, STRMSG_S_P2PRENOTIFY_0000, CAtumSJ::GetRaceString(i_nAccountType), i_szAccountName, i_szPrivateIP);
		return TRUE;
	}

	return FALSE;

// 2007-10-19 by cmkwon, AllowedIP �ý��� ���� - ���� ���� IP üũ�� ���⿡�� ���� ����
////	// atumdemo, ���� ������ ������ ����
////	if (strncmp(i_szAccountName, "spacetest", strlen("spacetest")) == 0)
////	{
////		DBGOUT("�ÿ��� ����(%s)���� �����Ͽ����ϴ�. IP: %s\r\n", i_szAccountName, i_szPrivateIP);
////		return TRUE;
////	}
//
//	if (COMPARE_RACE(i_nAccountType, RACE_OPERATION|RACE_GAMEMASTER|RACE_DEMO|RACE_MONITOR|RACE_GUEST))
//	{
//		DBGOUT(STRMSG_S_P2PRENOTIFY_0000, CAtumSJ::GetRaceString(i_nAccountType), i_szAccountName, i_szPrivateIP);
//		return TRUE;
//	}
//	if (m_AllowedAccounts.empty() 
//		&& m_AllowedIPList.empty())
//	{
//		if(FALSE == i_pGroupInfo->m_bEnableServerGroup
//			&& IS_SCADMINTOOL_CONNECTABLE_IP(i_szPrivateIP))
//		{
//			return FALSE;
//		}
//		return TRUE;
//	}
//
//	if (m_AllowedAccounts.empty() == FALSE
//		&& m_AllowedAccounts.find(i_szAccountName) != m_AllowedAccounts.end())
//	{
//		return TRUE;
//	}
//
//	if (m_AllowedIPList.empty() == FALSE)
//	{
//		for (int i = 0; i < m_AllowedIPList.size(); i++)
//		{
//			if (strncmp(m_AllowedIPList[i].c_str(), i_szPrivateIP, strlen(m_AllowedIPList[i].c_str())) == 0)
//			{
//				return TRUE;
//			}
//		}
//	}
}

void CPreGlobal::PrintAllowedList(void)
{
	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	int LastVersion = m_AllowedIPList_ReloadVersion.size();
	if ( 0 < LastVersion )
	{
		vector<string>	tmAllowedIPList = m_AllowedIPList_ReloadVersion[LastVersion-1];
		for (vector<string>::iterator itr2 = tmAllowedIPList.begin(); itr2 != tmAllowedIPList.end(); itr2++)
		{
			DBGOUT("  AllowedIP: \'%s\'\r\n", itr2->c_str());
		}
	}
#else
	for (vector<string>::iterator itr2 = m_AllowedIPList.begin(); itr2 != m_AllowedIPList.end(); itr2++)
	{
		DBGOUT("  AllowedIP: \'%s\'\r\n", itr2->c_str());
	}
#endif
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	for (set<string>::iterator itr3 = m_AllowedAccounts.begin(); itr3 != m_AllowedAccounts.end(); itr3++)
	{
		DBGOUT("  AllowedAccount: \'%s\'\r\n", itr3->c_str());
	}
	DBGOUT("\n");
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::CheckAllowedIP(char *i_szPublicIP)
/// \brief		// 2007-10-19 by cmkwon, AllowedIP �ý��� ���� - �㰡 IP üũ �Լ�
/// \author		cmkwon
/// \date		2007-10-19 ~ 2007-10-19
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::CheckAllowedIP(char *i_szPublicIP)
{
	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	int LastVersion = m_AllowedIPList_ReloadVersion.size();
	if ( 0 < LastVersion )
	{
		vector<string>	tmAllowedIPList = m_AllowedIPList_ReloadVersion[LastVersion-1];
		for (int i = 0; i < tmAllowedIPList.size(); i++)
		{
			if (0 == strncmp(tmAllowedIPList[i].c_str(), i_szPublicIP, strlen(tmAllowedIPList[i].c_str())))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] Allowed IP(%s)\r\n", i_szPublicIP);
				return TRUE;
			}
		}
	}
	else
	{
		return TRUE;
	}
#else
	if (m_AllowedIPList.empty())
	{// 2007-10-19 by cmkwon, �㰡 IP ����Ʈ�� ���ٸ� ��� ���� ��� ������
		return TRUE;
	}

	for (int i = 0; i < m_AllowedIPList.size(); i++)
	{
		if (0 == strncmp(m_AllowedIPList[i].c_str(), i_szPublicIP, strlen(m_AllowedIPList[i].c_str())))
		{
			// 2008-01-31 by cmkwon, �ý��� �α� �߰�
			g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Notify] Allowed IP(%s)\r\n", i_szPublicIP);
			return TRUE;
		}
	}
#endif
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����

	// 2008-01-31 by cmkwon, �ý��� �α� �߰�
	g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Notify] Not Allowed IP(%s)\r\n", i_szPublicIP);
	return FALSE;
}

BOOL CPreGlobal::InitServerSocket(void)
{
	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - �Ʒ��� ���� ����
	//g_pPreGlobal->WriteSystemLogEX(TRUE, "Starting PreServer... \r\n");

	if(NULL != m_pGIOCP){		return FALSE;}

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CPreGlobal::InitServerSocket# Starting... \r\n");

	m_pGIOCP = new CPreIOCP(m_nPortListening, m_szIPLocal);
	if(m_pGIOCP->IOCPInit() == FALSE)
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] PreServer IOCPInit Error\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
		return FALSE;
	}

	CGlobalGameServer::InitServerSocket();

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CPreGlobal::InitServerSocket# Started \r\n");

	return TRUE;
}

BOOL CPreGlobal::EndServerSocket(void)
{
	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CPreGlobal::EndServerSocket# \r\n");

	CGlobalGameServer::EndServerSocket();


	return TRUE;
}

BOOL CPreGlobal::LoadConfiguration(void)
{
	// set config root path
	this->SetConfigRootPath();

	///////////////////////////////////////////////////////////////////////////////
	// MGameEvent�� ���� AccountName/CharacterName�� �ε��Ѵ�
	LoadAccountNameAndCharacterNameForMGameEvent();

	DBGOUT("========================================\n");
	DBGOUT("Loading Server Informations...\n");

	const int SIZE_BUFF = 512;
	string configFileName = string(CONFIG_ROOT) + string("pre.cfg");
	char buff[SIZE_BUFF];
	char buffBackup[SIZE_BUFF];		// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	const char *token;
	char seps[] = " \t";
	char seps_servergroup[] = ".";

	//char tmpIP[SIZE_MAX_IPADDRESS];
	//int	 tmpPort;

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
		
		STRNCPY_MEMSET(buffBackup, buff, SIZE_BUFF);		// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 

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
			this->SetIPLocal((char*)token);
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
// 2008-09-01 by cmkwon, ���� �̹� ���� �Ǿ� ����
// 		else if(stricmp(token, "ODBCUID") == 0)
// 		{
// 			token = config.strtok(NULL, seps);
// 			if (token == NULL)
// 			{
// 				char *msg = "Loading Configuration File Failed. ODBCUID\n";
// 				DBGOUT(msg);
// 				MessageBox(NULL, msg, "Error", MB_OK);
// 				return FALSE;
// 			}
// 			if(strcmp(token, "") != 0)
// 			{
// 				STRNCPY_MEMSET((char*)m_szODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
// 			}
// 		}
// 		else if(stricmp(token, "ODBCPASSWD") == 0)
// 		{
// 			token = config.strtok(NULL, seps);
// 			if (token == NULL)
// 			{
// 				char *msg = "Loading Configuration File Failed. ODBCPASSWD\n";
// 				DBGOUT(msg);
// 				MessageBox(NULL, msg, "Error", MB_OK);
// 				return FALSE;
// 			}
// 			if(strcmp(token, "") != 0)
// 			{
// 				STRNCPY_MEMSET((char*)m_szODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
// 			}
// 		}
		else if(0 == stricmp(token, "ServerGroupLimiteUserCount"))
		{// 2006-10-11 by cmkwon, �������� �ִ� ���� ������

			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadConfiguration Initialization Error2!!, FieldName: ServerGroupMaxUserCount\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			m_nServerGroupLimiteUserCount = atoi(token);
			if(0 >= m_nServerGroupLimiteUserCount)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadConfiguration ServerGroupLimiteUserCount Error!!, ServerGroupLimiteUserCount(%d)\r\n", m_nServerGroupLimiteUserCount);
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
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
// 			else if(SIZE_MAX_SERVER_NAME <= strlen(token))
// 			{// 2006-02-24 by cmkwon,
// 				char	szSystemLog[256];
// 				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers error, ServerGroupName size overflow\r\n");
// 				WriteSystemLog(szSystemLog);
// 				DBGOUT(szSystemLog);
// 				return FALSE;
// 			}
// 
// 			char	szGroupName[SIZE_MAX_SERVER_NAME];
// 			STRNCPY_MEMSET(szGroupName, token, SIZE_MAX_SERVER_NAME);			
// 			token = config.strtok(NULL, seps);
// 			if(NULL == token)
// 			{
// 				return FALSE;
// 			}
// 			
// 			BOOL	bEnableServerGroup	= TRUE;
// 			if( 0 == stricmp(token, "TRUE"))
// 			{
// 				bEnableServerGroup	= TRUE;
// 			}
// 			else
// 			{
// 				bEnableServerGroup	= FALSE;
// 			}
// 
// 			int		nMGameServerID		= 10061;
// 			token = config.strtok(NULL, seps);
// 			if(NULL == token)
// 			{
// 				return FALSE;
// 			}
// 			nMGameServerID = atoi(token);
// 
// 			CServerGroup *pServerGroup = GetServerGroupForLoading(szGroupName);
// 			if ( pServerGroup == NULL )
// 			{
// 				pServerGroup = new CServerGroup;
// 				STRNCPY_MEMSET(pServerGroup->m_ServerGroupName, szGroupName, SIZE_MAX_SERVER_NAME);
// 				pServerGroup->m_LimitGroupUserCounts	= m_nServerGroupLimiteUserCount;	// Default Limit User Count
// 				pServerGroup->m_bEnableServerGroup		= bEnableServerGroup;
// 				pServerGroup->m_nMGameServerID			= nMGameServerID;
// 				m_AllServerGroupVectorForLoading.push_back(pServerGroup);
// 
// 				DBGOUT("	ServerGroup: %20s, Enable(%d) MGameServerID(%5d)\n", szGroupName, bEnableServerGroup, nMGameServerID);
// 			}
// 			else
// 			{
// 				continue;
// 			}
// 		}
		// 2007-12-22 by dhjin, �Ʒ��� ���� - �Ʒ��� ���� ������ ServerGroup�� �߰�
		else if(stricmp(token, "ArenaServer") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadArenaServer Config Initialization Error\r\n");
				WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			else if(SIZE_MAX_SERVER_NAME <= strlen(token))
			{// 2006-02-24 by cmkwon,
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadArenaServer error, ArenaServerName size overflow\r\n");
				WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			char	szGroupName[SIZE_MAX_SERVER_NAME];
			STRNCPY_MEMSET(szGroupName, token, SIZE_MAX_SERVER_NAME);			
			token = config.strtok(NULL, seps);
			if(NULL == token)
			{
				return FALSE;
			}
			int		nMGameServerID = atoi(token);
			
			BOOL	bEnableServerGroup	= TRUE;

			CServerGroup *pServerGroup = GetServerGroupForLoading(szGroupName);
			if ( pServerGroup == NULL )
			{
				pServerGroup = new CServerGroup;
				STRNCPY_MEMSET(pServerGroup->m_ServerGroupName, szGroupName, SIZE_MAX_SERVER_NAME);
				pServerGroup->m_LimitGroupUserCounts	= m_nServerGroupLimiteUserCount;	// Default Limit User Count
				pServerGroup->m_bEnableServerGroup		= bEnableServerGroup;
				pServerGroup->m_nMGameServerID			= nMGameServerID;
				m_AllServerGroupVectorForLoading.push_back(pServerGroup);

				DBGOUT("ArenaServer: %20s, Enable(%d) MGameServerID(%5d)\n", szGroupName, bEnableServerGroup, nMGameServerID);
			}
			else
			{
				continue;
			}
		}// 2007-12-22 by dhjin, �Ʒ��� ���� - �Ʒ��� ���� ������ ServerGroup�� �߰�
		else if(stricmp(token, "UploadFtpServerIP") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: UploadFtpServerIP\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->SetUploadFTPIP((char*)token);
		}
		else if(stricmp(token, "UploadFtpServerPort") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: UploadFtpServerPort\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->SetUploadFTPPort(atoi(token));
		}
		else if(stricmp(token, "UploadFTPServerAccount") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: UploadFTPServerAccount\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			this->SetUploadFTPAccount((char*)token);
		}
		else if(stricmp(token, "UploadFTPServerPassword") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: UploadFTPServerPassword\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->SetUploadFTPPassword((char*)token);
		}
		else if(stricmp(token, "DownloadFTPServerIP") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DownloadFTPServerIP\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->AddDownloadFTPIP((char*)token);
		}
		else if(stricmp(token, "DownloadFTPServerPort") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DownloadFTPServerPort\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->SetDownloadFTPPort(atoi(token));
		}
		else if(stricmp(token, "DownloadFTPServerAccount") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DownloadFTPServerAccount\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			this->SetDownloadFTPAccount((char*)token);
		}
		else if(stricmp(token, "DownloadFTPServerPassword") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DownloadFTPServerPassword\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			this->SetDownloadFTPPassword((char*)token);
		}
		else if(stricmp(token, "ClientFTPUpdateUploadDir") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: ClientFTPUpdateUploadDir\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szClientFTPUpdateUploadDir, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "ClientFTPUpdateDownloadDir") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: ClientFTPUpdateDownloadDir\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szClientFTPUpdateDownloadDir, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "LauncherFileUploadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: LauncherFileUploadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szLauncherFileUploadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "LauncherFileDownloadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: LauncherFileDownloadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szLauncherFileDownloadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "DeleteFileListUploadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DeleteFileListUploadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szDeleteFileListUploadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "DeleteFileListDownloadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: DeleteFileListDownloadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szDeleteFileListDownloadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "NoticeFileUploadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: NoticeFileUploadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szNoticeFileUploadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "NoticeFileDownloadPath") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: NoticeFileDownloadPath\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			STRNCPY_MEMSET(this->m_szNoticeFileDownloadPath, (char*)token, SIZE_MAX_FTP_FILE_PATH);
		}
		else if(stricmp(token, "ClientReInstallVersion") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: ClientReInstallVersion\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			m_ClientReinstallVersion.SetVersion((char*)token);
		}
		else if(stricmp(token, "CriticalUpdateVersion") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: CriticalUpdateVersion\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			VersionInfo tmpCriticalVersion;
			tmpCriticalVersion.SetVersion((char*)token);
			m_vectorCriticalUpdateVersion.push_back(tmpCriticalVersion);
		}
		else if (stricmp(token, "AllowedIP") == 0)
		{
			token = config.strtok(NULL, seps);

// 2008-09-24 by cmkwon, global.cfg ���� ���� - 
//			if (token == NULL)
//			{
//				char	szSystemLog[256];
//				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: AllowedIP\r\n");
//				this->WriteSystemLog(szSystemLog);
//				DBGOUT(szSystemLog);
//				return FALSE;
//			}
			if(NULL == token
				|| 0 == stricmp(token, ""))
			{// 2008-09-24 by cmkwon, global.cfg ���� ���� - ������ IP�� ����� ���� ó������ �ʰ� �׳� continue ó���Ѵ�.
				continue;
			}

			m_AllowedIPList.push_back(token);
			// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
			this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedIP Add (%s)\r\n", token);
#endif
			// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
		}
		else if (stricmp(token, "AllowedAccount") == 0)
		{
			token = config.strtok(NULL, seps);

// 2008-09-24 by cmkwon, global.cfg ���� ���� - 
//			if (token == NULL)
//			{
//				char	szSystemLog[256];
//				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: AllowedAccount\r\n");
//				this->WriteSystemLog(szSystemLog);
//				DBGOUT(szSystemLog);
//				return FALSE;
//			}
			if(NULL == token
				|| 0 == stricmp(token, ""))
			{// 2008-09-24 by cmkwon, global.cfg ���� ���� - ������ AccountName�� ��� ���� ó������ �ʰ� �׳� continue ó���Ѵ�.
				continue;
			}
			_strlwr((char*)token);
			m_AllowedAccounts.insert(token);
			// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
			this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedAccount Add (%s)\r\n", token);
#endif
			// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
		}
		else if (stricmp(token, "RandomFieldSelect") == 0)
		{
			token = config.strtok(NULL, seps);

			if (token == NULL || (stricmp(token, "TRUE") != 0 && stricmp(token, "FALSE") != 0))
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: RandomFieldSelect\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			if (stricmp(token, "TRUE") == 0)
			{
				m_bRandomFieldSelect = TRUE;
			}
			else if (stricmp(token, "FALSE") == 0)
			{
				m_bRandomFieldSelect = FALSE;
			}
			else
			{
				// unreachable
				return FALSE;
			}
		}
		else if (stricmp(token, "IgnoreClientVersionUpdate") == 0)
		{
			token = config.strtok(NULL, seps);

			if (token == NULL || (stricmp(token, "TRUE") != 0 && stricmp(token, "FALSE") != 0))
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CPreIOCP::LoadAllServers Config Initialization Error2: RandomFieldSelect\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			if (stricmp(token, "TRUE") == 0)
			{
				m_bIgnoreClientVersionUpdate = TRUE;
			}
			else if (stricmp(token, "FALSE") == 0)
			{
				m_bIgnoreClientVersionUpdate = FALSE;
			}
			else
			{
				// unreachable
				return FALSE;
			}
		}
		else if(0 == stricmp(token, "IsTestServer"))
		{
			token = config.strtok(NULL, seps);
			if(token == NULL)
			{
				m_bIsTestServer = FALSE;
			}
			else
			{
				if (stricmp(token, "FALSE") == 0)
				{
					m_bIsTestServer = FALSE;
				}
				else
				{
					m_bIsTestServer = TRUE;
				}
			}
		}
		else if(0 == stricmp(token, "IsOnlyChoiceServer"))
		{// 2007-07-06 by cmkwon, IsOnlyChoiceServer �÷��� ���� �߰�

			m_bIsOnlyChoiceServer		= FALSE;		// �⺻��
			token = config.strtok(NULL, seps);
			if(token
				&& 0 == stricmp(token, "TRUE"))
			{
				m_bIsOnlyChoiceServer = TRUE;
			}			
		}
		else if(0 == stricmp(token, "IsExternalAuthentication"))
		{// 2006-04-27 by cmkwon, �ܺ� DB ���� �÷���

			m_bIsExternalAuthentication	= FALSE;
			token = config.strtok(NULL, seps);
			if(token
				&& 0 == stricmp(token, "TRUE"))
			{
				m_bIsExternalAuthentication	= TRUE;
			}
		}
		else if(0 == stricmp(token, "ExtAuthODBCDSN"))
		{// 2006-04-27 by cmkwon, �ܺ� ���� DB ����

			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET((char*)m_szExtAuthODBCDSN, token, SIZE_MAX_ODBC_CONN_STRING);
			}
		}
		else if(0 == stricmp(token, "ExtAuthODBCUID"))
		{// 2006-04-27 by cmkwon, �ܺ� ���� DB ����

			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET((char*)m_szExtAuthODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg ���Ͽ� DB ID/PWD ��ȣȭ - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szExtAuthODBCUID, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szExtAuthODBCUID, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(0 == stricmp(token, "ExtAuthODBCPASSWD"))
		{// 2006-04-27 by cmkwon, �ܺ� ���� DB ����

			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET((char*)m_szExtAuthODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg ���Ͽ� DB ID/PWD ��ȣȭ - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szExtAuthODBCPASSWORD, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szExtAuthODBCPASSWORD, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
#ifdef SC_CHANNELING_JHSEOL_BCKIM_SSJUNG	// - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
		else if(0 == stricmp(token, CONFIG_NAME_IS_EXTERNAL_USER_INFO))
		{
			m_bIsExternalUserInfo	= FALSE;
			token = config.strtok(NULL, seps);
			if(token)
			{
				if( 0 == stricmp(token, "TRUE"))	{	m_bIsExternalUserInfo	= TRUE;	}
			}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_USER_INFO_ODBC_UID))
		{
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET((char*)m_szExtUserInfoODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szExtUserInfoODBCUID, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szExtUserInfoODBCUID, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
			else	{	STRNCPY_MEMSET((char*)m_szExtUserInfoODBCUID, "1", SIZE_MAX_ODBC_CONN_STRING);	}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_USER_INFO_ODBC_PASSWD))
		{
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET((char*)m_szExtUserInfoODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szExtUserInfoODBCPASSWORD, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szExtUserInfoODBCPASSWORD, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
			else	{	STRNCPY_MEMSET((char*)m_szExtUserInfoODBCPASSWORD, "1", SIZE_MAX_ODBC_CONN_STRING);	}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_USER_INFO_DB_SERVER_IP))
		{
			token = config.strtok(NULL, seps);
			if (token)	{	STRNCPY_MEMSET(m_szExtUserInfoDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);	}
			else	{	STRNCPY_MEMSET((char*)m_szExtUserInfoDBServerIP, "1", SIZE_MAX_ODBC_CONN_STRING);	}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_USER_INFO_DB_SERVER_PORT))
		{
			token = config.strtok(NULL, seps);
			if (token)	{	m_nExtUserInfoDBServerPort = atoi(token);	}
			else	{	m_nExtUserInfoDBServerPort = 1;	}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_USER_INFO_DB_SERVER_DATABASE_NAME))
		{
			token = config.strtok(NULL, seps);
			if (token)	{	STRNCPY_MEMSET(m_szExtUserInfoDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);	}
			else	{	STRNCPY_MEMSET((char*)m_szExtUserInfoDBServerDatabaseName, "1", SIZE_MAX_ODBC_CONN_STRING);	}
		}
#endif	// #ifdef SC_CHANNELING_JHSEOL_BCKIM_SSJUNG
		// end 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(0 == stricmp(token, "AutoUpdateServerType"))
		{// 2007-01-06 by cmkwon, 

			m_nAutoUpdateServerType			= AU_SERVER_TYPE_FTP;		// 2007-01-06 by cmkwon, default
			token = config.strtok(NULL, seps);
			if(token
				&& 0 == stricmp(token, "HTTP"))
			{
				m_nAutoUpdateServerType		= AU_SERVER_TYPE_HTTP;
			}			
		}
		else if(0 == stricmp(token, "DownloadHttpServerIP"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				AddDownloadHttpIP(token);
			}
		}
		else if(0 == stricmp(token, "DownloadHttpServerPort"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				m_nDownloadHttpServerPort	= atoi(token);
			}
		}
		else if(0 == stricmp(token, "DownloadHttpServerAccount"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szDownloadHttpServerAccountName, token, SIZE_MAX_ACCOUNT_NAME);
			}
		}
		else if(0 == stricmp(token, "DownloadHttpServerPassword"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szDownloadHttpServerPassword, token, SIZE_MAX_PASSWORD);
			}
		}
		else if(0 == stricmp(token, "ClientUpdateDownloadHttpDir"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szClientHttpUpdateDownloadDir, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(0 == stricmp(token, "LauncherFileDownloadHttpPath"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szLauncherFileDownloadHttpPath, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(0 == stricmp(token, "DeleteFileListDownloadHttpPath"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szDeleteFileListDownloadHttpPath, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(0 == stricmp(token, "NoticeFileDownloadHttpPath"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szNoticeFileDownloadHttpPath, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(0 == stricmp(token, "VersionListFileUploadPath"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szVersionListFileUploadPath, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(0 == stricmp(token, "VersionListFileDownloadHttpPath"))
		{// 2007-01-06 by cmkwon, 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szVersionListFileDownloadHttpPath, token, SIZE_MAX_FTP_FILE_PATH);
			}
		}
		else if(stricmp(token, "GameServerGroup") == 0)
		{// 2007-05-02 by cmkwon
			
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
				continue;
			}

			InsertGameServerGroup((char*)tokenList[0].c_str(), (char*)tokenList[1].c_str(), atoi(tokenList[2].c_str()));
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CPreGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_IP, buffBackup);
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
				sprintf(szErr, "[ERROR] CPreGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_PORT, buffBackup);
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
				sprintf(szErr, "[ERROR] CPreGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_DATABASE_NAEE, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_AUTH_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (token)
			{
				STRNCPY_MEMSET(m_szExtAuthDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
			}			
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_AUTH_DB_SERVER_PORT))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (token)
			{
				m_nExtAuthDBServerPort = atoi(token);
			}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_AUTH_DB_SERVER_DATABASE_NAEE))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (token)
			{
				STRNCPY_MEMSET(m_szExtAuthDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
			}			
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
					g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CPreIOCP::LoadAllServers# error !! %s\r\n", buffBackup);
					return FALSE;
				}
				continue;
			}

			if(SIZE_MAX_SERVER_NAME <= strlen(tokenList[0].c_str()))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CPreIOCP::LoadAllServers# longer than max servergroupname !! %s\r\n", buffBackup);
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
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CPreIOCP::LoadAllServers# smaller than min ServerGroupID !! %s\r\n", buffBackup);
				return FALSE;
			}

			CServerGroup *pServerGroup = GetServerGroupForLoading(szGroupName);
			if (pServerGroup)
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CPreIOCP::LoadAllServers# Same ServerGroupName registered already !! %s\r\n", buffBackup);
				return FALSE;
			}
			pServerGroup = new CServerGroup;
			STRNCPY_MEMSET(pServerGroup->m_ServerGroupName, szGroupName, SIZE_MAX_SERVER_NAME);
			pServerGroup->m_LimitGroupUserCounts	= m_nServerGroupLimiteUserCount;	// Default Limit User Count
			pServerGroup->m_bEnableServerGroup		= bEnableServerGroup;
			pServerGroup->m_nMGameServerID			= nMGameServerID;
			m_AllServerGroupVectorForLoading.push_back(pServerGroup);
				
			g_pGlobal->WriteSystemLogEX(TRUE, "	ServerGroup: %20s, Enable(%d) MGameServerID(%5d)\r\n", szGroupName, bEnableServerGroup, nMGameServerID);
		}
		
		// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �÷��� �߰�
		else if(0 == stricmp(token, "IsExtAuthSOAP"))
		{ // ��� ���� �÷��� �� ��������		
			m_IsSOAPUse	= FALSE;
			token = config.strtok(NULL, seps);
			if(token
				&& 0 == stricmp(token, "TRUE"))
			{
				m_IsSOAPUse	= TRUE;
			}
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_AUTH_SOAP_URL))
		{ // URL ��������
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CPreGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_EXT_AUTH_SOAP_URL, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			if(token)
			{
				STRNCPY_MEMSET(m_szSOAPUrlString, token, SIZE_MAX_ODBC_CONN_STRING);
			}			
		}
		else if(0 == stricmp(token, CONFIG_NAME_EXT_AUTH_SOAP_GAMEID))
		{ // URL���� üũ�� �ش� ���� ID ��������
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CPreGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_EXT_AUTH_SOAP_GAMEID, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			if (token)
			{
				STRNCPY_MEMSET(m_szSOAPGameID, token, SIZE_MAX_GAME_ID);
			}			
		}
		// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��
		else if(0 == stricmp(token, "GamePublisher"))
		{	// 2010-06-01 by shcho, GLogDB ���� -
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szGamePublisherName, token, SIZE_MAX_GAME_PUBLISHER_NAME);
			}
		}
		// start 2011-12-12 by hskim, GLog 2��
		else if(stricmp(token, "ServerGroupName") == 0)
		{
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetServerGroupName((char*)token);
			}
		}
		// end 2011-12-12 by hskim, GLog 2��
		// 2012-10-05 by jhseol, NPlay pc�� ��� - NPlay ���� IP
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
		else if(stricmp(token, "NPlayServerIPReal") == 0)
		{
			token = config.strtok(NULL, seps);

			// 2012-10-26 by hskim, Global.cfg �� �ش� �׸��� ���°�� ���ߴ� ���� ����
			if (NULL == token)
			{
				continue;	
			}
			// end 2012-10-26 by hskim, Global.cfg �� �ش� �׸��� ���°�� ���ߴ� ���� ����

			if(strcmp(token, "") != 0)
			{
				STRNCPY_MEMSET(m_szNPlayServerIP_Real, token, SIZE_MAX_IPADDRESS);
			}
		}
		else if(stricmp(token, "NPlayServerIPBackUP") == 0)
		{
			token = config.strtok(NULL, seps);

			// 2012-10-26 by hskim, Global.cfg �� �ش� �׸��� ���°�� ���ߴ� ���� ����
			if (NULL == token)
			{
				continue;	
			}
			// end 2012-10-26 by hskim, Global.cfg �� �ش� �׸��� ���°�� ���ߴ� ���� ����

			if(strcmp(token, "") != 0)
			{
				STRNCPY_MEMSET(m_szNPlayServerIP_BackUP, token, SIZE_MAX_IPADDRESS);
			}
		}
#endif
		// 2012-10-05 by jhseol, NPlay pc�� ��� - NPlay ���� IP
		else
		{
			// configuration file error!
			return FALSE;
		}
	}

	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	if ( 0 < m_AllowedIPList.size() )
	{
		m_AllowedIPList_ReloadVersion.push_back(m_AllowedIPList);
		WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] ReLoad_AllowedIPList, Reload IP Count (%2d), AllowedIPList Version (%d)\r\n", m_AllowedIPList.size(), m_AllowedIPList_ReloadVersion.size() );
		m_AllowedIPList.clear();
	}
	this->ReLoad_AllowedToolIPList();
#endif
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	if(m_vectGameServerGroupList.empty())
	{
		char	szSystemLog[1024];
		sprintf(szSystemLog, "[Error] CPreIOCP::LoadConfiguration GameServerGroupList error !!, GameServerGroupList is nothing !!\r\n");
		WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		return FALSE;
	}


	DBGOUT("========================================\n");

	fin.close();

	return TRUE;
}

// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
BOOL CPreGlobal::ReLoadConfiguration(void)
{
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	const int SIZE_BUFF = 512;
	string configFileName = string(CONFIG_ROOT) + string("pre.cfg");
	char buff[SIZE_BUFF];
	char buffBackup[SIZE_BUFF];
	const char *token;
	char seps[] = " \t";
	char seps_servergroup[] = ".";
	
	ifstream fin;
	CConfig config;
	
	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
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
		
		token = config.strtok(buff, seps);
		
		if (token == NULL
			|| strncmp(token, "#", 1) == 0
			|| strncmp(token, "$", 1) == 0)
		{
			continue;
		}
		
		if (stricmp(token, "AllowedIP") == 0)
		{
			token = config.strtok(NULL, seps);
			if(NULL == token
				|| 0 == stricmp(token, ""))
			{
				continue;
			}
			
			m_AllowedIPList.push_back(token);
			this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedIP Add (%s)\r\n", token);
		}
		else if (stricmp(token, "AllowedAccount") == 0)
		{
			token = config.strtok(NULL, seps);
			if(NULL == token
				|| 0 == stricmp(token, ""))
			{
				continue;
			}
			_strlwr((char*)token);

			if ( m_AllowedAccounts.empty() || ( m_AllowedAccounts.find(token) != m_AllowedAccounts.end() ) )
			{
				m_AllowedAccounts.insert(token);
				this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedAccount Add (%s)\r\n", token);
			}
		}
		else if(0 == stricmp(token, "AllowedToolIP"))
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
	if ( 0 < m_AllowedIPList.size() )
	{
		m_AllowedIPList_ReloadVersion.push_back(m_AllowedIPList);
		this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] Reload AllowedIP Count (%2d), AllowedIPList Version (%d)\r\n", m_AllowedIPList.size(), m_AllowedIPList_ReloadVersion.size() );
		m_AllowedIPList.clear();
	}
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

CServerGroup* CPreGlobal::GetServerGroupForLoading(const char * szServerGruopName)
{
	vector<CServerGroup*>::iterator itr = m_AllServerGroupVectorForLoading.begin();
	for (; itr != m_AllServerGroupVectorForLoading.end(); itr++)
	{
		if (strnicmp((*itr)->m_ServerGroupName, szServerGruopName, SIZE_MAX_SERVER_NAME) == 0)
		{
			return *itr;
		}
	}
	
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CPreGlobal::GetEnableServerGroupCount(void)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CPreGlobal::GetEnableServerGroupCount(void)
{
	int nRetCnts = 0;
	vector<CServerGroup*>::iterator itr = m_AllServerGroupVectorForLoading.begin();
	for (; itr != m_AllServerGroupVectorForLoading.end(); itr++)
	{
		CServerGroup *pServGroup = *itr;
		if (pServGroup->m_bEnableServerGroup)
		{
			nRetCnts++;
		}
	}

	return nRetCnts;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::InsertGameServerGroup(char *i_szGameServerGroupName, char *i_szPreServerIP, USHORT i_usPreServerPort, int i_nTab8OrderIndex)
/// \brief		// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �����߰�(, USHORT i_usTab8OrderIndex), ���� ����(, USHORT i_usPreServerPort, ��Ʈ�� �⺻ ��Ʈ ���)
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::InsertGameServerGroup(char *i_szGameServerGroupName, char *i_szPreServerIP, int i_nTab8OrderIndex)
{
	if(0 >= i_nTab8OrderIndex)
	{// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - üũ�߰�
		return FALSE;
	}

	int nCurCnt = m_vectGameServerGroupList.size();
	if(COUNT_MAX_GAME_SERVER_GROUP_LIST <= nCurCnt)
	{
		return FALSE;
	}

	for(int i=0; i < nCurCnt; i++)
	{
		if(0 == stricmp(i_szPreServerIP, m_vectGameServerGroupList[i].szPreServerIP0))
		{// 2007-05-02 by cmkwon, PreServerIP�� �̹� ��ϵǾ� ����, ���� IP�� �ϳ��� ��ϰ���
			return FALSE;
		}
	}

	SGAME_SERVER_GROUP tmGSGroup;
	MEMSET_ZERO(&tmGSGroup, sizeof(tmGSGroup));
	STRNCPY_MEMSET(tmGSGroup.szGameServerGroupName, i_szGameServerGroupName, SIZE_MAX_GAME_SERVER_GROUP_NAME);
	STRNCPY_MEMSET(tmGSGroup.szPreServerIP0, i_szPreServerIP, SIZE_MAX_IPADDRESS);

#ifdef S_TEMP_PRESERVER_MAKE_HSKIM
	STRNCPY_MEMSET(tmGSGroup.szPreServerIP0, TEMP_PRESERVER_MAKE_IP, SIZE_MAX_IPADDRESS);
#endif

// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - ������, ��Ʈ�� �⺻��Ʈ�� �����
//	tmGSGroup.usPreServerPort0			= i_usPreServerPort;
	tmGSGroup.usPreServerTab8OrderIndex	= i_nTab8OrderIndex;

	m_vectGameServerGroupList.push_back(tmGSGroup);
	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::Make_MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList)
/// \brief		
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::Make_MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList)
{
	int nCurCnt = m_vectGameServerGroupList.size();
	if(COUNT_MAX_GAME_SERVER_GROUP_LIST <= nCurCnt)
	{
		return FALSE;
	}

	for(int i=0; i < nCurCnt; i++)
	{
		if(COUNT_MAX_GAME_SERVER_GROUP_LIST <= i)
		{
			break;
		}

		// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - ���� ���� ȣȯ�� ���� ����ü ����
		STRNCPY_MEMSET(o_pGameServerGroupList->arrGameServerGroupList[i].szGameServerGroupName, m_vectGameServerGroupList[i].szGameServerGroupName, SIZE_MAX_GAME_SERVER_GROUP_NAME);
		STRNCPY_MEMSET(o_pGameServerGroupList->arrGameServerGroupList[i].szPreServerIP0, m_vectGameServerGroupList[i].szPreServerIP0, SIZE_MAX_IPADDRESS);
		o_pGameServerGroupList->arrGameServerGroupList[i].usPreServerPort0 = this->m_pGIOCP->GetListenerPort();
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::Make_MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK(MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList)
/// \brief		// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �Ź��� �Լ� �߰�
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::Make_MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK(MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList)
{
	int nCurCnt = m_vectGameServerGroupList.size();
	if(COUNT_MAX_GAME_SERVER_GROUP_LIST <= nCurCnt)
	{
		return FALSE;
	}

	for(int i=0; i < nCurCnt; i++)
	{
		if(COUNT_MAX_GAME_SERVER_GROUP_LIST <= i)
		{
			break;
		}
		o_pGameServerGroupList->arrGameServerGroupList[i] = m_vectGameServerGroupList[i];
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::GetOnlyChoiceServer(void)
/// \brief		// 2007-07-06 by cmkwon, OnlyChoiceServer �÷��� ���� �߰�
/// \author		cmkwon
/// \date		2007-07-06 ~ 2007-07-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::GetOnlyChoiceServer(void)
{
	return m_bIsOnlyChoiceServer;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::createPreToAllServer(HWND i_hWnd)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::createPreToAllServer(HWND i_hWnd)
{
	m_pSPToMPWinsoc = new CSPToMPWinSocket(i_hWnd, SECURITY_TICK_INTERVAL);		// 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
	if(NULL == m_pSPToMPWinsoc)
	{
		return FALSE;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::connectBySPToMPWinSoc(char *i_szIP, int i_nPort)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::connectBySPToMPWinSoc(char *i_szIP, int i_nPort)
{
	if(NULL == m_pSPToMPWinsoc
		|| m_pSPToMPWinsoc->IsConnected())
	{
		return FALSE;
	}

	//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� connect MasangPreServer(%s:%d)\r\n", i_szIP, i_nPort);
	return m_pSPToMPWinsoc->Connect(i_szIP, i_nPort);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::sendToMasangPreServer(BYTE *i_pData, int i_nDataLen)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::sendToMasangPreServer(BYTE *i_pData, int i_nDataLen)
{
	if(NULL == m_pSPToMPWinsoc
		|| FALSE == m_pSPToMPWinsoc->IsConnected())
	{
		return FALSE;
	}

	//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� sendToMasangPreServer(0x%4X:%s)\r\n", *(MessageType_t*)i_pData, GetProtocolTypeString(*(MessageType_t*)i_pData));
	return m_pSPToMPWinsoc->Write(i_pData, i_nDataLen);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::OnAsyncEventOfSPToMPWinSoc(SOCKET i_hSocket, LONG i_nEvent)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::OnAsyncEventOfSPToMPWinSoc(SOCKET i_hSocket, LONG i_nEvent)
{
	if(NULL == m_pSPToMPWinsoc
		|| i_hSocket != m_pSPToMPWinsoc->GetSocketHandle())
	{
		return FALSE;
	}

	m_pSPToMPWinsoc->OnAsyncEvent(i_nEvent);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::OnPacketNotifyOfSPToMPWinSoc(WORD i_wNotifyTy, WORD i_wParam)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::OnPacketNotifyOfSPToMPWinSoc(WORD i_wNotifyTy, WORD i_wParam)
{
	if(NULL == m_pSPToMPWinsoc)
	{
		return FALSE;
	}

	switch(i_wNotifyTy)
	{
	case CWinSocket::WS_CONNECTED:
		{
			//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� CPreGlobal::OnPacketNotifyOfSPToMPWinSoc CWinSocket::WS_CONNECTED wParam(%d)\r\n", i_wParam);

			// 2009-10-13 by cmkwon, PreServer �ý��� �α� �߰� - 
			g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreGlobal::OnPacketNotifyOfSPToMPWinSoc# 10000 CWinSocket::WS_CONNECTED wParam(%d) \r\n", i_wParam);

			// start 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
			if( g_pPreGlobal->m_pSPToMPWinsoc != NULL )
			{
				g_pPreGlobal->m_pSPToMPWinsoc->InsertTickEvent(SPTOMP_TICK_EVENT_SESSION_TIMEOUT, SPTOMP_DELAY_TIME_SEC_TIMEOUT);
			}
			// end 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��

			g_pPreGlobal->m_pSecurityManager->SetAuthentication(FALSE);		// 2011-06-22 by hskim, �缳 ���� ����

			if(FALSE == i_wParam)
			{
#ifdef S_AUTHENTICATION_SERVER_HSKIM		// 2011-01-26 by hskim, ���� ���� ����

#ifdef S_AUTHENTICATION_SERVER_2ND_HSKIM
				exit(0);		// cmkwon���� ���Ͻô� �������� ���� ����
#else
				// start 2011-06-22 by hskim, �缳 ���� ����
				// �缳 ���� ���� �������� ���� (���� ��å�� ���� ����)
				
				if(NULL != g_pPreGlobal->GetGIOCP() ) 
				{
					break;
				}

				if(FALSE == g_pPreGlobal->InitServerSocket())
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] CPreGlobal::OnPacketNotifyOfSPToMPWinSoc_ InitServerSocket_ error !!");

					break;
				}

				g_pPreGlobal->StartTimerTraffic();
				g_pPreGlobal->StartTimerAliveCheck();
				
				break;
				// end 2011-06-22 by hskim, �缳 ���� ����
#endif // S_AUTHENTICATION_SERVER_2ND_HSKIM
				
#else
				// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
				// 2008-02-22 by cmkwon, �ϴ� ����� �׳� ���񽺸� �����Ѵ�. ���� ���μ��� ����� ó��

				// start 2011-06-22 by hskim, �缳 ���� ����
				if(NULL != g_pPreGlobal->GetGIOCP() ) 
				{
					break;
				}
				// end 2011-06-22 by hskim, �缳 ���� ����

 				if(FALSE == g_pPreGlobal->InitServerSocket())
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] CPreGlobal::OnPacketNotifyOfSPToMPWinSoc_ InitServerSocket_ error !!");
					break;
				}
				g_pPreGlobal->StartTimerTraffic();
				g_pPreGlobal->StartTimerAliveCheck();

				break;
#endif	// S_AUTHENTICATION_SERVER_HSKIM
			}

#ifdef S_AUTHENTICATION_SERVER_HSKIM		// 2011-01-26 by hskim, ���� ���� ����
			// PreServer ���۽� ���� Authentication Server���� ���� ����
			SendToAuthenticationServer();
#else
			// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
			// 2008-02-22 by cmkwon, ���� ���� �Ͽ����Ƿ� �������� ����
			INIT_MSG_WITH_BUFFER(MSG_PP_CONNECT, T_PP_CONNECT, pConnect, SendBuf);
			pConnect->nServiceUID			= 0;	// 2008-02-22 by cmkwon, ���� �������� ����
			pConnect->nLanguageType			= g_pPreGlobal->GetLanguageType();
			STRNCPY_MEMSET(pConnect->szPreServerIP, g_pPreGlobal->GetPublicIPLocal(), SIZE_MAX_IPADDRESS);
			pConnect->nPreServerPort		= g_pPreGlobal->GetPortListening();
			pConnect->byIsOnlyChoiceServer	= g_pPreGlobal->GetOnlyChoiceServer();
			pConnect->byIsTestServer		= g_pPreGlobal->IsTestServer();
			pConnect->byIsUseExternalAuthentication	= g_pPreGlobal->IsExternalAuthentication();
			pConnect->nPreServerGroupCnts	= g_pPreGlobal->m_vectGameServerGroupList.size();
			pConnect->nEnableGameServerGroupCnts	= g_pPreGlobal->GetEnableServerGroupCount();
			g_pPreGlobal->sendToMasangPreServer(SendBuf, MSG_SIZE(MSG_PP_CONNECT));
#endif
		}
		break;
	case CWinSocket::WS_CLOSED:
		{
			//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� CPreGlobal::OnPacketNotifyOfSPToMPWinSoc CWinSocket::WS_CLOSED wParam(%d)\r\n", i_wParam);
		}
		break;
	case CWinSocket::WS_RECEIVED:
		{
			//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� CPreGlobal::OnPacketNotifyOfSPToMPWinSoc CWinSocket::WS_RECEIVED wParam(%d)\r\n", i_wParam);
		}
		break;
	}

	return TRUE;
}

char *CPreGlobal::GetGamePublisherName(void)
{	// 2010-06-01 by shcho, GLogDB ���� -
	return m_szGamePublisherName;
}

// start 2011-06-22 by hskim, �缳 ���� ����
void CPreGlobal::SendToAuthenticationServer()
{
	INIT_MSG_WITH_BUFFER(MSG_PATUM_CONNECT, T_PAUTH_CONNECT_LOGIN, pConnect, SendBuf);

	STRNCPY_MEMSET(pConnect->szGameName, "���̽��¶���", SIZE_MAX_AUTH_GAMENAME);
	STRNCPY_MEMSET(pConnect->szServerIP, g_pPreGlobal->GetPublicIPLocal(), SIZE_MAX_IPADDRESS);
	pConnect->nServerPort		= g_pPreGlobal->GetPortListening();
	_snprintf(pConnect->szCurrentVer, SIZE_MAX_AUTH_CURRENTVER, "%s %s", __DATE__, __TIME__);
	pConnect->nLanguageType			= g_pPreGlobal->GetLanguageType();
	pConnect->byTestServer		= g_pPreGlobal->IsTestServer();
	pConnect->byUseExternalAuthentication	= g_pPreGlobal->IsExternalAuthentication();
	pConnect->nPreServerGroupCnts	= g_pPreGlobal->m_vectGameServerGroupList.size();
	pConnect->nEnableGameServerGroupCnts	= g_pPreGlobal->GetEnableServerGroupCount();

	g_pPreGlobal->sendToMasangPreServer(SendBuf, MSG_SIZE(MSG_PATUM_CONNECT));
}
// end 2011-06-22 by hskim, �缳 ���� ����


// 2012-10-05 by jhseol, NPlay pc�� ���
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::createNPlayPCBangModule(HWND i_hWnd)
/// \brief		NPlay PC�� ��� ���� ����
/// \author		jhseol
/// \date		2012-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::createNPlayPCBangModule(HWND i_hWnd, char* i_szNPlayServerIP_Real, char* i_szNPlayServerIP_BackUp)
{
	m_pNPlayPCBangModule = new CNPlayPCBangModule(i_hWnd, SPTOMP_TICK_INTERVAL, i_szNPlayServerIP_Real, i_szNPlayServerIP_BackUp);
	if(NULL == m_pNPlayPCBangModule)
	{
		return FALSE;
	}
	
	return TRUE;
}
// end 2012-10-05 by jhseol, NPlay pc�� ���


// 2012-10-05 by jhseol, NPlay pc�� ���
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::connectByNPlayPCBangModuleWinSoc(char *i_szIP, int i_nPort)
/// \brief		PC�� ��� ���� ����
/// \author		jhseol
/// \date		2012-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::connectByNPlayPCBangModuleWinSoc(char *i_szIP, int i_nPort)
{
	if(NULL == m_pNPlayPCBangModule	|| TRUE == m_pNPlayPCBangModule->IsConnected())
	{
		return FALSE;
	}
	
	//g_pPreGlobal->WriteSystemLogEX(TRUE, "�ӽ��׽�Ʈ�� connect MasangPreServer(%s:%d)\r\n", i_szIP, i_nPort);
	g_pPreGlobal->SetNPlayConnectServer(NPLAY_CONNECT_SERVER_REAL);
	return m_pNPlayPCBangModule->Connect(i_szIP, i_nPort);
}
// end 2012-10-05 by jhseol, NPlay pc�� ���


// 2012-10-05 by jhseol, NPlay pc�� ���
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::OnAsyncEventOfNPlayPCBangModuleWinSoc(SOCKET i_hSocket, LONG i_nEvent)
/// \brief		PC�� ��� ���� �̺�Ʈ ó��
/// \author		jhseol
/// \date		2012-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::OnAsyncEventOfNPlayPCBangModuleWinSoc(SOCKET i_hSocket, LONG i_nEvent)
{
	if(NULL == m_pNPlayPCBangModule
		|| i_hSocket != m_pNPlayPCBangModule->GetSocketHandle())
	{
		return FALSE;
	}
	
	m_pNPlayPCBangModule->OnAsyncEvent(i_nEvent);
	return TRUE;
}
// end 2012-10-05 by jhseol, NPlay pc�� ���


// 2012-10-05 by jhseol, NPlay pc�� ���
///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CPreGlobal::OnPacketNotifyOfNPlayPCBangModuleWinSoc(WORD i_wNotifyTy, WORD i_wParam)
/// \brief		PC�� ��� ���� NOTIFY ó��
/// \author		jhseol
/// \date		2012-10-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CPreGlobal::OnPacketNotifyOfNPlayPCBangModuleWinSoc(WORD i_wNotifyTy, WORD i_wParam)
{
	if(NULL == m_pNPlayPCBangModule)
	{
		return FALSE;
	}

	switch(i_wNotifyTy)
	{
	case CWinSocket::WS_CONNECTED:
		{
			// 2009-10-13 by cmkwon, PreServer �ý��� �α� �߰� - 
			g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreGlobal::OnPacketNotifyOfNPlayPCBangModuleWinSoc 20000 CWinSocket::WS_CONNECTED wParam(%d) \r\n", i_wParam);
			if( FALSE == m_pNPlayPCBangModule->NPlayServerConnect() )
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "  [ERROR] NPlay PCBang Module Game Server Connect Failed!! :: NPlayServerConnect() \r\n");
				return FALSE;
			}
		}
		break;
	case CWinSocket::WS_CLOSED:
		{
			m_pNPlayPCBangModule->NPlayCreateSocket();
			if( NPLAY_CONNECT_SERVER_REAL == g_pPreGlobal->GetNPlayConnectServer() )
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Error] CPreGlobal::OnPacketNotifyOfNPlayPCBangModuleWinSoc, NPlay DisConnect Socket! ReConnect BackUp Server[IP:%s]",g_pPreGlobal->GetNPlayServerIP_BackUP());
				g_pPreGlobal->SetNPlayConnectServer(NPLAY_CONNECT_SERVER_BACKUP);
				m_pNPlayPCBangModule->Connect(g_pPreGlobal->GetNPlayServerIP_BackUP(), NPLAY_SERVER_PORT);
			}
			else if( NPLAY_CONNECT_SERVER_BACKUP == g_pPreGlobal->GetNPlayConnectServer() )
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "  [Error] CPreGlobal::OnPacketNotifyOfNPlayPCBangModuleWinSoc, NPlay DisConnect Socket! ReConnect Real Server[IP:%s]",g_pPreGlobal->GetNPlayServerIP_Real());
				g_pPreGlobal->SetNPlayConnectServer(NPLAY_CONNECT_SERVER_REAL);
				m_pNPlayPCBangModule->Connect(g_pPreGlobal->GetNPlayServerIP_Real(), NPLAY_SERVER_PORT);
			}
		}
		break;
	case CWinSocket::WS_RECEIVED:
		{
		}
		break;
	}

	return TRUE;
}

char* CPreGlobal::GetNPlayServerIP_Real()
{
	return m_szNPlayServerIP_Real;
}

char* CPreGlobal::GetNPlayServerIP_BackUP()
{
	return m_szNPlayServerIP_BackUP;
}

void CPreGlobal::SetNPlayConnectServer(BYTE i_nConnectServer)
{
	m_nNPlayConectServer = i_nConnectServer;
}

BYTE CPreGlobal::GetNPlayConnectServer()
{
	return m_nNPlayConectServer;
}
// end 2012-10-05 by jhseol, NPlay pc�� ���
