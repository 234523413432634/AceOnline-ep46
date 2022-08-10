#ifndef _FIELD_TICK_MANAGER_H_
#define _FIELD_TICK_MANAGER_H_

#include "TickManager.h"
#include "FieldIOCPSocket.h"

#define FIELD_DEFAULT_TICK_INTERVAL			500		// 0.5 second

// event types
#define FIELD_TICK_EVENT_END_GUILD_WAR			0

class CFieldTickManager : public CTickManager
{
public:
	CFieldTickManager(CFieldIOCP *i_pFieldIOCP, DWORD i_nTickInterval = FIELD_DEFAULT_TICK_INTERVAL);
	virtual ~CFieldTickManager();

	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent);
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime){};	// 2005-12-27 by cmkwon, �Ѵ޿� �� �� �� �ؾ� �� ��

public:
	CFieldIOCP		*m_pFieldIOCP6;
};

#endif // _ATUM_FIELD_TICK_MANAGER_H_
