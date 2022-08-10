#ifndef _ATUM_PRE_TICK_MANAGER_H_
#define _ATUM_PRE_TICK_MANAGER_H_

#include "TickManager.h"

class CPreIOCP;

class CPreTickManager : public CTickManager
{
public:
	CPreTickManager(CPreIOCP *i_pPreIOCP, DWORD i_nTickInterval = 1000);
	virtual ~CPreTickManager();

	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent) {}
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime){};	// 2005-12-27 by cmkwon, �Ѵ޿� �� �� �� �ؾ� �� ��

public:
	CPreIOCP *m_pPreIOCP1;
};

#endif // _ATUM_PRE_TICK_MANAGER_H_
