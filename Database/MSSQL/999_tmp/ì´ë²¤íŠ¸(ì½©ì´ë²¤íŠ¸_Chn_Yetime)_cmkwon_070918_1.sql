
-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_characters
-- Desc: // 2007-09-18 by cmkwon, ���������� �������� ���� ĳ���͸� �����´�
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_characters
	@i_AccountName				VARCHAR(20)				-- ������
AS
	SELECT CharacterName, UniqueNumber
	FROM td_character WITH(NOLOCK)
	WHERE AccountName = @i_AccountName AND 0 = (Race & 0x4000)
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_item_counts
-- Desc: // 2007-09-18 by cmkwon, ĳ���͸�� ��������� ItemNum���� �ش� �������� ���� ������ �����Ѵ�.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--			�Ķ��� ItemNum: 7016980
--			����� ItemNum: 7016990
--			������ ItemNum: 7017000
--			#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--
-- parameter:
--		[1] INPUT @i_CharacterName	: �˻��Ϸ��� �������� ���� ĳ���͸�
--		[2] INPUT @i_ItemNum		: �˻��Ϸ��� �������� ItemNum(7016980, 7016990, 7017000)
--
-- ��� record set: [��� ���� �ڵ�(Error Code)] [�˻��� �������� ����]
--		[1]	[��� ���� �ڵ�(Error Code)]
--									0	==> ���� ����
--									100	==> ItemNum�� ��ȿ���� �ʽ��ϴ�.
--									101	==> �ش� ĳ���� Ȥ�� ������ ����
--									102	==> �ش� ������ Ư�� ���� ������ ���� ���� �����Դϴ�.
--									103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
--									104	==> �ش� ĳ���Ϳ� �ش� ������ �������� ���� ����Ϸ��� �մϴ�.
--		[2] [�˻��� �������� ����] : �ش� �������� ���� ����
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_item_counts
	@i_CharacterName				VARCHAR(20),		-- ĳ���͸�
	@i_ItemNum						INT
AS
	IF (@i_ItemNum <> 7016980) AND (@i_ItemNum <> 7016990) AND (@i_ItemNum <> 7017000)
	BEGIN
		SELECT 100, 0		-- 100	==> ItemNum�� ��ȿ���� �ʽ��ϴ�.
		RETURN
	END

	-- CharacterUID�� �˻��Ѵ�. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 101, 0		-- 101	==> �ش� ĳ���� Ȥ�� ������ ����
		RETURN
	END

	-- AccountUID�� �˻��Ѵ�. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101, 0		-- 101	==> �ش� ĳ���� Ȥ�� ������ ����
		RETURN
	END

	-- �ش� �������� ItemUID�� �˻��Ѵ�.
	DECLARE @ItemUID BIGINT
	SET @ItemUID = (SELECT s.UniqueNumber
					FROM td_character c WITH(NOLOCK), td_store s WITH(NOLOCK)
					WHERE c.CharacterName = @i_CharacterName AND 0 = (c.Race & 0x4000) AND c.UniqueNumber = s.Possess AND s.ItemStorage = 0 AND s.ItemNum = @i_ItemNum)
	IF (@ItemUID IS NULL)
	BEGIN
		SELECT 103, 0		-- 103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
		RETURN
	END

	-- �ش� �������� ���� ������ �˻��Ѵ�.
	DECLARE @CurCnts INT
	SET @CurCnts = (SELECT CurrentCount	FROM td_store WITH(NOLOCK) WHERE UniqueNumber = @ItemUID)
	IF (@CurCnts IS NULL)
	BEGIN
		SELECT 103, 0		-- 103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
		RETURN
	END

	SELECT 0, @CurCnts		-- 0	==> ���� ����
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_use_item
-- Desc: // 2007-09-18 by cmkwon, ĳ���͸�� ��������� ItemNum���� �ش� �������� �ش� ���� ��ŭ ����Ѵ�.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--			�Ķ��� ItemNum: 7016980
--			����� ItemNum: 7016990
--			������ ItemNum: 7017000
--			#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--
-- parameter:
--		[1] INPUT @i_CharacterName	: ����Ϸ��� �������� ���� ĳ���͸�
--		[2] INPUT @i_ItemNum		: ����Ϸ��� �������� ItemNum(7016980, 7016990, 7017000)
--		[3] INPUT @i_UseCounts		: ����Ϸ��� ����
--
-- ��� record set: [��� ���� �ڵ�(Error Code)]
--		[1]	[��� ���� �ڵ�(Error Code)]
--									0	==> ���� ����
--									100	==> ItemNum�� ��ȿ���� �ʽ��ϴ�.
--									101	==> �ش� ĳ���� Ȥ�� ������ ����
--									102	==> �ش� ������ Ư�� ���� ������ ���� ���� �����Դϴ�.
--									103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
--									104	==> �ش� ĳ���Ϳ� �ش� ������ �������� ���� ����Ϸ��� �մϴ�.
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_use_item
	@i_CharacterName				VARCHAR(20),				-- ĳ���͸�
	@i_ItemNum						INT,
	@i_UseCounts					INT
AS
	IF (@i_ItemNum <> 7016980) AND (@i_ItemNum <> 7016990) AND (@i_ItemNum <> 7017000)
	BEGIN
		SELECT 100		-- 100	==> ItemNum�� ��ȿ���� �ʽ��ϴ�.
		RETURN
	END

	-- CharacterUID�� �˻��Ѵ�. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> �ش� ĳ���� Ȥ�� ������ ����
		RETURN
	END

	-- AccountUID�� �˻��Ѵ�. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> �ش� ĳ���� Ȥ�� ������ ����
		RETURN
	END

	-- ���ӿ� ���������� üũ�Ѵ�.
	DECLARE	@ConnectingServerGroupID INT
	SET @ConnectingServerGroupID = (SELECT ConnectingServerGroupID FROM td_account WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID)
	IF (@ConnectingServerGroupID IS NOT NULL) AND (@ConnectingServerGroupID <> 0)
	BEGIN
		SELECT 102		-- 102	==> �ش� ������ Ư�� ���� ������ ���� ���� �����Դϴ�.
		RETURN
	END

	-- �ش� �������� ItemUID�� �˻��Ѵ�.
	DECLARE @ItemUID BIGINT
	SET @ItemUID = (SELECT s.UniqueNumber
					FROM td_character c WITH(NOLOCK), td_store s WITH(NOLOCK)
					WHERE c.CharacterName = @i_CharacterName AND 0 = (c.Race & 0x4000) AND c.UniqueNumber = s.Possess AND s.ItemStorage = 0 AND s.ItemNum = @i_ItemNum)
	IF (@ItemUID IS NULL)
	BEGIN
		SELECT 103		-- 103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
		RETURN
	END

	-- �ش� �������� ���� ������ �˻��Ѵ�.
	DECLARE @CurCnts INT
	SET @CurCnts = (SELECT CurrentCount	FROM td_store WITH(NOLOCK) WHERE UniqueNumber = @ItemUID)
	IF (@CurCnts IS NULL)
	BEGIN
		SELECT 103		-- 103	==> �ش� ĳ���Ϳ� �ش� �������� �����ϴ�.
		RETURN
	END
	ELSE IF (@CurCnts < @i_UseCounts)
	BEGIN
		SELECT 104		-- 104	==> �ش� ĳ���Ϳ� �ش� ������ �������� ���� ����Ϸ��� �մϴ�.
		RETURN
	END
	

	-- ��� �̻������ �����Ѵ�.
	SELECT 0		-- 0	==> ���� ����


	DECLARE @RemainCnts INT
	SET @RemainCnts = @CurCnts - @i_UseCounts
	IF (0 >= @RemainCnts)
	BEGIN

		-- ������ 0���� �Ǿ����Ƿ� �������� �����Ѵ�.
		DELETE td_store
		WHERE UniqueNumber = @ItemUID
	END
	ELSE
	BEGIN

		-- ����� ������ŭ ���ϰ� ���� ������ ������Ʈ �Ѵ�.
		UPDATE td_store
		SET CurrentCount = @RemainCnts
		WHERE UniqueNumber = @ItemUID
	END

	-------------------------------------------------------------------------------
	-- ��� ������ �α׿� �����Ѵ�.
	-- #define T1_FL_LOG_ITEM_USE_ITEM					0x27	// 39 - ������ ���
	INSERT INTO atum_log_item_charac_use
	VALUES (39, GetDate(), @CharUID, 0,
			@ItemUID, @i_ItemNum, @RemainCnts, @i_UseCounts)
GO
