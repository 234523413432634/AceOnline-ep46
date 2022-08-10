// INFItemMixWnd.h: interface for the CINFArmorCollectWnd class.
//
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		
/// \author		// 2013-05-28 by bhsohn 아머 컬렉션 시스템
/// \date		2013-05-28 ~ 
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMOR_COLLECT_WND_H__872742CD_5E6C_46B0_869F_C6F429B0A473__INCLUDED_)
#define AFX_ARMOR_COLLECT_WND_H__872742CD_5E6C_46B0_869F_C6F429B0A473__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CINFBase;
class CINFGroupImage;
class CINFEditBox;
class CINFAutoEditBox;
class CINFComboBoxEX;
class CINFListBox;
class CINFArenaScrollBar;

#define MIX_SEARCH_KIND_COUNT				3

// 최대 라인수
#define	MAX_ARMOR_X							4
#define	MAX_ARMOR_Y							3

// Icone크기값
#define		BIGICON_WIDTH							84
#define		BIGICON_HEIGHT							58

// 2014-09-04 by ymjoo 컴파일 경고 제거 작업
// #define		ICON_CAPX							85
// #define		ICON_CAPY							52
#define		ARMOR_COLLECT_ICON_CAPX			85
#define		ARMOR_COLLECT_ICON_CAPY			52
// END 2014-09-04 by ymjoo 컴파일 경고 제거 작업

#define MAX_SCROLL_CNT						30						// 최대 페이지

// 최대 인첸 수
#define		MAX_ARMOR_COLLECT_ENCHANT		10

class CINFArmorCollectWnd  : public CINFBase
{		
public:	
	CINFArmorCollectWnd(CAtumNode* pParent);
	virtual ~CINFArmorCollectWnd();
	
	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void	InitWndData();

	virtual void	Tick();
	void			Render();	

	DataHeader* FindResource(char* szRcName);

	void			RenderCommonCtrl();			

	void			RenderInitArmor();
	void			RenderCurrentArmor();
	void			RenderApplyArmor();
	
	void			RenderArmorList();		// 아머 정보 랜더링
	// 2014-07-02 by ymjoo DrawText 성능 개선 작업 (아머컬렉션)
// 	void			RenderHaveArmor(int nStartX, int nStartY, CINFImageEx* pArmorIcon, struArmorCollectionInfo* pArmorInfo);		// 아머 정보 랜더링
// 	void			RenderNotHaveArmor(int nStartX, int nStartY, CINFImageEx* pArmorIcon, struArmorCollectionInfo* pArmorInfo);		// 아머 정보 랜더링
	void			RenderHaveArmor(int nStartX, int nStartY, CINFImageEx* pArmorIcon, struArmorCollectionInfo* pArmorInfo, int nPosX, int nPosY);			// 아머 정보 랜더링
	void			RenderNotHaveArmor(int nStartX, int nStartY, CINFImageEx* pArmorIcon, struArmorCollectionInfo* pArmorInfo, int nPosX, int nPosY);		// 아머 정보 랜더링
	// END 2014-07-02 by ymjoo DrawText 성능 개선 작업 (아머컬렉션)

	void			ConvertSecond_To_DayHourMin(INT nSecond, int *pDay, int *pHour, int *pMin);

	BOOL IsShowWnd();
	virtual void ShowWnd(BOOL bShow, INT nShowItemNum, UID64_t uItemUniNum, POINT *tMixWndPos=NULL);
	
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);	
	virtual int OnMouseWheel(WPARAM wParam, LPARAM lParam);
	virtual int OnLButtonDown(WPARAM wParam, LPARAM lParam);
	virtual int OnMouseMove(WPARAM wParam, LPARAM lParam);
	virtual int OnLButtonUp(WPARAM wParam, LPARAM lParam);
	virtual void UpdateBtnPos();
	virtual int OnCilckSelectItem(POINT pt);		// 검색항목 클릭	
	virtual int OnCilckGearTab(POINT ptPos);

	BOOL IsMouseCaps(POINT ptPos);
	
	// 검색 타입
	void SetSearchItemNum(INT nSearchItemNum) {m_nSearchItemNum = nSearchItemNum;}
	INT GetSearchItemNum() {return m_nSearchItemNum;}

	// 아이템 툴팁 표시
	void SetTooltipItemInfo(INT	nItemNum, int x, int y, int nLinkItem);

	void FindTooltipItemInfo_POS(POINT pt, int *nFindPosX, int *nFindPosY);
	struArmorCollectionInfo* GetTooltipItemInfo_ItemNum(int nScroll, int nFindPosX, int nFindPosY, int* pLinkItem);

	INT GetTooltip_Target_ItemInfo_ItemNum(int nPage, int nScroll, int nFindPosX, int nFindPosY);

	void InitItemListScroll();
	void UpdateItemListScroll(int nCurrentPage, int nStartPage);

	
	POINT GetBkSize();	
	void SetShowItemNumShowWnd(BOOL bShow, int nShowItemNum, UID64_t uItemUniNum);
	
	void ResotreAllArmorIcon();		// 아머 아이콘 전체 갱신
	void InvalidateAllArmorIcon();		// 아머 아이콘 전체 갱신
	void DeleteAllArmorIcon();
	CINFImageEx* GetArmorIcon(INT nUnitCollectType, INT nItemNum);

	INT GetSelUnitCollectType(){return m_nSelUnitCollectType;}	// 2013-06-12 by ssjung 아머 컬렉션 툴팁 표시

protected:
	void OnClickApplyArrmor();
	void OnClickInitArmor();

	void RenderGearTab();

	
	INT GetSelectArmorShapeNum(POINT ptSelectPos);
	INT GetSelectArmorItemNum(POINT ptSelectPos);


protected:
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					       
	CINFGroupImage*		m_pImgBackg;
#endif	
	CINFArenaScrollBar*		m_pScroll;
	
	// 2014-07-02 by ymjoo DrawText 성능 개선 작업 (아머컬렉션)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*		m_pInitArmorFont;
	CD3DHanFont*		m_pCurrentArmorFont;
	CD3DHanFont*		m_pCurrentArmorStateFont;
	CD3DHanFont*		m_pApplyArmorFont;
	CD3DHanFont*		m_pApplyArmorStateFont;
	CD3DHanFont*		m_pArmorListFont[MAX_ARMOR_Y][MAX_ARMOR_X][3];
#else
	CD3DHanFont*		m_pItemListFont; // 페이지 폰트
#endif		// C_DRAWTEXT_UPGRADE_YMJOO
	// END 2014-07-02 by ymjoo DrawText 성능 개선 작업 (아머컬렉션)

	CD3DHanFont*		m_pConuntFont; // 페이지 폰트

	CINFImageBtn*		m_pCloseBtn;

	CINFImageBtn*		m_pArmorApplyBtn;
	CINFImageBtn*		m_pArmorInitBtn;

	char		m_strMixKind[MIX_SEARCH_KIND_COUNT][MAX_PATH];		// 검색 종류

	BOOL		m_bShowWnd;
	
	POINT					m_ptBkPos;	// 윈도우 시작위치
	
	// 윈도우 이동 관련 처리
	BOOL					m_bMove;
	POINT					m_ptCommOpMouse;
	
	INT						m_nSearchItemNum;

	char					m_szPrice[64];
	vector<CItemInfo*>		m_vecSource;
	vector<CItemInfo*>		m_vecTarget;
	BOOL					m_bShowTarget;

	int						m_nEditElementIndex;

	vector<structResultMixingInfo>		m_vecMaterialList;						// 검색결과
	vector<structResultMixingInfo>		m_vecMixingItemList;		// 재료 결과
		


	// 해제시 외형 아머 
	RECT					m_rcInitItem;
	
	// 현재 착용 아머
	RECT					m_rcShowItem;

	RECT					m_rcApplayItem;


	// 재료들 리스트
	RECT					m_rcArmorItem[MAX_ARMOR_Y][MAX_ARMOR_X];

	INT						m_nMaxShowItemLen;// 최대 라인수 // 아이템 최대 라인수
	int						m_pPageCntBtnPosY;
	int						m_nDiffScrollHeight;

	//////////////////// 선택항목관련 처리 ////////////////////	
	CINFImageEx*		m_pSearchIconBk;		
	

	CINFImageEx*		m_pSearchListBk;		// ItemList배경
	CINFImageEx*		m_pApplyItem;			// 적용된 ItemList배경
	CINFImageEx*		m_pSearchListSel;		// 선택한 ItemList배경
	CINFImageEx*		m_pUseSel;
	

	INT					m_nShowItemNum;				
	UID64_t				m_uItemUniNum;	

	char				m_nBkImageGroup[MAX_PATH];

	map<INT, CINFImageEx*>		m_mapBigIconInfo[MAX_COLLECT_UNIT];		// BigIcon

	CINFImageEx*		m_pGearTabImg[MAX_COLLECT_UNIT];		
	RECT				m_rcGearTab[MAX_COLLECT_UNIT];

	INT				m_nSelUnitCollectType;

	POINT				m_ptSelectPos;
	
	CINFImageEx*		m_pLackItemImage ;

	// 2014-07-18 by ymjoo 프리미엄 아머컬렉션 구현
#ifdef SC_PREMIUM_COLLECTION_ARMOR_YMJOO_BCKIM
	CINFImageEx*		m_pPremiumMarkImage[2];
	float				m_fPremiumMarkTickCnt;
	BOOL				m_bIsPremiumMarkTwinkle;
#endif
	// END 2014-07-18 by ymjoo 프리미엄 아머컬렉션 구현
};
#endif // !defined(AFX_ARMOR_COLLECT_WND_H__872742CD_5E6C_46B0_869F_C6F429B0A473__INCLUDED_)
