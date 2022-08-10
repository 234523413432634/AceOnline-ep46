-- Database ��ü�� �ѱ��� ��� Korean_Wansung_CI_AS�� ����

--------------------------------------------------------------------------------
--
-- ����� ���� ����Ÿ
--
-- td_Account
-- td_AccountBackup, AdminTool���� �����ϸ鼭 ������, 20041115, kelovon
-- td_AccountBlock
-- td_BlockedAccounts
-- td_AccountCashStore
-- td_CouponList
-- 
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_Account
-- DESC      : ����� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_Account (
	AccountUniqueNumber	INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	AccountName			VARCHAR(20)	NOT NULL,
	Password			VARCHAR(35),						-- MD5, 32 bytes ĳ������
	AccountType			SMALLINT	NOT NULL DEFAULT(0),	-- ������(128), ���Ӹ�����(256), �����(512), �Խ�Ʈ(1024)
	Sex					TINYINT,							-- 1: ��, 2: ��
	BirthYear			INT,								-- ����
	RegisteredDate		DATETIME	DEFAULT(GetDate()),
	LastLoginDate		DATETIME	DEFAULT(GetDate()),
	IsBlocked			TINYINT		DEFAULT(0),
	ChattingBlocked		TINYINT		DEFAULT(0),
	MGameEventType		INT			DEFAULT(0),
	ConnectingServerGroupID				INT			DEFAULT(0),			-- 2006-09-21 by cmkwon, �������� ���� �ʵ� �߰�
	GameContinueTimeInSecondOfToday		INT			DEFAULT(0),			-- 2006-11-15 by cmkwon, ���� �Ϸ� ���� ���� �ð�(����:��)
	LastGameEndDate						DATETIME	DEFAULT(GetDate()),	-- 2006-11-15 by cmkwon, ���������� ������ ������ �ð�(����â�� �������)
	JuminNumber							VARCHAR(20),					-- 2007-06-29 by cmkwon, td_account ���̺� �ֹι�ȣ�����ϱ� - �ֹι�ȣ�ʵ�
	SecondaryPassword	VARCHAR(35)										-- // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - td_Account�� �ʵ� �߰�
)
CREATE UNIQUE INDEX idx_AccountName_on_account ON td_Account(AccountName)
CREATE INDEX idx_ConnectingServerGroupID_on_account ON td_Account(ConnectingServerGroupID)	-- 2006-09-21 by cmkwon, �߰�
CREATE INDEX idx_N_td_Account_JuminNumber on td_Account(JuminNumber)	-- 2007-10-01 by dhjin, 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_BlockedAccounts
-- DESC      : �з����� ����� ����
--				2007-01-10 by cmkwon, �ʵ��߰�(BlockedReasonForOnlyAdmin	VARCHAR(200))
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_BlockedAccounts (
	AccountName					VARCHAR(20)		PRIMARY KEY,
	BlockedType					INT				DEFAULT(0),
	StartDate					DATETIME		DEFAULT(GetDate()),
	EndDate						DATETIME		DEFAULT(GetDate()),
	AdminAccountName			VARCHAR(20),
	BlockedReason				VARCHAR(200),							-- ������ ���� �� ����
	BlockedReasonForOnlyAdmin	VARCHAR(200)							-- 2007-01-10 by cmkwon, �����ڰ� ���� ������
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_AccountCashStore
-- DESC      : ����ȭ ī��(�Ϲ� �����̾�, ���� �����̾�)
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AccountCashStore (
	UniqueNumber			BIGINT		IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	AccountUniqueNumber		INT			NOT NULL,				-- ������ AccountUniqueNumber
	ItemNum					INT			NOT NULL,				-- 7010120(�Ϲ������̾�) or 7010130(���������̾�)
	CreatedTime				DATETIME 	DEFAULT GetDate(),		-- ������ ���� �ð�
	UpdatedTime				DATETIME 	,						-- ������ ���� �ð�(�籸�� or Upgrade)
	ExpireTime				DATETIME							-- ������ ���� �ð�
)
CREATE UNIQUE INDEX idx_AccountUniqueNumber_on_accountCashStore ON td_AccountCashStore(AccountUniqueNumber)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_CouponList
-- DESC      : ���� ����Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CouponList (
	UniqueNumber			INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	CouponNumber			VARCHAR(30)	NOT NULL,				-- ���� ��ȣ
	ExpireTime				DATETIME 	,						-- ���� ��ȿ �Ⱓ
	UsedFlag				INT			DEFAULT 0,				-- ���� ��� ����	
	UsedAccountName			VARCHAR(20)	,						-- ���� ����� AccountName
	UsedTime				DATETIME							-- ������ ���� �ð�
)
CREATE UNIQUE INDEX idx_CouponNumber_on_CouponList ON td_CouponList(CouponNumber)
GO



--------------------------------------------------------------------------------
--
-- ���� ����
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
--		- 2006-04-12 by cmkwon, �߰���
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
-- DESC      : ������ ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Item (
	ItemNum			INT UNIQUE,	-- �����۰����ѹ�,	�������� �����ѹ��� ��Ÿ����.
	Kind			TINYINT,			-- ����,			�������� ������ ��Ÿ����
	ItemName		VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�. �������� �̸�
	AbilityMin		FLOAT,				-- �������ּҼ���,	�������� ���� �ּҰ�
	AbilityMax		FLOAT,				-- �������ִ뼺��,	�������� ���� �ִ밪
	ReqRace			SMALLINT,			-- �ʿ�����,		�����ۻ���� ���Ͽ� �ʿ��� ����
	ReqAttackPart	SMALLINT,			-- �ʿ������Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� ������Ʈ
	ReqDefensePart	SMALLINT,			-- �ʿ�����Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� �����Ʈ
	ReqFuelPart		SMALLINT,			-- �ʿ俬����Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� ������Ʈ
	ReqSoulPart		SMALLINT,			-- �ʿ䰨����Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� ������Ʈ
	ReqShieldPart	SMALLINT,			-- �ʿ佯����Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� ������Ʈ
	ReqDodgePart	SMALLINT,			-- �ʿ�ȸ����Ʈ,	�����ۻ���� ���Ͽ� �ʿ��� ȸ����Ʈ
	ReqUnitKind		INT,				-- �ʿ���������,	�����ۻ���� ���Ͽ� �ʿ��� ��������
	ReqMinLevel		TINYINT,			-- �ʿ� ���� ����,		�����ۻ���� ���Ͽ� �ʿ��� ����
	ReqMaxLevel		TINYINT,			-- �ʿ� �ְ� ����,		�����ۻ���� ���Ͽ� �ʿ��� ����
	ReqItemKind		TINYINT,			-- �ʿ����������,	��ų���� ���, 20040818, kelovon
	Weight			SMALLINT,			-- ����,			�������� ����
	HitRate			TINYINT,			-- ����Ȯ��,		���� ������ ������ �ִ� ��
	Defense			TINYINT,			-- ����,			ĳ������ Defense�� ������ �ִ� ��ġ
	FractionResistance	TINYINT,		-- �Ӽ����׷�,		ĳ������ �Ӽ����׷¿� ������ �ִ� ��
	NaturalFaction	TINYINT,			-- õ���迭,		�����ۿ� ���� �迭
	SpeedPenalty	TINYINT,			-- ���ǵ����Ƽ,	�������� �̵��ӵ��� ��ġ�� ����
	Range			SMALLINT,			-- ���ݹ���,		�������� ���ݹ���
	Position		TINYINT,			-- ������ġ,		������ ���� ��ġ
	Scarcity		TINYINT,			-- ��ͼ�,			�������� ��͵��� ��Ÿ���� �Ķ����, �������� ���׷��̵� ���ο� �����۰��� ������ ������ ���¿��� �ʿ��� �Ķ�����ΰ� ���
	Endurance		FLOAT,				-- ������,			�������� ������
	AbrasionRate	TINYINT,			-- ������,			�������� ����߸� �� �ִ� Ȯ��
	Charging		SMALLINT,			-- ��ź ��,			�����ۿ� ���ԵǴ� ź�� ��
	Luck			TINYINT,			-- ���,			�� �����ۿ� ��� ���ġ
	MinTradeQuantity	SMALLINT,		-- �ּ� �ŷ� ����,	Price�� �� ������ ���� �����̴�
	Price			INT,				-- ����,			�ּ� �ŷ� ������ ����, PriceRevision���
	CashPrice		INT,				-- ���� ����,		�ּ� �ŷ� ������ ����, PriceRevision���
	DestParameter1	TINYINT,			-- ����Ķ����1,	�� �������� ������ �ִ� ĳ������ �Ķ����
	ParameterValue1	FLOAT,				-- �����Ķ����1,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter2	TINYINT,			-- ����Ķ����2,	�� �������� ������ �ִ� ĳ������ �Ķ����
	ParameterValue2	FLOAT,				-- �����Ķ����2,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter3	TINYINT,			-- ����Ķ����3,	�� �������� ������ �ִ� ĳ������ �Ķ����
	ParameterValue3	FLOAT,				-- �����Ķ����3,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter4	TINYINT,			-- ����Ķ����4,	�� �������� ������ �ִ� ĳ������ �Ķ����
	ParameterValue4	FLOAT,				-- �����Ķ����4,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	ReAttacktime	INT,				-- �� ���ݽð�,		�� ������ �ϱ� ���� �ʿ��� �ð�
	Time			INT,				-- ���� �ð�,			�������� ȿ���� �󸶳� ���ӵ����� ��Ÿ��
	RepeatTime		SMALLINT,			-- ���Ƚ��,		�������� ��� ���� Ƚ��
	Material		SMALLINT,			-- ����,			�� �������� ���
	ReqMaterial		SMALLINT,			-- �ʿ��� ���� ��,	������ ���Ͽ� �ʿ��� ������ ���� ��Ÿ��
	RangeAngle		FLOAT,				-- ��������,		������ ������ ��Ÿ����.
	UpgradeNum		TINYINT,			-- ���׷��̵� ��,	���׷��̵��� �Ѱ踦 ��Ÿ��.
	LinkItem		INT,				-- ��ũ������,		�����۰� ������ ������ (�Ѿ�)
	MultiTarget		TINYINT,			-- ����Ÿ��,		���ÿ� ���� �� �ִ� Ÿ���� ��
	ExplosionRange	SMALLINT,			-- ���߹ݰ�,		���� �� �������� ������ ��ġ�� �ݰ�
	ReactionRange	SMALLINT,			-- �����ݰ�,		���� ���� �����ϴ� �ݰ�
	ShotNum			TINYINT,			-- ���� ��,			���� �� �߻� ���� ��Ÿ����.
	MultiNum		TINYINT,			-- ���� �߻� ź ��,	1�� �߻翡 ����� ���ÿ� ��������
	AttackTime		SMALLINT,			-- ���ݽð�,	������ �ϱ� ���� �ʿ��� �ð�
	ReqSP			TINYINT,			-- SP �Ҹ�(��ų)
	SummonMonster	INT,				-- ��ȯ����(��ų)
	NextSkill		INT,				-- ��ų�䱸 ����(��ų), ���⼭�� �����ϰ� store������ ������, 12
	SkillLevel		TINYINT,			-- ����
	SkillHitRate	TINYINT,			-- ��ų����Ȯ��
	SkillType		TINYINT,			-- ��ų����
	SkillTargetType	TINYINT,			-- ��ųŸ��Ÿ��
	Caliber			TINYINT,			-- ����(�Ѿ�, ź�� ��)
	OrbitType		TINYINT,			-- �̻���, ���� ���� ����
	ItemAttribute	INT,				-- �������� �Ӽ�, �Ϲ� ���Ϳ��� �������� �������̳�? Ȥ�� quest�� �������̳�? �ŷ�&�̵� �Ұ���? ���
	BoosterAngle	FLOAT,				-- �ν��ͽÿ� ������ ȸ����, ����� �������� ���
	CameraPattern	INT,				-- ī�޶� ����
	SourceIndex		INT,				-- �������� ���ҽ� �ҽ�, 2005-08-22 by cmkwon
	Description		VARCHAR(200) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�. ������ ����
)
GO
CREATE UNIQUE CLUSTERED INDEX idx_on_Item ON ti_Item(Kind, ItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_EnchantInfo
-- DESC      : Enchant ���� ����
-- 2005-08-02 by cmkwon, ��æƮ �ִ� 9������ 40���� �ø�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_EnchantInfo (
	EnchantItemNum			INT	NOT NULL	-- enchant�� ���� �������� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	EnchantItemCount		INT	NOT NULL,	-- �ʿ��� ����
	EnchantCost				INT NOT NULL,	-- ��� ������ ���� ������
	Prob1					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob2					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob3					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob4					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob5					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob6					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob7					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob8					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob9					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob10					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob11					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob12					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob13					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob14					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob15					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob16					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob17					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob18					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob19					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob20					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob21					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob22					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob23					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob24					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob25					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob26					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob27					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob28					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob29					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob30					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob31					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob32					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob33					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob34					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob35					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob36					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob37					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob38					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob39					INT	NOT NULL DEFAULT(0),	-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
	Prob40					INT	NOT NULL DEFAULT(0)		-- �� �ܰ� ��æƮ �� ���յ� Ȯ��(1~10000)
)
CREATE CLUSTERED INDEX idx_on_EnchantInfo ON ti_EnchantInfo(EnchantItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_ItemMixingInfo
-- DESC      : ������ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemMixingInfo (
	TargetItemNum			INT NOT NULL	-- �ϼ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	MixingProbability		INT	NOT NULL,	-- ���۵� Ȯ��(1~10000)
	MixingCost				INT	NOT NULL,	-- ��� ������ ���� ������
	SourceItemNum1			INT	NOT NULL				-- �ʿ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount1		INT	NOT NULL,				-- �ʿ��� ����
	SourceItemNum2			INT	NOT NULL DEFAULT(0)		-- �ʿ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount2		INT	NOT NULL DEFAULT(0),	-- �ʿ��� ����
	SourceItemNum3			INT	NOT NULL DEFAULT(0)		-- �ʿ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount3		INT	NOT NULL DEFAULT(0),	-- �ʿ��� ����
	SourceItemNum4			INT	NOT NULL DEFAULT(0)		-- �ʿ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount4		INT	NOT NULL DEFAULT(0),	-- �ʿ��� ����
	SourceItemNum5			INT	NOT NULL DEFAULT(0)		-- �ʿ��� ��� ItemNum
		--REFERENCES ti_Item(ItemNum)
		,
	SourceItemCount5		INT	NOT NULL DEFAULT(0)		-- �ʿ��� ����
)
CREATE UNIQUE CLUSTERED INDEX idx_on_ItemMixingInfo
	ON ti_ItemMixingInfo(TargetItemNum, SourceItemNum1, SourceItemNum2,
						SourceItemNum3, SourceItemNum4, SourceItemNum5)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_RareItemInfo
-- DESC      : ���� �������� ����� ���� suffix Ȥ�� prefix�� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_RareItemInfo
(
	CodeNum				INT,		-- ���λ�, ���̻� ���е�
	Name				VARCHAR(21) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�., 12->21�� ������
	ReqUseType			INT DEFAULT(1),					-- 2005-04-04 by cmkwon
	ReqMinLevel			INT,
	ReqMaxLevel			INT,
	ReqItemKind			TINYINT,
	ReqAttackPart		SMALLINT,	-- ���� ��Ʈ
	ReqDefensePart		SMALLINT,	-- ��� ��Ʈ
	ReqDodgePart		SMALLINT,	-- ȸ�� ��Ʈ
	ReqFuelPart			SMALLINT,	-- ���� ��Ʈ
	ReqShieldPart		SMALLINT,	-- ���� ��Ʈ
	ReqSoulPart			SMALLINT,	-- ���� ��Ʈ
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
	Probability			INT			-- ���� Ȯ��, ����: 1 ~ 100000
)
CREATE UNIQUE CLUSTERED INDEX idx_CodeNum_on_RareItemInfo ON ti_RareItemInfo(CodeNum)		-- 2005-10-19 by cmkwon
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Shop
-- DESC      : ���ÿ� ����� ������ �ű⼭ �Ĵ� ������
-- 2007-08-10 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Shop (
	ShopOrder			INT,		-- 2007-08-10 by dhjin, ���� ����Ʈ ������ ���� �߰���
	UniqueNumber		INT,		-- UINT, �� 4�ڸ�(NPCTalkIndex), �� 4�ڸ�(�ǹ� �з�)
	ItemNum				INT			-- UINT
		--REFERENCES ti_Item(ItemNum)
)
CREATE UNIQUE CLUSTERED INDEX idx_ShopOrder_on_ti_Shop ON ti_Shop(ShopOrder)		-- 2007-08-10 by dhjin
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Monster
-- DESC      : ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Monster (
	UniqueNumber		INT		PRIMARY KEY,
	MonsterName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.
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
	SizeForServer		INT, -- USHORT�� ���
	SizeForClient		INT, -- USHORT�� ���, ������ size���� ����
	Faction				TINYINT,
	MonsterForm			SMALLINT,
	AttackPattern		TINYINT,
	MovePattern			SMALLINT,
	Belligerence		TINYINT,
	Defense				TINYINT,
	DefenceProbability	TINYINT,
	AlphaBlending		TINYINT,
	AttackObject		TINYINT,
	AttackRange			SMALLINT,				-- 2005-02-01 by cmkwon, ���ݼ��� ���Ͱ� Ÿ�����ϴ� �Ÿ�
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
-- DESC      : ���Ͱ� �׾��� �� ����߸��� �������� ���� �� �� Ȯ��
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MonsterItem (
	MonsterUniqueNumber	INT,	--REFERENCES ti_Monster(UniqueNumber),	-- ���� ����
	ItemNum				INT,	--REFERENCES ti_Item(ItemNum),			-- �����۰����ѹ�
	MinCount			INT,	-- ������ �������� �ּ� ����
	MaxCount			INT,	-- ������ �������� �ִ� ����, ���� ������ ������ �ִٸ� MinCount = MixCount
	Probability			INT,	-- ���� Ȯ��: 0 ~ 1000000
	PrefixProbability	INT,		-- ���λ簡 ���� Ȯ��, 0 ~ 100000
	SuffixProbability	INT,		-- ���̻簡 ���� Ȯ��, 0 ~ 100000
)
CREATE UNIQUE CLUSTERED INDEX idx_monsteritem ON ti_MonsterItem(monsteruniquenumber, itemnum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_MapObject
-- DESC      : ������, Map Object�� ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MapObject (
	ObjectName				VARCHAR(50) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.
	Code					INT,
	Alpha					TINYINT,		-- 1(TRUE), 0(FALSE)
	RadiusForServer			INT,			-- USHORT
	RadiusForClient			INT,			-- USHORT, ������ Radius���� ����
	Collision				TINYINT,		-- 1(TRUE), 0(FALSE)
	CollisionForServer		TINYINT,		-- 1(TRUE), 0(FALSE)
	RenderIndex				SMALLINT,		-- USHORT
	ObjectRenderType		TINYINT,
	ObjectDescription		VARCHAR(250) COLLATE Korean_Wansung_CI_AS	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_BuildingNPC
-- DESC      : �� ���� �� ��� NPC�� ����	  
--				// 2008-01-03 by cmkwon, BuildingName �ʵ� 40Bytes �� ���� - ����(<--20)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_BuildingNPC (
	BuildingIndex			INT,			-- �ǹ�(���� ��) ���� ��ȣ
	BuildingName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�., ���� �̸�
	BuildingKind			TINYINT,		-- �ǹ� ����, ex)���� ����, ��ǰ ����, ...
	MapIndex				SMALLINT,		-- ���� �ִ� ���� Index, ex)0101, 0102
	NPCIndex				INT,			-- ��� NPC
	NPCName					VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.
	GreetingTalk			VARCHAR(400) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�., �λ縻
	OwnerCityMapIndex		INT,			-- �� ������ ������ ���ø��� ���ε���
	OwnerOrderNumber		INT				-- �ʵ� ������ ���ɼ���
)
GO
CREATE CLUSTERED INDEX idx_BuildingNPC ON ti_BuildingNPC(MapIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_CityTargetWarpMap
-- DESC      : ���ÿ��� ������ ���� �� �ִ� ���� ����Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_CityTargetWarpMap (
	MapIndex				INT,
	BuildingIndex			INT,
	WarpTargetMapIndex		INT,
	WarpTargetIndex			INT,
	WarpTargetName			VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.
	Fee						INT				-- ���� ���
)
GO
-- 2007-02-05 by cmkwon, �Ʒ��� ���� ������
--CREATE UNIQUE CLUSTERED INDEX idx_CityTargetWarpMap ON ti_CityTargetWarpMap(MapIndex, WarpTargetMapIndex, WarpTargetIndex)
CREATE CLUSTERED INDEX idx_MapIndex_on_CityTargetWarpMap ON ti_CityTargetWarpMap(MapIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_MapInfo
-- DESC      : �� ����		   
--				// 2008-01-03 by cmkwon, MapName �ʵ� 40Bytes �� ���� - ����(<--30)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MapInfo(
	MapIndex				INT PRIMARY KEY,
	RenderMapIndex			INT,				-- Render ���� ���� ���ε���, 2005-07-12 by cmkwon
	BeforeMapIndex			INT,				-- 2006-08-02 by cmkwon, Ÿ���¸ʿ��� �׾��� ��� ��Ȱ�� ���⿡ ������ �ʿ��� ��Ȱ��
	MapName					VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�., ���̸�
	MapInfluenceType		SMALLINT,			-- 2005-12-26 by cmkwon, ���� ���� ����(0=�߸�, 1000~1999=����������, 2000~2999=�˸���)
	CityMapIndex			INT,				-- ���������� �ʿ��� ������
	CityWarQuestIndex		INT,				-- ���������� �ʿ��� ������
	CityWarQuestNPCIndex	INT,				-- ���������� �ʿ��� ������
	CityWarQuestMonsterUID	INT,				-- ���������� �ʿ��� ������
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
	ClientMaxAltitudeHeight	smallint,			-- Ŭ���̾�Ʈ �̵� ���� �ִ� ����, 2005-07-11 by cmkwon
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
	BeforeMapIndex2			INT					-- // 2008-06-20 by cmkwon, EP3 ��� �ý��� ����(�ʴ� ����� 2�� ���� �� �� �ִ�) - ti_mapInfo ���̺� �ʵ� �߰�
	)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: ti_HappyHourEvent
-- DESC      : ���� ����Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_HappyHourEvent(
	UniqueNumber			INT			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	ServerGroupID			INT 		DEFAULT(0),				-- 0(=AllServerGroup), 1(=10061), 2(10062), ...
	DayOfWeek				INT 		NOT NULL,				-- ����	- ��(0) ��(1) ȭ(2) ��(3) ��(4) ��(5) ��(6) HappyHourEvent�Ⱓ(7) PCBangHappyHourEvent�Ⱓ�׼���(8)
	StartTime				DATETIME	NOT NULL,				-- ���� �ð�(DayOfWeek=7 �϶����� ������� ����)
	EndTime					DATETIME 	NOT NULL,				-- ���� �ð�(DayOfWeek=7 �϶����� ������� ����)
	EXPRate					FLOAT,								-- ����ġ �̺�Ʈ Rate
	SPIRate					FLOAT,								-- ���� �̺�Ʈ Rate
	EXPRepairRate			FLOAT,								-- ����ġ ���� �̺�Ʈ Rate
	DropItemRate			FLOAT,								-- ������ ��� Rate
	DropRareItemRate		FLOAT,								-- ���� ������ ��� Rate
	WarPointRate			FLOAT,								-- 2007-06-27 by dhjin, WarPoint �̺�Ʈ Rate
	InfluenceType			TINYINT,							-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ti_HappyHourEvent ���̺� �ʵ� �߰�
	MinLevel				INT,
	MaxLevel				INT									
)
CREATE INDEX idx_DayOfWeek_on_HappyHourEvent ON ti_HappyHourEvent(DayOfWeek)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfluenceWar - 2006-04-12 by cmkwon
-- DESC      : ������ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfluenceWar(
	InfluenceType				TINYINT		NOT NULL,		-- INFLUENCE_TYPE_VCN(2) or INFLUENCE_TYPE_ANI(4)
	WartimeStage				TINYINT		NOT NULL,		-- ���ôܰ�(0, 1, 2, 3, 4,...10)
	ReqContributionPoint		INT			NOT NULL,		-- ���ôܰ谡 �Ǳ� ���� �ʿ� �⿩��(ContributionPoint)
	HPRepairRate				FLOAT,			-- �ش� ���ôܰ� �� �� HPȸ����
	DPRepairRate				FLOAT,			-- �ش� ���ôܰ� �� �� DPȸ����
	SPRepairRate				FLOAT,			-- �ش� ���ôܰ� �� �� SPȸ����
	EventTime					INT,			-- 
	EventExperience				FLOAT,			-- 
	EventDropSPI				FLOAT,			-- 
	EventDownExperience			FLOAT,			-- 
	EventDropItem				FLOAT,			-- 
	EventDropRareItem			FLOAT,			-- 
	SupplyItemNum				INT,			-- 
	SupplyItemCount				INT,			-- 
	IsSummonJacoMonster			TINYINT,		-- �ش� ���ôܰ�� �ɶ� ���ڸ��� ��ȯ �÷���
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
-- DESC      : 2007-05-11 by cmkwon, �̽��׸�ĸ���� �������� ��� �� �� ����� ������ ����Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_MysteryItemDrop(
	MysteryItemDropNum		INT			NOT NULL,	-- ���� ��ȣ, �ߺ� ����
	ReqUnitKind				INT,					-- �ʿ���������,	�����ۻ���� ���Ͽ� �ʿ��� ��������
	ReqMinLevel				TINYINT,				-- �ʿ� ���� ����,		�����ۻ���� ���Ͽ� �ʿ��� ����
	ReqMaxLevel				TINYINT,				-- �ʿ� �ְ� ����,		�����ۻ���� ���Ͽ� �ʿ��� ����
	DropItemNum				INT,					-- 
	MinCount				INT,					-- ������ �������� �ּ� ����
	MaxCount				INT,					-- ������ �������� �ִ� ����, ���� ������ ������ �ִٸ� MinCount = MixCount
	Probability				INT,					-- ���� Ȯ��(��밪���� ó��): 0 ~ 1000000
	PrefixProbability		INT,					-- ���λ簡 ���� Ȯ��, 0 ~ 100000
	SuffixProbability		INT						-- ���̻簡 ���� Ȯ��, 0 ~ 100000
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
-- �α� ����
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
-- 2005-01-10 7:08����
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
-- Account DB atum_back_log_X ���̺� �����
-- �� �Ʒ� ���̺� �׻� ���� �ؾ��Ѵ�
--------------------------------------------------------------------------------
SELECT * INTO dbo.atum_backup_log_connection			FROM dbo.atum_log_connection		-- 1
SELECT * INTO dbo.atum_backup_log_total_user			FROM dbo.atum_log_total_user		-- 2
GO

--------------------------------------------------------------------------------
-- 2006-08-24 11:55����   by dhjin
-- TABLE NAME: ti_ItemEvent
-- DESC      : �̺�Ʈ ������ ����
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
	ReqLevel		TINYINT,			-- 2007-07-23 by dhjin, �������� �̺�Ʈ  
	NewMember		BIT,				-- 2007-07-23 by dhjin, �̺�Ʈ �Ⱓ �ȿ� �ű� ������ ���� ���
	UnitKind		INT,     			-- 2007-07-24 by dhjin, ������ ���� ����
	PrefixCodeNum	INT,				-- 2007-07-25 by dhjin, ������ ���� ���� �ɼ�
	SuffixCodeNum   INT,				-- 2007-07-25 by dhjin, ������ ���� ���� �ɼ�
	UseLastGameEndDate	INT,			-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
	LastGameEndDate		DATETIME		-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
)
GO

--------------------------------------------------------------------------------
-- 2006-08-24 11:55����   by dhjin
-- TABLE NAME: atum_Log_ItemEvent
-- DESC      : �̺�Ʈ ������ ���� ���� ����
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
	UID					INT				NOT NULL,				-- 2007-01-19 by dhjin, PC�� IP UniqueNumber
	ST_IP				VARCHAR(20)		NOT NULL,				-- 2007-01-19 by dhjin, PC�� ���� IP
	ED_IP				VARCHAR(4),								-- 2007-01-19 by dhjin, PC�� �� IP
	User_Id				VARCHAR(15)		NOT NULL,				-- 2007-01-19 by dhjin, PC�� ���� ID
	Branch_Name			NVARCHAR(50)	NOT NULL,				-- 2007-01-19 by dhjin, PC�� ��ȣ��
	Branch_RegNO		VARCHAR(12)		NOT NULL,				-- 2007-01-19 by dhjin, PC�� �����Ϲ�ȣ
	Branch_Tel			VARCHAR(14)		NOT NULL,				-- 2007-01-19 by dhjin, PC�� ��ȭ��ȣ
	ZipCode				CHAR(15)		NOT NULL,				-- 2007-01-19 by dhjin, PC�� �����ȣ
	Addr_Sido			NVARCHAR(10)	NOT NULL,				-- 2007-01-19 by dhjin, PC�� �ּ� ��
	Addr_SiGuGun		NVARCHAR(20)	NOT NULL,				-- 2007-01-19 by dhjin, PC�� �ּ� ��
	Addr_Dong			NVARCHAR(100)	NOT NULL,				-- 2007-01-19 by dhjin, PC�� �ּ� ��
	Addr_Detail			NVARCHAR(50),							-- 2007-01-19 by dhjin, PC�� ���ּ�
	User_Level			TINYINT			DEFAULT(0)				-- 2007-06-25 by dhjin, PC�� ��� �߰�
)
CREATE CLUSTERED INDEX idx_UID_on_td_PCBang ON td_PCBang(UID)
CREATE INDEX idx_Branch_Name_on_td_PCBang ON td_PCBang(Branch_Name)
CREATE INDEX idx_Addr_Sido_on_td_PCBang ON td_PCBang(Addr_Sido)
CREATE INDEX idx_Addr_SiGuGun_on_td_PCBang ON td_PCBang(Addr_SiGuGun)
CREATE INDEX idx_Addr_Dong_on_td_PCBang ON td_PCBang(Addr_Dong)
GO

	
--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_integration
-- DESC      : 2007-01-26 by cmkwon, �߰��� - ���� ����, ���� ���� �α�
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_integration (
	LogType						TINYINT,
	Time						DATETIME,
	AccountName					VARCHAR(20),			-- 2007-01-29 by cmkwon, �߰���
	AccountUID					INT,					-- 2007-01-29 by cmkwon, �߰���
	SourceDBNum					INT,
	SourceCharacterUID			INT,
	SourceCharacterName			VARCHAR(20),
	TargetDBNum					INT,
	TargetCharacterUID			INT,
	TargetCharacterName			VARCHAR(20)
)
CREATE CLUSTERED INDEX idx_Time_on_atum_log_integration ON atum_log_integration (Time)
CREATE INDEX idx_LogType_on_atum_log_integration ON atum_log_integration(LogType)
CREATE INDEX idx_AccountName_on_atum_log_integration ON atum_log_integration(AccountName)					-- 2007-01-29 by cmkwon, �߰���
CREATE INDEX idx_AccountUID_on_atum_log_integration ON atum_log_integration(AccountUID)						-- 2007-01-29 by cmkwon, �߰���
CREATE INDEX idx_SourceCharacterUID_on_atum_log_integration ON atum_log_integration(SourceCharacterUID)
CREATE INDEX idx_SourceCharacterName_on_atum_log_integration ON atum_log_integration(SourceCharacterName)
CREATE INDEX idx_TargetCharacterUID_on_atum_log_integration ON atum_log_integration(TargetCharacterUID)
CREATE INDEX idx_TargetCharacterName_on_atum_log_integration ON atum_log_integration(TargetCharacterName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_StrategyPointSummonMapIndex
-- DESC      : ��������Ʈ ���� �� ����
-- 2007-02-26 by dhjin,
--				-- // 2008-01-03 by cmkwon, MapName �ʵ� 40Bytes �� ���� - ����(<--30)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_StrategyPointSummonMapIndex
(
	MapName				VARCHAR(40) COLLATE Korean_Wansung_CI_AS,	-- // 2008-04-24 by cmkwon, �ѱ� �ϼ������� �����Ѵ�.	
	MapIndex			INT PRIMARY KEY,
	StratrgyPiontNum	INT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ�
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointSummonRange
(
	SummonRange		SMALLINT,			-- ���� �ֱ� (���� : ��)
	StrategyPointSummonCheck TINYINT, -- ��������Ʈ ���� üũ�� (0: �������� �ʴ´�, 1: ����)
	MaxSummonCountDaily  TINYINT,        -- �Ϸ翡 ��������Ʈ ���� ������ ��
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_StrategyPointNotSummonTime
-- DESC      : ��������Ʈ�� �����Ǹ� �ȵǴ� ���Ϻ� �ð� ����
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_StrategyPointNotSummonTime
(
	DayOfWeek				SMALLINT PRIMARY KEY,		-- ����
	StartTime				SMALLDATETIME,				-- �����Ǹ� �ȵǴ� ���� �ð�
	EndTime					SMALLDATETIME,				-- �����Ǹ� �ȵǴ� ������ �ð�
	CheckSummon				TINYINT						--// 2008-04-04 by dhjin, ��ȯ ���� �ð� ���� - 0:�����ð� , 1:��ȯ�ð�
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
-- DESC      : �Ʒ��� ����
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ArenaInfo(
 ArenaMode		TINYINT,			-- �Ʒ��� ��� 0 : DeathMatch, 1 : Round
 ReqMemberNum	TINYINT,			-- �� �ο� ���� 
 PayInfluencePointWIN 	INT,			-- �¸� ���¿��� ����Ǵ� ��������Ʈ��
 PayInfluencePointLOSE	INT,			-- �й� ���¿��� ����Ǵ� ��������Ʈ��
 PayWarPointWIN	INT,			-- �¸� ������ ����Ǵ� WP��
 PayWarPointLOSE	INT			-- �й� ������ ����Ǵ� WP��
)
CREATE CLUSTERED INDEX idx_ArenaMode_on_ArenaInfo ON ti_ArenaInfo(ArenaMode)
CREATE INDEX idx_ReqMemberNum_on_ArenaInfo ON ti_ArenaInfo(ReqMemberNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ArenaMapinfo
-- DESC      : �Ʒ��� �� ����
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ArenaMapinfo(
 ArenaMapIndex	INT,				-- dbo.ti_MapInfo(MapIndex)�� �����ؾ� �Ѵ�.
 ArenaMode		TINYINT,			-- �Ʒ��� ��� 0 : DeathMatch, 1 : Round
 ReqMemberNum 	TINYINT , 			-- dbo.ti_ArenaInfo(ReqMemberNum)�� �����ؾ� �Ѵ�.
 PlayLimitedTime	TINYINT,		-- ������ġ ��� ���� �ð�
 WINCondition		TINYINT,		-- ������ġ ��� �¸� ����
 LvDSupplyItemNum1		INT,		-- �Ʒ��� ���� ������ 1                        
 LvDSupplyItemCount1	INT,        -- �Ʒ��� ���� ������ 1 ��                     
 LvDSupplyItemNum2		INT,        -- �Ʒ��� ���� ������ 2                        
 LvDSupplyItemCount2	INT,        -- �Ʒ��� ���� ������ 2 ��                      
 LvDSupplyItemNum3		INT,        -- �Ʒ��� ���� ������ 3                        
 LvDSupplyItemCount3	INT         -- �Ʒ��� ���� ������ 3 �� 
)
CREATE CLUSTERED INDEX idx_ArenaMapIndex_on_ArenaMapinfo ON ti_ArenaMapinfo(ArenaMapIndex)
CREATE INDEX idx_ReqMemberNum_on_ArenaMapinfo ON ti_ArenaMapinfo(ReqMemberNum)
CREATE INDEX idx_ArenaMode_on_ArenaMapinfo ON ti_ArenaMapinfo(ArenaMode)
GO

 CREATE TABLE dbo.ti_TutorialInfo(
   TutorialUID             	 INT, 			-- Ʃ�丮�� UID
   TutorialPayItem1       	 INT,			-- Ʃ�丮�� ���� ������1
   TutorialPayItemCount1     INT,			-- Ʃ�丮�� ���� ������ �� 1
   TutorialPayItem2     	 INT,			-- Ʃ�丮�� ���� ������2
   TutorialPayItemCount2	 INT,			-- Ʃ�丮�� ���� ������ �� 2  
   TutorialPayItem3      	 INT,			-- Ʃ�丮�� ���� ������3
   TutorialPayItemCount3     INT			-- Ʃ�丮�� ���� ������ �� 3
)
CREATE CLUSTERED INDEX idx_TutorialUID_on_TutorialInfo ON ti_TutorialInfo(TutorialUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_OutPostNextWarTime
-- DESC		 : �������� ���� �ð� ����
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_OutPostNextWarTime
(
	OutPostWarStartTime		DATETIME		-- �������� �� ���� �ð� ���� (����: ������ �ð��� 2�ð� ���̴�)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ActionByLevel
-- DESC		 : ������ ���� ���� ������
-- 2007-10-16 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ActionByLevel
(
	Level		TINYINT		PRIMARY KEY,	-- Level
	PollPoint	INT							-- Poll����
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_PollDate
-- DESC		 : ��ǥ �Ⱓ
-- 2007-10-23 by dhjin,
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_PollDate
(
	ApplicationStartDate	datetime,		-- �ĺ� ��û ���� 
	ApplicationEndDate		datetime,		-- �ĺ� ��û ��
	VoteStartDate			datetime,		-- ��ǥ ���� 
	VoteEndDate				datetime,		-- ��ǥ ��
	Election				datetime		-- ������
)
GO
-- // 2008-01-09 by dhjin, DB �ԷµǴ� ��¥ ���� ����
TRUNCATE TABLE td_PollDate
INSERT INTO td_PollDate VALUES('20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00', '20100101 00:00:00')
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_blockedAccount
-- DESC      : // 2008-01-29 by cmkwon, ���� ��/���� �α� �ý��� �߰� - �α� ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.atum_log_blockedAccount(
	LogType						TINYINT,
	Time						DATETIME,
	AccountName					VARCHAR(20),
	BlockedType					INT				DEFAULT(0),
	StartDate					DATETIME		DEFAULT(GetDate()),
	EndDate						DATETIME		DEFAULT(GetDate()),
	AdminAccountName			VARCHAR(20),
	BlockedReason				VARCHAR(200),							-- ������ ���� �� ����
	BlockedReasonForOnlyAdmin	VARCHAR(200)							-- 2007-01-10 by cmkwon, �����ڰ� ���� ������
)
CREATE CLUSTERED INDEX idx_Time_on_atum_log_blockedAccount		ON atum_log_blockedAccount(Time)
CREATE INDEX idx_LogType_on_atum_log_blockedAccount				ON atum_log_blockedAccount(LogType)
CREATE INDEX idx_AccountName_on_atum_log_blockedAccount			ON atum_log_blockedAccount(AccountName)					-- 2007-01-29 by cmkwon, �߰���
CREATE INDEX idx_BlockedType_on_atum_log_blockedAccount			ON atum_log_blockedAccount(BlockedType)
CREATE INDEX idx_StartDate_on_atum_log_blockedAccount			ON atum_log_blockedAccount(StartDate)
CREATE INDEX idx_EndDate_on_atum_log_blockedAccount				ON atum_log_blockedAccount(EndDate)
CREATE INDEX idx_AdminAccountName_on_atum_log_blockedAccount	ON atum_log_blockedAccount(AdminAccountName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_EventMonster
-- DESC      : // 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - ti_EventMonster ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_EventMonster
(
	EventMonsterUID				INT        IDENTITY(1,1) PRIMARY KEY,		-- EventMonsterUID
	ServerGroupID				INT,						-- // EventMonster �� ����Ǵ� ServerGroupID(0�̸� ��� �������� ����, 0�� �ƴϸ� ������ �������� ����)
	StartDateTime				DATETIME,					-- // EventMonster ���� ��¥�ð�
	EndDateTime					DATETIME,					-- // EventMonster ���� ��¥�ð�
	SummonerMapIndex			SMALLINT,					-- // ��ȯ�Ǵ� ���ε���(0�̸� ���ʿ��� ��ȯ��, 0�� �ƴϸ� ������ �ʿ����� ��ȯ��) 
	SummonerReqMinLevel			TINYINT,					-- // ��ȯ�ϴ� ������ �ּ� ���� üũ(0�̸� üũ���� ����)
	SummonerReqMaxLevel			TINYINT,					-- // ��ȯ�ϴ� ������ �ְ� ���� üũ(0�̸� üũ���� ����)
	SummonerExceptMonster		INT,						-- // ��ȯ�ϴ� ���� ���� üũ  Bit Flag
	SummonMonsterNum			INT,						-- // ��ȯ�Ǵ� MonsterUniqueNumber
	SummonMonsterCount			INT,						-- // ��ȯ�� ��ȯ�Ǵ� ���� ����
	SummonDelayTime				INT,						-- // ���� ��� �� ��ȯ���� �ɸ��� �����ð�(����:��)
	SummonProbability			INT							-- // ��ȯ ���� Ȯ��(0~10000)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.td_serverGroup
-- DESC      : // 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_serverGroup
(
	ServerGroupID						INT,						-- // �ش� ServerGroupID
	ServerGroupName						VARCHAR(20),				-- // ServerGroupName
	LimitUserCount						INT,						-- // �������� ���� �ִ� ������
	LockCreateCharacterForNewAccount	INT						-- // �ű� ����(ĳ���Ͱ� ���� ����)�� ĳ���� ���� ���� ���� �÷���
)
GO

