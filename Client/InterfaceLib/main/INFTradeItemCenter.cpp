// INFTradeItemCenter.cpp: implementation of the CINFTradeItemCenter class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFTradeItemCenter.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "ItemInfo.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFInvenExtend.h"
#include "INFItemInfo.h"
#include "INFNumEditBox.h"
#include "INFTradeItemAdd.h"
#include "INFTradeItemBuy.h"
#include "INFTradeMyItemShow.h"
// 2014-06-17 거래소 추가작업 (주석 처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "AtumDatabase.h"
//#include "ShuttleChild.h"
//#include "CharacterChild.h"
//#include "INFWindow.h"
//#include "AtumSound.h"
//#include "Interface.h"
//#include "INFEditBox.h"
//#include "INFAutoEditBox.h"
//#include "INFImageBtn.h"
//#include "INFListBox.h"
//#include "INFArenaScrollBar.h"
//#include "INFIcon.h"
// END 2014-06-17 거래소 추가작업 (주석 처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// 창 크기
#define TRADEITEMBUY_WIDTH					936
#define	TRADEITEMBUY_HEIGHT					642

// 탭 버튼
#define IMAGETAPBTN_BUY_LOCATION_X			190
#define IMAGETAPBTN_BUY_LOCATION_Y			49
#define IMAGETAPBTN_ADD_LOCATION_X			402
#define IMAGETAPBTN_ADD_LOCATION_Y			49
#define IMAGETAPBTN_SHOW_LOCATION_X			614
#define IMAGETAPBTN_SHOW_LOCATION_Y			49

// MY CASH
#define MYCASH_SPI_LOCATION_X				100
#define MYCASH_SPI_LOCATION_Y				115
#define MYCASH_WP_LOCATION_X				100
#define MYCASH_WP_LOCATION_Y				139

// 아이템 등록 탭 인벤토리
#define PAGE_ADD_INVEN_LOCATION_X			206
#define PAGE_ADD_INVEN_LOCATION_Y			105

#define MAX_TAPCOUNT						3
#define MONEYCOUNT							2


CINFTradeItemCenter::CINFTradeItemCenter(CAtumNode* pParent, BUILDINGNPC* pBuilding)
{
	m_pParent = pParent;	// CGameMain*
	m_pGameData = NULL;

	m_pBackImg = NULL;

	m_nMySPI = 0;
	m_nMyWP = 0;
	m_pMySPIFont = NULL;
	m_pMyWPFont = NULL;

	m_dwState = _TRADE_ITEM_BUY;

	memset(&m_ptStartPos, 0x00, sizeof(POINT));

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		m_pImgTapBtn[i] = NULL;
		m_pTradeItemView[i] = NULL;
		m_pImgTapBtn[i] = NULL;
	}
	{
		for(int i =0; i<MONEYCOUNT; ++i)
		{
			m_pMoneyImg[i] = NULL;
		}
	}

	m_pItemSl = NULL;

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		m_pPageBtn[nCnt] = NULL;
	}

	m_pBlackBackImg = NULL;

	m_nSellingTime = 0;
	
	m_bNormalInflMsgBuyTab = TRUE;	// 2014-06-17 거래소 추가작업
	m_bNormalInflMsgAddTab = TRUE;	// 2014-06-17 거래소 추가작업
}

CINFTradeItemCenter::~CINFTradeItemCenter()
{
	SAFE_DELETE(m_pBackImg);
	SAFE_DELETE(m_pMySPIFont);
	SAFE_DELETE(m_pMyWPFont);

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		SAFE_DELETE(m_pImgTapBtn[i]);
		SAFE_DELETE(m_pTradeItemView[i]);
		SAFE_DELETE(m_pImgTapBtn[i]);
	}

	{
		for(int i =0; i<MONEYCOUNT; ++i)
		{
			SAFE_DELETE(m_pMoneyImg[i]);
		}
	}

	SAFE_DELETE(m_pItemSl);

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		SAFE_DELETE(m_pPageBtn[nCnt]);
	}

	SAFE_DELETE(m_pBlackBackImg);

}

void CINFTradeItemCenter::Init()
{
	m_nMySPI = 0;
	m_nMyWP = 0;
	
	m_ptStartPos.x = (g_pD3dApp->GetBackBufferDesc().Width - TRADEITEMBUY_WIDTH)/2;
	m_ptStartPos.y = CITY_BASE_NPC_BOX_START_Y  - (TRADEITEMBUY_HEIGHT - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT));
	//m_ptStartPos.y = m_pBackImg->GetTransY();
	
	m_pBackImg->Move(m_ptStartPos.x, m_ptStartPos.y);

	m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_UP);
	m_dwState = _TRADE_ITEM_BUY;
	m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_DOWN);

	//m_pBackImg->Move((g_pD3dApp->GetBackBufferDesc().Width - 936) /2, CITY_BASE_NPC_BOX_START_Y  - 	(642 - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT)));
}

HRESULT CINFTradeItemCenter::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;

	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("tc_bg");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage( pDataHeader );
		m_pBackImg->InitDeviceObjects( g_pD3dApp->m_pImageList );		
	}

	if(NULL == m_pMySPIFont)
	{
		m_pMySPIFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,512,32);
		m_pMySPIFont->InitDeviceObjects(g_pD3dDev) ;
	}	
	if(NULL == m_pMyWPFont)
	{
		//		m_pItemListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),8, D3DFONT_ZENABLE, TRUE,512,32);
		m_pMyWPFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,512,32);		
		m_pMyWPFont->InitDeviceObjects(g_pD3dDev) ;
	}

	if(NULL == m_pTradeItemView[_TRADE_ITEM_BUY])
	{
		m_pTradeItemView[_TRADE_ITEM_BUY] = new CINFTradeItemBuy(this);
		m_pTradeItemView[_TRADE_ITEM_BUY]->InitDeviceObjects();
	}
	if(NULL == m_pTradeItemView[_TRADE_ITEM_ADD])
	{
		m_pTradeItemView[_TRADE_ITEM_ADD] = new CINFTradeItemAdd(this);
		m_pTradeItemView[_TRADE_ITEM_ADD]->InitDeviceObjects();
	}
	if(NULL == m_pTradeItemView[_TRADE_MY_ITEM_SHOW])
	{
		m_pTradeItemView[_TRADE_MY_ITEM_SHOW] = new CINFTradeMyItemShow(this);
		m_pTradeItemView[_TRADE_MY_ITEM_SHOW]->InitDeviceObjects();
	}

	
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_buy03");
		wsprintf(szDownBtn, "tc_buy01");
		wsprintf(szSelBtn, "tc_buy00");
		wsprintf(szDisBtn, "tc_buy02");
		if(NULL == m_pImgTapBtn[_TRADE_ITEM_BUY])
		{
			m_pImgTapBtn[_TRADE_ITEM_BUY] = new CINFImageBtn;
		}
		m_pImgTapBtn[_TRADE_ITEM_BUY]->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_reg03");
		wsprintf(szDownBtn, "tc_reg01");
		wsprintf(szSelBtn, "tc_reg00");
		wsprintf(szDisBtn, "tc_reg02");
		if(NULL == m_pImgTapBtn[_TRADE_ITEM_ADD])
		{
			m_pImgTapBtn[_TRADE_ITEM_ADD] = new CINFImageBtn;
		}
		m_pImgTapBtn[_TRADE_ITEM_ADD]->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];

		wsprintf(szUpBtn, "tc_state03");
		wsprintf(szDownBtn, "tc_state01");
		wsprintf(szSelBtn, "tc_state00");
		wsprintf(szDisBtn, "tc_state02");
		if(NULL == m_pImgTapBtn[_TRADE_MY_ITEM_SHOW])
		{
			m_pImgTapBtn[_TRADE_MY_ITEM_SHOW] = new CINFImageBtn;
		}
		m_pImgTapBtn[_TRADE_MY_ITEM_SHOW]->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}

	if(g_pGameMain)
	{
		pDataHeader = g_pGameMain->FindResource("tc_spi");
		if(pDataHeader)
		{
			if(NULL == m_pMoneyImg[SPI])
			{
				m_pMoneyImg[SPI] = new CINFImageEx();
				m_pMoneyImg[SPI]->InitDeviceObjects(pDataHeader);
			}
		}
		pDataHeader = g_pGameMain->FindResource("tc_wp");
		if(pDataHeader)
		{
			if(NULL == m_pMoneyImg[WP])
			{
				m_pMoneyImg[WP] = new CINFImageEx();
				m_pMoneyImg[WP]->InitDeviceObjects(pDataHeader);
			}
		}

		pDataHeader = g_pGameMain->FindResource("LM_inven");
		if(pDataHeader)
		{
			if(NULL == m_pBlackBackImg)
			{
				m_pBlackBackImg = new CINFImageEx();
				m_pBlackBackImg->InitDeviceObjects(pDataHeader);
			}
		}
	}	

	if(g_pGameMain)
		pDataHeader = g_pGameMain->FindResource("itemsl");
	if(pDataHeader)
	{
		if(NULL == m_pItemSl)
		{
			m_pItemSl = new CINFImageEx();
			m_pItemSl->InitDeviceObjects(pDataHeader);
		}
	}

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		char szUpBtn[MAX_PAGE_BTN][30], szDownBtn[MAX_PAGE_BTN][30], szSelBtn[MAX_PAGE_BTN][30], szDisBtn[MAX_PAGE_BTN][30];
		
		wsprintf(szUpBtn[PAGE_BTN_FIRST], "rec_pagef3");
		wsprintf(szDownBtn[PAGE_BTN_FIRST], "rec_pagef1");
		wsprintf(szSelBtn[PAGE_BTN_FIRST], "rec_pagef0");
		wsprintf(szDisBtn[PAGE_BTN_FIRST], "rec_pagef2");
		
		wsprintf(szUpBtn[PAGE_BTN_PREV], "call3");
		wsprintf(szDownBtn[PAGE_BTN_PREV], "call1");
		wsprintf(szSelBtn[PAGE_BTN_PREV], "call0");
		wsprintf(szDisBtn[PAGE_BTN_PREV], "call2");
		
		wsprintf(szUpBtn[PAGE_BTN_NEXT], "calr3");
		wsprintf(szDownBtn[PAGE_BTN_NEXT], "calr1");
		wsprintf(szSelBtn[PAGE_BTN_NEXT], "calr0");
		wsprintf(szDisBtn[PAGE_BTN_NEXT], "calr2");
		
		wsprintf(szUpBtn[PAGE_BTN_LAST], "rec_pagee3");
		wsprintf(szDownBtn[PAGE_BTN_LAST], "rec_pagee1");
		wsprintf(szSelBtn[PAGE_BTN_LAST], "rec_pagee0");
		wsprintf(szDisBtn[PAGE_BTN_LAST], "rec_pagee2");
		
		if(NULL == m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt] = new CINFImageBtn;
		}
		m_pPageBtn[nCnt]->InitDeviceObjects(szUpBtn[nCnt], szDownBtn[nCnt], szSelBtn[nCnt], szDisBtn[nCnt]);		
	}

	InitPagePosList();


	return S_OK ; 
}
HRESULT CINFTradeItemCenter::RestoreDeviceObjects()
{
	Init();
	if(m_pBackImg)
		m_pBackImg->RestoreDeviceObjects();

	if(m_pMySPIFont)
		m_pMySPIFont->RestoreDeviceObjects();

	if(m_pMyWPFont)
		m_pMyWPFont->RestoreDeviceObjects();

	if(m_pImgTapBtn[_TRADE_ITEM_BUY])
	{
		m_pImgTapBtn[_TRADE_ITEM_BUY]->RestoreDeviceObjects();
		m_pImgTapBtn[_TRADE_ITEM_BUY]->SetBtnPosition(m_ptStartPos.x + IMAGETAPBTN_BUY_LOCATION_X, m_ptStartPos.y + IMAGETAPBTN_BUY_LOCATION_Y);
	}

	if(m_pImgTapBtn[_TRADE_ITEM_ADD])
	{
		m_pImgTapBtn[_TRADE_ITEM_ADD]->RestoreDeviceObjects();
		m_pImgTapBtn[_TRADE_ITEM_ADD]->SetBtnPosition(m_ptStartPos.x + IMAGETAPBTN_ADD_LOCATION_X, m_ptStartPos.y + IMAGETAPBTN_ADD_LOCATION_Y);
	}

	if(m_pImgTapBtn[_TRADE_MY_ITEM_SHOW])
	{
		m_pImgTapBtn[_TRADE_MY_ITEM_SHOW]->RestoreDeviceObjects();
		m_pImgTapBtn[_TRADE_MY_ITEM_SHOW]->SetBtnPosition(m_ptStartPos.x + IMAGETAPBTN_SHOW_LOCATION_X, m_ptStartPos.y + IMAGETAPBTN_SHOW_LOCATION_Y);
	}

	m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_DOWN);

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		m_pTradeItemView[i]->RestoreDeviceObjects();
	}
	{
		for(int i =0; i<MONEYCOUNT; ++i)
		{
			if(m_pMoneyImg[i])
				m_pMoneyImg[i]->RestoreDeviceObjects();
		}
	}

	if(m_pItemSl)
		m_pItemSl->RestoreDeviceObjects();

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt]->RestoreDeviceObjects();		
		}
	}

	if(m_pBlackBackImg)
		m_pBlackBackImg->RestoreDeviceObjects();

	g_pGameMain->m_pInven->ShowInven(NULL, NULL);
	g_pGameMain->m_pInven->SetTradeItemCenterState(FALSE);


	return S_OK ;
}
HRESULT CINFTradeItemCenter::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}
	
	if(m_pMySPIFont)
	{
		m_pMySPIFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pMySPIFont);
	}
	
	if(m_pMyWPFont)
	{
		m_pMyWPFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pMyWPFont);
	}

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pImgTapBtn[i]);
		}
		if(m_pTradeItemView[i])
		{
			m_pTradeItemView[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pTradeItemView[i]);
		}

	}

	{
		for(int i =0; i<MONEYCOUNT; ++i)
		{
			if(m_pMoneyImg[i])
			{
				m_pMoneyImg[i]->DeleteDeviceObjects();
				SAFE_DELETE(m_pMoneyImg[i]);
			}
		}
	}

	if(m_pItemSl)
	{
		m_pItemSl->DeleteDeviceObjects();
		SAFE_DELETE(m_pItemSl);
	}

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(m_pPageBtn[nCnt])
		{			
			m_pPageBtn[nCnt]->DeleteDeviceObjects();
			SAFE_DELETE(m_pPageBtn[nCnt]);
		}
		
	}

	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBlackBackImg);
	}

	return S_OK ;
}
HRESULT CINFTradeItemCenter::InvalidateDeviceObjects()
{
	if(m_pBackImg)
		m_pBackImg->InvalidateDeviceObjects();
	
	if(m_pMySPIFont)
		m_pMySPIFont->InvalidateDeviceObjects();
	
	if(m_pMyWPFont)
		m_pMyWPFont->InvalidateDeviceObjects();

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->InvalidateDeviceObjects();		
		}
		if(m_pTradeItemView[i])
			m_pTradeItemView[i]->InvalidateDeviceObjects();
	}

	{
		for(int i =0; i<MONEYCOUNT; ++i)
		{
			if(m_pMoneyImg[i])
				m_pMoneyImg[i]->InvalidateDeviceObjects();
		}
	}

	if(m_pItemSl)
		m_pItemSl->InvalidateDeviceObjects();

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt]->InvalidateDeviceObjects();		
		}
		
	}

	if(m_pBlackBackImg)
		m_pBlackBackImg->InvalidateDeviceObjects();

	return S_OK ;
}
void CINFTradeItemCenter::Render()
{
	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->Render();
		}
	}

	if(m_pTradeItemView[m_dwState])
		m_pTradeItemView[m_dwState]->Render();

	g_pGameMain->m_pInven->RenderSpi( m_ptStartPos.x + MYCASH_SPI_LOCATION_X, m_ptStartPos.y + MYCASH_SPI_LOCATION_Y);
	g_pGameMain->m_pInven->RenderWp( m_ptStartPos.x + MYCASH_WP_LOCATION_X, m_ptStartPos.y + MYCASH_WP_LOCATION_Y);

}
void CINFTradeItemCenter::Tick()
{
	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(m_pTradeItemView[i])
			m_pTradeItemView[i]->Tick();
	}
}

int CINFTradeItemCenter::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(INF_MSGPROC_BREAK == m_pTradeItemView[m_dwState]->WndProc(uMsg, wParam, lParam))
		return INF_MSGPROC_BREAK;

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

int	 CINFTradeItemCenter::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	POINT ptItem, ptEq;
	ptItem.x = ptItem.y = ptEq.x = ptEq.y = 0;

	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(TRUE == m_pImgTapBtn[i]->OnLButtonDown(pt))
		{
			m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_UP);
	//		m_pTradeItemView[m_dwState]->RestoreDeviceObjects();
			m_pImgTapBtn[i]->SetBtnState(BTN_STATUS_DOWN);
			m_pTradeItemView[i]->RestoreDeviceObjects();
			m_dwState = i;

			if(m_dwState == _TRADE_ITEM_ADD)
			{
				// 보통 상점
				ptItem.x = m_ptStartPos.x + PAGE_ADD_INVEN_LOCATION_X;
				ptItem.y = m_ptStartPos.y + PAGE_ADD_INVEN_LOCATION_Y;
				ptEq.x = m_ptStartPos.x  + PAGE_ADD_INVEN_LOCATION_X;
				ptEq.y = m_ptStartPos.y + PAGE_ADD_INVEN_LOCATION_Y;														  
				
				g_pGameMain->m_pInven->ShowInven(&ptItem, &ptEq, FALSE, TRUE);
				g_pGameMain->m_pInven->SetTradeItemCenterState(TRUE);
			}
			else
			{		
				g_pGameMain->m_pInven->ShowInven(NULL, NULL);
				g_pGameMain->m_pInven->SetTradeItemCenterState(FALSE);
				
				if(m_dwState == _TRADE_ITEM_BUY)
				{
//					if(((CINFTradeItemBuy*)m_pTradeItemView[i])->RefreshSendMsg())
					{
						g_pFieldWinSocket->SendMsg( T_FC_MARKET_BASE_INFO_REQUEST, NULL , 0);
						TradeCenterLock(TRUE);
					}

				}
				else if(m_dwState == _TRADE_MY_ITEM_SHOW)
				{
					((CINFTradeMyItemShow*)m_pTradeItemView[i])->RefreshBtnDown();
//					((CINFTradeItemBuy*)m_pTradeItemView[i])->RefreshSendMsg();
				}
				
				// 2014-04-30 by ymjoo 거래소 아이템 회수 버그 수정
				((CINFTradeItemAdd*)m_pTradeItemView[_TRADE_ITEM_ADD])->InitData();
				// END 2014-04-30 by ymjoo 거래소 아이템 회수 버그 수정
			}

			return  INF_MSGPROC_BREAK;
		}		
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemCenter::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(TRUE == m_pImgTapBtn[i]->OnLButtonDown(pt))
		{
			return INF_MSGPROC_BREAK;
		}
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemCenter::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	for(int i = 0; i<MAX_TAPCOUNT; ++i)
	{
		if(i == m_dwState)
			continue;
		if(TRUE == m_pImgTapBtn[i]->OnMouseMove(pt))
		{
			return INF_MSGPROC_BREAK;
		}
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemCenter::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	return INF_MSGPROC_NORMAL;
}

void CINFTradeItemCenter::GetItemName(CItemInfo	* pRefItemInfo, char * pName, BOOL bColor)
{
	CItemInfo* m_pRefItemInfo = pRefItemInfo;
	ITEM	*	m_pRefITEM = pRefItemInfo->GetItemInfo();
	RARE_ITEM_INFO *	m_pRefPrefixRareInfo = m_pRefItemInfo->GetPrefixRareInfo();
	RARE_ITEM_INFO *m_pRefSuffixRareInfo = m_pRefItemInfo->GetSuffixRareInfo();
	CParamFactor *	m_pRefEnchant = 	m_pRefEnchant = m_pRefItemInfo->GetEnchantParamFactor();
	BOOL			m_bEnableItem  = g_pGameMain->GetINFItemInfo()->IsEnableItem( m_pRefItemInfo->GetRealItemInfo() );

	char cTempName[ITEMINFO_ITEM_FULL_NAME] = {0,};
	memset( pName, 0x00, ITEMINFO_ITEM_FULL_NAME);

	if(m_pRefPrefixRareInfo)
	{
		if(bColor)
			wsprintf( pName, "\\g%s\\g", m_pRefPrefixRareInfo->Name );
		else
			wsprintf( pName, "%s", m_pRefPrefixRareInfo->Name );
	}
	if(m_bEnableItem)
	{
		if(g_pGameMain->GetINFItemInfo()->IsStringColor(m_pRefITEM->ItemName))	
		{
			if(bColor)
				wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);				
			else
			{
				RemoveColor(pRefItemInfo, cTempName);
				wsprintf( pName,"%s %s", pName, cTempName);				
			}
			
		}
		else if(m_pRefPrefixRareInfo || m_pRefSuffixRareInfo)
		{
			if(m_pRefEnchant)
			{
				if(bColor)
					wsprintf(pName,"%s \\e%s\\e", pName, m_pRefITEM->ItemName);
				else
					wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);	
			}
			else
			{
				if(bColor)
					wsprintf( pName,"%s \\g%s\\g", pName, m_pRefITEM->ItemName);
				else
					wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);
			}
		}
		else
		{
			if(m_pRefEnchant)
			{
				if(bColor)			
					wsprintf( pName,"%s \\e%s\\e", pName, m_pRefITEM->ItemName);				
				else
					wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);
			}
			else
			{
				wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);				
			}
		}
	}
	else
	{
		if(bColor)
			wsprintf( pName,"%s \\r%s\\r", pName, m_pRefITEM->ItemName);
		else
		{
			if(g_pGameMain->GetINFItemInfo()->IsStringColor(m_pRefITEM->ItemName))	
			{
				RemoveColor(pRefItemInfo, cTempName);
				wsprintf( pName,"%s %s", pName, cTempName);				
			}
			else
				wsprintf( pName,"%s %s", pName, m_pRefITEM->ItemName);
		}
	
	}
	if(m_pRefSuffixRareInfo)
	{
		if(bColor)
			wsprintf( pName, "%s \\g%s\\g", pName, m_pRefSuffixRareInfo->Name );
		else
			wsprintf( pName, "%s %s", pName, m_pRefSuffixRareInfo->Name );
	}

}

void CINFTradeItemCenter::NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum)
{
	char chBuff[32];
	wsprintf(chBuff, "%d", nNum);		
	pNumEditBox->SetString(chBuff, 32);
} 


void CINFTradeItemCenter::RemoveColor(CItemInfo	* pRefItemInfo, char* pChar)
{
	int  nCnt = 0;
	BOOL bContinue = FALSE;
	ITEM *	m_pRefITEM = pRefItemInfo->GetItemInfo();

	for(int i = 0; i<strlen(m_pRefITEM->ItemName); ++i)
	{
		if(m_pRefITEM->ItemName[i] == '\\' || bContinue)
		{
			bContinue ^= TRUE;
			continue;
		}
		else
		{
			pChar[nCnt] = m_pRefITEM->ItemName[i];
			nCnt++;
		}
	}
};

BOOL CINFTradeItemCenter::GetRemainTime(ATUM_DATE_TIME regTime, char* buf)
{
	ATUM_DATE_TIME curServerTime = GetServerDateTime();
	regTime.AddDateTime(0,0,0,0,m_nSellingTime);
	
	if(curServerTime > regTime)
	{
		wsprintf( buf, STRMSG_C_131205_0040);	// "\\r기간만료\\r"
		return FALSE;
	}
	else
	{
		int nRemainSecond = ( regTime.GetTimeInSeconds() - curServerTime.GetTimeInSeconds() );
		
		int m_nDay	= (nRemainSecond ) / 86400;
		int m_nHour	= (nRemainSecond ) % 86400 / 3600;
		int m_nMin	= (nRemainSecond ) % 86400 % 3600 / 60;
		int m_nSec	= (nRemainSecond ) % 86400 % 3600 % 60 / 1;
		
		if (m_nDay)
		{
			wsprintf( buf, STRMSG_C_131205_0041, m_nDay);				// "%d일"
		}
		else if ((m_nDay == NULL) && m_nHour)
		{		
			wsprintf( buf, STRMSG_C_131205_0042, m_nHour);	// "%d시간"
		}
		else if ((m_nDay == NULL) && (m_nHour == NULL) && m_nMin)
		{
			wsprintf( buf, STRMSG_C_131205_0043, m_nMin);			// "%d분"
		}
		else if ((m_nDay == NULL) && (m_nHour == NULL) && (m_nMin  == NULL) && m_nSec)
		{	
			wsprintf( buf, STRMSG_C_131205_0044);				// "1분이하"
		}
	}
	return TRUE;
}

void CINFTradeItemCenter::InitPagePosList()
{
	int nCntX, nCntY;
	nCntX = nCntY = 0;
	for(nCntY=0;nCntY< MAX_SEARCH_PAGE;nCntY++)
	{
		for(nCntX=0;nCntX< MAX_SEARCH_PAGE;nCntX++)
		{
			m_ptPagePosList[nCntY][nCntX].x = -1;
			m_ptPagePosList[nCntY][nCntX].y = -1;
		}
	}	
	
	POINT	ptPagePosList[MAX_SEARCH_PAGE][MAX_SEARCH_PAGE] = 
	{
		// 1자리
		{					
			{PAGE_LIST_WIDTH/2 + 4*PAGE_LIST_WIDTH, 0},								
				
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},
		// 2 자리
		{					
			{4*PAGE_LIST_WIDTH, 0},				
			{5*PAGE_LIST_WIDTH, 0},				
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},
		// 3자리
		{					
			{PAGE_LIST_WIDTH/2 + 3*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 4*PAGE_LIST_WIDTH, 0},				
			{PAGE_LIST_WIDTH/2 + 5*PAGE_LIST_WIDTH, 0},				
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},	
		//4자리
		{					
			{3*PAGE_LIST_WIDTH, 0},
			{4*PAGE_LIST_WIDTH, 0},				
			{5*PAGE_LIST_WIDTH, 0},
			{6*PAGE_LIST_WIDTH, 0},				
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},	
		// 5자리
		{					
			{PAGE_LIST_WIDTH/2 + 2*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 3*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 4*PAGE_LIST_WIDTH, 0},				
			{PAGE_LIST_WIDTH/2 + 5*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 6*PAGE_LIST_WIDTH, 0},				
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},		
		// 6자리
		{								
			{2*PAGE_LIST_WIDTH, 0},
			{3*PAGE_LIST_WIDTH, 0},
			{4*PAGE_LIST_WIDTH, 0},
			
			{5*PAGE_LIST_WIDTH, 0},
			{6*PAGE_LIST_WIDTH, 0},
			{7*PAGE_LIST_WIDTH, 0},				
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},
		// 7자리
		{	
			{PAGE_LIST_WIDTH/2 + PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 2*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 3*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 4*PAGE_LIST_WIDTH, 0},
			
			{PAGE_LIST_WIDTH/2 + 5*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 6*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 7*PAGE_LIST_WIDTH, 0},
			
			{-1, -1},
			{-1, -1},
			{-1, -1},
		},		
		// 8 자리
		{			
			{PAGE_LIST_WIDTH, 0},
			{2*PAGE_LIST_WIDTH, 0},
			{3*PAGE_LIST_WIDTH, 0},
			{4*PAGE_LIST_WIDTH, 0},
			
			{5*PAGE_LIST_WIDTH, 0},
			{6*PAGE_LIST_WIDTH, 0},
			{7*PAGE_LIST_WIDTH, 0},
			{8*PAGE_LIST_WIDTH, 0},
			
			{-1, -1},
			{-1, -1},
		},		
		// 9자리
		{
			{PAGE_LIST_WIDTH/2,	0},
			{PAGE_LIST_WIDTH/2 + PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 2*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 3*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 4*PAGE_LIST_WIDTH, 0},
			
			{PAGE_LIST_WIDTH/2 + 5*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 6*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 7*PAGE_LIST_WIDTH, 0},
			{PAGE_LIST_WIDTH/2 + 8*PAGE_LIST_WIDTH, 0},
			{-1, -1},
		},
		// 10자리 표시
		{
			{0,	0},
			{PAGE_LIST_WIDTH, 0},
			{2*PAGE_LIST_WIDTH, 0},
			{3*PAGE_LIST_WIDTH, 0},
			{4*PAGE_LIST_WIDTH, 0},
			
			{5*PAGE_LIST_WIDTH, 0},
			{6*PAGE_LIST_WIDTH, 0},
			{7*PAGE_LIST_WIDTH, 0},
			{8*PAGE_LIST_WIDTH, 0},
			{9*PAGE_LIST_WIDTH, 0},
			
		},		
		
	};
	memcpy(m_ptPagePosList, ptPagePosList, sizeof(POINT)*MAX_SEARCH_PAGE*MAX_SEARCH_PAGE);
}

void CINFTradeItemCenter::OnCloseInfWnd()
{
	// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
	m_bNormalInflMsgAddTab = TRUE;
	m_bNormalInflMsgBuyTab = TRUE;
#endif
	// END 2014-06-17 거래소 추가작업
	RestoreDeviceObjects();
}

void CINFTradeItemCenter::TradeCenterLock(BOOL bState)
{
	g_pD3dApp->m_bRequestEnable = !bState;
	g_pD3dApp->m_bTradeCenterLock = bState;
}
void CINFTradeItemCenter::BlackBackImgRender()
{
	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->Move(0,0);
		m_pBlackBackImg->SetAniScale(g_pD3dApp->GetBackBufferDesc().Width,g_pD3dApp->GetBackBufferDesc().Height);
		m_pBlackBackImg->Render();
	}
}

void CINFTradeItemCenter::ChangeMaxLenString(char* String, int nLen)
{
 	char chResultBuf[512];
	memset(chResultBuf,0x00,512);
			
	if( strlen(String) > nLen )
	{
		strncpy( chResultBuf, String, nLen );
		chResultBuf[ GetStringBuffPos(chResultBuf, GetStringBuffLen( chResultBuf ) - 1) ]='\0';
		sprintf(String,"%s...", chResultBuf);
	}
}

void CINFTradeItemCenter::SetSellingTime(INT nSellingTime)
{
	m_nSellingTime = nSellingTime;
}