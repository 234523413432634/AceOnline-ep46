// INFTradeItemAdd.h: interface for the CINFTradeItemAdd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFTRADEITEMADD_H__67F8D5BC_DFAA_4252_9923_5443DEB151DF__INCLUDED_)
#define AFX_INFTRADEITEMADD_H__67F8D5BC_DFAA_4252_9923_5443DEB151DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)
//#include "INFBase.h"

// class CINFMessageBox;
// class CINFImage;
// class CD3DHanFont;
// class CItemInfo;
// class CINFImageEx;
// class CINFImageBtn;
// class CINFGroupImage;
// class CINFGroupManager;
// class CINFListBox;
// class CINFIcon;
// class CINFNumEditBox;
// END 2014-06-17 �ŷ��� �߰��۾� (�ּ� ó��)

class CINFTradeItemAdd : public CINFBase
{
public:
	CINFTradeItemAdd(CAtumNode* pParent);
	virtual ~CINFTradeItemAdd();

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

	void SetbtnPos();

	BOOL UpLoadItem(CItemInfo* i_pItem);
	void InvenToSourceItem(CItemInfo* pItemInfo, int nCount);
	void InitData();
	void NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum);
	int NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount);

	void ADDItem();
	void ADDItemOk(UID64_t ItemUID);
	
	CINFGroupImage*		m_pBackImg;					//����̹��� 
	CINFListBox*		m_pMoneyComboBox;			//���� ���� ���� �޺��ڽ� 
	CINFImageBtn*		m_pAddBtn;					// ���  
	CINFImageBtn*		m_pMaxBtn;					// ALL ��ư 
	
	POINT				m_ptStartPos;

	BYTE				m_byMoneySelect;

	CItemInfo*			m_pSourceItem;

	CINFIcon*			m_pIconInfo;

	char				m_pItemName[140];

	CD3DHanFont*		m_pSelItemNameFont;			//������ �̸� ��Ʈ 

	CINFNumEditBox*		m_pNumEditBox;
	CINFNumEditBox*		m_pMoneyEditBox;

	CINFImageBtn*		m_pUpCntBtn;
	CINFImageBtn*		m_pDownCntBtn;

	CItemInfo*			m_nCurerntInfo;
};

#endif // !defined(AFX_INFTRADEITEMADD_H__67F8D5BC_DFAA_4252_9923_5443DEB151DF__INCLUDED_)
