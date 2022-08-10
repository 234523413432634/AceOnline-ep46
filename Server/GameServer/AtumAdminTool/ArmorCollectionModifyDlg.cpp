// ArmorCollectionModifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "SCUserAdminDlg.h"
#include "ArmorCollectionModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionModifyDlg dialog


CArmorCollectionModifyDlg::CArmorCollectionModifyDlg(COLLECTION_INFO* i_pInfo, CODBCStatement *i_pODBC, CSCUserAdminDlg* i_pMainDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CArmorCollectionModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CArmorCollectionModifyDlg)
	m_nShapeNum = 0;
	m_nShapeLevel = 0;
	m_strShapeName = _T("");
	m_strRemainTime = _T("");
	m_nRemainSeconds = 0;
	m_strOptionName = _T("");
	m_timeOptionDate = 0;
	m_timeOptionTime = 0;
	//}}AFX_DATA_INIT

	memcpy(&m_ModifyInfo, i_pInfo, sizeof(COLLECTION_INFO));
	m_pODBCStmt	= i_pODBC;
	m_pCUserAdminDlg		= i_pMainDlg;
}


void CArmorCollectionModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArmorCollectionModifyDlg)
	DDX_Control(pDX, IDC_CMDLG_COMBO_OPTION, m_ComboOptionList);
	DDX_Text(pDX, IDC_CMDLG_EDIT_SHAPE_NUM, m_nShapeNum);
	DDX_Text(pDX, IDC_CMDLG_EDIT_SHAPE_LEVEL, m_nShapeLevel);
	DDX_Text(pDX, IDC_CMDLG_EDIT_SHAPE_NAME, m_strShapeName);
	DDX_Text(pDX, IDC_CMDLG_EDIT_REMAIN_TIME_OUTPUT, m_strRemainTime);
	DDX_Text(pDX, IDC_CMDLG_EDIT_REMAIN_TIME_INPUT, m_nRemainSeconds);
	DDX_Text(pDX, IDC_CMDLG_EDIT_OPTION_NAME, m_strOptionName);
	DDX_DateTimeCtrl(pDX, IDC_CMDLG_DATEPICKER_DATE, m_timeOptionDate);
	DDX_DateTimeCtrl(pDX, IDC_CMDLG_TIMEPICKER_TIME, m_timeOptionTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArmorCollectionModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CArmorCollectionModifyDlg)
	ON_EN_CHANGE(IDC_CMDLG_EDIT_REMAIN_TIME_INPUT, OnChangeCmdlgEditRemainTimeInput)
	ON_EN_CHANGE(IDC_CMDLG_EDIT_SHAPE_LEVEL, OnChangeCmdlgEditShapeLevel)
	ON_BN_CLICKED(IDOK, OnApply)
	ON_CBN_SELCHANGE(IDC_CMDLG_COMBO_OPTION, OnSelchangeCmdlgComboOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionModifyDlg message handlers
BOOL CArmorCollectionModifyDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
        // 여기에 엔터키 기능 작성
		return TRUE;
    }
    else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
        // 여기에 ESC키 기능 작성
		CDialog::OnCancel();
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

BOOL CArmorCollectionModifyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	//	// Set the icon for this dialog.  The framework does this automatically
	//	//  when the application's main window is not a dialog
	//	SetIcon(m_hIcon, TRUE);			// Set big icon
	//	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_nShapeNum		= m_ModifyInfo.ShapeNum;

	char ShapeName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(m_ModifyInfo.ShapeNum, ShapeName);
	m_strShapeName	= (CString)ShapeName;

	m_nShapeLevel	= m_ModifyInfo.EnchantLevel;

	char RemainTime[SIZE_MAX_ITEM_NAME] = {0,};
	int day, hour, minute, second = 0;
	second = m_ModifyInfo.RemainSeconds%60;
	minute = (m_ModifyInfo.RemainSeconds/60)%60;
	hour = ((m_ModifyInfo.RemainSeconds/60)/60)%24;
	day = ((m_ModifyInfo.RemainSeconds/60)/60)/24;
	sprintf(RemainTime, "%02dday %02d:%02d:%02d", day, hour, minute, second);
	m_strRemainTime	= (CString)RemainTime;

	m_nRemainSeconds	= m_ModifyInfo.RemainSeconds;

	m_ComboOptionList.AddString("0");
	m_pCUserAdminDlg->GetItemInfoListByDesParam(&m_VectOptionItemList, DES_OPTION_ITEM_DEFAULT_DESPARAM);
	ITEM *pItemInfo = m_pCUserAdminDlg->GetItemByItemNum(m_ModifyInfo.ShapeNum);
	if(pItemInfo)
	{
		int forloofindex = 0;
		vectItemPtr::iterator itr = m_VectOptionItemList.begin();
		for ( ; itr != m_VectOptionItemList.end() ; itr++ )
		{
			if( IS_SAME_UNITKIND(pItemInfo->ReqUnitKind,(*itr)->ReqUnitKind) )
			{
				char szTemp[1024];
				sprintf(szTemp, "%d", (*itr)->ItemNum);
				m_ComboOptionList.AddString(szTemp);
				forloofindex++;
				if ( m_ModifyInfo.nOptionItemNum == (*itr)->ItemNum )
				{
					m_ComboOptionList.SetCurSel(forloofindex);
				}
			}
		}
	}
	if ( 0 > m_ComboOptionList.GetCurSel() )
	{
		m_ComboOptionList.SetCurSel(0);
	}

	char OptionItemName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(m_ModifyInfo.nOptionItemNum, OptionItemName);
	m_strOptionName	= (CString)OptionItemName;

	m_timeOptionDate = CTime(2000 < m_ModifyInfo.DurationTime.Year?m_ModifyInfo.DurationTime.Year:2000
		, 0 < m_ModifyInfo.DurationTime.Month?m_ModifyInfo.DurationTime.Month:1
		, 0 < m_ModifyInfo.DurationTime.Day?m_ModifyInfo.DurationTime.Day:1
		, m_ModifyInfo.DurationTime.Hour
		, m_ModifyInfo.DurationTime.Minute
		, m_ModifyInfo.DurationTime.Second);
	m_timeOptionTime = CTime(2000 < m_ModifyInfo.DurationTime.Year?m_ModifyInfo.DurationTime.Year:2000
		, 0 < m_ModifyInfo.DurationTime.Month?m_ModifyInfo.DurationTime.Month:1
		, 0 < m_ModifyInfo.DurationTime.Day?m_ModifyInfo.DurationTime.Day:1
		, m_ModifyInfo.DurationTime.Hour
		, m_ModifyInfo.DurationTime.Minute
		, m_ModifyInfo.DurationTime.Second);

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BOOL CArmorCollectionModifyDlg::UpdateArmorCollectionInfo()
{
	SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.CollectionType, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.AccountUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.CharacterUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.ShapeNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.ShapeItemNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &m_ModifyInfo.EnchantLevel, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 7, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.RemainSeconds, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 8, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_ModifyInfo.nOptionItemNum, 0, NULL);
	char tmpTimeString[SIZE_MAX_SQL_DATETIME_STRING] = {0,};
	if ( 0 != m_ModifyInfo.DurationTime.Year || 0 != m_ModifyInfo.DurationTime.Month || 0 != m_ModifyInfo.DurationTime.Day )
	{
		m_ModifyInfo.DurationTime.GetSQLDateTimeString(tmpTimeString, SIZE_MAX_SQL_DATETIME_STRING);
	}
	SQLBindParameter(m_pODBCStmt->m_hstmt, 9, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmpTimeString, 0,	NULL);
	
    SQLRETURN	ret = SQLExecDirect(m_pODBCStmt->m_hstmt, PROCEDURE_130531_0002, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO )
	{
//		ProcessLogMessagesField(SQL_HANDLE_STMT, m_pODBCStmt->m_hstmt,"QP_CollectionArmorUpdate Failed!\n", TRUE, q.pFieldIOCPSocket, q);
		SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);
		return FALSE;
	}
	return TRUE;
}

void CArmorCollectionModifyDlg::OnChangeCmdlgEditRemainTimeInput() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	char RemainTime[SIZE_MAX_ITEM_NAME] = {0,};
	int day, hour, minute, second = 0;
	second = m_nRemainSeconds%60;
	minute = (m_nRemainSeconds/60)%60;
	hour = ((m_nRemainSeconds/60)/60)%24;
	day = ((m_nRemainSeconds/60)/60)/24;
	sprintf(RemainTime, "%02dday %02d:%02d:%02d", day, hour, minute, second);
	m_strRemainTime	= (CString)RemainTime;
	UpdateData(FALSE);
}

void CArmorCollectionModifyDlg::OnChangeCmdlgEditShapeLevel() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if ( SHAPE_STAT_INIT_LEVEL >= m_nShapeLevel ) m_nShapeLevel = 1;
	else if ( SHAPE_STAT_MAX_LEVEL < m_nShapeLevel ) m_nShapeLevel = SHAPE_STAT_MAX_LEVEL;
	UpdateData(FALSE);
}

void CArmorCollectionModifyDlg::OnApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ModifyInfo.EnchantLevel = m_nShapeLevel;
	m_ModifyInfo.RemainSeconds = m_nRemainSeconds;
	CString strSelectOptionItemNum;
	int nSelectIndex = m_ComboOptionList.GetCurSel();
	m_ComboOptionList.GetLBText(nSelectIndex, strSelectOptionItemNum);
	m_ModifyInfo.nOptionItemNum = atoi(strSelectOptionItemNum);
	if ( 0 != m_ModifyInfo.nOptionItemNum )
	{
		m_ModifyInfo.DurationTime.SetDateTime(m_timeOptionDate.GetYear(), m_timeOptionDate.GetMonth(), m_timeOptionDate.GetDay(), m_timeOptionTime.GetHour(), m_timeOptionTime.GetMinute(), m_timeOptionTime.GetSecond());
	}
	else
	{
		m_ModifyInfo.DurationTime.Reset();
	}

	if ( TRUE == UpdateArmorCollectionInfo() )
	{
		MessageBox("Apply Success.");
	}
	else
	{
		MessageBox("Apply Fail!");
	}
	CDialog::OnCancel();
}


void CArmorCollectionModifyDlg::OnSelchangeCmdlgComboOption() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	CString strSelectOptionItemNum;
	int nSelectIndex = m_ComboOptionList.GetCurSel();
	m_ComboOptionList.GetLBText(nSelectIndex, strSelectOptionItemNum);
	char OptionItemName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(atoi(strSelectOptionItemNum), OptionItemName);
	m_strOptionName	= (CString)OptionItemName;
	UpdateData(FALSE);
}
