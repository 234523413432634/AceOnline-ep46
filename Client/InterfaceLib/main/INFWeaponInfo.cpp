// INFWeaponInfo.cpp: implementation of the CINFWeaponInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "INFWeaponInfo.h"
#include "INFGameMain.h"
#include "AtumApplication.h"
#include "StoreData.h"
#include "INFWindow.h"
#include "ShuttleChild.h"
#include "CharacterChild.h"				// 2005-07-21 by ispark
#include "ItemInfo.h"
#include "RangeTime.h"
#include "INFInven.h"
#include "INFImage.h"
#include "GameDataLast.h"
#include "WeaponItemInfo.h"
#include "dxutil.h"
#include "INFImageList.h"				// 2011. 10. 10 by jskim UI�ý��� ����
#include "INFImageEx.h"					// 2011. 10. 10 by jskim UI�ý��� ����

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define LEFT_WEAPON_NUMBER g_pShuttleChild->m_pPrimaryWeapon->GetItemGeneral()->CurrentCount// ������ ��� ���� �����(USE FUEL)
#define RIGHT_WEAPON_NUMBER g_pShuttleChild->m_pSecondaryWeapon->GetItemGeneral()->CurrentCount

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
#define FIRST_WEAPON_START_X	x
#define FIRST_WEAPON_START_Y	y + 22
#define FIRST_WEAPON_FONT_X		x + 17 //(FIRST_WEAPON_START_X + 55)
#define FIRST_WEAPON_FONT_Y		y + 8  //(FIRST_WEAPON_START_Y + 10)

#define SECOND_WEAPON_START_X	x
#define SECOND_WEAPON_START_Y	y + 22
#define SECOND_WEAPON_FONT_X	x + 11//SECOND_WEAPON_START_X + 55)
#define SECOND_WEAPON_FONT_Y	y + 8//SECOND_WEAPON_START_Y + 10)

#define FIRST_WEAPON_EMPTY_X	FIRST_WEAPON_START_X - 37
#define FIRST_WEAPON_EMPTY_Y	FIRST_WEAPON_START_Y + 5 
#define SECOND_WEAPON_EMPTY_X	SECOND_WEAPON_START_X - 37
#define SECOND_WEAPON_EMPTY_Y	SECOND_WEAPON_START_Y + 5
// end 2011. 10. 10 by jskim UI�ý��� ����														  
#else 
#define FIRST_WEAPON_START_X	23
#define FIRST_WEAPON_START_Y	178
#define FIRST_WEAPON_GAGE_X		(FIRST_WEAPON_START_X + 37)
#define FIRST_WEAPON_GAGE_Y		(FIRST_WEAPON_START_Y + 3)
#define FIRST_WEAPON_FONT_X		(FIRST_WEAPON_START_X + 55)
#define FIRST_WEAPON_FONT_Y		(FIRST_WEAPON_START_Y + 10)

#define SECOND_WEAPON_START_X	23
#define SECOND_WEAPON_START_Y	207
#define SECOND_WEAPON_GAGE_X	(SECOND_WEAPON_START_X + 37)
#define SECOND_WEAPON_GAGE_Y	(SECOND_WEAPON_START_Y + 3)
#define SECOND_WEAPON_FONT_X	(SECOND_WEAPON_START_X + 55)
#define SECOND_WEAPON_FONT_Y	(SECOND_WEAPON_START_Y + 10)

#endif

#define LEFT_WEAPON_NUMBER_X	5
#define LEFT_WEAPON_NUMBER_Y	57
#define WEAPON_NUMBER_SIZE		10
// 2007-10-15 by bhsohn �Ѿ� ������ �߰� ó��
//#define RIGHT_WEAPON_NUMBER_X	(g_pD3dApp->GetBackBufferDesc().Width - 45) // 45 = WEAPON_NUMBER_SIZE*4(4�ڸ�����) + LEFT_WEAPON_NUMBER_X
#define RIGHT_WEAPON_NUMBER_X	(g_pD3dApp->GetBackBufferDesc().Width - 52) // 50 = WEAPON_NUMBER_SIZE*5(5�ڸ�����) + LEFT_WEAPON_NUMBER_X

#define LEFT_FUEL_X				1
#define LEFT_FUEL_Y				59

CINFWeaponInfo::CINFWeaponInfo(CAtumNode* pParent)
{
	FLOG( "CINFWeaponInfo(CAtumNode* pParent)" );
	m_pStImage = NULL ;
	m_pStWeaponImage = NULL;
	m_pNdImage = NULL ;
	m_pNdWeaponImage = NULL;
	m_pStOverHeatBar = NULL;
	m_pNdOverHeatBar = NULL;
	m_pEmptyWeaponImage = NULL;
	m_pStFuelGageBar = NULL;
	m_pStFuelUnderGageBar = NULL;
//	m_pNdFuelGageBar = NULL;
//	m_pNdFuelUnderGageBar = NULL;
	m_pReloadImage = NULL;
	m_pOverHeatImage = NULL;
	m_pBulletEmptyImage = NULL;

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	m_pBulletEmptyImage1 = NULL;			// 2011. 10. 10 by jskim UI�ý��� ����
	m_pBulletEmptyImage2 = NULL;			// 2011. 10. 10 by jskim UI�ý��� ����
    m_pBulletLowImage1 = NULL;				// 2011. 10. 10 by jskim UI�ý��� ����
	m_bFlash = FALSE;						// 2011. 10. 10 by jskim UI�ý��� ����
#endif
	m_pBulletLowImage = NULL;



	m_nLeftWeaponInfoPosX = 0 ;
	m_nRightWeaponInfoPosX = g_pD3dApp->GetBackBufferDesc().Width - SIZE_WEAPON_X;

	m_pParent = pParent;
	memset(m_pWeaponNumberImage, 0x00, sizeof(INT)*10);
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	memset(m_pWeaponWarningNumberImage, 0x00, sizeof(INT)*10);									  
#endif
}

CINFWeaponInfo::~CINFWeaponInfo()
{
	FLOG( "~CINFWeaponInfo()" );
	SAFE_DELETE(m_pStImage) ;
	SAFE_DELETE(m_pStWeaponImage);
	SAFE_DELETE(m_pNdImage) ;
	SAFE_DELETE(m_pNdWeaponImage);
	SAFE_DELETE(m_pStOverHeatBar) ;
	SAFE_DELETE(m_pNdOverHeatBar);
	SAFE_DELETE(m_pEmptyWeaponImage);
	SAFE_DELETE(m_pWeaponData);
	SAFE_DELETE(m_pStFuelGageBar);
	SAFE_DELETE(m_pStFuelUnderGageBar);
//	SAFE_DELETE(m_pNdFuelGageBar);
//	SAFE_DELETE(m_pNdFuelUnderGageBar);
	SAFE_DELETE(m_pReloadImage);
	SAFE_DELETE(m_pOverHeatImage);
	SAFE_DELETE(m_pBulletEmptyImage);
    SAFE_DELETE(m_pBulletLowImage);				// 2011. 10. 10 by jskim UI�ý��� ����
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	SAFE_DELETE(m_pBulletEmptyImage1);			// 2011. 10. 10 by jskim UI�ý��� ����
	SAFE_DELETE(m_pBulletEmptyImage2);			// 2011. 10. 10 by jskim UI�ý��� ����	
	SAFE_DELETE(m_pBulletLowImage1);			// 2011. 10. 10 by jskim UI�ý��� ����			  
#endif

	int i; for(i=0;i<10;i++)
	{
		SAFE_DELETE(m_pWeaponNumberImage[i]);
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
		SAFE_DELETE(m_pWeaponWarningNumberImage[i]);			// 2011. 10. 10 by jskim UI�ý��� ����
#endif
	}
}

HRESULT CINFWeaponInfo::InitDeviceObjects()
{
	FLOG( "CINFWeaponInfo::InitDeviceObjects()" );
	char strPath[256];
	g_pD3dApp->LoadPath( strPath, IDS_DIRECTORY_TEXTURE, "weapon.tex");
	m_pWeaponData = new CGameData;
	m_pWeaponData->SetFile(strPath, FALSE, NULL, 0);

	m_pStImage = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	DataHeader	* pDataHeader = FindResource("1sta");
	m_pStImage->InitDeviceObjects( pDataHeader ) ;

	m_pNdImage = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("2nda");
	m_pNdImage->InitDeviceObjects( pDataHeader ) ;

	m_pStOverHeatBar = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("1stgage");
	m_pStOverHeatBar->InitDeviceObjects( pDataHeader ) ;

	m_pNdOverHeatBar = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("2ndgage");
	m_pNdOverHeatBar->InitDeviceObjects( pDataHeader ) ;

	m_pEmptyWeaponImage = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("weslot");
	m_pEmptyWeaponImage->InitDeviceObjects( pDataHeader ) ;

	m_pStFuelGageBar = new CINFImageEx;				// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("beam1_g");
	m_pStFuelGageBar->InitDeviceObjects( pDataHeader ) ;

	m_pStFuelUnderGageBar = new CINFImageEx;			// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("beam1_b");
	m_pStFuelUnderGageBar->InitDeviceObjects( pDataHeader ) ;

/*	m_pNdFuelGageBar = new CINFImage;
	pDataHeader = FindResource("beam2_g");
	m_pNdFuelGageBar->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;

	m_pNdFuelUnderGageBar = new CINFImage;
	pDataHeader = FindResource("beam2_b");
	m_pNdFuelUnderGageBar->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
*/
	m_pReloadImage = new CINFImageEx;				// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("reload");
	m_pReloadImage->InitDeviceObjects( pDataHeader ) ;
							
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	m_pOverHeatImage = new CINFImageEx;				// 2011. 10. 10 by jskim UI�ý��� ����
	pDataHeader = FindResource("weover_1");
	m_pOverHeatImage->InitDeviceObjects( pDataHeader ) ;
	// 2011. 10. 10 by jskim UI�ý��� ����
	m_pBulletEmptyImage = new CINFImageEx;			
	pDataHeader = FindResource("welow_1");
	m_pBulletEmptyImage->InitDeviceObjects( pDataHeader ) ;

	m_pBulletEmptyImage1 = new CINFImageEx;
	pDataHeader = FindResource("welow_11");
	m_pBulletEmptyImage1->InitDeviceObjects( pDataHeader ) ;

	m_pBulletEmptyImage2 = new CINFImageEx;
	pDataHeader = FindResource("welow_21");
	m_pBulletEmptyImage2->InitDeviceObjects( pDataHeader ) ;

	m_pBulletLowImage = new CINFImageEx;
	pDataHeader = FindResource("welow_1");
	m_pBulletLowImage->InitDeviceObjects( pDataHeader ) ;

	m_pBulletLowImage1 = new CINFImageEx;
	pDataHeader = FindResource("welow_2");
	m_pBulletLowImage1->InitDeviceObjects( pDataHeader ) ;	   
#else	 
	m_pOverHeatImage = new CINFImageEx;
	pDataHeader = FindResource("weover");
	m_pOverHeatImage->InitDeviceObjects(pDataHeader);
	m_pBulletEmptyImage = new CINFImageEx;
	pDataHeader = FindResource("weempty");
	m_pBulletEmptyImage->InitDeviceObjects(pDataHeader) ;
	m_pBulletLowImage = new CINFImageEx;
	pDataHeader = FindResource("welow");
	m_pBulletLowImage->InitDeviceObjects(pDataHeader) ;
#endif

	int i; for(i=0;i<10;i++)
	{
		char buf[16];
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
		wsprintf(buf, "BR%d", i);
		m_pWeaponWarningNumberImage[i] = new CINFImageEx;
		pDataHeader = FindResource(buf);
		m_pWeaponWarningNumberImage[i]->InitDeviceObjects(  pDataHeader );						  
#endif
		wsprintf(buf, "B%d", i);
		m_pWeaponNumberImage[i] = new CINFImageEx;		// 2011. 10. 10 by jskim UI�ý��� ����
		pDataHeader = FindResource(buf);
		m_pWeaponNumberImage[i]->InitDeviceObjects(  pDataHeader ) ;
	}

	return S_OK ;
}

HRESULT CINFWeaponInfo::RestoreDeviceObjects()
{
	FLOG( "CINFWeaponInfo::RestoreDeviceObjects()" );
	m_nRightWeaponInfoPosX = g_pD3dApp->GetBackBufferDesc().Width - SIZE_WEAPON_X;
	if(m_pStImage )
		m_pStImage->RestoreDeviceObjects();
	if(m_pNdImage )
		m_pNdImage->RestoreDeviceObjects();
	if(m_pStOverHeatBar )
		m_pStOverHeatBar->RestoreDeviceObjects();
	if(m_pNdOverHeatBar )
		m_pNdOverHeatBar->RestoreDeviceObjects();
	if(m_pEmptyWeaponImage )
		m_pEmptyWeaponImage->RestoreDeviceObjects();
	if(m_pStFuelGageBar )
		m_pStFuelGageBar->RestoreDeviceObjects();
	if(m_pStFuelUnderGageBar )
		m_pStFuelUnderGageBar->RestoreDeviceObjects();
/*	if(m_pNdFuelGageBar )
		m_pNdFuelGageBar->RestoreDeviceObjects();
	if(m_pNdFuelUnderGageBar )
		m_pNdFuelUnderGageBar->RestoreDeviceObjects();
*/	if(m_pReloadImage )
		m_pReloadImage->RestoreDeviceObjects();
	if(m_pOverHeatImage )
		m_pOverHeatImage->RestoreDeviceObjects();
	if(m_pBulletEmptyImage )
		m_pBulletEmptyImage->RestoreDeviceObjects();
	if(m_pBulletLowImage )
		m_pBulletLowImage->RestoreDeviceObjects();

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	if(m_pBulletEmptyImage1 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage1->RestoreDeviceObjects();
	if(m_pBulletEmptyImage2 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage2->RestoreDeviceObjects();

	if(m_pBulletLowImage1 )			// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletLowImage1->RestoreDeviceObjects();
#endif
	int i; for(i=0;i<10;i++)
	{
		m_pWeaponNumberImage[i]->RestoreDeviceObjects();

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
		m_pWeaponWarningNumberImage[i]->RestoreDeviceObjects();									  
#endif
	}
	ChangeWeapon(1);
	ChangeWeapon(2);
	return S_OK ;
}

void CINFWeaponInfo::ChangeWeapon(int nWeapon)// nWeapon == 1 then 1�� ����, 2 then 2�� ����
{
	FLOG( "CINFWeaponInfo::ChangeWeapon(int nWeapon)" );

	if(nWeapon == 1)
	{
//		map<int, ITEM_GENERAL*>::iterator it = g_pStoreData->m_mapItemInInventory.find(POS_PROWOUT);// FIRST WEAPON
		CItemInfo *pItemInfo = g_pStoreData->FindItemInInventoryByWindowPos(POS_PROWOUT);
//		if(it != g_pStoreData->m_mapItemInInventory.end())
		if(pItemInfo)
		{
//			ITEM_GENERAL* pItem = it->second;
			char buf[16];
//			wsprintf(buf, "%08d",pItemInfo->ItemNum);	// 2005-08-23 by ispark
			wsprintf(buf, "%08d",pItemInfo->ItemInfo->SourceIndex);
			DataHeader	*  pHeader = m_pWeaponData->Find(buf);
			if(m_pStWeaponImage)
			{
				m_pStWeaponImage->InvalidateDeviceObjects();
				m_pStWeaponImage->DeleteDeviceObjects();
				SAFE_DELETE(m_pStWeaponImage);
			}
			if(pHeader)
			{
				m_pStWeaponImage = new CINFImageEx();		// 2011. 10. 10 by jskim UI�ý��� ����
				m_pStWeaponImage->InitDeviceObjects( pHeader  );
				m_pStWeaponImage->RestoreDeviceObjects();
			}
		}
		else
		{
			if(m_pStWeaponImage)
			{
				m_pStWeaponImage->InvalidateDeviceObjects();
				m_pStWeaponImage->DeleteDeviceObjects();
				SAFE_DELETE(m_pStWeaponImage);
			}
		}
	}
	else if(nWeapon == 2)
	{
//		map<int, ITEM_GENERAL*>::iterator it = g_pStoreData->m_mapItemInInventory.find(POS_WINGOUT);// SECOND WEAPON
		CItemInfo *pItemInfo = g_pStoreData->FindItemInInventoryByWindowPos(POS_WINGOUT);
//		if(it != g_pStoreData->m_mapItemInInventory.end())
		if(pItemInfo)
		{
//			ITEM_GENERAL* pItem = it->second;
			char buf[16];
//			wsprintf(buf, "%08d",pItemInfo->ItemNum);	// 2005-08-23 by ispark
			wsprintf(buf, "%08d",pItemInfo->ItemInfo->SourceIndex);
			DataHeader	*  pHeader = m_pWeaponData->Find(buf);
			if(m_pNdWeaponImage)
			{
				m_pNdWeaponImage->InvalidateDeviceObjects();
				m_pNdWeaponImage->DeleteDeviceObjects();
				SAFE_DELETE(m_pNdWeaponImage);
			}
			if(pHeader)
			{
				m_pNdWeaponImage = new CINFImageEx();			// 2011. 10. 10 by jskim UI�ý��� ����
				m_pNdWeaponImage->InitDeviceObjects( pHeader );
				m_pNdWeaponImage->RestoreDeviceObjects();
			}
		}
		else
		{
			if(m_pNdWeaponImage)
			{
				m_pNdWeaponImage->InvalidateDeviceObjects();
				m_pNdWeaponImage->DeleteDeviceObjects();
				SAFE_DELETE(m_pNdWeaponImage);
			}
		}
	}

}

HRESULT CINFWeaponInfo::DeleteDeviceObjects()
{
	FLOG( "CINFWeaponInfo::DeleteDeviceObjects()" );
	if(m_pStImage )
		m_pStImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pStImage ) ;

	if(m_pStWeaponImage )
		m_pStWeaponImage->DeleteDeviceObjects() ;
	SAFE_DELETE(m_pStWeaponImage );

	if(m_pNdImage )
		m_pNdImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pNdImage ) ;

	if(m_pNdWeaponImage )
		m_pNdWeaponImage->DeleteDeviceObjects() ;
	SAFE_DELETE(m_pNdWeaponImage );

	if(m_pStOverHeatBar )
		m_pStOverHeatBar->DeleteDeviceObjects();
	SAFE_DELETE(m_pStOverHeatBar ) ;

	if(m_pNdOverHeatBar )
		m_pNdOverHeatBar->DeleteDeviceObjects() ;
	SAFE_DELETE(m_pNdOverHeatBar );

	if(m_pEmptyWeaponImage )
		m_pEmptyWeaponImage->DeleteDeviceObjects() ;
	SAFE_DELETE(m_pEmptyWeaponImage );

	if(m_pStFuelGageBar )
		m_pStFuelGageBar->DeleteDeviceObjects();
	SAFE_DELETE(m_pStFuelGageBar );
	if(m_pStFuelUnderGageBar )
		m_pStFuelUnderGageBar->DeleteDeviceObjects();
	SAFE_DELETE(m_pStFuelUnderGageBar );
/*	if(m_pNdFuelGageBar )
		m_pNdFuelGageBar->DeleteDeviceObjects();
	SAFE_DELETE(m_pNdFuelGageBar );
	if(m_pNdFuelUnderGageBar )
		m_pNdFuelUnderGageBar->DeleteDeviceObjects();
	SAFE_DELETE(m_pNdFuelUnderGageBar );
*/	if(m_pReloadImage )
		m_pReloadImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pReloadImage );
	if(m_pOverHeatImage )
		m_pOverHeatImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pOverHeatImage );
	if(m_pBulletEmptyImage )
		m_pBulletEmptyImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pBulletEmptyImage );
	if(m_pBulletLowImage )
		m_pBulletLowImage->DeleteDeviceObjects();
	SAFE_DELETE(m_pBulletLowImage );

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	if(m_pBulletEmptyImage1 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage1->DeleteDeviceObjects();
	SAFE_DELETE(m_pBulletEmptyImage1 );
	if(m_pBulletEmptyImage2 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage2->DeleteDeviceObjects();
	SAFE_DELETE(m_pBulletEmptyImage2 );		// 2011. 10. 10 by jskim UI�ý��� ����

	if(m_pBulletLowImage1 )		
		m_pBulletLowImage1->DeleteDeviceObjects();
	SAFE_DELETE(m_pBulletLowImage1 );		// 2011. 10. 10 by jskim UI�ý��� ����
#endif
	int i; for(i=0;i<10;i++)
	{
		m_pWeaponNumberImage[i]->DeleteDeviceObjects();
		SAFE_DELETE(m_pWeaponNumberImage[i] );

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
		m_pWeaponWarningNumberImage[i]->DeleteDeviceObjects();		// 2011. 10. 10 by jskim UI�ý��� ����
		SAFE_DELETE(m_pWeaponWarningNumberImage[i] );											  
#endif
	}
	return S_OK ;
}


HRESULT CINFWeaponInfo::InvalidateDeviceObjects()
{
	FLOG( "CINFWeaponInfo::InvalidateDeviceObjects()" );
	if(m_pStImage )
		m_pStImage->InvalidateDeviceObjects() ;
	if(m_pStWeaponImage )
		m_pStWeaponImage->InvalidateDeviceObjects() ;
	if(m_pNdImage )
		m_pNdImage->InvalidateDeviceObjects() ;
	if(m_pNdWeaponImage )
		m_pNdWeaponImage->InvalidateDeviceObjects() ;
	if(m_pStOverHeatBar )
		m_pStOverHeatBar->InvalidateDeviceObjects() ;
	if(m_pNdOverHeatBar )
		m_pNdOverHeatBar->InvalidateDeviceObjects() ;
	if(m_pEmptyWeaponImage )
		m_pEmptyWeaponImage->InvalidateDeviceObjects() ;
	if(m_pStFuelGageBar )
		m_pStFuelGageBar->InvalidateDeviceObjects();
	if(m_pStFuelUnderGageBar )
		m_pStFuelUnderGageBar->InvalidateDeviceObjects();
/*	if(m_pNdFuelGageBar )
		m_pNdFuelGageBar->InvalidateDeviceObjects();
	if(m_pNdFuelUnderGageBar )
		m_pNdFuelUnderGageBar->InvalidateDeviceObjects();
*/	if(m_pReloadImage )
		m_pReloadImage->InvalidateDeviceObjects();
	if(m_pOverHeatImage )
		m_pOverHeatImage->InvalidateDeviceObjects();
	if(m_pBulletEmptyImage )
		m_pBulletEmptyImage->InvalidateDeviceObjects();
	if(m_pBulletLowImage )
		m_pBulletLowImage->InvalidateDeviceObjects();

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	if(m_pBulletEmptyImage1 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage1->InvalidateDeviceObjects();
	if(m_pBulletEmptyImage2 )		// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletEmptyImage2->InvalidateDeviceObjects();
	if(m_pBulletLowImage1 )			// 2011. 10. 10 by jskim UI�ý��� ����
		m_pBulletLowImage1->InvalidateDeviceObjects();
#endif

	int i; for(i=0;i<10;i++)
	{
		m_pWeaponNumberImage[i]->InvalidateDeviceObjects();
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
		m_pWeaponWarningNumberImage[i]->InvalidateDeviceObjects();								  
#endif
	}

	return S_OK ;
}


void CINFWeaponInfo::Tick()
{
	FLOG( "CINFWeaponInfo::Tick()" );
	if(m_fFlashTime < FLASH_TIME)
	{
		m_fFlashTime += g_pD3dApp->GetCheckElapsedTime();
	}
	else
	{
		m_fFlashTime = 0;
		m_bFlash = !m_bFlash;
	}


}
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
void CINFWeaponInfo::RenderLeftWeapon(float x, float y)		// 2011. 10. 10 by jskim UI�ý��� ����
#else						 
void CINFWeaponInfo::RenderLeftWeapon()
#endif
{
	FLOG( "CINFWeaponInfo::RenderLeftWeapon()" );
 	int nWindowPosY = g_pGameMain->m_nLeftWindowY;

	// ���������� ������ ������ �ʴ´�
	if(g_pD3dApp->m_dwGameState == _SHOP)
		return;
	// 2007-03-27 by bhsohn ������ ���� �������̽� ����
	if(g_pShuttleChild->IsObserverMode())
	{
		return;
	}
	// end 2007-03-27 by bhsohn ������ ���� �������̽� ����

//	if(m_pStImage )
//	{
//		m_pStImage->Move(m_nLeftWeaponInfoPosX, nWindowPosY);
//		m_pStImage->Render() ;
//	}
//	if(m_pStOverHeatBar)
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	if(g_pShuttleChild->m_pPrimaryWeapon)
	{
// 2008-05-29 by dgwoo ���� �������̽� ���� ��ȹ.
//		m_pStOverHeatBar->Move(m_nLeftWeaponInfoPosX+LEFT_OVERHEAT_START_X, nWindowPosY+OVERHEAT_START_Y);
////		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pD3dApp->m_pShuttleChild->m_fPrimaryWeaponActionRate, OVERHEAT_HEIGHT);
//		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pShuttleChild->m_pPrimaryWeapon->GetOverHeatRate(), OVERHEAT_HEIGHT);
//		m_pStOverHeatBar->Render();
		m_pStOverHeatBar->Move( FIRST_WEAPON_START_X - 7, FIRST_WEAPON_START_Y - 20);
//		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pD3dApp->m_pShuttleChild->m_fPrimaryWeaponActionRate, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->SetRect(0, 0, m_pStOverHeatBar->GetImgSize().x * g_pShuttleChild->m_pPrimaryWeapon->GetOverHeatRate(), OVERHEAT_HEIGHT);
		m_pStOverHeatBar->Render();
	}
	// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
	//if(m_pStWeaponImage )		// ���⸦ ������ ������
	if(g_pShuttleChild && g_pShuttleChild->m_pPrimaryWeapon)
	{
//		if(g_pD3dApp->m_pShuttleChild && g_pD3dApp->m_pShuttleChild->m_pItemPrimary )
		if(g_pShuttleChild && g_pShuttleChild->m_pPrimaryWeapon )
		{
			if(IS_PRIMARY_WEAPON_1(g_pShuttleChild->m_pPrimaryWeapon->GetRealItemInfo()->Kind))
			{
				if(LEFT_WEAPON_NUMBER == 0)
				{
					m_pBulletEmptyImage->Move( FIRST_WEAPON_START_X - 37, FIRST_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
					m_pBulletEmptyImage->Render();
					m_pBulletEmptyImage1->Move( FIRST_WEAPON_START_X - 34, FIRST_WEAPON_START_Y + 5  - m_pBulletEmptyImage->GetImgSize().y );
					m_pBulletEmptyImage1->Render();

					RenderWarningWeaponNumber(FIRST_WEAPON_FONT_X, FIRST_WEAPON_FONT_Y, LEFT_WEAPON_NUMBER);
				}
				else if( g_pShuttleChild->m_pPrimaryWeapon->IsOverHeat()) 
				{
					m_pOverHeatImage->Move( FIRST_WEAPON_START_X - 37, FIRST_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
					m_pOverHeatImage->Render();
					if( m_bFlash )
						RenderWarningWeaponNumber(FIRST_WEAPON_FONT_X, FIRST_WEAPON_FONT_Y, LEFT_WEAPON_NUMBER);
				}
				else if(LEFT_WEAPON_NUMBER < 100 && m_bFlash)//���������� ���
				{
					m_pBulletLowImage->Move( FIRST_WEAPON_START_X - 37, FIRST_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y  );
					m_pBulletLowImage->Render();					

					RenderWarningWeaponNumber(FIRST_WEAPON_FONT_X, FIRST_WEAPON_FONT_Y, LEFT_WEAPON_NUMBER);
				}
				else
				{
					// 2006-07-19 by dgwoo m_nLeftWeaponInfoPosX�߰� �ִϸ��̼ǿ� ���� �۾��� ������ ��ġ�� �������ش�.
					RenderWeaponNumber(FIRST_WEAPON_FONT_X, FIRST_WEAPON_FONT_Y, LEFT_WEAPON_NUMBER);
				}
			}
			else if(IS_PRIMARY_WEAPON_2(g_pShuttleChild->m_pPrimaryWeapon->GetRealItemInfo()->Kind))// ���� �����
			{
				float fRate = g_pShuttleChild->m_myShuttleInfo.CurrentEP/(float)g_pShuttleChild->m_myShuttleInfo.EP;
				RenderWeaponFuel( LEFT_FUEL_X, nWindowPosY, fRate );
				if(fRate == 0)
				{
					m_pBulletEmptyImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pBulletEmptyImage->Render();
				}
				else if( fRate < 0.1f)
				{
					m_pBulletLowImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pBulletLowImage->Render();
				}
// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
//				else if(g_pShuttleChild->m_pPrimaryWeapon->IsOverHeat() == FALSE)
//				{
//					m_pStWeaponImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
//					m_pStWeaponImage->Render() ;
//				}
				else//���������� ���
				{
					m_pOverHeatImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pOverHeatImage->Render() ;
				}
			}
		}		
	}
	else
	{
		m_pBulletEmptyImage->Move( FIRST_WEAPON_START_X - 37, FIRST_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
		m_pBulletEmptyImage->Render();

//		m_pEmptyWeaponImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
//		m_pEmptyWeaponImage->Render() ;
	}
#else
	if(g_pShuttleChild->m_pPrimaryWeapon)
	{
// 2008-05-29 by dgwoo ���� �������̽� ���� ��ȹ.
//		m_pStOverHeatBar->Move(m_nLeftWeaponInfoPosX+LEFT_OVERHEAT_START_X, nWindowPosY+OVERHEAT_START_Y);
////		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pD3dApp->m_pShuttleChild->m_fPrimaryWeaponActionRate, OVERHEAT_HEIGHT);
//		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pShuttleChild->m_pPrimaryWeapon->GetOverHeatRate(), OVERHEAT_HEIGHT);
//		m_pStOverHeatBar->Render();
		m_pStOverHeatBar->Move(FIRST_WEAPON_GAGE_X, FIRST_WEAPON_GAGE_Y);
//		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pD3dApp->m_pShuttleChild->m_fPrimaryWeaponActionRate, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->SetRect(0, 0, OVERHEAT_LENGTH*g_pShuttleChild->m_pPrimaryWeapon->GetOverHeatRate(), OVERHEAT_HEIGHT);
		m_pStOverHeatBar->Render();
	}
	// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
	//if(m_pStWeaponImage )		// ���⸦ ������ ������
	if(g_pShuttleChild && g_pShuttleChild->m_pPrimaryWeapon)
	{
		
//		if(g_pD3dApp->m_pShuttleChild && g_pD3dApp->m_pShuttleChild->m_pItemPrimary )
		if(g_pShuttleChild && g_pShuttleChild->m_pPrimaryWeapon )
		{
			if(IS_PRIMARY_WEAPON_1(g_pShuttleChild->m_pPrimaryWeapon->GetRealItemInfo()->Kind))
			{
				if(LEFT_WEAPON_NUMBER == 0)
				{
					m_pBulletEmptyImage->Move(FIRST_WEAPON_START_X, FIRST_WEAPON_START_Y);
					m_pBulletEmptyImage->Render();
				}
				else if( g_pShuttleChild->m_pPrimaryWeapon->IsOverHeat())
				{
					m_pOverHeatImage->Move(FIRST_WEAPON_START_X, FIRST_WEAPON_START_Y);
					m_pOverHeatImage->Render();
				}
				else if(LEFT_WEAPON_NUMBER < 100 && m_bFlash)//���������� ���
				{
					m_pBulletLowImage->Move(FIRST_WEAPON_START_X, FIRST_WEAPON_START_Y);
					m_pBulletLowImage->Render();
				}
				else
				{
					// 2006-07-19 by dgwoo m_nLeftWeaponInfoPosX�߰� �ִϸ��̼ǿ� ���� �۾��� ������ ��ġ�� �������ش�.
					RenderWeaponNumber(FIRST_WEAPON_FONT_Y, FIRST_WEAPON_FONT_X, LEFT_WEAPON_NUMBER);
				}
			}
			else if(IS_PRIMARY_WEAPON_2(g_pShuttleChild->m_pPrimaryWeapon->GetRealItemInfo()->Kind))// ���� �����
			{
				float fRate = g_pShuttleChild->m_myShuttleInfo.CurrentEP/(float)g_pShuttleChild->m_myShuttleInfo.EP;
				RenderWeaponFuel( nWindowPosY, LEFT_FUEL_X, fRate );
				if(fRate == 0)
				{
					m_pBulletEmptyImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pBulletEmptyImage->Render();
				}
				else if( fRate < 0.1f)
				{
					m_pBulletLowImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pBulletLowImage->Render();
				}
// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
//				else if(g_pShuttleChild->m_pPrimaryWeapon->IsOverHeat() == FALSE)
//				{
//					m_pStWeaponImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
//					m_pStWeaponImage->Render() ;
//				}
				else//���������� ���
				{
					m_pOverHeatImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
					m_pOverHeatImage->Render() ;
				}
			}
		}
		
	}
	else
	{
		m_pBulletEmptyImage->Move(FIRST_WEAPON_START_X, FIRST_WEAPON_START_Y);
		m_pBulletEmptyImage->Render();

//		m_pEmptyWeaponImage->Move(m_nLeftWeaponInfoPosX+3, nWindowPosY + 10);
//		m_pEmptyWeaponImage->Render() ;
	}
#endif
}

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
void CINFWeaponInfo::RenderRightWeapon(float x, float y)			// 2011. 10. 10 by jskim UI�ý��� ����
#else 
void CINFWeaponInfo::RenderRightWeapon()
#endif
{
	FLOG( "CINFWeaponInfo::RenderRightWeapon()" );
	int nWindowPosY = g_pGameMain->m_nRightWindowY;

	// ���������� ������ ������ �ʴ´�
	if(g_pD3dApp->m_dwGameState == _SHOP)
		return;
	// 2007-03-27 by bhsohn ������ ���� �������̽� ����
	if(g_pShuttleChild->IsObserverMode())
	{
		return;
	}
	// end 2007-03-27 by bhsohn ������ ���� �������̽� ����
	
//	if(m_pNdImage )
//	{
//		m_pNdImage->Move(m_nRightWeaponInfoPosX, nWindowPosY);
//		m_pNdImage->Render() ;
//	}
//	if(m_pNdOverHeatBar)
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	if(g_pShuttleChild->m_pSecondaryWeapon)
	{
//		int startX = (1.0f-g_pD3dApp->m_pShuttleChild->m_fSecondaryWeaponActionRate)*OVERHEAT_LENGTH;
		int startX = (g_pShuttleChild->m_pSecondaryWeapon->GetReattackTimeRate())*OVERHEAT_LENGTH;
		if(g_pD3dApp->m_bCharacter)
			startX = OVERHEAT_LENGTH;
		m_pStOverHeatBar->Move(SECOND_WEAPON_START_X - 13, SECOND_WEAPON_START_Y - 20);
		//m_pStOverHeatBar->SetRect(startX, 0, OVERHEAT_LENGTH, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->SetRect(0, 0, startX, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->Render();
	}
// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
//	if(m_pNdWeaponImage )		// ���⸦ ������ ������
	if(g_pShuttleChild->m_pSecondaryWeapon)
	{
		if(RIGHT_WEAPON_NUMBER == 0)
		{		
			m_pBulletLowImage1->Move( SECOND_WEAPON_START_X - 43, SECOND_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
			m_pBulletLowImage1->Render();
			m_pBulletEmptyImage2->Move( SECOND_WEAPON_START_X - 43, SECOND_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
			m_pBulletEmptyImage2->Render();	
			RenderWarningWeaponNumber(SECOND_WEAPON_FONT_X, SECOND_WEAPON_FONT_Y, RIGHT_WEAPON_NUMBER); 
		}
		else if( RIGHT_WEAPON_NUMBER < 10 && m_bFlash)
		{
			m_pBulletLowImage1->Move( SECOND_WEAPON_START_X - 43, SECOND_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y );
			m_pBulletLowImage1->Render();
			RenderWarningWeaponNumber( SECOND_WEAPON_FONT_X, SECOND_WEAPON_FONT_Y, RIGHT_WEAPON_NUMBER);
		}
		else //if(g_pD3dApp->m_pShuttleChild->m_bSecondaryWeaponAction)
		{ 
			if(RIGHT_WEAPON_NUMBER >= 0)
			{
				RenderWeaponNumber( SECOND_WEAPON_FONT_X, SECOND_WEAPON_FONT_Y, RIGHT_WEAPON_NUMBER);
			}
		}
	}
	else
	{
		m_pBulletEmptyImage2->Move( SECOND_WEAPON_START_X - 43, SECOND_WEAPON_START_Y + 5 - m_pBulletEmptyImage->GetImgSize().y);
		m_pBulletEmptyImage2->Render();
	}
#else				
	if(g_pShuttleChild->m_pSecondaryWeapon)
	{
//		int startX = (1.0f-g_pD3dApp->m_pShuttleChild->m_fSecondaryWeaponActionRate)*OVERHEAT_LENGTH;
		int startX = (g_pShuttleChild->m_pSecondaryWeapon->GetReattackTimeRate())*OVERHEAT_LENGTH;
		if(g_pD3dApp->m_bCharacter)
			startX = OVERHEAT_LENGTH;
		m_pStOverHeatBar->Move(SECOND_WEAPON_GAGE_X, SECOND_WEAPON_GAGE_Y);
		//m_pStOverHeatBar->SetRect(startX, 0, OVERHEAT_LENGTH, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->SetRect(0, 0, startX, OVERHEAT_HEIGHT);
		m_pStOverHeatBar->Render();
	}
// 2008-10-20 by dgwoo ���� �̹����� �ʿ����.
//	if(m_pNdWeaponImage )		// ���⸦ ������ ������
	if(g_pShuttleChild->m_pSecondaryWeapon)
	{

		if(RIGHT_WEAPON_NUMBER == 0)
		{
			m_pBulletEmptyImage->Move(SECOND_WEAPON_START_X, SECOND_WEAPON_START_Y);
			m_pBulletEmptyImage->Render();
		}
		else if( RIGHT_WEAPON_NUMBER < 10 && m_bFlash)
		{
			m_pBulletLowImage->Move(SECOND_WEAPON_START_X, SECOND_WEAPON_START_Y);
			m_pBulletLowImage->Render();
		}
		else //if(g_pD3dApp->m_pShuttleChild->m_bSecondaryWeaponAction)
		{
			if(RIGHT_WEAPON_NUMBER >= 0)
			{
				RenderWeaponNumber( SECOND_WEAPON_FONT_Y, SECOND_WEAPON_FONT_X, RIGHT_WEAPON_NUMBER);
			}
		}
	}
	else
	{
		m_pBulletEmptyImage->Move(SECOND_WEAPON_START_X, SECOND_WEAPON_START_Y);
		m_pBulletEmptyImage->Render();
	}

#endif
}

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
void CINFWeaponInfo::RenderWeaponFuel( int nWindowPosX, int nWindowPosY, float fRate)			// 2011. 10. 10 by jskim UI�ý��� ����
#else 
void CINFWeaponInfo::RenderWeaponFuel( int nWindowPosY, int nWindowPosX, float fRate)

#endif
{

	FLOG( "CINFWeaponInfo::RenderWeaponFuel( int nWindowPosX, int nWindowPosY,  float fRate)" );
	if(fRate>0)
	{
		m_pStFuelUnderGageBar->Move(nWindowPosX, nWindowPosY+LEFT_FUEL_Y);
		m_pStFuelUnderGageBar->Render();
		m_pStFuelGageBar->Move(nWindowPosX, nWindowPosY+LEFT_FUEL_Y);
		m_pStFuelGageBar->SetRect(0, 0, FUEL_GAGE_LENGTH*fRate, FUEL_GAGE_HEIGHT);
		m_pStFuelGageBar->Render();
	}
	else
	{
		m_pReloadImage->Move(nWindowPosX, nWindowPosY+LEFT_WEAPON_NUMBER_Y);
		m_pReloadImage->Render() ;
	}
}
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
void CINFWeaponInfo::RenderWeaponNumber( int nWindowPosX, int nWindowPosY,  int nValue)			// 2011. 10. 10 by jskim UI�ý��� ����
#else		  
void CINFWeaponInfo::RenderWeaponNumber( int nWindowPosY, int nWindowPosX, int nValue)
#endif
{
	

#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
	FLOG( "CINFWeaponInfo::RenderWeaponNumber( int nWindowPosX, int nWindowPosY, int nValue)" );  
#else								
	FLOG( "CINFWeaponInfo::RenderWeaponNumber( int nWindowPosY, int nWindowPosX, int nValue)" );
#endif
	if(nValue > 0)
	{
//		int i; for(i=0;i<5;i++) // 5 : 5�ڸ�����
//		{
//			int nNum = nValue%10;
//			m_pWeaponNumberImage[nNum]->Move(nWindowPosX+WEAPON_NUMBER_SIZE*(4-i), nWindowPosY+LEFT_WEAPON_NUMBER_Y);
//			m_pWeaponNumberImage[nNum]->Render();
//			nValue /= 10;
//		}
		int i; for(i=0;i<5;i++) // 5 : 5�ڸ�����
		{
			int nNum = nValue%10;
#ifdef C_EPSODE4_UI_CHANGE_JSKIM					        // 2011. 10. 10 by jskim UI�ý��� ����
			m_pWeaponNumberImage[nNum]->Move(nWindowPosX + ( m_pWeaponNumberImage[nNum]->GetImgSize().x - 3 ) *(4-i), nWindowPosY);
#else					 
			m_pWeaponNumberImage[nNum]->Move(nWindowPosX+WEAPON_NUMBER_SIZE*(4-i), nWindowPosY);
#endif
			m_pWeaponNumberImage[nNum]->Render();
			nValue /= 10;
		}
	}
	else
	{
//		m_pReloadImage->Move(nWindowPosX, nWindowPosY+LEFT_WEAPON_NUMBER_Y);
//		m_pReloadImage->Render() ;
	}
}
 // 2011. 10. 10 by jskim UI�ý��� ����
#ifdef C_EPSODE4_UI_CHANGE_JSKIM	
void CINFWeaponInfo::RenderWarningWeaponNumber( int nWindowPosX, int nWindowPosY, int nValue)			// 2011. 10. 10 by jskim UI�ý��� ����
{
	FLOG( "CINFWeaponInfo::RenderWarningWeaponNumber( int nWindowPosX, int nWindowPosY, int nValue)" );
	int i; for(i=0;i<5;i++) // 5 : 5�ڸ�����
	{
		int nNum = nValue%10;
		m_pWeaponWarningNumberImage[nNum]->Move(nWindowPosX + ( m_pWeaponNumberImage[nNum]->GetImgSize().x - 3 ) *(4-i), nWindowPosY);
		m_pWeaponWarningNumberImage[nNum]->Render();
		nValue /= 10;
	}
}
// end 2011. 10. 10 by jskim UI�ý��� ����
#endif

int CINFWeaponInfo::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	FLOG( "CINFWeaponInfo::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)" );
	return INF_MSGPROC_NORMAL;
}
