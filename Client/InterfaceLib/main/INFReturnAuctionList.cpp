// INFReturnAuctionList.cpp: implementation of the CINFReturnAuctionList class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "INFWindow.h"
#include "ItemInfo.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFIcon.h"
#include "INFImageListTreeCtrl.h"	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
#include "INFReturnAuctionMsgBox.h"
#include "INFReturnAuctionList.h"
#include "StoreData.h"				// 2014-06-12 by ymjoo 파괴 경매장 추가작업
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
//#include "INFImageList.h"
//#include "INFItemInfo.h"
//#include "INFImageListCtrl.h"
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

enum AUCTION_ITEM_KIND
{
	_ALLITEM = 0,
	_WEAPON,
	_PRIMARY_WEAPON,
	_SECONDARY_WEAPON,
	_DEFENSE,
	_SUPPORT,
	_ENGIN,						//엔진
	_RADAR,
	_ACCESSORY_UNLIMITED		//무제한 아이템 
};

#define	TOTALITEMCNT_LOCATION_X				875				//아이템수 글자 X 좌표
#define	TOTALITEMCNT_LOCATION_Y				186				//아이템수 글자 Y 좌표
#define	REFRESHBTN_LOCATION_X				879				//새로고침 버튼 x
#define	REFRESHBTN_LOCATION_Y				182				//새로고침 버튼 Y
#define PAGE_ITEM_COUNT						8

// 아이템 리스트
#define ITEMLIST_ITEMNUM					8
#define ITEMLIST_LOCATION_X					219
#define ITEMLIST_LOCATION_Y					230
#define ITEMLIST_CELL_HEIGHT				40
#define ITEMLIST_WIDTH						684
#define ITEMLIST_HEIGHT						328
#define ITEMLIST_ITEMSL_LOCATION_X			235
#define ITEMLIST_ITEMSL_LOCATION_Y			235
#define ITEMLIST_ICON_LOCATION_X			236
#define ITEMLIST_ICON_LOCATION_Y			236
#define ITEMLIST_ITEMCNT_LOCATION_X			26
#define ITEMLIST_ITEMCNT_LOCATION_Y			-2
#define ITEMLIST_ITEM_WIDTH					58
#define ITEMLIST_ENCHANT_LOCATION_X			279
#define ITEMLIST_ENCHANT_WIDTH				58
#define ITEMLIST_NAME_LOCATION_X			338
#define ITEMLIST_NAME_WIDTH					280
#define ITEMLIST_LEVEL_LOCATION_X			619
#define ITEMLIST_LEVEL_WIDTH				58
#define ITEMLIST_REGISTTIME_LOCATION_X		678
#define ITEMLIST_REGISTTIME_WIDTH			73
#define ITEMLIST_PRICE_LOCATION_X			752
#define ITEMLIST_PRICE_WIDTH				91
#define ITEMLIST_MONEYTYPE_LOCATION_X		847
#define ITEMLIST_MONEYTYPE_LOCATION_Y		241
#define ITEMLIST_BIDDINGIMG_LOCATION_X		861
#define ITEMLIST_BIDDINGIMG_LOCATION_Y		231
#define ITEMLIST_MAXITEMNAME_LEN			45

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
//입찰 버튼 
#define BIDDINGBTN_LOCATION_X				595	
#define BIDDINGBTN_LOCATION_Y				92
/////////////////////////////////////////////////////
//남은 입찰 휫수 
#define BIDDINGCOUNT_X						473
#define BIDDINGCOUNT_Y						118


CINFReturnAuctionList::CINFReturnAuctionList(CAtumNode* parent)
{
	m_pParent = parent;
	m_pBackImg = NULL;
	m_bShowWnd = FALSE;
	m_nTotalItemCount = 0;
	m_pTotalItemCountFont = NULL;
	m_pListFont = NULL;
	m_pRefreshBtn = NULL;
//	m_pScroll = NULL;
	m_pIconInfo = NULL;
	m_pReturnAuctionCenter = NULL;
	m_pListTreeCtrl = NULL;		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선							 
	//m_pListCtrl = NULL;
	m_byOrgKind = -1;
	m_pToolTipFont = NULL;
	m_nCurrentPage = 1;	
	m_nStartPage = 1;
	m_nMaxScrollPage = 1;
	m_pConuntFont = NULL;
	m_nSelectListItem = -1;
	m_pSelectImg = NULL;
	m_pBiddingBtn = NULL;
	m_pBiddingCountFont = NULL;
	m_pMsgBox = NULL;
	m_bRenderState = FALSE;

	m_pLastRefreshTime = GetServerDateTime();			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	m_pLastRefreshTime.AddDateTime(0, 0, 0, 0, 0, -10);	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

CINFReturnAuctionList::~CINFReturnAuctionList()
{
	SAFE_DELETE(m_pTotalItemCountFont);
	SAFE_DELETE(m_pListFont);
	SAFE_DELETE(m_pRefreshBtn);
//	SAFE_DELETE(m_pScroll);
	SAFE_DELETE(m_pBackImg)
	SAFE_DELETE(m_pListTreeCtrl);		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	//SAFE_DELETE(m_pListCtrl);
	SAFE_DELETE(m_pToolTipFont);
	SAFE_DELETE(m_pConuntFont);
	SAFE_DELETE(m_pSelectImg);
	SAFE_DELETE(m_pBiddingBtn);
	SAFE_DELETE(m_pBiddingCountFont);
	SAFE_DELETE(m_pMsgBox);
}

HRESULT CINFReturnAuctionList::InitDeviceObjects()
{
	DataHeader* pDataHeader = NULL;

	if(NULL == m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);		
		m_pTotalItemCountFont->InitDeviceObjects(g_pD3dDev) ;
	}
	
	if(NULL == m_pListFont)
	{
		m_pListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
		m_pListFont->InitDeviceObjects(g_pD3dDev);
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

// 	if(NULL == m_pScroll)
// 	{
// 		m_pScroll = new CINFArenaScrollBar;
// 		m_pScroll->InitDeviceObjects(PAGE_ITEM_COUNT,"c_scrlb");
// 		//m_pScroll->SetMaxItem(1);
// 	}

	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("ra_parti");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage(pDataHeader);
		m_pBackImg->InitDeviceObjects(g_pD3dApp->m_pImageList);		
	}

	{
		char chPlus[30], chMinus[30], chItem[30], chSel[30];
		wsprintf(chPlus, "m_plus");
		wsprintf(chMinus, "m_minus");
		wsprintf(chItem, "misradn");
		wsprintf(chSel, "tc_catesel");

		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
		if(NULL == m_pListTreeCtrl)
		{
			m_pListTreeCtrl = new CINFImageListTreeCtrl();
		}
		m_pListTreeCtrl->InitDeviceObjects(20);
		m_pListTreeCtrl->InitDeviceEtc(chPlus, chMinus, chItem, chSel);
		m_pListTreeCtrl->SetTextList(TRUE);
//		if(NULL == m_pListCtrl)
//		{
//			m_pListCtrl = new CINFImageListCtrl();
//		}
//		m_pListCtrl->InitDeviceObjects(20);
//		m_pListCtrl->InitDeviceEtc(chPlus, chMinus, chItem, chSel);
//		m_pListCtrl->SetTextList(TRUE);
		// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	}

	if(NULL == m_pToolTipFont)
	{
		m_pToolTipFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 128, 32);
		m_pToolTipFont->InitDeviceObjects(g_pD3dDev);
	}

	if(NULL == m_pConuntFont)
	{
		m_pConuntFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 1024, 32);
		m_pConuntFont->InitDeviceObjects(g_pD3dDev);
	}

	if(NULL == m_pBiddingCountFont)
	{
		//m_pBiddingCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),16, D3DFONT_ZENABLE | D3DFONT_BOLD, TRUE,1024,32);
		m_pBiddingCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 16, D3DFONT_ZENABLE, TRUE, 1024, 32);
		m_pBiddingCountFont->InitDeviceObjects(g_pD3dDev);
	}

	if(g_pGameMain)
	{
		pDataHeader = g_pGameMain->FindResource("tc_listsel");
	}

	if(pDataHeader)
	{
		if(NULL == m_pSelectImg)
		{
			m_pSelectImg = new CINFImageEx();
			m_pSelectImg->InitDeviceObjects(pDataHeader);
		}
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "ra_ten03");
		wsprintf(szDownBtn, "ra_ten01");
		wsprintf(szSelBtn, "ra_ten00");
		wsprintf(szDisBtn, "ra_ten02");
		if(NULL == m_pBiddingBtn)
		{
			m_pBiddingBtn = new CINFImageBtn;
		}
		m_pBiddingBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}

	m_pIconInfo = g_pGameMain->m_pIcon;

	return S_OK;
}

HRESULT CINFReturnAuctionList::RestoreDeviceObjects()
{
	if(m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont->RestoreDeviceObjects();
	}
	
	if(m_pListFont)
	{
		m_pListFont->RestoreDeviceObjects();
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->RestoreDeviceObjects();
	}

// 	if(m_pScroll)
// 		m_pScroll->RestoreDeviceObjects();

	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
	}

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->RestoreDeviceObjects();
	}
//	if(m_pListCtrl)
//		m_pListCtrl->RestoreDeviceObjects();
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선

	if(m_pToolTipFont)
	{
		m_pToolTipFont->RestoreDeviceObjects();
	}

	if(m_pConuntFont)
	{
		m_pConuntFont->RestoreDeviceObjects();
	}

	if(m_pSelectImg)
	{
		m_pSelectImg->RestoreDeviceObjects();
	}

	if(m_pBiddingBtn)
	{
		m_pBiddingBtn->RestoreDeviceObjects();
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

HRESULT CINFReturnAuctionList::DeleteDeviceObjects()
{
	if(m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pTotalItemCountFont);
	}

	if(m_pListFont)
	{
		m_pListFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pListFont);
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pRefreshBtn);
	}

// 	if(m_pScroll)
// 	{
// 		m_pScroll->DeleteDeviceObjects();
// 		SAFE_DELETE(m_pScroll);
// 	}

	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->DeleteDeviceObjects();
		SAFE_DELETE(m_pListTreeCtrl);
	}
//	if(m_pListCtrl)
//	{
//		m_pListCtrl->DeleteDeviceObjects();
//		SAFE_DELETE(m_pListCtrl)
//	}
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선

	if(m_pToolTipFont)
	{
		m_pToolTipFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipFont);
	}

	if(m_pConuntFont)
	{
		m_pConuntFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pConuntFont);
	}

	if(m_pSelectImg)
	{
		m_pSelectImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pSelectImg);
	}

	if(m_pBiddingBtn)
	{
		m_pBiddingBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pBiddingBtn);
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

HRESULT CINFReturnAuctionList::InvalidateDeviceObjects()
{
	if(m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont->InvalidateDeviceObjects();
	}
	
	if(m_pListFont)
	{
		m_pListFont->InvalidateDeviceObjects();
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->InvalidateDeviceObjects();
	}

// 	if(m_pScroll)
// 		m_pScroll->InvalidateDeviceObjects();

	if(m_pBackImg)
	{
		m_pBackImg->InvalidateDeviceObjects();
	}

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->InvalidateDeviceObjects();
	}
//	if(m_pListCtrl)
//		m_pListCtrl->InvalidateDeviceObjects();
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선

	if(m_pToolTipFont)
	{
		m_pToolTipFont->InvalidateDeviceObjects();
	}

	if(m_pConuntFont)
	{
		m_pConuntFont->InvalidateDeviceObjects();
	}

	if(m_pSelectImg)
	{
		m_pSelectImg->InvalidateDeviceObjects();
	}

	if(m_pBiddingBtn)
	{
		m_pBiddingBtn->InvalidateDeviceObjects();
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

void CINFReturnAuctionList::Render()
{
	if(!m_bShowWnd)
	{
		return;
	}

	if(m_pBackImg)
	{
		m_pBackImg->Render();
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

		m_pBiddingCountFont->DrawText(STARTPOS_X + BIDDINGCOUNT_X + (72 / 2 - m_pBiddingCountFont->GetStringSize(buf).cx / 2), STARTPOS_Y + BIDDINGCOUNT_Y, GUI_FONT_COLOR_W, buf);	
	}

	if(m_pTotalItemCountFont && 0 < m_nTotalItemCount)
	{
		char cTotalItemCount[256] = {0, };
		wsprintf(cTotalItemCount, STRMSG_C_131205_0036, m_nTotalItemCount);		// "(아이템수 : %d)"
		
		SIZE sSize = m_pTotalItemCountFont->GetStringSize(cTotalItemCount);
		m_pTotalItemCountFont->DrawText(STARTPOS_X + TOTALITEMCNT_LOCATION_X - sSize.cx, STARTPOS_Y + TOTALITEMCNT_LOCATION_Y, GUI_FONT_COLOR, cTotalItemCount, 0L);
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->Render();
	}

	ListRender();

// 	if(m_pScroll)
// 		m_pScroll->Render();

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->Render();
	}
//	if(m_pListCtrl)
//		m_pListCtrl->Render();
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->Render();			
		}	
	}

	RenderPageCnt();

	ToolTipRender();

	int nTemp = 0;
	if(m_pSelectImg && 0 <= m_nSelectListItem)
	{
		nTemp = (0 == m_nCurrentPage - 1) ? m_nSelectListItem : (m_nSelectListItem % ((m_nCurrentPage - 1) * ITEMLIST_ITEMNUM));
		m_pSelectImg->Move(STARTPOS_X + ITEMLIST_LOCATION_X, STARTPOS_Y + ITEMLIST_LOCATION_Y - 1 + nTemp * (ITEMLIST_CELL_HEIGHT + 1));
		m_pSelectImg->Render();
	}

	if(m_pBiddingBtn)
	{
		m_pBiddingBtn->Render();
	}

	if(m_pMsgBox)
	{
		m_pMsgBox->Render();
	}
}
void CINFReturnAuctionList::Tick()
{
	if(m_pMsgBox)
	{
		m_pMsgBox->Tick();
	}
}	

int CINFReturnAuctionList::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(m_pMsgBox)
	{
		int nResult = m_pMsgBox->WndProc(uMsg, wParam, lParam);
		if(INF_MSGPROC_NORMAL != nResult)
		{
			if(INF_MSGPROC_CLOSE == nResult)
			{
				m_pMsgBox->ShowWnd(FALSE);
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

int	CINFReturnAuctionList::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pRefreshBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}	
	
// 	BOOL bClick = m_pScroll->IsMouseBallPos(pt);
// 	if(bClick)		
// 	{
// 		m_pScroll->SetMouseMoveMode(TRUE);
// 		return  INF_MSGPROC_BREAK;
// 	}		

	int nSelMainIdx = -1, nSelSubIdx = -1;
	{				
		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
		if(TRUE == m_pListTreeCtrl->OnLButtonDown(pt))
		{
			SortList(m_pListTreeCtrl->FindKindBySelectedItem());
			return INF_MSGPROC_BREAK;
		}
//		if(TRUE == m_pListCtrl->OnLButtonDown(pt, &nSelMainIdx, &nSelSubIdx))
//		{		
//			POINT pt = m_pListCtrl->GetSelectPoint(); //x가 메인 y가 서브 
//			SortList(SerachKind(pt));
//			return INF_MSGPROC_BREAK;
//		}
		// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	}

	if(TRUE == ItemListMouseDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; nCnt++)
	{
		if(((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			if(TRUE == ((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonDown(pt))
			{
				return  INF_MSGPROC_BREAK;
			}
		}		
	}

	if(INF_MSGPROC_BREAK == OnCilckPageCnt(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	int nTemp = -1;
	if(pt.x > STARTPOS_X + ITEMLIST_LOCATION_X
		&& pt.x < STARTPOS_X + ITEMLIST_LOCATION_X + ITEMLIST_WIDTH
		&& pt.y > STARTPOS_Y + ITEMLIST_LOCATION_Y - 1
		&& pt.y < STARTPOS_Y + ITEMLIST_LOCATION_Y - 1 + ITEMLIST_HEIGHT)
	{
		nTemp = (((pt.y - STARTPOS_Y - ITEMLIST_LOCATION_Y - 1) / (ITEMLIST_CELL_HEIGHT + 1)) + ((m_nCurrentPage - 1) * ITEMLIST_ITEMNUM)) + 1;
		if(nTemp <= m_vecItemInfo.size())
		{
			m_nSelectListItem = nTemp - 1;
		}
	}

	if(TRUE == m_pBiddingBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}	

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnAuctionList::OnLButtonUp(WPARAM wParam, LPARAM lParam)
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

// 	BOOL bClick = m_pScroll->GetMouseMoveMode();
// 	if(bClick)		
// 	{
// 		m_pScroll->SetMouseMoveMode(FALSE);	
// 		return  INF_MSGPROC_BREAK;
// 	}

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(TRUE == m_pListTreeCtrl->OnLButtonUp(pt))
	//if(TRUE == m_pListCtrl->OnLButtonUp(pt))
	{
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

	if(TRUE == m_pBiddingBtn->OnLButtonUp(pt))
	{
		BiddingBtnDown();
		return INF_MSGPROC_BREAK;
	}		

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnAuctionList::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	m_nToolTipState = 0;

	m_pRefreshBtn->OnMouseMove(pt);

	m_pBiddingBtn->OnMouseMove(pt);

// 	if(m_pScroll->GetMouseMoveMode())
// 	{
// 		if(FALSE == m_pScroll->IsMouseScrollPos(pt))
// 			m_pScroll->SetMouseMoveMode(FALSE);
// 		else
// 		{
// 			m_pScroll->SetScrollPos(pt);
// 			//UpdateItemPos();
// 			return  INF_MSGPROC_BREAK;
// 		}
// 	}

	m_pListTreeCtrl->OnMouseMove(pt);		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	//m_pListCtrl->OnMouseMove(pt);

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

int	CINFReturnAuctionList::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
 	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(g_pD3dApp->GetHwnd(), &pt);
	CheckMouseReverse(&pt);

// 	BOOL bClick = m_pScroll->IsMouseWhellPos(pt);
// 	if(bClick)		
// 	{			
// 		m_pScroll->OnMouseWheel(wParam, lParam);	
// //		UpdateItemPos();		
// 		return  INF_MSGPROC_BREAK;
// 	}
	
	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl->OnMouseWheel(pt, wParam, lParam))
	//if(m_pListCtrl->OnMouseWheel(pt,wParam,lParam))
	{
		return INF_MSGPROC_BREAK;
	}
	
	return INF_MSGPROC_NORMAL;
}


void CINFReturnAuctionList::ShowWnd(BOOL bShow)
{
	m_bShowWnd = bShow;
	if(bShow)
	{
		InitData();
		SortList(m_pListTreeCtrl->FindKindBySelectedItem());	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
		//POINT pt = m_pListCtrl->GetSelectPoint();		//x가 메인 y가 서브 
		//SortList(SerachKind(pt));
		UpdateItemListScroll(1, 1);
	}
	else
	{
		
	}
}

void CINFReturnAuctionList::SetBtnPos()
{
// 	RECT rcMouseWhell, rcMousePos;
// 	POINT ptScrollPos;
// 	POINT ptScroll;
// 	ptScrollPos.x = STARTPOS_X;
// 	ptScrollPos.y = STARTPOS_Y;
// 	
// 	ptScrollPos.x += 223;		//포지션 만큼 더함		//화면에서 스크롤이 적용받을 처음 위치 
// 	ptScrollPos.y += 226;
// 	
// 	// 스크롤 x = 위치의 -5
// 	// 스크롤 height = 이미지 길이의 - 34W
// 	
// 	rcMouseWhell.left		= ptScrollPos.x;
// 	rcMouseWhell.top		= ptScrollPos.y;
// 	rcMouseWhell.right		= ptScrollPos.x + 680;						//스크롤이 적용 받을 인터페이스의 크기 
// 	rcMouseWhell.bottom		= ptScrollPos.y + 326;
// 
// 	rcMousePos.left			= ptScrollPos.x + 680;					//스크롤의 위치 처음 
// 	rcMousePos.top			= ptScrollPos.y;
// 	rcMousePos.right		= rcMousePos.left;						
// 	rcMousePos.bottom		= rcMousePos.top;
// 
// 	m_pScroll->SetPosition(rcMousePos.left, rcMousePos.top, 11/*SCROLL_BALL_WIDTH*/, 326/*스크롤 높이 */ );		//스크롤 그림의 넓이가 11 임 
// 	m_pScroll->SetPosition(ptScrollPos.x ,ptScrollPos.y,11,247);
// 	m_pScroll->SetMouseWhellRect(rcMouseWhell);
// 
// 	ptScroll = m_pScroll->GetImgBkSize();
// 	
// 	rcMousePos.bottom		= rcMousePos.top + ptScroll.y + 100;			//갭을 넣은 위아래 양옆 몇까지 의 갭에서 작동 할 것인가 스크롤이 
// 	rcMousePos.top			= 100;
// 	rcMousePos.right		= rcMousePos.left + 100;
// 	rcMousePos.left			-= 100;					
// 
// 	m_pScroll->SetMouseBallRect(rcMousePos);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->SetBtnPosition(STARTPOS_X + REFRESHBTN_LOCATION_X, STARTPOS_Y + REFRESHBTN_LOCATION_Y);
	}
	if(m_pBackImg)
	{
		m_pBackImg->Move(STARTPOS_X + LISTVIEW_START_X, STARTPOS_Y + LISTVIEW_START_Y);
	}

	if(m_pBiddingBtn)
	{
		m_pBiddingBtn->SetBtnPosition(STARTPOS_X + BIDDINGBTN_LOCATION_X, STARTPOS_Y + BIDDINGBTN_LOCATION_Y);
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_byOrgKind = -1;
	m_nSelectListItem = -1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	{
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage - m_nStartPage + 1);
		nPageCnt = max(1, nPageCnt);	
		
		int nStartX = STARTPOS_X + PAGEBTN_LOCATION_X;
		int nStartY = STARTPOS_Y + PAGEBTN_LOCATION_Y;
		
		int nTmpPosX = nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][0].x;
		int nTmpPosY = nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][0].y;
		
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_FIRST]->SetBtnPosition(nTmpPosX + PAGEBTN_FIRST_LOCATION_X, nTmpPosY + 2);				
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_PREV]->SetBtnPosition(nTmpPosX + PAGEBTN_PREV_LOCATION_X, nTmpPosY + 2);				
		
		nTmpPosX = nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nPageCnt - 1].x;
		nTmpPosY = nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nPageCnt - 1].y;
		
		int nTmpNextPosX = nTmpPosX + 16;
		if(m_pConuntFont)
		{
			char chTxt[64] ={0, }; 
			wsprintf(chTxt, "%d", m_nMaxScrollPage);
			SIZE szSize = m_pConuntFont->GetStringSize(chTxt);
			nTmpNextPosX = nTmpPosX + szSize.cx + 8;
		}
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_NEXT]->SetBtnPosition(nTmpNextPosX + PAGEBTN_NEXT_LOCATION_X, nTmpPosY + 2);				
		((CINFReturnAuctionCenter*)m_pParent)->m_pPageBtn[PAGE_BTN_LAST]->SetBtnPosition(nTmpNextPosX + PAGEBTN_LAST_LOCATION_X, nTmpPosY + 2);
	}		
}

void CINFReturnAuctionList::InitData()
{
	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->RestoreDeviceObjects();
		m_pListTreeCtrl->SetListCtrlPos(STARTPOS_X + CATEGORY_LOCATION_X, STARTPOS_Y + CATEGORY_LOCATION_Y,
										CATEGORY_SUBITEM_LOCATION_X, CATEGORY_SUBITEM_LOCATION_Y, 
										CATEGORY_SCROLL_LOCATION_X, CATEGORY_SCROLL_LOCATION_Y, 
										CATEGORY_WIDTH, CATEGORY_HEIGHT);
		LoadListItem();
		m_pListTreeCtrl->RestoreItemDeviceObjects();
		m_pListTreeCtrl->UpdateItemPos();
		m_pListTreeCtrl->SetSelPoint(NULL);
	}
//	if(m_pListCtrl)
//	{
//		m_pListCtrl->RestoreDeviceObjects();
//		m_pListCtrl->SetListCtrlPos(STARTPOS_X + CATEGORY_LOCATION_X, STARTPOS_Y + CATEGORY_LOCATION_Y,
//			CATEGORY_SUBITEM_LOCATION_X, CATEGORY_SUBITEM_LOCATION_Y, 
//			CATEGORY_SCROLL_LOCATION_X, CATEGORY_SCROLL_LOCATION_Y, 
//			CATEGORY_WIDTH, CATEGORY_HEIGHT);
//		LoadListItem();
//		m_pListCtrl->RestoreItemDeviceObjects();
//		m_pListCtrl->UpdateItemPos();
//		m_pListCtrl->SetSelPoint(0, 0);		
//		//시작 위치 x, y, 서브 아이템 위치 x, y 스크롤 위치 x, y, 휠 범위
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
}

void CINFReturnAuctionList::RefreshBtnDown()
{
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	ATUM_DATE_TIME pTime = m_pLastRefreshTime;
	pTime.AddDateTime(0, 0, 0, 0, 0, 10);
	if(pTime < GetServerDateTime())
	{
		m_pLastRefreshTime = GetServerDateTime();
		g_pFieldWinSocket->SendMsg(T_FC_DESTROY_AUCTION_BASE_INFO_REQUEST, NULL , 0);
	}
	else
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "
	}
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

void CINFReturnAuctionList::ListRender()
{
	int nStartCnt = 0;
	int nFinalCnt = 0;

	int nCnt = 0;
	int nCnt02 = 0;
	char cList[512] = {0, };
	char cTemp[512] = {0, };
	CINFImageEx* pImg = NULL;
	CINFReturnAuctionCenter* pParent = NULL;
	pParent = ((CINFReturnAuctionCenter*)m_pParent);

	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;

//	nStartCnt = m_pScroll->GetScrollStep();
	
	if(m_vecItemInfo.size() <= 0 || !m_bRenderState)
	{
		return;
	}

//	((m_vecItemInfo.size() > PAGE_ITEM_COUNT) ? nFinalCnt = nStartCnt + PAGE_ITEM_COUNT : nFinalCnt = m_vecItemInfo.size());  //스크롤이 Max아이템을 넣으면 예외처리 해줌 직접 위에서 안해도됨 
	
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
			return;
		}

		pParent->m_pItemSl->Move(STARTPOS_X + ITEMLIST_ITEMSL_LOCATION_X, STARTPOS_Y + ITEMLIST_ITEMSL_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1));
		pParent->m_pItemSl->Render();
		
		wsprintf(cList, "\\e+%d\\e", pMarketItem->pItem->GetEnchantNumber());
		SIZE sSize = m_pListFont->GetStringSize(cList);
		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_ENCHANT_LOCATION_X + ITEMLIST_LEVEL_WIDTH / 2 - sSize.cx / 2, 
			STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2  - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1), GUI_FONT_COLOR, cList);
		
		wsprintf(cList, "%s", pMarketItem->Name);
		pParent->ChangeMaxLenString(cList, ITEMLIST_MAXITEMNAME_LEN);
		sSize = m_pListFont->GetStringSize(cList);
		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_NAME_LOCATION_X + ITEMLIST_NAME_WIDTH / 2 - sSize.cx / 2, 
			STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2  - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1), GUI_FONT_COLOR, cList);
		
		wsprintf(cList, "%d", pMarketItem->pItem->ItemInfo->ReqMinLevel);
		sSize = m_pListFont->GetStringSize(cList);
		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_LEVEL_LOCATION_X + ITEMLIST_LEVEL_WIDTH / 2 - sSize.cx / 2, 
			STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2  - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1), GUI_FONT_COLOR, cList);
		
 		pParent->GetRemainTime(pParent->m_DAuctionEndTime, cList);
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(STARTPOS_X  + ITEMLIST_REGISTTIME_LOCATION_X + ITEMLIST_REGISTTIME_WIDTH / 2 - sSize.cx / 2, 
 			STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2  - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1), GUI_FONT_COLOR, cList);
		
		wsprintf(cTemp, "%d", pMarketItem->pINFO->DAuctionInfo.Price);
		MakeCurrencySeparator(cList, cTemp, 3, ',');			
		sSize = m_pListFont->GetStringSize(cList);
		m_pListFont->DrawText(STARTPOS_X + ITEMLIST_PRICE_LOCATION_X + ITEMLIST_PRICE_WIDTH - sSize.cx, 
			STARTPOS_Y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT / 2  - sSize.cy / 2 + nCnt * (ITEMLIST_CELL_HEIGHT + 1), GUI_FONT_COLOR, cList);
		
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
			pImg->Move(STARTPOS_X + ITEMLIST_MONEYTYPE_LOCATION_X, STARTPOS_Y + ITEMLIST_MONEYTYPE_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1));
			pImg->Render();
		}
		
		if(m_pIconInfo)
		{
			char chIconName[64] = {0, };	
			if( !pMarketItem->pItem->ShapeItemNum)
			{
				wsprintf( chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
			}
			else
			{
				ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(pMarketItem->pItem->ShapeItemNum);
				if( pShapeItem )
				{
					wsprintf( chIconName, "%08d", pShapeItem->SourceIndex );
				}
				else
				{
					wsprintf( chIconName, "%08d", pMarketItem->pItem->ItemInfo->SourceIndex);
				}
			}		
			
			m_pIconInfo->SetIcon(chIconName, STARTPOS_X + ITEMLIST_ICON_LOCATION_X,	STARTPOS_Y + ITEMLIST_ICON_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1), 1.0f);
			m_pIconInfo->Render();
			
			if(IS_COUNTABLE_ITEM(pMarketItem->pItem->Kind))
			{
				if(1 < pMarketItem->pINFO->DAuctionInfo.ItemCount)
				{
					wsprintf(cList, "%d", pMarketItem->pINFO->DAuctionInfo.ItemCount);
					int itemCntStrLen = m_pListFont->GetStringSize(cList).cx;
					m_pListFont->DrawText(STARTPOS_X + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen, 
											STARTPOS_Y + ITEMLIST_ICON_LOCATION_Y + ITEMLIST_ITEMCNT_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT + 1),
											QSLOT_COUNTERBLE_NUMBER, cList, 0L);
				}
			}
		}

		++nCnt;
	}
}

void CINFReturnAuctionList::LoadListItem()
{
	int nTempTotalCnt = 0;
	nTempTotalCnt = _ACCESSORY_UNLIMITED + 1;

	m_pListTreeCtrl->ResetContent();		// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	//m_pListCtrl->ResetContent();
	if(NULL == m_pCategorytree)
	{
		TREECATEGORY TempcaTree[] = 
		{
			{0, 0,	_ALLITEM,				STRMSG_C_131205_0001},	//전체 
			{1, 0,	_WEAPON,				STRMSG_C_131205_0002},		//무기
			{1, 1,	_PRIMARY_WEAPON,		STRMSG_C_131205_0003},			//기본무기
			{1, 2,	_SECONDARY_WEAPON,		STRMSG_C_131205_0011},			//고급무기
			{2, 0,	_DEFENSE,				STRMSG_C_131205_0014},		//아머 
			{3, 0,	_SUPPORT,				STRMSG_C_131205_0020},		//보조장비
			{3, 1,	_ENGIN,					STRMSG_C_131205_0024},			//엔진
			{3, 2,	_RADAR,					STRMSG_C_131205_0019},			//레이더
			{3, 3,	_ACCESSORY_UNLIMITED,	STRMSG_C_131205_0021}			//무제한 악세사리
		};

		m_pCategorytree = new TREECATEGORY[nTempTotalCnt];
		for(int i = 0 ; i < nTempTotalCnt ; ++i)
		{
			memcpy(&m_pCategorytree[i], &TempcaTree[i], sizeof(TREECATEGORY));
		}
	}

	// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
	m_pListTreeCtrl->InsertTextItemWithByKind(0, -1, 0, m_pCategorytree[0].byKind, m_pCategorytree[0].Name, 0, TRUE);
	for(int i = 1 ; i < nTempTotalCnt ; ++i)
	{
		int nCategoryId = m_pCategorytree[i].nMainidx * 10 + m_pCategorytree[i].nSubIdx;
		if(0 == m_pCategorytree[i].nSubIdx)
		{
			m_pListTreeCtrl->InsertTextItemWithByKind(0, 0, nCategoryId, m_pCategorytree[i].byKind, m_pCategorytree[i].Name, GUI_FONT_COLOR, FALSE);
		}
		else
		{
			m_pListTreeCtrl->InsertTextItemWithByKind(0, m_pCategorytree[i].nMainidx * 10, nCategoryId, m_pCategorytree[i].byKind, m_pCategorytree[i].Name, GUI_FONT_COLOR, FALSE);
		}
	}
//	m_pListCtrl->InsertTextItem(0, m_pCategorytree[0].nMainidx, m_pCategorytree[0].Name, TRUE);
//	for(int i = 1; i<nTempTotalCnt; ++i)
//	{
//		if(0 == m_pCategorytree[i].nSubIdx)
//		{
//			m_pListCtrl->InsertTextItem(0, m_pCategorytree[i].nMainidx, m_pCategorytree[i].Name, FALSE);
//		}
//		else
//		{
//			m_pListCtrl->InserSubItem(0, m_pCategorytree[i].nMainidx, m_pCategorytree[i].nSubIdx,m_pCategorytree[i].Name, GUI_FONT_COLOR);
//		}
//	}
	// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
}

BYTE CINFReturnAuctionList::SerachKind(POINT pt)
{
 	for(int i = 0 ; i < _ACCESSORY_UNLIMITED + 1 ; ++i)
 	{
 		if(pt.x == m_pCategorytree[i].nMainidx && pt.y == m_pCategorytree[i].nSubIdx)
 		{
 			return m_pCategorytree[i].byKind;
 		}
 	}
 	return 0;
}

void CINFReturnAuctionList::SortList(BYTE byKind)
{
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	it = ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.begin();
	AUCTION_MY_ITEM_INFO* pTempData = NULL;
	
	if(m_byOrgKind == byKind)
	{
		return;
	}

	m_vecItemInfo.clear();

	switch(byKind)
	{
	case _ALLITEM : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				m_vecItemInfo.push_back(*it);
			}
		}
		break;
	case _WEAPON : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(IS_WEAPON(pTempData->pItem->Kind))
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _PRIMARY_WEAPON : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(IS_PRIMARY_WEAPON(pTempData->pItem->Kind))
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _SECONDARY_WEAPON : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(IS_SECONDARY_WEAPON(pTempData->pItem->Kind))
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _DEFENSE : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(ITEMKIND_DEFENSE == pTempData->pItem->Kind)
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _SUPPORT : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{	
				pTempData = *it;
				if(ITEMKIND_SUPPORT == pTempData->pItem->Kind
					|| ITEMKIND_RADAR == pTempData->pItem->Kind
					|| ITEMKIND_ACCESSORY_UNLIMITED == pTempData->pItem->Kind )
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _ENGIN : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(ITEMKIND_SUPPORT == pTempData->pItem->Kind)
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _RADAR : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(ITEMKIND_RADAR == pTempData->pItem->Kind)
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	case _ACCESSORY_UNLIMITED : 
		{
			for( ; it != ((CINFReturnAuctionCenter*)m_pParent)->m_vecOrginItemInfo.end() ; ++it)
			{
				pTempData = *it;
				if(ITEMKIND_ACCESSORY_UNLIMITED == pTempData->pItem->Kind)
				{
					m_vecItemInfo.push_back(pTempData);
				}
			}
		}
		break;
	}
//	m_pScroll->SetMaxItem(m_vecItemInfo.size());
	m_nTotalItemCount = m_vecItemInfo.size();

	m_byOrgKind = byKind;

	if(0 < m_vecItemInfo.size())
	{
		m_nMaxScrollPage = m_vecItemInfo.size() / PAGE_ITEM_COUNT;
		
		if(0 < m_vecItemInfo.size() % PAGE_ITEM_COUNT)
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

void CINFReturnAuctionList::ToolTipRender()
{
	if(0 == m_nToolTipState)
	{
		return;
	}
	
	char buf[128] = {0, };
	int nX = m_ptToolTipPos.x;
	
	wsprintf(buf, STRMSG_C_140121_0002);	// "입찰"
	
	int leng = m_pToolTipFont->GetStringSize(buf).cx + 4;
	
	if(g_pD3dApp->GetBackBufferDesc().Width < nX + leng)
	{
		nX = g_pD3dApp->GetBackBufferDesc().Width - leng;
	}
	g_pGameMain->RenderPopUpWindowImage(nX, m_ptToolTipPos.y + TOOLTIP_POSITION_Y, leng, 1);
	m_pToolTipFont->DrawText(nX+1, m_ptToolTipPos.y + TOOLTIP_POSITION_Y - 2 , GUI_FONT_COLOR_W, buf);
}

void CINFReturnAuctionList::ItemListMouseMove(POINT pt)
{
// 	{
// 		int nStartCnt = 0;
// 		int nFinalCnt = 0;
// 		CINFReturnAuctionCenter* pParent = NULL;
// 		pParent = ((CINFReturnAuctionCenter*)m_pParent);
// 		
// 		int nCnt = 0;
// 		
// 		MARKET_MY_ITEM_INFO* pMarketItem = NULL;
// 		
// 		nStartCnt = m_pScroll->GetScrollStep();
// 		
// 		if(m_vecItemInfo.size() <= 0)
// 			return;
// 		
// 		((m_vecItemInfo.size() > PAGE_ITEM_COUNT) ? nFinalCnt = nStartCnt + PAGE_ITEM_COUNT : nFinalCnt = m_vecItemInfo.size());
// 		
// 		for(int i = nStartCnt; i<nFinalCnt; ++i)
// 		{
// 			pMarketItem	= m_vecItemInfo[i];
// 			
// 			if(!pMarketItem)
// 				return;
// 			
// 			if(pt.x > STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X && pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x &&
// 				pt.y > STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
// 			{
// 				if(pMarketItem->byBtnState != BTN_STATUS_DOWN)
// 					pMarketItem->byBtnState = BTN_STATUS_UP;
// 				
// 				memcpy(&m_ptToolTipPos, &pt, sizeof(POINT));
// 				
// 				m_nToolTipState = pMarketItem->pINFO->MarketInfo.MarketState;
// 			}
// 			else
// 				pMarketItem->byBtnState = BTN_STATUS_UP;
// 			
// 			nCnt++;
// 		}
// 	}
// 
// 

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

BOOL CINFReturnAuctionList::ItemListMouseDown(POINT pt)
{
// 	int nStartCnt = 0;
// 	int nFinalCnt = 0;
// 	CINFReturnAuctionCenter* pParent = NULL;
// 	pParent = ((CINFReturnAuctionCenter*)m_pParent);
// 	
// 	int nCnt = 0;
// 	
// 	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
// 	
// 	nStartCnt = m_pScroll->GetScrollStep();
// 	
// 	if(m_vecItemInfo.size() <= 0)
// 		return FALSE;
// 	
// 	((m_vecItemInfo.size() > PAGE_ITEM_COUNT) ? nFinalCnt = nStartCnt + PAGE_ITEM_COUNT : nFinalCnt = m_vecItemInfo.size());
// 	
// 	for(int i = nStartCnt; i<nFinalCnt; ++i)
// 	{
// 		pMarketItem	= m_vecItemInfo[i];
// 		
// 		if(!pMarketItem)
// 			return FALSE;
// 		
// 		if(pt.x > STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X && pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x &&
// 			pt.y > STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
// 		{
// 			pMarketItem->byBtnState = BTN_STATUS_DOWN;
// 			return  TRUE;
// 		}
// 		nCnt++;
// 	}
 	return FALSE;
}

BOOL CINFReturnAuctionList::ItemListMouseUP(POINT pt)
{
// 	int nStartCnt = 0;
// 	int nFinalCnt = 0;
// 	CINFReturnAuctionCenter* pParent = NULL;
// 	pParent = ((CINFReturnAuctionCenter*)m_pParent);
// 	
// 	int nCnt = 0;
// 	
// 	MARKET_MY_ITEM_INFO* pMarketItem = NULL;
// 	
// 	nStartCnt = m_pScroll->GetScrollStep();
// 	
// 	if(m_vecItemInfo.size() <= 0)
// 		return FALSE;
// 	
// 	((m_vecItemInfo.size() > PAGE_ITEM_COUNT) ? nFinalCnt = nStartCnt + PAGE_ITEM_COUNT : nFinalCnt = m_vecItemInfo.size());
// 	
// 	for(int i = nStartCnt; i<nFinalCnt; ++i)
// 	{
// 		pMarketItem	= m_vecItemInfo[i];
// 		
// 		if(!pMarketItem)
// 			return FALSE;
// 		
// 		if(pt.x > STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X && pt.x < STARTPOS_X + ITEMLIST_BIDDINGIMG_LOCATION_X + pParent->m_pBiddingImg[1]->GetImgSize().x &&
// 			pt.y > STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) && pt.y < STARTPOS_Y + ITEMLIST_BIDDINGIMG_LOCATION_Y + nCnt * (ITEMLIST_CELL_HEIGHT+1) + pParent->m_pBiddingImg[pMarketItem->byBtnState]->GetImgSize().y)
// 		{
// 			if(pMarketItem->byBtnState == BTN_STATUS_DOWN)
// 			{
// 				pMarketItem->byBtnState = BTN_STATUS_UP;				//입찰 버튼 클릭 했을 때 여기서 해도 되고 리턴 해서 함수를 다시 파도 되고 
// 				BiddingBtnDown(pMarketItem);
// 				m_nToolTipState = 0;
// 			}
// 			return TRUE;
// 		}
// 		nCnt++;
// 	}
 	return FALSE;
}

void CINFReturnAuctionList::BiddingBtnDown()
{
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	char cList[512] = {0, };
	CINFReturnAuctionCenter* pParent = (CINFReturnAuctionCenter*)m_pParent;
	if(FALSE == pParent->GetRemainTime(pParent->m_DAuctionEndTime, cList))
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_140121_0011, _Q_MARKET_NORMAL_MESSAGE);	 // "진행중인 경매가 없습니다. "
		return;
	}
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업

	char buf[256] = {0, };
	char buf02[256] = {0, };
	char chIconName[64] = {0, };	
	AUCTION_MY_ITEM_INFO* pMarketItem = NULL;

	if(-1 < m_nSelectListItem)
	{
		pMarketItem = m_vecItemInfo[m_nSelectListItem];
	}
	else
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0033, _Q_MARKET_NORMAL_MESSAGE);	 // "선택하신 물품이 없거나 잘 못 선택 하셨습니다. "
	}

	if(NULL == pMarketItem)
	{
		return;
	}

	if(pMarketItem->pINFO->DAuctionInfo.CharacterUID == g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_140121_0003, _Q_MARKET_NORMAL_MESSAGE);	//"최고 입찰가로 입찰중입니다. "
		return;
	}

	if(NULL != m_pMsgBox)
	{
		m_pMsgBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMsgBox);
//		m_pMsgBox = NULL;
	}

	m_pMsgBox = new CINFReturnAuctionMsgBox();
	m_pMsgBox->InitDeviceObjects("ra_tender", pMarketItem, BIDDING, m_pParent);
	m_pMsgBox->RestoreDeviceObjects();
	m_pMsgBox->ShowWnd(TRUE);	
}

void CINFReturnAuctionList::RenderPageCnt()
{
	if(NULL == m_pConuntFont)
	{
		return;
	}

	{
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
			m_pConuntFont->DrawText(nStartX + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].x,
									nStartY + ((CINFReturnAuctionCenter*)m_pParent)->m_ptPagePosList[nPageCnt - 1][nCnt].y,
									dwColor, chTxt);
		}		
	}
}

void CINFReturnAuctionList::OnClickPageBtn(int nPageMode)
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

void CINFReturnAuctionList::UpdateItemListScroll(int nCurrentPage, int nStartPage)
{
	m_nCurrentPage = nCurrentPage;	
	m_nStartPage = nStartPage;	
	
	SetBtnPos();
}

int CINFReturnAuctionList::OnCilckPageCnt(POINT ptPos)
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
			int nCurrentPage = m_nStartPage + nCnt;
			UpdateItemListScroll(nCurrentPage, m_nStartPage);
			
			return INF_MSGPROC_BREAK;	
		}	
	}
	return INF_MSGPROC_NORMAL;	
}

void CINFReturnAuctionList::VecItemInfoClear()
{
	m_bRenderState = FALSE;
	m_nCurrentPage = 1;
	m_nMaxScrollPage = 1; 
	m_nStartPage = 1;
	SetBtnPos();
	
	if(0 < m_vecItemInfo.size())
	{
		if(false == m_vecItemInfo.empty())
		{
			m_vecItemInfo.clear();
		}
	}

	m_nTotalItemCount = m_vecItemInfo.size();
}

void CINFReturnAuctionList::ItemVecDone()
{
	m_bRenderState = TRUE;
}
