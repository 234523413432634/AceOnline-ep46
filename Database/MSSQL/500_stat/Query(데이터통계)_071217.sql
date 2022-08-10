-------------------------------------------------------------------------------
-- 정해진 날짜에 접속한 유니크 계정 리스트
	select dbo.atum_GetOnlyDate(l.Time) AS GameStartDate, c.AccountName, c.SelectableInfluenceMask
		from dbo.td_character c with(nolock) inner join dbo.atum_log_user_game_start_end l with(nolock)
		  on c.uniquenumber = l.characteruniquenumber
		where l.time >= '2007-10-01 00:00:00' and l.time < '2007-12-17 00:00:00' and l.logtype = 19 and (c.influencetype & 6 <> 0)
		group by dbo.atum_GetOnlyDate(l.Time), c.AccountName, c.SelectableInfluenceMask
		order by dbo.atum_GetOnlyDate(l.Time), c.SelectableInfluenceMask, c.AccountName
--
-------------------------------------------------------------------------------


