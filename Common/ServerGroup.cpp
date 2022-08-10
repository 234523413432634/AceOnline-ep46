#include "stdafx.h"
#include "servergroup.h"
#include "IOCPSocket.h"

CServerGroup::CServerGroup()
{
	InitServerGroup();
}

CServerGroup::~CServerGroup()
{
	InitServerGroup();
}

void CServerGroup::InitServerGroup(void)
{
	memset(m_ServerGroupName, 0x00, SIZE_MAX_SERVER_NAME);
	m_bEnableServerGroup			= TRUE;
	m_LimitGroupUserCounts			= 0;
	m_bForbidViewServer				= FALSE;		// 2007-12-22 by dhjin, �Ʒ��� ���� - ���� ����Ʈ���� ���̸� �ȵǴ� ���� üũ, TRUE = ������ �ʴ´�.
	
	m_AccumulatedGroupUserCounts	= 0;
	m_MaxGroupUserCounts			= 0;

	m_bLockCreateCharacterForNewAccount	= FALSE;	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 

	// reset m_IMServerInfo
	m_IMServerInfo.Reset();

	// init m_setLoginedAccount
	m_setLoginedAccount.clearLock();

	m_FieldServerInfo.Reset();
}

void CServerGroup::ResetServerGroup(BOOL i_bExcludeIMServer/*=FALSE*/)
{
	m_AccumulatedGroupUserCounts	= 0;
	m_MaxGroupUserCounts			= 0;

	// init m_setLoginedAccount
	m_setLoginedAccount.clearLock();

	m_FieldServerInfo.Reset();

	if(FALSE == i_bExcludeIMServer)
	{
		// reset m_IMServerInfo
		m_IMServerInfo.Reset();
	}
}

INT CServerGroup::GetUserCount()
{
	return m_setLoginedAccount.size();
}


void CServerGroup::SendMessageToFieldServer(BYTE *i_pBuff, int i_nSize)
{
// 2007-11-20 by cmkwon, �Ʒ��� ���� ���� ��
//	if(m_FieldServerInfo.IsActive
//		&& m_FieldServerInfo.pSocket
//		&& m_FieldServerInfo.pSocket->IsUsing())
//	{
//		m_FieldServerInfo.pSocket->SendAddData(i_pBuff, i_nSize);
//	}
	CIOCPSocket *pISoc = m_FieldServerInfo.pSocket;
	if(FALSE == m_FieldServerInfo.IsActive
		|| NULL == pISoc
		|| FALSE == pISoc->IsUsing())
	{
		return;
	}
	
	pISoc->SendAddData(i_pBuff, i_nSize);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CServerGroup::SendMsgToIMServer(BYTE *i_pBuff, int i_nSize)
/// \brief		// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - CServerGroup::SendMsgToIMServer() �߰�
/// \author		cmkwon
/// \date		2007-11-20 ~ 2007-11-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CServerGroup::SendMsgToIMServer(BYTE *i_pBuff, int i_nSize)
{
	CIOCPSocket *pISoc = m_IMServerInfo.pSocket;
	if(FALSE == m_IMServerInfo.IsActive
		|| NULL == pISoc
		|| FALSE == pISoc->IsUsing())
	{
		return;
	}
	
	pISoc->SendAddData(i_pBuff, i_nSize);
}