--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_USER_Select], [GLog_TB_USER_Delete], [GLog_TB_USER_Insert]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: GLog_TB_USER 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROC [dbo].[GLog_TB_USER_Select]
AS
-- YD 보안 코드
BEGIN
	SELECT TOP 1000 [UID], [us_id], [us_birthday], [us_sex], [us_regdate], [us_delete], [us_ip], [us_location], [us_country], [us_publisher], [us_gameserver]
		FROM [GLog].[dbo].[GLog_TB_USER] WHERE [GLogUpdated] = 0
END
GO

CREATE PROC [dbo].[GLog_TB_USER_Delete]
	@i_UID		BIGINT
AS
-- YD 보안 코드
BEGIN
	UPDATE [GLog].[dbo].[GLog_TB_USER] SET [GLogUpdated] = 1 WHERE [UID] = @i_UID
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_CONNECT_USER_Select], [GLog_TB_CONNECT_USER_Delete], [GLog_TB_CONNECT_USER_Insert]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: TB_CONNECT_USER 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROC [dbo].[GLog_TB_CONNECT_USER_Select]
AS
-- YD 보안 코드
BEGIN
	SELECT TOP 1000 [UID], [c_date], [c_world], [c_unique], [c_new], [c_times], [c_del], [c_gameserver], [c_publisher] 
		FROM [GLog].[dbo].[GLog_TB_CONNECT_USER]
END
GO

CREATE PROC [dbo].[GLog_TB_CONNECT_USER_Delete]
	@i_UID		BIGINT
AS
-- YD 보안 코드
BEGIN
	DELETE FROM [GLog].[dbo].[GLog_TB_CONNECT_USER] WHERE [UID] = @i_UID
END
GO

CREATE PROC [dbo].[GLog_TB_CONNECT_USER_Insert]
	@i_c_date		SMALLDATETIME,
	@i_c_world		TINYINT,
	@i_c_unique		INT,
	@i_c_new		INT,
	@i_c_times		INT,
	@i_c_del		INT,
	@i_c_gameserver	VARCHAR(100),
	@i_c_publisher	VARCHAR(100)
AS
-- YD 보안 코드
BEGIN
	INSERT INTO [GLog].[dbo].[GLog_TB_CONNECT_USER] ([c_date], [c_world], [c_unique], [c_new], [c_times], [c_del], [c_gameserver], [c_publisher])
		VALUES(@i_c_date, @i_c_world, @i_c_unique, @i_c_new, @i_c_times, @i_c_del, @i_c_gameserver, @i_c_publisher)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_ITEM_BUY_Select], [GLog_TB_ITEM_BUY_Delete], [GLog_TB_ITEM_BUY_Insert]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: TB_ITEM_BUY 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROC [dbo].[GLog_TB_ITEM_BUY_Select]
AS
-- YD 보안 코드
BEGIN
	SELECT TOP 1000 [UID], [ib_date], [ib_totalCost], [ib_CashCost], [us_no], [us_id], [ib_good_id], [ib_good_name], [ib_publisher], [ib_charName], [ib_charLevel], [ib_itemCount], [ib_gameserver]
		FROM [GLog].[dbo].[GLog_TB_ITEM_BUY]
END
GO

CREATE PROC [dbo].[GLog_TB_ITEM_BUY_Delete]
	@i_UID		BIGINT
AS
-- YD 보안 코드
BEGIN
	DELETE FROM [GLog].[dbo].[GLog_TB_ITEM_BUY] WHERE [UID] = @i_UID
END
GO

CREATE PROC [dbo].[GLog_TB_ITEM_BUY_Insert]
	@i_ib_date			DATETIME,
	@i_ib_totalCost		INT,
	@i_ib_CashCost		INT,
	@i_us_no			INT,
	@i_us_id			VARCHAR(255),
	@i_ib_good_id		INT,
	@i_ib_good_name		VARCHAR(128),
	@i_ib_publisher		VARCHAR(100),
	@i_ib_charName		VARCHAR(100),
	@i_ib_charLevel		INT,
	@i_ib_itemCount		INT,
	@i_ib_gameserver	VARCHAR(100)
AS
-- YD 보안 코드
BEGIN
	INSERT INTO [GLog].[dbo].[GLog_TB_ITEM_BUY] ([ib_date], [ib_totalCost], [ib_CashCost], [us_no], [us_id], [ib_good_id], [ib_good_name], [ib_publisher], [ib_charName], [ib_charLevel], [ib_itemCount], [ib_gameserver])
		VALUES(@i_ib_date, @i_ib_totalCost, @i_ib_CashCost, @i_us_no, @i_us_id, @i_ib_good_id, @i_ib_good_name, @i_ib_publisher, @i_ib_charName, @i_ib_charLevel, @i_ib_itemCount, @i_ib_gameserver)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_CONCURRENT_USER_Select], [GLog_TB_CONCURRENT_USER_Delete], [GLog_TB_CONCURRENT_USER_Insert]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: TB_CONCURRENT_USER 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROC [dbo].[GLog_TB_CONCURRENT_USER_Select]
AS
-- YD 보안 코드
BEGIN
	SELECT TOP 1000 [UID], [cu_world], [cu_date], [cu_count], [cu_publisher], [cu_gameServer]
		FROM [GLog].[dbo].[GLog_TB_CONCURRENT_USER]
END
GO

CREATE PROC [dbo].[GLog_TB_CONCURRENT_USER_Delete]
	@i_UID		BIGINT
AS
-- YD 보안 코드
BEGIN
	DELETE FROM [GLog].[dbo].[GLog_TB_CONCURRENT_USER] WHERE [UID] = @i_UID
END
GO

CREATE PROC [dbo].[GLog_TB_CONCURRENT_USER_Insert]
	@i_cu_world			TINYINT,
	@i_cu_date			SMALLDATETIME,
	@i_cu_count			INT,
	@i_cu_publisher		VARCHAR(100),
	@i_cu_gameServer	VARCHAR(100)
AS
-- YD 보안 코드
BEGIN
	INSERT INTO [GLog].[dbo].[GLog_TB_CONCURRENT_USER] ([cu_world], [cu_date], [cu_count], [cu_publisher], [cu_gameServer])
		VALUES(@i_cu_world, @i_cu_date, @i_cu_count, @i_cu_publisher, @i_cu_gameServer)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_USER_PLAYTIME_Select], [GLog_TB_USER_PLAYTIME_Delete], [GLog_TB_USER_PLAYTIME_Insert]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: TB_USER_PLAYTIME 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROC [dbo].[GLog_TB_USER_PLAYTIME_Select]
AS
-- YD 보안 코드
BEGIN
	SELECT TOP 1000 [UID], [up_login], [up_logout], [up_time], [us_no], [up_charID], [up_country], [up_race], [up_class], [up_exp], [up_publisher], [up_gameserver]
		FROM [GLog].[dbo].[GLog_TB_USER_PLAYTIME]
END
GO

CREATE PROC [dbo].[GLog_TB_USER_PLAYTIME_Delete]
	@i_UID		BIGINT
AS
-- YD 보안 코드
BEGIN
	DELETE FROM [GLog].[dbo].[GLog_TB_USER_PLAYTIME] WHERE [UID] = @i_UID
END
GO

CREATE PROC [dbo].[GLog_TB_USER_PLAYTIME_Insert]
	@i_up_login		DATETIME,
	@i_up_logout	DATETIME,
	@i_up_time		INT,
	@i_us_no		INT,
	@i_up_charID	INT,
	@i_up_country	CHAR(1),
	@i_up_race		CHAR(1),
	@i_up_class		CHAR(1),
	@i_up_exp		INT,
	@i_up_publisher		VARCHAR(100),
	@i_up_gameserver	VARCHAR(100)
AS
-- YD 보안 코드
BEGIN
	INSERT INTO [GLog].[dbo].[GLog_TB_USER_PLAYTIME] ([up_login], [up_logout], [up_time], [us_no], [up_charID], [up_country], [up_race], [up_class], [up_exp], [up_publisher], [up_gameserver])
		VALUES(@i_up_login, @i_up_logout, @i_up_time, @i_us_no, @i_up_charID, @i_up_country, @i_up_race, @i_up_class, @i_up_exp, @i_up_publisher, @i_up_gameserver)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_USER_LocalUserConnectInfo_DelCount_Inc]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: GLog_Local_UserConnectInfo 테이블 관련 프로시져
--------------------------------------------------------------------------------

CREATE PROCEDURE [dbo].[GLog_TB_USER_LocalUserConnectInfo_DelCount_Inc]
	@i_AccountName				VARCHAR(20)
AS
-- YD 보안 코드
BEGIN
	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN

	DECLARE @RtnID			VARCHAR(40)
	SET @RtnID = (SELECT [ID] from [GLog].[dbo].[GLog_Local_UserConnectInfo] where [ID] = @i_AccountName)
	
	IF (@RtnID IS NOT NULL )
	BEGIN
		-- 업데이트
		UPDATE [GLog].[dbo].[GLog_Local_UserConnectInfo] SET [DeleteCount] = [DeleteCount] + 1 WHERE [ID] = @i_AccountName;
	END
	
	COMMIT TRAN
	SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
END
GO