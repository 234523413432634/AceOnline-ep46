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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	-- // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - SecondaryPassword 가져오기 추가
	-- // 2011-08-25 by shcho, 횟수별 아이템 지급기능 구현 - 컬럼 정보 추가 LastLoginDate clumn
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, BirthYear, SecondaryPassword, LastLoginDate
	FROM dbo.td_account WITH (NOLOCK)
	WHERE AccountName = @i_accname
GO

--!!!!
-- Name:
-- Desc:2006-06-02 by cmkwon, 추가함
-- Desc: // 2012-10-07 by hskim, 휴식 경험치
--====
CREATE PROCEDURE dbo.atum_PreServerUpdateLastLoginDate
	@i_accUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @NowDate				DATETIME; SET @NowDate = GETDATE();
	DECLARE @DiffMin				INT
	DECLARE @RestExperienceCount	INT

	DECLARE @MinTime				INT; SET @MinTime = 300			-- 기본 값 설정	(최소 적용 분	: [300, 5시간])
	DECLARE @MaxCount				INT; SET @MaxCount = 3600		-- 기본 값 설정	(최대 적용 숫자	: [3600, 2분당 1마리, 총 5일, 3600마리)

	UPDATE dbo.td_account SET LastLoginDate = @NowDate WHERE AccountUniqueNumber = @i_accUID

	-- 현재 테이블에 값이 있는지 확인후에 없으면 종료
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
-- Desc: 2006-04-27 by cmkwon, 추가함
--		   외부 DB 인증 로그인 처리 - 비번 체크는 없음, 계정이 없으면 계정 추가, AccountUniqueNumber를 리턴한다.
--		2006-11-15 by cmkwon, Select 검색 필드 추가(td_account테이블에 추가된 필드 - GameContinueTimeInSecondOfToday, LastGameEndDate)
--		2007-06-29 by cmkwon, dbo.td_account 테이블에 주민번호저장하기 - 주민번호 인자 추가
--		// 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - atum_PreServerExtAuthLogin 프로시저 수정
--====
CREATE PROCEDURE dbo.atum_PreServerExtAuthLogin
	@i_AccountName				VARCHAR(20),
	@i_Sex						TINYINT,			-- 1: 남, 2: 여
	@i_BirthYear				INT,				-- 생년
	@i_MGameEventType			INT,
	@i_JuminNumber				VARCHAR(20)			-- 2007-06-29 by cmkwon, dbo.td_account 테이블에 주민번호저장하기 - 추가된 인자
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccountUID INT
	SET @AccountUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH (NOLOCK) WHERE AccountName = @i_AccountName)

	-- 최초 접속자는 계정 추가
	IF (@AccountUID IS NULL)
	BEGIN
		INSERT INTO dbo.td_account(AccountName, Sex, BirthYear, MGameEventType, JuminNumber)
			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType, @i_JuminNumber)
	END
	ELSE
	BEGIN
		-- 2007-03-30 by cmkwon
		-- SQLMoreResults()의 개수를 맞추기 위해서 추가한 코드임
		UPDATE dbo.td_account
			SET Sex = Sex
			WHERE AccountName = @i_AccountName
	END
	
	-- 마지막 로그인 시간 저장
	UPDATE dbo.td_account
		SET LastLoginDate = GetDate()
		WHERE AccountName = @i_AccountName	
	
	-- // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - SecondaryPassword 가져오기 추가
	SELECT AccountUniqueNumber, AccountType, Password, RegisteredDate, GameContinueTimeInSecondOfToday, LastGameEndDate, SecondaryPassword
		FROM dbo.td_account WHERE AccountName = @i_AccountName
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
--	@i_Sex						TINYINT,			-- 1: 남, 2: 여
--	@i_BirthYear				INT,				-- 생년
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
--	-- 최초 접속자는 계정 추가
--	IF (@AccountUniqueNumber IS NULL)
--		BEGIN
--			INSERT INTO dbo.td_account(AccountName, Sex, BirthYear, MGameEventType)
--			VALUES(@i_AccountName, @i_Sex, @i_BirthYear, @i_MGameEventType)
--		END
--
--	-- 마지막 로그인 시간 저장
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
--	DELETE FROM dbo.td_account WHERE AccountName = @strUserId
--GO


--------------------------------------------------------------------------------
-- MGAME - 계정 블럭 관리
--------------------------------------------------------------------------------
	-- 2005-06-02 by cmkwon
	-- 계정 블럭 리스트 로딩
	--			2007-01-10 by cmkwon, td_BlockedAccounts 테이블에 BlockedReasonForOnlyAdmin 필드 추가함
	CREATE PROCEDURE dbo.atum_Load_BlockAccounts
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
	AS
		-- 모두 로딩한다
		SELECT AccountName, BlockedType, StartDate, EndDate, AdminAccountName, BlockedReason, BlockedReasonForOnlyAdmin
			FROM dbo.td_blockedaccounts WITH (NOLOCK)
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
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
	-- 계정 블럭 리스트에서 제거
	CREATE PROCEDURE dbo.atum_Delete_BlockedAccounts
		@i_AccountName			VARCHAR(20)
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
	AS
		DELETE FROM dbo.td_blockedaccounts
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
	@i_UserCount				INT,
	@i_UserCountsOtherPublisherConncect	INT		   -- 2010-11 by dhjin, 아라리오 채널링 로그인
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	INSERT INTO atum_log_total_user
	VALUES (GetDate(), @i_ServerGroupName, @i_MGameServerID, @i_UserCount, @i_UserCountsOtherPublisherConncect)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- Desc: 2007-03-30 by cmkwon, 추가 함
--		   외부 DB 인증 프로시저 - 이것은 없어도 되지만 내부에서 테스트 하기 위해 필요한 모듈임
--		   실제로 이 모듈은 상대 회사에서 구현해 주어야 한다.
--====
CREATE PROCEDURE dbo.atum_ExternalAuthentication2
	@o_RetCode					INT				OUTPUT,		-- 2007-03-30 by cmkwon
	@i_AccountName				VARCHAR(20),				-- 계정명
	@i_Password					VARCHAR(35),				-- 패스워드
	@i_WebLoginAuthKey			VARCHAR(20)					-- 웹인증키
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- Desc: 2007-06-29 by cmkwon, dbo.td_account 테이블에 주민번호저장하기 - 인증프로시저 추가
--		   외부 DB 인증 프로시저 - 이것은 없어도 되지만 내부에서 테스트 하기 위해 필요한 모듈임
--		   실제로 이 모듈은 상대 회사에서 구현해 주어야 한다.
--		 // 2007-07-05 by cmkwon, 중국 인증 오류 수정 - output 인자를 결과 쿼리로 넘기도록 수정함
--====
CREATE PROCEDURE dbo.atum_ExternalAuthenticationChina
	@i_AccountName				VARCHAR(20),				-- ???
	@i_Password					VARCHAR(35)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT TOP 1 GameContinueTimeInSecondOfToday, LastGameEndDate 
	FROM dbo.td_account WITH(NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	--------------------------------------------------------------------------------
	-- 1. 해당 계정이 있는지 체크
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT AccountUniqueNumber FROM dbo.td_account WHERE AccountName = @i_AccountName)
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
		SET @AccUID = (SELECT TOP 1 AccountUniqueNumber FROM dbo.td_account WHERE AccountName = @TmAccName + CAST(@i AS VARCHAR(20)))

		IF @AccUID IS NULL
			BREAK

		SET @i = @i + 1
	END

	DECLARE @NewAccName VARCHAR(20)
	SET @NewAccName = @TmAccName + CAST(@i AS VARCHAR(20))

	--------------------------------------------------------------------------------
	-- 3. dbo.td_account 테이블에 계정명을 변경하고 현재 시간을 LastLoginDate에 저장한다.
	UPDATE dbo.td_account
	SET AccountName = @NewAccName, LastLoginDate = GetDate()
	WHERE AccountName = @i_AccountName

	--------------------------------------------------------------------------------
	-- 4. 계정 변경 정보를 로그 테이블에 추가한다
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - 캐릭터 삭제
	INSERT INTO atum_log_connection
	VALUES (28, GetDate(), NULL, @OriginAccUID, @i_AccountName, @TmAccName + CAST(@i AS VARCHAR(20)), NULL)

	--------------------------------------------------------------------------------
	-- 5. 각 서버군 DB에 계정명을 변경한다
	-- 각 나라별 서비스에 맞게 설정한다 - 한국 Yedang_Kor은 atum2_db_1(데카), atum2_db_7(비숍)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_AccountName)
	IF @AccUID IS NULL
	BEGIN 
		RETURN
	END

	-- 1. 각 서버그룹에서 해당 계정의 캐릭터를 모두 삭제한다.
	-- 각 나라별 서비스에 맞게 설정한다 - 한국 Yedang_Kor은 atum2_db_1(데카), atum2_db_7(비숍)
	EXEC atum2_db_1.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
	EXEC atum2_db_2.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName
--	EXEC atum2_db_3.dbo.atum_Delete_All_Character_By_AccountName @i_AccountName

	-- 2. 멤버쉽 서비스 테이블에서 삭제
	DELETE dbo.td_accountcashstore WHERE AccountUniqueNumber = @AccUID

	-- 3. 계정에서 제거
	DELETE FROM dbo.td_account WHERE AccountUniqueNumber = @AccUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0074
-- DESC				: -- // 2008-08-27 by cmkwon, 날쿼리를 Procedure로 수정 - 
--							atum2_db_account, atum2_db_[n] 둘다 필요한 프로시저임.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0074
	@i_AccName				VARCHAR(20),
	@i_Password				VARCHAR(33),
	@i_MD5EncodedPassword	VARCHAR(33)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT accounttype
	FROM dbo.td_account WITH (NOLOCK)
	WHERE accountname = @i_AccName and (password = @i_Password OR password = @i_MD5EncodedPassword);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0087
-- DESC				: -- // 2008-08-27 by cmkwon, 날쿼리를 Procedure로 수정 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0087
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	UPDATE dbo.td_account
	SET ConnectingServerGroupID = 0;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0258
-- DESC				: -- // 2008-08-27 by cmkwon, 날쿼리를 Procedure로 수정 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0258
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT AccountUniqueNumber, AccountType, Password FROM dbo.td_account WITH (NOLOCK) WHERE AccountName = @i_AccountName
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertLoginItemEvent
-- SERVER PROC NAME	: PROCEDURE_LOGINITEMEVENT_110825_0001
-- DESC			: // 2011-08-25 by shcho, 횟수별 아이템 지급기능 구현
--------------------------------------------------------------------------------
-- 이벤트 횟수 삽입 프로시저
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
-- DESC			: // 2011-12-21 by hskim, EP4 [동영상 1회 재생]
-- DESC			: EP4 [동영상 1회 재생] - 0, 동영상 기준 시간
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_SystemEvent]
	@i_ID			INT
AS
-- YD 보안 코드
BEGIN
	SELECT [Date] FROM [atum2_db_account].[dbo].[ti_SystemEvent] WHERE [ID] = @i_ID	
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Update_AccountLastGameEndDate]
-- DESC			: // 2011-12-21 by hskim, EP4 [동영상 1회 재생]
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_AccountLastGameEndDate]
	@i_AccountUniqueNumber		INT
AS
-- YD 보안 코드
BEGIN
	UPDATE [dbo].[td_Account] SET [LastGameEndDate] = getdate() WHERE AccountUniqueNumber = @i_AccountUniqueNumber
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GNGWC_GetCharacterInfoByAccountUID
-- DESC				: GNGWC 용 캐릭터 정보 확인 프로시져 (계정UID), 2012-08-16 by hskim
--
-- INPUT				: @DataBaseFlag			INT					서버 종류	(1 = 데카, 2 = 비숍)
--					: @AccountUniqueNumber	INT					계정 UID
--
-- OUTPUT			: [Level]				tinyint				캐릭터 레벨	(1~110)
--					: [CharacterName]		varchar(20)			캐릭터 이름
--					: [UnitKind]			int					기어종류		(1 ~ 15 = B기어, 16 ~ 240 = M기어, 256 ~ 3840 = A기어, 4096 ~ 61440 = I기어)
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
-- DESC				: GNGWC 용 캐릭터 정보 확인 프로시져 (캐릭터 이름), 2012-08-16 by hskim
--
-- INPUT				: @DataBaseFlag			INT					서버 종류	(1 = 데카, 2 = 비숍)
--					: @CharacterName		varchar(20)			캐릭터 이름
--
-- OUTPUT			: [Level]				tinyint				캐릭터 레벨	(1~110)
--					: [CharacterName]		varchar(20)			캐릭터 이름
--					: [UnitKind]			int					기어종류		(1 ~ 15 = B기어, 16 ~ 240 = M기어, 256 ~ 3840 = A기어, 4096 ~ 61440 = I기어)
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


--> 121014_DB스키마_(휴식경험치)_DBQuery(atum2_db_account)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Set_AddExp_RestExperienceCount]
-- DESC				: // 2012-10-07 by hskim, 휴식 경험치
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Set_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT,
	@i_RestExperienceCount		INT
-- YD 보안 코드
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
-- DESC				: // 2012-10-07 by hskim, 휴식 경험치
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Get_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT
-- YD 보안 코드
AS
BEGIN
	SELECT RestExperienceCount FROM atum2_db_account.dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber
END
GO
