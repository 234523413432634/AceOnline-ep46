-- ������ ��¥�� ���ǵ��� ����� �˻�

-- 1. ������ ��¥�� ���ǵ��ٿ� üũ�� �������߿� üũ�� ī��Ʈ�� ū ������ 10���� ĳ���� �˻�
	SELECT c.AccountName, c.AccountuniqueNumber, c.charactername, c.uniquenumber, s.Count
	FROM td_character c, (Select TOP 10 CharacterUniqueNumber, COUNT(CharacterUniqueNumber) As "Count"
			FROM atum_log_user_speed_hack
			WHERE [Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND [Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)
			GROUP BY CharacterUniqueNumber
			ORDER BY Count desc) as s
	where c.uniquenumber = s.Characteruniquenumber

-- 2. ������ ��¥�� ĳ���� ����ũ �ѹ��� ������ ���ǵ��� üũ�� ������ �˻�
	Select c.characterName, s.Time, s.MapIndex, s.ReceivedMoveCounts
		FROM td_character c, atum_log_user_speed_hack s 
		WHERE c.uniquenumber = s.characteruniquenumber and s.characteruniquenumber = 4341
			 and s.[Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND s.[Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)