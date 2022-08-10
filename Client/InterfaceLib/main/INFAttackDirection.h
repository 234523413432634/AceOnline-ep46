 // INFAttackDirection.h: interface for the CINFAttackDirection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFATTACKDIRECTION_H__6AD52A80_E91A_4F13_8442_6FD00F2D565F__INCLUDED_)
#define AFX_INFATTACKDIRECTION_H__6AD52A80_E91A_4F13_8442_6FD00F2D565F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "INFBase.h"


// Unit Warning and State
typedef enum
{
	INF_AD_DIRECTION0,
	INF_AD_DIRECTION1,
	INF_AD_DIRECTION2,
	INF_AD_DIRECTION3,
	INF_AD_DIRECTION4,
	INF_AD_DIRECTION5,
	INF_AD_DIRECTION6,
	INF_AD_DIRECTION7,

	INF_AD_DIRECTION_MAX
	
} INFAttackDirection;


/////////////////////////////////////////////////////////////////////////////////
///	\class 	CINFAttackDirection
/// \brief  ������ ���� ���ݴ������� ������ ���� ������ �˾ƺ��� ���� �Ϸ���
/////////////////////////////////////////////////////////////////////////////////
class CINFImage;
class CINFImageEx;								  // 2011. 10. 10 by jskim UI�ý��� ����
class CINFAttackDirection  : public CINFBase
{
public:
	CINFAttackDirection();
	CINFAttackDirection(CAtumNode* pParent);
	virtual ~CINFAttackDirection();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();

	// main function
	void Tick();
	void Render();

	// sub function
	void OnAttackDirection( DWORD dwShiftNum );					//
	void OffAttackDirection( DWORD dwShiftNum );
	BOOL IsSeted( DWORD dwDirection );

public:
	// init()
	bool m_bRestored;

	// image data
	CINFImageEx	*m_pImgAttackDirection[INF_AD_DIRECTION_MAX];	// ������ ���� �������� ���� ���� �̹���
	
	// tick(), render()
	DWORD m_dwAttackDirectionBits;								// ������⿡�� �¾Ҵ��� �V�õǴ� 32��Ʈ Flag
	CRemainTime tRemainTime[INF_AD_DIRECTION_MAX];				// �V�õ� �� m_dwAttackDirectionBits�� ���� �ð�
};

#endif // !defined(AFX_INFATTACKDIRECTION_H__6AD52A80_E91A_4F13_8442_6FD00F2D565F__INCLUDED_)
