--------------------------------
-- LevelRanking
--------------------------------
drop view LevelRanking
go

create view LevelRanking
as
	select c.accountname, c.accountuniquenumber, c.charactername, c.uniquenumber, c.level, atum.atum_GetGearString(c.unitkind) as unit, c2.maxexp, c2.numofcharacter, a.sex, a.birthyear, (2005-a.birthyear) as age, ((2005-a.birthyear)-1)/5 as b_age, a.registereddate, a.lastlogindate, c.createdtime, c.LastStartedTime
	from character c, (select accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter
						from character
						where race < 128
						group by accountuniquenumber) c2, account a
	where c.accountuniquenumber = c2.accountuniquenumber and c.experience = c2.maxexp
			and (c2.maxexp != 0 OR charactername in (select max(charactername) from character group by accountuniquenumber))
			and a.accountuniquenumber = c.accountuniquenumber and a.LastLoginDate > '2004-09-17 14:00'
GO

-- ����� ���� �� ����ġ
select * from levelranking order by maxexp desc

-- ������ ���
select level, count(*) as count
from levelranking 
group by level
order by level desc

-- ��� ���� �ο� �˻�(ĳ���� �̻����� �� Ư�� ���� ��)
select * from character where accountuniquenumber in (
	select accountuniquenumber from account a where a.lastlogindate > '2004/9/17 14:00' and a.accountname not in (select accountname from levelranking)
)

-- ���̺� ���� ����
select b_age*5+1, count(*) from levelranking where sex = 1 group by b_age
select b_age*5+1, count(*) from levelranking where sex = 2 group by b_age


-----------------------------------------
-- ��¥, �ð��� ���
-----------------------------------------

-- ��¥�� ���� ���� ����
select time, clientcount
from atum_log_server_map
where mapindex = 0 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59'
order by time desc
GO

-- ��¥�� �ְ�, ��� ������
drop view user_count_timeline
go
create view user_count_timeline
as
select top 100000 time, DATEPART(yy, time)*10000+DATEPART(m, time)*100+DATEPART(d, time) as date, DATEPART(hh, time) as hour, sum(clientcount) as clientcount
from atum_log_server_map
where mapindex = 0 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59' group by time order by time
go

-- ��¥�� �ְ�, ��� ������
select date, max(clientcount), avg(clientcount)
from user_count_timeline
group by date
order by date

-- �ð��� �ְ�, ��� ������
select hour, max(clientcount), avg(clientcount)
from user_count_timeline
group by hour
order by hour

--------------------------------
-- LevelUnit
--------------------------------
drop view LevelUnit
go

CREATE view LevelUnit
as
select accountname, charactername, level, (level-1)/5*5+5 as slevel, atum.atum_GetGearString(c.unitkind) as unit
from atum.character c
where race < 128 and laststartedtime > '2004-09-17 14:00'
--order by level desc
go

-- ���� �� ���� �� ��� ��
select slevel, unit, count(*) as count
from levelunit
group by slevel, unit
order by slevel, unit

--------------------------------
-- ����, ĳ���ͺ� ���� �ð�
-- VIEW: PlayTime
--------------------------------
drop view playtime
go

create view PlayTime
AS
	select c.accountname, c.accountuniquenumber, c.charactername, c.uniquenumber, c.level, l.TotalPlayTime, l.TotalPlayTime/60 as Minute, l.TotalPlayTime/3600 as Hour
	from character c, (select top 10000000 characteruniquenumber, sum(playtime) as TotalPlayTime
						from atum_log_user_game_start_end
						where logtype = 20 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59'
						group by characteruniquenumber) l
	where c.uniquenumber = l.characteruniquenumber and race < 128
GO

-- ĳ���ͺ� ���� �ð�
select *, cast(level as float)/ totalplaytime * 3600 as Eff
from PlayTime
order by totalplaytime desc

-- ������ ���� �ð�
select accountname, max(level) as level, sum(totalplaytime) as TotalPlayTime
from playtime
group by accountname
order by totalplaytime desc


--------------------------------
-- ��¥�� 1:1 ���� Ƚ ��
--------------------------------
select date, count(*)
from (select time, atum.atum_getonlydate(time) as date
		from atum_log_user_quest_pk_dead l
		where logtype = 22 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59') ll
group by date
order by date

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.character c1, atum.character c2
where logtype = 22 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.character c1, atum.character c2
where (logtype = 22 or logtype = 23) and time > '2004-09-17 14:00' and time < '2004-9-23 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

-- ĳ���ͺ� 1:1 ���� ȸ��
select c1.charactername, (select level from atum.character where charactername = c1.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.character c1, atum.character c2
where (logtype = 22 or logtype = 23) and time > '2004-09-17 14:00' and time < '2004-9-23 23:59' and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber
group by c1.charactername
order by count desc
--order by time

--------------------------------
-- ��¥�� �̼� �̿� ��
--------------------------------
select date, count(*)
from (select time, atum.atum_getonlydate(time) as date
		from atum.atum_log_user_quest_pk_dead l
		where logtype = 21 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59') ll
group by date
order by date

select c.charactername, (select level from atum.character where charactername = c.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.character c
where l.characteruniquenumber = c.uniquenumber and logtype = 21 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59'
group by c.charactername
order by count desc


----------------------------------------------------------------
-- ���� ����(ĳ����) ���
----------------------------------------------------------------

-- ���� �ð�, ������(�������� ���� ĳ���ʹ� ����)
select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel as leveldiff
from playtime p, levelranking l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate < '2004-09-17 14:00'
order by p.accountname

-- ���� ���� ���
select *
from levelranking
where registereddate < '2004-09-17 14:00'

----------------------------------------------------------------
-- �ű� ����(ĳ����) ���
----------------------------------------------------------------

-- ���� �ð�, ������(�������� ���� ĳ���ʹ� ����)
select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel as leveldiff
from playtime p, levelranking l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004-09-17 14:00' and time < '2004-9-23 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate > '2004-09-17 14:00'
order by p.accountname

-- ���� ���� ���
select *
from levelranking
where registereddate > '2004-09-17 14:00'
