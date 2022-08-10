// INFReturnMyAuctionList.h: interface for the CINFReturnMyAuctionList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFRETURNMYAUCTIONLIST_H__E6E929C9_8CE1_43B0_B84B_DBB67FB5DD75__INCLUDED_)
#define AFX_INFRETURNMYAUCTIONLIST_H__E6E929C9_8CE1_43B0_B84B_DBB67FB5DD75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)
//#include "INFReturnAuctionCenter.h"

//class CINFReturnAuctionMsgBox;
// END 2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)

#define ITEMLIST_ITEMNUM					10

class CINFReturnMyAuctionList : public CINFReturnAucionBase
{
public:
	CINFReturnMyAuctionList(CAtumNode* parent);
	virtual ~CINFReturnMyAuctionList();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual void ShowWnd(BOOL bShow);
	virtual void SetBtnPos();
	virtual void VecItemInfoClear();

	int	 OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	 OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	 OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	 OnMouseWheel(WPARAM wParam, LPARAM lParam);

	void RefreshBtnDown();

	void ListRender(vector<AUCTION_MY_ITEM_INFO*>* vecItemInfo);
	
	void ToolTipRender();

	void ItemListMouseMove(POINT pt);
	BOOL ItemListMouseDown(POINT pt);
	BOOL ItemListMouseUP(POINT pt);

	void RenderPageCnt();
	void OnClickPageBtn(int nPageMode);
	void UpdateItemListScroll(int nCurrentPage, int nStartPage);
	int OnCilckPageCnt(POINT ptPos);

	void StateBtnDown(AUCTION_MY_ITEM_INFO* pMarketItem);

	void PushMyList(MSG_FC_DESTROY_AUCTION_TENDER_OK* pMsg);

	void ItemVecAdd(MSG_FC_DESTROY_AUCTION_MY_LIST_OK* pMsg);

	void MyItemListDone();

	BOOL CompareData(AUCTION_MY_ITEM_INFO* pData);

	void MyAuctionGetOk(MSG_FC_DESTROY_AUCTION_GET_OK* pMsg);

	void ListITemCheck();

	CINFGroupImage*		m_pBackImg;
	
	CINFImageBtn*		m_pRefreshBtn;

	vector<AUCTION_MY_ITEM_INFO*>	m_vecItemInfo;
//	vector<AUCTION_MY_ITEM_INFO*>	m_vecTempIteminfo;		// 2014-07-17 by ymjoo �ı������ �ڵ尳�� (�ּ�ó��)

	CD3DHanFont*		m_pToolTipFont;
	CD3DHanFont*		m_pConuntFont;
	// 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�����)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pCountFont[MAX_SEARCH_PAGE];
	CD3DHanFont*		m_pListFont[ITEMLIST_ITEMNUM][7];
#else
	CD3DHanFont*		m_pListFont;
#endif
	// END 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�����)
	CD3DHanFont*		m_pBiddingCountFont;

	CINFIcon*			m_pIconInfo;

	CItemInfo*			m_nCurerntInfo;

	POINT				m_ptToolTipPos;
	INT					m_nToolTipState;

	int					m_nCurrentPage;
	int					m_nStartPage;		// ���� �׸��� ���� ������	
	int					m_nMaxScrollPage;	// �ִ� ������

	CINFReturnAuctionMsgBox*		m_pMsgBox;
	
	float				m_fItemCheckTime;

	ATUM_DATE_TIME		m_pLastRefreshTime;		// 2014-06-12 by ymjoo �ı� ����� �߰��۾�
};

#endif // !defined(AFX_INFRETURNMYAUCTIONLIST_H__E6E929C9_8CE1_43B0_B84B_DBB67FB5DD75__INCLUDED_)
