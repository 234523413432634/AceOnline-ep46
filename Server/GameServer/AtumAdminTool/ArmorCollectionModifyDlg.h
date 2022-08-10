#if !defined(AFX_ARMORCOLLECTIONMODIFYDLG_H__34EFD2E8_9AB9_4AA5_B569_D0D6CCBA88FB__INCLUDED_)
#define AFX_ARMORCOLLECTIONMODIFYDLG_H__34EFD2E8_9AB9_4AA5_B569_D0D6CCBA88FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ArmorCollectionModifyDlg.h : header file
//

#include "ODBCStatement.h"

/////////////////////////////////////////////////////////////////////////////
// CArmorCollectionModifyDlg dialog

class CArmorCollectionModifyDlg : public CDialog
{
// Construction
public:
	CArmorCollectionModifyDlg(COLLECTION_INFO* i_pInfo, CODBCStatement *i_pODBC, CSCUserAdminDlg* i_pMainDlg, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CArmorCollectionModifyDlg)
	enum { IDD = IDD_DLG_ARMOR_COLLECTION_MODIFY };
	CComboBox	m_ComboOptionList;
	int		m_nShapeNum;
	int		m_nShapeLevel;
	CString	m_strShapeName;
	CString	m_strRemainTime;
	int		m_nRemainSeconds;
	CString	m_strOptionName;
	CTime	m_timeOptionDate;
	CTime	m_timeOptionTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArmorCollectionModifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	BOOL UpdateArmorCollectionInfo();

	COLLECTION_INFO m_ModifyInfo;
	CODBCStatement *m_pODBCStmt;

// Implementation
protected:
	CSCUserAdminDlg		*m_pCUserAdminDlg;
	vectItemPtr m_VectOptionItemList;

	// Generated message map functions
	//{{AFX_MSG(CArmorCollectionModifyDlg)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeCmdlgEditRemainTimeInput();
	afx_msg void OnChangeCmdlgEditShapeLevel();
	afx_msg void OnApply();
	afx_msg void OnSelchangeCmdlgComboOption();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARMORCOLLECTIONMODIFYDLG_H__34EFD2E8_9AB9_4AA5_B569_D0D6CCBA88FB__INCLUDED_)
