// cashshopmanagementdlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\atumadmintool.h"
#include "AtumAdminToolDlg.h"			// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 
#include "WPShopManagementDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWPShopManagementDlg dialog

CWPShopManagementDlg::CWPShopManagementDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWPShopManagementDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCashShopManagementDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pMainDlg = (CAtumAdminToolDlg*)AfxGetMainWnd();	
}

CWPShopManagementDlg::~CWPShopManagementDlg()
{
	
}

void CWPShopManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCashShopManagementDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_WPSHOP_LIST, m_GridWPShopList);
}


BEGIN_MESSAGE_MAP(CWPShopManagementDlg, CDialog)
	//{{AFX_MSG_MAP(CCashShopManagementDlg)
	ON_BN_CLICKED(ID_UPDATE_TO_DB, OnBtnUpdateToDb)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CLICK, IDC_GRID_WPSHOP_LIST, OnGridCurItem)	
END_MESSAGE_MAP()

WP_SHOP_ITEM *CWPShopManagementDlg::FindShopItem(int i_ItemNum)
{
	vectWP_SHOP_ITEM::iterator itr(m_vectWPShopItemList.begin());
	for(; itr != m_vectWPShopItemList.end(); itr++)
	{
		WP_SHOP_ITEM *pShopItem = &*itr;
		if(i_ItemNum == pShopItem->ItemNum)
		{
			return pShopItem;
		}
	}	
	return NULL;
}

void CWPShopManagementDlg::OnGridCurItem(NMHDR *pNotifyStruct, LRESULT* pResult)
{	
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	if(0 > pItem->iRow)
	{
		return;
	}

	if( 4 == pItem->iColumn)
	{
		CGridCellBase *pItemNumGCell = m_GridWPShopList.GetCell(pItem->iRow, 1 );
		WP_SHOP_ITEM *pSelShopItem = FindShopItem(atoi(pItemNumGCell->GetText()));
		if(NULL == pSelShopItem)
		{
			AfxMessageBox("error !!");
			return;
		}

		CString csMsg;
		csMsg.Format(" %s ItemNum(%s) ?", (pSelShopItem->IsShowItem)?("Removed from the list"):("Added to the list"), pItemNumGCell->GetText());

		int nRet = AfxMessageBox(csMsg, MB_OKCANCEL);
		if(IDCANCEL == nRet)
		{
			return;
		}

		pSelShopItem->IsShowItem = !(pSelShopItem->IsShowItem);

		int nCurScrollPos = m_GridWPShopList.GetScrollPos32(SB_VERT);
		
		this->InitGridCurItem8GridChangedItem();
		this->ViewGrid(&m_GridWPShopList);
				
		m_GridWPShopList.SetScrollPos32(SB_VERT, nCurScrollPos);
		return;
	}
	return;
}

void CWPShopManagementDlg::_InitGrid(CGridCtrl *i_pGridCtrl)
{
		i_pGridCtrl->SetBkColor(0xFFFFFF);
		
		int nRows = 1;
		int nCols = 5;
		
		i_pGridCtrl->SetEditable(FALSE);		 
		i_pGridCtrl->SetListMode(TRUE);
		i_pGridCtrl->SetSingleRowSelection(TRUE);
		i_pGridCtrl->EnableSelection(TRUE);
		i_pGridCtrl->SetFrameFocusCell(FALSE);
		i_pGridCtrl->SetTrackFocusCell(FALSE);
		
		i_pGridCtrl->SetRowCount(nRows);
		i_pGridCtrl->SetColumnCount(nCols);
		i_pGridCtrl->SetFixedRowCount(1);
		
		// 칼럼 만들기
		nCols			= 0;
		GV_ITEM Item;
		Item.mask		= GVIF_TEXT|GVIF_FORMAT;
		Item.row		= 0;
		Item.nFormat	= GRID_CELL_FORMAT;
		
		Item.col		= nCols++;
		Item.strText.Format("NUM");
		i_pGridCtrl->SetItem(&Item);
		
		Item.col = 1;	// itemnum 
		Item.strText.Format("ItemNum");
		i_pGridCtrl->SetItem(&Item);
		
		Item.col = 2;	// itemname
		Item.strText.Format("ItemName");
		i_pGridCtrl->SetItem(&Item);
		
		Item.col = 3;	// price 
		Item.strText.Format("Price");
		i_pGridCtrl->SetItem(&Item);
		
		Item.col = 4;
		Item.strText.Format("IsShowItem");
		i_pGridCtrl->SetItem(&Item);		
		
		// arrange grid
		i_pGridCtrl->AutoSize();
		i_pGridCtrl->ExpandColumnsToFit();
		
		// clean all cells
		CCellRange tmpCellRange(1, 0, i_pGridCtrl->GetRowCount()-1, i_pGridCtrl->GetColumnCount()-1);
		i_pGridCtrl->ClearCells(tmpCellRange);
}


BOOL CWPShopManagementDlg::DBQueryLoadWPShopList(vectWP_SHOP_ITEM *o_pVectWPShopItemList)
{
	SQLHSTMT hstmt = m_odbcStmt2.GetSTMTHandle();
	BOOL bRet = m_odbcStmt2.ExecuteQuery(PROCEDURE_140714_0001);
	if (!bRet)
	{
		m_odbcStmt2.FreeStatement();		// cleanup		
		AfxMessageBox("DBQueryLoadWPShopList error !!");
		return FALSE;
	}	
	SQLINTEGER arrCB[5]={SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS};
	WP_SHOP_ITEM tmWPShopItem;
	INT tempIsShow;
	SQLBindCol(hstmt,  1, SQL_C_LONG, &tmWPShopItem.ItemNum, 0,							&arrCB[1]);	
	SQLBindCol(hstmt,  2, SQL_C_LONG, &tmWPShopItem.Price, 0,							&arrCB[2]);
	SQLBindCol(hstmt,  3, SQL_C_LONG, &tempIsShow, 0,									&arrCB[3]);
	
	do
	{
		MEMSET_ZERO(&tmWPShopItem, sizeof(tmWPShopItem));
		tempIsShow = 0;
		
		SQLRETURN ret = SQLFetch(hstmt);
		if(SQL_SUCCESS != ret && SQL_SUCCESS_WITH_INFO != ret)
		{
			break;
		}
		
		ITEM *pItemInfo = m_mapItemInfo.findEZ_ptr(tmWPShopItem.ItemNum);
		if(pItemInfo)
		{// 2006-03-27 by cmkwon, 아이템 이름 현지화 처리
			STRNCPY_MEMSET(tmWPShopItem.ItemName, pItemInfo->ItemName, SIZE_MAX_ITEM_NAME);
		}

		if( 0 == tempIsShow )
		{
			tmWPShopItem.IsShowItem = TRUE;
		}

		o_pVectWPShopItemList->push_back(tmWPShopItem);
	}while(TRUE);
	
	m_odbcStmt2.FreeStatement();		// cleanup
	return TRUE;
}

void CWPShopManagementDlg::InitGridCurItem8GridChangedItem(void)
{
	m_ilCheckImageList.DeleteImageList();
	m_ilCheckImageList.Create(24, 12, ILC_COLOR, 1, 1);

	CBitmap bmCheckImage;
	bmCheckImage.LoadBitmap(IDB_BITMAP1);
	m_ilCheckImageList.Add(&bmCheckImage, RGB(0,0,0));
	
	m_GridWPShopList.SetImageList(&m_ilCheckImageList);
	this->_InitGrid(&m_GridWPShopList);
}

 void CWPShopManagementDlg::_AddCashItem(CGridCtrl *i_pGridCtrl, WP_SHOP_ITEM *i_pShopItem)
 {
 	GV_ITEM Item;
 
 	Item.mask		= GVIF_TEXT|GVIF_FORMAT;
 	Item.nFormat	= DT_LEFT|DT_VCENTER|DT_SINGLELINE;
 	
 	int nNewRowIdx = i_pGridCtrl->GetRowCount();
 	i_pGridCtrl->SetRowCount(nNewRowIdx+1);
 	
 	//select된 값을 GridDetail GridCtrl에 넣어준다.
 	Item.row		= nNewRowIdx;
 	Item.col		= 0;
 	Item.strText.Format("%d", nNewRowIdx);
 	i_pGridCtrl->SetItem(&Item);
 	
 	Item.col		= 1;
 	Item.strText.Format("%d", i_pShopItem->ItemNum);
 	i_pGridCtrl->SetItem(&Item);
 	
 	Item.col		= 2;
 	Item.strText.Format("%s", i_pShopItem->ItemName);
 	i_pGridCtrl->SetItem(&Item);

	Item.col		= 3;
	Item.strText.Format("%d", i_pShopItem->Price);
 	i_pGridCtrl->SetItem(&Item);
 	
	Item.nFormat	= DT_CENTER|DT_BOTTOM|DT_SINGLELINE;
 	Item.mask		= GVIF_FORMAT|GVIF_IMAGE;
 	Item.col		= 4;
 	Item.iImage		= i_pShopItem->IsShowItem;
 	i_pGridCtrl->SetItem(&Item);
}

void CWPShopManagementDlg::ViewGrid(CGridCtrl *i_pGridCtrl)
{
	vectWP_SHOP_ITEM::iterator itr(m_vectWPShopItemList.begin());
	for(; itr != m_vectWPShopItemList.end(); itr++)
	{
		WP_SHOP_ITEM *pShopItem = &*itr;
		_AddCashItem(i_pGridCtrl, pShopItem);
	}
	i_pGridCtrl->UpdateData();
	i_pGridCtrl->AutoSize();
}

BOOL CWPShopManagementDlg::DBQueryUpdateWPShopList(vectWP_SHOP_ITEM *i_pVectItemList)
{
	SQLHSTMT hstmt = m_odbcStmt2.GetSTMTHandle();
	
	BOOL bRet = m_odbcStmt2.ExecuteQuery(PROCEDURE_140714_0002);		// 기존 데이터 삭제 
	if (!bRet)
	{
		m_odbcStmt2.FreeStatement();		// cleanup		
		AfxMessageBox("DBQueryUpdateWPShopList Delete error !!");
		return FALSE;
	}

	vectWP_SHOP_ITEM::iterator itr(i_pVectItemList->begin());
	for (; itr != i_pVectItemList->end(); itr++)
	{
		WP_SHOP_ITEM *pShopItem = &*itr;		
		if ( NULL != pShopItem && FALSE == pShopItem->IsShowItem) 
		{
			SQLINTEGER arrCB[2]={SQL_NTS,SQL_NTS};
			SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &pShopItem->ItemNum, 0,	&arrCB[1]);		
			BOOL bRet = m_odbcStmt2.ExecuteQuery(PROCEDURE_140714_0003);
			if (!bRet)
			{
				m_odbcStmt2.FreeStatement();		// cleanup		
				AfxMessageBox("DBQueryUpdateWPShopList insert error !!");
				return FALSE;
			}			
		}		
		m_odbcStmt2.FreeStatement();			// cleanup				
	}
	return TRUE;
}

BOOL CWPShopManagementDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	// Connect DB
	if ( FALSE == m_odbcStmt2.Init(m_pMainDlg->m_pServerInfo4Admin->DBIP, m_pMainDlg->m_pServerInfo4Admin->DBPort, m_pMainDlg->m_pServerInfo4Admin->DBName,
		m_pMainDlg->m_pServerInfo4Admin->DBUID, m_pMainDlg->m_pServerInfo4Admin->DBPWD, GetSafeHwnd()) )
	{
		char szTemp[1024];
		sprintf(szTemp, "Can not connect DBServer<%s(%s:%d)> !!"
			, m_pMainDlg->m_pServerInfo4Admin->DBName, m_pMainDlg->m_pServerInfo4Admin->DBIP
			, m_pMainDlg->m_pServerInfo4Admin->DBPort);
		MessageBox(szTemp);
		EndDialog(-1);
		return FALSE;
	}
	
	CAtumDBHelper::LoadItemInfo(&m_odbcStmt2, &m_mapItemInfo, &(m_pMainDlg->m_Localization));
	
	m_vectWPShopItemList.clear();
	this->DBQueryLoadWPShopList(&m_vectWPShopItemList);
	this->InitGridCurItem8GridChangedItem();	
	this->ViewGrid(&m_GridWPShopList);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWPShopManagementDlg::OnBtnUpdateToDb() 
{
	AfxMessageBox("Apply when the server restarts. !!");

	this->DBQueryUpdateWPShopList(&m_vectWPShopItemList);

	m_vectWPShopItemList.clear();
	this->DBQueryLoadWPShopList(&m_vectWPShopItemList);
	this->InitGridCurItem8GridChangedItem();
	this->ViewGrid(&m_GridWPShopList);
	
	AfxMessageBox("Been successfully applied to the database.!! (Applies to restart the server)");	
}

