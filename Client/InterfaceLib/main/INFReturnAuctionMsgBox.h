// INFReturnAuctionMsgBox.h: interface for the CINFReturnAuctionMsgBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFRETURNAUCTIONMSGBOX_H__5512213E_49B3_44B1_A148_493A607F1404__INCLUDED_)
#define AFX_INFRETURNAUCTIONMSGBOX_H__5512213E_49B3_44B1_A148_493A607F1404__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "INFReturnAuctionCenter.h"

enum STATE{ ITEMNONE = -1, BIDDING, GETITEM, FAILGETITEM};

class CINFNumEditBox;
// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
// class CINFReturnAuctionCenter;
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)

class CINFReturnAuctionMsgBox : public CINFReturnAucionBase
{
public:
	CINFReturnAuctionMsgBox();
	virtual ~CINFReturnAuctionMsgBox();

	virtual HRESULT InitDeviceObjects(char* cBkName, void* nData ,int nMode, void* pCenter);
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual void ShowWnd(BOOL bShow);
	virtual void SetBtnPos();
	
	int	 OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	 OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	 OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	 OnMouseWheel(WPARAM wParam, LPARAM lParam);

	void OkBtnDown(int nMode);

	void NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum);
	int NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount, BOOL bTick = FALSE);

	AUCTION_MY_ITEM_INFO* GetItemInfo(){return m_pData;}
	void SetItemInfo(AUCTION_MY_ITEM_INFO* pData = NULL){m_pData = pData;}

	CINFReturnAuctionCenter*		m_pReturnAuctionCenter;

	CINFImageBtn*					m_pOkBtn;
	CINFImageBtn*					m_pCanCelBtn;

	// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
	//CINFImageEx*					m_pBigIcon;
	CINFIcon*						m_pIcon;
	// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경

	CD3DHanFont*					m_pInchantNum;

	CD3DHanFont*					m_pListFont;
	CD3DHanFont*					m_pFinalMoneyFont;

	int								m_nMode;

	AUCTION_MY_ITEM_INFO*			m_pData;

	BOOL							m_bShow;

	CItemInfo*						m_nCurerntInfo;

	CINFNumEditBox*					m_pNumEditBox;

	int								m_nTotalMoney;
};

#endif // !defined(AFX_INFRETURNAUCTIONMSGBOX_H__5512213E_49B3_44B1_A148_493A607F1404__INCLUDED_)
