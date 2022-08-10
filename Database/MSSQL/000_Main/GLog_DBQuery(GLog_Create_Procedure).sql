USE GLog
go

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Account
-- DESC      : 계정 생성 로그 관련 프로시저
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_Account_Insert
	@i_AccountName			NVARCHAR(128),			-- 계정 이름
	@i_GamePublisher		NVARCHAR(128),			-- 게임서비스사 이름
	@i_GameName				NVARCHAR(128),			-- 게임 이름
	@i_GameServerIP			NVARCHAR(64),			-- 게임서버IP (서비스지역 표시를 위해(ex:한국,미국등등))
	@i_Birthday				NVARCHAR(64),			-- 유저 생년월일
	@i_Sex					bit,					-- 유저 성별	// 0 : 남자, 1 : 여자
	@i_RegDate				datetime				-- 계정 생성 날짜
AS
	INSERT INTO GLog.dbo.GLog_Account([AccountName], [GamePublisher], [GameName], [GameServerIP], [Birthday], [Sex], [RegDate])
		VALUES(@i_AccountName, @i_GamePublisher, @i_GameName, @i_GameServerIP, @i_Birthday, @i_Sex, @i_RegDate)
GO

CREATE PROCEDURE dbo.GLog_Account_Select
AS
	SELECT TOP 1000 [UID], [AccountName], [GamePublisher], [GameName], [GameServerIP], [Birthday], [Sex], [RegDate]		
	FROM GLog.dbo.GLog_Account
GO

CREATE PROCEDURE dbo.GLog_Account_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_Account 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_BuyCashItem
-- DESC      : 유료 아이템 구매 로그
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_BuyCashItem_Insert
	@i_AccountName			[nvarchar] (128),		-- 계정 이름
	@i_GamePublisher		[nvarchar] (128),		-- 게임서비스사 이름
	@i_GameName				[nvarchar] (128),		-- 게임 이름
	@i_CharacterName		[nvarchar] (128),		-- 구매한 케릭터 이름
	@i_CharacterLevel		[int],					-- 구매한 케릭터 레벨
	@i_ItemName				[nvarchar] (128),		-- 구매한 아이템 이름
	@i_CashCost				[int],					-- 구매한 아이템 개당 유료 가격
	@i_ItemCount			[int],					-- 구매한 아이템 수
	@i_BuyDate				[datetime]				-- 구매 날짜
AS
	INSERT INTO GLog.dbo.GLog_BuyCashItem([AccountName], [GamePublisher], [GameName], [CharacterName], [CharacterLevel], [ItemName], [CashCost], [ItemCount], [BuyDate])
		VALUES(@i_AccountName, @i_GamePublisher, @i_GameName, @i_CharacterName, @i_CharacterLevel, @i_ItemName, @i_CashCost, @i_ItemCount, @i_BuyDate)
GO

CREATE PROCEDURE dbo.GLog_BuyCashItem_Select
AS
	SELECT TOP 1000 [UID], [AccountName], [GamePublisher], [GameName], [CharacterName], [CharacterLevel], [ItemName], [CashCost], [ItemCount], [BuyDate]
	FROM GLog.dbo.GLog_BuyCashItem
GO

CREATE PROCEDURE dbo.GLog_BuyCashItem_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_BuyCashItem 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_CharacterPlayTime
-- DESC      : 케릭터 플레이 종료시 저장 로그
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_CharacterPlayTime_Insert
	@i_AccountName				[nvarchar] (128),		-- 계정 이름
	@i_GamePublisher			[nvarchar] (128),		-- 게임서비스사 이름
	@i_GameName					[nvarchar] (128),		-- 게임 이름
	@i_GameServerName			[nvarchar] (128),		-- 게임서버 이름
	@i_CharacterName			[nvarchar] (128),		-- 종료한 케릭터 이름
	@i_LoginDate				[datetime],				-- 케릭터 접속 날짜
	@i_LogoutDate				[datetime],				-- 케릭터 종료 날짜
	@i_TotalPlayTime			[bigint],				-- 케릭터 생성일부터 지금까지 플레이 시간
	@i_PlayExp					[int],					-- 케릭터 접속부터 종료까지 획득 경험치
	@i_TotalExp					[bigint],				-- 케릭터 생성일부터 지금까지 획득 경험치
	@i_Race						[nvarchar] (128),		-- 케릭터 종족
	@i_Class					[nvarchar] (128),		-- 케릭터 종류
	@i_Level					[int],					-- 케릭터 종료 시 레벨
	@i_MostStayedInZoneName		[nvarchar] (128)		-- 케릭터가 접속하여 종료시까지 제일 많이 머물렀던 지역 이름
AS
	INSERT INTO GLog.dbo.GLog_CharacterPlayTime([AccountName], [GamePublisher], [GameName], [GameServerName], [CharacterName], [LoginDate], [LogoutDate], [TotalPlayTime], [PlayExp], [TotalExp], [Race], [Class], [Level], [MostStayedInZoneName])
		VALUES(@i_AccountName, @i_GamePublisher, @i_GameName, @i_GameServerName, @i_CharacterName, @i_LoginDate, @i_LogoutDate,	@i_TotalPlayTime, @i_PlayExp, @i_TotalExp, @i_Race, @i_Class, @i_Level, @i_MostStayedInZoneName)
GO

CREATE PROCEDURE dbo.GLog_CharacterPlayTime_Select
AS
	SELECT TOP 1000 [UID], [AccountName], [GamePublisher], [GameName], [GameServerName], [CharacterName], [LoginDate], [LogoutDate], [TotalPlayTime], [PlayExp], [TotalExp], [Race], [Class], [Level], [MostStayedInZoneName]
	FROM GLog.dbo.GLog_CharacterPlayTime
GO

CREATE PROCEDURE dbo.GLog_CharacterPlayTime_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_CharacterPlayTime 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectTotalUserCount
-- DESC      : 1시간 간격으로 저장되는 게임 서버 동접 로그
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_ConnectTotalUserCount_Insert
	@i_Date				[datetime],					-- 저장 시간
	@i_GamePublisher	[nvarchar] (128),			-- 게임서비스사 이름
	@i_GameName			[nvarchar] (128),			-- 게임 이름
	@i_GameServerName	[nvarchar] (128),			-- 게임서버 이름
	@i_TotalUserCount	[int]						-- 최대 동접자 수
AS
	INSERT INTO GLog.dbo.GLog_ConnectTotalUserCount([Date],	[GamePublisher], [GameName], [GameServerName], [TotalUserCount])
		VALUES(@i_Date,	@i_GamePublisher, @i_GameName, @i_GameServerName, @i_TotalUserCount)
GO

CREATE PROCEDURE dbo.GLog_ConnectTotalUserCount_Select
AS
	SELECT TOP 1000 [UID], [Date],	[GamePublisher], [GameName], [GameServerName], [TotalUserCount]
	FROM GLog.dbo.GLog_ConnectTotalUserCount
GO

CREATE PROCEDURE dbo.GLog_ConnectTotalUserCount_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_ConnectTotalUserCount 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_ConnectZoneUserCount
-- DESC      : 1시간 간격으로 저장되는 지역별 동접 로그(단, 전체 동접에 1% 이하에 동접 지역은 로그 대상에서 제외한다.)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_ConnectZoneUserCount_Insert
	@i_Date				[datetime],					-- 저장 시간
	@i_GamePublisher	[nvarchar] (128),			-- 게임서비스사 이름
	@i_GameName			[nvarchar] (128),			-- 게임 이름
	@i_GameServerName	[nvarchar] (128),			-- 게임서버 이름
	@i_ZoneName			[nvarchar] (128),			-- 게임 지역 이름
	@i_ZoneUserCount	[int]						-- 해당 게임 지역에 최대 동접자 수		
AS
	INSERT INTO GLog.dbo.GLog_ConnectZoneUserCount([Date],	[GamePublisher], [GameName], [GameServerName], [ZoneName], [ZoneUserCount])
		VALUES(@i_Date,	@i_GamePublisher, @i_GameName, @i_GameServerName, @i_ZoneName, @i_ZoneUserCount)
GO

CREATE PROCEDURE dbo.GLog_ConnectZoneUserCount_Select
AS
	SELECT TOP 1000 [UID], [Date],	[GamePublisher], [GameName], [GameServerName], [ZoneName], [ZoneUserCount]
	FROM GLog.dbo.GLog_ConnectZoneUserCount
GO

CREATE PROCEDURE dbo.GLog_ConnectZoneUserCount_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_ConnectZoneUserCount 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Event
-- DESC      : 특정 게임 이벤트 로그
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_Event_Insert
	@i_GamePublisher	[nvarchar] (128),			-- 게임서비스사 이름 
	@i_GameName			[nvarchar] (128),			-- 게임 이름
	@i_GameServerName	[nvarchar] (128),			-- 게임서버 이름     
	@i_StartDate		[datetime],					-- 이벤트 시작 날짜
	@i_EndDate			[datetime],					-- 이벤트 종료 날짜
	@i_Description		[nvarchar] (512)			-- 이벤트 설명		
AS
	INSERT INTO GLog.dbo.GLog_Event([GamePublisher], [GameName], [GameServerName], [StartDate], [EndDate], [Description])
		VALUES(@i_GamePublisher, @i_GameName, @i_GameServerName, @i_StartDate, @i_EndDate, @i_Description)
GO

CREATE PROCEDURE dbo.GLog_Event_Select
AS
	SELECT TOP 1000 [UID], [GamePublisher], [GameName], [GameServerName], [StartDate], [EndDate], [Description]
	FROM GLog.dbo.GLog_Event
GO

CREATE PROCEDURE dbo.GLog_Event_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_Event 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: GLog_EventParticipationRate
-- DESC      : 게임내에 일정 주기 및 자주 발생하는 게임 이벤트에 참여율 로그
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_EventParticipationRate_Insert
	@i_GamePublisher			[nvarchar] (128),			-- 게임서비스사 이름 
	@i_GameName					[nvarchar] (128),			-- 게임 이름
	@i_GameServerName			[nvarchar] (128),			-- 게임서버 이름     
	@i_StartDate				[datetime],					-- 이벤트 시작 날짜
	@i_EndDate					[datetime],					-- 이벤트 종료 날짜
	@i_ParticipationCount		[int],						-- 이벤트 참여 총인원수
	@i_ParticipationRate		[smallint],					-- 이벤트 참여율 [0%~100%]
	@i_Description				[nvarchar] (512)			-- 이벤트 설명	
AS
	INSERT INTO GLog.dbo.GLog_EventParticipationRate([GamePublisher], [GameName], [GameServerName], [StartDate], [EndDate], [ParticipationCount], [ParticipationRate], [Description])
		VALUES(@i_GamePublisher, @i_GameName, @i_GameServerName, @i_StartDate, @i_EndDate, @i_ParticipationCount, @i_ParticipationRate, @i_Description)
GO

CREATE PROCEDURE dbo.GLog_EventParticipationRate_Select
AS
	SELECT TOP 1000 [UID], [GamePublisher], [GameName], [GameServerName], [StartDate], [EndDate], [ParticipationCount], [ParticipationRate], [Description]
	FROM GLog.dbo.GLog_EventParticipationRate
GO

CREATE PROCEDURE dbo.GLog_EventParticipationRate_Delete
	@i_UID					BIGINT
AS
	DELETE FROM GLog.dbo.GLog_EventParticipationRate 
	WHERE [UID] = @i_UID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: 
-- DESC      : Atum2_DB_account에 추가될 프로시저 - 퍼블리셔와 ID로 있는지 찾는다.
--------------------------------------------------------------------------------
USE atum2_db_account
go

CREATE PROCEDURE dbo.atum_InsertGlogAccount
	@i_AccountName				VARCHAR(20),
--	@i_Sex					TINYINT,			-- 1: 남, 2: 여
--	@i_BirthYear				INT,				-- 생년
	@i_GamePublisher			NVARCHAR(128),		-- 게임서비스사 이름
	@i_GameServerIP				NVARCHAR(64)			-- 게임서버IP (서비스지역 표시를 위해(ex:한국,미국등등))
--	@i_DateTime 				DATETIME
AS
	--AccountUID 받아오기 퍼블리셔와 이름을 검색한다.
	DECLARE @AccountName	 	NVARCHAR(128)
	SET @AccountName = (SELECT AccountName FROM GLog.dbo.GLog_Account WITH (NOLOCK) WHERE AccountName = @i_AccountName and GamePublisher = @i_GamePublisher)
	
	
	-- 최초 접속자는 계정 추가
	IF (@AccountName IS NULL)
	BEGIN
		--// 2010-06-01 by shcho, GLogDB 관련 - 서비스사 이름, IP는 받아와야 한다.	
		DECLARE @tBirthYear INT, @tSex TINYINT, @tRegisteredDate DATETIME	
		SELECT @tBirthYear = BirthYear, @tSex = sex, @tRegisteredDate = RegisteredDate FROM atum2_db_account.dbo.td_account WHERE AccountName = @i_AccountName;
		
		INSERT GLog.dbo.GLog_Account (AccountName, GamePublisher, GameName, GameServerIP, Birthday, Sex, RegDate )
		VALUES(@i_AccountName, @i_GamePublisher, 'AceOnline', @i_GameServerIP,  CAST(@tBirthYear AS NVARCHAR(64)), @tSex-1, @tRegisteredDate)

	END
GO
