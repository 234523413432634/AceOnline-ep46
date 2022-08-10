#include "stdafx.h"
#include "FieldIOCP.h"
#include "DestroyAuctionManager.h"

CDestroyAuctionManager::CDestroyAuctionManager(CFieldIOCP *i_pFieldIOCP)
{
	ms_pFieldIOCP = i_pFieldIOCP;
	m_DestroyAuctionList.reserve(1000);
}

CDestroyAuctionManager::~CDestroyAuctionManager()
{
	if( FALSE == m_DestroyAuctionList.empty() )
	{
		for_each(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end(), Delete_Object());
		m_DestroyAuctionList.clear();
	}
}

DESTROY_AUCTION_LIST* CDestroyAuctionManager::GetDestroyAuctionListPtr()
{
	return &m_DestroyAuctionList;
}

void CDestroyAuctionManager::CopyDestroyAuctionList(DESTROY_AUCTION_LIST *o_DestroyAuctionList)
{
	if( TRUE == m_DestroyAuctionList.empty() )
	{
		return;
	}
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	o_DestroyAuctionList->assign(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end());
//	*o_MarketList = m_DestroyAuctionList;
}

void CDestroyAuctionManager::InsertDestroyAuction(DESTROY_AUCTION_INFO i_DestroyAuctionItem)
{
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	DESTROY_AUCTION_INFO *pDestroyAuction = new DESTROY_AUCTION_INFO(&i_DestroyAuctionItem);
	m_DestroyAuctionList.push_back(pDestroyAuction);
}

void CDestroyAuctionManager::UpdateDestroyAuction(UID64_t i_nDestroyAuctionUID, BYTE i_nDestroyAuctionState)
{
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	DESTROY_AUCTION_ITR itr = find_if(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end(), DESTROY_AUCTION_LIST_DAuctionUID_Find_Object(i_nDestroyAuctionUID));
	if ( itr != m_DestroyAuctionList.end() )
	{
		(*itr)->DAuctionState = i_nDestroyAuctionState;
	}
}

void CDestroyAuctionManager::UpdateDestroyAuctionTenderInfo(MSG_FC_DESTROY_AUCTION_TENDER_REQUEST *i_pTenderInfo)
{
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	DESTROY_AUCTION_ITR itr = find_if(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end(), DESTROY_AUCTION_LIST_DAuctionUID_Find_Object(i_pTenderInfo->DAuctionUID));
	if ( itr != m_DestroyAuctionList.end() )
	{
		(*itr)->AccountUID = i_pTenderInfo->AccountUID;
		(*itr)->CharacterUID = i_pTenderInfo->CharacterUID;
		(*itr)->Price = i_pTenderInfo->TenderPrice;
	}
}

DESTROY_AUCTION_INFO* CDestroyAuctionManager::GetpDestroyAuctionInfo(UID64_t i_nDestroyAuctionUID)
{
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	DESTROY_AUCTION_ITR itr = find_if(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end(), DESTROY_AUCTION_LIST_DAuctionUID_Find_Object(i_nDestroyAuctionUID));
	if ( itr != m_DestroyAuctionList.end() )
	{
		return (*itr);
	}

	return NULL;
}

void CDestroyAuctionManager::SetDestroyAuctionStartEndTime()
{
	m_atDAuctionStartTime.SetCurrentDateTime(TRUE);
	m_atDAuctionEndTime = m_atDAuctionStartTime;
#if defined(TEST140)
#else
	m_atDAuctionEndTime.Minute = 0;
	m_atDAuctionEndTime.Second = 0;
#endif
	m_atDAuctionEndTime.AddDateTime(0,0,0,0,DESTROY_AUCTION_RUN_TIME_MINUTE,-1);
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	m_DestroyAuctionList.clear();
}

void CDestroyAuctionManager::SetItemDestroyTimeFilter()
{
	m_atItemDestroyTimeFilterEnd.SetCurrentDateTime(TRUE);		// �ı������� ���� �Ⱓ (~����)
	m_atItemDestroyTimeFilterBegin.SetCurrentDateTime(TRUE);
	m_atItemDestroyTimeFilterBegin.Minute = 0;
	m_atItemDestroyTimeFilterBegin.Second = 0;
	m_atItemDestroyTimeFilterBegin.AddDateTime(0,0,0,-(DESTROY_AUCTION_RUN_GAP_TIME_HOUR),0,0);	// �ı������� ���� �Ⱓ (~����)

// 	m_atItemDestroyTimeFilterBegin.SetCurrentDateTime(TRUE);
// 	m_atItemDestroyTimeFilterBegin.Minute = 0;
// 	m_atItemDestroyTimeFilterBegin.Second = 0;
// 	m_atItemDestroyTimeFilterBegin.AddDateTime(0,0,0,-(DESTROY_AUCTION_RUN_GAP_TIME_HOUR*2),0,0);
// 	m_atItemDestroyTimeFilterEnd = m_atItemDestroyTimeFilterBegin;
// 	m_atItemDestroyTimeFilterEnd.AddDateTime(0,0,0,DESTROY_AUCTION_RUN_GAP_TIME_HOUR,0,-1);
}

void CDestroyAuctionManager::DestroyItemListUP()
{
	mt_auto_lock mtDestroyAuction(&m_DestroyAuctionList);
	DESTROY_AUCTION_LIST tmItemListSource;
	DESTROY_AUCTION_LIST tmItemListDes;

	tmItemListSource.reserve(m_DestroyAuctionList.size());
	tmItemListSource.assign(m_DestroyAuctionList.begin(), m_DestroyAuctionList.end());

	int nSourceListHalfSize = tmItemListSource.size()/2;	// ��ü ����Ʈ�� ������ ���

	DESTROY_AUCTION_ITR itr = tmItemListSource.begin();
	while ( itr != tmItemListSource.end() )
	{
		
		// 2014-06-12 by bckim, �ı������ ����ó�� - ������ ������ ���� ���� ���� 
		if( NULL == ms_pFieldIOCP->GetItemInfo(	(*itr)->ItemNum) )
		{
			itr++;
			continue;
		}		
		// End. 2014-06-12 by bckim, �ı������ ����ó�� - ������ ������ ���� ���� ���� 

		switch((*itr)->ItemKind)
		{
		case ITEMKIND_SUPPORT:				// ����
		case ITEMKIND_RADAR:				// ���̴�
		case ITEMKIND_ACCESSORY_UNLIMITED:	// �������
			{
				// 3þ �̻� ����
				if ( DESTROY_AUCTION_LISTUP_ITEM_ENCHANT_TYPE_1 <= (BYTE)((*itr)->EnchantCount) )
				{
					tmItemListDes.push_back(*itr);		// ������ �߰�
					tmItemListSource.erase(itr);		// �ҽ������� ����
				}
				else	{	itr++;	}					// ���Ϳ� �Ȱɸ��� ���� ���� Ȯ��
			}
			break;
		case ITEMKIND_AUTOMATIC:			// �⺻���� 
		case ITEMKIND_VULCAN:				// �⺻���� 
		case ITEMKIND_DUALIST:				// �⺻���� 
		case ITEMKIND_CANNON:				// �⺻���� 
		case ITEMKIND_RIFLE:				// �⺻���� 
		case ITEMKIND_GATLING:				// �⺻���� 
		case ITEMKIND_LAUNCHER:				// �⺻���� 
		case ITEMKIND_MASSDRIVE:			// �⺻���� 
		case ITEMKIND_ROCKET:				// ��޹��� 
		case ITEMKIND_MISSILE:				// ��޹��� 
		case ITEMKIND_BUNDLE:				// ��޹��� 
		case ITEMKIND_DEFENSE:				// �Ƹ�
			{
				// 10þ �̻� ����
				if ( DESTROY_AUCTION_LISTUP_ITEM_ENCHANT_TYPE_2 <= (BYTE)((*itr)->EnchantCount) )
				{
					tmItemListDes.push_back(*itr);		// ������ �߰�
					tmItemListSource.erase(itr);		// �ҽ������� ����
				}
				else	{	itr++;	}					// ���Ϳ� �Ȱɸ��� ���� ���� Ȯ��
			}
			break;
		default:
			tmItemListSource.erase(itr);				// �߸� ��ϵ� ������ �ҽ������� ����
			break;
		}
	}

	if ( nSourceListHalfSize < tmItemListDes.size() )
	{
		// ����Ʈ �� �ؾ��ϴ� ���� �ʰ� �ϹǷ� ����Ʈ�� �����Ѵ�.
		random_shuffle(tmItemListDes.begin(), tmItemListDes.end());
		while ( nSourceListHalfSize < tmItemListDes.size() )
		{
			DESTROY_AUCTION_ITR itrDelete = tmItemListDes.begin();
			tmItemListDes.erase(itrDelete);
		}
	}
	else if ( nSourceListHalfSize > tmItemListDes.size() )
	{
		// ����Ʈ �� �ؾ��ϴ� ���� �� ��ġ�Ƿ� ����Ʈ�� �߰��Ѵ�.
		while ( nSourceListHalfSize > tmItemListDes.size() )
		{
			DESTROY_AUCTION_ITR itrAdd = tmItemListSource.begin();
			if ( itrAdd != tmItemListSource.end() )
			{
				tmItemListDes.push_back(*itrAdd);
				tmItemListSource.erase(itrAdd);
			}
			else
			{
				// ���̻� �߰��� �ҽ� �����Ͱ� ������ while�� Ż���������� ������ ����
				nSourceListHalfSize = tmItemListDes.size();
			}
		}
	}

	m_DestroyAuctionList.clear();
	m_DestroyAuctionList.reserve(tmItemListDes.size());
	m_DestroyAuctionList.assign(tmItemListDes.begin(), tmItemListDes.end());
}

