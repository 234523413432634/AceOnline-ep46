#include "stdafx.h"
#include "FieldIOCP.h"
#include "MarketDataManager.h"

CMarketDataManager::CMarketDataManager(CFieldIOCP *i_pFieldIOCP)
{
	ms_pFieldIOCP = i_pFieldIOCP;
	m_vectMarketPtr.reserve(MARKET_VECTOR_SIZE);
}

CMarketDataManager::~CMarketDataManager()
{
	if( FALSE == m_vectMarketPtr.empty() )
	{
		for_each(m_vectMarketPtr.begin(), m_vectMarketPtr.end(), Delete_Object());
		m_vectMarketPtr.clear();
	}
}

MARKET_LIST* CMarketDataManager::GetMarketListPtr()
{
	return &m_vectMarketPtr;
}

void CMarketDataManager::CopyMarketList(MARKET_LIST *o_MarketList)
{
	if( TRUE == m_vectMarketPtr.empty() )
	{
		return;
	}
	mt_auto_lock mtMarket(&m_vectMarketPtr);
	o_MarketList->assign(m_vectMarketPtr.begin(), m_vectMarketPtr.end());
//	*o_MarketList = m_vectMarketPtr;
}

void CMarketDataManager::InsertMarket(MARKET_INFO i_MarketItem)
{
	mt_auto_lock mtMarket(&m_vectMarketPtr);
	MARKET_INFO *pMarket = new MARKET_INFO(&i_MarketItem);
	m_vectMarketPtr.push_back(pMarket);
}

void CMarketDataManager::UpdateMarket(UID64_t i_nMarketUID, BYTE i_nMarketState)
{
	mt_auto_lock mtMarket(&m_vectMarketPtr);
	MARKET_ITR itr = find_if(m_vectMarketPtr.begin(), m_vectMarketPtr.end(), MARKET_LIST_MarketUID_Find_Object(i_nMarketUID));
	if ( itr != m_vectMarketPtr.end() )
	{
		(*itr)->MarketState = i_nMarketState;
	}
}

MARKET_INFO* CMarketDataManager::GetpMarketInfo(UID64_t i_nMarketUID)
{
	mt_auto_lock mtMarket(&m_vectMarketPtr);
	MARKET_ITR itr = find_if(m_vectMarketPtr.begin(), m_vectMarketPtr.end(), MARKET_LIST_MarketUID_Find_Object(i_nMarketUID));
	if ( itr != m_vectMarketPtr.end() )
	{
		return (*itr);
	}

	return NULL;
}

// 마켓비용처리 
BOOL CMarketDataManager::MarketExpenses(MARKET_INFO * pMarketItem, CFieldIOCPSocket * pBuyersocket)
{
	
	if ( NULL ==  pMarketItem || NULL == pBuyersocket)
	{
		return FALSE;
	}
	
	// 비용처리 부분 
	if( pMarketItem->MoneyType == MARKET_MONEY_TYPE_SPI)
	{	
		ITEM_GENERAL *pMoney = pBuyersocket->m_ItemManager.GetFirstItemGeneralByItemNum(MONEY_ITEM_NUMBER);		// DB 처리 같이 함 
		if( NULL == pMoney )
		{
			pBuyersocket->SendErrorMessage(T_FC_MARKET_BUY_REQUEST, ERR_PROTOCOL_ALREADY_HAVE_ITEM);		
		//	SAFE_DELETE(tmpMarketInfo);
		//	SQLFreeStmt(hstmt, SQL_CLOSE);
			return FALSE;
		}
		pBuyersocket->m_ItemManager.UpdateItemCountByPointer(pMoney, -(pMarketItem->Price), IUT_MARKET);		
	}
	else if( pMarketItem->MoneyType == MARKET_MONEY_TYPE_WP)
	{	// DB 처리 같이 함 
		pBuyersocket->WPAddWarPoint(-(pMarketItem->Price), FALSE, TRUE, WPUT_MARKET);		
	}	
	else
	{
		return FALSE;
	}
	return TRUE;
}

// 아이템 제너럴 생성 
ITEM_GENERAL* CMarketDataManager::MarketMakeItemGeneral(MARKET_INFO * pMarketInfo, CFieldIOCPSocket * pFieldIOCPSocket)
{
	if( NULL == pMarketInfo || NULL == pFieldIOCPSocket)
	{
		return NULL;
	}
	
	ITEM_GENERAL *o_pItemGeneral = (ITEM_GENERAL*)(pFieldIOCPSocket->m_ItemManager.MakeNewItem(pMarketInfo->ItemNum, ITEM_IN_CHARACTER));
	if (o_pItemGeneral == NULL || !IS_GENERAL_ITEM(o_pItemGeneral->Kind))
	{
		return NULL;
	}
	
	o_pItemGeneral->AccountUniqueNumber = pMarketInfo->AccountUID; 
	o_pItemGeneral->UniqueNumber	= pMarketInfo->ItemUID;
	o_pItemGeneral->PrefixCodeNum	= pMarketInfo->PrefixCodeNum;
	o_pItemGeneral->SuffixCodeNum = pMarketInfo->SuffixCodeNum;
	o_pItemGeneral->ShapeItemNum  = pMarketInfo->ShapeItemNum;
	o_pItemGeneral->ColorCode		= pMarketInfo->ColorCode;
	o_pItemGeneral->CurrentCount	= pMarketInfo->ItemCount;			
	
	if(FALSE == pFieldIOCPSocket->m_ItemManager.InsertItemGeneralByPointer(o_pItemGeneral, IUT_MARKET, FALSE, ITEM_IN_CHARACTER, FALSE, TRUE, pFieldIOCPSocket->m_character.CharacterUniqueNumber))
	{
		return NULL; 
	}				
	return o_pItemGeneral;
}