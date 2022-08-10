// #if !defined(AFX_CASHSHOPMANAGEMENTDLG_H__33066C39_CBB9_40F3_9121_533CE72FA6FA__INCLUDED_)
// #define AFX_CASHSHOPMANAGEMENTDLG_H__33066C39_CBB9_40F3_9121_533CE72FA6FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cashshopmanagementdlg.h : header file
//
#include "SCGridHelper.h"		// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 
#include "ODBCStatement.h"		// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 

struct WP_SHOP_ITEM
{
	INT		ItemNum;
	char	ItemName[SIZE_MAX_ITEM_NAME];
	INT		Price;
	BOOL	IsShowItem;
};
typedef vector<WP_SHOP_ITEM>		vectWP_SHOP_ITEM;

/////////////////////////////////////////////////////////////////////////////
// CCashShopManagementDlg dialog
class CAtumAdminToolDlg;			// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 
class CWPShopManagementDlg : public CDialog
{
// Construction
public:
	CWPShopManagementDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWPShopManagementDlg();

// Dialog Data
	//{{AFX_DATA(CCashShopManagementDlg)
	enum { IDD = IDD_DLG_WP_SHOP_MANAGEMENT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCashShopManagementDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	afx_msg void OnGridCurItem(NMHDR *pNotifyStruct, LRESULT* pResult);

// Implementation
	void _InitGrid(CGridCtrl *i_pGridCtrl);
	void InitGridCurItem8GridChangedItem(void);

	void _AddCashItem(CGridCtrl *i_pGridCtrl, WP_SHOP_ITEM *i_pShopItem);
	void ViewGrid(CGridCtrl *i_pGridCtrl);
	BOOL DBQueryLoadWPShopList(vectWP_SHOP_ITEM *o_pVectItemList);
	BOOL DBQueryUpdateWPShopList(vectWP_SHOP_ITEM *i_pVectItemList);
	WP_SHOP_ITEM * FindShopItem(int i_ItemNum);

protected:

	CGridCtrl				m_GridWPShopList;		
	CImageList				m_ilCheckImageList;		
	vectWP_SHOP_ITEM		m_vectWPShopItemList;		

	CODBCStatement			m_odbcStmt2;
	CAtumAdminToolDlg *		m_pMainDlg;
	ez_map<INT, ITEM>		m_mapItemInfo;

	// Generated message map functions
	//{{AFX_MSG(CCashShopManagementDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnUpdateToDb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

//#endif // !defined(AFX_CASHSHOPMANAGEMENTDLG_H__33066C39_CBB9_40F3_9121_533CE72FA6FA__INCLUDED_)
