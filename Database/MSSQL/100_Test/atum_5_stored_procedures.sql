--------------------------------------------------------------------------------
-- functions
--------------------------------------------------------------------------------
CREATE FUNCTION dbo.atum_IsCountableItem(@ItemKind TINYINT)
RETURNS INT
AS
BEGIN
	-- #define ITEMKIND_ENERGY					(BYTE)18	// ��������, countable
	-- #define ITEMKIND_INGOT					(BYTE)19	// ���� & ����, countable
	-- #define ITEMKIND_CARD					(BYTE)20	// �Ϲ� ī��(���� �������� ����, 20040716, kelovon, ����ϰ� �Ǹ� �츲)
	-- #define ITEMKIND_ENCHANT				(BYTE)21	// ��æƮ ī��
	-- #define ITEMKIND_BULLET					(BYTE)23	// ź�˷�(=ź��), countable
	-- #define ITEMKIND_QUEST					(BYTE)24	// ����Ʈ�� ������, countable
	-- #define ITEMKIND_GAMBLE					(BYTE)27	// RareFix ������ ī��, ��æƮ�� ���� ��� ���
	-- #define ITEMKIND_PREVENTION_DELETE_ITEM	(BYTE)28	// ��æƮ �ÿ� ������ ���� ���� ������ 
	-- #define ITEMKIND_INFLUENCE_BUFF			(BYTE)33	// 2006-04-21 by cmkwon, ���� ����, ����� ���¹��� ������
	-- #define ITEMKIND_INFLUENCE_GAMEEVENT	(BYTE)34	// 2006-04-21 by cmkwon, ���� �����̺�Ʈ

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
-- ������ procedures
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

-- 2005-12-07 by cmkwon, ������� ����
----!!!!
---- Name:
---- Desc: â�� �־��ֱ�
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
		-- ������̸� charging�� count�� �Ҵ�
		INSERT INTO td_Store
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, i.Charging, 0, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
			FROM ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	ELSE
	BEGIN
		-- ������� �ƴϸ� �׳� @Count�� �Ҵ�
		INSERT INTO td_Store
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, @CurrentCount, 0, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
			FROM ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	RETURN SCOPE_IDENTITY();
GO

-- character���� ��� ����� ����
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

-- character���� ���� ������ �´� ����� ����
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

-- character���� ��� ��밡���� ��ų�� ����
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

-- character ������ ��� ������ ��ȯ
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

-- character ������ ��� ��ų ��ȯ
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

-- ���� ���� ����
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

-- ��� ĳ���� ���� - ���� ����
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
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
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
		WHERE c.charactername LIKE '���ݸ���' AND a.AccountName LIKE @CharacterName

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername LIKE @CharacterName)
	IF (@uniquenumber IS NOT NULL)
	BEGIN
		-- ���� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 07000070, 1, 1, 2
		-- ���� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
		-- �� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0

	END
GO

--------------------------------------------------------------------------------
-- �Ϲ� procedures
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
-- 		2005-06-30 5:19 by cmkwon, �� �⺻ ���� ������ ������
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
--		2006-09-14 by cmkwon, Demo ���� �⺻ ���� ������ ������
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
	-- AccountType ������ ����
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
		@bonusStat, @bonusSkillPoint, @lastPartyID, 0, 0, GetDate(), NULL,GetDate(), 0, 0, 0, 0, 0, 0, 0	-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
	)

	-- 2007-07-25 by cmkwon, ������ ĳ���ʹ� ����
	--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SET @nNumCharacter = (SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000)

	--///////////////////////////////////
	--// ������ ���� ��ġ(POS_XXX)
	--#define POS_PROW						((BYTE)0)	// ���̴�(���� ���)
	--#define POS_PROWIN					((BYTE)1)	// ��ǻ��(�߾� ����)
	--#define POS_PROWOUT					((BYTE)2)	// 1�� ����(���� ����)
	--#define POS_WINGIN					((BYTE)3)	//		������(�߾� ����)
	--#define POS_WINGOUT					((BYTE)4)	// 2�� ����(���� ����)
	--#define POS_CENTER					((BYTE)5)	// �Ƹ�(�߾� ���)
	--#define POS_REAR						((BYTE)6)	// ����(�Ĺ� ���)
	--#define POS_ATTACHMENT				((BYTE)7)	// ������(�Ĺ� ����-������ũ|�����̳ʰ迭)
	--#define POS_PET						((BYTE)8)	//		������(�Ĺ� ����)
	--#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
	--#define POS_ITEMWINDOW_OFFSET			((BYTE)100)	// 100, �� ��ȣ���� ������â�� ����
	--#define SIZE_MAX_POS					9			// ���� ������ slot�� ����

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WITH (NOLOCK) WHERE charactername LIKE @CharacterNameForSearch)
	IF (@uniquenumber IS NOT NULL)
	BEGIN
		-- ���� �� quest ����
		IF ( @UnitKind = 1)     -- BT, B-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001700, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E�� ���� ����
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002710, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900910, 400, 1, 4			-- �ʱ޿� ����
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 1, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 16)    -- OT, M-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001710, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E�� ���� ����
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002750, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900930, 400, 1, 4			-- �ʱ޿� ����
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 41, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- �Ƹ� - ����� 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 256)     -- DT, A-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001710, 1500, 0, 99
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 5, 0, 99			-- E�� ���� ����
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002770, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900940, 400, 1, 4			-- �ʱ޿� ����
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 61, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2�� ���� - ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- ��Ű ���̴�
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
			END
		ELSE IF ( @UnitKind = 4096)     -- ST, I-Gear
			BEGIN
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000790, 10, 0, 99			-- E�� ���� ����
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002740, 1, 1, 2
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6
--				EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900920, 400, 1, 4			-- �ʱ޿� �̻���
	--			INSERT INTO td_CharacterQuest VALUES (@uniquenumber, 21, 1)
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- ����
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
				EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- �Ƹ� - ���δ� 2005-12-03 by cmkwon
			END
		
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0		-- 2005-12-07 by cmkwon, �������� �� �߰� �ؾ���
		
		DECLARE @bIsRace	INT
		-- AccountType or Race ==> 128:������, 256:���ӿ��, 512:�����, 1024:�Խ�Ʈ, 2048:����
		-- ADMIN ���� ==> 2006-09-14 by cmkwon, ó������ ����, ���ӻ󿡼� ��� ���� ������
		--SET @bIsRace		= 128 & @AccoutTypeAppliedRace
		--IF (0 <> @bIsRace)
		--	BEGIN
		--	END

		-- DEMO ���� ==> 2006-09-14 by cmkwon, Level:50, SPI:5000000, ���ʽ�����:200, �⺻�����۸� ����
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
--		#define RACE_BATTALUS				(USHORT)0x0001	// ��Ż����, 1
--		#define RACE_DECA					(USHORT)0x0002	// ��ī, 2
--		#define RACE_PHILON					(USHORT)0x0004	// �ʷ�, 4
--		#define RACE_SHARRINE				(USHORT)0x0008	// ����, 8
--		#define RACE_INFLUENCE_LEADER		(USHORT)0x0010	// 16, ������ ����, 2006-04-20 by cmkwon, RACE_MONSTER1(����, 16)�� ������ ����
--		#define RACE_INFLUENCE_SUBLEADER	(USHORT)0x0020	// 32, ������ ��������, 2006-12-08 by cmkwon, RACE_MONSTER2(����, 32)�� ������ ���� ����, 32
--		#define RACE_NPC					(USHORT)0x0040	// NPC, 64
--		#define RACE_OPERATION				(USHORT)0x0080	// ������, 128
--		#define RACE_GAMEMASTER				(USHORT)0x0100	// ���Ӹ�����, 256
--		#define RACE_MONITOR				(USHORT)0x0200	// �����, 512
--		#define RACE_GUEST					(USHORT)0x0400	// �Խ�Ʈ, 1024
--		#define RACE_DEMO					(USHORT)0x0800	// �ÿ�(����)��, 2048
--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
--		#define RACE_ALL					(USHORT)0x000F	// ��� ����, (RACE_BATTALUS|RACE_DECA|RACE_PHILON|RACE_SHARRINE), 15
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
			-- 0.1. ĳ���Ͱ� ������ �������� atum_DeleteCharacter ȣ���ϱ� ���� ��� ���� ó���ȴ�
			-- 0.2. �ڽ��� ������� ���� atum_DeleteCharacter ȣ���ϱ� ���� IMServer�� ��� ������ �����Ѵ�
			
			-- 1. td_GuildMember ���̺��� �ڽ��� �����Ѵ�
			DELETE FROM td_GuildMember WHERE CharacterUniqueNumber = @CharUniqueNum
				
--	2007.2.23 by dhjin,	�ɸ��� ���� ��å���� ����.
--			-- 2. ����Ʈ ���̺��� ����
--			DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber = @CharUniqueNum
--			
--			-- 3. ģ������Ʈ���� ����
--			DELETE FROM td_FriendList WHERE CharacterName = @CharName OR FriendName = @CharName
--				
--			-- last ĳ���� ���̺��� ����
--			DELETE FROM td_Character WHERE UniqueNumber = @CharUniqueNum

			-- 2. ��� ���� ����
			UPDATE td_Character SET guildname = NULL, guilduniquenumber = 0 WHERE UniqueNumber = @CharUniqueNum

			-- 3. �ɸ��� ������ ����
			UPDATE td_Character SET Race = Race | 0x4000, LastStartedTime = GetDate() WHERE UniqueNumber = @CharUniqueNum	-- Race >= 16384 �̸� �ɸ��� ���� ��å���� �켱 ����.
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
	WHERE td_Character.AccountName LIKE @ID AND 0 = Race & 0x4000	-- Race >= 16384 ������ �ɸ���
GO

--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_GetCharacter
	@acc	INT,
	@charac	INT
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
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
	-- // 2007-07-30 by cmkwon, ���� ���� CharacterUID�θ� �˻�
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
--		// 2007-07-31 by cmkwon, ���� ����( <== @acc varchar(64), @charname varchar(64) ) - ������ like ����� ���� �ʴ°����� ����
--====
CREATE PROCEDURE dbo.atum_GetChatCharacterInfoByName
	@acc		varchar(20),
	@charname	varchar(20)
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
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
-- Desc:// 2007-07-31 by cmkwon, �߰���
--====
CREATE PROCEDURE dbo.atum_admin_GetCharacterByCharacterName
	@i_CharName	VARCHAR(20)
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
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
--		2006-04-10 by cmkwon, �Ķ���� �߰�(@i_DownSPIOnDeath	INT,			-- 2006-04-10 by cmkwon)
--		2006-11-15 by cmkwon, ���� 2�� �߰�
--						@i_GameContinueTimeInSecondOfToday	INT,			-- 2006-11-15 by cmkwon, ���� �Ϸ� ���� ���� �ð�
--						@i_LastGameEndDate					VARCHAR(30)		-- 2006-11-15 by cmkwon, ������ ���� ���� ��¥�ð�
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
	@i_GameContinueTimeInSecondOfToday	INT,			-- 2006-11-15 by cmkwon, ���� �Ϸ� ���� ���� �ð�
	@i_LastGameEndDate					VARCHAR(30),	-- 2006-11-15 by cmkwon, ������ ���� ���� ��¥�ð�
	@i_PCBangtotalPlayTime	BIGINT,						-- 2007-06-07 by dhjin, PC�� �� �÷��� �ð�
	@i_SecretInfoOption		INT				-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
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
		SecretInfoOption	= @i_SecretInfoOption				-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
	WHERE UniqueNumber = @i_CharacterUID
	
	--------------------------------------------------------------------------------
	-- 2006-11-15 by cmkwon
	-- td_account ���̺� �������ӽð�, ������ ���� ����ð��� ������Ʈ �Ѵ�.
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
-- Desc: 2005-11-15 by cmkwon, Level Up �̿��� ������� �߰��� ���ʽ� ���� ��ġ ���� ��
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
-- 2005-11-15 by cmkwon, BonusSkillPoint�� BonusStatPoint�� �����ϸ鼭 �ʿ������
--	@bskillpoint	TINYINT
AS
	UPDATE td_Character
		SET Level = @level, BonusStat = @bstat, LevelUpTime = GetDate()
		WHERE  UniqueNumber = @UniqueNumber;
-- 2005-11-15 by cmkwon, BonusSkillPoint�� BonusStatPoint�� �����ϸ鼭 �ʿ������
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
-- Desc:���¼��ý� ������ ����ȴ�.
--		2005-12-07 by cmkwon, ��� ĳ������ SelectableInfluenceMask�� ������Ʈ �Ѵ�.
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
-- CHAT ����
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
-- ITEM ����
--------------------------------------------------------------

--!!!!
-- Name:
-- Desc:
--		2005-12-07 by cmkwon, ������ġ
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

-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
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
--		2005-12-07 by cmkwon, ������ġ �ʵ� �߰�
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
	@ColorCode			INT,			-- 2005-11-21 by cmkwon, �Ƹ� Ʃ�׽� Į��
	@UsingTimeStamp		INT
AS
	INSERT INTO td_Store
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ScarcityNumber, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, GetDate())
	RETURN SCOPE_IDENTITY();
GO

-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν�����
--!!!!
-- Name:
-- Desc:
--====
--CREATE PROCEDURE dbo.atum_MoveItemPossessCountable
--	@ret					BIGINT OUTPUT, -- ���� ���ԵǾ��ٸ� uniquenumber, �ƴϸ� -1
--	@accNum					INT,
--	@ToPossessCharacter		INT,	-- CharacterUniqueNumber OR 0
--	@ItemNum				INT,	-- �������� ����
--	@ItemUniqueNumber		BIGINT,
--	@CurrentCount			INT,
--	@RemainedCount			INT
--AS
--	DECLARE @ToItemUniqueNumber	BIGINT	-- ToItem, ������ NULL
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

-- 2005-12-07 by cmkwon, �ʿ����
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
-- Desc:	2005-12-07 by cmkwon, �������� ���� ��ġ ����(ĳ�����κ�->â��, â��->ĳ�����κ�)
--====
CREATE PROCEDURE dbo.atum_UpdateItemStorage
	@i_ItemUniqueNumber		BIGINT,
	@i_ItemCharacterUID     INT,		-- 2006-09-19 by dhjin, ���õ� �ɸ���
	@i_ItemStorage			TINYINT		-- 0(ITEM_IN_CHARACTER):ĳ�����κ�, 1(ITEM_IN_STORE):â��
AS
	UPDATE td_Store
		SET ItemStorage = @i_ItemStorage, Possess = @i_ItemCharacterUID
		WHERE UniqueNumber = @i_ItemUniqueNumber
GO

-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
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
-- Desc:2006-06-14 by cmkwon, �߰���
--			�ٸ����� �������� �ʰ� ItemNum�� �����Ѵ�. ����,��æƮ�� �����ȴ�.
--====
CREATE PROCEDURE dbo.atum_UpdateItemNum
	@UniqueNumber	BIGINT,
	@ItemNum		INT
AS
	UPDATE td_store
		SET ItemNum = @ItemNum
		WHERE UniqueNumber = @UniqueNumber
GO


-- 2005-11-21 by cmkwon, ������
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
--		�Ƹ� �������� Į�� �ؽ��� �ڵ� ������Ʈ
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
--			2005-12-08 by cmkwon, �ƸӸ� ���� colorcode�� �����´�.
--			2007-01-19, #define ITEM_IN_CHARACTER				0	// ĳ�����κ�
--						#define ITEM_IN_STORE					1	// â��
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--
--						#define POS_PROW						((BYTE)0)	// ���̴�(���� ���)	--> ���� 2��
--						#define POS_PROWIN						((BYTE)1)	// ��ǻ��(�߾� ����)	--> ���� 2��
--						#define POS_PROWOUT						((BYTE)2)	// 1�� ����(���� ����)	--> ���� 1��
--						#define POS_WINGIN						((BYTE)3)	// 2006-07-20 by cmkwon, ����Ʈ ������ (�߾� ����)
--						#define POS_WINGOUT						((BYTE)4)	// 2�� ����(���� ����)	--> ���� 1��
--						#define POS_CENTER						((BYTE)5)	// �Ƹ�(�߾� ���)	--> ���� 4��
--						#define POS_REAR						((BYTE)6)	// ����(�Ĺ� ���)	--> ���� 3��
--						#define POS_ATTACHMENT					((BYTE)7)	// 2006-03-30 by cmkwon, ������ �Ǽ��縮 - ������(�Ĺ� ����-������ũ|�����̳ʰ迭) --> ���� 3��
--						#define POS_PET							((BYTE)8)	// 2006-03-30 by cmkwon, �ð����� �Ǽ��縮(�Ĺ� ����)	--> ���� 4��
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
-- td_Enchant ����
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


-- 2007-01-30 by cmkwon, �ʿ� ��� �ּ� ó���� - atum_GetEnchantBYItemUID() ���ν����� ��ü��
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
-- Quest ����
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
--			// 2007-11-16 by cmkwon, ���̺� Unique Key ������ �� ������ �߰��� üũ �Ŀ� �߰� - td_characterQuest
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
	@i_QuestPlayTimeStamp		BIGINT		-- 2006-08-31 by cmkwon, �߰���
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
-- 2005-10-19 by cmkwon, ����Ʈ ���� ī���� ����

--!!!!
-- Name:
-- Desc:ĳ������ ��� ���� ī��Ʈ�� �˻��Ѵ�.
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
-- Desc:����Ʈ ���� ī��Ʈ�� �߰� Ȥ�� ����
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
-- Desc:����Ʈ ���� ī��Ʈ ����
--====
CREATE PROCEDURE dbo.atum_DeleteQuestMonsterCount
	@CharacterUniqueNumber		INT,
	@QuestIndex					INT
AS
	DELETE FROM td_CharacterQuestMonsterCount
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO


-- End_����Ʈ ���� ī���� ����
-----------------------------------------------------------------------------


--------------------------------------------------------------
-- SKILL ����
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
--			2007-01-19, #define ITEM_IN_CHARACTER				0	// ĳ�����κ�
--						#define ITEM_IN_STORE					1	// â��
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--====
CREATE PROCEDURE dbo.atum_DeleteAllCharacterItems
	@i_AccountUID INT,
	@i_CharacterUID INT
AS
	IF (@i_CharacterUID = 0)
		RETURN

	-- 1. ĳ���� ���� �������� ��æƮ ����	
	DELETE td_Enchant FROM td_Enchant e, td_Store s 
		WHERE s.AccountUniqueNumber = @i_AccountUID AND s.ItemStorage <> 2 AND s.Possess = @i_CharacterUID AND s.UniqueNumber = e.TargetItemUniqueNumber
	
	-- 2. ĳ���� ���� ������ ����
	DELETE FROM td_Store WHERE AccountUniqueNumber = @i_AccountUID AND ItemStorage <> 2 AND possess = @i_CharacterUID
	
	-- 3. ĳ���� �� ���� ����
	DELETE FROM td_QuickSlot WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
	
	-- 4. ĳ���� ���� ��ų ����
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

-- 2006-10-20 by cmkwon, ������� �ʴ� ���ν���, �Ʒ��� �ΰ��� ���ν��� �ΰ��� ����� ����
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
-- Desc:2006-10-20 by cmkwon, ���� ��� BuildingIndex�� ��������
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
-- Desc:2006-10-20 by cmkwon, BuildingIndex�� ������ ��������
--		// 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder ������ ���� ������ ����Ʈ�� �����´�.
--====
CREATE PROCEDURE dbo.atum_GetShopItems
	@BuildingIndex INT
AS
	-- // 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder ������ ���� ������ ����Ʈ�� �����´�.
	SELECT i.itemnum, i.itemname, i.MinTradeQuantity, i.price, i.kind
		FROM ti_Item i WITH(NOLOCK), ti_Shop s WITH(NOLOCK)
		WHERE i.itemnum = s.itemnum AND @buildingIndex = s.uniquenumber
		ORDER BY s.ShopOrder
GO


-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
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
-- ������ Trade
--------------------------------------------------------------------------------
--!!!!
-- Name:
-- Desc:
--====
CREATE PROCEDURE dbo.atum_TradeMoveItem
	@ToCharacter			INT,
	@ToAccount				INT,
	@FromCharacter			INT,
	@ItemUniqueNumber		BIGINT			-- 2006-05-11 by cmkwon, INT�� ������
AS
	UPDATE td_Store
		SET AccountUniqueNumber = @ToAccount, Possess = @ToCharacter, Wear = 0, ItemWindowIndex = 99
		WHERE UniqueNumber = @ItemUniqueNumber AND Possess = @FromCharacter
GO


--!!!!
-- Name:
-- Desc:������ �ŷ��� ī���ͺ� ������ ó��
--		2005-11-21 by cmkwon, ColorCode�� �Ƹӿ��� ���ǹǷ� �ŷ��� 0���� �����Ѵ�.
--====
CREATE PROCEDURE dbo.atum_TradeMoveItemCountable
	@ToCharacter			INT,
	@ToAccount				INT,
	@FromCharacter			INT,
	@FromItemUniqueNumber	BIGINT,
	@Amount					INT,		-- �ŷ���
	@RemainedCount			INT,		-- �ִ� �������� ���� ��
	@ToItemUniqueNumber		BIGINT OUTPUT,		-- 0: �޴� ���� ���� �������� ����, else: �޴� �ʿ� �������� ������(�޴� ������ ������ȣ)
	@FromItemNum			INT			-- spi���� �ƴ��� Ȯ���ؼ�, spi�̸� ���� ���� 0�̴��� ������ �ʴ´�!
AS

	-- �������� �޴� �� ó��
	IF (@ToItemUniqueNumber = 0)
	BEGIN
		-- ���� ĳ���Ͱ� �ش� �������� �������� ���� ���
		INSERT INTO td_Store
			SELECT @ToAccount, @ToCharacter, 0, 0, @Amount, s.ScarcityNumber, 100,
						s.ItemNum, 0, s.PrefixCodeNum, s.SuffixCodeNum, s.CurrentEndurance, 0, 0, GetDate()
			FROM td_Store s
			WHERE s.UniqueNumber = @FromItemUniqueNumber AND s.Possess = @FromCharacter

		SET @ToItemUniqueNumber = SCOPE_IDENTITY()
	END
	ELSE
	BEGIN
		-- ���� ĳ���Ͱ� �ش� �������� �̹� ������ ���
		UPDATE td_Store
			SET CurrentCount = CurrentCount + @Amount
			WHERE UniqueNumber = @ToItemUniqueNumber AND Possess = @ToCharacter
	END

	-- �������� �ִ� �� ó��
	IF (@RemainedCount > 0 OR @FromItemNum = 7000022)
	BEGIN -- �ܵ� statement�� �ƴ� �� ���, ���⼭�� ���� ������ ���� �̸� �����
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
--====	2005-12-27 by cmkwon, td_Guild�� �ʵ� �ΰ� �߰��Ѱ� ����
--		// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �ʵ� �߰�(GuildMarkState)
--			#define GUILD_MARK_STATE_NONE					((BYTE)0)	// ��ũ ���� ����
--			#define GUILD_MARK_STATE_WAITING_PERMISSION		((BYTE)1)	// ��ũ ����� ��ٸ��� ����, ���ӻ󿡼��� ��� �Ұ�
--			#define GUILD_MARK_STATE_NORMAL					((BYTE)2)	// ��ũ ��� ���� ����
--DROP PROCEDURE atum_CreateGuild
--GO
CREATE PROCEDURE dbo.atum_CreateGuild
	@name			VARCHAR(30),
	@commander		INT,
	@capacity		INT
AS
	-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����, // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �ʵ� �߰�(GuildMarkState)
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
	-- ���� ����
	INSERT INTO td_GuildMember VALUES(@guildUniqueNum, @characUniqueNum, @guildRank, GetDate())
	
	DECLARE @GuildName VARCHAR(30)
	SET @GuildName = (SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNum)

	-- ĳ������ ��� ���� ������Ʈ
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
	-- �������� ����
	DELETE td_GuildMember WHERE characterUniqueNumber = @characUniqueNum

	-- ĳ������ ��� ���� ����
	UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		WHERE uniquenumber = @characUniqueNum
GO

--!!!!
-- Name:
-- Desc:
--		// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �ʵ������ ��� �˻� ó���ϸ� �ʵ� �߰���
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
	-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
	SELECT c.CharacterName, c.UniqueNumber, gm.GuildRank, c.UnitKind, c.Level
	FROM td_Character c, td_GuildMember gm
	WHERE c.UniqueNumber = gm.CharacterUniqueNumber AND gm.GuildUniqueNumber = @guildUniqueNum
GO



--!!!!
-- Name: atum_Guild_UpdateMemberCapacity
-- Desc: ��� ���� �ο� ����
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
-- Desc: ��� �ػ� ��û�� ����� ����(�ػ���) ���� �� �ػ� ��¥ ����
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

	-- // 2008-06-13 by dhjin, EP3 - ���� ���� ����
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @guildUniqueNum
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @guildUniqueNum
GO


--!!!!
-- Name: atum_CancelDismember
-- Desc: ��� �ػ� ���
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
-- Desc: ��� ���� ����
--====
--DROP PROCEDURE atum_DismemberGuild
--GO
CREATE PROCEDURE dbo.atum_DismemberGuild
	@guildUniqueNum		INT	-- UINT
AS
	-- ��� ����
	DELETE FROM td_Guild WHERE GuildUniqueNumber = @guildUniqueNum

	-- ���� ����
	DELETE FROM td_GuildMember WHERE GuildUniqueNumber = @guildUniqueNum
	
	-- 2007-11-02 by jin, ������ �ĺ��̸� ����
	DELETE FROM td_LeaderCandidate WHERE GuildUID = @guildUniqueNum

	-- ĳ���� ���� ����
	UPDATE td_Character
	SET guildname = NULL, guilduniquenumber = 0
	WHERE guilduniquenumber = @guildUniqueNum

	-- // 2008-06-13 by dhjin, EP3 - ���� ���� ����
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @guildUniqueNum
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @guildUniqueNum
GO

--!!!!
-- Name: atum_ChangeGuildRank
-- Desc: ��� ��� ����
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
-- Desc: ��� �̸� ����
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
-- Desc: ��� ��ũ ��������
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
-- Desc: ��� ��ũ �Ҵ�
--====
--			// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �����߰�(@i_guildMarkState		TINYINT)
--DROP PROCEDURE atum_SetGuildMark
--GO
CREATE PROCEDURE dbo.atum_SetGuildMark
	@guildUniqueNumber		INT,	-- UINT
	@guildMarkSize			INT,
	@guildMarkImage			BINARY(1600),
	@i_guildMarkState		TINYINT			-- // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �����߰�(@i_guildMarkState		TINYINT)
AS
	DECLARE @GuildMarkVersion INT
	SET @GuildMarkVersion = (SELECT GuildMarkVersion FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNumber) + 1

	-- // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - Update�� �߰���
	UPDATE td_Guild
	SET GuildMarkVersion = @GuildMarkVersion, GuildMarkSize = @guildMarkSize, GuildMarkImage = @guildMarkImage, GuildMarkState= @i_guildMarkState
	WHERE GuildUniqueNumber = @guildUniqueNumber
	
	RETURN @GuildMarkVersion
GO

-- Name: atum_GuildAddGuildFame
-- Desc: 2005-12-28 by cmkwon, ���� �� ���ϱ�
--====
CREATE PROCEDURE dbo.atum_GuildAddGuildFame
	@i_guildUID				INT,	-- UINT
	@i_totalFameAddition	INT,	-- �߰���
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
-- Desc: 2006-01-02 by cmkwon, �Ŵ� ó���ϴ� �� - ���� �Ѵ� ���� �� ó��
--			�Ѵ� ���� �� 10�������� �˻�
--			�ְ� ���� �� �����忡�� 14-���强 ��� �����ϱ�(���� ���强�� 0-�Ʒ� ��������� ����, �ڵ� �缳����)
--====
CREATE PROCEDURE dbo.atumManager_DoMonthlyWork_ProcessMontylyGuildFame
AS
	-- �Ѵ� ���� �� 10�������� �˻�
	SELECT TOP 10 g.GuildName, g.GuildUniqueNumber as GuildUID, c.CharacterName as GuildMasterCharacterName
				, g.GuildCommanderUniqueNumber as GuildMasterCharacterUID, g.TotalFame, g.MonthlyFame
		FROM td_Guild g, td_character c WITH (NOLOCK)
		WHERE g.GuildCommanderUniqueNumber = c.uniquenumber
		ORDER BY MonthlyFame desc
	
	-- ���� ����� 14(���强) ������ ����� 0(�Ʒ� �����)���� ����
	UPDATE td_Character
		SET Status = 0
		WHERE Status = 14

	-- �Ѵ� ���� �� �ְ� �����忡�� ��� 14(���强)�� ����
	DECLARE @GuildMasterCharUID INT
	SET @GuildMasterCharUID = (SELECT TOP 1 GuildCommanderUniqueNumber FROM td_Guild WITH (NOLOCK) ORDER BY MonthlyFame desc)
	UPDATE td_Character
		SET Status = 14
		WHERE UniqueNumber = @GuildMasterCharUID
GO

-- Name: atumManager_DoMonthlyWork_ResetMontylyGuildFame
-- Desc: 2006-01-02 by cmkwon, �Ŵ� ó���ϴ� �� - ���� �Ѵ� ���� �� �ʱ�ȭ
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
-- Desc: ����� ��û ����
-- Returns: ��û ����, 0 �����̸� ����
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
	@i_RegDate						VARCHAR(30)			-- // 2008-04-11 by dhjin, EP3 �źθ�� -
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

-- 2005-11-21 by cmkwon, Auction�� ������� �����Ƿ� �ּ� ó����
----------------------------------------------------------------------------------
---- AUCTION, ��ǰ ���� ����
----------------------------------------------------------------------------------
--
----!!!!
---- Name: atum_AuctionGetRegisterCount
-- Desc: ��ǰ ���� ������ ������ ���
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
---- Desc: ��ǰ ���� ������ ������ ���
----====
--CREATE PROCEDURE dbo.atum_AuctionRegisterItem
--	@i_AuctionItemKind				TINYINT,	-- ������ ����, AtumProtocol.h�� AUCTION_KIND_XXX ����
--	@i_AuctionPrice					INT,		-- ��Ű�
--	@i_AuctionItemUID				BIGINT,		-- ������ ���� ��ȣ, td_Store.UniqueNumber
--	@i_AuctionAccountUID			INT,		-- ���� Account �ε���, td_Store.AccountUniqueNumber
--	@i_AuctionCharacterUID			INT,		-- ���� ĳ���� �ε���, td_Store.Possess
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
---- Desc: ��ǰ ���� ������ ������ ��� ���
----====
--CREATE PROCEDURE dbo.atum_AuctionCancelItem
--	@i_ItemUID				BIGINT,		-- ������ ���� ��ȣ, td_Store.UniqueNumber
--	@i_AccountUID			INT,		-- ���� Account �ε���, td_Store.AccountUniqueNumber
--	@i_CharacterUID			INT			-- ���� ĳ���� �ε���, td_Store.Possess
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
---- Desc: ��ǰ ���� ������ ��ϵ� �ڽ��� �������� ��ȯ
----====
--CREATE PROCEDURE dbo.atum_AuctionGetMyItem
--	@i_CharacterUID			INT			-- ���� ĳ���� �ε���, td_Store.Possess
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
---- Desc: ��ǰ ���� ������ ��ϵ� ������ �������� ��ȯ
----====
--CREATE PROCEDURE dbo.atum_AuctionGetKindItem
--	@i_AuctionItemKind		TINYINT		-- ������ ����, AtumProtocol.h�� AUCTION_KIND_XXX ����
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
---- Desc: ��ǰ ���� ������ ��ϵ� �����۱���
----       �����ڿ��� ������ �ѱ�, �Ǹ����� â�� �� ����
----       �������� �� ���Ŵ� ���� �� �־�� ��
----====
--CREATE PROCEDURE dbo.atum_AuctionBuyItem
--	@i_AuctionItemUID					BIGINT,	-- ������
--	@i_AuctionSellerAccountUID			INT,	-- �Ǹ����� Account UID
--	@i_AuctionSellerCharacterUID		INT,	-- �Ǹ����� Character UID
--	@i_AuctionBuyerAccountUID			INT,	-- �������� Account UID
--	@i_AuctionBuyerCharacterUID			INT		-- �������� Character UID
--AS
--	DECLARE @tmpItemPrice	INT
--	SET @tmpItemPrice = (SELECT TOP 1 AuctionPrice FROM td_Auction WHERE AuctionItemUID = @i_AuctionItemUID)
--
--	-- �������� ������ return
--	IF (@tmpItemPrice IS NULL) RETURN 0
--
--	-- â�� ������ ����
--	DELETE FROM td_Auction WHERE AuctionItemUID = @i_AuctionItemUID
--
--	-- �������� ������ ����
--	UPDATE td_Store
--	SET Possess = @i_AuctionBuyerCharacterUID, AccountUniqueNumber = @i_AuctionBuyerAccountUID
--	WHERE UniqueNumber = @i_AuctionItemUID
--
--	-- �Ǹ����� �� ������Ʈ
--	IF (SELECT count(*) FROM td_Store WHERE ItemNum = 7000022 AND Possess = 0 AND AccountUniqueNumber = @i_AuctionSellerAccountUID) >= 1
--		BEGIN
--			-- â�� �� �������� �ִ� ���
--			UPDATE td_Store
--			SET CurrentCount = CurrentCount + @tmpItemPrice
--			WHERE ItemNum = 7000022 AND Possess = 0 AND AccountUniqueNumber = @i_AuctionSellerAccountUID
--		END
--	ELSE
--		BEGIN
--			-- â�� �� �������� ���� ���
--			EXEC atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @i_AuctionSellerCharacterUID, 7000022, @tmpItemPrice
--		END
--
--	RETURN 1
--GO

-- // 2008-02-13 by cmkwon, ���� ���� �ý��� ����� - ������� �ʴ� ���ν���
------------------------------------------------------------------------------------
---- MGAME - ���� ����
----------------------------------------------------------------------------------
--CREATE PROCEDURE dbo.Pb_Delete_Character
--	@strUserId char(20)        -- ������ȸ�����̵�
--AS
--	DECLARE @AccountUID INT
--	DECLARE @CharacterUID INT
--	SET @AccountUID = (SELECT top 1 AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE AccountName = @strUserId)
--	SET @CharacterUID = (SELECT top 1 UniqueNumber FROM td_Character WITH (NOLOCK) WHERE AccountName = @strUserId)
--
--	IF (@AccountUID IS NULL) RETURN
--
--	-- ��æƮ ����
--	DELETE td_Enchant
--		FROM td_Enchant e, td_Store s
--		WHERE s.UniqueNumber = e.TargetItemUniqueNumber AND s.AccountUniqueNumber = @AccountUID
--
--	-- ������ ����
--	DELETE FROM td_Store WHERE AccountUniqueNumber = @AccountUID
--	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber = @AccountUID
--
--	-- ������϶� ó��
--	DECLARE @GuildUID	INT
--	SET @GuildUID = (SELECT top 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildCommanderUniqueNumber = @CharacterUID)
--	IF (@GuildUID IS NOT NULL)
--		BEGIN
--			UPDATE td_Character
--			SET GuildName='', GuildUniqueNumber=0
--			WHERE GuildUniqueNumber=@GuildUID
--			
--			-- ��� ������� ����	
--			DELETE td_GuildMember
--			FROM td_GuildMember
--			WHERE GuildUniqueNumber=@GuildUID
--		END
--	ELSE
--		BEGIN 
--			-- ��� ������� ����	
--			DELETE td_GuildMember
--			FROM td_GuildMember
--			WHERE CharacterUniqueNumber = @CharacterUID
--		END
--
--	-- ����Ʈ���� ����
--	DELETE td_CharacterQuest
--		FROM td_CharacterQuest q, td_Character c
--		WHERE c.UniqueNumber = q.CharacterUniqueNumber AND c.AccountUniqueNumber = @AccountUID
--
--	-- ĳ���Ϳ��� ����
--	DELETE FROM td_Character WHERE AccountUniqueNumber = @AccountUID
--GO
--

-------------------------------
-- ���� ĳ���� ����
-------------------------------
-------------------------------
-- I-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_I
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
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
		WHERE CharacterName = 'I���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- �Ƹ� - ���δ� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO

-------------------------------
-- A-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_A
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
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
		WHERE CharacterName = 'A���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2�� ���� - ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- ��Ű ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO

-------------------------------
-- B-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_B
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
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
		WHERE CharacterName = 'B���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO

-------------------------------
-- M-GEAR
-------------------------------
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
--		2007-01-24 by cmkwon, ���ν��� �뵵 ���� - 'M���' ĳ���͸� ������ ĳ���͸� �߰��ϴ� ���ν���
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_M
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
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
		WHERE CharacterName = 'M���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- �Ƹ� - ����� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO

-------------------------------
-- �α� ������ procedures
-------------------------------

--!!!!
-- Name: atum_log_insert_connection
-- Desc: inserts connection log
--====
--		2006-09-14 by cmkwon, Add Parameter - @i_ServerGroupID INT
--		// 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - atum_Update_ConnectingServerGroupID_Of_Account() ���ν����� ó��
--
CREATE PROCEDURE dbo.atum_log_insert_connection
	@i_LogType					TINYINT,
	@i_IPAddress				BINARY(4),
	@i_AccountUniqueNumber		INT,
	@i_AccountName				VARCHAR(20),
	@i_ServerName				VARCHAR(20),
	@i_ServerGroupID			INT				-- 2006-09-14 by cmkwon, �߰���
AS
	INSERT INTO atum_log_connection
	VALUES (@i_LogType, GetDate(), @i_IPAddress,
			@i_AccountUniqueNumber, @i_AccountName, @i_ServerName)

	-- // 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - atum_Update_ConnectingServerGroupID_Of_Account() ���ν����� ó��
	---- 2006-09-14 by cmkwon
	---- �α��ν�(0 == @i_LogType)	==> ConnectingServerGroupID�� @i_ServerGroupID�� �����Ѵ�
	---- �α׾ƿ���(0 <> @i_LogType)	==> ConnectingServerGroupID�� 0�� �����Ѵ�
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
--			2006-12-18 by cmkwon, ���� �߰�(@i_PCBangPlayTime INT)
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
 	@i_MonsterUnitKind			INT,		-- ���� ���� ����
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
-- Desc: mgame ����
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
-- ������ ������ üũ ���ν���
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_GAMELOGIN
	@strClientID	VARCHAR(20),		-- User ID  <<  MGame ID
	@strIPAddr		VARCHAR(16), 		-- User IP Address
	@nGameID		INT					-- GameSvr ID

AS
	--exec [pubaccount].[dbo].PB_GAMELOGIN @strClientID, @strIPAddr, @nGameID
GO

-- ������ üũ ���ν���
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_GAMELOGOUT
	@strClientID	VARCHAR(20)			-- User ID  <<  MGame ID
AS
	--exec [pubaccount].[dbo].PB_GAMELOGOUT @strClientID
GO


-- ������ üũ �ʱ�ȭ ���ν���
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_INIT
	@nGameID int		-- GameSvr ID
AS
	--exec [pubaccount].[dbo].PB_INIT @nGameID

	-- 2007-01-29 by cmkwon, ServerGroupID �ʱ�ȭ
	UPDATE td_Account 
	SET ConnectingServerGroupID = 0
	WHERE ConnectingServerGroupID = @nGameID
GO
-- end_������ ������ üũ ���ν���
-------------------------------------------------------------------------------


--/*
-------------------------------------------------------------------------------
-- ���� ������(�Ϲ������̾�, ���� �����̾�) ���� ���ν���

-- 2005-01-20 by cmkwon, ������ ���� �������� �����´�
CREATE PROCEDURE dbo.atum_GetAccountCashStoreItem
	@i_accNum		INT					-- AccountUniqueNumber
AS
	SELECT * FROM td_accountCashStore WITH (NOLOCK)
		WHERE AccountUniqueNumber = @i_accNum
GO

-- 2005-01-20 by cmkwon, Cash ī�带 �߰�
CREATE PROCEDURE dbo.atum_insert_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber
	@i_ItemNum			INT,				-- �߰� �� ItemNum
	@i_CurTime			VARCHAR(30),		-- ���� �ð�
	@i_ExpireTime		VARCHAR(30)			-- ��� ���� �ð�
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

-- 2005-01-20 by cmkwon, Cash ī�� ������ Update
CREATE PROCEDURE dbo.atum_update_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber	
	@i_ItemNum			INT,				-- ã�� ����Ÿ�� ������ ItemNum	
	@i_CurTime			VARCHAR(30),		-- ���� �ð�
	@i_ExpireTime		VARCHAR(30)			-- ��� ���� �ð�
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

-- 2005-01-20 by cmkwon, Cash ī�� ������ �����Ѵ�
CREATE PROCEDURE dbo.atum_delete_AccountCashStoreItem
	@i_accNum			INT				-- AccountUniqueNumber
AS
	DELETE FROM td_accountCashStore
		WHERE AccountUniqueNumber = @i_accNum
GO

-- end_���� ������(�Ϲ������̾�, ���� �����̾�) ���� ���ν���
-------------------------------------------------------------------------------






-------------------------------------------------------------------------------
-- ���������� ���� ���ν���

-- 2005-02-04 by cmkwon, MapIndex�� MGameServerID�� ������ ���������� �ε�
CREATE PROCEDURE dbo.atum_CityWar_LoadingOccupyInfo
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT					-- ������������ �߻��� ������ä�� ID
AS
	SELECT OccupyGuildUID, OccupyGuildName, OccupyGuildMasterCharUID, Tex
		, CityWarDefaultTime, CityWarSettingTime, DefenseCounts, SumOfTex, Briefing 
		FROM td_OccupyInfo WITH (NOLOCK) WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
GO

-- 2005-02-04 by cmkwon, ������ ��ȿ���� üũ�Ѵ�
CREATE PROCEDURE dbo.atum_CityWar_CheckGuildAndGuildMaster
	@i_GuildUID					INT,				-- ����UID
	@i_GuildMasterCharUID		INT					-- ������ CharacterUID
AS
	DECLARE @guildUID INT
	SET @guildUID = (SELECT g.GuildUniqueNumber
						FROM td_Guild g, td_Character c
						WHERE c.UniqueNumber = @i_GuildMasterCharUID AND c.GuildUniqueNumber = g.GuildUniqueNumber
							AND g.GuildCommanderUniqueNumber = @i_GuildMasterCharUID)
	IF (@guildUID IS NULL)	RETURN 0
	ELSE					RETURN 1
GO

-- 2005-02-04 by cmkwon, ������ ��ȿ���� üũ�Ѵ�
CREATE PROCEDURE dbo.atum_CityWar_LoaingCityWarGuildList
	@i_CityWarQuestIndex		INT,				-- Quest Index
	@i_MGameServerID			INT					-- ������������ �߻��� ������ä�� ID
AS
	SELECT g.GuildUniqueNumber, g.GuildName, g.GuildCommanderUniqueNumber
		FROM td_Guild g, td_CharacterQuest q
		WHERE q.QuestIndex = @i_CityWarQuestIndex AND q.QuestParam1 = @i_MGameServerID
			AND g.GuildCommanderUniqueNumber = q.CharacterUniqueNumber
GO

-- 2005-02-04 by cmkwon, 
CREATE PROCEDURE dbo.atum_CityWar_StoreOccupyInfo
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT,				-- ������������ �߻��� ������ä�� ID
	@i_OccupyGuildUID				INT,				-- ���ɿ���UID
	@i_OccupyGuildName				VARCHAR(30),		-- ���ɿ��ܸ�
	@i_OccupyGuildMasterCharUID		INT,				-- ���ɿ����� CharacterUID
	@i_Tex							FLOAT,				-- ���� �̿� Tex Percent
	@i_CityWarDefaultTime			VARCHAR(30),		-- ���� ���������� �⺻�ð�
	@i_CityWarSettingTime			VARCHAR(30),		-- ���� ���������� �����ð�(�⺻�ð����� 12�� ���� �ð���������)
	@i_DefenseCounts				INT,				-- ��� ī��Ʈ
	@i_SumOfTex						INT,				-- �Ϸ� ������
	@i_Briefing						VARCHAR(100)		-- ���� �̿�� �λ縻
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
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT,				-- ������������ �߻��� ������ä�� ID
	@i_Tex							FLOAT				-- ���� �̿� Tex Percent
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
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT,				-- ������������ �߻��� ������ä�� ID
	@i_CityWarDefaultTime			VARCHAR(30),		-- ���� ���������� �⺻�ð�
	@i_CityWarSettingTime			VARCHAR(30)			-- ���� ���������� �����ð�(�⺻�ð����� 12�� ���� �ð���������)	
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
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT,				-- ������������ �߻��� ������ä�� ID
	@i_SumOfTex						INT					-- �Ϸ� ������	
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
	@i_MapIndex						INT,				-- ���������� ���ε���
	@i_MGameServerID				INT,				-- ������������ �߻��� ������ä�� ID
	@i_Briefing						VARCHAR(100)		-- ���� �̿�� �λ縻
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
-- end_���������� ���� ���ν���
-------------------------------------------------------------------------------


--!!!!
-- Name: atum_UpdateInfluenceWarData
-- Desc: 2006-04-14 by cmkwon, 
--====
CREATE PROCEDURE dbo.atum_UpdateInfluenceWarData
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,				-- ������������ �߻��� ������ä�� ID
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
	@i_InfluenceType			TINYINT,			-- �������� ���� ����
	@i_MGameServerID			INT					-- ������������ �߻��� ������ä�� ID
AS
	-- �ٸ� ������ ���� �ʵ带 0���� �����Ѵ�
	UPDATE td_InfluenceWarData
		SET OwnerOfConflictArea = 0
		WHERE InfluenceType <> @i_InfluenceType and MGameServerID = @i_MGameServerID

	-- ���� ���� ������ ���� �ʵ带 1�� �����Ѵ�.
	UPDATE td_InfluenceWarData
		SET OwnerOfConflictArea = 1
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
GO


-- 2006-07-25 by cmkwon, atum_GameLog_BackUp ���ν����� ������
---------------------------------------------------------------------------------
---- 2005-02-25 by cmkwon, Log ���̺� �����ϱ� ���ν���
----		: atum_log_X ���̺���� atum_backup_log_X ���̺������ �����Ѵ�
------		: atum_log_type_info ���̺��� ����
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
---- end_Log ���̺� �����ϱ� ���ν���
---------------------------------------------------------------------------------



-----------------------------------------------------------------------------
-- 2005-03-02 by cmkwon, Coupon ����

-- ���� ��������
CREATE PROCEDURE dbo.atum_Coupon_LoadCouponByNumber
	@i_CouponNumber			VARCHAR(30)			-- ���� �ѹ�	
AS
	SELECT * 
		FROM td_CouponList WITH (NOLOCK)
		WHERE CouponNumber = @i_CouponNumber
GO

-- ���� ����ϱ�
CREATE PROCEDURE dbo.atum_Coupon_UseCoupon
	@i_UniqueNumber			INT,				-- ���� ����ũ �ѹ�
	@i_UsedAccountName		VARCHAR(20),		-- ���� ��� AccountName
	@i_UsedTime				VARCHAR(30)			-- ���� ��� �ð�(���� ���� �ð��� ����)
AS
	UPDATE td_CouponList
		SET UsedFlag = 1, UsedAccountName = @i_UsedAccountName, UsedTime = @i_UsedTime
		WHERE UniqueNumber = @i_UniqueNumber
GO
-- End_Coupon ����
-------------------------------------------------------------------------------


-----------------------------------------------------------------------------
-- 2005-03-30 by cmkwon, HappyHourEvent ����

-- ��� ServerGroup �̺�Ʈ, ���� ������ �̺�Ʈ ��������
-- 2006-08-25 by cmkwon, @i_ServerGroupID		INT �߰���
-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ʵ� �߰�(InfluenceType)
-- 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� - MinLevel, MaxLevel �ʵ� �߰�
CREATE PROCEDURE dbo.atum_LoadHappyHourEvent
	@i_ServerGroupID		INT				-- 2006-08-25 by cmkwon, 0(=AllServerGroup), 1(=10061), 2(10062), ...
AS
	-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ʵ� �߰�(InfluenceType)�� �Ʒ��� ���� �ʵ�� ��÷� ������
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

-- HappyHourEvnet ���� Update -- ����	- ��(0) ��(1) ȭ(2) ��(3) ��(4) ��(5) ��(6) HappyHourEvent�Ⱓ(7) PCBangHappyHourEvent�Ⱓ�׼���(8)
-- 2006-08-25 by cmkwon, ti_HappyHourEvent ���̺� ServerGroupID �ʵ� �߰���
-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� ���� �߰� ��
CREATE PROCEDURE dbo.atum_UpdateHappyHourEventDate
	@i_StartTime		VARCHAR(30),		-- �̺�Ʈ ���� �ð�
	@i_EndTime			VARCHAR(30),		-- �̺�Ʈ ���� �ð�
	@i_InflTy			TINYINT				-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - dbo.atum_UpdateHappyHourEventDate() ���ν����� �߰� �� ����
AS
	DECLARE @searchUniqueNumber INT
	-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ش� ������ �Ⱓ�� �˻��Ѵ�.
	SET @searchUniqueNumber = (SELECT UniqueNumber FROM ti_HappyHourEvent WHERE InfluenceType = @i_InflTy AND DayOfWeek = 7)

	IF (@searchUniqueNumber IS NULL)
		BEGIN
			INSERT INTO ti_HappyHourEvent
				VALUES(0, 7, @i_StartTime, @i_EndTime, 0, 0, 0, 0, 0, 0, @i_InflTy, 1, 100)
				-- 2007-08-31 by cmkwon, ����
				-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� �ʵ� �߰���
				-- // 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� -
		END
	ELSE
		BEGIN
			UPDATE ti_HappyHourEvent
				SET StartTime = @i_StartTime, EndTime = @i_EndTime
				WHERE UniqueNumber = @searchUniqueNumber
		END	
GO
-- HappyHourEvent ����
-------------------------------------------------------------------------------




-----------------------------------------------------------------------------
-- 2005-04-07 by cmkwon, ���� ������ ����



CREATE PROCEDURE dbo.atum_Cash_ChangeCharacterName
	@i_CharacterUID				INT,					-- ���� �� ĳ���� UID
	@i_OriginCharacterName		VARCHAR(20),			-- ���� ĳ���͸�
	@i_ChangeCharacterName		VARCHAR(20)				-- �����Ϸ��� ĳ���͸�
AS
	DECLARE @searchUniqueNumber INT
	SET @searchUniqueNumber = (SELECT UniqueNumber	FROM td_Character WHERE CharacterName = @i_ChangeCharacterName)

	IF (@searchUniqueNumber IS NOT NULL)
		return 0
	
	-- ģ������Ʈ���� ���(�ڽ�,����) ����
	DELETE FROM td_FriendList
		WHERE CharacterName = @i_OriginCharacterName OR FriendName = @i_OriginCharacterName
	
	UPDATE td_Character
		SET CharacterName = @i_ChangeCharacterName
		WHERE UniqueNumber = @i_CharacterUID
	
	return 1
GO
-- End_���� ������ ����
-----------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- ���� ���˽� GameLog BackUp Procedure         --2006-06-30 by dhJin 
CREATE PROCEDURE dbo.atum_GameLog_BackUp
AS

    --------------------------------------------------------------------------------
    -- 1. atum_backup_log_xxx ���̺� ����
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
    --atum_backup_log_xxx ���̺� ����
    --------------------------------------------------------------------------------

    --------------------------------------------------------------------------------
    -- 2. atum_log_xxx -> atum_backup_log_xxx �� ���̺� �̸� ����
    exec sp_rename 'atum_log_item_trade', 'atum_backup_log_item_trade'
    exec sp_rename 'atum_log_user_memory_hack', 'atum_backup_log_user_memory_hack'
    exec sp_rename 'atum_log_user_speed_hack', 'atum_backup_log_user_speed_hack'
-- 2006-07-25 by cmkwon, ����� �α׸� �������� �ʰų� Ȥ�� �α׸� �������� �ʴ� ���̺�
--    exec sp_rename 'atum_log_item_buy_sell', 'atum_backup_log_item_buy_sell'
--    exec sp_rename 'atum_log_item_charac_use', 'atum_backup_log_item_charac_use'
--    exec sp_rename 'atum_log_item_get_throw', 'atum_backup_log_item_get_throw'
--    exec sp_rename 'atum_log_monster_boss', 'atum_backup_log_monster_boss'
--    exec sp_rename 'atum_log_server_map', 'atum_backup_log_server_map'
--    exec sp_rename 'atum_log_user_exp', 'atum_backup_log_user_exp'
--    exec sp_rename 'atum_log_user_game_start_end', 'atum_backup_log_user_game_start_end'
--    exec sp_rename 'atum_log_user_quest_pk_dead', 'atum_backup_log_user_quest_pk_dead'
--    exec sp_rename 'atum_log_user_warp', 'atum_backup_log_user_warp'
    --atum_log_xxx -> atum_backup_log_xxx �� ���̺� �̸� ����
    --------------------------------------------------------------------------------

    --------------------------------------------------------------------------------
    --atum_log_xxx ���̺� ����
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
    --					���� - 
    --					���� -
    --					�Ƹ� - 
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
    --atum_log_xxx ���̺� ����
    --------------------------------------------------------------------------------

GO
-- ���� ���˽� GameLog BackUp Procedure
--------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �̺�Ʈ ������ ���� ���� ���� �˻��ϴ� ���ν���
CREATE PROCEDURE dbo.atum_GetEventItemList
	@i_AccountUID                int,
	@i_ItemEventUID               int
AS
	Select GetTime from atum_Log_ItemEvent WITH (NOLOCK)
	where AccountUID = @i_AccountUID and ItemEventUID = @i_ItemEventUID
GO
-- end �̺�Ʈ ������ ���� ���� ���� �˻��ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �̺�Ʈ ������ ���� ���� ���� ����ϴ� ���ν���
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
-- end �̺�Ʈ ������ ���� ���� ���� ����ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �̺�Ʈ ������ �˻� �ϴ� ���ν���
-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - �ʵ� �߰� �� �� �˻� ����� �߰�
CREATE PROCEDURE dbo.atum_Load_ItemEvent
AS
	select ItemEventUID, ItemEventType, OnlyPCBang, InfluenceType,ItemNum,Count,StartTime,EndTime,MemberShip,ReqLevel,NewMember,UnitKind,PrefixCodeNum,SuffixCodeNum,UseLastGameEndDate,LastGameEndDate
	from ti_ItemEvent WITH (NOLOCK)
GO
-- end �̺�Ʈ ������ �˻� �ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ ���� ����� ���ν���
CREATE PROCEDURE dbo.atum_delete_QuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int,
	@i_TabIdx                     int
AS
	DELETE FROM td_QuickSlot 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND TabIdx = @i_TabIdx
GO
-- end ������ ���� ����� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ ������Ʈ ���ν���
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
	@i_ItemNum_8                  int,		--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	@i_ItemNum_9                  int,		--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	@i_ItemNum_10                 int		--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
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
	ItemNum_9 = @i_ItemNum_9, ItemNum_10 = @i_ItemNum_10		--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID 
			 AND TabIdx = @i_TabIdx 
END
ELSE
BEGIN
	INSERT INTO td_QuickSlot 
	VALUES(@i_AccountUID, @i_CharacterUID, @i_TabIdx, @i_ItemNum_1,
	 @i_ItemNum_2, @i_ItemNum_3, @i_ItemNum_4, @i_ItemNum_5,
	 @i_ItemNum_6, @i_ItemNum_7, @i_ItemNum_8, @i_ItemNum_9, @i_ItemNum_10)			--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
END
GO
-- end ������ ������Ʈ ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ �˻� ���ν���
CREATE PROCEDURE dbo.atum_GetQuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int
AS
	SELECT * FROM td_QuickSlot WITH (NOLOCK)
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
GO
-- end ������ �˻� ���ν���
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- ���� â�� ����
--!!!!	2006-09-21 by cmkwon
-- Name: atum_Get_GuildStore
-- Desc: �ش� ���� â�� ������ ��������
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

-- 2007-01-30 by cmkwon, �ʿ� ��� �ּ� ó���� - atum_GetEnchantBYItemUID() ���ν����� ��ü��
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
-- Desc: 2007-01-30 by cmkwon, �߰���
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
-- 2006-09-21 by cmkwon, ���� ����

--!!!!
-- Name: Billing_CashItem_Insert_TO_Store
-- Desc: �ش� ĳ���� â�� ������ �߰�
--====
CREATE PROCEDURE dbo.Billing_CashItem_Insert_TO_Store
	@i_AccUID			INT,			-- 
	@i_CharUID			INT,			-- 
	@i_ItemNum			INT,			-- 
	@i_MinTradeQuantity	INT,			-- �ּ� �ŷ� ī��Ʈ(ī���ͺ�:1, ��ī���ͺ�:1�̻�)
	@i_InsertCount		INT				-- �߰� ī��Ʈ
AS
	DECLARE @ItemKind	TINYINT
	SET @ItemKind		= (SELECT Kind FROM ti_item WHERE ItemNum = @i_ItemNum)
	IF (@ItemKind IS NULL)
	BEGIN
		RETURN
	END

	-- ��ī���ͺ������ ������ - �ּ� �ŷ� ī��Ʈ�� 1�� ����
	IF ( 0 = dbo.atum_IsCountableItem(@ItemKind) )
	BEGIN
		SET @i_MinTradeQuantity	= 1
	END

	DECLARE @InsertCount	INT
	DECLARE @CurCount		INT
	-- ��ī���ͺ� �������� CurrentCount = 1, �߰����� = @i_InsertCount
	-- ī���ͺ� �������� CurrentCount = @i_MinTradeQuantity * @i_InsertCount, �߰�����=1
	IF ( 0 = dbo.atum_IsCountableItem(@ItemKind) )
		BEGIN
			SET @InsertCount	= @i_InsertCount	-- td_store ���̺� �߰��� ī��Ʈ
			SET @CurCount		= 1					-- CurrentCount�� �Ҵ� �� ����
		END
	ELSE
		BEGIN
			SET @InsertCount	= 1						-- td_store ���̺� �߰��� ī��Ʈ
			SET @CurCount		= @i_MinTradeQuantity * @i_InsertCount	-- CurrentCount�� �Ҵ� �� ����
		END

	-------------------------------------------------------------------------------
	-- td_store ���̺� ������ �߰�
	DECLARE @i	INT
	SET @i		= 0	
	DECLARE @InsertItemUID	BIGINT
	WHILE (@i < @InsertCount)
		BEGIN
			
			-- ĳ������ â��� ������ �߰�
			INSERT INTO td_Store
				VALUES(@i_AccUID, @i_CharUID, 1, 0, @CurCount, 0, 99, @i_ItemNum, 0, 0, 0, 0, 0, 0, GetDate())
			SET @InsertItemUID = SCOPE_IDENTITY();

			-- ������ ���� �α� �߰�
			-- #define T1_FL_LOG_ITEM_BUY_ITEM					0x25	// 37 - ������ ����
			exec dbo.atum_log_insert_item_buy_sell 37, @i_CharUID, 0, @InsertItemUID, @i_ItemNum, @CurCount, @CurCount, 0

			SET @i		= @i + 1
		END
GO

--!!!!	2006-09-21 by cmkwon
-- Name: Billing_Insert_Item
-- Desc: ������ ���󿡼� ������ ������ �������� ���ӻ��� ĳ���� â�� �־��ִ� ���ν���
-- 		
--		
--		[out 1] INT nErrCode	==> =0(����), <>0(����, ERR_DB_XXX)
--====
CREATE PROCEDURE dbo.Billing_Insert_Item
	@i_AccountName				VARCHAR(20),				-- ������ ���� ������
	@i_CharacterName			VARCHAR(20),				-- ������ ���Ž� ���ӻ󿡼��� ĳ���͸�
	@i_ItemNum					VARCHAR(50),				-- ������ ����ũ ��ȣ
	@i_BuyItemCount				INT							-- ������ ���� ī��Ʈ
AS
	--------------------------------------------------------------------------------
	-- �ش� ���� ���� ����üũ �� ���� ������ ���ӿ� ���� ������ üũ
	DECLARE @AccUID		INT
	SET @AccUID			= (SELECT AccountUniqueNumber FROM td_Account WHERE AccountName = @i_AccountName AND ConnectingServerGroupID = 0)
	IF (@AccUID IS NULL)
	BEGIN
		-- #define ERR_DB_USER_CONNECTING_GAME_SERVER		300			// ������ ���Ӽ����� ���� ���̴� - ������ ������ ���Žô� ������ �����ؾ���
		SELECT 300
		RETURN
	END
	
	--------------------------------------------------------------------------------
	-- ĳ���͸� üũ
	DECLARE @CharUID	INT
	SET @CharUID		= (SELECT c.UniqueNumber FROM td_account a, td_character c
								WHERE a.AccountName = @i_AccountName AND a.AccountUniqueNumber = c.AccountUniqueNumber AND c.CharacterName = @i_CharacterName)
	IF (@CharUID IS NULL)
	BEGIN
		-- #define ERR_DB_IS_NOT_CHARACTERNAME				301			// ���� DB ���̺� ĳ���͸��� �����ϴ�.
		SELECT 301
		RETURN
	END

	--------------------------------------------------------------------------------
	-- ������ �˻�
	-- 1. Ŀ�� ����
	DECLARE cur_item_info CURSOR 
	FOR
		SELECT ItemNum, Kind, SummonMonster, MinTradeQuantity, Time, ParameterValue1, DestParameter1
				, ParameterValue2, DestParameter2, ParameterValue3, DestParameter3, ParameterValue4, DestParameter4
			FROM ti_item WHERE ItemNum = @i_ItemNum

	-- 2. Ŀ�� ����
	OPEN cur_item_info

	-- 3. ���� ����
	DECLARE @ItemNum			INT
	DECLARE @ItemKind			TINYINT
	DECLARE @CashItemType		INT
	DECLARE @MinTradeQuantity	SMALLINT
	DECLARE @Period				INT			-- �����̾� ������ ���� �Ⱓ(Day)
	DECLARE @AddItemNum1		FLOAT
	DECLARE @AddItemCount1		TINYINT
	DECLARE @AddItemNum2		FLOAT
	DECLARE @AddItemCount2		TINYINT
	DECLARE @AddItemNum3		FLOAT
	DECLARE @AddItemCount3		TINYINT
	DECLARE @AddItemNum4		FLOAT
	DECLARE @AddItemCount4		TINYINT

	-- 4. ù �ο� FETCH
	FETCH NEXT FROM cur_item_info
		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
				, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
	-- �ʿ���� �κ��� 5. ��ȯ
	--WHILE @@FETCH_STATUS = 0
	--BEGIN
	--	FETCH NEXT FROM cur_item_info
	--		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
	--			, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
	--END

	-- 6. Ŀ�� CLOSE
	CLOSE cur_item_info
	
	-- 7. Ŀ�� DEALLOCATE
	DEALLOCATE cur_item_info

	-- ������ ���� üũ
	IF (@ItemNum IS NULL) OR (@ItemKind IS NULL) OR (@CashItemType IS NULL) OR (@MinTradeQuantity IS NULL)
	BEGIN
		-- #define ERR_DB_INVALID_ITEM						4			// �����Ϸ��� �������� ��ȿ���� ���� - ti_item_info ���̺� ���ų� IsDisable �ʵ尡 0�� �ƴϴ�
		SELECT 4
		RETURN
	END
	
	-- // ����ȭ ������ kind - ITEM ����ü���� SummonMonster �ʵ带 ����Ѵ�
	-- #define CASH_ITEMKIND_PREMIUM_CARD			(BYTE)0
	-- #define CASH_ITEMKIND_OPTION_ITEM			(BYTE)1
	-- #define CASH_ITEMKIND_CARD_ITEM				(BYTE)2
	-- #define CASH_ITEMKIND_ACCESSORY_ITEM		(BYTE)3
	-- 1. �����̾�ī�� ������ ����
	-- 2. �Ϲ� ���� ������ ����
	IF (0 = @CashItemType)
	BEGIN

		--------------------------------------------------------------------------------
		-- �����̾� �˻�
		-- 1. Ŀ�� ����
		DECLARE cur_premium_info CURSOR 
		FOR
			SELECT UniqueNumber, ItemNum, ExpireTime FROM td_AccountCashStore WHERE AccountUniqueNumber = @AccUID

		-- 2. Ŀ�� ����
		OPEN cur_premium_info

		-- 3. ���� ����
		DECLARE @PremiumUID			BIGINT
		DECLARE @PremiumItemNum		INT
		DECLARE @ExpireTime			DATETIME
			
		-- 4. ù �ο� FETCH
		FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
		-- �ʿ���� �κ��� 5. ��ȯ
		--WHILE @@FETCH_STATUS = 0
		--BEGIN
		--	FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
		--END

		-- 6. Ŀ�� CLOSE
		CLOSE cur_premium_info
		
		-- 7. Ŀ�� DEALLOCATE
		DEALLOCATE cur_premium_info

		DECLARE @CurDate	DATETIME
		SET @CurDate		= GetDate()
		IF (@PremiumUID IS NULL)-- �����̾� �������� ����, �߰�
		BEGIN
			INSERT INTO td_accountCashStore
				VALUES (@AccUID, @ItemNum, @CurDate, @CurDate, DATEADD(Day, @Period, @CurDate))
		END
		
		ELSE-- ������ �����̾� �������� �����Ѵ�.
		BEGIN

			-- �̹� ����� �����̾� ������
			IF @ExpireTime < @CurDate
			BEGIN
				SET @ExpireTime		= @CurDate
			END

			ELSE
			BEGIN
				-- ���� �� ��¥�� ���� ��¥�κ��� 180�ϱ����� ���԰���
				IF DATEADD(Day, @Period, @ExpireTime) > DATEADD(Day, 180, @CurDate)
				BEGIN
					-- #define ERR_DB_CANNOT_ADD_PREMIUMITEM			303			// �����̾� ������ �߰� ���� �Ұ�(����η� 180�� ����)
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

		-- �����̾� �߰� ������ �߰����ֱ�
		IF (@AddItemNum1 IS NOT NULL) AND (0 <> @AddItemNum1) AND (0 < @AddItemCount1)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum1, 1, @AddItemCount1
		IF (@AddItemNum2 IS NOT NULL) AND (0 <> @AddItemNum2) AND (0 < @AddItemCount2)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum2, 1, @AddItemCount2
		IF (@AddItemNum3 IS NOT NULL) AND (0 <> @AddItemNum3) AND (0 < @AddItemCount3)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum3, 1, @AddItemCount3
		IF (@AddItemNum4 IS NOT NULL) AND (0 <> @AddItemNum4) AND (0 < @AddItemCount4)
			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum4, 1, @AddItemCount4
	END-- END - IF (0 = @CashItemType)

	ELSE-- �Ϲ� ���� ������
	BEGIN
		-- #define ERR_NO_ERROR						0
		SELECT 0

		exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @ItemNum, @MinTradeQuantity, @i_BuyItemCount
	END

GO

-- END_���� ����
-------------------------------------------------------------------------------

--!!!!
-- Name: atum_log_Insert_GuildStore
-- Desc: 2006-09-27 by dhjin
--		 // 2008-04-02 by dhjin, ti_item ����ϴ� ���� ������, ti_item ���� �ʿ� ������
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
-- DESC      : 2006-11-17 by dhjin, 2�� ��ų ��� ���� ������Ʈ
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
-- Desc: 2007-01-22 by cmkwon, �߰� ��
--		   �ش� ������ ĳ���� ������ ã�Ƽ� ��� ������ �������� �����Ѵ�.
--====
CREATE PROCEDURE dbo.atum_Change_AccountName_Of_AllCharacter
	@i_OriginAccountName		VARCHAR(20),
	@i_NewAccountName			VARCHAR(20)
AS
	--------------------------------------------------------------------------------
	-- 1. �ش� ������ ĳ���Ͱ� �ִ��� üũ
	DECLARE @OriginAccUID INT
	SET @OriginAccUID = (SELECT TOP 1 AccountUniqueNumber FROM td_Character WHERE AccountName = @i_OriginAccountName)
	IF @OriginAccUID IS NULL
		RETURN 0

	--------------------------------------------------------------------------------
	-- 2. ���� ���� ������ �α� ���̺� �߰��Ѵ�
	-- #define T1_FL_LOG_DELETE_CHARACTER				0x1C	// 28 - ĳ���� ����
	INSERT INTO atum_log_user_game_start_end
		SELECT 28, GetDate(), UniqueNumber, 0, 0, 0, 0,	CharacterName, AccountUniqueNumber, AccountName, 0, TotalPlayTime, 0, 0
		FROM td_Character
		WHERE AccountName = @i_OriginAccountName

	--------------------------------------------------------------------------------
	-- 3. td_Account���̺� �������� �����Ѵ�.
	UPDATE td_Character
	SET AccountName = @i_NewAccountName
	WHERE AccountName = @i_OriginAccountName

	RETURN 1
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_GetPCBangIPList
-- DESC      : 2007-01-24 by dhjin, PC�� IP����Ʈ
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetPCBangIPList
AS
	SELECT UID, ST_IP, ED_IP FROM td_PCBang with(NOLOCK)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_insert_integration
-- DESC      : 2007-01-26 by cmkwon, ���� ����,���� �α� �����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_insert_integration
	@i_LogType					TINYINT,
	@i_AccountName				VARCHAR(20),		-- 2007-01-29 by cmkwon, �߰���
	@i_AccountUID				INT,				-- 2007-01-29 by cmkwon, �߰���
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
-- DESC      : 2007-01-30 by dhjin, ���� ����,���� �α� �˻�
--				// 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
--------------------------------------------------------------------------------
CREATE  PROCEDURE dbo.atum_log_select_integration
	@i_str				VARCHAR(2000)
AS
	IF (@i_str = '')
	BEGIN
		-- // 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
		SELECT AccountUID, AccountName, SourceDBNum, SourceCharacterUID, SourceCharacterName, 
			TargetDBNum, TargetCharacterUID, TargetCharacterName, Time, LogType
		FROM atum2_db_account_test.dbo.atum_log_integration WITH (NOLOCK) 
		order by Time
	END
	ELSE
	BEGIN
		-- // 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
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
-- DESC      : 2007-02-13 by dhjin, ������ ���� ������ �߰��ϴ� ���ν���
--				7001320	�������� ����(����������)
--				7001330	�������� ����(�˸���)
--				7001090	������ ��ȣ
--				7001110	������ �ð�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertLeaderItem
	@i_Infltype				TINYINT,
	@i_AccountUniqueNumber	INT,
	@i_Possess				INT
AS
	IF @i_Infltype = 2 -- ����������
	BEGIN
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001320, 1, 0, 99		-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001090, 10, 0, 99	-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001110, 5, 0, 99		-- 
	END

	ELSE IF @i_Infltype = 4 -- �˸���
	BEGIN
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001330, 1, 0, 99		-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001090, 10, 0, 99	-- 
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_Possess, 7001110, 5, 0, 99		-- 
	END
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_InsertLeaderItem
-- DESC      : 2007-02-13 by dhjin, ������ ���� ������ �����ϴ� ���ν���
--				7001320	�������� ����(����������)
--				7001330	�������� ����(�˸���)
--				7001090	������ ��ȣ
--				7001110	������ �ð�
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
-- DESC      : 2007-02-13 by dhjin, �������� ���� ���ν���
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
		SET @o_RetCode = 10						-- �������� �ɸ��� �˻� �̸��� ����.
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
			SET @o_RetCode = 20						-- �̹� �������ڷ� ���� �Ǿ��ִ�.
			RETURN
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub1LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType
			SET @o_RetCode = 1
			RETURN	@SetUID							-- ��������1�� ����
		END
	END
	
	ELSE IF(2 = @i_SubLeaderRank)
	BEGIN
		SELECT @SetSubLeaderNum = InflSub2LeaderCharacterUID FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
				WHERE InfluenceType = @i_InflType AND  InflSub1LeaderCharacterUID <> @SetUID AND InflLeaderCharacterUID <> @SetUID
		IF(@SetSubLeaderNum = @SetUID)
		BEGIN
			SET @o_RetCode = 20						-- �̹� �������ڷ� ���� �Ǿ��ִ�.
			RETURN
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub2LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType
			SET @o_RetCode = 2
			RETURN	@SetUID							-- ��������2�� ����
		END
	END
	
	SET @o_RetCode = 0
	RETURN										-- �������� ������ �̹� �Ǿ��־ ������ �ȵȴ�.
GO

-- 2007-05-15 by cmkwon, �Ʒ��� ���ν����� ����
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
--				// 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� �� ����, ���� ������ ���� �����ֱ� �߰� - �������� �ʵ� �߰�(InfluenceType, SelectableInfluenceMask)
--				// 2008-03-03 by cmkwon, ���� ������ ĳ���͸���Ʈ ������ ���� �� ��¥ ���� �ֱ� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_GetAllDeletedCharacter
	@i_AccName		VARCHAR(20)
AS
	-- // 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� �� ����, ���� ������ ���� �����ֱ� �߰� - �������� �ʵ� �߰�(InfluenceType, SelectableInfluenceMask)
	-- // 2008-03-03 by cmkwon, ���� ������ ĳ���͸���Ʈ ������ ���� �� ��¥ ���� �ֱ� - ������ ��¥ �������� �߰�, ������ ��¥ ������ ���� �߰�
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

	-- // 2008-02-20 by cmkwon, ���� ��û���� 2ȸ���� ���� �����ϴ�
	IF (@LivedCheck >= 2)
		BEGIN
			RETURN	10			-- ���� ������ �ִ� �ɸ���
		END
	
	DECLARE @CharacterNum		INT
	SELECT @CharacterNum = count(*) FROM td_Character WITH (NOLOCK) WHERE 0 = Race & 0x4000 AND AccountUniqueNumber = @i_AccountUID

	IF (@CharacterNum >= 3)
		BEGIN
			RETURN	20			-- �ɸ��Ͱ� 3���� �ֱ� ������ ���� �Ұ�.
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
	-- // 2007-11-16 by cmkwon, ĳ���� ���� ���� �� ���� ������ �̾Ƽ� ó�� - dbo.atum_Job_DeleteCharacter ���ν��� ����
	DECLARE @KeepTermOfDay INT
	SET @KeepTermOfDay		= 14

	-- 1. ĳ���� ���� �������� ��æƮ ����	
	DELETE td_Enchant FROM td_Enchant e, td_Store s 
	WHERE s.ItemStorage <> 2 AND s.AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND s.Possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND s.UniqueNumber = e.TargetItemUniqueNumber

	-- 2. ĳ���� ���� ������ ����
	DELETE FROM td_Store WHERE ItemStorage <> 2 AND AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 3. ĳ���� �� ���� ����
	DELETE FROM td_QuickSlot WHERE AccountUID IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND CharacterUID IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 4. ĳ���� ���� ��ų ����
	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) AND possess IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 5. ����Ʈ ���̺��� ����
	DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 6. ����Ʈ ���� ���� ���̺��� ����
	DELETE FROM td_CharacterQuestMonsterCount WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- 7. ģ������Ʈ���� ����
	DELETE FROM td_FriendList WHERE CharacterName IN 
	(SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay)) OR FriendName IN 
	(SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	--8. Ʃ�丮�� ����Ʈ���� ����
	DELETE FROM td_TutorialComplete WHERE CharacterUID IN 
	(SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE 0 <> Race & 0x4000 AND (DATEDIFF(dd, LastStartedTime, GETDATE()) > @KeepTermOfDay))

	-- last ĳ���� ���̺��� ����
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
-- DESC      : �����ؾ� �� ��������Ʈ ���� �ֱ� �ð� ������ ������ ���ν���.
-- 2007-03-29 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRangeTimeInfo
AS
	SELECT StartTime, EndTime, SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily FROM dbo.td_StrategyPointSummonRangeTimeInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonInfo
-- DESC      : �����ؾ� �� ��������Ʈ ������ ������ ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonInfo
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadAllStrategyPointSummonInfo
-- DESC      : �����ؾ� �� ��������Ʈ ���� ��ü �������� ���ν��� (SCAdminTool���� ���)
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadAllStrategyPointSummonInfo
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK) ORDER BY SummonTime
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoByMapIndex
-- DESC      : �����ؾ� �� ��������Ʈ �� ������ ti_StrategyPointSummonMapIndex�� �����ϰ� �ϴ� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoByMapIndex
AS
	DELETE dbo.td_StrategyPointSummonInfo WHERE MapIndex NOT IN (SELECT MapIndex FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex)
	INSERT INTO dbo.td_StrategyPointSummonInfo 
		SELECT MapIndex, 0, GetDATE(), NULL		-- // 2008-04-08 by dhjin, ��ȯ ���� �ð� ���� - 
		FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex
		WHERE MapIndex NOT IN (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoBySummon
-- DESC      : ������ ��������Ʈ ���� ���ν���.
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
-- DESC      : ��������Ʈ ���� �ð� ���� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoBySummonTime
	@i_MapIndex			INT,
	@i_SummonTime		VARCHAR(30),
	@i_SummonAttribute	TINYINT		-- // 2008-04-08 by dhjin, ��ȯ ���� �ð� ���� - 
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonTime = @i_SummonTime, SummonAttribute = @i_SummonAttribute WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonInfoByNewSummonRange
-- DESC      : ������ ��������Ʈ �ð� �� ���� ���ν���.
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
-- DESC      : ��������Ʈ ���� �� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonMapIndex
AS
	SELECT MapIndex FROM atum2_db_account_test.dbo.ti_StrategyPointSummonMapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_LoadStrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRange
AS
	SELECT SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily
	FROM atum2_db_account_test.dbo.td_StrategyPointSummonRange
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ� ������Ʈ ���ν���
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
-- DESC      : ��������Ʈ ���� �ֱ� �� ���� �ʱ�ȭ ���ν���.
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
	
		-- // 2008-01-09 by dhjin, DB �ԷµǴ� ��¥ ���� ����
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
-- DESC      : ��������Ʈ �����Ǹ� �ȵǴ� �ð� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointNotSummonTime
AS
	SELECT DayOfWeek, StartTime, EndTime, CheckSummon FROM atum2_db_account_test.dbo.td_StrategyPointNotSummonTime
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_UpdateStrategyPointNotSummonTime
-- DESC      : ��������Ʈ �����Ǹ� �ȵǴ� �ð� ������Ʈ ���ν���
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
-- DESC			 : WarPoint ������Ʈ
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
-- DESC			 : �Ʒ��� ���� �ε�
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadArenaInfo
AS
	SELECT ArenaMode, ReqMemberNum, PayInfluencePointWIN, PayInfluencePointLOSE, PayWarPointWIN, PayWarPointLOSE
	FROM atum2_db_account_test.dbo.ti_ArenaInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadArenaMapInfo
-- DESC			 : �Ʒ��� �� ���� �ε�
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
-- DESC			 : Arena��� ������Ʈ
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
-- DESC			 : Arena ���� ���� ������Ʈ
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
-- DESC			 : 2007-06-20 by cmkwon, �߰� - �ְ� ���� ĳ���� ����
--					���� ������������ ������ ĳ���͸� �����ֱ����� �߰��� ���ν�����
--					
-- parameter:
--		[1]	OUTPUT @o_RetCode		:���� �ڵ�(�����ڵ�)
--									0	==> ���� ����
--									100	==> �ش� ������ ĳ���Ͱ� ����
--		[2]	OUTPUT @o_CharacterName	:ĳ���͸�
--		[3]	OUTPUT @o_PilotFace		:ĳ������ �ι� ĳ����
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
--		[4]	OUTPUT @o_Level			:ĳ������ ����
--		[5] INPUT  @i_AccountName	:�˻��� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atumManager_GetMaxLevelCharacter
	@o_RetCode			INT				OUTPUT,
	@o_CharacterName	VARCHAR(20)		OUTPUT,
	@o_PilotFace		TINYINT			OUTPUT,
	@o_Level			TINYINT			OUTPUT,
	@i_AccountName		VARCHAR(20)
AS
	SET	@o_RetCode		= 0			--									0	==> ���� ����

	SELECT TOP 1 @o_CharacterName= CharacterName, @o_PilotFace= PilotFace, @o_Level= Level
	FROM td_character WITH(NOLOCK)
	WHERE AccountName = @i_AccountName
	ORDER BY Experience DESC

	IF @o_CharacterName IS NULL
	BEGIN
		SET @o_RetCode	= 100		--									100	==> �ش� ������ ĳ���Ͱ� ����
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
--					// 2007-11-16 by cmkwon, ���̺� Unique Key ������ �� ������ �߰��� üũ �Ŀ� �߰� - td_tutorialComplete
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
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �ε� ���ν��� �߰�
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
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - CharacterUID��������
--====
CREATE PROCEDURE dbo.atum_getCharacterUIDByCharacterName
	@i_CharacterName		VARCHAR(20),	
	@i_CharInflMask			TINYINT
AS
	-- #define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SELECT UniqueNumber
	FROM td_character WITH(NOLOCK)
	WHERE CharacterName = @i_CharacterName AND 0 = Race & 0x4000 AND 0 <> InfluenceType & @i_CharInflMask
GO

--!!!!
-- Name:dbo.atum_insert2WarpableUserList
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ���� �߰��ϱ�
--			#define ERR_NO_ERROR									0x0000
--			#define ERR_DB_INTEGRITY_CONSTRAINT_VIOLATION			0x2103		// integrity constraint violation, 23000
--====
CREATE PROCEDURE dbo.atum_insert2WarpableUserList
	@i_RetErr				INT		OUTPUT,		-- 0�̸� No Error, �� �ܴ̿� ������
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
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��� ���� �����ϱ�
--====
CREATE PROCEDURE dbo.atum_deleteAllWarpableUserList
AS
	DELETE FROM dbo.td_user_list_warpable_to_map
GO

--!!!!
-- Name:dbo.atum_deleteWarpableUser
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ���� �߰��ϱ�
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
-- DESC			 : �������� ���� ������ ���ν���
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
-- DESC			 : �������� NPC������ �����ϴ� ���ν���
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
-- DESC			 : �������� ���� ������ �����ϴ� ���ν���
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
-- DESC			 : ���� ���������� �ð� �����ϴ� ���ν���
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
-- DESC			 : ���� ���������� �ð� ������������ ���ν���
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadOutPostNextWarTime
AS
	SELECT OutPostWarStartTime
	FROM atum2_db_account_test.dbo.ti_OutPostNextWarTime WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_GetInfluenceLeaderGuildUID
-- DESC			 : ������ ���� UID��������
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
-- DESC			 : ���� ���� ������ ���ν���
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadCityLeaderInfo
AS
	SELECT MapIndex, Influence, CharacterUID, ExpediencyFundCumulative, ExpediencyFund, ExpediencyFundRate, Notice
	FROM td_CityLeaderInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InitExpediencyFund
-- DESC			 : �ǰ��� ���� �ʱ��ϴ� ���ν���
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
-- DESC			 : �ǰ��� ���� �����ϴ� ���ν���
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
-- DESC			 : �ǰ��� ȯ�� ���ν���
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
-- DESC			 : �ǰ����� ���� �����ϴ� ���ν���
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
-- DESC			 : ���� ���� ���� ���ν���
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
-- DESC			 : �������� ��� ���ν���
-- 2007-08-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_RegNotice
	@i_MapIndex						INT,
	@i_CharacterUID					INT,
	@i_Notice						VARCHAR(512)
AS
	DECLARE	@CheckCount INT
	SET @CheckCount = (SELECT Count(*) FROM td_CityLeaderInfo WHERE MapIndex = @i_MapIndex)

	-- �������� ���� ���� ���� ��츦 ����Ͽ� �߰��ϴ� ��ƾ�� �д�.
	IF (@CheckCount = 0)
	BEGIN
	--  2007-10-18 by dhjin, �߰� ���� �����Ѵ�.
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
-- DESC			 : �������� ����.���� ���ν���
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
-- Desc: // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - 2���н����� ������Ʈ ���ν���
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
-- DESC			 : ������ ���� �� td_CityLeaderInfo�� ���� ����
-- 2007-09-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateCityLeaderByLeaderSet
	@i_Infltype				TINYINT,
	@i_Possess				INT
AS
	DECLARE @CountInfl INT
	SET @CountInfl = (SELECT count(*) FROM dbo.td_CityLeaderInfo WHERE Influence = @i_Infltype)

	IF @i_Infltype = 2 -- ����������
	BEGIN
		UPDATE dbo.td_CityLeaderInfo
		SET	Influence = 2, CharacterUID = @i_Possess, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 10 + (@CountInfl * 5), Notice = NULL
		WHERE MapIndex = 2001
	END

	ELSE IF @i_Infltype = 4 -- �˸���
	BEGIN
		UPDATE dbo.td_CityLeaderInfo
		SET	Influence = 4, CharacterUID = @i_Possess, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 10 + (@CountInfl * 5), Notice = NULL
		WHERE MapIndex = 2002
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InitCityLeaderForInflLeader
-- DESC			 : ���� �ʱ�ȭ �� td_CityLeaderInfo�� ������ ���� �ʱ�ȭ�Ѵ�.
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
-- DESC				: ���� ���� �� �������� ���ν��� (pollpoint���)
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadActionByLevel
AS
	SELECT Level, PollPoint
	FROM atum2_db_account_test.dbo.ti_ActionByLevel
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadPollDate
-- DESC				: ��ǥ ���� �Ⱓ, ��ǥ��, �����ϵ� �������� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadPollDate
AS
	SELECT ApplicationStartDate, ApplicationEndDate, VoteStartDate, VoteEndDate, Election
	FROM atum2_db_account_test.dbo.td_PollDate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdatePollDate
-- DESC				: ��ǥ ���� �Ⱓ, ��ǥ��, �����ϵ� ������Ʈ ���ν���
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
-- DESC				: ��ǥ�� ����Ʈ �������� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadVoterList
AS
	SELECT AccountUID, CharacterUID, LeaderCandidateNum
	FROM dbo.td_VoterList
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InitVoterList
-- DESC				: ��ǥ�� ����Ʈ �ʱ�ȭ ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitVoterList
AS
	DELETE FROM dbo.td_VoterList
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertVoterList
-- DESC				: ��ǥ�� ��� ���ν���
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
-- DESC				: ������ �ĺ� ����Ʈ �������� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadLeaderCandidate
AS
	SELECT LeaderCandidateNum, AccountUID, CharacterUID, CharacterName, GuildUID, GuildName, Influence, DeleteCandidate, PollCount, CampaignPromises
	FROM dbo.td_LeaderCandidate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InitLeaderCandidate
-- DESC				: ������ �ĺ� ����Ʈ �ʱ�ȭ ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitLeaderCandidate
AS
	DELETE FROM dbo.td_LeaderCandidate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertLeaderCandidate
-- DESC				: ������ �ĺ� ��� ���ν���
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
		SET @o_RetCode = 10		-- ������ �������� �ʰų� �䱸 ������ �۴�.
		RETURN
	END
	
	SET @ReqGuildMemberNum = (SELECT Count(*) FROM dbo.td_GuildMember WITH (NOLOCK) WHERE GuildUniqueNumber = @i_GuildUID)
	IF(@ReqGuildMemberNum < @i_ReqGuildMemberNum)
	BEGIN
		SET @o_RetCode = 20		-- ������ �������� �ʰų� �䱸 ���� ������ �۴�
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
-- DESC				: ��ǥ�� ȹ�� ǥ ������Ʈ ���ν���
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
-- DESC				: ������ �ĺ� Ż�� ������Ʈ ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateLeaderDeleteCandidate
	@i_CharacterUID		INT
AS
	UPDATE dbo.td_LeaderCandidate SET DeleteCandidate = 1 WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_SelectLeaderCandidateInfoByRealTimeVariable
-- DESC				: ������ �ĺ��� �ǽð����� ��ȭ �� �� �ִ� ������(level, guildfame���) ������ ���ν���
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
-- DESC				: // 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - ���� ���� ������Ʈ
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
-- DESC				: // 2007-11-13 by cmkwon, �����ϱ� ��� �߰� - ���� �޴� ĳ���� ���� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGiveTargetCharacter
	@i_CharName				VARCHAR(20)
AS
	--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SELECT a.AccountName, a.AccountUniqueNumber, a.ConnectingServerGroupID, am.ItemNum, am.ExpireTime, c.UniqueNumber, c.InfluenceType, c.GuildName, c.UnitKind, c.Level
	FROM td_account a WITH(NOLOCK) INNER JOIN td_character c WITH(NOLOCK) ON c.AccountUniqueNumber = a.AccountUniqueNumber
	LEFT OUTER JOIN td_accountCashStore am WITH(NOLOCK) ON a.AccountUniqueNumber = am.AccountUniqueNumber
	WHERE c.CharacterName = @i_CharName AND 0 = c.Race & 0x4000
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdatePilotFace
-- DESC				: // 2007-11-21 by cmkwon, PilotFace ���� ī�� ���� - �ش� ĳ������ PilotFace�� �����Ѵ�.
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
-- DESC				: // 2007-11-28 by cmkwon, �����ý��� ���� - dbo.atum_InsertNotifyMsg �߰�
--					  // 2007-12-20 by cmkwon, �����ý��� ���� ���� - �߰��� NotifyMsgUID �� �����Ѵ�.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertNotifyMsg
	@i_CharacterUID				INT,							-- ���� ���� CharacterUID
	@i_NotifyMsgType			TINYINT,						-- ���� �޽��� Ÿ��(NOTIFY_MSG_TYPE_XXX)
	@i_NotifyMsgString			VARCHAR(512),					-- ���� �޽��� ��Ʈ��(512)
	@i_SenderCharacterUID		INT,							-- ������ ���� CharacterUID
	@i_SenderCharacterName		VARCHAR(20)						-- ������ ���� CharacterName
AS
	INSERT INTO dbo.td_NotifyMsg(CharacterUID, NotifyMsgType, NotifyMsgString, SenderCharacterUID, SenderCharacterName)
	VALUES(@i_CharacterUID, @i_NotifyMsgType, @i_NotifyMsgString, @i_SenderCharacterUID, @i_SenderCharacterName)

	RETURN SCOPE_IDENTITY();		-- // 2007-12-20 by cmkwon, �����ý��� ���� ���� - �߰��� NotifyMsgUID �� �����Ѵ�.
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, �����ý��� ���� - dbo.atum_GetNotifyMsg �߰�
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetNotifyMsg
	@i_CharacterUID				INT								-- ���� ���� CharacterUID
AS
	SELECT NotifyMsgUID, CharacterUID, NotifyMsgType, NotifyMsgString, SenderCharacterUID, SenderCharacterName, CreatedTime
	FROM dbo.td_NotifyMsg WITH(NOLOCK)
	WHERE CharacterUID = 0 OR CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, �����ý��� ���� - dbo.atum_DeleteNotifyMsg �߰�
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
-- DESC				: // 2008-01-10 by cmkwon, ������ �̺�Ʈ �ý��ۿ� �� ���� �ý��� �߰� - dbo.atum_UseCouponNumber �߰�
--						���� ��ȣ�� ��밡���� ������ȣ ���� üũ�ϰ� �����ϸ� ���Ȱ����� ������Ʈ �Ѵ�.
--						#define ERR_PROTOCOL_QUEST_COUPON_INVALID_NUMBER				0x2710		// ������ȣ�� DB�� �������� �ʰų�
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
-- DESC      : // 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� ������ �����ϴ� ��� �߰� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_DeleteDeletedCharacter
	@i_CharName			VARCHAR(20),
	@i_CharacterUID		INT
AS
	-- 2008-01-17 by cmkwon, �����Ⱦ��� ������ ĳ�������� üũ
	IF NOT EXISTS( SELECT * FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharacterUID AND 0 <> (Race & 0x4000) )
		BEGIN
			RETURN	10			-- ������ ������ ĳ���Ͱ� �ƴϴ�
		END
	
	-- 1. ĳ���� ���� �������� ��æƮ ����	
	DELETE td_Enchant FROM td_Store s INNER JOIN td_Enchant e ON s.UniqueNumber = e.TargetItemUniqueNumber
	WHERE s.Possess = @i_CharacterUID AND s.ItemStorage <> 2

	-- 2. ĳ���� ���� ������ ����
	DELETE FROM td_Store WHERE Possess = @i_CharacterUID AND ItemStorage <> 2

	-- 3. ĳ���� �� ���� ����
	DELETE FROM td_QuickSlot WHERE CharacterUID = @i_CharacterUID

	-- 4. ĳ���� ���� ��ų ����
	DELETE FROM td_StoreSkill WHERE Possess = @i_CharacterUID 

	-- 5. ����Ʈ ���̺��� ����
	DELETE FROM td_CharacterQuest WHERE CharacterUniqueNumber = @i_CharacterUID

	-- 6. ����Ʈ ���� ���� ���̺��� ����
	DELETE FROM td_CharacterQuestMonsterCount WHERE CharacterUniqueNumber  = @i_CharacterUID

	-- 7. ģ������Ʈ���� ����
	DELETE FROM td_FriendList
	WHERE CharacterName = @i_CharName OR FriendName = @i_CharName

	--8. Ʃ�丮�� ����Ʈ���� ����
	DELETE FROM td_TutorialComplete WHERE CharacterUID = @i_CharacterUID

	-- last ĳ���� ���̺��� ����
	DELETE FROM td_Character WHERE UniqueNumber = @i_CharacterUID


	RETURN 0
GO


--------------------------------------------------------------------------------
-- Name: dbo.atum_Delete_All_Character_By_AccountName
-- Desc: -- // 2008-02-13 by cmkwon, ���� ���� �ý��� ����� - atum2_db_[n].dbo.atum_Delete_All_Character_By_AccountName() ���ν��� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_All_Character_By_AccountName
	@i_AccountName VARCHAR(20)        -- AccountName
AS

	DECLARE @CharacterCnt INT
	SET @CharacterCnt = (SELECT Count(*) FROM dbo.td_Character WITH (NOLOCK) WHERE AccountName = @i_AccountName)
	IF (@CharacterCnt IS NULL)
	BEGIN
		RETURN		-- // 2008-02-13 by cmkwon, �ش� ������ ĳ���Ͱ� ����
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

		-- // 2008-02-13 by cmkwon, ���� ������ ĳ���ͷ� ����
		--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
		UPDATE dbo.td_character
		SET Race = Race | 0x4000
		WHERE UniqueNumber = @CharUID

		-- // 2008-02-13 by cmkwon, ���� ������ ĳ���� �ٷ� ����
		DECLARE @RetCode INT		
		EXEC @RetCode = dbo.atum_admin_DeleteDeletedCharacter @CharName, @CharUID

		SELECT TOP 1 @CharUID= UniqueNumber, @CharName= CharacterName FROM dbo.td_Character WITH (NOLOCK) 
		WHERE AccountName = @i_AccountName AND UniqueNumber > @CharUID ORDER BY UniqueNumber

		SET @i			= @i + 1		
	END

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_updateCharacterInfo
-- DESC				: �Ʒ��� ���� - �ɸ��� ���� ������Ʈ
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

		-- // ���� �����͸� ������Ʈ �Ѵ�.
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

		-- // atum2_db_arena_test.dbo.td_character ���̺��� �ش� ĳ���͸����� ���� ó���Ѵ�. - ������ ĳ���͸��� ���� �� �� �ִ�. ������� �ʴ� �����̴�
		DELETE atum2_db_arena_test.dbo.td_character
		WHERE CharacterName = @i_NewCharacterName

		-- // ������ �߰��Ѵ�.
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
-- DESC				: �Ʒ��� ���� - �ɸ��� ���� �ε�
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
-- DESC				: �Ʒ��� ���� - �Ʒ��� DB�� ����Ÿ ����
-- 2008-01-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.arena_CopyDBInfo
	@o_RetCode					INT OUTPUT,
	@i_ArenaCharacterUID		INT,
	@i_CharacterUID				INT,
	@i_AccountUID				INT			
AS
	SET @o_RetCode = 0		--			0	==> ���� ����

	DELETE FROM atum2_db_arena_test.dbo.td_enchant 
	WHERE TargetItemUniqueNumber IN (SELECT UniqueNumber FROM atum2_db_arena_test.dbo.td_store WHERE Possess = @i_ArenaCharacterUID)
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 30		--			30	==> ��þƮ���� ���� ����
		RETURN              
	END
	DELETE FROM atum2_db_arena_test.dbo.td_store WHERE Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 40		--			40	==> ���������� ���� ����
		RETURN              
	END
	DELETE FROM atum2_db_arena_test.dbo.td_storeskill WHERE Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 70				--			70	==> ��ų ���� ����
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
		SET @o_RetCode = 20		--			20	==> �Ʒ��� ������ �ɸ��� ���� ������Ʈ ����
		RETURN              
	END

-- td_storeskill
	INSERT atum2_db_arena_test.dbo.td_storeskill (AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime)
	SELECT AccountUniqueNumber, @i_ArenaCharacterUID, ItemWindowIndex, ItemNum, CreatedTime, NULL
	FROM dbo.td_storeskill
	WHERE Possess = @i_CharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 80				--			80	==> ��ų �߰� ����
		RETURN              
	END

-- td_store
	-- â��� ĳ�����κ��� �����۰� ��æƮ(td_Store, td_Enchant)
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL

	SELECT TOP 1 @SItemUID=UniqueNumber 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 ORDER BY UniqueNumber
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 50				--			50	==> ���μ������� ������ ���� ������ ����
		RETURN              
	END

	SELECT @SItemCnt=COUNT(*) 
	FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
	ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000
	IF (@@Error <> 0)
	BEGIN 
		SET @o_RetCode = 51				--			51	==> ���μ������� ������ ���� ������ ����
		RETURN              
	END
	IF (@SItemUID IS NULL)
	BEGIN 
		SET @o_RetCode = 52				--			52	==> ���μ������� ������ ���� ������ ����
		RETURN              
	END
	IF (@SItemCnt IS NULL)
	BEGIN 
		SET @o_RetCode = 53				--			53	==> ���μ������� ������ ���� ������ ����
		RETURN              
	END
	IF (@SItemCnt = 0)
	BEGIN 
		SET @o_RetCode = 54				--			54	==> ���μ������� ������ ���� ������ ����
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
				SET @o_RetCode = 60			--			60	==> ������ �߰� ����
				RETURN              
			END


			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- ��æƮ�� �����ϴ� �������� Ÿ�� �������� ��æƮ �߰�
			IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_arena_test.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @o_RetCode = 61		--			61	==> ��þƮ �߰� ����
					RETURN              
				END
			END

			--------------------------------------------------------------------------------
			-- ���� �������� UID�� �˻��Ѵ�.
			SELECT TOP 1 @SItemUID= UniqueNumber 
			FROM dbo.td_store AS S WITH (NOLOCK) INNER JOIN ti_item AS I WITH (NOLOCK)
			ON S.Possess = @i_CharacterUID AND S.itemnum = I.itemnum AND S.itemstorage = 0 AND 0 = I.ItemAttribute & 0x8000 AND UniqueNumber > @SItemUID 
			ORDER BY UniqueNumber
			IF (@SItemUID IS NULL)
			BEGIN 
				SET @o_RetCode = 62			--			62	==> ���μ������� ������ ���� ������ ����
				RETURN              
			END
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Insert_MSWar
-- DESC				: ���� �α� �߰�
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
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
-- DESC				: ���� �α� ��������
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Get_MSWar
AS
	SELECT   AttInfluence, MonsterUID, ContributionPoint, MSWarStartTime, MSWarEndTime, WinInfluence
	FROM     dbo.atum_log_MSWar WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_Insert_SPWar
-- DESC				: ������ �α� �߰�
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
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
-- DESC				: ������ �α� ��������
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_Get_SPWar
AS
	SELECT   AttInfluence, SPSummonMapIndex, SPWarStartTime, SPWarEndTime, WinInfluence
	FROM     dbo.atum_log_SPWar WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_InitMSWar
-- DESC				: ���� ����Ʈ �ʱ�ȭ ���ν���
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_InitMSWar
AS
	DELETE FROM dbo.atum_log_MSWar
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_InitSPWar
-- DESC				: ������ ����Ʈ �ʱ�ȭ ���ν���
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_InitSPWar
AS
	DELETE FROM dbo.atum_log_SPWar
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_MSWarOptionType
-- DESC				: ������ ����Ʈ �ʱ�ȭ ���ν���
-- // 2008-04-10 by dhjin, ���� ���� ǥ�� ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_MSWarOptionType
	@i_InfluenceType		TINYINT,
	@i_MSWarOptionType		SMALLINT
AS
	UPDATE dbo.td_InfluenceWarData SET MSWarOptionType = @i_MSWarOptionType WHERE InfluenceType = @i_InfluenceType
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadServerGroupInfo
-- DESC				: ServerGroup ���� ���� �ε�
-- // 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
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
-- DESC				: ServerGroup ���� ���� �ε�
-- // 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
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
-- DESC				: ĳ������ ������ �����´�. ���� ������  ĳ���� ����.
-- // 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
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
-- DESC		 : ���� �Ⱓ ���� ���� �����ϱ�
-- // 2008-05-13 by dhjin, EP3 �����ý��� - 
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
-- DESC		 : ���� ��������
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_Letter
	@i_RecvCharacterUID		INT,
	@i_LetterPassedRangeDay	INT
AS
	SELECT LetterUID, SendCharacterName, SendDate, CheckRead, Title, Content FROM dbo.td_Letter WITH (NOLOCK) WHERE RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Send_Letter
-- DESC		 : ���� ������
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
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

	-- �����ϴ� �������� üũ�Ѵ�.
	SET @o_RecvCharacterUID = ( SELECT UniqueNumber FROM dbo.td_character WITH (NOLOCK) WHERE CharacterName = @i_RecvCharacterName )
	IF(@o_RecvCharacterUID IS NULL)
	BEGIN
		SET @o_Err = 1		-- 1 ������ �������� �ʴ´�.
		RETURN
	END
	
	-- �ڽ� �ź� üũ
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_RecvCharacterName AND FriendName = @i_SendCharacterName )
	IF(0 <> @CheckCount)
	BEGIN
		SET @o_Err = 2		-- 2 �ź� ��Ͽ� �ִ� �����̴�.
		RETURN
	END	

	-- ���� �ź� üũ
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_SendCharacterName AND FriendName = @i_RecvCharacterName )
	IF(0 <> @CheckCount)
	BEGIN
		SET @o_Err = 3		-- 3 ������ ���� �ź��� �����̴�.
		RETURN
	END	

	-- ���� �߰�
	INSERT INTO dbo.td_Letter (RecvCharacterUID, SendCharacterName, SendDate, CheckRead, Title, Content)
		VALUES (@o_RecvCharacterUID, @i_SendCharacterName, @i_SendDate, 0, @i_Title, @i_Content)

	RETURN SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Read_Letter
-- DESC		 : ���� �б�
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Read_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	UPDATE dbo.td_Letter SET CheckRead = 1 WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Delete_Letter
-- DESC		 : ���� ����
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
AS
	DELETE FROM dbo.td_Letter WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Get_AllLetter
-- DESC		 : ��ü ���� ��������
-- // 2008-05-09 by dhjin, EP3 �����ý��� - 
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
		-- ��ü ������ ���� ����
	UNION
	SELECT A.AllLetterUID, A.SendCharacterName, A.SendDate, A.Title, A.Content, 1 
		FROM dbo.td_AllLetter AS A WITH (NOLOCK) INNER JOIN dbo.td_ReadAllLetter AS R WITH (NOLOCK) 
		ON A.SendCharacterInfl = @i_RecvCharacterInfl AND R.RecvCharacterUID = @i_RecvCharacterUID AND A.AllLetterUID = R.AllLetterUID AND 0 = R.CheckDelete
		-- ��ü ������ �о����� ���������� ����
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Send_AllLetter_ByLeader
-- DESC		 : �����ο��� ���� �߼����� ���� ���� �߰�
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Send_AllLetter_ByLeader
	@i_SendCharacterInfl	TINYINT,
	@i_SendCharacterUID		INT,
	@i_SendCharacterName	VARCHAR(20),
	@i_SendDate				DATETIME,
	@i_Title				VARCHAR(40),
	@i_Content				VARCHAR(1000)
AS
	-- ���� �߰�
	INSERT INTO dbo.td_AllLetter (SendCharacterInfl, SendCharacterUID, SendCharacterName, SendDate, Title, Content)
		VALUES (@i_SendCharacterInfl, @i_SendCharacterUID, @i_SendCharacterName, @i_SendDate, @i_Title, @i_Content)
	RETURN SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_Insert_ReadAllLetter_ByRead
-- DESC		 : �����ο��� ���� �߼� ����
-- // 2008-05-08 by dhjin, EP3 �����ý��� - 
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
-- DESC		 : �����ο��� ���� �߼� ����
-- // 2008-05-08 by dhjin, EP3 �����ý��� - 
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
-- DESC		 : ��ü ���� ����
-- // 2008-05-09 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_AllLetter
	@i_AllLetterUID			BIGINT
AS
	DELETE FROM dbo.td_ReadAllLetter WHERE AllLetterUID = @i_AllLetterUID
	DELETE FROM dbo.td_AllLetter WHERE AllLetterUID = @i_AllLetterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildRank
-- DESC				: ���� ��ũ ��������
-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ������ ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildNotice
	@GuildUniqueNum INT,
	@Notice			VARCHAR(512)
AS
	UPDATE dbo.td_Guild SET Notice = @Notice WHERE GuildUniqueNumber = @GuildUniqueNum
GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildIntroduction
-- DESC				: ���� �Ұ� ������Ʈ
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� �Ұ� ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteGuildIntroduction
	@i_GuildUID		INT
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE GuildUID = @i_GuildUID
	DELETE FROM dbo.td_GuildIntroduction WHERE GuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteGuildIntroduction_By_PassedRangeDay
-- DESC				: ���� ���� �Ұ� ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� �Ұ� ��ü ��������
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� �Ұ� ��������
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGuildIntroduction
	@i_GuildUID					INT
AS
	SELECT Content, WriteDate FROM dbo.td_GuildIntroduction WITH (NOLOCK) WHERE GuildUID = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildApplicant
-- DESC				: ���� ������ ��������
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: �ڱ� �Ұ��� ��������
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: �ڱ� �Ұ��� ����
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteSelfIntroduction
	@i_CharacterUID					INT
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateSelfIntroduction
-- DESC				: �ڱ� �Ұ��� ������Ʈ
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: �� ���� �� ����
-- JOB				: ���� ��ħ�ð����� JOB�� �Ǵ�.
-- // 2008-06-05 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� ���� �� ���� 
-- JOB				: ���� ��ħ�ð����� JOB�� �Ǵ�.
-- // 2008-06-05 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ������ ĳ�� ���� ������
-- // 2008-06-20 by dhjin, EP3 - ���� ���� ����
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
-- DESC				: ���� ���� ��������
-- // 2008-06-20 by dhjin, EP3 ���������ɼ� -
--------------------------------------------------------------------------------
CREATE PROCEDURE atum_GetUserInfo
	@i_CharacterUID		INT
AS
	SELECT PilotFace, CharacterName, UnitKind, GuildName, GuildUniqueNumber, Level, MapIndex, ChannelIndex, Propensity, LastStartedTime, SecretInfoOption
	FROM dbo.td_character
	WHERE UniqueNumber = @i_CharacterUID
GO
