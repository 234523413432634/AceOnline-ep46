// NPCGlobal.cpp: implementation of the CNPCGlobal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NPCGlobal.h"
#include "N2FSocket.h"
#include "NPCIOCP.h"
#include "Config.h"

CNPCGlobal *			g_pNPCGlobal = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNPCGlobal::CNPCGlobal()
{
	if(g_pNPCGlobal)
	{
		return;
	}
	g_pNPCGlobal = this;

	memset(m_szIPFieldServer, 0x00, SIZE_MAX_IPADDRESS);
	m_nPortFieldServer			= 0;

	m_pN2FSocket				= NULL;

	m_bIsArenaServer			= FALSE;		// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
}

CNPCGlobal::~CNPCGlobal()
{
	EndServerSocket();
	this->DestroyN2FSocket();

	g_pGlobalGameServer = NULL;
}


///////////////////////////////////////////////////////////////////////////
// Property
///////////////////////////////////////////////////////////////////////////
void CNPCGlobal::SetIPFieldServer(char *i_szIP)
{
	memcpy(m_szIPFieldServer, i_szIP, SIZE_MAX_IPADDRESS);
}

char *CNPCGlobal::GetIPFieldServer(void)
{
	return m_szIPFieldServer;
}

void CNPCGlobal::SetPortFieldServer(int i_nPort)
{
	m_nPortFieldServer = i_nPort;
}

int CNPCGlobal::GetPortFieldServer(void)
{
	return m_nPortFieldServer;
}

CN2FSocket * CNPCGlobal::GetN2FSocket(void)
{
	return m_pN2FSocket;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCGlobal::WriteN2FSocket(BYTE *pData, int nSize)
/// \brief		// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) - CNPCGlobal::WriteN2FSocket() �߰�
/// \author		cmkwon
/// \date		2007-11-26 ~ 2007-11-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCGlobal::WriteN2FSocket(BYTE *pData, int nSize)
{
	if(NULL == m_pN2FSocket
		|| FALSE == m_pN2FSocket->IsConnected())
	{
		return FALSE;
	}

	return m_pN2FSocket->Write(pData, nSize);
}

///////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////
BOOL CNPCGlobal::CreateN2FSocket(HWND i_hWnd)
{
	if(m_pN2FSocket)
	{
		return FALSE;
	}

	m_pN2FSocket = new CN2FSocket(i_hWnd, WM_N2F_ASYNC_EVENT, WM_N2F_PACKET_NOTIFY);
	return TRUE;
}

void CNPCGlobal::DestroyN2FSocket(void)
{
	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - IMServer 
	this->WriteSystemLogEX(TRUE, "  [Notify] CNPCGlobal::DestroyN2FSocket# 0x%X IsConnected(%d) \r\n", m_pN2FSocket, (m_pN2FSocket)?m_pN2FSocket->IsConnected():FALSE);

	if(m_pN2FSocket && m_pN2FSocket->IsConnected())
	{
		m_pN2FSocket->CloseSocket();
	}
	SAFE_DELETE(m_pN2FSocket);
}

///////////////////////////////////////////////////////////////////////////
// virtual Function
///////////////////////////////////////////////////////////////////////////
BOOL CNPCGlobal::InitServerSocket(void)
{
	if(NULL == GetN2FSocket()
		|| GetN2FSocket()->IsConnected() == FALSE)
	{
		return FALSE;
	}
	if(m_pGIOCP){		 return FALSE;}

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CNPCGlobal::InitServerSocket# Starting... \r\n");

	m_pGIOCP = new CNPCIOCP(m_nPortListening, m_szIPLocal);
	if(m_pGIOCP->IOCPInit() == FALSE)
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] NPCServer IOCPInit Error\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
		return FALSE;
	}
	if(FALSE == ((CNPCIOCP*)m_pGIOCP)->OpenUDPPortForOtherServer())
	{
		return FALSE;
	}

	CGlobalGameServer::InitServerSocket();

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CNPCGlobal::InitServerSocket# Started \r\n");

	return TRUE;
}

BOOL CNPCGlobal::EndServerSocket(void)
{
	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CNPCGlobal::EndServerSocket# \r\n");

	CGlobalGameServer::EndServerSocket();

	return TRUE;
}

CString CNPCGlobal::LoadConfiguration1()
{
	const int SIZE_BUFF = 512;
	char		buff[SIZE_BUFF];
	char		buffBackup[SIZE_BUFF];	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	const char	*token;
	char		seps[] = " \t";
	ifstream	fin;
	CConfig		config;

	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		return szError;
	}

	if (!config.LoadUserDefinedVariables(NPC_SERVER_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables() error, FileName[%s]\r\n"
			, NPC_SERVER_CONFIG_FILE_PATH);
		return szError;
	}

	fin.open(NPC_SERVER_CONFIG_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...

		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, NPC_SERVER_CONFIG_FILE_PATH);
		return szError;
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
				return "Loading Configuration File Failed1.\n";

			this->SetIPLocal((char*)token);
		}
		else if(stricmp(token, "LocalPublicIPAddress") == 0)
		{// 2006-05-23 by cmkwon,
			token = config.strtok(NULL, seps);
			if (token == NULL)
				return "Loading Configuration File Failed2.\n";

			this->SetPublicIPLocal((char*)token);
		}
		else if(stricmp(token, "LocalListenPort") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
				return "Loading Configuration File Failed3.\n";
			
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
				return "Loading Configuration File Failed4.\n";
			}
			this->m_nLanguageType = atoi(token);
			if(FALSE == IS_VALID_LANGUAGE_TYPE(this->m_nLanguageType))
			{
				return "Loading Configuration File Failed5.\n";
			}
		}
		else if(stricmp(token, "ODBCDSN") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				return "Loading Configuration File Failed6. ODBCDSN\n";
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
				return "Loading Configuration File Failed7. ODBCUID\n";
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
				return "Loading Configuration File Failed8. ODBCPASSWD\n";
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
		else if(stricmp(token, "FieldServer") == 0)
		{
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetIPFieldServer((char*)token);
			}
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetPortFieldServer(atoi(token));
			}
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CNPCGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_IP, buffBackup);
				return szErr;
			}
			
			STRNCPY_MEMSET(m_szDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_PORT))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CNPCGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_PORT, buffBackup);
				return szErr;
			}
			
			m_nDBServerPort = atoi(token);			
		}
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_DATABASE_NAEE))
		{// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CNPCGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_DATABASE_NAEE, buffBackup);
				return szErr;
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
		else if(0 == stricmp(token, "ArenaServerFlag"))
		{// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
			token = config.strtok(NULL, seps);
			if(NULL == token)
			{				
				return "Loading Configuration File failed !!! \r\n";
			}
			if(0 == stricmp(token, "TRUE"))
			{
				m_bIsArenaServer	= TRUE;
			}
		}// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
		// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����
#ifdef S_DISABLE_ALONE_RUN_MODE_HSKIM
		else if(stricmp(token, "ServerGroupName") == 0)
		{
			token = config.strtok(NULL, seps);
			if(strcmp(token, "") != 0)
			{
				this->SetServerGroupName((char*)token);
			}
		}
#endif
		// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����
		else
		{
			// configuration file error!
			assert(0);
		}
	}
	fin.close();

	if(strcmp(this->GetIPLocal(), "") == 0
		|| strcmp(this->GetIPFieldServer(), "") == 0
		|| this->GetPortFieldServer() == 0)
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration() Loading Configuration Failed, LocalIP[%s] FieldServer[%s:%d]\r\n"
			, this->GetIPLocal(), this->GetIPFieldServer(), this->GetPortFieldServer());
		return szError;
	}
	if (m_Localization.LoadConfiguration((char*)LOCALIZATION_CONFIG_DIRECTORY_PATH, this->m_nLanguageType) == FALSE)
		return "Cannot load localization files!";
	
	return "OK";
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CNPCGlobal::GetIsArenaServer(void)
/// \brief		// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
/// \author		cmkwon
/// \date		2008-09-10 ~ 2008-09-10
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CNPCGlobal::GetIsArenaServer(void)
{
	return m_bIsArenaServer;
}
