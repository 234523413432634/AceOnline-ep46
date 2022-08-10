// INFImageAnimation.h: interface for the INFImageAnimation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFCITYCASHSHOP_H__8B409C14_93C0_4282_B7B5_8367FF326F11__INCLUDED_)
#define AFX_INFCITYCASHSHOP_H__8B409C14_93C0_4282_B7B5_8367FF326F11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "INFBase.h"
#include "INFImageBtn.h"

// 2008-10-28 by bhsohn 캐쉬 상점 구조 변경
//#define CASH_SHOP_TAB				6		// 캐쉬샵 전체 탭수
#define CASH_SHOP_BUTTON_STATE_ALL	3		// 버튼 상태
#define CASH_SHOP_ITEM_FONT			15		// 아이템샵 아이템 설명(이름, 개수, 캐쉬)
#define CASH_SHOP_ITEM_INFO			13		// 아이템샵 아이템 설명(용도)
#define INVEN_ROTATION_NUM		5	// 로테이션 이미지 
#define INVEN_ROTATION_STATE	2	// 로테이션 이미지 

// 2008-10-28 by bhsohn 캐쉬 상점 구조 변경
//#ifdef LANGUAGE_ENGLISH
//#define		CASH_SHOP_VIEW_TAB					4
//#endif
//#ifdef LANGUAGE_VIETNAM
//#define		CASH_SHOP_VIEW_TAB					5
//#endif
//#ifdef LANGUAGE_KOREA
//#define		CASH_SHOP_VIEW_TAB					CASH_SHOP_TAB		// 2008-10-20 by dgwoo 패키지 탭 추가
//#endif
//#ifdef LANGUAGE_CHINA
//#define		CASH_SHOP_VIEW_TAB					4
//#endif
//// 2008-04-30 by bhsohn 태국 버전 추가
//#ifdef LANGUAGE_THAI
//	#define		CASH_SHOP_VIEW_TAB					4
//#endif
// end 2008-04-30 by bhsohn 태국 버전 추가


///// 각탭별 이름
// 2009-01-12 by bhsohn 신규 캐쉬샵 작업
// #define		CASHSHOP_ITEM_PREMIUM_CARD			0
// #define		CASHSHOP_ITEM_OPTION_ITEM			1
// #define		CASHSHOP_ITEM_CARD_ITEM				2
// #define		CASHSHOP_ITEM_ACCESSORY_ITEM		3
// #define		CASHSHOP_ITEM_SKIN_ITEM				4							// 2007-08-07 by dgwoo 스킨 탭 추가.
// #define		CASHSHOP_ITEM_PACKAGE				5							// 2008-10-20 by dgwoo 패키지 탭 추가
// #define		MAX_CASH_SHOP_TAB				6		// 캐쉬샵 전체 탭수
// #define		CASH_SHOP_VIEW_TAB				MAX_CASH_SHOP_TAB	// 탭의 최대수
// #ifdef LANGUAGE_JAPAN
// 	#define		CASHSHOP_ITEM_RECOMMAND				0		// 추천
// 	#define		CASHSHOP_ITEM_LUCKY_MECHINE			1		// 럭키 머신
// 	#define		CASHSHOP_ITEM_OPTION_ITEM			2		// 보조
// 	#define		CASHSHOP_ITEM_CARD_ITEM				3		// 카드
// 	#define		CASHSHOP_ITEM_ACCESSORY_ITEM		4		// 치장	
// 	#define		CASHSHOP_ITEM_PACKAGE				5		// 패키지 탭 추가
// 	#define		CASHSHOP_ITEM_PREMIUM_CARD			6
// 	#define		CASHSHOP_ITEM_SKIN_ITEM				7							// 2007-08-07 by dgwoo 스킨 탭 추가.	
// #else
// 	#define		CASHSHOP_ITEM_PREMIUM_CARD			0
// 	#define		CASHSHOP_ITEM_OPTION_ITEM			1
// 	#define		CASHSHOP_ITEM_CARD_ITEM				2
// 	#define		CASHSHOP_ITEM_ACCESSORY_ITEM		3
// 	#define		CASHSHOP_ITEM_SKIN_ITEM				4							// 2007-08-07 by dgwoo 스킨 탭 추가.
// 	#define		CASHSHOP_ITEM_PACKAGE				5							// 2008-10-20 by dgwoo 패키지 탭 추가	
// #endif
// 2011. 11. 17 by jskim EP4 UI 변경
#ifdef C_EPSODE4_UI_CHANGE_JSKIM
#define		MAX_CASH_SHOP_TAB					7		// 캐쉬샵 전체 탭수+1 (마지막 1개는 더미탭이다.) // 2009-01-28 by bhsohn 캐쉬샵 처리
#else
#define		MAX_CASH_SHOP_TAB					11		// 캐쉬샵 전체 탭수+1 (마지막 1개는 더미탭이다.) // 2009-01-28 by bhsohn 캐쉬샵 처리
#endif
#define		CASH_SHOP_VIEW_TAB					MAX_CASH_SHOP_TAB	// 탭의 최대수
// end 2011. 11. 17 by jskim EP4 UI 변경


// 2014-07-02 by ymjoo DrawText 성능 개선 작업 (캐시샵)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
#define		CASHSHOP_TAB_W_SIZE					3
#define		CASHSHOP_TAB_H_SIZE					3
#endif
// END 2014-07-02 by ymjoo DrawText 성능 개선 작업 (캐시샵)

// 신규 상품 
#define		MAX_NEW_CASHSHOP_IMAGE				2
// end 2009-01-12 by bhsohn 신규 캐쉬샵 작업

class CINFImage;
class CINFImageEx;
class DataHeader;
class CGameData;
class CD3DHanFont;
class CINFScrollBar;
class CINFGroupImage;
class CINFImageBtn;

typedef struct
{
	int						nItemNum;
	// 2007-08-21 by bhsohn 캐쉬 아이템 alt+tab버그 수정
	DataHeader*				pDataHeader;
	CINFImageEx	*			vecImgCashIcon;
} CashItemIcon;

class CINFCityCashShop: public CINFBase
{
	// 2012-11-22 by jhjang 웹 상점을 위한 더미 클래스 제작
protected:
	CINFCityCashShop() {}
	// end 2012-11-22 by jhjang 웹 상점을 위한 더미 클래스 제작
public:
	CINFCityCashShop(CAtumNode* pParent, BUILDINGNPC* pBuilding);
	virtual ~CINFCityCashShop();
	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	// 2007-08-08 by dgwoo 캐쉬탭에 미러 추가.
	int ProcessRotationUnitWnd(UINT uMsg, WPARAM wParam, LPARAM lParam);
	int ProcessRotationUnit(POINT pt, UINT uMsg);
	void SetByPushButton(BOOL bFlag);
	void OnChangeWearItem();
	void InputCashColorShopItem();
	void SendMsgGift(MSG_FC_SHOP_CHECK_GIVE_TARGET_OK* pMsg);

	// 2009-01-28 by bhsohn 캐쉬샵 처리
	//SHOP_ITEM* FindCashShopData(int nTabIndex, SHOP_ITEM* pCashShop);
	SHOP_ITEM* FindCashShopData(int nTabIndex, UINT ItemNum);
	// end 2009-01-28 by bhsohn 캐쉬샵 처리

	// 2013-05-07 by bhsohn 웹캐쉬 상점 인증키 추가
	virtual void ShowMasangWebCashShop(char * pAuthenticationKey, INT nServerID){}
	// End 2013-05-07 by bhsohn 웹캐쉬 상점 인증키 추가

// 2013-09-25 by ssjung 캐쉬샾 추천탭 과 일반탭의 순서 관련 사항 수정
	void RecommendItemSort();
// end 2013-09-25 by ssjung 캐쉬샾 추천탭 과 일반탭의 순서 관련 사항 수정


private:
	// 2007-08-21 by bhsohn 캐쉬 아이템 alt+tab버그 수정
	CINFImageEx* FindCashIcon(int nItemNum, DataHeader*	pDataHeader);

	// 2009-01-28 by bhsohn 캐쉬샵 처리
	void UpdateGiftButton(int i_nCurrentSelectTab, int i_nItemSelect);
	void RefreshGetSkinItemIndex();
	int GetSkinItemIndex();
	int GetNonEmptyNextIndex(int i_nStartIdx);	
	void ReLoadSkinItemVector();
	int GetTabToItemIdx(int i_nIdx);
	void RenderNewShopInfo(int nPosX, int nPosY, SHOP_ITEM* i_pShopInfo);
	// end 2009-01-28 by bhsohn 캐쉬샵 처리
	
	// 2009-02-24 by bhsohn 캐쉬샵 충전 웹페이지 추가
	void OnClickCashChargeBtn();
	int WndWebProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	// end 2009-02-24 by bhsohn 캐쉬샵 충전 웹페이지 추가

protected:
	// 2011. 11. 17 by jskim EP4 UI 변경
#ifdef C_EPSODE4_UI_CHANGE_JSKIM
	CINFGroupImage*			m_pImgBack;
	CINFImageBtn*			m_pCloseBtn;
#else
	CINFImageEx	*			m_pImgBack;
#endif
	
	vector< CINFImageEx* > m_vecCINFImageInfo;


	// end 2011. 11. 17 by jskim EP4 UI 변경
	CINFImageEx	*			m_pImgSelectItem;
	CINFImageEx	*			m_pImgTab[CASH_SHOP_VIEW_TAB];
	CINFImageEx	*			m_pImgChargeButton[CASH_SHOP_BUTTON_STATE_ALL];
	CINFImageBtn	*		m_pImgGiftButton;
	CINFImageEx	*			m_pImgBuyButton[CASH_SHOP_BUTTON_STATE_ALL];
	CINFImageEx	*			m_pImgMoreItem[4];

	vector<CashItemIcon>	m_vecImgCashIcon[MAX_CASH_SHOP_TAB];
	// 2014-07-02 by ymjoo DrawText 성능 개선 작업 (캐시샵)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*			m_pFontSTRCULL;
	CD3DHanFont*			m_pFontItem[CASHSHOP_TAB_H_SIZE][CASHSHOP_TAB_W_SIZE][8];
#else
	CD3DHanFont	*			m_pFontItem[CASH_SHOP_ITEM_FONT];
#endif
	// END 2014-07-02 by ymjoo DrawText 성능 개선 작업 (캐시샵)
	CD3DHanFont	*			m_pFontItemInfo[CASH_SHOP_ITEM_INFO];
	BUILDINGNPC	*			m_pBuildingInfo;
	BOOL					m_bInputItemDone;				// InputItemDone이 온 경우 TRUE, 이 값이 TRUE이면 아이템 리스트를 다시 받지 않는다.
	CINFScrollBar*			m_pScroll;
	POINT					m_pointBeforeMousePoints;			// 마우스 이전좌표
	ITEM		*			m_pItem;
	
	int						m_nCurrentMouseStateCharge;		// 캐쉬 충전 버튼 상태 
	BOOL					m_bCurrentMouseStateCharge;	// 캐쉬 충전 버튼 상태 
	int						m_nCurrentMouseStateBuy;		// 사기 버튼 상태
	BOOL					m_bCurrentMouseStateBuy;		// 사기 버튼 상태
	int						m_nMyCashPoint;					// 내 캐쉬 정보(전체 : 캐쉬 + 상품권)
	int						m_nGiftCardPoint;				// 내 캐쉬중 상품권
	int						m_nGiftButtonState;				// 선물버튼 상태.
	
	int						m_nShopOldPosX;
	int						m_nShopOldPosY;
	float					m_fTimeMoreIcon;
	BOOL					m_bMoreItemRenderFlag;

	int						m_nShopTapEndPosX[CASH_SHOP_VIEW_TAB];

	// 2007-08-08 by dgwoo 미러 추가.
	CINFImageEx*			m_pDirection[INVEN_ROTATION_STATE][INVEN_ROTATION_NUM];
	CINFImageEx*			m_pRotationBase;

	BOOL					m_bByPush[4];
	int						m_nRotationState;
	int						m_nButtonState;
	
	BOOL					m_bTurnLeft;
	BOOL					m_bTurnRight;
	BOOL					m_bTurnUp;
	BOOL					m_bTurnDown;

	// 2009-01-28 by bhsohn 캐쉬샵 처리
	int						m_nTabToItemIdx[MAX_CASH_SHOP_TAB];
	int						m_nSkinItemIdx;
	CINFImageEx	*			m_pImgNewTab[MAX_NEW_CASHSHOP_IMAGE];
	int						m_nNewPlayIndex;
	float					m_fNewPlayTime;
	// end 2009-01-28 by bhsohn 캐쉬샵 처리

	// 2009-02-24 by bhsohn 캐쉬샵 충전 웹페이지 추가
	CINFImageBtn	*		m_pImgChargeBtn;	
	CINFImageBtn	*		m_pImgChargeCloseBtn;	
	CINFImageEx*				m_pWebChargeBk;
	// end 2009-02-24 by bhsohn 캐쉬샵 충전 웹페이지 추가

	// 2010. 01. 27 by ckPark 캐쉬 아이템 한정 판매 시스템
	CINFImageEx*				m_pSoldOut_Item;
	CINFImageEx*				m_pSoldOut_ToolTip;
	CINFImageEx*				m_pLimitedEdtion[ 2 ];

	BOOL					m_bBling;
	DWORD					m_nBlingStartTime;
	// end 2010. 01. 27 by ckPark 캐쉬 아이템 한정 판매 시스템


public:
	BOOL		IsInputItemDone() { return m_bInputItemDone; }
	void		InitData();
	void		InputItemDone();
	void		SendBuyItem(ITEM *pItem);
	void		SendChargeCash();
	int			InputItem(char* pMsg);
	void		SetCashMoney(int nMoney){m_nMyCashPoint = nMoney; }
	void		SetGiftCardCashPoint(int nGiftCardPoint) { m_nGiftCardPoint = nGiftCardPoint; }
	void		RenderDescIcon();

	void		ClearItemList();

#ifdef C_EPSODE4_UI_CHANGE_JSKIM
	void		RenderDescIcon( POINT pPos, ITEM* pItem, int nWidht, int nHeight );
#endif
	void		CashItemSort();

	// 2010. 01. 27 by ckPark 캐쉬 아이템 한정 판매 시스템
	void		UpdateCashItemRemainCount( ItemNum_t nItemNum, INT nRemainCount );
	// end 2010. 01. 27 by ckPark 캐쉬 아이템 한정 판매 시스템

	// 2014-09-18 by ymjoo 캐쉬샵 열 때 스크롤 초기화
	void		InitScrollbar();
	// END 2014-09-18 by ymjoo 캐쉬샵 열 때 스크롤 초기화


	int			m_nItemSelect;								// 아이템 선택
	int			m_nShopMovePosX;							// 창이동 포지션
	int			m_nShopMovePosY;							// 창이동 포지션
	int			m_nCurrentSelectTab;
	
	BOOL		m_bItemBuySend;
	BOOL		m_bMoveShop;
	
	UID32_t		m_nGiveTargetCharacterUID;					// 2007-11-15 by dgwoo 선물을 줄 캐릭터의 UID

	vector<SHOP_ITEM*> m_vecItemInfo[MAX_CASH_SHOP_TAB];	
};

//================================================================================================================================
// CINFCityWebCashShop // 2012-11-22 by jhjang 웹 상점을 위한 더미 클래스 제작
//================================================================================================================================
class CINFCityWebCashShop : public CINFCityCashShop
{
public:
	CINFCityWebCashShop(CAtumNode* pParent, BUILDINGNPC* pBuilding);
	virtual ~CINFCityWebCashShop();

	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();

	// 2013-05-07 by bhsohn 웹캐쉬 상점 인증키 추가
	virtual void ShowMasangWebCashShop(char * pAuthenticationKey, INT nServerID);
	// End 2013-05-07 by bhsohn 웹캐쉬 상점 인증키 추가

private:
	CINFImageBtn*	m_pCloseXBtn;			// X닫기 버튼

// 2013-11-06 by ssjung 웹캐쉬 상점 검정 뒷 배경 추가 
	CINFImageEx*	m_pBlackImg;			// 검정 배경
	POINT			m_ptWinSize;			// 윈도우 사이즈 
// end 2013-11-06 by ssjung 웹캐쉬 상점 검정 뒷 배경 추가 
};
//================================================================================================================================

#endif
