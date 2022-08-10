USE GLog
go

--------------------------------------------------------------------------------
-- TABLE NAME: GLog_Account
-- DESC      : ���� ���� �α� ���� ���ν���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_Account_Insert
	@i_AccountName			NVARCHAR(128),			-- ���� �̸�
	@i_GamePublisher		NVARCHAR(128),			-- ���Ӽ��񽺻� �̸�
	@i_GameName				NVARCHAR(128),			-- ���� �̸�
	@i_GameServerIP			NVARCHAR(64),			-- ���Ӽ���IP (�������� ǥ�ø� ����(ex:�ѱ�,�̱����))
	@i_Birthday				NVARCHAR(64),			-- ���� �������
	@i_Sex					bit,					-- ���� ����	// 0 : ����, 1 : ����
	@i_RegDate				datetime				-- ���� ���� ��¥
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
-- DESC      : ���� ������ ���� �α�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_BuyCashItem_Insert
	@i_AccountName			[nvarchar] (128),		-- ���� �̸�
	@i_GamePublisher		[nvarchar] (128),		-- ���Ӽ��񽺻� �̸�
	@i_GameName				[nvarchar] (128),		-- ���� �̸�
	@i_CharacterName		[nvarchar] (128),		-- ������ �ɸ��� �̸�
	@i_CharacterLevel		[int],					-- ������ �ɸ��� ����
	@i_ItemName				[nvarchar] (128),		-- ������ ������ �̸�
	@i_CashCost				[int],					-- ������ ������ ���� ���� ����
	@i_ItemCount			[int],					-- ������ ������ ��
	@i_BuyDate				[datetime]				-- ���� ��¥
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
-- DESC      : �ɸ��� �÷��� ����� ���� �α�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_CharacterPlayTime_Insert
	@i_AccountName				[nvarchar] (128),		-- ���� �̸�
	@i_GamePublisher			[nvarchar] (128),		-- ���Ӽ��񽺻� �̸�
	@i_GameName					[nvarchar] (128),		-- ���� �̸�
	@i_GameServerName			[nvarchar] (128),		-- ���Ӽ��� �̸�
	@i_CharacterName			[nvarchar] (128),		-- ������ �ɸ��� �̸�
	@i_LoginDate				[datetime],				-- �ɸ��� ���� ��¥
	@i_LogoutDate				[datetime],				-- �ɸ��� ���� ��¥
	@i_TotalPlayTime			[bigint],				-- �ɸ��� �����Ϻ��� ���ݱ��� �÷��� �ð�
	@i_PlayExp					[int],					-- �ɸ��� ���Ӻ��� ������� ȹ�� ����ġ
	@i_TotalExp					[bigint],				-- �ɸ��� �����Ϻ��� ���ݱ��� ȹ�� ����ġ
	@i_Race						[nvarchar] (128),		-- �ɸ��� ����
	@i_Class					[nvarchar] (128),		-- �ɸ��� ����
	@i_Level					[int],					-- �ɸ��� ���� �� ����
	@i_MostStayedInZoneName		[nvarchar] (128)		-- �ɸ��Ͱ� �����Ͽ� ����ñ��� ���� ���� �ӹ����� ���� �̸�
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
-- DESC      : 1�ð� �������� ����Ǵ� ���� ���� ���� �α�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_ConnectTotalUserCount_Insert
	@i_Date				[datetime],					-- ���� �ð�
	@i_GamePublisher	[nvarchar] (128),			-- ���Ӽ��񽺻� �̸�
	@i_GameName			[nvarchar] (128),			-- ���� �̸�
	@i_GameServerName	[nvarchar] (128),			-- ���Ӽ��� �̸�
	@i_TotalUserCount	[int]						-- �ִ� ������ ��
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
-- DESC      : 1�ð� �������� ����Ǵ� ������ ���� �α�(��, ��ü ������ 1% ���Ͽ� ���� ������ �α� ��󿡼� �����Ѵ�.)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_ConnectZoneUserCount_Insert
	@i_Date				[datetime],					-- ���� �ð�
	@i_GamePublisher	[nvarchar] (128),			-- ���Ӽ��񽺻� �̸�
	@i_GameName			[nvarchar] (128),			-- ���� �̸�
	@i_GameServerName	[nvarchar] (128),			-- ���Ӽ��� �̸�
	@i_ZoneName			[nvarchar] (128),			-- ���� ���� �̸�
	@i_ZoneUserCount	[int]						-- �ش� ���� ������ �ִ� ������ ��		
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
-- DESC      : Ư�� ���� �̺�Ʈ �α�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_Event_Insert
	@i_GamePublisher	[nvarchar] (128),			-- ���Ӽ��񽺻� �̸� 
	@i_GameName			[nvarchar] (128),			-- ���� �̸�
	@i_GameServerName	[nvarchar] (128),			-- ���Ӽ��� �̸�     
	@i_StartDate		[datetime],					-- �̺�Ʈ ���� ��¥
	@i_EndDate			[datetime],					-- �̺�Ʈ ���� ��¥
	@i_Description		[nvarchar] (512)			-- �̺�Ʈ ����		
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
-- DESC      : ���ӳ��� ���� �ֱ� �� ���� �߻��ϴ� ���� �̺�Ʈ�� ������ �α�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.GLog_EventParticipationRate_Insert
	@i_GamePublisher			[nvarchar] (128),			-- ���Ӽ��񽺻� �̸� 
	@i_GameName					[nvarchar] (128),			-- ���� �̸�
	@i_GameServerName			[nvarchar] (128),			-- ���Ӽ��� �̸�     
	@i_StartDate				[datetime],					-- �̺�Ʈ ���� ��¥
	@i_EndDate					[datetime],					-- �̺�Ʈ ���� ��¥
	@i_ParticipationCount		[int],						-- �̺�Ʈ ���� ���ο���
	@i_ParticipationRate		[smallint],					-- �̺�Ʈ ������ [0%~100%]
	@i_Description				[nvarchar] (512)			-- �̺�Ʈ ����	
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
-- DESC      : Atum2_DB_account�� �߰��� ���ν��� - �ۺ��ſ� ID�� �ִ��� ã�´�.
--------------------------------------------------------------------------------
USE atum2_db_account
go

CREATE PROCEDURE dbo.atum_InsertGlogAccount
	@i_AccountName				VARCHAR(20),
--	@i_Sex					TINYINT,			-- 1: ��, 2: ��
--	@i_BirthYear				INT,				-- ����
	@i_GamePublisher			NVARCHAR(128),		-- ���Ӽ��񽺻� �̸�
	@i_GameServerIP				NVARCHAR(64)			-- ���Ӽ���IP (�������� ǥ�ø� ����(ex:�ѱ�,�̱����))
--	@i_DateTime 				DATETIME
AS
	--AccountUID �޾ƿ��� �ۺ��ſ� �̸��� �˻��Ѵ�.
	DECLARE @AccountName	 	NVARCHAR(128)
	SET @AccountName = (SELECT AccountName FROM GLog.dbo.GLog_Account WITH (NOLOCK) WHERE AccountName = @i_AccountName and GamePublisher = @i_GamePublisher)
	
	
	-- ���� �����ڴ� ���� �߰�
	IF (@AccountName IS NULL)
	BEGIN
		--// 2010-06-01 by shcho, GLogDB ���� - ���񽺻� �̸�, IP�� �޾ƿ;� �Ѵ�.	
		DECLARE @tBirthYear INT, @tSex TINYINT, @tRegisteredDate DATETIME	
		SELECT @tBirthYear = BirthYear, @tSex = sex, @tRegisteredDate = RegisteredDate FROM atum2_db_account.dbo.td_account WHERE AccountName = @i_AccountName;
		
		INSERT GLog.dbo.GLog_Account (AccountName, GamePublisher, GameName, GameServerIP, Birthday, Sex, RegDate )
		VALUES(@i_AccountName, @i_GamePublisher, 'AceOnline', @i_GameServerIP,  CAST(@tBirthYear AS NVARCHAR(64)), @tSex-1, @tRegisteredDate)

	END
GO
