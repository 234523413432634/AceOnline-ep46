#include "stdafx.h"
#include "ArmorCollection.h"
#include "FieldDataManager.h"
#include "FieldIOCPSocket.h"
#include "AtumLogSender.h"
#include "FieldGlobal.h"

CArmorCollection::CArmorCollection()
{
	m_CollectionList.clear();
	m_CollectionList.reserve(200);
}

void CArmorCollection::CollectionLoad()
{
	//	디비 로드 및 초기값 컬렉션 리스트 클라이언트 전송.(데이터 가공없이 일단 보내줘)	
	if ( NULL != m_pFieldIOCPSocket && NULL != m_pFieldDBManager )
	{
		m_pFieldDBManager->MakeAndEnqueueQuery(QT_CollectionArmorListLoad, m_pFieldIOCPSocket, m_pFieldIOCPSocket->m_character.AccountUniqueNumber, NULL, NULL, 1);
		g_pFieldGlobal->WriteSystemLogEX(FALSE, "  [NOTIFY] SC_COLLECTION_ARMOR_JHSEOL_BCKIM, CArmorCollection::CollectionLoad() - AUID(%d) CUID(%d) CNAME(%d)\r\n",
			m_pFieldIOCPSocket->m_character.AccountUniqueNumber, m_pFieldIOCPSocket->m_character.CharacterUniqueNumber, m_pFieldIOCPSocket->m_character.CharacterName);
	}
}

void CArmorCollection::CollectionUpdate(COLLECTION_INFO *i_pCollectioninfo)
{
	if ( NULL != m_pFieldIOCPSocket && NULL != m_pFieldDBManager && NULL != i_pCollectioninfo )
	{
		COLLECTION_INFO *pQParamCollectionInfo = new COLLECTION_INFO;
		MEMSET_ZERO(pQParamCollectionInfo, sizeof(COLLECTION_INFO));
		memcpy(pQParamCollectionInfo, i_pCollectioninfo, sizeof(COLLECTION_INFO));
		m_pFieldDBManager->MakeAndEnqueueQuery(QT_CollectionArmorUpdate, m_pFieldIOCPSocket, m_pFieldIOCPSocket->m_character.AccountUniqueNumber, pQParamCollectionInfo);
	}
}

void CArmorCollection::CollectionAdd(COLLECTION_INFO* i_pCollectioninfo, BOOL i_bDB_Update /* = FALSE*/)
{
	if ( NULL != i_pCollectioninfo )
	{
		// 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경 - 컬렉션 로드 및 추가시 이달의 아머 이벤트 체크
		BYTE GameLogState = GAMELOG_COLLECTION_STATE_ADD;
#ifdef S_MONTHL_ARMOR_EVENT_JHSEOL_BCKIM	// - 컬렉션 로드 및 추가시 이달의 아머 이벤트 체크
		ATUM_DATE_TIME CurTime(TRUE);
		ItemNum_t tmBeforeOptionItemNum = i_pCollectioninfo->nOptionItemNum;
		ATUM_DATE_TIME tmBeforeDurationTime = i_pCollectioninfo->DurationTime;
		if ( CurTime >= i_pCollectioninfo->DurationTime )
		{
			i_pCollectioninfo->nOptionItemNum = 0;

			if ( NULL != ms_pFieldIOCP2->m_pMonthlyArmorManager)
			{
				ms_pFieldIOCP2->m_pMonthlyArmorManager->CheckMonthlyArmorEventCollection(m_pFieldIOCPSocket, i_pCollectioninfo);
			}
		}
		if ( tmBeforeOptionItemNum != i_pCollectioninfo->nOptionItemNum || tmBeforeDurationTime != i_pCollectioninfo->DurationTime )
		{
			i_bDB_Update = TRUE;	// 적용중인 컬렉션에 대한 이달의 아머 이벤트 정보가 바귀면 DB업데이트 한다.
			GameLogState = GAMELOG_COLLECTION_STATE_MONTHLY_EVENT;
		}
#endif
		// end 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경 - 컬렉션 로드 및 추가시 이달의 아머 이벤트 체크
		COLLECTION_INFO tmCollectionInfo;
		MEMSET_ZERO(&tmCollectionInfo, sizeof(tmCollectionInfo));
		memcpy(&tmCollectionInfo, i_pCollectioninfo, sizeof(tmCollectionInfo));
		m_CollectionList.push_back(tmCollectionInfo);
		
		if ( TRUE == i_bDB_Update )
		{
			CollectionUpdate(i_pCollectioninfo);
			CAtumLogSender::SendLogMessageCollectionState(m_pFieldIOCPSocket, &tmCollectionInfo, GameLogState);	// 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경
		}
	}
}

void CArmorCollection::CollectionEnchant(COLLECTION_INFO* i_pCollectioninfo, BYTE i_nAddEnchantLevel, UINT i_nRemainSeconds)
{
	if( NULL == i_pCollectioninfo )
	{
		return ;
	}

	i_pCollectioninfo->EnchantLevel = min(SHAPE_STAT_MAX_LEVEL, (i_pCollectioninfo->EnchantLevel + i_nAddEnchantLevel));
	i_pCollectioninfo->RemainSeconds = i_nRemainSeconds;
	if ( 0 < i_pCollectioninfo->ActivedCount )
	{
		SetEndTime(i_pCollectioninfo);
	}
	CollectionUpdate(i_pCollectioninfo);
	CAtumLogSender::SendLogMessageCollectionState(m_pFieldIOCPSocket, i_pCollectioninfo, GAMELOG_COLLECTION_STATE_ENCHANT);
}

COLLECTION_INFO* CArmorCollection::ChangeActivedCount(ItemNum_t i_nShapeNum, BOOL i_bIncrease)
{
	COLLECTION_INFO* temp =  GetCollectionInfoPtr(i_nShapeNum);

	if( NULL == temp )
	{
		return NULL;
	}

	if ( TRUE == i_bIncrease )
	{
		temp->ActivedCount++;
		if ( 1 == temp->ActivedCount )
		{
			SetEndTime(temp);
			if ( NULL != m_pFieldIOCPSocket )
			{
				INIT_MSG_WITH_BUFFER(MSG_FC_COLLECTION_INFO, T_FC_COLLECTION_INFO, pCollectionInfo, SendBuf);
				memcpy(pCollectionInfo, temp, sizeof(COLLECTION_INFO));
				m_pFieldIOCPSocket->SendAddData(SendBuf, MSG_SIZE(MSG_FC_COLLECTION_INFO));
				CAtumLogSender::SendLogMessageCollectionState(m_pFieldIOCPSocket, temp, GAMELOG_COLLECTION_STATE_TIME_START);
			}
		}
	}
	else
	{
		temp->ActivedCount = max(0, (temp->ActivedCount - 1));
		if ( 0 == temp->ActivedCount )
		{
			ReFreshRemainSeconds(temp);
			CAtumLogSender::SendLogMessageCollectionState(m_pFieldIOCPSocket, temp, GAMELOG_COLLECTION_STATE_TIME_END);
		}
	}

	return temp;
}

void CArmorCollection::SetEndTime(COLLECTION_INFO* i_pCollectionInfo)
{
	if ( NULL != i_pCollectionInfo )
	{
		i_pCollectionInfo->EndTime.SetCurrentDateTime(FALSE);
		i_pCollectionInfo->EndTime.AddDateTime(0,0,0,0,0,i_pCollectionInfo->RemainSeconds);
	}
}

void CArmorCollection::ReFreshRemainSeconds(COLLECTION_INFO* i_pCollectionInfo)
{
	ATUM_DATE_TIME atCurrentTime(TRUE);
	i_pCollectionInfo->RemainSeconds = (UINT)max(0, i_pCollectionInfo->EndTime.GetTimeDiffTimeInSeconds(atCurrentTime));
	i_pCollectionInfo->EndTime.Reset();
	CollectionUpdate(i_pCollectionInfo);
}

COLLECTION_INFO* CArmorCollection::GetCollectionInfoPtr(ItemNum_t i_nShapeNum)
{
	COLLECTION_LIST::iterator itr = m_CollectionList.begin();
	for ( ; itr != m_CollectionList.end() ; itr++ )
	{
		if ( i_nShapeNum == itr->ShapeNum )
		{
			return &*itr;
		}
	}
	return NULL;
}

ATUM_DATE_TIME CArmorCollection::GetEndTime(ItemNum_t i_nShapeNum)
{
	ATUM_DATE_TIME tmCurrentTime(TRUE);
	COLLECTION_LIST::iterator itr = m_CollectionList.begin();
	for ( ; itr != m_CollectionList.end() ; itr++ )
	{
		if ( i_nShapeNum == itr->ShapeNum )
		{
			if ( 0 < itr->ActivedCount )
			{
				tmCurrentTime = itr->EndTime;
			}
		}
	}
	return tmCurrentTime;
}

void CArmorCollection::CollectionFinish()
{
	COLLECTION_LIST::iterator itr = m_CollectionList.begin();
	for ( ; itr != m_CollectionList.end() ; itr++ )
	{
		if ( 0 < itr->ActivedCount )
		{
			ReFreshRemainSeconds(&*itr);
		}
	}
	m_CollectionList.clear();
}

void CArmorCollection::SendCollectionInfoAllData()
{
	if ( NULL == m_pFieldIOCPSocket )
	{
		g_pFieldGlobal->WriteSystemLogEX(FALSE, "  [ERROR] SC_COLLECTION_ARMOR_JHSEOL_BCKIM, CArmorCollection::SendCollectionInfoAllData() - sock is null\r\n");
		return;
	}
	COLLECTION_LIST::iterator itr = m_CollectionList.begin();
	for ( ; itr != m_CollectionList.end() ; itr++ )
	{
		INIT_MSG_WITH_BUFFER(MSG_FC_COLLECTION_INFO, T_FC_COLLECTION_INFO, pCollectionInfo, SendBuf);
		memcpy(pCollectionInfo, &*itr, sizeof(COLLECTION_INFO));
		m_pFieldIOCPSocket->SendAddData(SendBuf, MSG_SIZE(MSG_FC_COLLECTION_INFO));
	}
}

// 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경
void CArmorCollection::CheckMonthlyArmorEvent(ITEM_GENERAL* io_pItemG, BOOL i_bClientNotify)
{
	if ( NULL == io_pItemG )
	{
		return;
	}
	
	if ( ITEMKIND_DEFENSE != io_pItemG->Kind && FALSE == io_pItemG->ItemInfo->IsExistDesParam(DES_SHAPE_ITEM) )
	{
		return;
	}
	
	ATUM_DATE_TIME atCurrentDate(TRUE);
	ItemNum_t tmBeforeOptionItemNum		= io_pItemG->nMonthlyOptionItemNum;
	ATUM_DATE_TIME tmBeforeEventDate	= io_pItemG->atMonthlyEventEndDate;

	io_pItemG->nMonthlyOptionItemNum	= 0;
	io_pItemG->atMonthlyEventEndDate.Reset();

	if ( (ITEMKIND_DEFENSE == io_pItemG->Kind && io_pItemG->FixedTermShape.nStatLevel > SHAPE_STAT_INIT_LEVEL ) )		// 인첸트 외변킷이 적용된 아머 인지 체크
	{
		COLLECTION_INFO* CollectionInfo = GetCollectionInfoPtr(io_pItemG->ShapeItemNum);
		if ( NULL != CollectionInfo )
		{
			if ( atCurrentDate < CollectionInfo->DurationTime )
			{
				io_pItemG->nMonthlyOptionItemNum = CollectionInfo->nOptionItemNum;
				io_pItemG->atMonthlyEventEndDate = CollectionInfo->DurationTime;
			}
		}
	}
	else if ( TRUE == io_pItemG->ItemInfo->IsExistDesParam(DES_COLLECTION_ARMOR_INDEX) && io_pItemG->ItemInfo->SkillLevel > 0 )	// 인첸트 외변킷 인지 체크
	{
		mtvectMONTHLY_ARMOR_EVNET_INFO * tmMonthlyArmorEventList = ms_pFieldIOCP2->m_pMonthlyArmorManager->GetVectMonthlyArmorEventListPtr();
		if ( NULL != tmMonthlyArmorEventList )
		{
			mt_auto_lock mtA(tmMonthlyArmorEventList);
			mtvectMONTHLY_ARMOR_EVNET_INFO::iterator itrEvent = tmMonthlyArmorEventList->begin();
			for ( ; itrEvent != tmMonthlyArmorEventList->end() ; itrEvent++ )
			{
				if ( atCurrentDate >= itrEvent->atStartDate && atCurrentDate < itrEvent->atEndDate && io_pItemG->ItemInfo->LinkItem == itrEvent->nArmorSourceIndex )
				{
					io_pItemG->nMonthlyOptionItemNum = itrEvent->nOptionItemNum;
					io_pItemG->atMonthlyEventEndDate = itrEvent->atEndDate;
					break;	// 더 있을지도 모르지만 그냥 무시하고 여기서 stop, 가장 첫번째 이벤트만 적용
				}
			}
			mtA.auto_unlock_cancel();
		}
	}

	if ( TRUE == i_bClientNotify )
	{
		if ( tmBeforeOptionItemNum != io_pItemG->nMonthlyOptionItemNum || tmBeforeEventDate != io_pItemG->atMonthlyEventEndDate )
		{
			if ( WEAR_ATTACHED == io_pItemG->Wear )
			{
				ITEM *pBeforeItem = ms_pFieldIOCP2->GetItemInfo(tmBeforeOptionItemNum);
				if ( NULL != pBeforeItem )
				{
#ifdef SC_PREMIUM_COLLECTION_ARMOR_YMJOO_BCKIM	// 2014-07-17 by bckim, 프리미엄 아머 컬렉션
					if( pBeforeItem->IsExistDesParam(DES_PREMIUM_OPTION_ITEM_DEFAULT_DESPARAM))
					{
						m_pFieldIOCPSocket->ReleaseItemDesParamOnlyPremiumAmor(pBeforeItem,io_pItemG->FixedTermShape.nStatLevel);
					}
					else
#endif // End. 2014-07-17 by bckim, 프리미엄 아머 컬렉션						
						
#ifdef SC_OLD_COLLECTION_ARMOR_SHCHOI // 2014-12-29 by shchoi 이달의 구 아머
						if( pBeforeItem->IsExistDesParam(DES_OLD_OPTION_ITEM_DEFAULT_DESPARAM))
						{
							m_pFieldIOCPSocket->ReleaseItemDesParamOnlyOldAmor(pBeforeItem,io_pItemG->FixedTermShape.nStatLevel);
						}
						else
#endif // end 2014-12-24 by shchoi 이달의 구 아머
					{
					m_pFieldIOCPSocket->ReleaseItemDesParam(pBeforeItem);
				}
				}
				
				if ( atCurrentDate < io_pItemG->atMonthlyEventEndDate )
				{
					ITEM *pAfterItem = ms_pFieldIOCP2->GetItemInfo(io_pItemG->nMonthlyOptionItemNum);
					if ( NULL != pAfterItem )
					{
#ifdef SC_PREMIUM_COLLECTION_ARMOR_YMJOO_BCKIM	// 2014-07-17 by bckim, 프리미엄 아머 컬렉션
						if( pAfterItem->IsExistDesParam(DES_PREMIUM_OPTION_ITEM_DEFAULT_DESPARAM))		// 2014-08-06 by bckim, 프리미엄 아머 컬렉션 버그수정 
						{
							m_pFieldIOCPSocket->ApplyItemDesParamOnlyPremiumAmor(pAfterItem,io_pItemG->FixedTermShape.nStatLevel);	// 2014-08-06 by bckim, 프리미엄 아머 컬렉션 버그수정
						}
						else
#endif // End. 2014-07-17 by bckim, 프리미엄 아머 컬렉션	
							
#ifdef SC_OLD_COLLECTION_ARMOR_SHCHOI // 2014-12-29 by shchoi 이달의 구 아머
						if( pAfterItem->IsExistDesParam(DES_OLD_OPTION_ITEM_DEFAULT_DESPARAM))
						{
							m_pFieldIOCPSocket->ApplyItemDesParamOnlyOldAmor(pAfterItem,io_pItemG->FixedTermShape.nStatLevel);
						}
						else
#endif // end 2014-12-24 by shchoi 이달의 구 아머

						{
						m_pFieldIOCPSocket->ApplyItemDesParam(pAfterItem);
						}						
					}
				}
			}
			
			INIT_MSG_OF_SIZE(MSG_FC_STORE_UPDATE_ARMOR_ITEM_EVENT_INFO, T_FC_STORE_UPDATE_ARMOR_ITEM_EVENT_INFO, pUpdateArmorEventInfo, pUpdateArmorEventInfoBuf);
			pUpdateArmorEventInfo->ItemUID			= io_pItemG->UniqueNumber;
			pUpdateArmorEventInfo->nOptionItemNum	= io_pItemG->nMonthlyOptionItemNum;
			pUpdateArmorEventInfo->atEndDate		= io_pItemG->atMonthlyEventEndDate;
			m_pFieldIOCPSocket->SendAddData(pUpdateArmorEventInfoBuf, MSG_SIZE(MSG_FC_STORE_UPDATE_ARMOR_ITEM_EVENT_INFO));
		}
	}
}
// end 2013-09-06 by jhseol, 이달의 아머 이벤트 적용 기간 변경