// PreServer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "PreGlobal.h"
#include "PreIOCP.h"
#include "PreIOCPSocket.h"
#include "VMemPool.h"
#include "SPToMPWinSocket.h"		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 

// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - �ӽÿ�
// 2009-12-28 by cmkwon, ����ȸ�� IP ���� - ����(121.134.114.)

// start 2011-06-22 by hskim, �缳 ���� ����
// �������� �������� PreGlobal.h �� �̵�
//#ifdef  S_AUTHENTICATION_SERVER_HSKIM		// 2011-01-26 by hskim, ���� ���� ����
//#define MasangPreServerIP		"c3.eyehs.kr"		// �׽�Ʈ�� URL
//#define MasangPreServerPort		14999
//#else
//#define MasangPreServerIP		"61.39.170.131"
//#define MasangPreServerPort		15100
//#endif
// end 2011-06-22 by hskim, �缳 ���� ����

// 2012-04-20 by hskim �̴ϴ��� ��� �߰�
#ifdef S_MINI_DUMP_HSKIM
#include "dbgHelp.h"
#pragma comment(lib, "dbghelp.lib")


LONG __stdcall ExceptionHandler(_EXCEPTION_POINTERS* pExceptionInfo)
{
    char fileName[MAX_PATH];
    GetModuleFileName(NULL, fileName, sizeof(fileName));
    char* ext = strrchr(fileName, '.');

#ifdef S_SERVER_CRASH_FILENAME_ADD_INFO
	// 2013-05-28 by hskim, �̴� ���� ���� �̸��� �ð� �߰�
	ATUM_DATE_TIME	CurrentTime(TRUE);
	sprintf(ext ? ext : fileName+strlen(fileName), "_%s.dmp", CurrentTime.GetFileDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)));
	// end 2013-05-28 by hskim, �̴� ���� ���� �̸��� �ð� �߰�
#else
    strcpy(ext ? ext : fileName+strlen(fileName), ".dmp");
#endif

    char szTemp[256];
    wsprintf(szTemp, "PreServer Crash !! : Create dump file (Exception 0x%08x arised)", pExceptionInfo->ExceptionRecord->ExceptionCode);

    HANDLE hProcess = GetCurrentProcess();
    DWORD dwProcessID = GetCurrentProcessId();
    HANDLE hFile = CreateFile(fileName, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    MINIDUMP_EXCEPTION_INFORMATION eInfo;
    eInfo.ThreadId = GetCurrentThreadId();
    eInfo.ExceptionPointers = pExceptionInfo;
    eInfo.ClientPointers = FALSE;

    MiniDumpWriteDump(hProcess, dwProcessID, hFile, MiniDumpWithFullMemory, pExceptionInfo ? &eInfo : NULL, NULL, NULL);

// 2012-10-18 by mspark, �������� ���� �浹 �� �޽��� �ڽ� ������ �ʴ� �۾�
#ifdef S_SERVER_CRASH_MSGBOX_REMOVE_MSPARK
	//MessageBox(NULL, szTemp, "ERROR", MB_TOPMOST | MB_ICONSTOP);
#else
	MessageBox(NULL, szTemp, "ERROR", MB_TOPMOST | MB_ICONSTOP);
#endif
// end 2012-10-18 by mspark, �������� ���� �浹 �� �޽��� �ڽ� ������ �ʴ� �۾�

	return EXCEPTION_EXECUTE_HANDLER;
}
// end 2012-04-20 by hskim �̴ϴ��� ��� �߰�
#endif
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
 	// TODO: Place code here.
	g_pPreGlobal = new CPreGlobal;

// 2012-04-20 by hskim �̴ϴ��� ��� �߰�
#ifdef S_MINI_DUMP_HSKIM
	SetUnhandledExceptionFilter(&ExceptionHandler);
#endif
// end 2012-04-20 by hskim �̴ϴ��� ��� �߰�
	
	if(FALSE == g_pPreGlobal->InitGlobal("Pre Server"))
	{
		return FALSE;
	}

	// set config root path
	g_pPreGlobal->SetConfigRootPath();
	g_pPreGlobal->GetSystemLogManagerPtr()->InitLogManger(TRUE, "PreSystem", (char*)(string(CONFIG_ROOT) + "../log/SystemLog/").c_str());

	g_pPreGlobal->WriteSystemLogEX(TRUE, "Pre Server Start\r\n");

	if(FALSE == CIOCP::SocketInit())
	{
		g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] WinaMain SocketInit error!!\r\n");
		return FALSE;
	}

	CVMemPool::vmPoolAddObject(sizeof(COverlapped), SIZE_MAX_PRESERVER_SESSION * 10);
	CVMemPool::vmPoolAddObject(sizeof(CSendPacket), 100);		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
	CVMemPool::vmPoolAddObject(sizeof(CRecvPacket), 100);		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
	if(CVMemPool::vmPoolInit() == FALSE)
	{
		g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] WinaMain vmPoolInit error!!\r\n");
		return FALSE;
	}

#if defined(SERVICE_TYPE_TAIWANESE_SERVER_1)
	// 2008-10-08 by cmkwon, �븸 Netpower_Tpe �ܺ����� ���� - 
	CoInitialize(NULL);			// COM �ʱ�ȭ
#endif

	g_pPreGlobal->WndRegisterClass(hInstance, IDI_PRESERVER, _T("Pre Server"));
	// Perform application initialization:
	if (!g_pPreGlobal->InitInstance (hInstance, nCmdShow, _T("Pre Server"), _T("Pre Server")))
	{
		return FALSE;
	}

	///////////////////////////////////////////////////////////////////////////
	// Main message loop:
	MSG			msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CVMemPool::vmPoolClean();
	CIOCP::SocketClean();

	g_pPreGlobal->WriteSystemLogEX(TRUE, "Pre Server End\r\n\r\n\r\n");

	SAFE_DELETE(g_pPreGlobal);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		{
			SetLastError(0);
// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - �Ʒ��� ���� ���� ��, g_pPreGlobal->InitServerSocket() ó���� MasangPreServer �� ���� �� ó���ϰ� ������
// 			if(g_pPreGlobal->LoadConfiguration())
// 			{
// 				if(g_pPreGlobal->InitServerSocket())
// 				{
// 					g_pPreGlobal->SetMainWndHandle(hWnd);
// 					g_pPreGlobal->StartTimerTraffic();
// 					g_pPreGlobal->StartTimerAliveCheck();
// 				}
// 			}
// 			else
// 			{
// 				MessageBox(hWnd, "LoadConfiguration Error", "ERROR", MB_OK);
// 				exit(0);
// 			}			
			
			// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
			g_pPreGlobal->SetMainWndHandle(hWnd);

			if(FALSE == g_pPreGlobal->LoadConfiguration())
			{
 				MessageBox(hWnd, "LoadConfiguration Error", "ERROR", MB_OK);
 				exit(0);
				break;
			}

			// 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����
			char szServerName[SIZE_MAX_STRING_128] = { 0, };
			sprintf(szServerName, "PreServer_%s", g_pPreGlobal->GetServerGroupName());
			SetWindowText(hWnd, szServerName);
			// end 2013-06-12 by hskim, �ϳ��� OS ���� ���� ���� ����

#ifdef S_AUTHENTICATION_SERVER_HSKIM		// 2011-01-26 by hskim, ���� ���� ����
			// _ATUM_AUTHENTICATION_SERVER ���ǽ� ���� ���������� ��� ���� (Authentication Server ������Ʈ�� ���� ����)
#else
			if(0 == stricmp(MasangPreServerIP, g_pPreGlobal->GetPublicIPLocal()))				
			{// 2008-02-22 by cmkwon, �ڽ��� MasangPreServer �̸� �ٷ� ���񽺸� �����Ѵ�.

				// start 2011-06-22 by hskim, �缳 ���� ����
				if(NULL != g_pPreGlobal->GetGIOCP() ) 
				{
					break;
				}
				// end 2011-06-22 by hskim, �缳 ���� ����

				if(FALSE == g_pPreGlobal->InitServerSocket())
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] WndProc InitServerSocket_ error !!");
				}
				else
				{
					g_pPreGlobal->StartTimerTraffic();
					g_pPreGlobal->StartTimerAliveCheck();
				}
				break;
			}
#endif

			// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
			if(FALSE == g_pPreGlobal->createPreToAllServer(hWnd))
			{
				g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] createPreToAllServer_ error !!");
				exit(0);
				break;
			}
			if(FALSE == g_pPreGlobal->connectBySPToMPWinSoc(MasangPreServerIP, MasangPreServerPort))
			{
// start 2011-07-26 by hskim, ���� ���� ����
//////////
// ����
// 				g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] connectBySPToMPWinSoc_ error !! IP(%s) Port(%d)", MasangPreServerIP, MasangPreServerPort);
// 				exit(0);
//				break;

//////////
// ����
#ifdef S_AUTHENTICATION_SERVER_2ND_HSKIM
 				g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] connectBySPToMPWinSoc_ error !! IP(%s) Port(%d)", MasangPreServerIP, MasangPreServerPort);
 				exit(0);
				break;
#else
				// �����ε� ���� ���� �� ���� �ٷ� ����

				if(NULL != g_pPreGlobal->GetGIOCP() ) 
				{
					break;
				}

				if(FALSE == g_pPreGlobal->InitServerSocket())
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] WndProc InitServerSocket_ error !!");
				}
				else
				{
					g_pPreGlobal->StartTimerTraffic();
					g_pPreGlobal->StartTimerAliveCheck();
				}
				break;
#endif
// end 2011-07-26 by hskim, ���� ���� ����
			}

			// 2012-10-05 by jhseol, NPlay PC�� ��� - ��ü ���� �� NPlay ���� Connect
#ifdef S_NPLAY_PCBANG_MODULE_JHSEOL
			if( 0 != stricmp("", g_pPreGlobal->GetNPlayServerIP_Real() ) )
			{
				if( FALSE == g_pPreGlobal->createNPlayPCBangModule(hWnd, g_pPreGlobal->GetNPlayServerIP_Real(), g_pPreGlobal->GetNPlayServerIP_BackUP() ) )
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] createNPlayPCBangModule_ error !!");
				}
				if( FALSE == g_pPreGlobal->connectByNPlayPCBangModuleWinSoc(g_pPreGlobal->GetNPlayServerIP_Real() ,NPLAY_SERVER_PORT) )
				{
					g_pPreGlobal->WriteSystemLogEX(TRUE, "[ERROR] connectByNPlayPCBangModuleWinSoc_ Connect Failed !!");
				}
			}
			// end 2012-10-05 by jhseol, NPlay PC�� ��� - ��ü ���� �� NPlay ���� Connect
#endif
			
		}
		break;
	case WM_COMMAND:
		{
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		{
			switch(wParam)
			{
			case TIMERID_TRAFFIC:
				{
					g_pPreGlobal->CheckServerThread();
					g_pPreGlobal->CalculateIOCPTraffic();
				}
				break;
			case TIMERID_ALIVE_CHECK:
				{
					// 2005-01-04 by cmkwon, ������ ������Ʈ�� �����ؾ���, ��ó���� AlivePacket�� �������� �ʴ´�
					g_pPreGlobal->CheckClientAlive();
				}
				break;
			}
		}
		break;
	case WM_DESTROY:
		{
			g_pPreGlobal->EndServerSocket();
			PostQuitMessage(0);
		}
		break;
	case WM_ASYNC_EVENT:	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
		{
			g_pPreGlobal->OnAsyncEventOfSPToMPWinSoc(wParam, lParam);
		}
		break;
	case WM_PACKET_NOTIFY:	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
		{
			g_pPreGlobal->OnPacketNotifyOfSPToMPWinSoc(LOWORD(wParam), HIWORD(wParam));
		}
		break;
		// 2012-10-05 by jhseol, NPlay pc�� ���
	case WM_ASYNC_EVENT_BY_NPLAY:
		{
			g_pPreGlobal->OnAsyncEventOfNPlayPCBangModuleWinSoc(wParam, lParam);
		}
		break;
	case WM_PACKET_NOTIFY_BY_NPLAY:
		{
			g_pPreGlobal->OnPacketNotifyOfNPlayPCBangModuleWinSoc(LOWORD(wParam), HIWORD(wParam));
		}
		break;
		// end 2012-10-05 by jhseol, NPlay pc�� ���
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
   return 0;
}
