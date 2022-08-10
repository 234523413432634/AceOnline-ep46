#ifndef _MGR_FIELD_DESTROY_AUCTION_MANAGER_H_
#define _MGR_FIELD_DESTROY_AUCTION_MANAGER_H_

class CDestroyAuctionManager
{
public:
	CDestroyAuctionManager(CFieldIOCP *i_pFieldIOCP);
	virtual ~CDestroyAuctionManager();

	DESTROY_AUCTION_LIST* GetDestroyAuctionListPtr();
	void CopyDestroyAuctionList(DESTROY_AUCTION_LIST *o_DestroyAuctionList);
	void InsertDestroyAuction(DESTROY_AUCTION_INFO i_DestroyAuctionItem);
	void UpdateDestroyAuction(UID64_t i_nDestroyAuctionUID, BYTE i_nDestroyAuctionState);
	void UpdateDestroyAuctionTenderInfo(MSG_FC_DESTROY_AUCTION_TENDER_REQUEST *i_pTenderInfo);
	DESTROY_AUCTION_INFO* GetpDestroyAuctionInfo(UID64_t i_nDestroyAuctionUID);
	void SetDestroyAuctionStartEndTime();
	void InitDestroyAuctionEndTime()			{ m_atDAuctionEndTime.SetCurrentDateTime(); };
	ATUM_DATE_TIME GetDestroyAuctionStartTime()	{ return m_atDAuctionStartTime; };
	ATUM_DATE_TIME GetDestroyAuctionEndTime()	{ return m_atDAuctionEndTime; };
	void SetItemDestroyTimeFilter();
	ATUM_DATE_TIME GetItemDestroyTimeFilterBegin()	{ return m_atItemDestroyTimeFilterBegin; };
	ATUM_DATE_TIME GetItemDestroyTimeFilterEnd()	{ return m_atItemDestroyTimeFilterEnd; };
	void DestroyItemListUP();

protected:
	DESTROY_AUCTION_LIST		m_DestroyAuctionList;
	ATUM_DATE_TIME	m_atDAuctionStartTime;	// ��� ���� �ð�
	ATUM_DATE_TIME	m_atDAuctionEndTime;	// ��� ���� �ð�
	CFieldIOCP *ms_pFieldIOCP;
	ATUM_DATE_TIME m_atItemDestroyTimeFilterBegin;	// ��ſ� �ö� �����۵��� �ı��ð� ���� - ����
	ATUM_DATE_TIME m_atItemDestroyTimeFilterEnd;	// ��ſ� �ö� �����۵��� �ı��ð� ���� - ����
};

#endif // _MGR_FIELD_DESTROY_AUCTION_MANAGER_H_
