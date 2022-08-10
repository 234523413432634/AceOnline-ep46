
-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - �������� �κ��� �߰� �� ��,  �� ������ �߰��Ǵ� ó���� ����
-- //����! - dbo.atum_Insert_td_pet�� �����ϱ� ������ �׻� �� ���ν��� ���� dbo.atum_Insert_td_pet�� �����Ǿ�� �Ѵ�.  
--
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_InsertStorePetItem]
	@accNum				INT,
	@possess			INT,
	@ItemStorage		TINYINT,
	@wear				TINYINT,
	@CurrentCount		INT,
	@ItemWindowIndex	INT,
	@ItemNum			INT,
	@NumOfEnchants		SMALLINT,
	@PrefixCodeNum		INT,
	@SufficCodeNum		INT,
	@CurrentEndurance	FLOAT,
	@ColorCode			INT,
	@UsingTimeStamp		INT,
	@i_LinkItem			INT				--�� �ε���
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @PetIndex int, @PetName	varchar(40), @BaseSocketCount tinyint, @store_Error INT, @pet_error INT 

	BEGIN TRAN

	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, GetDate(), 0, 0, 0);
	
	SET @store_Error = @@ERROR

	IF (@store_error <> 0)
	BEGIN
		ROLLBACK TRAN;
		SELECT 0;
		RETURN 0;
	END

	SELECT @PetIndex = PetIndex, @PetName = PetName, @BaseSocketCount = BaseSocketCount FROM atum2_db_account.dbo.ti_pet WHERE PetIndex = @i_linkItem
	EXEC dbo.atum_Insert_td_pet @@IDENTITY, @PetIndex, @PetName, 1, 0, 0, @BaseSocketCount, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	
	SET @pet_error = @@ERROR

	IF (@pet_error <> 0)
	BEGIN
		ROLLBACK TRAN;
		SELECT 0;
		RETURN 0;
	END

	COMMIT TRAN;

	SELECT SCOPE_IDENTITY();
	RETURN SCOPE_IDENTITY();
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_insertStoreItem_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--					  -- atum_insertStoreItem_FromWeb ������� �ش� ���ν����� ���� �ۼ�, �߰� �߰� ������ Ʋ���ϴ� �����ϼ���
--					  -- �ؿܿ��� atum_insertStoreItem_FromWeb ���ν����� ����ϴ� ��� ��� ������ ������ �ּ�ȭ �ϱ� ���� ���ο� ���ν����� �ۼ�
--					  -- �� ĳ�� ���� �������̽� XMLRPC ���� �ϵ��� �����ؾ� �ϸ�, ���� �� atum_insertStoreItem_FromWeb ���ν����� �����ؾ� ��
--
--					///////////////////////////////////
--					// WEAR
--					#define WEAR_NOT_ATTACHED				0	// ������
--					#define WEAR_ATTACHED					1	// ����
--							
--					///////////////////////////////////////////////////////////////////////////////
--					// 2005-12-07 by cmkwon
--					#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--					#define ITEM_IN_STORE					1	// â��
--					#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--							
--					@i_ItemWindowIndex ����, �Ʒ��� 99�� �����ϸ� �⺻������ ���� ����, �ٸ� ������ ������ų���� �ʿ�
--					#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
--
-- Parameter		:	@i_AccountUID			INT			==> �ش� ������ ������ȣ (AccountUID) , ���� ���� ���� ���� Ȯ�ο�
--					@i_CharUID			INT			==> �ش� ĳ������ ������ȣ(CharacterUID)
--					@i_ItemNum			INT			==> �߰� �� �������� ItemNum
--					@i_CurrentCount		INT			==> �߰� �� �������� ����, ī���ͺ� �������� �ƴϸ� �ִ� 20�� ������ �߰� ������
--					@i_ItemStorage		TINYINT		==> �߰� �� ��ġ�� 0�̸� ĳ������ �κ�, 1�̸� ĳ������ â����, ITEM_IN_XXX�� ����
--					@i_Wear				TINYINT		==> �߰��� ��ġ�� ĳ������ �κ��϶��� â�� ���θ� ��Ÿ����, WEAR_XXX�� ����
--					@i_ItemWindowIndex	INT			==> â�� �����϶����� ��ȿ�ϸ�, â�����°� �ƴϸ� 99�� �����ϸ� �ȴ�.
--					@i_IsBuyCashItem	TINYINT			==> ������ �߰��� ĳ�������� ���ſ� ���� �߰� ������ ����, �ش� ���� ���� �α� �߰� ��ġ�� �޶�����.
--
-- Result Set	:	[ErrorCode INT] [InsertedItemUID BIGINT]
--					[ErrorCode INT]	==>	0 �̸� ����, 0 �� �ƴϸ� ������ ������ ����
--										-13,		// ������ ��ġ�� ��ȿ���� ����
--										-10,		// ������ ���� ������ ��ȿ���� ����
--										-6,		// ������ ĳ���� ������ ���� ����
--										-1,		// ���� ���� ����
--										-20,		// ������� �ʴ� ������ (�߰� / ����)
--										-10,		// ������ ���� ������ ��ȿ���� ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_insertStoreItem_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT,
	@i_ItemStorage		TINYINT,
	@i_Wear				TINYINT,
	@i_ItemWindowIndex	INT,
	@i_IsBuyCashItem	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @i			INT;
	SET @i				= 0;

	-- ĳ�����κ�, ĳ���� â�� ������ �߰��� ����, ����â�� ������ �߰��� �������� �ʴ´�.
	IF (0 <> @i_ItemStorage) AND (1 <> @i_ItemStorage)
	BEGIN
		-- #define XMLRPC_ERROR_INVALID_ITEM_STORAGE				-13			// ������ ��ġ�� ��ȿ���� ����
		SELECT -13;
		RETURN;
	END
	IF (0 >= @i_CurrentCount)
	BEGIN
		-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// ������ ���� ������ ��ȿ���� ����
		SELECT -10;	
		RETURN;	
	END

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID		INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384 )
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6;
		RETURN;
	END

	IF (0 != @i_ItemStorage)
	BEGIN
		SET @i_Wear				= 0;	-- ������
		SET @i_ItemWindowIndex	= 99;	-- ������
	END

	-- #define ITEM_ATTR_CASH_ITEM_PREMIUM_CARD		0x00020000		// 131072, // 2008-08-26 by cmkwon, ItemAttribute �߰� - �����(�����̾�) ������,  
	DECLARE @ItemKd				TINYINT;
	DECLARE @ItemAttri			BIGINT;
	DECLARE @ItemCharging		SMALLINT;
	DECLARE @ItemEndur			FLOAT;
	DECLARE @InsertedItemUID	BIGINT;
	DECLARE @LinkItem			INT;

	DECLARE	@RtvValue			INT;

	SELECT @ItemKd= Kind, @ItemAttri= ItemAttribute, @ItemCharging= Charging, @ItemEndur= Endurance, @LinkItem = LinkItem FROM atum2_db_account.dbo.ti_Item WITH(NOLOCK) WHERE ItemNum = @i_ItemNum;
	IF (@ItemKd IS NULL) OR (0 <> @ItemAttri & 131072)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ACCEPTED_ITEMNUM				-20			// ������� �ʴ� ������ (�߰� / ����)
		SELECT -20;
		RETURN
	END

	IF (0 <> dbo.atum_IsCountableItem(@ItemKd)) 
	BEGIN
		INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @i_CurrentCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

		IF (0 <> @@error)
		BEGIN
			-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
			SELECT -1;
			RETURN
		END
		
		--SET @InsertedItemUID = SCOPE_IDENTITY();
		SET @i					= @i + @i_CurrentCount;
	END
	ELSE
	BEGIN
		IF (10 < @i_CurrentCount)		-- ��ī���ͺ� ������ ó��(�ִ� 10�� ������ �߰� ������)
		BEGIN
			-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// ������ ���� ������ ��ȿ���� ����
			SELECT -10;
			RETURN
		END

		DECLARE @CurCount	INT;
		SET @CurCount		= 1;
		IF (0 <> dbo.atum_IsChargableItem(@ItemKd))
		BEGIN
			IF (@ItemCharging IS NULL)
			BEGIN
				-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
				SELECT -1;
				RETURN
			END
				
			SET @CurCount = @ItemCharging;
		END

		WHILE @i < @i_CurrentCount
		BEGIN
			IF (@ItemKd <> 38)
			BEGIN
				-- �Ϲ� ������
				INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
					VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @CurCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

				IF (0 <> @@error)
				BEGIN
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
					SELECT @i;
					RETURN
				END
			END
			ELSE
			BEGIN
				-- ��Ʈ�� ������
				EXEC @RtvValue = dbo.atum_InsertStorePetItem
					@accNum = @AccUID,
					@possess = @i_CharUID,
					@ItemStorage = @i_ItemStorage,
					@wear = @i_Wear,
					@CurrentCount = @CurCount,
					@ItemWindowIndex = @i_ItemWindowIndex,
					@ItemNum = @i_ItemNum,
					@NumOfEnchants = 0,
					@PrefixCodeNum = 0,
					@SufficCodeNum = 0,
					@CurrentEndurance = @ItemEndur,
					@ColorCode = 0,
					@UsingTimeStamp = 0,
					@i_LinkItem = @LinkItem

				IF (0 = @RtvValue)
				BEGIN
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
					SELECT @i;
					RETURN					
				END
			END

			SET @i = @i + 1;
		END
	END

	SELECT @i;
	RETURN;
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfo_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetCharacterInfo_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_GiftCharUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @AccountName		VARCHAR(20);
	DECLARE @CharacterName		VARCHAR(20);
	DECLARE @Race				SMALLINT;

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @GiftAccUID		INT; SET @GiftAccUID = 0;

	SELECT @AccUID = AccountUniqueNumber, @AccountName = AccountName, @CharacterName = CharacterName, @Race = Race FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6, NULL, NULL, NULL, 0;
		RETURN;
	END

	IF(0 != @i_GiftCharUID)
	BEGIN
		SELECT @GiftAccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_GiftCharUID AND 0 = Race & 16384
		IF (@GiftAccUID IS NULL)
		BEGIN
			-- #define XMLRPC_ERROR_INVALID_GET_CHARACTERUID				-18			// ���� ���� ���� ������ ��ȿ���� ����
			SELECT -18, NULL, NULL, NULL, 0;
			RETURN;
		END
	END

	SELECT 1, @AccountName, @CharacterName, @Race, @GiftAccUID;
	RETURN;
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteItem_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_DeleteItem_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @ItemUID		INT; SET @ItemUID = 0;
	DECLARE @CurrentCount	INT; SET @CurrentCount = 0;

	SELECT @AccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6;
		RETURN;
	END

	SELECT TOP 1 @ItemUID = [UniqueNumber], @CurrentCount = [CurrentCount] FROM [dbo].[td_Store] WHERE [ItemStorage] = 0 and [Possess] = @i_CharUID and [AccountUniqueNumber] = @i_AccountUID and [ItemNum] = @i_ItemNum

	IF (@ItemUID IS NULL) OR (@CurrentCount IS NULL)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// ������ �� ����
		SELECT -22;
		RETURN;
	END

	IF @CurrentCount < @i_CurrentCount
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// ������ �� ����
		SELECT -22;
		RETURN;
	END

	IF @CurrentCount = @i_CurrentCount
	BEGIN
		DELETE FROM [dbo].[td_Store] WHERE [UniqueNumber] = @ItemUID;
	END
	ELSE
	BEGIN
		UPDATE [dbo].[td_Store] SET [CurrentCount] = [CurrentCount] - @i_CurrentCount WHERE [UniqueNumber] = @ItemUID;
	END

	SELECT @i_CurrentCount;
	RETURN;
END
GO


--EXEC	[dbo].[atum_GetCharacterInfo_FromXMLRPC]
--		@i_AccountUID = 301,
--		@i_CharUID = 1353
--GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfoByAccountName
-- DESC				: �� ĳ�ÿ� ĳ���� ���� Ȯ�� ���ν��� (����Name), 2013-04-29 by hskim
--					  * ������ ĳ���ʹ� ������ ����
--
-- INPUT				: @AccountName			varchar(20)			���� �̸�
--
-- OUTPUT			: [AccountName]			varchar(20)			���� �̸�
--					: [AccountUID]			int					���� UID
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [CharacterUID]		int					ĳ���� UID
--					: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--                  : [InfluenceType]       tinyint             ��������		(1 = �Ϲ�, 2 = ����������, 4 = �˸���)
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetCharacterInfoByAccountName]
	@AccountName			varchar(20)
	--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT [AccountName], [AccountUniqueNumber], [CharacterName], [UniqueNumber], [Level], [UnitKind], [InfluenceType] FROM [dbo].[td_Character] WITH (NOLOCK) WHERE [AccountName] = @AccountName AND 0 = [Race] & 16384
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfoByCharacterName
-- DESC				: �� ĳ�ÿ� ĳ���� ���� Ȯ�� ���ν��� (����Name), 2013-04-29 by hskim
--					  * ������ ĳ���ʹ� ������ ����
--
-- INPUT				: @CharacterName		varchar(20)			ĳ���� �̸�
--
-- OUTPUT			: [AccountName]			varchar(20)			���� �̸�
--					: [AccountUID]			int					���� UID
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [CharacterUID]		int					ĳ���� UID
--					: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--                  : [InfluenceType]       tinyint             ��������		(1 = �Ϲ�, 2 = ����������, 4 = �˸���)
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetCharacterInfoByCharacterName]
	@CharacterName			varchar(20)
	--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT [AccountName], [AccountUniqueNumber], [CharacterName], [UniqueNumber], [Level], [UnitKind], [InfluenceType] FROM [dbo].[td_Character] WITH (NOLOCK) WHERE [CharacterName] = @CharacterName AND 0 = [Race] & 16384
END
