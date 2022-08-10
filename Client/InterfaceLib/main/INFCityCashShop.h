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

// 2008-10-28 by bhsohn ĳ�� ���� ���� ����
//#define CASH_SHOP_TAB				6		// ĳ���� ��ü �Ǽ�
#define CASH_SHOP_BUTTON_STATE_ALL	3		// ��ư ����
#define CASH_SHOP_ITEM_FONT			15		// �����ۼ� ������ ����(�̸�, ����, ĳ��)
#define CASH_SHOP_ITEM_INFO			13		// �����ۼ� ������ ����(�뵵)
#define INVEN_ROTATION_NUM		5	// �����̼� �̹��� 
#define INVEN_ROTATION_STATE	2	// �����̼� �̹��� 

// 2008-10-28 by bhsohn ĳ�� ���� ���� ����
//#ifdef LANGUAGE_ENGLISH
//#define		CASH_SHOP_VIEW_TAB					4
//#endif
//#ifdef LANGUAGE_VIETNAM
//#define		CASH_SHOP_VIEW_TAB					5
//#endif
//#ifdef LANGUAGE_KOREA
//#define		CASH_SHOP_VIEW_TAB					CASH_SHOP_TAB		// 2008-10-20 by dgwoo ��Ű�� �� �߰�
//#endif
//#ifdef LANGUAGE_CHINA
//#define		CASH_SHOP_VIEW_TAB					4
//#endif
//// 2008-04-30 by bhsohn �±� ���� �߰�
//#ifdef LANGUAGE_THAI
//	#define		CASH_SHOP_VIEW_TAB					4
//#endif
// end 2008-04-30 by bhsohn �±� ���� �߰�


///// ���Ǻ� �̸�
// 2009-01-12 by bhsohn �ű� ĳ���� �۾�
// #define		CASHSHOP_ITEM_PREMIUM_CARD			0
// #define		CASHSHOP_ITEM_OPTION_ITEM			1
// #define		CASHSHOP_ITEM_CARD_ITEM				2
// #define		CASHSHOP_ITEM_ACCESSORY_ITEM		3
// #define		CASHSHOP_ITEM_SKIN_ITEM				4							// 2007-08-07 by dgwoo ��Ų �� �߰�.
// #define		CASHSHOP_ITEM_PACKAGE				5							// 2008-10-20 by dgwoo ��Ű�� �� �߰�
// #define		MAX_CASH_SHOP_TAB				6		// ĳ���� ��ü �Ǽ�
// #define		CASH_SHOP_VIEW_TAB				MAX_CASH_SHOP_TAB	// ���� �ִ��
// #ifdef LANGUAGE_JAPAN
// 	#define		CASHSHOP_ITEM_RECOMMAND				0		// ��õ
// 	#define		CASHSHOP_ITEM_LUCKY_MECHINE			1		// ��Ű �ӽ�
// 	#define		CASHSHOP_ITEM_OPTION_ITEM			2		// ����
// 	#define		CASHSHOP_ITEM_CARD_ITEM				3		// ī��
// 	#define		CASHSHOP_ITEM_ACCESSORY_ITEM		4		// ġ��	
// 	#define		CASHSHOP_ITEM_PACKAGE				5		// ��Ű�� �� �߰�
// 	#define		CASHSHOP_ITEM_PREMIUM_CARD			6
// 	#define		CASHSHOP_ITEM_SKIN_ITEM				7							// 2007-08-07 by dgwoo ��Ų �� �߰�.	
// #else
// 	#define		CASHSHOP_ITEM_PREMIUM_CARD			0
// 	#define		CASHSHOP_ITEM_OPTION_ITEM			1
// 	#define		CASHSHOP_ITEM_CARD_ITEM				2
// 	#define		CASHSHOP_ITEM_ACCESSORY_ITEM		3
// 	#define		CASHSHOP_ITEM_SKIN_ITEM				4							// 2007-08-07 by dgwoo ��Ų �� �߰�.
// 	#define		CASHSHOP_ITEM_PACKAGE				5							// 2008-10-20 by dgwoo ��Ű�� �� �߰�	
// #endif
// 2011. 11. 17 by jskim EP4 UI ����
#ifdef C_EPSODE4_UI_CHANGE_JSKIM
#define		MAX_CASH_SHOP_TAB					7		// ĳ���� ��ü �Ǽ�+1 (������ 1���� �������̴�.) // 2009-01-28 by bhsohn ĳ���� ó��
#else
#define		MAX_CASH_SHOP_TAB					11		// ĳ���� ��ü �Ǽ�+1 (������ 1���� �������̴�.) // 2009-01-28 by bhsohn ĳ���� ó��
#endif
#define		CASH_SHOP_VIEW_TAB					MAX_CASH_SHOP_TAB	// ���� �ִ��
// end 2011. 11. 17 by jskim EP4 UI ����


// 2014-07-02 by ymjoo DrawText ���� ���� �۾� (ĳ�ü�)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
#define		CASHSHOP_TAB_W_SIZE					3
#define		CASHSHOP_TAB_H_SIZE					3
#endif
// END 2014-07-02 by ymjoo DrawText ���� ���� �۾� (ĳ�ü�)

// �ű� ��ǰ 
#define		MAX_NEW_CASHSHOP_IMAGE				2
// end 2009-01-12 by bhsohn �ű� ĳ���� �۾�

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
	// 2007-08-21 by bhsohn ĳ�� ������ alt+tab���� ����
	DataHeader*				pDataHeader;
	CINFImageEx	*			vecImgCashIcon;
} CashItemIcon;

class CINFCityCashShop: public CINFBase
{
	// 2012-11-22 by jhjang �� ������ ���� ���� Ŭ���� ����
protected:
	CINFCityCashShop() {}
	// end 2012-11-22 by jhjang �� ������ ���� ���� Ŭ���� ����
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

	// 2007-08-08 by dgwoo ĳ���ǿ� �̷� �߰�.
	int ProcessRotationUnitWnd(UINT uMsg, WPARAM wParam, LPARAM lParam);
	int ProcessRotationUnit(POINT pt, UINT uMsg);
	void SetByPushButton(BOOL bFlag);
	void OnChangeWearItem();
	void InputCashColorShopItem();
	void SendMsgGift(MSG_FC_SHOP_CHECK_GIVE_TARGET_OK* pMsg);

	// 2009-01-28 by bhsohn ĳ���� ó��
	//SHOP_ITEM* FindCashShopData(int nTabIndex, SHOP_ITEM* pCashShop);
	SHOP_ITEM* FindCashShopData(int nTabIndex, UINT ItemNum);
	// end 2009-01-28 by bhsohn ĳ���� ó��

	// 2013-05-07 by bhsohn ��ĳ�� ���� ����Ű �߰�
	virtual void ShowMasangWebCashShop(char * pAuthenticationKey, INT nServerID){}
	// End 2013-05-07 by bhsohn ��ĳ�� ���� ����Ű �߰�

// 2013-09-25 by ssjung ĳ���� ��õ�� �� �Ϲ����� ���� ���� ���� ����
	void RecommendItemSort();
// end 2013-09-25 by ssjung ĳ���� ��õ�� �� �Ϲ����� ���� ���� ���� ����


private:
	// 2007-08-21 by bhsohn ĳ�� ������ alt+tab���� ����
	CINFImageEx* FindCashIcon(int nItemNum, DataHeader*	pDataHeader);

	// 2009-01-28 by bhsohn ĳ���� ó��
	void UpdateGiftButton(int i_nCurrentSelectTab, int i_nItemSelect);
	void RefreshGetSkinItemIndex();
	int GetSkinItemIndex();
	int GetNonEmptyNextIndex(int i_nStartIdx);	
	void ReLoadSkinItemVector();
	int GetTabToItemIdx(int i_nIdx);
	void RenderNewShopInfo(int nPosX, int nPosY, SHOP_ITEM* i_pShopInfo);
	// end 2009-01-28 by bhsohn ĳ���� ó��
	
	// 2009-02-24 by bhsohn ĳ���� ���� �������� �߰�
	void OnClickCashChargeBtn();
	int WndWebProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	// end 2009-02-24 by bhsohn ĳ���� ���� �������� �߰�

protected:
	// 2011. 11. 17 by jskim EP4 UI ����
#ifdef C_EPSODE4_UI_CHANGE_JSKIM
	CINFGroupImage*			m_pImgBack;
	CINFImageBtn*			m_pCloseBtn;
#else
	CINFImageEx	*			m_pImgBack;
#endif
	
	vector< CINFImageEx* > m_vecCINFImageInfo;


	// end 2011. 11. 17 by jskim EP4 UI ����
	CINFImageEx	*			m_pImgSelectItem;
	CINFImageEx	*			m_pImgTab[CASH_SHOP_VIEW_TAB];
	CINFImageEx	*			m_pImgChargeButton[CASH_SHOP_BUTTON_STATE_ALL];
	CINFImageBtn	*		m_pImgGiftButton;
	CINFImageEx	*			m_pImgBuyButton[CASH_SHOP_BUTTON_STATE_ALL];
	CINFImageEx	*			m_pImgMoreItem[4];

	vector<CashItemIcon>	m_vecImgCashIcon[MAX_CASH_SHOP_TAB];
	// 2014-07-02 by ymjoo DrawText ���� ���� �۾� (ĳ�ü�)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*			m_pFontSTRCULL;
	CD3DHanFont*			m_pFontItem[CASHSHOP_TAB_H_SIZE][CASHSHOP_TAB_W_SIZE][8];
#else
	CD3DHanFont	*			m_pFontItem[CASH_SHOP_ITEM_FONT];
#endif
	// END 2014-07-02 by ymjoo DrawText ���� ���� �۾� (ĳ�ü�)
	CD3DHanFont	*			m_pFontItemInfo[CASH_SHOP_ITEM_INFO];
	BUILDINGNPC	*			m_pBuildingInfo;
	BOOL					m_bInputItemDone;				// InputItemDone�� �� ��� TRUE, �� ���� TRUE�̸� ������ ����Ʈ�� �ٽ� ���� �ʴ´�.
	CINFScrollBar*			m_pScroll;
	POINT					m_pointBeforeMousePoints;			// ���콺 ������ǥ
	ITEM		*			m_pItem;
	
	int						m_nCurrentMouseStateCharge;		// ĳ�� ���� ��ư ���� 
	BOOL					m_bCurrentMouseStateCharge;	// ĳ�� ���� ��ư ���� 
	int						m_nCurrentMouseStateBuy;		// ��� ��ư ����
	BOOL					m_bCurrentMouseStateBuy;		// ��� ��ư ����
	int						m_nMyCashPoint;					// �� ĳ�� ����(��ü : ĳ�� + ��ǰ��)
	int						m_nGiftCardPoint;				// �� ĳ���� ��ǰ��
	int						m_nGiftButtonState;				// ������ư ����.
	
	int						m_nShopOldPosX;
	int						m_nShopOldPosY;
	float					m_fTimeMoreIcon;
	BOOL					m_bMoreItemRenderFlag;

	int						m_nShopTapEndPosX[CASH_SHOP_VIEW_TAB];

	// 2007-08-08 by dgwoo �̷� �߰�.
	CINFImageEx*			m_pDirection[INVEN_ROTATION_STATE][INVEN_ROTATION_NUM];
	CINFImageEx*			m_pRotationBase;

	BOOL					m_bByPush[4];
	int						m_nRotationState;
	int						m_nButtonState;
	
	BOOL					m_bTurnLeft;
	BOOL					m_bTurnRight;
	BOOL					m_bTurnUp;
	BOOL					m_bTurnDown;

	// 2009-01-28 by bhsohn ĳ���� ó��
	int						m_nTabToItemIdx[MAX_CASH_SHOP_TAB];
	int						m_nSkinItemIdx;
	CINFImageEx	*			m_pImgNewTab[MAX_NEW_CASHSHOP_IMAGE];
	int						m_nNewPlayIndex;
	float					m_fNewPlayTime;
	// end 2009-01-28 by bhsohn ĳ���� ó��

	// 2009-02-24 by bhsohn ĳ���� ���� �������� �߰�
	CINFImageBtn	*		m_pImgChargeBtn;	
	CINFImageBtn	*		m_pImgChargeCloseBtn;	
	CINFImageEx*				m_pWebChargeBk;
	// end 2009-02-24 by bhsohn ĳ���� ���� �������� �߰�

	// 2010. 01. 27 by ckPark ĳ�� ������ ���� �Ǹ� �ý���
	CINFImageEx*				m_pSoldOut_Item;
	CINFImageEx*				m_pSoldOut_ToolTip;
	CINFImageEx*				m_pLimitedEdtion[ 2 ];

	BOOL					m_bBling;
	DWORD					m_nBlingStartTime;
	// end 2010. 01. 27 by ckPark ĳ�� ������ ���� �Ǹ� �ý���


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

	// 2010. 01. 27 by ckPark ĳ�� ������ ���� �Ǹ� �ý���
	void		UpdateCashItemRemainCount( ItemNum_t nItemNum, INT nRemainCount );
	// end 2010. 01. 27 by ckPark ĳ�� ������ ���� �Ǹ� �ý���

	// 2014-09-18 by ymjoo ĳ���� �� �� ��ũ�� �ʱ�ȭ
	void		InitScrollbar();
	// END 2014-09-18 by ymjoo ĳ���� �� �� ��ũ�� �ʱ�ȭ


	int			m_nItemSelect;								// ������ ����
	int			m_nShopMovePosX;							// â�̵� ������
	int			m_nShopMovePosY;							// â�̵� ������
	int			m_nCurrentSelectTab;
	
	BOOL		m_bItemBuySend;
	BOOL		m_bMoveShop;
	
	UID32_t		m_nGiveTargetCharacterUID;					// 2007-11-15 by dgwoo ������ �� ĳ������ UID

	vector<SHOP_ITEM*> m_vecItemInfo[MAX_CASH_SHOP_TAB];	
};

//================================================================================================================================
// CINFCityWebCashShop // 2012-11-22 by jhjang �� ������ ���� ���� Ŭ���� ����
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

	// 2013-05-07 by bhsohn ��ĳ�� ���� ����Ű �߰�
	virtual void ShowMasangWebCashShop(char * pAuthenticationKey, INT nServerID);
	// End 2013-05-07 by bhsohn ��ĳ�� ���� ����Ű �߰�

private:
	CINFImageBtn*	m_pCloseXBtn;			// X�ݱ� ��ư

// 2013-11-06 by ssjung ��ĳ�� ���� ���� �� ��� �߰� 
	CINFImageEx*	m_pBlackImg;			// ���� ���
	POINT			m_ptWinSize;			// ������ ������ 
// end 2013-11-06 by ssjung ��ĳ�� ���� ���� �� ��� �߰� 
};
//================================================================================================================================

#endif
