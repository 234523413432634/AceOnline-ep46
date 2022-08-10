// INFTradeMyItemShow.h: interface for the CINFTradeMyItemShow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFTRADEMYITEMSHOW_H__40176546_DC60_4538_8582_C57B55BA2FA8__INCLUDED_)
#define AFX_INFTRADEMYITEMSHOW_H__40176546_DC60_4538_8582_C57B55BA2FA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-17 거래소 추가작업 (주석 처리)
//#include "INFBase.h"

// class CINFMessageBox;
// class CINFImage;
// class CD3DHanFont;
// class CItemInfo;
// class CINFImageEx;
// class CINFImageBtn;
// class CINFGroupImage;
// class CINFGroupManager;
// END 2014-06-17 거래소 추가작업 (주석 처리)

#define ITEMLIST_ITEMNUM					10

struct MARKET_MY_ITEM_INFO
{
	MSG_FC_MARKET_MY_LIST_OK* pINFO;
	CItemInfo*	pItem;
	BYTE byBtnState;
};

class CINFTradeMyItemShow : public CINFBase
{
public:
	CINFTradeMyItemShow(CAtumNode* pParent);
	virtual ~CINFTradeMyItemShow();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	void Render();
	virtual void Tick();

	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	int	OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	OnMouseWheel(WPARAM wParam, LPARAM lParam);
	void MyItemVecAdd(MSG_FC_MARKET_MY_LIST_OK* pMsg);
	void SetMyListCount(int nCount);

	void SetBtnPos();

	void ListRender();

	void VecItemInfoClear();

	void SendGetRequest(UID64_t UID, BYTE byState, INT nPrice, BYTE	MoneyType);

	void RenderPageCnt();
	void OnClickPageBtn(int nPageMode);
	void UpdateItemListScroll(int nCurrentPage, int nStartPage);
	int OnCilckPageCnt(POINT ptPos);
	void MarketGetOk(MSG_FC_MARKET_GET_OK* pMsg);
	void ToolTipRender();
	void RefreshBtnDown();

	CINFGroupImage*		m_pBackImg;
	
	CINFImageBtn*		m_pRefreshBtn;

	int					m_nMyItemCount;

	vector<MARKET_MY_ITEM_INFO*>	m_vecItemInfo;

	POINT				m_ptStartPos;

	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pListFont[ITEMLIST_ITEMNUM][6];
	CD3DHanFont*		m_pFeeFont;
#else
	CD3DHanFont*		m_pListFont;
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)

	CINFIcon*			m_pIconInfo;

	CINFImageEx*		m_pSellOKBtn[3];
	CINFImageEx*		m_pTimeLimitBtn[3];

	CD3DHanFont*		m_pConuntFont;
	// 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pCountFont[MAX_SEARCH_PAGE];
#endif
	// END 2014-06-27 by ymjoo DrawText 성능 개선 작업 (거래소)
	int					m_nCurrentPage;
	int					m_nStartPage;		// 현재 그림의 시작 페이지	
	int					m_nMaxScrollPage;	// 최대 페이지

	POINT				m_ptToolTipPos;
	INT					m_nToolTipState;

	CD3DHanFont*		m_pToolTipFont;

	BOOL				m_bRefreshState;
	float				m_fRefreshTime;

	BOOL				m_bRenderState;
};

#endif // !defined(AFX_INFTRADEMYITEMSHOW_H__40176546_DC60_4538_8582_C57B55BA2FA8__INCLUDED_)
