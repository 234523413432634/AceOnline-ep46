// S2CWinSocket.cpp: implementation of the CS2CWinSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SCDialer2.h"
#include "S2CWinSocket.h"
#include "VoIPProtocol.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CS2CWinSocket::CS2CWinSocket(HWND hWnd, UINT wmSock/*=WM_S2C_ASYNC_EVENT*/, UINT wmNotify/*=WM_S2C_PACKET_NOTIFY*/)
	: CWinSocket(hWnd, wmSock, wmNotify, FALSE)
{

}

CS2CWinSocket::~CS2CWinSocket()
{

}


BOOL CS2CWinSocket::OnCloseSocket(int nErrorCode)
{
	//////////////////////////////////////////////////////////////////////
	// TODO: Add your specialized code here

	//
	//////////////////////////////////////////////////////////////////////

	return CWinSocket::OnCloseSocket(nErrorCode);
}

BOOL CS2CWinSocket::OnConnect(int nErrorCode)
{
	CWinSocket::OnConnect(nErrorCode);
	//////////////////////////////////////////////////////////////////////
	// TODO: Add your specialized code here

	//
	//////////////////////////////////////////////////////////////////////
	return	TRUE;
}


BOOL CS2CWinSocket::OnRecvdPacket(LPSTR pPacket, int nLength, BYTE nSeq)
{
	int					nBytesUsed	= 0;
	MessageType_t		RecvMsgType	= 0;
	int					nRecvMsgSize = 0;
	ProcessResult		procRes		= RES_RETURN_FALSE;


	while(nBytesUsed < nLength)
	{
		procRes			= RES_BREAK;
		RecvMsgType		= *(MessageType_t*)(pPacket+nBytesUsed);
		nRecvMsgSize	= SIZE_FIELD_TYPE_HEADER;

		switch(RecvMsgType)
		{
		case T_C2S_CONNECT_OK:		// nobody
			break;
		case T_C2S_CREATE_ROOM_OK:
			{
				nRecvMsgSize += sizeof(MSG_C2S_CREATE_ROOM_OK);
			}
			break;
		case T_C2S_JOIN_ROOM_OK:
			{
				nRecvMsgSize += sizeof(MSG_C2S_JOIN_ROOM_OK);
			}
			break;
		case T_C2S_JOINED_USERLIST:
			{
				MSG_C2S_JOINED_USERLIST *pMsg = (MSG_C2S_JOINED_USERLIST*)(pPacket+nBytesUsed+nRecvMsgSize);
				nRecvMsgSize += sizeof(MSG_C2S_JOINED_USERLIST) + pMsg->byUserCounts*sizeof(JoinedUserInfo);
			}
			break;
		case T_C2S_JOIN_USER:
			{
				nRecvMsgSize += sizeof(MSG_C2S_JOIN_USER);
			}
			break;
		case T_C2S_GOOUT_USER:
			{
				nRecvMsgSize += sizeof(MSG_C2S_GOOUT_USER);
			}
			break;
		case T_C2S_REQUEST_TOKEN_OK:
			{
				nRecvMsgSize += sizeof(MSG_C2S_REQUEST_TOKEN_OK);
			}
			break;
		case T_C2S_CHANGE_TALKING_STATE_OK:	// 2008-10-15 by cmkwon, ���ϱ� ��� ���� - 
			{
				nRecvMsgSize += sizeof(MSG_C2S_CHANGE_TALKING_STATE_OK);
			}
			break;
		case T_C2S_LOST_TOKEN:
			{
				nRecvMsgSize += sizeof(MSG_C2S_LOST_TOKEN);
			}
			break;
		case T_C2S_RTP_PACKET:
			{
				MSG_C2S_RTP_PACKET *pMsg = (MSG_C2S_RTP_PACKET*)(pPacket+nBytesUsed+nRecvMsgSize);
				nRecvMsgSize += sizeof(MSG_C2S_RTP_PACKET) + pMsg->usRTPLength;				
			}
			break;

		case T_ERROR:
			{
				nRecvMsgSize += sizeof(MSG_ERROR);
			}
			break;
			
		////////////////////////////////////////////////////////////////////////
		// Unknown Message	
		default:
			{
				char	szSystemLog[256];
				sprintf(szSystemLog, "[Error] CS2CWinSocket::OnRecvdPacket Unknown Message Type[%d (0x%08X)]\r\n"
					, RecvMsgType, RecvMsgType);
				DbgOut(szSystemLog);
				procRes = RES_PACKET_ERROR;
			}
		}

		///////////////////////////////////////////////////////////////////////////////
		// ���� �޼��� üũ
		if(nLength-(nBytesUsed+nRecvMsgSize) < 0){				procRes = RES_PACKET_ERROR;}

		///////////////////////////////////////////////////////////////////////////////
		// MSG ��� ó��
		switch(procRes)
		{
		case RES_RETURN_FALSE:	// �ɰ��� ���� �̹Ƿ� FALSE�� �����Ͽ� Socket�� �����Ѵ�
		case RES_PACKET_ERROR:	// ��Ŷ�� �ջ�� ���. ���� packet�� ó������ �ʰ� �ٷ� �����Ѵ�.
			return FALSE;
		}
		
		char *pTmMsg = new char[nRecvMsgSize];
		memcpy(pTmMsg, pPacket+nBytesUsed, nRecvMsgSize);
		EnterCriticalSection(&m_criticalRecvMessageQueue);
		m_queueRecvMessage.push(pTmMsg);
		LeaveCriticalSection(&m_criticalRecvMessageQueue);

		nBytesUsed +=nRecvMsgSize;
	}// while_end

	if(false == m_queueRecvMessage.empty())
	{
		PostNotify(WS_RECEIVED); 
	}
	return TRUE;
}