// PreIOCPSocket.h: interface for the CPreIOCPSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREIOCPSOCKET_H__9C62870A_F7ED_49A2_9583_956845931320__INCLUDED_)
#define AFX_PREIOCPSOCKET_H__9C62870A_F7ED_49A2_9583_956845931320__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PreIOCP.h"
#include "AtumProtocol.h"

class CPreIOCPSocket : public CIOCPSocket
{
	friend CPreIOCP;
public:
	CPreIOCPSocket();
	~CPreIOCPSocket();

public:
	BOOL OnRecvdPacketPreServer(const char* pPacket, int nLength, BYTE nSeq, char* pPeerIP = "", int nPeerPort = 0, SThreadInfo *i_pThreadInfo=NULL);
	void OnConnect(void);
	void OnClose(int reason = 0);

	// Process Protocol
	ProcessResult Process_PA_ADMIN_PETITION_SET_PERIOD(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PA_ADMIN_SET_DBSERVER_GROUP(const char* pPacket, int nLength, int &nBytesUsed);	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	ProcessResult Process_PA_RELOAD_GUILD_INFO(const char* pPacket, int nLength, int &nBytesUsed);				// 2014-02-11 by bckim, �����ʱ�ȭ�� ���� ����ȭó��

	// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - CPreIOCPSocket::Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM() 
	ProcessResult Process_PA_ADMIN_RELOAD_ADMIN_NOTICE_SYSTEM(const char* pPacket, int nLength, int &nBytesUsed);

	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	ProcessResult Process_PA_ADMIN_RELOAD_WORLDRANKING(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PA_ADMIN_RELOAD_INFLUENCERATE(const char* pPacket, int nLength, int &nBytesUsed);	// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 

	ProcessResult Process_PC_CONNECT_SINGLE_FILE_VERSION_CHECK(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_CONNECT_VERSION(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_DEFAULT_UPDATE_LAUNCHER_VERSION(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_CONNECT_LOGIN(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_CONNECT_GET_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_DEFAULT_NEW_UPDATE_LAUNCHER_VERSION(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PC_CONNECT_NETWORK_CHECK(const char* pPacket, int nLength, int &nBytesUsed);		// 2007-06-18 by cmkwon, ��Ʈ��ũ ���� üũ
	ProcessResult Process_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST(const char* pPacket, int nLength, int &nBytesUsed);	// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �߰��� �������� ó���Լ�

	ProcessResult Process_FP_CONNECT_AUTH_USER(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_CONNECT_FIELD_CONNECT(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_CONNECT_NOTIFY_FIELDSERVER_CHANGE(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_CONNECT_NOTIFY_CLOSE(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_CONNECT_CHECK_CONNECTABLE_ACCOUNT_OK(const char* pPacket, int nLength, int &nBytesUsed);	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 

	ProcessResult Process_FP_EVENT_NOTIFY_WARP(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_EVENT_ENTER_SELECT_SCREEN(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_EVENT_GAME_STARTED(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_EVENT_MAP_CHANGED(const char* pPacket, int nLength, int &nBytesUsed);
	
	ProcessResult Process_FP_CASH_CHANGE_CHARACTERNAME(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_ADMIN_BLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed);		// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
	ProcessResult Process_FP_ADMIN_UNBLOCKACCOUNT(const char* pPacket, int nLength, int &nBytesUsed);	// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 

	ProcessResult Process_IP_CONNECT_IM_CONNECT(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_IP_GET_SERVER_GROUP_INFO_ACK(const char* pPacket, int nLength, int &nBytesUsed);

	ProcessResult Process_PM_PREPARE_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PM_RELOAD_VERSION_INFO_HEADER(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PM_RELOAD_VERSION_INFO_LIST(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PM_RELOAD_VERSION_INFO_DONE(const char* pPacket, int nLength, int &nBytesUsed);

	// start 2011-06-22 by hskim, �缳 ���� ����
	ProcessResult Process_IP_AUTHENTICATION_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_AUTHENTICATION_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed);
	// end 2011-06-22 by hskim, �缳 ���� ����

	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
	ProcessResult Process_PP_CONNECT(const char* pPacket, int nLength, int &nBytesUsed);

	////////////////////////////////////////////////////////////////////////////
	// 2012-10-05 by jhseol, NPlay pc�� ���
	ProcessResult Process_FP_PCBANG_USER_GAME_START(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_PCBANG_USER_GAME_END(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_PCBANG_USER_PREMIUN_END(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_FP_PCBANG_USER_PREMIUM_REQUEST(const char* pPacket, int nLength, int &nBytesUsed);
	// end 2012-10-05 by jhseol, NPlay pc�� ���

	// Process DB Query Result
	BOOL ResPreLogin(MSG_PC_CONNECT_LOGIN *pRecvMsgLogin, CAccountInfo *i_pAccInfo, Err_t nErr);

	void SendErrorMessage(MessageType_t msgType, Err_t err, int errParam1 = 0, int errParam2 = 0, char* errMsg = NULL, BOOL bCloseConnection = FALSE);

	void SetClientState(CP_State i_nCPState, CAccountInfo *i_pAccountInfo);
	CP_State GetClientState(CAccountInfo *i_pAccountInfo);

private:
	CP_State			m_CPClientState;
	char				m_szConnectedServerGroupName[SIZE_MAX_SERVER_NAME];
	char				m_szAdminAccountName[SIZE_MAX_ACCOUNT_NAME];			// 2007-06-20 by cmkwon, ���� ������ �ý��� �α׿� �߰�

	static CPreIOCP		*ms_pPreIOCP;

	eCONNECT_PUBLISHER	m_eOtherPublisherConncect;				// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
};

#endif // !defined(AFX_PREIOCPSOCKET_H__9C62870A_F7ED_49A2_9583_956845931320__INCLUDED_)
