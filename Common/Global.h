#ifndef _GROBAL_VARIABEL_H_
#define _GROBAL_VARIABEL_H_

#include "SystemLogManager.h"

class CGlobal;


///////////////////////////////////////////////////////////////////////////////
// Global Variable
///////////////////////////////////////////////////////////////////////////////
extern CGlobal *			g_pGlobal;


//////////////////////////////////////////////////////////////////////////
// Global Function
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// ������ �޼��� ���ν���

static BOOL bFirstChecked = FALSE;	// 2014-01-02 by bckim, �������ý��� ����(���μ������� �ѹ����� üũ)

///////////////////////////////////////////////////////////////////////////////
/// \class		CGlobal
///
/// \brief		���� ������ �����ϱ� ���� Ŭ����
/// \author		cmkwon
/// \version	
/// \date		2004-03-18 ~ 2004-03-18
/// \warning	��ü�� �ϳ��� �����ؾ���.
///////////////////////////////////////////////////////////////////////////////
class CGlobal
{
public:
	CGlobal();
	virtual ~CGlobal();

	///////////////////////////////////////////////////////////////////////////
	// Property
	CSystemLogManager * GetSystemLogManagerPtr(void);
	
	virtual BOOL InitGlobal(char * i_szServerName);
	BOOL CreateDuplicateRun(char * i_szServerName);		// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����

	///////////////////////////////////////////////////////////////////////////
	// public Method
	static BOOL CheckWriteLog(char *szLogMsg);		// 2011-06-22 by hskim, �缳 ���� ����
	static BOOL WriteSystemLog(char *szLogMsg, BOOL bTimeHeaderFlag = TRUE);
	static BOOL WriteSystemLogEX(BOOL bPrintDBGOUT, const char* pFormat, ...);

protected:		

	HANDLE							m_hMutexMonoInstance;

	//////////////////////////////////////////////////////////////////////////
	// �α� ���� ��� ����
	static CSystemLogManager 		ms_SystemLogManager;			// ��� �������� �ý��� ���� �α׸� �����ϱ� ���� �������

};


#endif	// _GROBAL_VARIABEL_H_endif