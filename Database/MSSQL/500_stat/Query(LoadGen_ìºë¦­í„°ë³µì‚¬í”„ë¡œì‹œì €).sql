--!!!!
-- Name: dbo.tmManager_copy_character_by_characterName
-- Desc: // 2008-03-19 by cmkwon, LoadGenerator 를 위한 Character 복사 프로시저 구현 - 임시용임, 안정성 보장 못함
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:리턴 코드
--									0	==> 에러 없음
--									10000	=> 소스 캐릭터명의 캐릭터가 없다.
--									10001	=> 타겟 캐릭터명이 이미 존재한다.
--									1002	==> 타겟 계정이 존재하지 않는다.
--									10023	==> 타겟 서버군에 캐릭터 추가시 오류 발생함
--									10028	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
--									10024	==> 타겟 서버군 td_Store테이블에 데이터 추가시 오류 발생함
--									10025	==> 타겟 서버군 td_Enchant테이블에 데이터 추가시 오류 발생함
--									10026	==> 타겟 서버군 td_StoreSkill테이블에 데이터 추가시 오류 발생함
--		[2] INPUT @i_SCharName	: 소스 캐릭터명
--		[3] INPUT @i_TAccName	: 타겟 계정명
--		[3] INPUT @i_TCharName	: 타겟 캐릭터명
--====
CREATE PROCEDURE dbo.tmManager_copy_character_by_characterName
	@o_RetCode			INT OUTPUT,				-- 
	@i_SCharName		VARCHAR(20),			-- 
	@i_TAccName			VARCHAR(20),
	@i_TCharName		VARCHAR(20)				-- 
AS
	SET @o_RetCode = 0		--			0	==> 에러 없음

	DECLARE @SAccUID INT
	DECLARE @SCharUID INT
	SELECT TOP 1 @SAccUID= AccountUniqueNumber, @SCharUID= UniqueNumber FROM dbo.td_Character WITH (NOLOCK) WHERE CharacterName = @i_SCharName
	IF (@SAccUID IS NULL) OR (@SCharUID IS NULL)
	BEGIN
		SET @o_RetCode = 1000	--	10000	=> 소스 캐릭터명의 캐릭터가 없다.
		RETURN
	END

	IF EXISTS(SELECT * FROM dbo.td_character WITH(NOLOCK) WHERE CharacterName = @i_TCharName)
	BEGIN
		SET @o_RetCode = 1001	--	10001	=> 타겟 캐릭터명이 이미 존재한다.
		RETURN
	END
	
	DECLARE @TAccUID INT
	SET @TAccUID = (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_TAccName)
	IF (@TAccUID IS NULL)
	BEGIN
		SET @o_RetCode = 1002	--	1002	==> 타겟 계정이 존재하지 않는다.
		RETURN
	END

	DECLARE @errNum INT

	BEGIN TRAN

		-- 캐릭터를 복사 한다.
		INSERT INTO dbo.td_Character
			SELECT @i_TCharName, @i_TAccName, @TAccUID,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,
				CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,NULL,0,
				Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint,PKLossPoint,Material,HP,DP,SP,EP,
				PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,
				CurrentEP,BonusStat,BonusStatPoint,0,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime,WarPoint,CumulativeWarPoint,
				ArenaWin,ArenaLose,ArenaDisConnect,PCBangTotalPlayTime,0,NULL
			FROM dbo.td_Character
			WHERE UniqueNumber = @SCharUID

		IF (@@Error <> 0)
		BEGIN 			
			SET @errNum = 10023	--	10023	==> 타겟 서버군에 캐릭터 추가시 오류 발생함
			GOTO GOTO_Label_ROLLBACK
		END

		DECLARE @TCharUID INT
		SET @TCharUID	= @@IDENTITY;
		
		--------------------------------------------------------------------------------
		-- 창고와 캐릭터인벤의 아이템과 인챈트(td_Store, td_Enchant)
		DECLARE @SItemUID BIGINT
		DECLARE @SItemCnt INT
		SET @SItemUID = NULL
		SET @SItemCnt = NULL
		SELECT TOP 1 @SItemUID=UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2 ORDER BY UniqueNumber
		SELECT @SItemCnt=COUNT(*) FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2

		IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
		BEGIN
			
			DECLARE @k INT
			SET @k		= 0

			WHILE (@k < @SItemCnt)
			BEGIN
				IF (@SItemUID IS NULL)
				BEGIN
					SET @errNum = 10028	--	10028	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
					GOTO GOTO_Label_ROLLBACK					
				END

				INSERT INTO dbo.td_Store
					SELECT @TAccUID,@TCharUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
						PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
					FROM td_Store WITH(NOLOCK)
					WHERE UniqueNumber = @SItemUID

				IF (@@Error <> 0)
				BEGIN 
					SET @errNum = 10024	--	10024	==> 타겟 서버군 td_Store테이블에 데이터 추가시 오류 발생함
					GOTO GOTO_Label_ROLLBACK
				END

				DECLARE @TItemUID BIGINT
				SET @TItemUID	= @@IDENTITY;

				--------------------------------------------------------------------------------
				-- 인챈트가 존재하는 아이템은 타겟 서버군에 인챈트 추가
				IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
				BEGIN
					INSERT INTO dbo.td_Enchant
						SELECT @TItemUID, TargetItemNum, EnchantItemNum
						FROM td_Enchant WITH(NOLOCK)
						WHERE TargetItemUniqueNumber = @SItemUID

					IF (@@ERROR <> 0)
					BEGIN
						SET @errNum = 10025	--	10025	==> 타겟 서버군 td_Enchant테이블에 데이터 추가시 오류 발생함
						GOTO GOTO_Label_ROLLBACK
					END
				END

				--------------------------------------------------------------------------------
				-- 다음 아이템의 UID를 검색한다.
				SELECT TOP 1 @SItemUID= UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
				
				SET @k			= @k +1
			END -- END - WHILE (@k < @SItemCnt)

		END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


		--------------------------------------------------------------------------------
		-- 스킬(td_StoreSkill)
		IF EXISTS(SELECT * FROM td_StoreSkill WITH(NOLOCK) WHERE Possess = @SCharUID)
		BEGIN
			INSERT INTO dbo.td_StoreSkill
				SELECT AccountUniqueNumber, @TCharUID, ItemWindowIndex, ItemNum, CreatedTime, UseTime
				FROM td_StoreSkill WITH(NOLOCK)
				WHERE Possess = @SCharUID
			IF (@@ERROR <> 0)
			BEGIN
				SET @errNum = 10026	--	10026	==> 타겟 서버군 td_StoreSkill테이블에 데이터 추가시 오류 발생함
				GOTO GOTO_Label_ROLLBACK
			END
		END


		--------------------------------------------------------------------------------
		-- 퀘스트(td_CharacterQuest)는 복사하지 않는다.
		--------------------------------------------------------------------------------
		-- 튜토리얼(td_TutorialComplete)도 복사하지 않는다.
	COMMIT TRAN

	SET @o_RetCode = 0		--			0	==> 에러 없음

	RETURN 

	--------------------------------------------------------------------------------
	--
	GOTO_Label_ROLLBACK:
		ROLLBACK TRAN
		SET @o_RetCode = @errNum
		RETURN
GO