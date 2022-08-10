--------------------------------------------------------------
-- Pre Server 관련
--------------------------------------------------------------


--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, 추가함
--		2006-11-15 by cmkwon, Select 검색 필드 추가(td_account테이블에 추가된 필드 - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-28 by cmkwon, 중국 방심취관련(출생년월일 FielServer로 가져오기) - 검색 결과에 BirthYear 필드 추가
--		// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - atum_PreServerGetAccountInfo 프로시저 수정
--====
CREATE PROCEDURE dbo.atum_PreServerGetAccountInfo
	@i_accname			varchar(20)
AS
	-- // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - SecondaryPassword 가져오기 추가
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, BirthYear, SecondaryPassword
	FROM td_Account WITH (NOLOCK)
	WHERE AccountName = @i_accname
GO

--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, 추가함
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
-- Desc: 2006-04-27 by cmkwon, 추가함
--		   외부 DB 인증 로그인 처리 - 비번 체크는 없음, 계정이 없으면 계정 추가, AccountUniqueNumber를 리턴한다.
--		2006-11-15 by cmkwon, Select 검색 필드 추가(td_account테이블에 추가된 필드 - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-29 by cmkwon, td_account 테이블에 주민번호저장하기 - 주민번호 인자 추가
--		// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - atum_PreServerExtAuthLogin 프로시저 수정
--====
CREATE PROCEDURE dbo.atum_PreServerExtAuthLogin
	@i_AccountName				VARCHAR(20),
	@i_Sex						TINYINT,			-- 1: 남, 2: 여
	@i_BirthYear				INT,				-- 생년
	@i_MGameEventType			INT,
	@i_JuminNumber				VARCHAR(20)			-- 2007-06-29 by cmkwon, td_account 테이블에 주민번호저장하기 - 추가된 인자
AS
	DECLARE @AccountUID INT
	SET @AccountUID = (SELECT AccountUniqueNumber FROM td_Account WITH (NOLOCK) WHERE AccountName = @i_AccountName)

	-- 최초 접속자는 계정 추가
	IF (@AccountUID IS NULL)
	BEGIN
		INSERT INTO td_Account(AccountName, Sex, BirthYear, MGameEventType, JuminNumber)
			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType, @i_JuminNumber)
	END
	ELSE
	BEGIN
		-- 2007-03-30 by cmkwon
		-- SQLMoreResults()의 개수를 맞추기 위해서 추가한 코드임
		UPDATE td_Account
			SET Sex = Sex
			WHERE AccountName = @i_AccountName
	END
	
	-- 마지막 로그인 시간 저장
	UPDATE td_Account
		SET LastLoginDate = GetDate()
		WHERE AccountName = @i_AccountName	
	
	-- // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - SecondaryPassword 가져오기 추가
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, SecondaryPassword
		FROM td_Account WHERE AccountName = @i_AccountName
GO




-- 2006-06-02 by cmkwon, atum_PreServerExtAuthLogin 로 통합
----!!!!
---- Name:
---- Desc:
----====
--CREATE PROCEDURE dbo.atum_PreServerLogin
--	@accname			varchar(64),
--	@passwd				varchar(35)
--AS
--	-- 마지막 로그인 시간 저장
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
--	@i_Sex						TINYINT,			-- 1: 남, 2: 여
--	@i_BirthYear				INT,				-- 생년
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
--	-- 최초 접속자는 계정 추가
--	IF (@AccountUniqueNumber IS NULL)
--		BEGIN
--			INSERT INTO td_Account(AccountName, Sex, BirthYear, MGameEventType)
--			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType)
--		END
--
--	-- 마지막 로그인 시간 저장
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




-- // 2008-02-13 by cmkwon, 계정 삭제 시스템 만들기 - 사용하지 않는 프로시저
----------------------------------------------------------------------------------
---- MGAME - 유저 삭제
---- 2006-01-09 by cmkwon, EP2용으로 atum_db_[n] --> atum2_db_[n]으로 변경함
----------------------------------------------------------------------------------
--CREATE PROCEDURE dbo.Pb_Delete_User
--	@strUserId char(64)        -- 엠게임회원아이디
--AS
--	exec atum2_db_1.dbo.Pb_Delete_Character @strUserId
--	exec atum2_db_2.dbo.Pb_Delete_Character @strUserId
--	exec atum2_db_3.dbo.Pb_Delete_Character @strUserId
--
--	-- 계정에서 제거
--	DELETE FROM td_Account WHERE AccountName = @strUserId
--GO


--------------------------------------------------------------------------------
-- MGAME - 계정 블럭 관리
--------------------------------------------------------------------------------
	-- 2005-06-02 by cmkwon
	-- 계정 블럭 리스트 로딩
	--			2007-01-10 by cmkwon, td_BlockedAccounts 테이블에 BlockedReasonForOnlyAdmin 필드 추가함
	CREATE PROCEDURE dbo.atum_Load_BlockAccounts
	AS
		-- 모두 로딩한다
		SELECT AccountName, BlockedType, StartDate, EndDate, AdminAccountName, BlockedReason, BlockedReasonForOnlyAdmin
			FROM td_BlockedAccounts WITH (NOLOCK)
	GO
	
	-- 2005-06-02 by cmkwon
	-- 계정 블럭 리스트에 추가 혹은 정보 Update
	--			2007-01-10 by cmkwon, td_BlockedAccounts 테이블에 BlockedReasonForOnlyAdmin 필드 추가함
	CREATE PROCEDURE dbo.atum_Insert_BlockedAccounts
		@i_AccountName			VARCHAR(20),
		@i_BlockedType			INT,
		@i_StartDate			VARCHAR(30),
		@i_EndDate				VARCHAR(30),
		@i_AdminAccountName		VARCHAR(20),
		@i_BlockedReason		VARCHAR(200),			-- 유저가 보는 블럭 사유
		@i_BlockedReasonForOnlyAdmin	VARCHAR(200)	-- 2007-01-10 by cmkwon, 추가함 - 관리자가 보는 블럭사유
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
	-- 계정 블럭 리스트에서 제거
	CREATE PROCEDURE dbo.atum_Delete_BlockedAccounts
		@i_AccountName			VARCHAR(20)
	AS
		DELETE FROM td_BlockedAccounts
			WHERE AccountName = @i_AccountName	
	GO

-- End_MGAME - 계정 블럭 관리
--------------------------------------------------------------------------------

-------------------------------
-- Pre Server용 Log Total User
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
-- Desc: 2006-04-27 by cmkwon, 추가 함
--		   외부 DB 인증 프로시저 - 이것은 없어도 되지만 내부에서 테스트 하기 위해 필요한 모듈임
--		   실제로 이 모듈은 상대 회사에서 구현해 주어야 한다.
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
-- Desc: 2007-03-30 by cmkwon, 추가 함
--		   외부 DB 인증 프로시저 - 이것은 없어도 되지만 내부에서 테스트 하기 위해 필요한 모듈임
--		   실제로 이 모듈은 상대 회사에서 구현해 주어야 한다.
--====
CREATE PROCEDURE dbo.atum_ExternalAuthentication2
	@o_RetCode					INT				OUTPUT,		-- 2007-03-30 by cmkwon
	@i_AccountName				VARCHAR(20),				-- 계정명
	@i_Password					VARCHAR(35),				-- 패스워드
	@i_WebLoginAuthKey			VARCHAR(20)					-- 웹인증키
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
-- Desc: 2007-06-29 by cmkwon, td_account 테이블에 주민번호저장하기 - 인증프로시저 추가
--		   외부 DB 인증 프로시저 - 이것은 없어도 되지만 내부에서 테스트 하기 위해 필요한 모듈임
--		   실제로 이 모듈은 상대 회사에서 구현해 주어야 한다.
--		 // 2007-07-05 by cmkwon, 중국 인증 오류 수정 - output 인자를 결과 쿼리로 넘기도록 수정함
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
-- Desc: 2007-06-29 by cmkwon, 2007-06-27 by cmkwon, 중국 방심취 시스템 수정 - 하나의 주민번호에 계정 처리
--		   주민번호 계정중에 최종 게임 플레이 정보를 검색한다.
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
-- Desc: 2007-01-22 by cmkwon, 추가 함
--		   모든 서버군에서 해당 계정의 캐릭터를 찾아서 계정명을 다른것으로 변경하는 프로시저
--		   홍길동 ==> *홍길동1, *홍길동2, ..., *홍길동98, *홍길동99
--====
CREATE PROCEDURE dbo.atum_Change_AccountName_Of_AllServerGroup
	@i_AccountName				VARCHAR(20)
AS
	--------------------------------------------------------------------------------
	-- 1. 해당 계정이 있는지 체크
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT AccountUniqueNumber FROM td_Account WHERE AccountName = @i_AccountName)
	IF @OriginAccUID IS NULL
		RETURN 0

	--------------------------------------------------------------------------------
	-- 2. td_Account테이블에 없는 변경 하려는 계정명을 검색한다
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
	-- 3. td_Account 테이블에 계정명을 변경하고 현재 시간을 LastLoginDate에 저장한다.
	UPDATE td_Account
	SET AccountName = @NewAccName, LastLoginDate = GetDate()
	WHERE AccountName = @i_AccountName

	--------------------------------------------------------------------------------
	-- 4. 계정 변경 정보를 로그 테이블에 추가한다
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - 캐릭터 삭제
	INSERT INTO atum_log_connection
	VALUES (28, GetDate(), NULL, @OriginAccUID, @i_AccountName, @TmAccName + CAST(@i AS VARCHAR(20)))

	--------------------------------------------------------------------------------
	-- 5. 각 서버군 DB에 계정명을 변경한다
	exec atum2_db_1.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName
	exec atum2_db_2.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName
	exec atum2_db_3.dbo.atum_Change_AccountName_Of_AllCharacter @i_AccountName, @NewAccName

	RETURN 1
GO


-------------------------------------------------------------------------------
-- Log 테이블 정리하기 프로시저
--		: atum_log_X 테이블명을 atum_backup_log_X 테이블명으로 변경한다
--		: atum_log_type_info 테이블은 제외
CREATE PROCEDURE dbo.atum_Log_Rename_AccountAllLogTable_to_BackupLog
AS
	EXEC sp_rename 'atum_log_connection', 			'atum_backup_log_connection'		-- 1
	EXEC sp_rename 'atum_log_total_user', 			'atum_backup_log_total_user'		-- 2	
GO
-- end_Log 테이블 정리하기 프로시저
-------------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- Name: atum_log_insert_block_unblock
-- Desc: -- // 2008-01-29 by cmkwon, 계정 블럭/해제 로그 시스템 추가 - 계정 블럭/수정/해제 정보 로그 추가하기
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_insert_block_unblock
	@i_LogType				TINYINT,
	@i_AccountName			VARCHAR(20),
	@i_BlockedType			INT,
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30),
	@i_AdminAccountName		VARCHAR(20),
	@i_BlockedReason		VARCHAR(200),			-- 유저가 보는 블럭 사유
	@i_BlockedReasonForOnlyAdmin	VARCHAR(200)	-- 2007-01-10 by cmkwon, 추가함 - 관리자가 보는 블럭사유
AS
	INSERT INTO dbo.atum_log_blockedAccount
	VALUES (@i_LogType, GetDate(), @i_AccountName, @i_BlockedType, @i_StartDate, @i_EndDate, @i_AdminAccountName, @i_BlockedReason, @i_BlockedReasonForOnlyAdmin)
GO

--------------------------------------------------------------------------------
-- Name: dbo.atum_Delete_AccountName
-- Desc: -- // 2008-02-13 by cmkwon, 계정 삭제 시스템 만들기 - atum2_db_account.dbo.atum_Delete_AccountName() 프로시저 추가
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

	-- 1. 각 서버그룹에서 해당 계정의 캐릭터를 모두 삭제한다.
	EXEC atum2_db_test.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_2.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_3.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName

	-- 2. 멤버쉽 서비스 테이블에서 삭제
	DELETE dbo.td_AccountCashStore WHERE AccountUniqueNumber = @AccUID

	-- 3. 계정에서 제거
	DELETE FROM dbo.td_Account WHERE AccountUniqueNumber = @AccUID
GO

