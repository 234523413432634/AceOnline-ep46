
-------------------------------------------------------------
-----관련 프로시저
-- // 2010-06-15 by shcho&hslee 펫시스템 - 아이템이 인벤에 추가 될 때,  펫 정보도 추가되는 처리를 수행
-- //주의! - dbo.atum_Insert_td_pet로 저장하기 때문에 항상 이 프로시저 위에 dbo.atum_Insert_td_pet가 생성되어야 한다.  
--
-- // 2011-08-05 by hskim, 파트너 시스템 2차 - 자료 구조 결정
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
	@i_LinkItem			INT				--팻 인덱스
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
-- DESC				: -- // 2013-03-13 by hskim, 웹 캐시 상점
--					  -- 해당 프로시져는 게임 서버 내에서만 호출 해야함
--					  -- atum_insertStoreItem_FromWeb 기반으로 해당 프로시져를 수정 작성, 중간 중간 내용이 틀립니다 주의하세요
--					  -- 해외에서 atum_insertStoreItem_FromWeb 프로시져를 사용하는 경우 기능 연동전 영향을 최소화 하기 위해 새로운 프로시져로 작성
--					  -- 웹 캐시 상점 인터페이스 XMLRPC 연동 하도록 유도해야 하며, 연동 후 atum_insertStoreItem_FromWeb 프로시져는 삭제해야 함
--
--					///////////////////////////////////
--					// WEAR
--					#define WEAR_NOT_ATTACHED				0	// 미장착
--					#define WEAR_ATTACHED					1	// 장착
--							
--					///////////////////////////////////////////////////////////////////////////////
--					// 2005-12-07 by cmkwon
--					#define ITEM_IN_CHARACTER				0	// 캐릭터인벤, 선택한 캐릭터 게임 시작시 한번만 호출됨
--					#define ITEM_IN_STORE					1	// 창고
--					#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, 여단 창고 
--							
--					@i_ItemWindowIndex 정보, 아래의 99로 설정하면 기본적으로 문제 없음, 다른 설정은 장착시킬때만 필요
--					#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
--
-- Parameter		:	@i_AccountUID			INT			==> 해당 계정의 고유번호 (AccountUID) , 계정 정보 정상 유무 확인용
--					@i_CharUID			INT			==> 해당 캐릭터의 고유번호(CharacterUID)
--					@i_ItemNum			INT			==> 추가 할 아이템의 ItemNum
--					@i_CurrentCount		INT			==> 추가 할 아이템의 개수, 카운터블 아이템이 아니면 최대 20개 까지만 추가 가능함
--					@i_ItemStorage		TINYINT		==> 추가 될 위치로 0이면 캐릭터의 인벤, 1이면 캐릭터의 창고임, ITEM_IN_XXX를 참고
--					@i_Wear				TINYINT		==> 추가될 위치가 캐릭터의 인벤일때에 창착 여부를 나타내며, WEAR_XXX를 참고
--					@i_ItemWindowIndex	INT			==> 창착 상태일때에만 유효하며, 창착상태가 아니면 99로 설정하면 된다.
--					@i_IsBuyCashItem	TINYINT			==> 아이템 추가가 캐쉬아이템 구매에 의한 추가 인지의 여부, 해당 값에 따라 로그 추가 위치가 달라진다.
--
-- Result Set	:	[ErrorCode INT] [InsertedItemUID BIGINT]
--					[ErrorCode INT]	==>	0 이면 성공, 0 이 아니면 에러를 리턴한 것임
--										-13,		// 아이템 위치가 유효하지 않음
--										-10,		// 아이템 수의 범위가 유효하지 않음
--										-6,		// 계정과 캐릭터 정보가 같지 않음
--										-1,		// 서버 내부 에러
--										-20,		// 허용하지 않는 아이템 (추가 / 삭제)
--										-10,		// 아이템 수의 범위가 유효하지 않음
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @i			INT;
	SET @i				= 0;

	-- 캐릭터인벤, 캐릭터 창고 아이템 추가만 지원, 여단창고 아이템 추가는 지원하지 않는다.
	IF (0 <> @i_ItemStorage) AND (1 <> @i_ItemStorage)
	BEGIN
		-- #define XMLRPC_ERROR_INVALID_ITEM_STORAGE				-13			// 아이템 위치가 유효하지 않음
		SELECT -13;
		RETURN;
	END
	IF (0 >= @i_CurrentCount)
	BEGIN
		-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// 아이템 수의 범위가 유효하지 않음
		SELECT -10;	
		RETURN;	
	END

	-- 해당 CharUID가 유효한지 체크
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID		INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384 )
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// 계정과 캐릭터 정보가 같지 않음
		SELECT -6;
		RETURN;
	END

	IF (0 != @i_ItemStorage)
	BEGIN
		SET @i_Wear				= 0;	-- 미장착
		SET @i_ItemWindowIndex	= 99;	-- 미지정
	END

	-- #define ITEM_ATTR_CASH_ITEM_PREMIUM_CARD		0x00020000		// 131072, // 2008-08-26 by cmkwon, ItemAttribute 추가 - 멤버쉽(프리미엄) 아이템,  
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
		-- #define XMLRPC_ERROR_NOT_ACCEPTED_ITEMNUM				-20			// 허용하지 않는 아이템 (추가 / 삭제)
		SELECT -20;
		RETURN
	END

	IF (0 <> dbo.atum_IsCountableItem(@ItemKd)) 
	BEGIN
		INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @i_CurrentCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

		IF (0 <> @@error)
		BEGIN
			-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// 서버 내부 에러
			SELECT -1;
			RETURN
		END
		
		--SET @InsertedItemUID = SCOPE_IDENTITY();
		SET @i					= @i + @i_CurrentCount;
	END
	ELSE
	BEGIN
		IF (10 < @i_CurrentCount)		-- 넌카운터블 아이템 처리(최대 10개 까지만 추가 가능함)
		BEGIN
			-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// 아이템 수의 범위가 유효하지 않음
			SELECT -10;
			RETURN
		END

		DECLARE @CurCount	INT;
		SET @CurCount		= 1;
		IF (0 <> dbo.atum_IsChargableItem(@ItemKd))
		BEGIN
			IF (@ItemCharging IS NULL)
			BEGIN
				-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// 서버 내부 에러
				SELECT -1;
				RETURN
			END
				
			SET @CurCount = @ItemCharging;
		END

		WHILE @i < @i_CurrentCount
		BEGIN
			IF (@ItemKd <> 38)
			BEGIN
				-- 일반 아이템
				INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
					VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @CurCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

				IF (0 <> @@error)
				BEGIN
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// 서버 내부 에러
					SELECT @i;
					RETURN
				END
			END
			ELSE
			BEGIN
				-- 파트너 아이템
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
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// 서버 내부 에러
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
-- DESC				: -- // 2013-03-13 by hskim, 웹 캐시 상점
--					  -- 해당 프로시져는 게임 서버 내에서만 호출 해야함
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetCharacterInfo_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_GiftCharUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @AccountName		VARCHAR(20);
	DECLARE @CharacterName		VARCHAR(20);
	DECLARE @Race				SMALLINT;

	-- 해당 CharUID가 유효한지 체크
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @GiftAccUID		INT; SET @GiftAccUID = 0;

	SELECT @AccUID = AccountUniqueNumber, @AccountName = AccountName, @CharacterName = CharacterName, @Race = Race FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// 계정과 캐릭터 정보가 같지 않음
		SELECT -6, NULL, NULL, NULL, 0;
		RETURN;
	END

	IF(0 != @i_GiftCharUID)
	BEGIN
		SELECT @GiftAccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_GiftCharUID AND 0 = Race & 16384
		IF (@GiftAccUID IS NULL)
		BEGIN
			-- #define XMLRPC_ERROR_INVALID_GET_CHARACTERUID				-18			// 선물 받을 계정 정보가 유효하지 않음
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
-- DESC				: -- // 2013-03-13 by hskim, 웹 캐시 상점
--					  -- 해당 프로시져는 게임 서버 내에서만 호출 해야함
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_DeleteItem_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
BEGIN
	SET NOCOUNT ON

	-- 해당 CharUID가 유효한지 체크
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @ItemUID		INT; SET @ItemUID = 0;
	DECLARE @CurrentCount	INT; SET @CurrentCount = 0;

	SELECT @AccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// 계정과 캐릭터 정보가 같지 않음
		SELECT -6;
		RETURN;
	END

	SELECT TOP 1 @ItemUID = [UniqueNumber], @CurrentCount = [CurrentCount] FROM [dbo].[td_Store] WHERE [ItemStorage] = 0 and [Possess] = @i_CharUID and [AccountUniqueNumber] = @i_AccountUID and [ItemNum] = @i_ItemNum

	IF (@ItemUID IS NULL) OR (@CurrentCount IS NULL)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// 아이템 수 부족
		SELECT -22;
		RETURN;
	END

	IF @CurrentCount < @i_CurrentCount
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// 아이템 수 부족
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
-- DESC				: 웹 캐시용 캐릭터 정보 확인 프로시져 (계정Name), 2013-04-29 by hskim
--					  * 삭제된 캐릭터는 보이지 않음
--
-- INPUT				: @AccountName			varchar(20)			계정 이름
--
-- OUTPUT			: [AccountName]			varchar(20)			계정 이름
--					: [AccountUID]			int					계정 UID
--					: [CharacterName]		varchar(20)			캐릭터 이름
--					: [CharacterUID]		int					캐릭터 UID
--					: [Level]				tinyint				캐릭터 레벨	(1~110)
--					: [UnitKind]			int					기어종류		(1 ~ 15 = B기어, 16 ~ 240 = M기어, 256 ~ 3840 = A기어, 4096 ~ 61440 = I기어)
--                  : [InfluenceType]       tinyint             세력정보		(1 = 일반, 2 = 바이제니유, 4 = 알링턴)
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
-- DESC				: 웹 캐시용 캐릭터 정보 확인 프로시져 (계정Name), 2013-04-29 by hskim
--					  * 삭제된 캐릭터는 보이지 않음
--
-- INPUT				: @CharacterName		varchar(20)			캐릭터 이름
--
-- OUTPUT			: [AccountName]			varchar(20)			계정 이름
--					: [AccountUID]			int					계정 UID
--					: [CharacterName]		varchar(20)			캐릭터 이름
--					: [CharacterUID]		int					캐릭터 UID
--					: [Level]				tinyint				캐릭터 레벨	(1~110)
--					: [UnitKind]			int					기어종류		(1 ~ 15 = B기어, 16 ~ 240 = M기어, 256 ~ 3840 = A기어, 4096 ~ 61440 = I기어)
--                  : [InfluenceType]       tinyint             세력정보		(1 = 일반, 2 = 바이제니유, 4 = 알링턴)
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetCharacterInfoByCharacterName]
	@CharacterName			varchar(20)
	--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT [AccountName], [AccountUniqueNumber], [CharacterName], [UniqueNumber], [Level], [UnitKind], [InfluenceType] FROM [dbo].[td_Character] WITH (NOLOCK) WHERE [CharacterName] = @CharacterName AND 0 = [Race] & 16384
END
