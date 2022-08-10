
// TEstbDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CTEstbDlg ��ȭ ����
class CTextFileManager;
class CHttpClient;
class CTextView;
class CBugTrapDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CBugTrapDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TESTB_DIALOG };
	CTextView* m_pDlg;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	void FileNameCreate(wchar_t* pName, wchar_t* UserName, wchar_t* FileName);

// �����Դϴ�.
protected:
	HICON m_hIcon;
	TCHAR* argv[7];
	bool m_bStartProgram;
	int m_nCount;

	CTextFileManager* pTextFileManager;
	CHttpClient* pHttpClient;// = NULL;
	//argv[1]											// ���� ������ �⺻path�� ���ڷ� �ƱԸ�Ʈ�� ����
	wchar_t sName[260];// = {0,};							// �⺻ �̸� 
	wchar_t sDirectoryPath[260];// = {0,};					// ���丮 path���� �������� zip���� ��� ����
	wchar_t sTextName[260];// = {0,};						// txt������ path ����
	wchar_t sZipInTextName[260];// = {0,};					// zip���Ͽ� �� txt���� �̸�
	wchar_t sZipInDmpName[260];// = {0,};					// dmp ���Ͽ� �� dmp���� �̸�
	wchar_t szVersionInfoName[260];

	// ������ �޽��� �� �Լ�
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
