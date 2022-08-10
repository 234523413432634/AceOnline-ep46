// NATAnalyzer.h: interface for the CNATAnalyzer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NATANALYZER_H__FBD61870_19C6_49E3_8715_80B672BEF120__INCLUDED_)
#define AFX_NATANALYZER_H__FBD61870_19C6_49E3_8715_80B672BEF120__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Protocol_FireTalk_II.h"
#include "NATAnalyzerSock.h"

typedef enum 
{
	_N_NULL					= 0,	// ó�� ������ ����
	_N_READY				= 1,	// ������ FireTalk II�� IP�� Port�� �����ǰ� �޼��� ������ �ڵ鵵 �̻��� ���� ����
	_N_A_SEND				= 2,	// NAT Ÿ��(cone or other)�� Ȯ���ϱ����� NAT_A UDP ��Ŷ�� ������ ���� ����
	_N_A_ACK_B_SEND			= 3,	// NAT_A��Ŷ�� ���� ������ �ް� NAT_B UDP ��Ŷ�� ������ FireTalk II�� ���� ����
//	_N_A_ACK_B_ACKfromS		= 4,	// NAT_A��Ŷ�� ���� ������ �ް� NAT_B UDP ��Ŷ�� ���� ������ ������ ���� ���� ����
//	_N_A_ACK_B_ACKfromF		= 5,	// NAT_A��Ŷ�� ���� ������ �ް� NAT_B UDP ��Ŷ�� ���� ������ FireTalk II�� ���� ���� ����

	_N_A_NOACK_B_SEND		= 10,	// NAT_A��Ŷ�� ���� ������ ���� ���ϰ� NAT_B UDP ��Ŷ�� ������ FireTalk II�� ���� ����
//	_N_A_NOACK_B_ACKfromS	= 11,	// NAT_A��Ŷ�� ���� ������ ���� ���ϰ� NAT_B UDP ��Ŷ�� ���� ������ ������ ���� ���� ����
//	_N_A_NOACK_B_ACKfromF	= 12,	// NAT_A��Ŷ�� ���� ������ ���� ���ϰ� NAT_B UDP ��Ŷ�� ���� ������ FireTalk II�� ���� ���� ����

	_N_RESULT				= 20	// NAT Ÿ�� �м��� �Ϸ� �Ͽ���
	
} NATAnalyzerStatus;

class CNATAnalyzerSock;
class CNATAnalyzer  
{
public:
	CNATAnalyzer();
	virtual ~CNATAnalyzer();

public:
	// ��� ����
	CNATAnalyzerSock*	m_pAnalyzerSock;		// NAT Ÿ���� �м��ϱ� ���� ���Ǵ� UDP ����
	HWND				m_hMsgWnd;				// NAT Ÿ���� Ȯ�εǸ� �޼����� ���� ������ �ڵ�
	char				m_strServerIP[16];		// NAT Ÿ���� �м��ϱ� ���� ���Ǵ� ���� A IP
	UINT				m_nServerPort;			// NAT Ÿ���� �м��ϱ� ���� ���Ǵ� ���� A Port
	char				m_strFireTalkIP[16];	// NAT Ÿ���� �м��ϱ� ���� ���Ǵ� ���� A IP
	UINT				m_nFireTalkPort;		// NAT Ÿ���� �м��ϱ� ���� ���Ǵ� ���� A Port
	BOOL				m_bReady;				// NAT Ÿ���� �м��� �غ� �Ǿ������� �÷���(������ IP�� Port ����, �޼��� ���� ������ �ڵ�)		
	
	BOOL				m_bServerReady;			// by cje 020614
	BOOL				m_bFireTalkReady;
	
	int					m_nSendtoServerCount;	// ������ ���۵� UDP ��Ŷ�� ���� ������ ���� ��� �������ϴ� count
//	int					m_nSendtoFireTalkCount;	// FireTalk II�� ���۵� UDP ��Ŷ�� ���� ������ ���� ��� �������ϴ� count
	int					m_nSendBtoServerCount;	// Server�� ���۵� UDP ��Ŷ�� ���� ������ ���� ��� �������ϴ�message B count
	NATErrorInfos			m_eErrorInfo;			// ������ ���� ����
	BOOL				m_bMMTimerSetFlag;		
	UINT				m_nMMTimerID;
	NetworkType			m_eNetworkType;			// Ȯ�ε� Network Type
	UINT				m_nPortNum;				// 

protected:
	NATAnalyzerStatus	m_Status;				// �м� �ܰ�

public:
	// ��� �Լ�
	NATAnalyzerStatus GetStatus();
	void SetStatus(NATAnalyzerStatus status);
	NATErrorInfos GetErrorInfos();
	void SetErrorInfos(NATErrorInfos err);
	void GetErrorInfosString(char* str, NATErrorInfos err = ERR_NOTHING);
	NetworkType GetNetworkType(){ return m_eNetworkType;}
	BOOL SetServersInfo(HWND hWnd, char* serverIP, UINT serverPort, char* fireTalkIP, UINT fireTalkPort);

	BOOL SetServerInfo(HWND hWnd, char* serverIP, UINT serverPort); //by cje 020614
	BOOL SetFireTalkInfo(char* fireTalkIP, UINT fireTalkPort);
	
	BOOL ExcuteAnalysis();
	void SetResendTimer();
	void KillResendTimer();
	BOOL NetworkTypeResult(NetworkType type);
};

#endif // !defined(AFX_NATANALYZER_H__FBD61870_19C6_49E3_8715_80B672BEF120__INCLUDED_)
