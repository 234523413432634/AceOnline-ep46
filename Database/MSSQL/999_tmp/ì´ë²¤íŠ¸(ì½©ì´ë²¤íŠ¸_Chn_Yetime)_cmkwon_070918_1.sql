
-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_characters
-- Desc: // 2007-09-18 by cmkwon, 계정명으로 삭제되지 않은 캐릭터를 가져온다
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_characters
	@i_AccountName				VARCHAR(20)				-- 계정명
AS
	SELECT CharacterName, UniqueNumber
	FROM td_character WITH(NOLOCK)
	WHERE AccountName = @i_AccountName AND 0 = (Race & 0x4000)
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_item_counts
-- Desc: // 2007-09-18 by cmkwon, 캐릭터명과 콩아이템의 ItemNum으로 해당 아이템의 현재 개수를 리턴한다.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--			파란콩 ItemNum: 7016980
--			노란콩 ItemNum: 7016990
--			빨간콩 ItemNum: 7017000
--			#define ITEM_IN_CHARACTER				0	// 캐릭터인벤, 선택한 캐릭터 게임 시작시 한번만 호출됨
--
-- parameter:
--		[1] INPUT @i_CharacterName	: 검색하려는 아이템의 소유 캐릭터명
--		[2] INPUT @i_ItemNum		: 검색하려는 아이템의 ItemNum(7016980, 7016990, 7017000)
--
-- 결과 record set: [결과 에러 코드(Error Code)] [검색된 아이템의 개수]
--		[1]	[결과 에러 코드(Error Code)]
--									0	==> 에러 없음
--									100	==> ItemNum이 유효하지 않습니다.
--									101	==> 해당 캐릭터 혹은 계정이 없음
--									102	==> 해당 계정이 특정 게임 서버에 접속 중인 상태입니다.
--									103	==> 해당 캐릭터에 해당 아이템이 없습니다.
--									104	==> 해당 캐릭터에 해당 아이템 개수보다 많이 사용하려고 합니다.
--		[2] [검색된 아이템의 개수] : 해당 아이템의 현재 개수
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_item_counts
	@i_CharacterName				VARCHAR(20),		-- 캐릭터명
	@i_ItemNum						INT
AS
	IF (@i_ItemNum <> 7016980) AND (@i_ItemNum <> 7016990) AND (@i_ItemNum <> 7017000)
	BEGIN
		SELECT 100, 0		-- 100	==> ItemNum이 유효하지 않습니다.
		RETURN
	END

	-- CharacterUID를 검색한다. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 101, 0		-- 101	==> 해당 캐릭터 혹은 계정이 없음
		RETURN
	END

	-- AccountUID를 검색한다. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101, 0		-- 101	==> 해당 캐릭터 혹은 계정이 없음
		RETURN
	END

	-- 해당 아이템의 ItemUID를 검색한다.
	DECLARE @ItemUID BIGINT
	SET @ItemUID = (SELECT s.UniqueNumber
					FROM td_character c WITH(NOLOCK), td_store s WITH(NOLOCK)
					WHERE c.CharacterName = @i_CharacterName AND 0 = (c.Race & 0x4000) AND c.UniqueNumber = s.Possess AND s.ItemStorage = 0 AND s.ItemNum = @i_ItemNum)
	IF (@ItemUID IS NULL)
	BEGIN
		SELECT 103, 0		-- 103	==> 해당 캐릭터에 해당 아이템이 없습니다.
		RETURN
	END

	-- 해당 아이템의 현재 개수를 검색한다.
	DECLARE @CurCnts INT
	SET @CurCnts = (SELECT CurrentCount	FROM td_store WITH(NOLOCK) WHERE UniqueNumber = @ItemUID)
	IF (@CurCnts IS NULL)
	BEGIN
		SELECT 103, 0		-- 103	==> 해당 캐릭터에 해당 아이템이 없습니다.
		RETURN
	END

	SELECT 0, @CurCnts		-- 0	==> 에러 없음
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_use_item
-- Desc: // 2007-09-18 by cmkwon, 캐릭터명과 콩아이템의 ItemNum으로 해당 아이템을 해당 개수 만큼 사용한다.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--			파란콩 ItemNum: 7016980
--			노란콩 ItemNum: 7016990
--			빨간콩 ItemNum: 7017000
--			#define ITEM_IN_CHARACTER				0	// 캐릭터인벤, 선택한 캐릭터 게임 시작시 한번만 호출됨
--
-- parameter:
--		[1] INPUT @i_CharacterName	: 사용하려는 아이템의 소유 캐릭터명
--		[2] INPUT @i_ItemNum		: 사용하려는 아이템의 ItemNum(7016980, 7016990, 7017000)
--		[3] INPUT @i_UseCounts		: 사용하려는 개수
--
-- 결과 record set: [결과 에러 코드(Error Code)]
--		[1]	[결과 에러 코드(Error Code)]
--									0	==> 에러 없음
--									100	==> ItemNum이 유효하지 않습니다.
--									101	==> 해당 캐릭터 혹은 계정이 없음
--									102	==> 해당 계정이 특정 게임 서버에 접속 중인 상태입니다.
--									103	==> 해당 캐릭터에 해당 아이템이 없습니다.
--									104	==> 해당 캐릭터에 해당 아이템 개수보다 많이 사용하려고 합니다.
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_use_item
	@i_CharacterName				VARCHAR(20),				-- 캐릭터명
	@i_ItemNum						INT,
	@i_UseCounts					INT
AS
	IF (@i_ItemNum <> 7016980) AND (@i_ItemNum <> 7016990) AND (@i_ItemNum <> 7017000)
	BEGIN
		SELECT 100		-- 100	==> ItemNum이 유효하지 않습니다.
		RETURN
	END

	-- CharacterUID를 검색한다. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> 해당 캐릭터 혹은 계정이 없음
		RETURN
	END

	-- AccountUID를 검색한다. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> 해당 캐릭터 혹은 계정이 없음
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

	-- 해당 아이템의 ItemUID를 검색한다.
	DECLARE @ItemUID BIGINT
	SET @ItemUID = (SELECT s.UniqueNumber
					FROM td_character c WITH(NOLOCK), td_store s WITH(NOLOCK)
					WHERE c.CharacterName = @i_CharacterName AND 0 = (c.Race & 0x4000) AND c.UniqueNumber = s.Possess AND s.ItemStorage = 0 AND s.ItemNum = @i_ItemNum)
	IF (@ItemUID IS NULL)
	BEGIN
		SELECT 103		-- 103	==> 해당 캐릭터에 해당 아이템이 없습니다.
		RETURN
	END

	-- 해당 아이템의 현재 개수를 검색한다.
	DECLARE @CurCnts INT
	SET @CurCnts = (SELECT CurrentCount	FROM td_store WITH(NOLOCK) WHERE UniqueNumber = @ItemUID)
	IF (@CurCnts IS NULL)
	BEGIN
		SELECT 103		-- 103	==> 해당 캐릭터에 해당 아이템이 없습니다.
		RETURN
	END
	ELSE IF (@CurCnts < @i_UseCounts)
	BEGIN
		SELECT 104		-- 104	==> 해당 캐릭터에 해당 아이템 개수보다 많이 사용하려고 합니다.
		RETURN
	END
	

	-- 결과 이상없음을 전송한다.
	SELECT 0		-- 0	==> 에러 없음


	DECLARE @RemainCnts INT
	SET @RemainCnts = @CurCnts - @i_UseCounts
	IF (0 >= @RemainCnts)
	BEGIN

		-- 개수가 0으로 되었으므로 아이템을 삭제한다.
		DELETE td_store
		WHERE UniqueNumber = @ItemUID
	END
	ELSE
	BEGIN

		-- 사용한 개수만큼 제하고 현재 개수를 업데이트 한다.
		UPDATE td_store
		SET CurrentCount = @RemainCnts
		WHERE UniqueNumber = @ItemUID
	END

	-------------------------------------------------------------------------------
	-- 사용 정보를 로그에 저장한다.
	-- #define T1_FL_LOG_ITEM_USE_ITEM					0x27	// 39 - 아이템 사용
	INSERT INTO atum_log_item_charac_use
	VALUES (39, GetDate(), @CharUID, 0,
			@ItemUID, @i_ItemNum, @RemainCnts, @i_UseCounts)
GO
