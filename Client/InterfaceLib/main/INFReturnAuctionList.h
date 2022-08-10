// INFReturnAuctionList.h: interface for the CINFReturnAuctionList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFRETURNAUCTIONLIST_H__B17E9911_3B1F_4E24_9292_32E2E5594F12__INCLUDED_)
#define AFX_INFRETURNAUCTIONLIST_H__B17E9911_3B1F_4E24_9292_32E2E5594F12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// E2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)
//#include "INFReturnAuctionCenter.h"
// END 2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)

struct TREECATEGORY
{
	int nMainidx;
	int nSubIdx;
	BYTE byKind;
	char* Name;
};

class CINFImageListTreeCtrl;		// 2014-01-15 by ymjoo �ı������ ī�װ� ��� ����
class CINFReturnAuctionMsgBox;
// 2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)
// class CINFReturnAuctionCenter;
// class CINFImageListCtrl;
// END 2014-06-12 by ymjoo �ı� ����� �߰��۾� (�ּ�ó��)

class CINFReturnAuctionList : public CINFReturnAucionBase
{
public:
	CINFReturnAuctionList(CAtumNode* parent);
	virtual ~CINFReturnAuctionList();

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

	void ListRender();

	void LoadListItem();

	BYTE SerachKind(POINT pt);

	void SortList(BYTE byKind = 0);

	void ToolTipRender();

	void ItemListMouseMove(POINT pt);
	BOOL ItemListMouseDown(POINT pt);
	BOOL ItemListMouseUP(POINT pt);

	void BiddingBtnDown();

	void RenderPageCnt();
	void OnClickPageBtn(int nPageMode);
	void UpdateItemListScroll(int nCurrentPage, int nStartPage);
	int OnCilckPageCnt(POINT ptPos);

	void InitData();

	void ItemVecDone();

	CINFReturnAuctionCenter*		m_pReturnAuctionCenter;

	CD3DHanFont*					m_pTotalItemCountFont;
	CD3DHanFont*					m_pListFont;


	CINFImageBtn*					m_pRefreshBtn;

	int								m_nTotalItemCount;

	vector<AUCTION_MY_ITEM_INFO*>	m_vecItemInfo;
	
	//CINFArenaScrollBar*				m_pScroll;

	CINFIcon*						m_pIconInfo;

	CINFImageListTreeCtrl*			m_pListTreeCtrl;	// 2014-01-15 by ymjoo �ı������ ī�װ� ��� ����
	//CINFImageListCtrl*				m_pListCtrl;

	TREECATEGORY*					m_pCategorytree;


	BYTE							m_byOrgKind;

	POINT							m_ptToolTipPos;
	INT								m_nToolTipState;

	CD3DHanFont*					m_pToolTipFont;

	CItemInfo*						m_nCurerntInfo;

	CD3DHanFont*					m_pConuntFont;
	int								m_nCurrentPage;
	int								m_nStartPage;		// ���� �׸��� ���� ������	
	int								m_nMaxScrollPage;	// �ִ� ������

	INT								m_nSelectListItem;
	CINFImageEx*					m_pSelectImg;					//���� �̹��� 

	CINFImageBtn*					m_pBiddingBtn;

	CD3DHanFont*					m_pBiddingCountFont;

	CINFReturnAuctionMsgBox*		m_pMsgBox;

	BOOL							m_bRenderState;

	ATUM_DATE_TIME					m_pLastRefreshTime;		// 2014-06-12 by ymjoo �ı� ����� �߰��۾�
};

#endif // !defined(AFX_INFRETURNAUCTIONLIST_H__B17E9911_3B1F_4E24_9292_32E2E5594F12__INCLUDED_)
