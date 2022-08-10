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
			and a.accountuniquenumber = c.accountuniquenumber and a.LastLoginDate > '2004-12-22 16:00'
GO

-- ����� ���� �� ����ġ
select *
from levelranking
where level >= 10
order by maxexp desc

-- ������ ���
select level, count(*) as count
from levelranking 
group by level
order by level asc


-- ��� ���� �ο� �˻�(ĳ���� �̻����� �� Ư�� ���� ��)
select * from td_character where accountuniquenumber in (
	select accountuniquenumber from td_account a where a.lastlogindate > '2004-12-22 16:00' and a.accountname not in (select accountname from levelranking)
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
where mapindex = 0 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
order by time desc
GO

-- ��¥�� �ְ�, ��� ������
drop view user_count_timeline
go
create view user_count_timeline
as
select	time,
		atum.atum_GetOnlyDate(time) as date,
		CAST(DATENAME(yy, time)+'-'+DATENAME(mm, time)+'-'+DATENAME(dd, time)+' '+DATENAME(hh, time)+':00' as datetime) as datehour,
		DATEPART(hh, time) as hour,
		sum(clientcount) as clientcount
from atum_log_server_map
where mapindex = 0 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
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
select date, max(clientcount) as maxcount, avg(clientcount) as avgcount, min(clientcount) as mincount
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

-----------------------------------------
-- ��¥�� ���� �ο�
-----------------------------------------
drop view new_reg_account_data
go
create view new_reg_account_data
as
	select *, atum.atum_getonlydate(RegisteredDate) as RegDate
	from td_Account
	where LastLoginDate >= '2004-12-22 16:00' and RegisteredDate >= '2004-12-22 16:00' and accounttype = 0
go

select RegDate, count(*)
from new_reg_account_data
group by RegDate
order by RegDate

-- ���� ���� ��
select 20041117, count(*)
from td_account
where LastLoginDate >= '2004-12-22 16:00' and RegisteredDate <= '2004-12-22 16:00' and accounttype = 0

--------------------------------
-- LevelUnit
--------------------------------
drop view LevelUnit
go

CREATE view LevelUnit
as
select accountname, charactername, level, (level-1)/5*5+5 as slevel, atum.atum_GetGearString(c.unitkind) as unit
from atum.td_character c
where race < 128  and charactername not like 'loadtest%' and laststartedtime > '2004-12-22 16:00'
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
						where logtype = 20 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
						group by characteruniquenumber) l
	where c.uniquenumber = l.characteruniquenumber and race < 128  and charactername not like 'loadtest%' 
GO

-- ĳ���ͺ� ���� �ð�
select *--, cast(level as float)/ totalplaytime * 3600 as Eff
from PlayTime
order by totalplaytime desc

-- ������ ���� �ð�
select accountname, max(level) as level, sum(totalplaytime) as TotalPlayTime, sum(totalplaytime)/60, sum(totalplaytime)/3600
from playtime
group by accountname
order by totalplaytime desc


--------------------------------
-- ��¥�� 1:1 ���� Ƚ ��
--------------------------------
select date, count(*)
from (select time, atum.atum_getonlydate(time) as date
		from atum_log_user_quest_pk_dead l
		where logtype = 22 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59') ll
group by date
order by date

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where logtype = 22 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2004-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
order by time

-- ĳ���ͺ� 1:1 ���� ȸ��
select c1.charactername, (select level from atum.td_character where charactername = c1.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2004-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber
group by c1.charactername
order by count desc
--order by time

--------------------------------
-- ��¥�� �̼� �̿� ��
--------------------------------
select date, count(*)
from (select time, atum.atum_getonlydate(time) as date
		from atum.atum_log_user_quest_pk_dead l
		where logtype = 21 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59') ll
group by date
order by date

select c.charactername, (select level from atum.td_character where charactername = c.charactername) as level, count(*) as count
from atum.atum_log_user_quest_pk_dead l, atum.td_character c
where l.characteruniquenumber = c.uniquenumber and logtype = 21 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
group by c.charactername
order by level desc


----------------------------------------------------------------
-- ���� ����(ĳ����) ���
----------------------------------------------------------------

-- ���� �ð�, ������(�������� ���� ĳ���ʹ� ����)
select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel as leveldiff
from playtime p, levelranking l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate < '2004-12-22 16:00'
order by p.accountname

-- ���� ���� ���
select (level-1)/5, count(*)
from levelranking
where registereddate < '2004-12-22 16:00'
group by (level-1)/5

----------------------------------------------------------------
-- �ű� ����(ĳ����) ���
----------------------------------------------------------------

-- ���� �ð�, ������(�������� ���� ĳ���ʹ� ����)
select l.accountname, p.charactername, p.totalplaytime, minute, hour, minlevel, maxlevel, maxlevel-minlevel as leveldiff
from playtime p, levelranking l,
	(select characteruniquenumber, min(param1) as minlevel, max(param2) as maxlevel
	from atum.atum_log_user_level_stat
	where logtype = 16 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
	group by characteruniquenumber) ll
where p.accountuniquenumber = l.accountuniquenumber and ll.characteruniquenumber = p.uniquenumber and l.registereddate > '2004-12-22 16:00'
order by p.accountname

-- �ű� ���� ���
select (level-1)/5, count(*)
from levelranking
where registereddate > '2004-12-22 16:00'
group by (level-1)/5


----------------------------------------------------------------
-- ������ ���� ��
----------------------------------------------------------------
DECLARE @OldUser INT
DECLARE @NewUser INT

SET @NewUser = (select count(*)
				from td_account
				where lastlogindate > '2004-12-22 16:00' and registereddate >= '2004-12-22 16:00' and accounttype = 0
				--order by accountname
				--order by registereddate
				)

SET @OldUser = (select count(*)
				from td_account
				where lastlogindate > '2004-12-22 16:00' and registereddate < '2004-12-22 16:00' and accounttype = 0
				--order by accountname
				--order by registereddate
				)

SELECT @olduser AS OldUser, @newuser AS NewUser, @olduser + @newuser as TotalUser
GO

select count(distinct AccountUniqueNumber)
from atum_log_connection
where time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
GO

----------------------------------------------------------------
-- ��Ÿ �ӽ� ����
----------------------------------------------------------------
select count(*) from td_store
where prefixcodenum != 0 or suffixcodenum != 0

select * from td_Enchant

select e.*, s.uniquenumber, i.itemname, i.reqlevel, c.charactername
from td_enchant e, ti_item i, td_character c, td_store s
where e.targetitemuniquenumber = s.uniquenumber and i.itemnum = s.itemnum and s.possess = c.uniquenumber
order by s.uniquenumber

select top 20 c.accountname, s.*
from td_store s, td_character c
where itemnum=7000022 and s.accountuniquenumber = c.accountuniquenumber
order by currentcount desc

select count(*)
from td_store s, td_character c
where s.possess = c.uniquenumber

select top 100 i.itemname, *
from td_store s, ti_item i
where s.itemnum != 7000022 and s.itemnum = i.itemnum
order by s.currentcount desc

select top 100 c.accountname, c.charactername, c.level, *
from td_store s, td_character c
where itemnum=7000022 and s.possess = c.uniquenumber and c.race < 128
order by currentcount desc

select top 400 accountname, charactername, level, atum.atum_GetGearString(unitkind) as unitkind, Experience, totalplaytime/3600, guildname
from td_character
where race < 128 and charactername not like 'loadtest%'
order by Experience desc

select accountname, charactername, level, atum.atum_GetGearString(unitkind) as unitkind, Experience, totalplaytime/3600, guildname
from td_character
where guildname like '%ACE OF PILOT%'
order by level desc

select top 100 * 
from atum_log_item_get_throw
order by time desc

select *
from td_character
where charactername='õ������'

--update td_store set ItemWindowIndex=2
--where uniquenumber=393315

select *
from td_account
where accountname='jkljkll'

select *
from td_storeskill
where Possess=278

select *
from td_character
where DefensePart<=0 or AttackPart<=0 or DefensePart<=0 or FuelPart<=0 or SoulPart<=0 or DodgePart<=0 or ShieldPart<=0

------------------------------------------------------------------------------------------------------------------------
-- 2005-07-19 by cmkwon
-- M-Gear�� ���� ���� : (���� 2, ȸ�� 3) ==> (���� 3, ȸ�� 2)�� ���� ��Ŵ
-- ���� �ʱ�ȭ
-- b-gear
update td_character set
				AttackPart = 3, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 3, DodgePart = 3,
				Bonusstat = 2*(level-1)
where (unitkind = 1)


-- i-gear
update character set
				AttackPart = 4, DefensePart = 2, FuelPart = 3, SoulPart = 3, ShieldPart = 2, DodgePart = 4,
				Bonusstat = 2*(level-1) 
where (unitkind = 4096)  -- i


-- a-gear
update td_character set
				AttackPart = 4, DefensePart = 3, FuelPart = 4, SoulPart = 2, ShieldPart = 4, DodgePart = 1,
				Bonusstat = 2*(level-1) 
where (unitkind = 256)

-- m-gear
update character set
				AttackPart = 2, DefensePart = 4, FuelPart = 4, SoulPart = 3, ShieldPart = 3, DodgePart = 2,
				Bonusstat = 2*(level-1) 
where (unitkind = 16) -- m
------------------------------------------------------------------------------------------------------------------------







-- ��ǻ�� ������ ������ ����
select *
from td_store
where (itemnum>=7009350 and itemnum<=7009610 ) and wear=1
order by possess

-- ��ǻ�� ������ ����Ʈ
select *
from ti_item
where kind=26

select *
from td_guild
order by guilddismemberdate

-- �ߺ� ������ �׽�Ʈ��
exec atum.atum_admin_InsertStoreItem_DB '1942', 7000022
exec atum.atum_admin_InsertStoreItemToAccountStore 'kelovon', 7000022
exec atum.atum_admin_InsertStoreItem_DB '1942', 7003060
exec atum.atum_admin_InsertStoreItemToAccountStore 'kelovon', 7003060


update atum_db_account.dbo.ti_temp_accountname set mgameeventtype = a.accountuniquenumber
from td_account a, atum_db_account.dbo.ti_temp_accountname t
where a.accountname = t.accountname


-- �̺�Ʈ ������ ����(�����ʱ�ȭ ������)
-------------------------------------------------------------------------------------
drop view EventAccountTable
go
create view EventAccountTable
as
select c.accountuniquenumber as accountuniquenumber, count(*) as characternumber
from td_character c, atum_db_account.atum.ti_temp_accountname t
where level >= 10 and t.mgameeventtype = c.accountuniquenumber
group by c.accountuniquenumber
go

select *
from EventAccountTable

INSERT INTO td_Store
		SELECT a.accountUniqueNumber, 0, 0, 1, 0, 99,
				7009970, 0, 0, 0, 0, GetDate()
		FROM EventAccountTable a
--------------------------------------------------------------------------------------
-- �� ���� ����-----------------------------------------------------------------------
drop view MoneyItemTable
go
create view MoneyItemTable
as
select top 100 *
from td_store
where itemnum=7000022
order by currentcount desc

select m.possess, m.accountuniquenumber, m.currentcount, c.charactername, c.level
from MoneyItemTable m, td_character c
where c.uniquenumber = m.possess and c.race < 128
order by m.currentcount desc
--------------------------------------------------------------------------------------
select * from td_store
where itemnum=7009970

select *
from td_account
where accountname='JUNE_LYK'
--where accountuniquenumber=3040
select *
from td_character
where accountuniquenumber=66514


select count(*)
from td_store
where itemnum=7900360

select *
from ti_item
where itemname='������'



-- ���� ���Խ� COUNT������ ���� ������ ���� ����
--delete
--from td_store
--where possess=74706 and itemnum=7900850 and wear=0


--update td_store set currentcount = 12640
--from td_store
--where possess=74706 and itemnum=7000022 and uniquenumber=1578754

--select *
--from td_store
--where possess=74706

-- 2004.12.31 by cmkwon, �α� ī��Ʈ ����
SELECT   COUNT(*)
FROM      atum_log_item_buy_sell
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_item_charac_use
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_item_get_throw
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_item_trade
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))
SELECT   COUNT(*)
FROM      atum_log_server_map
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

------------------------------------------------------------------------
SELECT   COUNT(*)
FROM      atum_log_user_exp
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_user_game_start_end
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_user_level_stat
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_user_quest_pk_dead
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_user_speed_hack
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))

SELECT   COUNT(*)
FROM      atum_log_user_warp
WHERE   ([Time] > CONVERT(DATETIME, '2004-12-30 14:00:00', 102) AND 
                [Time] < CONVERT(DATETIME, '2004-12-30 15:00:00', 102))


-- 2005-01-11 by cmkwon, ������ ��¥�� ���ǵ��� ����� �˻�
SELECT c.AccountName, c.AccountuniqueNumber, c.charactername, c.uniquenumber, s.Count
FROM td_character c, (Select TOP 10 CharacterUniqueNumber, COUNT(CharacterUniqueNumber) As "Count"
		FROM atum_log_user_speed_hack
		WHERE [Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND [Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)
		GROUP BY CharacterUniqueNumber
		ORDER BY Count desc) as s
where c.uniquenumber = s.Characteruniquenumber

Select c.characterName, s.Time, s.MapIndex, s.ReceivedMoveCounts
	FROM td_character c, atum_log_user_speed_hack s 
	WHERE c.uniquenumber = s.characteruniquenumber and s.characteruniquenumber = 4341
		 and s.[Time] > CONVERT(DATETIME, '2005-01-18 00:00:00', 102) AND s.[Time] < CONVERT(DATETIME, '2005-01-25 17:00:00', 102)


-- 2005-01-14 by cmkwon, ���� ���� ����� �˻�
	-- B���
	SELECT *
	FROM td_character c, td_Store s
	where c.UnitKind = 1 and (6+(c.Level-1)*2 - c.bonusstat ) <> AttackPart/3 + DefensePart/3 + FuelPart/3 + SoulPart/3 + ShieldPart/3 + DodgePart/3
		and c.uniqueNumber = s.Possess and s.ItemWindowIndex <> 1


-- �׽�Ʈ ���� �̺�Ʈ ������ ����
-- Level 10�̻��� ĳ���� �ִ� AccountUniqueNumber�� ������ tempAccountTable �並 �����
-------------------------------------------------------------------------------------
drop view tempAccountTable
GO
create view tempAccountTable
as
select c.accountuniquenumber as accountuniquenumber 
	from td_character c
	where c.level >= 10
	group by c.accountUniqueNumber
go
select * from tempAccountTable
	order by accountuniquenumber

-- ������ ����
-- ���� �ʱ�ȭ ������				- 7009970 - 1��
-- S�� ȸ�� ���� ŰƮ				- 7010290 - 50��
-- S�� ȸ�� ���� ŰƮ				- 7010300 - 50��
-- ���λ� �⺻���� ���� �׺� ī��	- 7010280 - 5��
-- ���̻� �⺻���� ���� ���� ī��	- 7010400 - 5��
-- ���λ� ��޹��� ���� ���� ī��	- 7010410 - 5��
-- ���̻� ��޹��� ���� ���� ī��	- 7010420 - 5��
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 1, 0, 99,
				7009970, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 50, 0, 99,
				7010290, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 50, 0, 99,
				7010300, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 5, 0, 99,
				7010280, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 5, 0, 99,
				7010400, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 5, 0, 99,
				7010410, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm
INSERT INTO td_Store
		SELECT tm.accountUniqueNumber, 0, 0, 5, 0, 99,
				7010420, 0, 0, 0, 0, GetDate()
		FROM tempAccountTable tm


--------------------------------------------------------------------------------------


