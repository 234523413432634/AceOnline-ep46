// LogTabItem.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "MarketTabTradeCenter.h"

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
const char *g_arrMarketLogColumnNames[] = {
		"IDX",
		"TradeStatus",
		"Character Name(UID)",
		"Date",
		"Influence",
		"Price(Type)",
		"Count",
		"ItemUID(ItemNum)",
		"ItemName",
		"PrefixNum",
		"SuffixNum",
		"Enchant",
		NULL
};

CMarketTabTradeCenter::CMarketTabTradeCenter(CDialog *i_pMainDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CMarketTabTradeCenter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogTabItem)
	//}}AFX_DATA_INIT
	//m_pMainDlg = (CSCMarketLogDlg*)i_pMainDlg;
	m_pMainDlg = (CSCLogAdminDlg*)i_pMainDlg;
	m_pODBCStmt = &(m_pMainDlg->m_ODBCStmt);
}

void CMarketTabTradeCenter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogTabItem)
	DDX_Control(pDX, IDC_COMBO_SELECTED_INFLUENCE_TYPE, m_comboInfluence);
	DDX_Control(pDX, IDC_EDIT_ITEM_TOTAL_LOG_COUNT, m_EditTotalLogRowCount);
	DDX_Text(pDX, IDC_EDIT_ITEM_MAX_LOG_COUNT, m_MaxLogCount);
	DDX_Check(pDX, IDC_CHECK_DATE, m_bCheckDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_DATE, m_dateStart);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_TIME, m_timeStart);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END_DATE, m_dateEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END_TIME, m_timeEnd);
	DDX_Check(pDX, IDC_CHECK_MARKET_INFLUENCE, m_bCheckInfluence	);	
	DDX_Check(pDX, IDC_CHECK_MARKET_CHARACTER_NAME, m_bCheckCharacterName	);
	DDX_Text(pDX, IDC_EDIT_MARKET_CHARACTER_NAME, m_szCharacterName);
	DDX_Check(pDX, IDC_CHECK_MARKET_CHARACTER_UID, m_bCheckCharacterUID);
	DDX_Text(pDX, IDC_EDIT_MARKET_CHARACTER_UID, m_nCharacterUID);	
	DDX_Check(pDX, IDC_CHECK_ITEM_UID, m_bCheckItemUID);
	DDX_Text(pDX, IDC_EDIT_ITEM_UID, m_ItemUID);
	DDX_Text(pDX, IDC_EDIT_ITEM_NUM, m_ItemNum);

	DDX_Check(pDX, IDC_CHECK_ITEM_NUM, m_bCheckItemNum);
	DDX_Check(pDX, IDC_CHECK_MAX_ROW_COUNT, m_bCheckMaxLogCount	);
	DDX_Check(pDX, IDC_CHECK_BUY_ITEM, m_bCheckBuyItem);
	DDX_Check(pDX, IDC_CHECK_SELL_ITEM, m_bCheckSellItem);
	DDX_Check(pDX, IDC_CHECK_CANCEL_TRADE, m_bCheckCancelTrade);
	DDX_Check(pDX, IDC_CHECK_GET_EXCHANGE, m_bCheckGetExchange);
	DDX_Check(pDX, IDC_CHECK_USE_SPI, m_bCheckUseSPI);
	DDX_Check(pDX, IDC_CHECK_USE_WP, m_bCheckUseWP);

	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_TRADE_MARKET, m_GridTradeMarket);
}


BEGIN_MESSAGE_MAP(CMarketTabTradeCenter, CDialog)
//{{AFX_MSG_MAP(CLogTabItem)
ON_BN_CLICKED(IDC_CHECK_DATE, OnCheckDate)
ON_BN_CLICKED(IDC_CHECK_MARKET_INFLUENCE, OnCheckInflunence)
ON_BN_CLICKED(IDC_CHECK_MARKET_CHARACTER_NAME, OnCheckCharacterName)
ON_BN_CLICKED(IDC_CHECK_MARKET_CHARACTER_UID, OnCheckCharacterUID)
ON_BN_CLICKED(IDC_CHECK_ITEM_UID, OnCheckItemUID)
ON_BN_CLICKED(IDC_CHECK_ITEM_NUM, OnCheckItemNum)
ON_BN_CLICKED(IDC_CHECK_MAX_ROW_COUNT, OnCheckMaxRowCount)
ON_BN_CLICKED(IDC_BUTTON_MARKET_TRADE_SELECT_ALL, OnButtonMarketSelectAll)
ON_BN_CLICKED(IDC_BUTTON_MARKET_TRADE_REMOVE_ALL, OnButtonMarketRemoveAll)
ON_BN_CLICKED(IDC_BUTTON_MARKET_SEARCH, OnButtonMarketSearchOk)
ON_BN_CLICKED(IDC_BUTTON_MARKET_RESET, OnButtonMarketReset)
ON_BN_CLICKED(IDC_BUTTON_MARKET_SAVE_RESULT, OnButtonMarketSaveResult)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogTabItem message handlers

BOOL CMarketTabTradeCenter::PreTranslateMessage(MSG* pMsg) 
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

BOOL CMarketTabTradeCenter::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here

	// 그리드 초기화 
	ResetVariables();
	InitGrid(&m_GridTradeMarket);

	m_comboInfluence.ResetContent();
	m_comboInfluence.AddString("ALL");
	m_comboInfluence.AddString("NORMAL");
	m_comboInfluence.AddString("BCU");
	m_comboInfluence.AddString("ANI");
	m_comboInfluence.SetCurSel(0);

	m_dateStart = (CTime::GetCurrentTime() - CTimeSpan(1, 0 , 0, 0));
	m_dateEnd = CTime::GetCurrentTime();

	GetDlgItem(IDC_DATETIMEPICKER_START_DATE)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_END_DATE)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_START_TIME)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_END_TIME)->EnableWindow(m_bCheckDate);

	GetDlgItem(IDC_COMBO_SELECTED_INFLUENCE_TYPE)->EnableWindow(m_bCheckInfluence);
	GetDlgItem(IDC_EDIT_MARKET_CHARACTER_NAME)->EnableWindow(m_bCheckCharacterName);
	GetDlgItem(IDC_EDIT_MARKET_CHARACTER_UID)->EnableWindow(m_bCheckCharacterUID);
	GetDlgItem(IDC_EDIT_ITEM_UID)->EnableWindow(m_bCheckItemUID);
	GetDlgItem(IDC_EDIT_ITEM_NUM)->EnableWindow(m_bCheckItemNum);
	GetDlgItem(IDC_EDIT_ITEM_MAX_LOG_COUNT)->EnableWindow(m_bCheckMaxLogCount);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMarketTabTradeCenter::ResetVariables()
{
	m_bCheckDate	= TRUE;			//기간선택 
	m_bCheckInfluence	= FALSE;		// 세력 선택 
	m_InfluenceType		= 1;	
	m_bCheckCharacterName	= FALSE;	// 케릭터 이름 
	m_szCharacterName	= "";

	m_bCheckCharacterUID= 0;		// 케릭터 UID 
	m_nCharacterUID		= 0;

	m_bCheckItemUID		= FALSE;			// 아이템 UID
	m_ItemUID				= 0;
	m_bCheckItemNum		= FALSE;			// 아이템 Num
	m_ItemNum				= 0;
	m_bCheckMaxLogCount	= FALSE;
	m_MaxLogCount			= 100;
	
	// kind of log
	m_bCheckBuyItem = TRUE;
	m_bCheckSellItem = TRUE;
	m_bCheckCancelTrade = FALSE;
	m_bCheckGetExchange = FALSE;
	m_bCheckUseSPI = FALSE;			// money type
	m_bCheckUseWP = FALSE;

	UpdateData(FALSE);
}

void CMarketTabTradeCenter::InitGrid(CGridCtrl *i_pGridCtrl)
{
	i_pGridCtrl->SetBkColor(0xFFFFFF);
	
	int m_nRows = 1;
	int m_nCols = SIZE_MAX_MARKET_TRADE_CENTER_GRID_COUNT;
	
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
	
	for (int i = 0; i < SIZE_MAX_MARKET_TRADE_CENTER_GRID_COUNT; i++)	
	{ 	
		Item.col = i;	
		Item.strText.Format(_T(g_arrMarketLogColumnNames[i]));	
		i_pGridCtrl->SetItem(&Item);
	}

	i_pGridCtrl->AutoSize();
	i_pGridCtrl->ExpandColumnsToFit();

	// clean all cells// 	
	CCellRange tmpCellRange(1, 0, i_pGridCtrl->GetRowCount()-1, i_pGridCtrl->GetColumnCount()-1);
	i_pGridCtrl->ClearCells(tmpCellRange);	
}
void CMarketTabTradeCenter::OnButtonMarketSearchOk()
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

	// 2014-05-26 by bckim, 거래소 운영툴 예외사항 추가 
	if( !m_bCheckBuyItem && !m_bCheckSellItem && !m_bCheckCancelTrade
		&& !m_bCheckGetExchange && !m_bCheckUseSPI && !m_bCheckUseWP )
	{
		MessageBox("No option is selected.(Kind of log)!!");
		return;
	}
	// 2014-05-26 by bckim, 거래소 운영툴 예외사항 추가 

	m_EditTotalLogRowCount.SetWindowText("");
	m_vectMarketInfoLogDataList.clear();

	DBQueryLoadMarketData(&m_vectMarketInfoLogDataList);		// 디비 로드 
	
	if( !m_vectMarketInfoLogDataList.size())
	{
		MessageBox("No data !!");
	}
	
	CCellRange tmpCellRange(1, 0, m_GridTradeMarket.GetRowCount()-1, m_GridTradeMarket.GetColumnCount()-1);
	m_GridTradeMarket.ClearCells(tmpCellRange);	
	m_GridTradeMarket.SetRowCount(1);

	MARKET_INFO_LOG_DATA_ITR	itr(m_vectMarketInfoLogDataList.begin());
	for(; itr != m_vectMarketInfoLogDataList.end(); itr++)
	{
		MARKET_INFO_LOG_DATA *MarketLogData = &*itr;
		_AddMarketLogData(&m_GridTradeMarket, MarketLogData);
	}

	// 리턴된 로그 수 할당
	char szRowCountBuf[10];
	m_EditTotalLogRowCount.SetWindowText(itoa(m_GridTradeMarket.GetRowCount() - 1, szRowCountBuf, 10));

	m_GridTradeMarket.AutoSize();
	m_GridTradeMarket.ExpandColumnsToFit();
	m_GridTradeMarket.UpdateData();
} 

void CMarketTabTradeCenter::OnButtonMarketSelectAll()
{
	UpdateData(TRUE);
	m_bCheckBuyItem = TRUE;
	m_bCheckSellItem = TRUE;
	m_bCheckCancelTrade = TRUE;
	m_bCheckGetExchange = TRUE;
	m_bCheckUseSPI = TRUE;
	m_bCheckUseWP = TRUE;
	UpdateData(FALSE);
}

void CMarketTabTradeCenter::OnButtonMarketRemoveAll()
{
	UpdateData(TRUE);
	m_bCheckBuyItem = FALSE;
	m_bCheckSellItem = FALSE;
	m_bCheckCancelTrade = FALSE;
	m_bCheckGetExchange = FALSE;
	m_bCheckUseSPI = FALSE;
	m_bCheckUseWP = FALSE;
	UpdateData(FALSE);
}

void CMarketTabTradeCenter::OnButtonMarketReset()
{
	int temp = 0;
	OnButtonMarketRemoveAll();
	m_EditTotalLogRowCount.SetWindowText(NULL);
	OnInitDialog();	
	UpdateData(FALSE);

}

void CMarketTabTradeCenter::OnButtonMarketSaveResult()
{
	// TODO: Add your control notification handler code here
	int nRowCount = m_GridTradeMarket.GetRowCount();
	if(1 == nRowCount)
	{
		MessageBox("No data !!");
		return;
	}
	
	CSystemLogManager resultLog;
	if(FALSE == resultLog.InitLogManger(TRUE, "Trade Market itemLog", "./resultLog/"))
	{
		return;
	}
	
	for(int i=0; i < nRowCount; i++)
	{
		char szResult[2048];
		MEMSET_ZERO(szResult, 2048);
		sprintf(szResult, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\r\n",
			m_GridTradeMarket.GetItemText(i, 0), m_GridTradeMarket.GetItemText(i, 1), m_GridTradeMarket.GetItemText(i, 2),
			m_GridTradeMarket.GetItemText(i, 3), m_GridTradeMarket.GetItemText(i, 4), m_GridTradeMarket.GetItemText(i, 5),
			m_GridTradeMarket.GetItemText(i, 6), m_GridTradeMarket.GetItemText(i, 7), m_GridTradeMarket.GetItemText(i, 8),
			m_GridTradeMarket.GetItemText(i, 9), m_GridTradeMarket.GetItemText(i, 10), m_GridTradeMarket.GetItemText(i, 11));
		resultLog.WriteSystemLog(szResult, FALSE);
	}
	MessageBox("Save success !!");
}

void CMarketTabTradeCenter::OnCheckDate()
{
	UpdateData();
	GetDlgItem(IDC_DATETIMEPICKER_START_DATE)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_END_DATE)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_START_TIME)->EnableWindow(m_bCheckDate);
	GetDlgItem(IDC_DATETIMEPICKER_END_TIME)->EnableWindow(m_bCheckDate);

}
void CMarketTabTradeCenter::OnCheckInflunence()
{
	UpdateData();
	GetDlgItem(IDC_COMBO_SELECTED_INFLUENCE_TYPE)->EnableWindow(m_bCheckInfluence);
}
void CMarketTabTradeCenter::OnCheckCharacterName()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_MARKET_CHARACTER_NAME)->EnableWindow(m_bCheckCharacterName);
}
void CMarketTabTradeCenter::OnCheckCharacterUID()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_MARKET_CHARACTER_UID)->EnableWindow(m_bCheckCharacterUID);
}
void CMarketTabTradeCenter::OnCheckItemUID()
{
	UpdateData();		
	GetDlgItem(IDC_EDIT_ITEM_UID)->EnableWindow(m_bCheckItemUID);
}
void CMarketTabTradeCenter::OnCheckItemNum()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_ITEM_NUM)->EnableWindow(m_bCheckItemNum);
}
void CMarketTabTradeCenter::OnCheckMaxRowCount()
{
	UpdateData();
	GetDlgItem(IDC_EDIT_ITEM_MAX_LOG_COUNT)->EnableWindow(m_bCheckMaxLogCount);
}



char* CMarketTabTradeCenter::GetLogtypeString(BYTE i_logtype)
{
	switch (i_logtype)
	{
	case 1:		return "Sell";				break;
	case 2:		return "Buy";				break;
	case 3:		return "Cancel";			break;
	case 4:		return "Get Exchange";		break;
	default:	return "error!!";			break;
	}	
	return "error!!";	
}

char* CMarketTabTradeCenter::GetInfluenceString(BYTE i_influence)
{
	switch (i_influence)
	{
	case 1:		return "NORMAL";		break;
	case 2:		return "BCU";			break;
	case 4:		return "ANI";			break;
	default:	return "ERROR!!";		break;
	}	
	return "ERROR!!";	
}

BOOL CMarketTabTradeCenter::DBQueryLoadMarketData(vect_MARKET_INFO_LOG_DATA *o_pVectMarketInfoLogDataList)
{
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();

	BYTE	temp_influenceType	= 0;	
	BYTE	temp_kindBuy = 0;	
	BYTE	temp_kindSell = 0;	
	BYTE	temp_kindCancel = 0;	
	BYTE	temp_kindGet = 0;	
	BYTE	temp_m_MoneyType	= 0;
	
	int temp_CharacterUID = 0;
	int temp_ItemUID = 0;
	int temp_ItemNum = 0;


	temp_CharacterUID = m_bCheckCharacterUID?(m_nCharacterUID):(0);
	temp_ItemUID = m_bCheckItemUID?(m_ItemUID):(0);
	temp_ItemNum = m_bCheckItemNum?(m_ItemNum):(0);

	if( m_bCheckInfluence)
	{
		switch(m_comboInfluence.GetCurSel())
		{
		case 0: temp_influenceType = 0; break;
		case 1: temp_influenceType = 1; break;
		case 2: temp_influenceType = 2; break;
		case 3: temp_influenceType = 4; break;
		default: temp_influenceType = 0; break;
		}
	}

	temp_kindBuy =  m_bCheckBuyItem?(2):(0);
	temp_kindSell = m_bCheckSellItem?(1):(0);
	temp_kindCancel = m_bCheckCancelTrade?(3):(0);
	temp_kindGet = m_bCheckGetExchange?(4):(0);

	if(m_bCheckUseSPI)
		temp_m_MoneyType += 1;
	if(m_bCheckUseWP)
		temp_m_MoneyType += 2;
	
	SQL_TIMESTAMP_STRUCT tempStartDateTime;
	tempStartDateTime.year = m_dateStart.GetYear();
	tempStartDateTime.month = m_dateStart.GetMonth();
	tempStartDateTime.day = m_dateStart.GetDay();
	tempStartDateTime.hour	= m_timeStart.GetHour();
	tempStartDateTime.minute = m_timeStart.GetMinute();
	tempStartDateTime.second = m_timeStart.GetSecond();
	tempStartDateTime.fraction = 0;
	
	SQL_TIMESTAMP_STRUCT tempEndDateTime;
	tempEndDateTime.year = m_dateEnd.GetYear();
	tempEndDateTime.month = m_dateEnd.GetMonth();
	tempEndDateTime.day = m_dateEnd.GetDay();
	tempEndDateTime.hour	= m_timeEnd.GetHour();
	tempEndDateTime.minute = m_timeEnd.GetMinute();
	tempEndDateTime.second = m_timeEnd.GetSecond();
	tempEndDateTime.fraction = 0;

	int row = 1;
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &m_bCheckDate, 0, NULL);	
 	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempStartDateTime, 0, NULL);							
 	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 3, (SQLPOINTER)&tempEndDateTime, 0, NULL);
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_TINYINT, SQL_TINYINT, 0, 0, &temp_influenceType, 0, NULL);
	SQLINTEGER cb1 = SQL_NTS;
	SQLBindParameter(hstmt,row++, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_CHARACTER_NAME+1, 0, LPSTR(LPCTSTR( m_bCheckCharacterName?(m_szCharacterName):(""))), 0, &cb1);
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_CharacterUID, 0, NULL);
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_ItemUID, 0, NULL);
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0,	&temp_ItemNum, 0, NULL);		
	// 	kind of Log
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &temp_kindBuy, 0, NULL);	
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &temp_kindSell, 0, NULL);	
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &temp_kindCancel, 0, NULL);	
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &temp_kindGet, 0, NULL);	
	SQLBindParameter(hstmt,row++,SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &temp_m_MoneyType, 0, NULL);	
	
	BOOL bRet = m_pODBCStmt->ExecuteQuery(PROCEDURE_140423_0001);		
	if (!bRet)
	{
		m_pODBCStmt->FreeStatement();		// cleanup		
		AfxMessageBox("DBQueryLoadMarketData error !!");
		return FALSE;
	}	

	SQLINTEGER arrCB[17]={SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,		SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,
		SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,		SQL_NTS, SQL_NTS};

	MARKET_INFO_LOG_DATA tmMarketInfoLogData;
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
	do
	{
		MEMSET_ZERO(&tmMarketInfoLogData, sizeof(MARKET_INFO_LOG_DATA));
		
		SQLRETURN ret = SQLFetch(hstmt);
		if(SQL_ERROR == ret)
		{
			m_pODBCStmt->ProcessLogMessagesForStmt(PROCEDURE_140423_0001);	//[atum_Load_Realignment_CashShop]
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

INT CMarketTabTradeCenter::_AddMarketLogData(CGridCtrl *i_pGridCtrl, MARKET_INFO_LOG_DATA *i_pMarketLogData)
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
	Item.strText.Format("%d", (IS_COUNTABLE_ITEM(i_pMarketLogData->ItemKind))?(i_pMarketLogData->ItemCount):(1));
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
		
	return nNewRowIdx;
}
