// PreIOCPSocket.cpp: implementation of the CPreIOCPSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreIOCPSocket.h"
#include "PreIOCP.h"
#include "PreGlobal.h"
#include "AtumError.h"
#include "AccountBlockManager.h"
#include "SecurityManager.h"		// 2011-06-22 by hskim, �缳 ���� ����
#include "AtumSJ.h"					// 2012-06-07 by hskim, ������ ���� ���� ��ȭ - ���� ���� ����� �α� ����
#include "SelectiveShutdown.h"		// 2012-07-11 by hskim, ������ �˴ٿ�
#include "NPlayPCBangModule.h"		// 2012-10-05 by jhseol, NPlay pc�� ���

#define ARENA_SERVER_GROUP_NAME		"ARENA"		// 2012-10-05 by jhseol, NPlay pc�� ��� - �Ʒ��� ���� �׷����

CPreIOCP		*CPreIOCPSocket::ms_pPreIOCP = NULL;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPreIOCPSocket::CPreIOCPSocket()
{
	SetClientState(CP_NOTCONNECTED, NULL);
	m_PeerSocketType	= ST_INVALID_TYPE;
	MEMSET_ZERO(m_szConnectedServerGroupName, SIZE_MAX_SERVER_NAME);

	m_eOtherPublisherConncect = CONNECT_PUBLISHER_DEFAULT;				// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
}

CPreIOCPSocket::~CPreIOCPSocket()
{
}

BOOL CPreIOCPSocket::OnRecvdPacketPreServer(const char* pPacket, int nLength, BYTE nSeq, char* pPeerIP, int nPeerPort, SThreadInfo *i_pThreadInfo)
{
	BYTE			SendBuf[SIZE_MAX_PACKET];
	int				nBytesUsed		= 0;
	MessageType_t	nRecvType		= 0;
	ProcessResult	procRes			= RES_BREAK;
	int				tmpSeq;
	MessageType_t	nOldRecvType	= 0;			// 2007-04-02 by cmkwon

	// TCP ó�� ��ƾ
	if(m_bPeerSequenceNumberInitFlag == FALSE)
	{
		tmpSeq = (nSeq + SEQNO_VAR_A) * SEQNO_VAR_B;
		if(tmpSeq > SEQNO_VAR_C)
		{
			tmpSeq = tmpSeq % SEQNO_VAR_C;
		}
		m_byPeerSequenceNumber = ++tmpSeq;
		m_bPeerSequenceNumberInitFlag = TRUE;
	}
	else
	{
		if(m_byPeerSequenceNumber != nSeq)
		{
			// Protocl Error ó��
			// - ���� ��Ŷ�� Sequence Number�� ��ȿ���� ����
			// Error Code : ERR_PROTOCOL_INVALID_SEQUENCE_NUMBER
			SendErrorMessage(T_PRE_IOCP, ERR_PROTOCOL_INVALID_SEQUENCE_NUMBER);
			Close(0x11000, TRUE);
			return FALSE;
		}
		tmpSeq = (nSeq + SEQNO_VAR_A) * SEQNO_VAR_B;
		if(tmpSeq > SEQNO_VAR_C)
		{
			tmpSeq = tmpSeq % SEQNO_VAR_C;
		}
		m_byPeerSequenceNumber = ++tmpSeq;
	} // end TCP ó�� ��ƾ


	while(this->IsUsing() && nBytesUsed < nLength)
	{
		nRecvType = *(MessageType_t*)(pPacket+nBytesUsed);
		nBytesUsed += SIZE_FIELD_TYPE_HEADER;

		if(i_pThreadInfo)
		{
			i_pThreadInfo->dwSocketIndex = m_nClientArrayIndex;
			i_pThreadInfo->dwMessageType = nRecvType;
		}


#ifdef _DEBUG
		PrintExchangeMsg(RECV_TYPE, nRecvType, m_szPeerIP, m_PeerSocketType, GGetexchangeMsgPrintLevel());
#endif

		// ������Ʈ���� ���� ��� ���񽺸� �ߴ��Ѵ�.
		if(ms_pPreIOCP->m_bPauseService &&
			(HIBYTE(nRecvType) == T0_PC_CONNECT || HIBYTE(nRecvType) == T0_PC_DEFAULT_UPDATE)
		)
		{
			// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - �Ʒ��� ���� ���� ��
			//if(FALSE == IS_SCADMINTOOL_CONNECTABLE_IP(this->GetPeerIP()))
			if(FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))	// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
			{
				SendErrorMessage(T_ERROR, ERR_COMMON_SERVICE_TEMPORARILY_PAUSED, 0, 0, this->GetPeerIP());
				return TRUE;
			}
		}

#ifdef S_EP4_DEBUG_HSKIM
// start 2011-10-10 by hskim, EP4 [���� �����]
		g_pGlobal->WriteSystemLogEX(TRUE, "[Debug Info] Type(%s) IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
		// end 2011-10-10 by hskim, EP4 [���� �����]
#endif	
		
#ifdef SC_ANTI_HACKING_CODE_BCKIM_JWLEE		// 2015-07-07 by bckim, �������� ��ŷ���� ����Ÿ��Ȯ��
		
		switch(nRecvType)
		{
		case T_PC_CONNECT_ALIVE:
		case T_FP_CONNECT_ALIVE:
		case T_IP_CONNECT_ALIVE:
		case T_PM_CONNECT_ALIVE:
		case T_IM_CONNECT_ALIVE:
		case T_FM_CONNECT_ALIVE:
		case T_NM_CONNECT_ALIVE:			
		case T_PA_ADMIN_CONNECT:
		case T_PC_CONNECT_LOGIN:
		case T_FP_CONNECT_FIELD_CONNECT:
		case T_IP_CONNECT_IM_CONNECT:
		case T_PM_CONNECT:			
		case T_IP_GET_SERVER_GROUP_INFO_ACK:
		case T_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST:	// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �߰��� �������� Ÿ�� ó��
			{				
				break;		// ��� 
			}
			
			// Server <-- AdminTool
		case T_PA_ADMIN_GET_ACCOUNT_INFO:
		case T_PA_ADMIN_BLOCK_ACCOUNT:
		case T_PA_ADMIN_UNBLOCK_ACCOUNT:
		case T_PA_ADMIN_LOG_ACCOUNT_ACCOUNTTYPE_CHANGE:
		case T_PA_ADMIN_LOG_CHARACTER_RACEACCOUNTTYPE_CHANGE:
		case T_PA_ADMIN_STRATRGYPOINT_INFO_CHANGE:
		case T_PA_ADMIN_GET_SERVER_INFO:
		case T_PA_ADMIN_GET_ACCOUNT_LIST:
		case T_PA_ADMIN_RELOAD_HAPPYEV:		// 2006-08-28 by cmkwon
		case T_PA_ADMIN_RELOAD_ITEMEV:
		case T_PA_ADMIN_RELOAD_GUILD_INFO:
		case T_PA_ADMIN_UPDATE_STRATEGYPOINT_NOTSUMMONTIME:
		case T_PA_ADMIN_PETITION_SET_PERIOD:		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
		case T_PA_ADMIN_SET_DBSERVER_GROUP:			// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
		case T_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM:		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - 
		case T_PA_ADMIN_RELOAD_WORLDRANKING:		// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
		case T_PA_ADMIN_RELOAD_INFLUENCERATE:		// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
			{	// �������  ������ Ȯ��.  ��� ������ Ȯ��. 				
				if( FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))		// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE1_Abnormal] type(%s) Input_IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
					Close(0x12000);
					return FALSE ;	
				}
				break;				
			}	
			///////////////////////////////////////////////////////////////////////
		// Pre Server <--> Client
		
			/*
			
			// case T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK:
		//case T_PC_CONNECT_VERSION:
		//case T_PC_DEFAULT_UPDATE_LAUNCHER_VERSION:
		//case T_PC_CONNECT_GET_SERVER_GROUP_LIST:
		//case T_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST:		// 2007-05-02 by cmkwon
		//case T_PC_CONNECT_NETWORK_CHECK:		// 2007-06-18 by cmkwon, ��Ʈ��ũ ���� üũ
				{	// Ŭ���̾�Ʈ ���� Ÿ�� Ȯ��. 
				if( ST_INVALID_TYPE == m_PeerSocketType )
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE2_Abnormal] type(%s) Input_IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
					Close(0x12000);
					return FALSE ;
				}
				break;
			}
			*/ 
			
			///////////////////////////////////////////////////////////////////////
			// Field Server <--> Pre Server
		// case T_FP_CONNECT_AUTH_USER:			
		case T_FP_CONNECT_NOTIFY_CLOSE:
		case T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE:
		case T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK:	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
		// case T_FP_EVENT_ENTER_SELECT_SCREEN:
		case T_FP_EVENT_GAME_STARTED:
		// case T_FP_EVENT_MAP_CHANGED:
		case T_FP_CASH_CHANGE_CHARACTERNAME:
		case T_FP_ADMIN_BLOCKACCOUNT:		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
		case T_FP_ADMIN_UNBLOCKACCOUNT:		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
		case T_FP_AUTHENTICATION_SHUTDOWN:
			{	// �ʵ弭�� ������ Ȯ�� 
				BOOL ret = FALSE;
				vector<CServerGroup*>::iterator itr(ms_pPreIOCP->GetAllServerGroupVector()->begin());
				while (itr != ms_pPreIOCP->GetAllServerGroupVector()->end() )
				{
					if( TRUE == (*itr)->m_bEnableServerGroup && ST_FIELD_SERVER == m_PeerSocketType )
					{
						CServerGroup* temp = (*itr);
						if (strnicmp( (*itr)->m_FieldServerInfo.pSocket->GetPeerIP(), this->GetPeerIP(), SIZE_MAX_IPADDRESS) == 0)
						{				
							g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE3_Normal] type(%s), m_FieldServerInfo(%15s), InputIP(%15s) \r\n",GetProtocolTypeString(nRecvType),(*itr)->m_FieldServerInfo.pSocket->GetPeerIP(), this->GetPeerIP());
							ret = TRUE;
							break;
						}
					}
					itr++;
				}				

				if( FALSE == ret )
				{		
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE3_Abnormal] type(%s) Input_IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
					Close(0x12000);
					return FALSE ;
				}
				break;				
			}
			
			///////////////////////////////////////////////////////////////////////
			// IM Server <--> Pre Server		
		case T_IP_AUTHENTICATION_SHUTDOWN:
			{	// IM ���� ������ Ȯ�� 				
				vector<CServerGroup*>::iterator itr(ms_pPreIOCP->GetAllServerGroupVector()->begin());
				while (itr != ms_pPreIOCP->GetAllServerGroupVector()->end())
				{
					if (strnicmp( (*itr)->m_IMServerInfo.pSocket->GetPeerIP(), this->GetPeerIP(), SIZE_MAX_IPADDRESS) == 0)
					{				
						g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE4_Normal] type(%s), IMserverIP(%15s), InputIP(%15s) \r\n",GetProtocolTypeString(nRecvType), (*itr)->m_IMServerInfo.pSocket->GetPeerIP(), this->GetPeerIP());
						break;
					}
					itr++;
				}
				g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE4_Abnormal] type(%s) Input_IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
				Close(0x12000);
				return FALSE ;			
			}
			
			//////////////////////////////////////////////////////////////////////
			// PreServer <-- Monitor			
		case T_PM_GET_NUM_CLIENTS:
		case T_PM_SHUTDOWN:
		case T_PM_PING:
		case T_PM_RELOAD_VERSION_INFO:
		case T_PM_RELOAD_BLOCKED_ACCOUNTS:
		case T_PM_CHANGE_BANDWIDTH_FLAG:
		case T_PM_SET_MSG_PRINT_LEVEL:
		case T_PM_PAUSE_SERVICE:
		case T_PM_START_SERVICE:
		case T_PM_GET_SERVER_GROUP_INFO:
		case T_PM_SET_LIMIT_GROUP_USER_COUNTS:
		case T_PM_SET_MGAME_EVENT_TYPE:
		case T_PM_CHANGE_ENABLE_SERVER_GROUP:
		case T_PM_PREPARE_SHUTDOWN:
		case T_PM_RELOAD_VERSION_INFO_HEADER:		// 2007-01-09 by cmkwon
		case T_PM_RELOAD_VERSION_INFO_LIST:			// 2007-01-09 by cmkwon
		case T_PM_RELOAD_VERSION_INFO_DONE:			// 2007-01-09 by cmkwon
			{	// �������  ������ Ȯ��.  ��� ������ Ȯ��. 				
				if( FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))		// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ANTI_HACKING_CODE_PRE5_Abnormal] type(%s), Input_IP(%15s)\r\n", GetProtocolTypeString(nRecvType), this->GetPeerIP());
					Close(0x12000);
					return FALSE ;	
				}
				break;				
			}	
		}
#endif	// End. 2015-07-07 by bckim, �������� ��ŷ���� ����Ÿ��Ȯ��		


		switch(nRecvType)
		{
		///////////////////////////////////////////////////////////////////////
		// Pre Server <-- Client, PreServer <-- FieldServer, PreServer <-- IMServer, PreServer <-- MonitorServer
		case T_PC_CONNECT_ALIVE:
		case T_FP_CONNECT_ALIVE:
		case T_IP_CONNECT_ALIVE:
		case T_PM_CONNECT_ALIVE:
		case T_IM_CONNECT_ALIVE:
		case T_FM_CONNECT_ALIVE:
		case T_NM_CONNECT_ALIVE:
			OnRecvdAlivePacket();
			procRes = RES_RETURN_TRUE;
			break;
		//////////////////////////////////////////////////////////////////
		// Server <-- AdminTool
		case T_PA_ADMIN_CONNECT:
			{
				MSG_PA_ADMIN_CONNECT* msgAdminConnect = (MSG_PA_ADMIN_CONNECT*)(pPacket + nBytesUsed);		// 2011-07-21 by hskim, ���� ���� ���� - ���� ������ ȣȯ �ȵǵ��� ����ü ũ�� �ٲ� (�߰� ���� ���� ����)
				nBytesUsed += sizeof(MSG_PA_ADMIN_CONNECT);		// 2011-07-21 by hskim, ���� ���� ���� - ���� ������ ȣȯ �ȵǵ��� ����ü ũ�� �ٲ� (�߰� ���� ���� ����)

				// �����ϱ�
				INIT_MSG(MSG_PA_ADMIN_CONNECT_OK, T_PA_ADMIN_CONNECT_OK, msgAdminConnectOK, SendBuf);
				// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - �Ʒ��� ���� ���� ��
				//if(IS_SCADMINTOOL_CONNECTABLE_IP(GetPeerIP()))
				if(g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))		// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
				{
					STRNCPY_MEMSET(m_szAdminAccountName, msgAdminConnect->UID, SIZE_MAX_ACCOUNT_NAME);		// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�
					msgAdminConnectOK->AccountType0 = g_pGlobalGameServer->AuthAdminToolUser(msgAdminConnect->UID, msgAdminConnect->PWD);
				}

				///////////////////////////////////////////////////////////////////////////////
				// 2007-11-01 by cmkwon, �ý��� �α� �߰�
				g_pGlobal->WriteSystemLogEX(TRUE, "[Notify] SCAdminTool connected !!, AccountName(%s) IP(%s) AccountType(%d)\r\n"
													, msgAdminConnect->UID, GetPeerIP(), msgAdminConnectOK->AccountType0);
				// 2012-06-16 by jhseol, �Ʒ��� �߰�����part2 - ���� : ���� ���ΰ� �ƴϸ� ��� �Ұ�
#ifdef SC_ARENA_EX_1ST_JHSEOL_MSPARK
				if(FALSE == strncmp(GetPeerIP(), MASANG_PREFIX_IP1, 9))
				{
					msgAdminConnectOK->IsMasang = TRUE;
				}
				else msgAdminConnectOK->IsMasang = FALSE;
#endif
				// end 2012-06-16 by jhseol, �Ʒ��� �߰�����part2 - ���� : ���� ���ΰ� �ƴϸ� ��� �Ұ�

				SendAddData(SendBuf, MSG_SIZE(MSG_PA_ADMIN_CONNECT_OK));

//				if (!bRet)
//				{
//					procRes = RES_RETURN_FALSE;
//					Close();
//				}

				// ���� ����
				m_PeerSocketType = ST_ADMIN_TOOL;

				ms_pPreIOCP->InsertMonitorIOCPSocketPtr(this);
			}
			break;
		case T_PA_ADMIN_GET_ACCOUNT_INFO:
			{
				MSG_PA_ADMIN_GET_ACCOUNT_INFO* msgAdminGetCharac = (MSG_PA_ADMIN_GET_ACCOUNT_INFO*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_GET_ACCOUNT_INFO);

				INIT_MSG(MSG_PA_ADMIN_GET_ACCOUNT_INFO_OK, T_PA_ADMIN_GET_ACCOUNT_INFO_OK, msgAdminGetCharacOK, SendBuf);

				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_GET_ACCOUNT_INFO Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.

				CAccountInfo tmAccountInfo;
				msgAdminGetCharacOK->IsBlocked			= ms_pPreIOCP->m_pAccountBlockManager->IsCheckBlockedAccountInfoByAccountName(&msgAdminGetCharacOK->BlockedAccountInfo, msgAdminGetCharac->AccountName, this);
				if (FALSE == ms_pPreIOCP->GetAccountInfo(&tmAccountInfo, msgAdminGetCharac->AccountName))
				{
					msgAdminGetCharacOK->IsOnline		= FALSE;
					STRNCPY_MEMSET(msgAdminGetCharacOK->AccountInfo.AccountName, msgAdminGetCharac->AccountName, SIZE_MAX_ACCOUNT_NAME);
				}
				else
				{
					msgAdminGetCharacOK->IsOnline		= TRUE;
					msgAdminGetCharacOK->AccountInfo	= tmAccountInfo;
				}
				SendAddData(SendBuf, MSG_SIZE(MSG_PA_ADMIN_GET_ACCOUNT_INFO_OK));
			}
			break;
// 2005-06-02 by cmkwon, ������� �ʴ� Protocol Type
//		case T_PA_ADMIN_DISCONNECT_USER:
//			{
//				MSG_PA_ADMIN_DISCONNECT_USER* msgDisconnect = (MSG_PA_ADMIN_DISCONNECT_USER*)(pPacket + nBytesUsed);
//				nBytesUsed += sizeof(MSG_PA_ADMIN_DISCONNECT_USER);
//
//				CAccountInfo tmAccountInfo;
//				if (FALSE == ms_pPreIOCP->GetAccountInfo(&tmAccountInfo, msgDisconnect->AccountName))
//				{
//					INIT_MSG(MSG_PA_ADMIN_GET_ACCOUNT_INFO_OK, T_PA_ADMIN_GET_ACCOUNT_INFO_OK, msgAdminGetCharacOK, SendBuf);
//					MEMSET_ZERO(msgAdminGetCharacOK, sizeof(MSG_PA_ADMIN_GET_ACCOUNT_INFO_OK));
//					msgAdminGetCharacOK->IsOnline = FALSE;
//					msgAdminGetCharacOK->IsBlocked = (ms_pPreIOCP->m_setBlockedAccounts.findLock_Ptr(msgDisconnect->AccountName) != NULL);
//					SendAddData(SendBuf, MSG_SIZE(MSG_PA_ADMIN_GET_ACCOUNT_INFO_OK));
//				}
//				else
//				{
//					if (!ms_pPreIOCP->BlockAccount(msgDisconnect->AccountName, this, TRUE))
//					{
//						// error
//					}
//				}
//			}
//			break;
		case T_PA_ADMIN_BLOCK_ACCOUNT:
			{
				MSG_PA_ADMIN_BLOCK_ACCOUNT* msgBlockAcc = (MSG_PA_ADMIN_BLOCK_ACCOUNT*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_BLOCK_ACCOUNT);

				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.
				if(FALSE ==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect Account Block Command Using: HackingIP(%15s) AdminAccountName(%20s), BlockedUserAccName(%20s) \r\n"
						, this->GetPeerIP(), m_szAdminAccountName, msgBlockAcc->szBlockedAccountName);
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.

				///////////////////////////////////////////////////////////////////////////////
				// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�
				g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Account Block: AdminIP(%15s) AdminAccountName(%20s), BlockedUserAccName(%20s) Period(%s ~ %s)\r\n"
					, this->GetPeerIP(), m_szAdminAccountName, msgBlockAcc->szBlockedAccountName
					, msgBlockAcc->atimeStartTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING))
					, msgBlockAcc->atimeEndTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));

				ms_pPreIOCP->BlockAccount(msgBlockAcc, this, TRUE);
			}
			break;
		case T_PA_ADMIN_UNBLOCK_ACCOUNT:
			{
				MSG_PA_ADMIN_UNBLOCK_ACCOUNT* msgUnblockAcc = (MSG_PA_ADMIN_UNBLOCK_ACCOUNT*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_UNBLOCK_ACCOUNT);

				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect Account UnBlock Command Using: HackingIP(%15s) AdminAccountName(%20s), UnBlockedUserAccName(%20s)\r\n"
						, this->GetPeerIP(), m_szAdminAccountName, msgUnblockAcc->szBlockedAccountName);
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.

				///////////////////////////////////////////////////////////////////////////////
				// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�
				g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Account Block Cancellation: AdminIP(%15s) AdminAccountName(%20s), UserAccName(%20s)\r\n"
					, this->GetPeerIP(), m_szAdminAccountName, msgUnblockAcc->szBlockedAccountName);

				msgUnblockAcc->atimeEndTime.SetCurrentDateTime();	// 2008-01-30 by cmkwon, ���� �� �α� ����� ���� - 
				ms_pPreIOCP->UnblockAccount(msgUnblockAcc, this);
			}
			break;

			// 2012-06-07 by hskim, ������ ���� ���� ��ȭ - ���� ���� ����� �α� ����
		case T_PA_ADMIN_LOG_ACCOUNT_ACCOUNTTYPE_CHANGE:
			{
				MSG_PA_ADMIN_LOG_ACCOUNT_ACCOUNTTYPE_CHANGE* msgAccTypeChange = (MSG_PA_ADMIN_LOG_ACCOUNT_ACCOUNTTYPE_CHANGE*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_LOG_ACCOUNT_ACCOUNTTYPE_CHANGE);

				char szAccountName[SIZE_MAX_ACCOUNT_NAME + 1] = { 0, };		
				STRNCPY_MEMSET(szAccountName, msgAccTypeChange->AccountName, SIZE_MAX_ACCOUNT_NAME);			

				g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Change Account AccountType : AdminIP(%s) AdminAccountName(%s), UserAccName(%s:%d) AccountType(%s => %s)\r\n"
					, this->GetPeerIP(), m_szAdminAccountName, 
					szAccountName, msgAccTypeChange->AccountUniqueNumber,
					CAtumSJ::GetRaceString(msgAccTypeChange->OldAccountType), CAtumSJ::GetRaceString(msgAccTypeChange->NewAccountType));
			}
			break;

		case T_PA_ADMIN_LOG_CHARACTER_RACEACCOUNTTYPE_CHANGE:
			{
				MSG_PA_ADMIN_LOG_CHARACTER_RACEACCOUNTTYPE_CHANGE* msgRaceAccTypeChange = (MSG_PA_ADMIN_LOG_CHARACTER_RACEACCOUNTTYPE_CHANGE*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_LOG_CHARACTER_RACEACCOUNTTYPE_CHANGE);

				char szAccountName[SIZE_MAX_ACCOUNT_NAME + 1] = { 0, };
				char szCharacterName[SIZE_MAX_CHARACTER_NAME + 1] = { 0, };
				
				STRNCPY_MEMSET(szAccountName, msgRaceAccTypeChange->AccountName, SIZE_MAX_ACCOUNT_NAME);			
				STRNCPY_MEMSET(szCharacterName, msgRaceAccTypeChange->CharacterName, SIZE_MAX_CHARACTER_NAME);

				g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Change Character RaceAccountType : AdminIP(%s) AdminAccountName(%s), UserAccName(%s:%d) UserCharName(%s:%d) AccountType(%s => %s)\r\n"
					, this->GetPeerIP(), m_szAdminAccountName, 
					szAccountName, msgRaceAccTypeChange->AccountUniqueNumber,
					szCharacterName, msgRaceAccTypeChange->CharacterUniqueNumber,
					CAtumSJ::GetRaceString(msgRaceAccTypeChange->OldAccountType), CAtumSJ::GetRaceString(msgRaceAccTypeChange->NewAccountType));
			}
			break;
			// end 2012-06-07 by hskim, ������ ���� ���� ��ȭ - ���� ���� ����� �α� ����

			////////////////////////////////////////////////////////////////////////////
			// 2012-11-13 by jhseol, ���� �ý��� ������ - ������
		case T_PA_ADMIN_STRATRGYPOINT_INFO_CHANGE:
			{
				MSG_PA_ADMIN_STRATRGYPOINT_INFO_CHANGE* msgStratrgyPointInfoChange = (MSG_PA_ADMIN_STRATRGYPOINT_INFO_CHANGE*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_STRATRGYPOINT_INFO_CHANGE);

				INIT_MSG_WITH_BUFFER(MSG_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE, T_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE, pSend, SendBuf);
				STRNCPY_MEMSET(pSend->DBName, msgStratrgyPointInfoChange->DBName, sizeof(pSend->DBName));
				ms_pPreIOCP->SendMessageToAllFieldServer(SendBuf, MSG_SIZE(MSG_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE));
				g_pPreGlobal->WriteSystemLogEX(FALSE, "  [Notify] S_WAR_SYSTEM_RENEWAL_STRATEGYPOINT_JHSEOL #Recvd & FieldServer Send Packet - DBName(%s)\r\n", msgStratrgyPointInfoChange->DBName);
			}
			// end 2012-11-13 by jhseol, ���� �ý��� ������ - ������

		case T_PA_ADMIN_GET_SERVER_INFO:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_GET_SERVER_INFO Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				// no body
				ms_pPreIOCP->SendServerInfoForAdmin(this);
			}
			break;
		case T_PA_ADMIN_GET_ACCOUNT_LIST:
			{
				MSG_PA_ADMIN_GET_ACCOUNT_LIST * msgGetAccList = (MSG_PA_ADMIN_GET_ACCOUNT_LIST*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PA_ADMIN_GET_ACCOUNT_LIST);

				INIT_MSG(MSG_PA_ADMIN_GET_ACCOUNT_LIST_OK, T_PA_ADMIN_GET_ACCOUNT_LIST_OK, msgGetOK, SendBuf);
				
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_GET_ACCOUNT_LIST Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.

				msgGetOK->NumOfAccounts = 0;
				CServerGroup *pServerGroup = ms_pPreIOCP->GetServerGroup(msgGetAccList->ServerName);

				pServerGroup->m_setLoginedAccount.lock();
				{
					mt_set<string>::iterator itr = pServerGroup->m_setLoginedAccount.begin();
					int offset = MSG_SIZE(MSG_PA_ADMIN_GET_ACCOUNT_LIST_OK);
					while (itr != pServerGroup->m_setLoginedAccount.end())
					{
						if (offset+sizeof(MEX_SIMPLE_ACCOUNT_INFO_FOR_ADMIN) >= SIZE_MAX_PACKET)
						{
							break;
						}

						MEX_SIMPLE_ACCOUNT_INFO_FOR_ADMIN *pAccInfo
							= (MEX_SIMPLE_ACCOUNT_INFO_FOR_ADMIN*)(SendBuf+offset);

						STRNCPY_MEMSET(pAccInfo->AccountName, (*itr).c_str(), SIZE_MAX_ACCOUNT_NAME);
						STRNCPY_MEMSET(pAccInfo->CharacterName, "", SIZE_MAX_CHARACTER_NAME);

						offset += sizeof(MEX_SIMPLE_ACCOUNT_INFO_FOR_ADMIN);
						msgGetOK->NumOfAccounts++;
						itr++;
					}
				}
				pServerGroup->m_setLoginedAccount.unlock();

				SendAddData(SendBuf, MSG_SIZE(MSG_PA_ADMIN_GET_ACCOUNT_LIST_OK)+msgGetOK->NumOfAccounts*sizeof(MEX_SIMPLE_ACCOUNT_INFO_FOR_ADMIN));
			}
			break;
		case T_PA_ADMIN_RELOAD_HAPPYEV:		// 2006-08-28 by cmkwon
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_RELOAD_HAPPYEV Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.

				///////////////////////////////////////////////////////////////////////////////
				// 2007-11-02 by cmkwon, �ý��� �α� �߰�
				g_pGlobal->WriteSystemLogEX(TRUE, "[Notify] Protocol Type(%s:0x%X) !!, AccountName(%s) IP(%s)\r\n"
												, GetProtocolTypeString(nRecvType), nRecvType, m_szAdminAccountName, GetPeerIP());

				MessageType_t nSTy = T_FP_EVENT_RELOAD_HAPPYEV;
				ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)&nSTy, SIZE_FIELD_TYPE_HEADER);
			}
			break;
		case T_PA_ADMIN_RELOAD_ITEMEV:
			{// 2006-08-31 by dhjin
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_RELOAD_ITEMEV Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				///////////////////////////////////////////////////////////////////////////////
				// 2007-11-02 by cmkwon, �ý��� �α� �߰�
				g_pGlobal->WriteSystemLogEX(TRUE, "[Notify] Protocol Type(%s:0x%X) !!, AccountName(%s) IP(%s)\r\n"
												, GetProtocolTypeString(nRecvType), nRecvType, m_szAdminAccountName, GetPeerIP());

				MessageType_t nSTy = T_FP_EVENT_RELOAD_ITEMEV;
				ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)&nSTy, SIZE_FIELD_TYPE_HEADER);
			}
			break;
			
			// 2014-02-11 by bckim, �����ʱ�ȭ�� ���� ����ȭó��
		case T_PA_ADMIN_RELOAD_GUILD_INFO:
			{
				procRes = Process_PA_RELOAD_GUILD_INFO(pPacket, nLength, nBytesUsed);
				break;			
			}
			// End. 2014-02-11 by bckim, �����ʱ�ȭ�� ���� ����ȭó��			

		case T_PA_ADMIN_UPDATE_PCBANGLIST:
			{// 2007-01-22 by dhjin
				MessageType_t nSTy = T_FP_EVENT_UPDATE_PCBANGLIST;
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_UPDATE_PCBANGLIST Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)&nSTy, SIZE_FIELD_TYPE_HEADER);
			}
			break;
		case T_PA_ADMIN_UPDATE_STRATEGYPOINT_NOTSUMMONTIME:
			{// 2007-03-06 by dhjin
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_UPDATE_STRATEGYPOINT_NOTSUMMONTIME Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.

				MessageType_t nSTy = T_FP_EVENT_UPDATE_STRATEGYPOINT_NOTSUMMONTIM;
				ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)&nSTy, SIZE_FIELD_TYPE_HEADER);
			}
			break;	
		case T_PA_ADMIN_PETITION_SET_PERIOD:		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_PETITION_SET_PERIOD Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
			procRes = Process_PA_ADMIN_PETITION_SET_PERIOD(pPacket, nLength, nBytesUsed);
			break;
		case T_PA_ADMIN_SET_DBSERVER_GROUP:			// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_SET_DBSERVER_GROUP Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
			procRes = Process_PA_ADMIN_SET_DBSERVER_GROUP(pPacket, nLength, nBytesUsed);
			break;
		case T_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM:		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - 
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
			procRes = Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM(pPacket, nLength, nBytesUsed);
			break;
		case T_PA_ADMIN_RELOAD_WORLDRANKING:		// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_RELOAD_WORLDRANKING Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
			procRes = Process_PA_ADMIN_RELOAD_WORLDRANKING(pPacket, nLength, nBytesUsed);
			break;
		case T_PA_ADMIN_RELOAD_INFLUENCERATE:		// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PA_ADMIN_RELOAD_INFLUENCERATE Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
			procRes = Process_PA_ADMIN_RELOAD_INFLUENCERATE(pPacket, nLength, nBytesUsed);
			break;

			
		///////////////////////////////////////////////////////////////////////
		// Pre Server <--> Client
		case T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK:
			procRes = Process_PC_CONNECT_SINGLE_FILE_VERSION_CHECK(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_VERSION:
			procRes = Process_PC_CONNECT_VERSION(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_DEFAULT_UPDATE_LAUNCHER_VERSION:
			procRes = Process_PC_DEFAULT_UPDATE_LAUNCHER_VERSION(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_LOGIN:
			procRes = Process_PC_CONNECT_LOGIN(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_GET_SERVER_GROUP_LIST:
			procRes = Process_PC_CONNECT_GET_SERVER_GROUP_LIST(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION:		// 2007-01-08 by cmkwon
			procRes = Process_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST:		// 2007-05-02 by cmkwon
			procRes = Process_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_NETWORK_CHECK:		// 2007-06-18 by cmkwon, ��Ʈ��ũ ���� üũ
			procRes = Process_PC_CONNECT_NETWORK_CHECK(pPacket, nLength, nBytesUsed);
			break;
		case T_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST:	// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �߰��� �������� Ÿ�� ó��
			procRes = Process_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST(pPacket, nLength, nBytesUsed);
			break;

		///////////////////////////////////////////////////////////////////////
		// Field Server <--> Pre Server
		case T_FP_CONNECT_AUTH_USER:
			procRes = Process_FP_CONNECT_AUTH_USER(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_FIELD_CONNECT:
			procRes = Process_FP_CONNECT_FIELD_CONNECT(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_NOTIFY_CLOSE:
			procRes = Process_FP_CONNECT_NOTIFY_CLOSE(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE:
			procRes = Process_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK:	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
			procRes = Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK(pPacket, nLength, nBytesUsed);
			break;
// 2005-07-27 by cmkwon, �ٸ� �ʵ弭������ ������ �����Ƿ� ������
//		case T_FP_EVENT_NOTIFY_WARP:
//			procRes = Process_FP_EVENT_NOTIFY_WARP(pPacket, nLength, nBytesUsed);
//			break;
		case T_FP_EVENT_ENTER_SELECT_SCREEN:
			procRes = Process_FP_EVENT_ENTER_SELECT_SCREEN(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_EVENT_GAME_STARTED:
			procRes = Process_FP_EVENT_GAME_STARTED(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_EVENT_MAP_CHANGED:
			procRes = Process_FP_EVENT_MAP_CHANGED(pPacket, nLength, nBytesUsed);
			break;

		case T_FP_CASH_CHANGE_CHARACTERNAME:
			procRes = Process_FP_CASH_CHANGE_CHARACTERNAME(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_BLOCKACCOUNT:		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
			procRes = Process_FP_ADMIN_BLOCKACCOUNT(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_UNBLOCKACCOUNT:		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
			procRes = Process_FP_ADMIN_UNBLOCKACCOUNT(pPacket, nLength, nBytesUsed);
			break;

		// start 2011-06-22 by hskim, �缳 ���� ����
		case T_FP_AUTHENTICATION_SHUTDOWN:
			procRes = Process_FP_AUTHENTICATION_SHUTDOWN(pPacket, nLength, nBytesUsed);
			break;
		// end 2011-06-22 by hskim, �缳 ���� ����

		///////////////////////////////////////////////////////////////////////
		// IM Server <--> Pre Server
		case T_IP_CONNECT_IM_CONNECT:
			procRes = Process_IP_CONNECT_IM_CONNECT(pPacket, nLength, nBytesUsed);
			break;
		case T_IP_GET_SERVER_GROUP_INFO_ACK:
			procRes = Process_IP_GET_SERVER_GROUP_INFO_ACK(pPacket, nLength, nBytesUsed);
			break;

		// start 2011-06-22 by hskim, �缳 ���� ����
		case T_IP_AUTHENTICATION_SHUTDOWN:
			procRes = Process_IP_AUTHENTICATION_SHUTDOWN(pPacket, nLength, nBytesUsed);
			break;
		// end 2011-06-22 by hskim, �缳 ���� ����

		///////////////////////////////////////////////////////////////////////
		// PreServer <-- Monitor
		case T_PM_CONNECT:
			{
				// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - �Ʒ��� ���� ���� ��
				//if(FALSE == IS_SCADMINTOOL_CONNECTABLE_IP(GetPeerIP()))
				if(FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))	// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
				{
					// 2009-01-21 by cmkwon, �ý��� �α� �߰�
					g_pGlobal->WriteSystemLogEX(TRUE, "[Notify] SCMonitor connect fail !!, IP(%s)\r\n", GetPeerIP());
					return FALSE;
				}

// 2007-11-01 by cmkwon, �Ʒ��� ���� ������
//				char szSystemLog[256];
//				sprintf(szSystemLog, "Monitor Client Connected, IP[%s]\r\n", GetPeerIP());
//				DBGOUT(szSystemLog);
//				g_pGlobal->WriteSystemLog(szSystemLog);
				g_pGlobal->WriteSystemLogEX(TRUE, "[Notify] SCMonitor connected !!, IP(%s)\r\n", GetPeerIP());

				MSG_PM_CONNECT_OK	*pSendPMConnectOK = NULL;

				*(MessageType_t*)SendBuf = T_PM_CONNECT_OK;
				pSendPMConnectOK = (MSG_PM_CONNECT_OK*)(SendBuf + SIZE_FIELD_TYPE_HEADER);
				STRNCPY_MEMSET(pSendPMConnectOK->IPAddress, g_pPreGlobal->GetPublicIPLocal(), SIZE_MAX_IPADDRESS);
				pSendPMConnectOK->NumOfClients = ms_pPreIOCP->m_AccountInfoMap.size();
				pSendPMConnectOK->Port = ms_pPreIOCP->m_nListenerPort;
				pSendPMConnectOK->CalcBandwidth = ms_pPreIOCP->GetFlagCalcTrafficInfo();
				pSendPMConnectOK->StartedTime = ms_pPreIOCP->m_dwTimeStarted;
				STRNCPY_MEMSET(pSendPMConnectOK->ServerName, "Pre Server", SIZE_MAX_SERVER_NAME);
				pSendPMConnectOK->nMGameEventType = g_pPreGlobal->m_enMGameEventType;
// 2007-01-08 by cmkwon, T_PM_AUTO_UPDATE_FTP_SERVER_SETTING�� ������ �����Ѵ�
//				STRNCPY_MEMSET(pSendPMConnectOK->FtpIP, g_pPreGlobal->GetUploadFTPIP(), SIZE_MAX_FTP_URL);
//				pSendPMConnectOK->FtpPort = g_pPreGlobal->GetUploadFTPPort();
//				STRNCPY_MEMSET(pSendPMConnectOK->FtpAccountName, g_pPreGlobal->GetUploadFTPAccount(), SIZE_MAX_ACCOUNT_NAME);
//				STRNCPY_MEMSET(pSendPMConnectOK->FtpPassword, g_pPreGlobal->GetUploadFTPPassword(), SIZE_MAX_PASSWORD);
//				STRNCPY_MEMSET(pSendPMConnectOK->ClientFTPUpdateUploadDir, g_pPreGlobal->m_szClientFTPUpdateUploadDir, SIZE_MAX_FTP_FILE_PATH);
//				STRNCPY_MEMSET(pSendPMConnectOK->LauncherFileUploadPath, g_pPreGlobal->m_szLauncherFileUploadPath, SIZE_MAX_FTP_FILE_PATH);
//				STRNCPY_MEMSET(pSendPMConnectOK->DeleteFileListUploadPath, g_pPreGlobal->m_szDeleteFileListUploadPath, SIZE_MAX_FTP_FILE_PATH);
//				STRNCPY_MEMSET(pSendPMConnectOK->NoticeFileUploadPath, g_pPreGlobal->m_szNoticeFileUploadPath, SIZE_MAX_FTP_FILE_PATH);
//				STRNCPY_MEMSET(pSendPMConnectOK->szVersionListFileUploadPath, g_pPreGlobal->m_szVersionListFileUploadPath, SIZE_MAX_FTP_FILE_PATH);

				m_PeerSocketType = ST_MONITOR_SERVER;
				ms_pPreIOCP->InsertMonitorIOCPSocketPtr(this);

				SendAddData(SendBuf, MSG_SIZE(MSG_PM_CONNECT_OK));
				
				///////////////////////////////////////////////////////////////////////////////
				// 2007-01-08 by cmkwon
				INIT_MSG(MSG_PM_AUTO_UPDATE_FTP_SERVER_SETTING, T_PM_AUTO_UPDATE_FTP_SERVER_SETTING, pSFTPMsg, SendBuf);
				pSFTPMsg->nAutoUpdateServerType			= g_pPreGlobal->m_nAutoUpdateServerType;
				STRNCPY_MEMSET(pSFTPMsg->FtpIP, g_pPreGlobal->GetUploadFTPIP(), SIZE_MAX_FTP_URL);
				pSFTPMsg->FtpPort = g_pPreGlobal->GetUploadFTPPort();
				STRNCPY_MEMSET(pSFTPMsg->FtpAccountName, g_pPreGlobal->GetUploadFTPAccount(), SIZE_MAX_ACCOUNT_NAME);
				STRNCPY_MEMSET(pSFTPMsg->FtpPassword, g_pPreGlobal->GetUploadFTPPassword(), SIZE_MAX_PASSWORD);
				STRNCPY_MEMSET(pSFTPMsg->ClientFTPUpdateUploadDir, g_pPreGlobal->m_szClientFTPUpdateUploadDir, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSFTPMsg->LauncherFileUploadPath, g_pPreGlobal->m_szLauncherFileUploadPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSFTPMsg->DeleteFileListUploadPath, g_pPreGlobal->m_szDeleteFileListUploadPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSFTPMsg->NoticeFileUploadPath, g_pPreGlobal->m_szNoticeFileUploadPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSFTPMsg->szVersionListFileUploadPath, g_pPreGlobal->m_szVersionListFileUploadPath, SIZE_MAX_FTP_FILE_PATH);
				SendAddData(SendBuf, MSG_SIZE(MSG_PM_AUTO_UPDATE_FTP_SERVER_SETTING));


				///////////////////////////////////////////////////////////////////////////////
				// 2007-01-06 by cmkwon
				INIT_MSG(MSG_PM_AUTO_UPDATE_HTTP_SERVER_SETTING, T_PM_AUTO_UPDATE_HTTP_SERVER_SETTING, pSHttpMsg, SendBuf);
				pSHttpMsg->nAutoUpdateServerType			= g_pPreGlobal->m_nAutoUpdateServerType;
				STRNCPY_MEMSET(pSHttpMsg->szDownloadHttpServerIP, g_pPreGlobal->GetRandomDownloadHttpIP(), SIZE_MAX_FTP_URL);
				pSHttpMsg->nDownloadHttpServerPort			= g_pPreGlobal->m_nDownloadHttpServerPort;
				STRNCPY_MEMSET(pSHttpMsg->szDownloadHttpServerAccountName, g_pPreGlobal->m_szDownloadHttpServerAccountName, SIZE_MAX_ACCOUNT_NAME);
				STRNCPY_MEMSET(pSHttpMsg->szDownloadHttpServerPassword, g_pPreGlobal->m_szDownloadHttpServerPassword, SIZE_MAX_PASSWORD);
				STRNCPY_MEMSET(pSHttpMsg->szClientHttpUpdateDownloadDir, g_pPreGlobal->m_szClientHttpUpdateDownloadDir, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSHttpMsg->szLauncherFileDownloadHttpPath, g_pPreGlobal->m_szLauncherFileDownloadHttpPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSHttpMsg->szDeleteFileListDownloadHttpPath, g_pPreGlobal->m_szDeleteFileListDownloadHttpPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSHttpMsg->szNoticeFileDownloadHttpPath, g_pPreGlobal->m_szNoticeFileDownloadHttpPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSHttpMsg->szNoticeFileDownloadHttpPath, g_pPreGlobal->m_szNoticeFileDownloadHttpPath, SIZE_MAX_FTP_FILE_PATH);
				STRNCPY_MEMSET(pSHttpMsg->szVersionListFileDownloadHttpPath, g_pPreGlobal->m_szVersionListFileDownloadHttpPath, SIZE_MAX_FTP_FILE_PATH);
				SendAddData(SendBuf, MSG_SIZE(MSG_PM_AUTO_UPDATE_HTTP_SERVER_SETTING));

				//////////////////////////////////////////////////////////
				// Loaded Server Group Info
				vector<CServerGroup*>::iterator itr(ms_pPreIOCP->GetAllServerGroupVector()->begin());
				while (itr != ms_pPreIOCP->GetAllServerGroupVector()->end())
				{
					INIT_MSG(MSG_PM_GET_SERVER_GROUP_INFO_ACK, T_PM_GET_SERVER_GROUP_INFO_ACK, pSendGroupInfo, SendBuf);
					STRNCPY_MEMSET(pSendGroupInfo->ServerGroupName, (*itr)->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
					pSendGroupInfo->IMServerID					= (*itr)->m_IMServerInfo.serverID;
					pSendGroupInfo->AccumulatedGroupUserCounts	= (*itr)->m_AccumulatedGroupUserCounts;
					pSendGroupInfo->CurrentGroupUserCounts		= (*itr)->GetUserCount();
					pSendGroupInfo->MaxGroupUserCounts			= (*itr)->m_MaxGroupUserCounts;
					pSendGroupInfo->bEnableServerGroup			= (*itr)->m_bEnableServerGroup;
					pSendGroupInfo->LimitGroupUserCounts		= (*itr)->m_LimitGroupUserCounts;
					SendAddData(SendBuf, MSG_SIZE(MSG_PM_GET_SERVER_GROUP_INFO_ACK));
					itr++;
				}
			}
			break;
		case T_PM_GET_NUM_CLIENTS:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_GET_NUM_CLIENTS Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
				MSG_PM_GET_NUM_CLIENTS_OK	*pSendPMGetNumClientsOK = NULL;

				*(MessageType_t*)SendBuf = T_PM_GET_NUM_CLIENTS_OK;
				pSendPMGetNumClientsOK = (MSG_PM_GET_NUM_CLIENTS_OK*)(SendBuf + SIZE_FIELD_TYPE_HEADER);
				pSendPMGetNumClientsOK->NumOfClients = ms_pPreIOCP->m_AccountInfoMap.size();

				SendAddData(SendBuf, MSG_SIZE(MSG_PM_GET_NUM_CLIENTS_OK));

//				ms_pPreIOCP->DBG_PrintAccountMap();
			}
			break;
		case T_PM_SHUTDOWN:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_SHUTDOWN Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
				*(MessageType_t*)SendBuf = T_PM_SHUTDOWN_OK;
				SendAddData(SendBuf, SIZE_FIELD_TYPE_HEADER);
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� -  �������� ���
				// PostMessage(g_pGlobalGameServer->GetMainWndHandle(), WM_CLOSE, 0, 0);
			}
			break;
		case T_PM_PING:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_PING Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
				*(MessageType_t*)SendBuf = T_PM_PING_OK;
				SendAddData(SendBuf, SIZE_FIELD_TYPE_HEADER);
			}
			break;
		case T_PM_RELOAD_VERSION_INFO:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_RELOAD_VERSION_INFO Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			
				ms_pPreIOCP->m_bPauseService = TRUE;

				MSG_PM_RELOAD_VERSION_INFO *pMsgReload
					= (MSG_PM_RELOAD_VERSION_INFO*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_RELOAD_VERSION_INFO) + pMsgReload->NumOfClientVersions*8*sizeof(USHORT);


				// delete version list
				ms_pPreIOCP->m_mtmapVersionOld2New.lock();
				ms_pPreIOCP->m_mtmapVersionOld2New.clear();

				// set version history
				ms_pPreIOCP->m_LatestLauncherVersion.SetVersion(pMsgReload->LauncherVersion);
				ms_pPreIOCP->m_LatestDeleteFileListVersion.SetVersion(pMsgReload->DeleteFileListVersion);
				ms_pPreIOCP->m_LatestNoticeVersion.SetVersion(pMsgReload->NoticeVersion);
				for (int i = 0; i < pMsgReload->NumOfClientVersions; i++)
				{
					USHORT *pOldVersionArray = (USHORT*)(((char*)pMsgReload) + sizeof(MSG_PM_RELOAD_VERSION_INFO) + i*8*sizeof(USHORT));
					USHORT *pNewVersionArray = (USHORT*)(((char*)pMsgReload) + sizeof(MSG_PM_RELOAD_VERSION_INFO) + i*8*sizeof(USHORT) + 4*sizeof(USHORT));

					VersionInfo OldVersion(pOldVersionArray);
					VersionInfo NewVersion(pNewVersionArray);

					ms_pPreIOCP->m_mtmapVersionOld2New.insertLock(OldVersion, NewVersion);
				}

				// set current client version
				if (!ms_pPreIOCP->m_mtmapVersionOld2New.empty())
				{
					ms_pPreIOCP->m_LatestClientVersion = ms_pPreIOCP->m_mtmapVersionOld2New.rbegin()->second;
				}

				// write versions
				ms_pPreIOCP->WriteVersionInfoToLocalFile();
#ifdef _DEBUG
				mtmapVersionInfo::iterator itr = ms_pPreIOCP->m_mtmapVersionOld2New.begin();
				for (; itr != ms_pPreIOCP->m_mtmapVersionOld2New.end(); itr++)
				{
					VersionInfo tmpOldVersion = itr->first;
					VersionInfo tmpNewVersion = itr->second;
					DBGOUT("  Client Version: %10s -> %10s\n", tmpOldVersion.GetVersionString(), tmpNewVersion.GetVersionString());
				}
				DBGOUT("  Latest Client Version: %s\n", ms_pPreIOCP->m_mtmapVersionOld2New.rbegin()->second.GetVersionString());
				DBGOUT("  Client Reinstall Version: %s\n", g_pPreGlobal->GetClientReinstallVersion().GetVersionString());
				DBGOUT("\n  Launcher Version: %s\n", ms_pPreIOCP->m_LatestLauncherVersion.GetVersionString());
				DBGOUT("  Delete File List Version: %s\n", ms_pPreIOCP->m_LatestDeleteFileListVersion.GetVersionString());
				DBGOUT("  Notice Version: %s\n\n", ms_pPreIOCP->m_LatestNoticeVersion.GetVersionString());
#endif
				ms_pPreIOCP->m_mtmapVersionOld2New.unlock();
				ms_pPreIOCP->m_bPauseService = FALSE;

				SendAddMessageType(T_PM_RELOAD_VERSION_INFO_OK);
			}
			break;
		case T_PM_RELOAD_BLOCKED_ACCOUNTS:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_RELOAD_BLOCKED_ACCOUNTS Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				ms_pPreIOCP->LoadBlockedAccounts();

				SendAddMessageType(T_PM_RELOAD_BLOCKED_ACCOUNTS_OK);
			}
			break;
		case T_PM_CHANGE_BANDWIDTH_FLAG:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_CHANGE_BANDWIDTH_FLAG Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				ms_pPreIOCP->SetFlagCalcTrafficInfo(!ms_pPreIOCP->GetFlagCalcTrafficInfo());

				*(MessageType_t*)SendBuf = T_PM_CHANGE_BANDWIDTH_FLAG_OK;
				MSG_PM_CHANGE_BANDWIDTH_FLAG_OK		*pChangeFlag
					 = (MSG_PM_CHANGE_BANDWIDTH_FLAG_OK*)(SendBuf + SIZE_FIELD_TYPE_HEADER);
				pChangeFlag->bChagedFlag = ms_pPreIOCP->GetFlagCalcTrafficInfo();

				SendAddData(SendBuf, MSG_SIZE(MSG_PM_CHANGE_BANDWIDTH_FLAG_OK));
			}
			break;
		case T_PM_SET_MSG_PRINT_LEVEL:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_SET_MSG_PRINT_LEVEL Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				BYTE tmpLevel = *(BYTE*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_SET_MSG_PRINT_LEVEL);

				// set msg print level
				GSetexchangeMsgPrintLevel(tmpLevel);
			}
			break;
		case T_PM_PAUSE_SERVICE:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_PAUSE_SERVICE Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				// 2011-11-08 by shcho, ����4D ���� ��ŷ ���� �ӽ� �ذ�
				g_pGlobal->WriteSystemLogEX(TRUE, "T_PM_PAUSE_SERVICE COMMAND! PeerIP:[%s]\r\n", this->GetPeerIP());				
// 				ms_pPreIOCP->m_bPauseService = TRUE;	//���� �ذ��� ���� �ϴ� ����
				// end 2011-11-08 by shcho, ����4D ���� ��ŷ ���� �ӽ� �ذ�
				MessageType_t sendMsgType = T_PM_PAUSE_SERVICE_OK;
				SendAddData((unsigned char*)&sendMsgType, SIZE_FIELD_TYPE_HEADER);
			}
			break;
		case T_PM_START_SERVICE:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_START_SERVICE Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				ms_pPreIOCP->m_bPauseService = FALSE;

				MessageType_t sendMsgType = T_PM_START_SERVICE_OK;
				SendAddData((unsigned char*)&sendMsgType, SIZE_FIELD_TYPE_HEADER);
			}
			break;
		case T_PM_GET_SERVER_GROUP_INFO:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_GET_SERVER_GROUP_INFO Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				MSG_PM_GET_SERVER_GROUP_INFO	*pRecvGroupInfo
					= (MSG_PM_GET_SERVER_GROUP_INFO*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_GET_SERVER_GROUP_INFO);

				//////////////////////////////////////////////////////////
				// Loaded Server Group Info
				CServerGroup* pSGroup = ms_pPreIOCP->GetServerGroup(pRecvGroupInfo->ServerGroupName);
				if(pSGroup && pSGroup->m_IMServerInfo.IsActive && pSGroup->m_IMServerInfo.pSocket)
				{
					*(MessageType_t*)SendBuf = T_IP_GET_SERVER_GROUP_INFO;
					pSGroup->m_IMServerInfo.pSocket->SendAddData(SendBuf, SIZE_FIELD_TYPE_HEADER);
				}
			}
			break;
		case T_PM_SET_LIMIT_GROUP_USER_COUNTS:
			{
				MSG_PM_SET_LIMIT_GROUP_USER_COUNTS	*pRecvLimitCounts
					= (MSG_PM_SET_LIMIT_GROUP_USER_COUNTS*)(pPacket + nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_SET_LIMIT_GROUP_USER_COUNTS);
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))		// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ����Ʈ ī��Ʈ�� �� IP�� üũ�ϵ��� �Ѵ�.
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_SET_LIMIT_GROUP_USER_COUNTS Command Using: HackingIP(%15s) \r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - �� ����� �� IP�� üũ�ϵ��� �Ѵ�.

				//////////////////////////////////////////////////////////
				// Loaded Server Group Info
				CServerGroup* pSGroup = ms_pPreIOCP->GetServerGroup(pRecvLimitCounts->ServerGroupName);
				if(pSGroup)
				{
					pSGroup->m_LimitGroupUserCounts = pRecvLimitCounts->LimitGroupUserCounts;

					INIT_MSG(MSG_PM_GET_SERVER_GROUP_INFO_ACK, T_PM_GET_SERVER_GROUP_INFO_ACK, pSendGroupInfo, SendBuf);
					STRNCPY_MEMSET(pSendGroupInfo->ServerGroupName, pSGroup->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
					pSendGroupInfo->IMServerID = pSGroup->m_IMServerInfo.serverID;
					pSendGroupInfo->AccumulatedGroupUserCounts	= pSGroup->m_AccumulatedGroupUserCounts;
					pSendGroupInfo->CurrentGroupUserCounts		= pSGroup->GetUserCount();
					pSendGroupInfo->MaxGroupUserCounts			= pSGroup->m_MaxGroupUserCounts;
					pSendGroupInfo->bEnableServerGroup			= pSGroup->m_bEnableServerGroup;
					pSendGroupInfo->LimitGroupUserCounts		= pSGroup->m_LimitGroupUserCounts;
					
					ms_pPreIOCP->SendMessageToMonitor(SendBuf, MSG_SIZE(MSG_PM_GET_SERVER_GROUP_INFO_ACK));
				}
			}
			break;
		case T_PM_SET_MGAME_EVENT_TYPE:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_SET_MGAME_EVENT_TYPE Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				MSG_PM_SET_MGAME_EVENT_TYPE		*pRMsg = (MSG_PM_SET_MGAME_EVENT_TYPE*)(pPacket+nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_SET_MGAME_EVENT_TYPE);

				g_pPreGlobal->SetMGameEventType(pRMsg->enMGameEvent);
				INIT_MSG(MSG_FP_MONITOR_SET_MGAME_EVENT_TYPE, T_FP_MONITOR_SET_MGAME_EVENT_TYPE, pSend, SendBuf);
				pSend->enMGameEvent = pRMsg->enMGameEvent;
				ms_pPreIOCP->SendMessageToAllFieldServer(SendBuf, MSG_SIZE(MSG_FP_MONITOR_SET_MGAME_EVENT_TYPE));
			}
			break;
		case T_PM_CHANGE_ENABLE_SERVER_GROUP:
			{
				// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_CHANGE_ENABLE_SERVER_GROUP Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
					break;
				}
				// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
				
				MSG_PM_CHANGE_ENABLE_SERVER_GROUP *pRMsg = (MSG_PM_CHANGE_ENABLE_SERVER_GROUP*)(pPacket+nBytesUsed);
				nBytesUsed += sizeof(MSG_PM_CHANGE_ENABLE_SERVER_GROUP);

				//////////////////////////////////////////////////////////
				// Loaded Server Group Info
				CServerGroup* pSGroup = ms_pPreIOCP->GetServerGroup(pRMsg->ServerGroupName);
				if(pSGroup)
				{
					pSGroup->m_bEnableServerGroup = pRMsg->bEnableServerGroup;
				}
			}
			break;
		case T_PM_PREPARE_SHUTDOWN:
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_PREPARE_SHUTDOWN Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			procRes = Process_PM_PREPARE_SHUTDOWN(pPacket, nLength, nBytesUsed);
			break;
		case T_PM_RELOAD_VERSION_INFO_HEADER:		// 2007-01-09 by cmkwon
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_RELOAD_VERSION_INFO_HEADER Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			procRes = Process_PM_RELOAD_VERSION_INFO_HEADER(pPacket, nLength, nBytesUsed);
			break;
		case T_PM_RELOAD_VERSION_INFO_LIST:			// 2007-01-09 by cmkwon
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_RELOAD_VERSION_INFO_LIST Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			procRes = Process_PM_RELOAD_VERSION_INFO_LIST(pPacket, nLength, nBytesUsed);
			break;
		case T_PM_RELOAD_VERSION_INFO_DONE:			// 2007-01-09 by cmkwon
			// 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			if(FALSE==g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "HACKUSER!! Connect T_PM_RELOAD_VERSION_INFO_DONE Command Using: HackingIP(%15s)\r\n", this->GetPeerIP());
				break;
			}
			// end 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - ��ϵ� IP�� �ƴϸ� ó���ȵǵ��� �Ѵ�.
			procRes = Process_PM_RELOAD_VERSION_INFO_DONE(pPacket, nLength, nBytesUsed);
			break;

		///////////////////////////////////////////////////////////////////////////////
		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
		case T_PP_CONNECT:			// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
			procRes = Process_PP_CONNECT(pPacket, nLength, nBytesUsed);
			break;

		////////////////////////////////////////////////////////////////////////////
		// 2012-10-05 by jhseol, NPlay pc�� ��� - ���ú� �Լ�
		case T_FP_PCBANG_USER_GAME_START:
			procRes = Process_FP_PCBANG_USER_GAME_START(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_PCBANG_USER_GAME_END:
			procRes = Process_FP_PCBANG_USER_GAME_END(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_PCBANG_USER_PREMIUN_END:
			procRes = Process_FP_PCBANG_USER_PREMIUN_END(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_PCBANG_USER_PREMIUM_REQUEST:
			procRes = Process_FP_PCBANG_USER_PREMIUM_REQUEST(pPacket, nLength, nBytesUsed);
			break;
		// end  2012-10-05 by jhseol, NPlay pc�� ��� - ���ú� �Լ�

		///////////////////////////////////////////////////////////////////////////////
		// 2006-08-04 by cmkwon
		default:
			{
				// Protocol Error ó��(Close ó����)
				// - Client�� ���� ���� Message Type�� ��ȿ���� �ʴ�
				SendErrorMessage(T_PRE_IOCP, ERR_PROTOCOL_INVALID_PROTOCOL_TYPE, 0, 0, NULL, TRUE);

				char	szSystemLog[1024];
				sprintf(szSystemLog, "[Error] CPreIOCPSocket::OnRecvdPacketPreServer invalid protocol type, OldRecvType(%#04X), CurRecvType[%s(%#04X)]", nOldRecvType, GetProtocolTypeString(nRecvType), nRecvType);
				g_pGlobal->WriteSystemLog(szSystemLog);
				DBGOUT(szSystemLog);
				return FALSE;
			}
		}	// end switch

		// MSG ��� ó��
		if (procRes == RES_BREAK)
		{
			// ����� ������. ������ ���� �ʴ´�.
			// do nothing, �׳� �����ִ� ���� packet�� ó���Ѵ�
		}
		else if (procRes == RES_PACKET_ERROR)
		{
			// ��Ŷ�� �ջ�� ���. ���� packet�� ó������ �ʰ� �ٷ� �����Ѵ�. ������ ���ῡ�� ���.
			return TRUE;
		}
		else if (procRes == RES_RETURN_TRUE)
		{
			// ����
			// do nothing, �׳� �����ִ� ���� packet�� ó���Ѵ�
		}
		else if (procRes == RES_RETURN_FALSE)
		{
			return FALSE;
		}

		nOldRecvType = nRecvType;						// 2007-04-02 by cmkwon, �߰���
	}	// end while

	return TRUE;
}

void CPreIOCPSocket::OnConnect(void)
{
	char szSystemLog[256];
	sprintf(szSystemLog, "Socket Connect SocketIndex[%3d] PeerIP[%15s] Port[%4d]\r\n",
		this->GetClientArrayIndex(), m_szPeerIP, m_nPeerPort);
	g_pGlobal->WriteSystemLog(szSystemLog);
	DBGOUT(szSystemLog);

	SetClientState(CP_CONNECTED, NULL);
	m_PeerSocketType		= ST_INVALID_TYPE;
	MEMSET_ZERO(m_szAdminAccountName, SIZE_MAX_ACCOUNT_NAME);		// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�

	m_eOtherPublisherConncect = CONNECT_PUBLISHER_DEFAULT;				// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.

	CIOCPSocket::OnConnect();
}

void CPreIOCPSocket::OnClose(int reason)
{
	char szSystemLog[1024];

	// 2009-03-19 by cmkwon, �ý��� �α� �߰� - m_PeerSocketType ���� �߰�
	sprintf(szSystemLog, "Socket Closed  SocketIndex[%3d] SocketType[%d] PeerIP[%15s] Port[%4d] MaxWriteBufCounts[%4d] ==> reason %d[%#08X]\r\n",
		this->GetClientArrayIndex(), m_PeerSocketType, m_szPeerIP, m_nPeerPort, m_nMaxWriteBufCounts, reason, reason);
	g_pGlobal->WriteSystemLog(szSystemLog);
	DBGOUT(szSystemLog);

	if (ST_FIELD_SERVER == m_PeerSocketType)
	{
		sprintf(szSystemLog, "	Closed FieldServer(%15s:%5d), ServerGroupName(%12s)\r\n"
			, GetPeerIP(), GetPeerPort(), m_szConnectedServerGroupName);
		g_pGlobal->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);
		////////////////////////////////////////////////////////////////////////////////////
		// 2012-10-05 by jhseol, NPlay pc�� ���, �ʵ弭���� ������ ��� ������ pc�� ���� ������û�� ������
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
		if( 0 != strncmp(ARENA_SERVER_GROUP_NAME, m_szConnectedServerGroupName, strlen(ARENA_SERVER_GROUP_NAME)) && strlen(ARENA_SERVER_GROUP_NAME) != strlen(m_szConnectedServerGroupName))
		{
			if( NULL != g_pPreGlobal && NULL != g_pPreGlobal->m_pNPlayPCBangModule )
			{
				g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_SendAllDisConnectByServername(m_szConnectedServerGroupName);
			}
		}
#endif
		// end 2012-10-05 by jhseol, NPlay pc�� ���, �ʵ弭���� ������ ��� ������ pc�� ���� ������û�� ������

		ms_pPreIOCP->ResetServerGroup(m_szConnectedServerGroupName, TRUE);
	}
	
	if(ST_IM_SERVER == m_PeerSocketType)
	{
		sprintf(szSystemLog, "	Closed IMServer(%15s:%5d), ServerGroupName(%12s)\r\n"
			, GetPeerIP(), GetPeerPort(), m_szConnectedServerGroupName);
		g_pGlobal->WriteSystemLog(szSystemLog);
		DBGOUT(szSystemLog);

		ms_pPreIOCP->ResetServerGroup(m_szConnectedServerGroupName);
	}

	if(m_PeerSocketType == ST_MONITOR_SERVER)
	{
		ms_pPreIOCP->DeleteMonitorIOCPSocketPtr(this);
	}

	if(m_PeerSocketType == ST_ADMIN_TOOL)
	{
		ms_pPreIOCP->DeleteMonitorIOCPSocketPtr(this);
	}

	SetClientState(CP_NOTCONNECTED, NULL);
	m_PeerSocketType = ST_INVALID_TYPE;
	MEMSET_ZERO(m_szConnectedServerGroupName, SIZE_MAX_SERVER_NAME);

	m_eOtherPublisherConncect = CONNECT_PUBLISHER_DEFAULT;				// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.

	CIOCPSocket::OnClose(30);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PA_ADMIN_PETITION_SET_PERIOD(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
/// \author		cmkwon
/// \date		2007-11-20 ~ 2007-11-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PA_ADMIN_PETITION_SET_PERIOD(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_PA_ADMIN_PETITION_SET_PERIOD, 
											MSG_PA_ADMIN_PETITION_SET_PERIOD, pRMsg); 
 
	INIT_MSG_WITH_BUFFER(MSG_IP_ADMIN_PETITION_SET_PERIOD, T_IP_ADMIN_PETITION_SET_PERIOD, pSMsg, SendBuf);
	*pSMsg			= *pRMsg;
	ms_pPreIOCP->SendMsgToAllIMServer(SendBuf, MSG_SIZE(MSG_IP_ADMIN_PETITION_SET_PERIOD));

	return RES_RETURN_TRUE;
}

// 2014-02-11 by bckim, �����ʱ�ȭ�� ���� ����ȭó��
ProcessResult CPreIOCPSocket::Process_PA_RELOAD_GUILD_INFO(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_PA_ADMIN_RELOAD_GUILD_INFO, 
		MSG_PA_RELOAD_GUILD_INFO, pRMsg); 
	
	INIT_MSG_WITH_BUFFER(MSG_PA_RELOAD_GUILD_INFO, T_IP_RELOAD_GUILD_INFO, pSMsg, SendBuf);
	*pSMsg			= *pRMsg;
	ms_pPreIOCP->SendMsgToAllIMServer(SendBuf, MSG_SIZE(MSG_IP_RELOAD_GUILD_INFO));
	
	return RES_RETURN_TRUE;
}
// End. 2014-02-11 by bckim, �����ʱ�ȭ�� ���� ����ȭó��


///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PA_ADMIN_SET_DBSERVER_GROUP(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
/// \author		cmkwon
/// \date		2008-04-30 ~ 2008-04-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PA_ADMIN_SET_DBSERVER_GROUP(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_PA_ADMIN_SET_DBSERVER_GROUP, 
											MSG_PA_ADMIN_SET_DBSERVER_GROUP, pRMsg); 

	CServerGroup* pServG = ms_pPreIOCP->GetServerGroup(pRMsg->ServerGroupName);
	if(NULL == pServG
		|| NULL == pServG->m_FieldServerInfo.pSocket
		|| FALSE == pServG->m_FieldServerInfo.pSocket->IsUsing()
		|| FALSE == pServG->m_FieldServerInfo.IsActive)
	{// 2008-05-01 by cmkwon, FieldServer ��ȿ�� üũ

		// 2009-01-30 by cmkwon, �����׷캰 ���� ������ ���� ���� �ý��� �α� �߰� - 
		g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] CPreIOCPSocket::Process_PA_ADMIN_SET_DBSERVER_GROUP# invalid FieldServer !!, %s, %d %d \r\n", 
			pRMsg->ServerGroupName, pRMsg->LimitUserCount, pRMsg->LockCreateCharacterForNewAccount);
		return RES_BREAK;
	}

	// 2008-04-30 by cmkwon, PreServer �� ������ ������Ʈ
	pServG->m_LimitGroupUserCounts				= pRMsg->LimitUserCount;
	pServG->m_bLockCreateCharacterForNewAccount	= pRMsg->LockCreateCharacterForNewAccount;

	// 2008-04-30 by cmkwon, FieldSever �� ����
	INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_UPDATE_DBSERVER_GROUP, T_FP_CONNECT_UPDATE_DBSERVER_GROUP, pSMsg, SendBuf);
	pSMsg->DBServerGroup.ServerGroupID						= pServG->m_nMGameServerID;
	STRNCPY_MEMSET(pSMsg->DBServerGroup.ServerGroupName, pServG->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
	pSMsg->DBServerGroup.LimitUserCount						= pServG->m_LimitGroupUserCounts;
	pSMsg->DBServerGroup.LockCreateCharacterForNewAccount	= pServG->m_bLockCreateCharacterForNewAccount;
	pServG->SendMessageToFieldServer(SendBuf, MSG_SIZE(MSG_FP_CONNECT_UPDATE_DBSERVER_GROUP));

	// 2008-05-01 by cmkwon, AdminTool �� ����
	INIT_MSG(MSG_PA_ADMIN_SET_DBSERVER_GROUP_OK, T_PA_ADMIN_SET_DBSERVER_GROUP_OK, pSMsgToAdmin, SendBuf);
	*pSMsgToAdmin	= *pRMsg;
	this->SendAddData(SendBuf, MSG_SIZE(MSG_PA_ADMIN_SET_DBSERVER_GROUP_OK));
	return RES_RETURN_TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - CPreIOCPSocket::Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM() 
/// \author		cmkwon
/// \date		2009-01-19 ~ 2009-01-19
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM(const char* pPacket, int nLength, int &nBytesUsed)
{// No body

	// 2009-01-19 by cmkwon, ��� IMServer�� ����
	MessageType_t msgTy = T_IP_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM;
	ms_pPreIOCP->SendMsgToAllIMServer((BYTE*)&msgTy, SIZE_FIELD_TYPE_HEADER);
	return RES_RETURN_TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
/// \author		cmkwon
/// \date		2009-02-25 ~ 2009-02-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PA_ADMIN_RELOAD_WORLDRANKING(const char* pPacket, int nLength, int &nBytesUsed)
{// No body

	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	MessageType_t msgTy = T_FP_ADMIN_RELOAD_WORLDRANKING;
	ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)&msgTy, SIZE_FIELD_TYPE_HEADER);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
/// \author		cmkwon
/// \date		2009-09-22 ~ 2009-09-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PA_ADMIN_RELOAD_INFLUENCERATE(const char* pPacket, int nLength, int &nBytesUsed)
{// T_PA_ADMIN_RELOAD_INFLUENCERATE	
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_PA_ADMIN_RELOAD_INFLUENCERATE, 
		MSG_PA_ADMIN_RELOAD_INFLUENCERATE, pRMsg); 
		
	CServerGroup* pServG = ms_pPreIOCP->GetServerGroup(pRMsg->ServerGroupName);
	if(NULL == pServG
		|| NULL == pServG->m_FieldServerInfo.pSocket
		|| FALSE == pServG->m_FieldServerInfo.pSocket->IsUsing()
		|| FALSE == pServG->m_FieldServerInfo.IsActive)
	{// 2009-09-22 by cmkwon
		
		// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
		g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] CPreIOCPSocket::Process_PA_ADMIN_RELOAD_INFLUENCERATE# invalid FieldServer !!, %s \r\n", pRMsg->ServerGroupName);
		return RES_BREAK;
	}

	MessageType_t msgTy = T_FP_ADMIN_RELOAD_INFLUENCERATE;
	pServG->SendMessageToFieldServer((BYTE*)&msgTy, SIZE_FIELD_TYPE_HEADER);
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PC_CONNECT_SINGLE_FILE_VERSION_CHECK(const char* pPacket, int nLength, int &nBytesUsed)
{
	int								nRecvTypeSize	= 0;
	MSG_PC_CONNECT_SINGLE_FILE_VERSION_CHECK	*pMsgSFVersion;

	nRecvTypeSize = sizeof(MSG_PC_CONNECT_SINGLE_FILE_VERSION_CHECK);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK, ERR_PROTOCOL_INVALID_FIELD_DATA);

		Close(0x11002, TRUE);
		return RES_RETURN_FALSE;
	}

	pMsgSFVersion = (MSG_PC_CONNECT_SINGLE_FILE_VERSION_CHECK*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	if (GetClientState(NULL) != CP_CONNECTED)
	{
		// Protocol Error ó��
		// Error Code : ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE
		SendErrorMessage(T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE);

		return RES_BREAK;
	}

#ifdef _DEBUG
	if (g_pPreGlobal->m_bIgnoreClientVersionUpdate)
	{
		SendAddMessageType(T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK_OK);
		SetClientState(CP_SINGLE_FILE_VERSIONCHECKED, NULL);
		m_PeerSocketType = ST_CLIENT_TYPE;
		return RES_RETURN_TRUE;
	}
#endif

	VersionInfo CurrentClientDelFileVerion(pMsgSFVersion->DeleteFileListVersion);
	VersionInfo CurrentClientNoticeVersion(pMsgSFVersion->NoticeVersion);

	BOOL bDownloadDeleteFileList = TRUE;
	BOOL bDownloadNotice = TRUE;

	if ( ms_pPreIOCP->m_LatestDeleteFileListVersion == CurrentClientDelFileVerion)
	{
		bDownloadDeleteFileList = FALSE;
	}
	else
	{
		bDownloadDeleteFileList = TRUE;
	}
	
	if ( ms_pPreIOCP->m_LatestNoticeVersion == CurrentClientNoticeVersion)
	{
		bDownloadNotice = FALSE;
	}
	else
	{
		bDownloadNotice = TRUE;
	}

	if (bDownloadDeleteFileList || bDownloadNotice)
	{
		INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_SINGLE_FILE_UPDATE_INFO, T_PC_CONNECT_SINGLE_FILE_UPDATE_INFO, msgUpdateInfo, msgUpdateInfoBuf);
		msgUpdateInfo->nAutoUpdateServerType		= g_pPreGlobal->GetAutoUpdateServerType();						// 2007-01-08 by cmkwon, �߰���
		msgUpdateInfo->NewDeleteFileListVersion[0]	= ms_pPreIOCP->m_LatestDeleteFileListVersion.GetVersion()[0];
		msgUpdateInfo->NewDeleteFileListVersion[1]	= ms_pPreIOCP->m_LatestDeleteFileListVersion.GetVersion()[1];
		msgUpdateInfo->NewDeleteFileListVersion[2]	= ms_pPreIOCP->m_LatestDeleteFileListVersion.GetVersion()[2];
		msgUpdateInfo->NewDeleteFileListVersion[3]	= ms_pPreIOCP->m_LatestDeleteFileListVersion.GetVersion()[3];
		msgUpdateInfo->NewNoticeVersion[0]			= ms_pPreIOCP->m_LatestNoticeVersion.GetVersion()[0];
		msgUpdateInfo->NewNoticeVersion[1]			= ms_pPreIOCP->m_LatestNoticeVersion.GetVersion()[1];
		msgUpdateInfo->NewNoticeVersion[2]			= ms_pPreIOCP->m_LatestNoticeVersion.GetVersion()[2];
		msgUpdateInfo->NewNoticeVersion[3]			= ms_pPreIOCP->m_LatestNoticeVersion.GetVersion()[3];
		STRNCPY_MEMSET(msgUpdateInfo->FtpIP, g_pPreGlobal->GetDownloadServerIP(), SIZE_MAX_FTP_URL);
		msgUpdateInfo->FtpPort						= g_pPreGlobal->GetDownloadServerPort();
		STRNCPY_MEMSET(msgUpdateInfo->FtpAccountName, g_pPreGlobal->GetDownloadServerAccountName(), SIZE_MAX_ACCOUNT_NAME);
		STRNCPY_MEMSET(msgUpdateInfo->FtpPassword, g_pPreGlobal->GetDownloadServerPassword(), SIZE_MAX_PASSWORD);
		STRNCPY_MEMSET(msgUpdateInfo->DeleteFileListDownloadPath, g_pPreGlobal->GetDeleteFileListDownloadPath(), SIZE_MAX_FTP_FILE_PATH);
		STRNCPY_MEMSET(msgUpdateInfo->NoticeFileDownloadPath, g_pPreGlobal->GetNoticeFileDownloadPath(), SIZE_MAX_FTP_FILE_PATH);
// 2007-01-08 by cmkwon, ���� ���� ������ - Http ������Ʈ ��� �߰�
//		STRNCPY_MEMSET(msgUpdateInfo->FtpIP, g_pPreGlobal->GetRandomDownloadFTPIP(), SIZE_MAX_FTP_URL);
//		msgUpdateInfo->FtpPort						= g_pPreGlobal->GetDownloadFTPPort();
//		STRNCPY_MEMSET(msgUpdateInfo->FtpAccountName, g_pPreGlobal->GetDownloadFTPAccount(), SIZE_MAX_ACCOUNT_NAME);
//		STRNCPY_MEMSET(msgUpdateInfo->FtpPassword, g_pPreGlobal->GetDownloadFTPPassword(), SIZE_MAX_PASSWORD);
//		STRNCPY_MEMSET(msgUpdateInfo->DeleteFileListDownloadPath, g_pPreGlobal->m_szDeleteFileListDownloadPath, SIZE_MAX_FTP_FILE_PATH);
//		STRNCPY_MEMSET(msgUpdateInfo->NoticeFileDownloadPath, g_pPreGlobal->m_szNoticeFileDownloadPath, SIZE_MAX_FTP_FILE_PATH);
		SendAddData(msgUpdateInfoBuf, MSG_SIZE(MSG_PC_CONNECT_SINGLE_FILE_UPDATE_INFO));
	}
	else
	{
		SendAddMessageType(T_PC_CONNECT_SINGLE_FILE_VERSION_CHECK_OK);
	}
	SetClientState(CP_SINGLE_FILE_VERSIONCHECKED, NULL);

	m_PeerSocketType = ST_CLIENT_TYPE;
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PC_CONNECT_VERSION(const char* pPacket, int nLength, int &nBytesUsed)
{
	int						nRecvTypeSize	= 0;
	BYTE					SendBuf[SIZE_MAX_PACKET];
	MSG_PC_CONNECT_VERSION	*pMsgRecvVersion;
	VersionInfo				CurrentClientVersion;

	nRecvTypeSize = sizeof(MSG_PC_CONNECT_VERSION);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_PC_CONNECT_VERSION, ERR_PROTOCOL_INVALID_FIELD_DATA);

		Close(0x11002, TRUE);
		return RES_RETURN_FALSE;
	}

	pMsgRecvVersion = (MSG_PC_CONNECT_VERSION*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

#ifdef _DEBUG
	if (g_pPreGlobal->m_bIgnoreClientVersionUpdate)
	{
		SendAddMessageType(T_PC_CONNECT_VERSION_OK);
		SetClientState(CP_VERSIONCHECKED, NULL);
		return RES_RETURN_TRUE;
	}
#endif

	// type conversion for temporary use
	CurrentClientVersion.SetVersion(pMsgRecvVersion->ClientVersion[0],
										pMsgRecvVersion->ClientVersion[1],
										pMsgRecvVersion->ClientVersion[2],
										pMsgRecvVersion->ClientVersion[3]);

	if (GetClientState(NULL) != CP_SINGLE_FILE_VERSIONCHECKED)
	{
		// Protocol Error ó��
		// Error Code : ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE
		SendErrorMessage(T_PC_CONNECT_VERSION, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE);

		return RES_BREAK;
	}

	if (g_pPreGlobal->GetClientReinstallVersion() >= CurrentClientVersion
		|| ms_pPreIOCP->m_LatestClientVersion < CurrentClientVersion)
	{
		// send REINSTALL_CLIENT
		INIT_MSG(MSG_PC_CONNECT_REINSTALL_CLIENT, T_PC_CONNECT_REINSTALL_CLIENT, pReinst, SendBuf);
		pReinst->LatestVersion[0] = ms_pPreIOCP->m_LatestClientVersion.GetVersion()[0];
		pReinst->LatestVersion[1] = ms_pPreIOCP->m_LatestClientVersion.GetVersion()[1];
		pReinst->LatestVersion[2] = ms_pPreIOCP->m_LatestClientVersion.GetVersion()[2];
		pReinst->LatestVersion[3] = ms_pPreIOCP->m_LatestClientVersion.GetVersion()[3];
		SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_REINSTALL_CLIENT));

		return RES_BREAK;
	}

	if (ms_pPreIOCP->m_LatestClientVersion == CurrentClientVersion)
	{
		// send VERSION_OK
		SendAddMessageType(T_PC_CONNECT_VERSION_OK);

		SetClientState(CP_VERSIONCHECKED, NULL);
	}
	else // (ms_pPreIOCP->m_LatestClientVersion > CurrentClientVersion)
	{

		// set updateinfo
		VersionInfo tmNewVersion;
		MEMSET_ZERO(&tmNewVersion, sizeof(VersionInfo));

		if (FALSE == ms_pPreIOCP->GetNextUpdateVersion(&tmNewVersion, &CurrentClientVersion))
		{
			SendErrorMessage(T_PC_CONNECT_VERSION, ERR_COMMON_INVALID_CLIENT_VERSION, 0, 0, CurrentClientVersion.GetVersionString(), TRUE);
			return RES_BREAK;
		}

		// send UPDATE_INFO
		INIT_MSG(MSG_PC_CONNECT_UPDATE_INFO, T_PC_CONNECT_UPDATE_INFO, pMsgUpdateInfo, SendBuf);
		pMsgUpdateInfo->nAutoUpdateServerType	= g_pPreGlobal->GetAutoUpdateServerType();			// 2007-01-08 by cmkwon
		pMsgUpdateInfo->OldVersion[0] = CurrentClientVersion.GetVersion()[0];
		pMsgUpdateInfo->OldVersion[1] = CurrentClientVersion.GetVersion()[1];
		pMsgUpdateInfo->OldVersion[2] = CurrentClientVersion.GetVersion()[2];
		pMsgUpdateInfo->OldVersion[3] = CurrentClientVersion.GetVersion()[3];
		pMsgUpdateInfo->UpdateVersion[0] = tmNewVersion.GetVersion()[0];
		pMsgUpdateInfo->UpdateVersion[1] = tmNewVersion.GetVersion()[1];
		pMsgUpdateInfo->UpdateVersion[2] = tmNewVersion.GetVersion()[2];
		pMsgUpdateInfo->UpdateVersion[3] = tmNewVersion.GetVersion()[3];
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpIP, g_pPreGlobal->GetDownloadServerIP(), SIZE_MAX_FTP_URL);
		pMsgUpdateInfo->FtpPort = g_pPreGlobal->GetDownloadServerPort();
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpAccountName, g_pPreGlobal->GetDownloadServerAccountName(), SIZE_MAX_ACCOUNT_NAME);
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpPassword, g_pPreGlobal->GetDownloadServerPassword(), SIZE_MAX_PASSWORD);
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpUpdateDownloadDir, g_pPreGlobal->GetClientUpdateDownloadDir(), SIZE_MAX_FTP_FILE_PATH);
// 2007-01-08 by cmkwon, ���� ���� ������, FTP or Http ������Ʈ ����
//		STRNCPY_MEMSET(pMsgUpdateInfo->FtpIP, g_pPreGlobal->GetRandomDownloadFTPIP(), SIZE_MAX_FTP_URL);
//		pMsgUpdateInfo->FtpPort = g_pPreGlobal->GetDownloadFTPPort();
//		STRNCPY_MEMSET(pMsgUpdateInfo->FtpAccountName, g_pPreGlobal->GetDownloadFTPAccount(), SIZE_MAX_ACCOUNT_NAME);
//		STRNCPY_MEMSET(pMsgUpdateInfo->FtpPassword, g_pPreGlobal->GetDownloadFTPPassword(), SIZE_MAX_PASSWORD);
//// 2005-12-23 by cmkwon
////		strncpy(pMsgUpdateInfo->FtpUpdateDir, g_pPreGlobal->m_szClientFTPUpdateDir, SIZE_MAX_FTP_FILE_PATH);
//		STRNCPY_MEMSET(pMsgUpdateInfo->FtpUpdateDownloadDir, g_pPreGlobal->m_szClientFTPUpdateDownloadDir, SIZE_MAX_FTP_FILE_PATH);

		SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_UPDATE_INFO));
	}

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PC_DEFAULT_UPDATE_LAUNCHER_VERSION(const char* pPacket, int nLength, int &nBytesUsed)
{
	int						nRecvTypeSize	= 0;
	MSG_PC_DEFAULT_UPDATE_LAUNCHER_VERSION	*pMsgRecvVersion;
	VersionInfo				CurrentClientVersion;

	nRecvTypeSize = sizeof(MSG_PC_DEFAULT_UPDATE_LAUNCHER_VERSION);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_PC_DEFAULT_UPDATE_LAUNCHER_VERSION, ERR_PROTOCOL_INVALID_FIELD_DATA);
		Close(0x11003, TRUE);
		return RES_RETURN_FALSE;
	}

	pMsgRecvVersion = (MSG_PC_DEFAULT_UPDATE_LAUNCHER_VERSION*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	// type conversion for temporary use
	CurrentClientVersion.SetVersion(pMsgRecvVersion->Version[0], pMsgRecvVersion->Version[1]
		, pMsgRecvVersion->Version[2], pMsgRecvVersion->Version[3]);

	if ( ms_pPreIOCP->m_LatestLauncherVersion == CurrentClientVersion)
	{
		// send VERSION_OK
		SendAddMessageType(T_PC_DEFAULT_UPDATE_LAUNCHER_VERSION_OK);
	}
	else
	{// Launcher ������ �ٸ��� ������ Update�Ѵ�
		// send UPDATE_INFO
		INIT_MSG_WITH_BUFFER(MSG_PC_DEFAULT_UPDATE_LAUNCHER_UPDATE_INFO, T_PC_DEFAULT_UPDATE_LAUNCHER_UPDATE_INFO, pMsgUpdateInfo, SendBuf);		
		VersionInfo *pNewVersion = &(ms_pPreIOCP->m_LatestLauncherVersion);
		pMsgUpdateInfo->UpdateVersion[0]	= pNewVersion->GetVersion()[0];
		pMsgUpdateInfo->UpdateVersion[1]	= pNewVersion->GetVersion()[1];
		pMsgUpdateInfo->UpdateVersion[2]	= pNewVersion->GetVersion()[2];
		pMsgUpdateInfo->UpdateVersion[3]	= pNewVersion->GetVersion()[3];
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpIP, g_pPreGlobal->GetRandomDownloadFTPIP(), SIZE_MAX_FTP_URL);
		pMsgUpdateInfo->FtpPort				= g_pPreGlobal->GetDownloadFTPPort();
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpAccountName, g_pPreGlobal->GetDownloadFTPAccount(), SIZE_MAX_ACCOUNT_NAME);
		STRNCPY_MEMSET(pMsgUpdateInfo->FtpPassword, g_pPreGlobal->GetDownloadFTPPassword(), SIZE_MAX_PASSWORD);
		STRNCPY_MEMSET(pMsgUpdateInfo->LauncherFileDownloadPath, g_pPreGlobal->m_szLauncherFileDownloadPath, SIZE_MAX_FTP_FILE_PATH);
		SendAddData(SendBuf, MSG_SIZE(MSG_PC_DEFAULT_UPDATE_LAUNCHER_UPDATE_INFO));
	}
	m_PeerSocketType = ST_CLIENT_TYPE;
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PC_CONNECT_LOGIN(const char* pPacket, int nLength, int &nBytesUsed)
{
	int						nRecvTypeSize	= 0;
	char					*pRecvMsg = NULL;

	nRecvTypeSize = sizeof(MSG_PC_CONNECT_LOGIN);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_INVALID_FIELD_DATA);
		Close(0x11005, TRUE);
		return RES_RETURN_FALSE;
	}
	pRecvMsg = new char[sizeof(MSG_PC_CONNECT_LOGIN)];
	memcpy(pRecvMsg, pPacket+nBytesUsed, nRecvTypeSize);
	nBytesUsed += nRecvTypeSize;

	if (GetClientState(NULL) != CP_VERSIONCHECKED)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, GetClientState(NULL));
		SAFE_DELETE(pRecvMsg);
		return RES_BREAK;
	}

	// 2010. 11. 24. by hsLee. �ƶ󸮿� ä�θ� �α��� ���� - ä�θ� �ۺ��� üũ�� ������� ����'AccountName'���� �����ϵ��� ����.
	// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
#ifdef S_ARARIO_HSSON
	char AccountNameArario[SIZE_MAX_ACCOUNT_NAME];

	STRNCPY_MEMSET(AccountNameArario, ((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName, SIZE_MAX_ACCOUNT_NAME);

	strtok(AccountNameArario, "@");

	if(0 != strcmp(AccountNameArario, ((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName))
	{
		m_eOtherPublisherConncect = CONNECT_PUBLISHER_NHN_JPN;
	}
 #endif	// S_ARARIO_HSSON

	if(strnicmp(((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName, "", SIZE_MAX_ACCOUNT_NAME) == 0)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_EMPTY_ACCOUNTNAME);
		SAFE_DELETE(pRecvMsg);
		return RES_BREAK;
	}

	CServerGroup* pSGroup = ms_pPreIOCP->GetServerGroup(((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->FieldServerGroupName);
	if(NULL == pSGroup)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_INVALID_SERVER_GROUP_NAME);
		SAFE_DELETE(pRecvMsg);
		return RES_BREAK;
	}
	else if(pSGroup->GetUserCount() >= pSGroup->m_LimitGroupUserCounts)
	{
		// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - �Ʒ��� ���� ���� ��
		//if(FALSE == IS_SCADMINTOOL_CONNECTABLE_IP(GetPeerIP()))
		if(FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP()))	// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
		{// 2006-04-20 by cmkwon, �系������ ���� ����
			SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_LIMIT_GROUP_USER_COUNT);
			SAFE_DELETE(pRecvMsg);
			return RES_BREAK;
		}
	}

	// 2012-07-11 by hskim, ������ �˴ٿ�
	if( NULL != g_pPreGlobal->m_pSelectiveShutdown )
	{
		if( g_pPreGlobal->m_pSelectiveShutdown->CheckShutdownStatus(((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->SelectiveShutdownInfo) )
		{
			SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_SELECTIVE_SHUTDOWN_NOT_ALLOWED_TIME);
			SAFE_DELETE(pRecvMsg);
			return RES_BREAK;
		}
	}	
	// end 2012-07-11 by hskim, ������ �˴ٿ�

// 2007-11-15 by cmkwon, �ּ� ó�� ��
//	///////////////////////////////////////////////////////////////////////////////
//	// 2007-10-31 by cmkwon, ���� G-Star_���� ó�� - �Ⱓ:2007-11-01 ~ 2007-11-12
//	if(LANGUAGE_TYPE_KOREAN == g_pPreGlobal->GetLanguageType())
//	{
//		MSG_PC_CONNECT_LOGIN *pLogin = (MSG_PC_CONNECT_LOGIN *)pRecvMsg;
//
//		// 2007-11-02 by cmkwon, 'G-Star_����'�� �ƴҶ��� üũ
//		if(0 != stricmp("G-Star_����", pLogin->FieldServerGroupName))
//		{
//			///////////////////////////////////////////////////////////////////////////////
//			// 2007-10-31 by cmkwon, G-Star_���� ���� �㰡 ������ ������ ���� ����
//			if(0 == stricmp("acetest050", pLogin->AccountName) || 0 == stricmp("acetest051", pLogin->AccountName) || 0 == stricmp("acetest052", pLogin->AccountName)
//				 || 0 == stricmp("acetest053", pLogin->AccountName) || 0 == stricmp("acetest054", pLogin->AccountName) || 0 == stricmp("acetest055", pLogin->AccountName)
//				 || 0 == stricmp("acetest056", pLogin->AccountName) || 0 == stricmp("acetest057", pLogin->AccountName) || 0 == stricmp("acetest058", pLogin->AccountName)
//				 || 0 == stricmp("acetest059", pLogin->AccountName) || 0 == stricmp("acetest060", pLogin->AccountName) || 0 == stricmp("acetest061", pLogin->AccountName)
//				 || 0 == stricmp("acetest062", pLogin->AccountName) || 0 == stricmp("acetest063", pLogin->AccountName)
//				  )
//			{
//				SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_INVALID_SERVER_GROUP_NAME);
//				SAFE_DELETE(pRecvMsg);
//				return RES_BREAK;
//			}
//		}
//	}

	
	_strlwr(((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName);		// 2006-05-06 by cmkwon, �ҹ��ڷ� �����Ѵ�.
	STRNCPY_MEMSET(((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->ClientIP, this->GetPeerIP(), SIZE_MAX_IPADDRESS);	// 2008-10-08 by cmkwon, �븸 Netpower_Tpe �ܺ����� ���� - 

	//////////////////////////////////////////
	// Blocked Accounts �˻�
	//////////////////////////////////////////
	char szTmpAccountName[SIZE_MAX_ACCOUNT_NAME];
	STRNCPY_MEMSET(szTmpAccountName, ((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName, SIZE_MAX_ACCOUNT_NAME);

	if(LANGUAGE_TYPE_TAIWANESE != g_pPreGlobal->GetLanguageType()
		|| g_pPreGlobal->IsExternalAuthentication())
	{// 2008-10-09 by cmkwon, �븸 Netpower_Tpe�� �ܺ� �����Ŀ� üũ�ϵ��� �Ѵ�. 2�ܰ� �����ý��� ��������

		
		// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] LanguageType[%d], BlockedAccountName[%s] \r\n", g_pPreGlobal->GetLanguageType(), szTmpAccountName);
		// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

		SBLOCKED_ACCOUNT_INFO tmBlockedInfo;
		MEMSET_ZERO(&tmBlockedInfo, sizeof(SBLOCKED_ACCOUNT_INFO));
		BOOL bBlocked = ms_pPreIOCP->m_pAccountBlockManager->IsCheckBlockedAccountInfoByAccountName(&tmBlockedInfo, szTmpAccountName, NULL);
		if(bBlocked && FALSE == g_pPreGlobal->CheckAllowedToolIP(this->GetPeerIP())) // 2013-09-23 by jekim, Tool IP���� ���� ��� ��ȸ�ǰ� ����.
		{
			// 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����
			g_pGlobalGameServer->WriteSystemLogEX(TRUE, "  [ACCOUNT_BLOCK_INFO] IsCheckBlockedAccountInfoByAccountName[%s] NOT BLOCKED_USER!! \r\n", szTmpAccountName);
			// End. 2015-05-26 by bckim, ��Ʈ�� ������ �α��εǴ� ���� �α� ����

			INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_LOGIN_BLOCKED, T_PC_CONNECT_LOGIN_BLOCKED, pSBlocked, SendBuf);
			STRNCPY_MEMSET(pSBlocked->szAccountName, tmBlockedInfo.szBlockedAccountName, SIZE_MAX_ACCOUNT_NAME);		// 2007-01-10 by cmkwon
			pSBlocked->nBlockedType		= tmBlockedInfo.enBlockedType;
			pSBlocked->atimeStart		= tmBlockedInfo.atimeStartTime;
			pSBlocked->atimeEnd			= tmBlockedInfo.atimeEndTime;
			STRNCPY_MEMSET(pSBlocked->szBlockedReasonForUser, tmBlockedInfo.szBlockedReasonForUser, SIZE_MAX_BLOCKED_ACCOUNT_REASON);		// 2007-01-10 by cmkwon
			SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_LOGIN_BLOCKED));		

			SAFE_DELETE(pRecvMsg);
			return RES_BREAK;
		}
	}

// 2005-06-02 by cmkwon
//	ms_pPreIOCP->m_setBlockedAccounts.lock();
//	if (ms_pPreIOCP->m_setBlockedAccounts.find(szTmpAccountName)
//		!= ms_pPreIOCP->m_setBlockedAccounts.end())
//	{
//		ms_pPreIOCP->m_setBlockedAccounts.unlock();
//
//		// ���� ������
//		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_ACCOUNT_BLOCKED, 0, 0, ((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->AccountName);
//		SAFE_DELETE(pRecvMsg);
//		return RES_BREAK;
//	}
//	ms_pPreIOCP->m_setBlockedAccounts.unlock();

	// 'pRecvMsg' should be deleted by DBManager
	if (((MSG_PC_CONNECT_LOGIN*)pRecvMsg)->LoginType == LOGIN_TYPE_DIRECT)
	{
		ms_pPreIOCP->m_pAtumDBManager->MakeAndEnqueueQuery(QT_PRE_Login, this, (void*)pRecvMsg);
	}
	else
	{
		ms_pPreIOCP->m_pAtumDBManager->MakeAndEnqueueQuery(QT_MGameLogin, this, (void*)pRecvMsg);
	}
	pRecvMsg = NULL;

	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	STRNCPY_MEMSET(m_szAdminAccountName, szTmpAccountName, SIZE_MAX_ACCOUNT_NAME);

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PC_CONNECT_GET_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed)
{
	// no body

	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_GET_SERVER_GROUP_LIST_OK, T_PC_CONNECT_GET_SERVER_GROUP_LIST_OK, pListOK, pListOKBuf);
	pListOK->NumOfServerGroup = 0;
	MEX_SERVER_GROUP_INFO_FOR_LAUNCHER *arrServerInfo
		= (MEX_SERVER_GROUP_INFO_FOR_LAUNCHER*)(pListOKBuf + MSG_SIZE(MSG_PC_CONNECT_GET_SERVER_GROUP_LIST_OK));

	vector<CServerGroup*>::iterator itr = ms_pPreIOCP->m_AllServerGroupVector.begin();
	for (; itr != ms_pPreIOCP->m_AllServerGroupVector.end(); itr++)
	{
		CServerGroup *pServerGroup = *itr;

		// 2008-06-13 by dhjin, �Ʒ��� ���� - �Ʒ��� ���� ���� �Ǿ� ���� ������ ���� ȭ�鿡 ���̴� �κ� �Ⱥ��̰� ����
		if(10090 == pServerGroup->m_nMGameServerID)
		{
			continue;
		}

		if(pServerGroup->m_bEnableServerGroup
			&& FALSE == pServerGroup->m_bForbidViewServer	// 2007-12-22 by dhjin, �Ʒ��� ���� - ���� ����Ʈ���� ���̸� �ȵǴ� ���� üũ, TRUE = ������ �ʴ´�.	
			)	
		{
			STRNCPY_MEMSET(arrServerInfo[pListOK->NumOfServerGroup].ServerGroupName, pServerGroup->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
			if(FALSE == pServerGroup->m_IMServerInfo.IsActive
				|| FALSE == pServerGroup->m_FieldServerInfo.IsActive)
			{
				arrServerInfo[pListOK->NumOfServerGroup].Crowdedness = 0;
			}
			else
			{
				int nCrowdedness = (pServerGroup->GetUserCount()*100)/pServerGroup->m_LimitGroupUserCounts;
				arrServerInfo[pListOK->NumOfServerGroup].Crowdedness = max(1, nCrowdedness);
			}
			pListOK->NumOfServerGroup++;
		}
	}

	SendAddData(pListOKBuf, MSG_SIZE(MSG_PC_CONNECT_GET_SERVER_GROUP_LIST_OK) + pListOK->NumOfServerGroup * sizeof(MEX_SERVER_GROUP_INFO_FOR_LAUNCHER));

	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-08 ~ 2007-01-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION(const char* pPacket, int nLength, int &nBytesUsed)
{
	int						nRecvTypeSize	= 0;
	MSG_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION	*pMsgRecvVersion;
	VersionInfo				CurrentClientVersion;

	nRecvTypeSize = sizeof(MSG_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION, ERR_PROTOCOL_INVALID_FIELD_DATA);
		Close(0x11003, TRUE);
		return RES_RETURN_FALSE;
	}

	pMsgRecvVersion = (MSG_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	///////////////////////////////////////////////////////////////////////////////
	// 
	m_PeerSocketType = ST_CLIENT_TYPE;		// 2007-01-08 by cmkwon

	///////////////////////////////////////////////////////////////////////////////	
	// type conversion for temporary use
	CurrentClientVersion.SetVersion(pMsgRecvVersion->Version[0], pMsgRecvVersion->Version[1]
		, pMsgRecvVersion->Version[2], pMsgRecvVersion->Version[3]);

	if ( ms_pPreIOCP->m_LatestLauncherVersion == CurrentClientVersion)
	{
		// send VERSION_OK
		SendAddMessageType(T_PC_DEFAULT_UPDATE_LAUNCHER_VERSION_OK);
		return RES_RETURN_TRUE;
	}

	INIT_MSG_WITH_BUFFER(MSG_PC_DEFAULT_NEW_UPDATE_LAUNCHER_UPDATE_INFO, T_PC_DEFAULT_NEW_UPDATE_LAUNCHER_UPDATE_INFO, pMsgUpdateInfo, SendBuf);
	pMsgUpdateInfo->nAutoUpdateServerType	= g_pPreGlobal->GetAutoUpdateServerType();
	VersionInfo *pNewVersion = &(ms_pPreIOCP->m_LatestLauncherVersion);
	pMsgUpdateInfo->UpdateVersion[0]		= pNewVersion->GetVersion()[0];
	pMsgUpdateInfo->UpdateVersion[1]		= pNewVersion->GetVersion()[1];
	pMsgUpdateInfo->UpdateVersion[2]		= pNewVersion->GetVersion()[2];
	pMsgUpdateInfo->UpdateVersion[3]		= pNewVersion->GetVersion()[3];
	STRNCPY_MEMSET(pMsgUpdateInfo->UpdateServerIP, g_pPreGlobal->GetDownloadServerIP(), SIZE_MAX_FTP_URL);
	pMsgUpdateInfo->UpdateServerPort		= g_pPreGlobal->GetDownloadServerPort();
	STRNCPY_MEMSET(pMsgUpdateInfo->AccountName, g_pPreGlobal->GetDownloadServerAccountName(), SIZE_MAX_ACCOUNT_NAME);
	STRNCPY_MEMSET(pMsgUpdateInfo->Password, g_pPreGlobal->GetDownloadServerPassword(), SIZE_MAX_PASSWORD);
	STRNCPY_MEMSET(pMsgUpdateInfo->LauncherFileDownloadPath, g_pPreGlobal->GetLauncherFileDownloadPath(), SIZE_MAX_FTP_FILE_PATH);
	SendAddData(SendBuf, MSG_SIZE(MSG_PC_DEFAULT_NEW_UPDATE_LAUNCHER_UPDATE_INFO));
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed)
{
	// 2007-10-19 by cmkwon, AllowedIP �ý��� ���� - �㰡 IP üũ �Լ�
	if(FALSE == g_pPreGlobal->CheckAllowedIP(this->GetPeerIP()))
	{
		SendErrorMessage(T_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST, ERR_NOT_ALLOWED_IP, 0, 0, this->GetPeerIP());
		this->Close();
		return RES_BREAK;		
	}

	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK, T_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK, pSGameServerGroupListOK, SendBuf);
	if(FALSE == g_pPreGlobal->Make_MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(pSGameServerGroupListOK))
	{
		return RES_BREAK;
	}
	SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK));
	
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �߰��� �������� ó���Լ�
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed)
{
	// 2007-10-19 by cmkwon, AllowedIP �ý��� ���� - �㰡 IP üũ �Լ�
	if(FALSE == g_pPreGlobal->CheckAllowedIP(this->GetPeerIP()))
	{
		SendErrorMessage(T_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST, ERR_NOT_ALLOWED_IP, 0, 0, this->GetPeerIP());
		this->Close();
		return RES_BREAK;		
	}

	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK, T_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK, pSGameServerGroupListOK, SendBuf);
	if(FALSE == g_pPreGlobal->Make_MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK(pSGameServerGroupListOK))
	{
		return RES_BREAK;
	}
	SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK));
	
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PC_CONNECT_NETWORK_CHECK(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2007-06-18 by cmkwon, ��Ʈ��ũ ���� üũ
/// \author		cmkwon
/// \date		2007-05-02 ~ 2007-05-02
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PC_CONNECT_NETWORK_CHECK(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_PC_CONNECT_NETWORK_CHECK,
		MSG_PC_CONNECT_NETWORK_CHECK, pRecvMsg);

	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_NETWORK_CHECK_OK, T_PC_CONNECT_NETWORK_CHECK_OK, pNetCheckOK, SendBuf);
	pNetCheckOK->nCheckCount	= pRecvMsg->nCheckCount;
	SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_NETWORK_CHECK_OK));

	return RES_RETURN_TRUE;
}


ProcessResult CPreIOCPSocket::Process_FP_CONNECT_AUTH_USER(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;
	MSG_FP_CONNECT_AUTH_USER	*pMsgRecvAuthUser;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_AUTH_USER);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecvAuthUser = (MSG_FP_CONNECT_AUTH_USER*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	CAccountInfo tmAccountInfo;
	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_CONNECT_AUTH_USER(&tmAccountInfo, pMsgRecvAuthUser);

	switch(nRetedErrorNum)
	{
	case 0:// ���� ����
		{
			//
			CServerGroup* pSGroup = ms_pPreIOCP->GetServerGroup(tmAccountInfo.CurrentServerGroup);
			if(pSGroup)
			{
				if(pMsgRecvAuthUser->AuthType == PRESERVER_AUTH_TYPE_LOGIN)
				{
					pSGroup->m_AccumulatedGroupUserCounts++;
				}
			}

			//////////////////////////////
			// Send AUTH_USER_OK
			INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_AUTH_USER_OK, T_FP_CONNECT_AUTH_USER_OK, pSendMsg, pSendBuf);			
			STRNCPY_MEMSET(pSendMsg->AccountName, tmAccountInfo.AccountName, SIZE_MAX_ACCOUNT_NAME);
			pSendMsg->AccountUniqueNumber	= tmAccountInfo.AccountUniqueNumber;
			pSendMsg->ClientIndex			= pMsgRecvAuthUser->ClientIndex;
			pSendMsg->AuthType				= pMsgRecvAuthUser->AuthType;
			pSendMsg->GalaNetAccountIDNum	= tmAccountInfo.nExtAuthAccountIDNum;		// 2006-06-01 by cmkwon, exteranl authentication DB accountID Number
			pSendMsg->AccountRegisteredDate	= tmAccountInfo.AccountRegisteredDate;		// 2006-06-02 by cmkwon
			pSendMsg->GameContinueTimeInSecondOfToday	= tmAccountInfo.GameContinueTimeInSecondOfToday;		// 2006-11-15 by cmkwon
			pSendMsg->LastGameEndDate					= tmAccountInfo.LastGameEndDate;						// 2006-11-15 by cmkwon
			pSendMsg->Birthday							= tmAccountInfo.atBirthday;								// 2007-06-28 by cmkwon, �߱� ��������(�������� FielServer�� ��������) - �������� ����
			pSendMsg->UserType							= tmAccountInfo.AccountType;								// 2013-01-18 by khkim, GLog ���� ���� 
			STRNCPY_MEMSET(pSendMsg->PasswordFromDB, tmAccountInfo.PasswordFromDB, SIZE_MAX_PASSWORD_MD5_STRING);	// 2006-06-02 by cmkwon
			STRNCPY_MEMSET(pSendMsg->SecondaryPassword, tmAccountInfo.SecondaryPassword, SIZE_MAX_PASSWORD_MD5_STRING);	// 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - Field Server�� ����
#ifdef S_ARARIO_HSSON
			pSendMsg->eOtherPublisherConncect = tmAccountInfo.eOtherPublisherConncect;				// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
#endif

			SendAddData(pSendBuf, MSG_SIZE(MSG_FP_CONNECT_AUTH_USER_OK));			
			return RES_RETURN_TRUE;
		}
		break;
	case ERR_PROTOCOL_NOT_LOGINED:
		{
			// Protocol Error ó��
			// Error Code : ERR_PROTOCOL_NOT_LOGINED
			SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_PROTOCOL_NOT_LOGINED, pMsgRecvAuthUser->ClientIndex);
		}
		break;
	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE:
		{
			// Protocol Error ó��
			// Error Code : ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE
			SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, pMsgRecvAuthUser->ClientIndex);
		}
		break;
	case ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED:
		{
			// Protocol Error ó��
			// Error Code : ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED
			DBGOUT("ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED: %s != %s\n", tmAccountInfo.CurrentFieldServerID.GetString(string()), pMsgRecvAuthUser->FieldServerID.GetString(string()));
			SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED, pMsgRecvAuthUser->ClientIndex, 0, tmAccountInfo.AccountName);
		}
		break;
	case ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED:
		{
			// Protocol Error ó��
			// Error Code : ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED
#ifdef _DEBUG
			DBGOUT("MSG_FP_CONNECT_AUTH_USER(%s) != CAccountInfo(%s)\n", pMsgRecvAuthUser->PrivateIP, tmAccountInfo.PrivateClientIP);
#endif
			SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED, pMsgRecvAuthUser->ClientIndex, 0, tmAccountInfo.AccountName);
		}
		break;
	default:
		{
			SendErrorMessage(T_FP_CONNECT_AUTH_USER, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0);
		}
	}

	return RES_BREAK;
}

ProcessResult CPreIOCPSocket::Process_IP_CONNECT_IM_CONNECT(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;
	MSG_IP_CONNECT_IM_CONNECT *pMsgRecvIMConnect;

	nRecvTypeSize = sizeof(MSG_IP_CONNECT_IM_CONNECT);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_IP_CONNECT_IM_CONNECT, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecvIMConnect = (MSG_IP_CONNECT_IM_CONNECT*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	CServerGroup *pServerGroup = ms_pPreIOCP->GetServerGroup(pMsgRecvIMConnect->ServerGroupName);
	if (pServerGroup == NULL)
	{
		SendErrorMessage(T_IP_CONNECT_IM_CONNECT, ERR_PROTOCOL_NO_SUCH_SERVER_GROUP, 0, 0, pMsgRecvIMConnect->ServerGroupName);
		Close(0x11008, TRUE);
		return RES_RETURN_FALSE;
	}

	if (pServerGroup->m_IMServerInfo.IsActive
		&& pServerGroup->m_IMServerInfo.pSocket
		&& pServerGroup->m_IMServerInfo.pSocket->IsUsing())
	{
		// error: �̹� ����� ������ ����
		SendErrorMessage(T_IP_CONNECT_IM_CONNECT, ERR_PROTOCOL_IMSERVER_ALREADY_CONNECTED);
		Close(0x1100A, TRUE);
		return RES_RETURN_FALSE;
	}

	STRNCPY_MEMSET(this->m_szConnectedServerGroupName, pServerGroup->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
	m_PeerSocketType = ST_IM_SERVER;
	
// 2006-05-10 by cmkwon, �Ʒ��� ���� IMServer IP�� ���۹������� �����Ѵ�
//	pServerGroup->m_IMServerInfo.serverID.SetValue(GetPeerIP(), pMsgRecvIMConnect->IMServerListenPort);
	pServerGroup->m_IMServerInfo.serverID	= pMsgRecvIMConnect->IMServerID;
	pServerGroup->m_IMServerInfo.IsActive	= TRUE;
	pServerGroup->m_IMServerInfo.pSocket	= this;
	pServerGroup->m_IMServerInfo.ServerType	= ST_IM_SERVER;
	
	char szTemp[1024];
	// 2009-04-15 by cmkwon, �ý��� �α� ���� - 
	wsprintf(szTemp, "ServerGroupName(%s) IMServer(%s), PeerIPPort[%s:%d] registeration done...\r\n", pServerGroup->m_ServerGroupName, pServerGroup->m_IMServerInfo.serverID.IP, GetPeerIP(), GetPeerPort());
	DBGOUT(szTemp);
	g_pPreGlobal->WriteSystemLog(szTemp);

	// send T_FP_CONNECT_FIELD_CONNECT_OK
	this->SendAddMessageType(T_IP_CONNECT_IM_CONNECT_OK);
	return RES_RETURN_TRUE;
}


ProcessResult CPreIOCPSocket::Process_IP_GET_SERVER_GROUP_INFO_ACK(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;
	MSG_IP_GET_SERVER_GROUP_INFO_ACK *pMsgRecv;

	nRecvTypeSize = sizeof(MSG_IP_GET_SERVER_GROUP_INFO_ACK);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_IP_GET_SERVER_GROUP_INFO_ACK, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecv = (MSG_IP_GET_SERVER_GROUP_INFO_ACK*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	CServerGroup *pServerGroup = ms_pPreIOCP->GetServerGroup(pMsgRecv->ServerGroupName);
	if (pServerGroup == NULL)
	{
		SendErrorMessage(T_IP_GET_SERVER_GROUP_INFO_ACK, ERR_PROTOCOL_NO_SUCH_SERVER_GROUP);
		return RES_BREAK;
	}

	pServerGroup->m_MaxGroupUserCounts			= pMsgRecv->IMMaxUserCounts;

	BYTE	SendBuf[SIZE_MAX_PACKET];
	INIT_MSG(MSG_PM_GET_SERVER_GROUP_INFO_ACK, T_PM_GET_SERVER_GROUP_INFO_ACK, pSendGroupInfo, SendBuf);
	STRNCPY_MEMSET(pSendGroupInfo->ServerGroupName, pServerGroup->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
	pSendGroupInfo->IMServerID = pServerGroup->m_IMServerInfo.serverID;
	pSendGroupInfo->AccumulatedGroupUserCounts	= pServerGroup->m_AccumulatedGroupUserCounts;
	pSendGroupInfo->CurrentGroupUserCounts		= pMsgRecv->IMCurrentUserCounts;
	pSendGroupInfo->MaxGroupUserCounts			= pMsgRecv->IMMaxUserCounts;
	pSendGroupInfo->bEnableServerGroup			= pServerGroup->m_bEnableServerGroup;
	pSendGroupInfo->LimitGroupUserCounts		= pServerGroup->m_LimitGroupUserCounts;
	ms_pPreIOCP->SendMessageToMonitor(SendBuf, MSG_SIZE(MSG_PM_GET_SERVER_GROUP_INFO_ACK));
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_PM_PREPARE_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed)
{
	return RES_RETURN_TRUE; // 2011-11-18 by shcho, �����ٿ� ���������ٿ� ���� ó�� - 

	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_PM_PREPARE_SHUTDOWN
		, MSG_PM_PREPARE_SHUTDOWN, pRMsg);

	CServerGroup *pServerGroup = ms_pPreIOCP->GetServerGroup(pRMsg->ServerGroupName);
	if (pServerGroup == NULL)
	{
		SendErrorMessage(T_PM_PREPARE_SHUTDOWN, ERR_PROTOCOL_NO_SUCH_SERVER_GROUP);
		return RES_BREAK;
	}

	MessageType_t msgTy = T_FP_CONNECT_PREPARE_SHUTDOWN;
	pServerGroup->SendMessageToFieldServer((BYTE*)&msgTy, SIZE_FIELD_TYPE_HEADER);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_HEADER(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-09 ~ 2007-01-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_HEADER(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_PM_RELOAD_VERSION_INFO_HEADER
		, MSG_PM_RELOAD_VERSION_INFO_HEADER, pRMsg);


	mt_auto_lock mtTV(&(ms_pPreIOCP->m_tmmtmapVersionOld2New));

	ms_pPreIOCP->m_tmmtmapVersionOld2New.clear();
	ms_pPreIOCP->m_tmTotalNumOfClientVersions		= pRMsg->TotalNumOfClientVersions;
	ms_pPreIOCP->m_tmLatestLauncherVersion.SetVersion(pRMsg->LauncherVersion);
	ms_pPreIOCP->m_tmLatestDeleteFileListVersion.SetVersion(pRMsg->DeleteFileListVersion);
	ms_pPreIOCP->m_tmLatestNoticeVersion.SetVersion(pRMsg->NoticeVersion);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_LIST(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-09 ~ 2007-01-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_LIST(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_PM_RELOAD_VERSION_INFO_LIST
		, MSG_PM_RELOAD_VERSION_INFO_LIST, pRMsg);

	if(nLength-nBytesUsed < pRMsg->NumOfClientVersions * (sizeof(USHORT)*8))
	{
		SendErrorMessage(T_PM_RELOAD_VERSION_INFO_LIST, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_RETURN_FALSE;
	}
	nBytesUsed		+= pRMsg->NumOfClientVersions * (sizeof(USHORT)*8);


	mt_auto_lock mtTV(&(ms_pPreIOCP->m_tmmtmapVersionOld2New));

	for (int i = 0; i < pRMsg->NumOfClientVersions; i++)
	{
		USHORT *pOldVersionArray = (USHORT*)(((char*)pRMsg) + sizeof(MSG_PM_RELOAD_VERSION_INFO_LIST) + i*8*sizeof(USHORT));
		USHORT *pNewVersionArray = (USHORT*)(((char*)pRMsg) + sizeof(MSG_PM_RELOAD_VERSION_INFO_LIST) + i*8*sizeof(USHORT) + 4*sizeof(USHORT));

		VersionInfo OldVersion(pOldVersionArray);
		VersionInfo NewVersion(pNewVersionArray);

		ms_pPreIOCP->m_tmmtmapVersionOld2New.insertLock(OldVersion, NewVersion);
	}

	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_DONE(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2007-01-09 ~ 2007-01-09
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PM_RELOAD_VERSION_INFO_DONE(const char* pPacket, int nLength, int &nBytesUsed)
{
	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	ms_pPreIOCP->m_bPauseService = TRUE;
	
	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	mt_auto_lock mtV(&(ms_pPreIOCP->m_mtmapVersionOld2New));
	mt_auto_lock mtTV(&(ms_pPreIOCP->m_tmmtmapVersionOld2New));

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	ms_pPreIOCP->m_mtmapVersionOld2New.clear();
	ms_pPreIOCP->m_LatestLauncherVersion		= ms_pPreIOCP->m_tmLatestLauncherVersion;
	ms_pPreIOCP->m_LatestDeleteFileListVersion	= ms_pPreIOCP->m_tmLatestDeleteFileListVersion;
	ms_pPreIOCP->m_LatestNoticeVersion			= ms_pPreIOCP->m_tmLatestNoticeVersion;

	mtmapVersionInfo::iterator itr = ms_pPreIOCP->m_tmmtmapVersionOld2New.begin();
	for(; itr != ms_pPreIOCP->m_tmmtmapVersionOld2New.end(); itr++)
	{
		ms_pPreIOCP->m_mtmapVersionOld2New.insertLock(itr->first, itr->second);
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	if (false == ms_pPreIOCP->m_mtmapVersionOld2New.empty())
	{// 2007-01-09 by cmkwon, ������ ���� ����
		ms_pPreIOCP->m_LatestClientVersion		= ms_pPreIOCP->m_mtmapVersionOld2New.rbegin()->second;
	}
	
	mtTV.auto_unlock_cancel();
	mtV.auto_unlock_cancel();
	
	///////////////////////////////////////////////////////////////////////////////	
	// write versions
	ms_pPreIOCP->WriteVersionInfoToLocalFile();

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	ms_pPreIOCP->m_bPauseService = FALSE;

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-09 by cmkwon
	SendAddMessageType(T_PM_RELOAD_VERSION_INFO_OK);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-09-08 by cmkwon, SCMonitor���� ReloadVersionInfo�ÿ� �Ϻ� üũ������(.\Res-Tex\*.*)�� ���ε��ϱ� - ��� FieldServer�� �޽��� ����
	MessageType_t msgTy = T_FP_MONITOR_RELOAD_VERSION_INFO_OK;
	ms_pPreIOCP->SendMessageToAllFieldServer((BYTE*)(&msgTy), SIZE_FIELD_TYPE_HEADER);

	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	g_pPreGlobal->ReLoadConfiguration();
	MessageType_t msgTy2 = T_IP_MONITOR_RELOAD_VERSION_INFO_OK;
	ms_pPreIOCP->SendMsgToAllIMServer((BYTE*)&msgTy2, SIZE_FIELD_TYPE_HEADER);
#endif
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����

	return RES_RETURN_TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_PP_CONNECT(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_PP_CONNECT(const char* pPacket, int nLength, int &nBytesUsed)
{
	// 2008-02-22 by cmkwon, ���� ������ ������ �����Ѵ�.
	g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Service PreServer Connected: PreServerIP(%15s)\r\n", GetPeerIP());

	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_PP_CONNECT, MSG_PP_CONNECT, pRMsg);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-02-22 by cmkwon, ���� ������ �ý��� �α׷� �����Ѵ�.
	char szGameLog[1024];
	MEMSET_ZERO(szGameLog, 1024);
	pRMsg->GetWriteLogString(szGameLog);
	g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Service PreServer      Info: PreServerIP(%15s) %s", GetPeerIP(), szGameLog);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-02-22 by cmkwon, ���� üũ �ʿ��� �κ� ����� ������ T_PP_CONNECT_OK �� �����Ѵ�.
	INIT_MSG_WITH_BUFFER(MSG_PP_CONNECT_OK, T_PP_CONNECT_OK, pSMsg, SendBuf);
	pSMsg->szPreServerODBCDSN;
	pSMsg->szPreServerODBCUID;
	pSMsg->szPreServerODBCPASSWORD;
	this->SendAddData(SendBuf, MSG_SIZE(MSG_PP_CONNECT_OK));

	///////////////////////////////////////////////////////////////////////////////
	// 2008-02-22 by cmkwon, �ٷ� ���� ��ƾ ��û ����
	this->SendAddMessageType(T_PP_CONNECT_DO_CLOSE);
	return RES_RETURN_TRUE;
}

/*
1. �ʵ� ������ active ���·� ��ȯ
2. ���� ������ ������ �ִ� ip�� �ʵ� ���� �̸�, ������ �̸��� �� Ȯ��

- �� ���������� �ʵ� ������ ���� ������ ��Ͻ�Ű�� ����
*/
ProcessResult CPreIOCPSocket::Process_FP_CONNECT_FIELD_CONNECT(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;
	MSG_FP_CONNECT_FIELD_CONNECT *pMsgRecvFieldConnect;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_FIELD_CONNECT)
			+ ((MSG_FP_CONNECT_FIELD_CONNECT*)(pPacket+nBytesUsed))->NumOfMapIndex * sizeof(MapIndex_t);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_FP_CONNECT_FIELD_CONNECT, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecvFieldConnect = (MSG_FP_CONNECT_FIELD_CONNECT*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	CServerGroup *pServerGroup = ms_pPreIOCP->GetServerGroup(pMsgRecvFieldConnect->FieldServerGroupName);
	if (pServerGroup == NULL)
	{
		SendErrorMessage(T_FP_CONNECT_FIELD_CONNECT, ERR_PROTOCOL_NO_SUCH_SERVER_GROUP);
		Close(0x1100C, TRUE);
		return RES_RETURN_FALSE;
	}
	
	if (pServerGroup->m_FieldServerInfo.IsActive)
	{
		SendErrorMessage(T_FP_CONNECT_FIELD_CONNECT, ERR_PROTOCOL_FIELD_SERVER_ALREADY_REGISTERD);
		Close(0x1100D, TRUE);
		return RES_RETURN_FALSE;
	}

	STRNCPY_MEMSET(this->m_szConnectedServerGroupName, pServerGroup->m_ServerGroupName, SIZE_MAX_SERVER_NAME);
	m_PeerSocketType = ST_FIELD_SERVER;

	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	pServerGroup->m_LimitGroupUserCounts				= pMsgRecvFieldConnect->DBServerGroup.LimitUserCount;
	pServerGroup->m_bLockCreateCharacterForNewAccount	= pMsgRecvFieldConnect->DBServerGroup.LockCreateCharacterForNewAccount;

	// 2007-12-26 by dhjin, �Ʒ��� ���� - TRUE => �Ʒ��� �ʵ� ����
	if(TRUE == pMsgRecvFieldConnect->ArenaFieldServerCheck)
	{// 2007-12-26 by dhjin, �Ʒ��� ���� - �Ʒ��� ������ ���� ��Ͽ��� �����Ѵ�.
		pServerGroup->m_bForbidViewServer = TRUE;
	}
	FieldServerInfo *pFieldServerInfo = &pServerGroup->m_FieldServerInfo;
	pFieldServerInfo->serverID		= pMsgRecvFieldConnect->FieldServerID;
	pFieldServerInfo->pSocket		= this;
	pFieldServerInfo->ServerType	= ST_FIELD_SERVER;
	for (int i = 0; i < pMsgRecvFieldConnect->NumOfMapIndex; i++)
	{
		MapIndex_t tmpMapIndex
			= *(MapIndex_t*)(((char*)pMsgRecvFieldConnect) + sizeof(MSG_FP_CONNECT_FIELD_CONNECT) + sizeof(MapIndex_t)*i);
// 2004-12-15 by cmkwon, FieldServer�� �������� �ϳ���
//		BOOL ret = pServerGroup->m_MapIndex2FieldServerMap.insertLock(tmpMapIndex, pFieldServerInfo);
//
//		if (!ret)
//		{
//			SendErrorMessage(T_FP_CONNECT_FIELD_CONNECT, ERR_PROTOCOL_MAP_ALREADY_SERVED_BY_FEILD_SERVER);
//			Close(0x11010, TRUE);
//			return RES_RETURN_FALSE;
//		}

		pFieldServerInfo->MapIndexVector.push_back(tmpMapIndex);
#ifdef _DEBUG
		DBGOUT("FieldServer(%s) -> %04d\n", pFieldServerInfo->serverID.GetString(string()), tmpMapIndex);
#endif
	}
	pFieldServerInfo->IsActive = TRUE;				// Map�� ��� �߰��ϰ� TRUE�� �����Ѵ�

	char szTemp[1024];
	// 2009-04-15 by cmkwon, �ý��� �α� ���� - 
	wsprintf(szTemp, "ServerGroup(%s) FieldServer(%s), PeerIPPort[%s:%d] registeration done...\r\n", pServerGroup->m_ServerGroupName, pFieldServerInfo->serverID.GetString(string()), GetPeerIP(), GetPeerPort());
	DBGOUT(szTemp);
	g_pPreGlobal->WriteSystemLog(szTemp);

	// send T_FP_CONNECT_FIELD_CONNECT_OK
	INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_FIELD_CONNECT_OK, T_FP_CONNECT_FIELD_CONNECT_OK, pSend, SBuff);
	pSend->CurrentMGameEventType = g_pPreGlobal->m_enMGameEventType;
	SendAddData(SBuff, MSG_SIZE(MSG_FP_CONNECT_FIELD_CONNECT_OK));
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_CONNECT_NOTIFY_CLOSE(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;
	MSG_FP_CONNECT_NOTIFY_CLOSE *pMsgRecvClose;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_NOTIFY_CLOSE);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_FP_CONNECT_NOTIFY_CLOSE, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecvClose = (MSG_FP_CONNECT_NOTIFY_CLOSE*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

#ifdef _DEBUG
	DBGOUT("%s NOTIFY_CLOSE: %s\n", GetTimeString(string()), pMsgRecvClose->AccountName);
#endif

	// 2010-04-26 by cmkwon, ���þ� Innva ����/���� �ý��� ���� - 
	//ms_pPreIOCP->DeleteAccountInfo(pMsgRecvClose->AccountName);
	///////////////////////////////////////////////////////////////////////////////
	// 2010-04-26 by cmkwon, ���þ� Innva ����/���� �ý��� ���� - 
	if(ms_pPreIOCP->DeleteAccountInfo(pMsgRecvClose->AccountName))
	{
		ms_pPreIOCP->INNBILL_LogOut(pMsgRecvClose->AccountName);
	}

//#ifdef _DEBUG
//	ms_pPreIOCP->DBG_PrintAccountMap();
//#endif

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_EVENT_NOTIFY_WARP(const char* pPacket, int nLength, int &nBytesUsed)
{
// 2005-07-27 by cmkwon, �ٸ� �ʵ弭������ ������ �����Ƿ� ������
//	int		nRecvTypeSize	= 0;
//	MSG_FP_EVENT_NOTIFY_WARP *pMsgRecvWarp;
//
//	nRecvTypeSize = sizeof(MSG_FP_EVENT_NOTIFY_WARP);
//	if(nLength - nBytesUsed < nRecvTypeSize)
//	{
//		// Protocl Error ó��
//		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
//		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
//		SendErrorMessage(T_FP_EVENT_NOTIFY_WARP, ERR_PROTOCOL_INVALID_FIELD_DATA);
//		return RES_PACKET_ERROR;
//	}
//	pMsgRecvWarp = (MSG_FP_EVENT_NOTIFY_WARP*)(pPacket+nBytesUsed);
//	nBytesUsed += nRecvTypeSize;
//
//	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_EVENT_NOTIFY_WARP(pMsgRecvWarp);
//	switch(nRetedErrorNum)
//	{
//	case 0:// ���� ����
//		{
//			//////////////////////////////
//			// Send AUTH_USER_OK
//			INIT_MSG_WITH_BUFFER(MSG_FP_EVENT_NOTIFY_WARP_OK, T_FP_EVENT_NOTIFY_WARP_OK, pSendMsg, pSendBuf);			
//			pSendMsg->CharacterUniqueNumber = pMsgRecvWarp->CharacterUniqueNumber;
//			
//			SendAddData(pSendBuf, MSG_SIZE(MSG_FP_CONNECT_AUTH_USER_OK));			
//			return RES_RETURN_TRUE;
//		}
//		break;
//	case ERR_PROTOCOL_NOT_LOGINED:
//		{
//			// Protocol Error ó��
//			// Error Code : ERR_PROTOCOL_NOT_LOGINED
//			SendErrorMessage(T_FP_EVENT_NOTIFY_WARP, ERR_PROTOCOL_NOT_LOGINED, pMsgRecvWarp->CharacterUniqueNumber, 0, pMsgRecvWarp->AccountName);
//		}
//		break;
//	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE:
//		{
//			// Protocol Error ó��
//			// Error Code : ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE
//			SendErrorMessage(T_FP_EVENT_NOTIFY_WARP, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, pMsgRecvWarp->CharacterUniqueNumber,  0, pMsgRecvWarp->AccountName);
//		}
//	default:
//		{
//			SendErrorMessage(T_FP_EVENT_NOTIFY_WARP, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0);
//		}
//	}

	return RES_BREAK;
}

ProcessResult CPreIOCPSocket::Process_FP_EVENT_ENTER_SELECT_SCREEN(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_EVENT_ENTER_SELECT_SCREEN,
											MSG_FP_EVENT_ENTER_SELECT_SCREEN, msgEnterSelect);

	CP_State cpState;
	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_EVENT_ENTER_SELECT_SCREEN(&cpState, msgEnterSelect);

	switch(nRetedErrorNum)
	{
	case 0:
		{

			return RES_RETURN_TRUE;
		}
		break;
	case ERR_PROTOCOL_NOT_LOGINED:
		{
			SendErrorMessage(T_FP_EVENT_ENTER_SELECT_SCREEN, ERR_PROTOCOL_NOT_LOGINED, 0, 0, msgEnterSelect->AccountName);
		}
		break;
	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE:
		{
			SendErrorMessage(T_FP_EVENT_ENTER_SELECT_SCREEN, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, cpState,  0, msgEnterSelect->AccountName);
		}
		break;
	default:
		{
			SendErrorMessage(T_FP_EVENT_ENTER_SELECT_SCREEN, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0);
		}
	}

	return RES_BREAK;
}

ProcessResult CPreIOCPSocket::Process_FP_EVENT_GAME_STARTED(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_EVENT_GAME_STARTED,
											MSG_FP_EVENT_GAME_STARTED, msgGameStarted);

	CP_State cpState;
	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_EVENT_GAME_STARTED(&cpState, msgGameStarted);
	switch(nRetedErrorNum)
	{
	case 0:
		{

			return RES_RETURN_TRUE;
		}
		break;
	case ERR_PROTOCOL_NOT_LOGINED:
		{
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_PROTOCOL_NOT_LOGINED, 0, 0, msgGameStarted->AccountName);
		}
		break;
	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE:
		{
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, cpState,  0, msgGameStarted->AccountName);
		}
		break;
	default:
		{
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0);
		}
	}

	return RES_BREAK;
}

ProcessResult CPreIOCPSocket::Process_FP_EVENT_MAP_CHANGED(const char* pPacket, int nLength, int &nBytesUsed) 
{ 
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_EVENT_MAP_CHANGED, 
											MSG_FP_EVENT_MAP_CHANGED, msgMapChanged); 
 
	CP_State cpState; 
	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_EVENT_MAP_CHANGED(&cpState, msgMapChanged); 
	switch(nRetedErrorNum) 
	{ 
	case 0: 
		{ 
 
			return RES_RETURN_TRUE; 
		} 
		break; 
	case ERR_PROTOCOL_NOT_LOGINED: 
		{ 
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_PROTOCOL_NOT_LOGINED, 0, 0, msgMapChanged->AccountName); 
		} 
		break; 
	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE: 
		{ 
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, cpState,  0, msgMapChanged->AccountName); 
		} 
		break; 
	default: 
		{ 
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0); 
		} 
	} 
 
	return RES_BREAK; 
} 
 


ProcessResult CPreIOCPSocket::Process_FP_CASH_CHANGE_CHARACTERNAME(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_CASH_CHANGE_CHARACTERNAME,
											MSG_FP_CASH_CHANGE_CHARACTERNAME, pSChangedCharName);

	mt_auto_lock mtA(&ms_pPreIOCP->m_AccountInfoMap);
	CAccountInfo *pAccountInfo = ms_pPreIOCP->GetAccountInfoPtr(pSChangedCharName->szAccName);
	if (pAccountInfo == NULL)
	{		
		return RES_BREAK;
	}

	STRNCPY_MEMSET(pAccountInfo->CurrentCharacterName, pSChangedCharName->szChangedCharName, SIZE_MAX_CHARACTER_NAME);
	return RES_BREAK;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_FP_ADMIN_BLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - CPreIOCPSocket::Process_FP_ADMIN_BLOCKACCOUNT() �߰�
/// \author		cmkwon
/// \date		2008-01-31 ~ 2008-01-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_FP_ADMIN_BLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_ADMIN_BLOCKACCOUNT,
											MSG_FP_ADMIN_BLOCKACCOUNT, pRMsg);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
	g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Account Block: AdminAccountName(%20s), BlockedUserAccName(%20s) Period(%s ~ %s)\r\n"
		, pRMsg->blockAccInfo.szBlockAdminAccountName, pRMsg->blockAccInfo.szBlockedAccountName
		, pRMsg->blockAccInfo.atimeStartTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING))
		, pRMsg->blockAccInfo.atimeEndTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));

	ms_pPreIOCP->BlockAccount(&pRMsg->blockAccInfo, this, TRUE);
	return RES_BREAK;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_FP_ADMIN_UNBLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - CPreIOCPSocket::Process_FP_ADMIN_UNBLOCKACCOUNT() �߰�
/// \author		cmkwon
/// \date		2008-01-31 ~ 2008-01-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_FP_ADMIN_UNBLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_ADMIN_UNBLOCKACCOUNT,
											MSG_FP_ADMIN_UNBLOCKACCOUNT, pRMsg);

	///////////////////////////////////////////////////////////////////////////////
	// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�
	g_pPreGlobal->WriteSystemLogEX(TRUE, "[Notify] Account Unblock: AdminAccountName(%20s), BlockedUserAccName(%20s)\r\n"
		, pRMsg->blockAccInfo.szBlockAdminAccountName, pRMsg->blockAccInfo.szBlockedAccountName);

	pRMsg->blockAccInfo.atimeStartTime.SetCurrentDateTime();
	pRMsg->blockAccInfo.atimeEndTime = pRMsg->blockAccInfo.atimeStartTime;
	if(FALSE == ms_pPreIOCP->UnblockAccount(&pRMsg->blockAccInfo, this))
	{
		// 2008-02-01 by cmkwon, ��� ����Ʈ�� ����.
		INIT_MSG_WITH_BUFFER(MSG_FP_ADMIN_UNBLOCKACCOUNT_OK, T_FP_ADMIN_UNBLOCKACCOUNT_OK, pSMsg, SendBuf);
		pSMsg->ErrCode		= ERR_NOT_ACCOUNT_BLOCKED;
		STRNCPY_MEMSET(pSMsg->UnblockedAccName, pRMsg->blockAccInfo.szBlockedAccountName, SIZE_MAX_ACCOUNT_NAME);
		this->SendAddData(SendBuf, MSG_SIZE(MSG_FP_ADMIN_UNBLOCKACCOUNT_OK));
	}
	return RES_BREAK;
}

ProcessResult CPreIOCPSocket::Process_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE(const char* pPacket, int nLength, int &nBytesUsed)
{
	int		nRecvTypeSize	= 0;

	MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE *pMsgRecvNotifyFieldServer;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		// Protocl Error ó��
		// - Client�� ���� ���� Data Size�� Field Type�� ���� Data Size���� �۴�
		// Error Code : ERR_PROTOCOL_INVALID_FIELD_DATA
		SendErrorMessage(T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pMsgRecvNotifyFieldServer = (MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE*)(pPacket+nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	int nRetedErrorNum = ms_pPreIOCP->On_MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE(pMsgRecvNotifyFieldServer);
	switch(nRetedErrorNum)
	{
	case 0:
		{
			//////////////////////////////
			// Send MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK
			INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK, T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK, pSendMsg, pSendBuf);
			pSendMsg->ClientIndex = pMsgRecvNotifyFieldServer->ClientIndex;

			SendAddData(pSendBuf, MSG_SIZE(MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK));
			return RES_RETURN_TRUE;
		}
		break;
	case ERR_PROTOCOL_NOT_LOGINED:
		{
			SendErrorMessage(T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE, ERR_PROTOCOL_NOT_LOGINED, pMsgRecvNotifyFieldServer->ClientIndex);
		}
		break;
	case ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE:
		{
			SendErrorMessage(T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE, ERR_PROTOCOL_INVALID_PRESERVER_CLIENT_STATE, pMsgRecvNotifyFieldServer->ClientIndex);
		}
		break;
	default:
		{
			SendErrorMessage(T_FP_EVENT_GAME_STARTED, ERR_COMMON_UNKNOWN_ERROR, 0, 0, 0);
		}
	}

	return RES_BREAK;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreIOCPSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - CPreIOCPSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK() �߰�
/// \author		cmkwon
/// \date		2008-04-30 ~ 2008-04-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreIOCPSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE(pPacket, nLength, nBytesUsed, T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK,
		MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK, pRecvMsg);

	CAccountInfo tmPreAccountInfo;	
	BOOL bReted = ms_pPreIOCP->GetAccountInfo(&tmPreAccountInfo, pRecvMsg->AccountName);
	if(FALSE == bReted)
	{// 2008-04-30 by cmkwon, ���� ������ ����.
		return RES_BREAK;
	}

	if(FALSE == tmPreAccountInfo.CurrentFieldServerID.CompareValue(pRecvMsg->PCConnectLoginOK.FieldServerIP, pRecvMsg->PCConnectLoginOK.FieldServerPort))
	{// 2008-04-30 by cmkwon, FieldServer ������ �ٸ���
		return RES_BREAK;
	}

	CPreIOCPSocket *pPISoc = ms_pPreIOCP->GetPreIOCPSocket(tmPreAccountInfo.CurrentPreServerClientIndex);
	if( NULL == pPISoc
		|| FALSE == pPISoc->IsUsing()
		|| 0 != strnicmp(pPISoc->m_szAdminAccountName, pRecvMsg->AccountName, SIZE_MAX_ACCOUNT_NAME) )
	{
		return RES_BREAK;
	}

	if(ERR_NO_ERROR != pRecvMsg->ErrorCode)
	{
		pPISoc->SendErrorMessage(T_PC_CONNECT_LOGIN, pRecvMsg->ErrorCode, 0, 0, pRecvMsg->AccountName);
		return RES_BREAK;
	}

	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_LOGIN_OK, T_PC_CONNECT_LOGIN_OK, pSMsg, SendBuf);
	*pSMsg		= pRecvMsg->PCConnectLoginOK;
	pPISoc->SendAddData(SendBuf, MSG_SIZE(MSG_PC_CONNECT_LOGIN_OK));
	
	///////////////////////////////////////////////////////////////////
	// 2012-10-05 by jhseol, NPlay pc�� ��� - ������ ���� Pre���� ���ӽ� NPlay Client ����Ʈ�� �߰�
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
	if( NULL != g_pPreGlobal && NULL != g_pPreGlobal->m_pNPlayPCBangModule )
	{
		g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_Login(pPISoc->m_szAdminAccountName, pPISoc->GetPeerIP(), pPISoc->GetPeerPort());
	}
#endif
	// end 2012-10-05 by jhseol, NPlay pc�� ��� - ������ ���� Pre���� ���ӽ� NPlay Client ����Ʈ�� �߰�

#ifdef S_GLOG_HSSON
	// 2010-06-01 by shcho, GLogDB ���� -
	QPARAM_GLOG_INSERT_ACCOUNT * pQMsg = new QPARAM_GLOG_INSERT_ACCOUNT;
	STRNCPY_MEMSET(pQMsg->szAccountName, pRecvMsg->AccountName, SIZE_MAX_ACCOUNT_NAME);
	ms_pPreIOCP->m_pAtumDBManager->MakeAndEnqueueQuery(QT_InsertGlogAccount, this, (void*)pQMsg);
#endif

	// start 2011-12-12 by hskim, GLog 2��
#ifdef S_GLOG_2ND_HSKIM
	INIT_MSG_WITH_BUFFER(MSG_FP_GLOG_CONNECT_USER_LOGIN, T_FP_GLOG_CONNECT_USER_LOGIN, pSendGLogMsg, pSendGLogBuf);
	STRNCPY_MEMSET(pSendGLogMsg->AccountName, pRecvMsg->AccountName, SIZE_MAX_ACCOUNT_NAME);
	SendAddData(pSendGLogBuf, MSG_SIZE(MSG_FP_GLOG_CONNECT_USER_LOGIN));
#endif
	// end 2011-12-12 by hskim, GLog 2��

	return RES_RETURN_TRUE;
}

BOOL CPreIOCPSocket::ResPreLogin(MSG_PC_CONNECT_LOGIN *pRecvMsgLogin, CAccountInfo *i_pAccInfo, Err_t nErr)
{
	if(IsUsing() == FALSE)
	{
		return FALSE;
	}

	if(ERR_NO_ERROR != nErr
		|| FALSE == IS_VALID_UNIQUE_NUMBER(i_pAccInfo->AccountUniqueNumber))
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, nErr, 0, 0, pRecvMsgLogin->AccountName);
		return FALSE;
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// ���� �׷��� �������� Ȱ��ȭ �Ǿ��ִ��� üũ
	CServerGroup *serverGroup = ms_pPreIOCP->GetServerGroup(pRecvMsgLogin->FieldServerGroupName);
	if (serverGroup == NULL)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_NO_SUCH_SERVER_GROUP);
		return FALSE;
	}
	
	// IM ���� ���� ���� Ȯ��
	if (!serverGroup->m_IMServerInfo.IsActive)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_IM_SERVER_NOT_ALIVE, serverGroup->m_IMServerInfo.IsActive, 0, pRecvMsgLogin->FieldServerGroupName);
		DBGOUT("Account(%s), PrivateIP(%s)\r\n", pRecvMsgLogin->AccountName, pRecvMsgLogin->PrivateIP);
		return FALSE;
	}
	
	ServerInfo *serverInfo = &serverGroup->m_FieldServerInfo;
	if(FALSE == serverInfo->IsActive)
	{
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_ALL_FIELD_SERVER_NOT_ALIVE);
		return FALSE;
	}
	
	if (FALSE == g_pPreGlobal->CheckAllowedList(serverGroup, pRecvMsgLogin->AccountName, pRecvMsgLogin->PrivateIP, i_pAccInfo->AccountType))
	{
		DBGOUT("  NOT ALLOWED IP or Account: Account(%s) Private(%s) Public(%s)\r\n"
			, pRecvMsgLogin->AccountName, pRecvMsgLogin->PrivateIP, this->GetPeerIP());
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PERMISSION_DENIED);					// 2006-09-27 by cmkwon, error code ����
		return FALSE;
	}

	CAccountInfo tmPreAccountInfo;
	ms_pPreIOCP->m_AccountInfoMap.lock();
	BOOL bReted = ms_pPreIOCP->GetAccountInfo(&tmPreAccountInfo, pRecvMsgLogin->AccountName);
	if(bReted)
	{// ���� ������ ����

		if (strncmp(tmPreAccountInfo.PrivateClientIP, pRecvMsgLogin->PrivateIP, SIZE_MAX_IPADDRESS) != 0
			|| GetClientState(&tmPreAccountInfo) >= CP_FIELD_LOGINED)
		{// ���� �α���, �� ���� ������ �� ���´�. AccountInfoMap���� �����Ѵ�.

			///////////////////////////////////////////////////////////////////////////////
			// Account ���� �����
			ms_pPreIOCP->DeleteAccountInfo(pRecvMsgLogin->AccountName);
			ms_pPreIOCP->m_AccountInfoMap.unlock();

			///////////////////////////////////////////////////////////////////////////////
			// ������ user ���� ����: �ʵ� ������ ���� �޼����� ������
			ms_pPreIOCP->SendErrorToFieldServer(tmPreAccountInfo.CurrentServerGroup, tmPreAccountInfo.CurrentFieldServerID
				, T_PC_CONNECT_LOGIN, ERR_PROTOCOL_DUPLICATE_LOGIN
				, tmPreAccountInfo.CurrentClientIndex, 0, pRecvMsgLogin->AccountName);

			///////////////////////////////////////////////////////////////////////////////
			// ���ο�(��� ������ �õ��ϴ�) user ���� ����
			SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_DUPLICATE_LOGIN, 0, 0, pRecvMsgLogin->AccountName);
			Sleep(100);
			Close(0x11015, TRUE);			
			return FALSE;
		}
		else
		{
			// Laucher��  �α����� �ٽ� Launcher�� �α��� �õ��� �ѻ���
			// Launcher ������ Ŭ���̾�Ʈ�� �������� �����ʰ� ����� ������
			ms_pPreIOCP->DeleteAccountInfo(tmPreAccountInfo.AccountName);
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// �߰��� ���� ������ �����Ѵ�.
	CAccountInfo *pCurrentAccountInfo					= new CAccountInfo;
	*pCurrentAccountInfo								= *i_pAccInfo;				// 2006-06-02 by cmkwon
	STRNCPY_MEMSET(pCurrentAccountInfo->AccountName, pRecvMsgLogin->AccountName, SIZE_MAX_ACCOUNT_NAME);
	STRNCPY_MEMSET(pCurrentAccountInfo->PrivateClientIP, pRecvMsgLogin->PrivateIP, SIZE_MAX_IPADDRESS);
	STRNCPY_MEMSET(pCurrentAccountInfo->PublicClientIP, GetPeerIP(), SIZE_MAX_IPADDRESS);
	STRNCPY_MEMSET(pCurrentAccountInfo->CurrentCharacterName, "", SIZE_MAX_CHARACTER_NAME);	// check: Ȯ��!
	pCurrentAccountInfo->CurrentCharacterUniqueNumber	= 0;							// check: Ȯ��!
	STRNCPY_MEMSET(pCurrentAccountInfo->CurrentServerGroup, pRecvMsgLogin->FieldServerGroupName, SIZE_MAX_SERVER_NAME);	
	pCurrentAccountInfo->CurrentFieldServerID			= serverInfo->serverID;
	SetClientState(CP_LOGINED, pCurrentAccountInfo);
	pCurrentAccountInfo->LauncherLoginTime.SetCurrentDateTime();
	pCurrentAccountInfo->CurrentPreServerClientIndex	= this->GetClientArrayIndex();		// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
#ifdef S_ARARIO_HSSON
	if(CONNECT_PUBLISHER_NHN_JPN == m_eOtherPublisherConncect)
	{
		pCurrentAccountInfo->eOtherPublisherConncect = CONNECT_PUBLISHER_NHN_JPN;
	}
#endif	// S_ARARIO_HSSON

	// 2012-07-11 by hskim, ������ �˴ٿ�
	if( NULL != g_pPreGlobal->m_pSelectiveShutdown )
	{
		int iCount = 0;
		for(int i=0; i<SIZE_MAX_SHUTDOWN_SERVICE_BLOCK; i++)
		{
			if( '1' == pRecvMsgLogin->SelectiveShutdownInfo[i] )	
			{
				iCount++;
			}
		}

		if( SIZE_MAX_SHUTDOWN_SERVICE_BLOCK != iCount )
		{
			pCurrentAccountInfo->bSelectiveShutdownTarget = TRUE;		// �� ������ �˴ٿ��� ������̴�.
		}
	}
	else
	{
		pCurrentAccountInfo->bSelectiveShutdownTarget = FALSE;
	}
	
	memcpy(pCurrentAccountInfo->SelectiveShutdownInfo, pRecvMsgLogin->SelectiveShutdownInfo, sizeof(pRecvMsgLogin->SelectiveShutdownInfo));
	// end 2012-07-11 by hskim, ������ �˴ٿ�

	/////////////////////////////////////////////////////
	// �޽����� �̸� �����, MSG_PC_CONNECT_LOGIN_OK to client
	INIT_MSG_WITH_BUFFER(MSG_PC_CONNECT_LOGIN_OK, T_PC_CONNECT_LOGIN_OK, pSendMsg, pSendBuf);
	STRNCPY_MEMSET(pSendMsg->AccountName, pRecvMsgLogin->AccountName, SIZE_MAX_ACCOUNT_NAME);	// 2008-10-08 by cmkwon, �븸 2�ܰ� ���� �ý��� ���� ����(email->uid) - 2�ܰ� ������ �����Ѵ�.
	STRNCPY_MEMSET(pSendMsg->FieldServerIP, pCurrentAccountInfo->CurrentFieldServerID.IP, SIZE_MAX_IPADDRESS);
	pSendMsg->FieldServerPort = (USHORT)pCurrentAccountInfo->CurrentFieldServerID.port;
	STRNCPY_MEMSET(pSendMsg->IMServerIP, serverGroup->m_IMServerInfo.serverID.IP, SIZE_MAX_IPADDRESS);
	pSendMsg->IMServerPort = (USHORT)serverGroup->m_IMServerInfo.serverID.port;
	pSendMsg->ConnectToTestServer = g_pPreGlobal->IsTestServer();	// 2014-01-06 by jhseol, �׼� ���� ����(TRUE=�׼�, FALSE=����)

	// start 2011-12-21 by hskim, EP4 [������ 1ȸ ���]
#ifdef S_EP4_HSKIM		// ON/OFF ��� ����
	if( TRUE == ms_pPreIOCP->m_OpeningMovieStandard.IsValidATUM_DATE_TIME() && TRUE == pCurrentAccountInfo->LastGameEndDate.IsValidATUM_DATE_TIME() )
	{
		if( pCurrentAccountInfo->LastGameEndDate != pCurrentAccountInfo->AccountRegisteredDate )
		{
			pSendMsg->OpeningMoviePlay = ((pCurrentAccountInfo->LastGameEndDate < ms_pPreIOCP->m_OpeningMovieStandard)? TRUE : FALSE);
		}
		else
		{
			pSendMsg->OpeningMoviePlay = TRUE;
		}
	}
	else
	{
		pSendMsg->OpeningMoviePlay = TRUE;
	}

	if( TRUE == pSendMsg->OpeningMoviePlay )
	{
		QPARAM_UPDATE_ACCOUNT_LASTGAMEENDDATE *pQMsg = new QPARAM_UPDATE_ACCOUNT_LASTGAMEENDDATE;
		pQMsg->AccountUniqueNumber = i_pAccInfo->AccountUniqueNumber;
		ms_pPreIOCP->m_pAtumDBManager->MakeAndEnqueueQuery(QT_UpdateAccountLastGameEndDate, this, (void*)pQMsg);
	}
#else
	pSendMsg->OpeningMoviePlay = FALSE;
#endif
	// end 2011-12-21 by hskim, EP4 [������ 1ȸ ���]

	/////////////////////////////////////////////////////
	// ������ ���� �α��� �� account���� list�� �߰�
	BOOL bInserted = ms_pPreIOCP->InsertAccountInfo(pCurrentAccountInfo->AccountName, pCurrentAccountInfo);
	if (FALSE == bInserted)
	{// ���� �α���, �� ���� ������ �� ���´�. AccountInfoMap���� �����Ѵ�.
		
		g_pPreGlobal->WriteSystemLogEX(TRUE, STRMSG_S_P2PRENOTIFY_0003, pRecvMsgLogin->AccountName, pRecvMsgLogin->PrivateIP);

		///////////////////////////////////////////////////////////////////////////////
		// ���ο�(��� ������ �õ��ϴ�) user ���� ����
		SendErrorMessage(T_PC_CONNECT_LOGIN, ERR_PROTOCOL_DUPLICATE_LOGIN, 0, 0, pCurrentAccountInfo->AccountName);
		Close(0x11016, TRUE);
		
		///////////////////////////////////////////////////////////////////////////////
		// ������ user ���� ����: �ʵ� ������ ���� �޼����� ������
		if(ms_pPreIOCP->GetAccountInfo(&tmPreAccountInfo, pCurrentAccountInfo->AccountName))
		{
			ms_pPreIOCP->SendErrorToFieldServer(tmPreAccountInfo.CurrentServerGroup, tmPreAccountInfo.CurrentFieldServerID
				, T_PC_CONNECT_LOGIN, ERR_PROTOCOL_DUPLICATE_LOGIN, tmPreAccountInfo.CurrentClientIndex, 0, tmPreAccountInfo.AccountName);
		}
		
		///////////////////////////////////////////////////////////////////////////////
		// Account ���� �����
		ms_pPreIOCP->DeleteAccountInfo(pRecvMsgLogin->AccountName);
		ms_pPreIOCP->m_AccountInfoMap.unlock();

		SAFE_DELETE(pCurrentAccountInfo);
		return FALSE;
	}
	ms_pPreIOCP->m_AccountInfoMap.unlock();

	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	if( COMPARE_BIT_FLAG(i_pAccInfo->AccountType, RACE_OPERATION|RACE_GAMEMASTER)	// 2008-05-19 by cmkwon, ������/��ڴ� ������ ���� ���ɿ��� üũ ���� �ʰ� ������ �ٷ� ����
		|| FALSE == serverGroup->m_bLockCreateCharacterForNewAccount )
	{
		SendAddData(pSendBuf, MSG_SIZE(MSG_PC_CONNECT_LOGIN_OK));

		///////////////////////////////////////////////////////////////////
		// 2012-10-05 by jhseol, NPlay pc�� ��� - ������ ���� Pre���� ���ӽ� NPlay Client ����Ʈ�� �߰�
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
		if( NULL != g_pPreGlobal && NULL != g_pPreGlobal->m_pNPlayPCBangModule )
		{
			g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_Login(pRecvMsgLogin->AccountName, this->GetPeerIP(), this->GetPeerPort());
		}
#endif
		// end 2012-10-05 by jhseol, NPlay pc�� ��� - ������ ���� Pre���� ���ӽ� NPlay Client ����Ʈ�� �߰�
		
		// 2010-06-01 by shcho, GLogDB ���� -
		QPARAM_GLOG_INSERT_ACCOUNT * pQMsg = new QPARAM_GLOG_INSERT_ACCOUNT;
		STRNCPY_MEMSET(pQMsg->szAccountName, pCurrentAccountInfo->AccountName, SIZE_MAX_ACCOUNT_NAME)

#ifdef S_GLOG_HSSON
			ms_pPreIOCP->m_pAtumDBManager->MakeAndEnqueueQuery(QT_InsertGlogAccount, this, (void*)pQMsg);
#endif

		// start 2011-12-12 by hskim, GLog 2��
#ifdef S_GLOG_2ND_HSKIM
		INIT_MSG_WITH_BUFFER(MSG_FP_GLOG_CONNECT_USER_LOGIN, T_FP_GLOG_CONNECT_USER_LOGIN, pSendGLogMsg, pSendGLogBuf);
		STRNCPY_MEMSET(pSendGLogMsg->AccountName, pCurrentAccountInfo->AccountName, SIZE_MAX_ACCOUNT_NAME);
		serverGroup->SendMessageToFieldServer(pSendGLogBuf, MSG_SIZE(MSG_FP_GLOG_CONNECT_USER_LOGIN));
#endif
		// end 2011-12-12 by hskim, GLog 2��
	}
	else
	{
		INIT_MSG_WITH_BUFFER(MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT, T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT, pSMsgToField, SendBuf2);
		STRNCPY_MEMSET(pSMsgToField->AccountName, pRecvMsgLogin->AccountName, SIZE_MAX_ACCOUNT_NAME);
		pSMsgToField->PCConnectLoginOK		= *pSendMsg;
		serverGroup->SendMessageToFieldServer(SendBuf2, MSG_SIZE(MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT));
	}
	return TRUE;
}

// start 2011-06-22 by hskim, �缳 ���� ����
ProcessResult CPreIOCPSocket::Process_IP_AUTHENTICATION_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_IP_AUTHENTICATION_SHUTDOWN,
		MSG_IP_AUTHENTICATION_SHUTDOWN, pRMsg);

	g_pPreGlobal->WriteSystemLogEX(TRUE, STRMSG_AUTHENTICATION_PRESERVER_SHUTDOWN_LOG, 1024);		// �α� ���

	if( FALSE == g_pPreGlobal->m_pSecurityManager->GetAuthentication() && pRMsg->bFlag == TRUE )
	{
		g_pPreGlobal->m_pSecurityManager->KillExec_Exit();
	}

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_AUTHENTICATION_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_AUTHENTICATION_SHUTDOWN,
		MSG_FP_AUTHENTICATION_SHUTDOWN, pRMsg);

	g_pPreGlobal->WriteSystemLogEX(TRUE, STRMSG_AUTHENTICATION_PRESERVER_SHUTDOWN_LOG, 8629);		// �α� ���

	if( FALSE == g_pPreGlobal->m_pSecurityManager->GetAuthentication() && pRMsg->bFlag == TRUE )
	{
		g_pPreGlobal->m_pSecurityManager->SetTimer_InfinityMemoryLeak(SM_DELAY_TIME_SEC_INTERVAL);
	}

	return RES_RETURN_TRUE;
}
// end 2011-06-22 by hskim, �缳 ���� ����



////////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
ProcessResult CPreIOCPSocket::Process_FP_PCBANG_USER_GAME_START(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_GAME_START,
		MSG_FP_PCBANG_USER_GAME_START, pRMsg);
	if( NULL == g_pPreGlobal || NULL == g_pPreGlobal->m_pNPlayPCBangModule )
	{
		return RES_BREAK;
	}

	g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_GameStart(pRMsg->AccountName, pRMsg->ServerGroupName);
	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_PCBANG_USER_GAME_END(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_GAME_END,
		MSG_FP_PCBANG_USER_GAME_END, pRMsg);

	if( NULL == g_pPreGlobal || NULL == g_pPreGlobal->m_pNPlayPCBangModule )
	{
		return RES_BREAK;
	}

	g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_GameEnd(pRMsg->AccountName);
	g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_Pop(pRMsg->AccountName);

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_PCBANG_USER_PREMIUN_END(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_PREMIUN_END,
		MSG_FP_PCBANG_USER_PREMIUN_END, pRMsg);

	if( NULL == g_pPreGlobal || NULL == g_pPreGlobal->m_pNPlayPCBangModule )
	{
		return RES_BREAK;
	}

	g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_GameEnd(pRMsg->AccountName);

	return RES_RETURN_TRUE;
}

ProcessResult CPreIOCPSocket::Process_FP_PCBANG_USER_PREMIUM_REQUEST(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_PREMIUM_REQUEST,
		MSG_FP_PCBANG_USER_PREMIUM_REQUEST, pRMsg);
	if( NULL == g_pPreGlobal || NULL == g_pPreGlobal->m_pNPlayPCBangModule )
	{
		return RES_BREAK;
	}

	g_pPreGlobal->m_pNPlayPCBangModule->VectNPlayConnectClientList_SendPremiuminfo(pRMsg->AccountName, pRMsg->ServerGroupName);

	return RES_RETURN_TRUE;
}
// end 2012-10-05 by jhseol, NPlay pc�� ���



// error �޼����� ����
void CPreIOCPSocket::SendErrorMessage(MessageType_t msgType, Err_t err, int errParam1, int errParam2, char* errMsg, BOOL bCloseConnection)
{
	MSG_ERROR	*pMsgError;
	BYTE		SendBuf[SIZE_MAX_PACKET];

	char szSystemLog[SIZE_MAX_ERROR_STRING]; // 2013-09-23 by jekim, ���� ����� �޼��� �ѷ��ֱ�. size 256 -> 1024 �� �ø�
	sprintf(szSystemLog, "  SendErrorMsg to ClientIndex[%3d] %15s(%4d) ==> %s(%#04x) AT %s Param1(%d) Param2(%d) Msg(%s)\r\n",
		this->GetClientArrayIndex(), m_szPeerIP, m_nPeerPort,
		GetErrorString(err), err, GetProtocolTypeString(msgType), errParam1, errParam2, errMsg);
	g_pGlobal->WriteSystemLog(szSystemLog);
#ifdef _DEBUG
//	if (err != ERR_PROTOCOL_INVALID_MAP_EVENT_INFO)
	{
		DBGOUT(szSystemLog);
	}
#endif

	*(MessageType_t*)SendBuf = T_ERROR;
	pMsgError = (MSG_ERROR*)(SendBuf+SIZE_FIELD_TYPE_HEADER);
	pMsgError->CloseConnection = bCloseConnection;
	pMsgError->ErrorCode = err;
	pMsgError->MsgType = msgType;
	pMsgError->ErrParam1 = errParam1;
	pMsgError->ErrParam2 = errParam2;
	if (errMsg == NULL || 0 == strncmp(errMsg, "", SIZE_MAX_ERROR_STRING))
	{
		pMsgError->StringLength = 0;
	}
	else
	{
		pMsgError->StringLength = (USHORT)(strlen(errMsg) + 1);
		STRNCPY_MEMSET((char*)SendBuf + MSG_SIZE(MSG_ERROR), errMsg, SIZE_MAX_ERROR_STRING);
	}
	SendAddData(SendBuf, MSG_SIZE(MSG_ERROR) + pMsgError->StringLength);
}

void CPreIOCPSocket::SetClientState(CP_State i_nCPState, CAccountInfo *i_pAccountInfo)
{
	if (i_pAccountInfo != NULL)
	{
		i_pAccountInfo->ClientState = i_nCPState;
	}
	else
	{
		m_CPClientState = i_nCPState;
	}
}

CP_State CPreIOCPSocket::GetClientState(CAccountInfo *i_pAccountInfo)
{
	if (i_pAccountInfo != NULL)
	{
		return i_pAccountInfo->ClientState;
	}
	else
	{
		return m_CPClientState;
	}
}
