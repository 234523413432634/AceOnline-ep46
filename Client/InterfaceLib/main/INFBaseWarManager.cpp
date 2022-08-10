// INFBaseWarManager.cpp: implementation of the CINFBaseWarManager class.
//
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		
/// \author		// 2013-08-23 by ssjung 거점전 리뉴얼
/// \date		2013-08-19~ 2013-08-23
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "AtumApplication.h"
#include "INFImage.h"
#include "GameDataLast.h"
#include "D3DHanFont.h"
#include "INFGameMain.h"

#include "ShuttleChild.h"
#include "Chat.h"
#include "StoreData.h"// 2008-08-19 by bhsohn 세력 마크 시스템 추가
#include "INFWindow.h"
#include "INFImageEx.h"
#include "INFGroupImage.h"
#include "INFGroupManager.h"											// 2011. 10. 10 by jskim UI시스템 변경
#include "INFToolTip.h"			// 2011. 1. 12 by jskim UI 이미지 버튼 툴팁 구현
#include "Interface.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "INFBaseWarManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI시스템 변경
#define BASEWAR_IMPORTANT_GAP			53
#define BASEWAR_BUTTON_IMPORTANT_GAP		20

// 2014-02-05 by ssjung 거점전 관련 UI 위치 수정
#define GAMEMAIN_BASEWAR_START_X							179
#define GAMEMAIN_BASEWAR_INTERFACE_SIZE_X					70
// end 2014-02-05 by ssjung 거점전 관련 UI 위치 수정

#define GAMEMAIN_BASEWAR_INFLUENCE1_START_X					187
#define GAMEMAIN_BASEWAR_INFLUENCE1_START_Y					45//22

#define GAMEMAIN_BASEWAR_INFLUENCE2_START_X					187
#define GAMEMAIN_BASEWAR_INFLUENCE2_START_Y					100//77

#define GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X		185
#define GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_Y		(GAMEMAIN_BASEWAR_INFLUENCE1_START_Y + 3)//25
// #define GAMEMAIN_MOTHERSHIP_INFLUENCE1_TIME_START_X				185
#define GAMEMAIN_BASEWAR_INFLUENCE1_TIME_START_Y				(GAMEMAIN_BASEWAR_INFLUENCE1_START_Y + 18)//40
// #define GAMEMAIN_MOTHERSHIP_INFLUENCE1_AREA_START_X				185
 #define GAMEMAIN_BASEWAR_INFLUENCE1_AREA_START_Y				(GAMEMAIN_BASEWAR_INFLUENCE1_START_Y + 33)//55

#define GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_X		185
#define GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_Y		(GAMEMAIN_BASEWAR_INFLUENCE2_START_Y + 3)//80
// #define GAMEMAIN_MOTHERSHIP_INFLUENCE2_TIME_START_X				185
#define GAMEMAIN_BASEWAR_INFLUENCE2_TIME_START_Y				(GAMEMAIN_BASEWAR_INFLUENCE2_START_Y + 18)//95
// #define GAMEMAIN_MOTHERSHIP_INFLUENCE2_AREA_START_X				185
#define GAMEMAIN_BASEWAR_INFLUENCE2_AREA_START_Y				(GAMEMAIN_BASEWAR_INFLUENCE2_START_Y + 33)//110

#define GAMEMAIN_BASEWAR_INFLUENCE_WIDTH						145
#define GAMEMAIN_BASEWAR_INFLUENCE_EACH_HEIGHT				15		// 각각의 글씨 높이 
#define GAMEMAIN_BASEWAR_INFLUENCE_CAP_HEIGHT				10		// 진행 표시시 여백 

//테두리
#define ID_BASEWAR_BALON_TLH				6
#define ID_BASEWAR_BALON_TLW				8
#define ID_BASEWAR_BALON_TMH				6
#define ID_BASEWAR_BALON_TMW				1
#define ID_BASEWAR_BALON_TRH				6
#define ID_BASEWAR_BALON_TRW				6

#define ID_BASEWAR_BALON_MLH				1
#define ID_BASEWAR_BALON_MLW				8
#define ID_BASEWAR_BALON_MMH				1
#define ID_BASEWAR_BALON_MMW				1
#define ID_BASEWAR_BALON_MRH				1
#define ID_BASEWAR_BALON_MRW				6

#define ID_BASEWAR_BALON_BLH				6
#define ID_BASEWAR_BALON_BLW				8
#define ID_BASEWAR_BALON_BMH				6
#define ID_BASEWAR_BALON_BMW				1
#define ID_BASEWAR_BALON_BRH				6
#define ID_BASEWAR_BALON_BRW				6

#define MAP_IMAGE_SIZE_X					47
#define MAP_IMAGE_SIZE_Y					52

#define NGC_BASEWAR_IMG_RESET_BAR_Y				150
#define NGC_BASEWAR_IMG_RESET_BAR_BAR_X			9
#define NGC_BASEWAR_IMG_RESET_BAR_BAR_Y			33
#define NGC_BASEWAR_IMG_RESET_BAR_ATTACK_X		7
#define NGC_BASEWAR_IMG_RESET_BAR_ATTACK_Y		15
#define NGC_BASEWAR_IMG_RESET_BAR_DEFEN_X		241
#define NGC_BASEWAR_IMG_RESET_BAR_DEFEN_Y		15

struct stSTRONGHOLD_INFO{
	DWORD			nIndex;
	DWORD			MapIndex;
};

CINFBaseWarManager::CINFBaseWarManager()
{

}

CINFBaseWarManager::~CINFBaseWarManager()
{
	vecINFImportantInfoIter it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		SAFE_DELETE((*it));
		it = m_vecImportBCU.erase(it);
	}
	it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		SAFE_DELETE((*it));
		it = m_vecImportANI.erase(it);
	}
	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		SAFE_DELETE((*it));
		it = m_vecImportNGC.erase(it);
	}


	{
		vecINFImportantInfoIter it;
		it = m_vecImportStateANI.begin();
		while(it != m_vecImportStateANI.end())
		{
			it = m_vecImportStateANI.erase(it);
		}
		it = m_vecImportStateBCU.begin();
		while(it != m_vecImportStateBCU.end())
		{
			it = m_vecImportStateBCU.erase(it);
		}
		it = m_vecImportStateNGC.begin();
		while(it != m_vecImportStateNGC.end())
		{
			it = m_vecImportStateNGC.erase(it);
		}
	}


	// 2007-02-06 by bhsohn 모선전 진행 사항 체크
	int i =0;
	// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(i = 0 ; i < BASEWAR_MAXLINE ; ++i)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			SAFE_DELETE(m_pFontBaseInfo[i][j]);
		}
	}
#else
 	for(i=0;i<BASEWAR_MAXLINE;i++)
 	{
 		SAFE_DELETE(m_pFontBaseInfo[i]);
 	}
#endif
	// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
	for(i=0; i<BASEWAR_INFO_BALON; i++)
	{
		SAFE_DELETE(m_pBalonChat[i]);
	}
	// end 2007-02-06 by bhsohn 모선전 진행 사항 체크

	for(i = 0; i<2; ++i)
	{
		SAFE_DELETE(m_pFontPToolTip[i]);
	}
	
	if(m_pColonImage)
		SAFE_DELETE(m_pColonImage);

	if(m_pImgResetBarBack)
		SAFE_DELETE(m_pImgResetBarBack);

	if(m_pImgResetBarBar1)
		SAFE_DELETE(m_pImgResetBarBar1);

	if(m_pImgResetBarBar2)
		SAFE_DELETE(m_pImgResetBarBar2);

	if(m_pImgResetBarInf1)	
		SAFE_DELETE(m_pImgResetBarInf1);
	
	if(m_pImgResetBarInf2)
		SAFE_DELETE(m_pImgResetBarInf2);

	
}

CINFBaseWarManager::CINFBaseWarManager(CGameData * pData)
{
	m_pGameData				= pData;
	
	m_nShowNum1				= 0;
	m_nShowNum0				= 0;
	
	
	m_fShowTime				= 0.0f;
	
	m_nButtonState1			= BUTTON_STATE_NORMAL;
	m_nButtonState0			= BUTTON_STATE_NORMAL;
	m_nButtonState2			= BUTTON_STATE_NORMAL;
	
	m_bShow1				= TRUE;
	m_bShow0				= TRUE;
	m_bShow2				= TRUE;
	
	m_nButtonPosX1			= 0;
	m_nButtonPosY1			= 0;
	m_nButtonPosX0			= 0;
	m_nButtonPosY0			= 0;
	m_nButtonPosX2			= 0;
	m_nButtonPosY2			= 0;

	m_pImgBaseWarBCUButton		= NULL;
	m_pImgBaseWarANIButton		= NULL;
	m_pImgBaseWarNGCButton		= NULL;
	
	m_nInfluenceState			= 0;

	m_bShowToolTip			= FALSE;

	strcpy(m_sInfluence[0], STRMSG_C_060210_0001);
	strcpy(m_sInfluence[1], STRMSG_C_060210_0000);

	m_strShowToolTipInfo = NULL;

	m_pColonImage = NULL;

	int i = 0;
	for( i=0; i<10; ++i )
		m_pTimeNumImage[ i ] = NULL;

	m_bShowTimeImage = FALSE;

	m_bNGCbaseWar = FALSE;

	m_pImgResetBarBack = NULL;
	m_pImgResetBarBar1 = NULL;
	m_pImgResetBarBar2 = NULL;
	m_pImgResetBarInf1 = NULL;
	m_pImgResetBarInf2 = NULL;

	m_fBarScale	= 0.0f;

	m_bBarRender = FALSE;

	m_enumNgcState = NGCSP_START;

	stSTRONGHOLD_INFO  _MAPORDER_BCU[] = 
	{
		{	10,		3067},
		{	20,		3004},
		{	30,		3005},
		{	40,		3006},
		{	50,		3063},		
		{	60,		3029},		// 2008-06-27 by dgwoo 거점 지역 추가.
		{	70,		4010},
		{	80,		3028},
		{	90,		3025}
	};
	
	stSTRONGHOLD_INFO  _MAPORDER_ANI[] = 
	{
		{	10,		3014},
		{	20,		3013},
		{	30,		4006},
		{	40,		3009},
		{	50,		3007},
		{	60,		3031},		// 2008-06-27 by dgwoo 거점 지역 추가.
		{	70,		3015},
		{	80,		3045},
		{   90,     3022}
	};

	stSTRONGHOLD_INFO _MAPORDER_NGC[] =
	{
		{	10,		4101},
		{	20,		4304},
		{	30,		4305},		// 2014-04-03 by ssjung NGC거점 지역 추가.
	};


	DWORD nCount = sizeof(_MAPORDER_BCU)/sizeof(stSTRONGHOLD_INFO);
	for(i = 0 ; i < nCount ; i++)
	{
		// 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		if(g_pGameMain->GetMapInfo(_MAPORDER_BCU[i].MapIndex)->MapIndex == 0)
			continue;
		// end 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		
		
		CINFImportantInfo* pImportInfo = new CINFImportantInfo;
		pImportInfo->SetGameData(pData);
		pImportInfo->SetMapNum(_MAPORDER_BCU[i].MapIndex);
		pImportInfo->m_nWarState = WARSTATE_BASEWAR;
		m_vecImportBCU.push_back(pImportInfo);
		
	}
	nCount = sizeof(_MAPORDER_ANI)/sizeof(stSTRONGHOLD_INFO);
	for(i = 0 ; i < nCount ; i++)
	{
		// 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		if(g_pGameMain->GetMapInfo(_MAPORDER_ANI[i].MapIndex)->MapIndex == 0)
			continue;
		// end 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		
		
		CINFImportantInfo* pImportInfo = new CINFImportantInfo;
		pImportInfo->SetGameData(pData);
		pImportInfo->SetMapNum(_MAPORDER_ANI[i].MapIndex);
		pImportInfo->m_nWarState = WARSTATE_BASEWAR;
		m_vecImportANI.push_back(pImportInfo);
	}

	// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
// 2014-04-30 by ssjung 거점전 맵의 리소스가 없을 경우 생기는 크래쉬 수정
	char buf[64] = {0,};
	DataHeader	* pDataHeader = NULL;
// 2014-04-30 by ssjung 거점전 맵의 리소스가 없을 경우 생기는 크래쉬 수정
	nCount = sizeof(_MAPORDER_NGC)/sizeof(stSTRONGHOLD_INFO);
	for(i = 0 ; i < nCount ; i++)
	{
		// 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		if(g_pGameMain->GetMapInfo(_MAPORDER_NGC[i].MapIndex)->MapIndex == 0)
			continue;
		// end 2009. 01. 12 by ckPark MapInfo 없는 맵은 모선전 정보 안띄우기
		
// 2014-04-30 by ssjung 거점전 맵의 리소스가 없을 경우 생기는 크래쉬 수정
		pDataHeader = NULL;
		wsprintf(buf,"%d%d",_MAPORDER_NGC[i].MapIndex,0);
		pDataHeader = FindResource(buf);
		if(pDataHeader == NULL)	continue;
// 2014-04-30 by ssjung 거점전 맵의 리소스가 없을 경우 생기는 크래쉬 수정
		
		CINFImportantInfo* pImportInfo = new CINFImportantInfo;
		pImportInfo->SetGameData(pData);
		pImportInfo->SetMapNum(_MAPORDER_NGC[i].MapIndex);
		pImportInfo->m_nWarState = WARSTATE_BASEWAR;
		m_vecImportNGC.push_back(pImportInfo);
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

	int nCnt;
	// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	for(nCnt = 0 ; nCnt < BASEWAR_MAXLINE ; ++nCnt)
	{
		for(int j = 0 ; j < 7 ; ++j)
		{
			m_pFontBaseInfo[nCnt][j] = NULL;
		}
	}
#else
 	for(nCnt = 0;nCnt < BASEWAR_MAXLINE;nCnt++)
 	{
 		m_pFontBaseInfo[nCnt]= NULL;
 	}
#endif
	// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
	for(nCnt=0; nCnt<BASEWAR_INFO_BALON; nCnt++)
	{
		m_pBalonChat[nCnt] = NULL;
	}
	for(nCnt=0; nCnt<2; nCnt++)
	{
		m_pFontPToolTip[nCnt] = NULL;
	}

 	SetBaseOption();
}

HRESULT CINFBaseWarManager::InitDeviceObjects()
{

	DataHeader *pDataHeader;
	pDataHeader = FindResource("ngcwar");					//배경 
	m_pImgResetBarBack = new CINFImageEx;
	m_pImgResetBarBack->InitDeviceObjects( pDataHeader );
	
	pDataHeader = FindResource("outpbar1");					//빨간바 
	m_pImgResetBarBar1 = new CINFImageEx;
	m_pImgResetBarBar1->InitDeviceObjects( pDataHeader );
	
	pDataHeader = FindResource("outpbar2");					//파란색바
	m_pImgResetBarBar2 = new CINFImageEx;
	m_pImgResetBarBar2->InitDeviceObjects( pDataHeader );
	
	pDataHeader = FindResource("outpinf1");					//BCU글자
	m_pImgResetBarInf1 = new CINFImageEx;
	m_pImgResetBarInf1->InitDeviceObjects( pDataHeader );
	
	pDataHeader = FindResource("outpinf2");					//ANI글자
	m_pImgResetBarInf2 = new CINFImageEx;
	m_pImgResetBarInf2->InitDeviceObjects( pDataHeader );

	if(NULL == m_pImgBaseWarBCUButton)
	{
		m_pImgBaseWarBCUButton = new CINFImageBtnBoth;
	}
	m_pImgBaseWarBCUButton->InitDeviceObjects("infoMB");
	m_pImgBaseWarBCUButton->ChangeBoth(m_bShow0);
	if(NULL == m_pImgBaseWarANIButton)
	{
		m_pImgBaseWarANIButton = new CINFImageBtnBoth;
	}
	m_pImgBaseWarANIButton->InitDeviceObjects("infoMB");
	m_pImgBaseWarANIButton->ChangeBoth(m_bShow1);

	if(NULL == m_pImgBaseWarNGCButton)
	{
		m_pImgBaseWarNGCButton = new CINFImageBtnBoth;
	}
	m_pImgBaseWarNGCButton->InitDeviceObjects("infoMB");
	m_pImgBaseWarNGCButton->ChangeBoth(m_bShow2);

	vecINFImportantInfoIter it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		(*it)->InitDeviceObjects();
		it++;
	}
	it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		(*it)->InitDeviceObjects();
		it++;
	}

	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		(*it)->InitDeviceObjects();
		it++;
	}

// 	DataHeader	* pDataHeader;
	{
		// 2007-02-06 by bhsohn 모선전 진행 사항 체크
		int i =0;
		// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		for(i = 0 ; i < BASEWAR_MAXLINE ; ++i)
		{
			for(int j = 0 ; j < 7 ; ++j)
			{
				m_pFontBaseInfo[i][j] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 8, D3DFONT_ZENABLE, TRUE, 256, 32);
				m_pFontBaseInfo[i][j]->InitDeviceObjects(g_pD3dDev);
			}
		}
#else
 		for(i=0;i<BASEWAR_MAXLINE;i++)
 		{		
 			m_pFontBaseInfo[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 8, D3DFONT_ZENABLE, TRUE, 256, 32);
 			m_pFontBaseInfo[i]->InitDeviceObjects(g_pD3dDev) ;
 		}	
#endif
		// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		
		char szImage[16];
		for(i=0; i<BASEWAR_INFO_BALON; i++)
		{		
			memset(szImage, 0x00, 16);		
			wsprintf(szImage,"c_bal%d",i);
			
			m_pBalonChat[i] = new CINFImageEx;
			pDataHeader = FindResource(szImage);
			m_pBalonChat[i]->InitDeviceObjects(pDataHeader ) ;		
		}	
		// end 2007-02-06 by bhsohn 모선전 진행 사항 체크
	}
	int i;
	for(i=0;i<2;i++)
	{		
		m_pFontPToolTip[i] = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 8, D3DFONT_ZENABLE, TRUE, 256, 32);
		m_pFontPToolTip[i]->InitDeviceObjects(g_pD3dDev) ;
	}
	
	char szBuff[ 32 ];
	for( i=0; i<10; ++i )
	{
		sprintf( szBuff, "if_time%d", i );
		DataHeader* pHeader = g_pGameMain->FindResource( szBuff );
		if ( pHeader )
		{
			m_pTimeNumImage[ i ] = new CINFImageEx;
			m_pTimeNumImage[ i ]->InitDeviceObjects( pHeader );
		}	
	}
	
	if( m_pColonImage == NULL )
	{
		DataHeader* pHeader	= g_pGameMain->FindResource( "if_colon" );
		
		if( pHeader )
		{
			m_pColonImage = new CINFImageEx;
			m_pColonImage->InitDeviceObjects( pHeader );
		}
	}
		
	m_strShowToolTipInfo = new ShowToolTipInfo;
	memset(m_strShowToolTipInfo, 0x00, sizeof(ShowToolTipInfo));

	return S_OK;
}
HRESULT CINFBaseWarManager::RestoreDeviceObjects()
{
	m_pImgResetBarBack->RestoreDeviceObjects();
	m_pImgResetBarBar1->RestoreDeviceObjects();
	m_pImgResetBarBar2->RestoreDeviceObjects();
	m_pImgResetBarInf1->RestoreDeviceObjects();
	m_pImgResetBarInf2->RestoreDeviceObjects();

	m_pImgBaseWarBCUButton->RestoreDeviceObjects();	
	m_pImgBaseWarANIButton->RestoreDeviceObjects();	
	m_pImgBaseWarNGCButton->RestoreDeviceObjects();

	vecINFImportantInfoIter it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		(*it)->RestoreDeviceObjects();
		it++;
	}
	it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		(*it)->RestoreDeviceObjects();
		it++;
	}
	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		(*it)->RestoreDeviceObjects();
		it++;
	}

/////////////////////////////////////////////////////////////
	// 2014-04-16 by ymjoo 거점전 UI가 사라지는 버그 수정
// 	{
// 		vecINFImportantInfoIter it;
// 		it = m_vecImportStateANI.begin();
// 		while(it != m_vecImportStateANI.end())
// 		{
// 			it = m_vecImportStateANI.erase(it);
// 		}
// 		it = m_vecImportStateBCU.begin();
// 		while(it != m_vecImportStateBCU.end())
// 		{
// 			it = m_vecImportStateBCU.erase(it);
// 		}
// 		it = m_vecImportStateNGC.begin();
// 		while(it != m_vecImportStateNGC.end())
// 		{
// 			it = m_vecImportStateNGC.erase(it);
// 		}
// 	}
	// END 2014-04-16 by ymjoo 거점전 UI가 사라지는 버그 수정
	{
		// 2007-02-06 by bhsohn 모선전 진행 사항 체크
		int i=0;
		// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		for(i = 0 ; i < BASEWAR_MAXLINE ; ++i)
		{
			for(int j = 0 ; j < 7 ; ++j)
			{
				m_pFontBaseInfo[i][j]->RestoreDeviceObjects();
			}
		}
#else
 		for(i=0;i<BASEWAR_MAXLINE;i++)
 		{
 			m_pFontBaseInfo[i]->RestoreDeviceObjects() ;
 		}
#endif
		// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		for(i=0; i<BASEWAR_INFO_BALON; i++)
		{
			m_pBalonChat[i]->RestoreDeviceObjects();
		}
		// end 2007-02-06 by bhsohn 모선전 진행 사항 체크

		for(i = 0; i<2; ++i)
			m_pFontPToolTip[i]->RestoreDeviceObjects();

		for( i=0; i<10; ++i )
		{
			if( m_pTimeNumImage[ i ] )
				m_pTimeNumImage[ i ]->RestoreDeviceObjects();
	}
	}

	if(m_pColonImage)
		m_pColonImage->RestoreDeviceObjects();
	
	return S_OK;
}
HRESULT CINFBaseWarManager::DeleteDeviceObjects()
{
	m_pImgResetBarBack->DeleteDeviceObjects(); 
	SAFE_DELETE(m_pImgResetBarBack);
	m_pImgResetBarBar1->DeleteDeviceObjects();
	SAFE_DELETE(m_pImgResetBarBar1);
	m_pImgResetBarBar2->DeleteDeviceObjects();
	SAFE_DELETE(m_pImgResetBarBar2);
	m_pImgResetBarInf1->DeleteDeviceObjects();
	SAFE_DELETE(m_pImgResetBarInf1);
	m_pImgResetBarInf2->DeleteDeviceObjects();
	SAFE_DELETE(m_pImgResetBarInf2);

	m_pImgBaseWarBCUButton->DeleteDeviceObjects();	
	SAFE_DELETE(m_pImgBaseWarBCUButton);
	m_pImgBaseWarANIButton->DeleteDeviceObjects();	
	SAFE_DELETE(m_pImgBaseWarANIButton);
	m_pImgBaseWarNGCButton->DeleteDeviceObjects();	
	SAFE_DELETE(m_pImgBaseWarNGCButton);
	
	vecINFImportantInfoIter it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		(*it)->DeleteDeviceObjects();
		SAFE_DELETE((*it));
		it++;
	}
	it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		(*it)->DeleteDeviceObjects();
		SAFE_DELETE((*it));
		it++;
	}

	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		(*it)->DeleteDeviceObjects();
		SAFE_DELETE((*it));
		it++;
	}

	{
		vecINFImportantInfoIter it;
		it = m_vecImportStateANI.begin();
		while(it != m_vecImportStateANI.end())
		{
			it = m_vecImportStateANI.erase(it);
		}
		it = m_vecImportStateBCU.begin();
		while(it != m_vecImportStateBCU.end())
		{
			it = m_vecImportStateBCU.erase(it);
		}
		it = m_vecImportStateNGC.begin();
		while(it != m_vecImportStateNGC.end())
		{
			it = m_vecImportStateNGC.erase(it);
		}
	}
	{
		// 2007-02-06 by bhsohn 모선전 진행 사항 체크
		int i=0;
		// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		for(i = 0 ; i < BASEWAR_MAXLINE ; ++i)
		{
			for(int j = 0 ; j < 7 ; ++j)
			{
				m_pFontBaseInfo[i][j]->DeleteDeviceObjects();
				SAFE_DELETE(m_pFontBaseInfo[i][j]);
			}
		}
#else
 		for(i=0;i<BASEWAR_MAXLINE;i++)
 		{		
 			m_pFontBaseInfo[i]->DeleteDeviceObjects() ;
 			SAFE_DELETE(m_pFontBaseInfo[i]);
 		}
#endif
		// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		for(i=0; i<BASEWAR_INFO_BALON; i++)
		{
			m_pBalonChat[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pBalonChat[i]);
		}
		// end 2007-02-06 by bhsohn 모선전 진행 사항 체크

		for(i = 0; i<2; ++i)
		{
			m_pFontPToolTip[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pFontPToolTip[i]);
		}

		for(  i=0; i<10; ++i )
		{
			if( m_pTimeNumImage[ i ] )
			{
				m_pTimeNumImage[ i ]->DeleteDeviceObjects();
				SAFE_DELETE( m_pTimeNumImage[ i ] );
			}
		}
	}

	if(m_pColonImage)
	{
		m_pColonImage->DeleteDeviceObjects();
		SAFE_DELETE(m_pColonImage);
	}
	
	return S_OK;
}
HRESULT CINFBaseWarManager::InvalidateDeviceObjects()
{
	m_pImgResetBarBack->InvalidateDeviceObjects();
	m_pImgResetBarBar1->InvalidateDeviceObjects();
	m_pImgResetBarBar2->InvalidateDeviceObjects();
	m_pImgResetBarInf1->InvalidateDeviceObjects();
	m_pImgResetBarInf2->InvalidateDeviceObjects();

	m_pImgBaseWarBCUButton->InvalidateDeviceObjects();	
	m_pImgBaseWarANIButton->InvalidateDeviceObjects();	
	m_pImgBaseWarNGCButton->InvalidateDeviceObjects();	

	vecINFImportantInfoIter it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		(*it)->InvalidateDeviceObjects();
		it++;
	}
	it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		(*it)->InvalidateDeviceObjects();
		it++;
	}
	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		(*it)->InvalidateDeviceObjects();
		it++;
	}
	
	{
		// 2007-02-06 by bhsohn 모선전 진행 사항 체크
		int i=0;
		// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		for(i = 0 ; i < BASEWAR_MAXLINE ; ++i)
		{
			for(int j = 0 ; j < 7 ; ++j)
			{
				m_pFontBaseInfo[i][j]->InvalidateDeviceObjects();
			}
		}
#else
 		for(i=0;i<BASEWAR_MAXLINE;i++)
 		{
 			m_pFontBaseInfo[i]->InvalidateDeviceObjects() ;
 		}
#endif
		// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		for(i=0; i<BASEWAR_INFO_BALON; i++)
		{
			m_pBalonChat[i]->InvalidateDeviceObjects();
		}
		// end 2007-02-06 by bhsohn 모선전 진행 사항 체크
		for(i = 0; i<2; i++)
			m_pFontPToolTip[i]->InvalidateDeviceObjects();

		for( i=0; i<10; ++i )
		{
			if( m_pTimeNumImage[ i ] )
				m_pTimeNumImage[ i ]->InvalidateDeviceObjects();
		}
	}

	if(m_pColonImage)
		m_pColonImage->InvalidateDeviceObjects();

	return S_OK;
}

void CINFBaseWarManager::AdventBaseBCU(SMSWARINFO_DISPLAY * pInfo)
{
	vecINFImportantInfoIter it = m_vecImportStateBCU.begin();
	while(it != m_vecImportStateBCU.end())
	{
		if((*it)->m_nMapNum == pInfo->MapIndex)
		{
			(*it)->m_bMapInfluence		= pInfo->MapInfluenceType;
			(*it)->SetState(pInfo->TelePortState,pInfo->HPRate);
			break;
		}
		it++;
	}
}

void CINFBaseWarManager::AdventBaseAHI(SMSWARINFO_DISPLAY * pInfo)
{
	vecINFImportantInfoIter it = m_vecImportStateANI.begin();
	while(it != m_vecImportStateANI.end())
	{
		if((*it)->m_nMapNum == pInfo->MapIndex)
		{
			(*it)->m_bMapInfluence		= pInfo->MapInfluenceType;
			(*it)->SetState(pInfo->TelePortState,pInfo->HPRate);
			break;
		}
		it++;
	}	
}

// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
void CINFBaseWarManager::AdventBaseNGC(MSG_NGCSPWAR_DISPLAY* pInfo, BOOL bPopUp)			//(SMSWARINFO_DISPLAY * pInfo)
{
	vecINFImportantInfoIter it = m_vecImportStateNGC.begin();
	while(it != m_vecImportStateNGC.end())
	{
		if((*it)->m_nMapNum == pInfo->MapIndex)
		{
			//(*it)->m_bMapInfluence		= pInfo->MapInfluenceType;
			(*it)->m_bMapInfluence		= MAP_INFLUENCE_NEUTRALITY;
			(*it)->SetState(0,pInfo->HPRate);
			(*it)->m_enumNgcState = pInfo->State;
			(*it)->m_fBarScale = pInfo->BCUContributePercent;

// 			if(NGCSP_START == pInfo->State && pInfo->HPRate == 0)
// 				(*it)->m_fBarScale = -1.0f;
// 			else
// 				(*it)->m_fBarScale = pInfo->BCUContributePercent;
// 
 			if(NGCSP_START == pInfo->State && !bPopUp)
 				(*it)->m_n10minTime = ENDTIME;	
	//		NGCSP_START == pInfo->State ? m_bBarRender = FALSE : m_bBarRender = TRUE;
			break;
		}
		it++;
	}	
}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

BOOL CINFBaseWarManager::SetBaseWarPointMapInfo(SMSWARINFO_DISPLAY * pWarInfo)
{
	if(IS_MAP_INFLUENCE_VCN(pWarInfo->MapInfluenceType))
	{// 바이제니유 맵.
		AdventBaseBCU(pWarInfo);
	}
	else if(IS_MAP_INFLUENCE_ANI(pWarInfo->MapInfluenceType))
	{// 알링턴 맵.
		AdventBaseAHI(pWarInfo);
	}
	return TRUE;
}

SIZE CINFBaseWarManager::GetStringSize(char* pTxt)
{
	SIZE sizeTxt;
	memset(&sizeTxt, 0x00, sizeof(SIZE));
	int nSize, nWidth, nHeight;
	DWORD dwFontFlags;
	
	nSize = 9;
	nWidth = 256;
	nHeight = 32;
	dwFontFlags = D3DFONT_ZENABLE;
	
	// 글자를 컬링 할것인가D3DFONT_BOLD
	CD3DHanFont* pFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),nSize, dwFontFlags, TRUE, nWidth, nHeight);
	pFont->InitDeviceObjects(g_pD3dDev);
	pFont->RestoreDeviceObjects();
	
	sizeTxt = pFont->GetStringSize(pTxt);		
	
	pFont->InvalidateDeviceObjects();
	pFont->DeleteDeviceObjects();
	SAFE_DELETE(pFont);	
	
	return sizeTxt;	
}

SIZE CINFBaseWarManager::GetBaseInfoFontWidth()
{
	SIZE sizeMaxWidth;		
	
	sizeMaxWidth.cx = GAMEMAIN_BASEWAR_INFLUENCE_WIDTH;
	sizeMaxWidth.cy = GAMEMAIN_BASEWAR_INFLUENCE_CAP_HEIGHT;	
	
	int nMaxString=0;
	char chMaxTxt[MAX_PATH];
	char chTmp[MAX_PATH];
	
	memset(chMaxTxt, 0x00, MAX_PATH);
	memset(chTmp, 0x00, MAX_PATH);
	
	// 바이제니유
	//wsprintf(chTmp, STRMSG_C_070206_0201, STRMSG_C_060210_0000);
	wsprintf(chTmp, STRMSG_C_060210_0000);
	strncpy(chMaxTxt, chTmp, MAX_PATH);
	nMaxString = strlen(chTmp);
	
	SIZE szTmp;
	szTmp = GetStringSize(chMaxTxt); 
// 	if(szTmp.cx > sizeMaxWidth.cx)
	{
		sizeMaxWidth.cx = szTmp.cx + 6;
	}
	
	if(szTmp.cy > sizeMaxWidth.cy)
	{
		sizeMaxWidth.cy = szTmp.cy;
	}	
	
	return sizeMaxWidth;
}
void CINFBaseWarManager::RenderBaseInfo()
{
#ifdef SC_STRATEGYPOINTWAR_RENEWAL_JHSEOL_SSJUNG 
//	if( 0 >= m_vecImportStateANI.size() && 0 >= m_vecImportStateBCU.size())
	if(m_nInfluenceState == INFLNONE && !m_bNGCbaseWar)
	{
		return;
	}
	POINT ptPos[BASEWAR_MAXLINE] =
	{
		{GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X,		GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_Y},
		{GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X+12,	GAMEMAIN_BASEWAR_INFLUENCE1_TIME_START_Y},
		{GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X+12,	GAMEMAIN_BASEWAR_INFLUENCE1_AREA_START_Y},
		
		{GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_X,		GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_Y},
		{GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_X+12,	GAMEMAIN_BASEWAR_INFLUENCE2_TIME_START_Y},
		{GAMEMAIN_BASEWAR_INFLUENCE2_INFLUENCE_START_X+12,	GAMEMAIN_BASEWAR_INFLUENCE2_AREA_START_Y}
	};
	DWORD dwColorList[BASEWAR_MAXLINE]	= 
	{
		GUI_FONT_COLOR_R, GUI_FONT_COLOR, GUI_FONT_COLOR,
		GUI_FONT_COLOR_R, GUI_FONT_COLOR, GUI_FONT_COLOR
	};	

	if(!m_bNGCbaseWar)
	{
		if(m_nInfluenceState % 2 == 0)
		{
			ptPos[0].x = GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X+12;
			dwColorList[0] = GUI_FONT_COLOR_SKY;
		}
		else
		{
			ptPos[BASEWAR_MAXLINE/2].x = GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X+12;
			dwColorList[BASEWAR_MAXLINE/2] = GUI_FONT_COLOR_SKY;
		}
	}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	else
	{
		ptPos[0].x = GAMEMAIN_BASEWAR_INFLUENCE1_INFLUENCE_START_X+20;
		dwColorList[0] = GUI_FONT_COLOR_M;
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	
	if(0 == m_sizeBaseInfo.cx )
	{
		m_sizeBaseInfo = GetBaseInfoFontWidth();
	}	
	
	int nCnt, nCntSub;
	nCnt = nCntSub = 0;
	
	int nBalonWidth,nBalonHeight;
	int nItemCnt = 0;
	int nPos = 0;
	nBalonWidth = m_sizeBaseInfo.cx;
	nBalonHeight = 0;	
	int nBoldPosX = GAMEMAIN_BASEWAR_INFLUENCE1_START_X;
	int nBoldPosY = GAMEMAIN_BASEWAR_INFLUENCE1_START_Y;
	
	int nSize = 1;
	if(!m_bNGCbaseWar)
		(m_nInfluenceState < INFLBCUANI ? nSize = 1 : nSize  = 2);

	for(int i = 0; i<nSize; ++i)
	{
		nItemCnt = 0;
		if(!m_bNGCbaseWar)
		{
// 2014-02-05 by ssjung 거점전 관련 UI 위치 수정
			if((m_nInfluenceState+i)%2 != 0)
			{
				// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
				m_pFontBaseInfo[i][0]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][0]->GetStringSize(m_sInfluence[(m_nInfluenceState + i) % 2]).cx) / 2,
												ptPos[nPos].y, dwColorList[nPos], m_sInfluence[(m_nInfluenceState + i) % 2], 0L);
#else
 				m_pFontBaseInfo[i]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i]->GetStringSize(m_sInfluence[(m_nInfluenceState+i)%2]).cx)/2,
 					ptPos[nPos].y, dwColorList[nPos], m_sInfluence[(m_nInfluenceState+i)%2], 0L);		
#endif
				// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
			}
			else
			{
				// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
				m_pFontBaseInfo[i][1]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][1]->GetStringSize(m_sInfluence[(m_nInfluenceState + i) % 2]).cx) / 2,
												ptPos[nPos].y,	dwColorList[nPos], m_sInfluence[(m_nInfluenceState + i) % 2], 0L);
#else
 				m_pFontBaseInfo[i]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i]->GetStringSize(m_sInfluence[(m_nInfluenceState+i)%2]).cx)/2,
 					ptPos[nPos].y,	dwColorList[nPos], m_sInfluence[(m_nInfluenceState+i)%2], 0L);
#endif
				// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
			}
		}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		else
		{
			// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
			m_pFontBaseInfo[i][2]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][2]->GetStringSize(STRMSG_C_130828_0001).cx) / 2,
											ptPos[nPos].y, dwColorList[nPos], STRMSG_C_130828_0001, 0L);
#else
 			m_pFontBaseInfo[i]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i]->GetStringSize(STRMSG_C_130828_0001).cx)/2,
 			ptPos[nPos].y, dwColorList[nPos], STRMSG_C_130828_0001, 0L);
#endif
			// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

		nItemCnt++;
		nPos++;
		
		// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
		if((m_nInfluenceState + i) % 2 != 0)
		{
			m_pFontBaseInfo[i][3]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][3]->GetStringSize(STRMSG_C_130823_0001).cx) / 2,
											ptPos[nPos].y,dwColorList[nPos], STRMSG_C_130823_0001, 0L);			//거점전
			++nItemCnt;
			++nPos;
			
			m_pFontBaseInfo[i][4]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][4]->GetStringSize(STRMSG_C_130823_0002).cx) / 2,
											ptPos[nPos].y, dwColorList[nPos], STRMSG_C_130823_0002, 0L);		//진행중
		}
		else
		{
			m_pFontBaseInfo[i][5]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][5]->GetStringSize(STRMSG_C_130823_0001).cx) / 2,
											ptPos[nPos].y,dwColorList[nPos], STRMSG_C_130823_0001, 0L);			//거점전
			++nItemCnt;
			++nPos;
			
			m_pFontBaseInfo[i][6]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i][6]->GetStringSize(STRMSG_C_130823_0002).cx) / 2,
											ptPos[nPos].y, dwColorList[nPos], STRMSG_C_130823_0002, 0L);		//진행중
		}
#else
 		m_pFontBaseInfo[i]->DrawText( GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i]->GetStringSize(STRMSG_C_130823_0001).cx)/2,
 		ptPos[nPos].y,dwColorList[nPos], STRMSG_C_130823_0001, 0L);		//거점전 
 		nItemCnt++;
 		nPos++;
 		
 		m_pFontBaseInfo[i]->DrawText(GAMEMAIN_BASEWAR_START_X + (GAMEMAIN_BASEWAR_INTERFACE_SIZE_X - m_pFontBaseInfo[i]->GetStringSize(STRMSG_C_130823_0002).cx)/2,
 		ptPos[nPos].y, dwColorList[nPos], STRMSG_C_130823_0002, 0L);		//진행중 
#endif
		// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
		nItemCnt++;
 		nPos++;
// end 2014-02-05 by ssjung 거점전 관련 UI 위치 수정		
		nBalonHeight = (nItemCnt*GAMEMAIN_BASEWAR_INFLUENCE_EACH_HEIGHT)+GAMEMAIN_BASEWAR_INFLUENCE_CAP_HEIGHT;
		
		if(i > 0)
		{// 두번째 모선.
			nBoldPosX = GAMEMAIN_BASEWAR_INFLUENCE2_START_X;
			nBoldPosY = GAMEMAIN_BASEWAR_INFLUENCE2_START_Y;
		}
		if(m_bNGCbaseWar)
		{
			SetButtonPos2(nBoldPosX+nBalonWidth+2,nBoldPosY+2);
		}
		else
		{
			if(INFLNONE < m_nInfluenceState)
			{
				if((m_nInfluenceState+i) % 2 != 0)		// 바이제니유.
				{
					SetButtonPos0(nBoldPosX+nBalonWidth+2,nBoldPosY+2);
				}
				else							//알링턴 
				{
					SetButtonPos1(nBoldPosX+nBalonWidth+2,nBoldPosY+2);
				}
			}
		}
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI시스템 변경
		RenderBaseWarInfoBalon(nBoldPosX - 8,
#else
		RenderBaseWarInfoBalon(nBoldPosX,
#endif
		nBoldPosY,
		nBalonWidth, nBalonHeight);
 	}
	
#endif
}
void CINFBaseWarManager::RenderBaseWarInfoBalon(int x, int y, int cx, int cy)
{	
	
	m_pBalonChat[0]->Move(x,y);
	m_pBalonChat[0]->Render();
	m_pBalonChat[1]->Move(x+ID_BASEWAR_BALON_TLW,y);
	m_pBalonChat[1]->SetScale(cx-(ID_BASEWAR_BALON_TLW), 1);
	m_pBalonChat[1]->Render();
	m_pBalonChat[2]->Move(x+cx - ID_BASEWAR_BALON_TLW+ID_BASEWAR_BALON_TRW+(ID_BASEWAR_BALON_TMW*2),y);
	m_pBalonChat[2]->Render();
	
	m_pBalonChat[3]->Move(x, y+ID_BASEWAR_BALON_TLH);
	m_pBalonChat[3]->SetScale(1, cy - (ID_BASEWAR_BALON_TLH + ID_BASEWAR_BALON_BLH));
	m_pBalonChat[3]->Render();
	m_pBalonChat[4]->Move(x+ID_BASEWAR_BALON_MLW, y+ID_BASEWAR_BALON_MRW);
	m_pBalonChat[4]->SetScale(cx-(ID_BASEWAR_BALON_TLW), cy - (ID_BASEWAR_BALON_TLH+ID_BASEWAR_BALON_BLH));
	m_pBalonChat[4]->Render();
	m_pBalonChat[5]->Move(x+cx - ID_BASEWAR_BALON_MLW+ID_BASEWAR_BALON_MRW+(ID_BASEWAR_BALON_MMW*2), y+ID_BASEWAR_BALON_TRH);
	m_pBalonChat[5]->SetScale(1, cy - (ID_BASEWAR_BALON_TRH + ID_BASEWAR_BALON_BRH));
	m_pBalonChat[5]->Render();
	
	m_pBalonChat[6]->Move(x, y+cy-ID_BASEWAR_BALON_BLH);
	m_pBalonChat[6]->Render();
	m_pBalonChat[7]->Move(x + ID_BASEWAR_BALON_BLW, y+cy-ID_BASEWAR_BALON_BLH);
	m_pBalonChat[7]->SetScale(cx-(ID_BASEWAR_BALON_BLW), 1);
	m_pBalonChat[7]->Render();
	m_pBalonChat[8]->Move(x+cx-ID_BASEWAR_BALON_BLW+ID_BASEWAR_BALON_BRW+(ID_BASEWAR_BALON_BMW*2), y+cy-ID_BASEWAR_BALON_BLH);
	m_pBalonChat[8]->Render();
	
}

BOOL CINFBaseWarManager::SetButtonPos1(UINT i_nPosX,UINT i_nPosY)
{
	
	m_nButtonPosX1 = i_nPosX;
	m_nButtonPosY1 = i_nPosY;
	m_pImgBaseWarANIButton->SetBtnPosition(m_nButtonPosX1,m_nButtonPosY1);
	
	// 이미지위치를 셋팅.
	
	UINT nPosX = i_nPosX + BASEWAR_BUTTON_IMPORTANT_GAP;
	vecINFImportantInfoIter it = m_vecImportStateANI.begin();
	while(it != m_vecImportStateANI.end())
	{
		(*it)->SetImportantPos(nPosX,i_nPosY);
		nPosX += BASEWAR_IMPORTANT_GAP;
		it++;
	}
	
	return TRUE;
}
BOOL CINFBaseWarManager::SetButtonPos0(UINT i_nPosX,UINT i_nPosY)
{
	m_nButtonPosX0 = i_nPosX;
	m_nButtonPosY0 = i_nPosY;
	m_pImgBaseWarBCUButton->SetBtnPosition(m_nButtonPosX0,m_nButtonPosY0);
	
	// 이미지위치를 셋팅.
	UINT nPosX = i_nPosX + BASEWAR_BUTTON_IMPORTANT_GAP;
	vecINFImportantInfoIter it = m_vecImportStateBCU.begin();
	while(it != m_vecImportStateBCU.end())
	{
		(*it)->SetImportantPos(nPosX,i_nPosY);
		nPosX += BASEWAR_IMPORTANT_GAP;
		it++;
	}
	return TRUE;
}

// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
BOOL CINFBaseWarManager::SetButtonPos2(UINT i_nPosX,UINT i_nPosY)
{
	m_nButtonPosX2 = i_nPosX;
	m_nButtonPosY2 = i_nPosY;
	m_pImgBaseWarNGCButton->SetBtnPosition(m_nButtonPosX2,m_nButtonPosY2);
	
	// 이미지위치를 셋팅.
	UINT nPosX = i_nPosX + BASEWAR_BUTTON_IMPORTANT_GAP;
	vecINFImportantInfoIter it = m_vecImportStateNGC.begin();
	while(it != m_vecImportStateNGC.end())
	{
		(*it)->SetImportantPos(nPosX,i_nPosY);
		nPosX += BASEWAR_IMPORTANT_GAP;
		it++;
	}
	return TRUE;
}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

void CINFBaseWarManager::Render()
{
	RenderBaseInfo();
	
	if((m_nButtonPosX0 != 0) && (m_nButtonPosY0 != 0))
	{
		m_pImgBaseWarBCUButton->Render();
 		if(m_bShow0)
 		{
			vecINFImportantInfoIter it = m_vecImportStateBCU.begin();
			while(it != m_vecImportStateBCU.end())
			{
				(*it)->Render();
				it++;
			}
		}
	}
	
	if((m_nButtonPosX1 != 0) && (m_nButtonPosY1 != 0))
	{
		m_pImgBaseWarANIButton->Render();
 		if(m_bShow1)
 		{		
			vecINFImportantInfoIter it = m_vecImportStateANI.begin();
			while(it != m_vecImportStateANI.end())
			{
// 				if((*it)->m_nMapNum == g_pShuttleChild->GetMyShuttleInfo().MapChannelIndex.MapIndex)
// 				{
// 					RenderTimeLimit();
// 				}
// 				if(m_bShow1)
// 				{
					(*it)->Render();
//				}
				it++;
			}
		}
	}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	if((m_nButtonPosX2 != 0) && (m_nButtonPosY2 != 0))
	{
		m_pImgBaseWarNGCButton->Render();
		if(m_bShow2)
		{		
			vecINFImportantInfoIter it = m_vecImportStateNGC.begin();
			while(it != m_vecImportStateNGC.end())
			{
				(*it)->Render();
				it++;
			}
		}
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

	if(m_bShowTimeImage)
	{
	// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		if(m_bNGCbaseWar)
		{
			RenderInflGauge();
		}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		RenderTimeLimit();
	}

	RenderBaseWarToolTip();

}
void CINFBaseWarManager::Tick()
{
	m_bShowTimeImage = FALSE;
	vecINFImportantInfoIter it = m_vecImportStateBCU.begin();
	while(it != m_vecImportStateBCU.end())
	{
		if((*it)->m_nMapNum == g_pShuttleChild->GetMyShuttleInfo().MapChannelIndex.MapIndex)
		{
			TimeSetting((*it)->m_fSummonLiveTime);
			m_bShowTimeImage = TRUE;
		}
		(*it)->Tick();
		it++;
	}
	it = m_vecImportStateANI.begin();
	while(it != m_vecImportStateANI.end())
	{
		if((*it)->m_nMapNum == g_pShuttleChild->GetMyShuttleInfo().MapChannelIndex.MapIndex)
		{
			TimeSetting((*it)->m_fSummonLiveTime);
			m_bShowTimeImage = TRUE;
		}
		(*it)->Tick();
		it++;
	}

// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	it = m_vecImportStateNGC.begin();
	while(it != m_vecImportStateNGC.end())
	{
		if((*it)->m_nMapNum == g_pShuttleChild->GetMyShuttleInfo().MapChannelIndex.MapIndex)
		{
			TimeSetting((*it)->m_fSummonLiveTime);
			m_bShowTimeImage = TRUE;
			m_fBarScale = (*it)->m_fBarScale;
			m_enumNgcState = (*it)->m_enumNgcState;
		}
		if(POPUPTIME == (*it)->m_n10minTime)
		{
			{
				g_pInterface->NGCBaseWar10MinPopUp((*it)->m_nMapNum);
			}
			(*it)->m_n10minTime = ENDTIME;
		}
		(*it)->Tick();
		it++;
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
}

USHORT CINFBaseWarManager::SetBaseOption(USHORT i_Option)
{
	USHORT OldOption = i_Option;

	vecINFImportantInfoIter it = m_vecImportBCU.begin();
	while(it != m_vecImportBCU.end())
	{
		(*it)->SetOption(i_Option);
		it++;
	}
	
	it = m_vecImportANI.begin();
	while(it != m_vecImportANI.end())
	{
		(*it)->SetOption(i_Option);
		it++;
	}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	it = m_vecImportNGC.begin();
	while(it != m_vecImportNGC.end())
	{
		(*it)->SetOption(i_Option);
		it++;
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

	m_nOption = i_Option;
	return OldOption;
}

int	CINFBaseWarManager::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_MOUSEMOVE:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			
			m_bShowToolTip = FALSE;
			vecINFImportantInfoIter it;
			int nCount = 0;
			int nStartPosX = 0; 
			int nImgSizeX = MAP_IMAGE_SIZE_X;
			int nImgSizeY = MAP_IMAGE_SIZE_Y;
			
			if(m_pImgBaseWarBCUButton->OnMouseMove(pt))
			{
			}
			if(m_pImgBaseWarANIButton->OnMouseMove(pt))
			{
			}
			if(m_pImgBaseWarNGCButton->OnMouseMove(pt))
			{
				
			}
			if(m_nInfluenceState != INFLNONE)
			{
				
				if(m_bShow1) //알링턴이 보일때 
				{
					nStartPosX = m_nButtonPosX1 + BASEWAR_BUTTON_IMPORTANT_GAP;
					it = m_vecImportStateANI.begin();
					while(it != m_vecImportStateANI.end())
					{
						if((pt.x > nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) && pt.x < nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) + nImgSizeX)
							&& (pt.y > m_nButtonPosY1 && pt.y < m_nButtonPosY1 + nImgSizeY) )
						{	
							ShowBaseWarToolTipInfo(pt, (*it)->m_nMapNum, (*it)->m_fSummonLiveTime);
							//break;
							return INF_MSGPROC_BREAK;
						}
						nCount++;
						it++;
					}
				}
				
				if(m_bShow0) //바이제니유가 보일때 
				{
					nCount = 0;
					nStartPosX = m_nButtonPosX0 + BASEWAR_BUTTON_IMPORTANT_GAP;
					it = m_vecImportStateBCU.begin();
					while(it != m_vecImportStateBCU.end())
					{
						if((pt.x > nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) && pt.x < nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) + nImgSizeX)
							&& (pt.y > m_nButtonPosY0 && pt.y < m_nButtonPosY0 + nImgSizeY) )
						{	
							ShowBaseWarToolTipInfo(pt, (*it)->m_nMapNum, (*it)->m_fSummonLiveTime);
							//break;
							return INF_MSGPROC_BREAK;
						}
						nCount++;
						it++;
					}
				}
				
			}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
			if(m_bNGCbaseWar)
			{
				if(m_bShow2)
				{
					nCount = 0;
					nStartPosX = m_nButtonPosX2 + BASEWAR_BUTTON_IMPORTANT_GAP;
					it = m_vecImportStateNGC.begin();
					while(it != m_vecImportStateNGC.end())
					{
						if((pt.x > nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) && pt.x < nStartPosX + (nCount * BASEWAR_IMPORTANT_GAP) + nImgSizeX)
							&& (pt.y > m_nButtonPosY2 && pt.y < m_nButtonPosY2 + nImgSizeY) )
						{	
							ShowBaseWarToolTipInfo(pt, (*it)->m_nMapNum, (*it)->m_fSummonLiveTime);
							//break;
							return INF_MSGPROC_BREAK;
						}
						nCount++;
						it++;
					}
				}
			}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		}
		break;
	case WM_LBUTTONDOWN:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			if(m_pImgBaseWarBCUButton->OnLButtonDown(pt))
			{
				return INF_MSGPROC_BREAK;
			}
			if(m_pImgBaseWarANIButton->OnLButtonDown(pt))
			{
				return INF_MSGPROC_BREAK;
			}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
			if(m_pImgBaseWarNGCButton->OnLButtonDown(pt))
			{
				return INF_MSGPROC_BREAK;
			}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		}
		break;
	case WM_LBUTTONUP:
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			CheckMouseReverse(&pt);
			if(m_pImgBaseWarBCUButton->OnLButtonUp(pt))
			{
				m_bShow0 = !m_bShow0;
				m_pImgBaseWarBCUButton->ChangeBoth(m_bShow0);
				return INF_MSGPROC_BREAK;
			}
			if(m_pImgBaseWarANIButton->OnLButtonUp(pt))
			{
				m_bShow1 = !m_bShow1;
				m_pImgBaseWarANIButton->ChangeBoth(m_bShow1);
				return INF_MSGPROC_BREAK;
			}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
			if(m_pImgBaseWarNGCButton->OnLButtonUp(pt))
			{
				m_bShow2 = !m_bShow2;
				m_pImgBaseWarNGCButton->ChangeBoth(m_bShow2);
				return INF_MSGPROC_BREAK;
			}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
		}
		break;
	}
	
	return INF_MSGPROC_NORMAL;
}

void CINFBaseWarManager::AddBaseInfo(MapIndex_t	MapIndex, float fSummonLiveTime, short MapInfluenceType)
{
	vecINFImportantInfoIter it;
	
	
	if(IS_MAP_INFLUENCE_VCN(MapInfluenceType))
	{
		it = m_vecImportBCU.begin();
		while(it != m_vecImportBCU.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_fSummonLiveTime = fSummonLiveTime;
				m_vecImportStateBCU.push_back((*it));

				if(m_nInfluenceState == INFLNONE)
					m_nInfluenceState = INFLBCU;
				else if(m_nInfluenceState == INFLANI)
					m_nInfluenceState = INFLANIBCU;

				m_pImgBaseWarBCUButton->ShowWindow(TRUE);
				break;
			}
			it++;
		}
	}
	else if(IS_MAP_INFLUENCE_ANI(MapInfluenceType))
	{
		it = m_vecImportANI.begin();
		while(it != m_vecImportANI.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_nWarState = WARSTATE_BASEWAR;
				(*it)->m_fSummonLiveTime = fSummonLiveTime;
				m_vecImportStateANI.push_back((*it));
				
				if(m_nInfluenceState == INFLNONE)
					m_nInfluenceState = INFLANI;
				else if(m_nInfluenceState == INFLBCU)
					m_nInfluenceState = INFLBCUANI;

				m_pImgBaseWarANIButton->ShowWindow(TRUE);
				break;
			}
			it++;
		}
	}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	else if(MAP_INFLUENCE_NEUTRALITY == MapInfluenceType) //ngc거점인가 
	{
		it = m_vecImportNGC.begin();
		while(it != m_vecImportNGC.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_nWarState = WARSTATE_BASEWAR;
				(*it)->m_fSummonLiveTime = fSummonLiveTime;
				(*it)->m_n10minTime = START_TIME;
				m_vecImportStateNGC.push_back((*it));
				m_pImgBaseWarNGCButton->ShowWindow(TRUE);
				m_bNGCbaseWar = TRUE;
				break;
			}
			it++;
		}
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
}


void CINFBaseWarManager::ShowBaseWarToolTipInfo(POINT pt, DWORD	nMapNum, float fSummonLiveTime)
{
	m_bShowToolTip = TRUE;

	MAP_INFO* pMapInfo = g_pDatabase->GetMapInfo(nMapNum);
	char chTime[128];
	memset(chTime, 0x00, 128);
	int nHour, nMinute;
	int nSecondRemainBaseWarTmp = fSummonLiveTime;	
	nHour = (nSecondRemainBaseWarTmp/3600);
	nSecondRemainBaseWarTmp -= (nHour*3600);
	nMinute = (nSecondRemainBaseWarTmp/60);

	m_strShowToolTipInfo->pMousePos = pt;

	strcpy(m_strShowToolTipInfo->sMapName, pMapInfo->MapName);
	wsprintf(m_strShowToolTipInfo->sTime, STRMSG_C_070206_0202, nHour, nMinute);
}

void CINFBaseWarManager::RenderBaseWarToolTip()
{
	if(!m_bShowToolTip)
		return;

	int lengX = 0;
	int nX = m_strShowToolTipInfo->pMousePos.x;
	
	int tempX = m_pFontPToolTip[0]->GetStringSize(m_strShowToolTipInfo->sMapName).cx + 5;
	int temp02X = m_pFontPToolTip[1]->GetStringSize(m_strShowToolTipInfo->sTime).cx + 5;
	int lengY = m_pFontPToolTip[1]->GetStringSize(m_strShowToolTipInfo->sTime).cy;

	(tempX > temp02X) ? lengX = tempX : lengX = temp02X;
	
	if(nX + lengX > g_pD3dApp->GetBackBufferDesc().Width)
	{
		nX = g_pD3dApp->GetBackBufferDesc().Width - lengX;
	}
	g_pGameMain->RenderPopUpWindowImage(nX, m_strShowToolTipInfo->pMousePos.y-(lengY*2), lengX, 1);
	g_pGameMain->RenderPopUpWindowImage(nX, m_strShowToolTipInfo->pMousePos.y-lengY, lengX, 1);
//	g_pGameMain->RenderToolTipBg(nX, m_strShowToolTipInfo->pMousePos.y-(lengY*2), lengX, 30);

 	m_pFontPToolTip[0]->DrawText(nX, m_strShowToolTipInfo->pMousePos.y-(lengY*2), GUI_FONT_COLOR_W,m_strShowToolTipInfo->sMapName);
 	m_pFontPToolTip[1]->DrawText(nX, m_strShowToolTipInfo->pMousePos.y-lengY, GUI_FONT_COLOR_W,m_strShowToolTipInfo->sTime);
}


void CINFBaseWarManager::DestroyBaseWarInfo(MapIndex_t MapIndex, SHORT MapInfluenceType)
{
	vecINFImportantInfoIter it;

	if(IS_MAP_INFLUENCE_VCN(MapInfluenceType))
	{
		it = m_vecImportStateBCU.begin();
		while(it != m_vecImportStateBCU.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_fSummonLiveTime = 0.0f;
				it = m_vecImportStateBCU.erase(it);
				break;
			}
			it++;
		}
		if(m_vecImportStateBCU.size() == 0)
		{
			if(m_nInfluenceState)
			{
				m_nInfluenceState -= (m_nInfluenceState % 2 == 0 ) ? 2 : INFLBCU;
				m_nButtonPosX0 = 0;
				m_nButtonPosY0 = 0;
				m_bShow0 = TRUE;
				m_pImgBaseWarBCUButton->ChangeBoth(m_bShow0);
				m_pImgBaseWarBCUButton->ShowWindow(FALSE);
			}
		}
	}
	else if(IS_MAP_INFLUENCE_ANI(MapInfluenceType))
	{
		it = m_vecImportStateANI.begin();
		while(it != m_vecImportStateANI.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_fSummonLiveTime = 0.0f;
				it = m_vecImportStateANI.erase(it);
				break;
			}
			it++;
		}
		if(m_vecImportStateANI.size() == 0)
		{
			if(m_nInfluenceState)
			{
				m_nInfluenceState -= (m_nInfluenceState == INFLANIBCU ) ? 3 : INFLANI;
				m_nButtonPosX1 = 0;
				m_nButtonPosY1 = 0;
				m_bShow1 = TRUE;
				m_pImgBaseWarANIButton->ChangeBoth(m_bShow1);
				m_pImgBaseWarANIButton->ShowWindow(FALSE);
			}
		}
	}
// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	if(MAP_INFLUENCE_NEUTRALITY == MapInfluenceType && m_bNGCbaseWar)//if NGC거점인가 
	{
		it = m_vecImportStateNGC.begin();
		while(it != m_vecImportStateNGC.end())
		{
			if((*it)->m_nMapNum == MapIndex)
			{
				(*it)->m_fSummonLiveTime = 0.0f;
				it = m_vecImportStateNGC.erase(it);
				break;
			}
			it++;
		}
		if(m_vecImportStateNGC.size() == 0)
		{
			if(m_bNGCbaseWar)
			{
				m_nButtonPosX2 = 0;
				m_nButtonPosY2 = 0;
				m_bShow2 = TRUE;
				m_pImgBaseWarNGCButton->ChangeBoth(m_bShow2);
				m_pImgBaseWarNGCButton->ShowWindow(FALSE);
				m_bNGCbaseWar = FALSE;
			}
		}
	}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
}


void CINFBaseWarManager::RenderTimeLimit()
{
	SIZE bkSize = { g_pD3dApp->GetBackBufferDesc().Width, g_pD3dApp->GetBackBufferDesc().Height };

	char szHour[32] = {0,}, szMin[32] = {0,}, szSec[32] = {0,};

	// 시간이 0일때는 표시 안한다
// 	if( m_nHour != 0 )
// 		sprintf( szHour, "%02d", m_nHour );

	sprintf( szMin, "%02d", m_nMin );
	sprintf( szSec, "%02d", m_nSec );

// 	int nHourLen	= strlen( szHour );
	int nMinLen		= strlen( szMin );
	int nSecLen		= strlen( szSec );

	// 시간 문자열 길이( 시간이 0일때는 콜론이 하나 빠진다)
//	int nLength = nHourLen > 0 ? nHourLen + nMinLen + nSecLen + 2 : nHourLen + nMinLen + nSecLen + 1;
	int nLength = nMinLen + nSecLen + 1;
	int	nWidth;
	int	nHeight;
	float fScale;
	int	nX;

	{
		nWidth	= m_pColonImage->GetImgSize().x;
		
		if( g_pGameMain->m_pQuickSlot->IsSlotOpen() == FALSE )
			nHeight = bkSize.cy - (90 + 84);			
		else
			nHeight = bkSize.cy - 90;		
		
		fScale	= 1.0f;
	}

	nX		= (bkSize.cx - nWidth * nLength )/2;

	int i=0;

	for( i=0; i<nMinLen; ++i )
	{
		int nIdx = szMin[i] - 48;	// 아스키 문자 to 숫자로
		
		m_pTimeNumImage[ nIdx ]->SetScale( fScale, fScale );
		m_pTimeNumImage[ nIdx ]->Move( nX, nHeight );
		m_pTimeNumImage[ nIdx ]->Render();
		
		nX	+= nWidth;
	}

	m_pColonImage->SetScale( fScale, fScale );
	m_pColonImage->Move( nX, nHeight );
	m_pColonImage->Render();
	nX	+= nWidth;

	for( i=0; i<nSecLen; ++i )		// 아스키 문자 to 숫자로
	{
		int nIdx = szSec[i] - 48;

		m_pTimeNumImage[ nIdx ]->SetScale( fScale, fScale );
		m_pTimeNumImage[ nIdx ]->Move( nX, nHeight );
		m_pTimeNumImage[ nIdx ]->Render();

		nX	+= nWidth;
	}
}

void CINFBaseWarManager::TimeSetting(float fTime)
{
	int nHour;
	int nSecondRemainBaseWarTmp = fTime;	
	nHour = (nSecondRemainBaseWarTmp/3600);
	nSecondRemainBaseWarTmp -= (nHour*3600);
	m_nMin = (nSecondRemainBaseWarTmp/60);
	nSecondRemainBaseWarTmp -= (m_nMin*60);
	m_nSec = nSecondRemainBaseWarTmp;
}

// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
void CINFBaseWarManager::RenderInflGauge()
{
	{
		POINT pt = m_pImgResetBarBack->GetImgSize();
		DWORD nX = (int)(g_pD3dApp->GetBackBufferDesc().Width - pt.x)/2;
		DWORD nY = (int)(g_pD3dApp->GetBackBufferDesc().Height - NGC_BASEWAR_IMG_RESET_BAR_Y);
		
		// 배경.
		m_pImgResetBarBack->Move(nX,nY);
		m_pImgResetBarBack->Render();

		if(NGCSP_START == m_enumNgcState && m_fBarScale == 0)
			m_bBarRender = FALSE;
		else
		{
			m_fBarScale /= 100.00f;
			m_bBarRender = TRUE;
		}
// 		if(m_fBarScale >= 0)
// 		{
// 			m_fBarScale /= 100.00f;
// 			m_bBarRender = TRUE;
// 		}
// 		else
// 			m_bBarRender = FALSE;

		if(m_bBarRender)
		{
			m_pImgResetBarBar1->SetScale(m_fBarScale,1.f);
			m_pImgResetBarBar1->Move(nX + NGC_BASEWAR_IMG_RESET_BAR_BAR_X,nY + NGC_BASEWAR_IMG_RESET_BAR_BAR_Y);
			m_pImgResetBarBar1->Render();

			m_pImgResetBarBar2->SetScale(1.00f - m_fBarScale,1.f);
			m_pImgResetBarBar2->Move(nX + NGC_BASEWAR_IMG_RESET_BAR_BAR_X + m_pImgResetBarBar1->GetImgSize().x * m_fBarScale,nY + NGC_BASEWAR_IMG_RESET_BAR_BAR_Y);
			m_pImgResetBarBar2->Render();
		}
		m_pImgResetBarInf1->Move(nX + NGC_BASEWAR_IMG_RESET_BAR_ATTACK_X, nY + NGC_BASEWAR_IMG_RESET_BAR_ATTACK_Y);
		m_pImgResetBarInf1->Render();
		m_pImgResetBarInf2->Move(nX + NGC_BASEWAR_IMG_RESET_BAR_DEFEN_X, nY + NGC_BASEWAR_IMG_RESET_BAR_DEFEN_Y);
		m_pImgResetBarInf2->Render();
	}
}
// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

// 2014-03-11 by ssjung&ymjoo 월드맵 구현
BOOL CINFBaseWarManager::FindBaseWarMapIdx(MapIndex_t i_MapIndex, BOOL bCurrent)	 //0이면 기본 , 1이면 현재 진행중)
{
	vecINFImportantInfoIter it;
	
	if(bCurrent)
	{
		if(m_nInfluenceState)
		{
			it = m_vecImportStateBCU.begin();
			while(it != m_vecImportStateBCU.end())
			{
				if((*it)->m_nMapNum == i_MapIndex)
					return TRUE;
				++it;
			}
			it = m_vecImportStateANI.begin();
			while(it != m_vecImportStateANI.end())
			{
				if((*it)->m_nMapNum == i_MapIndex)
					return TRUE;
				++it;
			}
		}
		if(m_bNGCbaseWar)
		{
			it = m_vecImportStateNGC.begin();
			while(it != m_vecImportStateNGC.end())
			{
				if((*it)->m_nMapNum == i_MapIndex)
					return TRUE;
				++it;
			}
		}
	}
	else
	{
		it = m_vecImportBCU.begin();
		while(it != m_vecImportBCU.end())
		{
			if((*it)->m_nMapNum == i_MapIndex)
				return TRUE;
			++it;
		}
		
		it = m_vecImportANI.begin();
		while(it != m_vecImportANI.end())
		{
			if((*it)->m_nMapNum == i_MapIndex)
				return TRUE;
			++it;
		}
		
		it = m_vecImportNGC.begin();
		while(it != m_vecImportNGC.end())
		{
			if((*it)->m_nMapNum == i_MapIndex)
				return TRUE;
			++it;
		}
	}
	return FALSE;
}  
// end 2014-03-11 by ssjung&ymjoo 월드맵 구현