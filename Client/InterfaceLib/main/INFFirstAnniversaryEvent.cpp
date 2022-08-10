// INFFirstAnniversaryEvent.cpp: implementation of the CINFFirstAnniversaryEvent class.
//
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		
/// \author		// 2013-10-01 by ssjung 1주년 이벤트
/// \date		2013-09-30~ 2013-10-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "INFGameMain.h"
#include "AtumApplication.h"
#include "INFCityBase.h"
#include "INFImage.h"
#include "INFWindow.h"
#include "Interface.h"
#include "ShuttleChild.h"
#include "AtumSound.h"
#include "IExplore.h"
#include "INFFirstAnniversaryEvent.h"
// 2014-09-24 by ymjoo 2주년 감사카드
#include "D3DHanFont.h"
// END 2014-09-24 by ymjoo 2주년 감사카드

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define WEBSIZE_X 682
#define WEBSIZE_Y 265

#define WEB_POS_X 20
#define WEB_POS_Y 376 + 22

#define CLOSEBTN_POS_X 687
#define CLOSEBTN_POS_Y 316

CINFFirstAnniversaryEvent::CINFFirstAnniversaryEvent()
{
	InitWndData();

	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		m_pTextFont[i] = NULL;
	}
	m_pRandMagNum = 0;
	m_pFirstAnniversaryEventMsgStr = NULL;
	// END 2014-09-24 by ymjoo 2주년 감사카드
}

CINFFirstAnniversaryEvent::~CINFFirstAnniversaryEvent()
{
	// 2014-09-24 by ymjoo 2주년 감사카드
	SAFE_DELETE(m_pCloseBtn);
	SAFE_DELETE(m_pBlackImg);
	SAFE_DELETE(m_pCloseBtn);
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		SAFE_DELETE(m_pTextFont[i]);
	}
	SAFE_DELETE(m_pFirstAnniversaryEventMsgStr);
	// END 2014-09-24 by ymjoo 2주년 감사카드
}

HRESULT CINFFirstAnniversaryEvent::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;
	{
		char buf[16];
		memset(buf, 0x00, 16);		
		wsprintf(buf,"1card_tab");
		
		pDataHeader = FindResource(buf);		
		if(pDataHeader && (NULL == m_pBackImg))
		{
			m_pBackImg = new CINFImageEx;
			m_pBackImg->InitDeviceObjects(pDataHeader);
		}
		
		memset(buf, 0x00, 16);		
		wsprintf(buf,"LM_inven");
		pDataHeader = FindResource(buf);
		if(pDataHeader && (NULL == m_pBlackImg))
		{
			m_pBlackImg = new CINFImageEx;
			m_pBlackImg->InitDeviceObjects(pDataHeader);
		}
	}	

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];

		wsprintf(szUpBtn, "1card_x1");
		wsprintf(szDownBtn, "1card_x0");
		wsprintf(szSelBtn, "1card_x0");
		wsprintf(szDisBtn, "1card_x1");															  

		if(NULL == m_pCloseBtn)
		{
			m_pCloseBtn = new CINFImageBtn;
		}
		m_pCloseBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}	

	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		if(NULL == m_pTextFont[i])
		{
			if(i == 0)
			{
				m_pTextFont[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 14, D3DFONT_ZENABLE|D3DFONT_BOLD, FALSE, 1024, 32);
			}
			else
			{
				m_pTextFont[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 11, D3DFONT_ZENABLE|D3DFONT_BOLD, FALSE, 1024, 32);
			}
			m_pTextFont[i]->InitDeviceObjects(g_pD3dDev);
		}
	}
	if(NULL == m_pFirstAnniversaryEventMsgStr)
	{
		m_pFirstAnniversaryEventMsgStr = new CFirstAnniversaryEventMsgStr();
	}
	// END 2014-09-24 by ymjoo 2주년 감사카드
	
	return S_OK ;
}
HRESULT CINFFirstAnniversaryEvent::RestoreDeviceObjects()
{
	if(m_pCloseBtn)
		m_pCloseBtn->RestoreDeviceObjects();
	if(m_pBackImg )
		m_pBackImg->RestoreDeviceObjects();
	if(m_pBlackImg)
		m_pBlackImg->RestoreDeviceObjects();
	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		if(m_pTextFont[i])
		{
			m_pTextFont[i]->RestoreDeviceObjects();
		}
	}
	// END 2014-09-24 by ymjoo 2주년 감사카드
	return S_OK ;
}
HRESULT CINFFirstAnniversaryEvent::DeleteDeviceObjects()
{
	if(m_pCloseBtn)
	{
		m_pCloseBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pCloseBtn);
	}
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}
	if(m_pBlackImg)
	{
		m_pBlackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBlackImg);
	}
	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		if(m_pTextFont[i])
		{
			m_pTextFont[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pTextFont[i]);
		}
	}
	if(m_pFirstAnniversaryEventMsgStr)
	{
		SAFE_DELETE(m_pFirstAnniversaryEventMsgStr);
	}
	// END 2014-09-24 by ymjoo 2주년 감사카드
	return S_OK ;
}
HRESULT CINFFirstAnniversaryEvent::InvalidateDeviceObjects()
{
	if(m_pCloseBtn)
		m_pCloseBtn->InvalidateDeviceObjects();
	if(m_pBackImg )
		m_pBackImg->InvalidateDeviceObjects();
	if(m_pBlackImg)
		m_pBlackImg->InvalidateDeviceObjects();
	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		if(m_pTextFont[i])
		{
			m_pTextFont[i]->InvalidateDeviceObjects();
		}
	}
	// END 2014-09-24 by ymjoo 2주년 감사카드
	return S_OK ;
}
void	CINFFirstAnniversaryEvent::InitWndData()
{
	m_pCloseBtn	 = NULL;
	m_pBackImg	 = NULL;
	m_ptBkPos.x	 = m_ptBkPos.y = 0;
	m_bShowWnd	 = NULL;
	m_pBlackImg	 = NULL;
	m_ptWinSize.x = m_ptWinSize.y = 0;
}

void	CINFFirstAnniversaryEvent::Tick()
{

}
void	CINFFirstAnniversaryEvent::Render()
{
	if(!IsShowWnd())
	{
		return;
	}

	if(m_pBlackImg)
	{
		m_pBlackImg->Move(0,0);
		m_pBlackImg->SetAniScale(m_ptWinSize.x, m_ptWinSize.y);
		m_pBlackImg->Render();
	}

	int nWindowPosX = m_ptBkPos.x;
	int nWindowPosY = m_ptBkPos.y;
	
	{
		m_pBackImg->Move( nWindowPosX, nWindowPosY);
		m_pBackImg->Render();
	}

	if(m_pCloseBtn)
	{
		m_pCloseBtn->Render();
	}

	// 2014-09-24 by ymjoo 2주년 감사카드
	for(int i = 0 ; i < FIRST_ANNIVERSARY_EVENT_MSG_LINE ; ++i)
	{
		if(m_pTextFont[i] && m_pFirstAnniversaryEventMsgStr->firstAnniversaryEventMsgStr[m_pRandMagNum][i])
		{
			if(i == 0)
			{
				m_pTextFont[i]->DrawText(nWindowPosX + 29, 
										 nWindowPosY + 383,
										 RGB(78, 75, 69), 
										 m_pFirstAnniversaryEventMsgStr->firstAnniversaryEventMsgStr[m_pRandMagNum][i]);
			}
			else if(i == FIRST_ANNIVERSARY_EVENT_MSG_LINE - 1)
			{
				int nStrSizeX = m_pTextFont[i]->GetStringSize(m_pFirstAnniversaryEventMsgStr->firstAnniversaryEventMsgStr[m_pRandMagNum][i]).cx;
				m_pTextFont[i]->DrawText(nWindowPosX + 693 - nStrSizeX, 
										 nWindowPosY + 398 + 24 * i, 
										 RGB(78, 75, 69), 
										 m_pFirstAnniversaryEventMsgStr->firstAnniversaryEventMsgStr[m_pRandMagNum][i]);
			}
			else
			{
				m_pTextFont[i]->DrawText(nWindowPosX + 40, 
										 nWindowPosY + 398 + 24 * i, 
										 RGB(78, 75, 69), 
										 m_pFirstAnniversaryEventMsgStr->firstAnniversaryEventMsgStr[m_pRandMagNum][i]);
			}
		}
	}
	// END 2014-09-24 by ymjoo 2주년 감사카드
}	
void CINFFirstAnniversaryEvent::ShowWnd(BOOL bShow,POINT *ptMixWndPos)
{
	m_bShowWnd = bShow;
	if(bShow)
	{
		if(ptMixWndPos)
		{
			m_ptBkPos = *ptMixWndPos;
		}
		else
		{
			m_ptBkPos.x = ( g_pD3dApp->GetBackBufferDesc().Width/2) - (m_pBackImg->GetImgSize().x / 2);
			m_ptBkPos.y = ( g_pD3dApp->GetBackBufferDesc().Height/2) - (m_pBackImg->GetImgSize().y / 2);		
		}

		m_ptWinSize.x = g_pD3dApp->GetBackBufferDesc().Width;
		m_ptWinSize.y = g_pD3dApp->GetBackBufferDesc().Height;

		UpdateBtnPos();

		g_pInterface->SetWindowOrder(WNDFirstAnniversaryEvent);

		char strWebSite[256]  = {0,};
		wsprintf(strWebSite,"%s", "http://testao.masangsoft.com/index.php?mid=event_letter");		//웹 주소 

// 		CreateWebWindow(strWebSite, 20, 376, 682, 265);
// 		ShowWebWindow(m_ptBkPos.x + 20 , m_ptBkPos.y + 376 + 22, 682, 265);

		// 2014-09-24 by ymjoo 2주년 감사카드
//  		CreateWebWindow(strWebSite, WEB_POS_X, WEB_POS_Y, WEBSIZE_X+30, WEBSIZE_Y+30);				//스크롤 수정
//  		ShowWebWindow(m_ptBkPos.x + WEB_POS_X , m_ptBkPos.y + WEB_POS_Y, WEBSIZE_X, WEBSIZE_Y);
		m_pRandMagNum = rand() % FIRST_ANNIVERSARY_EVENT_MSG_NUM;
		// END 2014-09-24 by ymjoo 2주년 감사카드
	}
	else
	{
		g_pD3dApp->ChangeGameState(_GAME);
		// 2014-09-24 by ymjoo 2주년 감사카드 (주석 처리)
// 		HideWebWindow();
// 		DestroyWebWindow();
		// END 2014-09-24 by ymjoo 2주년 감사카드 (주석 처리)
	}
}
BOOL CINFFirstAnniversaryEvent::IsShowWnd()
{
	return m_bShowWnd;
}
void CINFFirstAnniversaryEvent::UpdateBtnPos()
{
	int nWindowPosX = m_ptBkPos.x;
	int nWindowPosY = m_ptBkPos.y;			
	
	{		
// 		int nPosX = nWindowPosX + 687;
// 		int nPosY = nWindowPosY + 316;	

		int nPosX = nWindowPosX + CLOSEBTN_POS_X;
		int nPosY = nWindowPosY + CLOSEBTN_POS_Y;	
		
		m_pCloseBtn->SetBtnPosition(nPosX, nPosY);
	}
}
BOOL CINFFirstAnniversaryEvent::IsMouseCaps(POINT ptPos)
{
	POINT ptBakPos = m_ptBkPos;
	POINT ptSize = {0,0};
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        
	ptSize = m_pBackImg->GetImgSize();
#endif
	if((ptPos.x >= ptBakPos.x && (ptPos.x <= ptBakPos.x+ptSize.x))
		&& (ptPos.y >= ptBakPos.y && (ptPos.y <= ptBakPos.y+20)))
	{
		return TRUE;
	}
	return FALSE;	
}

int CINFFirstAnniversaryEvent::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(!IsShowWnd())
	{
		return INF_MSGPROC_NORMAL;
	}

	switch(uMsg)
	{		
	case WM_LBUTTONDOWN:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			return OnLButtonDown(wParam, lParam);
		}
		break;
	case WM_MOUSEMOVE:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			
			return OnMouseMove(wParam, lParam);			
		}
		break;
	case WM_LBUTTONUP:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			return OnLButtonUp(wParam, lParam);			
		}
		break;	
	case WM_IME_STARTCOMPOSITION:
		//	case WM_IME_NOTIFY:
	case WM_IME_COMPOSITION:
	case WM_INPUTLANGCHANGE:	
	case WM_IME_ENDCOMPOSITION:
	case WM_IME_SETCONTEXT:	
	case WM_CHAR:
	case WM_KEYDOWN:
		{
			BOOL bBreak = FALSE;
			
			if(WM_KEYDOWN==uMsg )
			{
				switch(wParam)
				{
				case VK_ESCAPE:
					{								
						// 현재 윈도우를 숨긴다.
						ShowWnd(FALSE);
// 						if(g_pGameMain && g_pGameMain->m_pInven)
// 						{
// 							g_pGameMain->m_pInven->ShowInven(NULL, NULL, FALSE);	
// 						}
						return INF_MSGPROC_BREAK;				
					}
					break;				
				}
			}
			if(bBreak)
			{
				return INF_MSGPROC_BREAK;
			}						
		}
		break;
	}

	return INF_MSGPROC_NORMAL;
}

int CINFFirstAnniversaryEvent::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	if(FALSE == IsShowWnd() )
	{
		return INF_MSGPROC_NORMAL;
	}
	
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	{
		if(TRUE == m_pCloseBtn->OnLButtonDown(pt))
		{
			// 버튼위에 마우스가 있다.
			return  INF_MSGPROC_BREAK;
		}		
	}	

	GUI_BUILDINGNPC* pTempBaseShop = g_pInterface->m_pCityBase->GetCurrentBuildingNPC(); // 상점이 없을때만 	
	if(IsMouseCaps(pt) && !pTempBaseShop)
	{
		g_pInterface->SetWindowOrder(WNDFirstAnniversaryEvent);
		return INF_MSGPROC_BREAK;
	}
	

	return INF_MSGPROC_NORMAL;
}
int CINFFirstAnniversaryEvent::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	if(FALSE == IsShowWnd() )
	{
		return INF_MSGPROC_NORMAL;
	}
	
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_pD3dApp->GetHwnd(), &pt);
	CheckMouseReverse(&pt);	

	m_pCloseBtn->OnMouseMove(pt);	

	return INF_MSGPROC_NORMAL;
}
int CINFFirstAnniversaryEvent::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	if(FALSE == IsShowWnd() )
	{
		return INF_MSGPROC_NORMAL;
	}
	
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);	
	
	{
		if(TRUE == m_pCloseBtn->OnLButtonUp(pt))
		{					
			// 현재 윈도우를 숨긴다.
			ShowWnd(FALSE);
			
			g_pD3dApp->m_pSound->PlayD3DSound(SOUND_CLOSE_MENU, g_pShuttleChild->m_vPos, FALSE);
			return  INF_MSGPROC_BREAK;
		}
	}

	return INF_MSGPROC_NORMAL;
}

void CINFFirstAnniversaryEvent::CreateWebWindow(char* strWebSite,int nWebPosX,int nWebPosY,int nWebWidth,int nWebHeight)
{
	char strParameter[MAX_PATH];
	wsprintf(strParameter,"userid=%s",g_pD3dApp->m_strUserID);
	g_pD3dApp->CreateWebWindow(strWebSite,strParameter,nWebPosX,nWebPosY,nWebWidth,nWebHeight);
}

void CINFFirstAnniversaryEvent::DestroyWebWindow()
{
	g_pD3dApp->DestroyWebWindow();
}

void CINFFirstAnniversaryEvent::ShowWebWindow(int nWebPosX,int nWebPosY, int nWebWidth,int nWebHeight)
{
	g_pD3dApp->ShowWebWindow_FirstAnniversaryEvent(nWebPosX,nWebPosY,nWebWidth,nWebHeight);
}

void CINFFirstAnniversaryEvent::HideWebWindow()
{
	g_pD3dApp->HideWebWindow(); 
}