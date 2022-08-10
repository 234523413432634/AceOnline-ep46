#pragma once
#include <windows.h>
#include <WinInet.h>
#pragma comment(lib,"wininet.lib")
class CHttpClient
{
public:
	CHttpClient(void);
	~CHttpClient(void);

public:
	//////////////////////////////////////////////////////////////////////////
	// Session
	DWORD CreateSession(IN LPTSTR lpszAgent, IN LPCTSTR lpszServer, IN DWORD dwPort, const wchar_t* UserName = NULL, const wchar_t* UserPass = NULL);
	VOID  CloseSession(VOID);

	//////////////////////////////////////////////////////////////////////////
	// Post Argument
	DWORD AddPostParam(IN LPCTSTR lpszName, IN LPCTSTR lpszValue);
	DWORD AddPostFile(IN LPCTSTR lpszNameValue, IN LPCTSTR lpszFilenameValue, IN LPCTSTR lpszLocalFilePath);

	//////////////////////////////////////////////////////////////////////////
	// Post Action
	DWORD RequestPost(IN LPCTSTR lpszObject, OPTIONAL OUT LPBYTE* plpszResponseAlloc, OPTIONAL IN LPDWORD pdwCbResponse, OPTIONAL OUT LPTSTR* plpszResponseTextAlloc, OPTIONAL OUT LPDWORD pdwHttpResponseCode);
	VOID  FreeAlloc(IN LPVOID pBuf);

	//////////////////////////////////////////////////////////////////////////
	// Option
	VOID SetEncoding(IN DWORD CodePage)	{m_dwCodePage = CodePage;}

private:
	HINTERNET m_hInternet;
	HINTERNET m_hConnection;

private:
	//////////////////////////////////////////////////////////////////////////
	// Post Array Context
	typedef struct tagST_POST_CONTEXT
	{
		BOOL bFile;

		// 아래 ~A로 끝나는 ANSI는 NewAllocAnsi의 CodePage로 변환된다.
		IN LPSTR lpszNameA;
		IN LPSTR lpszValueA;

		IN LPSTR lpszNameValueA;
		IN LPSTR lpszFilenameValueA;
		IN LPTSTR lpszLocalFilePath;

		DWORD dwCbFileSize;
	} ST_POST_CONTEXT, *LPST_POST_CONTEXT;

	CRITICAL_SECTION	m_cs;
	LPST_POST_CONTEXT	m_pstArrPostContext;
	INT					m_nArrPostContextAllocSize;
	INT					m_nArrPostContextSize;

	VOID				ClearPostContext(VOID);
	CHttpClient::LPST_POST_CONTEXT	AllocPostContext(VOID);

private:
	DWORD m_dwCodePage;
	int m_nReSendCount;

public:
	//////////////////////////////////////////////////////////////////////////
	// Utility
	static LPSTR NewAllocAnsi(IN LPCTSTR lpszSource, IN UINT CodePage);
	static DWORD StringCbVPrintfAppendA(OUT LPSTR lpszDestA, IN DWORD dwCbSize, IN INT nStartPos, OUT PINT pnEndPos, IN LPCSTR lpszFormatA, ...);

public:
	//////////////////////////////////////////////////////////////////////////
	// Define
#define HTTP_CLIENT_BOUNDARY "--HC-MPFD-BOUNDARY"
};
