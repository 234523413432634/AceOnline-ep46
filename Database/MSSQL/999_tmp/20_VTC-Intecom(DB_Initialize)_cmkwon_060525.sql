-- 1. all user table initialze
	-- exclude td_Character table
	TRUNCATE TABLE td_CharacterQuest
	TRUNCATE TABLE td_CharacterQuestMonsterCount
	TRUNCATE TABLE td_Guild
	TRUNCATE TABLE td_GuildMember
	TRUNCATE TABLE td_Store
	TRUNCATE TABLE td_StoreSkill
	TRUNCATE TABLE td_Enchant
	TRUNCATE TABLE td_FriendList
	UPDATE td_InfluenceWarData	SET WartimeStage= 0, ContributionPoint= 0, InflLeaderCharacterUID= 0
	
	TRUNCATE TABLE atum_log_user_level_stat
	TRUNCATE TABLE atum_log_user_exp
	TRUNCATE TABLE atum_log_user_game_start_end
	TRUNCATE TABLE atum_log_user_quest_pk_dead
	TRUNCATE TABLE atum_log_user_warp
	TRUNCATE TABLE atum_log_user_speed_hack
	TRUNCATE TABLE atum_log_item_charac_use
	TRUNCATE TABLE atum_log_item_get_throw
	TRUNCATE TABLE atum_log_item_buy_sell
	TRUNCATE TABLE atum_log_item_trade
	TRUNCATE TABLE atum_log_server_map
	TRUNCATE TABLE atum_log_monster_boss
	TRUNCATE TABLE atum_backup_log_user_level_stat	
	TRUNCATE TABLE atum_backup_log_user_exp			
	TRUNCATE TABLE atum_backup_log_user_game_start_end
	TRUNCATE TABLE atum_backup_log_user_quest_pk_dead 
	TRUNCATE TABLE atum_backup_log_user_warp			
	TRUNCATE TABLE atum_backup_log_user_speed_hack	
	TRUNCATE TABLE atum_backup_log_item_charac_use	
	TRUNCATE TABLE atum_backup_log_item_get_throw	    
	TRUNCATE TABLE atum_backup_log_item_buy_sell		
	TRUNCATE TABLE atum_backup_log_item_trade		    
	TRUNCATE TABLE atum_backup_log_server_map		    
	TRUNCATE TABLE atum_backup_log_monster_boss

-- 2. td_Character table initialize
	Update td_Character
		SET InfluenceType= 1, SelectableInfluenceMask= 6, CharacterMode= 0, GuildName= ''
			, GuildUniqueNumber= 0, Level= 1, Experience= 0, DownExperience= 0, DownSPIOnDeath= 0, Propensity= 0
			, BodyCondition= 2, Status=0, PKWinPoint=0,PKLossPoint=0, Position_X=830, Position_Y=307, Position_Z=5250
			, MapIndex=8001, ChannelIndex=0, HP= 600, CurrentHP=600, EP=30, CurrentEP=30, BonusStat=0, BonusStatPoint=0
			, LastPartyID=0, TotalPlayTime=0, CreatedTime= '2006-05-26 09:00:00', LastStartedTime= NULL

	-- stat initialize
	update td_character set AttackPart = 3, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 3, DodgePart = 3, db= 33, sp= 24, ep= 30, CurrentDP= 33, CurrentSP= 24, CurrentEP= 30 
		where (unitkind = 1)	-- BGear
	update td_character set AttackPart = 2, DefensePart = 4, FuelPart = 4, SoulPart = 3, ShieldPart = 3, DodgePart = 2, db= 33, sp= 24, ep= 40, CurrentDP= 33, CurrentSP= 24, CurrentEP= 40
		where (unitkind = 16)	-- MGear
	update td_character set AttackPart = 4, DefensePart = 3, FuelPart = 4, SoulPart = 2, ShieldPart = 4, DodgePart = 1, db= 40, sp= 10, ep= 40, CurrentDP= 40, CurrentSP= 16, CurrentEP= 40
		where (unitkind = 256)	-- AGear
	update td_character set AttackPart = 4, DefensePart = 2, FuelPart = 3, SoulPart = 3, ShieldPart = 2, DodgePart = 4, db= 26, sp= 24, ep= 30, CurrentDP= 26, CurrentSP= 24, CurrentEP= 30
		where (unitkind = 4096)	-- IGear

-- 3. Level 1 base item
	DECLARE character_cur CURSOR FOR
	SELECT UniqueNumber, UnitKind
		FROM td_Character

	DECLARE @CharacterUID INT
	DECLARE @UnitKind INT
	
	OPEN character_cur
	FETCH NEXT FROM character_cur			-- Perform the first fetch.
	INTO @CharacterUID, @UnitKind

	WHILE @@FETCH_STATUS = 0				-- Check @@FETCH_STATUS to see if there are any more rows to fetch.
	BEGIN
		
		IF ( @UnitKind = 1)     -- BT, B-Gear
			BEGIN
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7900000, 150, 1, 4		-- 2형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7001230, 1, 1, 6			-- 엔진
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 8010100, 1, 1, 5		-- 아머 - 베일 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 16)    -- OT, M-Gear
			BEGIN
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7900000, 150, 1, 4		-- 2형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7002580, 1, 1, 6			-- 엔진
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 8011100, 1, 1, 5		-- 아머 - 디펜더 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 256)     -- DT, A-Gear
			BEGIN
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7000050, 1000, 1, 2		-- 1형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7900440, 300, 1, 4			-- 2형 무기 - 가드
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7002590, 1, 1, 6			-- 엔진
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7011500, 1, 1, 0		-- 미키 레이다
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 8012100, 1, 1, 5		-- 아머 - 가더 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 4096)     -- ST, I-Gear
			BEGIN
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7900000, 150, 1, 4		-- 2형 무기
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7002570, 1, 1, 6			-- 엔진
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @CharacterUID, 8013100, 1, 1, 5		-- 아머 - 바인더 2005-12-03 by cmkwon
			END
		
		EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @CharacterUID, 7000022, 0		-- 2005-12-07 by cmkwon, 아이템은 꼭 추가 해야함

		FETCH NEXT FROM character_cur			-- Perform the first fetch.
		INTO @CharacterUID, @UnitKind
	END	
	CLOSE character_cur
	DEALLOCATE character_cur