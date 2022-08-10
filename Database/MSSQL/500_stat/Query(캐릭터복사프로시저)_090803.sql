-- !!!!
-- Name:
-- Desc:
--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
-- ====
CREATE PROCEDURE dbo.atum_CreateCharacterBulk
	@CharacterName		VARCHAR(20)
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS

	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @CharacterName, @CharacterName, a.AccountUniqueNumber, Gender, 2,
				UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
				SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
				Level, Experience, 0, 0, BodyCondition, Propensity, Status,
				PKWinPoint, PKLossPoint, Material, HP, DP,
				SP, EP, PetName, PetLevel, PetExperience,
				Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
				MaxLevel, currentHP, currentDP, currentSP, currentEP,
				200, 200, 0, 0, 0, GetDate(), NULL,GetDate()
		FROM atum2_db_account.dbo.td_account a, td_Character c
		WHERE c.charactername = '���ݸ���' AND a.AccountName = @CharacterName
		-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
		-- WHERE c.charactername LIKE '���ݸ���' AND a.AccountName LIKE @CharacterName

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername = @CharacterName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @uniquenumber = (SELECT uniquenumber FROM td_Character WHERE charactername LIKE @CharacterName)
	IF (@uniquenumber IS NOT NULL)
	BEGIN
		-- ���� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 07000070, 1, 1, 2
		-- ���� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6
		-- �� ����
		EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 0

	END
GO


--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_I
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'I���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002570, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8013100, 1, 1, 5		-- �Ƹ� - ���δ� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO


--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_A
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'A���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000050, 1000, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900440, 300, 1, 4			-- 2�� ���� - ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002590, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7011500, 1, 1, 0		-- ��Ű ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8012100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO


--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_B
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'B���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001230, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8010100, 1, 1, 5		-- �Ƹ� - ���� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO


--		2006-04-11 by cmkwon, td_Character ���̺� DownSPIOnDeath �ʵ� �߰�
--		2007-01-24 by cmkwon, ���ν��� �뵵 ���� - 'M���' ĳ���͸� ������ ĳ���͸� �߰��ϴ� ���ν���
CREATE PROCEDURE dbo.atum_CreateCharacterBulk_M
	@i_AccName		VARCHAR(20),		-- ���� ����
	@i_CharName		VARCHAR(20)			-- ���� ĳ���͸�
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
	DECLARE @AccUID INT
	SET @AccUID = (select AccountUniqueNumber from atum2_db_account.dbo.td_account WITH(NOLOCK) where AccountName = @i_AccName)
	IF @AccUID IS NULL
		RETURN

	-- // 2009-02-12 by cmkwon, EP3-3 ���巩ŷ�ý��� ���� - NickName �ʵ尡 �߰��Ǿ����� �ʵ��÷� ���ڸ� �߰� �� �ʿ� ����.
	INSERT INTO td_Character(CharacterName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,GuildName,GuildUniqueNumber,Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint
							,PKLossPoint,Material,HP,DP,SP,EP,PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,CurrentEP,BonusStat,BonusStatPoint
							,LastPartyID,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime)
		SELECT @i_CharName, @i_AccName, @AccUID, Gender, 2,
					UnitKind, InfluenceType, SelectableInfluenceMask, PilotFace, 0, 0, AttackPart, DefensePart, FuelPart,
					SoulPart, ShieldPart, DodgePart, GuildName, GuildUniqueNumber,
					Level, Experience, 0, 0, BodyCondition, Propensity, Status,
					PKWinPoint, PKLossPoint, Material, HP, DP,
					SP, EP, PetName, PetLevel, PetExperience,
					Position_X, Position_Y, Position_Z, MapIndex, ChannelIndex,
					MaxLevel, currentHP, currentDP, currentSP, currentEP,
					200, 200, 0, 0, 0, GetDate(), NULL, GetDate()
		FROM td_Character
		WHERE CharacterName = 'M���'

	-- �⺻ ������ ����
	DECLARE @uniquenumber INT
	SET @uniquenumber = (select uniquenumber from td_Character where charactername = @i_CharName)
	-- // 2009-01-29 by cmkwon, ���ڿ� ���� �˻��� �ʿ���� LIKE ����� ���� - 
	-- SET @uniquenumber = (select uniquenumber from td_Character where charactername like @i_CharName)
	IF (@uniquenumber IS NULL)
		RETURN

	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7001950, 1500, 1, 2		-- 1�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7900000, 150, 1, 4		-- 2�� ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7002580, 1, 1, 6			-- ����
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 7000970, 1, 1, 0		-- �⺻ ���̴�
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @uniquenumber, 8011100, 1, 1, 5		-- �Ƹ� - ����� 2005-12-03 by cmkwon
	EXEC dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum @uniquenumber, 7000022, 20000000					-- �� ����

GO
