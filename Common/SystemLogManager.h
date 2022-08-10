#ifndef __SYSTEM_LOG_MANAGER_H__
#define __SYSTEM_LOG_MANAGER_H__

#include "StdAfx.h"

class CSystemLogManager
{
///////////////////////////////////////////////////////////////////////////////
// public member functions
///////////////////////////////////////////////////////////////////////////////
public:
	CSystemLogManager();
	virtual ~CSystemLogManager();

	HANDLE GetFileHandle(void){		return m_hFile;}
	BOOL InitLogManger(BOOL bUse = TRUE, char *szFileName = "SystemLog", char *szDirectory = "./SystmeLog/");
	void Clean();

	BOOL OpenFile(char *szFileName, char *szDirectory);
	BOOL CloseFile();
	BOOL ChangeFile();
	BOOL WriteSystemLog(char* log, BOOL bTimeFlag = TRUE);

	void SetServerCreateTime(char *szFileName = "ERROR");	// 2013-10-09 by jhseol, �α����Ͽ� ���� �����ð� �߰�
	
///////////////////////////////////////////////////////////////////////////////
// private member functions
///////////////////////////////////////////////////////////////////////////////
private:

///////////////////////////////////////////////////////////////////////////////
// public member variables
///////////////////////////////////////////////////////////////////////////////
public:

///////////////////////////////////////////////////////////////////////////////
// private member functions
///////////////////////////////////////////////////////////////////////////////
protected:
	CRITICAL_SECTION	m_criticalSection;
	HANDLE				m_hFile;
	BOOL				m_bChangingFlagFile;

	char				m_szFileName[512];
	char				m_szDirectory[512];
	char				m_szOpenedFilePath[1024];
	// 2013-10-09 by jhseol, �α����Ͽ� ���� �����ð� �߰�
	BYTE				m_nLogFileCreateCount;		// �α����� ���� Ƚ��
	char				m_szServerCreateTime[128];	// ���� �����ð� ����
	// end 2013-10-09 by jhseol, �α����Ͽ� ���� �����ð� �߰�
};

#endif
