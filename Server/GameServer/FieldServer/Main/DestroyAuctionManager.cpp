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
	m_atItemDestroyTimeFilterEnd.SetCurrentDateTime(TRUE);		// 파괴아이템 수집 기간 (~까지)
	m_atItemDestroyTimeFilterBegin.SetCurrentDateTime(TRUE);
	m_atItemDestroyTimeFilterBegin.Minute = 0;
	m_atItemDestroyTimeFilterBegin.Second = 0;
	m_atItemDestroyTimeFilterBegin.AddDateTime(0,0,0,-(DESTROY_AUCTION_RUN_GAP_TIME_HOUR),0,0);	// 파괴아이템 수집 기간 (~부터)

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

	int nSourceListHalfSize = tmItemListSource.size()/2;	// 전체 리스트의 절반을 등록

	DESTROY_AUCTION_ITR itr = tmItemListSource.begin();
	while ( itr != tmItemListSource.end() )
	{
		
		// 2014-06-12 by bckim, 파괴경매장 예외처리 - 아이템 정보가 없는 것은 제외 
		if( NULL == ms_pFieldIOCP->GetItemInfo(	(*itr)->ItemNum) )
		{
			itr++;
			continue;
		}		
		// End. 2014-06-12 by bckim, 파괴경매장 예외처리 - 아이템 정보가 없는 것은 제외 

		switch((*itr)->ItemKind)
		{
		case ITEMKIND_SUPPORT:				// 엔진
		case ITEMKIND_RADAR:				// 레이더
		case ITEMKIND_ACCESSORY_UNLIMITED:	// 보조장비
			{
				// 3첸 이상만 필터
				if ( DESTROY_AUCTION_LISTUP_ITEM_ENCHANT_TYPE_1 <= (BYTE)((*itr)->EnchantCount) )
				{
					tmItemListDes.push_back(*itr);		// 데이터 추가
					tmItemListSource.erase(itr);		// 소스데이터 삭제
				}
				else	{	itr++;	}					// 필터에 안걸리면 다음 값을 확인
			}
			break;
		case ITEMKIND_AUTOMATIC:			// 기본무기 
		case ITEMKIND_VULCAN:				// 기본무기 
		case ITEMKIND_DUALIST:				// 기본무기 
		case ITEMKIND_CANNON:				// 기본무기 
		case ITEMKIND_RIFLE:				// 기본무기 
		case ITEMKIND_GATLING:				// 기본무기 
		case ITEMKIND_LAUNCHER:				// 기본무기 
		case ITEMKIND_MASSDRIVE:			// 기본무기 
		case ITEMKIND_ROCKET:				// 고급무기 
		case ITEMKIND_MISSILE:				// 고급무기 
		case ITEMKIND_BUNDLE:				// 고급무기 
		case ITEMKIND_DEFENSE:				// 아머
			{
				// 10첸 이상만 필터
				if ( DESTROY_AUCTION_LISTUP_ITEM_ENCHANT_TYPE_2 <= (BYTE)((*itr)->EnchantCount) )
				{
					tmItemListDes.push_back(*itr);		// 데이터 추가
					tmItemListSource.erase(itr);		// 소스데이터 삭제
				}
				else	{	itr++;	}					// 필터에 안걸리면 다음 값을 확인
			}
			break;
		default:
			tmItemListSource.erase(itr);				// 잘못 등록된 아이템 소스데이터 삭제
			break;
		}
	}

	if ( nSourceListHalfSize < tmItemListDes.size() )
	{
		// 리스트 업 해야하는 수를 초과 하므로 리스트를 삭제한다.
		random_shuffle(tmItemListDes.begin(), tmItemListDes.end());
		while ( nSourceListHalfSize < tmItemListDes.size() )
		{
			DESTROY_AUCTION_ITR itrDelete = tmItemListDes.begin();
			tmItemListDes.erase(itrDelete);
		}
	}
	else if ( nSourceListHalfSize > tmItemListDes.size() )
	{
		// 리스트 업 해야하는 수를 못 미치므로 리스트를 추가한다.
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
				// 더이상 추가할 소스 데이터가 없으면 while문 탈출조건으로 사이즈 변경
				nSourceListHalfSize = tmItemListDes.size();
			}
		}
	}

	m_DestroyAuctionList.clear();
	m_DestroyAuctionList.reserve(tmItemListDes.size());
	m_DestroyAuctionList.assign(tmItemListDes.begin(), tmItemListDes.end());
}

