//-----------------------------------------------------------------------------
// File: D3DApp.h
//
// Desc: Application class for the Direct3D samples framework library.
//
// Copyright (c) 1998-2001 Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#ifndef D3DAPP_H
#define D3DAPP_H

// basetsd.h defines INT_PTR (used below).  It is not included by default
// under VC 5.0.  If you are using VC6 or later, it is included via Windows.h.
#include <basetsd.h> 


//-----------------------------------------------------------------------------
// Error codes
//-----------------------------------------------------------------------------
enum APPMSGTYPE { MSG_NONE, MSGERR_APPMUSTEXIT, MSGWARN_SWITCHEDTOREF };

#define D3DAPPERR_NODIRECT3D          0x82000001
#define D3DAPPERR_NOWINDOW            0x82000002
#define D3DAPPERR_NOCOMPATIBLEDEVICES 0x82000003
#define D3DAPPERR_NOWINDOWABLEDEVICES 0x82000004
#define D3DAPPERR_NOHARDWAREDEVICE    0x82000005
#define D3DAPPERR_HALNOTCOMPATIBLE    0x82000006
#define D3DAPPERR_NOWINDOWEDHAL       0x82000007
#define D3DAPPERR_NODESKTOPHAL        0x82000008
#define D3DAPPERR_NOHALTHISMODE       0x82000009
#define D3DAPPERR_NONZEROREFCOUNT     0x8200000a
#define D3DAPPERR_MEDIANOTFOUND       0x8200000b
#define D3DAPPERR_RESIZEFAILED        0x8200000c
#define D3DAPPERR_NULLREFDEVICE       0x8200000d




//-----------------------------------------------------------------------------
// Name: struct D3DModeInfo
// Desc: Structure for holding information about a display mode
//-----------------------------------------------------------------------------
struct D3DModeInfo
{
    DWORD      Width;      // Screen width in this mode
    DWORD      Height;     // Screen height in this mode
    D3DFORMAT  Format;     // Pixel format in this mode
    DWORD      dwBehavior; // Hardware / Software / Mixed vertex processing
    D3DFORMAT  DepthStencilFormat; // Which depth/stencil format to use with this mode
};




//-----------------------------------------------------------------------------
// Name: struct D3DDeviceInfo
// Desc: Structure for holding information about a Direct3D device, including
//       a list of modes compatible with this device
//-----------------------------------------------------------------------------
struct D3DDeviceInfo
{
    // Device data
    D3DDEVTYPE   DeviceType;      // Reference, HAL, etc.
    D3DCAPS9     d3dCaps;         // Capabilities of this device
    const TCHAR* strDesc;         // Name of this device
    BOOL         bCanDoWindowed;  // Whether this device can work in windowed mode

    // Modes for this device
    DWORD        dwNumModes;
    D3DModeInfo  modes[150];

    // Current state
    DWORD        dwCurrentMode;
    BOOL         bWindowed;
    D3DMULTISAMPLE_TYPE MultiSampleTypeWindowed;
    D3DMULTISAMPLE_TYPE MultiSampleTypeFullscreen;
};




//-----------------------------------------------------------------------------
// Name: struct D3DAdapterInfo
// Desc: Structure for holding information about an adapter, including a list
//       of devices available on this adapter
//-----------------------------------------------------------------------------
struct D3DAdapterInfo
{
    // Adapter data
    D3DADAPTER_IDENTIFIER9 d3dAdapterIdentifier;
    D3DDISPLAYMODE d3ddmDesktop;      // Desktop display mode for this adapter

    // Devices for this adapter
    DWORD          dwNumDevices;
    D3DDeviceInfo  devices[5];

    // Current state
    DWORD          dwCurrentDevice;
};



class Host;
class CExploreHost; // 2013-05-23 by bhsohn 익스폴로워 모드로 업그레이드
//-----------------------------------------------------------------------------
// Name: class CD3DApplication
// Desc: A base class for creating sample D3D8 applications. To create a simple
//       Direct3D application, simply derive this class into a class (such as
//       class CMyD3DApplication) and override the following functions, as 
//       needed:
//          OneTimeSceneInit()    - To initialize app data (alloc mem, etc.)
//          InitDeviceObjects()   - To initialize the 3D scene objects
//          FrameMove()           - To animate the scene
//          Render()              - To render the scene
//          DeleteDeviceObjects() - To cleanup the 3D scene objects
//          FinalCleanup()        - To cleanup app data (for exitting the app)
//          MsgProc()             - To handle Windows messages
//-----------------------------------------------------------------------------
class CD3DApplication
{
protected:
	HINSTANCE		  m_hInstance;// by dhkwon
	DWORD			  m_dwCurrentMode;
    HCURSOR			  m_hCursor;
	DWORD			  m_dwCursor;
	DWORD			  m_dwIcon;
	BOOL			  m_bShowCursor;

    // Internal variables for the state of the app
    D3DAdapterInfo    m_Adapters[10];
    DWORD             m_dwNumAdapters;
    DWORD             m_dwAdapter;
    BOOL              m_bWindowed;
    BOOL              m_bActive;
    BOOL              m_bReady;
    BOOL              m_bHasFocus;

    // Internal variables used for timing
    BOOL              m_bFrameMoving;
    BOOL              m_bSingleStep;
	HDC				  m_hHangulDC;		//CD3DHanFont에서 사용한다.(리소스 절약)
    // Internal error handling function
    HRESULT DisplayErrorMsg( HRESULT hr, DWORD dwType );

    // Internal functions to manage and render the 3D scene
    HRESULT BuildDeviceList();
    BOOL    FindDepthStencilFormat( UINT iAdapter, D3DDEVTYPE DeviceType,
                D3DFORMAT TargetFormat, D3DFORMAT* pDepthStencilFormat );
    HRESULT Initialize3DEnvironment();
    HRESULT Resize3DEnvironment();
    HRESULT ToggleFullscreen();
    HRESULT ForceWindowed();
    HRESULT UserSelectNewDevice();
    VOID    Cleanup3DEnvironment();// 
    HRESULT Render3DEnvironment();
    virtual HRESULT AdjustWindowForChange();
    static INT_PTR CALLBACK SelectDeviceProc( HWND hDlg, UINT msg, 
                WPARAM wParam, LPARAM lParam );

public:
    D3DSURFACE_DESC		m_d3dsdBackBuffer;   // Surface desc of the backbuffer
	UINT				m_nWidth;
	UINT				m_nHeight;
	POINT				m_ptCursor;
	Host*				m_pHost;		// 2005-01-19 by jschoi - 웹과 연동
	CExploreHost*		m_pExploreHost;		// 2013-05-23 by bhsohn 익스폴로워 모드로 업그레이드
	
protected:
    // Main objects used for creating and rendering the 3D scene
    D3DPRESENT_PARAMETERS m_d3dpp;         // Parameters for CreateDevice/Reset
    HWND              m_hWnd;              // The main app window
	HWND			  m_hWebWnd;		   // 웹과 연동을 위한 윈도우 핸들
    HWND              m_hWndFocus;         // The D3D focus window (usually same as m_hWnd)
    HMENU             m_hMenu;             // App menu bar (stored here when fullscreen)
    LPDIRECT3D9       m_pD3D;              // The main D3D object
    LPDIRECT3DDEVICE9 m_pd3dDevice;        // The D3D rendering device
	// 2010-09-29 by jskim, SpriteDevice Lost 되었을 때 구조 변경
	LPD3DXSPRITE	  m_pd3dxSprite;	   // The D3D Sprite device
	// end 2010-09-29 by jskim, SpriteDevice Lost 되었을 때 구조 변경
    D3DCAPS9          m_d3dCaps;           // Caps for the device
    DWORD             m_dwCreateFlags;     // Indicate sw or hw vertex processing
    DWORD             m_dwWindowStyle;     // Saved window style for mode switches
    RECT              m_rcWindowBounds;    // Saved window bounds for mode switches
    RECT              m_rcWindowClient;    // Saved client area size for mode switches
	
    // Variables for timing
    FLOAT             m_fTime;             // Current time in seconds
    FLOAT             m_fElapsedTime;      // Time elapsed since last frame
    FLOAT             m_fFPS;              // Instanteous frame rate
    TCHAR             m_strDeviceStats[90];// String to hold D3D device stats
    TCHAR             m_strFrameStats[90]; // String to hold frame stats
#ifdef _SHOW_LATENCY
    FLOAT				m_fSendTime;
#endif

    // Overridable variables for the app
    TCHAR*            m_strWindowTitle;    // Title for the app's window
    BOOL              m_bUseDepthBuffer;   // Whether to autocreate depthbuffer
    DWORD             m_dwMinDepthBits;    // Minimum number of bits needed in depth buffer
    DWORD             m_dwMinStencilBits;  // Minimum number of bits needed in stencil buffer
    DWORD             m_dwCreationWidth;   // Width used to create window
    DWORD             m_dwCreationHeight;  // Height used to create window
    BOOL              m_bShowCursorWhenFullscreen; // Whether to show cursor when fullscreen
    BOOL              m_bClipCursorWhenFullscreen; // Whether to limit cursor pos when fullscreen

	// 2008-11-06 by bhsohn 마우스 가두기 모드 보완
	int					m_nSetCursel;
	RECT				m_rcClipRect;

	// 2005-01-17 by jschoi
	BOOL              m_bDeviceLost;		// 디바이스를 잃어버렸을때 처리를 위해

    // Overridable functions for the 3D scene created by the app
    virtual HRESULT ConfirmDevice(D3DCAPS9*,DWORD,D3DFORMAT)   { return S_OK; }
    virtual HRESULT OneTimeSceneInit()                         { return S_OK; }
    virtual HRESULT InitDeviceObjects()                        { return S_OK; }
    virtual HRESULT RestoreDeviceObjects()                     { return S_OK; }
    virtual HRESULT FrameMove()                                { return S_OK; }
	virtual HRESULT InActiveFrameMove()						   { return S_OK; }
	virtual HRESULT Render()                                   { return S_OK; }
    virtual HRESULT InvalidateDeviceObjects()                  { return S_OK; }
    virtual HRESULT DeleteDeviceObjects()                      { return S_OK; }
    virtual HRESULT FinalCleanup()                             { return S_OK; }
	virtual void LostDeviceTick()							   { return; }

public:
    // Functions to create, run, pause, and clean up the application
    virtual HRESULT Create( HINSTANCE hInstance );
    virtual INT     Run();
    virtual LRESULT MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    virtual VOID    Pause( BOOL bPause );

 	int GetWidth() { return m_dwCreationWidth; }
	int GetHeight() { return m_dwCreationHeight; }
	HDC GetHDC() { return m_hHangulDC; }

	// 2005-01-07 by jschoi
	D3DPRESENT_PARAMETERS GetPresentParameters() { return m_d3dpp; }
	
	// 2005-01-13 by jschoi
	HWND GetWebWnd() { return m_hWebWnd; }
	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return m_pd3dDevice; }
	// 2010-09-29 by jskim, SpriteDevice Lost 되었을 때 구조 변경
	LPD3DXSPRITE GetDirectSprite() { return m_pd3dxSprite; }			
	// end 2010-09-29 by jskim, SpriteDevice Lost 되었을 때 구조 변경

	// 2005-01-19 by jschoi - WebWindow
	// 2012-11-28 by jhjang 게임포지 웹 상점 통합 추가 작업
	// 2012-11-23 by jhjang 게임포지 웹 상점 통합 작업
	//void	CreateWebWindow();
	//void	CreateWebWindow(char* strWebSite = NULL,char* strWebParameter = NULL);
	void	CreateWebWindow(char* strWebSite = NULL,char* strWebParameter = NULL,int nWebPosX = -1,int nWebPosY = -1,int nWebWidth = -1,int nWebHeight = -1);
	// end 2012-11-23 by jhjang 게임포지 웹 상점 통합 작업
	void	DestroyWebWindow();
	//void	ShowWebWindow(int nWebPosX = -1,int nWebPosY = -1);
	void	ShowWebWindow(int nWebPosX = -1,int nWebPosY = -1,int nWebWidth = -1, int nWebHeight = -1);			// 2013-07-18 by ssjung 신규 웹 캐쉬 상점 적용
	// end 2012-11-28 by jhjang 게임포지 웹 상점 통합 추가 작업
	void	HideWebWindow();

 	// 2006-11-10 by ispark, 알파 렌더링 상태 셋팅
	void SetAlphaRenderState(int nAlphaValue);
	void InitAlphaRenderState();

	// 2007-04-12 by bhsohn 포커스 잃어 버렸을때의 추가버그 처리
	BOOL IsDeviceLost();

	// 2008-11-06 by bhsohn 마우스 가두기 모드 보완
	void RefreshMouseMode();
	void SetClipCursor(int nSetCursel);

	// 2013-05-23 by bhsohn 익스폴로워 모드로 업그레이드
	void PopupExplore(char* strWebSite,char* strWebParameter,int nWebPosX,int nWebPosY,int nWebWidth,int nWebHeight);
	void ReleaseExplore();
	// END 2013-05-23 by bhsohn 익스폴로워 모드로 업그레이드

// 2013-10-01 by ssjung 1주년 이벤트
	void ShowWebWindow_FirstAnniversaryEvent(int nWebPosX,int nWebPosY, int nWebWidth,int nWebHeight);

   // Internal constructor
    CD3DApplication();
};

extern CD3DApplication			*	g_pApp;



#endif



