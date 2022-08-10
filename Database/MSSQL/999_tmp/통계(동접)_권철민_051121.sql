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
	where mapindex = 0 and time > '2005-11-14 19:00:00' and time < '2005-11-15 19:00:00'
	group by time
	go

	--1. �ְ� ���� �� �ð�
	select TOP 1 time, clientCount
	from user_count_timeline
	order by clientcount desc

	--2. ���� �� ȸ����, �ű� ȸ����
	declare @Yesterday datetime
	declare @Today datetime
	set @Yesterday = '2005-11-14 19:00:00'
	set @Today = DATEADD(dd, 1, @Yesterday);

	SELECT COUNT(*) AS '���� �� ȸ����'
		FROM td_Account
		where registeredDate < @Today

	SELECT COUNT(*) AS '�ű� ȸ����'
		FROM td_Account
		where registeredDate > @Yesterday and registeredDate < @Today