// INFTradeMyItemShow.cpp: implementation of the CINFTradeMyItemShow class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "AtumDatabase.h"
#include "INFWindow.h"
#include "ItemInfo.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFIcon.h"
#include "INFTradeItemCenter.h"
#include "INFTradeMyItemShow.h"
// 2014-06-17 거래소 추가작업 (주석 처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "ShuttleChild.h"
//#include "CharacterChild.h"
//#include "AtumSound.h"
//#include "Interface.h"
//#include "INFEditBox.h"
//#include "INFAutoEditBox.h"
//#include "INFImageBtn.h"
//#include "INFListBox.h"
//#include "INFArenaScrollBar.h"
//#include "INFInvenExtend.h"
//#include "INFItemInfo.h"
// END 2014-06-17 거래소 추가작업 (주석 처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// 창 크기
#define TRADEITEMBUY_WIDTH					936
#define	TRADEITEMBUY_HEIGHT					642

// 거래소 창 (그룹)
#define BACKIMAGE_LOCATION_X				19
#define BACKIMAGE_LOCATION_Y				92

// 새로고침
#define REFRESHBTN_LOCATION_X				879
#define REFRESHBTN_LOCATION_Y				96

// 아이템 리스트
#define ITEMLIST_LOCATION_Y					144
#define ITEMLIST_CELL_HEIGHT				40
#define ITEMLIST_ITEMSL_LOCATION_X			235
#define ITEMLIST_ITEMSL_LOCATION_Y			149
#define ITEMLIST_ICON_LOCATION_X			236
#define ITEMLIST_ICON_LOCATION_Y			150
#define ITEMLIST_ITEMCNT_LOCATION_X			26
#define ITEMLIST_ITEMCNT_LOCATION_Y			-2
#define ITEMLIST_ENCHANT_LOCATION_X			279
#define ITEMLIST_ENCHANT_WIDTH				58
#define ITEMLIST_NAME_LOCATION_X			338
#define ITEMLIST_NAME_WIDTH					241
#define ITEMLIST_LEVEL_LOCATION_X			580
#define ITEMLIST_LEVEL_WIDTH				58
#define	ITEMLIST_REGISTTIME_LOCATION_X		639
#define ITEMLIST_REGISTTIME_WIDTH			73
#define ITEMLIST_PRICE_LOCATION_X			713
#define ITEMLIST_PRICE_WIDTH				83
#define ITEMLIST_MONEYTYPE_LOCATION_X		800
#define ITEMLIST_MONEYTYPE_LOCATION_Y		155
#define ITEMLIST_MARKETGET_LOCATION_X		861
#define ITEMLIST_MARKETGET_LOCATION_Y		155
#define ITEMLIST_MAXITEMNAME_LEN			39

// 페이지 버튼
#define PAGEBTN_LOCATION_X					395
#define PAGEBTN_LOCATION_Y					566
#define PAGEBTN_FIRST_LOCATION_X			-32
#define PAGEBTN_PREV_LOCATION_X				-18
#define PAGEBTN_NEXT_LOCATION_X				0
#define PAGEBTN_LAST_LOCATION_X				10

// 툴팁
#define TOOLTIP_POSITION_Y					-13

CINFTradeMyItemShow::CINFTradeMyItemShow(CAtumNode* pParent)
{
	m_pParent = pParent;
	m_pBackImg = NULL;
	m_pRefreshBtn = NULL;
	m_nMyItemCount = 0;
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6; ++j)
		{
			m_pListFont[i][j] = NULL;
		}
	}
	m_pFeeFont = NULL;
#else
	m_pListFont = NULL;
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	m_pIconInfo = NULL;
	memset(&m_ptStartPos, 0x00, sizeof(POINT));

	for(i = 0; i<3; ++i)
	{
		m_pSellOKBtn[i] = NULL;
		m_pTimeLimitBtn[i] = NULL;
	}

	m_pConuntFont = NULL;
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		m_pCountFont[i] = NULL;
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	m_nMaxScrollPage = 1;
	m_pToolTipFont = NULL;
	m_bRefreshState = FALSE;

	m_fRefreshTime = -1.0f;
	m_vecItemInfo.clear();

	m_bRenderState = FALSE;
}

CINFTradeMyItemShow::~CINFTradeMyItemShow()
{
	SAFE_DELETE(m_pBackImg);
	SAFE_DELETE(m_pRefreshBtn);
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			SAFE_DELETE(m_pListFont[i][j]);
		}
	}
	SAFE_DELETE(m_pFeeFont);
#else
	SAFE_DELETE(m_pListFont);
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	for(i = 0; i<3; ++i)
	{
		SAFE_DELETE(m_pSellOKBtn[i]);
		SAFE_DELETE(m_pTimeLimitBtn[i]);
	}
	SAFE_DELETE(m_pConuntFont);
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		SAFE_DELETE(m_pCountFont[i]);
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	SAFE_DELETE(m_pToolTipFont);
}

HRESULT CINFTradeMyItemShow::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;
	
	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("tc_state");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage( pDataHeader );
		m_pBackImg->InitDeviceObjects( g_pD3dApp->m_pImageList );		
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "refs03");
		wsprintf(szDownBtn, "refs01");
		wsprintf(szSelBtn, "refs00");
		wsprintf(szDisBtn, "refs02");
		if(NULL == m_pRefreshBtn)
		{
			m_pRefreshBtn = new CINFImageBtn;
		}
		m_pRefreshBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn,"STRTOOLTIP46");	
	}

	char ImgName[30] = {0,};
	int i;
	for(i = 0; i<3; ++i)
	{
		if(g_pGameMain)
		{
			wsprintf(ImgName,"oks0%d", i);
			pDataHeader = g_pGameMain->FindResource(ImgName);
		}
		if(pDataHeader)
		{
			if(NULL == m_pSellOKBtn[i])
			{
				m_pSellOKBtn[i] = new CINFImageEx();
				m_pSellOKBtn[i]->InitDeviceObjects(pDataHeader);
			}
		}

		if(g_pGameMain)
		{
			wsprintf(ImgName,"apps0%d", i);
			pDataHeader = g_pGameMain->FindResource(ImgName);
		}
		if(pDataHeader)
		{
			if(NULL == m_pTimeLimitBtn[i])
			{
				m_pTimeLimitBtn[i] = new CINFImageEx();
				m_pTimeLimitBtn[i]->InitDeviceObjects(pDataHeader);
			}
		}
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(NULL == m_pListFont[i][j])
			{
				m_pListFont[i][j] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
				m_pListFont[i][j]->InitDeviceObjects(g_pD3dDev);
			}
		}
	}
	if(NULL == m_pFeeFont)
	{
		m_pFeeFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
		m_pFeeFont->InitDeviceObjects(g_pD3dDev);
	}
#else
 	if(NULL == m_pListFont)
 	{
 		m_pListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,512,32);
 		m_pListFont->InitDeviceObjects(g_pD3dDev);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

 	if(NULL == m_pConuntFont)
 	{
 		m_pConuntFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,1024,32);
 		m_pConuntFont->InitDeviceObjects(g_pD3dDev) ;
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(NULL == m_pCountFont[i])
		{
			m_pCountFont[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 1024, 32);
			m_pCountFont[i]->InitDeviceObjects(g_pD3dDev);
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	if(NULL == m_pToolTipFont)
	{
		m_pToolTipFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,128,32);
		m_pToolTipFont->InitDeviceObjects(g_pD3dDev) ;
	}

	return S_OK;
}
HRESULT CINFTradeMyItemShow::RestoreDeviceObjects()
{
	m_nMyItemCount = 0;
	m_nCurrentPage	= 1;	
	m_nStartPage	= 1;
	
	m_ptStartPos.x = (g_pD3dApp->GetBackBufferDesc().Width - TRADEITEMBUY_WIDTH)/2;
	m_ptStartPos.y = CITY_BASE_NPC_BOX_START_Y  - (TRADEITEMBUY_HEIGHT - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT));

	m_pIconInfo = g_pGameMain->m_pIcon;

	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
		m_pBackImg->Move(m_ptStartPos.x + BACKIMAGE_LOCATION_X, m_ptStartPos.y + BACKIMAGE_LOCATION_Y);
	}

	if(m_pRefreshBtn)
		m_pRefreshBtn->RestoreDeviceObjects();

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->RestoreDeviceObjects();
			}
		}
	}
	if(m_pFeeFont)
	{
		m_pFeeFont->RestoreDeviceObjects();
	}
#else
 	if(m_pListFont)
 		m_pListFont->RestoreDeviceObjects();
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	for(i = 0; i<3; ++i)
	{
		if(m_pSellOKBtn[i])
			m_pSellOKBtn[i]->RestoreDeviceObjects();
		if(m_pTimeLimitBtn[i])
			m_pTimeLimitBtn[i]->RestoreDeviceObjects();
	}

 	if(m_pConuntFont)
		m_pConuntFont->RestoreDeviceObjects();
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(m_pCountFont[i])
		{
			m_pCountFont[i]->RestoreDeviceObjects();
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	if(m_pToolTipFont)
		m_pToolTipFont->RestoreDeviceObjects();

//	RefreshBtnDown();
//	VecItemInfoClear();
	SetBtnPos();

	return S_OK;
}
HRESULT CINFTradeMyItemShow::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pRefreshBtn);
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->DeleteDeviceObjects();
				SAFE_DELETE(m_pListFont[i][j]);
			}
		}
	}
	if(m_pFeeFont)
	{
		m_pFeeFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pFeeFont);
	}
#else
 	if(m_pListFont)
 	{
 		m_pListFont->DeleteDeviceObjects();
 		SAFE_DELETE(m_pListFont);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	for(i = 0; i<3; ++i)
	{
		if(m_pSellOKBtn[i])
		{
			m_pSellOKBtn[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pSellOKBtn[i]);
		}

		if(m_pTimeLimitBtn[i])
		{
			m_pTimeLimitBtn[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pTimeLimitBtn[i]);
		}
	}

 	if(m_pConuntFont)
 	{
 		m_pConuntFont->DeleteDeviceObjects();
 		SAFE_DELETE(m_pConuntFont);
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(m_pCountFont[i])
		{
			m_pCountFont[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pCountFont[i]);
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	if(m_pToolTipFont)
	{
		m_pToolTipFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipFont);
	}

	return S_OK;
}
HRESULT CINFTradeMyItemShow::InvalidateDeviceObjects()
{
	if(m_pBackImg)
		m_pBackImg->InvalidateDeviceObjects();

	if(m_pRefreshBtn)
		m_pRefreshBtn->InvalidateDeviceObjects();

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->InvalidateDeviceObjects();
			}
		}
	}
	if(m_pFeeFont)
	{
		m_pFeeFont->InvalidateDeviceObjects();
	}
#else
 	if(m_pListFont)
 		m_pListFont->InvalidateDeviceObjects();
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	for(i = 0; i<3; ++i)
	{
		if(m_pSellOKBtn[i])
			m_pSellOKBtn[i]->InvalidateDeviceObjects();
		
		if(m_pTimeLimitBtn[i])
			m_pTimeLimitBtn[i]->InvalidateDeviceObjects();
	}

 	if(m_pConuntFont)
		m_pConuntFont->InvalidateDeviceObjects();
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(m_pCountFont[i])
		{
			m_pCountFont[i]->InvalidateDeviceObjects();
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	if(m_pToolTipFont)
		m_pToolTipFont->InvalidateDeviceObjects();

	return S_OK;
}
void CINFTradeMyItemShow::Render()
{
	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	if(m_pRefreshBtn)
		m_pRefreshBtn->Render();

	if(m_bRenderState)
		ListRender();

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->Render();			
		}	
	}
	RenderPageCnt();
	ToolTipRender();
}
void CINFTradeMyItemShow::Tick()
{
	if(m_bRefreshState)
	{
		if(m_fRefreshTime < 0)
		{
			m_bRefreshState = FALSE;
			m_pRefreshBtn->SetBtnState(BTN_STATUS_UP);
		}
		m_fRefreshTime -= g_pD3dApp->GetElapsedTime();
	}
}

int CINFTradeMyItemShow::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_MOUSEWHEEL:
		{
			return OnMouseWheel(wParam, lParam);
		}
		break;
	case WM_MOUSEMOVE:
		{
			return OnMouseMove(wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			return OnLButtonDown(wParam, lParam);			
		}
		break;
		
	case WM_LBUTTONUP:
		{
			return OnLButtonUp(wParam, lParam);
		}
		break;
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFTradeMyItemShow::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}	

 	int nCnt = 0;
	int nCnt02 = 0;
// 	vector<MARKET_MY_ITEM_INFO*>::iterator it;
// 	for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end(); it++)
// 	{
// 		MARKET_MY_ITEM_INFO* pMarketItem = (*it);

	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	else
		nCnt02 = ITEMLIST_ITEMNUM;
	
	for(int i = 0; i<nCnt02; ++i)
	{
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage-1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
			INF_MSGPROC_BREAK;
		
		if(pt.x > m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X && pt.x < m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X + m_pTimeLimitBtn[1]->GetImgSize().x && 
			pt.y > m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + m_pTimeLimitBtn[1]->GetImgSize().y)
		{
			pMarketItem->byBtnState = BTN_STATUS_DOWN;
			return  INF_MSGPROC_BREAK;
		}	
		nCnt++;
	}

	nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			if(TRUE == ((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonDown(pt))
			{
				return  INF_MSGPROC_BREAK;
			}
		}		
	}
	
	if(INF_MSGPROC_BREAK == OnCilckPageCnt(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_NORMAL;
}
int	CINFTradeMyItemShow::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnLButtonUp(pt))
	{
		RefreshBtnDown();
		return  INF_MSGPROC_BREAK;
	}	

	int nCnt = 0;
	int nCnt02 = 0;
// 	vector<MARKET_MY_ITEM_INFO*>::iterator it;
// 	for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end(); it++)
// 	{
// 		MARKET_MY_ITEM_INFO* pMarketItem = (*it);

	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	else
		nCnt02 = ITEMLIST_ITEMNUM;
	
	for(int i = 0; i<nCnt02; ++i)
	{
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage-1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
			INF_MSGPROC_BREAK;
		
		if(pt.x > m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X && pt.x < m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X + m_pTimeLimitBtn[1]->GetImgSize().x && 
			pt.y > m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + m_pTimeLimitBtn[1]->GetImgSize().y)
		{
			if(pMarketItem->byBtnState == BTN_STATUS_DOWN)
			{
				SendGetRequest(pMarketItem->pINFO->MarketInfo.MarketUID, pMarketItem->pINFO->MarketInfo.MarketState, pMarketItem->pINFO->MarketInfo.Price,pMarketItem->pINFO->MarketInfo.MoneyType);
				pMarketItem->byBtnState = BTN_STATUS_UP;
			}
			return  INF_MSGPROC_BREAK;
		}	
		nCnt++;
	}

	nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{		
		if(TRUE == ((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonUp(pt))
		{			
			OnClickPageBtn(nCnt);
			return  INF_MSGPROC_BREAK;
		}		
	}	

	return INF_MSGPROC_NORMAL;
}
int	CINFTradeMyItemShow::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	m_nToolTipState = 0;

	if(TRUE == m_pRefreshBtn->OnMouseMove(pt))
	{
		return  INF_MSGPROC_BREAK;
	}

	int nCnt = 0;
	int nCnt02 = 0;
// 	vector<MARKET_MY_ITEM_INFO*>::iterator it;
// 	for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end(); it++)
// 	{
//		MARKET_MY_ITEM_INFO* pMarketItem = (*it);

	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	else
		nCnt02 = ITEMLIST_ITEMNUM;
	
	for(int i = 0; i<nCnt02; ++i)
	{
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage-1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
			return INF_MSGPROC_BREAK;

		if(pt.x > m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X && pt.x < m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X + m_pTimeLimitBtn[1]->GetImgSize().x &&
			pt.y > m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + m_pTimeLimitBtn[1]->GetImgSize().y)
		{
			if(pMarketItem->byBtnState != BTN_STATUS_DOWN)
				pMarketItem->byBtnState = BTN_STATUS_UP;

			memcpy(&m_ptToolTipPos, &pt, sizeof(POINT));

			m_nToolTipState = pMarketItem->pINFO->MarketInfo.MarketState;
		}
		else
			pMarketItem->byBtnState = BTN_STATUS_UP;

		nCnt++;
	}

	nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->OnMouseMove(pt);				
		}		
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeMyItemShow::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	return INF_MSGPROC_NORMAL;
}

void CINFTradeMyItemShow::SetBtnPos()
{
	m_pRefreshBtn->SetBtnPosition(m_ptStartPos.x + REFRESHBTN_LOCATION_X, m_ptStartPos.y + REFRESHBTN_LOCATION_Y);

	{
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage+1);
		nPageCnt = max(1, nPageCnt);	
		
		int nStartX = m_ptStartPos.x + PAGEBTN_LOCATION_X;
		int nStartY = m_ptStartPos.y + PAGEBTN_LOCATION_Y;
		
		int nTmpPosX = nStartX+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][0].x;
		int nTmpPosY = nStartY+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][0].y;
		
		((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_FIRST]->SetBtnPosition(nTmpPosX + PAGEBTN_FIRST_LOCATION_X, nTmpPosY + 2);				
		((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_PREV]->SetBtnPosition(nTmpPosX + PAGEBTN_PREV_LOCATION_X, nTmpPosY + 2);				
		
		nTmpPosX = nStartX+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nPageCnt-1].x;
		nTmpPosY = nStartY+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nPageCnt-1].y;

		int nTmpNextPosX = nTmpPosX+16;
		if(m_pConuntFont)
		{
			char chTxt[64] ={0,}; 
			wsprintf(chTxt, "%d", m_nMaxScrollPage);
			SIZE szSize = m_pConuntFont->GetStringSize(chTxt);
			nTmpNextPosX = nTmpPosX + szSize.cx + 8;
		}
		((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_NEXT]->SetBtnPosition(nTmpNextPosX + PAGEBTN_NEXT_LOCATION_X, nTmpPosY + 2);				
		((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_LAST]->SetBtnPosition(nTmpNextPosX + PAGEBTN_LAST_LOCATION_X, nTmpPosY + 2);
	}			
}

void CINFTradeMyItemShow::MyItemVecAdd(MSG_FC_MARKET_MY_LIST_OK* pMsg)
{
	MARKET_MY_ITEM_INFO* pTemp = new MARKET_MY_ITEM_INFO;
	memset(pTemp, 0x00, sizeof(MARKET_MY_ITEM_INFO));

	pTemp->pINFO = new MSG_FC_MARKET_MY_LIST_OK;
	ITEM_GENERAL *pITEMG = new ITEM_GENERAL;
	
	memset(pITEMG, 0x00, sizeof(ITEM_GENERAL));
	memset(pTemp->pINFO, 0x00, sizeof(MSG_FC_MARKET_MY_LIST_OK));
	
	memcpy(pTemp->pINFO, pMsg, sizeof(MSG_FC_MARKET_MY_LIST_OK));
	
	pITEMG->PrefixCodeNum = pMsg->MarketInfo.PrefixCodeNum;
	pITEMG->SuffixCodeNum = pMsg->MarketInfo.SuffixCodeNum;
	pITEMG->UniqueNumber = pMsg->MarketInfo.ItemUID;
	pITEMG->ShapeItemNum = pMsg->MarketInfo.ShapeItemNum;

	pITEMG->	UniqueNumber = pMsg->MarketInfo.ItemUID;
	pITEMG->	ItemNum =pMsg->MarketInfo.ItemNum;
	pITEMG->	CurrentCount = pMsg->MarketInfo.ItemCount;
	
	pITEMG->	PrefixCodeNum = pMsg->MarketInfo.PrefixCodeNum;
	pITEMG->	SuffixCodeNum = pMsg->MarketInfo.SuffixCodeNum;
	pITEMG->	ShapeItemNum	= pMsg->MarketInfo.ShapeItemNum;
	pITEMG->	ColorCode	  = pMsg->MarketInfo.ColorCode;
	
	pTemp->pItem = new CItemInfo(pITEMG);
	
	for(int i = 0; i<8; ++i)
	{
		for(int j  = 0; j < pMsg->MarketInfo.Enchant[i].Count; ++j)
		{
			pTemp->pItem->AddEnchantItem(pMsg->MarketInfo.Enchant[i].ItemNum);
		}
	}
	pTemp->pItem->Kind = pTemp->pItem->ItemInfo->Kind;
	m_vecItemInfo.push_back(pTemp);
}

void CINFTradeMyItemShow::ListRender()
{
	int nCnt = 0;
	int nCnt02 = 0;
	char cList[512] = {0,};
	char cTemp[512] = {0,};
	CINFImageEx* pImg = NULL;

	if(m_vecItemInfo.size() <= 0)
		return;
	
// 	vector<MARKET_MY_ITEM_INFO*>::iterator it;
// 	for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end(); it++)
	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	else
		nCnt02 = ITEMLIST_ITEMNUM;

	for(int i = 0; i<nCnt02; ++i)
	{
//		MARKET_MY_ITEM_INFO* pMarketItem = (*it);
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage-1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
			return;

		if(((CINFTradeItemCenter*)m_pParent)->GetRemainTime(pMarketItem->pINFO->MarketInfo.RegistTime, cList) == FALSE && MARKET_STATE_SELL_DONE != pMarketItem->pINFO->MarketInfo.MarketState)
		{
			pMarketItem->pINFO->MarketInfo.MarketState = MARKET_STATE_TIME_OUT;
		}
		
 		((CINFTradeItemCenter*)m_pParent)->m_pItemSl->Move(m_ptStartPos.x + ITEMLIST_ITEMSL_LOCATION_X, m_ptStartPos.y + ITEMLIST_ITEMSL_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1));
 		((CINFTradeItemCenter*)m_pParent)->m_pItemSl->Render();
		
		if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL) wsprintf(cList,"\\e+%d\\e", pMarketItem->pItem->GetEnchantNumber());
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE) wsprintf(cList,"\\y+%d\\y", pMarketItem->pItem->GetEnchantNumber());
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) wsprintf(cList,"\\r+%d\\r", pMarketItem->pItem->GetEnchantNumber());
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		SIZE sSize = m_pListFont[i][0]->GetStringSize(cList);
		m_pListFont[i][0]->DrawText(m_ptStartPos.x + ITEMLIST_ENCHANT_LOCATION_X + ITEMLIST_ENCHANT_WIDTH/2 - sSize.cx/2, 
									m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
									GUI_FONT_COLOR, cList);
#else
 		SIZE sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_ENCHANT_LOCATION_X + ITEMLIST_ENCHANT_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
		
		if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL) wsprintf(cList,"%s", pMarketItem->pINFO->MarketInfo.ItemName);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE) wsprintf(cList,"\\y%s\\y", pMarketItem->pINFO->MarketInfo.ItemName);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) wsprintf(cList,"\\r%s\\r", pMarketItem->pINFO->MarketInfo.ItemName);

		((CINFTradeItemCenter*)m_pParent)->ChangeMaxLenString(cList, ITEMLIST_MAXITEMNAME_LEN);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][1]->GetStringSize(cList);
		m_pListFont[i][1]->DrawText(m_ptStartPos.x + ITEMLIST_NAME_LOCATION_X + ITEMLIST_NAME_WIDTH/2 - sSize.cx/2, 
									m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_NAME_LOCATION_X + ITEMLIST_NAME_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	
		if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL) wsprintf(cList,"%d", pMarketItem->pINFO->MarketInfo.ItemLevel);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE) wsprintf(cList,"\\y%d\\y", pMarketItem->pINFO->MarketInfo.ItemLevel);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) wsprintf(cList,"\\r%d\\r", pMarketItem->pINFO->MarketInfo.ItemLevel);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][2]->GetStringSize(cList);
		m_pListFont[i][2]->DrawText(m_ptStartPos.x + ITEMLIST_LEVEL_LOCATION_X + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
									m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_LEVEL_LOCATION_X + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL) ((CINFTradeItemCenter*)m_pParent)->GetRemainTime(pMarketItem->pINFO->MarketInfo.RegistTime, cList);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE) wsprintf(cList, STRMSG_C_131205_0045);	// "\\y판매완료\\y"
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) wsprintf(cList, STRMSG_C_131205_0046);		// "\\r기간만료\\r"
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][3]->GetStringSize(cList);
		m_pListFont[i][3]->DrawText(m_ptStartPos.x + ITEMLIST_REGISTTIME_LOCATION_X + ITEMLIST_REGISTTIME_WIDTH/2 - sSize.cx/2, 
									m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_REGISTTIME_LOCATION_X + ITEMLIST_REGISTTIME_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		wsprintf(cList,"%d", pMarketItem->pINFO->MarketInfo.Price);
		MakeCurrencySeparator(cTemp,cList,3,',');	
		ZeroMemory(cList,sizeof(cList));
		if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL) strncpy(cList,cTemp,strlen(cTemp));
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE) wsprintf(cList,"\\y%s\\y", cTemp);
		else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) wsprintf(cList,"\\r%s\\r", cTemp);

		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][4]->GetStringSize(cList);
		m_pListFont[i][4]->DrawText(m_ptStartPos.x + ITEMLIST_PRICE_LOCATION_X + ITEMLIST_PRICE_WIDTH - sSize.cx, 
									m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_PRICE_LOCATION_X + ITEMLIST_PRICE_WIDTH - sSize.cx, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2 - sSize.cy/2 + nCnt * (ITEMLIST_CELL_HEIGHT+1), 
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
		
		if(SPI == pMarketItem->pINFO->MarketInfo.MoneyType)
			pImg  = ((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[SPI];
		else if(WP == pMarketItem->pINFO->MarketInfo.MoneyType)
			pImg  = ((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[WP];
		
		if(pImg)
		{
			pImg->Move(m_ptStartPos.x + ITEMLIST_MONEYTYPE_LOCATION_X, m_ptStartPos.y + ITEMLIST_MONEYTYPE_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1));
			pImg->Render();
		}
		
		if(m_pIconInfo)
		{
			char chIconName[64] = {0,};	
			if( !pMarketItem->pItem->ShapeItemNum)
				wsprintf( chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
			else
			{
				ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(pMarketItem->pItem->ShapeItemNum);
				if( pShapeItem )
					wsprintf( chIconName, "%08d", pShapeItem->SourceIndex );
				else
					wsprintf( chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
			}		

			m_pIconInfo->SetIcon(chIconName, m_ptStartPos.x + ITEMLIST_ICON_LOCATION_X, 
											 m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1), 1.0f);
			m_pIconInfo->Render();

			if( IS_COUNTABLE_ITEM(pMarketItem->pItem->Kind) )
			{
				if( pMarketItem->pINFO->MarketInfo.ItemCount > 1 )
				{
					wsprintf(cList, "%d", pMarketItem->pINFO->MarketInfo.ItemCount);
					// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
					int itemCntStrLen = m_pListFont[i][5]->GetStringSize(cList).cx;
					m_pListFont[i][5]->DrawText(m_ptStartPos.x + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen, 
												m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + ITEMLIST_ITEMCNT_LOCATION_Y, 
												QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#else
 					int itemCntStrLen = m_pListFont->GetStringSize(cList).cx;
 					m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen, 
 										  m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + ITEMLIST_ITEMCNT_LOCATION_Y, 
 										  QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#endif
					// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
				}
			}
		}

	if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL)
	{
		m_pTimeLimitBtn[pMarketItem->byBtnState]->Move(m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X, 
													   m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1));
		m_pTimeLimitBtn[pMarketItem->byBtnState]->Render();
	}
	else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_SELL_DONE)
	{
		m_pSellOKBtn[pMarketItem->byBtnState]->Move(m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X, 
													m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1));
		m_pSellOKBtn[pMarketItem->byBtnState]->Render();
	}
	else if(pMarketItem->pINFO->MarketInfo.MarketState == MARKET_STATE_TIME_OUT) 
	{
		m_pTimeLimitBtn[pMarketItem->byBtnState]->Move(m_ptStartPos.x + ITEMLIST_MARKETGET_LOCATION_X, 
													   m_ptStartPos.y + ITEMLIST_MARKETGET_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1));
		m_pTimeLimitBtn[pMarketItem->byBtnState]->Render();
	}

		nCnt++;
	}

	sprintf(cList,STRMSG_C_131217_0008, MARKET_SELL_CHARGE_SPI*100, MARKET_SELL_CHARGE_WP*100);
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	SIZE sSize = m_pFeeFont->GetStringSize(cList);
	m_pFeeFont->DrawText(m_ptStartPos.x + 920 - sSize.cx, m_ptStartPos.y + 617, GUI_FONT_COLOR_W, cList);
#else
 	SIZE sSize = m_pListFont->GetStringSize(cList);
 	m_pListFont->DrawText(m_ptStartPos.x + 920 - sSize.cx, m_ptStartPos.y + 617, GUI_FONT_COLOR_W, cList);
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
}

void CINFTradeMyItemShow::VecItemInfoClear()
{
	m_bRenderState = FALSE;
	m_nCurrentPage = 1;
	m_nMaxScrollPage = 1; 
	m_nStartPage = 1;
	SetBtnPos();

	if(0 < m_vecItemInfo.size())
	{
		vector<MARKET_MY_ITEM_INFO*>::iterator it;
		for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end();)
		{
			MARKET_MY_ITEM_INFO* pMarketItem = (*it);
			if(pMarketItem)
			{
				SAFE_DELETE(pMarketItem->pINFO);
				SAFE_DELETE(pMarketItem->pItem);
				SAFE_DELETE(pMarketItem);
				it = m_vecItemInfo.erase(it);
			}
			else
				it++;
		}
		if(m_vecItemInfo.empty() == false)
			m_vecItemInfo.clear();
	}
}
void CINFTradeMyItemShow::SetMyListCount(int nCount)
{
	m_nMyItemCount = nCount;
	m_nMaxScrollPage = nCount/10;

	if(nCount % ITEMLIST_ITEMNUM != 0)
		m_nMaxScrollPage++;

	SetBtnPos();

	m_bRenderState = TRUE;
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(FALSE);
}
void CINFTradeMyItemShow::SendGetRequest(UID64_t UID, BYTE byState, INT nPrice, BYTE MoneyType)
{
	if(MARKET_STATE_SELL == byState)
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0047, _Q_MARKET_GET_ITEM,byState,0,0,UID);	// "거래소에 등록중인 아이템을 회수 하시겠습니까?"
	else if(MARKET_STATE_TIME_OUT == byState)
		//g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0048, _Q_MARKET_GET_ITEM,MARKET_STATE_SELL,0,0,UID);	// "기간 만료된 아이템을 회수 하시겠습니까?"
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0048, _Q_MARKET_GET_ITEM,byState,0,0,UID);	// "기간 만료된 아이템을 회수 하시겠습니까?"
	else if(MARKET_STATE_SELL_DONE == byState)
	{
		char cTemp[256] = {0,};
		char cTemp02[256] = {0,};
		INT nTemp = 0;

		if(MoneyType == SPI)
			nTemp = GetMarketSellChargeSPI(nPrice);	
		else if(MoneyType == WP)
			nTemp = GetMarketSellChargeWP(nPrice);

		wsprintf(cTemp,"%d",nTemp);
		MakeCurrencySeparator(cTemp02,cTemp,3,',');

		if(MoneyType == SPI)
			wsprintf(cTemp, STRMSG_C_131205_0049, cTemp02,"SPI");
		else if(MoneyType == WP)
			wsprintf(cTemp, STRMSG_C_131205_0049, cTemp02,"WP");			//"판매된 물품의 금액을 회수 하시겠습니까?\\n(판매 수수료 : %s %s)"
		
		g_pGameMain->m_pInfWindow->AddMsgBox(cTemp, _Q_MARKET_GET_ITEM,byState,0,0,UID,NULL,TRUE);
	}
	m_nToolTipState = 0;
}


void CINFTradeMyItemShow::RenderPageCnt()
{	
	if(NULL == m_pConuntFont)
	{
		return;
	}
	{
		int nStartX = m_ptStartPos.x + PAGEBTN_LOCATION_X;
		int nStartY = m_ptStartPos.y + PAGEBTN_LOCATION_Y;
		
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage+1);
		nPageCnt = max(1, nPageCnt);
		
		int nCnt = 0;
		
		char chTxt[64];				
		for(nCnt = 0;nCnt < nPageCnt;nCnt++)
		{
			if(-1 == ((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nCnt].x)
			{
				break;
			}
			DWORD dwColor = GUI_FONT_COLOR_W;
			int nShowPage = m_nStartPage+nCnt;
			if(nShowPage == m_nCurrentPage)
			{
				dwColor = GUI_FONT_COLOR_Y;
			}
			wsprintf(chTxt, "%d", nShowPage);
			// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
			m_pCountFont[nCnt]->DrawText(nStartX + ((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].x,
										 nStartY + ((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].y,
										 dwColor, chTxt);
#else
			m_pConuntFont->DrawText(nStartX+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nCnt].x,
 				nStartY+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nCnt].y,
 				dwColor, 
 				chTxt);
#endif
			// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
		}		
	}
}

void CINFTradeMyItemShow::OnClickPageBtn(int nPageMode)
{
	switch(nPageMode)
	{
	case PAGE_BTN_FIRST:
		{			
			//첫페이지로
			UpdateItemListScroll(1,1);
		}
		break;
	case PAGE_BTN_PREV:
		{
			int	nStartPage		= m_nStartPage-MAX_SEARCH_PAGE;		// 현재 그림의 시작 페이지
			int	nCurrentPage	= m_nCurrentPage;	// 현재 보고 있는 페이지
			if(nStartPage <= 0)
			{
				// 10페이지 씩이동하는데 10페이지보다 작다
				return;
			}			
			UpdateItemListScroll(nStartPage,nStartPage);
		}
		break;
	case PAGE_BTN_NEXT:
		{
			int	nStartPage		= m_nStartPage+MAX_SEARCH_PAGE;		// 현재 그림의 시작 페이지
			int	nCurrentPage	= m_nCurrentPage;	// 현재 보고 있는 페이지
			if(nStartPage > m_nMaxScrollPage)
			{
				// 10페이지 씩이동하는데 10페이지보다 작다
				return;
			}			
			UpdateItemListScroll(nStartPage,nStartPage);
		}
		break;
	case PAGE_BTN_LAST:
		{
			int	nCap		= max(0, m_nMaxScrollPage-m_nStartPage);		// 현재 그림의 시작 페이지
			if(nCap <= 0)
			{
				return;
			}
			int	nAddPage	= nCap/MAX_SEARCH_PAGE;	// 현재 보고 있는 페이지
			int	nStartPage	= m_nStartPage+(nAddPage*MAX_SEARCH_PAGE);			
			UpdateItemListScroll(m_nMaxScrollPage,nStartPage);
		}
		break;
	default:
		{
			return;
		}
		break;
	}
}

void CINFTradeMyItemShow::UpdateItemListScroll(int nCurrentPage, int nStartPage)
{
	m_nCurrentPage	= nCurrentPage;	
	m_nStartPage	= nStartPage;	
	
	SetBtnPos();
}

int CINFTradeMyItemShow::OnCilckPageCnt(POINT ptPos)
{
	int nStartX = m_ptStartPos.x + PAGEBTN_LOCATION_X;
	int nStartY = m_ptStartPos.y + PAGEBTN_LOCATION_Y;
	
	int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage+1);
	nPageCnt = max(1, nPageCnt);	
	int nCnt = 0;
	
	for(nCnt = 0;nCnt < nPageCnt;nCnt++)
	{		
		int nTmpPosX = nStartX+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nCnt].x;
		int nTmpPosY = nStartY+((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][nCnt].y;
		
		if((nTmpPosY <= ptPos.y) && (ptPos.y <= nTmpPosY+PAGE_LIST_HEIGHT))
		{
			if((nTmpPosX <= ptPos.x) && (ptPos.x <= nTmpPosX+PAGE_LIST_WIDTH))
			{
				int nCurrentPage = m_nStartPage+nCnt;
				UpdateItemListScroll(nCurrentPage, m_nStartPage);
				
				return INF_MSGPROC_BREAK;	
			}	
		}
	}
	return INF_MSGPROC_NORMAL;	
}

void CINFTradeMyItemShow::MarketGetOk(MSG_FC_MARKET_GET_OK* pMsg)
{
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(FALSE);
	BOOL DeleteItem = FALSE;
	if(pMsg->MarketStatus == MARKET_GET_SELLING)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0051, _Q_MARKET_NORMAL_MESSAGE);	// "판매 중인 아이템을 회수 하였습니다. "
		DeleteItem = TRUE;
	}
	else if(pMsg->MarketStatus == MARKET_GET_EXPIRATION)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0052, _Q_MARKET_NORMAL_MESSAGE);	// "기간이 만료된 아이템을 회수 하셨습니다. "
		DeleteItem = TRUE;
	}
	else if(pMsg->MarketStatus == MARKET_GET_SOLD)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0053, _Q_MARKET_NORMAL_MESSAGE);	// "판매 금액을 회수 하였습니다. "
		DeleteItem = TRUE;
	}
	else
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0054, _Q_MARKET_NORMAL_MESSAGE);	// "회수에 실패 하였습니다. 다시 시도 하시기 바랍니다. "
	}
	if(DeleteItem == TRUE)
	{
		vector<MARKET_MY_ITEM_INFO*>::iterator it;
		for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end();)
		{
			MARKET_MY_ITEM_INFO* pMarketItem = (*it);
			
			if(!pMarketItem) return;

			if(pMarketItem->pINFO->MarketInfo.MarketUID == pMsg->MarketUID)
			{
				SAFE_DELETE(pMarketItem->pINFO);
				SAFE_DELETE(pMarketItem->pItem);
				SAFE_DELETE(pMarketItem);
				it = m_vecItemInfo.erase(it);
				break;
			}
			else
			{
				it++;
			}
		}
	}

	if(m_vecItemInfo.size() > 0)
	{
		m_nMaxScrollPage = m_vecItemInfo.size()/10;
		
		if(m_vecItemInfo.size()%10 > 0)
			m_nMaxScrollPage++;

		if(m_nCurrentPage > m_nMaxScrollPage)
			m_nCurrentPage = m_nMaxScrollPage;
	}
	else
		m_nMaxScrollPage = m_nCurrentPage = 1;
	
	SetBtnPos();

	//g_pFieldWinSocket->SendMsg( T_FC_MARKET_MY_LIST_REQUEST, NULL , 0);
}

void CINFTradeMyItemShow::ToolTipRender()
{
	if(0 == m_nToolTipState)
		return;

	char buf[128] = {0,};
	int nX = m_ptToolTipPos.x;

	if(MARKET_STATE_SELL == m_nToolTipState || MARKET_STATE_TIME_OUT == m_nToolTipState)
	{
		wsprintf(buf, STRMSG_C_131205_0055);	// "회수"
	}
	else if(MARKET_STATE_SELL_DONE == m_nToolTipState)
	{
		wsprintf(buf, STRMSG_C_131205_0056);	// "금액회수"
	}

	int leng = m_pToolTipFont->GetStringSize(buf).cx + 4;
	
	if(nX + leng > g_pD3dApp->GetBackBufferDesc().Width)
	{
		nX = g_pD3dApp->GetBackBufferDesc().Width - leng;
	}
	g_pGameMain->RenderPopUpWindowImage(nX, m_ptToolTipPos.y + TOOLTIP_POSITION_Y, leng, 1);
	m_pToolTipFont->DrawText(nX+1, m_ptToolTipPos.y + TOOLTIP_POSITION_Y - 2 , GUI_FONT_COLOR_W, buf);

}

void CINFTradeMyItemShow::RefreshBtnDown()
{
	if(!m_bRefreshState)
	{
		m_bRefreshState = TRUE;
		m_fRefreshTime = 0.0f;
		m_pRefreshBtn->SetBtnState(BTN_STATUS_DISABLE);

		g_pFieldWinSocket->SendMsg( T_FC_MARKET_MY_LIST_REQUEST, NULL , 0);
		((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
	}
	//시간간이 지나면 상태를 바꾸면됨 저걸 펄스로 
}
