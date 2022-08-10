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

#include "SCMonthlyArmorEventDlg.h"		// 2013-04-18 by jhseol,bckim 이달의 아머


#include "AdminAutoNoticeDlg.h"			// 2009-01-14 by cmkwon, 운영자 자동 공지 시스템 구현 - 

#include "RenewalStrategyPointAdminDlg.h"	// 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전 툴 추가
#include "AtumAdminToolButtonDlg.h" // 2013-09-11 by jekim, 어드민 툴 해상도 수정
#define WM_ICON_NOTIFY		WM_USER+20

/////////////////////////////////////////////////////////////////////////////
// CAtumAdminToolDlg dialog
class CAtumAdminToolButtonDlg; // 2013-09-11 by jekim, 어드민 툴 해상도 수정
class CExpViewerDlg;
class CSCGuildAdminDlg;
class CXORTestDlg;			// 2007-10-24 by cmkwon, 서버 정보 암호화 - 
class CPetitionManagementDlg;		// 2007-11-19 by cmkwon, 진정시스템 업데이트 - 
class CEventMonsterManagementDlg;	// 2008-04-16 by cmkwon, 몬스터 사망 시 몬스터 소환 이벤트 시스템 구현 - 
class CCashShopManagementDlg;		// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 
class CWRankingManagement;			// 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 

class SCMonthlyArmorEventDlg;		// 2013-04-18 by jhseol,bckim 이달의 아머
	  
// start 2012-02-27 by jhseol, 화폐통계툴 기능 추가
class CStaisticsMoneyDlg;
// end 2012-02-27 by jhseol, 화폐통계툴 기능 추가

// 2014-07-14 by bckim, 워포샵 리스트 컨트롤
class CWPShopManagementDlg;
// End. 2014-07-14 by bckim, 워포샵 리스트 컨트롤

class CArenaCharSend; // 2012-06-16 by jhseol, 아레나 추가개발part2 - 전달 : 퀴리만들기
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

	void EnableToolControls ( USHORT usAccountType );		// 계정 타입별 메뉴 권한 부여.

	void SetLanguageString(int i_nLanguageType);

	BOOL IsManagerAdministrator(void);

	// 2007-11-19 by cmkwon, 진정시스템 업데이트 - 
	BOOL SendMsgToPreServer(BYTE *i_pbyData, int i_nDataLen);
	BOOL SendMsgTypeToPreServer(MessageType_t i_nMsgTy);

	void ExchangeAccountDBName(CString *szTmpQuery);			// 2013-04-30 by bckim. 베트남 운영툴관련 처리 	
	// 2013-09-11 by jekim, 어드민 툴 해상도 수정
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
	// 2014-07-14 by bckim, 워포샵 리스트 컨트롤
	void OnBtnWPshopManagement();
	// End. 2014-07-14 by bckim, 워포샵 리스트 컨트롤
	void OnBtnWrankingManagement();
	void OnBtnInfinity();
	void OnBtnStatisticsMoney();
	void OnButtonMonthlyArmorEvent();
	// end 2013-09-11 by jekim, 어드민 툴 해상도 수정
public :	// Inline Process.

	inline USHORT GetManagerAccountType ( void ) { return m_usManagerAccountType; };

public:
	// dialogs
	CAtumAdminToolButtonDlg     *m_pButtonDlg; // 2013-09-11 by jekim, 어드민 툴 해상도 수정
	CSCUserAdminDlg				*m_pUserAdminDlg;
	CSCServerAdminDlg			*m_pServerAdminDlg;
	CSCBadUserAdminDlg			*m_pBadUserAdminDlg;
	CSCLogAdminDlg				*m_pLogAdminDlg;
	CSCHappyHourEventAdminDlg	*m_pHappyHourEventAdminDlg;
	CExpViewerDlg				*m_pExpViewer;					// 2005-08-08 by cmkwon
	CSCGuildAdminDlg			*m_pGuildAdminDlg;				// 2006-03-07 by cmkwon
	CSCItemEventDlg				*m_pItemEventDlg;				// 2006-08-29 by dhjin
	CSCStrategyPointAdminDlg	*m_pStrategyPointDlg;			// 2007-03-05 by dhjin
	CXORTestDlg					*m_pXOREncodeDlg;				// 2007-10-24 by cmkwon, 서버 정보 암호화
	CPetitionManagementDlg		*m_pPetitionDlg;				// 2007-11-19 by cmkwon, 진정시스템 업데이트 - 
	CSCOutPostDlg				*m_pOutPostDlg;					// 2008-01-28 by dhjin, OutPst
	CEventMonsterManagementDlg	*m_pEventMonsterDlg;			// 2008-04-16 by cmkwon, 몬스터 사망 시 몬스터 소환 이벤트 시스템 구현 - 
	// start 2012-02-27 by jhseol, 화폐통계툴 기능 추가
	CStaisticsMoneyDlg			*m_pStatisticsMoneyDlg;
	// end 2012-02-27 by jhseol, 화폐통계툴 기능 추가

	CArenaCharSend				*m_pCArenaCharSendDlg;	// 2012-06-16 by jhseol, 아레나 추가개발part2 - 전달 : 퀴리만들기

	CRenewalStrategyPointAdminDlg	*m_pRenewalStrategyPointDlg;	// 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼 - 거점전 툴 추가

	SCMonthlyArmorEventDlg			*m_pSCMonthlyArmorEventDlg;		// 2013-04-18 by jhseol,bckim 이달의 아머
	
	// 2009-01-14 by cmkwon, 운영자 자동 공지 시스템 구현 - Admin Auto Notice Management
	CAdminAutoNoticeDlg*		m_pAdminAutoNoticeDlg;

	// 2009-01-28 by cmkwon, 캐쉬샾 수정(추천탭,신상품 추가) - 
	CCashShopManagementDlg *	m_pCashShopManagementDlg;	

	// 2014-07-14 by bckim, 워포샵 리스트 컨트롤
	CWPShopManagementDlg *		m_pWPShopManagementDlg;	
	// End. 2014-07-14 by bckim, 워포샵 리스트 컨트롤

	// 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
	CWRankingManagement *		m_pWRankingManagementDlg;	
	BOOL IsConnectedToPreServer(void);

	// data
	GAME_SERVER_INFO_FOR_ADMIN	*m_pServerInfo4Admin;
	CSCAdminPreWinSocket		*m_pAdminPreSocket;

	CString						m_szServerName;
	
	// 현지화 관련
	CLocalization				m_Localization;
	CString						m_strLocalizationDirectoryPath;
	INT							m_nLanguageType;

	// 2006-04-15 by cmkwon
	char						m_szManagerAccountName[SIZE_MAX_ACCOUNT_NAME];	// 2006-04-15 by cmkwon, SCAdminTool 접속자 계정
	USHORT						m_usManagerAccountType;							// 2006-04-15 by cmkwon, 접속자 계정 권한

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
