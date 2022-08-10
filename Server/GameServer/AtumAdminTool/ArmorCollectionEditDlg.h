#if !defined(AFX_ARMORCOLLECTIONEDITDLG_H__D2F731F3_49EB_4CAD_8802_4DC5EEEF1112__INCLUDED_)
#define AFX_ARMORCOLLECTIONEDITDLG_H__D2F731F3_49EB_4CAD_8802_4DC5EEEF1112__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ArmorCollectionEditDlg.h : header file
//

#include "GridCtrl/GridCtrl.h"
#include "ODBCStatement.h"

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionEditDlg dialog

class CArmorCollectionEditDlg : public CDialog
{
// Construction
public:
	CArmorCollectionEditDlg(UID32_t i_u32AccUID, CODBCStatement *i_pODBC, CSCUserAdminDlg* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CArmorCollectionEditDlg)
	enum { IDD = IDD_DLG_ARMOR_COLLECTION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArmorCollectionEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	void LoadUserArmorCollectionList();
	void InitGridItem();
	void AddGridItem(COLLECTION_INFO i_AddItemInfo, int i_nRow);
	BOOL DeleteArmorCollectionInfo(COLLECTION_INFO *i_pDeleteTarget);

	UID32_t m_nAccountUID;
	CODBCStatement *m_pODBCStmt;


// Implementation
protected:
	CSCUserAdminDlg		*m_pCUserAdminDlg;
	CGridCtrl			m_GridCollectionList;
	COLLECTION_LIST		m_UserCollectionList;
	// Generated message map functions
	//{{AFX_MSG(CArmorCollectionEditDlg)
		// NOTE: the ClassWizard will add member functions here
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
    afx_msg void OnGridRClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnCmgInsertItem();
	afx_msg void OnCmgModifyItem();
	afx_msg void OnCmgDeleteItem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARMORCOLLECTIONEDITDLG_H__D2F731F3_49EB_4CAD_8802_4DC5EEEF1112__INCLUDED_)
