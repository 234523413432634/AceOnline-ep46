// INFImageListTreeCtrl.cpp: implementation of the CINFImageListTreeCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AtumApplication.h"
#include "INFImage.h"
#include "GameDataLast.h"
#include "INFGameMain.h"
#include "D3DHanFont.h"

#include "INFImageListTreeCtrl.h"
#include "INFImageEx.h"										 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define	SCROLL_BALL_WIDTH					11
#define	SCROLL_BALL_SCROLL_CAP				100

CINFImageListTreeCtrl::CINFImageListTreeCtrl()
{	
	m_pMainImageTreeHead.nNodeId = -1;
	m_fPosX = m_fPosY = 0;
	m_fWidth = m_fHeight = 1;
	m_fSubItemStartX = 0;
	m_fSubItemStartY = 0;
	m_fScrollStartX = m_fScrollStartY = 0;

	int nCnt = 0;
	for(nCnt = 0;nCnt < MAX_LIST_SHOW;nCnt++)
	{
		m_pListShowImage[nCnt] = NULL;
		memset(&m_ptIconSize[nCnt],0x00, sizeof(POINT));
	}		
	memset(&m_ptSubItemSize,0x00, sizeof(POINT));
	
	m_pSubItemImage = NULL;
	m_pFontSubItem = NULL;
	m_pINFScrollBar = NULL;
	m_pSelItemImage = NULL;
	m_nScrollStep = 100;

	m_pSelPoint = NULL;

	m_bTextList = FALSE;

	m_pMainImageTreeHead.pChild = NULL;
	m_pMainImageTreeHead.pNext = NULL;
}

CINFImageListTreeCtrl::~CINFImageListTreeCtrl()
{
	DeleteDeviceObjects();
}


HRESULT CINFImageListTreeCtrl::InitDeviceObjects(int nScrollStep)
{
	m_nScrollStep = nScrollStep;
	{
		char  szScBall[30];	
		if(NULL == m_pINFScrollBar)
		{
			m_pINFScrollBar = new CINFArenaScrollBar;
		}		
		wsprintf(szScBall,"c_scrlb");
		
		m_pINFScrollBar->InitDeviceObjects(m_nScrollStep, szScBall);
	}

	m_pFontSubItem = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE,1024,32);
	m_pFontSubItem->InitDeviceObjects(g_pD3dDev);

	return S_OK;
}

void CINFImageListTreeCtrl::_RestoreDeviceObjects(ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		_RestoreDeviceObjects(it->pChild);
		_RestoreDeviceObjects(it->pNext);
		if(it->pInfImage)
		{
			it->pInfImage->RestoreDeviceObjects();
		}
	}
}

HRESULT CINFImageListTreeCtrl::RestoreDeviceObjects()
{
	_RestoreDeviceObjects(&m_pMainImageTreeHead);
	
	int nCnt = 0;	
	{
		for(nCnt = 0;nCnt < MAX_LIST_SHOW;nCnt++)
		{
			m_pListShowImage[nCnt]->RestoreDeviceObjects();
			m_ptIconSize[nCnt] = m_pListShowImage[nCnt]->GetImgSize();
		}
	}	
	m_pSubItemImage->RestoreDeviceObjects();
	m_ptSubItemSize = m_pSubItemImage->GetImgSize();

	m_pSelItemImage->RestoreDeviceObjects();
	
	m_pFontSubItem->RestoreDeviceObjects();
	
	{
		m_pINFScrollBar->RestoreDeviceObjects();		
	}
	return S_OK;
}

HRESULT CINFImageListTreeCtrl::DeleteDeviceObjects()
{
	DeleteaAllItem();	
	int nCnt = 0;
	{
		for(nCnt = 0;nCnt < MAX_LIST_SHOW;nCnt++)
		{
			if(m_pListShowImage[nCnt])
			{
				m_pListShowImage[nCnt]->DeleteDeviceObjects();
				SAFE_DELETE(m_pListShowImage[nCnt]);
			}			
		}
	}
	if(m_pSubItemImage)
	{
		m_pSubItemImage->DeleteDeviceObjects();
		SAFE_DELETE(m_pSubItemImage);
	}
	
	if(m_pSelItemImage)
	{
		m_pSelItemImage->DeleteDeviceObjects();
		SAFE_DELETE(m_pSelItemImage);
	}
	

	if(m_pFontSubItem)
	{
		m_pFontSubItem->DeleteDeviceObjects();
		SAFE_DELETE(m_pFontSubItem);
	}

	if(m_pINFScrollBar)
	{
		m_pINFScrollBar->DeleteDeviceObjects();	
		SAFE_DELETE(m_pINFScrollBar);
	}
	
	return S_OK;
}

void CINFImageListTreeCtrl::_InvalidateDeviceObjects(ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		_InvalidateDeviceObjects(it->pChild);
		_InvalidateDeviceObjects(it->pNext);
		if(it->pInfImage)
		{
			it->pInfImage->InvalidateDeviceObjects();
		}
	}
}

HRESULT CINFImageListTreeCtrl::InvalidateDeviceObjects()
{
	_InvalidateDeviceObjects(&m_pMainImageTreeHead);

	int nCnt = 0;
	{
		for(nCnt = 0;nCnt < MAX_LIST_SHOW;nCnt++)
		{
			m_pListShowImage[nCnt]->InvalidateDeviceObjects();
		}
	}
	m_pSubItemImage->InvalidateDeviceObjects();
	m_pSelItemImage->InvalidateDeviceObjects();
	m_pFontSubItem->InvalidateDeviceObjects();
	m_pINFScrollBar->InvalidateDeviceObjects();
	return S_OK;
}

void CINFImageListTreeCtrl::Render()
{
	RenderListItem();
	m_pINFScrollBar->Render();
}

void CINFImageListTreeCtrl::_RenderListItem(ImageListTreeCtrlIcon* it, int* nCnt, int* nShowItemCnt, int fPosX)
{
	if(it)
	{
		do 
		{
			BOOL bSelect = FALSE;
			int nSelPosX = 0;		   
			ImageListTreeCtrlIcon* pItem = it;
			CINFImage* pImage = pItem->pInfImage;			

			if(FALSE == pItem->bShow)
			{
				continue;
			}		
			if(*nCnt < m_pINFScrollBar->GetScrollStep())
			{
				(*nCnt)++;
				continue;
			}	

		// 2013-11-29 by ssjung 거래소 구현
			if(m_bTextList){if(*nShowItemCnt >= m_nScrollStep)break;}
			else
			{
				// 그리는 최대수 
				if(*nShowItemCnt > m_nScrollStep)
				{
					break;
				}
			}
		// end 2013-11-29 by ssjung 거래소 구현
			(*nShowItemCnt)++;	
			int listImageWidthSpace = 15;

			float fPosY = pItem->fPosY;

			if(it->pChild)
			{
				if(!pItem->bEpTitle)
				{				
					//fPosX += (int)(m_ptIconSize[LIST_SHOW_PLUS].x);
				}

				if(pItem->bExtend)
				{
					m_pListShowImage[LIST_SHOW_MINUS]->Move(fPosX, fPosY);
					m_pListShowImage[LIST_SHOW_MINUS]->Render();				
				}
				else
				{
					m_pListShowImage[LIST_SHOW_PLUS]->Move(fPosX, fPosY);
					m_pListShowImage[LIST_SHOW_PLUS]->Render();				
				}	 

				if(!m_bTextList)
				{
					if(pImage)
					{
						pImage->Move(fPosX + listImageWidthSpace, pItem->fPosY);
						pImage->Render();
					}			
				}
				else
				{
					if(pItem->szItemTxt)
					{
						m_pFontSubItem->DrawText(fPosX + listImageWidthSpace, pItem->fPosY - 2, GUI_FONT_COLOR, pItem->szItemTxt, 0L);
					}
					
					if(m_pSelPoint == pItem)
					{
						bSelect = TRUE;
						if(pItem != m_pMainImageTreeHead.pChild)
						{
							nSelPosX = m_fSubItemStartX/2;
						}
					}
				}
			}
			// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
			else if(_IsParentAndChild(m_pMainImageTreeHead.pChild, it))
			{
				m_pListShowImage[LIST_SHOW_MINUS]->Move(fPosX, fPosY);
				m_pListShowImage[LIST_SHOW_MINUS]->Render();		 
				
				if(!m_bTextList)
				{
					if(pImage)
					{
						pImage->Move(fPosX + listImageWidthSpace, pItem->fPosY);
						pImage->Render();
					}			
				}
				else
				{
					if(pItem->szItemTxt)
					{
						m_pFontSubItem->DrawText(fPosX + listImageWidthSpace, pItem->fPosY - 2, GUI_FONT_COLOR, pItem->szItemTxt, 0L);
					}
					
					if(m_pSelPoint == pItem)
					{
						bSelect = TRUE;
						if(pItem != m_pMainImageTreeHead.pChild)
						{
							nSelPosX = m_fSubItemStartX/2;
						}
					}
				}
			}
			// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
			else
			{		
				int listLastImageSpace = -7;
				m_pSubItemImage->Move(fPosX + listLastImageSpace, pItem->fPosY + m_fSubItemStartY - 2);
				m_pSubItemImage->Render();			

				if(m_pSelPoint == pItem)
				{
					bSelect = TRUE;
					nSelPosX = m_fSubItemStartX;
				}

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI시스템 변경
				char chBuf[512], chResultBuf[512];
				chBuf[0] = NULL;
				memset(chResultBuf,0x00,512);

				if(!m_bTextList)
				{
					if(bSelect)
					{					
						wsprintf(chBuf, "\\e%s", pItem->szItemTxt);
					}
				}

				if(m_bTextList || !bSelect)
				{
					strncpy(chBuf, pItem->szItemTxt, strlen(pItem->szItemTxt)+1);
				}

				if( strlen(chBuf) > 25 )
				{
					char chTemp[512];
					memset(chTemp,0x00,512);
 					strncpy( chResultBuf, chBuf, 25 );
 					chResultBuf[ GetStringBuffPos(chResultBuf, GetStringBuffLen( chResultBuf ) - 1) ]='\0';
 					sprintf(chBuf,"%s..", chResultBuf);
				}  
#else
				char chBuf[512];
				chBuf[0] = NULL;

				if(bSelect)
				{					
					wsprintf(chBuf, "\\e%s", pItem->szItemTxt);
				}
				else
				{
					strncpy(chBuf, pItem->szItemTxt, strlen(pItem->szItemTxt)+1);
				}
#endif
				
				m_pFontSubItem->DrawText(fPosX + listImageWidthSpace + listLastImageSpace, pItem->fPosY - 2, pItem->dwColor, chBuf, 0L);

				if(!m_bTextList)
				{
					if(bSelect)
					{
						m_pSelItemImage->Move(m_fPosX - 2, pItem->fPosY - 2);
						m_pSelItemImage->Render();
					}
				}
			}

			if(m_bTextList)
			{
				if(bSelect)
				{
					m_pSelItemImage->Move(m_fPosX - 2, pItem->fPosY - 2);
					m_pSelItemImage->Render();
				}
			}	
		} while (FALSE);

		_RenderListItem(it->pChild, nCnt, nShowItemCnt, fPosX + (int)(m_ptIconSize[LIST_SHOW_PLUS].x));
		_RenderListItem(it->pNext, nCnt, nShowItemCnt, fPosX);
	}
}

void CINFImageListTreeCtrl::RenderListItem()
{		
	float fPosX = m_fPosX;	

	int nItemNonEpTitle = (int)(m_ptIconSize[LIST_SHOW_PLUS].x);

	ImageListTreeCtrlIcon* it = m_pMainImageTreeHead.pChild;
	int nCnt=0;
	int nShowItemCnt = 0;	
	_RenderListItem(it, &nCnt, &nShowItemCnt, fPosX);
}

void CINFImageListTreeCtrl::InitDeviceEtc(char* pPlus, char* pMinus, char* pSmallIcon, char* pSelIcon)
{
	DataHeader	* pDataHeader = NULL;
	// 
	{
		if(NULL == m_pListShowImage[LIST_SHOW_PLUS])
		{
			m_pListShowImage[LIST_SHOW_PLUS] = new CINFImageEx;
		}		
		pDataHeader = g_pGameMain->FindResource(pPlus);
		m_pListShowImage[LIST_SHOW_PLUS]->InitDeviceObjects(pDataHeader);
	}	
	{
		if(NULL == m_pListShowImage[LIST_SHOW_MINUS])
		{
			m_pListShowImage[LIST_SHOW_MINUS] = new CINFImageEx;
		}		
		pDataHeader = g_pGameMain->FindResource(pMinus);
		m_pListShowImage[LIST_SHOW_MINUS]->InitDeviceObjects(pDataHeader);				
	}
	{
		if(NULL == m_pSubItemImage)
		{
			m_pSubItemImage = new CINFImageEx;
		}		
		pDataHeader = g_pGameMain->FindResource(pSmallIcon);
		m_pSubItemImage->InitDeviceObjects(pDataHeader);				
	}
	// 선책 상자
	{
		if(NULL == m_pSelItemImage)
		{
			m_pSelItemImage = new CINFImageEx;
		}		
		pDataHeader = g_pGameMain->FindResource(pSelIcon);
		m_pSelItemImage->InitDeviceObjects(pDataHeader);
		m_pSelItemImage->Scaling(m_pSelItemImage->GetScale().x * 1.1f, m_pSelItemImage->GetScale().y);
	}
}

ImageListTreeCtrlIcon* CINFImageListTreeCtrl::_FindImageListTreeCtrlIconById(ImageListTreeCtrlIcon* it, int nodeId)
{
	if(it)
	{
		if(it->nNodeId == nodeId)
		{
			return it;
		}
		ImageListTreeCtrlIcon* resultIt;
		resultIt = _FindImageListTreeCtrlIconById(it->pChild, nodeId);
		if(resultIt)
		{
			return resultIt;
		}
		resultIt = _FindImageListTreeCtrlIconById(it->pNext, nodeId);
		if(resultIt)
		{
			return resultIt;
		}
	}
	return NULL;
}

BYTE CINFImageListTreeCtrl::FindKindBySelectedItem()
{
	if(m_pSelPoint)
	{
		return m_pSelPoint->byKind;
	}
	return NULL;
	// NULL을 반환하는 경우 (BYTE)0 이 반환되므로 사용시 주의
}

int CINFImageListTreeCtrl::FindNodeIdBySelectedItem()
{
	if(m_pSelPoint)
	{
		return m_pSelPoint->nNodeId;
	}
	return m_pMainImageTreeHead.nNodeId;
	// 이 경우 -1이 반환되므로 사용시 주의
}

BYTE CINFImageListTreeCtrl::FindParentKindById(int nodeId)
{
	ImageListTreeCtrlIcon* parent = _FindParentImageListTreeCtrlIconById(&m_pMainImageTreeHead, nodeId);
	if(parent)
	{
		if(parent == &m_pMainImageTreeHead)
		{
			return NULL;
		}
		else
		{
			return parent->byKind;
		}
	}
	return NULL;
	// NULL을 반환하는 경우 (BYTE)0 이 반환되므로 사용시 주의
}

int CINFImageListTreeCtrl::FindParentIdById(int nodeId)
{
	ImageListTreeCtrlIcon* parent = _FindParentImageListTreeCtrlIconById(&m_pMainImageTreeHead, nodeId);
	if(parent)
	{
		return parent->nNodeId;
	}
	return m_pMainImageTreeHead.nNodeId;
	// 이 경우 -1이 반환되므로 사용시 주의
}

ImageListTreeCtrlIcon* CINFImageListTreeCtrl::_FindParentImageListTreeCtrlIconById(ImageListTreeCtrlIcon* it, int nodeId)
{
	ImageListTreeCtrlIcon* child = _FindImageListTreeCtrlIconById(&m_pMainImageTreeHead, nodeId);
	if(it && child)
	{
		if(_IsAncestorAndDescendent(it, child))
		{
			if(_IsParentAndChild(it, child))
			{
				return it;
			}

			ImageListTreeCtrlIcon* pItem = it->pChild;

			while(pItem)
			{
				if(_IsAncestorAndDescendent(pItem, child))
				{
					return _FindParentImageListTreeCtrlIconById(pItem, nodeId);
				}
				pItem = pItem->pNext;
			}
		}
	}
	return NULL;
}

char* CINFImageListTreeCtrl::GetItemTitleById(int nodeId)
{
	ImageListTreeCtrlIcon* it = _FindImageListTreeCtrlIconById(&m_pMainImageTreeHead, nodeId);
	return it->szItemTxt;
}

void CINFImageListTreeCtrl::InsertItem(int nEpId, int parentNodeId, int nodeId, char* pItemName, DWORD dwColor, BOOL bEpTitle)
{
	ImageListTreeCtrlIcon* pNewNode = new ImageListTreeCtrlIcon;
	ImageListTreeCtrlIcon* pParentNode = _FindImageListTreeCtrlIconById(&m_pMainImageTreeHead, parentNodeId);
	
	if(!pParentNode)
	{
		pParentNode = &m_pMainImageTreeHead;
	}
	
	ImageListTreeCtrlIcon* pPrevNode = pParentNode->pChild;
	
	if(!pPrevNode)
	{
		pParentNode->pChild = pNewNode;
	}
	else
	{
		while(pPrevNode->pNext)
		{
			pPrevNode = pPrevNode->pNext;
		}
		pPrevNode->pNext = pNewNode;
	}
	
	pNewNode->fPosX			= 0;
	pNewNode->fPosY			= 0;
	pNewNode->fWidth		= 1;
	pNewNode->fHeight		= 1;
	pNewNode->bShow			= bEpTitle;
	pNewNode->bExtend		= FALSE;
	pNewNode->dwColor		= dwColor;
	memset(pNewNode->szItemTxt, 0x00, 256);
	pNewNode->nEpId			= nEpId;
	pNewNode->bEpTitle		= bEpTitle;
	pNewNode->pInfImage		= new CINFImageEx;
	pNewNode->nNodeId		= nodeId;
	pNewNode->pChild		= NULL;
	pNewNode->pNext			= NULL;

	DataHeader* pDataHeader	= g_pGameMain->FindResource(pItemName);
	pNewNode->pInfImage->InitDeviceObjects(pDataHeader);
}

void CINFImageListTreeCtrl::InsertTextItem(int nEpId, int parentNodeId, int nodeId, char *szItemTitle, DWORD dwColor, BOOL bEpTitle)
{
	ImageListTreeCtrlIcon* pNewNode = new ImageListTreeCtrlIcon;
	ImageListTreeCtrlIcon* pParentNode = _FindImageListTreeCtrlIconById(&m_pMainImageTreeHead, parentNodeId);

	if(!pParentNode)
	{
		pParentNode = &m_pMainImageTreeHead;
	}
	
	ImageListTreeCtrlIcon* pPrevNode = pParentNode->pChild;
	
	if(!pPrevNode)
	{
		pParentNode->pChild = pNewNode;
	}
	else
	{
		while(pPrevNode->pNext)
		{
			pPrevNode = pPrevNode->pNext;
		}
		pPrevNode->pNext = pNewNode;
	}
	
	pNewNode->fPosX			= 0;
	pNewNode->fPosY			= 0;
	pNewNode->fWidth		= 1;
	pNewNode->fHeight		= 1;
	pNewNode->bShow			= bEpTitle;
	pNewNode->bExtend		= FALSE;
	pNewNode->dwColor		= dwColor;
	memset(pNewNode->szItemTxt, 0x00, 256);
	strncpy(pNewNode->szItemTxt, szItemTitle, strlen(szItemTitle)+1);
	pNewNode->nEpId			= nEpId;
	pNewNode->bEpTitle		= bEpTitle;
	pNewNode->pInfImage		= NULL;	
	pNewNode->nNodeId		= nodeId;
	pNewNode->pChild		= NULL;
	pNewNode->pNext			= NULL;
}

void CINFImageListTreeCtrl::InsertTextItemWithByKind(int nEpId, int parentNodeId, int nodeId, int byKind, char *szItemTitle, DWORD dwColor, BOOL bEpTitle)
{
	ImageListTreeCtrlIcon* pNewNode = new ImageListTreeCtrlIcon;
	ImageListTreeCtrlIcon* pParentNode = _FindImageListTreeCtrlIconById(&m_pMainImageTreeHead, parentNodeId);
	
	if(!pParentNode)
	{
		pParentNode = &m_pMainImageTreeHead;
	}
	
	ImageListTreeCtrlIcon* pPrevNode = pParentNode->pChild;
	
	if(!pPrevNode)
	{
		pParentNode->pChild = pNewNode;
	}
	else
	{
		while(pPrevNode->pNext)
		{
			pPrevNode = pPrevNode->pNext;
		}
		pPrevNode->pNext = pNewNode;
	}
	
	pNewNode->fPosX			= 0;
	pNewNode->fPosY			= 0;
	pNewNode->fWidth		= 1;
	pNewNode->fHeight		= 1;
	pNewNode->bShow			= bEpTitle;
	pNewNode->bExtend		= FALSE;
	pNewNode->dwColor		= dwColor;
	memset(pNewNode->szItemTxt, 0x00, 256);
	strncpy(pNewNode->szItemTxt, szItemTitle, strlen(szItemTitle)+1);
	pNewNode->nEpId			= nEpId;
	pNewNode->bEpTitle		= bEpTitle;
	pNewNode->pInfImage		= NULL;	
	pNewNode->nNodeId		= nodeId;
	pNewNode->byKind		= byKind;
	pNewNode->pChild		= NULL;
	pNewNode->pNext			= NULL;
}

void CINFImageListTreeCtrl::SortListCtrlItem()
{
	/*sort(m_vecMainImage.begin(), m_vecMainImage.end(), Mission_Sort_MainIdx());*/
}

int CINFImageListTreeCtrl::_GetMaxShowItem(ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		int result = 0;
		if(TRUE == it->bShow)
		{
			++result;
		}
		return result + _GetMaxShowItem(it->pChild) + _GetMaxShowItem(it->pNext);
	}
	return 0;
}

int CINFImageListTreeCtrl::GetMaxShowItem()
{
	return _GetMaxShowItem(m_pMainImageTreeHead.pChild);
}

void CINFImageListTreeCtrl::_UpdateItemPos(ImageListTreeCtrlIcon* it, int* nCnt, float* fPosY)
{
	if(it)
	{
		do 
		{
			ImageListTreeCtrlIcon* pItem = it;
			CINFImage* pImage = pItem->pInfImage;
			if(FALSE == pItem->bShow)
			{
				pItem->fPosX		= 0;
				pItem->fPosY		= -100;
				pItem->fWidth		= 1;
				pItem->fHeight		= 1;
				continue;
			}			
			
			if(*nCnt < m_pINFScrollBar->GetScrollStep())
			{
				++(*nCnt);
				continue;
			}		
			
			pItem->fPosX = m_fPosX;
			
			if(it->pChild)
			{
				pItem->fPosX += (int)(m_ptIconSize[LIST_SHOW_PLUS].x*1.5);				
				if(!pItem->bEpTitle)
				{
					pItem->fPosX += (int)(m_ptIconSize[LIST_SHOW_PLUS].x);
				}
			}
			else
			{
	#ifdef C_EPSODE4_UI_CHANGE_JSKIM
				pItem->fPosX += m_fSubItemStartX + (int)(m_ptSubItemSize.x*1.1);	
	#else 
				pItem->fPosX += m_fSubItemStartX + (int)(m_ptSubItemSize.x*1.5);	
	#endif
			}

			pItem->fPosY = *fPosY;
			*fPosY += (int)(m_ptIconSize[LIST_SHOW_PLUS].y*1.5);

			if(pImage)
			{
				pItem->fWidth	= pImage->GetImgSize().x;
				pItem->fHeight	= pImage->GetImgSize().y;
			}
			else
			{
				pItem->fWidth	= m_fWidth;
				pItem->fHeight	= (int)(m_ptIconSize[LIST_SHOW_MINUS].y*1.5);
			}
		} while (FALSE);

		_UpdateItemPos(it->pChild, nCnt, fPosY);
		_UpdateItemPos(it->pNext, nCnt, fPosY);
	}
}

void CINFImageListTreeCtrl::UpdateItemPos()
{
	float fPosX, fPosY;
	fPosX = m_fPosX;
	fPosY = m_fPosY;
	int nCnt=0;

	_UpdateItemPos(m_pMainImageTreeHead.pChild, &nCnt, &fPosY);
}

void CINFImageListTreeCtrl::SetListCtrlPos(float fPosX, float fPosY, 
										float fSubItemStartX, float fSubItemStartY, 
										float fScrollStartX, float fScrollStartY, 
										float fWidth,float fHeight)
{
	m_fPosX = fPosX;
	m_fPosY = fPosY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;

	m_fSubItemStartX = fSubItemStartX;
	m_fSubItemStartY = fSubItemStartY;

	m_fScrollStartX = fScrollStartX;
	m_fScrollStartY = fScrollStartY;

	UpdateScrollPos();

	// 리스트 컨트롤 위치 지정
	UpdateItemPos();
}

void CINFImageListTreeCtrl::UpdateScrollPos()
{	
	float fPosX, fPosY;
	fPosX = m_fPosX;
	fPosY = m_fPosY;			
	
	POINT ptScroll;
	RECT rcMouseWhell, rcMousePos;
	
	// 휠 위치지정 
	rcMouseWhell.left		= fPosX ;
	rcMouseWhell.top		= fPosY;
	rcMouseWhell.right		= rcMouseWhell.left + m_fWidth;
	rcMouseWhell.bottom		= rcMouseWhell.top + m_fHeight;
	
	
	// 마우스 위치 지정
	rcMousePos.left			= fPosX + m_fScrollStartX;
	rcMousePos.top			= fPosY + m_fScrollStartY;
	rcMousePos.right		= rcMousePos.left;
	rcMousePos.bottom		= rcMousePos.top;
		
	// Resotre를 해야지만 이미지 크기를 알수 있다. 
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI시스템 변경
	m_pINFScrollBar->SetPosition(rcMousePos.left, rcMousePos.top, SCROLL_BALL_WIDTH, m_fHeight - 23 );
#else		  
	m_pINFScrollBar->SetPosition(rcMousePos.left, rcMousePos.top, SCROLL_BALL_WIDTH, m_fHeight);
#endif
	m_pINFScrollBar->SetMouseWhellRect(rcMouseWhell);			

	ptScroll = m_pINFScrollBar->GetImgBkSize();
	
	rcMousePos.bottom		= rcMousePos.top + ptScroll.y + SCROLL_BALL_SCROLL_CAP;
	rcMousePos.top			= SCROLL_BALL_SCROLL_CAP;
	rcMousePos.right		= rcMousePos.left + SCROLL_BALL_SCROLL_CAP;
	rcMousePos.left			-= SCROLL_BALL_SCROLL_CAP;					
	
	m_pINFScrollBar->SetMouseBallRect(rcMousePos);
}

void CINFImageListTreeCtrl::_FillImageListTreeCtrlIconToVector(vector<ImageListTreeCtrlIcon*>* targetVec, ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		targetVec->push_back(it);
		_FillImageListTreeCtrlIconToVector(targetVec, it->pChild);
		_FillImageListTreeCtrlIconToVector(targetVec, it->pNext);
	}
}

BOOL CINFImageListTreeCtrl::OnLButtonDown(POINT pt)
{		
	vector<ImageListTreeCtrlIcon*> vecMainImage;
	vecMainImage.clear();
	_FillImageListTreeCtrlIconToVector(&vecMainImage, m_pMainImageTreeHead.pChild);

	vector<ImageListTreeCtrlIcon*>::iterator it = vecMainImage.begin();
	int nCnt=0;
	while(it != vecMainImage.end())
	{
		ImageListTreeCtrlIcon* pItem = *it;
		if(FALSE == pItem->bShow)
		{
			it++;
			continue;
		}		

		if(nCnt < m_pINFScrollBar->GetScrollStep())
		{
			nCnt++;
			it++;
			continue;
		}	

		if((m_fPosX <= pt.x)
			&&(pt.x <= (m_fPosX+pItem->fWidth)))
		{		
			if((pItem->fPosY <= pt.y)
				&&(pt.y <= (pItem->fPosY+pItem->fHeight)))
			{

				if(pItem->pChild)
				{
					pItem->bExtend ^= TRUE;
					PopupItem(pItem);
					if(m_bTextList)
						SetSelPoint(pItem);
				}
				else
				{
					SetSelPoint(pItem);
				}
				
				return TRUE;
			}
		}
		it++;
	}
	{
		BOOL bClick = m_pINFScrollBar->IsMouseBallPos(pt);
		if(bClick)		
		{
			m_pINFScrollBar->SetMouseMoveMode(TRUE);
			return TRUE;
		}		
	}
	return FALSE;
}

BOOL CINFImageListTreeCtrl::OnLButtonUp(POINT pt)
{
	BOOL bClick = m_pINFScrollBar->GetMouseMoveMode();
	if(bClick)		
	{
		m_pINFScrollBar->SetMouseMoveMode(FALSE);			
	}		
	return bClick;
}

BOOL CINFImageListTreeCtrl::OnMouseMove(POINT pt)
{
	if(m_pINFScrollBar->GetMouseMoveMode())
	{
		if(FALSE == m_pINFScrollBar->IsMouseScrollPos(pt))
		{
			m_pINFScrollBar->SetMouseMoveMode(FALSE);
			return FALSE;			
		}
		m_pINFScrollBar->SetScrollPos(pt);
		UpdateItemPos();
		return TRUE;			
	}
	return FALSE;	

}
BOOL CINFImageListTreeCtrl::OnMouseWheel(POINT pt, WPARAM wParam, LPARAM lParam)
{
	BOOL bClick = m_pINFScrollBar->IsMouseWhellPos(pt);
	if(bClick)		
	{			
		m_pINFScrollBar->OnMouseWheel(wParam, lParam);	
		UpdateItemPos();		
	}
	return bClick;
}

BOOL CINFImageListTreeCtrl::_IsParentAndChild(ImageListTreeCtrlIcon* parentIt, ImageListTreeCtrlIcon* childIt)
{
	if(parentIt && childIt && parentIt->pChild)
	{
		ImageListTreeCtrlIcon* it = parentIt->pChild;
		while(it)
		{
			if(it == childIt)
			{
				return TRUE;
			}
			it = it->pNext;
		}
	}
	return FALSE;
}

BOOL CINFImageListTreeCtrl::_IsAncestorAndDescendent(ImageListTreeCtrlIcon* ancestorIt, ImageListTreeCtrlIcon* descendentIt)
{
	if(ancestorIt && descendentIt && ancestorIt->pChild)
	{
		ImageListTreeCtrlIcon* it = ancestorIt->pChild;
		while(it)
		{
			if(it == descendentIt)
			{
				return TRUE;
			}
			if(_IsAncestorAndDescendent(it, descendentIt))
			{
				return TRUE;
			}
			it = it->pNext;
		}
	}
	return FALSE;
}

void CINFImageListTreeCtrl::PopupItem(ImageListTreeCtrlIcon* popupItem)
{
	vector<ImageListTreeCtrlIcon*> vecMainImage;
	vecMainImage.clear();
	_FillImageListTreeCtrlIconToVector(&vecMainImage, m_pMainImageTreeHead.pChild);
	
	vector<ImageListTreeCtrlIcon*>::iterator it = vecMainImage.begin();
	while(it != vecMainImage.end())
	{
		ImageListTreeCtrlIcon* pItem = *it;
		if(popupItem->bEpTitle)
		{
			if(pItem->nEpId == popupItem->nEpId)
			{
				if(pItem->bEpTitle)
				{
					pItem->bExtend = popupItem->bExtend;
					pItem->bShow = TRUE;
				}
				else if(_IsParentAndChild(popupItem, pItem))
				{
					if(pItem->pChild)
					{
						pItem->bExtend = FALSE;
						//pItem->bShow = popupItem->bExtend;
					}
					// 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
//					else
//					{
//						pItem->bShow = FALSE;					    
//					}
					pItem->bShow = popupItem->bExtend;
					// END 2014-01-15 by ymjoo 파괴경매장 카테고리 목록 개선
				}
				else
				{
					pItem->bShow = FALSE;
				}
			}
		}
		else
		{
			if(_IsParentAndChild(popupItem, pItem))
			{				
				if(pItem->pChild)
				{				
					if(!pItem->bEpTitle)
					{
						pItem->bExtend = FALSE;
						pItem->bShow = popupItem->bExtend;
					}									
				}
				else
				{
					pItem->bShow = popupItem->bExtend;
				}		
			}		
			else if(_IsAncestorAndDescendent(popupItem, pItem))
			{
				pItem->bExtend = FALSE;
				pItem->bShow = FALSE;
			}
		}		
		it++;
	}		
	int nShowItem = GetMaxShowItem();
	m_pINFScrollBar->SetOnlyMaxItem(nShowItem);	

	UpdateItemPos();	
}

void CINFImageListTreeCtrl::ShowTitleAllEpId(BOOL bShow, int nEpId)	
{
	/*
	vector<stImageListTreeCtrlIcon*>::iterator it = m_vecMainImage.begin();
	while(it != m_vecMainImage.end())
	{
		stImageListTreeCtrlIcon* pItem = (*it);
		if(pItem->nEpId == nEpId 
			&& 0 == pItem->nSubIdx
			&& !pItem->bEpTitle)
		{
			(*it)->bShow = bShow;
		}
		it++;
	}

	int nShowItem = GetMaxShowItem();
	m_pINFScrollBar->SetOnlyMaxItem(nShowItem);	
	// 리스트 컨트롤 위치 지정
	UpdateItemPos();	
	*/
}

void CINFImageListTreeCtrl::_DeleteAllItem(ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		_DeleteAllItem(it->pChild);
		_DeleteAllItem(it->pNext);
		if(it->pInfImage)
		{
			it->pInfImage->DeleteDeviceObjects();
			SAFE_DELETE(it->pInfImage);
		}
		SAFE_DELETE(it);
	}
}

void CINFImageListTreeCtrl::DeleteaAllItem()
{
	_DeleteAllItem(m_pMainImageTreeHead.pChild);
	m_pMainImageTreeHead.pChild = NULL;
	SetSelPoint(NULL);
}

void CINFImageListTreeCtrl::_RestoreItemDeviceObjects(ImageListTreeCtrlIcon* it)
{
	if(it)
	{
		_RestoreItemDeviceObjects(it->pChild);
		_RestoreItemDeviceObjects(it->pNext);
		ImageListTreeCtrlIcon* pItem = it;
		if(pItem->pInfImage)
		{
			pItem->pInfImage->RestoreDeviceObjects();
		}
	}
}

void CINFImageListTreeCtrl::RestoreItemDeviceObjects()
{
	_RestoreItemDeviceObjects(m_pMainImageTreeHead.pChild);

	int nShowItem = GetMaxShowItem();
	m_pINFScrollBar->SetOnlyMaxItem(nShowItem);	
}

void CINFImageListTreeCtrl::ResetContent()
{
	DeleteaAllItem();
}

void CINFImageListTreeCtrl::SetSelPoint(ImageListTreeCtrlIcon* it)
{
	m_pSelPoint = it;
}