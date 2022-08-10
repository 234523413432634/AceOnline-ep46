--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_USER_Insert], [GLog_TB_USER_LocalUserConnectInfo_DelCount_Inc], [GLog_TB_USER_LocalUserConnectInfo_NewCount_Inc]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: GLog_TB_USER 테이블 관련 프로시져
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[GLog_TB_USER_Insert]
	@i_AccountName				VARCHAR(20),
	@i_ServiceCountry			NVARCHAR(50),
	@i_GamePublisher			NVARCHAR(100),
	@i_IPAddress				NVARCHAR(20),
	@i_GameServer				NVARCHAR(100)
AS
-- YD 보안 코드
BEGIN
	-- GLog_TB_USER 처리

	DECLARE @AccountName	 	NVARCHAR(128)
	SET @AccountName = (SELECT [us_id] FROM [GLog].[dbo].[GLog_TB_USER] WHERE [us_id] = @i_AccountName and [us_publisher] = @i_GamePublisher)

	IF (@AccountName IS NULL)
	BEGIN
		DECLARE @i_BirthYear	NVARCHAR(64)
		DECLARE @i_SexSrc		TINYINT
		DECLARE @i_SexDst		CHAR(1)
		
		SET @i_BirthYear = (SELECT BirthYear FROM [atum2_db_account].[dbo].[td_account] WHERE AccountName = @i_AccountName)
		SET @i_SexSrc = (SELECT Sex FROM [atum2_db_account].[dbo].[td_account] WHERE AccountName = @i_AccountName)
		
		IF @i_BirthYear = '0' 
		BEGIN
			SET @i_BirthYear = NULL
		END
		
		SET @i_SexDst = 
		CASE
			WHEN (@i_SexSrc = 1) THEN 'M'
			WHEN (@i_SexSrc = 2) THEN 'F'
			ELSE NULL
		END
	
		INSERT [GLog].[dbo].[GLog_TB_USER] ([us_id], [us_birthday], [us_sex], [us_regdate], [us_delete], [us_ip], [us_location], [us_country], [us_publisher], [us_gameserver]) 
			SELECT @i_AccountName, @i_BirthYear, @i_SexDst, RegisteredDate, 0, @i_IPAddress, NULL, @i_ServiceCountry, @i_GamePublisher, @i_GameServer
				FROM [atum2_db_account].[dbo].[td_account] WHERE AccountName = @i_AccountName
	END

	-- GLog_TB_CONNECT_USER 처리

	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN
	
	DECLARE @RtnDate			DATETIME
	SET @RtnDate = (SELECT TOP 1 [Date] from [GLog].[dbo].[GLog_Local_UserConnectInfo] ORDER BY [Date])
	
	IF (@RtnDate IS NOT NULL )
	BEGIN
		-- 여기서 시간 확인 후 날이 지났으면 Insert 처리
		DECLARE @NowDate		DATETIME
		SET @NowDate = getdate()

		IF DATEDIFF(d, @NowDate, @RtnDate) != 0
		BEGIN
			DECLARE @UniqueCount	INT
			DECLARE @TotalCount		INT
			DECLARE @NewCount		INT
			DECLARE @DeleteCount	INT
			
			SET @UniqueCount = (SELECT count(*) from [GLog].[dbo].[GLog_Local_UserConnectInfo] WHERE DATEDIFF(d, @RtnDate, [Date]) = 0)
			SET @TotalCount = (SELECT sum(CurrentCount) from [GLog].[dbo].[GLog_Local_UserConnectInfo] WHERE DATEDIFF(d, @RtnDate, [Date]) = 0)
			SET @NewCount = (SELECT sum(NewCount) from [GLog].[dbo].[GLog_Local_UserConnectInfo] WHERE DATEDIFF(d, @RtnDate, [Date]) = 0)
			SET @DeleteCount = (SELECT sum(DeleteCount) from [GLog].[dbo].[GLog_Local_UserConnectInfo] WHERE DATEDIFF(d, @RtnDate, [Date]) = 0)
			
			INSERT INTO [GLog].[dbo].[GLog_TB_CONNECT_USER]
				([c_date], [c_world], [c_unique], [c_new], [c_times], [c_del], [c_gameserver], [c_publisher])
					VALUES (convert(varchar(19), @RtnDate, 112), 0, @UniqueCount, @NewCount, @TotalCount, @DeleteCount, @i_GameServer, @i_GamePublisher)
			DELETE FROM [GLog].[dbo].[GLog_Local_UserConnectInfo] WHERE DATEDIFF(d, @RtnDate, [Date]) = 0
		END
	END

	-- 현재 테이블에 있는지 확인하고 없으면 추가 있으면 업데이트 한다
	
	DECLARE @RtnID			VARCHAR(40)
	SET @RtnID = (SELECT [ID] from [GLog].[dbo].[GLog_Local_UserConnectInfo] where [ID] = @i_AccountName)
	
	IF (@RtnID IS NOT NULL )
		BEGIN
			-- 업데이트
			UPDATE [GLog].[dbo].[GLog_Local_UserConnectInfo] SET [CurrentCount] = [CurrentCount] + 1 WHERE [ID] = @i_AccountName;
		END
	ELSE
		BEGIN
			-- 추가
			INSERT INTO [GLog].[dbo].[GLog_Local_UserConnectInfo] ([Date], [ID], [CurrentCount])
				VALUES (getdate(), @i_AccountName, 1)
		END
	
	COMMIT TRAN
	SET TRANSACTION ISOLATION LEVEL READ COMMITTED;	
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [GLog_TB_USER_LocalUserConnectInfo_NewCount_Inc]
-- DESC			: // 2011-12-12 by hskim, GLog 2차
-- DESC			: GLog_Local_UserConnectInfo 테이블 관련 프로시져
--------------------------------------------------------------------------------

CREATE PROCEDURE [dbo].[GLog_TB_USER_LocalUserConnectInfo_NewCount_Inc]
	@i_AccountName				VARCHAR(20)
AS
-- YD 보안 코드
BEGIN
	DECLARE @AccountUID INT
	SET @AccountUID = (SELECT AccountUniqueNumber FROM [atum2_db_account].[dbo].[td_account] WITH (NOLOCK) WHERE AccountName = @i_AccountName)

	IF (@AccountUID IS NULL)
	BEGIN
		SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
		BEGIN TRAN

		DECLARE @RtnID			VARCHAR(40)
		SET @RtnID = (SELECT [ID] from [GLog].[dbo].[GLog_Local_UserConnectInfo] where [ID] = @i_AccountName)

		IF (@RtnID IS NOT NULL )
			BEGIN
				-- 업데이트
				UPDATE [GLog].[dbo].[GLog_Local_UserConnectInfo] SET [NewCount] = 1 WHERE [ID] = @i_AccountName;
			END
		ELSE
			BEGIN
				-- 추가
				INSERT INTO [GLog].[dbo].[GLog_Local_UserConnectInfo] ([Date], [ID], [CurrentCount], [NewCount])
					VALUES (getdate(), @i_AccountName, 0, 1)
			END
		
		COMMIT TRAN
		SET TRANSACTION ISOLATION LEVEL READ COMMITTED;	
	END
END
GO
