#include "stdafx.h"
#include "FieldTickManager.h"
#include "FieldIOCP.h"
#include "FieldGlobal.h"	// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� �������� - �α׸� ����� ���� �ش� ����

CFieldTickManager::CFieldTickManager(CFieldIOCP *i_pFieldIOCP, DWORD i_nTickInterval /* = FIELD_DEFAULT_TICK_INTERVAL */)
: CTickManager(i_nTickInterval)
{
	m_pFieldIOCP6 = i_pFieldIOCP;
}

CFieldTickManager::~CFieldTickManager()
{
}

void CFieldTickManager::DoTickEvent(ATUM_DATE_TIME *pDateTime, TICK_EVENT *pTickEvent)
{
#ifdef _DEBUG
	DBGOUT(STRMSG_S_F2NOTIFY_0141, pDateTime->GetDateTimeString(STRNBUF(SIZE_MAX_ATUM_DATE_TIME_STRING)));
#endif
	
	// 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
#ifdef S_ITEM_EVENT_SUB_TYPE_JHSEOL
	switch( pTickEvent->TickEventType )
	{
	case SM_TICK_EVENT_SUB_ITEM_EVENT:
		{
			if ( TRUE == g_pFieldGlobal->IsArenaServer() )	// �Ʒ��� �������� ����Ÿ�� �̺�Ʈ �������� �������� �ʴ´�.
			{
				return;
			}
			int nItemEventUID = pTickEvent->nTickEventParam1;
			UID32_t nCharacterUID = pTickEvent->nTickEventParam2;
			int nPlayTimeBySecond = (int)pTickEvent->vpTickEventParam1;
			CFieldIOCPSocket *pSock = m_pFieldIOCP6->GetFieldIOCPSocketByCharacterUniqueNumber(nCharacterUID, TRUE);
			if ( NULL == pSock )
			{
				g_pFieldGlobal->WriteSystemLogEX(TRUE, "[S_ITEM_EVENT_SUB_TYPE_JHSEOL][Error1] CFieldTickManager::DoTickEvent, CUID(%8d) pSock Is NULL \r\n", nCharacterUID);
				return;
			}

			ATUM_DATE_TIME atCurrentDateTime;
			atCurrentDateTime.SetCurrentDateTime();
			if ( nPlayTimeBySecond > atCurrentDateTime.GetTimeDiffTimeInSeconds(pSock->m_character.LastStartedTime) )
			{
				char timestr[SIZE_MAX_SQL_DATETIME_STRING] = {0,};
				pSock->m_atLoginDate.GetSQLDateTimeString(timestr, SIZE_MAX_SQL_DATETIME_STRING);
				g_pFieldGlobal->WriteSystemLogEX(TRUE, "[S_ITEM_EVENT_SUB_TYPE_JHSEOL][Error2] CFieldTickManager::DoTickEvent, CUID(%8d) Re Start User (%s) EventTime(%d)\r\n", nCharacterUID, timestr, nPlayTimeBySecond);
				return;
			}

			SITEM_EVENT_INFO* ItemEventInfo = m_pFieldIOCP6->m_pGiveItemManager->GetItemEventInfoByEventUID(nItemEventUID);
			if ( NULL == ItemEventInfo )
			{
				g_pFieldGlobal->WriteSystemLogEX(TRUE, "[S_ITEM_EVENT_SUB_TYPE_JHSEOL][Error3] CFieldTickManager::DoTickEvent, CUID(%8d) ItemEevntUID(%4d) ItemEventInfo Is NULL \r\n",nCharacterUID, nItemEventUID);
				return;
			}
			g_pFieldGlobal->WriteSystemLogEX(TRUE, "[S_ITEM_EVENT_SUB_TYPE_JHSEOL][Notify] CFieldTickManager::DoTickEvent, Run TickEvent AUID(%8d) CUID(%8d) ItemEevntUID(%4d) \r\n"
				, pSock->m_character.AccountUniqueNumber, pSock->m_character.CharacterUniqueNumber, nItemEventUID);
			if ( TRUE == m_pFieldIOCP6->ItemEventSubTypeCheck(pSock->m_character.AccountUniqueNumber, pSock->m_character.CharacterUniqueNumber, *ItemEventInfo, ITEM_EVENT_DES_PLAY_TIME) )
			{
				// 2013-04-22 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰����� �ý��� ����
				if( TRUE== pSock->IsValidCharacter(FALSE, TRUE) )
				{
					QPARAM_CHECK_EVENTITEM *pQParam = new QPARAM_CHECK_EVENTITEM;
					pQParam->AccountUID		= pSock->m_character.AccountUniqueNumber;
					pQParam->ItemEventUID	= ItemEventInfo->ItemEventUID;
					pQParam->ItemEventType  = ItemEventInfo->ItemEventType;
					pQParam->ItemNum		= ItemEventInfo->ItemNum;
					pQParam->Count			= ItemEventInfo->Count;
					pQParam->PrefixCodeNum	= ItemEventInfo->PrefixCodeNum;
					pQParam->SuffixCodeNum	= ItemEventInfo->SuffixCodeNum;
					pQParam->CharacterUID	= pSock->m_character.CharacterUniqueNumber;	// 2014-03-12 by jekim, �ֹι�ȣ�� ������ ���� // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - 
					pQParam->CheckWithCharacterUID = ItemEventInfo->CheckWithCharacterUID; // 2014-03-12 by jekim, �ֹι�ȣ�� ������ ����

					if ( CS_ARENASERVER_PLAYING == pSock->GetClientState() )
					{
						pQParam->InsertStorage = ITEM_IN_STORE;		// �Ʒ������� �̿����̸� â��� �������� �־��ش�.
					}
					m_pFieldIOCP6->m_pAtumDBManager->MakeAndEnqueueQuery(QT_CheckEventItem, pSock, pSock->m_character.AccountUniqueNumber, pQParam);
				}
				// end 2013-04-22 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰����� �ý��� ����
			}
		}
		break;
	default:
		{
		}
		break;
	}
#endif
	// end 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
	return;
}

void CFieldTickManager::DoEveryTickWork(ATUM_DATE_TIME *pDateTime)
{
}

void CFieldTickManager::DoDailyWork(ATUM_DATE_TIME *pDateTime)
{
	m_pFieldIOCP6->ResetAllP2PPKFamePoint();
}

void CFieldTickManager::DoHourlyWork(ATUM_DATE_TIME *pDateTime)
{
	m_pFieldIOCP6->OnDoHourlyWorkIOCP(pDateTime);
}

void CFieldTickManager::DoMinutelyWork(ATUM_DATE_TIME *pDateTime)
{
	m_pFieldIOCP6->OnDoMinutelyWorkIOCP(pDateTime);
}

void CFieldTickManager::DoSecondlyWork(ATUM_DATE_TIME *pDateTime)
{
	m_pFieldIOCP6->OnDoSecondlyWorkFIOCP(pDateTime);
}
