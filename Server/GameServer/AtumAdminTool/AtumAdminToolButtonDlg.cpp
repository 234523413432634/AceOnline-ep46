// AtumAdminToolButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AtumAdminToolDlg.h"
#include "AtumProtocol.h"
#include "AtumError.h"
#include "atumadmintool.h"
#include "AtumAdminToolButtonDlg.h"
#include "AtumAdminToolDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAtumAdminToolButtonDlg dialog


CAtumAdminToolButtonDlg::CAtumAdminToolButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAtumAdminToolButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAtumAdminToolButtonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pParent = (CAtumAdminToolDlg*)pParent;
	m_bDragging=FALSE;
	Create(CAtumAdminToolButtonDlg::IDD,pParent);
}


void CAtumAdminToolButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAtumAdminToolButtonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAtumAdminToolButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CAtumAdminToolButtonDlg)
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KILLFOCUS()
	ON_BN_CLICKED(IDC_BTN_CASHSHOP_MANAGEMENT, OnBtnCashshopManagement)
	// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	ON_BN_CLICKED(IDC_BTN_WPSHOP_MANAGEMENT, OnBtnWPshopManagement)
	// End. 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	ON_BN_CLICKED(IDC_BTN_EXP_VIEWER, OnBtnExpViewer)
	ON_BN_CLICKED(IDC_BTN_GUILD_TOOL, OnBtnGuildTool)
	ON_BN_CLICKED(IDC_BTN_INFINITY, OnBtnInfinity)
	ON_BN_CLICKED(IDC_BTN_PETITION_SYTEM, OnBtnPetitionSytem)
	ON_BN_CLICKED(IDC_BTN_STATISTICS_MONEY, OnBtnStatisticsMoney)
	ON_BN_CLICKED(IDC_BTN_WRANKING_MANAGEMENT, OnBtnWrankingManagement)
	ON_BN_CLICKED(IDC_BTN_XOR_ENCODE, OnBtnXorEncode)
	ON_BN_CLICKED(IDC_BUTTON_AUTO_NOTICE, OnButtonAutoNotice)
	ON_BN_CLICKED(IDC_BUTTON_EVENT_MONSTER, OnButtonEventMonster)
	ON_BN_CLICKED(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL, OnButtonHappyHourEventTool)
	ON_BN_CLICKED(IDC_BUTTON_ITEM_EVENT, OnButtonItemEvent)
	ON_BN_CLICKED(IDC_BUTTON_LOG_TOOL, OnButtonLogTool)
	ON_BN_CLICKED(IDC_BUTTON_MONTHLY_ARMOR_EVENT, OnButtonMonthlyArmorEvent)
	ON_BN_CLICKED(IDC_BUTTON_OUTPOST, OnButtonOutpost)
	ON_BN_CLICKED(IDC_BUTTON_SCREEN_SHOT_VIEWER, OnButtonScreenShotViewer)
	ON_BN_CLICKED(IDC_BUTTON_SERVER, OnButtonServer)
	ON_BN_CLICKED(IDC_BUTTON_STRATEGYPOINT, OnButtonStrategypoint)
	ON_BN_CLICKED(IDC_BUTTON_USER_TOOL, OnButtonUserTool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAtumAdminToolButtonDlg message handlers

BOOL CAtumAdminToolButtonDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	GetWindowRect(m_rcOriginalRect);
	m_nScrollPos = 0;


#ifdef _ATUM_ONLY_SERVER_ADMIN_TOOL
	GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow(FALSE);
	// 2005-10-11 by cmkwon, �α� �˻����� �����ϵ��� ����
	//	GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON_SCREEN_SHOT_VIEWER)->EnableWindow(FALSE);	
	GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_ITEM_EVENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_STRATEGYPOINT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_OUTPOST)->EnableWindow(FALSE);
	
	// 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
	GetDlgItem(IDC_BUTTON_MONTHLY_ARMOR_EVENT)->EnableWindow(FALSE);
	// End. 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
	
#endif// _ATUM_ONLY_SERVER_ADMIN_TOOL_end_ifdef


	return TRUE;
}
void CAtumAdminToolButtonDlg::EnableToolControls ( USHORT usAccountType )
{
	switch ( usAccountType )
	{
	case RACE_MONITOR :
		
		GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow( TRUE );
		GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow( FALSE );
		GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow( FALSE );
		GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow( FALSE );
		GetDlgItem(IDC_BUTTON_ITEM_EVENT)->EnableWindow( FALSE );
		GetDlgItem(IDC_BTN_PETITION_SYTEM)->EnableWindow( FALSE );		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
		GetDlgItem(IDC_BUTTON_STRATEGYPOINT)->EnableWindow( FALSE );
		GetDlgItem(IDC_BUTTON_OUTPOST)->EnableWindow( FALSE );
		GetDlgItem(IDC_BUTTON_EVENT_MONSTER)->EnableWindow( FALSE );		// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
		GetDlgItem(IDC_BUTTON_AUTO_NOTICE)->EnableWindow( FALSE );		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - Admin Auto Notice Management
		GetDlgItem(IDC_BTN_CASHSHOP_MANAGEMENT)->EnableWindow( FALSE );	// 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - 
		GetDlgItem(IDC_BTN_WPSHOP_MANAGEMENT)->EnableWindow( FALSE );	// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
		GetDlgItem(IDC_BTN_WRANKING_MANAGEMENT)->EnableWindow( FALSE );	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
		GetDlgItem(IDC_BUTTON_SERVER)->EnableWindow( FALSE );
		// start 2012-02-27 by jhseol, ȭ������� ��� �߰�
		GetDlgItem(IDC_BTN_STATISTICS_MONEY)->EnableWindow(FALSE);
		// end 2012-02-27 by jhseol, ȭ������� ��� �߰�
		break;
		
	default :
		break;
	}
	
	
}
void CAtumAdminToolButtonDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int nDelta;
	int nMaxPos = m_rcOriginalRect.Height() - m_nCurHeight;
	
	switch (nSBCode)
	{
	case SB_LINEDOWN:
		if (m_nScrollPos >= nMaxPos)
			return;
		
		nDelta = min(max(nMaxPos/20,5),nMaxPos-m_nScrollPos);
		break;
		
	case SB_LINEUP:
		if (m_nScrollPos <= 0)
			return;
		nDelta = -min(max(nMaxPos/20,5),m_nScrollPos);
		break;
	case SB_PAGEDOWN:
		if (m_nScrollPos >= nMaxPos)
			return;
		nDelta = min(max(nMaxPos/10,5),nMaxPos-m_nScrollPos);
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		nDelta = (int)nPos - m_nScrollPos;
		break;
		
	case SB_PAGEUP:
		if (m_nScrollPos <= 0)
			return;
		nDelta = -min(max(nMaxPos/10,5),m_nScrollPos);
		break;
		
	default:
		return;
	}
	m_nScrollPos += nDelta;
	SetScrollPos(SB_VERT,m_nScrollPos,TRUE);
	ScrollWindow(0,-nDelta);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CAtumAdminToolButtonDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	int temp=m_nScrollPos;
	m_nCurHeight = cy;
	m_nScrollPos = 0;
	
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_ALL; 
	si.nMin = 0;
	si.nMax = m_rcOriginalRect.Height();
	si.nPage = cy;
	si.nPos = 0;
    SetScrollInfo(SB_VERT, &si, TRUE); 		
	ScrollWindow(0,temp);
	SetScrollPos(SB_VERT,m_nScrollPos,TRUE);
}

BOOL CAtumAdminToolButtonDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	int nMaxPos = m_rcOriginalRect.Height() - m_nCurHeight;
	
	if (zDelta<0)
	{
		if (m_nScrollPos < nMaxPos)
		{
			zDelta=20;
			m_nScrollPos += zDelta;
			SetScrollPos(SB_VERT,m_nScrollPos,TRUE);
			ScrollWindow(0,-zDelta);
		}
	}
	else
	{
		if (m_nScrollPos > 0)
		{
			zDelta=-20;
			m_nScrollPos += zDelta;
			SetScrollPos(SB_VERT,m_nScrollPos,TRUE);
			ScrollWindow(0,-zDelta);
		}
	}
	return TRUE;
}

void CAtumAdminToolButtonDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//m_bDragging=TRUE;
	//SetCapture();
	//m_ptDragPoint=point;
	CDialog::OnLButtonDown(nFlags, point);
}

void CAtumAdminToolButtonDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	EndDrag();
	CDialog::OnLButtonUp(nFlags, point);
}

void CAtumAdminToolButtonDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bDragging)
	{
		int nDelta=m_ptDragPoint.y-point.y;
		m_ptDragPoint=point;
		
		int nNewPos=m_nScrollPos+nDelta;
		
		if (nNewPos<0)
			nNewPos=0;
		else if (nNewPos>m_rcOriginalRect.Height() - m_nCurHeight)
			nNewPos=m_rcOriginalRect.Height() - m_nCurHeight;
		
		nDelta=nNewPos-m_nScrollPos;
		m_nScrollPos=nNewPos;
		
		SetScrollPos(SB_VERT,m_nScrollPos,TRUE);
		ScrollWindow(0,-nDelta);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CAtumAdminToolButtonDlg::OnKillFocus(CWnd* pNewWnd) 
{
	CDialog::OnKillFocus(pNewWnd);
	EndDrag();	
}
void CAtumAdminToolButtonDlg::EndDrag()
{
	m_bDragging=FALSE;
	ReleaseCapture();
}
void CAtumAdminToolButtonDlg::EnableToolControls(BOOL i_bEnable)
{
	// 2007-07-06 by cmkwon, �߱��� ��ڴ� ServerAdmin�� ���� ���� - �Ʒ��� ���� ������
	//	GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
	//#ifndef _ATUM_ONLY_SERVER_ADMIN_TOOL
	//	GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow(i_bEnable);
	//// 2005-10-11 by cmkwon, �α� �˻����� �����ϵ��� ����
	////	GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_COMBO_SERVER)->EnableWindow(!i_bEnable);
	//#endif// _ATUM_ONLY_SERVER_ADMIN_TOOL_end_ifndef
	
	// 2007-11-21 by cmkwon, �߱��� ������ ������ GM ������ �����ϰ� ó���Ѵ�. - 
	//#if defined(_CHN_S1)		// 2007-07-06 by cmkwon, �߱��� ��ڴ� ServerAdmin�� ���� ����
	//	GetDlgItem(IDC_COMBO_SERVER)->EnableWindow(!i_bEnable);
	//	if(FALSE == i_bEnable
	//		|| this->IsManagerAdministrator())
	//	{
	//		GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow(i_bEnable);
	//		GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
	//		GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow(i_bEnable);
	//		GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow(i_bEnable);
	//		GetDlgItem(IDC_BUTTON_ITEM_EVENT)->EnableWindow(i_bEnable);
	//		GetDlgItem(IDC_BUTTON_STRATEGYPOINT)->EnableWindow(i_bEnable);
	//	}
	//#elif !defined(_ATUM_ONLY_SERVER_ADMIN_TOOL)
	//	GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_COMBO_SERVER)->EnableWindow(!i_bEnable);
	//	GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_BUTTON_ITEM_EVENT)->EnableWindow(i_bEnable);
	//	GetDlgItem(IDC_BUTTON_STRATEGYPOINT)->EnableWindow(i_bEnable);
	//#endif// _ATUM_ONLY_SERVER_ADMIN_TOOL_end_ifndef
#if !defined(_ATUM_ONLY_SERVER_ADMIN_TOOL)	
	GetDlgItem(IDC_BUTTON_USER_TOOL)->EnableWindow(i_bEnable);
	// 2012-01-07 by khkim, ��Ʈ�� GM ���Ѽ���
#ifdef S_MANAGER_ADMIN_HSSON
	if(RACE_GAMEMASTER == m_pParent->m_usManagerAccountType) // 2013-10-16 by jekim, ��Ʈ�� �� ���� ���� ����.
	{
		GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
		GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow(i_bEnable);
	}
#endif
	// end 2012-01-07 by khkim, ��Ʈ�� GM ���Ѽ���
	GetDlgItem(IDC_BUTTON_LOG_TOOL)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BUTTON_HAPPY_HOUR_EVENT_TOOL)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BTN_GUILD_TOOL)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BUTTON_ITEM_EVENT)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BUTTON_STRATEGYPOINT)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BTN_PETITION_SYTEM)->EnableWindow(i_bEnable);		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - 
	GetDlgItem(IDC_BUTTON_OUTPOST)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BUTTON_EVENT_MONSTER)->EnableWindow(i_bEnable);		// 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - 
	GetDlgItem(IDC_BUTTON_AUTO_NOTICE)->EnableWindow(i_bEnable);		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - Admin Auto Notice Management
	GetDlgItem(IDC_BTN_CASHSHOP_MANAGEMENT)->EnableWindow(i_bEnable);	// 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - 
	GetDlgItem(IDC_BTN_WPSHOP_MANAGEMENT)->EnableWindow(i_bEnable);		// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
	GetDlgItem(IDC_BTN_WRANKING_MANAGEMENT)->EnableWindow(i_bEnable);	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	// start 2012-02-27 by jhseol, ȭ������� ��� �߰�
	GetDlgItem(IDC_BTN_STATISTICS_MONEY)->EnableWindow(i_bEnable);
	GetDlgItem(IDC_BUTTON_SERVER)->EnableWindow(i_bEnable);
	// end 2012-02-27 by jhseol, ȭ������� ��� �߰�
	
	// 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
#ifdef S_MONTHL_ARMOR_EVENT_JHSEOL_BCKIM		// �̺�Ʈ ���ε�
	GetDlgItem(IDC_BUTTON_MONTHLY_ARMOR_EVENT)->EnableWindow(i_bEnable);
#else
	GetDlgItem(IDC_BUTTON_MONTHLY_ARMOR_EVENT)->EnableWindow(FALSE);
#endif
	// End. 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
	
#endif // END - #if !defined(_ATUM_ONLY_SERVER_ADMIN_TOOL)	
	
}
//OnButtonBadUserTool
void CAtumAdminToolButtonDlg::OnBtnCashshopManagement() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnCashshopManagement();
}

// 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��
void CAtumAdminToolButtonDlg::OnBtnWPshopManagement() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnWPshopManagement();
}
// End. 2014-07-14 by bckim, ������ ����Ʈ ��Ʈ��



void CAtumAdminToolButtonDlg::OnBtnExpViewer() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnExpViewer();
}

void CAtumAdminToolButtonDlg::OnBtnGuildTool() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnGuildTool();
}

void CAtumAdminToolButtonDlg::OnBtnInfinity() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnInfinity();
}

void CAtumAdminToolButtonDlg::OnBtnPetitionSytem() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnPetitionSytem();
}

void CAtumAdminToolButtonDlg::OnBtnStatisticsMoney() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnStatisticsMoney();
}

void CAtumAdminToolButtonDlg::OnBtnWrankingManagement() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnWrankingManagement();
}

void CAtumAdminToolButtonDlg::OnBtnXorEncode() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnBtnXorEncode();
}

void CAtumAdminToolButtonDlg::OnButtonAutoNotice() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonAutoNotice();
	
}

void CAtumAdminToolButtonDlg::OnButtonEventMonster() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonEventMonster();
	
}

void CAtumAdminToolButtonDlg::OnButtonHappyHourEventTool() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonHappyHourEventTool();
	
}

void CAtumAdminToolButtonDlg::OnButtonItemEvent() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonItemEvent();
}

void CAtumAdminToolButtonDlg::OnButtonLogTool() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonLogTool();
}

void CAtumAdminToolButtonDlg::OnButtonMonthlyArmorEvent() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonMonthlyArmorEvent();
}

void CAtumAdminToolButtonDlg::OnButtonOutpost() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonOutpost();
}

void CAtumAdminToolButtonDlg::OnButtonScreenShotViewer() 
{
	// TODO: Add your control notification handler code here
	m_pParent->OnButtonScreenShotViewer();
}

void CAtumAdminToolButtonDlg::OnButtonServer() 
{
	m_pParent->OnButtonServerTool();
}

void CAtumAdminToolButtonDlg::OnButtonStrategypoint() 
{
	m_pParent->OnButtonStrategypoint();
}

void CAtumAdminToolButtonDlg::OnButtonUserTool() 
{
	m_pParent->OnButtonUserTool();
}
// 2013-10-11 by jekim, ������ ESC ����.
BOOL CAtumAdminToolButtonDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}
// end 2013-10-11 by jekim, ������ ESC ����.
