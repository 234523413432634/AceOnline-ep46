// AtumThread.cpp: implementation of the CAtumThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AtumThread.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DWORD WINAPI ThreadProc(LPVOID pParam)
{
	return ((CAtumThread*)pParam)->Run();
}

CAtumThread::CAtumThread()
{
	m_bRunning = FALSE;
}

HANDLE CAtumThread::CreateThread(DWORD dwCreattionFlags)
{
	m_bRunning = TRUE;
	m_hThread = ::CreateThread(NULL, 0, ThreadProc, (LPVOID)this, dwCreattionFlags, &m_dThreadID);
	return m_hThread;
}

CAtumThread::~CAtumThread()
{
	DWORD dExitCode;
	if(m_bRunning)
	{
		GetExitCodeThread(m_hThread, &dExitCode);
		TerminateThread(m_hThread, dExitCode);
	}
	CloseHandle(m_hThread);
}

VOID CAtumThread::Resume()
{
	SuspendThread(m_hThread);
}

VOID CAtumThread::Suspend()
{
	ResumeThread(m_hThread);
}

VOID CAtumThread::Priority(int pri)
{
	SetThreadPriority(m_hThread, pri);
}

DWORD CAtumThread::Run()
{
	m_bRunning = FALSE;
	return 0;
}
