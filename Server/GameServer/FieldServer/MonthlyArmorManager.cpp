// MonthlyArmorManager.cpp: implementation of the CMonthlyArmorManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FieldIOCP.h"
#include "FieldIOCPSocket.h"
#include "MonthlyArmorManager.h"
#include "FieldGlobal.h"			// 2008-01-17 by cmkwon, S_F: �ý��� �α� �߰� - ������� �߰�
#include "AtumLogSender.h"			// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMonthlyArmorManager::CMonthlyArmorManager(CFieldIOCP *i_pFieldIOCP)
{
	ms_pFieldIOCP = i_pFieldIOCP;
	m_mtMonthlyArmorEventList.reserve(10);
}

CMonthlyArmorManager::~CMonthlyArmorManager()
{
	m_mtMonthlyArmorEventList.clear();
}

mtvectMONTHLY_ARMOR_EVNET_INFO * CMonthlyArmorManager::GetVectMonthlyArmorEventListPtr()
{
	return &m_mtMonthlyArmorEventList;
}

BOOL CMonthlyArmorManager::InitMonthlyArmorEventManager(vectMONTHLY_ARMOR_EVNET_INFO *i_pMonthlyArmorEventList)
{
	// 2008-01-17 by cmkwon, S_F: �ý��� �α� �߰�
	g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] MonthlyArmorEvent reloaded !!, MonthlyArmorEvent Count(%d)\r\n", i_pMonthlyArmorEventList->size());

	mt_auto_lock mtA(this->GetVectMonthlyArmorEventListPtr());				// 2006-08-24 by cmkwon

	m_mtMonthlyArmorEventList.clear();			// 2006-09-12 by cmkwon, ������ �ʱ�ȭ ó���ؾ���

	if(i_pMonthlyArmorEventList->empty())
	{
		return FALSE;
	}
	
	m_mtMonthlyArmorEventList.assign(i_pMonthlyArmorEventList->begin(), i_pMonthlyArmorEventList->end());
	SendMonthlyArmorEventListToAllClients();
	return TRUE;
}

void CMonthlyArmorManager::SendMonthlyArmorEventListToAllClients()
{
	CFieldIOCPSocket *pSock = NULL;

	for (int i = (CLIENT_INDEX_START_NUM); i < ms_pFieldIOCP->GetArrayClientSize(); i++)
	{
		pSock = (CFieldIOCPSocket*)ms_pFieldIOCP->GetIOCPSocket(i);
		if ( NULL != pSock )
		{
			if ( TRUE == pSock->IsValidCharacter(FALSE) )
			{
				SendMonthlyArmorEventAllCollectionList(pSock);	// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �̴��� ��� �̺�Ʈ ���� ������
				mt_auto_lock igLock(&(pSock->m_ItemManager.m_mapItemGeneral));
				mtmapUID2ItemGeneral::iterator itrItem = pSock->m_ItemManager.m_mapItemGeneral.begin();
				for(; pSock->m_ItemManager.m_mapItemGeneral.end() != itrItem; itrItem++)
				{
					ITEM_GENERAL *pItemG = itrItem->second;
					pSock->m_ArmorCollection.CheckMonthlyArmorEvent(pItemG);	// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
				}
			}
		}
	}
}

// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �̴��� ��� �̺�Ʈ ���� ������
void CMonthlyArmorManager::CheckMonthlyArmorEventCollection(CFieldIOCPSocket* i_pSock, COLLECTION_INFO* io_pCollectioninfo)	// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
{
#ifdef SC_COLLECTION_ARMOR_JHSEOL_BCKIM	// - �ϳ��� �÷��ǿ� ���Ͽ� �̴��� ��� �̺�Ʈ ���� ������
	if ( NULL == i_pSock || NULL == io_pCollectioninfo )	// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
	{
		// ����
		return;
	}
	mt_auto_lock mtA(this->GetVectMonthlyArmorEventListPtr());

	{
		ATUM_DATE_TIME atCurrentDate(TRUE);
		mtvectMONTHLY_ARMOR_EVNET_INFO::iterator itrEvent = m_mtMonthlyArmorEventList.begin();
		for ( ; itrEvent != m_mtMonthlyArmorEventList.end() ; itrEvent++ )
		{
			if ( atCurrentDate >= itrEvent->atStartDate && atCurrentDate < itrEvent->atEndDate && io_pCollectioninfo->ShapeNum == itrEvent->nArmorSourceIndex )	// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
			{
				// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
				if ( atCurrentDate >= io_pCollectioninfo->DurationTime )
				{
					io_pCollectioninfo->nOptionItemNum = itrEvent->nOptionItemNum;
					io_pCollectioninfo->DurationTime.SetCurrentDateTime(TRUE);
					io_pCollectioninfo->DurationTime.AddDateTime(0,0,itrEvent->nDuration,0,0,0);
				}
				// end 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
			}
		}
	}

	mtA.auto_unlock_cancel();
#endif
}

void CMonthlyArmorManager::SendMonthlyArmorEventAllCollectionList(CFieldIOCPSocket* i_pSock)
{
#ifdef SC_COLLECTION_ARMOR_JHSEOL_BCKIM	// - ��� �÷��ǿ� ���Ͽ� �̴��� ��� �̺�Ʈ ���� ������
	if ( NULL == i_pSock )
	{
		// ����
		return;
	}
	mt_auto_lock mtA(this->GetVectMonthlyArmorEventListPtr());
	
	i_pSock->SendAddMessageType(T_FC_COLLECTION_MONTHLY_AROMOR_EVENT_INIT);
	
	ATUM_DATE_TIME atCurrentDate(TRUE);
	mtvectMONTHLY_ARMOR_EVNET_INFO::iterator itrEvent = m_mtMonthlyArmorEventList.begin();
	for ( ; itrEvent != m_mtMonthlyArmorEventList.end() ; itrEvent++ )
	{
		if ( atCurrentDate >= itrEvent->atStartDate && atCurrentDate < itrEvent->atEndDate )
		{
			COLLECTION_INFO *tmCollectionPtr = i_pSock->m_ArmorCollection.GetCollectionInfoPtr(itrEvent->nArmorSourceIndex);
			if ( NULL != tmCollectionPtr )
			{
				// 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
				if ( atCurrentDate >= tmCollectionPtr->DurationTime )	// ���� ���ŵǾ�� �ϴ� �̺�Ʈ�� �ֵ�� ���� �� DB������Ʈ
				{
					tmCollectionPtr->nOptionItemNum = itrEvent->nOptionItemNum;
					tmCollectionPtr->DurationTime.SetCurrentDateTime(TRUE);
					tmCollectionPtr->DurationTime.AddDateTime(0,0,itrEvent->nDuration,0,0,0);
					i_pSock->m_ArmorCollection.CollectionUpdate(tmCollectionPtr);
					CAtumLogSender::SendLogMessageCollectionState(i_pSock, tmCollectionPtr, GAMELOG_COLLECTION_STATE_MONTHLY_EVENT);
				}
				// end 2013-09-06 by jhseol, �̴��� �Ƹ� �̺�Ʈ ���� �Ⱓ ����
			}
		}
	}
	
	mtA.auto_unlock_cancel();
#endif
}
// end 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �̴��� ��� �̺�Ʈ ���� ������