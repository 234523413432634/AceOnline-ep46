-------------------------------------------------------------------------------
-- 1. 신규 회원 관련
-------------------------------------------------------------------------------
-- 1.1 날짜별 가입 인원		
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

-- 1.2 잠정 탈퇴 회원 수(2주 이상 접속 로그가 없는 유저)
	-- 구현 안됨
	
-- 1.3 1일 탈퇴 회원수
	-- 알수 없음
	-- 계정 삭제 처리가 안되는것 같음
	
-- 1.4 
	-- 구현 안됨

-- 1.5 날짜별 동접 변동 추이
	select time, clientcount
	from atum_log_server_map
	where mapindex = 0 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59'
	order by time desc
	GO
--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 2. 총 누적 회원 현황 수
-------------------------------------------------------------------------------
-- 2.1 현재 누적 회원수
	SELECT TOP 1 (AccountUniqueNumber) AS '총 누적 회원수'
		FROM td_Account
		ORDER BY AccountUniqueNumber DESC

-- 2.2 현재 회원수
	SELECT COUNT(*) AS '현재 총 회원수'
		FROM td_Account

-- 2.3 현재 탈퇴 회원수	
	DECLARE @AccTotal INT
	SET @AccTotal = (SELECT TOP 1 (AccountUniqueNumber) FROM td_Account ORDER BY AccountUniqueNumber DESC)
	SELECT (@AccTotal - COUNT(*)) AS '탈퇴 회원수'
		FROM td_Account

-- 2.4 현재 잠정 회원수
	-- 미 구현
--
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-- 3. 날짜, 시간별 통계 동시 접속자 수 통계
-------------------------------------------------------------------------------
-- 3.1 날짜별 동접 변동 추이 - 지정한 날짜 사이의
	select time, clientcount
	from atum_log_server_map
	where mapindex = 0 and time > '2004-12-22 16:00' and time < '2004-12-31 23:59'
	order by time desc
	GO

-- 3.2 날짜별 최고, 평균 동접수 - 지정한 날짜 사이의
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

-- 3.3 동접수
	select time, clientcount
	from user_count_timeline
	order by time desc

-- 3.4 날짜&시간별 최고, 평균 동접수
	select datehour, max(clientcount) as maxcount, min(clientcount) as mincount, avg(clientcount) as avgcount
	from user_count_timeline
	group by datehour
	order by datehour desc

-- 3.5 날짜별 최고, 평균 동접수
	select date, max(clientcount) as maxcount, avg(clientcount) as avgcount, min(clientcount) as mincount
	from user_count_timeline
	group by date
	order by date

-- 3.6 시간별 최고, 평균 동접수
	select hour, max(clientcount) as maxcount,avg(clientcount) as avgcount
	from user_count_timeline
	group by hour
	order by hour
--
-------------------------------------------------------------------------------




-------------------------------------------------------------------------------
-- 4. 기어별 레벨 분포도
-------------------------------------------------------------------------------
-- 4.1 레벨 및 유닛 별 기어 수 - 지정한 날짜이후 접속했던 유저중에 검색
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
-- 5. 캐쉬 아이템 판매 현황
-------------------------------------------------------------------------------



--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 6. 일반 아이템 소유 현황
-------------------------------------------------------------------------------
-- 6.1 돈 많은 순서 상위 300명, 운영자 제외
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

--6.2 레벨별 유닛 평균 소유 돈의 양
	-- 미구현

--6.3 레벨별 유닛 레어 아이템 평균 개수
	-- 미구현

--6.4 레벨별 유닛 인챈트 아이템 평균 개수
	-- 미구현

--6.5 레벨별 유닛 인첸트 카드 평균 개수
	-- 미구현

--6.6 서버별 멀티넘, 샷넘 아이템 개수
	-- 미구현

--6.7 레벨별 유닛 평균 미션 클리어 개수
	-- 미구현

--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 7. 1:1 전투관련 통계
-------------------------------------------------------------------------------
-- 7.1 날짜별 1:1 전투 횟수
	select date, count(*)
	from (select time, atum.atum_getonlydate(time) as date
			from atum_log_user_quest_pk_dead l
			where logtype = 22 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59') ll
	group by date
	order by date

-- 7.2 1:1 결투 승리 로그 리스트	
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where logtype = 22 and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
	order by time
	
-- 7.3 1:1 결투 승리, 패배 로그 리스트	
	select time, c1.charactername, c1.level,  c2.charactername, c2.level, l.mapindex, atum.atum_getonlydate(time)
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and l.param1 = c2.uniquenumber
	order by time
	
-- 7.4 캐릭터별 1:1 전투 회수
	select c1.charactername, (select level from atum.td_character where charactername = c1.charactername) as level, count(*) as count
	from atum.atum_log_user_quest_pk_dead l, atum.td_character c1, atum.td_character c2
	where (logtype = 22 or logtype = 23) and time > '2004-12-22 16:00' and time < '2005-12-31 23:59' and l.characteruniquenumber = c1.uniquenumber and c1.uniquenumber = c2.uniquenumber
	group by c1.charactername
	order by count desc

--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 8. 미션 관련
-------------------------------------------------------------------------------
-- 8.1 날짜별 미션 이용수
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
-- 9. 접속자 계정 수
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