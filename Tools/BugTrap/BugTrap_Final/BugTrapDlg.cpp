
// TEstbDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "BugTrap.h"
#include "BugTrapDlg.h"
#include <wininet.h>
#pragma comment(lib, "wininet")
#include <iostream>
#include "zip.h"
#include "TextFileManager.h"
#include "HttpClient.h"
#include "TextView.h"
#include "afxdialogex.h"
#include "Contents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTEstbDlg 대화 상자




CBugTrapDlg::CBugTrapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBugTrapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBugTrapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_pOKBtn);
	DDX_Control(pDX, IDCANCEL, m_pCanCelBtn);
}

BEGIN_MESSAGE_MAP(CBugTrapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBugTrapDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBugTrapDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CTEstbDlg 메시지 처리기

BOOL CBugTrapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_pDlg = new CTextView();
 	m_pDlg->Create(IDD_FORMVIEW, this);
 	m_pDlg->SetBackgroundColor(RGB(255, 255, 255));
 	m_pDlg->SetWindowPos((CWnd *)NULL,-1,-1,1000,90,SWP_NOZORDER);
 	m_pDlg->ShowWindow(SW_SHOW);


	m_pOKBtn.SetWindowText(TEXT(STRMSG_C_140218_0003));
	m_pCanCelBtn.SetWindowText(TEXT(STRMSG_C_140218_0004));

	CreateFile();
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBugTrapDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBugTrapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBugTrapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBugTrapDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	HZIP hz = CreateZip(sDirectoryPath,0);
	ZipAdd(hz,sZipInTextName,sTextName);
	ZipAdd(hz,sZipInDmpName,argv[1]);
	ZipAdd(hz,_T("VersionInfo.ver"),szVersionInfoName);
	CloseZip(hz);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wchar_t nname[512] = {0,};
	{
		//	FTP 파일 전송
		// 		time_t timer;
		// 		struct tm t;
		// 		timer = time(NULL); 
		// 		localtime_s(&t, &timer);
		// 		wsprintf(nname, L"dmp/%d%02d%02d%02d%02d%02d%s", t.tm_year + 1900, t.tm_mon +1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, argv[2]);
		// 		FtpFileUpload(_T("115.144.35.22"),_T("buguser"),_T("1111"),sDirectoryPath,nname);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//HTTP 파일 전송
	FileNameCreate(nname, argv[2], argv[6]);
	pHttpClient = new CHttpClient();

	pHttpClient->SetEncoding(CP_ACP);  
	pHttpClient->CreateSession(TEXT("myagnt"), argv[3], 80, argv[4], argv[5]);			//아이피, 포트, 아이디, 비밀번호
	pHttpClient->AddPostFile(TEXT("userfile"), nname, sDirectoryPath);  
	pHttpClient->RequestPost(TEXT("/upload.php"),NULL,NULL,NULL,NULL);
	pHttpClient->CloseSession();  
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	DeleteFile();

	AfxMessageBox(TEXT(STRMSG_C_140218_0005));

	CDialogEx::OnOK();
}

bool CBugTrapDlg::SetProgramArgv(LPTSTR param)
{
	pTextFileManager = NULL;
	pHttpClient = NULL;
	ZeroMemory(sName, sizeof(sName));
	ZeroMemory(sDirectoryPath, sizeof(sDirectoryPath));
	ZeroMemory(sTextName, sizeof(sTextName));
	ZeroMemory(sZipInTextName, sizeof(sZipInTextName));
	ZeroMemory(sZipInDmpName, sizeof(sZipInDmpName));
	ZeroMemory(szVersionInfoName, sizeof(szVersionInfoName));
	m_nCount = 1;

	for(int i = 1; i<7; ++i)
	{
		argv[i] = NULL;
	}

	if (param==NULL || param[0]==_T('\0'))
		return false;

	
	TCHAR* token = _tcstok(param, TEXT(" "));

	while(token !=NULL)
	{
		argv[m_nCount] = token;
		token = _tcstok(NULL, TEXT(" "));
		m_nCount++;
	}
	return true;
}
void CBugTrapDlg::FileNameCreate(wchar_t* pName, wchar_t* UserName, wchar_t* FileName)
{
	time_t timer;
	struct tm t;
	timer = time(NULL); 
	localtime_s(&t, &timer);
	wsprintf(pName, L"%s%d%02d%02d%02d%02d%02d%s.zip", FileName, t.tm_year + 1900, t.tm_mon +1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, UserName);
}

void CBugTrapDlg::CreateFile()
{
	if(m_nCount < 7 || argv[1] == NULL || argv[2]== NULL || argv[3]== NULL || argv[4]== NULL || argv[5]== NULL || argv[6]== NULL)
	{
		CDialogEx::OnCancel();
		return;
	}

	wchar_t* ext = _tcsrchr( argv[1], '.');

	if(ext)
		_tcsncpy(sDirectoryPath, argv[1],_tcslen(argv[1]) - _tcslen(ext));

	ext = _tcsrchr(sDirectoryPath, '\\');
	if(ext)
		_tcscpy_s(sName, ext);

	_tcsncpy(szVersionInfoName, argv[1],_tcslen(sDirectoryPath) - _tcslen(ext));
	_tcscat(szVersionInfoName, _T("\\VersionInfo.ver"));

	_tcscpy_s(sTextName, sDirectoryPath);
	_tcscat(sTextName, _T(".txt"));
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//TEXT 파일 생성 
	pTextFileManager = new CTextFileManager();
	pTextFileManager->CreateTextFile(sTextName);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_tcscat(sDirectoryPath, _T(".zip"));

	_tcscpy_s(sZipInTextName, &sName[1]);
	_tcscpy_s(sZipInDmpName, &sName[1]);

	_tcscat(sZipInTextName, _T(".txt"));
	_tcscat(sZipInDmpName, _T(".dmp"));
}

void CBugTrapDlg::DeleteFile()
{
	if(pTextFileManager != NULL)
		delete(pTextFileManager);
	if(pHttpClient != NULL)
		delete(pHttpClient);

	//파일 지우기
	_tunlink(sTextName);
	_tunlink(argv[1]);
	_tunlink(sDirectoryPath);

	if(m_pDlg)
		delete m_pDlg;

}

void CBugTrapDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DeleteFile();
	CDialogEx::OnCancel();
}

void CBugTrapDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialogEx::OnClose();
}
