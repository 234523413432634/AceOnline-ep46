#pragma once

#include <windows.h>
#include <tchar.h>
#include <time.h>

class LogFile
{
public:
	LogFile(void);
	~LogFile(void);

private:
	CRITICAL_SECTION	m_criticalSection;
	HANDLE				m_hFile;
	bool				m_bChangingFlagFile;

	TCHAR				m_szFileName[512];
	TCHAR				m_szDirectory[512];
	TCHAR				m_szOpenedFilePath[1024];
public:

	bool OpenLogFile(TCHAR* szFileName, TCHAR* szDirectory);
	bool OpenFile(TCHAR* szFileName, TCHAR* szDirectory);
	bool CloseFile();
	bool ChangeFile();
	bool WriteSystemLog(TCHAR* log, bool bTimeFlag = true);
};

extern LogFile* g_LogFile;