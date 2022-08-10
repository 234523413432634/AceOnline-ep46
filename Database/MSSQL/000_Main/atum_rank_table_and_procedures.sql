--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_level, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_level(
	PilotFace			TINYINT,
	CharacterName		VARCHAR(20),
	UnitKind			INT,
	Level				TINYINT,
	Experience			FLOAT,
	LevelUpTime			DATETIME,			-- 2006-12-18 by cmkwon, ������ �ð�
	GuildName			VARCHAR(30),
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),
	InfluenceType		TINYINT
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_level ON td_rank_level(CharacterName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_level_gear, 2006-11-09 by cmkwon
-- DESC      : �� ������ŷ���� �� 10�� ��ŷ, �� 40��
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_level_gear(
	PilotFace			TINYINT,
	CharacterName		VARCHAR(20),
	UnitKind			INT,
	Level				TINYINT,
	Experience			FLOAT,
	LevelUpTime			DATETIME,			-- 2006-12-18 by cmkwon, ������ �ð�
	GuildName			VARCHAR(30),
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),
	InfluenceType		TINYINT
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_level_gear ON td_rank_level_gear(CharacterName)
CREATE INDEX idx_UnitKind_on_rank_level_gear ON td_rank_level_gear(UnitKind)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_fame, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_fame(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- ĳ���͸�
	UnitKind			INT,				-- Gear(���)
	Level				TINYINT,			-- ĳ���� ����
	Propensity			INT,				-- ĳ���� ���� ��
	GuildName			VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),		-- ���� ��ũ �̹���
	InfluenceType		TINYINT				-- �Ҽ� ����
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_fame ON td_rank_fame(CharacterName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_fame_gear, 2007-05-09 by cmkwon
-- DESC      : �� ���θ���ŷ���� �� 10�� ��ŷ, �� 40��
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_fame_gear(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- ĳ���͸�
	UnitKind			INT,				-- Gear(���)
	Level				TINYINT,			-- ĳ���� ����
	Propensity			INT,				-- ĳ���� ���� ��
	GuildName			VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),		-- ���� ��ũ �̹���
	InfluenceType		TINYINT				-- �Ҽ� ����
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_fame_gear ON td_rank_fame_gear(CharacterName)
CREATE INDEX idx_UnitKind_on_rank_fame_gear ON td_rank_fame_gear(UnitKind)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_guild_total_fame, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_guild_total_fame(
	GuildMarkImage			BINARY(1600),		-- ���� ��ũ �̹���
	GuildName				VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID				INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	CommanderCharacterName	VARCHAR(20),		-- ������ ĳ���͸�
	GuildTotalFame			INT,				-- ���� �Ѹ�
	CommanderInfluenceType	TINYINT,			-- ������ ����
	GuildMemberCount		INT					-- ���ܿ���
)
CREATE UNIQUE INDEX idx_GuildName_on_rank_guild_total_fame ON td_rank_guild_total_fame(GuildName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_guild_monthly_fame, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_guild_monthly_fame(
	GuildMarkImage			BINARY(1600),		-- ���� ��ũ �̹���
	GuildName				VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID				INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	CommanderCharacterName	VARCHAR(20),		-- ������ ĳ���͸�
	GuildMonthlyFame		INT,				-- ���� �Ѹ�
	CommanderInfluenceType	TINYINT,			-- ������ ����
	GuildMemberCount		INT					-- ���ܿ���
)
CREATE UNIQUE INDEX idx_GuildName_on_rank_guild_monthly_fame ON td_rank_guild_monthly_fame(GuildName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_pvp, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_pvp(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- ĳ���͸�
	UnitKind			INT,				-- Gear(���)
	Level				TINYINT,			-- ĳ���� ����
	GuildName			VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),		-- ���� ��ũ �̹���
	PvPScore			INT,				-- PvP ���ھ�
	PvPWinPoint			INT,				-- PvP �¸� ����Ʈ
	PvPLossPoint		INT,				-- PvP �й� ����Ʈ
	InfluenceType		TINYINT				-- �Ҽ� ����
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_pvp ON td_rank_pvp(CharacterName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_pvp_gear, 2007-05-09 by cmkwon
-- DESC      : �� PvP��ŷ���� �� 10�� ��ŷ, �� 40��
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_pvp_gear(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- ĳ���͸�
	UnitKind			INT,				-- Gear(���)
	Level				TINYINT,			-- ĳ���� ����
	GuildName			VARCHAR(30),		-- �Ҽ� ���� �̸�
	GuildUID			INT,				-- 2006-10-24 by cmkwon, ��û���� �߰���
	GuildMarkImage		BINARY(1600),		-- ���� ��ũ �̹���
	PvPScore			INT,				-- PvP ���ھ�
	PvPWinPoint			INT,				-- PvP �¸� ����Ʈ
	PvPLossPoint		INT,				-- PvP �й� ����Ʈ
	InfluenceType		TINYINT				-- �Ҽ� ����
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_pvp_gear ON td_rank_pvp_gear(CharacterName)
CREATE INDEX idx_UnitKind_on_rank_pvp_gear ON td_rank_pvp_gear(UnitKind)
GO




-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
--!!!!
-- Name: rank_reset_level
-- Desc: level ranking table reset 
-- 			2006-10-24 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_level
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_level

	INSERT INTO td_rank_level
		SELECT TOP 50 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Experience, c.LevelUpTime, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Experience DESC, c.LevelUpTime

GO



--!!!!
-- Name: rank_reset_level_gear
-- Desc: each gear level ranking table reset 
-- 			2006-11-09 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_level_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_level_gear

	INSERT INTO td_rank_level_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Experience, c.LevelUpTime, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 15 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY Experience DESC, c.LevelUpTime

	INSERT INTO td_rank_level_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Experience, c.LevelUpTime, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 240 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Experience DESC, c.LevelUpTime

	INSERT INTO td_rank_level_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Experience, c.LevelUpTime, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 3840 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Experience DESC, c.LevelUpTime

	INSERT INTO td_rank_level_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Experience, c.LevelUpTime, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 61440 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Experience DESC, c.LevelUpTime
GO


--!!!!
-- Name: rank_reset_fame
-- Desc: fame ranking table reset 
-- 			2006-10-24 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_fame

	INSERT INTO td_rank_fame
		SELECT TOP 50 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Propensity, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
			FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
		    ORDER BY c.Propensity DESC, c.LevelUpTime
GO


--!!!!
-- Name: rank_reset_fame_gear
-- Desc: 2007-05-09 by cmkwon, �߰���, each gear fame ranking table reset 
--
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_fame_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_fame_gear

	INSERT INTO td_rank_fame_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Propensity, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
			FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 15 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Propensity DESC, c.LevelUpTime

	INSERT INTO td_rank_fame_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Propensity, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
			FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 240 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Propensity DESC, c.LevelUpTime

	INSERT INTO td_rank_fame_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Propensity, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
			FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 3840 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Propensity DESC, c.LevelUpTime

	INSERT INTO td_rank_fame_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, c.Propensity, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, c.InfluenceType
			FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 61440 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY c.Propensity DESC, c.LevelUpTime
GO

--!!!!
-- Name: rank_reset_guild_total_fame
-- Desc: guild_total_fame ranking table reset 
-- 			2006-10-24 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--====
CREATE PROCEDURE dbo.rank_reset_guild_total_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_guild_total_fame

	INSERT INTO td_rank_guild_total_fame
		SELECT TOP 50 g.GuildMarkImage, g.GuildName, g.GuildUniqueNumber, c.CharacterName, g.TotalFame, c.InfluenceType, tm.MemCount
			FROM td_Character c, td_Guild g, (SELECT g2.GuildUniqueNumber, COUNT(g2.GuildUniqueNumber) AS MemCount FROM td_Guild g2, td_GuildMember gm WHERE g2.GuildUniqueNumber = gm.GuildUniqueNumber GROUP BY g2.GuildUniqueNumber) tm
			WHERE g.GuildCommanderUniqueNumber = c.uniquenumber and g.GuildUniqueNumber = tm.GuildUniquenumber AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY g.TotalFame desc
GO

--!!!!
-- Name: rank_reset_guild_monthly_fame
-- Desc: guild_monthly_fame ranking table reset 
-- 			2006-10-24 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--====
CREATE PROCEDURE dbo.rank_reset_guild_monthly_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_guild_monthly_fame

	INSERT INTO td_rank_guild_monthly_fame
		SELECT TOP 50 g.GuildMarkImage, g.GuildName, g.GuildUniqueNumber, c.CharacterName, g.MonthlyFame, c.InfluenceType, tm.MemCount
			FROM td_Character c, td_Guild g, (SELECT g2.GuildUniqueNumber, COUNT(g2.GuildUniqueNumber) AS MemCount FROM td_Guild g2, td_GuildMember gm WHERE g2.GuildUniqueNumber = gm.GuildUniqueNumber GROUP BY g2.GuildUniqueNumber) tm
			WHERE g.GuildCommanderUniqueNumber = c.uniquenumber and g.GuildUniqueNumber = tm.GuildUniquenumber AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY g.MonthlyFame desc
GO



--!!!!
-- Name: rank_reset_pvp
-- Desc: pvp ranking table reset 
-- 			2006-10-24 by cmkwon, �˻��� GuildUID �ʵ� �߰���
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_pvp
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_pvp

	INSERT INTO td_rank_pvp
		SELECT TOP 50 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, (c.PKWinPoint*10-c.PKLossPoint*5) AS SCORE, c.PKWinPoint, c.PKLossPoint, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY SCORE DESC, c.LevelUpTime
GO


--!!!!
-- Name: rank_reset_pvp_gear
-- Desc: 2007-05-09 by cmkwon, �߰���, each gear pvp ranking table reset 
--
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, ������ ĳ���� ó��(RACE_DELETED_CHARACTER) - �˻� ������� ���� �Ѵ�
--====
CREATE PROCEDURE dbo.rank_reset_pvp_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	TRUNCATE TABLE td_rank_pvp_gear

	INSERT INTO td_rank_pvp_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, (c.PKWinPoint*10-c.PKLossPoint*5) AS SCORE, c.PKWinPoint, c.PKLossPoint, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 15 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY SCORE DESC, c.LevelUpTime

	INSERT INTO td_rank_pvp_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, (c.PKWinPoint*10-c.PKLossPoint*5) AS SCORE, c.PKWinPoint, c.PKLossPoint, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 240 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY SCORE DESC, c.LevelUpTime

	INSERT INTO td_rank_pvp_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, (c.PKWinPoint*10-c.PKLossPoint*5) AS SCORE, c.PKWinPoint, c.PKLossPoint, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 3840 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY SCORE DESC, c.LevelUpTime

	INSERT INTO td_rank_pvp_gear
		SELECT TOP 10 c.PilotFace, c.CharacterName, c.UnitKind, c.Level, g.GuildName, g.GuildUniqueNumber, g.GuildMarkImage, (c.PKWinPoint*10-c.PKLossPoint*5) AS SCORE, c.PKWinPoint, c.PKLossPoint, c.InfluenceType
		    FROM dbo.td_Character c LEFT OUTER JOIN dbo.td_Guild g ON c.GuildUniqueNumber = g.GuildUniqueNumber
			WHERE 0 = c.Race & 0x4000 AND c.Race < 128 AND 0 <> c.UnitKind & 61440 AND c.AccountName NOT IN 
					(SELECT AccountName FROM atum2_db_account.dbo.td_blockedaccounts) 
			ORDER BY SCORE DESC, c.LevelUpTime
GO


