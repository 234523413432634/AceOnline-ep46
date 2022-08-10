// ArmorCollectionEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "SCUserAdminDlg.h"
#include "ArmorCollectionEditDlg.h"
#include "ArmorCollectionAddDlg.h"
#include "ArmorCollectionModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionEditDlg dialog


CArmorCollectionEditDlg::CArmorCollectionEditDlg(UID32_t i_u32AccUID, CODBCStatement *i_pODBC, CSCUserAdminDlg* pParent /*=NULL*/)
	: CDialog(CArmorCollectionEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CArmorCollectionEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nAccountUID			= i_u32AccUID;
	m_pODBCStmt				= i_pODBC;
	m_pCUserAdminDlg		= pParent;
}


void CArmorCollectionEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArmorCollectionEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_GridControl(pDX, IDC_GRID_COLLECTION_LIST, m_GridCollectionList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArmorCollectionEditDlg, CDialog)
	//{{AFX_MSG_MAP(CArmorCollectionEditDlg)
		// NOTE: the ClassWizard will add message map macros here
	ON_NOTIFY(NM_RCLICK, IDC_GRID_COLLECTION_LIST, OnGridRClick)
	ON_NOTIFY(NM_CLICK, IDC_GRID_COLLECTION_LIST, OnGridClick)
	ON_COMMAND(ID_CMG_INSERT_ITEM, OnCmgInsertItem)
	ON_COMMAND(ID_CMG_MODIFY_ITEM, OnCmgModifyItem)
	ON_COMMAND(ID_CMG_DELETE_ITEM, OnCmgDeleteItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionEditDlg message handlers
BOOL CArmorCollectionEditDlg::PreTranslateMessage(MSG* pMsg) 
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

BOOL CArmorCollectionEditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	//	// Set the icon for this dialog.  The framework does this automatically
	//	//  when the application's main window is not a dialog
	//	SetIcon(m_hIcon, TRUE);			// Set big icon
	//	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	LoadUserArmorCollectionList();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CArmorCollectionEditDlg::InitGridItem()
{
	m_GridCollectionList.SetBkColor(0xFFFFFF);

	int m_nRows = 1;
	int m_nCols = 7;
	int m_nFixRows = 1;
	
	m_GridCollectionList.SetEditable(FALSE);
	m_GridCollectionList.SetListMode(TRUE);
	m_GridCollectionList.SetSingleRowSelection(TRUE);	// 오직 1게의 라인만 선택 가능하게 하는 옵션
	m_GridCollectionList.EnableSelection(TRUE);
	m_GridCollectionList.SetHeaderSort(FALSE);
	m_GridCollectionList.SetFrameFocusCell(FALSE);
	m_GridCollectionList.SetTrackFocusCell(FALSE);

	m_GridCollectionList.SetRowCount(m_nRows);
	m_GridCollectionList.SetColumnCount(m_nCols);
	m_GridCollectionList.SetFixedRowCount(m_nFixRows);

	// 칼럼 만들기
	m_nCols = 0;
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = 0;
	Item.nFormat = GRID_CELL_FORMAT;

	Item.col = m_nCols++;
	Item.strText.Format(_T("ShapeNum"));
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format(_T("ShapeName"));
	m_GridCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("Level"));
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format(_T("RemainTime"));
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format(_T("MonthlyArmorEventOption"));
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	Item.strText.Format(_T("OptionItemNum"));
	m_GridCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("OptionDurationTime"));
	m_GridCollectionList.SetItem(&Item);

	m_GridCollectionList.AutoSize();
	m_GridCollectionList.ExpandColumnsToFit();

	// clean all cells
	CCellRange tmpCellRange(1, 0, m_GridCollectionList.GetRowCount()-1, m_GridCollectionList.GetColumnCount()-1);
	m_GridCollectionList.ClearCells(tmpCellRange);
}

void CArmorCollectionEditDlg::AddGridItem(COLLECTION_INFO i_AddItemInfo, int i_nRow)
{
	// 칼럼 만들기
	int m_nCols = 0;

	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = i_nRow;
	Item.nFormat = GRID_CELL_FORMAT;

	Item.col = m_nCols++;
	Item.strText.Format("%d", i_AddItemInfo.ShapeNum);
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	char ShapeName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(i_AddItemInfo.ShapeNum, ShapeName);
	Item.strText.Format("%s", ShapeName);
	m_GridCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%d", i_AddItemInfo.EnchantLevel);
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	int day, hour, minute, second = 0;
	second = i_AddItemInfo.RemainSeconds%60;
	minute = (i_AddItemInfo.RemainSeconds/60)%60;
	hour = ((i_AddItemInfo.RemainSeconds/60)/60)%24;
	day = ((i_AddItemInfo.RemainSeconds/60)/60)/24;
	Item.strText.Format("%02dday %02d:%02d:%02d", day, hour, minute, second);
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	char OptionItemName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(i_AddItemInfo.nOptionItemNum, OptionItemName);
	Item.strText.Format("%s", OptionItemName);
	m_GridCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%d", i_AddItemInfo.nOptionItemNum);
	m_GridCollectionList.SetItem(&Item);

	Item.col = m_nCols++;
	if ( 0 == i_AddItemInfo.nOptionItemNum)
	{
		i_AddItemInfo.DurationTime.Reset();
	}
	Item.strText.Format("%s", i_AddItemInfo.DurationTime.GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
	m_GridCollectionList.SetItem(&Item);
}

// NM_RCLICK
void CArmorCollectionEditDlg::OnGridRClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
	UpdateData();
	
    NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	
	if (pItem->iRow == 0)
	{
		return;
	}
	
	m_GridCollectionList.SetFocusCell(-1,-1);
	m_GridCollectionList.SetSelectedRange(pItem->iRow, 0, pItem->iRow, m_GridCollectionList.GetColumnCount()-1, TRUE, TRUE);
	m_GridCollectionList.SetFocusCell(pItem->iRow, pItem->iColumn);

	// show context menu
	CMenu muTemp, *pContextMenu;
	muTemp.LoadMenu(IDR_CONTEXT_MENU_GRID_ITEM);
	CPoint point;
	GetCursorPos(&point);
	
	pContextMenu = muTemp.GetSubMenu(0);
	pContextMenu->EnableMenuItem(ID_CMG_INSERT_ITEM, FALSE);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}

// NM_CLICK
void CArmorCollectionEditDlg::OnGridClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
    NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	
	if (pItem->iRow != 0)
	{
		return;
	}
	
	m_GridCollectionList.SetCompareFunction(CGridCtrl::pfnCellTextCompare);
	
    if (pItem->iColumn == m_GridCollectionList.GetSortColumn())
        m_GridCollectionList.SortItems(pItem->iColumn, !m_GridCollectionList.GetSortAscending());
    else
        m_GridCollectionList.SortItems(pItem->iColumn, TRUE);
	
	m_GridCollectionList.AutoSize();
	m_GridCollectionList.ExpandColumnsToFit();
}

void CArmorCollectionEditDlg::OnCmgInsertItem()
{
	CArmorCollectionAddDlg dlg(m_UserCollectionList, m_pODBCStmt, m_pCUserAdminDlg, this);
	dlg.DoModal();
// 	if (IDOK != dlg.DoModal())
// 	{
// 		return;
// 	}
	LoadUserArmorCollectionList();
}

void CArmorCollectionEditDlg::OnCmgModifyItem()
{
	CCellID cellID = m_GridCollectionList.GetFocusCell();
	if(0 > cellID.row)
	{// 2005-12-12 by cmkwon, 선택 오류
		return;
	}
	ItemNum_t nSelectShapeNum = atoi(m_GridCollectionList.GetItemText(cellID.row, 0));
	
	COLLECTION_LIST::iterator itrSelect = m_UserCollectionList.begin();
	for ( ; itrSelect != m_UserCollectionList.end() ; itrSelect++ )
	{
		if ( itrSelect->ShapeNum == nSelectShapeNum )
		{
			CArmorCollectionModifyDlg dlg(&*itrSelect, m_pODBCStmt, m_pCUserAdminDlg, this);
			dlg.DoModal();
// 			if (IDOK != dlg.DoModal())
// 			{
// 				return;
// 			}
		}
	}
	LoadUserArmorCollectionList();
}

void CArmorCollectionEditDlg::OnCmgDeleteItem()
{
	if (IDYES != AfxMessageBox(STRERR_S_SCADMINTOOL_0029, MB_YESNO))
	{
		return;
	}

	CCellID cellID = m_GridCollectionList.GetFocusCell();
	if(0 > cellID.row)
	{// 2005-12-12 by cmkwon, 선택 오류
		return;
	}
	ItemNum_t nSelectShapeNum = atoi(m_GridCollectionList.GetItemText(cellID.row, 0));
	BOOL Ret = FALSE;
	COLLECTION_LIST::iterator itrSelect = m_UserCollectionList.begin();
	for ( ; itrSelect != m_UserCollectionList.end() ; itrSelect++ )
	{
		if ( itrSelect->ShapeNum == nSelectShapeNum )
		{
			Ret = DeleteArmorCollectionInfo(&*itrSelect);
			break;
		}
	}

	LoadUserArmorCollectionList();
	if ( TRUE == Ret )
	{
		MessageBox("Delete Success!");
	}
	else
	{
		MessageBox("Delete Fail!");
	}
}

BOOL CArmorCollectionEditDlg::DeleteArmorCollectionInfo(COLLECTION_INFO *i_pDeleteTarget)
{
	i_pDeleteTarget->EnchantLevel = SHAPE_STAT_INIT_LEVEL;

	SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->CollectionType, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->AccountUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->CharacterUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->ShapeNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->ShapeItemNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &i_pDeleteTarget->EnchantLevel, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 7, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->RemainSeconds, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 8, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &i_pDeleteTarget->nOptionItemNum, 0, NULL);
	char tmpTimeString[SIZE_MAX_SQL_DATETIME_STRING] = {0,};
	if ( 0 != i_pDeleteTarget->DurationTime.Year || 0 != i_pDeleteTarget->DurationTime.Month || 0 != i_pDeleteTarget->DurationTime.Day )
	{
		i_pDeleteTarget->DurationTime.GetSQLDateTimeString(tmpTimeString, SIZE_MAX_SQL_DATETIME_STRING);
	}
	SQLBindParameter(m_pODBCStmt->m_hstmt, 9, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmpTimeString, 0,	NULL);
	
    SQLRETURN	ret = SQLExecDirect(m_pODBCStmt->m_hstmt, PROCEDURE_130531_0002, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO )
	{
//		ProcessLogMessagesField(SQL_HANDLE_STMT, m_pODBCStmt->m_hstmt,"QP_CollectionArmorUpdate Failed!\n", TRUE, q.pFieldIOCPSocket, q);
		SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);
		return FALSE;
	}
	SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);
	return TRUE;
}

void CArmorCollectionEditDlg::LoadUserArmorCollectionList()
{
	InitGridItem();
	m_UserCollectionList.clear();

	int nType = COLLECTION_TYPE_ARMOR;
	
	SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &nType, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &m_nAccountUID, 0, NULL);
	
    SQLRETURN	ret = SQLExecDirect(m_pODBCStmt->m_hstmt, PROCEDURE_130531_0001, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO )
	{
//		ProcessLogMessagesField(SQL_HANDLE_STMT, m_pODBCStmt,"QP_CollectionArmorListLoad Failed!\n", TRUE, q.pFieldIOCPSocket, q);
		SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);
		return;
	}
	
	SQLINTEGER		arrCB[10] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS, SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS};
	
	if( SQL_NO_DATA != ret )
	{
		int forloofindex = 1;
		COLLECTION_INFO tmpCollectionInfo;
		
		SQLBindCol(m_pODBCStmt->m_hstmt, 1, SQL_C_SLONG, &tmpCollectionInfo.CollectionType	, 0,&arrCB[1]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 2, SQL_C_SLONG, &tmpCollectionInfo.AccountUID		, 0,&arrCB[2]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 3, SQL_C_SLONG, &tmpCollectionInfo.CharacterUID	, 0,&arrCB[3]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 4, SQL_C_SLONG, &tmpCollectionInfo.ShapeNum		, 0,&arrCB[4]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 5, SQL_C_SLONG, &tmpCollectionInfo.ShapeItemNum	, 0,&arrCB[5]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 6, SQL_C_UTINYINT, &tmpCollectionInfo.EnchantLevel, 0,&arrCB[6]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 7, SQL_C_SLONG, &tmpCollectionInfo.RemainSeconds	, 0,&arrCB[7]);
		// 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경
		SQL_TIMESTAMP_STRUCT   tmDurationTime;
		MEMSET_ZERO(&tmDurationTime, sizeof(SQL_TIMESTAMP_STRUCT));
		SQLBindCol(m_pODBCStmt->m_hstmt, 8, SQL_C_SLONG, &tmpCollectionInfo.nOptionItemNum	, 0,&arrCB[8]);
		SQLBindCol(m_pODBCStmt->m_hstmt, 9, SQL_C_TIMESTAMP, &tmDurationTime				, 0,&arrCB[9]);
		// end 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경
		
		while( (ret = SQLFetch(m_pODBCStmt->m_hstmt)) != SQL_NO_DATA )
		{
			if( ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO )
			{
//				ProcessLogMessagesField(SQL_HANDLE_STMT, m_pODBCStmt->m_hstmt,"atum_GetCollectionList Fetching Failed!\n", TRUE, q.pFieldIOCPSocket, q);
				break;
			}
			tmpCollectionInfo.DurationTime = tmDurationTime;
			m_UserCollectionList.push_back(tmpCollectionInfo);
			m_GridCollectionList.SetRowCount(forloofindex+1);
			AddGridItem(tmpCollectionInfo, forloofindex);
			MEMSET_ZERO(&tmDurationTime, sizeof(SQL_TIMESTAMP_STRUCT));
			forloofindex++;
		}
	}
	SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);

	m_GridCollectionList.AutoSize();
	m_GridCollectionList.ExpandColumnsToFit();
	UpdateData(FALSE);
}
