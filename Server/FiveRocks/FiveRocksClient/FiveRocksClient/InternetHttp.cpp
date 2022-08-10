#include "InternetHttp.h"

InternetHttp* g_InternetHttp = NULL;

InternetHttp::InternetHttp(void)
{
	InitializeCriticalSection(&m_criticalSection);

	m_Session = NULL;
	m_Connect = NULL;
	m_Request = NULL;

	m_ServerName = NULL;
	m_ServerObject = NULL;
	m_ServerContentType = NULL;

	m_ServerResult = NULL;
}

InternetHttp::~InternetHttp(void)
{
	if (m_ServerName)
	{
		delete m_ServerName;
		m_ServerName = NULL;
	}
	if (m_ServerObject)
	{
		delete[] m_ServerObject;
		m_ServerObject = NULL;
	}
	if(m_ServerContentType)
	{
		delete[] m_ServerContentType;
		m_ServerContentType = NULL;
	}
	deleteServerResult();
	DeleteCriticalSection(&m_criticalSection);
}

DWORD InternetHttp::Init(TCHAR* ServerName, TCHAR* ServerObject, TCHAR* ServerContentType)
{
	int Length = 0;

	Length = lstrlen(ServerName);
	m_ServerName = new TCHAR[Length+1];
	lstrcpy(m_ServerName,ServerName);

	Length = lstrlen(ServerObject);
	m_ServerObject = new TCHAR[Length+1];
	lstrcpy(m_ServerObject,ServerObject);

	Length = lstrlen(ServerContentType);
	m_ServerContentType = new TCHAR[Length+1];
	lstrcpy(m_ServerContentType,ServerContentType);

	return NO_ERROR;
}

DWORD InternetHttp::OpenHttp()
{
	m_Session = InternetOpen(TEXT("Ace FiveRocks"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0x00000000);
	if (!m_Session)
	{
		return GetLastError();
	}
	return NO_ERROR;
}

DWORD InternetHttp::ConnectHttp()
{
	if(!m_Session) return ERROR_INVALID_DATA;

	EnterCriticalSection(&m_criticalSection);
	m_Connect = InternetConnect(m_Session, m_ServerName , INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);
	if (!m_Connect)
	{
		LeaveCriticalSection(&m_criticalSection);
		return GetLastError();
	}
	LeaveCriticalSection(&m_criticalSection);
	return NO_ERROR;
}

DWORD InternetHttp::OpenRequestHttp()
{
	if(!m_Connect) return ERROR_INVALID_DATA;

	EnterCriticalSection(&m_criticalSection);
	m_Request = HttpOpenRequest(m_Connect, TEXT("POST"), m_ServerObject, NULL, NULL, NULL, NULL, NULL);
	if (!m_Request)
	{
		DWORD Err = GetLastError();
		HttpCloseHandle(m_Connect);
		LeaveCriticalSection(&m_criticalSection);
		return Err;
	}
	LeaveCriticalSection(&m_criticalSection);
	return NO_ERROR;
}

DWORD InternetHttp::SendHttp(char* HttpPostData)
{
	BOOL bResult;
	DWORD ErrorCode = 0;
	EnterCriticalSection(&m_criticalSection);
	bResult = HttpSendRequest( m_Request, 
		m_ServerContentType,lstrlen(m_ServerContentType), 
		HttpPostData, 
		strlen(HttpPostData));
	if (bResult == FALSE)
	{
		ErrorCode = GetLastError();
		HttpCloseHandle(m_Connect);
		LeaveCriticalSection(&m_criticalSection);
		return ErrorCode;
	}

	DWORD dwSize = 0;
	DWORD dwRead = 0;

	BOOL bQuery = InternetQueryDataAvailable( m_Request, &dwSize, 0, 0 );
	deleteServerResult();
	if ( bQuery && dwSize > 0 )
	{
		DWORD dwTotal = 0;
		m_ServerResult = (char*)malloc( dwTotal + dwSize + 1 );
		while ( m_ServerResult && dwSize )
		{
			DWORD dwRead = 0;
			InternetReadFile( m_Request, m_ServerResult+dwTotal, dwSize, &dwRead );
			dwTotal += dwRead;
			m_ServerResult[dwTotal] = NULL;
			InternetQueryDataAvailable( m_Request, &dwSize, 0, 0 );
			if ( dwSize > 0 )
			{
				m_ServerResult = (char*)realloc( m_ServerResult, dwTotal + dwSize+1 );
			}
		}
	}
	ErrorCode = HttpCloseHandle(m_Request);
	if(ErrorCode) 
	{
		LeaveCriticalSection(&m_criticalSection);
		return ErrorCode;
	}

	ErrorCode = HttpCloseHandle(m_Connect);
	if(ErrorCode) 
	{
		LeaveCriticalSection(&m_criticalSection);
		return ErrorCode;
	}

	LeaveCriticalSection(&m_criticalSection);
	return NO_ERROR;
}
DWORD InternetHttp::HttpCloseHandle(HINTERNET& Internet)
{
	if (Internet)
	{
		if (InternetCloseHandle(Internet) == FALSE)
		{
			return GetLastError();
		}
		Internet = NULL;
	}

	return NO_ERROR;
}