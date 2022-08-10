#pragma once


// CTextView 대화 상자입니다.

class CTextView : public CDialogEx
{
	DECLARE_DYNAMIC(CTextView)

public:
	CTextView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTextView();
	void ChangeLable();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_sTitle;
	CString m_sValue;
};
