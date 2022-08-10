
-- 
-- 대회서버 db는 atum2_db_20를 사용한다.

--!!!!
-- Name: jamboree_init_jamboree_db
-- Desc: 대회서버 그룹용 프로시저로 DB의 캐릭터를 삭제하기 위한 프로시저이다
--		 운영자, 관리자의 캐릭터를 제외한 모든 캐릭터와 캐릭터 관련 데이터가 삭제됨
--
--		#define RACE_OPERATION				(USHORT)0x0080	// 관리자, 128
--		#define RACE_GAMEMASTER				(USHORT)0x0100	// 게임마스터, 256

-- warning:	서버가 내려간 상태에서 처리되어야 함
--			
-- input:
-- output:
--====
CREATE PROCEDURE dbo.jamboree_init_jamboree_db	
AS
	-- 1. 캐릭터 소유 아이템의 인챈트 제거	
	DELETE atum2_db_20.dbo.td_Enchant FROM td_Enchant e, td_Store s 
	WHERE s.AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND s.Possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND s.UniqueNumber = e.TargetItemUniqueNumber

	-- 2. 캐릭터 소유 아이템 제거
	DELETE FROM atum2_db_20.dbo.td_Store WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 3. 캐릭터 퀵 슬롯 제거
	DELETE FROM atum2_db_20.dbo.td_QuickSlot WHERE AccountUID IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND CharacterUID IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 4. 캐릭터 소유 스킬 제거
	DELETE FROM atum2_db_20.dbo.td_StoreSkill WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 5. 퀘스트 테이블에서 제거
	DELETE FROM atum2_db_20.dbo.td_CharacterQuest WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 6. 친구리스트에서 제거
	DELETE FROM atum2_db_20.dbo.td_FriendList WHERE CharacterName IN 
	(SELECT CharacterName FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) OR FriendName IN 
	(SELECT CharacterName FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- last 캐릭터 테이블에서 제거
	DELETE FROM atum2_db_20.dbo.td_Character WHERE UniqueNumber IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 모든 운영자, 관리자 캐릭터의 여단 초기화함
	UPDATE atum2_db_20.dbo.td_character
	SET GuildName = '', GuildUniqueNumber = 0

	-- 모든 여단 초기화함, 대회서버 초기화시 모든 여단 삭제됨
	TRUNCATE TABLE atum2_db_20.dbo.td_GuildMember
	TRUNCATE TABLE atum2_db_20.dbo.td_Guild
GO


--!!!!
-- Name: jamboree_copy_character_to_jamboree_db
-- Desc: 대회서버 그룹용 프로시저로 DB의 캐릭터를 삭제하기 위한 프로시저이다
--		 운영자, 관리자를 제외한 모든 캐릭터와 캐릭터 소유의 데이터를 삭제한다.
--
--			2007-01-25, #define ITEM_IN_CHARACTER				0	// 캐릭터인벤
--						#define ITEM_IN_STORE					1	// 창고
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, 여단 창고 
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:리턴 코드
--									0	==> 에러 없음
--									20	==> 해당 계정의 캐릭터가 없음
--									21	==> 통합하려는 서버군에 해당 계정의 캐릭터가 존재한다.
--									22	==> 기존 서버군에서 캐릭터 정보가 검색되지 않음, 캐릭터
--									23	==> 타겟 서버군에 캐릭터 추가시 오류 발생함
--									24	==> 타겟 서버군 td_Store테이블에 데이터 추가시 오류 발생함
--									25	==> 타겟 서버군 td_Enchant테이블에 데이터 추가시 오류 발생함
--									26	==> 타겟 서버군 td_StoreSkill테이블에 데이터 추가시 오류 발생함
--									27	==> 타겟 서버군 td_CharacterQuest테이블에 데이터 추가시 오류 발생함
--									28	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
--									29	==> // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 타겟 서버군 DB 에 캐릭터가 이미 3개 이상 존재한다.
--									30	==> // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 타겟 서버군 DB 에 같은 캐릭터명이 존재한다.
--		[2] INPUT @i_CharName: 캐릭터명
--		[3] INPUT i_PreAddString2CharacterName: 캐릭터명앞에 붙일 추가 스트링
--									ex> '1_', '2_', '3_',....
--====
CREATE PROCEDURE dbo.jamboree_copy_character_to_jamboree_db
	@o_RetCode						INT OUTPUT,
	@i_CharName						VARCHAR(20),
	@i_PreAddString2CharacterName	VARCHAR(5)
AS
	SET @o_RetCode = 0		--			0	==> 에러 없음

	DECLARE @AccountUID INT
	DECLARE @SCharUID INT
	SELECT TOP 1 @AccountUID=AccountUniqueNumber, @SCharUID=UniqueNumber FROM td_Character WITH (NOLOCK) WHERE CharacterName = @i_CharName ORDER BY UniqueNumber
	IF (@AccountUID IS NULL) OR (@SCharUID IS NULL)
	BEGIN
		SET @o_RetCode = 20		--			20	==> 해당 계정의 캐릭터가 없음
		RETURN
	END

-- // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 하나의 계정의 여러개 캐릭터를 복사 할 수 있도록 하기 위해 체크 루틴 아래와 같이 수정 함	
--	IF Exists(SELECT * FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID)
--	BEGIN 
--		SET @o_RetCode = 21		--			21	==> 대회서버 서버군(atum2_db_20)에 해당 계정의 캐릭터가 존재한다.
--		RETURN
--	END
	DECLARE @CharacterCnts INT	
	SET @CharacterCnts = (SELECT COUNT(*) FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID)
	IF (@CharacterCnts IS NOT NULL) AND (3 <= @CharacterCnts)
	BEGIN 
		SET @o_RetCode = 29		--			29	==> // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 타겟 서버군 DB에 캐릭터가 이미 3개 이상 존재한다.
		RETURN
	END

	DECLARE @TCharName VARCHAR(20)
	SET @TCharName			= NULL
	SELECT TOP 1 @TCharName=CharacterName 
	FROM atum2_db_20.dbo.td_Character WITH(NOLOCK) WHERE CharacterName = @i_PreAddString2CharacterName + @i_CharName

	IF (@TCharName IS NOT NULL)
	BEGIN
		-- // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 아래와 같이 에러 코드를 리턴 함
		--SET @TCharName = @i_PreAddString2CharacterName + '#' + @i_CharName
		SET @o_RetCode = 30		--			30	==> // 2007-11-05 by cmkwon, 대회 서버 캐릭터 복사 시스템 수정 - 타겟 서버군 DB 에 같은 캐릭터명이 존재한다.
		RETURN
	END
	ELSE
	BEGIN
		SET @TCharName = @i_PreAddString2CharacterName + @i_CharName
	END
	
	--------------------------------------------------------------------------------
	-- 캐릭터추가(td_character)
	INSERT INTO atum2_db_20.dbo.td_Character
		SELECT @TCharName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,
			CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,NULL,0,
			Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint,PKLossPoint,Material,HP,DP,SP,EP,
			PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,
			CurrentEP,BonusStat,BonusStatPoint,0,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime,WarPoint,CumulativeWarPoint,
			ArenaWin,ArenaLose,ArenaDisConnect,PCBangTotalPlayTime,0 	--// 2008-06-20 by dhjin, EP3 유저정보옵션 -		-- 20070712 아레나 관련 및 PC방 플레이시간 추가
		FROM td_Character WITH(NOLOCK)
		WHERE UniqueNumber = @SCharUID

	IF (@@Error <> 0)
	BEGIN 			
		SET @o_RetCode = 23	--			23	==> 대회서버 서버군(atum2_db_20)에 캐릭터 추가시 오류 발생함
		RETURN
	END

	DECLARE @TCharUID INT
	SET @TCharUID	= @@IDENTITY;
	
	--------------------------------------------------------------------------------
	-- 창고와 캐릭터인벤의 아이템과 인챈트(td_Store, td_Enchant)
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL
	SELECT TOP 1 @SItemUID=UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2 ORDER BY UniqueNumber
	SELECT @SItemCnt=COUNT(*) FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2

	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			IF (@SItemUID IS NULL)
			BEGIN
				SET @o_RetCode = 28	--			28	==> 기존 서버군에서 아이템 정보가 검색되지 않음, td_Store
				RETURN
			END

			INSERT INTO atum2_db_20.dbo.td_Store
				SELECT AccountUniqueNumber,@TCharUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
					PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
				FROM td_Store WITH(NOLOCK)
				WHERE UniqueNumber = @SItemUID

			IF (@@Error <> 0)
			BEGIN 
				SET @o_RetCode = 28	--			24	==> 대회서버 서버군(atum2_db_20) td_Store테이블에 데이터 추가시 오류 발생함
				RETURN
			END

			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- 인챈트가 존재하는 아이템은 대회서버 서버군(atum2_db_20)에 인챈트 추가
			IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_20.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @o_RetCode = 25	--			25	==> 대회서버 서버군(atum2_db_20) td_Enchant테이블에 데이터 추가시 오류 발생함
					RETURN
				END
			END

			--------------------------------------------------------------------------------
			-- 다음 아이템의 UID를 검색한다.
			SELECT TOP 1 @SItemUID= UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


	--------------------------------------------------------------------------------
	-- 스킬(td_StoreSkill)
	IF EXISTS(SELECT * FROM td_StoreSkill WITH(NOLOCK) WHERE Possess = @SCharUID)
	BEGIN
		INSERT INTO atum2_db_20.dbo.td_StoreSkill
			SELECT AccountUniqueNumber, @TCharUID, ItemWindowIndex, ItemNum, CreatedTime, UseTime
			FROM td_StoreSkill WITH(NOLOCK)
			WHERE Possess = @SCharUID
		IF (@@ERROR <> 0)
		BEGIN
			SET @o_RetCode = 26	--			26	==> 대회서버 서버군(atum2_db_20) td_StoreSkill테이블에 데이터 추가시 오류 발생함
			RETURN
		END
	END


	--------------------------------------------------------------------------------
	-- 퀘스트(td_CharacterQuest)
	IF EXISTS(SELECT * FROM td_CharacterQuest WITH(NOLOCK) WHERE CharacterUniqueNumber = @SCharUID)
	BEGIN
		INSERT INTO atum2_db_20.dbo.td_CharacterQuest
			SELECT @TCharUID, QuestIndex, QuestState, QuestParam1, QuestTimeStamp, QuestPlayTimeStamp
			FROM td_CharacterQuest WITH(NOLOCK)
			WHERE CharacterUniqueNumber = @SCharUID
		IF (@@ERROR <> 0)
		BEGIN
			SET @o_RetCode = 27	--			27	==> 대회서버 서버군(atum2_db_20) td_CharacterQuest테이블에 데이터 추가시 오류 발생함
			RETURN
		END
	END
	
	SET @o_RetCode = 0		--			0	==> 에러 없음
	RETURN 
GO




