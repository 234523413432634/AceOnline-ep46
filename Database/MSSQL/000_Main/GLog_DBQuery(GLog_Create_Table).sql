--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Account
-- DESC      : ���� ���� �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_Account]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_Account]
GO
CREATE TABLE [dbo].[GLog_Account] (
 [UID]   [bigint]   IDENTITY (1, 1) NOT NULL PRIMARY KEY,
 [AccountName] [nvarchar] (128) NOT NULL ,   -- ���� �̸�
 [GamePublisher] [nvarchar] (128) NOT NULL ,   -- ���Ӽ��񽺻� �̸�
 [GameName]  [nvarchar] (128) NOT NULL ,   -- ���� �̸�
 [GameServerIP] [nvarchar] (64)  NOT NULL ,   -- ���Ӽ���IP (�������� ǥ�ø� ����(ex:�ѱ�,�̱����))
 [Birthday]  [nvarchar] (64)  NULL ,    -- ���� �������
 [Sex]   [bit]    NOT NULL DEFAULT(0) ,    -- ���� ���� // 0 : ����, 1 : ����
 [RegDate]  [datetime]   NOT NULL,   -- ���� ���� ��¥
 [GLogUpdated] [bit]    NOT NULL DEFAULT(0) -- GLog DB�� ������Ʈ �Ǿ����� üũ�ϴ� ��Ʈ, 0 : ������Ʈ ��, 1: ������Ʈ ��
)
CREATE UNIQUE INDEX idx_on_GLog_Account ON GLog_Account(AccountName, GamePublisher, GameName, RegDate)
CREATE INDEX idx_GLog_Account_RegDate on GLog_Account(RegDate) 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_BuyCashItem
-- DESC      : ���� ������ ���� �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_BuyCashItem]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_BuyCashItem]
GO
CREATE TABLE [dbo].[GLog_BuyCashItem] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[AccountName]		[nvarchar] (128)	NOT NULL ,		-- ���� �̸�
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,		-- ���Ӽ��񽺻� �̸�
	[GameName]			[nvarchar] (128)	NOT NULL ,		-- ���� �̸�
	[CharacterName]		[nvarchar] (128)	NOT NULL ,		-- ������ �ɸ��� �̸�
	[CharacterLevel]	[int]				NOT NULL ,		-- ������ �ɸ��� ����
	[ItemName]			[nvarchar] (128)	NOT NULL ,		-- ������ ������ �̸�
	[CashCost]			[int]				NOT NULL ,		-- ������ ������ ���� ���� ����
	[ItemCount]			[int]				NOT NULL ,		-- ������ ������ ��
	[BuyDate]			[datetime]			NOT NULL		-- ���� ��¥
)
CREATE UNIQUE INDEX idx_on_GLog_BuyCashItem ON GLog_BuyCashItem(AccountName, GamePublisher, GameName, BuyDate)
CREATE INDEX idx_GLog_BuyCashItem_CharacterLevel on GLog_BuyCashItem(CharacterLevel)
CREATE INDEX idx_GLog_BuyCashItem_BuyDate on GLog_BuyCashItem(BuyDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_CharacterPlayTime
-- DESC      : �ɸ��� �÷��� ����� ���� �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_CharacterPlayTime]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_CharacterPlayTime]
GO
CREATE TABLE [dbo].[GLog_CharacterPlayTime] (
	[UID]					[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[AccountName]			[nvarchar] (128)	NOT NULL ,		-- ���� �̸�
	[GamePublisher]			[nvarchar] (128)	NOT NULL ,		-- ���Ӽ��񽺻� �̸�
	[GameName]				[nvarchar] (128)	NOT NULL ,		-- ���� �̸�
	[GameServerName]		[nvarchar] (128)	NOT NULL ,		-- ���Ӽ��� �̸�
	[CharacterName]			[nvarchar] (128)	NOT NULL ,		-- ������ �ɸ��� �̸�
	[LoginDate]				[datetime]			NOT NULL ,		-- �ɸ��� ���� ��¥
	[LogoutDate]			[datetime]			NOT NULL ,		-- �ɸ��� ���� ��¥
	[TotalPlayTime]			[bigint]			NOT NULL ,		-- �ɸ��� �����Ϻ��� ���ݱ��� �÷��� �ð�
	[PlayExp]				[int]				NOT NULL ,		-- �ɸ��� ���Ӻ��� ������� ȹ�� ����ġ
	[TotalExp]				[bigint]			NOT NULL ,		-- �ɸ��� �����Ϻ��� ���ݱ��� ȹ�� ����ġ
	[Race]					[nvarchar] (128)	NOT NULL ,		-- �ɸ��� ����
	[Class]					[nvarchar] (128)	NOT NULL ,		-- �ɸ��� ����
	[Level]					[int]				NOT NULL ,		-- �ɸ��� ���� �� ����
	[MostStayedInZoneName]	[nvarchar] (128)	NOT NULL		-- �ɸ��Ͱ� �����Ͽ� ����ñ��� ���� ���� �ӹ����� ���� �̸�
)
CREATE UNIQUE INDEX idx_on_GLog_CharacterPlayTime ON GLog_CharacterPlayTime(AccountName, GameName, GameServerName, LogoutDate)
CREATE INDEX idx_GLog_CharacterPlayTime_LogoutDate on GLog_CharacterPlayTime(LogoutDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectTotalUserCount
-- DESC      : 1�ð� �������� ����Ǵ� ���� ���� ���� �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_ConnectTotalUserCount]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_ConnectTotalUserCount]
GO
CREATE TABLE [dbo].[GLog_ConnectTotalUserCount] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[Date]				[datetime]			NOT NULL ,			-- ���� �ð�
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��񽺻� �̸�
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- ���� �̸�
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��� �̸�
	[TotalUserCount]	[int]				NOT NULL			-- �ִ� ������ ��
)
CREATE UNIQUE INDEX idx_on_GLog_ConnectTotalUserCount ON GLog_ConnectTotalUserCount(Date, GamePublisher, GameName, GameServerName)
CREATE INDEX idx_GLog_ConnectTotalUserCount_Date on GLog_ConnectTotalUserCount(Date)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectZoneUserCount
-- DESC      : 1�ð� �������� ����Ǵ� ������ ���� �α�(��, ��ü ������ 1% ���Ͽ� ���� ������ �α� ��󿡼� �����Ѵ�.)
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_ConnectZoneUserCount]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_ConnectZoneUserCount]
GO
CREATE TABLE [dbo].[GLog_ConnectZoneUserCount] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[Date]				[datetime]			NOT NULL ,			-- ���� �ð�         
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��񽺻� �̸� 
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- ���� �̸�
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��� �̸�     
	[ZoneName]			[nvarchar] (128)	NOT NULL ,			-- ���� ���� �̸�
	[ZoneUserCount]		[int]				NOT NULL			-- �ش� ���� ������ �ִ� ������ ��
)
CREATE UNIQUE INDEX idx_on_GLog_ConnectZoneUserCount ON GLog_ConnectZoneUserCount(Date, GameName, GameServerName, ZoneName)
CREATE INDEX idx_GLog_ConnectZoneUserCount_Date on GLog_ConnectZoneUserCount(Date)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Event
-- DESC      : Ư�� ���� �̺�Ʈ �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_Event]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_Event]
GO
CREATE TABLE [dbo].[GLog_Event] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��񽺻� �̸� 
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- ���� �̸�
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��� �̸�     
	[StartDate]			[datetime]			NOT NULL ,			-- �̺�Ʈ ���� ��¥
	[EndDate]			[datetime]			NOT NULL ,			-- �̺�Ʈ ���� ��¥
	[Description]		[nvarchar] (512)	NOT NULL			-- �̺�Ʈ ����
)
CREATE UNIQUE INDEX idx_on_GLog_Event ON GLog_Event(GameName, GameServerName, StartDate, EndDate)
CREATE INDEX idx_GLog_Event_EndDate on GLog_Event(EndDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_EventParticipationRate
-- DESC      : ���ӳ��� ���� �ֱ� �� ���� �߻��ϴ� ���� �̺�Ʈ�� ������ �α�
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_EventParticipationRate]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_EventParticipationRate]
GO
CREATE TABLE [dbo].[GLog_EventParticipationRate] (
	[UID]					[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[GamePublisher]			[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��񽺻� �̸� 
	[GameName]				[nvarchar] (128)	NOT NULL ,			-- ���� �̸�
	[GameServerName]		[nvarchar] (128)	NOT NULL ,			-- ���Ӽ��� �̸�     
	[StartDate]				[datetime]			NOT NULL ,			-- �̺�Ʈ ���� ��¥
	[EndDate]				[datetime]			NOT NULL ,			-- �̺�Ʈ ���� ��¥
	[ParticipationCount]	[int]				NOT NULL ,			-- �̺�Ʈ ���� ���ο���
	[ParticipationRate]		[smallint]			NOT NULL ,			-- �̺�Ʈ ������ [0%~100%]
	[Description]			[nvarchar] (512)	NOT NULL			-- �̺�Ʈ ����
)
CREATE UNIQUE INDEX idx_on_GLog_EventParticipationRate ON GLog_EventParticipationRate(GameName, GameServerName, StartDate, EndDate)
CREATE INDEX idx_GLog_EventParticipationRate_EndDate on GLog_EventParticipationRate(EndDate)
GO

