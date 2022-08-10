#include "stdafx.h"
#include "AtumThread.h"

#include <process.h>

CAtumThread::CAtumThread()
{
	// �ʱ�ȭ
	m_hWorkerThread = NULL;
	m_bShutDownFlag = FALSE;
	m_dwThreadID = 0;
	m_hAtumThreadEvent = NULL;
}

CAtumThread::~CAtumThread()
{
	CleanThread();
}

DWORD WINAPI __WorkerThread(LPVOID lpParam)
{
	if (lpParam == NULL)
	{
		return 0x100;
	}

	return ((CAtumThread*)lpParam)->ThreadWorkerWrapper();
}

BOOL CAtumThread::InitThread()
{
	if (m_hWorkerThread != NULL)
	{
		return FALSE;
	}

	// �ʱ�ȭ
	m_hWorkerThread = NULL;
	m_bShutDownFlag = FALSE;
	m_dwThreadID = 0;

	// create event
	m_hAtumThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	// begin thread
	m_hWorkerThread = chBEGINTHREADEX(NULL, 0, __WorkerThread, (LPVOID)this, 0, &m_dwThreadID);
	if (m_hWorkerThread == NULL )
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CAtumThread::CleanThread()
{
	if (m_hWorkerThread == NULL)
	{
		return FALSE;
	}

	DWORD dwRet;

	// Set ShutDownFlag
	m_bShutDownFlag = TRUE;

	// set evnet
	SetEvent(m_hAtumThreadEvent);

	// Wait for threads to quit
	dwRet = WaitForSingleObject(m_hWorkerThread, INFINITE);

	if(WAIT_OBJECT_0 == dwRet)
	{
		// ��� Thread�� signaled ���°� ��, ��� ���� ����
	}
	else if(WAIT_ABANDONED_0 == dwRet)
	{
		// ��� Thread�� signaled ���°� ��, ��� �ϳ� �̻��� object�� ������
	}
	else if(WAIT_TIMEOUT == dwRet)
	{
		// ��� Thread�� signaled ���°� ���� ����, ������ Time�� ���
	}
	else
	{
		// ������ WAIT_FAILED��
		int nError = GetLastError();
	}

	// Close event handle
	if (m_hAtumThreadEvent != NULL)
	{
		CloseHandle(m_hAtumThreadEvent);
	}

	// close thread handle
	if (m_hWorkerThread != NULL)
	{
		CloseHandle(m_hWorkerThread);
	}

	// �ʱ�ȭ
	m_hWorkerThread = NULL;
	m_bShutDownFlag = FALSE;
	m_dwThreadID = 0;
	m_hAtumThreadEvent = NULL;

	return TRUE;
}

DWORD CAtumThread::ThreadWorkerWrapper()
{
	DWORD dwRet = ThreadWorker();

	return dwRet;
}