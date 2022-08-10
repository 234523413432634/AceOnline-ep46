--------------------------------------------------------------
-- Pre Server ����
--------------------------------------------------------------


--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, �߰���
--		2006-11-15 by cmkwon, Select �˻� �ʵ� �߰�(td_account���̺� �߰��� �ʵ� - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-28 by cmkwon, �߱� ��������(�������� FielServer�� ��������) - �˻� ����� BirthYear �ʵ� �߰�
--		// 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - atum_PreServerGetAccountInfo ���ν��� ����
--====
CREATE PROCEDURE dbo.atum_PreServerGetAccountInfo
	@i_accname			varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - SecondaryPassword �������� �߰�
	-- // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - �÷� ���� �߰� LastLoginDate clumn
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, BirthYear, SecondaryPassword, LastLoginDate
	FROM dbo.td_account WITH (NOLOCK)
	WHERE AccountName = @i_accname
GO

--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, �߰���
-- Desc: // 2012-10-07 by hskim, �޽� ����ġ
--====
CREATE PROCEDURE dbo.atum_PreServerUpdateLastLoginDate
	@i_accUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @NowDate				DATETIME; SET @NowDate = GETDATE();
	DECLARE @DiffMin				INT
	DECLARE @RestExperienceCount	INT

	DECLARE @MinTime				INT; SET @MinTime = 300			-- �⺻ �� ����	(�ּ� ���� ��	: [300, 5�ð�])
	DECLARE @MaxCount				INT; SET @MaxCount = 3600		-- �⺻ �� ����	(�ִ� ���� ����	: [3600, 2�д� 1����, �� 5��, 3600����)

	UPDATE dbo.td_account SET LastLoginDate = @NowDate WHERE AccountUniqueNumber = @i_accUID

	-- ���� ���̺� ���� �ִ��� Ȯ���Ŀ� ������ ����
	SELECT @RestExperienceCount = RestExperienceCount FROM dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_accUID

	IF( @RestExperienceCount IS NULL )
	BEGIN 
		EXEC [dbo].[atum_Set_AddExp_RestExperienceCount] @i_AccountUniqueNumber = @i_accUID, @i_RestExperienceCount = 0;

		RETURN
	END

	SELECT @DiffMin = DATEDIFF(minute, LastGameEndDate, @NowDate) FROM dbo.td_account WITH (NOLOCK) WHERE [AccountUniqueNumber] = @i_accUID;

	IF( @DiffMin IS NULL )
	BEGIN
		RETURN
	END

	IF( @DiffMin >= @MinTime )
	BEGIN
		SET @RestExperienceCount = @RestExperienceCount + (@DiffMin / 2)

		IF( @RestExperienceCount > @MaxCount )
		BEGIN
			SET @RestExperienceCount = @MaxCount
		END

		EXEC [dbo].[atum_Set_AddExp_RestExperienceCount] @i_AccountUniqueNumber = @i_accUID, @i_RestExperienceCount = @RestExperienceCount;
	END
GO


--!!!!
-- Name: atum_PreServerExtAuthLogin
-- Desc: 2006-04-27 by cmkwon, �߰���
--		   �ܺ� DB ���� �α��� ó�� - ��� üũ�� ����, ������ ������ ���� �߰�, AccountUniqueNumber�� �����Ѵ�.
--		2006-11-15 by cmkwon, Select �˻� �ʵ� �߰�(td_account���̺� �߰��� �ʵ� - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-29 by cmkwon, dbo.td_account ���̺� �ֹι�ȣ�����ϱ� - �ֹι�ȣ ���� �߰�
--		// 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - atum_PreServerExtAuthLogin ���ν��� ����
--====
CREATE PROCEDURE dbo.atum_PreServerExtAuthLogin
	@i_AccountName				VARCHAR(20),
	@i_Sex						TINYINT,			-- 1: ��, 2: ��
	@i_BirthYear				INT,				-- ����
	@i_MGameEventType			INT,
	@i_JuminNumber				VARCHAR(20)			-- 2007-06-29 by cmkwon, dbo.td_account ���̺� �ֹι�ȣ�����ϱ� - �߰��� ����
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccountUID INT
	SET @AccountUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH (NOLOCK) WHERE AccountName = @i_AccountName)

	-- ���� �����ڴ� ���� �߰�
	IF (@AccountUID IS NULL)
	BEGIN
		INSERT INTO dbo.td_account(AccountName, Sex, BirthYear, MGameEventType, JuminNumber)
			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType, @i_JuminNumber)
	END
	ELSE
	BEGIN
		-- 2007-03-30 by cmkwon
		-- SQLMoreResults()�� ������ ���߱� ���ؼ� �߰��� �ڵ���
		UPDATE dbo.td_account
			SET Sex = Sex
			WHERE AccountName = @i_AccountName
	END
	
	-- ������ �α��� �ð� ����
	UPDATE dbo.td_account
		SET LastLoginDate = GetDate()
		WHERE AccountName = @i_AccountName	
	
	-- // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - SecondaryPassword �������� �߰�
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, SecondaryPassword
		FROM dbo.td_account WHERE AccountName = @i_AccountName
GO




-- 2006-06-02 by cmkwon, atum_PreServerExtAuthLogin �� ����
----!!!!
---- Name:
---- Desc:
----====
--CREATE PROCEDURE dbo.atum_PreServerLogin
--	@accname			varchar(64),
--	@passwd				varchar(35)
--AS
--	-- ������ �α��� �ð� ����
--	UPDATE dbo.td_account
--	SET LastLoginDate = GetDate()
--	WHERE AccountName LIKE @accname
--
--	SELECT AccountUniqueNumber, AccountType
--	FROM dbo.td_account
--	WHERE AccountName LIKE @accname AND Password LIKE @passwd
--GO
--
----!!!!
---- Name: atum_PreServerMGameLogin
---- Desc:
----====
----DROP PROCEDURE atum_PreServerMGameLogin
--GO
--CREATE PROCEDURE dbo.atum_PreServerMGameLogin
--	@i_AccountName				VARCHAR(20),
--	@i_AccountNameForSearch		VARCHAR(64),
--	@i_Sex						TINYINT,			-- 1: ��, 2: ��
--	@i_BirthYear				INT,				-- ����
--	@i_MGameEventType			INT,
--	@o_AccountType				SMALLINT	OUTPUT
--AS
--	DECLARE @AccountUniqueNumber INT
--	
--	SET @AccountUniqueNumber = (
--		SELECT AccountUniqueNumber
--		FROM dbo.td_account
--		WHERE AccountName LIKE @i_AccountNameForSearch
--	)
--
--	-- ���� �����ڴ� ���� �߰�
--	IF (@AccountUniqueNumber IS NULL)
--		BEGIN
--			INSERT INTO dbo.td_account(AccountName, Sex, BirthYear, MGameEventType)
--			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType)
--		END
--
--	-- ������ �α��� �ð� ����
--	UPDATE dbo.td_account
--	SET LastLoginDate = GetDate()
--	WHERE AccountName LIKE @i_AccountNameForSearch
--
--	SET @AccountUniqueNumber = (
--		SELECT AccountUniqueNumber
--		FROM dbo.td_account
--		WHERE AccountName LIKE @i_AccountNameForSearch
--	)
--	
--	SET @o_AccountType = (
--		SELECT AccountType
--		FROM dbo.td_account
--		WHERE AccountUniqueNumber = @AccountUniqueNumber
--	)
--
--	RETURN @AccountUniqueNumber
--GO




-- // 2008-02-13 by cmkwon, ���� ���� �ý��� ����� - ������� �ʴ� ���ν���
----------------------------------------------------------------------------------
---- MGAME - ���� ����
---- 2006-01-09 by cmkwon, EP2������ atum_db_[n] --> atum2_db_[n]���� ������
----------------------------------------------------------------------------------
--CREATE PROCEDURE dbo.Pb_Delete_User
--	@strUserId char(64)        -- ������ȸ�����̵�
--AS
--	exec atum2_db_1.dbo.Pb_Delete_Character @strUserId
--	exec atum2_db_2.dbo.Pb_Delete_Character @strUserId
--	exec atum2_db_3.dbo.Pb_Delete_Character @strUserId
--
--	-- �������� ����
--	DELETE FROM dbo.td_account WHERE AccountName = @strUserId
--GO


--------------------------------------------------------------------------------
-- MGAME - ���� �� ����
--------------------------------------------------------------------------------
	-- 2005-06-02 by cmkwon
	-- ���� �� ����Ʈ �ε�
	--			2007-01-10 by cmkwon, td_BlockedAccounts ���̺� BlockedReasonForOnlyAdmin �ʵ� �߰���
	CREATE PROCEDURE dbo.atum_Load_BlockAccounts
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
	AS
		-- ��� �ε��Ѵ�
		SELECT AccountName, BlockedType, StartDate, EndDate, AdminAccountName, BlockedReason, BlockedReasonForOnlyAdmin
			FROM dbo.td_blockedaccounts WITH (NOLOCK)
	GO
	
	-- 2005-06-02 by cmkwon
	-- ���� �� ����Ʈ�� �߰� Ȥ�� ���� Update
	--			2007-01-10 by cmkwon, td_BlockedAccounts ���̺� BlockedReasonForOnlyAdmin �ʵ� �߰���
	CREATE PROCEDURE dbo.atum_Insert_BlockedAccounts
		@i_AccountName			VARCHAR(20),
		@i_BlockedType			INT,
		@i_StartDate			VARCHAR(30),
		@i_EndDate				VARCHAR(30),
		@i_AdminAccountName		VARCHAR(20),
		@i_BlockedReason		VARCHAR(200),			-- ������ ���� �� ����
		@i_BlockedReasonForOnlyAdmin	VARCHAR(200)	-- 2007-01-10 by cmkwon, �߰��� - �����ڰ� ���� ������
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
	AS	
		DECLARE @blockedTy INT
		SET @blockedTy = (SELECT BlockedType FROM dbo.td_blockedaccounts WITH(NOLOCK) WHERE AccountName = @i_AccountName)
		
		IF (@blockedTy IS NULL)
			BEGIN
				INSERT INTO dbo.td_blockedaccounts
					VALUES (@i_AccountName, @i_BlockedType, @i_StartDate, @i_EndDate, @i_AdminAccountName, @i_BlockedReason, @i_BlockedReasonForOnlyAdmin)
			END
		ELSE
			BEGIN
				UPDATE dbo.td_blockedaccounts
					SET BlockedType = @i_BlockedType, StartDate = @i_StartDate
							, EndDate = @i_EndDate, AdminAccountName = @i_AdminAccountName, BlockedReason = @i_BlockedReason, BlockedReasonForOnlyAdmin = @i_BlockedReasonForOnlyAdmin
						WHERE AccountName = @i_AccountName
			END	
	GO
	
	-- 2005-06-02 by cmkwon
	-- ���� �� ����Ʈ���� ����
	CREATE PROCEDURE dbo.atum_Delete_BlockedAccounts
		@i_AccountName			VARCHAR(20)
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
	AS
		DELETE FROM dbo.td_blockedaccounts
			WHERE AccountName = @i_AccountName	
	GO

-- End_MGAME - ���� �� ����
--------------------------------------------------------------------------------

-------------------------------
-- Pre Server�� Log Total User
-------------------------------

--!!!!
-- Name: atum_log_insert_total_user
-- Desc: inserts total user count log
--====
--DROP PROCEDURE atum_log_insert_total_user
--GO
CREATE PROCEDURE dbo.atum_log_insert_total_user
	@i_ServerGroupName			VARCHAR(20),	
	@i_MGameServerID			INT,
	@i_UserCount				INT,
	@i_UserCountsOtherPublisherConncect	INT		   -- 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_total_user
	VALUES (GetDate(), @i_ServerGroupName, @i_MGameServerID, @i_UserCount, @i_UserCountsOtherPublisherConncect)
GO


--!!!!
-- Name: atum_ExternalAuthentication
-- Desc: 2006-04-27 by cmkwon, �߰� ��
--		   �ܺ� DB ���� ���ν��� - �̰��� ��� ������ ���ο��� �׽�Ʈ �ϱ� ���� �ʿ��� �����
--		   ������ �� ����� ��� ȸ�翡�� ������ �־�� �Ѵ�.
--====
CREATE PROCEDURE dbo.atum_ExternalAuthentication
	@i_AccountName				VARCHAR(20),	
	@i_Password					VARCHAR(35)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccountUID INT
	
	SET @AccountUID = (SELECT AccountUniqueNumber 
							FROM dbo.td_account
							WHERE AccountName = @i_AccountName AND Password = @i_Password)
	
	IF (@AccountUID IS NULL)
		BEGIN
				RETURN 0
		END

	RETURN 1
GO


--!!!!
-- Name: atum_ExternalAuthentication2
-- Desc: 2007-03-30 by cmkwon, �߰� ��
--		   �ܺ� DB ���� ���ν��� - �̰��� ��� ������ ���ο��� �׽�Ʈ �ϱ� ���� �ʿ��� �����
--		   ������ �� ����� ��� ȸ�翡�� ������ �־�� �Ѵ�.
--====
CREATE PROCEDURE dbo.atum_ExternalAuthentication2
	@o_RetCode					INT				OUTPUT,		-- 2007-03-30 by cmkwon
	@i_AccountName				VARCHAR(20),				-- ������
	@i_Password					VARCHAR(35),				-- �н�����
	@i_WebLoginAuthKey			VARCHAR(20)					-- ������Ű
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SET @o_RetCode		= 0

	DECLARE @AccountUID INT	
	SET @AccountUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_AccountName AND Password = @i_Password)
	
	IF (@AccountUID IS NULL)
	BEGIN
		SET @o_RetCode		= 1
		RETURN
	END

	SET @o_RetCode		= 0
	RETURN
GO

--!!!!
-- Name: atum_ExternalAuthenticationChina
-- Desc: 2007-06-29 by cmkwon, dbo.td_account ���̺� �ֹι�ȣ�����ϱ� - �������ν��� �߰�
--		   �ܺ� DB ���� ���ν��� - �̰��� ��� ������ ���ο��� �׽�Ʈ �ϱ� ���� �ʿ��� �����
--		   ������ �� ����� ��� ȸ�翡�� ������ �־�� �Ѵ�.
--		 // 2007-07-05 by cmkwon, �߱� ���� ���� ���� - output ���ڸ� ��� ������ �ѱ⵵�� ������
--====
CREATE PROCEDURE dbo.atum_ExternalAuthenticationChina
	@i_AccountName				VARCHAR(20),				-- ???
	@i_Password					VARCHAR(35)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @JuminNum VARCHAR(20)
	DECLARE @AccountUID INT	
	SELECT @AccountUID= UserUniqueNumber, @JuminNum= ID_Card 
	FROM member WITH(NOLOCK) 
	WHERE UserID = @i_AccountName AND Password = @i_Password
	
	IF (@AccountUID IS NULL)
	BEGIN
		SELECT 1, NULL
		RETURN
	END

	SELECT 0, @JuminNum
GO

--!!!!
-- Name: atum_GetLastGamePlayData
-- Desc: 2007-06-29 by cmkwon, 2007-06-27 by cmkwon, �߱� ����� �ý��� ���� - �ϳ��� �ֹι�ȣ�� ���� ó��
--		   �ֹι�ȣ �����߿� ���� ���� �÷��� ������ �˻��Ѵ�.
--====
CREATE PROCEDURE dbo.atum_GetLastGamePlayData
	@i_JuminNumber				VARCHAR(20)		-- 2007-06-29 by cmkwon
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 GameContinueTimeInSecondOfToday, LastGameEndDate 
	FROM dbo.td_account WITH(NOLOCK)
	WHERE JuminNumber = @i_JuminNumber 
	ORDER BY LastGameEndDate DESC
GO

--!!!!
--!!!!
-- Name: atum_Change_AccountName_Of_AllServerGroup
-- Desc: 2007-01-22 by cmkwon, �߰� ��
--		   ��� ���������� �ش� ������ ĳ���͸� ã�Ƽ� �������� �ٸ������� �����ϴ� ���ν���
--		   ȫ�浿 ==> *ȫ�浿1, *ȫ�浿2, ..., *ȫ�浿98, *ȫ�浿99
--====
CREATE PROCEDURE dbo.atum_Change_AccountName_Of_AllServerGroup
	@i_AccountName				VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	--------------------------------------------------------------------------------
	-- 1. �ش� ������ �ִ��� üũ
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT AccountUniqueNumber FROM dbo.td_account WHERE AccountName = @i_AccountName)
	IF @OriginAccUID IS NULL
		RETURN 0

	--------------------------------------------------------------------------------
	-- 2. td_Account���̺� ���� ���� �Ϸ��� �������� �˻��Ѵ�
	DECLARE @TmAccName VARCHAR(20)

	SET @TmAccName = LEFT('*' + @i_AccountName, 17)

	DECLARE @i INT
	SET @i = 0

	WHILE @i <= 100
	BEGIN
		IF @i >= 100
			RETURN 0

		DECLARE @AccUID INT
		SET @AccUID = (SELECT TOP 1 AccountUniqueNumber FROM dbo.td_account WHERE AccountName = @TmAccName + CAST(@i AS VARCHAR(20)))

		IF @AccUID IS NULL
			BREAK

		SET @i = @i + 1
	END

	DECLARE @NewAccName VARCHAR(20)
	SET @NewAccName = @TmAccName + CAST(@i AS VARCHAR(20))

	--------------------------------------------------------------------------------
	-- 3. dbo.td_account ���̺� �������� �����ϰ� ���� �ð��� LastLoginDate�� �����Ѵ�.
	UPDATE dbo.td_account
	SET AccountName = @NewAccName, LastLoginDate = GetDate()
	WHERE AccountName = @i_AccountName

	--------------------------------------------------------------------------------
	-- 4. ���� ���� ������ �α� ���̺� �߰��Ѵ�
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - ĳ���� ����
	INSERT INTO atum_log_connection
	VALUES (28, GetDate(), NULL, @OriginAccUID, @i_AccountName, @TmAccName + CAST(@i AS VARCHAR(20)), NULL)

	--------------------------------------------------------------------------------
	-- 5. �� ������ DB�� �������� �����Ѵ�
	-- �� ���� ���񽺿� �°� �����Ѵ� - �ѱ� Yedang_Kor�� atum2_db_1(��ī), atum2_db_7(���)
	exec atum2_db_1.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName
	exec atum2_db_2.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName
	exec atum2_db_3.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName

	RETURN 1
GO


-------------------------------------------------------------------------------
-- Log ���̺� �����ϱ� ���ν���
--		: atum_log_X ���̺���� atum_backup_log_X ���̺������ �����Ѵ�
--		: atum_log_type_info ���̺��� ����
CREATE PROCEDURE dbo.atum_Log_Rename_AccountAllLogTable_to_BackupLog
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	EXEC sp_rename 'atum_log_connection', 			'atum_backup_log_connection'		-- 1
	EXEC sp_rename 'atum_log_total_user', 			'atum_backup_log_total_user'		-- 2	
GO
-- end_Log ���̺� �����ϱ� ���ν���
-------------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- Name: atum_log_insert_block_unblock
-- Desc: -- // 2008-01-29 by cmkwon, ���� ��/���� �α� �ý��� �߰� - ���� ��/����/���� ���� �α� �߰��ϱ�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_insert_block_unblock
	@i_LogType				TINYINT,
	@i_AccountName			VARCHAR(20),
	@i_BlockedType			INT,
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30),
	@i_AdminAccountName		VARCHAR(20),
	@i_BlockedReason		VARCHAR(200),			-- ������ ���� �� ����
	@i_BlockedReasonForOnlyAdmin	VARCHAR(200)	-- 2007-01-10 by cmkwon, �߰��� - �����ڰ� ���� ������
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.atum_log_blockedAccount
	VALUES (@i_LogType, GetDate(), @i_AccountName, @i_BlockedType, @i_StartDate, @i_EndDate, @i_AdminAccountName, @i_BlockedReason, @i_BlockedReasonForOnlyAdmin)
GO

--------------------------------------------------------------------------------
-- Name: dbo.atum_Delete_AccountName
-- Desc: -- // 2008-02-13 by cmkwon, ���� ���� �ý��� ����� - atum2_db_account.dbo.atum_Delete_AccountName() ���ν��� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_AccountName
	@i_AccountName VARCHAR(20)        -- AccountName
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_AccountName)
	IF @AccUID IS NULL
	BEGIN 
		RETURN
	END

	-- 1. �� �����׷쿡�� �ش� ������ ĳ���͸� ��� �����Ѵ�.
	-- �� ���� ���񽺿� �°� �����Ѵ� - �ѱ� Yedang_Kor�� atum2_db_1(��ī), atum2_db_7(���)
	EXEC atum2_db_1.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
	EXEC atum2_db_2.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_3.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName

	-- 2. ����� ���� ���̺��� ����
	DELETE dbo.td_accountcashstore WHERE AccountUniqueNumber = @AccUID

	-- 3. �������� ����
	DELETE FROM dbo.td_account WHERE AccountUniqueNumber = @AccUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0074
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--							atum2_db_account, atum2_db_[n] �Ѵ� �ʿ��� ���ν�����.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0074
	@i_AccName				VARCHAR(20),
	@i_Password				VARCHAR(33),
	@i_MD5EncodedPassword	VARCHAR(33)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT accounttype
	FROM dbo.td_account WITH (NOLOCK)
	WHERE accountname = @i_AccName and (password = @i_Password OR password = @i_MD5EncodedPassword);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0087
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0087
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_account
	SET ConnectingServerGroupID = 0;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0258
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0258
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountUniqueNumber, AccountType, Password FROM dbo.td_account WITH (NOLOCK) WHERE AccountName = @i_AccountName
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertLoginItemEvent
-- SERVER PROC NAME	: PROCEDURE_LOGINITEMEVENT_110825_0001
-- DESC			: // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
--------------------------------------------------------------------------------
-- �̺�Ʈ Ƚ�� ���� ���ν���
CREATE PROC [dbo].[atum_InsertLoginItemEvent]
@i_EventUniqueNumber		INT,
@i_AccountUniqueNumber	INT, 
@i_CompleteFlag		INT
AS
BEGIN
INSERT dbo.atum2_db_account.td_LoginEvent (EventUniqueNumber,AccountUniqueNumber,CompleteFlag)
VALUES(@i_EventUniqueNumber,@i_AccountUniqueNumber,@i_CompleteFlag)
END

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.ti_SystemEvent
-- DESC			: // 2011-12-21 by hskim, EP4 [������ 1ȸ ���]
-- DESC			: EP4 [������ 1ȸ ���] - 0, ������ ���� �ð�
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_SystemEvent]
	@i_ID			INT
AS
-- YD ���� �ڵ�
BEGIN
	SELECT [Date] FROM [atum2_db_account].[dbo].[ti_SystemEvent] WHERE [ID] = @i_ID	
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Update_AccountLastGameEndDate]
-- DESC			: // 2011-12-21 by hskim, EP4 [������ 1ȸ ���]
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_AccountLastGameEndDate]
	@i_AccountUniqueNumber		INT
AS
-- YD ���� �ڵ�
BEGIN
	UPDATE [dbo].[td_Account] SET [LastGameEndDate] = getdate() WHERE AccountUniqueNumber = @i_AccountUniqueNumber
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GNGWC_GetCharacterInfoByAccountUID
-- DESC				: GNGWC �� ĳ���� ���� Ȯ�� ���ν��� (����UID), 2012-08-16 by hskim
--
-- INPUT				: @DataBaseFlag			INT					���� ����	(1 = ��ī, 2 = ���)
--					: @AccountUniqueNumber	INT					���� UID
--
-- OUTPUT			: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_GNGWC_GetCharacterInfoByAccountUID]
	@DataBaseFlag			INT,
	@AccountUniqueNumber	INT
AS
BEGIN
	IF( 1 = @DataBaseFlag )
	BEGIN
		SELECT [Level], [CharacterName], [UnitKind], [InfluenceType] FROM [atum2_db_1].[dbo].[td_Character] WHERE [AccountUniqueNumber] = @AccountUniqueNumber
	END

	IF( 2 = @DataBaseFlag )
	BEGIN
		SELECT [Level], [CharacterName], [UnitKind], [InfluenceType] FROM [atum2_db_7].[dbo].[td_Character] WHERE [AccountUniqueNumber] = @AccountUniqueNumber
	END
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GNGWC_GetCharacterInfoByCharacterName
-- DESC				: GNGWC �� ĳ���� ���� Ȯ�� ���ν��� (ĳ���� �̸�), 2012-08-16 by hskim
--
-- INPUT				: @DataBaseFlag			INT					���� ����	(1 = ��ī, 2 = ���)
--					: @CharacterName		varchar(20)			ĳ���� �̸�
--
-- OUTPUT			: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_GNGWC_GetCharacterInfoByCharacterName]
	@DataBaseFlag			INT,
	@CharacterName		varchar(20)
AS
BEGIN
	IF( 1 = @DataBaseFlag )
	BEGIN
		SELECT [Level], [CharacterName], [UnitKind], [InfluenceType] FROM [atum2_db_1].[dbo].[td_Character] WHERE [CharacterName] = @CharacterName
	END

	IF( 2 = @DataBaseFlag )
	BEGIN
		SELECT [Level], [CharacterName], [UnitKind], [InfluenceType] FROM [atum2_db_7].[dbo].[td_Character] WHERE [CharacterName] = @CharacterName
	END
END
GO


--> 121014_DB��Ű��_(�޽İ���ġ)_DBQuery(atum2_db_account)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Set_AddExp_RestExperienceCount]
-- DESC				: // 2012-10-07 by hskim, �޽� ����ġ
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Set_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT,
	@i_RestExperienceCount		INT
-- YD ���� �ڵ�
AS
BEGIN
	DECLARE @RestExperienceCount	INT

	SELECT @RestExperienceCount = RestExperienceCount FROM atum2_db_account.dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber

	IF( @RestExperienceCount IS NULL )
	BEGIN
		INSERT INTO [atum2_db_account].[dbo].[td_AdditionalExperience] ([AccountUniqueNumber], [RestExperienceCount]) VALUES (@i_AccountUniqueNumber, @i_RestExperienceCount)
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.td_AdditionalExperience SET RestExperienceCount = @i_RestExperienceCount WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Get_AddExp_RestExperienceCount]
-- DESC				: // 2012-10-07 by hskim, �޽� ����ġ
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Get_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT
-- YD ���� �ڵ�
AS
BEGIN
	SELECT RestExperienceCount FROM atum2_db_account.dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber
END
GO
