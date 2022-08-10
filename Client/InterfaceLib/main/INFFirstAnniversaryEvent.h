// INFFirstAnniversaryEvent.h: interface for the CINFFirstAnniversaryEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFFIRSTANNIVERSARYEVENT_H__2F4134E1_D52D_4F52_B82F_28427297C819__INCLUDED_)
#define AFX_INFFIRSTANNIVERSARYEVENT_H__2F4134E1_D52D_4F52_B82F_28427297C819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-09-24 by ymjoo 2주년 감사카드
#include "INFFirstAnniversaryEventString.h"
// END 2014-09-24 by ymjoo 2주년 감사카드

class CINFBase;

class CINFFirstAnniversaryEvent  : public CINFBase
{
public:
	CINFFirstAnniversaryEvent();
	virtual ~CINFFirstAnniversaryEvent();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void	InitWndData();
	
	virtual void	Tick();
	void			Render();	

	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);	

	virtual int OnLButtonDown(WPARAM wParam, LPARAM lParam);
	virtual int OnMouseMove(WPARAM wParam, LPARAM lParam);
	virtual int OnLButtonUp(WPARAM wParam, LPARAM lParam);
	virtual void UpdateBtnPos();
	void ShowWnd(BOOL bShow,POINT *ptMixWndPos=NULL);
	BOOL IsShowWnd();
	BOOL IsMouseCaps(POINT ptPos);
/////////////////////////////////////////////////////////////////////////////////////////////////
	void CreateWebWindow(char* strWebSite,int nWebPosX,int nWebPosY,int nWebWidth,int nWebHeight);
	void DestroyWebWindow();
	void ShowWebWindow(int nWebPosX,int nWebPosY, int nWebWidth,int nWebHeight);
	void HideWebWindow();
/////////////////////////////////////////////////////////////////////////////////////////////////
	CINFImageBtn*		m_pCloseBtn;
	CINFImageEx*		m_pBackImg;
	CINFImageEx*		m_pBlackImg;
	POINT				m_ptBkPos;	// 윈도우 시작위치
	BOOL				m_bShowWnd;
	POINT				m_ptWinSize;
/////////////////////////////////////////////////////////////////////////////////////////////////

	// 2014-09-24 by ymjoo 2주년 감사카드
	CD3DHanFont*		m_pTextFont[FIRST_ANNIVERSARY_EVENT_MSG_LINE];
	int					m_pRandMagNum;
	CFirstAnniversaryEventMsgStr*	m_pFirstAnniversaryEventMsgStr;
	// END 2014-09-24 by ymjoo 2주년 감사카드
};

#endif // !defined(AFX_INFFIRSTANNIVERSARYEVENT_H__2F4134E1_D52D_4F52_B82F_28427297C819__INCLUDED_)
