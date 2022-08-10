drop view LevelRanking2nd
go

create view LevelRanking2nd
as
	select top 1000000 c.accountname, c.accountuniquenumber, c.charactername, c.uniquenumber, c.level, atum.atum_GetGearString(c.unitkind) as unit, c2.maxexp, c2.numofcharacter, a.sex, a.birthyear, (2005-a.birthyear) as age, a.registereddate, a.lastlogindate
	from atum.character c, (select top 1000000 accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter
						from atum.character
						where race < 128
						group by accountuniquenumber
						order by maxexp desc) c2, atum.account a
	where c.accountuniquenumber = c2.accountuniquenumber and c.experience = c2.maxexp
			and (c2.maxexp != 0 OR charactername in (select max(charactername) from atum.character group by accountuniquenumber))
			and a.accountuniquenumber = c.accountuniquenumber and a.RegisteredDate < '2004/8/5 14:00' and a.lastlogindate > '2004/8/5 14:00'
	order by c2.maxexp desc
GO


select *
from levelranking2nd


--drop view levelunit

create view LevelUnit
as
select top 10000 accountname, charactername, level, (level-1)/5*5 as slevel, atum.atum_GetGearString(c.unitkind) as unit
from atum.character c
where race < 128
order by level desc
go

select slevel, unit, count(*)
from levelunit
group by slevel, unit
order by slevel, unit


select * from character where level > 40



drop view playtime
go

create view PlayTime
AS
	select top 1000000 c.accountname, c.accountuniquenumber, c.charactername, c.uniquenumber,  c.level, l.TotalPlayTime, l.TotalPlayTime/60 as Minute, l.TotalPlayTime/3600 as Hour
	from atum.character c, (select top 10000000 characteruniquenumber, sum(playtime) as TotalPlayTime
						from atum.atum_log_user_game_start_end
						where logtype = 20 and time > '2004/8/5 14:00' and time < '2004/8/13 00:00'
						group by characteruniquenumber) l
	where c.uniquenumber = l.characteruniquenumber and race < 128
	order by TotalPlayTime desc
GO

select *, cast(level as float)/ totalplaytime * 3600 as Eff
from PlayTime
order by totalplaytime desc

select accountname, max(level), sum(totalplaytime)
from playtime
group by accountname



select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel
from playtime p, levelranking2nd l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004/8/5 14:00' and time < '2004/8/13 00:00'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber
order by p.accountname


select characteruniquenumber, min(param1), max(param2)
from atum.atum_log_user_level_stat
where logtype = 16 and time > '2004/8/5 14:00' and time < '2004/8/13 00:00'
group by characteruniquenumber

