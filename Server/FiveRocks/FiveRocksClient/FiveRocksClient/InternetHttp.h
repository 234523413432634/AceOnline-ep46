#pragma once

#include <windows.h>
#include <WinInet.h>

#pragma comment( lib, "WinInet.lib")

#define INTERNET_HTTP_MESSAGE_MAX_LENGTH	1024

class InternetHttp
{
public:
	InternetHttp(void);
	virtual ~InternetHttp(void);

	CRITICAL_SECTION	m_criticalSection;

	HINTERNET		m_Session;
	HINTERNET		m_Connect;
	HINTERNET		m_Request;

	TCHAR*			m_ServerName;
	TCHAR*			m_ServerObject;
	TCHAR*			m_ServerContentType;

	char*			m_ServerResult;
public:
	DWORD Init(TCHAR* ServerName, TCHAR* ServerObject, TCHAR* ServerContentType);

	DWORD OpenHttp();					//Success : NO_ERROR
	DWORD ConnectHttp();				//Success : NO_ERROR
	DWORD OpenRequestHttp();			//Success : NO_ERROR
	DWORD SendHttp(char* HttpPostData);	//Success : NO_ERROR

	char* GetServerResult() { return m_ServerResult; }
	void deleteServerResult() {if(m_ServerResult) { free(m_ServerResult); m_ServerResult = NULL;}}

	DWORD HttpCloseHandle(HINTERNET& Internet);
};

extern InternetHttp* g_InternetHttp;