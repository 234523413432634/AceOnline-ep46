#ifndef _ATUM_THREAD_H_
#define _ATUM_THREAD_H_

/******************************************************************************
	By Kelovon
	��ӹ޾� ����Ͽ��� �ϰ�, ThreadWorker()�� �����ؼ� ����ؾ� ��.
	Thread�� �����ϱ� ���ؼ��� InitThread()�� ȣ���Ͽ��� �ϰ�,
	�� ����� ���Ŀ��� CleanThread()�� ȣ���Ͽ��� ��.
******************************************************************************/
#include <WINDOWS.H>

// refer to the site: http://www.microsoft.com/msj/0799/Win32/Win320799.aspx
#ifndef chBEGINTHREADEX
typedef unsigned (__stdcall *PTHREAD_START) (void *);

#define chBEGINTHREADEX(psa, cbStack, pfnStartAddr, \
   pvParam, fdwCreate, pdwThreadID)                 \
      ((HANDLE) _beginthreadex(                     \
         (void *) (psa),                            \
         (unsigned) (cbStack),                      \
         (PTHREAD_START) (pfnStartAddr),            \
         (void *) (pvParam),                        \
         (unsigned) (fdwCreate),                    \
         (unsigned *) (pdwThreadID)))
#endif

class CAtumThread  
{
public:
	CAtumThread();
	virtual ~CAtumThread();

	virtual DWORD ThreadWorker() = 0;

	BOOL InitThread();
	BOOL CleanThread();

	void SetShutDownFlag() { m_bShutDownFlag = TRUE; }
	BOOL GetShutDownFlag() { return m_bShutDownFlag; }

	DWORD SleepAndWaitForEvent(DWORD dwMilliseconds)
	{
		return WaitForSingleObject(m_hAtumThreadEvent, dwMilliseconds);
	}

	// not used by user
	DWORD ThreadWorkerWrapper(); 

protected:
	HANDLE			m_hWorkerThread;
	DWORD			m_dwThreadID;

private:
	BOOL			m_bShutDownFlag;
	HANDLE			m_hAtumThreadEvent;
};

#endif // _ATUM_THREAD_H_
