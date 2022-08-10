// NPCTickManager.h: interface for the CNPCTickManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NPCTICKMANAGER_H__E9D91658_B931_40F7_BBFD_DE11FCE6A94A__INCLUDED_)
#define AFX_NPCTICKMANAGER_H__E9D91658_B931_40F7_BBFD_DE11FCE6A94A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TickManager.h"
#include "NPCIOCPSocket.h"

#define NPC_DEFAULT_TICK_INTERVAL			500		// 0.5 second

class CNPCTickManager : public CTickManager  
{
public:
	CNPCTickManager(CNPCIOCP *i_pNPCIOCP, DWORD i_nTickInterval = NPC_DEFAULT_TICK_INTERVAL);
	virtual ~CNPCTickManager();

	void DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent);
	void DoEveryTickWork(ATUM_DATE_TIME *pDateTime);	// �Ź� �����ؾ� �� ��
	void DoDailyWork(ATUM_DATE_TIME *pDateTime);		// �Ϸ翡 �� �� �� �ؾ� �� ��
	void DoHourlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ð����� �� �� �� �ؾ� �� ��
	void DoMinutelyWork(ATUM_DATE_TIME *pDateTime);		// �� �и��� �� �� �� �ؾ� �� ��
	void DoSecondlyWork(ATUM_DATE_TIME *pDateTime);		// �� �ʸ��� �� �� �� �ؾ� �� ��
	void DoMonthlyWork(ATUM_DATE_TIME *pDateTime){};	// 2005-12-27 by cmkwon, �Ѵ޿� �� �� �� �ؾ� �� ��

public:
	CNPCIOCP		*m_pNPCIOCP2;
};

#endif // !defined(AFX_NPCTICKMANAGER_H__E9D91658_B931_40F7_BBFD_DE11FCE6A94A__INCLUDED_)
