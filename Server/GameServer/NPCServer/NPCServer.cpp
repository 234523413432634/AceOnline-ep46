// NPCServer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "NPCGlobal.h"
#include "NPCIOCP.h"
#include "NPCIOCPSocket.h"
#include "config.h"
#include "VMemPool.h"
#include "N2FSocket.h"
#include "Monster.h"

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
#ifdef ARENA
    wsprintf(szTemp, "ArenaNPCServer Crash !! : Create dump file (Exception 0x%08x arised)", pExceptionInfo->ExceptionRecord->ExceptionCode);
#else
    wsprintf(szTemp, "NPCServer Crash !! : Create dump file (Exception 0x%08x arised)", pExceptionInfo->ExceptionRecord->ExceptionCode);
#endif
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
	g_pNPCGlobal = new CNPCGlobal;

// 2012-04-20 by hskim �̴ϴ��� ��� �߰�
#ifdef S_MINI_DUMP_HSKIM
	SetUnhandledExceptionFilter(&ExceptionHandler);
#endif
// end 2012-04-20 by hskim �̴ϴ��� ��� �߰�
#ifdef ARENA
	if(FALSE == g_pNPCGlobal->InitGlobal("Arena NPC Server"))
#else	
	if(FALSE == g_pNPCGlobal->InitGlobal("NPC Server"))
#endif //ARENA	
	{
		return FALSE;
	}

 	// TODO: Place code here.
	MSG			msg;

	// set config root path
	g_pNPCGlobal->SetConfigRootPath();

#ifdef ARENA
	g_pNPCGlobal->GetSystemLogManagerPtr()->InitLogManger(TRUE, "ArenaNPCSystem", (char*)(string(CONFIG_ROOT) + "../log/SystemLog/").c_str());
#else
	g_pNPCGlobal->GetSystemLogManagerPtr()->InitLogManger(TRUE, "NPCSystem", (char*)(string(CONFIG_ROOT) + "../log/SystemLog/").c_str());
#endif //ARENA
#if defined(DEV)
	CNPCGlobal::WriteSystemLogEX(TRUE, "========================================\r\n");
	CNPCGlobal::WriteSystemLogEX(TRUE, "==== NPC SERVER DEVELOPMENT VERSION ====\r\n");
	CNPCGlobal::WriteSystemLogEX(TRUE, "========================================\r\n");
#endif
	char szSystemLog[256];
#ifdef ARENA
	sprintf(szSystemLog, "Arena NPC Server Start\r\n\r\n");
#else
	sprintf(szSystemLog, "NPC Server Start\r\n\r\n");
#endif
	g_pNPCGlobal->WriteSystemLog(szSystemLog);

	if(FALSE == CIOCP::SocketInit())
	{
		return FALSE;
	}

	CVMemPool::vmPoolAddObject(sizeof(ActionInfo), SIZE_MAX_FIELDSERVER_SESSION * 5);
	CVMemPool::vmPoolAddObject(sizeof(COverlapped), SIZE_MAX_UDP_CHANNEL_SESSION * 20);		// 2010-04-09 by cmkwon, NPCServer �޸� �������� ������ - ���� ���Ǵ� 100��
	CVMemPool::vmPoolAddObject(sizeof(EVENTINFO), SIZE_MAX_UDP_CHANNEL_SESSION*200);			// 2010-04-14 by cmkwon, ���� �޸� ���� ���� ���� - �ʴ� 200���� Ÿ�� �̺�Ʈ ���� ���� ����
	CVMemPool::vmPoolAddObject(sizeof(CSendPacket), 1000);
	CVMemPool::vmPoolAddObject(sizeof(CRecvPacket), 100);	

	if(CVMemPool::vmPoolInit() == FALSE)
	{
		return FALSE;
	}
#ifdef ARENA
	g_pNPCGlobal->WndRegisterClass(hInstance, IDI_NPCSERVER, "Arena NPC Server");
#else	
	g_pNPCGlobal->WndRegisterClass(hInstance, IDI_NPCSERVER, "NPC Server");
#endif //ARENA	
	// Perform application initialization:
#ifdef ARENA
	if (FALSE == g_pNPCGlobal->InitInstance (hInstance, nCmdShow, "Arena NPC Server", "Arena NPC Server"))
#else	
	if (FALSE == g_pNPCGlobal->InitInstance (hInstance, nCmdShow, "NPC Server", "NPC Server"))
#endif //ARENA	
	{
		return FALSE;
	}

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CVMemPool::vmPoolClean();
	CIOCP::SocketClean();
#ifdef ARENA
	sprintf(szSystemLog, "Arena NPC Server End\r\n\r\n\r\n");
#else
	sprintf(szSystemLog, "NPC Server End\r\n\r\n\r\n");
#endif
	DBGOUT(szSystemLog);
	g_pNPCGlobal->WriteSystemLog(szSystemLog);

	SAFE_DELETE(g_pNPCGlobal);
	return msg.wParam;
}


//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		{
			HRESULT hr;
			if( FAILED(hr = g_pNPCGlobal->m_D3DApp.Create(g_pNPCGlobal->GetInstanceHandle(), hWnd)) )
			{
				g_pNPCGlobal->WriteSystemLogEX(TRUE, "====================================================================================================\r\n");
				g_pNPCGlobal->WriteSystemLogEX(TRUE, STRMSG_S_N2NOTIFY_0000);
				g_pNPCGlobal->WriteSystemLogEX(TRUE, "====================================================================================================\r\n");
			}

			SetLastError(0);
			CString sLoadCfgResult = g_pNPCGlobal->LoadConfiguration1();
			if("OK" == sLoadCfgResult)
			{
				
				g_pNPCGlobal->CreateN2FSocket(hWnd);
				g_pNPCGlobal->GetN2FSocket()->Connect(g_pNPCGlobal->GetIPFieldServer(), g_pNPCGlobal->GetPortFieldServer());
			}
			else
			{
				CNPCGlobal::WriteSystemLogEX(TRUE, sLoadCfgResult);
				MessageBox(hWnd, sLoadCfgResult, "ERROR", MB_OK|MB_ICONERROR);
			}
		}
		break;
	case WM_N2F_ASYNC_EVENT:
		{
			if(g_pNPCGlobal->GetN2FSocket())
			{
				g_pNPCGlobal->GetN2FSocket()->OnAsyncEvent(lParam);
			}
		}
		break;
	case WM_N2F_PACKET_NOTIFY:
		{
			switch(LOWORD(wParam))
			{
			case CWinSocket::WS_CONNECTED:
				{
					g_pNPCGlobal->EndTimerReconnect();

					if(HIWORD(wParam) == FALSE)
					{
						char	szSystemLog[256];
						sprintf(szSystemLog, "[Error] WndProc(), Can't connect to FieldServer[%15s:%4d] Reconnect\r\n",
							g_pNPCGlobal->GetIPFieldServer(), g_pNPCGlobal->GetPortFieldServer());
						g_pNPCGlobal->WriteSystemLog(szSystemLog);
						DBGOUT(szSystemLog);

						g_pNPCGlobal->StartTimerReconnect();
					}
					else
					{
						DBGOUT(STRMSG_S_N2FIELDCONNECT_0000);

						int nSendType = T_FN_NPCSERVER_START;
						g_pNPCGlobal->GetN2FSocket()->Write((char*)&nSendType, SIZE_FIELD_TYPE_HEADER);
					}
				}
				break;
			case CWinSocket::WS_RECEIVED:
				{
					char * pPacket = NULL;
					int len,nType;
					g_pNPCGlobal->GetN2FSocket()->Read(&pPacket, len);
					if(pPacket)
					{
						nType = 0;
						memcpy(&nType, pPacket, SIZE_FIELD_TYPE_HEADER);
						switch(nType)
						{
						case T_FN_NPCSERVER_START_OK:
							{
								if(g_pNPCGlobal->InitServerSocket())
								{
									g_pNPCGlobal->GetN2FSocket()->SetNPCIOCP((CNPCIOCP*)g_pNPCGlobal->GetGIOCP());
									g_pNPCGlobal->StartTimerTraffic();
									g_pNPCGlobal->StartTimerAliveCheck();
								}
							}
							break;
						case T_FN_NPCSERVER_SUMMON_JACO_MONSTER:
							{
							}
							break;
						}
						SAFE_DELETE(pPacket);		// 2006-04-19 by cmkwon
					}

				}
				break;
			case CWinSocket::WS_CLOSED:
				{
					char	szSystemLog[256];
					sprintf(szSystemLog, STRMSG_S_N2FIELDCONNECT_0001,
						g_pNPCGlobal->GetIPFieldServer(), g_pNPCGlobal->GetPortFieldServer());
					g_pNPCGlobal->WriteSystemLog(szSystemLog);
					DBGOUT(szSystemLog);

					g_pNPCGlobal->EndServerSocket();
					g_pNPCGlobal->StartTimerReconnect();
				}
				break;
			case CWinSocket::WS_ERROR:
				{
				}
				break;
			}
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
					g_pNPCGlobal->CheckServerThread();
					g_pNPCGlobal->CalculateIOCPTraffic();
				}
				break;
			case TIMERID_ALIVE_CHECK:
				{
					//////////////////////////////////////////////////////
					// Field Server�� Alive�� �����Ѵ�
					if(g_pNPCGlobal->GetN2FSocket()
						&& g_pNPCGlobal->GetN2FSocket()->IsConnected())
					{
						int nSendType = T_FN_CONNECT_ALIVE;
						g_pNPCGlobal->GetN2FSocket()->Write((char*)&nSendType, SIZE_FIELD_TYPE_HEADER);
					}

					//////////////////////////////////////////////////////
					// NPC Server�� TCP ������ �����Ƿ� Alive Check�� ���� �ʴ´�
					//g_pNPCGlobal->CheckClientAlive();
				}
				break;
			case TIMERID_RECONNECT:
				{
					g_pNPCGlobal->EndTimerReconnect();
					if(g_pNPCGlobal->GetN2FSocket())
					{
						g_pNPCGlobal->GetN2FSocket()->Connect(g_pNPCGlobal->GetIPFieldServer(), g_pNPCGlobal->GetPortFieldServer());
					}
				}
				break;
			}

		}
		break;
	case WM_DESTROY:
		{
			g_pNPCGlobal->EndServerSocket();
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

