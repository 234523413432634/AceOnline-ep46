
CREATE PROCEDURE dbo.CharacterCopy
	@o_RetCode					INT OUTPUT,
	@i_CharacterName			VARCHAR(20),		-- OriginalCharacterName
	@i_CreateCharacterName		VARCHAR(20),
	@i_CreateAccountName		VARCHAR(20)
--	@i_CreateAccountUID			INT			
AS
	SET @o_RetCode = 0		--			0	==> no error
	DECLARE @CheckCode INT
	SET @CheckCode = (SELECT Count(*) FROM td_account WHERE AccountName = @i_CreateAccountName)
	IF (@CheckCode <> 1)
	BEGIN
		SET @o_RetCode = 10 -- 10 ==> account not exist
		return @o_RetCode
	END	

	DECLARE @i_CreateAccountUID INT
	SET @i_CreateAccountUID = (SELECT AccountUniqueNumber FROM td_account WHERE AccountName = @i_CreateAccountName)
	
	SET @CheckCode = (SELECT Count(*) FROM td_character WHERE AccountUniqueNumber = @i_CreateAccountUID AND 0 <> (Race & 0x4000))
	IF (@CheckCode >= 3)
	BEGIN
		SET @o_RetCode = 20 -- 20 ==> characterCount exceed 
		return @o_RetCode
	END

	SET @CheckCode = (SELECT Count(*) FROM td_character WHERE CharacterName = @i_CreateCharacterName)
	IF (@CheckCode <> 0)
	BEGIN
		SET @o_RetCode = 30 -- 30 ==> character exist
		return @o_RetCode
	END

	--td_character copy
	INSERT INTO td_character (CharacterName, AccountName, AccountUniqueNumber, Gender, Race, UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace
				, CharacterMode, AutoStatType, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level, Experience, DownExperience, DownSPIOnDeath
				, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, Material, HP, DP, SP, EP, PetName, PetLevel, PetExperience
				, Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex, MaxLevel, CurrentHP, CurrentDP, CurrentSP, CurrentEP
				, BonusStat, BonusStatPoint, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect)
		SELECT @i_CreateCharacterName, @i_CreateAccountName, @i_CreateAccountUID, Gender, Race, UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace
			, CharacterMode, AutoStatType, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level, Experience, DownExperience, DownSPIOnDeath
			, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, Material, HP, DP, SP, EP, PetName, PetLevel, PetExperience
			, Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex, MaxLevel, CurrentHP, CurrentDP, CurrentSP, CurrentEP
			, BonusStat, BonusStatPoint, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect
		FROM td_character
		WHERE CharacterName = @i_CharacterName

	DECLARE @CharacterUID INT
	DECLARE @CreateCharacterUID INT
	SET @CharacterUID = (SELECT UniqueNumber FROM td_character WHERE CharacterName = @i_CharacterName)
	SET @CreateCharacterUID = (SELECT UniqueNumber FROM td_character WHERE CharacterName = @i_CreateCharacterName)

-- td_CharacterQuest copy
	INSERT td_CharacterQuest (CharacterUniqueNumber, QuestIndex, QuestState, QuestParam1, QuestTimeStamp, QuestPlayTimeStamp)
		SELECT @CreateCharacterUID, QuestIndex, QuestState, QuestParam1, QuestTimeStamp, QuestPlayTimeStamp
		FROM td_CharacterQuest
		WHERE CharacterUniqueNumber = @CharacterUID

-- td_CharacterQuestMonsterCount copy
--	INSERT td_CharacterQuestMonsterCount (CharacterUniqueNumber, QuestIndex, MonsterUniqueNumber, Count)
--		SELECT @CreateCharacterUID, QuestIndex, MonsterUniqueNumber, Count
--		FROM td_CharacterQuestMonsterCount
--		WHERE CharacterUniqueNumber = @CharacterUID

-- td_storeskill copy
	INSERT td_storeskill (AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime)
		SELECT @i_CreateAccountUID, @CreateCharacterUID, ItemWindowIndex, ItemNum, CreatedTime, NULL
		FROM td_storeskill
		WHERE Possess = @CharacterUID

-- td_store copy
	-- 창고와 캐릭터인벤의 아이템과 인챈트(td_Store, td_Enchant)
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL

	SELECT TOP 1 @SItemUID=UniqueNumber 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 ORDER BY UniqueNumber

	SELECT @SItemCnt=COUNT(*) 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000

	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			INSERT td_store (AccountUniqueNumber, Possess, ItemStorage, Wear, CurrentCount, ScarcityNumber, ItemWindowIndex
					, ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime)
				SELECT @i_CreateAccountUID,  @CreateCharacterUID, ItemStorage, Wear, CurrentCount, ScarcityNumber, ItemWindowIndex
						, ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime
				FROM td_Store WITH(NOLOCK)
				WHERE UniqueNumber = @SItemUID

			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- 인챈트가 존재하는 아이템은 타겟 서버군에 인챈트 추가
			IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID
			END

			--------------------------------------------------------------------------------
			-- 다음 아이템의 UID를 검색한다.
			SELECT TOP 1 @SItemUID= UniqueNumber 
			FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
			ON S.Possess = @CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 AND UniqueNumber > @SItemUID 
			ORDER BY UniqueNumber
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)

GO