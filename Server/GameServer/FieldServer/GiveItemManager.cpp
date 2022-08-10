// GiveItemManager.cpp: implementation of the CGiveItemManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FieldIOCPSocket.h"
#include "GiveItemManager.h"
#include "FieldGlobal.h"			// 2008-01-17 by cmkwon, S_F: �ý��� �α� �߰� - ������� �߰�

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGiveItemManager::CGiveItemManager()
{
	m_mtEventItemList.reserve(10);
}

CGiveItemManager::~CGiveItemManager()
{
	m_mtEventItemList.clear();
}

// 2007-07-24 by dhjin, INT i_nUnitkind �߰�
// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
//void CGiveItemManager::GetActEventItemGameStart(vectItemEventInfo *o_ItemEventInfo, BOOL i_bPCBangCheck, BYTE i_byInfluenecType, BOOL i_bMemberShip, ATUM_DATE_TIME *i_Time, INT i_nUnitkind, ATUM_DATE_TIME *i_patLastGameEndDate)
// 2010-06-16 by jskim, ������ �̺�Ʈ üũ ��� -
//void CGiveItemManager::GetActEventItemGameStart(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, ATUM_DATE_TIME *i_patRegisteredDate, ATUM_DATE_TIME *i_patLastGameEndDate)
// start 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���� �߰�
void CGiveItemManager::GetActEventItemGameStart(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, \
												ATUM_DATE_TIME *i_patRegisteredDate, ATUM_DATE_TIME *i_patLastGameEndDate, BYTE b_Level, UID32_t i_AccountUniqueNumber, INT i_LoginCheckNum, INT i_ChannelingType)	// 2014-02-10 by jhseol&bckim, ü�θ�
//end 2010-06-16 by jskim, ������ �̺�Ʈ üũ ��� -
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());
	
	ATUM_DATE_TIME		CurTime(TRUE);
	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 

		if ( ((m_mtEventItemList[i].StartTime) < CurTime) 
			&& ((m_mtEventItemList[i].EndTime) > CurTime) )		
		{
			// 2007-07-20 by dhjin, ���º���� ������ �̺�Ʈ�� �ٸ� �Լ����� ó���Ѵ�.

			// 2008-01-15 by cmkwon, ���� �ý��� ���� ���� - ITEM_EVENT_TYPE_INFLCHANGE, ITEM_EVENT_TYPE_LEVELUP �� �̺�Ʈ�� �ٸ� �Լ����� ó��
			//if(ITEM_EVENT_TYPE_ONLYONE != m_mtEventItemList[i].ItemEventType
			//	&& ITEM_EVENT_TYPE_ONEDAY != m_mtEventItemList[i].ItemEventType)
			if(ITEM_EVENT_TYPE_INFLCHANGE == m_mtEventItemList[i].ItemEventType
				|| ITEM_EVENT_TYPE_LEVELUP == m_mtEventItemList[i].ItemEventType
				|| ITEM_EVENT_TYPE_FIRST_PURCHASE == m_mtEventItemList[i].ItemEventType	// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
				|| ITEM_EVENT_TYPE_AT_TIME == m_mtEventItemList[i].ItemEventType	// 2013-12-17 by bckim, Ư���ð� ������ ���� ����
				)
			{
				continue;
			}

// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - �Ʒ��� ���� �Լ��� üũ
// 			if (m_mtEventItemList[i].OnlyPCBang
// 				&& FALSE == i_bPCBangCheck)
// 			{
// 				continue;
// 			}
// 
// 			if (m_mtEventItemList[i].MemberShip
// 				&& FALSE == i_bMemberShip)
// 			{
// 				continue;
// 			}
// 
// 			if (INFLUENCE_TYPE_ALL_MASK != m_mtEventItemList[i].byInfluenceType
// 				&& m_mtEventItemList[i].byInfluenceType != i_byInfluenecType)
// 			{// 2006-09-05 by cmkwon
// 				continue;
// 			}
// 
// 			if (FALSE == (i_nUnitkind & m_mtEventItemList[i].UnitKind))
// 			{// 2007-07-24 by dhjin, ���� ����� �ƴ� �������� üũ
// 				continue;	
// 			}
// 
// 			if(m_mtEventItemList[i].NewMember
// 				&& (((m_mtEventItemList[i].StartTime) > *i_Time) 
// 					|| ((m_mtEventItemList[i].EndTime) < *i_Time)) )
// 			{// 2007-07-23 by dhjin, �̺�Ʈ �Ⱓ�ȿ� ������ ���� ������� üũ
// 				continue;
// 			}
			// 2010-06-16 by jskim, ������ �̺�Ʈ üũ ��� -
			if(pItemEvInfo->iLevelMin && pItemEvInfo->iLevelMax &&
				(b_Level < pItemEvInfo->iLevelMin || b_Level > pItemEvInfo->iLevelMax))
			{
				continue;
			}
			//end 2010-06-16 by jskim, ������ �̺�Ʈ üũ ��� -				
			// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����

			//if(FALSE == this->IsEnableItemEvent(pItemEvInfo, i_bMemberShip, i_bPCBangUser, i_byInfluenecType, i_nUnitkind, i_patRegisteredDate,i_LoginCheckNum,i_AccountUniqueNumber))
			if(FALSE == this->IsEnableItemEvent(pItemEvInfo, i_bMemberShip, i_bPCBangUser, i_byInfluenecType, i_nUnitkind, i_patRegisteredDate,i_LoginCheckNum,i_AccountUniqueNumber, i_ChannelingType))// 2014-02-10 by jhseol&bckim, ü�θ�
			{// 2008-02-01 by cmkwon, IsEnableItemEvent() ���� üũ
				continue;
			}

			///////////////////////////////////////////////////////////////////////////////			
			// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
			if(ITEM_EVENT_TYPE_ONLYONE == pItemEvInfo->ItemEventType			// 2008-04-23 by cmkwon, ���� ����, ITEM_EVENT_TYPE_ONLYONE Ÿ�� �� ������ atLastGameEndDate �� üũ�ؾ� �Ѵ�.
				&& pItemEvInfo->UseLastGameEndDate								// 2008-06-25 by cmkwon, ���� ����, ������ �̺�Ʈ ���� UseLastGameEndDate �� �� �϶��� üũ �ؾ� ��.
				&& pItemEvInfo->atLastGameEndDate.IsValidATUM_DATE_TIME())
			{
				ATUM_DATE_TIME *patCheckDate = i_patLastGameEndDate;
				if(FALSE == i_patLastGameEndDate->IsValidATUM_DATE_TIME())
				{// 2008-02-01 by cmkwon, LastGameEndDate�� ��ȿ���� �����Ƿ� RegisteredDate �� üũ�Ѵ�.					
					patCheckDate = i_patRegisteredDate;
				}

				if(FALSE == patCheckDate->IsValidATUM_DATE_TIME()
					|| *patCheckDate > pItemEvInfo->atLastGameEndDate)
				{// 2008-02-01 by cmkwon, ��ȿ���� �Ȱų� ���� ��¥ ���� �ð� �̸� ���� �̺�Ʈ�� �ƴϴ�.
					continue;
				}
			}

#ifdef SC_ITEM_EVENT_RETURN_USER_BCKIM_BHSOHN				// 2013-02-28 by bckim, �������� �����߰�
			if(ITEM_EVENT_TYPE_ONLYONE == pItemEvInfo->ItemEventType && pItemEvInfo->UseFixedPeriod && pItemEvInfo->FixedPeriod_DAY )
			{
				
#ifdef S_TEMP_RESTRICTION_ITEMEVENT_PYLONES_SERVER	// 2014-04-21 by bckim,  �ʷ� ���� �������� ������ �������� 
				if( 10066 == g_pFieldGlobal->GetMGameServerID() )	// 2014-04-21 by bckim,  �ʷ� ���� �������� ������ �������� 
					continue;
#endif
				
				ATUM_DATE_TIME *patCheckDate = i_patLastGameEndDate;
				if(FALSE == i_patLastGameEndDate->IsValidATUM_DATE_TIME())
				{				
					patCheckDate = i_patRegisteredDate;
				}
				ATUM_DATE_TIME tmpCurrentDate = tmpCurrentDate.GetCurrentDateTime();
				tmpCurrentDate.AddDateTime(0,0, -pItemEvInfo->FixedPeriod_DAY ,0,0,0);			// ������ ���ӽð��� ���� �ð����� �����̸� ������ ����
				if(FALSE == patCheckDate->IsValidATUM_DATE_TIME() || *patCheckDate > tmpCurrentDate )
				{
					continue;
				}
			}			
#endif

			o_ItemEventInfo->push_back(m_mtEventItemList[i]);
		}
	}
}

mtvectItemEventInfo * CGiveItemManager::GetVectItemEventListPtr()
{
	return &m_mtEventItemList;
}

BOOL CGiveItemManager::InitItemEventManager(vectItemEventInfo *i_pItemEventList)
{
	// 2008-01-17 by cmkwon, S_F: �ý��� �α� �߰�
	g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] ItemEvent reloaded !!, ItemEvent Count(%d)\r\n", i_pItemEventList->size());

	mt_auto_lock mtA(this->GetVectItemEventListPtr());				// 2006-08-24 by cmkwon

	m_mtEventItemList.clear();			// 2006-09-12 by cmkwon, ������ �ʱ�ȭ ó���ؾ���

	if(i_pItemEventList->empty())
	{
		return FALSE;
	}
	
	m_mtEventItemList.assign(i_pItemEventList->begin(), i_pItemEventList->end());	
	return TRUE;
}

// 2013-09-30 by bckim, Ư���ð� ���������� 
void CGiveItemManager::OnMinutecheckItemEventAtTime(vectItemEventInfo *o_pItemEventList)
{
	g_pFieldGlobal->WriteSystemLogEX(TRUE, "[Notify] OnMinutecheckItemEventAtTime timeGetTime(%d)!!\r\n",timeGetTime());

	mt_auto_lock mtA(this->GetVectItemEventListPtr());	

	ATUM_DATE_TIME		CurTime(TRUE);
	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);
		if ( ((m_mtEventItemList[i].StartTime) < CurTime) && ((m_mtEventItemList[i].EndTime) > CurTime) )	// �ش��̺�Ʈ �ⰣȮ�� 	
		{
			if(ITEM_EVENT_TYPE_AT_TIME == m_mtEventItemList[i].ItemEventType
 				&& CurTime.Hour ==  m_mtEventItemList[i].GiveItemAtTime.Hour 
 				&& CurTime.Minute ==  m_mtEventItemList[i].GiveItemAtTime.Minute )
			{
				o_pItemEventList->push_back(*pItemEvInfo);					
			}
		}
	}
}
// end. 2013-09-30 by bckim, Ư���ð� ���������� 


///////////////////////////////////////////////////////////////////////////////
/// \fn			void CGiveItemManager::GetActEventItemInflChange(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, ATUM_DATE_TIME *i_patRegisteredDate)
/// \brief		ITEM_EVENT_TYPE_NEWMEMBER_INFLCHANGE �̺�Ʈ ���� üũ
///				// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
/// \author		dhjin
/// \date		2007-07-20 ~ 2007-07-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CGiveItemManager::GetActEventItemInflChange(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind,\
												 ATUM_DATE_TIME *i_patRegisteredDate, INT i_channelingType)	// 2014-02-10 by jhseol&bckim, ü�θ�
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());

	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 

		if (ITEM_EVENT_TYPE_INFLCHANGE != m_mtEventItemList[i].ItemEventType)
		{
			continue;
		}

// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - �Ʒ��� ���� IsEnableItemEvent() �� üũ
// 		if (FALSE == (i_nUnitkind & m_mtEventItemList[i].UnitKind))
// 		{// 2007-07-24 by dhjin, ���� ����� �ƴ� �������� üũ
// 			continue;	
// 		}
// 
// 		if(m_mtEventItemList[i].NewMember
// 			&& (((m_mtEventItemList[i].StartTime) > *i_Time) 
// 				|| ((m_mtEventItemList[i].EndTime) < *i_Time)) )
// 		{// 2007-07-23 by dhjin, �̺�Ʈ �Ⱓ�ȿ� ������ ���� ������� üũ
// 			continue;
// 		}
		if(FALSE == this->IsEnableItemEvent(pItemEvInfo, i_bMemberShip, i_bPCBangUser, i_byInfluenecType, i_nUnitkind, i_patRegisteredDate, 0,0, i_channelingType))	// 2014-02-10 by jhseol&bckim, ü�θ�
		{// 2008-02-01 by cmkwon, IsEnableItemEvent() ���� üũ
			continue;
		}

		o_ItemEventInfo->push_back(m_mtEventItemList[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CGiveItemManager::GetActEventItemLevelUp(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, ATUM_DATE_TIME *i_patRegisteredDate, BYTE i_nLevel)
/// \brief		ITEM_EVENT_TYPE_NEWMEMBER_LEVELUP �̺�Ʈ ���� üũ
///				// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
/// \author		dhjin
/// \date		2007-07-20 ~ 2007-07-20
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CGiveItemManager::GetActEventItemLevelUp(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, \
											  ATUM_DATE_TIME *i_patRegisteredDate, BYTE i_nLevel, INT i_channelingType)	// 2014-02-10 by jhseol&bckim, ü�θ�
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());

	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 

		if (ITEM_EVENT_TYPE_LEVELUP != m_mtEventItemList[i].ItemEventType
			|| i_nLevel != m_mtEventItemList[i].ReqLevel)
		{
			continue;
		}
// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - �Ʒ��� ���� IsEnableItemEvent() �� üũ
// 		if (FALSE == (i_nUnitkind & m_mtEventItemList[i].UnitKind))
// 		{// 2007-07-24 by dhjin, ���� ����� �ƴ� �������� üũ
// 			continue;	
// 		}
// 
// 		if(m_mtEventItemList[i].NewMember
// 			&& (((m_mtEventItemList[i].StartTime) > *i_Time) 
// 				|| ((m_mtEventItemList[i].EndTime) < *i_Time)) )
// 		{// 2007-07-23 by dhjin, �̺�Ʈ �Ⱓ�ȿ� ������ ���� ������� üũ
// 			continue;
// 		}
		if(FALSE == this->IsEnableItemEvent(pItemEvInfo, i_bMemberShip, i_bPCBangUser, i_byInfluenecType, i_nUnitkind, i_patRegisteredDate, 0,0, i_channelingType ))	// 2014-02-10 by jhseol&bckim, ü�θ�
		{// 2008-02-01 by cmkwon, IsEnableItemEvent() ���� üũ
			continue;
		}

		o_ItemEventInfo->push_back(m_mtEventItemList[i]);
	}
}

// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
///////////////////////////////////////////////////////////////////////////////
/// \fn			void CGiveItemManager::GetActEventItemFirstPurchase(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, ATUM_DATE_TIME i_atAccountLastBuyDate, ATUM_DATE_TIME i_atCharacterLastBuyDate)
/// \brief		�ſ� ù ����� ��������
/// \author		jhseol
/// \date		2013-03-29
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CGiveItemManager::GetActEventItemFirstPurchase(vectItemEventInfo *o_ItemEventInfo, BOOL i_bMemberShip, BOOL i_bPCBangUser, BYTE i_byInfluenecType, INT i_nUnitkind, \
													ATUM_DATE_TIME i_atAccountLastBuyDate, ATUM_DATE_TIME i_atCharacterLastBuyDate, ATUM_DATE_TIME i_atAccountExtLastBuyDate, INT i_channelingType ) // 2014-03-12 by jekim, �ֹι�ȣ�� ������ ����	// 2014-02-10 by jhseol&bckim, ü�θ�)
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());
	
	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
		
		if ( ITEM_EVENT_TYPE_FIRST_PURCHASE != pItemEvInfo->ItemEventType )
		{
			continue;
		}
		ATUM_DATE_TIME		CurrentTime(TRUE);
		if ( CurrentTime < pItemEvInfo->StartTime || CurrentTime > pItemEvInfo->EndTime )
		{
			continue;
		}
// 2014-03-12 by jekim, �ֹι�ȣ�� ������ ����
		if ( ITEM_EVENT_CHECKWITH_CHARACTER_UID == pItemEvInfo->CheckWithCharacterUID )
		{
			if ( i_atCharacterLastBuyDate > pItemEvInfo->StartTime )
			{
				continue;
			}
		}
		else if( ITEM_EVENT_CHECKWITH_ACCOUNT_UID == pItemEvInfo->CheckWithCharacterUID )
		{
			if ( i_atAccountLastBuyDate > pItemEvInfo->StartTime )
			{
				continue;
			}
		}
		else if( ITEM_EVENT_CHECKWITH_ACCOUNTEXT_UID == pItemEvInfo->CheckWithCharacterUID )
		{
			if ( i_atAccountLastBuyDate > pItemEvInfo->StartTime )
			{
				continue;
			}
		}
		else
		{
				continue;
			}
// end 2014-03-12 by jekim, �ֹι�ȣ�� ������ ����
		if(FALSE == this->IsEnableItemEvent(pItemEvInfo, i_bMemberShip, i_bPCBangUser, i_byInfluenecType, i_nUnitkind, &CurrentTime, 0,0, i_channelingType ))	// 2014-02-10 by jhseol&bckim, ü�θ�
		{
			continue;
		}
		
		o_ItemEventInfo->push_back(m_mtEventItemList[i]);
	}
}
// end 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CGiveItemManager::IsEnableItemEvent(SITEM_EVENT_INFO *i_pItemEvInfo, BOOL i_bMemberShip, BOOL i_bPCBangCheck, BYTE i_byInfluenecType, INT i_nUnitkind, ATUM_DATE_TIME *i_patRegisteredDate)
/// \brief		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - CGiveItemManager::IsEnableItemEvent() �߰�
///				// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - üũ�ѹ� �����߰�
/// \author		cmkwon
/// \date		2008-02-01 ~ 2008-02-01
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CGiveItemManager::IsEnableItemEvent(SITEM_EVENT_INFO *i_pItemEvInfo, BOOL i_bMemberShip, BOOL i_bPCBangCheck, BYTE i_byInfluenecType, INT i_nUnitkind, \
										 ATUM_DATE_TIME *i_patRegisteredDate, INT i_LoginEventCheckNumber, UID32_t i_AccountUniqueNumber/*=0*/, int i_ChannelingType/*=0*/)
{

	if(i_pItemEvInfo->OnlyPCBang
		&& FALSE == i_bPCBangCheck)
	{
		return FALSE;
	}

	// 2014-02-10 by jhseol&bckim, ü�θ�	
	if( 100 == i_pItemEvInfo->ChannelingType  )
	{	
		if( 0 == i_ChannelingType )
		{
			return FALSE;
		}
	}	
	if( 0 != i_pItemEvInfo->ChannelingType 
		&& 100 != i_pItemEvInfo->ChannelingType
		&& i_pItemEvInfo->ChannelingType != i_ChannelingType )
	{
		return FALSE;
	}
	// End. 2014-02-10 by jhseol&bckim, ü�θ�

	if (i_pItemEvInfo->MemberShip
		&& FALSE == i_bMemberShip)
	{
		return FALSE;
	}

	if (INFLUENCE_TYPE_ALL_MASK != i_pItemEvInfo->byInfluenceType
		&& i_pItemEvInfo->byInfluenceType != i_byInfluenecType)
	{
		return FALSE;
	}

	if (FALSE == (i_nUnitkind & i_pItemEvInfo->UnitKind))
	{
		return FALSE;
	}

	if( i_pItemEvInfo->NewMember
		&& (i_pItemEvInfo->StartTime > *i_patRegisteredDate || i_pItemEvInfo->EndTime < *i_patRegisteredDate) )
	{
		return FALSE;
	}
	// start 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���ڷ� ���� üũ�ѹ��� üũ

	if( ITEM_EVENT_TYPE_LOGIN == i_pItemEvInfo->ItemEventType
		|| 0 != i_pItemEvInfo->LoginCheckNumber )
	{
		// �ѹ��� ����Ǿ�� �Ѵ�.
		if(i_LoginEventCheckNumber == i_pItemEvInfo->LoginCheckNumber) // ������ �Ϸ�� ������ ó��
		{
			// �̺�Ʈ ���� �α״� �����Ƿ� ���� �ȳ��ܵ� �ȴ�.
			// g_pFieldGlobal->WriteSystemLogEX(TRUE,"Login Event Success!! CheckEventNumber[%d], AccountUniqueNumber[%d]\r\n",i_LoginEventCheckNumber,i_AccountUniqueNumber);
			return TRUE;
		}
		return FALSE;	// �α����̺�Ʈ�̰� ���� �� ������ �������� ������ ������ ����
	}
	// end 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���ڷ� ���� üũ�ѹ��� üũ
	return TRUE;
}

// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - üũ�Լ� �߰�
BOOL CGiveItemManager::IsEnableCheckLoginEvent()
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());
	
	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);		// 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
		
		if (ITEM_EVENT_TYPE_LEVELUP != m_mtEventItemList[i].ItemEventType)
		{
			return TRUE;
		}
	}
	return FALSE;
}

// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
SITEM_EVENT_INFO* CGiveItemManager::GetItemEventInfoByEventUID(int i_nItemEventUID)
{
	mt_auto_lock mtA(this->GetVectItemEventListPtr());
	
	int v_size = m_mtEventItemList.size();
	for (int i=0; i < v_size;i++)
	{
		SITEM_EVENT_INFO *pItemEvInfo = &(m_mtEventItemList[i]);
		
		if ( i_nItemEventUID == pItemEvInfo->ItemEventUID )
		{
			return pItemEvInfo;
		}
	}
	return NULL;
}
// end 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
