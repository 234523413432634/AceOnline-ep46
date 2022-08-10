// INFNumEditBox.h: interface for the CINFNumEditBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFNUMEDITBOX_H__4EE1EDCB_E75B_4B39_B948_C9871617F003__INCLUDED_)
#define AFX_INFNUMEDITBOX_H__4EE1EDCB_E75B_4B39_B948_C9871617F003__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "INFEditBox.h"

#include "INFBase.h"


class CINFNumEditBox    : public CINFEditBox
{
public:
	CINFNumEditBox();
	virtual ~CINFNumEditBox();

	virtual void Render(BOOL nColorNum = FALSE);		// 2014-05-07 by ssjung 거래소 금액에 따라 색이 변하도록 수정
	virtual BOOL WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	virtual void EnableEdit(BOOL bEnableEdit);	
	virtual BOOL OnLButtonDown(POINT ptPos);	

	void SetMaxStringLen(int nMaxStringLen);

private:
	BOOL OnKeyDown(WPARAM wParam, LPARAM lParam);	
	
	BOOL CheckNum(LPARAM lParam, char* pSmallKey, char* pBigKey);

private:
	// 최대 글씨 수 
	int				m_nMaxStringLen ;

};

#endif // !defined(AFX_INFNUMEDITBOX_H__4EE1EDCB_E75B_4B39_B948_C9871617F003__INCLUDED_)
