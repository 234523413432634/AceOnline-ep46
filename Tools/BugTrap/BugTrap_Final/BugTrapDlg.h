
// TEstbDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CTEstbDlg 대화 상자
class CTextFileManager;
class CHttpClient;
class CTextView;
class CBugTrapDlg : public CDialogEx
{
// 생성입니다.
public:
	CBugTrapDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.


// 대화 상자 데이터입니다.
	enum { IDD = IDD_TESTB_DIALOG };
	CTextView* m_pDlg;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	void FileNameCreate(wchar_t* pName, wchar_t* UserName, wchar_t* FileName);

// 구현입니다.
protected:
	HICON m_hIcon;
	TCHAR* argv[7];
	bool m_bStartProgram;
	int m_nCount;

	CTextFileManager* pTextFileManager;
	CHttpClient* pHttpClient;// = NULL;
	//argv[1]											// 덤프 파일의 기본path를 인자로 아규먼트로 받음
	wchar_t sName[260];// = {0,};							// 기본 이름 
	wchar_t sDirectoryPath[260];// = {0,};					// 디렉토리 path저장 마지막엔 zip파일 경로 저장
	wchar_t sTextName[260];// = {0,};						// txt파일의 path 저장
	wchar_t sZipInTextName[260];// = {0,};					// zip파일에 들어갈 txt파일 이름
	wchar_t sZipInDmpName[260];// = {0,};					// dmp 파일에 들어갈 dmp파일 이름
	wchar_t szVersionInfoName[260];

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool SetProgramArgv(LPTSTR param);
	void CreateFile();
	void DeleteFile();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	CButton m_pOKBtn;
	CButton m_pCanCelBtn;
};
