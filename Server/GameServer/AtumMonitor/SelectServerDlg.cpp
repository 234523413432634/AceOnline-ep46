// selectserverdlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\AtumMonitor\atummonitor.h"
#include "selectserverdlg.h"
#include "BrowseForFolder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectServerDlg dialog


CSelectServerDlg::CSelectServerDlg(CString i_strPath, int i_nLangType, CString i_strServerName, CWnd* pParent /*=NULL*/)
	: CDialog(CSelectServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectServerDlg)
	m_ctl_strLocalizationPath = _T("");
	//}}AFX_DATA_INIT
	m_ctl_strLocalizationPath	= i_strPath;
	m_nLanguageT				= i_nLangType;
	m_strServerName				= i_strServerName;
}


void CSelectServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectServerDlg)
	DDX_Control(pDX, IDC_EDIT_DIRECTORY, m_ctl_editLocalizationPath);
	DDX_Control(pDX, IDC_COMBO_SERVER_LIST, m_ComboServerList);
	DDX_Text(pDX, IDC_EDIT_DIRECTORY, m_ctl_strLocalizationPath);
	DDX_Text(pDX, IDC_EDIT_LANG_TYPE, m_nLanguageT);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectServerDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectServerDlg)
	ON_BN_CLICKED(IDC_BTN_SELECT_PATH, OnBtnSelectPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectServerDlg message handlers

BOOL CSelectServerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();



	// TODO: Add extra initialization here
	int nComboSelIndex = 0;
	auto i{ 0 };
	for (i = 0; g_arrGameServers[i].ServerName !=NULL; i++)
	{
		m_ComboServerList.AddString(g_arrGameServers[i].ServerName);
		if (0 == m_strServerName.Compare(g_arrGameServers[i].ServerName))
		{
			nComboSelIndex = i;
		}
	}
	m_ComboServerList.SetCurSel(nComboSelIndex);

// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - �ʿ� ����
// 	switch(m_nLanguageT)
// 	{
// 	case LANGUAGE_TYPE_KOREAN:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_K, TRUE);
// 		}
// 		break;
// 	case LANGUAGE_TYPE_ENGLISH:		this->CheckDlgButton(IDC_RADIO_E, TRUE);		break;
// 	case LANGUAGE_TYPE_JAPANESE:	this->CheckDlgButton(IDC_RADIO_J, TRUE);		break;
// 	case LANGUAGE_TYPE_CHINESE:		this->CheckDlgButton(IDC_RADIO_C, TRUE);		break;
// 	case LANGUAGE_TYPE_VIETNAMESE:	this->CheckDlgButton(IDC_RADIO_VIT, TRUE);		break;
// 	default:
// 		{
// 			this->CheckDlgButton(IDC_RADIO_K, TRUE);
// 			m_nLanguageT	= LANGUAGE_TYPE_KOREAN;
// 		}
// 	}
//	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - ��� ����Ʈ ���� ���
	CString strLangTyInfo;
	for(i=0; i <= LANGUAGE_TYPE_LAST; i++)
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

void CSelectServerDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
	if(FALSE == IS_VALID_LANGUAGE_TYPE(m_nLanguageT))
	{
		AfxMessageBox("LanguageType is invalid !!\r\n Please check LanguageType.");
		return;
	}

	CString szServerName;
	m_ComboServerList.GetLBText(m_ComboServerList.GetCurSel(), szServerName);

	for (int i = 0; g_arrGameServers[i].ServerName !=NULL; i++)
	{
		if (szServerName == g_arrGameServers[i].ServerName)
		{
			m_strServerName = szServerName;
			m_GameServerInfoForAdmin = g_arrGameServers[i];
			break;
		}
	}
	
	CDialog::OnOK();
}

// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - LanguageType �� ���ڷ� �Է��ϰ� ����
// void CSelectServerDlg::OnRadioK() 
// {
// 	// TODO: Add your control notification handler code here
// 	m_nLanguageT = LANGUAGE_TYPE_KOREAN;
// 	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);
// }
// 
// void CSelectServerDlg::OnRadioE() 
// {
// 	// TODO: Add your control notification handler code here
// 	m_nLanguageT = LANGUAGE_TYPE_ENGLISH;
// 	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);
// }
// 
// void CSelectServerDlg::OnRadioJ() 
// {
// 	// TODO: Add your control notification handler code here
// 	m_nLanguageT = LANGUAGE_TYPE_JAPANESE;
// 	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);
// }
// 
// void CSelectServerDlg::OnRadioC() 
// {
// 	// TODO: Add your control notification handler code here
// 	m_nLanguageT = LANGUAGE_TYPE_CHINESE;
// 	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);
// }
// 
// void CSelectServerDlg::OnRadioVit() 
// {
// 	// TODO: Add your control notification handler code here
// 	m_nLanguageT = LANGUAGE_TYPE_VIETNAMESE;
// 	m_ctl_editLocalizationPath.EnableWindow(m_nLanguageT != LANGUAGE_TYPE_KOREAN);	
// }

void CSelectServerDlg::OnBtnSelectPath() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	// 2008-04-25 by cmkwon, ���� �� ���Ͼ� �߰� - 
	if(LANGUAGE_TYPE_KOREAN == m_nLanguageT)
	{
		AfxMessageBox("Korean don't need to set this setting !!");
		return;
	}
	else if(FALSE == IS_VALID_LANGUAGE_TYPE(m_nLanguageT))
	{
		AfxMessageBox("LanguageType is invalid !!\r\n Please check LanguageType.");
		return;
	}


	CBrowseForFolder bf;
	bf.hWndOwner = this->m_hWnd;
	bf.strTitle = "Select folder that files for localization";
	CString sz;
	if (!bf.GetFolder(sz, (LPCSTR)m_ctl_strLocalizationPath))
		return;

	m_ctl_strLocalizationPath.Format("%s", sz);
	UpdateData(FALSE);
}
