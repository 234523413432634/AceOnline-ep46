// ProjectAtum.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include <shellapi.h>					// 2014-02-10 by ssjung, 버그 트랩
#include "AtumApplication.h"
#include "MGameDecryption.h"

// 2010-09-29 by jskim, 덤프 남기도록 수정 
#include "dbgHelp.h"
#pragma comment(lib, "dbghelp.lib")

#include "CustomOptimizer.h"

#include "DarkCrash.h" // 2011-08-17 by hsson 클라이언트 크래쉬 날때 서버로 클라 정보 전송
#include "ShuttleChild.h"		// 2014-02-10 by ssjung, 버그 트랩

 #define  SET_CRT_DEBUG_FIELD(a) \
                 _CrtSetDbgFlag((a) | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))

LONG __stdcall Exception_Minidump(_EXCEPTION_POINTERS* pExceptionInfo)
{
    char fileName[MAX_PATH];
    GetModuleFileName(NULL, fileName, sizeof(fileName));
    char* ext = strrchr(fileName, '.');

	// 2014-03-04 by ymjoo 크래쉬 덤프 파일명에 시간, 날짜 추가
#if defined C_DUMP_FILE_NAME_CURRENT_TIME_YMJOO
	SYSTEMTIME stime;
	::GetLocalTime(&stime);
	char currentTimeString[100];
	_snprintf(currentTimeString, 100, "-%04d-%02d-%02d-%02d-%02d-%02d", stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, stime.wSecond);
	strcpy(ext ? ext : fileName+strlen(fileName), currentTimeString);
	strcat(fileName, ".dmp");
#else
	strcpy(ext ? ext : fileName+strlen(fileName), ".dmp");
#endif
	// END 2014-03-04 by ymjoo 크래쉬 덤프 파일명에 시간, 날짜 추가

    char temp[256];
    wsprintf(temp, "Exception 0x%08x arised !!", pExceptionInfo->ExceptionRecord->ExceptionCode);
    MessageBox(NULL, temp, fileName, MB_OK);

    HANDLE hProcess = GetCurrentProcess();
    DWORD dwProcessID = GetCurrentProcessId();
    HANDLE hFile = CreateFile(fileName, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    MINIDUMP_EXCEPTION_INFORMATION eInfo;
    eInfo.ThreadId = GetCurrentThreadId();
    eInfo.ExceptionPointers = pExceptionInfo;
    eInfo.ClientPointers = FALSE;

    MiniDumpWriteDump(hProcess, dwProcessID, hFile, MiniDumpNormal, pExceptionInfo ? &eInfo : NULL, NULL, NULL);

// 2014-02-10 by ssjung, 버그 트랩
#ifdef SC_BUGTRAP_BCKIM_SSJUNG		
	{
		char buffer[SIZE_MAX_PACKET];
		MSG_FC_BUGTRAP_ACCEPT sMsg;
		memset(&sMsg, 0x00, sizeof(MSG_FC_BUGTRAP_ACCEPT));
		sMsg.CharacterUniqueNumber =  g_pD3dApp->m_pShuttleChild->GetMyShuttleInfo().CharacterUniqueNumber;
		int nType = T_FC_BUGTRAP_ACCEPT;
		memcpy(buffer, &nType, SIZE_FIELD_TYPE_HEADER);
		memcpy(buffer+SIZE_FIELD_TYPE_HEADER, &sMsg, sizeof(sMsg));
		g_pFieldWinSocket->Write(buffer, SIZE_FIELD_TYPE_HEADER + sizeof(sMsg));

		char AppArgv[1024] = {0,};
		
		wsprintf(AppArgv,"%s %s %s %s %s %s %s","AceTrap.atm", fileName, g_pD3dApp->GetMFSMyShuttleInfo()->CharacterName, g_pD3dApp->m_strBugtrapSeverInfo.BugTrapServerIP, 
			g_pD3dApp->m_strBugtrapSeverInfo.LoginID, g_pD3dApp->m_strBugtrapSeverInfo.LoginPW, g_pD3dApp->m_strBugtrapSeverInfo.ServerNationInfo);
		
		WinExec(AppArgv, SW_SHOW);
	}
#endif
// 2014-02-10 by ssjung, 버그 트랩


	// 2011-08-17 by hsson 클라이언트 크래쉬 날때 서버로 클라 정보 전송
#ifdef SC_DARK_CRASH_HSSON
	Exception::CDarkCrash::OnPlayMiniDump( pExceptionInfo );
	char* pc = new char[1024];
	Exception::CDarkCrash::OutInfo( pc );
	//OutputDebugString( pc );
	
	char buffer[SIZE_MAX_PACKET];
	int nType = T_FC_PARTY_ACCEPT_INVITE;
	memcpy(buffer, &nType, SIZE_FIELD_TYPE_HEADER);
	memcpy(buffer+SIZE_FIELD_TYPE_HEADER, pc, strlen(pc));
	g_pFieldWinSocket->Write(buffer, SIZE_FIELD_TYPE_HEADER + strlen(pc));

	delete pc;
#endif // SC_DARK_CRASH_HSSON
	// end 2011-08-17 by hsson 클라이언트 크래쉬 날때 서버로 클라 정보 전송

    return EXCEPTION_EXECUTE_HANDLER;
}
// end 2010-09-29 by jskim, 덤프 남기도록 수정 

HANDLE g_hMutexMonoInstance = NULL;
HANDLE g_hMutexMonoInstanceTemp = NULL;


// 2014-01-06 by bhsohn Xtrap 테스트서버 키 다르게 처리
int loadArgc(LPSTR   lpCmdLine, CAtumApplication *pD3dApp)
{	
	if(__argc != 14 && __argc != 18 && __argc != 13 && __argc != 17)
	{
		DBGOUT("[Error] Parameter Count Error, Count(%d)(%s)\n", __argc, lpCmdLine);
		return FALSE;
	}

	char szTemp[20] = {0,};
	
	
	if( __argc == 14 )
	{
#ifdef MULTI_LOADER_HSSON
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %d %s", pD3dApp->m_strFieldIP, &pD3dApp->m_nFieldPort, pD3dApp->m_strChatIP, &pD3dApp->m_nChatPort, pD3dApp->m_strUserID,
			pD3dApp->m_strUserPassword, &pD3dApp->m_IsFullMode, &pD3dApp->m_nWidth, &pD3dApp->m_nHeight, &pD3dApp->m_bDegree,
			&pD3dApp->m_bMovePlayer, 
			&pD3dApp->m_bArgcTestServer,
			szTemp);
		
		if( strcmp( szTemp, "DEVELOP" ) != 0 )
			return 0;
#else // MULTI_LOADER_HSSON
		return 0;
#endif // MULTI_LOADER_HSSON
	}
	else if(__argc == 13)	// 2005-08-05 by cmkwon, for JPN release
	{
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %d", 
			pD3dApp->m_strFieldIP, &pD3dApp->m_nFieldPort, pD3dApp->m_strChatIP, &pD3dApp->m_nChatPort, pD3dApp->m_strUserID,
			pD3dApp->m_strUserPassword, &pD3dApp->m_IsFullMode, &pD3dApp->m_nWidth, &pD3dApp->m_nHeight, &pD3dApp->m_bDegree, 
			&pD3dApp->m_bMovePlayer, &pD3dApp->m_bArgcTestServer);
	}
#ifdef KOR_YEDANG_WEB_LAUNCHER_HSSON	
	else if(__argc == 17)
	{
		int nSeed = 0;
		int nType = 0;
		char Reserve1[20] = {0,};
		char Reserve2[20] = {0,};
		char strMutexID[1024] = {0,};
		
		DbgOut("%s\n", lpCmdLine);
		sscanf(lpCmdLine,"%s %d %s %d %d %d %d %d %s %s %d %d %s %s %d %d", 
			pD3dApp->m_strFieldIP, &pD3dApp->m_nFieldPort, pD3dApp->m_strChatIP, &pD3dApp->m_nChatPort, &pD3dApp->m_nWidth, 
			&pD3dApp->m_nHeight, &pD3dApp->m_bDegree, &pD3dApp->m_IsFullMode, pD3dApp->m_strUserID, pD3dApp->m_strUserPassword, 
			&nSeed, &nType, Reserve1, Reserve2, &pD3dApp->m_bMovePlayer,
			&pD3dApp->m_bArgcTestServer);
#ifdef  CHECK_SUM_ON 
		HANDLE hMutex = NULL;
		sprintf(strMutexID, "%s%d", pD3dApp->m_strUserPassword, nSeed);
		hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, (LPTSTR)strMutexID);
		if(hMutex == NULL)
		{
			DbgOut("[Error] Mutex Error\n");
			return FALSE;
		}	
		// 2006-10-18 by ispark, ReleaseMutex() -> CloseHandle()로 변경
		CloseHandle(hMutex);
		
#endif
	}
#endif //YEDANG_WEB_LAUNCHER
	else
	{
		int nSeed = 0;
		char szAccount[SIZE_MAX_ACCOUNT_NAME];
		char szEncAccount[MGAME_MAX_PARAM_STRING_SIZE];
		char szEncPassword[MGAME_MAX_PARAM_STRING_SIZE];
		/*
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %s %d %s %s %s ", pD3dApp.m_strFieldIP, &pD3dApp.m_nFieldPort, pD3dApp.m_strChatIP, &pD3dApp.m_nChatPort,
		*/
		
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %d %s %d %s %s %s ", 
			pD3dApp->m_strFieldIP, &pD3dApp->m_nFieldPort, pD3dApp->m_strChatIP, &pD3dApp->m_nChatPort, pD3dApp->m_strUserID, 
			pD3dApp->m_strUserPassword, &pD3dApp->m_IsFullMode, &pD3dApp->m_nWidth, &pD3dApp->m_nHeight, &pD3dApp->m_bDegree,
			&pD3dApp->m_bMovePlayer,&pD3dApp->m_bArgcTestServer, szTemp, &nSeed, szAccount, 
			szEncAccount, szEncPassword);
		
		// Mutex Check
		HANDLE hMutex = NULL;	
		hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, (LPTSTR)szEncPassword);  // 암호화된패스워드값을 넣는다
		if(hMutex == NULL)
		{
			DBGOUT("[Error] Mutex Error\n");
			return FALSE;
		}	
		// 2006-10-18 by ispark, ReleaseMutex() -> CloseHandle()로 변경
		CloseHandle(hMutex);
		
		// ExcuteType Check
		if(strcmp(szTemp, "INET"))
		{
			DBGOUT("[Error] Excute Type Error, Type(%s)\n", szTemp);
			return FALSE;
		}
		
		char szDecryptedID[MGAME_MAX_PARAM_STRING_SIZE];	
		strncpy(szDecryptedID, (char *)decrypt((unsigned char*)szEncAccount, nSeed), MGAME_MAX_PARAM_STRING_SIZE);
		
		// ID Check
		if(strcmp(szAccount, szDecryptedID))
		{
			DBGOUT("[Error] Decryption ID Error, DecryptedID(%s)\n", szDecryptedID);
			return FALSE;
		}
		
	}
	DbgOut("loadArgc __argc[%d] TRUE[%s] TestServerArgc[%d] \n", __argc, lpCmdLine, pD3dApp->m_bArgcTestServer);
	return true;
}
// END 2014-01-06 by bhsohn Xtrap 테스트서버 키 다르게 처리


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	CAtumApplication pD3dApp;

	pD3dApp.b_CanadaMutex = true;// 2012-09-17 by jhahn	캐나다 핵쉴드 제거 버전
	g_cCustomOptimizer.AutoLauncher();

	// 2013-05-03 by bhsohn 핵쉴드 Dump 안나오는 현상 처리
	// 2010-09-29 by jskim, 덤프 남기도록 수정 
//	SetUnhandledExceptionFilter(Exception_Minidump);
	// end 2010-09-29 by jskim, 덤프 남기도록 수정 
	if(GAMEGUARD_TYPE != USE_GAMEGUARD_AHNLAB_HACKSHIELD)
	{		
		SetUnhandledExceptionFilter(Exception_Minidump);		
	}
	// END 2013-05-03 by bhsohn 핵쉴드 Dump 안나오는 현상 처리


	// 2012-09-17 by jhahn	캐나다 핵쉴드 제거 버전
#ifdef SC_HACKSHIELD_REMOVE_JHSEOL_JHAHN
	{
		HANDLE hMutexTemp = NULL;	
			
		hMutexTemp = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, "CANADA_HACK_SHIELD");
		if(hMutexTemp == NULL)
		{
			pD3dApp.b_CanadaMutex = true;
		}	
		else
		{
			pD3dApp.b_CanadaMutex = false;
		}
		
		
		CloseHandle(hMutexTemp);
		//end 2012-09-17 by jhahn	캐나다 핵쉴드 제거 버전
		
	}
#endif
	
	
	if(g_hMutexMonoInstance)
		return 0;

	g_hMutexMonoInstance = CreateMutex(NULL, TRUE, WINDOWTEXT_NAME_CLIENT);

	if(NULL == g_hMutexMonoInstance)
		return 0;

#ifdef MULTI_LOADER_HSSON

#else // MULTI_LOADER_HSSON
	if(ERROR_ALREADY_EXISTS == ::GetLastError())
	{
		MessageBox(NULL, "ERROR : \nApplication is running already...", WINDOWTEXT_NAME_CLIENT, MB_OK);
		return 0;
	}
#endif // MULTI_LOADER_HSSON

	// 2014-01-06 by bhsohn Xtrap 테스트서버 키 다르게 처리
	if(!loadArgc(lpCmdLine, &pD3dApp))
	{
		DbgOut("Fail Load Argc");
		return FALSE;
	}
	/*
	// 2007-07-26 by bhsohn 예당 윈도우 모드만 되는 버그 수정
	//if(__argc != 12 && __argc != 16 && __argc != 11 && __argc != 14)
	if(__argc != 13 && __argc != 17 && __argc != 12 && __argc != 16)
	{
		DBGOUT("[Error] Parameter Count Error, Count(%d)(%s)\n", __argc, lpCmdLine);
		return FALSE;
	}

	char szTemp[20];


	if( __argc == 13 )
	{
#ifdef MULTI_LOADER_HSSON
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %s", pD3dApp.m_strFieldIP, &pD3dApp.m_nFieldPort, pD3dApp.m_strChatIP, &pD3dApp.m_nChatPort, pD3dApp.m_strUserID,
				pD3dApp.m_strUserPassword, &pD3dApp.m_IsFullMode, &pD3dApp.m_nWidth, &pD3dApp.m_nHeight, &pD3dApp.m_bDegree,&pD3dApp.m_bMovePlayer, szTemp);
		
		if( strcmp( szTemp, "DEVELOP" ) != 0 )
			return 0;
#else // MULTI_LOADER_HSSON
		return 0;
#endif // MULTI_LOADER_HSSON
	}
	else if(__argc == 12)	// 2005-08-05 by cmkwon, for JPN release
	{
		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d", pD3dApp.m_strFieldIP, &pD3dApp.m_nFieldPort, pD3dApp.m_strChatIP, &pD3dApp.m_nChatPort, pD3dApp.m_strUserID,
				pD3dApp.m_strUserPassword, &pD3dApp.m_IsFullMode, &pD3dApp.m_nWidth, &pD3dApp.m_nHeight, &pD3dApp.m_bDegree, &pD3dApp.m_bMovePlayer);
	}
#ifdef KOR_YEDANG_WEB_LAUNCHER_HSSON
	// 2006-10-02 by ispark, 한국 웹 런처
	// 2007-07-26 by bhsohn 예당 윈도우 모드만 되는 버그 수정
	//else if(__argc == 14)
	else if(__argc == 16)
	{
		int nSeed = 0;
		int nType = 0;
		char Reserve1[20] = {0,};
		char Reserve2[20] = {0,};
		char strMutexID[1024] = {0,};

		DbgOut("%s\n", lpCmdLine);
		sscanf(lpCmdLine,"%s %d %s %d %d %d %d %d %s %s %d %d %s %s %d", pD3dApp.m_strFieldIP, &pD3dApp.m_nFieldPort, pD3dApp.m_strChatIP, &pD3dApp.m_nChatPort,
						&pD3dApp.m_nWidth, &pD3dApp.m_nHeight, &pD3dApp.m_bDegree,						
						&pD3dApp.m_IsFullMode,	// 2007-07-26 by bhsohn 예당 윈도우 모드만 되는 버그 수정
						pD3dApp.m_strUserID, pD3dApp.m_strUserPassword, &nSeed, &nType, Reserve1, Reserve2, &pD3dApp.m_bMovePlayer);
#ifdef  CHECK_SUM_ON 
		HANDLE hMutex = NULL;
		sprintf(strMutexID, "%s%d", pD3dApp.m_strUserPassword, nSeed);
		hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, (LPTSTR)strMutexID);
		if(hMutex == NULL)
		{
			DbgOut("[Error] Mutex Error\n");
			return FALSE;
		}	
		// 2006-10-18 by ispark, ReleaseMutex() -> CloseHandle()로 변경
		CloseHandle(hMutex);

#endif
	}
#endif //YEDANG_WEB_LAUNCHER
	else
	{
		int nSeed = 0;
		char szAccount[SIZE_MAX_ACCOUNT_NAME];
		char szEncAccount[MGAME_MAX_PARAM_STRING_SIZE];
		char szEncPassword[MGAME_MAX_PARAM_STRING_SIZE];

		sscanf(lpCmdLine,"%s %d %s %d %s %s %d %d %d %d %d %s %d %s %s %s ", pD3dApp.m_strFieldIP, &pD3dApp.m_nFieldPort, pD3dApp.m_strChatIP, &pD3dApp.m_nChatPort,
						pD3dApp.m_strUserID, pD3dApp.m_strUserPassword, &pD3dApp.m_IsFullMode, &pD3dApp.m_nWidth, &pD3dApp.m_nHeight, &pD3dApp.m_bDegree,
						&pD3dApp.m_bMovePlayer,	szTemp, &nSeed, szAccount, szEncAccount, szEncPassword);

		// Mutex Check
		HANDLE hMutex = NULL;	
		hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, (LPTSTR)szEncPassword);  // 암호화된패스워드값을 넣는다
		if(hMutex == NULL)
		{
			DBGOUT("[Error] Mutex Error\n");
			return FALSE;
		}	
		// 2006-10-18 by ispark, ReleaseMutex() -> CloseHandle()로 변경
		CloseHandle(hMutex);
		
		// ExcuteType Check
		if(strcmp(szTemp, "INET"))
		{
			DBGOUT("[Error] Excute Type Error, Type(%s)\n", szTemp);
			return FALSE;
		}

		char szDecryptedID[MGAME_MAX_PARAM_STRING_SIZE];	
		strncpy(szDecryptedID, (char *)decrypt((unsigned char*)szEncAccount, nSeed), MGAME_MAX_PARAM_STRING_SIZE);
		
		// ID Check
		if(strcmp(szAccount, szDecryptedID))
		{
			DBGOUT("[Error] Decryption ID Error, DecryptedID(%s)\n", szDecryptedID);
			return FALSE;
		}

	}
	*/
	// END 2014-01-06 by bhsohn Xtrap 테스트서버 키 다르게 처리	

#ifdef ONLY_FULL_WINDOW_HSSON
		pD3dApp.m_IsFullMode = TRUE;
#endif // ONLY_FULL_WINDOW_HSSON

// 2012-09-17 by jhahn	캐나다 핵쉴드 제거 버전

		if (pD3dApp.b_CanadaMutex)
		{
			// 2009-01-22 by bhsohn Xign Code시, Sleep(3000)추가
			if(!pD3dApp.StartGameGuard())
			{
				pD3dApp.CloseGameGuard();
				return FALSE;
			}		
			// end 2009-01-22 by bhsohn Xign Code시, Sleep(3000)추가
		}
		// 2013-05-03 by bhsohn 핵쉴드 Dump 안나오는 현상 처리		
		if(GAMEGUARD_TYPE == USE_GAMEGUARD_AHNLAB_HACKSHIELD)
		{		
			SetUnhandledExceptionFilter(Exception_Minidump);		
		}
		// END 2013-05-03 by bhsohn 핵쉴드 Dump 안나오는 현상 처리

//end 2012-09-17 by jhahn	캐나다 핵쉴드 제거 버전
	// 2007-12-21 by dgwoo 창모드 지원
	DbgOut("FullMode = %d\n",pD3dApp.m_IsFullMode);
	if( FAILED( pD3dApp.Create( hInstance ) ) )
		return 0;
// 2008-11-28 by bhsohn XignCode추가
	///////// 게임 가드 설정///////// 
//#if defined(_DEBUG) || defined(GAMEFORGE_RELEASE) || defined(WORLD_RELEASE) || defined(LANGUAGE_RUSSIA)// 2008-04-30 by bhsohn 태국 버전 추가
//#if defined(_DEBUG) || defined(LANGUAGE_RUSSIA)
//#else
//	// 2006-06-05 by ispark
//	if(!pD3dApp.HS_Start())
//	{
//		DBGOUT("HShield Error\n");
//		pD3dApp.HS_Close();
//		return FALSE;
//	}
//#endif
	// 2009-01-22 by bhsohn Xign Code시, Sleep(3000)추가
// 	if(!pD3dApp.StartGameGuard())
// 	{
// 		pD3dApp.CloseGameGuard();
// 		return FALSE;
// 	}	
	// end 2008-11-28 by bhsohn XignCode추가
	// end 2009-01-22 by bhsohn Xign Code시, Sleep(3000)추가

	// 2009-01-28 by bhsohn nProtector 게임 가드 추가
	if(!pD3dApp.SetGameGuardHWND())
	{
		pD3dApp.CloseGameGuard();
		return FALSE;
	}	
	// end 2009-01-28 by bhsohn nProtector 게임 가드 추가

	g_input.InitInput();

	INT nResult;

// 2010-09-29 by jskim, 덤프 남기도록 수정 
// #ifdef _DEBUG
// 	nResult = pD3dApp.Run();
// #else
// 	try
// 	{
// 		nResult = pD3dApp.Run();
// 	}
// 
// 	catch(...)
// 	{
// 		DBGOUT("Extations Error\n");
// 		// 2008-11-28 by bhsohn XignCode추가
// 		//pD3dApp.HS_Close();
// 		pD3dApp.CloseGameGuard();
// 		// end 2008-11-28 by bhsohn XignCode추가
// 	}
// #endif
//#ifdef _DEBUG
	nResult = pD3dApp.Run();
//#else
//	try
//	{
//		nResult = pD3dApp.Run();
//	}

//	catch(...)
//	{
		DBGOUT("Extations Error\n");
		// 2008-11-28 by bhsohn XignCode추가
		//pD3dApp.HS_Close();
		pD3dApp.CloseGameGuard();
		// end 2008-11-28 by bhsohn XignCode추가
//	}
//#endif
// end 2010-09-29 by jskim, 덤프 남기도록 수정
	CloseHandle(g_hMutexMonoInstance);

	// 2008-11-28 by bhsohn XignCode추가
// 2008-09-19 by bhsohn Canada HackShield
//#if	defined(_DEBUG) || defined(GAMEFORGE_RELEASE) || defined(WORLD_RELEASE)|| defined(LANGUAGE_RUSSIA)// 2008-04-30 by bhsohn 태국 버전 추가
//#if	defined(_DEBUG) || defined(LANGUAGE_RUSSIA)// 2008-04-30 by bhsohn 태국 버전 추가
//#else
//	// 2006-06-05 by ispark
//	pD3dApp.HS_Close();	
//#endif
	//pD3dApp.CloseGameGuard();	
	// end 2008-11-28 by bhsohn XignCode추가

	// 2006-07-06 by ispark, 강제 종료이면서 에러 메세지를 가지고 있다면
	if(pD3dApp.m_bShutDown && strlen(pD3dApp.m_strMsgLastError))
	{
		MessageBox(NULL, pD3dApp.m_strMsgLastError,STRMSG_WINDOW_TEXT, MB_OK);
	}
	return nResult;
}
