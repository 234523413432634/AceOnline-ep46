-- // 2009-04-29 일본 GM 퀘스트 이벤트 - 3.	시드(7002660) 30개를 획득하라 (특정일 데이터를 기준으로 합니다.)
-- 수정 해야 하는 사항 : 해당 서버군 DB명(atum2_db_[n])과 백업 DB명(atum2_db_[n]_backup) 
	DROP VIEW tmStatistics
	GO
	CREATE VIEW tmStatistics
	AS
		SELECT curS.AccountUniqueNumber, curS.Possess, curS.TotalCount AS CurTotalCount, oldS.TotalCount AS OldTotalCount, (curS.TotalCount - oldS.TotalCount) AS AddedCount
		FROM (SELECT AccountUniqueNumber, possess, SUM(currentcount) AS TotalCount
				FROM atum2_db_1.dbo.td_store
				WHERE itemnum = 7002660 and 2 <> ItemStorage
				GROUP BY AccountUniqueNumber, possess) curS LEFT OUTER JOIN 
				(SELECT AccountUniqueNumber, possess, SUM(currentcount) AS TotalCount
					FROM atum2_db_1_backup.dbo.td_store 
					WHERE itemnum = 7002660 and 2 <> ItemStorage
					GROUP BY AccountUniqueNumber, possess) oldS on curS.AccountUniqueNumber = oldS.AccountUniqueNumber AND curS.Possess = oldS.Possess 
		WHERE (oldS.TotalCount IS NOT NULL AND (curS.TotalCount - oldS.TotalCount) >= 30) or (oldS.TotalCount IS NULL AND curS.TotalCount >= 30)
	GO

	-- 백업 DB에 해당 아이템을 가지고 있고 현재도 아이템을 소유한 유저리스트
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.AddedCount
	FROM atum2_db_1.dbo.td_character c, tmStatistics tm
	WHERE c.uniqueNumber = tm.Possess AND tm.AddedCount IS NOT NULL
	ORDER BY tm.AddedCount DESC

	-- 백업 DB에 해당 아이템을 소유하지 않았지만 현재는 아이템을 소유한 유저리스트
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.CurTotalCount AS AddedCount
	FROM atum2_db_1.dbo.td_character c, tmStatistics tm
	WHERE c.uniqueNumber = tm.Possess AND tm.AddedCount IS NULL
	ORDER BY AddedCount DESC

	-- 백업 DB에 이후에 캐릭터를 생성한 유저중 해당 아이템을 소유한 유저리스트
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.TotalCount AS AddedCount
	FROM atum2_db_1.dbo.td_character c, (SELECT AccountUniqueNumber, possess, SUM(currentcount) AS TotalCount
											FROM atum2_db_1.dbo.td_store
											WHERE itemnum = 7002660 and 2 <> ItemStorage AND Possess NOT IN (SELECT UniqueNumber FROM atum2_db_1_backup.dbo.td_Character)
											GROUP BY AccountUniqueNumber, possess) tm
	WHERE c.UniqueNumber = tm.Possess
	ORDER BY AddedCount DESC
