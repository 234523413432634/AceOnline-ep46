#if !defined(AFX_LOGTABCOMBATPOWER_H__AE0E31F1_1042_45DB_AD93_25236FD8DD76__INCLUDED_)
#define AFX_LOGTABCOMBATPOWER_H__AE0E31F1_1042_45DB_AD93_25236FD8DD76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogTabCombatPower.h : header file
//
#include "SCGridHelper.h"
#include "ODBCStatement.h"
#include "AtumProtocol.h"

#include "AtumAdminToolDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CLogTabCombatPower dialog
class CCombatPower;

class CLogTabCombatPower : public CDialog
{
// Construction
public:
	CLogTabCombatPower(CDialog *i_pMainDlg, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogTabCombatPower)
	enum { IDD = IDD_LOG_TAB_COMBATPOWER };
	CDateTimeCtrl	m_StartDate;
	CDateTimeCtrl	m_EndDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogTabCombatPower)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	void OnGridRClick(NMHDR *pNotifyStruct, LRESULT* pResult);
// Implementation
public:
	CSCLogAdminDlg	*m_pMainDlg;
	CODBCStatement	*m_pODBCStmt;
	CSCGridCtrl		m_GridCombatPowerLog;
	std::vector<CCombatPower> m_powers;
	std::vector<CCombatPower> m_gridItems;
	void InitGrid(void);
	void ResetVariables(void);
	void InsertGridRow(CCombatPower & cp);
	void GetDayBuff(CCombatPower & cp,std::vector<CCombatPower> * o_ani,std::vector<CCombatPower> * o_bcu);

protected:

	// Generated message map functions
	//{{AFX_MSG(CLogTabCombatPower)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnBtnSaveResult();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
class CCombatPower {
public:
	SQL_DATE_STRUCT date;
	int diff;
	int ANI;
	int BCU;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGTABCOMBATPOWER_H__AE0E31F1_1042_45DB_AD93_25236FD8DD76__INCLUDED_)
