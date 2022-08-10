-- check: 개발 단계에서는 파라미터를 바꿀 일이 많으므로 reference constraints를 해제한다. 나중에 다시 되돌려야 함! 2003.6.12.
-- Database 자체는 한글일 경우 Korean_Wansung_CI_AS로 설정

--------------------------------------------------------------------------------
--
-- 사용자 데이타
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
--		2006-04-14 by cmkwon, 추가함
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_Character
-- DESC      : 캐릭터(기체) 정보
--				2006-04-12 by cmkwon, DownSPIOnDeath 필드 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Character (
	UniqueNumber		INT			IDENTITY(1,1) PRIMARY KEY,
	CharacterName		VARCHAR(20),
	AccountName			VARCHAR(20),		--REFERENCES td_account(AccountName)
	AccountUniqueNumber	INT,											--REFERENCES td_account(UniqueNumber)
	Gender				TINYINT,
	Race				SMALLINT,
	UnitKind			INT,		-- 주의: USHORT의 bit flag로 사용됨!
	InfluenceType		TINYINT,										-- 2005-06-23 by cmkwon
	SelectableInfluenceMask		TINYINT,								-- 2005-12-07 by cmkwon, 세력선택시 선택가능한 세력Mask, 한계정에는 하나의 세력만 선택 가능함
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
	DownSPIOnDeath		INT,				-- 2006-04-10 by cmkwon, 죽을 때 떨어지는 SPI
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
	MapIndex			SMALLINT,	-- 속해 있는 맵의 Index, ex)0101, 0102
	ChannelIndex		SMALLINT,	-- 속해 있는 맵채널의 Index, ex)0, 1, 2, ...
	MaxLevel			TINYINT,
	CurrentHP			FLOAT,
	CurrentDP			FLOAT,
	CurrentSP			SMALLINT,
	CurrentEP			FLOAT,
	BonusStat			TINYINT,
-- 2005-11-15 by cmkwon, BonusSkillPoint를 BonusStatPoint로 변경하면서 필요없어짐
--	BonusSkillPoint		TINYINT,
	BonusStatPoint		TINYINT DEFAULT 0,				-- 
	LastPartyID			BIGINT DEFAULT 0,				-- 최후의 파티 아이디
	RacingPoint			INT DEFAULT 0,					-- Racing 결과 Point
	TotalPlayTime		BIGINT DEFAULT 0,				-- 초단위
	CreatedTime			DATETIME DEFAULT GetDate(),		-- 캐릭터 생성 시간
	LastStartedTime		DATETIME DEFAULT NULL,			-- 최종 게임 시작 시간
	LevelUpTime			DATETIME DEFAULT(NULL),			-- 2006-12-18 레벨업 시간 저장
	WarPoint			INT DEFAULT 0,					-- WarPoint를 추가
	CumulativeWarPoint  INT DEFAULT 0,					-- 누적WarPoint를 추가
	ArenaWin			INT DEFAULT 0,					-- 아레나 승패 추가 승
	ArenaLose			INT DEFAULT 0,					-- 아레나 승패 추가 패
	ArenaDisConnect		INT	DEFAULT 0,		 			-- 아레나 강제 종료
	PCBangTotalPlayTime BIGINT DEFAULT 0,				-- PC방 총 플레이 시간
	SecretInfoOption	INT	DEFAULT 0,					-- // 2008-06-23 by dhjin, EP3 유저정보옵션
	NickName			VARCHAR(20)						-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_Character 테이블에 추가






)
CREATE INDEX idx_AccountName_on_character ON td_Character(AccountName)
CREATE UNIQUE INDEX idx_CharacterName_on_character ON td_Character(CharacterName)
CREATE INDEX idx_AccountUniqueNumber_on_character ON td_Character(AccountUniqueNumber)
CREATE INDEX idx_Status_on_character ON td_Character(Status)							-- 2006-01-02 by cmkwon, 한달 여단 명성 처리에서 필요
CREATE INDEX idx_NickName_on_character ON td_Character(NickName)	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_Character 테이블에 NickName 인덱스 추가, Unique하게 유지는 프로시저에서 처리한다.
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_CharacterQuest
-- DESC      : 캐릭터의 퀘스트 진행 상황
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CharacterQuest (
	CharacterUniqueNumber	INT			NOT NULL,						-- UINT 	--		REFERENCES td_Character(UniqueNumber)
	QuestIndex				INT			NOT NULL,						--		REFERENCES Quest(QuestIndex)
	QuestState				TINYINT		NOT NULL DEFAULT 0,				-- 완료, 진행중
	QuestParam1				INT			DEFAULT 0,
	QuestTimeStamp			DATETIME	NOT NULL DEFAULT GetDate(),
	QuestPlayTimeStamp		BIGINT		NOT NULL DEFAULT 0


)
-- // 2007-10-10 by cmkwon, 인덱스 수정 쿼리 - 아래와 같이 수정함
-- CREATE CLUSTERED INDEX idx_CharacterUniqueNumber_at_characterQuest_Questindex ON td_CharacterQuest(CharacterUniqueNumber)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_CharacterQuest ON td_CharacterQuest(CharacterUNiqueNumber, QuestIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_CharacterQuestMonsterCount
-- DESC      : 캐릭터의 퀘스트시 사냥한 몬스터의 카운터를 저장
--				2005-10-17 by cmkwon
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CharacterQuestMonsterCount (
	CharacterUniqueNumber	INT			NOT NULL,						-- UINT 	--		REFERENCES td_Character(UniqueNumber)
	QuestIndex				INT			NOT NULL,						--		REFERENCES Quest(QuestIndex)
	MonsterUniqueNumber		INT			DEFAULT	0,						-- 사냥한 몬스터의 유니크넘버			
	Count					INT			DEFAULT	0						-- 사냥한 몬스터의 수
)
-- // 2007-10-10 by cmkwon, 인덱스 수정 쿼리 - 아래와 같이 수정함
-- CREATE CLUSTERED INDEX idx_CharacterUniqueNumber_at_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(CharacterUniqueNumber)
-- CREATE INDEX idx_QuestIndex_on_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(QuestIndex)
-- CREATE INDEX idx_MonsterUniqueNumber_on_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(MonsterUniqueNumber)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_CharacterQuestMonsterCount ON td_CharacterQuestMonsterCount(CharacterUniqueNumber, QuestIndex, MonsterUniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Guild
-- DESC      : 길드(여대) 정보
--				// 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 여단마크상태 필드 추가
--				#define GUILD_MARK_STATE_NONE					((BYTE)0)	// 마크 없는 상태
--				#define GUILD_MARK_STATE_WAITING_PERMISSION		((BYTE)1)	// 마크 허용을 기다리는 상태, 게임상에서는 사용 불가
--				#define GUILD_MARK_STATE_NORMAL					((BYTE)2)	// 마크 사용 중인 상태
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Guild (
	GuildUniqueNumber			INT			IDENTITY(1,1) PRIMARY KEY,
	GuildName					VARCHAR(30),
	GuildCommanderUniqueNumber	INT,								-- UINT
	GuildMemberCapacity			INT,								-- 가입 가능한 길드원의 최대 수
	GuildState					TINYINT				DEFAULT 0,
	GuildDismemberDate			DATETIME			DEFAULT NULL,
	GuildMarkVersion			INT					DEFAULT 0,
	GuildMarkSize				INT					DEFAULT 0,
	GuildMarkImage				BINARY(1600)		DEFAULT NULL,
	WarWinPoint					INT					DEFAULT 0,		-- 여단전 승리 수
	WarLossPoint				INT					DEFAULT 0,		-- 여단전 패배 수
	TotalFame					INT		NOT NULL	DEFAULT 0,		-- 2005-12-27 by cmkwon, 여단 총 누적 명성
	MonthlyFame					INT		NOT NULL	DEFAULT 0,		-- 2005-12-27 by cmkwon, 여단 한달 누적 명성
	GuildMarkState				TINYINT				DEFAULT 0,		-- // 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 여단마크상태 필드 추가
	Notice						VARCHAR(512),						-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
	GuildMemberCardCashPrice	INT					DEFAULT 0,		-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
	GuildTotalFameRank			INT					DEFAULT 0,		-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항	
	GuildMonthlyFameRank		INT					DEFAULT 0		-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
)
CREATE UNIQUE INDEX idx_guildName_on_Guild ON td_Guild(GuildName)
CREATE INDEX idx_GuildCommanderUniqueNumber_on_Guild ON td_Guild(GuildCommanderUniqueNumber)
CREATE INDEX idx_CU_TotalFame_td_Guild ON td_Guild(GuildTotalFameRank)			-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
CREATE INDEX idx_CU_MonthlyFame_td_Guild ON td_Guild(GuildMonthlyFameRank)		-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_GuildMember
-- DESC      : 길드원 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_GuildMember (
	GuildUniqueNumber		INT,		--UINT		--REFERENCES td_Guild(GuildUniqueNumber)
	CharacterUniqueNumber	INT,		--REFERENCES td_Character(UniqueNumber)
	GuildRank				TINYINT,	-- 계급: GUILD_RANK_XXX, 여단장, 제1대대장, 제1대대원, 제2대대장, 제2대대원, ...
	JoinDate DATETIME DEFAULT(NULL) -- 2006-12-18 by dhjin, 여단 가입 날
)
CREATE CLUSTERED INDEX idx_on_GuildMember ON td_GuildMember(GuildUniqueNumber)
CREATE UNIQUE INDEX idx_character_on_GuildMember ON td_GuildMember(CharacterUniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Store
-- DESC      : 캐릭터의 소유 아이템
--				-- // 2009-08-25 by cmkwon, 사용하지 않는 필드 제거(td_Store.ScarcityNumber) - 
--				-- // 2009-08-26 by cmkwon, 그래픽 리소스 변경 시스템 구현 - td_Store.ShapeItemNum 필드 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Store (
	UniqueNumber	BIGINT		NOT NULL UNIQUE IDENTITY(1,1),	-- td_Store table의 Index
	AccountUniqueNumber INT		NOT NULL,	-- 소유 Account 인덱스 - REFERENCES td_account(UniqueNumber)
	Possess			INT			NOT NULL,	-- 소유 캐릭터인덱스, 0xFFFFFFFF(-1)이면 물품대행 상점, 0 이면 창고, 그외 캐릭터 아이템창
	ItemStorage		TINYINT		DEFAULT 0,	-- 2005-12-07 by cmkwon, 0:캐릭터인벤, 1:창고, 2:여단창고(AccountUniqueNumber=GuildUID, Possess=GuildUID)
	Wear			TINYINT		NOT NULL	-- 장착 여부, 0: 미장착, 1: 장착, 2:장착+장전
		DEFAULT 0,
	CurrentCount	INT			NOT NULL	-- 아이템 개수, 가변 필드가 없는 것에 대해 사용
		DEFAULT 1,
-- // 2009-08-25 by cmkwon, 사용하지 않는 필드 제거(td_Store.ScarcityNumber) - 제거
--	ScarcityNumber	BIGINT		NOT NULL	-- 회소성 수치가 상위 일 때 자동생성
--		DEFAULT 0,
	ItemWindowIndex	INT			NOT NULL	-- 게임 화면에서 아이템 창에 들어가는 자리, (0~8: 장착 or 장전, 100~:아이템창)
		DEFAULT 99,
	ItemNum			INT			NOT NULL	-- 아이템고유넘버,	아이템의 고유넘버를 나타낸다.
		--REFERENCES ti_Item(ItemNum)
		,
	NumOfEnchants	SMALLINT	NOT NULL	-- 적용한 enchant의 수, 0이면 아무것도 적용하지 않음
		DEFAULT 0,
	PrefixCodeNum	INT			NOT NULL
		DEFAULT 0,
	SuffixCodeNum	INT			NOT NULL
		DEFAULT 0,
	CurrentEndurance	FLOAT	DEFAULT 0,	-- 남은 내구도, 초기값은 ti_Item.Endurance, 2006-04-26 by cmkwon - NULL 허용으로 수정
	ColorCode		INT			DEFAULT 0,	-- // 2009-08-26 by cmkwon, 그래픽 리소스 변경 시스템 구현 - 무기의 EffectItemNum으로 사용, 아머아이템의 튜닝 색상 코드 2005-11-21 by cmkwon
	UsingTimeStamp	INT			DEFAULT 0,	-- 시간제한 아이템이 사용된 시작 저장
	CreatedTime		DATETIME	NOT NULL DEFAULT GETDATE(),	-- 생성 시간
	ShapeItemNum	INT,										-- // 2009-08-26 by cmkwon, 그래픽 리소스 변경 시스템 구현 - 외형ItemNum
	MainSvrItemUID				BIGINT,		-- // 2009-09-09 ~ 2010 by dhjin, 인피니티 - Main서버 아이템 UID 추가
	CoolingTime		INT						-- // 2009-09-09 ~ 2010-02-10 by dhjin, 인피니티 - 발동류장착아이템
)
CREATE CLUSTERED INDEX idx_AccountUniqueNumber_on_store ON td_Store(AccountUniqueNumber) WITH FILLFACTOR = 85
CREATE INDEX idx_Possess_at_store ON td_Store(Possess)
-- 2007-01-17 by cmkwon, 인덱스가 이미 추가되어 있음므로 필요 없음 CREATE INDEX idx_UniqueNumber_on_store ON td_Store(UniqueNumber)
CREATE INDEX idx_ItemWindowIndex_at_store ON td_Store(ItemWindowIndex)
CREATE INDEX idx_ItemStorage_at_store ON td_Store(ItemStorage)				-- 2006-03-10 by cmkwon
CREATE INDEX idx_ItemNum_td_Store ON td_Store(ItemNum)					-- 2008-06-19 by dhjin

GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_StoreSkill
-- DESC      : 캐릭터의 소유 Skill
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StoreSkill (
	UniqueNumber		BIGINT	NOT NULL	UNIQUE	IDENTITY(1,1),	-- // 2007-10-10 by cmkwon, UNIQUE 추가함, td_Store table의 Index
	AccountUniqueNumber	INT,				-- REFERENCES td_account(UniqueNumber),	-- 소유 Account 인덱스
	Possess				INT,				-- 소유 캐릭터인덱스, 0 이면 창고, 그외 캐릭터 아이템창
	ItemWindowIndex		INT,				-- 게임 화면에서 아이템 창에 들어가는 자리, (0~8: 장착 or 장전, 100~:아이템창)
	ItemNum				INT,				-- REFERENCES ti_Item(ItemNum),	-- 아이템고유넘버,	아이템의 고유넘버를 나타낸다.
	CreatedTime			DATETIME	NOT NULL	DEFAULT(GetDate()),	-- 생성 시간
	UseTime				DATETIME DEFAULT(NULL)	-- 2006-12-05 스킬 재사용시간을 위해 추가함
)
CREATE CLUSTERED INDEX idx_AccountUniqueNumber_on_storeSkill ON td_StoreSkill(AccountUniqueNumber)
CREATE INDEX idx_Possess_at_storeSkill ON td_StoreSkill(Possess)
-- 2007-01-17 by cmkwon, 인덱스가 이미 추가되어 있음므로 필요 없음 CREATE INDEX idx_UniqueNumber_on_storeSkill ON td_StoreSkill(UniqueNumber)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_Enchant
-- DESC      : 캐릭터의 소유 아이템에 대한 enchant
-- 주의      : 창고 기능이 구현되면, enchant가 더해진 아이템도 창고로 가므로
--             AccountUniqueNumber Column이 추가되어야 한다
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Enchant (
	TargetItemUniqueNumber	BIGINT,	 				-- 대상 아이템의 UniqueNumber		--REFERENCES td_Store(UniqueNumber)
	TargetItemNum			INT,				-- 대상 아이템의 ItemNum
	EnchantItemNum			INT,				-- enchant로 쓰인 아이템의 ItemNum
	SequenceNumber			bigint IDENTITY(1,1) NOT NULL
)

CREATE CLUSTERED INDEX idx_TargetItemUniqueNumber_on_enchant ON td_Enchant(TargetItemUniqueNumber)	-- 2007-01-17 by cmkwon, 추가함
GO

--------------------------------------------------------------------------------
-- TABLE NAME	: dbo.atum_Temporary_Infomation
-- DESC			: --// 2013-01-02 by hskim, 임시 시스템 정보 저장용 테이블
--				: Type = [1]	[Date1 = 생성시 [td_Enchant]의 SequenceNumber 최고 숫자, 이 번호 이하는 인첸트 순번을 무시한다]
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[atum_Temporary_SystemInfomation]
(
	[UID]			bigint			identity(1,1)	NOT NULL,
	[CreateDate]	datetime		NOT NULL,
	[Type]			int				NOT NULL,
	[Data1]			int				BIGINT,		--> 130605_DB스키마_04_(아이템추가보안)_DBQuery(atum2_db_[n] & stum2_db_arena)
	[Data2]			int				NULL,
	[Data3]			nvarchar(1024)	NULL,
	[Data4]			nvarchar(1024)	NULL
)
GO

INSERT [dbo].[atum_Temporary_SystemInfomation]([CreateDate], [Type], [Data1]) SELECT getdate(), 1, max([SequenceNumber]) FROM [dbo].[td_Enchant]
INSERT [dbo].[atum_Temporary_SystemInfomation]([CreateDate], [Type], [Data1]) SELECT getdate(), 2, max([UniqueNumber]) FROM [dbo].[td_Store]
GO

-- // 2007-10-11 by cmkwon, 사용하지 않는 테이블임
----------------------------------------------------------------------------------
---- TABLE NAME: td_MapOwnership
---- DESC      : 맵의 소유권에 관한 정보
----------------------------------------------------------------------------------
--CREATE TABLE dbo.td_MapOwnership (
--	MapIndex					SMALLINT	NOT NULL,
--	OwnerGuildUniqueNumber		INT			DEFAULT 0	NOT NULL
--)
--CREATE CLUSTERED INDEX idx_on_MapOwnership ON td_MapOwnership(MapIndex, OwnerGuildUniqueNumber)
--GO

-- // 2007-10-11 by cmkwon, 사용하지 않는 테이블임
----------------------------------------------------------------------------------
---- TABLE NAME: td_GuildWar
---- DESC      : 실드전 신청 정보
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
-- DESC      : 친구 목록
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_FriendList (
	CharacterName				VARCHAR(20)	NOT NULL,
	FriendName					VARCHAR(20)	NOT NULL,
	Type						TINYINT		NOT NULL,	-- 친구 or 거부
	RegDate						DateTime				-- 2008-04-14 by dhjin, EP3 거부 시스템 -
)
CREATE CLUSTERED INDEX idx_on_FriendList ON td_FriendList(CharacterName)
GO

-- 2005-11-21 by cmkwon, 사용하지 않은 주석 처리함
----------------------------------------------------------------------------------
---- TABLE NAME: td_Auction
---- DESC      : 물품 대행 상점
--------------------------------------------------------------------------------
--CREATE TABLE td_Auction (
--	AuctionItemKind					TINYINT		NOT NULL,	-- 아이템 종류, AtumProtocol.h의 AUCTION_KIND_XXX 참고, ITEMKIND_XXX가 아님
--	AuctionPrice					INT			NOT NULL,	-- 경매가
--	AuctionStartDate				DATETIME	NOT NULL,	-- 경매 등록 날짜
--	AuctionState					TINYINT		NOT NULL,	-- 경매 진행 상황, 1:진행중, 2:팔림
--	SellerCharacterName				VARCHAR(20)	NOT NULL,	-- 판매자 이름
--	-- 여기 부터는 아이템 정보
--	AuctionItemNum					INT			NOT NULL,	-- 아이템 넘버, td_Store.ItemNum
--	AuctionItemUID					BIGINT		NOT NULL,	-- 아이템 고유 번호, td_Store.UniqueNumber
--	AuctionAccountUID				INT			NOT NULL,	-- 소유 Account 인덱스, td_Store.AccountUniqueNumber
--	AuctionCharacterUID				INT			NOT NULL,	-- 소유 캐릭터 인덱스, td_Store.Possess
--	AuctionCurrentCount				INT			NOT NULL,	-- 아이템 개수, td_Store.CurrentCount
--	AuctionNumOfEnchants			SMALLINT	NOT NULL,	-- 적용한 enchant의 수, td_Store.NumOfEnchants
--	AuctionPrefixCodeNum			INT			NOT NULL,	-- 접두사, td_Store.PrefixCodeNum
--	AuctionSuffixCodeNum			INT			NOT NULL,	-- 접미사, td_Store.SuffixCodeNum
--	AuctionCurrentEndurance			FLOAT		NOT NULL	-- 남은 내구도, 초기값은 ti_Item.Endurance
--)
--CREATE CLUSTERED INDEX idx_on_Auction ON td_Auction(AuctionItemKind)
--CREATE INDEX idx_on_Auction_CharacterUID ON td_Auction(AuctionCharacterUID)
--CREATE INDEX idx_on_Auction_ItemUID ON td_Auction(AuctionItemUID)
--GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_OccupyInfo
-- DESC      : 친구 목록
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_OccupyInfo (
	MapIndex					INT	NOT NULL,			-- 도시점령전이 일어나는 맵인덱스
	MGameServerID				INT	NOT NULL,			-- 도시점령전이 발생하는 서버군채널의 서버ID
	OccupyGuildUID				INT,					-- 점령여단 UID
	OccupyGuildName				VARCHAR(30),			-- 점령여단명
	OccupyGuildMasterCharUID	INT,					-- 점령여단장 캐릭터 UID
	Tex							FLOAT,					-- 세금
	CityWarDefaultTime			DATETIME,				-- 다음 도시점령전 시간 - 자동으로 설정된 시간
	CityWarSettingTime			DATETIME,				-- 다음 도시점령전 시간 - 여단장이 설정한 시간
	DefenseCounts				INT,					-- 방어 카운트
	SumOfTex					INT,					-- 세금은 합
	Briefing					VARCHAR(100)			-- 여단장이 설정하는 상점 인사말
	)
CREATE UNIQUE CLUSTERED INDEX idx_on_OccupyInfo ON td_OccupyInfo(MapIndex, MGameServerID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_InfluenceWarData
-- DESC      : 2006-04-14 by cmkwon, 추가함
--				- 세력전 관련 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_InfluenceWarData (
	InfluenceType				TINYINT	NOT NULL,		-- INFLUENCE_TYPE_VCN(2) or INFLUENCE_TYPE_ANI(4)
	MGameServerID				INT	NOT NULL,			-- 점령전이 발생하는 서버군채널의 서버ID
	WartimeStage				TINYINT,				-- 전시단계(0, 1, 2, 3, 4,...10)
	ContributionPoint			INT,					-- 세력 기여도
	InflLeaderCharacterUID		INT,					-- 세력 지도자 CharacterUniqueNumber
	OwnerOfConflictArea		TINYINT DEFAULT(0),		-- 2006-07-12 by cmkwon, 해당 세력이 분쟁지역 소유 여부
	InflSub1LeaderCharacterUID INT DEFAULT(0),		-- 2006-12-08 by dhjin, 부지도자1
	InflSub2LeaderCharacterUID INT DEFAULT(0),		-- 2006-12-08 by dhjin, 부지도자2
	MSWarOptionType				SMALLINT DEFAULT(510), -- // 2008-04-10 by dhjin, 모선전 정보 표시 기획안 - 기본값 510	
	[ConsecutiveVictories] SMALLINT NOT NULL DEFAULT 0		--> 130605_DB스키마_03_(세력포인트개선)_DBQuery(atum2_db_[n] & stum2_db_arena)
	)
CREATE UNIQUE CLUSTERED INDEX idx_on_InfluenceWarData ON td_InfluenceWarData(InfluenceType, MGameServerID)	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_QuickSlot
-- DESC      : 2006-09-04 by dhjin, 퀵 슬롯 저장 정보
--				2012-06-19 by jhseol, 슬롯 사용 목적 추가(아레나 전용 슬롯) 및 인덱스 수정, 기본값 셋팅
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
	ItemNum_9       int,			--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
	ItemNum_10      int				--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
	,SlotPurpose	int				-- 슬롯 사용 목적('0'메인, '1'아레나)
)
-- // 2007-10-10 by cmkwon, 인덱스 수정 쿼리 - 아래와 같이 수정함
-- CREATE INDEX idx_td_QuickSlot ON td_QuickSlot (AccountUID, CharacterUID)
-- CREATE INDEX idx_td_QuickSlot_TabIdx ON td_QuickSlot (TabIdx)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_QuickSlot ON td_QuickSlot(AccountUID, CharacterUID, TabIdx, SlotPurpose)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonInfo
-- DESC      : 전략포인트 생성에 필요한 정보
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonInfo
(
	MapIndex	INT PRIMARY KEY,
	SummonCount	TINYINT,	-- 전략포인트 소환 되어야 하는 수
	SummonTime  DATETIME,	-- 소환 예정 시간
	SummonAttribute		TINYINT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonRangeTimeInfo
-- DESC      : 전략포인트 생성 주기 시간 정보
-- 2007-03-29 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonRangeTimeInfo
(
	StartTime	DATETIME,			-- 주기 설정 시작 시간
	EndTime		DATETIME,			-- 주기 설정 끝 시간
	SummonRange		SMALLINT,		-- 생성 주기 (단위 : 일) 새롭게 업데이트 되는 예약을 위해 atum2_db_n에서도 가지고 있는다.
	StrategyPointSummonCheck TINYINT, -- 전략포인트 생성 체크값 (0: 생성하지 않는다, 1: 생성) 새롭게 업데이트 되는 예약을 위해 atum2_db_n에서도 가지고 있는다.
	MaxSummonCountDaily  TINYINT   -- 하루에 전략포인트 생성 가능한 수 새롭게 업데이트 되는  예약을 위해 atum2_db_n에서도 가지고 있는다.
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_TutorialComplete
-- DESC			 : 튜토리얼 완료 정보 테이블
-- 2007-06-28 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_TutorialComplete(
   CharacterUID                 INT,		-- 유저 UID 
   TutorialUID                  INT,		-- 튜토리얼 UID
   TutorialCompleteTime    		DATETIME	-- 튜토리얼 완료시간
)
-- // 2007-10-10 by cmkwon, 인덱스 수정 쿼리 - 아래와 같이 수정함
-- CREATE CLUSTERED INDEX idx_CharacterUID_on_td_TutorialComplete ON td_TutorialComplete(CharacterUID)
-- CREATE INDEX idx_TutorialUID_on_td_TutorialComplete ON td_TutorialComplete(TutorialUID)
CREATE UNIQUE CLUSTERED INDEX idx_CU_td_TutorialComplete ON td_TutorialComplete(CharacterUID, TutorialUID)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_user_list_warpable_to_map
-- DESC			 : // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 테이블 추가
--
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_user_list_warpable_to_map(
	MapIndex					INT,		-- 해당 MapIndex
	CharacterUID				INT,		-- 접속 가능한 CharacterUID 
)
CREATE CLUSTERED INDEX idx_MapIndex_on_td_user_list_warpable_to_map ON td_user_list_warpable_to_map(MapIndex)
CREATE UNIQUE INDEX idx_MapIndex8CharacterUID_on_td_user_list_warpable_to_map ON td_user_list_warpable_to_map(MapIndex, CharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_OutPostInfo
-- DESC		 : 전진기지 정보 테이블 생성
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_OutPostInfo(
   OutPostMapIndex			    	INT,			-- 전진기지 맵 번호
   OutPostCityMapIndex				INT,			-- 전진기지 도시 맵 번호
   OutPostGetTime					DATETIME,		-- 전진기지전이 끝나고 소유가 된 시점 시간
   OutPostNextWarTime		  		DATETIME,		-- 다음에 발생해야 하는 전진기지전 시간
   OutPostNextWarTimeSet			TINYINT,		-- 다음에 발생하는 전진기지전 시간 설정을 할 수 있는지
   OutPostGetInfl					TINYINT,		-- 전진기지를 소유한 세력
   OutPostGuildUID					INT				-- 전진기지를 소유한 여단
)
CREATE CLUSTERED INDEX idx_OutPostMapIndex_on_td_OutPostInfo ON td_OutPostInfo(OutPostMapIndex)
-- 2008-01-24 by cmkwon, S_DB: td_OutPostInfo 테이블에 중복되는 데이터가 들어가면 안된므로 인덱스 추가함
CREATE UNIQUE INDEX idx_OutPostMapIndex8CityMapIndex_on_td_OutPostInfo ON td_OutPostInfo(OutPostMapIndex, OutPostCityMapIndex)
GO

-- 주의~!!!!! 전진기지 기본 정보를 꼭 추가해줘야한다.!!!
-- // 2008-01-09 by dhjin, DB 입력되는 날짜 형식 변경
TRUNCATE TABLE td_OutPostInfo
INSERT INTO td_OutPostInfo VALUES(6016, 2004, '20100101 00:00:00', '20100101 00:00:00', 1, 0, 0)
INSERT INTO td_OutPostInfo VALUES(6017, 2005, '20100101 00:00:00', '20100101 00:00:00', 1, 0, 0)
INSERT INTO td_OutPostInfo VALUES(6018, 2006, '20100101 00:00:00', '20100101 00:00:00', 1, 0, 0)
INSERT INTO td_OutPostInfo VALUES(4303, 2007, '20500101 00:00:00', '20500101 00:00:00', 1, 0, 0)	--> 130323_DB스키마_02_(NGC 전진기지 트리거)_DBQuery(atum2_db_[n] & stum2_db_arena)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_CityLeaderInfo
-- DESC		 : 도시 정보
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CityLeaderInfo(
   MapIndex			    			INT,			-- 관리되는 도시 맵 번호 ex)1001 : 지도자 공지사항 (바자맵), 
   Influence						TINYINT,		-- 세력
   CharacterUID						INT,			-- 유저 UID
   ExpediencyFundCumulative			INT,			-- 누적 판공 비
   ExpediencyFund					INT,			-- 가용 판공 비
   ExpediencyFundRate				INT,			-- 판공비율, %단위, 1000단위로 계산 10 => 1%
   Notice							VARCHAR(512)	-- 공지사항
)
CREATE CLUSTERED INDEX idx_MapIndex_on_td_CityLeaderInfo ON td_CityLeaderInfo(MapIndex)
CREATE INDEX idx_Influence_on_td_CityLeaderInfo ON td_CityLeaderInfo(Influence)
CREATE INDEX idx_CharacterUID_on_td_CityLeaderInfo ON td_CityLeaderInfo(CharacterUID)
-- // 2008-01-24 by cmkwon, S_DB: td_CityLeaderInfo 테이블에 중복되는 데이터가 들어가면 안되므로 인덱스 추가함
CREATE INDEX idx_MapIndex8Influence_on_td_CityLeaderInfo ON td_CityLeaderInfo(MapIndex, Influence)
GO

-- 주의~!!!!! 지도자가 활동하는 도시맵은 기본값을 꼭 추가해줘야한다.!!!
TRUNCATE TABLE dbo.td_CityLeaderInfo
INSERT INTO td_CityLeaderInfo VALUES(2001, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2002, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2004, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2005, 0, 0, 0, 0, 10, NULL)
INSERT INTO td_CityLeaderInfo VALUES(2006, 0, 0, 0, 0, 10, NULL)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_VoterList
-- DESC		 : 투표자 리스트
-- 2007-10-16 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_VoterList(
	AccountUID				INT,			-- 투표자 계정 UID
    CharacterUID			INT,			-- 투표자 UID
    LeaderCandidateNum		INT,			-- 투표자가 투표한 후보자 번호
	PollDate				DATETIME		-- 투표한 시간	
)
CREATE UNIQUE CLUSTERED INDEX idx_AccountUID_on_td_VoterList ON td_VoterList(AccountUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_LeaderCandidate
-- DESC		 : 지도자 후보들
-- 2007-10-23 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_LeaderCandidate(
	LeaderCandidateNum		INT,			-- 지도자 후보 번호
	AccountUID				INT,			-- 지도자 후보 계정 UID
	CharacterUID			INT,			-- 지도자 후보 UID
	CharacterName			VARCHAR(20),		-- 지도자 후보 이름
	GuildUID				INT,			-- 지도자 후보 길드 UID
	GuildName				VARCHAR(30),		-- 지도자 후보 길드명
	Influence				TINYINT,		-- 지도자 후보의 세력
	DeleteCandidate			TINYINT,		-- 이번 선거 기간에 후보 탈퇴 했는지 여부, TRUE = 탈퇴
	PollCount				INT,			-- 지도자 후보 득표수
	CampaignPromises		VARCHAR(512)	-- 지도자 후보 공약
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
-- DESC		 : // 2007-11-28 by cmkwon, 통지시스템 구현 - 통지 메시지 저장 테이블
--
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_NotifyMsg(
	NotifyMsgUID			BIGINT		NOT NULL IDENTITY(1,1),	-- 
	CharacterUID			INT,							-- 통지 받을 CharacterUID
	NotifyMsgType			TINYINT,						-- 통지 메시지 타입(NOTIFY_MSG_TYPE_XXX)
	NotifyMsgString			VARCHAR(512),					-- 통지 메시지 스트링(512)
	SenderCharacterUID		INT,							-- 통지를 보낸 CharacterUID
	SenderCharacterName		VARCHAR(20),					-- 통지를 보낸 CharacterName
	CreatedTime				DATETIME DEFAULT GetDate()		-- 통지 메시지 생성 시간
)
CREATE UNIQUE CLUSTERED INDEX idx_NotifyMsgUID_on_td_NotifyMsg ON td_NotifyMsg(NotifyMsgUID)
CREATE INDEX idx_CharacterUID_on_td_NotifyMsg ON td_NotifyMsg(CharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_Letter
-- DESC		 : 편지 테이블
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
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
-- DESC		 : 전체 편지 테이블
-- // 2008-05-07 by dhjin, EP3 편지시스템 - 
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
-- DESC		 : 전체 편지 읽은 정보 테이블
-- // 2008-05-07 by dhjin, EP3 편지시스템 - 
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
-- DESC		 : 여단 소개
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
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
-- DESC		 : 자기 소개
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_SelfIntroduction (
	GuildUID					INT,
	CharacterUID				INT,
	Content						VARCHAR(512)
)
CREATE INDEX idx_GuildUID_td_SelfIntroduction ON td_SelfIntroduction(GuildUID)
CREATE INDEX idx_CharacterUID_td_SelfIntroduction ON td_SelfIntroduction(CharacterUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_DeclarationOfWar
-- DESC      : 선전 포고 테이블
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_DeclarationOfWar (
	Influence				TINYINT,
	MSWarStep				TINYINT,
	NCP						INT,
	MSNum               	INT,
	MSAppearanceMap     	INT,
	MSWarStepStartTime  	datetime,	
	MSWarStepEndTime		datetime,
	MSWarStartTime			datetime,	
	MSWarEndTime			datetime,
	SelectCount				TINYINT,
	GiveUp					BIT,
	MSWarEndState			TINYINT
)
CREATE UNIQUE CLUSTERED INDEX idx_on_DeclarationOfWar ON td_DeclarationOfWar(Influence, MSWarStep)
GO
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 1, 0, 0, 0, GetDate(), DateAdd(day, 7, GetDate()), DateAdd(day, 3, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 2, 0, 0, 0, DateAdd(day, 7, GetDate()), DateAdd(day, 14, GetDate()), DateAdd(day, 10, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 3, 0, 0, 0, DateAdd(day, 14, GetDate()), DateAdd(day, 21, GetDate()), DateAdd(day, 17, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 4, 0, 0, 0, DateAdd(day, 21, GetDate()), DateAdd(day, 28, GetDate()), DateAdd(day, 24, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 5, 0, 0, 0, DateAdd(day, 28, GetDate()), DateAdd(day, 35, GetDate()), DateAdd(day, 31, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (2, 99, 0, 0, 0, DateAdd(day, 35, GetDate()), DateAdd(day, 42, GetDate()), DateAdd(day, 38, GetDate()), NULL, 3, 0, 0)

INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 1, 0, 0, 0, GetDate(), DateAdd(day, 7, GetDate()), DateAdd(day, 3, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 2, 0, 0, 0, DateAdd(day, 7, GetDate()), DateAdd(day, 14, GetDate()), DateAdd(day, 10, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 3, 0, 0, 0, DateAdd(day, 14, GetDate()), DateAdd(day, 21, GetDate()), DateAdd(day, 17, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 4, 0, 0, 0, DateAdd(day, 21, GetDate()), DateAdd(day, 28, GetDate()), DateAdd(day, 24, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 5, 0, 0, 0, DateAdd(day, 28, GetDate()), DateAdd(day, 35, GetDate()), DateAdd(day, 31, GetDate()), NULL, 3, 0, 0)
INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
										, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
	VALUES (4, 99, 0, 0, 0, DateAdd(day, 35, GetDate()), DateAdd(day, 42, GetDate()), DateAdd(day, 38, GetDate()), NULL, 3, 0, 0)
GO


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_selfServerGroupInfo
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_wrk_selfServerGroupList 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_selfServerGroupInfo(
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20)
)
CREATE UNIQUE CLUSTERED INDEX idx_ServiGID_on_td_wrk_selfServerGroupInfo ON td_wrk_selfServerGroupInfo(ServerGroupID)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: td_InfluenceRate
-- DESC      : // 2009-09-16 by cmkwon, 세력 초기화시 어뷰징 방지 구현 - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_InfluenceRate(
	StartLevel				TINYINT,
	EndLevel				TINYINT,
	AllowablePercent		INT DEFAULT 0,
	UpdateTime				DATETIME DEFAULT GETDATE(),		-- 수정 시간
	NormalUserCount			INT DEFAULT 0,
	BCUUserCount			INT DEFAULT 0,
	ANIUserCount			INT DEFAULT 0
)
CREATE CLUSTERED INDEX idx_StartLv_on_td_InfluenceRate ON td_InfluenceRate(StartLevel)
CREATE UNIQUE INDEX idx_StartLv_EndLv_on_td_InfluenceRate ON td_InfluenceRate(StartLevel, EndLevel)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_InfinityImpute
-- 2009-09-09 ~ 2010 by dhjin, 인피니티
-- DESC      : 인피니티 귀속 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_InfinityImpute (
	AccountUID				INT			NOT NULL,
	CharacterUID			INT			NOT NULL,
	InfinityModeUID			INT			NOT NULL,		--REFERENCES ti_InfinityMode(InfinityModeUID)
	EntranceCount			TINYINT		DEFAULT(0),
	StartTime				DATETIME
)
CREATE UNIQUE CLUSTERED INDEX idx_on_td_InfinityImpute
	ON td_InfinityImpute (AccountUID, CharacterUID, InfinityModeUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Log_Infinity 
-- 2009-09-09 ~ 2010 by dhjin, 인피니티
-- DESC      : 인피니티 로그
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_Log_Infinity (
	AccountUID				INT			NOT NULL,
	CharacterUID			INT			NOT NULL,
	InfinityModeUID			INT			NOT NULL,
	StartTime				DATETIME,
	EndTime					DATETIME,
	DeathCount				INT			DEFAULT(0),
	KillCount				INT			DEFAULT(0),
	EndAllExp				FLOAT			DEFAULT(0),
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_pet
-- // 2010-06-15 by shcho&hslee 펫시스템 - 유저가 소유한 펫 기본 정보 테이블 추가 쿼리
-- // 2011-08-30 by hskim, 파트너 시스템 2차 : 데이터 구조 변경
-- DESC      : 인피니티 로그
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_pet]
(
	[ItemUID]				BIGINT		NOT NULL,
	[PetIndex]				INT			NOT NULL,
	[Experience]			FLOAT		NOT NULL,
	[Level]					INT			NOT NULL,
	[Name]					VARCHAR(40)	NOT NULL,
	[ExpRatio]				TINYINT		NOT NULL,
	[EnableSocketCount]		TINYINT		NOT NULL,
	[SocketItem1]			BIGINT		NOT NULL,
	[SocketItem2]			BIGINT		NOT NULL,
	[SocketItem3]			BIGINT		NOT NULL,
	[SocketItem4]			BIGINT		NOT NULL,
	[SocketItem5]			BIGINT		NOT NULL,
	[SocketItem6]			BIGINT		NOT NULL,
	[HPKitItemNum]			INT			NOT NULL,
	[ShieldKitItemNum]		INT			NOT NULL,
	[ShieldKitTriggerValue]	FLOAT		NOT NULL,
	[SPKitItemNum]			INT			NOT NULL,
	[SPKitTriggerValue]		FLOAT		NOT NULL,
	[AutoSkilItemNum1]		INT			NOT NULL,
	[AutoSkilItemNum2]		INT			NOT NULL,
	[AutoSkilItemNum3]		INT			NOT NULL,
	[AutoSkilItemNum4]		INT			NOT NULL,
	[AutoSkilItemNum5]		INT			NOT NULL,
	[AutoSkilItemNum6]		INT			NOT NULL,
	[HPKitTriggerValue]		FLOAT		NOT NULL
)
GO

CREATE UNIQUE CLUSTERED INDEX idx_td_pet_ItemUID ON [dbo].[td_pet] (ItemUID)
GO

CREATE NONCLUSTERED INDEX idx_td_pet_PetIndex ON [dbo].[td_pet] (PetIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME	: dbo.atum_Log_Infinity_UserGetTenderItemInfo
-- DESC		: -- // 2010-06-25 by shcho, 인피니티 관련로그 찍기 - 습득 아이템 정보 DB저장
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_Log_Infinity_UserGetTenderItemInfo
(
	AccountUID	INT, 
	AccountName	VARCHAR(30), 
	CharacterUID	INT, 
	CharacterName	VARCHAR(30), 
	DiceCount	TINYINT, 
	ItemNum		INT 	
)

GO

--> 120619_DB스키마_(아레나 컨텐츠 리뉴얼)_DBQuery(atum2_db_[n])
--------------------------------------------------------------------------------
-- TABLE NAME:	[td_CharacterArena]
-- DESC      :	2012-05-14 by jhseol, 캐릭터 별 아레나 정보 테이블
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_CharacterArena]
(
	CharacterUID		INT		 PRIMARY KEY,		-- 캐릭터 UID
	CharacterName		VARCHAR(20),				-- 캐릭터 이름
	AccountName			VARCHAR(20),				-- 계정 이름
	AccountUID			INT,						-- 계정 UID
	PlayCount			INT		NOT NULL DEFAULT 0,	-- 아레나 플레이 횟수
	LastPlayTime		DATETIME	DEFAULT NULL	-- 마지막 아레나 플레이 시간
)
GO


--> 121013_DB스키마_(기간제아머외형)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- TABLE NAME:	td_FixedTerm
-- DESC      :	기간제 아이템 추가 정보
--				// 2012-10-10 by hskim, 기간제 속성 구현 (기간제 외형)
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_FixedTerm
(
	ItemUID			BIGINT,			-- 아이템UID
	TermType		SMALLINT,		-- 0 : 기간제 외형, 1 : 기간제 아이템
	AppliedItemNum	INT,			-- 적용된 아이템 번호
	StartDate		DATETIME,
	EndDate			DATETIME

	PRIMARY KEY (ItemUID, TermType)
)
Go

--> 121113_DB스키마_(전쟁시스템 리뉴얼 - 거점전)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_RenewalStrategyPointSummonTime
-- DESC      : 요일별 시간 및 거점 정보
-- // 2012-11-13 by jhseol, 전쟁 시스템 리뉴얼
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_RenewalStrategyPointSummonTime
(
	DayOfWeek				TINYINT PRIMARY KEY,		-- 요일
	StartTime				SMALLDATETIME,				-- 생성되면 시작 시간
	EndTime					SMALLDATETIME,				-- 생성되면 마지막 시간
	CountBCU				TINYINT,					-- BCU 세력에 생성할 거점 수
	CountANI				TINYINT						-- ANI 세력에 생성할 거점 수
)
GO
TRUNCATE TABLE dbo.td_RenewalStrategyPointSummonTime
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(0, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(1, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(2, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(3, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(4, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(5, '00:00:00', '00:00:00', 0, 0)
INSERT INTO dbo.td_RenewalStrategyPointSummonTime VALUES(6, '00:00:00', '00:00:00', 0, 0)
GO

--> 130329_DB스키마_01_(매월 첫 결재시 선물 지급)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- TABLE NAME	:	dbo.td_CashBuyDate 
-- DESC			:	// 2013-03-29 by jhseol, 아이템 이벤트 - 매월 첫 결재시 선물지급
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CashBuyDate(
	AccountUID			INT,			-- 계정 UID
	CharacterUID		INT,			-- 캐릭터 UID
	LastCashBuyDate		DATETIME		-- 최근 구매날짜
)
GO


--> 130605_DB스키마_04_(아이템추가보안)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- TABLE NAME : [td_StoreExtension]
--					// 2013-05-20 by hskim, [보안 시스템] 비정상적인 방법으로 아이템 추가 방지
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_StoreExtension]
(
	[UniqueNumber]	BIGINT	PRIMARY KEY,
	[Gesture]		BIGINT	NOT NULL
)
GO

--> 130617_DB스키마_01_(아머컬랙션)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- TABLE NAME	: [td_ShapeStatLevel]
-- DESC			: // 2013-05-31 by jhseol,bckim 아머 컬렉션
-- 아머에 적용된 컬렉션 정보를 관리할 테이블
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_ShapeStatLevel](
	[ItemKind] [tinyint] NOT NULL,
	[ItemUID] [bigint] NOT NULL,
	[ShapeItemNum] [int] NOT NULL,
	[AllStatLevel] [int] NOT NULL
) ON [PRIMARY]
GO

--------------------------------------------------------------------------------
-- TABLE NAME	: [td_Collection]
-- DESC			: // 2013-05-31 by jhseol,bckim 아머 컬렉션
-- 컬렉션 정보를 관리할 테이블 ([Type] = 1 : 아머 컬렉션)
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_Collection](
	[Type] [int] NULL,
	[AccountUID] [int] NULL,
	[CharacterUID] [int] NULL,
	[BaseItemNum] [int] NULL,
	[OptionItemNum] [int] NULL,
	[Level] [tinyInt] NULL,
	[RemainSeconds] [int] NULL,
	[MAEOptionItemNum] INT DEFAULT 0,
	[MAEDurationTime] DATETIME
) ON [PRIMARY]
CREATE CLUSTERED INDEX idx_on_CollectionAUID ON [td_Collection]([AccountUID])
GO
