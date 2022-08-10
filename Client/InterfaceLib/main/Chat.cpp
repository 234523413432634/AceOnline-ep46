// Chat.cpp: implementation of the CChat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Chat.h"
#include "ChatData.h"
#include "AtumApplication.h"
#include "INFGameMain.h"
#include "INFGameMainChat.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChat::CChat()
{
	FLOG( "CChat()" );
	m_nDataNum = 0;
//	m_pRenderer = pRender;
	
	// 2007-11-05 by bhsohn ���� ������Ʈ üũ�� ó��
	m_vecErrInfo.clear();


	FieldSecretNumber = NULL;				// 2011-11-01 by jhahn ��ȣȭ ó��
	ImeSceretNumbere = NULL;				// 2011-11-01 by jhahn ��ȣȭ ó��		
}

CChat::~CChat()
{
	FLOG( "~CChat()" );
}

HRESULT CChat::InitDeviceObjects()
{
	FLOG( "CChat::InitDeviceObjects()" );

	return CAtumNode::InitDeviceObjects();
}

HRESULT CChat::RestoreDeviceObjects()
{
	FLOG( "CChat::RestoreDeviceObjects()" );
	return CAtumNode::RestoreDeviceObjects();
}

HRESULT CChat::InvalidateDeviceObjects()
{
	FLOG( "CChat::InvalidateDeviceObjects()" );
	return CAtumNode::InvalidateDeviceObjects();
}

HRESULT CChat::DeleteDeviceObjects()
{
	FLOG( "CChat::DeleteDeviceObjects()" );
	return CAtumNode::DeleteDeviceObjects();
}

void CChat::CreateChatChild(TCHAR *str,int type, int chatType/* = CHAT_TAB_SYSTEM */, char* szWisperToCharacterName, char *szWisperFromCharacterName)
{
	FLOG( "CChat::CreateChatChild(TCHAR *str,int type, int chatType)" );
/*	m_nDataNum++;
	if(m_nDataNum > 7)
	{
		CAtumNode * pChild = m_pChild;
		while(pChild)
		{
			if(!pChild->m_pNext)
				break;
			pChild = pChild->m_pNext;
		}
		if(pChild)
		{
			pChild->m_bUsing = FALSE;
		}
		m_nDataNum = 7;
	}
	CChatData * pChatData = new CChatData(str,1024,32,type);
	pChatData->InitDeviceObjects();
	pChatData->RestoreDeviceObjects();
	AddChild(pChatData);

*/
	// �ӽ� �ڵ�
//	int temp,temp2;
//	g_pD3dApp->m_pAbuseFilter->AbuseFiltering(str,&temp,&temp2);
	if(g_pD3dApp->m_pInterface && g_pGameMain && g_pGameMain->m_pChat)
	{
		g_pGameMain->m_pChat->AddBuffer(chatType, str, type, szWisperToCharacterName, szWisperFromCharacterName);
	}
	// 2007-11-05 by bhsohn ���� ������Ʈ üũ�� ó��
	// ���� ���ҽ��� �������� �ʾҴ�. 
	else
	{
		structErrorChatInfo strcErrInfo;
		memset(&strcErrInfo, 0x00,sizeof(structErrorChatInfo));

		strncpy(strcErrInfo.szErrString, str, 512);
		strcErrInfo.nType = type;

		m_vecErrInfo.push_back(strcErrInfo);		
	}
}

// 2007-11-05 by bhsohn ���� ������Ʈ üũ�� ó��
void CChat::ErrorInfoAllAddChat()
{	
	vector<structErrorChatInfo>::iterator it = m_vecErrInfo.begin();
	while(it != m_vecErrInfo.end())
	{
		structErrorChatInfo stctErrInfo = (*it);
		CreateChatChild(stctErrInfo.szErrString, stctErrInfo.nType);
		
		it++;
	}
	m_vecErrInfo.clear();

}

void CChat::Tick()
{
	FLOG( "CChat::Tick()" );
	CAtumNode::Tick();
	D3DXVECTOR2 vStartPos=D3DXVECTOR2(20.0f, 490.0f);
	CChatData * pChild = (CChatData *)m_pChild;
	m_nDataNum=0;
	while(pChild)
	{
		pChild->m_vRenderPos.y = vStartPos.y - m_nDataNum*20;
		m_nDataNum++;
		pChild = (CChatData *)pChild->m_pNext;
	}
}

void CChat::Render()
{
	FLOG( "CChat::Render()" );
	if(m_nDataNum == 0) return;
	CAtumNode::Render();
}

