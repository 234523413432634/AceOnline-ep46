-- Database 자체는 한글일 경우 Korean_Wansung_CI_AS로 설정

--------------------------------------------------------------------------------
--
-- 사용자 계정 데이타
--
-- td_Account
-- td_AccountBackup, AdminTool에서 관리하면서 제거함, 20041115, kelovon
-- td_AccountBlock
-- td_BlockedAccounts
-- td_AccountCashStore
-- td_CouponList
-- 
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_Account
-- DESC      : 사용자 계정
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Account (
	AccountUniqueNumber	INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	AccountName			VARCHAR(20)	NOT NULL,
	Password			VARCHAR(35),						-- MD5, 32 bytes 캐릭터임
	AccountType			SMALLINT	NOT NULL DEFAULT(0),	-- 관리자(128), 게임마스터(256), 모니터(512), 게스트(1024)
	Sex					TINYINT,							-- 1: 남, 2: 여
	BirthYear			INT,								-- 생년
	RegisteredDate		DATETIME	DEFAULT(GetDate()),
	LastLoginDate		DATETIME	DEFAULT(GetDate()),
	IsBlocked			TINYINT		DEFAULT(0),
	ChattingBlocked		TINYINT		DEFAULT(0),
	MGameEventType		INT			DEFAULT(0),
	ConnectingServerGroupID				INT			DEFAULT(0),			-- 2006-09-21 by cmkwon, 접속중인 정보 필드 추가
	GameContinueTimeInSecondOfToday		INT			DEFAULT(0),			-- 2006-11-15 by cmkwon, 오늘 하루 게임 진행 시간(단위:초)
	LastGameEndDate						DATETIME	DEFAULT(GetDate()),	-- 2006-11-15 by cmkwon, 마지막으로 게임을 종료한 시간(선택창은 상관없음)
	JuminNumber							VARCHAR(20),					-- 2007-06-29 by cmkwon, td_account 테이블에 주민번호저장하기 - 주민번호필드
	SecondaryPassword	VARCHAR(35)										-- // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - td_Account에 필드 추가
)
CREATE UNIQUE INDEX idx_AccountName_on_account ON td_Account(AccountName)
CREATE INDEX idx_ConnectingServerGroupID_on_account ON td_Account(ConnectingServerGroupID)	-- 2006-09-21 by cmkwon, 추가
CREATE INDEX idx_N_td_Account_JuminNumber on td_Account(JuminNumber)	-- 2007-10-01 by dhjin, 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_BlockedAccounts
-- DESC      : 압류당한 사용자 계정
--				2007-01-10 by cmkwon, 필드추가(BlockedReasonForOnlyAdmin	VARCHAR(200))
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_BlockedAccounts (
	AccountName					VARCHAR(20)		PRIMARY KEY,
	BlockedType					INT				DEFAULT(0),
	StartDate					DATETIME		DEFAULT(GetDate()),
	EndDate						DATETIME		DEFAULT(GetDate()),
	AdminAccountName			VARCHAR(20),
	BlockedReason				VARCHAR(200),							-- 유저가 보는 블럭 사유
	BlockedReasonForOnlyAdmin	VARCHAR(200)							-- 2007-01-10 by cmkwon, 관리자가 보는 블럭사유
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_AccountCashStore
-- DESC      : 유료화 카드(일반 프리미엄, 슈퍼 프리미엄)
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AccountCashStore (
	UniqueNumber			BIGINT		IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	AccountUniqueNumber		INT			NOT NULL,				-- 소유자 AccountUniqueNumber
	ItemNum					INT			NOT NULL,				-- 7010120(일반프리미엄) or 7010130(슈퍼프리미엄)
	CreatedTime				DATETIME 	DEFAULT GetDate(),		-- 아이템 생성 시간
	UpdatedTime				DATETIME 	,						-- 아이템 변경 시간(재구입 or Upgrade)
	ExpireTime				DATETIME							-- 아이템 종료 시간
)
CREATE UNIQUE INDEX idx_AccountUniqueNumber_on_accountCashStore ON td_AccountCashStore(AccountUniqueNumber)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_CouponList
-- DESC      : 쿠폰 리스트
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CouponList (
	UniqueNumber			INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	CouponNumber			VARCHAR(30)	NOT NULL,				-- 쿠폰 번호
	ExpireTime				DATETIME 	,						-- 쿠폰 유효 기간
	UsedFlag				INT			DEFAULT 0,				-- 쿠폰 사용 여부	
	UsedAccountName			VARCHAR(20)	,						-- 쿠폰 사용자 AccountName
	UsedTime				DATETIME							-- 쿠폰이 사용된 시간
)
CREATE UNIQUE INDEX idx_CouponNumber_on_CouponList ON td_CouponList(CouponNumber)
GO



--------------------------------------------------------------------------------
--
-- 게임 정보
--
-- ti_Item
-- ti_EnchantInfo
-- ti_ItemMixingInfo
-- ti_RareItemInfo
-- ti_Shop
-- ti_Monster
-- ti_MonsterItem
-- ti_MapObject
-- ti_BuildingNPC
-- ti_CityTargetWarpMap
-- ti_MapInfo
-- ti_HappyHourEvent
-- ti_InfluenceWar
--		- 2006-04-12 by cmkwon, 추가함
--------------------------------------------------------------------------------

/*
DROP TABLE ti_Item
DROP TABLE ti_EnchantInfo
DROP TABLE ti_ItemMixingInfo
DROP TABLE ti_RareItemInfo
DROP TABLE ti_Shop
DROP TABLE ti_Monster
DROP TABLE ti_MonsterItem
DROP TABLE ti_MapObject
DROP TABLE ti_BuildingNPC
DROP TABLE ti_CityTargetWarpMap
DROP TABLE ti_MapInfo
*/

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Item
-- DESC      : 아이템 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Item (
	ItemNum			INT UNIQUE,	-- 아이템고유넘버,	아이템의 고유넘버를 나타낸다.
	Kind			TINYINT,			-- 종류,			아이템의 종류를 나타낸다
	ItemName		VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다. 아이템의 이름
	AbilityMin		FLOAT,				-- 아이템최소성능,	아이템의 성능 최소값
	AbilityMax		FLOAT,				-- 아이템최대성능,	아이템의 성능 최대값
	ReqRace			SMALLINT,			-- 필요종족,		아이템사용을 위하여 필요한 종족
	ReqAttackPart	SMALLINT,			-- 필요공격파트,	아이템사용을 위하여 필요한 공격파트
	ReqDefensePart	SMALLINT,			-- 필요방어파트,	아이템사용을 위하여 필요한 방어파트
	ReqFuelPart		SMALLINT,			-- 필요연료파트,	아이템사용을 위하여 필요한 연료파트
	ReqSoulPart		SMALLINT,			-- 필요감응파트,	아이템사용을 위하여 필요한 감응파트
	ReqShieldPart	SMALLINT,			-- 필요쉴드파트,	아이템사용을 위하여 필요한 쉴드파트
	ReqDodgePart	SMALLINT,			-- 필요회피파트,	아이템사용을 위하여 필요한 회피파트
	ReqUnitKind		INT,				-- 필요유닛종류,	아이템사용을 위하여 필요한 유닛종류
	ReqMinLevel		TINYINT,			-- 필요 최저 레벨,		아이템사용을 위하여 필요한 레벨
	ReqMaxLevel		TINYINT,			-- 필요 최고 레벨,		아이템사용을 위하여 필요한 레벨
	ReqItemKind		TINYINT,			-- 필요아이템종류,	스킬에만 사용, 20040818, kelovon
	Weight			SMALLINT,			-- 무게,			아이템의 무게
	HitRate			TINYINT,			-- 명중확률,		명중 판정에 영향을 주는 값
	Defense			TINYINT,			-- 방어력,			캐릭터의 Defense에 영향을 주는 수치
	FractionResistance	TINYINT,		-- 속성저항력,		캐릭터의 속성저항력에 영향을 주는 값
	NaturalFaction	TINYINT,			-- 천적계열,		아이템에 약한 계열
	SpeedPenalty	TINYINT,			-- 스피드페널티,	아이템이 이동속도에 미치는 영향
	Range			SMALLINT,			-- 공격범위,		아이템의 공격범위
	Position		TINYINT,			-- 장착위치,		아이템 장착 위치
	Scarcity		TINYINT,			-- 희귀성,			아이템의 희귀도를 나타내는 파라미터, 아이템의 업그레이드 여부와 아이템관련 사항이 독립된 상태에서 필요한 파라미터인가 고려
	Endurance		FLOAT,				-- 내구성,			아이템의 내구도
	AbrasionRate	TINYINT,			-- 마모율,			내구도를 떨어뜨릴 수 있는 확률
	Charging		SMALLINT,			-- 장탄 수,			아이템에 포함되는 탄알 수
	Luck			TINYINT,			-- 행운,			이 아이템에 깃든 행운치
	MinTradeQuantity	SMALLINT,		-- 최소 거래 수량,	Price는 이 수량에 대한 가격이다
	Price			INT,				-- 가격,			최소 거래 수량의 가격, PriceRevision고려
	CashPrice		INT,				-- 현금 가격,		최소 거래 수량의 가격, PriceRevision고려
	DestParameter1	TINYINT,			-- 대상파라미터1,	이 아이템이 영향을 주는 캐릭터의 파라미터
	ParameterValue1	FLOAT,				-- 수정파라미터1,	대상파라미터의 값(혹은 state)을 어떻게 변화시킬 것인지를 나타내는 파라미터
	DestParameter2	TINYINT,			-- 대상파라미터2,	이 아이템이 영향을 주는 캐릭터의 파라미터
	ParameterValue2	FLOAT,				-- 수정파라미터2,	대상파라미터의 값(혹은 state)을 어떻게 변화시킬 것인지를 나타내는 파라미터
	DestParameter3	TINYINT,			-- 대상파라미터3,	이 아이템이 영향을 주는 캐릭터의 파라미터
	ParameterValue3	FLOAT,				-- 수정파라미터3,	대상파라미터의 값(혹은 state)을 어떻게 변화시킬 것인지를 나타내는 파라미터
	DestParameter4	TINYINT,			-- 대상파라미터4,	이 아이템이 영향을 주는 캐릭터의 파라미터
	ParameterValue4	FLOAT,				-- 수정파라미터4,	대상파라미터의 값(혹은 state)을 어떻게 변화시킬 것인지를 나타내는 파라미터
	ReAttacktime	INT,				-- 재 공격시간,		재 공격을 하기 위해 필요한 시간
	Time			INT,				-- 지속 시간,			아이템의 효과가 얼마나 지속되지를 나타냄
	RepeatTime		SMALLINT,			-- 사용횟수,		아이템의 사용 제한 횟수
	Material		SMALLINT,			-- 재질,			이 아이템의 재료
	ReqMaterial		SMALLINT,			-- 필요한 재질 수,	제조를 위하여 필요한 재질의 수를 나타냄
	RangeAngle		FLOAT,				-- 범위각도,		범위의 각도를 나타낸다.
	UpgradeNum		TINYINT,			-- 업그레이드 수,	업그레이드의 한계를 나타냄.
	LinkItem		INT,				-- 링크아이템,		아이템과 연관된 아이템 (총알)
	MultiTarget		TINYINT,			-- 다중타켓,		동시에 잡을 수 있는 타켓의 수
	ExplosionRange	SMALLINT,			-- 폭발반경,		폭발 시 데미지의 영향이 미치는 반경
	ReactionRange	SMALLINT,			-- 반응반경,		마인 등이 반응하는 반경
	ShotNum			TINYINT,			-- 점사 수,			점사 시 발사 수를 나타낸다.
	MultiNum		TINYINT,			-- 동시 발사 탄 수,	1번 발사에 몇발이 동시에 나가느냐
	AttackTime		SMALLINT,			-- 공격시간,	공격을 하기 위해 필요한 시간
	ReqSP			TINYINT,			-- SP 소모량(스킬)
	SummonMonster	INT,				-- 소환몬스터(스킬)
	NextSkill		INT,				-- 스킬요구 레벨(스킬), 여기서는 제거하고 store에서만 관리함, 12
	SkillLevel		TINYINT,			-- 레벨
	SkillHitRate	TINYINT,			-- 스킬명중확률
	SkillType		TINYINT,			-- 스킬형태
	SkillTargetType	TINYINT,			-- 스킬타겟타입
	Caliber			TINYINT,			-- 구경(총알, 탄두 등)
	OrbitType		TINYINT,			-- 미사일, 로켓 등의 궤적
	ItemAttribute	INT,				-- 아이템의 속성, 일반 몬스터에서 떨어지는 아이템이냐? 혹은 quest용 아이템이냐? 거래&이동 불가냐? 등등
	BoosterAngle	FLOAT,				-- 부스터시에 유닛의 회전각, 현재는 엔진에만 사용
	CameraPattern	INT,				-- 카메라 패턴
	SourceIndex		INT,				-- 아이템의 리소스 소스, 2005-08-22 by cmkwon
	Description		VARCHAR(200) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다. 아이템 설명
)
GO
CREATE UNIQUE CLUSTERED INDEX idx_on_Item ON ti_Item(Kind, ItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_EnchantInfo
-- DESC      : Enchant 관련 정보
-- 2005-08-02 by cmkwon, 인챈트 최대 9개에서 40개로 늘림
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_EnchantInfo (
	EnchantItemNum			INT	NOT NULL	-- enchant로 쓰인 아이템의 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	EnchantItemCount		INT	NOT NULL,	-- 필요한 개수
	EnchantCost				INT NOT NULL,	-- 재료 조합을 위한 수수료
	Prob1					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob2					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob3					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob4					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob5					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob6					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob7					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob8					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob9					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob10					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob11					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob12					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob13					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob14					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob15					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob16					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob17					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob18					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob19					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob20					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob21					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob22					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob23					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob24					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob25					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob26					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob27					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob28					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob29					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob30					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob31					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob32					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob33					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob34					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob35					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob36					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob37					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob38					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob39					INT	NOT NULL DEFAULT(0),	-- 현 단계 인챈트 시 조합될 확률(1~10000)
	Prob40					INT	NOT NULL DEFAULT(0)		-- 현 단계 인챈트 시 조합될 확률(1~10000)
)
CREATE CLUSTERED INDEX idx_on_EnchantInfo ON ti_EnchantInfo(EnchantItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_ItemMixingInfo
-- DESC      : 아이템 조합 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemMixingInfo (
	TargetItemNum			INT NOT NULL	-- 완성된 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	MixingProbability		INT	NOT NULL,	-- 제작될 확률(1~10000)
	MixingCost				INT	NOT NULL,	-- 재료 조합을 위한 수수료
	SourceItemNum1			INT	NOT NULL				-- 필요한 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount1		INT	NOT NULL,				-- 필요한 개수
	SourceItemNum2			INT	NOT NULL DEFAULT(0)		-- 필요한 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount2		INT	NOT NULL DEFAULT(0),	-- 필요한 개수
	SourceItemNum3			INT	NOT NULL DEFAULT(0)		-- 필요한 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount3		INT	NOT NULL DEFAULT(0),	-- 필요한 개수
	SourceItemNum4			INT	NOT NULL DEFAULT(0)		-- 필요한 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount4		INT	NOT NULL DEFAULT(0),	-- 필요한 개수
	SourceItemNum5			INT	NOT NULL DEFAULT(0)		-- 필요한 재료 ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount5		INT	NOT NULL DEFAULT(0)		-- 필요한 개수
)
CREATE UNIQUE CLUSTERED INDEX idx_on_ItemMixingInfo
	ON ti_ItemMixingInfo(TargetItemNum, SourceItemNum1, SourceItemNum2,
						SourceItemNum3, SourceItemNum4, SourceItemNum5)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_RareItemInfo
-- DESC      : 레어 아이템을 만들기 위한 suffix 혹은 prefix의 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_RareItemInfo
(
	CodeNum				INT,		-- 접두사, 접미사 구분됨
	Name				VARCHAR(21) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다., 12->21로 변경함
	ReqUseType			INT DEFAULT(1),					-- 2005-04-04 by cmkwon
	ReqMinLevel			INT,
	ReqMaxLevel			INT,
	ReqItemKind			TINYINT,
	ReqAttackPart		SMALLINT,	-- 공격 파트
	ReqDefensePart		SMALLINT,	-- 방어 파트
	ReqDodgePart		SMALLINT,	-- 회피 파트
	ReqFuelPart			SMALLINT,	-- 연료 파트
	ReqShieldPart		SMALLINT,	-- 쉴드 파트
	ReqSoulPart			SMALLINT,	-- 감응 파트
	DesParameter1		TINYINT,
	ParameterValue1		FLOAT,
	DesParameter2		TINYINT,
	ParameterValue2		FLOAT,
	DesParameter3		TINYINT,
	ParameterValue3		FLOAT,
	DesParameter4		TINYINT,
	ParameterValue4		FLOAT,
	DesParameter5		TINYINT,
	ParameterValue5		FLOAT,
	DesParameter6		TINYINT,
	ParameterValue6		FLOAT,
	DesParameter7		TINYINT,
	ParameterValue7		FLOAT,
	DesParameter8		TINYINT,
	ParameterValue8		FLOAT,
	DesParameter9		TINYINT,
	ParameterValue9		FLOAT,
	Probability			INT			-- 성공 확률, 범위: 1 ~ 100000
)
CREATE UNIQUE CLUSTERED INDEX idx_CodeNum_on_RareItemInfo ON ti_RareItemInfo(CodeNum)		-- 2005-10-19 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Shop
-- DESC      : 도시와 연결된 상점과 거기서 파는 아이템
-- 2007-08-10 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Shop (
	ShopOrder			INT,		-- 2007-08-10 by dhjin, 상점 리스트 순서를 위해 추가함
	UniqueNumber		INT,		-- UINT, 앞 4자리(NPCTalkIndex), 뒤 4자리(건물 분류)
	ItemNum				INT			-- UINT
		--REFERENCES ti_Item(ItemNum)
)
CREATE UNIQUE CLUSTERED INDEX idx_ShopOrder_on_ti_Shop ON ti_Shop(ShopOrder)		-- 2007-08-10 by dhjin
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Monster
-- DESC      : 몬스터 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Monster (
	UniqueNumber		INT		PRIMARY KEY,
	MonsterName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.
	Level				TINYINT,
	Experience			BIGINT,
	HP					INT,
	Race				SMALLINT,	-- USHORT
	Speed				TINYINT,
	MonsterItem01		INT
		--REFERENCES ti_Item(ItemNum)
		,
	MonsterItem02		INT
		--REFERENCES ti_Item(ItemNum)
		,
	MonsterItem03		INT
		--REFERENCES ti_Item(ItemNum)
		,
	MonsterItem04		INT
		--REFERENCES ti_Item(ItemNum)
		,
	MonsterItem05		INT
		--REFERENCES ti_Item(ItemNum)
		,
	ControlSkill		INT
		--REFERENCES ti_Item(ItemNum)
		,
	SizeForServer		INT, -- USHORT로 사용
	SizeForClient		INT, -- USHORT로 사용, 기존의 size에서 변경
	Faction				TINYINT,
	MonsterForm			SMALLINT,
	AttackPattern		TINYINT,
	MovePattern			SMALLINT,
	Belligerence		TINYINT,
	Defense				TINYINT,
	DefenceProbability	TINYINT,
	AlphaBlending		TINYINT,
	AttackObject		TINYINT,
	AttackRange			SMALLINT,				-- 2005-02-01 by cmkwon, 공격성향 몬스터가 타겟팅하는 거리
	HPRecoveryTime		SMALLINT,
	HPRecoveryValue		SMALLINT,
	RenderIndex			SMALLINT,
	ScaleValue			FLOAT,
	TextureIndex		TINYINT,
	SourceIndex			INT,
	QuickTurnAngle		TINYINT,
	QuickSpeed			TINYINT,
	QuickTurnTerm		SMALLINT,
	MPOption			TINYINT,
	MPOptionParam1		TINYINT,
	MPOptionParam2		TINYINT,
	Range				SMALLINT,
	TurnAngle			FLOAT,
	MonsterHabit		TINYINT,
	ClickEvent			TINYINT				-- 2007-09-12 by dhjin
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_MonsterItem
-- DESC      : 몬스터가 죽었을 때 떨어뜨리는 아이템의 개수 및 그 확률
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MonsterItem (
	MonsterUniqueNumber	INT,	--REFERENCES ti_Monster(UniqueNumber),	-- 몬스터 종류
	ItemNum				INT,	--REFERENCES ti_Item(ItemNum),			-- 아이템고유넘버
	MinCount			INT,	-- 생성할 아이템의 최소 개수
	MaxCount			INT,	-- 생성할 아이템의 최대 개수, 만약 개수가 정해져 있다면 MinCount = MixCount
	Probability			INT,	-- 생성 확률: 0 ~ 1000000
	PrefixProbability	INT,		-- 접두사가 붙을 확률, 0 ~ 100000
	SuffixProbability	INT,		-- 접미사가 붙을 확률, 0 ~ 100000
)
CREATE UNIQUE CLUSTERED INDEX idx_monsteritem ON ti_MonsterItem(monsteruniquenumber, itemnum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_MapObject
-- DESC      : 관리용, Map Object에 대한 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MapObject (
	ObjectName				VARCHAR(50) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.
	Code					INT,
	Alpha					TINYINT,		-- 1(TRUE), 0(FALSE)
	RadiusForServer			INT,			-- USHORT
	RadiusForClient			INT,			-- USHORT, 기존의 Radius에서 변경
	Collision				TINYINT,		-- 1(TRUE), 0(FALSE)
	CollisionForServer		TINYINT,		-- 1(TRUE), 0(FALSE)
	RenderIndex				SMALLINT,		-- USHORT
	ObjectRenderType		TINYINT,
	ObjectDescription		VARCHAR(250) COLLATE Korean_Wansung_CI_AS	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_BuildingNPC
-- DESC      : 각 빌딩 및 담당 NPC의 정보	  
--				// 2008-01-03 by cmkwon, BuildingName 필드 40Bytes 로 수정 - 수정(<--20)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_BuildingNPC (
	BuildingIndex			INT,			-- 건물(가게 등) 고유 번호
	BuildingName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다., 상점 이름
	BuildingKind			TINYINT,		-- 건물 종류, ex)무기 상점, 부품 상점, ...
	MapIndex				SMALLINT,		-- 속해 있는 맵의 Index, ex)0101, 0102
	NPCIndex				INT,			-- 담당 NPC
	NPCName					VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.
	GreetingTalk			VARCHAR(400) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다., 인사말
	OwnerCityMapIndex		INT,			-- 이 상점을 소유한 도시맵의 맵인덱스
	OwnerOrderNumber		INT				-- 필드 상점의 점령순서
)
GO
CREATE CLUSTERED INDEX idx_BuildingNPC ON ti_BuildingNPC(MapIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_CityTargetWarpMap
-- DESC      : 도시에서 워프해 나갈 수 있는 맵의 리스트
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_CityTargetWarpMap (
	MapIndex				INT,
	BuildingIndex			INT,
	WarpTargetMapIndex		INT,
	WarpTargetIndex			INT,
	WarpTargetName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.
	Fee						INT				-- 워프 요금
)
GO
-- 2007-02-05 by cmkwon, 아래와 같이 수정함
--CREATE UNIQUE CLUSTERED INDEX idx_CityTargetWarpMap ON ti_CityTargetWarpMap(MapIndex, WarpTargetMapIndex, WarpTargetIndex)
CREATE CLUSTERED INDEX idx_MapIndex_on_CityTargetWarpMap ON ti_CityTargetWarpMap(MapIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_MapInfo
-- DESC      : 맵 정보		   
--				// 2008-01-03 by cmkwon, MapName 필드 40Bytes 로 수정 - 수정(<--30)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MapInfo(
	MapIndex				INT PRIMARY KEY,
	RenderMapIndex			INT,				-- Render 정보 원본 맵인덱스, 2005-07-12 by cmkwon
	BeforeMapIndex			INT,				-- 2006-08-02 by cmkwon, 타세력맵에서 죽었을 경우 부활시 여기에 설정된 맵에서 부활됨
	MapName					VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다., 맵이름
	MapInfluenceType		SMALLINT,			-- 2005-12-26 by cmkwon, 맵의 세력 설정(0=중립, 1000~1999=바이제니유, 2000~2999=알링턴)
	CityMapIndex			INT,				-- 도시점령전 맵에만 설정됨
	CityWarQuestIndex		INT,				-- 도시점령전 맵에만 설정됨
	CityWarQuestNPCIndex	INT,				-- 도시점령전 맵에만 설정됨
	CityWarQuestMonsterUID	INT,				-- 도시점령전 맵에만 설정됨
	MaxUserCount			SMALLINT,
	MaxGroundHeight			SMALLINT,
	MinGroundHeight			SMALLINT,
	WaterHeight				SMALLINT,
	UserVisibleDistance		SMALLINT,
	MonsterVisibleDistance	SMALLINT,
	QuestIndexForWarp		INT,
	FrontPositionDistance	SMALLINT,
	AutoRecoveryFlag		TINYINT,
	DefaultMapIndex			INT,
	CityWarpTargetPositionX	smallint,
	CityWarpTargetPositionY	smallint,
	CityWarpTargetPositionZ	smallint,
	ClientMaxAltitudeHeight	smallint,			-- 클라이언트 이동 가능 최대 높이, 2005-07-11 by cmkwon
	DayFogColor				int,
	NightFogColor			int,
	DayFogStartDistance		smallint,
	DayFogEndDistance		smallint,
	NightFogStartDistance	smallint,
	NightFogEndDistance		smallint,
	DaySunDirectionX		smallint,
	DaySunDirectionY		smallint,
	DaySunDirectionZ		smallint,
	NightSunDirectionX		smallint,
	NightSunDirectionY		smallint,
	NightSunDirectionZ		smallint,
	WaterType				tinyint,
	PKZoneFlag				tinyint,
	TileRenderingFlag		tinyint,
	SkyRenderingFlag		tinyint,
	SunRenderingFlag		tinyint,
	FogRenderingFlag		tinyint,
	VCNWarpObjectIndex		INT		DEFAULT(0),		-- 2006-12-08 by cmkwon
	ANIWarpObjectIndex		INT		DEFAULT(0),		-- 2006-12-08 by cmkwon
	dat						INT,				-- 2007-03-14 by dhjin
	map						INT,				-- 2007-03-14 by dhjin
	tex						INT,				-- 2007-03-14 by dhjin
	cloud					INT,				-- 2007-03-14 by dhjin
	sky						INT,				-- 2007-03-14 by dhjin
	nsky					INT,				-- 2007-03-14 by dhjin
	bgm						INT,				-- 2007-03-14 by dhjin
	TeleportWarpObjectIndex	INT,				-- 2007-09-12 by dhjin
	BeforeMapIndex2			INT					-- // 2008-06-20 by cmkwon, EP3 백맵 시스템 수정(맵당 백맵이 2개 설정 할 수 있다) - ti_mapInfo 테이블에 필드 추가
	)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: ti_HappyHourEvent
-- DESC      : 쿠폰 리스트
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_HappyHourEvent(
	UniqueNumber			INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	ServerGroupID			INT 		DEFAULT(0),				-- 0(=AllServerGroup), 1(=10061), 2(10062), ...
	DayOfWeek				INT 		NOT NULL,				-- 요일	- 일(0) 월(1) 화(2) 수(3) 목(4) 금(5) 토(6) HappyHourEvent기간(7) PCBangHappyHourEvent기간및설정(8)
	StartTime				DATETIME	NOT NULL,				-- 시작 시간(DayOfWeek=7 일때에만 년월일이 사용됨)
	EndTime					DATETIME 	NOT NULL,				-- 종료 시간(DayOfWeek=7 일때에만 년월일이 사용됨)
	EXPRate					FLOAT,								-- 경험치 이벤트 Rate
	SPIRate					FLOAT,								-- 스피 이벤트 Rate
	EXPRepairRate			FLOAT,								-- 경험치 복구 이벤트 Rate
	DropItemRate			FLOAT,								-- 아이템 드롭 Rate
	DropRareItemRate		FLOAT,								-- 레어 아이템 드롭 Rate
	WarPointRate			FLOAT,								-- 2007-06-27 by dhjin, WarPoint 이벤트 Rate
	InfluenceType			TINYINT,							-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - ti_HappyHourEvent 테이블에 필드 추가
	MinLevel				INT,
	MaxLevel				INT									
)
CREATE INDEX idx_DayOfWeek_on_HappyHourEvent ON ti_HappyHourEvent(DayOfWeek)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfluenceWar - 2006-04-12 by cmkwon
-- DESC      : 세력전 설정 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfluenceWar(
	InfluenceType				TINYINT		NOT NULL,		-- INFLUENCE_TYPE_VCN(2) or INFLUENCE_TYPE_ANI(4)
	WartimeStage				TINYINT		NOT NULL,		-- 전시단계(0, 1, 2, 3, 4,...10)
	ReqContributionPoint		INT			NOT NULL,		-- 전시단계가 되기 위한 필요 기여도(ContributionPoint)
	HPRepairRate				FLOAT,			-- 해당 전시단계 일 때 HP회복률
	DPRepairRate				FLOAT,			-- 해당 전시단계 일 때 DP회복률
	SPRepairRate				FLOAT,			-- 해당 전시단계 일 때 SP회복률
	EventTime					INT,			-- 
	EventExperience				FLOAT,			-- 
	EventDropSPI				FLOAT,			-- 
	EventDownExperience			FLOAT,			-- 
	EventDropItem				FLOAT,			-- 
	EventDropRareItem			FLOAT,			-- 
	SupplyItemNum				INT,			-- 
	SupplyItemCount				INT,			-- 
	IsSummonJacoMonster			TINYINT,		-- 해당 전시단계로 될때 자코몬스터 소환 플래그
	BossMonsterUnitKind			INT,	
	BossMonsterCount			INT,		
	BossMonsterSummonTerm		INT,	
	BossMonsterSummonMapIndex	SMALLINT,
	BossMonsterSummonPositionX	SMALLINT,
	BossMonsterSummonPositionY	SMALLINT,
	BossMonsterSummonPositionZ	SMALLINT,

	SummonMonsterUnitKind1		INT,
	SummonCount1				INT,
	SummonMapIndex1				SMALLINT,
	SummonPositionX1			SMALLINT,
	SummonPositionY1			SMALLINT,
	SummonPositionZ1			SMALLINT,
	SummonMonsterUnitKind2		INT,
	SummonCount2				INT,
	SummonMapIndex2				SMALLINT,
	SummonPositionX2			SMALLINT,
	SummonPositionY2			SMALLINT,
	SummonPositionZ2			SMALLINT,
	SummonMonsterUnitKind3		INT,
	SummonCount3				INT,
	SummonMapIndex3				SMALLINT,
	SummonPositionX3			SMALLINT,
	SummonPositionY3			SMALLINT,
	SummonPositionZ3			SMALLINT,
	SummonMonsterUnitKind4		INT,
	SummonCount4				INT,
	SummonMapIndex4				SMALLINT,
	SummonPositionX4			SMALLINT,
	SummonPositionY4			SMALLINT,
	SummonPositionZ4			SMALLINT,
	SummonMonsterUnitKind5		INT,
	SummonCount5				INT,
	SummonMapIndex5				SMALLINT,
	SummonPositionX5			SMALLINT,
	SummonPositionY5			SMALLINT,
	SummonPositionZ5			SMALLINT,
	SupplyItemNum2				INT,
	SupplyItemCount2			INT
)
CREATE UNIQUE CLUSTERED  INDEX idx_InfluenceType8WarTimeStage_on_InfluenceWar ON ti_InfluenceWar(InfluenceType, WarTimeStage)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: ti_MysteryItemDrop
-- DESC      : 2007-05-11 by cmkwon, 미스테리캡슐이 아이템을 드랍 할 때 드랍할 아이템 리스트
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MysteryItemDrop(
	MysteryItemDropNum		INT			NOT NULL,	-- 구분 번호, 중복 가능
	ReqUnitKind				INT,					-- 필요유닛종류,	아이템사용을 위하여 필요한 유닛종류
	ReqMinLevel				TINYINT,				-- 필요 최저 레벨,		아이템사용을 위하여 필요한 레벨
	ReqMaxLevel				TINYINT,				-- 필요 최고 레벨,		아이템사용을 위하여 필요한 레벨
	DropItemNum				INT,					-- 
	MinCount				INT,					-- 생성할 아이템의 최소 개수
	MaxCount				INT,					-- 생성할 아이템의 최대 개수, 만약 개수가 정해져 있다면 MinCount = MixCount
	Probability				INT,					-- 생성 확률(상대값으로 처리): 0 ~ 1000000
	PrefixProbability		INT,					-- 접두사가 붙을 확률, 0 ~ 100000
	SuffixProbability		INT						-- 접미사가 붙을 확률, 0 ~ 100000
)
CREATE CLUSTERED INDEX idx_MysteryItemDropNum_on_MysteryItemDrop ON ti_MysteryItemDrop(MysteryItemDropNum)
GO

--------------------------------------------------------------------------------
--
-- VIEWs
--
-- ItemCharacterView
-- ItemSkillView
-- ItemMonsterView
--
--------------------------------------------------------------------------------
DROP VIEW ItemCharacterView
GO
CREATE VIEW dbo.ItemCharacterView
AS
	SELECT *
	FROM ti_Item
	WHERE Kind <= 49
GO

DROP VIEW ItemSkillView
GO
CREATE VIEW dbo.ItemSkillView
AS
	SELECT *
	FROM ti_Item
	WHERE Kind >= 50 AND Kind <= 99
GO

DROP VIEW ItemMonsterView
GO
CREATE VIEW dbo.ItemMonsterView
AS
	SELECT *
	FROM ti_Item
	WHERE Kind >= 100
GO


--------------------------------------------------------------------------------
-- 
-- 로그 관련
--
--------------------------------------------------------------------------------
/*
select i.LogStringEN, i.LogStringKO, l.*
from atum_log_type_info i, atum_log_connection l
where i.logtype = l.logtype
order by time

delete from atum_log_connection

drop table atum_log_connection
*/

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
INSERT INTO atum_log_type_info VALUES(0x00, 'LOGIN', 'LOGIN')
INSERT INTO atum_log_type_info VALUES(0x01, 'LOGOUT', 'LOGOUT')
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_connection
-- DESC      : 1 - Connection Log
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_connection (
	LogType						TINYINT,
	Time						DATETIME,
	IPAddress					BINARY(4),
	AccountUniqueNumber			INT,		-- UINT
	AccountName					VARCHAR(20),
	ServerName					VARCHAR(20)
)
GO
CREATE CLUSTERED INDEX idx_atum_log_connection ON atum_log_connection (Time)
CREATE INDEX idx_AccountUniqueNumber_On_log_connection ON atum_log_connection(AccountUniqueNumber)	-- 2005-03-08 by cmkwon
CREATE INDEX idx_AccountName_On_log_connection ON atum_log_connection(AccountName)					-- 2005-03-08 by cmkwon	
GO


--------------------------------------------------------------------------------
-- 2005-01-10 7:08오후
-- TABLE NAME: atum_log_total_user
-- DESC      : 2 - total user count
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_total_user (	
	Time						DATETIME,
	ServerGroupName				VARCHAR(20),
	MGameServerID				INT,
	UserCount					INT
)
GO
CREATE CLUSTERED INDEX idx_atum_log_total_user ON atum_log_total_user (Time)
CREATE INDEX idx_ServerGroupName_On_log_total_user ON atum_log_total_user(ServerGroupName)			-- 2005-03-08 by cmkwon
CREATE INDEX idx_MGameServerID_On_log_total_user ON atum_log_total_user(MGameServerID)				-- 2005-03-08 by cmkwon
GO






--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
-- Account DB atum_back_log_X 테이블 만들기
-- 이 아래 테이블도 항상 존재 해야한다
--------------------------------------------------------------------------------
SELECT * INTO dbo.atum_backup_log_connection			FROM dbo.atum_log_connection		-- 1
SELECT * INTO dbo.atum_backup_log_total_user			FROM dbo.atum_log_total_user		-- 2
GO

--------------------------------------------------------------------------------
-- 2006-08-24 11:55오전   by dhjin
-- TABLE NAME: ti_ItemEvent
-- DESC      : 이벤트 아이템 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemEvent (
	ItemEventUID    int        IDENTITY(1,1) PRIMARY KEY,
	ItemEventType   smallint,
	OnlyPCBang      smallint,
	InfluenceType   tinyint,
	ItemNum         int,
	Count            int,
	StartTime        datetime,
	EndTime         datetime,
	MemberShip		bit,
	ReqLevel		TINYINT,			-- 2007-07-23 by dhjin, 레벨업시 이벤트  
	NewMember		BIT,				-- 2007-07-23 by dhjin, 이벤트 기간 안에 신규 가입한 유저 대상
	UnitKind		INT,     			-- 2007-07-24 by dhjin, 아이템 지급 유닛
	PrefixCodeNum	INT,				-- 2007-07-25 by dhjin, 아이템 지급 접두 옵션
	SuffixCodeNum   INT,				-- 2007-07-25 by dhjin, 아이템 지급 접미 옵션
	UseLastGameEndDate	INT,			-- // 2008-02-01 by cmkwon, ItemEvent 에 LastGameEndDate 체크 루틴 추가 - 
	LastGameEndDate		DATETIME		-- // 2008-02-01 by cmkwon, ItemEvent 에 LastGameEndDate 체크 루틴 추가 - 
)
GO

--------------------------------------------------------------------------------
-- 2006-08-24 11:55오전   by dhjin
-- TABLE NAME: atum_Log_ItemEvent
-- DESC      : 이벤트 아이템 받은 유저 정보
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_Log_ItemEvent (
	AccountUID                int,
	CharacterUID               int,
	ItemEventUID               int,
	GetTime                   datetime
)
CREATE CLUSTERED INDEX idx_atum_Log_ItemEvent_GetTime ON atum_Log_ItemEvent (GetTime)
CREATE INDEX idx_atum_Log_ItemEvent_AccountUID_ItemEventUID ON atum_Log_ItemEvent (AccountUID, ItemEventUID) 
GO

CREATE TABLE dbo.td_PCBang (
	UID					INT				NOT NULL,				-- 2007-01-19 by dhjin, PC방 IP UniqueNumber
	ST_IP				VARCHAR(20)		NOT NULL,				-- 2007-01-19 by dhjin, PC방 시작 IP
	ED_IP				VARCHAR(4),								-- 2007-01-19 by dhjin, PC방 끝 IP
	User_Id				VARCHAR(15)		NOT NULL,				-- 2007-01-19 by dhjin, PC방 업주 ID
	Branch_Name			NVARCHAR(50)	NOT NULL,				-- 2007-01-19 by dhjin, PC방 상호명
	Branch_RegNO		VARCHAR(12)		NOT NULL,				-- 2007-01-19 by dhjin, PC방 사업등록번호
	Branch_Tel			VARCHAR(14)		NOT NULL,				-- 2007-01-19 by dhjin, PC방 전화번호
	ZipCode				CHAR(15)		NOT NULL,				-- 2007-01-19 by dhjin, PC방 우편번호
	Addr_Sido			NVARCHAR(10)	NOT NULL,				-- 2007-01-19 by dhjin, PC방 주소 시
	Addr_SiGuGun		NVARCHAR(20)	NOT NULL,				-- 2007-01-19 by dhjin, PC방 주소 구
	Addr_Dong			NVARCHAR(100)	NOT NULL,				-- 2007-01-19 by dhjin, PC방 주소 동
	Addr_Detail			NVARCHAR(50),							-- 2007-01-19 by dhjin, PC방 상세주소
	User_Level			TINYINT			DEFAULT(0)				-- 2007-06-25 by dhjin, PC방 등급 추가
)
CREATE CLUSTERED INDEX idx_UID_on_td_PCBang ON td_PCBang(UID)
CREATE INDEX idx_Branch_Name_on_td_PCBang ON td_PCBang(Branch_Name)
CREATE INDEX idx_Addr_Sido_on_td_PCBang ON td_PCBang(Addr_Sido)
CREATE INDEX idx_Addr_SiGuGun_on_td_PCBang ON td_PCBang(Addr_SiGuGun)
CREATE INDEX idx_Addr_Dong_on_td_PCBang ON td_PCBang(Addr_Dong)
GO

	
--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_integration
-- DESC      : 2007-01-26 by cmkwon, 추가함 - 서버 통합, 이전 관련 로그
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_integration (
	LogType						TINYINT,
	Time						DATETIME,
	AccountName					VARCHAR(20),			-- 2007-01-29 by cmkwon, 추가함
	AccountUID					INT,					-- 2007-01-29 by cmkwon, 추가함
	SourceDBNum					INT,
	SourceCharacterUID			INT,
	SourceCharacterName			VARCHAR(20),
	TargetDBNum					INT,
	TargetCharacterUID			INT,
	TargetCharacterName			VARCHAR(20)
)
CREATE CLUSTERED INDEX idx_Time_on_atum_log_integration ON atum_log_integration (Time)
CREATE INDEX idx_LogType_on_atum_log_integration ON atum_log_integration(LogType)
CREATE INDEX idx_AccountName_on_atum_log_integration ON atum_log_integration(AccountName)					-- 2007-01-29 by cmkwon, 추가함
CREATE INDEX idx_AccountUID_on_atum_log_integration ON atum_log_integration(AccountUID)						-- 2007-01-29 by cmkwon, 추가함
CREATE INDEX idx_SourceCharacterUID_on_atum_log_integration ON atum_log_integration(SourceCharacterUID)
CREATE INDEX idx_SourceCharacterName_on_atum_log_integration ON atum_log_integration(SourceCharacterName)
CREATE INDEX idx_TargetCharacterUID_on_atum_log_integration ON atum_log_integration(TargetCharacterUID)
CREATE INDEX idx_TargetCharacterName_on_atum_log_integration ON atum_log_integration(TargetCharacterName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_StrategyPointSummonMapIndex
-- DESC      : 전략포인트 생성 맵 정보
-- 2007-02-26 by dhjin,
--				-- // 2008-01-03 by cmkwon, MapName 필드 40Bytes 로 수정 - 수정(<--30)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_StrategyPointSummonMapIndex
(
	MapName				VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, 한글 완성형으로 설정한다.	
	MapIndex			INT PRIMARY KEY,
	StratrgyPiontNum	INT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonRange
-- DESC      : 전략포인트 생성 주기
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonRange
(
	SummonRange		SMALLINT,			-- 생성 주기 (단위 : 일)
	StrategyPointSummonCheck TINYINT, -- 전략포인트 생성 체크값 (0: 생성하지 않는다, 1: 생성)
	MaxSummonCountDaily  TINYINT,        -- 하루에 전략포인트 생성 가능한 수
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointNotSummonTime
-- DESC      : 전략포인트가 생성되면 안되는 요일별 시간 정보
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointNotSummonTime
(
	DayOfWeek				SMALLINT PRIMARY KEY,		-- 요일
	StartTime				SMALLDATETIME,				-- 생성되면 안되는 시작 시간
	EndTime					SMALLDATETIME,				-- 생성되면 안되는 마지막 시간
	CheckSummon				TINYINT						--// 2008-04-04 by dhjin, 소환 가능 시간 설정 - 0:금지시간 , 1:소환시간
)
GO
TRUNCATE TABLE dbo.td_StrategyPointNotSummonTime
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(0, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(1, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(2, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(3, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(4, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(5, '00:00:00', '00:00:00', 0)
INSERT INTO dbo.td_StrategyPointNotSummonTime VALUES(6, '00:00:00', '00:00:00', 0)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ArenaInfo
-- DESC      : 아레나 정보
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ArenaInfo(
 ArenaMode		TINYINT,			-- 아레나 모드 0 : DeathMatch, 1 : Round
 ReqMemberNum	TINYINT,			-- 팀 인원 제한 
 PayInfluencePointWIN 	INT,			-- 승리 세력에게 보상되는 세력포인트값
 PayInfluencePointLOSE	INT,			-- 패배 세력에게 보상되는 세력포인트값
 PayWarPointWIN	INT,			-- 승리 팀에게 보상되는 WP값
 PayWarPointLOSE	INT			-- 패배 팀에게 보상되는 WP값
)
CREATE CLUSTERED INDEX idx_ArenaMode_on_ArenaInfo ON ti_ArenaInfo(ArenaMode)
CREATE INDEX idx_ReqMemberNum_on_ArenaInfo ON ti_ArenaInfo(ReqMemberNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ArenaMapinfo
-- DESC      : 아레나 맵 정보
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ArenaMapinfo(
 ArenaMapIndex	INT,				-- dbo.ti_MapInfo(MapIndex)에 존재해야 한다.
 ArenaMode		TINYINT,			-- 아레나 모드 0 : DeathMatch, 1 : Round
 ReqMemberNum 	TINYINT , 			-- dbo.ti_ArenaInfo(ReqMemberNum)에 존재해야 한다.
 PlayLimitedTime	TINYINT,		-- 데스매치 경기 제한 시간
 WINCondition		TINYINT,		-- 데스매치 경기 승리 조건
 LvDSupplyItemNum1		INT,		-- 아레나 전용 아이템 1                        
 LvDSupplyItemCount1	INT,        -- 아레나 전용 아이템 1 수                     
 LvDSupplyItemNum2		INT,        -- 아레나 전용 아이템 2                        
 LvDSupplyItemCount2	INT,        -- 아레나 전용 아이템 2 수                      
 LvDSupplyItemNum3		INT,        -- 아레나 전용 아이템 3                        
 LvDSupplyItemCount3	INT         -- 아레나 전용 아이템 3 수 
)
CREATE CLUSTERED INDEX idx_ArenaMapIndex_on_ArenaMapinfo ON ti_ArenaMapinfo(ArenaMapIndex)
CREATE INDEX idx_ReqMemberNum_on_ArenaMapinfo ON ti_ArenaMapinfo(ReqMemberNum)
CREATE INDEX idx_ArenaMode_on_ArenaMapinfo ON ti_ArenaMapinfo(ArenaMode)
GO

 CREATE TABLE dbo.ti_TutorialInfo(
   TutorialUID             	 INT, 			-- 튜토리얼 UID
   TutorialPayItem1       	 INT,			-- 튜토리얼 지급 아이템1
   TutorialPayItemCount1     INT,			-- 튜토리얼 지급 아이템 수 1
   TutorialPayItem2     	 INT,			-- 튜토리얼 지급 아이템2
   TutorialPayItemCount2	 INT,			-- 튜토리얼 지급 아이템 수 2  
   TutorialPayItem3      	 INT,			-- 튜토리얼 지급 아이템3
   TutorialPayItemCount3     INT			-- 튜토리얼 지급 아이템 수 3
)
CREATE CLUSTERED INDEX idx_TutorialUID_on_TutorialInfo ON ti_TutorialInfo(TutorialUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_OutPostNextWarTime
-- DESC		 : 전진기지 다음 시간 설정
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_OutPostNextWarTime
(
	OutPostWarStartTime		DATETIME		-- 전진기지 전 시작 시간 설정 (주의: 끝나는 시간은 2시간 뒤이다)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ActionByLevel
-- DESC		 : 레벨에 따른 여러 행위들
-- 2007-10-16 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ActionByLevel
(
	Level		TINYINT		PRIMARY KEY,	-- Level
	PollPoint	INT							-- Poll점수
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_PollDate
-- DESC		 : 투표 기간
-- 2007-10-23 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_PollDate
(
	ApplicationStartDate	datetime,		-- 후보 신청 시작 
	ApplicationEndDate		datetime,		-- 후보 신청 끝
	VoteStartDate			datetime,		-- 투표 시작 
	VoteEndDate				datetime,		-- 투표 끝
	Election				datetime		-- 선출일
)
GO
-- // 2008-01-09 by dhjin, DB 입력되는 날짜 형식 변경
TRUNCATE TABLE td_PollDate
INSERT INTO td_PollDate VALUES('20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00')
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_blockedAccount
-- DESC      : // 2008-01-29 by cmkwon, 계정 블럭/해제 로그 시스템 추가 - 로그 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_blockedAccount(
	LogType						TINYINT,
	Time						DATETIME,
	AccountName					VARCHAR(20),
	BlockedType					INT				DEFAULT(0),
	StartDate					DATETIME		DEFAULT(GetDate()),
	EndDate						DATETIME		DEFAULT(GetDate()),
	AdminAccountName			VARCHAR(20),
	BlockedReason				VARCHAR(200),							-- 유저가 보는 블럭 사유
	BlockedReasonForOnlyAdmin	VARCHAR(200)							-- 2007-01-10 by cmkwon, 관리자가 보는 블럭사유
)
CREATE CLUSTERED INDEX idx_Time_on_atum_log_blockedAccount		ON atum_log_blockedAccount(Time)
CREATE INDEX idx_LogType_on_atum_log_blockedAccount				ON atum_log_blockedAccount(LogType)
CREATE INDEX idx_AccountName_on_atum_log_blockedAccount			ON atum_log_blockedAccount(AccountName)					-- 2007-01-29 by cmkwon, 추가함
CREATE INDEX idx_BlockedType_on_atum_log_blockedAccount			ON atum_log_blockedAccount(BlockedType)
CREATE INDEX idx_StartDate_on_atum_log_blockedAccount			ON atum_log_blockedAccount(StartDate)
CREATE INDEX idx_EndDate_on_atum_log_blockedAccount				ON atum_log_blockedAccount(EndDate)
CREATE INDEX idx_AdminAccountName_on_atum_log_blockedAccount	ON atum_log_blockedAccount(AdminAccountName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_EventMonster
-- DESC      : // 2008-04-16 by cmkwon, 몬스터 사망 시 몬스터 소환 이벤트 시스템 구현 - ti_EventMonster 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_EventMonster
(
	EventMonsterUID				INT        IDENTITY(1,1) PRIMARY KEY,		-- EventMonsterUID
	ServerGroupID				INT,						-- // EventMonster 가 적용되는 ServerGroupID(0이면 모든 서버군에 적용, 0이 아니면 지정된 서버군만 적용)
	StartDateTime				DATETIME,					-- // EventMonster 시작 날짜시간
	EndDateTime					DATETIME,					-- // EventMonster 종료 날짜시간
	SummonerMapIndex			SMALLINT,					-- // 소환되는 맵인덱스(0이면 모든맵에서 소환됨, 0이 아니면 지정한 맵에서만 소환됨) 
	SummonerReqMinLevel			TINYINT,					-- // 소환하는 몬스터의 최소 레벨 체크(0이면 체크하지 않음)
	SummonerReqMaxLevel			TINYINT,					-- // 소환하는 몬스터의 최고 레벨 체크(0이면 체크하지 않음)
	SummonerExceptMonster		INT,						-- // 소환하는 몬스터 제외 체크  Bit Flag
	SummonMonsterNum			INT,						-- // 소환되는 MonsterUniqueNumber
	SummonMonsterCount			INT,						-- // 소환시 소환되는 몬스터 숫자
	SummonDelayTime				INT,						-- // 몬스터 사망 후 소환까지 걸리는 지연시간(단위:초)
	SummonProbability			INT							-- // 소환 성공 확률(0~10000)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_serverGroup
-- DESC      : // 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_serverGroup
(
	ServerGroupID						INT,						-- // 해당 ServerGroupID
	ServerGroupName						VARCHAR(20),				-- // ServerGroupName
	LimitUserCount						INT,						-- // 서버군에 접속 최대 유저수
	LockCreateCharacterForNewAccount	INT						-- // 신규 계정(캐릭터가 없는 계정)의 캐릭터 생성 제한 여부 플래그
)
GO

