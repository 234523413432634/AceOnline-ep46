#pragma once


// CTextView ��ȭ �����Դϴ�.

class CTextView : public CDialogEx
{
	DECLARE_DYNAMIC(CTextView)

public:
	CTextView(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextView();
	void ChangeLable();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_sTitle;
	CString m_sValue;
};
