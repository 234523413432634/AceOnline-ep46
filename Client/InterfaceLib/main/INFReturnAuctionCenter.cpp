// INFReturnAuctionCenter.cpp: implementation of the CINFReturnAuctionCenter class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "INFWindow.h"
#include "ItemInfo.h"
#include "Interface.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFInvenExtend.h"
#include "INFItemInfo.h"
#include "INFReturnAuctionCenter.h"
#include "INFReturnAuctionList.h"
#include "INFReturnMyAuctionList.h"
// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "AtumDatabase.h"
//#include "ShuttleChild.h"
//#include "CharacterChild.h"
//#include "INFToolTip.h"
//#include "INFImageBtn.h"
//#include "INFArenaScrollBar.h"
//#include "INFIcon.h"
//#include "StoreData.h"
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define MAX_TAPCOUNT							2
#define	TAP_BTN_POS_Y							49						//탭 버튼 Y위치 
#define	TAP_BTN_POS_LIST_X						217						//탭 버튼 첫번째 탭 x위치 
#define	TAP_BTN_POS_MY_LIST_X					520						//탭 버튼 두번째 탭 x위치 

// MY CASH
#define MYCASH_SPI_LOCATION_X				100
#define MYCASH_SPI_LOCATION_Y				115
#define MYCASH_WP_LOCATION_X				100
#define MYCASH_WP_LOCATION_Y				139


CINFReturnAuctionCenter::CINFReturnAuctionCenter()
{
	int i = 0;
	for(i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		m_pAuctionView[i] = NULL;
		m_pImgTapBtn[i] = NULL;
	}

	for(i = 0 ; i < MONEYCOUNT ; ++i)
	{
		m_pMoneyImg[i] = NULL;
	}

	m_pBackImg = NULL;

	m_pBlackBackImg = NULL;

	m_pItemSl = NULL;

	m_dwState = _RETURN_AUCTION_LIST;

	for(i = 0 ; i < 4 ; ++i)
	{
		m_pBiddingImg[i] = NULL;
		m_pMoneyGetImg[i] = NULL;
		m_pMoneyNoGetImg[i] = NULL;
	}

	// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
	//m_nBiddingCount = 3;

	m_bShowWnd = FALSE;

	int nCnt = 0;
	for(nCnt = 0 ; nCnt < MAX_PAGE_BTN ; nCnt++)
	{
		m_pPageBtn[nCnt] = NULL;
	}

	m_vecOrginItemInfo.clear();

	m_bFistMyViewTapClick = FALSE;

	m_bNeedRestartWnd = FALSE;					// 2014-06-12 by ymjoo 파괴 경매장 추가작업
	m_DAuctionEndTime = GetServerDateTime();	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
}

CINFReturnAuctionCenter::~CINFReturnAuctionCenter()
{
	int i = 0;
	for(i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		SAFE_DELETE(m_pAuctionView[i]);
		SAFE_DELETE(m_pImgTapBtn[i]);
	}

	for(i = 0 ; i < MONEYCOUNT ; ++i)
	{
		SAFE_DELETE(m_pMoneyImg[i]);
	}

	SAFE_DELETE(m_pBackImg);

	SAFE_DELETE(m_pBlackBackImg);

	SAFE_DELETE(m_pItemSl);

	for(i = 0 ; i < 4 ; ++i)
	{
		SAFE_DELETE(m_pBiddingImg[i]);
		SAFE_DELETE(m_pMoneyGetImg[i]);
		SAFE_DELETE(m_pMoneyNoGetImg[i]);
	}

	int nCnt = 0;
	for(nCnt = 0 ; nCnt < MAX_PAGE_BTN ; nCnt++)
	{
		SAFE_DELETE(m_pPageBtn[nCnt]);
	}
}

HRESULT CINFReturnAuctionCenter::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;
	
	if(NULL == m_pAuctionView[_RETURN_AUCTION_LIST])
	{
		m_pAuctionView[_RETURN_AUCTION_LIST] = new CINFReturnAuctionList(this);
		m_pAuctionView[_RETURN_AUCTION_LIST]->InitDeviceObjects();
	}
	
	if(NULL == m_pAuctionView[_RETURN_MY_AUCTION_LIST])
	{
		m_pAuctionView[_RETURN_MY_AUCTION_LIST] = new CINFReturnMyAuctionList(this);
		m_pAuctionView[_RETURN_MY_AUCTION_LIST]->InitDeviceObjects();
	}

	if(NULL == m_pBackImg)		//배경 이미지 
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("ra_bg");					//배경이미지 파일 이름 
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage(pDataHeader);
		m_pBackImg->InitDeviceObjects(g_pD3dApp->m_pImageList);		
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

	pDataHeader = g_pGameMain->FindResource("tc_spi");
	if(pDataHeader)
	{
		if(NULL == m_pMoneyImg[_SPI])
		{
			m_pMoneyImg[_SPI] = new CINFImageEx();
			m_pMoneyImg[_SPI]->InitDeviceObjects(pDataHeader);
		}
	}

	pDataHeader = g_pGameMain->FindResource("tc_wp");
	if(pDataHeader)
	{
		if(NULL == m_pMoneyImg[_WP])
		{
			m_pMoneyImg[_WP] = new CINFImageEx();
			m_pMoneyImg[_WP]->InitDeviceObjects(pDataHeader);
		}
	}

	pDataHeader = g_pGameMain->FindResource("itemsl");
	if(pDataHeader)
	{
		if(NULL == m_pItemSl)
		{
			m_pItemSl = new CINFImageEx();
			m_pItemSl->InitDeviceObjects(pDataHeader);
		}
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];				//탭 버튼 파일 이름 
		wsprintf(szUpBtn, "ra_parti03");
		wsprintf(szDownBtn, "ra_parti01");
		wsprintf(szSelBtn, "ra_parti00");
		wsprintf(szDisBtn, "ra_parti02");
		if(NULL == m_pImgTapBtn[_RETURN_AUCTION_LIST])
		{
			m_pImgTapBtn[_RETURN_AUCTION_LIST] = new CINFImageBtn;
		}
		m_pImgTapBtn[_RETURN_AUCTION_LIST]->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];			//탭 버튼 파일 이름 
		wsprintf(szUpBtn, "ra_state03");
		wsprintf(szDownBtn, "ra_state01");
		wsprintf(szSelBtn, "ra_state00");
		wsprintf(szDisBtn, "ra_state02");
		if(NULL == m_pImgTapBtn[_RETURN_MY_AUCTION_LIST])
		{
			m_pImgTapBtn[_RETURN_MY_AUCTION_LIST] = new CINFImageBtn;
		}
		m_pImgTapBtn[_RETURN_MY_AUCTION_LIST]->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}

	int i  = 0;
	char ImgName[30] = {0, };
	for(i = 0 ; i < 4 ; ++i)
	{
		if(g_pGameMain)
		{
			wsprintf(ImgName, "hurrytm%d", i);
			pDataHeader = g_pGameMain->FindResource(ImgName);
		}
		if(pDataHeader)
		{
			if(NULL == m_pBiddingImg[i])
			{
				m_pBiddingImg[i] = new CINFImageEx();
				m_pBiddingImg[i]->InitDeviceObjects(pDataHeader);
			}
		}
		if(g_pGameMain)
		{
			wsprintf(ImgName, "apps0%d", i);
			pDataHeader = g_pGameMain->FindResource(ImgName);
		}
		if(pDataHeader)
		{
			if(NULL == m_pMoneyGetImg[i])
			{
				m_pMoneyGetImg[i] = new CINFImageEx();
				m_pMoneyGetImg[i]->InitDeviceObjects(pDataHeader);
			}
		}
		if(g_pGameMain)
		{
			wsprintf(ImgName, "cancb%d", i);
			pDataHeader = g_pGameMain->FindResource(ImgName);
		}
		if(pDataHeader)
		{
			if(NULL == m_pMoneyNoGetImg[i])
			{
				m_pMoneyNoGetImg[i] = new CINFImageEx();
				m_pMoneyNoGetImg[i]->InitDeviceObjects(pDataHeader);
			}
		}
	}

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		char szUpBtn[MAX_PAGE_BTN][30], szDownBtn[MAX_PAGE_BTN][30], szSelBtn[MAX_PAGE_BTN][30], szDisBtn[MAX_PAGE_BTN][30];
		
		wsprintf(szUpBtn[PAGE_BTN_FIRST],	"rec_pagef3");
		wsprintf(szDownBtn[PAGE_BTN_FIRST], "rec_pagef1");
		wsprintf(szSelBtn[PAGE_BTN_FIRST],	"rec_pagef0");
		wsprintf(szDisBtn[PAGE_BTN_FIRST],	"rec_pagef2");
		
		wsprintf(szUpBtn[PAGE_BTN_PREV],	"call3");
		wsprintf(szDownBtn[PAGE_BTN_PREV],	"call1");
		wsprintf(szSelBtn[PAGE_BTN_PREV],	"call0");
		wsprintf(szDisBtn[PAGE_BTN_PREV],	"call2");
		
		wsprintf(szUpBtn[PAGE_BTN_NEXT],	"calr3");
		wsprintf(szDownBtn[PAGE_BTN_NEXT],	"calr1");
		wsprintf(szSelBtn[PAGE_BTN_NEXT],	"calr0");
		wsprintf(szDisBtn[PAGE_BTN_NEXT],	"calr2");
		
		wsprintf(szUpBtn[PAGE_BTN_LAST],	"rec_pagee3");
		wsprintf(szDownBtn[PAGE_BTN_LAST],  "rec_pagee1");
		wsprintf(szSelBtn[PAGE_BTN_LAST],	"rec_pagee0");
		wsprintf(szDisBtn[PAGE_BTN_LAST],	"rec_pagee2");
		
		if(NULL == m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt] = new CINFImageBtn;
		}
		m_pPageBtn[nCnt]->InitDeviceObjects(szUpBtn[nCnt], szDownBtn[nCnt], szSelBtn[nCnt], szDisBtn[nCnt]);		
	}

	InitPagePosList();

	return S_OK;
}

HRESULT CINFReturnAuctionCenter::RestoreDeviceObjects()
{
	int i = 0;
	for(i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		m_pAuctionView[i]->RestoreDeviceObjects();
		m_pImgTapBtn[i]->RestoreDeviceObjects();
	}

	for(i = 0 ; i < MONEYCOUNT ; ++i)
	{
		if(m_pMoneyImg[i])
		{
			m_pMoneyImg[i]->RestoreDeviceObjects();
		}
	}

	for(i = 0 ; i < 4 ; ++i)
	{
		if(m_pBiddingImg[i])
		{
			m_pBiddingImg[i]->RestoreDeviceObjects();
		}
		if(m_pMoneyGetImg[i])
		{
			m_pMoneyGetImg[i]->RestoreDeviceObjects();
		}
		if(m_pMoneyNoGetImg[i])
		{
			m_pMoneyNoGetImg[i]->RestoreDeviceObjects();
		}
	}

	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
	}

	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->RestoreDeviceObjects();
	}

	if(m_pItemSl)
	{
		m_pItemSl->RestoreDeviceObjects();
	}

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt]->RestoreDeviceObjects();		
		}
	}

	return S_OK;
}

HRESULT CINFReturnAuctionCenter::DeleteDeviceObjects()
{
	int i = 0;
	for(i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(m_pAuctionView[i])
		{
			m_pAuctionView[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pAuctionView[i]);
		}
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pImgTapBtn[i]);
		}
	}

	for(i = 0 ; i < MONEYCOUNT ; ++i)
	{
		if(m_pMoneyImg[i])
		{
			m_pMoneyImg[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pMoneyImg[i]);
		}
	}

	for(i = 0 ; i < 4 ; ++i)
	{
		if(m_pBiddingImg[i])
		{
			m_pBiddingImg[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pBiddingImg[i]);
		}
		if(m_pMoneyGetImg[i])
		{
			m_pMoneyGetImg[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pMoneyGetImg[i]);
		}
		if(m_pMoneyNoGetImg[i])
		{
			m_pMoneyNoGetImg[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pMoneyNoGetImg[i]);
		}
	}

	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBlackBackImg);
	}

	if(m_pItemSl)
	{
		m_pItemSl->DeleteDeviceObjects();
		SAFE_DELETE(m_pItemSl);
	}

	
	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(m_pPageBtn[nCnt])
		{			
			m_pPageBtn[nCnt]->DeleteDeviceObjects();
			SAFE_DELETE(m_pPageBtn[nCnt]);
		}
		
	}

	return S_OK;
}

HRESULT CINFReturnAuctionCenter::InvalidateDeviceObjects()
{
	int i = 0;
	for(i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(m_pAuctionView[i])
		{
			m_pAuctionView[i]->InvalidateDeviceObjects();
		}
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->InvalidateDeviceObjects();
		}
	}

	for(i = 0 ; i < MONEYCOUNT ; ++i)
	{
		if(m_pMoneyImg[i])
		{
			m_pMoneyImg[i]->InvalidateDeviceObjects();
		}
	}

	for(i = 0 ; i < 4 ; ++i)
	{
		if(m_pBiddingImg[i])
		{
			m_pBiddingImg[i]->InvalidateDeviceObjects();
		}
		if(m_pMoneyGetImg[i])
		{
			m_pMoneyGetImg[i]->InvalidateDeviceObjects();
		}
		if(m_pMoneyNoGetImg[i])
		{
			m_pMoneyNoGetImg[i]->InvalidateDeviceObjects();
		}
	}

	if(m_pBackImg)
	{
		m_pBackImg->InvalidateDeviceObjects();
	}

	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->InvalidateDeviceObjects();
	}

	if(m_pItemSl)
	{
		m_pItemSl->InvalidateDeviceObjects();
	}

	for(int nCnt = 0 ; nCnt < MAX_PAGE_BTN ; ++nCnt)
	{
		if(m_pPageBtn[nCnt])
		{
			m_pPageBtn[nCnt]->InvalidateDeviceObjects();		
		}
	}

	return S_OK;
}

void CINFReturnAuctionCenter::Render()
{
	if(!m_bShowWnd)
	{
		return;
	}

//	BlackBackImgRender();				//검은 배경 

	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	if(m_pAuctionView[m_dwState])
	{
		m_pAuctionView[m_dwState]->Render();		//기본 유아이 배경 
	}

	g_pGameMain->m_pInven->RenderSpi(STARTPOS_X + MYCASH_SPI_LOCATION_X, STARTPOS_Y + MYCASH_SPI_LOCATION_Y);
	g_pGameMain->m_pInven->RenderWp(STARTPOS_X + MYCASH_WP_LOCATION_X, STARTPOS_Y + MYCASH_WP_LOCATION_Y);


	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(m_pImgTapBtn[i])
		{
			m_pImgTapBtn[i]->Render();				//탭	버튼
		}
	}
}

void CINFReturnAuctionCenter::Tick()
{
	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(m_pAuctionView[i])
		{
			m_pAuctionView[i]->Tick();
		}
	}
}

int CINFReturnAuctionCenter::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(INF_MSGPROC_BREAK == m_pAuctionView[m_dwState]->WndProc(uMsg, wParam, lParam))
	{
		return INF_MSGPROC_BREAK;
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

int	CINFReturnAuctionCenter::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(TRUE == m_pImgTapBtn[i]->OnLButtonDown(pt))
		{
			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
			if(m_bNeedRestartWnd && _RETURN_MY_AUCTION_LIST == m_dwState && _RETURN_AUCTION_LIST == i)
			{
				RestartWnd();
			}
			// END 2014-06-12 by ymjoo 파괴 경매장 추가작업

			m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_UP);
			m_pImgTapBtn[i]->SetBtnState(BTN_STATUS_DOWN);
			m_pAuctionView[m_dwState]->ShowWnd(FALSE);
			m_pAuctionView[i]->ShowWnd(TRUE);
			m_dwState = i;

			if(m_dwState == _RETURN_MY_AUCTION_LIST && !m_bFistMyViewTapClick)
			{
				g_pFieldWinSocket->SendMsg(T_FC_DESTROY_AUCTION_MY_LIST_REQUEST, NULL , 0);
//				m_bFistMyViewTapClick = TRUE;
			}
		}
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnAuctionCenter::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(TRUE == m_pImgTapBtn[i]->OnLButtonDown(pt))
		{
			return INF_MSGPROC_BREAK;
		}
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnAuctionCenter::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		if(i == m_dwState)
		{
			continue;
		}
		if(TRUE == m_pImgTapBtn[i]->OnMouseMove(pt))
		{
			return INF_MSGPROC_BREAK;
		}
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFReturnAuctionCenter::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	return INF_MSGPROC_NORMAL;
}

void CINFReturnAuctionCenter::ShowWnd(BOOL bShow)
{
	m_bShowWnd = bShow;
	if(bShow)
	{
		m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_UP);
		m_dwState = _RETURN_AUCTION_LIST;
		m_pImgTapBtn[m_dwState]->SetBtnState(BTN_STATUS_DOWN);
		m_pAuctionView[m_dwState]->ShowWnd(bShow);

		// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
		/*
		m_nBiddingCount = 0;
		CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED);
		if(pItemInfo)
			m_nBiddingCount += pItemInfo->CurrentCount;
		
		if(DESTROY_AUCTION_TENDET_ITEM_NUM_LIMITED != DESTROY_AUCTION_TENDET_ITEM_NUM_UNLIMITED)
		{
			pItemInfo = g_pStoreData->FindItemInInventoryByItemNum(DESTROY_AUCTION_TENDET_ITEM_NUM_UNLIMITED);
			if(pItemInfo)
				m_nBiddingCount += pItemInfo->CurrentCount;
		}
		*/
		// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

		SetBtnPos();

		// 2014-06-12 by ymjoo 파괴 경매장 추가작업
		if(m_bNeedRestartWnd)
		{
			m_bNeedRestartWnd = FALSE;
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_140612_0001, _Q_MARKET_NORMAL_MESSAGE);	// "경매가 시작되었습니다."
		}
		// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
	}
	else
	{
	}
}

void CINFReturnAuctionCenter::SetBtnPos()
{
	if(m_pBackImg)
	{
		m_pBackImg->Move(STARTPOS_X, STARTPOS_Y);
	}
	if(m_pImgTapBtn[_RETURN_AUCTION_LIST])
	{
		m_pImgTapBtn[_RETURN_AUCTION_LIST]->SetBtnPosition(STARTPOS_X + TAP_BTN_POS_LIST_X, STARTPOS_Y + TAP_BTN_POS_Y);
	}
	if(m_pImgTapBtn[_RETURN_MY_AUCTION_LIST])
	{
		m_pImgTapBtn[_RETURN_MY_AUCTION_LIST]->SetBtnPosition(STARTPOS_X + TAP_BTN_POS_MY_LIST_X, STARTPOS_Y + TAP_BTN_POS_Y);
	}
}

void CINFReturnAuctionCenter::BlackBackImgRender()
{
	if(m_pBlackBackImg)
	{
		m_pBlackBackImg->Move(0, 0);
		m_pBlackBackImg->SetAniScale(g_pD3dApp->GetBackBufferDesc().Width, g_pD3dApp->GetBackBufferDesc().Height);
		m_pBlackBackImg->Render();
	}
}

BOOL CINFReturnAuctionCenter::GetRemainTime(ATUM_DATE_TIME regTime, char* buf)
{
	ATUM_DATE_TIME curServerTime = GetServerDateTime();
	
	if(regTime < curServerTime)
	{
		wsprintf(buf, STRMSG_C_140121_0001);	// "\\경매종료\\"
		return FALSE;
	}
	else
	{
		int nRemainSecond = regTime.GetTimeInSeconds() - curServerTime.GetTimeInSeconds();
		
		int m_nDay	= nRemainSecond / 86400;
		int m_nHour	= nRemainSecond % 86400 / 3600;
		int m_nMin	= nRemainSecond % 3600 / 60;
		int m_nSec	= nRemainSecond % 60;
		
		if(0 != m_nDay)
		{
			wsprintf(buf, STRMSG_C_131205_0041, m_nDay);				// "%d일"
		}
		else if(0 != m_nHour)
		{		
			wsprintf(buf, STRMSG_C_131205_0042, m_nHour);				// "%d시간"
		}
		else if(0 != m_nMin)
		{
			wsprintf(buf, STRMSG_C_131205_0043, m_nMin);				// "%d분"
		}
		else if(0 != m_nSec)
		{	
			wsprintf(buf, STRMSG_C_131205_0044);						// "1분이하"
		}
	}
	return TRUE;
}

void CINFReturnAuctionCenter::InitPagePosList()
{
	int nCntX, nCntY;

	for(nCntY = 0 ; nCntY < MAX_SEARCH_PAGE ; ++nCntY)
	{
		for(nCntX = 0 ; nCntX < MAX_SEARCH_PAGE ; ++nCntX)
		{
			m_ptPagePosList[nCntY][nCntX].x = -1;
			m_ptPagePosList[nCntY][nCntX].y = -1;
		}
	}	
	
	// 2014-06-12 by ymjoo 파괴 경매장 추가작업
 	POINT ptPagePosList[MAX_SEARCH_PAGE][MAX_SEARCH_PAGE] =
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
// 	POINT ptPagePosList[MAX_SEARCH_PAGE][MAX_SEARCH_PAGE];
// 	for(int i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
// 	{
// 		for(int j = 0 ; j < MAX_SEARCH_PAGE ; ++j)
// 		{
// 			if(i < j)
// 			{
// 				ptPagePosList[i][j].x = -1;
// 				ptPagePosList[i][j].y = -1;
// 			}
// 			else
// 			{
// 				ptPagePosList[i][j].x = PAGE_LIST_WIDTH * (4 - i / 2);
// 				ptPagePosList[i][j].y = 0;
// 
// 				if(0 == i % 2)
// 				{
// 					ptPagePosList[i][j].x += PAGE_LIST_WIDTH / 2;
// 				}
// 			}
// 		}
//  	}
	// END 2014-06-12 by ymjoo 파괴 경매장 추가작업

	memcpy(m_ptPagePosList, ptPagePosList, sizeof(POINT) * MAX_SEARCH_PAGE * MAX_SEARCH_PAGE);
}

void CINFReturnAuctionCenter::ChangeMaxLenString(char* String, int nLen)
{
	char chResultBuf[512];
	memset(chResultBuf, 0x00, 512);
	
	if(nLen < strlen(String))
	{
		strncpy(chResultBuf, String, nLen);
		chResultBuf[GetStringBuffPos(chResultBuf, GetStringBuffLen(chResultBuf) - 1)] = '\0';
		sprintf(String, "%s...", chResultBuf);
	}
}

void CINFReturnAuctionCenter::GetItemName(CItemInfo* pRefItemInfo, char* pName, BOOL bColor)
{
	CItemInfo*			m_pRefItemInfo			= pRefItemInfo;
	ITEM*				m_pRefITEM				= pRefItemInfo->GetItemInfo();
	RARE_ITEM_INFO*		m_pRefPrefixRareInfo	= m_pRefItemInfo->GetPrefixRareInfo();
	RARE_ITEM_INFO*		m_pRefSuffixRareInfo	= m_pRefItemInfo->GetSuffixRareInfo();
	CParamFactor*		m_pRefEnchant			= m_pRefItemInfo->GetEnchantParamFactor();
	BOOL				m_bEnableItem			= g_pGameMain->GetINFItemInfo()->IsEnableItem(m_pRefItemInfo->GetRealItemInfo());
	
	char cTempName[ITEMINFO_ITEM_FULL_NAME] = {0, };
	memset(pName, 0x00, ITEMINFO_ITEM_FULL_NAME);
	
	if(m_pRefPrefixRareInfo)
	{
		if(bColor)
		{
			wsprintf(pName, "\\g%s\\g", m_pRefPrefixRareInfo->Name);
		}
		else
		{
			wsprintf(pName, "%s", m_pRefPrefixRareInfo->Name);
		}
	}

	if(m_bEnableItem)
	{
		if(g_pGameMain->GetINFItemInfo()->IsStringColor(m_pRefITEM->ItemName))	
		{
			if(bColor)
			{
				wsprintf( pName, "%s %s", pName, m_pRefITEM->ItemName);
			}
			else
			{
				RemoveColor(pRefItemInfo, cTempName);
				wsprintf(pName, "%s %s", pName, cTempName);				
			}
		}
		else if(m_pRefPrefixRareInfo || m_pRefSuffixRareInfo)
		{
			if(m_pRefEnchant)
			{
				if(bColor)
				{
					wsprintf(pName, "%s \\e%s\\e", pName, m_pRefITEM->ItemName);
				}
				else
				{
					wsprintf(pName, "%s %s", pName, m_pRefITEM->ItemName);
				}
			}
			else
			{
				if(bColor)
				{
					wsprintf(pName, "%s \\g%s\\g", pName, m_pRefITEM->ItemName);
				}
				else
				{
					wsprintf(pName, "%s %s", pName, m_pRefITEM->ItemName);
				}
			}
		}
		else
		{
			if(m_pRefEnchant)
			{
				if(bColor)
				{
					wsprintf(pName, "%s \\e%s\\e", pName, m_pRefITEM->ItemName);
				}
				else
				{
					wsprintf(pName, "%s %s", pName, m_pRefITEM->ItemName);
				}
			}
			else
			{
				wsprintf(pName, "%s %s", pName, m_pRefITEM->ItemName);
			}
		}
	}
	else
	{
		if(bColor)
		{
			wsprintf(pName, "%s \\r%s\\r", pName, m_pRefITEM->ItemName);
		}
		else
		{
			if(g_pGameMain->GetINFItemInfo()->IsStringColor(m_pRefITEM->ItemName))	
			{
				RemoveColor(pRefItemInfo, cTempName);
				wsprintf(pName, "%s %s", pName, cTempName);				
			}
			else
			{
				wsprintf(pName, "%s %s", pName, m_pRefITEM->ItemName);
			}
		}
	}
	if(m_pRefSuffixRareInfo)
	{
		if(bColor)
		{
			wsprintf(pName, "%s \\g%s\\g", pName, m_pRefSuffixRareInfo->Name);
		}
		else
		{
			wsprintf(pName, "%s %s", pName, m_pRefSuffixRareInfo->Name);
		}
	}
}

void CINFReturnAuctionCenter::RemoveColor(CItemInfo* pRefItemInfo, char* pChar)
{
	int nCnt = 0;
	BOOL bContinue = FALSE;
	ITEM* m_pRefITEM = pRefItemInfo->GetItemInfo();
	
	for(int i = 0 ; i < strlen(m_pRefITEM->ItemName) ; ++i)
	{
		if('\\' == m_pRefITEM->ItemName[i] || bContinue)
		{
			bContinue ^= TRUE;
			continue;
		}
		else
		{
			pChar[nCnt] = m_pRefITEM->ItemName[i];
			++nCnt;
		}
	}
}

void CINFReturnAuctionCenter::OnCloseInfWnd()
{
	m_bFistMyViewTapClick = FALSE;
	ShowWnd(FALSE);
}

void CINFReturnAuctionCenter::VecItemInfoClear(MSG_FC_DESTROY_AUCTION_BASE_INFO_HEADER* pMsg)
{
	if(NULL != pMsg)
	{
		m_DAuctionEndTime = pMsg->DAuctionEndTime;
	}

	SetBtnPos();

	for(int i = 0 ; i < MAX_TAPCOUNT ; ++i)
	{
		m_pAuctionView[i]->VecItemInfoClear();
	}
	
	if(0 < m_vecOrginItemInfo.size())
	{
		vector<AUCTION_MY_ITEM_INFO*>::iterator it;
		for(it = m_vecOrginItemInfo.begin() ; it != m_vecOrginItemInfo.end() ;)
		{
			AUCTION_MY_ITEM_INFO* pMarketItem = *it;
			if(pMarketItem)
			{
				SAFE_DELETE(pMarketItem->pINFO);
				SAFE_DELETE(pMarketItem->pItem);
				SAFE_DELETE(pMarketItem);
				it = m_vecOrginItemInfo.erase(it);
			}
			else
			{
				++it;
			}
		}
		if(false == m_vecOrginItemInfo.empty())
		{
			m_vecOrginItemInfo.clear();
		}
	}
}

void CINFReturnAuctionCenter::ItemVecAdd(MSG_FC_DESTROY_AUCTION_BASE_INFO_OK* pMsg)
{
	AUCTION_MY_ITEM_INFO* pTemp = new AUCTION_MY_ITEM_INFO;
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

	GetItemName(pTemp->pItem, pTemp->Name, FALSE);

	m_vecOrginItemInfo.push_back(pTemp);
}

AUCTION_MY_ITEM_INFO* CINFReturnAuctionCenter::GetAuctionItemInfo(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg)
{
	AUCTION_MY_ITEM_INFO* pData = NULL;
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	for(it = m_vecOrginItemInfo.begin() ; it != m_vecOrginItemInfo.end() ; ++it)
	{
		pData = *it;
		if(pMsg->DAuctionUID == pData->pINFO->DAuctionInfo.DAuctionUID)
		{
			return pData;
		}
	}
	return NULL;
}

AUCTION_MY_ITEM_INFO* CINFReturnAuctionCenter::GetAuctionItemInfo(UID64_t DAuctionUID)
{
	AUCTION_MY_ITEM_INFO* pData = NULL;
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	for(it = m_vecOrginItemInfo.begin() ; it != m_vecOrginItemInfo.end() ; ++it)
	{
		pData = *it;
		if(DAuctionUID == pData->pINFO->DAuctionInfo.DAuctionUID)
		{
			return pData;
		}
	}
	return NULL;
}

void CINFReturnAuctionCenter::UpdateDataInfo(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg)
{
	AUCTION_MY_ITEM_INFO* pData = NULL;
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	for(it = m_vecOrginItemInfo.begin() ; it != m_vecOrginItemInfo.end() ; ++it)
	{
		pData = *it;
		if(pMsg->DAuctionUID == pData->pINFO->DAuctionInfo.DAuctionUID)
		{
			pData->pINFO->DAuctionInfo.AccountUID	= pMsg->AccountUID;
			pData->pINFO->DAuctionInfo.CharacterUID	= pMsg->CharacterUID;
			pData->pINFO->DAuctionInfo.Price		= pMsg->TenderPrice;
			return;
		}
	}
}

void CINFReturnAuctionCenter::VecItemStateEnd()
{
	AUCTION_MY_ITEM_INFO* pData = NULL;
	vector<AUCTION_MY_ITEM_INFO*>::iterator it;
	for(it = m_vecOrginItemInfo.begin() ; it != m_vecOrginItemInfo.end() ; ++it)
	{
		pData = *it;
		if(pData)
		{
			pData->pINFO->DAuctionInfo.DAuctionState	= AUCTION_ITEM_STATE_END;
			pData->pINFO->DAuctionInfo.DAuctionEndTime	= m_DAuctionEndTime;
		}
	}
}

void CINFReturnAuctionCenter::RestartWnd()
{
	g_pInterface->m_pCityBase->CloseCurrentEnterBuilding();
	g_pGameMain->PopupReturnAuctionWnd();
}