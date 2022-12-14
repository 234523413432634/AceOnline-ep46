// PreWinSocket.cpp: implementation of the CPreWinSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreWinSocket.h"
#include "FieldIOCP.h"
#include "FieldGlobal.h"
#include "AtumLogSender.h"
#include "AtumError.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPreWinSocket::CPreWinSocket(HWND hWnd, UINT wmSock, UINT wmNotify)
:CWinSocket(hWnd, wmSock, wmNotify, FALSE)
{
	m_PeerSocketType = ST_PRE_SERVER;
}

CPreWinSocket::~CPreWinSocket()
{

}

void CPreWinSocket::SetFieldIOCP(CFieldIOCP *pFieldIOCP)
{
	m_pFieldIOCP2 = pFieldIOCP;
}


BOOL CPreWinSocket::OnCloseSocket(int nErrorCode)
{
	return CWinSocket::OnCloseSocket(nErrorCode);
}

BOOL CPreWinSocket::OnConnect(int nErrorCode)
{
	CWinSocket::OnConnect(nErrorCode);
	//////////////////////////////////////////////////////////////////////
	// TODO: Add your specialized code here

	//
	//////////////////////////////////////////////////////////////////////
	return	TRUE;
}


BOOL CPreWinSocket::OnRecvdPacket(LPSTR pPacket, int nLength, BYTE nSeq)
{
	int				nBytesUsed	= 0;
	MessageType_t	nType		= 0;
	MessageType_t	prevMsgType = 0;
	int				nMsgSize	= 0;
	ProcessResult	procRes		= RES_BREAK;

	while(nBytesUsed < nLength)
	{
		nType = *(MessageType_t*)(pPacket+nBytesUsed);
		nBytesUsed += SIZE_FIELD_TYPE_HEADER;

#ifdef _DEBUG
		PrintExchangeMsg(RECV_TYPE, nType, m_szPeerIP, ST_PRE_SERVER, GGetexchangeMsgPrintLevel());
#endif

		switch(nType)
		{
		case T_FP_CONNECT_FIELD_CONNECT_OK:	// no body
			{
				MSG_FP_CONNECT_FIELD_CONNECT_OK *pRMsg = (MSG_FP_CONNECT_FIELD_CONNECT_OK*)(pPacket+nBytesUsed);
				nBytesUsed += sizeof(MSG_FP_CONNECT_FIELD_CONNECT_OK);
				g_pFieldGlobal->SetMGameEventType(pRMsg->CurrentMGameEventType);

				DBGOUT("FieldServer successfully registered to PreServer...\n");
				procRes = RES_RETURN_TRUE;
			}
			break;
// 2005-07-27 by cmkwon, 다른 필드서버로의 워프는 없으므로 삭제함
//		case T_FP_EVENT_NOTIFY_WARP_OK:
//			procRes = Process_FP_EVENT_NOTIFY_WARP_OK(pPacket, nLength, nBytesUsed);
//			break;
		case T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK:
			procRes = Process_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_AUTH_USER_OK:
			procRes = Process_FP_CONNECT_AUTH_USER_OK(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_MONITOR_SET_MGAME_EVENT_TYPE:			
			procRes = Process_FP_MONITOR_SET_MGAME_EVENT_TYPE(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_MONITOR_RELOAD_VERSION_INFO_OK:			// 2008-09-08 by cmkwon, SCMonitor에서 ReloadVersionInfo시에 일부 체크섬파일(.\Res-Tex\*.*)도 리로드하기 - 
			procRes = Process_FP_MONITOR_RELOAD_VERSION_INFO_OK(pPacket, nLength, nBytesUsed);
			break;

		case T_FP_CONNECT_PREPARE_SHUTDOWN:
			procRes = Process_FP_CONNECT_PREPARE_SHUTDOWN(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_UPDATE_DBSERVER_GROUP:	// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
			procRes = Process_FP_CONNECT_UPDATE_DBSERVER_GROUP(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT:	// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
			procRes = Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_RELOAD_WORLDRANKING:	// 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
			procRes = Process_FP_ADMIN_RELOAD_WORLDRANKING(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_RELOAD_INFLUENCERATE:	// 2009-09-16 by cmkwon, 세력 초기화시 어뷰징 방지 구현 - 
			procRes = Process_FP_ADMIN_RELOAD_INFLUENCERATE(pPacket, nLength, nBytesUsed);
			break;

		case T_FP_EVENT_RELOAD_HAPPYEV:
			procRes = Process_FP_EVENT_RELOAD_HAPPYEV(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_EVENT_RELOAD_ITEMEV:
			procRes = Process_FP_EVENT_RELOAD_ITEMEV(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_EVENT_UPDATE_PCBANGLIST:
			procRes = Process_FP_EVENT_UPDATE_PCBANGLIST(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_EVENT_UPDATE_STRATEGYPOINT_NOTSUMMONTIM:
			procRes = Process_FP_EVENT_UPDATE_STRATEGYPOINT_NOTSUMMONTIM(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_BLOCKACCOUNT_OK:		// 2008-01-31 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - 
			procRes = Process_FP_ADMIN_BLOCKACCOUNT_OK(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_ADMIN_UNBLOCKACCOUNT_OK:		// 2008-01-31 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - 
			procRes = Process_FP_ADMIN_UNBLOCKACCOUNT_OK(pPacket, nLength, nBytesUsed);
			break;
			////////////////////////////////////////////////////////////////////////////
			// 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전
		case T_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE:
			procRes = Process_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE(pPacket, nLength, nBytesUsed);
			break;
			// end 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전

			// start 2012-01-08 by hskim, GLog 2차
		case T_FP_GLOG_CONNECT_USER_NEW:
			procRes = Process_FP_GLOG_CONNECT_USER_NEW(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_GLOG_CONNECT_USER_LOGIN:
			procRes = Process_FP_GLOG_CONNECT_USER_LOGIN(pPacket, nLength, nBytesUsed);
			break;
			// end 2012-01-08 by hskim, GLog 2차

		// 2013-03-14 by bckim, Glog 기능추가
		case T_FP_GLOG_NEW_ACCOUNT_INFO:
			procRes = Process_FP_GLOG_NEW_ACCOUNT_INFO(pPacket, nLength, nBytesUsed);
			break;
		// End. 2013-03-14 by bckim, Glog 기능추가

			///////////////////////////////////////////////////////////////////////////////
			// 2012-10-05 by jhseol, NPlay pc방 모듈 - 프리서버에서 PC방 프리미엄 정보를 알려 줌
		case T_FP_PCBANG_USER_PREMIUM_INFO:
			procRes = Process_FP_PCBANG_USER_PREMIUM_INFO(pPacket, nLength, nBytesUsed);
			break;
		case T_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME:
			procRes = Process_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME(pPacket, nLength, nBytesUsed);
			break;
			// end 2012-10-05 by jhseol, NPlay pc방 모듈 - 프리서버에서 PC방 프리미엄 정보를 알려 줌


		case T_ERROR:
			procRes = Process_ERROR(pPacket, nLength, nBytesUsed);
			break;
		default:
			{
				// check: unknown message type --> error!
				DBGOUT("[Error]Unknown Message Type from Pre Server: %s(%#04X), prev. msg: %s(%#04X)\n", GetProtocolTypeString(nType), nType, GetProtocolTypeString(prevMsgType), prevMsgType);
				return TRUE;
			}
		} // end - switch

		// 에러 관리용 이전 메세지 저장
		prevMsgType = nType;

		// MSG 결과 처리
		if (procRes == RES_BREAK)
		{
			// 경미한 에러들. 연결을 끊지 않는다.
			// do nothing, 그냥 남아있는 다음 packet을 처리한다
		}
		else if (procRes == RES_PACKET_ERROR)
		{
			// 패킷이 손상된 경우. 남은 packet을 처리하지 않고 바로 리턴한다. 서버간 연결에만 사용.
			return TRUE;
		}
		else if (procRes == RES_RETURN_TRUE)
		{
			// 정상
			// do nothing, 그냥 남아있는 다음 packet을 처리한다
		}
		else if (procRes == RES_RETURN_FALSE)
		{
			return FALSE;
		}

	}	// end while

	return TRUE;
}

ProcessResult CPreWinSocket::Process_FP_EVENT_NOTIFY_WARP_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
// 2005-07-27 by cmkwon, 다른 필드서버로의 워프는 없으므로 삭제함
//	int							nRecvTypeSize;
//	MSG_FP_EVENT_NOTIFY_WARP_OK	*pRecvMsgNotifyWarpOK;
//
//	nRecvTypeSize = sizeof(MSG_FP_EVENT_NOTIFY_WARP_OK);
//	if(nLength - nBytesUsed < nRecvTypeSize)
//	{
//		SendErrorMessage(T_FP_EVENT_NOTIFY_WARP_OK, ERR_PROTOCOL_INVALID_FIELD_DATA);
//		return RES_PACKET_ERROR;
//	}
//	pRecvMsgNotifyWarpOK = (MSG_FP_EVENT_NOTIFY_WARP_OK*)(pPacket + nBytesUsed);
//	nBytesUsed += nRecvTypeSize;
//
//	CFieldIOCPSocket *pFieldIOCPSocket
//		= m_pFieldIOCP2->m_mapCharacterUniqueNumber.findLock(pRecvMsgNotifyWarpOK->CharacterUniqueNumber);
//	if (pFieldIOCPSocket == NULL || !pFieldIOCPSocket->IsUsing())
//	{
//		DBGOUT("[PreServer]No Such CharacterUniqueNumber: [%d]\n", pRecvMsgNotifyWarpOK->CharacterUniqueNumber);
//		return RES_BREAK;
//	}
//
//	// m_pCurrentEventInfo가 NULL인지 확인
//	if (pFieldIOCPSocket->m_pCurrentEventInfo == NULL)
//	{
//		pFieldIOCPSocket->DBGOUT2(DO2_ALL, "FATAL ERROR @ CPreWinSocket::Process_FP_EVENT_NOTIFY_WARP_OK -> pFieldIOCPSocket->m_pCurrentEventInfo == NULL");
//		pFieldIOCPSocket->Close(70001);
//		return RES_BREAK;
//	}
//	CFieldMapProject *pFieldMapProject
//		= (CFieldMapProject*)m_pFieldIOCP2->GetMapWorkspace()->GetMapProjectByMapIndex(pFieldIOCPSocket->m_pCurrentEventInfo->m_EventwParam3);
//	if (pFieldMapProject == NULL)
//	{
//		DBGOUT("[PreServer]No Such MapProject: [%d]\n", pFieldIOCPSocket->m_pCurrentEventInfo->m_EventwParam3);
//		return RES_BREAK;
//	}
//
//	// Warp 지점 결정, 새 맵에서의 vector들 설정(DB에 저장한다)
//	AVECTOR3 pTmpWarpTargetVector;
//	if (EVENT_RESULT_CLOSE_CONNECTION == pFieldIOCPSocket->SetWarpTargetPosition(pFieldMapProject, pFieldIOCPSocket->m_pCurrentEventInfo, &pTmpWarpTargetVector))
//	{
//		return RES_BREAK;
//	}
//	pFieldIOCPSocket->m_character.PositionVector = A2DX(pTmpWarpTargetVector);
//
//	QPARAM_CHARACTER_CHANGE_POSITION *m = new QPARAM_CHARACTER_CHANGE_POSITION;
//	m->CharacterUniqueNumber = pFieldIOCPSocket->m_character.CharacterUniqueNumber;
//	m->PositionVector = pFieldIOCPSocket->m_character.PositionVector;
//	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_ChangePosition, pFieldIOCPSocket, pFieldIOCPSocket->m_character.AccountUniqueNumber, m);
//
//	// m_pCurrentEventInfo가 NULL인지 확인
//	if (pFieldIOCPSocket->m_pCurrentEventInfo == NULL)
//	{
//		pFieldIOCPSocket->DBGOUT2(DO2_ALL, "FATAL ERROR @ CPreWinSocket::Process_FP_EVENT_NOTIFY_WARP_OK -> pFieldIOCPSocket->m_pCurrentEventInfo == NULL");
//		pFieldIOCPSocket->Close(70002);
//		return RES_BREAK;
//	}
//
//	// map name 설정(DB에 저장한다)
//	pFieldIOCPSocket->m_character.MapChannelIndex.MapIndex = pFieldIOCPSocket->m_pCurrentEventInfo->m_EventwParam3;
//	pFieldIOCPSocket->m_character.MapChannelIndex.ChannelIndex = 0;	// check: MapChannel 도입중, 20040322, kelovon
//	QPARAM_CHARACTER_CHANGE_MAPCHANNEL *m2 = new QPARAM_CHARACTER_CHANGE_MAPCHANNEL;
//	m2->CharacterUniqueNumber = pFieldIOCPSocket->m_character.CharacterUniqueNumber;
//	m2->MapChannelIndex = pFieldIOCPSocket->m_character.MapChannelIndex;
//	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_ChangeMapChannel, pFieldIOCPSocket, pFieldIOCPSocket->m_character.AccountUniqueNumber, m2);
//
//	// T_FC_EVENT_WARP 메세지를 보낸다.
//	char SendBuf[SIZE_MAX_PACKET];
//	// set header
//	*(MessageType_t*)SendBuf = T_FC_EVENT_WARP;
//	// set body
//	MSG_FC_EVENT_WARP *pSendEventWarp = (MSG_FC_EVENT_WARP*)(SendBuf+SIZE_FIELD_TYPE_HEADER);
//	pSendEventWarp->FieldServerID.SetValue(pFieldMapProject->m_strFieldIP, pFieldMapProject->m_sFieldListenPort);
//	pSendEventWarp->MapChannelIndex.MapIndex = pFieldMapProject->m_nMapIndex;
//	pSendEventWarp->MapChannelIndex.ChannelIndex = 0;	// check: MapChannel 도입중, 20040322, kelovon
//	pSendEventWarp->WarpAreaIndex = pFieldIOCPSocket->m_pCurrentEventInfo->m_EventwParam2;
//
//	pFieldIOCPSocket->SendAddData((BYTE*)SendBuf, MSG_SIZE(MSG_FC_EVENT_WARP));
//
//	pFieldIOCPSocket->m_bNotifyCloseFlag = FALSE;
//
//	// ADMIN COMMAND에 따른 워프시에는 pFieldIOCPSocket->m_pCurrentEventInfo를 삭제해야 함! '/이동' 참조
//	if (pFieldIOCPSocket->m_pCurrentEventInfo->m_EventwParam1 == ~0)
//	{
//		SAFE_DELETE(pFieldIOCPSocket->m_pCurrentEventInfo);
//	}

	return RES_RETURN_TRUE;
}

ProcessResult CPreWinSocket::Process_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	int											nRecvTypeSize;
	MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK	*pRecvFieldChangeOK;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pRecvFieldChangeOK = (MSG_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE_OK*)(pPacket + nBytesUsed);
	nBytesUsed += nRecvTypeSize;

// 2007-04-09 by cmkwon, 멀티필드서버에 관련된 부분으로 사용하지 않는 기능임
//	CFieldIOCPSocket *pFieldIOCPSocket
//		= (CFieldIOCPSocket*)(m_pFieldIOCP2->GetIOCPSocket(pRecvFieldChangeOK->ClientIndex));
//
//	// T_FC_CHARACTER_GAMESTART_OK 메세지를 보낸다.
//	char SendBuf[SIZE_MAX_PACKET];
//	// set header
//	*(MessageType_t*)SendBuf = T_FC_CHARACTER_GAMESTART_OK;
//	// set body
//	MSG_FC_CHARACTER_GAMESTART_OK *pSendCharacterGameStartOK = (MSG_FC_CHARACTER_GAMESTART_OK*)(SendBuf+SIZE_FIELD_TYPE_HEADER);
//	pSendCharacterGameStartOK->ClientIndex = pRecvFieldChangeOK->ClientIndex;
//	CFieldMapProject *pFieldMapProject
//		= (CFieldMapProject*)(m_pFieldIOCP2->GetMapWorkspace()->GetMapProjectByMapIndex(pFieldIOCPSocket->m_character.MapChannelIndex.MapIndex));
//	if (pFieldMapProject == NULL)
//	{
//		DBGOUT("[PreServer]No Such MapProject: [%04d]\n", pFieldIOCPSocket->m_character.MapChannelIndex.MapIndex);
//		return RES_BREAK;
//	}
//	STRNCPY_MEMSET(pSendCharacterGameStartOK->FieldServerIP, pFieldMapProject->m_strFieldIP, SIZE_MAX_IPADDRESS);	// set field server IP
//	pSendCharacterGameStartOK->FieldServerPort = pFieldMapProject->m_sFieldListenPort;
//	pSendCharacterGameStartOK->bMemberPCBang	= pFieldIOCPSocket->m_bIsPCBangClient;		// 2007-01-25 by cmkwon
//	pFieldIOCPSocket->SendAddData((BYTE*)SendBuf, MSG_SIZE(MSG_FC_CHARACTER_GAMESTART_OK));
//
//	pFieldIOCPSocket->m_bNotifyCloseFlag = FALSE;

	return RES_RETURN_TRUE;
}

ProcessResult CPreWinSocket::Process_FP_CONNECT_AUTH_USER_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	int							nRecvTypeSize	= 0;
	MSG_FP_CONNECT_AUTH_USER_OK	*pAuthUserOK	= NULL;

	nRecvTypeSize = sizeof(MSG_FP_CONNECT_AUTH_USER_OK);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_FP_CONNECT_AUTH_USER_OK, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pAuthUserOK = (MSG_FP_CONNECT_AUTH_USER_OK*)(pPacket + nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	BYTE authType = pAuthUserOK->AuthType;
	if ( authType == PRESERVER_AUTH_TYPE_LOGIN )
	{
		CFieldIOCPSocket * pSoc = (CFieldIOCPSocket*)m_pFieldIOCP2->GetIOCPSocket(pAuthUserOK->ClientIndex);
		if (pSoc == NULL || !pSoc->IsUsing())
		{
			// check: fatal error
			DBGOUT("@Process_FP_CONNECT_AUTH_USER_OK(): pSoc is NULL, %d\r\n", pAuthUserOK->ClientIndex);
			return RES_BREAK;
		}
		
		// 2007-11-06 by cmkwon, 체크 추가 함
		if(0 != strnicmp(pSoc->m_character.AccountName, pAuthUserOK->AccountName, SIZE_MAX_ACCOUNT_NAME))
		{
			g_pGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreWinSocket::Process_FP_CONNECT_AUTH_USER_OK(), CIdx(%d) FISocketAccountName(%20s) AuthUserAccountName(%s)\r\n"
				, pAuthUserOK->ClientIndex, pSoc->m_character.AccountName, pAuthUserOK->AccountName);
			return RES_BREAK;
		}
		
		pSoc->m_character.AccountUniqueNumber	= pAuthUserOK->AccountUniqueNumber;	// 2007-11-06 by cmkwon, 설정한다.
		pSoc->SetPreServerAuthenticated(TRUE, TRUE);								// 2007-11-06 by cmkwon, 게임 로그 DB 서버 따로 구축하기 - 게임서버 로그인/로그아웃 처리

#ifdef S_ARARIO_HSSON
		// 2010-11 by dhjin, 아라리오 채널링 로그인.
		pSoc->m_eOtherPublisherConncect	= pAuthUserOK->eOtherPublisherConncect;
#endif

		MSG_FP_CONNECT_AUTH_USER_OK	*pQParamAuthUserOK = new MSG_FP_CONNECT_AUTH_USER_OK;	// should be delete at CAtumDBManager::QP_GetAllCharacterInfoByID()
		*pQParamAuthUserOK = *pAuthUserOK;
		m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_GetAllCharacterInfoByID, pSoc, pSoc->m_character.AccountUniqueNumber, pQParamAuthUserOK);

		// send log
		CAtumLogSender::SendLogMessageLOGIN(pSoc, pAuthUserOK->AccountUniqueNumber);
		
		// start 2012-10-08 by khkim, GLog 
		// LogIn GLog 패킷Send 부분
		// 2015-02-10 by bckim, 임시 허용 
		//if(!COMPARE_RACE(pAuthUserOK->UserType, RACE_OPERATION|RACE_GAMEMASTER|RACE_MONITOR|RACE_GUEST|RACE_DEMO))		// 2013-01-18 by khkim, GLog (일반유저만 기록)
		{
			MSG_FL_LOG_ACCOUNTCONNECT LogAccountParameter;	
			LogAccountParameter.LogType			= GLOG_AC_LT_LOGIN; 
			LogAccountParameter.UserSerial		= pSoc->m_character.AccountUniqueNumber;
			LogAccountParameter.IP				= pSoc->GetPeerIP4();
			LogAccountParameter.GameServerID	= g_pFieldGlobal->GetMGameServerID();
			CAtumLogSender::SendLogAccountConnect(&LogAccountParameter);
		}
		// end 2012-10-08 by khkim, GLog

		INIT_MSG_WITH_BUFFER(MSG_FP_EVENT_ENTER_SELECT_SCREEN, T_FP_EVENT_ENTER_SELECT_SCREEN, msgEnterSelectScreen, msgEnterSelectScreenBuf);
		STRNCPY_MEMSET(msgEnterSelectScreen->AccountName, pSoc->m_character.AccountName, SIZE_MAX_ACCOUNT_NAME);
		Write(msgEnterSelectScreenBuf, MSG_SIZE(MSG_FP_EVENT_ENTER_SELECT_SCREEN));

		// 2012-10-05 by jhseol, NPlay pc방 모듈 - 필드에서 요청한 유저 인증이 완료되면 PREMIUM_INFO정보를 요청한다
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
		INIT_MSG_WITH_BUFFER(MSG_FP_PCBANG_USER_PREMIUM_REQUEST, T_FP_PCBANG_USER_PREMIUM_REQUEST, pSendRequestInfo, SendBuf);
		STRNCPY_MEMSET(pSendRequestInfo->AccountName, pSoc->m_character.AccountName, sizeof(pSendRequestInfo->AccountName));
		STRNCPY_MEMSET(pSendRequestInfo->ServerGroupName, g_pFieldGlobal->GetServerGroupName(), sizeof(pSendRequestInfo->ServerGroupName));
		m_pFieldIOCP2->m_pPreWinSocket->Write((char*)SendBuf, MSG_SIZE(MSG_FP_PCBANG_USER_PREMIUM_INFO));
		g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreWinSocket::Process_FP_CONNECT_AUTH_USER_OK, Send T_FP_PCBANG_USER_PREMIUM_REQUEST [AccountName:%s]\r\n", pSendRequestInfo->AccountName);
#endif
		// end 2012-10-05 by jhseol, NPlay pc방 모듈 - 필드에서 요청한 유저 인증이 완료되면 PREMIUM_INFO정보를 요청한다
	}
// 2004-12-16 by cmkwon, 다른 필드서버로의 워프는 없으므로 삭제함
//	else if ( authType == PRESERVER_AUTH_TYPE_WARP_CONNECT )
//	{
//		CFieldIOCPSocket *pCharacterSocket = (CFieldIOCPSocket*)(m_pFieldIOCP2->GetIOCPSocket(pAuthUserOK->ClientIndex));
//		INIT_MSG_WITH_BUFFER(MSG_FI_EVENT_GET_WARP_INFO, T_FI_EVENT_GET_WARP_INFO, pGetWarpInfo, pGetWarpInfoBuf);
//		pGetWarpInfo->CharacterUniqueNumber = pCharacterSocket->m_character.CharacterUniqueNumber;
//
//		m_pFieldIOCP2->m_pIMWinSocket->Write((char*)pGetWarpInfoBuf, MSG_SIZE(MSG_FI_EVENT_GET_WARP_INFO));
//
//		// check: QT_EventWarpConnect는 MSG_FI_EVENT_GET_WARP_INFO_OK 이후로 넘어감
//	}

// 2005-07-21 by cmkwon, 다른 필드서버로의 GameStart는 없으므로 삭제함
//	else if ( authType == PRESERVER_AUTH_TYPE_CONNECT_GAMESTART )
//	{
//		CFieldIOCPSocket *pFISocket = m_pFieldIOCP2->GetFieldIOCPSocket(pAuthUserOK->ClientIndex);
//		if(pFISocket 
//			&& pFISocket->IsUsing())
//		{
//			MSG_FP_CONNECT_AUTH_USER_OK	*pQParamAuthUserOK = new MSG_FP_CONNECT_AUTH_USER_OK;	// should be delete at CAtumDBManager::QP_GetAllCharacterInfoByID()
//			*pQParamAuthUserOK = *pAuthUserOK;
//
//			m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_ConnectGameStart, pFISocket
//				, pFISocket->m_character.AccountUniqueNumber, pQParamAuthUserOK);
//		}		
//	}
	else
	{
		// not reachable
		DBGOUT("ERROR@Process_FP_CONNECT_AUTH_USER_OK(): invalid authType[%d]\n\n", authType);
		assert(0);
	}

	return RES_RETURN_TRUE;
}

ProcessResult CPreWinSocket::Process_FP_MONITOR_SET_MGAME_EVENT_TYPE(const char* pPacket, int nLength, int &nBytesUsed)
{
	int							nRecvTypeSize	= 0;
	MSG_FP_MONITOR_SET_MGAME_EVENT_TYPE	*pRMsg	= NULL;

	nRecvTypeSize = sizeof(MSG_FP_MONITOR_SET_MGAME_EVENT_TYPE);
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_FP_MONITOR_SET_MGAME_EVENT_TYPE, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_PACKET_ERROR;
	}
	pRMsg = (MSG_FP_MONITOR_SET_MGAME_EVENT_TYPE*)(pPacket + nBytesUsed);
	nBytesUsed += nRecvTypeSize;

	g_pFieldGlobal->SetMGameEventType(pRMsg->enMGameEvent);
	return RES_RETURN_TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_MONITOR_RELOAD_VERSION_INFO_OK(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-09-08 by cmkwon, SCMonitor에서 ReloadVersionInfo시에 일부 체크섬파일(.\Res-Tex\*.*)도 리로드하기 - 
/// \author		cmkwon
/// \date		2008-09-08 ~ 2008-09-08
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_MONITOR_RELOAD_VERSION_INFO_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	g_pFieldGlobal->LoadResObjCheckListW(TRUE);
	// 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
#ifdef S_ALLOWED_IP_RELOAD_JHSEOL
	g_pFieldGlobal->ReLoadConfiguration();
	MessageType_t msgType = T_FL_LOG_MONITOR_RELOAD_VERSION_INFO_OK;
	g_pFieldGlobal->SendLogFieldServer2LogServer((BYTE*)&msgType, sizeof(msgType));

	if ( NULL != m_pFieldIOCP2->m_pNPCTCPSocket )
	{
		BYTE SendBuf[SIZE_MAX_PACKET];
		*(MessageType_t*)SendBuf = T_FN_MONITOR_RELOAD_VERSION_INFO_OK;
		m_pFieldIOCP2->m_pNPCTCPSocket->SendAddData(SendBuf, SIZE_FIELD_TYPE_HEADER);
	}
#endif
	// end 2013-03-14 by jhseol, 버전인포 리로드 시 접속 허용 IP리스트도 갱신
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_CONNECT_PREPARE_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2006-08-04 ~ 2006-08-04
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_CONNECT_PREPARE_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed)
{// No body

	m_pFieldIOCP2->SetPrepareShutdown(TRUE);
// 2007-08-27 by cmkwon, 서버다운준비 명령어 추가(SCAdminTool에서 SCMonitor의 PrepareShutdown을 진행 할 수 있게) - 위의 함수로 처리
//	m_pFieldIOCP2->m_bPrepareShutDown		= TRUE;		// 2006-08-04 by cmkwon, 서버 다운 진행상태
//	m_pFieldIOCP2->SetUnusableSpeakerItem(TRUE);		// 2007-08-24 by cmkwon, 스피커아이템 사용 가능/금지 설정 기능 추가 - 사용 불가로 설정한다
//	
//
//	MessageType_t msgTy = T_FC_CONNECT_NOTIFY_SERVER_SHUTDOWN;
//	m_pFieldIOCP2->SendMessageToAllClients((BYTE*)&msgTy, SIZE_FIELD_TYPE_HEADER);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_CONNECT_UPDATE_DBSERVER_GROUP(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - CPreWinSocket::Process_FP_CONNECT_UPDATE_DBSERVER_GROUP() 추가
/// \author		cmkwon
/// \date		2008-04-29 ~ 2008-04-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_CONNECT_UPDATE_DBSERVER_GROUP(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_CONNECT_UPDATE_DBSERVER_GROUP,
		MSG_FP_CONNECT_UPDATE_DBSERVER_GROUP, pRMsg);

	// 2009-01-30 by cmkwon, 서버그룹별 제한 유저수 설정 관련 시스템 로그 추가 - 아래와 같이 ServerGroupID 체크로 수정
	//if(0 != strncmp(pRMsg->DBServerGroup.ServerGroupName, g_pFieldGlobal->GetServerGroupName(), SIZE_MAX_SERVER_GROUP_COUNT))
	if(g_pFieldGlobal->GetMGameServerID() != pRMsg->DBServerGroup.ServerGroupID)
	{
		// 2009-01-30 by cmkwon, 서버그룹별 제한 유저수 설정 관련 시스템 로그 추가 - 
		g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] CPreWinSocket::Process_FP_CONNECT_UPDATE_DBSERVER_GROUP# invalid ServerGroupName !!, %s(%d), %d %d \r\n", 
			pRMsg->DBServerGroup.ServerGroupName, pRMsg->DBServerGroup.ServerGroupID, pRMsg->DBServerGroup.LimitUserCount, pRMsg->DBServerGroup.LockCreateCharacterForNewAccount);
		return RES_BREAK;
	}
	pRMsg->DBServerGroup.ServerGroupID		= g_pFieldGlobal->GetMGameServerID();		// 2008-04-29 by cmkwon, 
	g_pFieldGlobal->SetDBServerGroup(&pRMsg->DBServerGroup);							// 2008-04-29 by cmkwon, 설정

	// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
	SDBSERVER_GROUP	 *pQParam = new SDBSERVER_GROUP;
	*pQParam		= pRMsg->DBServerGroup;

	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_UpdateDBServerGroup, NULL, DB_THREAD_INDEX_1, pQParam);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - CPreWinSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT() 추가
/// \author		cmkwon
/// \date		2008-04-29 ~ 2008-04-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT,
		MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT, pRMsg);

	// 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
	MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT	 *pQParam = new MSG_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT;
	*pQParam		= *pRMsg;

	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_CheckConnectableAccount, NULL, DB_THREAD_INDEX_1, pQParam);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_ADMIN_RELOAD_WORLDRANKING(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
/// \author		cmkwon
/// \date		2009-02-25 ~ 2009-02-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_ADMIN_RELOAD_WORLDRANKING(const char* pPacket, int nLength, int &nBytesUsed)
{// No Body

	///////////////////////////////////////////////////////////////////////////////
	// 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
	m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_ReloadWRKServiceList, NULL, NULL);	

	// 2010-01-14 by cmkwon, 월드랭킹 리스트 리로드 구조 변경 - DQT_ReloadWRKServiceList 처리 후에 자동으로 호출되게 수정
	//m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_ReloadWRKLevel, NULL, NULL, NULL, FALSE);
	//m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_ReloadWRKFame, NULL, NULL, NULL, FALSE);
	//m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_ReloadWRKPVP, NULL, NULL, NULL, FALSE);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2009-09-16 by cmkwon, 세력 초기화시 어뷰징 방지 구현 - 
/// \author		cmkwon
/// \date		2009-09-22 ~ 2009-09-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_ADMIN_RELOAD_INFLUENCERATE(const char* pPacket, int nLength, int &nBytesUsed)
{// No Body

	g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreWinSocket::Process_FP_ADMIN_RELOAD_INFLUENCERATE \r\n");

	///////////////////////////////////////////////////////////////////////////////
	// 2009-09-16 by cmkwon, 세력 초기화시 어뷰징 방지 구현 - 
	m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_LoadInfluenceRate, NULL, NULL);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_EVENT_RELOAD_HAPPYEV(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		cmkwon
/// \date		2006-08-04 ~ 2006-08-04
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_EVENT_RELOAD_HAPPYEV(const char* pPacket, int nLength, int &nBytesUsed)
{// No body

	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_LoadHappyHourEvent, NULL, 0, NULL);
	return RES_RETURN_TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_EVENT_RELOAD_ITEMEV(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		dhjin
/// \date		2006-08-31 ~ 2006-08-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_EVENT_RELOAD_ITEMEV(const char* pPacket, int nLength, int &nBytesUsed)
{// No body

	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_LoadItemEvent, NULL, 0, NULL);
	// 2013-04-18 by jhseol,bckim 이달의 아머 - 이벤트 리로드
#ifdef S_MONTHL_ARMOR_EVENT_JHSEOL_BCKIM		// 이벤트 리로드
	if ( FALSE == g_pFieldGlobal->IsArenaServer() )
	{
		m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_LoadMonthlyArmorEvent, NULL, 0, NULL);
	}
#endif
	// end 2013-04-18 by jhseol,bckim 이달의 아머 - 이벤트 리로드
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_EVENT_UPDATE_PCBANGLIST(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		dhjin
/// \date		2007-01-22 ~ 2007-01-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_EVENT_UPDATE_PCBANGLIST(const char* pPacket, int nLength, int &nBytesUsed)
{
	// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList 변경 - 
	//m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_UpdatePCBangList, NULL, 0, NULL);
	m_pFieldIOCP2->m_pAtumDBManager->MakeQueryWithNewThread(DQT_UpdatePCBangList, NULL, NULL);	// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList 변경 - 
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_EVENT_UPDATE_STRATEGYPOINT_NOTSUMMONTIM(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		
/// \author		dhjin
/// \date		2007-03-06 ~ 2007-03-06
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_EVENT_UPDATE_STRATEGYPOINT_NOTSUMMONTIM(const char* pPacket, int nLength, int &nBytesUsed)
{
	m_pFieldIOCP2->m_pAtumDBManager->MakeAndEnqueueQuery(QT_LoadStrategyPointNotSummonTimeByAdminTool, NULL, 0, NULL);
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_ADMIN_BLOCKACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-01-31 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - CPreWinSocket::Process_FP_ADMIN_BLOCKACCOUNT_OK() 추가
/// \author		cmkwon
/// \date		2008-01-31 ~ 2008-01-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_ADMIN_BLOCKACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_ADMIN_BLOCKACCOUNT_OK,
											MSG_FP_ADMIN_BLOCKACCOUNT_OK, pRMsg);

	CFieldIOCPSocket *pFISoc = m_pFieldIOCP2->GetFieldIOCPSocket(pRMsg->AdminFieldServerClientIndex);
	if(NULL == pFISoc
		|| FALSE == pFISoc->IsValidCharacter(FALSE)
		|| 0 != strnicmp(pRMsg->AdminAccName, pFISoc->GetCharacter()->AccountName, SIZE_MAX_ACCOUNT_NAME))
	{
		return RES_BREAK;
	}

	if(ERR_NO_ERROR != pRMsg->ErrCode)
	{
		pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0001, pRMsg->BlockedAccName, pRMsg->ErrCode);
		return RES_BREAK;
	}

// 2008-03-18 by cmkwon, 나라별 날짜 형식 수정 - 아래와 같이 GetLocalDateTimeString() 함수로 변경
// 	pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0002
// 		, pRMsg->BlockedAccName, pRMsg->atimeEndTime.GetDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)));
 	pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0002
 		, pRMsg->BlockedAccName, pRMsg->atimeEndTime.GetLocalDateTimeString(string(), g_pFieldGlobal->GetLanguageType(), TRUE));
	return RES_RETURN_TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_ADMIN_UNBLOCKACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		// 2008-01-31 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - CPreWinSocket::Process_FP_ADMIN_UNBLOCKACCOUNT_OK() 추가
/// \author		cmkwon
/// \date		2008-01-31 ~ 2008-01-31
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_ADMIN_UNBLOCKACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_ADMIN_UNBLOCKACCOUNT_OK,
											MSG_FP_ADMIN_UNBLOCKACCOUNT_OK, pRMsg);

	CFieldIOCPSocket *pFISoc = m_pFieldIOCP2->GetFieldIOCPSocket(pRMsg->AdminFieldServerClientIndex);
	if(NULL == pFISoc
		|| FALSE == pFISoc->IsValidCharacter(FALSE)
		|| 0 != strnicmp(pRMsg->AdminAccName, pFISoc->GetCharacter()->AccountName, SIZE_MAX_ACCOUNT_NAME))
	{
		return RES_BREAK;
	}

	if(ERR_NO_ERROR != pRMsg->ErrCode)
	{
		switch(pRMsg->ErrCode)
		{
		case ERR_NOT_ACCOUNT_BLOCKED:
			{
				pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0003, pRMsg->UnblockedAccName, pRMsg->ErrCode);
			}
			break;
		default:
			{
				pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0004, pRMsg->UnblockedAccName, pRMsg->ErrCode);
			}
		}
		return RES_BREAK;
	}

	pFISoc->SendString128(STRING_128_ADMIN_CMD, STRMSG_080201_0005, pRMsg->UnblockedAccName);
	return RES_RETURN_TRUE;
}

////////////////////////////////////////////////////////////////////////////
// 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전
///////////////////////////////////////////////////////////////////////////////
/// \fn			ProcessResult CPreWinSocket::Process_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE(const char* pPacket, int nLength, int &nBytesUsed)
/// \brief		어드민 툴에서 거점전 셋팅을 변경했다고 알림
/// \author		jhseol
/// \date		2012-11-13
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ProcessResult CPreWinSocket::Process_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE,
		MSG_FP_ADMIN_STRATRGYPOINT_INFO_CHANGE, pRMsg);
	if( 0 == strcmp(pRMsg->DBName, g_pGlobalGameServer->GetDBServerDatabaseName()) )
	{
		if( NULL != m_pFieldIOCP2 )
		{
			m_pFieldIOCP2->m_InflWarManager.InitStrategyPoint();
			g_pFieldGlobal->WriteSystemLogEX(FALSE, "  [Notify] S_WAR_SYSTEM_RENEWAL_STRATEGYPOINT_JHSEOL #RecvdPacket - DBName(%s)\r\n", pRMsg->DBName);	// 2013-10-16 by jhseol, 서버 디버깅시 불필요 DBGOUT 출력 코드 제거
		}
	}
	return RES_RETURN_TRUE;
}
// end 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전

ProcessResult CPreWinSocket::Process_ERROR(const char* pPacket, int nLength, int &nBytesUsed)
{
	int			nRecvTypeSize	= 0;
	MSG_ERROR	*pMsgRecvErr	= NULL;
	char szErrString[SIZE_MAX_STRING_1024]; // 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.

	nRecvTypeSize = sizeof(MSG_ERROR) + ((MSG_ERROR*)(pPacket+nBytesUsed))->StringLength;
	if(nLength - nBytesUsed < nRecvTypeSize)
	{
		SendErrorMessage(T_ERROR, ERR_PROTOCOL_INVALID_FIELD_DATA);
		return RES_BREAK;
	}
	pMsgRecvErr = (MSG_ERROR*)(pPacket + nBytesUsed);
	
	// 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
	MEMSET_ZERO(szErrString, SIZE_MAX_STRING_1024);
	if(0 < ((MSG_ERROR*)(pPacket+nBytesUsed))->StringLength)
	{
		memcpy(szErrString,pPacket+nBytesUsed+sizeof(MSG_ERROR),((MSG_ERROR*)(pPacket+nBytesUsed))->StringLength);
	}
	// end 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
	nBytesUsed += nRecvTypeSize;

	//  처리
	char buf[128];
	Err_t error = pMsgRecvErr->ErrorCode;

	g_pFieldGlobal->WriteSystemLogEX(TRUE, "  T_ERROR %s(%#04X) received from %s[%s]\r\n", GetErrorString(pMsgRecvErr->ErrorCode), pMsgRecvErr->ErrorCode, "ST_PRE_SERVER", m_szPeerIP);

	switch(pMsgRecvErr->MsgType)
	{
	case T_FP_CONNECT_AUTH_USER:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_NOT_LOGINED);
				DBGOUT("[Error] %s : %s(%d)\n", pFieldIOCPSocket->m_character.CharacterName, GetErrorString(ERR_PROTOCOL_NOT_LOGINED), ERR_PROTOCOL_NOT_LOGINED);
			}
			
			return RES_BREAK;
		}
		break;		
	}


	switch (error)
	{
	case ERR_PROTOCOL_ACCOUNT_BLOCKED:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				// 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_ACCOUNT_BLOCKED,0,0,szErrString,TRUE);
				DBGOUT("[Error]ERR_PROTOCOL_ACCOUNT_BLOCKED: %s\n", pFieldIOCPSocket->GetCharacter()->AccountName);
				//pFieldIOCPSocket->Close(0x14063);
				// end 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
			}
		}
		break;		// 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기. 누락된 break; 추가
	case ERR_PROTOCOL_DUPLICATE_LOGIN:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_DUPLICATE_LOGIN);
				DBGOUT("[Error]ERR_PROTOCOL_DUPLICATE_LOGIN: %s\n", pFieldIOCPSocket->GetCharacter()->AccountName);
				pFieldIOCPSocket->Close(0x14063);
			}
		}
		break;
	case ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED);
				DBGOUT("[Error]ERR_PROTOCOL_CLIENT_IP_NOT_MATCHED: %s\n", pFieldIOCPSocket->GetCharacter()->AccountName);
				pFieldIOCPSocket->Close(0x14064);
			}
		}
		break;
	case ERR_PROTOCOL_NOT_LOGINED:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_NOT_LOGINED);
			}
			DBGOUT("[Error]ERR_PROTOCOL_NOT_LOGINED: %d\n", pMsgRecvErr->ErrParam1);
		}
		break;
	case ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED);
				DBGOUT("[Error]ERR_PROTOCOL_FIELD_SERVER_ID_NOT_MATCHED: %s %d\n", pFieldIOCPSocket->m_character.CharacterName, pMsgRecvErr->ErrParam1);
			}
		}
		break;
	// 2012-07-11 by hskim, 선택적 셧다운
	case ERR_PROTOCOL_SELECTIVE_SHUTDOWN_APPLY_LOGOUT:
		{
			CFieldIOCPSocket *pFieldIOCPSocket = m_pFieldIOCP2->GetFieldIOCPSocket(pMsgRecvErr->ErrParam1);
			if (pFieldIOCPSocket->GetClientState() != CS_NOTCONNECT)
			{
				pFieldIOCPSocket->SendErrorMessage(T_ERROR, ERR_PROTOCOL_SELECTIVE_SHUTDOWN_APPLY_LOGOUT);
				DBGOUT("[Error]ERR_PROTOCOL_SELECTIVE_SHUTDOWN_APPLY_LOGOUT: %s\n", pFieldIOCPSocket->GetCharacter()->AccountName);
				pFieldIOCPSocket->Close(0x14063);
			}
		}
		break;
	// end 2012-07-11 by hskim, 선택적 셧다운
	case ERR_PROTOCOL_NO_SUCH_SERVER_GROUP:
	case ERR_PROTOCOL_NO_SUCH_FIELD_SERVER:
	default:
		{
			sprintf(buf, "Cannt Handle Error(From Pre Server): %s[%#04X]\n", GetErrorString(pMsgRecvErr->ErrorCode), pMsgRecvErr->ErrorCode);
			//MessageBox(NULL, buf, "Error", MB_OK);
			DBGOUT(buf);
		}
		break;
	}

	return RES_RETURN_TRUE;
}

// start 2012-01-08 by hskim, GLog 2차
ProcessResult CPreWinSocket::Process_FP_GLOG_CONNECT_USER_NEW(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_GLOG_CONNECT_USER_NEW,
		MSG_FP_GLOG_CONNECT_USER_NEW, pRMsg);

	CAtumLogSender::SendLogMessageConnectUserNew(pRMsg->AccountName);

	return RES_RETURN_TRUE;
}

ProcessResult CPreWinSocket::Process_FP_GLOG_CONNECT_USER_LOGIN(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_GLOG_CONNECT_USER_LOGIN,
		MSG_FP_GLOG_CONNECT_USER_LOGIN, pRMsg);

	CAtumLogSender::SendLogMessageConnectUserLogin(pRMsg->AccountName);

	return RES_RETURN_TRUE;
}
// end 2012-01-08 by hskim, GLog 2차

// 2013-03-14 by bckim, Glog 기능추가
ProcessResult CPreWinSocket::Process_FP_GLOG_NEW_ACCOUNT_INFO(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_GLOG_NEW_ACCOUNT_INFO,
		MSG_FP_GLOG_NEW_ACCOUNT_INFO, pRMsg);

	pRMsg->Type = m_pFieldIOCP2->GetChannellingServerUIDbyToken(pRMsg->AccountName[0]);	// 2014-02-10 by jhseol&bckim, 체널링 - 한국 유저 정보 GLog 저장

	CAtumLogSender::SendLogMessageNewAccountInfo(pRMsg);
	
	return RES_RETURN_TRUE;
}
// End. 2013-03-14 by bckim, Glog 기능추가


///////////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc방 모듈
ProcessResult CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_INFO(const char* pPacket, int nLength, int &nBytesUsed)
{
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_PREMIUM_INFO,
		MSG_FP_PCBANG_USER_PREMIUM_INFO, pRMsg);

	g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_INFO, Recevie [AccountName:%s] [PremiumApply:%d]\r\n", pRMsg->AccountName, pRMsg->PremiumApply);
	CFieldIOCPSocket *pFSocket = NULL;
	pFSocket = m_pFieldIOCP2->GetFieldIOCPSocketByAccountName(pRMsg->AccountName);
	if( NULL == pFSocket)
	{
		g_pFieldGlobal->WriteSystemLogEX(TRUE,"  [Notify] CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_INFO, [AccountName:%s] pFSocket is NULL.\r\n", pRMsg->AccountName);
	}
	else
	{
		pFSocket->m_bIsPCBangClient = pRMsg->PremiumApply;
		//pFSocket->SetHomepremium(pRMsg->PremiumApply);
	}
	return RES_RETURN_TRUE;
}

ProcessResult CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME(const char* pPacket, int nLength, int &nBytesUsed)
{
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
	DECLARE_MESSAGE_AND_CHECK_SIZE_SERVER(pPacket, nLength, nBytesUsed, T_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME,
		MSG_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME, pRMsg);
	
	g_pFieldGlobal->WriteSystemLogEX(TRUE, "  [Notify] CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME, Recevie [AccountName:%s] [ResidualTime:%d]\r\n", pRMsg->AccountName, pRMsg->ResidualTime);
	CFieldIOCPSocket *pFSocket = NULL;
	pFSocket = m_pFieldIOCP2->GetFieldIOCPSocketByAccountName(pRMsg->AccountName);
	if( NULL == pFSocket)
	{
		g_pFieldGlobal->WriteSystemLogEX(TRUE,"  [Notify] CPreWinSocket::Process_FP_PCBANG_USER_PREMIUM_RESIDUAL_TIME, [AccountName:%s] pFSocket is NULL.\r\n", pRMsg->AccountName);
	}
	else
	{
		if( 0 >= pRMsg->ResidualTime )
		{
			pFSocket->SendString128(STRING_128_USER_NOTICE, STRMSG_121005_0002);
		}
		else
		{
			pFSocket->SendString128(STRING_128_USER_NOTICE, STRMSG_121005_0001, pRMsg->ResidualTime);
		}
	}
#endif
	return RES_RETURN_TRUE;
}
// end 2012-10-05 by jhseol, NPlay pc방 모듈

















