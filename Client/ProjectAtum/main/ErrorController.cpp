// 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����

//######################################################################################
// File    : NTDbgHelper.h
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Blog    : http://blog.naver.com/goli81
// Desc    : NTDbgHelper
// Bug     : 
//######################################################################################
//#include "./Network/NTClientSocket.h"
#include "ErrorController.h"

#include <Shlwapi.h>
#pragma comment( lib, "shlwapi.lib" )

//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : �޸� �Ҵ� ���н� ȣ��
//######################################################################################
void __cdecl OnNewhandler()
{
	MessageBox( NULL, _T("�޸� �Ҵ翡 �����Ͽ����ϴ�. ���α׷��� �ٽ� ���� �ϰų� \
��ǻ�͸� ����� �Ͽ� �ֽʽÿ�"), _T("Error"), MB_OK );
	throw std::bad_alloc();
}

//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : Exception Filter
//######################################################################################
LONG WINAPI OnExceptionFilter(_EXCEPTION_POINTERS *pException)
{
	LONG lResult = EXCEPTION_CONTINUE_SEARCH;

	lResult = g_cErrorController.OnPlayMiniDump(pException);

	return lResult;
}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : ������
//######################################################################################
CErrorController::CErrorController() :
m_hDllModule( NULL ),
m_bUseServer( false ),
m_bUseDumpServer( true ),
m_bOnlyDumpString( true ), // ũ������ ������ ���ڿ��θ� ������ �ֱ�
m_nSerialCode( 0 ),
m_nBuildCount( 0 )
{
	memset( &m_dwCallStack , 0, sizeof(m_dwCallStack) );
	
	// �ܺο��� ��� �� �� ũ���� ����, �ٸ� �۾��� �� �� �ֱ⿡ ���⼱ ������� ����
	//::SetUnhandledExceptionFilter(OnExceptionFilter);

	// �� Ŭ������ �뵵�� ũ�����ϱ� new �Ҵ� üũ�� ���� ����
	//std::set_new_handler(OnNewhandler);
}

//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : �Ҹ���
//######################################################################################
CErrorController::~CErrorController()
{
}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : Debug ����
//######################################################################################
LONG CErrorController::OnPlayMiniDump(_EXCEPTION_POINTERS *pException)
{
	if( false == OnLoadDbgDllFile() )
		return EXCEPTION_EXECUTE_HANDLER;

	SetCallStack(pException);
	m_cSystemInfo.Initialize();

	if( OnlyDumpString(pException, &m_cSystemInfo) )
		return EXCEPTION_EXECUTE_HANDLER;

	m_cDbgWindow.OnCreateWindow();
	m_cDbgWindow.SetMoreInfo(pException, &m_cSystemInfo);
	
	TCHAR szSaveFilename[512+100];
	TCHAR szTempString[100];

	// ��¥�� �����ڵ�� ����ѹ�
	SYSTEMTIME stime;
	::GetLocalTime(&stime);
	_snprintf( szTempString, 100, _T("\\%02d-%02d-%02d_%02d-%02d-%02d+%06d-%06d"), stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, stime.wSecond, m_nSerialCode, m_nBuildCount);

	_tfullpath(szSaveFilename,NULL,512);

	strncat( szSaveFilename, szTempString, 100 );			// ��¥ ���ϱ�
	strcat( szSaveFilename, _T("-") );
	strcat( szSaveFilename, m_pstrUserName.c_str() );		// �����̸� ���ϱ�
	strcat( szSaveFilename, _T(".dmp") );

	SendBaseExceptionInfo(szSaveFilename);

	if( IDC_DUMPCANCEL == m_cDbgWindow.GetEvent() )
	{
		return EXCEPTION_EXECUTE_HANDLER;
	}

	TCHAR szDataString[1024] = {0};
	//m_strSysInfo += _T("\n============================================\n");
	m_cDbgWindow.GetSystemString( szDataString, sizeof(szDataString) );
	m_strSysInfo += szDataString;
	//m_strSysInfo += _T("\n============================================\n");


	szDataString[0] = NULL;
	m_cDbgWindow.GetUserString( szDataString, sizeof(szDataString) );
	m_szUserData += _T(" ");
	for( size_t i = 0; i < _tcslen(szDataString); i++ )
	{
		if( szDataString[i] == 13 )
			m_szUserData += ' ';
		m_szUserData += szDataString[i];
		if( szDataString[i] == 10 )
			m_szUserData += ' ';
	}
	m_szUserData += m_szMyDebugData;

	LONG lResult = m_cMiniDump.OnSaveMiniDump( pException, szSaveFilename, m_hDllModule, 
		m_strSysInfo.c_str(), (UINT)m_strSysInfo.length(), m_szUserData.c_str(), (UINT)m_szUserData.length() );

	if( EXCEPTION_EXECUTE_HANDLER == lResult )
	{
		if( m_bUseDumpServer )
		{
			if( !m_pstrFTPServerIP.empty() )
			{
				if( m_cUploadFtp.Connect( m_pstrFTPServerIP.c_str(), m_dFTPPort, m_strFTPID.c_str(), m_strFTPPassword.c_str() ) )
				{
					if( false == m_cUploadFtp.UpLoad(m_cDbgWindow.GetProgressHWND(), szSaveFilename) )
					{
						MessageBoxA(NULL, "FTP transfers are failed.", "Error", MB_OK);
					}

				}
				else
				{
					MessageBoxA(NULL, "FTP connection is failed.", "Error", MB_OK);
				}

				DeleteFile( szSaveFilename );
			}
		}
		else
		{
			DeleteFile( szSaveFilename );
		}
	}


	return lResult;
}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : Ftp���� ���� ����
//######################################################################################
void CErrorController::SetFtpInfo(const TCHAR *pszFTPIP, WORD dFTPPort, const TCHAR *pszFTPID, const TCHAR *pszFTPPassword)
{
	m_pstrFTPServerIP = pszFTPIP;
	m_dFTPPort = dFTPPort;
	m_strFTPID = pszFTPID;
	m_strFTPPassword = pszFTPPassword;
}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : Ftp���� ���� ����
//######################################################################################
void CErrorController::SetServerInfo(const TCHAR *pszServerIP, WORD dPort)
{
	m_pstrServerIP = pszServerIP;
	m_dPort = dPort;
}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : CallStack�� �����Ѵ�
//######################################################################################
void CErrorController::SetCallStack(_EXCEPTION_POINTERS *pException)
{
	memset( &m_dwCallStack, 0, sizeof(m_dwCallStack) );

	STACKFRAME64 sStackFrame;
	memset(&sStackFrame, 0, sizeof(sStackFrame));
	DWORD imageType;
#ifdef _M_IX86
	imageType = IMAGE_FILE_MACHINE_I386;
	sStackFrame.AddrPC.Offset = pException->ContextRecord->Eip;
	sStackFrame.AddrPC.Mode = AddrModeFlat;
	sStackFrame.AddrFrame.Offset = pException->ContextRecord->Ebp;
	sStackFrame.AddrFrame.Mode = AddrModeFlat;
	sStackFrame.AddrStack.Offset = pException->ContextRecord->Esp;
	sStackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_X64
	imageType = IMAGE_FILE_MACHINE_AMD64;
	sStackFrame.AddrPC.Offset = pException->ContextRecord->Rip;
	sStackFrame.AddrPC.Mode = AddrModeFlat;
	sStackFrame.AddrFrame.Offset = pException->ContextRecord->Rsp;
	sStackFrame.AddrFrame.Mode = AddrModeFlat;
	sStackFrame.AddrStack.Offset = pException->ContextRecord->Rsp;
	sStackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_IA64
	imageType = IMAGE_FILE_MACHINE_IA64;
	sStackFrame.AddrPC.Offset = pException->ContextRecord->StIIP;
	sStackFrame.AddrPC.Mode = AddrModeFlat;
	sStackFrame.AddrFrame.Offset = pException->ContextRecord->IntSp;
	sStackFrame.AddrFrame.Mode = AddrModeFlat;
	sStackFrame.AddrBStore.Offset = pException->ContextRecord->RsBSP;
	sStackFrame.AddrBStore.Mode = AddrModeFlat;
	sStackFrame.AddrStack.Offset = pException->ContextRecord->IntSp;
	sStackFrame.AddrStack.Mode = AddrModeFlat;
#else
#error "Platform not supported!"
#endif

	HANDLE process = GetCurrentProcess();
	HANDLE thread  = GetCurrentThread();
	for(UINT i = 0; i < MAX_CALLSTACK ; ++i) 
	{
		if( FALSE == StackWalk64(imageType, process, thread, &sStackFrame, &pException->ContextRecord, 
			NULL, NULL, NULL, NULL ) )
		{
			break;
		}

		//char szTemp[256];
		//sprintf( szTemp, "0x%08x \n", sStackFrame.AddrPC.Offset);
		//OutputDebugString( szTemp );
		if( sStackFrame.AddrPC.Offset > 268435456 )
			m_dwCallStack[i] = 0;
		else
			m_dwCallStack[i] = (DWORD)sStackFrame.AddrPC.Offset;
	}

}


//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : Dll���� �ε�
//######################################################################################
bool CErrorController::OnLoadDbgDllFile()
{
	TCHAR szDllHelpPath[MAX_PATH] = {0};

	// DLL �ε�
	if(::GetModuleFileName(NULL, szDllHelpPath, _MAX_PATH))
	{
		TCHAR *pSlash = ::_tcsrchr(szDllHelpPath, _T('\\'));
		if( pSlash )
		{
			::lstrcpy(pSlash + 1, _T("DBGHELP.DLL"));
			m_hDllModule = ::LoadLibrary(szDllHelpPath);
		}
	}

	if( NULL == m_hDllModule )
	{
		m_hDllModule = ::LoadLibrary( _T("DBGHELP.DLL") );
	}


	if( NULL == m_hDllModule )
	{
		MessageBox(NULL, _T("DBGHELP.DLL not find."), _T("Error"), MB_OK);
		return false;
	}

	return true;
}

//######################################################################################
// Date    : 2007-1-8
// Author  : ��(goli81@naver.com)
// Desc    : �⺻ �浹���� ���� ����
//######################################################################################
void CErrorController::SendBaseExceptionInfo(const TCHAR* pszDumpCode)
{
	if( m_pstrServerIP.empty() )
		return;

	//CNTClientSocket cClintSocket;

	//if( false == cClintSocket.Initialize( m_pstrServerIP.c_str(), m_dPort ) )
	//{
	//	//::MessageBox( NULL, "�����ʱ�ȭ ����!", "����", MB_OK );
	//	return;
	//}

	TString strDumpName;

	size_t nCutNum = 0;
	size_t nLen = _tcsclen(pszDumpCode);
	for( size_t i = nLen-1; i > 0; i-- )
	{
		if( pszDumpCode[i] == '\\' )
		{
			nCutNum = i+1;
			break;
		}
	}
	strDumpName = pszDumpCode+nCutNum;

	//CNTPacket vData;
	//vData.SetMsgID(MSGID_EXCEPTION);

	//vData << m_nSerialCode << m_pstrUserName.c_str() << strDumpName.c_str();

	//for( int i = 0; i < MAX_CALLSTACK; i++ )
	//	vData << m_dwCallStack[i];


	//cClintSocket.SendPacket( &vData );

}

// fopen
// "r"  �б� ����. ������ �ݵ�� �־�� �մϴ�.
// "w"  ���� ����. ������ ������ �����ǰ�, ������ �ִٸ� ���� ������ �������ϴ�.
// "a"  ���� �߰�. ������ ������ �����ǰ�, ������ �ִٸ� ���� ���� �ڿ� �߰��˴ϴ�.
// "rb" ���̳ʸ� ���� �б� �������� ����
// "wb" ���̳ʸ� ���� ���� �������� ����
// "ab" ���̳ʸ� ���� �߰������� ����
// "r+" �б�� ��������� ����
// "w+" �б�� ��������� ����

//Binary �������� Ansi ���� ���
bool exportBinaryFile(LPCSTR szPath, const std::string & data, int nLoadType = 0 )
{
	FILE *stream;

	switch( nLoadType )
	{
	case 0:
		stream = fopen(szPath, "wb");
		break;
	case 1:
		stream = fopen(szPath, "a");
		break;
	}

	if( !stream )
		return false;
	//�ؽ�Ʈ ����
	fwrite( (void*)data.c_str(), sizeof(char), data.size(), stream);
	fclose(stream);
	return true;
}

//Binary �������� Uni ���� ���
bool exportBinaryFile(LPCSTR szPath, const std::wstring & data)
{
	FILE *stream;
	stream = fopen(szPath, "wb");
	if( !stream )
		return false;
	//Bom ���
	fputwc(0xFEFF, stream);
	//�ؽ�Ʈ ����
	fwrite( (void*)data.c_str(), sizeof(wchar_t), data.size(), stream);
	fclose(stream);
	return true;
}

struct HandleReleaseBlock {
	HandleReleaseBlock(HANDLE _handle)
		: handle_(_handle) {}
	~HandleReleaseBlock() {
		if (handle_ != INVALID_HANDLE_VALUE) {
			CloseHandle(handle_);
		}
	}

	HANDLE handle_;
};

inline bool getFileTime(__in const TCHAR* filePath, 
	__out SYSTEMTIME* creationTime, 
	__out SYSTEMTIME* lastAccessTime, 
	__out SYSTEMTIME* lastWriteTime)
{
	//assert(filePath);
	if(!filePath)
	{
		return false;
	}

	SYSTEMTIME* outTime[3];
	outTime[0] = creationTime;
	outTime[1] = lastAccessTime;
	outTime[2] = lastWriteTime;

	if (!outTime[0] && !outTime[1] && !outTime[2]) {
		return true;
	}

	HANDLE hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return false;
	}
	HandleReleaseBlock fileBlock(hFile);

	FILETIME fileTime[3];

	if (! GetFileTime(hFile, 
		(outTime[0] ? &fileTime[0] : NULL), 
		(outTime[1] ? &fileTime[1] : NULL),
		(outTime[2] ? &fileTime[2] : NULL)) ) {
			return false;
	}

	SYSTEMTIME systemTime;
	for (int index = 0; index < 3; ++index) {
		if (outTime[index]) {
			if (! FileTimeToSystemTime(&fileTime[index], &systemTime)) {
				return false;
			}
			if (! SystemTimeToTzSpecificLocalTime(NULL, &systemTime, outTime[index])) {
				return false;
			}
		}
	}

	return true;
}

bool CErrorController::OnlyDumpString(_EXCEPTION_POINTERS *pException, CNTSystemInfo* pSystemInfo)
{
	if( m_bOnlyDumpString )
	{
		TCHAR szTempString[N_BUF_SIZE] = {0, };
		TString strSnedEdit;

		_snprintf( szTempString, N_BUF_SIZE, _T("�߻�����	: %x\r\n"), pException->ExceptionRecord->ExceptionCode );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("�����ּ�	: 0x%08x\r\n"), pException->ContextRecord->Eip );
		strSnedEdit += szTempString;

		SYSTEMTIME creationTime_;
		SYSTEMTIME lastAccessTime_;
		SYSTEMTIME lastWriteTime_;
		TCHAR tcPath[N_BUF_SIZE] = {0, };
		GetModuleFileName( NULL, tcPath, N_BUF_SIZE );		
		getFileTime( tcPath, &creationTime_, &lastAccessTime_, &lastWriteTime_);
		_snprintf( szTempString, N_BUF_SIZE, _T("���		: %s\r\n"), tcPath );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("������ ��¥	: %d�� %d�� %d�� %d�� %d��\r\n"),
			lastWriteTime_.wYear, lastWriteTime_.wMonth, lastWriteTime_.wDay, lastWriteTime_.wHour, lastWriteTime_.wMinute );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("�ü��	: %s\r\n"), pSystemInfo->GetWindowVersionString() );
		strSnedEdit += szTempString;

// 		_snprintf( szTempString, N_BUF_SIZE, _T("�׷��� ī��	: %s\r\n"), pSystemInfo->GetVideoCardString() );
// 		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("CPU		: %s\r\n"), pSystemInfo->GetCpuString() );
		strSnedEdit += szTempString;

// 		_snprintf( szTempString, N_BUF_SIZE, _T("DirectX	: %s\r\n"), pSystemInfo->GetDxVersionString() );
// 		strSnedEdit += szTempString;


		strSnedEdit += _T("\r\n<�޸� ����>\r\n");
		MEMORYSTATUS MemStatus;
		MemStatus.dwLength=sizeof(MemStatus);
		GlobalMemoryStatus(&MemStatus);

		_snprintf( szTempString, N_BUF_SIZE, _T("��ü �޸�		: %dMB \r\n"), MemStatus.dwTotalPhys/(1024*1024) );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("����� �޸�		: %dMB \r\n"), MemStatus.dwAvailPhys/(1024*1024) );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("���� �޸�		: %dMB \r\n"), MemStatus.dwTotalVirtual/(1024*1024) );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("����� ���� �޸�	: %dMB \r\n"), MemStatus.dwAvailVirtual/(1024*1024) );
		strSnedEdit += szTempString;

// 		_snprintf( szTempString, N_BUF_SIZE, _T("���� �޸�		: %dMB \r\n"), pSystemInfo->GetVideoPhysicMemory() );
// 		strSnedEdit += szTempString;


		strSnedEdit += _T("\r\n<�������� ����>\r\n");
		_snprintf( szTempString, N_BUF_SIZE, _T("EDI	: 0x%08x\r\nESI	: 0x%08x\r\nEAX	: 0x%08x\r\n"), 
			pException->ContextRecord->Edi, pException->ContextRecord->Esi, pException->ContextRecord->Eax );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("EBX	: 0x%08x\r\nECX	: 0x%08x\r\nEDX	: 0x%08x\r\n"), 
			pException->ContextRecord->Ebx, pException->ContextRecord->Ecx, pException->ContextRecord->Edx );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("EIP	: 0x%08x\r\nEBP	: 0x%08x\r\nSegCs	: 0x%08x\r\n"), 
			pException->ContextRecord->Eip, pException->ContextRecord->Ebp, pException->ContextRecord->SegCs );
		strSnedEdit += szTempString;

		_snprintf( szTempString, N_BUF_SIZE, _T("EFlags	: 0x%08x\r\nESP	: 0x%08x\r\nSegSs	: 0x%08x\r\n"), 
			pException->ContextRecord->EFlags, pException->ContextRecord->Esp, pException->ContextRecord->SegSs );
		strSnedEdit += szTempString;

		PathRemoveFileSpec( tcPath );
		
		_snprintf( szTempString, N_BUF_SIZE, _T("%s\\%08x_%s.txt"), tcPath, pException->ContextRecord->Eip, m_pstrUserName.c_str() ); 
		
#ifdef SC_DARK_CRASH_FILE_OUTPUT_HSSON
		//txt���Ϸ� �̴� ���
		exportBinaryFile( szTempString, strSnedEdit );
#endif // SC_DARK_CRASH_FILE_OUTPUT_HSSON

		CopyMemory( m_strOutInfo, strSnedEdit.c_str(), sizeof(TCHAR) * strSnedEdit.length() );

		return true;
	}

	return false;
}

// end 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����