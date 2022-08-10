// SPToMPWinSocket.h: interface for the CSPToMPWinSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPTOMPWINSOCKET_H__D89CA12F_A5C7_4AB8_8C65_5879AA2B7E42__INCLUDED_)
#define AFX_SPTOMPWINSOCKET_H__D89CA12F_A5C7_4AB8_8C65_5879AA2B7E42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WinSocket.h"
#include "TickManager.h"		// 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��

// start 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
// event types
#define SPTOMP_TICK_EVENT_SESSION_TIMEOUT		0

#define SPTOMP_DELAY_TIME_SEC_TIMEOUT			2 * 60		// (1��) (���� : ��)
// end 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��

///////////////////////////////////////////////////////////////////////////////
/// \class		class CSPToMPWinSocket : public CWinSocket
///
/// \brief		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
/// \author		cmkwon
/// \version	
/// \date		2008-02-22 ~ 2008-02-22
/// \warning	
///////////////////////////////////////////////////////////////////////////////
class CPreIOCP;

class CSPToMPWinSocket : public CWinSocket, public CTickManager		// 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
{
public:
	CSPToMPWinSocket(HWND i_hWnd, DWORD i_nTickInterval = SPTOMP_TICK_INTERVAL);		// 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
	virtual ~CSPToMPWinSocket();

	void SetPreIOCP(CPreIOCP *i_pPreIOCP);

	ProcessResult Process_PP_CONNECT_OK(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PP_CONNECT_DO_CLOSE(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_ERROR(const char* pPacket, int nLength, int &nBytesUsed);
	ProcessResult Process_PAUTH_CONNECT_OK(const char* pPacket, int nLength, int &nBytesUsed);			// 2011-01-26 by hskim, ���� ���� ����
	ProcessResult Process_PAUTH_CONNECT_FAIL(const char* pPacket, int nLength, int &nBytesUsed);		// 2011-01-26 by hskim, ���� ���� ����
	ProcessResult Process_PAUTH_CONNECT_SHUTDOWN(const char* pPacket, int nLength, int &nBytesUsed);	// 2011-06-22 by hskim, �缳 ���� ����

	// start 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��
	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent);
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime);
	// end 2011-07-21 by hskim, ���� ���� ���� - ������ Timeout ó��

public:
	virtual BOOL OnRecvdPacket(LPSTR pPacket, int nLength, BYTE nSeq);

public:
	CPreIOCP		*m_pPreIOCP3;
};

#endif // !defined(AFX_SPTOMPWINSOCKET_H__D89CA12F_A5C7_4AB8_8C65_5879AA2B7E42__INCLUDED_)
