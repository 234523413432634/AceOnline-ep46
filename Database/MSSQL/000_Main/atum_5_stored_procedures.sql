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
-- Function NAME	: dbo.atum_IsChargableItem
-- DESC				: // 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - ChargableItem ���� üũ
--------------------------------------------------------------------------------
CREATE FUNCTION dbo.atum_IsChargableItem(@ItemKind TINYINT)
RETURNS INT
AS
BEGIN
	-- #define IS_CHARGABLE_ITEM(_ITEM_KIND)	(IS_WEAPON(_ITEM_KIND)||(_ITEM_KIND)==ITEMKIND_TANK || (_ITEM_KIND)==ITEMKIND_ACCESSORY_UNLIMITED || (_ITEM_KIND)==ITEMKIND_ACCESSORY_TIMELIMIT)	// ITEM::Charging�� ITEM_GENERAL::CurrentCount�� �Ҵ��ؼ� ���� ������
	-- #define ITEMKIND_TANK					(BYTE)22	// ��ũ(EP ��ũ ��)
	-- #define ITEMKIND_ACCESSORY_UNLIMITED	(BYTE)31	// 2006-03-17 by cmkwon, ���ð��� <����>�� �׼����� ������
	-- #define ITEMKIND_ACCESSORY_TIMELIMIT	(BYTE)32	// 2006-03-17 by cmkwon, ���ð��� �ð� ������ �ִ� �׼����� ������
	IF (0 <> dbo.atum_IsWeapon(@ItemKind)) OR (22 = @ItemKind) OR (31 = @ItemKind) OR (32 = @ItemKind)
	BEGIN 
		RETURN 1
	END

	RETURN 0
END
GO

--------------------------------------------------------------------------------
-- For Simulating Oracle Sequences In MS SQL
--------------------------------------------------------------------------------
-- !!!!
-- Name:
-- Desc:  for ScarcityNumber, WOULD NOT BE USED
-- ====
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

-- !!!!
-- Name:
-- Desc:
--			// 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- ====
CREATE PROCEDURE dbo.atum_admin_GetAccountInfo
	@accName varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS	
	SELECT a.accountname, a.AccountUniqueNumber, c.charactername, c.uniquenumber
	FROM atum2_db_account.dbo.td_account a, td_Character c
	WITH (NOLOCK)
	WHERE a.accountname = @accName AND c.accountuniquenumber = a.AccountUniqueNumber
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE a.accountname LIKE @accName AND c.accountuniquenumber = a.AccountUniqueNumber
GO

-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertStoreItemToAllCharacter_DB
-- 	@vItemNum INT
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_Store
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, 1, 0, 99,
-- 				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WHERE i.ItemNum = @vItemNum  AND
-- 			 c.uniquenumber IN
-- 			( SELECT uniquenumber FROM td_Character)
-- GO


-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertStoreItemCountableToAllCharacter_DB
-- 	@vItemNum INT,
-- 	@num INT
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_Store
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @num, 0, 99,
-- 				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WHERE i.ItemNum = @vItemNum  AND
-- 			 c.uniquenumber IN
-- 			( SELECT uniquenumber FROM td_Character)
-- GO


-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB
-- 	@charac_name varchar(20),
-- 	@ItemNum INT
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_Store
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, 1, 0, 99,
-- 				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WHERE i.ItemNum = @ItemNum AND c.charactername = @charac_name
-- 		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 		-- WHERE i.ItemNum = @ItemNum AND c.charactername LIKE @charac_name
-- 	
-- 	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
-- 	--RETURN SCOPE_IDENTITY();
-- 	SELECT SCOPE_IDENTITY();
-- GO


-- 2005-12-07 by cmkwon, ������� ����
-- !!!!
---- Name:
---- Desc: â�� �־��ֱ�
-- ====
--CREATE PROCEDURE dbo.atum_admin_InsertStoreItemToAccountStore
--	@account_name varchar(20),
--	@ItemNum INT
--AS
--	INSERT INTO td_Store
--		SELECT a.accountUniqueNumber, 0, 0, 1, 0, 99,
--				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
--		FROM atum2_db_account.dbo.ti_Item i, atum2_db_account.dbo.td_account a
--		WHERE i.ItemNum = @ItemNum AND a.AccountName LIKE @account_name
--	RETURN SCOPE_IDENTITY();
--GO


-- !!!!
-- Name: dbo.atum_admin_InsertStoreItemCountable_DB
-- Desc:
--			-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ScarcityNumber �ʵ� ����
--			-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--			-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--			-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- ====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItemCountable_DB
	@charac_name varchar(20),	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ����
	@ItemNum INT,
	@CurrentCount INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @CurrentCount, 99,
				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate(), 0, 0, 0
		FROM atum2_db_account.dbo.ti_Item i, td_Character c
		WHERE i.ItemNum = @ItemNum AND c.charactername = @charac_name

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	SELECT SCOPE_IDENTITY();
GO

-- !!!!
-- Name:
-- Desc:
--		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ScarcityNumber �ʵ� ����
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- ====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum
	@charac INT,
	@ItemNum INT,
	@CurrentCount INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, @CurrentCount, 99,
				@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate(), 0, 0, 0
		FROM atum2_db_account.dbo.ti_Item i, td_Character c
		WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	SELECT SCOPE_IDENTITY();
GO

-- !!!!
-- Name:
-- Desc:
--		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ScarcityNumber �ʵ� ����
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- ====
CREATE PROCEDURE dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default
	@charac INT,
	@ItemNum INT,
	@CurrentCount INT,
	@wear	TINYINT,
	@ItemWindowIndex	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @ItemKind TINYINT
	SET @ItemKind = (SELECT Kind FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE ItemNum = @ItemNum)

	IF (dbo.atum_IsWeapon(@ItemKind) = 1)
	BEGIN
		-- ������̸� charging�� count�� �Ҵ�
		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
		INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, i.Charging, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate(), 0, 0, 0
			FROM atum2_db_account.dbo.ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	ELSE
	BEGIN
		-- ������� �ƴϸ� �׳� @Count�� �Ҵ�
		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
		INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			SELECT c.accountUniqueNumber, c.UniqueNumber, 0, @wear, @CurrentCount, @ItemWindowIndex,
					@ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate(), 0, 0, 0
			FROM atum2_db_account.dbo.ti_Item i, td_Character c
			WITH (NOLOCK)
			WHERE i.ItemNum = @ItemNum AND c.uniquenumber = @charac
	END
	
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	SELECT SCOPE_IDENTITY();
GO


-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- character���� ��� ����� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertAllWeaponToCharacter
-- 	@acc_name		varchar(20),
-- 	@charac_name	varchar(20)
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_Store
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, i.Charging, 0, 99,
-- 				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WITH (NOLOCK)
-- 		WHERE c.accountname = @acc_name AND c.charactername = @charac_name AND i.ItemNum IN	( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
-- 		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 		-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND i.ItemNum IN ( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
-- GO


-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- character���� ���� ������ �´� ����� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertAllWeaponToCharacterByUnitKind
-- 	@acc_name varchar(20),
-- 	@charac_name varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_Store
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 0, 0, i.Charging, 0, 99,
-- 				i.ItemNum, 0, 0, 0, i.Endurance, 0, 0, GetDate()
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WITH (NOLOCK)
-- 		WHERE c.accountname = @acc_name AND c.charactername = @charac_name AND (i.reqUnitKind & c.unitkind) != 0 AND i.ItemNum IN ( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
-- 		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 		-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND (i.reqUnitKind & c.unitkind) != 0 AND i.ItemNum IN ( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 0 AND Kind <= 11)
-- GO


-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ������� �ʴ� ���ν��� ����
-- -- character���� ��� ��밡���� ��ų�� ����
-- -- !!!!
-- -- Name:
-- -- Desc:
-- -- ====
-- CREATE PROCEDURE dbo.atum_admin_InsertAllSkillToCharacter
-- 	@acc_name varchar(20),
-- 	@charac_name varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	INSERT INTO td_StoreSkill
-- 		SELECT c.accountUniqueNumber, c.UniqueNumber, 99, i.ItemNum, GetDate(), NULL
-- 		FROM atum2_db_account.dbo.ti_Item i, td_Character c
-- 		WITH (NOLOCK)
-- 		WHERE c.accountname = @acc_name AND c.charactername = @charac_name AND (i.reqUnitKind & c.unitkind) != 0 AND i.skilllevel = 1 AND i.ItemNum IN ( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 50  AND Kind <= 53)
-- 		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 		-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name	AND (i.reqUnitKind & c.unitkind) != 0 AND i.skilllevel = 1 AND i.ItemNum IN	( SELECT ItemNum FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK) WHERE Kind >= 50  AND Kind <= 53)
-- GO

-- character ������ ��� ������ ��ȯ
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_GetStoreItemCharacter
	@acc_name varchar(20),
	@charac_name varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
	-- SELECT a.accountname, c.charactername, i.itemname, s.*
	-- FROM td_Store s, atum2_db_account.dbo.td_account a, td_Character c, atum2_db_account.dbo.ti_Item i
	-- WITH (NOLOCK)
	-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber
	--	AND s.itemnum = i.itemnum
	-- ORDER BY c.charactername, s.itemnum
	SELECT a.accountname, c.charactername, i.Itemname, s.*
	FROM td_Store s, atum2_db_account.dbo.td_account a, td_Character c, atum2_db_account.dbo.ti_Item i
	WITH (NOLOCK)
	WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber AND s.Itemnum = i.Itemnum
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber AND s.Itemnum = i.Itemnum
	ORDER BY c.charactername, s.Itemnum
GO

-- character ������ ��� ��ų ��ȯ
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_GetAllSkillOfCharacter
	@acc_name varchar(20),
	@charac_name varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemName, ItemNum ����
	SELECT a.accountname, c.charactername, i.ItemName, i.skilltype, s.*
	FROM td_StoreSkill s, atum2_db_account.dbo.td_account a, td_Character c, atum2_db_account.dbo.ti_Item i
	WITH (NOLOCK)
	WHERE c.accountname = @acc_name AND c.charactername = @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber AND s.ItemNum = i.ItemNum
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE c.accountname LIKE @acc_name AND c.charactername LIKE @charac_name AND a.AccountUniqueNumber = s.accountuniquenumber AND s.possess = c.uniquenumber AND s.ItemNum = i.ItemNum
	ORDER BY c.charactername, s.ItemNum
GO

-- ���� ���� ����
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_SetAccountType
	@acc_name varchar(20),
	@type int
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account
	SET AccountType = @type
	WHERE  accountname = @acc_name
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE  accountname LIKE @acc_name
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_SetAdminCharacter
	@charac_name varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
	SET race = race | 128
	WHERE charactername LIKE @charac_name
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE charactername LIKE @charac_name
GO

-- ��� ĳ���� ���� - ���� ����
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_DeleteAccountWOAccount
	@accName varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @accNum INT
	SET @accNum = (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WHERE accountname = @accName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @accNum = (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WHERE accountname LIKE @accName)

	DELETE FROM td_Store WHERE accountuniquenumber = @accNum
	DELETE FROM td_StoreSkill WHERE accountuniquenumber = @accNum

	DELETE FROM td_Character WHERE accountuniquenumber = @accNum
GO

-- !!!!
-- Name:
-- Desc:
-- ====
-- // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - �Ʒ��� ���� ������.
-- CREATE PROCEDURE dbo.atum_admin_SetMoney
-- 	@charac_name varchar(64),
-- 	@moneyAmount int
-- AS
-- 	DECLARE @characNum INT
-- 	SET @characNum = (SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE charactername LIKE @charac_name)
-- -- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
-- -- 	UPDATE td_Store
-- -- 	SET CurrentCount = @moneyAmount
-- -- 	WHERE possess = @characNum AND itemnum = 7000022
--  	UPDATE td_Store
-- 	SET CurrentCount = @moneyAmount
-- 	WHERE possess = @characNum AND Itemnum = 7000022
-- GO
CREATE PROCEDURE dbo.atum_admin_SetMoney
 	@charac_name varchar(20),
 	@moneyAmount int
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - LIKE �� ������� �ʰ� ����.
	DECLARE @characNum INT
	SET @characNum = (SELECT UniqueNumber FROM td_Character WITH (NOLOCK) WHERE charactername = @charac_name)
 	UPDATE td_Store
	SET CurrentCount = @moneyAmount
	WHERE possess = @characNum AND Itemnum = 7000022
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_admin_SetBonusStat
	@charac_name varchar(20),
	@bonusstat TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
	SET BonusStat = @bonusstat
	WHERE charactername = @charac_name
GO

-- // 2009-08-03 by cmkwon, ���� �ٸ� ���񽺿��� ������� �ʴ� ���ν���(������ ���� ���� ���) - 
-- -- !!!!
-- -- Name:
-- -- Desc:
-- --		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- -- ====
-- CREATE PROCEDURE dbo.atum_CreateCharacterBulk
-- 	@CharacterName		VARCHAR(20)
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 
-- 	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
-- 	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
-- 							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
-- 							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
-- 		SELECT @CharacterName, @CharacterName, a.AccountUniqueNumber, Gender, 2,
-- 				UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
-- 				SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
-- 				Level, Experience, 0, 0, BodyCondition, Propensity, Status,
-- 				PKWinPoint, PKLossPoint, Material, HP, DP,
-- 				SP, EP, PetName, PetLevel, PetExperience,
-- 				Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
-- 				MaxLevel, currentHP, currentDP, currentSP, currentEP,
-- 				200, 200, 0, 0, 0, GetDate(), NULL,GetDate()
-- 		FROM atum2_db_account.dbo.td_account a, td_Character c
-- 		WHERE c.charactername = '���ݸ���' AND a.AccountName = @CharacterName
-- 		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 		-- WHERE c.charactername LIKE '���ݸ���' AND a.AccountName LIKE @CharacterName
-- 
-- 	-- �⺻ ������ ����
-- 	DECLARE @uniquenumber INT
-- 	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername = @CharacterName)
-- 	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 	-- SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername LIKE @CharacterName)
-- 	IF (@uniquenumber IS NOT NULL)
-- 	BEGIN
-- 		-- ���� ����
-- 		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 07000070, 1, 1, 2
-- 		-- ���� ����
-- 		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
-- 		-- �� ����
-- 		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0
-- 
-- 	END
-- GO


--------------------------------------------------------------------------------
-- �Ϲ� procedures
--------------------------------------------------------------------------------
-- !!!!
-- Name:
-- Desc:
-- 		2005-06-30 5:19 by cmkwon, �� �⺻ ���� ������ ������
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
--		2006-09-14 by cmkwon, Demo ���� �⺻ ���� ������ ������
--			-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - ResultSet ==> Number of Characters
-- ====
CREATE PROCEDURE dbo.atum_CreateCharacter
	@i_CharacterName				VARCHAR(20),		-- // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - "i_"�� �߰���.
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
	@lastPartyID	BIGINT
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� -  
	--@nNumCharacter	INT OUTPUT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- AccountType ������ ����
	DECLARE @AccoutTypeAppliedRace INT
	SET @AccoutTypeAppliedRace = @Race | (SELECT AccountType FROM atum2_db_account.dbo.td_account
								WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber)

-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - �Ʒ��� ���� �ʿ� �ʵ带 ����ϴ� ������ ������.
--	INSERT INTO td_Character
--	VALUES (@i_CharacterName, @AccountName, @AccountUniqueNumber, @Gender, @AccoutTypeAppliedRace,
--		@UnitKind, @InfluenceType, @SelectableInfluenceMask, @PilotFace, @CharacterMode, @AutoStatType, @AttackPart, @DefensePart, @FuelPart,
--		@SoulPart, @ShieldPart, @DodgePart, @GuildName, @GuildUniqueNumber,
--		@Level, @Experience, 0, 0, @BodyCondition, @Propensity, @Status,
--		@PKWinPoint, @PKLossPoint, @Material, @HP, @DP,
--		@SP, @EP, @PetName, @PetLevel, @PetExperience,
--		@Position_X, @Position_Y, @Position_Z, @MapIndex, @ChannelIndex,
--		@MaxLevel, @currentHP, @currentDP, @currentSP, @currentEP,
--		@bonusStat, @bonusSkillPoint, @lastPartyID, 0, 0, GetDate(), NULL,GetDate(), 0, 0, 0, 0, 0, 0, 0	-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
--	)
	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
	VALUES (@i_CharacterName, @AccountName, @AccountUniqueNumber, @Gender, @AccoutTypeAppliedRace,
		@UnitKind, @InfluenceType, @SelectableInfluenceMask, @PilotFace, @CharacterMode, @AutoStatType, @AttackPart, @DefensePart, @FuelPart,
		@SoulPart, @ShieldPart, @DodgePart, @GuildName, @GuildUniqueNumber,
		@Level, @Experience, 0, 0, @BodyCondition, @Propensity, @Status,
		@PKWinPoint, @PKLossPoint, @Material, @HP, @DP,
		@SP, @EP, @PetName, @PetLevel, @PetExperience,
		@Position_X, @Position_Y, @Position_Z, @MapIndex, @ChannelIndex,
		@MaxLevel, @currentHP, @currentDP, @currentSP, @currentEP,
		@bonusStat, @bonusSkillPoint, @lastPartyID, 0, 0, GetDate(), NULL,GetDate())

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	---- 2007-07-25 by cmkwon, ������ ĳ���ʹ� ����
	----		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	--SET @nNumCharacter = (SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000)

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
	-- // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - LIKE ������� �ʰ� ����
	-- SET @uniquenumber = (SELECT uniquenumber FROM td_Character WITH (NOLOCK) WHERE charactername LIKE @CharacterNameForSearch)
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WITH (NOLOCK) WHERE charactername = @i_CharacterName)
	IF (@uniquenumber IS NULL)
	BEGIN
		SELECT 0;
		RETURN;
	END

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
			-- // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - �Ʒ��� ���� i_CharacterName�� ����ϰ� ����
			-- EXEC dbo.atum_admin_SetMoney @CharacterNameForSearch, 5000000
			EXEC dbo.atum_admin_SetMoney @i_CharacterName, 5000000
		END

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	---- 2007-07-25 by cmkwon, ������ ĳ���ʹ� ����
	----		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000;
GO



-- !!!!
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
--		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - ResultSet ==> Number of Characters
-- ====
CREATE PROCEDURE dbo.atum_DeleteCharacter
	@CharUniqueNum		INT
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--@nNumCharacter		INT OUTPUT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccountUniqueNumber INT
	SET @AccountUniqueNumber = (SELECT DISTINCT AccountUniqueNumber FROM td_Character WITH (NOLOCK) WHERE UniqueNumber = @CharUniqueNum)
	
	DECLARE @CharName VARCHAR(20)
	SET @CharName = (SELECT CharacterName FROM td_Character WITH (NOLOCK) WHERE UniqueNumber = @CharUniqueNum)
	
	IF (@AccountUniqueNumber IS NULL) OR (@CharName IS NULL)
	BEGIN
		SELECT -1;		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - error �� �����Ѵ�.
		RETURN;
	END

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

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - �Ʒ��� ���� ResultSet ���� �ѱ��.
	--SET @nNumCharacter = (SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000)
	SELECT count(*) FROM td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUniqueNumber AND 0 = Race & 0x4000;
GO



-- !!!!
-- Name:
-- Desc:
-- ====
-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - �Ʒ��� ���� ������.
-- CREATE PROCEDURE dbo.atum_GetAllCharacterInfoByID
-- 	@ID	VARCHAR(64)
-- AS
-- 	SELECT *
-- 	FROM td_Character
-- 	WITH (NOLOCK)
-- 	WHERE td_Character.AccountName LIKE @ID AND 0 = Race & 0x4000	-- Race >= 16384 ������ �ɸ���
-- GO
CREATE PROCEDURE dbo.atum_GetAllCharacterInfoByID
	@i_AccUID		INT		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - AccountUID �� �˻����� ����
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE AccountUniqueNumber = @i_AccUID AND 0 = Race & 0x4000	-- Race >= 16384 ������ �ɸ���
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetCharacter
	@acc	INT,
	@charac	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_Character c, td_Guild g, td_GuildMember gm WITH(NOLOCK) WHERE c.UniqueNumber = @charac AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_Character c	WITH (NOLOCK)
		WHERE c.UniqueNumber = @charac
	END
	ELSE
	BEGIN
		UPDATE td_Character
		SET GuildName = g.GuildName
		FROM td_Character c, td_Guild g	WITH (NOLOCK)
		WHERE c.UniqueNumber = @charac AND c.GuildUniqueNumber = g.GuildUniqueNumber
	END

	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE UniqueNumber=@charac
	-- // 2007-07-30 by cmkwon, ���� ���� CharacterUID�θ� �˻�
	--WHERE UniqueNumber=@charac AND AccountUniqueNumber = @acc
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetAccountUniqueNumber
	@name varchar(20)	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ������.
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountUniqueNumber
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername = @name
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE charactername LIKE @name
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetCharacterNumByName
	@name varchar(20)		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ������.
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername = @name
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE charactername LIKE @name
GO

-- !!!!
-- Name:
-- Desc:
--		// 2007-07-31 by cmkwon, ���� ����( <== @acc varchar(64), @charname varchar(64) ) - ������ like ����� ���� �ʴ°����� ����
-- ====
CREATE PROCEDURE dbo.atum_GetChatCharacterInfoByName
	@acc		varchar(20),
	@charname	varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_Character c, td_Guild g, td_GuildMember gm WITH(NOLOCK) WHERE c.charactername = @charname AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_Character c	WITH (NOLOCK)
		WHERE c.charactername = @charname
	END
	ELSE
	BEGIN
		UPDATE td_Character
		SET GuildName = g.GuildName
		FROM td_Character c, td_Guild g	WITH (NOLOCK)
		WHERE c.charactername = @charname AND c.GuildUniqueNumber = g.GuildUniqueNumber
	END

	SELECT *
	FROM td_Character
	WITH (NOLOCK)
	WHERE charactername = @charname AND accountname = @acc
GO

-- !!!!
-- Name:
-- Desc:// 2007-07-31 by cmkwon, �߰���
-- ====
CREATE PROCEDURE dbo.atum_admin_GetCharacterByCharacterName
	@i_CharName	VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2007-07-30 by cmkwon, SCAdminTool���� ���ܸ� ���� ��� �߰� - ĳ���� ������ �����ö� td_Guild ���̺��� �����Ͽ� ������Ʈ�� ���Ŀ� �����´�
	IF NOT EXISTS(SELECT c.UniqueNumber FROM td_Character c, td_Guild g, td_GuildMember gm WITH(NOLOCK) WHERE c.charactername = @i_CharName AND c.GuildUniqueNumber = g.GuildUniqueNumber AND gm.GuildUniqueNumber = c.GuildUniqueNumber AND gm.CharacterUniqueNumber = c.UniqueNumber)
	BEGIN
		UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		FROM td_Character c	WITH (NOLOCK)
		WHERE c.charactername = @i_CharName
	END
	ELSE
	BEGIN
		UPDATE td_Character
		SET GuildName = g.GuildName
		FROM td_Character c, td_Guild g	WITH (NOLOCK)
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

-- !!!!
-- Name:
-- Desc:
--		2006-04-10 by cmkwon, �Ķ���� �߰�(@i_DownSPIOnDeath	INT,			-- 2006-04-10 by cmkwon)
--		2006-11-15 by cmkwon, ���� 2�� �߰�
--						@i_GameContinueTimeInSecondOfToday	INT,			-- 2006-11-15 by cmkwon, ���� �Ϸ� ���� ���� �ð�
--						@i_LastGameEndDate					VARCHAR(30)		-- 2006-11-15 by cmkwon, ������ ���� ���� ��¥�ð�
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
	-- atum2_db_account.dbo.td_account ���̺� �������ӽð�, ������ ���� ����ð��� ������Ʈ �Ѵ�.
	UPDATE atum2_db_account.dbo.td_account
		SET GameContinueTimeInSecondOfToday = @i_GameContinueTimeInSecondOfToday,
			LastGameEndDate = @i_LastGameEndDate
		FROM atum2_db_account.dbo.td_account a, td_Character c
		WHERE c.UniqueNumber = @i_CharacterUID AND a.AccountUniqueNumber = c.AccountUniqueNumber

GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeUnitKind
	@UniqueNumber	int,
	@UnitKind		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET UnitKind = @UnitKind
		WHERE  UniqueNumber = @UniqueNumber;
GO


-- !!!!
-- Name:
-- Desc:
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET AutoStatType = @byAutoStatType, AttackPart = @AttackPart, DefensePart = @DefensePart, FuelPart = @FuelPart,
			SoulPart = @SoulPart, ShieldPart = @ShieldPart, DodgePart = @DodgePart,
			HP = @hp, DP = @dp, EP = @ep, SP = @sp, BonusStat = @bstat
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc: 2005-11-15 by cmkwon, Level Up �̿��� ������� �߰��� ���ʽ� ���� ��ġ ���� ��
-- ====
CREATE PROCEDURE dbo.atum_ChangeBonusStatPoint
	@UniqueNumber		INT,
	@BonusStatPoint		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET BonusStatPoint = @BonusStatPoint
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
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


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeExp
	@UniqueNumber	INT,
	@exp			FLOAT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Experience = @exp
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeLevel
	@UniqueNumber	INT,
	@level			TINYINT,
	@bstat			TINYINT
-- 2005-11-15 by cmkwon, BonusSkillPoint�� BonusStatPoint�� �����ϸ鼭 �ʿ������
--	@bskillpoint	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Level = @level, BonusStat = @bstat, LevelUpTime = GetDate()
		WHERE  UniqueNumber = @UniqueNumber;
-- 2005-11-15 by cmkwon, BonusSkillPoint�� BonusStatPoint�� �����ϸ鼭 �ʿ������
--		SET Level = @level, BonusStat = @bstat, BonusSkillPoint = @bskillpoint
--		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeBodyCondition
	@UniqueNumber	int,
	@bc				BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET BodyCondition = @bc
		WHERE  UniqueNumber = @UniqueNumber;
GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangePropensity
	@UniqueNumber	INT,
	@Prop			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Propensity = @Prop
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:���¼��ý� ������ ����ȴ�.
--		2005-12-07 by cmkwon, ��� ĳ������ SelectableInfluenceMask�� ������Ʈ �Ѵ�.
-- ====
CREATE PROCEDURE dbo.atum_ChangeInfluenceType
	@AccountUID					int,
	@CharacterUID				int,
	@InfluenceType				TINYINT,
	@SelectableInfluenceMask	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET InfluenceType = @InfluenceType
		WHERE  UniqueNumber = @CharacterUID;
	
	UPDATE td_Character
		SET SelectableInfluenceMask = @SelectableInfluenceMask
		WHERE AccountUniqueNumber = @AccountUID
GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeStatus
	@UniqueNumber	INT,
	@status			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Status = @status
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangePKPoint
	@UniqueNumber	INT,
	@Propensity		INT,
	@PKWinPoint		SMALLINT,
	@PKLossPoint	SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Propensity = @Propensity, PKWinPoint = @PKWinPoint, PKLossPoint = @PKLossPoint
		WHERE  UniqueNumber = @UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_ChangeRacingPoint
-- DESC				: // 2009-11-02 by cmkwon, ĳ��(�κ�/â�� Ȯ��) ������ �߰� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ChangeRacingPoint
	@i_CharacterUID		INT,
	@i_RacingPoint		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET RacingPoint = @i_RacingPoint
		WHERE  UniqueNumber = @i_CharacterUID;
GO

-- !!!!
-- Name: atum_ChangeHPDPSPEP
-- Desc: 
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET HP = @i_HP, DP = @i_DP, SP = @i_SP, EP = @i_EP,
			CurrentHP = @i_CurrentHP, CurrentDP = @i_CurrentDP, CurrentSP = @i_CurrentSP, CurrentEP = @i_CurrentEP
		WHERE  UniqueNumber = @i_CharacterUID;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeMapChannel
	@UniqueNumber	INT,
	@MapIndex		SMALLINT,
	@ChannelIndex	SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET MapIndex = @MapIndex, ChannelIndex = @ChannelIndex
		WHERE  UniqueNumber = @UniqueNumber;
GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangePetInfo
	@UniqueNumber	int,
	@level			TINYINT,
	@exp			FLOAT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET level = @level, experience=@exp
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangePosition
	@UniqueNumber	INT,
	@x			FLOAT,
	@y			FLOAT,
	@z			FLOAT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET Position_X=@x, Position_Y=@y, Position_Z=@z
		WHERE  UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_SaveLastPartyID
	@CharacterUniqueNumber	INT,
	@PartyID				BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET LastPartyID = @PartyID
		WHERE  UniqueNumber = @CharacterUniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateTotalPlayTime
	@i_CharacterUniqueNumber	INT,
	@i_TotalPlayTime			BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET TotalPlayTime = @i_TotalPlayTime
		WHERE  UniqueNumber = @i_CharacterUniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateLastStartedTime
	@CharacterUniqueNumber	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_AuthChatLogin
	@acc			varchar(20),	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ����
	@pass			varchar(35)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountName
	FROM atum2_db_account.dbo.td_account
	WITH (NOLOCK)
	WHERE AccountName = @acc AND IsBlocked = 0 --AND Password LIKE @pass 
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE AccountName LIKE @acc AND IsBlocked = 0 --AND Password LIKE @pass 
GO

--------------------------------------------------------------
-- ITEM ����
--------------------------------------------------------------

-- !!!!
-- Name:
-- Desc:
--		2005-12-07 by cmkwon, ������ġ
-- ====
CREATE PROCEDURE dbo.atum_GetStoreItem
	@accNum			INT,
	@possessNum		INT,
	@ItemStorage	TINYINT				-- 2005-12-07 by cmkwon,
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber,AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,
		NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,
		ShapeItemNum,MainSvrItemUID,CoolingTime
	FROM td_Store
	WHERE AccountUniqueNumber = @accNum AND Possess = @possessNum AND ItemStorage = @ItemStorage
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_DeleteStoreItem
	@accNum	INT,
	@uniqueNum BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_Enchant
		WHERE TargetItemUniqueNumber = @uniqueNum

	DELETE FROM td_Store
		WHERE AccountUniqueNumber = @accNum AND UniqueNumber = @uniqueNum;
	DELETE FROM td_pet
		WHERE ItemUID = @uniqueNum; -- // 2010-06-15 by shcho&hslee ��ý��� - �� ���� ���� �߰�
GO


-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
-- !!!!
-- Name:
-- Desc:
-- ====
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
--		FROM atum2_db_account.dbo.ti_Item i
--		WHERE i.ItemNum = @ItemNum
--	RETURN SCOPE_IDENTITY();
--GO


-- !!!!
-- Name: dbo.atum_InsertStoreItem
-- Desc:
--		2005-12-07 by cmkwon, ������ġ �ʵ� �߰�
--		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- ====
CREATE PROCEDURE dbo.atum_InsertStoreItem
	@accNum				INT,
	@possess			INT,
	@ItemStorage		TINYINT,			-- 2005-12-07 by cmkwon
	@wear				TINYINT,
	@CurrentCount		INT,
-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
--	@ScarcityNumber		BIGINT,
	@ItemWindowIndex	INT,
	@ItemNum			INT,
	@NumOfEnchants		SMALLINT,
	@PrefixCodeNum		INT,
	@SufficCodeNum		INT,
	@CurrentEndurance	FLOAT,
	@ColorCode			INT,			-- 2005-11-21 by cmkwon, �Ƹ� Ʃ�׽� Į��
	@UsingTimeStamp		INT,
	@i_ShapeItemNum		INT				-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - �Ʒ��� ���� ����
	-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
	-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
	-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, GetDate(), @i_ShapeItemNum, 0, 0)

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END

	SELECT SCOPE_IDENTITY();
GO


-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν�����
-- !!!!
-- Name:
-- Desc:
-- ====
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


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_MoveItemPossess
	@accNum					INT,
	@ToPossessCharacter		INT,	-- CharacterUniqueNumber OR 0
	@ItemUniqueNumber		BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET Possess = @ToPossessCharacter
	WHERE UniqueNumber = @ItemUniqueNumber
GO

-- 2005-12-07 by cmkwon, �ʿ����
---- !!!!
---- Name:
---- Desc:
-- ====
--CREATE PROCEDURE dbo.atum_UpdateItemPossess
--	@i_ItemUniqueNumber		BIGINT,
--	@i_ToPossess			INT		-- CharacterUniqueNumber OR 0
--AS
--	UPDATE td_Store
--	SET Possess = @i_ToPossess
--	WHERE UniqueNumber = @i_ItemUniqueNumber
--GO

-- !!!!
-- Name:
-- Desc:	2005-12-07 by cmkwon, �������� ���� ��ġ ����(ĳ�����κ�->â��, â��->ĳ�����κ�)
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemStorage
	@i_ItemUniqueNumber		BIGINT,
	@i_ItemCharacterUID     INT,		-- 2006-09-19 by dhjin, ���õ� �ɸ���
	@i_ItemStorage			TINYINT		-- 0(ITEM_IN_CHARACTER):ĳ�����κ�, 1(ITEM_IN_STORE):â��
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
		SET ItemStorage = @i_ItemStorage, Possess = @i_ItemCharacterUID
		WHERE UniqueNumber = @i_ItemUniqueNumber
GO

-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
---- !!!!
---- Name:
---- Desc:
-- ====
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
--	FROM td_Enchant e, td_Store i 
--	WHERE i.AccountUniqueNumber = @i_AccountUID AND i.possess = @i_CharacterUID
--			AND e.TargetItemUniqueNumber = i.UniqueNumber AND UniqueNumber = @i_ItemUID
--GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemCount
	@UniqueNumber	BIGINT,
	@CurrentCount	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET CurrentCount = @CurrentCount
	WHERE UniqueNumber = @UniqueNumber
GO


-- !!!!
-- Name:
-- Desc:2006-06-14 by cmkwon, �߰���
--			�ٸ����� �������� �ʰ� ItemNum�� �����Ѵ�. ����,��æƮ�� �����ȴ�.
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemNum
	@UniqueNumber	BIGINT,
	@ItemNum		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
		SET ItemNum = @ItemNum
		WHERE UniqueNumber = @UniqueNumber
GO


-- 2005-11-21 by cmkwon, ������
---- !!!!
---- Name:
---- Desc:
---- ====
--CREATE PROCEDURE dbo.atum_UpdateEndurance
--	@UniqueNumber	BIGINT,
--	@CurrentEndurance		FLOAT
--AS
--	UPDATE td_Store
--	SET CurrentEndurance = @CurrentEndurance
--	WHERE UniqueNumber = @UniqueNumber
--GO

-- !!!!
-- Name:
-- Desc:2005-11-21 by cmkwon
--		�Ƹ� �������� Į�� �ؽ��� �ڵ� ������Ʈ
-- ====
CREATE PROCEDURE dbo.atum_StoreUpdateColorCode
	@UniqueNumber	BIGINT,
	@ColorCode		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET ColorCode = @ColorCode
	WHERE UniqueNumber = @UniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemUsingTimeStamp
	@UniqueNumber		BIGINT,
	@UsingTimeStamp		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET UsingTimeStamp = @UsingTimeStamp
	WHERE UniqueNumber = @UniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemRareFix
	@i_ItemUID			BIGINT,
	@i_PrefixCodeNum	INT,
	@i_SuffixCodeNum	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET PrefixCodeNum = @i_PrefixCodeNum, SuffixCodeNum = @i_SuffixCodeNum
	WHERE UniqueNumber = @i_ItemUID
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateItemWindowList
	@UniqueNumber	BIGINT,
	@Wear			TINYINT,
	@WndIdx			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET ItemWindowIndex = @WndIdx, Wear = @Wear
	WHERE UniqueNumber = @UniqueNumber;
GO

-- !!!!
-- Name: dbo.atum_GetAttachedItems
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
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - ShapeItemNum �ʵ� �߰�, ��� �ʵ� 1�� �߰�
-- ====
CREATE PROCEDURE dbo.atum_GetAttachedItems
	@Possess		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemWindowIndex ����
--	SELECT ItemWindowIndex, ItemNum, ColorCode
-- 	FROM td_Store
-- 	WITH (NOLOCK)
-- 	WHERE ItemStorage = 0 AND possess = @Possess AND itemwindowindex >= 0 AND itemwindowindex <= 9
	SELECT ItemWindowIndex, ItemNum, ColorCode, ShapeItemNum
	FROM td_Store WITH (NOLOCK)
	WHERE ItemStorage = 0 AND possess = @Possess AND ItemWindowIndex >= 0 AND ItemWindowIndex <= 9
GO

--------------------------------------------------------------
-- td_Enchant ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc:
-- ====
-- 	// 2013-01-15 by bckim, ��æƮ������ �������ѹ� �߰�
CREATE PROCEDURE [dbo].[atum_InsertEnchant]
	@i_TargetItemUniqueNumber	BIGINT,
	@i_TargetItemNum			INT,
	@i_EnchantItemNum			INT
--WITH EXECUTE AS 'proexe'
AS
	INSERT INTO td_Enchant
	VALUES (@i_TargetItemUniqueNumber, @i_TargetItemNum, @i_EnchantItemNum)
	SELECT SCOPE_IDENTITY();	
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_DeleteAllEnchant
	@i_TargetItemUniqueNumber	BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_Enchant
		WHERE TargetItemUniqueNumber = @i_TargetItemUniqueNumber
GO


-- 2007-01-30 by cmkwon, �ʿ� ��� �ּ� ó���� - atum_GetEnchantBYItemUID() ���ν����� ��ü��
---- !!!!
---- Name:
---- Desc:
---- ====
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
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetAllQuest
	@CharacterUniqueNumber	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM td_CharacterQuest
	WITH (NOLOCK)
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
--			// 2007-11-16 by cmkwon, ���̺� Unique Key ������ �� ������ �߰��� üũ �Ŀ� �߰� - td_CharacterQuest
CREATE PROCEDURE dbo.atum_InsertQuest
	@i_CharacterUniqueNumber	INT,
	@i_QuestIndex				INT,
	@i_QuestState				TINYINT,
	@i_QuestParam1				INT,
	@i_QuestTimeStamp			VARCHAR(50),
	@i_QuestPlayTimeStamp		BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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

-- !!!!
-- Name:
-- Desc:
--		2006-08-31 by cmkwon, @i_QuestPlayTimeStamp		BIGINT
-- ====
CREATE PROCEDURE dbo.atum_UpdateQuestState
	@CharacterUniqueNumber	INT,
	@QuestIndex				INT,
	@QuestState				TINYINT,
	@i_QuestPlayTimeStamp		BIGINT		-- 2006-08-31 by cmkwon, �߰���
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_CharacterQuest
	SET QuestState = @QuestState, QuestPlayTimeStamp = @i_QuestPlayTimeStamp
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_DeleteQuest
	@CharacterUniqueNumber	INT,
	@QuestIndex				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_CharacterQuest
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO

-----------------------------------------------------------------------------
-- 2005-10-19 by cmkwon, ����Ʈ ���� ī���� ����

-- !!!!
-- Name:
-- Desc:ĳ������ ��� ���� ī��Ʈ�� �˻��Ѵ�.
-- ====
CREATE PROCEDURE dbo.atum_GetAllQuestMonsterCount
	@CharacterUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM td_CharacterQuestMonsterCount
	WITH (NOLOCK)
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber
GO

-- !!!!
-- Name:
-- Desc:����Ʈ ���� ī��Ʈ�� �߰� Ȥ�� ����
-- ====
CREATE PROCEDURE dbo.atum_UpdateQuestMonsterCount
	@CharacterUniqueNumber		INT,
	@QuestIndex					INT,
	@MonsterUniqueNumber		INT,
	@Count						INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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

-- !!!!
-- Name:
-- Desc:����Ʈ ���� ī��Ʈ ����
-- ====
CREATE PROCEDURE dbo.atum_DeleteQuestMonsterCount
	@CharacterUniqueNumber		INT,
	@QuestIndex					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_CharacterQuestMonsterCount
	WHERE CharacterUniqueNumber = @CharacterUniqueNumber AND QuestIndex = @QuestIndex
GO


-- End_����Ʈ ���� ī���� ����
-----------------------------------------------------------------------------


--------------------------------------------------------------
-- SKILL ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetStoreItemSkill
	@accNum	INT,
	@possessNum INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime
	FROM td_StoreSkill
	WITH (NOLOCK)
	WHERE AccountUniqueNumber = @accNum AND Possess = @possessNum
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_DeleteStoreItemSkill
	@accNum	INT,
	@uniqueNum BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND UniqueNumber = @uniqueNum;
GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_InsertStoreItemSkill
	@accNum			INT,
	@possess		INT,
	@ItemWindowIndex	INT,
	@ItemNum		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND Possess = @possess AND (ItemNum/10)*10 = (@ItemNum/10)*10

	INSERT INTO td_StoreSkill
	VALUES (@accNum, @possess, @ItemWindowIndex, @ItemNum, GetDate(), NULL)

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END
	
	SELECT SCOPE_IDENTITY();
GO

-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - ������� �ʴ� ���ν���
---- !!!!
---- Name:
---- Desc:
----			2007-01-19, #define ITEM_IN_CHARACTER				0	// ĳ�����κ�
----						#define ITEM_IN_STORE					1	// â��
----						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
---- ====
--CREATE PROCEDURE dbo.atum_DeleteAllCharacterItems
--	@i_AccountUID INT,
--	@i_CharacterUID INT
--AS
--	IF (@i_CharacterUID = 0)
--		RETURN
--
--	-- 1. ĳ���� ���� �������� ��æƮ ����	
--	DELETE td_Enchant FROM td_Enchant e, td_Store s 
--		WHERE s.AccountUniqueNumber = @i_AccountUID AND s.ItemStorage <> 2 AND s.Possess = @i_CharacterUID AND s.UniqueNumber = e.TargetItemUniqueNumber
--	
--	-- 2. ĳ���� ���� ������ ����
--	DELETE FROM td_Store WHERE AccountUniqueNumber = @i_AccountUID AND ItemStorage <> 2 AND possess = @i_CharacterUID
--	
--	-- 3. ĳ���� �� ���� ����
--	DELETE FROM td_QuickSlot WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
--	
--	-- 4. ĳ���� ���� ��ų ����
--	DELETE FROM td_StoreSkill WHERE AccountUniqueNumber = @i_AccountUID AND possess = @i_CharacterUID
--GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeCurrentHPDPSPEP
	@UniqueNumber		INT,
	@hp					FLOAT,
	@dp					FLOAT,
	@sp					SMALLINT,
	@ep					FLOAT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
		SET CurrentHP = @hp, CurrentDP = @dp, CurrentSP=@sp, CurrentEP=@ep
		WHERE  UniqueNumber = @UniqueNumber;
GO


-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_ChangeWindowPosition
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_ItemUID1				BIGINT,
	@i_ItemWindowIndex1		INT,
	@i_ItemWear1			TINYINT,
	@i_ItemUID2				BIGINT,
	@i_ItemWindowIndex2		INT,
	@i_ItemWear2			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET		ItemWindowIndex = @i_ItemWindowIndex1, Wear = @i_ItemWear1
	WHERE	UniqueNumber = @i_ItemUID1 AND Possess = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
	
	UPDATE td_Store
	SET		ItemWindowIndex = @i_ItemWindowIndex2, Wear = @i_ItemWear2
	WHERE	UniqueNumber = @i_ItemUID2 AND Possess = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_GetBuildingNPC
	@MapIndex	SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM atum2_db_account.dbo.ti_BuildingNPC WITH (NOLOCK)	
	WHERE MapIndex = @MapIndex OR MapIndex = 0
GO

-- 2006-10-20 by cmkwon, ������� �ʴ� ���ν���, �Ʒ��� �ΰ��� ���ν��� �ΰ��� ����� ����
---- !!!!
---- Name:
---- Desc:
---- ====
--CREATE PROCEDURE dbo.atum_GetAllShopItems
--	@MapIndex SMALLINT
--AS
--	SELECT b.BuildingIndex, i.itemnum, itemname, i.MinTradeQuantity, i.price, kind
--	FROM atum2_db_account.dbo.ti_Item i, atum2_db_account.dbo.ti_Shop s, ti_BuildingNPC b
--	WHERE i.itemnum = s.itemnum AND b.BuildingIndex = s.uniquenumber AND (b.MapIndex = @MapIndex OR b.MapIndex = 0)
--	order by b.BuildingIndex
--GO

-- !!!!
-- Name:
-- Desc:2006-10-20 by cmkwon, ���� ��� BuildingIndex�� ��������
-- ====
CREATE PROCEDURE dbo.atum_GetAllBuildingIndex
	@MapIndex SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT BuildingIndex
		FROM atum2_db_account.dbo.ti_BuildingNPC WITH (NOLOCK)
		WHERE MapIndex = @MapIndex OR MapIndex = 0
GO

-- !!!!
-- Name:
-- Desc:2006-10-20 by cmkwon, BuildingIndex�� ������ ��������
--		// 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder ������ ���� ������ ����Ʈ�� �����´�.
--		// 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - 
--		// 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - �����Ǹ� ���� ������ ����� �߰�
--		// 2013-02-05 by bckim, ĳ�ü� ��õ�� ���ļ����ο�
-- ====
CREATE PROCEDURE dbo.atum_GetShopItems
	@BuildingIndex INT
--WITH EXECUTE AS 'proexe'
AS
-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
--	-- // 2008-01-22 by cmkwon, S_DB: ti_Shop.ShopOrder ������ ���� ������ ����Ʈ�� �����´�.
-- 	SELECT i.itemnum, i.itemname, i.MinTradeQuantity, i.price, i.kind
-- 		FROM atum2_db_account.dbo.ti_Item i WITH(NOLOCK), atum2_db_account.dbo.ti_Shop s WITH(NOLOCK)
-- 		WHERE i.itemnum = s.itemnum AND @buildingIndex = s.uniquenumber
-- 		ORDER BY s.ShopOrder

	-- // 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - SummonMonster,CashShopBit �� �˻�
	-- // 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - cs.RemainCountForLimitedEdition
	-------------------------------------------------------------------------------
	IF( @BuildingIndex = 9999 )
	BEGIN
		SELECT i.ItemNum, i.ItemName, i.MinTradeQuantity, i.Price, i.Kind, i.SummonMonster, cs.CashShopBit, cs.RemainCountForLimitedEdition
		FROM atum2_db_account.dbo.ti_Item i WITH(NOLOCK) 
		INNER JOIN atum2_db_account.dbo.ti_Shop s WITH(NOLOCK) ON i.ItemNum = s.ItemNum 
		LEFT OUTER JOIN atum2_db_account.dbo.td_CashShop cs WITH(NOLOCK) ON s.ItemNum = cs.ItemNum
		LEFT OUTER JOIN atum2_db_account.dbo.td_CashShop_Realignment_Index cr WITH(NOLOCK) ON cs.ItemNum = cr.ItemNum
		WHERE @BuildingIndex = s.Uniquenumber ORDER BY cr.RealignmentIndex, s.ShopOrder 
	END

	ELSE
	BEGIN
		SELECT i.ItemNum, i.ItemName, i.MinTradeQuantity, i.Price, i.Kind, i.SummonMonster, cs.CashShopBit, cs.RemainCountForLimitedEdition
		FROM atum2_db_account.dbo.ti_Item i WITH(NOLOCK) 
		INNER JOIN atum2_db_account.dbo.ti_Shop s WITH(NOLOCK) ON i.ItemNum = s.ItemNum 
		LEFT OUTER JOIN atum2_db_account.dbo.td_CashShop cs WITH(NOLOCK) ON s.ItemNum = cs.ItemNum
		WHERE @BuildingIndex = s.Uniquenumber
		ORDER BY s.ShopOrder
	END
GO


-- 2005-11-21 by cmkwon, ������� �ʴ� ���ν���
-- !!!!
-- Name:
-- Desc:
-- ====
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
--		FROM atum2_db_account.dbo.ti_Item i
--		WHERE i.ItemNum = @ItemNum
--
--	RETURN SCOPE_IDENTITY();
--GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_InsertStoreItemSkill_DB_AND_UpdateCount
	@accNum	INT,
	@possess INT,
	@ItemWindowIndex	INT,
	@ItemNum INT,
	@ItemUniqueNumber	BIGINT,	-- Money
	@ItemCount	INT				-- Money
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET CurrentCount = @ItemCount
	WHERE UniqueNumber = @ItemUniqueNumber

	DELETE FROM td_StoreSkill
	WHERE AccountUniqueNumber = @accNum AND Possess = @possess AND (ItemNum/10)*10 = (@ItemNum/10)*10

	INSERT INTO td_StoreSkill
		SELECT @accNum, @possess, @ItemWindowIndex, @ItemNum, GetDate(), NULL
		FROM atum2_db_account.dbo.ti_Item i WITH (NOLOCK)
		WHERE i.ItemNum = @ItemNum

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	SELECT SCOPE_IDENTITY();
GO

-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_UpdateStoreItemCount_AND_UpdateMoney
	@ItemUniqueNumber		BIGINT,
	@ItemCount				INT,
	@MoneyItemUniqueNumber	BIGINT,
	@MoneyItemCount			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET CurrentCount = @MoneyItemCount
	WHERE UniqueNumber = @MoneyItemUniqueNumber;

	UPDATE td_Store
	SET CurrentCount = @ItemCount
	WHERE UniqueNumber = @ItemUniqueNumber;
GO



-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_DeleteStoreItem_AND_UpdateMoney
	@ItemUniqueNumber		BIGINT,
	@MoneyItemUniqueNumber	BIGINT,
	@MoneyItemCount			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- !!!!
-- Name:
-- Desc:
-- ====
CREATE PROCEDURE dbo.atum_TradeMoveItem
	@ToCharacter			INT,
	@ToAccount				INT,
	@FromCharacter			INT,
	@ItemUniqueNumber		BIGINT			-- 2006-05-11 by cmkwon, INT�� ������
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
		SET AccountUniqueNumber = @ToAccount, Possess = @ToCharacter, Wear = 0, ItemWindowIndex = 99
		WHERE UniqueNumber = @ItemUniqueNumber AND Possess = @FromCharacter
GO

-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - ������� �ʴ� ���ν���
---- !!!!
---- Name:
---- Desc:������ �ŷ��� ī���ͺ� ������ ó��
----		2005-11-21 by cmkwon, ColorCode�� �Ƹӿ��� ���ǹǷ� �ŷ��� 0���� �����Ѵ�.
---- ====
--CREATE PROCEDURE dbo.atum_TradeMoveItemCountable
--	@ToCharacter			INT,
--	@ToAccount				INT,
--	@FromCharacter			INT,
--	@FromItemUniqueNumber	BIGINT,
--	@Amount					INT,		-- �ŷ���
--	@RemainedCount			INT,		-- �ִ� �������� ���� ��
--	@ToItemUniqueNumber		BIGINT OUTPUT,		-- 0: �޴� ���� ���� �������� ����, else: �޴� �ʿ� �������� ������(�޴� ������ ������ȣ)
--	@FromItemNum			INT			-- spi���� �ƴ��� Ȯ���ؼ�, spi�̸� ���� ���� 0�̴��� ������ �ʴ´�!
--AS
--
--	-- �������� �޴� �� ó��
--	IF (@ToItemUniqueNumber = 0)
--	BEGIN
--		-- ���� ĳ���Ͱ� �ش� �������� �������� ���� ���
--		INSERT INTO td_Store
--			SELECT @ToAccount, @ToCharacter, 0, 0, @Amount, s.ScarcityNumber, 100,
--						s.ItemNum, 0, s.PrefixCodeNum, s.SuffixCodeNum, s.CurrentEndurance, 0, 0, GetDate()
--			FROM td_Store s
--			WHERE s.UniqueNumber = @FromItemUniqueNumber AND s.Possess = @FromCharacter
--
--		SET @ToItemUniqueNumber = SCOPE_IDENTITY()
--	END
--	ELSE
--	BEGIN
--		-- ���� ĳ���Ͱ� �ش� �������� �̹� ������ ���
--		UPDATE td_Store
--			SET CurrentCount = CurrentCount + @Amount
--			WHERE UniqueNumber = @ToItemUniqueNumber AND Possess = @ToCharacter
--	END
--
--	-- �������� �ִ� �� ó��
--	IF (@RemainedCount > 0 OR @FromItemNum = 7000022)
--	BEGIN -- �ܵ� statement�� �ƴ� �� ���, ���⼭�� ���� ������ ���� �̸� �����
--		UPDATE td_Store
--		SET CurrentCount = @RemainedCount
--		WHERE UniqueNumber = @FromItemUniqueNumber AND Possess = @FromCharacter
--	END
--	ELSE
--	BEGIN
--		DELETE td_Store
--		WHERE  UniqueNumber = @FromItemUniqueNumber AND Possess = @FromCharacter
--	END
--
--GO


--------------------------------------------------------------------------------
-- GUILD
--------------------------------------------------------------------------------
-- !!!!
-- Name:
-- Desc:
-- ====	2005-12-27 by cmkwon, td_Guild�� �ʵ� �ΰ� �߰��Ѱ� ����
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����, // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �ʵ� �߰�(GuildMarkState)
	INSERT INTO td_Guild VALUES (@name, @commander, @capacity, 0, NULL, 0, 0, NULL, 0, 0, 0, 0, 0, NULL, 0, 0, 0)

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END

	SELECT SCOPE_IDENTITY();	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
GO

-- !!!!
-- Name:
-- Desc:
-- ====
--DROP PROCEDURE atum_InsertGuildMember
--GO
CREATE PROCEDURE dbo.atum_InsertGuildMember
	@guildUniqueNum		INT,	-- UINT
	@characUniqueNum	INT,	-- UINT
	@guildRank			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- ���� ����
	INSERT INTO td_GuildMember VALUES(@guildUniqueNum, @characUniqueNum, @guildRank, GetDate())
	
	DECLARE @GuildName VARCHAR(30)
	SET @GuildName = (SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNum)

	-- ĳ������ ��� ���� ������Ʈ
	UPDATE td_Character
	SET GuildName = @GuildName, GuildUniqueNumber = @guildUniqueNum
	WHERE UniqueNumber = @characUniqueNum
GO

-- !!!!
-- Name:
-- Desc:
-- ====
--DROP PROCEDURE atum_DeleteGuildMember
--GO
CREATE PROCEDURE dbo.atum_DeleteGuildMember
	@characUniqueNum	INT		-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- �������� ����
	DELETE td_GuildMember WHERE characterUniqueNumber = @characUniqueNum

	-- ĳ������ ��� ���� ����
	UPDATE td_Character
		SET GuildName = NULL, GuildUniqueNumber = 0
		WHERE uniquenumber = @characUniqueNum
GO

-- !!!!
-- Name:
-- Desc:
--		// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �ʵ������ ��� �˻� ó���ϸ� �ʵ� �߰���
-- ====
--DROP PROCEDURE atum_GetGuildInfoByUniqueNumber
--GO
CREATE PROCEDURE dbo.atum_GetGuildInfoByUniqueNumber
	@guildUniqueNum		INT	-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT g.GuildUniqueNumber, g.GuildName, g.GuildCommanderUniqueNumber, g.GuildMemberCapacity, g.GuildState, g.GuildDismemberDate,
			g.GuildMarkVersion, g.GuildMarkSize, g.GuildMarkImage, g.WarWinPoint, g.WarLossPoint, g.TotalFame, g.MonthlyFame,
			g.GuildMarkState, g.Notice, o.OutPostCityMapIndex, g.GuildTotalFameRank, g.GuildMonthlyFameRank
	FROM td_Guild AS g WITH (NOLOCK) LEFT OUTER JOIN td_OutPostInfo AS o WITH (NOLOCK)
		ON g.GuildUniqueNumber = o.OutPostGuildUID	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - OutPostGuildUID ����
		WHERE GuildUniqueNumber = @guildUniqueNum
GO


-- !!!!
-- Name:
-- Desc:
-- ====
--DROP PROCEDURE atum_SaveGuildWarPoint
--GO
CREATE PROCEDURE dbo.atum_SaveGuildWarPoint
	@i_GuildUniqueNumber	INT,	-- UINT
	@i_WarWinPoint			INT,
	@i_WarLossPoint			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
		SET WarWinPoint = @i_WarWinPoint, WarLossPoint = @i_WarLossPoint
		WHERE GuildUniqueNumber = @i_GuildUniqueNumber
GO

-- !!!!
-- Name:
-- Desc:
-- ====
--DROP PROCEDURE atum_GetAllGuildMembers
--GO
CREATE PROCEDURE dbo.atum_GetAllGuildMembers
	@guildUniqueNum		INT	-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
	SELECT c.CharacterName, c.UniqueNumber, gm.GuildRank, c.UnitKind, c.Level
	FROM td_Character c, td_GuildMember gm
	WHERE c.UniqueNumber = gm.CharacterUniqueNumber AND gm.GuildUniqueNumber = @guildUniqueNum
GO



-- !!!!
-- Name: atum_Guild_UpdateMemberCapacity
-- Desc: ��� ���� �ο� ����
-- ====
--DROP PROCEDURE atum_Guild_UpdateMemberCapacity
--GO
CREATE PROCEDURE dbo.atum_Guild_UpdateMemberCapacity
	@guildUniqueNum				INT,		-- UINT
	@MemberCapacity				INT,		--
	@GuildMemberCardCashPrice	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
		SET GuildMemberCapacity = @MemberCapacity, GuildMemberCardCashPrice = GuildMemberCardCashPrice + @GuildMemberCardCashPrice
		WHERE GuildUniqueNumber = @guildUniqueNum
GO

-- !!!!
-- Name: atum_SetDismemberDate
-- Desc: ��� �ػ� ��û�� ����� ����(�ػ���) ���� �� �ػ� ��¥ ����
-- ====
--DROP PROCEDURE atum_SetDismemberDate
--GO
CREATE PROCEDURE dbo.atum_SetDismemberDate
	@guildUniqueNum		INT		-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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


-- !!!!
-- Name: atum_CancelDismember
-- Desc: ��� �ػ� ���
-- ====
--DROP PROCEDURE atum_CancelDismember
--GO
CREATE PROCEDURE dbo.atum_CancelDismember
	@guildUniqueNum		INT		-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
	SET GuildDismemberDate = NULL, GuildState = 0
	WHERE GuildUniqueNumber = @guildUniqueNum
GO

-- !!!!
-- Name: atum_DismemberGuild
-- Desc: ��� ���� ����
-- ====
--DROP PROCEDURE atum_DismemberGuild
--GO
CREATE PROCEDURE dbo.atum_DismemberGuild
	@guildUniqueNum		INT	-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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

-- !!!!
-- Name: atum_ChangeGuildRank
-- Desc: ��� ��� ����
-- ====
--DROP PROCEDURE atum_ChangeGuildRank
--GO
CREATE PROCEDURE dbo.atum_ChangeGuildRank
	@memberUniqueNumber		INT,	-- UINT
	@rank					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_GuildMember
	SET GuildRank = @rank
	WHERE CharacterUniqueNumber = @memberUniqueNumber
GO

-- !!!!
-- Name: atum_ChangeGuildName
-- Desc: ��� �̸� ����
-- ====
--DROP PROCEDURE atum_ChangeGuildName
--GO
CREATE PROCEDURE dbo.atum_ChangeGuildName
	@guildUniqueNumber		INT,	-- UINT
	@guildName				VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
	SET GuildName = @guildName
	WHERE GuildUniqueNumber = @guildUniqueNumber
GO

-- Name: atum_GetGuildMark
-- Desc: ��� ��ũ ��������
-- ====
--DROP PROCEDURE atum_GetGuildMark
--GO
CREATE PROCEDURE dbo.atum_GetGuildMark
	@guildUniqueNumber		INT	-- UINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildMarkVersion, GuildMarkSize, GuildMarkImage
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildUniqueNumber = @guildUniqueNumber
GO

-- Name: atum_SetGuildMark
-- Desc: ��� ��ũ �Ҵ�
-- ====
--			// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �����߰�(@i_guildMarkState		TINYINT)
--DROP PROCEDURE atum_SetGuildMark
--GO
CREATE PROCEDURE dbo.atum_SetGuildMark
	@guildUniqueNumber		INT,	-- UINT
	@guildMarkSize			INT,
	@guildMarkImage			BINARY(1600),
	@i_guildMarkState		TINYINT			-- // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �����߰�(@i_guildMarkState		TINYINT)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @GuildMarkVersion INT
	SET @GuildMarkVersion = (SELECT GuildMarkVersion FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @guildUniqueNumber) + 1

	-- // 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - Update�� �߰���
	UPDATE td_Guild
	SET GuildMarkVersion = @GuildMarkVersion, GuildMarkSize = @guildMarkSize, GuildMarkImage = @guildMarkImage, GuildMarkState= @i_guildMarkState
	WHERE GuildUniqueNumber = @guildUniqueNumber
	
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN @GuildMarkVersion
	SELECT @GuildMarkVersion;
GO

-- Name: atum_GuildAddGuildFame
-- Desc: 2005-12-28 by cmkwon, ���� �� ���ϱ�
-- ====
CREATE PROCEDURE dbo.atum_GuildAddGuildFame
	@i_guildUID				INT,	-- UINT
	@i_totalFameAddition	INT,	-- �߰���
	@i_monthlyFameAddition	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- ====
CREATE PROCEDURE dbo.atumManager_DoMonthlyWork_ProcessMontylyGuildFame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- �Ѵ� ���� �� 10�������� �˻�
	SELECT TOP 10 g.GuildName, g.GuildUniqueNumber as GuildUID, c.CharacterName as GuildMasterCharacterName
				, g.GuildCommanderUniqueNumber as GuildMasterCharacterUID, g.TotalFame, g.MonthlyFame
		FROM td_Guild g, td_Character c WITH (NOLOCK)
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
-- ====
CREATE PROCEDURE dbo.atumManager_DoMonthlyWork_ResetMontylyGuildFame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
		SET MonthlyFame = 0
GO

--------------------------------------------------------------------------------
-- GUILDWAR
--------------------------------------------------------------------------------

-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - ������� �ʴ� ���ν���
---- Name: atum_InsertRequestForGuildWar
---- Desc: ����� ��û ����
---- Returns: ��û ����, 0 �����̸� ����
---- ====
----DROP PROCEDURE atum_InsertRequestForGuildWar
----GO
--CREATE PROCEDURE dbo.atum_InsertRequestForGuildWar
--	@i_MapIndex				SMALLINT,
--	@i_DefenderGuildName	VARCHAR(30),
--	@i_ChallengerGuildName	VARCHAR(30)
--AS
--	DECLARE @DefenderGuildUNUM INT
--	DECLARE @ChallengerGuildUNUM INT
--
--	SET @DefenderGuildUNUM = (SELECT TOP 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildName like @i_DefenderGuildName)
--	SET @ChallengerGuildUNUM = (SELECT TOP 1 GuildUniqueNumber FROM td_Guild WITH (NOLOCK) WHERE GuildName like @i_ChallengerGuildName)
--
--	IF (@DefenderGuildUNUM IS NULL OR @ChallengerGuildUNUM IS NULL)
--		RETURN 0
--
--	INSERT INTO td_GuildWar(MapIndex, DefenderGuildUniqueNumber, ChallengerGuildUniqueNumber)
--	VALUES (@i_MapIndex, @DefenderGuildUNUM, @ChallengerGuildUNUM)
--	
--	IF (@@ERROR <> 0)
--		RETURN 0
--
--	RETURN (SELECT count(*) FROM td_GuildWar WITH (NOLOCK)
--			WHERE MapIndex = @i_MapIndex AND DefenderGuildUniqueNumber = @DefenderGuildUNUM)
--GO
--
--

--------------------------------------------------------------------------------
-- FRIEND LIST
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_FriendInsertFriend
	@i_CharacterName				VARCHAR(20),
	@i_FriendName					VARCHAR(20),
	@i_Type							TINYINT,
	@i_RegDate						VARCHAR(30)			-- // 2008-04-11 by dhjin, EP3 �źθ�� -
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO td_FriendList
	VALUES (@i_CharacterName, @i_FriendName, @i_Type, @i_RegDate)
GO

CREATE PROCEDURE dbo.atum_FriendDeleteFriend
	@i_CharacterName				VARCHAR(20),	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ����
	@i_FriendName					VARCHAR(20),	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ����
	@i_Type							TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_FriendList
	WHERE CharacterName = @i_CharacterName AND FriendName = @i_FriendName AND Type = @i_Type
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE CharacterName like @i_CharacterName AND FriendName like @i_FriendName AND Type = @i_Type
GO

CREATE PROCEDURE dbo.atum_FriendLoadFriends
	@i_CharacterName				VARCHAR(20)		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 64�� ����
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM td_FriendList WITH (NOLOCK)
	WHERE CharacterName = @i_CharacterName
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- WHERE CharacterName like @i_CharacterName
GO


-- 2005-11-21 by cmkwon, Auction�� ������� �����Ƿ� �ּ� ó����
----------------------------------------------------------------------------------
---- AUCTION, ��ǰ ���� ����
----------------------------------------------------------------------------------
--
---- !!!!
---- Name: atum_AuctionGetRegisterCount
-- Desc: ��ǰ ���� ������ ������ ���
-- ====
--CREATE PROCEDURE dbo.atum_AuctionGetRegisterCount
--	@i_CharacterUID			INT
--AS
--	SELECT count(*)
--	FROM td_Auction
--	WHERE AuctionCharacterUID = @i_CharacterUID
--GO
--
---- !!!!
---- Name: atum_AuctionRegisterItem
---- Desc: ��ǰ ���� ������ ������ ���
---- ====
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
---- !!!!
---- Name: atum_AuctionCancelItem
---- Desc: ��ǰ ���� ������ ������ ��� ���
---- ====
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
---- !!!!
---- Name: atum_AuctionGetMyItem
---- Desc: ��ǰ ���� ������ ��ϵ� �ڽ��� �������� ��ȯ
---- ====
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
---- !!!!
---- Name: atum_AuctionGetKindItem
---- Desc: ��ǰ ���� ������ ��ϵ� ������ �������� ��ȯ
---- ====
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
---- !!!!
---- Name: atum_AuctionBuyItem
---- Desc: ��ǰ ���� ������ ��ϵ� �����۱���
----       �����ڿ��� ������ �ѱ�, �Ǹ����� â�� �� ����
----       �������� �� ���Ŵ� ���� �� �־�� ��
---- ====
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
-- // 2009-08-03 by cmkwon, ���� �ٸ� ���񽺿��� ������� �ʴ� ���ν���(������ ���� ���� ���) - 
-- --		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- CREATE PROCEDURE dbo.atum_CreateCharacterBulk_I
-- 	@i_AccName		VARCHAR(20),		-- ���� ����
-- 	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	DECLARE @AccUID INT
-- 	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
-- 	IF @AccUID IS NULL
-- 		RETURN
-- 
-- 		-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
-- 	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
-- 							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
-- 							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
-- 		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
-- 					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
-- 					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
-- 					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
-- 					PKWinPoint, PKLossPoint, Material, HP, DP,
-- 					SP, EP, PetName, PetLevel, PetExperience,
-- 					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
-- 					MaxLevel, currentHP, currentDP, currentSP, currentEP,
-- 					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
-- 		FROM td_Character
-- 		WHERE CharacterName = 'I���'
-- 
-- 	-- �⺻ ������ ����
-- 	DECLARE @uniquenumber INT
-- 	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
-- 	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
-- 	IF (@uniquenumber IS NULL)
-- 		RETURN
-- 
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- �Ƹ� - ���δ� 2005-12-03 by cmkwon
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����
-- 
-- GO


-------------------------------
-- A-GEAR
-------------------------------
-- // 2009-08-03 by cmkwon, ���� �ٸ� ���񽺿��� ������� �ʴ� ���ν���(������ ���� ���� ���) - 
-- --		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- CREATE PROCEDURE dbo.atum_CreateCharacterBulk_A
-- 	@i_AccName		VARCHAR(20),		-- ���� ����
-- 	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	DECLARE @AccUID INT
-- 	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
-- 	IF @AccUID IS NULL
-- 		RETURN
-- 
-- 	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
-- 	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
-- 							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
-- 							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
-- 		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
-- 					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
-- 					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
-- 					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
-- 					PKWinPoint, PKLossPoint, Material, HP, DP,
-- 					SP, EP, PetName, PetLevel, PetExperience,
-- 					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
-- 					MaxLevel, currentHP, currentDP, currentSP, currentEP,
-- 					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
-- 		FROM td_Character
-- 		WHERE CharacterName = 'A���'
-- 
-- 	-- �⺻ ������ ����
-- 	DECLARE @uniquenumber INT
-- 	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
-- 	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
-- 	IF (@uniquenumber IS NULL)
-- 		RETURN
-- 
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2�� ���� - ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- ��Ű ���̴�
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����
-- 
-- GO


-------------------------------
-- B-GEAR
-------------------------------
-- // 2009-08-03 by cmkwon, ���� �ٸ� ���񽺿��� ������� �ʴ� ���ν���(������ ���� ���� ���) - 
-- --		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- CREATE PROCEDURE dbo.atum_CreateCharacterBulk_B
-- 	@i_AccName		VARCHAR(20),		-- ���� ����
-- 	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	DECLARE @AccUID INT
-- 	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
-- 	IF @AccUID IS NULL
-- 		RETURN
-- 
-- 	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
-- 	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
-- 							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
-- 							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
-- 		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
-- 					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
-- 					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
-- 					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
-- 					PKWinPoint, PKLossPoint, Material, HP, DP,
-- 					SP, EP, PetName, PetLevel, PetExperience,
-- 					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
-- 					MaxLevel, currentHP, currentDP, currentSP, currentEP,
-- 					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
-- 		FROM td_Character
-- 		WHERE CharacterName = 'B���'
-- 
-- 	-- �⺻ ������ ����
-- 	DECLARE @uniquenumber INT
-- 	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
-- 	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
-- 	IF (@uniquenumber IS NULL)
-- 		RETURN
-- 
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����
-- 
-- GO


-------------------------------
-- M-GEAR
-------------------------------
-- // 2009-08-03 by cmkwon, ���� �ٸ� ���񽺿��� ������� �ʴ� ���ν���(������ ���� ���� ���) - 
-- --		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- --		2007-01-24 by cmkwon, ���ν��� �뵵 ���� - 'M���' ĳ���͸� ������ ĳ���͸� �߰��ϴ� ���ν���
-- CREATE PROCEDURE dbo.atum_CreateCharacterBulk_M
-- 	@i_AccName		VARCHAR(20),		-- ���� ����
-- 	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- -- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
-- AS
-- 	DECLARE @AccUID INT
-- 	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
-- 	IF @AccUID IS NULL
-- 		RETURN
-- 
-- 	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
-- 	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
-- 							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
-- 							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
-- 		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
-- 					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
-- 					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
-- 					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
-- 					PKWinPoint, PKLossPoint, Material, HP, DP,
-- 					SP, EP, PetName, PetLevel, PetExperience,
-- 					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
-- 					MaxLevel, currentHP, currentDP, currentSP, currentEP,
-- 					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
-- 		FROM td_Character
-- 		WHERE CharacterName = 'M���'
-- 
-- 	-- �⺻ ������ ����
-- 	DECLARE @uniquenumber INT
-- 	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
-- 	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
-- 	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
-- 	IF (@uniquenumber IS NULL)
-- 		RETURN
-- 
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- ����
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- �Ƹ� - ����� 2005-12-03 by cmkwon
-- 	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����
-- 
-- GO


-------------------------------
-- �α� ������ procedures
-------------------------------

-- !!!!
-- Name: atum_log_insert_connection
-- Desc: inserts connection log
-- ====
--		2006-09-14 by cmkwon, Add Parameter - @i_ServerGroupID INT
--		// 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - atum_Update_ConnectingServerGroupID_Of_Account() ���ν����� ó��
--
CREATE PROCEDURE dbo.atum_log_insert_connection
	@i_LogType					TINYINT,
	@i_IPAddress				BINARY(4),
	@i_AccountUniqueNumber		INT,
	@i_AccountName				VARCHAR(20),
	@i_ServerName				VARCHAR(20),
	@i_ServerGroupID			INT,				-- 2006-09-14 by cmkwon, �߰���
	@i_PubilsherName			VARCHAR(20)			-- 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.atum_log_connection
	VALUES (@i_LogType, GetDate(), @i_IPAddress,
			@i_AccountUniqueNumber, @i_AccountName, @i_ServerName, @i_PubilsherName)

	-- // 2007-11-06 by cmkwon, ���� �α� DB ���� ���� �����ϱ� - atum_Update_ConnectingServerGroupID_Of_Account() ���ν����� ó��
	---- 2006-09-14 by cmkwon
	---- �α��ν�(0 == @i_LogType)	==> ConnectingServerGroupID�� @i_ServerGroupID�� �����Ѵ�
	---- �α׾ƿ���(0 <> @i_LogType)	==> ConnectingServerGroupID�� 0�� �����Ѵ�
	--IF (0 = @i_LogType)
	--	BEGIN
	--		UPDATE atum2_db_account.dbo.td_account
	--			SET ConnectingServerGroupID = @i_ServerGroupID
	--			WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	--	END
	--ELSE
	--	BEGIN
	--		UPDATE atum2_db_account.dbo.td_account
	--			SET ConnectingServerGroupID = 0
	--			WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	--	END
GO

-- !!!!
-- Name: atum_log_insert_user_level_stat
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_level_stat
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1, @i_Param2, @i_Param3)
GO

-- !!!!
-- Name: atum_log_insert_user_exp
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_exp
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1, @i_Param2)
GO

-- !!!!
-- Name: atum_log_insert_user_game_start_end
-- Desc: inserts log
--			2006-12-18 by cmkwon, ���� �߰�(@i_PCBangPlayTime INT)
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_game_start_end
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_CharacterName, @i_AccountUniqueNumber, @i_AccountName, @i_PlayTime, @i_TotalPlayTime, @i_PCBangPlayTime, @i_PCBangUID)
GO

-- !!!!
-- Name: atum_log_insert_user_quest_pk_dead
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_quest_pk_dead
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_Param1)
GO

-- !!!!
-- Name: atum_log_insert_user_warp
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_warp
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_Position_X, @i_Position_Y, @i_Position_Z,
			@i_TargetMapIndex, @i_TargetPosition_X, @i_TargetPosition_Y, @i_TargetPosition_Z)
GO

-- !!!!
-- Name: atum_log_insert_user_speed_hack
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_speed_hack
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex, @i_Position_X,
			@i_Position_Y, @i_Position_Z, @i_CheckType, @i_ReceivedMoveCounts, @i_EngineItemNum,
			@i_ServerPastTime, @i_ClientPastTime, @i_PastDistance, @i_CurrentSpeed)
GO

-- !!!!
-- Name: atum_log_insert_user_memory_hack
-- Desc: 2005-12-20 by cmkwon
--			inserts log
-- ====

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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_user_memory_hack
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex, @i_Position_X,
			@i_Position_Y, @i_Position_Z, @i_ItemKind, @i_ItemNum, @i_ItemUniqueNumber,
			@i_MemoryHackCheckType, @i_ValidValue, @i_CurrentValue, @i_Param1)
GO


-- !!!!
-- Name: atum_log_insert_item_charac_use
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_item_charac_use
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount, @i_Param1)
GO

-- !!!!
-- Name: atum_log_insert_item_get_throw
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_item_get_throw
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount)
GO

-- !!!!
-- Name: atum_log_insert_item_buy_sell
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_item_buy_sell
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount, @i_RemainedMoney)
GO

-- !!!!
-- Name: atum_log_insert_item_trade
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_item_trade
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber, @i_MapIndex,
			@i_ItemUniqueNumber, @i_ItemNum, @i_CurrentCount,
			@i_ChangeCount, @i_PeerCharacterName, @i_PeerCharacterUniqueNumber)
GO

-- !!!!
-- Name: atum_log_insert_server_map
-- Desc: inserts log
-- ====
--DROP PROCEDURE atum_log_insert_server_map
--GO
CREATE PROCEDURE dbo.atum_log_insert_server_map
	@i_LogType						TINYINT,
	@i_MapIndex						SMALLINT,
	@i_ChannelIndex					SMALLINT,
	@i_ClientCount					INT,
	@i_MonsterCount					INT,
	@i_MGameServerID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_server_map
	VALUES (@i_LogType, GetDate(), @i_MapIndex, @i_ChannelIndex,
			@i_ClientCount, @i_MonsterCount, @i_MGameServerID)
GO

-- !!!!
-- Name: atum_log_insert_monster_boss
-- Desc: inserts log
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_monster_boss
	VALUES (@i_LogType, GetDate(), @i_MapIndex, @i_ChannelIndex,
			@i_MonsterUnitKind, @i_CreatedTime, @i_DeadTime, @i_AttackUser1, @i_AttackUser2,
			@i_AttackUser3, @i_AttackUser4, @i_AttackUser5, @i_AttackUser6, @i_AttackUser7,
			@i_AttackUser8, @i_AttackUser9, @i_AttackUser10, @i_DropItemList, @i_MGameServerID)
GO

-- !!!!
-- Name: mgame_server_stat
-- Desc: mgame ����
-- ====
--DROP PROCEDURE atum_server_stat_for_mgame
--GO
CREATE PROCEDURE dbo.atum_server_stat_for_mgame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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

-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	--exec [pubaccount].[dbo].PB_GAMELOGIN @strClientID, @strIPAddr, @nGameID
GO

-- ������ üũ ���ν���
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_GAMELOGOUT
	@strClientID	VARCHAR(20)			-- User ID  <<  MGame ID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	--exec [pubaccount].[dbo].PB_GAMELOGOUT @strClientID
GO


-- ������ üũ �ʱ�ȭ ���ν���
-- 2003-09-22 by CKS
CREATE PROCEDURE dbo.PB_INIT
	@nGameID int		-- GameSvr ID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	--exec [pubaccount].[dbo].PB_INIT @nGameID

	-- 2007-01-29 by cmkwon, ServerGroupID �ʱ�ȭ
	UPDATE atum2_db_account.dbo.td_account 
	SET ConnectingServerGroupID = 0
	WHERE ConnectingServerGroupID = @nGameID
GO
-- end_������ ������ üũ ���ν���
-------------------------------------------------------------------------------


--
-------------------------------------------------------------------------------
-- ���� ������(�Ϲ������̾�, ���� �����̾�) ���� ���ν���

-- 2005-01-20 by cmkwon, ������ ���� �������� �����´�
CREATE PROCEDURE dbo.atum_GetAccountCashStoreItem
	@i_accNum		INT					-- AccountUniqueNumber
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.td_accountcashstore WITH (NOLOCK)
		WHERE AccountUniqueNumber = @i_accNum
GO

-- 2005-01-20 by cmkwon, Cash ī�带 �߰�
CREATE PROCEDURE dbo.atum_insert_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber
	@i_ItemNum			INT,				-- �߰� �� ItemNum
	@i_CurTime			VARCHAR(30),		-- ���� �ð�
	@i_ExpireTime		VARCHAR(30)			-- ��� ���� �ð�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @RetUniqueNum	BIGINT
	SET @RetUniqueNum = (SELECT uniqueNumber FROM atum2_db_account.dbo.td_accountcashstore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NOT NULL)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 0
		SELECT 0;
		RETURN;
	END
	
	INSERT INTO atum2_db_account.dbo.td_accountcashstore
		VALUES (@i_accNum, @i_ItemNum, @i_CurTime, @i_CurTime, @i_ExpireTime)
	
	SET @RetUniqueNum = (SELECT uniqueNumber FROM atum2_db_account.dbo.td_accountcashstore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NULL)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 0
		SELECT 0;
		RETURN;
	END
	
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN @RetUniqueNum
	SELECT @RetUniqueNum;
GO

-- 2005-01-20 by cmkwon, Cash ī�� ������ Update
CREATE PROCEDURE dbo.atum_update_AccountCashStoreItem
	@i_accNum			INT,				-- AccountUniqueNumber	
	@i_ItemNum			INT,				-- ã�� ����Ÿ�� ������ ItemNum	
	@i_CurTime			VARCHAR(30),		-- ���� �ð�
	@i_ExpireTime		VARCHAR(30)			-- ��� ���� �ð�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @RetUniqueNum	BIGINT
	SET @RetUniqueNum = (SELECT uniqueNumber FROM atum2_db_account.dbo.td_accountcashstore WHERE AccountUniqueNumber = @i_accNum)
	IF (@RetUniqueNum IS NULL)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 0
		SELECT 0;
		RETURN;
	END
	
	UPDATE atum2_db_account.dbo.td_accountcashstore
		SET ItemNum = @i_ItemNum, UpdatedTime = @i_CurTime, ExpireTime = @i_ExpireTime
		WHERE uniqueNumber = @RetUniqueNum
			
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN @RetUniqueNum
	SELECT @RetUniqueNum;
GO

-- 2005-01-20 by cmkwon, Cash ī�� ������ �����Ѵ�
CREATE PROCEDURE dbo.atum_delete_AccountCashStoreItem
	@i_accNum			INT				-- AccountUniqueNumber
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_accountcashstore
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT OccupyGuildUID, OccupyGuildName, OccupyGuildMasterCharUID, Tex
		, CityWarDefaultTime, CityWarSettingTime, DefenseCounts, SumOfTex, Briefing 
		FROM td_OccupyInfo WITH (NOLOCK) WHERE MapIndex = @i_MapIndex AND MGameServerID = @i_MGameServerID
GO

-- 2005-02-04 by cmkwon, ������ ��ȿ���� üũ�Ѵ�
CREATE PROCEDURE dbo.atum_CityWar_CheckGuildAndGuildMaster
	@i_GuildUID					INT,				-- ����UID
	@i_GuildMasterCharUID		INT					-- ������ CharacterUID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @guildUID INT
	SET @guildUID = (SELECT g.GuildUniqueNumber
						FROM td_Guild g, td_Character c
						WHERE c.UniqueNumber = @i_GuildMasterCharUID AND c.GuildUniqueNumber = g.GuildUniqueNumber
							AND g.GuildCommanderUniqueNumber = @i_GuildMasterCharUID)
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--IF (@guildUID IS NULL)	RETURN 0
	--ELSE					RETURN 1
	IF (@guildUID IS NULL)	SELECT 0;
	ELSE					SELECT 1;	
GO

-- 2005-02-04 by cmkwon, ������ ��ȿ���� üũ�Ѵ�
CREATE PROCEDURE dbo.atum_CityWar_LoaingCityWarGuildList
	@i_CityWarQuestIndex		INT,				-- Quest Index
	@i_MGameServerID			INT					-- ������������ �߻��� ������ä�� ID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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


-- !!!!
-- Name: atum_UpdateInfluenceWarData
-- Desc: 2006-04-14 by cmkwon, 
-- ====
CREATE PROCEDURE dbo.atum_UpdateInfluenceWarData
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,				-- ������������ �߻��� ������ä�� ID
	@i_WartimeStage				TINYINT,
	@i_ContributionPoint		INT					-- 
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_InfluenceWarData
		SET WartimeStage = @i_WartimeStage, ContributionPoint = @i_ContributionPoint
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
GO


-- !!!!
-- Name: atum_UpdateOwnerOfConflictArea
-- Desc: 2006-07-12 by cmkwon, 
-- ====
CREATE PROCEDURE dbo.atum_UpdateOwnerOfConflictArea
	@i_InfluenceType			TINYINT,			-- �������� ���� ����
	@i_MGameServerID			INT					-- ������������ �߻��� ������ä�� ID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * 
		FROM atum2_db_account.dbo.td_couponlist WITH (NOLOCK)
		WHERE CouponNumber = @i_CouponNumber
GO

-- ���� ����ϱ�
CREATE PROCEDURE dbo.atum_Coupon_UseCoupon
	@i_UniqueNumber			INT,				-- ���� ����ũ �ѹ�
	@i_UsedAccountName		VARCHAR(20),		-- ���� ��� AccountName
	@i_UsedTime				VARCHAR(30)			-- ���� ��� �ð�(���� ���� �ð��� ����)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_couponlist
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ʵ� �߰�(InfluenceType)�� �Ʒ��� ���� �ʵ�� ��÷� ������
	--SELECT * 
	--	FROM ti_HappyHourEvent WITH (NOLOCK)
	--	WHERE ServerGroupID= 0 OR ServerGroupID= @i_ServerGroupID
	--	ORDER BY DayOfWeek, StartTime
	SELECT UniqueNumber, ServerGroupID, DayOfWeek, StartTime, EndTime, EXPRate, SPIRate, EXPRepairRate, DropItemRate, DropRareItemRate
			, WarPointRate, InfluenceType, MinLevel, MaxLevel
	FROM atum2_db_account.dbo.ti_HappyHourEvent WITH (NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @searchUniqueNumber INT
	-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �ش� ������ �Ⱓ�� �˻��Ѵ�.
	SET @searchUniqueNumber = (SELECT UniqueNumber FROM atum2_db_account.dbo.ti_HappyHourEvent WHERE InfluenceType = @i_InflTy AND DayOfWeek = 7)

	IF (@searchUniqueNumber IS NULL)
		BEGIN
			INSERT INTO atum2_db_account.dbo.ti_HappyHourEvent
				VALUES(0, 7, @i_StartTime, @i_EndTime, 0, 0, 0, 0, 0, 0, @i_InflTy, 1, 100)
				-- 2007-08-31 by cmkwon, ����
				-- // 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� �ʵ� �߰���
				-- // 2008-03-13 by dhjin, Level�� ���Ǿƿ� �̺�Ʈ ���� -
		END
	ELSE
		BEGIN
			UPDATE atum2_db_account.dbo.ti_HappyHourEvent
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @searchUniqueNumber INT
	SET @searchUniqueNumber = (SELECT UniqueNumber	FROM td_Character WHERE CharacterName = @i_ChangeCharacterName)

	IF (@searchUniqueNumber IS NOT NULL)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--return 0
		SELECT 0;
		RETURN;
	END
	
	-- ģ������Ʈ���� ���(�ڽ�,����) ����
	DELETE FROM td_FriendList
		WHERE CharacterName = @i_OriginCharacterName OR FriendName = @i_OriginCharacterName
	
	UPDATE td_Character
		SET CharacterName = @i_ChangeCharacterName
		WHERE UniqueNumber = @i_CharacterUID
	
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- return 1
	SELECT 1;
GO
-- End_���� ������ ����
-----------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- ���� ���˽� GameLog BackUp Procedure         --2006-06-30 by dhJin 
CREATE PROCEDURE dbo.atum_GameLog_BackUp
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - 
CREATE PROCEDURE dbo.atum_GetEventItemList
	@i_AccountUID			int,
	@i_ItemEventUID			int,
	@i_CharacterUID			INT		-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - 
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - �Ʒ��� ���� ����
	--Select GetTime from atum2_db_account.dbo.atum_log_itemevent WITH (NOLOCK)
	--where AccountUID = @i_AccountUID and ItemEventUID = @i_ItemEventUID
	IF (0 = @i_CharacterUID) 
	BEGIN
		SELECT TOP 1 GetTime FROM atum2_db_account.dbo.atum_log_itemevent WITH (NOLOCK)
		WHERE AccountUID = @i_AccountUID AND ItemEventUID = @i_ItemEventUID
		ORDER BY GetTime DESC
	END
	ELSE
	BEGIN
		SELECT TOP 1 GetTime FROM atum2_db_account.dbo.atum_log_itemevent WITH (NOLOCK)
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND ItemEventUID = @i_ItemEventUID
		ORDER BY GetTime DESC
	END
GO
-- end �̺�Ʈ ������ ���� ���� ���� �˻��ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �̺�Ʈ ������ ���� ���� ���� ����ϴ� ���ν���
-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - 
CREATE PROCEDURE dbo.atum_insert_Log_ItemEvent
	@i_AccountUID               int,
	@i_CharacterUID             int,
	@i_ItemEventUID             int,
	@i_InsertItemTime			VARCHAR(50)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - ���� ������ ���� ����
	--Delete from atum2_db_account.dbo.atum_log_itemevent 
	--	where AccountUID = @i_AccountUID and ItemEventUID = @i_ItemEventUID
	INSERT INTO atum2_db_account.dbo.atum_log_itemevent 
		VALUES(@i_AccountUID, @i_CharacterUID, @i_ItemEventUID, @i_InsertItemTime)
GO
-- end �̺�Ʈ ������ ���� ���� ���� ����ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �̺�Ʈ ������ �˻� �ϴ� ���ν���
-- // 2008-02-01 by cmkwon, ItemEvent �� LastGameEndDate üũ ��ƾ �߰� - �ʵ� �߰� �� �� �˻� ����� �߰�
-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - �ʵ� �߰� �� �� �˻� ����� �߰�
CREATE PROCEDURE [dbo].[atum_Load_ItemEvent]
--WITH EXECUTE AS 'proexe'
AS
	SELECT ItemEventUID,ItemEventType,OnlyPCBang,InfluenceType,ItemNum,Count,StartTime,EndTime,MemberShip,ReqLevel,NewMember,UnitKind,PrefixCodeNum,SuffixCodeNum,UseLastGameEndDate,LastGameEndDate,CheckWithCharacterUID,LevelMin,LevelMax,LoginCheckNumber -- // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���� �߰�
			,UseFixedPeriod, FixedPeriod -- // 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
	FROM atum2_db_account.dbo.ti_ItemEvent WITH (NOLOCK)
GO
-- end �̺�Ʈ ������ �˻� �ϴ� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ ���� ����� ���ν���
---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_GetQuickSlot]
-- DESC: 2012-06-19 by jhseol, ��� ������ �´� ������ ���� �� �ֵ��� ����
---------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_QuickSlot
	@i_AccountUID                int,
	@i_CharacterUID               int,
	@i_TabIdx                     int
	,@i_SlotPurpose				 int
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_QuickSlot 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND TabIdx = @i_TabIdx AND SlotPurpose = @i_SlotPurpose
GO
-- end ������ ���� ����� ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ ������Ʈ ���ν���
---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_GetQuickSlot]
-- DESC: 2012-06-19 by jhseol, ��� ������ �´� ������ ������Ʈ �� �� �ֵ��� ����
---------------------------------------------------------------------
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
	@i_ItemNum_8                  int,		-- // 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	@i_ItemNum_9                  int,		-- // 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	@i_ItemNum_10                 int		-- // 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	,@i_SlotPurpose				  int
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckNum  INT
	SET @CheckNum = (SELECT TabIdx FROM td_QuickSlot 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID 
				 AND TabIdx = @i_TabIdx AND SlotPurpose = @i_SlotPurpose)
	IF (@CheckNum IS NOT NULL)
	BEGIN
		UPDATE td_QuickSlot
		SET ItemNum_1 = @i_ItemNum_1, ItemNum_2 = @i_ItemNum_2, 
		ItemNum_3 = @i_ItemNum_3, ItemNum_4 = @i_ItemNum_4, 
		ItemNum_5 = @i_ItemNum_5, ItemNum_6 = @i_ItemNum_6,
		ItemNum_7 = @i_ItemNum_7, ItemNum_8 = @i_ItemNum_8,
		ItemNum_9 = @i_ItemNum_9, ItemNum_10 = @i_ItemNum_10		--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID 
				 AND TabIdx = @i_TabIdx AND SlotPurpose = @i_SlotPurpose
	END
	ELSE
	BEGIN
		INSERT INTO td_QuickSlot 
		VALUES(@i_AccountUID, @i_CharacterUID, @i_TabIdx, @i_ItemNum_1,
		 @i_ItemNum_2, @i_ItemNum_3, @i_ItemNum_4, @i_ItemNum_5,
		 @i_ItemNum_6, @i_ItemNum_7, @i_ItemNum_8, @i_ItemNum_9, @i_ItemNum_10, @i_SlotPurpose)			--// 2008-06-19 by dhjin, EP3 - 8 -> 10���� ���� 
	END
GO
-- end ������ ������Ʈ ���ν���
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2006-09-04 by dhjin, ������ �˻� ���ν���
---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_GetQuickSlot]
-- DESC: 2012-06-19 by jhseol, ��� ������ �´� ������ ������ �� �ֵ��� ����
---------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetQuickSlot
	@i_AccountUID               int,
	@i_CharacterUID             int
	,@i_SlotPurpose				int
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT [AccountUID],[CharacterUID],[TabIdx],[ItemNum_1],[ItemNum_2],[ItemNum_3],[ItemNum_4],[ItemNum_5],[ItemNum_6],[ItemNum_7],[ItemNum_8],[ItemNum_9],[ItemNum_10]
		FROM td_QuickSlot WITH (NOLOCK)
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND SlotPurpose = @i_SlotPurpose
GO
-- end ������ �˻� ���ν���
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- ���� â�� ����
-- !!!!	2006-09-21 by cmkwon
-- Name: atum_Get_GuildStore
-- Desc: �ش� ���� â�� ������ ��������
-- 		
--		
-- ====
CREATE PROCEDURE dbo.atum_Get_GuildStore
	@i_GuildUID         INT,
	@i_ItemStorage		TINYINT		-- 2006-09-25 by cmkwon
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM td_Store WITH (NOLOCK)
		WHERE Possess = @i_GuildUID AND ItemStorage = @i_ItemStorage
GO

-- !!!!
-- Name: atum_Update_Guild_Store
-- Desc: 2006-09-08 by dhjin
-- ====
CREATE PROCEDURE dbo.atum_Update_Guild_Store 
	@i_ItemUID                  INT,
	@i_AccountUID                INT,
	@i_Possess					 INT,
	@i_ItemStorage				 TINYINT,
	@i_Count                     INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store 
		SET AccountUniqueNumber = @i_AccountUID, Possess = @i_Possess, 
				ItemStorage = @i_ItemStorage, CurrentCount = @i_Count
		WHERE UniqueNumber = @i_ItemUID
GO

-- !!!!
-- Name: atum_Delete_Guild_Store
-- Desc: 2006-09-08 by dhjin
-- ====
CREATE PROCEDURE dbo.atum_Delete_Guild_Store
	@i_ItemUID                   INT,
	@i_GuildUID                  INT,
	@i_ItemStorage				 TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_Store
		WHERE UniqueNumber = @i_ItemUID AND AccountUniqueNumber = @i_GuildUID AND Possess = @i_GuildUID
GO

-- 2007-01-30 by cmkwon, �ʿ� ��� �ּ� ó���� - atum_GetEnchantBYItemUID() ���ν����� ��ü��
---- !!!!
---- Name: atum_GetAllEnchant2
---- Desc: 2006-09-24 by cmkwon
---- ====
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


-- !!!!
-- Name: atum_GetEnchantBYItemUID
-- Desc: 2007-01-30 by cmkwon, �߰���
-- ====
-- 	// 2013-01-15 by bckim, ��æƮ������ �������ѹ� �߰�
CREATE PROCEDURE [dbo].[atum_GetEnchantBYItemUID]
	@i_ItemUID		BIGINT
--WITH EXECUTE AS 'proexe'
AS
	SELECT TargetItemNum, EnchantItemNum, SequenceNumber
	FROM td_enchant WITH(NOLOCK)
	WHERE @i_ItemUID = TargetItemUniqueNumber

GO








-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- 2006-09-21 by cmkwon, ���� ����

-- !!!!
-- Name: Billing_CashItem_Insert_TO_Store
-- Desc: �ش� ĳ���� â�� ������ �߰�
--		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - ScarcityNumber �ʵ� ����
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- ====
CREATE PROCEDURE dbo.Billing_CashItem_Insert_TO_Store
	@i_AccUID			INT,			-- 
	@i_CharUID			INT,			-- 
	@i_ItemNum			INT,			-- 
	@i_MinTradeQuantity	INT,			-- �ּ� �ŷ� ī��Ʈ(ī���ͺ�:1, ��ī���ͺ�:1�̻�)
	@i_InsertCount		INT				-- �߰� ī��Ʈ
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @ItemKind	TINYINT
	SET @ItemKind		= (SELECT Kind FROM atum2_db_account.dbo.ti_Item WHERE ItemNum = @i_ItemNum)
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
			SET @InsertCount	= @i_InsertCount	-- td_Store ���̺� �߰��� ī��Ʈ
			SET @CurCount		= 1					-- CurrentCount�� �Ҵ� �� ����
		END
	ELSE
		BEGIN
			SET @InsertCount	= 1						-- td_Store ���̺� �߰��� ī��Ʈ
			SET @CurCount		= @i_MinTradeQuantity * @i_InsertCount	-- CurrentCount�� �Ҵ� �� ����
		END

	-------------------------------------------------------------------------------
	-- td_Store ���̺� ������ �߰�
	DECLARE @i	INT
	SET @i		= 0	
	DECLARE @InsertItemUID	BIGINT
	WHILE (@i < @InsertCount)
		BEGIN
			
			-- ĳ������ â��� ������ �߰�
			-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - �Ʒ��� ���� ����
			-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
			-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
			-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
			INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
				VALUES(@i_AccUID, @i_CharUID, 1, 0, @CurCount, 99, @i_ItemNum, 0, 0, 0, 0, 0, 0, GetDate(), 0, 0, 0)
			SET @InsertItemUID = SCOPE_IDENTITY();

			-- ������ ���� �α� �߰�
			-- #define T1_FL_LOG_ITEM_BUY_ITEM					0x25	// 37 - ������ ����
			exec dbo.atum_log_insert_item_buy_sell 37, @i_CharUID, 0, @InsertItemUID, @i_ItemNum, @CurCount, @CurCount, 0

			SET @i		= @i + 1
		END
GO


-- // 2009-04-22 by cmkwon, (ĳ���� ��û)������ ĳ�������� ���� ���� - ���� ���ν��� �ּ� ó����, atum_insertStoreItem_FromWeb() ���ν����� ��ü��.
---- !!!!	2006-09-21 by cmkwon
---- Name: Billing_Insert_Item
---- Desc: ������ ���󿡼� ������ ������ �������� ���ӻ��� ĳ���� â�� �־��ִ� ���ν���
---- 		
----		
----		[out 1] INT nErrCode	==> =0(����), <>0(����, ERR_DB_XXX)
---- ====
--CREATE PROCEDURE dbo.Billing_Insert_Item
--	@i_AccountName				VARCHAR(20),				-- ������ ���� ������
--	@i_CharacterName			VARCHAR(20),				-- ������ ���Ž� ���ӻ󿡼��� ĳ���͸�
--	@i_ItemNum					VARCHAR(50),				-- ������ ����ũ ��ȣ
--	@i_BuyItemCount				INT							-- ������ ���� ī��Ʈ
---- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
--AS
--	--------------------------------------------------------------------------------
--	-- �ش� ���� ���� ����üũ �� ���� ������ ���ӿ� ���� ������ üũ
--	DECLARE @AccUID		INT
--	SET @AccUID			= (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WHERE AccountName = @i_AccountName AND ConnectingServerGroupID = 0)
--	IF (@AccUID IS NULL)
--	BEGIN
--		-- #define ERR_DB_USER_CONNECTING_GAME_SERVER		300			// ������ ���Ӽ����� ���� ���̴� - ������ ������ ���Žô� ������ �����ؾ���
--		SELECT 300
--		RETURN
--	END
--	
--	--------------------------------------------------------------------------------
--	-- ĳ���͸� üũ
--	DECLARE @CharUID	INT
--	SET @CharUID		= (SELECT c.UniqueNumber FROM atum2_db_account.dbo.td_account a, td_Character c
--								WHERE a.AccountName = @i_AccountName AND a.AccountUniqueNumber = c.AccountUniqueNumber AND c.CharacterName = @i_CharacterName)
--	IF (@CharUID IS NULL)
--	BEGIN
--		-- #define ERR_DB_IS_NOT_CHARACTERNAME				301			// ���� DB ���̺� ĳ���͸��� �����ϴ�.
--		SELECT 301
--		RETURN
--	END
--
--	--------------------------------------------------------------------------------
--	-- ������ �˻�
--	-- 1. Ŀ�� ����
--	DECLARE cur_item_info CURSOR 
--	FOR
--		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - �Ʒ��� ���� 8���� �߰���
--		--SELECT ItemNum, Kind, SummonMonster, MinTradeQuantity, Time, ParameterValue1, DestParameter1
--		--		, ParameterValue2, DestParameter2, ParameterValue3, DestParameter3, ParameterValue4, DestParameter4
--		--	FROM atum2_db_account.dbo.ti_Item WHERE ItemNum = @i_ItemNum
--		SELECT ItemNum, Kind, SummonMonster, MinTradeQuantity, Time, ParameterValue1, DestParameter1
--				, ParameterValue2, DestParameter2, ParameterValue3, DestParameter3, ParameterValue4, DestParameter4
--				, ParameterValue5, DestParameter5, ParameterValue6, DestParameter6, ParameterValue7, DestParameter7, ParameterValue8, DestParameter8
--			FROM atum2_db_account.dbo.ti_Item WHERE ItemNum = @i_ItemNum
--
--	-- 2. Ŀ�� ����
--	OPEN cur_item_info
--
--	-- 3. ���� ����
--	DECLARE @ItemNum			INT
--	DECLARE @ItemKind			TINYINT
--	DECLARE @CashItemType		INT
--	DECLARE @MinTradeQuantity	SMALLINT
--	DECLARE @Period				INT			-- �����̾� ������ ���� �Ⱓ(Day)
--	DECLARE @AddItemNum1		FLOAT
--	DECLARE @AddItemCount1		TINYINT
--	DECLARE @AddItemNum2		FLOAT
--	DECLARE @AddItemCount2		TINYINT
--	DECLARE @AddItemNum3		FLOAT
--	DECLARE @AddItemCount3		TINYINT
--	DECLARE @AddItemNum4		FLOAT
--	DECLARE @AddItemCount4		TINYINT
--	DECLARE @AddItemNum5		FLOAT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemCount5		TINYINT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemNum6		FLOAT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemCount6		TINYINT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemNum7		FLOAT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemCount7		TINYINT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemNum8		FLOAT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--	DECLARE @AddItemCount8		TINYINT		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--
--	-- 4. ù �ο� FETCH
--	FETCH NEXT FROM cur_item_info
--		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
--				, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
--				, @AddItemNum5, @AddItemCount5, @AddItemNum6, @AddItemCount6, @AddItemNum7, @AddItemCount7, @AddItemNum8, @AddItemCount8	-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--
--	-- �ʿ���� �κ��� 5. ��ȯ
--	--WHILE @@FETCH_STATUS = 0
--	--BEGIN
--	--	FETCH NEXT FROM cur_item_info
--	--		INTO @ItemNum, @ItemKind, @CashItemType, @MinTradeQuantity, @Period, @AddItemNum1, @AddItemCount1
--	--			, @AddItemNum2, @AddItemCount2, @AddItemNum3, @AddItemCount3, @AddItemNum4, @AddItemCount4
--	--END
--
--	-- 6. Ŀ�� CLOSE
--	CLOSE cur_item_info
--	
--	-- 7. Ŀ�� DEALLOCATE
--	DEALLOCATE cur_item_info
--
--	-- ������ ���� üũ
--	IF (@ItemNum IS NULL) OR (@ItemKind IS NULL) OR (@CashItemType IS NULL) OR (@MinTradeQuantity IS NULL)
--	BEGIN
--		-- #define ERR_DB_INVALID_ITEM						4			// �����Ϸ��� �������� ��ȿ���� ���� - ti_item_info ���̺� ���ų� IsDisable �ʵ尡 0�� �ƴϴ�
--		SELECT 4
--		RETURN
--	END
--	
--	-- // ����ȭ ������ kind - ITEM ����ü���� SummonMonster �ʵ带 ����Ѵ�
--	-- #define CASH_ITEMKIND_PREMIUM_CARD			(BYTE)0
--	-- #define CASH_ITEMKIND_OPTION_ITEM			(BYTE)1
--	-- #define CASH_ITEMKIND_CARD_ITEM				(BYTE)2
--	-- #define CASH_ITEMKIND_ACCESSORY_ITEM		(BYTE)3
--	-- 1. �����̾�ī�� ������ ����
--	-- 2. �Ϲ� ���� ������ ����
--	IF (0 = @CashItemType)
--	BEGIN
--
--		--------------------------------------------------------------------------------
--		-- �����̾� �˻�
--		-- 1. Ŀ�� ����
--		DECLARE cur_premium_info CURSOR 
--		FOR
--			SELECT UniqueNumber, ItemNum, ExpireTime FROM atum2_db_account.dbo.td_accountcashstore WHERE AccountUniqueNumber = @AccUID
--
--		-- 2. Ŀ�� ����
--		OPEN cur_premium_info
--
--		-- 3. ���� ����
--		DECLARE @PremiumUID			BIGINT
--		DECLARE @PremiumItemNum		INT
--		DECLARE @ExpireTime			DATETIME
--			
--		-- 4. ù �ο� FETCH
--		FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
--		-- �ʿ���� �κ��� 5. ��ȯ
--		--WHILE @@FETCH_STATUS = 0
--		--BEGIN
--		--	FETCH NEXT FROM cur_premium_info INTO @PremiumUID, @PremiumItemNum, @ExpireTime
--		--END
--
--		-- 6. Ŀ�� CLOSE
--		CLOSE cur_premium_info
--		
--		-- 7. Ŀ�� DEALLOCATE
--		DEALLOCATE cur_premium_info
--
--		DECLARE @CurDate	DATETIME
--		SET @CurDate		= GetDate()
--		IF (@PremiumUID IS NULL)-- �����̾� �������� ����, �߰�
--		BEGIN
--			INSERT INTO atum2_db_account.dbo.td_accountcashstore
--				VALUES (@AccUID, @ItemNum, @CurDate, @CurDate, DATEADD(Day, @Period, @CurDate))
--		END
--		
--		ELSE-- ������ �����̾� �������� �����Ѵ�.
--		BEGIN
--
--			-- �̹� ����� �����̾� ������
--			IF @ExpireTime < @CurDate
--			BEGIN
--				SET @ExpireTime		= @CurDate
--			END
--
--			ELSE
--			BEGIN
--				-- ���� �� ��¥�� ���� ��¥�κ��� 180�ϱ����� ���԰���
--				IF DATEADD(Day, @Period, @ExpireTime) > DATEADD(Day, 180, @CurDate)
--				BEGIN
--					-- #define ERR_DB_CANNOT_ADD_PREMIUMITEM			303			// �����̾� ������ �߰� ���� �Ұ�(����η� 180�� ����)
--					SELECT 302
--					RETURN
--				END				
--			END
--
--			-- #define ERR_NO_ERROR						0
--			SELECT 0
--
--			UPDATE atum2_db_account.dbo.td_accountcashstore
--				SET UpdatedTime = @CurDate, ExpireTime = DATEADD(Day, @Period, @ExpireTime)
--				WHERE UniqueNumber = @PremiumUID
--		END
--
--		-- �����̾� �߰� ������ �߰����ֱ�
--		IF (@AddItemNum1 IS NOT NULL) AND (0 <> @AddItemNum1) AND (0 < @AddItemCount1)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum1, 1, @AddItemCount1
--		IF (@AddItemNum2 IS NOT NULL) AND (0 <> @AddItemNum2) AND (0 < @AddItemCount2)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum2, 1, @AddItemCount2
--		IF (@AddItemNum3 IS NOT NULL) AND (0 <> @AddItemNum3) AND (0 < @AddItemCount3)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum3, 1, @AddItemCount3
--		IF (@AddItemNum4 IS NOT NULL) AND (0 <> @AddItemNum4) AND (0 < @AddItemCount4)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum4, 1, @AddItemCount4
--
--		-- // 2009-04-21 by cmkwon, ITEM�� DesParam �ʵ� ���� 8���� �ø��� - 
--		IF (@AddItemNum5 IS NOT NULL) AND (0 <> @AddItemNum5) AND (0 < @AddItemCount5)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum5, 1, @AddItemCount5
--		IF (@AddItemNum6 IS NOT NULL) AND (0 <> @AddItemNum6) AND (0 < @AddItemCount6)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum6, 1, @AddItemCount6
--		IF (@AddItemNum7 IS NOT NULL) AND (0 <> @AddItemNum7) AND (0 < @AddItemCount7)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum7, 1, @AddItemCount7
--		IF (@AddItemNum8 IS NOT NULL) AND (0 <> @AddItemNum8) AND (0 < @AddItemCount8)
--			exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @AddItemNum8, 1, @AddItemCount8
--
--	END-- END - IF (0 = @CashItemType)
--
--	ELSE-- �Ϲ� ���� ������
--	BEGIN
--		-- #define ERR_NO_ERROR						0
--		SELECT 0
--
--		exec dbo.Billing_CashItem_Insert_TO_Store @AccUID, @CharUID, @ItemNum, @MinTradeQuantity, @i_BuyItemCount
--	END
--
--GO

-- END_���� ����
-------------------------------------------------------------------------------

-- !!!!
-- Name: atum_log_Insert_GuildStore
-- Desc: 2006-09-27 by dhjin
--		 // 2008-04-02 by dhjin, atum2_db_account.dbo.ti_Item ����ϴ� ���� ������, atum2_db_account.dbo.ti_Item ���� �ʿ� ������
-- ====
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum_log_GuildItem 
		VALUES (@i_LogType, GetDate(), @i_GuildUID, @i_GuildName, @i_AccountUID, @i_AccountName, 
				@i_CharacterUID, @i_CharacterName, @i_ItemUID, @i_ItemNum, 
				@i_PrefixCodeNum, @i_SuffixCodeNum, @i_ItemResultCount, @i_ItemChangeCount)
GO

-- !!!!
-- Name: atum_log_Get_GuildStore
-- Desc: 2006-09-27 by dhjin
-- ====
CREATE PROCEDURE dbo.atum_log_Get_GuildStore
	@i_GuildUID						INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
		SELECT   LogType, Time, CharacterUID, CharacterName, ItemNum, 
					PrefixCodeNum, SuffixCodeNum, ItemChangeCount
		FROM     atum_log_GuildItem
		WHERE	 (DATEDIFF(hh, Time, GETDATE()) < 48) AND (GuildUID = @i_GuildUID)
		ORDER BY Time
GO

-- !!!!
-- Name: atum_AllDelete_Guild_Store
-- Desc: 2006-09-29 by dhjin
-- ====
CREATE PROCEDURE dbo.atum_AllDelete_Guild_Store
	@i_GuildUID                  INT,
	@i_ItemStorage				 TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_Store
		WHERE AccountUniqueNumber = @i_GuildUID AND Possess = @i_GuildUID AND ItemStorage = @i_ItemStorage
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_StoreSkill
-- DESC      : 2006-11-17 by dhjin, 2�� ��ų ��� ���� ������Ʈ
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStoreItemSkillUseTime
	@ItemUID		BIGINT,
	@i_UseTime		VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_StoreSkill
		SET UseTime = @i_UseTime
		WHERE UniqueNumber = @ItemUID
GO


-- Name: atum_Change_AccountName_Of_AllCharacter
-- Desc: 2007-01-22 by cmkwon, �߰� ��
--		   �ش� ������ ĳ���� ������ ã�Ƽ� ��� ������ �������� �����Ѵ�.
-- ====
CREATE PROCEDURE dbo.atum_Change_AccountName_Of_AllCharacter
	@i_OriginAccountName		VARCHAR(20),
	@i_NewAccountName			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UID, ST_IP, ED_IP FROM atum2_db_account.dbo.td_PCBang with(NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.atum_log_integration
	VALUES(@i_LogType, GetDate(), @i_AccountName, @i_AccountUID, @i_SourceDBNum, @i_SourceCharUID, @i_SourceCharName,
		@i_TargetDBNum, @i_TargetCharUID, @i_TargetCharName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_log_select_integration
-- DESC      : 2007-01-30 by dhjin, ���� ����,���� �α� �˻�
--				// 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_select_integration
	@i_str				VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (@i_str = '')
	BEGIN
		-- // 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
		SELECT AccountUID, AccountName, SourceDBNum, SourceCharacterUID, SourceCharacterName, 
			TargetDBNum, TargetCharacterUID, TargetCharacterName, Time, LogType
		FROM atum2_db_account.dbo.atum_log_integration WITH (NOLOCK) 
		order by Time
	END
	ELSE
	BEGIN
		-- // 2008-03-03 by cmkwon, ������ ���� �α� Ÿ�� �����ֱ� - �˻� ����� �α�Ÿ�� �߰�
		DECLARE @Query VARCHAR(3000)
		SET @Query = 'SELECT AccountUID, AccountName, SourceDBNum, SourceCharacterUID, 
				SourceCharacterName, TargetDBNum, TargetCharacterUID, TargetCharacterName, Time, LogType	
				FROM atum2_db_account.dbo.atum_log_integration WITH (NOLOCK) where ' 
				+@i_str + ' order by Time'
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- TABLE NAME: atum_InsertLeaderItem
-- DESC      : 2007-02-13 by dhjin, ������ ���� ������ �����ϴ� ���ν���
--				7001320	�������� ����(����������)
--				7001330	�������� ����(�˸���)
--				7001090	������ ��ȣ
--				7001110	������ �ð�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteLeaderItem
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001320
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001330
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001090
	DELETE FROM dbo.td_Store WHERE Itemnum = 7001110
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Update_SubLeader
-- DESC      : 2007-02-13 by dhjin, �������� ���� ���ν���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_SubLeader
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- @o_RetCode				INT OUTPUT,
	@i_CharacterName		varchar(20),
	@i_InflType				TINYINT,
	@i_SubLeaderRank		TINYINT,
	@i_OrderNormalRace		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @SetSubLeaderNum	INT
	DECLARE @SetUID				INT
	DECLARE @CheckCount	INT

	IF(0 <> @i_OrderNormalRace)
	BEGIN
		SELECT @SetUID = UniqueNumber FROM dbo.td_Character WITH(NOLOCK) where CharacterName = @i_CharacterName AND InfluenceType = @i_InflType
		IF(@SetUID IS NULL)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 10						-- �������� �ɸ��� �˻� �̸��� ����.
			-- RETURN
			SELECT 0, 10;
			RETURN;
		END
	END
	ELSE
	BEGIN
		SELECT @SetUID = UniqueNumber FROM dbo.td_Character WITH(NOLOCK) where CharacterName = @i_CharacterName AND InfluenceType = @i_InflType AND Race = 2
		IF(@SetUID IS NULL)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 10						-- �������� �ɸ��� �˻� �̸��� ����.
			-- RETURN
			SELECT 0, 10;
			RETURN;
		END
	END

	
	SELECT @CheckCount = count(*)  FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
		WHERE InfluenceType = @i_InflType  AND (InflSub1LeaderCharacterUID = @SetUID OR  InflSub2LeaderCharacterUID = @SetUID OR InflLeaderCharacterUID = @SetUID)
	
	IF(@CheckCount > 0)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		-- SET @o_RetCode = 0
		-- RETURN
		SELECT 0, 0;
		RETURN;
	END

	IF(1 = @i_SubLeaderRank)
	BEGIN
		SELECT @SetSubLeaderNum = InflSub1LeaderCharacterUID FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
				WHERE InfluenceType = @i_InflType AND  InflSub2LeaderCharacterUID <> @SetUID AND InflLeaderCharacterUID <> @SetUID
		IF(@SetSubLeaderNum = @SetUID)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 20						-- �̹� �������ڷ� ���� �Ǿ��ִ�.
			-- RETURN
			SELECT 0, 20;
			RETURN;
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub1LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType

			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 1
			-- RETURN	@SetUID							-- ��������1�� ����
			SELECT @SetUID, 1;
			RETURN;
		END
	END
	
	ELSE IF(2 = @i_SubLeaderRank)
	BEGIN
		SELECT @SetSubLeaderNum = InflSub2LeaderCharacterUID FROM dbo.td_InfluenceWarData WITH(NOLOCK) 
				WHERE InfluenceType = @i_InflType AND  InflSub1LeaderCharacterUID <> @SetUID AND InflLeaderCharacterUID <> @SetUID
		IF(@SetSubLeaderNum = @SetUID)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 20						-- �̹� �������ڷ� ���� �Ǿ��ִ�.
			-- RETURN
			SELECT 0, 20;
			RETURN;
		END
		IF(@SetSubLeaderNum = 0 OR @SetSubLeaderNum IS NULL)
		BEGIN
			UPDATE dbo.td_InfluenceWarData SET InflSub2LeaderCharacterUID = @SetUID
			WHERE InfluenceType = @i_InflType
			
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- SET @o_RetCode = 2
			-- RETURN	@SetUID							-- ��������2�� ����
			SELECT @SetUID, 2;
			RETURN;
		END
	END
	
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- SET @o_RetCode = 0
	-- RETURN										-- �������� ������ �̹� �Ǿ��־ ������ �ȵȴ�.
	SELECT 0,0;
GO

-- 2007-05-15 by cmkwon, �Ʒ��� ���ν����� ����
----------------------------------------------------------------------------------
---- TABLE NAME: atum_SelectDeletedCharacter
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
-- TABLE NAME: atum_admin_GetAllDeletedCharacter
-- DESC      : 2007-05-15 by cmkwon,
--				// 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� �� ����, ���� ������ ���� �����ֱ� �߰� - �������� �ʵ� �߰�(InfluenceType, SelectableInfluenceMask)
--				// 2008-03-03 by cmkwon, ���� ������ ĳ���͸���Ʈ ������ ���� �� ��¥ ���� �ֱ� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_GetAllDeletedCharacter
	@i_AccName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� �� ����, ���� ������ ���� �����ֱ� �߰� - �������� �ʵ� �߰�(InfluenceType, SelectableInfluenceMask)
	-- // 2008-03-03 by cmkwon, ���� ������ ĳ���͸���Ʈ ������ ���� �� ��¥ ���� �ֱ� - ������ ��¥ �������� �߰�, ������ ��¥ ������ ���� �߰�
	SELECT AccountUniqueNumber, AccountName, UniqueNumber, CharacterName, InfluenceType, SelectableInfluenceMask, LastStartedTime FROM td_Character WITH (NOLOCK) 
	WHERE 0 <> Race & 0x4000 AND AccountName = @i_AccName
	ORDER BY LastStartedTime
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_LiveDeletedCharacter
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LiveDeletedCharacter
	@i_AccountUID		INT,
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @LivedCheck		TINYINT
	SELECT @LivedCheck = count(*) FROM atum_log_Live_Deleted_Character WITH (NOLOCK) WHERE CharacterUID = @i_CharacterUID

	-- // 2008-02-20 by cmkwon, ���� ��û���� 2ȸ���� ���� �����ϴ�
	IF (@LivedCheck >= 2)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- RETURN	10			-- ���� ������ �ִ� �ɸ���
			SELECT 10;
			RETURN;
		END
	
	DECLARE @CharacterNum		INT
	SELECT @CharacterNum = count(*) FROM td_Character WITH (NOLOCK) WHERE 0 = Race & 0x4000 AND AccountUniqueNumber = @i_AccountUID

	IF (@CharacterNum >= 3)
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			-- RETURN	20			-- �ɸ��Ͱ� 3���� �ֱ� ������ ���� �Ұ�.
			SELECT 20;
			RETURN;
		END
	ELSE
		BEGIN
			UPDATE td_Character SET Race = Race ^ 0x4000 WHERE AccountUniqueNumber = @i_AccountUID AND UniqueNumber = @i_CharacterUID
		END

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- RETURN 0
	SELECT 0;
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_Job_DeleteCharacter
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Job_DeleteCharacter
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- TABLE NAME: atum_DeleteCharacterByJob
-- DESC      : 2007-02-22 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.Insert_atum_log_Live_Deleted_Character
	@i_LogType						TINYINT,
	@i_AccountUID					INT,
	@i_AccountName					VARCHAR(20),
	@i_CharacterUID					INT,
	@i_CharacterName				VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.atum_log_Live_Deleted_Character
	VALUES (@i_LogType, GetDate(), @i_AccountUID, @i_AccountName, @i_CharacterUID, @i_CharacterName)
GO



--------------------------------------------------------------------------------
-- TABLE NAME: atum_load_ti_MysteryItemDrop
-- DESC      : 2007-05-11 by cmkwon,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_MysteryItemDrop
	@i_ServerGroupID	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- 2008-12-01 by dhjin, ��Ű�ӽ� ����
	SELECT D.MysteryItemDropNum,D.ReqUnitKind,D.ReqMinLevel,D.ReqMaxLevel,D.DropItemNum
			,D.MinCount,D.MaxCount,D.Probability,D.PrefixProbability,D.SuffixProbability
			,D.Period,D.CountPerPeriod,C.DropCount,D.starttime		-- // 2008-11-04 by dhjin, ��Ű�ӽ�
	FROM atum2_db_account.dbo.ti_MysteryItemDrop AS D WITH(NOLOCK) LEFT JOIN 
			atum2_db_account.dbo.td_MysteryItemDropCount AS C WITH(NOLOCK)
			ON D.MysteryItemDropNum = C.MysteryItemDropNum AND C.ServerGroupID = @i_ServerGroupID AND D.DropItemNum = C.DropItemNum 
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadStrategyPointSummonRangeTimeInfo
-- DESC      : �����ؾ� �� ��������Ʈ ���� �ֱ� �ð� ������ ������ ���ν���.
-- 2007-03-29 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRangeTimeInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT StartTime, EndTime, SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily FROM dbo.td_StrategyPointSummonRangeTimeInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadStrategyPointSummonInfo
-- DESC      : �����ؾ� �� ��������Ʈ ������ ������ ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadAllStrategyPointSummonInfo
-- DESC      : �����ؾ� �� ��������Ʈ ���� ��ü �������� ���ν��� (SCAdminTool���� ���)
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadAllStrategyPointSummonInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT MapIndex, SummonCount, SummonTime, SummonAttribute FROM dbo.td_StrategyPointSummonInfo WITH (NOLOCK) ORDER BY SummonTime
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointSummonInfoByMapIndex
-- DESC      : �����ؾ� �� ��������Ʈ �� ������ ti_StrategyPointSummonMapIndex�� �����ϰ� �ϴ� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoByMapIndex
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE dbo.td_StrategyPointSummonInfo WHERE MapIndex NOT IN (SELECT MapIndex FROM atum2_db_account.dbo.ti_StrategyPointSummonMapIndex)
	INSERT INTO dbo.td_StrategyPointSummonInfo 
		SELECT MapIndex, 0, GetDATE(), NULL		-- // 2008-04-08 by dhjin, ��ȯ ���� �ð� ���� - 
		FROM atum2_db_account.dbo.ti_StrategyPointSummonMapIndex
		WHERE MapIndex NOT IN (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointSummonInfoBySummon
-- DESC      : ������ ��������Ʈ ���� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoBySummon
	@i_MapIndex			INT,
	@i_SummonCount		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = @i_SummonCount WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointSummonInfoBySummonTime
-- DESC      : ��������Ʈ ���� �ð� ���� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoBySummonTime
	@i_MapIndex			INT,
	@i_SummonTime		VARCHAR(30),
	@i_SummonAttribute	TINYINT		-- // 2008-04-08 by dhjin, ��ȯ ���� �ð� ���� - 
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonTime = @i_SummonTime, SummonAttribute = @i_SummonAttribute WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointSummonInfoByNewSummonRange
-- DESC      : ������ ��������Ʈ �ð� �� ���� ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonInfoByNewSummonRange
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = SummonCount + 1
	DECLARE @tmNewSTime	DATETIME
	SET @tmNewSTime = (SELECT EndTime FROM dbo.td_StrategyPointSummonRangeTimeInfo)
	DECLARE @tmSummonRange SMALLINT
	SET @tmSummonRange = (SELECT SummonRange FROM atum2_db_account.dbo.td_StrategyPointSummonRange)
	DECLARE @tmStrategyPointSummonCheck TINYINT
	SET @tmStrategyPointSummonCheck = (SELECT StrategyPointSummonCheck FROM atum2_db_account.dbo.td_StrategyPointSummonRange)
	DECLARE @tmMaxSummonCountDaily TINYINT
	SET @tmMaxSummonCountDaily = (SELECT MaxSummonCountDaily FROM atum2_db_account.dbo.td_StrategyPointSummonRange)
	UPDATE dbo.td_StrategyPointSummonRangeTimeInfo SET StartTime = @tmNewSTime, EndTime = DateAdd(day, @tmSummonRange, EndTime), 
	       SummonRange = @tmSummonRange, StrategyPointSummonCheck = @tmStrategyPointSummonCheck, MaxSummonCountDaily = @tmMaxSummonCountDaily
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadStrategyPointSummonMapIndex
-- DESC      : ��������Ʈ ���� �� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonMapIndex
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT MapIndex FROM atum2_db_account.dbo.ti_StrategyPointSummonMapIndex
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadStrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointSummonRange
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT SummonRange, StrategyPointSummonCheck, MaxSummonCountDaily
	FROM atum2_db_account.dbo.td_StrategyPointSummonRange
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ� ������Ʈ ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStrategyPointSummonRange
	@i_NewSummonRange					SMALLINT,
	@i_NewStrategyPointSummonCheck		TINYINT,
	@i_NewMaxSummonCountDaily			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF(0=@i_NewStrategyPointSummonCheck)
	BEGIN
		UPDATE atum2_db_account.dbo.td_StrategyPointSummonRange
		SET StrategyPointSummonCheck = @i_NewStrategyPointSummonCheck
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.td_StrategyPointSummonRange 
		SET SummonRange = @i_NewSummonRange, StrategyPointSummonCheck = @i_NewStrategyPointSummonCheck, 
			MaxSummonCountDaily = @i_NewMaxSummonCountDaily
	END
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_InitStrategyPointSummonRange
-- DESC      : ��������Ʈ ���� �ֱ� �� ���� �ʱ�ȭ ���ν���.
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InitStrategyPointSummonRange
	@i_SummonRange					SMALLINT,
	@i_StrategyPointSummonCheck		TINYINT,
	@i_MaxSummonCountDaily			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-07-09 by cmkwon, ���� AdminTool ���� ���� ���� �ذ� - �Ʒ��� ���� DELETE ������ ������.
	--TRUNCATE TABLE	dbo.td_StrategyPointSummonInfo
	--TRUNCATE TABLE	dbo.td_StrategyPointSummonRangeTimeInfo
	--TRUNCATE TABLE	atum2_db_account.dbo.td_StrategyPointSummonRange
	DELETE FROM	dbo.td_StrategyPointSummonInfo
	DELETE FROM dbo.td_StrategyPointSummonRangeTimeInfo
	DELETE FROM atum2_db_account.dbo.td_StrategyPointSummonRange

	INSERT INTO dbo.td_StrategyPointSummonInfo 
		SELECT MapIndex, 0, GetDATE(), NULL
		FROM atum2_db_account.dbo.ti_StrategyPointSummonMapIndex
		WHERE MapIndex NOT IN (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo)

	IF(0=@i_StrategyPointSummonCheck)
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_StrategyPointSummonRange
		VALUES(0, 0, 0)
	
		-- // 2008-01-09 by dhjin, DB �ԷµǴ� ��¥ ���� ����
		INSERT INTO dbo.td_StrategyPointSummonRangeTimeInfo
		VALUES('19000101 00:00:00', '19000101 00:00:00', 0, 0, 0)
	END
	ELSE
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_StrategyPointSummonRange
		VALUES(@i_SummonRange, 1, @i_MaxSummonCountDaily)
		
		UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = SummonCount + 1

		INSERT INTO dbo.td_StrategyPointSummonRangeTimeInfo
		VALUES(GetDATE(), DateAdd(day, @i_SummonRange, GetDATE()), @i_SummonRange, @i_StrategyPointSummonCheck, @i_MaxSummonCountDaily)
	END
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_LoadStrategyPointNotSummonTime
-- DESC      : ��������Ʈ �����Ǹ� �ȵǴ� �ð� �������� ���ν���
-- 2007-02-26 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadStrategyPointNotSummonTime
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT DayOfWeek, StartTime, EndTime, CheckSummon FROM atum2_db_account.dbo.td_StrategyPointNotSummonTime WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_UpdateStrategyPointNotSummonTime
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SSunday, EndTime = @i_ESunday, CheckSummon = @i_CheckSummonSunday			WHERE DayOfWeek = 0
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SMonday, EndTime = @i_EMonday, CheckSummon = @i_CheckSummonMonday			WHERE DayOfWeek = 1
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_STuesday, EndTime = @i_ETuesday, CheckSummon = @i_CheckSummonTuesday		WHERE DayOfWeek = 2
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SWednesday, EndTime = @i_EWednesday, CheckSummon = @i_CheckSummonWednesday	WHERE DayOfWeek = 3
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SThursday, EndTime = @i_EThursday, CheckSummon = @i_CheckSummonThursday	WHERE DayOfWeek = 4
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SFirday, EndTime = @i_EFirday, CheckSummon = @i_CheckSummonFirday			WHERE DayOfWeek = 5
	UPDATE atum2_db_account.dbo.td_StrategyPointNotSummonTime SET StartTime = @i_SSaturday, EndTime = @i_ESaturday, CheckSummon = @i_CheckSummonSaturday	WHERE DayOfWeek = 6
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Character
		SET WarPoint = @i_WP, CumulativeWarPoint = @i_CumulativeWP
		WHERE UniqueNumber = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadArenaInfo
-- DESC			 : �Ʒ��� ���� �ε�
-- 2007-04-17 by dhjin,
--> 2012-05-23 by jhseol, �Ʒ��� WP �⺻���޷� �ʵ� �߰�(DefaultPayWarPointWIN, DefaultPayWarPointLOSE)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadArenaInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ArenaMode, ReqMemberNum, PayInfluencePointWIN, PayInfluencePointLOSE, PayWarPointWIN, PayWarPointLOSE, DefaultPayWarPointWIN, DefaultPayWarPointLOSE
	FROM atum2_db_account.dbo.ti_ArenaInfo WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadArenaMapInfo
-- DESC			 : �Ʒ��� �� ���� �ε�
-- 2012-09-14 by jhseol, �Ʒ��� �߰����� part3 - �Ʒ��� ���� ������ �߰� (�Ʒ��� ���� ź�� ������ ī��)
-- 2007-04-17 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadArenaMapInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ArenaMapIndex, ArenaMode, ReqMemberNum, PlayLimitedTime, WINCondition, 
			LvDSupplyItemNum1, LvDSupplyItemCount1, LvDSupplyItemNum2, LvDSupplyItemCount2, LvDSupplyItemNum3, LvDSupplyItemCount3, LvDSupplyItemNum4, LvDSupplyItemCount4
	FROM atum2_db_account.dbo.ti_ArenaMapinfo WITH (NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SET	@o_RetCode		= 0			--									0	==> ���� ����

	SELECT TOP 1 @o_CharacterName= CharacterName, @o_PilotFace= PilotFace, @o_Level= Level
	FROM td_Character WITH(NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
    SELECT TutorialUID, TutorialPayItem1, TutorialPayItemCount1, TutorialPayItem2, TutorialPayItemCount2, TutorialPayItem3, TutorialPayItemCount3
	FROM atum2_db_account.dbo.ti_TutorialInfo
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadTutorialComplete
-- DESC			 : 
-- 2007-06-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTutorialComplete
    @i_CharacterUID          INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
    SELECT TutorialUID FROM dbo.td_TutorialComplete 
    WHERE CharacterUID = @i_CharacterUID
	ORDER BY TutorialUID DESC
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_InsertTutorialComplete
-- DESC			 : 
-- 2007-06-28 by dhjin,
--					// 2007-11-16 by cmkwon, ���̺� Unique Key ������ �� ������ �߰��� üũ �Ŀ� �߰� - td_TutorialComplete
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertTutorialComplete
    @i_CharacterUID          INT,
    @i_TutorialUID           INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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


-- !!!!
-- Name:dbo.atum_loadWarpableUserList
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - �ε� ���ν��� �߰�
-- ====
CREATE PROCEDURE dbo.atum_loadWarpableUserList
	@i_MapIndex				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.UniqueNumber, c.CharacterName
	FROM td_user_list_warpable_to_map ul WITH(NOLOCK), td_Character c WITH(NOLOCK)
	WHERE ul.MapIndex = @i_MapIndex AND ul.CharacterUID = c.UniqueNumber
GO

-- !!!!
-- Name:dbo.atum_getCharacterUIDByCharacterName
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - CharacterUID��������
-- ====
CREATE PROCEDURE dbo.atum_getCharacterUIDByCharacterName
	@i_CharacterName		VARCHAR(20),	
	@i_CharInflMask			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- #define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SELECT UniqueNumber
	FROM td_Character WITH(NOLOCK)
	WHERE CharacterName = @i_CharacterName AND 0 = Race & 0x4000 AND 0 <> InfluenceType & @i_CharInflMask
GO

-- !!!!
-- Name:dbo.atum_insert2WarpableUserList
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ���� �߰��ϱ�
--			#define ERR_NO_ERROR									0x0000
--			#define ERR_DB_INTEGRITY_CONSTRAINT_VIOLATION			0x2103		// integrity constraint violation, 23000
-- ====
CREATE PROCEDURE dbo.atum_insert2WarpableUserList
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--@i_RetErr				INT		OUTPUT,		-- 0�̸� No Error, �� �ܴ̿� ������
	@i_MapIndex				INT,
	@i_CharUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_user_list_warpable_to_map
	VALUES(@i_MapIndex, @i_CharUID)

	IF (@@Error <> 0)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @i_RetErr = 0x2103
		SELECT 0x2103;
	END
	ELSE
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @i_RetErr = 0
		SELECT 0;
	END

GO

-- !!!!
-- Name:dbo.atum_deleteAllWarpableUserList
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��� ���� �����ϱ�
-- ====
CREATE PROCEDURE dbo.atum_deleteAllWarpableUserList
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_user_list_warpable_to_map
GO

-- !!!!
-- Name:dbo.atum_deleteWarpableUser
-- Desc: // 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ���� �߰��ϱ�
-- ====
CREATE PROCEDURE dbo.atum_deleteWarpableUser
	@i_MapIndex				INT,
	@i_CharUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT OutPostWarStartTime
	FROM atum2_db_account.dbo.ti_OutPostNextWarTime WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_GetInfluenceLeaderGuildUID
-- DESC			 : ������ ���� UID��������
-- 2007-09-07 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetInfluenceLeaderGuildUID
	@i_LeaderUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildUniqueNumber FROM td_Character
	WHERE UniqueNumber = @i_LeaderUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_LoadCityLeaderInfo
-- DESC			 : ���� ���� ������ ���ν���
-- 2007-08-13 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadCityLeaderInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_CityLeaderInfo SET Notice = @i_Notice
	WHERE MapIndex = @i_MapIndex AND CharacterUID = @i_CharacterUID
GO


-- !!!!
-- Name:
-- Desc: // 2007-09-12 by cmkwon, ��Ʈ�� 2���н����� ���� - 2���н����� ������Ʈ ���ν���
-- ====
CREATE PROCEDURE dbo.atum_UpdateSecondaryPassword
	@i_AccUID						INT,
	@i_SecPassword					VARCHAR(35)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT Level, PollPoint
	FROM atum2_db_account.dbo.ti_ActionByLevel
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadPollDate
-- DESC				: ��ǥ ���� �Ⱓ, ��ǥ��, �����ϵ� �������� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadPollDate
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ApplicationStartDate, ApplicationEndDate, VoteStartDate, VoteEndDate, Election
	FROM atum2_db_account.dbo.td_PollDate
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_PollDate
	SET ApplicationStartDate = @i_ApplicationStartDate, ApplicationEndDate = @i_ApplicationEndDate
		, VoteStartDate = @i_VoteStartDate, VoteEndDate = @i_VoteEndDate, Election = @i_Election
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadVoterList
-- DESC				: ��ǥ�� ����Ʈ �������� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadVoterList
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_LeaderCandidate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertLeaderCandidate
-- DESC				: ������ �ĺ� ��� ���ν���
-- 2007-10-24 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertLeaderCandidate
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--@o_RetCode					INT OUTPUT,
	--@o_NewLeaderCandidateNum	INT OUTPUT,
	@i_ReqGuildMemberNum		INT,
	@i_ReqGuildFame				INT,
	@i_AccountUID				INT,
	@i_CharacterUID				INT,
	@i_CharacterName			VARCHAR(20),
	@i_GuildUID					INT,
	@i_GuildName				VARCHAR(30),
	@i_Influence				TINYINT,
	@i_CampaignPromises			VARCHAR(512)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckCount			INT
	DECLARE @ReqGuildMemberNum	INT
	DECLARE @GuildUID			INT
	DECLARE @NewLeaderCandidateNum	INT	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 

	SET @CheckCount = (SELECT Count(*) FROM dbo.td_Guild WITH (NOLOCK) 
						WHERE GuildUniqueNumber = @i_GuildUID AND GuildCommanderUniqueNumber = @i_CharacterUID AND MonthlyFame >= @i_ReqGuildFame)
	IF(@CheckCount <> 1)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 10		-- ������ �������� �ʰų� �䱸 ������ �۴�.
		--RETURN
		SELECT 10, 0;
		RETURN;
	END
	
	SET @ReqGuildMemberNum = (SELECT Count(*) FROM dbo.td_GuildMember WITH (NOLOCK) WHERE GuildUniqueNumber = @i_GuildUID)
	IF(@ReqGuildMemberNum < @i_ReqGuildMemberNum)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 20		-- ������ �������� �ʰų� �䱸 ���� ������ �۴�
		--RETURN
		SELECT 20, 0;
		RETURN;
	END

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--SET @o_NewLeaderCandidateNum = (SELECT TOP 1 LeaderCandidateNum FROM dbo.td_LeaderCandidate WITH (NOLOCK) 
	--									WHERE Influence = @i_Influence ORDER BY LeaderCandidateNum DESC)
	--SET @o_NewLeaderCandidateNum = @o_NewLeaderCandidateNum + 1
	--INSERT INTO dbo.td_LeaderCandidate (LeaderCandidateNum, AccountUID, CharacterUID, CharacterName, GuildUID, GuildName, Influence, DeleteCandidate, PollCount, CampaignPromises) 
	--VALUES (@o_NewLeaderCandidateNum, @i_AccountUID, @i_CharacterUID, @i_CharacterName, @i_GuildUID, @i_GuildName, @i_Influence, 0, 0, @i_CampaignPromises)
	--
	--SET @o_RetCode = 0
	SET @NewLeaderCandidateNum = (SELECT TOP 1 LeaderCandidateNum FROM dbo.td_LeaderCandidate WITH (NOLOCK) 
										WHERE Influence = @i_Influence ORDER BY LeaderCandidateNum DESC)
	IF(@NewLeaderCandidateNum IS NULL)
	BEGIN
		SET @NewLeaderCandidateNum = 0
	END
	SET @NewLeaderCandidateNum = @NewLeaderCandidateNum + 1
	INSERT INTO dbo.td_LeaderCandidate (LeaderCandidateNum, AccountUID, CharacterUID, CharacterName, GuildUID, GuildName, Influence, DeleteCandidate, PollCount, CampaignPromises) 
	VALUES (@NewLeaderCandidateNum, @i_AccountUID, @i_CharacterUID, @i_CharacterName, @i_GuildUID, @i_GuildName, @i_Influence, 0, 0, @i_CampaignPromises)

	SELECT 0, @NewLeaderCandidateNum;
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT C.Level, C.PilotFace, G.MonthlyFame, G.GuildMarkImage, G.GuildMarkSize
	FROM td_Character AS C WITH(NOLOCK) INNER JOIN td_Guild AS G WITH(NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account
	SET ConnectingServerGroupID = @i_ServerGroupID
	WHERE AccountUniqueNumber = @i_AccUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGiveTargetCharacter
-- DESC				: // 2007-11-13 by cmkwon, �����ϱ� ��� �߰� - ���� �޴� ĳ���� ���� ��������
--						// 2009-10-15 by cmkwon, �����ϱ� üũ�ÿ� ���̽� ��ü ������ üũ �߰� - �Ʒ��� ���� ���� ������ �ƴѰ�츸 �ش� ĳ���� ������ �Ѱ��ش�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGiveTargetCharacter
	@i_CharName				VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	--		#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	SELECT a.AccountName, a.AccountUniqueNumber, a.ConnectingServerGroupID, am.ItemNum, am.ExpireTime, c.UniqueNumber, c.InfluenceType, c.GuildName, c.UnitKind, c.Level
	FROM atum2_db_account.dbo.td_account a WITH(NOLOCK) INNER JOIN td_Character c WITH(NOLOCK) ON c.AccountUniqueNumber = a.AccountUniqueNumber
	LEFT OUTER JOIN atum2_db_account.dbo.td_accountcashstore am WITH(NOLOCK) ON a.AccountUniqueNumber = am.AccountUniqueNumber
	WHERE c.CharacterName = @i_CharName AND 0 = c.Race & 0x4000 AND NOT EXISTS(SELECT b.AccountName FROM atum2_db_account.dbo.td_BlockedAccounts b WITH(NOLOCK) INNER JOIN dbo.td_Character c ON c.AccountName = b.AccountName
																				WHERE c.CharacterName = @i_CharName AND 0 = c.Race & 0x4000 AND GETDATE() > b.StartDate AND GETDATE() < b.EndDate)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdatePilotFace
-- DESC				: // 2007-11-21 by cmkwon, PilotFace ���� ī�� ���� - �ش� ĳ������ PilotFace�� �����Ѵ�.
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdatePilotFace
	@i_CharUID		INT,
	@i_PilotFace	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Character
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_NotifyMsg(CharacterUID, NotifyMsgType, NotifyMsgString, SenderCharacterUID, SenderCharacterName)
	VALUES(@i_CharacterUID, @i_NotifyMsgType, @i_NotifyMsgString, @i_SenderCharacterUID, @i_SenderCharacterName)

	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();		-- // 2007-12-20 by cmkwon, �����ý��� ���� ���� - �߰��� NotifyMsgUID �� �����Ѵ�.
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END

	SELECT SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetNotifyMsg
-- DESC				: // 2007-11-28 by cmkwon, �����ý��� ���� - dbo.atum_GetNotifyMsg �߰�
--
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetNotifyMsg
	@i_CharacterUID				INT								-- ���� ���� CharacterUID
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CouponUID INT
	SET @CouponUID = (SELECT UniqueNumber FROM atum2_db_account.dbo.td_couponlist WITH(NOLOCK) WHERE CouponNumber = @i_CouponNumber AND UsedFlag = 0)
	IF @CouponUID IS NULL
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		-- RETURN 0x2710
		-- // 2008-10-08 by cmkwon, ���� ���� - ������ ��Ȯ�� ��, select �� ��� �ѱ涧 0x�� �ѱ�� �ڷ����� �ٸ��� ����.
		-- SELECT 0x2710;
		SELECT 10000;
		RETURN;
	END

	UPDATE atum2_db_account.dbo.td_couponlist
	SET UsedFlag = 1, UsedAccountName = @i_AccName, UsedTime = @i_UseTime
	WHERE UniqueNumber = @CouponUID
	
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- RETURN 0
	SELECT 0;
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_admin_DeleteDeletedCharacter
-- DESC      : // 2008-01-17 by cmkwon, T_A: ���� ������ ĳ���� ������ �����ϴ� ��� �߰� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_admin_DeleteDeletedCharacter
	@i_CharName			VARCHAR(20),
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- 2008-01-17 by cmkwon, �����Ⱦ��� ������ ĳ�������� üũ
	IF NOT EXISTS( SELECT * FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharacterUID AND 0 <> (Race & 0x4000) )
		BEGIN
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			--RETURN	10			-- ������ ������ ĳ���Ͱ� �ƴϴ�
			SELECT 10;
			RETURN;
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


	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- RETURN 0
	SELECT 0;
GO


--------------------------------------------------------------------------------
-- Name: dbo.atum_Delete_All_Character_By_AccountName
-- Desc: -- // 2008-02-13 by cmkwon, ���� ���� �ý��� ����� - atum2_db_[n].dbo.atum_Delete_All_Character_By_AccountName() ���ν��� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_All_Character_By_AccountName
	@i_AccountName VARCHAR(20)        -- AccountName
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS

	DECLARE @CharacterCnt INT
	SET @CharacterCnt = (SELECT Count(*) FROM dbo.td_Character WITH (NOLOCK) WHERE AccountName = @i_AccountName)
	IF (@CharacterCnt IS NULL)
	BEGIN
		RETURN		-- // 2008-02-13 by cmkwon, �ش� ������ ĳ���Ͱ� ����
	END

	DECLARE @CharUID INT
	DECLARE @CharName VARCHAR(20)
	SELECT TOP 1 @CharUID= UniqueNumber, @CharName= CharacterName FROM dbo.td_Character WITH(NOLOCK) 
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
		UPDATE dbo.td_Character
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

-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó�� - dbo.arena_updateCharacterInfo
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'

		--------------------------------------------------------------------------------
		-- PROCEDURE NAME	: dbo.arena_updateCharacterInfo
		-- DESC				: �Ʒ��� ���� - �ɸ��� ���� ������Ʈ
		-- 2007-12-28 by dhjin,
		--------------------------------------------------------------------------------
		CREATE PROCEDURE dbo.arena_updateCharacterInfo
			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			--@o_NewCharacterUID			INT OUTPUT,
			@i_NewCharacterName			VARCHAR(20),
			@i_CharacterUID				INT,
			@i_AccountUniqueNumber		INT			
		-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
		AS
			-- // 
			IF EXISTS(SELECT * FROM atum2_db_arena.dbo.td_Character WITH(NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber AND CharacterName = @i_NewCharacterName)
			BEGIN

				-- // ���� �����͸� ������Ʈ �Ѵ�.	
				-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - LevelUpTime �߰�, ����ġ �߰�
				UPDATE atum2_db_arena.dbo.td_Character
				SET	Race = sc.Race, UnitKind = sc.UnitKind, InfluenceType = sc.InfluenceType
					, PilotFace = sc.PilotFace, AttackPart = sc.AttackPart, DefensePart = sc.DefensePart, FuelPart = sc.FuelPart, SoulPart = sc.SoulPart
					, ShieldPart = sc.ShieldPart, DodgePart = sc.DodgePart, Level = sc.Level, Experience = sc.Experience, BodyCondition = sc.BodyCondition, Propensity = sc.Propensity
					, Status = sc.Status, PKWinPoint = sc.PKWinPoint, PKLossPoint = sc.PKLossPoint, HP = sc.HP, DP = sc.DP, SP = sc.SP, EP = sc.EP
					, BonusStat = sc.BonusStat, BonusStatPoint = sc.BonusStatPoint, LevelUpTime = sc.LevelUpTime, WarPoint = sc.WarPoint, CumulativeWarPoint = sc.CumulativeWarPoint
					, ArenaWin = sc.ArenaWin,	ArenaLose = sc.ArenaLose, ArenaDisConnect = sc.ArenaDisConnect
				FROM dbo.td_Character sc, atum2_db_arena.dbo.td_Character tc
				WHERE tc.AccountUniqueNumber = @i_AccountUniqueNumber AND tc.CharacterName = @i_NewCharacterName AND sc.UniqueNumber = @i_CharacterUID
			END
			ELSE
			BEGIN

				-- // atum2_db_arena.dbo.td_Character ���̺��� �ش� ĳ���͸����� ���� ó���Ѵ�. - ������ ĳ���͸��� ���� �� �� �ִ�. ������� �ʴ� �����̴�
				DELETE atum2_db_arena.dbo.td_Character
				WHERE CharacterName = @i_NewCharacterName

				-- // ������ �߰��Ѵ�.	
				-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - LevelUpTime �߰�, ����ġ �߰�
				INSERT INTO atum2_db_arena.dbo.td_Character (CharacterName, AccountName, AccountUniqueNumber, Race, UnitKind, InfluenceType, PilotFace
							, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level, Experience
							, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, HP, DP, SP, EP, BonusStat
							, BonusStatPoint, LevelUpTime, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect)
					SELECT @i_NewCharacterName, AccountName, AccountUniqueNumber, Race, UnitKind, InfluenceType, PilotFace
						, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level, Experience
						, BodyCondition, Propensity, Status, PKWinPoint, PKLossPoint, HP, DP, SP, EP
						, BonusStat, BonusStatPoint, LevelUpTime, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect
					FROM dbo.td_Character
					WHERE UniqueNumber = @i_CharacterUID
			END

			-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
			--SET @o_NewCharacterUID = (SELECT UniqueNumber FROM atum2_db_arena.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber AND CharacterName = @i_NewCharacterName)
			SELECT UniqueNumber FROM atum2_db_arena.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber AND CharacterName = @i_NewCharacterName;
'
END -- END - IF -- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó�� - dbo.arena_updateCharacterInfo
GO	


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_GetCharacter
-- DESC				: �Ʒ��� ���� - �ɸ��� ���� �ε�
-- 2007-12-28 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.arena_GetCharacter
	@acc	INT,
	@charac	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM atum2_db_arena.dbo.td_Character
	WITH (NOLOCK)
	WHERE UniqueNumber=@charac AND AccountUniqueNumber = @acc
GO

-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'

--> 130617_DB��Ű��_01_(�Ƹ��÷���)_DBQuery(atum2_db_[n] & atum2_db_arena)
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_CopyDBInfo
-- DESC				: �Ʒ��� ���� - �Ʒ��� DB�� ����Ÿ ����
-- 2008-01-07 by dhjin,
--						-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
--						-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--						-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--						-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
--						-- // 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - DB ���� ���� ���� ����
--						-- // 2012-06-20 by jhseol, �Ʒ��� �߰�����part2 : �Ʒ��� ���� �ɸ��ͷ� ī�� �߰�
--						-- // 2012-07-10 by jhseol, �Ʒ��� �÷��̽� �������� �Ƹ��� ������ �����ϵ��� ����
--						-- // 2012-08-06 by jhseol, ���ʿ��� ����ó���׸� ����
--						-- // 2012-10-29 by jhseol, ���ʿ��� ����Ʈ �� �ּ�ó��
--						-- // 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[arena_CopyDBInfo]
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--@o_RetCode					INT OUTPUT,
	@i_ArenaCharacterUID		INT,
	@i_CharacterUID				INT,
	@i_AccountUID				INT,
	@i_TypeSelectNUM			INT,
	@i_CharacterType			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--SET @o_RetCode = 0		--			0	==> ���� ����

	--DECLARE @traceID INT
	--INSERT INTO [_trace2] (ArenaCharacterUID, CharacterUID, AccountUID, TypeSelectNUM, CharacterType)
	--VALUES (@i_ArenaCharacterUID, @i_CharacterUID, @i_AccountUID, @i_TypeSelectNUM, @i_CharacterType)
	--SET @traceID = SCOPE_IDENTITY()

	--DECLARE @traceStart DATETIME
	--SET @traceStart = GETUTCDATE()

	--2013-05-16 Edison: Remove enchant info for all items owned by this user on Arena DB
	DELETE e
	FROM atum2_db_arena.dbo.td_Enchant AS e
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = e.TargetItemUniqueNumber
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 30		--			30	==> ��þƮ���� ���� ����
		SELECT 30;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 1)

	-- // 2011-10-17 by hskim ��Ʈ�� �ý��� 2�� - ���� ���� ���� (���� ��ġ ����)
	-- // 2010-06-15 by shcho&hslee ��ý��� - �� ���� Copy�߰�
	-- �� ������ ����
	--2013-05-16 Edison: Remove pet info for all items owned by this user on Arena DB
	DELETE p
	FROM atum2_db_arena.dbo.td_pet AS p
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = p.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 90				--			90	==> �� ������ ���� ����
		SELECT 90;
		RETURN              
	END
	
	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 2)

	-- // 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����
	DELETE ss
	FROM atum2_db_arena.dbo.td_ShapeStatLevel AS ss
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = ss.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SELECT 101;
		RETURN              
	END

	DELETE f
	FROM atum2_db_arena.dbo.td_FixedTerm AS f
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = f.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SELECT 102;
		RETURN              
	END
	-- // end 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����


	--2013-05-16 Edison: Remove all items owned by this user on Arena DB
	DELETE s
	FROM atum2_db_arena.dbo.td_Store AS s
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 40		--			40	==> ���������� ���� ����
		SELECT 40;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 3)

	--2013-05-16 Edison: Remove all skills owned by this user on Arena DB
	DELETE k
	FROM atum2_db_arena.dbo.td_StoreSkill AS k
	WHERE k.AccountUniqueNumber = @i_AccountUID
	AND k.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 70				--			70	==> ��ų ���� ����
		SELECT 70;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 4)

	--2013-05-16 Edison: Set template information if applicable. @TargetCharacterUID will be NULL if no such character exists or @i_TypeSelectNUM is out of range
	DECLARE @TargetCharacterUID INT
	DECLARE @TargetAccountUID INT
	SET @TargetCharacterUID = NULL
	SET @TargetAccountUID = NULL
	SELECT @TargetCharacterUID = UniqueNumber, @TargetAccountUID = AccountUniqueNumber
	FROM td_Character
	WITH (NOLOCK)
	WHERE @i_TypeSelectNUM BETWEEN 1 AND 12 -- inclusive; effectively merges this evaluation into @TargetCharacterUID variable
	AND CharacterName = @i_CharacterType
	
	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 5)

-- td_Character
	--2013-05-16 Edison: Clone td_Character
	UPDATE tc		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - LevelUpTime �߰�, ����ġ �߰�
	SET	Race = c.Race, UnitKind = sc.UnitKind, InfluenceType = c.InfluenceType
		, PilotFace = c.PilotFace, AttackPart = sc.AttackPart, DefensePart = sc.DefensePart, FuelPart = sc.FuelPart, SoulPart = sc.SoulPart
		, ShieldPart = sc.ShieldPart, DodgePart = sc.DodgePart, [Level] = sc.Level, Experience = sc.Experience, BodyCondition = sc.BodyCondition, Propensity = sc.Propensity
		, [Status] = sc.Status, PKWinPoint = c.PKWinPoint, PKLossPoint = c.PKLossPoint, HP = sc.HP, DP = sc.DP, SP = sc.SP, EP = sc.EP
		, BonusStat = sc.BonusStat, BonusStatPoint = sc.BonusStatPoint, LevelUpTime = c.LevelUpTime, WarPoint = c.WarPoint, CumulativeWarPoint = c.CumulativeWarPoint
		, ArenaWin = c.ArenaWin, ArenaLose = c.ArenaLose, ArenaDisConnect = c.ArenaDisConnect, RacingPoint = c.RacingPoint, SecretInfoOption = c.SecretInfoOption -- // 2010-12-22 by shcho, ���Ǵ�Ƽ ����ó�� - �κ�Ȯ�� ������� ����
	FROM atum2_db_arena.dbo.td_Character AS tc
	INNER JOIN td_Character AS c WITH (NOLOCK) ON c.UniqueNumber = @i_CharacterUID -- users original character
	INNER JOIN td_Character AS sc WITH (NOLOCK) ON sc.UniqueNumber = ISNULL(@TargetCharacterUID, @i_CharacterUID) -- users original character or template character with template character taking precedence
	WHERE tc.UniqueNumber = @i_ArenaCharacterUID
	AND tc.AccountUniqueNumber = @i_AccountUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 20		--			20	==> �Ʒ��� ������ �ɸ��� ���� ������Ʈ ����
		SELECT 20;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 6)

-- // end 2012-07-10 by jhseol, �Ʒ��� �÷��̽� �������� �Ƹ��� ������ �����ϵ��� ����

-- td_StoreSkill
	--2013-05-16 Edison: Clone td_StoreSkill
	INSERT atum2_db_arena.dbo.td_StoreSkill (AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime)
	SELECT @i_AccountUID, @i_ArenaCharacterUID, ItemWindowIndex, ItemNum, CreatedTime, NULL
	FROM td_StoreSkill
	WHERE AccountUniqueNumber = ISNULL(@TargetAccountUID, @i_AccountUID)
	AND Possess = ISNULL(@TargetCharacterUID, @i_CharacterUID)
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 80				--			80	==> ��ų �߰� ����
		SELECT 80;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 7)

-- td_Store
	-- â��� ĳ�����κ��� �����۰� ��æƮ(td_Store, td_Enchant)

	--2013-05-16 Edison: This VERY IMPORTANT table variable holds the relationship between main server ItemUID and arena server ItemUID.
	DECLARE @ItemMatching TABLE (MainItemUID BIGINT, ArenaItemUID BIGINT, PRIMARY KEY (MainItemUID))

	-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - �Ʒ��� ���� ����, 
	-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
	-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
	-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	--2013-05-16 Edison: Clone td_Store. Uses the OUTPUT keyword to gather the generated IDENTITY column in a set operation.
	INSERT atum2_db_arena.dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID, CoolingTime)
	OUTPUT INSERTED.MainSvrItemUID, INSERTED.UniqueNumber
	INTO @ItemMatching
	SELECT @i_AccountUID, @i_ArenaCharacterUID, ItemStorage, Wear, CurrentCount, ItemWindowIndex
			, i.ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime
			,	CASE --	if the user is using a contour, copy the contour shape
				WHEN @TargetCharacterUID IS NOT NULL AND s.ItemStorage = 0 AND s.Wear = 1 AND s.ItemWindowIndex = 5
				THEN 
				(
					SELECT CASE WHEN s.ShapeItemNum > 0 THEN s.ShapeItemNum ELSE i.SourceIndex END
					FROM td_Store AS s WITH (NOLOCK)
					INNER JOIN atum2_db_account.dbo.ti_Item AS i WITH (NOLOCK) ON i.ItemNum = s.ItemNum
					WHERE s.AccountUniqueNumber = @i_AccountUID
					AND s.Possess = @i_CharacterUID
					AND s.ItemStorage = 0
					AND s.Wear = 1
					AND s.ItemWindowIndex = 5
				)
				ELSE
					ShapeItemNum
				END 
			, UniqueNumber, CoolingTime
	FROM td_Store AS s WITH(NOLOCK)
	INNER JOIN atum2_db_account.dbo.ti_Item AS i WITH (NOLOCK) ON i.ItemNum = s.ItemNum AND 0 = i.ItemAttribute & 0x8000
	WHERE AccountUniqueNumber = ISNULL(@TargetAccountUID, @i_AccountUID)
	AND Possess = ISNULL(@TargetCharacterUID, @i_CharacterUID)
	AND ItemStorage = 0
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 60			--			60	==> ������ �߰� ����
		SELECT 60;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 8)

	-- ��æƮ�� �����ϴ� �������� Ÿ�� �������� ��æƮ �߰�
	--2013-05-16 Edison: Clone td_Enchant. Again uses @ItemMatching to convert Main to Arena as a set operation.
	INSERT INTO atum2_db_arena.dbo.td_Enchant (TargetItemUniqueNumber, TargetItemNum, EnchantItemNum)
	SELECT m.ArenaItemUID, e.TargetItemNum, e.EnchantItemNum
	FROM td_Enchant AS e WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = e.TargetItemUniqueNumber
	IF (@@ERROR <> 0)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 61		--			61	==> ��þƮ �߰� ����
		SELECT 61;
		RETURN              
	END

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 9)

	-- // 2010-06-15 by shcho&hslee ��ý��� - �� ���� Copy�߰�
	-- �� ������ �ִٸ� �Ʒ������� td_pet�� �ִ´�.
	--2013-05-16 Edison: Clone td_pet. Again uses @ItemMatching to convert Main to Arena as a set operation.
	INSERT INTO atum2_db_arena.dbo.td_pet(ItemUID,PetIndex,Experience,[Level],[Name],ExpRatio,EnableSocketCount,SocketItem1,SocketItem2,SocketItem3,SocketItem4,SocketItem5,SocketItem6,HPKitItemNum,HPKitTriggerValue,ShieldKitItemNum,ShieldKitTriggerValue,SPKitItemNum,SPKitTriggerValue,AutoSkilItemNum1,AutoSkilItemNum2,AutoSkilItemNum3,AutoSkilItemNum4,AutoSkilItemNum5,AutoSkilItemNum6)
	SELECT m.ArenaItemUID,PetIndex,Experience,[Level],[Name],ExpRatio,EnableSocketCount
			,ISNULL(m1.ArenaItemUID,0),ISNULL(m2.ArenaItemUID,0),ISNULL(m3.ArenaItemUID,0),ISNULL(m4.ArenaItemUID,0),ISNULL(m5.ArenaItemUID,0),ISNULL(m6.ArenaItemUID,0)
			,HPKitItemNum,HPKitTriggerValue,ShieldKitItemNum,ShieldKitTriggerValue,SPKitItemNum,SPKitTriggerValue,AutoSkilItemNum1,AutoSkilItemNum2,AutoSkilItemNum3,AutoSkilItemNum4,AutoSkilItemNum5,AutoSkilItemNum6
	FROM td_Pet WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = ItemUID
	LEFT JOIN @ItemMatching AS m1 ON m1.MainItemUID = SocketItem1
	LEFT JOIN @ItemMatching AS m2 ON m2.MainItemUID = SocketItem2
	LEFT JOIN @ItemMatching AS m3 ON m3.MainItemUID = SocketItem3
	LEFT JOIN @ItemMatching AS m4 ON m4.MainItemUID = SocketItem4
	LEFT JOIN @ItemMatching AS m5 ON m5.MainItemUID = SocketItem5
	LEFT JOIN @ItemMatching AS m6 ON m6.MainItemUID = SocketItem6
	IF (@@ERROR <> 0)
	BEGIN
		-- // 2010-06-15 by shcho&hslee ��ý��� - ���Ǵ�Ƽ ����� �� ���� �߰�
		--SET @o_RetCode = 91		--			91	==> �� ���� �߰� ����
		SELECT 91;
		RETURN              
	END			
	-- // end 2011-09-20 by hskim, ��Ʈ�� �ý��� 2��

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 10)

	-- // 2012-06-12 by jhseol, �Ʒ��� �߰�����part2 - ������ : ������ ����
	--2013-05-16 Edison: Remove all skill bars owned by this user on Arena DB
	DELETE FROM atum2_db_arena.dbo.td_QuickSlot
	WHERE AccountUID = @i_AccountUID
	AND CharacterUID = @i_ArenaCharacterUID

	--2013-05-16 Edison: Clone td_QuickSlot.
	INSERT INTO atum2_db_arena.dbo.td_QuickSlot
						([AccountUID],[CharacterUID],[TabIdx]
						,[ItemNum_1],[ItemNum_2],[ItemNum_3],[ItemNum_4],[ItemNum_5],[ItemNum_6],[ItemNum_7],[ItemNum_8],[ItemNum_9],[ItemNum_10]
						,SlotPurpose)
	SELECT AccountUID,@i_ArenaCharacterUID,[TabIdx]
					,[ItemNum_1],[ItemNum_2],[ItemNum_3],[ItemNum_4],[ItemNum_5],[ItemNum_6],[ItemNum_7],[ItemNum_8],[ItemNum_9],[ItemNum_10]
					,SlotPurpose
	FROM td_QuickSlot WITH (NOLOCK)
	WHERE AccountUID = @i_AccountUID
	AND CharacterUID = @i_CharacterUID
	AND TabIdx BETWEEN 0 AND 2 -- inclusive
	AND SlotPurpose BETWEEN 0 AND 1 -- inclusive
	-- // end 2012-06-12 by jhseol, �Ʒ��� �߰�����part2 - ������ : ������ ����

	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 11)

	SELECT 0;	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	
	--INSERT INTO [_traceDetail2] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 0)
' 
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.atum_log_MSWar
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_log_InitSPWar
-- DESC				: ������ ����Ʈ �ʱ�ȭ ���ν���
-- // 2008-04-01 by dhjin, ����, ������ ����â ��ȹ�� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_log_InitSPWar
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ServerGroupName, LimitUserCount, LockCreateCharacterForNewAccount
	FROM atum2_db_account.dbo.td_serverGroup WITH(NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF EXISTS(SELECT * FROM atum2_db_account.dbo.td_serverGroup WITH(NOLOCK) WHERE ServerGroupID = @i_ServGroupID)
	BEGIN
		UPDATE atum2_db_account.dbo.td_serverGroup
		SET ServerGroupName= @i_ServGroupName, LimitUserCount= @i_LimitUserCount, LockCreateCharacterForNewAccount= @i_LockCreateCharacterForNewAccount	
		WHERE ServerGroupID = @i_ServGroupID
	END
	ELSE
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_serverGroup(ServerGroupID, ServerGroupName, LimitUserCount, LockCreateCharacterForNewAccount)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(*) 
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE AccountName = @i_AccName
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_Delete_Letter_By_LetterPassedRangeDay
-- DESC		 : ���� �Ⱓ ���� ���� �����ϱ�
-- // 2008-05-13 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_Letter_By_LetterPassedRangeDay
	@i_RecvCharacterUID		INT,
	@i_LetterPassedRangeDay	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_Letter WHERE RecvCharacterUID = @i_RecvCharacterUID AND (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay)
	DELETE FROM dbo.td_ReadAllLetter WHERE AllLetterUID IN (SELECT AllLetterUID FROM  dbo.td_AllLetter WITH (NOLOCK) WHERE (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay) )
	DELETE FROM dbo.td_AllLetter WHERE (DATEDIFF(dd, SendDate, GETDATE()) > @i_LetterPassedRangeDay)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Get_Letter
-- DESC		 : ���� ��������
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_Letter
	@i_RecvCharacterUID		INT,
	@i_LetterPassedRangeDay	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT LetterUID, SendCharacterName, SendDate, CheckRead, Title, Content FROM dbo.td_Letter WITH (NOLOCK) WHERE RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Send_Letter
-- DESC		 : ���� ������
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--				-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - Result Set ==> ErrorCode, RecvCharacterUID, LetterUID
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Send_Letter
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- @o_Err					TINYINT	OUTPUT,
	-- @o_RecvCharacterUID		INT	OUTPUT,
	@i_RecvCharacterName	VARCHAR(20),
	@i_SendCharacterUID		INT,
	@i_SendCharacterName	VARCHAR(20),
	@i_SendDate				VARCHAR(30),
	@i_Title				VARCHAR(40),
	@i_Content				VARCHAR(1000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckCount		INT
	SET @CheckCount = 0
	
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	-- SET @o_Err = 0
	-- SET @o_RecvCharacterUID = 0
	--
	-- -- �����ϴ� �������� üũ�Ѵ�.
	-- SET @o_RecvCharacterUID = ( SELECT UniqueNumber FROM dbo.td_Character WITH (NOLOCK) WHERE CharacterName = @i_RecvCharacterName )
	-- IF(@o_RecvCharacterUID IS NULL)
	-- BEGIN
	-- 	SET @o_Err = 1		-- 1 ������ �������� �ʴ´�.
	-- 	RETURN
	-- END

	DECLARE @tmRecvCharacterUID INT
	-- �����ϴ� �������� üũ�Ѵ�.
	SET @tmRecvCharacterUID = (SELECT UniqueNumber FROM dbo.td_Character WITH (NOLOCK) WHERE CharacterName = @i_RecvCharacterName )
	IF(@tmRecvCharacterUID IS NULL)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_Err = 1		-- 1 ������ �������� �ʴ´�.
		SELECT 1, 0, 0;
		RETURN
	END

	-- ���� �������� üũ.
	DECLARE @SendCharacterInfl TINYINT
	DECLARE @RecvCharacterInfl TINYINT
	SET @SendCharacterInfl = 0
	SET @RecvCharacterInfl = 0
	SET @SendCharacterInfl = ( SELECT InfluenceType FROM dbo.td_Character WITH (NOLOCK) WHERE UniqueNumber = @i_SendCharacterUID )
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--SET @RecvCharacterInfl = ( SELECT InfluenceType FROM dbo.td_Character WITH (NOLOCK) WHERE UniqueNumber = @o_RecvCharacterUID )
	SET @RecvCharacterInfl = ( SELECT InfluenceType FROM dbo.td_Character WITH (NOLOCK) WHERE UniqueNumber = @tmRecvCharacterUID )
	IF(@SendCharacterInfl <> @RecvCharacterInfl)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_Err = 4		-- 4 ���� ������ �ƴϴ�.
		SELECT 4, 0, 0;
		RETURN
	END	
	
	-- �ڽ� �ź� üũ
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_RecvCharacterName AND FriendName = @i_SendCharacterName  AND Type = 1)
	IF(0 <> @CheckCount)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_Err = 2		-- 2 �ź� ��Ͽ� �ִ� �����̴�.
		SELECT 2, 0, 0;
		RETURN
	END	

	-- ���� �ź� üũ
	SET @CheckCount = (SELECT Count(*) FROM dbo.td_FriendList WITH (NOLOCK) 
						WHERE CharacterName = @i_SendCharacterName AND FriendName = @i_RecvCharacterName  AND Type = 1)
	IF(0 <> @CheckCount)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_Err = 3		-- 3 ������ ���� �ź��� �����̴�.
		SELECT 3, 0, 0;
		RETURN
	END	

	-- ���� �߰�
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--INSERT INTO dbo.td_Letter (RecvCharacterUID, SendCharacterName, SendDate, CheckRead, Title, Content)
	--	VALUES (@o_RecvCharacterUID, @i_SendCharacterName, @i_SendDate, 0, @i_Title, @i_Content)
	INSERT INTO dbo.td_Letter (RecvCharacterUID, SendCharacterName, SendDate, CheckRead, Title, Content)
		VALUES (@tmRecvCharacterUID, @i_SendCharacterName, @i_SendDate, 0, @i_Title, @i_Content)

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	SELECT 0, @tmRecvCharacterUID, SCOPE_IDENTITY();	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_Read_Letter
-- DESC		 : ���� �б�
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Read_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Letter SET CheckRead = 1 WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Delete_Letter
-- DESC		 : ���� ����
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_Letter
	@i_LetterUID			BIGINT,
	@i_RecvCharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_Letter WHERE LetterUID = @i_LetterUID AND RecvCharacterUID = @i_RecvCharacterUID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: atum_Get_AllLetter
-- DESC		 : ��ü ���� ��������
-- // 2008-05-09 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Get_AllLetter
	@i_RecvCharacterUID		INT,
	@i_RecvCharacterInfl	TINYINT,
	@i_LetterPassedRangeDay	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- TABLE NAME: atum_Send_AllLetter_ByLeader
-- DESC		 : �����ο��� ���� �߼����� ���� ���� �߰�
-- // 2008-04-14 by dhjin, EP3 �����ý��� - 
--				-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - Result Set ==> ErrorCode
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Send_AllLetter_ByLeader
	@i_SendCharacterInfl	TINYINT,
	@i_SendCharacterUID		INT,
	@i_SendCharacterName	VARCHAR(20),
	@i_SendDate				DATETIME,
	@i_Title				VARCHAR(40),
	@i_Content				VARCHAR(1000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- ���� �߰�
	INSERT INTO dbo.td_AllLetter (SendCharacterInfl, SendCharacterUID, SendCharacterName, SendDate, Title, Content)
		VALUES (@i_SendCharacterInfl, @i_SendCharacterUID, @i_SendCharacterName, @i_SendDate, @i_Title, @i_Content)

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN SCOPE_IDENTITY();
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END

	SELECT SCOPE_IDENTITY();	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Insert_ReadAllLetter_ByRead
-- DESC		 : �����ο��� ���� �߼� ����
-- // 2008-05-08 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_ReadAllLetter_ByRead
	@i_AllLetterUID			BIGINT,
	@i_RecvCharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_ReadAllLetter (AllLetterUID, RecvCharacterUID, CheckDelete)
		VALUES (@i_AllLetterUID, @i_RecvCharacterUID, 0)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: atum_Delete_ReadAllLetter
-- DESC		 : �����ο��� ���� �߼� ����
-- // 2008-05-08 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_ReadAllLetter
	@i_AllLetterUID			BIGINT,
	@i_RecvCharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- TABLE NAME: atum_Delete_AllLetter
-- DESC		 : ��ü ���� ����
-- // 2008-05-09 by dhjin, EP3 �����ý��� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_AllLetter
	@i_AllLetterUID			BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_ReadAllLetter WHERE AllLetterUID = @i_AllLetterUID
	DELETE FROM dbo.td_AllLetter WHERE AllLetterUID = @i_AllLetterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetGuildRank
-- DESC				: ���� ��ũ ��������
-- // 2008-05-30 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetGuildRank
	@i_GuildUID			INT,	-- UINT
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildRank
	FROM td_GuildMember
	WHERE CharacterUniqueNumber = @i_CharacterUID AND GuildUniqueNumber = @i_GuildUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildCommander
-- DESC				: ������ ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--						-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - Result Set ==> ErrorCode
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildCommander
	@GuildUniqueNum INT,
	@Commander		INT,
	@NewCommander	INT,
	@LevelCheck     INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckBit	 TINYINT
	SET @CheckBit = (SELECT count(*) FROM dbo.td_CityLeaderInfo WITH (NOLOCK) WHERE CharacterUID = @Commander)
	IF(0 <> @CheckBit)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 1
		SELECT 1;
		RETURN;
	END
	SET @CheckBit = (SELECT count(*) FROM dbo.td_LeaderCandidate WITH (NOLOCK) WHERE CharacterUID = @Commander)
	IF(0 <> @CheckBit)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 2
		SELECT 2;
		RETURN;
	END
	SET @CheckBit = (SELECT count(*) FROM dbo.td_Character WITH (NOLOCK) WHERE UniqueNumber = @NewCommander and Level >= @LevelCheck )
	IF(0 = @CheckBit)
	BEGIN
		SELECT 3;	-- // 2008-10-13 by dhjin, ������ ���� ���� ���� üũ �߰�.
		RETURN;
	END

	UPDATE dbo.td_Guild SET GuildCommanderUniqueNumber = @NewCommander WHERE GuildUniqueNumber = @GuildUniqueNum
	UPDATE dbo.td_GuildMember SET GuildRank = 0	WHERE CharacterUniqueNumber = @Commander
	UPDATE dbo.td_GuildMember SET GuildRank = 1	WHERE CharacterUniqueNumber = @NewCommander

	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	SELECT 0;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateGuildNotice
-- DESC				: ���� ����
-- // 2008-05-20 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateGuildNotice
	@GuildUniqueNum INT,
	@Notice			VARCHAR(512)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT G.GuildUniqueNumber, G.GuildName, GI.WriteDate, GI.Content, C.CharacterName
	FROM dbo.td_Guild AS G WITH (NOLOCK) INNER JOIN dbo.td_GuildIntroduction AS GI WITH (NOLOCK)
			ON G.GuildUniqueNumber = GI.GuildUID 
		INNER JOIN dbo.td_Character AS C WITH (NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT S.CharacterUID, C.CharacterName, C.UnitKind, C.Level
	FROM dbo.td_SelfIntroduction AS S WITH (NOLOCK) INNER JOIN dbo.td_Character AS C WITH (NOLOCK)
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_SelfIntroduction WHERE CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateSelfIntroduction
-- DESC				: �ڱ� �Ұ��� ������Ʈ
-- // 2008-05-26 by dhjin, EP3 - ���� ���� ����
--						-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - Result Set ==> ErrorFlag
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateSelfIntroduction
	@i_TargetGuildUID				INT,
	@i_CharacterUID					INT,
	@i_Content						VARCHAR(512)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckBit	 TINYINT
	SET @CheckBit = (SELECT count(*) FROM dbo.td_SelfIntroduction WITH (NOLOCK) WHERE CharacterUID = @i_CharacterUID)
	IF(0 = @CheckBit)
	BEGIN
		INSERT INTO dbo.td_SelfIntroduction (GuildUID, CharacterUID, Content)
			VALUES (@i_TargetGuildUID, @i_CharacterUID, @i_Content)	
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 1;	
		SELECT 1;
		RETURN;
	END
	ELSE IF(2 <= @CheckBit)
	BEGIN
		-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
		--RETURN 0;
		SELECT 0;
		RETURN;
	END

	UPDATE dbo.td_SelfIntroduction SET Content = @i_Content WHERE GuildUID = @i_TargetGuildUID AND CharacterUID = @i_CharacterUID
	-- // 2008-08-22 by cmkwon, MySQL ���� �ҽ� ���� - 
	--RETURN 1;
	SELECT 1;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Guild_Update_TotalFameRankByJob
-- DESC				: �� ���� �� ����
-- JOB				: ���� ��ħ�ð����� JOB�� �Ǵ�.
-- // 2008-06-05 by dhjin, EP3 - ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Guild_Update_TotalFameRankByJob
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
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
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT A.ExpireTime
		FROM td_Character AS C WITH (NOLOCK) INNER JOIN atum2_db_account.dbo.td_accountcashstore AS A
			ON C.AccountUniqueNumber = A.AccountUniquenumber
		WHERE C.UniqueNumber = @GuildMasterUID	
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetUserInfo
-- DESC				: ���� ���� ��������
-- // 2008-06-20 by dhjin, EP3 ���������ɼ� -
--						// 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetUserInfo
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �� �����´�.
	SELECT PilotFace, CharacterName, UnitKind, GuildName, GuildUniqueNumber, Level, MapIndex, ChannelIndex, Propensity, LastStartedTime, SecretInfoOption, NickName
	FROM dbo.td_Character
	WHERE UniqueNumber = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0001
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0001
	@i_AccName			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountName, Password, AccountType, Sex, BirthYear, RegisteredDate, LastLoginDate,
			IsBlocked, ChattingBlocked, SecondaryPassword
	FROM atum2_db_account.dbo.td_account WITH (NOLOCK)
	where accountname = @i_AccName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0002
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0002
	@i_AccName			VARCHAR(20),
	@i_AccType			SMALLINT,
	@i_Password			VARCHAR(33),
	@i_SecPassword		VARCHAR(33)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account 
	SET AccountType = @i_AccType, Password = @i_Password, SecondaryPassword = @i_SecPassword
	WHERE AccountName = @i_AccName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0003
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0003
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountName, BlockedType, StartDate,	EndDate, AdminAccountName, BlockedReason, BlockedReasonForOnlyAdmin
	FROM atum2_db_account.dbo.td_blockedaccounts	WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0004
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0004
	@i_InflTy				TINYINT,
	@i_InflLeaderCharacUID	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_InfluenceWarData 
	SET InflLeaderCharacterUID = @i_InflLeaderCharacUID
	WHERE InfluenceType = @i_InflTy;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0005
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0005
	@i_InflTy					TINYINT,
	@i_InflSub1LeaderCharacUID	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_InfluenceWarData 
	SET InflSub1LeaderCharacterUID = @i_InflSub1LeaderCharacUID 
	WHERE InfluenceType = @i_InflTy;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0006
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0006
	@i_InflTy					TINYINT,
	@i_InflSub2LeaderCharacUID	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_InfluenceWarData
	SET InflSub2LeaderCharacterUID = @i_InflSub2LeaderCharacUID
	WHERE InfluenceType = @i_InflTy;
GO

--> 130605_DB��Ű��_03_(��������Ʈ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0007
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--				: -- // 2013-05-09 by hskim, ���� ����Ʈ ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_PROCEDURE_080827_0007]
--WITH EXECUTE AS 'proexe'	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT wd.InfluenceType, wd.MGameServerID, wd.WartimeStage, wd.ContributionPoint, wd.InflLeaderCharacterUID, c.CharacterName, wd.InflSub1LeaderCharacterUID, c1.CharacterName, wd.InflSub2LeaderCharacterUID, c2.CharacterName, wd.ConsecutiveVictories
	FROM td_influencewardata wd  LEFT OUTER JOIN td_character c ON wd.InflLeaderCharacterUID = c.uniquenumber
		LEFT OUTER JOIN td_character c1	ON wd.InflSub1LeaderCharacterUID = c1.uniquenumber 
			LEFT OUTER JOIN td_character c2 ON wd.InflSub2LeaderCharacterUID = c2.uniquenumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0008
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0008
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_InfluenceWarData
	SET WartimeStage = 0, ContributionPoint = 0, InflLeaderCharacterUID = 0, OwnerOfConflictArea = 0, InflSub1LeaderCharacterUID = 0, InflSub2LeaderCharacterUID = 0, MSWarOptionType = 510;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0009
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0009
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
	SET MonthlyFame = 0;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0010
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0010
	@i_LogTableName		VARCHAR(128),
	@i_Query			VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @SearchedIdx INT;

	SET @SearchedIdx = PATINDEX('%'+@i_LogTableName+'%', @i_Query);
	IF (0 >= @SearchedIdx)
	BEGIN
		RETURN;
	END

	exec (@i_Query);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0014
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0014
	@i_AccUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, ItemNum, CreatedTime,	UpdatedTime, ExpireTime
	FROM atum2_db_account.dbo.td_accountcashstore WITH (NOLOCK)
	WHERE AccountUniqueNumber = @i_AccUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0015
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0015
	@i_AccUID			INT,
	@i_ItemNum			INT,
	@i_CreatedTime		VARCHAR(30),
	@i_UpdatedTime		VARCHAR(30),
	@i_ExpireTime		VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.td_accountcashstore(AccountUniqueNumber,ItemNum,CreatedTime,UpdatedTime,ExpireTime)
	VALUES (@i_AccUID, @i_ItemNum, @i_CreatedTime, @i_UpdatedTime, @i_ExpireTime);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0017
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0017
	@i_GuildName		VARCHAR(30),
	@i_GuildUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (@i_GuildName <> '')
	BEGIN
		SELECT GuildUniqueNumber, GuildName, GuildCommanderUniqueNumber, GuildMemberCapacity, GuildState, GuildDismemberDate, GuildMarkVersion, GuildMarkSize, WarWinPoint, WarLossPoint, TotalFame, MonthlyFame, GuildMarkImage, GuildMarkState, GuildMemberCardCashPrice
		FROM td_Guild WITH (NOLOCK)
		WHERE GuildName = @i_GuildName;
	END
	ELSE
	BEGIN
		SELECT GuildUniqueNumber, GuildName, GuildCommanderUniqueNumber, GuildMemberCapacity, GuildState, GuildDismemberDate, GuildMarkVersion, GuildMarkSize, WarWinPoint, WarLossPoint, TotalFame, MonthlyFame, GuildMarkImage, GuildMarkState, GuildMemberCardCashPrice
		FROM td_Guild WITH (NOLOCK)
		WHERE GuildUniqueNumber = @i_GuildUID;
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0019
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0019
	@i_GuildUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.AccountName, c.CharacterName, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, c.propensity, c.PKWinPoint, c.PKLossPoint, gm.GuildRank
	FROM td_Character c, td_GuildMember gm WITH (NOLOCK)
	WHERE gm.GuildUniqueNumber = @i_GuildUID and c.uniqueNumber = gm.CharacterUniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0020
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - ShapeItemNum �ʵ� �߰�, ��� �ʵ� 1�� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0020
	@i_GuildUID			INT,
	@i_ItemStorage		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT s.UniqueNumber, s.ItemNum, s.PrefixCodeNum, s.SuffixCodeNum, s.ItemStorage, s.Wear, s.ItemWindowIndex, s.CurrentCount, s.ColorCode, s.possess, s.CreatedTime, s.ShapeItemNum
	FROM td_Store s WITH (NOLOCK)
	WHERE s.Possess = @i_GuildUID AND s.ItemStorage = @i_ItemStorage;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0021
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0021
	@i_ItemUID			BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(*)
	FROM td_Enchant WITH (NOLOCK)
	where TargetItemUniqueNumber = @i_ItemUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0022
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0022
	@i_GuildName			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildUniqueNumber
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildName = @i_GuildName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0023
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0023
	@i_GuildUID				INT,
	@i_GuildName			VARCHAR(30),
	@i_GuildMarkState		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
	SET GuildName = @i_GuildName, GuildMarkState= @i_GuildMarkState
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0024
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0024
	@i_GuildUID				INT,
	@i_GuildName			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character
	SET GuildName = @i_GuildName
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0025
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0025
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
	SELECT uniquenumber, ServerGroupID, dayofweek, starttime, endtime, exprate, SPIRate, exprepairrate, DropItemRate, DropRareItemRate, WarPointRate, InfluenceType, MinLevel, MaxLevel
	FROM atum2_db_account.dbo.ti_HappyHourEvent WITH (NOLOCK)
	ORDER BY ServerGroupID, InfluenceType, dayofweek;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0026
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0026
	@i_ServerGroupID		INT,
	@i_DayOfWeek			INT,
	@i_StartTime			VARCHAR(30),
	@i_EndTime				VARCHAR(30),
	@i_EXPRate				FLOAT,
	@i_SPIRate				FLOAT,
	@i_EXPRepaireRate		FLOAT,
	@i_DropItemRate			FLOAT,
	@i_DropRareItemRate		FLOAT,
	@i_WarPointRate			FLOAT,
	@i_InflType				TINYINT,
	@i_MinLevel				INT,
	@i_MaxLevel				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
	INSERT atum2_db_account.dbo.ti_HappyHourEvent(ServerGroupID, dayofweek, starttime, endtime, exprate, SPIRate, exprepairrate, DropItemRate, DropRareItemRate, WarPointRate, InfluenceType, MinLevel, MaxLevel)
	VALUES( @i_ServerGroupID, @i_DayOfWeek, @i_StartTime, @i_EndTime, @i_EXPRate, @i_SPIRate, @i_EXPRepaireRate, @i_DropItemRate, @i_DropRareItemRate, @i_WarPointRate, @i_InflType, @i_MinLevel, @i_MaxLevel);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0027
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0027
	@i_ServerGroupID		INT,
	@i_DayOfWeek			INT,
	@i_StartTime			VARCHAR(30),
	@i_EndTime				VARCHAR(30),
	@i_EXPRate				FLOAT,
	@i_SPIRate				FLOAT,
	@i_EXPRepaireRate		FLOAT,
	@i_DropItemRate			FLOAT,
	@i_DropRareItemRate		FLOAT,
	@i_WarPointRate			FLOAT,
	@i_InflType				TINYINT,
	@i_MinLevel				INT,
	@i_MaxLevel				INT,
	@i_EventUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
	UPDATE atum2_db_account.dbo.ti_HappyHourEvent
	SET ServerGroupID= @i_ServerGroupID, dayofweek= @i_DayOfWeek, starttime = @i_StartTime, endtime = @i_EndTime, exprate = @i_EXPRate, SPIRate = @i_SPIRate, exprepairrate = @i_EXPRepaireRate, DropItemRate = @i_DropItemRate, DropRareItemRate = @i_DropRareItemRate , WarPointRate = @i_WarPointRate, InfluenceType = @i_InflType, MinLevel = @i_MinLevel, MaxLevel = @i_MaxLevel
	WHERE uniquenumber= @i_EventUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0028
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0028
	@i_DayOfWeek			INT,
	@i_InflType				TINYINT,
	@i_StartTime			VARCHAR(30),
	@i_EndTime				VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @EvUID INT
	SET @EvUID = (SELECT UniqueNumber
					FROM atum2_db_account.dbo.ti_HappyHourEvent WITH(NOLOCK)
					WHERE InfluenceType = @i_InflType AND DayOfWeek = @i_DayOfWeek);
	IF (@EvUID IS NULL)
	BEGIN
		-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
		INSERT atum2_db_account.dbo.ti_HappyHourEvent(ServerGroupID, dayofweek, starttime, endtime, exprate, SPIRate, exprepairrate, DropItemRate, DropRareItemRate, WarPointRate, InfluenceType, MinLevel, MaxLevel)
		VALUES(0, @i_DayOfWeek, @i_StartTime, @i_EndTime, 0, 0, 0, 0, 0, 0, @i_InflType, 1, 100);
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.ti_HappyHourEvent
		SET StartTime= @i_StartTime, EndTime= @i_EndTime
		WHERE UniqueNumber= @EvUID;
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0029
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - �ʵ� �߰� �� �� �˻� ����� �߰� �� ��� �ʵ�� ���
--						// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - LoginCheckNumber �÷� �߰�
--						// 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_PROCEDURE_080827_0029]
--WITH EXECUTE AS 'proexe'
AS
	SELECT ItemEventUID,ItemEventType,OnlyPCBang,InfluenceType,ItemNum,Count,StartTime,EndTime,MemberShip,ReqLevel,NewMember,UnitKind,PrefixCodeNum,SuffixCodeNum,UseLastGameEndDate,LastGameEndDate,CheckWithCharacterUID, LevelMin, LevelMax, LoginCheckNumber, UseFixedPeriod, FixedPeriod
	FROM atum2_db_account.dbo.ti_ItemEvent WITH (NOLOCK)
	ORDER BY StartTime;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0030
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0030
	@i_ItemEvUID			INT,
	@i_ItemEvType1			INT,
	@i_ItemEvType2			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemEventUID
	FROM atum2_db_account.dbo.ti_ItemEvent
	WHERE ItemEventUID <> @i_ItemEvUID AND (ItemEventType = @i_ItemEvType1 OR ItemEventType = @i_ItemEvType2);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0031
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0031
	@i_AccName				VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM atum2_db_account.dbo.td_blockedaccounts WITH (NOLOCK)
	WHERE AccountName = @i_AccName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0032
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0032
	@i_CharacName				VARCHAR(20),
	@i_ItemNum					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
	SELECT COUNT(*)
	FROM td_Store s, td_Character c WITH (NOLOCK)
	WHERE ItemNum = @i_ItemNum AND s.possess = c.uniquenumber AND s.ItemStorage = 0 AND c.charactername = @i_CharacName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0033
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0033
	@i_ItemUID					BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE
	FROM td_Store
	WHERE uniquenumber = @i_ItemUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0034
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0034
	@i_ItemUID					BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE
	FROM td_Enchant
	WHERE TargetItemUniqueNumber = @i_ItemUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0035
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - ShapeItemNum �ʵ� �߰�, ���� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0035
	@i_ItemUID					BIGINT,
	@i_CurCnts					INT,
	@i_ColorCode				INT,
	@i_PrefixCodeNum			INT,
	@i_SuffixCodeNum			INT,
	@i_ShapeItemNum				INT				-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - ShapeItemNum �ʵ� �߰�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET CurrentCount = @i_CurCnts, ColorCode = @i_ColorCode, PrefixCodeNum = @i_PrefixCodeNum, SuffixCodeNum = @i_SuffixCodeNum, ShapeItemNum= @i_ShapeItemNum
	WHERE UniqueNumber = @i_ItemUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0036
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0036
	@i_ItemUID					BIGINT,
	@i_TargetItemNum			INT,
	@i_EnchantItemNum			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT td_Enchant(TargetItemUniqueNumber, TargetItemNum, EnchantItemNum)
	VALUES(@i_ItemUID, @i_TargetItemNum, @i_EnchantItemNum);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0037
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0037
	@i_AccName					VARCHAR(20),
	@i_AccUID					INT,
	@i_CharacName				VARCHAR(20),
	@i_CharacUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF @i_AccName <> ''
	BEGIN
		SELECT Accountname, AccountUniqueNumber, CharacterName
		FROM td_Character WITH (NOLOCK)
		WHERE accountname = @i_AccName AND (0 = Race & 0x4000);
		RETURN;
	END

	IF @i_AccUID <> 0
	BEGIN
		SELECT Accountname, AccountUniqueNumber, CharacterName
		FROM td_Character WITH (NOLOCK)
		WHERE AccountUniqueNumber = @i_AccUID AND (0 = Race & 0x4000);
		RETURN;
	END

	IF @i_CharacName <> ''
	BEGIN
		SELECT Accountname, AccountUniqueNumber, CharacterName
		FROM td_Character WITH (NOLOCK)
		WHERE accountname IN (SELECT accountname FROM td_Character WHERE charactername = @i_CharacName) AND (0 = Race & 0x4000);
		RETURN;
	END

	IF @i_CharacUID <> 0
	BEGIN
		SELECT Accountname, AccountUniqueNumber, CharacterName
		FROM td_Character WITH (NOLOCK)
		WHERE accountname IN (SELECT accountname FROM td_Character WHERE uniquenumber = @i_CharacUID) AND (0 = Race & 0x4000);
		RETURN;
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0041
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0041
	@i_AccName					VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT accounttype
	FROM atum2_db_account.dbo.td_account WITH (NOLOCK)
	WHERE AccountName = @i_AccName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0042
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0042
	@i_InflTy					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 c.CharacterName, c.UniqueNumber
	FROM td_Character c, td_InfluenceWarData iw WITH (NOLOCK)
	WHERE iw.InfluenceType = @i_InflTy and iw.InflLeaderCharacterUID = c.UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0043
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0043
	@i_InflTy					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 c.CharacterName, c.UniqueNumber
	FROM td_Character c, td_InfluenceWarData iw WITH (NOLOCK)
	WHERE iw.InfluenceType = @i_InflTy and iw.InflSub1LeaderCharacterUID = c.UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0044
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0044
	@i_InflTy					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 c.CharacterName, c.UniqueNumber
	FROM td_Character c, td_InfluenceWarData iw WITH (NOLOCK)
	WHERE iw.InfluenceType = @i_InflTy and iw.InflSub2LeaderCharacterUID = c.UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0045
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - ShapeItemNum �ʵ� �߰�, ��� ���ڵ忡 �ʵ� 1�� �߰�
--						-- // 2009-11-18 by cmkwon, AdminTool���� �ð����� �������� ����� ���� ���� �߰� - UsingTimeStamp �ʵ� �������� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0045
	@i_CharacName				VARCHAR(20),
	@i_ItemStorage1				TINYINT,
	@i_ItemStorage2				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
	SELECT s.UniqueNumber, i.ItemNum, s.PrefixCodeNum, s.SuffixCodeNum, s.ItemStorage, s.Wear, s.ItemWindowIndex, s.CurrentCount, s.ColorCode, s.possess, s.CreatedTime, s.ShapeItemNum, s.UsingTimeStamp
	FROM td_Store s, td_Character c, atum2_db_account.dbo.ti_Item i WITH (NOLOCK) 
	WHERE c.charactername = @i_CharacName AND i.ItemNum = s.ItemNum AND c.accountuniquenumber = s.accountuniquenumber
		AND (c.uniquenumber = s.possess OR s.possess = 0 OR s.possess = -1) AND (s.ItemStorage = @i_ItemStorage1 OR s.ItemStorage= @i_ItemStorage2);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0046
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0046
	@i_ItemUID			BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(*)
	FROM td_Enchant WITH (NOLOCK)
	where TargetItemUniqueNumber = @i_ItemUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0047
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0047
	@i_CharacName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT uniqueNumber
	FROM td_Character WITH (NOLOCK)
	WHERE CharacterName = @i_CharacName;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0048
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0048
	@i_CharacterName		VARCHAR(20),
	@i_MapIndex				SMALLINT,
	@i_ChannelIndex			SMALLINT,
	@i_Position_X			FLOAT,
	@i_Position_Z			FLOAT,
	@i_Race					SMALLINT,
	@i_InfluenceType		TINYINT,
	@i_Level				TINYINT,
	@i_Experience			FLOAT,
	@i_HP					SMALLINT,

	@i_DP					SMALLINT,
	@i_SP					SMALLINT,
	@i_EP					SMALLINT,
	@i_currentHP			FLOAT,
	@i_currentDP			FLOAT,
	@i_currentSP			SMALLINT,
	@i_currentEP			FLOAT,
	@i_AttackPart			SMALLINT,
	@i_DefensePart			SMALLINT,
	@i_FuelPart				SMALLINT,

	@i_SoulPart				SMALLINT,
	@i_ShieldPart			SMALLINT,
	@i_DodgePart			SMALLINT,
	@i_bonusStat			TINYINT,
	@i_bonusSkillPoint		TINYINT,
	@i_Propensity			INT,
	@i_RacingPoint			INT,
	@i_WarPoint				INT,
	@i_CumulativeWarPoint	INT,
	@i_ArenaWin				INT,

	@i_ArenaLose			INT,
	@i_ArenaDisConnect		INT,
	@i_PCBangTotalPlayTime	BIGINT,
	@i_CharacUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-26 by cmkwon, ���� �������� �̺�Ʈ ���� ���� - AdminTool�� ���� ����� �ش� ������ ��� ĳ������ ���� ���������� ���� ����(������ ĳ���͵� ����)
	DECLARE @AccUID		INT;
	DECLARE @curInflTy	TINYINT;
	SELECT @AccUID= AccountUniqueNumber, @curInflTy = InfluenceType FROM td_Character WITH(NOLOCK) WHERE uniqueNumber = @i_CharacUID;
	IF (@curInflTy <> @i_InfluenceType)
	BEGIN
		-- #define INFLUENCE_TYPE_NORMAL				(BYTE)0x0001	// 2005-12-20 by cmkwon, ���������� �Ϲݱ�
		-- #define INFLUENCE_TYPE_VCN					(BYTE)0x0002	// 2005-12-20 by cmkwon, ���������� ���Ա�, ����(V.C.U: Vijuenill City United.)
		-- #define INFLUENCE_TYPE_ANI					(BYTE)0x0004	// 2005-12-20 by cmkwon, �˸��� ���Ա�, ����(�� �������� ���� -�˸��� ��Ƽ �ݶ���- (A.N.I: Anti Nationalism Influence))
		DECLARE @NewSeletableInfTy TINYINT;
		SET @NewSeletableInfTy = @i_InfluenceType;
		IF (@i_InfluenceType = 1)
		BEGIN
			SET @NewSeletableInfTy = 6;		-- 6 = 2 + 4
		END

		-- �ش� ������ ��� ĳ������ ���ð����� ������ �����Ѵ�.
		EXEC atum_ChangeInfluenceType @AccUID, @i_CharacUID, @i_InfluenceType, @NewSeletableInfTy;

		-- �ش� ĳ���͸��� ��� ģ��/�ź� ����Ʈ���� �����Ѵ�.
		DELETE FROM td_FriendList
		WHERE CharacterName = @i_CharacterName OR FriendName = @i_CharacterName;
	END

	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - MapIndex ����
	UPDATE td_Character 
	SET CharacterName = @i_CharacterName, MapIndex = @i_MapIndex, ChannelIndex = @i_ChannelIndex, Position_X = @i_Position_X, Position_Z = @i_Position_Z
			, Race = @i_Race, InfluenceType = @i_InfluenceType, Level = @i_Level, Experience = @i_Experience
			, HP = @i_HP, DP = @i_DP,SP = @i_SP, EP = @i_EP, CurrentHP = @i_currentHP, CurrentDP = @i_currentDP, CurrentSP = @i_currentSP, CurrentEP = @i_currentEP
			, AttackPart = @i_AttackPart, DefensePart = @i_DefensePart, FuelPart = @i_FuelPart, SoulPart = @i_SoulPart, ShieldPart = @i_ShieldPart,	DodgePart = @i_DodgePart
			, BonusStat = @i_bonusStat, BonusStatPoint = @i_bonusSkillPoint, Propensity = @i_Propensity, RacingPoint = @i_RacingPoint
			, WarPoint =@i_WarPoint, CumulativeWarPoint = @i_CumulativeWarPoint, ArenaWin = @i_ArenaWin, ArenaLose = @i_ArenaLose, ArenaDisConnect = @i_ArenaDisConnect
			, PCBangTotalPlayTime = @i_PCBangTotalPlayTime
	WHERE uniqueNumber = @i_CharacUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0049
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0049
	@i_ItemNum				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemNum
	FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK)
	WHERE ItemNum = @i_ItemNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0050
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0050
	@i_LogTableName		VARCHAR(128),
	@i_Query			VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @SearchedIdx INT;

	SET @SearchedIdx = PATINDEX('%'+@i_LogTableName+'%', @i_Query);
	IF (0 >= @SearchedIdx)
	BEGIN
		RETURN;
	END

	exec (@i_Query);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0051
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0051
	@i_ServerGroupID			INT,
	@i_StartDateTime			VARCHAR(30),
	@i_EndDateTime				VARCHAR(30),
	@i_SummonerMapIndex			SMALLINT,
	@i_SummonerReqMinLevel		TINYINT,
	@i_SummonerReqMaxLevel		TINYINT,
	@i_SummonerExceptMonster	INT,
	@i_SummonMonsterNum			INT,
	@i_SummonMonsterCount		INT,
	@i_SummonDelayTime			INT,

	@i_SummonProbability		INT	
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_EventMonster(ServerGroupID,StartDateTime,EndDateTime,SummonerMapIndex,SummonerReqMinLevel,SummonerReqMaxLevel,SummonerExceptMonster,SummonMonsterNum,SummonMonsterCount,SummonDelayTime,SummonProbability)
	VALUES(@i_ServerGroupID, @i_StartDateTime, @i_EndDateTime, @i_SummonerMapIndex, @i_SummonerReqMinLevel, @i_SummonerReqMaxLevel, @i_SummonerExceptMonster, @i_SummonMonsterNum, @i_SummonMonsterCount, @i_SummonDelayTime, @i_SummonProbability);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0052
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0052
	@i_ServerGroupID			INT,
	@i_StartDateTime			VARCHAR(30),
	@i_EndDateTime				VARCHAR(30),
	@i_SummonerMapIndex			SMALLINT,
	@i_SummonerReqMinLevel		TINYINT,
	@i_SummonerReqMaxLevel		TINYINT,
	@i_SummonerExceptMonster	INT,
	@i_SummonMonsterNum			INT,
	@i_SummonMonsterCount		INT,
	@i_SummonDelayTime			INT,

	@i_SummonProbability		INT,
	@i_EventMonsterUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.ti_EventMonster
	SET ServerGroupID= @i_ServerGroupID, StartDateTime= @i_StartDateTime, EndDateTime= @i_EndDateTime,
			SummonerMapIndex= @i_SummonerMapIndex, SummonerReqMinLevel= @i_SummonerReqMinLevel, 
			SummonerReqMaxLevel= @i_SummonerReqMaxLevel, SummonerExceptMonster= @i_SummonerExceptMonster,
			SummonMonsterNum= @i_SummonMonsterNum, SummonMonsterCount= @i_SummonMonsterCount,
			SummonDelayTime= @i_SummonDelayTime, SummonProbability= @i_SummonProbability
	WHERE EventMonsterUID = @i_EventMonsterUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0053
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0053
	@i_EventMonsterUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE atum2_db_account.dbo.ti_EventMonster
	WHERE EventMonsterUID = @i_EventMonsterUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0054
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0054
	@i_GuildMarkState			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildUniqueNumber, GuildName, GuildMarkImage, GuildMarkState
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildMarkState = @i_GuildMarkState;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0055
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0055
	@i_GuildUID					INT,
	@i_GuildMarkState			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Guild
	SET GuildMarkState = @i_GuildMarkState
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0056
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0056
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0057
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0057
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_EnchantInfo WITH (NOLOCK);
GO

--> 130605_DB��Ű��_02_(�����۹̸�����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0058
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						 // 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo	
--						 // 2013-05-06 by hskim, ������ �̸� ���� (�Ӽ� �� �߰�)
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_PROCEDURE_080827_0058]
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT UniqueID, TargetItemNum, MixingProbability, MixingCost, Visible FROM atum2_db_account.dbo.ti_ItemMixingInfo ORDER BY UniqueID ASC;
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_load_ti_itemmixingelement
-- DESC				: // 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo	
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_itemmixingelement
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueID, SourceItemNum, SourceItemCount FROM atum2_db_account.dbo.ti_ItemMixingElement ORDER BY UniqueID ASC;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_OverlapItem
-- DESC				: // 2012-03-12 by hskim, DB ���� ���� - it_Item (�� ���̺� �����Ͱ� ������ ti_Item �����͸� ���� ����)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_ti_OverlapItem
	@ItemNum			INT,
	@CashPrice			INT,
	@Tab				INT,
	@ItemAttribute		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_OverlapItem(ItemNum, CashPrice, Tab, ItemAttribute)
		VALUES (@ItemNum, @CashPrice, @Tab, @ItemAttribute)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_OverlapItem
-- DESC				: // 2012-03-12 by hskim, DB ���� ���� - it_Item (�� ���̺� �����Ͱ� ������ ti_Item �����͸� ���� ����)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_ti_OverlapItem
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_OverlapItem
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_load_ti_OverlapItem
-- DESC				: // 2012-03-12 by hskim, DB ���� ���� - it_Item (�� ���̺� �����Ͱ� ������ ti_Item �����͸� ���� ����)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_ti_OverlapItem
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemNum, CashPrice, Tab, ItemAttribute FROM atum2_db_account.dbo.ti_OverlapItem
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0059
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0059
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_RareItemInfo WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0060
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0060
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT Code, Alpha, Collision, CollisionForServer, RenderIndex, ObjectRenderType
	FROM atum2_db_account.dbo.ti_MapObject WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0061
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0061
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_BuildingNPC WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0062
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ChangeTargetTime �ʵ� �߰�
--						-- // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - WayPointPattern �ʵ� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0062
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, MonsterName, Level, Experience, HP, Race, Speed, MonsterItem01, MonsterItem02, MonsterItem03, MonsterItem04, MonsterItem05, 
			MonsterItem06, MonsterItem07, MonsterItem08, MonsterItem09, MonsterItem10,	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
			MonsterItem11, MonsterItem12, MonsterItem13, MonsterItem14, MonsterItem15,	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
			ControlSkill, SizeForClient, Faction, 
			MonsterForm, AttackPattern, MovePattern, Belligerence, Defense, DefenceProbability, AlphaBlending, AttackObject, AttackRange, HPRecoveryTime, HPRecoveryValue, RenderIndex, ScaleValue, TextureIndex, SourceIndex, QuickTurnAngle,
			QuickSpeed, QuickTurnTerm, MPOption, MPOptionParam1, MPOptionParam2, Range, TurnAngle, MonsterHabit, ClickEvent
			, HPActionIdx, MonsterTarget, ChangeTarget, MonsterTarget2, PortraitFileName,ChangeTargetTime, WayPointPattern		-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - 	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - -- 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - WayPointPattern �ʵ� �߰�
	FROM atum2_db_account.dbo.ti_Monster WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0063
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ChangeTargetTime �ʵ� �߰�
--						-- // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - WayPointPattern �ʵ� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0063
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, MonsterName, Level, Experience, HP, Race, Speed, MonsterItem01, MonsterItem02, MonsterItem03, MonsterItem04, MonsterItem05, 
			MonsterItem06, MonsterItem07, MonsterItem08, MonsterItem09, MonsterItem10,	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
			MonsterItem11, MonsterItem12, MonsterItem13, MonsterItem14, MonsterItem15,	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
			ControlSkill, SizeForServer, Faction, 
			MonsterForm, AttackPattern, MovePattern, Belligerence, Defense, DefenceProbability, AlphaBlending, AttackObject, AttackRange, HPRecoveryTime, HPRecoveryValue, RenderIndex, ScaleValue, TextureIndex, SourceIndex, QuickTurnAngle, 
			QuickSpeed, QuickTurnTerm, MPOption, MPOptionParam1, MPOptionParam2, Range, TurnAngle, MonsterHabit, ClickEvent
			, HPActionIdx, MonsterTarget, ChangeTarget, MonsterTarget2, PortraitFileName,ChangeTargetTime, WayPointPattern	-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - -- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - -- 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - WayPointPattern �ʵ� �߰�
	FROM atum2_db_account.dbo.ti_Monster WITH (NOLOCK);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0064
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0064
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_MapInfo WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0065
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0065
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	Select TempIp.UID, TempIp.ST_IP, TempIp.ED_IP, TempBr.User_Id, TempBr.Branch_Name, TempBr.Branch_RegNO, TempBr.Branch_Tel, TempBr.ZipCode, TempBr.Addr_Sido, TempBr.Addr_SiGugun, TempBr.Addr_Dong, 
			TempBr.Addr_Detail, TempBr.User_Level 
	From 	(Select MAX(BSeq) As UID, ST_IP, MAX(ED_IP)As ED_IP 
				From pc_mem_branch_ip where ST_IP <> ' ' AND ST_IP NOT LIKE '%..%' Group by ST_IP 
									) As TempIp
									Inner Join
									(select TempBranch.BSeq, TempBranch.User_Id,
									TempBranch.Branch_Name, 	TempBranch.Branch_RegNO,	 TempBranch.Branch_Tel,
									TempBranch.ZipCode,		 TempBranch.Addr_Sido, 		TempBranch.Addr_SiGugun,	 TempBranch.Addr_Dong,
									TempBranch.Addr_Detail, 		TempMember.User_Level
									from
									(select * from pc_mem_branch) As TempBranch Inner join
									(select User_Id, User_Level  from pc_member Where  pc_member.User_Level >= 3) As TempMember
									On TempBranch.User_Id = TempMember.User_Id) As TempBr
									On TempIp.UID = TempBr.BSeq;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0066
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0066
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE atum2_db_account.dbo.td_pcbang;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0067
-- DESC				: -- // 2008-09-01 by cmkwon, SQLPrepare ��ü ó�� - �ϳ��� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0067
	@i_UID					INT,
	@i_ST_IP				VARCHAR(16),
	@i_ED_IP				VARCHAR(4),
	@i_User_id				VARCHAR(15),
	@i_Branch_Name			VARCHAR(50),
	@i_Branch_RegNO			VARCHAR(12),
	@i_Branch_Tel			VARCHAR(14),
	@i_ZipCode				VARCHAR(15),
	@i_Addr_Sido			VARCHAR(10),
	@i_Addr_SiGuGun			VARCHAR(20),
	@i_Addr_Dong			VARCHAR(100),
	@i_Addr_Detail			VARCHAR(50),
	@i_User_Level			TINYINT		
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - @i_User_id ����
	INSERT atum2_db_account.dbo.td_pcbang(UID,ST_IP,ED_IP,User_Id,Branch_Name,Branch_RegNO,Branch_Tel,ZipCode,Addr_Sido,Addr_SiGuGun,Addr_Dong,Addr_Detail,User_Level)
	VALUES (@i_UID,@i_ST_IP,@i_ED_IP,@i_User_id,@i_Branch_Name,@i_Branch_RegNO,@i_Branch_Tel,@i_ZipCode,@i_Addr_Sido,@i_Addr_SiGuGun,@i_Addr_Dong,@i_Addr_Detail,@i_User_Level);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0068
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0068
	@i_ServerGroupID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfluenceType, InflLeaderCharacterUID
	FROM td_InfluenceWarData WITH (NOLOCK)
	WHERE MGameServerID = @i_ServerGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0069
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0069
	@i_ServerGroupID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfluenceType, InflSub1LeaderCharacterUID
	FROM td_InfluenceWarData WITH (NOLOCK)
	WHERE MGameServerID = @i_ServerGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0070
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0070
	@i_ServerGroupID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfluenceType, InflSub2LeaderCharacterUID
	FROM td_InfluenceWarData WITH (NOLOCK)
	WHERE MGameServerID = @i_ServerGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0071
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0071
	@i_PeriodDay		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
-- // 2009-02-10 by cmkwon, ���� ���� ī��Ʈ ���� ���� - ���� ����� ���� ���� ī��Ʈ �˻� ����, ���� ĳ���� ����, �������� ���
-- 	SELECT InfluenceType, COUNT(*)
--	FROM td_Character WITH (NOLOCK)
--	WHERE LastStartedTime > DATEADD(day, @i_PepiodDay, GETDATE())
--	GROUP BY InfluenceType;
	SELECT tm.InfluenceType, COUNT(*)
	FROM (SELECT DISTINCT AccountName, InfluenceType
			FROM td_Character WITH(NOLOCK)
			WHERE Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_PeriodDay, GETDATE())) tm
	GROUP BY tm.InfluenceType;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0072
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0072
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_InfluenceWar WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0073
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0073
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT EventMonsterUID, ServerGroupID, StartDateTime, EndDateTime, SummonerMapIndex, SummonerReqMinLevel, SummonerReqMaxLevel, SummonerExceptMonster, SummonMonsterNum, SummonMonsterCount, SummonDelayTime, SummonProbability
	FROM atum2_db_account.dbo.ti_EventMonster WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0074
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--							atum2_db_account, atum2_db_[n] �Ѵ� �ʿ��� ���ν�����.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0074
	@i_AccName				VARCHAR(20),
	@i_Password				VARCHAR(33),
	@i_MD5EncodedPassword	VARCHAR(33)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT accounttype
	FROM atum2_db_account.dbo.td_account WITH (NOLOCK)
	WHERE accountname = @i_AccName and (password = @i_Password OR password = @i_MD5EncodedPassword);
GO

--> 130605_DB��Ű��_03_(��������Ʈ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0075
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0075
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT wd.InfluenceType, wd.MGameServerID, wd.WartimeStage, wd.ContributionPoint, wd.InflLeaderCharacterUID, c.CharacterName, wd.OwnerOfConflictArea, wd.InflSub1LeaderCharacterUID, c1.CharacterName, wd.InflSub2LeaderCharacterUID, c2.CharacterName, wd.MSWarOptionType, wd.ConsecutiveVictories
									FROM td_influencewardata wd  LEFT OUTER JOIN td_character c
									ON wd.InflLeaderCharacterUID = c.uniquenumber
									LEFT OUTER JOIN td_character c1
									ON wd.InflSub1LeaderCharacterUID = c1.uniquenumber
									LEFT OUTER JOIN td_character c2
									ON wd.InflSub2LeaderCharacterUID = c2.uniquenumber;
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0076
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0076
	@i_InflTy				TINYINT,
	@i_ServerGroupID		INT,
	@i_WartimeStage			TINYINT,
	@i_ContributionPoint	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO td_InfluenceWarData
	VALUES (@i_InflTy, @i_ServerGroupID, @i_WartimeStage, @i_ContributionPoint, 0, 0, 0, 0, 510);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0077
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0077
	@i_CharacUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT g.GuildUniqueNumber
	FROM td_Guild g WITH (NOLOCK), td_Character c WITH (NOLOCK)
	WHERE c.UniqueNumber = @i_CharacUID AND g.GuildUniqueNumber = c.GuildUniqueNumber AND g.GuildCommanderUniqueNumber = c.UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0078
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0078
	@i_CharacUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT g.GuildMemberCapacity
	FROM td_Guild g, td_Character c WITH (NOLOCK)
	WHERE c.UniqueNumber = @i_CharacUID AND g.GuildUniqueNumber = c.GuildUniqueNumber AND g.GuildCommanderUniqueNumber = c.UniqueNumber;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0079
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0079
	@i_GuildUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0080
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0080
	@i_GuildUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT CharacterUniqueNumber
	FROM td_GuildMember WITH (NOLOCK)
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0081
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0081
	@i_GuildUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildCommanderUniqueNumber
	FROM td_Guild WITH (NOLOCK)
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0082
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0082
	@i_CharacUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildUniqueNumber
	FROM td_Character
	WHERE UniqueNumber = @i_CharacUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0083
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0083
	@i_GuildUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildState FROM td_Guild WITH (NOLOCK)
	WHERE GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0084
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0084
	@i_GuildUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.CharacterName
	FROM td_Character c WITH (NOLOCK) INNER JOIN td_Guild g ON c.UniqueNumber = g.GuildCommanderUniqueNumber
	WHERE g.GuildUniqueNumber = @i_GuildUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0120
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0120
	@i_AccName				VARCHAR(20),
	@i_Password				VARCHAR(33),
	@i_MD5EncodedPassword	VARCHAR(33)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT accounttype
	FROM atum2_db_account.dbo.td_account
	WHERE accountname = @i_AccName AND (password = @i_Password OR password = @i_MD5EncodedPassword);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0122
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0122
	@i_Query			VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0125
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0125
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select a.AccountName, a.CharacterName, c.Level, a.START_TIME, b.END_TIME, b.PlayTime, b.PCBangUID, c.CreatedTime 
									from 
									(select CharacterUniqueNumber, AccountName, CharacterName, Time as START_TIME, TotalPlayTime 
									from dbo.game_log_start_end 
									where LogType = 19) as a, 
									(select CharacterUniqueNumber, AccountName, CharacterName, Time as END_TIME, TotalPlayTime, PlayTime, PCBangUID 
									from dbo.game_log_start_end 
									where LogType = 20) as b, 
									dbo.td_Character as c 
									where (0 = c.Race & 0x4000) AND a.CharacterUniqueNumber = b.CharacterUniqueNumber  
									and (b.TotalPlayTime - a.TotalPlayTime) = PlayTime  
									and a.CharacterUniqueNumber = c.UniqueNumber 
									and a.START_TIME < b.END_TIME 
									order by  a.START_TIME;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0129
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0129
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select TotalTime.PCBangUID, PCBang.Branch_Name, TotalTime.TotalPCBangPlayTime, 
									PCBang.Branch_Tel, PCBang.ZipCode, PCBang.Addr_Sido, PCBang.Addr_SiGuGun, 
									PCBang.Addr_Dong, PCBang.Addr_Detail, PCBang.User_Level 
									from 
									dbo.view_pcbangplaytime AS TotalTime INNER JOIN atum2_db_account.dbo.td_pcbang AS PCBang 
									on TotalTime.PCBangUID = PCBang.UID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0133
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0133
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	Select Time, PCBangUID, PCBangPlayTime
	From dbo.log_pcbangtotalplaytimebyeachday WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0134
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0134
	@i_ReqRowCounts			INT,
	@i_ExcludeRace			SMALLINT,
	@i_OrderByFieldName		VARCHAR(128)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @Query VARCHAR(3000)
	SET @Query = 'SELECT TOP ' + CAST(@i_ReqRowCounts AS VARCHAR(10)) + ' accountname, charactername, dbo.atum_GetGearString(unitkind), InfluenceType, level, WarPoint, CumulativeWarPoint, ArenaWin, ArenaLose, ArenaDisConnect FROM td_Character WITH (NOLOCK) WHERE (0 = Race & '
					+ CAST(@i_ExcludeRace AS VARCHAR(10))+ ' ) AND race < 128 ORDER BY ' + @i_OrderByFieldName + ' DESC;'
	exec (@Query)	
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0135
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0135
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT dbo.atum_getonlydate(RegisteredDate), count(*) 
									FROM atum2_db_account.dbo.td_account WITH (NOLOCK) 
									WHERE RegisteredDate >= @i_StartDate and RegisteredDate <= @i_EndDate and accounttype = 0 
									GROUP BY dbo.atum_getonlydate(RegisteredDate) 
									ORDER BY dbo.atum_getonlydate(RegisteredDate);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0136
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0136
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT dbo.atum_getonlydate(RegisteredDate), count(*) 
	FROM atum2_db_account.dbo.td_account WITH (NOLOCK) 
	WHERE RegisteredDate >= @i_StartDate and RegisteredDate <= @i_EndDate and accounttype = 0 
		and AccountUniqueNumber in (select DISTINCT a.accountuniquenumber from atum2_db_account.dbo.td_account a, td_Character c where a.RegisteredDate >= @i_StartDate and a.RegisteredDate <=@i_EndDate and a.AccountuniqueNumber = c.AccountUniqueNumber) 
	GROUP BY dbo.atum_getonlydate(RegisteredDate) 
	ORDER BY dbo.atum_getonlydate(RegisteredDate);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0136
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0137
	@i_TermDay				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select count(*)
	from atum2_db_account.dbo.td_account WITH (NOLOCK)
	where lastlogindate < dateadd(ww, @i_TermDay, getdate());
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0138
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0138
	@i_StartDate			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select birthyear, count(*)
	from atum2_db_account.dbo.td_account WITH (NOLOCK)
	where registereddate >= @i_StartDate
	group by birthyear
	order by birthyear;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0141
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0141
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT time, clientCount FROM log_server_map ORDER BY time DESC;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0142
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0142
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 (AccountUniqueNumber) FROM atum2_db_account.dbo.td_account WITH (NOLOCK) ORDER BY AccountUniqueNumber DESC;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0143
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0143
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(*) FROM atum2_db_account.dbo.td_account WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0144
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0144
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ((SELECT TOP 1 (AccountUniqueNumber) FROM atum2_db_account.dbo.td_account WITH (NOLOCK) ORDER BY AccountUniqueNumber DESC) - COUNT(*)) FROM atum2_db_account.dbo.td_account;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0145
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0145
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT (SELECT TOP 1 (AccountUniqueNumber) FROM atum2_db_account.dbo.td_account WITH (NOLOCK) ORDER BY AccountUniqueNumber DESC) - ((SELECT TOP 1 (AccountUniqueNumber) FROM atum2_db_account.dbo.td_account ORDER BY AccountUniqueNumber DESC) - COUNT(*))/datediff(dd, min(registereddate), getdate()) AS 'now provisional member counts'
	FROM atum2_db_account.dbo.td_account;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0155
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0155
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select hour, max(clientcount) as maxcount, min(clientcount) as mincount,avg(clientcount) as avgcount
	from user_count_timeline
	group by hour
	order by hour ;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0160
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0160
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select date, max(clientcount) as maxcount, avg(clientcount) as avgcount, min(clientcount) as mincount
	from user_count_timeline
	group by date
	order by date;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0165
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0165
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select datehour, max(clientcount) as maxcount, min(clientcount) as mincount, avg(clientcount) as avgcount
	from user_count_timeline
	group by datehour
	order by datehour desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0168
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0168
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM view_levelranking;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0171
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0171
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM view_levelranking;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0175
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0175
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT *
	FROM view_levelranking
	ORDER BY InfluenceType, Level desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0178
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0178
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM view_levelranking ORDER BY InfluenceType, Level desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0180
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0180
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - ItemNum ����
	select i.ItemNum, count(i.ItemNum) as Sellcount, count(i.ItemNum)*i.CashPrice as SellCash 
	from atum_log_item_buy_sell il, atum2_db_account.dbo.ti_Item i WITH (NOLOCK)
	where il.ItemNum = i.ItemNum and 0 <> i.ItemAttribute & 65536 and il.ItemUniqueNumber = 0 -- // 2008-10-06 by dhjin, ��������� 2�� �����ϴ� �κ��� �־� ItemUID = 0���� �����Ѵ�.
			and il.time >= @i_StartDate and il.time <= @i_EndDate 
	group by i.ItemNum, i.CashPrice;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0183
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0183
	@i_ExcludeRace			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.accountname, c.charactername, dbo.atum_GetGearString(c.unitkind) as unit, c.InfluenceType, c.level, tm.Count 
									FROM td_Character c, (SELECT accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter	FROM td_Character 
									WHERE (0 = Race & @i_ExcludeRace) AND race < 128 and charactername not like 'loadtest%%'	group by accountuniquenumber) c2, atum2_db_account.dbo.td_account a, view_itemcount tm 
									WHERE (0 = c.Race & @i_ExcludeRace) AND c.Race < 128 AND c.accountuniquenumber = c2.accountuniquenumber and c.experience >= c2.maxexp AND (c.AccountUniqueNumber in (select AccountUniqueNumber from view_itemcount)) 
									AND a.accountuniquenumber = c.accountuniquenumber and tm.AccountUniqueNumber = c.accountuniquenumber 
									ORDER BY tm.Count desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0186
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0186
	@i_ExcludeRace			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.accountname, c.charactername, dbo.atum_GetGearString(c.unitkind) as unit, c.InfluenceType, c.level, tm.Count 
									FROM td_Character c, (SELECT accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter	FROM td_Character 
									WHERE (0 = Race& @i_ExcludeRace) AND race < 128 and charactername not like 'loadtest%%'	group by accountuniquenumber) c2, atum2_db_account.dbo.td_account a, view_itemcount tm 
									WHERE (0 = c.Race& @i_ExcludeRace) AND c.Race < 128 and c.accountuniquenumber = c2.accountuniquenumber and c.experience >= c2.maxexp AND (c.AccountUniqueNumber in (select AccountUniqueNumber from view_itemcount)) 
									AND a.accountuniquenumber = c.accountuniquenumber and tm.AccountUniqueNumber = c.accountuniquenumber 
									ORDER BY tm.Count desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0187
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0187
	@i_ItemNum				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT SUM(CAST(CurrentCount AS FLOAT)) 
									FROM td_Store s, atum2_db_account.dbo.td_account a WITH (NOLOCK)
									WHERE s.ItemNum= @i_ItemNum and s.AccountUniqueNumber = a.AccountUniqueNumber and a.AccountType < 128 
									GROUP by s.ItemNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0188
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0188
	@i_ItemNum				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(s.ItemNum) 
									FROM td_Store s, atum2_db_account.dbo.td_account a WITH (NOLOCK)
									WHERE s.ItemNum= @i_ItemNum and s.AccountUniqueNumber = a.AccountUniqueNumber and a.AccountType < 128 
									GROUP by s.ItemNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0195
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0195
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select c.AccountName, c.charactername, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, c.TotalPlayTime, m.TotalCount from moneyitemtable m, td_Character c WITH (NOLOCK)
	where c.uniquenumber = m.possess and c.race < 128 order by m.TotalCount desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0198
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0198
	@i_ReqRowCounts			INT,
	@i_ExcludeRace			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.accountname, c.charactername, dbo.atum_GetGearString(c.unitkind) as unit, c.InfluenceType, c.level, tmM.TotalCount 
	FROM td_Character c, (SELECT accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter	FROM td_Character 
									WHERE (0 = Race & @i_ExcludeRace) AND race < 128 and charactername not like 'loadtest%%'	group by accountuniquenumber) c2, atum2_db_account.dbo.td_account a, moneyitemtable tmM 
	WHERE (0 = c.Race & @i_ExcludeRace) AND c.Race < 128 AND c.accountuniquenumber = c2.accountuniquenumber and c.experience >= c2.maxexp AND (c.AccountUniqueNumber in (select AccountUniqueNumber from moneyitemtable)) 
			AND a.accountuniquenumber = c.accountuniquenumber and tmM.AccountUniqueNumber = c.accountuniquenumber 
	ORDER BY tmM.TotalCount desc;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0199
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0199
	@i_ItemNum				INT,
	@i_ExcludeRace			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT SUM(CAST(CurrentCount AS FLOAT)) 
									FROM td_Store s, td_Character c WITH (NOLOCK)
									WHERE s.ItemNum= @i_ItemNum and s.Possess = c.uniqueNumber and 0 = c.Race & @i_ExcludeRace AND c.Race < 128 
									GROUP by s.ItemNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0200
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0200
	@i_ReqRowCounts			INT,
	@i_ExcludeRace			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @Query VARCHAR(3000)
	SET @Query = 'SELECT TOP ' + CAST(@i_ReqRowCounts AS VARCHAR(10)) + ' c.accountname, c.charactername, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, c.PKWinPoint*10 + c.PKLossPoint, c.PKWinPoint, c.PKLossPoint FROM td_Character c WITH (NOLOCK) WHERE 0 = c.Race & '
					+ CAST(@i_ExcludeRace AS VARCHAR(10))+ ' AND c.race < 128 ORDER BY c.PKWinPoint*10 + c.PKLossPoint DESC';
	exec (@Query);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0201
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0201
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0202
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0202
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0203
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0203
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select date, count(*) from (select time, dbo.atum_getonlydate(time) as date	from Temp_View l where logtype = 22 and time > @i_StartDate and time < @i_EndDate) ll 
	group by date	order by date
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0204
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0204
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0205
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0205
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0206
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0206
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30),
	@i_DeleteRace		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, dbo.atum_getonlydate(time) 
					from Temp_View l, td_Character c1, td_Character c2 where logtype = 22 and time > @i_StartDate and time < @i_EndDate 
						and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber AND 0 = c1.Race & @i_DeleteRace
					order by time
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0207
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0207
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0208
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0208
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0209
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0209
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30),
	@i_DeleteRace		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, dbo.atum_getonlydate(time) 
 						from Temp_View l, td_Character c1, td_Character c2 where (logtype = 22 or logtype = 23) and time > @i_StartDate and time < @i_EndDate 
 							and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber AND 0 = c1.Race & @i_DeleteRace
 						order by time
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0210
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0210
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0211
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0211
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0212
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0212
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30),
	@i_DeleteRace		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select c1.charactername, (select level from td_Character where charactername = c1.charactername) as level, count(*) as count 
 						from Temp_View l, td_Character c1, td_Character c2 where (logtype = 22 or logtype = 23) and time > @i_StartDate and time < @i_EndDate 
 							and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber AND 0 = c1.Race & @i_DeleteRace
 						group by c1.charactername 
 						order by count desc
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0213
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0213
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0214
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0214
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0215
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0215
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	select date, count(*) from (select time, dbo.atum_getonlydate(time) as date	from Temp_View l	where logtype = 21 and time > @i_StartDate and time < @i_EndDate) ll 
	group by date order by date
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0216
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0216
	@i_QuestIndex		INT,
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30),
	@i_DeleteRace		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.AccountName, c.CharacterName, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, q.QuestTimeStamp 
		FROM td_Character c, td_CharacterQuest q WITH (NOLOCK) 
 		WHERE q.QuestIndex = @i_QuestIndex and q.QuestState = 2 and q.QuestTimeStamp > @i_StartDate and q.QuestTimeStamp < @i_EndDate and q.CharacterUniqueNumber = c.uniqueNumber AND 0 = c.Race & @i_DeleteRace
		ORDER BY q.QuestTimeStamp
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0217
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0217
	@i_QuestIndex		INT,
	@i_StartDate		VARCHAR(30),
	@i_EndDate			VARCHAR(30),
	@i_DeleteRace		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT c.AccountName, c.CharacterName, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, q.QuestTimeStamp 
 		FROM td_Character c, td_CharacterQuest q WITH (NOLOCK) 
 		WHERE q.QuestIndex = @i_QuestIndex and q.QuestState = 1 and q.QuestTimeStamp > @i_StartDate and q.QuestTimeStamp < @i_EndDate and q.CharacterUniqueNumber = c.uniqueNumber AND 0 = c.Race & @i_DeleteRace
 		ORDER BY q.QuestTimeStamp
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0218
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0218
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW Temp_View
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0219
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0219
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0220
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0220
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT l.MonsterUnitKind, l.MapIndex, l.ChannelIndex, l.CreatedTime, l.DeadTime, l.AttackUser1, l.AttackUser2, l.AttackUser3, l.AttackUser4, l.AttackUser5 
 			, l.AttackUser6, l.AttackUser7, l.AttackUser8, l.AttackUser9, l.AttackUser10, l.DropItemList 
 		FROM Temp_View l
 		ORDER BY l.Time DESC
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0221
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0221
	@i_CharacterName   VARCHAR(20)	
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT dbo.atum_GetGearString(unitkind), InfluenceType, Level 
				FROM td_Character WITH (NOLOCK)
				WHERE CharacterName = @i_CharacterName
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0222
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0222
	@i_RankCount	INT,
	@i_DeleteRace	SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @Query VARCHAR(3000)
	SET @Query = 'SELECT TOP ' + CAST(@i_RankCount AS VARCHAR(10)) + ' g.GuildName, g.GuildUniqueNumber, g.TotalFame, g.MonthlyFame, c.AccountName, c.CharacterName, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level 
 		FROM td_Character c, td_Guild g WITH (NOLOCK) 
 		WHERE g.GuildCommanderUniqueNumber = c.UniqueNumber AND 0 = c.Race & ' + CAST(@i_DeleteRace AS VARCHAR(10)) + ' ORDER BY g.MonthlyFame DESC'
	exec (@Query)	
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0223
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0223
	@i_RankCount	INT,
	@i_DeleteRace	SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @Query VARCHAR(3000)
	SET @Query = 'SELECT TOP ' + CAST(@i_RankCount AS VARCHAR(10)) + ' c.accountname, c.charactername, dbo.atum_GetGearString(c.unitkind), c.InfluenceType, c.level, c.GuildName, c.Propensity, c.TotalPlayTime 
		FROM td_Character c WITH (NOLOCK) 
 		WHERE 0 = c.Race & ' + CAST(@i_DeleteRace AS VARCHAR(10)) + ' AND c.race < 128 
 		ORDER BY c.Propensity DESC'
	exec (@Query)	
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0224
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0224
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW tm_user_connection
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0225
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0225
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0226
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0226
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT selectableinfluencemask, COUNT(selectableinfluencemask) 
 						FROM tm_user_connection 
 						GROUP BY selectableinfluencemask
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0227
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0227
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DROP VIEW tm_user_connection
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0228
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0228
	@i_Query   VARCHAR(2000)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	exec (@i_Query)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0229
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0229
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT l.conntedDate, l.SelectableInfluenceMask, COUNT(l.AccountUniqueNumber) 
 		FROM tm_user_connection l WITH(NOLOCK) 
 		GROUP BY l.conntedDate, l.SelectableInfluenceMask 
 		ORDER BY l.conntedDate
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0236
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0236
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT a.AccountName, a.Password as TempPassword, ak.Password as OrgPassword
						FROM atum2_db_account.dbo.td_account a, td_accountBackup ak
						WHERE a.accountname = ak.accountname
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0237
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0237
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO AccountBackup
			SELECT AccountName, Password
			FROM atum2_db_account.dbo.td_account
			WHERE AccountName = @i_AccountName
			-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
			-- WHERE AccountName like @i_AccountName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0238
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0238
	@i_PW				VARCHAR(33),
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account SET Password = @i_PW WHERE AccountName = @i_AccountName
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- UPDATE atum2_db_account.dbo.td_account SET Password = @i_PW WHERE AccountName like @i_AccountName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0239
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0239
	@i_AccountName1		VARCHAR(20),
	@i_AccountName2		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_account SET Password = (SELECT Password FROM td_AccountBackup WHERE AccountName = @i_AccountName1)
						WHERE AccountName = @i_AccountName2
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	--UPDATE atum2_db_account.dbo.td_account SET Password = (SELECT Password FROM td_AccountBackup WHERE AccountName like @i_AccountName1)
	--					WHERE AccountName LIKE @i_AccountName2
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0240
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0240
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM td_AccountBackup WHERE AccountName = @i_AccountName
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- DELETE FROM td_AccountBackup WHERE AccountName like @i_AccountName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0241
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0241
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO BlockedAccounts VALUES(@i_AccountName)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0242
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0242
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_blockedaccounts WHERE AccountName = @i_AccountName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0243
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0243
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.td_blockedaccounts WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0244
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0244
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT Code, Alpha, Collision, CollisionForServer,RenderIndex, ObjectRenderType FROM atum2_db_account.dbo.ti_MapObject WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0246
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0246
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0247
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0247
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - 
	--SELECT * FROM atum2_db_account.dbo.ti_MonsterItem WITH (NOLOCK)
	SELECT MonsterUniqueNumber,ItemNum,MinCount,MaxCount,Probability,PrefixProbability,SuffixProbability,DropType
	FROM atum2_db_account.dbo.ti_MonsterItem WITH (NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0248
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0248
	@i_MapIndex		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_CityTargetWarpMap WITH (NOLOCK) WHERE MapIndex = @i_MapIndex
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0249
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0249
	@i_AccountName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT Password FROM atum2_db_account.dbo.td_account WITH (NOLOCK)
		WHERE AccountName = @i_AccountName AND IsBlocked = 0
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0250
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0250
	@i_GuildName		VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildName = @i_GuildName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0251
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0251
	@i_GuildCommanderUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildCommanderUniqueNumber = @i_GuildCommanderUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0252
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0252
	@i_GuildCommanderUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildDismemberDate FROM td_Guild WITH (NOLOCK) WHERE GuildUniqueNumber = @i_GuildCommanderUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0253
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0253
	@i_NewGuildName		VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildName = @i_NewGuildName
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SELECT GuildName FROM td_Guild WITH (NOLOCK) WHERE GuildName LIKE @i_NewGuildName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0254
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0254
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Character SET GuildName = '', GuildUniqueNumber = 0 WHERE uniqueNumber = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0255
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0255
	@i_FriendName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT CharacterName, Race, InfluenceType FROM td_Character WITH (NOLOCK) WHERE CharacterName = @i_FriendName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0256
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0256
	@i_CharacterName	VARCHAR(20),
	@i_FriendName		VARCHAR(20),
	@i_Type				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT CharacterName FROM td_FriendList WITH (NOLOCK) WHERE CharacterName = @i_CharacterName AND FriendName = @i_FriendName AND Type = @i_Type
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SELECT CharacterName FROM td_FriendList WITH (NOLOCK) WHERE CharacterName LIKE @i_CharacterName AND FriendName LIKE @i_FriendName AND Type = @i_Type
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0257
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0257
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT * FROM atum2_db_account.dbo.ti_Item WITH (NOLOCK)
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0259
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0259
	@i_AccountUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_accountcashstore WHERE AccountUniqueNumber = @i_AccountUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0260
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0260
	@i_ItemNum					INT,
	@i_UpdatedTime				VARCHAR(30),
	@i_ExpireTime				VARCHAR(30),
	@i_AccountUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_accountcashstore SET ItemNum = @i_ItemNum, UpdatedTime = @i_UpdatedTime, ExpireTime = @i_ExpireTime WHERE AccountUniqueNumber = @i_AccountUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0261
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0261
	@i_EventUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE atum2_db_account.dbo.ti_HappyHourEvent WHERE uniquenumber = @i_EventUniqueNumber
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0262
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0262
	@i_tmWeek					INT,
	@i_STTime					VARCHAR(30),
	@i_EDTime					VARCHAR(30),
	@i_InflTy					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
	INSERT atum2_db_account.dbo.ti_HappyHourEvent(ServerGroupID, dayofweek, starttime, endtime, exprate, SPIRate, exprepairrate
		, DropItemRate, DropRareItemRate, WarPointRate, InfluenceType, MinLevel, MaxLevel) 
		values( 0, @i_tmWeek, @i_STTime, @i_EDTime, 0, 0, 0, 0, 0, 0, @i_InflTy, 1, 100)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0263
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0263
	@i_STTime					VARCHAR(30),
	@i_EDTime					VARCHAR(30),
	@i_EventUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.ti_HappyHourEvent SET starttime = @i_STTime, endtime = @i_EDTime where UniqueNumber= @i_EventUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0264
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0264
	@i_tmWeek					INT,
	@i_STTime					VARCHAR(30),
	@i_EDTime					VARCHAR(30),
	@i_fEXPRate2				float,
	@i_fSPIRate2				float,
	@i_fEXPRepairRate2			float,
	@i_fDropItemRate2			float,
	@i_fDropRareItemRate2		float,
	@i_fWarPointRate2			float
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate ����
	INSERT atum2_db_account.dbo.ti_HappyHourEvent(ServerGroupID, dayofweek, starttime, endtime, exprate, SPIRate, exprepairrate, DropItemRate, DropRareItemRate, WarPointRate, MinLevel, MaxLevel) 
	VALUES( 0, @i_tmWeek, @i_STTime, @i_EDTime, @i_fEXPRate2, @i_fSPIRate2, @i_fEXPRepairRate2, @i_fDropItemRate2, @i_fDropRareItemRate2, @i_fWarPointRate2, 1, 100)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0265
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0265
	@i_STTime					VARCHAR(30),
	@i_EDTime					VARCHAR(30),
	@i_fEXPRate2				float,
	@i_fSPIRate2				float,
	@i_fEXPRepairRate2			float,
	@i_fDropItemRate2			float,
	@i_fDropRareItemRate2		float,
	@i_fWarPointRate2			float,
	@i_EventUniqueNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-12-24 by cmkwon, ��Ű Gameforge4D_Tur ���� i���ڸ� ��ҹ��� �����ؾ� �� - SPIRate, DropItemRate, DropRareItemRate ����
	UPDATE atum2_db_account.dbo.ti_HappyHourEvent SET starttime= @i_STTime, endtime= @i_EDTime, exprate= @i_fEXPRate2, SPIRate= @i_fSPIRate2, exprepairrate= @i_fEXPRepairRate2
		, DropItemRate= @i_fDropItemRate2, DropRareItemRate= @i_fDropRareItemRate2, WarPointRate= @i_fWarPointRate2 WHERE UniqueNumber= @i_EventUniqueNumber
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0266
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - ���� �߰� �� �ʵ� �߰� ó��
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_PROCEDURE_080827_0266]
	@i_ItemEventType			INT,
	@i_OnlyPCBang				INT,
	@i_byInfluenceType			TINYINT,
	@i_ItemNum				INT,
	@i_Count				INT,
	@i_STTime				VARCHAR(30),
	@i_EDTime				VARCHAR(30),
	@i_MemberShip				BIT,
	@i_ReqLevel				TINYINT,
	@i_NewMember				BIT,
	@i_UnitKind				INT,
	@i_PrefixCodeNum			INT,
	@i_SuffixCodeNum			INT,
	@i_UseLastGameEndDate			INT,
	@i_atLastGameEndDate			VARCHAR(30),
	@i_CheckWithCharacterUID		INT,				-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - 
	@i_LevelMin				INT,
	@i_LevelMax				INT,				-- // 2010-06-15 by jskim �����뺰 �α��� �̺�Ʈ �߰�
	@i_LoginCheckNumber		INT,				-- // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���� �߰�
	@i_UseFixedPeriod			INT,				-- // 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
	@i_FixedPeriod				INT					-- // 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
--WITH EXECUTE AS 'proexe'
AS
	INSERT into atum2_db_account.dbo.ti_ItemEvent (ItemEventType,OnlyPCBang,InfluenceType,ItemNum,[Count],StartTime,EndTime,MemberShip,
							ReqLevel,NewMember,UnitKind,PrefixCodeNum,SuffixCodeNum,UseLastGameEndDate,LastGameEndDate,CheckWithCharacterUID,LevelMin,LevelMax,LoginCheckNumber,
							UseFixedPeriod, FixedPeriod) 
	values( @i_ItemEventType, @i_OnlyPCBang, @i_byInfluenceType, @i_ItemNum, @i_Count, @i_STTime, @i_EDTime, @i_MemberShip, 
							@i_ReqLevel, @i_NewMember, @i_UnitKind, @i_PrefixCodeNum, @i_SuffixCodeNum, @i_UseLastGameEndDate, @i_atLastGameEndDate, @i_CheckWithCharacterUID, @i_LevelMin, @i_LevelMax, @i_LoginCheckNumber,
							@i_UseFixedPeriod, @i_FixedPeriod)

	-- 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
	-- ��� �μ�Ʈ�� UID��ȣ�� ����
	SELECT @@IDENTITY
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0267
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--				// 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - �α��� �̺�Ʈ ���� ���� �߰� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_PROCEDURE_080827_0267
	@i_ItemEventUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckItemEventType INT;
	SELECT @CheckItemEventType=ItemEventType FROM atum2_db_account.dbo.ti_itemevent WHERE ItemEventUID = @i_ItemEventUID
	DELETE atum2_db_account.dbo.ti_itemevent WHERE ItemEventUID = @i_ItemEventUID
	if(7 = @CheckItemEventType) -- üũŸ�� 7�� �α��� �̺�Ʈ�̴�. ���� ������ �ʿ��ϴ�.
	DELETE FROM atum2_db_account.dbo.td_LoginEvent

	-- 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
	-- ������ �̺�Ʈ ����Ʈ�� ���� �� �� ���� Ÿ�Ե� ���� ����
	DELETE FROM atum2_db_account.dbo.td_ItemEventSubType WHERE ItemEventUID = @i_ItemEventUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0268
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--						-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - ���� �߰� �� �ʵ� �߰� ó��
--> 121015_DB��Ű��_(ItemEvent_Update_����_����)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_PROCEDURE_080827_0268]
	@i_ItemEventType				INT,
	@i_OnlyPCBang				INT,
	@i_byInfluenceType			TINYINT,
	@i_ItemNum					INT,
	@i_Count					INT,
	@i_STTime					VARCHAR(30),
	@i_EDTime					VARCHAR(30),
	@i_MemberShip				BIT,
	@i_ReqLevel					TINYINT,
	@i_NewMember				BIT,
	@i_UnitKind					INT,
	@i_PrefixCodeNum			INT,
	@i_SuffixCodeNum			INT,
	@i_UseLastGameEndDate		INT,
	@i_atLastGameEndDate		VARCHAR(30),
	@i_ItemEventUID				INT,
	@i_CheckWithCharacterUID	INT,				-- // 2009-11-19 by cmkwon, ������ �̺�Ʈ�� Account/Character üũ ��� �߰� - �ʵ� �߰� �� �� �˻� ����� �߰�
	@i_LevelMin					INT,			   	-- // 2010-06-16 by jskim
	@i_LevelMax					INT,
	@i_LoginCheckNumber			INT,				-- // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ���� - ���� �߰�
	@i_UseFixedPeriod			INT,				-- // 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
	@i_FixedPeriod				INT					-- // 2013-02-28 by bckim, �������� �����߰� ��� �����Ⱓ �߰�
--WITH EXECUTE AS 'proexe'
AS
	UPDATE atum2_db_account.dbo.ti_ItemEvent SET ItemEventType = @i_ItemEventType, OnlyPCBang = @i_OnlyPCBang, InfluenceType = @i_byInfluenceType, ItemNum = @i_ItemNum, Count = @i_Count
			, StartTime = @i_STTime, EndTime = @i_EDTime, MemberShip = @i_MemberShip, ReqLevel = @i_ReqLevel, NewMember = @i_NewMember, UnitKind = @i_UnitKind
			, PrefixCodeNum = @i_PrefixCodeNum, SuffixCodeNum = @i_SuffixCodeNum, UseLastGameEndDate= @i_UseLastGameEndDate, LastGameEndDate= @i_atLastGameEndDate, CheckWithCharacterUID = @i_CheckWithCharacterUID, LevelMin = @i_LevelMin,  LevelMax = @i_LevelMax, LoginCheckNumber = @i_LoginCheckNumber
			, UseFixedPeriod = @i_UseFixedPeriod, FixedPeriod = @i_FixedPeriod
	WHERE ItemEventUID = @i_ItemEventUID;
GO

--> 130116_DB��Ű��_(���� ������ ������ ���� �� ���� ���� ������Ʈ)_DBQuery(atum2_db_[n]&atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0269
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
-- 2013-01-08 by jhseol, �������� �������� ���� �� �ǰ����� �������� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_PROCEDURE_080827_0269]
	@i_UpdateTime				VARCHAR(30),
	@i_NextWarTimeSet			TINYINT,
	@i_byInfluence				TINYINT,
	@i_nGuildUID				INT,
	@i_nOutPostMap				INT,
	@i_nCityMap					INT,
	@i_byInfluence2				TINYINT,
	@i_nGuildUID2				INT,
	@i_nCityMap2				INT
--WITH EXECUTE AS 'proexe'
AS	
BEGIN
	UPDATE dbo.td_OutPostInfo 
			SET OutPostNextWarTime = @i_UpdateTime, OutPostNextWarTimeSet = @i_NextWarTimeSet, OutPostGetInfl = @i_byInfluence, OutPostGuildUID = @i_nGuildUID
			WHERE OutPostMapIndex = @i_nOutPostMap AND OutPostCityMapIndex = @i_nCityMap
			UPDATE dbo.td_CityLeaderInfo 
			SET Influence = @i_byInfluence2, CharacterUID = (SELECT GuildCommanderUniqueNumber FROM dbo.td_Guild WHERE GuildUniqueNumber = @i_nGuildUID2) 
			WHERE MapIndex = @i_nCityMap2

-- 2013-01-08 by jhseol, �������� �������� ���� �� �ǰ����� �������� �߰�
	DECLARE @BCU_CountInfl INT
	DECLARE @ANI_CountInfl INT

	SET @BCU_CountInfl = (SELECT count(*) FROM dbo.td_CityLeaderInfo WHERE Influence = 2 AND MapIndex <> 2001 )
	SET @ANI_CountInfl = (SELECT count(*) FROM dbo.td_CityLeaderInfo WHERE Influence = 4 AND MapIndex <> 2002 )

-- 10 => 1%, 5 => 0.5%
	UPDATE dbo.td_CityLeaderInfo
	SET	ExpediencyFundRate = 10 + (@BCU_CountInfl * 5)
	WHERE MapIndex = 2001

	UPDATE dbo.td_CityLeaderInfo
	SET	ExpediencyFundRate = 10 + (@ANI_CountInfl * 5)
	WHERE MapIndex = 2002
-- end 2013-01-08 by jhseol, �������� �������� ���� �� �ǰ����� �������� �߰�
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_get_connecting_ServerGroupID
-- DESC				: // 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - 
--						�ش� ������ ���� ���� ServerGroupID �� �����Ѵ�. ���ӿ� ���� ������ ���θ� �Ǵ� �� �� �ִ�.
-- Result Set		: [ConnectingServerGroupID INT]
--						[ConnectingServerGroupID INT] ==> ServerGroupID, 0 �̰ų� NULL �̸� ���� ���� �ƴϸ� �� �̿ܿ��� �ش� ������ Ư�� �������� ���� ���� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_getConnectingServerGroupID
	@i_AccName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ConnectingServerGroupID
	FROM atum2_db_account.dbo.td_account WITH(NOLOCK)
	WHERE AccountName = @i_AccName
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertStoreItem_FromWeb
-- DESC				: // 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - �߰� ������.
--							// 2008-11-26 by cmkwon, ��ī���ͺ� �����۵� 20�� ������ �߰� �ǵ��� ����
--							///////////////////////////////////
--							// WEAR
--							#define WEAR_NOT_ATTACHED				0	// ������
--							#define WEAR_ATTACHED					1	// ����
--							
--							///////////////////////////////////////////////////////////////////////////////
--							// 2005-12-07 by cmkwon
--							#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--							#define ITEM_IN_STORE					1	// â��
--							#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--							
--							@i_ItemWindowIndex ����, �Ʒ��� 99�� �����ϸ� �⺻������ ���� ����, �ٸ� ������ ������ų���� �ʿ�
--							#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
-- Parameter		: @i_CharUID			INT			==> �ش� ĳ������ ������ȣ(CharacterUID)
--					  @i_ItemNum			INT			==> �߰� �� �������� ItemNum
--					  @i_CurrentCount		INT			==> �߰� �� �������� ����, ī���ͺ� �������� �ƴϸ� �ִ� 20�� ������ �߰� ������
--					  @i_ItemStorage		TINYINT		==> �߰� �� ��ġ�� 0�̸� ĳ������ �κ�, 1�̸� ĳ������ â����, ITEM_IN_XXX�� ����
--					  @i_Wear				TINYINT		==> �߰��� ��ġ�� ĳ������ �κ��϶��� â�� ���θ� ��Ÿ����, WEAR_XXX�� ����
--					  @i_ItemWindowIndex	INT			==> â�� �����϶����� ��ȿ�ϸ�, â�����°� �ƴϸ� 99�� �����ϸ� �ȴ�.
--					  @i_IsBuyCashItem	TINYINT			==> ������ �߰��� ĳ�������� ���ſ� ���� �߰� ������ ����, �ش� ���� ���� �α� �߰� ��ġ�� �޶�����.
-- Result Set		: [ErrorCode INT] [InsertedItemUID BIGINT]
--						[ErrorCode INT]	==> 0 �̸� ����, 0 �� �ƴϸ� ������ ������ ����
--											8452 ���� â�� �������� �߰� �Ұ�
--											9219 �ش� ĳ���Ͱ� ���ų� ���� ������ ĳ�����̴�.
--											8203 �ش� ������ ���ӿ� ���� ���� �����̴�.
--											9348 �ش� ItemNum �� ���ų� �߰� �Ҽ� ���� ItemNum ��
--											8463 DB�� ������ �߰��� ���� �߻� ��
--		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - 
--		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
--		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
--		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_insertStoreItem_FromWeb
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT,
	@i_ItemStorage		TINYINT,
	@i_Wear				TINYINT,
	@i_ItemWindowIndex	INT,
	@i_IsBuyCashItem	TINYINT			-- // 2009-04-22 by cmkwon, (ĳ���� ��û)������ ĳ�������� ���� ���� - ĳ���޿��� ���ſ� ���� �߰����� ����
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- ĳ�����κ�, ĳ���� â�� ������ �߰��� ����, ����â�� ������ �߰��� �������� �ʴ´�.
	IF (0 <> @i_ItemStorage) AND (1 <> @i_ItemStorage)
	BEGIN
		-- #define ERR_DB_INVALID_PARAMETER						0x2104		// �Ķ���� �� �̻�, 22018
		SELECT 8452, 0;		
	END
	IF (0 >= @i_CurrentCount)
	BEGIN
		-- #define ERR_DB_INVALID_PARAMETER						0x2104		// �Ķ���� �� �̻�, 22018
		SELECT 8452, 0;		
	END

	-- �ش� CharUID�� ��ȿ���� üũ
		--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID		INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384 )
	IF @AccUID IS NULL
	BEGIN
		-- #define ERR_PROTOCOL_INVALID_CHARACTER_UNIQUENUMBER		0x2403		// CharacterUniqueNumber�� ��ȿ���� ����
		SELECT 9219, 0;
		RETURN;
	END

	-- // 2009-04-22 by cmkwon, (ĳ���� ��û)������ ĳ�������� ���� ���� - ĳ���� �κ�ü �߰��ÿ��� ������ ���� ���θ� üũ�Ѵ�.
	IF (0 = @i_ItemStorage)
	BEGIN
		-- �ش� ����(AccountName)�� ���� ������ ���� üũ, 
		DECLARE @ConnectingServerGroupID INT
		SET @ConnectingServerGroupID = (SELECT ConnectingServerGroupID FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID)
		IF (@ConnectingServerGroupID IS NOT NULL) AND (0 <> @ConnectingServerGroupID)
		BEGIN
			-- #define ERR_COMMON_CONNECTING_GAME						0x200B		// 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - ���ӿ� ���� ���̴�.
			SELECT 8203, 0;
			RETURN
		END
	END
	ELSE
	BEGIN
		SET @i_Wear				= 0;	-- ������
		SET @i_ItemWindowIndex	= 99;	-- ������
	END

	-- #define ITEM_ATTR_CASH_ITEM_PREMIUM_CARD		0x00020000		// 131072, // 2008-08-26 by cmkwon, ItemAttribute �߰� - �����(�����̾�) ������,  
	DECLARE @ItemKd				TINYINT;
	DECLARE @ItemAttri			BIGINT;
	DECLARE @ItemCharging		SMALLINT;
	DECLARE @ItemEndur			FLOAT;
	DECLARE @InsertedItemUID	BIGINT;

	SELECT @ItemKd= Kind, @ItemAttri= ItemAttribute, @ItemCharging= Charging, @ItemEndur= Endurance FROM atum2_db_account.dbo.ti_Item WITH(NOLOCK) WHERE ItemNum = @i_ItemNum;
	IF (@ItemKd IS NULL) OR (0 <> @ItemAttri & 131072)
	BEGIN
		-- #define ERR_PROTOCOL_INVALID_ITEMNUM					0x2484		// ItemNum�� �߸��Ǿ���
		SELECT 9348, 0;
		RETURN
	END

	IF (0 <> dbo.atum_IsCountableItem(@ItemKd)) 
	BEGIN
		-- ī���ͺ� ������ ó��
		-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - �Ʒ��� ���� ����
		-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
		INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @i_CurrentCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

		IF (0 <> @@error)
		BEGIN
			-- #define ERR_DB_INSERT_QUERY_ERROR						0x210F		// 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - 
			SELECT 8463, 0;
			RETURN
		END
		
		SET @InsertedItemUID = SCOPE_IDENTITY();

		-- // 2009-04-22 by cmkwon, (ĳ���� ��û)������ ĳ�������� ���� ���� - ĳ�������� ���� ���ο� ���� �α׸� ���� �߰��Ѵ�.
		IF (0 = @i_IsBuyCashItem)
		BEGIN
			-- �α� �����
			-- #define T1_FL_LOG_ITEM_GET_ITEM					0x21	// 33 - Drop Item ����
			EXEC atum_log_insert_item_get_throw 33, @i_CharUID, 0, @InsertedItemUID, @i_ItemNum, @i_CurrentCount, @i_CurrentCount
		END
		ELSE
		BEGIN
			-- ĳ�� ������ ���� �α� �����
			-- #define T1_FL_LOG_ITEM_BUY_ITEM					0x25	// 37 - ������ ����
			EXEC atum_log_insert_item_buy_sell 37, @i_CharUID, 0, @InsertedItemUID, @i_ItemNum, @i_CurrentCount, @i_CurrentCount, -1
		END
	END
	ELSE
	BEGIN
		-- ��ī���ͺ� ������ ó��(�ִ� 20�� ������ �߰� ������)
		IF (20 < @i_CurrentCount)
		BEGIN
			-- #define ERR_OVER_COUNT									0x4013		// 2006-07-26 by cmkwon
			SELECT 16403, 0;
			RETURN
		END

		DECLARE @CurCount	INT;
		SET @CurCount		= 1;
		IF (0 <> dbo.atum_IsChargableItem(@ItemKd))
		BEGIN
			IF (@ItemCharging IS NULL)
			BEGIN
				-- #define ERR_DB_INVALID_PARAMETER						0x2104		// �Ķ���� �� �̻�, 22018
				SELECT 8452, 0;
				RETURN
			END

			SET @CurCount = @ItemCharging;
		END

		DECLARE @i			INT;
		SET @i				= 0;
		WHILE (@i < @i_CurrentCount)
		BEGIN

			-- // 2009-08-25 by cmkwon, ������� �ʴ� �ʵ� ����(td_Store.ScarcityNumber) - �Ʒ��� ���� ����
			-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
			-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Main���� ������ UID �߰�
			-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
			INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
				VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @CurCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);
			
			IF (0 <> @@error)
			BEGIN
				-- #define ERR_DB_INSERT_QUERY_ERROR						0x210F		// 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - 
				SELECT 8463, 0;
				RETURN
			END
			
			SET @InsertedItemUID	= SCOPE_IDENTITY();

			SET @i					= @i + 1;

			-- // 2009-04-22 by cmkwon, (ĳ���� ��û)������ ĳ�������� ���� ���� - ĳ�������� ���� ���ο� ���� �α׸� ���� �߰��Ѵ�.
			IF (0 = @i_IsBuyCashItem)
			BEGIN
				-- �α� �����
				-- #define T1_FL_LOG_ITEM_GET_ITEM					0x21	// 33 - Drop Item ����
				EXEC atum_log_insert_item_get_throw 33, @i_CharUID, 0, @InsertedItemUID, @i_ItemNum, @i_CurrentCount, @i
			END
			ELSE
			BEGIN
				-- ĳ�� ������ ���� �α� �����
				-- #define T1_FL_LOG_ITEM_BUY_ITEM					0x25	// 37 - ������ ����
				EXEC atum_log_insert_item_buy_sell 37, @i_CharUID, 0, @InsertedItemUID, @i_ItemNum, @i_CurrentCount, @i_CurrentCount, -1
			END
		END
	END

	-- ��� �ѱ��
	SELECT 0, @InsertedItemUID;
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_ValidCheck_td_MysteryItemDropCount
-- DESC      : 2008-11-25 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ValidCheck_td_MysteryItemDropCount
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_MysteryItemDropCount WHERE MysteryItemDropNum NOT IN 
	(SELECT MysteryItemDropNum FROM atum2_db_account.dbo.ti_MysteryItemDrop WITH(NOLOCK))
GO

--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_load_ti_MysteryItemDropByOmi
-- DESC      : 2008-11-25 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_MysteryItemDropByOmi
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT MysteryItemDropNum,ReqUnitKind,ReqMinLevel,ReqMaxLevel,DropItemNum
			,MinCount,MaxCount,Probability,PrefixProbability,SuffixProbability,Period	-- // 2008-12-30 by dhjin, ��Ű�ӽ� - Ŭ���̾�Ʈ ����Ʈ ó�� ���� ����
	FROM atum2_db_account.dbo.ti_MysteryItemDrop WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_LuckyItem_DropCount
-- DESC				: ��Ű�ӽ� ������ �� ������Ʈ
-- 2008-11-04 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_LuckyItem_DropCount
	@i_MysteryItemDropNum	INT,
	@i_DropItemNum			INT,
	@i_ServerGroupID		INT,
	@i_DropCount			INT				
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CheckCount INT
	SET @CheckCount = (SELECT count(*) FROM atum2_db_account.dbo.td_MysteryItemDropCount WITH (NOLOCK) WHERE MysteryItemDropNum = @i_MysteryItemDropNum AND ServerGroupID = @i_ServerGroupID AND DropItemNum = @i_DropItemNum)
	IF (0 = @CheckCount)
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_MysteryItemDropCount (MysteryItemDropNum, DropItemNum, ServerGroupID, DropCount) 
		VALUES (@i_MysteryItemDropNum, @i_DropItemNum, @i_ServerGroupID, @i_DropCount)
		RETURN;
	END

	UPDATE atum2_db_account.dbo.td_MysteryItemDropCount SET DropCount = DropCount + @i_DropCount 
	WHERE MysteryItemDropNum = @i_MysteryItemDropNum AND ServerGroupID = @i_ServerGroupID AND DropItemNum = @i_DropItemNum
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_LuckyItem_STARTTIME
-- DESC				: ��Ű�ӽ� ���۽ð� ������Ʈ
-- 2008-11-04 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_LuckyItem_STARTTIME
	@i_MysteryItemDropNum	INT,
	@i_StartTime			VARCHAR(30)				
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.ti_MysteryItemDrop SET starttime = @i_StartTime
	WHERE MysteryItemDropNum = @i_MysteryItemDropNum
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_LuckyItem_DropCount_Reset
-- DESC				: ��Ű�ӽ� ��������� �ʱ�ȭ
-- 2008-11-04 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_LuckyItem_DropCount_Reset
	@i_MysteryItemDropNum	INT				
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_MysteryItemDropCount SET DropCount = 0
	WHERE MysteryItemDropNum = @i_MysteryItemDropNum
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME: dbo.atum_load_ti_LuckyMachine
-- DESC			 : 2008-11-10 by dhjin,
--					// 2009-03-03 by dhjin, ��Ű�ӽ� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_LuckyMachine
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT BuildingIndex,MachineKind,MachineNum,CoinItemNum,SlotNum,SlotProbability,MysteryItemDropNum
	FROM atum2_db_account.dbo.ti_LuckyMachine WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_LuckyItem_DropCount_AllReset_ByAdminTool
-- DESC				: ��Ű�ӽ� ��������� ���� �ʱ�ȭ
-- 2008-12-01 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_LuckyItem_DropCount_AllReset_ByAdminTool				
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_MysteryItemDropCount SET DropCount = 0
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_LuckyItem_DropCount_ServerGroupIDReset_ByAdminTool
-- DESC				: ��Ű�ӽ� ��������� ServerID�� �ʱ�ȭ
-- 2008-12-01 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_LuckyItem_DropCount_ServerGroupIDReset_ByAdminTool	
	@i_ServerGroupID	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_MysteryItemDropCount SET DropCount = 0
	WHERE ServerGroupID = @i_ServerGroupID
GO


--------------------------------------------------------------------------------
-- TABLE NAME: dbo.atum_load_ti_LuckyMachineByOmi
-- DESC      : // 2009-03-03 by dhjin, ��Ű�ӽ� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_load_ti_LuckyMachineByOmi
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT MachineOrder, BuildingIndex, MachineKind, MachineNum, CoinItemNum, SlotNum, SourceIndex, Description
	FROM atum2_db_account.dbo.ti_LuckyMachine WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_AdminAutoNoticeInfo
-- DESC				: // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - atum_Load_AdminAutoNoticeInfo() ���ν��� �߰�
--						�ڵ� ���� ���� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_AdminAutoNoticeInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS	
	SELECT UsingFlag,LoopSec,IntervalSec,EditorAccountName
	FROM atum2_db_account.dbo.td_AdminAutoNoticeInfo WITH(NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Update_AdminAutoNoticeInfo
-- DESC				: // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - atum_Update_AdminAutoNoticeInfo() ���ν��� �߰�
--						�ڵ� ���� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_AdminAutoNoticeInfo
	@i_UsingFlag			INT,
	@i_LoopSec				INT,
	@i_IntervalSec			INT,
	@i_EditorAccountName	VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_AdminAutoNoticeInfo;

	INSERT INTO atum2_db_account.dbo.td_AdminAutoNoticeInfo (UsingFlag,LoopSec,IntervalSec,EditorAccountName)
	VALUES (@i_UsingFlag, @i_LoopSec, @i_IntervalSec, @i_EditorAccountName);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_AdminAutoNoticeString
-- DESC				: // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - atum_Load_AdminAutoNoticeString() ���ν��� �߰�
--						��� ���� ��Ʈ�� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_AdminAutoNoticeString
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS	
	SELECT NoticeStringIndex,NoticeString
	FROM atum2_db_account.dbo.td_AdminAutoNoticeString WITH(NOLOCK)
	ORDER BY NoticeStringIndex;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_AdminAutoNoticeString
-- DESC				: // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - atum_Load_AdminAutoNoticeString() ���ν��� �߰�
--						��� ���� ��Ʈ�� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_AdminAutoNoticeString
	@i_bDeleteOldNoticeString	INT,
	@i_NoticeStringIndex		INT,
	@i_NoticeString				VARCHAR(256)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS

	-- // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - @i_bDeleteOldNoticeString�� TRUE�̸� ���� �����͸� ��� �����Ѵ�.
	IF (0 <> @i_bDeleteOldNoticeString)
	BEGIN
		DELETE FROM atum2_db_account.dbo.td_AdminAutoNoticeString;		
	END

	-- // 2009-01-14 by cmkwon, ��� �ڵ� ���� �ý��� ���� - Notice String�� �߰��Ѵ�.
	INSERT INTO atum2_db_account.dbo.td_AdminAutoNoticeString (NoticeStringIndex,NoticeString)
	VALUES (@i_NoticeStringIndex, @i_NoticeString);
GO

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_CreateCharacter_FromWeb
-- DESC				: // 2009-01-21 by cmkwon, ������ ��� ������ ĳ���� ���� ���ν��� �߰� - dbo.atum_CreateCharacter_FromWeb() �߰�, Arario ��û
-- Result Set		: [ErrorCode, INT] [Inserted CharacterUID, BIGINT]
--						[ErrorCode INT]	==> 0 �̸� ����, 0 �� �ƴϸ� ������ ������ ����
--											8452 ����(AccountName Ȥ�� CharacterName Ȥ�� i_PilotFace)�� ��ȿ���� ����
--											9220 i_UnitKind�� ��ȿ���� ����
--											9232 �ش� ������ ��ȿ���� ����
--											8203 �ش� ������ ���ӿ� ���� ���� �����̴�.
--											9248 �ش� ������ �̹� 3���� ĳ���Ͱ� �ִ�. ���̻� ĳ���� �����Ұ�
--											8195 �ش� ĳ���͸��� �̹� �����Ѵ�.
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_CreateCharacter_FromWeb
	@i_AccName			VARCHAR(20),		-- �ش� AccountName
	@i_CharName			VARCHAR(20),		-- ������ ���� CharacterName
	@i_UnitKind			INT,				-- ��� ����(BGear=1, MGear=16, AGear=256, IGear=4096)
	@i_PilotFace		TINYINT				-- ���Ϸ� �� (��ȿ�� ��, 0~5, 100~105)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	
	IF (@i_AccName IS NULL) OR (0 >= DATALENGTH(@i_AccName)) OR (20 <= DATALENGTH(@i_AccName))
		OR (@i_CharName IS NULL) OR (0 >= DATALENGTH(@i_CharName)) OR (20 <= DATALENGTH(@i_CharName))
	BEGIN
		-- #define ERR_DB_INVALID_PARAMETER						0x2104		// �Ķ���� �� �̻�, 22018
		SELECT 8452, 0;
		RETURN;
	END

	IF (0 <> @i_PilotFace) AND (1 <> @i_PilotFace) AND (2 <> @i_PilotFace) AND (3 <> @i_PilotFace) AND (4 <> @i_PilotFace) AND (5 <> @i_PilotFace)
		AND (100 <> @i_PilotFace) AND (101 <> @i_PilotFace) AND (102 <> @i_PilotFace) AND (103 <> @i_PilotFace) AND (104 <> @i_PilotFace) AND (105 <> @i_PilotFace)
	BEGIN
		-- #define ERR_DB_INVALID_PARAMETER						0x2104		// �Ķ���� �� �̻�, 22018
		SELECT 8452, 0;
		RETURN;
	END

	-- ��ȿ�� ������� üũ 
	-- #define UNITKIND_BT01				(USHORT)0x0001	// BT - 01��, B-GEAR, 1
	-- #define UNITKIND_OT01				(USHORT)0x0010	// OT - 01��, M-GEAR, 16
	-- #define UNITKIND_DT01				(USHORT)0x0100	// DT - 01��, A-GEAR, 256
	-- #define UNITKIND_ST01				(USHORT)0x1000	// ST - 01��, I-GEAR, 4096
	IF (1 <> @i_UnitKind) AND (16 <> @i_UnitKind) AND (256 <> @i_UnitKind) AND (4096 <> @i_UnitKind)
	BEGIN
		-- #define ERR_PROTOCOL_INVALID_UNITKIND					0x2404		// Unit Kind�� ��ȿ���� ����
		SELECT 9220, 0;
		RETURN;
	END

	-- �ش� AccountName�� ��ȿ���� üũ
	DECLARE @AccUID		INT;
	SET @AccUID = (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_AccName)
	IF (@AccUID IS NULL)
	BEGIN
		-- #define ERR_PROTOCOL_EMPTY_ACCOUNTNAME					0x2410		// AccountName�� ��ȿ���� ����
		SELECT 9232, 0;
		RETURN;
	END
	
	-- �ش� ����(AccountName)�� ���� ������ ���� üũ, 
	DECLARE @ConnectingServerGroupID INT;
	SET @ConnectingServerGroupID = (SELECT ConnectingServerGroupID FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID)
	IF (@ConnectingServerGroupID IS NOT NULL) AND (0 <> @ConnectingServerGroupID)
	BEGIN
		-- #define ERR_COMMON_CONNECTING_GAME						0x200B		// 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� - ���ӿ� ���� ���̴�.
		SELECT 8203, 0;
		RETURN
	END

	-- �������°� �ƴ� ĳ���� ���� üũ
	DECLARE @CharcCnts	INT;
	SET @CharcCnts = (SELECT COUNT(*) FROM dbo.td_Character WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID AND 0 = Race & 16384 )
	IF (@CharcCnts IS NOT NULL) AND (3 <= @CharcCnts)
	BEGIN
		-- #define ERR_PROTOCOL_ALREADY_MAX_CHARACTER				0x2420		// ���̻� Character�� ����� ����, �ִ� 3(SIZE_MAX_NUM_CHARACTER)
		SELECT 9248, 0;
		RETURN;
	END

	-- ĳ���͸��� �̹� �����ϴ��� üũ
	IF EXISTS(SELECT * FROM dbo.td_Character WITH(NOLOCK) WHERE CharacterName = @i_CharName)
	BEGIN
		-- #define ERR_COMMON_CHARACTER_ALREADY_EXISTS				0x2003
		SELECT 8195, 0;
		RETURN;
	END


	DECLARE @CharacterNameForSearch		VARCHAR(64);
	DECLARE @Gender						TINYINT;
	DECLARE @Race						SMALLINT;
	DECLARE @InfluenceType				TINYINT;
	DECLARE @SelectableInfluenceMask	TINYINT;
	DECLARE @CharacterMode				TINYINT;
	DECLARE @AutoStatType				TINYINT;
	DECLARE @AttackPart					SMALLINT;
	DECLARE @DefensePart				SMALLINT;
	DECLARE @FuelPart					SMALLINT;
	DECLARE @SoulPart					SMALLINT;
	DECLARE @ShieldPart					SMALLINT;
	DECLARE @DodgePart					SMALLINT;
	DECLARE @GuildName					VARCHAR(30);
	DECLARE @GuildUniqueNumber			INT;
	DECLARE @Level						TINYINT;
	DECLARE @Experience					FLOAT;
	DECLARE @BodyCondition				BIGINT;
	DECLARE @Propensity					INT;
	DECLARE @Status						TINYINT;
	DECLARE @PKWinPoint					SMALLINT;
	DECLARE @PKLossPoint				SMALLINT;
	DECLARE @Material					SMALLINT;
	DECLARE @HP							SMALLINT;
	DECLARE @DP							SMALLINT;
	DECLARE @SP							SMALLINT;
	DECLARE @EP							SMALLINT;
	DECLARE @PetName					VARCHAR(20);
	DECLARE @PetLevel					TINYINT;
	DECLARE @PetExperience				FLOAT;
	DECLARE @Position_X					FLOAT;
	DECLARE @Position_Y					FLOAT;
	DECLARE @Position_Z					FLOAT;
	DECLARE @MapIndex					SMALLINT;
	DECLARE @ChannelIndex				SMALLINT;
	DECLARE @MaxLevel					TINYINT;
	DECLARE @currentHP					FLOAT;
	DECLARE @currentDP					FLOAT;
	DECLARE @currentSP					SMALLINT;
	DECLARE @currentEP					FLOAT;
	DECLARE @bonusStat					TINYINT;
	DECLARE @bonusSkillPoint			TINYINT;
	DECLARE @lastPartyID				BIGINT;


	SET @CharacterNameForSearch			= '';
	SET @Gender							= 0;
	SET @Race							= 2;
	SET @InfluenceType					= 1;	-- #define INFLUENCE_TYPE_NORMAL				(BYTE)0x0001	// 2005-12-20 by cmkwon, ���������� �Ϲݱ�

	SET @SelectableInfluenceMask = (SELECT TOP 1 SelectableInfluenceMask FROM dbo.td_Character WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID);
	IF (@SelectableInfluenceMask IS NULL)
	BEGIN
		-- #define INFLUENCE_TYPE_VCN					(BYTE)0x0002	// 2005-12-20 by cmkwon, ���������� ���Ա�, ����(V.C.U: Vijuenill City United.)
		-- #define INFLUENCE_TYPE_ANI					(BYTE)0x0004	// 2005-12-20 by cmkwon, �˸��� ���Ա�, ����(�� �������� ���� -�˸��� ��Ƽ �ݶ���- (A.N.I: Anti Nationalism Influence))
		SET @SelectableInfluenceMask = 6;
	END

	SET @CharacterMode					= 1;	-- ĳ���͸��� ����
	SET @AutoStatType					= 0;	-- #define AUTOSTAT_TYPE_FREESTYLE					0	// ����� ������

	-- �� ���� ����
	-- #define UNITKIND_BT01				(USHORT)0x0001	// BT - 01��, B-GEAR, 1
	-- #define UNITKIND_OT01				(USHORT)0x0010	// OT - 01��, M-GEAR, 16
	-- #define UNITKIND_DT01				(USHORT)0x0100	// DT - 01��, A-GEAR, 256
	-- #define UNITKIND_ST01				(USHORT)0x1000	// ST - 01��, I-GEAR, 4096
	IF (1 = @i_UnitKind)
	BEGIN
		-- B-Gear	==> 3, 3, 3, 3, 3, 3
		SET @AttackPart		= 3;
		SET @DefensePart	= 3;
		SET @FuelPart		= 3;
		SET @SoulPart		= 3;
		SET @ShieldPart		= 3;
		SET @DodgePart		= 3;
	END
	ElSE IF (16 = @i_UnitKind)
	BEGIN
		-- M-Gear	==> 2, 4, 3, 4, 3, 2
		SET @AttackPart		= 2;
		SET @DefensePart	= 4;
		SET @FuelPart		= 3;
		SET @SoulPart		= 4;
		SET @ShieldPart		= 3;
		SET @DodgePart		= 2;
	END
	ELSE IF (256 = @i_UnitKind)
	BEGIN
		-- A-Gear	==> 4, 3, 3, 3, 4, 1
		SET @AttackPart		= 4;
		SET @DefensePart	= 3;
		SET @FuelPart		= 3;
		SET @SoulPart		= 3;
		SET @ShieldPart		= 4;
		SET @DodgePart		= 1;
	END
	ELSE -- (4096 = @i_UnitKind)
	BEGIN
		-- I-Gear	==> 4, 2, 3, 3, 2, 4
		SET @AttackPart		= 4;
		SET @DefensePart	= 2;
		SET @FuelPart		= 3;
		SET @SoulPart		= 3;
		SET @ShieldPart		= 2;
		SET @DodgePart		= 4;
	END

	SET @GuildName			= '';
	SET @GuildUniqueNumber	= 0;
	SET @Level				= 1;
	SET @Experience			= 0;
	SET @BodyCondition		= 2;	-- #define BODYCON_FLY_MASK				(BodyCond_t)0x0000000000000002		// ����
	SET @Propensity			= 0;
	SET @Status				= 0;
	SET @PKWinPoint			= 0;
	SET @PKLossPoint		= 0;
	SET @Material			= 0;
	SET @HP					= 600;	-- �⺻ 600
	SET @DP					= 120;	-- 4���� �ִ� 120
	SET @SP					= @ShieldPart * 8;
	SET @EP					= @FuelPart * 10;
	SET @PetName			= '';
	SET @PetLevel			= 0;
	SET @PetExperience		= 0;
	SET @Position_X			= 9171;
	SET @Position_Y			= 669;
	SET @Position_Z			= 4878;
	SET @MapIndex			= 8001;	-- #define TUTORIAL_MAP_INDEX							8001	// Ʃ�丮����� �ϳ��̹Ƿ� define�Ѵ�
	SET @ChannelIndex		= 0;
	SET @MaxLevel			= 1;
	SET @currentHP			= @HP;
	SET @currentDP			= @DP;
	SET @currentSP			= @SP;
	SET @currentEP			= @EP;
	SET @bonusStat			= 0;
	SET @bonusSkillPoint	= 0;
	SET @lastPartyID		= 0;

	EXEC dbo.atum_CreateCharacter @i_CharName,@CharacterNameForSearch,@i_AccName,@AccUID,@Gender,@Race,@i_UnitKind,@InfluenceType,@SelectableInfluenceMask,@i_PilotFace,@CharacterMode,@AutoStatType,@AttackPart,@DefensePart,@FuelPart,@SoulPart,@ShieldPart,@DodgePart,@GuildName,@GuildUniqueNumber,@Level,@Experience,@BodyCondition,@Propensity,@Status,@PKWinPoint,@PKLossPoint,@Material,@HP,@DP,@SP,@EP,@PetName,@PetLevel,@PetExperience,@Position_X,@Position_Y,@Position_Z,@MapIndex,@ChannelIndex,@MaxLevel,@currentHP,@currentDP,@currentSP,@currentEP,@bonusStat,@bonusSkillPoint,@lastPartyID;

	DECLARE @NewCharcUID	INT;
	SET @NewCharcUID = (SELECT UniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE AccountUniqueNumber = @AccUID AND CharacterName = @i_CharName);

	IF (@NewCharcUID IS NULL)
	BEGIN
		-- #define ERR_DB_INSERT_QUERY_ERROR						0x210F		// 2008-11-26 by cmkwon, �븸 Netpower_Tpe ������ ������ �߰� ���ν��� �߰� -
		SELECT 8463, 0;
		RETURN;
	END

	SELECT 0, @NewCharcUID;
GO
								
								
								

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_DeclarationOfWarInfo
-- DESC				: ���� ����
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_DeclarationOfWarInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime, MSWarStartTime,
			MSWarEndTime, SelectCount, GiveUp, MSWarEndState
	FROM dbo.td_DeclarationOfWar WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_DeclarationOfWarForbidTimeInfo
-- DESC				: ���� ���� �����ð� ��������
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_DeclarationOfWarForbidTimeInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT DayOfWeek, ForbidStartTime, ForbidEndTime
	FROM atum2_db_account.dbo.td_DeclarationOfWarForbidTime WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateStartDeclarationOfWar
-- DESC				: ���� ���� ���� ���� ���� �� ����.
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStartDeclarationOfWar
	@i_Influence			TINYINT, 
	@i_MSWarStep			TINYINT, 
	@i_NCP					INT,     
	@i_MSNum				INT,     
	@i_MSAppearanceMap		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_DeclarationOfWar SET NCP = @i_NCP, MSNum = @i_MSNum, MSAppearanceMap = @i_MSAppearanceMap
	WHERE Influence = @i_Influence AND MSWarStep = @i_MSWarStep
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateEndDeclarationOfWar
-- DESC				: ���� ���� ���� ���� ���� �� ����.
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateEndDeclarationOfWar
	@i_Influence			TINYINT, 
	@i_MSWarStep			TINYINT, 
	@i_MSWarEndTime			VARCHAR(30),
	@i_MSWarEndState		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_DeclarationOfWar SET MSWarEndTime = @i_MSWarEndTime, MSWarEndState = @i_MSWarEndState
	WHERE Influence = @i_Influence AND MSWarStep = @i_MSWarStep
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateMSWarStartTime
-- DESC				: ���� ���� ���� ���� �ð� ����
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateMSWarStartTime
	@i_Influence			TINYINT, 
	@i_MSWarStep			TINYINT,
	@i_MSWarStartTime		VARCHAR(30),
	@i_SelectCount			TINYINT,
	@i_GiveUp				BIT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_DeclarationOfWar SET MSWarStartTime = @i_MSWarStartTime, SelectCount = @i_SelectCount, GiveUp = @i_GiveUp
	WHERE Influence = @i_Influence AND MSWarStep = @i_MSWarStep
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateSelectCountDeclarationOfWarByAdminTool
-- DESC				: ���� ���� ���� ���� ���� �� ������Ʈ
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateSelectCountDeclarationOfWarByAdminTool
	@i_Influence			TINYINT, 
	@i_MSWarStep			TINYINT, 
	@i_SelectCount			TINYINT    
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_DeclarationOfWar SET SelectCount = @i_SelectCount
	WHERE Influence = @i_Influence AND MSWarStep = @i_MSWarStep
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateForbidTimeDeclarationOfWarByAdminTool
-- DESC				: ���� ���� ���� ���� ���� �� ������Ʈ
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateForbidTimeDeclarationOfWarByAdminTool
	@i_DayOfWeek				INT,
	@i_ForbidStartTime			VARCHAR(30),
	@i_ForbidEndTime			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE atum2_db_account.dbo.td_DeclarationOfWarForbidTime SET DayOfWeek = @i_DayOfWeek, ForbidStartTime = @i_ForbidStartTime
																, ForbidEndTime = @i_ForbidEndTime
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateStepDeclarationOfWarByAdminTool
-- DESC				: ���� ���� �ܰ� ����.
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateStepDeclarationOfWarByAdminTool
	@i_MSWarStep			TINYINT,
	@i_MSWarStartTime		VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (1 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
		SET @i_MSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = @i_MSWarStep)
		SET @i_MSWarStep = 2
	END
	IF (2 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
		SET @i_MSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = @i_MSWarStep)
		SET @i_MSWarStep = 3
	END
	IF (3 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
		SET @i_MSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = @i_MSWarStep)
		SET @i_MSWarStep = 4
	END
	IF (4 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
		SET @i_MSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = @i_MSWarStep)
		SET @i_MSWarStep = 5
	END
	IF (5 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
		SET @i_MSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = @i_MSWarStep)
		SET @i_MSWarStep = 99
	END
	IF (99 = @i_MSWarStep)
	BEGIN
		UPDATE dbo.td_DeclarationOfWar SET MSWarStepStartTime = @i_MSWarStartTime, MSWarStepEndTime = DateAdd(day, 7, @i_MSWarStartTime)
											, MSWarStartTime = DateAdd(day, 3, @i_MSWarStartTime)
		WHERE MSWarStep = @i_MSWarStep
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_ResetDeclarationOfWarByAdminTool
-- DESC				: ���� ���� ������ �ʱ�ȭ�� �ʱ�ȭ�ȴ�.
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ResetDeclarationOfWarByAdminTool
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_DeclarationOfWar WHERE MSWarStep = 1 or MSWarStep = 2 or MSWarStep = 3 or MSWarStep = 4 or MSWarStep = 5
	
	UPDATE dbo.td_DeclarationOfWar SET MSWarStep = 1 WHERE MSWarStep = 99

	DECLARE @tmMSWarStartTime datetime
	SET @tmMSWarStartTime = (SELECT MSWarStepEndTime FROM dbo.td_DeclarationOfWar WHERE Influence = 2 AND MSWarStep = 1)

	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (2, 2, 0, 0, 0, @tmMSWarStartTime, DateAdd(day, 7, @tmMSWarStartTime), DateAdd(day, 3, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (2, 3, 0, 0, 0, DateAdd(day, 7, @tmMSWarStartTime), DateAdd(day, 14, @tmMSWarStartTime), DateAdd(day, 10, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (2, 4, 0, 0, 0, DateAdd(day, 14, @tmMSWarStartTime), DateAdd(day, 21, @tmMSWarStartTime), DateAdd(day, 17, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (2, 5, 0, 0, 0, DateAdd(day, 21, @tmMSWarStartTime), DateAdd(day, 28, @tmMSWarStartTime), DateAdd(day, 24, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (2, 99, 0, 0, 0, DateAdd(day, 28, @tmMSWarStartTime), DateAdd(day, 35, @tmMSWarStartTime), DateAdd(day, 31, @tmMSWarStartTime), NULL, 3, 0, 0)

	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (4, 2, 0, 0, 0, @tmMSWarStartTime, DateAdd(day, 7, @tmMSWarStartTime), DateAdd(day, 3, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (4, 3, 0, 0, 0, DateAdd(day, 7, @tmMSWarStartTime), DateAdd(day, 14, @tmMSWarStartTime), DateAdd(day, 10, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (4, 4, 0, 0, 0, DateAdd(day, 14, @tmMSWarStartTime), DateAdd(day, 21, @tmMSWarStartTime), DateAdd(day, 17, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (4, 5, 0, 0, 0, DateAdd(day, 21, @tmMSWarStartTime), DateAdd(day, 28, @tmMSWarStartTime), DateAdd(day, 24, @tmMSWarStartTime), NULL, 3, 0, 0)
	INSERT INTO dbo.td_DeclarationOfWar (Influence, MSWarStep, NCP, MSNum, MSAppearanceMap, MSWarStepStartTime, MSWarStepEndTime
											, MSWarStartTime, MSWarEndTime, SelectCount, GiveUp, MSWarEndState)
		VALUES (4, 99, 0, 0, 0, DateAdd(day, 28, @tmMSWarStartTime), DateAdd(day, 35, @tmMSWarStartTime), DateAdd(day, 31, @tmMSWarStartTime), NULL, 3, 0, 0)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateMSWarStartDeclarationOfWarByAdminTool
-- DESC				: ���� ���� ���� ���� ���� �ð� ������Ʈ
-- 2009-01-14 by dhjin,
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateMSWarStartDeclarationOfWarByAdminTool
	@i_Influence			TINYINT, 
	@i_MSWarStep			TINYINT, 
	@i_MSWarStartTime		VARCHAR(30)   
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_DeclarationOfWar SET MSWarStartTime = @i_MSWarStartTime
	WHERE Influence = @i_Influence AND MSWarStep = @i_MSWarStep AND MSWarStepStartTime <= @i_MSWarStartTime AND MSWarStepEndTime >= @i_MSWarStartTime
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_CashShopBit
-- DESC				: // 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - atum_Load_CashShopBit() ���ν��� �߰�, ��õ��,�Ż�ǰ ������ ����Ʈ ��������
--						// 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - cs.RemainCountForLimitedEdition
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_CashShopBit
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2009-04-14 by cmkwon, ĳ���ް��� ���� ���� - ĳ�� ������ ��ϵ��� ���� ������ ����, -- ĳ�� ������ ��ϵ��� ���� ������ �����Ѵ�.
	-- #define CASH_SHOP_BUILDING_INDEX					9999		// ����ȭ ���� BuindNPCIndex
	SELECT i.ItemNum, i.ItemName, i.SummonMonster, cs.CashShopBit, cs.RemainCountForLimitedEdition
	FROM atum2_db_account.dbo.ti_Item i WITH(NOLOCK) INNER JOIN atum2_db_account.dbo.ti_Shop s WITH(NOLOCK) ON i.ItemNum = s.ItemNum LEFT OUTER JOIN atum2_db_account.dbo.td_CashShop cs WITH(NOLOCK) ON s.ItemNum = cs.ItemNum
	WHERE 9999 = s.Uniquenumber
	ORDER BY s.ShopOrder;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Update_CashShopBit
-- DESC				: // 2009-01-28 by cmkwon, ĳ���� ����(��õ��,�Ż�ǰ �߰�) - atum_Update_CashShopBit() ���ν��� �߰�, ��õ��,�Ż�ǰ ������ ����Ʈ ��������
--						// 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - 
--						// 2013-02-05 by bckim, ĳ�ü� ��õ�� ���ļ����ο�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_CashShopBit
	@i_ItemNum				INT,
	@i_CashShopBit			TINYINT,
	@i_RemainCount			INT								-- // 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - 
--WITH EXECUTE AS 'proexe'
AS
	DECLARE @itemNum INT;
	SET @itemNum = (SELECT ItemNum FROM atum2_db_account.dbo.td_CashShop WITH(NOLOCK) WHERE ItemNum = @i_ItemNum);
	IF (@itemNum IS NULL)
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_CashShop (ItemNum, CashShopBit, RemainCountForLimitedEdition)
		VALUES (@i_ItemNum, @i_CashShopBit, @i_RemainCount);
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.td_CashShop
		SET CashShopBit = @i_CashShopBit, RemainCountForLimitedEdition= @i_RemainCount
		WHERE ItemNum = @i_ItemNum;
	END

	-- by bckim
	IF ( @i_CashShopBit = 48 OR @i_CashShopBit = 16)
	BEGIN
		
		DECLARE @NewIndex INT

		SET @itemNum = (SELECT ItemNum FROM atum2_db_account.dbo.td_CashShop_Realignment_Index WITH(NOLOCK) WHERE ItemNum = @i_ItemNum);
		SET @NewIndex = (SELECT MAX(RealignmentIndex) FROM atum2_db_account.dbo.td_CashShop_Realignment_Index)

		IF (@itemNum IS NULL)
		BEGIN
			INSERT INTO atum2_db_account.dbo.td_CashShop_Realignment_Index (ItemNum, CashShopBit, RealignmentIndex)
			VALUES (@i_ItemNum, @i_CashShopBit, @NewIndex + 1 );
		END
		ELSE
		BEGIN
			UPDATE atum2_db_account.dbo.td_CashShop_Realignment_Index
			SET CashShopBit = @i_CashShopBit
			WHERE ItemNum = @i_ItemNum;
		END
	END
	ELSE
		BEGIN
		SET @itemNum = (SELECT ItemNum FROM atum2_db_account.dbo.td_CashShop_Realignment_Index WITH(NOLOCK) WHERE ItemNum = @i_ItemNum);
		IF (@itemNum IS NOT NULL)
		BEGIN
			DELETE FROM atum2_db_account.dbo.td_CashShop_Realignment_Index WHERE ItemNum = @i_ItemNum
		END
	END
GO

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_load_selfServiceInfo8ServerGroupName
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_load_selfServiceInfo8ServerGroupName
	@i_ServGroupID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TOP 1 ss.ServiceUID, ss.ServiceName, sg.ServerGroupNameforRK
	FROM atum2_db_account.dbo.td_wrk_selfServiceInfo ss WITH(NOLOCK), dbo.td_wrk_selfServerGroupInfo sg WITH(NOLOCK)
	WHERE sg.ServerGroupID = @i_ServGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_selfAllLevelRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_selfAllLevelRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_level
	WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_arrange_selfAllLevelRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--							#define SIZE_MAX_WRK_COUNT				100						// ���巩ŷ �ʼ� ��ŷ
--
--							#define RANKING_SCOPE_LOCAL				0		// ���� ���� ���� ��ŷ, Name �� NickName
--							#define RANKING_SCOPE_WORLD				1		// ���� ��ŷ ����, Name �� CharacterName
--						
--							#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--							#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--							#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--							#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--							#define UNITKIND_ALL_MASK			(USHORT)0xFFFF	// 65535
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_arrange_selfAllLevelRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT,
	@i_ServGroupName			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @RankScope TINYINT;

	-- Local Ranking, �� �� 100 ������
	SET @RankScope = 0;
	
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	-- World Ranking, �� �� 100 ������
	SET @RankScope = 1;
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Experience, LevelUpTime
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Experience DESC, LevelUpTime
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_LevelRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_LevelRanking
	@i_ServiceUID				INT,
	@i_RankScope				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (0 = @i_ServiceUID)
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope
						ORDER BY Experience DESC, LevelUpTime) t) t
		ORDER BY t.Experience DESC, t.LevelUpTime;
	END
	ELSE
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Experience DESC, LevelUpTime) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
						FROM atum2_db_account.dbo.td_wrk_level WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Experience DESC, LevelUpTime) t) t
		ORDER BY t.Experience DESC, t.LevelUpTime;
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_selfAllFameRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_selfAllFameRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_fame
	WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_arrange_selfAllFameRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--							#define SIZE_MAX_WRK_COUNT				100						// ���巩ŷ �ʼ� ��ŷ
--
--							#define RANKING_SCOPE_LOCAL				0		// ���� ���� ���� ��ŷ, Name �� NickName
--							#define RANKING_SCOPE_WORLD				1		// ���� ��ŷ ����, Name �� CharacterName
--						
--							#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--							#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--							#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--							#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--							#define UNITKIND_ALL_MASK			(USHORT)0xFFFF	// 65535
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_arrange_selfAllFameRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT,
	@i_ServGroupName			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @RankScope TINYINT;

	-- Local Ranking, �� �� 100 ������
	SET @RankScope = 0;
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC

	-- World Ranking, �� �� 100 ������
	SET @RankScope = 1;
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, Propensity
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Propensity DESC
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_FameRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_FameRanking
	@i_ServiceUID				INT,
	@i_RankScope				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (0 = @i_ServiceUID)
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope
						ORDER BY Fame DESC) t) t
		ORDER BY t.Fame DESC;
	END
	ELSE
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Fame DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
						FROM atum2_db_account.dbo.td_wrk_fame WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Fame DESC) t) t
		ORDER BY t.Fame DESC;
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_selfAllPVPRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_selfAllPVPRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_pvp
	WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServGroupID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_arrange_selfAllPVPRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--							#define SIZE_MAX_WRK_COUNT				100						// ���巩ŷ �ʼ� ��ŷ
--
--							#define RANKING_SCOPE_LOCAL				0		// ���� ���� ���� ��ŷ, Name �� NickName
--							#define RANKING_SCOPE_WORLD				1		// ���� ��ŷ ����, Name �� CharacterName
--						
--							#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--							#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--							#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--							#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--							#define UNITKIND_ALL_MASK			(USHORT)0xFFFF	// 65535
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_arrange_selfAllPVPRanking
	@i_ServiceUID				INT,
	@i_ServGroupID				INT,
	@i_ServGroupName			VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @RankScope TINYINT;

	-- Local Ranking, �� �� 100 ������
	SET @RankScope = 0;
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, CharacterName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC

	-- World Ranking, �� �� 100 ������
	SET @RankScope = 1;
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 15) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 240) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 3840) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score)
		SELECT TOP 100 @i_ServiceUID, @RankScope, @i_ServGroupID, @i_ServGroupName, UniqueNumber, NickName, UnitKind, InfluenceType, Level, PKWinPoint, PKLossPoint, (PKWinPoint*10-PKLossPoint*5) AS Score
		FROM dbo.td_Character WITH(NOLOCK)
		WHERE 0 <> (UnitKind & 61440) AND NickName IS NOT NULL AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) )
		AND  0 = (Race & 20352)		-- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
		ORDER BY Score DESC
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_PVPRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_PVPRanking
	@i_ServiceUID				INT,
	@i_RankScope				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (0 = @i_ServiceUID)
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope
						ORDER BY Score DESC) t) t
		ORDER BY Score DESC; 
	END
	ELSE
	BEGIN
		SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
		FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 15) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 240) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 3840) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Score DESC) t
				UNION 
				SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
				FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
						FROM atum2_db_account.dbo.td_wrk_pvp WITH(NOLOCK)
						WHERE 0 <> (UnitKind & 61440) AND RankingScope = @i_RankScope AND ServiceUID = @i_ServiceUID
						ORDER BY Score DESC) t) t
		ORDER BY Score DESC; 
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_allServiceInfo
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_allServiceInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ServiceUID, ServiceName, ServiceSymbolImage, SymbolImageSize
	FROM atum2_db_account.dbo.td_wrk_allServiceInfo WITH(NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_updateNickName
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_updateNickName
	@i_CharacUID				INT,
	@i_NickName					VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @CharUID INT;

	SET @CharUID = (SELECT UniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE NickName = @i_NickName);
	IF (@CharUID IS NOT NULL)
	BEGIN
		SELECT 1;
		RETURN;
	END

	UPDATE dbo.td_Character
	SET NickName = @i_NickName
	WHERE UniqueNumber = @i_CharacUID;
	
	IF (0 <> @@ERROR)
	BEGIN
		SELECT 1;
		RETURN;
	END

	SELECT 0;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_load_selfServiceInfo
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_load_selfServiceInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT s.ServiceUID, s.ServiceName, s.ServiceSymbolImage, s.SymbolImageSize
	FROM atum2_db_account.dbo.td_wrk_selfServiceInfo s
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_updateService_to_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_update_selfServiceInfo
	@i_ServiUID					INT,
	@i_ServiName				VARChAR(20),
	@i_SymbolImage				BINARY(2000),
	@i_SymbolImageSize			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_selfServiceInfo;

	INSERT INTO atum2_db_account.dbo.td_wrk_selfServiceInfo(ServiceUID,ServiceName,ServiceSymbolImage,SymbolImageSize)
	VALUES(@i_ServiUID, @i_ServiName, @i_SymbolImage,@i_SymbolImageSize);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_selfServiceInfo
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_selfServiceInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_selfServiceInfo;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_load_ServerGroupInfo_forWRK
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_load_ServerGroupInfo_forWRK
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ServerGroupID, ServerGroupNameforRK
	FROM dbo.td_wrk_selfServerGroupInfo WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_update_ServerGroupInfo_forWRK
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_update_ServerGroupInfo_forWRK
	@i_ServGID					INT,
	@i_ServGName				VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_wrk_selfServerGroupInfo;

	INSERT INTO dbo.td_wrk_selfServerGroupInfo(ServerGroupID, ServerGroupNameforRK)
	VALUES(@i_ServGID, @i_ServGName);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_AllServiceList
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_AllServiceList
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_allServiceInfo;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_ServiceInfo
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_insert_ServiceInfo
	@i_ServiUID					INT,
	@i_ServiName				VARCHAR(20),
	@i_SymbolImage				BINARY(2000),
	@i_SymbolImageSize			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.td_wrk_allServiceInfo(ServiceUID, ServiceName, ServiceSymbolImage,SymbolImageSize)
	VALUES(@i_ServiUID, @i_ServiName, @i_SymbolImage, @i_SymbolImageSize);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_otherAllLevelRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_otherAllLevelRanking
	@i_ExcludeServiceUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_level
	WHERE ServiceUID <> @i_ExcludeServiceUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_otherAllFameRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_otherAllFameRanking
	@i_ExcludeServiceUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_fame
	WHERE ServiceUID <> @i_ExcludeServiceUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_otherAllPVPRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_otherAllPVPRanking
	@i_ExcludeServiceUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.td_wrk_pvp
	WHERE ServiceUID <> @i_ExcludeServiceUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_LevelRanker
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_insert_LevelRanker
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_Experience				FLOAT,
	@i_LevelUpTime				DATETIME
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.td_wrk_level(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,Experience,LevelUpTime)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_Experience,@i_LevelUpTime);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_FameRanker
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_insert_FameRanker
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_Fame						INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.td_wrk_fame(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,Fame)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_Fame);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_PVPRanker
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_insert_PVPRanker
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_WinPoint					INT,
	@i_LossPoint				INT,
	@i_Score					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.td_wrk_pvp(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,WinPoint,LossPoint,Score)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_WinPoint,@i_LossPoint,@i_Score);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_delete_ServerGroupInfo_forWRK
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_delete_ServerGroupInfo_forWRK
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_wrk_selfServerGroupInfo;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_SelfLevelRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_SelfLevelRanking
	@i_CharcUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @Experi			FLOAT;
	DECLARE @LevelUpTime	DATETIME;

	SELECT @Experi= Experience, @LevelUpTime= LevelUpTime
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE UniqueNumber = @i_CharcUID;

	SELECT COUNT(*) + 1
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE (Experience > @Experi OR (Experience = @Experi AND LevelUpTime < @LevelUpTime)) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) AND (0 = (Race & 20352)) ); -- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_SelfFameRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_SelfFameRanking
	@i_CharcUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @SelfFame			INT;

	SELECT @SelfFame= Propensity
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE UniqueNumber = @i_CharcUID;

	SELECT COUNT(*) + 1
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE (Propensity > @SelfFame) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) AND (0 = (Race & 20352)) ); -- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_get_SelfPVPRanking
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - 
--					  // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrk_get_SelfPVPRanking
	@i_CharcUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @SelfScore		INT;

	SELECT @SelfScore= (PKWinPoint*10-PKLossPoint*5)
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE UniqueNumber = @i_CharcUID;

	SELECT COUNT(*) + 1
	FROM dbo.td_Character WITH(NOLOCK)
	WHERE ((PKWinPoint*10-PKLossPoint*5) > @SelfScore) AND ( AccountName NOT IN (SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) AND (0 = (Race & 20352)) ); -- // 2012-01-03 by hskim, ������ �� ���� �����ʹ� ���� ���� �߰�
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_QuestMaching
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_QuestMatching
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT QuestIndexForBCU, QuestIndexForANI
	FROM atum2_db_account.dbo.ti_QuestMatching WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_ItemMaching
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_ItemMatching
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemNumForBCU, ItemNumForANI
	FROM atum2_db_account.dbo.ti_ItemMatching WITH(NOLOCK)
GO

--> 130605_DB��Ű��_03_(��������Ʈ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Init_InfluenceType_AllCharacter
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
--						
--						#define QUEST_STATE_NONE			(BYTE)0		// �������� ���� ����
--						#define QUEST_STATE_IN_PROGRESS		(BYTE)1		// ������
--						#define QUEST_STATE_COMPLETED		(BYTE)2		// �Ϸ�
--
--						#define QUEST_INDEX_OF_SELECT_INFLUENCE				112
--						 // 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
--						 // 2013-05-09 by hskim, ���� ����Ʈ ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_Init_InfluenceType_AllCharacter]
--WITH EXECUTE AS 'proexe'	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	-- �����ʱ�ȭ�� �����忡�� �Ű����� ������ �α׸� ���� ������ ���
	-- // 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
	INSERT [atum_Temporary_Initialized_Guild_List] 
	(AccountUniqueNumber,AccountName,CharacterUniqueNumber,CharacterName,ItemUniqueNumber,ItemNum,Kind,CurrentCount,GuildUniqueNumber,GuildName )	
	SELECT c.AccountUniqueNumber, c.AccountName, c.UniqueNumber, c.CharacterName, s.UniqueNumber, s.ItemNum, i.Kind, s.CurrentCount, g.GuildUniqueNumber, g.GuildName
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g 
	ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c 
	ON g.GuildCommanderUniqueNumber = c.UniqueNumber INNER JOIN [atum2_db_account].[dbo].[ti_ItemInfo] i
	ON i.[ItemNum] = s.ItemNum
	WHERE s.ItemStorage = 2

	-- ���� â���� �������� �ش� ������ �������� â��� �̵�
	UPDATE dbo.td_Store
		SET AccountUniqueNumber = c.AccountUniqueNumber, Possess = c.UniqueNumber, ItemStorage = 1
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c ON g.GuildCommanderUniqueNumber = c.UniqueNumber
	WHERE s.ItemStorage = 2



	-- BCU,ANI ���� ĳ������ �������� �̼��� �����Ѵ�.
	-- ���� ������ ĳ���͵� ���� ó���Ѵ�.
	-- // 2009-04-30 by cmkwon, ���� �ʱ�ȭ ���� ���� - ������ �̼��� ���� ��� ī��Ʈ���� �����Ѵ�.
	DELETE dbo.td_CharacterQuestMonsterCount
	FROM dbo.td_Character c INNER JOIN dbo.td_CharacterQuest cq ON c.UniqueNumber = cq.CharacterUniqueNumber INNER JOIN dbo.td_CharacterQuestMonsterCount cqm ON cq.QuestIndex = cqm.QuestIndex
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1
	DELETE dbo.td_CharacterQuest
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1


	-- BCU,ANI ���� ĳ������ ���� ���� �̼��� ���������� �����Ѵ�.
	UPDATE dbo.td_CharacterQuest
		SET QuestState = 1
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestIndex = 112


	-- BCU,ANI ���� ĳ���Ϳ� ���� ���� �̼��� ���ٸ� ���� ���·� �߰��Ѵ�.
	INSERT INTO dbo.td_CharacterQuest
		SELECT UniqueNumber, 112, 1, 0, GetDate(), 0
		FROM  dbo.td_Character
		WHERE (InfluenceType = 2 OR InfluenceType = 4) AND UniqueNumber NOT IN(SELECT CharacterUniqueNumber FROM dbo.td_CharacterQuest WITH(NOLOCK) WHERE QuestIndex = 112)


	-- ��� ĳ������ ���°� ���ð����� ������ �ش� ������ �����Ѵ�.
	-- // 2009-10-12 by cmkwon, ������ī ���� ��� ���� - �Ϲݼ��� ���ø� ���� ����
	UPDATE dbo.td_Character
		SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode= 1, GuildName='', GuildUniqueNumber = 0, MapIndex = Material, ChannelIndex = 0, Position_X = 9290 , Position_Y = 673 , Position_Z = 4993

	-- ��� ����, ���ܸ��, ģ�� ����Ʈ�� �����Ѵ�.
	DELETE dbo.td_Guild;
	DELETE dbo.td_GuildMember;
	DELETE dbo.td_FriendList;

	-- �����ʱ�ȭ�ÿ� ���� ���� ������ ����
	UPDATE dbo.td_InfluenceWarData SET ConsecutiveVictories = 0
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Init_InfluenceType_ByAccountUID
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
--						
--						#define QUEST_STATE_NONE			(BYTE)0		// �������� ���� ����
--						#define QUEST_STATE_IN_PROGRESS		(BYTE)1		// ������
--						#define QUEST_STATE_COMPLETED		(BYTE)2		// �Ϸ�
--
--						#define QUEST_INDEX_OF_SELECT_INFLUENCE				112
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Init_InfluenceType_ByAccountUID
	@i_AccUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- �ش� ������ BCU,ANI ���� ĳ������ �������� �̼��� �����Ѵ�.
	-- ���� ������ ĳ���͵� ���� ó���Ѵ�.
	-- // 2009-04-30 by cmkwon, ���� �ʱ�ȭ ���� ���� - ������ �̼��� ���� ��� ī��Ʈ���� �����Ѵ�.
	DELETE dbo.td_CharacterQuestMonsterCount
	FROM dbo.td_Character c INNER JOIN dbo.td_CharacterQuest cq ON c.UniqueNumber = cq.CharacterUniqueNumber INNER JOIN dbo.td_CharacterQuestMonsterCount cqm ON cq.QuestIndex = cqm.QuestIndex
	WHERE c.AccountUniqueNumber = @i_AccUID AND (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1
	DELETE dbo.td_CharacterQuest
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE c.AccountUniqueNumber = @i_AccUID AND (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1


	-- �ش� ������ BCU,ANI ���� ĳ������ ���� ���� �̼��� ���������� �����Ѵ�.
	UPDATE dbo.td_CharacterQuest
		SET QuestState = 1
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE c.AccountUniqueNumber = @i_AccUID AND (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestIndex = 112


	-- �ش� ������ BCU,ANI ���� ĳ���Ϳ� ���� ���� �̼��� ���ٸ� ���� ���·� �߰��Ѵ�.
	INSERT INTO dbo.td_CharacterQuest
		SELECT UniqueNumber, 112, 1, 0, GetDate(), 0
		FROM  dbo.td_Character
		WHERE AccountUniqueNumber = @i_AccUID AND (InfluenceType = 2 OR InfluenceType = 4) AND UniqueNumber NOT IN(SELECT c.UniqueNumber 
																		FROM dbo.td_Character c WITH(NOLOCK) INNER JOIN dbo.td_CharacterQuest cq WITH(NOLOCK) ON c.UniqueNumber = cq.CharacterUniqueNumber
																		WHERE c.AccountUniqueNumber = @i_AccUID AND cq.QuestIndex = 112)


	-- �ش� ������ ĳ������ ���°� ���ð����� ������ �ش� ������ �����Ѵ�.
	-- // 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
	--UPDATE dbo.td_Character
	--	SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode=1, GuildName='', GuildUniqueNumber = 0, ChannelIndex = 0, Position_X = 9290 , Position_Y = 673 , Position_Z = 4993
	--WHERE AccountUniqueNumber = @i_AccUID
	-- // 2009-10-12 by cmkwon, ������ī ���� ��� ���� - �Ϲݼ��� ���ø� ���� ����
	UPDATE dbo.td_Character
		SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode=1, GuildName='', GuildUniqueNumber = 0, ChannelIndex = 0, Position_X = 1830 , Position_Y = 303 , Position_Z = 5288
	WHERE AccountUniqueNumber = @i_AccUID AND Material <> 2002;
	UPDATE dbo.td_Character
		SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode=1, GuildName='', GuildUniqueNumber = 0, ChannelIndex = 0, Position_X = 1093 , Position_Y = 961 , Position_Z = 5283
	WHERE AccountUniqueNumber = @i_AccUID AND Material = 2002;


	-- ���ܸ������Ʈ���� �ش� ������ ĳ���͸� �����Ѵ�.
	DELETE dbo.td_GuildMember
	FROM dbo.td_GuildMember gm INNER JOIN dbo.td_Character c ON c.UniqueNumber = gm.CharacterUniqueNumber
	WHERE c.AccountUniqueNumber = @i_AccUID;

	-- ģ��/�ź� ����Ʈ���� �ش� ������ ĳ���͸� �����Ѵ�.
	DELETE dbo.td_FriendList
	FROM dbo.td_FriendList fl INNER JOIN dbo.td_Character c ON c.CharacterName = fl.CharacterName OR c.CharacterName = fl.FriendName
	WHERE c.AccountUniqueNumber = @i_AccUID;

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_QuestMaching
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ChangeQuestIndex
	@i_CharcUID					INT,
	@i_FromQuestIndex			INT,
	@i_ToQuestIndex				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_CharacterQuest
		SET QuestIndex = @i_ToQuestIndex
	WHERE CharacterUniqueNumber = @i_CharcUID AND QuestIndex = @i_FromQuestIndex;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Load_QuestMaching
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - �ش� ĳ������ â�� �����۸� ó���Ѵ�.
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_ChangeItemWithItemMatching
	@i_CharcUID					INT,
	@i_InflTy					TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (@i_InflTy = 2)
	BEGIN
		-- change Influence Type from ANI to BCU
		UPDATE dbo.td_Store
			SET ItemNum = im.ItemNumForBCU
		FROM dbo.td_Store s INNER JOIN atum2_db_account.dbo.ti_ItemMatching im ON s.ItemNum = im.ItemNumForANI
		WHERE s.Possess = @i_CharcUID AND s.ItemStorage = 1
	END
	ELSE IF (@i_InflTy = 4)
	BEGIN
		-- change Influence Type from BCU to ANI
		UPDATE dbo.td_Store
			SET ItemNum = im.ItemNumForANI
		FROM dbo.td_Store s INNER JOIN atum2_db_account.dbo.ti_ItemMatching im ON s.ItemNum = im.ItemNumForBCU
		WHERE s.Possess = @i_CharcUID AND s.ItemStorage = 1		
	END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_check_enableChangeInfluence
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_check_enableChangeInfluence
	@i_AccUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @i_tmCharUID INT;
	SET @i_tmCharUID = (SELECT TOP 1 c.UniqueNumber FROM td_Character c WITH(NOLOCK) INNER JOIN dbo.td_Guild g WITH(NOLOCK) ON c.UniqueNumber = g.GuildCommanderUniqueNumber WHERE c.AccountUniqueNumber = @i_AccUID);
	IF (@i_tmCharUID IS NOT NULL)
	BEGIN
		-- �ش� ������ ĳ���� �߿� �������� ĳ���Ͱ� �ִ�.
		-- #define ERR_DELETE_CHARACTER_GUILDCOMMANDER				0x404E		// 2008-10-20 by dhjin, �������� �ɸ��� ���� �Ұ��� ����
		SELECT 16462;
		RETURN;
	END
	
	SET @i_tmCharUID = NULL;
	SET @i_tmCharUID = (SELECT TOP 1 c.UniqueNumber FROM td_Character c WITH(NOLOCK) INNER JOIN dbo.td_InfluenceWarData iw WITH(NOLOCK) ON c.UniqueNumber = iw.InflLeaderCharacterUID OR c.UniqueNumber = iw.InflSub1LeaderCharacterUID OR c.UniqueNumber = InflSub2LeaderCharacterUID WHERE c.AccountUniqueNumber = @i_AccUID);
	IF (@i_tmCharUID IS NOT NULL)
	BEGIN
		-- �ش� ������ ĳ���� �߿� ������ Ȥ�� ���������� ĳ���Ͱ� �ִ�.
		-- #define ERR_PROTOCOL_SUBLEADER_SET_ALEADY				0x4111		// 2007-10-06 by dhjin, �������ڰ� �̹� ���� �Ǿ�����
		SELECT 16657;
		RETURN;
	END

	SET @i_tmCharUID = NULL;
	SET @i_tmCharUID = (SELECT TOP 1 c.UniqueNumber FROM td_Character c WITH(NOLOCK) INNER JOIN dbo.td_LeaderCandidate lc WITH(NOLOCK) ON c.UniqueNumber = lc.CharacterUID WHERE c.AccountUniqueNumber = @i_AccUID);

	IF (@i_tmCharUID IS NOT NULL)
	BEGIN
		-- �ش� ������ ĳ���� �߿� ������ �ĺ��� ĳ���Ͱ� �ִ�.
		-- #define ERR_REQ_REG_LEADER_CANDIDATE					0x404C		// 2007-11-20 by dhjin, ������ �ĺ��� ����� �Ǿ��ִ�.
		SELECT 16460;
		RETURN;
	END
	
	SELECT 0;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_getAccountUID_byAccountName
-- DESC				: // 2009-07-07 by cmkwon, �ε� ���ʷ����� ���� �ذ� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_getAccountUID_byAccountName
	@i_AccName		VARCHAR(20)		-- 
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT AccountUniqueNumber
	FROM atum2_db_account.dbo.td_account WITH(NOLOCK)
	WHERE AccountName = @i_AccName;
GO


--------------------------------------------------------------
-- ti_Item ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- Desc: // 2001-08-01 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
-- ====

CREATE PROCEDURE [dbo].[atum_import_ti_item]
	@ItemNum			INT,
	@Kind				TINYINT,
	@ItemName			VARCHAR(40),
	@AbilityMin			FLOAT,
	@AbilityMax			FLOAT,
	@ReqRace			SMALLINT,
	@ReqAttackPart		SMALLINT,
	@ReqDefensePart		SMALLINT,
	@ReqFuelPart		SMALLINT,
	@ReqSoulPart		SMALLINT,
	@ReqShieldPart		SMALLINT,
	@ReqDodgePart		SMALLINT,
	@ReqUnitKind		INT,
	@ReqMinLevel		TINYINT,
	@ReqMaxLevel		TINYINT,
	@ReqItemKind		TINYINT,
	@Weight				SMALLINT,
	@HitRate			FLOAT,		-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
	@Defense			TINYINT,
	@FractionResistance	FLOAT,		-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
	@NaturalFaction		TINYINT,
	@SpeedPenalty		TINYINT,
	@Range				SMALLINT,
	@Position			TINYINT,
	@Scarcity			TINYINT,
	@Endurance			FLOAT,
	@AbrasionRate		TINYINT,
	@Charging			SMALLINT,
	@Luck				TINYINT,
	@MinTradeQuantity	SMALLINT,
	@Price				INT,
	@CashPrice			INT,
	@DestParameter1		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue1	FLOAT,
	@DestParameter2		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue2	FLOAT,
	@DestParameter3		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue3	FLOAT,
	@DestParameter4		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue4	FLOAT,
	@DestParameter5		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue5	FLOAT,
	@DestParameter6		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue6	FLOAT,
	@DestParameter7		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue7	FLOAT,
	@DestParameter8		SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@ParameterValue8	FLOAT,
	@ReAttacktime		INT,
	@Time				INT,
	@RepeatTime			SMALLINT,
	@Material			SMALLINT,
	@ReqMaterial		SMALLINT,
	@RangeAngle			FLOAT,
	@UpgradeNum			TINYINT,
	@LinkItem			INT,
	@MultiTarget		TINYINT,
	@ExplosionRange		SMALLINT,
	@ReactionRange		SMALLINT,
	@ShotNum			TINYINT,
	@MultiNum			TINYINT,
	@AttackTime			SMALLINT,
	@ReqSP				TINYINT,
	@SummonMonster		INT,
	@NextSkill			INT,
	@SkillLevel			TINYINT,
	@SkillHitRate		TINYINT,
	@SkillType			TINYINT,
	@SkillTargetType	TINYINT,
	@Caliber			TINYINT,
	@OrbitType			TINYINT,
	@ItemAttribute		BIGINT,		-- // 2009-09-23 by cmkwon, Excel to DB ���� �ڷ��� ���� ���� - 
	@BoosterAngle		FLOAT,
	@CameraPattern		INT,
	@SourceIndex		INT,
	@Description		VARCHAR(200),
	@EnchantCheckDestParam		TINYINT,		-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	@InvokingDestParamID		INT,			-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	@InvokingDestParamIDByUse	INT				-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ItemInfo(ItemNum, Kind, ItemName, AbilityMin, AbilityMax, ReqRace, ReqAttackPart, ReqDefensePart,
						 ReqFuelPart, ReqSoulPart, ReqShieldPart, ReqDodgePart, ReqUnitKind, ReqMinLevel, 
						 ReqMaxLevel, ReqItemKind, Weight, HitRate, Defense, FractionResistance, NaturalFaction,
						 SpeedPenalty, Range, Position, Scarcity, Endurance, AbrasionRate, Charging, Luck,
						 MinTradeQuantity, Price, CashPrice, DestParameter1, ParameterValue1, DestParameter2,
						 ParameterValue2, DestParameter3, ParameterValue3, DestParameter4,
						 ParameterValue4, DestParameter5, ParameterValue5, DestParameter6,
						 ParameterValue6, DestParameter7, ParameterValue7, DestParameter8,
						 ParameterValue8, ReAttacktime, Time, RepeatTime, Material, ReqMaterial,
						 RangeAngle, UpgradeNum, LinkItem, MultiTarget, ExplosionRange, ReactionRange,
						 ShotNum, MultiNum, AttackTime, ReqSP, SummonMonster, NextSkill, SkillLevel,
						 SkillHitRate, SkillType, SkillTargetType, Caliber, OrbitType, ItemAttribute,
						 BoosterAngle, CameraPattern, SourceIndex, Description, 
						 EnchantCheckDestParam, InvokingDestParamID, InvokingDestParamIDByUse)	-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
	VALUES (@ItemNum, @Kind, @ItemName, round(@AbilityMin,2), round(@AbilityMax,2), @ReqRace, @ReqAttackPart, @ReqDefensePart,
                @ReqFuelPart, @ReqSoulPart, @ReqShieldPart, @ReqDodgePart, @ReqUnitKind, @ReqMinLevel,
                @ReqMaxLevel, @ReqItemKind, @Weight, @HitRate, @Defense, @FractionResistance, @NaturalFaction,
                @SpeedPenalty, @Range, @Position, @Scarcity, @Endurance, @AbrasionRate, @Charging, @Luck,
		@MinTradeQuantity, @Price, @CashPrice, @DestParameter1, round(@ParameterValue1,2), @DestParameter2,
		round(@ParameterValue2,2), @DestParameter3, round(@ParameterValue3,2), @DestParameter4,
		round(@ParameterValue4,2), @DestParameter5, round(@ParameterValue5,2), @DestParameter6,
		round(@ParameterValue6,2), @DestParameter7, round(@ParameterValue7,2), @DestParameter8,
		round(@ParameterValue8,2), @ReAttacktime, @Time, @RepeatTime, @Material, @ReqMaterial,
		round(@RangeAngle,2), @UpgradeNum, @LinkItem, @MultiTarget, @ExplosionRange, @ReactionRange,
		@ShotNum, @MultiNum, @AttackTime, @ReqSP, @SummonMonster, @NextSkill, @SkillLevel,
		@SkillHitRate, @SkillType, @SkillTargetType, @Caliber, @OrbitType, @ItemAttribute,
		round(@BoosterAngle,2), @CameraPattern, @SourceIndex, @Description,
		@EnchantCheckDestParam, @InvokingDestParamID, @InvokingDestParamIDByUse)	-- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
GO

--------------------------------------------------------------
-- ti_Item ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_item
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ItemInfo
GO

--------------------------------------------------------------
-- ti_MonsterItem ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--			-- // 2010-04-09 by cmkwon, ����2�� �߰� ����(�ܰ躰 ���� �߰�) - DropType �ʵ� �߰�
-- ====
CREATE PROCEDURE dbo.atum_import_ti_monsteritem
	@i_MonsterUniqueNumber		INT,
	@i_ItemNum					INT,
	@i_MinCount					INT,
	@i_MaxCount					INT,
	@i_Probability				INT,
	@i_PrefixProbability		INT,
	@i_SuffixProbability		INT,
	@i_DropType					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_MonsterItem(MonsterUniqueNumber, ItemNum, MinCount, MaxCount, Probability, PrefixProbability, SuffixProbability,DropType)
	VALUES (@i_MonsterUniqueNumber,@i_ItemNum,@i_MinCount,@i_MaxCount,@i_Probability,@i_PrefixProbability,@i_SuffixProbability,@i_DropType);
GO

--------------------------------------------------------------
-- ti_MonsterItem ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_monsteritem
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_MonsterItem
GO

--------------------------------------------------------------
-- ti_RareItemInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_rareiteminfo
	@CodeNum			INT,
	@Name				VARCHAR(30),	-- // 2009-09-23 by cmkwon, �±� ������ ���� ���� ������ ���� - 
	@ReqUseType			INT,
	@ReqMinLevel		INT,
	@ReqMaxLevel		INT,
	@ReqItemKind		TINYINT,
	@ReqAttackPart		SMALLINT,
	@ReqDefensePart		SMALLINT,
	@ReqDodgePart		SMALLINT,
	@ReqFuelPart		SMALLINT,
	@ReqShieldPart		SMALLINT,
	@ReqSoulPart		SMALLINT,
	@DesParameter1		TINYINT,
	@ParameterValue1	FLOAT,
	@DesParameter2		TINYINT,
	@ParameterValue2	FLOAT,
	@DesParameter3		TINYINT,
	@ParameterValue3	FLOAT,
	@DesParameter4		TINYINT,
	@ParameterValue4	FLOAT,
	@DesParameter5		TINYINT,
	@ParameterValue5	FLOAT,
	@DesParameter6		TINYINT,
	@ParameterValue6	FLOAT,
	@DesParameter7		TINYINT,
	@ParameterValue7	FLOAT,
	@DesParameter8		TINYINT,
	@ParameterValue8	FLOAT,
	@DesParameter9		TINYINT,
	@ParameterValue9	FLOAT,
	@Probability		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_RareItemInfo(CodeNum, Name, ReqUseType, ReqMinLevel, ReqMaxLevel, ReqItemKind, ReqAttackPart,
							 ReqDefensePart, ReqDodgePart, ReqFuelPart, ReqShieldPart, ReqSoulPart, DesParameter1, ParameterValue1, DesParameter2,
							 ParameterValue2, DesParameter3, ParameterValue3, DesParameter4, ParameterValue4, DesParameter5, ParameterValue5,
							 DesParameter6, ParameterValue6, DesParameter7, ParameterValue7, DesParameter8, ParameterValue8, DesParameter9,
							 ParameterValue9, Probability)
	VALUES (@CodeNum, @Name, @ReqUseType, @ReqMinLevel, @ReqMaxLevel, @ReqItemKind, @ReqAttackPart,
		@ReqDefensePart, @ReqDodgePart, @ReqFuelPart, @ReqShieldPart, @ReqSoulPart, @DesParameter1,
		round(@ParameterValue1,2), @DesParameter2, round(@ParameterValue2,2), @DesParameter3,
		round(@ParameterValue3,2), @DesParameter4, round(@ParameterValue4,2), @DesParameter5,
		round(@ParameterValue5,2), @DesParameter6, round(@ParameterValue6,2), @DesParameter7,
		round(@ParameterValue7,2), @DesParameter8, round(@ParameterValue8,2), @DesParameter9,
		round(@ParameterValue9,2), @Probability)
GO

--------------------------------------------------------------
-- ti_RareItemInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_rareiteminfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_RareItemInfo
GO

--------------------------------------------------------------
-- ti_Shop ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_shop
	@ShopOrder			INT,
	@UniqueNumber		INT,
	@ItemNum			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_Shop(ShopOrder, UniqueNumber, ItemNum)
	VALUES (@ShopOrder, @UniqueNumber, @ItemNum)
GO

--------------------------------------------------------------
-- ti_Shop ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_shop
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_Shop
GO

-------------------------------------------------------------
-- ti_CityTargetWarpMap ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_citytargetwarpmap
	@MapIndex			INT,
	@BuildingIndex		INT,
	@WarpTargetMapIndex	INT,
	@WarpTargetIndex	INT,
	@WarpTargetName		VARCHAR(40),
	@Fee				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_CityTargetWarpMap(MapIndex, BuildingIndex, WarpTargetMapIndex, WarpTargetIndex, WarpTargetName, Fee)
	VALUES (@MapIndex, @BuildingIndex, @WarpTargetMapIndex, @WarpTargetIndex, @WarpTargetName, @Fee)
GO

--------------------------------------------------------------
-- ti_CityTargetWarpMap ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_citytargetwarpmap
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_CityTargetWarpMap
GO

--> 130605_DB��Ű��_02_(�����۹̸�����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------
-- ti_ItemMixingInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--		 // 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo	
--		 // 2013-05-06 by hskim, ������ �̸� ���� (�Ӽ� �� �߰�)
-- ====
CREATE PROCEDURE [dbo].[atum_import_ti_itemmixinginfo]
	@UniqueID			INT,
	@TargetItemNum		INT,
	@MixingProbability	INT,
	@MixingCost			INT,
	@Visible			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	INSERT INTO atum2_db_account.dbo.ti_ItemMixingInfo(UniqueID, TargetItemNum, MixingProbability, MixingCost, Visible)
	VALUES (@UniqueID, @TargetItemNum, @MixingProbability, @MixingCost, @Visible)
END
GO

--------------------------------------------------------------
-- ti_ItemMixingInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_itemmixinginfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ItemMixingInfo
GO

--------------------------------------------------------------
-- ti_ItemMixingElement ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo	
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_itemmixingelement
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ItemMixingElement
GO

--------------------------------------------------------------
-- ti_ItemMixingElement ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--		 // 2012-02-20 by hskim, DB ����ȭ - ItemMixingInfo	
-- ====
CREATE PROCEDURE dbo.atum_import_ti_itemmixingelement
	@UniqueID			INT,
	@SourceItemNum		INT,
	@SourceItemCount	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ItemMixingElement(UniqueID, SourceItemNum, SourceItemCount)
	VALUES (@UniqueID, @SourceItemNum, @SourceItemCount)
GO

--------------------------------------------------------------
-- ti_EnchantInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_enchantinfo
	@EnchantItemNum		INT,
	@EnchantItemCount	INT,
	@EnchantCost		INT,
	@Prob1				INT,
	@Prob2				INT,
	@Prob3				INT,
	@Prob4				INT,
	@Prob5				INT,
	@Prob6				INT,
	@Prob7				INT,
	@Prob8				INT,
	@Prob9				INT,
	@Prob10				INT,
	@Prob11				INT,
	@Prob12				INT,
	@Prob13				INT,
	@Prob14				INT,
	@Prob15				INT,
	@Prob16				INT,
	@Prob17				INT,
	@Prob18				INT,
	@Prob19				INT,
	@Prob20				INT,
	@Prob21				INT,
	@Prob22				INT,
	@Prob23				INT,
	@Prob24				INT,
	@Prob25				INT,
	@Prob26				INT,
	@Prob27				INT,
	@Prob28				INT,
	@Prob29				INT,
	@Prob30				INT,
	@Prob31				INT,
	@Prob32				INT,
	@Prob33				INT,
	@Prob34				INT,
	@Prob35				INT,
	@Prob36				INT,
	@Prob37				INT,
	@Prob38				INT,
	@Prob39				INT,
	@Prob40				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_EnchantInfo(EnchantItemNum, EnchantItemCount, EnchantCost, Prob1, Prob2, Prob3, Prob4, Prob5,
					                Prob6, Prob7, Prob8, Prob9, Prob10, Prob11, Prob12, Prob13, Prob14, Prob15, Prob16,
					                Prob17, Prob18, Prob19, Prob20, Prob21, Prob22, Prob23, Prob24, Prob25, Prob26,
					                Prob27, Prob28, Prob29, Prob30, Prob31, Prob32, Prob33, Prob34, Prob35, Prob36,
					                Prob37, Prob38, Prob39, Prob40)
	VALUES (@EnchantItemNum, @EnchantItemCount, @EnchantCost, @Prob1, @Prob2, @Prob3, @Prob4, @Prob5,
                @Prob6, @Prob7, @Prob8, @Prob9, @Prob10, @Prob11, @Prob12, @Prob13, @Prob14, @Prob15, @Prob16,
                @Prob17, @Prob18, @Prob19, @Prob20, @Prob21, @Prob22, @Prob23, @Prob24, @Prob25, @Prob26,
                @Prob27, @Prob28, @Prob29, @Prob30, @Prob31, @Prob32, @Prob33, @Prob34, @Prob35, @Prob36,
                @Prob37, @Prob38, @Prob39, @Prob40)
GO

--------------------------------------------------------------
-- ti_EnchantInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_enchantinfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_EnchantInfo
GO

--------------------------------------------------------------
-- ti_StrategyPointSummonMapIndex ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_strategypointsummonmapindex
	@MapName			VARCHAR(40),
	@MapIndex			INT,
	@StratrgyPiontNum	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_StrategyPointSummonMapIndex(MapName, MapIndex, StratrgyPiontNum)
	VALUES (@MapName, @MapIndex, @StratrgyPiontNum)
GO

--------------------------------------------------------------
-- ti_StrategyPointSummonMapIndex ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_strategyoointsummonmapindex
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_StrategyPointSummonMapIndex
GO

--------------------------------------------------------------
-- ti_ArenaInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:	atum_import_ti_arenainfo
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--		 --> 2012-05-23 by jhseol, �Ʒ��� WP �⺻���޷� �ʵ� �߰�
-- ====
CREATE PROCEDURE dbo.atum_import_ti_arenainfo
	@ArenaMode				TINYINT,
	@ReqMemberNum			TINYINT,
	@PayInfluencePointWIN 	INT,
	@PayInfluencePointLOSE	INT,
	@PayWarPointWIN			INT,
	@PayWarPointLOSE		INT
	,@DefaultPayWarPointWIN		INT
	,@DefaultPayWarPointLOSE	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ArenaInfo(ArenaMode, ReqMemberNum, PayInfluencePointWIN, PayInfluencePointLOSE, PayWarPointWIN, PayWarPointLOSE, DefaultPayWarPointWIN, DefaultPayWarPointLOSE)
	VALUES (@ArenaMode, @ReqMemberNum, @PayInfluencePointWIN, @PayInfluencePointLOSE, @PayWarPointWIN, @PayWarPointLOSE, @DefaultPayWarPointWIN, @DefaultPayWarPointLOSE)
GO

--------------------------------------------------------------
-- ti_ArenaInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_arenainfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ArenaInfo
GO

--------------------------------------------------------------
-- ti_ArenaMapinfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--		// 2012-09-14 by jhseol, �Ʒ��� �߰����� part3 - �Ʒ��� ���� ������ �߰� (�Ʒ��� ���� ź�� ������ ī��)
-- ====
CREATE PROCEDURE dbo.atum_import_ti_arenamapinfo
	@ArenaMapIndex			INT,
	@ArenaMode				TINYINT,
	@ReqMemberNum 			TINYINT,
	@PlayLimitedTime		TINYINT,
	@WINCondition			TINYINT,
	@LvDSupplyItemNum1		INT,
	@LvDSupplyItemCount1	INT,
	@LvDSupplyItemNum2		INT,
	@LvDSupplyItemCount2	INT,
	@LvDSupplyItemNum3		INT,
	@LvDSupplyItemCount3	INT,
	@LvDSupplyItemNum4		INT,
	@LvDSupplyItemCount4	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ArenaMapinfo(ArenaMapIndex, ArenaMode, ReqMemberNum , PlayLimitedTime, WINCondition, LvDSupplyItemNum1,
							 LvDSupplyItemCount1, LvDSupplyItemNum2, LvDSupplyItemCount2, LvDSupplyItemNum3, LvDSupplyItemCount3, LvDSupplyItemNum4, LvDSupplyItemCount4)
	VALUES (@ArenaMapIndex, @ArenaMode, @ReqMemberNum , @PlayLimitedTime, @WINCondition, @LvDSupplyItemNum1,
		@LvDSupplyItemCount1, @LvDSupplyItemNum2, @LvDSupplyItemCount2, @LvDSupplyItemNum3, @LvDSupplyItemCount3, @LvDSupplyItemNum4, @LvDSupplyItemCount4)
GO

--------------------------------------------------------------
-- ti_ArenaMapinfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_arenamapinfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ArenaMapinfo
GO

--------------------------------------------------------------
-- ti_MysteryItemDrop ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_mysteryitemdrop
	@MysteryItemDropNum		INT,
	@ReqUnitKind			INT,
	@ReqMinLevel			TINYINT,
	@ReqMaxLevel			TINYINT,
	@DropItemNum			INT,
	@MinCount				INT,
	@MaxCount				INT,
	@Probability			INT,
	@PrefixProbability		INT,
	@SuffixProbability		INT,
	@Period					SMALLINT,
	@CountPerPeriod			INT,
	@Starttime				DATETIME
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_MysteryItemDrop(MysteryItemDropNum, ReqUnitKind, ReqMinLevel, ReqMaxLevel, DropItemNum, MinCount, MaxCount,
							    Probability, PrefixProbability, SuffixProbability, Period, CountPerPeriod, Starttime)
	VALUES (@MysteryItemDropNum, @ReqUnitKind, @ReqMinLevel, @ReqMaxLevel, @DropItemNum, @MinCount, @MaxCount,
		@Probability, @PrefixProbability, @SuffixProbability, @Period, @CountPerPeriod, @Starttime)
GO

--------------------------------------------------------------
-- ti_MysteryItemDrop ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_mysteryitemdrop
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_MysteryItemDrop
GO

--------------------------------------------------------------
-- ti_InfluenceWar ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_influencewar
	@InfluenceType			TINYINT,
	@WartimeStage			TINYINT,
	@ReqContributionPoint		INT,
	@HPRepairRate			FLOAT,
	@DPRepairRate			FLOAT,
	@SPRepairRate			FLOAT,
	@EventTime			INT,
	@EventExperience		FLOAT,
	@EventDropSPI			FLOAT,
	@EventDownExperience		FLOAT,
	@EventDropItem			FLOAT,
	@EventDropRareItem		FLOAT,
	@SupplyItemNum			INT,
	@SupplyItemCount		INT,
	@IsSummonJacoMonster		TINYINT,
	@BossMonsterUnitKind		INT,
	@BossMonsterCount		INT,
	@BossMonsterSummonTerm		INT,
	@BossMonsterSummonMapIndex	SMALLINT,
	@BossMonsterSummonPositionX	SMALLINT,
	@BossMonsterSummonPositionY	SMALLINT,
	@BossMonsterSummonPositionZ	SMALLINT,
	@SummonMonsterUnitKind1		INT,
	@SummonCount1			INT,
	@SummonMapIndex1		SMALLINT,
	@SummonPositionX1		SMALLINT,
	@SummonPositionY1		SMALLINT,
	@SummonPositionZ1		SMALLINT,
	@SummonMonsterUnitKind2		INT,
	@SummonCount2			INT,
	@SummonMapIndex2		SMALLINT,
	@SummonPositionX2		SMALLINT,
	@SummonPositionY2		SMALLINT,
	@SummonPositionZ2		SMALLINT,
	@SummonMonsterUnitKind3		INT,
	@SummonCount3			INT,
	@SummonMapIndex3		SMALLINT,
	@SummonPositionX3		SMALLINT,
	@SummonPositionY3		SMALLINT,
	@SummonPositionZ3		SMALLINT,
	@SummonMonsterUnitKind4		INT,
	@SummonCount4			INT,
	@SummonMapIndex4		SMALLINT,
	@SummonPositionX4		SMALLINT,
	@SummonPositionY4		SMALLINT,
	@SummonPositionZ4		SMALLINT,
	@SummonMonsterUnitKind5		INT,
	@SummonCount5			INT,
	@SummonMapIndex5		SMALLINT,
	@SummonPositionX5		SMALLINT,
	@SummonPositionY5		SMALLINT,
	@SummonPositionZ5		SMALLINT,
	@SupplyItemNum2			INT,
	@SupplyItemCount2		INT,
	@WinBossMonsterNum		INT,
	@LossBossMonsterNum		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InfluenceWar(InfluenceType, WartimeStage, ReqContributionPoint, HPRepairRate, DPRepairRate,
		SPRepairRate, EventTime, EventExperience, EventDropSPI, EventDownExperience, EventDropItem, EventDropRareItem, SupplyItemNum,
		SupplyItemCount, IsSummonJacoMonster, BossMonsterUnitKind, BossMonsterCount, BossMonsterSummonTerm,
		BossMonsterSummonMapIndex, BossMonsterSummonPositionX, BossMonsterSummonPositionY,
		BossMonsterSummonPositionZ, SummonMonsterUnitKind1, SummonCount1, SummonMapIndex1,
		SummonPositionX1, SummonPositionY1, SummonPositionZ1, SummonMonsterUnitKind2, SummonCount2,
		SummonMapIndex2, SummonPositionX2, SummonPositionY2, SummonPositionZ2, SummonMonsterUnitKind3,
		SummonCount3, SummonMapIndex3, SummonPositionX3, SummonPositionY3, SummonPositionZ3,
		SummonMonsterUnitKind4, SummonCount4, SummonMapIndex4, SummonPositionX4, SummonPositionY4,
		SummonPositionZ4, SummonMonsterUnitKind5, SummonCount5, SummonMapIndex5, SummonPositionX5,
		SummonPositionY5, SummonPositionZ5, SupplyItemNum2, SupplyItemCount2, WinBossMonsterNum, LossBossMonsterNum)
	VALUES (@InfluenceType, @WartimeStage, @ReqContributionPoint, round(@HPRepairRate,2), round(@DPRepairRate,2),
		round(@SPRepairRate,2), @EventTime, round(@EventExperience,2), round(@EventDropSPI,2),
		round(@EventDownExperience,2), round(@EventDropItem,2), round(@EventDropRareItem,2), @SupplyItemNum,
		@SupplyItemCount, @IsSummonJacoMonster, @BossMonsterUnitKind, @BossMonsterCount, @BossMonsterSummonTerm,
		@BossMonsterSummonMapIndex, @BossMonsterSummonPositionX, @BossMonsterSummonPositionY,
		@BossMonsterSummonPositionZ, @SummonMonsterUnitKind1, @SummonCount1, @SummonMapIndex1,
		@SummonPositionX1, @SummonPositionY1, @SummonPositionZ1, @SummonMonsterUnitKind2, @SummonCount2,
		@SummonMapIndex2, @SummonPositionX2, @SummonPositionY2, @SummonPositionZ2, @SummonMonsterUnitKind3,
		@SummonCount3, @SummonMapIndex3, @SummonPositionX3, @SummonPositionY3, @SummonPositionZ3,
		@SummonMonsterUnitKind4, @SummonCount4, @SummonMapIndex4, @SummonPositionX4, @SummonPositionY4,
		@SummonPositionZ4, @SummonMonsterUnitKind5, @SummonCount5, @SummonMapIndex5, @SummonPositionX5,
		@SummonPositionY5, @SummonPositionZ5, @SupplyItemNum2, @SupplyItemCount2, @WinBossMonsterNum, @LossBossMonsterNum)
GO

--------------------------------------------------------------
-- ti_InfluenceWar ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_influencewar
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_InfluenceWar
GO

--------------------------------------------------------------
-- ti_OutPostNextWarTime ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_outpostnextwartime
	@OutPostWarStartTime		DATETIME
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_OutPostNextWarTime(OutPostWarStartTime)
	VALUES (@OutPostWarStartTime)
GO

--------------------------------------------------------------
-- ti_OutPostNextWarTime ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_outpostnextwartime
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_OutPostNextWarTime
GO

--------------------------------------------------------------
-- ti_ActionByLevel ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_actionbylevel
	@Level				TINYINT,
	@PollPoint			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ActionByLevel(Level, PollPoint)
	VALUES (@Level, @PollPoint)
GO

--------------------------------------------------------------
-- ti_ActionByLevel ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_actionbylevel
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ActionByLevel
GO

--------------------------------------------------------------
-- ti_MapInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_mapinfo
	@MapIndex					INT,
	@RenderMapIndex				INT,
	@BeforeMapIndex				INT,
	@MapName					VARCHAR(40),
	@MapInfluenceType			SMALLINT,
	@CityMapIndex				INT,
	@CityWarQuestIndex			INT,
	@CityWarQuestNPCIndex		INT,
	@CityWarQuestMonsterUID		INT,
	@MaxUserCount				SMALLINT,
	@MaxGroundHeight			SMALLINT,
	@MinGroundHeight			SMALLINT,
	@WaterHeight				SMALLINT,
	@UserVisibleDistance		SMALLINT,
	@MonsterVisibleDistance		SMALLINT,
	@QuestIndexForWarp			INT,
	@FrontPositionDistance		SMALLINT,
	@AutoRecoveryFlag			TINYINT,
	@DefaultMapIndex			INT,
	@CityWarpTargetPositionX	SMALLINT,
	@CityWarpTargetPositionY	SMALLINT,
	@CityWarpTargetPositionZ	SMALLINT,
	@ClientMaxAltitudeHeight	SMALLINT,
	@DayFogColor				INT,
	@NightFogColor				INT,
	@DayFogStartDistance		SMALLINT,
	@DayFogEndDistance			SMALLINT,
	@NightFogStartDistance		SMALLINT,
	@NightFogEndDistance		SMALLINT,
	@DaySunDirectionX			SMALLINT,
	@DaySunDirectionY			SMALLINT,
	@DaySunDirectionZ			SMALLINT,
	@NightSunDirectionX			SMALLINT,
	@NightSunDirectionY			SMALLINT,
	@NightSunDirectionZ			SMALLINT,
	@WaterType					TINYINT,
	@PKZoneFlag					TINYINT,
	@TileRenderingFlag			TINYINT,
	@SkyRenderingFlag			TINYINT,
	@SunRenderingFlag			TINYINT,
	@FogRenderingFlag			TINYINT,
	@VCNWarpObjectIndex			INT,
	@ANIWarpObjectIndex			INT,
	@dat						INT,
	@map						INT,
	@tex						INT,
	@cloud						INT,
	@sky						INT,
	@nsky						INT,
	@bgm						INT,
	@TeleportWarpObjectIndex	INT,
	@BeforeMapIndex2		INT,
	@MapDescription		VARCHAR(1024)			-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - 
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_MapInfo(MapIndex, RenderMapIndex, BeforeMapIndex, MapName, MapInfluenceType, CityMapIndex,
						    CityWarQuestIndex, CityWarQuestNPCIndex, CityWarQuestMonsterUID, MaxUserCount, MaxGroundHeight,
						    MinGroundHeight, WaterHeight, UserVisibleDistance, MonsterVisibleDistance, QuestIndexForWarp,
						    FrontPositionDistance, AutoRecoveryFlag, DefaultMapIndex, CityWarpTargetPositionX,
						    CityWarpTargetPositionY, CityWarpTargetPositionZ, ClientMaxAltitudeHeight, DayFogColor, NightFogColor,
						    DayFogStartDistance, DayFogEndDistance, NightFogStartDistance, NightFogEndDistance, DaySunDirectionX,
						    DaySunDirectionY, DaySunDirectionZ, NightSunDirectionX, NightSunDirectionY, NightSunDirectionZ,
						    WaterType, PKZoneFlag, TileRenderingFlag, SkyRenderingFlag, SunRenderingFlag, FogRenderingFlag,
						    VCNWarpObjectIndex, ANIWarpObjectIndex, dat, map, tex, cloud, sky, nsky, bgm, TeleportWarpObjectIndex, BeforeMapIndex2, MapDescription)
	VALUES (@MapIndex, @RenderMapIndex, @BeforeMapIndex, @MapName, @MapInfluenceType, @CityMapIndex,
		@CityWarQuestIndex, @CityWarQuestNPCIndex, @CityWarQuestMonsterUID, @MaxUserCount, @MaxGroundHeight,
		@MinGroundHeight, @WaterHeight, @UserVisibleDistance, @MonsterVisibleDistance, @QuestIndexForWarp,
		@FrontPositionDistance, @AutoRecoveryFlag, @DefaultMapIndex, @CityWarpTargetPositionX,
		@CityWarpTargetPositionY, @CityWarpTargetPositionZ, @ClientMaxAltitudeHeight, @DayFogColor, @NightFogColor,
		@DayFogStartDistance, @DayFogEndDistance, @NightFogStartDistance, @NightFogEndDistance, @DaySunDirectionX,
		@DaySunDirectionY, @DaySunDirectionZ, @NightSunDirectionX, @NightSunDirectionY, @NightSunDirectionZ,
		@WaterType, @PKZoneFlag, @TileRenderingFlag, @SkyRenderingFlag, @SunRenderingFlag, @FogRenderingFlag,
		@VCNWarpObjectIndex, @ANIWarpObjectIndex, @dat, @map, @tex, @cloud, @sky, @nsky, @bgm,
		@TeleportWarpObjectIndex, @BeforeMapIndex2, @MapDescription)
GO

--------------------------------------------------------------
-- ti_MapInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_mapinfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_MapInfo
GO

--------------------------------------------------------------
-- ti_BuildingNPC ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_buildingnpc
	@BuildingIndex			INT,
	@BuildingName			VARCHAR(40),
	@BuildingKind			TINYINT,
	@MapIndex				SMALLINT,
	@NPCIndex				INT,
	@NPCName				VARCHAR(40),
	@GreetingTalk			VARCHAR(400),
	@OwnerCityMapIndex		INT,
	@OwnerOrderNumber		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_BuildingNPC(BuildingIndex, BuildingName, BuildingKind, MapIndex, NPCIndex, NPCName, GreetingTalk, OwnerCityMapIndex, OwnerOrderNumber)
	VALUES (@BuildingIndex, @BuildingName, @BuildingKind, @MapIndex, @NPCIndex, @NPCName, @GreetingTalk,
                @OwnerCityMapIndex, @OwnerOrderNumber)
GO

--------------------------------------------------------------
-- ti_BuildingNPC ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_buildingnpc
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_BuildingNPC
GO

--------------------------------------------------------------
-- ti_Monster ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
--			// 2010-01-11 by cmkwon, ���� MPOption 64bit�� ���� - 
--			-- // 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ChangeTargetTime �ʵ� �߰�
--  110530_DB��Ű��_(���Ǵ�Ƽ3������2��)_DBQuery(atum2_db_[n]) ���� �߰�
-- ====
CREATE PROCEDURE dbo.atum_import_ti_monster
	@i_UniqueNumber			INT,
	@i_MonsterName			VARCHAR(40),
	@i_Level				TINYINT,
	@i_Experience			BIGINT,
	@i_HP					INT,
	@i_Race					SMALLINT,
	@i_Speed				TINYINT,
	@i_MonsterItem01		INT,
	@i_MonsterItem02		INT,
	@i_MonsterItem03		INT,
	@i_MonsterItem04		INT,
	@i_MonsterItem05		INT,
	@i_MonsterItem06		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem07		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem08		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem09		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem10		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem11		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem12		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem13		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem14		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterItem15		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_ControlSkill			INT,
	@i_SizeForServer		INT,
	@i_SizeForClient		INT,
	@i_Faction				TINYINT,
	@i_MonsterForm			SMALLINT,
	@i_AttackPattern		TINYINT,
	@i_MovePattern			SMALLINT,
	@i_Belligerence			TINYINT,
	@i_Defense				FLOAT,	-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
	@i_DefenceProbability	FLOAT,	-- // 2010-07-19 by dhjin, Ȯ�� ���� ����, // 2009-12-17 by cmkwon, ������ ���� ������ �ʵ�(����,ȸ��,�Ǿ,Ȯ��)�� 255�̻� ���� ���� �����ϰ� ���� - �����ڷ���(TINYINT)�� ����
	@i_AlphaBlending		TINYINT,
	@i_AttackObject			TINYINT,
	@i_AttackRange			SMALLINT,
	@i_HPRecoveryTime		SMALLINT,
	@i_HPRecoveryValue		SMALLINT,
	@i_RenderIndex			SMALLINT,
	@i_ScaleValue			FLOAT,
	@i_TextureIndex			TINYINT,
	@i_SourceIndex			INT,
	@i_QuickTurnAngle		TINYINT,
	@i_QuickSpeed			TINYINT,
	@i_QuickTurnTerm		SMALLINT,
	@i_MPOption				BIGINT,			-- // 2010-01-11 by cmkwon, ���� MPOption 64bit�� ���� - ����(TINYINT)
	@i_MPOptionParam1		TINYINT,
	@i_MPOptionParam2		TINYINT,
	@i_Range				SMALLINT,
	@i_TurnAngle			FLOAT,
	@i_MonsterHabit			TINYINT,
	@i_ClickEvent			TINYINT,
	@i_HPActionIdx			INT,	--REFERENCES ti_MonsterHPAction(MonsterHPActionNum)	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ
	@i_MonsterTarget		INT,		-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� ��� ��ȣ
	@i_ChangeTarget			TINYINT,	-- 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� ���� ��� Ÿ�ٰ� ���� ����
	@i_MonsterTarget2		INT,		-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���� ���� ���� ��� ��ȣ 2��° �켱 ����
	@i_PortraitFileName		VARCHAR(50),				-- 2010-03-31 by dhjin, ���Ǵ�Ƽ(�������) - ���� �ʻ�ȭ ����
	@i_ChangeTargetTime		INT,							-- // 2010-04-14 by cmkwon, ����2�� ���� ���� Ÿ�� ���� ó�� - ChangeTargetTime �ʵ� �߰�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
	@i_WayPointPattern		INT								-- // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ���� - WayPointPattern �ʵ� �߰�
AS
	INSERT INTO atum2_db_account.dbo.ti_Monster(UniqueNumber, MonsterName, Level, Experience, HP, Race, Speed, 
							MonsterItem01,MonsterItem02, MonsterItem03, MonsterItem04, MonsterItem05, 
							MonsterItem06,MonsterItem07, MonsterItem08, MonsterItem09, MonsterItem10, 
							MonsterItem11,MonsterItem12, MonsterItem13, MonsterItem14, MonsterItem15, 
							ControlSkill, SizeForServer, SizeForClient, Faction, MonsterForm, AttackPattern, MovePattern, Belligerence, Defense,
						    DefenceProbability, AlphaBlending, AttackObject, AttackRange, HPRecoveryTime, HPRecoveryValue,
						    RenderIndex, ScaleValue, TextureIndex, SourceIndex, QuickTurnAngle, QuickSpeed,
						    QuickTurnTerm, MPOption, MPOptionParam1, MPOptionParam2, Range, TurnAngle, MonsterHabit, ClickEvent, HPActionIdx, MonsterTarget, ChangeTarget, MonsterTarget2, PortraitFileName, ChangeTargetTime, WayPointPattern)
	VALUES (@i_UniqueNumber, @i_MonsterName, @i_Level, @i_Experience, @i_HP, @i_Race, @i_Speed, @i_MonsterItem01,
		@i_MonsterItem02, @i_MonsterItem03, @i_MonsterItem04, @i_MonsterItem05, @i_MonsterItem06, @i_MonsterItem07, @i_MonsterItem08, @i_MonsterItem09, @i_MonsterItem10, 
		@i_MonsterItem11, @i_MonsterItem12, @i_MonsterItem13, @i_MonsterItem14, @i_MonsterItem15, @i_ControlSkill, @i_SizeForServer,
		@i_SizeForClient, @i_Faction, @i_MonsterForm, @i_AttackPattern, @i_MovePattern, @i_Belligerence, @i_Defense,
		@i_DefenceProbability, @i_AlphaBlending, @i_AttackObject, @i_AttackRange, @i_HPRecoveryTime, @i_HPRecoveryValue,
		@i_RenderIndex, round(@i_ScaleValue,2), @i_TextureIndex, @i_SourceIndex, @i_QuickTurnAngle, @i_QuickSpeed,
		@i_QuickTurnTerm, @i_MPOption, @i_MPOptionParam1, @i_MPOptionParam2, @i_Range, round(@i_TurnAngle,3),
		@i_MonsterHabit, @i_ClickEvent, @i_HPActionIdx, @i_MonsterTarget, @i_ChangeTarget, @i_MonsterTarget2, @i_PortraitFileName, @i_ChangeTargetTime, @i_WayPointPattern);
GO

--------------------------------------------------------------
-- ti_Monster ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_monster
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_Monster
GO

--------------------------------------------------------------
-- ti_TutorialInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_tutorialinfo
	@TutorialUID			INT,
	@TutorialPayItem1		INT,
	@TutorialPayItemCount1		INT,
	@TutorialPayItem2		INT,
	@TutorialPayItemCount2		INT,
	@TutorialPayItem3		INT,
	@TutorialPayItemCount3		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_TutorialInfo(TutorialUID, TutorialPayItem1, TutorialPayItemCount1, TutorialPayItem2, TutorialPayItemCount2, TutorialPayItem3, TutorialPayItemCount3)
	VALUES (@TutorialUID, @TutorialPayItem1, @TutorialPayItemCount1, @TutorialPayItem2,
		@TutorialPayItemCount2, @TutorialPayItem3, @TutorialPayItemCount3)
GO

--------------------------------------------------------------
-- ti_TutorialInfo ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_tutorialinfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_TutorialInfo
GO

--------------------------------------------------------------
-- ti_MapObject ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_mapobject
	@ObjectName			VARCHAR(50),
	@Code				INT,
	@Alpha				TINYINT,
	@RadiusForServer		INT,
	@RadiusForClient		INT,
	@Collision			TINYINT,
	@CollisionForServer		TINYINT,
	@RenderIndex			SMALLINT,
	@ObjectRenderType		TINYINT,
	@ObjectDescription		VARCHAR(250)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_MapObject(ObjectName, Code, Alpha, RadiusForServer, RadiusForClient, Collision, CollisionForServer,
						      RenderIndex, ObjectRenderType, ObjectDescription)
	VALUES (@ObjectName, @Code, @Alpha, @RadiusForServer, @RadiusForClient, @Collision, @CollisionForServer,
		@RenderIndex, @ObjectRenderType, @ObjectDescription)
GO

--------------------------------------------------------------
-- ti_MapObject ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_mapobject
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_MapObject
GO

--------------------------------------------------------------
-- ti_LuckyMachine ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_luckymachine
	@MachineOrder			INT,
	@BuildingIndex			INT,
	@MachineKind			TINYINT,
	@MachineNum			INT,
	@CoinItemNum			INT,
	@SlotNum			TINYINT,
	@SlotProbability		INT,
	@MysteryItemDropNum		INT,
	@SourceIndex			INT,
	@Description			VARCHAR(200)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_LuckyMachine(MachineOrder, BuildingIndex, MachineKind, MachineNum, CoinItemNum, SlotNum,
							 SlotProbability, MysteryItemDropNum, SourceIndex, Description)
	VALUES (@MachineOrder, @BuildingIndex, @MachineKind, @MachineNum, @CoinItemNum, @SlotNum,
		@SlotProbability, @MysteryItemDropNum, @SourceIndex, @Description)
GO

--------------------------------------------------------------
-- ti_LuckyMachine ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_luckymachine
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_LuckyMachine
GO

--------------------------------------------------------------
-- ti_QuestMatching ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_questmatching
	@QuestIndexForBCU		INT,
	@QuestIndexForANI		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_QuestMatching(QuestIndexForBCU, QuestIndexForANI)
	VALUES (@QuestIndexForBCU, @QuestIndexForANI)
GO

--------------------------------------------------------------
-- ti_QuestMatching ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_questmatching
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_QuestMatching
GO

--------------------------------------------------------------
-- ti_ItemMatching ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_import_ti_itemmatching
	@ItemNumForBCU			INT,
	@ItemNumForANI			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ItemMatching(ItemNumForBCU, ItemNumForANI)
	VALUES (@ItemNumForBCU, @ItemNumForANI)
GO

--------------------------------------------------------------
-- ti_ItemMatching ������ ���� ����
--------------------------------------------------------------
-- !!!!
-- Name:
-- Desc: // 2009-07-09 by jwlee, ���� ���� ���̺� ������ DB�� �о�ֱ� �� ���� -
-- ====
CREATE PROCEDURE dbo.atum_delete_ti_itemmatching
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ItemMatching
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_ShapeItemNum
-- DESC				: -- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_ShapeItemNum
	@i_ItemUID			BIGINT,
	@i_ShapeItemNum		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Store
	SET ShapeItemNum = @i_ShapeItemNum
	WHERE UniqueNumber = @i_ItemUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Rearrange_InfluenceRate
-- DESC				: -- // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Rearrange_InfluenceRate
	@i_ValidPeriodOfDay		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	
	-- StartLevel�� ���� ������ ����Ʈ�� ���ٸ� ������ DB���� ���� ó��
	DELETE FROM dbo.td_InfluenceRate
	WHERE StartLevel NOT IN (SELECT StartLevel FROM atum2_db_account.dbo.ti_InfluenceRate WITH(NOLOCK)) AND StartLevel <> 0

	-- EndLevel�� ���� ������ ����Ʈ�� ���ٸ� ������ DB���� ���� ó��
	DELETE FROM dbo.td_InfluenceRate
	WHERE EndLevel NOT IN (SELECT EndLevel FROM atum2_db_account.dbo.ti_InfluenceRate WITH(NOLOCK)) AND StartLevel <> 0

	-- ������ DB�� ���� ������ ����Ʈ�� ���ٸ� �߰�
	INSERT INTO dbo.td_InfluenceRate(StartLevel,EndLevel,AllowablePercent,UpdateTime)
		SELECT StartLevel, EndLevel, 0, GETDATE()
		FROM atum2_db_account.dbo.ti_InfluenceRate WITH(NOLOCK)
		WHERE StartLevel NOT IN (SELECT StartLevel FROM dbo.td_InfluenceRate WITH(NOLOCK))

	-- ��� ����Ʈ�� ���¼��� 0���� �ʱ�ȭ �Ѵ�.
	UPDATE dbo.td_InfluenceRate
		SET NormalUserCount= 0, BCUUserCount= 0, ANIUserCount= 0;

	IF EXISTS(SELECT StartLevel FROM dbo.td_InfluenceRate WITH(NOLOCK) WHERE StartLevel = 0 AND EndLevel = 0)
	BEGIN
		-- ��ü ������ �ְ� ������ ������� ���º����� ����
		
		-- ���� �̼��� ������ ���
		UPDATE dbo.td_InfluenceRate
			SET NormalUserCount = (SELECT COUNT(*) FROM (SELECT DISTINCT AccountName, SelectableInfluenceMask FROM dbo.td_Character WITH(NOLOCK)
															WHERE SelectableInfluenceMask=6 AND Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE())) tm)
		WHERE StartLevel = 0 AND EndLevel = 0

		-- BCU ���� ������ ���
		UPDATE dbo.td_InfluenceRate
			SET BCUUserCount = (SELECT COUNT(*)	FROM (SELECT DISTINCT AccountName, SelectableInfluenceMask FROM dbo.td_Character WITH(NOLOCK)
														WHERE SelectableInfluenceMask=2 AND Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE())) tm)
		WHERE StartLevel = 0 AND EndLevel = 0

		-- ANI ���� ������ ���
		UPDATE dbo.td_InfluenceRate
			SET ANIUserCount = (SELECT COUNT(*)	FROM (SELECT DISTINCT AccountName, SelectableInfluenceMask FROM dbo.td_Character WITH(NOLOCK)
														WHERE SelectableInfluenceMask=4 AND Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE())) tm)
		WHERE StartLevel = 0 AND EndLevel = 0
	END

	--------------------------------------------------------------------------------
	-- �� ������ �ְ��� ĳ������ ������ ���º����� ����

	-- ������ ���� �̼��� ������ ���
	UPDATE dbo.td_InfluenceRate
		SET NormalUserCount = tm2.UserCount
	FROM td_InfluenceRate dir, (SELECT StartLevel, EndLevel, COUNT(*) AS UserCount 
								FROM (SELECT dir.StartLevel, dir.EndLevel FROM td_InfluenceRate dir, (SELECT AccountName, SelectableInfluenceMask, MAX(LEVEL) AS MaxLv FROM dbo.td_Character WITH(NOLOCK) WHERE Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE()) GROUP BY AccountName, SelectableInfluenceMask) tm WHERE dir.StartLevel <= tm.MaxLv AND dir.EndLevel >= tm.MaxLv AND tm.SelectableInfluenceMask = 6) tm1
								GROUP BY StartLevel, EndLevel) tm2
	WHERE dir.StartLevel = tm2.StartLevel AND dir.EndLevel = tm2.EndLevel

	-- ������ ���� BCU ���� ������ ���
	UPDATE td_InfluenceRate
		SET BCUUserCount = tm2.UserCount
	FROM td_InfluenceRate dir, (SELECT StartLevel, EndLevel, COUNT(*) AS UserCount
								FROM (SELECT dir.StartLevel, dir.EndLevel FROM td_InfluenceRate dir, (SELECT AccountName, SelectableInfluenceMask, MAX(LEVEL) AS MaxLv FROM dbo.td_Character WITH(NOLOCK) WHERE Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE()) GROUP BY AccountName, SelectableInfluenceMask) tm WHERE dir.StartLevel <= tm.MaxLv AND dir.EndLevel >= tm.MaxLv AND tm.SelectableInfluenceMask = 2) tm1
								GROUP BY StartLevel, EndLevel) tm2
	WHERE dir.StartLevel = tm2.StartLevel AND dir.EndLevel = tm2.EndLevel

	-- ������ ���� ANI ���� ������ ���
	UPDATE td_InfluenceRate
		SET ANIUserCount = tm2.UserCount
	FROM td_InfluenceRate dir, (SELECT StartLevel, EndLevel, COUNT(*) AS UserCount
								FROM (SELECT dir.StartLevel, dir.EndLevel FROM td_InfluenceRate dir, (SELECT AccountName, SelectableInfluenceMask, MAX(LEVEL) AS MaxLv FROM dbo.td_Character WITH(NOLOCK) WHERE Race & 0x4000 = 0 AND LastStartedTime > DATEADD(day, @i_ValidPeriodOfDay, GETDATE()) GROUP BY AccountName, SelectableInfluenceMask) tm WHERE dir.StartLevel <= tm.MaxLv AND dir.EndLevel >= tm.MaxLv AND tm.SelectableInfluenceMask = 4) tm1
								GROUP BY StartLevel, EndLevel) tm2
	WHERE dir.StartLevel = tm2.StartLevel AND dir.EndLevel = tm2.EndLevel

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfluenceRate
-- DESC				: -- // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfluenceRate	
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT StartLevel,EndLevel,AllowablePercent,UpdateTime,NormalUserCount,BCUUserCount,ANIUserCount
	FROM dbo.td_InfluenceRate WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_AllowablePercent
-- DESC				: -- // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_AllowablePercent
	@i_StartLv				TINYINT,
	@i_EndLv				TINYINT,
	@i_AllowablePercent		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (@i_StartLv = 0 AND @i_EndLv = 0 AND NOT EXISTS(SELECT StartLevel FROM dbo.td_InfluenceRate WITH(NOLOCK) WHERE StartLevel = @i_StartLv AND EndLevel = @i_EndLv))
	BEGIN
		INSERT INTO dbo.td_InfluenceRate(StartLevel,EndLevel,AllowablePercent,UpdateTime)
		VALUES(@i_StartLv, @i_EndLv, @i_AllowablePercent, GETDATE());
	END
	ELSE
	BEGIN
		UPDATE dbo.td_InfluenceRate
			SET AllowablePercent= @i_AllowablePercent, UpdateTime= GETDATE()
		WHERE StartLevel = @i_StartLv AND EndLevel = @i_EndLV;
	END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_InfluenceRate
-- DESC				: -- // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_InfluenceRate
	@i_StartLv				TINYINT,
	@i_EndLv				TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE dbo.td_InfluenceRate
	WHERE StartLevel = @i_StartLv AND EndLevel = @i_EndLV;	
GO


--------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InfluenceRate
-- Desc				: // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - ti_InfluenceRate ���̺� �߰�, ti_InfluenceRate ������ ���� ����
--
--------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_InfluenceRate
	@i_StartLevel		TINYINT,
	@i_EndLevel			TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InfluenceRate(StartLevel, EndLevel)
	VALUES (@i_StartLevel, @i_EndLevel)
GO

--------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InfluenceRate
-- Desc				: // 2009-09-16 by cmkwon, ���� �ʱ�ȭ�� ���¡ ���� ���� - ti_InfluenceRate ���̺� �߰�, ti_InfluenceRate ������ ���� ����
--
--------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InfluenceRate
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_InfluenceRate
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_change_StartCityMapIndex
-- DESC				: // 2009-10-12 by cmkwon, ������ī ���� ��� ���� - �ش� ĳ������ StartCityMapIndex�� �����Ѵ�(Material �ʵ�)
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_change_StartCityMapIndex
	@i_CharcUID					INT,
	@i_StartCityMapIdx			SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Character
		SET Material = @i_StartCityMapIdx
	WHERE UniqueNumber = @i_CharcUID;
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_HPAction
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - HP �ൿ �ε� 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_HPAction
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT HPActionUID, HPActionNum, HPMaxValueRate, HPMinValueRate, UseItemArrayIdx, NextUseItemArrayIdx, HitRate, UseCount, HPTalkCondition, HPTalkImportance
			, PreHPCameraTremble, PreHPTalk , HPCameraTremble, HPTalk 
	FROM atum2_db_account.dbo.ti_HPAction WITH (NOLOCK) ORDER BY HPActionNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_HPAction
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_HPAction
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_HPAction
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_HPAction
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_HPAction
	@i_HPActionUID					INT,
	@i_HPActionNum					INT,	
	@i_HPMaxValueRate				TINYINT,
	@i_HPMinValueRate				TINYINT,
	@i_UseItemArrayIdx				INT,
	@i_NextUseItemArrayIdx			INT,	
	@i_HitRate						TINYINT,
	@i_UseCount						INT,
	@i_HPTalkCondition				TINYINT,
	@i_HPTalkImportance				TINYINT,
	@i_PreHPCameraTremble			INT,
	@i_PreHPTalk					VARCHAR(100),
	@i_HPCameraTremble				INT,
	@i_HPTalk						VARCHAR(100)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_HPAction(HPActionUID, HPActionNum, HPMaxValueRate, HPMinValueRate, UseItemArrayIdx, NextUseItemArrayIdx,
			HitRate, UseCount, HPTalkCondition, HPTalkImportance, PreHPCameraTremble, PreHPTalk, HPCameraTremble, HPTalk)
	VALUES (@i_HPActionUID, @i_HPActionNum,	@i_HPMaxValueRate, @i_HPMinValueRate, @i_UseItemArrayIdx, @i_NextUseItemArrayIdx,
			@i_HitRate, @i_UseCount, @i_HPTalkCondition, @i_HPTalkImportance, @i_PreHPCameraTremble, @i_PreHPTalk, @i_HPCameraTremble, @i_HPTalk)
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_Cinema
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� �ε� 
--					  -- // 2010-03-29 by cmkwon, ����2�� �ó׸��� ȿ���� ���� ���� �߰� - SoundFileName �ʵ� �߰�
--                    -- // 2011-03-09 by hskim, �ó׸� ����Ʈ �ε��� ���� �߰� - QuestIndex �ʵ� �߰�
--					  -- // 2011-04-28 by hskim, �ó׸� ���� ���� �߰� (��ȯ�� ��ǥ/���� ����/Ŀ���ҵ���)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_Cinema
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT 	CinemaNum, CinemaOrder, StartTime, EffectIdx, EffectPosition_X, EffectPosition_Y, EffectPosition_Z, 
			EffectPlayTime, EffectPlayCount, ObjectIdx, ChangeObjectIdx, ChangeTime, CameraTremble, 
			KeyMonster, MonsterIdx, SummonCount, SummonRandomPos, ObjectBodyConditionIdx, BodyCondition, TipFileName, SkyFileName, CinemaTalk, SoundFileName, QuestIndex, MonsterIdxType, CustomIdx, UpdateMonsterIdx
	FROM atum2_db_account.dbo.ti_Cinema WITH (NOLOCK);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_Revision
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ����ġ �ε� 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_Revision
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT 	RevisionNum, UnitKind, RevisionLevel, RevisionHP, RevisionDP, RevisionStandardWeapon, RevisionAdvancedWeapon
	FROM atum2_db_account.dbo.ti_Revision WITH (NOLOCK);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityMonster
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ���� ���� ���� ó��
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfinityMonster
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfinityMonsterUID, InfinityMonsterIdx, MonsterIdx, TargetType, TargetCount
	FROM atum2_db_account.dbo.ti_InfinityMonster WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityMode
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ ��� ���� ��������
--					: -- // 2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰� (HP �� �ð� ���� ������ ����)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfinityMode
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfinityModeUID, ModeTypeNum, MapIdx, InfinityMonsterIdx, CinemaNum, RevisionNum
			, ResetCycle, EntranceCount, LimitTime, MinLv, MaxLv, MinAdmissionCount, MaxAdmissionCount, TimePenaltyValue, HPPenaltyValue	-- // 2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰�
	FROM atum2_db_account.dbo.ti_InfinityMode WITH (NOLOCK);
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ͼ� ���� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfinityImpute
	@i_AccountUID			INT,
	@i_CharacterUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InfinityModeUID, EntranceCount
	FROM dbo.td_InfinityImpute WITH (NOLOCK)
	WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ�� �ͼӵ�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_InfinityImpute
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_InfinityModeUID		INT,
	@i_StartTime			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_InfinityImpute(AccountUID, CharacterUID, InfinityModeUID, EntranceCount, StartTime)
	VALUES (@i_AccountUID, @i_CharacterUID, @i_InfinityModeUID, 1, @i_StartTime)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ �ͼ� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Update_InfinityImpute
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_InfinityModeUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_InfinityImpute
	SET EntranceCount = EntranceCount + 1
	WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND InfinityModeUID = @i_InfinityModeUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Reset_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ �ͼ� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Reset_InfinityImpute
	@i_InfinityModeUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_InfinityImpute
	WHERE InfinityModeUID = @i_InfinityModeUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Reset_InfinityImputeByServerStart
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ �ͼ� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Reset_InfinityImputeByServerStart
	@i_InfinityModeUID		INT,
	@i_StartTime			VARCHAR(30)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_InfinityImpute
	WHERE InfinityModeUID = @i_InfinityModeUID AND StartTime <= @i_StartTime
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_Log_Infinity
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���Ǵ�Ƽ ���� ��� �α׷� �����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_Log_Infinity
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_InfinityModeUID		INT,
	@i_StartTime			VARCHAR(30),
	@i_EndTime				VARCHAR(30),
	@i_DeathCount			INT,
	@i_KillCount			INT,
	@i_AllEXP			INT	-- // 2010-06-25 by shcho, ���Ǵ�Ƽ ���÷α� ��� - ����� �ִ� ����ġ
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.atum_Log_Infinity(AccountUID, CharacterUID, InfinityModeUID, StartTime, EndTime, DeathCount, KillCount,EndAllExp)
	VALUES (@i_AccountUID, @i_CharacterUID, @i_InfinityModeUID, @i_StartTime, @i_EndTime, @i_DeathCount, @i_KillCount,@i_AllEXP)
GO


-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'

--> 130617_DB��Ű��_01_(�Ƹ��÷���)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_CopyDBInfo_Infinity
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �Ʒ���DB�� �����ϱ�
--					  -- // 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - DB ���� ���� ���� ����
--						-- // 2012-10-29 by jhseol, ���ʿ��� ����Ʈ �� �ּ�ó��
--						-- // 2013-05-31 by jhseol,bckim �Ƹ� �÷���
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[arena_CopyDBInfo_Infinity]
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--@o_RetCode					INT OUTPUT,
	@i_ArenaCharacterUID		INT,
	@i_CharacterUID				INT,
	@i_AccountUID				INT			
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
	--SET @o_RetCode = 0		--			0	==> ���� ����

	--DECLARE @traceID INT
	--INSERT INTO [_trace] (ArenaCharacterUID, CharacterUID, AccountUID)
	--VALUES (@i_ArenaCharacterUID, @i_CharacterUID, @i_AccountUID)
	--SET @traceID = SCOPE_IDENTITY()

	--DECLARE @traceStart DATETIME
	--SET @traceStart = GETUTCDATE()
	
	--2013-05-16 Edison: Remove enchant info for all items owned by this user on Arena DB
	DELETE e
	FROM atum2_db_arena.dbo.td_Enchant AS e
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = e.TargetItemUniqueNumber
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 30		--			30	==> ��þƮ���� ���� ����
		SELECT 30;
		RETURN              
	END
	
	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 1)

	-- // 2011-10-17 by hskim ��Ʈ�� �ý��� 2�� - ���� ���� ���� (���� ��ġ ����)
	-- // 2010-06-15 by shcho&hslee ��ý��� - �� ���� Copy�߰�
	--2013-05-16 Edison: Remove pet info for all items owned by this user on Arena DB
	DELETE p
	FROM atum2_db_arena.dbo.td_pet AS p
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = p.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 90				--			90	==> �� ������ ���� ����
		SELECT 90;
		RETURN              
	END
	
	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 2)

	-- // 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����
	DELETE ss
	FROM atum2_db_arena.dbo.td_ShapeStatLevel AS ss
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = ss.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SELECT 101;
		RETURN              
	END

	DELETE f
	FROM atum2_db_arena.dbo.td_FixedTerm AS f
	INNER JOIN atum2_db_arena.dbo.td_Store AS s WITH (NOLOCK) ON s.UniqueNumber = f.ItemUID
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		SELECT 102;
		RETURN              
	END
	-- // end 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����


	--2013-05-16 Edison: Remove all items owned by this user on Arena DB
	DELETE s
	FROM atum2_db_arena.dbo.td_Store AS s
	WHERE s.AccountUniqueNumber = @i_AccountUID
	AND s.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 40		--			40	==> ���������� ���� ����
		SELECT 40;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 3)

	--2013-05-16 Edison: Remove all skills owned by this user on Arena DB
	DELETE k
	FROM atum2_db_arena.dbo.td_StoreSkill AS k
	WHERE k.AccountUniqueNumber = @i_AccountUID
	AND k.Possess = @i_ArenaCharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 70				--			70	==> ��ų ���� ����
		SELECT 70;
		RETURN              
	END
	
	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 4)

-- td_Character
	--2013-05-16 Edison: Clone td_Character
	UPDATE atum2_db_arena.dbo.td_Character		-- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - LevelUpTime �߰�, ����ġ �߰�
	SET	Race = sc.Race, UnitKind = sc.UnitKind, InfluenceType = sc.InfluenceType
		, PilotFace = sc.PilotFace, AttackPart = sc.AttackPart, DefensePart = sc.DefensePart, FuelPart = sc.FuelPart, SoulPart = sc.SoulPart
		, ShieldPart = sc.ShieldPart, DodgePart = sc.DodgePart, [Level] = sc.Level, Experience = sc.Experience, BodyCondition = sc.BodyCondition, Propensity = sc.Propensity
		, [Status] = sc.Status, PKWinPoint = sc.PKWinPoint, PKLossPoint = sc.PKLossPoint, HP = sc.HP, DP = sc.DP, SP = sc.SP, EP = sc.EP
		, BonusStat = sc.BonusStat, BonusStatPoint = sc.BonusStatPoint, WarPoint = sc.WarPoint, CumulativeWarPoint = sc.CumulativeWarPoint
		, ArenaWin = sc.ArenaWin,	ArenaLose = sc.ArenaLose, ArenaDisConnect = sc.ArenaDisConnect, TotalPlayTime = sc.TotalPlayTime, PCBangTotalPlayTime = sc.PCBangTotalPlayTime
		, RacingPoint = sc.RacingPoint, SecretInfoOption = sc.SecretInfoOption -- //2011-11-28 by shcho, �������� �ɼ� �ʱ�ȭ ���� // 2010-12-22 by shcho, ���Ǵ�Ƽ ����ó�� - �κ�Ȯ�� ������� ����
	FROM dbo.td_Character sc, atum2_db_arena.dbo.td_Character tc
	WHERE tc.AccountUniqueNumber = @i_AccountUID AND tc.UniqueNumber = @i_ArenaCharacterUID AND sc.UniqueNumber = @i_CharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 20		--			20	==> �Ʒ��� ������ �ɸ��� ���� ������Ʈ ����
		SELECT 20;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 5)

-- td_StoreSkill
	--2013-05-16 Edison: Clone td_StoreSkill
	INSERT atum2_db_arena.dbo.td_StoreSkill (AccountUniqueNumber, Possess, ItemWindowIndex, ItemNum, CreatedTime, UseTime)
	SELECT AccountUniqueNumber, @i_ArenaCharacterUID, ItemWindowIndex, ItemNum, CreatedTime, NULL
	FROM dbo.td_StoreSkill
	WHERE AccountUniqueNumber = @i_AccountUID
	AND Possess = @i_CharacterUID
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 80				--			80	==> ��ų �߰� ����
		SELECT 80;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 6)

	--2013-05-16 Edison: This VERY IMPORTANT table variable holds the relationship between main server ItemUID and arena server ItemUID.
	DECLARE @ItemMatching TABLE (MainItemUID BIGINT, ArenaItemUID BIGINT, PRIMARY KEY (MainItemUID))

	--2013-05-16 Edison: Clone td_Store. Uses the OUTPUT keyword to gather the generated IDENTITY column in a set operation.
	INSERT atum2_db_arena.dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
	OUTPUT INSERTED.MainSvrItemUID, INSERTED.UniqueNumber
	INTO @ItemMatching
	SELECT AccountUniqueNumber, @i_ArenaCharacterUID, ItemStorage, Wear, CurrentCount, ItemWindowIndex
		, i.ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime, ShapeItemNum, UniqueNumber, CoolingTime
	FROM td_Store AS s WITH(NOLOCK)
	INNER JOIN atum2_db_account.dbo.ti_Item AS i WITH (NOLOCK) ON i.ItemNum = s.ItemNum
	WHERE AccountUniqueNumber = @i_AccountUID
	AND Possess = @i_CharacterUID
	AND ItemStorage = 0
	IF (@@Error <> 0)
	BEGIN 
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 60			--			60	==> ������ �߰� ����
		SELECT 60;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 7)

	--2013-05-16 Edison: Clone td_Enchant. Again uses @ItemMatching to convert Main to Arena as a set operation.
	INSERT INTO atum2_db_arena.dbo.td_Enchant (TargetItemUniqueNumber, TargetItemNum, EnchantItemNum)
	SELECT m.ArenaItemUID, e.TargetItemNum, e.EnchantItemNum
	FROM td_Enchant AS e WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = e.TargetItemUniqueNumber
	IF (@@ERROR <> 0)
	BEGIN
		-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 
		--SET @o_RetCode = 61		--			61	==> ��þƮ �߰� ����
		SELECT 61;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 8)

	--2013-05-16 Edison: Clone td_pet. Again uses @ItemMatching to convert Main to Arena as a set operation.
	INSERT INTO atum2_db_arena.dbo.td_pet(ItemUID,PetIndex,Experience,[Level],[Name],ExpRatio,EnableSocketCount,SocketItem1,SocketItem2,SocketItem3,SocketItem4,SocketItem5,SocketItem6,HPKitItemNum,HPKitTriggerValue,ShieldKitItemNum,ShieldKitTriggerValue,SPKitItemNum,SPKitTriggerValue,AutoSkilItemNum1,AutoSkilItemNum2,AutoSkilItemNum3,AutoSkilItemNum4,AutoSkilItemNum5,AutoSkilItemNum6)
	SELECT m.ArenaItemUID,PetIndex,Experience,[Level],[Name],ExpRatio,EnableSocketCount
		,ISNULL(m1.ArenaItemUID,0),ISNULL(m2.ArenaItemUID,0),ISNULL(m3.ArenaItemUID,0),ISNULL(m4.ArenaItemUID,0),ISNULL(m5.ArenaItemUID,0),ISNULL(m6.ArenaItemUID,0)
		,HPKitItemNum,HPKitTriggerValue,ShieldKitItemNum,ShieldKitTriggerValue,SPKitItemNum,SPKitTriggerValue,AutoSkilItemNum1,AutoSkilItemNum2,AutoSkilItemNum3,AutoSkilItemNum4,AutoSkilItemNum5,AutoSkilItemNum6
	FROM td_Pet WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = ItemUID
	LEFT JOIN @ItemMatching AS m1 ON m1.MainItemUID = SocketItem1
	LEFT JOIN @ItemMatching AS m2 ON m2.MainItemUID = SocketItem2
	LEFT JOIN @ItemMatching AS m3 ON m3.MainItemUID = SocketItem3
	LEFT JOIN @ItemMatching AS m4 ON m4.MainItemUID = SocketItem4
	LEFT JOIN @ItemMatching AS m5 ON m5.MainItemUID = SocketItem5
	LEFT JOIN @ItemMatching AS m6 ON m6.MainItemUID = SocketItem6
	IF (@@ERROR <> 0)
	BEGIN
		-- // 2010-06-15 by shcho&hslee ��ý��� - ���Ǵ�Ƽ ����� �� ���� �߰�
		--SET @o_RetCode = 91		--			91	==> �� ���� �߰� ����
		SELECT 91;
		RETURN              
	END

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 9)

	-- // 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����
	INSERT INTO atum2_db_arena.dbo.td_ShapeStatLevel(ItemKind, ItemUID, ShapeItemNum, AllStatLevel)
	SELECT ss.ItemKind, m.ArenaItemUID, ss.ShapeItemNum, ss.AllStatLevel
	FROM td_ShapeStatLevel AS ss WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = ss.ItemUID
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 111;
		RETURN              
	END

	INSERT INTO atum2_db_arena.dbo.td_FixedTerm(ItemUID, TermType, AppliedItemNum, StartDate, EndDate)
	SELECT m.ArenaItemUID, f.TermType, f.AppliedItemNum, f.StartDate, f.EndDate
	FROM td_FixedTerm AS f WITH(NOLOCK)
	INNER JOIN @ItemMatching AS m ON m.MainItemUID = f.ItemUID
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 112;
		RETURN              
	END
	-- // end 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - td_ShapeStatLevel �� td_FixedTerm ����

	SELECT 0;	-- // 2008-08-20 by cmkwon, MySQL ���� �ҽ� ���� - 

	--INSERT INTO [_traceDetail] (traceID, traceDetailTime, tracePayload) VALUES (@traceID, DATEDIFF(ms, @traceStart, GETUTCDATE()), 0)
' 
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_CharacterSaveDataInfinityFin
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ �ɸ��� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_CharacterSaveDataInfinityFin
	@i_CharacterUID		INT,
	@i_Level			TINYINT,
	@i_Experience		FLOAT,
	@i_DownExperience	FLOAT,
	@i_DownSPIOnDeath	INT,			-- 2006-04-10 by cmkwon
	@i_totalPlayTime	BIGINT,
	@i_PCBangtotalPlayTime	BIGINT,						-- 2007-06-07 by dhjin, PC�� �� �÷��� �ð�
	@i_SecretInfoOption		INT,				-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
	@i_AttackPart		SMALLINT,
	@i_DefensePart		SMALLINT,
	@i_FuelPart			SMALLINT,
	@i_SoulPart			SMALLINT,
	@i_ShieldPart		SMALLINT,
	@i_DodgePart		SMALLINT,
	@i_bstat			TINYINT,
	@i_bstatPoint		TINYINT,
	@i_LevelUpTime		VARCHAR(30),				--// 2006-12-18 by dhjin, ������ �ð�
	@i_WarPoint			INT,					--	// 2007-04-17 by dhjin, WP
	@i_CumulativeWarPoint	INT,				--	// 2007-05-28 by dhjin, ����WP
	@i_MapIndex			SMALLINT,							--	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ñ� ���� ������ ó��
	@i_ChannelIndex		SMALLINT							--	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ñ� ���� ������ ó��
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Character
	SET	Level			= @i_Level,
		Experience		= @i_Experience,
		DownExperience  = @i_DownExperience,
		DownSPIOnDeath	= @i_DownSPIOnDeath,			-- 2006-04-10 by cmkwon
		totalPlayTime	= @i_totalPlayTime,
		PCBangtotalPlayTime = @i_PCBangtotalPlayTime,						-- 2007-06-07 by dhjin, PC�� �� �÷��� �ð�
		SecretInfoOption	= @i_SecretInfoOption,				-- // 2008-06-23 by dhjin, EP3 ���������ɼ�
		AttackPart		= @i_AttackPart,
		DefensePart		= @i_DefensePart,
		FuelPart		= @i_FuelPart,
		SoulPart		= @i_SoulPart,
		ShieldPart		= @i_ShieldPart,
		DodgePart		= @i_DodgePart,
		BonusStat		= @i_bstat,
		BonusStatPoint	= @i_bstatPoint,
		LevelUpTime		= @i_LevelUpTime,			--	// 2006-12-18 by dhjin, ������ �ð�
		WarPoint		= @i_WarPoint,					--	// 2007-04-17 by dhjin, WP
		CumulativeWarPoint	= @i_CumulativeWarPoint,					--	// 2007-05-28 by dhjin, ����WP
		MapIndex		= @i_MapIndex,			--	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ñ� ���� ������ ó��
		ChannelIndex	= @i_ChannelIndex		--	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ñ� ���� ������ ó��
	WHERE UniqueNumber = @i_CharacterUID
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InfinityFinInsertItem
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ������ �߰�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InfinityFinInsertItem
	@accNum				INT,
	@possess			INT,
	@ItemStorage		TINYINT,			-- 2005-12-07 by cmkwon
	@wear				TINYINT,
	@CurrentCount		INT,
	@ItemWindowIndex	INT,
	@ItemNum			INT,
	@NumOfEnchants		SMALLINT,
	@PrefixCodeNum		INT,
	@SufficCodeNum		INT,
	@CurrentEndurance	FLOAT,
	@ColorCode			INT,				-- 2005-11-21 by cmkwon, �Ƹ� Ʃ�׽� Į��
	@UsingTimeStamp		INT,
	@i_ShapeItemNum		INT,				-- // 2009-08-26 by cmkwon, �׷��� ���ҽ� ���� �ý��� ���� - td_Store.ShapeItemNum �ʵ� �߰�, �ʵ帮��Ʈ ���
	@i_GetDate			VARCHAR(30),
	@i_CoolingTime		INT					--	// 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,CoolingTime)
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, @i_GetDate, @i_ShapeItemNum, @i_CoolingTime)
	IF (@@ERROR <> 0)
	BEGIN
		SELECT 0;
		RETURN;
	END

	SELECT SCOPE_IDENTITY();
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InfinityFinUpdateItem
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �� MainSvr�� ���� �����ϸ鼭 ������ ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InfinityFinUpdateItem
	@i_MainSvrItemUID	BIGINT,
	@i_wear				TINYINT,
	@i_CurrentCount		INT,
	@i_ItemWindowIndex	INT,
	@i_UsingTimeStamp	INT,
	@i_CoolingTime		INT					--	// 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Store
	SET Wear = @i_wear, CurrentCount = @i_CurrentCount, ItemWindowIndex = @i_ItemWindowIndex, UsingTimeStamp = @i_UsingTimeStamp, CoolingTime = @i_CoolingTime
	WHERE UniqueNumber = @i_MainSvrItemUID
GO




--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_Cinema
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_Cinema
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_Cinema
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_Cinema
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--					  -- // 2010-03-29 by cmkwon, ����2�� �ó׸��� ȿ���� ���� ���� �߰� - SoundFileName �ʵ� �߰�
--					  -- // 2011-03-09 by hskim, �ó׸� ����Ʈ �ε��� ���� �߰�
--					  -- // 2011-04-28 by hskim, �ó׸� ���� ���� �߰� (���� ����/Ŀ���ҵ���)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_Cinema
	@i_CinemaNum			INT,
	@i_CinemaOrder			INT,	-- 51000 ~ 51999 : ���� ���� �ó׸�, 52000 ~ 52999 : ���� ���� �ó׸�
	@i_StartTime			INT,	-- msec
	@i_EffectIdx			INT,
	@i_EffectPosition_X		FLOAT,
	@i_EffectPosition_Y		FLOAT,
	@i_EffectPosition_Z		FLOAT,
	@i_EffectPlayTime		INT,	-- msec	
	@i_EffectPlayCount		INT,
	@i_ObjectIdx			INT,
	@i_ChangeObjectIdx		INT,
	@i_ChangeTime			INT,	-- msec	
	@i_CameraTremble		INT,	-- msec
	@i_KeyMonster			TINYINT,
	@i_MonsterIdx			INT,
	@i_SummonCount			INT,
	@i_SummonRandomPos		INT, -- M	
	@i_ObjectBodyConditionIdx	INT,
	@i_BodyCondition		BIGINT,
	@i_TipFileName			VARCHAR(50),
	@i_SkyFileName			VARCHAR(50),
	@i_CinemaTalk			VARCHAR(100),
	@i_SoundFileName		VARCHAR(50),
	@i_QuestIndex			INT,	-- // 2011-03-09 by hskim, �ó׸� ���� ���� �߰� (���� ����/Ŀ���ҵ���)
	@i_MonsterIdxType		INT,	-- // 2011-03-09 by hskim, ���� Ÿ�� (0 = ����, 1 = ����), MonsterIdx ���� ����Ͽ� ����
	@i_CustomIdx			INT,	-- // 2011-03-09 by hskim, �ó׸� Ŀ���� ��� ������	(1xxx = 1�� �ó׸�, 2xxx = 2�� �ó׸�, 3xxx = 3�� �ó׸�)
	@i_UpdateMonsterIdx		INT		-- // 2011-03-09 by hskim, ���� ��ü (���� ��� �ִ� ���͸� ��ü)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_Cinema(CinemaNum, CinemaOrder, StartTime, EffectIdx, EffectPosition_X, EffectPosition_Y, EffectPosition_Z, 
			EffectPlayTime, EffectPlayCount, ObjectIdx, ChangeObjectIdx, ChangeTime, CameraTremble, 
			KeyMonster, MonsterIdx, SummonCount, SummonRandomPos, ObjectBodyConditionIdx, BodyCondition, TipFileName, SkyFileName, CinemaTalk, SoundFileName, QuestIndex, MonsterIdxType, CustomIdx, UpdateMonsterIdx)
	VALUES (@i_CinemaNum, @i_CinemaOrder, @i_StartTime, @i_EffectIdx, @i_EffectPosition_X, @i_EffectPosition_Y, @i_EffectPosition_Z, 
			@i_EffectPlayTime, @i_EffectPlayCount, @i_ObjectIdx, @i_ChangeObjectIdx, @i_ChangeTime, @i_CameraTremble, 
			@i_KeyMonster, @i_MonsterIdx, @i_SummonCount, @i_SummonRandomPos, @i_ObjectBodyConditionIdx, @i_BodyCondition, @i_TipFileName, @i_SkyFileName, @i_CinemaTalk, @i_SoundFileName, @i_QuestIndex, @i_MonsterIdxType, @i_CustomIdx, @i_UpdateMonsterIdx)
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InfinityMonster
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InfinityMonster
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_InfinityMonster
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InfinityMonster
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_InfinityMonster
	@i_InfinityMonsterUID		INT,
	@i_InfinityMonsterIdx		INT,		
	@i_MonsterIdx				INT,	
	@i_TargetType				TINYINT,
	@i_TargetCount				TINYINT	
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InfinityMonster(InfinityMonsterUID, InfinityMonsterIdx, MonsterIdx, TargetType, TargetCount)
	VALUES (@i_InfinityMonsterUID, @i_InfinityMonsterIdx, @i_MonsterIdx, @i_TargetType, @i_TargetCount)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_Revision
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_Revision
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_Revision
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_Revision
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_Revision
	@i_RevisionNum					INT,
	@i_UnitKind						INT,
	@i_RevisionLevel				TINYINT,
	@i_RevisionHP					SMALLINT,
	@i_RevisionDP					SMALLINT,
	@i_RevisionStandardWeapon		INT,
	@i_RevisionAdvancedWeapon		INT		
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_Revision(RevisionNum, UnitKind, RevisionLevel, RevisionHP, RevisionDP, RevisionStandardWeapon, RevisionAdvancedWeapon)
	VALUES (@i_RevisionNum, @i_UnitKind, @i_RevisionLevel, @i_RevisionHP, @i_RevisionDP, @i_RevisionStandardWeapon, @i_RevisionAdvancedWeapon)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InfinityMode
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InfinityMode
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_InfinityMode
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InfinityMode
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--					: -- // 2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰� (HP �� �ð� ���� ������ ����)
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_InfinityMode
	@i_InfinityModeUID			INT,
	@i_ModeTypeNum				TINYINT,
	@i_MapIdx					INT,	
	@i_InfinityMonsterIdx		INT,
	@i_CinemaNum				INT,	
	@i_RevisionNum				INT,	
	@i_ResetCycle				TINYINT,
	@i_EntranceCount			TINYINT,
	@i_LimitTime				INT,
	@i_MinLv					TINYINT,
	@i_MaxLv					TINYINT,
	@i_MinAdmissionCount		TINYINT,
	@i_MaxAdmissionCount		TINYINT,
	@i_TimePenaltyValue			INT,
	@i_HPPenaltyValue			INT							-- // 2011-06-14 by hskim, ���Ǵ�Ƽ 3�� - �г�Ƽ ��� �߰� (HP �� �ð� ���� ������ ����)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InfinityMode(InfinityModeUID, ModeTypeNum, MapIdx, InfinityMonsterIdx, CinemaNum, RevisionNum, ResetCycle,
			EntranceCount, LimitTime, MinLv, MaxLv, MinAdmissionCount, MaxAdmissionCount, TimePenaltyValue, HPPenaltyValue)
	VALUES (@i_InfinityModeUID, @i_ModeTypeNum, @i_MapIdx, @i_InfinityMonsterIdx, @i_CinemaNum, @i_RevisionNum, @i_ResetCycle,
			@i_EntranceCount, @i_LimitTime, @i_MinLv, @i_MaxLv, @i_MinAdmissionCount, @i_MaxAdmissionCount, @i_TimePenaltyValue, @i_HPPenaltyValue)
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_Tender
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Tender �ε� 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_Tender
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT TenderUID, TenderItemNum 
	FROM atum2_db_account.dbo.ti_Tender WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_Tender
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_Tender
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_Tender
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_Tender
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_Tender
	@i_TenderUID				INT,
	@i_TenderItemNum			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_Tender(TenderUID, TenderItemNum)
	VALUES (@i_TenderUID, @i_TenderItemNum)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityShop
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - ���� ���� �ε�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfinityShop
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT 	InfinityShopUID, BuyItemNum, BuyItemCount, TradeItemNum1, TradeItemCount1
			, TradeItemNum2, TradeItemCount2, TradeItemNum3, TradeItemCount3, TradeItemNum4, TradeItemCount4, TradeItemNum5, TradeItemCount5 
	FROM atum2_db_account.dbo.ti_InfinityShop WITH (NOLOCK)
	ORDER BY InfinityShopUID
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InfinityShop
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InfinityShop
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_InfinityShop
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InfinityShop
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - Excel -> DB �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_InfinityShop
	@i_InfinityShopUID			INT,
	@i_BuyItemNum				INT,
	@i_BuyItemCount				INT,
	@i_TradeItemNum1			INT,
	@i_TradeItemCount1			INT,
	@i_TradeItemNum2			INT,
	@i_TradeItemCount2			INT,
	@i_TradeItemNum3			INT,
	@i_TradeItemCount3			INT,
	@i_TradeItemNum4			INT,
	@i_TradeItemCount4			INT,
	@i_TradeItemNum5			INT,
	@i_TradeItemCount5			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InfinityShop(InfinityShopUID, BuyItemNum, BuyItemCount, TradeItemNum1, TradeItemCount1
													, TradeItemNum2, TradeItemCount2, TradeItemNum3, TradeItemCount3, TradeItemNum4, TradeItemCount4, TradeItemNum5, TradeItemCount5)
	VALUES (@i_InfinityShopUID, @i_BuyItemNum, @i_BuyItemCount, @i_TradeItemNum1, @i_TradeItemCount1, @i_TradeItemNum2, @i_TradeItemCount2
			, @i_TradeItemNum3, @i_TradeItemCount3, @i_TradeItemNum4, @i_TradeItemCount4, @i_TradeItemNum5, @i_TradeItemCount5)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Reset_All_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ͼ� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Reset_All_InfinityImpute
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  dbo.td_InfinityImpute
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Reset_Character_InfinityImpute
-- DESC				: -- // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ - �ͼ� ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Reset_Character_InfinityImpute
	@i_CharacterUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM dbo.td_InfinityImpute
	WHERE CharacterUID = @i_CharacterUID
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_wrkR_delete_AllRankingList_from_LRankingServer
-- DESC				: -- // 2010-01-14 by cmkwon, ���巩ŷ�ý��� ���� ����(���񽺻���,�����׷����) - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_delete_AllRankingList_from_LRankingServer
	@i_ServiceUID				INT,
	@i_ServerGroupID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	EXEC dbo.atum_wrk_delete_selfAllLevelRanking @i_ServiceUID, @i_ServerGroupID;
	EXEC dbo.atum_wrk_delete_selfAllFameRanking @i_ServiceUID, @i_ServerGroupID;
	EXEC dbo.atum_wrk_delete_selfAllPVPRanking @i_ServiceUID, @i_ServerGroupID;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_get_ItemParamOverlap
-- DESC				: // 2010-01-18 by cmkwon, ������ ���� Parameter �ߺ� üũ �ý��� ���� - ti_ItemParamOverlap
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_get_ItemParamOverlap
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemNum, OverlapIndex
	FROM atum2_db_account.dbo.ti_ItemParamOverlap WITH(NOLOCK)
	ORDER BY ItemNum;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_ItemParamOverlap
-- DESC				: // 2010-01-18 by cmkwon, ������ ���� Parameter �ߺ� üũ �ý��� ���� - ti_ItemParamOverlap
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_ItemParamOverlap
	@i_ItemNum				INT,
	@i_OverlapIndex			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_ItemParamOverlap(ItemNum, OverlapIndex)
	VALUES (@i_ItemNum, @i_OverlapIndex);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_ItemParamOverlap
-- DESC				: // 2010-01-18 by cmkwon, ������ ���� Parameter �ߺ� üũ �ý��� ���� - ti_ItemParamOverlap
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_ItemParamOverlap
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE FROM atum2_db_account.dbo.ti_ItemParamOverlap;
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_check_Buy_LimitedEdtion_shopItem
-- DESC				: // 2010-01-26 by cmkwon, ĳ�� ������ �����Ǹ� �ý��� ���� - 
--					
-- Result set		: [ErrorCode] [RemainCountForLimitedEdition]
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_check_Buy_LimitedEdtion_shopItem
	@i_ItemNum				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @NewRemainCount INT

	UPDATE atum2_db_account.dbo.td_CashShop
	SET @NewRemainCount = RemainCountForLimitedEdition = (RemainCountForLimitedEdition - 1)
	WHERE @i_ItemNum = ItemNum AND RemainCountForLimitedEdition > 0;

	IF (@NewRemainCount IS NULL)
	BEGIN
		SELECT 10000, 0;
		RETURN;
	END

	SELECT 0, @NewRemainCount;
	RETURN;	
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InvokingWearItemDestParamNum
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ������������� 
-- DESC				: �ߵ��� ���� ������ ���� DestParam �� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InvokingWearItemDestParamNum
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InvokingDestParamID, InvokingDestParam, InvokingDestParamValue, InvokingEffectIdx 
	FROM atum2_db_account.dbo.ti_InvokingWearItemDPNum WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InvokingWearItemDestParamNum
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- DESC				: �ߵ��� ���� ������ ���� DestParam �� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InvokingWearItemDestParamNum
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_InvokingWearItemDPNum
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InvokingWearItemDestParamNum
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- DESC				: �ߵ��� ���� ������ ���� DestParam �� DB -> Excel �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_import_ti_InvokingWearItemDestParamNum]
	@i_InvokingDestParamID				INT,
	@i_InvokingDestParam				SMALLINT,			-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@i_InvokingDestParamValue			FLOAT,
	@i_InvokingEffectIdx				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InvokingWearItemDPNum(InvokingDestParamID, InvokingDestParam, InvokingDestParamValue, InvokingEffectIdx)
	VALUES (@i_InvokingDestParamID, @i_InvokingDestParam, @i_InvokingDestParamValue, @i_InvokingEffectIdx)
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InvokingWearItemDestParamNumByUse
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ������������� 
-- DESC				: �ߵ��� ���� ������ ��� DestParam �� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InvokingWearItemDestParamNumByUse
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT InvokingDestParamIDByUse, InvokingDestParamByUse, InvokingDestParamValueByUse, InvokingEffectIdxbyUse 
	FROM atum2_db_account.dbo.ti_InvokingWearItemDPNumByUse WITH (NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_InvokingWearItemDestParamNumByUse
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- DESC				: �ߵ��� ���� ������ ��� DestParam �� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_InvokingWearItemDestParamNumByUse
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_InvokingWearItemDPNumByUse
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_InvokingWearItemDestParamNumByUse
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
-- DESC				: �ߵ��� ���� ������ ��� DestParam �� DB -> Excel �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_import_ti_InvokingWearItemDestParamNumByUse]
	@i_InvokingDestParamIDByUse				INT,
	@i_InvokingDestParamByUse				SMALLINT,		-- // 2001-08-01 by hskim, ��Ʈ�� �ý��� - �ڷ��� ���� (DestParameter - 255 -> 32767 ����)
	@i_InvokingDestParamValueByUse			FLOAT,
	@i_InvokingEffectIdxbyUse				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_InvokingWearItemDPNumByUse(InvokingDestParamIDByUse, InvokingDestParamByUse, InvokingDestParamValueByUse, InvokingEffectIdxbyUse)
	VALUES (@i_InvokingDestParamIDByUse, @i_InvokingDestParamByUse, @i_InvokingDestParamValueByUse, @i_InvokingEffectIdxbyUse)
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_UpdateItemCoolingTimeStamp
-- DESC				: -- // 2009-09-09 ~ 2010-02-10 by dhjin, ���Ǵ�Ƽ - �ߵ�������������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateItemCoolingTimeStamp
	@UniqueNumber		BIGINT,
	@CoolingTime		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_Store
	SET CoolingTime = @CoolingTime
	WHERE UniqueNumber = @UniqueNumber
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InfinityUpdateUserMapInfo
-- DESC				: -- // 2010-04-06 by cmkwon, ����2�� �߰� ���� - 
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InfinityUpdateUserMapInfo
	@i_CharacterUID		INT,
	@i_MapIndex			SMALLINT,
	@i_ChannelIndex		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE dbo.td_Character
	SET MapIndex = @i_MapIndex, ChannelIndex = @i_ChannelIndex
	WHERE UniqueNumber = @i_CharacterUID
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityDifficultMonster
-- DESC				: -- // 2010-05-13 by shcho, ���Ǵ�Ƽ ���̵� ���� -
-- DESC				: �������� �ε� ���ν���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_InfinityDifficultMonster
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS 
	SELECT IncreaseStep,MonsterHp,MonsterDefense,MonsterEvasion,MonsterAttackItem,MonsterPopulation
	FROM atum2_db_account.dbo.ti_LevelAdjustment WITH(NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_InfinityDifficult
-- DESC				: -- // 2010-05-13 by shcho, ���Ǵ�Ƽ ���̵� ���� -
-- DESC				: ������ �ε� ���ν���
--------------------------------------------------------------------------------          
CREATE PROCEDURE dbo.atum_Load_InfinityDifficult
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT IncreaseStep, IncreaseIncomeExp, IncreaseIncomeDropProbabillity, IncreaseIncomeDropCount
	FROM atum2_db_account.dbo.ti_LevelAdjustmentReward WITH(NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_LevelAdjustment
-- DESC				: -- // 2010-05-24 by shcho, ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ���̵� ������ ���� �� ������Ʈ
-- DESC				: ���̵� ���� ���� ���ν���(���Ǵ�Ƽ�� ����Ǵ� ����) DB -> Excel �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_LevelAdjustment
	@i_IncreaseStep INT,
	@i_MonsterHP INT,
	@i_MonsterDefense INT,
	@i_MonsterEvasion INT,
	@i_MonsterAttackItem INT,
	@i_MonsterPopulation INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_LevelAdjustment(IncreaseStep,MonsterHP,MonsterDefense,MonsterEvasion,MonsterAttackItem,MonsterPopulation)
	VALUES(@i_IncreaseStep, @i_MonsterHP, @i_MonsterDefense, @i_MonsterEvasion, @i_MonsterAttackItem, @i_MonsterPopulation);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_LevelAdjustmentReward
-- DESC				: -- // 2010-05-24 by shcho, ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ���̵� ������ ���� �� ������Ʈ
-- DESC				: ���̵� ���� ���� ���ν���(�������� ���̴� ����) DB -> Excel �б�
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_LevelAdjustmentReward
	@i_IncreaseStep INT,
	@i_IncreaselncomeEXP INT,
	@i_IncreaselncomeDropProbabillity INT,
	@i_IncreaselncomeDropCount INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	INSERT INTO atum2_db_account.dbo.ti_LevelAdjustmentReward(IncreaseStep,IncreaseIncomeExp,IncreaseIncomeDropProbabillity,IncreaseIncomeDropCount)
	VALUES(@i_IncreaseStep, @i_IncreaselncomeEXP, @i_IncreaselncomeDropProbabillity, @i_IncreaselncomeDropCount);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_LevelAdjustment
-- DESC				: -- // 2010-05-24 by shcho, ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ���̵� ������ ���� �� ������Ʈ
-- DESC				: ���̵� ���� DB ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_LevelAdjustment
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE atum2_db_account.dbo.ti_LevelAdjustment;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_LevelAdjustmentReward
-- DESC				: -- // 2010-05-24 by shcho, ���Ǵ�Ƽ ���̵� ���� - ���Ǵ�Ƽ ���̵� ������ ���� �� ������Ʈ
-- DESC				: ���̵� ���� DB ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_LevelAdjustmentReward
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DELETE atum2_db_account.dbo.ti_LevelAdjustmentReward;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_BurningMap
-- DESC			: ���׸� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Load_BurningMap
AS
	SELECT BuringMapUID, MapIndex, ReqUnitKind, ReqMinLv, ReqMaxLv
	FROM atum2_db_account.dbo.ti_BurningMap WITH(NOLOCK)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_delete_ti_BurningMap
-- DESC			: ���׸� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_delete_ti_BurningMap
AS
	TRUNCATE TABLE  atum2_db_account.dbo.ti_BurningMap
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_import_ti_BurningMap
-- DESC			: ���׸� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_import_ti_BurningMap
	@i_BuringMapUID		INT,		-- UID
	@i_MapIndex		INT,		-- �� ��ȣ
	@i_ReqUnitKind		INT,		-- ���� ������ ��� ����
	@i_ReqMinLv		TINYINT,		-- ���� ���� �ּ� ����
	@i_ReqMaxLv		TINYINT		-- ���� ���� �ִ� ����
AS
	INSERT INTO atum2_db_account.dbo.ti_BurningMap(BuringMapUID, MapIndex, ReqUnitKind, ReqMinLv, ReqMaxLv)
	VALUES (@i_BuringMapUID, @i_MapIndex, @i_ReqUnitKind, @i_ReqMinLv, @i_ReqMaxLv)
GO



----------------------------�� �ý���---------------------------------------------
----------------------------------------------------------------------------------

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���̽� ���̺� ���� ����( �����б� ������ ó�� )
--
-------------------------------------------------------------
CREATE PROC dbo.atum_Delete_ti_pet
AS
BEGIN
	DELETE atum2_db_account.dbo.ti_pet;
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� ����( �����б� ������ ó�� )
--
-------------------------------------------------------------
CREATE PROC dbo.atum_Delete_ti_petLevel
AS
BEGIN
	DELETE atum2_db_account.dbo.ti_petLevel;
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ������ ���� �� ���� ���̺� �߰�(�������� ����)
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_td_pet]
	@i_ItemUID					BIGINT,			-- ������ UID
	@i_PetIndex					INT,			-- �ε���(1000,1001......)
	@i_Name						VARCHAR(40),	-- �̸�
	@i_Level					INT,			-- ���� ����
	@i_Experience				FLOAT,			-- ����ġ (����ġ)
	@i_ExpRatio					TINYINT,		-- ��� ����ġ ����
	@i_EnableSocketCount		TINYINT,		-- ���� ���� ��
	@i_SocketItem1				INT,			-- ���� ���� ������
	@i_SocketItem2				INT,
	@i_SocketItem3				INT,
	@i_SocketItem4				INT,
	@i_SocketItem5				INT,
	@i_SocketItem6				INT,
	@i_HPKitItemNum				INT,			-- HP Kit �� ������ ��ȣ
	@i_HPKitTriggerValue		FLOAT,			-- HP Kit �� Ʈ���� �� (���� �߻� ����)
	@i_ShieldKitItemNum			INT,			-- Shield Kit �� ������ ��ȣ
	@i_ShieldKitTriggerValue	FLOAT,			-- Shield Kit �� Ʈ���� �� (���� �߻� ����)
	@i_SPKitItemNum				INT,			-- SP Kit �� ������ ��ȣ
	@i_SPKitTriggerValue		FLOAT,			-- SP Kit �� Ʈ���� �� (���� �߻� ����)
	@i_AutoSkilItemNum1			INT,			-- ���� ��ų ������ ���� ������
	@i_AutoSkilItemNum2			INT,
	@i_AutoSkilItemNum3			INT,
	@i_AutoSkilItemNum4			INT,
	@i_AutoSkilItemNum5			INT,
	@i_AutoSkilItemNum6			INT
AS
BEGIN
	INSERT INTO dbo.td_pet(ItemUID, PetIndex, Name, [Level], Experience, ExpRatio, EnableSocketCount, 
			SocketItem1, SocketItem2, SocketItem3, SocketItem4, SocketItem5, SocketItem6, 
			HPKitItemNum, HPKitTriggerValue, ShieldKitItemNum, ShieldKitTriggerValue, SPKitItemNum, SPKitTriggerValue, 
			AutoSkilItemNum1, AutoSkilItemNum2, AutoSkilItemNum3, AutoSkilItemNum4, AutoSkilItemNum5, AutoSkilItemNum6)
	VALUES (@i_ItemUID, @i_PetIndex, @i_Name, @i_Level, @i_Experience, @i_ExpRatio, @i_EnableSocketCount, 
			@i_SocketItem1, @i_SocketItem2, @i_SocketItem3, @i_SocketItem4, @i_SocketItem5, @i_SocketItem6, 
			@i_HPKitItemNum, @i_HPKitTriggerValue, @i_ShieldKitItemNum, @i_ShieldKitTriggerValue, @i_SPKitItemNum, @i_SPKitTriggerValue, 
			@i_AutoSkilItemNum1, @i_AutoSkilItemNum2, @i_AutoSkilItemNum3, @i_AutoSkilItemNum4, @i_AutoSkilItemNum5, @i_AutoSkilItemNum6)
END
GO

--> 130605_DB��Ű��_01_(��ĳ�û���)_DBQuery(atum2_db_[n] & stum2_db_arena)
-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - �������� �κ��� �߰� �� ��,  �� ������ �߰��Ǵ� ó���� ����
-- //����! - dbo.atum_Insert_td_pet�� �����ϱ� ������ �׻� �� ���ν��� ���� dbo.atum_Insert_td_pet�� �����Ǿ�� �Ѵ�.  
--
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InsertStorePetItem]
	@accNum				INT,
	@possess			INT,
	@ItemStorage		TINYINT,
	@wear				TINYINT,
	@CurrentCount		INT,
	@ItemWindowIndex	INT,
	@ItemNum			INT,
	@NumOfEnchants		SMALLINT,
	@PrefixCodeNum		INT,
	@SufficCodeNum		INT,
	@CurrentEndurance	FLOAT,
	@ColorCode			INT,
	@UsingTimeStamp		INT,
	@i_LinkItem			INT				--�� �ε���
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @PetIndex int, @PetName	varchar(40), @BaseSocketCount tinyint, @store_Error INT, @pet_error INT 

	BEGIN TRAN

	INSERT INTO dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
	VALUES (@accNum, @possess, @ItemStorage, @wear, @CurrentCount, @ItemWindowIndex,
			@ItemNum, @NumOfEnchants, @PrefixCodeNum, @SufficCodeNum, @CurrentEndurance, @ColorCode, @UsingTimeStamp, GetDate(), 0, 0, 0);
	
	SET @store_Error = @@ERROR

	IF (@store_error <> 0)
	BEGIN
		ROLLBACK TRAN;
		SELECT 0;
		RETURN 0;
	END

	SELECT @PetIndex = PetIndex, @PetName = PetName, @BaseSocketCount = BaseSocketCount FROM atum2_db_account.dbo.ti_pet WHERE PetIndex = @i_linkItem
	EXEC dbo.atum_Insert_td_pet @@IDENTITY, @PetIndex, @PetName, 1, 0, 0, @BaseSocketCount, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	
	SET @pet_error = @@ERROR

	IF (@pet_error <> 0)
	BEGIN
		ROLLBACK TRAN;
		SELECT 0;
		RETURN 0;
	END

	COMMIT TRAN;

	SELECT SCOPE_IDENTITY();
	RETURN SCOPE_IDENTITY();
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���̽� ���̺� ���� ����( �����б� ������ ó�� )
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_pet]
	@i_PetIndex			INT,			-- ��Ʈ�� �ε���
	@i_PetName			VARCHAR(40),	-- �⺻ ��Ʈ�� �̸�
	@i_Petkind			INT,			-- ���� [0=������ / 1=�Ϲ��� ��Ʈ�� / 2=������ ��Ʈ��]
	@i_EnableName		SMALLINT,		-- �̸� ���� ���� ���� [0=���� / 1=���]
	@i_EnableLevel		SMALLINT,		-- ���� �� ���� ���� [0=���� / 1=���]
	@i_MaxLevel			SMALLINT,		-- �ִ� ���� ����
	@i_BaseSocketCount	TINYINT			-- �⺻ ���� ����
AS
BEGIN
	INSERT INTO atum2_DB_account.dbo.ti_pet(PetIndex, PetName, PetKind, EnableName, EnableLevel, MaxLevel, BaseSocketCount)
			VALUES(@i_PetIndex, @i_PetName, @i_PetKind, @i_EnableName, @i_EnableLevel, @i_MaxLevel, @i_BaseSocketCount)
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� ����( �����б� ������ ó�� )
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_petLevel]
	@i_PetIndex			INT,
	@i_Level			INT,
	@i_NeedExp			FLOAT,
	@i_UseWeaponIndex	INT,
	@i_SlotCountSkill	TINYINT,
	@i_SlotCountSocket	TINYINT,
	@i_KitLevelHP		TINYINT,
	@i_KitLevelShield	TINYINT,
	@i_KitLevelSP		TINYINT
AS
BEGIN
	INSERT INTO atum2_db_account.dbo.ti_PetLevel(PetIndex, [Level], NeedExp, UseWeaponIndex, SlotCountSkill, SlotCountSocket, KitLevelHP, KitLevelShield, KitLevelSP)
	VALUES(@i_PetIndex, @i_Level, @i_NeedExp, @i_UseWeaponIndex, @i_SlotCountSkill, @i_SlotCountSocket, @i_KitLevelHP, @i_KitLevelShield, @i_KitLevelSP)
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� �� ���� �ε� 
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_td_petInfo]
	@i_ItemUID BIGINT
AS
BEGIN
	SELECT ItemUID, PetIndex, Name, [Level], Experience, ExpRatio, EnableSocketCount,
		SocketItem1, SocketItem2, SocketItem3, SocketItem4, SocketItem5, SocketItem6,
		HPKitItemNum, HPKitTriggerValue, ShieldKitItemNum, ShieldKitTriggerValue, SPKitItemNum, SPKitTriggerValue,
		AutoSkilItemNum1, AutoSkilItemNum2, AutoSkilItemNum3, AutoSkilItemNum4, AutoSkilItemNum5, AutoSkilItemNum6 
			FROM dbo.td_pet  WHERE ItemUID = @i_ItemUID;
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���̽� ���̺� ���� �ε�( �����б� ������ ó�� )
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_pet]
AS
BEGIN
	SELECT PetIndex, PetName, PetKind, EnableName, EnableLevel, MaxLevel, BaseSocketCount
	FROM atum2_db_account.dbo.ti_pet
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� �ε�( �����б� ������ ó�� )
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_petLevel]
	@i_PetIndex INT
AS
BEGIN
	SELECT PetIndex, [Level], NeedExp, UseWeaponIndex, SlotCountSkill, SlotCountSocket, KitLevelHP, KitLevelShield, KitLevelSP 
		FROM atum2_db_account.dbo.ti_PetLevel WHERE PetIndex = @i_PetIndex;
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetName
-- DESC				: �� �̸� ����
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetName]
	@i_ItemUID		BIGINT,
	@i_Name			VARCHAR(40)
AS
BEGIN
	UPDATE [dbo].[td_pet] SET [Name] = @i_Name WHERE [ItemUID] = @i_ItemUID;		
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetExpRatio
-- DESC				: �� ����ġ ȹ�� ���� ����
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetExpRatio]
	@i_ItemUID		BIGINT,
	@i_ExpRatio		TINYINT
AS
BEGIN
	UPDATE [dbo].[td_pet] SET [ExpRatio] = @i_ExpRatio WHERE [ItemUID] = @i_ItemUID;		
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetLevel
-- DESC				: �� ���� ����
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetLevel]
	@i_ItemUID		BIGINT,
	@i_Level		INT
AS
BEGIN
	UPDATE [dbo].[td_pet] SET [Level] = @i_Level WHERE [ItemUID] = @i_ItemUID;		
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetExp
-- DESC				: �� ����ġ ����
-- // 2011-08-05 by hskim, ��Ʈ�� �ý��� 2�� - �ڷ� ���� ����
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetExp]
	@i_ItemUID		BIGINT,
	@i_Exp			FLOAT
AS
BEGIN
	UPDATE [dbo].[td_pet] SET [Experience] = @i_Exp WHERE [ItemUID] = @i_ItemUID;		
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetSocket
-- DESC				: �� ���� ������ ����
-- // 2011-08-30 by hskim, ��Ʈ�� �ý��� 2��
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetSocket]
	@i_ItemUID		BIGINT,
	@i_SocketItem1	INT,
	@i_SocketItem2	INT,
	@i_SocketItem3	INT,
	@i_SocketItem4	INT,
	@i_SocketItem5	INT,
	@i_SocketItem6	INT
AS
BEGIN
	UPDATE [dbo].[td_pet] 
		SET [SocketItem1] = @i_SocketItem1, [SocketItem2] = @i_SocketItem2, [SocketItem3] = @i_SocketItem3, 
			[SocketItem4] = @i_SocketItem4, [SocketItem5] = @i_SocketItem5, [SocketItem6] = @i_SocketItem6 WHERE [ItemUID] = @i_ItemUID;
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetKitSlot
-- DESC				: �� ŰƮ ���� ����
-- // 2011-08-30 by hskim, ��Ʈ�� �ý��� 2��
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetKitSlot]
	@i_ItemUID					BIGINT,
	@i_HPKitItemNum				INT,
	@i_HPKitTriggerValue		FLOAT,
	@i_ShieldKitItemNum			INT,
	@i_ShieldKitTriggerValue	FLOAT,
	@i_SPKitItemNum				INT,
	@i_SPKitTriggerValue		FLOAT
AS
BEGIN
	UPDATE [dbo].[td_pet] 
		SET [HPKitItemNum] = @i_HPKitItemNum, [HPKitTriggerValue] = @i_HPKitTriggerValue, [ShieldKitItemNum] = @i_ShieldKitItemNum, 
			[ShieldKitTriggerValue] = @i_ShieldKitTriggerValue, [SPKitItemNum] = @i_SPKitItemNum, [SPKitTriggerValue] = @i_SPKitTriggerValue WHERE [ItemUID] = @i_ItemUID;
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetAutoSkillSlot
-- DESC				: �� ���� ��ų ���� ����
-- // 2011-08-30 by hskim, ��Ʈ�� �ý��� 2��
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetAutoSkillSlot]
	@i_ItemUID				BIGINT,
	@i_AutoSkilItemNum1		INT,
	@i_AutoSkilItemNum2		INT,
	@i_AutoSkilItemNum3		INT,
	@i_AutoSkilItemNum4		INT,
	@i_AutoSkilItemNum5		INT,
	@i_AutoSkilItemNum6		INT
AS
BEGIN
	UPDATE [dbo].[td_pet] 
		SET [AutoSkilItemNum1] = @i_AutoSkilItemNum1, [AutoSkilItemNum2] = @i_AutoSkilItemNum2, [AutoSkilItemNum3] = @i_AutoSkilItemNum3, 
			[AutoSkilItemNum4] = @i_AutoSkilItemNum4, [AutoSkilItemNum5] = @i_AutoSkilItemNum5, [AutoSkilItemNum6] = @i_AutoSkilItemNum6 WHERE [ItemUID] = @i_ItemUID;
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetInfo
-- DESC				: �� ���� ������Ʈ
-- // 2011-09-30 by hskim, ��Ʈ�� �ý���
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetInfo]
	@i_ItemUID					BIGINT,
	@i_Experience				FLOAT,
	@i_Level					INT,
	@i_Name						VARCHAR(40),
	@i_ExpRatio					TINYINT,
	@i_EnableSocketCount		TINYINT,
	@i_HPKitItemNum				INT,
	@i_HPKitTriggerValue		FLOAT,
	@i_ShieldKitItemNum			INT,
	@i_ShieldKitTriggerValue	FLOAT,
	@i_SPKitItemNum				INT,
	@i_SPKitTriggerValue		FLOAT,
	@i_AutoSkilItemNum1			INT,
	@i_AutoSkilItemNum2			INT,
	@i_AutoSkilItemNum3			INT,
	@i_AutoSkilItemNum4			INT,
	@i_AutoSkilItemNum5			INT,
	@i_AutoSkilItemNum6			INT
AS
BEGIN
	UPDATE [dbo].[td_pet] 
		SET Experience = @i_Experience, [Level] = @i_Level, Name = @i_Name, ExpRatio = @i_ExpRatio, 
			EnableSocketCount = @i_EnableSocketCount,
			HPKitItemNum = @i_HPKitItemNum, HPKitTriggerValue = @i_HPKitTriggerValue, 
			ShieldKitItemNum = @i_ShieldKitItemNum, ShieldKitTriggerValue = @i_ShieldKitTriggerValue,
			SPKitItemNum = @i_SPKitItemNum, SPKitTriggerValue = @i_SPKitTriggerValue,
			AutoSkilItemNum1 = @i_AutoSkilItemNum1, AutoSkilItemNum2 = @i_AutoSkilItemNum2,
			AutoSkilItemNum3 = @i_AutoSkilItemNum3, AutoSkilItemNum4 = @i_AutoSkilItemNum4,
			AutoSkilItemNum5 = @i_AutoSkilItemNum5, AutoSkilItemNum6 = @i_AutoSkilItemNum6
		WHERE [ItemUID] = @i_ItemUID;		
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� �ε�( �����б� ������ ó�� )
-- // 2010-06-15 by shcho&hslee ��ý��� - ���۷����� �ý���
-------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Delete_ti_OperatorAction

AS

BEGIN
	DELETE atum2_db_account.dbo.ti_OperatorAction;
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� �ε�( �����б� ������ ó�� )
-- // 2010-06-15 by shcho&hslee ��ý��� - ���۷����� �ý���
-------------------------------------------------------------
CREATE PROC dbo.atum_Load_ti_OperatorAction

AS

BEGIN
	SELECT ActionType, Itemnum, FunctionIndex, FunctionValue, SourceIndex, ActionDesc FROM atum2_db_account.dbo.ti_OperatorAction;
END
GO

-------------------------------------------------------------
-----���� ���ν���
-- // 2010-06-15 by shcho&hslee ��ý��� - ���� ���̽� ���̺� ���� �ε�( �����б� ������ ó�� )
-- // 2010-06-15 by shcho&hslee ��ý��� - ���۷����� �ý���
-------------------------------------------------------------
CREATE PROC dbo.atum_import_ti_OperatorAction

@i_ActionType INT, 
@i_Itemnum INT, 
@i_FunctionIndex INT, 
@i_FunctionValue FLOAT, 
@i_SourceIndex INT, 
@i_ActionDesc VARCHAR(128)

AS

BEGIN
	INSERT INTO atum2_db_account.dbo.ti_OperatorAction ( ActionType, Itemnum, FunctionIndex, FunctionValue, SourceIndex, ActionDesc )
	VALUES( @i_ActionType, @i_Itemnum, @i_FunctionIndex, @i_FunctionValue, @i_SourceIndex, @i_ActionDesc ) 
END
GO
----------------------------�� �ý���---------------------------------------------
----------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_DissolutionItem
-- DESC			: // 2010-08-31 by shcho&jskim �����ۿ��� �ý��� -
-- DESC			: ���� ������ ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC dbo.atum_Load_ti_DissolutionItem
AS
BEGIN
	SELECT SourceItemnum, 
		ResultItemNum1, ResultItemMinCount1, ResultItemMaxCount1, ResultItemProbabillity1,
		ResultItemNum2, ResultItemMinCount2, ResultItemMaxCount2, ResultItemProbabillity2,
		ResultItemNum3, ResultItemMinCount3, ResultItemMaxCount3, ResultItemProbabillity3 
		FROM atum2_db_account.dbo.ti_DissolutionItem;
END

GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_DissolutionItem
-- DESC			: // 2010-08-31 by shcho&jskim �����ۿ��� �ý��� -
-- DESC			: ���� ������ ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC dbo.atum_Delete_ti_DissolutionItem
AS
BEGIN
	DELETE  atum2_db_account.dbo.ti_DissolutionItem;
END

GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_insert_ti_DissolutionItem
-- DESC			: // 2010-08-31 by shcho&jskim �����ۿ��� �ý��� -
-- DESC			: ���� ������ ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC dbo.atum_insert_ti_DissolutionItem
	@i_SourceItemnum		INT ,	-- Item�ѹ�

	@i_ResultItemNum1		INT ,	-- ���� ��� ������ ��ȣ1
	@i_ResultItemMinCount1		INT ,	-- ���� ��� ������ �ּ� ����1
	@i_ResultItemMaxCount1		INT ,	-- ���� ��� ������ �ִ� ����1
	@i_ResultItemProbabillity1	INT ,	--�������� ���� Ȯ��1


	@i_ResultItemNum2		INT ,	-- ���� ��� ������ ��ȣ2
	@i_ResultItemMinCount2		INT ,	-- ���� ��� ������ �ּ� ����2
	@i_ResultItemMaxCount2		INT ,	-- ���� ��� ������ �ִ� ����2
	@i_ResultItemProbabillity2	INT ,	--�������� ���� Ȯ��2
	
	
	@i_ResultItemNum3		INT ,	-- ���� ��� ������ ��ȣ3
	@i_ResultItemMinCount3		INT ,	-- ���� ��� ������ �ּ� ����3
	@i_ResultItemMaxCount3		INT ,	-- ���� ��� ������ �ִ� ����3
	@i_ResultItemProbabillity3	INT 	--�������� ���� Ȯ��3

AS
BEGIN
	INSERT atum2_db_account.dbo.ti_DissolutionItem 
	(SourceItemnum, ResultItemNum1, ResultItemNum2, ResultItemNum3, ResultItemMinCount1, ResultItemMinCount2, ResultItemMinCount3, 
	ResultItemMaxCount1, ResultItemMaxCount2, ResultItemMaxCount3, ResultItemProbabillity1, ResultItemProbabillity2, ResultItemProbabillity3)
	VALUES(@i_SourceItemnum, @i_ResultItemNum1, @i_ResultItemNum2, @i_ResultItemNum3, @i_ResultItemMinCount1, @i_ResultItemMinCount2, @i_ResultItemMinCount3,
		@i_ResultItemMaxCount1, @i_ResultItemMaxCount2, @i_ResultItemMaxCount3, @i_ResultItemProbabillity1, @i_ResultItemProbabillity2, @i_ResultItemProbabillity3)

END

GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_Log_Infinity_User_Get_TenderItem
-- DESC				: -- // 2010-06-25 by shcho, ���Ǵ�Ƽ ���÷α� ��� - ���� ������ ���� DB����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_Insert_Log_Infinity_User_Get_TenderItem
	@i_AccountUID			INT,
	@i_AccountName			VARCHAR(30),
	@i_CharacterUID			INT,
	@i_CharacterName		VARCHAR(30),
	@i_DiceCount			TINYINT,
	@i_ItemNum			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	INSERT INTO dbo.atum_Log_Infinity_UserGetTenderItemInfo(AccountUID, AccountName, CharacterUID, CharacterName, DiceCount, ItemNum)
	VALUES (@i_AccountUID, @i_AccountName, @i_CharacterUID, @i_CharacterName, @i_DiceCount, @i_ItemNum)
END

GO



----------------------------���Ǵ�Ƽ 3�� -----------------------------------------
----------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_MonsterMultiTarget
-- DESC			: // 2011-03-17 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
-- DESC			: ���� ��Ƽ Ÿ���� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_MonsterMultiTarget]
AS
BEGIN
	SELECT [MonsterIndex] ,[PointIndex] ,[x] ,[y] ,[z] FROM [atum2_db_account].[dbo].[ti_MonsterMultiTarget]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_MonsterMultiTarget
-- DESC			: // 2011-03-17 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
-- DESC			: ���� ��Ƽ Ÿ���� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_MonsterMultiTarget]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_MonsterMultiTarget]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_insert_MonsterMultiTarget
-- DESC			: // 2011-03-17 by hskim, ���Ǵ�Ƽ 3�� - ���� ��Ƽ Ÿ���� ��� �߰�
-- DESC			: ���� ��Ƽ Ÿ���� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_MonsterMultiTarget]
	@i_MonsterIndex			INT ,	-- Monster ��ȣ
	@i_PointIndex			INT ,	-- ����Ʈ �ε���
	@f_X					FLOAT ,	-- X ��ǥ
	@f_y					FLOAT ,	-- Y ��ǥ
	@f_z					FLOAT 	-- Z ��ǥ
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_MonsterMultiTarget] ([MonsterIndex], [PointIndex], [x], [y], [z])
		VALUES (@i_MonsterIndex, @i_PointIndex, @f_x, @f_y, @f_z)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_WayPointMove
-- DESC			: // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
-- DESC			: ��������Ʈ ���� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_WayPointMove]
AS
BEGIN
	SELECT [PatternIndex], [CompletionAction] FROM [atum2_db_account].[dbo].[ti_WayPointMove]
END
GO

CREATE PROC [dbo].[atum_Load_ti_WayPoint]
AS
BEGIN
	SELECT [PatternIndex], [SequenceNum], [PostionAttribute], [X] ,[Y] ,[Z] FROM [atum2_db_account].[dbo].[ti_WayPoint]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_WayPointMove
-- DESC			: // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
-- DESC			: ��������Ʈ ���� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_WayPointMove]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_WayPointMove]
END
GO

CREATE PROC [dbo].[atum_Delete_ti_WayPoint]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_WayPoint]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_WayPointMove
-- DESC			: // 2011-05-23 by hskim, ���Ǵ�Ƽ 3�� - ��������Ʈ ����
-- DESC			: ��������Ʈ ���� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_WayPointMove]
	@i_PatternIndex			INT ,		-- ���� ��ȣ
	@i_CompletionAction		TINYINT		-- �Ϸ� �� ����		(�ݺ�, �պ�, ����, ���� ����)
							------------------------------------------------------------------------------------------------------------------------------
							-- WAY_POINT_COMPLETION_ACTION_REPEAT			0		// �ݺ�	
							-- WAY_POINT_COMPLETION_ACTION_RECIPROCATION	1		// �պ�	
							-- WAY_POINT_COMPLETION_ACTION_STOP				2		// ����	
							------------------------------------------------------------------------------------------------------------------------------
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_WayPointMove] ([PatternIndex], [CompletionAction])
		VALUES (@i_PatternIndex, @i_CompletionAction)
END
GO

CREATE PROC [dbo].[atum_Insert_ti_WayPoint]
	@i_PatternIndex			INT ,		-- ���� ��ȣ
	@i_SequenceNum			INT ,		-- ��������Ʈ ����
	@i_PostionAttribute		TINYINT ,	-- �Ӽ�			(���� ��ǥ, ��� ��ǥ)
							------------------------------------------------------------------------------------------------------------------------------
							-- WAY_POINT_POSITION_ATTRIBUTE_RELATIVE		0		// ��� ��ǥ				- ���� ����
							-- WAY_POINT_POSITION_ATTRIBUTE_ABSOLUTE		1		// ���� ��ǥ
							------------------------------------------------------------------------------------------------------------------------------
	@f_X					FLOAT ,		-- X ��ǥ
	@f_Y					FLOAT ,		-- Y ��ǥ
	@f_Z					FLOAT 		-- Z ��ǥ
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_WayPoint] ([PatternIndex], [SequenceNum], [PostionAttribute], [X], [Y], [Z])
		VALUES (@i_PatternIndex, @i_SequenceNum, @i_PostionAttribute, @f_X, @f_Y, @f_Z)
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_WayPointMove
-- DESC			: // 2011-08-25 by shcho, Ƚ���� ������ ���ޱ�� ����
-- DESC			: ������ �̺�Ʈ ����, ����, üũ ���� ���ν���
--------------------------------------------------------------------------------

-----------------------------------------
-----------------------------------------
-- �̺�Ʈ Ƚ�� ���� ���ν���
-----------------------------------------
-----------------------------------------
CREATE PROC atum_InsertLoginItemEvent
@i_EventUniqueNumber		INT,
@i_AccountUniqueNumber	INT, 
@i_CompleteFlag		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
INSERT atum2_db_account.dbo.td_LoginEvent (EventUniqueNumber,AccountUniqueNumber,CompleteFlag)
VALUES(@i_EventUniqueNumber, @i_AccountUniqueNumber, @i_CompleteFlag)
END
GO

-----------------------------------------
-----------------------------------------
-- �̺�Ʈ ���� ���� ���ν��� 
-----------------------------------------
-----------------------------------------
CREATE PROC atum_EndLoginEvent	--�̺�Ʈ �Ⱓ�� �Ϸ�Ǹ� �ش� �̺�Ʈ�� ��� ������ �����Ѵ�.
@i_EventUniqueNumber INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
DELETE atum2_db_account.dbo.td_LoginEvent WHERE EventUniqueNumber = @i_EventUniqueNumber;
END

GO

-----------------------------------------
-----------------------------------------
-- üũ ���ν���
-----------------------------------------
-----------------------------------------
CREATE PROC [dbo].[atum_CheckLoginItemEvent]	--�̺�Ʈ Ƚ���� ã�� ���ν���(Ƚ���� count�� üũ�Ѵ�.)
@i_EventUniqueNumber	INT,
@i_AccountUniqueNumber	INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
--ī��Ʈ�� ��ȯ
DECLARE @check_completeCount INT, @successcount INT
SELECT @check_completeCount=CompleteFlag FROM atum2_db_account.dbo.td_LoginEvent WHERE EventUniqueNumber = @i_EventUniqueNumber and AccountUniqueNumber = @i_AccountUniqueNumber;
if(0 <> @check_completeCount) -- 0�� �ƴϸ� ī��Ʈ�� ��ȯ�ϸ� �ȵȴ�. -1�̸� �������� ������ ���̴�.
RETURN -10;
if(0 = @check_completeCount)  -- 0�̸� ī��Ʈ�� ��ȯ�Ѵ�.
SELECT @successcount=count(*) FROM atum2_db_account.dbo.td_LoginEvent WHERE EventUniqueNumber = @i_EventUniqueNumber and AccountUniqueNumber = @i_AccountUniqueNumber;
RETURN @successcount;
END

GO





------------------------EP4 [Ʈ���� �ý���] - ũ����Ż �ý���----------------------
----------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_MapBuff
-- DESC			: //2011-10-10 by hskim, EP4 [Ʈ���� �ý���] - ȭ���� / �� ��ǳ
-- DESC			: EP4 Ʈ���� �ý��� (ȭ����/����ǳ) ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_MapBuff]
AS
BEGIN
	SELECT [MapIndex] ,[ItemNum] FROM [atum2_db_account].[dbo].[ti_MapBuff]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_MapBuff
-- DESC			: //2011-10-10 by hskim, EP4 [Ʈ���� �ý���] - ȭ���� / �� ��ǳ
-- DESC			: EP4 Ʈ���� �ý��� (ȭ����/����ǳ) ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_MapBuff]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_MapBuff]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_MapBuff
-- DESC			: //2011-10-10 by hskim, EP4 [Ʈ���� �ý���] - ȭ���� / �� ��ǳ
-- DESC			: EP4 Ʈ���� �ý��� (ȭ����/����ǳ) ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_MapBuff]
	@i_MapIndex			INT,	-- ���� �� ��ȣ
	@i_ItemNum			INT		-- ���� ��ų ��ȣ
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_MapBuff] ([MapIndex], [ItemNum])
		VALUES (@i_MapIndex, @i_ItemNum)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_MapTrigger
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_MapTrigger]
AS
BEGIN
	SELECT [MapTriggerID], [MapIndex], [MapChannel], [FunctionID] FROM [atum2_db_account].[dbo].[ti_MapTrigger]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_MapTrigger
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_MapTrigger]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_MapTrigger]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_MapTrigger
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_MapTrigger]
	@i_MapTriggerID		INT,
	@i_MapIndex			INT,
	@i_MapChannel		SMALLINT,
	@i_FunctionID		INT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_MapTrigger] ([MapTriggerID], [MapIndex], [MapChannel], [FunctionID])
		VALUES (@i_MapTriggerID, @i_MapIndex, @i_MapChannel, @i_FunctionID)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_TriggerFunctionCrystal
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_TriggerFunctionCrystal]
AS
BEGIN
	SELECT [FunctionID], [CrystalGroupID], [PeriodTime], [RandomSequence] FROM [atum2_db_account].[dbo].[ti_TriggerFunctionCrystal]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_TriggerFunctionCrystal
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_TriggerFunctionCrystal]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_TriggerFunctionCrystal]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_TriggerFunctionCrystal
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_TriggerFunctionCrystal]
	@i_FunctionID		INT,
	@i_CrystalGroupID	INT,
	@i_PeriodTime		INT,
	@i_RandomSequence	TINYINT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_TriggerFunctionCrystal] ([FunctionID], [CrystalGroupID], [PeriodTime], [RandomSequence])
		VALUES (@i_FunctionID, @i_CrystalGroupID, @i_PeriodTime, @i_RandomSequence)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_TriggerCrystalGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_TriggerCrystalGroup]
AS
BEGIN
	SELECT [CrystalGroupID], [DestroyGroupID], [EventID] FROM [atum2_db_account].[dbo].[ti_TriggerCrystalGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_TriggerCrystalGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_TriggerCrystalGroup]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_TriggerCrystalGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_TriggerCrystalGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_TriggerCrystalGroup]
	@i_CrystalGroupID	INT,
	@i_DestroyGroupID	INT,
	@i_EventID			INT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_TriggerCrystalGroup] ([CrystalGroupID], [DestroyGroupID], [EventID])
		VALUES (@i_CrystalGroupID, @i_DestroyGroupID, @i_EventID)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_TriggerCrystalDestroyGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_TriggerCrystalDestroyGroup]
AS
BEGIN
	SELECT [DestroyGroupID], [SequenceNumber], [TargetMonster] FROM [atum2_db_account].[dbo].[ti_TriggerCrystalDestroyGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_TriggerCrystalDestroyGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_TriggerCrystalDestroyGroup]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_TriggerCrystalDestroyGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_TriggerCrystalDestroyGroup
-- DESC			: // 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - ũ����Ż �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_TriggerCrystalDestroyGroup]
	@i_DestroyGroupID	INT,
	@i_SequenceNumber	SMALLINT,
	@i_TargetMonster	INT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_TriggerCrystalDestroyGroup] ([DestroyGroupID], [SequenceNumber], [TargetMonster])
		VALUES (@i_DestroyGroupID, @i_SequenceNumber, @i_TargetMonster)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_TriggerFunctionNGCInflWar
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_TriggerFunctionNGCInflWar]
AS
BEGIN
	SELECT [FunctionID], [NGCInflWarGroupID], [PeriodTime], [BossMonster], [WinInfluenceWP], [LossInfluenceWP], [FirstDamageGuildWP], [FixedTimeType] FROM [atum2_db_account].[dbo].[ti_TriggerFunctionNGCInflWar]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_TriggerFunctionNGCInflWar
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_TriggerFunctionNGCInflWar]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_TriggerFunctionNGCInflWar]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_TriggerFunctionNGCInflWar
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_TriggerFunctionNGCInflWar]
	@i_FunctionID			INT,
	@i_NGCInflWarGroupID	INT,
	@i_PeriodTime			INT,
	@i_BossMonster			INT,
	@i_WinInfluenceWP		INT,
	@i_LossInfluenceWP		INT,
	@i_FirstDamageGuildWP	INT,
	@i_FixedTimeType		INT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_TriggerFunctionNGCInflWar] ([FunctionID], [NGCInflWarGroupID], [PeriodTime], [BossMonster], [WinInfluenceWP], [LossInfluenceWP], [FirstDamageGuildWP], [FixedTimeType])
		VALUES (@i_FunctionID, @i_NGCInflWarGroupID, @i_PeriodTime, @i_BossMonster, @i_WinInfluenceWP, @i_LossInfluenceWP, @i_FirstDamageGuildWP, @i_FixedTimeType)
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Load_ti_TriggerNGCInflWarMonsterGroup
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� �ε� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Load_ti_TriggerNGCInflWarMonsterGroup]
AS
BEGIN
	SELECT [NGCInflWarGroupID], [Monster], [SummonCount], [SummonRandmomPos] FROM [atum2_db_account].[dbo].[ti_TriggerNGCInflWarMonsterGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Delete_ti_TriggerNGCInflWarMonsterGroup
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_ti_TriggerNGCInflWarMonsterGroup]
AS
BEGIN
	DELETE FROM [atum2_db_account].[dbo].[ti_TriggerNGCInflWarMonsterGroup]
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Insert_ti_TriggerNGCInflWarMonsterGroup
-- DESC			: // 2011-11-07 by hskim, EP4 [Ʈ���� �ý���] - NCG ������ �ý���
-- DESC			: EP4 [Ʈ���� �ý���] - NCG ������ �ý��� ���� ������ ���� ���ν��� ( Execl �б� )
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ti_TriggerNGCInflWarMonsterGroup]
	@i_NGCInflWarGroupID	INT,
	@i_Monster				INT,
	@i_SummonCount			INT,
	@i_SummonRandmomPos		INT
AS
BEGIN
	INSERT INTO [atum2_db_account].[dbo].[ti_TriggerNGCInflWarMonsterGroup] ([NGCInflWarGroupID], [Monster], [SummonCount], [SummonRandmomPos])
		VALUES (@i_NGCInflWarGroupID, @i_Monster, @i_SummonCount, @i_SummonRandmomPos)
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_Update_PetSocketOwner
-- DESC				: ��Ʈ�� ���Ͼ������� ���� ĳ���� ����
-- // 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�
-------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_PetSocketOwner]
	@i_SocketUN			BIGINT,
	@i_Possess			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	UPDATE [dbo].[td_Store] SET [Possess] = @i_Possess WHERE [UniqueNumber] = @i_SocketUN
END
GO

-------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetStoreItemOne
-- DESC				: ��Ʈ�� ���Ͼ������� ���� ĳ���� ����
-- // 2012-01-30 by hskim, ��Ʈ�� �ý��� 2�� - ���� â�� �̵�
-------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetStoreItemOne]
	@i_UniqueNumber		BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT UniqueNumber,AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,
		NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,
		ShapeItemNum,MainSvrItemUID,CoolingTime
	FROM td_Store
	WHERE UniqueNumber = @i_UniqueNumber
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_log_Insert_StatisticsMoney
-- DESC				: // 2012-01-16 by hskim, ��� - ȭ��
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_log_Insert_StatisticsMoney]
	@i_LogType				TINYINT,
	@i_Function				TINYINT,
	@i_DeltaSPI				BIGINT,
	@i_DeltaWarPoint		BIGINT,
	@i_DeltaSystemOrb		BIGINT,
	@i_DeltaQuasarOrb		BIGINT,
	@i_DeltaClusterOrb		BIGINT,
	@i_DeltaGalaxyOrb		BIGINT,
	@i_DeltaUniverseOrb		BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	INSERT INTO [atum2_db_1].[dbo].[atum_log_statistics_money] ([LogType], [Function], [Time],[DeltaSPI], [DeltaWarPoint], [DeltaSystemOrb], [DeltaQuasarOrb], [DeltaClusterOrb], [DeltaGalaxyOrb], [DeltaUniverseOrb])
     VALUES(@i_LogType, @i_Function, getdate(), @i_DeltaSPI, @i_DeltaWarPoint, @i_DeltaSystemOrb, @i_DeltaQuasarOrb, @i_DeltaClusterOrb, @i_DeltaGalaxyOrb, @i_DeltaUniverseOrb)
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_log_Search_StatisticsMoney
-- DESC				: // 2012-02-27 by jhseol, ��� - ȭ�� �˻����ν���
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_log_Search_StatisticsMoney]
	@StartTime	datetime,
	@EndTime	datetime
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [Function]
      ,[Time]
      ,[DeltaSPI]
      ,[DeltaWarPoint]
      ,[DeltaSystemOrb]
      ,[DeltaQuasarOrb]
      ,[DeltaClusterOrb]
      ,[DeltaGalaxyOrb]
      ,[DeltaUniverseOrb]
    FROM [atum2_db_1].[dbo].[atum_log_statistics_money]
	WHERE [Time] >= @StartTime AND [Time] < @EndTime
END
GO

--> 120410_DB��Ű��_(������_��Ʈ�ʱ��)_atum2_db_[n]
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_log_Insert_pet_info_updata
-- DESC				: // 2012-03-15 by jhseol, ��Ʈ�� - ��Ʈ�� �������� �α� ���� ���ν���
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_log_Insert_pet_info_updata]
	@i_AccountUID			INT,
	@i_CharacterUID			INT,
	@i_AdministratorName	VARCHAR(20),
	@i_PetItemUID			BIGINT,
	@i_PetIndex				INT,
	@i_PetName				VARCHAR(40),
	@i_PetUpdataName		VARCHAR(40),
	@i_PetLevel				INT,
	@i_PetUpdataLevel		INT,
	@i_PetExperience		FLOAT,
	@i_PetUpdataExperience	FLOAT,
	@i_PetSocketItem1		BIGINT,
	@i_PetUpdataSocketItem1	BIGINT,
	@i_PetSocketItem2		BIGINT,
	@i_PetUpdataSocketItem2	BIGINT,
	@i_PetSocketItem3		BIGINT,
	@i_PetUpdataSocketItem3	BIGINT,
	@i_PetSocketItem4		BIGINT,
	@i_PetUpdataSocketItem4	BIGINT,
	@i_PetSocketItem5		BIGINT,
	@i_PetUpdataSocketItem5	BIGINT,
	@i_PetSocketItem6		BIGINT,
	@i_PetUpdataSocketItem6	BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	INSERT INTO [atum2_db_1].[dbo].[atum_log_pet_info_updata] ([Time], [AccountUID], [CharacterUID], [AdministratorName],
		[PetItemUID], [PetIndex],
		[PetName], [PetUpdataName],
		[PetLevel], [PetUpdataLevel],
		[PetExperience], [PetUpdataExperience],
		[PetSocketItem1], [PetUpdataSocketItem1], 
		[PetSocketItem2], [PetUpdataSocketItem2], 
		[PetSocketItem3], [PetUpdataSocketItem3], 
		[PetSocketItem4], [PetUpdataSocketItem4], 
		[PetSocketItem5], [PetUpdataSocketItem5], 
		[PetSocketItem6], [PetUpdataSocketItem6])
     VALUES(getdate(), @i_AccountUID, @i_CharacterUID, @i_AdministratorName, 
		@i_PetItemUID, @i_PetIndex, 
		@i_PetName, @i_PetUpdataName, 
		@i_PetLevel, @i_PetUpdataLevel, 
		@i_PetExperience, @i_PetUpdataExperience, 
		@i_PetSocketItem1, @i_PetUpdataSocketItem1, 
		@i_PetSocketItem2, @i_PetUpdataSocketItem2, 
		@i_PetSocketItem3, @i_PetUpdataSocketItem3, 
		@i_PetSocketItem4, @i_PetUpdataSocketItem4, 
		@i_PetSocketItem5, @i_PetUpdataSocketItem5, 
		@i_PetSocketItem6, @i_PetUpdataSocketItem6)
END
GO

--> 120619_DB��Ű��_(�Ʒ��� ������ ������)_DBQuery(atum2_db_[n])
---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_arena_CharacterArena_Insert]
-- DESC: 2012-05-14 by jhseol, ĳ���Ϳ� ���� �Ʒ��� ���� �μ�Ʈ ����
---------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_arena_CharacterArena_Insert]
	@i_CharacterUID				INT,		-- ĳ���� UID
	@i_AccountUID				INT			-- ���� UID
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	INSERT INTO [dbo].[td_CharacterArena]([CharacterUID], [CharacterName], [AccountName], [AccountUID])
     SELECT UniqueNumber, CharacterName, AccountName, AccountUniqueNumber
     FROM td_Character
     WHERE UniqueNumber = @i_CharacterUID AND AccountUniqueNumber = @i_AccountUID
END
GO


---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_arena_CharacterArena_Insert]
-- DESC: 2012-05-14 by jhseol, ĳ���Ϳ� ���� �Ʒ��� ���� �������� ����
---------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_arena_CharacterArena_Get]
	@i_CharacterUID				INT,		-- ĳ���� UID
	@i_AccountUID				INT			-- ���� UID
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT	[PlayCount], [LastPlayTime]
	FROM	[dbo].[td_CharacterArena]
	WHERE	[CharacterUID] = @i_CharacterUID AND [AccountUID] = @i_AccountUID
END
GO



---------------------------------------------------------------------
-- PROCEDURE NAME: [atum_arena_CharacterArena_Insert]
-- DESC: 2012-05-14 by jhseol, ĳ���Ϳ� ���� �Ʒ��� ���� ������Ʈ ����
---------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_arena_CharacterArena_Updata]
	@i_CharacterUID				INT,		-- ĳ���� UID
	@i_AccountUID				INT,		-- ���� UID
	@i_PlayCount				INT,		-- �Ʒ��� �÷��� Ƚ��
	@i_LastPlayTime				DATETIME	-- ������ �Ʒ��� �÷��� �ð�
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	UPDATE	[dbo].[td_CharacterArena]
	SET		[PlayCount] = @i_PlayCount, [LastPlayTime] = @i_LastPlayTime
	WHERE	[CharacterUID] = @i_CharacterUID AND [AccountUID] = @i_AccountUID
END
GO


-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'
--> 120619_DB��Ű��_(�Ʒ��� ������ ������)_DBQuery(Only_atum2_db_[n])
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_Get_Arena_SoruceCharacterInfo
-- DESC				: �Ʒ��� ������ ���� �ɸ��� ���� ��������, ���� ���ο��� �ִ� ����
-- 2012-06-17 by jhseol,
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[arena_Get_Arena_SoruceCharacterInfo]
	@i_CharacterName varchar(20)
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, Race, UnitKind, AttackPart, DefensePart, FuelPart, SoulPart, ShieldPart, DodgePart, Level, Experience, BodyCondition, Propensity, Status, HP, DP, SP, EP, BonusStat, BonusStatPoint
	FROM td_Character WITH (NOLOCK) WHERE CharacterName = @i_CharacterName
'
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
GO

-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_Get_Arena_SoruceCharacterInfo_Skill
-- DESC				: �Ʒ��� ������ ���� �ɸ��� ���� �������� ��ų, ���� ���ο��� �ִ� ����
-- 2012-06-17 by jhseol,
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[arena_Get_Arena_SoruceCharacterInfo_Skill]
	@i_CUID int
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT ItemNum FROM td_StoreSkill WITH (NOLOCK) WHERE Possess = @i_CUID
'
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
GO


-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_Get_Arena_SoruceCharacterInfo_Item
-- DESC				: �Ʒ��� ������ ���� �ɸ��� ���� �������� ������, ���� ���ο��� �ִ� ����
-- 2012-06-17 by jhseol,
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[arena_Get_Arena_SoruceCharacterInfo_Item]
	@i_CUID int
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT UniqueNumber, ItemStorage, Wear, CurrentCount, ItemWindowIndex, ItemNum, PrefixCodeNum, SuffixCodeNum, CurrentEndurance
	FROM td_Store WITH (NOLOCK) WHERE Possess = @i_CUID
'
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
GO


-- 2009-10-09 by cmkwon, �Ʒ���DB(atum2_db_arena)�� �ƴҰ�츸 �߰��ǵ��� ó��
IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
BEGIN
	EXEC dbo.sp_executesql @statement = N'
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_Get_Arena_SoruceCharacterInfo_Enchant
-- DESC				: �Ʒ��� ������ ���� �ɸ��� ���� �������� ��þƮ, ���� ���ο��� �ִ� ����
-- 2012-06-17 by jhseol,
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[arena_Get_Arena_SoruceCharacterInfo_Enchant]
	@i_StoreUID bigint
	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT COUNT(*), EnchantItemNum
	FROM td_Enchant WITH (NOLOCK)
	WHERE TargetItemUniqueNumber = @i_StoreUID
	GROUP BY [EnchantItemNum]
'
END -- END - IF 'atum2_db_arena' <> (SELECT DB_NAME() AS [Current Database])
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetEnchantCountByItemUID
-- DESC			: // 2012-08-27 by hskim, ��Ʈ�� ��þƮ �� ���� �߰� ���� ó�� (�ڵ���� �������� �߰ߵ��� �ʾ����� ������ ��쿡�� �α׸� �����) (����ȭ DB ������ �õ��ؼ� ���� ���ϰ� ���� : �ʿ���ٰ� �ǴܵǸ� ���� ����)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_GetEnchantCountByItemUID]
	@i_TargetItemUniqueNumber		BIGINT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT count(*) FROM [dbo].[td_Enchant] WITH(NOLOCK) WHERE [TargetItemUniqueNumber] = @i_TargetItemUniqueNumber
END
GO



--> 120912_DB��Ű��_(��ü���� WebPage ��������)_DBQuery(Only_atum2_db_[n])
CREATE PROCEDURE dbo.atum_GetInfluenceInfo
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetInfluenceInfo
-- DESC				: ���������� ������ �������� ����
-- 2012-08-31 by jhseol, Ȩ������ ���� : �������� ����
--------------------------------------------------------------------------------
	@i_MGameServerID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	DECLARE @InfluenceType				TINYINT
	DECLARE @ContributionPoint			INT
	DECLARE @WarStep					TINYINT
	DECLARE @InflLeaderCharacterUID		INT
	DECLARE @InflLeaderCharacterName	VARCHAR(20)
	DECLARE @TopGuildName				VARCHAR(30)
	DECLARE @TopGulidCommanderName		VARCHAR(20)
	DECLARE @RoofIndex					TINYINT

	CREATE TABLE #WarInfo (InfluenceType TINYINT, ContributionPoint INT, WarStep INT, InflLeaderCharacterName VARCHAR(20), TopGuildName VARCHAR(30), TopGulidCommanderName VARCHAR(20))

	DECLARE CursorInfluenceInfo CURSOR LOCAL FOR 
		SELECT InfluenceType, ContributionPoint, InflLeaderCharacterUID, WartimeStage
		FROM td_InfluenceWarData
		WHERE MGameServerID = @i_MGameServerID
	OPEN CursorInfluenceInfo
	FETCH NEXT FROM CursorInfluenceInfo INTO @InfluenceType, @ContributionPoint, @InflLeaderCharacterUID, @WarStep
	WHILE @@FETCH_STATUS = 0
	BEGIN
		SET @InflLeaderCharacterName = NULL
		IF @InflLeaderCharacterUID IS NOT NULL
		BEGIN
			SELECT @InflLeaderCharacterName = CharacterName
			FROM td_Character WHERE UniqueNumber = @InflLeaderCharacterUID
		END
		INSERT INTO #WarInfo(InfluenceType, ContributionPoint, InflLeaderCharacterName, WarStep)
		VALUES(@InfluenceType, @ContributionPoint, @InflLeaderCharacterName, @WarStep)
		FETCH NEXT FROM CursorInfluenceInfo INTO @InfluenceType, @ContributionPoint, @InflLeaderCharacterUID, @WarStep
	END

	SET @RoofIndex = 2
	WHILE @RoofIndex = 2 OR @RoofIndex = 4
	BEGIN
		SET @TopGuildName = NULL
		SELECT TOP 1 @TopGuildName = G.GuildName, @TopGulidCommanderName = C.CharacterName, @InfluenceType = C.InfluenceType
		FROM td_Character AS C, td_Guild AS G
		WHERE G.GuildCommanderUniqueNumber = C.UniqueNumber AND C.InfluenceType = @RoofIndex ORDER BY G.TotalFame DESC
		IF @TopGuildName IS NOT NULL
		BEGIN
			UPDATE #WarInfo
			SET TopGuildName = @TopGuildName, TopGulidCommanderName = @TopGulidCommanderName
			WHERE InfluenceType = @InfluenceType
		END
		
		SET @RoofIndex = @RoofIndex + @RoofIndex
	END
	

	SELECT InfluenceType, ContributionPoint, WarStep, InflLeaderCharacterName, TopGuildName, TopGulidCommanderName
	FROM #WarInfo
	DROP TABLE #WarInfo
END
GO


CREATE PROCEDURE dbo.atum_GetRankGuild
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetRankGuild
-- DESC				: ���������� ������ ��� ��ŷ ���� ����, ��DB���� ���ν��� ȣ��.
-- 2012-08-23 by jhseol, Ȩ������ ���� : ��� ��ŷ���� ����
--------------------------------------------------------------------------------
	@i_ServerName		VARCHAR(10),
	@i_TotalScope		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	IF ( @i_TotalScope > 100 ) SET @i_TotalScope = 100

	DECLARE	@GuildUID		INT
	DECLARE	@Name			VARCHAR(30)
	DECLARE @MemberCount	INT
	DECLARE @CommanderName	VARCHAR(10)
	DECLARE @CommanderUID	INT
	DECLARE @TotalFame		INT
	DECLARE @MonthlyFame	INT
	DECLARE @Influence		VARCHAR(30)
	DECLARE @Index			INT
	DECLARE @tempName		VARCHAR(20)
		
	CREATE TABLE #tRankGuild(ServerName VARCHAR(10), Name VARCHAR(30), MemberCount INT,	CommanderName VARCHAR(10), TotalFame INT, MonthlyFame INT, Influence VARCHAR(30))

	/*��ü start********************************************************************************************************/
	SET @Index = 0
	SET @CommanderUID = NULL
	DECLARE CursorTotalRank CURSOR LOCAL FOR 
		SELECT GuildUniqueNumber, GuildName, GuildCommanderUniqueNumber, TotalFame, MonthlyFame
		FROM td_Guild WITH(NOLOCK) WHERE TotalFame >= 0 ORDER BY TotalFame DESC
	OPEN CursorTotalRank
	FETCH NEXT FROM CursorTotalRank INTO @GuildUID, @Name, @CommanderUID, @TotalFame, @MonthlyFame
	WHILE @@FETCH_STATUS = 0 AND @Index < @i_TotalScope
	BEGIN
		SET @tempName = NULL
		IF ((SELECT Name FROM #tRankGuild WHERE Name = @Name) IS NULL)
		BEGIN
			SELECT @CommanderName = CharacterName, @Influence = InfluenceType
			FROM td_Character WITH(NOLOCK) WHERE UniqueNumber = @CommanderUID
			
			SELECT @MemberCount = COUNT(UniqueNumber)
			FROM td_Character WITH(NOLOCK) WHERE GuildUniqueNumber = @GuildUID
			
			IF ( @Influence = 2) SET @Influence = 'BCU'
			ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
			ELSE SET @Influence = NULL
		
			IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CommanderName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
			BEGIN
				INSERT INTO #tRankGuild(ServerName, Name, MemberCount, CommanderName, TotalFame, MonthlyFame, Influence)
				VALUES(@i_ServerName, @Name, @MemberCount, @CommanderName, @TotalFame, @MonthlyFame, @Influence)
				SET @Index = @Index - 1
				IF ( @Index < 0 ) SET @Index = 0
			END
			FETCH NEXT FROM CursorTotalRank INTO @GuildUID, @Name, @CommanderUID, @TotalFame, @MonthlyFame
		END
		SET @Index = @Index + 1
	END
	CLOSE CursorTotalRank
	DEALLOCATE CursorTotalRank
	/*��ü start********************************************************************************************************/
	
	
	/*���� start********************************************************************************************************/
	SET @Index = 0
	SET @CommanderUID = NULL
	DECLARE CursorTotalRank CURSOR LOCAL FOR 
		SELECT GuildUniqueNumber, GuildName, GuildCommanderUniqueNumber, TotalFame, MonthlyFame
		FROM td_Guild WITH(NOLOCK) WHERE MonthlyFame >= 0 ORDER BY TotalFame DESC
	OPEN CursorTotalRank
	FETCH NEXT FROM CursorTotalRank INTO @GuildUID, @Name, @CommanderUID, @TotalFame, @MonthlyFame
	WHILE @@FETCH_STATUS = 0 AND @Index < @i_TotalScope
	BEGIN
		SET @tempName = NULL
		IF ((SELECT Name FROM #tRankGuild WHERE Name = @Name) IS NULL)
		BEGIN
			SELECT @CommanderName = CharacterName, @Influence = InfluenceType
			FROM td_Character WITH(NOLOCK) WHERE UniqueNumber = @CommanderUID
			
			SELECT @MemberCount = COUNT(UniqueNumber)
			FROM td_Character WITH(NOLOCK) WHERE GuildUniqueNumber = @GuildUID
			
			IF ( @Influence = 2) SET @Influence = 'BCU'
			ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
			ELSE SET @Influence = NULL
		
			IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CommanderName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
			BEGIN
				INSERT INTO #tRankGuild(ServerName, Name, MemberCount, CommanderName, TotalFame, MonthlyFame, Influence)
				VALUES(@i_ServerName, @Name, @MemberCount, @CommanderName, @TotalFame, @MonthlyFame, @Influence)
				SET @Index = @Index - 1
				IF ( @Index < 0 ) SET @Index = 0
			END
			FETCH NEXT FROM CursorTotalRank INTO @GuildUID, @Name, @CommanderUID, @TotalFame, @MonthlyFame
		END
		SET @Index = @Index + 1
	END
	CLOSE CursorTotalRank
	DEALLOCATE CursorTotalRank
	/*���� start********************************************************************************************************/

	
	SELECT ServerName, Name, MemberCount, CommanderName, TotalFame, MonthlyFame, Influence FROM #tRankGuild
	DROP TABLE #tRankGuild
END
GO


CREATE PROCEDURE dbo.atum_GetRankPersonal
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetRankPersonal
-- DESC				: ���������� ������ ���� ��ŷ ���� ����, ��DB���� ���ν��� ȣ��.
-- 2012-08-23 by jhseol, Ȩ������ ���� : ���� ��ŷ���� ����
--------------------------------------------------------------------------------
	@i_ServerName		VARCHAR(10),
	@i_TotalScope		INT,
	@i_GearScope		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	IF ( @i_TotalScope > 100 ) SET @i_TotalScope = 100
	IF ( @i_GearScope > 50 ) SET @i_GearScope = 50

	DECLARE	@CharacterName	VARCHAR(20)
	DECLARE @Gear			INT
	DECLARE @Level			TINYINT
	DECLARE @Experience		FLOAT
	DECLARE @Propensity		INT
	DECLARE @Score			INT
	DECLARE @PKWinPoint		SMALLINT
	DECLARE @PKLossPoint	SMALLINT
	DECLARE @GuildName		VARCHAR(30)
	DECLARE @Influence		VARCHAR(30)
	DECLARE @Index			INT
	DECLARE @GearIndex		INT
	DECLARE @tempName		VARCHAR(20)
	DECLARE @SelectGear		INT
	DECLARE @SelectRace		SMALLINT
	SET @SelectRace = 2
		
	CREATE TABLE #tRankPersonal(ServerName VARCHAR(10), CharacterName VARCHAR(20), Gear TINYINT, [Level] TINYINT, Experience FLOAT, Propensity INT, Score INT, PKWinPoint SMALLINT, PKLossPoint SMALLINT, GuildName VARCHAR(30), Influence VARCHAR(30))

	/*���� start********************************************************************************************************/
	SET @Index = 0
	SET @GearIndex = 0
	DECLARE CursorTotalRank CURSOR LOCAL FOR 
		SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType 
		FROM td_Character WITH(NOLOCK) WHERE Race = @SelectRace AND Experience > 0 ORDER BY Experience DESC
	OPEN CursorTotalRank
	FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
	WHILE @@FETCH_STATUS = 0 AND @Index < @i_TotalScope
	BEGIN
		SET @tempName = NULL
		IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
		BEGIN
			IF (@Gear = 1) SET @Gear = 1
			ELSE IF (@Gear = 16) SET @Gear = 2
			ELSE IF (@Gear = 256) SET @Gear = 3
			ELSE IF (@Gear = 4096) SET @Gear = 4
			
			IF ( @Influence = 1) SET @Influence = 'Normal'
			ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
			ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
			ELSE SET @Influence = NULL
			
			IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
			BEGIN
				INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
				VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
				SET @Index = @Index - 1
				IF ( @Index < 0 ) SET @Index = 0
			END
			FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		END
		SET @Index = @Index + 1
	END
	CLOSE CursorTotalRank
	DEALLOCATE CursorTotalRank
	WHILE @GearIndex < 4
	BEGIN
		IF (@GearIndex = 0) SET @SelectGear = 1
		ELSE IF (@GearIndex = 1) SET @SelectGear = 16
		ELSE IF (@GearIndex = 2) SET @SelectGear = 256
		ELSE IF (@GearIndex = 3) SET @SelectGear = 4096
		
		SET @Index = 0
		DECLARE CursorBGearRank CURSOR LOCAL FOR 
			SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType
			FROM td_Character WITH(NOLOCK) WHERE UnitKind = @SelectGear AND Race = @SelectRace AND Experience > 0 ORDER BY Experience DESC
		OPEN CursorBGearRank
		FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		WHILE @@FETCH_STATUS = 0 AND @Index < @i_GearScope
		BEGIN
			SET @tempName = NULL
			IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
			BEGIN
				IF (@Gear = 1) SET @Gear = 1
				ELSE IF (@Gear = 16) SET @Gear = 2
				ELSE IF (@Gear = 256) SET @Gear = 3
				ELSE IF (@Gear = 4096) SET @Gear = 4

				IF ( @Influence = 1) SET @Influence = 'Normal'
				ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
				ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
				ELSE SET @Influence = NULL

				IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
				BEGIN
					INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
					VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
					SET @Index = @Index - 1
					IF ( @Index < 0 ) SET @Index = 0
				END
			END
			FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
			SET @Index = @Index + 1
		END
		CLOSE CursorBGearRank
		DEALLOCATE CursorBGearRank
		SET @GearIndex = @GearIndex + 1
	END
	/*���� end********************************************************************************************************/


	/*�� start********************************************************************************************************/
	SET @Index = 0
	SET @GearIndex = 0
	DECLARE CursorTotalRank CURSOR LOCAL FOR 
		SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType 
		FROM td_Character WITH(NOLOCK) WHERE Race = @SelectRace AND Propensity > 0 ORDER BY Propensity DESC
	OPEN CursorTotalRank
	FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
	WHILE @@FETCH_STATUS = 0 AND @Index < @i_TotalScope
	BEGIN
		SET @tempName = NULL
		IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
		BEGIN
			IF (@Gear = 1) SET @Gear = 1
			ELSE IF (@Gear = 16) SET @Gear = 2
			ELSE IF (@Gear = 256) SET @Gear = 3
			ELSE IF (@Gear = 4096) SET @Gear = 4

			IF ( @Influence = 1) SET @Influence = 'Normal'
			ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
			ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
			ELSE SET @Influence = NULL

			IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
			BEGIN
				INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
				VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
				SET @Index = @Index - 1
				IF ( @Index < 0 ) SET @Index = 0
			END
			FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		END
		SET @Index = @Index + 1
	END
	CLOSE CursorTotalRank
	DEALLOCATE CursorTotalRank
	WHILE @GearIndex < 4
	BEGIN
			IF (@Gear = 1) SET @Gear = 1
			ELSE IF (@Gear = 16) SET @Gear = 2
			ELSE IF (@Gear = 256) SET @Gear = 3
			ELSE IF (@Gear = 4096) SET @Gear = 4
		
		SET @Index = 0
		DECLARE CursorBGearRank CURSOR LOCAL FOR 
			SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType
			FROM td_Character WITH(NOLOCK) WHERE UnitKind = @SelectGear AND Race = @SelectRace AND Propensity > 0 ORDER BY Propensity DESC
		OPEN CursorBGearRank
		FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		WHILE @@FETCH_STATUS = 0 AND @Index < @i_GearScope
		BEGIN
			SET @tempName = NULL
			IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
			BEGIN
				IF (@Gear = 1) SET @Gear = 1
				ELSE IF (@Gear = 16) SET @Gear = 2
				ELSE IF (@Gear = 256) SET @Gear = 3
				ELSE IF (@Gear = 4096) SET @Gear = 4

				IF ( @Influence = 1) SET @Influence = 'Normal'
				ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
				ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
				ELSE SET @Influence = NULL

				IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
				BEGIN
					INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
					VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
					SET @Index = @Index - 1
					IF ( @Index < 0 ) SET @Index = 0
				END
			END
			FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
			SET @Index = @Index + 1
		END
		CLOSE CursorBGearRank
		DEALLOCATE CursorBGearRank
		SET @GearIndex = @GearIndex + 1
	END
	/*�� end********************************************************************************************************/


	/*PVP start********************************************************************************************************/
	SET @Index = 0
	SET @GearIndex = 0
	DECLARE CursorTotalRank CURSOR LOCAL FOR 
		SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType 
		FROM td_Character WITH(NOLOCK) WHERE Race = @SelectRace AND (PKWinPoint*10-PKLossPoint*5) > 0 ORDER BY (PKWinPoint*10-PKLossPoint*5) DESC
	OPEN CursorTotalRank
	FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
	WHILE @@FETCH_STATUS = 0 AND @Index < @i_TotalScope
	BEGIN
		SET @tempName = NULL
		IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
		BEGIN
			IF (@Gear = 1) SET @Gear = 1
			ELSE IF (@Gear = 16) SET @Gear = 2
			ELSE IF (@Gear = 256) SET @Gear = 3
			ELSE IF (@Gear = 4096) SET @Gear = 4

			IF ( @Influence = 1) SET @Influence = 'Normal'
			ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
			ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
			ELSE SET @Influence = NULL

			IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
			BEGIN
				INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
				VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
				SET @Index = @Index - 1
				IF ( @Index < 0 ) SET @Index = 0
			END
			FETCH NEXT FROM CursorTotalRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		END
		SET @Index = @Index + 1
	END
	CLOSE CursorTotalRank
	DEALLOCATE CursorTotalRank
	WHILE @GearIndex < 4
	BEGIN
			IF (@Gear = 1) SET @Gear = 1
			ELSE IF (@Gear = 16) SET @Gear = 2
			ELSE IF (@Gear = 256) SET @Gear = 3
			ELSE IF (@Gear = 4096) SET @Gear = 4
		
		SET @Index = 0
		DECLARE CursorBGearRank CURSOR LOCAL FOR 
			SELECT CharacterName, UnitKind, [Level], Experience, Propensity, (PKWinPoint*10-PKLossPoint*5), PKWinPoint, PKLossPoint, GuildName, InfluenceType
			FROM td_Character WITH(NOLOCK) WHERE UnitKind = @SelectGear AND Race = @SelectRace AND (PKWinPoint*10-PKLossPoint*5) > 0 ORDER BY (PKWinPoint*10-PKLossPoint*5) DESC
		OPEN CursorBGearRank
		FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
		WHILE @@FETCH_STATUS = 0 AND @Index < @i_GearScope
		BEGIN
			SET @tempName = NULL
			IF ((SELECT CharacterName FROM #tRankPersonal WHERE CharacterName = @CharacterName) IS NULL)
			BEGIN
				IF (@Gear = 1) SET @Gear = 1
				ELSE IF (@Gear = 16) SET @Gear = 2
				ELSE IF (@Gear = 256) SET @Gear = 3
				ELSE IF (@Gear = 4096) SET @Gear = 4

				IF ( @Influence = 1) SET @Influence = 'Normal'
				ELSE IF ( @Influence = 2) SET @Influence = 'BCU'
				ELSE IF ( @Influence = 4) SET @Influence = 'ANI'
				ELSE SET @Influence = NULL

				IF ((SELECT AccountName FROM td_Character WHERE CharacterName = @CharacterName AND ( AccountName like '%@%' OR AccountName like '%#%' )) IS NULL)
				BEGIN
					INSERT INTO #tRankPersonal(ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence)
					VALUES(@i_ServerName, @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence)
					SET @Index = @Index - 1
					IF ( @Index < 0 ) SET @Index = 0
				END
			END
			FETCH NEXT FROM CursorBGearRank INTO @CharacterName, @Gear, @Level, @Experience, @Propensity, @Score, @PKWinPoint, @PKLossPoint, @GuildName, @Influence
			SET @Index = @Index + 1
		END
		CLOSE CursorBGearRank
		DEALLOCATE CursorBGearRank
		SET @GearIndex = @GearIndex + 1
	END
	/*PVP end********************************************************************************************************/
	
	SELECT ServerName, CharacterName, Gear, [Level], Experience, Propensity, Score, PKWinPoint, PKLossPoint, GuildName, Influence FROM #tRankPersonal
	DROP TABLE #tRankPersonal
END
GO



--> 120921_DB��Ű��_(�Ʒ��� �������� ���)_DBQuery(Only_atum2_db_[n])
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.arena_CopyDBInfo_EX_GAMEFORGE_VERSION
-- DESC				: �������� ���� ������ �߰� ���� ����
--						-- // 2012-09-21 by jhseol, �Ʒ��� �߰����� GF���� - �Ʒ��� ���� ĳ���͸� ����ϵ� �⺻.���.�ƸӸ� �����ϰ� ��� ���� �ɸ����� ��� ���������� ����.
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[arena_CopyDBInfo_EX_GAMEFORGE_VERSION]
	@i_ArenaCharacterUID		INT,
	@i_CharacterUID				INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @WeaponItemKind TINYINT
	DECLARE @ArmorItemKind TINYINT
	SET @WeaponItemKind = 11
	SET @ArmorItemKind = 16
	DECLARE @DeleteStoreItemUID BIGINT
	SET @DeleteStoreItemUID = NULL
	DECLARE CursorDeleteStoreItem CURSOR LOCAL FOR 
		SELECT S.UniqueNumber FROM atum2_db_account.dbo.ti_Item AS I, atum2_db_arena.dbo.td_Store AS S
		WHERE I.ItemNum = S.ItemNum AND S.Possess = @i_ArenaCharacterUID AND (I.Kind < @WeaponItemKind OR I.Kind = @ArmorItemKind)
	OPEN CursorDeleteStoreItem
	FETCH NEXT FROM CursorDeleteStoreItem INTO @DeleteStoreItemUID
	WHILE @@FETCH_STATUS = 0
	BEGIN
		DELETE atum2_db_arena.dbo.td_Store
		WHERE UniqueNumber = @DeleteStoreItemUID
		
		DELETE atum2_db_arena.dbo.td_Enchant
		WHERE TargetItemUniqueNumber = @DeleteStoreItemUID
		
		FETCH NEXT FROM CursorDeleteStoreItem INTO @DeleteStoreItemUID
	END
	
	CLOSE CursorDeleteStoreItem
	DEALLOCATE CursorDeleteStoreItem

	DECLARE @InsertStoreItemUID BIGINT
	SET @InsertStoreItemUID = NULL
	DECLARE CursorInsertStoreItem CURSOR LOCAL FOR 
		SELECT S.UniqueNumber FROM atum2_db_account.dbo.ti_Item AS I, dbo.td_Store AS S
		WHERE I.ItemNum = S.ItemNum AND S.Possess = @i_CharacterUID AND (I.Kind < @WeaponItemKind OR I.Kind = @ArmorItemKind)
	OPEN CursorInsertStoreItem
	FETCH NEXT FROM CursorInsertStoreItem INTO @InsertStoreItemUID
	WHILE @@FETCH_STATUS = 0
	BEGIN
		INSERT atum2_db_arena.dbo.td_Store(AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID, CoolingTime)
		SELECT AccountUniqueNumber,  @i_ArenaCharacterUID, ItemStorage, Wear, CurrentCount, ItemWindowIndex
				, ItemNum, NumOfEnchants, PrefixCodeNum, SuffixCodeNum, CurrentEndurance, ColorCode, UsingTimeStamp, CreatedTime, ShapeItemNum, UniqueNumber, CoolingTime
		FROM dbo.td_Store WITH(NOLOCK)
		WHERE UniqueNumber = @InsertStoreItemUID

		DECLARE @TItemUID BIGINT
		SET @TItemUID	= @@IDENTITY;

		IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @InsertStoreItemUID)
		BEGIN
			INSERT INTO atum2_db_arena.dbo.td_Enchant(TargetItemUniqueNumber, TargetItemNum, EnchantItemNum)
				SELECT @TItemUID, TargetItemNum, EnchantItemNum
				FROM dbo.td_Enchant WITH(NOLOCK)
				WHERE TargetItemUniqueNumber = @InsertStoreItemUID
		END

		FETCH NEXT FROM CursorInsertStoreItem INTO @InsertStoreItemUID
	END
	
	CLOSE CursorInsertStoreItem
	DEALLOCATE CursorInsertStoreItem
GO


--> 121013_DB��Ű��_(�Ⱓ���Ƹӿ���)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_Get_FixedTerm]
--					// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Get_FixedTerm]
	@i_ItemUID			BIGINT,
	@i_TermType			SMALLINT
-- YD ���� �ڵ�
AS
BEGIN
	SELECT AppliedItemNum, StartDate, EndDate FROM [dbo].[td_FixedTerm] WHERE [ItemUID] = @i_ItemUID and [TermType] = @i_TermType
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME :	[atum_Insert_FixedTerm]
--					// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_FixedTerm]
	@i_ItemUID			BIGINT,
	@i_TermType			SMALLINT,
	@i_AppliedItemNum	INT,
	@i_StartDate		DATETIME,
	@i_EndDate			DATETIME
-- YD ���� �ڵ�
AS
BEGIN
	DECLARE	@ResultCnt	INT
	SELECT @ResultCnt = COUNT(*) FROM [dbo].[td_FixedTerm]  WHERE [ItemUID] = @i_ItemUID and [TermType] = @i_TermType

	IF( @ResultCnt != 0 )
	BEGIN
		UPDATE [dbo].[td_FixedTerm] SET [AppliedItemNum] = @i_AppliedItemNum, [StartDate] = @i_StartDate, [EndDate] = @i_EndDate
			WHERE [ItemUID] = @i_ItemUID and [TermType] = @i_TermType
	END
	ELSE
	BEGIN
		INSERT INTO [dbo].[td_FixedTerm] ([ItemUID], [TermType], [AppliedItemNum], [StartDate], [EndDate])
			VALUES (@i_ItemUID, @i_TermType, @i_AppliedItemNum, @i_StartDate, @i_EndDate)
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_Delete_FixedTerm]
--					// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Delete_FixedTerm]
	@i_ItemUID			BIGINT,
	@i_TermType			SMALLINT
-- YD ���� �ڵ�
AS
BEGIN
	DELETE FROM [dbo].[td_FixedTerm] WHERE [ItemUID] = @i_ItemUID and [TermType] = @i_TermType
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_Update_FixedTerm]
--					// 2012-10-10 by hskim, �Ⱓ�� �Ӽ� ���� (�Ⱓ�� ����)
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Update_FixedTerm]
	@i_ItemUID			BIGINT,
	@i_TermType			SMALLINT,
	@i_AppliedItemNum	INT,
	@i_StartDate		DATETIME,
	@i_EndDate			DATETIME
-- YD ���� �ڵ�
AS
BEGIN
	UPDATE [dbo].[td_FixedTerm] SET [AppliedItemNum] = @i_AppliedItemNum, [StartDate] = @i_StartDate, [EndDate] = @i_EndDate
		WHERE [ItemUID] = @i_ItemUID and [TermType] = @i_TermType
END
GO


--> 121014_DB��Ű��_(�޽İ���ġ)_DBQuery(atum2_db_[n]&atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Set_AddExp_RestExperienceCount]
-- DESC				: // 2012-10-07 by hskim, �޽� ����ġ
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Set_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT,
	@i_RestExperienceCount		INT
-- YD ���� �ڵ�
AS
BEGIN
	DECLARE @RestExperienceCount	INT

	SELECT @RestExperienceCount = RestExperienceCount FROM atum2_db_account.dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber

	IF( @RestExperienceCount IS NULL )
	BEGIN
		INSERT INTO [atum2_db_account].[dbo].[td_AdditionalExperience] ([AccountUniqueNumber], [RestExperienceCount]) VALUES (@i_AccountUniqueNumber, @i_RestExperienceCount)
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.td_AdditionalExperience SET RestExperienceCount = @i_RestExperienceCount WHERE AccountUniqueNumber = @i_AccountUniqueNumber
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Get_AddExp_RestExperienceCount]
-- DESC				: // 2012-10-07 by hskim, �޽� ����ġ
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Get_AddExp_RestExperienceCount]
	@i_AccountUniqueNumber		INT
-- YD ���� �ڵ�
AS
BEGIN
	SELECT RestExperienceCount FROM atum2_db_account.dbo.td_AdditionalExperience WITH (NOLOCK) WHERE AccountUniqueNumber = @i_AccountUniqueNumber
END
GO

--> 121113_DB��Ű��_(����ý��� ������ - ������)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_LoadRenewalStrategyPointMapInfluenceInfo
-- DESC				: �������� �������� ��������
-- // 2012-11-13 by jhseol, ���� �ý��� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE atum_LoadRenewalStrategyPointMapInfluenceInfo
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [MapIndex], [MapName], [MapInfluenceType]
	FROM [atum2_db_account].[dbo].[ti_MapInfo]
	WHERE [MapIndex] IN (SELECT [MapIndex] FROM [atum2_db_account].[dbo].[ti_StrategyPointSummonMapIndex])
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_LoadRenewalStrategyPointSummonTime
-- DESC				: ���Ϻ� �ð� �� ���� ���� �������� ���ν���
-- // 2012-11-13 by jhseol, ���� �ý��� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadRenewalStrategyPointSummonTime
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	SELECT DayOfWeek, StartTime, EndTime, CountBCU, CountANI FROM td_RenewalStrategyPointSummonTime WITH(NOLOCK)
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_UpdateRenewalStrategyPointSummonTime
-- DESC				: ���Ϻ� �ð� �� ���� ���� ������Ʈ ���ν���
-- // 2012-11-13 by jhseol, ���� �ý��� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateRenewalStrategyPointSummonTime
	@i_DayOfWeek	TINYINT,
	@i_StartTime	VARCHAR(30),
	@i_EndTime		VARCHAR(30),
	@i_CountBCU		TINYINT,
	@i_CountANI		TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	UPDATE td_RenewalStrategyPointSummonTime SET StartTime = @i_StartTime, EndTime = @i_EndTime, CountBCU = @i_CountBCU, CountANI = @i_CountANI WHERE DayOfWeek = @i_DayOfWeek
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_UpdateRenewalStrategyPointSummonInfo
-- DESC				: ������ ���� ���� ������Ʈ
-- // 2012-11-13 by jhseol, ���� �ý��� ������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_UpdateRenewalStrategyPointSummonInfo
	@i_MapIndex			INT,
	@i_SummonCount		TINYINT,
	@i_SummonTime		VARCHAR(30),
	@i_SummonAttribute	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	IF (SELECT MapIndex FROM dbo.td_StrategyPointSummonInfo WHERE MapIndex = @i_MapIndex) IS NULL
	BEGIN
		INSERT INTO dbo.td_StrategyPointSummonInfo(MapIndex, SummonCount, SummonTime, SummonAttribute)
		VALUES(@i_MapIndex, '19000101 00:00:00.000', 0, 0)
	END
	
	IF (@i_SummonTime like '0000%')
	BEGIN
		UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = @i_SummonCount, SummonTime = '19000101 00:00:00.000', SummonAttribute = @i_SummonAttribute WHERE MapIndex = @i_MapIndex
	END
	ELSE
	BEGIN
		UPDATE dbo.td_StrategyPointSummonInfo SET SummonCount = @i_SummonCount, SummonTime = @i_SummonTime, SummonAttribute = @i_SummonAttribute WHERE MapIndex = @i_MapIndex
	END
GO

--> 130102_DB��Ű��_(�����ʱ�ȭ �αװ���)_DBQuery(Only_atum2_db_[n])
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadInitializedGuildList
-- DESC				: --	// 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
-- �����ʱ�ȭ�� �α׸� ����� ���� �ӽ������ߴ� ������ �ε�
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_LoadInitializedGuildList]
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT [AccountUniqueNumber]
      ,[AccountName]
      ,[CharacterUniqueNumber]
      ,[CharacterName]
      ,[ItemUniqueNumber]
      ,[ItemNum]
      ,[Kind]
      ,[CurrentCount]
      ,[GuildUniqueNumber]
      ,[GuildName]
	FROM [dbo].[atum_Temporary_Initialized_Guild_List]
END
GO
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [dbo].[atum_Delete_LoadInitializedGuildList]
-- DESC				: // 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
-- �����ʱ�ȭ�� �α׸� ����� ���� �ӽ������ߴ� ������ ����.					
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_Delete_LoadInitializedGuildList]
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	DELETE FROM [dbo].[atum_Temporary_Initialized_Guild_List]
END
GO


--> 130116_DB��Ű��_(���� ������ ������ ���� �� ���� ���� ������Ʈ)_DBQuery(atum2_db_[n]&atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InitCityLeader
-- DESC				: 2013-01-16 by jhseol, ������ ���� ��Ż�� ���� ���� ���ν���
--	1. ĳ���� ������ �Ϲݱ������� ����
--	2. td_CityLeaderInfo ���� ����
--	3. ������ �������� ����(���º�)
--	4. ȸ�Ƿ� ���� ����Ʈ �ʱ�ȭ. (BCU:1001 / ANI:1002)
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InitCityLeader]
	@i_Influence	TINYINT,
	@i_CUID			INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	IF (@i_Influence = 2)
	BEGIN
	-- BCU ���� �����ڰ� �´��� Ȯ�� �� ������ �ʱ�ȭ ����
		IF EXISTS ( SELECT CharacterUID	FROM td_CityLeaderInfo	WHERE MapIndex = 2001 AND CharacterUID = @i_CUID )
		BEGIN
		--	1. ĳ���� ������ �Ϲݱ������� ����
			UPDATE dbo.td_Character
			SET Race = 2
			WHERE UniqueNumber = @i_CUID

		--	2. td_CityLeaderInfo ���� �ʱ�ȭ(BCU)
			UPDATE dbo.td_CityLeaderInfo
			SET	Influence = 0, CharacterUID = 0, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 0, Notice = NULL
			WHERE MapIndex = 2001

		--	3. ������ �������� ����(BCU)
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001320 AND Possess = @i_CUID	--	�������� ����(����������)
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001090 AND Possess = @i_CUID	--	������ ��ȣ
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001110 AND Possess = @i_CUID	--	������ �ð�

		--	4. ȸ�Ƿ� ���� ����Ʈ �ʱ�ȭ. (BCU:1001)
			DELETE FROM dbo.td_user_list_warpable_to_map WHERE MapIndex = 1001
		END
	END
	ELSE IF (@i_Influence = 4)
	BEGIN
	-- ANI ���� �����ڰ� �´��� Ȯ�� �� ������ �ʱ�ȭ ����
		IF EXISTS ( SELECT CharacterUID	FROM td_CityLeaderInfo	WHERE MapIndex = 2002 AND CharacterUID = @i_CUID )
		BEGIN
		--	1. ĳ���� ������ �Ϲݱ������� ����
			UPDATE dbo.td_Character
			SET Race = 2
			WHERE UniqueNumber = @i_CUID

		--	2. td_CityLeaderInfo ���� �ʱ�ȭ(ANI)
			UPDATE dbo.td_CityLeaderInfo
			SET	Influence = 0, CharacterUID = 0, ExpediencyFundCumulative = 0, ExpediencyFund = 0, ExpediencyFundRate = 0, Notice = NULL
			WHERE MapIndex = 2002
			
		--	3. ������ �������� ����(ANI)
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001330 AND Possess = @i_CUID	--	�������� ����(�˸���)
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001090 AND Possess = @i_CUID	--	������ ��ȣ
			DELETE FROM dbo.td_Store WHERE Itemnum = 7001110 AND Possess = @i_CUID	--	������ �ð�

		--	4. ȸ�Ƿ� ���� ����Ʈ �ʱ�ȭ. (ANI:1002)
			DELETE FROM dbo.td_user_list_warpable_to_map WHERE MapIndex = 1002
		END
	END
END
GO


--130205_DB��Ű��_(ĳ������õ�Ǿ����ۼ�����Ʈ��)_DBQuery(atum2_db_[n]&atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Load_Realignment_CashShop]
-- DESC				: // 2013-02-05 by bckim, ĳ�ü� ��õ�� ���ļ����ο�
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_Load_Realignment_CashShop]
AS

BEGIN
	SELECT i.ItemNum, i.ItemName, cr.CashShopBit, c.RemainCountForLimitedEdition, cr.RealignmentIndex
	FROM atum2_db_account.dbo.ti_Item i INNER JOIN atum2_db_account.dbo.ti_Shop s ON i.ItemNum = s.ItemNum
		INNER JOIN [atum2_db_account].[dbo].[td_CashShop] c ON i.ItemNum = c.ItemNum 
		INNER JOIN [atum2_db_account].[dbo].[td_CashShop_Realignment_Index] cr ON i.ItemNum = cr.ItemNum
	ORDER BY cr.RealignmentIndex
END
GO
-- 4
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Update_Realignment_CashShop]
-- DESC				: // 2013-02-05 by bckim, ĳ�ü� ��õ�� ���ļ����ο�
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_Update_Realignment_CashShop]
	@i_ItemNum				INT,
	@i_RealignmentIndex		INT	
AS
BEGIN
	UPDATE [atum2_db_account].[dbo].[td_CashShop_Realignment_Index] SET RealignmentIndex = @i_RealignmentIndex 
	WHERE ItemNum = @i_ItemNum;
END
GO

-- // 2012-11-21 by bckim, �������߰�, ��æƮ���������ű��
-- Name: [atum_log_insert_item_Enchant_Change_By_Admin]
-- Desc: �α� ���� insert 
CREATE PROCEDURE [dbo].[atum_log_insert_item_Enchant_Change_By_Admin]
	@i_LogType						TINYINT,
	@i_CharacterUniqueNumber		INT,
	@i_ItemUniqueNumber				BIGINT,
	@i_ItemNum						INT,
	@i_EnchantCardNumber						INT,
	@i_ChangeEnchantCount					INT,
	@i_ResultEnchantCount					INT,
	@i_PeerCharacterName			VARCHAR(20)

AS
	INSERT INTO dbo.atum_log_item_Enchant_Change_By_Admin
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber,
			@i_ItemUniqueNumber, @i_ItemNum, @i_EnchantCardNumber,
			@i_ChangeEnchantCount,@i_ResultEnchantCount,
			@i_PeerCharacterName)
GO

-- Name: [[atum_PROCEDURE_121121_001]]
-- Desc: ��æƮ ���� ���ν��� 
CREATE PROCEDURE [dbo].[atum_PROCEDURE_121121_001]
	@i_ItemUID					BIGINT,
	@i_RemoveItemCount			INT,
	@i_EnchantItemNum			INT
AS
	DELETE TOP(@i_RemoveItemCount) FROM dbo.td_Enchant 
	WHERE TargetItemUniqueNumber = @i_ItemUID AND EnchantItemNum = @i_EnchantItemNum

GO

--> 130228_DB��Ű��_(�������������߰�)_DBQuery(atum2_db_[n]&atum2_db_arena)
-- ���ν��� ���� CREATE PROCEDURE [dbo].[atum_update_Log_ItemEvent_fixed_period]
CREATE PROCEDURE [dbo].[atum_update_Log_ItemEvent_fixed_period]
	@i_AccountUID               int,
	@i_CharacterUID             int,
	@i_ItemEventUID             int,
	@i_InsertItemTime			VARCHAR(50)
AS
	IF (0 = @i_CharacterUID) 
	BEGIN
		UPDATE atum2_db_account.dbo.atum_log_itemevent SET GetTime = @i_InsertItemTime 
		WHERE AccountUID = @i_AccountUID AND ItemEventUID = @i_ItemEventUID
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.atum_log_itemevent SET GetTime = @i_InsertItemTime 
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID AND ItemEventUID = @i_ItemEventUID
	END
GO

--> 130323_DB��Ű��_02_(NGC �������� Ʈ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteTriggerFunctionNGCOutPost
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteTriggerFunctionNGCOutPost
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	DELETE FROM atum2_db_account.dbo.ti_TriggerFunctionNGCOutPost
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertTriggerFunctionNGCOutPost
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertTriggerFunctionNGCOutPost
	@i_FunctionID			INT,
	@i_NGCInflWarGroupID	INT,
	@i_StandardOutPostMap	INT,
	@i_BossMonster			INT,
	@i_WinInfluenceWP		INT,
	@i_LossInfluenceWP		INT,
	@i_NextOutPostMap		INT,
	@i_DestroyCrystalcount	INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	INSERT INTO atum2_db_account.dbo.ti_TriggerFunctionNGCOutPost
		(FunctionID, NGCInflWarGroupID, StandardOutPostMap, BossMonster, WinInfluenceWP, LossInfluenceWP, NextOutPostMap, DestroyCrystalcount)
	VALUES(@i_FunctionID, @i_NGCInflWarGroupID, @i_StandardOutPostMap, @i_BossMonster, @i_WinInfluenceWP, @i_LossInfluenceWP, @i_NextOutPostMap, @i_DestroyCrystalcount)
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadTriggerFunctionNGCOutPost
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTriggerFunctionNGCOutPost
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT FunctionID, NGCInflWarGroupID, StandardOutPostMap, BossMonster, WinInfluenceWP, LossInfluenceWP, NextOutPostMap, DestroyCrystalcount
	FROM atum2_db_account.dbo.ti_TriggerFunctionNGCOutPost
END
GO

/**********************************************************************************************/
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteTriggerOutPosKill
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteTriggerOutPosKill
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	DELETE FROM atum2_db_account.dbo.ti_TriggerOutPostBossKill
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertTriggerOutPosKill
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertTriggerOutPosKill
	@i_BossMonster			INT,
	@i_CrystalNum			INT,
	@i_RegenMinTimeMinutes	INT,
	@i_RegenMaxTimeMinutes	INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	INSERT INTO atum2_db_account.dbo.ti_TriggerOutPostBossKill
		(BossMonster, CrystalNum, RegenMinTimeMinutes, RegenMaxTimeMinutes)
	VALUES(@i_BossMonster, @i_CrystalNum, @i_RegenMinTimeMinutes, @i_RegenMaxTimeMinutes)
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadTriggerOutPosKill
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTriggerOutPosKill
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT BossMonster, CrystalNum, RegenMinTimeMinutes, RegenMaxTimeMinutes
	FROM atum2_db_account.dbo.ti_TriggerOutPostBossKill
END
GO

/**********************************************************************************************/

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteTriggerCrystalBuff
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_DeleteTriggerCrystalBuff
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	DELETE FROM atum2_db_account.dbo.ti_TriggerCrystalBuff
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertTriggerCrystalBuff
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertTriggerCrystalBuff
	@i_FunctionID			INT,
	@i_SkillItemNum			INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	INSERT INTO atum2_db_account.dbo.ti_TriggerCrystalBuff
		(FunctionID, SkillItemNum)
	VALUES(@i_FunctionID, @i_SkillItemNum)
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_LoadTriggerCrystalBuff
-- DESC				: // 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_LoadTriggerCrystalBuff
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT FunctionID, SkillItemNum
	FROM atum2_db_account.dbo.ti_TriggerCrystalBuff
END
GO


--> 130329_DB��Ű��_01_(�ſ� ù ����� ���� ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertCashBuyDate
-- DESC				: // 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertCashBuyDate
	@i_AccountUID		INT,
	@i_CharacterUID		INT,
	@i_LastCashBuyDate	VARCHAR(30)
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	IF EXISTS(SELECT * FROM td_CashBuyDate WITH (NOLOCK) WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID)
	BEGIN
		UPDATE td_CashBuyDate
		SET LastCashBuyDate = CONVERT(DATETIME, @i_LastCashBuyDate)
		WHERE AccountUID = @i_AccountUID AND CharacterUID = @i_CharacterUID
	END
	ELSE
	BEGIN
		INSERT INTO td_CashBuyDate(AccountUID, CharacterUID, LastCashBuyDate)
		VALUES(@i_AccountUID, @i_CharacterUID, CONVERT(DATETIME, @i_LastCashBuyDate))
	END
END
GO


-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCashBuyDateByAccountUID
-- DESC				: // 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetCashBuyDateByAccountUID
	@i_AccountUID		INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT TOP 1 LastCashBuyDate
	FROM td_CashBuyDate WITH (NOLOCK)
	WHERE AccountUID = @i_AccountUID order by LastCashBuyDate desc
END
GO

-------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCashBuyDateByCharacterUID
-- DESC				: // 2013-03-29 by jhseol, ������ �̺�Ʈ - �ſ� ù ����� ��������
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetCashBuyDateByCharacterUID
	@i_CharacterUID		INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT LastCashBuyDate
	FROM td_CashBuyDate WITH (NOLOCK)
	WHERE CharacterUID = @i_CharacterUID
END
GO


--> 130329_DB��Ű��_02_(������ �̺�Ʈ ����Ÿ��)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_InsertItemEventSubType
-- DESC				: -- // 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_InsertItemEventSubType
	@i_ItemEventUID			INT,
	@i_SubEventType			BIT,
	@i_Param1				SMALLINT,
	@i_Value1				INT,
	@i_Param2				SMALLINT,
	@i_Value2				INT,
	@i_Param3				SMALLINT,
	@i_Value3				INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	IF EXISTS(SELECT * FROM atum2_db_account.dbo.td_ItemEventSubType WITH (NOLOCK) WHERE ItemEventUID = @i_ItemEventUID)
	BEGIN
		UPDATE atum2_db_account.dbo.td_ItemEventSubType
		SET SubEventType = @i_SubEventType
			,Param1 = @i_Param1, Value1 = @i_Value1
			,Param2 = @i_Param2, Value2 = @i_Value2
			,Param3 = @i_Param3, Value3 = @i_Value3
		WHERE ItemEventUID = @i_ItemEventUID
	END
	ELSE
	BEGIN
		INSERT INTO atum2_db_account.dbo.td_ItemEventSubType
			(ItemEventUID,SubEventType,Param1,Value1,Param2,Value2,Param3,Value3)
     VALUES
           (@i_ItemEventUID, @i_SubEventType, @i_Param1, @i_Value1, @i_Param2, @i_Value2, @i_Param3, @i_Value3)
	END
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetItemEventSubType
-- DESC				: -- // 2013-03-29 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰������� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_GetItemEventSubType
	@i_ItemEventUID			INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT SubEventType,Param1,Value1,Param2,Value2,Param3,Value3
	FROM atum2_db_account.dbo.td_ItemEventSubType WITH (NOLOCK)
	WHERE ItemEventUID = @i_ItemEventUID
END
GO

--> 130605_DB��Ű��_01_(��ĳ�û���)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_insertStoreItem_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--					  -- atum_insertStoreItem_FromWeb ������� �ش� ���ν����� ���� �ۼ�, �߰� �߰� ������ Ʋ���ϴ� �����ϼ���
--					  -- �ؿܿ��� atum_insertStoreItem_FromWeb ���ν����� ����ϴ� ��� ��� ������ ������ �ּ�ȭ �ϱ� ���� ���ο� ���ν����� �ۼ�
--					  -- �� ĳ�� ���� �������̽� XMLRPC ���� �ϵ��� �����ؾ� �ϸ�, ���� �� atum_insertStoreItem_FromWeb ���ν����� �����ؾ� ��
--
--					///////////////////////////////////
--					// WEAR
--					#define WEAR_NOT_ATTACHED				0	// ������
--					#define WEAR_ATTACHED					1	// ����
--							
--					///////////////////////////////////////////////////////////////////////////////
--					// 2005-12-07 by cmkwon
--					#define ITEM_IN_CHARACTER				0	// ĳ�����κ�, ������ ĳ���� ���� ���۽� �ѹ��� ȣ���
--					#define ITEM_IN_STORE					1	// â��
--					#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--							
--					@i_ItemWindowIndex ����, �Ʒ��� 99�� �����ϸ� �⺻������ ���� ����, �ٸ� ������ ������ų���� �ʿ�
--					#define POS_INVALID_POSITION			((BYTE)99)	// 99,  invalid position
--
-- Parameter		:	@i_AccountUID			INT			==> �ش� ������ ������ȣ (AccountUID) , ���� ���� ���� ���� Ȯ�ο�
--					@i_CharUID			INT			==> �ش� ĳ������ ������ȣ(CharacterUID)
--					@i_ItemNum			INT			==> �߰� �� �������� ItemNum
--					@i_CurrentCount		INT			==> �߰� �� �������� ����, ī���ͺ� �������� �ƴϸ� �ִ� 20�� ������ �߰� ������
--					@i_ItemStorage		TINYINT		==> �߰� �� ��ġ�� 0�̸� ĳ������ �κ�, 1�̸� ĳ������ â����, ITEM_IN_XXX�� ����
--					@i_Wear				TINYINT		==> �߰��� ��ġ�� ĳ������ �κ��϶��� â�� ���θ� ��Ÿ����, WEAR_XXX�� ����
--					@i_ItemWindowIndex	INT			==> â�� �����϶����� ��ȿ�ϸ�, â�����°� �ƴϸ� 99�� �����ϸ� �ȴ�.
--					@i_IsBuyCashItem	TINYINT			==> ������ �߰��� ĳ�������� ���ſ� ���� �߰� ������ ����, �ش� ���� ���� �α� �߰� ��ġ�� �޶�����.
--
-- Result Set	:	[ErrorCode INT] [InsertedItemUID BIGINT]
--					[ErrorCode INT]	==>	0 �̸� ����, 0 �� �ƴϸ� ������ ������ ����
--										-13,		// ������ ��ġ�� ��ȿ���� ����
--										-10,		// ������ ���� ������ ��ȿ���� ����
--										-6,		// ������ ĳ���� ������ ���� ����
--										-1,		// ���� ���� ����
--										-20,		// ������� �ʴ� ������ (�߰� / ����)
--										-10,		// ������ ���� ������ ��ȿ���� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_insertStoreItem_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT,
	@i_ItemStorage		TINYINT,
	@i_Wear				TINYINT,
	@i_ItemWindowIndex	INT,
	@i_IsBuyCashItem	TINYINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @i			INT;
	SET @i				= 0;

	-- ĳ�����κ�, ĳ���� â�� ������ �߰��� ����, ����â�� ������ �߰��� �������� �ʴ´�.
	IF (0 <> @i_ItemStorage) AND (1 <> @i_ItemStorage)
	BEGIN
		-- #define XMLRPC_ERROR_INVALID_ITEM_STORAGE				-13			// ������ ��ġ�� ��ȿ���� ����
		SELECT -13;
		RETURN;
	END
	IF (0 >= @i_CurrentCount)
	BEGIN
		-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// ������ ���� ������ ��ȿ���� ����
		SELECT -10;	
		RETURN;	
	END

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID		INT
	SET @AccUID = (SELECT AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384 )
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6;
		RETURN;
	END

	IF (0 != @i_ItemStorage)
	BEGIN
		SET @i_Wear				= 0;	-- ������
		SET @i_ItemWindowIndex	= 99;	-- ������
	END

	-- #define ITEM_ATTR_CASH_ITEM_PREMIUM_CARD		0x00020000		// 131072, // 2008-08-26 by cmkwon, ItemAttribute �߰� - �����(�����̾�) ������,  
	DECLARE @ItemKd				TINYINT;
	DECLARE @ItemAttri			BIGINT;
	DECLARE @ItemCharging		SMALLINT;
	DECLARE @ItemEndur			FLOAT;
	DECLARE @InsertedItemUID	BIGINT;
	DECLARE @LinkItem			INT;

	DECLARE	@RtvValue			INT;

	SELECT @ItemKd= Kind, @ItemAttri= ItemAttribute, @ItemCharging= Charging, @ItemEndur= Endurance, @LinkItem = LinkItem FROM atum2_db_account.dbo.ti_Item WITH(NOLOCK) WHERE ItemNum = @i_ItemNum;
	IF (@ItemKd IS NULL) OR (0 <> @ItemAttri & 131072)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ACCEPTED_ITEMNUM				-20			// ������� �ʴ� ������ (�߰� / ����)
		SELECT -20;
		RETURN
	END

	IF (0 <> dbo.atum_IsCountableItem(@ItemKd)) 
	BEGIN
		INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
			VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @i_CurrentCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

		IF (0 <> @@error)
		BEGIN
			-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
			SELECT -1;
			RETURN
		END
		
		--SET @InsertedItemUID = SCOPE_IDENTITY();
		SET @i					= @i + @i_CurrentCount;
	END
	ELSE
	BEGIN
		IF (10 < @i_CurrentCount)		-- ��ī���ͺ� ������ ó��(�ִ� 10�� ������ �߰� ������)
		BEGIN
			-- #define XMLRPC_ERROR_OUT_OF_RANGE_ITEMCOUNT				-10			// ������ ���� ������ ��ȿ���� ����
			SELECT -10;
			RETURN
		END

		DECLARE @CurCount	INT;
		SET @CurCount		= 1;
		IF (0 <> dbo.atum_IsChargableItem(@ItemKd))
		BEGIN
			IF (@ItemCharging IS NULL)
			BEGIN
				-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
				SELECT -1;
				RETURN
			END
				
			SET @CurCount = @ItemCharging;
		END

		WHILE @i < @i_CurrentCount
		BEGIN
			IF (@ItemKd <> 38)
			BEGIN
				-- �Ϲ� ������
				INSERT INTO dbo.td_Store (AccountUniqueNumber,Possess,ItemStorage,Wear,CurrentCount,ItemWindowIndex,ItemNum,NumOfEnchants,PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime,ShapeItemNum,MainSvrItemUID,CoolingTime)
					VALUES (@AccUID, @i_CharUID, @i_ItemStorage, @i_Wear, @CurCount, @i_ItemWindowIndex, @i_ItemNum, 0, 0, 0, @ItemEndur, 0, 0, GETDATE(), 0, 0, 0);

				IF (0 <> @@error)
				BEGIN
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
					SELECT @i;
					RETURN
				END
			END
			ELSE
			BEGIN
				-- ��Ʈ�� ������
				EXEC @RtvValue = dbo.atum_InsertStorePetItem
					@accNum = @AccUID,
					@possess = @i_CharUID,
					@ItemStorage = @i_ItemStorage,
					@wear = @i_Wear,
					@CurrentCount = @CurCount,
					@ItemWindowIndex = @i_ItemWindowIndex,
					@ItemNum = @i_ItemNum,
					@NumOfEnchants = 0,
					@PrefixCodeNum = 0,
					@SufficCodeNum = 0,
					@CurrentEndurance = @ItemEndur,
					@ColorCode = 0,
					@UsingTimeStamp = 0,
					@i_LinkItem = @LinkItem

				IF (0 = @RtvValue)
				BEGIN
					-- #define XMLRPC_ERROR_INTERNAL_SERVER					-1			// ���� ���� ����
					SELECT @i;
					RETURN					
				END
			END

			SET @i = @i + 1;
		END
	END

	SELECT @i;
	RETURN;
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfo_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetCharacterInfo_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_GiftCharUID		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	DECLARE @AccountName		VARCHAR(20);
	DECLARE @CharacterName		VARCHAR(20);
	DECLARE @Race				SMALLINT;

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @GiftAccUID		INT; SET @GiftAccUID = 0;

	SELECT @AccUID = AccountUniqueNumber, @AccountName = AccountName, @CharacterName = CharacterName, @Race = Race FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6, NULL, NULL, NULL, 0;
		RETURN;
	END

	IF(0 != @i_GiftCharUID)
	BEGIN
		SELECT @GiftAccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_GiftCharUID AND 0 = Race & 16384
		IF (@GiftAccUID IS NULL)
		BEGIN
			-- #define XMLRPC_ERROR_INVALID_GET_CHARACTERUID				-18			// ���� ���� ���� ������ ��ȿ���� ����
			SELECT -18, NULL, NULL, NULL, 0;
			RETURN;
		END
	END

	SELECT 1, @AccountName, @CharacterName, @Race, @GiftAccUID;
	RETURN;
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_DeleteItem_FromXMLRPC
-- DESC				: -- // 2013-03-13 by hskim, �� ĳ�� ����
--					  -- �ش� ���ν����� ���� ���� �������� ȣ�� �ؾ���
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_DeleteItem_FromXMLRPC]
	@i_AccountUID		INT,
	@i_CharUID			INT,
	@i_ItemNum			INT,
	@i_CurrentCount		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SET NOCOUNT ON

	-- �ش� CharUID�� ��ȿ���� üũ
	--	#define RACE_DELETED_CHARACTER		(USHORT)0x4000	// ������ ĳ����, 16384 // 2007-02-21 by cmkwon
	DECLARE @AccUID			INT; SET @AccUID = 0;
	DECLARE @ItemUID		INT; SET @ItemUID = 0;
	DECLARE @CurrentCount	INT; SET @CurrentCount = 0;

	SELECT @AccUID = AccountUniqueNumber FROM dbo.td_Character WITH(NOLOCK) WHERE UniqueNumber = @i_CharUID AND 0 = Race & 16384
	IF (@AccUID IS NULL) OR (@AccUID != @i_AccountUID)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_MATCHED_USER_INFO				-6			// ������ ĳ���� ������ ���� ����
		SELECT -6;
		RETURN;
	END

	SELECT TOP 1 @ItemUID = [UniqueNumber], @CurrentCount = [CurrentCount] FROM [dbo].[td_Store] WHERE [ItemStorage] = 0 and [Possess] = @i_CharUID and [AccountUniqueNumber] = @i_AccountUID and [ItemNum] = @i_ItemNum

	IF (@ItemUID IS NULL) OR (@CurrentCount IS NULL)
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// ������ �� ����
		SELECT -22;
		RETURN;
	END

	IF @CurrentCount < @i_CurrentCount
	BEGIN
		-- #define XMLRPC_ERROR_NOT_ENOUGH_ITEM_COUNT				-22			// ������ �� ����
		SELECT -22;
		RETURN;
	END

	IF @CurrentCount = @i_CurrentCount
	BEGIN
		DELETE FROM [dbo].[td_Store] WHERE [UniqueNumber] = @ItemUID;
	END
	ELSE
	BEGIN
		UPDATE [dbo].[td_Store] SET [CurrentCount] = [CurrentCount] - @i_CurrentCount WHERE [UniqueNumber] = @ItemUID;
	END

	SELECT @i_CurrentCount;
	RETURN;
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfoByAccountName
-- DESC				: �� ĳ�ÿ� ĳ���� ���� Ȯ�� ���ν��� (����Name), 2013-04-29 by hskim
--					  * ������ ĳ���ʹ� ������ ����
--
-- INPUT				: @AccountName			varchar(20)			���� �̸�
--
-- OUTPUT			: [AccountName]			varchar(20)			���� �̸�
--					: [AccountUID]			int					���� UID
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [CharacterUID]		int					ĳ���� UID
--					: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--                  : [InfluenceType]       tinyint             ��������		(1 = �Ϲ�, 2 = ����������, 4 = �˸���)
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetCharacterInfoByAccountName]
	@AccountName			varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [AccountName], [AccountUniqueNumber], [CharacterName], [UniqueNumber], [Level], [UnitKind], [InfluenceType] FROM [dbo].[td_Character] WITH (NOLOCK) WHERE [AccountName] = @AccountName AND 0 = [Race] & 16384
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_GetCharacterInfoByCharacterName
-- DESC				: �� ĳ�ÿ� ĳ���� ���� Ȯ�� ���ν��� (����Name), 2013-04-29 by hskim
--					  * ������ ĳ���ʹ� ������ ����
--
-- INPUT				: @CharacterName		varchar(20)			ĳ���� �̸�
--
-- OUTPUT			: [AccountName]			varchar(20)			���� �̸�
--					: [AccountUID]			int					���� UID
--					: [CharacterName]		varchar(20)			ĳ���� �̸�
--					: [CharacterUID]		int					ĳ���� UID
--					: [Level]				tinyint				ĳ���� ����	(1~110)
--					: [UnitKind]			int					�������		(1 ~ 15 = B���, 16 ~ 240 = M���, 256 ~ 3840 = A���, 4096 ~ 61440 = I���)
--                  : [InfluenceType]       tinyint             ��������		(1 = �Ϲ�, 2 = ����������, 4 = �˸���)
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetCharacterInfoByCharacterName]
	@CharacterName			varchar(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [AccountName], [AccountUniqueNumber], [CharacterName], [UniqueNumber], [Level], [UnitKind], [InfluenceType] FROM [dbo].[td_Character] WITH (NOLOCK) WHERE [CharacterName] = @CharacterName AND 0 = [Race] & 16384
END
GO


--> 130605_DB��Ű��_03_(��������Ʈ����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--!!!!
-- Name: atum_UpdateInfluenceConsecutiveVictorites
-- Desc: // 2013-05-09 by hskim, ���� ����Ʈ ����
--====
CREATE PROCEDURE [dbo].[atum_UpdateInfluenceConsecutiveVictorites]
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,	
	@i_ConsecutiveVictories		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	UPDATE td_InfluenceWarData
		SET ConsecutiveVictories = @i_ConsecutiveVictories
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
END
GO


--> 130605_DB��Ű��_04_(�������߰�����)_DBQuery(atum2_db_[n] & stum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_InsertStoreExtension]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InsertStoreExtension]
	@i_UniqueNumber		BIGINT,
	@i_Gesture			BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	IF EXISTS(SELECT * FROM [td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber)
	BEGIN
		-- ����
		UPDATE [dbo].[td_StoreExtension] SET [Gesture] = @i_Gesture WHERE [UniqueNumber] = @i_UniqueNumber
	END
	ELSE
	BEGIN
		-- �߰�
		INSERT INTO [dbo].[td_StoreExtension] ([UniqueNumber], [Gesture]) VALUES (@i_UniqueNumber, @i_Gesture)
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetStoreExtension]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetStoreExtension]
	@i_UniqueNumber		BIGINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [Gesture] FROM [dbo].[td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetTemporarySystemInfomation]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetTemporarySystemInfomation]
	@i_Type		INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT [UID], [CreateDate], [Data1], [Data2], [Data3], [Data4] FROM [dbo].[atum_Temporary_SystemInfomation] WITH (NOLOCK) WHERE [Type] = @i_Type
END
GO


--> 130617_DB��Ű��_01_(�Ƹ��÷���)_DBQuery(atum2_db_[n] & atum2_db_arena)
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Insert_ShapeStatLevel]
-- DESC				: // 2013-05-31 by jhseol,bckim �Ƹ� �÷���
-- �Ƹӿ� ����� �÷��� ������ ��� �� ������Ʈ �ϴ� ���ν���
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Insert_ShapeStatLevel]
	@i_ItemKind			TINYINT,
	@i_ItemUID			BIGINT,
	@i_ShapeItemNum		INT,
	@i_AllStatLevel		INT
--WITH EXECUTE AS 'proexe'
AS

BEGIN
	DECLARE	@ResultCnt	INT
	SELECT @ResultCnt = COUNT(*) FROM [dbo].[td_ShapeStatLevel]  WITH(NOLOCK) WHERE [ItemUID] = @i_ItemUID

	IF( @ResultCnt != 0 )
	BEGIN
		UPDATE [dbo].[td_ShapeStatLevel]  SET [ShapeItemNum] = @i_ShapeItemNum, [AllStatLevel] = @i_AllStatLevel
			WHERE  [ItemUID] = @i_ItemUID 
	END

	ELSE
	BEGIN
		INSERT INTO [dbo].[td_ShapeStatLevel] ([ItemKind],[ItemUID],[ShapeItemNum],[AllStatLevel]) 
			VALUES (@i_ItemKind, @i_ItemUID, @i_ShapeItemNum,@i_AllStatLevel)
	END
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_Get_ShapeStatLevel]
-- DESC				: // 2013-05-31 by jhseol,bckim �Ƹ� �÷���
-- �Ƹӿ� ����� �÷��� ������ �������� ���ν���
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_Get_ShapeStatLevel]
	@i_ItemUID			BIGINT
--WITH EXECUTE AS 'proexe'
AS

BEGIN
	SELECT [ItemKind],[ItemUID],[ShapeItemNum],[AllStatLevel]
	FROM [dbo].[td_ShapeStatLevel] WITH(NOLOCK)
	WHERE [ItemUID] = @i_ItemUID
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_GetCollectionList]
-- DESC				: // 2013-05-31 by jhseol,bckim �Ƹ� �÷���
-- �÷��� ������ �������� ���ν���
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_GetCollectionList]
	@i_Type				INT,
	@i_AccountUID		INT
--WITH EXECUTE AS 'proexe'
AS

BEGIN
	SELECT 	[Type], [AccountUID],[CharacterUID],[BaseItemNum],[OptionItemNum],[Level],[RemainSeconds],[MAEOptionItemNum],[MAEDurationTime]
	FROM dbo.td_Collection WITH (NOLOCK)
	WHERE @i_Type = [Type] AND	@i_AccountUID = [AccountUID]
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_GetCollectionList]
-- DESC				: // 2013-05-31 by jhseol,bckim �Ƹ� �÷���
-- �÷��� ��� �� ������Ʈ�ϴ� ���ν���
--------------------------------------------------------------------------------
CREATE PROC [dbo].[atum_UpdateCollectionInfo]
	@i_Type				INT,
	@i_AccountUID		INT,
	@i_CharacterUID		INT,
	@i_BaseItemNum		INT,
	@i_OptionItemNum	INT,
	@i_Level			TINYINT,
	@i_RemainSeconds	INT,
	@i_MAEOptionItemNum	INT,
	@i_MAEDurationTime		DATETIME
--WITH EXECUTE AS 'proexe'
AS

BEGIN
	DECLARE @iBaseNum INT;
	SET @iBaseNum = (SELECT [BaseItemNum] FROM dbo.td_Collection WITH(NOLOCK)
					WHERE 	@i_Type	= [Type] AND
							@i_AccountUID = [AccountUID] AND
							@i_CharacterUID	= [CharacterUID] AND
							@i_BaseItemNum = [BaseItemNum] )


	IF (@iBaseNum IS NULL)
	BEGIN
		INSERT INTO dbo.td_Collection ( [Type],[AccountUID],[CharacterUID],[BaseItemNum],[OptionItemNum],[Level],[RemainSeconds],[MAEOptionItemNum],[MAEDurationTime])
		VALUES (	@i_Type,@i_AccountUID,@i_CharacterUID,@i_BaseItemNum,@i_OptionItemNum,@i_Level,@i_RemainSeconds,@i_MAEOptionItemNum,@i_MAEDurationTime);
	END
	ELSE
	BEGIN
		UPDATE dbo.td_Collection 
		SET [OptionItemNum] = @i_OptionItemNum , [Level] = @i_Level, [RemainSeconds] = @i_RemainSeconds, [MAEOptionItemNum] = @i_MAEOptionItemNum, [MAEDurationTime] = @i_MAEDurationTime
		WHERE @i_Type = [Type] AND @i_AccountUID = [AccountUID] AND @i_CharacterUID	= [CharacterUID] AND @i_BaseItemNum = [BaseItemNum]
	END

END
GO


--> 130617_DB��Ű��_02_(�̴��ǾƸ�)_DBQuery(atum2_db_[n] & atum2_db_arena)
------------------------------------------------------------------------------------------------
-- 2013-04-18 by jhseol,bckim �̴��� �Ƹ�
------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------
-- INSERT & UPDATE
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InsertMonthlyArmorEvent]
	@i_EventUID				INT,
	@i_StartDate			VARCHAR(30),
	@i_EndDate				VARCHAR(30),
	@i_ItemNum				INT,
	@i_ArmorSourceIndex		INT,
	@i_OptionItemNum		INT
--WITH EXECUTE AS 'proexe'
AS
	IF (@i_EventUID = 0 )
	BEGIN
		INSERT into atum2_db_account.dbo.td_MonthlyArmorEvent ([StartDate],[EndDate],[ArmorItemNum],[ArmorSourceIndex],[OptionItemNum],[Duration])
		VALUES (@i_StartDate, @i_EndDate, @i_ItemNum, @i_ArmorSourceIndex, @i_OptionItemNum, @i_Duration)

		SELECT @@IDENTITY	
	END
	ELSE
	BEGIN
		UPDATE atum2_db_account.dbo.td_MonthlyArmorEvent
		SET [StartDate]= @i_StartDate, [EndDate] = @i_EndDate,[ArmorItemNum] = @i_ItemNum, [ArmorSourceIndex] = @i_ArmorSourceIndex, [OptionItemNum] = @i_OptionItemNum, [Duration]= @i_Duration
		WHERE [EventUID] = @i_EventUID;
		return @i_EventUID
	END
GO



------------------------------------------------------------------------------------------------
-- SELECT ������� ��� 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetMonthlyArmorEventByTool]
--WITH EXECUTE AS 'proexe'
AS
	SELECT M.[EventUID], M.[StartDate], M.[EndDate], M.[ArmorItemNum], M.[ArmorSourceIndex], M.[OptionItemNum],
	(SELECT I.ItemName FROM atum2_db_account.dbo.ti_ItemInfo I WHERE M.[ArmorItemNum] = I.ItemNum),
	(SELECT I.ItemName FROM atum2_db_account.dbo.ti_ItemInfo I WHERE M.[OptionItemNum] = I.ItemNum),m.[Duration]
	FROM atum2_db_account.dbo.td_MonthlyArmorEvent M
GO

------------------------------------------------------------------------------------------------
-- SELECT ���μҽ����� ��� 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetMonthlyArmorEventByServer]
--WITH EXECUTE AS 'proexe'
AS
	SELECT [EventUID],[StartDate],[EndDate],[ArmorSourceIndex],[OptionItemNum],[Duration]
	FROM atum2_db_account.dbo.td_MonthlyArmorEvent
GO


------------------------------------------------------------------------------------------------
-- DELETE 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_DeleteMonthlyArmorEvent]
	@i_EventUID		int
--WITH EXECUTE AS 'proexe'
AS
	DELETE FROM atum2_db_account.dbo.td_MonthlyArmorEvent WHERE [EventUID] = @i_EventUID
GO
------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------
-- SELECT : �̴��� �Ƹ� ����Ʈ 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetMonthlyArmorList]
	@i_DesParam				INT,
	@i_ItemKind				TINYINT
--WITH EXECUTE AS 'proexe'
AS
	SELECT [SkillLevel],[ItemNum],[LinkItem],[ItemName],[ReqUnitKind]
	FROM atum2_db_account.dbo.ti_ItemInfo 
	WHERE SkillLevel > 0 AND @i_ItemKind = kind AND @i_DesParam in (
	[DestParameter1],
	[DestParameter2],
	[DestParameter3],
	[DestParameter4],
	[DestParameter5],
	[DestParameter6],
	[DestParameter7],
	[DestParameter8]
	) 
GO


------------------------------------------------------------------------------------------------
-- SELECT : �̴��� �ɼ� ����Ʈ 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_GetMonthlyOptionList]
	@i_DesParam				INT
--WITH EXECUTE AS 'proexe'
AS
	SELECT [ItemNum],[ItemName],[ReqUnitKind]
	FROM atum2_db_account.dbo.ti_ItemInfo 
	WHERE @i_DesParam in (
	[DestParameter1],
	[DestParameter2],
	[DestParameter3],
	[DestParameter4],
	[DestParameter5],
	[DestParameter6],
	[DestParameter7],
	[DestParameter8]
	)
GO


--> 130708_DB��Ű��_(Try_Enchant_Log)_DBQuery(atum2_db_[n] & atum2_db_arena)
------------------------------------------------------------------------------------------------
-- �α����� ���ν��� ���� 
------------------------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_log_Insert_Try_Enchant_Info]
	@i_LogType						TINYINT,
	@i_CharacterUniqueNumber		INT,
	@i_ItemUniqueNumber				BIGINT,
	@i_ItemNum						INT,
	@i_ResultType					VARCHAR(32),
	@i_PrefixCodeNum				INT,
	@i_SuffixCodeNum				INT,
	@i_EnchantCount					INT,
	@i_CardList						VARCHAR(512)
--WITH EXECUTE AS 'proexe'
AS
	INSERT INTO dbo.atum_log_item_Try_Enchant_Info
	VALUES (@i_LogType, GetDate(), @i_CharacterUniqueNumber,
			@i_ItemUniqueNumber, @i_ItemNum, @i_ResultType,
			@i_PrefixCodeNum,@i_SuffixCodeNum,
			@i_EnchantCount,@i_CardList)
GO


--> 130805_DB��Ű��_01_(Ÿ ���� ���º���)_DBQuery(atum2_db_[n])
--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_CheckInfluenceType_ByAccountUID]
-- DESC				: // 2013-07-26 by jhseol, Ÿ ���� ���º���
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_CheckInfluenceType_ByAccountUID]
	@i_AccountUID					INT,
	@i_InflTy					TINYINT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	-- ���º����� �ɸ��� CUID�� ������ �ӽ� ���̺�
	CREATE TABLE #ChangeCharCUID (CUID INT, CLevel TINYINT, CTime BIGINT PRIMARY KEY (CUID))

	-- ���º����� ������ ������ �ɸ����ΰ� Ȯ��
	DECLARE @CharacterCUID INT
	DECLARE @CharacterInfluenceType TINYINT
	DECLARE @CharacterLevel TINYINT
	DECLARE @CharacterRace SMALLINT
	DECLARE @CharacterGuildUID INT
	DECLARE @CharacterTotalPlayTime BIGINT
	SET @CharacterCUID = 0
	SET @CharacterInfluenceType = 0
	SET @CharacterLevel = 0
	SET @CharacterRace = 0
	SET @CharacterGuildUID = 0
	SET @CharacterTotalPlayTime = 0

	SET NOCOUNT ON
	DECLARE CursorCharacterInfo CURSOR LOCAL FOR 
	SELECT UniqueNumber, [Level], InfluenceType, Race, GuildUniqueNumber, TotalPlayTime FROM dbo.td_Character WITH(NOLOCK)
	WHERE AccountUniqueNumber = @i_AccountUID
	OPEN CursorCharacterInfo
	FETCH NEXT FROM CursorCharacterInfo INTO @CharacterCUID, @CharacterLevel, @CharacterInfluenceType, @CharacterRace, @CharacterGuildUID, @CharacterTotalPlayTime
	WHILE @@FETCH_STATUS = 0
	BEGIN
		IF @CharacterInfluenceType = @i_InflTy
		BEGIN
			SELECT 1
			RETURN	-- �̹� ������ ������ �ɸ��Ͱ� �ִ�.
		END

		IF @CharacterInfluenceType = 2 OR @CharacterInfluenceType = 4
		BEGIN
			IF @CharacterRace & 0x70 <> 0
			BEGIN
				SELECT 2
				RETURN	-- ���������� �Ұ����� ������ �ɸ��Ͱ� �ִ� (������, ��������1, ��������2)
			END

			IF @CharacterGuildUID <> 0
			BEGIN
				SELECT 3
				RETURN	-- ���ܿ� ���ԵǾ� �ִ� �ɸ��Ͱ� �ִ�.
			END

			INSERT INTO #ChangeCharCUID(CUID, CLevel, CTime)
			VALUES (@CharacterCUID, @CharacterLevel, @CharacterTotalPlayTime)
		END
		FETCH NEXT FROM CursorCharacterInfo INTO @CharacterCUID, @CharacterLevel, @CharacterInfluenceType, @CharacterRace, @CharacterGuildUID, @CharacterTotalPlayTime
	END
	CLOSE CursorCharacterInfo
	DEALLOCATE CursorCharacterInfo

	SELECT 100, CUID, CLevel, CTime FROM #ChangeCharCUID
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_ChangeInfluence_ItemNum]
-- DESC				: // 2013-07-26 by jhseol, Ÿ ���� ���º���
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_ChangeInfluence_ItemNum]
	@i_CharcUID					INT,
	@i_InflTy					TINYINT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	IF (@i_InflTy = 2)
	BEGIN
		-- change Influence Type from ANI to BCU
		UPDATE dbo.td_Store
			SET ItemNum = im.ItemNumForBCU, Wear = 0, ItemWindowIndex = 100
		FROM dbo.td_Store s INNER JOIN atum2_db_account.dbo.ti_ItemMatching im ON s.ItemNum = im.ItemNumForANI
		WHERE s.Possess = @i_CharcUID
	END
	ELSE IF (@i_InflTy = 4)
	BEGIN
		-- change Influence Type from BCU to ANI
		UPDATE dbo.td_Store
			SET ItemNum = im.ItemNumForANI, Wear = 0, ItemWindowIndex = 100
		FROM dbo.td_Store s INNER JOIN atum2_db_account.dbo.ti_ItemMatching im ON s.ItemNum = im.ItemNumForBCU
		WHERE s.Possess = @i_CharcUID
	END

	DELETE FROM td_CharacterQuest
	WHERE CharacterUniqueNumber = @i_CharcUID AND QuestState = 1
END
GO



--------------------------------------------------------------------------------
-- PROCEDURE NAME	: [atum_getAccountName_byAccountUID]
-- DESC				: // 2013-07-26 by jhseol, Ÿ ���� ���º���
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_getAccountName_byAccountUID]
	@i_AccountUID					INT
--WITH EXECUTE AS 'proexe'
AS
BEGIN
	SELECT AccountName
	FROM atum2_db_account.dbo.td_account WITH(NOLOCK)
	WHERE AccountUniqueNumber = @i_AccountUID
END
GO
