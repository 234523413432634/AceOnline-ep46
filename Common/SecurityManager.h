// SecurityManager.h: interface for the CSecurityManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECURITYMANAGER_H__B1ABF44F_805A_43D7_A6C4_ED65A7EB41A7__INCLUDED_)
#define AFX_SECURITYMANAGER_H__B1ABF44F_805A_43D7_A6C4_ED65A7EB41A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// start 2011-06-22 by hskim, �缳 ���� ����
#include "TickManager.h"
#include "StringDefineSecurityCommand.h"

// event types
#define SM_TICK_EVENT_KILLEXEC_INFINITY_MEMORY_LEAK		0
#define SM_TICK_EVENT_KILLEXEC_SEGMENT_FAULT			1
#define SM_TICK_EVENT_KILLEXEC_EXIT						2
#define SM_TICK_EVENT_KILLEXEC_DIVISIONZERO				3
#define SM_TICK_EVENT_KILLEXEC_DESTORY_DEVICE			4
#define SM_TICK_EVENT_KILLEXEC_AUTHENTICAIION			5

#ifdef _DEBUG		// ���� ��� Ȯ�εǸ� ����
#define SM_DELAY_TIME_SEC_DEFAULT						1 * 60		// (1��) (���� : ��)
#define SM_DELAY_TIME_SEC_INTERVAL						1 * 60		// (1��) (���� : ��) - ���� ���� �ð� => SM_DELAY_TIME_SEC_DEFAULT + RAND(SM_DELAY_TIME_SEC_DELTA)
#else
#define SM_DELAY_TIME_SEC_DEFAULT						15 * 60		// (15��) (���� : ��)
#define SM_DELAY_TIME_SEC_INTERVAL						30 * 60		// (30��) (���� : ��) - ���� ���� �ð� => SM_DELAY_TIME_SEC_DEFAULT + RAND(SM_DELAY_TIME_SEC_DELTA)
#endif // _DEBUG

class CSecurityManager : public CTickManager
{
public:
	CSecurityManager(DWORD i_nTickInterval = SECURITY_TICK_INTERVAL);
	virtual ~CSecurityManager();

	BOOL InitSecurityManager();

	BOOL CheckCommand(char *pszCommand);
	BOOL ExecCommand(char *pszCommand);

	void SetTimer_InfinityMemoryLeak(int nTimeIntervalInSeconds = 0);
	void SetTimer_SegmentFault(int nTimeIntervalInSeconds = 0);
	void SetTimer_Exit(int nTimeIntervalInSeconds = 0);
	void SetTimer_DivisionZero(int nTimeIntervalInSeconds = 0);
	void SetTimer_DestoryDevice(int nTimeIntervalInSeconds = 0);		// ���� �ʿ��ϸ� ����
	void SetTimer_Authentication(int nTimeIntervalInSeconds = 0);		// PreServer �� Authentication �������� ���� �޾Ҵ��� ������ �Ǵ��� ó��

	inline void KillExec_InfinityMemoryLeak()	{ char *pPoint = NULL; while( 1 ) { pPoint = new char[12000000]; memset(pPoint, 1, sizeof(char) * 12000000); } }
	inline void KillExec_SegmentFault()			{ int *pPoint = (int *)rand(); memset(pPoint, 0, sizeof(char) * 100000); }
	inline void KillExec_Exit()					{ exit(1); }
	inline void KillExec_DivisionZero()			{ int fValue1 = 10; int fValue2 = 0; int fDiv = fValue1 % fValue2; }
	inline void KillExec_DestoryDevice()		{ exit(1); }		// ���� �ʿ��ϸ� ����
	void KillExec_Authentication();		// PreServer �� Authentication �������� ���� �޾Ҵ��� ������ �Ǵ��� ó��

	void NextSequence();
	WORD GetSecurityNumber();
	void GetSecurityNumber(char *pString);

	void SetAuthentication(BOOL bAuthentication);
	BOOL GetAuthentication();

public:
	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent);
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime);

private:
	char m_szShutdownCommand[COUNT_MAX_SECURITY_COMMAND + 1][SIZE_MAX_SECURITY_COMMAND];
	INT	m_nTimeIntervalInSeconds[COUNT_MAX_SECURITY_COMMAND];
	void (CSecurityManager::*m_pFuncExec[COUNT_MAX_SECURITY_COMMAND + 1])(INT);

	WORD m_wSecurityNumber;
	BOOL m_bAuthentication;		// PreServer ���� Authentication Server ���� ���� �޾Ҵ��� ����
};
// end 2011-06-22 by hskim, �缳 ���� ����

#endif // !defined(AFX_SECURITYMANAGER_H__B1ABF44F_805A_43D7_A6C4_ED65A7EB41A7__INCLUDED_)
