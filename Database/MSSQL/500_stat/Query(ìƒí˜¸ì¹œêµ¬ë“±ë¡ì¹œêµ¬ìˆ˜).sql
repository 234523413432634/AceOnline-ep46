
	-- // 2008-06-26 by cmkwon
	SELECT TOP 100 f1.CharacterName, COUNT(*) AS cntsOfChar
	FROM td_friendList f1 INNER JOIN td_friendList f2 ON f1.type = 0 AND f2.Type = 0 AND f1.charactername = f2.FriendName AND f1.FriendName = f2.CharacterName
	GROUP BY f1.CharacterName
	ORDER BY cntsOfChar DESC