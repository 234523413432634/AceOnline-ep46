--!!!!
-- Name: dbo.tmManager_copy_character_by_characterName
-- Desc: // 2008-03-19 by cmkwon, LoadGenerator �� ���� Character ���� ���ν��� ���� - �ӽÿ���, ������ ���� ����
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:���� �ڵ�
--									0	==> ���� ����
--									10000	=> �ҽ� ĳ���͸��� ĳ���Ͱ� ����.
--									10001	=> Ÿ�� ĳ���͸��� �̹� �����Ѵ�.
--									1002	==> Ÿ�� ������ �������� �ʴ´�.
--									10023	==> Ÿ�� �������� ĳ���� �߰��� ���� �߻���
--									10028	==> ���� ���������� ������ ������ �˻����� ����, td_Store
--									10024	==> Ÿ�� ������ td_Store���̺� ������ �߰��� ���� �߻���
--									10025	==> Ÿ�� ������ td_Enchant���̺� ������ �߰��� ���� �߻���
--									10026	==> Ÿ�� ������ td_StoreSkill���̺� ������ �߰��� ���� �߻���
--		[2] INPUT @i_SCharName	: �ҽ� ĳ���͸�
--		[3] INPUT @i_TAccName	: Ÿ�� ������
--		[3] INPUT @i_TCharName	: Ÿ�� ĳ���͸�
--====
CREATE PROCEDURE dbo.tmManager_copy_character_by_characterName
	@o_RetCode			INT OUTPUT,				-- 
	@i_SCharName		VARCHAR(20),			-- 
	@i_TAccName			VARCHAR(20),
	@i_TCharName		VARCHAR(20)				-- 
AS
	SET @o_RetCode = 0		--			0	==> ���� ����

	DECLARE @SAccUID INT
	DECLARE @SCharUID INT
	SELECT TOP 1 @SAccUID= AccountUniqueNumber, @SCharUID= UniqueNumber FROM dbo.td_Character WITH (NOLOCK) WHERE CharacterName = @i_SCharName
	IF (@SAccUID IS NULL) OR (@SCharUID IS NULL)
	BEGIN
		SET @o_RetCode = 1000	--	10000	=> �ҽ� ĳ���͸��� ĳ���Ͱ� ����.
		RETURN
	END

	IF EXISTS(SELECT * FROM dbo.td_character WITH(NOLOCK) WHERE CharacterName = @i_TCharName)
	BEGIN
		SET @o_RetCode = 1001	--	10001	=> Ÿ�� ĳ���͸��� �̹� �����Ѵ�.
		RETURN
	END
	
	DECLARE @TAccUID INT
	SET @TAccUID = (SELECT AccountUniqueNumber FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountName = @i_TAccName)
	IF (@TAccUID IS NULL)
	BEGIN
		SET @o_RetCode = 1002	--	1002	==> Ÿ�� ������ �������� �ʴ´�.
		RETURN
	END

	DECLARE @errNum INT

	BEGIN TRAN

		-- ĳ���͸� ���� �Ѵ�.
		INSERT INTO dbo.td_Character
			SELECT @i_TCharName, @i_TAccName, @TAccUID,Gender,Race,UnitKind,InfluenceType,SelectableInfluenceMask,PilotFace,
				CharacterMode,AutoStatType,AttackPart,DefensePart,FuelPart,SoulPart,ShieldPart,DodgePart,NULL,0,
				Level,Experience,DownExperience,DownSPIOnDeath,BodyCondition,Propensity,Status,PKWinPoint,PKLossPoint,Material,HP,DP,SP,EP,
				PetName,PetLevel,PetExperience,Position_X,Position_Y,Position_Z,MapIndex,ChannelIndex,MaxLevel,CurrentHP,CurrentDP,CurrentSP,
				CurrentEP,BonusStat,BonusStatPoint,0,RacingPoint,TotalPlayTime,CreatedTime,LastStartedTime,LevelUpTime,WarPoint,CumulativeWarPoint,
				ArenaWin,ArenaLose,ArenaDisConnect,PCBangTotalPlayTime,0,NULL
			FROM dbo.td_Character
			WHERE UniqueNumber = @SCharUID

		IF (@@Error <> 0)
		BEGIN 			
			SET @errNum = 10023	--	10023	==> Ÿ�� �������� ĳ���� �߰��� ���� �߻���
			GOTO GOTO_Label_ROLLBACK
		END

		DECLARE @TCharUID INT
		SET @TCharUID	= @@IDENTITY;
		
		--------------------------------------------------------------------------------
		-- â��� ĳ�����κ��� �����۰� ��æƮ(td_Store, td_Enchant)
		DECLARE @SItemUID BIGINT
		DECLARE @SItemCnt INT
		SET @SItemUID = NULL
		SET @SItemCnt = NULL
		SELECT TOP 1 @SItemUID=UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2 ORDER BY UniqueNumber
		SELECT @SItemCnt=COUNT(*) FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2

		IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
		BEGIN
			
			DECLARE @k INT
			SET @k		= 0

			WHILE (@k < @SItemCnt)
			BEGIN
				IF (@SItemUID IS NULL)
				BEGIN
					SET @errNum = 10028	--	10028	==> ���� ���������� ������ ������ �˻����� ����, td_Store
					GOTO GOTO_Label_ROLLBACK					
				END

				INSERT INTO dbo.td_Store
					SELECT @TAccUID,@TCharUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
						PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
					FROM td_Store WITH(NOLOCK)
					WHERE UniqueNumber = @SItemUID

				IF (@@Error <> 0)
				BEGIN 
					SET @errNum = 10024	--	10024	==> Ÿ�� ������ td_Store���̺� ������ �߰��� ���� �߻���
					GOTO GOTO_Label_ROLLBACK
				END

				DECLARE @TItemUID BIGINT
				SET @TItemUID	= @@IDENTITY;

				--------------------------------------------------------------------------------
				-- ��æƮ�� �����ϴ� �������� Ÿ�� �������� ��æƮ �߰�
				IF EXISTS(SELECT * FROM td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
				BEGIN
					INSERT INTO dbo.td_Enchant
						SELECT @TItemUID, TargetItemNum, EnchantItemNum
						FROM td_Enchant WITH(NOLOCK)
						WHERE TargetItemUniqueNumber = @SItemUID

					IF (@@ERROR <> 0)
					BEGIN
						SET @errNum = 10025	--	10025	==> Ÿ�� ������ td_Enchant���̺� ������ �߰��� ���� �߻���
						GOTO GOTO_Label_ROLLBACK
					END
				END

				--------------------------------------------------------------------------------
				-- ���� �������� UID�� �˻��Ѵ�.
				SELECT TOP 1 @SItemUID= UniqueNumber FROM td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SAccUID AND Possess = @SCharUID AND ItemStorage <> 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
				
				SET @k			= @k +1
			END -- END - WHILE (@k < @SItemCnt)

		END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


		--------------------------------------------------------------------------------
		-- ��ų(td_StoreSkill)
		IF EXISTS(SELECT * FROM td_StoreSkill WITH(NOLOCK) WHERE Possess = @SCharUID)
		BEGIN
			INSERT INTO dbo.td_StoreSkill
				SELECT AccountUniqueNumber, @TCharUID, ItemWindowIndex, ItemNum, CreatedTime, UseTime
				FROM td_StoreSkill WITH(NOLOCK)
				WHERE Possess = @SCharUID
			IF (@@ERROR <> 0)
			BEGIN
				SET @errNum = 10026	--	10026	==> Ÿ�� ������ td_StoreSkill���̺� ������ �߰��� ���� �߻���
				GOTO GOTO_Label_ROLLBACK
			END
		END


		--------------------------------------------------------------------------------
		-- ����Ʈ(td_CharacterQuest)�� �������� �ʴ´�.
		--------------------------------------------------------------------------------
		-- Ʃ�丮��(td_TutorialComplete)�� �������� �ʴ´�.
	COMMIT TRAN

	SET @o_RetCode = 0		--			0	==> ���� ����

	RETURN 

	--------------------------------------------------------------------------------
	--
	GOTO_Label_ROLLBACK:
		ROLLBACK TRAN
		SET @o_RetCode = @errNum
		RETURN
GO