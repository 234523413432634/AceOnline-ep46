// INFTradeItemBuy.cpp: implementation of the CINFTradeItemBuy class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "INFWindow.h"
#include "ItemInfo.h"
#include "Interface.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFIcon.h"
#include "INFImageListTreeCtrl.h"		// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
#include "INFListBox.h"
#include "INFTradeItemCenter.h"
#include "INFNumEditBox.h"
#include "INFTradeItemBuy.h"
// 2014-06-17 거래소 추가작업 (주석 처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "CharacterChild.h"
//#include "AtumSound.h"
//#include "INFEditBox.h"
//#include "INFAutoEditBox.h"
//#include "INFImageBtn.h"
//#include "INFListBox.h"
//#include "INFArenaScrollBar.h"
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

// 검색어 입력
#define NAMEEDITBOX_LOCATION_X				240
#define NAMEEDITBOX_LOCATION_Y				107
#define NAMEEDITBOX_POSITION				{232, 102}
#define NAMEEDITBOX_WIDTH					390
#define NAMEEDITBOX_CAP						28

// 레벨, 인챈트 입력
#define NUMEDITBOX_POSITION					{307, 470}
#define NUMEDITBOX_WIDTH					26
#define NUMEDITBOX_CAP						20
#define MINLEVEL_NUMEDITBOX_LOCATION_X		253
#define MAXLEVEL_NUMEDITBOX_LOCATION_X		298
#define MINENCHANT_NUMEDITBOX_LOCATION_X	386
#define MAXENCHANT_NUMEDITBOX_LOCATION_X	431
#define NUMEDITBOX_LOCATION_Y				142
#define MINLEVEL							1
#define MAXLEVEL							110
#define MINENCHANT							1
#define MAXENCHANT							40 

// 기체, 돈 선택
#define	GEAR_COMBO_LOCATION_X				477
#define MONEY_COMBO_LOCATION_X				600
#define	GEAR_MONEY_COMBO_LOCATION_Y			142
#define GEAR_MONEY_COMBO_MAIN_WIDTH			103
#define GEAR_MONEY_COMBO_MAIN_HEIGHT		17
#define GEAR_MONEY_COMBO_ELE_WIDTH			87
#define GEAR_MONEY_COMBO_ELE_HEIGHT			15	

// 초기화, 검색, 구매, 새로고침 버튼
#define INITBTN_LOCATION_X					629
#define INITBTN_LOCATION_Y					101
#define SEARCHBTN_LOCATION_X				726
#define SEARCHBTN_LOCATION_Y				92
#define BUYBTN_LOCATION_X					824
#define BUYBTN_LOCATION_Y					92
#define REFRESHBTN_LOCATION_X				879
#define REFRESHBTN_LOCATION_Y				182	

// 아이템 수
#define TOTALITEMCNT_LOCATION_X				875
#define TOTALITEMCNT_LOCATION_Y				186

// 카테고리
#define CATEGORY_LOCATION_X					26
#define CATEGORY_LOCATION_Y					204
#define CATEGORY_WIDTH						154
#define CATEGORY_HEIGHT						385
#define CATEGORY_SUBITEM_LOCATION_X			21
#define CATEGORY_SUBITEM_LOCATION_Y			5
#define CATEGORY_SCROLL_LOCATION_X			154
#define CATEGORY_SCROLL_LOCATION_Y			-5

// 검색 카테고리 경로
#define CATEGORYPATH_LOCATION_X				224
#define CATEGORYPATH_LOCATION_Y				190
#define CATEGORYPATH_COLOR					0xA7C4DB
#define CATEGORYPATH_ICON_LOCATION_X		219
#define CATEGORYPATH_ICON_LOCATION_Y		194

// 아이템 리스트 정렬 버튼
#define SORTBTN_LOCATION_Y					209
#define SORTBTN_ENCHANT_LOCATION_X			324
#define SORTBTN_ENCHANT_LEFT_X				278
#define SORTBTN_ENCHANT_WIDTH				58
#define SORTBTN_NAME_LOCATION_X				605
#define SORTBTN_NAME_LEFT_X					337
#define SORTBTN_NAME_WIDTH					280
#define SORTBTN_LEVEL_LOCATION_X			664
#define SORTBTN_LEVEL_LEFT_X				618
#define SORTBTN_LEVEL_WIDTH					58
#define SORTBTN_REGISTTIME_LOCATION_X		739
#define SORTBTN_REGISTTIME_LEFT_X			677
#define SORTBTN_REGISTTIME_WIDTH			73
#define SORTBTN_PRICE_LOCATION_X			889
#define SORTBTN_PRICE_LEFT_X				751
#define SORTBTN_PRICE_WIDTH					150

// 아이템 리스트
#define ITEMLIST_LOCATION_X					219
#define ITEMLIST_LOCATION_Y					230
#define ITEMLIST_WIDTH						684
#define ITEMLIST_HEIGHT						328
#define ITEMLIST_CELL_HEIGHT				40
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
#define ITEMLIST_MAXITEMNAME_LEN			45

// 페이지 버튼
#define PAGEBTN_LOCATION_X					395
#define PAGEBTN_LOCATION_Y					566
#define PAGEBTN_FIRST_LOCATION_X			-32
#define PAGEBTN_PREV_LOCATION_X				-18
#define PAGEBTN_NEXT_LOCATION_X				0
#define PAGEBTN_LAST_LOCATION_X				10


CINFTradeItemBuy::CINFTradeItemBuy(CAtumNode* pParent)
{
	m_pParent = pParent;
	m_pBackImg = NULL;
	memset(&m_ptStartPos, 0x00, sizeof(POINT));

	//m_pListCtrl = NULL;
	m_pListTreeCtrl = NULL;				// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	m_pGearComboBox = NULL;
	m_pMoneyComboBox = NULL;
	m_fParentPosY = 0;

	m_pSearchBtn = NULL;
	m_pBuyBtn = NULL;
	m_pInitBtn = NULL;
	m_pRefreshBtn = NULL;
	m_nSelectListItem	 = -1;

	m_pSelectImg = NULL;

	m_pNameEditBox = NULL;

	int i;
	for(i = 0; i<2; ++i)
	{
		m_plevelNumEditBox[i] = NULL;
		m_pEnchantNumEditBox[i] = NULL;
	}
	//m_pCategorytree = NULL;
	m_pItemCategorytree = NULL;			// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

	for(i = 0; i<3; ++i)
	{
		m_pSortImg[i] = NULL;
	}

	m_pTotalItemCountFont = NULL;

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			m_pListFont[i][j] = NULL;
		}
	}
#else
	m_pListFont = NULL;
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	m_nCurrentPage = 1;
	m_nStartPage = 1;

	m_nOldCurrentPage = 1;
	m_nOldStartPage = 1;

	m_nTotalItemCount = 0;

	m_pIconInfo = NULL;

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
	
	m_pCategoryPathArrowImage = NULL;	// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	m_pFontCategoryPath = NULL;			// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	m_nSelectedCategoryId = 0;			// 초기값 : 전체			   
	
	m_bRefreshState = FALSE;
	m_fRefreshTime = -1.0f;

	m_nCurerntInfo = NULL;
	m_vecItemInfo.clear();

	m_bRenderState = FALSE;

	m_nCurrentSortType = 0;
	m_nOldSortType = 0;

}	

CINFTradeItemBuy::~CINFTradeItemBuy()
{
	SAFE_DELETE(m_pBackImg);
	//SAFE_DELETE(m_pListCtrl);
	SAFE_DELETE(m_pListTreeCtrl);		// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	SAFE_DELETE(m_pGearComboBox);
	SAFE_DELETE(m_pMoneyComboBox);

	SAFE_DELETE(m_pSearchBtn); 
	SAFE_DELETE(m_pBuyBtn);
	SAFE_DELETE(m_pInitBtn);
	SAFE_DELETE(m_pRefreshBtn);

	SAFE_DELETE(m_pSelectImg);
	int i;
	for(i = 0; i<2; ++i)
	{
		SAFE_DELETE(m_plevelNumEditBox[i]);
		SAFE_DELETE(m_pEnchantNumEditBox[i]);
	}
	for(i = 0; i<3; ++i)
	{
		SAFE_DELETE(m_pSortImg[i]);
	}
	SAFE_DELETE(m_pNameEditBox);

	SAFE_DELETE(m_pTotalItemCountFont);

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			SAFE_DELETE(m_pListFont[i][j]);
		}
	}
#else
	SAFE_DELETE(m_pListFont);
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	SAFE_DELETE(m_pConuntFont);
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		SAFE_DELETE(m_pCountFont[i]);
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	
	SAFE_DELETE(m_pCategoryPathArrowImage);		// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	SAFE_DELETE(m_pFontCategoryPath);			// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
}

HRESULT CINFTradeItemBuy::InitDeviceObjects()
{

	m_ptStartPos.x = (g_pD3dApp->GetBackBufferDesc().Width - TRADEITEMBUY_WIDTH) /2;
	m_ptStartPos.y = CITY_BASE_NPC_BOX_START_Y  - (TRADEITEMBUY_HEIGHT - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT));

	DataHeader *pDataHeader = NULL;

	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("tc_buy");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage( pDataHeader );
		m_pBackImg->InitDeviceObjects( g_pD3dApp->m_pImageList );		
	}

	{
		char chPlus[30], chMinus[30], chItem[30], chSel[30];
		wsprintf(chPlus, "m_plus");
		wsprintf(chMinus, "m_minus");
		wsprintf(chItem, "misradn");
		wsprintf(chSel, "tc_catesel");
		// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
		/*
		if(NULL == m_pListCtrl)
		{
			m_pListCtrl = new CINFImageListCtrl();
		}
		m_pListCtrl->InitDeviceObjects(20);
		m_pListCtrl->InitDeviceEtc(chPlus, chMinus, chItem, chSel);
		m_pListCtrl->SetTextList(TRUE);
		*/
		if(NULL == m_pListTreeCtrl)								
		{
			m_pListTreeCtrl = new CINFImageListTreeCtrl();
		}
		m_pListTreeCtrl->InitDeviceObjects(20);
		m_pListTreeCtrl->InitDeviceEtc(chPlus, chMinus, chItem, chSel);
		m_pListTreeCtrl->SetTextList(TRUE);
		// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

		LoadListItem();
	}

	if(NULL == m_pGearComboBox)
	{
		m_pGearComboBox = new CINFListBox("cbarena","cbarenab");

		m_pGearComboBox->SetUseCulling(TRUE); //글씨 컬링 사용
		m_pGearComboBox->InitDeviceObjects();
	}

	if(NULL == m_pMoneyComboBox)
	{
		m_pMoneyComboBox = new CINFListBox("cbarena","cbarenab");
		
		m_pMoneyComboBox->SetUseCulling(TRUE); //글씨 컬링 사용
		m_pMoneyComboBox->InitDeviceObjects();

	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_sbtn03");
		wsprintf(szDownBtn, "tc_sbtn01");
		wsprintf(szSelBtn, "tc_sbtn00");
		wsprintf(szDisBtn, "tc_sbtn02");

		if(NULL == m_pSearchBtn)
		{
			m_pSearchBtn = new CINFImageBtn;
		}
		m_pSearchBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_bbtn03");
		wsprintf(szDownBtn, "tc_bbtn01");
		wsprintf(szSelBtn, "tc_bbtn00");
		wsprintf(szDisBtn, "tc_bbtn02");
		if(NULL == m_pBuyBtn)
		{
			m_pBuyBtn = new CINFImageBtn;
		}
		m_pBuyBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_ini03");
		wsprintf(szDownBtn, "tc_ini01");
		wsprintf(szSelBtn, "tc_ini00");
		wsprintf(szDisBtn, "tc_ini02");
		if(NULL == m_pInitBtn)
		{
			m_pInitBtn = new CINFImageBtn;
		}
		m_pInitBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
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

	if(g_pGameMain)
		pDataHeader = g_pGameMain->FindResource("tc_listsel");
	if(pDataHeader)
	{
		if(NULL == m_pSelectImg)
		{
			m_pSelectImg = new CINFImageEx();
			m_pSelectImg->InitDeviceObjects(pDataHeader);
		}
	}

	{
		char ImgName[30] = {0,};
		for(int i = 0; i<3; ++i)
		{
			if(g_pGameMain)
			{
				if(i == 2)
					wsprintf(ImgName,"tc_sort0%d", i+1);
				else
					wsprintf(ImgName,"tc_sort0%d", i);
				pDataHeader = g_pGameMain->FindResource(ImgName);
			}
			if(pDataHeader)
			{
				if(NULL == m_pSortImg[i])
				{
					m_pSortImg[i] = new CINFImageEx();
					m_pSortImg[i]->InitDeviceObjects(pDataHeader);
				}
			}
		}
	}

	int i;
	for(i = 0; i<2; ++i)
	{
		if(NULL == m_plevelNumEditBox[i])
		{
			m_plevelNumEditBox[i] = new CINFNumEditBox;
		}
		char chMaxMixCnt[64];
		
		wsprintf(chMaxMixCnt, "%d", MAXLEVEL);
		
		POINT ptPos = NUMEDITBOX_POSITION;
		m_plevelNumEditBox[i]->InitDeviceObjects(9, ptPos, NUMEDITBOX_WIDTH, TRUE, NUMEDITBOX_CAP);				
		m_plevelNumEditBox[i]->SetMaxStringLen(strlen(chMaxMixCnt));
		m_plevelNumEditBox[i]->SetString(" ", 32);

		if(NULL == m_pEnchantNumEditBox[i])
		{
			m_pEnchantNumEditBox[i] = new CINFNumEditBox;
		}
		
		wsprintf(chMaxMixCnt, "%d", MAXENCHANT);
		
		m_pEnchantNumEditBox[i]->InitDeviceObjects(9, ptPos, NUMEDITBOX_WIDTH, TRUE, NUMEDITBOX_CAP);				
		m_pEnchantNumEditBox[i]->SetMaxStringLen(strlen(chMaxMixCnt));
		m_pEnchantNumEditBox[i]->SetString(" ", 32);
	}

	{
		if(NULL == m_pNameEditBox)
		{
			m_pNameEditBox = new CINFEditBox;
		}
		POINT ptPos = NAMEEDITBOX_POSITION;
		m_pNameEditBox->InitDeviceObjects(9, ptPos, NAMEEDITBOX_WIDTH, TRUE, NAMEEDITBOX_CAP);				
		m_pNameEditBox->SetStringMaxBuff(SIZE_MAX_ARENA_FULL_NAME);
	}
	
	if(NULL == m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);		
		m_pTotalItemCountFont->InitDeviceObjects(g_pD3dDev) ;
	}

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
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
#else
 	if(NULL == m_pListFont)
 	{
 		m_pListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
 		m_pListFont->InitDeviceObjects(g_pD3dDev);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	if(NULL == m_pConuntFont)
	{
		m_pConuntFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 1024, 32);
		m_pConuntFont->InitDeviceObjects(g_pD3dDev) ;
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < MAX_SEARCH_PAGE ; ++i)
	{
		if(NULL == m_pCountFont[i])
		{
			m_pCountFont[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 0, D3DFONT_ZENABLE, TRUE, 1024, 32);
			m_pCountFont[i]->InitDeviceObjects(g_pD3dDev);
		}
	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	
	// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	if(NULL == m_pCategoryPathArrowImage)
	{
		m_pCategoryPathArrowImage = new CINFImageEx;
		pDataHeader = g_pGameMain->FindResource("tc_arrow");
		m_pCategoryPathArrowImage->InitDeviceObjects(pDataHeader);
	}		
	
	if(NULL == m_pFontCategoryPath)
	{
		m_pFontCategoryPath = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, FALSE, 1024, 32);
		m_pFontCategoryPath->InitDeviceObjects(g_pD3dDev);
	}
	// END 2013-12-04 by ymjoo 거래소 카테고리 경로 표시

	return S_OK;
}
HRESULT CINFTradeItemBuy::RestoreDeviceObjects()
{
	m_ptStartPos.x = (g_pD3dApp->GetBackBufferDesc().Width - TRADEITEMBUY_WIDTH) /2;
	m_ptStartPos.y = CITY_BASE_NPC_BOX_START_Y  - (TRADEITEMBUY_HEIGHT - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT));
	m_nSelectListItem = -1;
	m_nSelectedCategoryId = 0;			// 초기값 : 전체

	m_nCurrentPage	= 1;	
	m_nStartPage	= 1;

	m_nOldCurrentPage = 1;
	m_nOldStartPage = 1;

	m_nCurrentSortType = 0;
	m_nOldSortType = 0;
	
	m_pIconInfo = g_pGameMain->m_pIcon;

	InitBtnClick();

	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
		m_pBackImg->Move(m_ptStartPos.x + BACKIMAGE_LOCATION_X, m_ptStartPos.y + BACKIMAGE_LOCATION_Y);
	}

	if(m_pInitBtn)
		m_pInitBtn->RestoreDeviceObjects();
	if(m_pSearchBtn)
		m_pSearchBtn->RestoreDeviceObjects();
	if(m_pBuyBtn)
		m_pBuyBtn->RestoreDeviceObjects();
	if(m_pRefreshBtn)
		m_pRefreshBtn->RestoreDeviceObjects();

	if(m_pSelectImg)
		m_pSelectImg->RestoreDeviceObjects();

	{
		for(int i = 0; i<3; ++i)
		{	
			if(m_pSortImg[i])
				m_pSortImg[i]->RestoreDeviceObjects();
		}
	}

	if(m_pTotalItemCountFont)
		m_pTotalItemCountFont->RestoreDeviceObjects();

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int i;
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->RestoreDeviceObjects();
			}
		}
	}
#else
 	if(m_pListFont)
 		m_pListFont->RestoreDeviceObjects();
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

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

//	VecItemInfoClear();
	
	for(i =0; i<5; ++i)
	{
		m_strSortBtn[i].bySortState = NON_SORT;
	}

	SetbtnPos();
		
	// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	if(m_pCategoryPathArrowImage)
		m_pCategoryPathArrowImage->RestoreDeviceObjects();

	if(m_pFontCategoryPath)
		m_pFontCategoryPath->RestoreDeviceObjects();
	// END 2013-12-04 by ymjoo 거래소 카테고리 경로 표시

	if(g_pInterface && g_pInterface->m_pGameMain)						//인터페이스 끄도록 변경 
		g_pInterface->m_pGameMain->InitShowWindow();

	return S_OK;
}
HRESULT CINFTradeItemBuy::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	/*
	if(m_pListCtrl)
	{
		m_pListCtrl->DeleteDeviceObjects();
		SAFE_DELETE(m_pListCtrl)
	}
	*/
	if(m_pListTreeCtrl)
	{
		m_pListTreeCtrl->DeleteDeviceObjects();
		SAFE_DELETE(m_pListTreeCtrl);
	}
	// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	
	if(m_pGearComboBox)
	{
		m_pGearComboBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pGearComboBox);
	}
	
	if(m_pMoneyComboBox)
	{
		m_pMoneyComboBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMoneyComboBox);
	}

	if(m_pRefreshBtn)
	{
		m_pRefreshBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pRefreshBtn);
	}

	if(m_pSearchBtn)
	{
		m_pSearchBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pSearchBtn);
	}

	if(m_pBuyBtn)
	{
		m_pBuyBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pBuyBtn);
	}

	if(m_pInitBtn)
	{
		m_pInitBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pInitBtn);
	}
	
	if(m_pSelectImg)
	{
		m_pSelectImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pSelectImg);
	}
	int i;
	for(i = 0; i<2; ++i)
	{
		if(m_plevelNumEditBox[i])
		{
			m_plevelNumEditBox[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_plevelNumEditBox[i]);
		}
		if(m_pEnchantNumEditBox[i])
		{
			m_pEnchantNumEditBox[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pEnchantNumEditBox[i]);

		}
	}
	for(i = 0; i<3; ++i)
	{	
		if(m_pSortImg[i])
		{
			m_pSortImg[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pSortImg[i]);
		}
	}
	if(m_pNameEditBox)
	{
		m_pNameEditBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pNameEditBox);
	}

	if(m_pTotalItemCountFont)
	{
		m_pTotalItemCountFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pTotalItemCountFont);
	}
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
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
#else
 	if(m_pListFont)
 	{
 		m_pListFont->DeleteDeviceObjects();
 		SAFE_DELETE(m_pListFont);
 	}
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

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
	// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	if(m_pCategoryPathArrowImage)
	{
		m_pCategoryPathArrowImage->DeleteDeviceObjects();
		SAFE_DELETE(m_pCategoryPathArrowImage);
	}

	if(m_pFontCategoryPath)
	{
		m_pFontCategoryPath->DeleteDeviceObjects();
		SAFE_DELETE(m_pFontCategoryPath);
	}
	// END 2013-12-04 by ymjoo 거래소 카테고리 경로 표시

	return S_OK;
}
HRESULT CINFTradeItemBuy::InvalidateDeviceObjects()
{
	if(m_pBackImg)
		m_pBackImg->InvalidateDeviceObjects();

	if(m_pGearComboBox)
		m_pGearComboBox->InvalidateDeviceObjects();
	if(m_pMoneyComboBox)
		m_pMoneyComboBox->InvalidateDeviceObjects();

	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	/*
	if(m_pListCtrl)
		m_pListCtrl->InvalidateDeviceObjects();
		*/
	if(m_pListTreeCtrl)
		m_pListTreeCtrl->InvalidateDeviceObjects();
	// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

	if(m_pRefreshBtn)
		m_pRefreshBtn->InvalidateDeviceObjects();

	if(m_pSearchBtn)
		m_pSearchBtn->InvalidateDeviceObjects();

	if(m_pInitBtn)
		m_pInitBtn->InvalidateDeviceObjects();

	if(m_pBuyBtn)
		m_pBuyBtn->InvalidateDeviceObjects();

	if(m_pSelectImg)
		m_pSelectImg->InvalidateDeviceObjects();

	int i;
	for(i = 0; i<2; ++i)
	{
		if(m_plevelNumEditBox[i])
		{
			m_plevelNumEditBox[i]->InvalidateDeviceObjects();
		}
		if(m_pEnchantNumEditBox[i])
		{
			m_pEnchantNumEditBox[i]->InvalidateDeviceObjects();
		}
	}

	if(m_pNameEditBox)
		m_pNameEditBox->InvalidateDeviceObjects();

	if(m_pTotalItemCountFont)
		m_pTotalItemCountFont->InvalidateDeviceObjects();

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < 8 ; ++i)
	{
		for(int j = 0 ; j < 6 ; ++j)
		{
			if(m_pListFont[i][j])
			{
				m_pListFont[i][j]->InvalidateDeviceObjects();
			}
		}
	}
#else
 	if(m_pListFont)
 		m_pListFont->InvalidateDeviceObjects();
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

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
	
	// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
	if(m_pCategoryPathArrowImage)
		m_pCategoryPathArrowImage->InvalidateDeviceObjects();

	if(m_pFontCategoryPath)
		m_pFontCategoryPath->InvalidateDeviceObjects();
	// END 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
			
	for(i = 0; i<3; ++i)
	{	
		if(m_pSortImg[i])
		{
			m_pSortImg[i]->InvalidateDeviceObjects();
		}
	}


	return S_OK;
}
void CINFTradeItemBuy::Render()
{
	// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
	if(((CINFTradeItemCenter*)m_pParent)->m_bNormalInflMsgBuyTab && IS_NORMAL_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
	{
		((CINFTradeItemCenter*)m_pParent)->m_bNormalInflMsgBuyTab = FALSE;
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060613_0000, _Q_MARKET_NORMAL_MESSAGE);		// "세력 선택전까지는 거래를 할 수 없습니다."
	}
#endif
	// END 2014-06-17 거래소 추가작업

	if(m_pBackImg)
		m_pBackImg->Render();

	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	/*
	if(m_pListCtrl)
		m_pListCtrl->Render();
		*/
	if(m_pListTreeCtrl)
		m_pListTreeCtrl->Render();
	// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

	if(m_pGearComboBox)
		m_pGearComboBox->Render();

	if(m_pMoneyComboBox)
		m_pMoneyComboBox->Render();

	if(m_pRefreshBtn)
		m_pRefreshBtn->Render();

	if(m_pInitBtn)
		m_pInitBtn->Render();

	if(m_pBuyBtn)
		m_pBuyBtn->Render();

	if(m_pSearchBtn)
		m_pSearchBtn->Render();

	if(m_pSelectImg && m_nSelectListItem >=0)
	{
		m_pSelectImg->Move(m_ptStartPos.x + ITEMLIST_LOCATION_X, 
						   m_ptStartPos.y + ITEMLIST_LOCATION_Y-1 + m_nSelectListItem * (ITEMLIST_CELL_HEIGHT+1));
		m_pSelectImg->Render();
	}

	for(int i = 0; i<2; ++i)
	{
		if(m_plevelNumEditBox[i])
		{
			m_plevelNumEditBox[i]->Render();
		}
		if(m_pEnchantNumEditBox[i])
		{
			m_pEnchantNumEditBox[i]->Render();
		}
	}

	if(m_pNameEditBox)
		m_pNameEditBox->Render();

	{
		for(int i = 0; i<5; ++i)
		{
			{
				m_pSortImg[m_strSortBtn[i].byBtnState]->Move(m_strSortBtn[i].ptPos.x, m_strSortBtn[i].ptPos.y);
				m_pSortImg[m_strSortBtn[i].byBtnState]->Render();
			}
		}
	}

	if(m_pTotalItemCountFont && m_nTotalItemCount > 0)
	{
		char cTotalItemCount[256] = {0,};
		wsprintf(cTotalItemCount, STRMSG_C_131205_0036, m_nTotalItemCount);		// "(아이템수 : %d)"

		SIZE sSize = m_pTotalItemCountFont->GetStringSize(cTotalItemCount);
		m_pTotalItemCountFont->DrawText(m_ptStartPos.x + TOTALITEMCNT_LOCATION_X - sSize.cx, 
										m_ptStartPos.y + TOTALITEMCNT_LOCATION_Y, 
										GUI_FONT_COLOR,	cTotalItemCount, 0L);
	}

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
	
	RenderCategoryPath();			// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
}
void CINFTradeItemBuy::Tick()
{
	for(int i = 0; i<2; ++i)
	{
		if(m_plevelNumEditBox[i])
		{
			m_plevelNumEditBox[i]->Tick();
		}
		if(m_pEnchantNumEditBox[i])
		{
			m_pEnchantNumEditBox[i]->Tick();
		}
	}
	if(m_pNameEditBox)
		m_pNameEditBox->Tick();

	if(m_bRefreshState)
	{
		if(m_fRefreshTime < 0)
		{
			m_bRefreshState = FALSE;
		}
		m_fRefreshTime -= g_pD3dApp->GetElapsedTime();
	}
}

int CINFTradeItemBuy::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	case WM_IME_STARTCOMPOSITION:
		//	case WM_IME_NOTIFY:
	case WM_IME_COMPOSITION:
	case WM_INPUTLANGCHANGE:	
	case WM_IME_ENDCOMPOSITION:
	case WM_IME_SETCONTEXT:	
	case WM_CHAR:
	case WM_KEYDOWN:
	case WM_KEYUP:
		{
			if(m_pNameEditBox->WndProc(uMsg,wParam,lParam,NULL,TRUE))
			{
				return INF_MSGPROC_BREAK;
			}

			if(WM_KEYDOWN == uMsg)
			{
				for(int i = 0; i<2; ++i)
				{
					if(m_plevelNumEditBox[i]->WndProc(uMsg, wParam, lParam))
					{
						// 갱신
						return INF_MSGPROC_BREAK;
					}
					else
					{
						if(wParam == VK_RETURN)
						{
							if(m_plevelNumEditBox[i]->IsEditMode())
							{
								if(m_plevelNumEditBox[i])
								{
									NumEditBoxMaxAndMIN(m_plevelNumEditBox[i], MAXLEVEL);
									m_plevelNumEditBox[i]->EnableEdit(FALSE);
								}
							}
						}
					}

					if(m_pEnchantNumEditBox[i]->WndProc(uMsg, wParam, lParam))
					{
						// 갱신
						return INF_MSGPROC_BREAK;
					}
					else
					{
						if(wParam == VK_RETURN)
						{
							if(m_pEnchantNumEditBox[i]->IsEditMode())
							{
								if(m_pEnchantNumEditBox[i])
								{
									NumEditBoxMaxAndMIN(m_pEnchantNumEditBox[i], MAXENCHANT, FALSE);
									m_pEnchantNumEditBox[i]->EnableEdit(FALSE);
								}
							}
						}
					}
				}
			}
		}
		break;
	}
	return INF_MSGPROC_NORMAL;
}

int	 CINFTradeItemBuy::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(1 == m_pGearComboBox->LButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	
	if(1 == m_pMoneyComboBox->LButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	BOOL bReturn = FALSE;;
	for(int i = 0; i<2; ++i)
	{
		INT nMixCounts = 0;
		char chBuff[256] = {0,};
		if(TRUE == m_plevelNumEditBox[i]->OnLButtonDown(pt) )
		{
			m_pNameEditBox->EnableEdit(FALSE, FALSE);
			m_plevelNumEditBox[i]->EnableEdit(TRUE);	
			m_plevelNumEditBox[i]->GetString(chBuff, 256);
			if(chBuff[0] == ' ')
			{
				if(m_pParent)
					((CINFTradeItemCenter*)m_pParent)->NumEditBoxChangeCount(m_plevelNumEditBox[i], 1);
			}
			//return  INF_MSGPROC_BREAK;				
			bReturn = TRUE;
		}
		else
			m_plevelNumEditBox[i]->EnableEdit(FALSE);

		NumEditBoxMaxAndMIN(m_plevelNumEditBox[i], MAXLEVEL);

		if(TRUE == m_pEnchantNumEditBox[i]->OnLButtonDown(pt) )
		{
			m_pNameEditBox->EnableEdit(FALSE, FALSE);
			m_pEnchantNumEditBox[i]->EnableEdit(TRUE);	
			m_pEnchantNumEditBox[i]->GetString(chBuff, 256);
			if(chBuff[0] == ' ')
			{
				if(m_pParent)
					((CINFTradeItemCenter*)m_pParent)->NumEditBoxChangeCount(m_pEnchantNumEditBox[i], 0);
			}
			//return  INF_MSGPROC_BREAK;				
			bReturn = TRUE;
		}
		else
			m_pEnchantNumEditBox[i]->EnableEdit(FALSE);
		
		NumEditBoxMaxAndMIN(m_pEnchantNumEditBox[i], MAXENCHANT, FALSE);
		
	}
	if(bReturn)
		return INF_MSGPROC_BREAK;

	if(TRUE == m_pNameEditBox->OnLButtonDown(pt))
	{
		if(m_pNameEditBox->IsEditMode())
		{
			m_pNameEditBox->BackupTxtString();
		}
		//		m_pNameEditBox->EnableEdit(FALSE, FALSE);
		m_pNameEditBox->EnableEdit(TRUE, TRUE);
		return INF_MSGPROC_BREAK;
	}
	m_pNameEditBox->EnableEdit(FALSE, FALSE);

	int nQuestIndex = 0;
	int nSelMainIdx, nSelSubIdx;
	nSelMainIdx = nSelSubIdx = -1;
	{		
		// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
		/*
		if(TRUE == m_pListCtrl->OnLButtonDown(pt, &nSelMainIdx, &nSelSubIdx))
		{		
			return INF_MSGPROC_BREAK;
		}
		*/
		if(TRUE == m_pListTreeCtrl->OnLButtonDown(pt))
		{
			return INF_MSGPROC_BREAK;
		}
		// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	}

	
	if(TRUE == m_pSearchBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pInitBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pBuyBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pRefreshBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}		

	int nTemp = -1;
 	if(pt.x > m_ptStartPos.x + ITEMLIST_LOCATION_X && pt.x < m_ptStartPos.x + ITEMLIST_LOCATION_X + ITEMLIST_WIDTH)
 	{
 		if(pt.y > m_ptStartPos.y + ITEMLIST_LOCATION_Y-1 && pt.y < m_ptStartPos.y + ITEMLIST_LOCATION_Y-1 + ITEMLIST_HEIGHT)
		{		
			nTemp = ((pt.y - m_ptStartPos.y - ITEMLIST_LOCATION_Y-1) / (ITEMLIST_CELL_HEIGHT+1)) ;
			if(nTemp < m_vecItemInfo.size())
			{
				m_nSelectListItem = nTemp;
			}
			
			return  INF_MSGPROC_BREAK;	
		}
 	}

	{
		for(int i = 0; i<5; ++i)
		{
			if(pt.x > m_strSortBtn[i].Range.left && pt.x < m_strSortBtn[i].Range.right
				&& pt.y > m_strSortBtn[i].Range.top && pt.y < m_strSortBtn[i].Range.bottom)
			{
				m_strSortBtn[i].byBtnState = BTN_STATUS_DOWN;
				return  INF_MSGPROC_BREAK;
			}
		}
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
int	 CINFTradeItemBuy::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	for(int i = 0; i<5; ++i)
	{
		if( BTN_STATUS_DOWN == m_strSortBtn[i].byBtnState)
		{
			m_strSortBtn[i].byBtnState = BTN_STATUS_SEL;
			SortBtnDown(i);
			return  INF_MSGPROC_BREAK;
		}
	}

	if(TRUE == m_pSearchBtn->OnLButtonUp(pt))
	{
		SearchBtnDown();
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pInitBtn->OnLButtonUp(pt))
	{

		InitBtnClick();
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pBuyBtn->OnLButtonUp(pt))
	{
		BuyButtonDown();
		return  INF_MSGPROC_BREAK;
	}		
	if(TRUE == m_pRefreshBtn->OnLButtonUp(pt))
	{
		SearchBtnDown();
		return  INF_MSGPROC_BREAK;
	}	

	nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{		
		if(TRUE == ((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->OnLButtonUp(pt))
		{
//			if(RefreshSendMsg())
			{
				OnClickPageBtn(nCnt);
			}
// 			else
// 				g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "

			return  INF_MSGPROC_BREAK;
		}		
	}	

	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
//	if(TRUE == m_pListCtrl->OnLButtonUp(pt))
	if(TRUE == m_pListTreeCtrl->OnLButtonUp(pt))
	{
		return  INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemBuy::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	m_pGearComboBox->MouseMove(pt);
	m_pMoneyComboBox->MouseMove(pt);
	m_pSearchBtn->OnMouseMove(pt);
	m_pBuyBtn->OnMouseMove(pt);
	m_pInitBtn->OnMouseMove(pt);
	m_pRefreshBtn->OnMouseMove(pt);
	
	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
//	m_pListCtrl->OnMouseMove(pt);
	m_pListTreeCtrl->OnMouseMove(pt);

	for(int i = 0; i<5; ++i)
	{
		if(pt.x > m_strSortBtn[i].Range.left && pt.x < m_strSortBtn[i].Range.right
			&& pt.y > m_strSortBtn[i].Range.top && pt.y < m_strSortBtn[i].Range.bottom)
		{
			if(m_strSortBtn[i].byBtnState != BTN_STATUS_DOWN)
				m_strSortBtn[i].byBtnState = BTN_STATUS_UP;
		}
		else
			m_strSortBtn[i].byBtnState = BTN_STATUS_SEL;
	}

	int nTemp = -1;
	if(pt.x > m_ptStartPos.x + ITEMLIST_LOCATION_X &&
		pt.x < m_ptStartPos.x + ITEMLIST_LOCATION_X+ITEMLIST_ITEM_WIDTH && 
		pt.y > m_ptStartPos.y + ITEMLIST_LOCATION_Y-1 && 
		pt.y < m_ptStartPos.y + ITEMLIST_LOCATION_Y-1+ITEMLIST_HEIGHT)
	{
		nTemp = ((pt.y - m_ptStartPos.y - ITEMLIST_LOCATION_Y-1)/(ITEMLIST_CELL_HEIGHT+1));
		if(nTemp < m_vecItemInfo.size())
		{
			if(m_nCurerntInfo != m_vecItemInfo[nTemp]->pItem)
			{
				g_pGameMain->SetItemInfoUser(m_vecItemInfo[nTemp]->pItem, pt.x, pt.y);
			}
			m_nCurerntInfo = m_vecItemInfo[nTemp]->pItem;
		}
		else
			m_nCurerntInfo = NULL;
 	}
	else
		m_nCurerntInfo = NULL;

	if(!m_nCurerntInfo)
		g_pGameMain->SetItemInfoUser( NULL, 0, 0);

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_PAGE_BTN; nCnt++)
	{
		if(((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt])
		{			
			((CINFTradeItemCenter*)m_pParent)->m_pPageBtn[nCnt]->OnMouseMove(pt);				
		}		
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemBuy::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
// 	pt.x = LOWORD(lParam);
// 	pt.y = HIWORD(lParam);
// 	CheckMouseReverse(&pt);

	GetCursorPos(&pt);
	ScreenToClient(g_pD3dApp->GetHwnd(), &pt);
	CheckMouseReverse(&pt);

	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	/*
	if(m_pListCtrl->OnMouseWheel(pt,wParam,lParam))
	{
		return INF_MSGPROC_BREAK;
	}
	*/
	if(m_pListTreeCtrl->OnMouseWheel(pt, wParam, lParam))
	{
		return INF_MSGPROC_BREAK;
	}
	// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

	return INF_MSGPROC_NORMAL;
}

void CINFTradeItemBuy::SetbtnPos()
{
	int nPosX, nPosY;
	nPosX = nPosY = 0;
	{		
		// 장치
		int nMainWidth, nMainHeight;
		int nEleWidth, nEleHeight;
		int nElePosX, nElePosY;
		nElePosX = nElePosY =0;
		
		nMainWidth = GEAR_MONEY_COMBO_MAIN_WIDTH;
		nMainHeight = GEAR_MONEY_COMBO_MAIN_HEIGHT;
		nEleWidth = GEAR_MONEY_COMBO_ELE_WIDTH;
		nEleHeight = GEAR_MONEY_COMBO_ELE_HEIGHT;		
		
		nPosX = m_ptStartPos.x + GEAR_COMBO_LOCATION_X;
		nPosY = m_ptStartPos.y + GEAR_MONEY_COMBO_LOCATION_Y;		
		
		nElePosX = nPosX;
		nElePosY = nPosY + nMainHeight;
		
		m_pGearComboBox->SetMainArea(nPosX, nPosY,nMainWidth, nMainHeight);
		m_pGearComboBox->SetElementArea(nElePosX, nElePosY+2, nEleWidth, nEleHeight);
		m_pGearComboBox->SetBGPos(nElePosX+6, nElePosY+4,nEleWidth, nEleHeight);
		
		nPosX = m_ptStartPos.x + MONEY_COMBO_LOCATION_X;

		nElePosX = nPosX;
		m_pMoneyComboBox->SetMainArea(nPosX, nPosY,nMainWidth, nMainHeight);
		m_pMoneyComboBox->SetElementArea(nElePosX, nElePosY+2, nEleWidth, nEleHeight);
		m_pMoneyComboBox->SetBGPos(nElePosX+6, nElePosY+4,nEleWidth, nEleHeight);
	}

	m_pInitBtn->SetBtnPosition(m_ptStartPos.x + INITBTN_LOCATION_X, m_ptStartPos.y + INITBTN_LOCATION_Y);
	m_pSearchBtn->SetBtnPosition(m_ptStartPos.x + SEARCHBTN_LOCATION_X, m_ptStartPos.y + SEARCHBTN_LOCATION_Y);
	m_pBuyBtn->SetBtnPosition(m_ptStartPos.x + BUYBTN_LOCATION_X, m_ptStartPos.y + BUYBTN_LOCATION_Y);
	m_pRefreshBtn->SetBtnPosition(m_ptStartPos.x + REFRESHBTN_LOCATION_X, m_ptStartPos.y + REFRESHBTN_LOCATION_Y);

	if(m_plevelNumEditBox[0])
		m_plevelNumEditBox[0]->SetPos(m_ptStartPos.x + MINLEVEL_NUMEDITBOX_LOCATION_X, m_ptStartPos.y + NUMEDITBOX_LOCATION_Y);

	if(m_plevelNumEditBox[1])
		m_plevelNumEditBox[1]->SetPos(m_ptStartPos.x + MAXLEVEL_NUMEDITBOX_LOCATION_X, m_ptStartPos.y + NUMEDITBOX_LOCATION_Y);

	if(m_pEnchantNumEditBox[0])
		m_pEnchantNumEditBox[0]->SetPos(m_ptStartPos.x + MINENCHANT_NUMEDITBOX_LOCATION_X, m_ptStartPos.y + NUMEDITBOX_LOCATION_Y);
	
	if(m_pEnchantNumEditBox[1])
		m_pEnchantNumEditBox[1]->SetPos(m_ptStartPos.x + MAXENCHANT_NUMEDITBOX_LOCATION_X, m_ptStartPos.y + NUMEDITBOX_LOCATION_Y);

	if(m_pNameEditBox)
	{
		int nPosX, nPosY;
		nPosX = m_ptStartPos.x + NAMEEDITBOX_LOCATION_X;
		nPosY = m_ptStartPos.y + NAMEEDITBOX_LOCATION_Y;		
		m_pNameEditBox->SetPos(nPosX, nPosY);
	}

	{
		int nSizeY = 0;
		if(m_pSortImg[1])
			nSizeY = m_pSortImg[1]->GetImgSize().y;
		for(int i =0; i<5; ++i)
		{
			m_strSortBtn[i].ptPos.y = m_ptStartPos.y + SORTBTN_LOCATION_Y;
			m_strSortBtn[i].Range.top = m_ptStartPos.y + SORTBTN_LOCATION_Y;
			m_strSortBtn[i].Range.bottom = m_strSortBtn[i].Range.top + nSizeY;
			m_strSortBtn[i].byBtnState = BTN_STATUS_SEL;
//			m_strSortBtn[i].bySortState = NON_SORT;
		}

		m_strSortBtn[0].ptPos.x = m_ptStartPos.x + SORTBTN_PRICE_LOCATION_X;
		m_strSortBtn[1].ptPos.x = m_ptStartPos.x + SORTBTN_LEVEL_LOCATION_X;
		m_strSortBtn[2].ptPos.x = m_ptStartPos.x + SORTBTN_ENCHANT_LOCATION_X;
		m_strSortBtn[3].ptPos.x = m_ptStartPos.x + SORTBTN_NAME_LOCATION_X;
		m_strSortBtn[4].ptPos.x = m_ptStartPos.x + SORTBTN_REGISTTIME_LOCATION_X;
	
		m_strSortBtn[0].Range.left = m_ptStartPos.x + SORTBTN_PRICE_LEFT_X;
		m_strSortBtn[1].Range.left = m_ptStartPos.x + SORTBTN_LEVEL_LEFT_X;
		m_strSortBtn[2].Range.left = m_ptStartPos.x + SORTBTN_ENCHANT_LEFT_X;
		m_strSortBtn[3].Range.left = m_ptStartPos.x + SORTBTN_NAME_LEFT_X;
		m_strSortBtn[4].Range.left = m_ptStartPos.x + SORTBTN_REGISTTIME_LEFT_X;

		m_strSortBtn[0].Range.right = 	m_strSortBtn[0].Range.left + SORTBTN_PRICE_WIDTH;
		m_strSortBtn[1].Range.right = 	m_strSortBtn[1].Range.left + SORTBTN_LEVEL_WIDTH;
		m_strSortBtn[2].Range.right = 	m_strSortBtn[2].Range.left + SORTBTN_ENCHANT_WIDTH;
		m_strSortBtn[3].Range.right = 	m_strSortBtn[3].Range.left + SORTBTN_NAME_WIDTH;
		m_strSortBtn[4].Range.right = 	m_strSortBtn[4].Range.left + SORTBTN_REGISTTIME_WIDTH;
	}

	{
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage-m_nStartPage+1);
		nPageCnt = max(1, nPageCnt);	

		int nStartX = m_ptStartPos.x + PAGEBTN_LOCATION_X;
		int nStartY = m_ptStartPos.y + PAGEBTN_LOCATION_Y;
		
		int nTmpPosX = nStartX + ((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][0].x;
		int nTmpPosY = nStartY + ((CINFTradeItemCenter*)m_pParent)->m_ptPagePosList[nPageCnt-1][0].y;
		
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
	
	m_nSelectListItem = -1;
}

void CINFTradeItemBuy::LoadListItem()
{
	// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
	//m_pListCtrl->ResetContent();
	m_pListTreeCtrl->ResetContent();

	if(NULL == m_pItemCategorytree)
	{
		TRADEITEMCATEGORYTREE TempcaTree [] =
		{
			{000, MARKET_ITEM_KIND_ALL,					STRMSG_C_131205_0001},		//전체
				
			{100, MARKET_ITEM_KIND_WEAPON,				STRMSG_C_131205_0002},		//	무기

			{110, MARKET_ITEM_KIND_PRIMARY_WEAPON,		STRMSG_C_131205_0003},		//		기본무기
			{111, MARKET_ITEM_KIND_VULCAN,				STRMSG_C_131205_0004},		//			발칸
			{112, MARKET_ITEM_KIND_CANNON,				STRMSG_C_131205_0005},		//			캐논
			{113, MARKET_ITEM_KIND_GATLING,				STRMSG_C_131205_0006},		//			개틀링
			{114, MARKET_ITEM_KIND_RIFLE,				STRMSG_C_131205_0007},		//			라이플
			{115, MARKET_ITEM_KIND_AUTOMATIC,			STRMSG_C_131205_0008},		//			오토매틱
			{116, MARKET_ITEM_KIND_DUALIST,				STRMSG_C_131205_0009},		//			듀얼리스트
			{117, MARKET_ITEM_KIND_MASSDRIVE,			STRMSG_C_131205_0010},		//			메스드라이브

			{120, MARKET_ITEM_KIND_SECONDARY_WEAPON,	STRMSG_C_131205_0011},		//		고급무기
			{121, MARKET_ITEM_KIND_MISSILE,				STRMSG_C_131205_0012},		//			미사일
			{122, MARKET_ITEM_KIND_BUNDLE,				STRMSG_C_131205_0013},		//			번들
				
			{200, MARKET_ITEM_KIND_ARMOR,				STRMSG_C_131205_0014},		//	아머
			{210, MARKET_ITEM_KIND_VEIL,				STRMSG_C_131205_0015},		//		베일
			{220, MARKET_ITEM_KIND_DEFENDER,			STRMSG_C_131205_0016},		//		디펜더
			{230, MARKET_ITEM_KIND_GUARDER,				STRMSG_C_131205_0017},		//		가더
			{240, MARKET_ITEM_KIND_BINDER,				STRMSG_C_131205_0018},		//		바인더
			
			{300, MARKET_ITEM_KIND_RADAR,				STRMSG_C_131205_0019},		//	레이더
			{310, MARKET_ITEM_KIND_RADAR_B,				STRCMD_CS_UNITKIND_BGEAR},	//		B-GEAR
			{320, MARKET_ITEM_KIND_RADAR_M,				STRCMD_CS_UNITKIND_MGEAR},	//		M-GEAR
			{330, MARKET_ITEM_KIND_RADAR_A,				STRCMD_CS_UNITKIND_AGEAR},	//		A-GEAR
			{340, MARKET_ITEM_KIND_RADAR_I,				STRCMD_CS_UNITKIND_IGEAR},	//		I-GEAR

			{400, MARKET_ITEM_KIND_SUPPORT,				STRMSG_C_131205_0020},		//	보조장비
			{410, MARKET_ITEM_KIND_UNLIMITED_ACCESSORY,	STRMSG_C_131205_0021},		//		무제한 액세서리
			{420, MARKET_ITEM_KIND_TIMELIMIT_ACCESSORY,	STRMSG_C_131205_0022},		//		시간제한 액세서리
			{430, MARKET_ITEM_KIND_COMPUTER,			STRMSG_C_131205_0023},		//		컴퓨터
			{440, MARKET_ITEM_KIND_MARK,				STRCMD_CS_ITEMKIND_MARK},	//		마크
			
			{500, MARKET_ITEM_KIND_ENGIN,				STRMSG_C_131205_0024},		//	엔진
			{510, MARKET_ITEM_KIND_ENGIN_B,				STRCMD_CS_UNITKIND_BGEAR},	//		B-GEAR
			{520, MARKET_ITEM_KIND_ENGIN_M,				STRCMD_CS_UNITKIND_MGEAR},	//		M-GEAR
			{530, MARKET_ITEM_KIND_ENGIN_A,				STRCMD_CS_UNITKIND_AGEAR},	//		A-GEAR
			{540, MARKET_ITEM_KIND_ENGIN_I,				STRCMD_CS_UNITKIND_IGEAR},	//		I-GEAR

			{600, MARKET_ITEM_KIND_CONSUMABLE,			STRMSG_C_131205_0025},		//	소모품
			{610, MARKET_ITEM_KIND_ENERGY,				STRMSG_C_131205_0026},		//		회복 키트
			{620, MARKET_ITEM_KIND_GAMBLE,				STRMSG_C_131205_0027},		//		갬블 키트
			{630, MARKET_ITEM_KIND_ENCHANT,				STRMSG_C_131205_0028},		//		인챈트 카드
			{640, MARKET_ITEM_KIND_CARD,				STRMSG_C_131205_0029},		//		일반 카드
			{650, MARKET_ITEM_KIND_RANDOMBOX,			STRMSG_C_131205_0030},		//		행운의 상자
			
			{700, MARKET_ITEM_KIND_ETC,					STRMSG_C_131205_0031},		//	기타
			{710, MARKET_ITEM_KIND_MATERIAL,			STRMSG_C_131205_0032}		//		광석
		};
		
		m_pItemCategorytree = new TRADEITEMCATEGORYTREE[41];
		for(int i = 0; i<41; ++i)
		{
			memcpy(&m_pItemCategorytree[i], &TempcaTree[i], sizeof(TRADEITEMCATEGORYTREE));
		}
	}

	m_pListTreeCtrl->InsertTextItemWithByKind(0, -1, 0, m_pItemCategorytree[0].byKind, m_pItemCategorytree[0].Name, 0, TRUE);
	for(int i = 1; i<41; ++i)
	{
		int nCategoryId = m_pItemCategorytree[i].nCategoryId;
		if(0 == nCategoryId % 100)
		{
			m_pListTreeCtrl->InsertTextItemWithByKind(0, 0, nCategoryId, m_pItemCategorytree[i].byKind, m_pItemCategorytree[i].Name, 0, FALSE);
		}
		else if(1 == nCategoryId / 100)
		{
			if(0 == nCategoryId % 10)
			{
				m_pListTreeCtrl->InsertTextItemWithByKind(0, (nCategoryId / 100) * 100, nCategoryId, m_pItemCategorytree[i].byKind, m_pItemCategorytree[i].Name, 0, FALSE);
			}
			else
			{
				m_pListTreeCtrl->InsertTextItemWithByKind(0, (nCategoryId / 10) * 10, nCategoryId, m_pItemCategorytree[i].byKind, m_pItemCategorytree[i].Name, GUI_FONT_COLOR, FALSE);
			}
		}
		else
		{
			m_pListTreeCtrl->InsertTextItemWithByKind(0, (nCategoryId / 100) * 100, nCategoryId, m_pItemCategorytree[i].byKind, m_pItemCategorytree[i].Name, GUI_FONT_COLOR, FALSE);
		}
	}
	// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장

	/*
	if(NULL == m_pCategorytree)
	{
		CATEGORYTREE TempcaTree [] = 
 		{
 			{0, 0,		MARKET_ITEM_KIND_ALL,					"전체"},

			{1, 0,		MARKET_ITEM_KIND_WEAPON,				"무기"},
	 			{1, 1,	MARKET_ITEM_KIND_VULCAN,				"발칸"},
				{1, 2,	MARKET_ITEM_KIND_CANNON,				"캐논"},
				{1, 3,	MARKET_ITEM_KIND_GATLING,				"개틀링"},
				{1, 4,	MARKET_ITEM_KIND_RIFLE,					"라이플"},
				{1, 5,	MARKET_ITEM_KIND_AUTOMATIC,				"오토매틱"},
				{1, 6,	MARKET_ITEM_KIND_DUALIST,				"듀얼리스트"}, 
				{1, 7,	MARKET_ITEM_KIND_MASSDRIVE,				"메스드라이브"},
				{1, 8,	MARKET_ITEM_KIND_MISSILE,				"미사일"},
				{1, 9,	MARKET_ITEM_KIND_BUNDLE,				"번들"},
			
			{2, 0,		MARKET_ITEM_KIND_ARMOR,					"아머"},
				{2, 1,	MARKET_ITEM_KIND_VEIL,					"베일"},
				{2, 2,	MARKET_ITEM_KIND_DEFENDER,				"디펜더"},
				{2, 3,	MARKET_ITEM_KIND_GUARDER,				"가더"},
				{2, 4,	MARKET_ITEM_KIND_BINDER,				"바인더"},

			{3, 0,		MARKET_ITEM_KIND_RADAR,					"레이더"},
				{3, 1,	MARKET_ITEM_KIND_RADAR_B,				STRCMD_CS_UNITKIND_BGEAR},
				{3, 2,	MARKET_ITEM_KIND_RADAR_M,				STRCMD_CS_UNITKIND_MGEAR},
				{3, 3,	MARKET_ITEM_KIND_RADAR_A,				STRCMD_CS_UNITKIND_AGEAR},
				{3, 4,	MARKET_ITEM_KIND_RADAR_I,				STRCMD_CS_UNITKIND_IGEAR},
			
			{4, 0,		MARKET_ITEM_KIND_SUPPORT,				"보조장비"},
				{4, 1,	MARKET_ITEM_KIND_UNLIMITED_ACCESSORY,	"무제한 액세서리"},
				{4, 2,	MARKET_ITEM_KIND_TIMELIMIT_ACCESSORY,	"시간제한 액세서리"},
				{4, 3,	MARKET_ITEM_KIND_COMPUTER,				"컴퓨터"},
				{4, 4,	MARKET_ITEM_KIND_MARK,					STRCMD_CS_ITEMKIND_MARK},

			{5, 0,		MARKET_ITEM_KIND_ENGIN,					"엔진"},
				{5, 1,	MARKET_ITEM_KIND_ENGIN_B,				STRCMD_CS_UNITKIND_BGEAR},
				{5, 2,	MARKET_ITEM_KIND_ENGIN_M,				STRCMD_CS_UNITKIND_MGEAR},
				{5, 3,	MARKET_ITEM_KIND_ENGIN_A,				STRCMD_CS_UNITKIND_AGEAR},
				{5, 4,	MARKET_ITEM_KIND_ENGIN_I,				STRCMD_CS_UNITKIND_IGEAR},

			{6, 0,		MARKET_ITEM_KIND_CONSUMABLE,			"소모품"},
				{6, 1,	MARKET_ITEM_KIND_ENERGY,				"회복 키트"},
				{6, 2,	MARKET_ITEM_KIND_GAMBLE,				"갬블 키트"},
				{6, 3,	MARKET_ITEM_KIND_ENCHANT,				"인챈트 카드"},
				{6, 4,	MARKET_ITEM_KIND_CARD,					"일반 카드"},
				{6, 5,	MARKET_ITEM_KIND_RANDOMBOX,				"행운의 상자"},
			
			{7, 0,		MARKET_ITEM_KIND_ETC,					"기타"},
				{7, 1,	MARKET_ITEM_KIND_MATERIAL,				"광석"}
		};

		m_pCategorytree = new CATEGORYTREE[39];
		for(int i = 0; i<39; ++i)
		{
			memcpy(&m_pCategorytree[i], &TempcaTree[i], sizeof(CATEGORYTREE));
		}
		
	}
	
	m_pListCtrl->InsertTextItem(0, m_pCategorytree[0].nMainidx, m_pCategorytree[0].Name, TRUE);
	for(int i = 1; i<39; ++i)
	{
		if(0 == m_pCategorytree[i].nSubIdx)
		{
			m_pListCtrl->InsertTextItem(0, m_pCategorytree[i].nMainidx, m_pCategorytree[i].Name, FALSE);
		}
		else
		{
			m_pListCtrl->InserSubItem(0, m_pCategorytree[i].nMainidx, m_pCategorytree[i].nSubIdx,m_pCategorytree[i].Name, GUI_FONT_COLOR);
		}
	}
	*/
}

int CINFTradeItemBuy::NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount, BOOL bDefaultText)
{
	if(!pNumEditBox)
	{
		return 0;
	}
	INT nMixCounts = 0;
	char chBuff[256] = {0,};
	pNumEditBox->GetString(chBuff, 256);
	
	nMixCounts = atoi(chBuff);
	
	if(nMixCounts > nMaxCount)
	{
		nMixCounts = nMaxCount;
	}
	if(strlen(chBuff) == 1 && chBuff[0] == ' ')
		return 0;

	if(strlen(chBuff) == 1 && chBuff[0] == 48)
	{
		if(bDefaultText)
			pNumEditBox->SetString(" ",32);
	}
	else
	{
		if(m_pParent)
			((CINFTradeItemCenter*)m_pParent)->NumEditBoxChangeCount(pNumEditBox,nMixCounts);
	}

	return nMixCounts;
}

void CINFTradeItemBuy::InitBtnClick()
{


		if(m_pGearComboBox)
		{
			m_pGearComboBox->ItemClear();
			m_pGearComboBox->RestoreDeviceObjects();
			m_pGearComboBox->ShowItem(FALSE);
			m_pGearComboBox->AddElement(STRCMD_CS_UNITKIND_GEAR_ALL);	// #define		WORLDRANK_GEAR_ALL		0		// 전체 기어
			m_pGearComboBox->AddElement(STRCMD_CS_UNITKIND_BGEAR);		// #define		WORLDRANK_GEAR_B		1		// B
			m_pGearComboBox->AddElement(STRCMD_CS_UNITKIND_MGEAR);		// #define		WORLDRANK_GEAR_M		2		// M
			m_pGearComboBox->AddElement(STRCMD_CS_UNITKIND_IGEAR);		// #define		WORLDRANK_GEAR_I		3		// I
			m_pGearComboBox->AddElement(STRCMD_CS_UNITKIND_AGEAR);		// #define		WORLDRANK_GEAR_A		4		// A
			
			if(IS_DT(g_pShuttleChild->GetShuttleInfo()->UnitKind))
			{// 에이기어.
				m_pGearComboBox->SetSelectItem(4);	
			}
			else if(IS_BT(g_pShuttleChild->GetShuttleInfo()->UnitKind))
			{// 비기어
				m_pGearComboBox->SetSelectItem(1);	
			}
			else if(IS_OT(g_pShuttleChild->GetShuttleInfo()->UnitKind))
			{// 엠기어.
				m_pGearComboBox->SetSelectItem(2);	
			}
			else if(IS_ST(g_pShuttleChild->GetShuttleInfo()->UnitKind))
			{// 아이기어.
				m_pGearComboBox->SetSelectItem(3);	
			}
			
		}
		if(m_pMoneyComboBox)
		{
			m_pMoneyComboBox->ItemClear();
			m_pMoneyComboBox->RestoreDeviceObjects();
			m_pMoneyComboBox->ShowItem(FALSE);
			m_pMoneyComboBox->AddElement("SPI");
			m_pMoneyComboBox->AddElement("WP");
			m_pMoneyComboBox->SetSelectItem(0);	
		}
		
		// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
		/*
		if(m_pListCtrl)
		{
			m_pListCtrl->RestoreDeviceObjects();
			m_pListCtrl->SetListCtrlPos(m_ptStartPos.x+26, m_ptStartPos.y+204, 21, 5, 154, -5, 154, 385);
			LoadListItem();
			m_pListCtrl->RestoreItemDeviceObjects();
			m_pListCtrl->UpdateItemPos();
			m_pListCtrl->SetSelPoint(0, 0);	
			
			//시작 위치 x, y, 서브 아이템 위치 x, y 스크롤 위치 x, y, 휠 범위 
		}
		*/
		if(m_pListTreeCtrl)
		{
			m_pListTreeCtrl->RestoreDeviceObjects();
			m_pListTreeCtrl->SetListCtrlPos(m_ptStartPos.x + CATEGORY_LOCATION_X, m_ptStartPos.y + CATEGORY_LOCATION_Y,
											CATEGORY_SUBITEM_LOCATION_X, CATEGORY_SUBITEM_LOCATION_Y, 
											CATEGORY_SCROLL_LOCATION_X, CATEGORY_SCROLL_LOCATION_Y, 
											CATEGORY_WIDTH, CATEGORY_HEIGHT);
			LoadListItem();
			m_pListTreeCtrl->RestoreItemDeviceObjects();
			m_pListTreeCtrl->UpdateItemPos();
			m_pListTreeCtrl->SetSelPoint(NULL);
		}
		// END 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
		
		for(int i = 0; i<2; ++i)
		{
			if(m_plevelNumEditBox[i])
			{
				m_plevelNumEditBox[i]->RestoreDeviceObjects();
				m_plevelNumEditBox[i]->SetString(" ", 32);
				m_plevelNumEditBox[i]->EnableEdit(FALSE);
			}
			if(m_pEnchantNumEditBox[i])
			{
				m_pEnchantNumEditBox[i]->RestoreDeviceObjects();
				m_pEnchantNumEditBox[i]->SetString(" ", 32);
				m_pEnchantNumEditBox[i]->EnableEdit(FALSE);
			}
		}
		
		if(m_pNameEditBox)
		{
			char chBlank[16];
			memset(chBlank, 0x00, 16);
			
			m_pNameEditBox->SetString(chBlank, 16);
			m_pNameEditBox->RestoreDeviceObjects();
			m_pNameEditBox->EnableEdit(FALSE, FALSE);
		}	
		
		m_nSelectListItem = -1;
}

void CINFTradeItemBuy::ItemBuyBaseDone(MSG_FC_MARKET_BASE_INFO_DONE* pMsg, int nTitleNum)
{
	m_nMaxScrollPage = pMsg->MaxPage;
	m_nCurrentPage = pMsg->CurrentPage;
	m_nTotalItemCount = pMsg->ItemCount;

	//m_nStartPage = pMsg->CurrentPage/11;
	m_nStartPage = (pMsg->CurrentPage - 1) / 10;	// 2014-05-21 by ymjoo 거래소 20페이지 이후 넘어가지 않는 버그 수정
	if(m_nStartPage > 0)
		m_nStartPage *= 10;
	m_nStartPage++;
		
	SetbtnPos();

	if(nTitleNum == TIMETITLE)
	{
		m_strSortBtn[nTitleNum].bySortState = DOWN_SORT;
		m_nCurrentSortType = MARKET_SORT_TIME_DOWN;			// 시간 내림차순
	}
	else if(nTitleNum == MONEYTITLE)
	{
		m_strSortBtn[nTitleNum].bySortState = UP_SORT;
		m_nCurrentSortType = MARKET_SORT_PRICE_UP;		// 가격 오름차순
	}
	
	m_bRenderState = TRUE;

	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(FALSE);
}

void CINFTradeItemBuy::ItemVecAdd(MSG_FC_MARKET_BASE_INFO_OK* pMsg)
{	
 	MARKETITEM_INFO* pTemp = new MARKETITEM_INFO;
 	pTemp->pINFO = new MSG_FC_MARKET_BASE_INFO_OK;
	ITEM_GENERAL *pITEMG = new ITEM_GENERAL;

	memset(pITEMG, 0x00, sizeof(ITEM_GENERAL));
	memset(pTemp->pINFO, 0x00, sizeof(MSG_FC_MARKET_BASE_INFO_OK));

	memcpy(pTemp->pINFO, pMsg, sizeof(MSG_FC_MARKET_BASE_INFO_OK));
 
	pITEMG->PrefixCodeNum = pMsg->MarketInfo.PrefixCodeNum;
	pITEMG->SuffixCodeNum = pMsg->MarketInfo.SuffixCodeNum;
	pITEMG->UniqueNumber = pMsg->MarketInfo.ItemUID;
	pITEMG->ShapeItemNum = pMsg->MarketInfo.ShapeItemNum;

	pITEMG->	UniqueNumber = pMsg->MarketInfo.ItemUID;
	pITEMG->	ItemNum =pMsg->MarketInfo.ItemNum;
	pITEMG->	CurrentCount = pMsg->MarketInfo.ItemCount;
	
	pITEMG->	PrefixCodeNum = pMsg->MarketInfo.PrefixCodeNum;
	pITEMG->	SuffixCodeNum = pMsg->MarketInfo.SuffixCodeNum;
	pITEMG->	ShapeItemNum  = pMsg->MarketInfo.ShapeItemNum;
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

void CINFTradeItemBuy::ListRender()
{
	int nCnt = 0;
	char cList[512] = {0,};
	char cTemp[512] = {0,};
	CINFImageEx* pImg = NULL;

	vector<MARKETITEM_INFO*>::iterator it;
	for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end(); it++)
	{
		MARKETITEM_INFO* pMarketItem = (*it);

		if(!pMarketItem)
			return;

		((CINFTradeItemCenter*)m_pParent)->m_pItemSl->Move(m_ptStartPos.x + ITEMLIST_ITEMSL_LOCATION_X, 
														   m_ptStartPos.y + ITEMLIST_ITEMSL_LOCATION_Y + nCnt*(ITEMLIST_CELL_HEIGHT+1));
		((CINFTradeItemCenter*)m_pParent)->m_pItemSl->Render();
		
		wsprintf(cList,"\\e+%d\\e", pMarketItem->pItem->GetEnchantNumber());
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		SIZE sSize = m_pListFont[nCnt][0]->GetStringSize(cList);
		m_pListFont[nCnt][0]->DrawText(m_ptStartPos.x + ITEMLIST_ENCHANT_LOCATION_X  + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
									   m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy/2 + nCnt*(ITEMLIST_CELL_HEIGHT+1),
									   GUI_FONT_COLOR, cList);
#else
 		SIZE sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_ENCHANT_LOCATION_X  + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy/2 + nCnt*(ITEMLIST_CELL_HEIGHT+1), GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		wsprintf(cList,"%s", pMarketItem->pINFO->MarketInfo.ItemName);
		((CINFTradeItemCenter*)m_pParent)->ChangeMaxLenString(cList, ITEMLIST_MAXITEMNAME_LEN);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[nCnt][1]->GetStringSize(cList);
		m_pListFont[nCnt][1]->DrawText(m_ptStartPos.x + ITEMLIST_NAME_LOCATION_X  + ITEMLIST_NAME_WIDTH/2 - sSize.cx/2, 
									   m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy/2 + nCnt*(ITEMLIST_CELL_HEIGHT+1),
									   GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_NAME_LOCATION_X  + ITEMLIST_NAME_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy/2 + nCnt*(ITEMLIST_CELL_HEIGHT+1), GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		wsprintf(cList,"%d", pMarketItem->pINFO->MarketInfo.ItemLevel);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[nCnt][2]->GetStringSize(cList);
		m_pListFont[nCnt][2]->DrawText(m_ptStartPos.x + ITEMLIST_LEVEL_LOCATION_X  + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
									   m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1),
									   GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_LEVEL_LOCATION_X  + ITEMLIST_LEVEL_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1), GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		((CINFTradeItemCenter*)m_pParent)->GetRemainTime(pMarketItem->pINFO->MarketInfo.RegistTime, cList);
		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[nCnt][3]->GetStringSize(cList);
		m_pListFont[nCnt][3]->DrawText(m_ptStartPos.x + ITEMLIST_REGISTTIME_LOCATION_X  + ITEMLIST_REGISTTIME_WIDTH/2 - sSize.cx/2, 
									   m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1),
									   GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_REGISTTIME_LOCATION_X  + ITEMLIST_REGISTTIME_WIDTH/2 - sSize.cx/2, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1), GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

// 2014-05-07 by ssjung 거래소 금액에 따라 색이 변하도록 수정
		char cTempChar[5] = {0,};
		if(pMarketItem->pINFO->MarketInfo.Price < 10000)
			wsprintf(cTempChar, "\\w");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 10000  && pMarketItem->pINFO->MarketInfo.Price < 100000)
			wsprintf(cTempChar, "\\c");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 100000  && pMarketItem->pINFO->MarketInfo.Price < 1000000)
			wsprintf(cTempChar, "\\g");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 1000000  && pMarketItem->pINFO->MarketInfo.Price < 10000000)
			wsprintf(cTempChar, "\\y");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 10000000  && pMarketItem->pINFO->MarketInfo.Price < 100000000)
			wsprintf(cTempChar, "\\m");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 100000000  && pMarketItem->pINFO->MarketInfo.Price < 1000000000)
			wsprintf(cTempChar, "\\e");
		else if(pMarketItem->pINFO->MarketInfo.Price >= 1000000000)
			wsprintf(cTempChar, "\\r");

		wsprintf(cList, "%d",pMarketItem->pINFO->MarketInfo.Price);
		MakeCurrencySeparator(cTemp,cList,3,',');
		wsprintf(cList, "%s%s%s",cTempChar, cTemp, cTempChar);
// 2014-05-07 by ssjung 거래소 금액에 따라 색이 변하도록 수정

		// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		sSize = m_pListFont[nCnt][4]->GetStringSize(cList);
		m_pListFont[nCnt][4]->DrawText(m_ptStartPos.x + ITEMLIST_PRICE_LOCATION_X  + ITEMLIST_PRICE_WIDTH - sSize.cx, 
									   m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1),
									   GUI_FONT_COLOR, cList);
#else
 		sSize = m_pListFont->GetStringSize(cList);
 		m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_PRICE_LOCATION_X  + ITEMLIST_PRICE_WIDTH - sSize.cx, 
 							  m_ptStartPos.y + ITEMLIST_LOCATION_Y + ITEMLIST_CELL_HEIGHT/2  - sSize.cy /2 + nCnt*(ITEMLIST_CELL_HEIGHT+1), GUI_FONT_COLOR, cList);
#endif
		// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

		if(SPI == pMarketItem->pINFO->MarketInfo.MoneyType)
			pImg  = ((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[SPI];
		else if(WP == pMarketItem->pINFO->MarketInfo.MoneyType)
			pImg  = ((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[WP];

		if(pImg)
		{
			pImg->Move(m_ptStartPos.x + ITEMLIST_MONEYTYPE_LOCATION_X,
					   m_ptStartPos.y + ITEMLIST_MONEYTYPE_LOCATION_Y + nCnt*(ITEMLIST_CELL_HEIGHT+1));
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
											 m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + nCnt*(ITEMLIST_CELL_HEIGHT+1), 1.0f);
			m_pIconInfo->Render();

			if( IS_COUNTABLE_ITEM(pMarketItem->pItem->Kind) )
			{
				if( pMarketItem->pINFO->MarketInfo.ItemCount > 1 )
				{
					wsprintf(cList, "%d", pMarketItem->pINFO->MarketInfo.ItemCount);
					// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
					int itemCntStrLen = m_pListFont[nCnt][5]->GetStringSize(cList).cx;
					m_pListFont[nCnt][5]->DrawText(m_ptStartPos.x + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen, 
												   m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + ITEMLIST_ITEMCNT_LOCATION_Y + nCnt*(ITEMLIST_CELL_HEIGHT+1),
												   QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#else
 					int itemCntStrLen = m_pListFont->GetStringSize(cList).cx;
 					m_pListFont->DrawText(m_ptStartPos.x + ITEMLIST_ICON_LOCATION_X + ITEMLIST_ITEMCNT_LOCATION_X - itemCntStrLen, 
 										  m_ptStartPos.y + ITEMLIST_ICON_LOCATION_Y + ITEMLIST_ITEMCNT_LOCATION_Y + nCnt*(ITEMLIST_CELL_HEIGHT+1),
 										  QSLOT_COUNTERBLE_NUMBER, cList, 0L);
#endif
					// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
				}
			}
		}

		nCnt++;
	}
}


void CINFTradeItemBuy::VecItemInfoClear()
{
	m_bRenderState = FALSE;
	m_nCurrentPage = 1;
	m_nMaxScrollPage = 1; 
	m_nStartPage = 1;
	SetbtnPos();

	if(0 < m_vecItemInfo.size())
	{
		vector<MARKETITEM_INFO*>::iterator it;
		for(it = m_vecItemInfo.begin(); it!=m_vecItemInfo.end();)
		{
			MARKETITEM_INFO* pMarketItem = (*it);
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

void CINFTradeItemBuy::BuyButtonDown()
{
	if(m_nSelectListItem < 0 || m_vecItemInfo.size() < m_nSelectListItem+1)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0033, _Q_MARKET_NORMAL_MESSAGE );	 // "선택하신 물품이 없거나 잘 못 선택 하셨습니다. "
	}
	else
	{
		// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
		if(IS_NORMAL_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
		{
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060613_0000, _Q_MARKET_NORMAL_MESSAGE);		// "세력 선택전까지는 거래를 할 수 없습니다."
			return;
		}
		if(m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.MarketItemInfl != g_pShuttleChild->m_myShuttleInfo.InfluenceType)
		{
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_050825_0011, _Q_MARKET_NORMAL_MESSAGE);		// "세력이 맞지않습니다."
			return;
		}
#endif
		// END 2014-06-17 거래소 추가작업
		char buf[256] = {0,};
		char buf02[256] = {0,};
		wsprintf(buf,"%d", m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.Price);
		MakeCurrencySeparator(buf02, buf,3,',');
		if(SPI == m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.MoneyType)
			wsprintf(buf, STRMSG_C_131205_0034, m_vecItemInfo[m_nSelectListItem]->pItem->GetEnchantNumber(), m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.ItemName, buf02);
			// "+%d %s 구매하시겠습니까? \\n%s SPI"
		else if(WP == m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.MoneyType)
			wsprintf(buf, STRMSG_C_131205_0035, m_vecItemInfo[m_nSelectListItem]->pItem->GetEnchantNumber(), m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.ItemName, buf02);
			// "+%d %s 구매하시겠습니까? \\n%s WP"
		
		g_pGameMain->m_pInfWindow->AddMsgBox(buf, _Q_MARKET_BUY_ITEM,0,0,0,0,NULL,TRUE);
	}
}
void CINFTradeItemBuy::BuyItem()
{
	MSG_FC_MARKET_BUY_REQUEST sMsg;
	memset(&sMsg,0x00,sizeof(sMsg));

	sMsg.MarketUID = m_vecItemInfo[m_nSelectListItem]->pINFO->MarketInfo.MarketUID;

//	if(RefreshSendMsg())
	{
		g_pFieldWinSocket->SendMsg( T_FC_MARKET_BUY_REQUEST, (char*)&sMsg, sizeof(sMsg) );
		((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
	}
// 	else
// 		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "
}

void CINFTradeItemBuy::RenderPageCnt()
{	
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
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
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	{
		int nStartX = m_ptStartPos.x + PAGEBTN_LOCATION_X;
		int nStartY = m_ptStartPos.y + PAGEBTN_LOCATION_Y;
		
		int nPageCnt = min(MAX_SEARCH_PAGE, m_nMaxScrollPage - m_nStartPage+1);
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

// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
void CINFTradeItemBuy::RenderCategoryPath()
{
	char chCategoryPath[256];

	PrintCategoryPath(chCategoryPath);

	m_pFontCategoryPath->DrawText(m_ptStartPos.x + CATEGORYPATH_LOCATION_X, m_ptStartPos.y + CATEGORYPATH_LOCATION_Y, CATEGORYPATH_COLOR, chCategoryPath, 0L);

	if(chCategoryPath[0] != NULL)
	{
		m_pCategoryPathArrowImage->Move(m_ptStartPos.x + CATEGORYPATH_ICON_LOCATION_X, m_ptStartPos.y + CATEGORYPATH_ICON_LOCATION_Y);
		m_pCategoryPathArrowImage->Render();
	}
}

// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
void CINFTradeItemBuy::PrintCategoryPath(char* chCategoryPath)
{
	memset(chCategoryPath, 0x00, sizeof(chCategoryPath));

	_PrintCategoryPath(chCategoryPath, m_nSelectedCategoryId);
}

// 2013-12-04 by ymjoo 거래소 카테고리 경로 표시
void CINFTradeItemBuy::_PrintCategoryPath(char* chCategoryPath, int nodeId)
{
	if(-1 != nodeId && 0 != nodeId)	// -1 : 오류일 가능성이 높음. 0 : 전체 혹은 선택하지 않음(전체)
	{
		int parentId = m_pListTreeCtrl->FindParentIdById(nodeId);
		_PrintCategoryPath(chCategoryPath, parentId);

		char* chNodeCategoryPath = m_pListTreeCtrl->GetItemTitleById(nodeId);

		if(chCategoryPath[0] != NULL)
		{
			strcat(chCategoryPath, " > ");
		}
		strcat(chCategoryPath, chNodeCategoryPath);
	}
}

void CINFTradeItemBuy::OnClickPageBtn(int nPageMode)
{
	switch(nPageMode)
	{
	case PAGE_BTN_FIRST:
		{			
			if(m_nCurrentPage == 1)
				return;
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
			if(nCap <= 0 || m_nCurrentPage == m_nMaxScrollPage)
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

void CINFTradeItemBuy::UpdateItemListScroll(int nCurrentPage, int nStartPage, UID64_t MarketUID)
{
	m_nOldCurrentPage	= m_nCurrentPage;
	m_nOldStartPage		= m_nStartPage;

	m_nCurrentPage		= nCurrentPage;	
	m_nStartPage		= nStartPage;	
	
	MSG_FC_MARKET_PAGING_REQUEST sMsg;
	memset(&sMsg,0x00,sizeof(sMsg));

	sMsg.SelectPage = m_nCurrentPage;
	sMsg.MarketUID = MarketUID;

	g_pFieldWinSocket->SendMsg( T_FC_MARKET_PAGING_REQUEST, (char*)&sMsg, sizeof(sMsg) );
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
	
	SetbtnPos();
}

int CINFTradeItemBuy::OnCilckPageCnt(POINT ptPos)
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
				if(m_nCurrentPage == m_nStartPage+nCnt)
					return INF_MSGPROC_BREAK;

//				if(RefreshSendMsg())
				{
					int nCurrentPage = m_nStartPage+nCnt;
					UpdateItemListScroll(nCurrentPage, m_nStartPage);
				}
// 				else
// 					g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "
				
				return INF_MSGPROC_BREAK;	
			}	
		}
	}
	return INF_MSGPROC_NORMAL;	
}
void CINFTradeItemBuy::SearchBtnDown()
{
	// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
	if(IS_NORMAL_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060613_0000, _Q_MARKET_NORMAL_MESSAGE);		// "세력 선택전까지는 거래를 할 수 없습니다."
		return;
	}
#endif
	// END 2014-06-17 거래소 추가작업
	m_nSelectedCategoryId = m_pListTreeCtrl->FindNodeIdBySelectedItem();
		
	MSG_FC_MARKET_SEARCH_REQUEST sMsg;
	memset(&sMsg,0x00,sizeof(sMsg));


// 	POINT pt = m_pListCtrl->GetSelectPoint(); //x가 메인 y가 서브 
// 	sMsg.Kind = SerachKimd(pt);
	sMsg.Kind = m_pListTreeCtrl->FindKindBySelectedItem();

	MinMaxValue(&sMsg.LevelMin, &sMsg.LevelMax, m_plevelNumEditBox[0], m_plevelNumEditBox[1], MAXLEVEL);
	MinMaxValue(&sMsg.EnchantMin, &sMsg.EnchantMax, m_pEnchantNumEditBox[0], m_pEnchantNumEditBox[1], MAXENCHANT);


	INT nTemp = m_pGearComboBox->GetSelect();

	if(0 == nTemp)
		sMsg.ItemGear = UNITKIND_ALL_MASK;
	else if(1 == nTemp)
		sMsg.ItemGear = UNITKIND_BGEAR_MASK;
	else if(2 == nTemp)
		sMsg.ItemGear = UNITKIND_MGEAR_MASK;
	else if(3 == nTemp)
		sMsg.ItemGear = UNITKIND_IGEAR_MASK;
	else if(4 == nTemp)
		sMsg.ItemGear = UNITKIND_AGEAR_MASK;

	sMsg.MoneyType = m_pMoneyComboBox->GetSelect();

	m_pNameEditBox->GetString(sMsg.Name,MARKET_ITEM_FULL_NAME);

//	if(RefreshSendMsg())
	{	
		g_pFieldWinSocket->SendMsg( T_FC_MARKET_SEARCH_REQUEST, (char*)&sMsg, sizeof(sMsg) );
		((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
	}
// 	else
// 		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "

	m_nSelectListItem = -1;

}
void CINFTradeItemBuy::MinMaxValue(BYTE* nMin, BYTE* nMax, CINFNumEditBox* pMinEditBox01, CINFNumEditBox* pMaxEditBox02, int nMaxCount)
{
	BYTE nTemp = 0;

	*nMin = (BYTE)NumEditBoxMaxAndMIN(pMinEditBox01, nMaxCount);
	*nMax = (BYTE)NumEditBoxMaxAndMIN(pMaxEditBox02, nMaxCount);

	if(*nMin && *nMax)
	{
		if(*nMin > *nMax)
		{
			nTemp = *nMin;
			*nMin = *nMax;
			*nMax = nTemp;
		}
	}
	else if(*nMax == 0 && *nMin)
	{
		*nMax = nMaxCount;
	}
}

BYTE CINFTradeItemBuy::SerachKimd(POINT pt)
{
// 2013-12-03 by ymjoo 거래소 카테고리 목록 확장
// 위 사항 적용 이후 쓰이지 않는 함수
// 	for(int i = 0; i<39; ++i)
// 	{
// 		if(pt.x == m_pCategorytree[i].nMainidx && pt.y == m_pCategorytree[i].nSubIdx)
// 		{
// 			return m_pCategorytree[i].byKind;
// 		}
// 	}
// 	return 0;
	return NULL;
}

void CINFTradeItemBuy::SortBtnDown(int nNum)
{
	m_nOldSortType = m_nCurrentSortType;

	if(m_strSortBtn[nNum].bySortState == DOWN_SORT)
	{
		m_strSortBtn[nNum].bySortState = UP_SORT;
		m_nCurrentSortType = nNum * 2 + 1;
	}
	else
	{
		m_strSortBtn[nNum].bySortState = DOWN_SORT;
		m_nCurrentSortType = nNum * 2 + 2;
	}

	MSG_FC_MARKET_SORT_REQUEST sMsg;
	memset(&sMsg,0x00,sizeof(sMsg));
	
	sMsg.SortingType = m_nCurrentSortType;

//	if(RefreshSendMsg())
	{
		g_pFieldWinSocket->SendMsg( T_FC_MARKET_SORT_REQUEST, (char*)&sMsg, sizeof(sMsg) );
		((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
	}
// 	else
// 		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0050, _Q_MARKET_NORMAL_MESSAGE);	// "잠시 후 다시 시도 하세요. "
		
}

BOOL CINFTradeItemBuy::RefreshSendMsg()
{
	if(!m_bRefreshState)
	{
		m_bRefreshState = TRUE;
		m_fRefreshTime = 2.0f;
		return TRUE;
	}
	return FALSE;
}
void CINFTradeItemBuy::ItemButOk(UID64_t MarketUID)
{	
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(FALSE);
	g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131206_0001, _Q_MARKET_NORMAL_MESSAGE,0,0,0,0,NULL,TRUE);	// "성공적으로 물건을 구매 하였습니다.\\n구매한 상품은 인벤토리로 전송됩니다. "
	UpdateItemListScroll(m_nCurrentPage, m_nStartPage, MarketUID);
}

void CINFTradeItemBuy::PaingError()
{
	m_nCurrentPage = m_nOldCurrentPage;
	m_nStartPage = m_nOldStartPage;
}
void CINFTradeItemBuy::SortError()
{
	int nNum = 0;
	m_nCurrentSortType = m_nOldSortType;
	
	if(m_nCurrentSortType%2==0)
		m_strSortBtn[m_nCurrentSortType / 2 - 1].bySortState = DOWN_SORT;
	else
		m_strSortBtn[m_nCurrentSortType / 2].bySortState = UP_SORT;
}
