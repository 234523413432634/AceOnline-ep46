-- 지정한 날짜에 스피드핵 사용자 검색

-- 1. 지정한 날짜에 스피드핵에 체크된 유저들중에 체크된 카운트가 큰 순서로 10명의 캐릭터 검색
	SELECT c.AccountName, c.AccountuniqueNumber, c.charactername, c.uniquenumber, s.Count
	FROM td_character c, (Select TOP 10 CharacterUniqueNumber, COUNT(CharacterUniqueNumber) As "Count"
			FROM atum_log_user_speed_hack
			WHERE [Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND [Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)
			GROUP BY CharacterUniqueNumber
			ORDER BY Count desc) as s
	where c.uniquenumber = s.Characteruniquenumber

-- 2. 지정한 날짜에 캐릭터 유니크 넘버를 가지고 스피드핵 체크된 내용을 검색
	Select c.characterName, s.Time, s.MapIndex, s.ReceivedMoveCounts
		FROM td_character c, atum_log_user_speed_hack s 
		WHERE c.uniquenumber = s.characteruniquenumber and s.characteruniquenumber = 4341
			 and s.[Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND s.[Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)