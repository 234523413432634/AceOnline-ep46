

-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_item
-- Desc: // 2007-09-18 by cmkwon, ������ �˻�
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
-- Desc: // 2007-09-18 by cmkwon, ������ ������ ������Ʈ �Ѵ�.
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

		-- ������ 0���� �Ǿ����Ƿ� �������� �����Ѵ�.
		DELETE td_store
		WHERE UniqueNumber = @i_ItemUID
	END
	ELSE
	BEGIN

		-- ����� ������ŭ ���ϰ� ���� ������ ������Ʈ �Ѵ�.
		UPDATE td_store
		SET CurrentCount = @RemainCnts
		WHERE UniqueNumber = @i_ItemUID
	END

	-------------------------------------------------------------------------------
	-- ��� ������ �α׿� �����Ѵ�.
	-- #define T1_FL_LOG_ITEM_USE_ITEM					0x27	// 39 - ������ ���
	INSERT INTO atum_log_item_charac_use
	VALUES (39, GetDate(), @i_CharUID, 0,
			@i_ItemUID, @i_ItemNum, @RemainCnts, @i_UseCnts)

GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_get_characters
-- Desc: // 2007-09-18 by cmkwon, ���������� �������� ���� ĳ���͸� �����´�
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--
-- parameter:
--		[1] INPUT @i_AccountName	: �˻��Ϸ��� ������
--
-- ��� record set: [ĳ���͸� 1] [ĳ���͸� 2] [ĳ���͸� 3]
--		[1]	[ĳ���͸� 1]	: VARCHAR(20), ĳ���͸� 1
--		[1]	[ĳ���͸� 2]	: VARCHAR(20), ĳ���͸� 2
--		[1]	[ĳ���͸� 3]	: VARCHAR(20), ĳ���͸� 3
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_characters
	@i_AccountName				VARCHAR(20)				-- ������
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
-- Desc: // 2007-09-18 by cmkwon, ĳ���͸����� ��� ������� ������ �� �����´�
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--			������(Red Bean) ItemNum	: 7017000
--			�����(Yellow Bean) ItemNum	: 7016990
--			�Ķ���(Blue Bean) ItemNum	: 7016980
--			#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--
-- parameter:
--		[1] INPUT @i_CharacterName	: �˻��Ϸ��� �������� ���� ĳ���͸�
--		[2] INPUT @i_ItemNum		: �˻��Ϸ��� �������� ItemNum(7016980, 7016990, 7017000)
--
-- ��� record set: [��� ���� �ڵ�(Error Code)] [Red Bean Counts] [Yellow Bean Counts] [Blue Bean Counts]
--		[1]	[��� ���� �ڵ�(Error Code)]	: INT, ��� ���� �ڵ�
--													0	==> ���� ����
--													100	==> �ش� ĳ���Ͱ� ����
--													101	==> �ش� ĳ������ ������ ����
--		[2] [Red Bean Counts]				: INT, �ش� �������� ���� ����
--		[3] [Yellow Bean Counts]			: INT, �ش� �������� ���� ����
--		[4] [Blue Bean Counts]				: INT, �ش� �������� ���� ����
--	
--====
CREATE PROCEDURE dbo.atum_tm_yetime_get_RYB_bean_counts
	@i_CharacterName				VARCHAR(20)		-- ĳ���͸�
AS
	-- CharacterUID�� �˻��Ѵ�. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 100, 0, 0, 0		-- 100	==> �ش� ĳ���Ͱ� ����
		RETURN
	END

	-- AccountUID�� �˻��Ѵ�. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101, 0, 0, 0		-- 101	==> �ش� ĳ������ ������ ����
		RETURN
	END

	DECLARE @ItemNum INT
	
	-------------------------------------------------------------------------------
	-- Red Bean Counts�� �˻�
	DECLARE @RBeanItemUID BIGINT
	DECLARE @RBeanCnts INT
	SET	@ItemNum		= 7017000	-- ������(Red Bean) ItemNum	: 7017000 ���� �ʱ�ȭ

	exec dbo.atum_tm_yetime_get_item @RBeanItemUID OUTPUT, @RBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@RBeanCnts IS NULL) OR (0 > @RBeanCnts)
	BEGIN
		SET @RBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- Yellow Bean Counts�� �˻�
	DECLARE @YBeanItemUID BIGINT
	DECLARE @YBeanCnts INT
	SET	@ItemNum		= 7016990	-- �����(Yellow Bean) ItemNum	: 7016990 ���� �ʱ�ȭ
	
	exec dbo.atum_tm_yetime_get_item @YBeanItemUID OUTPUT, @YBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@YBeanCnts IS NULL) OR (0 > @YBeanCnts)
	BEGIN
		SET @YBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- Blue Bean Counts�� �˻�
	DECLARE @BBeanItemUID BIGINT
	DECLARE @BBeanCnts INT
	SET	@ItemNum		= 7016980	-- �Ķ���(Blue Bean) ItemNum	: 7016980 ���� �ʱ�ȭ

	exec dbo.atum_tm_yetime_get_item @BBeanItemUID OUTPUT, @BBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum
	IF (@BBeanCnts IS NULL) OR (0 > @BBeanCnts)
	BEGIN
		SET @BBeanCnts	= 0
	END

	-------------------------------------------------------------------------------
	-- ����� ����
	SELECT 0, @RBeanCnts, @YBeanCnts, @BBeanCnts		-- 0	==> ���� ����
GO


-------------------------------------------------------------------------------
--!!!!
-- Name: dbo.atum_tm_yetime_use_item
-- Desc: // 2007-09-18 by cmkwon, ĳ���͸�� ��������� ItemNum���� �ش� �������� �ش� ���� ��ŭ ����Ѵ�.
--			#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--			������(Red Bean) ItemNum	: 7017000
--			�����(Yellow Bean) ItemNum	: 7016990
--			�Ķ���(Blue Bean) ItemNum	: 7016980
--			#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--
-- parameter:
--		[1] INPUT @i_CharacterName	: ����Ϸ��� �������� ���� ĳ���͸�
--		[2] INPUT @i_UseRBCnt		: ����Ϸ��� Red Bean Counts
--		[3] INPUT @i_UseYBCnt		: ����Ϸ��� Yellow Bean Counts
--		[4] INPUT @i_UseBBCnt		: ����Ϸ��� Blue Bean Counts
--
-- ��� record set: [��� ���� �ڵ�(Error Code)]
--		[1]	[��� ���� �ڵ�(Error Code)]	: INT, ��� ���� �ڵ�
--													0	==> ���� ����
--													100	==> �ش� ĳ���Ͱ� ����
--													101	==> �ش� ĳ������ ������ ����
--													102	==> �ش� ������ Ư�� ���� ������ ���� ���� �����Դϴ�.
--													103	==> ������� ������ ������ �ֽ��ϴ�. 0���� �������� �ְų� Ȥ�� ��� 0�̴�
--													110	==> Red Bean ������ ����Ϸ��� �������� �۴�
--													111	==> Yellow Bean ������ ����Ϸ��� �������� �۴�
--													112	==> Blue Bean ������ ����Ϸ��� �������� �۴�
--
--====
CREATE PROCEDURE dbo.atum_tm_yetime_use_RYB_bean
	@i_CharacterName				VARCHAR(20),				-- ĳ���͸�
	@i_UseRBCnt						INT,
	@i_UseYBCnt						INT,
	@i_UseBBCnt						INT
AS
	IF (0 > @i_UseRBCnt) OR (0 > @i_UseYBCnt) OR (0 > @i_UseBBCnt)
	BEGIN
		SELECT 103		-- 103	==> ������� ������ ������ �ֽ��ϴ�. 0���� �������� �ְų� Ȥ�� ��� 0�̴�
		RETURN
	END
	IF (0 = @i_UseRBCnt) AND (0 = @i_UseYBCnt) AND (0 = @i_UseBBCnt)
	BEGIN
		SELECT 103		-- 103	==> ������� ������ ������ �ֽ��ϴ�. 0���� �������� �ְų� Ȥ�� ��� 0�̴�
		RETURN
	END

	-- CharacterUID�� �˻��Ѵ�. 
	DECLARE	@CharUID INT
	SET @CharUID = (SELECT UniqueNumber FROM td_character WITH(NOLOCK) WHERE CharacterName = @i_CharacterName AND 0 = (Race & 0x4000))
	IF (@CharUID IS NULL)
	BEGIN
		SELECT 100		-- 100	==> �ش� ĳ���Ͱ� ����
		RETURN
	END

	-- AccountUID�� �˻��Ѵ�. 
	DECLARE	@AccUID INT
	SET @AccUID = (SELECT a.AccountUniqueNumber FROM td_account a WITH(NOLOCK), td_character c WITH(NOLOCK) WHERE c.UniqueNumber = @CharUID AND c.AccountName = a.AccountName)
	IF (@AccUID IS NULL)
	BEGIN
		SELECT 101		-- 101	==> �ش� ĳ������ ������ ����
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

	DECLARE @ItemNum INT

	-------------------------------------------------------------------------------
	-- Red Bean Counts�� �˻� �� üũ
	DECLARE @RBeanItemUID BIGINT
	DECLARE @RBeanCnts INT
	IF (0 < @i_UseRBCnt)
	BEGIN
		SET	@ItemNum		= 7017000	-- ������(Red Bean) ItemNum	: 7017000 ���� �ʱ�ȭ
		exec dbo.atum_tm_yetime_get_item @RBeanItemUID OUTPUT, @RBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@RBeanCnts < @i_UseRBCnt)
		BEGIN
			SELECT 110		-- 110	==> Red Bean ������ ����Ϸ��� �������� �۴�
			RETURN			
		END
	END

	-------------------------------------------------------------------------------
	-- Yellow Bean Counts�� �˻� �� üũ
	DECLARE @YBeanItemUID BIGINT
	DECLARE @YBeanCnts INT
	IF (0 < @i_UseYBCnt)
	BEGIN
		SET	@ItemNum		= 7016990	-- �����(Yellow Bean) ItemNum	: 7016990 ���� �ʱ�ȭ
		exec dbo.atum_tm_yetime_get_item @YBeanItemUID OUTPUT, @YBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@YBeanCnts < @i_UseYBCnt)
		BEGIN
			SELECT 111		-- 111	==> Yellow Bean ������ ����Ϸ��� �������� �۴�
			RETURN			
		END
	END


	-------------------------------------------------------------------------------
	-- Blue Bean Counts�� �˻�
	DECLARE @BBeanItemUID BIGINT
	DECLARE @BBeanCnts INT
	IF (0 < @i_UseBBCnt)
	BEGIN
		SET	@ItemNum		= 7016980	-- �Ķ���(Blue Bean) ItemNum	: 7016980 ���� �ʱ�ȭ
		exec dbo.atum_tm_yetime_get_item @BBeanItemUID OUTPUT, @BBeanCnts OUTPUT, @AccUID, @CharUID, @ItemNum

		IF (@BBeanCnts < @i_UseBBCnt)
		BEGIN
			SELECT 112		-- 112	==> Blue Bean ������ ����Ϸ��� �������� �۴�
			RETURN			
		END
	END

	-- ��� �̻������ �����Ѵ�.
	SELECT 0		-- 0	==> ���� ����

	IF (0 < @i_UseRBCnt)
	BEGIN
		SET	@ItemNum		= 7017000	-- ������(Red Bean) ItemNum	: 7017000 ���� �ʱ�ȭ
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @RBeanItemUID, @RBeanCnts, @i_UseRBCnt
	END
	
	IF (0 < @i_UseYBCnt)
	BEGIN
		SET	@ItemNum		= 7016990	-- �����(Yellow Bean) ItemNum	: 7016990 ���� �ʱ�ȭ
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @YBeanItemUID, @YBeanCnts, @i_UseYBCnt
	END

	IF (0 < @i_UseBBCnt)
	BEGIN
		SET	@ItemNum		= 7016980	-- �Ķ���(Blue Bean) ItemNum	: 7016980 ���� �ʱ�ȭ
		exec atum_tm_yetime_use_item @CharUID, @ItemNum, @BBeanItemUID, @BBeanCnts, @i_UseBBCnt
	END
GO
