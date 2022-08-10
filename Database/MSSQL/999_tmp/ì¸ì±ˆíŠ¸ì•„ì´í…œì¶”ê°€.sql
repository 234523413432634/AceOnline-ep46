

-- // 2008-09-09 by cmkwon, 해당 캐릭터에 인챈트 아이템을 추가한다.
CREATE PROCEDURE dbo.temp_insertItem
	@i_CharacUID			INT,
	@i_Count				INT
AS
	DECLARE @i int
	DECLARE @ItemUID BIGINT

	set @i = 0;
	while (@i < @i_Count)
	BEGIN
		exec dbo.atum_admin_InsertStoreItem_DB_by_CharacUniqueNum_for_default @i_CharacUID, 7003760, 8500, 0, 99
		
		SET @ItemUID = (SELECT TOP 1 UniqueNumber FROM td_store ORDER BY UniqueNumber DESC)

		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 1
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 5
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)
		INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 10

		IF (@i > 300)
		BEGIN
			INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 10		
		END

		IF (@i > 600)
		BEGIN
			INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 10		
		END

		IF (@i > 900)
		BEGIN
			INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 10		
		END

		IF (@i > 1200)
		BEGIN
			INSERT INTO td_enchant VALUES(@ItemUID, 7003760, 7000630)		-- 10		
		END

		SET @i = @i + 1;
	END
GO