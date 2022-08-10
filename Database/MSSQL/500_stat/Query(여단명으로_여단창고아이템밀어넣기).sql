--!!!!
-- Name: 해당 서버군의 캐릭터를 소스상의 서버군으로 이동한다.
-- Desc:
--			2007-01-25, #define ITEM_IN_CHARACTER				0	// 캐릭터인벤
--						#define ITEM_IN_STORE					1	// 창고
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, 여단 창고 
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:리턴 코드
--									0	==> 에러 없음
--									20	==> SourceGuildName 여단이 없음
--									21	==> TargetGuildName 여단이 없음
--									22	==> 기존 서버군에서 캐릭터 정보가 검색되지 않음, 캐릭터
--									23	==> 타겟 서버군에 캐릭터 추가시 오류 발생함
--									24	==> 타겟 서버군 td_Store테이블에 데이터 추가시 오류 발생함
--									25	==> 타겟 서버군 td_Enchant테이블에 데이터 추가시 오류 발생함
--									26	==> 타겟 서버군 td_StoreSkill테이블에 데이터 추가시 오류 발생함
--									27	==> 타겟 서버군 td_CharacterQuest테이블에 데이터 추가시 오류 발생함
--									28	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
--		[2] INPUT @i_AccName: 사용자 계정
--		[3] INPUT @i_DBNumber:
--====
CREATE PROCEDURE dbo.integration_guildItem_move_to_atum2_db_5
	@o_RetCode			INT OUTPUT,				-- 2007-01-29 by cmkwon
	@i_SGuildName		VARCHAR(30),			-- SourceGuildName
	@i_TGuildName		VARCHAR(30)				-- TargetGuildName
AS
	SET @o_RetCode = 0		--			0	==> 에러 없음

	DECLARE @SGuildUID INT
	SET @SGuildUID = (SELECT GuildUniqueNumber FROM dbo.td_Guild WITH (NOLOCK) WHERE GuildName = @i_SGuildName)
	IF (@SGuildUID IS NULL)
	BEGIN
		SET @o_RetCode = 20	--			20	==> SourceGuildName 여단이 없음
		RETURN
	END
	
	DECLARE @TGuildUID INT
	SET @TGuildUID = (SELECT GuildUniqueNumber FROM atum2_db_5.dbo.td_Guild WITH (NOLOCK) WHERE GuildName = @i_TGuildName)
	IF (@TGuildUID IS NULL)
	BEGIN
		SET @o_RetCode = 21	--			21	==> TargetGuildName 여단이 없음
		RETURN
	END

	DECLARE @errNum INT

	--------------------------------------------------------------------------------
	--------------------------------------------------------------------------------
	BEGIN TRAN

	--------------------------------------------------------------------------------
	-- 여단창고와 해당 아이템의 인챈트(td_Store, td_Enchant)를 밀어넣기 한다.
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL
	SELECT @SItemCnt=COUNT(*) FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2
	SELECT TOP 1 @SItemUID=UniqueNumber FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2 ORDER BY UniqueNumber

	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			IF (@SItemUID IS NULL)
			BEGIN
				SET @errNum = 28	--			28	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
				GOTO GOTO_Label_ROLLBACK					
			END

			INSERT INTO atum2_db_5.dbo.td_Store
				SELECT @TGuildUID, @TGuildUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
					PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
				FROM dbo.td_Store WITH(NOLOCK)
				WHERE UniqueNumber = @SItemUID

			IF (@@Error <> 0)
			BEGIN 
				SET @errNum = 24	--			24	==> 타겟 서버군 td_Store테이블에 데이터 추가시 오류 발생함
				GOTO GOTO_Label_ROLLBACK
			END

			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- 인챈트가 존재하는 아이템은 타겟 서버군에 인챈트 추가
			IF EXISTS(SELECT * FROM dbo.td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_5.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM dbo.td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @errNum = 25	--			25	==> 타겟 서버군 td_Enchant테이블에 데이터 추가시 오류 발생함
					GOTO GOTO_Label_ROLLBACK
				END
			END

			--------------------------------------------------------------------------------
			-- 다음 아이템의 UID를 검색한다.
			SELECT TOP 1 @SItemUID= UniqueNumber FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


		
	COMMIT TRAN
	--------------------------------------------------------------------------------
	--------------------------------------------------------------------------------

	SET @o_RetCode = 0		--			0	==> 에러 없음

	RETURN 

	--------------------------------------------------------------------------------
	--
	GOTO_Label_ROLLBACK:
		ROLLBACK TRAN
		SET @o_RetCode = @errNum
		RETURN

GO