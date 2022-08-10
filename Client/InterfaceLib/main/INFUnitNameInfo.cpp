// INFUnitNameInfo.cpp: implementation of the CINFUnitNameInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "INFUnitNameInfo.h"
#include "chatmovedata.h"
#include "AtumApplication.h"
#include "INFTarget.h"
#include "EnemyData.h"
#include "INFCommunity.h"
#include "INFCommunityGuild.h"
#include "INFImage.h"
#include "GameDataLast.h"
#include "SceneData.h"
#include "ShuttleChild.h"
#include "CharacterChild.h"				// 2005-07-21 by ispark
#include "INFGameMain.h"
#include "Interface.h"
#include "Camera.h"
#include "dxutil.h"
#include "INFGameMain.h"
#include "INFGameMainChat.h"
#include "D3DHanFont.h"
#include "AbuseFilter.h"
#include "Chat.h"
#include "MonsterData.h"
#include "AbuseFilter.h"
#include "TutorialSystem.h"
#include "INFImageEx.h"								  // 2011. 10. 10 by jskim UI�ý��� ����

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define DEFAULT_RENDER_DISTANCE		1500.0f//100.0f//600.0f
#define CHARACTER_RENDER_DISTANCE	1000.0f//600.0f

#define ID_FRAME_START_Y			27//-(����)
#define ID_NAME_START_Y				40//-
#define ID_NAME_START_X				27
#define ID_NAME_CENTER_X			60
#define ID_CHAT_START_X				106//-
#define ID_CHAT_START_Y				68//-
#define ID_CHAT_LINE_HEIGHT			17

#define ID_PARTY_HP_SIZE_X			93
#define ID_PARTY_HP_SIZE_Y			3
#define ID_PARTY_HP_START_X			25
#define ID_PARTY_HP_START_Y			26//-

#define ID_PARTY_EP_SIZE_X			96
#define ID_PARTY_EP_SIZE_Y			2
#define ID_PARTY_EP_START_X			22
#define ID_PARTY_EP_START_Y			22//-

#define ID_MONSTER_HP_SIZE_X			93
#define ID_MONSTER_HP_SIZE_Y			3
#define ID_MONSTER_HP_START_X			25
#define ID_MONSTER_HP_START_Y			26//-

#define ID_MENT_Y_POSITION				62
#define ID_MENT_GUILD_MARK_POSITION_X	33
#define ID_MENT_GUILD_MENT_POSITION_X	38

#define ID_CHAT_BALON_TLH				6
#define ID_CHAT_BALON_TLW				8
#define ID_CHAT_BALON_TMH				6
#define ID_CHAT_BALON_TMW				1
#define ID_CHAT_BALON_TRH				6
#define ID_CHAT_BALON_TRW				6

#define ID_CHAT_BALON_MLH				1
#define ID_CHAT_BALON_MLW				8
#define ID_CHAT_BALON_MMH				1
#define ID_CHAT_BALON_MMW				1
#define ID_CHAT_BALON_MRH				1
#define ID_CHAT_BALON_MRW				6

#define ID_CHAT_BALON_BLH				6
#define ID_CHAT_BALON_BLW				8
#define ID_CHAT_BALON_BMH				6
#define ID_CHAT_BALON_BMW				1
#define ID_CHAT_BALON_BRH				6
#define ID_CHAT_BALON_BRW				6

#define ID_CHAT_SHUTTLE					1
#define ID_CHAT_ENEMY					2
#define ID_CHAT_MONSTER					3

#define ID_CHAT_VIEW_COUNT				220 // APP�� ���� ����

// 2007-02-28 by bhsohn �ν��� ���� ID��ġ ������
#define	UNITNAME_POS_X					(g_pD3dApp->GetBackBufferDesc().Width/2)
#define	UNITNAME_POS_Y					(g_pD3dApp->GetBackBufferDesc().Height/2 - 2*TARGET_MOUSE_SCALE)
// end 2007-02-28 by bhsohn �ν��� ���� ID��ġ ������

CINFUnitNameInfo::CINFUnitNameInfo(CAtumNode* pParent)
{
	FLOG( "CINFUnitNameInfo(CAtumNode* pParent)" );
	m_pParent = pParent;

//	m_pUnitInfo = NULL;
//	m_pPartyUnitInfo = NULL;
//	m_pMonsterInfo = NULL;

//	m_pPartyUnitHP = NULL;
//	m_pPartyUnitEP = NULL;
//	m_pMonsterHP = NULL;
//	m_pUp = NULL;
//	m_pDown = NULL;
	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{
		m_pBalonChat[i] = NULL;
	}

	m_fRenderDistance = DEFAULT_RENDER_DISTANCE;
	nOldx = 0;
	nOldy = 0;
	m_pFontMent = NULL;
	memset(m_strChatFullLen, 0x00, 1024);

	// 2007-02-23 by bhsohn ID�� �ڷ� �и��� ���� ó��
	memset(&m_ptUnitNameFirst, 0x00, sizeof(POINT));	// ó����ġ	

	// 2013-03-06 by bhsohn ���� ���� �ý���
	m_pImageRtnUserMark = NULL;
	// END 2013-03-06 by bhsohn ���� ���� �ý���
}

CINFUnitNameInfo::~CINFUnitNameInfo()
{
	FLOG( "~CINFUnitNameInfo()" );
//	SAFE_DELETE(m_pUnitInfo);
//	SAFE_DELETE(m_pPartyUnitInfo);
//	SAFE_DELETE(m_pMonsterInfo);
//
//	SAFE_DELETE(m_pPartyUnitHP);
//	SAFE_DELETE(m_pPartyUnitEP);
//	SAFE_DELETE(m_pMonsterHP);
//	SAFE_DELETE(m_pUp);
//	SAFE_DELETE(m_pDown);
	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{
		SAFE_DELETE(m_pBalonChat[i]);
	}
	
	SAFE_DELETE(m_pFontMent);
	// 2013-03-06 by bhsohn ���� ���� �ý���
	SAFE_DELETE(m_pImageRtnUserMark);
	// END 2013-03-06 by bhsohn ���� ���� �ý���

}


HRESULT CINFUnitNameInfo::InitDeviceObjects()
{
	FLOG( "CINFUnitNameInfo::InitDeviceObjects()" );
	DataHeader	* pDataHeader ;

//		m_pUnitInfo = new CINFImage;
//	pDataHeader = FindResource("USER_ID");
//	m_pUnitInfo->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pPartyUnitInfo = new CINFImage;
//	pDataHeader = FindResource("PARTY_ID");
//	m_pPartyUnitInfo->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pMonsterInfo = new CINFImage;
//	pDataHeader = FindResource("MOB_ID");
//	m_pMonsterInfo->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pPartyUnitHP = new CINFImage;
//	pDataHeader = FindResource("PARTY_HP");
//	m_pPartyUnitHP->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pPartyUnitEP = new CINFImage;
//	pDataHeader = FindResource("PARTY_EP");
//	m_pPartyUnitEP->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pMonsterHP = new CINFImage;
//	pDataHeader = FindResource("MOB_HP");
//	m_pMonsterHP->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pUp = new CINFImage;
//	pDataHeader = FindResource("ID_UP");
//	m_pUp->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;
//
//		m_pDown = new CINFImage;
//	pDataHeader = FindResource("ID_DOWN");
//	m_pDown->InitDeviceObjects(pDataHeader->m_pData,pDataHeader->m_DataSize) ;

	char buf[16];
	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{		
		memset(buf, 0x00, 16);		
		wsprintf(buf,"c_bal%d",i);
		
		m_pBalonChat[i] = new CINFImageEx;
		pDataHeader = FindResource(buf);
		m_pBalonChat[i]->InitDeviceObjects(pDataHeader) ;		
	}

	m_pFontMent = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE,  FALSE,512,32);
	m_pFontMent->InitDeviceObjects(g_pD3dDev);

	// 2013-03-06 by bhsohn ���� ���� �ý���
#ifdef SC_ITEM_EVENT_RETURN_USER_BCKIM_BHSOHN
	{
		memset(buf, 0x00, 16);		
		wsprintf(buf,"gr_re");
		
		pDataHeader = FindResource(buf);		
		if(pDataHeader && (NULL == m_pImageRtnUserMark ))
		{
			m_pImageRtnUserMark = new CINFImageEx;
			m_pImageRtnUserMark->InitDeviceObjects(pDataHeader);
		}
		
	}
#endif
	// END 2013-03-06 by bhsohn ���� ���� �ý���
	return S_OK ;
}

HRESULT CINFUnitNameInfo::RestoreDeviceObjects()
{
	FLOG( "CINFUnitNameInfo::RestoreDeviceObjects()" );
//	m_pUnitInfo->RestoreDeviceObjects();
//	m_pPartyUnitInfo->RestoreDeviceObjects();
//	m_pMonsterInfo->RestoreDeviceObjects();
//	m_pPartyUnitHP->RestoreDeviceObjects();
//	m_pPartyUnitEP->RestoreDeviceObjects();
//	m_pMonsterHP->RestoreDeviceObjects();
//	m_pUp->RestoreDeviceObjects();
//	m_pDown->RestoreDeviceObjects();
	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{
		m_pBalonChat[i]->RestoreDeviceObjects();
	}
	
	m_pFontMent->RestoreDeviceObjects();
	// 2013-03-06 by bhsohn ���� ���� �ý���
	if(m_pImageRtnUserMark )
	{
		m_pImageRtnUserMark ->RestoreDeviceObjects();
	}
	// END 2013-03-06 by bhsohn ���� ���� �ý���
	return S_OK ;
}

HRESULT CINFUnitNameInfo::DeleteDeviceObjects()
{
	FLOG( "CINFUnitNameInfo::DeleteDeviceObjects()" );
//	m_pUnitInfo->DeleteDeviceObjects();
//	m_pPartyUnitInfo->DeleteDeviceObjects();
//	m_pMonsterInfo->DeleteDeviceObjects();
//	m_pPartyUnitHP->DeleteDeviceObjects();
//	m_pPartyUnitEP->DeleteDeviceObjects();
//	m_pMonsterHP->DeleteDeviceObjects();
//	m_pUp->DeleteDeviceObjects();
//	m_pDown->DeleteDeviceObjects();
	m_pFontMent->DeleteDeviceObjects();

//	SAFE_DELETE(m_pUnitInfo );
//	SAFE_DELETE(m_pPartyUnitInfo );
//	SAFE_DELETE(m_pMonsterInfo );
//	SAFE_DELETE(m_pPartyUnitHP );
//	SAFE_DELETE(m_pPartyUnitEP );
//	SAFE_DELETE(m_pMonsterHP );
//	SAFE_DELETE(m_pUp );
//	SAFE_DELETE(m_pDown );
	SAFE_DELETE(m_pFontMent );

	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{
		m_pBalonChat[i]->DeleteDeviceObjects();
		SAFE_DELETE(m_pBalonChat[i]);
	}
	// 2013-03-06 by bhsohn ���� ���� �ý���
	if(m_pImageRtnUserMark )
	{		 
		m_pImageRtnUserMark->DeleteDeviceObjects();
		SAFE_DELETE(m_pImageRtnUserMark);
	}
	// END 2013-03-06 by bhsohn ���� ���� �ý���

	return S_OK ;
}

HRESULT CINFUnitNameInfo::InvalidateDeviceObjects()
{
	FLOG( "CINFUnitNameInfo::InvalidateDeviceObjects()" );
//	m_pUnitInfo->InvalidateDeviceObjects();
//	m_pPartyUnitInfo->InvalidateDeviceObjects();
//	m_pMonsterInfo->InvalidateDeviceObjects();
//	m_pPartyUnitHP->InvalidateDeviceObjects();
//	m_pPartyUnitEP->InvalidateDeviceObjects();
//	m_pMonsterHP->InvalidateDeviceObjects();
//	m_pUp->InvalidateDeviceObjects();
//	m_pDown->InvalidateDeviceObjects();
	int i; for(i=0; i<NAME_INFO_BALON_CHAT; i++)
	{
		m_pBalonChat[i]->InvalidateDeviceObjects();
	}

	m_pFontMent->InvalidateDeviceObjects();
	// 2013-03-06 by bhsohn ���� ���� �ý���
	if(m_pImageRtnUserMark )
	{		 
		m_pImageRtnUserMark->InvalidateDeviceObjects();
	}
	// END 2013-03-06 by bhsohn ���� ���� �ý���
	return S_OK ;
}

void CINFUnitNameInfo::Tick()
{
	FLOG( "CINFUnitNameInfo::Tick()" );


}

// 2013-03-06 by bhsohn ���� ���� �ý���
// void CINFUnitNameInfo::RenderCharacterInfo(int x, int y, CChatMoveData* pChatData, 
// 										   char* strName, BOOL bShowHP, float fHP, 
// 										   int nGuildUniqueNumber, int nCharacterUniqueNumber, char *strMent, DWORD dwNameColor)
void CINFUnitNameInfo::RenderCharacterInfo(int x, int y, CChatMoveData* pChatData, 
										   char* strName, BOOL bShowHP, float fHP, 
										   int nGuildUniqueNumber, int nCharacterUniqueNumber, char *strMent, DWORD dwNameColor,
										   BYTE bRtnUser)
{
	FLOG( "CINFUnitNameInfo::RenderCharacterInfo(int x, int y, ..." );

	char buff[256];
	memset(&buff, 0x00, 256);
	if(bShowHP && g_pD3dApp->m_pInterface) 
	{
		g_pD3dApp->m_pInterface->m_pTarget->RenderHP(x, y, fHP); 
	}

//	pChatData->Render( x - (strlen(strName)*3),	y - NAME_FROM_MOUSE_CENTER_Y );
	// 2005-05-13 by jschoi -  ���̵� �� �߰�
//	pChatData->Render( x - (strlen(strName)*3),	y - DISTANCE_FROM_MOUSE_CENTER_Y , dwNameColor);
	// 2005-08-01 by ispark
	// ���̵� ��ǥ Y�� ������ ���� ����
	
	MSG_IC_GUILD_GET_GUILD_INFO_OK * GuildTemp = g_pGameMain->m_pCommunity->GetGuild()->GetGuildInfo();

//	int	nMarkRenderXPos = 0;
	if(nGuildUniqueNumber != 0 )
	{
		// ��� ��ũ ������
		// 2006-01-12 by ispark, ���� nMarkRenderXPos �Ⱦ���.
//		if(GuildTemp == NULL || GuildTemp->GuildUniqueNumber != nGuildUniqueNumber)
//		{
//			nMarkRenderXPos = ID_MENT_GUILD_MENT_POSITION_X;
//		}		
//		else if( 0 ==strcmp(g_pGameMain->m_pChat->m_strMyMent, strMent) && 
//			GuildTemp->GuildCommanderUniqueNumber == g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber)
//		{
//			nMarkRenderXPos = ID_MENT_GUILD_MENT_POSITION_X-4;
//		}
//		else if(GuildTemp->GuildUniqueNumber == nGuildUniqueNumber || 0 ==strcmp(g_pGameMain->m_pChat->m_strMyMent, strMent))
//		{
//			nMarkRenderXPos = ID_MENT_GUILD_MENT_POSITION_X+9;
//		}
		g_pGameMain->m_pCommunity->GetGuild()->RenderGuildMark( x, y - 10, nGuildUniqueNumber, nCharacterUniqueNumber );
	}

	if(strlen(strMent) > 0)
	{
		// ��Ʈ ������
		char buf[2][512];
		int temp,temp2;
		memset(buf, 0x00, 512*2);		
		strncpy( buf[0], strMent, strlen(strMent));
		// 2006-04-13 by ispark
		g_pD3dApp->CheckReadyStringFiltering(buf[0], &temp, &temp2);
//		g_pD3dApp->m_pAbuseFilter->AbuseFiltering(buf[0],&temp,&temp2);
		strncpy( buf[1], buf[0], strlen(buf[0]));
		sprintf(buff, "\\w:%s", buf[1]);

//		m_pFontMent->DrawText( x-(strlen(strName)*3)+nMarkRenderXPos,
//				y - ID_GUILD_MARK_START_Y-5,GUI_FONT_COLOR, buff);
//		g_pGameMain->SetMentMessage(x-(strlen(strName)*3)+nMarkRenderXPos, y - ID_GUILD_MARK_START_Y-5, buff);
	}

	// 2006-02-10 by ispark, ���� ���� ��������
	if(pChatData)
	{
		int sizeX = pChatData->m_vecFontInput[0]->GetStringSize(strName).cx;
		int nCharacterNameX = sizeX/2;

		// 2013-03-06 by bhsohn ���� ���� �ý���
		int nRtnUserStartX = x - nCharacterNameX + sizeX + 4;		
		// END 2013-03-06 by bhsohn ���� ���� �ý���

		pChatData->Render(x - nCharacterNameX, y - 10, dwNameColor);
		if(strlen(buff) > 0)
		{
			g_pGameMain->SetMentMessage(x - nCharacterNameX + sizeX + 2, y - 10, buff);

			// 2013-03-06 by bhsohn ���� ���� �ý���			
			if(bRtnUser)
			{
				// ���� ���̸� �������� �Լ��� CDC�� �̿��Ͽ� ������ ������ ������ ó���� �Ͽ���.
				nRtnUserStartX += g_pGameMain->GetMentMessageSize(buff);
			}
			// END 2013-03-06 by bhsohn ���� ���� �ý���
		}
		// 2013-03-06 by bhsohn ���� ���� �ý���
		if(bRtnUser)
		{
			RenderRtnUserMark(nRtnUserStartX, y - 8);			
		}
		// END 2013-03-06 by bhsohn ���� ���� �ý���
	}
}

// 2013-03-06 by bhsohn ���� ���� �ý���
void CINFUnitNameInfo::RenderRtnUserMark(int ntartX, int ntartY)
{
#ifdef SC_ITEM_EVENT_RETURN_USER_BCKIM_BHSOHN
	if(!m_pImageRtnUserMark)
	{
		return;	
	}
	m_pImageRtnUserMark->Move(ntartX, ntartY);
	m_pImageRtnUserMark->Render();
#endif
}

void CINFUnitNameInfo::Render()
{
	FLOG( "CINFUnitNameInfo::Render()" );
	// �ڽ� ĳ������ ä�� ���� ǥ��
	int nScreenX = g_pShuttleChild->m_nObjScreenX;
	int nScreenY = g_pShuttleChild->m_nObjScreenY;
	int nScreenW = g_pShuttleChild->m_nObjScreenW;

	// 2005-04-08 by jschoi - Tutorial
	if( g_pTutorial->IsTutorialMode() == FALSE
		&& !g_pShuttleChild->IsOperAndObser()
		&& !g_pShuttleChild->IsOperation())
	{
		if(	nScreenX > 0 &&
			nScreenX < g_pD3dApp->GetBackBufferDesc().Width &&
			nScreenY > 0 &&
			nScreenY < g_pD3dApp->GetBackBufferDesc().Height &&
			nScreenW > 0)
		{
			// 2006-07-28 by ispark, ���� �̸�
			int nBazaarW = 0;
			int nBazaarH = 0;
			int nChatDataH = 0;
			if(g_pCharacterChild && g_pCharacterChild->m_pMoveChatShop)
			{
				if(g_pD3dApp->m_pShuttleChild->m_pMoveChat->m_pChild)
				{
					nChatDataH = 0;
					nBazaarW = g_pCharacterChild->m_pMoveChatShop->m_nSizeW;
					nBazaarH = g_pCharacterChild->m_pMoveChatShop->m_nSizeH;
				}
				else
				{
					nChatDataH = 16;
				}
			}

			if(g_pD3dApp->m_pShuttleChild->m_pMoveChat->m_pChild)
			{
				CChatMoveData * pChatData = (CChatMoveData *)g_pD3dApp->m_pShuttleChild->m_pMoveChat->m_pChild;
				
				////////////////////////////////////////////////////////
				// ä�� ��� �߰�
				int nChatLen = strlen(m_strChatFullLen);
				int nChatMax = 0;		
				//
				////////////////////////////////////////////////////////
				
				int count = 0;
				if(pChatData)
				{
					pChatData->Render(g_pD3dApp->m_pShuttleChild->m_nObjScreenX,
						g_pD3dApp->m_pShuttleChild->m_nObjScreenY - nBazaarH - nChatDataH);
				}
			}
			else
			{
				if( g_pCamera->GetCamType() != CAMERA_TYPE_FPS && 
					g_pShuttleChild->m_bAttackMode != _SIEGE &&
					g_pD3dApp->m_dwGameState != _SHOP)
				{
					DWORD dwShuttleNameColor = GetNameColor(g_pShuttleChild->m_byCityWarTeamType, g_pShuttleChild->m_myShuttleInfo.Race);
					(abs(nOldx-nScreenX) < 3) ? nScreenX = nOldx : nOldx = nScreenX;
					(abs(nOldy-nScreenY) < 3) ? nScreenY = nOldy : nOldy = nScreenY;

					// 2007-02-23 by bhsohn ID�� �ڷ� �и��� ���� ó��
					if( 0 == m_ptUnitNameFirst.x && 0 == m_ptUnitNameFirst.y
						&& (FALSE == g_pD3dApp->IsMyShuttleCharacter())	// 2007-07-27 by bhsohn ���̵� �ڷ� �и��� ���� ó��
						&& BOOSTER_TYPE_MIN == g_pShuttleChild->m_nBooster)
					{
						int nTxtLen = strlen(g_pShuttleChild->m_myShuttleInfo.CharacterName);
						if(nTxtLen > 0)
						{
							m_ptUnitNameFirst.x = UNITNAME_POS_X - nTxtLen*TARGET_MOUSE_SCALE;	
							m_ptUnitNameFirst.y = UNITNAME_POS_Y;
						}						
					}
					
					// ī�޶� ���� ����?					
					if(TRUE == g_pCamera->m_bIsCamControl 
						//&& BOOSTER_TYPE_MAX == g_pShuttleChild->m_nBooster
						&& (FALSE == g_pD3dApp->IsMyShuttleCharacter())	// 2007-07-27 by bhsohn ���̵� �ڷ� �и��� ���� ó��
						&& (0 != m_ptUnitNameFirst.x && 0 != m_ptUnitNameFirst.y))
					{
						nScreenX = m_ptUnitNameFirst.x;
						nScreenY = m_ptUnitNameFirst.y;						
					}			
					// 2007-08-28 by dgwoo ��� ��忡�� ���̵� ��ġ�� ���ݾ� ���� �ø���.
					if(FALSE == g_pD3dApp->IsMyShuttleCharacter())
					{
						nScreenY -= 30;
					}
					// end 2007-02-23 by bhsohn ID�� �ڷ� �и��� ���� ó��

					// 2008-02-26 by bhsohn ���� �Ʒ��� ���� ���� ����
					char szCharName[SIZE_MAX_ARENA_FULL_NAME];
					STRNCPY_MEMSET(szCharName, g_pShuttleChild->m_myShuttleInfo.CharacterName, SIZE_MAX_ARENA_FULL_NAME);
					// ���� �̸� ����
					g_pD3dApp->ConevertArenaRenderUserName(g_pD3dApp->GetArenaState(), szCharName);
					
					RenderCharacterInfo( nScreenX, 
										 nScreenY, 
										 (CChatMoveData *)g_pShuttleChild->m_pIDChat->m_pChild, 
										 //g_pShuttleChild->m_myShuttleInfo.CharacterName,
										 szCharName,
										 FALSE,
										 0,
										 g_pShuttleChild->m_myShuttleInfo.GuildUniqueNumber,
										 g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber,
										 g_pGameMain->m_pChat->m_strMyMent,
										 dwShuttleNameColor,
										 g_pShuttleChild->GetRtnGameUser());// 2013-03-06 by bhsohn ���� ���� �ý���
				}
			}

			if(g_pCharacterChild->m_pMoveChatShop)
			{
				g_pCharacterChild->m_pMoveChatShop->Render(g_pD3dApp->m_pShuttleChild->m_nObjScreenX, g_pD3dApp->m_pShuttleChild->m_nObjScreenY - nChatDataH);
			}
		}
		else
		{
			// 2007-02-23 by bhsohn ID�� �ڷ� �и��� ���� ó��
			if( g_pCamera->GetCamType() != CAMERA_TYPE_FPS && 
					g_pShuttleChild->m_bAttackMode != _SIEGE &&
					g_pD3dApp->m_dwGameState != _SHOP)
			{
				if(TRUE == g_pCamera->m_bIsCamControl 
					//&& (BOOSTER_TYPE_MAX == g_pShuttleChild->m_nBooster)
					&& (FALSE == g_pD3dApp->IsMyShuttleCharacter())	// 2007-07-27 by bhsohn ���̵� �ڷ� �и��� ���� ó��
					&& (0 != m_ptUnitNameFirst.x && 0 != m_ptUnitNameFirst.y))
				{
					DWORD dwShuttleNameColor = GetNameColor(g_pShuttleChild->m_byCityWarTeamType, g_pShuttleChild->m_myShuttleInfo.Race);
					// ī�޶� ���� ����?
					nScreenX = m_ptUnitNameFirst.x;
					nScreenY = m_ptUnitNameFirst.y;//

					// 2007-08-28 by dgwoo ��� ��忡�� ���̵� ��ġ�� ���ݾ� ���� �ø���.
					if(FALSE == g_pD3dApp->IsMyShuttleCharacter())
					{
						nScreenY -= 30;
					}
					// 2008-02-26 by bhsohn ���� �Ʒ��� ���� ���� ����
					char szCharName[SIZE_MAX_ARENA_FULL_NAME];
					STRNCPY_MEMSET(szCharName, g_pShuttleChild->m_myShuttleInfo.CharacterName, SIZE_MAX_ARENA_FULL_NAME);
					// ���� �̸� ����
					g_pD3dApp->ConevertArenaRenderUserName(g_pD3dApp->GetArenaState(), szCharName);
					
					RenderCharacterInfo( nScreenX, 
										 nScreenY, 
										 (CChatMoveData *)g_pShuttleChild->m_pIDChat->m_pChild, 
										 //g_pShuttleChild->m_myShuttleInfo.CharacterName,
										 szCharName,
										 FALSE,
										 0,
										 g_pShuttleChild->m_myShuttleInfo.GuildUniqueNumber,
										 g_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber,
										 g_pGameMain->m_pChat->m_strMyMent,
										 dwShuttleNameColor,
										 g_pShuttleChild->GetRtnGameUser());// 2013-03-06 by bhsohn ���� ���� �ý���

				}
				
			}
			// end 2007-02-23 by bhsohn ID�� �ڷ� �и��� ���� ó��
		}
	}
	
	// Ÿ ĳ���� ���̵�,ä�� ǥ��
	CVecEnemyIterator itEnemy = g_pD3dApp->m_pScene->m_vecEnemyRenderList.begin();
	while(itEnemy != g_pD3dApp->m_pScene->m_vecEnemyRenderList.end())
	{
		// 2006-08-23 by ispark, ����� �� �̸� ǥ�� �Ÿ� ����
		float fRenderDistance = DEFAULT_RENDER_DISTANCE;
		if((*itEnemy)->m_bEnemyCharacter)
		{
			fRenderDistance = CHARACTER_RENDER_DISTANCE;
		}
		if( IS_VALID_CLIENT_INDEX((*itEnemy)->m_infoCharacter.CharacterInfo.ClientIndex) && 
			D3DXVec3Length(&((*itEnemy)->m_vPos-g_pD3dApp->m_pShuttleChild->m_vPos)) < fRenderDistance &&
			*itEnemy != g_pD3dApp->m_pShuttleChild->m_pOrderTarget && // Target�� CINFTarget���� ������
			*itEnemy != g_pD3dApp->m_pShuttleChild->m_pTarget)
		{
			// 2006-11-28 by dgwoo, ���� ó���� ���� ó��
			// �����̸鼭 ����� �����̸� ĳ���� �� ǥ�� ����
			if((*itEnemy)->m_nAlphaValue == SKILL_OBJECT_ALPHA_OTHER_INFLUENCE && 
				(!IsInfluenceCharacter(g_pShuttleChild->m_myShuttleInfo.InfluenceType, (*itEnemy)->m_infoCharacter.CharacterInfo.InfluenceType) ||	// ����� �̸�
				(*itEnemy)->IsPkEnable()))
			{
				itEnemy++;
				continue;
			}

			CChatMoveData * pChatData = (CChatMoveData *)(*itEnemy)->m_pMoveChat->m_pChild;
			int count = 0;
			if( (*itEnemy)->m_nObjScreenX > 0 && (*itEnemy)->m_nObjScreenX < g_pD3dApp->GetBackBufferDesc().Width &&
				(*itEnemy)->m_nObjScreenY > 0 && (*itEnemy)->m_nObjScreenY < g_pD3dApp->GetBackBufferDesc().Height &&
				(*itEnemy)->m_nObjScreenW > 0)
			{
				// 2006-07-28 by ispark, ���� �̸�
				int nBazaarW = 0;
				int nBazaarH = 0;
				int nChatDataH = 0;
				if((*itEnemy)->m_pMoveChatShop)
				{
					if(pChatData)
					{
						nChatDataH = 0;
						nBazaarW = (*itEnemy)->m_pMoveChatShop->m_nSizeW;
						nBazaarH = (*itEnemy)->m_pMoveChatShop->m_nSizeH;
					}
					else
					{
						nChatDataH = 16;
					}
				}
				
				if(pChatData)
				{
					
					pChatData->Render(	(*itEnemy)->m_nObjScreenX,
										(*itEnemy)->m_nObjScreenY - nBazaarH - nChatDataH);
				}
				else
				{
					DWORD dwEnemyNameColor = GetInfluenceColor((*itEnemy)->m_infoCharacter.CharacterInfo.InfluenceType, (*itEnemy)->m_infoCharacter.CharacterInfo.Race);
//					DWORD dwEnemyNameColor = GetNameColor((*itEnemy)->m_infoCharacter.CharacterInfo.CityWarTeamType);
					// 2006-01-13 by ispark, ���� ĳ������ �̸� ��� Y���� �ٸ��� �ߴ�.
					int nScreenY = (*itEnemy)->m_nObjScreenY - 5;
					if((*itEnemy)->m_bEnemyCharacter == FALSE)
						nScreenY -= 10;

					if( (*itEnemy)->m_nPartyID != 0)//��Ƽ
					{
						float fRight = (float)(*itEnemy)->m_infoCharacter.CurrentHP/(float)(*itEnemy)->m_infoCharacter.HP;
						
						// 2008-02-26 by bhsohn ���� �Ʒ��� ���� ���� ����
						char szCharName[SIZE_MAX_ARENA_FULL_NAME];
						STRNCPY_MEMSET(szCharName, (*itEnemy)->m_infoCharacter.CharacterInfo.CharacterName, SIZE_MAX_ARENA_FULL_NAME);
						// ���� �̸� ����
						g_pD3dApp->ConevertArenaRenderUserName(g_pD3dApp->GetArenaState(), szCharName);

						RenderCharacterInfo( (*itEnemy)->m_nObjScreenX, 
											 nScreenY, 
											 (CChatMoveData *)(*itEnemy)->m_pIDChat->m_pChild, 
											 //(*itEnemy)->m_infoCharacter.CharacterInfo.CharacterName,
											 szCharName,
											 TRUE,
											 fRight, 
											 (*itEnemy)->m_infoCharacter.CharacterInfo.GuildUniqueNumber,
											 (*itEnemy)->m_infoCharacter.CharacterInfo.CharacterUniqueNumber,
											 (*itEnemy)->m_infoCharacter.CharacterInfo.szCharacterMent,
											 dwEnemyNameColor,
											 (*itEnemy)->GetRtnGameUser());// 2013-03-06 by bhsohn ���� ���� �ý���
					}
					else
					{
						// 2007-05-17 by bhsohn ������Ʈ �ڿ� �������� �� ���� ó �˻� ó��
						// ���� Ÿ�� ��ų� ���̰� ������ 
						if((*itEnemy)->IsCheckObjectShow())
						{
							// 2008-02-26 by bhsohn ���� �Ʒ��� ���� ���� ����
							char szCharName[SIZE_MAX_ARENA_FULL_NAME];
							STRNCPY_MEMSET(szCharName, (*itEnemy)->m_infoCharacter.CharacterInfo.CharacterName, SIZE_MAX_ARENA_FULL_NAME);
							// ���� �̸� ����
							g_pD3dApp->ConevertArenaRenderUserName(g_pD3dApp->GetArenaState(), szCharName);
							
							RenderCharacterInfo( (*itEnemy)->m_nObjScreenX, 
											 nScreenY, 
											 (CChatMoveData *)(*itEnemy)->m_pIDChat->m_pChild, 
											 //(*itEnemy)->m_infoCharacter.CharacterInfo.CharacterName,
											 szCharName,
											 FALSE,
											 0,
											 (*itEnemy)->m_infoCharacter.CharacterInfo.GuildUniqueNumber,
											 (*itEnemy)->m_infoCharacter.CharacterInfo.CharacterUniqueNumber,
											 (*itEnemy)->m_infoCharacter.CharacterInfo.szCharacterMent,
											 dwEnemyNameColor,
											 (*itEnemy)->GetRtnGameUser());// 2013-03-06 by bhsohn ���� ���� �ý���);							
						}						
					}
				}

				if((*itEnemy)->m_pMoveChatShop)
				{
					(*itEnemy)->m_pMoveChatShop->Render((*itEnemy)->m_nObjScreenX, (*itEnemy)->m_nObjScreenY - nChatDataH);
				}
			}
		}
		itEnemy++;
	}


	// 2009. 09. 18 by ckPark ���Ǵ�Ƽ �ʵ� HP�� ���� ���� ��ȭ
	// ���� ��ȭ ��ǳ�� ������ �ڵ�
	CVecMonsterIterator itMonster = g_pD3dApp->m_pScene->m_vecMonsterRenderList.begin();
	while(itMonster != g_pD3dApp->m_pScene->m_vecMonsterRenderList.end())
	{
		// ��ǳ�� ���� �Ÿ�
		float fRenderDistance = DEFAULT_RENDER_DISTANCE;

		if( IS_MONSTER_CLIENT_INDEX( (*itMonster)->m_info.MonsterIndex)
			&& D3DXVec3Length(&((*itMonster)->m_vPos-g_pD3dApp->m_pShuttleChild->m_vPos)) < fRenderDistance
			&& (CChatMoveData *)(*itMonster)->m_pMoveChat->m_pChild )
		{
			
			int count = 0;
			if( (*itMonster)->m_nObjScreenX > 0 && (*itMonster)->m_nObjScreenX < g_pD3dApp->GetBackBufferDesc().Width &&
				(*itMonster)->m_nObjScreenY > 0 && (*itMonster)->m_nObjScreenY < g_pD3dApp->GetBackBufferDesc().Height &&
				(*itMonster)->m_nObjScreenW > 0)
			{
				((CChatMoveData *)(*itMonster)->m_pMoveChat->m_pChild)->Render(	(*itMonster)->m_nObjScreenX, (*itMonster)->m_nObjScreenY - 16 );
			}
		}
		
		++itMonster;
	}

	// end 2009. 09. 18 by ckPark ���Ǵ�Ƽ �ʵ� HP�� ���� ���� ��ȭ
}

void CINFUnitNameInfo::RenderChatBalon(int x, int y, int cx, int cy)
{
	FLOG( "CINFUnitNameInfo::RenderChatBalon(int x, int y, int cx, int cy)" );

	m_pBalonChat[0]->Move(x,y);
	m_pBalonChat[0]->Render();
	m_pBalonChat[1]->Move(x+ID_CHAT_BALON_TLW,y);
	m_pBalonChat[1]->SetScale(cx-(ID_CHAT_BALON_TLW), 1);
	m_pBalonChat[1]->Render();
	m_pBalonChat[2]->Move(x+cx - ID_CHAT_BALON_TLW+ID_CHAT_BALON_TRW+(ID_CHAT_BALON_TMW*2),y);
	m_pBalonChat[2]->Render();

	m_pBalonChat[3]->Move(x, y+ID_CHAT_BALON_TLH);
	m_pBalonChat[3]->SetScale(1, cy - (ID_CHAT_BALON_TLH + ID_CHAT_BALON_BLH));
	m_pBalonChat[3]->Render();
	m_pBalonChat[4]->Move(x+ID_CHAT_BALON_MLW, y+ID_CHAT_BALON_MRW);
	m_pBalonChat[4]->SetScale(cx-(ID_CHAT_BALON_TLW), cy - (ID_CHAT_BALON_TLH+ID_CHAT_BALON_BLH));
	m_pBalonChat[4]->Render();
	m_pBalonChat[5]->Move(x+cx - ID_CHAT_BALON_MLW+ID_CHAT_BALON_MRW+(ID_CHAT_BALON_MMW*2), y+ID_CHAT_BALON_TRH);
	m_pBalonChat[5]->SetScale(1, cy - (ID_CHAT_BALON_TRH + ID_CHAT_BALON_BRH));
	m_pBalonChat[5]->Render();

	m_pBalonChat[6]->Move(x, y+cy-ID_CHAT_BALON_BLH);
	m_pBalonChat[6]->Render();
	m_pBalonChat[7]->Move(x + ID_CHAT_BALON_BLW, y+cy-ID_CHAT_BALON_BLH);
	m_pBalonChat[7]->SetScale(cx-(ID_CHAT_BALON_BLW), 1);
	m_pBalonChat[7]->Render();
	m_pBalonChat[8]->Move(x+cx-ID_CHAT_BALON_BLW+ID_CHAT_BALON_BRW+(ID_CHAT_BALON_BMW*2), y+cy-ID_CHAT_BALON_BLH);
	m_pBalonChat[8]->Render();
}

void CINFUnitNameInfo::ChatCreateInfo(int nStringLength, char *strMsgChat, char *strFromCharacterName)
{
	FLOG( "CINFUnitNameInfo::ChatCreateInfo(int nChatCreate)" );
	
	CAtumNode * pChat = NULL;
	
	char strChat[SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+4];
	memset(strChat, 0x00, SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+4);
	char textbuf[SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+4];
	memset(textbuf, 0x00, SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+4);
	char textbufChat[SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+24];
	memset(textbufChat, 0x00, SIZE_MAX_CHAT_MESSAGE + SIZE_MAX_CHARACTER_NAME+24);
	
	strncpy(strChat, strMsgChat, nStringLength);

//	int i,j;
//	int strlength;
//	int cont;
	int re;
	CChatMoveData* pChatData;

	// 2007-11-22 by bhsohn �Ʒ��� ���ռ���
	char szCharacterName[SIZE_MAX_ARENA_FULL_NAME];
	memset(szCharacterName, 0x00, SIZE_MAX_ARENA_FULL_NAME);
	strncpy(szCharacterName, strFromCharacterName, SIZE_MAX_CHARACTER_NAME);
	g_pD3dApp->ConevertArenaRenderUserName(g_pD3dApp->GetArenaState(), szCharacterName);
	
	//////////////////////////////////////////////////////
	//
	int temp,temp2;
	// 2006-04-13 by ispark
	g_pD3dApp->CheckReadyStringFiltering(strChat, &temp, &temp2);
//	g_pD3dApp->m_pAbuseFilter->AbuseFiltering(strChat,&temp,&temp2);

	// 2007-11-22 by bhsohn �Ʒ��� ���ռ���
	//wsprintf(textbuf,"[%s]:%s",strFromCharacterName,strChat);
	wsprintf(textbuf,"[%s]:%s",szCharacterName,strChat);		

	g_pD3dApp->m_pChat->CreateChatChild(textbuf,COLOR_CHAT_REGION, CHAT_TAB_NORMAL);
	//
	//////////////////////////////////////////////////////

	memset(m_strChatFullLen, 0x00, 1024);
	strncpy(m_strChatFullLen, textbuf, strlen(textbuf));

	int nChatSend = 0;
	BOOL bReturn = TRUE;
	if(re = strcmp(g_pShuttleChild->m_myShuttleInfo.CharacterName,strFromCharacterName) == 0)
	{
		pChat = g_pShuttleChild->m_pMoveChat;
		bReturn = FALSE;
	}
	CMapEnemyIterator itEnemy = g_pScene->m_mapEnemyList.begin();
	while(itEnemy != g_pScene->m_mapEnemyList.end())
	{
		if(re = strcmp(itEnemy->second->m_infoCharacter.CharacterInfo.CharacterName,strFromCharacterName) == 0)
		{
			pChat = itEnemy->second->m_pMoveChat;
			bReturn = FALSE;
		}
		itEnemy++;
	}
	CMapMonsterIterator itMonster = g_pScene->m_mapMonsterList.begin();
	while(itMonster != g_pScene->m_mapMonsterList.end())
	{
		if(re = strcmp(itMonster->second->m_pMonsterInfo->MonsterName,strFromCharacterName) == 0)
		{
			pChat = itMonster->second->m_pMoveChat;
			bReturn = FALSE;
		}
		itMonster++;
	}

	if(bReturn)
	{
		return;
	}	

	//////////////////////////////////////////////////////////////////////////////////////
	// �ڽ��� ä��	
	while(pChat->m_pChild)
	{
		pChat->m_pChild->InvalidateDeviceObjects();
		pChat->m_pChild->DeleteDeviceObjects();
		pChat->m_pChild->m_bUsing = FALSE;
		pChat->m_pChild = pChat->m_pChild->m_pNext;
	}

//	strlength = strlen(strChat);
//	cont = strlength/ID_CHAT_VIEW_COUNT;
//	i = 0; j = 0;
//	memset(textbuf,0x00,sizeof(textbuf));
//	int strsizeX = 0;
//	for(i=0;i<strlength;i++)
//	{
//		textbuf[j++] = strChat[i];
//		strsizeX = m_pFontMent->GetStringSize(textbuf);
//		if(j>ID_CHAT_VIEW_COUNT)
//		{
//			if(strChat[i]==' ' || i == strlength-1)
//			{
//				j=0;
//				strsizeX = 0;
//				
//				wsprintf(textbufChat,"[%s]:%s",strFromCharacterName,textbuf);
//				pChatData = new CChatMoveData(pChat,textbufChat,COLOR_CHAT_REGION,9,1024,32,ID_CHAT_VIEW_COUNT,TRUE);
//				pChatData->InitDeviceObjects();
//				pChatData->RestoreDeviceObjects();
//				pChatData = (CChatMoveData *)(pChat->AddChild(pChatData));					
//				memset(textbuf,0x00,sizeof(textbuf));
//				memset(textbufChat,0x00,sizeof(textbufChat));
//
//				if(i==strlength-1)
//					break;
//			}
//		}
//		else
//		{
//			if(i == strlength-1)
//			{
//				wsprintf(textbufChat,"[%s]:%s",strFromCharacterName,textbuf);
//				pChatData = new CChatMoveData(pChat,textbufChat,COLOR_CHAT_REGION,9,1024,32,0,TRUE);
//				pChatData->InitDeviceObjects();
//				pChatData->RestoreDeviceObjects();
//				pChatData = (CChatMoveData *)(pChat->AddChild(pChatData));
//				memset(textbuf,0x00,sizeof(textbuf));
//				memset(textbufChat,0x00,sizeof(textbufChat));
//				break;
//			}
//		}
//	}
	memset(textbuf,0x00,sizeof(textbuf));
	// 2007-11-22 by bhsohn �Ʒ��� ���ռ���
	//wsprintf(textbuf,"[%s]:%s",strFromCharacterName,strChat);
	wsprintf(textbuf,"[%s]:%s",szCharacterName,strChat);
	
	pChatData = new CChatMoveData(pChat,textbuf,COLOR_CHAT_REGION,9,1024,32,ID_CHAT_VIEW_COUNT,TRUE);
	pChatData->InitDeviceObjects();
	pChatData->RestoreDeviceObjects();
	pChatData = (CChatMoveData *)(pChat->AddChild(pChatData));					
	memset(textbuf,0x00,sizeof(textbuf));

	//
	////////////////////////////////////////////////////////////////////////////////
}


// 2009. 09. 18 by ckPark ���Ǵ�Ƽ �ʵ� HP�� ���� ���� ��ȭ
void	CINFUnitNameInfo::MonsterChatCreateInfo( int nStringLength, char *strMsgChat, int nMonsterUID )
{
	CMapMonsterIterator itMonster = g_pScene->m_mapMonsterList.begin();
	while(itMonster != g_pScene->m_mapMonsterList.end())
	{
		// ���� �ʻ󿡼� ���� UID�� ���� ���͸� ã�´�
		if( (*itMonster).second->m_info.MonsterIndex == nMonsterUID )
		{
			CAtumNode* pChat	= (*itMonster).second->m_pMoveChat;
			while(pChat->m_pChild)
			{
				pChat->m_pChild->InvalidateDeviceObjects();
				pChat->m_pChild->DeleteDeviceObjects();
				pChat->m_pChild->m_bUsing = FALSE;
				pChat->m_pChild = pChat->m_pChild->m_pNext;
			}

			// �ش� ������ ä�� ������ ������Ʈ
			CChatMoveData* pChatData = NULL;
			pChatData	= new CChatMoveData( pChat, strMsgChat, COLOR_CHAT_REGION, 9, 1024, 32, ID_CHAT_VIEW_COUNT, TRUE );
			pChatData->InitDeviceObjects();
			pChatData->RestoreDeviceObjects();

			pChatData	= (CChatMoveData *)(pChat->AddChild(pChatData));

			return;
		}
		itMonster++;
	}
}
// end 2009. 09. 18 by ckPark ���Ǵ�Ƽ �ʵ� HP�� ���� ���� ��ȭ


DWORD CINFUnitNameInfo::GetNameColor(BYTE byCityWarTeamType, BYTE byInfluenceLeader)
{
	// 2006-04-21 by ispark, �����ڴ� �������, ���°� �����ϰ� ���
	if(COMPARE_RACE(RACE_INFLUENCE_LEADER,byInfluenceLeader))
	{
		return COLOR_CHAT_ALL;
	}
	if(CITYWAR_TEAM_TYPE_NORMAL == byCityWarTeamType)
	{
		return NAME_COLOR_NORMAL;
	}
	else if( CITYWAR_TEAM_TYPE_ATTACKER == byCityWarTeamType)
	{
		return NAME_COLOR_ATTACKER;
	}
	else if( CITYWAR_TEAM_TYPE_DEFENSER == byCityWarTeamType)
	{
		return NAME_COLOR_DEFENSER;
	}
	return NAME_COLOR_NORMAL;
}


DWORD CINFUnitNameInfo::GetInfluenceColor(int byInfluence, BYTE byInfluenceLeader)
{
	// 2006-04-21 by ispark, �����ڴ� �������, ���°� �����ϰ� ���
	if(COMPARE_RACE(RACE_INFLUENCE_LEADER,byInfluenceLeader))
	{
		return COLOR_CHAT_ALL;
	}
//	if(g_pShuttleChild->IsInfluenceWarType(byInfluence) == TRUE)
	if(!IsInfluenceCharacter(g_pShuttleChild->m_myShuttleInfo.InfluenceType, byInfluence))
	{
	// 2011-11-03 by jhahn EP4 �߸����� ���̵� �� ����
		if(((g_pShuttleChild->m_myShuttleInfo.MapChannelIndex.MapIndex - 4000)/100) == 1) //���ε��� ����
		{
			return NAME_COLOR_SAFEJONE;
		}
		else
		return NAME_COLOR_ATTACKER;
	//end 2011-11-03 by jhahn EP4 �߸����� ���̵� �� ����
	}
	return NAME_COLOR_NORMAL;
}