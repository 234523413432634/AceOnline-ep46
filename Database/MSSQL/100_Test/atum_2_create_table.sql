-- check: ���� �ܰ迡���� �Ķ���͸� �ٲ� ���� �����Ƿ� reference constraints�� �����Ѵ�. ���߿� �ٽ� �ǵ����� ��! 2003.6.12.
-- Database ��ü�� �ѱ��� ��� Korean_Wansung_CI_AS�� ����

--------------------------------------------------------------------------------
--
-- ����� ����Ÿ
--
-- td_Character
-- td_CharacterQuest
-- td_CharacterQuestMonsterCount	// 2005-10-17 by cmkwon
-- td_Guild
-- td_GuildMember
-- td_Store
-- td_StoreSkill
-- td_Enchant
-- td_MapOwnership
-- td_GuildWar
-- td_FriendList
-- td_Auction
-- td_OccupyInfo
-- td_InfluenceWarData
--		2006-04-14 by cmkwon, �߰���
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_Character
-- DESC      : ĳ����(��ü) ����
--				2006-04-12 by cmkwon, DownSPIOnDeath �ʵ� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Character (
	UniqueNumber		INT			IDENTITY(1,1) PRIMARY KEY,
	CharacterName		VARCHAR(20),
	AccountName			VARCHAR(20),		--REFERENCES td_Account(AccountName)
	AccountUniqueNumber	INT,											--REFERENCES td_Account(UniqueNumber)
	Gender				TINYINT,
	Race				SMALLINT,
	UnitKind			INT,		-- ����: USHORT�� bit flag�� ����!
	InfluenceType		TINYINT,										-- 2005-06-23 by cmkwon
	SelectableInfluenceMask		TINYINT,								-- 2005-12-07 by cmkwon, ���¼��ý� ���ð����� ����Mask, �Ѱ������� �ϳ��� ���¸� ���� ������
	PilotFace			TINYINT,
	CharacterMode		TINYINT,										-- 2005-10-06 by cmkwon
	AutoStatType		TINYINT,								-- 2005-04-04 by cmkwon
	AttackPart			SMALLINT,
	DefensePart			SMALLINT,
	FuelPart			SMALLINT,
	SoulPart			SMALLINT,
	ShieldPart			SMALLINT,
	DodgePart			SMALLINT,
	GuildName			VARCHAR(30),
	GuildUniqueNumber	INT,
	Level				TINYINT,
	Experience			FLOAT,
	DownExperience		FLOAT,
	DownSPIOnDeath		INT,				-- 2006-04-10 by cmkwon, ���� �� �������� SPI
	BodyCondition		BIGINT,
	Propensity			INT,
	Status				TINYINT,
	PKWinPoint			SMALLINT,
	PKLossPoint			SMALLINT,
	Material			SMALLINT,
	HP					SMALLINT,
	DP					SMALLINT,
	SP					SMALLINT,
	EP					SMALLINT,
	PetName				VARCHAR(20),
	PetLevel			TINYINT,
	PetExperience		FLOAT,
	Position_X			FLOAT,
	Position_Y			FLOAT,
	Position_Z			FLOAT,
	MapIndex			SMALLINT,	-- ���� �ִ� ���� Index, ex)0101, 0102
	ChannelIndex		SMALLINT,	-- ���� �ִ� ��ä���� Index, ex)0, 1, 2, ...
	MaxLevel			TINYINT,
	CurrentHP			FLOAT,
	CurrentDP			FLOAT,
	CurrentSP			SMALLINT,
	CurrentEP			FLOAT,
	BonusStat			TINYINT,
-- 2005-11-15 by cmkwon, BonusSkillPoint�� BonusStatPoint�� �����ϸ鼭 �ʿ������
--	BonusSkillPoint		TINYINT,
	BonusStatPoint		TINYINT DEFAULT 0,				-- 
	LastPartyID			BIGINT DEFAULT 0,				-- ������ ��Ƽ ���̵�
	RacingPoint			INT DEFAULT 0,					-- Racing ��� Point
	TotalPlayTime		BIGINT DEFAULT 0,				-- �ʴ���
	CreatedTime			DATETIME DEFAULT GetDate(),		-- ĳ���� ���� �ð�
	LastStartedTime		DATETIME DEFAULT NULL,			-- ���� ���� ���� �ð�
	LevelUpTime			DATETIME DEFAULT(NULL),			-- 2006-12-18 ������ �ð� ����
	WarPoint			INT DEFAULT 0,					-- WarPoint�� �߰�
	CumulativeWarPoint  INT DEFAULT 0,					-- ����WarPoint�� �߰�
	ArenaWin			INT DEFAULT 0,					-- �Ʒ��� ���� �߰� ��
	ArenaLose			INT DEFAULT 0,					-- �Ʒ��� ���� �߰� ��
	ArenaDisConnect		INT	DEFAULT 0,		 			-- �Ʒ��� ���� ����
	PCBangTotalPlayTime BIGINT DEFAULT 0,				-- PC�� �� �÷��� �ð�
	SecretInfoOption	INT	DEFAULT 0					-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
)
CREATE INDEX idx_AccountName_on_character ON td_Character(AccountName)
CREATE UNIQUE INDEX idx_CharacterName_on_character ON td_Character(CharacterName)
CREATE INDEX idx_AccountUniqueNumber_on_character ON td_Character(AccountUniqueNumber)
CREATE INDEX idx_Status_on_character ON td_Character(Status)							-- 2006-01-02 by cmkwon, �Ѵ� ���� �� ó������ �ʿ�
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_CharacterQuest
-- DESC      : ĳ������ ����Ʈ ���� ��Ȳ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CharacterQuest (
	CharacterUniqueNumber	INT			NOT NULL,						-- UINT 	--		REFERENCES td_Character(UniqueNumber)
	QuestIndex				INT			NOT NULL,						--		REFERENCES Quest(QuestIndex)
	QuestState				TINYINT		NOT NULL DEFAULT 0,				-- �Ϸ�, ������
	QuestParam1				INT			DEFAULT 0,
	QuestTimeStamp			DATETIME	NOT NULL DEFAULT GetDate(),
	QuestPlayTimeStamp		BIGINT		NOT NULL DEFAULT 0
)
-- // 2007-10-10 by cmkwon, �ε��� ���� ���� - �Ʒ��� ���� ������
-- CREATE CLUSTERED INDEX idx_CharacterUniqueNumber_at_characterQuest_Questindex ON td_CharacterQuest(CharacterUniqueNumber)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_CharacterQuest ON td_CharacterQuest(CharacterUNiqueNumber, QuestIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_CharacterQuestMonsterCount
-- DESC      : ĳ������ ����Ʈ�� ����� ������ ī���͸� ����
--				2005-10-17 by cmkwon
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CharacterQuestMonsterCount (
	CharacterUniqueNumber	INT			NOT NULL,						-- UINT 	--		REFERENCES td_Character(UniqueNumber)
	QuestIndex				INT			NOT NULL,						--		REFERENCES Quest(QuestIndex)
	MonsterUniqueNumber		INT			DEFAULT	0,						-- ����� ������ ����ũ�ѹ�			
	Count					INT			DEFAULT	0						-- ����� ������ ��
)
-- // 2007-10-10 by cmkwon, �ε��� ���� ���� - �Ʒ��� ���� ������
-- CREATE CLUSTERED INDEX idx_CharacterUniqueNumber_at_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(CharacterUniqueNumber)
-- CREATE INDEX idx_QuestIndex_on_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(QuestIndex)
-- CREATE INDEX idx_MonsterUniqueNumber_on_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(MonsterUniqueNumber)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(CharacterUniqueNumber, QuestIndex, MonsterUniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Guild
-- DESC      : ���(����) ����
--				// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - ���ܸ�ũ���� �ʵ� �߰�
--				#define GUILD_MARK_STATE_NONE					((BYTE)0)	// ��ũ ���� ����
--				#define GUILD_MARK_STATE_WAITING_PERMISSION		((BYTE)1)	// ��ũ ����� ��ٸ��� ����, ���ӻ󿡼��� ��� �Ұ�
--				#define GUILD_MARK_STATE_NORMAL					((BYTE)2)	// ��ũ ��� ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Guild (
	GuildUniqueNumber			INT			IDENTITY(1,1) PRIMARY KEY,
	GuildName					VARCHAR(30),
	GuildCommanderUniqueNumber	INT,								-- UINT
	GuildMemberCapacity			INT,								-- ���� ������ ������ �ִ� ��
	GuildState					TINYINT				DEFAULT 0,
	GuildDismemberDate			DATETIME			DEFAULT NULL,
	GuildMarkVersion			INT					DEFAULT 0,
	GuildMarkSize				INT					DEFAULT 0,
	GuildMarkImage				BINARY(1600)		DEFAULT NULL,
	WarWinPoint					INT					DEFAULT 0,		-- ������ �¸� ��
	WarLossPoint				INT					DEFAULT 0,		-- ������ �й� ��
	TotalFame					INT		NOT NULL	DEFAULT 0,		-- 2005-12-27 by cmkwon, ���� �� ���� ��
	MonthlyFame					INT		NOT NULL	DEFAULT 0,		-- 2005-12-27 by cmkwon, ���� �Ѵ� ���� ��
	GuildMarkState				TINYINT				DEFAULT 0,		-- // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - ���ܸ�ũ���� �ʵ� �߰�
	Notice						VARCHAR(512),						-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
	GuildMemberCardCashPrice	INT					DEFAULT 0,		-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
	GuildTotalFameRank			INT					DEFAULT 0,		-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����	
	GuildMonthlyFameRank		INT					DEFAULT 0		-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
)
CREATE UNIQUE INDEX idx_guildName_on_Guild ON td_Guild(GuildName)
CREATE INDEX idx_GuildCommanderUniqueNumber_on_Guild ON td_Guild(GuildCommanderUniqueNumber)
CREATE INDEX idx_CU_TotalFame_td_Guild ON td_Guild(GuildTotalFameRank)			-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
CREATE INDEX idx_CU_MonthlyFame_td_Guild ON td_Guild(GuildMonthlyFameRank)		-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_GuildMember
-- DESC      : ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_GuildMember (
	GuildUniqueNumber		INT		--UINT
		--REFERENCES td_Guild(GuildUniqueNumber)
		,
	CharacterUniqueNumber	INT
		--REFERENCES td_Character(UniqueNumber)
		,
	GuildRank				TINYINT	-- ���: GUILD_RANK_XXX, ������, ��1�����, ��1����, ��2�����, ��2����, ...
	    ,
	JoinDate DATETIME DEFAULT(NULL) -- 2006-12-18 by dhjin, ���� ���� ��
)
CREATE CLUSTERED INDEX idx_on_GuildMember ON td_GuildMember(GuildUniqueNumber)
CREATE UNIQUE INDEX idx_character_on_GuildMember ON td_GuildMember(CharacterUniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Store
-- DESC      : ĳ������ ���� ������
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Store (
	UniqueNumber	BIGINT		NOT NULL UNIQUE IDENTITY(1,1),	-- td_Store table�� Index
	AccountUniqueNumber INT		NOT NULL,	-- ���� Account �ε��� - REFERENCES td_Account(UniqueNumber)
	Possess			INT			NOT NULL,	-- ���� ĳ�����ε���, 0xFFFFFFFF(-1)�̸� ��ǰ���� ����, 0 �̸� â��, �׿� ĳ���� ������â
	ItemStorage		TINYINT		DEFAULT 0,	-- 2005-12-07 by cmkwon, 0:ĳ�����κ�, 1:â��, 2:����â��(AccountUniqueNumber=GuildUID, Possess=GuildUID)
	Wear			TINYINT		NOT NULL	-- ���� ����, 0: ������, 1: ����, 2:����+����
		DEFAULT 0,
	CurrentCount	INT			NOT NULL	-- ������ ����, ���� �ʵ尡 ���� �Ϳ� ���� ���
		DEFAULT 1,
	ScarcityNumber	BIGINT		NOT NULL	-- ȸ�Ҽ� ��ġ�� ���� �� �� �ڵ�����
		DEFAULT 0,
	ItemWindowIndex	INT			NOT NULL	-- ���� ȭ�鿡�� ������ â�� ���� �ڸ�, (0~8: ���� or ����, 100~:������â)
		DEFAULT 99,
	ItemNum			INT			NOT NULL	-- �����۰����ѹ�,	�������� �����ѹ��� ��Ÿ����.
		--REFERENCES ti_Item(ItemNum)
		,
	NumOfEnchants	SMALLINT	NOT NULL	-- ������ enchant�� ��, 0�̸� �ƹ��͵� �������� ����
		DEFAULT 0,
	PrefixCodeNum	INT			NOT NULL
		DEFAULT 0,
	SuffixCodeNum	INT			NOT NULL
		DEFAULT 0,
	CurrentEndurance	FLOAT	DEFAULT 0,	-- ���� ������, �ʱⰪ�� ti_Item.Endurance, 2006-04-26 by cmkwon - NULL ������� ����
	ColorCode		INT			DEFAULT 0,	-- �ƸӾ������� Ʃ�� ���� �ڵ� 2005-11-21 by cmkwon
	UsingTimeStamp	INT			DEFAULT 0,	-- �ð����� �������� ���� ���� ����
	CreatedTime		DATETIME	NOT NULL	-- ���� �ð�
		DEFAULT		GetDate()
)
CREATE CLUSTERED INDEX idx_AccountUniqueNumber_on_store ON td_Store(AccountUniqueNumber) WITH FILLFACTOR = 85
CREATE INDEX idx_Possess_at_store ON td_Store(Possess)
-- 2007-01-17 by cmkwon, �ε����� �̹� �߰��Ǿ� �����Ƿ� �ʿ� ���� CREATE INDEX idx_UniqueNumber_on_store ON td_Store(UniqueNumber)
CREATE INDEX idx_ItemWindowIndex_at_store ON td_Store(ItemWindowIndex)
CREATE INDEX idx_ItemStorage_at_store ON td_Store(ItemStorage)				-- 2006-03-10 by cmkwon
CREATE INDEX idx_ItemNum_td_Store ON td_Store(ItemNum)					-- 2008-06-19 by dhjin

GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_StoreSkill
-- DESC      : ĳ������ ���� Skill
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StoreSkill (
	UniqueNumber		BIGINT	NOT NULL	UNIQUE	IDENTITY(1,1),	-- // 2007-10-10 by cmkwon, UNIQUE �߰���, td_Store table�� Index
	AccountUniqueNumber	INT,				-- REFERENCES td_Account(UniqueNumber),	-- ���� Account �ε���
	Possess				INT,				-- ���� ĳ�����ε���, 0 �̸� â��, �׿� ĳ���� ������â
	ItemWindowIndex		INT,				-- ���� ȭ�鿡�� ������ â�� ���� �ڸ�, (0~8: ���� or ����, 100~:������â)
	ItemNum				INT,				-- REFERENCES ti_Item(ItemNum),	-- �����۰����ѹ�,	�������� �����ѹ��� ��Ÿ����.
	CreatedTime			DATETIME	NOT NULL	DEFAULT(GetDate()),	-- ���� �ð�
	UseTime				DATETIME DEFAULT(NULL)	-- 2006-12-05 ��ų ����ð��� ���� �߰���
)
CREATE CLUSTERED INDEX idx_AccountUniqueNumber_on_storeSkill ON td_StoreSkill(AccountUniqueNumber)
CREATE INDEX idx_Possess_at_storeSkill ON td_StoreSkill(Possess)
-- 2007-01-17 by cmkwon, �ε����� �̹� �߰��Ǿ� �����Ƿ� �ʿ� ���� CREATE INDEX idx_UniqueNumber_on_storeSkill ON td_StoreSkill(UniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Enchant
-- DESC      : ĳ������ ���� �����ۿ� ���� enchant
-- ����      : â�� ����� �����Ǹ�, enchant�� ������ �����۵� â��� ���Ƿ�
--             AccountUniqueNumber Column�� �߰��Ǿ�� �Ѵ�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Enchant (
	TargetItemUniqueNumber	BIGINT		-- ��� �������� UniqueNumber
		--REFERENCES td_Store(UniqueNumber)
		,
	TargetItemNum			INT,		-- ��� �������� ItemNum
	EnchantItemNum			INT			-- enchant�� ���� �������� ItemNum
)
CREATE CLUSTERED INDEX idx_TargetItemUniqueNumber_on_enchant ON td_Enchant(TargetItemUniqueNumber)	-- 2007-01-17 by cmkwon, �߰���
GO

-- // 2007-10-11 by cmkwon, ������� �ʴ� ���̺���
----------------------------------------------------------------------------------
---- TABLE NAME: td_MapOwnership
---- DESC      : ���� �����ǿ� ���� ����
----------------------------------------------------------------------------------
--CREATE TABLE dbo.td_MapOwnership (
--	MapIndex					SMALLINT	NOT NULL,
--	OwnerGuildUniqueNumber		INT			DEFAULT 0	NOT NULL
--)
--CREATE CLUSTERED INDEX idx_on_MapOwnership ON td_MapOwnership(MapIndex, OwnerGuildUniqueNumber)
--GO

-- // 2007-10-11 by cmkwon, ������� �ʴ� ���̺���
----------------------------------------------------------------------------------
---- TABLE NAME: td_GuildWar
---- DESC      : �ǵ��� ��û ����
----------------------------------------------------------------------------------
--CREATE TABLE dbo.td_GuildWar (
--	MapIndex					SMALLINT	NOT NULL,
--	DefenderGuildUniqueNumber	INT			NOT NULL,
--	ChallengerGuildUniqueNumber	INT			NOT NULL,
--	RequestTime					DATETIME	DEFAULT(GetDate()) NOT NULL	
--)
--CREATE CLUSTERED INDEX idx_on_guildwar ON td_GuildWar(MapIndex, DefenderGuildUniqueNumber)
--GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_FriendList
-- DESC      : ģ�� ���
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_FriendList (
	CharacterName				VARCHAR(20)	NOT NULL,
	FriendName					VARCHAR(20)	NOT NULL,
	Type						TINYINT		NOT NULL,	-- ģ�� or �ź�
	RegDate						DateTime				-- 2008-04-14 by dhjin, EP3 �ź� �ý��� -
)
CREATE CLUSTERED INDEX idx_on_FriendList ON td_FriendList(CharacterName)
GO

-- 2005-11-21 by cmkwon, ������� ���� �ּ� ó����
----------------------------------------------------------------------------------
---- TABLE NAME: td_Auction
---- DESC      : ��ǰ ���� ����
--------------------------------------------------------------------------------
--CREATE TABLE td_Auction (
--	AuctionItemKind					TINYINT		NOT NULL,	-- ������ ����, AtumProtocol.h�� AUCTION_KIND_XXX ����, ITEMKIND_XXX�� �ƴ�
--	AuctionPrice					INT			NOT NULL,	-- ��Ű�
--	AuctionStartDate				DATETIME	NOT NULL,	-- ��� ��� ��¥
--	AuctionState					TINYINT		NOT NULL,	-- ��� ���� ��Ȳ, 1:������, 2:�ȸ�
--	SellerCharacterName				VARCHAR(20)	NOT NULL,	-- �Ǹ��� �̸�
--	-- ���� ���ʹ� ������ ����
--	AuctionItemNum					INT			NOT NULL,	-- ������ �ѹ�, td_Store.ItemNum
--	AuctionItemUID					BIGINT		NOT NULL,	-- ������ ���� ��ȣ, td_Store.UniqueNumber
--	AuctionAccountUID				INT			NOT NULL,	-- ���� Account �ε���, td_Store.AccountUniqueNumber
--	AuctionCharacterUID				INT			NOT NULL,	-- ���� ĳ���� �ε���, td_Store.Possess
--	AuctionCurrentCount				INT			NOT NULL,	-- ������ ����, td_Store.CurrentCount
--	AuctionNumOfEnchants			SMALLINT	NOT NULL,	-- ������ enchant�� ��, td_Store.NumOfEnchants
--	AuctionPrefixCodeNum			INT			NOT NULL,	-- ���λ�, td_Store.PrefixCodeNum
--	AuctionSuffixCodeNum			INT			NOT NULL,	-- ���̻�, td_Store.SuffixCodeNum
--	AuctionCurrentEndurance			FLOAT		NOT NULL	-- ���� ������, �ʱⰪ�� ti_Item.Endurance
--)
--CREATE CLUSTERED INDEX idx_on_Auction ON td_Auction(AuctionItemKind)
--CREATE INDEX idx_on_Auction_CharacterUID ON td_Auction(AuctionCharacterUID)
--CREATE INDEX idx_on_Auction_ItemUID ON td_Auction(AuctionItemUID)
--GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_OccupyInfo
-- DESC      : ģ�� ���
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_OccupyInfo (
	MapIndex					INT	NOT NULL,			-- ������������ �Ͼ�� ���ε���
	MGameServerID				INT	NOT NULL,			-- ������������ �߻��ϴ� ������ä���� ����ID
	OccupyGuildUID				INT,					-- ���ɿ��� UID
	OccupyGuildName				VARCHAR(30),			-- ���ɿ��ܸ�
	OccupyGuildMasterCharUID	INT,					-- ���ɿ����� ĳ���� UID
	Tex							FLOAT,					-- ����
	CityWarDefaultTime			DATETIME,				-- ���� ���������� �ð� - �ڵ����� ������ �ð�
	CityWarSettingTime			DATETIME,				-- ���� ���������� �ð� - �������� ������ �ð�
	DefenseCounts				INT,					-- ��� ī��Ʈ
	SumOfTex					INT,					-- ������ ��
	Briefing					VARCHAR(100)			-- �������� �����ϴ� ���� �λ縻
	)
CREATE UNIQUE CLUSTERED INDEX idx_on_OccupyInfo ON td_OccupyInfo(MapIndex, MGameServerID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_InfluenceWarData
-- DESC      : 2006-04-14 by cmkwon, �߰���
--				- ������ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_InfluenceWarData (
	InfluenceType				TINYINT	NOT NULL,		-- INFLUENCE_TYPE_VCN(2) or INFLUENCE_TYPE_ANI(4)
	MGameServerID				INT	NOT NULL,			-- �������� �߻��ϴ� ������ä���� ����ID
	WartimeStage				TINYINT,				-- ���ôܰ�(0, 1, 2, 3, 4,...10)
	ContributionPoint			INT,					-- ���� �⿩��
	InflLeaderCharacterUID		INT,					-- ���� ������ CharacterUniqueNumber
	OwnerOfConflictArea		TINYINT DEFAULT(0),		-- 2006-07-12 by cmkwon, �ش� ������ �������� ���� ����
	InflSub1LeaderCharacterUID INT DEFAULT(0),		-- 2006-12-08 by dhjin, ��������1
	InflSub2LeaderCharacterUID INT DEFAULT(0),		-- 2006-12-08 by dhjin, ��������2
	MSWarOptionType				SMALLINT DEFAULT(510) -- // 2008-04-10 by dhjin, ���� ���� ǥ�� ��ȹ�� - �⺻�� 510	
	)
CREATE UNIQUE CLUSTERED INDEX idx_on_InfluenceWarData ON td_InfluenceWarData(InfluenceType, MGameServerID)	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_QuickSlot
-- DESC      : 2006-09-04 by dhjin, �� ���� ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_QuickSlot (
	AccountUID       int,
	CharacterUID     int,
	TabIdx           int,
	ItemNum_1       int,
	ItemNum_2       int,
	ItemNum_3       int,
	ItemNum_4       int,
	ItemNum_5       int,
	ItemNum_6       int,
	ItemNum_7       int,
	ItemNum_8       int,
	ItemNum_9       int,			--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	ItemNum_10      int				--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
)
-- // 2007-10-10 by cmkwon, �ε��� ���� ���� - �Ʒ��� ���� ������
-- CREATE INDEX idx_td_QuickSlot ON td_QuickSlot (AccountUID, CharacterUID)
-- CREATE INDEX idx_td_QuickSlot_TabIdx ON td_QuickSlot (TabIdx)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_QuickSlot ON td_QuickSlot(AccountUID, CharacterUID, TabIdx)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonInfo
-- DESC      : ��������Ʈ ������ �ʿ��� ����
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonInfo
(
	MapIndex	INT PRIMARY KEY,
	SummonCount	TINYINT,	-- ��������Ʈ ��ȯ �Ǿ�� �ϴ� ��
	SummonTime  DATETIME,	-- ��ȯ ���� �ð�
	SummonAttribute		TINYINT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonRangeTimeInfo
-- DESC      : ��������Ʈ ���� �ֱ� �ð� ����
-- 2007-03-29 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonRangeTimeInfo
(
	StartTime	DATETIME,			-- �ֱ� ���� ���� �ð�
	EndTime		DATETIME,			-- �ֱ� ���� �� �ð�
	SummonRange		SMALLINT,		-- ���� �ֱ� (���� : ��) ���Ӱ� ������Ʈ �Ǵ� ������ ���� atum2_db_n������ ������ �ִ´�.
	StrategyPointSummonCheck TINYINT, -- ��������Ʈ ���� üũ�� (0: �������� �ʴ´�, 1: ����) ���Ӱ� ������Ʈ �Ǵ� ������ ���� atum2_db_n������ ������ �ִ´�.
	MaxSummonCountDaily  TINYINT   -- �Ϸ翡 ��������Ʈ ���� ������ �� ���Ӱ� ������Ʈ �Ǵ�  ������ ���� atum2_db_n������ ������ �ִ´�.
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_TutorialComplete
-- DESC			 : Ʃ�丮�� �Ϸ� ���� ���̺�
-- 2007-06-28 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_TutorialComplete(
   CharacterUID                 INT,		-- ���� UID 
   TutorialUID                  INT,		-- Ʃ�丮�� UID
   TutorialCompleteTime    		DATETIME	-- Ʃ�丮�� �Ϸ�ð�
)
-- // 2007-10-10 by cmkwon, �ε��� ���� ���� - �Ʒ��� ���� ������
-- CREATE CLUSTERED INDEX idx_CharacterUID_on_td_TutorialComplete ON td_TutorialComplete(CharacterUID)
-- CREATE INDEX idx_TutorialUID_on_td_TutorialComplete ON td_TutorialComplete(TutorialUID)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_TutorialComplete ON td_TutorialComplete(CharacterUID, TutorialUID)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_user_list_warpable_to_map
-- DESC			 : // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ���̺� �߰�
--
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_user_list_warpable_to_map(
	MapIndex					INT,		-- �ش� MapIndex
	CharacterUID				INT,		-- ���� ������ CharacterUID 
)
CREATE CLUSTERED INDEX idx_MapIndex_on_td_user_list_warpable_to_map ON td_user_list_warpable_to_map(MapIndex)
CREATE UNIQUE INDEX idx_MapIndex8CharacterUID_on_td_user_list_warpable_to_map ON td_user_list_warpable_to_map(MapIndex, CharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_OutPostInfo
-- DESC		 : �������� ���� ���̺� ����
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_OutPostInfo(
   OutPostMapIndex			    	INT,			-- �������� �� ��ȣ
   OutPostCityMapIndex				INT,			-- �������� ���� �� ��ȣ
   OutPostGetTime					DATETIME,		-- ������������ ������ ������ �� ���� �ð�
   OutPostNextWarTime		  		DATETIME,		-- ������ �߻��ؾ� �ϴ� ���������� �ð�
   OutPostNextWarTimeSet			TINYINT,		-- ������ �߻��ϴ� ���������� �ð� ������ �� �� �ִ���
   OutPostGetInfl					TINYINT,		-- ���������� ������ ����
   OutPostGuildUID					INT				-- ���������� ������ ����
)
CREATE CLUSTERED INDEX idx_OutPostMapIndex_on_td_OutPostInfo ON td_OutPostInfo(OutPostMapIndex)
-- 2008-01-24 by cmkwon, S_DB: td_OutPostInfo ���̺� �ߺ��Ǵ� �����Ͱ� ���� �ȵȹǷ� �ε��� �߰���
CREATE UNIQUE INDEX idx_OutPostMapIndex8CityMapIndex_on_td_OutPostInfo ON td_OutPostInfo(OutPostMapIndex, OutPostCityMapIndex)
GO

-- ����~!!!!! �������� �⺻ ������ �� �߰�������Ѵ�.!!!
-- // 2008-01-09 by dhjin, DB �ԷµǴ� ��¥ ���� ����
TRUNCATE TABLE td_OutPostInfo
INSERT INTO td_OutPostInfo VALUES(6016, 2004, '20100101 00:00:00', '20100101 00:00:00', 1, 0, 0)
INSERT INTO td_OutPostInfo VALUES(6017, 2005, '20100101 00:00:00', '20100101 00:00:00', 1, 0, 0)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_CityLeaderInfo
-- DESC		 : ���� ����
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CityLeaderInfo(
   MapIndex			    			INT,			-- �����Ǵ� ���� �� ��ȣ ex)1001 : ������ �������� (���ڸ�), 
   Influence						TINYINT,		-- ����
   CharacterUID						INT,			-- ���� UID
   ExpediencyFundCumulative			INT,			-- ���� �ǰ� ��
   ExpediencyFund					INT,			-- ���� �ǰ� ��
   ExpediencyFundRate				INT,			-- �ǰ�����, %����, 1000������ ��� 10 => 1%
   Notice							VARCHAR(512)	-- ��������
)
CREATE CLUSTERED INDEX idx_MapIndex_on_td_CityLeaderInfo ON td_CityLeaderInfo(MapIndex)
CREATE INDEX idx_Influence_on_td_CityLeaderInfo ON td_CityLeaderInfo(Influence)
CREATE INDEX idx_CharacterUID_on_td_CityLeaderInfo ON td_CityLeaderInfo(CharacterUID)
-- // 2008-01-24 by cmkwon, S_DB: td_CityLeaderInfo ���̺� �ߺ��Ǵ� �����Ͱ� ���� �ȵǹǷ� �ε��� �߰���
CREATE INDEX idx_MapIndex8Influence_on_td_CityLeaderInfo ON td_CityLeaderInfo(MapIndex, Influence)
GO

-- ����~!!!!! �����ڰ� Ȱ���ϴ� ���ø��� �⺻���� �� �߰�������Ѵ�.!!!
TRUNCATE TABLE dbo.td_CityLeaderInfo
INSERT INTO td_CityLeaderInfo VALUES(2001, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2002, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2004, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2005, 0, 0, 0, 0, 10, NULL)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_VoterList
-- DESC		 : ��ǥ�� ����Ʈ
-- 2007-10-16 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_VoterList(
	AccountUID				INT,			-- ��ǥ�� ���� UID
    CharacterUID			INT,			-- ��ǥ�� UID
    LeaderCandidateNum		INT,			-- ��ǥ�ڰ� ��ǥ�� �ĺ��� ��ȣ
	PollDate				DATETIME		-- ��ǥ�� �ð�	
)
CREATE UNIQUE CLUSTERED INDEX idx_AccountUID_on_td_VoterList ON td_VoterList(AccountUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_LeaderCandidate
-- DESC		 : ������ �ĺ���
-- 2007-10-23 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_LeaderCandidate(
	LeaderCandidateNum		INT,			-- ������ �ĺ� ��ȣ
	AccountUID				INT,			-- ������ �ĺ� ���� UID
	CharacterUID			INT,			-- ������ �ĺ� UID
	CharacterName			VARCHAR(20),		-- ������ �ĺ� �̸�
	GuildUID				INT,			-- ������ �ĺ� ��� UID
	GuildName				VARCHAR(30),		-- ������ �ĺ� ����
	Influence				TINYINT,		-- ������ �ĺ��� ����
	DeleteCandidate			TINYINT,		-- �̹� ���� �Ⱓ�� �ĺ� Ż�� �ߴ��� ����, TRUE = Ż��
	PollCount				INT,			-- ������ �ĺ� ��ǥ��
	CampaignPromises		VARCHAR(512)	-- ������ �ĺ� ����
)
CREATE UNIQUE CLUSTERED INDEX idx_LeaderCandidateNumAndInfluence_on_td_LeaderCandiate ON td_LeaderCandidate(LeaderCandidateNum, Influence)
CREATE INDEX idx_AccountUID_on_td_LeaderCandiate ON td_LeaderCandidate(AccountUID)
CREATE INDEX idx_CharacterUID_on_td_LeaderCandiate ON td_LeaderCandidate(CharacterUID)
CREATE INDEX idx_GuildUID_on_td_LeaderCandiate ON td_LeaderCandidate(GuildUID)
CREATE INDEX idx_DeleteCandidate_on_td_LeaderCandiate ON td_LeaderCandidate(DeleteCandidate)
CREATE INDEX idx_PollCount_on_td_LeaderCandiate ON td_LeaderCandidate(PollCount)
CREATE INDEX idx_CampaignPromises_on_td_LeaderCandiate ON td_LeaderCandidate(CampaignPromises)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_NotifyMsg
-- DESC		 : // 2007-11-28 by cmkwon, �����ý��� ���� - ���� �޽��� ���� ���̺�
--
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_NotifyMsg(
	NotifyMsgUID			BIGINT		NOT NULL IDENTITY(1,1),	-- 
	CharacterUID			INT,							-- ���� ���� CharacterUID
	NotifyMsgType			TINYINT,						-- ���� �޽��� Ÿ��(NOTIFY_MSG_TYPE_XXX)
	NotifyMsgString			VARCHAR(512),					-- ���� �޽��� ��Ʈ��(512)
	SenderCharacterUID		INT,							-- ������ ���� CharacterUID
	SenderCharacterName		VARCHAR(20),					-- ������ ���� CharacterName
	CreatedTime				DATETIME DEFAULT GetDate()		-- ���� �޽��� ���� �ð�
)
CREATE UNIQUE CLUSTERED INDEX idx_NotifyMsgUID_on_td_NotifyMsg ON td_NotifyMsg(NotifyMsgUID)
CREATE INDEX idx_CharacterUID_on_td_NotifyMsg ON td_NotifyMsg(CharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_Letter
-- DESC		 : ���� ���̺�
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Letter (
	LetterUID					BIGINT IDENTITY(1,1) PRIMARY KEY,
	RecvCharacterUID			INT,
	SendCharacterName			VARCHAR(20),
	SendDate					DATETIME,
	CheckRead					TINYINT,
	Title						VARCHAR(40),
	Content						VARCHAR(1000)
)
CREATE INDEX idx_RecvCharacterUID_td_Letter ON td_Letter(RecvCharacterUID)
CREATE INDEX idx_SendDate_td_Letter ON td_Letter(SendDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_AllLetter
-- DESC		 : ��ü ���� ���̺�
-- // 2008-05-07 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AllLetter (
	AllLetterUID				BIGINT IDENTITY(1,1) PRIMARY KEY,
	SendCharacterInfl			TINYINT,
	SendCharacterUID			INT,
	SendCharacterName			VARCHAR(20),
	SendDate					DATETIME,
	Title						VARCHAR(40),
	Content						VARCHAR(1000)
)
CREATE INDEX idx_SendCharacterInfl_td_Letter ON td_AllLetter(SendCharacterInfl)
CREATE INDEX idx_SendCharacterUID_td_Letter ON td_AllLetter(SendCharacterUID)
CREATE INDEX idx_SendDate_td_Letter ON td_AllLetter(SendDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_ReadAllLetter
-- DESC		 : ��ü ���� ���� ���� ���̺�
-- // 2008-05-07 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_ReadAllLetter (
	AllLetterUID				BIGINT,
	RecvCharacterUID			INT,
	CheckDelete					TINYINT
)
CREATE INDEX idx_AllLetterUID_td_Letter ON td_ReadAllLetter(AllLetterUID)
CREATE INDEX idx_RecvCharacterUID_td_Letter ON td_ReadAllLetter(RecvCharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_GuildIntroduction
-- DESC		 : ���� �Ұ�
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_GuildIntroduction (
	GuildUID					INT,
	Content						VARCHAR(512),
	WriteDate					DATETIME
)
CREATE UNIQUE INDEX idx_GuildUID_td_GuildIntroduction ON td_GuildIntroduction(GuildUID)
CREATE INDEX idx_WriteDate_td_GuildIntroduction ON td_GuildIntroduction(WriteDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_SelfIntroduction
-- DESC		 : �ڱ� �Ұ�
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_SelfIntroduction (
	GuildUID					INT,
	CharacterUID				INT,
	Content						VARCHAR(512)
)
CREATE INDEX idx_GuildUID_td_SelfIntroduction ON td_SelfIntroduction(GuildUID)
CREATE INDEX idx_CharacterUID_td_SelfIntroduction ON td_SelfIntroduction(CharacterUID)
GO
