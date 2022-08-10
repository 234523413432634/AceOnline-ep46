// AtumAdminToolDlg.h : header file
//

#if !defined(AFX_ATUMADMINTOOLDLG_H__FEBE4557_6076_4041_AB75_004F385A2854__INCLUDED_)
#define AFX_ATUMADMINTOOLDLG_H__FEBE4557_6076_4041_AB75_004F385A2854__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SCUserAdminDlg.h"
#include "SCServerAdminDlg.h"
#include "SCBadUserAdminDlg.h"
#include "SCLogAdminDlg.h"
#include "TrayIcon.h"
#include "Localization.h"
#include "SCHappyHourEventAdminDlg.h"
#include "SCItemEventDlg.h"
#include "SCStrategyPointAdminDlg.h"
#include "SCOutPostDlg.h"

#include "SCMonthlyArmorEventDlg.h"		// 2013-04-18 by jhseol,bckim �̴��� �Ƹ�


#include "AdminAutoNoticeDlg.h"			// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - 

#include "RenewalStrategyPointAdminDlg.h"	// 2012-11-13 by jhseol, ���� �ý��� ������ - ������ �� �߰�
#include "AtumAdminToolButtonDlg.h" // 2013-09-11 by jekim, ���� �� �ػ� ����
#define WM_ICON_NOTIFY		WM_USER+20

/////////////////////////////////////////////////////////////////////////////
// CAtumAdminToolDlg dialog
class CAtumAdminToolButtonDlg; // 2013-09-11 by jekim, ���� �� �ػ� ����
class CExpViewerDlg;
class CSCGuildAdminDlg;
class CXORTestDlg;			// 2007-10-24 by cmkwon, ���� ���� ��ȣȭ - 
class CPetitionManagementDlg;		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
class CEventMonsterManagementDlg;	// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
class CCashShopManagementDlg;		// 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - 
class CWRankingManagement;			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 

class SCMonthlyArmorEventDlg;		// 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
	  
// start 2012-02-27 by jhseol, ȭ������� ��� �߰�
class CStaisticsMoneyDlg;
// end 2012-02-27 by jhseol, ȭ������� ��� �߰�

// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
class CWPShopManagementDlg;
// End. 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��

class CArenaCharSend; // 2012-06-16 by jhseol, �Ʒ��� �߰�����part2 - ���� : ���������
class CAtumAdminToolDlg : public CDialog
{
// Construction
public:
	CAtumAdminToolDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CAtumAdminToolDlg();

//	CTrayIcon		m_TrayIcon;	

// Dialog Data
	//{{AFX_DATA(CAtumAdminToolDlg)
	enum { IDD = IDD_DIALOG_ATUM_ADMIN_TOOL };
	CComboBox	m_ComboSelectServer;
	CString	m_UID;
	CString	m_PWD;
	CString	m_ctl_strLanguageString;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAtumAdminToolDlg)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL ConnectServer();

	void EnableToolControls(BOOL i_bEnable);

	void EnableToolControls ( USHORT usAccountType );		// ���� Ÿ�Ժ� �޴� ���� �ο�.

	void SetLanguageString(int i_nLanguageType);

	BOOL IsManagerAdministrator(void);

	// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
	BOOL SendMsgToPreServer(BYTE *i_pbyData, int i_nDataLen);
	BOOL SendMsgTypeToPreServer(MessageType_t i_nMsgTy);

	void ExchangeAccountDBName(CString *szTmpQuery);			// 2013-04-30 by bckim. ��Ʈ�� ������� ó�� 	
	// 2013-09-11 by jekim, ���� �� �ػ� ����
	void OnButtonUserTool();
	void OnButtonServerTool();
	void OnButtonLogTool();
	void OnButtonBadUserTool();
	void OnButtonScreenShotViewer();
	void OnButtonHappyHourEventTool();
	void OnBtnExpViewer();
	void OnBtnGuildTool();
	void OnButtonItemEvent();
	void OnButtonStrategypoint();
	void OnBtnXorEncode();
	void OnButtonOutpost();
	void OnBtnPetitionSytem();
	void OnButtonEventMonster();
	void OnButtonAutoNotice();
	void OnBtnCashshopManagement();
	// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	void OnBtnWPshopManagement();
	// End. 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	void OnBtnWrankingManagement();
	void OnBtnInfinity();
	void OnBtnStatisticsMoney();
	void OnButtonMonthlyArmorEvent();
	// end 2013-09-11 by jekim, ���� �� �ػ� ����
public :	// Inline Process.

	inline USHORT GetManagerAccountType ( void ) { return m_usManagerAccountType; };

public:
	// dialogs
	CAtumAdminToolButtonDlg     *m_pButtonDlg; // 2013-09-11 by jekim, ���� �� �ػ� ����
	CSCUserAdminDlg				*m_pUserAdminDlg;
	CSCServerAdminDlg			*m_pServerAdminDlg;
	CSCBadUserAdminDlg			*m_pBadUserAdminDlg;
	CSCLogAdminDlg				*m_pLogAdminDlg;
	CSCHappyHourEventAdminDlg	*m_pHappyHourEventAdminDlg;
	CExpViewerDlg				*m_pExpViewer;					// 2005-08-08 by cmkwon
	CSCGuildAdminDlg			*m_pGuildAdminDlg;				// 2006-03-07 by cmkwon
	CSCItemEventDlg				*m_pItemEventDlg;				// 2006-08-29 by dhjin
	CSCStrategyPointAdminDlg	*m_pStrategyPointDlg;			// 2007-03-05 by dhjin
	CXORTestDlg					*m_pXOREncodeDlg;				// 2007-10-24 by cmkwon, ���� ���� ��ȣȭ
	CPetitionManagementDlg		*m_pPetitionDlg;				// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
	CSCOutPostDlg				*m_pOutPostDlg;					// 2008-01-28 by dhjin, OutPst
	CEventMonsterManagementDlg	*m_pEventMonsterDlg;			// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
	// start 2012-02-27 by jhseol, ȭ������� ��� �߰�
	CStaisticsMoneyDlg			*m_pStatisticsMoneyDlg;
	// end 2012-02-27 by jhseol, ȭ������� ��� �߰�

	CArenaCharSend				*m_pCArenaCharSendDlg;	// 2012-06-16 by jhseol, �Ʒ��� �߰�����part2 - ���� : ���������

	CRenewalStrategyPointAdminDlg	*m_pRenewalStrategyPointDlg;	// 2012-11-13 by jhseol, ���� �ý��� ������ - ������ �� �߰�

	SCMonthlyArmorEventDlg			*m_pSCMonthlyArmorEventDlg;		// 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
	
	// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - Admin Auto Notice Management
	CAdminAutoNoticeDlg*		m_pAdminAutoNoticeDlg;

	// 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - 
	CCashShopManagementDlg *	m_pCashShopManagementDlg;	

	// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	CWPShopManagementDlg *		m_pWPShopManagementDlg;	
	// End. 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��

	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	CWRankingManagement *		m_pWRankingManagementDlg;	
	BOOL IsConnectedToPreServer(void);

	// data
	GAME_SERVER_INFO_FOR_ADMIN	*m_pServerInfo4Admin;
	CSCAdminPreWinSocket		*m_pAdminPreSocket;

	CString						m_szServerName;
	
	// ����ȭ ����
	CLocalization				m_Localization;
	CString						m_strLocalizationDirectoryPath;
	INT							m_nLanguageType;

	// 2006-04-15 by cmkwon
	char						m_szManagerAccountName[SIZE_MAX_ACCOUNT_NAME];	// 2006-04-15 by cmkwon, SCAdminTool ������ ����
	USHORT						m_usManagerAccountType;							// 2006-04-15 by cmkwon, ������ ���� ����

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAtumAdminToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonDisconnect();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuTrayExit();
	afx_msg void OnMenuTrayOpen();
	virtual void OnCancel();
	afx_msg void OnDestroy();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnBtnArenaCharSend();
	afx_msg void OnBtnLocalization();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	afx_msg LONG OnSocketNotifyPre(WPARAM wParam, LPARAM lParam);
	afx_msg LONG OnAsyncSocketMessage(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnTrayNotification(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATUMADMINTOOLDLG_H__FEBE4557_6076_4041_AB75_004F385A2854__INCLUDED_)
