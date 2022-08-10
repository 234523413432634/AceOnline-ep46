-------------------------------------------------------------------------------
-- ���� �߰�
	-- ����(��Ż���� = 1, ��ī = 2), ����(������ = 128, ���/GM = 256, ����� = 2048)
	
	-- 2005-08-19 by cmkwon, �ϳ��� ���� �߰��ϱ�
	INSERT INTO td_Account(AccountName, Password, AccountType, Sex, BirthYear, MGameEventType)
		VALUES('shkim2', '1111', 128, 0, 2005, 0)
	
	-- 2005-10-21 by cmkwon, temp_insert_account ���̺� �����
	CREATE TABLE temp_insert_account(
		AccountName			VARCHAR(20)	NOT NULL,
		Password			VARCHAR(35),						-- MD5, 32 bytes ĳ������
		type                SMALLINT
	)
	GO
	DELETE FROM temp_insert_account

	-- 2005-08-19 by cmkwon, temp_insert_account ���̺� �ִ� ����,������� ���� �߰�
	-- �Ϲ�(0), ������(128), ���(256), �����(2048)
	INSERT INTO td_Account
		SELECT tm.AccountName, tm.Password, 2048, 0, 2005,
			GetDate(), GetDate(), 0, 0, 0
		FROM temp_insert_account tm


	INSERT INTO member                   --WEB DB�� ���� �߰�
		SELECT tm.AccountName, tm.Password, NULL, NULL, NULL, NULL, NULL,
				 NULL, NULL, NULL, NULL, NULL, Getdate(), 'U' , NULL, NULL, NULL,
				 NULL, NULL, NULL, NULL, 'n'
		FROM temp_insert_account tm

	-- 2007-04-17 by cmkwon, Ư�� ��¥ ���Ŀ� ������ ĳ������ ���� ����
	SELECT AccountName, RegisteredDate
	FROM td_account
	WHERE accountname IN (SELECT accountname FROM td_character WHERE LastStartedTime > '20070401 00:00:00')

	-- 2007-04-23 by cmkwon, ��¥ �ð��� ������ ������
	SELECT CAST(DATENAME(yy, registeredDate)+'-'+DATENAME(mm, registeredDate)+'-'+DATENAME(dd, registeredDate)+' '+DATENAME(hh, registeredDate)+':00' as datetime) as datehour, count(CAST(DATENAME(yy, registeredDate)+'-'+DATENAME(mm, registeredDate)+'-'+DATENAME(dd, registeredDate)+' '+DATENAME(hh, registeredDate)+':00' as datetime))
	FROM td_account
	WHERE registeredDate > '20070420 00:00:00'
	GROUP BY CAST(DATENAME(yy, registeredDate)+'-'+DATENAME(mm, registeredDate)+'-'+DATENAME(dd, registeredDate)+' '+DATENAME(hh, registeredDate)+':00' as datetime)



-------------------------------------------------------------------------------
-- ĳ���� ����

	-- 2005-11-16 by cmkwon, ���� �ʱ�ȭ(�� 3�ܰ� - �����ʱ�ȭ, ���º����ø����� �̵�/ĳ���͸��κ���, ��� ���������� ����) 
	-- ���󺰷� �ʱ� ������ �ٸ��� �����ؾ���
	-- Unit - BGear(1), MGear(16), AGear(256), IGear(4096)
	-- �⺻����		Attack,	Defense,	Fuel,	Soul,	Shield,	Dodge
	-- Korea 
	-- Kor_Yedang
	-- Chn_Yetime
		--	BGear - 3,		3,		3,		3,		3,		3
		--	MGear - 2,		4,		3,		4,		3,		2
		--	AGear - 4,		3,		3,		3,		4,		1		2007-05-21 by cmkwon, ������(<--4,3,3,2,4,2)
		--	IGear - 4,		2,		3,		3,		2,		4
	update td_character set AttackPart = 3, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 3, DodgePart = 3, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 1)	-- BGear
	update td_character set AttackPart = 2, DefensePart = 4, FuelPart = 3, SoulPart = 4, ShieldPart = 3, DodgePart = 2, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 16)	-- MGear
	update td_character set AttackPart = 4, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 4, DodgePart = 1, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 256)	-- AGear
	update td_character set AttackPart = 4, DefensePart = 2, FuelPart = 3, SoulPart = 3, ShieldPart = 2, DodgePart = 4, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 4096)	-- IGear

	-- English, Vietnam
		--	BGear - 3,		3,		3,		3,		3,		3
		--	MGear - 2,		4,		4,		3,		3,		2
		--	AGear - 4,		3,		4,		2,		4,		1
		--	IGear - 4,		2,		3,		3,		2,		4
	update td_character set AttackPart = 3, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 3, DodgePart = 3, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 1)	-- BGear
	update td_character set AttackPart = 2, DefensePart = 4, FuelPart = 4, SoulPart = 3, ShieldPart = 3, DodgePart = 2, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 16)	-- MGear
	update td_character set AttackPart = 4, DefensePart = 3, FuelPart = 4, SoulPart = 2, ShieldPart = 4, DodgePart = 1, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 256)	-- AGear
	update td_character set AttackPart = 4, DefensePart = 2, FuelPart = 3, SoulPart = 3, ShieldPart = 2, DodgePart = 4, Bonusstat = 1*(level-1)+BonusStatPoint
		where (unitkind = 4096)	-- IGear
	
	-- ���º� ���ø����� �̵�, ĳ���� ���� ������
	-- InfluenceType - �Ϲ�(1), �������������Ա�(2), �����������ݶ���(4), ��Ż�󽺿��決(8) 
	Update td_Character set CharacterMode= 1, MapIndex= 2001, ChannelIndex= 0, Position_X= 950, Position_Y= 304, Position_Z= 4850
		where InfluenceType= 1 or InfluenceType= 2	-- �Ϲ�, ���Ա�
	Update td_Character set CharacterMode= 1, MapIndex= 2002, ChannelIndex= 0, Position_X= 1350, Position_Y= 958, Position_Z= 5175
		where InfluenceType= 4						-- �ݶ���
	

	-- 2005-12-02 by cmkwon, td_character ���̺� ĳ���Ͱ� �����ϴ� ������ ���� ���Ѵ�.
	select count(*)
		from td_account a, (select c.accountuniquenumber
							from td_character c group by c.accountuniquenumber) c
		where a.accountuniquenumber = c.accountuniquenumber
-------------------------------------------------------------------------------
-- �����̾� ����
	-- 7010120		// �Ϲ� �����̾� �����۳ѹ�
	-- 7010130		// ���� �����̾� �����۳ѹ�
		
	-- 2005-03-30 by cmkwon, ������ �ִ� ��� �������� �����̾� ������ ����, �Ⱓ ����
	INSERT INTO td_AccountCashStore
		SELECT a.accountUniqueNumber, 7010130, GetDate(), GetDate(), '20050405 23:59:00'
		FROM td_Account a

	-- 2005-08-11 by cmkwon, �����̾��� ���ᰡ ������ ���� �������� 1�� �����Ѵ�.
	Update td_AccountCashStore
	Set ExpireTime = DATEADD(dd, 1, ExpireTime)
	where ExpireTime > GetDate()
	
	-- 2005-08-11 by cmkwon
	Update td_AccountCashStore
	Set ExpireTime = '20050812 11:00:00'
	where ExpireTime >= '20050809 00:01:00' and ExpireTime <= GetDate()
	
	-- 2005-09-06 by cmkwon, �����̾� ���� �˻�	
	select a.accountName, ac.*
	from td_account a, td_AccountCashStore ac
	where a.accountuniquenumber = ac.accountuniquenumber
	order by ExpireTime
	
	-- 2005-12-26 by cmkwon, �̼Ǻ� �Ϸ� ���
	select cq.QuestIndex, COUNT(QuestIndex)
	from td_CharacterQuest cq, td_character c
	where cq.QuestState = 2 and cq.CharacterUniquenumber = c.uniquenumber
	group by cq.QuestIndex
	order by questIndex

	-- 2005-12-26 by cmkwon, ���º� ���� ������
	select level, influencetype, count(influencetype)
	from td_character
	where race = 2
	group by level, influencetype
	order by level, influencetype

	-- 2007-04-12 by cmkwon, ������ ��� ������
	SELECT level, dbo.atum_GetGearString(unitkind) AS Gear, COUNT(unitkind) AS Counts
	FROM td_character
	WHERE race < 128
	GROUP BY level, unitkind
	ORDER BY level, unitkind

-- 
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- �� ����
	
	-- 2005-08-11 by cmkwon, ��� ĳ���� �ݳ��� �̵�
	update td_character 
	set MapIndex = 1001
	
	-- 2005-08-30 by cmkwon, ti_MapInfo�� ����� �߰��ϱ� ����
	INSERT INTO ti_MapInfo
		SELECT 3308, 0, MapName, CityMapIndex, CityWarQuestIndex, CityWarQuestNPCIndex, CityWarQuestMonsterUID,
				MaxUserCount, MaxGroundHeight, MinGroundHeight, WaterHeight, UserVisibleDistance, MonsterVisibleDistance,
				QuestIndexForWarp, FrontPositionDistance, AutoRecoveryFlag, DefaultMapIndex, CityWarpTargetPositionX,
				CityWarpTargetPositionY, CityWarpTargetPositionZ, ClientMaxAltitudeHeight, DayFogColor, NightFogColor,
				DayFogStartDistance, DayFogEndDistance, NightFogStartDistance, NightFogEndDistance, DaySunDirectionX,
				DaySunDirectionY, DaySunDirectionZ, NightSunDirectionX, NightSunDirectionY, NightSunDirectionZ, WaterType,
				PKZoneFlag, TileRenderingFlag, SkyRenderingFlag, SunRenderingFlag, FogRenderingFlag
		FROM ti_MapInfo
		WHERE MapIndex = 3006
--
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- ������ ����

	-- 2005-08-11 by cmkwon, ��� ĳ���Ͱ� ������ ��� ������ �����ϱ�
	update td_store
	set Wear = 0, ItemWindowIndex = 99
	where Wear = 1
	
	-- 2005-11-26 by cmkwon, ���� ���潺 ��ȣ ��ü�� ���� ��ų ���� 
	-- 7820041 --> 7821041
	-- 7820042 --> 7821042
	-- 7820043 --> 7821043
	-- 7820044 --> 7821044
	DELETE FROM td_StoreSkill
	WHERE   (ItemNum >= 7820041) AND (ItemNum <= 7820044)


	-- 2005-12-02 by cmkwon, td_store ���̺� ĳ���� ������ SPI �������� ���� ĳ���Ϳ� ������ �߰��ϱ�
	-- td_store ���̺� ĳ���� ������ SPI �������� ���� CharacterUniqueNumber VIEW �����
	DROP VIEW VIEW_NotExistSPIItemIntd_Store
	GO
	CREATE VIEW VIEW_NotExistSPIItemIntd_Store
	AS
		select uniquenumber as CharacterUniqueNumber
			from td_character 
			where not exists (select possess from td_store where possess = td_character.uniquenumber AND ItemStorage = 0 AND itemnum = 7000022)
	GO
	
	select c.AccountName, c.CharacterName
		from td_character c, VIEW_NotExistSPIItemIntd_Store v
		where c.uniquenumber = v.CharacterUniqueNumber	

	-- td_store ���̺� ĳ���� ������ SPI ������ �߰��ϱ�
	INSERT INTO td_Store
		SELECT c.accountuniquenumber, c.uniquenumber, 0, 0, 1, 0, 99, 7000022, 0, 0, 0, 0, 0, 0, GetDate()
		from td_character c, VIEW_NotExistSPIItemIntd_Store v
		where c.uniquenumber = v.CharacterUniqueNumber


--
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- 2005-08-11 by cmkwon, ����Ÿ�� ���� �̺�Ʈ ����
	-- �� ������ DB�� temp_for_lockontarget ���̺��� �̺�Ʈ �ش� �������� AccountName�� CharacterName�� ����ִ�.
	Update td_Store
		SET CurrentCount = 1000000 + CurrentCount
		FROM td_Store s, td_character c, temp_for_lockontarget tm
		WHERE tm.AccName = c.AccountName and tm.CharName = c.CharacterName 
				and c.AccountUniqueNumber = s.AccountUniqueNumber 
				and c.UniqueNumber = s.Possess and s.ItemNum = 7000022
	
	SELECT c.AccountName, c.CharacterName
		FROM td_Store s, td_character c, temp_for_lockontarget tm
		WHERE tm.AccName = c.AccountName and tm.CharName = c.CharacterName 
				and c.AccountUniqueNumber = s.AccountUniqueNumber 
				and c.UniqueNumber = s.Possess and s.ItemNum = 7000022
		order by accountname
	
	
	SELECT accName, charName
		FROM temp_for_lockontarget
		WHERE charName not in 
		(
			SELECT c.characterName
				FROM td_Store s, td_character c, temp_for_lockontarget tm
				WHERE tm.AccName = c.AccountName and tm.CharName = c.CharacterName 
					and c.AccountUniqueNumber = s.AccountUniqueNumber 
					and c.UniqueNumber = s.Possess and s.ItemNum = 7000022
		)
-- 
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 2005-09-23 by cmkwon, ���ǵ��� ����

	-- 2005-09-23 by cmkwon, ������ �Ⱓ�� ���� ����ڸ� �˻��Ѵ�. backup log ���̺���� �ΰ� ��� �˻��ؾ��Ѵ�.
	select c.charactername, c.AccountName, l.Time, l.CheckType, l.ReceivedMoveCounts, ServerPastTime, ClientPastTime, PastDistance, CurrentSpeed
	from td_character c, atum_backup_log_user_speed_hack l
	where l.Time > '20050904 00:00:00' and l.Time < '20050912 23:59:59' and l.Characteruniquenumber = c.uniquenumber	
	order by l.time
	select c.charactername, c.AccountName, l.Time, l.CheckType, l.ReceivedMoveCounts, ServerPastTime, ClientPastTime, PastDistance, CurrentSpeed
	from td_character c, atum_log_user_speed_hack l
	where l.Time > '20050904 00:00:00' and l.Time < '20050912 23:59:59' and l.Characteruniquenumber = c.uniquenumber
	order by l.time
	
--
-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
-- 2007-12-12 by cmkwon, ���̳ʸ� IP(0xFD123456)�� �ؽ�Ʈ IP(xxx.xxx.xxx.xxx)�� �����ֱ�
	SELECT LogType, Time, CAST(CAST(substring(ipaddress, 1, 1) AS INT) AS VARCHAR(3)) + '.' + CAST(CAST(substring(ipaddress, 2, 1) AS INT) AS VARCHAR(3)) + '.' + CAST(CAST(substring(ipaddress, 3, 1) AS INT) AS VARCHAR(3)) + '.' + CAST(CAST(substring(ipaddress, 4, 1) AS INT) AS VARCHAR(3)) AS IPAddress, AccountUniqueNumber, AccountName, ServerName
	FROM atum_log_connection
--
-------------------------------------------------------------------------------


