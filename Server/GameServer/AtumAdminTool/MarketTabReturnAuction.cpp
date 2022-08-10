// LogTabItem.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "MarketTabReturnAuction.h"

#include "ODBCStatement.h"
#include "AtumProtocol.h"
#include "SelectItemDlg.h"
#include "AtumAdminToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////////
// 거래소 그리드 컬럼 리스트 
///////////////////////////////////////////////////////////////////////////////
const char *g_arrReturnAuctionColumnNames[] = {
		"IDX",
		"Auction Status",
		"Character Name(UID)",
		"Auction Date",
		"Influence",
		"Price",
		"Count",
		"ItemUID(ItemNum)",
		"ItemName",
		"PrefixNum",
		"SuffixNum",
		"Enchant",
		"Color Code",
		NULL
};


CMarketTabReturnAuction::CMarketTabReturnAuction(CDialog *i_pMainDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CMarketTabReturnAuction::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogTabItem)
	//}}AFX_DATA_INIT
	//m_pMainDlg = (CSCMarketLogDlg*)i_pMainDlg;

	m_bCheckSearchAuctionItem = FALSE;	

	m_pMainDlg = (CSCLogAdminDlg*)i_pMainDlg;	
	m_pODBCStmt = &(m_pMainDlg->m_ODBCStmt);
}

void CMarketTabReturnAuction::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogTabItem)

	// search condition			// 파괴 졍매장 
	DDX_Check(pDX, IDC_CHECK_AUCTION_DATE, m_bCheckDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_DATE_AUCTION, m_dateStart);
	DDX_Control(pDX, IDC_COMBO_SELECTED_AUCTION_PERIOD, m_comboSearchCondition);
	DDX_Check(pDX, IDC_CHECK_AUCTION_INFLUENCE, m_bCheckInfluence);
	DDX_Control(pDX, IDC_COMBO_SELECTED_INFLUENCE_TYPE, m_comboInfluence);
	DDX_Check(pDX, IDC_CHECK_AUCTIONT_STATUS_1, m_bCheckStatus);
	DDX_Control(pDX, IDC_COMBO_SELECTED_AUCTION_STATUS_1, m_comboStatus);
	DDX_Check(pDX, IDC_CHECK_AUCTION_CHARACTER_NAME, m_bCheckCharacterName);
	DDX_Text(pDX, IDC_EDIT_AUCTION_CHARACTER_NAME, m_szCharacterName);
	DDX_Check(pDX, IDC_CHECK_AUCTION_CHARACTER_UID, m_bCheckCharacterUID);
	DDX_Text(pDX, IDC_EDIT_AUCTION_CHARACTER_UID, m_nCharacterUID);
	DDX_Check(pDX, IDC_CHECK_AUCTION_ITEM_UID, m_bCheckItemUID);
	DDX_Text(pDX, IDC_EDIT_AUCTION_ITEM_UID, m_ItemUID);
	DDX_Check(pDX, IDC_CHECK_AUCTION_ITEM_NUM, m_bCheckItemNum);
	DDX_Text(pDX, IDC_EDIT_AUCTION_ITEM_NUM, m_ItemNum);
	DDX_Check(pDX, IDC_CHECK_AUCTION_MAX_ROW_COUNT, m_bCheckMaxLogCount);
	DDX_Text(pDX, IDC_EDIT_AUCTION_ITEM_MAX_LOG_COUNT, m_MaxLogCount);

	// search auction item			// 파괴 졍매장 
	DDX_Check(pDX, IDC_CHECK_SEARCH_AUCTION_ITEM, m_bCheckSearchAuctionItem);
	DDX_Check(pDX, IDC_CHECK_SEARCH_AUCTION_ITEM_DATE, m_bCheckSearchAuctionItemDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_DATE_SEARCH_AUCTION_ITEM, m_dateSearchAUctionItemStart);
	DDX_Control(pDX, IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM, m_comboSearchAuctionItem);
	DDX_Check(pDX, IDC_CHECK_SEARCH_AUCTION_ITEM_STATUS, m_bCheckSearchAuctionItemStatus);
	DDX_Control(pDX, IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM_STATUS, m_comboSearchAuctionItemStatus);

	// 버튼 
	DDX_Control(pDX, IDC_EDIT_ITEM_TOTAL_LOG_COUNT, m_EditTotalLogRowCount);		// 파괴경매장 로그 카운트 

	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_RETURN_AUCTION, m_GridReturnAuction);
}


BEGIN_MESSAGE_MAP(CMarketTabReturnAuction, CDialog)
//{{AFX_MSG_MAP(CLogTabItem)
ON_BN_CLICKED(IDC_CHECK_AUCTION_DATE, OnCheckDate)
ON_BN_CLICKED(IDC_CHECK_AUCTION_INFLUENCE, OnCheckInflunence)
ON_BN_CLICKED(IDC_CHECK_AUCTIONT_STATUS_1, OnCheckStatus1)
ON_BN_CLICKED(IDC_CHECK_AUCTION_CHARACTER_NAME, OnCheckCharacterName)
ON_BN_CLICKED(IDC_CHECK_AUCTION_CHARACTER_UID, OnCheckCharacterUID)
ON_BN_CLICKED(IDC_CHECK_AUCTION_ITEM_UID, OnCheckItemUID)
ON_BN_CLICKED(IDC_CHECK_AUCTION_ITEM_NUM, OnCheckItemNum)
ON_BN_CLICKED(IDC_CHECK_AUCTION_MAX_ROW_COUNT, OnCheckMaxRowCount)

// search auction item			// 파괴 졍매장 
ON_BN_CLICKED(IDC_CHECK_SEARCH_AUCTION_ITEM, OnCheckSearchAuctionItem)
ON_BN_CLICKED(IDC_CHECK_SEARCH_AUCTION_ITEM_DATE, OnCheckDate2)
ON_BN_CLICKED(IDC_CHECK_SEARCH_AUCTION_ITEM_STATUS, OnCheckStatus2)

// button 
ON_BN_CLICKED(IDC_BUTTON_AUTCION_SEARCH, OnButtonAuctionSearchOk)
ON_BN_CLICKED(IDC_BUTTON_AUTCION_RESET, OnButtonAuctionReset)
ON_BN_CLICKED(IDC_BUTTON_AUTCION_SAVE_RESULT, OnButtonAuctionSaveResult)

//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogTabItem message handlers

BOOL CMarketTabReturnAuction::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		m_pMainDlg->EndDialog(-1);
		return TRUE;
	}
	
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{	
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CMarketTabReturnAuction::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here

	// 그리드 초기화 
	ResetVariables();
	InitGrid(&m_GridReturnAuction);

	// search condition
	m_dateStart = (CTime::GetCurrentTime() - CTimeSpan(1, 0 , 0, 0));
			
	m_comboSearchCondition.ResetContent();
	m_comboSearchCondition.AddString("AM 00:00 ~ AM 03:00");
	m_comboSearchCondition.AddString("AM 03:00 ~ AM 06:00");
	m_comboSearchCondition.AddString("AM 06:00 ~ AM 09:00");
	m_comboSearchCondition.AddString("AM 09:00 ~ AM 12:00");
	m_comboSearchCondition.AddString("PM 12:00 ~ PM 03:00");
	m_comboSearchCondition.AddString("PM 03:00 ~ PM 06:00");
	m_comboSearchCondition.AddString("PM 06:00 ~ PM 09:00");
	m_comboSearchCondition.AddString("PM 09:00 ~ AM 00:00");
	m_comboSearchCondition.SetCurSel(0);

	m_comboInfluence.ResetContent();
	m_comboInfluence.AddString("ALL");
	m_comboInfluence.AddString("NORMAL");
	m_comboInfluence.AddString("BCU");
	m_comboInfluence.AddString("ANI");
	m_comboInfluence.SetCurSel(0);

	m_comboStatus.ResetContent();
	m_comboStatus.AddString("Tender");
	m_comboStatus.AddString("Bidding");
	m_comboStatus.AddString("Not Tender");
	m_comboStatus.SetCurSel(0);

	// search auction item 
	m_comboSearchAuctionItem.ResetContent();
	m_comboSearchAuctionItem.AddString("AM 00:00 ~ AM 03:00");
	m_comboSearchAuctionItem.AddString("AM 03:00 ~ AM 06:00");
	m_comboSearchAuctionItem.AddString("AM 06:00 ~ AM 09:00");
	m_comboSearchAuctionItem.AddString("AM 09:00 ~ AM 12:00");
	m_comboSearchAuctionItem.AddString("PM 12:00 ~ PM 03:00");
	m_comboSearchAuctionItem.AddString("PM 03:00 ~ PM 06:00");
	m_comboSearchAuctionItem.AddString("PM 06:00 ~ PM 09:00");
	m_comboSearchAuctionItem.AddString("PM 09:00 ~ AM 00:00");
	m_comboSearchAuctionItem.SetCurSel(0);
	
	m_comboSearchAuctionItemStatus.ResetContent();
	m_comboSearchAuctionItemStatus.AddString("Destroyed Item");
	m_comboSearchAuctionItemStatus.AddString("Registered item");
	m_comboSearchAuctionItemStatus.AddString("Bidding");
	m_comboSearchAuctionItemStatus.AddString("Get Exchange");
	m_comboSearchAuctionItemStatus.AddString("Not Tender");
	m_comboSearchAuctionItemStatus.SetCurSel(0);
	
	m_dateSearchAUctionItemStart = (CTime::GetCurrentTime() - CTimeSpan(1, 0 , 0, 0));
	
	GetDlgItem(IDC_DATETIMEPICKER_START_DATE_AUCTION)->EnableWindow(m_bCheckSearchAuctionItemDate);
	OnCheckSearchAuctionItem();

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMarketTabReturnAuction::ResetVariables()
{
	// search condition
	m_bCheckDate	= TRUE;			//기간선택 
	m_dateStart = (CTime::GetCurrentTime() - CTimeSpan(1, 0 , 0, 0));
	m_bCheckInfluence	= FALSE;		// 세력 선택 
	m_bCheckStatus		= FALSE;
	m_bCheckCharacterName	= FALSE;	// 케릭터 이름 
	m_szCharacterName	= "";
	m_bCheckCharacterUID	= FALSE;		// 케릭터 UID 
	m_nCharacterUID		= 0;
	m_bCheckItemUID		= FALSE;
	m_ItemUID			= 0;
	m_bCheckItemNum = FALSE;
	m_ItemNum		= 0;
	m_bCheckMaxLogCount	= FALSE;
	m_MaxLogCount			= 100;
	
	// Search auction item
	m_bCheckSearchAuctionItemDate = TRUE;

	m_dateSearchAUctionItemStart = (CTime::GetCurrentTime() - CTimeSpan(1, 0 , 0, 0));

	m_bCheckSearchAuctionItemStatus = FALSE;

	UpdateData(FALSE);
}

void CMarketTabReturnAuction::InitGrid(CGridCtrl *i_pGridCtrl)
{
	i_pGridCtrl->SetBkColor(0xFFFFFF);
	
	int m_nRows = 1;
	int m_nCols = SIZE_MAX_MARKET_DESTROY_AUCTION_GRID_COUNT;
	
	i_pGridCtrl->SetEditable(TRUE);
	i_pGridCtrl->SetListMode(TRUE);
	i_pGridCtrl->SetSingleRowSelection(TRUE); 	
	i_pGridCtrl->EnableSelection(TRUE); 	
	i_pGridCtrl->SetFrameFocusCell(FALSE); 	
	i_pGridCtrl->SetTrackFocusCell(FALSE); 	
	i_pGridCtrl->SetHeaderSort(TRUE); 	
	
	i_pGridCtrl->SetRowCount(m_nRows);
	i_pGridCtrl->SetColumnCount(m_nCols);
	i_pGridCtrl->SetFixedRowCount(1);
	
	// 칼럼 만들기// 	
	m_nCols = 0;	
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = 0;
	Item.nFormat = GRID_CELL_FORMAT;
	
	for (int i = 0; i < SIZE_MAX_MARKET_DESTROY_AUCTION_GRID_COUNT; i++)	
	{ 	
		Item.col = i;	
		Item.strText.Format(_T(g_arrReturnAuctionColumnNames[i]));	
		i_pGridCtrl->SetItem(&Item);
	}

	i_pGridCtrl->AutoSize();
	i_pGridCtrl->ExpandColumnsToFit();

	// clean all cells// 	
	CCellRange tmpCellRange(1, 0, i_pGridCtrl->GetRowCount()-1, i_pGridCtrl->GetColumnCount()-1);
	i_pGridCtrl->ClearCells(tmpCellRange);	
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void CMarketTabReturnAuction::OnButtonAuctionSearchOk()
{
	UpdateData();

	if( m_bCheckCharacterName && 0 == m_szCharacterName.GetLength())
	{
		MessageBox("Invalid input value(CharacterName)!!");
		return;	
	}
	if( m_bCheckCharacterUID && 0 == m_nCharacterUID)
	{
		MessageBox("Invalid input value(CharacterUID)!!");
		return;		
	}
	if( m_bCheckItemUID && 0 == m_ItemUID)
	{
		MessageBox("Invalid input value(ItemUID)!!");
		return;		
	}
	if( m_bCheckItemNum && 0 == m_ItemNum)
	{
		MessageBox("Invalid input value(ItemNum)!!");
		return;
	}

	m_EditTotalLogRowCount.SetWindowText("");
	m_vectReturnAuctionInfoLogDataList.clear();

	DBQueryLoadReturnAuctionData(&m_vectReturnAuctionInfoLogDataList);		// 디비 로드 
	
	if( !m_vectReturnAuctionInfoLogDataList.size())
	{
		MessageBox("No data !!");
	}
	
	CCellRange tmpCellRange(1, 0, m_GridReturnAuction.GetRowCount()-1, m_GridReturnAuction.GetColumnCount()-1);
	m_GridReturnAuction.ClearCells(tmpCellRange);	
	m_GridReturnAuction.SetRowCount(1);

	MARKET_RETURN_AUCTION_INFO_LOG_DATA_ITR	itr(m_vectReturnAuctionInfoLogDataList.begin());
	for(; itr != m_vectReturnAuctionInfoLogDataList.end(); itr++)
	{
		MARKET_RETURN_AUCTION_INFO_LOG_DATA *MarketLogData = &*itr;
		_AddMarketLogData(&m_GridReturnAuction, MarketLogData);
	}

	// 리턴된 로그 수 할당
	char szRowCountBuf[10];
	m_EditTotalLogRowCount.SetWindowText(itoa(m_GridReturnAuction.GetRowCount() - 1, szRowCountBuf, 10));

	m_GridReturnAuction.ExpandColumnsToFit();
	m_GridReturnAuction.AutoSize();
	m_GridReturnAuction.UpdateData();
} 

void CMarketTabReturnAuction::OnButtonAuctionReset()
{
	m_EditTotalLogRowCount.SetWindowText(NULL);
	OnInitDialog();	
	UpdateData(FALSE);
}

void CMarketTabReturnAuction::OnButtonAuctionSaveResult()
{
	// TODO: Add your control notification handler code here
	int nRowCount = m_GridReturnAuction.GetRowCount();
	if(1 == nRowCount)
	{
		MessageBox("No data !!");
		return;
	}
	
	CSystemLogManager resultLog;
	if(FALSE == resultLog.InitLogManger(TRUE, "Return Auction itemLog", "./resultLog/"))
	{
		return;
	}
	
	for(int i=0; i < nRowCount; i++)
	{
		char szResult[2048];
		MEMSET_ZERO(szResult, 2048);
		sprintf(szResult, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\r\n",
			m_GridReturnAuction.GetItemText(i, 0), m_GridReturnAuction.GetItemText(i, 1), m_GridReturnAuction.GetItemText(i, 2),
			m_GridReturnAuction.GetItemText(i, 3), m_GridReturnAuction.GetItemText(i, 4), m_GridReturnAuction.GetItemText(i, 5),
			m_GridReturnAuction.GetItemText(i, 6), m_GridReturnAuction.GetItemText(i, 7), m_GridReturnAuction.GetItemText(i, 8),
			m_GridReturnAuction.GetItemText(i, 9), m_GridReturnAuction.GetItemText(i, 10), m_GridReturnAuction.GetItemText(i, 11),
			m_GridReturnAuction.GetItemText(i, 12));
		resultLog.WriteSystemLog(szResult, FALSE);
	}
	MessageBox("Save success !!");
}


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void CMarketTabReturnAuction::OnCheckDate()
{
	UpdateData();
	GetDlgItem(IDC_DATETIMEPICKER_START_DATE_AUCTION)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_COMBO_SELECTED_AUCTION_PERIOD)->EnableWindow(m_bCheckDate);
}
void CMarketTabReturnAuction::OnCheckInflunence()
{
	UpdateData();
	GetDlgItem(IDC_COMBO_SELECTED_INFLUENCE_TYPE)->EnableWindow(m_bCheckInfluence);
}
void CMarketTabReturnAuction::OnCheckStatus1()
{
	UpdateData();
	GetDlgItem(IDC_COMBO_SELECTED_AUCTION_STATUS_1)->EnableWindow(m_bCheckStatus);
}
void CMarketTabReturnAuction::OnCheckCharacterName()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_NAME)->EnableWindow(m_bCheckCharacterName);
}
void CMarketTabReturnAuction::OnCheckCharacterUID()
{
	UpdateData();		
	GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_UID)->EnableWindow(m_bCheckCharacterUID);
}
void CMarketTabReturnAuction::OnCheckItemUID()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_AUCTION_ITEM_UID)->EnableWindow(m_bCheckItemUID);
}
void CMarketTabReturnAuction::OnCheckItemNum()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_AUCTION_ITEM_NUM)->EnableWindow(m_bCheckItemNum);
}

void CMarketTabReturnAuction::OnCheckMaxRowCount()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_AUCTION_ITEM_MAX_LOG_COUNT)->EnableWindow(m_bCheckMaxLogCount);
}


// Search Auction Item
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void CMarketTabReturnAuction::OnCheckSearchAuctionItem()
{
	UpdateData();
	// search condition 	
	GetDlgItem(IDC_CHECK_AUCTION_DATE)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTION_INFLUENCE)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTIONT_STATUS_1)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTION_CHARACTER_NAME)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTION_CHARACTER_UID)->EnableWindow(!m_bCheckSearchAuctionItem);	
	GetDlgItem(IDC_CHECK_AUCTION_ITEM_UID)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTION_ITEM_NUM)->EnableWindow(!m_bCheckSearchAuctionItem);
	GetDlgItem(IDC_CHECK_AUCTION_MAX_ROW_COUNT)->EnableWindow(!m_bCheckSearchAuctionItem);
	
	if( m_bCheckSearchAuctionItem )
	{
		GetDlgItem(IDC_DATETIMEPICKER_START_DATE_AUCTION)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_AUCTION_PERIOD)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_INFLUENCE_TYPE)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_AUCTION_STATUS_1)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_NAME)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_UID)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_UID)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_NUM)->EnableWindow(!m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_MAX_LOG_COUNT)->EnableWindow(!m_bCheckSearchAuctionItem);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER_START_DATE_AUCTION)->EnableWindow(m_bCheckDate);
		GetDlgItem(IDC_COMBO_SELECTED_AUCTION_PERIOD)->EnableWindow(m_bCheckDate);
		GetDlgItem(IDC_COMBO_SELECTED_INFLUENCE_TYPE)->EnableWindow(m_bCheckInfluence);
		GetDlgItem(IDC_COMBO_SELECTED_AUCTION_STATUS_1)->EnableWindow(m_bCheckStatus);
		GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_NAME)->EnableWindow(m_bCheckCharacterName);		
		GetDlgItem(IDC_EDIT_AUCTION_CHARACTER_UID)->EnableWindow(m_bCheckCharacterUID);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_UID)->EnableWindow(m_bCheckItemUID);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_NUM)->EnableWindow(m_bCheckItemNum);
		GetDlgItem(IDC_EDIT_AUCTION_ITEM_MAX_LOG_COUNT)->EnableWindow(m_bCheckMaxLogCount);
	}

	// search auction item 
	if( m_bCheckSearchAuctionItem )
	{
		GetDlgItem(IDC_CHECK_SEARCH_AUCTION_ITEM_DATE)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_DATETIMEPICKER_START_DATE_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItemDate);
		GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItemDate);
		GetDlgItem(IDC_CHECK_SEARCH_AUCTION_ITEM_STATUS)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM_STATUS)->EnableWindow(m_bCheckSearchAuctionItemStatus);
	}
	else
	{
		GetDlgItem(IDC_CHECK_SEARCH_AUCTION_ITEM_DATE)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_DATETIMEPICKER_START_DATE_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_CHECK_SEARCH_AUCTION_ITEM_STATUS)->EnableWindow(m_bCheckSearchAuctionItem);
		GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM_STATUS)->EnableWindow(m_bCheckSearchAuctionItem);
	}
	
}
void CMarketTabReturnAuction::OnCheckDate2()
{
	UpdateData();
	GetDlgItem(IDC_DATETIMEPICKER_START_DATE_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItemDate);
	GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM)->EnableWindow(m_bCheckSearchAuctionItemDate);
}
void CMarketTabReturnAuction::OnCheckStatus2()
{
	UpdateData();
	GetDlgItem(IDC_COMBO_SELECTED_SEARCH_AUCTION_ITEM_STATUS)->EnableWindow(m_bCheckSearchAuctionItemStatus);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

char* CMarketTabReturnAuction::GetLogtypeString(BYTE i_logtype)
{
	switch (i_logtype)
	{
	case 1:		return "DestroyedItem";		break;			// 파괴되어 경매장에 올려질수 있는 아이템 
	case 2:		return "Registered item";	break;			// 파괴경매장 리스트업 된 아이템 
	case 3:		return "Tender";			break;			// 아이템 입찰 
	case 4:		return "bidding";			break;			// 아이템 낙찰 
	case 5:		return "Get Exchange";		break;			// 아이템 회수 
	case 6:		return "Not Tender";		break;			// 입찰이 안번도 안된 아이템
	default:	return "error!!";			break;
	}	
	return "error!!";	
}

char* CMarketTabReturnAuction::GetInfluenceString(BYTE i_influence)
{
	switch (i_influence)
	{
	case 0:		return " ";				break;
	case 1:		return "NORMAL";		break;
	case 2:		return "BCU";			break;
	case 4:		return "ANI";			break;
	default:	return "ERROR!!";		break;
	}	
	return "ERROR!!";	
}

BOOL CMarketTabReturnAuction::SetTimeStamp( CTime* i_pDateyymmdd, CComboBox* i_pComboBox, SQL_TIMESTAMP_STRUCT* o_tempStart, SQL_TIMESTAMP_STRUCT* o_tempEnd)
{
	// 시작 시간 설정 
	o_tempStart->year = i_pDateyymmdd->GetYear();
	o_tempStart->month = i_pDateyymmdd->GetMonth();
	o_tempStart->day = i_pDateyymmdd->GetDay();
	o_tempStart->hour = ( i_pComboBox->GetCurSel() ) * 3;		
	o_tempStart->minute = 0;
	o_tempStart->second = 0;
	o_tempStart->fraction = 0;
	
	// 종료시간 설정 		
	o_tempEnd->year = i_pDateyymmdd->GetYear();
	o_tempEnd->month = i_pDateyymmdd->GetMonth();
	o_tempEnd->day = i_pDateyymmdd->GetDay();
	o_tempEnd->hour = (o_tempStart->hour + 2)%24;
	o_tempEnd->minute = 59;
	o_tempEnd->second = 59;
	o_tempEnd->fraction = 0;

	CTime temp(i_pDateyymmdd->GetYear(), i_pDateyymmdd->GetMonth(),i_pDateyymmdd->GetDay(),o_tempEnd->hour,59,59);
	if( CTime::GetCurrentTime() <= temp )
	{
		return FALSE;
	}

	return TRUE; 
}

BOOL CMarketTabReturnAuction::DBQueryLoadReturnAuctionData(vect_MARKET_RETURN_AUCTION_INFO_LOG_DATA *o_pVectMarketInfoLogDataList)
{

	SQL_TIMESTAMP_STRUCT tempStartDateTime;
	SQL_TIMESTAMP_STRUCT tempEndDateTime;
	
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();

	if ( m_bCheckSearchAuctionItem )
	{
		SetTimeStamp( &m_dateSearchAUctionItemStart, &m_comboSearchAuctionItem, &tempStartDateTime, &tempEndDateTime);

		BYTE tempStatus = 0;
		if( m_bCheckSearchAuctionItemStatus )
		{
			tempStatus = m_comboSearchAuctionItemStatus.GetCurSel() + 1 ;	// DB 로그타입 낙찰 : 4 , cancel :2 
		}
			
		int row = 1;
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &m_bCheckSearchAuctionItemDate, 0, NULL);	
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempStartDateTime, 0, NULL);							
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempEndDateTime, 0, NULL);
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TINYINT, SQL_TINYINT, 0, 0, &tempStatus, 0, NULL);
		BOOL bRet = m_pODBCStmt->ExecuteQuery(PROCEDURE_140512_0002);		
		if (!bRet)
		{
			m_pODBCStmt->FreeStatement();		// cleanup		
			AfxMessageBox("DBQueryLoadReturnAuctionData PROCEDURE_140512_0002 error !!");
			return FALSE;
		}			
	}
	else
	{	
		BYTE	temp_status  = 0;
		BYTE	temp_influenceType	= 0;
		int		temp_CharacterUID = 0;
		int		temp_ItemUID = 0;
		int		temp_ItemNum = 0;
	
		// 시간 설정 
		if ( FALSE == SetTimeStamp( &m_dateStart, &m_comboSearchCondition, &tempStartDateTime, &tempEndDateTime) )
		{
			AfxMessageBox("Auction is in progress or the time value is not correct.!!");
			m_pODBCStmt->FreeStatement();		// cleanup	
			return FALSE;
		}

		if( m_bCheckInfluence)
		{
			temp_influenceType = m_comboInfluence.GetCurSel();	
		}		
		if( m_bCheckStatus )
		{
			temp_status = m_comboStatus.GetCurSel() + 1 ;			// DB 로그타입 낙찰 : 4 , cancel :2 
		}		

		temp_CharacterUID = m_bCheckCharacterUID?(m_nCharacterUID):(0);
		temp_ItemUID = m_bCheckItemUID?(m_ItemUID):(0);
		temp_ItemNum = m_bCheckItemNum?(m_ItemNum):(0);

		int row = 1;
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &m_bCheckDate, 0, NULL);	
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempStartDateTime, 0, NULL);							
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempEndDateTime, 0, NULL);		
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TINYINT, SQL_TINYINT, 0, 0, &temp_influenceType, 0, NULL);
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TINYINT, SQL_TINYINT, 0, 0, &temp_status, 0, NULL);

		SQLINTEGER cb1 = SQL_NTS;
		SQLBindParameter(hstmt,row++, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_CHARACTER_NAME+1, 0, LPSTR(LPCTSTR( m_bCheckCharacterName?(m_szCharacterName):(""))), 0, &cb1);
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_CharacterUID, 0, NULL);
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_ItemUID, 0, NULL);
		SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_ItemNum, 0, NULL);		
		
		BOOL bRet = m_pODBCStmt->ExecuteQuery(PROCEDURE_140512_0003);		
		if (!bRet)
		{
			m_pODBCStmt->FreeStatement();		// cleanup		
			AfxMessageBox("DBQueryLoadReturnAuctionData PROCEDURE_140512_0003 error !!");
			return FALSE;
		}	
	}

	SQLINTEGER arrCB[18]={SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,		SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
		SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,		SQL_NTS,SQL_NTS,SQL_NTS};

	MARKET_RETURN_AUCTION_INFO_LOG_DATA tmMarketInfoLogData;
	SQLBindCol(hstmt,  1, SQL_C_SBIGINT, &tmMarketInfoLogData.TransactionNum,			 0,	&arrCB[1]);
	SQLBindCol(hstmt,  2, SQL_C_TINYINT, &tmMarketInfoLogData.LogType,					0,	&arrCB[2]);
	SQLBindCol(hstmt,  3, SQL_C_CHAR, &tmMarketInfoLogData.CharacterName,SIZE_MAX_CHARACTER_NAME,	&arrCB[3]);
	SQLBindCol(hstmt,  4, SQL_C_LONG, &tmMarketInfoLogData.CharacterUID, 0,					&arrCB[4]);
	SQL_TIMESTAMP_STRUCT   Date;
	SQLBindCol(hstmt,  5, SQL_C_TIMESTAMP, &Date,										 0,	&arrCB[5]);
	SQLBindCol(hstmt,  6, SQL_C_TINYINT, &tmMarketInfoLogData.influence, 0,					&arrCB[6]);
	SQLBindCol(hstmt,  7, SQL_C_LONG, &tmMarketInfoLogData.Price, 0,						&arrCB[7]);
	SQLBindCol(hstmt,  8, SQL_C_TINYINT, &tmMarketInfoLogData.MoneyType,0		,			&arrCB[8]);
	SQLBindCol(hstmt,  9, SQL_C_LONG, &tmMarketInfoLogData.ItemCount, 0,					&arrCB[9]);
	SQLBindCol(hstmt,  10, SQL_C_SBIGINT, &tmMarketInfoLogData.ItemUID, 0,					&arrCB[10]);
	SQLBindCol(hstmt,  11, SQL_C_LONG, &tmMarketInfoLogData.ItemNum, 0,						&arrCB[11]);
	SQLBindCol(hstmt,  12, SQL_C_TINYINT, &tmMarketInfoLogData.ItemKind, 0,					&arrCB[12]);
	SQLBindCol(hstmt,  13, SQL_C_CHAR, &tmMarketInfoLogData.ItemName, MARKET_ITEM_FULL_NAME,&arrCB[13]);
	SQLBindCol(hstmt,  14, SQL_C_LONG, &tmMarketInfoLogData.PrefixCodeNum, 0,				&arrCB[14]);
	SQLBindCol(hstmt,  15, SQL_C_LONG, &tmMarketInfoLogData.SuffixCodeNum, 0,				&arrCB[15]);
	SQLBindCol(hstmt,  16, SQL_C_TINYINT, &tmMarketInfoLogData.EnchantCount, 0,				&arrCB[16]);
	SQLBindCol(hstmt,  17, SQL_C_LONG, &tmMarketInfoLogData.ColorCode, 0,					&arrCB[17]);
	do
	{
		MEMSET_ZERO(&tmMarketInfoLogData, sizeof(MARKET_RETURN_AUCTION_INFO_LOG_DATA));
		
		SQLRETURN ret = SQLFetch(hstmt);
		if(SQL_ERROR == ret)
		{
			m_pODBCStmt->ProcessLogMessagesForStmt(PROCEDURE_140423_0001);	
		}
		if(SQL_SUCCESS != ret && SQL_SUCCESS_WITH_INFO != ret)
		{
			break;
		}
		tmMarketInfoLogData.DateTime	= Date;
		o_pVectMarketInfoLogDataList->push_back(tmMarketInfoLogData);

		if (o_pVectMarketInfoLogDataList->size() >= max(100, (m_bCheckMaxLogCount?m_MaxLogCount:SIZE_MAX_LOG_ROW_COUNT)))
		{
			MessageBox(STRERR_S_SCADMINTOOL_0012);
			break;			
		}
	}while(TRUE);
	
	m_pODBCStmt->FreeStatement();		// cleanup	
	return TRUE;
}

INT CMarketTabReturnAuction::_AddMarketLogData(CGridCtrl *i_pGridCtrl, MARKET_RETURN_AUCTION_INFO_LOG_DATA *i_pMarketLogData)
{
	GV_ITEM Item;
	
	Item.mask		= GVIF_TEXT|GVIF_FORMAT;
	Item.nFormat	= DT_LEFT|DT_VCENTER|DT_SINGLELINE;
	
	int nNewRowIdx = i_pGridCtrl->GetRowCount();
	i_pGridCtrl->SetRowCount(nNewRowIdx+1);
	
	int nColumn = 0;

	//select된 값을 GridDetail GridCtrl에 넣어준다.
	Item.row		= nNewRowIdx;
	
	Item.col		= nColumn++;
	Item.strText.Format("%d", i_pMarketLogData->TransactionNum);
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	Item.strText.Format("%s", GetLogtypeString(i_pMarketLogData->LogType));
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	Item.strText.Format("%s(%d)", i_pMarketLogData->CharacterName,i_pMarketLogData->CharacterUID);
	i_pGridCtrl->SetItem(&Item);

	Item.col		= nColumn++;
	Item.strText.Format("%s", i_pMarketLogData->DateTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	Item.strText.Format("%s", GetInfluenceString(i_pMarketLogData->influence));
	i_pGridCtrl->SetItem(&Item);

	Item.col		= nColumn++;
	Item.strText.Format("%d(%s)", i_pMarketLogData->Price,i_pMarketLogData->MoneyType?"WP":"SPI");
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	//Item.strText.Format("%d", (IS_COUNTABLE_ITEM(i_pMarketLogData->ItemKind))?(i_pMarketLogData->ItemCount):(1));
	Item.strText.Format("%d", 1);
	i_pGridCtrl->SetItem(&Item);	

	Item.col		= nColumn++;
	Item.strText.Format("%I64d(%d)", i_pMarketLogData->ItemUID,i_pMarketLogData->ItemNum);
	i_pGridCtrl->SetItem(&Item);	
	
	Item.col		= nColumn++;
	Item.strText.Format("%s", i_pMarketLogData->ItemName);
	i_pGridCtrl->SetItem(&Item);	

	Item.col		= nColumn++;
	Item.strText.Format("%d", i_pMarketLogData->PrefixCodeNum);
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	Item.strText.Format("%d", i_pMarketLogData->SuffixCodeNum);
	i_pGridCtrl->SetItem(&Item);	

	Item.col		= nColumn++;
	Item.strText.Format("%d", i_pMarketLogData->EnchantCount);
	i_pGridCtrl->SetItem(&Item);
	
	Item.col		= nColumn++;
	Item.strText.Format("%d", i_pMarketLogData->ColorCode);
	i_pGridCtrl->SetItem(&Item);

		
	return nNewRowIdx;
}

