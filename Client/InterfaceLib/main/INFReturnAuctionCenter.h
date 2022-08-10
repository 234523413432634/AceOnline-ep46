// INFReturnAuctionCenter.h: interface for the CINFReturnAuctionCenter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFRETURNAUCTIONCENTER_H__5B92A597_A51F_42D8_A926_2B51C861B4A8__INCLUDED_)
#define AFX_INFRETURNAUCTIONCENTER_H__5B92A597_A51F_42D8_A926_2B51C861B4A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
//#include "INFBase.h"

// class CINFMessageBox;
// class CINFImage;
// class CD3DHanFont;
// class CItemInfo;
// class CINFImageEx;
// class CINFImageBtn;
// class CINFGroupImage;
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

// 최대 10페이까지 보여주자
#define	MAX_SEARCH_PAGE						10

// 최대 페이지 관련 버튼 
#define PAGE_BTN_FIRST						0
#define PAGE_BTN_PREV						1
#define PAGE_BTN_NEXT						2
#define PAGE_BTN_LAST						3
#define MAX_PAGE_BTN						4

#define		PAGE_LIST_WIDTH					30
#define		PAGE_LIST_HEIGHT				30


enum AUCTION_TAP_NAME
{
	_RETURN_AUCTION_LIST = 0,
	_RETURN_MY_AUCTION_LIST
};

enum MONEY_TYPE
{
	_SPI, _WP
};

#define MONEYCOUNT							2

#define STARTPOS_X							((g_pD3dApp->GetBackBufferDesc().Width - 936)/2)
//#define STARTPOS_Y							((g_pD3dApp->GetBackBufferDesc().Height - 642)/2)

#define STARTPOS_Y							((CITY_BASE_NPC_BOX_START_Y)  - (642 - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT)))

struct AUCTION_MY_ITEM_INFO
{
	MSG_FC_DESTROY_AUCTION_BASE_INFO_OK* pINFO;
	CItemInfo*	pItem;
	char		Name[MARKET_ITEM_FULL_NAME];	// 아이템 이름(접두, 접미 포함)
	BYTE byBtnState;
};

class CINFReturnAucionBase : public CINFBase
{
public :
	CINFReturnAucionBase(){};
	virtual ~CINFReturnAucionBase(){};
	
	virtual void ShowWnd(BOOL bShow) = 0;
	virtual void SetBtnPos() = 0;
	virtual void VecItemInfoClear(){};
	
	BOOL					m_bShowWnd;
	CINFGroupImage*			m_pBackImg;
};

class CINFReturnAuctionCenter : public CINFReturnAucionBase
{
public:
	CINFReturnAuctionCenter();
	virtual ~CINFReturnAuctionCenter();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual void ShowWnd(BOOL bShow);
	virtual void SetBtnPos();
	virtual void VecItemInfoClear(MSG_FC_DESTROY_AUCTION_BASE_INFO_HEADER* pMsg = NULL);

	int	 OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	 OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	 OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	 OnMouseWheel(WPARAM wParam, LPARAM lParam);

	void BlackBackImgRender();
	BOOL GetRemainTime(ATUM_DATE_TIME regTime, char* buf);

	void InitPagePosList();

	// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
	//int GetBiddingCount(){return m_nBiddingCount;}

	void ChangeMaxLenString(char* String, int nLen);
	
	void GetItemName(CItemInfo	* pRefItemInfo, char * pName, BOOL bColor = TRUE);
	void RemoveColor(CItemInfo	* pRefItemInfo, char* pChar);

	void OnCloseInfWnd();

	CINFBase* GetCurrentView(){return m_pAuctionView[m_dwState];}

	void ItemVecAdd(MSG_FC_DESTROY_AUCTION_BASE_INFO_OK* pMsg);

	AUCTION_MY_ITEM_INFO* GetAuctionItemInfo(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg);
	AUCTION_MY_ITEM_INFO* GetAuctionItemInfo(UID64_t DAuctionUID);

	void UpdateDataInfo(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg);

	BOOL GetFistMyViewTapClick(){return m_bFistMyViewTapClick;}
	void SetFistMyViewTapClick(BOOL bFlag){m_bFistMyViewTapClick = bFlag;}

	void VecItemStateEnd();

	DWORD GetState()	{ return m_dwState; }							// 2014-06-12 by ymjoo 파괴 경매장 추가작업

	void SetNeedRestartWnd(BOOL bNeed) { m_bNeedRestartWnd = bNeed; }	// 2014-06-12 by ymjoo 파괴 경매장 추가작업

	void RestartWnd();													// 2014-06-12 by ymjoo 파괴 경매장 추가작업

	CINFReturnAucionBase* m_pAuctionView[2];

	vector<AUCTION_MY_ITEM_INFO*>	m_vecOrginItemInfo;

	DWORD				m_dwState;

	CINFImageEx*		m_pBlackBackImg;
	CINFImageEx*		m_pMoneyImg[2];				// 돈의 형태에 맞게 이미지 번경 
	CINFImageBtn*		m_pImgTapBtn[2];			//탭 버튼 

	CINFImageEx*		m_pItemSl;					//아이콘 테두리 

	CINFImageEx*		m_pBiddingImg[4];				//입찰 이미지 
	CINFImageEx*		m_pMoneyGetImg[4];				//돈 회수  이미지 
	CINFImageEx*		m_pMoneyNoGetImg[4];				//돈 회수 못할때 이미지 

	// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
	//int					m_nBiddingCount;					//남은 입찰 횟수 

	CINFImageBtn*		m_pPageBtn[MAX_PAGE_BTN];
	POINT				m_ptPagePosList[MAX_SEARCH_PAGE][MAX_SEARCH_PAGE];

	ATUM_DATE_TIME		m_DAuctionEndTime;		//남은 시간 

	BOOL				m_bFistMyViewTapClick;

	BOOL				m_bNeedRestartWnd;		// 2014-06-12 by ymjoo 파괴 경매장 추가작업
};

#endif // !defined(AFX_INFRETURNAUCTIONCENTER_H__5B92A597_A51F_42D8_A926_2B51C861B4A8__INCLUDED_)
