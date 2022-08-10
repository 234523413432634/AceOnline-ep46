-- 2005-03-03 by cmkwon, 스탯 오류 사용자 체크
-- 1.1 atum2_db_account DB에 ti_ComputerItemStat Table 만들기
	CREATE TABLE ti_ComputerItemStat(
		ItemNum			INT	DEFAULT 0,
		Attack			INT	DEFAULT 0,
		Defense			INT	DEFAULT 0,
		Fuel			INT	DEFAULT 0,
		Soul			INT	DEFAULT 0,
		Shield			INT	DEFAULT 0,
		Dodge			INT	DEFAULT 0
	)
	CREATE CLUSTERED INDEX idx_ItemNum_at_ComputerItemStat ON ti_ComputerItemStat(ItemNum)
	GO
	
-- 2.1 atum_db_[n] DB에 ti_ComputerItemStat VIEW 만들기
	CREATE VIEW ti_ComputerItemStat
	AS
		SELECT * FROM atum2_db_account.atum.ti_ComputerItemStat
	GO
-- 2.2 atum_db_[n] DB에 오류 사용자를 추가할 테이블을 만든다
	CREATE TABLE td_StatErrorCharacter(
		CharacterUID			INT	NOT NULL,
		Level					INT	DEFAULT 0,
		CharacterStat			INT	DEFAULT 0,
		OriginalCharacterStat	INT	DEFAULT 0
	)	
	GO
-- 3. ti_ComputerItemStat 테이블 비우기
	TRUNCATE TABLE ti_ComputerItemStat
-- 4. ti_ComputerItemStat 테이블 데이타 만들기
	DECLARE computer_cur CURSOR FOR
	SELECT ItemNum, DestParameter1, ParameterValue1, DestParameter2, ParameterValue2, DestParameter3, ParameterValue3, DestParameter4, ParameterValue4
		FROM ti_Item
	WHERE Kind = 26
	
	DECLARE @ItemNum INT
	DECLARE @DP1 INT, @PV1 INT
	DECLARE @DP2 INT, @PV2 INT
	DECLARE @DP3 INT, @PV3 INT
	DECLARE @DP4 INT, @PV4 INT
	
	OPEN computer_cur
	FETCH NEXT FROM computer_cur			-- Perform the first fetch.
	INTO @ItemNum, @DP1, @PV1, @DP2, @PV2, @DP3, @PV3, @DP4, @PV4
	
	WHILE @@FETCH_STATUS = 0				-- Check @@FETCH_STATUS to see if there are any more rows to fetch.
	BEGIN
		-- This is executed as long as the previous fetch succeeds.
	
		DECLARE @Attack INT
		DECLARE @Defense INT
		DECLARE @Fuel INT
		DECLARE @Soul INT
		DECLARE @Shield INT
		DECLARE @Dodge INT
		SET @Attack = 0
		SET @Defense = 0
		SET @Fuel = 0
		SET @Soul = 0
		SET @Shield = 0
		SET @Dodge = 0
	
		IF @DP1 = 1
			SET @Attack = @PV1
		ELSE IF @DP1 = 2
			SET @Defense = @PV1
		ELSE IF @DP1 = 3
			SET @Fuel = @PV1
		ELSE IF @DP1 = 4
			SET @Soul = @PV1
		ELSE IF @DP1 = 5
			SET @Shield = @PV1
		ELSE IF @DP1 = 6
			SET @Dodge = @PV1
	
		IF @DP2 = 1
			SET @Attack = @PV2
		ELSE IF @DP2 = 2
			SET @Defense = @PV2
		ELSE IF @DP2 = 3
			SET @Fuel = @PV2
		ELSE IF @DP2 = 4
			SET @Soul = @PV2
		ELSE IF @DP2 = 5
			SET @Shield = @PV2
		ELSE IF @DP2 = 6
			SET @Dodge = @PV2
	
		IF @DP3 = 1
			SET @Attack = @PV3
		ELSE IF @DP3 = 2
			SET @Defense = @PV3
		ELSE IF @DP3 = 3
			SET @Fuel = @PV3
		ELSE IF @DP3 = 4
			SET @Soul = @PV3
		ELSE IF @DP3 = 5
			SET @Shield = @PV3
		ELSE IF @DP3 = 6
			SET @Dodge = @PV3
	
		IF @DP4 = 1
			SET @Attack = @PV4
		ELSE IF @DP4 = 2
			SET @Defense = @PV4
		ELSE IF @DP4 = 3
			SET @Fuel = @PV4
		ELSE IF @DP4 = 4
			SET @Soul = @PV4
		ELSE IF @DP4 = 5
			SET @Shield = @PV4
		ELSE IF @DP4 = 6
			SET @Dodge = @PV4
	
		INSERT INTO ti_ComputerItemStat
		VALUES(@ItemNum, @Attack, @Defense, @Fuel, @Soul, @Shield, @dodge)
			
		FETCH NEXT FROM computer_cur
		INTO @ItemNum, @DP1, @PV1, @DP2, @PV2, @DP3, @PV3, @DP4, @PV4
	END
	
	CLOSE computer_cur
	DEALLOCATE computer_cur

-- 5. 스탯 오류 캐릭터를 추가할 테이블 비우기
	TRUNCATE TABLE td_StatErrorCharacter
	
-- 6. 스탯 오류 캐릭터 검색
	DECLARE character_cur CURSOR FOR
	SELECT UniqueNumber, UnitKind, Level, BonusStat, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart
		FROM td_Character

	DECLARE @CharacterUID INT
	DECLARE @UnitKind INT
	DECLARE @Level INT
	DECLARE @BonusStat INT
	DECLARE @AttackPart INT, @DefensePart INT, @FuelPart INT
	DECLARE @SoulPart INT, @ShieldPart INT, @DodgePart INT
	
	OPEN character_cur
	FETCH NEXT FROM character_cur			-- Perform the first fetch.
	INTO @CharacterUID, @UnitKind, @Level, @BonusStat, @AttackPart, @DefensePart, @FuelPart, @SoulPart, @ShieldPart, @DodgePart
	
	WHILE @@FETCH_STATUS = 0				-- Check @@FETCH_STATUS to see if there are any more rows to fetch.
	BEGIN
		-- This is executed as long as the previous fetch succeeds.
	
		DECLARE @CAttack INT
		DECLARE @CDefense INT
		DECLARE @CFuel INT
		DECLARE @CSoul INT
		DECLARE @CShield INT
		DECLARE @CDodge INT
		SET @CAttack = 0
		SET @CDefense = 0
		SET @CFuel = 0
		SET @CSoul = 0
		SET @CShield = 0
		SET @CDodge = 0
		
		SELECT @CAttack = i.Attack, @CDefense = i.Defense, @CFuel = i.Fuel, @CSoul = i.Soul, @CShield = i.Shield, @CDodge = i.Dodge
			FROM td_Store s, ti_ComputerItemStat i
			WHERE s.Possess = @CharacterUID and s.Wear = 1 and s.ItemNum = i.ItemNum
		
		DECLARE @AttackR INT
		DECLARE @DefenseR INT
		DECLARE @FuelR INT
		DECLARE @SoulR INT
		DECLARE @ShieldR INT
		DECLARE @DodgeR INT
		SET @AttackR = 0
		SET @DefenseR = 0
		SET @FuelR = 0
		SET @SoulR = 0
		SET @ShieldR = 0
		SET @DodgeR = 0
		
		IF @UnitKind = 1
			BEGIN
				SET @AttackR = 3
				SET @DefenseR = 3
				SET @FuelR = 3
				SET @SoulR = 3
				SET @ShieldR = 3
				SET @DodgeR = 3		
			END
		ELSE IF @UnitKind = 16
			BEGIN			
				SET @AttackR = 2
				SET @DefenseR = 4
				SET @FuelR = 4
				SET @SoulR = 2
				SET @ShieldR = 3
				SET @DodgeR = 3		
			END
		ELSE IF @UnitKind = 256
			BEGIN			
				SET @AttackR = 4
				SET @DefenseR = 3
				SET @FuelR = 4
				SET @SoulR = 2
				SET @ShieldR = 4
				SET @DodgeR = 1		
			END
		ELSE IF @UnitKind = 4096
			BEGIN			
				SET @AttackR = 4
				SET @DefenseR = 2
				SET @FuelR = 3
				SET @SoulR = 3
				SET @ShieldR = 2
				SET @DodgeR = 4		
			END
		
		-- Character Stat 계산
		DECLARE @CharStat INT
		SET @CharStat = @BonusStat + (@AttackPart-@CAttack)/@AttackR + (@DefensePart-@CDefense)/@DefenseR + (@FuelPart-@CFuel)/@FuelR + (@SoulPart-@CSoul)/@SoulR + (@ShieldPart-@CShield)/@ShieldR + (@DodgePart-@CDodge)/@DodgeR
		
		-- Character Stat Standard
		DECLARE @OrginCharStat INT
		SET @OrginCharStat = 6 + (@Level-1)*2
		
		IF @CharStat <> @OrginCharStat
		BEGIN
			INSERT INTO td_StatErrorCharacter
			VALUES(@CharacterUID, @Level, @CharStat, @OrginCharStat)			
		END

		FETCH NEXT FROM character_cur			-- Perform the first fetch.
		INTO @CharacterUID, @UnitKind, @Level, @BonusStat, @AttackPart, @DefensePart, @FuelPart, @SoulPart, @ShieldPart, @DodgePart
	END
	
	CLOSE character_cur
	DEALLOCATE character_cur

-- 7. td_StatErrorCharacter 테이블 검색
	SELECT c.uniqueNumber, c.CharacterName, c.Race, c. LEVEL, c.BonusStat, c.AttackPart
			, c.DefensePart, c.FuelPart, c.SoulPart, c.ShieldPart, c.DodgePart
			, sec.CharacterStat, sec.OriginalCharacterStat
		FROM td_Character c INNER JOIN td_StatErrorCharacter sec ON c.UniqueNumber = sec.CharacterUID
		ORDER BY sec.CharacterStat DESC

-- * 컴퓨터 아이템 장착 해제하기
	DECLARE character_cur CURSOR FOR
	SELECT UniqueNumber, UnitKind, Level, BonusStat, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart
		FROM td_Character

	DECLARE @CharacterUID INT
	DECLARE @UnitKind INT
	DECLARE @Level INT
	DECLARE @BonusStat INT
	DECLARE @AttackPart INT, @DefensePart INT, @FuelPart INT
	DECLARE @SoulPart INT, @ShieldPart INT, @DodgePart INT
	
	OPEN character_cur
	FETCH NEXT FROM character_cur			-- Perform the first fetch.
	INTO @CharacterUID, @UnitKind, @Level, @BonusStat, @AttackPart, @DefensePart, @FuelPart, @SoulPart, @ShieldPart, @DodgePart
	
	WHILE @@FETCH_STATUS = 0				-- Check @@FETCH_STATUS to see if there are any more rows to fetch.
	BEGIN
		-- This is executed as long as the previous fetch succeeds.
	
		DECLARE @CAttack INT
		DECLARE @CDefense INT
		DECLARE @CFuel INT
		DECLARE @CSoul INT
		DECLARE @CShield INT
		DECLARE @CDodge INT
		SET @CAttack = 0
		SET @CDefense = 0
		SET @CFuel = 0
		SET @CSoul = 0
		SET @CShield = 0
		SET @CDodge = 0
		
		SELECT @CAttack = i.Attack, @CDefense = i.Defense, @CFuel = i.Fuel, @CSoul = i.Soul, @CShield = i.Shield, @CDodge = i.Dodge
			FROM td_Store s, ti_ComputerItemStat i
			WHERE s.Possess = @CharacterUID and s.Wear = 1 and s.ItemNum = i.ItemNum
				
		-- 컴퓨터 아이템 제거한 Character Stat 계산
		UPDATE td_Character
			SET AttackPart = @AttackPart-@CAttack, DefensePart = @DefensePart-@CDefense, FuelPart = @FuelPart-@CFuel
				, SoulPart = @SoulPart-@CSoul, ShieldPart = @ShieldPart-@CShield, DodgePart = @DodgePart-@CDodge		
			WHERE uniqueNumber = @CharacterUID

		-- 컴퓨터 아이템 장착해제
		IF @CAttack<>0 OR @CDefense<>0 OR @CFuel<>0 OR @CSoul<>0 OR @CShield<>0 OR @CDodge<>0
		BEGIN
			UPDATE td_Store
				SET Wear = 0, ItemWindowIndex = 99
				FROM td_Store s, ti_ComputerItemStat i
				WHERE s.Possess = @CharacterUID and s.ItemNum = i.ItemNum
		END
		
		FETCH NEXT FROM character_cur			-- Perform the first fetch.
		INTO @CharacterUID, @UnitKind, @Level, @BonusStat, @AttackPart, @DefensePart, @FuelPart, @SoulPart, @ShieldPart, @DodgePart
	END
	
	CLOSE character_cur
	DEALLOCATE character_cur
	