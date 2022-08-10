// CNPlayPCBangModule.h: interface for the CNPlayPCBangModule class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASPCBNAGMANAGER_H__F54CA42B_41BD_4644_A648_5B5A0E907EBC__INCLUDED_)
#define AFX_ASPCBNAGMANAGER_H__F54CA42B_41BD_4644_A648_5B5A0E907EBC__INCLUDED_
  
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma pack(push, 1)
struct NET_Packet_PCBANG
{
	WORD	wLen;
	WORD	wReqType;	
};


//////////// ���Ӽ��� ���� ��û ////////////
typedef struct _BOQPTS_GS_CONNECT
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	BYTE  ConnectFlag;
	
	WORD	RetCode;
}BOQPTS_GS_CONNECT, PBOQPTS_GS_CONNECT;

//////////// ���� ���� ���� üũ ��û ////////////
typedef struct _BOQPTS_HEALTH_CHECK
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	
	WORD	RetCode;
} BOQPTS_HEALTH_CHECK, *PBOQPTS_HEALTH_CHECK;

//////////// PC�� �������� Ȯ�� ��û ////////////
typedef struct _BOQPTS_CHECKPREMIUM
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD ClientIP;
	WORD	ClientPort;
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	char    UserID[50+1];
	
	BYTE	PremiumType;
	BYTE	BillMethod;
	DWORD	RemainTime;
	WORD	RetCode;
} BOQPTS_CHECKPREMIUM, *PBOQPTS_CHECKPREMIUM;

//////////// PC�� �������� Ȯ�� ��û2 ////////////
typedef struct _BOQPTS_CHECKPREMIUM2
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD ClientIP;
	WORD	ClientPort;
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	char    UserID[50+1];
	
	BYTE	PremiumType;
	BYTE	BillMethod;
	DWORD	RemainTime;
	BYTE	SameGameUser;
	DWORD	PCBangNo;
	WORD	RetCode;
} BOQPTS_CHECKPREMIUM2, *PBOQPTS_CHECKPREMIUM2;

//////////// �ð����� ���� ��û ////////////
typedef struct _BOQPTS_GAMESTART
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD ClientIP;
	WORD	ClientPort;
	BYTE   DisconnectFlag;
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	char    UserID[50+1];
	char    CharacterID[30+1];
	BYTE	PremiumType;
	BYTE	BillMethod;
	DWORD	RemainTime;
	BYTE	SameGameUser;
	DWORD	PCBangNo;
	WORD	RetCode;
} BOQPTS_GAMESTART, *PBOQPTS_GAMESTART;

//////////// ���Ӽ��� ���� ��û////////////
typedef struct _BOQPTS_CHANGE_GAMESERVER
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	BYTE   Status;
	WORD  GameServerNoB;
	WORD  GameServerNoA;
	DWORD WorldNo;
	WORD  GameNo;
	DWORD UserNo;
	char    UserID[50+1];
	
	WORD	RetCode;
} BOQPTS_CHANGE_GAMESERVER, *PBOQPTS_CHANGE_GAMESERVER;

//////////// �ð����� ���� ��û //////////// 
typedef struct _BOQPTS_GAMEEND
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD WorldNo;
	WORD  GameNo;
	char    UserID[50+1];
	
	WORD	RetCode;
} BOQPTS_GAMEEND, *PBOQPTS_GAMEEND;
//////////// ���Ӽ��� �� ��� ����� ���� ��û ////////////
typedef struct _BOQPTS_ALL_DISCONNECT
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	WORD  GameServerNo;
	DWORD WorldNo;
	WORD  GameNo;
	
	WORD	RetCode;
}BOQPTS_ALL_DISCONNECT, *PBOQPTS_ALL_DISCONNECT;

//////////// ���ӻ��� Ȯ�� ��û //////////// 
typedef struct _BOQPTS_ISALIVE
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD WorldNo;
	WORD  GameNo;
	char    UserID[50+1];
	
	WORD	RetCode;
} BOQPTS_ISALIVE, *PBOQPTS_ISALIVE;

//////////// �ܿ��ð� �뺸 //////////// 
typedef struct _BOQPTS_ALARM_EXPIRE
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD WorldNo;
	DWORD Minutes;
	char    UserID[50+1];
	
} BOQPTS_ALARM_EXPIRE, *PBOQPTS_ALARM_EXPIRE;

//////////// �ܿ��ð� ���� �뺸 //////////// 
typedef struct _BOQPTS_TIME_EXPIRED
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD WorldNo;
	char    UserID[50+1];
	
} BOQPTS_TIME_EXPIRED, *PBOQPTS_TIME_EXPIRED;

//////////// ��ǰ �Ӽ� ���� �뺸//////////// 
typedef struct _BOQPTS_PTYPE_CHANGED
{
	WORD  ReqLen;
	WORD  ReqType;
	DWORD ReqKey;
	
	DWORD UserNo;
	DWORD WorldNo;
	char    UserID[50+1];
	BYTE   PremiumTypeB;
	BYTE   PremiumTypeA;
} BOQPTS_PTYPE_CHANGED, *PBOQPTS_PTYPE_CHANGED;

#pragma pack(pop)

struct NPLAY_CONNECT_CLIENT_INFO
{
	char	AccountName[SIZE_MAX_ACCOUNT_NAME];			// ����� ���̵�
	char	ServerGroupName[SIZE_MAX_SERVER_NAME];			// ���� �׷� �̸�
 	BOQPTS_CHECKPREMIUM2	PremiumInfo;					// �����̾� ����
};

typedef vector<NPLAY_CONNECT_CLIENT_INFO>		vectNPlayConnectClientList;


#include "WinSocket.h"
#include "TickManager.h"

class CPreIOCP;

//////////////////////////////////////////////////////////////////////
// class CNPlayPCBangModule
class CNPlayPCBangModule : public CWinSocket, public CTickManager
{
public:
	CNPlayPCBangModule(HWND i_hWnd, DWORD i_nTickInterval = SPTOMP_TICK_INTERVAL, char* i_szNPlayServerIP_Real = "", char* i_szNPlayServerIP_BackUp = "");
	virtual ~CNPlayPCBangModule();
	
	void NPlayCreateSocket();
	virtual BOOL OnRecvdPacket(LPSTR pPacket, int nLength, BYTE nSeq);
	virtual BOOL OnCloseSocket(int nErrorCode);

	BOOL NPlayServerConnect();
	BOOL IsConnected();
	void VectNPlayConnectClientList_Login(char* i_AccountName, char* i_ClientIP, int i_ClientPort);
	void VectNPlayConnectClientList_Pop(char* i_AccountName);
	void VectNPlayConnectClientList_SendPremiuminfo(char* i_AccountName, char* i_ServerGroupName);
	void VectNPlayConnectClientList_GameStart(char* i_AccountName, char* i_ServerGroupName);
	void VectNPlayConnectClientList_GameEnd(char* i_AccountName);
	void VectNPlayConnectClientList_SendAllDisConnectByServername(char* i_srvername);


protected:
	//////////////////////// Receive ��Ŷ //////////////////////// 
	ProcessResult Process_GsConnect			(const char* pPacket, int nLength, int &nBytesUsed);		// ���Ӽ������� ��û/����
	ProcessResult Process_HealthCHeck		(const char* pPacket, int nLength, int &nBytesUsed);		// ���Ӽ������� ��û/����
	ProcessResult Process_CheckPremium2		(const char* pPacket, int nLength, int &nBytesUsed);		// PC�� �������� Ȯ�� ��û2
	ProcessResult Process_GameStart			(const char* pPacket, int nLength, int &nBytesUsed);		// ���ӽ�ŸƮ
	ProcessResult Process_ChangeGameEnd		(const char* pPacket, int nLength, int &nBytesUsed);		// ��������
	ProcessResult Process_AllDisConnect		(const char* pPacket, int nLength, int &nBytesUsed);		// ��ü����
	ProcessResult Process_IsAlive			(const char* pPacket, int nLength, int &nBytesUsed);		// ����ֳ�?
	ProcessResult Process_AlarmExpire		(const char* pPacket, int nLength, int &nBytesUsed);		// �ܿ��ð� �뺸
	ProcessResult Process_TimeExpire		(const char* pPacket, int nLength, int &nBytesUsed);		// �ܿ��ð� ���� �뺸
	ProcessResult Process_BoqptsChanged		(const char* pPacket, int nLength, int &nBytesUsed);		// ��ǰ���� BOQPTS_PTYPE_CHANGED

	//////////////////////// Send ��Ŷ ////////////////////////
	// ���Ӽ������� ��û/����
	BOOL GsConnect();
	// ���Ӽ��� �������
	void SendHealthCheck();
	// PC�� �������� Ȯ�� ��û2
	void SendCheckPremium2(char* pAccountName, char* pUserIp, WORD wClientPort);
	// �ð����� ���� ��û
	void SendGameStart(BOQPTS_CHECKPREMIUM2* pCheckPreMium2);
	// �ð����� ���� ��û
	void SendGameEnd(char* pAccountName);
	// ���Ӽ��� �� ��� ����� ���� ��û
	void SendAllDisConnect();
	// ���ӻ��� Ȯ�� ��û
	void SendIsAlive(char* pAccountName);

	int HealthCheckTimer();
	void SendPremiuminfoToField(char* i_AccountName, char* i_UserGameServerName, BOOL i_PremiumApply);
	void SendResidualTimeToField(char* i_AccountName, char* i_UserGameServerName, DWORD ResidualTime);
	
	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent);
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime);

	BOOL m_bConnectNPlayServer;		// PC�� ������ ���� ����
	vectNPlayConnectClientList	m_vectNPlayConnectClientList;

	BYTE				m_nGsConnectFailCount;
	ATUM_DATE_TIME		m_atimeGsConnectFailTime;
	ATUM_DATE_TIME		m_atimeHealthCheckTime;
	BOOL				m_bHealthCheckReturn;

	CRITICAL_SECTION	m_criticalSection;

private:

};

#endif