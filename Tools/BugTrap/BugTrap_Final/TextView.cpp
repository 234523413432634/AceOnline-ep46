// TextView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "resource.h"
#include "TextView.h"
#include "afxdialogex.h"



// CTextView ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTextView, CDialogEx)

CTextView::CTextView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextView::IDD, pParent)
	, m_sTitle(_T(""))
	, m_sValue(_T(""))
{
	ChangeLable();
}

CTextView::~CTextView()
{
}

void CTextView::DoDataExchange(CDataExchange* pDX)
{                   ;
	DDX_Text(pDX, IDC_TITLE, m_sTitle);
	DDX_Text(pDX, IDC_VALUE, m_sValue);
}


BEGIN_MESSAGE_MAP(CTextView, CDialogEx)
END_MESSAGE_MAP()

void CTextView::ChangeLable()
{
	m_sTitle = STRMSG_C_140218_0001;
	m_sValue = STRMSG_C_140218_0002;
}

// CTextView �޽��� ó�����Դϴ�.
