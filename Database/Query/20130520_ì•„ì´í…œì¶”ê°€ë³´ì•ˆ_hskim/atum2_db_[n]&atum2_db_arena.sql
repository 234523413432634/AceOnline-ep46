ALTER TABLE [dbo].[atum_Temporary_SystemInfomation] ALTER COLUMN [Data1] BIGINT
GO

INSERT [dbo].[atum_Temporary_SystemInfomation]([CreateDate], [Type], [Data1]) SELECT getdate(), 2, max([UniqueNumber]) FROM [dbo].[td_Store]
GO

--------------------------------------------------------------------------------
-- TABLE NAME : [td_StoreExtension]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
CREATE TABLE [dbo].[td_StoreExtension]
(
	[UniqueNumber]	BIGINT	PRIMARY KEY,
	[Gesture]		BIGINT	NOT NULL
)
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_InsertStoreExtension]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
CREATE PROCEDURE [dbo].[atum_InsertStoreExtension]
	@i_UniqueNumber		BIGINT,
	@i_Gesture			BIGINT
-- YD ���� �ڵ�
AS
BEGIN
	IF EXISTS(SELECT * FROM [td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber)
	BEGIN
		-- ����
		UPDATE [dbo].[td_StoreExtension] SET [Gesture] = @i_Gesture WHERE [UniqueNumber] = @i_UniqueNumber
	END
	ELSE
	BEGIN
		-- �߰�
		INSERT INTO [dbo].[td_StoreExtension] ([UniqueNumber], [Gesture]) VALUES (@i_UniqueNumber, @i_Gesture)
	END
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetStoreExtension]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetStoreExtension]
	@i_UniqueNumber		BIGINT
-- YD ���� �ڵ�
AS
BEGIN
	SELECT [Gesture] FROM [dbo].[td_StoreExtension] WITH (NOLOCK) WHERE [UniqueNumber] = @i_UniqueNumber
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME : [atum_GetTemporarySystemInfomation]
--					// 2013-05-20 by hskim, [���� �ý���] ���������� ������� ������ �߰� ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_GetTemporarySystemInfomation]
	@i_Type		INT
-- YD ���� �ڵ�
AS
BEGIN
	SELECT [UID], [CreateDate], [Data1], [Data2], [Data3], [Data4] FROM [dbo].[atum_Temporary_SystemInfomation] WITH (NOLOCK) WHERE [Type] = @i_Type
END
GO
