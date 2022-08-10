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
	LevelUpTime			DATETIME,			-- 2006-12-18 by cmkwon, 레벨업 시간
	GuildName			VARCHAR(30),
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	GuildMarkImage		BINARY(1600),
	InfluenceType		TINYINT
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_level ON td_rank_level(CharacterName)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_level_gear, 2006-11-09 by cmkwon
-- DESC      : 기어별 레벨랭킹으로 기어별 10명 랭킹, 총 40명
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_level_gear(
	PilotFace			TINYINT,
	CharacterName		VARCHAR(20),
	UnitKind			INT,
	Level				TINYINT,
	Experience			FLOAT,
	LevelUpTime			DATETIME,			-- 2006-12-18 by cmkwon, 레벨업 시간
	GuildName			VARCHAR(30),
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
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
	CharacterName		VARCHAR(20),		-- 캐릭터명
	UnitKind			INT,				-- Gear(기어)
	Level				TINYINT,			-- 캐릭터 레벨
	Propensity			INT,				-- 캐릭터 개인 명성
	GuildName			VARCHAR(30),		-- 소속 여단 이름
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	GuildMarkImage		BINARY(1600),		-- 여단 마크 이미지
	InfluenceType		TINYINT				-- 소속 세력
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_fame ON td_rank_fame(CharacterName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_fame_gear, 2007-05-09 by cmkwon
-- DESC      : 기어별 개인명성랭킹으로 기어별 10명 랭킹, 총 40명
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_fame_gear(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- 캐릭터명
	UnitKind			INT,				-- Gear(기어)
	Level				TINYINT,			-- 캐릭터 레벨
	Propensity			INT,				-- 캐릭터 개인 명성
	GuildName			VARCHAR(30),		-- 소속 여단 이름
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	GuildMarkImage		BINARY(1600),		-- 여단 마크 이미지
	InfluenceType		TINYINT				-- 소속 세력
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_fame_gear ON td_rank_fame_gear(CharacterName)
CREATE INDEX idx_UnitKind_on_rank_fame_gear ON td_rank_fame_gear(UnitKind)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_guild_total_fame, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_guild_total_fame(
	GuildMarkImage			BINARY(1600),		-- 여단 마크 이미지
	GuildName				VARCHAR(30),		-- 소속 여단 이름
	GuildUID				INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	CommanderCharacterName	VARCHAR(20),		-- 여단장 캐릭터명
	GuildTotalFame			INT,				-- 여단 총명성
	CommanderInfluenceType	TINYINT,			-- 여단장 세력
	GuildMemberCount		INT					-- 여단원수
)
CREATE UNIQUE INDEX idx_GuildName_on_rank_guild_total_fame ON td_rank_guild_total_fame(GuildName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_guild_monthly_fame, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_guild_monthly_fame(
	GuildMarkImage			BINARY(1600),		-- 여단 마크 이미지
	GuildName				VARCHAR(30),		-- 소속 여단 이름
	GuildUID				INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	CommanderCharacterName	VARCHAR(20),		-- 여단장 캐릭터명
	GuildMonthlyFame		INT,				-- 여단 총명성
	CommanderInfluenceType	TINYINT,			-- 여단장 세력
	GuildMemberCount		INT					-- 여단원수
)
CREATE UNIQUE INDEX idx_GuildName_on_rank_guild_monthly_fame ON td_rank_guild_monthly_fame(GuildName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_pvp, 2006-09-20 by cmkwon
-- DESC      : 
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_pvp(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- 캐릭터명
	UnitKind			INT,				-- Gear(기어)
	Level				TINYINT,			-- 캐릭터 레벨
	GuildName			VARCHAR(30),		-- 소속 여단 이름
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	GuildMarkImage		BINARY(1600),		-- 여단 마크 이미지
	PvPScore			INT,				-- PvP 스코어
	PvPWinPoint			INT,				-- PvP 승리 포인트
	PvPLossPoint		INT,				-- PvP 패배 포인트
	InfluenceType		TINYINT				-- 소속 세력
)
CREATE UNIQUE INDEX idx_CharacterName_on_rank_pvp ON td_rank_pvp(CharacterName)
GO


--------------------------------------------------------------------------------
-- TABLE NAME: td_rank_pvp_gear, 2007-05-09 by cmkwon
-- DESC      : 기어별 PvP랭킹으로 기어별 10명 랭킹, 총 40명
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_rank_pvp_gear(
	PilotFace			TINYINT,			-- 
	CharacterName		VARCHAR(20),		-- 캐릭터명
	UnitKind			INT,				-- Gear(기어)
	Level				TINYINT,			-- 캐릭터 레벨
	GuildName			VARCHAR(30),		-- 소속 여단 이름
	GuildUID			INT,				-- 2006-10-24 by cmkwon, 요청으로 추가함
	GuildMarkImage		BINARY(1600),		-- 여단 마크 이미지
	PvPScore			INT,				-- PvP 스코어
	PvPWinPoint			INT,				-- PvP 승리 포인트
	PvPLossPoint		INT,				-- PvP 패배 포인트
	InfluenceType		TINYINT				-- 소속 세력
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
-- 			2006-10-24 by cmkwon, 검색에 GuildUID 필드 추가함
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_level
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- 			2006-11-09 by cmkwon, 검색에 GuildUID 필드 추가함
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_level_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- 			2006-10-24 by cmkwon, 검색에 GuildUID 필드 추가함
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- Desc: 2007-05-09 by cmkwon, 추가함, each gear fame ranking table reset 
--
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_fame_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- 			2006-10-24 by cmkwon, 검색에 GuildUID 필드 추가함
--====
CREATE PROCEDURE dbo.rank_reset_guild_total_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- 			2006-10-24 by cmkwon, 검색에 GuildUID 필드 추가함
--====
CREATE PROCEDURE dbo.rank_reset_guild_monthly_fame
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- 			2006-10-24 by cmkwon, 검색에 GuildUID 필드 추가함
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_pvp
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- Desc: 2007-05-09 by cmkwon, 추가함, each gear pvp ranking table reset 
--
--			#define UNITKIND_BGEAR_MASK			(USHORT)0x000F	// B-GEAR, 15
--			#define UNITKIND_MGEAR_MASK			(USHORT)0x00F0	// M-GEAR, 240
--			#define UNITKIND_AGEAR_MASK			(USHORT)0x0F00	// A-GEAR, 3840
--			#define UNITKIND_IGEAR_MASK			(USHORT)0xF000	// I-GEAR, 61440
--			// 2007-08-09 by cmkwon, 삭제된 캐릭터 처리(RACE_DELETED_CHARACTER) - 검색 결과에서 제외 한다
--====
CREATE PROCEDURE dbo.rank_reset_pvp_gear
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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


