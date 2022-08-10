// SecurityManager.cpp: implementation of the CSecurityManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SecurityManager.h"

#ifdef _ATUM_FIELD_SERVER
#include "FieldGlobal.h"
#include "PreWinSocket.h"
#endif	// _ATUM_FIELD_SERVER

#ifdef _ATUM_IM_SERVER
#include "IMGlobal.h"
#include "PreIMWinSocket.h"
#endif	// _ATUM_IM_SERVER

#ifdef _ATUM_PRE_SERVER
#include "PreGlobal.h"
#include "SPToMPWinSocket.h"
#endif // _ATUM_PRE_SERVER

// start 2011-06-22 by hskim, �缳 ���� ����

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSecurityManager::CSecurityManager(DWORD i_nTickInterval /*= SECURITY_TICK_INTERVAL*/)
: CTickManager(i_nTickInterval)
{
	int iCount = 0;

	m_bAuthentication = FALSE;

	ZeroMemory(m_szShutdownCommand, sizeof(m_szShutdownCommand));
	ZeroMemory(m_pFuncExec, sizeof(m_pFuncExec));

	srand(time(NULL));
	m_wSecurityNumber = rand();

	ZeroMemory(m_nTimeIntervalInSeconds, sizeof(m_nTimeIntervalInSeconds));

#ifdef _ATUM_FIELD_SERVER
	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_NOW_FIELD_01,		STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_Exit;
	m_nTimeIntervalInSeconds[iCount] = 0;
	iCount++;

	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_AFTER_FIELD_01,	STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_InfinityMemoryLeak;
	m_nTimeIntervalInSeconds[iCount] = SM_DELAY_TIME_SEC_INTERVAL;
	iCount++;

	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_AUTH_FIELD_01,		STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_Authentication;
	m_nTimeIntervalInSeconds[iCount] = SM_DELAY_TIME_SEC_INTERVAL;
	iCount++;
#endif	// _ATUM_FIELD_SERVER

#ifdef _ATUM_IM_SERVER
	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_NOW_IM_01,		STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_DivisionZero;
	m_nTimeIntervalInSeconds[iCount] = 0;
	iCount++;

	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_AFTER_IM_01,	STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_InfinityMemoryLeak;
	m_nTimeIntervalInSeconds[iCount] = SM_DELAY_TIME_SEC_INTERVAL;
	iCount++;

	XOR::XORDecrypt(m_szShutdownCommand[iCount], PRIVATE_SERVER_SHUTDOWN_COMMAND_AUTH_IM_01,	STR_XOR_KEY_STRING_SECURITY_COMMAND);
	m_pFuncExec[iCount] = &CSecurityManager::SetTimer_Authentication;
	m_nTimeIntervalInSeconds[iCount] = SM_DELAY_TIME_SEC_INTERVAL;
	iCount++;
#endif	// _ATUM_FIELD_SERVER

	// �ǾƷ����� ������ NULL ó���� �迭�� �־���Ѵ�... by hskim 2011-07-05
	// ������ ���� ���� ���� ����
}

CSecurityManager::~CSecurityManager()
{
}

BOOL CSecurityManager::InitSecurityManager()
{
#ifdef SC_SECURITY_COMMAND_HSKIM
	CTickManager::InitTickManager();
#endif // SC_SECURITY_COMMAND_HSKIM

	return TRUE;
}

BOOL CSecurityManager::CheckCommand(char *pszCommand)
{
	int iCount = 0;
	char szXorKey[SIZE_MAX_SECURITY_COMMAND] = { 0, };
	char szDecryptCommand[SIZE_MAX_SECURITY_COMMAND] = { 0, };

	GetSecurityNumber(szXorKey);		// Key �о����

	szDecryptCommand[0] = pszCommand[0];		// '/' ����
	XOR::XORDecrypt(&szDecryptCommand[1], &pszCommand[1], szXorKey);		// ������ ���ڵ� ó��

	// 1�� �˻� => Ŀ�ǵ� ��

	while( 1 )
	{
		if( NULL == m_szShutdownCommand[iCount][0] ) break;

		if( 0 == stricmp(szDecryptCommand , m_szShutdownCommand[iCount] ) )
		{
			return TRUE;
		}

		iCount++;
	}

	// 2�� �˻� => ����� �Ǽ� ����
	// ���� String ���̰� 50 �Ѱ� A~F �� 0~9 ���� ���� ���ڸ� �� ���� Ű �Է� �Ǽ��Ѱ����� ó���ؼ� OK ó��

	int iLength = strlen(pszCommand);
	if( SIZE_THRESHOLD_SECURITY_COMMAND < iLength )
	{
		for(int a=1; a<iLength; a++)
		{
			if( (pszCommand[a] >= 'A' && pszCommand[a] <= 'F') || (pszCommand[a] >= '0' && pszCommand[a] <= '9') ) continue;

			return FALSE;
		}

		return TRUE;		// Ŀ�ǵ�� ��ġ������ ������ ��� Ŀ�ǵ��� �Ǽ��� �����ϰ� �α׸� ������ �ʴ´�.
	}

	return FALSE;
}

BOOL CSecurityManager::ExecCommand(char *pszCommand)
{
	int iCount = 0;
	char szXorKey[SIZE_MAX_SECURITY_COMMAND] = { 0, };
	char szDecryptCommand[SIZE_MAX_SECURITY_COMMAND] = { 0, };

	GetSecurityNumber(szXorKey);		// Key �о����

	szDecryptCommand[0] = pszCommand[0];		// '/' ����
	XOR::XORDecrypt(&szDecryptCommand[1], &pszCommand[1], szXorKey);		// ������ ���ڵ� ó��

#ifdef SC_SECURITY_COMMAND_HSKIM
	while( 1 )
	{
		if( NULL == m_szShutdownCommand[iCount][0] ) break;

		if( 0 == stricmp(szDecryptCommand , m_szShutdownCommand[iCount] ) )
		{
#ifdef _ATUM_FIELD_SERVER
			g_pFieldGlobal->WriteSystemLogEX(TRUE, STRMSG_AUTHENTICATION_FIELDSERVER_SHUTDOWN_LOG, 61);		// �α� ���
#endif // _ATUM_FIELD_SERVER

#ifdef _ATUM_IM_SERVER
			g_pIMGlobal->WriteSystemLogEX(TRUE, STRMSG_AUTHENTICATION_IMSERVER_SHUTDOWN_LOG, 6021);		// �α� ���
#endif //_ATUM_IM_SERVER

			(this->*m_pFuncExec[iCount])(m_nTimeIntervalInSeconds[iCount]);		// ����

			return TRUE;
		}

		iCount++;
	}
#endif // SC_SECURITY_COMMAND_HSKIM

	return FALSE;
}

void CSecurityManager::SetTimer_InfinityMemoryLeak(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;

	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);

	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_INFINITY_MEMORY_LEAK, nTimeInterval);
}

void CSecurityManager::SetTimer_SegmentFault(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;
	
	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);
	
	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_SEGMENT_FAULT, nTimeInterval);
}

void CSecurityManager::SetTimer_Exit(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;
	
	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);
	
	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_EXIT, nTimeInterval);
}

void CSecurityManager::SetTimer_DivisionZero(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;
	
	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);
	
	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_DIVISIONZERO, nTimeInterval);
}

void CSecurityManager::SetTimer_DestoryDevice(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;
	
	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);
	
	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_DESTORY_DEVICE, nTimeInterval);
}

void CSecurityManager::SetTimer_Authentication(int nTimeIntervalInSeconds /* = 0 */)
{
	INT nTimeInterval = 0;
	
	if( 0 != nTimeIntervalInSeconds ) nTimeInterval = SM_DELAY_TIME_SEC_DEFAULT + RANDI(1, SM_DELAY_TIME_SEC_INTERVAL);
	
	InsertTickEvent(SM_TICK_EVENT_KILLEXEC_AUTHENTICAIION, nTimeInterval);
}

void CSecurityManager::KillExec_Authentication()
{
#ifdef _ATUM_FIELD_SERVER
	INIT_MSG_WITH_BUFFER(MSG_FP_AUTHENTICATION_SHUTDOWN, T_FP_AUTHENTICATION_SHUTDOWN, pSendMsg, SendBuff);
	pSendMsg->bFlag = TRUE;
	g_pFieldGlobal->GetField2PreWinSocket()->Write(SendBuff, MSG_SIZE(MSG_FP_AUTHENTICATION_SHUTDOWN));
#endif // _ATUM_FIELD_SERVER
	
#ifdef _ATUM_IM_SERVER
	INIT_MSG_WITH_BUFFER(MSG_IP_AUTHENTICATION_SHUTDOWN, T_IP_AUTHENTICATION_SHUTDOWN, pSendMsg, SendBuff);
	pSendMsg->bFlag = TRUE;
	g_pIMGlobal->GetIM2PreWinSocket()->Write(SendBuff, MSG_SIZE(MSG_IP_AUTHENTICATION_SHUTDOWN));
#endif //_ATUM_IM_SERVER
}

void CSecurityManager::NextSequence()
{
	m_wSecurityNumber = m_wSecurityNumber + rand();
}

WORD CSecurityManager::GetSecurityNumber()
{
	return m_wSecurityNumber;
}

void CSecurityManager::GetSecurityNumber(char *pString)
{
	itoa(m_wSecurityNumber, pString, 10);
}

void CSecurityManager::SetAuthentication(BOOL bAuthentication)
{
	m_bAuthentication = bAuthentication;
}

BOOL CSecurityManager::GetAuthentication()
{
	return m_bAuthentication;
}

void CSecurityManager::DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent)
{
#ifdef _DEBUG
	DBGOUT(STRMSG_S_F2NOTIFY_0141, pDateTime->GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
#endif

	switch (pTickEvent->TickEventType)
	{
	case SM_TICK_EVENT_KILLEXEC_INFINITY_MEMORY_LEAK:
		{
			KillExec_InfinityMemoryLeak();
		}
		break;

	case SM_TICK_EVENT_KILLEXEC_SEGMENT_FAULT:
		{
			KillExec_SegmentFault();
		}
		break;

	case SM_TICK_EVENT_KILLEXEC_EXIT:
		{
			KillExec_Exit();
		}
		break;

	case SM_TICK_EVENT_KILLEXEC_DIVISIONZERO:
		{
			KillExec_DivisionZero();
		}
		break;

	case SM_TICK_EVENT_KILLEXEC_DESTORY_DEVICE:
		{
			KillExec_DestoryDevice();
		}
		break;

	case SM_TICK_EVENT_KILLEXEC_AUTHENTICAIION:
		{
			KillExec_Authentication();
		}
		break;

	default:
		break;
	}

	return;
}

void CSecurityManager::DoEveryTickWork(ATUM_DATE_TIME *pDateTime)
{
}

void CSecurityManager::DoDailyWork(ATUM_DATE_TIME *pDateTime)
{	
#ifdef _ATUM_PRE_SERVER
	////////////////////////////////////////////////////////////
	// 2013-03-04 by hskim, 00 �ÿ� �ٽ� Ȯ���ϴ� ��� ���� 

	/*
	static BOOL bFirst = FALSE;
	
	if( TRUE != bFirst )
	{
		bFirst = TRUE;
		
		return ;
	}
	
	SetAuthentication(FALSE);

	if( TRUE == g_pPreGlobal->m_pSPToMPWinsoc->IsConnected() )
	{
		g_pPreGlobal->SendToAuthenticationServer();
	}
	else 
	{
		if( FALSE == g_pPreGlobal->connectBySPToMPWinSoc(MasangPreServerIP, MasangPreServerPort) )
		{
			g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] connectBySPToMPWinSoc_ error !! IP(%s) Port(%d)", MasangPreServerIP, MasangPreServerPort);
		}
	}
	*/

	// end 2013-03-04 by hskim, 00 �ÿ� �ٽ� Ȯ���ϴ� ��� ���� 
	////////////////////////////////////////////////////////////

#endif // _ATUM_PRE_SERVER
}

void CSecurityManager::DoHourlyWork(ATUM_DATE_TIME *pDateTime)
{
	NextSequence();		// 1 �ð��� �ѹ��� ������ ��ȣ�� �ٲ۴�.
}

void CSecurityManager::DoMinutelyWork(ATUM_DATE_TIME *pDateTime)
{
}

void CSecurityManager::DoSecondlyWork(ATUM_DATE_TIME *pDateTime)
{
}

void CSecurityManager::DoMonthlyWork(ATUM_DATE_TIME *pDateTime)
{
}

// end 2011-06-22 by hskim, �缳 ���� ����






























