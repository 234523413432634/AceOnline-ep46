// INFTradeItemCenter.h: interface for the CINFTradeItemCenter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFTRADEITEMCENTER_H__ED3D0911_8764_414F_B286_FAEC3C56FD3B__INCLUDED_)
#define AFX_INFTRADEITEMCENTER_H__ED3D0911_8764_414F_B286_FAEC3C56FD3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "INFBase.h"

class CINFImageEx;
class CINFImageBtn;
class CINFGroupImage;
class CINFNumEditBox;
// 2014-06-17 거래소 추가작업 (주석 처리)
// class CINFMessageBox;
// class CINFImage;
// class CD3DHanFont;
// class CItemInfo;
// class CINFGroupManager;
// class CINFTradeItemAdd;
// class CINFTradeMyItemShow;
// class CINFTradeItemBuy;
// END 2014-06-17 거래소 추가작업 (주석 처리)

enum TAP_NAME
{
	_TRADE_ITEM_BUY = 0,
	_TRADE_ITEM_ADD,
	_TRADE_MY_ITEM_SHOW
};
enum{SPI, WP};

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


class CINFTradeItemCenter : public CINFBase
{
public:
	CINFTradeItemCenter(CAtumNode* pParent, BUILDINGNPC* pBuilding);
	virtual ~CINFTradeItemCenter();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void Init();

	int	 OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	 OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	 OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	 OnMouseWheel(WPARAM wParam, LPARAM lParam);

	void GetItemName(CItemInfo	*	m_pRefItemInfo, char * pName, BOOL bColor = TRUE);

	void NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum);

	void RemoveColor(CItemInfo	* pRefItemInfo, char* pChar);
	
	CINFBase* GetCurrentView(){return m_pTradeItemView[m_dwState];}

	BOOL GetRemainTime(ATUM_DATE_TIME regTime, char* buf);

	void InitPagePosList();

	void OnCloseInfWnd();

	void TradeCenterLock(BOOL bState);

	void BlackBackImgRender();

	void ChangeMaxLenString(char* String, int nLen);

	void SetSellingTime(INT nSellingTime);

// 	BOOL IsEnableItem(ITEM* pITEM);
// 	BOOL IsStringColor(char *i_szStr);

	CINFGroupImage*		m_pBackImg;

	CINFImageBtn*		m_pImgTapBtn[3];					//탭 버튼 
	int					m_nMySPI;
	int					m_nMyWP;
	CD3DHanFont*		m_pMySPIFont;
	CD3DHanFont*		m_pMyWPFont;

	CINFBase*			m_pTradeItemView[3];
	
	DWORD				m_dwState;

	POINT				m_ptStartPos;

	CINFImageEx*		m_pMoneyImg[2];				// 돈의 형태에 맞게 이미지 번경 

	CINFImageEx*		m_pItemSl;

	CINFImageBtn*			m_pPageBtn[MAX_PAGE_BTN];
	POINT					m_ptPagePosList[MAX_SEARCH_PAGE][MAX_SEARCH_PAGE];

	CINFImageEx*		m_pBlackBackImg;

	INT					m_nSellingTime;

	BOOL				m_bNormalInflMsgBuyTab;		// 2014-06-17 거래소 추가작업
	BOOL				m_bNormalInflMsgAddTab;		// 2014-06-17 거래소 추가작업
};

#endif // !defined(AFX_INFTRADEITEMCENTER_H__ED3D0911_8764_414F_B286_FAEC3C56FD3B__INCLUDED_)
