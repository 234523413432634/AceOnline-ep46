// SetLanguageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "SetLanguageDlg.h"
#include "AtumParam.h"
#include "BrowseForFolder.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetLanguageDlg dialog


CSetLanguageDlg::CSetLanguageDlg(CString i_strLocalizationPath, int i_nLangType, CWnd* pParent /*=NULL*/)
	: CDialog(CSetLanguageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetLanguageDlg)
	m_ctl_strLocalPath = _T("");
	//}}AFX_DATA_INIT

	m_ctl_strLocalPath		= i_strLocalizationPath;
	m_nLanguageType			= i_nLangType;
}


void CSetLanguageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetLanguageDlg)
	DDX_Control(pDX, IDC_EDIT_LOCALIZATION_PATH, m_ctl_editLocalPath);
	DDX_Text(pDX, IDC_EDIT_LOCALIZATION_PATH, m_ctl_strLocalPath);
	DDX_Text(pDX, IDC_EDIT_LANG_TYPE, m_nLanguageType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetLanguageDlg, CDialog)
	//{{AFX_MSG_MAP(CSetLanguageDlg)
	ON_BN_CLICKED(IDC_RADIO_KOREAN, OnRadioKorean)
	ON_BN_CLICKED(IDC_RADIO_JAPANESE, OnRadioJapanese)
	ON_BN_CLICKED(IDC_RADIO_ENGLISH, OnRadioEnglish)
	ON_BN_CLICKED(IDC_RADIO_CHINESE, OnRadioChinese)
	ON_BN_CLICKED(IDC_RADIO_VIETNAMESE, OnRadioVietnamese)
	ON_BN_CLICKED(IDC_BTN_SELECT_PATH, OnBtnSelectPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetLanguageDlg message handlers

BOOL CSetLanguageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
// 	switch(m_nLanguageType)
// 	{
// 	case LANGUAGE_TYPE_KOREAN:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_KOREAN, TRUE);
// 		}
// 		break;
// 	case LANGUAGE_TYPE_ENGLISH:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_ENGLISH, TRUE);
// 		}
// 		break;
// 	case LANGUAGE_TYPE_JAPANESE:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_JAPANESE, TRUE);
// 		}
// 		break;
// 	case LANGUAGE_TYPE_CHINESE:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_CHINESE, TRUE);
// 		}
// 		break;
// 	case LANGUAGE_TYPE_VIETNAMESE:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_VIETNAMESE, TRUE);
// 		}
// 		break;
// 	default:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_KOREAN, TRUE);
// 			m_nLanguageType		= LANGUAGE_TYPE_KOREAN;
// 		}
// 	}
// 	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);
	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - ��� ����Ʈ ���� ���
	CString strLangTyInfo;
	for(int i=0; i <= LANGUAGE_TYPE_LAST; i++)
	{
		char szTemp[1024];
		sprintf(szTemp, "LanguageType %2d : [%s]\r\n", i, GET_LANGUAGE_TYPE_STRING(i));
		strLangTyInfo.Insert(strLangTyInfo.GetLength(), szTemp);
	}
	GetDlgItem(IDC_EDIT_LANG_INFO)->SetWindowText(strLangTyInfo);
	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetLanguageDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
	if(FALSE == IS_VALID_LANGUAGE_TYPE(m_nLanguageType))
	{
		AfxMessageBox("LanguageType is invalid !!\r\n Please check LanguageType.");
		return;
	}


	CDialog::OnOK();
}

void CSetLanguageDlg::OnRadioKorean() 
{
	// TODO: Add your control notification handler code here
	
	m_nLanguageType		= LANGUAGE_TYPE_KOREAN;
	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);
}

void CSetLanguageDlg::OnRadioEnglish() 
{
	// TODO: Add your control notification handler code here
	
	m_nLanguageType		= LANGUAGE_TYPE_ENGLISH;
	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);
}

void CSetLanguageDlg::OnRadioJapanese() 
{
	// TODO: Add your control notification handler code here
	
	m_nLanguageType		= LANGUAGE_TYPE_JAPANESE;
	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);
}

void CSetLanguageDlg::OnRadioChinese() 
{
	// TODO: Add your control notification handler code here
	
	m_nLanguageType		= LANGUAGE_TYPE_CHINESE;
	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);
}

void CSetLanguageDlg::OnRadioVietnamese() 
{
	// TODO: Add your control notification handler code here
	m_nLanguageType		= LANGUAGE_TYPE_VIETNAMESE;
	m_ctl_editLocalPath.EnableWindow(m_nLanguageType != LANGUAGE_TYPE_KOREAN);	
}

void CSetLanguageDlg::OnBtnSelectPath() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
	if(LANGUAGE_TYPE_KOREAN == m_nLanguageType)
	{
		AfxMessageBox("Korean don't need to set this setting !!");
		return;
	}
	else if(FALSE == IS_VALID_LANGUAGE_TYPE(m_nLanguageType))
	{
		AfxMessageBox("LanguageType is invalid !!\r\n Please check LanguageType.");
		return;
	}

	CBrowseForFolder bf;
	bf.hWndOwner = this->m_hWnd;
	bf.strTitle = "Select folder that files for localization";
	CString sz;
	if (!bf.GetFolder(sz, (LPCSTR)m_ctl_strLocalPath))
		return;

	m_ctl_strLocalPath.Format("%s", sz);
	UpdateData(FALSE);
}
