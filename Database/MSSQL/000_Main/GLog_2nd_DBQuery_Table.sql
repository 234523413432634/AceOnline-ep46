--------------------------------------------------------------------------------
-- DESC      : GLog 2차 테이블 생성 
--		    데이터베이스 GLog 에 테이블 생성
--------------------------------------------------------------------------------

-- CREATE DATABASE GLog		-- 데이터베이스 생성 후 밀기

CREATE TABLE [dbo].[GLog_TB_USER]
(
	[UID]			[bigint]		NOT NULL	 IDENTITY(1,1) PRIMARY KEY,
	[us_id]			[varchar](255)	NOT NULL,
	[us_birthday]	[datetime]		NULL,
	[us_sex]		[char](1)		NULL,
	[us_regdate]	[datetime]		NULL,
	[us_delete]		[char](1)		NULL,
	[us_ip]			[varchar](20)	NULL,
	[us_location]	[varchar](50)	NULL,
	[us_country]	[varchar](50)	NULL,
	[us_publisher]	[varchar](100)	NULL,
	[us_gameserver] [varchar](100) NULL,
	[GLogUpdated]	[bit]			NULL		DEFAULT(0),
)

CREATE TABLE [dbo].[GLog_TB_CONNECT_USER]
(
	[UID]			[bigint]		NOT NULL	  IDENTITY(1,1) PRIMARY KEY,
	[c_date]		[smalldatetime]	NOT NULL,
	[c_world]		[tinyint]		NOT NULL,
	[c_unique]		[int]			NOT NULL,
	[c_new]			[int]			NOT NULL,
	[c_times]		[int]			NOT NULL,
	[c_del]			[int]			NOT NULL,
	[c_gameserver]	[varchar](100)	NULL,
	[c_publisher]	[varchar](100)	NULL,
)

CREATE TABLE [dbo].[GLog_TB_ITEM_BUY]
(
	[UID]			[bigint]		NOT NULL	 IDENTITY(1,1) PRIMARY KEY,
	[ib_date]		[datetime]		NULL,
	[ib_totalCost]	[int]			NULL,
	[ib_CashCost]	[int]			NULL,
	[us_no]			[int]			NULL,
	[us_id]			[varchar](255)	NULL,
	[ib_good_id]	[int]			NULL,
	[ib_good_name]	[varchar](128)	NULL,
	[ib_publisher]	[varchar](100)	NULL,
	[ib_charName]	[varchar](100)	NULL,
	[ib_charLevel]	[int]			NULL,
	[ib_itemCount]	[int]			NULL,
	[ib_gameserver] [varchar](100) NULL
)

CREATE TABLE [dbo].[GLog_TB_CONCURRENT_USER]
(
	[UID]			[bigint]		NOT NULL	IDENTITY(1,1) PRIMARY KEY,
	[cu_world]		[tinyint]		NOT NULL,
	[cu_date]		[smalldatetime]	NOT NULL,
	[cu_count]		[int]			NOT NULL,
	[cu_publisher]	[varchar](100)	NULL,
	[cu_gameServer]	[varchar](100)	NULL
)

CREATE TABLE [dbo].[GLog_TB_USER_PLAYTIME]
(
	[UID]			[bigint]	NOT NULL		IDENTITY(1,1) PRIMARY KEY,
	[up_login]		[datetime]	NULL,
	[up_logout]		[datetime]	NULL,
	[up_time]		[int]		NULL,
	[us_no]			[int]		NULL,
	[up_charID]		[int]		NULL,
	[up_country]	[char](1)	NULL,
	[up_race]		[char](1)	NULL,
	[up_class]		[char](1)	NULL,
	[up_exp]		[float]		NULL,
	[up_publisher]	[varchar](100) NULL,
	[up_gameserver]	[varchar](100) NULL
)

CREATE TABLE [dbo].[GLog_Local_UserConnectInfo]
(
	[UID]			[bigint]		NOT NULL	IDENTITY(1,1) PRIMARY KEY,
	[Date]			[datetime]		NOT NULL,
	[ID]			[varchar](255)	NOT NULL,
	[CurrentCount]	[int]			NOT NULL	DEFAULT(0),
	[NewCount]		[int]			NOT NULL	DEFAULT(0),
	[DeleteCount]	[int]			NOT NULL	DEFAULT(0)
)

CREATE UNIQUE INDEX [idx_Local_UserConnectInfo_ID] ON [GLog_Local_UserConnectInfo] ([ID])