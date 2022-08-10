--!!!!
-- Name: �ش� �������� ĳ���͸� �ҽ����� ���������� �̵��Ѵ�.
-- Desc:
--			2007-01-25, #define ITEM_IN_CHARACTER				0	// ĳ�����κ�
--						#define ITEM_IN_STORE					1	// â��
--						#define ITEM_IN_GUILD_STORE             2   // 2006-09-14 by dhjin, ���� â�� 
--			
-- parameter:
--		[1]	OUTPUT @o_RetCode:���� �ڵ�
--									0	==> ���� ����
--									20	==> SourceGuildName ������ ����
--									21	==> TargetGuildName ������ ����
--									22	==> ���� ���������� ĳ���� ������ �˻����� ����, ĳ����
--									23	==> Ÿ�� �������� ĳ���� �߰��� ���� �߻���
--									24	==> Ÿ�� ������ td_Store���̺� ������ �߰��� ���� �߻���
--									25	==> Ÿ�� ������ td_Enchant���̺� ������ �߰��� ���� �߻���
--									26	==> Ÿ�� ������ td_StoreSkill���̺� ������ �߰��� ���� �߻���
--									27	==> Ÿ�� ������ td_CharacterQuest���̺� ������ �߰��� ���� �߻���
--									28	==> ���� ���������� ������ ������ �˻����� ����, td_Store
--		[2] INPUT @i_AccName: ����� ����
--		[3] INPUT @i_DBNumber:
--====
CREATE PROCEDURE dbo.integration_guildItem_move_to_atum2_db_5
	@o_RetCode			INT OUTPUT,				-- 2007-01-29 by cmkwon
	@i_SGuildName		VARCHAR(30),			-- SourceGuildName
	@i_TGuildName		VARCHAR(30)				-- TargetGuildName
AS
	SET @o_RetCode = 0		--			0	==> ���� ����

	DECLARE @SGuildUID INT
	SET @SGuildUID = (SELECT GuildUniqueNumber FROM dbo.td_Guild WITH (NOLOCK) WHERE GuildName = @i_SGuildName)
	IF (@SGuildUID IS NULL)
	BEGIN
		SET @o_RetCode = 20	--			20	==> SourceGuildName ������ ����
		RETURN
	END
	
	DECLARE @TGuildUID INT
	SET @TGuildUID = (SELECT GuildUniqueNumber FROM atum2_db_5.dbo.td_Guild WITH (NOLOCK) WHERE GuildName = @i_TGuildName)
	IF (@TGuildUID IS NULL)
	BEGIN
		SET @o_RetCode = 21	--			21	==> TargetGuildName ������ ����
		RETURN
	END

	DECLARE @errNum INT

	--------------------------------------------------------------------------------
	--------------------------------------------------------------------------------
	BEGIN TRAN

	--------------------------------------------------------------------------------
	-- ����â��� �ش� �������� ��æƮ(td_Store, td_Enchant)�� �о�ֱ� �Ѵ�.
	DECLARE @SItemUID BIGINT
	DECLARE @SItemCnt INT
	SET @SItemUID = NULL
	SET @SItemCnt = NULL
	SELECT @SItemCnt=COUNT(*) FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2
	SELECT TOP 1 @SItemUID=UniqueNumber FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2 ORDER BY UniqueNumber

	IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)
	BEGIN
		
		DECLARE @k INT
		SET @k		= 0

		WHILE (@k < @SItemCnt)
		BEGIN
			IF (@SItemUID IS NULL)
			BEGIN
				SET @errNum = 28	--			28	==> ���� ���������� ������ ������ �˻����� ����, td_Store
				GOTO GOTO_Label_ROLLBACK					
			END

			INSERT INTO atum2_db_5.dbo.td_Store
				SELECT @TGuildUID, @TGuildUID,ItemStorage,Wear,CurrentCount,ScarcityNumber,ItemWindowIndex,ItemNum,NumOfEnchants,
					PrefixCodeNum,SuffixCodeNum,CurrentEndurance,ColorCode,UsingTimeStamp,CreatedTime
				FROM dbo.td_Store WITH(NOLOCK)
				WHERE UniqueNumber = @SItemUID

			IF (@@Error <> 0)
			BEGIN 
				SET @errNum = 24	--			24	==> Ÿ�� ������ td_Store���̺� ������ �߰��� ���� �߻���
				GOTO GOTO_Label_ROLLBACK
			END

			DECLARE @TItemUID BIGINT
			SET @TItemUID	= @@IDENTITY;

			--------------------------------------------------------------------------------
			-- ��æƮ�� �����ϴ� �������� Ÿ�� �������� ��æƮ �߰�
			IF EXISTS(SELECT * FROM dbo.td_Enchant WITH(NOLOCK) WHERE TargetItemUniqueNumber = @SItemUID)
			BEGIN
				INSERT INTO atum2_db_5.dbo.td_Enchant
					SELECT @TItemUID, TargetItemNum, EnchantItemNum
					FROM dbo.td_Enchant WITH(NOLOCK)
					WHERE TargetItemUniqueNumber = @SItemUID

				IF (@@ERROR <> 0)
				BEGIN
					SET @errNum = 25	--			25	==> Ÿ�� ������ td_Enchant���̺� ������ �߰��� ���� �߻���
					GOTO GOTO_Label_ROLLBACK
				END
			END

			--------------------------------------------------------------------------------
			-- ���� �������� UID�� �˻��Ѵ�.
			SELECT TOP 1 @SItemUID= UniqueNumber FROM dbo.td_Store WITH (NOLOCK) WHERE AccountUniqueNumber = @SGuildUID AND Possess = @SGuildUID AND ItemStorage = 2 AND UniqueNumber > @SItemUID ORDER BY UniqueNumber
			
			SET @k			= @k +1
		END -- END - WHILE (@k < @SItemCnt)

	END -- END - IF (@SItemUID IS NOT NULL) AND (@SItemCnt IS NOT NULL) AND (@SItemCnt > 0)


		
	COMMIT TRAN
	--------------------------------------------------------------------------------
	--------------------------------------------------------------------------------

	SET @o_RetCode = 0		--			0	==> ���� ����

	RETURN 

	--------------------------------------------------------------------------------
	--
	GOTO_Label_ROLLBACK:
		ROLLBACK TRAN
		SET @o_RetCode = @errNum
		RETURN

GO