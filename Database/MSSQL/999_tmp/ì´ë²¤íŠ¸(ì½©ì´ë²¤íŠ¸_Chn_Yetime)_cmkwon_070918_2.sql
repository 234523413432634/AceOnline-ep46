

-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_item
-- Desc: // 2007-09-18 by cmkwon, 아이템 검색
--
-- parameter:
--
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_item
	@o_ItemUID					BIGINT			OUTPUT,
	@o_CurCnts					INT				OUTPUT,
	@i_AccUID					INT,
	@i_CharUID					INT,
	@i_ItemNum					INT
AS	
	SET @o_ItemUID = (SELECT TOP 1 UniqueNumber
							FROM td_store WITH(NOLOCK)
							WHERE AccountUniqueNumber = @i_AccUID AND Possess = @i_CharUID AND ItemStorage = 0 AND ItemNum = @i_ItemNum
							ORDER BY UniqueNumber)
	IF (@o_ItemUID IS NOT NULL)
	BEGIN
		SET	@o_CurCnts	= (SELECT CurrentCount
							FROM td_store WITH(NOLOCK)
							WHERE UniqueNumber = @o_ItemUID)
	END

	IF (@o_CurCnts IS NULL) OR (0 > @o_CurCnts)
	BEGIN
		SET @o_CurCnts	= 0
	END
GO

-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_use_item
-- Desc: // 2007-09-18 by cmkwon, 아이템 개수를 업데이트 한다.
--
-- parameter:
--
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_use_item
	@i_CharUID					INT,
	@i_ItemNum					INT,
	@i_ItemUID					BIGINT,
	@i_CurCnts					INT,
	@i_UseCnts					INT
AS	
	DECLARE @RemainCnts INT
	SET @RemainCnts = @i_CurCnts - @i_UseCnts
	IF (0 >= @RemainCnts)
	BEGIN

		-- 개수가 0으로 되었으므로 아이템을 삭제한다.
		DELETE td_store
		WHERE UniqueNumber = @i_ItemUID
	END
	ELSE
	BEGIN

		-- 사용한 개수만큼 제하고 현재 개수를 업데이트 한다.
		UPDATE td_store
		SET CurrentCount = @RemainCnts
		WHERE UniqueNumber = @i_ItemUID
	END

	-------------------------------------------------------------------------------
	-- 사용 정보를 로그에 저장한다.
	-- #define T1_FL_LOG_ITEM_USE_ITEM					0x27	// 39 - 아이템 사용
	INSERT INTO atum_log_item_charac_use
	VALUES (39, GetDate(), @i_CharUID, 0,
			@i_ItemUID, @i_ItemNum, @RemainCnts, @i_UseCnts)

GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_characters
-- Desc: // 2007-09-18 by cmkwon, 계정명으로 삭제되지 않은 캐릭터를 가져온다
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--
-- parameter:
--		[1] INPUT @i_AccountName	: 검색하려는 계정명
--
-- 결과 record set: [캐릭터명 1] [캐릭터명 2] [캐릭터명 3]
--		[1]	[캐릭터명 1]	: VARCHAR(20), 캐릭터명 1
--		[1]	[캐릭터명 2]	: VARCHAR(20), 캐릭터명 2
--		[1]	[캐릭터명 3]	: VARCHAR(20), 캐릭터명 3
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_characters
	@i_AccountName				VARCHAR(20)				-- 계정명
AS
	DECLARE @CharName1 VARCHAR(20)
	SET @CharName1 = (SELECT TOP 1 CharacterName 
						FROM td_character WITH(NOLOCK) 
						WHERE AccountName = @i_AccountName AND 0 = (Race & 0x4000)
						ORDER BY CharacterName)
	IF (@CharName1 IS NULL)
	BEGIN
		SELECT NULL, NULL, NULL
		RETURN
	END

	DECLARE @CharName2 VARCHAR(20)
	SET @CharName2 = (SELECT TOP 1 CharacterName 
						FROM td_character WITH(NOLOCK)
						WHERE AccountName = @i_AccountName AND 0 = (Race & 0x4000) AND CharacterName <> @CharName1
						ORDER BY CharacterName)
	IF (@CharName2 IS NULL)
	BEGIN
		SELECT @CharName1, NULL, NULL
		RETURN
	END

	DECLARE @CharName3 VARCHAR(20)
	SET @CharName3 = (SELECT TOP 1 CharacterName 
						FROM td_character WITH(NOLOCK)
						WHERE AccountName = @i_AccountName AND 0 = (Race & 0x4000) AND CharacterName <> @CharName1 AND CharacterName <> @CharName2
						ORDER BY CharacterName)
	SELECT @CharName1, @CharName2, @CharName3	
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_RYB_bean_counts
-- Desc: // 2007-09-18 by cmkwon, 캐릭터명으로 모든 콩아인템 개수를 다 가져온다
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--			빨간콩(Red Bean) ItemNum	: 7017000
--			노란콩(Yellow Bean) ItemNum	: 7016990
--			파란콩(Blue Bean) ItemNum	: 7016980
--			#define ITEM_IN_CHARACTER				0	// 캐릭터인벤, 선택한 캐릭터 게임 시작시 한번만 호출됨
--
-- parameter:
--		[1] INPUT @i_CharacterName	: 검색하려는 아이템의 소유 캐릭터명
--		[2] INPUT @i_ItemNum		: 검색하려는 아이템의 ItemNum(7016980, 7016990, 7017000)
--
-- 결과 record set: [결과 에러 코드(Error Code)] [Red Bean Counts] [Yellow Bean Counts] [Blue Bean Counts]
--		[1]	[결과 에러 코드(Error Code)]	: INT, 결과 에러 코드
--													0	==> 에러 없음
--													100	==> 해당 캐릭터가 없음
--													101	==> 해당 캐릭터의 계정이 없음
--		[2] [Red Bean Counts]				: INT, 해당 아이템의 현재 개수
--		[3] [Yellow Bean Counts]			: INT, 해당 아이템의 현재 개수
--		[4] [Blue Bean Counts]				: INT, 해당 아이템의 현재 개수
--	
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_RYB_bean_counts
	@i_CharacterName				VARCHAR(20)		-- 캐릭터명
AS
	-- CharacterUID를 검색한다. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 100, 0, 0, 0		-- 100	==> 해당 캐릭터가 없음
		RETURN
	END

	-- AccountUID를 검색한다. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101, 0, 0, 0		-- 101	==> 해당 캐릭터의 계정이 없음
		RETURN
	END

	DECLARE @ItemNum INT
	
	-------------------------------------------------------------------------------
	-- Red Bean Counts를 검색
	DECLARE @RBeanItemUID BIGINT
	DECLARE @RBeanCnts INT
	SET	@ItemNum		= 7017000	-- 빨간콩(Red Bean) ItemNum	: 7017000 으로 초기화

	exec dbo.atum_tm_yetime_get_item @RBeanItemUID OUTPUT, @RBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@RBeanCnts IS NULL) OR (0 > @RBeanCnts)
	BEGIN
		SET @RBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- Yellow Bean Counts를 검색
	DECLARE @YBeanItemUID BIGINT
	DECLARE @YBeanCnts INT
	SET	@ItemNum		= 7016990	-- 노란콩(Yellow Bean) ItemNum	: 7016990 으로 초기화
	
	exec dbo.atum_tm_yetime_get_item @YBeanItemUID OUTPUT, @YBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@YBeanCnts IS NULL) OR (0 > @YBeanCnts)
	BEGIN
		SET @YBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- Blue Bean Counts를 검색
	DECLARE @BBeanItemUID BIGINT
	DECLARE @BBeanCnts INT
	SET	@ItemNum		= 7016980	-- 파란콩(Blue Bean) ItemNum	: 7016980 으로 초기화

	exec dbo.atum_tm_yetime_get_item @BBeanItemUID OUTPUT, @BBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@BBeanCnts IS NULL) OR (0 > @BBeanCnts)
	BEGIN
		SET @BBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- 결과를 리턴
	SELECT 0, @RBeanCnts, @YBeanCnts, @BBeanCnts		-- 0	==> 에러 없음
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_use_item
-- Desc: // 2007-09-18 by cmkwon, 캐릭터명과 콩아이템의 ItemNum으로 해당 아이템을 해당 개수 만큼 사용한다.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--			빨간콩(Red Bean) ItemNum	: 7017000
--			노란콩(Yellow Bean) ItemNum	: 7016990
--			파란콩(Blue Bean) ItemNum	: 7016980
--			#define ITEM_IN_CHARACTER				0	// 캐릭터인벤, 선택한 캐릭터 게임 시작시 한번만 호출됨
--
-- parameter:
--		[1] INPUT @i_CharacterName	: 사용하려는 아이템의 소유 캐릭터명
--		[2] INPUT @i_UseRBCnt		: 사용하려는 Red Bean Counts
--		[3] INPUT @i_UseYBCnt		: 사용하려는 Yellow Bean Counts
--		[4] INPUT @i_UseBBCnt		: 사용하려는 Blue Bean Counts
--
-- 결과 record set: [결과 에러 코드(Error Code)]
--		[1]	[결과 에러 코드(Error Code)]	: INT, 결과 에러 코드
--													0	==> 에러 없음
--													100	==> 해당 캐릭터가 없음
--													101	==> 해당 캐릭터의 계정이 없음
--													102	==> 해당 계정이 특정 게임 서버에 접속 중인 상태입니다.
--													103	==> 사용인자 개수에 오류가 있습니다. 0보다 작은것이 있거나 혹은 모두 0이다
--													110	==> Red Bean 개수가 사용하려는 개수보다 작다
--													111	==> Yellow Bean 개수가 사용하려는 개수보다 작다
--													112	==> Blue Bean 개수가 사용하려는 개수보다 작다
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_use_RYB_bean
	@i_CharacterName				VARCHAR(20),				-- 캐릭터명
	@i_UseRBCnt						INT,
	@i_UseYBCnt						INT,
	@i_UseBBCnt						INT
AS
	IF (0 > @i_UseRBCnt) OR (0 > @i_UseYBCnt) OR (0 > @i_UseBBCnt)
	BEGIN
		SELECT 103		-- 103	==> 사용인자 개수에 오류가 있습니다. 0보다 작은것이 있거나 혹은 모두 0이다
		RETURN
	END
	IF (0 = @i_UseRBCnt) AND (0 = @i_UseYBCnt) AND (0 = @i_UseBBCnt)
	BEGIN
		SELECT 103		-- 103	==> 사용인자 개수에 오류가 있습니다. 0보다 작은것이 있거나 혹은 모두 0이다
		RETURN
	END

	-- CharacterUID를 검색한다. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 100		-- 100	==> 해당 캐릭터가 없음
		RETURN
	END

	-- AccountUID를 검색한다. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> 해당 캐릭터의 계정이 없음
		RETURN
	END

	-- 게임에 접속중인지 체크한다.
	DECLARE	@ConnectingServerGroupID INT
	SET @ConnectingServerGroupID = (SELECT ConnectingServerGroupID FROM td_account WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID)
	IF (@ConnectingServerGroupID IS NOT NULL) AND (@ConnectingServerGroupID <> 0)
	BEGIN
		SELECT 102		-- 102	==> 해당 계정이 특정 게임 서버에 접속 중인 상태입니다.
		RETURN
	END

	DECLARE @ItemNum INT

	-------------------------------------------------------------------------------
	-- Red Bean Counts를 검색 및 체크
	DECLARE @RBeanItemUID BIGINT
	DECLARE @RBeanCnts INT
	IF (0 < @i_UseRBCnt)
	BEGIN
		SET	@ItemNum		= 7017000	-- 빨간콩(Red Bean) ItemNum	: 7017000 으로 초기화
		exec dbo.atum_tm_yetime_get_item @RBeanItemUID OUTPUT, @RBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@RBeanCnts < @i_UseRBCnt)
		BEGIN
			SELECT 110		-- 110	==> Red Bean 개수가 사용하려는 개수보다 작다
			RETURN			
		END
	END

	-------------------------------------------------------------------------------
	-- Yellow Bean Counts를 검색 및 체크
	DECLARE @YBeanItemUID BIGINT
	DECLARE @YBeanCnts INT
	IF (0 < @i_UseYBCnt)
	BEGIN
		SET	@ItemNum		= 7016990	-- 노란콩(Yellow Bean) ItemNum	: 7016990 으로 초기화
		exec dbo.atum_tm_yetime_get_item @YBeanItemUID OUTPUT, @YBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@YBeanCnts < @i_UseYBCnt)
		BEGIN
			SELECT 111		-- 111	==> Yellow Bean 개수가 사용하려는 개수보다 작다
			RETURN			
		END
	END


	-------------------------------------------------------------------------------
	-- Blue Bean Counts를 검색
	DECLARE @BBeanItemUID BIGINT
	DECLARE @BBeanCnts INT
	IF (0 < @i_UseBBCnt)
	BEGIN
		SET	@ItemNum		= 7016980	-- 파란콩(Blue Bean) ItemNum	: 7016980 으로 초기화
		exec dbo.atum_tm_yetime_get_item @BBeanItemUID OUTPUT, @BBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@BBeanCnts < @i_UseBBCnt)
		BEGIN
			SELECT 112		-- 112	==> Blue Bean 개수가 사용하려는 개수보다 작다
			RETURN			
		END
	END

	-- 결과 이상없음을 전송한다.
	SELECT 0		-- 0	==> 에러 없음

	IF (0 < @i_UseRBCnt)
	BEGIN
		SET	@ItemNum		= 7017000	-- 빨간콩(Red Bean) ItemNum	: 7017000 으로 초기화
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @RBeanItemUID, @RBeanCnts, @i_UseRBCnt
	END
	
	IF (0 < @i_UseYBCnt)
	BEGIN
		SET	@ItemNum		= 7016990	-- 노란콩(Yellow Bean) ItemNum	: 7016990 으로 초기화
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @YBeanItemUID, @YBeanCnts, @i_UseYBCnt
	END

	IF (0 < @i_UseBBCnt)
	BEGIN
		SET	@ItemNum		= 7016980	-- 파란콩(Blue Bean) ItemNum	: 7016980 으로 초기화
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @BBeanItemUID, @BBeanCnts, @i_UseBBCnt
	END
GO
