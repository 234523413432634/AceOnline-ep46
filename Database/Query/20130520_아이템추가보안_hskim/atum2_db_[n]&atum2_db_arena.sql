ALTER TABLE [dbo].[atum_Temporary_SystemInfomation] ALTER COLUMN [Data1] BIGINT
GO

INSERT [dbo].[atum_Temporary_SystemInfomation]([CreateDate], [Type], [Data1]) SELECT getdate(), 2, max([UniqueNumber]) FROM [dbo].[td_Store]
GO

--------------------------------------------------------------------------------
-- TABLE NAME : [td_StoreExtension]
--					// 2013-05-20 by hskim, [보안 시스템] 비정상적인 방법으로 아이템 추가 방지
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_StoreExtension]
(
	[UniqueNumber]	BIGINT	PRIMARY KEY,
	[Gesture]		BIGINT	NOT NULL
)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_InsertStoreExtension]
--					// 2013-05-20 by hskim, [보안 시스템] 비정상적인 방법으로 아이템 추가 방지
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InsertStoreExtension]
	@i_UniqueNumber		BIGINT,
	@i_Gesture			BIGINT
-- YD 보안 코드
AS
BEGIN
	IF EXISTS(SELECT * FROM [td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber)
	BEGIN
		-- 갱신
		UPDATE [dbo].[td_StoreExtension] SET [Gesture] = @i_Gesture WHERE [UniqueNumber] = @i_UniqueNumber
	END
	ELSE
	BEGIN
		-- 추가
		INSERT INTO [dbo].[td_StoreExtension] ([UniqueNumber], [Gesture]) VALUES (@i_UniqueNumber, @i_Gesture)
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetStoreExtension]
--					// 2013-05-20 by hskim, [보안 시스템] 비정상적인 방법으로 아이템 추가 방지
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetStoreExtension]
	@i_UniqueNumber		BIGINT
-- YD 보안 코드
AS
BEGIN
	SELECT [Gesture] FROM [dbo].[td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetTemporarySystemInfomation]
--					// 2013-05-20 by hskim, [보안 시스템] 비정상적인 방법으로 아이템 추가 방지
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetTemporarySystemInfomation]
	@i_Type		INT
-- YD 보안 코드
AS
BEGIN
	SELECT [UID], [CreateDate], [Data1], [Data2], [Data3], [Data4] FROM [dbo].[atum_Temporary_SystemInfomation] WITH (NOLOCK) WHERE [Type] = @i_Type
END
GO
