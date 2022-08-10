// INFReturnMyAuctionList.cpp: implementation of the CINFReturnMyAuctionList class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "ItemInfo.h"
#include "INFGroupImage.h"
#include "INFGroupManager.h"
#include "INFToolTip.h"
#include "INFIcon.h"
#include "INFReturnAuctionMsgBox.h"
#include "INFReturnMyAuctionList.h"
#include "INFWindow.h"
#include "StoreData.h"							// 2014-06-12 by ymjoo 파괴 경매장 추가작업
// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "CharacterChild.h"
//#include "Interface.h"
//#include "INFImageBtn.h"
//#include "INFArenaScrollBar.h"
//#include "INFItemInfo.h"
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define	REFRESHBTN_LOCATION_X				879				//새로고침 버튼 x
#define	REFRESHBTN_LOCATION_Y				96				//새로고침 버튼 Y

// 아이템 리스트
#define ITEMLIST_LOCATION_X					219
#define ITEMLIST_LOCATION_Y					144
#define ITEMLIST_CELL_HEIGHT				40
#define ITEMLIST_WIDTH						684
#define ITEMLIST_HEIGHT						408
#define ITEMLIST_ITEMSL_LOCATION_X			235
#define ITEMLIST_ITEMSL_LOCATION_Y			149
#define ITEMLIST_ICON_LOCATION_X			236
#define ITEMLIST_ICON_LOCATION_Y			150
#define ITEMLIST_ITEMCNT_LOCATION_X			26
#define ITEMLIST_ITEMCNT_LOCATION_Y			-2
#define ITEMLIST_ITEM_WIDTH					58
#define ITEMLIST_ENCHANT_LOCATION_X			279
#define ITEMLIST_ENCHANT_WIDTH				58
#define ITEMLIST_NAME_LOCATION_X			338
#define ITEMLIST_NAME_WIDTH					168
#define ITEMLIST_LEVEL_LOCATION_X			507
#define ITEMLIST_LEVEL_WIDTH				58
#define ITEMLIST_REGISTTIME_LOCATION_X		566
#define ITEMLIST_REGISTTIME_WIDTH			73
#define ITEMLIST_PRICE_LOCATION_X			640
#define ITEMLIST_PRICE_WIDTH				83
#define ITEMLIST_MONEYTYPE_LOCATION_X		727
#define ITEMLIST_MONEYTYPE_LOCATION_Y		155
#define ITEMLIST_BIDDINGIMG_LOCATION_X		861
#define ITEMLIST_BIDDINGIMG_LOCATION_Y		151
#define ITEMLIST_MAXITEMNAME_LEN			30

/////////////////////////////////////////////////////
#define LISTVIEW_START_X					19			//각 뷰의 뒷 배경 위치 지정 
#define LISTVIEW_START_Y					92
/////////////////////////////////////////////////////
// 카테고리
#define CATEGORY_LOCATION_X					26
#define CATEGORY_LOCATION_Y					204
#define CATEGORY_WIDTH						154
#define CATEGORY_HEIGHT						385
#define CATEGORY_SUBITEM_LOCATION_X			21
#define CATEGORY_SUBITEM_LOCATION_Y			5
#define CATEGORY_SCROLL_LOCATION_X			154
#define CATEGORY_SCROLL_LOCATION_Y			-5
/////////////////////////////////////////////////////

// 툴팁
#define TOOLTIP_POSITION_Y					-13
/////////////////////////////////////////////////////
// 페이지 버튼
#define PAGEBTN_LOCATION_X					395
#define PAGEBTN_LOCATION_Y					566
#define PAGEBTN_FIRST_LOCATION_X			-32
#define PAGEBTN_PREV_LOCATION_X				-18
#define PAGEBTN_NEXT_LOCATION_X				0
#define PAGEBTN_LAST_LOCATION_X				10

/////////////////////////////////////////////////////
//남은 입찰 휫수 
#define BIDDINGCOUNT_X						72
#define BIDDINGCOUNT_Y						338

enum AUCTIONSTATE
{
	AUCTION_START_MY_ITEM = 1,
	AUCTION_START_NO_ITEM,
	AUCTION_END_MY_ITEM,
	AUCTION_END_NO_ITEM,
};


CINFReturnMyAuctionList::CINFReturnMyAuctionList(CAtumNode* parent)
{
	m_pParent = parent;

	m_bShowWnd = FALSE;

	m_pBackImg = NULL;

	m_pRefreshBtn = NULL;

	m_pToolTipFont = NULL;
	m_pConuntFont = NULL;
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		m_pCountFont[i] = NULL;
	}
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			m_pListFont[i][j] = NULL;
		}
	}
#else
	m_pListFont = NULL;
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	m_pBiddingCountFont = NULL;

	m_nCurrentPage = 1;	
	m_nStartPage = 1;
	m_nMaxScrollPage = 1;
	m_pIconInfo = NULL;

	m_pMsgBox = NULL;

	m_fItemCheckTime = -1.0f;

	m_pLastRefreshTime = GetServerDateTime();			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	m_pLastRefreshTime.AddDateTime(0, 0, 0, 0, 0, -10);	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

CINFReturnMyAuctionList::~CINFReturnMyAuctionList()
{
	SAFE_DELETE(m_pBackImg);
	SAFE_DELETE(m_pRefreshBtn);
	SAFE_DELETE(m_pToolTipFont);
	SAFE_DELETE(m_pConuntFont);
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		SAFE_DELETE(m_pCountFont[i]);
	}
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			SAFE_DELETE(m_pListFont[i][j]);
		}
	}
#else
	SAFE_DELETE(m_pListFont);
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	SAFE_DELETE(m_pBiddingCountFont);
	SAFE_DELETE(m_pMsgBox);
}

HRESULT CINFReturnMyAuctionList::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;

	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("ra_state");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage(pDataHeader);
		m_pBackImg->InitDeviceObjects(g_pD3dApp->m_pImageList);		
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
		m_pRefreshBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn, "STRTOOLTIP46");	
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			if(NULL == m_pListFont[i][j])
			{
				m_pListFont[i][j] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
				m_pListFont[i][j]->InitDeviceObjects(g_pD3dDev);
			}
		}
	}
#else
 	if(NULL == m_pListFont)
 	{
 		m_pListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
 		m_pListFont->InitDeviceObjects(g_pD3dDev);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	
	if(NULL == m_pConuntFont)
	{
		m_pConuntFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 1024, 32);
		m_pConuntFont->InitDeviceObjects(g_pD3dDev);
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
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
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)

	if(NULL == m_pToolTipFont)
	{
		m_pToolTipFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 128, 32);
		m_pToolTipFont->InitDeviceObjects(g_pD3dDev);
	}

	if(NULL == m_pBiddingCountFont)
	{
		//m_pBiddingCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),16, D3DFONT_ZENABLE | D3DFONT_BOLD, TRUE,1024,32);
		m_pBiddingCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 16, D3DFONT_ZENABLE, TRUE, 1024, 32);
		m_pBiddingCountFont->InitDeviceObjects(g_pD3dDev);
	}

	m_pIconInfo = g_pGameMain->m_pIcon;

	return S_OK;
}

HRESULT CINFReturnMyAuctionList::RestoreDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->RestoreDeviceObjects();
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->RestoreDeviceObjects();
			}
		}
	}
#else
 	if(m_pListFont)
 	{
 		m_pListFont->RestoreDeviceObjects();
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)

	if(m_pConuntFont)
	{
		m_pConuntFont->RestoreDeviceObjects();
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(m_pCountFont[i])
		{
			m_pCountFont[i]->RestoreDeviceObjects();
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	
	if(m_pToolTipFont)
	{
		m_pToolTipFont->RestoreDeviceObjects();
	}

	if(m_pBiddingCountFont)
	{
		m_pBiddingCountFont->RestoreDeviceObjects();
	}

	if(m_pMsgBox)
	{
		m_pMsgBox->RestoreDeviceObjects();
	}

	return S_OK;
}

HRESULT CINFReturnMyAuctionList::DeleteDeviceObjects()
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

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->DeleteDeviceObjects();
				SAFE_DELETE(m_pListFont[i][j]);
			}
		}
	}
#else
 	if(m_pListFont)
 	{
 		m_pListFont->DeleteDeviceObjects();
 		SAFE_DELETE(m_pListFont);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)

	if(m_pConuntFont)
	{
		m_pConuntFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pConuntFont);
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
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
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	
	if(m_pToolTipFont)
	{
		m_pToolTipFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipFont);
	}

	if(m_pBiddingCountFont)
	{
		m_pBiddingCountFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pBiddingCountFont);
	}

	if(m_pMsgBox)
	{
		m_pMsgBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMsgBox);
	}

	return S_OK;
}

HRESULT CINFReturnMyAuctionList::InvalidateDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->InvalidateDeviceObjects();
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->InvalidateDeviceObjects();
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	int i;
	for(i = 0 ; i < ITEMLIST_ITEMNUM ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->InvalidateDeviceObjects();
			}
		}
	}
#else
 	if(m_pListFont)
 	{
 		m_pListFont->InvalidateDeviceObjects();
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)

	if(m_pConuntFont)
	{
		m_pConuntFont->InvalidateDeviceObjects();
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(m_pCountFont[i])
		{
			m_pCountFont[i]->InvalidateDeviceObjects();
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	
	if(m_pToolTipFont)
	{
		m_pToolTipFont->InvalidateDeviceObjects();
	}

	if(m_pBiddingCountFont)
	{
		m_pBiddingCountFont->InvalidateDeviceObjects();
	}

	if(m_pMsgBox)
	{
		m_pMsgBox->InvalidateDeviceObjects();
	}

	return S_OK;
}

void CINFReturnMyAuctionList::Render()
{
	if(!m_bShowWnd)
	{
		return;
	}

	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->Render();
	}

	if(m_pBiddingCountFont)
	{
		char buf[256] = {0, };
		// 2014-06-12 by ymjoo 파괴 경매장 추가작업
		//wsprintf(buf, "%d", ((CINFReturnAuctionCenter*)m_pParent)->GetBiddingCount());
		int nBiddingCount = 0;
		if(g_pStoreData)
		{
			// 2014-07-09 by ymjoo 파괴 경매장 입찰권 noncountable로 변경
			vector<CItemInfo*> vecItemList;
			g_pStoreData->FindItemInInventoryByItemNumList(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED, &vecItemList);
			for(vector<CItemInfo*>::iterator it = vecItemList.begin() ; it != vecItemList.end() ; ++it)
			{
				++nBiddingCount;
			}
// 			if(g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED))
// 			{
// 				nBiddingCount += g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED)->CurrentCount;
// 			}
			// END 2014-07-09 by ymjoo 파괴 경매장 입찰권 noncountable로 변경
			if(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED != DESTROY_AUCTION_TENDET_ITEM_NUM_UNLIMITED
				&& g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_UNLIMITED))
			{
				nBiddingCount += g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_UNLIMITED)->CurrentCount;
			}
		}
		wsprintf(buf, "%d", nBiddingCount);
		// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
		m_pBiddingCountFont->DrawText(STARTPOS_X + BIDDINGCOUNT_X + (72 / 2 - m_pBiddingCountFont->GetStringSize(buf).cx / 2),
										STARTPOS_Y + BIDDINGCOUNT_Y, GUI_FONT_COLOR_W, buf);	
	}

	ListRender(&m_vecItemInfo);

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->Render();			
		}	
	}
	
	RenderPageCnt();
	
	ToolTipRender();

	if(m_pMsgBox)
	{
		m_pMsgBox->Render();
	}
}

void CINFReturnMyAuctionList::Tick()
{
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	if(!m_bShowWnd)
	{
		return;
	}
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업

	if(m_pMsgBox)
	{
		m_pMsgBox->Tick();
	}

	if(m_fItemCheckTime < 0)
	{
		ListITemCheck();
		m_fItemCheckTime = 10.0f;
	}
	m_fItemCheckTime -= g_pD3dApp->GetElapsedTime();
}

void CINFReturnMyAuctionList::ListITemCheck()
{
	BOOL bDelete = FALSE;
 	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
 	it = m_vecItemInfo.begin();
 
 	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;
 	
 	for( ; it != m_vecItemInfo.end() ; )
 	{
 		pMarketItem = *it;
 		
 		if(!pMarketItem)
		{
 			return;
		}
 
 		ATUM_DATE_TIME pTempTime = pMarketItem->pINFO->DAuctionInfo.DAuctionEndTime;
 
 		if(pTempTime.GetTimeInSeconds() <= 0)
		{
 			++it;
		}
		else
		{	
			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
			CINFReturnAuctionCenter* pParent = (CINFReturnAuctionCenter*)m_pParent;
			char buf[128];
			if(FALSE == pParent->GetRemainTime(pParent->m_DAuctionEndTime, buf)
				&& (AUCTION_ITEM_STATE_END != pMarketItem->pINFO->DAuctionInfo.DAuctionState
					&& AUCTION_ITEM_STATE_COMPLETE != pMarketItem->pINFO->DAuctionInfo.DAuctionState))
			{
				bDelete = TRUE;
				it = m_vecItemInfo.erase(it);
				continue;
			}

			if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState
				&& GetServerDateTime() < pMarketItem->pINFO->DAuctionInfo.DAuctionEndTime)
			{
				bDelete = TRUE;
				it = m_vecItemInfo.erase(it);
				continue;
			}

 			if(pMarketItem->pINFO->DAuctionInfo.CharacterUID == g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
			{
				if(AUCTION_ITEM_STATE_COMPLETE == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
				{
					bDelete = TRUE;
					it = m_vecItemInfo.erase(it);
					continue;
				}
 				pTempTime.AddDateTime(0, 0, 0, DESTROY_AUCTION_GET_POSSIBLE_TIME_HOUR, 0, 0);
			}
 			else
			{
#if defined(TEST140) // 임시
 				pTempTime.AddDateTime(0, 0, 0, 0, 10, 0);
#else
 				pTempTime.AddDateTime(0, 0, 0, 0, DESTROY_AUCTION_RUN_TIME_MINUTE, 0);
#endif
			}
			// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
 
 			if(pTempTime < GetServerDateTime())
 			{
				if(pTempTime < GetServerDateTime())
				{
					if(m_pMsgBox)
					{
						if(m_pMsgBox->GetItemInfo() == pMarketItem)
						{
							++it;
							continue;
						}
					}
				}

				bDelete = TRUE;
 				if(NULL == ((CINFReturnAuctionCenter*)m_pParent)->GetAuctionItemInfo(pMarketItem->pINFO->DAuctionInfo.DAuctionUID))
 				{
 					SAFE_DELETE(pMarketItem->pINFO);
 					SAFE_DELETE(pMarketItem->pItem);
 					SAFE_DELETE(pMarketItem);
 				}
 				it = m_vecItemInfo.erase(it);
 			}
 			else
			{
 				++it;
			}
		}
	}

	// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
	//if(bDelete)
	{
		if(0 < m_vecItemInfo.size())
		{
			m_nMaxScrollPage = m_vecItemInfo.size() / ITEMLIST_ITEMNUM;
			
			if(0 < m_vecItemInfo.size() % ITEMLIST_ITEMNUM)
			{
				++m_nMaxScrollPage;
			}
			
			if(m_nMaxScrollPage < m_nCurrentPage)
			{
				m_nCurrentPage = m_nMaxScrollPage;
			}
		}
		else
		{
			m_nMaxScrollPage = m_nCurrentPage = 1;
		}
		
		UpdateItemListScroll(m_nCurrentPage, m_nStartPage);
	}
}

int CINFReturnMyAuctionList::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(m_pMsgBox)
	{
		int nResult = m_pMsgBox->WndProc(uMsg,wParam,lParam);
		if(nResult != INF_MSGPROC_NORMAL)
		{
			if(nResult == INF_MSGPROC_CLOSE)
			{
				m_pMsgBox->ShowWnd(FALSE);
				m_pMsgBox->SetItemInfo();
			}
			return INF_MSGPROC_BREAK;
		}
	}

	switch(uMsg)
	{
	case WM_MOUSEWHEEL:
		{
			return OnMouseWheel(wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			return OnLButtonDown(wParam, lParam);			
		}
		break;
	case WM_MOUSEMOVE:
		{
			return OnMouseMove(wParam, lParam);
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

int	CINFReturnMyAuctionList::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	
	if(TRUE == ItemListMouseDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	
	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			if(TRUE == ((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonDown(pt))
			{
				return INF_MSGPROC_BREAK;
			}
		}		
	}

	if(INF_MSGPROC_BREAK == OnCilckPageCnt(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnMyAuctionList::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnLButtonUp(pt))
	{
		RefreshBtnDown();
		return INF_MSGPROC_BREAK;
	}
	
	if(TRUE == ItemListMouseUP(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	
	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{		
		if(TRUE == ((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonUp(pt))
		{			
			OnClickPageBtn(nCnt);
			return INF_MSGPROC_BREAK;
		}		
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnMyAuctionList::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnMouseMove(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	ItemListMouseMove(pt);

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->OnMouseMove(pt);				
		}		
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnMyAuctionList::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	
	return INF_MSGPROC_NORMAL;
}

void CINFReturnMyAuctionList::ShowWnd(BOOL bShow)
{
	m_bShowWnd = bShow;
	if(bShow)
	{
		UpdateItemListScroll(1, 1);
	}
	else
	{
	}
}

void CINFReturnMyAuctionList::SetBtnPos()
{
	m_pBackImg->Move(STARTPOS_X + LISTVIEW_START_X, STARTPOS_Y + LISTVIEW_START_Y);
	m_pRefreshBtn->SetBtnPosition(STARTPOS_X + REFRESHBTN_LOCATION_X, STARTPOS_Y + REFRESHBTN_LOCATION_Y);

	{
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage + 1);
		nPageCnt = max(1, nPageCnt);	
		
		int nStartX = STARTPOS_X + PAGEBTN_LOCATION_X;
		int nStartY = STARTPOS_Y + PAGEBTN_LOCATION_Y;
		
		int nTmpPosX = nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][0].x;
		int nTmpPosY = nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][0].y;
		
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_FIRST]->SetBtnPosition(nTmpPosX + PAGEBTN_FIRST_LOCATION_X, nTmpPosY + 2);				
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_PREV]->SetBtnPosition(nTmpPosX + PAGEBTN_PREV_LOCATION_X, nTmpPosY + 2);				
		
		nTmpPosX = nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nPageCnt-1].x;
		nTmpPosY = nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nPageCnt-1].y;
		
		int nTmpNextPosX = nTmpPosX + 16;
		if(m_pConuntFont)
		{
			char chTxt[64] ={0,}; 
			wsprintf(chTxt, "%d", m_nMaxScrollPage);
			SIZE szSize = m_pConuntFont->GetStringSize(chTxt);
			nTmpNextPosX = nTmpPosX + szSize.cx + 8;
		}
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_NEXT]->SetBtnPosition(nTmpNextPosX + PAGEBTN_NEXT_LOCATION_X, nTmpPosY + 2);				
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_LAST]->SetBtnPosition(nTmpNextPosX + PAGEBTN_LAST_LOCATION_X, nTmpPosY + 2);
	}		
}

void CINFReturnMyAuctionList::RefreshBtnDown()
{
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	ATUM_DATE_TIME pTime = m_pLastRefreshTime;
	pTime.AddDateTime(0, 0, 0, 0, 0, 10);
	if(pTime < GetServerDateTime())
	{
		m_pLastRefreshTime = GetServerDateTime();
		g_pFieldWinSocket->SendMsg(T_FC_DESTROY_AUCTION_MY_LIST_REQUEST, NULL, 0);
	}
	else
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "
	}
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

void CINFReturnMyAuctionList::ListRender(vector<AUCTION_MY_ITEM_INFO*>*	vecItemInfo)
{
	int nCnt = 0;
	int nCnt02 = 0;
	char cList[512] = {0, };
	char cTemp[512] = {0, };
	CINFImageEx* pImg = NULL;
	CINFReturnAuctionCenter* pParent = NULL;
	pParent = ((CINFReturnAuctionCenter*)m_pParent);
	
	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;
	
	BOOL bDifferenceCharacterUID = FALSE;
	
	if(vecItemInfo->size() <= 0)
	{
		return;
	}

	if(vecItemInfo->size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
	{
		nCnt02 = vecItemInfo->size() % ITEMLIST_ITEMNUM;
	}
	else
	{
		nCnt02 = ITEMLIST_ITEMNUM;
	}

	
	for(int i = 0 ; i < nCnt02 ; ++i)
	{
		bDifferenceCharacterUID = FALSE;
		// 2014-06-12 by ymjoo 파괴 경매장 추가작업
		if(vecItemInfo->size() <= i + (m_nCurrentPage - 1) * ITEMLIST_ITEMNUM)
		{
			return;
		}
		// END 2014-06-12 by ymjoo 파괴 경매장 추가작업

		pMarketItem = (*vecItemInfo)[i + (m_nCurrentPage - 1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
		{
			return;
		}

		if(pMarketItem->pINFO->DAuctionInfo.CharacterUID != g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
		{
			bDifferenceCharacterUID = TRUE;
		}

		if(FALSE == pParent->GetRemainTime(pParent->m_DAuctionEndTime, cList))
		{
			pMarketItem->pINFO->DAuctionInfo.DAuctionState = AUCTION_ITEM_STATE_END;
		}

		pParent->m_pItemSl->Move(STARTPOS_X + ITEMLIST_ITEMSL_LOCATION_X,
								 STARTPOS_Y + ITEMLIST_ITEMSL_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1));
		pParent->m_pItemSl->Render();
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
		if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			wsprintf(cList, "\\e+%d\\e", pMarketItem->pItem->GetEnchantNumber());
		}
		else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			if(!bDifferenceCharacterUID)
			{
				wsprintf(cList, "\\y+%d\\y", pMarketItem->pItem->GetEnchantNumber());
			}
			else
			{
				wsprintf(cList, "\\r+%d\\r", pMarketItem->pItem->GetEnchantNumber());
			}
		}
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		SIZE sSize = m_pListFont[i][0]->GetStringSize(cList);
		m_pListFont[i][0]->DrawText(STARTPOS_X + ITEMLIST_ENCHANT_LOCATION_X + ITEMLIST_ENCHANT_WIDTH / 2 - sSize.cx / 2,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		SIZE sSize = m_pListFont->GetStringSize(cList);
		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_ENCHANT_LOCATION_X + ITEMLIST_ENCHANT_WIDTH / 2 - sSize.cx / 2,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			wsprintf(cList, "%s", pMarketItem->Name);
		}
		else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			if(!bDifferenceCharacterUID)
			{
				wsprintf(cList, "\\y%s\\y", pMarketItem->Name);
			}
			else
			{
				wsprintf(cList, "\\r%s\\r", pMarketItem->Name);
			}
		}	
		pParent->ChangeMaxLenString(cList, ITEMLIST_MAXITEMNAME_LEN);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][1]->GetStringSize(cList);
		m_pListFont[i][1]->DrawText(STARTPOS_X + ITEMLIST_NAME_LOCATION_X + ITEMLIST_NAME_WIDTH / 2 - sSize.cx / 2,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_NAME_LOCATION_X + ITEMLIST_NAME_WIDTH / 2 - sSize.cx / 2,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			wsprintf(cList,"%d", pMarketItem->pItem->ItemInfo->ReqMinLevel);
		}
		else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			if(!bDifferenceCharacterUID)
			{
				wsprintf(cList, "\\y%d\\y", pMarketItem->pItem->ItemInfo->ReqMinLevel);
			}
			else
			{
				wsprintf(cList, "\\r%d\\r", pMarketItem->pItem->ItemInfo->ReqMinLevel);
			}
		}
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][2]->GetStringSize(cList);
		m_pListFont[i][2]->DrawText(STARTPOS_X + ITEMLIST_LEVEL_LOCATION_X + ITEMLIST_LEVEL_WIDTH / 2 - sSize.cx / 2,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_LEVEL_LOCATION_X + ITEMLIST_LEVEL_WIDTH / 2 - sSize.cx / 2,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		if(FALSE == pParent->GetRemainTime(pParent->m_DAuctionEndTime, cList)
			|| AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			if(!bDifferenceCharacterUID)
			{
				wsprintf(cList, "\\y%s\\y", STRMSG_C_140121_0001);
			}
			else
			{
				wsprintf(cList, "\\r%s\\r", STRMSG_C_140121_0001);
			}
		}
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][3]->GetStringSize(cList);
		m_pListFont[i][3]->DrawText(STARTPOS_X + ITEMLIST_REGISTTIME_LOCATION_X + ITEMLIST_REGISTTIME_WIDTH / 2 - sSize.cx / 2,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_REGISTTIME_LOCATION_X + ITEMLIST_REGISTTIME_WIDTH / 2 - sSize.cx / 2,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		wsprintf(cList, "%d", pMarketItem->pINFO->DAuctionInfo.Price);
		MakeCurrencySeparator(cTemp, cList, 3, ',');
		ZeroMemory(cList, sizeof(cList));
		if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			strncpy(cList, cTemp, strlen(cTemp));
		}
		else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			if(!bDifferenceCharacterUID)
			{
				wsprintf(cList, "\\y%s\\y", cTemp);
			}
			else
			{
				wsprintf(cList, "\\r%s\\r", cTemp);
			}
		}
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][4]->GetStringSize(cList);
		m_pListFont[i][4]->DrawText(STARTPOS_X + ITEMLIST_PRICE_LOCATION_X + ITEMLIST_PRICE_WIDTH - sSize.cx,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_PRICE_LOCATION_X + ITEMLIST_PRICE_WIDTH - sSize.cx,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		if(bDifferenceCharacterUID)
		{
			if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				wsprintf(cList, STRMSG_C_140121_0005);	// "\\r상회 입찰중\\r"
			}
			else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				wsprintf(cList, STRMSG_C_140121_0016);	// "\\r상회 입찰됨\\r"
			}
		}
		else
		{
			if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				wsprintf(cList, STRMSG_C_140121_0004);	// "최고가 입찰중"
			}
			else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				wsprintf(cList, STRMSG_C_140121_0006);	// "\\y낙찰됨\\y"
			}
		}
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[i][5]->GetStringSize(cList);
		m_pListFont[i][5]->DrawText(STARTPOS_X + 771 + 73 / 2 - sSize.cx / 2,
									STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
									GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X + 771 + 73 / 2 - sSize.cx / 2,
 							  STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2 - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 							  GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		if(_SPI == pMarketItem->pINFO->DAuctionInfo.MoneyType)
		{
			pImg  = pParent->m_pMoneyImg[_SPI];
		}
		else if(_WP == pMarketItem->pINFO->DAuctionInfo.MoneyType)
		{
			pImg  = pParent->m_pMoneyImg[_WP];
		}
		
		if(pImg)
		{
			pImg->Move(STARTPOS_X + ITEMLIST_MONEYTYPE_LOCATION_X,
					   STARTPOS_Y + ITEMLIST_MONEYTYPE_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1));
			pImg->Render();
		}
		
		if(m_pIconInfo)
		{
			char chIconName[64] = {0, };	
			if(!pMarketItem->pItem->ShapeItemNum)
			{
				wsprintf(chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
			}
			else
			{
				ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(pMarketItem->pItem->ShapeItemNum);
				if(pShapeItem)
				{
					wsprintf(chIconName, "%08d", pShapeItem->SourceIndex);
				}
				else
				{
					wsprintf(chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
				}
			}		
			
			m_pIconInfo->SetIcon(chIconName,
								STARTPOS_X + ITEMLIST_ICON_LOCATION_X,
								STARTPOS_Y + ITEMLIST_ICON_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1), 1.0f);
			m_pIconInfo->Render();
			
			if(IS_COUNTABLE_ITEM(pMarketItem->pItem->Kind))
			{
				if(1 < pMarketItem->pINFO->DAuctionInfo.ItemCount)
				{
					wsprintf(cList, "%d", pMarketItem->pINFO->DAuctionInfo.ItemCount);
					// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
					int itemCntStrLen = m_pListFont[i][6]->GetStringSize(cList).cx;
					m_pListFont[i][6]->DrawText(STARTPOS_X + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen,
												STARTPOS_Y + ITEMLIST_ICON_LOCATION_Y + ITEMLIST_ITEMCNT_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
												QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#else
 					int itemCntStrLen = m_pListFont->GetStringSize(cList).cx;
 					m_pListFont->DrawText(STARTPOS_X + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen,
 										  STARTPOS_Y + ITEMLIST_ICON_LOCATION_Y + ITEMLIST_ITEMCNT_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
 										  QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#endif
					// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
				}
			}
		}
		
		if(bDifferenceCharacterUID)
		{
			if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				pImg = pParent->m_pBiddingImg[pMarketItem->byBtnState];		//경매시작 + 다른사람 입찰
			}
			else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				pImg = pParent->m_pMoneyNoGetImg[pMarketItem->byBtnState];	//경매끝 + 다른사람이 낙찰
			}
		}
		else
		{
			if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				pImg = pParent->m_pBiddingImg[2];							//경매시작 + 내가 입찰
			}
			else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
			{
				pImg = pParent->m_pMoneyGetImg[pMarketItem->byBtnState];	//경매끝 + 내가 낙찰
			}
		}

		pImg->Move(STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X,
				   STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1));
		pImg->Render();
	
		++nCnt;
	}
}

void CINFReturnMyAuctionList::ToolTipRender()
{
	if(0 == m_nToolTipState || AUCTION_START_MY_ITEM == m_nToolTipState)
	{
		return;
	}
	
	char buf[128] = {0, };
	int nX = m_ptToolTipPos.x;
	
	if(AUCTION_START_NO_ITEM == m_nToolTipState)
	{
		wsprintf(buf, STRMSG_C_140121_0007);	// "재입찰"
	}
	else if(AUCTION_END_MY_ITEM == m_nToolTipState)
	{
		wsprintf(buf, STRMSG_C_140121_0008);	// "물품회수"
	}

	else if(AUCTION_END_NO_ITEM == m_nToolTipState)
	{
		wsprintf(buf, STRMSG_C_140121_0009);	// "결과확인"
	}

	int leng = m_pToolTipFont->GetStringSize(buf).cx + 4;
	
	if(g_pD3dApp->GetBackBufferDesc().Width < nX + leng)
	{
		nX = g_pD3dApp->GetBackBufferDesc().Width - leng;
	}
	g_pGameMain->RenderPopUpWindowImage(nX, m_ptToolTipPos.y + TOOLTIP_POSITION_Y, leng, 1);
	m_pToolTipFont->DrawText(nX + 1, m_ptToolTipPos.y + TOOLTIP_POSITION_Y - 2, GUI_FONT_COLOR_W, buf);
}

void CINFReturnMyAuctionList::ItemListMouseMove(POINT pt)
{
	m_nToolTipState = 0;
	{	
		int nCnt = 0;
		int nCnt02 = 0;
		CINFReturnAuctionCenter* pParent = NULL;
		pParent = (CINFReturnAuctionCenter*)m_pParent;
		
		AUCTION_MY_ITEM_INFO* pMarketItem = NULL;

		BOOL bDifferenceCharacterUID = FALSE;
		
		if(m_vecItemInfo.size() <= 0)
		{
			return;
		}
		
		if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
		{
			nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
		}
		else
		{
			nCnt02 = ITEMLIST_ITEMNUM;
		}
		
		for(int i = 0 ; i < nCnt02 ; ++i)
		{
			bDifferenceCharacterUID = FALSE;
			pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage - 1) * ITEMLIST_ITEMNUM];

			if(pMarketItem->pINFO->DAuctionInfo.CharacterUID != g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
			{
				bDifferenceCharacterUID = TRUE;
			}

			if(!pMarketItem)
			{
				return;
			}
			
			if(STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X < pt.x
				&& pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x
				&& STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) < pt.y
				&& pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
			{
				if(BTN_STATUS_DOWN != pMarketItem->byBtnState)
				{
					pMarketItem->byBtnState = BTN_STATUS_UP;
				}
				
				memcpy(&m_ptToolTipPos, &pt, sizeof(POINT));
				
				if(bDifferenceCharacterUID)
				{
					if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
					{
						m_nToolTipState = AUCTION_START_NO_ITEM;
					}
					else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
					{
						m_nToolTipState = AUCTION_END_NO_ITEM;
					}
				}
				else
				{
					if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
					{
						m_nToolTipState = AUCTION_START_MY_ITEM;
					}
					else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
					{
						m_nToolTipState = AUCTION_END_MY_ITEM;
					}
				}
				
			}
			else
			{
				pMarketItem->byBtnState = BTN_STATUS_UP;
			}
			
			++nCnt;
		}
	}
	
	int nTemp = -1;
	if(STARTPOS_X + ITEMLIST_LOCATION_X < pt.x && pt.x < STARTPOS_X + ITEMLIST_LOCATION_X + ITEMLIST_ITEM_WIDTH
		&& STARTPOS_Y + ITEMLIST_LOCATION_Y - 1 < pt.y && pt.y < STARTPOS_Y + ITEMLIST_LOCATION_Y - 1 + ITEMLIST_HEIGHT)
	{
		nTemp = (((pt.y - STARTPOS_Y - ITEMLIST_LOCATION_Y - 1) / (ITEMLIST_CELL_HEIGHT + 1)) + ((m_nCurrentPage - 1) * ITEMLIST_ITEMNUM)) + 1;
		if(nTemp <= m_vecItemInfo.size())
		{
			if(m_nCurerntInfo != m_vecItemInfo[nTemp-1]->pItem)
			{
				g_pGameMain->SetItemInfoUser(m_vecItemInfo[nTemp-1]->pItem, pt.x, pt.y);
			}
			m_nCurerntInfo = m_vecItemInfo[nTemp-1]->pItem;
		}
		else
		{
			m_nCurerntInfo = NULL;
		}
	}
	else
	{
		m_nCurerntInfo = NULL;
	}
	
	if(!m_nCurerntInfo)
	{
		g_pGameMain->SetItemInfoUser(NULL, 0, 0);
	}
}

BOOL CINFReturnMyAuctionList::ItemListMouseDown(POINT pt)
{
	int nCnt = 0;
	int nCnt02 = 0;
	CINFReturnAuctionCenter* pParent = NULL;
	pParent = (CINFReturnAuctionCenter*)m_pParent;
	
	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() <= 0)
	{
		return FALSE;
	}
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
	{
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	}
	else
	{
		nCnt02 = ITEMLIST_ITEMNUM;
	}
	
	for(int i = 0 ; i < nCnt02 ; ++i)
	{
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage - 1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
		{
			return FALSE;	
		}
		
		if(STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X < pt.x
			&& pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x
			&& STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) < pt.y
			&& pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
		{
			pMarketItem->byBtnState = BTN_STATUS_DOWN;
			return TRUE;
		}		
		++nCnt;
	}
	return FALSE;
}

BOOL CINFReturnMyAuctionList::ItemListMouseUP(POINT pt)
{
	int nCnt = 0;
	int nCnt02 = 0;
	CINFReturnAuctionCenter* pParent = NULL;
	pParent = ((CINFReturnAuctionCenter*)m_pParent);
	
	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;
	
	if(m_vecItemInfo.size() <= 0)
	{
		return FALSE;
	}
	
	if(m_vecItemInfo.size() < m_nCurrentPage * ITEMLIST_ITEMNUM)
	{
		nCnt02 = m_vecItemInfo.size() % ITEMLIST_ITEMNUM;
	}
	else
	{
		nCnt02 = ITEMLIST_ITEMNUM;
	}
	
	for(int i = 0 ; i < nCnt02 ; ++i)
	{
		pMarketItem	= m_vecItemInfo[i + (m_nCurrentPage - 1) * ITEMLIST_ITEMNUM];
		
		if(!pMarketItem)
		{
			return FALSE;
		}
		
		if(STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X < pt.x
			&& pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x
			&& STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) < pt.y
			&& pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
		{
			if(pMarketItem->byBtnState == BTN_STATUS_DOWN)
			{
				pMarketItem->byBtnState = BTN_STATUS_UP;	//버튼 클릭
				StateBtnDown(pMarketItem);
				m_nToolTipState = 0;
			}
			return TRUE;
		}
		++nCnt;
	}
	return FALSE;
}

void CINFReturnMyAuctionList::RenderPageCnt()
{
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	if(NULL == m_pCountFont)
	{
		return;
	}
#else
	if(NULL == m_pConuntFont)	
	{
		return;
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)

	int nStartX = STARTPOS_X + PAGEBTN_LOCATION_X;
	int nStartY = STARTPOS_Y + PAGEBTN_LOCATION_Y;
	
	int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage + 1);
	nPageCnt = max(1, nPageCnt);
	
	char chTxt[64];				
	for(int nCnt = 0 ; nCnt < nPageCnt ; ++nCnt)
	{
		if(-1 == ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].x)
		{
			break;
		}

		DWORD dwColor = GUI_FONT_COLOR_W;
		int nShowPage = m_nStartPage + nCnt;
		if(nShowPage == m_nCurrentPage)
		{
			dwColor = GUI_FONT_COLOR_Y;
		}
		wsprintf(chTxt, "%d", nShowPage);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		m_pCountFont[nCnt]->DrawText(nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt  -1][nCnt].x,
									 nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].y,
									 dwColor, chTxt);
#else
 		m_pConuntFont->DrawText(nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt  -1][nCnt].x,
 								nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].y,
 								dwColor, chTxt);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (경매장)
	}
}

void CINFReturnMyAuctionList::OnClickPageBtn(int nPageMode)
{
	switch(nPageMode)
	{
	case PAGE_BTN_FIRST:
		{			
			//첫페이지로
			UpdateItemListScroll(1, 1);
		}
		break;
	case PAGE_BTN_PREV:
		{
			int	nStartPage = m_nStartPage - MAX_SEARCH_PAGE;	// 현재 그림의 시작 페이지
			int	nCurrentPage = m_nCurrentPage;					// 현재 보고 있는 페이지
			if(nStartPage <= 0)
			{
				// 10페이지 씩이동하는데 10페이지보다 작다
				return;
			}			
			UpdateItemListScroll(nStartPage, nStartPage);
		}
		break;
	case PAGE_BTN_NEXT:
		{
			int	nStartPage = m_nStartPage + MAX_SEARCH_PAGE;	// 현재 그림의 시작 페이지
			int	nCurrentPage = m_nCurrentPage;					// 현재 보고 있는 페이지
			if(m_nMaxScrollPage < nStartPage)
			{
				// 10페이지 씩이동하는데 10페이지보다 작다
				return;
			}			
			UpdateItemListScroll(nStartPage, nStartPage);
		}
		break;
	case PAGE_BTN_LAST:
		{
			int	nCap = max(0, m_nMaxScrollPage - m_nStartPage);	// 현재 그림의 시작 페이지
			if(nCap <= 0)
			{
				return;
			}
			int	nAddPage = nCap / MAX_SEARCH_PAGE;				// 현재 보고 있는 페이지
			int	nStartPage = m_nStartPage + (nAddPage * MAX_SEARCH_PAGE);
			UpdateItemListScroll(m_nMaxScrollPage, nStartPage);
		}
		break;
	default:
		{
			return;
		}
		break;
	}
}

void CINFReturnMyAuctionList::UpdateItemListScroll(int nCurrentPage, int nStartPage)
{
	m_nCurrentPage = nCurrentPage;	
	m_nStartPage = nStartPage;	
	
	SetBtnPos();
}

int CINFReturnMyAuctionList::OnCilckPageCnt(POINT ptPos)
{
	int nStartX = STARTPOS_X + PAGEBTN_LOCATION_X;
	int nStartY = STARTPOS_Y + PAGEBTN_LOCATION_Y;
	
	int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage - m_nStartPage + 1);
	nPageCnt = max(1, nPageCnt);
	
	for(int nCnt = 0 ; nCnt < nPageCnt ; ++nCnt)
	{		
		int nTmpPosX = nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].x;
		int nTmpPosY = nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].y;
		
		if(nTmpPosY <= ptPos.y && ptPos.y <= nTmpPosY + PAGE_LIST_HEIGHT
			&& nTmpPosX <= ptPos.x && ptPos.x <= nTmpPosX + PAGE_LIST_WIDTH)
		{
			int nCurrentPage = m_nStartPage+nCnt;
			UpdateItemListScroll(nCurrentPage, m_nStartPage);
			
			return INF_MSGPROC_BREAK;	
		}
	}
	return INF_MSGPROC_NORMAL;	
}

void CINFReturnMyAuctionList::StateBtnDown(AUCTION_MY_ITEM_INFO* pMarketItem)
{
	if(!pMarketItem)
	{
		return;
	}

	if(NULL != m_pMsgBox)
	{
		m_pMsgBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMsgBox);
	}

	m_pMsgBox = new CINFReturnAuctionMsgBox();
	
	BOOL bDifferenceCharacterUID = FALSE;

	if(pMarketItem->pINFO->DAuctionInfo.CharacterUID != g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
	{
		bDifferenceCharacterUID = TRUE;
	}

	if(bDifferenceCharacterUID)
	{
		if(AUCTION_ITEM_STATE_START == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{	
			m_pMsgBox->InitDeviceObjects("ra_tender", pMarketItem, BIDDING, m_pParent);
			m_pMsgBox->RestoreDeviceObjects();
			m_pMsgBox->ShowWnd(TRUE);
		}
		else if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			m_pMsgBox->InitDeviceObjects("ra_tenfail", pMarketItem, FAILGETITEM, m_pParent);
			m_pMsgBox->RestoreDeviceObjects();
			m_pMsgBox->ShowWnd(TRUE);
		}
	}
	else
	{
		if(AUCTION_ITEM_STATE_END == pMarketItem->pINFO->DAuctionInfo.DAuctionState)
		{
			m_pMsgBox->InitDeviceObjects("ra_tensucc", pMarketItem, GETITEM, m_pParent);
			m_pMsgBox->RestoreDeviceObjects();
			m_pMsgBox->ShowWnd(TRUE);
		}
	}
}

void CINFReturnMyAuctionList::PushMyList(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg)
{
	AUCTION_MY_ITEM_INFO* pData = NULL;
	CINFReturnAuctionCenter* pParent = (CINFReturnAuctionCenter*)m_pParent;
	pData = pParent->GetAuctionItemInfo(pMsg);
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
	//pParent->m_nBiddingCount--;

	if(NULL == pData)
	{
		return;
	}

	if(FALSE == pParent->GetFistMyViewTapClick())
	{
//		m_vecTempIteminfo.push_back(pData);		// 2014-07-17 by ymjoo 파괴경매장 코드개선 (주석처리)
//		g_pFieldWinSocket->SendMsg( T_FC_DESTROY_AUCTION_MY_LIST_REQUEST, NULL , 0);
	}
	else
	{
		if(FALSE == CompareData(pData))
		{
			m_vecItemInfo.push_back(pData);
		}
	}
	//소트가 들어가야 할 수도 있음 ;
}

void CINFReturnMyAuctionList::VecItemInfoClear()
{
//	m_bRenderState = FALSE;
	m_nCurrentPage = 1;
	m_nMaxScrollPage = 1; 
	m_nStartPage = 1;
	SetBtnPos();

	if(0 < m_vecItemInfo.size())
	{
		vector<AUCTION_MY_ITEM_INFO*>::iterator it;
		for(it = m_vecItemInfo.begin() ; it != m_vecItemInfo.end() ; )
		{
			AUCTION_MY_ITEM_INFO* pMarketItem = *it;
			if(pMarketItem)
			{
				if(NULL == ((CINFReturnAuctionCenter*)m_pParent)->GetAuctionItemInfo(pMarketItem->pINFO->DAuctionInfo.DAuctionUID))
				{
					SAFE_DELETE(pMarketItem->pINFO);
					SAFE_DELETE(pMarketItem->pItem);
					SAFE_DELETE(pMarketItem);
				}
				it = m_vecItemInfo.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	
	if(0 < m_vecItemInfo.size())
	{
		if(false == m_vecItemInfo.empty())
		{
			m_vecItemInfo.clear();
		}
	}
}

void CINFReturnMyAuctionList::ItemVecAdd(MSG_FC_DESTROY_AUCTION_MY_LIST_OK* pMsg)
{
	CINFReturnAuctionCenter* pParent = NULL;
	AUCTION_MY_ITEM_INFO* pTemp = NULL;
	pParent = (CINFReturnAuctionCenter*)m_pParent;

	pTemp = pParent->GetAuctionItemInfo(pMsg->DAuctionInfo.DAuctionUID);

	if(NULL == pTemp || pParent->m_DAuctionEndTime < GetServerDateTime())
	{
		pTemp = new AUCTION_MY_ITEM_INFO;
		pTemp->pINFO = new MSG_FC_DESTROY_AUCTION_BASE_INFO_OK;
		ITEM_GENERAL* pITEMG = new ITEM_GENERAL;
		
		memset(pITEMG, 0x00, sizeof(ITEM_GENERAL));
		memset(pTemp->pINFO, 0x00, sizeof(MSG_FC_DESTROY_AUCTION_BASE_INFO_OK));
		memcpy(pTemp->pINFO, pMsg, sizeof(MSG_FC_DESTROY_AUCTION_BASE_INFO_OK));
		
		pITEMG->PrefixCodeNum	= pMsg->DAuctionInfo.PrefixCodeNum;
		pITEMG->SuffixCodeNum	= pMsg->DAuctionInfo.SuffixCodeNum;
		pITEMG->UniqueNumber	= pMsg->DAuctionInfo.ItemUID;
		pITEMG->ShapeItemNum	= pMsg->DAuctionInfo.ShapeItemNum;
		
		pITEMG->UniqueNumber	= pMsg->DAuctionInfo.ItemUID;
		pITEMG->ItemNum			= pMsg->DAuctionInfo.ItemNum;
		pITEMG->CurrentCount	= pMsg->DAuctionInfo.ItemCount;
		
		pITEMG->PrefixCodeNum	= pMsg->DAuctionInfo.PrefixCodeNum;
		pITEMG->SuffixCodeNum	= pMsg->DAuctionInfo.SuffixCodeNum;
		pITEMG->ShapeItemNum	= pMsg->DAuctionInfo.ShapeItemNum;
		pITEMG->ColorCode		= pMsg->DAuctionInfo.ColorCode;
		
		pTemp->pItem = new CItemInfo(pITEMG);
		
		for(int i = 0 ; i < 8 ; ++i)
		{
			for(int j = 0 ; j < pMsg->DAuctionInfo.Enchant[i].Count ; ++j)
			{
				pTemp->pItem->AddEnchantItem(pMsg->DAuctionInfo.Enchant[i].ItemNum);
			}
		}
		pTemp->pItem->Kind = pTemp->pItem->ItemInfo->Kind;
		
		pParent->GetItemName(pTemp->pItem, pTemp->Name, FALSE);		
	}
	if(pTemp != NULL)
	{
		m_vecItemInfo.push_back(pTemp);
	}
}

void CINFReturnMyAuctionList::MyItemListDone()
{
	// 2014-09-04 by ymjoo 컴파일 경고 제거 작업
// 	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
// 	AUCTION_MY_ITEM_INFO* pData = NULL;
	// END 2014-09-04 by ymjoo 컴파일 경고 제거 작업
	// 2014-07-17 by ymjoo 파괴경매장 코드개선 (주석처리)
// 	if(0 < m_vecTempIteminfo.size())
// 	{
// 		it = m_vecTempIteminfo.begin();
// 		for( ; it != m_vecTempIteminfo.end() ; ++it)
// 		{
// 			pData = *it;
// 			if(FALSE == CompareData(pData))
// 			{
// 				m_vecItemInfo.push_back(pData);
// 			}
// 		}
// 	}
// 
// 	m_vecTempIteminfo.clear();
	// END 2014-07-17 by ymjoo 파괴경매장 코드개선 (주석처리)
	((CINFReturnAuctionCenter*)m_pParent)->SetFistMyViewTapClick(TRUE);
	
	if(0 < m_vecItemInfo.size())
	{
		m_nMaxScrollPage = m_vecItemInfo.size() / ITEMLIST_ITEMNUM;
		
		if(0 < m_vecItemInfo.size() % ITEMLIST_ITEMNUM)
		{
			++m_nMaxScrollPage;
		}
		
		if(m_nMaxScrollPage < m_nCurrentPage)
		{
			m_nCurrentPage = m_nMaxScrollPage;
		}
	}
	else
	{
		m_nMaxScrollPage = m_nCurrentPage = 1;
	}
	
	UpdateItemListScroll(m_nCurrentPage, m_nStartPage);
	
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	ListITemCheck();
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

BOOL CINFReturnMyAuctionList::CompareData(AUCTION_MY_ITEM_INFO* pData)
{
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	AUCTION_MY_ITEM_INFO* pTempData = NULL;
	it = m_vecItemInfo.begin();
	for( ; it != m_vecItemInfo.end() ; ++it)
	{
		pTempData = *it;

		if(pTempData->pINFO->DAuctionInfo.DAuctionUID == pData->pINFO->DAuctionInfo.DAuctionUID)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void CINFReturnMyAuctionList::MyAuctionGetOk(MSG_FC_DESTROY_AUCTION_GET_OK* pMsg)
{
	if(0 < m_vecItemInfo.size())
	{
		vector<AUCTION_MY_ITEM_INFO*>::iterator it;
		for(it = m_vecItemInfo.begin() ; it != m_vecItemInfo.end() ; )
		{
			AUCTION_MY_ITEM_INFO* pMarketItem = *it;
			if(pMarketItem)
			{
				if(pMarketItem->pINFO->DAuctionInfo.DAuctionUID == pMsg->DAuctionUID)
				{
					if(NULL == ((CINFReturnAuctionCenter*)m_pParent)->GetAuctionItemInfo(pMarketItem->pINFO->DAuctionInfo.DAuctionUID))
					{
						SAFE_DELETE(pMarketItem->pINFO);
						SAFE_DELETE(pMarketItem->pItem);
						SAFE_DELETE(pMarketItem);
					}
					it = m_vecItemInfo.erase(it);
				}
				else
				{
					++it;
				}
			}
		}
	}
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	ListITemCheck();
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
}