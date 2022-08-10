-- // 2009-04-29 �Ϻ� GM ����Ʈ �̺�Ʈ - 3.	�õ�(7002660) 30���� ȹ���϶� (Ư���� �����͸� �������� �մϴ�.)
-- ���� �ؾ� �ϴ� ���� : �ش� ������ DB��(atum2_db_[n])�� ��� DB��(atum2_db_[n]_backup) 
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

	-- ��� DB�� �ش� �������� ������ �ְ� ���絵 �������� ������ ��������Ʈ
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.AddedCount
	FROM atum2_db_1.dbo.td_character c, tmStatistics tm
	WHERE c.uniqueNumber = tm.Possess AND tm.AddedCount IS NOT NULL
	ORDER BY tm.AddedCount DESC

	-- ��� DB�� �ش� �������� �������� �ʾ����� ����� �������� ������ ��������Ʈ
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.CurTotalCount AS AddedCount
	FROM atum2_db_1.dbo.td_character c, tmStatistics tm
	WHERE c.uniqueNumber = tm.Possess AND tm.AddedCount IS NULL
	ORDER BY AddedCount DESC

	-- ��� DB�� ���Ŀ� ĳ���͸� ������ ������ �ش� �������� ������ ��������Ʈ
	SELECT c.AccountName, c.AccountUniqueNumber, c.CharacterName, c.UniqueNumber, tm.TotalCount AS AddedCount
	FROM atum2_db_1.dbo.td_character c, (SELECT AccountUniqueNumber, possess, SUM(currentcount) AS TotalCount
											FROM atum2_db_1.dbo.td_store
											WHERE itemnum = 7002660 and 2 <> ItemStorage AND Possess NOT IN (SELECT UniqueNumber FROM atum2_db_1_backup.dbo.td_Character)
											GROUP BY AccountUniqueNumber, possess) tm
	WHERE c.UniqueNumber = tm.Possess
	ORDER BY AddedCount DESC
