-- !!!!
-- Name:
-- Desc:
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
-- ====
CREATE PROCEDURE dbo.atum_CreateCharacterBulk
	@CharacterName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS

	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - NickName 필드가 추가되었지만 필드명시로 인자를 추가 할 필요 없음.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @CharacterName, @CharacterName, a.AccountUniqueNumber, Gender, 2,
				UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
				SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
				Level, Experience, 0, 0, BodyCondition, Propensity, Status,
				PKWinPoint, PKLossPoint, Material, HP, DP,
				SP, EP, PetName, PetLevel, PetExperience,
				Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
				MaxLevel, currentHP, currentDP, currentSP, currentEP,
				200, 200, 0, 0, 0, GetDate(), NULL,GetDate()
		FROM atum2_db_account.dbo.td_account a, td_Character c
		WHERE c.charactername = '공격만땅' AND a.AccountName = @CharacterName
		-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
		-- WHERE c.charactername LIKE '공격만땅' AND a.AccountName LIKE @CharacterName

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername = @CharacterName)
	-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
	-- SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername LIKE @CharacterName)
	IF (@uniquenumber IS NOT NULL)
	BEGIN
		-- 무기 삽입
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 07000070, 1, 1, 2
		-- 엔진 삽입
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
		-- 돈 삽입
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0

	END
GO


--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_I
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - NickName 필드가 추가되었지만 필드명시로 인자를 추가 할 필요 없음.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'I기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- 아머 - 바인더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO


--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_A
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - NickName 필드가 추가되었지만 필드명시로 인자를 추가 할 필요 없음.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'A기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2형 무기 - 가드
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- 미키 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- 아머 - 가더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO


--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_B
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - NickName 필드가 추가되었지만 필드명시로 인자를 추가 할 필요 없음.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'B기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- 아머 - 베일 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO


--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
--		2007-01-24 by cmkwon, 프로시저 용도 수정 - 'M기어' 캐릭터를 가지고 캐릭터를 추가하는 프로시저
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_M
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - NickName 필드가 추가되었지만 필드명시로 인자를 추가 할 필요 없음.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'M기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, 문자열 쿼리 검색시 필요없는 LIKE 사용을 제거 - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- 아머 - 디펜더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO
