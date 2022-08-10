#if !defined(AFX_ATUMADMINTOOLBUTTONDLG_H__FC4FD91E_88A3_470E_97F3_F1FEE3FD5863__INCLUDED_)
#define AFX_ATUMADMINTOOLBUTTONDLG_H__FC4FD91E_88A3_470E_97F3_F1FEE3FD5863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AtumAdminToolButtonDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAtumAdminToolButtonDlg dialog
class CAtumAdminToolDlg;
class CAtumAdminToolButtonDlg : public CDialog
{
	friend CAtumAdminToolDlg;
// Construction
public:
	CAtumAdminToolButtonDlg(CWnd* pParent = NULL);   // standard constructor
	CAtumAdminToolDlg *m_pParent;
	CRect	m_rcOriginalRect;
	
	// dragging
	BOOL	m_bDragging;
	CPoint	m_ptDragPoint;
	
	// actual scroll position
	int		m_nScrollPos;
	
	// actual dialog height
	int		m_nCurHeight;
	void EndDrag();
	void EnableToolControls(BOOL i_bEnable);
	void EnableToolControls ( USHORT usAccountType );
	BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) ;
// Dialog Data
	//{{AFX_DATA(CAtumAdminToolButtonDlg)
	enum { IDD = IDD_DIALOG_ATUM_ADMIN_TOOL_BUTTON };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAtumAdminToolButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);		// 2013-10-11 by jekim, 어드민툴 ESC 수정.
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAtumAdminToolButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnBtnCashshopManagement();
	// 2014-07-14 by bckim, 워포샵 리스트 컨트롤
	afx_msg void OnBtnWPshopManagement();
	// End. 2014-07-14 by bckim, 워포샵 리스트 컨트롤
	afx_msg void OnBtnExpViewer();
	afx_msg void OnBtnGuildTool();
	afx_msg void OnBtnInfinity();
	afx_msg void OnBtnPetitionSytem();
	afx_msg void OnBtnStatisticsMoney();
	afx_msg void OnBtnWrankingManagement();
	afx_msg void OnBtnXorEncode();
	afx_msg void OnButtonAutoNotice();
	afx_msg void OnButtonEventMonster();
	afx_msg void OnButtonHappyHourEventTool();
	afx_msg void OnButtonItemEvent();
	afx_msg void OnButtonLogTool();
	afx_msg void OnButtonMonthlyArmorEvent();
	afx_msg void OnButtonOutpost();
	afx_msg void OnButtonScreenShotViewer();
	afx_msg void OnButtonServer();
	afx_msg void OnButtonStrategypoint();
	afx_msg void OnButtonUserTool();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATUMADMINTOOLBUTTONDLG_H__FC4FD91E_88A3_470E_97F3_F1FEE3FD5863__INCLUDED_)
