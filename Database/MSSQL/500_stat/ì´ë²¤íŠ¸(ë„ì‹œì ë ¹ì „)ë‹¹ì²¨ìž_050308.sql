-- 1.1 atum_db_[n]_event Table ¸¸µé±â
	CREATE TABLE atum_db_3_event(
		AccountUID		INT,
		AccountName		VARCHAR(20),
		CharacterUID	INT,
		CharacterName	VARCHAR(20),
		GuildName		VARCHAR(30),
		LevelGap		INT,
		ExpGap			FLOAT
	)
	CREATE CLUSTERED INDEX idx_CharacterUID_On_db_3_event ON atum_db_3_event(CharacterUID)
	GO


TRUNCATE TABLE atum_db_3_event

INSERT INTO atum_db_3_event
	SELECT a1.AccountUniqueNumber, a1.AccountName, a1.UniqueNumber, a1.CharacterName
			, a1.GuildName, a2.Level - a1.Level, a2.Experience - a1.Experience
		FROM atum_db_3_0222back a1, atum_db_3_0301back a2
		WHERE a1.uniqueNumber = a2.uniqueNumber AND a1.GuildUniqueNumber <> 0 AND a1.GuildName = a2.GuildName

SELECT   GuildName, SUM(LevelGap) AS LGap, SUM(ExpGap) AS EGap
	FROM      atum_db_3_event
	GROUP BY GuildName
	ORDER BY LGap DESC

SELECT   GuildName, SUM(LevelGap) AS LGap, SUM(ExpGap) AS EGap
	FROM      atum_db_3_event
	GROUP BY GuildName
	ORDER BY EGap DESC