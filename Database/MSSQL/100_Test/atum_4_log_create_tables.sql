--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_type_info
-- DESC      : 0 - string conversion of log type
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_type_info (
	LogType						TINYINT,
	LogStringEN					VARCHAR(30),
	LogStringKO					VARCHAR(30)
)
GO
CREATE UNIQUE INDEX idx_LogType_On_atum_log_type_info ON atum_log_type_info(LogType)								-- 2005-03-08 by cmkwon	
DELETE FROM dbo.atum_log_type_info
INSERT INTO dbo.atum_log_type_info VALUES(0x00, 'LOGIN', 'LOGIN')
INSERT INTO dbo.atum_log_type_info VALUES(0x01, 'LOGOUT', 'LOGOUT')
INSERT INTO dbo.atum_log_type_info VALUES(0x10, 'LEVEL', 'LEVEL')
INSERT INTO dbo.atum_log_type_info VALUES(0x11, 'EXP', 'EXP')
INSERT INTO dbo.atum_log_type_info VALUES(0x12, 'STAT', 'STAT')
INSERT INTO dbo.atum_log_type_info VALUES(0x13, 'GAME_START', 'GAME_START')
INSERT INTO dbo.atum_log_type_info VALUES(0x14, 'GAME_END', 'GAME_END')
INSERT INTO dbo.atum_log_type_info VALUES(0x15, 'QUEST', 'QUEST')
INSERT INTO dbo.atum_log_type_info VALUES(0x16, 'PKWIN', 'PKWIN')
INSERT INTO dbo.atum_log_type_info VALUES(0x17, 'PKLOSS', 'PKLOSS')
INSERT INTO dbo.atum_log_type_info VALUES(0x18, 'DEAD', 'DEAD')
INSERT INTO dbo.atum_log_type_info VALUES(0x19, 'WARP', 'WARP')
INSERT INTO dbo.atum_log_type_info VALUES(0x1A, 'SPEED_HACK', 'SPEED_HACK')
INSERT INTO dbo.atum_log_type_info VALUES(0x1B, 'CREATE_CHARACTER', 'CREATE_CHARACTER')
INSERT INTO dbo.atum_log_type_info VALUES(0x1C, 'DELETE_CHARACTER', 'DELETE_CHARACTER')
INSERT INTO dbo.atum_log_type_info VALUES(0x1D, 'MEMORY_HACK', 'MEMORY_HACK')					-- 2005-12-21 by cmkwon
INSERT INTO dbo.atum_log_type_info VALUES(0x1E, 'PvE_WIN', 'PvE_WIN')							-- 2006-03-06 by cmkwon
INSERT INTO dbo.atum_log_type_info VALUES(0x1F, 'PvE_LOSS', 'PvE_LOSS')							-- 2006-03-06 by cmkwon
INSERT INTO dbo.atum_log_type_info VALUES(0x20, 'CHARACTER_ITEM', 'CHARACTER_ITEM')
INSERT INTO dbo.atum_log_type_info VALUES(0x21, 'GET_ITEM', 'GET_ITEM')
INSERT INTO dbo.atum_log_type_info VALUES(0x22, 'TRADE_SEND', 'TRADE_SEND')
INSERT INTO dbo.atum_log_type_info VALUES(0x23, 'TRADE_RECV', 'TRADE_RECV')
INSERT INTO dbo.atum_log_type_info VALUES(0x24, 'THROWAWAY', 'THROWAWAY')
INSERT INTO dbo.atum_log_type_info VALUES(0x25, 'BUY', 'BUY')
INSERT INTO dbo.atum_log_type_info VALUES(0x26, 'SELL', 'SELL')
INSERT INTO dbo.atum_log_type_info VALUES(0x27, 'USE_ITEM', 'USE_ITEM')
INSERT INTO dbo.atum_log_type_info VALUES(0x28, 'USE_ENERGY', 'USE_ENERGY')
INSERT INTO dbo.atum_log_type_info VALUES(0x29, 'USE_ENCHANT', 'USE_ENCHANT')
INSERT INTO dbo.atum_log_type_info VALUES(0x2A, 'ADD_ITEM_BY_ADMIN', 'ADD_ITEM_BY_ADMIN')
INSERT INTO dbo.atum_log_type_info VALUES(0x2B, 'DEL_ITEM_BY_ADMIN', 'DEL_ITEM_BY_ADMIN')
INSERT INTO dbo.atum_log_type_info VALUES(0x2C, 'ADD_ITEM_BY_COMMAND', 'ADD_ITEM_BY_COMMAND')
INSERT INTO dbo.atum_log_type_info VALUES(0x2D, 'INSERT_TO_STORE', 'INSERT_TO_STORE')
INSERT INTO dbo.atum_log_type_info VALUES(0x2E, 'DRAW_FROM_STORE', 'DRAW_FROM_STORE')
INSERT INTO dbo.atum_log_type_info VALUES(0x2F, 'STORE_ITEM', 'STORE_ITEM')
INSERT INTO dbo.atum_log_type_info VALUES(0x50, 'MONSTER_BOSS', 'MONSTER_BOSS')
INSERT INTO dbo.atum_log_type_info VALUES(0x33, 'BAZAAR_SEND', 'BAZAAR_SEND')	
INSERT INTO dbo.atum_log_type_info VALUES(0x34,	'BAZAAR_RECEVIED', 'BAZAAR_RECEVIED')
INSERT INTO dbo.atum_log_type_info VALUES(0x35, 'F_Char_TO_GuildStore', 'F_Char_TO_GuildStore')
INSERT INTO dbo.atum_log_type_info VALUES(0x36, 'F_GuildStore_TO_Char', 'F_GuildStore_TO_Char')
INSERT INTO dbo.atum_log_type_info VALUES(0x43, 'LIVE_DELETED_CHARACTER', 'LIVE_DELETED_CHARACTER')		-- 2007-02-22 by dhjin
INSERT INTO dbo.atum_log_type_info VALUES(0x51, 'MSWar', 'MSWar')										-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
INSERT INTO dbo.atum_log_type_info VALUES(0x52, 'SPWar', 'SPWar')										-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 	
INSERT INTO dbo.atum_log_type_info VALUES(0xB0, 'ITEM_GIFT_SEND', 'ITEM_GIFT_SEND')						-- // 2007-11-13 by cmkwon, 선물하기 기능 추가 - 
INSERT INTO dbo.atum_log_type_info VALUES(0xB1, 'ITEM_GIFT_RECV', 'ITEM_GIFT_RECV')						-- // 2007-11-13 by cmkwon, 선물하기 기능 추가 - 
INSERT INTO dbo.atum_log_type_info VALUES(0xB2, 'RearrangeItem_DeletedItem', 'RearrangeItem_DeletedItem')	-- 	// 2007-11-29 by cmkwon, 카운터블아이템 합쳐지는 게임 로그 남기기 - 
INSERT INTO dbo.atum_log_type_info VALUES(0xB3, 'RearrangeItem_RemainedItem', 'RearrangeItem_RemainedItem')	-- 	// 2007-11-29 by cmkwon, 카운터블아이템 합쳐지는 게임 로그 남기기 - 
INSERT INTO dbo.atum_log_type_info VALUES(0xD0, 'Block', 'Block')			-- // 2008-01-29 by cmkwon, 계정 블럭/해제 로그 시스템 추가 - VIEW 추가
INSERT INTO dbo.atum_log_type_info VALUES(0xD1, 'Unblock', 'Unblock')		-- // 2008-01-29 by cmkwon, 계정 블럭/해제 로그 시스템 추가 - VIEW 추가
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_level_stat
-- DESC      : 1 - level & stat log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_level_stat (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,	-- UINT
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	Param1						SMALLINT,
	Param2						SMALLINT,
	Param3						BIGINT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_level_stat ON atum_log_user_level_stat (Time)
CREATE INDEX idx_LogType_On_log_user_level_stat ON atum_log_user_level_stat(LogType)								-- 2005-03-08 by cmkwon	
CREATE INDEX idx_CharacterUniqueNumber_On_log_user_level_stat ON atum_log_user_level_stat(CharacterUniqueNumber)	-- 2005-03-08 by cmkwon	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_exp
-- DESC      : 2 - exp log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_exp (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,	-- UINT
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	Param1						FLOAT,
	Param2						BIGINT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_exp ON atum_log_user_exp (Time)
CREATE INDEX idx_LogType_On_log_user_exp ON atum_log_user_exp(LogType)								-- 2005-03-08 by cmkwon	
CREATE INDEX idx_CharacterUniqueNumber_On_log_user_exp ON atum_log_user_exp(CharacterUniqueNumber)	-- 2005-03-08 by cmkwon	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_game_start_end
-- DESC      : 3 - gamestart & gameend log & create_character & delete_character
--				2006-12-18 by cmkwon, 필드 추가(PCBangPlayTime INT)
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_game_start_end (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	CharacterName				VARCHAR(20),
	AccountUniqueNumber			INT,			-- UINT
	AccountName					VARCHAR(20),
	PlayTime					INT,
	TotalPlayTime				BIGINT,
	PCBangPlayTime				INT,			-- 2006-12-18 by cmkwon, PCBang PlayTime 
	PCBangUID					INT				-- 2007-01-24 by dhjin, PCBang UID
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_game_start_end ON atum_log_user_game_start_end (Time)
CREATE INDEX idx_LogType_On_log_user_game_start_end ON atum_log_user_game_start_end(LogType)								-- 2005-03-08 by cmkwon	
CREATE INDEX idx_CharacterUniqueNumber_On_log_user_game_start_end ON atum_log_user_game_start_end(CharacterUniqueNumber)	-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterName_On_log_user_game_start_end ON atum_log_user_game_start_end(CharacterName)					-- 2005-03-08 by cmkwon
CREATE INDEX idx_AccountUniqueNumber_On_log_user_game_start_end ON atum_log_user_game_start_end(AccountUniqueNumber)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_AccountName_On_log_user_game_start_end ON atum_log_user_game_start_end(AccountName)						-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_quest_pk_dead
-- DESC      : 4 - quest & pk & dead log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_quest_pk_dead (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	Param1						INT				-- UINT or INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_quest_pk_dead ON atum_log_user_quest_pk_dead (Time)
CREATE INDEX idx_LogType_log_user_quest_pk_dead ON atum_log_user_quest_pk_dead(LogType)									-- 2005-03-08 by cmkwon	
CREATE INDEX idx_CharacterUniqueNumber_log_user_quest_pk_dead ON atum_log_user_quest_pk_dead(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_warp
-- DESC      : 5 - warp log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_warp (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	TargetMapIndex				SMALLINT,
	TargetPosition_X			SMALLINT,
	TargetPosition_Y			SMALLINT,
	TargetPosition_Z			SMALLINT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_warp ON atum_log_user_warp (Time)
CREATE INDEX idx_LogType_log_user_warp ON atum_log_user_warp(LogType)									-- 2005-03-08 by cmkwon	
CREATE INDEX idx_CharacterUniqueNumber_log_user_warp ON atum_log_user_warp(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_speed_hack
-- DESC      : 6 - speed hack log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_speed_hack (
	LogType					TINYINT,
	Time					DATETIME,
	CharacterUniqueNumber	INT,
	MapIndex				SMALLINT,
	Position_X				SMALLINT,
	Position_Y				SMALLINT,
	Position_Z				SMALLINT,
	CheckType				TINYINT,
	ReceivedMoveCounts		INT,
	EngineItemNum			INT,
	ServerPastTime			INT,
	ClientPastTime			INT,
	PastDistance			INT,
	CurrentSpeed			INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_user_speed_hack ON atum_log_user_speed_hack (Time)
CREATE INDEX idx_LogType_log_user_speed_hack ON atum_log_user_speed_hack(LogType)									-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterUniqueNumber_log_user_speed_hack ON atum_log_user_speed_hack(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_ReceivedMoveCounts_log_user_speed_hack ON atum_log_user_speed_hack(ReceivedMoveCounts)				-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_item_charac_use
-- DESC      : 7 - character_item, use_item, use_energy, use_enchant, store_item(창고 아이템)
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_item_charac_use (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	ItemUniqueNumber			BIGINT,
	ItemNum						INT,
	CurrentCount				INT,
	Param1						INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_item_charac_use ON atum_log_item_charac_use (Time)
CREATE INDEX idx_LogType_log_item_charac_use ON atum_log_item_charac_use(LogType)									-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterUniqueNumber_log_item_charac_use ON atum_log_item_charac_use(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemUniqueNumber_log_item_charac_use ON atum_log_item_charac_use(ItemUniqueNumber)					-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemNum_log_item_charac_use ON atum_log_item_charac_use(ItemNum)									-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_item_get_throw
-- DESC      : 8 - get_item, throwaway_item, add_item_by_command, insert_to_store, draw_from_store
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_item_get_throw (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	ItemUniqueNumber			BIGINT,
	ItemNum						INT,
	CurrentCount				INT,
	ChangeCount					INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_item_get_throw ON atum_log_item_get_throw (Time)
CREATE INDEX idx_LogType_log_item_get_throw ON atum_log_item_get_throw(LogType)									-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterUniqueNumber_log_item_get_throw ON atum_log_item_get_throw(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemUniqueNumber_log_item_get_throw ON atum_log_item_get_throw(ItemUniqueNumber)				-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemNum_log_item_get_throw ON atum_log_item_get_throw(ItemNum)									-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_item_buy_sell
-- DESC      : 9 - buy_item, sell_item
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_item_buy_sell (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	ItemUniqueNumber			BIGINT,
	ItemNum						INT,
	CurrentCount				INT,
	ChangeCount					INT,
	RemainedMoney				INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_item_buy_sell ON atum_log_item_buy_sell (Time)
CREATE INDEX idx_LogType_log_item_buy_sell ON atum_log_item_buy_sell(LogType)									-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterUniqueNumber_log_item_buy_sell ON atum_log_item_buy_sell(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemUniqueNumber_log_item_buy_sell ON atum_log_item_buy_sell(ItemUniqueNumber)					-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemNum_log_item_buy_sell ON atum_log_item_buy_sell(ItemNum)									-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_item_trade
-- DESC      : 10 - trade_send, trade_recv, add_item_by_admin, del_item_by_admin
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_item_trade (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,			-- UINT
	MapIndex					SMALLINT,
	ItemUniqueNumber			BIGINT,
	ItemNum						INT,
	CurrentCount				INT,
	ChangeCount					INT,
	PeerCharacterName			VARCHAR(20),
	PeerCharacterUniqueNumber	INT				-- UINT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_item_trade ON atum_log_item_trade (Time)
CREATE INDEX idx_LogType_log_item_trade ON atum_log_item_trade(LogType)											-- 2005-03-08 by cmkwon
CREATE INDEX idx_CharacterUniqueNumber_log_item_trade ON atum_log_item_trade(CharacterUniqueNumber)				-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemUniqueNumber_log_item_trade ON atum_log_item_trade(ItemUniqueNumber)						-- 2005-03-08 by cmkwon
CREATE INDEX idx_ItemNum_log_item_trade ON atum_log_item_trade(ItemNum)											-- 2005-03-08 by cmkwon
CREATE INDEX idx_PeerCharacterName_log_item_trade ON atum_log_item_trade(PeerCharacterName)						-- 2005-03-08 by cmkwon
CREATE INDEX idx_PeerCharacterUniqueNumber_log_item_trade ON atum_log_item_trade(PeerCharacterUniqueNumber)		-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_server_map
-- DESC      : 11 - server_map log
--				#define T1_FL_LOG_SERVER_INFO_MAP				0x40	// 64 - 맵별 동접수
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_server_map (
	LogType						TINYINT,	-- 고정된 값(64)
	Time						DATETIME,	-- 로그가 저장된 시간
	MapIndex					SMALLINT,	-- 0 or 맵인덱스(0: 서버군 전체 동접수, 맵인덱스:해당맵채널의 동접수)
	ChannelIndex				SMALLINT,	-- 채널 인덱스(MapIndex가 0이 아닐때만 유효함)
	ClientCount					INT,		-- 접속 유저수
	MonsterCount				INT,		-- 현재의 몬스터수
	MGameServerID				INT			-- ServerGroup ID
)
GO
CREATE CLUSTERED INDEX idx_atum_log_server_map ON atum_log_server_map (Time)
CREATE INDEX idx_LogType_log_server_map ON atum_log_server_map(LogType)						-- 2005-03-08 by cmkwon
CREATE INDEX idx_MapIndex_log_server_map ON atum_log_server_map(MapIndex)					-- 2005-03-08 by cmkwon
CREATE INDEX idx_MGameServerID_log_server_map ON atum_log_server_map(MGameServerID)			-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_monster_boss
-- DESC      : 12 - server_map log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_monster_boss (
	LogType						TINYINT,
	Time						DATETIME,
	MapIndex					SMALLINT,
	ChannelIndex				SMALLINT,
 	MonsterUnitKind				INT,		-- 생성 몬스터 정보
 	CreatedTime					DATETIME,
 	DeadTime					DATETIME,
 	AttackUser1					VARCHAR(20),
 	AttackUser2					VARCHAR(20),
 	AttackUser3					VARCHAR(20),
 	AttackUser4					VARCHAR(20),
 	AttackUser5					VARCHAR(20),
 	AttackUser6					VARCHAR(20),
 	AttackUser7					VARCHAR(20),
 	AttackUser8					VARCHAR(20),
 	AttackUser9					VARCHAR(20),
 	AttackUser10				VARCHAR(20),
 	DropItemList				VARCHAR(200),
 	MGameServerID				INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_monster_boss ON atum_log_monster_boss (Time)
CREATE INDEX idx_LogType_log_monster_boss ON atum_log_monster_boss(LogType)						-- 2005-03-08 by cmkwon
CREATE INDEX idx_MapIndex_log_monster_boss ON atum_log_monster_boss(MapIndex)					-- 2005-03-08 by cmkwon
CREATE INDEX idx_ChannelIndex_log_monster_boss ON atum_log_monster_boss(ChannelIndex)			-- 2005-03-08 by cmkwon
CREATE INDEX idx_MonsterUnitKind_log_monster_boss ON atum_log_monster_boss(MonsterUnitKind)		-- 2005-03-08 by cmkwon
CREATE INDEX idx_MGameServerID_log_monster_boss ON atum_log_monster_boss(MGameServerID)			-- 2005-03-08 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_user_memory_hack
-- DESC      : 2005-12-20 by cmkwon
--			   13 - memory_hack log
--					무기 - 
--					엔진 -
--					아머 - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_user_memory_hack (
	LogType						TINYINT,
	Time						DATETIME,
	CharacterUniqueNumber		INT,
	MapIndex					SMALLINT,
	Position_X					SMALLINT,
	Position_Y					SMALLINT,
	Position_Z					SMALLINT,
	ItemKind					INT,
	ItemNum						INT,
	ItemUniqueNumber			BIGINT,
	MemoryHackCheckType			INT,
	ValidValue					FLOAT,
	CurrentValue				FLOAT,
	Param1						INT
)
CREATE CLUSTERED INDEX idx_atum_log_user_memory_hack ON atum_log_user_memory_hack (Time)
CREATE INDEX idx_CharacterUniqueNumber_log_user_memory_hack ON atum_log_user_memory_hack(CharacterUniqueNumber)		-- 2005-12-20 by cmkwon	
CREATE INDEX idx_ItemKind_log_user_memory_hack ON atum_log_user_memory_hack(ItemKind)			-- 2005-12-20 by cmkwon	
CREATE INDEX idx_ItemNum_log_user_memory_hack ON atum_log_user_memory_hack(ItemNum)				-- 2005-12-20 by cmkwon	
CREATE INDEX idx_MemoryHackCheckType_log_user_memory_hack ON atum_log_user_memory_hack(MemoryHackCheckType)	-- 2005-12-20 by cmkwon	
GO





--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
-- Group DB atum_back_log_X 테이블 만들기
-- 이 아래 테이블도 항상 존재 해야한다
--------------------------------------------------------------------------------
SELECT * INTO dbo.atum_backup_log_user_level_stat			FROM atum_log_user_level_stat		-- 1
SELECT * INTO dbo.atum_backup_log_user_exp					FROM atum_log_user_exp				-- 2
SELECT * INTO dbo.atum_backup_log_user_game_start_end		FROM atum_log_user_game_start_end	-- 3
SELECT * INTO dbo.atum_backup_log_user_quest_pk_dead		FROM atum_log_user_quest_pk_dead	-- 4
SELECT * INTO dbo.atum_backup_log_user_warp					FROM atum_log_user_warp				-- 5
SELECT * INTO dbo.atum_backup_log_user_speed_hack			FROM atum_log_user_speed_hack		-- 6
SELECT * INTO dbo.atum_backup_log_item_charac_use			FROM atum_log_item_charac_use		-- 7
SELECT * INTO dbo.atum_backup_log_item_get_throw			FROM atum_log_item_get_throw		-- 8
SELECT * INTO dbo.atum_backup_log_item_buy_sell				FROM atum_log_item_buy_sell			-- 9
SELECT * INTO dbo.atum_backup_log_item_trade				FROM atum_log_item_trade			-- 10
SELECT * INTO dbo.atum_backup_log_server_map				FROM atum_log_server_map			-- 11
SELECT * INTO dbo.atum_backup_log_monster_boss				FROM atum_log_monster_boss			-- 12
SELECT * INTO dbo.atum_backup_log_user_memory_hack			FROM atum_log_user_memory_hack		-- 13, 2005-12-20 by cmkwon

--!!!!
-- Name: atum_log_GuildItem
-- Desc: 2006-09-27 by dhjin
--====
CREATE TABLE dbo.atum_log_GuildItem (
	LogType						TINYINT,
	Time						DATETIME,
	GuildUID					INT,
	GuildName					VARCHAR(30),
	AccountUID					INT,
	AccountName					VARCHAR(20),
	CharacterUID				INT,
	CharacterName				VARCHAR(20),
	ItemUID						BIGINT,
	ItemNum						INT,
	PrefixCodeNum				INT,
	SuffixCodeNum				INT,
	ItemResultCount				INT,
	ItemChangeCount				INT
)
CREATE CLUSTERED INDEX idx_atum_log_GuildItem ON atum_log_GuildItem (Time)
CREATE INDEX idx_LogType_log_GuildItem ON atum_log_GuildItem(LogType)
CREATE INDEX idx_GuildUID_log_GuildItem ON atum_log_GuildItem(GuildUID)
CREATE INDEX idx_GuildName_log_GuildItem ON atum_log_GuildItem(GuildName)
CREATE INDEX idx_AccountName_log_GuildItem ON atum_log_GuildItem(AccountName)
CREATE INDEX idx_CharacterName_log_GuildItem ON atum_log_GuildItem(CharacterName)
CREATE INDEX idx_ItemUID_log_GuildItem ON atum_log_GuildItem(ItemUID)
CREATE INDEX idx_ItemNum_log_GuildItem ON atum_log_GuildItem(ItemNum)
GO

--!!!!
-- Name: atum_backup_log_GuildItem
-- Desc: 2006-09-28 by dhjin
--====
CREATE TABLE dbo.atum_backup_log_GuildItem (
	LogType						TINYINT,
	Time						DATETIME,
	GuildUID					INT,
	GuildName					VARCHAR(30),
	AccountUID					INT,
	AccountName					VARCHAR(20),
	CharacterUID				INT,
	CharacterName				VARCHAR(20),
	ItemUID						BIGINT,
	ItemNum						INT,
	PrefixCodeNum				INT,
	SuffixCodeNum				INT,
	ItemResultCount				INT,
	ItemChangeCount				INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_GuildItem ON atum_backup_log_GuildItem (Time)
CREATE INDEX idx_LogType_log_GuildItem ON atum_backup_log_GuildItem(LogType)
CREATE INDEX idx_GuildUID_log_GuildItem ON atum_backup_log_GuildItem(GuildUID)
CREATE INDEX idx_GuildName_log_GuildItem ON atum_backup_log_GuildItem(GuildName)
CREATE INDEX idx_AccountName_log_GuildItem ON atum_backup_log_GuildItem(AccountName)
CREATE INDEX idx_CharacterName_log_GuildItem ON atum_backup_log_GuildItem(CharacterName)
CREATE INDEX idx_ItemNum_log_GuildItem ON atum_backup_log_GuildItem(ItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_log_Live_Deleted_Character
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_Live_Deleted_Character
(
	LogType			TINYINT,
	Time			DATETIME,
	AccountUID		INT,
	AccountName		VARCHAR(20),
	CharacterUID	INT,
	CharacterName	VARCHAR(20)
)
GO
CREATE CLUSTERED INDEX idx_atum_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character (Time)
CREATE INDEX idx_LogType_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character(LogType)
CREATE INDEX idx_AccountUID_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character(AccountUID)
CREATE INDEX idx_AccountName_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character(AccountName)
CREATE INDEX idx_CharacterUID_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character(CharacterUID)
CREATE INDEX idx_CharacterName_log_Live_Deleted_Character ON atum_log_Live_Deleted_Character(CharacterName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_log_MSWar
-- DESC		 : 모선전 로그 -- 지도자 초기화시 같이 초기화
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_MSWar (
	LogType						TINYINT,
	AttInfluence				TINYINT,
	MonsterUID					INT,
	ContributionPoint			INT,
	MSWarStartTime				DATETIME,
	MSWarEndTime				DATETIME,
	WinInfluence				TINYINT
)
CREATE INDEX idx_LogType_log_MSWar ON atum_log_MSWar(LogType)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_log_SPWar
-- DESC		 : 거점전 로그 -- 지도자 초기화시 같이 초기화
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_SPWar (
	LogType						TINYINT,
	AttInfluence				TINYINT,
	SPSummonMapIndex			INT,
	SPWarStartTime				DATETIME,
	SPWarEndTime				DATETIME,
	WinInfluence				TINYINT
)
CREATE INDEX idx_LogType_log_SPWar ON atum_log_SPWar(LogType)
GO
