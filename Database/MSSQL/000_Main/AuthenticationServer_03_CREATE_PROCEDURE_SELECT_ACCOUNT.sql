USE [db_authentication_server]
GO
/****** ��ü:  StoredProcedure [dbo].[authentication_server_select_account]    ��ũ��Ʈ ��¥: 01/25/2011 15:29:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[authentication_server_select_account]
	-- Add the parameters for the stored procedure here
	@GameName						nchar(30)
AS
	SELECT * FROM db_authentication_server.dbo.account WHERE GameName = @GameName