// SCHappyHourEventAdminDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "SCHappyHourEventAdminDlg.h"
#include "AtumAdminToolDlg.h"
#include "sethappyev.h"
#include "setpcbanghappyev.h"			// 2006-08-28 by cmkwon
#include "AtumSJ.h"						// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� -

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSCHappyHourEventAdminDlg dialog


CSCHappyHourEventAdminDlg::CSCHappyHourEventAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSCHappyHourEventAdminDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSCHappyHourEventAdminDlg)
	m_valueDTPTotalSetStartDate = COleDateTime::GetCurrentTime();
	m_valueDTPTotalSetEndDate = COleDateTime::GetCurrentTime();
	m_valueDTPTotalSetStartTime = COleDateTime::GetCurrentTime();
	m_valueDTPTotalSetEndTime = COleDateTime::GetCurrentTime();
	m_OleDatePCBangStart = COleDateTime::GetCurrentTime();
	m_OleTimePCBangStart = COleDateTime::GetCurrentTime();
	m_OleDatePCBangEnd = COleDateTime::GetCurrentTime();
	m_OleTimePCBangEnd = COleDateTime::GetCurrentTime();
	m_ctlOleDateNormalStart = COleDateTime::GetCurrentTime();
	m_ctlOleDateNormalEnd = COleDateTime::GetCurrentTime();
	m_ctlOleDateVCNStart = COleDateTime::GetCurrentTime();
	m_ctlOleDateVCNEnd = COleDateTime::GetCurrentTime();
	m_ctlOleDateANIStart = COleDateTime::GetCurrentTime();
	m_ctlOleDateANIEnd = COleDateTime::GetCurrentTime();
	m_ctlOleTimeNormalStart = COleDateTime::GetCurrentTime();
	m_ctlOleTimeNormalEnd = COleDateTime::GetCurrentTime();
	m_ctlOleTimeVCNStart = COleDateTime::GetCurrentTime();
	m_ctlOleTimeVCNEnd = COleDateTime::GetCurrentTime();
	m_ctlOleTimeANIStart = COleDateTime::GetCurrentTime();
	m_ctlOleTimeANIEnd = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	m_pMainDlg = (CAtumAdminToolDlg*)AfxGetMainWnd();
	m_pODBCStmt = new CODBCStatement;

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� ������ �ּ� ó���ϰ� �迭 ������ �߰���
//	m_nHappyEvUID			= 0;
	MEMSET_ZERO(&m_PCBangHappyEv, sizeof(m_PCBangHappyEv));		// 2006-08-25 by cmkwon

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ʱ�ȭ
	for(int i=0; i < INFLUENCE_TYPE_COUNT; i++)
	{
		m_arrHappyEvPeriodStart[i].Reset();
		m_arrHappyEvPeriodEND[i].Reset();
	}
}

// �Ҹ���
CSCHappyHourEventAdminDlg::~CSCHappyHourEventAdminDlg()
{
	SAFE_DELETE(m_pODBCStmt);
}

void CSCHappyHourEventAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSCHappyHourEventAdminDlg)
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_valueDTPTotalSetStartDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER3, m_valueDTPTotalSetEndDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_valueDTPTotalSetStartTime);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER4, m_valueDTPTotalSetEndTime);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_PCBANG_START, m_OleDatePCBangStart);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_PCBANG_START, m_OleTimePCBangStart);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_PCBANG_END, m_OleDatePCBangEnd);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_PCBANG_END, m_OleTimePCBangEnd);
	DDX_Control(pDX, IDC_GRID_EVENT_DETAIL, m_GridDetail);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_NORMAL_START, m_ctlOleDateNormalStart);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_NORMAL_END, m_ctlOleDateNormalEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_VCN_START, m_ctlOleDateVCNStart);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_VCN_END, m_ctlOleDateVCNEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_ANI_START, m_ctlOleDateANIStart);
	DDX_DateTimeCtrl(pDX, IDC_DATEPICKER_ANI_END, m_ctlOleDateANIEnd);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_NORMAL_START, m_ctlOleTimeNormalStart);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_NORMAL_END, m_ctlOleTimeNormalEnd);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_VCN_START, m_ctlOleTimeVCNStart);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_VCN_END, m_ctlOleTimeVCNEnd);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_ANI_START, m_ctlOleTimeANIStart);
	DDX_DateTimeCtrl(pDX, IDC_TIMEPICKER_ANI_END, m_ctlOleTimeANIEnd);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT_DROPITEMRATE, m_PCBangHappyEv.fDropItemRate2);
	DDX_Text(pDX, IDC_EDIT_DROPRAREITEMRATE, m_PCBangHappyEv.fDropRareItemRate2);
	DDX_Text(pDX, IDC_EDIT_EXPRATE, m_PCBangHappyEv.fEXPRate2);
	DDX_Text(pDX, IDC_EDIT_EXPREPAIRRATE, m_PCBangHappyEv.fEXPRepairRate2);
	DDX_Text(pDX, IDC_EDIT_SPIRATE, m_PCBangHappyEv.fSPIRate2);
	DDX_Text(pDX, IDC_EDIT_WPRATE, m_PCBangHappyEv.fWarPointRate2);				// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰� 

	DDX_Text(pDX, IDC_EDIT_HP_RECOVERY_RATE2, m_PCBangHappyEv.fHPRecoveryRate);		// 2013-08-12 by bckim, �ű����Ǿƿ�	// PC
	DDX_Text(pDX, IDC_EDIT_SHD_RECOVERY_RATE2, m_PCBangHappyEv.fSHDRecoveryRate);	
	DDX_Text(pDX, IDC_EDIT_SP_RECOVERY_RATE2, m_PCBangHappyEv.fSPRecoveryRate);	
	DDX_Text(pDX, IDC_EDIT_WEAPON_ENCHANT_RATE2, m_PCBangHappyEv.fWeaponEnchantRate);	
	DDX_Text(pDX, IDC_EDIT_ARMOR_ENCHANT_RATE2, m_PCBangHappyEv.fArmorEnchantRate);	
	DDX_Text(pDX, IDC_EDIT_ETC_ITEM_ENCHANT_RATE2, m_PCBangHappyEv.fETCItemEnchantRate);	
	DDX_Text(pDX, IDC_EDIT_SPI_DISCOUNT_RATE2, m_PCBangHappyEv.fSPIDiscountRate);	
	DDX_Text(pDX, IDC_EDIT_WP_DISCOUNT_RATE2, m_PCBangHappyEv.fWPDiscountRate);		// End. 2013-08-12 by bckim, �ű����Ǿƿ�
	
}


BEGIN_MESSAGE_MAP(CSCHappyHourEventAdminDlg, CDialog)
	//{{AFX_MSG_MAP(CSCHappyHourEventAdminDlg)
	ON_BN_CLICKED(IDC_BUTTON_TOTAL_UPDATE, OnButtonTotalUpdate)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_COMMAND(IDR_CONMENU_SELECTED_INSERT, OnConmenuSelectedInsert)
	ON_COMMAND(IDR_CONMENU_SELECTED_UPDATE, OnConmenuSelectedUpdate)
	ON_COMMAND(IDR_CONMENU_SELECTED_DELETE, OnConmenuSelectedDelete)
	ON_COMMAND(IDR_CONMENU_NOTSELECTED_INSERT, OnConmenuNotselectedInsert)
	ON_BN_CLICKED(IDC_BTN_UPDATE_PCBANG_HAPPYEV, OnBtnUpdatePcbangHappyev)
	ON_BN_CLICKED(IDC_BTN_RELOAD_HAPPYHOUREV, OnBtnReloadHappyEv)
	ON_BN_CLICKED(IDC_BTN_RELOAD_PCBANG_LIST, OnBtnReloadPCbangList)
	ON_BN_CLICKED(IDC_BTN_UPDATE_PERIOD_NORMAL, OnBtnUpdatePeriodNormal)
	ON_BN_CLICKED(IDC_BTN_UPDATE_PERIOD_VCN, OnBtnUpdatePeriodVcn)
	ON_BN_CLICKED(IDC_BTN_UPDATE_PERIOD_ANI, OnBtnUpdatePeriodAni)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_RCLICK, IDC_GRID_EVENT_DETAIL, OnGridRClick)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSCHappyHourEventAdminDlg message handlers

BOOL CSCHappyHourEventAdminDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	// Connect DB
	if (!m_pODBCStmt->Init(m_pMainDlg->m_pServerInfo4Admin->DBIP, m_pMainDlg->m_pServerInfo4Admin->DBPort, m_pMainDlg->m_pServerInfo4Admin->DBName,
							m_pMainDlg->m_pServerInfo4Admin->DBUID, m_pMainDlg->m_pServerInfo4Admin->DBPWD, GetSafeHwnd())
	)
	{
		MessageBox(STRERR_S_SCADMINTOOL_0013);
		EndDialog(-1);
		return FALSE;
	}

	//���� DB�� �ִ� �� �ҷ��´�.
	GetHappyHourEventDetailInfo();

	///////////////////////////////////////////////////////////////////////////////
	// 2007-10-02 by cmkwon, SCAdminTool ���� ���� ó�� - ���Ǿƿ� �̺�Ʈ ó��
	// 2012-02-01 by jhseol, ��Ʈ�� GM ���� ����
#ifdef S_MANAGER_ADMIN_HSSON
	GetDlgItem(IDC_BUTTON_TOTAL_UPDATE)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));
	GetDlgItem(IDC_BTN_UPDATE_PCBANG_HAPPYEV)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));
	GetDlgItem(IDC_BTN_RELOAD_HAPPYHOUREV)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_NORMAL)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));	// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_VCN)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));		// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_ANI)->EnableWindow(COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION));		// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
#else
	GetDlgItem(IDC_BUTTON_TOTAL_UPDATE)->EnableWindow(m_pMainDlg->IsManagerAdministrator());
	GetDlgItem(IDC_BTN_UPDATE_PCBANG_HAPPYEV)->EnableWindow(m_pMainDlg->IsManagerAdministrator());
	GetDlgItem(IDC_BTN_RELOAD_HAPPYHOUREV)->EnableWindow(m_pMainDlg->IsManagerAdministrator());
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_NORMAL)->EnableWindow(m_pMainDlg->IsManagerAdministrator());	// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_VCN)->EnableWindow(m_pMainDlg->IsManagerAdministrator());		// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
	GetDlgItem(IDC_BTN_UPDATE_PERIOD_ANI)->EnableWindow(m_pMainDlg->IsManagerAdministrator());		// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
#endif
	// end 2012-02-01 by jhseol, ��Ʈ�� GM ���� ����
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CSCHappyHourEventAdminDlg::InitGridDetail()
{
	m_GridDetail.SetBkColor(0xFFFFFF);

	int m_nRows = 1;
	int m_nCols = 14;			// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� �ʵ� �߰�

	// 2013-08-12 by bckim, �ű����Ǿƿ�
#ifdef SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM		
	m_nCols += 8;
#endif
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�

	m_GridDetail.SetEditable(FALSE);
	m_GridDetail.SetListMode(TRUE);
	m_GridDetail.SetSingleRowSelection(TRUE);
	m_GridDetail.EnableSelection(TRUE);
	m_GridDetail.SetFrameFocusCell(FALSE);
	m_GridDetail.SetTrackFocusCell(FALSE);

	m_GridDetail.SetRowCount(m_nRows);
	m_GridDetail.SetColumnCount(m_nCols);
	m_GridDetail.SetFixedRowCount(1);
	m_GridDetail.SetColumnWidth(0, 0);

	// Į�� �����
	m_nCols = 0;
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = 0;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE;

	Item.col = m_nCols++;
	Item.strText.Format("EvnetUID");
	m_GridDetail.SetItem(&Item);

	// 2006-08-25 by cmkwon
	Item.col = m_nCols++;
	Item.strText.Format("ServerGroup");
	m_GridDetail.SetItem(&Item);

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� -
	Item.col = m_nCols++;
	Item.strText.Format("Influence");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("Day Of Week");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("MinLevel");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("MaxLevel");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("Start Time");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("End Time");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("EXP Plus");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("SPI Plus");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("EXPRepair Plus");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("DropItem Plus");
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("DropRareItem Plus");
	m_GridDetail.SetItem(&Item);

	// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
	Item.col = m_nCols++;
	Item.strText.Format("WarPoint Plus");
	m_GridDetail.SetItem(&Item);	

	// 2013-08-12 by bckim, �ű����Ǿƿ�
#ifdef SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM		//	InitGridDetail
	Item.col = m_nCols++;
	Item.strText.Format("HPR Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("DPR Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("SPR Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("Weapon Ent Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("Armor Ent Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("Etc Ent Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("SPI Sale Plus");
	m_GridDetail.SetItem(&Item);	
	
	Item.col = m_nCols++;
	Item.strText.Format("WP Sale Plus");
	m_GridDetail.SetItem(&Item);	
#endif
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�

	// arrange grid
	m_GridDetail.AutoSize();
	m_GridDetail.ExpandColumnsToFit();

	// clean all cells
	CCellRange tmpCellRange(1, 0, m_GridDetail.GetRowCount()-1, m_GridDetail.GetColumnCount()-1);
	m_GridDetail.ClearCells(tmpCellRange);
}



void CSCHappyHourEventAdminDlg::GetHappyHourEventDetailInfo()
{
	this->InitGridDetail();
	
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = 1;
	Item.nFormat = GRID_CELL_FORMAT;
	
	CString szSQLQuery;
	// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - MinLevel, MaxLevel �߰�
	// szSQLQuery.Format("SELECT uniquenumber, ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate, InfluenceType, MinLevel, MaxLevel \
	//	FROM ti_HappyHourEvent WITH (NOLOCK) order by ServerGroupID, InfluenceType, dayofweek");
	// 2008-07-02 by cmkwon, MySQL ���� ���� - 
	//szSQLQuery.Format("SELECT uniquenumber, ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate, InfluenceType, MinLevel, MaxLevel \
	//	FROM ti_HappyHourEvent WITH (NOLOCK) order by ServerGroupID, InfluenceType, dayofweek");

// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
//	szSQLQuery.Format(QUERY_080702_0025);		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
//	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szSQLQuery);

	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0025));

	if (!bRet)
	{
		// clean up
		m_pODBCStmt->FreeStatement();
		MessageBox("Error");
		return;
	}

	CString starttime;
	SQLINTEGER arrCB[23] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
							SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
							SQL_NTS,SQL_NTS,SQL_NTS};			// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - MinLevel, MaxLevel �߰�
																// 2013-08-12 by bckim, �ű����Ǿƿ�

	SHAPPY_HOUR_EVENT tmHappyEv;	
	MEMSET_ZERO(&tmHappyEv, sizeof(tmHappyEv));

	SQL_TIMESTAMP_STRUCT tmpStartTime;
	SQL_TIMESTAMP_STRUCT tmpEndTime;

	SQLBindCol(m_pODBCStmt->m_hstmt, 1, SQL_C_ULONG, &tmHappyEv.EventUniqueNumber, 0,			&arrCB[1]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 2, SQL_C_ULONG, &tmHappyEv.ServerGroupID, 0,				&arrCB[2]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 3, SQL_C_ULONG, &tmHappyEv.DayOfWeek, 0,					&arrCB[3]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 4, SQL_C_TIMESTAMP, &tmpStartTime, 0,						&arrCB[4]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 5, SQL_C_TIMESTAMP, &tmpEndTime, 0,						&arrCB[5]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 6, SQL_C_FLOAT, &tmHappyEv.fEXPRate2, SIZE_MAX_ITEM_NAME,	&arrCB[6]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 7, SQL_C_FLOAT, &tmHappyEv.fSPIRate2, 0,					&arrCB[7]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 8, SQL_C_FLOAT, &tmHappyEv.fEXPRepairRate2, 0,				&arrCB[8]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 9, SQL_C_FLOAT, &tmHappyEv.fDropItemRate2, 0,				&arrCB[9]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 10, SQL_C_FLOAT, &tmHappyEv.fDropRareItemRate2, 0,			&arrCB[10]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 11, SQL_C_FLOAT, &tmHappyEv.fWarPointRate2, 0,				&arrCB[11]);		// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
	SQLBindCol(m_pODBCStmt->m_hstmt, 12, SQL_C_TINYINT, &tmHappyEv.InfluenceType3, 0,			&arrCB[12]);		// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - InfluenceType �ʵ� �߰�
	SQLBindCol(m_pODBCStmt->m_hstmt, 13, SQL_C_ULONG, &tmHappyEv.MinLevel, 0,					&arrCB[13]);		// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - 
	SQLBindCol(m_pODBCStmt->m_hstmt, 14, SQL_C_ULONG, &tmHappyEv.MaxLevel, 0,					&arrCB[14]);		// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - 

	// 2013-08-12 by bckim, �ű����Ǿƿ�
	SQLBindCol(m_pODBCStmt->m_hstmt, 15, SQL_C_FLOAT, &tmHappyEv.fHPRecoveryRate, 0,			&arrCB[15]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 16, SQL_C_FLOAT, &tmHappyEv.fSHDRecoveryRate, 0,			&arrCB[16]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 17, SQL_C_FLOAT, &tmHappyEv.fSPRecoveryRate, 0,			&arrCB[17]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 18, SQL_C_FLOAT, &tmHappyEv.fWeaponEnchantRate, 0,			&arrCB[18]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 19, SQL_C_FLOAT, &tmHappyEv.fArmorEnchantRate, 0,			&arrCB[19]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 20, SQL_C_FLOAT, &tmHappyEv.fETCItemEnchantRate, 0,		&arrCB[20]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 21, SQL_C_FLOAT, &tmHappyEv.fSPIDiscountRate, 0,			&arrCB[21]);
	SQLBindCol(m_pODBCStmt->m_hstmt, 22, SQL_C_FLOAT, &tmHappyEv.fWPDiscountRate, 0,			&arrCB[22]);
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� ������ �ּ� ó���ϰ� �迭 ������ �߰���
//	m_nHappyEvUID			= 0;
	MEMSET_ZERO(&m_PCBangHappyEv, sizeof(m_PCBangHappyEv));		// 2006-08-28 by cmkwon
	m_mtvectHappyEventList.clear();			// 2006-08-25 by cmkwon, 
	// DB�� ���� ���������� loop�� ����
	while ( (bRet = SQLFetch(m_pODBCStmt->m_hstmt)) != SQL_NO_DATA)
	{
		tmHappyEv.atimeStartTime2	= tmpStartTime;
		tmHappyEv.atimeEndTime2		= tmpEndTime;		

		// 2013-08-12 by bckim, �ű����Ǿƿ�
#ifndef SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM		// ��� select 
		tmHappyEv.fHPRecoveryRate		= 0.0f;
		tmHappyEv.fSHDRecoveryRate		= 0.0f;
		tmHappyEv.fSPRecoveryRate		= 0.0f;
		tmHappyEv.fWeaponEnchantRate	= 0.0f;
		tmHappyEv.fArmorEnchantRate		= 0.0f;
		tmHappyEv.fETCItemEnchantRate	= 0.0f;
		tmHappyEv.fSPIDiscountRate		= 0.0f;
		tmHappyEv.fWPDiscountRate		= 0.0f;
#endif
		// End. 2013-08-12 by bckim, �ű����Ǿƿ�

		// 2013-08-12 by bckim, �ű����Ǿƿ�	//	�ӽ�
		if( DAY_OF_WEEK_PCBANG_HAPPYHOUREVENT == tmHappyEv.DayOfWeek )
		{	
			tmHappyEv.MinLevel = 1;
			tmHappyEv.MaxLevel = CHARACTER_LEVEL_110;
		}
		// End. 2013-08-12 by bckim, �ű����Ǿƿ�

		m_mtvectHappyEventList.push_back(tmHappyEv);

		MEMSET_ZERO(&tmHappyEv, sizeof(tmHappyEv));
	}
	m_pODBCStmt->FreeStatement();	// clean up

	for(int i=0; i < m_mtvectHappyEventList.size(); i++)
	{
		SHAPPY_HOUR_EVENT *pHappyEv = &m_mtvectHappyEventList[i];
		switch(pHappyEv->DayOfWeek)
		{
		case DAY_OF_WEEK_SUMDAY:
		case DAY_OF_WEEK_MONDAY:
		case DAY_OF_WEEK_TUESDAY:
		case DAY_OF_WEEK_WEDNESDAY:
		case DAY_OF_WEEK_THURSDAY:
		case DAY_OF_WEEK_FRIDAY:
		case DAY_OF_WEEK_SATURDAY:
			{
				int nRowCount = m_GridDetail.GetRowCount();
				m_GridDetail.SetRowCount(nRowCount+1);
				InsertItemToGridDetail(pHappyEv, nRowCount);
			}
			break;
		case DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD:
			{

				// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� -
				ATUM_DATE_TIME *patStart	= this->GetHappyEvPeriodStartDateTime(pHappyEv->InfluenceType3);
				ATUM_DATE_TIME *patEnd		= this->GetHappyEvPeriodEndDateTime(pHappyEv->InfluenceType3);
				if(NULL == patStart
					|| NULL == patEnd)
				{
					continue;
				}

				*patStart		= pHappyEv->atimeStartTime2;
				*patEnd			= pHappyEv->atimeEndTime2;				
				switch(pHappyEv->InfluenceType3)
				{
				case INFLUENCE_TYPE_NORMAL:
					{
						m_ctlOleDateNormalStart.SetDate(patStart->Year, patStart->Month, patStart->Day);
						m_ctlOleTimeNormalStart.SetTime(patStart->Hour, patStart->Minute, 0);

						m_ctlOleDateNormalEnd.SetDate(patEnd->Year, patEnd->Month, patEnd->Day);
						m_ctlOleTimeNormalEnd.SetTime(patEnd->Hour, patEnd->Minute, 0);
					}
					break;
				case INFLUENCE_TYPE_VCN:
					{
						m_ctlOleDateVCNStart.SetDate(patStart->Year, patStart->Month, patStart->Day);
						m_ctlOleTimeVCNStart.SetTime(patStart->Hour, patStart->Minute, 0);

						m_ctlOleDateVCNEnd.SetDate(patEnd->Year, patEnd->Month, patEnd->Day);
						m_ctlOleTimeVCNEnd.SetTime(patEnd->Hour, patEnd->Minute, 0);
					}
					break;
				case INFLUENCE_TYPE_ANI:
					{
						m_ctlOleDateANIStart.SetDate(patStart->Year, patStart->Month, patStart->Day);
						m_ctlOleTimeANIStart.SetTime(patStart->Hour, patStart->Minute, 0);

						m_ctlOleDateANIEnd.SetDate(patEnd->Year, patEnd->Month, patEnd->Day);
						m_ctlOleTimeANIEnd.SetTime(patEnd->Hour, patEnd->Minute, 0);
					}
					break;
				case INFLUENCE_TYPE_ALL_MASK:
					{
						m_valueDTPTotalSetStartDate.SetDate(patStart->Year, patStart->Month, patStart->Day);
						m_valueDTPTotalSetStartTime.SetTime(patStart->Hour, patStart->Minute, 0);

						m_valueDTPTotalSetEndDate.SetDate(patEnd->Year, patEnd->Month, patEnd->Day);
						m_valueDTPTotalSetEndTime.SetTime(patEnd->Hour, patEnd->Minute, 0);
					}
					break;
				}
				UpdateData(FALSE);
			}
			break;
		case DAY_OF_WEEK_PCBANG_HAPPYHOUREVENT:
			{
				m_PCBangHappyEv					= *pHappyEv;
				m_OleDatePCBangStart.SetDate(m_PCBangHappyEv.atimeStartTime2.Year, m_PCBangHappyEv.atimeStartTime2.Month, m_PCBangHappyEv.atimeStartTime2.Day);
				m_OleTimePCBangStart.SetTime(m_PCBangHappyEv.atimeStartTime2.Hour, m_PCBangHappyEv.atimeStartTime2.Minute, 0);

				m_OleDatePCBangEnd.SetDate(m_PCBangHappyEv.atimeEndTime2.Year, m_PCBangHappyEv.atimeEndTime2.Month, m_PCBangHappyEv.atimeEndTime2.Day);
				m_OleTimePCBangEnd.SetTime(m_PCBangHappyEv.atimeEndTime2.Hour, m_PCBangHappyEv.atimeEndTime2.Minute, 0);

				UpdateData(FALSE);
			}
			break;
		}
	}

	m_GridDetail.AutoSize();
	//m_GridDetail.ExpandColumnsToFit();		// 2013-08-12 by bckim, �ű����Ǿƿ�
}

void CSCHappyHourEventAdminDlg::InsertItemToGridDetail(SHAPPY_HOUR_EVENT *i_pHappyEv, int i_nRow)
{
	// Į�� �����
	int m_nCols = 0;

	// �÷��� �� �ֱ�
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = i_nRow;
	Item.nFormat = GRID_CELL_FORMAT;

	Item.col = m_nCols++;
	Item.strText.Format("%d", i_pHappyEv->EventUniqueNumber);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	if(0 == i_pHappyEv->ServerGroupID)
	{
		Item.strText.Format("%s", STR_ALL_SERVERGROUP_NAME);
	}
	else
	{
		Item.strText.Format("server %d", 1 + (i_pHappyEv->ServerGroupID - SERVERGROUP_START_ID));
	}
	m_GridDetail.SetItem(&Item);

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� �ʵ� �߰�	
	Item.col = m_nCols++;
	Item.strText.Format("%s", CAtumSJ::GetInfluenceTypeString(i_pHappyEv->InfluenceType3));
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%s", DayofWeekToString(i_pHappyEv->DayOfWeek));
	m_GridDetail.SetItem(&Item);

	// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - 
	Item.col = m_nCols++;
	Item.strText.Format("%d", i_pHappyEv->MinLevel);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%d", i_pHappyEv->MaxLevel);
	m_GridDetail.SetItem(&Item);


	Item.col = m_nCols++;
	Item.strText.Format("%s", i_pHappyEv->atimeStartTime2.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
	Item.strText = Item.strText.Right(8);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%s", i_pHappyEv->atimeEndTime2.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
	Item.strText = Item.strText.Right(8);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fEXPRate2);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fSPIRate2);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fEXPRepairRate2);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fDropItemRate2);
	m_GridDetail.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fDropRareItemRate2);
	m_GridDetail.SetItem(&Item);

	// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fWarPointRate2);
	m_GridDetail.SetItem(&Item);


	// 2013-08-12 by bckim, �ű����Ǿƿ�
#ifdef SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM		//	InsertItemToGridDetail
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fHPRecoveryRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fSHDRecoveryRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fSPRecoveryRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fWeaponEnchantRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fArmorEnchantRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fETCItemEnchantRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fSPIDiscountRate);
	m_GridDetail.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%.1f", i_pHappyEv->fWPDiscountRate);
	m_GridDetail.SetItem(&Item);

#endif
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�


}

void CSCHappyHourEventAdminDlg::OnButtonTotalUpdate() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	ATUM_DATE_TIME *pATStart	= GetHappyEvPeriodStartDateTime(INFLUENCE_TYPE_ALL_MASK);
	ATUM_DATE_TIME *pATEnd		= GetHappyEvPeriodEndDateTime(INFLUENCE_TYPE_ALL_MASK);

	pATStart->SetDateTime(m_valueDTPTotalSetStartDate.GetYear(), m_valueDTPTotalSetStartDate.GetMonth(), m_valueDTPTotalSetStartDate.GetDay()
		, m_valueDTPTotalSetStartTime.GetHour(), m_valueDTPTotalSetStartTime.GetMinute(), 0);
	pATEnd->SetDateTime(m_valueDTPTotalSetEndDate.GetYear(), m_valueDTPTotalSetEndDate.GetMonth(), m_valueDTPTotalSetEndDate.GetDay()
		, m_valueDTPTotalSetEndTime.GetHour(), m_valueDTPTotalSetEndTime.GetMinute(), 0);

	// 2007-11-01 by cmkwon, DB �� ������Ʈ �Ѵ�.
	this->UpdateHappyHourEventPeriod(INFLUENCE_TYPE_ALL_MASK, pATStart, pATEnd);

	// 2007-11-01 by cmkwon, ��� �̺�Ʈ ������ �ٽ� �ε��Ѵ�.
	GetHappyHourEventDetailInfo();

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - UpdateHappyHourEventPeriod() �Լ��� ó��, ���� ���� ���� ��
//	m_atiHappyEvStartDateTime.SetDateTime(m_valueDTPTotalSetStartDate.GetYear(), m_valueDTPTotalSetStartDate.GetMonth(), m_valueDTPTotalSetStartDate.GetDay()
//		, m_valueDTPTotalSetStartTime.GetHour(), m_valueDTPTotalSetStartTime.GetMinute(), 0);
//	m_atiHappyEvEndDateTime.SetDateTime(m_valueDTPTotalSetEndDate.GetYear(), m_valueDTPTotalSetEndDate.GetMonth(), m_valueDTPTotalSetEndDate.GetDay()
//		, m_valueDTPTotalSetEndTime.GetHour(), m_valueDTPTotalSetEndTime.GetMinute(), 0);
//
//	CString szQuery;
//	if(0 == m_nHappyEvUID)
//	{// 2006-08-25 by cmkwon, �߰��ؾ���
//		szQuery.Format("INSERT ti_happyhourevent(ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate) values( 0, %d, '%s', '%s', 0, 0, 0, 0, 0, 0)"
//			, DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD
//			, m_atiHappyEvStartDateTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING))
//			, m_atiHappyEvEndDateTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));	// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
//	}
//	else
//	{// 2006-08-25 by cmkwon, Update
//		szQuery.Format("UPDATE ti_happyhourevent SET starttime = '%s', endtime = '%s' where UniqueNumber= %d"
//			, m_atiHappyEvStartDateTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING))
//			, m_atiHappyEvEndDateTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING))
//			, m_nHappyEvUID);
//	}
//
//	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
//	if (!bRet)
//	{
//		m_pODBCStmt->FreeStatement();		// cleanup
//
//		MessageBox("HappyHourEvent period error !!");
//		return;
//	}
//	m_pODBCStmt->FreeStatement();	// cleanup
//
//	GetHappyHourEventDetailInfo();
}


CString CSCHappyHourEventAdminDlg::DayofWeekToString(int nDayofweek)
{
	// int�� ���ϰ��� ���ڿ������� ������Ų��
	switch(nDayofweek)
	{
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	}
	return "FALSE";
}
void CSCHappyHourEventAdminDlg::OnButtonEnd() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void CSCHappyHourEventAdminDlg::OnConmenuSelectedInsert() 
{
	// TODO: Add your command handler code here

	
	CSetHappyEv	dlg(TRUE, this);
	if (IDOK != dlg.DoModal())
	{
		return;
	}

	if(FALSE == CheckHappyHourEvent(&dlg.m_happyEv))
	{
		return;
	}

	// �� ctrl�� ���� �ٹ����� insert�Ѵ�.
	CString szQuery;

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - InfluenceType �ʵ� �߰�
	// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 	szQuery.Format("INSERT ti_happyhourevent(ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate, InfluenceType, MinLevel, MaxLevel \
// 					) values( %d, %d, '%s', '%s', %6.4f, %6.4f, %6.4f, %6.4f, %6.4f, %6.4f, %d, %d, %d)"
// 		, dlg.m_happyEv.ServerGroupID, dlg.m_happyEv.DayOfWeek
// 		, dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		, dlg.m_happyEv.fEXPRate2, dlg.m_happyEv.fSPIRate2, dlg.m_happyEv.fEXPRepairRate2
// 		, dlg.m_happyEv.fDropItemRate2, dlg.m_happyEv.fDropRareItemRate2, dlg.m_happyEv.fWarPointRate2, dlg.m_happyEv.InfluenceType3
// 		, dlg.m_happyEv.MinLevel, dlg.m_happyEv.MaxLevel);	// 2008-03-14 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - // 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�

// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
// 	szQuery.Format(QUERY_080702_0026		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 		, dlg.m_happyEv.ServerGroupID, dlg.m_happyEv.DayOfWeek
// 		, dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		, dlg.m_happyEv.fEXPRate2, dlg.m_happyEv.fSPIRate2, dlg.m_happyEv.fEXPRepairRate2
// 		, dlg.m_happyEv.fDropItemRate2, dlg.m_happyEv.fDropRareItemRate2, dlg.m_happyEv.fWarPointRate2, dlg.m_happyEv.InfluenceType3
// 		, dlg.m_happyEv.MinLevel, dlg.m_happyEv.MaxLevel);	// 2008-03-14 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - // 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
// 
// 	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
	char tmStartTime[SIZE_MAX_SQL_DATETIME_STRING];		dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(tmStartTime, SIZE_MAX_SQL_DATETIME_STRING);
	char tmEndTime[SIZE_MAX_SQL_DATETIME_STRING];		dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(tmEndTime, SIZE_MAX_SQL_DATETIME_STRING);
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();
	SQLINTEGER arrCB2[22] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
							SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
								SQL_NTS,SQL_NTS};		// 2013-08-12 by bckim, �ű����Ǿƿ�

	SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.ServerGroupID), 0,			&arrCB2[1]);
	SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.DayOfWeek), 0,				&arrCB2[2]);
	SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmStartTime, 0,	&arrCB2[3]);
	SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmEndTime, 0,		&arrCB2[4]);
	SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fEXPRate2), 0,				&arrCB2[5]);
	SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPIRate2), 0,				&arrCB2[6]);
	SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fEXPRepairRate2), 0,			&arrCB2[7]);
	SQLBindParameter(hstmt, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fDropItemRate2), 0,			&arrCB2[8]);
	SQLBindParameter(hstmt, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fDropRareItemRate2), 0,		&arrCB2[9]);
	SQLBindParameter(hstmt, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWarPointRate2), 0,			&arrCB2[10]);
	SQLBindParameter(hstmt, 11, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &(dlg.m_happyEv.InfluenceType3), 0,		&arrCB2[11]);
	SQLBindParameter(hstmt, 12, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.MinLevel), 0,				&arrCB2[12]);
	SQLBindParameter(hstmt, 13, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.MaxLevel), 0,				&arrCB2[13]);	
	// 2013-08-12 by bckim, �ű����Ǿƿ�		//	INSERT QUERY 
	SQLBindParameter(hstmt, 14, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fHPRecoveryRate), 0,			&arrCB2[14]);
	SQLBindParameter(hstmt, 15, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSHDRecoveryRate), 0,		&arrCB2[15]);
	SQLBindParameter(hstmt, 16, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPRecoveryRate), 0,			&arrCB2[16]);
	SQLBindParameter(hstmt, 17, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWeaponEnchantRate), 0,		&arrCB2[17]);
	SQLBindParameter(hstmt, 18, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fArmorEnchantRate), 0,		&arrCB2[18]);
	SQLBindParameter(hstmt, 19, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fETCItemEnchantRate), 0,		&arrCB2[19]);
	SQLBindParameter(hstmt, 20, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPIDiscountRate), 0,		&arrCB2[20]);
	SQLBindParameter(hstmt, 21, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWPDiscountRate), 0,			&arrCB2[21]);
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�	
	
	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0026));
	
	if (!bRet)
	{
		m_pODBCStmt->FreeStatement();		// cleanup

		MessageBox("HappyHourEvent insert error !!");
		return;
	}
	m_pODBCStmt->FreeStatement();	// cleanup

	this->GetHappyHourEventDetailInfo();
}

void CSCHappyHourEventAdminDlg::OnConmenuSelectedUpdate() 
{
	// TODO: Add your command handler code here
	CCellID cellID = m_GridDetail.GetFocusCell();
	if(0 >= cellID.row)
	{// 2006-08-25 by cmkwon, ���� ����
		return;
	}

	int nHappyEvUID				= atoi(m_GridDetail.GetItemText(cellID.row, 0));
	SHAPPY_HOUR_EVENT	*pHappyEv = this->FindHappyHourEvent(nHappyEvUID);
	if(NULL == pHappyEv)
	{
		return;
	}

	CSetHappyEv	dlg(FALSE, this);
	dlg.m_happyEv = *pHappyEv;

	if (IDOK != dlg.DoModal())
	{
		return;
	}

	if(FALSE == CheckHappyHourEvent(&dlg.m_happyEv))
	{
		return;
	}


	CString szQuery;

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - InfluenceType �ʵ� �߰�
	// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
	// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - MinLevel, MaxLevel �ʵ� �߰�
// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 	szQuery.Format("UPDATE ti_happyhourevent SET ServerGroupID= %d, dayofweek= %d, starttime = '%s', endtime = '%s', exprate = %6.2f, spirate = %6.2f, exprepairrate = %6.2f, dropitemrate = %6.2f, droprareitemrate = %6.2f , WarPointRate = %6.2f, InfluenceType = %d, MinLevel = %d, MaxLevel = %d where uniquenumber= %d",
// 		dlg.m_happyEv.ServerGroupID, dlg.m_happyEv.DayOfWeek
// 		, dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		, dlg.m_happyEv.fEXPRate2, dlg.m_happyEv.fSPIRate2, dlg.m_happyEv.fEXPRepairRate2
// 		, dlg.m_happyEv.fDropItemRate2, dlg.m_happyEv.fDropRareItemRate2, dlg.m_happyEv.fWarPointRate2, dlg.m_happyEv.InfluenceType3
// 		, dlg.m_happyEv.MinLevel, dlg.m_happyEv.MaxLevel, dlg.m_happyEv.EventUniqueNumber);	

// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
// 	szQuery.Format(QUERY_080702_0027,		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 		dlg.m_happyEv.ServerGroupID, dlg.m_happyEv.DayOfWeek
// 		, dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		, dlg.m_happyEv.fEXPRate2, dlg.m_happyEv.fSPIRate2, dlg.m_happyEv.fEXPRepairRate2
// 		, dlg.m_happyEv.fDropItemRate2, dlg.m_happyEv.fDropRareItemRate2, dlg.m_happyEv.fWarPointRate2, dlg.m_happyEv.InfluenceType3
// 		, dlg.m_happyEv.MinLevel, dlg.m_happyEv.MaxLevel, dlg.m_happyEv.EventUniqueNumber);	
// 
// 	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
	char tmStartTime[SIZE_MAX_SQL_DATETIME_STRING];		dlg.m_happyEv.atimeStartTime2.GetSQLDateTimeString(tmStartTime, SIZE_MAX_SQL_DATETIME_STRING);
	char tmEndTime[SIZE_MAX_SQL_DATETIME_STRING];		dlg.m_happyEv.atimeEndTime2.GetSQLDateTimeString(tmEndTime, SIZE_MAX_SQL_DATETIME_STRING);
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();
	SQLINTEGER arrCB2[23] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
							SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
							SQL_NTS,SQL_NTS,SQL_NTS};	// 2013-08-12 by bckim, �ű����Ǿƿ�

	SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.ServerGroupID), 0,			&arrCB2[1]);
	SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.DayOfWeek), 0,				&arrCB2[2]);
	SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmStartTime, 0,	&arrCB2[3]);
	SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmEndTime, 0,		&arrCB2[4]);
	SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fEXPRate2), 0,				&arrCB2[5]);
	SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPIRate2), 0,				&arrCB2[6]);
	SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fEXPRepairRate2), 0,			&arrCB2[7]);
	SQLBindParameter(hstmt, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fDropItemRate2), 0,			&arrCB2[8]);
	SQLBindParameter(hstmt, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fDropRareItemRate2), 0,		&arrCB2[9]);
	SQLBindParameter(hstmt, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWarPointRate2), 0,			&arrCB2[10]);
	SQLBindParameter(hstmt, 11, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &(dlg.m_happyEv.InfluenceType3), 0,		&arrCB2[11]);
	SQLBindParameter(hstmt, 12, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.MinLevel), 0,				&arrCB2[12]);
	SQLBindParameter(hstmt, 13, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.MaxLevel), 0,				&arrCB2[13]);	
	SQLBindParameter(hstmt, 14, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &(dlg.m_happyEv.EventUniqueNumber), 0,		&arrCB2[14]);	
	// 2013-08-12 by bckim, �ű����Ǿƿ�		//	UPDATE QUERY 
	SQLBindParameter(hstmt, 15, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fHPRecoveryRate), 0,			&arrCB2[15]);
	SQLBindParameter(hstmt, 16, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSHDRecoveryRate), 0,		&arrCB2[16]);
	SQLBindParameter(hstmt, 17, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPRecoveryRate), 0,			&arrCB2[17]);
	SQLBindParameter(hstmt, 18, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWeaponEnchantRate), 0,		&arrCB2[18]);
	SQLBindParameter(hstmt, 19, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fArmorEnchantRate), 0,		&arrCB2[19]);
	SQLBindParameter(hstmt, 20, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fETCItemEnchantRate), 0,		&arrCB2[20]);
	SQLBindParameter(hstmt, 21, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fSPIDiscountRate), 0,		&arrCB2[21]);
	SQLBindParameter(hstmt, 22, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &(dlg.m_happyEv.fWPDiscountRate), 0,			&arrCB2[22]);
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�	

	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0027));

	if (!bRet)
	{
		m_pODBCStmt->FreeStatement();		// cleanup

		AfxMessageBox("HappyHourEvent update error !!");
		return;
	}
	m_pODBCStmt->FreeStatement();	// cleanup

	this->GetHappyHourEventDetailInfo();
}

void CSCHappyHourEventAdminDlg::OnConmenuSelectedDelete() 
{
	// TODO: Add your command handler code here
	
	CCellID cellID = m_GridDetail.GetFocusCell();
	if(0 >= cellID.row)
	{// 2006-08-25 by cmkwon, ���� ����
		return;
	}

	int nHappyEvUID				= atoi(m_GridDetail.GetItemText(cellID.row, 0));
	SHAPPY_HOUR_EVENT	*pHappyEv = this->FindHappyHourEvent(nHappyEvUID);
	if(NULL == pHappyEv)
	{
		return;
	}

//	CString szQuery;
	// 2008-07-02 by cmkwon, MySQL ���� ���� - 
	//szQuery.Format("DELETE ti_happyhourevent WHERE uniquenumber = %d", pHappyEv->EventUniqueNumber);
// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
//	szQuery.Format(QUERY_080702_0261, pHappyEv->EventUniqueNumber);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &pHappyEv->EventUniqueNumber, 0, NULL);	
	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)PROCEDURE_080827_0261);
	if (!bRet)
	{
		m_pODBCStmt->FreeStatement();		// cleanup

		MessageBox("HappyHourEvent delete error !!");
		return;
	}
	m_pODBCStmt->FreeStatement();		// cleanup

	this->GetHappyHourEventDetailInfo();
}

void CSCHappyHourEventAdminDlg::OnConmenuNotselectedInsert() 
{
	// TODO: Add your command handler code here
	OnConmenuSelectedInsert();
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSCHappyHourEventAdminDlg::OnGridRClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
/// \brief		
/// \author		cmkwon
/// \date		2006-08-25 ~ 2006-08-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSCHappyHourEventAdminDlg::OnGridRClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
	UpdateData();

    NM_GRIDVIEW* pGridView = (NM_GRIDVIEW*)pNotifyStruct;
	if (pGridView->iRow == 0)
	{// 2006-08-25 by cmkwon, ������ ����
		return;
	}

	// 2009-02-04 by cmkwon, AdminTool�� GM ���� ���� - �̺�Ʈ ���� �˻��� ����, ���� �Ұ�
	// 2012-02-01 by jhseol, ��Ʈ�� GM ���� ����
#ifdef S_MANAGER_ADMIN_HSSON
	if(FALSE == COMPARE_RACE(m_pMainDlg->m_usManagerAccountType, RACE_OPERATION))
#else
	if(FALSE == m_pMainDlg->IsManagerAdministrator())
#endif
		// 2012-02-01 by jhseol, ��Ʈ�� GM ���� ����
	{
		AfxMessageBox(ADSTRMSG_090204_0001);
		return;
	}

	m_GridDetail.SetFocusCell(-1,-1);
	m_GridDetail.SetSelectedRange(pGridView->iRow, 0, pGridView->iRow, m_GridDetail.GetColumnCount()-1, TRUE, TRUE);
	m_GridDetail.SetFocusCell(pGridView->iRow, pGridView->iColumn);

	// show context menu
	CMenu muTemp, *pContextMenu;
	muTemp.LoadMenu(IDR_CONTEXT_MENU_HAPPYEV);
	CPoint point;
	GetCursorPos(&point);

	if(pGridView->iRow > 0)
	{// 2006-08-25 by cmkwon, ��ȿ�� ���� ����
		pContextMenu = muTemp.GetSubMenu(0);
	}
	else
	{// 2006-08-25 by cmkwon, ��ȿ���� ���� ���� ����
		pContextMenu = muTemp.GetSubMenu(1);
	}
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			SHAPPY_HOUR_EVENT * CSCHappyHourEventAdminDlg::FindHappyHourEvent(int i_nHappyEvUID)
/// \brief		
/// \author		cmkwon
/// \date		2006-08-25 ~ 2006-08-25
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
SHAPPY_HOUR_EVENT * CSCHappyHourEventAdminDlg::FindHappyHourEvent(int i_nHappyEvUID)
{
	for(int i=0; i < m_mtvectHappyEventList.size(); i++)
	{
		if(i_nHappyEvUID == m_mtvectHappyEventList[i].EventUniqueNumber)
		{
			return &m_mtvectHappyEventList[i];
		}
	}

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSCHappyHourEventAdminDlg::CheckHappyHourEvent(SHAPPY_HOUR_EVENT *i_pHappyEv)
/// \brief		
/// \author		cmkwon
/// \date		2006-08-30 ~ 2006-08-30
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSCHappyHourEventAdminDlg::CheckHappyHourEvent(SHAPPY_HOUR_EVENT *i_pHappyEv)
{

	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��
	if(0.0f >= i_pHappyEv->fEXPRate2
		&& 0.0f >= i_pHappyEv->fSPIRate2
		&& 0.0f >= i_pHappyEv->fEXPRepairRate2
		&& 0.0f >= i_pHappyEv->fDropItemRate2
		&& 0.0f >= i_pHappyEv->fDropRareItemRate2
 		&& 0.0f >= i_pHappyEv->fWarPointRate2	// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�

		&& 0.0f >= i_pHappyEv->fHPRecoveryRate		// 2013-08-12 by bckim, �ű����Ǿƿ�
		&& 0.0f >= i_pHappyEv->fSHDRecoveryRate
		&& 0.0f >= i_pHappyEv->fSPRecoveryRate
		&& 0.0f >= i_pHappyEv->fWeaponEnchantRate
		&& 0.0f >= i_pHappyEv->fArmorEnchantRate
		&& 0.0f >= i_pHappyEv->fETCItemEnchantRate 
		&& 0.0f >= i_pHappyEv->fSPIDiscountRate
		&& 0.0f >= i_pHappyEv->fWPDiscountRate )	// End. 2013-08-12 by bckim, �ű����Ǿƿ�		
	{
		AfxMessageBox("All HappyHourEvent Rate is default values !!");
		return FALSE;
	}

	// 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - 
	if(i_pHappyEv->MaxLevel < i_pHappyEv->MinLevel)
	{
		AfxMessageBox("Please Check Minlevel");
		return FALSE;
	}
	else if(i_pHappyEv->MinLevel < 1
			|| i_pHappyEv->MinLevel > CHARACTER_LEVEL_110)	// 2010-03-11 by cmkwon, �������� 110 ���� ó�� ������ ���� - 
	{
		AfxMessageBox("Please Check Minlevel");
		return FALSE;
	}
	else if(i_pHappyEv->MaxLevel < 1
			|| i_pHappyEv->MaxLevel > CHARACTER_LEVEL_110)		// 2010-03-11 by cmkwon, �������� 110 ���� ó�� ������ ���� - 
	{
		AfxMessageBox("Please Check Maxlevel");
		return FALSE;
	}

	// �� Rate�� ������ üũ�Ѵ�.
	if (FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fEXPRate2, 10.0f))	// 2013-08-12 by bckim, �ű����Ǿƿ� // �������� ���� 100.0f >> 10.0f 
	{// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��
		AfxMessageBox("Please Check EXP Rate value.(0.0f ~ 10.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fSPIRate2, 10.0f))	// 2013-08-12 by bckim, �ű����Ǿƿ� // �������� ���� 100.0f >> 10.0f 
	{// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��
		AfxMessageBox("Please Check SPI Rate value(0.0f ~ 10.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fEXPRepairRate2, 1.0f))
	{
		AfxMessageBox("Please Check EXP Repair Rate value(0.0f ~ 1.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fDropItemRate2, 5.0f))	// 2013-08-12 by bckim, �ű����Ǿƿ� // �������� ���� 100.0f >> 10.0f 
	{// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��
		AfxMessageBox("Please Check Drop Item Rate value(0.0f ~ 5.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fDropRareItemRate2, 5.0f))	// 2013-08-12 by bckim, �ű����Ǿƿ� // �������� ���� 100.0f >> 10.0f 
	{// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��
		AfxMessageBox("Please Check Drop Rare Item Rate value(0.0f ~ 5.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fWarPointRate2, 3.0f))	// 2013-08-12 by bckim, �ű����Ǿƿ� // �������� ���� 100.0f >> 10.0f 
	{// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �⺻���� ��� 0.0f �� ���� ��// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
		AfxMessageBox("Please Check WarPoint Rate value(1.0f ~ 3.0f)");
		return FALSE;
	}
	
	// 2013-08-12 by bckim, �ű����Ǿƿ�	//	CheckHappyHourEvent
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fHPRecoveryRate, 10.0f))
	{
		AfxMessageBox("Please Check HP recovery Plus Rate value(0.0f ~ 10.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fSHDRecoveryRate, 10.0f))
	{
		AfxMessageBox("Please Check DP recovery Plus Rate value(0.0f ~ 10.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fSPRecoveryRate, 10.0f))
	{
		AfxMessageBox("Please Check SP recovery Plus Rate value(0.0f ~ 10.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fWeaponEnchantRate, 1.0f))
	{
		AfxMessageBox("Please Check Weapon Enchant Plus Rate value(0.0f ~ 1.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fArmorEnchantRate, 1.0f))
	{
		AfxMessageBox("Please Check Armor Enchant Plus Rate value(0.0f ~ 1.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fETCItemEnchantRate, 1.0f))
	{
		AfxMessageBox("Please Check Etc Item Enchant Plus Rate value(0.0f ~ 1.0f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fSPIDiscountRate, 0.5f))
	{
		AfxMessageBox("Please Check SPI Item Discount Rate value(0.0f ~ 0.5f)");
		return FALSE;
	}
	if(FALSE == IS_IN_RANGE(0.0f, i_pHappyEv->fWPDiscountRate, 0.5f))
	{
		AfxMessageBox("Please Check WP Item Discount Rate value(0.0f ~ 0.5f)");
		return FALSE;
	}
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�
	
	// 2006-08-30 by cmkwon, �ð� ���� üũ
	if(i_pHappyEv->atimeStartTime2 >= i_pHappyEv->atimeEndTime2)
	{
		AfxMessageBox("End Time must more then Start Time !!");
		return FALSE;
	}

	for(int i = 0; i < m_mtvectHappyEventList.size(); i++)
	{
		SHAPPY_HOUR_EVENT *pHappyEv = &m_mtvectHappyEventList[i];
		if(pHappyEv->EventUniqueNumber == i_pHappyEv->EventUniqueNumber
			|| pHappyEv->DayOfWeek != i_pHappyEv->DayOfWeek)
		{// 2006-08-30 by cmkwon, ������ �׸��̰ų� ������ ���� ������ üũ�� �ʿ� ����
			continue;
		}

		if(0 != i_pHappyEv->ServerGroupID
			&& 0 != pHappyEv->ServerGroupID 
			&& pHappyEv->ServerGroupID != i_pHappyEv->ServerGroupID)
		{// 2006-08-30 by cmkwon, ��� ���� �׸��� �ƴϸ鼭 üũ�� ���� �������� ���� ������ üũ �ʿ� ����
			continue;
		}

		if(pHappyEv->InfluenceType3 != i_pHappyEv->InfluenceType3)
		{	// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ������ �ٸ��� üũ �ʿ� ����
			continue;
		}

		pHappyEv->atimeStartTime2.Year	= i_pHappyEv->atimeStartTime2.Year;
		pHappyEv->atimeStartTime2.Month	= i_pHappyEv->atimeStartTime2.Month;
		pHappyEv->atimeStartTime2.Day	= i_pHappyEv->atimeStartTime2.Day;
		pHappyEv->atimeEndTime2.Year	= i_pHappyEv->atimeStartTime2.Year;
		pHappyEv->atimeEndTime2.Month	= i_pHappyEv->atimeStartTime2.Month;
		pHappyEv->atimeEndTime2.Day		= i_pHappyEv->atimeStartTime2.Day;

		if(pHappyEv->atimeStartTime2 == i_pHappyEv->atimeStartTime2)
		{
			AfxMessageBox("Start Time or End Time error !!");
			return FALSE;
		}

		if(pHappyEv->atimeStartTime2 < i_pHappyEv->atimeStartTime2)
		{
			if(pHappyEv->atimeEndTime2 >= i_pHappyEv->atimeStartTime2)
			{
				AfxMessageBox("Start Time or End Time error !!");
				return FALSE;
			}
		}
		else
		{
			if(pHappyEv->atimeStartTime2 <= i_pHappyEv->atimeEndTime2)
			{
				AfxMessageBox("Start Time or End Time error !!");
				return FALSE;
			}
		}
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ATUM_DATE_TIME *CSCHappyHourEventAdminDlg::GetHappyEvPeriodStartDateTime(BYTE i_byInflTy)
/// \brief		// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - CSCHappyHourEventAdminDlg::GetHappyEvPeriodStartDateTime() �Լ� �߰�
/// \author		cmkwon
/// \date		2007-11-01 ~ 2007-11-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ATUM_DATE_TIME *CSCHappyHourEventAdminDlg::GetHappyEvPeriodStartDateTime(BYTE i_byInflTy)
{
	int nArrIdx = GetArrayIndexByInfluenceType(i_byInflTy);
	if(0 > nArrIdx)
	{
		return NULL;
	}
	return &m_arrHappyEvPeriodStart[nArrIdx];
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			ATUM_DATE_TIME *CSCHappyHourEventAdminDlg::GetHappyEvPeriodEndDateTime(BYTE i_byInflTy)
/// \brief		// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - CSCHappyHourEventAdminDlg::GetHappyEvPeriodEndDateTime() �Լ� �߰�
/// \author		cmkwon
/// \date		2007-11-01 ~ 2007-11-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
ATUM_DATE_TIME *CSCHappyHourEventAdminDlg::GetHappyEvPeriodEndDateTime(BYTE i_byInflTy)
{
	int nArrIdx = GetArrayIndexByInfluenceType(i_byInflTy);
	if(0 > nArrIdx)
	{
		return NULL;
	}

	return &m_arrHappyEvPeriodEND[nArrIdx];
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CSCHappyHourEventAdminDlg::UpdateHappyHourEventPeriod(BYTE i_byInflTy, ATUM_DATE_TIME *i_pATStart, ATUM_DATE_TIME *i_pATEnd)
/// \brief		// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - CSCHappyHourEventAdminDlg::UpdateHappyHourEventPeriod() �Լ� �߰�
/// \author		cmkwon
/// \date		2007-11-01 ~ 2007-11-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CSCHappyHourEventAdminDlg::UpdateHappyHourEventPeriod(BYTE i_byInflTy, ATUM_DATE_TIME *i_pATStart, ATUM_DATE_TIME *i_pATEnd)
{
// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
//	CString szQuery;
//	UID32_t EvendUID = 0;
//
// 	///////////////////////////////////////////////////////////////////////////////
// 	// 2007-11-01 by cmkwon, �ش� ������ HappyHourEvnet �Ⱓ �����Ͱ� DB�� ���� �ϴ��� üũ
// // 2008-07-02 by cmkwon, MySQL ���� ���� - 
// // 	szQuery.Format("SELECT UniqueNumber FROM ti_happyHourEvent WITH(NOLOCK) WHERE InfluenceType = %d AND DayOfWeek = %d"
// // 		, i_byInflTy, DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD);
// 	szQuery.Format(QUERY_080702_0028, i_byInflTy, DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD);	// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 	SQLBindCol(m_pODBCStmt->m_hstmt, 1, SQL_C_ULONG, &EvendUID, 0, NULL);
// 
// 	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
// 	if (!bRet)
// 	{
// 		m_pODBCStmt->FreeStatement();		// clean up
// 		MessageBox("HappyHourEvent period update error !!, 1");
// 		return FALSE;
// 	}
// 	SQLFetch(m_pODBCStmt->m_hstmt);
// 	m_pODBCStmt->FreeStatement();		// cleanup
// 
// 
// 	///////////////////////////////////////////////////////////////////////////////
// 	// 2007-11-01 by cmkwon, 
// 	if(FALSE == IS_VALID_UNIQUE_NUMBER(EvendUID))
// 	{// 2006-08-25 by cmkwon, �߰��ؾ���
// 
// 		// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
// 		// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - InfluenceType �ʵ� �߰�
// 		// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
// 		// 2008-03-14 by dhjin,  Level�� ���Ǿƿ� �̺�Ʈ ���� - ���°��� �ֱ� ������ �⺻���� 1~CHARACTER_MAX_LEVEL�� �����Ѵ�.
// 		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 		//szQuery.Format("INSERT ti_happyhourevent(ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate, InfluenceType, MinLevel, MaxLevel) values( 0, %d, '%s', '%s', 0, 0, 0, 0, 0, 0, %d, 1, 100)"
// 		//	, DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD, i_pATStart->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		//	, i_pATEnd->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), i_byInflTy);
// 		szQuery.Format(QUERY_080702_0262
// 			, DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD, i_pATStart->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 			, i_pATEnd->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING)), i_byInflTy);
// 	}
// 	else
// 	{// 2006-08-25 by cmkwon, Update
// 		// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
// 		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
// 		//szQuery.Format("UPDATE ti_happyhourevent SET starttime = '%s', endtime = '%s' where UniqueNumber= %d"
// 		//	, i_pATStart->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		//	, i_pATEnd->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 		//	, EvendUID);
// 		szQuery.Format(QUERY_080702_0263
// 			, i_pATStart->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 			, i_pATEnd->GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
// 			, EvendUID);
// 	}
// 
// 	bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
// 	if (!bRet)
// 	{
// 		m_pODBCStmt->FreeStatement();		// cleanup
// 
// 		MessageBox("HappyHourEvent period error !!, 2");
// 		return FALSE;
// 	}
// 	m_pODBCStmt->FreeStatement();	// cleanup

	///////////////////////////////////////////////////////////////////////////////
	// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
	int nDayOfWeek = DAY_OF_WEEK_HAPPYHOUREVENT_PERIOD;
	char tmStartTime[SIZE_MAX_SQL_DATETIME_STRING];		i_pATStart->GetSQLDateTimeString(tmStartTime, SIZE_MAX_SQL_DATETIME_STRING);
	char tmEndTime[SIZE_MAX_SQL_DATETIME_STRING];		i_pATEnd->GetSQLDateTimeString(tmEndTime, SIZE_MAX_SQL_DATETIME_STRING);
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();
	SQLINTEGER arrCB2[5] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS};
	SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &(nDayOfWeek), 0,							&arrCB2[1]);
	SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &(i_byInflTy), 0,						&arrCB2[2]);
	SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmStartTime, 0,	&arrCB2[3]);
	SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmEndTime, 0,		&arrCB2[4]);
	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0028));
	if(FALSE == bRet)
	{
 		MessageBox("HappyHourEvent period error !!, 2");
	}
 	m_pODBCStmt->FreeStatement();	// cleanup

	return TRUE;
}



void CSCHappyHourEventAdminDlg::OnBtnUpdatePcbangHappyev() 
{
	// TODO: Add your control notification handler code here

	CSetPCBangHappyEv dlg(&m_PCBangHappyEv, this);
	if(IDOK != dlg.DoModal())
	{
		return;
	}
	m_PCBangHappyEv				= dlg.m_pcBangEv;

	// 2013-08-12 by bckim, �ű����Ǿƿ�
#ifdef SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM		//	CheckHappyHourEvent ���� �Ǿ��� ���� ����üũ �߰�
	if( FALSE == CheckHappyHourEvent( &m_PCBangHappyEv))
	{
		MessageBox("PCBang HappyHourEvent update error !!");
		return;
	}
#endif
	// End. 2013-08-12 by bckim, �ű����Ǿƿ�	
	
//	CString szQuery;
	BOOL bRet;
	if(0 == m_PCBangHappyEv.EventUniqueNumber)
	{// 2006-08-28 by cmkwon, Insert

		// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
		//szQuery.Format("INSERT ti_happyhourevent(ServerGroupID, dayofweek, starttime, endtime, exprate, spirate, exprepairrate, dropitemrate, droprareitemrate, WarPointRate, MinLevel, MaxLevel) VALUES( 0, %d, '%s', '%s', %6.4f, %6.4f, %6.4f, %6.4f, %6.4f, %6.4f, 1, 100)"
// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
//		szQuery.Format(QUERY_080702_0264
//			, DAY_OF_WEEK_PCBANG_HAPPYHOUREVENT 
//			, m_PCBangHappyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
//			, m_PCBangHappyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
//			, m_PCBangHappyEv.fEXPRate2, m_PCBangHappyEv.fSPIRate2, m_PCBangHappyEv.fEXPRepairRate2
//			, m_PCBangHappyEv.fDropItemRate2, m_PCBangHappyEv.fDropRareItemRate2, m_PCBangHappyEv.fWarPointRate2);		// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
		int tmWeek = DAY_OF_WEEK_PCBANG_HAPPYHOUREVENT;
		SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &tmWeek, 0, NULL);
		char szATStart[SIZE_MAX_SQL_DATETIME_STRING];
		m_PCBangHappyEv.atimeStartTime2.GetSQLDateTimeString(szATStart, SIZE_MAX_SQL_DATETIME_STRING);	
		SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, szATStart, 0, NULL);
		char szATEnd[SIZE_MAX_SQL_DATETIME_STRING];
		m_PCBangHappyEv.atimeEndTime2.GetSQLDateTimeString(szATEnd, SIZE_MAX_SQL_DATETIME_STRING);	
		SQLBindParameter(m_pODBCStmt->m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, szATEnd, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fEXPRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPIRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fEXPRepairRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fDropItemRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fDropRareItemRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWarPointRate2, 0, NULL);
		// 2013-08-12 by bckim, �ű����Ǿƿ�		//	PC insert query
		SQLBindParameter(m_pODBCStmt->m_hstmt, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fHPRecoveryRate,		0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSHDRecoveryRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPRecoveryRate,		0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 13, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWeaponEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 14, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fArmorEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 15, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fETCItemEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 16, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPIDiscountRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 17, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWPDiscountRate,		0, NULL);
		// End. 2013-08-12 by bckim, �ű����Ǿƿ�

		bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0264));
	}
	else
	{// 2006-08-28 by cmkwon, Update
		// 2008-01-24 by cmkwon, S_A: ��¥ ���� ���ø� ���̼� ó�� ���� ���� - GetDateTimeString() �� GetSQLDateTimeString() �� ���� ��
		// 2008-07-02 by cmkwon, MySQL ���� ���� - 
		//szQuery.Format("UPDATE ti_happyhourevent SET starttime= '%s', endtime= '%s', exprate= %6.4f, spirate= %6.4f, exprepairrate= %6.4f, dropitemrate= %6.4f, droprareitemrate= %6.4f, WarPointRate= %6.4f WHERE UniqueNumber= %d"
// 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
//		szQuery.Format(QUERY_080702_0265
//			, m_PCBangHappyEv.atimeStartTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
//			, m_PCBangHappyEv.atimeEndTime2.GetSQLDateTimeString(STRNBUF(SIZE_MAX_SQL_DATETIME_STRING))
//			, m_PCBangHappyEv.fEXPRate2, m_PCBangHappyEv.fSPIRate2, m_PCBangHappyEv.fEXPRepairRate2
//			, m_PCBangHappyEv.fDropItemRate2, m_PCBangHappyEv.fDropRareItemRate2, m_PCBangHappyEv.fWarPointRate2
//			, m_PCBangHappyEv.EventUniqueNumber);			// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
		char szATStart[SIZE_MAX_SQL_DATETIME_STRING];
		m_PCBangHappyEv.atimeStartTime2.GetSQLDateTimeString(szATStart, SIZE_MAX_SQL_DATETIME_STRING);	
		SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, szATStart, 0, NULL);
		char szATEnd[SIZE_MAX_SQL_DATETIME_STRING];
		m_PCBangHappyEv.atimeEndTime2.GetSQLDateTimeString(szATEnd, SIZE_MAX_SQL_DATETIME_STRING);	
		SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, szATEnd, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fEXPRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPIRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fEXPRepairRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fDropItemRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fDropRareItemRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWarPointRate2, 0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 9, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &m_PCBangHappyEv.EventUniqueNumber, 0, NULL);
		// 2013-08-12 by bckim, �ű����Ǿƿ�	//	PC update query
		SQLBindParameter(m_pODBCStmt->m_hstmt, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fHPRecoveryRate,		0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSHDRecoveryRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPRecoveryRate,		0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 13, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWeaponEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 14, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fArmorEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 15, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fETCItemEnchantRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 16, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fSPIDiscountRate,	0, NULL);
		SQLBindParameter(m_pODBCStmt->m_hstmt, 17, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &m_PCBangHappyEv.fWPDiscountRate,		0, NULL);
		// End. 2013-08-12 by bckim, �ű����Ǿƿ�

		bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_080827_0265));
	}

//	BOOL bRet = m_pODBCStmt->ExecuteQuery((LPCSTR)szQuery);
	if (!bRet)
	{
		m_pODBCStmt->FreeStatement();		// cleanup

		MessageBox("PCBang HappyHourEvent update error !!");
		return;
	}
	m_pODBCStmt->FreeStatement();	// cleanup

	GetHappyHourEventDetailInfo();
}

void CSCHappyHourEventAdminDlg::OnBtnReloadHappyEv() 
{
	// TODO: Add your control notification handler code here

	// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - �Ʒ��� ���� �Լ��� ó����
	//m_pMainDlg->m_pAdminPreSocket->WriteMessageType(T_PA_ADMIN_RELOAD_HAPPYEV);
	if(FALSE == m_pMainDlg->SendMsgTypeToPreServer(T_PA_ADMIN_RELOAD_HAPPYEV))
	{
		MessageBox("diconnected from preserver !!");
		return;
	}

	// 2007-11-01 by cmkwon, ���� �޽��� �ڽ� �߰�
	Sleep(1000);
	MessageBox("All ServerGroup reload HappyHourEvent !!");
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CSCHappyHourEventAdminDlg::OnBtnReloadPCbangList()
/// \brief		
/// \author		dhjin
/// \date		2007-01-22 ~ 2007-01-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CSCHappyHourEventAdminDlg::OnBtnReloadPCbangList()
{
// 2007-01-25 by dhjin, ���縸 PC�� �ǽð� ����
// 2008-08-14 by cmkwon, �±� WinnerOnline_Tha PCBang �ý��� ���� - 
#if !defined(SERVICE_TYPE_KOREAN_SERVER_2) && !(defined(SERVICE_TYPE_THAI_SERVER_1) || defined(SERVICE_TYPE_SINGAPORE_1) || defined(SERVICE_TYPE_INDONESIA_SERVER_1))
	MessageBox("Not Update Button");
	return;
#endif

// 2008-08-14 by cmkwon, �±� WinnerOnline_Tha PCBang �ý��� ���� - �±��� PreServer �� ���ε� �޽����� �����Ѵ�.
#if defined(SERVICE_TYPE_KOREAN_SERVER_2)
	CODBCStatement odbc;
	// Connect WebDB
	// 2008-11-26 by cmkwon, �ѱ� Yedang_Kor PCBang �ҽ� DB IDC �������� IP���� - 2008-11-27(��) ������ �۾�
	//if ( FALSE == odbc.Init("192.168.2.86", 1456, "ref_ace", "alpha", "dnpqthffntus13579!", GetSafeHwnd()) )
	if ( FALSE == odbc.Init("192.168.21.11", 1456, "ref_ace", "alpha", "dnpqthffntus13579!", GetSafeHwnd()) )
	{
		MessageBox("Can't connect to WebDBServer !!");
		return;
	}
	
	vectorPCBANG_INFO		vectPCbangInfo;
	char 					ErrorString[1024];

	int Result = CAtumDBHelper::LoadPCBangInfo(&odbc, &vectPCbangInfo, ErrorString);
	if (Result == -1)
	{

		MessageBox(ErrorString);
		return;
	}

	Result = CAtumDBHelper::InsertPCBangInfo(m_pODBCStmt, &vectPCbangInfo);
	if (0 >= Result)
	{
		// 2007-09-27 by cmkwon, ���� �ڵ� ������ ���� ����
		char szLog[1024];
		sprintf(szLog, "PCBangIP Insert Error !!, result(%d), size(%d)", Result, vectPCbangInfo.size());
		MessageBox(szLog);
		return;
	}
#endif

	// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - �Ʒ��� ���� �Լ��� ó����
	//m_pMainDlg->m_pAdminPreSocket->WriteMessageType(T_PA_ADMIN_UPDATE_PCBANGLIST);	
	if(FALSE == m_pMainDlg->SendMsgTypeToPreServer(T_PA_ADMIN_UPDATE_PCBANGLIST))
	{
		MessageBox("disconnected from PreServer !!");
		return;
	}
	MessageBox("PCBang Reload Success !!");
}


void CSCHappyHourEventAdminDlg::OnBtnUpdatePeriodNormal() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	ATUM_DATE_TIME *pATStart	= GetHappyEvPeriodStartDateTime(INFLUENCE_TYPE_NORMAL);
	ATUM_DATE_TIME *pATEnd		= GetHappyEvPeriodEndDateTime(INFLUENCE_TYPE_NORMAL);

	pATStart->SetDateTime(m_ctlOleDateNormalStart.GetYear(), m_ctlOleDateNormalStart.GetMonth(), m_ctlOleDateNormalStart.GetDay()
		, m_ctlOleTimeNormalStart.GetHour(), m_ctlOleTimeNormalStart.GetMinute(), 0);
	pATEnd->SetDateTime(m_ctlOleDateNormalEnd.GetYear(), m_ctlOleDateNormalEnd.GetMonth(), m_ctlOleDateNormalEnd.GetDay()
		, m_ctlOleTimeNormalEnd.GetHour(), m_ctlOleTimeNormalEnd.GetMinute(), 0);

	// 2007-11-01 by cmkwon, DB �� ������Ʈ �Ѵ�.
	this->UpdateHappyHourEventPeriod(INFLUENCE_TYPE_NORMAL, pATStart, pATEnd);

	// 2007-11-01 by cmkwon, ��� �̺�Ʈ ������ �ٽ� �ε��Ѵ�.
	GetHappyHourEventDetailInfo();	
}

void CSCHappyHourEventAdminDlg::OnBtnUpdatePeriodVcn() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();

	ATUM_DATE_TIME *pATStart	= GetHappyEvPeriodStartDateTime(INFLUENCE_TYPE_VCN);
	ATUM_DATE_TIME *pATEnd		= GetHappyEvPeriodEndDateTime(INFLUENCE_TYPE_VCN);

	pATStart->SetDateTime(m_ctlOleDateVCNStart.GetYear(), m_ctlOleDateVCNStart.GetMonth(), m_ctlOleDateVCNStart.GetDay()
		, m_ctlOleTimeVCNStart.GetHour(), m_ctlOleTimeVCNStart.GetMinute(), 0);
	pATEnd->SetDateTime(m_ctlOleDateVCNEnd.GetYear(), m_ctlOleDateVCNEnd.GetMonth(), m_ctlOleDateVCNEnd.GetDay()
		, m_ctlOleTimeVCNEnd.GetHour(), m_ctlOleTimeVCNEnd.GetMinute(), 0);

	// 2007-11-01 by cmkwon, DB �� ������Ʈ �Ѵ�.
	this->UpdateHappyHourEventPeriod(INFLUENCE_TYPE_VCN, pATStart, pATEnd);

	// 2007-11-01 by cmkwon, ��� �̺�Ʈ ������ �ٽ� �ε��Ѵ�.
	GetHappyHourEventDetailInfo();	
}

void CSCHappyHourEventAdminDlg::OnBtnUpdatePeriodAni() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();

	ATUM_DATE_TIME *pATStart	= GetHappyEvPeriodStartDateTime(INFLUENCE_TYPE_ANI);
	ATUM_DATE_TIME *pATEnd		= GetHappyEvPeriodEndDateTime(INFLUENCE_TYPE_ANI);

	pATStart->SetDateTime(m_ctlOleDateANIStart.GetYear(), m_ctlOleDateANIStart.GetMonth(), m_ctlOleDateANIStart.GetDay()
		, m_ctlOleTimeANIStart.GetHour(), m_ctlOleTimeANIStart.GetMinute(), 0);
	pATEnd->SetDateTime(m_ctlOleDateANIEnd.GetYear(), m_ctlOleDateANIEnd.GetMonth(), m_ctlOleDateANIEnd.GetDay()
		, m_ctlOleTimeANIEnd.GetHour(), m_ctlOleTimeANIEnd.GetMinute(), 0);

	// 2007-11-01 by cmkwon, DB �� ������Ʈ �Ѵ�.
	this->UpdateHappyHourEventPeriod(INFLUENCE_TYPE_ANI, pATStart, pATEnd);

	// 2007-11-01 by cmkwon, ��� �̺�Ʈ ������ �ٽ� �ε��Ѵ�.
	GetHappyHourEventDetailInfo();	
}
