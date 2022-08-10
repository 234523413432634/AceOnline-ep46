#include <tchar.h>
#include "FiveRocksMain.h"

HINSTANCE g_hInst;
HWND g_hWnd;
const TCHAR g_WndName[] = TEXT(APP_NAME);

FiveRocksMain* g_FiveRocks;

LRESULT CALLBACK WndProc( HWND , UINT, WPARAM , LPARAM );

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	WNDCLASSEX WndClassEx;

	WndClassEx.cbSize			= sizeof(WNDCLASSEX);
	WndClassEx.cbClsExtra		= NULL;
	WndClassEx.cbWndExtra		= NULL;
	WndClassEx.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClassEx.hCursor			= LoadCursor(NULL, IDC_ARROW);
	WndClassEx.hInstance		= hInstance;
	WndClassEx.hIcon			= LoadIcon(hInstance, IDI_APPLICATION);
	WndClassEx.hIconSm			= NULL;
	WndClassEx.lpfnWndProc		= WndProc;
	WndClassEx.lpszClassName	= g_WndName;
	WndClassEx.lpszMenuName		= NULL;
	WndClassEx.style			= CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&WndClassEx);

	g_hWnd = CreateWindow(g_WndName, g_WndName, WS_OVERLAPPEDWINDOW, 350, 270, 300, 120, NULL, NULL, hInstance, NULL);

	if(g_hWnd == NULL)
	{
		return false;
	}

	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

	//Init
	g_FiveRocks = new FiveRocksMain;
	if(!g_FiveRocks->Init())
	{
		return false;
	}

	MSG Message;
#if defined(USE_SERVER2003_R2)
	DWORD TickCheckTime = GetTickCount();
#else
	ULONGLONG TickCheckTime = GetTickCount64();
#endif
	while(1)
	{
		if(PeekMessage(&Message,NULL,0,0,PM_REMOVE))
		{
			if(Message.message == WM_QUIT) 
				break;
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
		{
			//Run
#if defined(USE_SERVER2003_R2)
			if (TickCheckTime < GetTickCount())
#else
			if (TickCheckTime < GetTickCount64())
#endif
			{
				g_FiveRocks->Run();
#if defined(USE_SERVER2003_R2)
				TickCheckTime = GetTickCount() + (1000 / 30);
#else
				TickCheckTime = GetTickCount64() + (1000 / 30);
#endif
			}
			else
			{
				Sleep(1);
			}
		}
	}
	//Release
	g_FiveRocks->Release();
	if(g_FiveRocks)
	{
		delete g_FiveRocks;
		g_FiveRocks = NULL;
	}

	return Message.wParam;
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam )
{
	switch( iMessage )
	{
	case WM_PAINT :
		{
			PAINTSTRUCT ps ;
			HDC hdc = BeginPaint( hWnd, &ps ) ;
			EndPaint( hWnd, &ps ) ;
		}
		break ;
	case WM_DESTROY :
		PostQuitMessage( 0 ) ;
		return 0 ;                
	}

	return ( DefWindowProc( hWnd, iMessage, wParam, lParam ) ) ;
}