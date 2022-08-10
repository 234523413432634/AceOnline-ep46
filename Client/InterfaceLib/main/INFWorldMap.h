// INFWorldMap.h: interface for the CINFWorldMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFWORLDMAP_H__674C7CC4_E8A2_4E8C_8BB0_50FFF3F0496A__INCLUDED_)
#define AFX_INFWORLDMAP_H__674C7CC4_E8A2_4E8C_8BB0_50FFF3F0496A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 2014-06-17 ����� �߰��۾� (�ּ�ó��)
//#include "INFBase.h"
//#include "AtumParam.h"
// END 2014-06-17 ����� �߰��۾� (�ּ�ó��)

#define WORLD_MAP_RAW_NUM	4
#define WORLD_MAP_COL_NUM	2

struct WorldMap_MapInfo
{
	POINT ptMapPos;
	CINFImageEx* pToolTipImg;
	MAP_INFO* mapInfo;
	DWORD dwCityWarp;
};

class CINFWorldMap : public CINFBase
{
public:
	CINFWorldMap();
	virtual ~CINFWorldMap();
	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void Render();
	virtual void Tick();
	virtual int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ShowWnd(BOOL bShow);
	
	int OnLButtonDown(WPARAM wParam, LPARAM lParam);
	int OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int OnRButtonDown(WPARAM wParam, LPARAM lParam);
	int OnRButtonUp(WPARAM wParam, LPARAM lParam);
	int OnMouseMove(WPARAM wParam, LPARAM lParam);
	int OnMouseWheel(WPARAM wParam, LPARAM lParam);

	BOOL IsShowWorldMap() {return m_bShowWnd;}

	int GetHeight();
	int GetWidth();
	void ChangeWorldMapScale(float oldScale, float newScale);
	void CheckWorldMapPosition();
	void RenderWorldMap();
	void RenderLineHighlight();
	void RenderImage(CINFImageEx* image, int x, int y, int nWidth, int nHeight, float fScale);
	void RenderToolTip();
	void CheckToolTipPosition();
	void LoadMapInfo();
	void InitMapInfo(MapIndex_t mapIdx, LONG x, LONG y, DWORD cityWarp = 0x0);

	DataHeader* FindWorldMapImgResource(char* szRcName);
//-----------------------------------------------------------------------------------------------------------

private:
	/// ����� �������̽� ///
	BOOL							m_bShowWnd;					// ���� â�� ���������� üũ
	CINFImageEx*					m_pBackImg;					// ��� �̹��� 

	/// ���콺 �̺�Ʈ ///
	BOOL							m_bIsMouseDown;				// ���콺 �¹�ư�� ���� ���� : �̹��� �巡��
	BOOL							m_bIsMouseDownAndMoved;		// ���콺 Ŭ�� �̺�Ʈ �˻��
	POINT							m_ptClickedPoint;			// ���콺�� ���ȴ� ��ġ : �̹��� �巡�� ������ǥ
	POINT							m_ptWorldMapPosOld;			// ���콺�� ������ �� ������� ���� ��ġ

	/// ����� �̹��� ///
	CINFImageEx*					m_pWorldMapInfoImg;			// ����� ����(����) �̹���
	POINT							m_ptWorldMapPos;			// ������� ���� ��ġ
	float							m_fWorldMapScale;			// ������� ũ�� ����
	CINFImageEx*					m_arrWorldMapImg[WORLD_MAP_RAW_NUM][WORLD_MAP_COL_NUM];	
																// ����� ���� �̹���

	/// ����� ȿ���� ///
	CINFImageEx*					m_pCurrentMapImg;			// ���� �� �̹���
	int								m_nCurrentMapTwinkleStep;	// ���� ���� ��¦�̰� ����� �ּ���.
	CINFImageEx*					m_pStrategyPointMapImg;		// ������ �� �̹���
	CINFImageEx*					m_pOutPostMapImg;			// ���������� �� �̹���
	CINFImageEx*					m_pMSWarMapImg;				// ���� �� �̹���
	int								m_nMapTwinkleStep;			// �������� ��¦�̰� ����� �ּ���.
	CINFImageEx*					m_pCannotMoveMapImg;		// �̵� �Ұ� �� �̹���
	
	/// �� ���� ///
	vector<WorldMap_MapInfo>		m_vecMapInfo;				// �� �ʵ��� ����
	CGameData*						m_pMapImgData;				// ����� ���� �̹��� ���ҽ� ������
	WorldMap_MapInfo*				m_pToolTipShowMap;			// ǥ�õ� ���� : ������ NULL
	CINFGroupImage*					m_pToolTipBackImg;			// ���� ���
	CD3DHanFont*					m_pToolTipMapNameFont;		// ���� ���̸�
	CINFImageEx*					m_pToolTipBaseEnImg;		// ���� ������ ǥ��
	CINFImageEx*					m_pToolTipBaseWarImg;		// ���� ������ ǥ��
	CINFImageEx*					m_pToolTipOutPostEnImg;		// ���� ���������� ǥ��
	CINFImageEx*					m_pToolTipOutPostWarImg;	// ���� ���������� ǥ��
	CINFImageEx*					m_pToolTipMSWarEnImg;		// ���� ���� ǥ��
	CINFImageEx*					m_pToolTipMSWarWarImg;		// ���� ���� ǥ��
	CINFImageEx*					m_pToolTipWarpEnImg;		// ���� ���� ���� ǥ��
	CINFImageEx*					m_pToolTipANIImg;			// ���� ���� ANI ǥ��
	CINFImageEx*					m_pToolTipBCUImg;			// ���� ���� BCU ǥ��
	POINT							m_ptToolTipPos;				// ���� ��ġ

	/// ���� �� ���̶���Ʈ ///
	CINFImageEx*					m_pLineHighlightANIImg;		// �˸��� ���� �� ���̶���Ʈ
	CINFImageEx*					m_pLineHighlightBCUImg;		// ���������� ���� �� ���̶���Ʈ
	CINFImageEx*					m_pLineHighlightNeutralImg;	// �߸� ���� �� ���̶���Ʈ

	/// �巡��, Ȯ����� ///
	POINT							m_ptWorldMapReturnPos;		// ���ƿ� ��ġ
	float							m_fWorldMapTargetScale;		// Ȯ�����

};

#endif // !defined(AFX_INFWORLDMAP_H__674C7CC4_E8A2_4E8C_8BB0_50FFF3F0496A__INCLUDED_)
