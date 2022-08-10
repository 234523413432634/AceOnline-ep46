#include "Stdafx.h"
#include "global.h"

CGlobal *			g_pGlobal = NULL;


CSystemLogManager	CGlobal::ms_SystemLogManager;
///////////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////////
CGlobal::CGlobal()
{
	m_hMutexMonoInstance = NULL;
	if(g_pGlobal)
	{
		return;
	}

	g_pGlobal = this;
}

CGlobal::~CGlobal()
{
	if(m_hMutexMonoInstance)
	{
		::CloseHandle(m_hMutexMonoInstance);
		m_hMutexMonoInstance = NULL;
	}
}


///////////////////////////////////////////////////////////////////////////////
// Property
///////////////////////////////////////////////////////////////////////////////
CSystemLogManager * CGlobal::GetSystemLogManagerPtr(void)
{
	return &ms_SystemLogManager;
}


///////////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////////

BOOL CGlobal::InitGlobal(char * i_szServerName)
{
#ifdef S_DISABLE_ALONE_RUN_MODE_HSKIM
	// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����
#else
	if(m_hMutexMonoInstance)
	{
		return FALSE;
	}

	m_hMutexMonoInstance = CreateMutex(NULL, TRUE, i_szServerName);
	if(NULL == m_hMutexMonoInstance)
	{
		MessageBox(NULL, "CreateMutex Error", i_szServerName, MB_OK);
		return FALSE;
	}

	if(ERROR_ALREADY_EXISTS == ::GetLastError())
	{
		MessageBox(NULL, "ERROR : \nApplication is running already...", i_szServerName, MB_OK);
		return FALSE;
	}
#endif

	return TRUE;
}

// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����
BOOL CGlobal::CreateDuplicateRun(char * i_szServerName)
{
	SetWindowText(NULL, i_szServerName);

#ifdef S_DISABLE_ALONE_RUN_MODE_HSKIM
	if( FALSE == bFirstChecked )	// 2014-01-02 by bckim, �������ý��� ����(���μ������� �ѹ����� üũ)
	{
		bFirstChecked = TRUE;		// 2014-01-02 by bckim, �������ý��� ����(���μ������� �ѹ����� üũ)
		
	if(m_hMutexMonoInstance)
	{
		return FALSE;
	}

	m_hMutexMonoInstance = CreateMutex(NULL, TRUE, i_szServerName);
	if(NULL == m_hMutexMonoInstance)
	{
		return FALSE;
	}

	if(ERROR_ALREADY_EXISTS == ::GetLastError())
	{
		return FALSE;
		}
	}
#endif

	return TRUE;
}
// end 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����

// start 2011-06-22 by hskim, �缳 ���� ����
BOOL CGlobal::CheckWriteLog(char *szLogMsg)
{
	if( strlen(szLogMsg) == strlen(STRCMD_CS_COMMAND_SERVERINFO) && 0 == stricmp(szLogMsg , STRCMD_CS_COMMAND_SERVERINFO) )
	{
		return FALSE;
	}
	
	return TRUE;
}
// end 2011-06-22 by hskim, �缳 ���� ����

BOOL CGlobal::WriteSystemLog(char *szLogMsg, BOOL bTimeHeaderFlag)
{
	return ms_SystemLogManager.WriteSystemLog(szLogMsg, bTimeHeaderFlag);
}

BOOL CGlobal::WriteSystemLogEX(BOOL bPrintDBGOUT, const char* pFormat, ...)
{
	char szLogMsg[1024];
	va_list args;
	va_start(args, pFormat);
	vsprintf(szLogMsg, pFormat, args);

	if (bPrintDBGOUT)
	{
		DBGOUT(szLogMsg);
	}

	return ms_SystemLogManager.WriteSystemLog(szLogMsg, TRUE);
}
