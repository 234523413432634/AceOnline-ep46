#ifndef _ATUM_AUTHENTICATION_TICK_MANAGER_H_
#define _ATUM_AUTHENTICATION_TICK_MANAGER_H_

#include "TickManager.h"

class CAuthenticationIOCP;

class CAuthenticationTickManager : public CTickManager
{
public:
	CAuthenticationTickManager(CAuthenticationIOCP *i_pAuthenticationIOCP, DWORD i_nTickInterval = 1000);
	virtual ~CAuthenticationTickManager();

	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent) {}
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime){};	// �Ѵ޿� �� �� �� �ؾ� �� ��

public:
	CAuthenticationIOCP *m_pAuthenticationIOCP1;
};

#endif // _ATUM_AUTHENTICATION_TICK_MANAGER_H_
