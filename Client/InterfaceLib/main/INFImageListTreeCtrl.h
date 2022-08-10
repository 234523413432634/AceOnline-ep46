// INFImageListTreeCtrl.h: interface for the CINFImageListTreeCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFIMAGELISTTREECTRL_H__FB81E265_C306_4E7B_9993_75A7C0D30E80__INCLUDED_)
#define AFX_INFIMAGELISTTREECTRL_H__FB81E265_C306_4E7B_9993_75A7C0D30E80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "INFBase.h"
#include "INFArenaScrollBar.h"
#include "INFImageListCtrl.h"

struct ImageListTreeCtrlIcon
{
	int							nNodeId;		// 트리에서의 위치 식별용
	BYTE						byKind;			// 노드 아이템 종류 식별용
	CINFImageEx*				pInfImage;
	float						fPosX;
	float						fPosY;
	float						fWidth;
	float						fHeight;
	ImageListTreeCtrlIcon*		pChild;			// 첫번째 자식 노드
	ImageListTreeCtrlIcon*		pNext;			// 다음 형제 노드
	BOOL						bShow;
	BOOL						bExtend;		// 확장키 
	DWORD						dwColor;
	char						szItemTxt[256];
	int							nEpId;			// 에피소드 ID
	BOOL						bEpTitle;		// 에피소드 Title
};

class CINFImageEx;
class CINFImageListTreeCtrl : public CINFBase  
{
public:
	CINFImageListTreeCtrl();
	virtual ~CINFImageListTreeCtrl();
	
	HRESULT InitDeviceObjects(int nScrollStep);	
	virtual HRESULT RestoreDeviceObjects();	
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();

	void Render();
	void RestoreItemDeviceObjects();
	
	void InitDeviceEtc(char* pPlus, char* pMinus, char* pSmallIcon, char* pSelIcon);
	
	void InsertItem(int nEpId, int parentNodeId, int nodeId, char* pItemName, DWORD dwColor, BOOL bEpTitle);
	void InsertTextItem(int nEpId, int parentNodeId, int nodeId, char *szItemTitle, DWORD dwColor, BOOL bEpTitle);
	void InsertTextItemWithByKind(int nEpId, int parentNodeId, int nodeId, int byKind, char *szItemTitle, DWORD dwColor, BOOL bEpTitle);
	
	void SetListCtrlPos(float fPosX, float fPosY, 
		float fSubItemStartX, float fSubItemStartY, 
		float fScrollStartX, float fScrollStartY, 
		float fWidth,float fHeight);
	void SortListCtrlItem();
	
	BOOL OnLButtonDown(POINT pt);	
	BOOL OnMouseWheel(POINT pt, WPARAM wParam, LPARAM lParam);
	BOOL OnLButtonUp(POINT pt);
	BOOL OnMouseMove(POINT pt);
	
	
	void DeleteaAllItem();
	void UpdateItemPos();
	
	void ResetContent();
	void PopupItem(ImageListTreeCtrlIcon* pItem);
	void SetSelPoint(ImageListTreeCtrlIcon* it);
	
	void ShowTitleAllEpId(BOOL bShow, int nEpId);
	
	void SetTextList(BOOL bVal){m_bTextList = bVal;}
	
	BYTE FindKindBySelectedItem();
	int FindNodeIdBySelectedItem();
	BYTE FindParentKindById(int nodeId);
	int FindParentIdById(int nodeId);
	char* GetItemTitleById(int nodeId);

private:
	int GetMaxShowItem();

	void RenderListItem();
	void UpdateScrollPos();
	
	void _RestoreDeviceObjects(ImageListTreeCtrlIcon* it);
	void _InvalidateDeviceObjects(ImageListTreeCtrlIcon* it);
	void _RenderListItem(ImageListTreeCtrlIcon* it, int* nCnt, int* nShowItemCnt, int fPosX);
	int _GetMaxShowItem(ImageListTreeCtrlIcon* it);
	void _UpdateItemPos(ImageListTreeCtrlIcon* it, int* nCnt, float* fPosY);
	void _FillImageListTreeCtrlIconToVector(vector<ImageListTreeCtrlIcon*>* targetVec, ImageListTreeCtrlIcon* it);
	void _DeleteAllItem(ImageListTreeCtrlIcon* it);
	void _RestoreItemDeviceObjects(ImageListTreeCtrlIcon* it);
	
	BOOL _IsParentAndChild(ImageListTreeCtrlIcon* parentIt, ImageListTreeCtrlIcon* childIt);
	BOOL _IsAncestorAndDescendent(ImageListTreeCtrlIcon* ancestorIt, ImageListTreeCtrlIcon* descendentIt);

	ImageListTreeCtrlIcon* _FindImageListTreeCtrlIconById(ImageListTreeCtrlIcon* it, int nodeId);
	ImageListTreeCtrlIcon* _FindParentImageListTreeCtrlIconById(ImageListTreeCtrlIcon* it, int nodeId);

private:	
	ImageListTreeCtrlIcon		m_pMainImageTreeHead;
	
	
	CINFImageEx*				m_pListShowImage[MAX_LIST_SHOW];
	POINT						m_ptIconSize[MAX_LIST_SHOW];
	
	CINFImageEx*				m_pSubItemImage;
	POINT						m_ptSubItemSize;
	
	CINFImageEx*				m_pSelItemImage;
	
	CINFArenaScrollBar*			m_pINFScrollBar;
	int							m_nScrollStep;
	
	CD3DHanFont *				m_pFontSubItem;				
	
	float						m_fPosX;
	float						m_fPosY;
	float						m_fWidth;
	float						m_fHeight;
	
	float						m_fSubItemStartX;
	float						m_fSubItemStartY;
	
	float						m_fScrollStartX;
	float						m_fScrollStartY;

	ImageListTreeCtrlIcon*		m_pSelPoint;
	
	BOOL						m_bTextList;
};

#endif // !defined(AFX_INFIMAGELISTTREECTRL_H__FB81E265_C306_4E7B_9993_75A7C0D30E80__INCLUDED_)
