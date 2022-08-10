// INFTradeItemBuy.h: interface for the CINFTradeItemBuy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFTRADEITEMBUY_H__63F50B71_C7A5_4CA7_A450_1CEE8D671FAB__INCLUDED_)
#define AFX_INFTRADEITEMBUY_H__63F50B71_C7A5_4CA7_A450_1CEE8D671FAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)
//#include "INFBase.h"
// END 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)

class CINFImageListTreeCtrl;		// 2013-12-03 by ymjoo �ŷ��� ī�װ� ��� Ȯ��
// 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)
//class CINFMessageBox;
//class CINFImage;
//class CD3DHanFont;
//class CItemInfo;
//class CINFImageEx;
//class CINFImageBtn;
//class CINFGroupImage;
//class CINFGroupManager;
//class CINFImageListCtrl;
//class CINFListBox;
//class CINFNumEditBox;
// END 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)

#define MAX_TREE_COUNT 41
enum {NON_SORT = -1, UP_SORT, DOWN_SORT};
//enum {NONETITME = -1, ENCHANTTITLE, NAMETITLE, LEVELTITLE, TIMETITLE, MONEYTITLE};
enum {NONETITME = -1, MONEYTITLE, LEVELTITLE, ENCHANTTITLE, NAMETITLE, TIMETITLE};
struct TRADEITEMCATEGORYTREE		// 2013-12-03 by ymjoo �ŷ��� ī�װ� ��� Ȯ��
{
	int nCategoryId;
	BYTE byKind;
	char* Name;
};
struct CATEGORYTREE
{
	int nMainidx;
	int nSubIdx;
	BYTE byKind;
	char* Name;

};
struct SORTBTNSTATE
{
	POINT ptPos;
	RECT  Range;
	BYTE byBtnState;
	BYTE bySortState;
};

struct MARKETITEM_INFO
{
	MSG_FC_MARKET_BASE_INFO_OK* pINFO;
	CItemInfo*	pItem;
};

class CINFTradeItemBuy : public CINFBase
{
public:
	CINFTradeItemBuy(CAtumNode* parent);
	virtual ~CINFTradeItemBuy();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	int	 OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int	 OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int	 OnMouseMove(WPARAM wParam, LPARAM lParam);
	int	 OnMouseWheel(WPARAM wParam, LPARAM lParam);

	void LoadListItem();

	void SetbtnPos();

	int NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount,BOOL bDefaultText = TRUE);

	void InitBtnClick();

	void ItemBuyBaseDone(MSG_FC_MARKET_BASE_INFO_DONE* pMsg, int nTitleNum = NONETITME);
	void ItemVecAdd(MSG_FC_MARKET_BASE_INFO_OK* pMsg);
	void ListRender();

	void VecItemInfoClear();

	void BuyItem();
	void BuyButtonDown();

	void RenderPageCnt();
	void OnClickPageBtn(int nPageMode);
	void UpdateItemListScroll(int nCurrentPage, int nStartPage, UID64_t MarketUID = 0);
	int OnCilckPageCnt(POINT ptPos);
	
	void RenderCategoryPath();									// 2013-12-04 by ymjoo �ŷ��� ī�װ� ��� ǥ��
	void PrintCategoryPath(char* chCategoryPath);				// 2013-12-04 by ymjoo �ŷ��� ī�װ� ��� ǥ��
	void _PrintCategoryPath(char* chCategoryPath, int nodeId);	// 2013-12-04 by ymjoo �ŷ��� ī�װ� ��� ǥ��
																																					 
	void SearchBtnDown();
	void MinMaxValue(BYTE* nMin, BYTE* nMax, CINFNumEditBox* pMinEditBox01, CINFNumEditBox* pMaxEditBox02, int nMaxCount);
	BYTE SerachKimd(POINT pt);

	void SortBtnDown(int nNum);
	BOOL RefreshSendMsg();
	void ItemButOk(UID64_t MarketUID);

	void PaingError();
	void SortError();
	

	CINFGroupImage*		m_pBackImg;

	POINT				m_ptStartPos;

//	CINFImageListCtrl*	m_pListCtrl;
	CINFImageListTreeCtrl*	m_pListTreeCtrl;			// 2013-12-03 by ymjoo �ŷ��� ī�װ� ��� Ȯ��

	CINFListBox*		m_pGearComboBox;
	CINFListBox*		m_pMoneyComboBox;

	float				m_fParentPosY;

	CINFImageBtn*		m_pSearchBtn;
	CINFImageBtn*		m_pBuyBtn;
	CINFImageBtn*		m_pInitBtn;
	CINFImageBtn*		m_pRefreshBtn;

	INT					m_nSelectListItem;
	CINFImageEx*		m_pSelectImg;					//���� �̹��� 

	CINFNumEditBox*		m_plevelNumEditBox[2];
	CINFNumEditBox*		m_pEnchantNumEditBox[2];

	CINFEditBox*		m_pNameEditBox;

//	CATEGORYTREE*		m_pCategorytree;
	TRADEITEMCATEGORYTREE*	m_pItemCategorytree;		// 2013-12-03 by ymjoo �ŷ��� ī�װ� ��� Ȯ��

	CINFImageEx*		m_pSortImg[3];

	SORTBTNSTATE		m_strSortBtn[5];

	int					m_nTotalItemCount;

	CD3DHanFont*		m_pTotalItemCountFont;
	// 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�ŷ���)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pListFont[8][6];
#else
	CD3DHanFont*		m_pListFont;
#endif
	// END 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�ŷ���)
	
	vector<MARKETITEM_INFO*>	m_vecItemInfo;

	CINFIcon*			m_pIconInfo;

	CD3DHanFont*		m_pConuntFont;
	// 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�ŷ���)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pCountFont[MAX_SEARCH_PAGE];
#endif
	// END 2014-06-27 by ymjoo DrawText ���� ���� �۾� (�ŷ���)
	int					m_nCurrentPage;
	int					m_nStartPage;		// ���� �׸��� ���� ������	
	int					m_nMaxScrollPage;	// �ִ� ������

	CINFImageEx*		m_pCategoryPathArrowImage;		// 2013-12-04 by ymjoo �ŷ��� ī�װ� ��� ǥ��
	CD3DHanFont *		m_pFontCategoryPath;			// 2013-12-04 by ymjoo �ŷ��� ī�װ� ��� ǥ��

	int					m_nSelectedCategoryId;			// �˻� ���� �� �����ְ� �ִ� ī�װ� ID		 
	
	BOOL				m_bRefreshState;
	float				m_fRefreshTime;

	CItemInfo*			m_nCurerntInfo;

	BOOL				m_bRenderState;

	int					m_nOldCurrentPage;
	int					m_nOldStartPage;

	BYTE				m_nCurrentSortType;
	BYTE				m_nOldSortType;
};

#endif // !defined(AFX_INFTRADEITEMBUY_H__63F50B71_C7A5_4CA7_A450_1CEE8D671FAB__INCLUDED_)
