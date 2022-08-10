#if !defined(AFX_COMBATPOWERDETAIL_H__6289C4B6_9795_4402_8664_1493E576AFA0__INCLUDED_)
#define AFX_COMBATPOWERDETAIL_H__6289C4B6_9795_4402_8664_1493E576AFA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CombatPowerDetail.h : header file
//
#include "LogTabCombatPower.h"
/////////////////////////////////////////////////////////////////////////////
// CCombatPowerDetail dialog

class CCombatPowerDetail : public CDialog
{
// Construction
public:
	CCombatPowerDetail(std::vector<CCombatPower> *ani,std::vector<CCombatPower> *bcu,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCombatPowerDetail)
	enum { IDD = IDD_DIALOG_COMBATPOWER_DETAIL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombatPowerDetail)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	std::vector<CCombatPower> m_ani;
	std::vector<CCombatPower> m_bcu;
	CSCGridCtrl		m_GridANI;
	CSCGridCtrl		m_GridBCU;

	void InitGrid(void);


	// Generated message map functions
	//{{AFX_MSG(CCombatPowerDetail)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBATPOWERDETAIL_H__6289C4B6_9795_4402_8664_1493E576AFA0__INCLUDED_)
