-------------------------------------------------------------------------------
-- 1. �ű� ȸ�� ����
-------------------------------------------------------------------------------
-- 1.1 ��¥�� ���� �ο�		
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

-- 1.2 ���� Ż�� ȸ�� ��(2�� �̻� ���� �αװ� ���� ����)
	-- ���� �ȵ�
	
-- 1.3 1�� Ż�� ȸ����
	-- �˼� ����
	-- ���� ���� ó���� �ȵǴ°� ����
	
-- 1.4 
	-- ���� �ȵ�

-- 1.5 ��¥�� ���� ���� ����
	select time, clientcount
	from atum_log_server_map
	where mapindex = 0 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59'
	order by time desc
	GO
--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 2. �� ���� ȸ�� ��Ȳ ��
-------------------------------------------------------------------------------
-- 2.1 ���� ���� ȸ����
	SELECT TOP 1 (AccountUniqueNumber) AS '�� ���� ȸ����'
		FROM td_Account
		ORDER BY AccountUniqueNumber DESC

-- 2.2 ���� ȸ����
	SELECT COUNT(*) AS '���� �� ȸ����'
		FROM td_Account

-- 2.3 ���� Ż�� ȸ����	
	DECLARE @AccTotal INT
	SET @AccTotal = (SELECT TOP 1 (AccountUniqueNumber) FROM td_Account ORDER BY AccountUniqueNumber DESC)
	SELECT (@AccTotal - COUNT(*)) AS 'Ż�� ȸ����'
		FROM td_Account

-- 2.4 ���� ���� ȸ����
	-- �� ����
--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 3. ��¥, �ð��� ��� ���� ������ �� ���
-------------------------------------------------------------------------------
-- 3.1 ��¥�� ���� ���� ���� - ������ ��¥ ������
	select time, clientcount
	from atum_log_server_map
	where mapindex = 0 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
	order by time desc
	GO

-- 3.2 ��¥�� �ְ�, ��� ������ - ������ ��¥ ������
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
	where mapindex = 0 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59'
	group by time
	go

-- 3.3 ������
	select time, clientcount
	from user_count_timeline
	order by time desc

-- 3.4 ��¥&�ð��� �ְ�, ��� ������
	select datehour, max(clientcount) as maxcount, min(clientcount) as mincount, avg(clientcount) as avgcount
	from user_count_timeline
	group by datehour
	order by datehour desc

-- 3.5 ��¥�� �ְ�, ��� ������
	select date, max(clientcount) as maxcount, avg(clientcount) as avgcount, min(clientcount) as mincount
	from user_count_timeline
	group by date
	order by date

-- 3.6 �ð��� �ְ�, ��� ������
	select hour, max(clientcount) as maxcount,avg(clientcount) as avgcount
	from user_count_timeline
	group by hour
	order by hour
--
-------------------------------------------------------------------------------




-------------------------------------------------------------------------------
-- 4. �� ���� ������
-------------------------------------------------------------------------------
-- 4.1 ���� �� ���� �� ��� �� - ������ ��¥���� �����ߴ� �����߿� �˻�
	drop view LevelUnit
	go
	CREATE view LevelUnit
	as
	select accountname, charactername, level, (level-1)/5*5+5 as slevel, atum.atum_GetGearString(c.unitkind) as unit
	from atum.td_character c
	where race < 128 charactername not like 'loadtest%' and laststartedtime > '2004-12-22 16:00'
	go


	select slevel, unit, count(*) as count
	from levelunit
	group by slevel, unit
	order by slevel, unit

--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 5. ĳ�� ������ �Ǹ� ��Ȳ
-------------------------------------------------------------------------------



--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 6. �Ϲ� ������ ���� ��Ȳ
-------------------------------------------------------------------------------
-- 6.1 �� ���� ���� ���� 300��, ��� ����
	drop view MoneyItemTable
	go
	create view MoneyItemTable
	as
		select top 300 *
		from td_store
		where itemnum=7000022
		order by currentcount desc
	GO

	select m.possess, m.accountuniquenumber, m.currentcount, c.charactername, c.AccountName, c.level
	from MoneyItemTable m, td_character c
	where c.uniquenumber = m.possess and c.race < 128
	order by m.currentcount desc

--6.2 ������ ���� ��� ���� ���� ��
	-- �̱���

--6.3 ������ ���� ���� ������ ��� ����
	-- �̱���

--6.4 ������ ���� ��æƮ ������ ��� ����
	-- �̱���

--6.5 ������ ���� ��þƮ ī�� ��� ����
	-- �̱���

--6.6 ������ ��Ƽ��, ���� ������ ����
	-- �̱���

--6.7 ������ ���� ��� �̼� Ŭ���� ����
	-- �̱���

--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 7. 1:1 �������� ���
-------------------------------------------------------------------------------
-- 7.1 ��¥�� 1:1 ���� Ƚ��
	select date, count(*)
	from (select time, atum.atum_getonlydate(time) as date
			from atum_log_user_quest_pk_dead l
			where logtype = 22 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59') ll
	group by date
	order by date

-- 7.2 1:1 ���� �¸� �α� ����Ʈ	
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where logtype = 22 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
	order by time
	
-- 7.3 1:1 ���� �¸�, �й� �α� ����Ʈ	
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
	order by time
	
-- 7.4 ĳ���ͺ� 1:1 ���� ȸ��
	select c1.charactername, (select level from atum.td_character where charactername = c1.charactername) as level, count(*) as count
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber
	group by c1.charactername
	order by count desc

--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 8. �̼� ����
-------------------------------------------------------------------------------
-- 8.1 ��¥�� �̼� �̿��
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

--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 9. ������ ���� ��
-------------------------------------------------------------------------------
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

--
-------------------------------------------------------------------------------