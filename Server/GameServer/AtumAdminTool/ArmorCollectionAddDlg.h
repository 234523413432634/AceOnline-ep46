#if !defined(AFX_ARMORCOLLECTIONADDDLG_H__A6CA67E8_B351_4C01_A777_3BE3D59E90BC__INCLUDED_)
#define AFX_ARMORCOLLECTIONADDDLG_H__A6CA67E8_B351_4C01_A777_3BE3D59E90BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ArmorCollectionAddDlg.h : header file
//

#include "ODBCStatement.h"

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionAddDlg dialog

class CArmorCollectionAddDlg : public CDialog
{
// Construction
public:
	CArmorCollectionAddDlg(COLLECTION_LIST i_Info, CODBCStatement *i_pODBC, CSCUserAdminDlg* i_pMainDlg, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CArmorCollectionAddDlg)
	enum { IDD = IDD_DLG_ARMOR_COLLECTION_ADD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArmorCollectionAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	void InitGridItem();
	void AddGridItem(ITEM *i_pAddItemInfo, int i_nRow);

	COLLECTION_LIST m_HaveCollectionList;
	CODBCStatement *m_pODBCStmt;
	
// Implementation
protected:
	CSCUserAdminDlg		*m_pCUserAdminDlg;
	vectItemPtr m_VectShapeItemList;
	CGridCtrl			m_GridAddCollectionList;

	// Generated message map functions
	//{{AFX_MSG(CArmorCollectionAddDlg)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARMORCOLLECTIONADDDLG_H__A6CA67E8_B351_4C01_A777_3BE3D59E90BC__INCLUDED_)
