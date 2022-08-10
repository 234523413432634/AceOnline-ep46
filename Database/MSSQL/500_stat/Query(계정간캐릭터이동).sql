

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: 
-- DESC				: // 2009-07-29 by cmkwon, 계정간 캐릭터 이동 프로시저 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_moveCharacter
	@i_SourceCharacterUID		INT,
	@i_TargetAccountUID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	
	DECLARE @SourAccUID INT
	DECLARE @SourCharInflTy TINYINT

	SELECT @SourAccUID= AccountUniqueNumber, @SourCharInflTy= InfluenceType FROM dbo.td_character WITH(NOLOCK) WHERE UniqueNumber = @i_SourceCharacterUID)
	IF (@SourAccUID IS NULL) OR (@SourCharInflTy IS NULL)
	BEGIN
		SELECT 1000;	-- isn't the source Character.
		RETURN;
	END

	DECLARE @TargetAccName VARCHAR(20)
	SET @TargetAccName = (SELECT AccountName FROM atum2_db_account.dbo.td_account WITH(NOLOCK) WHERE AccountUniqueNumber = @i_TargetAccountUID)
	IF (@i_TargetAccountUID IS NULL)
	BEGIN
		SELECT 2000;	-- isn't the targer Account.
		RETURN;
	END

	DECLARE @CharCnt INT
	SET @CharCnt = (SELECT COUNT(*) FROM dbo.td_character WITH(NOLOCK) WHERE AccountUniqueNumber = @i_TargetAccountUID AND 0 = (Race & 0x4000))
	IF (@CharCnt IS NOT NULL) AND (@CharCnt > 3)
	BEGIN
		SELECT 3000;	-- Already have valid 3 characters for the target Account.
		RETURN;
	END

	DECLARE @TargInflTy TINYINT
	DECLARE @TargSelInflMask TINYINT

	SELECT @TargInflTy= InfluenceType, @TargSelInflMask= SelectableInfluenceMask 
	FROM dbo.td_character WITH(NOLOCK)
	WHERE AccountUniqueNumber = @i_TargetAccountUID AND 0 = (Race & 0x4000) AND 
	
GO

