--------------------------------
-- LevelRanking
--------------------------------
drop view LevelRanking
go

create view LevelRanking
as
	select c.accountname, c.accountuniquenumber, c.charactername, c.uniquenumber, c.level, atum.atum_GetGearString(c.unitkind) as unit, c2.maxexp, c2.numofcharacter, a.sex, a.birthyear, (2005-a.birthyear) as age, ((2005-a.birthyear)-1)/5 as b_age, a.registereddate, a.lastlogindate, c.createdtime, c.LastStartedTime
	from td_character c, (select accountuniquenumber, max(experience) as maxexp, count(*) as numofcharacter
						from td_character
						where race < 128 and charactername not like 'loadtest%'
						group by accountuniquenumber) c2, td_account a
	where c.accountuniquenumber = c2.accountuniquenumber and c.experience = c2.maxexp
			and (c2.maxexp != 0 OR charactername in (select max(charactername) from td_character group by accountuniquenumber))
			and a.accountuniquenumber = c.accountuniquenumber and a.LastLoginDate > '2004-10-28 14:00'
GO

-- ����� ���� �� ����ġ
select * from levelranking order by maxexp desc

-- ������ ���
select level, count(*) as count
from levelranking 
group by level
order by level desc

-- ��� ���� �ο� �˻�(ĳ���� �̻����� �� Ư�� ���� ��)
select * from td_character where accountuniquenumber in (
	select accountuniquenumber from td_account a where a.lastlogindate > '2004-10-28 14:00' and a.accountname not in (select accountname from levelranking)
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
where mapindex = 0 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
order by time desc
GO

-- ��¥�� �ְ�, ��� ������
drop view user_count_timeline
go
create view user_count_timeline
as
select	time,
		DATENAME(yy, time)+'-'+DATENAME(mm, time)+'-'+DATENAME(dd, time) as date,
		CAST(DATENAME(yy, time)+'-'+DATENAME(mm, time)+'-'+DATENAME(dd, time)+' '+DATENAME(hh, time)+':00' as datetime) as datehour,
		DATEPART(hh, time) as hour,
		sum(clientcount) as clientcount
from atum_log_server_map
where mapindex = 0 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
group by time
--order by time
go

-- ������
select time, clientcount
from user_count_timeline
order by time desc

-- ��¥&�ð��� �ְ�, ��� ������
select datehour, max(clientcount) as maxcount, min(clientcount) as mincount, avg(clientcount) as avgcount
from user_count_timeline
group by datehour
order by datehour desc

-- ��¥�� �ְ�, ��� ������
select date, max(clientcount) as maxcount, min(clientcount) as mincount, avg(clientcount) as avgcount
from user_count_timeline
group by date
order by date

-- �ð��� �ְ�, ��� ������
select hour, max(clientcount) as maxcount,
-- min(clientcount) as mincount,
avg(clientcount) as avgcount
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
from atum.td_character c
where race < 128  and charactername not like 'loadtest%' and laststartedtime > '2004-10-28 14:00'
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
	from td_character c, (select top 10000000 characteruniquenumber, sum(playtime) as TotalPlayTime
						from atum_log_user_game_start_end
						where logtype = 20 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
						group by characteruniquenumber) l
	where c.uniquenumber = l.characteruniquenumber and race < 128  and charactername not like 'loadtest%' 
GO

-- ĳ���ͺ� ���� �ð�
select *--, cast(level as float)/ totalplaytime * 3600 as Eff
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
		where logtype = 22 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59') ll
group by date
order by date

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where logtype = 22 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where (logtype = 22 or logtype = 23) and time > '2004-10-28 14:00' and time < '2004-11-7 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

-- ĳ���ͺ� 1:1 ���� ȸ��
select c1.charactername, (select level from atum.td_character where charactername = c1.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where (logtype = 22 or logtype = 23) and time > '2004-10-28 14:00' and time < '2004-11-7 23:59' and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber
group by c1.charactername
order by count desc
--order by time

--------------------------------
-- ��¥�� �̼� �̿� ��
--------------------------------
select date, count(*)
from (select time, atum.atum_getonlydate(time) as date
		from atum.atum_log_user_quest_pk_dead l
		where logtype = 21 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59') ll
group by date
order by date

select c.charactername, (select level from atum.td_character where charactername = c.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.td_character c
where l.characteruniquenumber = c.uniquenumber and logtype = 21 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
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
	where logtype = 16 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate < '2004-10-28 14:00'
order by p.accountname

-- ���� ���� ���
select *
from levelranking
where registereddate < '2004-10-28 14:00'
order by maxexp desc

----------------------------------------------------------------
-- �ű� ����(ĳ����) ���
----------------------------------------------------------------

-- ���� �ð�, ������(�������� ���� ĳ���ʹ� ����)
select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel as leveldiff
from playtime p, levelranking l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate > '2004-10-28 14:00'
order by p.accountname

-- �ű� ���� ���
select *
from levelranking
where registereddate > '2004-10-28 14:00'
order by maxexp desc

----------------------------------------------------------------
-- ������ ���� ��
----------------------------------------------------------------
DECLARE @OldUser INT
DECLARE @NewUser INT

SET @NewUser = (select count(*)
				from td_account
				where lastlogindate > '2004-10-28 14:00' and registereddate >= '2004-10-28 14:00' and accounttype = 0
				--order by accountname
				--order by registereddate
				)

SET @OldUser = (select count(*)
				from td_account
				where lastlogindate > '2004-10-28 14:00' and registereddate < '2004-10-28 14:00' and accounttype = 0
				--order by accountname
				--order by registereddate
				)

SELECT @olduser AS OldUser, @newuser AS NewUser, @olduser + @newuser as TotalUser
GO

select count(distinct AccountUniqueNumber)
from atum_log_connection
where time > '2004-10-28 14:00' and time < '2004-11-7 23:59'
GO

----------------------------------------------------------------
-- ��Ÿ �ӽ� ����
----------------------------------------------------------------
select * from td_store
where prefixcodenum != 0 or suffixcodenum != 0

select * from td_store
where numofenchants!=0

select e.*, i.itemname, i.reqlevel, c.charactername
from td_enchant e, ti_item i, td_character c, td_store s
where e.targetitemuniquenumber = s.uniquenumber and i.itemnum = s.itemnum and s.possess = c.uniquenumber

select top 20 c.accountname, s.*
from td_store s, td_character c
where itemnum=7000022 and s.accountuniquenumber = c.accountuniquenumber
order by currentcount

select top 10 c.accountname, c.charactername, *
from td_store s, td_character c
where itemnum=7000022 and s.possess = c.uniquenumber
order by currentcount desc

select top 400 accountname, charactername, level, atum.atum_GetGearString(unitkind) as unitkind, Experience, totalplaytime/3600
from td_character
where race < 128 and charactername not like 'loadtest%'
order by Experience desc
