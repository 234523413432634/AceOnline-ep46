// ArmorCollectionAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "SCUserAdminDlg.h"
#include "ArmorCollectionAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionAddDlg dialog


CArmorCollectionAddDlg::CArmorCollectionAddDlg(COLLECTION_LIST i_Info, CODBCStatement *i_pODBC, CSCUserAdminDlg* i_pMainDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CArmorCollectionAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CArmorCollectionAddDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_HaveCollectionList.assign(i_Info.begin(), i_Info.end());
	m_pODBCStmt	= i_pODBC;
	m_pCUserAdminDlg		= i_pMainDlg;
}


void CArmorCollectionAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArmorCollectionAddDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_GridControl(pDX, IDC_GRID_COLLECTION_ADD_LIST, m_GridAddCollectionList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArmorCollectionAddDlg, CDialog)
	//{{AFX_MSG_MAP(CArmorCollectionAddDlg)
	ON_BN_CLICKED(IDOK, OnAdd)
	ON_NOTIFY(NM_CLICK, IDC_GRID_COLLECTION_ADD_LIST, OnGridClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionAddDlg message handlers
BOOL CArmorCollectionAddDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
        // 여기에 엔터키 기능 작성
		OnAdd();
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

BOOL CArmorCollectionAddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	//	// Set the icon for this dialog.  The framework does this automatically
	//	//  when the application's main window is not a dialog
	//	SetIcon(m_hIcon, TRUE);			// Set big icon
	//	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	InitGridItem();
	m_VectShapeItemList.clear();
	m_pCUserAdminDlg->GetItemInfoListByDesParam(&m_VectShapeItemList, DES_COLLECTION_ARMOR_INDEX);
	int forloofindex = 1;
	vectItemPtr::iterator itr = m_VectShapeItemList.begin();
	for ( ; itr != m_VectShapeItemList.end() ; itr++ )
	{
		BOOL isHaveCollection = FALSE;
		COLLECTION_LIST::iterator itrHaveList = m_HaveCollectionList.begin();
		for ( ; itrHaveList != m_HaveCollectionList.end() ; itrHaveList++ )
		{
			if ( (*itr)->LinkItem == itrHaveList->ShapeNum )
			{
				isHaveCollection = TRUE;
			}
		}
		if ( FALSE == isHaveCollection )
		{
			m_GridAddCollectionList.SetRowCount(forloofindex+1);
			AddGridItem((*itr), forloofindex);
			forloofindex++;
		}
	}
	m_GridAddCollectionList.AutoSize();
	m_GridAddCollectionList.ExpandColumnsToFit();
	UpdateData(FALSE);



//	DES_COLLECTION_ARMOR_INDEX


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CArmorCollectionAddDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CCellID cellID = m_GridAddCollectionList.GetFocusCell();
	if(0 > cellID.row)
	{// 2005-12-12 by cmkwon, 선택 오류
		MessageBox("Add Item Select Error!");
		return;
	}
	ITEM *pItemInfo = m_pCUserAdminDlg->GetItemByItemNum(atoi(m_GridAddCollectionList.GetItemText(cellID.row, 1)));
	if ( NULL == pItemInfo )
	{
		MessageBox("Add Item Find Error!");
		return;
	}

	COLLECTION_INFO tmAddCollection;
	tmAddCollection.CollectionType	= COLLECTION_TYPE_ARMOR;
	tmAddCollection.AccountUID		= m_pCUserAdminDlg->GetAccountUID();
	tmAddCollection.CharacterUID	= 0;
	tmAddCollection.ShapeNum		= pItemInfo->LinkItem;
	tmAddCollection.ShapeItemNum	= pItemInfo->ItemNum;
	tmAddCollection.EnchantLevel	= pItemInfo->SkillLevel;
	tmAddCollection.RemainSeconds	= (UINT)(pItemInfo->GetParameterValue(DES_FIXED_TERM_SHAPE_TIME)*60);
	tmAddCollection.EndTime.Reset();
	tmAddCollection.nOptionItemNum	= 0;
	tmAddCollection.DurationTime.Reset();

	SQLBindParameter(m_pODBCStmt->m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.CollectionType, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.AccountUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.CharacterUID, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.ShapeNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.ShapeItemNum, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &tmAddCollection.EnchantLevel, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 7, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.RemainSeconds, 0, NULL);
	SQLBindParameter(m_pODBCStmt->m_hstmt, 8, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &tmAddCollection.nOptionItemNum, 0, NULL);
	char tmpTimeString[SIZE_MAX_SQL_DATETIME_STRING] = {0,};
	if ( 0 != tmAddCollection.DurationTime.Year || 0 != tmAddCollection.DurationTime.Month || 0 != tmAddCollection.DurationTime.Day )
	{
		tmAddCollection.DurationTime.GetSQLDateTimeString(tmpTimeString, SIZE_MAX_SQL_DATETIME_STRING);
	}
	SQLBindParameter(m_pODBCStmt->m_hstmt, 9, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, SIZE_MAX_SQL_DATETIME_STRING, 0, tmpTimeString, 0,	NULL);
	
    SQLRETURN	ret = SQLExecDirect(m_pODBCStmt->m_hstmt, PROCEDURE_130531_0002, SQL_NTS);
	
	if ( ret!=SQL_SUCCESS && ret!=SQL_SUCCESS_WITH_INFO )
	{
//		ProcessLogMessagesField(SQL_HANDLE_STMT, m_pODBCStmt->m_hstmt,"QP_CollectionArmorUpdate Failed!\n", TRUE, q.pFieldIOCPSocket, q);
		SQLFreeStmt(m_pODBCStmt->m_hstmt, SQL_CLOSE);
		MessageBox("Add Fail!");
		return;
	}
	MessageBox("Add Success.");
	m_GridAddCollectionList.DeleteRow(cellID.row);
	m_GridAddCollectionList.AutoSize();
	m_GridAddCollectionList.ExpandColumnsToFit();
	UpdateData(FALSE);
//	CDialog::OnCancel();
	return;
}

void CArmorCollectionAddDlg::InitGridItem()
{
	m_GridAddCollectionList.SetBkColor(0xFFFFFF);
	
	int m_nRows = 1;
	int m_nCols = 4;
	int m_nFixRows = 1;
	
	m_GridAddCollectionList.SetEditable(FALSE);
	m_GridAddCollectionList.SetListMode(TRUE);
	m_GridAddCollectionList.SetSingleRowSelection(TRUE);	// 오직 1게의 라인만 선택 가능하게 하는 옵션
	m_GridAddCollectionList.EnableSelection(TRUE);
	m_GridAddCollectionList.SetHeaderSort(FALSE);
	m_GridAddCollectionList.SetFrameFocusCell(FALSE);
	m_GridAddCollectionList.SetTrackFocusCell(FALSE);
	
	m_GridAddCollectionList.SetRowCount(m_nRows);
	m_GridAddCollectionList.SetColumnCount(m_nCols);
	m_GridAddCollectionList.SetFixedRowCount(m_nFixRows);
	
	// 칼럼 만들기
	m_nCols = 0;
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = 0;
	Item.nFormat = GRID_CELL_FORMAT;
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("ShapeNum"));
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("ShapeItemNum"));
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("ShapeName"));
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format(_T("GearType"));
	m_GridAddCollectionList.SetItem(&Item);
	
	m_GridAddCollectionList.AutoSize();
	m_GridAddCollectionList.ExpandColumnsToFit();
	
	// clean all cells
	CCellRange tmpCellRange(1, 0, m_GridAddCollectionList.GetRowCount()-1, m_GridAddCollectionList.GetColumnCount()-1);
	m_GridAddCollectionList.ClearCells(tmpCellRange);
}

void CArmorCollectionAddDlg::AddGridItem(ITEM *i_pAddItemInfo, int i_nRow)
{
	// 칼럼 만들기
	int m_nCols = 0;
	
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = i_nRow;
	Item.nFormat = GRID_CELL_FORMAT;
	
	Item.col = m_nCols++;
	Item.strText.Format("%d", i_pAddItemInfo->LinkItem);
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	Item.strText.Format("%d", i_pAddItemInfo->ItemNum);
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	char ShapeName[SIZE_MAX_ITEM_NAME] = {0,};
	m_pCUserAdminDlg->GetItemNameByItemNum(i_pAddItemInfo->LinkItem, ShapeName);
	Item.strText.Format("%s", ShapeName);
	m_GridAddCollectionList.SetItem(&Item);
	
	Item.col = m_nCols++;
	ITEM *pItemInfo = m_pCUserAdminDlg->GetItemByItemNum(i_pAddItemInfo->LinkItem);
	if ( NULL != pItemInfo )
	{
		if ( TRUE == IS_BGEAR(pItemInfo->ReqUnitKind) )
		{
			Item.strText.Format("B-Gear");
		}
		else if ( TRUE == IS_MGEAR(pItemInfo->ReqUnitKind) )
		{
			Item.strText.Format("M-Gear");
		}
		else if ( TRUE == IS_AGEAR(pItemInfo->ReqUnitKind) )
		{
			Item.strText.Format("A-Gear");
		}
		else if ( TRUE == IS_IGEAR(pItemInfo->ReqUnitKind) )
		{
			Item.strText.Format("I-Gear");
		}
		m_GridAddCollectionList.SetItem(&Item);

	}
}

// NM_CLICK
void CArmorCollectionAddDlg::OnGridClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
    NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	
	if (pItem->iRow != 0)
	{
		return;
	}
	
	m_GridAddCollectionList.SetCompareFunction(CGridCtrl::pfnCellTextCompare);
	
    if (pItem->iColumn == m_GridAddCollectionList.GetSortColumn())
        m_GridAddCollectionList.SortItems(pItem->iColumn, !m_GridAddCollectionList.GetSortAscending());
    else
        m_GridAddCollectionList.SortItems(pItem->iColumn, TRUE);
	
	m_GridAddCollectionList.AutoSize();
	m_GridAddCollectionList.ExpandColumnsToFit();
}
