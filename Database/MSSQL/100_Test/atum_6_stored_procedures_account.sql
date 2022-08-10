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
AS
	-- // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - SecondaryPassword �������� �߰�
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, BirthYear, SecondaryPassword
	FROM td_Account WITH (NOLOCK)
	WHERE AccountName = @i_accname
GO

--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, �߰���
--====
CREATE PROCEDURE dbo.atum_PreServerUpdateLastLoginDate
	@i_accUID			INT
AS
	UPDATE td_Account
		SET LastLoginDate = GetDate()
		WHERE AccountUniqueNumber = @i_accUID
GO


--!!!!
-- Name: atum_PreServerExtAuthLogin
-- Desc: 2006-04-27 by cmkwon, �߰���
--		   �ܺ� DB ���� �α��� ó�� - ��� üũ�� ����, ������ ������ ���� �߰�, AccountUniqueNumber�� �����Ѵ�.
--		2006-11-15 by cmkwon, Select �˻� �ʵ� �߰�(td_account���̺� �߰��� �ʵ� - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-29 by cmkwon, td_account ���̺� �ֹι�ȣ�����ϱ� - �ֹι�ȣ ���� �߰�
--		// 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - atum_PreServerExtAuthLogin ���ν��� ����
--====
CREATE PROCEDURE dbo.atum_PreServerExtAuthLogin
	@i_AccountName				VARCHAR(20),
	@i_Sex						TINYINT,			-- 1: ��, 2: ��
	@i_BirthYear				INT,				-- ����
	@i_MGameEventType			INT,
	@i_JuminNumber				VARCHAR(20)			-- 2007-06-29 by cmkwon, td_account ���̺� �ֹι�ȣ�����ϱ� - �߰��� ����
AS
	DECLARE @AccountUID INT
	SET @AccountUID = (SELECT AccountUniqueNumber FROM td_Account WITH (NOLOCK) WHERE AccountName = @i_AccountName)

	-- ���� �����ڴ� ���� �߰�
	IF (@AccountUID IS NULL)
	BEGIN
		INSERT INTO td_Account(AccountName, Sex, BirthYear, MGameEventType, JuminNumber)
			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType, @i_JuminNumber)
	END
	ELSE
	BEGIN
		-- 2007-03-30 by cmkwon
		-- SQLMoreResults()�� ������ ���߱� ���ؼ� �߰��� �ڵ���
		UPDATE td_Account
			SET Sex = Sex
			WHERE AccountName = @i_AccountName
	END
	
	-- ������ �α��� �ð� ����
	UPDATE td_Account
		SET LastLoginDate = GetDate()
		WHERE AccountName = @i_AccountName	
	
	-- // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - SecondaryPassword �������� �߰�
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, SecondaryPassword
		FROM td_Account WHERE AccountName = @i_AccountName
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
--	UPDATE td_Account
--	SET LastLoginDate = GetDate()
--	WHERE AccountName LIKE @accname
--
--	SELECT AccountUniqueNumber, AccountType
--	FROM td_Account
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
--		FROM td_Account
--		WHERE AccountName LIKE @i_AccountNameForSearch
--	)
--
--	-- ���� �����ڴ� ���� �߰�
--	IF (@AccountUniqueNumber IS NULL)
--		BEGIN
--			INSERT INTO td_Account(AccountName, Sex, BirthYear, MGameEventType)
--			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType)
--		END
--
--	-- ������ �α��� �ð� ����
--	UPDATE td_Account
--	SET LastLoginDate = GetDate()
--	WHERE AccountName LIKE @i_AccountNameForSearch
--
--	SET @AccountUniqueNumber = (
--		SELECT AccountUniqueNumber
--		FROM td_Account
--		WHERE AccountName LIKE @i_AccountNameForSearch
--	)
--	
--	SET @o_AccountType = (
--		SELECT AccountType
--		FROM td_Account
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
--	DELETE FROM td_Account WHERE AccountName = @strUserId
--GO


--------------------------------------------------------------------------------
-- MGAME - ���� �� ����
--------------------------------------------------------------------------------
	-- 2005-06-02 by cmkwon
	-- ���� �� ����Ʈ �ε�
	--			2007-01-10 by cmkwon, td_BlockedAccounts ���̺� BlockedReasonForOnlyAdmin �ʵ� �߰���
	CREATE PROCEDURE dbo.atum_Load_BlockAccounts
	AS
		-- ��� �ε��Ѵ�
		SELECT AccountName, BlockedType, StartDate, EndDate, AdminAccountName, BlockedReason, BlockedReasonForOnlyAdmin
			FROM td_BlockedAccounts WITH (NOLOCK)
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
	AS	
		DECLARE @blockedTy INT
		SET @blockedTy = (SELECT BlockedType FROM td_BlockedAccounts WHERE AccountName = @i_AccountName)
		
		IF (@blockedTy IS NULL)
			BEGIN
				INSERT INTO td_BlockedAccounts
					VALUES (@i_AccountName, @i_BlockedType, @i_StartDate, @i_EndDate, @i_AdminAccountName, @i_BlockedReason, @i_BlockedReasonForOnlyAdmin)
			END
		ELSE
			BEGIN
				UPDATE td_BlockedAccounts
					SET BlockedType = @i_BlockedType, StartDate = @i_StartDate
							, EndDate = @i_EndDate, AdminAccountName = @i_AdminAccountName, BlockedReason = @i_BlockedReason, BlockedReasonForOnlyAdmin = @i_BlockedReasonForOnlyAdmin
						WHERE AccountName = @i_AccountName
			END	
	GO
	
	-- 2005-06-02 by cmkwon
	-- ���� �� ����Ʈ���� ����
	CREATE PROCEDURE dbo.atum_Delete_BlockedAccounts
		@i_AccountName			VARCHAR(20)
	AS
		DELETE FROM td_BlockedAccounts
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
	@i_UserCount				INT
AS
	INSERT INTO atum_log_total_user
	VALUES (GetDate(), @i_ServerGroupName, @i_MGameServerID, @i_UserCount)
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
AS
	DECLARE @AccountUID INT
	
	SET @AccountUID = (SELECT AccountUniqueNumber 
							FROM td_Account
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
AS
	SET @o_RetCode		= 0

	DECLARE @AccountUID INT	
	SET @AccountUID = (SELECT AccountUniqueNumber FROM td_Account WITH(NOLOCK) WHERE AccountName = @i_AccountName AND Password = @i_Password)
	
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
-- Desc: 2007-06-29 by cmkwon, td_account ���̺� �ֹι�ȣ�����ϱ� - �������ν��� �߰�
--		   �ܺ� DB ���� ���ν��� - �̰��� ��� ������ ���ο��� �׽�Ʈ �ϱ� ���� �ʿ��� �����
--		   ������ �� ����� ��� ȸ�翡�� ������ �־�� �Ѵ�.
--		 // 2007-07-05 by cmkwon, �߱� ���� ���� ���� - output ���ڸ� ��� ������ �ѱ⵵�� ������
--====
CREATE PROCEDURE dbo.atum_ExternalAuthenticationChina
	@i_AccountName				VARCHAR(20),				-- ???
	@i_Password					VARCHAR(35)
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
AS
	SELECT TOP 1 GameContinueTimeInSecondOfToday, LastGameEndDate 
	FROM td_Account WITH(NOLOCK)
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
AS
	--------------------------------------------------------------------------------
	-- 1. �ش� ������ �ִ��� üũ
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT AccountUniqueNumber FROM td_Account WHERE AccountName = @i_AccountName)
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
		SET @AccUID = (SELECT TOP 1 AccountUniqueNumber FROM td_Account WHERE AccountName = @TmAccName + CAST(@i AS VARCHAR(20)))

		IF @AccUID IS NULL
			BREAK

		SET @i = @i + 1
	END

	DECLARE @NewAccName VARCHAR(20)
	SET @NewAccName = @TmAccName + CAST(@i AS VARCHAR(20))

	--------------------------------------------------------------------------------
	-- 3. td_Account ���̺� �������� �����ϰ� ���� �ð��� LastLoginDate�� �����Ѵ�.
	UPDATE td_Account
	SET AccountName = @NewAccName, LastLoginDate = GetDate()
	WHERE AccountName = @i_AccountName

	--------------------------------------------------------------------------------
	-- 4. ���� ���� ������ �α� ���̺� �߰��Ѵ�
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - ĳ���� ����
	INSERT INTO atum_log_connection
	VALUES (28, GetDate(), NULL, @OriginAccUID, @i_AccountName, @TmAccName + CAST(@i AS VARCHAR(20)))

	--------------------------------------------------------------------------------
	-- 5. �� ������ DB�� �������� �����Ѵ�
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
AS
	DECLARE @AccUID INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_AccountName)
	IF @AccUID IS NULL
	BEGIN 
		RETURN
	END

	-- 1. �� �����׷쿡�� �ش� ������ ĳ���͸� ��� �����Ѵ�.
	EXEC atum2_db_test.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_2.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_3.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName

	-- 2. ����� ���� ���̺��� ����
	DELETE dbo.td_AccountCashStore WHERE AccountUniqueNumber = @AccUID

	-- 3. �������� ����
	DELETE FROM dbo.td_Account WHERE AccountUniqueNumber = @AccUID
GO

