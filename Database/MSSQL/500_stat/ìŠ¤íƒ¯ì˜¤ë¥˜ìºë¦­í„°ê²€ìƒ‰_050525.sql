-- 2005-03-03 by cmkwon, 스탯 오류 사용자 체크
-- 1 atum_db_[n] DB에 오류 사용자를 추가할 테이블을 만든다
	CREATE TABLE td_StatErrorCharacter(
		CharacterUID			INT	NOT NULL,
		Level					INT	DEFAULT 0,
		CharacterStat			INT	DEFAULT 0,
		OriginalCharacterStat	INT	DEFAULT 0
	)	
	GO

-- 2. 스탯 오류 캐릭터를 추가할 테이블 비우기
	TRUNCATE TABLE td_StatErrorCharacter
	
-- 3. 스탯 오류 캐릭터 검색
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
		SET @CharStat = @BonusStat + (@AttackPart)/@AttackR + (@DefensePart)/@DefenseR + (@FuelPart)/@FuelR + (@SoulPart)/@SoulR + (@ShieldPart)/@ShieldR + (@DodgePart)/@DodgeR
		
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

-- 4. td_StatErrorCharacter 테이블 검색
	SELECT c.uniqueNumber, c.CharacterName, c.Race, c. LEVEL, c.BonusStat, c.AttackPart
			, c.DefensePart, c.FuelPart, c.SoulPart, c.ShieldPart, c.DodgePart
			, sec.CharacterStat, sec.OriginalCharacterStat
		FROM td_Character c INNER JOIN td_StatErrorCharacter sec ON c.UniqueNumber = sec.CharacterUID
		ORDER BY sec.CharacterStat DESC
	