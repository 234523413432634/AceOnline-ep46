--------------------------------------------------------------------------------
-- functions
--------------------------------------------------------------------------------
CREATE FUNCTION dbo.atum_IsCountableItem(@ItemKind TINYINT)
RETURNS INT
AS
BEGIN
	-- #define ITEMKIND_ENERGY					(BYTE)18	// 에너지류, countable
	-- #define ITEMKIND_INGOT					(BYTE)19	// 오어 & 보드, countable
	-- #define ITEMKIND_CARD					(BYTE)20	// 일반 카드(지금 존재하지 않음, 20040716, kelovon, 사용하게 되면 살림)
	-- #define ITEMKIND_ENCHANT				(BYTE)21	// 인챈트 카드
	-- #define ITEMKIND_BULLET					(BYTE)23	// 탄알류(=탄통), countable
	-- #define ITEMKIND_QUEST					(BYTE)24	// 퀘스트용 아이템, countable
	-- #define ITEMKIND_GAMBLE					(BYTE)27	// RareFix 생성용 카드, 인챈트와 같은 방법 사용
	-- #define ITEMKIND_PREVENTION_DELETE_ITEM	(BYTE)28	// 인챈트 시에 아이템 삭제 방지 아이템 
	-- #define ITEMKIND_INFLUENCE_BUFF			(BYTE)33	// 2006-04-21 by cmkwon, 세력 버프, 현재는 세력버프 아이템
	-- #define ITEMKIND_INFLUENCE_GAMEEVENT	(BYTE)34	// 2006-04-21 by cmkwon, 세력 게임이벤트

	-- #define IS_COUNTABLE_ITEM(_ITEM_KIND)			((_ITEM_KIND) == ITEMKIND_ENERGY || (_ITEM_KIND) == ITEMKIND_INGOT || (_ITEM_KIND) == ITEMKIND_CARD || (_ITEM_KIND) == ITEMKIND_ENCHANT || (_ITEM_KIND) == ITEMKIND_BULLET || (_ITEM_KIND) == ITEMKIND_QUEST || (_ITEM_KIND) == ITEMKIND_GAMBLE || (_ITEM_KIND) == ITEMKIND_PREVENTION_DELETE_ITEM || (_ITEM_KIND) == ITEMKIND_INFLUENCE_BUFF || (_ITEM_KIND) == ITEMKIND_INFLUENCE_GAMEEVENT)
	IF (@ItemKind = 18 OR @ItemKind = 19 OR @ItemKind = 20 OR @ItemKind = 21 OR @ItemKind = 23 OR @ItemKind = 24 OR @ItemKind = 27 OR @ItemKind = 28 OR @ItemKind = 33 OR @ItemKind = 34) 
		RETURN 1
	
	RETURN 0
END
GO

CREATE FUNCTION dbo.atum_IsWeapon(@ItemKind TINYINT)
RETURNS INT
AS
BEGIN
	IF (@ItemKind >= 0 AND @ItemKind <= 15) RETURN 1
	ELSE RETURN 0

	RETURN 0
END
GO

CREATE FUNCTION dbo.atum_IsSecondaryWeapon(@ItemKind TINYINT)
RETURNS INT
AS
BEGIN
	IF (@ItemKind >= 8 AND @ItemKind <= 15) RETURN 1
	ELSE RETURN 0

	RETURN 0
END
GO

CREATE FUNCTION dbo.fn_sex(@ssn varchar(30))
RETURNS int
AS
BEGIN
	RETURN (cast(@ssn as bigint) - (cast(@ssn as bigint)/10000000)*10000000)/1000000
END
GO

CREATE FUNCTION dbo.fn_age(@ssn varchar(30))
RETURNS int
AS
BEGIN
	RETURN (cast(@ssn as bigint)/100000000000)
END
GO

CREATE FUNCTION dbo.atum_GetTimeInSeconds(@time DATETIME)
RETURNS INT
AS
BEGIN
	RETURN (datepart(d, @time)-1) * 3600 * 24 + datepart(hh, @time) * 3600 + datepart(mi, @time) * 60 + datepart(s, @time)
END
GO

CREATE FUNCTION dbo.atum_GetOnlyDate(@time DATETIME)
RETURNS INT
AS
BEGIN
	RETURN (datepart(yy, @time)) * 10000 + datepart(m, @time) * 100 + datepart(d, @time)
END
GO

CREATE FUNCTION dbo.atum_GetGearString(@unitkind SMALLINT)
RETURNS VARCHAR(10)
AS
BEGIN
	IF (@unitkind = 1) RETURN 'B'
	ELSE IF (@unitkind = 16) RETURN 'M'
	ELSE IF (@unitkind = 256) RETURN 'A'
	ELSE IF (@unitkind = 4096) RETURN 'I'
	RETURN NULL
END
GO

CREATE FUNCTION dbo.atum_GetHMSFromS(@i_nSeconds BIGINT)
RETURNS VARCHAR(30)
AS
BEGIN
	IF (@i_nSeconds IS NOT NULL)
		RETURN CAST(@i_nSeconds/3600 AS VARCHAR(10))+ 'Hour'
			 + CAST((@i_nSeconds%3600)/60 AS VARCHAR(10)) + 'Minute'
			 + CAST((@i_nSeconds%60) AS VARCHAR(10)) + 'Second'

	RETURN '?'
END
GO
--------------------------------------------------------------------------------
-- For Simulating Oracle Sequences In MS SQL
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:  for ScarcityNumber, WOULD NOT BE USED
--====
--CREATE PROCEDURE atum_scn_nextval
--	@sequence_id INT OUTPUT
--AS
--	-- return an error if sequence does not exist
--	-- so we will know if someone truncates the table
--	set @sequence_id = -1
--
--	UPDATE sequences
--	SET    @sequence_id = sequence_id = sequence_id + 1
--	WHERE  seq = 0
--
--	RETURN @sequence_id
--GO

--------------------------------------------------------------------------------
-- 관리용 procedures
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_GetAccountInfo
	@accName varchar(20)
AS
	SELECT a.accountname, a.AccountUniqueNumber, c.charactername, c.uniquenumber
	FROM td_Account a, td_Character c
	WITH (NOLOCK)
	WHERE a.accountname LIKE @accName AND c.accountuniquenumber = a.AccountUniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItemToAllCharacter_DB
	@vItemNum INT
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, 1, 0, 99,
				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WHERE i.ItemNum = @vItemNum  AND
			 c.uniquenumber IN
			( SELECT uniquenumber FROM td_Character)
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItemCountableToAllCharacter_DB
	@vItemNum INT,
	@num INT
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @num, 0, 99,
				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WHERE i.ItemNum = @vItemNum  AND
			 c.uniquenumber IN
			( SELECT uniquenumber FROM td_Character)
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB
	@charac_name varchar(20),
	@ItemNum INT
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, 1, 0, 99,
				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WHERE i.ItemNum = @ItemNum AND c.charactername LIKE @charac_name
	RETURN SCOPE_IDENTITY();
GO

-- 2005-12-07 by cmkwon, 사용하지 않음
----!!!!
---- Name:
---- Desc: 창고에 넣어주기
--====
--CREATE PROCEDURE dbo.atum_admin_InsertStoreItemToAccountStore
--	@account_name varchar(20),
--	@ItemNum INT
--AS
--	INSERT INTO td_Store
--		SELECT a.accountUniqueNumber, 0, 0, 1, 0, 99,
--				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
--		FROM ti_Item i, td_Account a
--		WHERE i.ItemNum = @ItemNum AND a.AccountName LIKE @account_name
--	RETURN SCOPE_IDENTITY();
--GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItemCountable_DB
	@charac_name varchar(64),
	@ItemNum INT,
	@CurrentCount INT
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @CurrentCount, 0, 99,
				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WHERE i.ItemNum = @ItemNum AND c.charactername LIKE @charac_name
	RETURN SCOPE_IDENTITY();
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum
	@charac INT,
	@ItemNum INT,
	@CurrentCount INT
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @CurrentCount, 0, 99,
				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	RETURN SCOPE_IDENTITY();
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default
	@charac INT,
	@ItemNum INT,
	@CurrentCount INT,
	@wear	TINYINT,
	@ItemWindowIndex	INT
AS
	DECLARE @ItemKind TINYINT
	SET @ItemKind = (SELECT Kind FROM ti_Item WITH (NOLOCK) WHERE ItemNum = @ItemNum)

	IF (dbo.atum_IsWeapon(@ItemKind) = 1)
	BEGIN
		-- 무기류이면 charging을 count에 할당
		INSERT INTO td_Store
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, i.Charging, 0, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
			FROM ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	ELSE
	BEGIN
		-- 무기류가 아니면 그냥 @Count를 할당
		INSERT INTO td_Store
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, @CurrentCount, 0, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
			FROM ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	RETURN SCOPE_IDENTITY();
GO

-- character에게 모든 무기류 삽입
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertAllWeaponToCharacter
	@acc_name		varchar(20),
	@charac_name	varchar(64)
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, i.Charging, 0, 99,
				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WITH (NOLOCK)
		WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name
			 AND i.ItemNum IN
			( SELECT ItemNum FROM ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
GO

-- character에게 유닛 종류에 맞는 무기류 삽입
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertAllWeaponToCharacterByUnitKind
	@acc_name varchar(20),
	@charac_name varchar(20)
AS
	INSERT INTO td_Store
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, i.Charging, 0, 99,
				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
		FROM ti_Item i, td_Character c
		WITH (NOLOCK)
		WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name
			AND (i.reqUnitKind & c.unitkind) != 0
			AND i.ItemNum IN
			( SELECT ItemNum FROM ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
GO

-- character에게 모든 사용가능한 스킬만 삽입
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_InsertAllSkillToCharacter
	@acc_name varchar(20),
	@charac_name varchar(20)
AS
	INSERT INTO td_StoreSkill
		SELECT c.accountUniqueNumber, c.UniqueNumber, 99, i.ItemNum, GetDate(), NULL
		FROM ti_Item i, td_Character c
		WITH (NOLOCK)
		WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name
			AND (i.reqUnitKind & c.unitkind) != 0
			AND i.skilllevel = 1
			AND i.ItemNum IN
			( SELECT ItemNum FROM ti_Item WITH (NOLOCK) WHERE Kind >= 50  AND Kind <= 53)
GO

-- character 소유의 모든 아이템 반환
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_GetStoreItemCharacter
	@acc_name varchar(20),
	@charac_name varchar(20)
AS
	SELECT a.accountname, c.charactername, i.itemname, s.*
	FROM td_Store s, td_Account a, td_Character c, ti_Item i
	WITH (NOLOCK)
	WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber
		AND s.itemnum = i.itemnum
	ORDER BY c.charactername, s.itemnum
GO

-- character 소유의 모든 스킬 반환
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_GetAllSkillOfCharacter
	@acc_name varchar(20),
	@charac_name varchar(20)
AS
	SELECT a.accountname, c.charactername, i.itemname, i.skilltype, s.*
	FROM td_StoreSkill s, td_Account a, td_Character c, ti_Item i
	WITH (NOLOCK)
	WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber
		AND s.itemnum = i.itemnum
	ORDER BY c.charactername, s.itemnum
GO

-- 계정 권한 설정
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_SetAccountType
	@acc_name varchar(20),
	@type int
AS
	UPDATE td_Account
	SET AccountType = @type
	WHERE  accountname LIKE @acc_name
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_SetAdminCharacter
	@charac_name varchar(20)
AS
	UPDATE td_Character
	SET race = race | 128
	WHERE charactername LIKE @charac_name
GO

-- 모든 캐릭터 삭제 - 계정 제외
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_DeleteAccountWOAccount
	@accName varchar(20)
AS
	DECLARE @accNum INT
	SET @accNum = (SELECT AccountUniqueNumber FROM td_Account WHERE accountname LIKE @accName)

	DELETE FROM td_Store WHERE accountuniquenumber = @accNum
	DELETE FROM td_StoreSkill WHERE accountuniquenumber = @accNum

	DELETE FROM td_Character WHERE accountuniquenumber = @accNum
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_SetMoney
	@charac_name varchar(64),
	@moneyAmount int
AS
	DECLARE @characNum INT
	SET @characNum = (SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE charactername LIKE @charac_name)

	UPDATE td_Store
	SET CurrentCount = @moneyAmount
	WHERE possess = @characNum AND itemnum = 7000022
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_admin_SetBonusStat
	@charac_name varchar(20),
	@bonusstat TINYINT
AS
	UPDATE td_Character
	SET BonusStat = @bonusstat
	WHERE charactername = @charac_name
GO

--!!!!
-- Name:
-- Desc:
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
--====
CREATE PROCEDURE dbo.atum_CreateCharacterBulk
	@CharacterName		VARCHAR(20)
AS
	INSERT INTO td_Character
		SELECT @CharacterName, @CharacterName, a.AccountUniqueNumber, Gender, 2,
				UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
				SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
				Level, Experience, 0, 0, BodyCondition, Propensity, Status,
				PKWinPoint, PKLossPoint, Material, HP, DP,
				SP, EP, PetName, PetLevel, PetExperience,
				Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
				MaxLevel, currentHP, currentDP, currentSP, currentEP,
				200, 200, 0, 0, 0, GetDate(), NULL,GetDate(), 0, 0, 0, 0, 0, 0	-- 2006-12-18 by dhjin
		FROM td_Account a, td_Character c
		WHERE c.charactername LIKE '공격만땅' AND a.AccountName LIKE @CharacterName

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername LIKE @CharacterName)
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

--------------------------------------------------------------------------------
-- 일반 procedures
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
-- 		2005-06-30 5:19 by cmkwon, 기어별 기본 제공 아이템 수정함
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
--		2006-09-14 by cmkwon, Demo 계정 기본 제공 아이템 수정함
--====
CREATE PROCEDURE dbo.atum_CreateCharacter
	@CharacterName				VARCHAR(20),
	@CharacterNameForSearch		VARCHAR(64),
	@AccountName				VARCHAR(20),
	@AccountUniqueNumber		INT,
	@Gender						TINYINT,
	@Race			SMALLINT,
	@UnitKind		INT,
	@InfluenceType	TINYINT,
	@SelectableInfluenceMask	TINYINT,		-- 2005-12-07 by cmkwon
	@PilotFace		TINYINT,
	@CharacterMode	TINYINT,
	@AutoStatType	TINYINT,
	@AttackPart		SMALLINT,
	@DefensePart	SMALLINT,
	@FuelPart		SMALLINT,
	@SoulPart		SMALLINT,
	@ShieldPart		SMALLINT,
	@DodgePart		SMALLINT,
	@GuildName		VARCHAR(30),
	@GuildUniqueNumber	INT,
	@Level			TINYINT,
	@Experience		FLOAT,
	@BodyCondition	BIGINT,
	@Propensity		INT,
	@Status			TINYINT,
	@PKWinPoint		SMALLINT,
	@PKLossPoint	SMALLINT,
	@Material		SMALLINT,
	@HP				SMALLINT,
	@DP				SMALLINT,
	@SP				SMALLINT,
	@EP				SMALLINT,
	@PetName		VARCHAR(20),
	@PetLevel		TINYINT,
	@PetExperience	FLOAT,
	@Position_X		FLOAT,
	@Position_Y		FLOAT,
	@Position_Z		FLOAT,
	@MapIndex		SMALLINT,
	@ChannelIndex	SMALLINT,
	@MaxLevel		TINYINT,
	@currentHP		FLOAT,
	@currentDP		FLOAT,
	@currentSP		SMALLINT,
	@currentEP		FLOAT,
	@bonusStat		TINYINT,
	@bonusSkillPoint	TINYINT,
	@lastPartyID	BIGINT,
	@nNumCharacter	INT OUTPUT
AS
	-- AccountType 가지고 오기
	DECLARE @AccoutTypeAppliedRace INT
	SET @AccoutTypeAppliedRace = @Race | (SELECT AccountType FROM td_Account
								WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber)

	INSERT INTO td_Character
	VALUES (@CharacterName, @AccountName, @AccountUniqueNumber, @Gender, @AccoutTypeAppliedRace,
		@UnitKind, @InfluenceType, @SelectableInfluenceMask, @PilotFace, @CharacterMode, @AutoStatType, @AttackPart, @DefensePart, @FuelPart,
		@SoulPart, @ShieldPart, @DodgePart, @GuildName, @GuildUniqueNumber,
		@Level, @Experience, 0, 0, @BodyCondition, @Propensity, @Status,
		@PKWinPoint, @PKLossPoint, @Material, @HP, @DP,
		@SP, @EP, @PetName, @PetLevel, @PetExperience,
		@Position_X, @Position_Y, @Position_Z, @MapIndex, @ChannelIndex,
		@MaxLevel, @currentHP, @currentDP, @currentSP, @currentEP,
		@bonusStat, @bonusSkillPoint, @lastPartyID, 0, 0, GetDate(), NULL,GetDate(), 0, 0, 0, 0, 0, 0, 0	-- // 2008-06-23 by dhjin, EP3 유저정보옵션
	)

	-- 2007-07-25 by cmkwon, 삭제된 캐릭터는 제외
	--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	SET @nNumCharacter = (SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000)

	--///////////////////////////////////
	--// 아이템 장착 위치(POS_XXX)
	--#define POS_PROW						((BYTE)0)	// 레이더(선두 가운데)
	--#define POS_PROWIN					((BYTE)1)	// 컴퓨터(중앙 좌측)
	--#define POS_PROWOUT					((BYTE)2)	// 1형 무기(선두 좌측)
	--#define POS_WINGIN					((BYTE)3)	//		사용안함(중앙 우측)
	--#define POS_WINGOUT					((BYTE)4)	// 2형 무기(선두 우측)
	--#define POS_CENTER					((BYTE)5)	// 아머(중앙 가운데)
	--#define POS_REAR						((BYTE)6)	// 엔진(후미 가운데)
	--#define POS_ATTACHMENT				((BYTE)7)	// 부착물(후미 우측-연료탱크|컨테이너계열)
	--#define POS_PET						((BYTE)8)	//		사용안함(후미 좌측)
	--#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
	--#define POS_ITEMWINDOW_OFFSET			((BYTE)100)	// 100, 이 번호부터 아이템창에 존재
	--#define SIZE_MAX_POS					9			// 장착 아이템 slot의 개수

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WITH (NOLOCK) WHERE charactername LIKE @CharacterNameForSearch)
	IF (@uniquenumber IS NOT NULL)
	BEGIN
		-- 무기 및 quest 삽입
		IF ( @UnitKind = 1)     -- BT, B-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001700, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E급 농축 연료
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002710, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900910, 400, 1, 4			-- 초급용 로켓
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 1, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- 엔진
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- 아머 - 베일 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 16)    -- OT, M-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001710, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E급 농축 연료
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002750, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900930, 400, 1, 4			-- 초급용 번들
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 41, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- 엔진
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- 아머 - 디펜더 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 256)     -- DT, A-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001710, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E급 농축 연료
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002770, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900940, 400, 1, 4			-- 초급용 마인
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 61, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2형 무기 - 가드
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- 엔진
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- 미키 레이다
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- 아머 - 가더 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 4096)     -- ST, I-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 10, 0, 99			-- E급 농축 연료
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002740, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900920, 400, 1, 4			-- 초급용 미사일
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 21, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- 엔진
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- 아머 - 바인더 2005-12-03 by cmkwon
			END
		
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0		-- 2005-12-07 by cmkwon, 아이템은 꼭 추가 해야함
		
		DECLARE @bIsRace	INT
		-- AccountType or Race ==> 128:관리자, 256:게임운영자, 512:모니터, 1024:게스트, 2048:데모
		-- ADMIN 계정 ==> 2006-09-14 by cmkwon, 처리사항 없음, 게임상에서 모두 변경 가능함
		--SET @bIsRace		= 128 & @AccoutTypeAppliedRace
		--IF (0 <> @bIsRace)
		--	BEGIN
		--	END

		-- DEMO 계정 ==> 2006-09-14 by cmkwon, Level:50, SPI:5000000, 보너스스탯:200, 기본아이템만 지급
		SET @bIsRace		= 2048 & @AccoutTypeAppliedRace
		IF (0 <> @bIsRace)
			BEGIN
				UPDATE td_Character
					SET level = 50, experience = 13328539, bonusstat = 200
					WHERE uniquenumber = @uniquenumber
				EXEC dbo.atum_admin_SetMoney @CharacterNameForSearch, 5000000
			END

	END
GO



--!!!!
-- Name:
-- Desc:
--		#define RACE_BATTALUS				(USHORT)0x0001	// 바탈러스, 1
--		#define RACE_DECA					(USHORT)0x0002	// 데카, 2
--		#define RACE_PHILON					(USHORT)0x0004	// 필론, 4
--		#define RACE_SHARRINE				(USHORT)0x0008	// 샤린, 8
--		#define RACE_INFLUENCE_LEADER		(USHORT)0x0010	// 16, 세력전 리더, 2006-04-20 by cmkwon, RACE_MONSTER1(예비, 16)를 변경한 것임
--		#define RACE_INFLUENCE_SUBLEADER	(USHORT)0x0020	// 32, 세력전 부지도자, 2006-12-08 by cmkwon, RACE_MONSTER2(예비, 32)를 변경한 것임 예비, 32
--		#define RACE_NPC					(USHORT)0x0040	// NPC, 64
--		#define RACE_OPERATION				(USHORT)0x0080	// 관리자, 128
--		#define RACE_GAMEMASTER				(USHORT)0x0100	// 게임마스터, 256
--		#define RACE_MONITOR				(USHORT)0x0200	// 모니터, 512
--		#define RACE_GUEST					(USHORT)0x0400	// 게스트, 1024
--		#define RACE_DEMO					(USHORT)0x0800	// 시연(데모)용, 2048
--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
--		#define RACE_ALL					(USHORT)0x000F	// 모든 종족, (RACE_BATTALUS|RACE_DECA|RACE_PHILON|RACE_SHARRINE), 15
--====
CREATE PROCEDURE dbo.atum_DeleteCharacter
	@CharUniqueNum		INT,
	@nNumCharacter		INT OUTPUT
AS
	DECLARE @AccountUniqueNumber INT
	SET @AccountUniqueNumber = (SELECT DISTINCT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE UniqueNumber = @CharUniqueNum)
	
	DECLARE @CharName VARCHAR(20)
	SET @CharName = (SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE UniqueNumber = @CharUniqueNum)
	
	IF (@AccountUniqueNumber IS NOT NULL)
		BEGIN
			-- 0.1. 캐릭터가 소지한 아이템은 atum_DeleteCharacter 호출하기 전에 모두 삭제 처리된다
			-- 0.2. 자신이 길드장일 경우는 atum_DeleteCharacter 호출하기 전에 IMServer로 길드 삭제를 전송한다
			
			-- 1. td_GuildMember 테이블에서 자신을 삭제한다
			DELETE FROM td_GuildMember WHERE CharacterUniqueNumber = @CharUniqueNum
				
--	2007.2.23 by dhjin,	케릭터 복구 정책으로 변경.
--			-- 2. 퀘스트 테이블에서 제거
--			DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber = @CharUniqueNum
--			
--			-- 3. 친구리스트에서 제거
--			DELETE FROM td_FriendList WHERE CharacterName = @CharName OR FriendName = @CharName
--				
--			-- last 캐릭터 테이블에서 제거
--			DELETE FROM td_Character WHERE UniqueNumber = @CharUniqueNum

			-- 2. 길드 정보 삭제
			UPDATE td_Character SET guildname = NULL, guilduniquenumber = 0 WHERE UniqueNumber = @CharUniqueNum

			-- 3. 케릭터 삭제로 변경
			UPDATE td_Character SET Race = Race | 0x4000, LastStartedTime = GetDate() WHERE UniqueNumber = @CharUniqueNum	-- Race >= 16384 이면 케릭터 복구 정책으로 우선 저장.
		END

	SET @nNumCharacter = (SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000)

GO




--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetAllCharacterInfoByID
	@ID	VARCHAR(64)
AS
	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE td_Character.AccountName LIKE @ID AND 0 = Race & 0x4000	-- Race >= 16384 삭제된 케릭터
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetCharacter
	@acc	INT,
	@charac	INT
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool에서 여단명 변경 기능 추가 - 캐릭터 정보를 가져올때 td_Guild 테이블을 참조하여 업데이트한 이후에 가져온다
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_character c, td_guild g, td_guildMember gm WITH(NOLOCK) WHERE c.UniqueNumber = @charac AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_character c	WITH (NOLOCK)
		WHERE c.UniqueNumber = @charac
	END
	ELSE
	BEGIN
		UPDATE td_character
		SET GuildName = g.GuildName
		FROM td_character c, td_Guild g	WITH (NOLOCK)
		WHERE c.UniqueNumber = @charac AND c.GuildUniqueNumber = g.GuildUniqueNumber
	END

	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE UniqueNumber=@charac
	-- // 2007-07-30 by cmkwon, 위와 같이 CharacterUID로만 검색
	--WHERE UniqueNumber=@charac AND AccountUniqueNumber = @acc
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetAccountUniqueNumber
	@name varchar(64)
AS
	SELECT AccountUniqueNumber
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername LIKE @name
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetCharacterNumByName
	@name varchar(64)
AS
	SELECT UniqueNumber
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername LIKE @name
GO

--!!!!
-- Name:
-- Desc:
--		// 2007-07-31 by cmkwon, 인자 수정( <== @acc varchar(64), @charname varchar(64) ) - 쿼리를 like 사용을 하지 않는것으로 수정
--====
CREATE PROCEDURE dbo.atum_GetChatCharacterInfoByName
	@acc		varchar(20),
	@charname	varchar(20)
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool에서 여단명 변경 기능 추가 - 캐릭터 정보를 가져올때 td_Guild 테이블을 참조하여 업데이트한 이후에 가져온다
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_character c, td_guild g, td_guildMember gm WITH(NOLOCK) WHERE c.charactername = @charname AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_character c	WITH (NOLOCK)
		WHERE c.charactername = @charname
	END
	ELSE
	BEGIN
		UPDATE td_character
		SET GuildName = g.GuildName
		FROM td_character c, td_Guild g	WITH (NOLOCK)
		WHERE c.charactername = @charname AND c.GuildUniqueNumber = g.GuildUniqueNumber
	END

	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername = @charname AND accountname = @acc
GO

--!!!!
-- Name:
-- Desc:// 2007-07-31 by cmkwon, 추가함
--====
CREATE PROCEDURE dbo.atum_admin_GetCharacterByCharacterName
	@i_CharName	VARCHAR(20)
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool에서 여단명 변경 기능 추가 - 캐릭터 정보를 가져올때 td_Guild 테이블을 참조하여 업데이트한 이후에 가져온다
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_character c, td_guild g, td_guildMember gm WITH(NOLOCK) WHERE c.charactername = @i_CharName AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_character c	WITH (NOLOCK)
		WHERE c.charactername = @i_CharName
	END
	ELSE
	BEGIN
		UPDATE td_character
		SET GuildName = g.GuildName
		FROM td_character c, td_Guild g	WITH (NOLOCK)
		WHERE c.charactername = @i_CharName AND c.GuildUniqueNumber = g.GuildUniqueNumber
	END

	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername = @i_CharName
GO


--------------------------------------------------------------
-- 9.30. update stored procedures
--------------------------------------------------------------

--!!!!
-- Name:
-- Desc:
--		2006-04-10 by cmkwon, 파라미터 추가(@i_DownSPIOnDeath	INT,			-- 2006-04-10 by cmkwon)
--		2006-11-15 by cmkwon, 인자 2개 추가
--						@i_GameContinueTimeInSecondOfToday	INT,			-- 2006-11-15 by cmkwon, 오늘 하루 게임 진행 시간
--						@i_LastGameEndDate					VARCHAR(30)		-- 2006-11-15 by cmkwon, 마지막 게임 종료 날짜시간
--====
CREATE PROCEDURE dbo.atum_SaveCharacterCriticalData
	@i_CharacterUID		INT,
	@i_Level			TINYINT,
	@i_CharacterMode	TINYINT,
	@i_Experience		FLOAT,
	@i_DownExperience	FLOAT,
	@i_DownSPIOnDeath	INT,			-- 2006-04-10 by cmkwon
	@i_BodyCondition	BIGINT,
	@i_PetLevel			TINYINT,
	@i_PetExperience	FLOAT,
	@i_Position_X		FLOAT,
	@i_Position_Y		FLOAT,
	@i_Position_Z		FLOAT,
	@i_MapIndex			SMALLINT,
	@i_ChannelIndex		SMALLINT,
	@i_HP				SMALLINT,
	@i_DP				SMALLINT,
	@i_SP				SMALLINT,
	@i_EP				SMALLINT,
	@i_currentHP		FLOAT,
	@i_currentDP		FLOAT,
	@i_currentSP		SMALLINT,
	@i_currentEP		FLOAT,
	@i_totalPlayTime	BIGINT,
	@i_GameContinueTimeInSecondOfToday	INT,			-- 2006-11-15 by cmkwon, 오늘 하루 게임 진행 시간
	@i_LastGameEndDate					VARCHAR(30),	-- 2006-11-15 by cmkwon, 마지막 게임 종료 날짜시간
	@i_PCBangtotalPlayTime	BIGINT,						-- 2007-06-07 by dhjin, PC방 총 플레이 시간
	@i_SecretInfoOption		INT				-- // 2008-06-23 by dhjin, EP3 유저정보옵션
AS
	UPDATE td_Character
	SET	Level			= @i_Level,
		CharacterMode	= @i_CharacterMode,
		Experience		= @i_Experience,
		DownExperience	= @i_DownExperience,
		DownSPIOnDeath	= @i_DownSPIOnDeath,		-- 2006-04-10 by cmkwon
		BodyCondition	= @i_BodyCondition,
		PetLevel		= @i_PetLevel,
		PetExperience	= @i_PetExperience,
		Position_X		= @i_Position_X,
		Position_Y		= @i_Position_Y,
		Position_Z		= @i_Position_Z,
		MapIndex		= @i_MapIndex,
		ChannelIndex	= @i_ChannelIndex,
		HP				= @i_HP,
		DP				= @i_DP,
		SP				= @i_SP,
		EP				= @i_EP,
		currentHP		= @i_currentHP,
		currentDP		= @i_currentDP,
		currentSP		= @i_currentSP,
		currentEP		= @i_currentEP,
		TotalPlayTime	= @i_totalPlayTime,
		PCBangTotalPlayTime = @i_PCBangtotalPlayTime,
		SecretInfoOption	= @i_SecretInfoOption				-- // 2008-06-23 by dhjin, EP3 유저정보옵션
	WHERE UniqueNumber = @i_CharacterUID
	
	--------------------------------------------------------------------------------
	-- 2006-11-15 by cmkwon
	-- td_account 테이블에 게임지속시간, 마지막 게임 종료시간을 업데이트 한다.
	UPDATE td_Account
		SET GameContinueTimeInSecondOfToday = @i_GameContinueTimeInSecondOfToday,
			LastGameEndDate = @i_LastGameEndDate
		FROM td_Account a, td_character c
		WHERE c.UniqueNumber = @i_CharacterUID AND a.AccountUniqueNumber = c.AccountUniqueNumber

GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeUnitKind
	@UniqueNumber	int,
	@UnitKind		SMALLINT
AS
	UPDATE td_Character
		SET UnitKind = @UnitKind
		WHERE  UniqueNumber = @UniqueNumber;
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeStat
	@UniqueNumber	INT,
	@byAutoStatType	TINYINT,
	@AttackPart		SMALLINT,
	@DefensePart	SMALLINT,
	@FuelPart		SMALLINT,
	@SoulPart		SMALLINT,
	@ShieldPart		SMALLINT,
	@DodgePart		SMALLINT,
	@hp				SMALLINT,
	@dp				SMALLINT,
	@ep				SMALLINT,
	@sp				SMALLINT,
	@bstat			TINYINT
AS
	UPDATE td_Character
		SET AutoStatType = @byAutoStatType, AttackPart = @AttackPart, DefensePart = @DefensePart, FuelPart = @FuelPart,
			SoulPart = @SoulPart, ShieldPart = @ShieldPart, DodgePart = @DodgePart,
			HP = @hp, DP = @dp, EP = @ep, SP = @sp, BonusStat = @bstat
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc: 2005-11-15 by cmkwon, Level Up 이외의 방법으로 추가된 보너스 스탯 수치 변경 됨
--====
CREATE PROCEDURE dbo.atum_ChangeBonusStatPoint
	@UniqueNumber		INT,
	@BonusStatPoint		TINYINT
AS
	UPDATE td_Character
		SET BonusStatPoint = @BonusStatPoint
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
--CREATE PROCEDURE dbo.atum_ChangeGuild
--	@UniqueNumber	int,
--	@g		varchar(20),
--AS
--	UPDATE td_Character
--		SET GuildName = @g
--		WHERE  UniqueNumber = @UniqueNumber;
--GO


-- CREATE PROCEDURE dbo.atum_ChangeFriendGroup
-- 	@UniqueNumber	int,
-- 	@fg		varchar(30)
-- AS
-- UPDATE td_Character
-- 	SET FriendGroup = @fg
-- 	WHERE  UniqueNumber = @UniqueNumber;
-- GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeExp
	@UniqueNumber	INT,
	@exp			FLOAT
AS
	UPDATE td_Character
		SET Experience = @exp
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeLevel
	@UniqueNumber	INT,
	@level			TINYINT,
	@bstat			TINYINT
-- 2005-11-15 by cmkwon, BonusSkillPoint를 BonusStatPoint로 변경하면서 필요없어짐
--	@bskillpoint	TINYINT
AS
	UPDATE td_Character
		SET Level = @level, BonusStat = @bstat, LevelUpTime = GetDate()
		WHERE  UniqueNumber = @UniqueNumber;
-- 2005-11-15 by cmkwon, BonusSkillPoint를 BonusStatPoint로 변경하면서 필요없어짐
--		SET Level = @level, BonusStat = @bstat, BonusSkillPoint = @bskillpoint
--		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeBodyCondition
	@UniqueNumber	int,
	@bc				BIGINT
AS
	UPDATE td_Character
		SET BodyCondition = @bc
		WHERE  UniqueNumber = @UniqueNumber;
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangePropensity
	@UniqueNumber	INT,
	@Prop			INT
AS
	UPDATE td_Character
		SET Propensity = @Prop
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:세력선택시 세력이 변경된다.
--		2005-12-07 by cmkwon, 모든 캐릭터의 SelectableInfluenceMask도 업데이트 한다.
--====
CREATE PROCEDURE dbo.atum_ChangeInfluenceType
	@AccountUID					int,
	@CharacterUID				int,
	@InfluenceType				TINYINT,
	@SelectableInfluenceMask	TINYINT
AS
	UPDATE td_Character
		SET InfluenceType = @InfluenceType
		WHERE  UniqueNumber = @CharacterUID;
	
	UPDATE td_Character
		SET SelectableInfluenceMask = @SelectableInfluenceMask
		WHERE AccountUniqueNumber = @AccountUID
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeStatus
	@UniqueNumber	INT,
	@status			TINYINT
AS
	UPDATE td_Character
		SET Status = @status
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangePKPoint
	@UniqueNumber	INT,
	@Propensity		INT,
	@PKWinPoint		SMALLINT,
	@PKLossPoint	SMALLINT
AS
	UPDATE td_Character
		SET Propensity = @Propensity, PKWinPoint = @PKWinPoint, PKLossPoint = @PKLossPoint
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeRacingPoint
	@i_CharacterUID		INT,
	@i_RacingPoint		INT
AS
	UPDATE td_Character
		SET RacingPoint = @i_RacingPoint
		WHERE  UniqueNumber = @i_CharacterUID;
GO

--!!!!
-- Name: atum_ChangeHPDPSPEP
-- Desc: 
--====
CREATE PROCEDURE dbo.atum_ChangeHPDPSPEP
	@i_CharacterUID		INT,
	@i_HP				SMALLINT,
	@i_DP				SMALLINT,
	@i_SP				SMALLINT,
	@i_EP				SMALLINT,
	@i_CurrentHP		FLOAT,
	@i_CurrentDP		FLOAT,
	@i_CurrentSP		SMALLINT,
	@i_CurrentEP		FLOAT
AS
	UPDATE td_Character
		SET HP = @i_HP, DP = @i_DP, SP = @i_SP, EP = @i_EP,
			CurrentHP = @i_CurrentHP, CurrentDP = @i_CurrentDP, CurrentSP = @i_CurrentSP, CurrentEP = @i_CurrentEP
		WHERE  UniqueNumber = @i_CharacterUID;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeMapChannel
	@UniqueNumber	INT,
	@MapIndex		SMALLINT,
	@ChannelIndex	SMALLINT
AS
	UPDATE td_Character
		SET MapIndex = @MapIndex, ChannelIndex = @ChannelIndex
		WHERE  UniqueNumber = @UniqueNumber;
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangePetInfo
	@UniqueNumber	int,
	@level			TINYINT,
	@exp			FLOAT
AS
	UPDATE td_Character
		SET level = @level, experience=@exp
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangePosition
	@UniqueNumber	INT,
	@x			FLOAT,
	@y			FLOAT,
	@z			FLOAT
AS
	UPDATE td_Character
		SET Position_X=@x, Position_Y=@y, Position_Z=@z
		WHERE  UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_SaveLastPartyID
	@CharacterUniqueNumber	INT,
	@PartyID				BIGINT
AS
	UPDATE td_Character
		SET LastPartyID = @PartyID
		WHERE  UniqueNumber = @CharacterUniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateTotalPlayTime
	@i_CharacterUniqueNumber	INT,
	@i_TotalPlayTime			BIGINT
AS
	UPDATE td_Character
		SET TotalPlayTime = @i_TotalPlayTime
		WHERE  UniqueNumber = @i_CharacterUniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateLastStartedTime
	@CharacterUniqueNumber	INT
AS
	UPDATE td_Character
		SET LastStartedTime = GetDate()
		WHERE  UniqueNumber = @CharacterUniqueNumber
GO

-- CREATE PROCEDURE dbo.atum_ChangeDockingItem
-- 	@UniqueNumber	int,
-- 	@pw				int,
-- 	@sw				int,
-- 	@armor			int
-- AS
-- UPDATE td_Character
-- 	SET CurrentPrimaryWeapon=@pw, CurrentSecond=@sw, Armor=@armor
-- 	WHERE  UniqueNumber = @UniqueNumber;
-- GO



--------------------------------------------------------------
-- CHAT 관련
--------------------------------------------------------------

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_AuthChatLogin
	@acc			varchar(64),
	@pass			varchar(35)
AS
	SELECT AccountName
	FROM td_Account
	WITH (NOLOCK)
	WHERE AccountName LIKE @acc AND IsBlocked = 0 --AND Password LIKE @pass 
GO

--------------------------------------------------------------
-- ITEM 관련
--------------------------------------------------------------

--!!!!
-- Name:
-- Desc:
--		2005-12-07 by cmkwon, 저장위치
--====
CREATE PROCEDURE dbo.atum_GetStoreItem
	@accNum			INT,
	@possessNum		INT,
	@ItemStorage	TINYINT				-- 2005-12-07 by cmkwon,
AS
	SELECT *
	FROM td_Store
	WITH (NOLOCK)
	WHERE AccountUniqueNumber = @accNum AND Possess = @possessNum AND ItemStorage = @ItemStorage
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_DeleteStoreItem
	@accNum	INT,
	@uniqueNum BIGINT
AS
	DELETE FROM td_Enchant
		WHERE TargetItemUniqueNumber = @uniqueNum

	DELETE FROM td_Store
		WHERE AccountUniqueNumber = @accNum AND UniqueNumber = @uniqueNum;
GO

-- 2005-11-21 by cmkwon, 사용하지 않는 프로시저
--!!!!
-- Name:
-- Desc:
--====
--CREATE PROCEDURE dbo.atum_InsertStoreItem_DB
--	@accNum	INT,
--	@possess INT,
--	@wear	TINYINT,
--	@CurrentCount	INT,
--	@ScarcityNumber BIGINT,
--	@ItemWindowIndex	INT,
--	@ItemNum INT,
--	@PrefixCodeNum INT,
--	@SufficCodeNum INT
--AS
--	INSERT INTO td_Store
--		SELECT @accNum, @possess, @wear, @CurrentCount, @ScarcityNumber, @ItemWindowIndex,
--				@ItemNum, 0, @PrefixCodeNum, @SufficCodeNum, i.Endurance, 0, GetDate()
--		FROM ti_Item i
--		WHERE i.ItemNum = @ItemNum
--	RETURN SCOPE_IDENTITY();
--GO

--!!!!
-- Name:
-- Desc:
--		2005-12-07 by cmkwon, 저장위치 필드 추가
--====
CREATE PROCEDURE dbo.atum_InsertStoreItem
	@accNum				INT,
	@possess			INT,
	@ItemStorage		TINYINT,			-- 2005-12-07 by cmkwon
	@wear				TINYINT,
	@CurrentCount		INT,
	@ScarcityNumber		BIGINT,
	@ItemWindowIndex	INT,
	@ItemNum			INT,
	@NumOfEnchants		SMALLINT,
	@PrefixCodeNum		INT,
	@SufficCodeNum		INT,
	@CurrentEndurance	FLOAT,
	@ColorCode			INT,			-- 2005-11-21 by cmkwon, 아머 튜닝시 칼라값
	@UsingTimeStamp		INT
AS
	INSERT INTO td_Store
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ScarcityNumber, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, GetDate())
	RETURN SCOPE_IDENTITY();
GO

-- 2005-11-21 by cmkwon, 사용하지 않는 프로시저임
--!!!!
-- Name:
-- Desc:
--====
--CREATE PROCEDURE dbo.atum_MoveItemPossessCountable
--	@ret					BIGINT OUTPUT, -- 새로 삽입되었다면 uniquenumber, 아니면 -1
--	@accNum					INT,
--	@ToPossessCharacter		INT,	-- CharacterUniqueNumber OR 0
--	@ItemNum				INT,	-- 아이템의 종류
--	@ItemUniqueNumber		BIGINT,
--	@CurrentCount			INT,
--	@RemainedCount			INT
--AS
--	DECLARE @ToItemUniqueNumber	BIGINT	-- ToItem, 없으면 NULL
--	SET @ToItemUniqueNumber = (SELECT CurrentCount FROM td_Store
--								WHERE AccountUniqueNumber = @accNum AND Possess = @ToPossessCharacter AND ItemNum = @ItemNum)
--	IF (@ToItemUniqueNumber IS  NULL)
--		BEGIN
--			INSERT INTO td_Store
--				SELECT @accNum, @ToPossessCharacter, s.Wear, @CurrentCount, s.ScarcityNumber, 99,
--						s.ItemNum, 0, s.PrefixCodeNum, s.SuffixCodeNum, s.CurrentEndurance, 0, GetDate()
--				FROM td_Store s
--				WHERE s.UniqueNumber = @ItemUniqueNumber
--			SET @ret = SCOPE_IDENTITY()
--		END
--	ELSE
--		BEGIN
--			UPDATE td_Store
--			SET CurrentCount = CurrentCount + @CurrentCount
--			WHERE UniqueNumber = @ToItemUniqueNumber
--			SET @ret = -1
--		END
--
--	IF (@RemainedCount > 0)
--		BEGIN
--			UPDATE td_Store
--			SET CurrentCount = CurrentCount - @CurrentCount
--			WHERE UniqueNumber = @ItemUniqueNumber
--		END
--	ELSE
--		BEGIN
--			DELETE td_Store
--			WHERE 	UniqueNumber = @ItemUniqueNumber
--		END
--GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_MoveItemPossess
	@accNum					INT,
	@ToPossessCharacter		INT,	-- CharacterUniqueNumber OR 0
	@ItemUniqueNumber		BIGINT
AS
	UPDATE td_Store
	SET Possess = @ToPossessCharacter
	WHERE UniqueNumber = @ItemUniqueNumber
GO

-- 2005-12-07 by cmkwon, 필요없음
----!!!!
---- Name:
---- Desc:
--====
--CREATE PROCEDURE dbo.atum_UpdateItemPossess
--	@i_ItemUniqueNumber		BIGINT,
--	@i_ToPossess			INT		-- CharacterUniqueNumber OR 0
--AS
--	UPDATE td_Store
--	SET Possess = @i_ToPossess
--	WHERE UniqueNumber = @i_ItemUniqueNumber
--GO

--!!!!
-- Name:
-- Desc:	2005-12-07 by cmkwon, 아이템의 저장 위치 변경(캐릭터인벤->창고, 창고->캐릭터인벤)
--====
CREATE PROCEDURE dbo.atum_UpdateItemStorage
	@i_ItemUniqueNumber		BIGINT,
	@i_ItemCharacterUID     INT,		-- 2006-09-19 by dhjin, 선택된 케릭터
	@i_ItemStorage			TINYINT		-- 0(ITEM_IN_CHARACTER):캐릭터인벤, 1(ITEM_IN_STORE):창고
AS
	UPDATE td_Store
		SET ItemStorage = @i_ItemStorage, Possess = @i_ItemCharacterUID
		WHERE UniqueNumber = @i_ItemUniqueNumber
GO

-- 2005-11-21 by cmkwon, 사용하지 않는 프로시저
----!!!!
---- Name:
---- Desc:
--====
--CREATE PROCEDURE dbo.atum_LoadOneItem
--	@i_AccountUID		INT,
--	@i_CharacterUID		INT,
--	@i_ItemUID			BIGINT
--AS
--	SELECT *
--	FROM td_Store
--	WHERE AccountUniqueNumber = @i_AccountUID AND Possess = @i_CharacterUID AND UniqueNumber = @i_ItemUID
--
--	SELECT e.TargetItemUniqueNumber, e.TargetItemNum, e.EnchantItemNum
--	FROM td_enchant e, td_store i 
--	WHERE i.AccountUniqueNumber = @i_AccountUID AND i.possess = @i_CharacterUID
--			AND e.TargetItemUniqueNumber = i.UniqueNumber AND UniqueNumber = @i_ItemUID
--GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateItemCount
	@UniqueNumber	BIGINT,
	@CurrentCount	INT
AS
	UPDATE td_Store
	SET CurrentCount = @CurrentCount
	WHERE UniqueNumber = @UniqueNumber
GO


--!!!!
-- Name:
-- Desc:2006-06-14 by cmkwon, 추가함
--			다른것은 변경하지 않고 ItemNum만 수정한다. 레어,인챈트는 유지된다.
--====
CREATE PROCEDURE dbo.atum_UpdateItemNum
	@UniqueNumber	BIGINT,
	@ItemNum		INT
AS
	UPDATE td_store
		SET ItemNum = @ItemNum
		WHERE UniqueNumber = @UniqueNumber
GO


-- 2005-11-21 by cmkwon, 삭제함
----!!!!
---- Name:
---- Desc:
----====
--CREATE PROCEDURE dbo.atum_UpdateEndurance
--	@UniqueNumber	BIGINT,
--	@CurrentEndurance		FLOAT
--AS
--	UPDATE td_Store
--	SET CurrentEndurance = @CurrentEndurance
--	WHERE UniqueNumber = @UniqueNumber
--GO

--!!!!
-- Name:
-- Desc:2005-11-21 by cmkwon
--		아머 아이템의 칼라 텍스쳐 코드 업데이트
--====
CREATE PROCEDURE dbo.atum_StoreUpdateColorCode
	@UniqueNumber	BIGINT,
	@ColorCode		INT
AS
	UPDATE td_Store
	SET ColorCode = @ColorCode
	WHERE UniqueNumber = @UniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateItemUsingTimeStamp
	@UniqueNumber		BIGINT,
	@UsingTimeStamp		INT
AS
	UPDATE td_Store
	SET UsingTimeStamp = @UsingTimeStamp
	WHERE UniqueNumber = @UniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateItemRareFix
	@i_ItemUID			BIGINT,
	@i_PrefixCodeNum	INT,
	@i_SuffixCodeNum	INT
AS
	UPDATE td_Store
	SET PrefixCodeNum = @i_PrefixCodeNum, SuffixCodeNum = @i_SuffixCodeNum
	WHERE UniqueNumber = @i_ItemUID
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateItemWindowList
	@UniqueNumber	BIGINT,
	@Wear			TINYINT,
	@WndIdx			INT
AS
	UPDATE td_Store
	SET ItemWindowIndex = @WndIdx, Wear = @Wear
	WHERE UniqueNumber = @UniqueNumber;
GO

--!!!!
-- Name:
-- Desc:
--			2005-12-08 by cmkwon, 아머를 위한 colorcode도 가져온다.
--			2007-01-19, #define ITEM_IN_CHARACTER				0	// 캐릭터인벤
--						#define ITEM_IN_STORE					1	// 창고
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, 여단 창고 
--
--						#define POS_PROW						((BYTE)0)	// 레이더(선두 가운데)	--> 좌측 2번
--						#define POS_PROWIN						((BYTE)1)	// 컴퓨터(중앙 좌측)	--> 우측 2번
--						#define POS_PROWOUT						((BYTE)2)	// 1형 무기(선두 좌측)	--> 좌측 1번
--						#define POS_WINGIN						((BYTE)3)	// 2006-07-20 by cmkwon, 이펙트 아이템 (중앙 위쪽)
--						#define POS_WINGOUT						((BYTE)4)	// 2형 무기(선두 우측)	--> 우측 1번
--						#define POS_CENTER						((BYTE)5)	// 아머(중앙 가운데)	--> 좌측 4번
--						#define POS_REAR						((BYTE)6)	// 엔진(후미 가운데)	--> 우측 3번
--						#define POS_ATTACHMENT					((BYTE)7)	// 2006-03-30 by cmkwon, 무제한 악세사리 - 부착물(후미 우측-연료탱크|컨테이너계열) --> 좌측 3번
--						#define POS_PET							((BYTE)8)	// 2006-03-30 by cmkwon, 시간제한 악세사리(후미 좌측)	--> 우측 4번
--====
CREATE PROCEDURE dbo.atum_GetAttachedItems
	@Possess		INT
AS
	SELECT ItemWindowIndex, ItemNum, ColorCode
	FROM td_Store
	WITH (NOLOCK)
	WHERE ItemStorage = 0 AND possess = @Possess AND itemwindowindex >= 0 AND itemwindowindex <= 9
GO

--------------------------------------------------------------
-- td_Enchant 관련
--------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_InsertEnchant
	@i_TargetItemUniqueNumber	BIGINT,
	@i_TargetItemNum			INT,
	@i_EnchantItemNum			INT
AS
	INSERT INTO td_Enchant
	VALUES (@i_TargetItemUniqueNumber, @i_TargetItemNum, @i_EnchantItemNum)
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_DeleteAllEnchant
	@i_TargetItemUniqueNumber	BIGINT
AS
	DELETE FROM td_Enchant
		WHERE TargetItemUniqueNumber = @i_TargetItemUniqueNumber
GO


-- 2007-01-30 by cmkwon, 필요 없어서 주석 처리함 - atum_GetEnchantBYItemUID() 프로시저로 대체함
----!!!!
---- Name:
---- Desc:
----====
--CREATE PROCEDURE dbo.atum_GetAllEnchant
--	@i_AccountUniqueNumber		INT,
--	@i_CharacterUniqueNumber	INT
--AS
--	SELECT e.TargetItemUniqueNumber, e.TargetItemNum, e.EnchantItemNum
--	FROM td_Enchant e, td_Store i
--	WITH (NOLOCK)
--	WHERE i.AccountUniqueNumber = @i_AccountUniqueNumber AND i.possess = @i_CharacterUniqueNumber
--			AND e.TargetItemUniqueNumber = i.UniqueNumber
--GO
--


--------------------------------------------------------------
-- Quest 관련
--------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetAllQuest
	@CharacterUniqueNumber	INT
AS
	SELECT *
	FROM td_CharacterQuest
	WITH (NOLOCK)
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
--			// 2007-11-16 by cmkwon, 테이블 Unique Key 설정한 것 데이터 추가시 체크 후에 추가 - td_characterQuest
CREATE PROCEDURE dbo.atum_InsertQuest
	@i_CharacterUniqueNumber	INT,
	@i_QuestIndex				INT,
	@i_QuestState				TINYINT,
	@i_QuestParam1				INT,
	@i_QuestTimeStamp			VARCHAR(50),
	@i_QuestPlayTimeStamp		BIGINT
AS
	DECLARE @QuestIdx INT
	SET @QuestIdx = (SELECT QuestIndex FROM td_CharacterQuest WHERE CharacterUniqueNumber = @i_CharacterUniqueNumber AND QuestIndex = @i_QuestIndex)
	IF @QuestIdx IS NULL
	BEGIN 
		INSERT INTO td_CharacterQuest
		VALUES (@i_CharacterUniqueNumber, @i_QuestIndex, @i_QuestState, @i_QuestParam1, @i_QuestTimeStamp, @i_QuestPlayTimeStamp)
	END
	ELSE
	BEGIN
		UPDATE td_CharacterQuest
		SET QuestState = @i_QuestState, QuestParam1 = @i_QuestParam1, QuestTimeStamp = @i_QuestTimeStamp, QuestPlayTimeStamp = @i_QuestPlayTimeStamp
		WHERE CharacterUniqueNumber = @i_CharacterUniqueNumber AND QuestIndex = @i_QuestIndex
	END
	
GO

--!!!!
-- Name:
-- Desc:
--		2006-08-31 by cmkwon, @i_QuestPlayTimeStamp		BIGINT
--====
CREATE PROCEDURE dbo.atum_UpdateQuestState
	@CharacterUniqueNumber	INT,
	@QuestIndex				INT,
	@QuestState				TINYINT,
	@i_QuestPlayTimeStamp		BIGINT		-- 2006-08-31 by cmkwon, 추가함
AS
	UPDATE td_CharacterQuest
	SET QuestState = @QuestState, QuestPlayTimeStamp = @i_QuestPlayTimeStamp
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_DeleteQuest
	@CharacterUniqueNumber	INT,
	@QuestIndex				INT
AS
	DELETE FROM td_CharacterQuest
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO

-----------------------------------------------------------------------------
-- 2005-10-19 by cmkwon, 퀘스트 몬스터 카운팅 관련

--!!!!
-- Name:
-- Desc:캐릭터의 모든 몬스터 카운트를 검색한다.
--====
CREATE PROCEDURE dbo.atum_GetAllQuestMonsterCount
	@CharacterUniqueNumber		INT
AS
	SELECT *
	FROM td_CharacterQuestMonsterCount
	WITH (NOLOCK)
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber
GO

--!!!!
-- Name:
-- Desc:퀘스트 몬스터 카운트의 추가 혹은 수정
--====
CREATE PROCEDURE dbo.atum_UpdateQuestMonsterCount
	@CharacterUniqueNumber		INT,
	@QuestIndex					INT,
	@MonsterUniqueNumber		INT,
	@Count						INT
AS
	DECLARE @nCurCount INT
	SET @nCurCount = (SELECT top 1 Count FROM td_CharacterQuestMonsterCount 
						WITH (NOLOCK) WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex AND MonsterUniqueNumber = @MonsterUniqueNumber)
	IF (@nCurCount IS NULL)
		BEGIN
			INSERT INTO td_CharacterQuestMonsterCount
			VALUES (@CharacterUniqueNumber, @QuestIndex, @MonsterUniqueNumber, @Count)
		END
	ELSE IF (@Count <= @nCurCount)
		BEGIN
			UPDATE td_CharacterQuestMonsterCount
			SET Count = @nCurCount + 1
			WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex AND MonsterUniqueNumber = @MonsterUniqueNumber
		END
	ELSE
		BEGIN
			UPDATE td_CharacterQuestMonsterCount
			SET Count = @Count
			WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex AND MonsterUniqueNumber = @MonsterUniqueNumber
		END
GO

--!!!!
-- Name:
-- Desc:퀘스트 몬스터 카운트 삭제
--====
CREATE PROCEDURE dbo.atum_DeleteQuestMonsterCount
	@CharacterUniqueNumber		INT,
	@QuestIndex					INT
AS
	DELETE FROM td_CharacterQuestMonsterCount
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO


-- End_퀘스트 몬스터 카운팅 관련
-----------------------------------------------------------------------------


--------------------------------------------------------------
-- SKILL 관련
--------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetStoreItemSkill
	@accNum	INT,
	@possessNum INT
AS
	SELECT UniqueNumber, AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime
	FROM td_StoreSkill
	WITH (NOLOCK)
	WHERE AccountUniqueNumber = @accNum AND Possess = @possessNum
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_DeleteStoreItemSkill
	@accNum	INT,
	@uniqueNum BIGINT
AS
	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND UniqueNumber = @uniqueNum;
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_InsertStoreItemSkill
	@accNum			INT,
	@possess		INT,
	@ItemWindowIndex	INT,
	@ItemNum		INT
AS
	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND Possess = @possess AND (ItemNum/10)*10 = (@ItemNum/10)*10

	INSERT INTO td_StoreSkill
	VALUES (@accNum, @possess, @ItemWindowIndex, @ItemNum, GetDate(), NULL)

	RETURN SCOPE_IDENTITY();

GO


--!!!!
-- Name:
-- Desc:
--			2007-01-19, #define ITEM_IN_CHARACTER				0	// 캐릭터인벤
--						#define ITEM_IN_STORE					1	// 창고
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, 여단 창고 
--====
CREATE PROCEDURE dbo.atum_DeleteAllCharacterItems
	@i_AccountUID INT,
	@i_CharacterUID INT
AS
	IF (@i_CharacterUID = 0)
		RETURN

	-- 1. 캐릭터 소유 아이템의 인챈트 제거	
	DELETE td_Enchant FROM td_Enchant e, td_Store s 
		WHERE s.AccountUniqueNumber = @i_AccountUID AND s.ItemStorage <> 2 AND s.Possess = @i_CharacterUID AND s.UniqueNumber = e.TargetItemUniqueNumber
	
	-- 2. 캐릭터 소유 아이템 제거
	DELETE FROM td_Store WHERE AccountUniqueNumber = @i_AccountUID AND ItemStorage <> 2 AND possess = @i_CharacterUID
	
	-- 3. 캐릭터 퀵 슬롯 제거
	DELETE FROM td_QuickSlot WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
	
	-- 4. 캐릭터 소유 스킬 제거
	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber = @i_AccountUID AND possess = @i_CharacterUID
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeCurrentHPDPSPEP
	@UniqueNumber		INT,
	@hp					FLOAT,
	@dp					FLOAT,
	@sp					SMALLINT,
	@ep					FLOAT
AS
	UPDATE td_Character
		SET CurrentHP = @hp, CurrentDP = @dp, CurrentSP=@sp, CurrentEP=@ep
		WHERE  UniqueNumber = @UniqueNumber;
GO


--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_ChangeWindowPosition
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_ItemUID1				BIGINT,
	@i_ItemWindowIndex1		INT,
	@i_ItemWear1			TINYINT,
	@i_ItemUID2				BIGINT,
	@i_ItemWindowIndex2		INT,
	@i_ItemWear2			TINYINT
AS
UPDATE td_store
	SET		ItemWindowIndex = @i_ItemWindowIndex1, Wear = @i_ItemWear1
	WHERE	UniqueNumber = @i_ItemUID1 AND Possess = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
UPDATE td_store
	SET		ItemWindowIndex = @i_ItemWindowIndex2, Wear = @i_ItemWear2
	WHERE	UniqueNumber = @i_ItemUID2 AND Possess = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetBuildingNPC
	@MapIndex	SMALLINT
AS
	SELECT *
	FROM ti_BuildingNPC WITH (NOLOCK)	
	WHERE MapIndex = @MapIndex OR MapIndex = 0
GO

-- 2006-10-20 by cmkwon, 사용하지 않는 프로시저, 아래의 두개의 프로시저 두개를 기능을 나눔
----!!!!
---- Name:
---- Desc:
----====
--CREATE PROCEDURE dbo.atum_GetAllShopItems
--	@MapIndex SMALLINT
--AS
--	SELECT b.BuildingIndex, i.itemnum, itemname, i.MinTradeQuantity, i.price, kind
--	FROM ti_Item i, ti_Shop s, ti_BuildingNPC b
--	WHERE i.itemnum = s.itemnum AND b.BuildingIndex = s.uniquenumber AND (b.MapIndex = @MapIndex OR b.MapIndex = 0)
--	order by b.BuildingIndex
--GO

--!!!!
-- Name:
-- Desc:2006-10-20 by cmkwon, 맵의 모든 BuildingIndex를 가져오기
--====
CREATE PROCEDURE dbo.atum_GetAllBuildingIndex
	@MapIndex SMALLINT
AS
	SELECT BuildingIndex
		FROM ti_BuildingNPC WITH (NOLOCK)
		WHERE MapIndex = @MapIndex OR MapIndex = 0
GO

--!!!!
-- Name:
-- Desc:2006-10-20 by cmkwon, BuildingIndex의 아이템 가져오기
--		// 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder 순으로 상점 아이템 리스트를 가져온다.
--====
CREATE PROCEDURE dbo.atum_GetShopItems
	@BuildingIndex INT
AS
	-- // 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder 순으로 상점 아이템 리스트를 가져온다.
	SELECT i.itemnum, i.itemname, i.MinTradeQuantity, i.price, i.kind
		FROM ti_Item i WITH(NOLOCK), ti_Shop s WITH(NOLOCK)
		WHERE i.itemnum = s.itemnum AND @buildingIndex = s.uniquenumber
		ORDER BY s.ShopOrder
GO


-- 2005-11-21 by cmkwon, 사용하지 않는 프로시저
--!!!!
-- Name:
-- Desc:
--====
--CREATE PROCEDURE dbo.atum_InsertStoreItem_DB_AND_UpdateCount
--	@accNum	INT,
--	@possess INT,
--	@wear	TINYINT,
--	@CurrentCount	INT,
--	@ScarcityNumber BIGINT,
--	@ItemWindowIndex	INT,
--	@ItemNum INT,
--	@PrefixCodeNum INT,
--	@SufficCodeNum INT,
--	@CurrentEndurance FLOAT,
--	@ItemUniqueNumber	BIGINT,
--	@ItemCount	INT
--AS
--	UPDATE td_Store
--	SET CurrentCount = @ItemCount
--	WHERE UniqueNumber = @ItemUniqueNumber;
--
--	INSERT INTO td_Store
--		SELECT @accNum, @possess, @wear, @CurrentCount, @ScarcityNumber, @ItemWindowIndex,
--				@ItemNum, 0, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, 0, GetDate()
--		FROM ti_Item i
--		WHERE i.ItemNum = @ItemNum
--
--	RETURN SCOPE_IDENTITY();
--GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_InsertStoreItemSkill_DB_AND_UpdateCount
	@accNum	INT,
	@possess INT,
	@ItemWindowIndex	INT,
	@ItemNum INT,
	@ItemUniqueNumber	BIGINT,	-- Money
	@ItemCount	INT				-- Money
AS
	UPDATE td_Store
	SET CurrentCount = @ItemCount
	WHERE UniqueNumber = @ItemUniqueNumber

	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND Possess = @possess AND (ItemNum/10)*10 = (@ItemNum/10)*10

	INSERT INTO td_StoreSkill
		SELECT @accNum, @possess, @ItemWindowIndex, @ItemNum, GetDate(), NULL
		FROM ti_Item i WITH (NOLOCK)
		WHERE i.ItemNum = @ItemNum

	RETURN SCOPE_IDENTITY();
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_UpdateStoreItemCount_AND_UpdateMoney
	@ItemUniqueNumber		BIGINT,
	@ItemCount				INT,
	@MoneyItemUniqueNumber	BIGINT,
	@MoneyItemCount			INT
AS
	UPDATE td_Store
	SET CurrentCount = @MoneyItemCount
	WHERE UniqueNumber = @MoneyItemUniqueNumber;

	UPDATE td_Store
	SET CurrentCount = @ItemCount
	WHERE UniqueNumber = @ItemUniqueNumber;
GO



--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_DeleteStoreItem_AND_UpdateMoney
	@ItemUniqueNumber		BIGINT,
	@MoneyItemUniqueNumber	BIGINT,
	@MoneyItemCount			INT
AS
	UPDATE td_Store
	SET CurrentCount = @MoneyItemCount
	WHERE UniqueNumber = @MoneyItemUniqueNumber;

	DELETE FROM td_Store
	WHERE UniqueNumber = @ItemUniqueNumber
GO

--------------------------------------------------------------------------------
-- 아이템 Trade
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_TradeMoveItem
	@ToCharacter			INT,
	@ToAccount				INT,
	@FromCharacter			INT,
	@ItemUniqueNumber		BIGINT			-- 2006-05-11 by cmkwon, INT를 수정함
AS
	UPDATE td_Store
		SET AccountUniqueNumber = @ToAccount, Possess = @ToCharacter, Wear = 0, ItemWindowIndex = 99
		WHERE UniqueNumber = @ItemUniqueNumber AND Possess = @FromCharacter
GO


--!!!!
-- Name:
-- Desc:유저간 거래시 카운터블 아이템 처리
--		2005-11-21 by cmkwon, ColorCode는 아머에만 사용되므로 거래시 0으로 설정한다.
--====
CREATE PROCEDURE dbo.atum_TradeMoveItemCountable
	@ToCharacter			INT,
	@ToAccount				INT,
	@FromCharacter			INT,
	@FromItemUniqueNumber	BIGINT,
	@Amount					INT,		-- 거래량
	@RemainedCount			INT,		-- 주는 아이템의 남은 양
	@ToItemUniqueNumber		BIGINT OUTPUT,		-- 0: 받는 쪽이 같은 아이템이 없음, else: 받는 쪽에 아이템이 존재함(받는 아이템 고유번호)
	@FromItemNum			INT			-- spi인지 아닌지 확인해서, spi이면 남은 양이 0이더라도 지우지 않는다!
AS

	-- 아이템을 받는 쪽 처리
	IF (@ToItemUniqueNumber = 0)
	BEGIN
		-- 받을 캐릭터가 해당 아이템을 소지하지 않은 경우
		INSERT INTO td_Store
			SELECT @ToAccount, @ToCharacter, 0, 0, @Amount, s.ScarcityNumber, 100,
						s.ItemNum, 0, s.PrefixCodeNum, s.SuffixCodeNum, s.CurrentEndurance, 0, 0, GetDate()
			FROM td_Store s
			WHERE s.UniqueNumber = @FromItemUniqueNumber AND s.Possess = @FromCharacter

		SET @ToItemUniqueNumber = SCOPE_IDENTITY()
	END
	ELSE
	BEGIN
		-- 받을 캐릭터가 해당 아이템을 이미 소지한 경우
		UPDATE td_Store
			SET CurrentCount = CurrentCount + @Amount
			WHERE UniqueNumber = @ToItemUniqueNumber AND Possess = @ToCharacter
	END

	-- 아이템을 주는 쪽 처리
	IF (@RemainedCount > 0 OR @FromItemNum = 7000022)
	BEGIN -- 단독 statement가 아닐 때 사용, 여기서는 에러 방지를 위해 미리 사용함
		UPDATE td_Store
		SET CurrentCount = @RemainedCount
		WHERE UniqueNumber = @FromItemUniqueNumber AND Possess = @FromCharacter
	END
	ELSE
	BEGIN
		DELETE td_Store
		WHERE  UniqueNumber = @FromItemUniqueNumber AND Possess = @FromCharacter
	END

GO


--------------------------------------------------------------------------------
-- GUILD
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====	2005-12-27 by cmkwon, td_Guild에 필드 두개 추가한것 적용
--		// 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 필드 추가(GuildMarkState)
--			#define GUILD_MARK_STATE_NONE					((BYTE)0)	// 마크 없는 상태
--			#define GUILD_MARK_STATE_WAITING_PERMISSION		((BYTE)1)	// 마크 허용을 기다리는 상태, 게임상에서는 사용 불가
--			#define GUILD_MARK_STATE_NORMAL					((BYTE)2)	// 마크 사용 중인 상태
--DROP PROCEDURE atum_CreateGuild
--GO
CREATE PROCEDURE dbo.atum_CreateGuild
	@name			VARCHAR(30),
	@commander		INT,
	@capacity		INT
AS
	-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항, // 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 필드 추가(GuildMarkState)
	INSERT INTO td_Guild VALUES (@name, @commander, @capacity, 0, NULL, 0, 0, NULL, 0, 0, 0, 0, 0, NULL, 0, 0, 0)
	RETURN SCOPE_IDENTITY();
GO

--!!!!
-- Name:
-- Desc:
--====
--DROP PROCEDURE atum_InsertGuildMember
--GO
CREATE PROCEDURE dbo.atum_InsertGuildMember
	@guildUniqueNum		INT,	-- UINT
	@characUniqueNum	INT,	-- UINT
	@guildRank			TINYINT
AS
	-- 길드원 삽입
	INSERT INTO td_GuildMember VALUES(@guildUniqueNum, @characUniqueNum, @guildRank, GetDate())
	
	DECLARE @GuildName VARCHAR(30)
	SET @GuildName = (SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNum)

	-- 캐릭터의 길드 정보 업데이트
	UPDATE td_Character
	SET GuildName = @guildName, GuildUniqueNumber = @guildUniqueNum
	WHERE UniqueNumber = @characUniqueNum
GO

--!!!!
-- Name:
-- Desc:
--====
--DROP PROCEDURE atum_DeleteGuildMember
--GO
CREATE PROCEDURE dbo.atum_DeleteGuildMember
	@characUniqueNum	INT		-- UINT
AS
	-- 길드원에서 제거
	DELETE td_GuildMember WHERE characterUniqueNumber = @characUniqueNum

	-- 캐릭터의 길드 정보 제거
	UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		WHERE uniquenumber = @characUniqueNum
GO

--!!!!
-- Name:
-- Desc:
--		// 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 필드명으로 결과 검색 처리하며 필드 추가됨
--====
--DROP PROCEDURE atum_GetGuildInfoByUniqueNumber
--GO
CREATE PROCEDURE dbo.atum_GetGuildInfoByUniqueNumber
	@guildUniqueNum		INT	-- UINT
AS
	SELECT g.GuildUniqueNumber, g.GuildName, g.GuildCommanderUniqueNumber, g.GuildMemberCapacity, g.GuildState, g.GuildDismemberDate,
			g.GuildMarkVersion, g.GuildMarkSize, g.GuildMarkImage, g.WarWinPoint, g.WarLossPoint, g.TotalFame, g.MonthlyFame,
			g.GuildMarkState, g.Notice, o.OutPostCityMapIndex, g.GuildTotalFameRank, g.GuildMonthlyFameRank
	FROM td_Guild AS g WITH (NOLOCK) Left outer join td_outpostinfo AS o WITH (NOLOCK)
		ON g.GuildUniqueNumber = o.outpostGuilduid
		WHERE GuildUniqueNumber = @guildUniqueNum
GO


--!!!!
-- Name:
-- Desc:
--====
--DROP PROCEDURE atum_SaveGuildWarPoint
--GO
CREATE PROCEDURE dbo.atum_SaveGuildWarPoint
	@i_GuildUniqueNumber	INT,	-- UINT
	@i_WarWinPoint			INT,
	@i_WarLossPoint			INT
AS
	UPDATE td_Guild
		SET WarWinPoint = @i_WarWinPoint, WarLossPoint = @i_WarLossPoint
		WHERE GuildUniqueNumber = @i_GuildUniqueNumber
GO

--!!!!
-- Name:
-- Desc:
--====
--DROP PROCEDURE atum_GetAllGuildMembers
--GO
CREATE PROCEDURE dbo.atum_GetAllGuildMembers
	@guildUniqueNum		INT	-- UINT
AS
	-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
	SELECT c.CharacterName, c.UniqueNumber, gm.GuildRank, c.UnitKind, c.Level
	FROM td_Character c, td_GuildMember gm
	WHERE c.UniqueNumber = gm.CharacterUniqueNumber AND gm.GuildUniqueNumber = @guildUniqueNum
GO



--!!!!
-- Name: atum_Guild_UpdateMemberCapacity
-- Desc: 길드 제한 인원 수정
--====
--DROP PROCEDURE atum_Guild_UpdateMemberCapacity
--GO
CREATE PROCEDURE dbo.atum_Guild_UpdateMemberCapacity
	@guildUniqueNum				INT,		-- UINT
	@MemberCapacity				INT,		--
	@GuildMemberCardCashPrice	INT
AS
	UPDATE td_Guild
		SET GuildMemberCapacity = @MemberCapacity, GuildMemberCardCashPrice = GuildMemberCardCashPrice + @GuildMemberCardCashPrice
		WHERE GuildUniqueNumber = @guildUniqueNum
GO

--!!!!
-- Name: atum_SetDismemberDate
-- Desc: 길드 해산 요청시 길드의 상태(해산대기) 설정 및 해산 날짜 설정
--====
--DROP PROCEDURE atum_SetDismemberDate
--GO
CREATE PROCEDURE dbo.atum_SetDismemberDate
	@guildUniqueNum		INT		-- UINT
AS
	DECLARE @dismemberDate DATETIME
	SET @dismemberDate = GetDate()
	SET @dismemberDate = dateadd(day, 7, @dismemberDate)

	UPDATE td_Guild
	SET GuildDismemberDate = @dismemberDate , GuildState = 1
	WHERE GuildUniqueNumber = @guildUniqueNum

	-- // 2008-06-13 by dhjin, EP3 - 여단 수정 사항
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @guildUniqueNum
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @guildUniqueNum
GO


--!!!!
-- Name: atum_CancelDismember
-- Desc: 길드 해산 취소
--====
--DROP PROCEDURE atum_CancelDismember
--GO
CREATE PROCEDURE dbo.atum_CancelDismember
	@guildUniqueNum		INT		-- UINT
AS
	UPDATE td_Guild
	SET GuildDismemberDate = NULL, GuildState = 0
	WHERE GuildUniqueNumber = @guildUniqueNum
GO

--!!!!
-- Name: atum_DismemberGuild
-- Desc: 길드 완전 삭제
--====
--DROP PROCEDURE atum_DismemberGuild
--GO
CREATE PROCEDURE dbo.atum_DismemberGuild
	@guildUniqueNum		INT	-- UINT
AS
	-- 길드 삭제
	DELETE FROM td_Guild WHERE GuildUniqueNumber = @guildUniqueNum

	-- 길드원 삭제
	DELETE FROM td_GuildMember WHERE GuildUniqueNumber = @guildUniqueNum
	
	-- 2007-11-02 by jin, 지도자 후보이면 삭제
	DELETE FROM td_LeaderCandidate WHERE GuildUID = @guildUniqueNum

	-- 캐릭터 정보 삭제
	UPDATE td_Character
	SET guildname = NULL, guilduniquenumber = 0
	WHERE guilduniquenumber = @guildUniqueNum

	-- // 2008-06-13 by dhjin, EP3 - 여단 수정 사항
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @guildUniqueNum
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @guildUniqueNum
GO

--!!!!
-- Name: atum_ChangeGuildRank
-- Desc: 길드 계급 변경
--====
--DROP PROCEDURE atum_ChangeGuildRank
--GO
CREATE PROCEDURE dbo.atum_ChangeGuildRank
	@memberUniqueNumber		INT,	-- UINT
	@rank					TINYINT
AS
	UPDATE td_GuildMember
	SET GuildRank = @rank
	WHERE CharacterUniqueNumber = @memberUniqueNumber
GO

--!!!!
-- Name: atum_ChangeGuildName
-- Desc: 길드 이름 변경
--====
--DROP PROCEDURE atum_ChangeGuildName
--GO
CREATE PROCEDURE dbo.atum_ChangeGuildName
	@guildUniqueNumber		INT,	-- UINT
	@guildName				VARCHAR(30)
AS
	UPDATE td_Guild
	SET GuildName = @guildName
	WHERE GuildUniqueNumber = @guildUniqueNumber
GO

-- Name: atum_GetGuildMark
-- Desc: 길드 마크 가져오기
--====
--DROP PROCEDURE atum_GetGuildMark
--GO
CREATE PROCEDURE dbo.atum_GetGuildMark
	@guildUniqueNumber		INT	-- UINT
AS
	SELECT GuildMarkVersion, GuildMarkSize, GuildMarkImage
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildUniqueNumber = @guildUniqueNumber
GO

-- Name: atum_SetGuildMark
-- Desc: 길드 마크 할당
--====
--			// 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 인자추가(@i_guildMarkState		TINYINT)
--DROP PROCEDURE atum_SetGuildMark
--GO
CREATE PROCEDURE dbo.atum_SetGuildMark
	@guildUniqueNumber		INT,	-- UINT
	@guildMarkSize			INT,
	@guildMarkImage			BINARY(1600),
	@i_guildMarkState		TINYINT			-- // 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 인자추가(@i_guildMarkState		TINYINT)
AS
	DECLARE @GuildMarkVersion INT
	SET @GuildMarkVersion = (SELECT GuildMarkVersion FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNumber) + 1

	-- // 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - Update에 추가함
	UPDATE td_Guild
	SET GuildMarkVersion = @GuildMarkVersion, GuildMarkSize = @guildMarkSize, GuildMarkImage = @guildMarkImage, GuildMarkState= @i_guildMarkState
	WHERE GuildUniqueNumber = @guildUniqueNumber
	
	RETURN @GuildMarkVersion
GO

-- Name: atum_GuildAddGuildFame
-- Desc: 2005-12-28 by cmkwon, 여단 명성 더하기
--====
CREATE PROCEDURE dbo.atum_GuildAddGuildFame
	@i_guildUID				INT,	-- UINT
	@i_totalFameAddition	INT,	-- 추가량
	@i_monthlyFameAddition	INT
AS
	UPDATE td_Guild
		SET TotalFame= TotalFame+@i_totalFameAddition, MonthlyFame= MonthlyFame+@i_monthlyFameAddition
		WHERE GuildUniqueNumber = @i_guildUID
	
	SELECT TotalFame, MonthlyFame
		FROM td_Guild WITH (NOLOCK)
		WHERE GuildUniqueNumber = @i_guildUID		
GO

-- Name: atumManager_DoMonthlyWork_ProcessMontylyGuildFame
-- Desc: 2006-01-02 by cmkwon, 매달 처리하는 일 - 여단 한달 누적 명성 처리
--			한달 여단 명성 10순위까지 검색
--			최고 여단 명성 여단장에게 14-소장성 계급 설정하기(기존 소장성은 0-훈련 에어맵으로 설정, 자동 재설정됨)
--====
CREATE PROCEDURE dbo.atumManager_DoMonthlyWork_ProcessMontylyGuildFame
AS
	-- 한달 여단 명성 10순위까지 검색
	SELECT TOP 10 g.GuildName, g.GuildUniqueNumber as GuildUID, c.CharacterName as GuildMasterCharacterName
				, g.GuildCommanderUniqueNumber as GuildMasterCharacterUID, g.TotalFame, g.MonthlyFame
		FROM td_Guild g, td_character c WITH (NOLOCK)
		WHERE g.GuildCommanderUniqueNumber = c.uniquenumber
		ORDER BY MonthlyFame desc
	
	-- 기존 계급이 14(소장성) 유저의 계급을 0(훈련 에어맨)으로 설정
	UPDATE td_Character
		SET Status = 0
		WHERE Status = 14

	-- 한달 여단 명성 최고 여단장에게 계급 14(소장성)을 설정
	DECLARE @GuildMasterCharUID INT
	SET @GuildMasterCharUID = (SELECT TOP 1 GuildCommanderUniqueNumber FROM td_Guild WITH (NOLOCK) ORDER BY MonthlyFame desc)
	UPDATE td_Character
		SET Status = 14
		WHERE UniqueNumber = @GuildMasterCharUID
GO

-- Name: atumManager_DoMonthlyWork_ResetMontylyGuildFame
-- Desc: 2006-01-02 by cmkwon, 매달 처리하는 일 - 여단 한달 누적 명성 초기화
--====
CREATE PROCEDURE dbo.atumManager_DoMonthlyWork_ResetMontylyGuildFame
AS
	UPDATE td_Guild
		SET MonthlyFame = 0
GO

--------------------------------------------------------------------------------
-- GUILDWAR
--------------------------------------------------------------------------------
-- Name: atum_InsertRequestForGuildWar
-- Desc: 길드전 신청 삽입
-- Returns: 신청 순위, 0 이하이면 실패
--====
--DROP PROCEDURE atum_InsertRequestForGuildWar
--GO
CREATE PROCEDURE dbo.atum_InsertRequestForGuildWar
	@i_MapIndex				SMALLINT,
	@i_DefenderGuildName	VARCHAR(30),
	@i_ChallengerGuildName	VARCHAR(30)
AS
	DECLARE @DefenderGuildUNUM INT
	DECLARE @ChallengerGuildUNUM INT

	SET @DefenderGuildUNUM = (SELECT TOP 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildName like @i_DefenderGuildName)
	SET @ChallengerGuildUNUM = (SELECT TOP 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildName like @i_ChallengerGuildName)

	IF (@DefenderGuildUNUM IS NULL OR @ChallengerGuildUNUM IS NULL)
		RETURN 0

	INSERT INTO td_GuildWar(MapIndex, DefenderGuildUniqueNumber, ChallengerGuildUniqueNumber)
	VALUES (@i_MapIndex, @DefenderGuildUNUM, @ChallengerGuildUNUM)
	
	IF (@@ERROR <> 0)
		RETURN 0

	RETURN (SELECT count(*) FROM td_GuildWar WITH (NOLOCK)
			WHERE MapIndex = @i_MapIndex AND DefenderGuildUniqueNumber = @DefenderGuildUNUM)
GO

--------------------------------------------------------------------------------
-- FRIEND LIST
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_FriendInsertFriend
	@i_CharacterName				VARCHAR(20),
	@i_FriendName					VARCHAR(20),
	@i_Type							TINYINT,
	@i_RegDate						VARCHAR(30)			-- // 2008-04-11 by dhjin, EP3 거부목록 -
AS
	INSERT INTO td_FriendList
	VALUES (@i_CharacterName, @i_FriendName, @i_Type, @i_RegDate)
GO

CREATE PROCEDURE dbo.atum_FriendDeleteFriend
	@i_CharacterName				VARCHAR(64),
	@i_FriendName					VARCHAR(64),
	@i_Type							TINYINT
AS
	DELETE FROM td_FriendList
	WHERE CharacterName like @i_CharacterName AND FriendName like @i_FriendName AND Type = @i_Type
GO

CREATE PROCEDURE dbo.atum_FriendLoadFriends
	@i_CharacterName				VARCHAR(64)
AS
	SELECT *
	FROM td_FriendList WITH (NOLOCK)
	WHERE CharacterName like @i_CharacterName
GO

-- 2005-11-21 by cmkwon, Auction은 사용하지 않으므로 주석 처리함
----------------------------------------------------------------------------------
---- AUCTION, 물품 대행 상점
----------------------------------------------------------------------------------
--
----!!!!
---- Name: atum_AuctionGetRegisterCount
-- Desc: 물품 대행 상점에 아이템 등록
--====
--CREATE PROCEDURE dbo.atum_AuctionGetRegisterCount
--	@i_CharacterUID			INT
--AS
--	SELECT count(*)
--	FROM td_Auction
--	WHERE AuctionCharacterUID = @i_CharacterUID
--GO
--
----!!!!
---- Name: atum_AuctionRegisterItem
---- Desc: 물품 대행 상점에 아이템 등록
----====
--CREATE PROCEDURE dbo.atum_AuctionRegisterItem
--	@i_AuctionItemKind				TINYINT,	-- 아이템 종류, AtumProtocol.h의 AUCTION_KIND_XXX 참고
--	@i_AuctionPrice					INT,		-- 경매가
--	@i_AuctionItemUID				BIGINT,		-- 아이템 고유 번호, td_Store.UniqueNumber
--	@i_AuctionAccountUID			INT,		-- 소유 Account 인덱스, td_Store.AccountUniqueNumber
--	@i_AuctionCharacterUID			INT,		-- 소유 캐릭터 인덱스, td_Store.Possess
--	@i_SellerName					VARCHAR(20)
--AS
--	INSERT INTO td_Auction
--		SELECT @i_AuctionItemKind, @i_AuctionPrice, GetDate(), 0, @i_SellerName,
--				ItemNum, UniqueNumber, AccountUniqueNumber, Possess,
--				CurrentCount, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance
--		FROM td_Store
--		WHERE UniqueNumber = @i_AuctionItemUID AND AccountUniqueNumber = @i_AuctionAccountUID AND Possess = @i_AuctionCharacterUID
--
--	UPDATE td_Store
--	SET Possess = -1
--	WHERE UniqueNumber = @i_AuctionItemUID AND AccountUniqueNumber = @i_AuctionAccountUID AND Possess = @i_AuctionCharacterUID
--GO
--
----!!!!
---- Name: atum_AuctionCancelItem
---- Desc: 물품 대행 상점에 아이템 등록 취소
----====
--CREATE PROCEDURE dbo.atum_AuctionCancelItem
--	@i_ItemUID				BIGINT,		-- 아이템 고유 번호, td_Store.UniqueNumber
--	@i_AccountUID			INT,		-- 소유 Account 인덱스, td_Store.AccountUniqueNumber
--	@i_CharacterUID			INT			-- 소유 캐릭터 인덱스, td_Store.Possess
--AS
--	UPDATE td_Store
--	SET Possess = @i_CharacterUID
--	WHERE UniqueNumber = @i_ItemUID AND AccountUniqueNumber = @i_AccountUID AND Possess = -1
--
--	DELETE FROM td_Auction
--	WHERE AuctionItemUID = @i_ItemUID AND AuctionAccountUID = @i_AccountUID AND AuctionCharacterUID = @i_CharacterUID
--GO
--
----!!!!
---- Name: atum_AuctionGetMyItem
---- Desc: 물품 대행 상점에 등록된 자신의 아이템을 반환
----====
--CREATE PROCEDURE dbo.atum_AuctionGetMyItem
--	@i_CharacterUID			INT			-- 소유 캐릭터 인덱스, td_Store.Possess
--AS
--	SELECT *
--	FROM td_Auction a
--	WHERE a.AuctionCharacterUID = @i_CharacterUID
--	
--	SELECT e.*
--	FROM td_Auction a, td_Enchant e
--	WHERE a.AuctionCharacterUID = @i_CharacterUID AND e.TargetItemUniqueNumber = a.AuctionItemUID
--GO
--
----!!!!
---- Name: atum_AuctionGetKindItem
---- Desc: 물품 대행 상점에 등록된 종류별 아이템을 반환
----====
--CREATE PROCEDURE dbo.atum_AuctionGetKindItem
--	@i_AuctionItemKind		TINYINT		-- 아이템 종류, AtumProtocol.h의 AUCTION_KIND_XXX 참고
--AS
--	SELECT *
--	FROM td_Auction a
--	WHERE a.AuctionItemKind = @i_AuctionItemKind
--
--	SELECT e.*
--	FROM td_Auction a, td_Enchant e
--	WHERE a.AuctionItemKind = @i_AuctionItemKind AND e.TargetItemUniqueNumber = a.AuctionItemUID
--GO
--
----!!!!
---- Name: atum_AuctionBuyItem
---- Desc: 물품 대행 상점에 등록된 아이템구매
----       구매자에게 아이템 넘김, 판매자의 창고에 돈 삽입
----       구매자의 돈 제거는 따로 해 주어야 함
----====
--CREATE PROCEDURE dbo.atum_AuctionBuyItem
--	@i_AuctionItemUID					BIGINT,	-- 아이템
--	@i_AuctionSellerAccountUID			INT,	-- 판매자의 Account UID
--	@i_AuctionSellerCharacterUID		INT,	-- 판매자의 Character UID
--	@i_AuctionBuyerAccountUID			INT,	-- 구매자의 Account UID
--	@i_AuctionBuyerCharacterUID			INT		-- 구매자의 Character UID
--AS
--	DECLARE @tmpItemPrice	INT
--	SET @tmpItemPrice = (SELECT TOP 1 AuctionPrice FROM td_Auction WHERE AuctionItemUID = @i_AuctionItemUID)
--
--	-- 아이템이 없으면 return
--	IF (@tmpItemPrice IS NULL) RETURN 0
--
--	-- 창고 아이템 제거
--	DELETE FROM td_Auction WHERE AuctionItemUID = @i_AuctionItemUID
--
--	-- 아이템의 소유권 이전
--	UPDATE td_Store
--	SET Possess = @i_AuctionBuyerCharacterUID, AccountUniqueNumber = @i_AuctionBuyerAccountUID
--	WHERE UniqueNumber = @i_AuctionItemUID
--
--	-- 판매자의 돈 업데이트
--	IF (SELECT count(*) FROM td_Store WHERE ItemNum = 7000022 AND Possess = 0 AND AccountUniqueNumber = @i_AuctionSellerAccountUID) >= 1
--		BEGIN
--			-- 창고에 돈 아이템이 있는 경우
--			UPDATE td_Store
--			SET CurrentCount = CurrentCount + @tmpItemPrice
--			WHERE ItemNum = 7000022 AND Possess = 0 AND AccountUniqueNumber = @i_AuctionSellerAccountUID
--		END
--	ELSE
--		BEGIN
--			-- 창고에 돈 아이템이 없는 경우
--			EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @i_AuctionSellerCharacterUID, 7000022, @tmpItemPrice
--		END
--
--	RETURN 1
--GO

-- // 2008-02-13 by cmkwon, 계정 삭제 시스템 만들기 - 사용하지 않는 프로시저
------------------------------------------------------------------------------------
---- MGAME - 유저 삭제
----------------------------------------------------------------------------------
--CREATE PROCEDURE dbo.Pb_Delete_Character
--	@strUserId char(20)        -- 엠게임회원아이디
--AS
--	DECLARE @AccountUID INT
--	DECLARE @CharacterUID INT
--	SET @AccountUID = (SELECT top 1 AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE AccountName = @strUserId)
--	SET @CharacterUID = (SELECT top 1 UniqueNumber FROM td_Character WITH (NOLOCK) WHERE AccountName = @strUserId)
--
--	IF (@AccountUID IS NULL) RETURN
--
--	-- 인챈트 제거
--	DELETE td_Enchant
--		FROM td_Enchant e, td_Store s
--		WHERE s.UniqueNumber = e.TargetItemUniqueNumber AND s.AccountUniqueNumber = @AccountUID
--
--	-- 아이템 제거
--	DELETE FROM td_Store WHERE AccountUniqueNumber = @AccountUID
--	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber = @AccountUID
--
--	-- 길드장일때 처리
--	DECLARE @GuildUID	INT
--	SET @GuildUID = (SELECT top 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildCommanderUniqueNumber = @CharacterUID)
--	IF (@GuildUID IS NOT NULL)
--		BEGIN
--			UPDATE td_Character
--			SET GuildName='', GuildUniqueNumber=0
--			WHERE GuildUniqueNumber=@GuildUID
--			
--			-- 길드 멤버에서 제거	
--			DELETE td_GuildMember
--			FROM td_GuildMember
--			WHERE GuildUniqueNumber=@GuildUID
--		END
--	ELSE
--		BEGIN 
--			-- 길드 멤버에서 제거	
--			DELETE td_GuildMember
--			FROM td_GuildMember
--			WHERE CharacterUniqueNumber = @CharacterUID
--		END
--
--	-- 퀘스트에서 제거
--	DELETE td_CharacterQuest
--		FROM td_CharacterQuest q, td_Character c
--		WHERE c.UniqueNumber = q.CharacterUniqueNumber AND c.AccountUniqueNumber = @AccountUID
--
--	-- 캐릭터에서 제거
--	DELETE FROM td_Character WHERE AccountUniqueNumber = @AccountUID
--GO
--

-------------------------------
-- 더미 캐릭터 생성
-------------------------------
-------------------------------
-- I-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_I
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from td_Account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	INSERT INTO td_Character
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate(), 0, 0, 0, 0, 0, 0	-- 2006-12-18 by dhjin
		FROM td_Character
		WHERE CharacterName = 'I기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- 아머 - 바인더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO

-------------------------------
-- A-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_A
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from td_Account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	INSERT INTO td_Character
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate(), 0, 0, 0, 0, 0, 0	-- 2006-12-18 by dhjin
		FROM td_Character
		WHERE CharacterName = 'A기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2형 무기 - 가드
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- 미키 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- 아머 - 가더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO

-------------------------------
-- B-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_B
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from td_Account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	INSERT INTO td_Character
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate(), 0, 0, 0, 0, 0, 0	-- 2006-12-18 by dhjin
		FROM td_Character
		WHERE CharacterName = 'B기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- 아머 - 베일 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO

-------------------------------
-- M-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character 테이블에 DownSPIOnDeath 필드 추가
--		2007-01-24 by cmkwon, 프로시저 용도 수정 - 'M기어' 캐릭터를 가지고 캐릭터를 추가하는 프로시저
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_M
	@i_AccName		VARCHAR(20),		-- 생성 계정
	@i_CharName		VARCHAR(20)			-- 생성 캐릭터명
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from td_Account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	INSERT INTO td_Character
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate(), 0, 0, 0, 0, 0, 0	-- 2006-12-18 by dhjin
		FROM td_Character
		WHERE CharacterName = 'M기어'

	-- 기본 아이템 삽입
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2형 무기
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- 엔진
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- 기본 레이다
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- 아머 - 디펜더 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- 돈 삽입

GO

-------------------------------
-- 로그 서버용 procedures
-------------------------------

--!!!!
-- Name: atum_log_insert_connection
-- Desc: inserts connection log
--====
--		2006-09-14 by cmkwon, Add Parameter - @i_ServerGroupID INT
--		// 2007-11-06 by cmkwon, 게임 로그 DB 서버 따로 구축하기 - atum_Update_ConnectingServerGroupID_Of_Account() 프로시저로 처리
--
CREATE PROCEDURE dbo.atum_log_insert_connection
	@i_LogType					TINYINT,
	@i_IPAddress				BINARY(4),
	@i_AccountUniqueNumber		INT,
	@i_AccountName				VARCHAR(20),
	@i_ServerName				VARCHAR(20),
	@i_ServerGroupID			INT				-- 2006-09-14 by cmkwon, 추가함
AS
	INSERT INTO atum_log_connection
	VALUES (@i_LogType, GetDate(), @i_IPAddress,
			@i_AccountUniqueNumber, @i_AccountName, @i_ServerName)

	-- // 2007-11-06 by cmkwon, 게임 로그 DB 서버 따로 구축하기 - atum_Update_ConnectingServerGroupID_Of_Account() 프로시저로 처리
	---- 2006-09-14 by cmkwon
	---- 로그인시(0 == @i_LogType)	==> ConnectingServerGroupID에 @i_ServerGroupID를 설정한다
	---- 로그아웃시(0 <> @i_LogType)	==> ConnectingServerGroupID에 0를 설정한다
	--IF (0 = @i_LogType)
	--	BEGIN
	--		UPDATE td_account
	--			SET ConnectingServerGroupID = @i_ServerGroupID
	--			WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	--	END
	--ELSE
	--	BEGIN
	--		UPDATE td_account
	--			SET ConnectingServerGroupID = 0
	--			WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	--	END
GO

--!!!!
-- Name: atum_log_insert_user_level_stat
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_user_level_stat
--GO
CREATE PROCEDURE dbo.atum_log_insert_user_level_stat
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_Param1					SMALLINT,
	@i_Param2					SMALLINT,
	@i_Param3					BIGINT
AS
	INSERT INTO atum_log_user_level_stat
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1, @i_Param2, @i_Param3)
GO

--!!!!
-- Name: atum_log_insert_user_exp
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_exp
--GO
CREATE PROCEDURE dbo.atum_log_insert_exp
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_Param1					FLOAT,
	@i_Param2					BIGINT
AS
	INSERT INTO atum_log_user_exp
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1, @i_Param2)
GO

--!!!!
-- Name: atum_log_insert_user_game_start_end
-- Desc: inserts log
--			2006-12-18 by cmkwon, 인자 추가(@i_PCBangPlayTime INT)
--====
CREATE PROCEDURE dbo.atum_log_insert_user_game_start_end
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_CharacterName			VARCHAR(20),
	@i_AccountUniqueNumber		INT,			-- UINT
	@i_AccountName				VARCHAR(20),
	@i_PlayTime					INT,
	@i_TotalPlayTime			BIGINT,
	@i_PCBangPlayTime			INT,				-- 2006-12-18 by cmkwon, 
	@i_PCBangUID				INT					-- 2007-01-24 by dhjin
AS
	INSERT INTO atum_log_user_game_start_end
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_CharacterName, @i_AccountUniqueNumber, @i_AccountName, @i_PlayTime, @i_TotalPlayTime, @i_PCBangPlayTime, @i_PCBangUID)
GO

--!!!!
-- Name: atum_log_insert_user_quest_pk_dead
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_user_quest_pk_dead
--GO
CREATE PROCEDURE dbo.atum_log_insert_user_quest_pk_dead
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_Param1					INT
AS
	INSERT INTO atum_log_user_quest_pk_dead
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1)
GO

--!!!!
-- Name: atum_log_insert_user_warp
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_user_warp
--GO
CREATE PROCEDURE dbo.atum_log_insert_user_warp
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_TargetMapIndex			SMALLINT,
	@i_TargetPosition_X			SMALLINT,
	@i_TargetPosition_Y			SMALLINT,
	@i_TargetPosition_Z			SMALLINT
AS
	INSERT INTO atum_log_user_warp
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_TargetMapIndex, @i_TargetPosition_X, @i_TargetPosition_Y, @i_TargetPosition_Z)
GO

--!!!!
-- Name: atum_log_insert_user_speed_hack
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_user_speed_hack
--GO
CREATE PROCEDURE dbo.atum_log_insert_user_speed_hack
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_CheckType				TINYINT,
 	@i_ReceivedMoveCounts		INT,
 	@i_EngineItemNum			INT,	
	@i_ServerPastTime			INT,
	@i_ClientPastTime			INT,
	@i_PastDistance				INT,
 	@i_CurrentSpeed				INT
AS
	INSERT INTO atum_log_user_speed_hack
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex, @i_Position_X,
			@i_Position_Y, @i_Position_Z, @i_CheckType, @i_ReceivedMoveCounts, @i_EngineItemNum,
			@i_ServerPastTime, @i_ClientPastTime, @i_PastDistance, @i_CurrentSpeed)
GO

--!!!!
-- Name: atum_log_insert_user_memory_hack
-- Desc: 2005-12-20 by cmkwon
--			inserts log
--====

CREATE PROCEDURE dbo.atum_log_insert_user_memory_hack
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_Position_X				SMALLINT,
	@i_Position_Y				SMALLINT,
	@i_Position_Z				SMALLINT,
	@i_ItemKind					INT,
 	@i_ItemNum					INT,
 	@i_ItemUniqueNumber			BIGINT,
 	@i_MemoryHackCheckType		INT,	
	@i_ValidValue				FLOAT,
	@i_CurrentValue				FLOAT,
	@i_Param1					INT
AS
	INSERT INTO atum_log_user_memory_hack
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex, @i_Position_X,
			@i_Position_Y, @i_Position_Z, @i_ItemKind, @i_ItemNum, @i_ItemUniqueNumber,
			@i_MemoryHackCheckType, @i_ValidValue, @i_CurrentValue, @i_Param1)
GO


--!!!!
-- Name: atum_log_insert_item_charac_use
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_item_charac_use
--GO
CREATE PROCEDURE dbo.atum_log_insert_item_charac_use
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_ItemUniqueNumber			BIGINT,
	@i_ItemNum					INT,
	@i_CurrentCount				INT,
	@i_Param1					INT
AS
	INSERT INTO atum_log_item_charac_use
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount, @i_Param1)
GO

--!!!!
-- Name: atum_log_insert_item_get_throw
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_item_get_throw
--GO
CREATE PROCEDURE dbo.atum_log_insert_item_get_throw
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_ItemUniqueNumber			BIGINT,
	@i_ItemNum					INT,
	@i_CurrentCount				INT,
	@i_ChangeCount				INT
AS
	INSERT INTO atum_log_item_get_throw
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount)
GO

--!!!!
-- Name: atum_log_insert_item_buy_sell
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_item_buy_sell
--GO
CREATE PROCEDURE dbo.atum_log_insert_item_buy_sell
	@i_LogType					TINYINT,
	@i_CharacterUniqueNumber	INT,
	@i_MapIndex					SMALLINT,
	@i_ItemUniqueNumber			BIGINT,
	@i_ItemNum					INT,
	@i_CurrentCount				INT,
	@i_ChangeCount				INT,
	@i_RemainedMoney			INT
AS
	INSERT INTO atum_log_item_buy_sell
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount, @i_RemainedMoney)
GO

--!!!!
-- Name: atum_log_insert_item_trade
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_item_trade
--GO
CREATE PROCEDURE dbo.atum_log_insert_item_trade
	@i_LogType						TINYINT,
	@i_CharacterUniqueNumber		INT,
	@i_MapIndex						SMALLINT,
	@i_ItemUniqueNumber				BIGINT,
	@i_ItemNum						INT,
	@i_CurrentCount					INT,
	@i_ChangeCount					INT,
	@i_PeerCharacterName			VARCHAR(20),
	@i_PeerCharacterUniqueNumber	INT				-- UINT
AS
	INSERT INTO atum_log_item_trade
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount, @i_PeerCharacterName, @i_PeerCharacterUniqueNumber)
GO

--!!!!
-- Name: atum_log_insert_server_map
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_server_map
--GO
CREATE PROCEDURE dbo.atum_log_insert_server_map
	@i_LogType						TINYINT,
	@i_MapIndex						SMALLINT,
	@i_ChannelIndex					SMALLINT,
	@i_ClientCount					INT,
	@i_MonsterCount					INT,
	@i_MGameServerID				INT
AS
	INSERT INTO atum_log_server_map
	VALUES (@i_LogType, GetDate(), @i_MapIndex, @i_ChannelIndex,
			@i_ClientCount, @i_MonsterCount, @i_MGameServerID)
GO

--!!!!
-- Name: atum_log_insert_monster_boss
-- Desc: inserts log
--====
--DROP PROCEDURE atum_log_insert_monster_boss
--GO
CREATE PROCEDURE dbo.atum_log_insert_monster_boss
	@i_LogType					TINYINT,
	@i_MapIndex					SMALLINT,
	@i_ChannelIndex				SMALLINT,
 	@i_MonsterUnitKind			INT,		-- 생성 몬스터 정보
 	@i_CreatedTime				VARCHAR(30),
 	@i_DeadTime					VARCHAR(30),
 	@i_AttackUser1				VARCHAR(20),
 	@i_AttackUser2				VARCHAR(20),
 	@i_AttackUser3				VARCHAR(20),
 	@i_AttackUser4				VARCHAR(20),
 	@i_AttackUser5				VARCHAR(20),
 	@i_AttackUser6				VARCHAR(20),
 	@i_AttackUser7				VARCHAR(20),
 	@i_AttackUser8				VARCHAR(20),
 	@i_AttackUser9				VARCHAR(20),
 	@i_AttackUser10				VARCHAR(20),
 	@i_DropItemList				VARCHAR(200),
 	@i_MGameServerID			INT
AS
	INSERT INTO atum_log_monster_boss
	VALUES (@i_LogType, GetDate(), @i_MapIndex, @i_ChannelIndex,
			@i_MonsterUnitKind, @i_CreatedTime, @i_DeadTime, @i_AttackUser1, @i_AttackUser2,
			@i_AttackUser3, @i_AttackUser4, @i_AttackUser5, @i_AttackUser6, @i_AttackUser7,
			@i_AttackUser8, @i_AttackUser9, @i_AttackUser10, @i_DropItemList, @i_MGameServerID)
GO

--!!!!
-- Name: mgame_server_stat
-- Desc: mgame 통계용
--====
--DROP PROCEDURE atum_server_stat_for_mgame
--GO
CREATE PROCEDURE dbo.atum_server_stat_for_mgame
AS
	SELECT TOP 1 ClientCount
	FROM atum_log_server_map
	WHERE MapIndex = 0
	ORDER BY Time DESC
GO

-------------------------------------------------------------------------------
-- 엠게임 접속자 체크 프로시져
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_GAMELOGIN
	@strClientID	VARCHAR(20),		-- User ID  <<  MGame ID
	@strIPAddr		VARCHAR(16), 		-- User IP Address
	@nGameID		INT					-- GameSvr ID

AS
	--exec [pubaccount].[dbo].PB_GAMELOGIN @strClientID, @strIPAddr, @nGameID
GO

-- 접속자 체크 프로시져
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_GAMELOGOUT
	@strClientID	VARCHAR(20)			-- User ID  <<  MGame ID
AS
	--exec [pubaccount].[dbo].PB_GAMELOGOUT @strClientID
GO


-- 접속자 체크 초기화 프로시져
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_INIT
	@nGameID int		-- GameSvr ID
AS
	--exec [pubaccount].[dbo].PB_INIT @nGameID

	-- 2007-01-29 by cmkwon, ServerGroupID 초기화
	UPDATE td_Account 
	SET ConnectingServerGroupID = 0
	WHERE ConnectingServerGroupID = @nGameID
GO
-- end_엠게임 접속자 체크 프로시져
-------------------------------------------------------------------------------


--/*
-------------------------------------------------------------------------------
-- 유료 아이템(일반프리미엄, 슈퍼 프리미엄) 관련 프로시저

-- 2005-01-20 by cmkwon, 유저의 유료 아이템을 가져온다
CREATE PROCEDURE dbo.atum_GetAccountCashStoreItem
	@i_accNum		INT					-- AccountUniqueNumber
AS
	SELECT * FROM td_accountCashStore WITH (NOLOCK)
		WHERE AccountUniqueNumber = @i_accNum
GO

-- 2005-01-20 by cmkwon, Cash 카드를 추가
CREATE PROCEDURE dbo.atum_insert_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber
	@i_ItemNum			INT,				-- 추가 할 ItemNum
	@i_CurTime			VARCHAR(30),		-- 현재 시간
	@i_ExpireTime		VARCHAR(30)			-- 사용 종료 시간
AS
	DECLARE @RetUniqueNum	BIGINT
	SET @RetUniqueNum = (SELECT uniqueNumber FROM td_accountCashStore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NOT NULL)
	BEGIN
		RETURN 0
	END
	
	INSERT INTO td_accountCashStore
		VALUES (@i_accNum, @i_ItemNum, @i_CurTime, @i_CurTime, @i_ExpireTime)
	
	SET @RetUniqueNum = (SELECT uniqueNumber FROM td_accountCashStore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NULL)
	BEGIN
		RETURN 0
	END
	
	RETURN @RetUniqueNum
GO

-- 2005-01-20 by cmkwon, Cash 카드 정보를 Update
CREATE PROCEDURE dbo.atum_update_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber	
	@i_ItemNum			INT,				-- 찾은 데이타에 설정할 ItemNum	
	@i_CurTime			VARCHAR(30),		-- 현재 시간
	@i_ExpireTime		VARCHAR(30)			-- 사용 종료 시간
AS
	DECLARE @RetUniqueNum	BIGINT
	SET @RetUniqueNum = (SELECT uniqueNumber FROM td_accountCashStore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NULL)
	BEGIN
		RETURN 0
	END
	
	UPDATE td_accountCashStore
		SET ItemNum = @i_ItemNum, UpdatedTime = @i_CurTime, ExpireTime = @i_ExpireTime
		WHERE uniqueNumber = @RetUniqueNum
			
	RETURN @RetUniqueNum
GO

-- 2005-01-20 by cmkwon, Cash 카드 정보를 삭제한다
CREATE PROCEDURE dbo.atum_delete_AccountCashStoreItem
	@i_accNum			INT				-- AccountUniqueNumber
AS
	DELETE FROM td_accountCashStore
		WHERE AccountUniqueNumber = @i_accNum
GO

-- end_유료 아이템(일반프리미엄, 슈퍼 프리미엄) 관련 프로시저
-------------------------------------------------------------------------------






-------------------------------------------------------------------------------
-- 도시점령전 관련 프로시저

-- 2005-02-04 by cmkwon, MapIndex와 MGameServerID를 가지고 점령정보를 로딩
CREATE PROCEDURE dbo.atum_CityWar_LoadingOccupyInfo
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT					-- 도시점령전이 발생한 서버군채널 ID
AS
	SELECT OccupyGuildUID, OccupyGuildName, OccupyGuildMasterCharUID, Tex
		, CityWarDefaultTime, CityWarSettingTime, DefenseCounts, SumOfTex, Briefing 
		FROM td_OccupyInfo WITH (NOLOCK) WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
GO

-- 2005-02-04 by cmkwon, 여단의 유효성을 체크한다
CREATE PROCEDURE dbo.atum_CityWar_CheckGuildAndGuildMaster
	@i_GuildUID					INT,				-- 여단UID
	@i_GuildMasterCharUID		INT					-- 여단장 CharacterUID
AS
	DECLARE @guildUID INT
	SET @guildUID = (SELECT g.GuildUniqueNumber
						FROM td_Guild g, td_Character c
						WHERE c.UniqueNumber = @i_GuildMasterCharUID AND c.GuildUniqueNumber = g.GuildUniqueNumber
							AND g.GuildCommanderUniqueNumber = @i_GuildMasterCharUID)
	IF (@guildUID IS NULL)	RETURN 0
	ELSE					RETURN 1
GO

-- 2005-02-04 by cmkwon, 여단의 유효성을 체크한다
CREATE PROCEDURE dbo.atum_CityWar_LoaingCityWarGuildList
	@i_CityWarQuestIndex		INT,				-- Quest Index
	@i_MGameServerID			INT					-- 도시점령전이 발생한 서버군채널 ID
AS
	SELECT g.GuildUniqueNumber, g.GuildName, g.GuildCommanderUniqueNumber
		FROM td_Guild g, td_CharacterQuest q
		WHERE q.QuestIndex = @i_CityWarQuestIndex AND q.QuestParam1 = @i_MGameServerID
			AND g.GuildCommanderUniqueNumber = q.CharacterUniqueNumber
GO

-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreOccupyInfo
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_OccupyGuildUID				INT,				-- 점령여단UID
	@i_OccupyGuildName				VARCHAR(30),		-- 점령여단명
	@i_OccupyGuildMasterCharUID		INT,				-- 점령여단장 CharacterUID
	@i_Tex							FLOAT,				-- 상점 이용 Tex Percent
	@i_CityWarDefaultTime			VARCHAR(30),		-- 다음 도시점령전 기본시간
	@i_CityWarSettingTime			VARCHAR(30),		-- 다음 도시점령전 설정시간(기본시간부터 12시 이후 시간까지가능)
	@i_DefenseCounts				INT,				-- 방어 카운트
	@i_SumOfTex						INT,				-- 하루 동안의
	@i_Briefing						VARCHAR(100)		-- 상점 이용시 인사말
AS
	DECLARE @searchMapIndex INT
	SET @searchMapIndex = (SELECT MapIndex FROM td_OccupyInfo WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID)
	IF (@searchMapIndex IS NULL)
		BEGIN
			INSERT INTO td_OccupyInfo
				VALUES (@i_MapIndex, @i_MGameServerID, @i_OccupyGuildUID, @i_OccupyGuildName, @i_OccupyGuildMasterCharUID, @i_Tex, @i_CityWarDefaultTime, @i_CityWarSettingTime, @i_DefenseCounts, @i_SumOfTex, @i_Briefing)
		END
	ELSE
		BEGIN
			UPDATE td_OccupyInfo
				SET OccupyGuildUID = @i_OccupyGuildUID, OccupyGuildName = @i_OccupyGuildName, OccupyGuildMasterCharUID = @i_OccupyGuildMasterCharUID
					, Tex = @i_Tex, CityWarDefaultTime = @i_CityWarDefaultTime, CityWarSettingTime = @i_CityWarSettingTime
					, DefenseCounts = @i_DefenseCounts, SumOfTex = @i_SumOfTex, Briefing = @i_Briefing
				WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
		END	
GO

-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreTexPercent
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_Tex							FLOAT				-- 상점 이용 Tex Percent
AS
	DECLARE @searchMapIndex INT
	SET @searchMapIndex = (SELECT MapIndex FROM td_OccupyInfo WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID)
	IF (@searchMapIndex IS NOT NULL)
		BEGIN
			UPDATE td_OccupyInfo
				SET Tex = @i_Tex
				WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
		END	
GO

-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreWarTime
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_CityWarDefaultTime			VARCHAR(30),		-- 다음 도시점령전 기본시간
	@i_CityWarSettingTime			VARCHAR(30)			-- 다음 도시점령전 설정시간(기본시간부터 12시 이후 시간까지가능)	
AS
	DECLARE @searchMapIndex INT
	SET @searchMapIndex = (SELECT MapIndex FROM td_OccupyInfo WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID)
	IF (@searchMapIndex IS NOT NULL)
		BEGIN
			UPDATE td_OccupyInfo
				SET CityWarDefaultTime = @i_CityWarDefaultTime, CityWarSettingTime = @i_CityWarSettingTime
				WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
		END	
GO


-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreSumOfTex
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_SumOfTex						INT					-- 하루 동안의	
AS
	DECLARE @searchMapIndex INT
	SET @searchMapIndex = (SELECT MapIndex FROM td_OccupyInfo WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID)
	IF (@searchMapIndex IS NOT NULL)
		BEGIN
			UPDATE td_OccupyInfo
				SET SumOfTex = @i_SumOfTex
				WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
		END	
GO

-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreBriefing
	@i_MapIndex						INT,				-- 도시점령전 맵인덱스
	@i_MGameServerID				INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_Briefing						VARCHAR(100)		-- 상점 이용시 인사말
AS
	DECLARE @searchMapIndex INT
	SET @searchMapIndex = (SELECT MapIndex FROM td_OccupyInfo WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID)
	IF (@searchMapIndex IS NOT NULL)
		BEGIN
			UPDATE td_OccupyInfo
				SET Briefing = @i_Briefing
				WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
		END	
GO
-- end_도시점령전 관련 프로시저
-------------------------------------------------------------------------------


--!!!!
-- Name: atum_UpdateInfluenceWarData
-- Desc: 2006-04-14 by cmkwon, 
--====
CREATE PROCEDURE dbo.atum_UpdateInfluenceWarData
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,				-- 도시점령전이 발생한 서버군채널 ID
	@i_WartimeStage				TINYINT,
	@i_ContributionPoint		INT					-- 
AS
	UPDATE td_InfluenceWarData
		SET WartimeStage = @i_WartimeStage, ContributionPoint = @i_ContributionPoint
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
GO


--!!!!
-- Name: atum_UpdateOwnerOfConflictArea
-- Desc: 2006-07-12 by cmkwon, 
--====
CREATE PROCEDURE dbo.atum_UpdateOwnerOfConflictArea
	@i_InfluenceType			TINYINT,			-- 분쟁지역 소유 세력
	@i_MGameServerID			INT					-- 도시점령전이 발생한 서버군채널 ID
AS
	-- 다른 세력은 소유 필드를 0으로 설정한다
	UPDATE td_InfluenceWarData
		SET OwnerOfConflictArea = 0
		WHERE InfluenceType <> @i_InfluenceType and MGameServerID = @i_MGameServerID

	-- 분쟁 지역 세력의 소유 필드를 1로 설정한다.
	UPDATE td_InfluenceWarData
		SET OwnerOfConflictArea = 1
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
GO


-- 2006-07-25 by cmkwon, atum_GameLog_BackUp 프로시저로 수정함
---------------------------------------------------------------------------------
---- 2005-02-25 by cmkwon, Log 테이블 정리하기 프로시저
----		: atum_log_X 테이블명을 atum_backup_log_X 테이블명으로 변경한다
------		: atum_log_type_info 테이블은 제외
--CREATE PROCEDURE dbo.atum_Log_Rename_GroupAllLogTable_to_BackupLog
--AS	
----	EXEC sp_rename 'atum_log_user_level_stat', 			'atum_backup_log_user_level_stat'		-- 1
--	EXEC sp_rename 'atum_log_user_exp', 				'atum_backup_log_user_exp'				-- 2
--	EXEC sp_rename 'atum_log_user_game_start_end', 		'atum_backup_log_user_game_start_end'	-- 3
--	EXEC sp_rename 'atum_log_user_quest_pk_dead', 		'atum_backup_log_user_quest_pk_dead'	-- 4
--	EXEC sp_rename 'atum_log_user_warp', 				'atum_backup_log_user_warp'				-- 5
--	EXEC sp_rename 'atum_log_user_speed_hack', 			'atum_backup_log_user_speed_hack'		-- 6
--	EXEC sp_rename 'atum_log_item_charac_use', 			'atum_backup_log_item_charac_use'		-- 7
--	EXEC sp_rename 'atum_log_item_get_throw', 			'atum_backup_log_item_get_throw'		-- 8
--	EXEC sp_rename 'atum_log_item_buy_sell', 			'atum_backup_log_item_buy_sell'			-- 9
--	EXEC sp_rename 'atum_log_item_trade', 				'atum_backup_log_item_trade'			-- 10
--	EXEC sp_rename 'atum_log_server_map', 				'atum_backup_log_server_map'			-- 11
--	EXEC sp_rename 'atum_log_monster_boss', 			'atum_backup_log_monster_boss'			-- 12
--	EXEC sp_rename 'atum_log_user_memory_hack', 		'atum_backup_log_user_memory_hack'		-- 13, 2006-01-07 by cmkwon
--GO
---- end_Log 테이블 정리하기 프로시저
---------------------------------------------------------------------------------



-----------------------------------------------------------------------------
-- 2005-03-02 by cmkwon, Coupon 관련

-- 쿠폰 가져오기
CREATE PROCEDURE dbo.atum_Coupon_LoadCouponByNumber
	@i_CouponNumber			VARCHAR(30)			-- 쿠폰 넘버	
AS
	SELECT * 
		FROM td_CouponList WITH (NOLOCK)
		WHERE CouponNumber = @i_CouponNumber
GO

-- 쿠폰 사용하기
CREATE PROCEDURE dbo.atum_Coupon_UseCoupon
	@i_UniqueNumber			INT,				-- 쿠폰 유니크 넘버
	@i_UsedAccountName		VARCHAR(20),		-- 쿠폰 사용 AccountName
	@i_UsedTime				VARCHAR(30)			-- 쿠폰 사용 시간(거의 현재 시간과 동일)
AS
	UPDATE td_CouponList
		SET UsedFlag = 1, UsedAccountName = @i_UsedAccountName, UsedTime = @i_UsedTime
		WHERE UniqueNumber = @i_UniqueNumber
GO
-- End_Coupon 관련
-------------------------------------------------------------------------------


-----------------------------------------------------------------------------
-- 2005-03-30 by cmkwon, HappyHourEvent 관련

-- 모든 ServerGroup 이벤트, 현재 서버군 이벤트 가져오기
-- 2006-08-25 by cmkwon, @i_ServerGroupID		INT 추가함
-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 필드 추가(InfluenceType)
-- 2008-03-13 by dhjin, Level별 해피아워 이벤트 구현 - MinLevel, MaxLevel 필드 추가
CREATE PROCEDURE dbo.atum_LoadHappyHourEvent
	@i_ServerGroupID		INT				-- 2006-08-25 by cmkwon, 0(=AllServerGroup), 1(=10061), 2(10062), ...
AS
	-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 필드 추가(InfluenceType)와 아래와 같이 필드명 명시로 수정함
	--SELECT * 
	--	FROM ti_HappyHourEvent WITH (NOLOCK)
	--	WHERE ServerGroupID= 0 OR ServerGroupID= @i_ServerGroupID
	--	ORDER BY DayOfWeek, StartTime
	SELECT UniqueNumber, ServerGroupID, DayOfWeek, StartTime, EndTime, EXPRate, SPIRate, EXPRepairRate, DropItemRate, DropRareItemRate
			, WarPointRate, InfluenceType, MinLevel, MaxLevel
	FROM ti_HappyHourEvent WITH (NOLOCK)
	WHERE ServerGroupID= 0 OR ServerGroupID= @i_ServerGroupID
	ORDER BY InfluenceType, DayOfWeek, StartTime

GO

-- HappyHourEvnet 정보 Update -- 요일	- 일(0) 월(1) 화(2) 수(3) 목(4) 금(5) 토(6) HappyHourEvent기간(7) PCBangHappyHourEvent기간및설정(8)
-- 2006-08-25 by cmkwon, ti_HappyHourEvent 테이블에 ServerGroupID 필드 추가함
-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 세력 인자 추가 함
CREATE PROCEDURE dbo.atum_UpdateHappyHourEventDate
	@i_StartTime		VARCHAR(30),		-- 이벤트 시작 시간
	@i_EndTime			VARCHAR(30),		-- 이벤트 종료 시간
	@i_InflTy			TINYINT				-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - dbo.atum_UpdateHappyHourEventDate() 프로시저에 추가 된 인자
AS
	DECLARE @searchUniqueNumber INT
	-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 해당 세력의 기간을 검색한다.
	SET @searchUniqueNumber = (SELECT UniqueNumber FROM ti_HappyHourEvent WHERE InfluenceType = @i_InflTy AND DayOfWeek = 7)

	IF (@searchUniqueNumber IS NULL)
		BEGIN
			INSERT INTO ti_HappyHourEvent
				VALUES(0, 7, @i_StartTime, @i_EndTime, 0, 0, 0, 0, 0, 0, @i_InflTy, 1, 100)
				-- 2007-08-31 by cmkwon, 수정
				-- // 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 세력 필드 추가됨
				-- // 2008-03-13 by dhjin, Level별 해피아워 이벤트 구현 -
		END
	ELSE
		BEGIN
			UPDATE ti_HappyHourEvent
				SET StartTime = @i_StartTime, EndTime = @i_EndTime
				WHERE UniqueNumber = @searchUniqueNumber
		END	
GO
-- HappyHourEvent 관련
-------------------------------------------------------------------------------




-----------------------------------------------------------------------------
-- 2005-04-07 by cmkwon, 유료 아이템 관련



CREATE PROCEDURE dbo.atum_Cash_ChangeCharacterName
	@i_CharacterUID				INT,					-- 변경 할 캐릭터 UID
	@i_OriginCharacterName		VARCHAR(20),			-- 원래 캐릭터명
	@i_ChangeCharacterName		VARCHAR(20)				-- 변경하려는 캐릭터명
AS
	DECLARE @searchUniqueNumber INT
	SET @searchUniqueNumber = (SELECT UniqueNumber	FROM td_Character WHERE CharacterName = @i_ChangeCharacterName)

	IF (@searchUniqueNumber IS NOT NULL)
		return 0
	
	-- 친구리스트에서 모두(자신,상대방) 삭제
	DELETE FROM td_FriendList
		WHERE CharacterName = @i_OriginCharacterName OR FriendName = @i_OriginCharacterName
	
	UPDATE td_Character
		SET CharacterName = @i_ChangeCharacterName
		WHERE UniqueNumber = @i_CharacterUID
	
	return 1
GO
-- End_유료 아이템 관련
-----------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- 서버 정검시 GameLog BackUp Procedure         --2006-06-30 by dhJin 
CREATE PROCEDURE dbo.atum_GameLog_BackUp
AS

    --------------------------------------------------------------------------------
    -- 1. atum_backup_log_xxx 테이블 삭제
    drop table atum_backup_log_item_trade
    drop table atum_backup_log_user_memory_hack
    drop table atum_backup_log_user_speed_hack
-- 2006-07-25 by cmkwon, 
--    drop table atum_backup_log_item_buy_sell
--    drop table atum_backup_log_item_charac_use
--    drop table atum_backup_log_item_get_throw
--    drop table atum_backup_log_monster_boss
--    drop table atum_backup_log_server_map
--    drop table atum_backup_log_user_exp
--    drop table atum_backup_log_user_game_start_end
--    drop table atum_backup_log_user_quest_pk_dead
--    drop table atum_backup_log_user_warp
    --atum_backup_log_xxx 테이블 삭제
    --------------------------------------------------------------------------------

    --------------------------------------------------------------------------------
    -- 2. atum_log_xxx -> atum_backup_log_xxx 로 테이블 이름 변경
    exec sp_rename 'atum_log_item_trade', 'atum_backup_log_item_trade'
    exec sp_rename 'atum_log_user_memory_hack', 'atum_backup_log_user_memory_hack'
    exec sp_rename 'atum_log_user_speed_hack', 'atum_backup_log_user_speed_hack'
-- 2006-07-25 by cmkwon, 현재는 로그를 저장하지 않거나 혹은 로그를 삭제하지 않는 테이블
--    exec sp_rename 'atum_log_item_buy_sell', 'atum_backup_log_item_buy_sell'
--    exec sp_rename 'atum_log_item_charac_use', 'atum_backup_log_item_charac_use'
--    exec sp_rename 'atum_log_item_get_throw', 'atum_backup_log_item_get_throw'
--    exec sp_rename 'atum_log_monster_boss', 'atum_backup_log_monster_boss'
--    exec sp_rename 'atum_log_server_map', 'atum_backup_log_server_map'
--    exec sp_rename 'atum_log_user_exp', 'atum_backup_log_user_exp'
--    exec sp_rename 'atum_log_user_game_start_end', 'atum_backup_log_user_game_start_end'
--    exec sp_rename 'atum_log_user_quest_pk_dead', 'atum_backup_log_user_quest_pk_dead'
--    exec sp_rename 'atum_log_user_warp', 'atum_backup_log_user_warp'
    --atum_log_xxx -> atum_backup_log_xxx 로 테이블 이름 변경
    --------------------------------------------------------------------------------

    --------------------------------------------------------------------------------
    --atum_log_xxx 테이블 생성
    --------------------------------------------------------------------------------
    -- TABLE NAME: atum_log_user_speed_hack
    -- DESC      : 6 - speed hack log
    --------------------------------------------------------------------------------
    CREATE TABLE dbo.atum_log_user_speed_hack (
	    LogType					TINYINT,
	    Time					DATETIME,
	    CharacterUniqueNumber	INT,
	    MapIndex				SMALLINT,
	    Position_X				SMALLINT,
	    Position_Y				SMALLINT,
	    Position_Z				SMALLINT,
	    CheckType				TINYINT,
	    ReceivedMoveCounts		INT,
	    EngineItemNum			INT,
	    ServerPastTime			INT,
	    ClientPastTime			INT,
	    PastDistance			INT,
	    CurrentSpeed			INT
    ) 
    CREATE CLUSTERED INDEX idx_atum_log_user_speed_hack ON atum_log_user_speed_hack (Time)
    CREATE INDEX idx_LogType_log_user_speed_hack ON atum_log_user_speed_hack(LogType)									-- 2005-03-08 by cmkwon
    CREATE INDEX idx_CharacterUniqueNumber_log_user_speed_hack ON atum_log_user_speed_hack(CharacterUniqueNumber)		-- 2005-03-08 by cmkwon
    CREATE INDEX idx_ReceivedMoveCounts_log_user_speed_hack ON atum_log_user_speed_hack(ReceivedMoveCounts)		-- 2005-03-08 by cmkwon
  
    --------------------------------------------------------------------------------
    -- TABLE NAME: atum_log_item_trade
    -- DESC      : 10 - trade_send, trade_recv, add_item_by_admin, del_item_by_admin
    --------------------------------------------------------------------------------
    CREATE TABLE dbo.atum_log_item_trade (
	    LogType						TINYINT,
	    Time						DATETIME,
	    CharacterUniqueNumber		INT,			-- UINT
	    MapIndex					SMALLINT,
	    ItemUniqueNumber			BIGINT,
	    ItemNum						INT,
	    CurrentCount				INT,
	    ChangeCount					INT,
	    PeerCharacterName			VARCHAR(20),
	    PeerCharacterUniqueNumber	INT				-- UINT
    )
    CREATE CLUSTERED INDEX idx_atum_log_item_trade ON atum_log_item_trade (Time)
    CREATE INDEX idx_LogType_log_item_trade ON atum_log_item_trade(LogType)											-- 2005-03-08 by cmkwon
    CREATE INDEX idx_CharacterUniqueNumber_log_item_trade ON atum_log_item_trade(CharacterUniqueNumber)				-- 2005-03-08 by cmkwon
    CREATE INDEX idx_ItemUniqueNumber_log_item_trade ON atum_log_item_trade(ItemUniqueNumber)						-- 2005-03-08 by cmkwon
    CREATE INDEX idx_ItemNum_log_item_trade ON atum_log_item_trade(ItemNum)											-- 2005-03-08 by cmkwon
    CREATE INDEX idx_PeerCharacterName_log_item_trade ON atum_log_item_trade(PeerCharacterName)						-- 2005-03-08 by cmkwon
    CREATE INDEX idx_PeerCharacterUniqueNumber_log_item_trade ON atum_log_item_trade(PeerCharacterUniqueNumber)		-- 2005-03-08 by cmkwon
  
    --------------------------------------------------------------------------------
    -- TABLE NAME: atum_log_user_memory_hack
    -- DESC      : 2005-12-20 by cmkwon
    --			   13 - memory_hack log
    --					무기 - 
    --					엔진 -
    --					아머 - 
    --------------------------------------------------------------------------------
    CREATE TABLE dbo.atum_log_user_memory_hack (
	    LogType						TINYINT,
	    Time						DATETIME,
	    CharacterUniqueNumber		INT,
	    MapIndex					SMALLINT,
	    Position_X					SMALLINT,
	    Position_Y					SMALLINT,
	    Position_Z					SMALLINT,
	    ItemKind					INT,
	    ItemNum						INT,
	    ItemUniqueNumber			BIGINT,
	    MemoryHackCheckType			INT,
	    ValidValue					FLOAT,
	    CurrentValue				FLOAT,
	    Param1						INT
    ) 
    CREATE CLUSTERED INDEX idx_atum_log_user_memory_hack ON atum_log_user_memory_hack (Time)
    CREATE INDEX idx_CharacterUniqueNumber_log_user_memory_hack ON atum_log_user_memory_hack(CharacterUniqueNumber)		-- 2005-12-20 by cmkwon	
    CREATE INDEX idx_ItemKind_log_user_memory_hack ON atum_log_user_memory_hack(ItemKind)			-- 2005-12-20 by cmkwon	
    CREATE INDEX idx_ItemNum_log_user_memory_hack ON atum_log_user_memory_hack(ItemNum)				-- 2005-12-20 by cmkwon	
    CREATE INDEX idx_MemoryHackCheckType_log_user_memory_hack ON atum_log_user_memory_hack(MemoryHackCheckType)	-- 2005-12-20 by cmkwon	
    --atum_log_xxx 테이블 생성
    --------------------------------------------------------------------------------

GO
-- 서버 정검시 GameLog BackUp Procedure
--------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 이벤트 아이템 받은 유저 정보 검색하는 프로시저
CREATE PROCEDURE dbo.atum_GetEventItemList
	@i_AccountUID                int,
	@i_ItemEventUID               int
AS
	Select GetTime from atum_Log_ItemEvent WITH (NOLOCK)
	where AccountUID = @i_AccountUID and ItemEventUID = @i_ItemEventUID
GO
-- end 이벤트 아이템 받은 유저 정보 검색하는 프로시저
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 이벤트 아이템 받은 유저 정보 기록하는 프로시저
CREATE PROCEDURE dbo.atum_insert_Log_ItemEvent
	@i_AccountUID               int,
	@i_CharacterUID             int,
	@i_ItemEventUID             int,
	@i_InsertItemTime			VARCHAR(50)
AS
	Delete from atum_Log_ItemEvent 
		where AccountUID = @i_AccountUID and ItemEventUID = @i_ItemEventUID
	Insert into atum_Log_ItemEvent 
		VALUES(@i_AccountUID, @i_CharacterUID, @i_ItemEventUID, @i_InsertItemTime)
GO
-- end 이벤트 아이템 받은 유저 정보 기록하는 프로시저
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 이벤트 아이템 검색 하는 프로시저
-- // 2008-02-01 by cmkwon, ItemEvent 에 LastGameEndDate 체크 루틴 추가 - 필드 추가 한 것 검색 결과에 추가
CREATE PROCEDURE dbo.atum_Load_ItemEvent
AS
	select ItemEventUID, ItemEventType, OnlyPCBang, InfluenceType,ItemNum,Count,StartTime,EndTime,MemberShip,ReqLevel,NewMember,UnitKind,PrefixCodeNum,SuffixCodeNum,UseLastGameEndDate,LastGameEndDate
	from ti_ItemEvent WITH (NOLOCK)
GO
-- end 이벤트 아이템 검색 하는 프로시저
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, 퀵슬롯 저장 지우는 프로시저
CREATE PROCEDURE dbo.atum_delete_QuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int,
	@i_TabIdx                     int
AS
	DELETE FROM td_QuickSlot 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND TabIdx = @i_TabIdx
GO
-- end 퀵슬롯 저장 지우는 프로시저
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, 퀵슬롯 업데이트 프로시저
CREATE PROCEDURE dbo.atum_Update_QuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int,
	@i_TabIdx                     int,
	@i_ItemNum_1                  int,
	@i_ItemNum_2                  int,
	@i_ItemNum_3                  int,
	@i_ItemNum_4                  int,
	@i_ItemNum_5                  int,
	@i_ItemNum_6                  int,
	@i_ItemNum_7                  int,
	@i_ItemNum_8                  int,		--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
	@i_ItemNum_9                  int,		--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
	@i_ItemNum_10                 int		--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
AS
DECLARE @CheckNum  INT
SET @CheckNum = (SELECT TabIdx FROM td_QuickSlot 
	WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID 
			 AND TabIdx = @i_TabIdx)
IF (@CheckNum IS NOT NULL)
BEGIN
	UPDATE td_QuickSlot
	SET ItemNum_1 = @i_ItemNum_1, ItemNum_2 = @i_ItemNum_2, 
	ItemNum_3 = @i_ItemNum_3, ItemNum_4 = @i_ItemNum_4, 
	ItemNum_5 = @i_ItemNum_5, ItemNum_6 = @i_ItemNum_6,
	ItemNum_7 = @i_ItemNum_7, ItemNum_8 = @i_ItemNum_8,
	ItemNum_9 = @i_ItemNum_9, ItemNum_10 = @i_ItemNum_10		--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
	WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID 
			 AND TabIdx = @i_TabIdx 
END
ELSE
BEGIN
	INSERT INTO td_QuickSlot 
	VALUES(@i_AccountUID, @i_CharacterUID, @i_TabIdx, @i_ItemNum_1,
	 @i_ItemNum_2, @i_ItemNum_3, @i_ItemNum_4, @i_ItemNum_5,
	 @i_ItemNum_6, @i_ItemNum_7, @i_ItemNum_8, @i_ItemNum_9, @i_ItemNum_10)			--// 2008-06-19 by dhjin, EP3 - 8 -> 10으로 수정 
END
GO
-- end 퀵슬롯 업데이트 프로시저
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, 퀵슬롯 검색 프로시저
CREATE PROCEDURE dbo.atum_GetQuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int
AS
	SELECT * FROM td_QuickSlot WITH (NOLOCK)
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
GO
-- end 퀵슬롯 검색 프로시저
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- 여단 창고 관련
--!!!!	2006-09-21 by cmkwon
-- Name: atum_Get_GuildStore
-- Desc: 해당 여단 창고 아이테 가져오기
-- 		
--		
--====
CREATE PROCEDURE dbo.atum_Get_GuildStore
	@i_GuildUID         INT,
	@i_ItemStorage		TINYINT		-- 2006-09-25 by cmkwon
AS
	SELECT * FROM td_Store WITH (NOLOCK)
		WHERE Possess = @i_GuildUID AND ItemStorage = @i_ItemStorage
GO

--!!!!
-- Name: atum_Update_Guild_Store
-- Desc: 2006-09-08 by dhjin
--====
CREATE PROCEDURE dbo.atum_Update_Guild_Store 
	@i_ItemUID                  INT,
	@i_AccountUID                INT,
	@i_Possess					 INT,
	@i_ItemStorage				 TINYINT,
	@i_Count                     INT
AS
	UPDATE td_Store 
		SET AccountUniqueNumber = @i_AccountUID, Possess = @i_Possess, 
				ItemStorage = @i_ItemStorage, CurrentCount = @i_Count
		WHERE UniqueNumber = @i_ItemUID
GO

--!!!!
-- Name: atum_Delete_Guild_Store
-- Desc: 2006-09-08 by dhjin
--====
CREATE PROCEDURE dbo.atum_Delete_Guild_Store
	@i_ItemUID                   INT,
	@i_GuildUID                  INT,
	@i_ItemStorage				 TINYINT
AS
	DELETE FROM td_Store
		WHERE UniqueNumber = @i_ItemUID AND AccountUniqueNumber = @i_GuildUID AND Possess = @i_GuildUID
GO

-- 2007-01-30 by cmkwon, 필요 없어서 주석 처리함 - atum_GetEnchantBYItemUID() 프로시저로 대체함
----!!!!
---- Name: atum_GetAllEnchant2
---- Desc: 2006-09-24 by cmkwon
----====
--CREATE PROCEDURE dbo.atum_GetAllEnchant2
--	@i_AccountUniqueNumber		INT,
--	@i_CharacterUniqueNumber	INT,
--	@i_ItemStorage				TINYINT
--AS
--	SELECT e.TargetItemUniqueNumber, e.TargetItemNum, e.EnchantItemNum
--	FROM td_Enchant e, td_Store s WITH (NOLOCK)
--	WHERE s.AccountUniqueNumber = @i_AccountUniqueNumber AND s.ItemStorage = @i_ItemStorage
--			AND s.possess = @i_CharacterUniqueNumber AND e.TargetItemUniqueNumber = s.UniqueNumber
--GO
--


--!!!!
-- Name: atum_GetEnchantBYItemUID
-- Desc: 2007-01-30 by cmkwon, 추가함
--====
CREATE PROCEDURE dbo.atum_GetEnchantBYItemUID
	@i_ItemUID		BIGINT
AS
	SELECT TargetItemNum, EnchantItemNum
	FROM td_enchant WITH(NOLOCK)
	WHERE @i_ItemUID = TargetItemUniqueNumber
GO








-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- 2006-09-21 by cmkwon, 빌링 관련

--!!!!
-- Name: Billing_CashItem_Insert_TO_Store
-- Desc: 해당 캐릭터 창고에 아이템 추가
--====
CREATE PROCEDURE dbo.Billing_CashItem_Insert_TO_Store
	@i_AccUID			INT,			-- 
	@i_CharUID			INT,			-- 
	@i_ItemNum			INT,			-- 
	@i_MinTradeQuantity	INT,			-- 최소 거래 카운트(카운터블:1, 난카운터블:1이상)
	@i_InsertCount		INT				-- 추가 카운트
AS
	DECLARE @ItemKind	TINYINT
	SET @ItemKind		= (SELECT Kind FROM ti_item WHERE ItemNum = @i_ItemNum)
	IF (@ItemKind IS NULL)
	BEGIN
		RETURN
	END

	-- 넌카운터블아이템 아이템 - 최소 거래 카운트를 1로 설정
	IF ( 0 = dbo.atum_IsCountableItem(@ItemKind) )
	BEGIN
		SET @i_MinTradeQuantity	= 1
	END

	DECLARE @InsertCount	INT
	DECLARE @CurCount		INT
	-- 넌카운터블 아이템은 CurrentCount = 1, 추가개수 = @i_InsertCount
	-- 카운터블 아이템은 CurrentCount = @i_MinTradeQuantity * @i_InsertCount, 추가개수=1
	IF ( 0 = dbo.atum_IsCountableItem(@ItemKind) )
		BEGIN
			SET @InsertCount	= @i_InsertCount	-- td_store 테이블에 추가될 카운트
			SET @CurCount		= 1					-- CurrentCount에 할당 될 개수
		END
	ELSE
		BEGIN
			SET @InsertCount	= 1						-- td_store 테이블에 추가될 카운트
			SET @CurCount		= @i_MinTradeQuantity * @i_InsertCount	-- CurrentCount에 할당 될 개수
		END

	-------------------------------------------------------------------------------
	-- td_store 테이블에 아이템 추가
	DECLARE @i	INT
	SET @i		= 0	
	DECLARE @InsertItemUID	BIGINT
	WHILE (@i < @InsertCount)
		BEGIN
			
			-- 캐릭터의 창고로 아이템 추가
			INSERT INTO td_Store
				VALUES(@i_AccUID, @i_CharUID, 1, 0, @CurCount, 0, 99, @i_ItemNum, 0, 0, 0, 0, 0, 0, GetDate())
			SET @InsertItemUID = SCOPE_IDENTITY();

			-- 아이템 구매 로그 추가
			-- #define T1_FL_LOG_ITEM_BUY_ITEM					0x25	// 37 - 아이템 구매
			exec dbo.atum_log_insert_item_buy_sell 37, @i_CharUID, 0, @InsertItemUID, @i_ItemNum, @CurCount, @CurCount, 0

			SET @i		= @i + 1
		END
GO

--!!!!	2006-09-21 by cmkwon
-- Name: Billing_Insert_Item
-- Desc: 유저가 웹상에서 아이템 결재후 아이템을 게임상의 캐릭터 창고에 넣어주는 프로시저
-- 		
--		
--		[out 1] INT nErrCode	==> =0(성공), <>0(실패, ERR_DB_XXX)
--====
CREATE PROCEDURE dbo.Billing_Insert_Item
	@i_AccountName				VARCHAR(20),				-- 아이템 구매 계정명
	@i_CharacterName			VARCHAR(20),				-- 아이템 구매시 게임상에서의 캐릭터명
	@i_ItemNum					VARCHAR(50),				-- 아이템 유니크 번호
	@i_BuyItemCount				INT							-- 아이템 구입 카운트
AS
	--------------------------------------------------------------------------------
	-- 해당 계정 존재 유무체크 및 현재 계정이 게임에 접속 중인지 체크
	DECLARE @AccUID		INT
	SET @AccUID			= (SELECT AccountUniqueNumber FROM td_Account WHERE AccountName = @i_AccountName AND ConnectingServerGroupID = 0)
	IF (@AccUID IS NULL)
	BEGIN
		-- #define ERR_DB_USER_CONNECTING_GAME_SERVER		300			// 유저가 게임서버에 접속 중이다 - 웹에서 아이템 구매시는 게임을 종료해야함
		SELECT 300
		RETURN
	END
	
	--------------------------------------------------------------------------------
	-- 캐릭터명 체크
	DECLARE @CharUID	INT
	SET @CharUID		= (SELECT c.UniqueNumber FROM td_account a, td_character c
								WHERE a.AccountName = @i_AccountName AND a.AccountUniqueNumber = c.AccountUniqueNumber AND c.CharacterName = @i_CharacterName)
	IF (@CharUID IS NULL)
	BEGIN
		-- #define ERR_DB_IS_NOT_CHARACTERNAME				301			// 게임 DB 테이블에 캐릭터명이 없습니다.
		SELECT 301
		RETURN
	END

	--------------------------------------------------------------------------------
	-- 아이템 검색
	-- 1. 커서 선언
	DECLARE cur_item_info CURSOR 
	FOR
		SELECT ItemNum, Kind, SummonMonster, MinTradeQuantity, Time, ParameterValue1, DestParameter1
				, ParameterValue2, DestParameter2, ParameterValue3, DestParameter3, ParameterValue4, DestParameter4
			FROM ti_item WHERE ItemNum = @i_ItemNum

	-- 2. 커서 오픈
	OPEN cur_item_info

	-- 3. 변수 선언
	DECLARE @ItemNum			INT
	DECLARE @ItemKind			TINYINT
	DECLARE @CashItemType		INT
	DECLARE @MinTradeQuantity	SMALLINT
	DECLARE @Period				INT			-- 프리미엄 아이템 적용 기간(Day)
	DECLARE @AddItemNum1		FLOAT
	DECLARE @AddItemCount1		TINYINT
	DECLARE @AddItemNum2		FLOAT
	DECLARE @AddItemCount2		TINYINT
	DECLARE @AddItemNum3		FLOAT
	DECLARE @AddItemCount3		TINYINT
	DECLARE @AddItemNum4		FLOAT
	DECLARE @AddItemCount4		TINYINT

	-- 4. 첫 로우 FETCH
	FETCH NEXT FROM cur_item_info
		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
				, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
	-- 필요없는 부분임 5. 순환
	--WHILE @@FETCH_STATUS = 0
	--BEGIN
	--	FETCH NEXT FROM cur_item_info
	--		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
	--			, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
	--END

	-- 6. 커서 CLOSE
	CLOSE cur_item_info
	
	-- 7. 커서 DEALLOCATE
	DEALLOCATE cur_item_info

	-- 아이템 정보 체크
	IF (@ItemNum IS NULL) OR (@ItemKind IS NULL) OR (@CashItemType IS NULL) OR (@MinTradeQuantity IS NULL)
	BEGIN
		-- #define ERR_DB_INVALID_ITEM						4			// 구매하려는 아이템이 유효하지 않음 - ti_item_info 테이블에 없거나 IsDisable 필드가 0이 아니다
		SELECT 4
		RETURN
	END
	
	-- // 유료화 아이템 kind - ITEM 구조체에서 SummonMonster 필드를 사용한다
	-- #define CASH_ITEMKIND_PREMIUM_CARD			(BYTE)0
	-- #define CASH_ITEMKIND_OPTION_ITEM			(BYTE)1
	-- #define CASH_ITEMKIND_CARD_ITEM				(BYTE)2
	-- #define CASH_ITEMKIND_ACCESSORY_ITEM		(BYTE)3
	-- 1. 프리미엄카드 아이템 구입
	-- 2. 일반 유료 아이템 구입
	IF (0 = @CashItemType)
	BEGIN

		--------------------------------------------------------------------------------
		-- 프리미엄 검색
		-- 1. 커서 선언
		DECLARE cur_premium_info CURSOR 
		FOR
			SELECT UniqueNumber, ItemNum, ExpireTime FROM td_AccountCashStore WHERE AccountUniqueNumber = @AccUID

		-- 2. 커서 오픈
		OPEN cur_premium_info

		-- 3. 변수 선언
		DECLARE @PremiumUID			BIGINT
		DECLARE @PremiumItemNum		INT
		DECLARE @ExpireTime			DATETIME
			
		-- 4. 첫 로우 FETCH
		FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
		-- 필요없는 부분임 5. 순환
		--WHILE @@FETCH_STATUS = 0
		--BEGIN
		--	FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
		--END

		-- 6. 커서 CLOSE
		CLOSE cur_premium_info
		
		-- 7. 커서 DEALLOCATE
		DEALLOCATE cur_premium_info

		DECLARE @CurDate	DATETIME
		SET @CurDate		= GetDate()
		IF (@PremiumUID IS NULL)-- 프리미엄 아이템이 없다, 추가
		BEGIN
			INSERT INTO td_accountCashStore
				VALUES (@AccUID, @ItemNum, @CurDate, @CurDate, DATEADD(Day, @Period, @CurDate))
		END
		
		ELSE-- 기존에 프리미엄 아이템이 존재한다.
		BEGIN

			-- 이미 만료된 프리미엄 아이템
			IF @ExpireTime < @CurDate
			BEGIN
				SET @ExpireTime		= @CurDate
			END

			ELSE
			BEGIN
				-- 구입 후 날짜가 현재 날짜로부터 180일까지만 구입가능
				IF DATEADD(Day, @Period, @ExpireTime) > DATEADD(Day, 180, @CurDate)
				BEGIN
					-- #define ERR_DB_CANNOT_ADD_PREMIUMITEM			303			// 프리미엄 아이템 추가 구매 불가(현재부로 180일 제한)
					SELECT 302
					RETURN
				END				
			END

			-- #define ERR_NO_ERROR						0
			SELECT 0

			UPDATE td_accountCashStore
				SET UpdatedTime = @CurDate, ExpireTime = DATEADD(Day, @Period, @ExpireTime)
				WHERE UniqueNumber = @PremiumUID
		END

		-- 프리미엄 추가 아이템 추가해주기
		IF (@AddItemNum1 IS NOT NULL) AND (0 <> @AddItemNum1) AND (0 < @AddItemCount1)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum1, 1, @AddItemCount1
		IF (@AddItemNum2 IS NOT NULL) AND (0 <> @AddItemNum2) AND (0 < @AddItemCount2)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum2, 1, @AddItemCount2
		IF (@AddItemNum3 IS NOT NULL) AND (0 <> @AddItemNum3) AND (0 < @AddItemCount3)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum3, 1, @AddItemCount3
		IF (@AddItemNum4 IS NOT NULL) AND (0 <> @AddItemNum4) AND (0 < @AddItemCount4)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum4, 1, @AddItemCount4
	END-- END - IF (0 = @CashItemType)

	ELSE-- 일반 유료 아이템
	BEGIN
		-- #define ERR_NO_ERROR						0
		SELECT 0

		exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @ItemNum, @MinTradeQuantity, @i_BuyItemCount
	END

GO

-- END_빌링 관련
-------------------------------------------------------------------------------

--!!!!
-- Name: atum_log_Insert_GuildStore
-- Desc: 2006-09-27 by dhjin
--		 // 2008-04-02 by dhjin, ti_item 사용하던 쿼리 수정함, ti_item 접근 필요 없었음
--====
CREATE PROCEDURE dbo.atum_log_Insert_GuildStore
	@i_LogType						TINYINT,
	@i_GuildUID						INT,
	@i_GuildName					VARCHAR(30),
	@i_AccountUID					INT,
	@i_AccountName					VARCHAR(20),
	@i_CharacterUID					INT,
	@i_CharacterName				VARCHAR(20),
	@i_ItemUID						BIGINT,
	@i_ItemNum						INT,
	@i_PrefixCodeNum				INT,
	@i_SuffixCodeNum				INT,
	@i_ItemResultCount				INT,
	@i_ItemChangeCount				INT
AS
	INSERT INTO atum_log_GuildItem 
		VALUES (@i_LogType, GetDate(), @i_GuildUID, @i_GuildName, @i_AccountUID, @i_AccountName, 
				@i_CharacterUID, @i_CharacterName, @i_ItemUID, @i_ItemNum, 
				@i_PrefixCodeNum, @i_SuffixCodeNum, @i_ItemResultCount, @i_ItemChangeCount)
GO

--!!!!
-- Name: atum_log_Get_GuildStore
-- Desc: 2006-09-27 by dhjin
--====
CREATE PROCEDURE dbo.atum_log_Get_GuildStore
	@i_GuildUID						INT
	AS
		SELECT   LogType, Time, CharacterUID, CharacterName, ItemNum, 
					PrefixCodeNum, SuffixCodeNum, ItemChangeCount
		FROM     atum_log_GuildItem
		WHERE	 (DATEDIFF(hh, Time, GETDATE()) < 48) AND (GuildUID = @i_GuildUID)
		ORDER BY Time
GO

--!!!!
-- Name: atum_AllDelete_Guild_Store
-- Desc: 2006-09-29 by dhjin
--====
CREATE PROCEDURE dbo.atum_AllDelete_Guild_Store
	@i_GuildUID                  INT,
	@i_ItemStorage				 TINYINT
AS
	DELETE FROM td_Store
		WHERE AccountUniqueNumber = @i_GuildUID AND Possess = @i_GuildUID AND ItemStorage = @i_ItemStorage
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_storeSkill
-- DESC      : 2006-11-17 by dhjin, 2차 스킬 사용 정보 업데이트
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStoreItemSkillUseTime
	@ItemUID		BIGINT,
	@i_UseTime		VARCHAR(30)
AS
	UPDATE td_storeSkill
		SET UseTime = @i_UseTime
		WHERE UniqueNumber = @ItemUID
GO


-- Name: atum_Change_AccountName_Of_AllCharacter
-- Desc: 2007-01-22 by cmkwon, 추가 함
--		   해당 계정의 캐릭터 정보를 찾아서 모두 인자의 계정으로 변경한다.
--====
CREATE PROCEDURE dbo.atum_Change_AccountName_Of_AllCharacter
	@i_OriginAccountName		VARCHAR(20),
	@i_NewAccountName			VARCHAR(20)
AS
	--------------------------------------------------------------------------------
	-- 1. 해당 계정의 캐릭터가 있는지 체크
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT TOP 1 AccountUniqueNumber FROM td_Character WHERE AccountName = @i_OriginAccountName)
	IF @OriginAccUID IS NULL
		RETURN 0

	--------------------------------------------------------------------------------
	-- 2. 계정 변경 정보를 로그 테이블에 추가한다
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - 캐릭터 삭제
	INSERT INTO atum_log_user_game_start_end
		SELECT 28, GetDate(), UniqueNumber, 0, 0, 0, 0,	CharacterName, AccountUniqueNumber, AccountName, 0, TotalPlayTime, 0, 0
		FROM td_Character
		WHERE AccountName = @i_OriginAccountName

	--------------------------------------------------------------------------------
	-- 3. td_Account테이블에 계정명을 변경한다.
	UPDATE td_Character
	SET AccountName = @i_NewAccountName
	WHERE AccountName = @i_OriginAccountName

	RETURN 1
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_GetPCBangIPList
-- DESC      : 2007-01-24 by dhjin, PC방 IP리스트
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetPCBangIPList
AS
	SELECT UID, ST_IP, ED_IP FROM td_PCBang with(NOLOCK)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_insert_integration
-- DESC      : 2007-01-26 by cmkwon, 서버 이전,통합 로그 남기기
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_insert_integration
	@i_LogType					TINYINT,
	@i_AccountName				VARCHAR(20),		-- 2007-01-29 by cmkwon, 추가함
	@i_AccountUID				INT,				-- 2007-01-29 by cmkwon, 추가함
	@i_SourceDBNum				INT,
	@i_SourceCharUID			INT,
	@i_SourceCharName			VARCHAR(20),
	@i_TargetDBNum				INT,
	@i_TargetCharUID			INT,
	@i_TargetCharName			VARCHAR(20)
AS
	INSERT INTO atum2_db_account_test.dbo.atum_log_integration
	VALUES(@i_LogType, GetDate(), @i_AccountName, @i_AccountUID, @i_SourceDBNum, @i_SourceCharUID, @i_SourceCharName,
		@i_TargetDBNum, @i_TargetCharUID, @i_TargetCharName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_select_integration
-- DESC      : 2007-01-30 by dhjin, 서버 이전,통합 로그 검색
--				// 2008-03-03 by cmkwon, 서버군 통합 로그 타입 보여주기 - 검색 결과에 로그타입 추가
--------------------------------------------------------------------------------
CREATE  PROCEDURE dbo.atum_log_select_integration
	@i_str				VARCHAR(2000)
AS
	IF (@i_str = '')
	BEGIN
		-- // 2008-03-03 by cmkwon, 서버군 통합 로그 타입 보여주기 - 검색 결과에 로그타입 추가
		SELECT AccountUID, AccountName, SourceDBNum, SourceCharacterUID, SourceCharacterName, 
			TargetDBNum, TargetCharacterUID, TargetCharacterName, Time, LogType
		FROM atum2_db_account_test.dbo.atum_log_integration WITH (NOLOCK) 
		order by Time
	END
	ELSE
	BEGIN
		-- // 2008-03-03 by cmkwon, 서버군 통합 로그 타입 보여주기 - 검색 결과에 로그타입 추가
		DECLARE @Query VARCHAR(3000)
		SET @Query = 'SELECT AccountUID, AccountName, SourceDBNum, SourceCharacterUID, 
				SourceCharacterName, TargetDBNum, TargetCharacterUID, TargetCharacterName, Time, LogType
				FROM atum2_db_account_test.dbo.atum_log_integration WITH (NOLOCK) where ' 
				+@i_str + 'order by Time'
		exec (@Query)
	END	
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_InsertLeaderItem
-- DESC      : 2007-02-13 by dhjin, 지도자 전용 아이템 추가하는 프로시저
--				7001320	지도자의 광휘(바이제니유)
--				7001330	지도자의 광휘(알링턴)
--				7001090	세력의 가호
--				7001110	성장의 시간
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertLeaderItem
	@i_Infltype				TINYINT,
	@i_AccountUniqueNumber	INT,
	@i_Possess				INT
AS
	IF @i_Infltype = 2 -- 바이제니유
	BEGIN
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001320, 1, 0, 99		-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001090, 10, 0, 99	-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001110, 5, 0, 99		-- 
	END

	ELSE IF @i_Infltype = 4 -- 알링턴
	BEGIN
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001330, 1, 0, 99		-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001090, 10, 0, 99	-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001110, 5, 0, 99		-- 
	END
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_InsertLeaderItem
-- DESC      : 2007-02-13 by dhjin, 지도자 전용 아이템 삭제하는 프로시저
--				7001320	지도자의 광휘(바이제니유)
--				7001330	지도자의 광휘(알링턴)
--				7001090	세력의 가호
--				7001110	성장의 시간
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteLeaderItem
AS
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001320
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001330
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001090
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001110
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Update_SubLeader
-- DESC      : 2007-02-13 by dhjin, 부지도자 설정 프로시저
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_SubLeader
	@o_RetCode				INT OUTPUT,
	@i_CharacterName		varchar(20),
	@i_InflType				TINYINT,
	@i_SubLeaderRank		TINYINT
AS
	DECLARE @SetSubLeaderNum	INT
	DECLARE @SetUID				INT
	DECLARE @CheckCount	INT
	SELECT @SetUID = UniqueNumber FROM dbo.td_character WITH(NOLOCK) where CharacterName = @i_CharacterName AND InfluenceType = @i_InflType
	IF(@SetUID IS NULL)
	BEGIN
		SET @o_RetCode = 10						-- 부지도자 케릭터 검색 이름이 없다.
		RETURN
	END
	
	SELECT @CheckCount = count(*)  FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
		WHERE InfluenceType = @i_InflType  AND (InflSub1LeaderCharacterUID = @SetUID OR  InflSub2LeaderCharacterUID = @SetUID OR InflLeaderCharacterUID = @SetUID)
	
	IF(@CheckCount > 0)
	BEGIN
		SET @o_RetCode = 0
		RETURN
	END

	IF(1 = @i_SubLeaderRank)
	BEGIN
		SELECT @SetSubLeaderNum = InflSub1LeaderCharacterUID FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
				WHERE InfluenceType = @i_InflType AND  InflSub2LeaderCharacterUID <> @SetUID AND InflLeaderCharacterUID <> @SetUID
		IF(@SetSubLeaderNum = @SetUID)
		BEGIN
			SET @o_RetCode = 20						-- 이미 부지도자로 설정 되어있다.
			RETURN
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub1LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType
			SET @o_RetCode = 1
			RETURN	@SetUID							-- 부지도자1로 설정
		END
	END
	
	ELSE IF(2 = @i_SubLeaderRank)
	BEGIN
		SELECT @SetSubLeaderNum = InflSub2LeaderCharacterUID FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
				WHERE InfluenceType = @i_InflType AND  InflSub1LeaderCharacterUID <> @SetUID AND InflLeaderCharacterUID <> @SetUID
		IF(@SetSubLeaderNum = @SetUID)
		BEGIN
			SET @o_RetCode = 20						-- 이미 부지도자로 설정 되어있다.
			RETURN
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub2LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType
			SET @o_RetCode = 2
			RETURN	@SetUID							-- 부지도자2로 설정
		END
	END
	
	SET @o_RetCode = 0
	RETURN										-- 부지도자 설정이 이미 되어있어서 설정이 안된다.
GO

-- 2007-05-15 by cmkwon, 아래의 프로시저로 수정
----------------------------------------------------------------------------------
---- TABLE NAME: dbo.atum_SelectDeletedCharacter
---- DESC      : 2007-02-22 by dhjin,
----------------------------------------------------------------------------------
--CREATE PROCEDURE dbo.atum_SelectDeletedCharacter
--	@i_AccountUID		INT
--AS
--	SELECT AccountUniqueNumber, AccountName, UniqueNumber, CharacterName FROM td_Character WITH (NOLOCK) 
--	WHERE 0 <> Race & 0x4000 AND AccountUniqueNumber = @i_AccountUID
--GO
--
--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_admin_GetAllDeletedCharacter
-- DESC      : 2007-05-15 by cmkwon,
--				// 2008-01-17 by cmkwon, T_A: 삭제 상태의 캐릭터 의 세력, 선택 가능한 세력 보여주기 추가 - 가져오는 필드 추가(InfluenceType, SelectableInfluenceMask)
--				// 2008-03-03 by cmkwon, 삭제 상태의 캐릭터리스트 정보에 삭제 된 날짜 보여 주기 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_GetAllDeletedCharacter
	@i_AccName		VARCHAR(20)
AS
	-- // 2008-01-17 by cmkwon, T_A: 삭제 상태의 캐릭터 의 세력, 선택 가능한 세력 보여주기 추가 - 가져오는 필드 추가(InfluenceType, SelectableInfluenceMask)
	-- // 2008-03-03 by cmkwon, 삭제 상태의 캐릭터리스트 정보에 삭제 된 날짜 보여 주기 - 삭제된 날짜 가져오기 추가, 삭제된 날짜 순으로 정렬 추가
	SELECT AccountUniqueNumber, AccountName, UniqueNumber, CharacterName, InfluenceType, SelectableInfluenceMask, LastStartedTime FROM td_Character WITH (NOLOCK) 
	WHERE 0 <> Race & 0x4000 AND AccountName = @i_AccName
	ORDER BY LastStartedTime
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LiveDeletedCharacter
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LiveDeletedCharacter
	@i_AccountUID		INT,
	@i_CharacterUID		INT
AS
	DECLARE @LivedCheck		TINYINT
	SELECT @LivedCheck = count(*) FROM atum_log_Live_Deleted_Character WITH (NOLOCK) WHERE CharacterUID = @i_CharacterUID

	-- // 2008-02-20 by cmkwon, 예당 요청으로 2회까지 복구 가능하다
	IF (@LivedCheck >= 2)
		BEGIN
			RETURN	10			-- 복구 한적이 있는 케릭터
		END
	
	DECLARE @CharacterNum		INT
	SELECT @CharacterNum = count(*) FROM td_Character WITH (NOLOCK) WHERE 0 = Race & 0x4000 AND AccountUniqueNumber = @i_AccountUID

	IF (@CharacterNum >= 3)
		BEGIN
			RETURN	20			-- 케릭터가 3명이 있기 때문에 복구 불가.
		END
	ELSE
		BEGIN
			UPDATE td_Character SET Race = Race ^ 0x4000 WHERE AccountUniqueNumber = @i_AccountUID AND UniqueNumber = @i_CharacterUID
		END

	RETURN 0
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Job_DeleteCharacter
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Job_DeleteCharacter
AS
	-- // 2007-11-16 by cmkwon, 캐릭터 삭제 유지 일 수를 변수로 뽑아서 처리 - dbo.atum_Job_DeleteCharacter 프로시저 수정
	DECLARE @KeepTermOfDay INT
	SET @KeepTermOfDay		= 14

	-- 1. 캐릭터 소유 아이템의 인챈트 제거	
	DELETE td_Enchant FROM td_Enchant e, td_Store s 
	WHERE s.ItemStorage <> 2 AND s.AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND s.Possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND s.UniqueNumber = e.TargetItemUniqueNumber

	-- 2. 캐릭터 소유 아이템 제거
	DELETE FROM td_Store WHERE ItemStorage <> 2 AND AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 3. 캐릭터 퀵 슬롯 제거
	DELETE FROM td_QuickSlot WHERE AccountUID IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND CharacterUID IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 4. 캐릭터 소유 스킬 제거
	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 5. 퀘스트 테이블에서 제거
	DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 6. 퀘스트 몬스터 정보 테이블에서 제거
	DELETE FROM td_CharacterQuestMonsterCount WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 7. 친구리스트에서 제거
	DELETE FROM td_FriendList WHERE CharacterName IN 
	(SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) OR FriendName IN 
	(SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	--8. 튜토리얼 리스트에서 제거
	DELETE FROM td_TutorialComplete WHERE CharacterUID IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- last 캐릭터 테이블에서 제거
	DELETE FROM td_Character WHERE UniqueNumber IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_DeleteCharacterByJob
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.Insert_atum_log_Live_Deleted_Character
	@i_LogType						TINYINT,
	@i_AccountUID					INT,
	@i_AccountName					VARCHAR(20),
	@i_CharacterUID					INT,
	@i_CharacterName				VARCHAR(20)
AS
	INSERT INTO dbo.atum_log_Live_Deleted_Character
	VALUES (@i_LogType, GetDate(), @i_AccountUID, @i_AccountName, @i_CharacterUID, @i_CharacterName)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_load_ti_MysteryItemDrop
-- DESC      : 2007-05-11 by cmkwon,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_MysteryItemDrop
AS
	SELECT MysteryItemDropNum,ReqUnitKind,ReqMinLevel,ReqMaxLevel,DropItemNum
			,MinCount,MaxCount,Probability,PrefixProbability,SuffixProbability
	FROM atum2_db_account_test.dbo.ti_MysteryItemDrop WITH(NOLOCK)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonRangeTimeInfo
-- DESC      : 생성해야 할 전략포인트 생성 주기 시간 정보를 얻어오는 프로시저.
-- 2007-03-29 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRangeTimeInfo
AS
	SELECT StartTime, EndTime, SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily FROM dbo.td_StrategyPointSummonRangeTimeInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonInfo
-- DESC      : 생성해야 할 전략포인트 정보를 얻어오는 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonInfo
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadAllStrategyPointSummonInfo
-- DESC      : 생성해야 할 전략포인트 정보 전체 가져오는 프로시저 (SCAdminTool에서 사용)
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadAllStrategyPointSummonInfo
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK) ORDER BY SummonTime
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoByMapIndex
-- DESC      : 생성해야 할 전략포인트 맵 정보를 ti_StrategyPointSummonMapIndex와 동일하게 하는 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoByMapIndex
AS
	DELETE dbo.td_StrategyPointSummonInfo WHERE MapIndex NOT IN (SELECT MapIndex FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex)
	INSERT INTO dbo.td_StrategyPointSummonInfo 
		SELECT MapIndex, 0, GetDATE(), NULL		-- // 2008-04-08 by dhjin, 소환 가능 시간 설정 - 
		FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex
		WHERE MapIndex NOT IN (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoBySummon
-- DESC      : 생성된 전략포인트 수정 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoBySummon
	@i_MapIndex			INT,
	@i_SummonCount		TINYINT
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = @i_SummonCount WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoBySummonTime
-- DESC      : 전략포인트 예정 시간 수정 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoBySummonTime
	@i_MapIndex			INT,
	@i_SummonTime		VARCHAR(30),
	@i_SummonAttribute	TINYINT		-- // 2008-04-08 by dhjin, 소환 가능 시간 설정 - 
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonTime = @i_SummonTime, SummonAttribute = @i_SummonAttribute WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoByNewSummonRange
-- DESC      : 생성될 전략포인트 시간 값 설정 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoByNewSummonRange
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = SummonCount + 1
	DECLARE @tmNewSTime	DATETIME
	SET @tmNewSTime = (SELECT EndTime FROM dbo.td_StrategyPointSummonRangeTimeInfo)
	DECLARE @tmSummonRange SMALLINT
	SET @tmSummonRange = (SELECT SummonRange FROM atum2_db_account_test.dbo.td_StrategyPointSummonRange)
	DECLARE @tmStrategyPointSummonCheck TINYINT
	SET @tmStrategyPointSummonCheck = (SELECT StrategyPointSummonCheck FROM atum2_db_account_test.dbo.td_StrategyPointSummonRange)
	DECLARE @tmMaxSummonCountDaily TINYINT
	SET @tmMaxSummonCountDaily = (SELECT MaxSummonCountDaily FROM atum2_db_account_test.dbo.td_StrategyPointSummonRange)
	UPDATE dbo.td_StrategyPointSummonRangeTimeInfo SET StartTime = @tmNewSTime, EndTime = DateAdd(day, @tmSummonRange, EndTime), 
	       SummonRange = @tmSummonRange, StrategyPointSummonCheck = @tmStrategyPointSummonCheck, MaxSummonCountDaily = @tmMaxSummonCountDaily
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonMapIndex
-- DESC      : 전략포인트 생성 맵 가져오는 프로시저
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonMapIndex
AS
	SELECT MapIndex FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonRange
-- DESC      : 전략포인트 생성 주기 가져오는 프로시저
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRange
AS
	SELECT SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily
	FROM atum2_db_account_test.dbo.td_StrategyPointSummonRange
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonRange
-- DESC      : 전략포인트 생성 주기 업데이트 프로시저
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonRange
	@i_NewSummonRange					SMALLINT,
	@i_NewStrategyPointSummonCheck		TINYINT,
	@i_NewMaxSummonCountDaily			TINYINT
AS
	IF(0=@i_NewStrategyPointSummonCheck)
	BEGIN
		UPDATE atum2_db_account_test.dbo.td_StrategyPointSummonRange
		SET StrategyPointSummonCheck = @i_NewStrategyPointSummonCheck
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account_test.dbo.td_StrategyPointSummonRange 
		SET SummonRange = @i_NewSummonRange, StrategyPointSummonCheck = @i_NewStrategyPointSummonCheck, 
			MaxSummonCountDaily = @i_NewMaxSummonCountDaily
	END
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_InitStrategyPointSummonRange
-- DESC      : 전략포인트 설정 주기 및 생성 초기화 프로시저.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitStrategyPointSummonRange
	@i_SummonRange					SMALLINT,
	@i_StrategyPointSummonCheck		TINYINT,
	@i_MaxSummonCountDaily			TINYINT
AS
	TRUNCATE TABLE	dbo.td_StrategyPointSummonInfo
	TRUNCATE TABLE	dbo.td_StrategyPointSummonRangeTimeInfo
	TRUNCATE TABLE	atum2_db_account_test.dbo.td_StrategyPointSummonRange
	INSERT INTO dbo.td_StrategyPointSummonInfo 
		SELECT MapIndex, 0, GetDATE(), NULL
		FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex
		WHERE MapIndex NOT IN (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo)

	IF(0=@i_StrategyPointSummonCheck)
	BEGIN
		INSERT INTO atum2_db_account_test.dbo.td_StrategyPointSummonRange
		VALUES(0, 0, 0)
	
		-- // 2008-01-09 by dhjin, DB 입력되는 날짜 형식 변경
		INSERT INTO dbo.td_StrategyPointSummonRangeTimeInfo
		VALUES('19000000 00:00:00', '19000000 00:00:00', 0, 0, 0)
	END
	ELSE
	BEGIN
		INSERT INTO atum2_db_account_test.dbo.td_StrategyPointSummonRange
		VALUES(@i_SummonRange, 1, @i_MaxSummonCountDaily)
		
		UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = SummonCount + 1

		INSERT INTO dbo.td_StrategyPointSummonRangeTimeInfo
		VALUES(GetDATE(), DateAdd(day, @i_SummonRange, GetDATE()), @i_SummonRange, @i_StrategyPointSummonCheck, @i_MaxSummonCountDaily)
	END
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointNotSummonTime
-- DESC      : 전략포인트 생성되면 안되는 시간 가져오는 프로시저
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointNotSummonTime
AS
	SELECT DayOfWeek, StartTime, EndTime, CheckSummon FROM atum2_db_account_test.dbo.td_StrategyPointNotSummonTime
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointNotSummonTime
-- DESC      : 전략포인트 생성되면 안되는 시간 업데이트 프로시저
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointNotSummonTime
	@i_SSunday				VARCHAR(30),
	@i_ESunday				VARCHAR(30),
	@i_CheckSummonSunday	TINYINT,
	@i_SMonday				VARCHAR(30),
	@i_EMonday				VARCHAR(30),
	@i_CheckSummonMonday	TINYINT,
	@i_STuesday				VARCHAR(30),
	@i_ETuesday				VARCHAR(30),
	@i_CheckSummonTuesday	TINYINT,
	@i_SWednesday			VARCHAR(30),
	@i_EWednesday			VARCHAR(30),
	@i_CheckSummonWednesday	TINYINT,
	@i_SThursday			VARCHAR(30),
	@i_EThursday			VARCHAR(30),
	@i_CheckSummonThursday	TINYINT,
	@i_SFirday				VARCHAR(30),
	@i_EFirday				VARCHAR(30),
	@i_CheckSummonFirday	TINYINT,
	@i_SSaturday			VARCHAR(30),
	@i_ESaturday			VARCHAR(30),
	@i_CheckSummonSaturday	TINYINT
AS
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SSunday, EndTime = @i_ESunday, CheckSummon = @i_CheckSummonSunday			WHERE DayOfWeek = 0
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SMonday, EndTime = @i_EMonday, CheckSummon = @i_CheckSummonMonday			WHERE DayOfWeek = 1
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_STuesday, EndTime = @i_ETuesday, CheckSummon = @i_CheckSummonTuesday		WHERE DayOfWeek = 2
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SWednesday, EndTime = @i_EWednesday, CheckSummon = @i_CheckSummonWednesday	WHERE DayOfWeek = 3
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SThursday, EndTime = @i_EThursday, CheckSummon = @i_CheckSummonThursday	WHERE DayOfWeek = 4
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SFirday, EndTime = @i_EFirday, CheckSummon = @i_CheckSummonFirday			WHERE DayOfWeek = 5
	UPDATE atum2_db_account_test.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SSaturday, EndTime = @i_ESaturday, CheckSummon = @i_CheckSummonSaturday	WHERE DayOfWeek = 6
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_UpdateCharacterWarPoint
-- DESC			 : WarPoint 업데이트
-- 2007-04-25 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateCharacterWarPoint
	@i_CharacterUID		INT,
	@i_AccountUID		INT,
	@i_WP				INT,
	@i_CumulativeWP		INT
AS
	UPDATE dbo.td_Character
		SET WarPoint = @i_WP, CumulativeWarPoint = @i_CumulativeWP
		WHERE UniqueNumber = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadArenaInfo
-- DESC			 : 아레나 정보 로드
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadArenaInfo
AS
	SELECT ArenaMode, ReqMemberNum, PayInfluencePointWIN, PayInfluencePointLOSE, PayWarPointWIN, PayWarPointLOSE
	FROM atum2_db_account_test.dbo.ti_ArenaInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadArenaMapInfo
-- DESC			 : 아레나 맵 정보 로드
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadArenaMapInfo
AS
	SELECT ArenaMapIndex, ArenaMode, ReqMemberNum, PlayLimitedTime, WINCondition, 
			LvDSupplyItemNum1, LvDSupplyItemCount1, LvDSupplyItemNum2, LvDSupplyItemCount2, LvDSupplyItemNum3, LvDSupplyItemCount3
	FROM atum2_db_account_test.dbo.ti_ArenaMapInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_UpdateCharacterArenaResult
-- DESC			 : Arena결과 업데이트
-- 2007-06-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateCharacterArenaResult
	@i_CharacterUID		INT,
	@i_AccountUID		INT,
	@i_WP				INT,
	@i_CumulativeWP		INT,
	@i_ArenaWin			INT,
	@i_ArenaLose		INT
AS
	UPDATE dbo.td_Character
		SET WarPoint = @i_WP, CumulativeWarPoint = @i_CumulativeWP, ArenaWin = @i_ArenaWin, ArenaLose = @i_ArenaLose
		WHERE UniqueNumber = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_UpdateCharacterArenaDisConnect
-- DESC			 : Arena 강제 종료 업데이트
-- 2007-06-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateCharacterArenaDisConnect
	@i_CharacterUID		INT,
	@i_AccountUID		INT,
	@i_ArenaDisConnect	INT
AS
	UPDATE dbo.td_Character
		SET ArenaDisConnect = @i_ArenaDisConnect
		WHERE UniqueNumber = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atumManager_GetMaxLevelCharacter
-- DESC			 : 2007-06-20 by cmkwon, 추가 - 최고 레벨 캐릭터 정보
--					예당 웹페이지에서 계정의 캐릭터를 보여주기위해 추가된 프로시저임
--					
-- parameter:
--		[1]	OUTPUT @o_RetCode		:리턴 코드(에러코드)
--									0	==> 에러 없음
--									100	==> 해당 계정의 캐릭터가 없음
--		[2]	OUTPUT @o_CharacterName	:캐릭터명
--		[3]	OUTPUT @o_PilotFace		:캐릭터의 인물 캐릭터
--									0		==> filename 0000.jpg
--									1		==> filename 0001.jpg
--									2		==> filename 0002.jpg
--									3		==> filename 0004.jpg
--									4		==> filename 0005.jpg
--									100		==> filename 0100.jpg
--									101		==> filename 0101.jpg
--									102		==> filename 0102.jpg
--									103		==> filename 0103.jpg
--									104		==> filename 0104.jpg
--		[4]	OUTPUT @o_Level			:캐릭터의 레벨
--		[5] INPUT  @i_AccountName	:검색할 계정명
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atumManager_GetMaxLevelCharacter
	@o_RetCode			INT				OUTPUT,
	@o_CharacterName	VARCHAR(20)		OUTPUT,
	@o_PilotFace		TINYINT			OUTPUT,
	@o_Level			TINYINT			OUTPUT,
	@i_AccountName		VARCHAR(20)
AS
	SET	@o_RetCode		= 0			--									0	==> 에러 없음

	SELECT TOP 1 @o_CharacterName= CharacterName, @o_PilotFace= PilotFace, @o_Level= Level
	FROM td_character WITH(NOLOCK)
	WHERE AccountName = @i_AccountName
	ORDER BY Experience DESC

	IF @o_CharacterName IS NULL
	BEGIN
		SET @o_RetCode	= 100		--									100	==> 해당 계정의 캐릭터가 없음
	END	
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadTutorialInfo
-- DESC			 : 
-- 2007-06-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTutorialInfo
AS
    SELECT TutorialUID, TutorialPayItem1, TutorialPayItemCount1, TutorialPayItem2, TutorialPayItemCount2, TutorialPayItem3, TutorialPayItemCount3
	FROM atum2_db_account_test.dbo.ti_TutorialInfo
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadTutorialComplete
-- DESC			 : 
-- 2007-06-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTutorialComplete
    @i_CharacterUID          INT
AS
    SELECT TutorialUID FROM dbo.td_TutorialComplete 
    WHERE CharacterUID = @i_CharacterUID
	ORDER BY TutorialUID DESC
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InsertTutorialComplete
-- DESC			 : 
-- 2007-06-28 by dhjin,
--					// 2007-11-16 by cmkwon, 테이블 Unique Key 설정한 것 데이터 추가시 체크 후에 추가 - td_tutorialComplete
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertTutorialComplete
    @i_CharacterUID          INT,
    @i_TutorialUID           INT
AS
	DECLARE @TutorialUID INT
	SET @TutorialUID = (SELECT TutorialUID FROM dbo.td_TutorialComplete WITH(NOLOCK) WHERE CharacterUID = @i_CharacterUID AND TutorialUID = @i_TutorialUID)

	IF @TutorialUID IS NULL
	BEGIN
		INSERT INTO dbo.td_TutorialComplete VALUES(@i_CharacterUID, @i_TutorialUID, GETDATE())
	END
	ELSE
	BEGIN
		UPDATE dbo.td_TutorialComplete
		SET TutorialCompleteTime = GETDATE()
		WHERE CharacterUID = @i_CharacterUID AND TutorialUID = @i_TutorialUID		
	END
GO


--!!!!
-- Name:dbo.atum_loadWarpableUserList
-- Desc: // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 로딩 프로시저 추가
--====
CREATE PROCEDURE dbo.atum_loadWarpableUserList
	@i_MapIndex				INT
AS
	SELECT c.UniqueNumber, c.CharacterName
	FROM td_user_list_warpable_to_map ul WITH(NOLOCK), td_character c WITH(NOLOCK)
	WHERE ul.MapIndex = @i_MapIndex AND ul.CharacterUID = c.UniqueNumber
GO

--!!!!
-- Name:dbo.atum_getCharacterUIDByCharacterName
-- Desc: // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - CharacterUID가져오기
--====
CREATE PROCEDURE dbo.atum_getCharacterUIDByCharacterName
	@i_CharacterName		VARCHAR(20),	
	@i_CharInflMask			TINYINT
AS
	-- #define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	SELECT UniqueNumber
	FROM td_character WITH(NOLOCK)
	WHERE CharacterName = @i_CharacterName AND 0 = Race & 0x4000 AND 0 <> InfluenceType & @i_CharInflMask
GO

--!!!!
-- Name:dbo.atum_insert2WarpableUserList
-- Desc: // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 유저 추가하기
--			#define ERR_NO_ERROR									0x0000
--			#define ERR_DB_INTEGRITY_CONSTRAINT_VIOLATION			0x2103		// integrity constraint violation, 23000
--====
CREATE PROCEDURE dbo.atum_insert2WarpableUserList
	@i_RetErr				INT		OUTPUT,		-- 0이면 No Error, 그 이외는 에러임
	@i_MapIndex				INT,
	@i_CharUID				INT
AS
	INSERT INTO dbo.td_user_list_warpable_to_map
	VALUES(@i_MapIndex, @i_CharUID)

	IF (@@Error <> 0)
	BEGIN
		SET @i_RetErr = 0x2103
	END
	ELSE
	BEGIN
		SET @i_RetErr = 0
	END

GO

--!!!!
-- Name:dbo.atum_deleteAllWarpableUserList
-- Desc: // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 모든 유저 삭제하기
--====
CREATE PROCEDURE dbo.atum_deleteAllWarpableUserList
AS
	DELETE FROM dbo.td_user_list_warpable_to_map
GO

--!!!!
-- Name:dbo.atum_deleteWarpableUser
-- Desc: // 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 유저 추가하기
--====
CREATE PROCEDURE dbo.atum_deleteWarpableUser
	@i_MapIndex				INT,
	@i_CharUID				INT
AS
	DELETE FROM dbo.td_user_list_warpable_to_map
	WHERE MapIndex = @i_MapIndex AND CharacterUID = @i_CharUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadOutPostInfo
-- DESC			 : 전진기지 정보 얻어오는 프로시저
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadOutPostInfo
AS
	SELECT O.OutPostMapIndex, O.OutPostCityMapIndex, O.OutPostGetTime, O.OutPostNextWarTime
			, O.OutPostNextWarTimeSet, O.OutPostGetInfl, O.OutPostGuildUID, G.GuildName
	FROM td_OutPostInfo AS O LEFT JOIN td_Guild AS G 
	ON O.OutPostGuildUID = G.GuildUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetNPCPossessionOutPost
-- DESC			 : 전진기지 NPC소유로 변경하는 프로시저
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetNPCPossessionOutPost
	@i_Mapindex					INT,
	@i_GetTime					DATETIME,
	@i_NextWarTime				DATETIME
AS
	UPDATE td_OutPostInfo SET OutPostGetTime = @i_GetTime, OutPostNextWarTime = @i_NextWarTime, OutPostNextWarTimeSet = 1, OutPostGetInfl = 0, OutPostGuildUID = 0
	WHERE OutPostMapIndex = @i_Mapindex
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetGuildPossessionOutPost
-- DESC			 : 전진기지 여단 소유로 변경하는 프로시저
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetGuildPossessionOutPost
	@i_Mapindex					INT,
	@i_Infl						TINYINT,
	@i_GuildUID					INT,
	@i_GetTime					DATETIME,
	@i_NextWarTime				DATETIME
AS
	UPDATE td_OutPostInfo 
	SET OutPostGetTime = @i_GetTime, OutPostNextWarTime = @i_NextWarTime, OutPostNextWarTimeSet = 0
						, OutPostGetInfl = @i_Infl, OutPostGuildUID = @i_GuildUID
	WHERE OutPostMapIndex = @i_Mapindex
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetOutPostNextWarTime
-- DESC			 : 다음 전진기지전 시간 변경하는 프로시저
-- 2007-08-09 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetOutPostNextWarTime
	@i_Mapindex					INT,
	@i_Infl						TINYINT,
	@i_GuildUID					INT,
	@i_NextWarTime				DATETIME
AS
	UPDATE td_OutPostInfo 
	SET OutPostNextWarTime = @i_NextWarTime, OutPostNextWarTimeSet = 1
	WHERE OutPostCityMapIndex = @i_Mapindex AND OutPostGetInfl = @i_Infl AND OutPostGuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadOutPostNextWarTime
-- DESC			 : 다음 전진기지전 시간 정보가져오는 프로시저
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadOutPostNextWarTime
AS
	SELECT OutPostWarStartTime
	FROM atum2_db_account_test.dbo.ti_OutPostNextWarTime WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_GetInfluenceLeaderGuildUID
-- DESC			 : 지도자 여단 UID가져오기
-- 2007-09-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetInfluenceLeaderGuildUID
	@i_LeaderUID				INT
AS
	SELECT GuildUniqueNumber FROM td_character
	WHERE UniqueNumber = @i_LeaderUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadCityLeaderInfo
-- DESC			 : 도시 정보 얻어오는 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadCityLeaderInfo
AS
	SELECT MapIndex, Influence, CharacterUID, ExpediencyFundCumulative, ExpediencyFund, ExpediencyFundRate, Notice
	FROM td_CityLeaderInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InitExpediencyFund
-- DESC			 : 판공비 정보 초기하는 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitExpediencyFund
	@i_MapIndex						INT,
	@i_Influence					TINYINT,
	@i_CharacterUID					INT,
	@i_ExpediencyFundCumulative		INT,
	@i_ExpediencyFund				INT,
	@i_ExpediencyFundRate			INT
AS
	DECLARE @tmCount INT
	SET @tmCount = (SELECT Count(*) FROM td_CityLeaderInfo WHERE MapIndex = @i_MapIndex)

	IF (0 = @tmCount)
	BEGIN
		INSERT INTO td_CityLeaderInfo VALUES(@i_MapIndex, @i_Influence, @i_CharacterUID, @i_ExpediencyFundCumulative
											, @i_ExpediencyFund, @i_ExpediencyFundRate, NULL)		
	END
	IF (1 = @tmCount)
	BEGIN
		UPDATE td_CityLeaderInfo
		SET	Influence = @i_Influence, CharacterUID = @i_CharacterUID, ExpediencyFundCumulative = @i_ExpediencyFundCumulative
			, ExpediencyFund = @i_ExpediencyFund, ExpediencyFundRate = @i_ExpediencyFundRate
		WHERE MapIndex = @i_MapIndex		
	END

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetExpediencyFund
-- DESC			 : 판공비 정보 설정하는 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetExpediencyFund
	@i_MapIndex						INT,
	@i_ExpediencyFund				INT,
	@i_ExpediencyFundCumulative		INT
AS
	UPDATE td_CityLeaderInfo
	SET	ExpediencyFundCumulative = @i_ExpediencyFundCumulative, ExpediencyFund = @i_ExpediencyFund
	WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetExpediencyFundPayBack
-- DESC			 : 판공비 환급 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetExpediencyFundPayBack
	@i_MapIndex						INT,
	@i_Influence					TINYINT,
	@i_CharacterUID					INT,
	@i_ExpediencyFund				INT
AS
	UPDATE td_CityLeaderInfo
	SET	ExpediencyFund = @i_ExpediencyFund
	WHERE MapIndex = @i_MapIndex AND Influence = @i_Influence AND CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_SetExpediencyFundRate
-- DESC			 : 판공비율 정보 설정하는 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SetExpediencyFundRate
	@i_MapIndex						INT,
	@i_Influence					TINYINT,
	@i_CharacterUID					INT,
	@i_ExpediencyFundRate			INT
AS
	UPDATE td_CityLeaderInfo
	SET	ExpediencyFundRate = @i_ExpediencyFundRate
	WHERE MapIndex = @i_MapIndex AND Influence = @i_Influence AND CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_DeleteCityLeaderInfo
-- DESC			 : 도시 정보 삭제 프로시저
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteCityLeaderInfo
	@i_MapIndex						INT,
	@i_Influence					TINYINT,
	@i_CharacterUID					INT
AS
	DELETE FROM td_CityLeaderInfo
	WHERE MapIndex = @i_MapIndex AND Influence = @i_Influence AND CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_RegNotice
-- DESC			 : 공지사항 등록 프로시저
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_RegNotice
	@i_MapIndex						INT,
	@i_CharacterUID					INT,
	@i_Notice						VARCHAR(512)
AS
	DECLARE	@CheckCount INT
	SET @CheckCount = (SELECT Count(*) FROM td_CityLeaderInfo WHERE MapIndex = @i_MapIndex)

	-- 공지사항 관련 값이 없을 경우를 대비하여 추가하는 루틴을 둔다.
	IF (@CheckCount = 0)
	BEGIN
	--  2007-10-18 by dhjin, 추가 없이 리턴한다.
    --	INSERT INTO	td_CityLeaderInfo VALUES(@i_MapIndex, @i_CharacterUID, 0,0,0,0, @i_Notice)		
		RETURN
	END

	IF (@CheckCount = 1)
	BEGIN
		UPDATE td_CityLeaderInfo SET Notice = @i_Notice
		WHERE MapIndex = @i_MapIndex AND CharacterUID = @i_CharacterUID
		RETURN
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_ModifyNotice
-- DESC			 : 공지사항 수정.삭제 프로시저
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ModifyNotice
	@i_MapIndex						INT,
	@i_CharacterUID					INT,
	@i_Notice						VARCHAR(512)
AS
	UPDATE td_CityLeaderInfo SET Notice = @i_Notice
	WHERE MapIndex = @i_MapIndex AND CharacterUID = @i_CharacterUID
GO


--!!!!
-- Name:
-- Desc: // 2007-09-12 by cmkwon, 베트남 2차패스워드 구현 - 2차패스워드 업데이트 프로시저
--====
CREATE PROCEDURE dbo.atum_UpdateSecondaryPassword
	@i_AccUID						INT,
	@i_SecPassword					VARCHAR(35)
AS
	UPDATE td_Account
	SET SecondaryPassword = @i_SecPassword
	WHERE AccountUniqueNumber = @i_AccUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_UpdateCityLeaderByLeaderSet
-- DESC			 : 지도자 설정 시 td_CityLeaderInfo에 정보 설정
-- 2007-09-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateCityLeaderByLeaderSet
	@i_Infltype				TINYINT,
	@i_Possess				INT
AS
	DECLARE @CountInfl INT
	SET @CountInfl = (SELECT count(*) FROM dbo.td_CityLeaderInfo WHERE Influence = @i_Infltype)

	IF @i_Infltype = 2 -- 바이제니유
	BEGIN
		UPDATE dbo.td_CityLeaderInfo
		SET	Influence = 2, CharacterUID = @i_Possess, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 10 + (@CountInfl * 5), Notice = NULL
		WHERE MapIndex = 2001
	END

	ELSE IF @i_Infltype = 4 -- 알링턴
	BEGIN
		UPDATE dbo.td_CityLeaderInfo
		SET	Influence = 4, CharacterUID = @i_Possess, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 10 + (@CountInfl * 5), Notice = NULL
		WHERE MapIndex = 2002
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InitCityLeaderForInflLeader
-- DESC			 : 세력 초기화 시 td_CityLeaderInfo에 지도자 관련 초기화한다.
-- 2007-09-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitCityLeaderForInflLeader
AS
	UPDATE dbo.td_CityLeaderInfo
	SET	Influence = 0, CharacterUID = 0, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 0, Notice = NULL
	WHERE MapIndex = 2001

	UPDATE dbo.td_CityLeaderInfo
	SET	Influence = 0, CharacterUID = 0, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 0, Notice = NULL
	WHERE MapIndex = 2002
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadActionByLevel
-- DESC				: 레벨 관련 값 가져오는 프로시저 (pollpoint등등)
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadActionByLevel
AS
	SELECT Level, PollPoint
	FROM atum2_db_account_test.dbo.ti_ActionByLevel
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadPollDate
-- DESC				: 투표 관련 기간, 투표일, 선출일등 가져오는 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadPollDate
AS
	SELECT ApplicationStartDate, ApplicationEndDate, VoteStartDate, VoteEndDate, Election
	FROM atum2_db_account_test.dbo.td_PollDate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdatePollDate
-- DESC				: 투표 관련 기간, 투표일, 선출일등 업데이트 프로시저
-- 2007-11-01 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdatePollDate
	@i_ApplicationStartDate		DATETIME,
	@i_ApplicationEndDate		DATETIME,
	@i_VoteStartDate			DATETIME,
	@i_VoteEndDate				DATETIME,
	@i_Election					DATETIME
AS
	UPDATE atum2_db_account_test.dbo.td_PollDate
	SET ApplicationStartDate = @i_ApplicationStartDate, ApplicationEndDate = @i_ApplicationEndDate
		, VoteStartDate = @i_VoteStartDate, VoteEndDate = @i_VoteEndDate, Election = @i_Election
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadVoterList
-- DESC				: 투표자 리스트 가져오는 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadVoterList
AS
	SELECT AccountUID, CharacterUID, LeaderCandidateNum
	FROM dbo.td_VoterList
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InitVoterList
-- DESC				: 투표자 리스트 초기화 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitVoterList
AS
	DELETE FROM dbo.td_VoterList
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertVoterList
-- DESC				: 투표자 등록 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertVoterList
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_LeaderCandidateNum	INT
AS
	INSERT INTO dbo.td_VoterList (AccountUID, CharacterUID, LeaderCandidateNum, PollDate) 
	VALUES (@i_AccountUID, @i_CharacterUID, @i_LeaderCandidateNum, GetDate())
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadLeaderCandidate
-- DESC				: 지도자 후보 리스트 가져오는 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadLeaderCandidate
AS
	SELECT LeaderCandidateNum, AccountUID, CharacterUID, CharacterName, GuildUID, GuildName, Influence, DeleteCandidate, PollCount, CampaignPromises
	FROM dbo.td_LeaderCandidate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InitLeaderCandidate
-- DESC				: 지도자 후보 리스트 초기화 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitLeaderCandidate
AS
	DELETE FROM dbo.td_LeaderCandidate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertLeaderCandidate
-- DESC				: 지도자 후보 등록 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertLeaderCandidate
	@o_RetCode					INT OUTPUT,
	@o_NewLeaderCandidateNum	INT OUTPUT,
	@i_ReqGuildMemberNum		INT,
	@i_ReqGuildFame				INT,
	@i_AccountUID				INT,
	@i_CharacterUID				INT,
	@i_CharacterName			VARCHAR(20),
	@i_GuildUID					INT,
	@i_GuildName				VARCHAR(30),
	@i_Influence				TINYINT,
	@i_CampaignPromises			VARCHAR(512)
AS
	DECLARE @CheckCount			INT
	DECLARE @ReqGuildMemberNum	INT
	DECLARE @GuildUID			INT
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_Guild WITH (NOLOCK) 
						WHERE GuildUniqueNumber = @i_GuildUID AND GuildCommanderUniqueNumber = @i_CharacterUID AND MonthlyFame >= @i_ReqGuildFame)
	IF(@CheckCount <> 1)
	BEGIN
		SET @o_RetCode = 10		-- 여단이 존재하지 않거나 요구 명성보다 작다.
		RETURN
	END
	
	SET @ReqGuildMemberNum = (SELECT Count(*) FROM dbo.td_GuildMember WITH (NOLOCK) WHERE GuildUniqueNumber = @i_GuildUID)
	IF(@ReqGuildMemberNum < @i_ReqGuildMemberNum)
	BEGIN
		SET @o_RetCode = 20		-- 여단이 존재하지 않거나 요구 여단 수보다 작다
		RETURN
	END

	SET @o_NewLeaderCandidateNum = (SELECT TOP 1 LeaderCandidateNum FROM dbo.td_LeaderCandidate WITH (NOLOCK) 
										WHERE Influence = @i_Influence ORDER BY LeaderCandidateNum DESC)
	SET @o_NewLeaderCandidateNum = @o_NewLeaderCandidateNum + 1
	INSERT INTO dbo.td_LeaderCandidate (LeaderCandidateNum, AccountUID, CharacterUID, CharacterName, GuildUID, GuildName, Influence, DeleteCandidate, PollCount, CampaignPromises) 
	VALUES (@o_NewLeaderCandidateNum, @i_AccountUID, @i_CharacterUID, @i_CharacterName, @i_GuildUID, @i_GuildName, @i_Influence, 0, 0, @i_CampaignPromises)

	SET @o_RetCode = 0
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateLeaderPollCount
-- DESC				: 투표자 획득 표 업데이트 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateLeaderPollCount
	@i_LeaderCandidateNum		INT,
	@i_Influence				TINYINT,
	@i_PollCount				INT
AS
	UPDATE dbo.td_LeaderCandidate SET PollCount = @i_PollCount WHERE LeaderCandidateNum = @i_LeaderCandidateNum AND Influence = @i_Influence
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateLeaderDeleteCandidate
-- DESC				: 지도자 후보 탈퇴 업데이트 프로시저
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateLeaderDeleteCandidate
	@i_CharacterUID		INT
AS
	UPDATE dbo.td_LeaderCandidate SET DeleteCandidate = 1 WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_SelectLeaderCandidateInfoByRealTimeVariable
-- DESC				: 지도자 후보의 실시간으로 변화 할 수 있는 변수값(level, guildfame등등) 얻어오는 프로시저
-- 2007-10-30 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SelectLeaderCandidateInfoByRealTimeVariable
	@i_AccountUID				INT,
	@i_CharacterUID				INT
AS
	SELECT C.Level, C.PilotFace, G.MonthlyFame, G.GuildMarkImage, G.GuildMarkSize
	FROM td_character AS C WITH(NOLOCK) INNER JOIN td_Guild AS G WITH(NOLOCK)
	ON C.UniqueNumber = G.GuildCommanderUniqueNumber
	WHERE C.UniqueNumber = @i_CharacterUID AND C.AccountUniqueNumber = @i_AccountUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_ConnectingServerGroupID_Of_Account
-- DESC				: // 2007-11-06 by cmkwon, 게임 로그 DB 서버 따로 구축하기 - 접속 정보 업데이트
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_ConnectingServerGroupID_Of_Account
	@i_AccUID				INT,
	@i_ServerGroupID		INT
AS
	UPDATE atum2_db_account_test.dbo.td_account
	SET ConnectingServerGroupID = @i_ServerGroupID
	WHERE AccountUniqueNumber = @i_AccUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGiveTargetCharacter
-- DESC				: // 2007-11-13 by cmkwon, 선물하기 기능 추가 - 선물 받는 캐릭터 정보 가져오기
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGiveTargetCharacter
	@i_CharName				VARCHAR(20)
AS
	--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
	SELECT a.AccountName, a.AccountUniqueNumber, a.ConnectingServerGroupID, am.ItemNum, am.ExpireTime, c.UniqueNumber, c.InfluenceType, c.GuildName, c.UnitKind, c.Level
	FROM td_account a WITH(NOLOCK) INNER JOIN td_character c WITH(NOLOCK) ON c.AccountUniqueNumber = a.AccountUniqueNumber
	LEFT OUTER JOIN td_accountCashStore am WITH(NOLOCK) ON a.AccountUniqueNumber = am.AccountUniqueNumber
	WHERE c.CharacterName = @i_CharName AND 0 = c.Race & 0x4000
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdatePilotFace
-- DESC				: // 2007-11-21 by cmkwon, PilotFace 변경 카드 구현 - 해당 캐릭터의 PilotFace를 수정한다.
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdatePilotFace
	@i_CharUID		INT,
	@i_PilotFace	TINYINT
AS
	UPDATE dbo.td_character
	SET PilotFace = @i_PilotFace
	WHERE UniqueNumber = @i_CharUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, 통지시스템 구현 - dbo.atum_InsertNotifyMsg 추가
--					  // 2007-12-20 by cmkwon, 통지시스템 버그 수정 - 추가된 NotifyMsgUID 를 리턴한다.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertNotifyMsg
	@i_CharacterUID				INT,							-- 통지 받을 CharacterUID
	@i_NotifyMsgType			TINYINT,						-- 통지 메시지 타입(NOTIFY_MSG_TYPE_XXX)
	@i_NotifyMsgString			VARCHAR(512),					-- 통지 메시지 스트링(512)
	@i_SenderCharacterUID		INT,							-- 통지를 보낸 CharacterUID
	@i_SenderCharacterName		VARCHAR(20)						-- 통지를 보낸 CharacterName
AS
	INSERT INTO dbo.td_NotifyMsg(CharacterUID, NotifyMsgType, NotifyMsgString, SenderCharacterUID, SenderCharacterName)
	VALUES(@i_CharacterUID, @i_NotifyMsgType, @i_NotifyMsgString, @i_SenderCharacterUID, @i_SenderCharacterName)

	RETURN SCOPE_IDENTITY();		-- // 2007-12-20 by cmkwon, 통지시스템 버그 수정 - 추가된 NotifyMsgUID 를 리턴한다.
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, 통지시스템 구현 - dbo.atum_GetNotifyMsg 추가
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetNotifyMsg
	@i_CharacterUID				INT								-- 통지 받을 CharacterUID
AS
	SELECT NotifyMsgUID, CharacterUID, NotifyMsgType, NotifyMsgString, SenderCharacterUID, SenderCharacterName, CreatedTime
	FROM dbo.td_NotifyMsg WITH(NOLOCK)
	WHERE CharacterUID = 0 OR CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, 통지시스템 구현 - dbo.atum_DeleteNotifyMsg 추가
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteNotifyMsg
	@i_NotifyMsgUID				BIGINT
AS
	DELETE dbo.td_NotifyMsg
	WHERE NotifyMsgUID = @i_NotifyMsgUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UseCouponNumber
-- DESC				: // 2008-01-10 by cmkwon, 아이템 이벤트 시스템에 신 쿠폰 시스템 추가 - dbo.atum_UseCouponNumber 추가
--						쿠폰 번호가 사용가능한 쿠폰번호 인지 체크하고 가능하면 사용된것으로 업데이트 한다.
--						#define ERR_PROTOCOL_QUEST_COUPON_INVALID_NUMBER				0x2710		// 쿠폰번호가 DB에 존재하지 않거나
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UseCouponNumber
	@i_CouponNumber				VARCHAR(30),
	@i_AccName					VARCHAR(20),
	@i_UseTime					VARCHAR(30)
AS
	DECLARE @CouponUID INT
	SET @CouponUID = (SELECT UniqueNumber FROM dbo.td_CouponList WITH(NOLOCK) WHERE CouponNumber = @i_CouponNumber AND UsedFlag = 0)
	IF @CouponUID IS NULL
	BEGIN
		RETURN 0x2710
	END

	UPDATE dbo.td_CouponList
	SET UsedFlag = 1, UsedAccountName = @i_AccName, UsedTime = @i_UseTime
	WHERE UniqueNumber = @CouponUID
	RETURN 0
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_admin_DeleteDeletedCharacter
-- DESC      : // 2008-01-17 by cmkwon, T_A: 삭제 상태의 캐릭터 영구히 삭제하는 기능 추가 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_DeleteDeletedCharacter
	@i_CharName			VARCHAR(20),
	@i_CharacterUID		INT
AS
	-- 2008-01-17 by cmkwon, 삭제된어진 상태의 캐릭터인지 체크
	IF NOT EXISTS( SELECT * FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharacterUID AND 0 <> (Race & 0x4000) )
		BEGIN
			RETURN	10			-- 삭제된 상태의 캐릭터가 아니다
		END
	
	-- 1. 캐릭터 소유 아이템의 인챈트 제거	
	DELETE td_Enchant FROM td_Store s INNER JOIN td_Enchant e ON s.UniqueNumber = e.TargetItemUniqueNumber
	WHERE s.Possess = @i_CharacterUID AND s.ItemStorage <> 2

	-- 2. 캐릭터 소유 아이템 제거
	DELETE FROM td_Store WHERE Possess = @i_CharacterUID AND ItemStorage <> 2

	-- 3. 캐릭터 퀵 슬롯 제거
	DELETE FROM td_QuickSlot WHERE CharacterUID = @i_CharacterUID

	-- 4. 캐릭터 소유 스킬 제거
	DELETE FROM td_StoreSkill WHERE Possess = @i_CharacterUID 

	-- 5. 퀘스트 테이블에서 제거
	DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber = @i_CharacterUID

	-- 6. 퀘스트 몬스터 정보 테이블에서 제거
	DELETE FROM td_CharacterQuestMonsterCount WHERE CharacterUniqueNumber  = @i_CharacterUID

	-- 7. 친구리스트에서 제거
	DELETE FROM td_FriendList
	WHERE CharacterName = @i_CharName OR FriendName = @i_CharName

	--8. 튜토리얼 리스트에서 제거
	DELETE FROM td_TutorialComplete WHERE CharacterUID = @i_CharacterUID

	-- last 캐릭터 테이블에서 제거
	DELETE FROM td_Character WHERE UniqueNumber = @i_CharacterUID


	RETURN 0
GO


--------------------------------------------------------------------------------
-- Name: dbo.atum_Delete_All_Character_By_AccountName
-- Desc: -- // 2008-02-13 by cmkwon, 계정 삭제 시스템 만들기 - atum2_db_[n].dbo.atum_Delete_All_Character_By_AccountName() 프로시저 추가
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_All_Character_By_AccountName
	@i_AccountName VARCHAR(20)        -- AccountName
AS

	DECLARE @CharacterCnt INT
	SET @CharacterCnt = (SELECT Count(*) FROM dbo.td_Character WITH (NOLOCK) WHERE AccountName = @i_AccountName)
	IF (@CharacterCnt IS NULL)
	BEGIN
		RETURN		-- // 2008-02-13 by cmkwon, 해당 계정의 캐릭터가 없다
	END

	DECLARE @CharUID INT
	DECLARE @CharName VARCHAR(20)
	SELECT TOP 1 @CharUID= UniqueNumber, @CharName= CharacterName FROM dbo.td_character WITH(NOLOCK) 
	WHERE AccountName = @i_AccountName ORDER BY UniqueNumber

	DECLARE @i INT
	SET @i				= 0

	WHILE (@i < @CharacterCnt)
	BEGIN
		IF (@CharUID IS NULL) OR (@CharName IS NULL)
		BEGIN
			RETURN
		END

		-- // 2008-02-13 by cmkwon, 삭제 상태의 캐릭터로 수정
		--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// 삭제된 캐릭터, 16384 // 2007-02-21 by cmkwon
		UPDATE dbo.td_character
		SET Race = Race | 0x4000
		WHERE UniqueNumber = @CharUID

		-- // 2008-02-13 by cmkwon, 삭제 상태의 캐릭터 바로 삭제
		DECLARE @RetCode INT		
		EXEC @RetCode = dbo.atum_admin_DeleteDeletedCharacter @CharName, @CharUID

		SELECT TOP 1 @CharUID= UniqueNumber, @CharName= CharacterName FROM dbo.td_Character WITH (NOLOCK) 
		WHERE AccountName = @i_AccountName AND UniqueNumber > @CharUID ORDER BY UniqueNumber

		SET @i			= @i + 1		
	END

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_updateCharacterInfo
-- DESC				: 아레나 통합 - 케릭터 정보 업데이트
-- 2007-12-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.arena_updateCharacterInfo
	@o_NewCharacterUID			INT OUTPUT,
	@i_NewCharacterName			VARCHAR(20),
	@i_CharacterUID				INT,
	@i_AccountUniqueNumber		INT			
AS
	-- // 
	IF EXISTS(SELECT * FROM atum2_db_arena_test.dbo.td_character WITH(NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber AND CharacterName = @i_NewCharacterName)
	BEGIN

		-- // 기존 데이터를 업데이트 한다.
		UPDATE atum2_db_arena_test.dbo.td_character
		SET	Race = sc.Race, UnitKind = sc.UnitKind, InfluenceType = sc.InfluenceType
			, PilotFace = sc.PilotFace, AttackPart = sc.AttackPart, DefensePart = sc.DefensePart, FuelPart = sc.FuelPart, SoulPart = sc.SoulPart
			, ShieldPart = sc.ShieldPart, DodgePart = sc.DodgePart, Level = sc.Level, BodyCondition = sc.BodyCondition, Propensity = sc.Propensity
			, Status = sc.Status, PKWinPoint = sc.PKWinPoint, PKLossPoint = sc.PKLossPoint, HP = sc.HP, DP = sc.DP, SP = sc.SP, EP = sc.EP
			, BonusStat = sc.BonusStat, BonusStatPoint = sc.BonusStatPoint, WarPoint = sc.WarPoint, CumulativeWarPoint = sc.CumulativeWarPoint
			, ArenaWin = sc.ArenaWin,	ArenaLose = sc.ArenaLose, ArenaDisConnect = sc.ArenaDisConnect
		FROM dbo.td_character sc, atum2_db_arena_test.dbo.td_character tc
		WHERE tc.AccountUniqueNumber = @i_AccountUniqueNumber AND tc.CharacterName = @i_NewCharacterName AND sc.UniqueNumber = @i_CharacterUID
	END
	ELSE
	BEGIN

		-- // atum2_db_arena_test.dbo.td_character 테이블에서 해당 캐릭터명으로 삭제 처리한다. - 동일한 캐릭터명이 존재 할 수 있다. 사용하지 않는 정보이다
		DELETE atum2_db_arena_test.dbo.td_character
		WHERE CharacterName = @i_NewCharacterName

		-- // 정보를 추가한다.
		INSERT INTO atum2_db_arena_test.dbo.td_character (CharacterName, AccountName, AccountUniqueNumber, Race, UnitKind, InfluenceType, PilotFace
					, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level
					, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, HP, DP, SP, EP, BonusStat
					, BonusStatPoint, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect)
			SELECT @i_NewCharacterName, AccountName, AccountUniqueNumber, Race, UnitKind, InfluenceType, PilotFace
				, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level
				, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, HP, DP, SP, EP
				, BonusStat, BonusStatPoint, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect
			FROM dbo.td_character
			WHERE UniqueNumber = @i_CharacterUID
	END

	SET @o_NewCharacterUID = (SELECT UniqueNumber FROM atum2_db_arena_test.dbo.td_character WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber AND CharacterName = @i_NewCharacterName)
GO	

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_GetCharacter
-- DESC				: 아레나 통합 - 케릭터 정보 로딩
-- 2007-12-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.arena_GetCharacter
	@acc	INT,
	@charac	INT
AS
	SELECT *
	FROM atum2_db_arena_test.dbo.td_Character
	WITH (NOLOCK)
	WHERE UniqueNumber=@charac AND AccountUniqueNumber = @acc
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_CopyDBInfo
-- DESC				: 아레나 통합 - 아레나 DB로 데이타 복사
-- 2008-01-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.arena_CopyDBInfo
	@o_RetCode					INT OUTPUT,
	@i_ArenaCharacterUID		INT,
	@i_CharacterUID				INT,
	@i_AccountUID				INT			
AS
	SET @o_RetCode = 0		--			0	==> 에러 없음

	DELETE FROM atum2_db_arena_test.dbo.td_enchant 
	WHERE TargetItemUniqueNumber IN (SELECT UniqueNumber FROM atum2_db_arena_test.dbo.td_store WHERE Possess = @i_ArenaCharacterUID)
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 30		--			30	==> 인첸트정보 삭제 실패
		RETURN              
	END
	DELETE FROM atum2_db_arena_test.dbo.td_store WHERE Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 40		--			40	==> 아이템정보 삭제 실패
		RETURN              
	END
	DELETE FROM atum2_db_arena_test.dbo.td_storeskill WHERE Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 70				--			70	==> 스킬 삭제 실패
		RETURN              
	END

-- td_character
	UPDATE atum2_db_arena_test.dbo.td_character
	SET	Race = sc.Race, UnitKind = sc.UnitKind, InfluenceType = sc.InfluenceType
		, PilotFace = sc.PilotFace, AttackPart = sc.AttackPart, DefensePart = sc.DefensePart, FuelPart = sc.FuelPart, SoulPart = sc.SoulPart
		, ShieldPart = sc.ShieldPart, DodgePart = sc.DodgePart, Level = sc.Level, BodyCondition = sc.BodyCondition, Propensity = sc.Propensity
		, Status = sc.Status, PKWinPoint = sc.PKWinPoint, PKLossPoint = sc.PKLossPoint, HP = sc.HP, DP = sc.DP, SP = sc.SP, EP = sc.EP
		, BonusStat = sc.BonusStat, BonusStatPoint = sc.BonusStatPoint, WarPoint = sc.WarPoint, CumulativeWarPoint = sc.CumulativeWarPoint
		, ArenaWin = sc.ArenaWin,	ArenaLose = sc.ArenaLose, ArenaDisConnect = sc.ArenaDisConnect
	FROM dbo.td_character sc, atum2_db_arena_test.dbo.td_character tc
	WHERE tc.AccountUniqueNumber = @i_AccountUID AND tc.UniqueNumber = @i_ArenaCharacterUID AND sc.UniqueNumber = @i_CharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 20		--			20	==> 아레나 서버에 케릭터 정보 업데이트 실패
		RETURN              
	END

-- td_storeskill
	INSERT atum2_db_arena_test.dbo.td_storeskill (AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime)
	SELECT AccountUniqueNumber, @i_ArenaCharacterUID, ItemWindowIndex, ItemNum, CreatedTime, NULL
	FROM dbo.td_storeskill
	WHERE Possess = @i_CharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 80				--			80	==> 스킬 추가 실패
		RETURN              
	END

-- td_store
	-- 창고와 캐릭터인벤의 아이템과 인챈트(td_Store, td_Enchant)
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL

	SELECT TOP 1 @SItemUID=UniqueNumber 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 ORDER BY UniqueNumber
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 50				--			50	==> 메인서버에서 아이템 정보 얻어오기 실패
		RETURN              
	END

	SELECT @SItemCnt=COUNT(*) 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 51				--			51	==> 메인서버에서 아이템 정보 얻어오기 실패
		RETURN              
	END
	IF (@SItemUID IS NULL)
	BEGIN 
		SET @o_RetCode = 52				--			52	==> 메인서버에서 아이템 정보 얻어오기 실패
		RETURN              
	END
	IF (@SItemCnt IS NULL)
	BEGIN 
		SET @o_RetCode = 53				--			53	==> 메인서버에서 아이템 정보 얻어오기 실패
		RETURN              
	END
	IF (@SItemCnt = 0)
	BEGIN 
		SET @o_RetCode = 54				--			54	==> 메인서버에서 아이템 정보 얻어오기 실패
		RETURN              
	END
	
	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			INSERT atum2_db_arena_test.dbo.td_store (AccountUniqueNumber, Possess, ItemStorage, Wear, CurrentCount, ScarcityNumber, ItemWindowIndex
					, ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime)
			SELECT AccountUniqueNumber,  @i_ArenaCharacterUID, ItemStorage, Wear, CurrentCount, ScarcityNumber, ItemWindowIndex
					, ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime
			FROM td_Store WITH(NOLOCK)
			WHERE UniqueNumber = @SItemUID
			IF (@@Error <> 0)
			BEGIN 
				SET @o_RetCode = 60			--			60	==> 아이템 추가 실패
				RETURN              
			END


			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- 인챈트가 존재하는 아이템은 타겟 서버군에 인챈트 추가
			IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_arena_test.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @o_RetCode = 61		--			61	==> 인첸트 추가 실패
					RETURN              
				END
			END

			--------------------------------------------------------------------------------
			-- 다음 아이템의 UID를 검색한다.
			SELECT TOP 1 @SItemUID= UniqueNumber 
			FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
			ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 AND UniqueNumber > @SItemUID 
			ORDER BY UniqueNumber
			IF (@SItemUID IS NULL)
			BEGIN 
				SET @o_RetCode = 62			--			62	==> 메인서버에서 아이템 정보 얻어오기 실패
				RETURN              
			END
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Insert_MSWar
-- DESC				: 모선전 로그 추가
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Insert_MSWar
	@i_LogType					TINYINT,
	@i_AttInfluence				TINYINT,
	@i_MonsterUID				INT,
	@i_ContributionPoint		INT,
	@i_MSWarStartTime			VARCHAR(30),
	@i_WinInfluence				TINYINT
AS
	INSERT INTO dbo.atum_log_MSWar(LogType, AttInfluence, MonsterUID, ContributionPoint, MSWarStartTime, MSWarEndTime, WinInfluence)
	VALUES(@i_LogType, @i_AttInfluence, @i_MonsterUID, @i_ContributionPoint, @i_MSWarStartTime, GetDate(), @i_WinInfluence)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Get_MSWar
-- DESC				: 모선전 로그 가져오기
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Get_MSWar
AS
	SELECT   AttInfluence, MonsterUID, ContributionPoint, MSWarStartTime, MSWarEndTime, WinInfluence
	FROM     dbo.atum_log_MSWar WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Insert_SPWar
-- DESC				: 거점전 로그 추가
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Insert_SPWar
	@i_LogType					TINYINT,
	@i_AttInfluence				TINYINT,
	@i_SPSummonMapIndex			INT,
	@i_SPWarStartTime			VARCHAR(30),
	@i_WinInfluence				TINYINT
AS
	INSERT INTO dbo.atum_log_SPWar(LogType, AttInfluence, SPSummonMapIndex, SPWarStartTime, SPWarEndTime, WinInfluence)
	VALUES(@i_LogType, @i_AttInfluence, @i_SPSummonMapIndex, @i_SPWarStartTime, GetDate(), @i_WinInfluence)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Get_SPWar
-- DESC				: 거점전 로그 가져오기
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Get_SPWar
AS
	SELECT   AttInfluence, SPSummonMapIndex, SPWarStartTime, SPWarEndTime, WinInfluence
	FROM     dbo.atum_log_SPWar WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_InitMSWar
-- DESC				: 모선전 리스트 초기화 프로시저
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_InitMSWar
AS
	DELETE FROM dbo.atum_log_MSWar
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_InitSPWar
-- DESC				: 거점전 리스트 초기화 프로시저
-- // 2008-04-01 by dhjin, 모선전, 거점전 정보창 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_InitSPWar
AS
	DELETE FROM dbo.atum_log_SPWar
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_MSWarOptionType
-- DESC				: 거점전 리스트 초기화 프로시저
-- // 2008-04-10 by dhjin, 모선전 정보 표시 기획안 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_MSWarOptionType
	@i_InfluenceType		TINYINT,
	@i_MSWarOptionType		SMALLINT
AS
	UPDATE dbo.td_InfluenceWarData SET MSWarOptionType = @i_MSWarOptionType WHERE InfluenceType = @i_InfluenceType
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadServerGroupInfo
-- DESC				: ServerGroup 관련 설정 로딩
-- // 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadServerGroupInfo
	@i_ServGroupID		INT
AS
	SELECT ServerGroupName, LimitUserCount, LockCreateCharacterForNewAccount
	FROM td_serverGroup WITH(NOLOCK)
	WHERE ServerGroupID = @i_ServGroupID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateServerGroupInfo
-- DESC				: ServerGroup 관련 설정 로딩
-- // 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateServerGroupInfo
	@i_ServGroupID							INT,
	@i_ServGroupName						VARCHAR(20),
	@i_LimitUserCount						INT,
	@i_LockCreateCharacterForNewAccount		INT
AS
	IF EXISTS(SELECT * FROM dbo.td_serverGroup WITH(NOLOCK) WHERE ServerGroupID = @i_ServGroupID)
	BEGIN
		UPDATE dbo.td_serverGroup
		SET ServerGroupName= @i_ServGroupName, LimitUserCount= @i_LimitUserCount, LockCreateCharacterForNewAccount= @i_LockCreateCharacterForNewAccount	
		WHERE ServerGroupID = @i_ServGroupID
	END
	ELSE
	BEGIN
		INSERT INTO dbo.td_serverGroup(ServerGroupID, ServerGroupName, LimitUserCount, LockCreateCharacterForNewAccount)
		VALUES(@i_ServGroupID, @i_ServGroupName, @i_LimitUserCount, @i_LockCreateCharacterForNewAccount)			
	END
		
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetNumOfCharacter
-- DESC				: 캐릭터의 개수를 가져온다. 삭제 상태의  캐릭터 포함.
-- // 2008-04-29 by cmkwon, 서버군 정보 DB에 추가(신규 계정 캐릭터 생성 제한 시스템추가) - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetNumOfCharacter
	@i_AccName			VARCHAR(20)
AS
	SELECT COUNT(*) 
	FROM dbo.td_character WITH(NOLOCK)
	WHERE AccountName = @i_AccName
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Delete_Letter_By_LetterPassedRangeDay
-- DESC		 : 유지 기간 지난 편지 삭제하기
-- // 2008-05-13 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_Letter_By_LetterPassedRangeDay
	@i_RecvCharacterUID		INT,
	@i_LetterPassedRangeDay	INT
AS
	DELETE FROM dbo.td_Letter WHERE RecvCharacterUID = @i_RecvCharacterUID AND (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay)
	DELETE FROM dbo.td_ReadAllLetter WHERE AllLetterUID IN (SELECT AllLetterUID FROM  dbo.td_AllLetter WITH (NOLOCK) WHERE (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay) )
	DELETE FROM dbo.td_AllLetter WHERE (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Get_Letter
-- DESC		 : 편지 가져오기
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_Letter
	@i_RecvCharacterUID		INT,
	@i_LetterPassedRangeDay	INT
AS
	SELECT LetterUID, SendCharacterName, SendDate, CheckRead, Title, Content FROM dbo.td_Letter WITH (NOLOCK) WHERE RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Send_Letter
-- DESC		 : 편지 보내기
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Send_Letter
	@o_Err					TINYINT	OUTPUT,
	@o_RecvCharacterUID		INT	OUTPUT,
	@i_RecvCharacterName	VARCHAR(20),
	@i_SendCharacterUID		INT,
	@i_SendCharacterName	VARCHAR(20),
	@i_SendDate				VARCHAR(30),
	@i_Title				VARCHAR(40),
	@i_Content				VARCHAR(1000)
AS
	DECLARE @CheckCount		INT
	SET @CheckCount = 0
	SET @o_Err = 0
	SET @o_RecvCharacterUID = 0

	-- 존재하는 유저인지 체크한다.
	SET @o_RecvCharacterUID = ( SELECT UniqueNumber FROM dbo.td_character WITH (NOLOCK) WHERE CharacterName = @i_RecvCharacterName )
	IF(@o_RecvCharacterUID IS NULL)
	BEGIN
		SET @o_Err = 1		-- 1 유저가 존재하지 않는다.
		RETURN
	END
	
	-- 자신 거부 체크
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_RecvCharacterName AND FriendName = @i_SendCharacterName )
	IF(0 <> @CheckCount)
	BEGIN
		SET @o_Err = 2		-- 2 거부 목록에 있는 유저이다.
		RETURN
	END	

	-- 상대방 거부 체크
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_SendCharacterName AND FriendName = @i_RecvCharacterName )
	IF(0 <> @CheckCount)
	BEGIN
		SET @o_Err = 3		-- 3 상대방이 나를 거부한 유저이다.
		RETURN
	END	

	-- 편지 추가
	INSERT INTO dbo.td_Letter (RecvCharacterUID, SendCharacterName, SendDate, CheckRead, Title, Content)
		VALUES (@o_RecvCharacterUID, @i_SendCharacterName, @i_SendDate, 0, @i_Title, @i_Content)

	RETURN SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Read_Letter
-- DESC		 : 편지 읽기
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Read_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	UPDATE dbo.td_Letter SET CheckRead = 1 WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Delete_Letter
-- DESC		 : 편지 삭제
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	DELETE FROM dbo.td_Letter WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Get_AllLetter
-- DESC		 : 전체 편지 가져오기
-- // 2008-05-09 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_AllLetter
	@i_RecvCharacterUID		INT,
	@i_RecvCharacterInfl	TINYINT,
	@i_LetterPassedRangeDay	INT
AS
	SELECT A.AllLetterUID, A.SendCharacterName, A.SendDate, A.Title, A.Content, 0 
		FROM dbo.td_AllLetter AS A WITH (NOLOCK)
		WHERE A.SendCharacterInfl = @i_RecvCharacterInfl AND A.AllLetterUID 
			NOT IN (SELECT AllLetterUID FROM dbo.td_ReadAllLetter AS R WITH (NOLOCK) WHERE R.RecvCharacterUID = @i_RecvCharacterUID)
		-- 전체 메일을 읽지 않음
	UNION
	SELECT A.AllLetterUID, A.SendCharacterName, A.SendDate, A.Title, A.Content, 1 
		FROM dbo.td_AllLetter AS A WITH (NOLOCK) INNER JOIN dbo.td_ReadAllLetter AS R WITH (NOLOCK) 
		ON A.SendCharacterInfl = @i_RecvCharacterInfl AND R.RecvCharacterUID = @i_RecvCharacterUID AND A.AllLetterUID = R.AllLetterUID AND 0 = R.CheckDelete
		-- 전체 메일을 읽었지만 삭제하지는 않음
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Send_AllLetter_ByLeader
-- DESC		 : 지도부에서 편지 발송으로 인한 편지 추가
-- // 2008-04-14 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Send_AllLetter_ByLeader
	@i_SendCharacterInfl	TINYINT,
	@i_SendCharacterUID		INT,
	@i_SendCharacterName	VARCHAR(20),
	@i_SendDate				DATETIME,
	@i_Title				VARCHAR(40),
	@i_Content				VARCHAR(1000)
AS
	-- 편지 추가
	INSERT INTO dbo.td_AllLetter (SendCharacterInfl, SendCharacterUID, SendCharacterName, SendDate, Title, Content)
		VALUES (@i_SendCharacterInfl, @i_SendCharacterUID, @i_SendCharacterName, @i_SendDate, @i_Title, @i_Content)
	RETURN SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Insert_ReadAllLetter_ByRead
-- DESC		 : 지도부에서 편지 발송 읽음
-- // 2008-05-08 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_ReadAllLetter_ByRead
	@i_AllLetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	INSERT INTO dbo.td_ReadAllLetter (AllLetterUID, RecvCharacterUID, CheckDelete)
		VALUES (@i_AllLetterUID, @i_RecvCharacterUID, 0)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Delete_ReadAllLetter
-- DESC		 : 지도부에서 편지 발송 삭제
-- // 2008-05-08 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_ReadAllLetter
	@i_AllLetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	DECLARE @CheckCount		INT
	SET @CheckCount = (SELECT count(*) FROM dbo.td_ReadAllLetter WHERE AllLetterUID = @i_AllLetterUID AND RecvCharacterUID = @i_RecvCharacterUID)

	IF(0 = @CheckCount)
	BEGIN
		INSERT INTO dbo.td_ReadAllLetter (AllLetterUID, RecvCharacterUID, CheckDelete)
			VALUES (@i_AllLetterUID, @i_RecvCharacterUID, 1)		
		RETURN
	END	 
	
	UPDATE dbo.td_ReadAllLetter SET CheckDelete = 1 WHERE AllLetterUID = @i_AllLetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Delete_AllLetter
-- DESC		 : 전체 편지 삭제
-- // 2008-05-09 by dhjin, EP3 편지시스템 - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_AllLetter
	@i_AllLetterUID			BIGINT
AS
	DELETE FROM dbo.td_ReadAllLetter WHERE AllLetterUID = @i_AllLetterUID
	DELETE FROM dbo.td_AllLetter WHERE AllLetterUID = @i_AllLetterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildRank
-- DESC				: 여단 랭크 가져오기
-- // 2008-05-30 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE atum_GetGuildRank
	@i_GuildUID			INT,	-- UINT
	@i_CharacterUID		INT
AS
	SELECT GuildRank
	FROM td_GuildMember
	WHERE CharacterUniqueNumber = @i_CharacterUID AND GuildUniqueNumber = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildCommander
-- DESC				: 여단장 위임
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildCommander
	@GuildUniqueNum INT,
	@Commander		INT,
	@NewCommander	INT
AS
	DECLARE @CheckBit	 TINYINT
	SET @CheckBit = (SELECT count(*) FROM dbo.td_CityLeaderInfo WITH (NOLOCK) WHERE CharacterUID = @Commander)
	IF(0 <> @CheckBit)
	BEGIN
		RETURN 1
	END
	SET @CheckBit = (SELECT count(*) FROM dbo.td_LeaderCandidate WITH (NOLOCK) WHERE CharacterUID = @Commander)
	IF(0 <> @CheckBit)
	BEGIN
		RETURN 2
	END

	UPDATE dbo.td_Guild SET GuildCommanderUniqueNumber = @NewCommander WHERE GuildUniqueNumber = @GuildUniqueNum
	UPDATE dbo.td_GuildMember SET GuildRank = 0	WHERE CharacterUniqueNumber = @Commander
	UPDATE dbo.td_GuildMember SET GuildRank = 1	WHERE CharacterUniqueNumber = @NewCommander
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildNotice
-- DESC				: 여단 공지
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildNotice
	@GuildUniqueNum INT,
	@Notice			VARCHAR(512)
AS
	UPDATE dbo.td_Guild SET Notice = @Notice WHERE GuildUniqueNumber = @GuildUniqueNum
GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildIntroduction
-- DESC				: 여단 소개 업데이트
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildIntroduction
	@i_GuildUID		INT,
	@i_WriteDate	VARCHAR(30),
	@i_Content		VARCHAR(512)
AS
	DECLARE @CheckBit	 TINYINT
	SET @CheckBit = (SELECT count(*) FROM dbo.td_GuildIntroduction WITH (NOLOCK) WHERE GuildUID = @i_GuildUID)
	IF(0 = @CheckBit)
	BEGIN
		INSERT INTO dbo.td_GuildIntroduction (GuildUID, Content, WriteDate)
			VALUES (@i_GuildUID, @i_Content, @i_WriteDate)	
		RETURN
	END

	UPDATE dbo.td_GuildIntroduction SET Content = @i_Content, WriteDate = @i_WriteDate WHERE GuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteGuildIntroduction
-- DESC				: 여단 소개 삭제
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteGuildIntroduction
	@i_GuildUID		INT
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @i_GuildUID
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteGuildIntroduction_By_PassedRangeDay
-- DESC				: 지난 여단 소개 삭제
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteGuildIntroduction_By_PassedRangeDay
	@i_PassedRangeDay	INT
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID IN 
				(SELECT GuildUID FROM dbo.td_GuildIntroduction WITH (NOLOCK) WHERE (DATEDIFF(dd, WriteDate, GETDATE()) > @i_PassedRangeDay ) )

	DELETE FROM dbo.td_GuildIntroduction WHERE (DATEDIFF(dd, WriteDate, GETDATE()) > @i_PassedRangeDay)
											   
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_SearchGuildIntroduction
-- DESC				: 여단 소개 전체 가져오기
-- // 2008-05-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_SearchGuildIntroduction
	@i_InfluenceType		TINYINT
AS
	SELECT G.GuildUniqueNumber, G.GuildName, GI.WriteDate, GI.Content, C.CharacterName
	FROM dbo.td_Guild AS G WITH (NOLOCK) INNER JOIN dbo.td_GuildIntroduction AS GI WITH (NOLOCK)
			ON G.GuildUniqueNumber = GI.GuildUID 
		INNER JOIN dbo.td_character AS C WITH (NOLOCK)
			ON C.UniqueNumber = G.GuildCommanderUniqueNumber
	WHERE C.InfluenceType = @i_InfluenceType
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildIntroduction
-- DESC				: 여단 소개 가져오기
-- // 2008-05-26 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGuildIntroduction
	@i_GuildUID					INT
AS
	SELECT Content, WriteDate FROM dbo.td_GuildIntroduction WITH (NOLOCK) WHERE GuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildApplicant
-- DESC				: 여단 지원자 가져오기
-- // 2008-05-26 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGuildApplicant
	@i_GuildUID					INT
AS
	SELECT S.CharacterUID, C.CharacterName, C.UnitKind, C.Level
	FROM dbo.td_SelfIntroduction AS S WITH (NOLOCK) INNER JOIN dbo.td_character AS C WITH (NOLOCK)
		ON C.UniqueNumber = S.CharacterUID
		WHERE S.GuildUID = @i_GuildUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetSelfIntroduction
-- DESC				: 자기 소개서 가져오기
-- // 2008-05-26 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetSelfIntroduction
	@i_CharacterUID					INT
AS
	SELECT G.GuildName, S.Content FROM dbo.td_Guild AS G WITH (NOLOCK) INNER JOIN dbo.td_SelfIntroduction AS S WITH (NOLOCK)
		ON G.GuildUniqueNumber = S.GuildUID
		WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteSelfIntroduction
-- DESC				: 자기 소개서 삭제
-- // 2008-05-26 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteSelfIntroduction
	@i_CharacterUID					INT
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateSelfIntroduction
-- DESC				: 자기 소개서 업데이트
-- // 2008-05-26 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateSelfIntroduction
	@i_TargetGuildUID				INT,
	@i_CharacterUID					INT,
	@i_Content						VARCHAR(512)
AS
	DECLARE @CheckBit	 TINYINT
	SET @CheckBit = (SELECT count(*) FROM dbo.td_SelfIntroduction WITH (NOLOCK) WHERE CharacterUID = @i_CharacterUID)
	IF(0 = @CheckBit)
	BEGIN
		INSERT INTO dbo.td_SelfIntroduction (GuildUID, CharacterUID, Content)
			VALUES (@i_TargetGuildUID, @i_CharacterUID, @i_Content)	
		RETURN 1;	
	END
	ELSE IF(2 <= @CheckBit)
	BEGIN
		RETURN 0;
	END

	UPDATE dbo.td_SelfIntroduction SET Content = @i_Content WHERE GuildUID = @i_TargetGuildUID AND CharacterUID = @i_CharacterUID
	RETURN 1;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Guild_Update_TotalFameRankByJob
-- DESC				: 총 여단 명성 순위
-- JOB				: 매일 아침시간으로 JOB을 건다.
-- // 2008-06-05 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Guild_Update_TotalFameRankByJob
AS
	UPDATE dbo.td_Guild SET GuildTotalFameRank = FG2.GuildTotalFameRank
	FROM dbo.td_Guild AS FG1,  
		(SELECT G1.GuildCommanderUniqueNumber, COUNT(G2.GuildCommanderUniqueNumber) + 1 AS GuildTotalFameRank
		FROM dbo.td_Guild AS G1 LEFT OUTER JOIN dbo.td_Guild AS G2
			ON G1.TotalFame < G2.TotalFame
		GROUP BY G1.GuildCommanderUniqueNumber) AS FG2
	WHERE FG1.GuildCommanderUniqueNumber = FG2.GuildCommanderUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Guild_Update_MonthlyFameRankByJob
-- DESC				: 월별 여단 명성 순위 
-- JOB				: 매일 아침시간으로 JOB을 건다.
-- // 2008-06-05 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Guild_Update_MonthlyFameRankByJob
AS
	UPDATE dbo.td_Guild SET GuildMonthlyFameRank = FG2.GuildMonthlyFameRank
	FROM dbo.td_Guild AS FG1,  
		(SELECT G1.GuildCommanderUniqueNumber, COUNT(G2.GuildCommanderUniqueNumber) + 1 AS GuildMonthlyFameRank
		FROM dbo.td_Guild AS G1 LEFT OUTER JOIN dbo.td_Guild AS G2
			ON G1.MonthlyFame < G2.MonthlyFame
		GROUP BY G1.GuildCommanderUniqueNumber) AS FG2
	WHERE FG1.GuildCommanderUniqueNumber = FG2.GuildCommanderUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Get_Guild_Master_CashStoreInfo
-- DESC				: 여단장 캐쉬 정보 얻어오기
-- // 2008-06-20 by dhjin, EP3 - 여단 수정 사항
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_Guild_Master_CashStoreInfo
	@GuildMasterUID			INT	
AS
	SELECT A.ExpireTime
		FROM td_Character AS C WITH (NOLOCK) INNER JOIN td_AccountCashStore AS A
			ON C.AccountUniqueNumber = A.AccountUniquenumber
		WHERE C.UniqueNumber = @GuildMasterUID	
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetUserInfo
-- DESC				: 유저 정보 가져오기
-- // 2008-06-20 by dhjin, EP3 유저정보옵션 -
--------------------------------------------------------------------------------
CREATE PROCEDURE atum_GetUserInfo
	@i_CharacterUID		INT
AS
	SELECT PilotFace, CharacterName, UnitKind, GuildName, GuildUniqueNumber, Level, MapIndex, ChannelIndex, Propensity, LastStartedTime, SecretInfoOption
	FROM dbo.td_character
	WHERE UniqueNumber = @i_CharacterUID
GO
