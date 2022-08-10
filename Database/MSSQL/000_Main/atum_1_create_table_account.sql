-- Database ��ü�� �ѱ��� ��� Korean_Wansung_CI_AS�� ����

--------------------------------------------------------------------------------
--
-- ����� ���� ����Ÿ
--
-- td_account
-- td_AccountBackup, AdminTool���� �����ϸ鼭 ������, 20041115, kelovon
-- td_AccountBlock
-- td_BlockedAccounts
-- td_AccountCashStore
-- td_CouponList
-- 
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_account
-- DESC      : ����� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_account (
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
CREATE UNIQUE INDEX idx_AccountName_on_account ON td_account(AccountName)
CREATE INDEX idx_ConnectingServerGroupID_on_account ON td_account(ConnectingServerGroupID)	-- 2006-09-21 by cmkwon, �߰�
CREATE INDEX idx_N_td_Account_JuminNumber on td_account(JuminNumber)	-- 2007-10-01 by dhjin, 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_BlockedAccounts
-- DESC      : �з����� ����� ����
--				2007-01-10 by cmkwon, �ʵ��߰�(BlockedReasonForOnlyAdmin	VARCHAR(200))
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_blockedaccounts (
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
CREATE TABLE dbo.td_accountcashstore (
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
CREATE TABLE dbo.td_couponlist (
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
-- TABLE NAME: ti_ItemInfo
-- DESC      : ������ ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemInfo (
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
	HitRate			FLOAT,				-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, ����Ȯ��,		���� ������ ������ �ִ� ��, -- // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
	Defense			TINYINT,			-- ����,			ĳ������ Defense�� ������ �ִ� ��ġ
	FractionResistance	FLOAT,			-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, �Ӽ����׷�,		ĳ������ �Ӽ����׷¿� ������ �ִ� �� -- // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
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
	DestParameter1	SMALLINT,			-- ����Ķ����1,	�� �������� ������ �ִ� ĳ������ �Ķ���� -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue1	FLOAT,				-- �����Ķ����1,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter2	SMALLINT,			-- ����Ķ����2,	�� �������� ������ �ִ� ĳ������ �Ķ���� -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue2	FLOAT,				-- �����Ķ����2,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter3	SMALLINT,			-- ����Ķ����3,	�� �������� ������ �ִ� ĳ������ �Ķ���� -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue3	FLOAT,				-- �����Ķ����3,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����
	DestParameter4	SMALLINT,			-- ����Ķ����4,	�� �������� ������ �ִ� ĳ������ �Ķ���� -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue4	FLOAT,				-- �����Ķ����4,	����Ķ������ ��(Ȥ�� state)�� ��� ��ȭ��ų �������� ��Ÿ���� �Ķ����

	DestParameter5	SMALLINT,			-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - ����Ķ����5 -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue5	FLOAT,				-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �����Ķ����5
	DestParameter6	SMALLINT,			-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - ����Ķ����6 -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue6	FLOAT,				-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �����Ķ����6
	DestParameter7	SMALLINT,			-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - ����Ķ����7 -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue7	FLOAT,				-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �����Ķ����7
	DestParameter8	SMALLINT,			-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - ����Ķ����8 -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	ParameterValue8	FLOAT,				-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �����Ķ����8

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
	EnchantCheckDestParam		TINYINT			DEFAULT(0),		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	InvokingDestParamID			INT,			-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ������������� --REFERENCES ti_InvokingWearItemDestParamNum(InvokingDestParamID)
	InvokingDestParamIDByUse	INT				-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ������������� --REFERENCES ti_InvokingWearItemDestParamNumByUse(InvokingDestParamIDByUse)
)
GO

CREATE UNIQUE CLUSTERED INDEX idx_on_Item ON ti_ItemInfo(Kind, ItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME:	ti_OverlapItem
-- DESC      :	������ ������ ����
--				// 2012-03-12 by hskim, DB ���� ���� - it_Item
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_OverlapItem
(
	ItemNum			INT	NOT NULL PRIMARY KEY,		-- REFERENCES ti_Item(ItemNum)
	CashPrice		INT,
	Tab				INT,							-- ���� �� (ItemNum���� summonmonster �ʵ�)
	ItemAttribute	INT
)
GO

CREATE VIEW dbo.ti_Item
AS
	SELECT [dbo].[ti_ItemInfo].[ItemNum]
		  ,[dbo].[ti_ItemInfo].[Kind]
		  ,[dbo].[ti_ItemInfo].[ItemName]
		  ,[dbo].[ti_ItemInfo].[AbilityMin]
		  ,[dbo].[ti_ItemInfo].[AbilityMax]
		  ,[dbo].[ti_ItemInfo].[ReqRace]
		  ,[dbo].[ti_ItemInfo].[ReqAttackPart]
		  ,[dbo].[ti_ItemInfo].[ReqDefensePart]
		  ,[dbo].[ti_ItemInfo].[ReqFuelPart]
		  ,[dbo].[ti_ItemInfo].[ReqSoulPart]
		  ,[dbo].[ti_ItemInfo].[ReqShieldPart]
		  ,[dbo].[ti_ItemInfo].[ReqDodgePart]
		  ,[dbo].[ti_ItemInfo].[ReqUnitKind]
		  ,[dbo].[ti_ItemInfo].[ReqMinLevel]
		  ,[dbo].[ti_ItemInfo].[ReqMaxLevel]
		  ,[dbo].[ti_ItemInfo].[ReqItemKind]
		  ,[dbo].[ti_ItemInfo].[Weight]
		  ,[dbo].[ti_ItemInfo].[HitRate]
		  ,[dbo].[ti_ItemInfo].[Defense]
		  ,[dbo].[ti_ItemInfo].[FractionResistance]
		  ,[dbo].[ti_ItemInfo].[NaturalFaction]
		  ,[dbo].[ti_ItemInfo].[SpeedPenalty]
		  ,[dbo].[ti_ItemInfo].[Range]
		  ,[dbo].[ti_ItemInfo].[Position]
		  ,[dbo].[ti_ItemInfo].[Scarcity]
		  ,[dbo].[ti_ItemInfo].[Endurance]
		  ,[dbo].[ti_ItemInfo].[AbrasionRate]
		  ,[dbo].[ti_ItemInfo].[Charging]
		  ,[dbo].[ti_ItemInfo].[Luck]
		  ,[dbo].[ti_ItemInfo].[MinTradeQuantity]
		  ,[dbo].[ti_ItemInfo].[Price]
		  --,[dbo].[ti_ItemInfo].[CashPrice]
		  , CASE 
				WHEN [dbo].[ti_OverlapItem].[CashPrice] != -1 THEN [dbo].[ti_OverlapItem].[CashPrice]
				ELSE [dbo].[ti_ItemInfo].[CashPrice]
			END AS CashPrice
		  ,[dbo].[ti_ItemInfo].[DestParameter1]
		  ,[dbo].[ti_ItemInfo].[ParameterValue1]
		  ,[dbo].[ti_ItemInfo].[DestParameter2]
		  ,[dbo].[ti_ItemInfo].[ParameterValue2]
		  ,[dbo].[ti_ItemInfo].[DestParameter3]
		  ,[dbo].[ti_ItemInfo].[ParameterValue3]
		  ,[dbo].[ti_ItemInfo].[DestParameter4]
		  ,[dbo].[ti_ItemInfo].[ParameterValue4]
		  ,[dbo].[ti_ItemInfo].[DestParameter5]
		  ,[dbo].[ti_ItemInfo].[ParameterValue5]
		  ,[dbo].[ti_ItemInfo].[DestParameter6]
		  ,[dbo].[ti_ItemInfo].[ParameterValue6]
		  ,[dbo].[ti_ItemInfo].[DestParameter7]
		  ,[dbo].[ti_ItemInfo].[ParameterValue7]
		  ,[dbo].[ti_ItemInfo].[DestParameter8]
		  ,[dbo].[ti_ItemInfo].[ParameterValue8]
		  ,[dbo].[ti_ItemInfo].[ReAttacktime]
		  ,[dbo].[ti_ItemInfo].[Time]
		  ,[dbo].[ti_ItemInfo].[RepeatTime]
		  ,[dbo].[ti_ItemInfo].[Material]
		  ,[dbo].[ti_ItemInfo].[ReqMaterial]
		  ,[dbo].[ti_ItemInfo].[RangeAngle]
		  ,[dbo].[ti_ItemInfo].[UpgradeNum]
		  ,[dbo].[ti_ItemInfo].[LinkItem]
		  ,[dbo].[ti_ItemInfo].[MultiTarget]
		  ,[dbo].[ti_ItemInfo].[ExplosionRange]
		  ,[dbo].[ti_ItemInfo].[ReactionRange]
		  ,[dbo].[ti_ItemInfo].[ShotNum]
		  ,[dbo].[ti_ItemInfo].[MultiNum]
		  ,[dbo].[ti_ItemInfo].[AttackTime]
		  ,[dbo].[ti_ItemInfo].[ReqSP]
		  --,[dbo].[ti_ItemInfo].[SummonMonster]
		  , CASE 
				WHEN [dbo].[ti_OverlapItem].[Tab] != -1 THEN [dbo].[ti_OverlapItem].[Tab]
				ELSE [dbo].[ti_ItemInfo].[SummonMonster]
			END AS SummonMonster
		  ,[dbo].[ti_ItemInfo].[NextSkill]
		  ,[dbo].[ti_ItemInfo].[SkillLevel]
		  ,[dbo].[ti_ItemInfo].[SkillHitRate]
		  ,[dbo].[ti_ItemInfo].[SkillType]
		  ,[dbo].[ti_ItemInfo].[SkillTargetType]
		  ,[dbo].[ti_ItemInfo].[Caliber]
		  ,[dbo].[ti_ItemInfo].[OrbitType]
		  --,[dbo].[ti_ItemInfo].[ItemAttribute]
		  , CASE 
				WHEN [dbo].[ti_OverlapItem].[ItemAttribute] != -1 THEN [dbo].[ti_OverlapItem].[ItemAttribute]
				ELSE [dbo].[ti_ItemInfo].[ItemAttribute]
			END AS ItemAttribute      
		  ,[dbo].[ti_ItemInfo].[BoosterAngle]
		  ,[dbo].[ti_ItemInfo].[CameraPattern]
		  ,[dbo].[ti_ItemInfo].[SourceIndex]
		  ,[dbo].[ti_ItemInfo].[Description]
		  ,[dbo].[ti_ItemInfo].[EnchantCheckDestParam]
		  ,[dbo].[ti_ItemInfo].[InvokingDestParamID]
		  ,[dbo].[ti_ItemInfo].[InvokingDestParamIDByUse]
		FROM [dbo].[ti_ItemInfo] LEFT JOIN [dbo].[ti_OverlapItem] 
		ON [dbo].[ti_ItemInfo].[ItemNum] = [dbo].[ti_OverlapItem].[ItemNum]
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_EnchantInfo
-- DESC      : Enchant ���� ����
-- 2005-08-02 by cmkwon, ��æƮ �ִ� 9������ 40���� �ø�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_EnchantInfo (
	EnchantItemNum			INT	NOT NULL,	-- enchant�� ���� �������� ItemNum	--REFERENCES ti_Item(ItemNum)
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
-- TABLE NAME:	ti_ItemMixingInfo
-- DESC      :	������ ���� ����
--				// 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemMixingInfo 
(
	UniqueID			INT	NOT NULL	PRIMARY KEY,	-- UID		// 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo
	TargetItemNum		INT	NOT NULL,					-- �ϼ��� ��� ItemNum		--REFERENCES ti_Item(ItemNum)
	MixingProbability	INT	NOT NULL,					-- ���۵� Ȯ��(1~10000)
	MixingCost			INT	NOT NULL,					-- ��� ������ ���� ������
	[Visible]			TINYINT NOT NULL DEFAULT 1		--> 130605_DB��Ű��_02_(�����۹̸�����)_DBQuery(atum2_db_account)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME:	ti_ItemMixingElement
-- DESC      :	������ ���� ���� (��ҵ�)
--				// 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemMixingElement
(
	UniqueID			INT	NOT NULL,	-- UID						--REFERENCES ti_ItemMixingInfo(UniqueID)
	SourceItemNum		INT	NOT NULL,	-- �ʿ��� ��� ItemNum		--REFERENCES ti_Item(ItemNum)
	SourceItemCount		INT	NOT NULL,	-- �ʿ��� ����
)
GO

CREATE CLUSTERED INDEX idx_on_ti_ItemMixingElement ON ti_ItemMixingElement(UniqueID, SourceItemNum)
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
	MonsterItem01		INT,		--REFERENCES ti_Item(ItemNum),
	MonsterItem02		INT,		--REFERENCES ti_Item(ItemNum),
	MonsterItem03		INT,		--REFERENCES ti_Item(ItemNum),
	MonsterItem04		INT,		--REFERENCES ti_Item(ItemNum),
	MonsterItem05		INT,		--REFERENCES ti_Item(ItemNum),
	MonsterItem06		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem07		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem08		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem09		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem10		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem11		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem12		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem13		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem14		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterItem15		INT,					-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	ControlSkill		INT,		--REFERENCES ti_Item(ItemNum)
	SizeForServer		INT, -- USHORT�� ���
	SizeForClient		INT, -- USHORT�� ���, ������ size���� ����
	Faction				TINYINT,
	MonsterForm			SMALLINT,
	AttackPattern		TINYINT,
	MovePattern			SMALLINT,
	Belligerence		TINYINT,
	Defense				FLOAT,			-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - ���� �ڷ���(TINYINT) ����
	DefenceProbability	FLOAT,			-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - ���� �ڷ���(TINYINT) ����
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
	MPOption			BIGINT,			-- // 2010-01-11 by cmkwon, ���� MPOption 64bit�� ���� - ����(TINYINT)
	MPOptionParam1		TINYINT,
	MPOptionParam2		TINYINT,
	Range				SMALLINT,
	TurnAngle			FLOAT,
	MonsterHabit		TINYINT,
	ClickEvent			TINYINT,				-- 2007-09-12 by dhjin
	HPActionIdx			INT,	--REFERENCES ti_MonsterHPAction(MonsterHPActionNum)	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	MonsterTarget		INT		DEFAULT(0),		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� ��� ��ȣ
	ChangeTarget		TINYINT	DEFAULT(0),		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� ��� Ÿ�ٰ� ���� ����
	MonsterTarget2		INT		DEFAULT(0),		-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���� ���� ���� ��� ��ȣ 2��° �켱 ����
	PortraitFileName	VARCHAR(50),			-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���� �ʻ�ȭ ����
	ChangeTargetTime	INT,					-- // 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ChangeTargetTime �ʵ� �߰�
	WayPointPattern		INT		DEFAULT(0)		-- // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
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
	DropType			INT			-- // 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - DROP_TYPE_XXX
)
-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
-- CREATE UNIQUE CLUSTERED INDEX idx_monsteritem ON ti_MonsterItem(monsteruniqueNumber, itemNum)
-- // 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - DropType �߰�
--CREATE UNIQUE CLUSTERED INDEX idx_monsteritem ON ti_MonsterItem(MonsterUniqueNumber, ItemNum)
CREATE UNIQUE CLUSTERED INDEX idx_monsteritem ON ti_MonsterItem(MonsterUniqueNumber, ItemNum, DropType)
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
	BeforeMapIndex2			INT,					-- // 2008-06-20 by cmkwon, EP3 ��� �ý��� ����(�ʴ� ����� 2�� ���� �� �� �ִ�) - ti_MapInfo ���̺� �ʵ� �߰�
	MapDescription			varchar(1024)		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
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
	SupplyItemCount2			INT,
	WinBossMonsterNum			INT,		-- // 2009-03-10 by dhjin, �ܰ躰 �� �ý���
	LossBossMonsterNum			INT			-- // 2009-03-10 by dhjin, �ܰ躰 �� �ý���
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
	SuffixProbability		INT,					-- ���̻簡 ���� Ȯ��, 0 ~ 100000
    Period					smallint,				-- 2008-11-11 by dhjin, ��Ű�ӽ�, �Ⱓ
	CountPerPeriod			int,					-- 2008-11-11 by dhjin, ��Ű�ӽ�, �Ⱓ�ȿ� ���ü� �ִ� �ִ� ������ ��	
	starttime				datetime				-- 2008-11-11 by dhjin, ��Ű�ӽ�, �Ⱓ ���� ��
)
CREATE CLUSTERED INDEX idx_MysteryItemDropNum_on_MysteryItemDrop ON ti_MysteryItemDrop(MysteryItemDropNum)
GO

-- // 2008-11-05 by cmkwon, MSSQL�� MySQL �������� ���� - �ʿ� ����
-- --------------------------------------------------------------------------------
-- --
-- -- VIEWs
-- --
-- -- ItemCharacterView
-- -- ItemSkillView
-- -- ItemMonsterView
-- --
-- --------------------------------------------------------------------------------
-- DROP VIEW ItemCharacterView
-- GO
-- CREATE VIEW dbo.ItemCharacterView
-- AS
-- 	SELECT *
-- 	FROM ti_Item
-- 	WHERE Kind <= 49
-- GO
-- 
-- DROP VIEW ItemSkillView
-- GO
-- CREATE VIEW dbo.ItemSkillView
-- AS
-- 	SELECT *
-- 	FROM ti_Item
-- 	WHERE Kind >= 50 AND Kind <= 99
-- GO
-- 
-- DROP VIEW ItemMonsterView
-- GO
-- CREATE VIEW dbo.ItemMonsterView
-- AS
-- 	SELECT *
-- 	FROM ti_Item
-- 	WHERE Kind >= 100
-- GO


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
	ServerName					VARCHAR(20),
	PubilsherName				VARCHAR(20)	   -- 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���
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
	UserCount					INT,
	UserCountsOtherPublisherConncect	INT					  -- 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���
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
	ItemEventUID			int        IDENTITY(1,1) PRIMARY KEY,
	ItemEventType			smallint,
	OnlyPCBang				smallint,
	InfluenceType			tinyint,
	ItemNum					int,
	Count					int,
	StartTime				datetime,
	EndTime					datetime,
	MemberShip				bit,
	ReqLevel				TINYINT,			-- 2007-07-23 by dhjin, �������� �̺�Ʈ  
	NewMember				BIT,				-- 2007-07-23 by dhjin, �̺�Ʈ �Ⱓ �ȿ� �ű� ������ ���� ���
	UnitKind				INT,     			-- 2007-07-24 by dhjin, ������ ���� ����
	PrefixCodeNum			INT,				-- 2007-07-25 by dhjin, ������ ���� ���� �ɼ�
	SuffixCodeNum			INT,				-- 2007-07-25 by dhjin, ������ ���� ���� �ɼ�
	UseLastGameEndDate		INT,			-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
	LastGameEndDate			DATETIME,		-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - 
	CheckWithCharacterUID	INT,			-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - dbo.ti_ItemEvent�� �ʵ� �߰�
	LevelMin				INT,
	LevelMax				INT,
	LoginCheckNumber	INT,			-- // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
	UseFixedPeriod		INT,			-- // 2013-02-28 by bckim, �������� �����߰�
	FixedPeriod			INT			-- // 2013-02-28 by bckim, �������� �����߰�
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
CREATE INDEX idx_CharacterUID_on_atum_Log_ItemEvent ON atum_Log_ItemEvent (CharacterUID)		-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - �ε��� �߰�
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
-- 2012-05-23 by jhseol, �Ʒ��� WP �⺻���޷� �ʵ� �߰� - ti_ArenaInfo ���̺� �ʵ� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ArenaInfo(
 ArenaMode				TINYINT,			-- �Ʒ��� ��� 0 : DeathMatch, 1 : Round
 ReqMemberNum			TINYINT,			-- �� �ο� ���� 
 PayInfluencePointWIN 	INT,			-- �¸� ���¿��� ����Ǵ� ��������Ʈ��
 PayInfluencePointLOSE	INT,			-- �й� ���¿��� ����Ǵ� ��������Ʈ��
 PayWarPointWIN			INT,			-- �¸� ������ ����Ǵ� WP��
 PayWarPointLOSE		INT			-- �й� ������ ����Ǵ� WP��
 ,DefaultPayWarPointWIN INT			-- �÷��� Ƚ�� �ʰ��� �¸� ������ ����Ǵ� WP��
 ,DefaultPayWarPointLOSE INT		-- �÷��� Ƚ�� �ʰ��� �й� ������ ����Ǵ� WP��
)
CREATE CLUSTERED INDEX idx_ArenaMode_on_ArenaInfo ON ti_ArenaInfo(ArenaMode)
CREATE INDEX idx_ReqMemberNum_on_ArenaInfo ON ti_ArenaInfo(ReqMemberNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.ti_ArenaMapinfo
-- DESC      : �Ʒ��� �� ����
--		// 2012-09-14 by jhseol, �Ʒ��� �߰����� part3 - �Ʒ��� ���� ������ �߰� (�Ʒ��� ���� ź�� ������ ī��)
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
 LvDSupplyItemCount3	INT,        -- �Ʒ��� ���� ������ 3 �� 
 LvDSupplyItemNum4		INT,        -- �Ʒ��� ���� ������ 4
 LvDSupplyItemCount4	INT			-- �Ʒ��� ���� ������ 4 ��
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

--------------------------------------------------------------------------------
-- TABLE NAME: ti_LuckyMachine
-- DESC      : ��Ű�ӽ� ���� ���� �� �� ���Կ� ���� ����	  
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_LuckyMachine (
	MachineOrder			INT,
	BuildingIndex			INT,			-- �ǹ�(���� ��) ���� ��ȣ
	MachineKind				TINYINT,		-- Slot���� ���´�.
	MachineNum				INT,
	CoinItemNum				INT,
	SlotNum					TINYINT,
	SlotProbability			INT,			-- ���� Ȯ��(��밪���� ó��): 0 ~ 1000000
	MysteryItemDropNum		INT,
	SourceIndex				INT,
	Description				varchar(200) COLLATE Korean_Wansung_CI_AS
)
GO
-- // 2009-09-16 by cmkwon, ��Ű�ӽ� ���� �ӽ� ���� ���� �ذ� - �Ʒ��� ���� ���� 
--CREATE CLUSTERED INDEX idx_LuckyMachine ON ti_LuckyMachine(BuildingIndex)
CREATE CLUSTERED INDEX idx_MachineNum_on_LuckyMachine ON ti_LuckyMachine(MachineNum DESC)	-- // 2009-09-16 by cmkwon, ��Ű�ӽ� ���� �ӽ� ���� ���� �ذ� - �߰�, MachineNum ������������ Ŭ�����͵� �ε��� ����
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_MysteryItemDropCount
-- DESC      : �Ⱓ���� ����� �̽��׸� ������ �� ����	  
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_MysteryItemDropCount (
	MysteryItemDropNum		INT,
	DropItemNum				INT,
	ServerGroupID			INT 		DEFAULT(0),				-- 0(=AllServerGroup), 1(=10061), 2(10062), ...
	DropCount				INT			-- 2008-11-11 by dhjin, ��Ű�ӽ�, �Ⱓ���� ���� ������ ��
)
GO
CREATE CLUSTERED INDEX idx_MysteryItemDropNum_on_MysteryItemDropCount ON td_MysteryItemDropCount(MysteryItemDropNum)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_AdminAutoNoticeInfo
-- DESC      : // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - td_AdminAutoNoticeInfo ���̺� ���� ��ũ��Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AdminAutoNoticeInfo (
	UsingFlag					INT,				-- �ڵ� ���� �ý��� ��뿩�� Flag(FALSE�̸� ���� ����, TRUE�̸� ��� �� ����)
	LoopSec						INT,				-- ������ ���� ��Ʈ���� ������ �ٽ� ó�� ���� ��Ʈ���� ������ ������ interval time(second)
	IntervalSec					INT,				-- each notice string interval time(second)
	EditorAccountName			VARCHAR(20)			-- ������ AccountName	
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_AdminAutoNoticeInfo
-- DESC      : // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - td_AdminAutoNoticeString ���̺� ���� ��ũ��Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AdminAutoNoticeString (
	NoticeStringIndex			INT,				-- �ڵ� ���� ��Ʈ�� �ε�����, �̰����� ���ĵǾ� ������� ���۵ȴ�.
	NoticeString				VARCHAR(256)		-- �ڵ� ���� ��Ʈ��
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_DeclarationOfWarForbidTime
-- DESC      : �������� ���� ���� �ð�	  
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_DeclarationOfWarForbidTime (
	DayOfWeek				INT,
	ForbidStartTime			datetime,
	ForbidEndTime			datetime
)
GO
INSERT INTO dbo.td_DeclarationOfWarForbidTime (DayOfWeek, ForbidStartTime, ForbidEndTime)
	VALUES (5, '2009-01-01 06:00:00', '2009-01-01 12:00:00')
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_CashShop
-- DESC      : // 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - td_CashShop ���̺� ���� ��ũ��Ʈ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_CashShop (
	ItemNum							INT	NOT NULL,	-- ti_Shop �� �־������ �����
	CashShopBit						TINYINT,		-- CASHSHOP_BIT_XXX ����
	RemainCountForLimitedEdition	INT				-- // 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - 
)
GO
CREATE UNIQUE INDEX idx_ItemNum_on_td_CashShop ON td_CashShop(ItemNum)
GO


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_selfServiceInfo
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - td_wrk_selfServiceInfo ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_selfServiceInfo(
	ServiceUID			INT,
	ServiceName			VARCHAR(20),
	ServiceSymbolImage	BINARY(2000),		-- 48x28x
	SymbolImageSize		INT		-- 48x28x
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_allServiceInfo
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - td_wrk_allServiceInfo ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_allServiceInfo(
	ServiceUID			INT,
	ServiceName			VARCHAR(20),
	ServiceSymbolImage	BINARY(2000),		-- 48x28x
	SymbolImageSize		INT		-- 48x28x
)
CREATE UNIQUE CLUSTERED INDEX idx_ServiUID_on_td_wrk_allServiceInfo ON td_wrk_allServiceInfo(ServiceUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_level
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - td_wrk_level ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_level(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	Experience				FLOAT,
	LevelUpTime				DATETIME
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrk_level ON td_wrk_level(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrk_level ON td_wrk_level(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrk_level ON td_wrk_level(ServerGroupID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_frame
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - td_wrk_frame ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_fame(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	Fame					INT
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrk_fame ON td_wrk_fame(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrk_fame ON td_wrk_fame(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrk_fame ON td_wrk_fame(ServerGroupID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrk_pvp
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - dbo.td_wrk_pvp ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrk_pvp(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	WinPoint				INT,
	LossPoint				INT,
	Score					INT
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrk_pvp ON td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrk_pvp ON td_wrk_pvp(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrk_pvp ON td_wrk_pvp(ServerGroupID)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: ti_QuestMatching
-- DESC      : // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - ti_QuestMatching ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_QuestMatching(
	QuestIndexForBCU		INT,
	QuestIndexForANI		INT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_QuestMatching
-- DESC      : // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - ti_ItemMatching ���̺� �߰�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemMatching(
	ItemNumForBCU			INT,
	ItemNumForANI			INT
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfluenceRate
-- DESC      : // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfluenceRate(
	StartLevel				TINYINT NOT NULL,
	EndLevel				TINYINT NOT NULL
)
CREATE CLUSTERED INDEX idx_StartLv_on_ti_InfluenceRate ON ti_InfluenceRate(StartLevel)
CREATE UNIQUE INDEX idx_StartLv_EndLv_on_ti_InfluenceRate ON ti_InfluenceRate(StartLevel, EndLevel)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: ti_HPAction
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : HP�� ���� ���� �ൿ ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_HPAction (
	HPActionUID					INT				PRIMARY KEY,
	HPActionNum					INT				NOT NULL,
	HPMaxValueRate				TINYINT			NOT NULL,
	HPMinValueRate				TINYINT			NOT NULL,
	UseItemArrayIdx				INT				DEFAULT(0),		--REFERENCES ti_MonsterItem(MonsterItem01~15)
	NextUseItemArrayIdx			INT				DEFAULT(0),		--REFERENCES ti_MonsterItem(MonsterItem01~15)
	HitRate						TINYINT			DEFAULT(0),
	UseCount					INT				DEFAULT(0),
	HPTalkCondition				TINYINT			DEFAULT(0),
	HPTalkImportance			TINYINT			DEFAULT(0),
	PreHPCameraTremble			INT				DEFAULT(0),	-- msec	
	PreHPTalk					VARCHAR(100),
	HPCameraTremble				INT				DEFAULT(0),	-- msec	
	HPTalk						VARCHAR(100)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Cinema
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Cinema (
	CinemaNum			INT				NOT NULL,
	CinemaOrder			INT				NOT NULL,	-- 51000 : ���� ���� �ó׸�, 52000 : ���� ���� �ó׸�
	StartTime			INT				DEFAULT(0),	-- msec
	EffectIdx			INT				DEFAULT(0),
	EffectPosition_X	FLOAT			DEFAULT(0),
	EffectPosition_Y	FLOAT			DEFAULT(0),
	EffectPosition_Z	FLOAT			DEFAULT(0),
	EffectPlayTime		INT				DEFAULT(0),	-- msec	
	EffectPlayCount		INT				DEFAULT(0),
	ObjectIdx			INT				DEFAULT(0),
	ChangeObjectIdx		INT				DEFAULT(0),
	ChangeTime			INT				DEFAULT(0),	-- msec	
	CameraTremble		INT				DEFAULT(0),	-- msec
	KeyMonster			TINYINT			DEFAULT(0),
	MonsterIdx			INT				DEFAULT(0),
	SummonCount			INT				DEFAULT(1),
	SummonRandomPos		INT				DEFAULT(0), -- M
	ObjectBodyConditionIdx	INT			DEFAULT(0),
	BodyCondition		BIGINT			DEFAULT(0),
	TipFileName			VARCHAR(50),
	SkyFileName			VARCHAR(50),
	CinemaTalk			VARCHAR(100),
	SoundFileName		VARCHAR(50),				-- // 2010-03-29 by cmkwon, ����2�� �ó׸��� ȿ���� ���� ���� �߰� - 
	MonsterIdxType		INT				DEFAULT(0),	-- // 2011-03-17 by hskim, ���Ǵ�Ƽ 3��
	CustomIdx			INT				DEFAULT(0),	-- // 2011-03-17 by hskim, ���Ǵ�Ƽ 3��
	UpdateMonsterIdx	INT				DEFAULT(0),	-- // 2011-03-17 by hskim, ���Ǵ�Ƽ 3��
	QuestIndex			INT				DEFAULT(0)	-- // 2011-03-17 by hskim, ���Ǵ�Ƽ 3��
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfinityMonster
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���Ǵ�Ƽ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfinityMonster (
	InfinityMonsterUID		INT			NOT NULL	PRIMARY KEY,
	InfinityMonsterIdx		INT			NOT NULL,
	MonsterIdx				INT			NOT NULL,
	TargetType				TINYINT		DEFAULT(0),
	TargetCount				TINYINT		DEFAULT(0)	
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Revision
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���� ����ġ
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Revision (
	RevisionNum					INT				NOT NULL,
	UnitKind					INT				NOT NULL,
	RevisionLevel				TINYINT			NOT NULL,
	RevisionHP					SMALLINT		NOT NULL,
	RevisionDP					SMALLINT		NOT NULL,
	RevisionStandardWeapon		INT				NOT NULL,
	RevisionAdvancedWeapon		INT				NOT NULL
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfinityMode
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���Ǵ�Ƽ ����
--				//2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰� (HP �� �ð� ���� ������ ����)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfinityMode (
	InfinityModeUID			INT			NOT NULL	PRIMARY KEY,
	MapIdx					INT			NOT NULL,
	ModeTypeNum				TINYINT		NOT NULL,		-- 1. ��������, 2. �������
	InfinityMonsterIdx		INT			DEFAULT(0),		--REFERENCES ti_InfinityMonster(InfinityMonsterIdx)
	CinemaNum				INT			DEFAULT(0),		--REFERENCES ti_Cinema(CinemaNum)
	RevisionNum				INT			DEFAULT(0),		--REFERENCES ti_InfinityRevision(RevisionNum)
	ResetCycle				TINYINT		NOT NULL,
	EntranceCount			TINYINT		NOT NULL,
	LimitTime				INT			DEFAULT(0),
	MinLv					TINYINT		NOT NULL,
	MaxLv					TINYINT		NOT NULL,
	MinAdmissionCount		TINYINT		NOT NULL,
	MaxAdmissionCount		TINYINT		NOT NULL,
	TimePenaltyValue		INT			DEFAULT(0),		-- min
	HPPenaltyValue			INT			DEFAULT(0)		-- //2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰� (HP �� �ð� ���� ������ ����)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Tender
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���Ǵ�Ƽ ������ ����  ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_Tender (
	TenderUID				INT			NOT NULL	PRIMARY KEY,
	TenderItemNum			INT			NOT NULL,
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_InfinityShop
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : ���Ǵ�Ƽ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InfinityShop (
	InfinityShopUID			INT			NOT NULL	PRIMARY KEY,
	BuyItemNum				INT			NOT NULL,
	BuyItemCount			INT,
	TradeItemNum1			INT			NOT NULL,
	TradeItemCount1			INT,
	TradeItemNum2			INT,
	TradeItemCount2			INT,
	TradeItemNum3			INT,
	TradeItemCount3			INT,
	TradeItemNum4			INT,
	TradeItemCount4			INT,
	TradeItemNum5			INT,
	TradeItemCount5			INT
)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: ti_ItemParamOverlap
-- DESC		 : // 2010-01-18 by cmkwon, ������ ���� Parameter �ߺ� üũ �ý��� ���� - 
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_ItemParamOverlap (
	ItemNum					INT			NOT NULL,
	OverlapIndex			INT
)
GO
CREATE UNIQUE CLUSTERED INDEX ItemNum8OverlapIndex_on_ItemParamOverlap ON ti_ItemParamOverlap(OverlapIndex, ItemNum)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_InvokingWearItemDPNum
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : �ߵ��� ���� ������ ���� DestParam ��
-- DESC      : // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InvokingWearItemDPNum (
	InvokingDestParamID			INT				NOT NULL,
	InvokingDestParam			SMALLINT		NOT NULL,	-- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	InvokingDestParamValue		FLOAT,
	InvokingEffectIdx			INT
)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: ti_InvokingWearItemDPNumByUse
-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
-- DESC      : �ߵ��� ���� ������ ��� DestParam ��
-- DESC      : -- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_InvokingWearItemDPNumByUse (
	InvokingDestParamIDByUse		INT				NOT NULL,
	InvokingDestParamByUse			SMALLINT		NOT NULL,	-- // 2011-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	InvokingDestParamValueByUse		FLOAT,
	InvokingEffectIdxbyUse			INT
)
GO		


--------------------------------------------------------------------------------
-- TABLE NAME: ti_LevelAdjustment
-- DESC      : // 2010-05-27 by shcho ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ���̵� ���� ���̺�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_LevelAdjustment
(
	IncreaseStep		INT,
	MonsterHP		INT,
	MonsterDefense		INT,
	MonsterEvasion		INT,
	MonsterAttackItem	INT,
	MonsterPopulation	INT
);
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_LevelAdjustmentReward
-- DESC      : // 2010-05-27 by shcho ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ������ ���̺�
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_LevelAdjustmentReward
(
	IncreaseStep			INT,
	IncreaseIncomeExp		INT,
	IncreaseIncomeDropProbabillity	INT,
	IncreaseIncomeDropCount		INT
);
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_BurningMap
-- DESC      : ���׸� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_BurningMap (
	BuringMapUID		INT		PRIMARY KEY,		-- UID
	MapIndex		INT		NOT NULL,		-- �� ��ȣ
	ReqUnitKind		INT		DEFAULT(65535),		-- ���� ������ ��� ����
	ReqMinLv		TINYINT		DEFAULT(1),		-- ���� ���� �ּ� ����
	ReqMaxLv		TINYINT		DEFAULT(100)		-- ���� ���� �ִ� ����
)
Go

--------------------------------------------------------------------------------
-- TABLE NAME: ti_PetLevel
-- DESC      : // 2010-06-15 by shcho&hslee ��ý��� - �⺻ ���� ���̺� �߰� ����
-- DESC		 : // 2011-08-30 by hskim, ��Ʈ�� �ý��� 2�� : ������ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[ti_PetLevel]
(
	[PetIndex]			INT		NOT NULL,
	[Level]				INT		NOT NULL,
	[NeedExp]			FLOAT	NOT NULL,
	[UseWeaponIndex]	INT		NOT NULL,
	[SlotCountSkill]	TINYINT	NOT NULL,
	[SlotCountSocket]	TINYINT	NOT NULL,
	[KitLevelHP]		TINYINT	NOT NULL,
	[KitLevelShield]	TINYINT	NOT NULL,
	[KitLevelSP]		TINYINT	NOT NULL
)
GO

CREATE INDEX [idx_ti_PetLevel_PetIndex] ON [ti_PetLevel] (PetIndex)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_Pet
-- DESC      : // 2010-06-15 by shcho&hslee ��ý��� - �⺻ ���� ���̺� �߰� ����
-- DESC		 : // 2011-08-30 by hskim, ��Ʈ�� �ý��� 2�� : ������ ���� ����
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[ti_pet]
(
	[PetIndex]			INT PRIMARY KEY	NOT NULL,
	[PetKind]			INT				NOT NULL,
	[EnableName]		SMALLINT		NOT NULL,
	[EnableLevel]		SMALLINT		NOT NULL,
	[PetName]			VARCHAR(40)		NOT NULL,
	[MaxLevel]			SMALLINT		NOT NULL,
	[BaseSocketCount]	TINYINT			NOT NULL
)
GO
--------------------------------------------------------------------------------
-- TABLE NAME: ti_OperatorAction 
-- DESC      : // 2010-06-15 by shcho&hslee ��ý��� - ���۷����� ���̺� (�������� ������)
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_OperatorAction 
(
	ActionType INT		NOT NULL ,
	ItemNum INT		NOT NULL ,
	FunctionIndex INT	NOT NULL ,
	FunctionValue FLOAT	NOT NULL ,
	SourceIndex INT		NOT NULL ,
	ActionDesc VARCHAR(128) 
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: ti_DissoulutionItem
-- DESC      : ���� ������ ���� ���̺�
-- // 2010-08-31 by shcho&jskim �����ۿ��� �ý��� -
--------------------------------------------------------------------------------
CREATE TABLE ti_DissolutionItem
(
	SourceItemnum		INT NOT NULL,	-- Item�ѹ�
	
	ResultItemNum1		INT NOT NULL,	-- ���� ��� ������ ��ȣ1
	ResultItemMinCount1	INT NOT NULL,	-- ���� ��� ������ �ּ� ����1
	ResultItemMaxCount1	INT NOT NULL,	-- ���� ��� ������ �ִ� ����1
	ResultItemProbabillity1	INT NOT NULL,	--�������� ���� Ȯ��1
	
	ResultItemNum2		INT NOT NULL,	-- ���� ��� ������ ��ȣ2
	ResultItemMinCount2	INT NOT NULL,	-- ���� ��� ������ �ּ� ����2
	ResultItemMaxCount2	INT NOT NULL,	-- ���� ��� ������ �ִ� ����2
	ResultItemProbabillity2	INT NOT NULL,	--�������� ���� Ȯ��2

	ResultItemNum3		INT NOT NULL,	-- ���� ��� ������ ��ȣ3
	ResultItemMinCount3	INT NOT NULL,	-- ���� ��� ������ �ּ� ����3
	ResultItemMaxCount3	INT NOT NULL,	-- ���� ��� ������ �ִ� ����3
	ResultItemProbabillity3	INT NOT NULL,	--�������� ���� Ȯ��3
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME:	ti_MonsterMultiTarget
-- DESC      :	���Ǵ�Ƽ 3�� ���� ���̺�
-- // 2011-03-17 by hskim, ���Ǵ�Ƽ 3��
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[ti_MonsterMultiTarget](
	[MonsterIndex]		[int]		NULL,
	[PointIndex]		[int]		NULL,
	[x]					[float]		NULL,
	[y]					[float]		NULL,
	[z]					[float]		NULL
) ON [PRIMARY]
GO

--------------------------------------------------------------------------------
-- TABLE NAME:	ti_WayPointMove, ti_WayPoint
-- DESC      :	���Ǵ�Ƽ 3�� - ��������Ʈ ����
--		2011-05-23 by hskim, ���̺� ����
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[ti_WayPointMove](
	[PatternIndex]		[int]		NULL,
	[CompletionAction]	[tinyint]	NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[ti_WayPoint](
	[PatternIndex]		[int]		NULL,
	[SequenceNum]		[int]		NULL,
	[PostionAttribute]	[tinyint]	NULL,
	[X]					[float]		NULL,
	[Y]					[float]		NULL,
	[Z]					[float]		NULL
) ON [PRIMARY]
GO

--------------------------------------------------------------------------------
-- TABLE NAME:	td_LoginEvent
-- DESC      :	�α��� �̺�Ʈ ����
--		// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
--------------------------------------------------------------------------------

CREATE TABLE [dbo].[td_LoginEvent] 
(
	[EventUniqueNumber] [int] NULL ,
	[AccountUniqueNumber] [int] NULL ,
	[CompleteFlag] [int] NULL 
) ON [PRIMARY]
GO

--------------------------------------------------------------------------------
-- TABLE NAME	:	ti_MapBuff, ti_MapTrigger, ti_TriggerFunctionCrystal, ti_TriggerCrystalGroup, 
--					ti_TriggerCrystalDestroyGroup, ti_TriggerFunctionNGCInflWar, ti_TriggerNGCInflWarMonsterGroup
-- DESC			:	// 2011-10-10 by hskim, EP4 [Ʈ���� �ý���] - ȭ���� / �� ��ǳ
--					// 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
--------------------------------------------------------------------------------

CREATE TABLE [dbo].[ti_MapBuff]
(
	[MapIndex] [int] NOT NULL,
	[ItemNum] [int] NOT NULL
)
GO

CREATE TABLE [dbo].[ti_MapTrigger]
(
	[MapTriggerID]		INT			PRIMARY KEY	NOT NULL,
	[MapIndex]			INT						NOT NULL,
	[MapChannel]		SMALLINT				NOT NULL,
	[FunctionID]		INT						NOT NULL
)
GO

CREATE TABLE [dbo].[ti_TriggerFunctionCrystal]
(
	[FunctionID]		INT						NOT NULL,
	[CrystalGroupID]	INT						NOT NULL,
	[PeriodTime]		INT						NOT NULL DEFAULT 60,
	[RandomSequence]	TINYINT					NOT NULL DEFAULT 0
)
GO

CREATE TABLE [dbo].[ti_TriggerCrystalGroup]
(
	[CrystalGroupID]	INT						NOT NULL,
	[DestroyGroupID]	INT						NOT NULL,
	[EventID]			INT						NOT NULL
)
GO

CREATE TABLE [dbo].[ti_TriggerCrystalDestroyGroup]
(
	[DestroyGroupID]	INT						NOT NULL,
	[SequenceNumber]			SMALLINT		NOT NULL,
	[TargetMonster]		INT						NOT NULL
)
GO

CREATE TABLE [dbo].[ti_TriggerFunctionNGCInflWar]
(
	[FunctionID]			INT						NOT NULL,
	[NGCInflWarGroupID]		INT						NOT NULL,
	[PeriodTime]			INT						NOT NULL,
	[BossMonster]			INT						NOT NULL,
	[WinInfluenceWP]		INT						NOT NULL,
	[LossInfluenceWP]		INT						NOT NULL,
	[FirstDamageGuildWP]	INT						NOT NULL,
	[FixedTimeType]			INT						NOT NULL DEFAULT 0
)
GO

CREATE TABLE [dbo].[ti_TriggerNGCInflWarMonsterGroup]
(
	[NGCInflWarGroupID]		INT						NOT NULL,
	[Monster]				INT						NOT NULL,
	[SummonCount]			INT						NOT NULL,
	[SummonRandmomPos]		INT						NOT NULL
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME	:	ti_SystemEvent
-- DESC			:	// 2011-12-21 by hskim, EP4 [������ 1ȸ ���]
--					0 : ������ 1ȸ ��� ���� �ð�
--------------------------------------------------------------------------------

CREATE TABLE [dbo].[ti_SystemEvent]
(
	[ID]		INT			PRIMARY KEY		NOT NULL,
	[Date]		DATETIME					NULL
)
GO

INSERT INTO [atum2_db_account].[dbo].[ti_SystemEvent] ([ID], [Date]) VALUES (0, getdate())		-- ���� �̴� �ð��� �������� ������ ��� ���� ����
GO


--> 121014_DB��Ű��_(�޽İ���ġ)_DBQuery(atum2_db_account)
--------------------------------------------------------------------------------
-- TABLE NAME: ti_AdditionalExperience
-- DESC      : �߰� ����ġ �ý��� �� ���̺�
--			   // 2012-10-07 by hskim, �޽� ����ġ
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_AdditionalExperience 
(
	AccountUniqueNumber		INT		PRIMARY KEY,	-- UID
	RestExperienceCount		INT		NOT NULL		-- �޽� ����ġ ������ ����
)
Go

--> 130205_DB��Ű��_(ĳ������õ�Ǿ����ۼ�����Ʈ��)_DBQuery(atum2_db_account)
-- [atum2_db_account]
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [td_CashShop_Realignment_Index]
-- DESC				: ��� ĳ���� ��õ�� ������ ���� ��Ʈ�� 
-- // 2013-02-05 by bckim, ĳ�ü� ��õ�� ���ļ����ο�
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_CashShop_Realignment_Index](
	[ItemNum] [int] NOT NULL,
	[CashShopBit] [tinyint] NOT NULL,
	[RealignmentIndex] [int] NOT NULL
) ON [PRIMARY]

GO

ALTER TABLE [dbo].[td_CashShop_Realignment_Index] ADD  DEFAULT ((0)) FOR [RealignmentIndex]
GO

-- �ʱⵥ���ͻ��� 
INSERT INTO [dbo].[td_CashShop_Realignment_Index] ([ItemNum],[CashShopBit],[RealignmentIndex]) 
	SELECT cs.ItemNum, cs.CashShopBit, 0 FROM [dbo].[td_CashShop] cs JOIN [dbo].[ti_Shop] s ON cs.CashShopbit = 48 OR cs.CashShopBit = 16 
	WHERE cs.ItemNum = s.ItemNum ORDER BY s.ShopOrder

-- �ʱⵥ���� �����ο� (�� �ؾ� �ϴ��� ��� )
DECLARE temp_cursor CURSOR LOCAL FOR SELECT ItemNum FROM [td_CashShop_Realignment_Index]
OPEN temp_cursor;

DECLARE @realignment int
DECLARE @itemnum int

SET @realignment = 0
FETCH NEXT FROM temp_cursor INTO @itemnum
WHILE @@FETCH_STATUS = 0
	BEGIN
		UPDATE [td_CashShop_Realignment_Index] SET RealignmentIndex = @realignment WHERE ItemNum = @itemnum
		FETCH NEXT FROM temp_cursor INTO @Itemnum;
		SET @realignment = @realignment + 1; 
	END

CLOSE temp_cursor;
DEALLOCATE temp_cursor;
GO

--> 130323_DB��Ű��_02_(NGC �������� Ʈ����)_DBQuery(atum2_db_account)
--------------------------------------------------------------------------------
-- TABLE NAME	:	dbo.ti_TriggerFunctionNGCOutPost 
-- DESC			:	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_TriggerFunctionNGCOutPost(
	FunctionID			INT,	-- Ʈ���� ID
	NGCInflWarGroupID	INT,	-- ��ȯ ���� �׷� ID
	StandardOutPostMap	INT,	-- Ʈ���� �ߵ� ������ �� ���������� ��
	BossMonster			INT,	-- ��������
	WinInfluenceWP		INT,	-- �¸����� ���� WP
	LossInfluenceWP		INT,	-- �й輼�� ���� WP
	NextOutPostMap		INT,	-- Ʈ���� �ߵ��� ����� �������� ��
	DestroyCrystalcount	INT		-- �ı��ؾ��ϴ� ũ����Ż�� ��
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME	:	dbo.ti_TriggerOutPostBossKill 
-- DESC			:	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_TriggerOutPostBossKill(
	BossMonster			INT,	-- ���� ���� ��ȣ
	CrystalNum			INT,	-- ũ����Ż ��ȣ
	RegenMinTimeMinutes	INT,	-- ���� �ּҽð�(��)
	RegenMaxTimeMinutes	INT		-- ���� �ִ�ð�(��)
)
GO

--------------------------------------------------------------------------------
-- TABLE NAME	:	dbo.ti_TriggerCrystalBuff
-- DESC			:	// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE TABLE dbo.ti_TriggerCrystalBuff(
	FunctionID			INT,	-- Ʈ���� ID
	SkillItemNum		INT		-- ���� ������ ��ȣ
)
GO

--> 130329_DB��Ű��_02_(������ �̺�Ʈ ����Ÿ��)_DBQuery(atum2_db_account)
--------------------------------------------------------------------------------
-- TABLE NAME	:	dbo.td_ItemEventSubType 
-- DESC			:	-- // 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_ItemEventSubType(
	ItemEventUID		INT,
	SubEventType		BIT,
	Param1				SMALLINT,
	Value1				INT,
	Param2				SMALLINT,
	Value2				INT,
	Param3				SMALLINT,
	Value3				INT
)
GO

--> 130617_DB��Ű��_02_(�̴��ǾƸ�)_DBQuery(atum2_db_account)
------------------------------------------------------------------------------------------------
-- 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
------------------------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_MonthlyArmorEvent](
	[EventUID] [int] IDENTITY(1,1) NOT NULL,
	[StartDate] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[ArmorItemNum] [int] NULL,
	[ArmorSourceIndex] [int] NULL,
	[OptionItemNum] [int] NULL,
	[Duration] INT DEFAULT 0
PRIMARY KEY CLUSTERED 
(
	[EventUID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
