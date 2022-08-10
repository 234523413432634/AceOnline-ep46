#ifndef _MGR_FIELD_MARKET_DATA_MANAGER_H_
#define _MGR_FIELD_MARKET_DATA_MANAGER_H_

class CMarketDataManager
{
public:
	CMarketDataManager(CFieldIOCP *i_pFieldIOCP);
	virtual ~CMarketDataManager();

	MARKET_LIST* GetMarketListPtr();
	void CopyMarketList(MARKET_LIST *o_MarketList);
	void InsertMarket(MARKET_INFO i_MarketItem);
	void UpdateMarket(UID64_t i_nMarketUID, BYTE i_nMarketState);
	
	MARKET_INFO* GetpMarketInfo(UID64_t i_nMarketUID);

	BOOL MarketExpenses(MARKET_INFO * pMarketItem, CFieldIOCPSocket * pBuyersocket);					// 마켓 물품구매 비용처리 
	ITEM_GENERAL * MarketMakeItemGeneral(MARKET_INFO * pMarketItem, CFieldIOCPSocket * pBuyersocket);	// 아이템 제너럴 생성 
	
protected:
	MARKET_LIST		m_vectMarketPtr;

	CFieldIOCP *ms_pFieldIOCP;
};

#endif // _MGR_FIELD_MARKET_DATA_MANAGER_H_
