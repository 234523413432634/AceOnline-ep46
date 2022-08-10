#include "LogFile.h"

LogFile* g_LogFile = NULL;

LogFile::LogFile(void)
{
	InitializeCriticalSection(&m_criticalSection);
	m_hFile		= NULL;
	memset(m_szFileName, 0x00, 512);
	memset(m_szDirectory, 0x00, 512);

	m_bChangingFlagFile = false;
}


LogFile::~LogFile(void)
{
	CloseFile();
	DeleteCriticalSection(&m_criticalSection);
}


bool LogFile::OpenLogFile(TCHAR* szFileName, TCHAR* szDirectory)
{
	if(lstrcmp(szFileName, NULL) == 0
		|| lstrcmp(szDirectory, NULL) == 0
		|| lstrlen(szFileName) > 511
		|| lstrlen(szDirectory) > 511)
	{
		return false;
	}

	EnterCriticalSection(&m_criticalSection);
	if(!OpenFile(szFileName, szDirectory))
	{
		LeaveCriticalSection(&m_criticalSection);
		return false;
	}
	LeaveCriticalSection(&m_criticalSection);
	return true;
}

bool LogFile::OpenFile(TCHAR* szFileName, TCHAR* szDirectory)
{
	if(m_hFile != NULL)
	{	
		return false;
	}

	if(false == CreateDirectory(szDirectory, NULL))
	{
		// error
		int nErr = GetLastError();
		SetLastError(0);

		if(NO_ERROR != nErr
			&& ERROR_ALREADY_EXISTS != nErr)
		{
			TCHAR szTemp[256];
			wsprintf(szTemp, L"[ERROR] LogFile::OpenFile_ CreateDirectory_ error, LastError[%d] FileName[%s] Directory[%s]\r\n",
				nErr, szFileName, szDirectory);
			MessageBox(NULL, szTemp, L"ERROR", MB_OK);
			return false;
		}
	}

	memset(m_szFileName, 0x00, 512);
	lstrcpy(m_szFileName, szFileName);
	memset(m_szDirectory, 0x00, 512);
	lstrcpy(m_szDirectory, szDirectory);

	time_t		ltime;
	struct tm	today;
	TCHAR		szCurrTime[128];
	_tzset();
	time(&ltime);
	localtime_s(&today, &ltime);
	wcsftime(szCurrTime, 128, L"%Y%m%d_%H%M%S.log", &today);

	wsprintf(m_szOpenedFilePath, L"%s%s_%s", m_szDirectory, m_szFileName, szCurrTime);

	m_hFile = CreateFile(m_szOpenedFilePath, GENERIC_WRITE, FILE_SHARE_READ, NULL,
		CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if ( m_hFile == INVALID_HANDLE_VALUE)
	{
		// error
		int nErr = GetLastError();
		SetLastError(0);

		TCHAR szTemp[256];
		wsprintf(szTemp, L"[ERROR] LogFile::OpenFile_ CreateFile_ error, LastError[%d] OpenFileName[%s]\r\n",
			nErr, m_szOpenedFilePath);
		MessageBox(NULL, szTemp, L"ERROR", MB_OK);
		return false;
	}

	return true;
}


bool LogFile::CloseFile()
{
	EnterCriticalSection(&m_criticalSection);
	if(m_hFile)
	{
		DWORD dwSize = GetFileSize(m_hFile, NULL);
		CloseHandle(m_hFile);
		m_hFile = NULL;

		if(dwSize == 0)
		{
			DeleteFile(m_szOpenedFilePath);
		}
	}
	LeaveCriticalSection(&m_criticalSection);
	return true;
}

bool LogFile::ChangeFile()
{
	m_bChangingFlagFile = true;
	EnterCriticalSection(&m_criticalSection);	
	CloseFile();
	TCHAR szTempFileName[512];
	TCHAR szTempDirectory[512];
	memset(szTempFileName, 0x00, 512);
	lstrcpy(szTempFileName, m_szFileName);
	memset(szTempDirectory, 0x00, 512);
	lstrcpy(szTempDirectory, m_szDirectory);

	if(!OpenFile(szTempFileName, szTempDirectory))
	{
		LeaveCriticalSection(&m_criticalSection);
		m_bChangingFlagFile = false;
		return false;
	}	
	LeaveCriticalSection(&m_criticalSection);
	m_bChangingFlagFile = false;
	return true;
}

bool LogFile::WriteSystemLog(TCHAR* log, bool bTimeFlag)
{
	if(lstrlen(log) >= 1024 - 18
		|| (m_bChangingFlagFile == false && m_hFile == INVALID_HANDLE_VALUE)
		|| (m_bChangingFlagFile == false && m_hFile == 0))
	{	
		return false;
	}

	TCHAR szLogLineBuffer[1024];
	TCHAR szTime[128];
	time_t ltime;
	struct tm today;
	DWORD	nWritten;
	DWORD	dwFileSize = 0;

	if(bTimeFlag)
	{

		EnterCriticalSection(&m_criticalSection);

		time(&ltime);
		localtime_s(&today, &ltime);
		wcsftime(szTime, 128, L"%m-%d %H:%M:%S|", &today );
		lstrcpy(szLogLineBuffer, szTime);
		lstrcat(szLogLineBuffer, log);

		dwFileSize = GetFileSize(m_hFile, NULL);
		if(dwFileSize > 3*1024*1024)
		{
			if(ChangeFile() == false)
			{
				LeaveCriticalSection(&m_criticalSection);
				return false;
			}
		}

		DWORD nDataSize = 0;
		WORD wd = 0xFEFF;
		WriteFile(m_hFile, &wd, 2, &nDataSize, NULL);
		WriteFile(m_hFile, szLogLineBuffer, lstrlen(szLogLineBuffer) * sizeof(TCHAR), &nWritten, NULL);
		LeaveCriticalSection(&m_criticalSection);
	}
	else
	{
		szLogLineBuffer[0] = NULL;
		lstrcpy(szLogLineBuffer, L"                  ");
		lstrcat(szLogLineBuffer, log);

		EnterCriticalSection(&m_criticalSection);
		WriteFile(m_hFile, szLogLineBuffer, lstrlen(szLogLineBuffer) * sizeof(TCHAR), &nWritten, NULL);
		dwFileSize = GetFileSize(m_hFile, NULL);
		LeaveCriticalSection(&m_criticalSection);
	}
	return true;
}
