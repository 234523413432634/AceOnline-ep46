// INFWorldMap.cpp: implementation of the CINFWorldMap class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "ShuttleChild.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFWorldMap.h"
#include "INFGameMainOutPost.h"
#include "AtumDatabase.h"
#include "IMSocketManager.h"
#include "QuestData.h"
// 2014-06-17 ����� �߰��۾� (�ּ�ó��)
//#include "AtumApplication.h""
//#include "INFCityBase.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "CharacterChild.h"
//#include "INFWindow.h"
//#include "Interface.h"
//#include "INFImageBtn.h"
// END 2014-06-17 ����� �߰��۾� (�ּ�ó��)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// �������̽� ũ��/��ġ
#define WMAP_INF_WIDTH			988

#define WMAP_WIDTH				867
#define WMAP_LEFT				(max((((int)(g_pD3dApp->GetBackBufferDesc().Width) - WMAP_INF_WIDTH) / 2 + 121), 0))
#define WMAP_RIGHT				(WMAP_LEFT + WMAP_WIDTH)
#define WMAP_HEIGHT				709
#define WMAP_TOP				(max((((int)(g_pD3dApp->GetBackBufferDesc().Height) - WMAP_HEIGHT) / 2), 0))
#define WMAP_BOTTOM				(WMAP_TOP + WMAP_HEIGHT)
#define WMAP_MARGIN_TOP			19
#define WMAP_MARGIN_BOTTOM		31
#define WMAP_MARGIN_LEFT		21
#define WMAP_MARGIN_RIGHT		37
#define WMAP_CENTER_X			(int)((WMAP_LEFT + WMAP_MARGIN_LEFT + WMAP_RIGHT - WMAP_MARGIN_RIGHT) / 2)
#define WMAP_CENTER_Y			(int)((WMAP_TOP + WMAP_MARGIN_TOP + WMAP_BOTTOM - WMAP_MARGIN_BOTTOM) / 2)

// ������ ũ��/��ġ
#define WMAP_INFO_WIDTH			123
#define WMAP_INFO_LEFT			(max((((int)(g_pD3dApp->GetBackBufferDesc().Width) - WMAP_INF_WIDTH) / 2), 0))
#define WMAP_INFO_RIGHT			(WMAP_INFO_LEFT + WMAP_INFO_WIDTH)
#define WMAP_INFO_HEIGHT		709
#define WMAP_INFO_TOP			(max((((int)(g_pD3dApp->GetBackBufferDesc().Height) - WMAP_INFO_HEIGHT) / 2), 0))
#define WMAP_INFO_BOTTOM		(WMAP_INFO_TOP + WMAP_INFO_HEIGHT)

// �� �̹���
#define WMAP_CITY_IMG_SIZE		78
#define WMAP_FIELD_IMG_SIZE		28

// ������� Ȯ��/��� ����
#define WMAPSCALE_S				0.2625f
#define WMAPSCALE_M				0.5f
#define WMAPSCALE_L				1.0f

// ������ ǥ�� Ŀ�� ����
#define WMAP_TOOLTIP_RANGE		40

// ���� �����۵� ��ġ
#define WMAP_TOOLTIP_NAME_X		149
#define WMAP_TOOLTIP_NAME_Y		11
#define WMAP_TOOLTIP_IMG_X		149
#define WMAP_TOOLTIP_IMG_Y		131
#define WMAP_TOOLTIP_BASE_X		167
#define WMAP_TOOLTIP_BASE_Y		220
#define WMAP_TOOLTIP_OUTPOST_X	140
#define WMAP_TOOLTIP_OUTPOST_Y	220
#define WMAP_TOOLTIP_MSWAR_X	194
#define WMAP_TOOLTIP_MSWAR_Y	220
#define WMAP_TOOLTIP_WARP_X		221
#define WMAP_TOOLTIP_WARP_Y		220
#define WMAP_TOOLTIP_INFL_X		248
#define WMAP_TOOLTIP_INFL_Y		220

// ����
#define WMAP_TOOLTIP_WARP_BCU	0x1
#define WMAP_TOOLTIP_WARP_ANI	0x2
#define WMAP_TOOLTIP_WARP_BOTH	(WMAP_TOOLTIP_WARP_BCU|WMAP_TOOLTIP_WARP_ANI)

// ���� �� ���̶���Ʈ
#define WMAP_LINE_ANI_X			683
#define WMAP_LINE_ANI_Y			1224
#define WMAP_LINE_BCU_X			683
#define WMAP_LINE_BCU_Y			145
#define WMAP_LINE_NEUTRAL_X		144
#define WMAP_LINE_NEUTRAL_Y		861

CINFWorldMap::CINFWorldMap()
{
	// ����� �������̽�
	m_bShowWnd = FALSE;
	m_pBackImg = NULL;
	
	// ���콺 �̺�Ʈ
	m_bIsMouseDown = FALSE;
	m_bIsMouseDownAndMoved = FALSE;
	m_ptClickedPoint.x = 0;
	m_ptClickedPoint.y = 0;
	m_ptWorldMapPosOld.x = 0;
	m_ptWorldMapPosOld.y = 0;

	// ����� �̹���
	m_pWorldMapInfoImg = NULL;
	m_ptWorldMapPos.x = 0;
	m_ptWorldMapPos.y = 0;
	m_fWorldMapScale = WMAPSCALE_S;
	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			m_arrWorldMapImg[i][j] = NULL;
		}
	}

	// ����� ȿ����
	m_pCurrentMapImg = NULL;
	m_nCurrentMapTwinkleStep = 0;
	m_pStrategyPointMapImg = NULL;
	m_pOutPostMapImg = NULL;
	m_pMSWarMapImg = NULL;
	m_nMapTwinkleStep = 0;
	m_pCannotMoveMapImg = NULL;
	
	// �� ����
	m_vecMapInfo.clear();
	m_pMapImgData = NULL;
	m_pToolTipShowMap = NULL;
	m_pToolTipBackImg = NULL;
	m_pToolTipMapNameFont = NULL;
	m_pToolTipBaseEnImg = NULL;
	m_pToolTipBaseWarImg = NULL;
	m_pToolTipOutPostEnImg = NULL;
	m_pToolTipOutPostWarImg = NULL;
	m_pToolTipMSWarEnImg = NULL;
	m_pToolTipMSWarWarImg = NULL;
	m_pToolTipWarpEnImg = NULL;
	m_pToolTipANIImg = NULL;
	m_pToolTipBCUImg = NULL;
	m_ptToolTipPos.x = 0;
	m_ptToolTipPos.y = 0;

	// ���� �� ���̶���Ʈ
	m_pLineHighlightANIImg = NULL;
	m_pLineHighlightBCUImg = NULL;
	m_pLineHighlightNeutralImg = NULL;

	// �巡��, Ȯ�����
	m_ptWorldMapReturnPos.x = 0;
	m_ptWorldMapReturnPos.y = 0;
	m_fWorldMapTargetScale = WMAPSCALE_S;
}

CINFWorldMap::~CINFWorldMap()
{
	SAFE_DELETE(m_pBackImg);

	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			SAFE_DELETE(m_arrWorldMapImg[i][j]);
		}
	}

	SAFE_DELETE(m_pWorldMapInfoImg);

	SAFE_DELETE(m_pCurrentMapImg);
	SAFE_DELETE(m_pStrategyPointMapImg);
	SAFE_DELETE(m_pOutPostMapImg);
	SAFE_DELETE(m_pMSWarMapImg);
	SAFE_DELETE(m_pCannotMoveMapImg);
	
	for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
	{
		SAFE_DELETE(it->pToolTipImg);
	}
	m_vecMapInfo.clear();
	
	m_pToolTipShowMap = NULL;
	
	SAFE_DELETE(m_pToolTipBackImg);
	SAFE_DELETE(m_pToolTipMapNameFont);
	SAFE_DELETE(m_pToolTipBaseEnImg);
	SAFE_DELETE(m_pToolTipBaseWarImg);
	SAFE_DELETE(m_pToolTipOutPostEnImg);
	SAFE_DELETE(m_pToolTipOutPostWarImg);
	SAFE_DELETE(m_pToolTipMSWarEnImg);
	SAFE_DELETE(m_pToolTipMSWarWarImg);
	SAFE_DELETE(m_pToolTipWarpEnImg);
	SAFE_DELETE(m_pToolTipANIImg);
	SAFE_DELETE(m_pToolTipBCUImg);

	SAFE_DELETE(m_pLineHighlightANIImg);
	SAFE_DELETE(m_pLineHighlightBCUImg);
	SAFE_DELETE(m_pLineHighlightNeutralImg);
	
	SAFE_DELETE(m_pMapImgData);
}

HRESULT CINFWorldMap::InitDeviceObjects()
{
	if(NULL == m_pBackImg)
	{	
		DataHeader* pDataHeader = FindResource("cabk");
		if(pDataHeader)
		{
			m_pBackImg = new CINFImageEx;			
			m_pBackImg->InitDeviceObjects(pDataHeader);
		}
	}
	
	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			if(NULL == m_arrWorldMapImg[i][j])
			{
				char buf[100];
				wsprintf(buf, "Wmap_0%d", i * WORLD_MAP_COL_NUM + j + 1);
				DataHeader* pDataHeader = FindResource(buf);
				if(pDataHeader)
				{
					m_arrWorldMapImg[i][j] = new CINFImageEx;
					m_arrWorldMapImg[i][j]->InitDeviceObjects(pDataHeader);
				}
			}
		}
	}

	if(NULL == m_pWorldMapInfoImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_info");
		if(pDataHeader)
		{
			m_pWorldMapInfoImg = new CINFImageEx;
			m_pWorldMapInfoImg->InitDeviceObjects(pDataHeader);
		}
	}

	if(NULL == m_pCurrentMapImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_I");
		if(pDataHeader)
		{
			m_pCurrentMapImg = new CINFImageEx;
			m_pCurrentMapImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pStrategyPointMapImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_war");
		if(pDataHeader)
		{
			m_pStrategyPointMapImg = new CINFImageEx;
			m_pStrategyPointMapImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pOutPostMapImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_war");
		if(pDataHeader)
		{
			m_pOutPostMapImg = new CINFImageEx;
			m_pOutPostMapImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pMSWarMapImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_war");
		if(pDataHeader)
		{
			m_pMSWarMapImg = new CINFImageEx;
			m_pMSWarMapImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pCannotMoveMapImg)
	{
		DataHeader* pDataHeader = FindResource("Wmap_dis");
		if(pDataHeader)
		{
			m_pCannotMoveMapImg = new CINFImageEx;
			m_pCannotMoveMapImg->InitDeviceObjects(pDataHeader);
		}
	}
	
	if(NULL == m_pToolTipBackImg)
	{
		DataHeader* pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("Wmap_tip");
		if(pDataHeader)
		{	
			m_pToolTipBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage( pDataHeader );
			m_pToolTipBackImg->InitDeviceObjects(g_pD3dApp->m_pImageList);
		}
	}
	if(NULL == m_pToolTipMapNameFont)
	{
		m_pToolTipMapNameFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE|D3DFONT_BOLD, FALSE, 512, 32);
		m_pToolTipMapNameFont->InitDeviceObjects(g_pD3dDev);
	}
	if(NULL == m_pToolTipBaseEnImg)
	{
		DataHeader* pDataHeader = FindResource("base_en");
		if(pDataHeader)
		{
			m_pToolTipBaseEnImg = new CINFImageEx;
			m_pToolTipBaseEnImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipBaseWarImg)
	{
		DataHeader* pDataHeader = FindResource("base_war");
		if(pDataHeader)
		{
			m_pToolTipBaseWarImg = new CINFImageEx;
			m_pToolTipBaseWarImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipOutPostEnImg)
	{
		DataHeader* pDataHeader = FindResource("outpost_en");
		if(pDataHeader)
		{
			m_pToolTipOutPostEnImg = new CINFImageEx;
			m_pToolTipOutPostEnImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipOutPostWarImg)
	{
		DataHeader* pDataHeader = FindResource("outpost_war");
		if(pDataHeader)
		{
			m_pToolTipOutPostWarImg = new CINFImageEx;
			m_pToolTipOutPostWarImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipMSWarEnImg)
	{
		DataHeader* pDataHeader = FindResource("mship_en");
		if(pDataHeader)
		{
			m_pToolTipMSWarEnImg = new CINFImageEx;
			m_pToolTipMSWarEnImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipMSWarWarImg)
	{
		DataHeader* pDataHeader = FindResource("mship_war");
		if(pDataHeader)
		{
			m_pToolTipMSWarWarImg = new CINFImageEx;
			m_pToolTipMSWarWarImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipWarpEnImg)
	{
		DataHeader* pDataHeader = FindResource("warp_en");
		if(pDataHeader)
		{
			m_pToolTipWarpEnImg = new CINFImageEx;
			m_pToolTipWarpEnImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipANIImg)
	{
		DataHeader* pDataHeader = FindResource("ani_en");
		if(pDataHeader)
		{
			m_pToolTipANIImg = new CINFImageEx;
			m_pToolTipANIImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pToolTipBCUImg)
	{
		DataHeader* pDataHeader = FindResource("bcu_en");
		if(pDataHeader)
		{
			m_pToolTipBCUImg = new CINFImageEx;
			m_pToolTipBCUImg->InitDeviceObjects(pDataHeader);
		}
	}

	if(NULL == m_pLineHighlightANIImg)
	{
		DataHeader* pDataHeader = FindResource("ani_line");
		if(pDataHeader)
		{
			m_pLineHighlightANIImg = new CINFImageEx;
			m_pLineHighlightANIImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pLineHighlightBCUImg)
	{
		DataHeader* pDataHeader = FindResource("bcu_line");
		if(pDataHeader)
		{
			m_pLineHighlightBCUImg = new CINFImageEx;
			m_pLineHighlightBCUImg->InitDeviceObjects(pDataHeader);
		}
	}
	if(NULL == m_pLineHighlightNeutralImg)
	{
		DataHeader* pDataHeader = FindResource("neu_line");
		if(pDataHeader)
		{
			m_pLineHighlightNeutralImg = new CINFImageEx;
			m_pLineHighlightNeutralImg->InitDeviceObjects(pDataHeader);
		}
	}
	
	if(NULL == m_pMapImgData)
	{
		m_pMapImgData = new CGameData;
		m_pMapImgData->SetFile(".\\Res-Tex\\mapimg.tex", FALSE, NULL, 0);
	}
	
	LoadMapInfo();

	return S_OK;
}

HRESULT CINFWorldMap::RestoreDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
	}
	
	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			if(m_arrWorldMapImg[i][j])
			{
				m_arrWorldMapImg[i][j]->RestoreDeviceObjects();
			}
		}
	}

	if(m_pWorldMapInfoImg)
	{
		m_pWorldMapInfoImg->RestoreDeviceObjects();
	}

	if(m_pCurrentMapImg)
	{
		m_pCurrentMapImg->RestoreDeviceObjects();
	}
	if(m_pStrategyPointMapImg)
	{
		m_pStrategyPointMapImg->RestoreDeviceObjects();
	}
	if(m_pOutPostMapImg)
	{
		m_pOutPostMapImg->RestoreDeviceObjects();
	}
	if(m_pMSWarMapImg)
	{
		m_pMSWarMapImg->RestoreDeviceObjects();
	}
	if(m_pCannotMoveMapImg)
	{
		m_pCannotMoveMapImg->RestoreDeviceObjects();
	}
	
	for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
	{
		if(it->pToolTipImg)
		{
			it->pToolTipImg->RestoreDeviceObjects();
		}
	}
	
	if(m_pToolTipShowMap)
	{
		//m_pToolTipShowImg->RestoreDeviceObjects();
	}

	if(m_pToolTipBackImg)
	{
		m_pToolTipBackImg->RestoreDeviceObjects();
	}
	if(m_pToolTipMapNameFont)
	{
		m_pToolTipMapNameFont->RestoreDeviceObjects();
	}
	if(m_pToolTipBaseEnImg)
	{
		m_pToolTipBaseEnImg->RestoreDeviceObjects();
	}
	if(m_pToolTipBaseWarImg)
	{
		m_pToolTipBaseWarImg->RestoreDeviceObjects();
	}
	if(m_pToolTipOutPostEnImg)
	{
		m_pToolTipOutPostEnImg->RestoreDeviceObjects();
	}
	if(m_pToolTipOutPostWarImg)
	{
		m_pToolTipOutPostWarImg->RestoreDeviceObjects();
	}
	if(m_pToolTipMSWarEnImg)
	{
		m_pToolTipMSWarEnImg->RestoreDeviceObjects();
	}
	if(m_pToolTipMSWarWarImg)
	{
		m_pToolTipMSWarWarImg->RestoreDeviceObjects();
	}
	if(m_pToolTipWarpEnImg)
	{
		m_pToolTipWarpEnImg->RestoreDeviceObjects();
	}
	if(m_pToolTipANIImg)
	{
		m_pToolTipANIImg->RestoreDeviceObjects();
	}
	if(m_pToolTipBCUImg)
	{
		m_pToolTipBCUImg->RestoreDeviceObjects();
	}

	if(m_pLineHighlightANIImg)
	{
		m_pLineHighlightANIImg->RestoreDeviceObjects();
	}
	if(m_pLineHighlightBCUImg)
	{
		m_pLineHighlightBCUImg->RestoreDeviceObjects();
	}
	if(m_pLineHighlightNeutralImg)
	{
		m_pLineHighlightNeutralImg->RestoreDeviceObjects();
	}

	return S_OK;

}

HRESULT CINFWorldMap::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			if(m_arrWorldMapImg[i][j])
			{
				m_arrWorldMapImg[i][j]->DeleteDeviceObjects();
				SAFE_DELETE(m_arrWorldMapImg[i][j]);
			}
		}
	}

	if(m_pWorldMapInfoImg)
	{
		m_pWorldMapInfoImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pWorldMapInfoImg);
	}
	
	if(m_pCurrentMapImg)
	{
		m_pCurrentMapImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pCurrentMapImg);
	}
	if(m_pStrategyPointMapImg)
	{
		m_pStrategyPointMapImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pStrategyPointMapImg);
	}
	if(m_pOutPostMapImg)
	{
		m_pOutPostMapImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pOutPostMapImg);
	}
	if(m_pMSWarMapImg)
	{
		m_pMSWarMapImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pMSWarMapImg);
	}
	if(m_pCannotMoveMapImg)
	{
		m_pCannotMoveMapImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pCannotMoveMapImg);
	}
	
	for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
	{
		if(it->pToolTipImg)
		{
			it->pToolTipImg->DeleteDeviceObjects();
			SAFE_DELETE(it->pToolTipImg);
		}
	}
	
	if(m_pToolTipShowMap)
	{
		//m_pToolTipShowImg->DeleteDeviceObjects();
		//SAFE_DELETE(m_pToolTipShowMap);
		m_pToolTipShowMap = NULL;
	}

	if(m_pToolTipBackImg)
	{
		m_pToolTipBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipBackImg);
	}
	if(m_pToolTipMapNameFont)
	{
		m_pToolTipMapNameFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipMapNameFont);
	}
	if(m_pToolTipBaseEnImg)
	{
		m_pToolTipBaseEnImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipBaseEnImg);
	}
	if(m_pToolTipBaseWarImg)
	{
		m_pToolTipBaseWarImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipBaseWarImg);
	}
	if(m_pToolTipOutPostEnImg)
	{
		m_pToolTipOutPostEnImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipOutPostEnImg);
	}
	if(m_pToolTipOutPostWarImg)
	{
		m_pToolTipOutPostWarImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipOutPostWarImg);
	}
	if(m_pToolTipMSWarEnImg)
	{
		m_pToolTipMSWarEnImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipMSWarEnImg);
	}
	if(m_pToolTipMSWarWarImg)
	{
		m_pToolTipMSWarWarImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipMSWarWarImg);
	}
	if(m_pToolTipWarpEnImg)
	{
		m_pToolTipWarpEnImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipWarpEnImg);
	}
	if(m_pToolTipANIImg)
	{
		m_pToolTipANIImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipANIImg);
	}
	if(m_pToolTipBCUImg)
	{
		m_pToolTipBCUImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pToolTipBCUImg);
	}

	if(m_pLineHighlightANIImg)
	{
		m_pLineHighlightANIImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pLineHighlightANIImg);
	}
	if(m_pLineHighlightBCUImg)
	{
		m_pLineHighlightBCUImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pLineHighlightBCUImg);
	}
	if(m_pLineHighlightNeutralImg)
	{
		m_pLineHighlightNeutralImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pLineHighlightNeutralImg);
	}
		
	if(m_pMapImgData)
	{
		SAFE_DELETE(m_pMapImgData);
	}

	return S_OK;
}

HRESULT CINFWorldMap::InvalidateDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->InvalidateDeviceObjects();
	}
	
	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			if(m_arrWorldMapImg[i][j])
			{
				m_arrWorldMapImg[i][j]->InvalidateDeviceObjects();
			}
		}
	}

	if(m_pWorldMapInfoImg)
	{
		m_pWorldMapInfoImg->InvalidateDeviceObjects();
	}

	if(m_pCurrentMapImg)
	{
		m_pCurrentMapImg->InvalidateDeviceObjects();
	}
	if(m_pStrategyPointMapImg)
	{
		m_pStrategyPointMapImg->InvalidateDeviceObjects();
	}
	if(m_pOutPostMapImg)
	{
		m_pOutPostMapImg->InvalidateDeviceObjects();
	}
	if(m_pMSWarMapImg)
	{
		m_pMSWarMapImg->InvalidateDeviceObjects();
	}
	if(m_pCannotMoveMapImg)
	{
		m_pCannotMoveMapImg->InvalidateDeviceObjects();
	}
	
	for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
	{
		if(it->pToolTipImg)
		{
			it->pToolTipImg->InvalidateDeviceObjects();
		}
	}
	
	if(m_pToolTipShowMap)
	{
		//m_pToolTipShowImg->InvalidateDeviceObjects();
	}

	if(m_pToolTipBackImg)
	{
		m_pToolTipBackImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipMapNameFont)
	{
		m_pToolTipMapNameFont->InvalidateDeviceObjects();
	}
	if(m_pToolTipBaseEnImg)
	{
		m_pToolTipBaseEnImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipBaseWarImg)
	{
		m_pToolTipBaseWarImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipOutPostEnImg)
	{
		m_pToolTipOutPostEnImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipOutPostWarImg)
	{
		m_pToolTipOutPostWarImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipMSWarEnImg)
	{
		m_pToolTipMSWarEnImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipMSWarWarImg)
	{
		m_pToolTipMSWarWarImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipWarpEnImg)
	{
		m_pToolTipWarpEnImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipANIImg)
	{
		m_pToolTipANIImg->InvalidateDeviceObjects();
	}
	if(m_pToolTipBCUImg)
	{
		m_pToolTipBCUImg->InvalidateDeviceObjects();
	}

	if(m_pLineHighlightANIImg)
	{
		m_pLineHighlightANIImg->InvalidateDeviceObjects();
	}
	if(m_pLineHighlightBCUImg)
	{
		m_pLineHighlightBCUImg->InvalidateDeviceObjects();
	}
	if(m_pLineHighlightNeutralImg)
	{
		m_pLineHighlightNeutralImg->InvalidateDeviceObjects();
	}

	return S_OK;
}

void CINFWorldMap::Render()
{
	if(!IsShowWorldMap())
	{
		return;
	}

	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	RenderWorldMap();
	
	if(m_pWorldMapInfoImg)
	{
		m_pWorldMapInfoImg->Render();
	}

	RenderToolTip();
}

void CINFWorldMap::Tick()
{
	if(!IsShowWorldMap())
	{
		return;
	}

	if(m_fWorldMapTargetScale != m_fWorldMapScale)
	{
		float ds = m_fWorldMapTargetScale - m_fWorldMapScale;
		float targetScale = m_fWorldMapScale;
		if(fabs(ds) < 0.001)
		{
			targetScale = m_fWorldMapTargetScale;
		}
		else if(fabs(ds) < 0.005)
		{
			targetScale += 0.001 * (0 < ds ? 1 : -1);
		}
		else
		{
			targetScale += ds / 5;
		}
		ChangeWorldMapScale(m_fWorldMapScale, targetScale);
	}

	if(!m_bIsMouseDown)
	{
		CheckWorldMapPosition();
		if(m_ptWorldMapReturnPos.x != m_ptWorldMapPos.x)
		{
			LONG dx = m_ptWorldMapReturnPos.x - m_ptWorldMapPos.x;
			if(fabs(dx) < 5)
			{
				m_ptWorldMapPos.x += dx / fabs(dx);
			}
			else
			{
				m_ptWorldMapPos.x += dx / 5;
			}
		}
		if(m_ptWorldMapReturnPos.y != m_ptWorldMapPos.y)
		{
			LONG dy = m_ptWorldMapReturnPos.y - m_ptWorldMapPos.y;
			if(fabs(dy) < 5)
			{
				m_ptWorldMapPos.y += dy / fabs(dy);
			}
			else
			{
				m_ptWorldMapPos.y += dy / 5;
			}
		}
	}
}

int CINFWorldMap::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(!IsShowWorldMap())
	{
		return INF_MSGPROC_NORMAL;
	}

	switch(uMsg)
	{
	case WM_MOUSEMOVE:
		{
			return OnMouseMove(wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			return OnLButtonDown(wParam, lParam);			
		}
		break;
	case WM_LBUTTONUP:
		{
			return OnLButtonUp(wParam, lParam);
		}
		break;
	case WM_RBUTTONDOWN:
		{
			return OnRButtonDown(wParam, lParam);
		}
		break;
	case WM_RBUTTONUP:
		{
			return OnRButtonUp(wParam, lParam);
		}
		break;
	case WM_MOUSEWHEEL:
		{
			return OnMouseWheel(wParam, lParam);
		}
		break;
	case WM_KEYDOWN:
		{
			if(VK_ESCAPE == wParam)
			{
				ShowWnd(FALSE);
				return INF_MSGPROC_BREAK;
			}
		}
		break;
	}

	return INF_MSGPROC_NORMAL;
}

int	CINFWorldMap::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	
	m_bIsMouseDownAndMoved = TRUE;

	if(m_bIsMouseDown)
	{
		m_pToolTipShowMap = NULL;
		m_ptWorldMapPos.x = m_ptWorldMapPosOld.x + pt.x - m_ptClickedPoint.x;
		m_ptWorldMapPos.y = m_ptWorldMapPosOld.y + pt.y - m_ptClickedPoint.y;
		return INF_MSGPROC_BREAK;
	}
	else
	{
		if(WMAP_LEFT + WMAP_MARGIN_LEFT < pt.x && pt.x < WMAP_RIGHT - WMAP_MARGIN_RIGHT
			&& WMAP_TOP + WMAP_MARGIN_TOP < pt.y && pt.y < WMAP_BOTTOM - WMAP_MARGIN_BOTTOM)
		{
			for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
			{
				LONG x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale;
				LONG y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale;
				if(x - WMAP_TOOLTIP_RANGE * m_fWorldMapScale < pt.x && pt.x < x + WMAP_TOOLTIP_RANGE * m_fWorldMapScale
					&& y - WMAP_TOOLTIP_RANGE * m_fWorldMapScale < pt.y && pt.y < y + WMAP_TOOLTIP_RANGE * m_fWorldMapScale)
				{
					m_pToolTipShowMap = &*it;
					m_ptToolTipPos = pt;
					return INF_MSGPROC_BREAK;
				}
			}
		}
		m_pToolTipShowMap = NULL;
	}

	
	return INF_MSGPROC_BREAK;
}

int	CINFWorldMap::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	m_bIsMouseDownAndMoved = TRUE;
	if(m_bIsMouseDown)
	{
		return INF_MSGPROC_BREAK;
	}

	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);

	if(WMAP_LEFT + WMAP_MARGIN_LEFT < pt.x && pt.x < WMAP_RIGHT - WMAP_MARGIN_RIGHT
		&& WMAP_TOP + WMAP_MARGIN_TOP < pt.y && pt.y < WMAP_BOTTOM - WMAP_MARGIN_BOTTOM)
	{
		m_bIsMouseDown = TRUE;
		m_ptClickedPoint = pt;
		m_ptWorldMapPosOld = m_ptWorldMapPos;
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_BREAK;
}

int	CINFWorldMap::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	if(m_bIsMouseDown)
	{
		m_bIsMouseDown = FALSE;
		
		CheckWorldMapPosition();
		
		return INF_MSGPROC_BREAK;
	}

	// 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
	//return INF_MSGPROC_BREAK;
	return INF_MSGPROC_NORMAL;
	// END 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
}

int CINFWorldMap::OnRButtonDown(WPARAM wParam, LPARAM lParam)
{
	if(m_bIsMouseDown)
	{
		return INF_MSGPROC_BREAK;
	}

	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	if(WMAP_LEFT + WMAP_MARGIN_LEFT < pt.x && pt.x < WMAP_RIGHT - WMAP_MARGIN_RIGHT
		&& WMAP_TOP + WMAP_MARGIN_TOP < pt.y && pt.y < WMAP_BOTTOM - WMAP_MARGIN_BOTTOM)
	{
		m_bIsMouseDownAndMoved = FALSE;
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_BREAK;
}

int CINFWorldMap::OnRButtonUp(WPARAM wParam, LPARAM lParam)
{
	if(m_bIsMouseDown)
	{
		// 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
		//return INF_MSGPROC_BREAK;
		return INF_MSGPROC_NORMAL;
		// END 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
	}
	
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	if(WMAP_LEFT + WMAP_MARGIN_LEFT < pt.x && pt.x < WMAP_RIGHT - WMAP_MARGIN_RIGHT
		&& WMAP_TOP + WMAP_MARGIN_TOP < pt.y && pt.y < WMAP_BOTTOM - WMAP_MARGIN_BOTTOM)
	{
		// GM�� Ŭ���� �� �̵�
		if(FALSE == m_bIsMouseDownAndMoved)
		{
			if(COMPARE_RACE(g_pShuttleChild->GetMyShuttleInfo().Race, RACE_OPERATION|RACE_GAMEMASTER))
			{
				char buf[512];
				
				for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
				{
					LONG x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale;
					LONG y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale;
					if(x - WMAP_TOOLTIP_RANGE * m_fWorldMapScale < pt.x && pt.x < x + WMAP_TOOLTIP_RANGE * m_fWorldMapScale
						&& y - WMAP_TOOLTIP_RANGE * m_fWorldMapScale < pt.y && pt.y < y + WMAP_TOOLTIP_RANGE * m_fWorldMapScale)
					{
						wsprintf(buf, "%s %d", STRCMD_CS_COMMAND_MOVE, it->mapInfo->MapIndex);
						g_pD3dApp->m_pIMSocket->SendChat(T_IC_CHAT_REGION, g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterName, buf);
						ShowWnd(FALSE);
						return INF_MSGPROC_BREAK;
					}
				}
			}
		}
		// 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
		//return INF_MSGPROC_BREAK;
		return INF_MSGPROC_NORMAL;
		// END 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
	}

	// 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
	//return INF_MSGPROC_BREAK;
	return INF_MSGPROC_NORMAL;
	// END 2014-07-30 by ymjoo ������� �ѳ����� ������ ��� ������ ���� ����
}

int	CINFWorldMap::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	if(m_bIsMouseDown)
	{
		return INF_MSGPROC_BREAK;
	}
	
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	
// 	if(WMAP_LEFT < pt.x && pt.x < WMAP_RIGHT
// 		&& WMAP_TOP < pt.y && pt.y < WMAP_BOTTOM)
	{
		// �� ���� (�̹��� Ȯ��)
		if(0 < (int)wParam)
		{
			if(WMAPSCALE_S == m_fWorldMapTargetScale)
			{
				m_fWorldMapTargetScale = WMAPSCALE_M;
			}
			else if(WMAPSCALE_M == m_fWorldMapTargetScale)
			{
				m_fWorldMapTargetScale = WMAPSCALE_L;
			}
		}
		// �� �Ʒ��� (�̹��� ���)
		else
		{
			if(WMAPSCALE_L == m_fWorldMapTargetScale)
			{
				m_fWorldMapTargetScale = WMAPSCALE_M;
			}
			else if(WMAPSCALE_M == m_fWorldMapTargetScale)
			{
				m_fWorldMapTargetScale = WMAPSCALE_S;
			}
		}
		CheckWorldMapPosition();
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_BREAK;
}

void CINFWorldMap::ShowWnd(BOOL bShow)
{
	m_bShowWnd = bShow;
	if(bShow)
	{
		int nWebPoxX = WMAP_LEFT;
		int nWebPoxY = WMAP_TOP;
		m_pBackImg->Move(nWebPoxX, nWebPoxY);
		m_pBackImg->Render();

		m_pWorldMapInfoImg->Move(WMAP_INFO_LEFT, WMAP_INFO_TOP);
		m_pWorldMapInfoImg->Render();

		m_bIsMouseDown = FALSE;
		m_bIsMouseDownAndMoved = TRUE;

		m_fWorldMapScale = WMAPSCALE_S;
		m_fWorldMapTargetScale = WMAPSCALE_S;
		m_ptWorldMapPos.x = WMAP_CENTER_X - GetWidth() / 2;
		m_ptWorldMapPos.y = WMAP_CENTER_Y - GetHeight() / 2;
		
		m_nCurrentMapTwinkleStep = 0;
		m_nMapTwinkleStep = 0;
		m_pOutPostMapImg->SetColor(m_pOutPostMapImg->GetColor() | 0xff000000);
		m_pStrategyPointMapImg->SetColor(m_pStrategyPointMapImg->GetColor() | 0xff000000);
		m_pMSWarMapImg->SetColor(m_pMSWarMapImg->GetColor() | 0xff000000);

		m_pToolTipShowMap = NULL;
	}
	else
	{
	}	
}

int CINFWorldMap::GetHeight()
{
	// ����� �̹����� ����
	int nHeight = m_arrWorldMapImg[0][0]->GetImgSize().y;
	return (int)(nHeight * WORLD_MAP_RAW_NUM * m_fWorldMapScale);
}

int CINFWorldMap::GetWidth()
{
	// ����� �̹����� �ʺ�
	int nWidth = m_arrWorldMapImg[0][0]->GetImgSize().x;
	return (int)(nWidth * WORLD_MAP_COL_NUM * m_fWorldMapScale);
}

void CINFWorldMap::ChangeWorldMapScale(float oldScale, float newScale)
{
	int oldx = WMAP_CENTER_X - GetWidth() / 2;
	int nowx = m_ptWorldMapPos.x;
	int dx = nowx - oldx;
	
	int oldy = WMAP_CENTER_Y - GetHeight() / 2;
	int nowy = m_ptWorldMapPos.y;
	int dy = nowy - oldy;
	
	m_fWorldMapScale = newScale;
	
	m_ptWorldMapPos.x = WMAP_CENTER_X - GetWidth() / 2 + dx * newScale / oldScale;
	m_ptWorldMapPos.y = WMAP_CENTER_Y - GetHeight() / 2 + dy * newScale / oldScale;
	
	m_pToolTipShowMap = NULL;
}

void CINFWorldMap::CheckWorldMapPosition()
{
	m_ptWorldMapReturnPos = m_ptWorldMapPos;

	if(GetWidth() <= (int)(WMAP_WIDTH - WMAP_MARGIN_LEFT - WMAP_MARGIN_RIGHT))
	{
		m_ptWorldMapReturnPos.x = WMAP_CENTER_X - GetWidth() / 2;
	}
	else
	{
		// ��� ��� ���
		if((int)(WMAP_LEFT + WMAP_MARGIN_LEFT) < m_ptWorldMapPos.x)
		{
			m_ptWorldMapReturnPos.x = WMAP_LEFT + WMAP_MARGIN_LEFT;
		}
		// �·� ��� ���
		else if(m_ptWorldMapPos.x + GetWidth() < (int)(WMAP_RIGHT - WMAP_MARGIN_RIGHT))
		{
			m_ptWorldMapReturnPos.x = WMAP_RIGHT - WMAP_MARGIN_RIGHT - GetWidth();
		}
	}
	
	if(GetHeight() <= (int)(WMAP_HEIGHT - WMAP_MARGIN_TOP - WMAP_MARGIN_BOTTOM))
	{
		m_ptWorldMapReturnPos.y = WMAP_CENTER_Y - GetHeight() / 2;
	}
	else
	{
		// �Ʒ��� ��� ���
		if((int)(WMAP_TOP + WMAP_MARGIN_TOP) < m_ptWorldMapPos.y)
		{
			m_ptWorldMapReturnPos.y = WMAP_TOP + WMAP_MARGIN_TOP;
		}
		// ���� ��� ���
		else if(m_ptWorldMapPos.y + GetHeight() < (int)(WMAP_BOTTOM - WMAP_MARGIN_BOTTOM))
		{
			m_ptWorldMapReturnPos.y = WMAP_BOTTOM - WMAP_MARGIN_BOTTOM - GetHeight();
		}
	}

	// ����̵� 
	// m_ptWorldMapPos = m_ptWorldMapReturnPos;
}

void CINFWorldMap::RenderWorldMap()
{
	int nWidth = GetWidth() / WORLD_MAP_COL_NUM;
	int nHeight = GetHeight() / WORLD_MAP_RAW_NUM;
	int x, y;

	for(int i = 0 ; i < WORLD_MAP_RAW_NUM ; ++i)
	{
		for(int j = 0 ; j < WORLD_MAP_COL_NUM ; ++j)
		{
			x = m_ptWorldMapPos.x + nWidth * j;
			y = m_ptWorldMapPos.y + nHeight * i;
			RenderImage(m_arrWorldMapImg[i][j], x, y, nWidth, nHeight, m_fWorldMapScale);
		}
	}
	
	RenderLineHighlight();
	
	D3DCOLOR argb = m_pStrategyPointMapImg->GetColor();
	if(m_nMapTwinkleStep < 20)
	{
		if(0x00000000 < (argb & 0xff000000))
		{
			argb -= 0x05000000;
		}
		else
		{
			++m_nMapTwinkleStep;
		}
	}
	else
	{
		if((argb & 0xff000000) < 0xff000000)
		{
			argb += 0x05000000;
		}
		else
		{
			m_nMapTwinkleStep = (m_nMapTwinkleStep + 1) % 60;
		}
	}
	m_nCurrentMapTwinkleStep = (m_nCurrentMapTwinkleStep + 1) % 90;

	for(vector<WorldMap_MapInfo>::iterator it = m_vecMapInfo.begin() ; it != m_vecMapInfo.end() ; ++it)
	{
		// ������ ��
		if(g_pGameMain->FindMotherShipMapIdx(it->mapInfo->MapIndex, TRUE) || g_pGameMain->FindBaseWarMapIdx(it->mapInfo->MapIndex, TRUE))
		{
			nWidth = m_pStrategyPointMapImg->GetImgSize().x * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			nHeight = m_pStrategyPointMapImg->GetImgSize().y * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale - nWidth / 2;
			y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale - nHeight / 2;
			m_pStrategyPointMapImg->SetColor(argb);
			RenderImage(m_pStrategyPointMapImg, x, y, nWidth, nHeight, sqrtf(WMAPSCALE_L * m_fWorldMapScale));
		}
		
		// ���������� ��
		if(g_pGameMain->m_pOutPost->FindOutPost(it->mapInfo->MapIndex))
		{
			nWidth = m_pOutPostMapImg->GetImgSize().x * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			nHeight = m_pOutPostMapImg->GetImgSize().y * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale - nWidth / 2;
			y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale - nHeight / 2;
			m_pOutPostMapImg->SetColor(argb);
			RenderImage(m_pOutPostMapImg, x, y, nWidth, nHeight, sqrtf(WMAPSCALE_L * m_fWorldMapScale));
		}

		// ���� ��
		if(g_pGameMain->GetSummonMotherShipCnt() || g_pD3dApp->IsWarMotherShip())
		{
			if((g_pGameMain->GetMotherShipInfl(MOTHERSHIP_INFLUENCE_ANI) && 3018 == it->mapInfo->MapIndex /*���̳��� �غ�*/) 
				|| (g_pGameMain->GetMotherShipInfl(MOTHERSHIP_INFLUENCE_VCN) && 3003 == it->mapInfo->MapIndex /*Ÿ�Ϸ�Ʈ ����*/))
			{
				nWidth = m_pMSWarMapImg->GetImgSize().x * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
				nHeight = m_pMSWarMapImg->GetImgSize().y * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
				x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale - nWidth / 2;
				y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale - nHeight / 2;
				m_pMSWarMapImg->SetColor(argb);
				RenderImage(m_pMSWarMapImg, x, y, nWidth, nHeight, sqrtf(WMAPSCALE_L * m_fWorldMapScale));
			}
		}
		
		// �̵� �Ұ� ��
		CQuest* pQuest = g_pQuestData->FindQuest(it->mapInfo->QuestIndexForWarp);
		if(pQuest)
		{
			if(COMPARE_INFLUENCE(pQuest->ReqInfluenceType, g_pShuttleChild->m_myShuttleInfo.GetInfluenceMask())
				&& FALSE == g_pQuestData->IsQuestCompleted(it->mapInfo->QuestIndexForWarp))
			{
				nWidth = m_pCannotMoveMapImg->GetImgSize().x * m_fWorldMapScale;
				nHeight = m_pCannotMoveMapImg->GetImgSize().y * m_fWorldMapScale;
				x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale - nWidth / 2;
				y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale - nHeight / 2;
				RenderImage(m_pCannotMoveMapImg, x, y, nWidth, nHeight, m_fWorldMapScale);
			}
		}

		// ������ ���� ��
		if(it->mapInfo->MapIndex == g_pShuttleChild->m_myShuttleInfo.MapChannelIndex.MapIndex)
		{
			nWidth = m_pCurrentMapImg->GetImgSize().x * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			nHeight = m_pCurrentMapImg->GetImgSize().y * sqrtf(WMAPSCALE_L * m_fWorldMapScale);
			x = m_ptWorldMapPos.x + it->ptMapPos.x * m_fWorldMapScale - nWidth / 2;
			y = m_ptWorldMapPos.y + it->ptMapPos.y * m_fWorldMapScale - nHeight / 2;
			if(3060 == it->mapInfo->MapIndex)
			{
				// ȣ�Ͼ� ŷ ������ ���º�
				if(g_pShuttleChild->m_myShuttleInfo.GetInfluenceMask() == (BYTE)(INFLUENCE_TYPE_NORMAL|INFLUENCE_TYPE_VCN))
				{
					// BCU
					x = m_ptWorldMapPos.x + (1427 + WMAP_FIELD_IMG_SIZE / 2) * m_fWorldMapScale - nWidth / 2;
					y = m_ptWorldMapPos.y + (572 + WMAP_FIELD_IMG_SIZE / 2) * m_fWorldMapScale - nHeight / 2;
				}
				else
				{
					// ANI
					x = m_ptWorldMapPos.x + (1427 + WMAP_FIELD_IMG_SIZE / 2) * m_fWorldMapScale - nWidth / 2;
					y = m_ptWorldMapPos.y + (1949 + WMAP_FIELD_IMG_SIZE / 2) * m_fWorldMapScale - nHeight / 2;
				}
			}
			if(m_nCurrentMapTwinkleStep < 45)
			{
				RenderImage(m_pCurrentMapImg, x, y, nWidth, nHeight, sqrtf(WMAPSCALE_L * m_fWorldMapScale));
			}
		}
	}
}

void CINFWorldMap::RenderLineHighlight()
{
	if(m_pToolTipShowMap)
	{
		if(IS_MAP_INFLUENCE_ANI(m_pToolTipShowMap->mapInfo->MapInfluenceType)
			|| (3060 == m_pToolTipShowMap->mapInfo->MapIndex							// ȣ�Ͼ� ŷ ������
				&& 1949 + WMAP_FIELD_IMG_SIZE / 2 == m_pToolTipShowMap->ptMapPos.y))
		{
			// ANI
			int x = m_ptWorldMapPos.x + WMAP_LINE_ANI_X * m_fWorldMapScale;
			int y = m_ptWorldMapPos.y + WMAP_LINE_ANI_Y * m_fWorldMapScale;
			int nWidth = m_pLineHighlightANIImg->GetImgSize().x;
			int nHeight = m_pLineHighlightANIImg->GetImgSize().y;
			RenderImage(m_pLineHighlightANIImg, x, y, nWidth, nHeight, m_fWorldMapScale);
		}
		else if(IS_MAP_INFLUENCE_VCN(m_pToolTipShowMap->mapInfo->MapInfluenceType)
				|| (3060 == m_pToolTipShowMap->mapInfo->MapIndex						// ȣ�Ͼ� ŷ ������
					&& 572 + WMAP_FIELD_IMG_SIZE / 2 == m_pToolTipShowMap->ptMapPos.y))
		{
			// BCU
			int x = m_ptWorldMapPos.x + WMAP_LINE_BCU_X * m_fWorldMapScale;
			int y = m_ptWorldMapPos.y + WMAP_LINE_BCU_Y * m_fWorldMapScale;
			int nWidth = m_pLineHighlightBCUImg->GetImgSize().x;
			int nHeight = m_pLineHighlightBCUImg->GetImgSize().y;
			RenderImage(m_pLineHighlightBCUImg, x, y, nWidth, nHeight, m_fWorldMapScale);
		}
		else
		{
			// Neutral
			int x = m_ptWorldMapPos.x + WMAP_LINE_NEUTRAL_X * m_fWorldMapScale;
			int y = m_ptWorldMapPos.y + WMAP_LINE_NEUTRAL_Y * m_fWorldMapScale;
			int nWidth = m_pLineHighlightNeutralImg->GetImgSize().x;
			int nHeight = m_pLineHighlightNeutralImg->GetImgSize().y;
			RenderImage(m_pLineHighlightNeutralImg, x, y, nWidth, nHeight, m_fWorldMapScale);
		}
	}
}

void CINFWorldMap::RenderImage(CINFImageEx* image, int x, int y, int nWidth, int nHeight, float fScale)
{
	if(image)
	{
		int rleft = 0, rtop = 0, rright = nWidth, rbottom = nHeight;
		// ��� ��� ���
		if((int)(WMAP_RIGHT - WMAP_MARGIN_RIGHT) < x + nWidth)
		{
			rright -= x + nWidth - (WMAP_RIGHT - WMAP_MARGIN_RIGHT);
			rright = max(0, rright);
		}
		// �·� ��� ���
		if(x < (int)(WMAP_LEFT + WMAP_MARGIN_LEFT))
		{
			rleft += (WMAP_LEFT + WMAP_MARGIN_LEFT) - x;
			rleft = min(nWidth, rleft);
		}
		// �Ʒ��� ��� ���
		if((int)(WMAP_BOTTOM - WMAP_MARGIN_BOTTOM) < y + nHeight)
		{
			rbottom -= y + nHeight - (WMAP_BOTTOM - WMAP_MARGIN_BOTTOM);
			rbottom = max(0, rbottom);
		}
		// ���� ��� ���
		if(y < (int)(WMAP_TOP + WMAP_MARGIN_TOP))
		{
			rtop += (WMAP_TOP + WMAP_MARGIN_TOP) - y;
			rtop = min(nHeight, rtop);
		}
		image->SetRect(rleft / fScale,
					   rtop / fScale,
					   rright / fScale,
					   rbottom / fScale);
		image->SetScale(fScale, fScale);
		image->Move(x + rleft, y + rtop);
		image->Render();
	}
}

void CINFWorldMap::RenderToolTip()
{
	CheckToolTipPosition();
	if(m_pToolTipShowMap)
	{
		int x = 0, y = 0;
		// ���
		if(m_pToolTipBackImg)
		{
			x = m_ptToolTipPos.x;
			y = m_ptToolTipPos.y;
			m_pToolTipBackImg->Move(x, y);
			m_pToolTipBackImg->Render();
		}
		// �� �̸�
		if(m_pToolTipMapNameFont)
		{
			char mapName[100];
			if(COMPARE_RACE(g_pShuttleChild->GetMyShuttleInfo().Race, RACE_OPERATION|RACE_GAMEMASTER))
			{
				wsprintf(mapName, "%s (%d)", m_pToolTipShowMap->mapInfo->MapName, m_pToolTipShowMap->mapInfo->MapIndex);
			}
			else
			{
				wsprintf(mapName, "%s", m_pToolTipShowMap->mapInfo->MapName);
			}
			SIZE size = m_pToolTipMapNameFont->GetStringSize(mapName);
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_NAME_X - size.cx / 2;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_NAME_Y - size.cy / 2;
			m_pToolTipMapNameFont->DrawText(x, y, GUI_FONT_COLOR_W, mapName);
		}
		// �� �̹���
		if(m_pToolTipShowMap->pToolTipImg)
		{
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_IMG_X - m_pToolTipShowMap->pToolTipImg->GetImgSize().x / 2;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_IMG_Y - m_pToolTipShowMap->pToolTipImg->GetImgSize().y / 2;
			m_pToolTipShowMap->pToolTipImg->Move(x, y);
			m_pToolTipShowMap->pToolTipImg->Render();
		}
		// ������ ǥ��
		if(g_pGameMain->FindBaseWarMapIdx(m_pToolTipShowMap->mapInfo->MapIndex))
		{
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_BASE_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_BASE_Y;
			if(g_pGameMain->FindMotherShipMapIdx(m_pToolTipShowMap->mapInfo->MapIndex, TRUE)
				|| g_pGameMain->FindBaseWarMapIdx(m_pToolTipShowMap->mapInfo->MapIndex, TRUE))
			{
				// ���� ��
				if(m_pToolTipBaseWarImg)
				{
					m_pToolTipBaseWarImg->Move(x, y);
					m_pToolTipBaseWarImg->Render();
				}
			}
			else
			{
				if(m_pToolTipBaseEnImg)
				{
					m_pToolTipBaseEnImg->Move(x, y);
					m_pToolTipBaseEnImg->Render();
				}
			}
		}
		// ��������� ǥ��
		if(IS_MAP_INFLUENCE_OUTPOST(m_pToolTipShowMap->mapInfo->MapInfluenceType))
		{
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_OUTPOST_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_OUTPOST_Y;
			if(g_pGameMain->m_pOutPost->FindOutPost(m_pToolTipShowMap->mapInfo->MapIndex))
			{
				// ���� ��
				if(m_pToolTipOutPostWarImg)
				{
					m_pToolTipOutPostWarImg->Move(x, y);
					m_pToolTipOutPostWarImg->Render();
				}
			}
			else
			{
				if(m_pToolTipOutPostEnImg)
				{
					m_pToolTipOutPostEnImg->Move(x, y);
					m_pToolTipOutPostEnImg->Render();
				}
			}
		}
		// ���� ǥ��
		if(3018 == m_pToolTipShowMap->mapInfo->MapIndex || 3003 == m_pToolTipShowMap->mapInfo->MapIndex)
		{
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_MSWAR_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_MSWAR_Y;
			if((g_pGameMain->GetMotherShipInfl(MOTHERSHIP_INFLUENCE_ANI) && 3018 == m_pToolTipShowMap->mapInfo->MapIndex /*���̳��� �غ�*/) 
 				|| (g_pGameMain->GetMotherShipInfl(MOTHERSHIP_INFLUENCE_VCN) && 3003 == m_pToolTipShowMap->mapInfo->MapIndex /*Ÿ�Ϸ�Ʈ ����*/))
			{
				// ���� ��
				if(m_pToolTipMSWarWarImg)
				{
					m_pToolTipMSWarWarImg->Move(x, y);
					m_pToolTipMSWarWarImg->Render();
				}
			}
			else
			{
				if(m_pToolTipMSWarEnImg)
				{
					m_pToolTipMSWarEnImg->Move(x, y);
					m_pToolTipMSWarEnImg->Render();
				}
			}
		}
		// ���� ���� ǥ��
		if(((m_pToolTipShowMap->dwCityWarp & WMAP_TOOLTIP_WARP_BCU) && IS_VCN_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
			|| ((m_pToolTipShowMap->dwCityWarp & WMAP_TOOLTIP_WARP_ANI) && IS_ANI_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType)))
		{
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_WARP_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_WARP_Y;
			if(m_pToolTipWarpEnImg)
			{
				m_pToolTipWarpEnImg->Move(x, y);
				m_pToolTipWarpEnImg->Render();
			}
		}
		// ���� ���� ǥ��
		if(IS_MAP_INFLUENCE_ANI(m_pToolTipShowMap->mapInfo->MapInfluenceType))
		{
			// ANI
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_INFL_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_INFL_Y;
			if(m_pToolTipANIImg)
			{
				m_pToolTipANIImg->Move(x, y);
				m_pToolTipANIImg->Render();
			}
		}
		else if(IS_MAP_INFLUENCE_VCN(m_pToolTipShowMap->mapInfo->MapInfluenceType))
		{
			// BCU
			x = m_ptToolTipPos.x + WMAP_TOOLTIP_INFL_X;
			y = m_ptToolTipPos.y + WMAP_TOOLTIP_INFL_Y;
			if(m_pToolTipBCUImg)
			{
				m_pToolTipBCUImg->Move(x, y);
				m_pToolTipBCUImg->Render();
			}
		}
	}
}

void CINFWorldMap::CheckToolTipPosition()
{
	if(m_pToolTipBackImg)
	{
		// ��� ��� ���
		if(WMAP_RIGHT - WMAP_MARGIN_RIGHT < m_ptToolTipPos.x + m_pToolTipBackImg->GetImgSize().x)
		{
			m_ptToolTipPos.x -= m_pToolTipBackImg->GetImgSize().x;
		}
		// �Ʒ��� ��� ���
		if(WMAP_BOTTOM - WMAP_MARGIN_BOTTOM < m_ptToolTipPos.y + m_pToolTipBackImg->GetImgSize().y)
		{
			m_ptToolTipPos.y -= m_pToolTipBackImg->GetImgSize().y;
		}
	}
}

void CINFWorldMap::LoadMapInfo()
{
	InitMapInfo(2001, 1221, 141);								// ���������� ��Ƽ
	InitMapInfo(3002, 1246, 346);								// ������ ����
	InitMapInfo(3003, 1246, 526, WMAP_TOOLTIP_WARP_BCU);				// Ÿ�Ϸ�Ʈ ����
		InitMapInfo(3060, 1427, 572);							// ȣ�Ͼ� ŷ ������
	InitMapInfo(3067, 1246, 616, WMAP_TOOLTIP_WARP_BCU);				// ���� ���
	InitMapInfo(3004, 1246, 706, WMAP_TOOLTIP_WARP_BCU);				// ���� ����Ʈ
	InitMapInfo(3005, 1246, 796);								// ���̷����� �غ�
	InitMapInfo(3006, 1246, 886, WMAP_TOOLTIP_WARP_BCU);				// ��Ÿ����Ʈ ���
		InitMapInfo(3064, 1427, 933, WMAP_TOOLTIP_WARP_BCU);			// ��ū ��Ƽ
	InitMapInfo(3063, 1246, 976, WMAP_TOOLTIP_WARP_BCU);				// ������� ��ġ
	InitMapInfo(3068, 1246, 1066);								// ���������Ʈ B
	InitMapInfo(3008, 1246, 1247);								// ��ũ��Ƽ
//		InitMapInfo(4002, 1074, 1137);							// ��ũ �����Ƽ(BCU)
//		InitMapInfo(4003, 1074, 1137);							// ��ũ �����Ƽ(ANI)
		InitMapInfo(6016, 1337, 1247);							// ��ũ��Ƽ ���
		InitMapInfo(2004, 1517, 1247, WMAP_TOOLTIP_WARP_BOTH);	// ��ũ��
	InitMapInfo(3069, 1246, 1428);								// ���������Ʈ A
	InitMapInfo(3007, 1246, 1518, WMAP_TOOLTIP_WARP_ANI);			// �������� ������
	InitMapInfo(3009, 1246, 1608, WMAP_TOOLTIP_WARP_ANI);			// ����� ���
	InitMapInfo(4006, 1246, 1698, WMAP_TOOLTIP_WARP_ANI);			// ũ����Ż ���̺�
	InitMapInfo(3013, 1246, 1788, WMAP_TOOLTIP_WARP_ANI);			// ������ �縷
		InitMapInfo(3016, 1066, 1718, WMAP_TOOLTIP_WARP_ANI);		// ���̿÷��� ���ڵ�
	InitMapInfo(3014, 1246, 1878, WMAP_TOOLTIP_WARP_ANI);			// �����Ʈ ���
		InitMapInfo(3060, 1427, 1949);							// ȣ�Ͼ� ŷ ������
	InitMapInfo(3018, 1246, 1968);								// ���̳��� �غ�
	InitMapInfo(2002, 1221, 2121);								// �˸��� ��Ƽ
	
	InitMapInfo(3029, 706, 616, WMAP_TOOLTIP_WARP_BCU);				// ���� �غ�
	InitMapInfo(4010, 706, 729, WMAP_TOOLTIP_WARP_BCU);				// ���ٸ�ũ ���̺�
	InitMapInfo(3028, 706, 842, WMAP_TOOLTIP_WARP_BCU);				// ������ �ݵ�
	InitMapInfo(3025, 706, 955, WMAP_TOOLTIP_WARP_BCU);				// ������ �����
	InitMapInfo(3024, 706, 1066);								// �ǵ��� ����Ʈ B
	InitMapInfo(3023, 706, 1247);								// �� ���� ��
		InitMapInfo(6018, 886, 1247);							// �ڷγ���
		InitMapInfo(2006, 1066, 1247, WMAP_TOOLTIP_WARP_BOTH);	// ĳ�� �ڷγ���
	InitMapInfo(3021, 706, 1428);								// �ǵ��� ����Ʈ A
	InitMapInfo(3022, 706, 1541, WMAP_TOOLTIP_WARP_ANI);				// �����ӽ� ����
	InitMapInfo(3045, 706, 1653, WMAP_TOOLTIP_WARP_ANI);				// ������ ��Ʈ
	InitMapInfo(3015, 706, 1765, WMAP_TOOLTIP_WARP_ANI);				// ����Ʈ �ε�
	InitMapInfo(3031, 706, 1878, WMAP_TOOLTIP_WARP_ANI);				// ������ �غ�

	InitMapInfo(3042, 526, 1247);								// �跱����
	InitMapInfo(3041, 346, 1247);								// �κ��Ͼ� ��Ƽ
		InitMapInfo(3043, 346, 1337);							// ��Ż���� ������
	InitMapInfo(3044, 166, 1247);								// �κ��Ͼ� ��Ƽ ���
	InitMapInfo(3086, 166, 1066);								// J-Ark �ݳ���
	InitMapInfo(3087, 166, 976);								// J-Ark ������
	
	InitMapInfo(3019, 1606, 976);								// ���� ���� ����(BCU)
	InitMapInfo(6007, 1606, 1066);								// ���� ���� ����(BCU)
	InitMapInfo(6009, 1606, 1247);								// ���� ���� ����
		InitMapInfo(6017, 1786, 1247);							// �޼ҽ� �÷ξ�
		InitMapInfo(2005, 1786, 1337, WMAP_TOOLTIP_WARP_BOTH);	// ��Ű��
	InitMapInfo(6008, 1606, 1428);								// ���� ���� ����(ANI)
	InitMapInfo(3020, 1606, 1518);								// ���� ���� ����(ANI)

	InitMapInfo(3034, 1966, 886, WMAP_TOOLTIP_WARP_ANI);				// ���̽����� �帲
	InitMapInfo(6001, 1966, 976);								// ī����
	InitMapInfo(6002, 1966, 1066);								// ������ ȸ��
	InitMapInfo(4007, 1966, 1156);								// G-Ark ������
	InitMapInfo(6003, 1966, 1247);								// ��Ÿ�� �÷ξ�
	InitMapInfo(3017, 1966, 1337);								// ����� ȭ��
	InitMapInfo(6004, 1966, 1428);								// G-Ark
	InitMapInfo(6005, 1966, 1518);								// Atum-1
	InitMapInfo(6006, 1966, 1608);								// Atum-2

	InitMapInfo(4100, 2326, 1337, WMAP_TOOLTIP_WARP_BOTH);		// �ֽ�����
	InitMapInfo(4101, 2326, 1427);								// �÷��� ����ũ
	InitMapInfo(4300, 2326, 1517, WMAP_TOOLTIP_WARP_BOTH);		// �ν�Ʈ ���ƽý�
	InitMapInfo(4301, 2326, 1607);								// NGC �ؾ� ������
	InitMapInfo(4302, 2326, 1697);								// NGC ��б���
		InitMapInfo(4303, 2181, 1697);							// NGC ���� ��������
		InitMapInfo(2007, 2036, 1697, WMAP_TOOLTIP_WARP_BOTH);	// �ҵ�
	InitMapInfo(4304, 2326, 1787);								// ������ ������
	InitMapInfo(4305, 2326, 1877);								// ���̿÷� ���̺�
	InitMapInfo(4306, 2326, 1965);								// �̸��� ä����
	InitMapInfo(4307, 2326, 2055);								// ������ �뵵��

	InitMapInfo(7002, 2025, 2147);								// ���׺���
	InitMapInfo(7004, 2687, 2147);								// ���ĸ���
	InitMapInfo(7005, 2687, 1247);								// �Ƹ�����
		InitMapInfo(7006, 2867, 1247);							// �丣ī��
		InitMapInfo(7007, 2867, 1337);							// ������
	InitMapInfo(7003, 2687, 166);								// ���󸮽�
	InitMapInfo(7001, 2025, 166, WMAP_TOOLTIP_WARP_BCU);				// ī��Ʈ��
}

void CINFWorldMap::InitMapInfo(MapIndex_t mapIdx, LONG x, LONG y, DWORD cityWarp)
{
	if(2001 == mapIdx || 2002 == mapIdx)
	{
		x += WMAP_CITY_IMG_SIZE / 2;
		y += WMAP_CITY_IMG_SIZE / 2;
	}
	else
	{
		x += WMAP_FIELD_IMG_SIZE / 2;
		y += WMAP_FIELD_IMG_SIZE / 2;
	}
	WorldMap_MapInfo newMapInfo;
	newMapInfo.ptMapPos.x = x;
	newMapInfo.ptMapPos.y = y;
	newMapInfo.pToolTipImg = new CINFImageEx;

	char cMapName[100] = {0, };
	wsprintf(cMapName, "%d", mapIdx);	
	DataHeader* pDataHeader = FindWorldMapImgResource(cMapName);
	if(pDataHeader)
	{
		newMapInfo.pToolTipImg->InitDeviceObjects(pDataHeader);
	}
	
	newMapInfo.mapInfo = g_pDatabase->GetMapInfo(mapIdx);
	newMapInfo.dwCityWarp = cityWarp;

	m_vecMapInfo.push_back(newMapInfo);
}

DataHeader* CINFWorldMap::FindWorldMapImgResource(char* szRcName)
{
	FLOG("CINFBase::FindResource(char* szRcName)");
	DataHeader* pHeader = NULL;
	if(m_pMapImgData)
	{
		pHeader = m_pMapImgData->Find(szRcName);
#ifdef _DEBUG
		if(!pHeader)
		{
			DBGOUT("INFBase::FindResource(%s) Can't Find Resource File.\n", szRcName);
		}
#endif // _DEBUG_endif
	}
	return pHeader;
}