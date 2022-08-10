
-- 
-- ��ȸ���� db�� atum2_db_20�� ����Ѵ�.

--!!!!
-- Name: jamboree_init_jamboree_db
-- Desc: ��ȸ���� �׷�� ���ν����� DB�� ĳ���͸� �����ϱ� ���� ���ν����̴�
--		 ���, �������� ĳ���͸� ������ ��� ĳ���Ϳ� ĳ���� ���� �����Ͱ� ������
--
--		#define RACE_OPERATION				(USHORT)0x0080	// ������, 128
--		#define RACE_GAMEMASTER				(USHORT)0x0100	// ���Ӹ�����, 256

-- warning:	������ ������ ���¿��� ó���Ǿ�� ��
--			
-- input:
-- output:
--====
CREATE PROCEDURE dbo.jamboree_init_jamboree_db	
AS
	-- 1. ĳ���� ���� �������� ��æƮ ����	
	DELETE atum2_db_20.dbo.td_Enchant FROM td_Enchant e, td_Store s 
	WHERE s.AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND s.Possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND s.UniqueNumber = e.TargetItemUniqueNumber

	-- 2. ĳ���� ���� ������ ����
	DELETE FROM atum2_db_20.dbo.td_Store WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 3. ĳ���� �� ���� ����
	DELETE FROM atum2_db_20.dbo.td_QuickSlot WHERE AccountUID IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND CharacterUID IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 4. ĳ���� ���� ��ų ����
	DELETE FROM atum2_db_20.dbo.td_StoreSkill WHERE AccountUniqueNumber IN 
	(SELECT AccountUniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) AND possess IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 5. ����Ʈ ���̺��� ����
	DELETE FROM atum2_db_20.dbo.td_CharacterQuest WHERE CharacterUniqueNumber IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- 6. ģ������Ʈ���� ����
	DELETE FROM atum2_db_20.dbo.td_FriendList WHERE CharacterName IN 
	(SELECT CharacterName FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180) OR FriendName IN 
	(SELECT CharacterName FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- last ĳ���� ���̺��� ����
	DELETE FROM atum2_db_20.dbo.td_Character WHERE UniqueNumber IN 
	(SELECT UniqueNumber FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE 0 = Race & 0x180)

	-- ��� ���, ������ ĳ������ ���� �ʱ�ȭ��
	UPDATE atum2_db_20.dbo.td_character
	SET GuildName = '', GuildUniqueNumber = 0

	-- ��� ���� �ʱ�ȭ��, ��ȸ���� �ʱ�ȭ�� ��� ���� ������
	TRUNCATE TABLE atum2_db_20.dbo.td_GuildMember
	TRUNCATE TABLE atum2_db_20.dbo.td_Guild
GO


--!!!!
-- Name: jamboree_copy_character_to_jamboree_db
-- Desc: ��ȸ���� �׷�� ���ν����� DB�� ĳ���͸� �����ϱ� ���� ���ν����̴�
--		 ���, �����ڸ� ������ ��� ĳ���Ϳ� ĳ���� ������ �����͸� �����Ѵ�.
--
--			2007-01-25, #define ITEM_IN_CHARACTER				0	// ĳ�����κ�
--						#define ITEM_IN_STORE					1	// â��
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:���� �ڵ�
--									0	==> ���� ����
--									20	==> �ش� ������ ĳ���Ͱ� ����
--									21	==> �����Ϸ��� �������� �ش� ������ ĳ���Ͱ� �����Ѵ�.
--									22	==> ���� ���������� ĳ���� ������ �˻����� ����, ĳ����
--									23	==> Ÿ�� �������� ĳ���� �߰��� ���� �߻���
--									24	==> Ÿ�� ������ td_Store���̺� ������ �߰��� ���� �߻���
--									25	==> Ÿ�� ������ td_Enchant���̺� ������ �߰��� ���� �߻���
--									26	==> Ÿ�� ������ td_StoreSkill���̺� ������ �߰��� ���� �߻���
--									27	==> Ÿ�� ������ td_CharacterQuest���̺� ������ �߰��� ���� �߻���
--									28	==> ���� ���������� ������ ������ �˻����� ����, td_Store
--									29	==> // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - Ÿ�� ������ DB �� ĳ���Ͱ� �̹� 3�� �̻� �����Ѵ�.
--									30	==> // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - Ÿ�� ������ DB �� ���� ĳ���͸��� �����Ѵ�.
--		[2] INPUT @i_CharName: ĳ���͸�
--		[3] INPUT i_PreAddString2CharacterName: ĳ���͸�տ� ���� �߰� ��Ʈ��
--									ex> '1_', '2_', '3_',....
--====
CREATE PROCEDURE dbo.jamboree_copy_character_to_jamboree_db
	@o_RetCode						INT OUTPUT,
	@i_CharName						VARCHAR(20),
	@i_PreAddString2CharacterName	VARCHAR(5)
AS
	SET @o_RetCode = 0		--			0	==> ���� ����

	DECLARE @AccountUID INT
	DECLARE @SCharUID INT
	SELECT TOP 1 @AccountUID=AccountUniqueNumber, @SCharUID=UniqueNumber FROM td_Character WITH (NOLOCK) WHERE CharacterName = @i_CharName ORDER BY UniqueNumber
	IF (@AccountUID IS NULL) OR (@SCharUID IS NULL)
	BEGIN
		SET @o_RetCode = 20		--			20	==> �ش� ������ ĳ���Ͱ� ����
		RETURN
	END

-- // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - �ϳ��� ������ ������ ĳ���͸� ���� �� �� �ֵ��� �ϱ� ���� üũ ��ƾ �Ʒ��� ���� ���� ��	
--	IF Exists(SELECT * FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID)
--	BEGIN 
--		SET @o_RetCode = 21		--			21	==> ��ȸ���� ������(atum2_db_20)�� �ش� ������ ĳ���Ͱ� �����Ѵ�.
--		RETURN
--	END
	DECLARE @CharacterCnts INT	
	SET @CharacterCnts = (SELECT COUNT(*) FROM atum2_db_20.dbo.td_Character WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID)
	IF (@CharacterCnts IS NOT NULL) AND (3 <= @CharacterCnts)
	BEGIN 
		SET @o_RetCode = 29		--			29	==> // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - Ÿ�� ������ DB�� ĳ���Ͱ� �̹� 3�� �̻� �����Ѵ�.
		RETURN
	END

	DECLARE @TCharName VARCHAR(20)
	SET @TCharName			= NULL
	SELECT TOP 1 @TCharName=CharacterName 
	FROM atum2_db_20.dbo.td_Character WITH(NOLOCK) WHERE CharacterName = @i_PreAddString2CharacterName + @i_CharName

	IF (@TCharName IS NOT NULL)
	BEGIN
		-- // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - �Ʒ��� ���� ���� �ڵ带 ���� ��
		--SET @TCharName = @i_PreAddString2CharacterName + '#' + @i_CharName
		SET @o_RetCode = 30		--			30	==> // 2007-11-05 by cmkwon, ��ȸ ���� ĳ���� ���� �ý��� ���� - Ÿ�� ������ DB �� ���� ĳ���͸��� �����Ѵ�.
		RETURN
	END
	ELSE
	BEGIN
		SET @TCharName = @i_PreAddString2CharacterName + @i_CharName
	END
	
	--------------------------------------------------------------------------------
	-- ĳ�����߰�(td_character)
	INSERT INTO atum2_db_20.dbo.td_Character
		SELECT @TCharName,AccountName,AccountUniqueNumber,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,
			CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,NULL,0,
			Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint,PKLossPoint,Material,HP,DP,SP,EP,
			PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,
			CurrentEP,BonusStat,BonusStatPoint,0,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime,WarPoint,CumulativeWarPoint,
			ArenaWin,ArenaLose,ArenaDisConnect,PCBangTotalPlayTime,0 	--// 2008-06-20 by dhjin, EP3 ���������ɼ� -		-- 20070712 �Ʒ��� ���� �� PC�� �÷��̽ð� �߰�
		FROM td_Character WITH(NOLOCK)
		WHERE UniqueNumber = @SCharUID

	IF (@@Error <> 0)
	BEGIN 			
		SET @o_RetCode = 23	--			23	==> ��ȸ���� ������(atum2_db_20)�� ĳ���� �߰��� ���� �߻���
		RETURN
	END

	DECLARE @TCharUID INT
	SET @TCharUID	= @@IDENTITY;
	
	--------------------------------------------------------------------------------
	-- â��� ĳ�����κ��� �����۰� ��æƮ(td_Store, td_Enchant)
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL
	SELECT TOP 1 @SItemUID=UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2 ORDER BY UniqueNumber
	SELECT @SItemCnt=COUNT(*) FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2

	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			IF (@SItemUID IS NULL)
			BEGIN
				SET @o_RetCode = 28	--			28	==> ���� ���������� ������ ������ �˻����� ����, td_Store
				RETURN
			END

			INSERT INTO atum2_db_20.dbo.td_Store
				SELECT AccountUniqueNumber,@TCharUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
					PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
				FROM td_Store WITH(NOLOCK)
				WHERE UniqueNumber = @SItemUID

			IF (@@Error <> 0)
			BEGIN 
				SET @o_RetCode = 28	--			24	==> ��ȸ���� ������(atum2_db_20) td_Store���̺� ������ �߰��� ���� �߻���
				RETURN
			END

			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- ��æƮ�� �����ϴ� �������� ��ȸ���� ������(atum2_db_20)�� ��æƮ �߰�
			IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_20.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @o_RetCode = 25	--			25	==> ��ȸ���� ������(atum2_db_20) td_Enchant���̺� ������ �߰��� ���� �߻���
					RETURN
				END
			END

			--------------------------------------------------------------------------------
			-- ���� �������� UID�� �˻��Ѵ�.
			SELECT TOP 1 @SItemUID= UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @AccountUID AND Possess = @SCharUID AND ItemStorage <> 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


	--------------------------------------------------------------------------------
	-- ��ų(td_StoreSkill)
	IF EXISTS(SELECT * FROM td_StoreSkill WITH(NOLOCK) WHERE Possess = @SCharUID)
	BEGIN
		INSERT INTO atum2_db_20.dbo.td_StoreSkill
			SELECT AccountUniqueNumber, @TCharUID, ItemWindowIndex, ItemNum, CreatedTime, UseTime
			FROM td_StoreSkill WITH(NOLOCK)
			WHERE Possess = @SCharUID
		IF (@@ERROR <> 0)
		BEGIN
			SET @o_RetCode = 26	--			26	==> ��ȸ���� ������(atum2_db_20) td_StoreSkill���̺� ������ �߰��� ���� �߻���
			RETURN
		END
	END


	--------------------------------------------------------------------------------
	-- ����Ʈ(td_CharacterQuest)
	IF EXISTS(SELECT * FROM td_CharacterQuest WITH(NOLOCK) WHERE CharacterUniqueNumber = @SCharUID)
	BEGIN
		INSERT INTO atum2_db_20.dbo.td_CharacterQuest
			SELECT @TCharUID, QuestIndex, QuestState, QuestParam1, QuestTimeStamp, QuestPlayTimeStamp
			FROM td_CharacterQuest WITH(NOLOCK)
			WHERE CharacterUniqueNumber = @SCharUID
		IF (@@ERROR <> 0)
		BEGIN
			SET @o_RetCode = 27	--			27	==> ��ȸ���� ������(atum2_db_20) td_CharacterQuest���̺� ������ �߰��� ���� �߻���
			RETURN
		END
	END
	
	SET @o_RetCode = 0		--			0	==> ���� ����
	RETURN 
GO




