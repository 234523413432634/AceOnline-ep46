--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Account
-- DESC      : 계정 생성 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_Account]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_Account]
GO
CREATE TABLE [dbo].[GLog_Account] (
 [UID]   [bigint]   IDENTITY (1, 1) NOT NULL PRIMARY KEY,
 [AccountName] [nvarchar] (128) NOT NULL ,   -- 계정 이름
 [GamePublisher] [nvarchar] (128) NOT NULL ,   -- 게임서비스사 이름
 [GameName]  [nvarchar] (128) NOT NULL ,   -- 게임 이름
 [GameServerIP] [nvarchar] (64)  NOT NULL ,   -- 게임서버IP (서비스지역 표시를 위해(ex:한국,미국등등))
 [Birthday]  [nvarchar] (64)  NULL ,    -- 유저 생년월일
 [Sex]   [bit]    NOT NULL DEFAULT(0) ,    -- 유저 성별 // 0 : 남자, 1 : 여자
 [RegDate]  [datetime]   NOT NULL,   -- 계정 생성 날짜
 [GLogUpdated] [bit]    NOT NULL DEFAULT(0) -- GLog DB에 업데이트 되었는지 체크하는 비트, 0 : 업데이트 전, 1: 업데이트 됨
)
CREATE UNIQUE INDEX idx_on_GLog_Account ON GLog_Account(AccountName, GamePublisher, GameName, RegDate)
CREATE INDEX idx_GLog_Account_RegDate on GLog_Account(RegDate) 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_BuyCashItem
-- DESC      : 유료 아이템 구매 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_BuyCashItem]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_BuyCashItem]
GO
CREATE TABLE [dbo].[GLog_BuyCashItem] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[AccountName]		[nvarchar] (128)	NOT NULL ,		-- 계정 이름
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,		-- 게임서비스사 이름
	[GameName]			[nvarchar] (128)	NOT NULL ,		-- 게임 이름
	[CharacterName]		[nvarchar] (128)	NOT NULL ,		-- 구매한 케릭터 이름
	[CharacterLevel]	[int]				NOT NULL ,		-- 구매한 케릭터 레벨
	[ItemName]			[nvarchar] (128)	NOT NULL ,		-- 구매한 아이템 이름
	[CashCost]			[int]				NOT NULL ,		-- 구매한 아이템 개당 유료 가격
	[ItemCount]			[int]				NOT NULL ,		-- 구매한 아이템 수
	[BuyDate]			[datetime]			NOT NULL		-- 구매 날짜
)
CREATE UNIQUE INDEX idx_on_GLog_BuyCashItem ON GLog_BuyCashItem(AccountName, GamePublisher, GameName, BuyDate)
CREATE INDEX idx_GLog_BuyCashItem_CharacterLevel on GLog_BuyCashItem(CharacterLevel)
CREATE INDEX idx_GLog_BuyCashItem_BuyDate on GLog_BuyCashItem(BuyDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_CharacterPlayTime
-- DESC      : 케릭터 플레이 종료시 저장 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_CharacterPlayTime]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_CharacterPlayTime]
GO
CREATE TABLE [dbo].[GLog_CharacterPlayTime] (
	[UID]					[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[AccountName]			[nvarchar] (128)	NOT NULL ,		-- 계정 이름
	[GamePublisher]			[nvarchar] (128)	NOT NULL ,		-- 게임서비스사 이름
	[GameName]				[nvarchar] (128)	NOT NULL ,		-- 게임 이름
	[GameServerName]		[nvarchar] (128)	NOT NULL ,		-- 게임서버 이름
	[CharacterName]			[nvarchar] (128)	NOT NULL ,		-- 종료한 케릭터 이름
	[LoginDate]				[datetime]			NOT NULL ,		-- 케릭터 접속 날짜
	[LogoutDate]			[datetime]			NOT NULL ,		-- 케릭터 종료 날짜
	[TotalPlayTime]			[bigint]			NOT NULL ,		-- 케릭터 생성일부터 지금까지 플레이 시간
	[PlayExp]				[int]				NOT NULL ,		-- 케릭터 접속부터 종료까지 획득 경험치
	[TotalExp]				[bigint]			NOT NULL ,		-- 케릭터 생성일부터 지금까지 획득 경험치
	[Race]					[nvarchar] (128)	NOT NULL ,		-- 케릭터 종족
	[Class]					[nvarchar] (128)	NOT NULL ,		-- 케릭터 종류
	[Level]					[int]				NOT NULL ,		-- 케릭터 종료 시 레벨
	[MostStayedInZoneName]	[nvarchar] (128)	NOT NULL		-- 케릭터가 접속하여 종료시까지 제일 많이 머물렀던 지역 이름
)
CREATE UNIQUE INDEX idx_on_GLog_CharacterPlayTime ON GLog_CharacterPlayTime(AccountName, GameName, GameServerName, LogoutDate)
CREATE INDEX idx_GLog_CharacterPlayTime_LogoutDate on GLog_CharacterPlayTime(LogoutDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectTotalUserCount
-- DESC      : 1시간 간격으로 저장되는 게임 서버 동접 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_ConnectTotalUserCount]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_ConnectTotalUserCount]
GO
CREATE TABLE [dbo].[GLog_ConnectTotalUserCount] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[Date]				[datetime]			NOT NULL ,			-- 저장 시간
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- 게임서비스사 이름
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- 게임 이름
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- 게임서버 이름
	[TotalUserCount]	[int]				NOT NULL			-- 최대 동접자 수
)
CREATE UNIQUE INDEX idx_on_GLog_ConnectTotalUserCount ON GLog_ConnectTotalUserCount(Date, GamePublisher, GameName, GameServerName)
CREATE INDEX idx_GLog_ConnectTotalUserCount_Date on GLog_ConnectTotalUserCount(Date)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectZoneUserCount
-- DESC      : 1시간 간격으로 저장되는 지역별 동접 로그(단, 전체 동접에 1% 이하에 동접 지역은 로그 대상에서 제외한다.)
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_ConnectZoneUserCount]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_ConnectZoneUserCount]
GO
CREATE TABLE [dbo].[GLog_ConnectZoneUserCount] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[Date]				[datetime]			NOT NULL ,			-- 저장 시간         
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- 게임서비스사 이름 
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- 게임 이름
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- 게임서버 이름     
	[ZoneName]			[nvarchar] (128)	NOT NULL ,			-- 게임 지역 이름
	[ZoneUserCount]		[int]				NOT NULL			-- 해당 게임 지역에 최대 동접자 수
)
CREATE UNIQUE INDEX idx_on_GLog_ConnectZoneUserCount ON GLog_ConnectZoneUserCount(Date, GameName, GameServerName, ZoneName)
CREATE INDEX idx_GLog_ConnectZoneUserCount_Date on GLog_ConnectZoneUserCount(Date)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Event
-- DESC      : 특정 게임 이벤트 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_Event]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_Event]
GO
CREATE TABLE [dbo].[GLog_Event] (
	[UID]				[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[GamePublisher]		[nvarchar] (128)	NOT NULL ,			-- 게임서비스사 이름 
	[GameName]			[nvarchar] (128)	NOT NULL ,			-- 게임 이름
	[GameServerName]	[nvarchar] (128)	NOT NULL ,			-- 게임서버 이름     
	[StartDate]			[datetime]			NOT NULL ,			-- 이벤트 시작 날짜
	[EndDate]			[datetime]			NOT NULL ,			-- 이벤트 종료 날짜
	[Description]		[nvarchar] (512)	NOT NULL			-- 이벤트 설명
)
CREATE UNIQUE INDEX idx_on_GLog_Event ON GLog_Event(GameName, GameServerName, StartDate, EndDate)
CREATE INDEX idx_GLog_Event_EndDate on GLog_Event(EndDate)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_EventParticipationRate
-- DESC      : 게임내에 일정 주기 및 자주 발생하는 게임 이벤트에 참여율 로그
--------------------------------------------------------------------------------
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[GLog_EventParticipationRate]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GLog_EventParticipationRate]
GO
CREATE TABLE [dbo].[GLog_EventParticipationRate] (
	[UID]					[bigint]			IDENTITY (1, 1) NOT NULL PRIMARY KEY,
	[GamePublisher]			[nvarchar] (128)	NOT NULL ,			-- 게임서비스사 이름 
	[GameName]				[nvarchar] (128)	NOT NULL ,			-- 게임 이름
	[GameServerName]		[nvarchar] (128)	NOT NULL ,			-- 게임서버 이름     
	[StartDate]				[datetime]			NOT NULL ,			-- 이벤트 시작 날짜
	[EndDate]				[datetime]			NOT NULL ,			-- 이벤트 종료 날짜
	[ParticipationCount]	[int]				NOT NULL ,			-- 이벤트 참여 총인원수
	[ParticipationRate]		[smallint]			NOT NULL ,			-- 이벤트 참여율 [0%~100%]
	[Description]			[nvarchar] (512)	NOT NULL			-- 이벤트 설명
)
CREATE UNIQUE INDEX idx_on_GLog_EventParticipationRate ON GLog_EventParticipationRate(GameName, GameServerName, StartDate, EndDate)
CREATE INDEX idx_GLog_EventParticipationRate_EndDate on GLog_EventParticipationRate(EndDate)
GO

