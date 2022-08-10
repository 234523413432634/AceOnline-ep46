#ifndef __ATUM_DB_MANAGER_H__
#define __ATUM_DB_MANAGER_H__

#include "StdAfx.h"

#include <sql.h>
#include <sqlext.h>
#include "mt_stl.h"
#include "ThreadCheck.h"
#include "windows.h"
#include "AtumDBHelper.h"

using namespace std;

#define MAXDBMSGBUFLEN						255
#define SIZE_MAX_SQL_PATTERN_BUFFER			64

#define COUNT_MAX_DBWORKER_THREADS			100

#define COUNT_PRE_SERVER_DBWORKER			50
#define COUNT_LOG_SERVER_DBWORKER			15		// 2006-05-21 by cmkwon
#define COUNT_IM_SERVER_DBWORKER			15		// 2006-05-21 by cmkwon
#define COUNT_FIELD_SERVER_DBWORKER			25		// 2006-05-21 by cmkwon
#define COUNT_AUTHENTICATION_SERVER_DBWORKER			15		// 2011-01-26 by hskim, ���� ���� ����

DWORD WINAPI DBWorkerThread(LPVOID lpParam);
DWORD WINAPI DBDynamicWorkerThread(LPVOID lpParam);		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 

class CAtumDBManager;
class CIOCPSocket;
class CIOCP;

enum EnumQueryType
{
	QT_CreateCharacter = 0,
	QT_DeleteCharacter,
	QT_GetCharacterInfoByName,
	QT_GetAccountUniqueNumber,
	QT_ConnectGameStart,
	QT_GetAllCharacterInfoByID,
	QT_SaveCharacterCriticalData,
	QT_ChangeUnitKind,
	QT_ChangeStat,
	QT_ChangeBonusStatPoint,			// 2005-11-15 by cmkwon, �߰���
	QT_ChangeGuild,
	QT_ChangeFriendGroup,
	QT_ChangeExp,
	QT_ChangeLevel,
	QT_ChangeBodyCondition,
	QT_ChangePropensity,

	QT_ChangeInfluenceType,
	QT_ChangeStatus,
	QT_ChangePKPoint,
// 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - ������� �����Ƿ� ����
//	QT_ChangeRacingPoint,
	QT_UpdateTotalPlayTime,
	QT_UpdateLastStartedTime,
	QT_ChangeHPDPSPEP,
	QT_ChangeCurrentHPDPSPEP,
	QT_ChangeMapChannel,
	QT_ChangePetInfo,
	QT_ChangeDockingItem,
	QT_ChangePosition,
	QT_EventWarpConnect,
	// Item ���� query��
	QT_GetStoreItem,
	QT_ReloadAllEnchant,
	QT_DeleteStoreItem,
	QT_InsertStoreItem,
	QT_InsertStoreItemSkill,
	QT_UpdateStoreItemSkillUseTime,		// 2006-11-17 by dhjin
	QT_UpdateItemCount,
	QT_UpdateItemNum,					// 2006-06-14 by cmkwon
	QT_UpdateEndurance,
	QT_StoreUpdateColorCode,			// 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - EffectItemNum �� �ǹ̷� ���, // 2005-11-21 by cmkwon, �߰���
	QT_UpdateShapeItemNum,				// 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - 

	QT_UpdateItemUsingTimeStamp,
	QT_UpdateItemRareFix,
	QT_InsertDefaultItems,
	QT_ChangeItemPosition,
	QT_UpdateWindowItemList,
	QT_UpdateItemPossess,
	QT_UpdateItemStorage,		// 2005-12-07 by cmkwon
	QT_LoadOneItem,			// �ϳ��� ������ �ε� �� ����, ��æƮ ���� ����
	QT_INSERTLOGINITEMEVENT,	// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
	QT_CheckEventItem,		// 2006-08-25 by dhjin, �̺�Ʈ ������ ����
	QT_InsertEventItem,		// 2006-08-25 by dhjin, �̺�Ʈ ������ ����
	QT_UpdateEventItemFixedPeriod,					// 2013-02-28 by bckim, �������� �����߰�
	QT_CheckCouponEvent,	// 2008-01-10 by cmkwon, ������ �̺�Ʈ �ý��ۿ� �� ���� �ý��� �߰� - 
	QT_GetGuildStoreItem,	// 2006-09-20 by dhjin, ���� â�� ����
	QT_UpdateGuildStoreItem,	// 2006-09-20 by dhjin, ���� â�� ����
	QT_InsertGuildStoreItem,	// 2006-09-20 by dhjin, ���� â�� ����
	QT_DeleteGuildStoreItem,	// 2006-09-20 by dhjin, ���� â�� ����
	QT_GetLogGuildStoreItem,	// 2006-09-27 by dhjin, ���� â�� �α� ����
	QT_AllDeleteGuildStoreItem, // 2006-09-29 by dhjin, ���� â�� ����
	QT_Insert2WarpableUserList,	// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �����㰡 �߰�
	QT_DeleteWarpableUser,		// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �����㰡 ����
	QT_UPDATE_ConnectingServerGroupID,		// 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - �߰� ��
	QT_GiveStoreItem,						// 2007-11-13 by cmkwon, �����ϱ� ��� �߰� - 
	QT_GetLetter,					// 2008-04-24 by dhjin, EP3 ���� �ý��� - DB���� ���� ��������
	QT_ReadLetter,					// 2008-04-24 by dhjin, EP3 ���� �ý��� - ���� �б�
	QT_DeleteLetter,				// 2008-04-24 by dhjin, EP3 ���� �ý��� - ���� ����
	QT_SendLetter,					// 2008-05-08 by dhjin, EP3 ���� �ý��� - ���� ������
	QT_GetAllLetter,				// 2008-05-09 by dhjin, EP3 ���� �ý��� - DB���� ��ü ���� ��������
	QT_SendAllLetter,				// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� ������
	QT_ReadAllLetter,				// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� �б�
	QT_DeleteAllLetter,				// 2008-05-09 by dhjin, EP3 ���� �ý��� - ��ü ���� ����
	QT_DeleteOldAllLetter,			// 2008-05-09 by dhjin, EP3 ���� �ý��� - ������ ��ü ���� ����

	// IM Server��
	QT_AuthChatLogin,
	QT_SaveLastPartyID,
	// Guild ����
	QT_GuildCreate,
	QT_GuildAddMember,
	QT_GuildAddOffMember,			// 2008-06-12 by dhjin, EP3 - ���� ���� ���� - �������� ���� ���� 		
	QT_GuildLeaveMember,
	QT_GuildBanMember,
	QT_GuildUpdateMemberCapacity,
	QT_GuildLoadGuild,
	QT_GuildDismember,			// ����� ��ü ��¥�� ���¸� �����ϱ�
	QT_GuildCancelDismember,
	QT_GuildChangeGuildName,
	QT_GuildSetGuildMark,
// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - ������� �ȴ� �Լ���
//	QT_GuildGetGuildMark,
	QT_GuildSetRank,
	QT_GuildDeleteGuild,		// ��带 ������ �����ϱ�
	QT_GuildSaveGuildWarPoint,
	QT_GuildDeleteGuildUIDOfCharacter,
	QT_GuildAddGuildFame,				// 2005-12-27 by cmkwon, ���ܸ� ����
	QT_GuildUpdateCommander,			// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - ������ ����
	QT_GuildNotice,						// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - ���� ����
	QT_GuildGetApplicant,				// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	QT_GuildGetIntroduction,			// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	QT_GuildDeleteIntroduction,			// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ�
	QT_GetSelfIntroduction,				// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� ������ �Ұ���
	QT_GuildSearchIntroduction,			// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - ���� �Ұ� �˻�
	QT_GuildUpdateIntroduction,			// 2008-05-27 by dhjin,	EP3 - ���� ���� ���� - ���� �Ұ� �ۼ�
	QT_GuildUpdateSelfIntroduction,		// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� �ۼ� 
	QT_GuildDeleteSelfIntroduction,		// 2008-05-27 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� ����� 
	QT_GuildDeleteSelfIntroductionOffUser,		// 2008-06-13 by dhjin, EP3 - ���� ���� ���� - �ڱ� �Ұ� ����� 

	// Trade
	QT_ExecuteTrade,
	QT_TradeMoveItem,					// 2006-05-11 by cmkwon, �ŷ��� ������ �̵�
	// Enchant
	QT_InsertEnchant,
	QT_DeleteAllEnchant,
	// Quest
	QT_GetAllQuest,					// ������� �������̰ų� �Ϸ�� ��� quest�� loading
	QT_InsertQuest,					// ������� quest�� ����
	QT_UpdateQuestState,			// Quest ���� ���� ������Ʈ
	QT_DeleteQuest,					// Quest�� ����
	QT_UpdateQuestMonsterCount,		// ���� ī��Ʈ �߰� Ȥ�� ����
	QT_DeleteQuestMonsterCount,		// ���� ī��Ʈ ����

	// Auction
	QT_AuctionGetItemList,		// ��� ������ ��� ��û
	QT_AuctionRegisterItem,		// ��� ������ ���
	QT_AuctionCancelRegister,	// ��� ������ ��� ���
	QT_AuctionBuyItem,			// ��� ������ ����
	QT_InsertCombatPowerLog,	// 2014-03-14 by jekim, ������ �α� �߰�

	// �Ϲ� query ����
	QT_GeneralExec,
	// Pre Server
	QT_PRE_Login,
	QT_BlockUser,
	QT_UnblockUser,
	QT_MGameLogin,
	QT_LogTotalUser,
	QT_InsertGlogAccount,		// 2010-06-01 by shcho, GLogDB ���� -
	// IM Server - Friend List
	QT_FriendInsertFriend,
	QT_FriendDeleteFriend,
	QT_FriendLoadFriends,
	// ����ȭ �����̾� ī�� 
	QT_CashInsertPremiumCard,
	QT_CashUpdatePremiumCard,
	QT_CashDeletePremiumCard,
	// HappyHourEvent ����
	QT_LoadHappyHourEvent,
	QT_UpdateHappyHourEventDate,
	// 2006-08-31 by dhjin, ItemEvent ����
	QT_LoadItemEvent,

// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList ���� - 
//	QT_UpdatePCBangList,	// 2007-01-22 by dhjin, PC�� 

	// 2006-09-04 by dhjin, �� ���� ����
	QT_Get_QuickSlot,	
	QT_Delete_QuickSlot,
	QT_Update_QuickSlot,
	// 2007-02-28 by dhjin, ��������Ʈ ���� �ֱ� ���� ����.
	QT_LoadStrategyPointSummonInfo,				
	QT_UpdateStrategyPointSummonInfoBySummon,
	QT_UpdateStrategyPointSummonInfoBySummonTime,
	QT_InsertStrategyPointSummonInfoBySummon,
	QT_DeleteStrategyPointSummonInfoBySummon,
	QT_UpdateStrategyPointSummonInfoByNewSummonRange,
	QT_LoadStrategyPointSummonRange,
	QT_LoadStrategyPointNotSummonTime,
	QT_LoadStrategyPointNotSummonTimeByAdminTool,
	
	QT_UpdateInfluenceWarData,			// 2006-04-14 by cmkwon
	QT_UpdateOwnerOfConflictArea,		// 2006-07-12 by cmkwon, �������� ������ 

	QT_UpdateSubleader,					// 2007-02-13 by dhjin, �������� ����

	QT_JamboreeInit,					// 2007-04-10 by cmkwon, ��ȸ������ DB(atum2_db_20) �ʱ�ȭ
	QT_JamboreeEntrants,				// 2007-04-10 by cmkwon, ĳ���͸� ��ȸ������ DB(atum2_db_20)�� ����

	// 2007-04-25 by dhjin, WarPoint ����
	QT_UpdateWarPoint,					// 2007-04-25 by dhjin
	// 2007-06-07 by dhjin, Arena��� ����
	QT_UpdateArenaResult,					// 2007-06-07 by dhjin
	QT_UpdateArenaDisConnect,				// 2007-06-07 by dhjin

	// 2007-07-06 by dhjin, Tutorial
	QT_LoadTutorialComplete,
	QT_InsertTutorialComplete,

	// 2007-08-21 by dhjin, OutPost
	QT_SetNPCPossessionOutPost,
	QT_SetGuildPossessionOutPost,
	QT_SetOutPostNextWarTime,

	// 2007-08-22 by dhjin, CityLeader
	QT_InitExpediencyFund,
	QT_SetExpediencyFund,
	QT_SetExpediencyFundPayBack,
	QT_SetExpediencyFundRate,
	QT_DeleteCityLeaderInfo,
	QT_RegNotice,
	QT_ModifyNotice,

	// 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� -
	QT_UpdateSecondaryPassword,		// 2���н����� ������Ʈ

	// 2007-10-29 by dhjin, poll����
	QT_LoadVoterList,
	QT_LoadLeaderCandidate,
	QT_SelectLeaderCandidateInfoByRealTimeVariable,
	QT_InsertLeaderCandidate,
	QT_UpdateLeaderDeleteCandidate,
	QT_UpdateLeaderPollCount,
	QT_InsertVoterList,

	QT_CheckGiveTarget,			// 2007-11-13 by cmkwon, �����ϱ� ��� �߰� - �߰�
	QT_UpdatePilotFace,			// 2007-11-21 by cmkwon, PilotFace ���� ī�� ���� - �߰�

	QT_InsertNotifyMsg,			// 2007-11-28 by cmkwon, �����ý��� ���� -
	QT_GetNotifyMsg,			// 2007-11-28 by cmkwon, �����ý��� ���� -
	QT_DeleteNotifyMsg,			// 2007-11-28 by cmkwon, �����ý��� ���� -

	QT_GetGuildMark,			// 2007-12-07 by dhjin

	//////////////////////////////////////////////////////////////////////////
	// 2007-12-28 by dhjin, �Ʒ��� ���� - 
	QT_ArenaUpdateCharacterInfo,		 // 2007-12-28 by dhjin, �Ʒ��� ���� - �ɸ��� ���� ������Ʈ
	QT_ArenaGetCharacter,				// 2007-12-29 by dhjin, �Ʒ��� ���� - �ɸ��� ���� �ε�
	QT_ArenaCopyDBInfo,					// 2008-01-08 by dhjin, �Ʒ��� ���� - �Ʒ��� DB�� ����Ÿ ����
	QT_ArenaStartGetCharacter,			// 2008-01-09 by dhjin, �Ʒ��� ���� - �Ʒ��� ������ ���� �ɸ��� ���� �ٽ� �ε��Ͽ� Ŭ���̾�Ʈ���� ����

	//////////////////////////////////////////////////////////////////////////
	// 2008-04-02 by dhjin,	����, ������ ����â ��ȹ�� -
	QT_GetLogMSWarInfo,
	QT_GetLogSPWarInfo,
	QT_UpdateMSWarOptionType,
	QT_InsertMSWarLog,	// 2008-08-28 by dhjin, ���� ����, ����DB�� ���ܾ� Admintool�� �ʱ�ȭ�� �����ϴ�.
	QT_InsertSPWarLog,	// 2008-08-28 by dhjin, ���� ����, ����DB�� ���ܾ� Admintool�� �ʱ�ȭ�� �����ϴ�.

	///////////////////////////////////////////////////////////////////////////////
	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	QT_UpdateDBServerGroup,				// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
	QT_CheckConnectableAccount,			// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 

	//////////////////////////////////////////////////////////////////////////
	// 2008-06-23 by dhjin, EP3 ���������ɼ� -
	QT_GetUserInfo,						// 2008-06-23 by dhjin, EP3 ���������ɼ� - �ٸ� ���� ���� ��û

// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - DQT_DailyJob �� ���� ��.
//	//////////////////////////////////////////////////////////////////////////
//	// 2008-08-19 by dhjin, MySQL���� ������ MySQL���� �������� �ʴ� MSSQL�� Job���� �۾��� ���⼭ ó���Ѵ�.
//	QT_DailyJob,
	
	// 2008-11-04 by dhjin, ��Ű�ӽ�
	QT_UpdateLuckyItemDropCount,		
	QT_UpdateLuckyItemStarttime,

	QT_ReloadAdminAutoNotice,		// 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - 


	//////////////////////////////////////////////////////////////////////////
	// 2009-01-12 by dhjin, ���� ����
	QT_UpdateStartDeclarationOfWar,
	QT_UpdateEndDeclarationOfWar,
	QT_UpdateMSWarStartTime,

	///////////////////////////////////////////////////////////////////////////////
	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	QT_UpdateNickName,
	QT_GetSelfRanking,

	///////////////////////////////////////////////////////////////////////////////
	// 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� -
	QT_ChangeItemWithItemMatching,		// 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - �ش� ������ â�� �������� ���� ���� ó���Ѵ�.

	///////////////////////////////////////////////////////////////////////////////
	// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
	QT_ChangeStartCityMapIndex,			// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 

	///////////////////////////////////////////////////////////////////////////////
	// 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - QT_ �߰�
	QT_ChangeAddedInventoryCount,		// 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - 

	////////////////////////////////////////////////////////////////////////////////
	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	
	QT_LoadInfinityImpute,					// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �ͼ� ���� ��������
	QT_InsertInfinityImpute,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �ͼ� ���� �߰�
	QT_UpdateInfinityImpute,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	���� �Ϸ� 
	QT_ResetInfinityImpute,					// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 	�ش� ���� �������� ���� ����
	QT_ArenaCopyInfinityDBInfo,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �Ʒ���DB�� �����ϱ�
	QT_CharacterSaveDataInfinityFin,		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ �ɸ��� ���� ����
	QT_InfinityFinUpdateItem,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ ���� ����
	QT_InfinityFinInsertItem,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ �߰���
	QT_InfinityInsertLog,					// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �α�
	QT_CharacterSaveDataInfinityFinByDisconnect,		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ �ɸ��� ���� ����
	QT_InfinityFinUpdateItemByDisconnect,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ ���� ����
	QT_InfinityFinInsertItemByDisconnect,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ �߰���
	QT_ResetInfinityImputeByServerStart,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���۽� ���� ����
	QT_InfinityComBackPostWork,				// 2012-01-16 by hskim, ��� - ȭ��

// 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - 
//	QT_LoadTenderInfo,						// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Tender

	QT_CashLoadPremiumCard,					// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �����̾� ���� ��������
	QT_LoadInfinityShopInfo,				// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ����
	QT_UpdateItemCoolingTimeStamp,			// 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	QT_InfinityUpdateUserMapInfo,			// 2010-04-06 by cmkwon, ����2�� �߰� ���� - 
	QT_LoadBurningMap,						// 2010-08-05 by dhjin, ���׸� -
	QT_Log_UserGetTenderItem,				// 2010-06-25 by shcho, ���Ǵ�Ƽ ���÷α� ��� - ���� ������ ���� DB����			

	/////////////////////////////////////////////////////////////
	// start 2011-08-22 by hskim, ��Ʈ�� �ý��� 2�� - ��� ����

	QT_PetUpdateInfinityFin,				// 2011-08-22 by hskim, �� ���� ������Ʈ (���Ǵ�Ƽ ���� �� ������Ʈ)
	QT_PetSetName,							// 2011-08-22 by hskim, �� �̸� ����
	QT_PetSetExpRatio,						// 2011-08-22 by hskim, �� ����ġ ȹ�� ���� ����
	QT_PetSetLevel,							// 2011-08-22 by hskim, �� ���� ����
	QT_PetSetExp,							// 2011-08-22 by hskim, �� ����ġ ����
	QT_PetSetSocket,						// 2011-08-30 by hskim, �� ���� ����
	QT_PetSetKitSlot,						// 2011-08-30 by hskim, �� ŰƮ ���� ����
	QT_PetSetAutoSkillSlot,					// 2011-08-30 by hskim, �� ���� ��ų ���� ����
	QT_PetChangeSocketOwner,				// 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�
	QT_StoreGetItemOne,						// 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�

	QT_GetEnchantCount,						// 2012-08-27 by hskim, ��Ʈ�� ��þƮ �� ���� �߰� ���� ó�� (�ڵ���� �������� �߰ߵ��� �ʾ����� ������ ��쿡�� �α׸� �����) (����ȭ DB ������ �õ��ؼ� ���� ���ϰ� ���� : �ʿ���ٰ� �ǴܵǸ� ���� ����)
	QT_GetAddExpRestExperienceCount,		// 2012-10-07 by hskim, �޽� ����ġ
	QT_SetAddExpRestExperienceCount,		// 2012-10-07 by hskim, �޽� ����ġ

	QT_GetFixedTerm,						// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
	QT_InsertFixedTerm,						// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
	QT_DeleteFixedTerm,						// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)

	QT_GetNumberOfChangeInflCount,			// 2014-06-10 by bckim, ���º��� ������		- ��� Get 
	QT_SetNumberOfChangeInflCount,			// 2014-06-10 by bckim, ���º��� ������		- ��� Set

	// end 2011-08-22 by hskim, ��Ʈ�� �ý��� 2�� - ��� ����
	/////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////
	// 2006-05-19 by cmkwon, Log Server
	QT_FL_LOG_LOGIN			= 10000,
	QT_FL_LOG_LOGOUT,
	QT_FL_LOG_LEVEL,
	QT_FL_LOG_EXP,
	QT_FL_LOG_STAT,
	QT_FL_LOG_GAME_START,
	QT_FL_LOG_GAME_END,
	QT_FL_LOG_QUEST_COMPLETION,
	QT_FL_LOG_QUEST_COMPENSATION,
	QT_FL_LOG_PKWIN,
	QT_FL_LOG_PKLOSS,
	QT_FL_LOG_DEAD,
	QT_FL_LOG_WARP,
	QT_FL_LOG_SPEED_HACK,
	QT_FL_LOG_CREATE_CHARACTER,
	QT_FL_LOG_DELETE_CHARACTER,
	QT_FL_LOG_MEMORY_HACK,
	QT_FL_LOG_PvEWIN,
	QT_FL_LOG_PvELOSS,
	QT_FL_LOG_ITEM_CHARACTER_ITEM,
	QT_FL_LOG_ITEM_GET_ITEM,
	QT_FL_LOG_ITEM_ADD_ITEM_BY_COMMAND,
	QT_FL_LOG_ITEM_INSERT_TO_STORE,
	QT_FL_LOG_ITEM_DRAW_FROM_STORE,
	QT_FL_LOG_ITEM_TRADE_SEND,
	QT_FL_LOG_ITEM_TRADE_RECV,
	QT_FL_LOG_GUILD_STORE,
	QT_FL_LOG_ITEM_THROWAWAY_ITEM,
	QT_FL_LOG_ITEM_BUY_ITEM,
	QT_FL_LOG_ITEM_SELL_ITEM,
	QT_FL_LOG_ITEM_USE_ITEM,
	QT_FL_LOG_ITEM_USE_ENERGY,
	QT_FL_LOG_ITEM_USE_ENCHANT,
	QT_FL_LOG_ITEM_STORE_ITEM,
	QT_FL_LOG_ITEM_USE_MIX,
	QT_FL_LOG_ITEM_USE_CHANGE_CHARACTER_NAME_ORIGIN,
	QT_FL_LOG_SERVER_INFO_MAP,
	QT_FL_LOG_SERVER_INFO_TOTAL,
	QT_FL_LOG_MONSTER_BOSS,
	QT_FL_LOG_START_FIELD_SERVER,
	QT_FL_LOG_MS_WAR,		// 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
	QT_FL_LOG_SP_WAR,		// 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
	QT_FL_LOG_STATISTICS_MONEY,		// 2012-01-16 by hskim, ��� - ȭ��
	QT_FL_LOG_ITEM_DISSOLUTION, // 2013-11-20 by jekim, ����, ���� ������ �� �� �ְ� ����.

	QT_NA,		// 2008-12-01 by cmkwon

	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - DQT_ <== Dynamic Query Type

	DQT_DailyJob,			// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
	DQT_UpdatePCBangList,	// 2008-12-19 by cmkwon, QT_UpdatePCBangList->DQT_UpdatePCBangList ���� - PCBang IP ����Ʈ ���ε�
	DQT_ReloadWRKServiceList,	// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	DQT_ReloadWRKLevel,			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	DQT_ReloadWRKFame,			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	DQT_ReloadWRKPVP,			// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
	DQT_LoadInfluenceRate,				// 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
	DQT_NA,

	// 2010-06-01 by shcho, GLogDB ���� -
	QT_FL_GLOG_BUY_CASH_ITEM = 30000,
	QT_FL_GLOG_CHARACTER_PLAY_TIME,
	QT_FL_GLOG_CONNECT_TOTAL_USER_COUNT,
	QT_FL_GLOG_CONNECT_ZONE_USER_COUNT,
	QT_FL_GLOG_EVENT_PARTICIPATION_RATE,

	// 2011-12-12 by hskim, GLog 2��
	QT_FL_GLOG_TB_USER_LocalUserConnectInfo_DelCountInc,	// LogServer
	QT_FL_GLOG_TB_USER_LocalUserConnectInfo_NewCountInc,	// LogServer
	QT_FL_GLOG_TB_CONNECT_USER,								// LogServer
	QT_FL_GLOG_TB_ITEM_BUY,									// LogServer
	QT_FL_GLOG_TB_CONCURRENT_USER,							// LogServer
	QT_FL_GLOG_TB_USER_PLAYTIME,							// LogServer

	// 2011-01-26 by hskim, ���� ���� ����
	QT_AUTH_CONFIRM,
	QT_AUTH_INSERT_CONFIRM_LOG,

	// 2012-01-13 by hskim, EP4 [������ 1ȸ ���]
	QT_UpdateAccountLastGameEndDate,

	//////////////////////////////////////////////////////////////////////////////
	// 2012-04-12 by jhseol, �Ʒ��� �߰����� - �Ʒ��� �÷��� ī��Ʈ Ȯ�� �� ���� Ipdata �߰�
	QT_ArenaPlayCount,
	QT_MF_Updata_CharacterArena,
	// end 2012-04-12 by jhseol, �Ʒ��� �߰����� - �Ʒ��� �÷��� ī��Ʈ Ȯ�� �� ���� Ipdata �߰�

	// start 2012-10-08 by khkim, GLog
	QT_FL_LOG_ACCOUNTCONNECT,
	QT_FL_LOG_CHARDATA,
	QT_FL_LOG_ITEM,
	QT_FL_LOG_ITEMSTATE,
	QT_FL_LOG_SERVER,
	// end 2012-10-08 by khkim, GLog
	QT_ArenaCharacterReset	// 2012-10-21 by jhseol, �Ʒ��� ���׼��� - �Ʒ��� ����� �ɸ��� ���� ����.

	//////////////////////////////////////////////////////////////////////////////
	// 2012-11-13 by jhseol, ���� �ý��� ������ - ������
	,QT_LoadRenewalStrategyPointSummonInfo
	,QT_UpdateStrategyPointSummonInfo
	// end 2012-11-13 by jhseol, ���� �ý��� ������ - ������

	,QT_ArenaCharacterReload	// 2012-12-18 by jhseol, �Ʒ��� ĳ���� ���� �� ĳ���� ���� �ٽ� �ε��ϱ�.
		   
    ,QT_FL_GLOG_NEW_ACCOUNT_INFO	// 2013-03-14 by bckim, Glog ����߰�	  

	,QT_InsertStoreItemFromXMLRPC		// 2013-03-13 by hskim, �� ĳ�� ����
	,QT_DeleteStoreItemFromXMLRPC		// 2013-03-13 by hskim, �� ĳ�� ����
	,QT_GetCharacterInfoFromXMLRPC		// 2013-03-13 by hskim, �� ĳ�� ����

	,QT_LoadCashBuyDate			// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
	,QT_InsertCashBuyDate		// 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
	,QT_InsertFirstPurchaseFromXMLRPC // 2014-04-21 by jekim, �� ĳ�� ���� ���� - ù����
	,QT_GetFirstPurchaseFromXMLRPC // 2014-04-21 by jekim, �� ĳ�� ���� ���� - ù����

	,QT_GetShapeStatLevel		// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - QT_GetShapeStatLevel �߰�
	,QT_InsertShapeStatLevel	// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - QT_InsertShapeStatLevel �߰�
	
	,QT_LoadMonthlyArmorEvent		// 2013-04-18 by jhseol,bckim �̴��� �Ƹ� - �̴��� �Ƹ� �̺�Ʈ �ε�
	,QT_UpdateInfluenceConsecutiveVictorites		// 2013-05-09 by hskim, ���� ����Ʈ ����

	,QT_GetTemporarySystemInfomation		// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	,QT_GetStoreExtension					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	,QT_InsertStoreExtension				// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
	,QT_CollectionArmorListLoad				// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �Ƹ� �÷��� �ε�
	,QT_CollectionArmorUpdate				// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - �Ƹ� �÷��� ����

	,QT_FL_LOG_ITEM_TRY_ENCHANT_INFO		// 2013-07-01 by bckim, 10��æƮ �̸� ������ī��ó��, �α��߰�, ��� ����
	,QT_AccountInflChange					// 2013-07-26 by jhseol, Ÿ ���� ���º���
	,QT_LoadSPWarInfoResult					// 2013-08-14 by jhseol, ������ ������ - ���� ���������� �ε�
	// 2013-11-25 by jhseol&bckim, �ŷ���
	,QT_Market_ItemRegistration				// 2013-11-26 by bckim, �ŷ��ҽý���
	,QT_Market_Buying						// 2013-11-26 by bckim, �ŷ��ҽý���
	,QT_Market_GetTradeItem					// 2013-11-26 by bckim, �ŷ��ҽý���
	,QT_Market_GetSaleList					// 2013-11-26 by bckim, �ŷ��ҽý���

	// 2013-12-16 by jhseol, ������ ��ȸ ���� ������
	,QT_GetTurnAroundBuffApplyInfo
	,QT_UpdateTurnAroundBuffApplyInfo
	// end 2013-12-16 by jhseol, ������ ��ȸ ���� ������

	,QT_PvpBuffUpdate // 2014-03-26 by jekim, ������ ���� ������

	// 2013-12-26 by bckim, �ı� ��� �ý��� 
	,QT_DestroyAuction_AddItem	
	,QT_DestroyAuction_UpdateBiddingInfo
	,QT_DestroyAuction_GetAuctionItem
	,QT_DestroyAuction_GetBiddingInfo
	,QT_DestroyAuction_SetClearAuctionList
	// End. 2013-12-26 by bckim, �ı� ��� �ý��� 
	,QT_FL_LOG_BUGTRAP_ACCEPT	// 2014-01-27 by bckim, ���� Ʈ��	
};

struct DB_QUERY {
	CIOCPSocket*	pIOCPSocket;
	UID32_t			nCharacterUID;
	EnumQueryType	enumQuryType;
	void			*pQueryParam;
	void			*pGeneralParam;		// General-Purpose void* Parameter
	INT64			nGeneralParam1;		// General-Purpose INT   Parameter
	INT64			nGeneralParam2;		// General-Purpose INT   Parameter
	DWORD			dwProcessedTick;	// ������ ó���Ǵ� �ð�

	DB_QUERY()
	{
		memset(this, 0x00, sizeof(*this));
	}
};

typedef mt_vector<DB_QUERY>				mtvectorDB_QUERY;
typedef mt_vector<HANDLE>				mtvectHANDLE;		// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 

const char* GetDBQueryTypeString(EnumQueryType qType);

enum EN_DBCONN_TYPE
{	EN_DBCONN_AUTO_COMMIT		= 0,	// 2006-05-17 by cmkwon
	EN_DBCONN_MANUAL_COMMIT		= 1,	// 2006-05-17 by cmkwon
	EN_DBCONN_EXT_AUTH			= 2		// 2006-05-17 by cmkwon, AutoCommit
	,EN_DBCONN_GLOG_COMMIT				// 2013-06-20 by jhseol,bckim GLog ����
};								

struct DBWorkerTLSDATA
{
	DBWorkerTLSDATA()
	{		
		henv			= SQL_NULL_HENV;
		hdbc			= SQL_NULL_HDBC;
		hstmt			= SQL_NULL_HSTMT;

		henv_ExtAuth	= SQL_NULL_HENV;		// 2006-05-17 by cmkwon
		hdbc_ExtAuth	= SQL_NULL_HDBC;		// 2006-05-17 by cmkwon
		hstmt_ExtAuth	= SQL_NULL_HSTMT;		// 2006-05-17 by cmkwon

		henv_mc			= SQL_NULL_HENV;
		hdbc_mc			= SQL_NULL_HDBC;
		hstmt_mc		= SQL_NULL_HSTMT;

		henv_GLog		= SQL_NULL_HENV;		// 2013-06-20 by jhseol,bckim GLog ����
		hdbc_GLog		= SQL_NULL_HDBC;		// 2013-06-20 by jhseol,bckim GLog ����
		hstmt_GLog		= SQL_NULL_HSTMT;		// 2013-06-20 by jhseol,bckim GLog ����
	}

	SQLHSTMT GetSQLHSTMT(EN_DBCONN_TYPE i_dbConnTy)
	{
		switch(i_dbConnTy)
		{
		case EN_DBCONN_AUTO_COMMIT:
			return hstmt;
		case EN_DBCONN_MANUAL_COMMIT:
			return hstmt_mc;
		case EN_DBCONN_EXT_AUTH:
			return hstmt_ExtAuth;
		case EN_DBCONN_GLOG_COMMIT:		return hstmt_GLog;		// 2013-06-20 by jhseol,bckim GLog ����
		}
		return NULL;
	}

	virtual ~DBWorkerTLSDATA()
	{
	}

	SQLHENV			henv;
	SQLHDBC			hdbc;
	SQLHSTMT		hstmt;

	SQLHENV			henv_ExtAuth;		// 2006-05-17 by cmkwon
	SQLHDBC			hdbc_ExtAuth;		// 2006-05-17 by cmkwon
	SQLHSTMT		hstmt_ExtAuth;		// 2006-05-17 by cmkwon

	SQLHENV			henv_mc;	// for manual commit
	SQLHDBC			hdbc_mc;	// for manual commit
	SQLHSTMT		hstmt_mc;	// for manual commit

	SQLHENV			henv_GLog;		// 2013-06-20 by jhseol,bckim GLog ����
	SQLHDBC			hdbc_GLog;		// 2013-06-20 by jhseol,bckim GLog ����
	SQLHSTMT		hstmt_GLog;		// 2013-06-20 by jhseol,bckim GLog ����
};

class CODBCStatement;
class CIOCP;
class CAtumDBManager : public CAtumDBHelper
{
///////////////////////////////////////////////////////////////////////////////
// public member functions
///////////////////////////////////////////////////////////////////////////////
public:
	CAtumDBManager(DWORD i_dwWorkerCounts);
	virtual ~CAtumDBManager();

	BOOL Init();
	void Clean();
	BOOL IsReadyAtumDBManager(void);
	BOOL Connect2DBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_AUTO_COMMIT);
	BOOL Connect2DBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy);
	void DisconnectDBServer(SQLHENV *i_phenv, SQLHDBC	*i_phdbc, SQLHSTMT *i_phstmt);
	void DisconnectDBServer(DBWorkerTLSDATA *io_pDBTlsData, EN_DBCONN_TYPE i_dbConnTy);
	DWORD AtumDBWorker(int i_nAtumDBThreadIndex);


	// General-function
	void MakeAndEnqueueQuery(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam = NULL, INT64 i_nGeneralParam1 = 0, INT64 i_nGeneralParam2 = 0);	// Asynchronous Excution
	BOOL ExecuteQuery(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam = NULL, INT64 i_nGeneralParam1 = 0, INT64 i_nGeneralParam2 = 0);		// Synchronous Excution

	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
	mtvectorDB_QUERY	m_mtvectInputQueryWithNewThread;
	mtvectHANDLE		m_mtvectQueryThreadHandleList;
	BOOL CheckAndCloseHandleDynamicDBThread(void);
	BOOL InsertDBQueryToDynamicQueryList(DB_QUERY *i_pDBQuery);
	BOOL GetDBQueryFromDynamicQueryList(DB_QUERY *o_pDBQuery);
	BOOL MakeQueryWithNewThread(EnumQueryType type, CIOCPSocket* pIOCPSocket, void *pMsg, void* i_pGeneralParam = NULL, INT64 i_nGeneralParam1 = 0, INT64 i_nGeneralParam2 = 0);
	DWORD AtumDBDynamicWorker(void);
	virtual BOOL ProcessDinamicServerQuery(DB_QUERY *i_qQuery, CODBCStatement *i_pODBC) = 0;
	

	// TLS
	BOOL TLSDataInit(LPVOID &lpvData);
	BOOL TLSDataClean(LPVOID &lpvData);
	DBWorkerTLSDATA* GetDBWorkerTLSDATA();

///////////////////////////////////////////////////////////////////////////////
// private member functions
///////////////////////////////////////////////////////////////////////////////
private:
	virtual BOOL ProcessServerQuery(DB_QUERY q, SQLHSTMT &hstmt, SQLHSTMT &hstmt_mc, SQLHSTMT &hstmt_extAuth, SQLHSTMT &hstmt_GLog) = 0;		// 2013-06-20 by jhseol,bckim GLog ����

public:
	char* GetSqlPattern(const char* str, char* buf);	// where�� string �� ������ %, [, ], _�� �����ϱ� ����
														// �˻������� ����ϸ� ��
														// buffer size�� max 64��!

	RETCODE GetDBError(SQLHSTMT hstmt, UCHAR *sqlState);

	void ProcessLogMessages(SQLSMALLINT plm_handle_type,
		SQLHANDLE &plm_handle, const char *logstring, BOOL ConnInd, CIOCPSocket *pIOCPSocket = NULL);

	SThreadInfo *CheckDBThread(DWORD i_dwThreadIdToExclude){	return m_DBThreadCheck.CheckThreadInfo(i_dwThreadIdToExclude);}

///////////////////////////////////////////////////////////////////////////////
// public member variables
///////////////////////////////////////////////////////////////////////////////
public:
	HANDLE				m_hDBWorkerThread[COUNT_MAX_DBWORKER_THREADS];
	CThreadCheck		m_DBThreadCheck;

///////////////////////////////////////////////////////////////////////////////
// private member variables
///////////////////////////////////////////////////////////////////////////////
protected:
	DWORD				m_dwCountDBWorker;
	BOOL				m_bShutDownFlag;
	mtvectorDB_QUERY	m_arrmtvectorInputDBQuery[COUNT_MAX_DBWORKER_THREADS];
	mtvectorDB_QUERY	m_arrmtvectorProcessDBQuery[COUNT_MAX_DBWORKER_THREADS];
	DWORD				m_dwTlsIndex;	 // TLS
	BOOL				m_bExtAuthDBConnect;			// 2006-05-17 by cmkwon,

	CODBCStatement		*m_ArrOdbcStmt;		// Synchronous Execution��
};

#endif
