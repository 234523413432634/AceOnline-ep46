// FieldGlobal.cpp: implementation of the CFieldGlobal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FieldGlobal.h"
#include "LogWinSocket.h"
#include "PreWinSocket.h"
#include "IMWinSocket.h"
#include "ArenaFieldWinSocket.h"		// 2007-12-26 by dhjin, 아레나 통합 - 
#include "FieldIOCP.h"
#include "Config.h"
#include "PCBangIPManager.h"
#include "AtumLogSender.h"				// 2012-10-08 by khkim, GLog
#include "FieldWebIOCP.h"				// 2013-03-13 by hskim, 웹 캐시 상점

CFieldGlobal *			g_pFieldGlobal = NULL;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFieldGlobal::CFieldGlobal()
{
	if(g_pFieldGlobal)
	{
		return;
	}
	g_pFieldGlobal				= this;

	m_dwLastTickLogSystem		= 0;
	memset(m_szFieldServerGroupName, 0x00, SIZE_MAX_SERVER_NAME);
	memset(m_szIPLogServer, 0x00, SIZE_MAX_IPADDRESS);
	memset(m_szIPNPCServer, 0x00, SIZE_MAX_IPADDRESS);		// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
	memset(m_szIPIMServer, 0x00, SIZE_MAX_IPADDRESS);
	memset(m_szIPVoIP1to1Server, 0x00, SIZE_MAX_IPADDRESS);
	m_nPortLogServer			= 0;
	m_nPortIMServer				= 0;
	m_nPortVoIP1to1Server		= 0;

	m_vectorF2LWSocketPtr.reserve(SIZE_FIELD2LOG_WINSOCKET);
	m_nSendIndexF2LWSocket		= 0;
	m_pField2PreWinSocket		= NULL;
	m_pField2IMWinSocket		= NULL;
	m_pField2ArenaFieldWinSocket = NULL;					// 2007-12-26 by dhjin, 아레나 통합 - 

	m_bEventActivated			= FALSE;

	m_plRequestInCRTLib			= NULL;		// 2006-05-30 by cmkwon
	m_plRequestInCRTLib			= (long*)0x10261538;		// 2006-05-30 by cmkwon

	m_bCashShopServiceFlag		= FALSE;	// 2007-01-10 by cmkwon
	m_bUseSecondaryPasswordSystemFlag	= FALSE;	// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - 초기화

	MEMSET_ZERO(m_szMainORTestServerName, SIZE_MAX_SERVER_NAME);		// 2007-04-09 by cmkwon
	MEMSET_ZERO(m_szGamePublisherName, SIZE_MAX_GAME_PUBLISHER_NAME);	// 2007-04-09 by cmkwon
	m_bIsJamboreeServer			= FALSE;	// 2007-04-09 by cmkwon

	strcpy(m_szMainORTestServerName, "Main");
	strcpy(m_szGamePublisherName, "Masangsoft");

	m_pPCBangIPManager			= NULL;
	MEMSET_ZERO(&m_sArenaServerInfo, sizeof(SARENA_SERVER_INFO));		// 2008-01-17 by dhjin, 아레나 통합 -  

	// 2014-01-27 by bckim, 버그 트랩
	MEMSET_ZERO(&m_sBugTrapServerInfo, sizeof(SBUGTRAP_SERVER_INFO));
	// End. 2014-01-27 by bckim, 버그 트랩

	///////////////////////////////////////////////////////////////////////////////
	// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 	
	MEMSET_ZERO(m_szBillingDBServerIP, SIZE_MAX_ODBC_CONN_STRING);
	m_nBillingDBServerPort		= 0;
	MEMSET_ZERO(m_szBillingDBServerDatabaseName, SIZE_MAX_ODBC_CONN_STRING);
	MEMSET_ZERO(m_szBillingDBServerUserID, SIZE_MAX_ODBC_CONN_STRING);
	MEMSET_ZERO(m_szBillingDBServerPassword, SIZE_MAX_ODBC_CONN_STRING);

	///////////////////////////////////////////////////////////////////////////////
	// 2009-06-03 by cmkwon, 세력 선택시 제한 시스템 사용 여부 플래그 추가 - 초기화
	m_bUseInflSelectionRestrictSystem	= FALSE;

	// 2013-03-13 by hskim, 웹 캐시 상점
	m_pFieldWebIOCP = NULL;
	m_bWebInterface = FALSE;
	m_bWebCashShop = FALSE;
	m_nWebInterfacePort = 0;
	// end 2013-03-13 by hskim, 웹 캐시 상점
}

CFieldGlobal::~CFieldGlobal()
{
	EndServerSocket();
	this->DestroyField2PreWinSocket();
	this->DestroyField2IMWinSocket();
	this->DestroyAllF2LWSocket();

	g_pGlobalGameServer = NULL;
	SAFE_DELETE(m_pPCBangIPManager);

	SAFE_DELETE(m_pFieldWebIOCP);		// 2013-03-13 by hskim, 웹 캐시 상점
}


//////////////////////////////////////////////////////////////////////
// Property
//////////////////////////////////////////////////////////////////////
void CFieldGlobal::SetLastTickLogSystem(DWORD i_dwTick)
{
	m_dwLastTickLogSystem  = i_dwTick;
}

DWORD CFieldGlobal::GetLastTickLogSystem(void)
{
	return m_dwLastTickLogSystem;
}

void CFieldGlobal::SetFieldServerGroupName(char *i_szFieldServerGroupName)
{
	STRNCPY_MEMSET(m_szFieldServerGroupName, i_szFieldServerGroupName, SIZE_MAX_SERVER_NAME);
}

char *CFieldGlobal::GetFieldServerGroupName(void)
{
	return m_szFieldServerGroupName;
}

void CFieldGlobal::SetIPLogServer(char *i_szIP)
{
	memcpy(m_szIPLogServer, i_szIP, SIZE_MAX_IPADDRESS);
}

char *CFieldGlobal::GetIPLogServer(void)
{
	return m_szIPLogServer;
}

// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
void CFieldGlobal::SetIPNPCServer(char *i_szIP)
{
	memcpy(m_szIPNPCServer, i_szIP, SIZE_MAX_IPADDRESS);
}

char *CFieldGlobal::GetIPNPCServer(void)
{
	return m_szIPNPCServer;
}
// end 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어

void CFieldGlobal::SetIPIMServer(char *i_szIP)
{
	memcpy(m_szIPIMServer, i_szIP, SIZE_MAX_IPADDRESS);
}

char *CFieldGlobal::GetIPIMServer(void)
{
	return m_szIPIMServer;
}

char *CFieldGlobal::GetIPVoIP1to1Server(void)
{
	return m_szIPVoIP1to1Server;
}

char *CFieldGlobal::GetIPVoIPNtoNServer(void)
{
	return m_szIPVoIPNtoNServer;
}


void CFieldGlobal::SetPortLogServer(int i_nPort)
{
	m_nPortLogServer = i_nPort;
}

int CFieldGlobal::GetPortLogServer(void)
{
	return m_nPortLogServer;
}

void CFieldGlobal::SetPortIMServer(int i_nPort)
{
	m_nPortIMServer = i_nPort;
}

int CFieldGlobal::GetPortIMServer(void)
{
	return m_nPortIMServer;
}

int CFieldGlobal::GetPortVoIP1to1Server(void)
{
	return m_nPortVoIP1to1Server;
}

int CFieldGlobal::GetPortVoIPNtoNServer(void)
{
	return m_nPortVoIPNtoNServer;
}

CPreWinSocket * CFieldGlobal::GetField2PreWinSocket(void)
{
	return m_pField2PreWinSocket;
}

CIMWinSocket * CFieldGlobal::GetField2IMWinSocket(void)
{
	return m_pField2IMWinSocket;
}

CArenaFieldWinSocket * CFieldGlobal::GetField2ArenaFieldWinSocket(void)
{
	return m_pField2ArenaFieldWinSocket;					// 2007-12-26 by dhjin, 아레나 통합 - ;
}

// 2013-03-13 by hskim, 웹 캐시 상점
void CFieldGlobal::SetWebInterface(BOOL bWebInterface)
{
	m_bWebInterface = bWebInterface;
}

BOOL CFieldGlobal::IsWebInterface(void)
{
	return m_bWebInterface;
}

void CFieldGlobal::SetWebCashShop(BOOL bWebCashShop)
{
	m_bWebCashShop = bWebCashShop;
}

BOOL CFieldGlobal::IsWebCashShop(void)
{
	return (TRUE == IsWebInterface() && TRUE == m_bWebCashShop);
}

void CFieldGlobal::SetPortWebInterface(int nWebInterfacePort)
{
	m_nWebInterfacePort = nWebInterfacePort;
}

int CFieldGlobal::GetPortWebInterface(void)
{
	return m_nWebInterfacePort;
}
// 2013-03-13 by hskim, 웹 캐시 상점

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CFieldGlobal::ChecklRequestInCRTLib(void)
/// \brief		
/// \author		cmkwon
/// \date		2006-05-30 ~ 2006-05-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CFieldGlobal::ChecklRequestInCRTLib(void)
{
#ifdef _DEBUG
	if(NULL != m_plRequestInCRTLib
		&& 0 > (*m_plRequestInCRTLib))
	{// 2006-05-30 by cmkwon, CRTLib에 debug 모드일때 
		*m_plRequestInCRTLib	= 1;		// 2006-05-30 by cmkwon
	}
#endif
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetMainORTestServerName(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-04-09 ~ 2007-04-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetMainORTestServerName(void)
{
	return m_szMainORTestServerName;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetGamePublisherName(void)
/// \brief		
/// \author		cmkwon
/// \date		2007-04-09 ~ 2007-04-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetGamePublisherName(void)
{
	return m_szGamePublisherName;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		
/// \author		cmkwon
/// \date		2007-04-09 ~ 2007-04-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::GetIsJamboreeServer(void)
{
	return m_bIsJamboreeServer;
}


///////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::CreateAllF2WSocket(HWND i_hWnd)
{
	if( false == m_vectorF2LWSocketPtr.empty() )
	{
		return FALSE;
	}

	if( NULL == m_hMainWndHandle )
	{
		m_hMainWndHandle = i_hWnd;
	}


	for( int i = 0; i < SIZE_FIELD2LOG_WINSOCKET; i++ )
	{
		CLogWinSocket *pF2LWSocket = new CLogWinSocket( m_hMainWndHandle , WM_LOG_ASYNC_EVENT , WM_LOG_PACKET_NOTIFY );
		m_vectorF2LWSocketPtr.push_back( pF2LWSocket );
		if ( m_vectorF2LWSocketPtr.size() >= SIZE_FIELD2LOG_WINSOCKET )
		{
			break;
		}
	}
	 
	return TRUE;
}

BOOL CFieldGlobal::CreateField2PreWinSocket(HWND i_hWnd)
{
	if(m_pField2PreWinSocket){		return FALSE;}
	if(NULL == m_hMainWndHandle)
	{
		m_hMainWndHandle = i_hWnd;
	}

	m_pField2PreWinSocket = new CPreWinSocket(m_hMainWndHandle, WM_PRE_ASYNC_EVENT, WM_PRE_PACKET_NOTIFY);
	return TRUE;
}

BOOL CFieldGlobal::CreateField2IMWinSocket(HWND i_hWnd)
{
	if(m_pField2IMWinSocket){		return FALSE;}
	if(NULL == m_hMainWndHandle)
	{
		m_hMainWndHandle = i_hWnd;
	}

	m_pField2IMWinSocket = new CIMWinSocket(m_hMainWndHandle, WM_IM_ASYNC_EVENT, WM_IM_PACKET_NOTIFY);
	return TRUE;
}

BOOL CFieldGlobal::CreateField2ArenaFieldWinSocket(HWND i_hWnd)
{// 2007-12-26 by dhjin, 아레나 통합 - 
	if(m_pField2ArenaFieldWinSocket){		return FALSE;}
	if(NULL == m_hMainWndHandle)
	{
		m_hMainWndHandle = i_hWnd;
	}

	m_pField2ArenaFieldWinSocket = new CArenaFieldWinSocket(m_hMainWndHandle, WM_FIELD_ASYNC_EVENT, WM_FIELD_PACKET_NOTIFY);
	return TRUE;
}

void CFieldGlobal::DestroyAllF2LWSocket(void)
{
	// 2009-04-20 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::DestroyAllF2LWSocket# \r\n");

	// start 2012-10-08 by khkim, GLog 
	// ServerOff GLog 패킷Send 부분
#ifdef S_GLOG_3ND_KHK
	INIT_MSG_WITH_BUFFER(MSG_FL_LOG_SERVER,T_FL_LOG_SERVER, pSMsg, SendBuf);
	pSMsg->LogType			= GLOG_SL_LT_SERVEROFF;
	pSMsg->GameServerID		= GetMGameServerID();
	SendLogFieldServer2LogServer(SendBuf,MSG_SIZE(MSG_FL_LOG_SERVER));
#endif
	// end 2012-10-08 by khkim, GLog

	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(m_vectorF2LWSocketPtr[i]
			&& INVALID_SOCKET != m_vectorF2LWSocketPtr[i]->GetSocketHandle())
		{
			m_vectorF2LWSocketPtr[i]->CloseSocket();
		}
	}
	for_each(m_vectorF2LWSocketPtr.begin(), m_vectorF2LWSocketPtr.end(), Delete_Object());
	m_vectorF2LWSocketPtr.clear();
}

void CFieldGlobal::DestroyField2PreWinSocket(void)
{
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - FieldServer 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::DestroyField2PreWinSocket# 0x%X IsConnected(%d) \r\n", m_pField2ArenaFieldWinSocket, (m_pField2ArenaFieldWinSocket)?m_pField2ArenaFieldWinSocket->IsConnected():FALSE);

	if(m_pField2PreWinSocket && m_pField2PreWinSocket->IsConnected())
	{
		m_pField2PreWinSocket->CloseSocket();
	}
	SAFE_DELETE(m_pField2PreWinSocket);
}

void CFieldGlobal::DestroyField2IMWinSocket(void)
{
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - FieldServer 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::DestroyField2IMWinSocket# 0x%X IsConnected(%d) \r\n", m_pField2IMWinSocket, (m_pField2IMWinSocket)?m_pField2IMWinSocket->IsConnected():FALSE);

	if(m_pField2IMWinSocket && m_pField2IMWinSocket->IsConnected())
	{
		m_pField2IMWinSocket->CloseSocket();
	}
	SAFE_DELETE(m_pField2IMWinSocket);
}

void CFieldGlobal::DestroyField2ArenaFieldWinSocket(void)
{// 2007-12-26 by dhjin, 아레나 통합 - 
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - FieldServer 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::DestroyField2ArenaFieldWinSocket# 0x%X IsConnected(%d) \r\n", m_pField2ArenaFieldWinSocket, (m_pField2ArenaFieldWinSocket)?m_pField2ArenaFieldWinSocket->IsConnected():FALSE);

	if(m_pField2ArenaFieldWinSocket && m_pField2ArenaFieldWinSocket->IsConnected())
	{
		m_pField2ArenaFieldWinSocket->CloseSocket();
	}
	SAFE_DELETE(m_pField2ArenaFieldWinSocket);
}

///////////////////////////////////////////////////////////////////////////
// virtual Function
///////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::InitServerSocket(void)
{
	if(FALSE == IsArenaServer())
	{// 2007-12-26 by dhjin, 아레나 통합 - 아레나 서버가 아니면 생성
		if(NULL == m_pField2PreWinSocket || m_pField2PreWinSocket->IsConnected() == FALSE
			|| NULL == m_pField2IMWinSocket || m_pField2IMWinSocket->IsConnected() == FALSE
			|| NULL == m_pField2ArenaFieldWinSocket)
		{
			return FALSE;
		}
	}
	else
	{
		if(NULL == m_pField2PreWinSocket || m_pField2PreWinSocket->IsConnected() == FALSE
			|| NULL == m_pField2IMWinSocket || m_pField2IMWinSocket->IsConnected() == FALSE)
		{
			return FALSE;
		}
	}
		
	// check log server가 TRUE이면 log server 없이는 서버 실행 안 됨
	if (m_bCheckLogServer
		&& FALSE == this->IsConnectedAllF2LWSocket())
	{
		return FALSE;
	}

	MessageType_t msgType = T_FL_LOG_START_FIELD_SERVER;
	this->SendLogFieldServer2LogServer((BYTE*)&msgType, sizeof(msgType));

	// start 2012-10-08 by khkim, GLog 
	// ServerOn GLog 패킷Send 부분
	MSG_FL_LOG_SERVER LogServerOnParameter;
	MEMSET_ZERO(&LogServerOnParameter, sizeof(LogServerOnParameter));		// 2013-05-30 by jhseol, GLog 시스템 보완 - 초기화
	LogServerOnParameter.LogType		= GLOG_SL_LT_SERVERON; 			
	LogServerOnParameter.GameServerID	= g_pFieldGlobal->GetMGameServerID();
	CAtumLogSender::SendLogServer(&LogServerOnParameter);
	// end 2012-10-08 by khkim, GLog

	if (NULL != m_pGIOCP)
	{
		return FALSE;
	}

	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::InitServerSocket# Starting... \r\n");

	m_dwLastTickLogSystem = GetTickCount() - (TIMERGAP_LOGSYSTEM - 60000);			// FieldServer가 시작하고 1분후에 한번 접속정보를 로그 서버에 남긴다. 이후 부터는 5분간에 한번씩 로그를 남긴다

	//////////////////////////////////////////////////////////////////////////
	// 2007-08-07 by dhjin, CPCBangIPManager 생성
	m_pPCBangIPManager = new CPCBangIPManager;	

	m_pGIOCP = new CFieldIOCP(m_nPortListening, m_szIPLocal);
	((CFieldIOCP*)m_pGIOCP)->m_pPreWinSocket = m_pField2PreWinSocket;
	((CFieldIOCP*)m_pGIOCP)->m_pIMWinSocket = m_pField2IMWinSocket;
	if(FALSE == IsArenaServer())
	{// 2007-12-26 by dhjin, 아레나 통합 - 아레나 서버가 아니면 생성
		((CFieldIOCP*)m_pGIOCP)->m_pArenaFieldWinSocket = m_pField2ArenaFieldWinSocket;
	}
	if(m_pGIOCP->IOCPInit() == FALSE)
	{
		char	szSystemLog[256];
		sprintf(szSystemLog, "[Error] FieldServer IOCPInit Error\r\n");
		this->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
		return FALSE;
	}
	//-- CMKWON 2003-06-12 NPC Server로 부터 T_FN_NPCSERVER_START를 받고 처리하도록 수정
	//m_pGIOCP->OpenUDPPortForOtherServer();

	m_pField2PreWinSocket->SetFieldIOCP(((CFieldIOCP*)m_pGIOCP));
	m_pField2IMWinSocket->SetFieldIOCP(((CFieldIOCP*)m_pGIOCP));
	if(m_pField2ArenaFieldWinSocket)
	{
		m_pField2ArenaFieldWinSocket->SetFieldIOCP(((CFieldIOCP*)m_pGIOCP));	// 2009-04-17 by cmkwon, 통합Arena 관련 버그 수정 - 여기에서 설정해야 함.
	}

	// 2013-03-13 by hskim, 웹 캐시 상점
#ifdef S_WEB_CASHSHOP_SERVER_MODULE_HSKIM
	if( FALSE == IsArenaServer() && NULL == m_pFieldWebIOCP && TRUE == IsWebInterface() )
	{
		m_pFieldWebIOCP = new CFieldWebIOCP(GetPortWebInterface(), m_szIPLocal);

		if(m_pFieldWebIOCP->IOCPInit() == FALSE)
		{
			char	szSystemLog[256];
			sprintf(szSystemLog, "[Error] FieldWeb Server IOCPInit Error\r\n");
			this->WriteSystemLog(szSystemLog);
			DBGOUT(szSystemLog);
			MessageBox(NULL, szSystemLog, "ERROR", MB_OK);
			return FALSE;
		}

		((CFieldWebIOCP *)m_pFieldWebIOCP)->SetFieldIOCP(((CFieldIOCP*)m_pGIOCP));
	}
#endif
	// end 2013-03-13 by hskim, 웹 캐시 상점

	///////////////////////////////////////////////////////////////////////////
	// PRE server에 Connect 및 Map 정보 전송 - by kelovon
	INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_FIELD_CONNECT, T_FP_CONNECT_FIELD_CONNECT, msgConnect, SendBuf);
	STRNCPY_MEMSET(msgConnect->FieldServerGroupName, this->GetFieldServerGroupName(), SIZE_MAX_SERVER_NAME);
// 2006-05-23 by cmkwon, 아래와 같이 수정함
//	msgConnect->FieldServerID.SetValue(m_pGIOCP->GetLocalIPAddress(), m_pGIOCP->GetListenerPort());
	msgConnect->FieldServerID.SetValue(g_pFieldGlobal->GetPublicIPLocal(), m_pGIOCP->GetListenerPort());
	msgConnect->NumOfMapIndex = ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject.size();	// 이후에 서비스되는 map 수만 할당
	msgConnect->ArenaFieldServerCheck = m_sArenaServerInfo.ArenaFieldServerCheck;		// 2007-12-26 by dhjin, 아레나 통합 - TRUE => 아레나 필드 서버
	msgConnect->DBServerGroup			= this->m_DBServerGroup;		// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - CFieldIOCP::IOCPInit() 에서 설정됨

	int offset = 0;
	int NumOfMapServiced = 0;
	auto i{ 0 };
	for (i = 0; i < msgConnect->NumOfMapIndex; i++)
	{
		SERVER_ID tmpID;
		tmpID.SetValue(((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_strFieldIP
					, ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_sFieldListenPort);
		if (tmpID == ((CFieldIOCP*)m_pGIOCP)->m_FieldServerID)
		{
			*(USHORT*)((char*)SendBuf + MSG_SIZE(MSG_FP_CONNECT_FIELD_CONNECT) + offset)
				= ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_nMapIndex;
			offset += sizeof(USHORT);
			NumOfMapServiced++;
		}
	}
	msgConnect->NumOfMapIndex = NumOfMapServiced;
	m_pField2PreWinSocket->Write((char*)SendBuf, MSG_SIZE(MSG_FP_CONNECT_FIELD_CONNECT) + offset);

	// 2007-12-17 by cmkwon, 시스템 로그 추가
	this->WriteSystemLogEX(TRUE, "[Notify] CFieldGlobal::InitServerSocket_ send to PreServer !!, Service map counts(%3d), Send Bytes(%d)\r\n", NumOfMapServiced, MSG_SIZE(MSG_FP_CONNECT_FIELD_CONNECT) + offset);

	///////////////////////////////////////////////////////////////////////////
	// IM server에 Connect 및 Map 정보 전송 - by kelovon
	offset = 0;

	*(MessageType_t*)SendBuf = T_FI_CONNECT;
	offset += SIZE_FIELD_TYPE_HEADER;

	MSG_FI_CONNECT *pMsgConn = (MSG_FI_CONNECT*)(SendBuf + offset);
	pMsgConn->NumOfMapIndex = ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject.size();	// 이후에 서비스되는 map 수만 할당
	pMsgConn->FieldServerID = ((CFieldIOCP*)m_pGIOCP)->m_FieldServerID;
	if(IsArenaServer())
	{// 2008-02-28 by dhjin, 아레나 통합 - 아레나 서버이면 IM서버에 아레나 서버 bit를 체크하여 보낸다.
		pMsgConn->ArenaServerCheck = TRUE;
	}
	else
	{
		pMsgConn->ArenaServerCheck = FALSE;
	}
	offset += sizeof(MSG_FI_CONNECT);

	NumOfMapServiced = 0;
	for (i = 0; i < pMsgConn->NumOfMapIndex; i++)
	{
		SERVER_ID tmpID;
		tmpID.SetValue(((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_strFieldIP
					, ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_sFieldListenPort);
		if (tmpID == ((CFieldIOCP*)m_pGIOCP)->m_FieldServerID)
		{
			*(USHORT*)((char*)SendBuf + offset)
				= ((CFieldIOCP*)m_pGIOCP)->GetMapWorkspace()->m_vectorPtrMapProject[i]->m_nMapIndex;
			offset += sizeof(USHORT);
			NumOfMapServiced++;
		}
	}
	pMsgConn->NumOfMapIndex = NumOfMapServiced;

	m_pField2IMWinSocket->Write((char*)SendBuf, offset);
	// 2007-12-17 by cmkwon, 시스템 로그 추가
	this->WriteSystemLogEX(TRUE, "[Notify] CFieldGlobal::InitServerSocket_ send to IMServer !!, Service map counts(%3d), Send Bytes(%d)\r\n", NumOfMapServiced, offset);

	CGlobalGameServer::InitServerSocket();

	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::InitServerSocket# Started \r\n");

	return TRUE;
}

BOOL CFieldGlobal::EndServerSocket(void)
{
	// 2009-03-19 by cmkwon, 시스템 로그 추가 - 아래와 같이 수정
	//this->WriteSystemLogEX(TRUE, "[Notify] CFieldGlobal::EndServerSocket\r\n");	// 2007-12-17 by cmkwon, 시스템 로그 추가
	this->WriteSystemLogEX(TRUE, "  [Notify] CFieldGlobal::EndServerSocket# \r\n");

	CGlobalGameServer::EndServerSocket();

	return TRUE;
}

BOOL CFieldGlobal::LoadConfiguration(void)
{
	LoadAbuseAndProhibitedName();
// 2007-01-22 by dhjin, PC방 리스트 실시간으로 변경
//	LoadPCBangIPListFromConfig();// 2006-08-18 by dhjin, pc방 리스트 .cfg에서 읽기.

	///////////////////////////////////////////////////////////////////////////////
	// 2007-05-07 by cmkwon, 캐릭터명 생성시 사용가능한 문자 리스트를 로딩한다.
	// 2007-05-07 by cmkwon, 문자리스트파일(AllLetterList.cfg)이 없으면 체크 할 필요 없다
	CAtumSJ::LoadAllLetterList((string(CONFIG_ROOT)+string("./AllLetterList.cfg")).c_str());

	const int SIZE_BUFF = 512;
	char		buff[SIZE_BUFF];
	char		buffBackup[SIZE_BUFF];		// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
	const char	*token;
	char		seps[] = " \t";
	ifstream	fin;
	CConfig		config;

	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables_1() error, FileName[%s]\r\n"
			, GLOBAL_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	if (!config.LoadUserDefinedVariables( FIELD_SERVER_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration LoadUserDefinedVariables_2() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	fin.open(FIELD_SERVER_CONFIG_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...

		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, FIELD_SERVER_CONFIG_FILE_PATH);
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
				STRNCPY_MEMSET((char*)m_szODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
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
		else if(stricmp(token, "LOGDB_ODBCDSN") == 0)
		{// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - LOGDB_ODBCDSN 가져오기
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
				// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - m_szLogDBODBCDSN 설정하기
				STRNCPY_MEMSET((char*)m_szLogDBODBCDSN, token, SIZE_MAX_ODBC_CONN_STRING);
			}
		}
		else if(stricmp(token, "LOGDB_ODBCUID") == 0)
		{// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - LOGDB_ODBCUID 가져오기
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
				// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - m_szLogDBODBCUID 설정하기
				STRNCPY_MEMSET((char*)m_szLogDBODBCUID, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szLogDBODBCUID, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szLogDBODBCUID, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(stricmp(token, "LOGDB_ODBCPASSWD") == 0)
		{// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - LOGDB_ODBCPASSWD 가져오기
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
				// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - m_szLogDBODBCPASSWORD 설정하기
				STRNCPY_MEMSET((char*)m_szLogDBODBCPASSWORD, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szLogDBODBCPASSWORD, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szLogDBODBCPASSWORD, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(stricmp(token, "FieldServerGroupName") == 0)
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
				this->SetFieldServerGroupName((char*)token);
			}
		}
		else if(stricmp(token, "PreServer") == 0)
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
				this->SetIPPreServer((char*)token);
			}
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
				this->SetPortPreServer(atoi(token));
			}
		}
		else if(stricmp(token, "IMServer") == 0)
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
				this->SetIPIMServer((char*)token);
			}
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
				this->SetPortIMServer(atoi(token));
			}
		}
		else if(stricmp(token, "LogServer") == 0)
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
				this->SetIPLogServer((char*)token);
			}
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
				this->SetPortLogServer(atoi(token));
			}
		}
		else if(stricmp(token, "VoIP1to1Server") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			STRNCPY_MEMSET(m_szIPVoIP1to1Server, token, SIZE_MAX_IPADDRESS);

			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			m_nPortVoIP1to1Server = atoi(token);
		}
		else if(stricmp(token, "VoIPNtoNServer") == 0)
		{
			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			STRNCPY_MEMSET(m_szIPVoIPNtoNServer, token, SIZE_MAX_IPADDRESS);

			token = config.strtok(NULL, seps);
			if (token == NULL)
			{
				char *msg = "Loading Configuration File Failed.\n";
				DBGOUT(msg);
				MessageBox(NULL, msg, "Error", MB_OK);
				return FALSE;
			}
			m_nPortVoIPNtoNServer = atoi(token);
		}
		else if (stricmp(token, "CheckLogServer") == 0)
		{
			token = config.strtok(NULL, seps);

			if (token == NULL || (stricmp(token, "TRUE") != 0 && stricmp(token, "FALSE") != 0))
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "Loading Configuration File Failed: CheckLogServer\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}

			if (stricmp(token, "TRUE") == 0)
			{
				m_bCheckLogServer = TRUE;
			}
			else if (stricmp(token, "FALSE") == 0)
			{
				m_bCheckLogServer = FALSE;
			}
			else
			{
				// unreachable
				return FALSE;
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
// 2008-09-24 by cmkwon, global.cfg 형식 수정 - ServerGroupInfo 로 수정 함.
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
		else if(0 == stricmp(token, "MainORTestServerName"))		// 2007-04-09 by cmkwon
		{
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szMainORTestServerName, token, SIZE_MAX_SERVER_NAME);
			}
		}
		else if(0 == stricmp(token, "GamePublisher"))				// 2007-04-09 by cmkwon
		{
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szGamePublisherName, token, SIZE_MAX_GAME_PUBLISHER_NAME);
			}
		}
		else if(0 == stricmp(token, "IsJamboreeServer"))				// 2007-04-09 by cmkwon
		{
			token = config.strtok(NULL, seps);
			if(token == NULL)
			{
				m_bIsJamboreeServer = FALSE;
			}
			else
			{
				if (stricmp(token, "FALSE") == 0)
				{
					m_bIsJamboreeServer = FALSE;
				}
				else
				{
					m_bIsJamboreeServer = TRUE;
				}
			}
		}
		else if(0 == stricmp(token, "CashShopServiceFlag"))
		{// 2007-01-10 by cmkwon
			
			token = config.strtok(NULL, seps);
			if(token == NULL)
			{
				m_bCashShopServiceFlag = FALSE;
			}
			else
			{
				if (0 == stricmp(token, "TRUE"))
				{
					m_bCashShopServiceFlag = TRUE;
				}
				else
				{
					m_bCashShopServiceFlag = FALSE;
				}
			}
		}
		else if(0 == stricmp(token, "UseSecondaryPasswrodSystemFlag"))
		{// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - field.cfg 형식 추가
			
			token = config.strtok(NULL, seps);
			if(token == NULL)
			{
				m_bUseSecondaryPasswordSystemFlag = FALSE;
			}
			else
			{
				if (0 == stricmp(token, "TRUE"))
				{
					m_bUseSecondaryPasswordSystemFlag = TRUE;
				}
				else
				{
					m_bUseSecondaryPasswordSystemFlag = FALSE;
				}
			}
		}
		// 2007-12-26 by dhjin, 아레나 통합 - 아레나 서버 정보
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
				m_sArenaServerInfo.ArenaFieldServerCheck	= TRUE;
			}
			else if(0 == stricmp(token, "FALSE"))
			{// 2007-12-26 by dhjin, 아레나 서버 정보 설정
				m_sArenaServerInfo.ArenaFieldServerCheck	= FALSE;
				// 2007-12-26 by dhjin, 아레나 서버 이름 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaServerName\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}				
				STRNCPY_MEMSET(m_sArenaServerInfo.ArenaServerName, token, SIZE_MAX_SERVER_NAME);
				// 2007-12-26 by dhjin, 아레나 서버 ID 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaServerID\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				m_sArenaServerInfo.ArenaServerID	= atoi(token);
				// 2007-12-26 by dhjin, 아레나 Field 서버 IP 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaFieldServerIP\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}				
				STRNCPY_MEMSET(m_sArenaServerInfo.ArenaFieldServerIP, token, SIZE_MAX_IPADDRESS);
				// 2007-12-26 by dhjin, 아레나 Field 서버 Port 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaFieldServerPort\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				m_sArenaServerInfo.ArenaFieldServerPort	= atoi(token);
				// 2007-12-26 by dhjin, 아레나 IM 서버 IP 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaIMServerIP\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}				
				STRNCPY_MEMSET(m_sArenaServerInfo.ArenaIMServerIP, token, SIZE_MAX_IPADDRESS);
				// 2007-12-26 by dhjin, 아레나 IM 서버 Port 설정
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: ArenaIMServerPort\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				m_sArenaServerInfo.ArenaIMServerPort	= atoi(token);
			}
		}// 2007-12-26 by dhjin, 아레나 통합 - 아레나 서버 정보
		else if(0 == stricmp(token, "BugTrapServerFlag"))		//$BUGTRAPSERVERFLAG
		{		// 2014-01-27 by bckim, 버그 트랩
			
			token = config.strtok(NULL, seps);
			if(NULL == token)
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "Loading Configuration File Failed: BugtrapServerloading\r\n");
				this->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
			
			if(0 == stricmp(token, "FALSE"))
			{
				m_sBugTrapServerInfo.BugTrapServerFlag	= FALSE;
			}
			else if(0 == stricmp(token, "TRUE"))
			{
				m_sBugTrapServerInfo.BugTrapServerFlag	= TRUE;
				
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: BugTrapServerType\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}				
				m_sBugTrapServerInfo.BugTrapServerType	= atoi(token);		// 서버타입 
				
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: BugTrapServerIP\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				STRNCPY_MEMSET(m_sBugTrapServerInfo.BugTrapServerIP, token, SIZE_MAX_IPADDRESS);	// 서버아이피 
				
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: BugTrapServerID\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}				
				STRNCPY_MEMSET(m_sBugTrapServerInfo.LoginID, token, SIZE_MAX_ACCOUNT_NAME);
				
				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: BugTrapServerPW\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				STRNCPY_MEMSET(m_sBugTrapServerInfo.LoginPW, token, SIZE_MAX_PASSWORD);

				token = config.strtok(NULL, seps);
				if(NULL == token)
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, "Loading Configuration File Failed: BugTrapServerPW\r\n");
					this->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);
					return FALSE;
				}
				STRNCPY_MEMSET(m_sBugTrapServerInfo.ServerNationInfo, token, SIZE_MAX_SERVER_NAME);
			}			
		}// End. 2014-01-27 by bckim, 버그 트랩
		else if(0 == stricmp(token, CONFIG_NAME_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_IP, buffBackup);
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
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_PORT, buffBackup);
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
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_DB_SERVER_DATABASE_NAEE, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_LOGDB_DB_SERVER_IP))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_LOGDB_DB_SERVER_IP, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szLogDBDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
		}
		else if(0 == stricmp(token, CONFIG_NAME_LOGDB_DB_SERVER_PORT))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_LOGDB_DB_SERVER_PORT, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			m_nLogDBDBServerPort = atoi(token);			
		}
		else if(0 == stricmp(token, CONFIG_NAME_LOGDB_DB_SERVER_DATABASE_NAEE))
		{// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
			
			token = config.strtok(NULL, seps);
			if (NULL == token)
			{
				char szErr[1024];
				sprintf(szErr, "[ERROR] CFieldGlobal::LoadConfiguration error !! %s, %s\r\n", CONFIG_NAME_LOGDB_DB_SERVER_DATABASE_NAEE, buffBackup);
				MessageBox(NULL, szErr, "Error", MB_OK);
				return FALSE;
			}
			
			STRNCPY_MEMSET(m_szLogDBDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
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
		// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
		else if(0 == stricmp(token, "AllowedAdminClientIP"))
		{
			token = config.strtok(NULL, seps);
			if(NULL == token || 0 == strcmp("", token))
			{
				continue;
			}
			m_AllowedAdminClientIPList.push_back(token);
			this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedAdminClientIP Add (%s)\r\n", token);
		}
		// end 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
		else if(0 == stricmp(token, "BillingDBServerIP"))
		{// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 

			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szBillingDBServerIP, token, SIZE_MAX_ODBC_CONN_STRING);
			}
		}
		else if(0 == stricmp(token, "BillingDBServerPort"))
		{// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
			token = config.strtok(NULL, seps);
			if(token)
			{
				m_nBillingDBServerPort = atoi(token);
			}
		}
		else if(0 == stricmp(token, "BillingDBServerDatabaseName"))
		{// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szBillingDBServerDatabaseName, token, SIZE_MAX_ODBC_CONN_STRING);
			}
		}
		else if(0 == stricmp(token, "BillingDBServerUserID"))
		{// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szBillingDBServerUserID, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szBillingDBServerUserID, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szBillingDBServerUserID, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
		}
		else if(0 == stricmp(token, "BillingDBServerPassword"))
		{// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
			token = config.strtok(NULL, seps);
			if(token)
			{
				STRNCPY_MEMSET(m_szBillingDBServerPassword, token, SIZE_MAX_ODBC_CONN_STRING);
				///////////////////////////////////////////////////////////////////////////////
				// 2008-09-01 by cmkwon, global.cfg 파일에 DB ID/PWD 암호화 - 
				BYTE byEncodedBinary[1024];
				MEMSET_ZERO(byEncodedBinary, 1024);
				if(XOR::XORString2Binary(byEncodedBinary, (char*)token))
				{
					MEMSET_ZERO(m_szBillingDBServerPassword, SIZE_MAX_ODBC_CONN_STRING);
					XOR::XOREncode((BYTE*)m_szBillingDBServerPassword, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
				}
			}
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
					g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CFieldGlobal::LoadConfiguration# error !! %s\r\n", buffBackup);
					return FALSE;
				}
				continue;
			}
			
			if(SIZE_MAX_SERVER_NAME <= strlen(tokenList[0].c_str()))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CFieldGlobal::LoadConfiguration# longer than max servergroupname !! %s\r\n", buffBackup);
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
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CFieldGlobal::LoadConfiguration# smaller than min ServerGroupID !! %s\r\n", buffBackup);
				return FALSE;
			}
			
			if (FALSE == InsertServerGroupforMGame(szGroupName, nMGameServerID))
			{
				g_pGlobal->WriteSystemLogEX(TRUE, "[Error] CFieldGlobal::LoadConfiguration# Same ServerGroupName registered already !! %s\r\n", buffBackup);
				return FALSE;
			}

			g_pGlobal->WriteSystemLogEX(TRUE, "	ServerGroup: %20s, Enable(%d) MGameServerID(%5d)\r\n", szGroupName, bEnableServerGroup, nMGameServerID);
		}
		// 2009-06-03 by cmkwon, 세력 선택시 제한 시스템 사용 여부 플래그 추가 - 
		else if(0 == stricmp(token, "UseInflSelectionRestrictSystem"))
		{
			token = config.strtok(NULL, seps);
			if (token
				&& 0 == stricmp("TRUE", token))
			{
				g_pFieldGlobal->SetUseInflSelectionRestrictSystem(TRUE);
			}
			else
			{
				g_pFieldGlobal->SetUseInflSelectionRestrictSystem(FALSE);
			}
		}
		// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
		else if(0 == stricmp(token, "NPCServer"))
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
				this->SetIPNPCServer((char*)token);
			}
		}
		// end 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
		// 2013-03-13 by hskim, 웹 캐시 상점
#ifdef S_WEB_CASHSHOP_SERVER_MODULE_HSKIM
		else if(0 == stricmp(token, "IsWebInterface"))
		{
			token = config.strtok(NULL, seps);
			if (token
				&& 0 == stricmp("TRUE", token))
			{
				g_pFieldGlobal->SetWebInterface(TRUE);
			}
			else
			{
				g_pFieldGlobal->SetWebInterface(FALSE);
			}
		}
		else if(0 == stricmp(token, "IsWebCashShop"))
		{
			token = config.strtok(NULL, seps);
			if (token
				&& 0 == stricmp("TRUE", token))
			{
				g_pFieldGlobal->SetWebCashShop(TRUE);
			}
			else
			{
				g_pFieldGlobal->SetWebCashShop(FALSE);
			}
		}
		else if(0 == stricmp(token, "WebInterfacePort"))
		{
			token = config.strtok(NULL, seps);
			if(token)
			{
				g_pFieldGlobal->SetPortWebInterface(atoi(token));
			}
		}
#endif
		// end 2013-03-13 by hskim, 웹 캐시 상점
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 2014-02-10 by jhseol&bckim, 체널링 - 사용자 CI값 확인을 하기 위해 외부 계정정보 DB연결
#ifdef SC_CHANNELING_JHSEOL_BCKIM_SSJUNG	// - 사용자 CI값 확인을 하기 위해 외부 계정정보 DB연결
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
		// end 2014-02-10 by jhseol&bckim, 체널링 - 사용자 CI값 확인을 하기 위해 외부 계정정보 DB연결
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

	if ( 0 < m_AllowedAdminClientIPList.size() )
	{
		m_AllowedAdminClientIPList_ReloadVersion.push_back(m_AllowedAdminClientIPList);
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] ReLoad_AllowedAdminClientIPList, Reload Admin Client IP Count (%2d), AllowedAdminClientIPList Version (%d)\r\n", m_AllowedAdminClientIPList.size(), m_AllowedAdminClientIPList_ReloadVersion.size() );
		m_AllowedAdminClientIPList.clear();
	}
#endif
	// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신

	m_nMGameServerID1 = GetServerIDforMGame(GetServerGroupName());

	if(strcmp(this->GetIPLocal(), "") == 0
		|| strcmp(this->GetFieldServerGroupName(), "") == 0
		|| strcmp(this->GetIPPreServer(), "") == 0
		|| strcmp(this->GetIPIMServer(), "") == 0
		|| strcmp(this->GetIPLogServer(), "") == 0
		|| strcmp(this->GetIPNPCServer(), "") == 0		// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
		|| strcmp(this->GetIPVoIP1to1Server(), "") == 0
		|| strcmp(this->GetIPVoIPNtoNServer(), "") == 0
		|| this->GetPortListening() == 0
		|| this->GetPortLogServer() == 0
		|| this->GetPortIMServer() == 0
		|| this->GetPortPreServer() == 0
		|| this->GetPortVoIP1to1Server() == 0
		|| this->GetPortVoIPNtoNServer() == 0)
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadConfiguration() Loading Configuration Failed, LocalIP[%s] FieldServerGroupName[%s] PreServer[%s:%d] LogServer[%s:%d] IMServer[%s:%d] NPCServer[%s]\r\n"		// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
			, this->GetIPLocal(), this->GetFieldServerGroupName(),
			this->GetIPPreServer(), this->GetPortPreServer(),
			this->GetIPLogServer(), this->GetPortLogServer(),
			this->GetIPIMServer(), this->GetPortIMServer(),
			this->GetIPNPCServer());		// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
		this->WriteSystemLog(szError);
		DBGOUT(szError);

		MessageBox(NULL, szError, "ERROR", MB_OK);
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2007-12-03 by cmkwon, 게임 로그 DB 따로 구축 하기 버그 수정 - 체크 추가
// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
//	if(0 == strcmp((LPSTR)this->GetLogDBODBCDSN(), "")
	if(0 == strcmp((LPSTR)this->GetLogDBODBCUID(), "")
		|| 0 == strcmp((LPSTR)this->GetLogDBODBCPASSWORD(), ""))
	{
		char	szError[1024];
		sprintf(szError, "[Error] CFieldGlobal::LoadConfiguration_ You must set LogDBServer !!, LOGDB_ODBCUID(%s) LOGDB_ODBCPASSWORD(%s)\r\n"
			, (LPSTR)this->GetLogDBODBCUID(), (LPSTR)this->GetLogDBODBCPASSWORD());
		MessageBox(NULL, szError, "ERROR", MB_OK);
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2008-08-26 by cmkwon, 베트남 VTC-Intecom_Viet 2차 패스워드 시스템 버그 수정 - 아레나 서버군일 경우 2차 패스워드를 사용하지 않도록 한다.
	if(IsArenaServer())
	{
		m_bUseSecondaryPasswordSystemFlag	= FALSE;	// 2008-08-26 by cmkwon, 베트남 VTC-Intecom_Viet 2차 패스워드 시스템 버그 수정 - FALSE로 설정
	}

	return m_Localization.LoadConfiguration((char*)LOCALIZATION_CONFIG_DIRECTORY_PATH, this->m_nLanguageType);
}

// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
BOOL CFieldGlobal::CheckAllowedAdminClientIP(char *i_szClientIP)
{
	if(IS_SCADMINTOOL_CONNECTABLE_IP(i_szClientIP))
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] CheckAllowedAccountClientIP ==> Allowed (%s) \r\n", i_szClientIP);
		return TRUE;
	}

	int LastVersion = m_AllowedAdminClientIPList_ReloadVersion.size();
	if ( 0 < LastVersion )
	{
		vector<string> tmAllowedAdminClientIPList = m_AllowedAdminClientIPList_ReloadVersion[LastVersion-1];
		for (int i = 0; i < tmAllowedAdminClientIPList.size(); i++)
		{
			if (0 == strncmp(tmAllowedAdminClientIPList[i].c_str(), i_szClientIP, strlen(tmAllowedAdminClientIPList[i].c_str())))
			{		
				g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] CheckAllowedAccountClientIP ==> Allowed (%s) \r\n", i_szClientIP);
				return TRUE;
			}
		}
	}
	
	g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] CheckAllowedAccountClientIP ==> Not Allowed (%s) !! \r\n", i_szClientIP);
	return FALSE;
}

BOOL CFieldGlobal::ReLoadConfiguration(void)
{
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	const int SIZE_BUFF = 512;
	char		buff[SIZE_BUFF];
	char		buffBackup[SIZE_BUFF];		// 2008-07-11 by cmkwon, MySQL 지원을 위해 수정(IP,Port 로 DB 서버 연결) - 
	const char	*token;
	char		seps[] = " \t";
	ifstream	fin;
	CConfig		config;
	
	if (!config.LoadUserDefinedVariables(GLOBAL_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration LoadUserDefinedVariables_1() error, FileName[%s]\r\n"
			, GLOBAL_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	if (!config.LoadUserDefinedVariables( FIELD_SERVER_CONFIG_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration LoadUserDefinedVariables_2() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	fin.open(FIELD_SERVER_CONFIG_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...
		
		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] ReLoadConfiguration open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, FIELD_SERVER_CONFIG_FILE_PATH);
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
		else if(0 == stricmp(token, "AllowedToolIP"))
		{
			
			token = config.strtok(NULL, seps);			
			if (token == NULL)
			{
				continue;
			}
			this->AddAllowedToolIP(token);
		}
		else if(0 == stricmp(token, "AllowedAdminClientIP"))
		{
			token = config.strtok(NULL, seps);			
			if(NULL == token || 0 == strcmp("", token))
			{
				continue;
			}
			m_AllowedAdminClientIPList.push_back(token);
			this->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] AllowedAdminClientIP Add (%s)\r\n", token);
		}
	}
	fin.close();

	this->ReLoad_AllowedToolIPList();

	if ( 0 < m_AllowedAdminClientIPList.size() )
	{
		m_AllowedAdminClientIPList_ReloadVersion.push_back(m_AllowedAdminClientIPList);
		g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] [S_ALLOWED_IP_RELOAD_JHSEOL] Reload AllowedAdminClientIP Count (%2d), AllowedAdminClientIPList Version (%d)\r\n", m_AllowedAdminClientIPList.size(), m_AllowedAdminClientIPList_ReloadVersion.size() );
		m_AllowedAdminClientIPList.clear();
	}

	return TRUE;
#else
	char	szError[1024];
	sprintf(szError, "[Error] No defined [S_ALLOWED_IP_RELOAD_JHSEOL] \r\n");
	this->WriteSystemLog(szError);
	return FALSE;
#endif
}
// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신

BOOL CFieldGlobal::SendLogFieldServer2LogServer(BYTE *szLogMsg, int nLength)
{
// 2009-04-20 by cmkwon, F2L 관련 시스템 수정 - 아래와 같이 수정함.
// 	int nIndex = m_nSendIndexF2LWSocket;
// 	if(false == m_vectorF2LWSocketPtr.empty())
// 	{
// 		m_nSendIndexF2LWSocket = (++m_nSendIndexF2LWSocket)%m_vectorF2LWSocketPtr.size();
// 		nIndex = nIndex%m_vectorF2LWSocketPtr.size();
// 		if (m_vectorF2LWSocketPtr[nIndex]->IsConnected())
// 		{
// 			int nSize = m_vectorF2LWSocketPtr[nIndex]->GetSendBufferCounts();
// 			if(nSize > 1000)
// 			{
// 				char szTemp[512];
// 				sprintf(szTemp, "[ERROR] LogError, Index(%3d) SendBufferSize(%4d)\r\n", nIndex, nSize);
// 				this->WriteSystemLog(szTemp);
// 			}
// 			if (m_vectorF2LWSocketPtr[nIndex]->Write(szLogMsg, nLength) == TRUE)
// 			{
// 				return TRUE;
// 			}
// 		}
// 	}
// 	char szTemp[512];
// 	sprintf(szTemp, "[ERROR] SendLogError, ArraySize(%2d) Index(%3d)\r\n"
// 		, m_vectorF2LWSocketPtr.size(), nIndex);
// 	this->WriteSystemLog(szTemp);
	///////////////////////////////////////////////////////////////////////////////
	// 2009-04-20 by cmkwon, F2L 관련 시스템 수정 - 아래같이 처리하게 수정
	if(m_vectorF2LWSocketPtr.empty())
	{
		g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [ERROR] Nothing F2L socket !! ArraySize(%d) \r\n", m_vectorF2LWSocketPtr.size());
		return FALSE;
	}

	int nCurF2LSocketIndex = m_nSendIndexF2LWSocket;
	for(int i = 0; i < SIZE_FIELD2LOG_WINSOCKET; i++)
	{
		int nIdx = (nCurF2LSocketIndex + i)%m_vectorF2LWSocketPtr.size();
		if(NULL == m_vectorF2LWSocketPtr[nIdx]
			|| FALSE == m_vectorF2LWSocketPtr[nIdx]->IsConnected())
		{
			continue;
		}
		int nSize = m_vectorF2LWSocketPtr[nIdx]->GetSendBufferCounts();
		if(nSize > 500)
		{
			g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] LogError, Index(%3d) CLogWinSocket(0x%X) SendBufferSize(%4d) \r\n", nIdx, m_vectorF2LWSocketPtr[nIdx], nSize);
		}
		if (m_vectorF2LWSocketPtr[nIdx]->Write(szLogMsg, nLength))
		{
			m_nSendIndexF2LWSocket = (++nIdx)%m_vectorF2LWSocketPtr.size();
			return TRUE;
		}
		g_pFieldGlobal->WriteSystemLogEX(TRUE, "[ERROR] F2L send to LogServer fail !!, Index(%3d) CLogWinSocket(0x%X) SendBufferSize(%4d), SockHandle(%d) IsConnected(%d) \r\n"
			, nIdx, m_vectorF2LWSocketPtr[nIdx], nSize, m_vectorF2LWSocketPtr[nIdx]->GetSocketHandle(), m_vectorF2LWSocketPtr[nIdx]->IsConnected());
	}

	g_pFieldGlobal->WriteSystemLogEX(TRUE, "[ERROR] F2L send to LogServer all fail !!, ArraySize(%d) \r\n", m_vectorF2LWSocketPtr.size());	
	return FALSE;
}

BOOL CFieldGlobal::SendLogFieldServer2LogServerORGFile(BYTE *szLogMsg, int nLength)
{
//	if(this->GetPtrFieldGameLogManager()->GetFileHandle() == NULL)
//	{
//		if(FALSE == this->GetPtrFieldGameLogManager()->InitLogManger(TRUE, "FieldGameLog", (char*)(string(CONFIG_ROOT) + "../log/GameLog/").c_str()))
//		{
//			return FALSE;
//		}
//	}
//	this->WriteGameLog(*(MessageType_t*)szLogMsg, (MSG_FL_LOG*)(szLogMsg+SIZE_FIELD_TYPE_HEADER), (char*)szLogMsg + MSG_SIZE(MSG_FL_LOG));

	return TRUE;
}


void CFieldGlobal::OnF2LAsyncEvent(SOCKET i_hSocket, LONG i_nEvent)
{
	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(m_vectorF2LWSocketPtr[i]
			&& m_vectorF2LWSocketPtr[i]->GetSocketHandle() == i_hSocket)
		{
			if(FD_CLOSE == WSAGETSELECTEVENT(i_nEvent))
			{
				// 2009-05-06 by cmkwon, 시스템 로그 추가(F2L관련) - 
				this->WriteSystemLogEX(TRUE, "[Notify] ON FD_Close(%s:%d) SockH(%ld) ErrorCode(%d) \r\n", m_vectorF2LWSocketPtr[i]->m_szPeerIP, m_vectorF2LWSocketPtr[i]->m_nPeerPort, m_vectorF2LWSocketPtr[i]->GetSocketHandle(), WSAGETSELECTERROR(i_nEvent));
			}
			m_vectorF2LWSocketPtr[i]->OnAsyncEvent(i_nEvent);
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2009-04-20 by cmkwon, F2L 관련 시스템 수정 - 
/// \author		cmkwon
/// \date		2009-04-20 ~ 2009-04-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::OnF2LClosed(CLogWinSocket *i_pF2LWinSoc)
{
	if(NULL == i_pF2LWinSoc)
	{
		return FALSE;
	}

	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(m_vectorF2LWSocketPtr[i]
			&& m_vectorF2LWSocketPtr[i] == i_pF2LWinSoc)
		{
			g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] F2L socket closed ! Index(%2d) CLogWinSocket(0x%X) \r\n", i, i_pF2LWinSoc);
			i_pF2LWinSoc->CloseSocket();			
			return TRUE;
		}
	}
	return FALSE;
}



///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::Send2PreServer(BYTE *i_pData, int i_nDataLen)
/// \brief		// 2007-11-19 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - CFieldGlobal::Send2PreServer() 추가
/// \author		cmkwon
/// \date		2008-01-31 ~ 2008-01-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::Send2PreServer(BYTE *i_pData, int i_nDataLen)
{
	CPreWinSocket *pF2PreSoc = this->GetField2PreWinSocket();
	if(NULL == pF2PreSoc
		|| FALSE == pF2PreSoc->IsConnected())
	{
		return FALSE;
	}

	return pF2PreSoc->Write(i_pData, i_nDataLen);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::LoadResObjCheckListW(BOOL i_bReloadOnlyRexTexDirectory/*=FALSE*/)
/// \brief		// 2008-09-08 by cmkwon, SCMonitor에서 ReloadVersionInfo시에 일부 체크섬파일(.\Res-Tex\*.*)도 리로드하기 - 
/// \author		cmkwon
/// \date		2008-09-08 ~ 2008-09-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::LoadResObjCheckListW(BOOL i_bReloadOnlyRexTexDirectory/*=FALSE*/)
{
	if(NULL == m_pGIOCP)
	{
		return FALSE;
	}

	CFieldIOCP *pFIOCP = (CFieldIOCP*)(m_pGIOCP);

	if(NULL == pFIOCP
		|| FALSE == pFIOCP->GetListeningFlag()
		|| FALSE == pFIOCP->GetServiceStartFlag())
	{
		return FALSE;
	}

	return pFIOCP->LoadResObjCheckList(i_bReloadOnlyRexTexDirectory);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::IsArenaServer(void)
/// \brief		// 2009-03-05 by cmkwon, 선전포고 아레나 서버 처리 - 
/// \author		cmkwon
/// \date		2009-03-05 ~ 2009-03-05
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::IsArenaServer(void)
{
	return m_sArenaServerInfo.ArenaFieldServerCheck;
}

BOOL CFieldGlobal::ConnectAllF2LWSocket(char *i_szSvrIP, int i_nSvrPort)
{
	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(m_vectorF2LWSocketPtr[i]
			&& FALSE == m_vectorF2LWSocketPtr[i]->IsConnected())
		{
			m_vectorF2LWSocketPtr[i]->Connect(i_szSvrIP, i_nSvrPort);
		}
	}

	return TRUE;
}

BOOL CFieldGlobal::ReConnectAllF2LWSocket(char *i_szSvrIP, int i_nSvrPort)
{
	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(m_vectorF2LWSocketPtr[i]
			&& INVALID_SOCKET == m_vectorF2LWSocketPtr[i]->GetSocketHandle())
		{
			m_vectorF2LWSocketPtr[i]->Connect(i_szSvrIP, i_nSvrPort);
		}
	}

	return TRUE;
}

BOOL CFieldGlobal::IsConnectedAllF2LWSocket(void)
{
	int nSize = m_vectorF2LWSocketPtr.size();
	for(int i=0; i < nSize; i++)
	{
		if(NULL == m_vectorF2LWSocketPtr[i]
			|| FALSE == m_vectorF2LWSocketPtr[i]->IsConnected())
		{
			return FALSE;
		}
	}

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::LoadPCBangIPListFromConfig()
/// \brief		PC방 리스트 로딩.
/// \author		dhjin
/// \date		2006-08-14 ~ 2006-08-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::LoadPCBangIPListFromConfig()
{

	const int	SIZE_BUFF = 1024;
	char		buff[SIZE_BUFF];
	const char	*token;
	char		seps[] = " \t";
	
	ifstream	fin;
	CConfig		config;

	if (!config.LoadUserDefinedVariables( PCBANG_IPADDR_FILE_PATH))
	{
		char	szError[1024];
		sprintf(szError, "[Error] LoadPCBangIPListFromConfig LoadUserDefinedVariables_2() error, FileName[%s]\r\n"
			, FIELD_SERVER_CONFIG_FILE_PATH);
		this->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	fin.open(PCBANG_IPADDR_FILE_PATH);
	if (!fin.is_open())
	{	// cannot open file...

		int nErr = GetLastError();
		SetLastError(0);
		char	szError[1024];
		sprintf(szError, "[Error] LoadPCBangIPListFromConfig open() error, LastError[%d] ConfigFileName[%s]\r\n"
			, nErr, PCBANG_IPADDR_FILE_PATH);
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

		token = strtok(buff, seps);

		if (token == NULL
			|| strncmp(token, "#", 1) == 0
			|| strncmp(token, "$", 1) == 0)
		{	// ignore blank lines
			// ignore comments
			// ignore user defined variables

			continue;
		}

		if (strchr(token,'~'))
		{
			char token0[SIZE_BUFF];
			strcpy(token0,token);
			char * pIPStart0 = strtok(token0,"~");
			char * pIPEndD   = strtok(NULL," \t");
			
			char * pIPClassA = strtok(pIPStart0,".");
			char * pIPClassB = strtok(NULL,".");
			char * pIPClassC = strtok(NULL,".");
			char * pIPClassD = strtok(NULL," \t");
			
			int iIPStartA	 = atoi(pIPClassA);
			int iIPStartB	 = atoi(pIPClassB);
			int iIPStartC	 = atoi(pIPClassC);
			int iIPStartD	 = atoi(pIPClassD);
			int iIPEndD		 = atoi(pIPEndD);
			
			if (FALSE == IS_IN_RANGE(0, iIPStartA, 255) ||
				FALSE == IS_IN_RANGE(0, iIPStartB, 255) ||
				FALSE == IS_IN_RANGE(0, iIPStartC, 255) ||
				FALSE == IS_IN_RANGE(0, iIPStartD, 255))
			{
				char	szError[1024];
				sprintf(szError, "[Error] LoadPCBangIPListFromConfig open() error, ConfigFileName[%s] ==> %s\r\n"
					, PCBANG_IPADDR_FILE_PATH, token);
				this->WriteSystemLog(szError);
				DBGOUT(szError);
				return FALSE;
			}			
			
			int IPClassDGap	 = (iIPEndD - iIPStartD);

			if ( 0 > IPClassDGap)
			{
				char	szError[1024];
				sprintf(szError, "[Error] LoadPCBangIPListFromConfig open() error, ConfigFileName[%s] ==> %s\r\n"
					, PCBANG_IPADDR_FILE_PATH, token);
				this->WriteSystemLog(szError);
				DBGOUT(szError);
				return FALSE;
			}
			
			for (int i=0 ; i <= IPClassDGap; i++)
			{				
				char szIP[SIZE_BUFF];
				sprintf(szIP, "%d.%d.%d.%d", iIPStartA, iIPStartB, iIPStartC, iIPStartD+i);
				m_setPCBangIPList.insert(szIP);
			}
			
			continue;
		}

		char token0[SIZE_BUFF];
		strcpy(token0,token);
	
		char * pIPClassA = strtok(token0,".");
		char * pIPClassB = strtok(NULL,".");
		char * pIPClassC = strtok(NULL,".");
		char * pIPClassD = strtok(NULL," \t");
		
		int iIPStartA	 = atoi(pIPClassA);
		int iIPStartB	 = atoi(pIPClassB);
		int iIPStartC	 = atoi(pIPClassC);
		int iIPStartD	 = atoi(pIPClassD);

		if (FALSE == IS_IN_RANGE(0, iIPStartA, 255) ||
			FALSE == IS_IN_RANGE(0, iIPStartB, 255) ||
			FALSE == IS_IN_RANGE(0, iIPStartC, 255) ||
			FALSE == IS_IN_RANGE(0, iIPStartD, 255))
		{
			char	szError[1024];
			sprintf(szError, "[Error] LoadPCBangIPListFromConfig open() error, ConfigFileName[%s] ==> %s\r\n"
				, PCBANG_IPADDR_FILE_PATH, token);
			this->WriteSystemLog(szError);
			DBGOUT(szError);
			return FALSE;
		}

		char szIP[SIZE_BUFF];
		sprintf(szIP, "%d.%d.%d.%d", iIPStartA, iIPStartB, iIPStartC, iIPStartD);
		m_setPCBangIPList.insert(szIP);
	}

	fin.close();
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::GetUseSecondaryPasswordSystemFlag(void)
/// \brief		// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - CFieldGlobal 에 멤버 함수 추가
/// \author		cmkwon
/// \date		2007-09-12 ~ 2007-09-12
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::GetUseSecondaryPasswordSystemFlag(void)
{
	return m_bUseSecondaryPasswordSystemFlag;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CFieldGlobal::SetDBServerGroup(SDBSERVER_GROUP *i_pDBServGroup)
/// \brief		// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - CFieldGlobal::SetDBServerGroup() 추가
/// \author		cmkwon
/// \date		2008-04-29 ~ 2008-04-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CFieldGlobal::SetDBServerGroup(SDBSERVER_GROUP *i_pDBServGroup)
{
	m_DBServerGroup		= *i_pDBServGroup;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetBillingDBServerIP(void)
/// \brief		// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
/// \author		cmkwon
/// \date		2008-07-30 ~ 2008-07-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetBillingDBServerIP(void)
{
	return m_szBillingDBServerIP;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			int CFieldGlobal::GetBillingDBServerPort(void)
/// \brief		// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
/// \author		cmkwon
/// \date		2008-07-30 ~ 2008-07-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
int CFieldGlobal::GetBillingDBServerPort(void)
{
	return m_nBillingDBServerPort;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetBillingDBServerDatabaseName(void)
/// \brief		// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
/// \author		cmkwon
/// \date		2008-07-30 ~ 2008-07-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetBillingDBServerDatabaseName(void)
{
	return m_szBillingDBServerDatabaseName;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetBillingDBServerUserID(void)
/// \brief		// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
/// \author		cmkwon
/// \date		2008-07-30 ~ 2008-07-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetBillingDBServerUserID(void)
{
	return m_szBillingDBServerUserID;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			char *CFieldGlobal::GetBillingDBServerPassword(void)
/// \brief		// 2008-07-30 by cmkwon, Yedang_Kor 빌링 DBServer 직접 연결하도록 수정 - 
/// \author		cmkwon
/// \date		2008-07-30 ~ 2008-07-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
char *CFieldGlobal::GetBillingDBServerPassword(void)
{
	return m_szBillingDBServerPassword;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CFieldGlobal::SendArenaServerMFSInfo()
/// \brief		아레나 통합 - 아레나 서버로 필드 서버 정보 전송
/// \author		dhjin
/// \date		2008-01-17 ~ 2008-01-17
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CFieldGlobal::SendArenaServerMFSInfo()
{
	// 2009-04-17 by cmkwon, 통합Arena 관련 버그 수정 - CFieldGlobal::InitServerSocket()에서 설정하게 수정
	//m_pField2ArenaFieldWinSocket->SetFieldIOCP(((CFieldIOCP*)m_pGIOCP));

	// 2007-12-27 by dhjin, 아레나 통합 - 아레나 서버에 필드 서버 정보 전송
	INIT_MSG_WITH_BUFFER(MSG_FtoA_MFSINFO, T_FtoA_MFSINFO, pMsgFtoAConn, FtoASendBuf);
	pMsgFtoAConn->MFS_ID	= this->GetMGameServerID();
	pMsgFtoAConn->MFS_Port	= this->GetPortListening();
	STRNCPY_MEMSET(pMsgFtoAConn->MFS_Name, this->GetFieldServerGroupName(), SIZE_MAX_SERVER_NAME);
	STRNCPY_MEMSET(pMsgFtoAConn->MFS_IP, this->GetPublicIPLocal(), SIZE_MAX_IPADDRESS);

	m_pField2ArenaFieldWinSocket->Write((char*)FtoASendBuf, MSG_SIZE(MSG_FtoA_MFSINFO));
	this->WriteSystemLogEX(FALSE, "[Notify] CFieldGlobal::InitServerSocket_ send to ArenaServer !!\r\n");	// 2013-10-16 by jhseol, 서버 디버깅시 불필요 DBGOUT 출력 코드 제거
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::GetUseInflSelectionRestrictSystem(void)
/// \brief		// 2009-06-03 by cmkwon, 세력 선택시 제한 시스템 사용 여부 플래그 추가 - 
/// \author		cmkwon
/// \date		2009-06-03 ~ 2009-06-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::GetUseInflSelectionRestrictSystem(void)
{
	return m_bUseInflSelectionRestrictSystem;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CFieldGlobal::SetUseInflSelectionRestrictSystem(BOOL i_bFlag)
/// \brief		// 2009-06-03 by cmkwon, 세력 선택시 제한 시스템 사용 여부 플래그 추가 - 
/// \author		cmkwon
/// \date		2009-06-03 ~ 2009-06-03
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CFieldGlobal::SetUseInflSelectionRestrictSystem(BOOL i_bFlag)
{
	m_bUseInflSelectionRestrictSystem	= i_bFlag;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CFieldGlobal::checkSHUTDOWNMINORS(int i_birthdayYears /* 생일 */ , ATUM_DATE_TIME currentTime/* 현재 시간 */)
/// \brief		// start 2011-11-03 by shcho, yedang 셧다운제 구현
/// \author		shcho
/// \date		20111110 ~
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CFieldGlobal::checkSHUTDOWNMINORS(int i_birthdayYears /* 생일 */ , ATUM_DATE_TIME currentTime/* 현재 시간 */) 
{ // 년도별 체크 함수
	int nCurrentTime = (currentTime.Year*10000)+(currentTime.Month*100)+(currentTime.Day);
	
	if(10000 > i_birthdayYears)
	{ // 년도일때 
		i_birthdayYears = i_birthdayYears * 10000; // 만 16세 (17살)
	}
	
	// 아니면 무조껀 수행한다.
	if(160000 <= nCurrentTime-i_birthdayYears)
	{ // 성인 
		return FALSE;
	}
	else
	{ // 16세 미만 
		return TRUE;
	}
}

// 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어
BOOL CFieldGlobal::CheckAllowedNPCServerIP(char *i_szIP)
{
	if (0 == strncmp(this->GetIPNPCServer(), i_szIP, strlen(this->GetIPNPCServer())))
	{		
		return TRUE;
	}

	g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [Notify] CheckAllowedNPCServerIP ==> Not Allowed (%s) !!\r\n", i_szIP);

	return FALSE;
}
// end 2013-04-01 by hskim, NPCServer 패킷으로 위조 공격 방어