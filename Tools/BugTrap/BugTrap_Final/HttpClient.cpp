#include "StdAfx.h"
#include "HttpClient.h"
#include <assert.h>
#include <strsafe.h>

// ����, �� class�� ����ϴ� ��⿡�� ���Ƿ� ����ϴ� DEBUGLOG�� �ִٸ�,
// stdafx.h�� DEBUGLOGHC�� �����Ͻÿ�.
// ��) #define DEBUGLOGHC(...) _tprintf(__VA_ARGS__);_tprintf(TEXT("\r\n"));

#ifndef DEBUGLOGHC
#define DEBUGLOGHC(...) ((void)(__VA_ARGS__))
#endif // DEBUGLOGHC

CHttpClient::CHttpClient(void)
{
	m_hInternet					= NULL;
	m_hConnection				= NULL;

	m_pstArrPostContext			= NULL;
	m_nArrPostContextAllocSize	= 0;
	m_nArrPostContextSize		= 0;

	m_dwCodePage				= CP_ACP;

	m_nReSendCount				= 0;

	::InitializeCriticalSection(&m_cs);
}

CHttpClient::~CHttpClient(void)
{
	CloseSession();
	ClearPostContext();

	::DeleteCriticalSection(&m_cs);
}

DWORD CHttpClient::CreateSession(IN LPTSTR lpszAgent, IN LPCTSTR lpszServer, IN DWORD dwPort, const wchar_t* UserName, const wchar_t* UserPass)
{
	DWORD dwRtnValue = ERROR_SUCCESS;

	if ((NULL == m_hInternet) && (NULL == m_hConnection))
	{
		// good
	}
	else
	{
		// bad
		dwRtnValue = ERROR_ALREADY_EXISTS;
		DEBUGLOGHC(TEXT("[ERROR] Fail to CreateSession, Already"));
		printf(("[ERROR] Fail to CreateSession, Already"));
		assert(FALSE);
		goto FINAL;
	}

	if ((NULL == lpszServer) || (NULL == lpszServer))
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		assert(FALSE);
		goto FINAL;
	}

	m_hInternet = ::InternetOpen(lpszAgent, 
		INTERNET_OPEN_TYPE_PRECONFIG, 
		TEXT(""), 
		TEXT(""), 
		0);
	if (NULL == m_hInternet)
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to InternetOpen, %s, %d"), lpszAgent, dwRtnValue);
		printf(("[ERROR] Fail to InternetOpen, %s, %d"), lpszAgent, dwRtnValue);
		assert(FALSE);
		goto FINAL;
	}

	m_hConnection = ::InternetConnect(m_hInternet, 
		lpszServer, 
		(INTERNET_PORT)dwPort, 
		(LPCWSTR)UserName, 
		(LPCWSTR)UserPass, 
		INTERNET_SERVICE_HTTP, 
		INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_CACHE_WRITE, 
		NULL);
	if (NULL == m_hConnection)
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to InternetConnect, %s, %d, %d"), lpszServer, dwPort, dwRtnValue);
		printf(("[ERROR] Fail to InternetConnect, %s, %d, %d"), lpszServer, dwPort, dwRtnValue);
		assert(FALSE);
		::InternetCloseHandle(m_hInternet);
		m_hInternet = NULL;
		goto FINAL;
	}

	dwRtnValue = ::InternetAttemptConnect(0);
	if (ERROR_SUCCESS != dwRtnValue)
	{
		DEBUGLOGHC(TEXT("[ERROR] Fail to internetAttamptConnect, %d"), dwRtnValue);
		printf(("[ERROR] Fail to internetAttamptConnect, %d"), dwRtnValue);
		assert(FALSE);
		::InternetCloseHandle(m_hConnection);
		::InternetCloseHandle(m_hInternet);
		m_hConnection = NULL;
		m_hInternet   = NULL;
	}

	// ������� �Դٸ� ����
	dwRtnValue = ERROR_SUCCESS;

FINAL:
	return dwRtnValue;
}

VOID CHttpClient::CloseSession(VOID)
{
	if (NULL != m_hInternet)
	{
		::InternetCloseHandle(m_hInternet);
		m_hInternet = NULL;
	}

	if (NULL != m_hConnection)
	{
		::InternetCloseHandle(m_hConnection);
		m_hConnection = NULL;
	}
}

VOID CHttpClient::ClearPostContext(VOID)
{
	INT i = 0;

	if (NULL != m_pstArrPostContext)
	{
		for (i=0; i<m_nArrPostContextAllocSize; i++)
		{
			if (NULL != &m_pstArrPostContext[i])
			{
				if (NULL != m_pstArrPostContext[i].lpszNameA)
				{
					delete [] m_pstArrPostContext[i].lpszNameA;
					m_pstArrPostContext[i].lpszNameA = NULL;
				}

				if (NULL != m_pstArrPostContext[i].lpszValueA)
				{
					delete [] m_pstArrPostContext[i].lpszValueA;
					m_pstArrPostContext[i].lpszValueA = NULL;
				}

				if (NULL != m_pstArrPostContext[i].lpszNameValueA)
				{
					delete [] m_pstArrPostContext[i].lpszNameValueA;
					m_pstArrPostContext[i].lpszNameValueA = NULL;
				}

				if (NULL != m_pstArrPostContext[i].lpszFilenameValueA)
				{
					delete [] m_pstArrPostContext[i].lpszFilenameValueA;
					m_pstArrPostContext[i].lpszFilenameValueA = NULL;
				}

				if (NULL != m_pstArrPostContext[i].lpszLocalFilePath)
				{
					delete [] m_pstArrPostContext[i].lpszLocalFilePath;
					m_pstArrPostContext[i].lpszLocalFilePath = NULL;
				}
			}
		}

		delete [] m_pstArrPostContext;
		m_pstArrPostContext			= NULL;
		m_nArrPostContextAllocSize	= 0;
		m_nArrPostContextSize		= 0;
	}
}

CHttpClient::LPST_POST_CONTEXT CHttpClient::AllocPostContext(VOID)
{
	LPST_POST_CONTEXT pstRtnValue = NULL;
	LPST_POST_CONTEXT pstRealloc  = NULL;

	// Ȥ�ó� MultiThread���� Alloc�Ҷ��� ����Ͽ�,
	// ���� ������ ���´�.
	::EnterCriticalSection(&m_cs);

	if (m_nArrPostContextSize + 1 > m_nArrPostContextAllocSize)
	{
		// realloc �ʿ�
		pstRealloc = new ST_POST_CONTEXT[m_nArrPostContextAllocSize + 8];
		if (NULL == pstRealloc)
		{
			pstRtnValue = NULL;
			goto FINAL;
		}

		// Array�� 4��ŭ Ŀ����. (Internet���� Post���� ���� ���� �ʰڴٴ� ����)
		ZeroMemory(pstRealloc, sizeof(ST_POST_CONTEXT)*(m_nArrPostContextAllocSize + 4));

		// �޸𸮸� ����~!!!
		CopyMemory(pstRealloc, m_pstArrPostContext, sizeof(ST_POST_CONTEXT)*m_nArrPostContextAllocSize);

		// ������ ����
		delete [] m_pstArrPostContext;

		// ���� commit
		m_nArrPostContextAllocSize += 4;
		m_pstArrPostContext = pstRealloc;
	}

	// �Ҵ�� �迭 Item �ϳ��� �ѱ��.
	pstRtnValue = &m_pstArrPostContext[m_nArrPostContextSize];

	// �ϳ��� �߰��Ǿ���.
	m_nArrPostContextSize++;

FINAL:

	::LeaveCriticalSection(&m_cs);
	return pstRtnValue;
}

DWORD CHttpClient::AddPostParam(IN LPCTSTR lpszName, IN LPCTSTR lpszValue)
{
	DWORD				dwRtnValue	= ERROR_SUCCESS;
	LPST_POST_CONTEXT	pstAlloc	= NULL;

	if ((NULL == lpszName) || (NULL == lpszValue))
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		assert(FALSE);
		goto FINAL;
	}

	pstAlloc = AllocPostContext();
	if (NULL == pstAlloc)
	{
		dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
		assert(FALSE);
		goto FINAL;
	}

	pstAlloc->lpszNameA		= CHttpClient::NewAllocAnsi(lpszName, m_dwCodePage);
	pstAlloc->lpszValueA	= CHttpClient::NewAllocAnsi(lpszValue, m_dwCodePage);
	if ((NULL == pstAlloc->lpszNameA) ||
		(NULL == pstAlloc->lpszValueA))
	{
		dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
		assert(FALSE);
		goto FINAL;
	}

	// ������� �Դٸ� ����
	dwRtnValue = ERROR_SUCCESS;

FINAL:
	return dwRtnValue;
}

DWORD CHttpClient::AddPostFile(IN LPCTSTR lpszNameValue, IN LPCTSTR lpszFilenameValue, IN LPCTSTR lpszLocalFilePath)
{
	DWORD				dwRtnValue			= ERROR_SUCCESS;
	LPST_POST_CONTEXT	pstAlloc			= NULL;
	size_t				dwCchLocalFilePath	= 0;
	DWORD				dwCbFileSize		= 0;
	HANDLE				hFile				= INVALID_HANDLE_VALUE;

	if ((NULL == lpszNameValue) || (NULL == lpszFilenameValue) || (NULL == lpszLocalFilePath))
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		assert(FALSE);
		goto FINAL;
	}

	dwCchLocalFilePath = _tcslen(lpszLocalFilePath) + 1;

	if (INVALID_FILE_ATTRIBUTES == ::GetFileAttributes(lpszLocalFilePath))
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to Get File, %d, %s"), dwRtnValue, lpszLocalFilePath);
		printf(("[ERROR] Fail to Get File, %d, %s"), dwRtnValue, lpszLocalFilePath);
			if(ERROR_SUCCESS == dwRtnValue)
			{
				dwRtnValue = ERROR_FILE_NOT_FOUND;
				goto FINAL;
			}
	}
	else
	{
		// ���� ũ�⸦ ���Ѵ�.
		hFile = ::CreateFile(lpszLocalFilePath, 
			GENERIC_READ, 
			0, 
			NULL, 
			OPEN_EXISTING, 
			FILE_ATTRIBUTE_NORMAL, 
			NULL);
		if (INVALID_HANDLE_VALUE == hFile)
		{
			dwRtnValue = ::GetLastError();
			DEBUGLOGHC(TEXT("[ERROR] Fail to CreateFile, %d, %s"), dwRtnValue, lpszLocalFilePath);
			printf(("[ERROR] Fail to CreateFile, %d, %s"), dwRtnValue, lpszLocalFilePath);
			assert(FALSE);
			goto FINAL;
		}

		dwCbFileSize = ::GetFileSize(hFile, NULL);
		::CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;

		if (0 == dwCbFileSize)
		{
			dwRtnValue = ERROR_EMPTY;
			DEBUGLOGHC(TEXT("[ERROR] Fail to Empty File, %s"), lpszLocalFilePath);
			printf(("[ERROR] Fail to Empty File, %s"), lpszLocalFilePath);
			assert(FALSE);
			goto FINAL;
		}
	}

	pstAlloc = AllocPostContext();
	if (NULL == pstAlloc)
	{
		dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
		assert(FALSE);
		goto FINAL;
	}

	pstAlloc->bFile					= TRUE;
	pstAlloc->dwCbFileSize			= dwCbFileSize;
	pstAlloc->lpszNameValueA		= CHttpClient::NewAllocAnsi(lpszNameValue, CP_ACP);
	pstAlloc->lpszFilenameValueA	= CHttpClient::NewAllocAnsi(lpszFilenameValue, CP_ACP);
	pstAlloc->lpszLocalFilePath		= new TCHAR[dwCchLocalFilePath];
	if ((NULL == pstAlloc->lpszNameValueA)		||
		(NULL == pstAlloc->lpszFilenameValueA)	||
		(NULL == pstAlloc->lpszLocalFilePath))
	{
		dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
		assert(FALSE);
		goto FINAL;
	}

	ZeroMemory(pstAlloc->lpszLocalFilePath, sizeof(TCHAR)*dwCchLocalFilePath);
	StringCchCopy(pstAlloc->lpszLocalFilePath, dwCchLocalFilePath, lpszLocalFilePath);

	// ������� �Դٸ� ����
	dwRtnValue = ERROR_SUCCESS;

FINAL:

	if (INVALID_HANDLE_VALUE != hFile)
	{
		::CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;
	}

	return dwRtnValue;
}

// [IN] lpszObject : ��) /tmp/upload.php
// [OUT] plpszResponseAlloc : Response BYTE Buffer. NULL ����
// [OUT] pdwCbResponse : Response BYTE Buffer ũ��. NULL ����
// [OUT] plpszResponseTextAlloc : Response�� Text�� ��ȯ. NULL ����
// [OUT] pdwHttpResponseCode : HTTP Response Code
//
// ���ϰ� : Win32 Error Code.
//			ERROR_SUCCESS - ����
//			���� ���δ� HttpResponseCode ����. �ش� ���� 0�̸� ���� �õ��� �ȵǾ��ٴ� ��.
//
// ����:
//
// - ���� ���δ� HttpResponseCode���� ���� �ٶ�. (0�� �ƴϸ� ���� �õ��� ����)
// - ResponseText�� CodePage�� ���� ��ȯ��. �⺻���� CP_ACP. SetEncoding(CP_UTF8)�� ��������.
// - plpsz~ �������� �� �Լ� ȣ��ڷ� ���ϰ��� ������� ���� ��� �� �� ����.
//   leak ������ ���� �� �Լ� ȣ��ڷ� ������ ���� ȣ���Ͻÿ�.
//
// BYTE		pBuf  = NULL;
// LPTSTR	pText = NULL;
// dwRtnValue = c.RequestPost(..., &pBuf, ..., &pText, ...);
// if (ERROR_SUCCESS == dwRtnValue) { ... }
// ...
// FINAL:
// if (NULL != pBuf) c.FreeAlloc(pBuf};
// if (NULL != pText) c.FreeAlloc(pText);
// ...
DWORD CHttpClient::RequestPost(IN LPCTSTR lpszObject, OPTIONAL OUT LPBYTE* plpszResponseAlloc, OPTIONAL IN LPDWORD pdwCbResponse, OPTIONAL OUT LPTSTR* plpszResponseTextAlloc, OPTIONAL OUT LPDWORD pdwHttpResponseCode)
{
	DWORD	dwRtnValue				= ERROR_SUCCESS;
	INT		i						= 0;
	INT		nPos					= 0;
	PCHAR	pSendBuffer				= NULL;

	LPCTSTR	szContentType			= TEXT("Content-Type: multipart/form-data; boundary=") TEXT(HTTP_CLIENT_BOUNDARY) TEXT("\r\n");
	LPCSTR	szMultiPartParamA		= "--" HTTP_CLIENT_BOUNDARY "\r\n"
		"Content-Disposition: form-data; name=\"%s\"\r\n"
		"\r\n"
		"%s\r\n"
		"";	// %s -> param name, %s -> param value

	LPCSTR	szMultiPartFileA		= "--" HTTP_CLIENT_BOUNDARY "\r\n"
		"Content-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\n"
		"Content-Type: application/octet-stream\r\n"
		"\r\n"
		"";	// %s -> param name value, %s -> param filename value, and lastly concat binary bytes... �׸��� ���� \r\n

	LPCSTR	szTail					= "--" HTTP_CLIENT_BOUNDARY "--\r\n";

	LPBYTE	pbufResponse			= NULL;
	DWORD	dwCbResponse			= 0;

	size_t	dwCchMultiPartParamA	= 0;
	size_t	dwCchMultiPartFileA		= 0;
	DWORD	dwCbPost				= 0;
	DWORD	dwCbRead				= 0;
	DWORD	dwCbWrite				= 0;
	TCHAR	szContentLength[32]		= {0,};
	TCHAR	szResponseBuf[16]		= {0,};
	HANDLE	hFile					= INVALID_HANDLE_VALUE;
	DWORD	dwCbResponseSize		= 0;
	INT		nCchLength				= 0;
	LPST_POST_CONTEXT	pstPost		= NULL;
	HINTERNET			hRequest	= NULL;
	INTERNET_BUFFERS	stBufIn		= {0,};

	if (NULL != pdwHttpResponseCode)
	{
		(*pdwHttpResponseCode) = 0;
	}

	if ((NULL == m_hInternet) || (NULL == m_hConnection))
	{
		dwRtnValue = ERROR_NOT_READY;
		assert(FALSE);
		goto FINAL;
	}

	if (NULL == lpszObject)
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		assert(FALSE);
		goto FINAL;
	}

	if (m_nArrPostContextAllocSize < m_nArrPostContextSize)
	{
		dwRtnValue = ERROR_INTERNAL_ERROR;
		assert(FALSE);
		goto FINAL;
	}

	dwCchMultiPartParamA = strlen(szMultiPartParamA) - sizeof(CHAR)*4;	// "%s"�� 2�� �ִµ� �װ��� ����
	dwCchMultiPartFileA  = strlen(szMultiPartFileA) - sizeof(CHAR)*4;	// "%s"�� 2�� �ִµ� �װ��� ����

	// �ϴ� �����ؾ��� Size�� ���Ѵ�.
	dwCbPost = 1; // StringCch~/StringCb~ �Լ� ������� �ּ��� ũ��� 1 �̻��̾�� �Ѵ�.
	dwCbPost += strlen(szTail); // tail �κ��� ũ��� ���Ѵ�.
	for (i=0; i<m_nArrPostContextSize; i++)
	{
		pstPost = &m_pstArrPostContext[i];
		if (NULL == pstPost)
		{
			assert(FALSE);
			continue;
		}

		if (TRUE == pstPost->bFile)
		{
			// szMultiPartFileA ���� 3���� param�� ����.
			if ((NULL == pstPost->lpszFilenameValueA) ||
				(NULL == pstPost->lpszNameValueA) ||
				(0    >= pstPost->dwCbFileSize))
			{
				assert(FALSE);
				continue;
			}

			dwCbPost += dwCchMultiPartFileA * sizeof(CHAR);

			dwCbPost += strlen(pstPost->lpszFilenameValueA) * sizeof(CHAR) +
				strlen(pstPost->lpszNameValueA) * sizeof(CHAR) +
				pstPost->dwCbFileSize;

			dwCbPost += strlen("\r\n");
		}
		else
		{
			// szMultiPartParamA ���� 2���� param�� ����.
			if ((NULL == pstPost->lpszNameA) ||
				(NULL == pstPost->lpszValueA))
			{
				assert(FALSE);
				continue;
			}

			dwCbPost += dwCchMultiPartParamA * sizeof(CHAR);

			dwCbPost += strlen(pstPost->lpszNameA) * sizeof(CHAR) +
				strlen(pstPost->lpszValueA) * sizeof(CHAR);
		}
	}

	pSendBuffer = new CHAR[dwCbPost];
	if (NULL == pSendBuffer)
	{
		dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
		assert(FALSE);
		goto FINAL;
	}
	ZeroMemory(pSendBuffer, sizeof(CHAR)*dwCbPost);

	// ���� ��������.
	nPos = 0;
	for (i=0; i<m_nArrPostContextSize; i++)
	{
		pstPost = &m_pstArrPostContext[i];
		if (NULL == pstPost)
		{
			assert(FALSE);
			continue;
		}

		if (TRUE == pstPost->bFile)
		{
			dwRtnValue = CHttpClient::StringCbVPrintfAppendA(pSendBuffer, 
				dwCbPost, 
				nPos, 
				&nPos, 
				szMultiPartFileA, 
				pstPost->lpszNameValueA,		// arg
				pstPost->lpszFilenameValueA);	// arg
			if (ERROR_SUCCESS != dwRtnValue)
			{
				DEBUGLOGHC(TEXT("[ERROR] Fail to StringCbPrintfAppendA"));
				printf(("[ERROR] Fail to StringCbPrintfAppendA"));
				assert(FALSE);
				goto FINAL;
			}

			if (INVALID_HANDLE_VALUE != hFile)
			{
				::CloseHandle(hFile);
				hFile = INVALID_HANDLE_VALUE;
			}

			hFile = ::CreateFile(pstPost->lpszLocalFilePath, 
				GENERIC_READ, 
				0, 
				NULL, 
				OPEN_EXISTING, 
				FILE_ATTRIBUTE_NORMAL, 
				NULL);
			if (INVALID_HANDLE_VALUE == hFile)
			{
				dwRtnValue = ::GetLastError();
				DEBUGLOGHC(TEXT("[ERROR] Fail to CreateFile 2nd, %d, %s"), dwRtnValue, pstPost->lpszLocalFilePath);
				printf(("[ERROR] Fail to CreateFile 2nd, %d, %s"), dwRtnValue, pstPost->lpszLocalFilePath);
				assert(FALSE);
				goto FINAL;
			}

			if (nPos + pstPost->dwCbFileSize >= dwCbPost)
			{
				dwRtnValue = ERROR_BUFFER_OVERFLOW;
				DEBUGLOGHC(TEXT("[ERROR] Fail to Buffer Overflow, %d, %d, %d,"), nPos, pstPost->dwCbFileSize, dwCbPost);
				printf(("[ERROR] Fail to Buffer Overflow, %d, %d, %d,"), nPos, pstPost->dwCbFileSize, dwCbPost);
				assert(FALSE);
				goto FINAL;
			}

			if (FALSE == ::ReadFile(hFile, 
				&pSendBuffer[nPos], 
				pstPost->dwCbFileSize, 
				&dwCbRead, 
				NULL))
			{
				dwRtnValue = ::GetLastError();
				DEBUGLOGHC(TEXT("[ERROR] Fail to ReadFile, %d, %s"), dwRtnValue, pstPost->lpszLocalFilePath);
				printf(("[ERROR] Fail to ReadFile, %d, %s"), dwRtnValue, pstPost->lpszLocalFilePath);
				assert(FALSE);
				goto FINAL;
			}

			::CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;

			nPos += dwCbRead;

			// ���� \r\n �߰�
			dwRtnValue = CHttpClient::StringCbVPrintfAppendA(pSendBuffer, 
				dwCbPost, 
				nPos, 
				&nPos, 
				"\r\n");
			if (ERROR_SUCCESS != dwRtnValue)
			{
				assert(FALSE);
				goto FINAL;
			}
		}
		else
		{
			dwRtnValue = CHttpClient::StringCbVPrintfAppendA(pSendBuffer, 
				dwCbPost, 
				nPos, 
				&nPos,
				szMultiPartParamA,
				pstPost->lpszNameA, 
				pstPost->lpszValueA);
			if (ERROR_SUCCESS != dwRtnValue)
			{
				assert(FALSE);
				goto FINAL;
			}
		}
	}

	// ���������� tail�� ���Ѵ�.
	// �׷��� ���� ���� ����
	if (strlen(szTail) + 1 + nPos == dwCbPost)
	{
		// good
	}
	else
	{
		// bad
		dwRtnValue = ERROR_INTERNAL_ERROR;
		assert(FALSE);
		goto FINAL;
	}
	StringCchCatA(&pSendBuffer[nPos], dwCbPost - nPos, szTail);

	// StringCch~ StringCb~ ����� ���� +1 �ߴ� ���� �ٽ� -1�� ����.
	// �׷���, ���� \0�� ������ ���� ũ�Ⱑ �ȴ�.
	dwCbPost--;

	// ���� ��������.
	hRequest = ::HttpOpenRequest(m_hConnection, 
		TEXT("POST"), 
		lpszObject, 
		NULL, 
		NULL, 
		NULL, 
		INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_FORMS_SUBMIT, 
		0);
	if (NULL == hRequest)
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to HttpOpenRequest, %d, %s"), dwRtnValue, lpszObject);
		printf(("[ERROR] Fail to HttpOpenRequest, %d, %s"), dwRtnValue, lpszObject);
		assert(FALSE);
		goto FINAL;
	}

	if (FALSE == ::HttpAddRequestHeaders(hRequest, 
		szContentType, 
		_tcslen(szContentType), 
		HTTP_ADDREQ_FLAG_ADD_IF_NEW))
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to HttpAddREquestHeaders, %d"), dwRtnValue); 
		printf(("[ERROR] Fail to HttpAddREquestHeaders, %d"), dwRtnValue); 
		assert(FALSE);
		goto FINAL;
	}

	StringCchPrintf(szContentLength, 32, TEXT("Content-Length: %d\r\n"), dwCbPost);
	if (FALSE == ::HttpAddRequestHeaders(hRequest, 
		szContentLength, 
		_tcslen(szContentLength), 
		HTTP_ADDREQ_FLAG_ADD_IF_NEW))
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to HttpAddRequestHeaders, %d"), dwRtnValue);
		printf(("[ERROR] Fail to HttpAddRequestHeaders, %d"), dwRtnValue);
		assert(FALSE);
		goto FINAL;
	}
	send_request:
	stBufIn.dwStructSize = sizeof(stBufIn);
	stBufIn.Next = NULL;
	if (FALSE == ::HttpSendRequestEx(hRequest, 
		&stBufIn, 
		NULL, 
		HSR_INITIATE, 
		0))
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to HttpSendRequestEx, %d"), dwRtnValue);
		printf(("[ERROR] Fail to HttpSendRequestEx, %d"), dwRtnValue);
		assert(FALSE);
		goto FINAL;
	}

	if (FALSE == ::InternetWriteFile(hRequest, 
		pSendBuffer, 
		dwCbPost, 
		&dwCbWrite))
	{
		dwRtnValue = ::GetLastError();
		DEBUGLOGHC(TEXT("[ERROR] Fail to InternetWriteFile, %d"), dwRtnValue);
		printf(("[ERROR] Fail to InternetWriteFile, %d"), dwRtnValue);
		assert(FALSE);
		goto FINAL;
	}

	if (FALSE == ::HttpEndRequest(hRequest, NULL, HSR_INITIATE, 0))
	{
 		dwRtnValue = ::GetLastError();
 		
		if (dwRtnValue == 12032 && m_nReSendCount < 2)					//��ȣȭ �Ѱ�� 12032 ���� �ڵ带 ������ �ٽ� �õ��϶�� �Ѵ�. 
		{																//goto ���� ���Ͽ� SendRequest�� �ٽ� �ϸ� ����� ���۵ȴ�. 
			m_nReSendCount++;
			goto send_request;
		}
		DEBUGLOGHC(TEXT("[ERROR] Fail to HttpEndRequest, %d"), dwRtnValue);
		printf("[ERROR] Fail to HttpEndRequest, %d", dwRtnValue);
		assert(FALSE);
		goto FINAL;
	}

	if (NULL != pdwHttpResponseCode)
	{
		// HTTP Response Code ��û�� ����...

		ZeroMemory(szResponseBuf, sizeof(szResponseBuf));

		dwCbRead = 16;
		if (FALSE == ::HttpQueryInfo(hRequest, 
			HTTP_QUERY_STATUS_CODE, 
			szResponseBuf, 
			&dwCbRead, 
			NULL))
		{
			dwRtnValue = ::GetLastError();
			DEBUGLOGHC(TEXT("[ERROR] Fail to HttpQueryInfo, HTTP_QUERY_STATUS_CODE, %d"), dwRtnValue);
			printf(("[ERROR] Fail to HttpQueryInfo, HTTP_QUERY_STATUS_CODE, %d"), dwRtnValue);
			assert(FALSE);
			goto FINAL;
		}

		(*pdwHttpResponseCode) = (DWORD)_ttoi64(szResponseBuf);
	}

	if ((NULL != pdwCbResponse) || (NULL != plpszResponseAlloc) || (NULL != plpszResponseTextAlloc))
	{
		// Response ��� ��û�� ����...

		ZeroMemory(szResponseBuf, sizeof(szResponseBuf));

		dwCbRead = 16;
		if (FALSE == ::HttpQueryInfo(hRequest, 
			HTTP_QUERY_CONTENT_LENGTH, 
			szResponseBuf, 
			&dwCbRead, 
			NULL))
		{
			dwRtnValue = ::GetLastError();
			DEBUGLOGHC(TEXT("[ERROR] Fail to HttpQueryInfo, HTTP_QUERY_CONTENT_LENGTH, %d"), dwCbRead);
			printf(("[ERROR] Fail to HttpQueryInfo, HTTP_QUERY_CONTENT_LENGTH, %d"), dwCbRead);
			assert(FALSE);
			goto FINAL;
		}

		dwCbResponse = (DWORD)::_ttoi64(szResponseBuf);
		pbufResponse = new BYTE[dwCbResponse];
		if (NULL == pbufResponse)
		{
			dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
			assert(FALSE);
			goto FINAL;
		}
		ZeroMemory(pbufResponse, sizeof(BYTE)*(dwCbResponse));

		if (FALSE == ::InternetReadFile(hRequest, 
			pbufResponse, 
			dwCbResponse, 
			&dwCbRead))
		{
			delete [] pbufResponse;
			pbufResponse = NULL;

			dwRtnValue = ::GetLastError();
			DEBUGLOGHC(TEXT("[ERROR] Fail to InternetReadFile, %d"), dwRtnValue);
			printf(("[ERROR] Fail to InternetReadFile, %d"), dwRtnValue);
			assert(FALSE);
			goto FINAL;
		}

		if (NULL != plpszResponseTextAlloc)
		{
			nCchLength = ::MultiByteToWideChar(m_dwCodePage, 
				0, 
				(LPCSTR)pbufResponse, 
				dwCbRead, 
				NULL, 
				0);

			(*plpszResponseTextAlloc) = new TCHAR[nCchLength+2];
			if (NULL == (*plpszResponseTextAlloc))
			{
				delete [] pbufResponse;
				pbufResponse = NULL;

				dwRtnValue = ERROR_NOT_ENOUGH_MEMORY;
				assert(FALSE);
				goto FINAL;
			}
			ZeroMemory((*plpszResponseTextAlloc), sizeof(TCHAR)*(nCchLength+2));

			::MultiByteToWideChar(m_dwCodePage, 
				0, 
				(LPCSTR)pbufResponse, 
				dwCbRead, 
				(*plpszResponseTextAlloc), 
				nCchLength+1);

		}

		if (NULL != plpszResponseAlloc)
		{
			(*plpszResponseAlloc) = pbufResponse;
		}
		else
		{
			delete [] pbufResponse;
			pbufResponse = NULL;
		}

		if (NULL != pdwCbResponse)
		{
			(*pdwCbResponse) = dwCbResponse;
		}
	}

	// ������� �Դٸ� ����
	ClearPostContext();
	dwRtnValue = ERROR_SUCCESS;

FINAL:

	if (NULL != hRequest)
	{
		::InternetCloseHandle(hRequest);
		hRequest = NULL;
	}

	if (INVALID_HANDLE_VALUE != hFile)
	{
		::CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;
	}

	if (NULL != pSendBuffer)
	{
		delete [] pSendBuffer;
		pSendBuffer = NULL;
	}

	return dwRtnValue;
}

LPSTR CHttpClient::NewAllocAnsi(IN LPCTSTR lpszSource, IN UINT CodePage)
{
	LPSTR	lpszRtnValue	= NULL;
	size_t	dwCchSource		= 0;

#ifndef UNICODE
	dwCchSource = strlen(lpszSource) + 1;
	lpszRtnValue = new CHAR[dwCchSource];
	if (NULL != lpszRtnValue)
	{
		ZeroMemory(lpszRtnValue, sizeof(CHAR)*dwCchSource);
		StringCchCopyA(lpszRtnValue, dwCchSource, lpszSource);
	}
#else
	dwCchSource = ::WideCharToMultiByte(CodePage, 0, lpszSource, -1, NULL, 0, NULL, NULL) + 1;
	lpszRtnValue = new CHAR[dwCchSource];
	if (NULL != lpszRtnValue)
	{
		ZeroMemory(lpszRtnValue, sizeof(CHAR)*dwCchSource);
		::WideCharToMultiByte(CodePage, 0, lpszSource, -1, lpszRtnValue, dwCchSource, NULL, NULL);
	}
#endif
	return lpszRtnValue;
}

// printf�� concat�Ѵ�.
DWORD CHttpClient::StringCbVPrintfAppendA(OUT LPSTR lpszDestA, IN DWORD dwCbSize, IN INT nStartPos, OUT PINT pnEndPos, IN LPCSTR lpszFormatA, ...)
{
	DWORD	dwRtnValue	= ERROR_SUCCESS;
	HRESULT	hResult		= S_OK;
	va_list arg			= {0,};

	if ((NULL == lpszDestA) || (NULL == pnEndPos) || (NULL == lpszFormatA))
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		assert(FALSE);
		goto FINAL;
	}

	if (nStartPos + 1 >= (INT)dwCbSize)
	{
		dwRtnValue = ERROR_MORE_DATA;
		assert(FALSE);
		goto FINAL;
	}

	va_start(arg, lpszFormatA);

	hResult = StringCchVPrintfA(&lpszDestA[nStartPos], dwCbSize - nStartPos, lpszFormatA, arg);
	if (S_OK == hResult)
	{
		dwRtnValue = ERROR_SUCCESS;
	}
	else
	{
		if (STRSAFE_E_INVALID_PARAMETER == hResult)
		{
			dwRtnValue = ERROR_INVALID_PARAMETER;
		}
		else if (STRSAFE_E_INSUFFICIENT_BUFFER == hResult)
		{
			dwRtnValue = ERROR_MORE_DATA;
		}
		else
		{
			dwRtnValue = ERROR_INTERNAL_ERROR;
		}

		// �����ߴٸ�, �ٽ� ����.
		lpszDestA[nStartPos] = TEXT('\0');
	}

	*pnEndPos = strlen(&lpszDestA[nStartPos]) + nStartPos;

FINAL:
	return dwRtnValue;
}

VOID CHttpClient::FreeAlloc(IN LPVOID pBuf)
{
	if (NULL != pBuf)
	{
		delete [] pBuf;
		pBuf = NULL;
	}
}