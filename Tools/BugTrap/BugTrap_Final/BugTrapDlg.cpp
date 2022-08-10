
// TEstbDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CTEstbDlg ��ȭ ����




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


// CTEstbDlg �޽��� ó����

BOOL CBugTrapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_pDlg = new CTextView();
 	m_pDlg->Create(IDD_FORMVIEW, this);
 	m_pDlg->SetBackgroundColor(RGB(255, 255, 255));
 	m_pDlg->SetWindowPos((CWnd *)NULL,-1,-1,1000,90,SWP_NOZORDER);
 	m_pDlg->ShowWindow(SW_SHOW);


	m_pOKBtn.SetWindowText(TEXT(STRMSG_C_140218_0003));
	m_pCanCelBtn.SetWindowText(TEXT(STRMSG_C_140218_0004));

	CreateFile();
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CBugTrapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CBugTrapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBugTrapDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	HZIP hz = CreateZip(sDirectoryPath,0);
	ZipAdd(hz,sZipInTextName,sTextName);
	ZipAdd(hz,sZipInDmpName,argv[1]);
	ZipAdd(hz,_T("VersionInfo.ver"),szVersionInfoName);
	CloseZip(hz);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wchar_t nname[512] = {0,};
	{
		//	FTP ���� ����
		// 		time_t timer;
		// 		struct tm t;
		// 		timer = time(NULL); 
		// 		localtime_s(&t, &timer);
		// 		wsprintf(nname, L"dmp/%d%02d%02d%02d%02d%02d%s", t.tm_year + 1900, t.tm_mon +1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, argv[2]);
		// 		FtpFileUpload(_T("115.144.35.22"),_T("buguser"),_T("1111"),sDirectoryPath,nname);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//HTTP ���� ����
	FileNameCreate(nname, argv[2], argv[6]);
	pHttpClient = new CHttpClient();

	pHttpClient->SetEncoding(CP_ACP);  
	pHttpClient->CreateSession(TEXT("myagnt"), argv[3], 80, argv[4], argv[5]);			//������, ��Ʈ, ���̵�, ��й�ȣ
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
	//TEXT ���� ���� 
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

	//���� �����
	_tunlink(sTextName);
	_tunlink(argv[1]);
	_tunlink(sDirectoryPath);

	if(m_pDlg)
		delete m_pDlg;

}

void CBugTrapDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DeleteFile();
	CDialogEx::OnCancel();
}

void CBugTrapDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDialogEx::OnClose();
}
