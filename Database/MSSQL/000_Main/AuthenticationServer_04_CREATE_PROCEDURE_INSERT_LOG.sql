USE [db_authentication_server]
GO
/****** 개체:  StoredProcedure [dbo].[authentication_server_insert_log]    스크립트 날짜: 01/25/2011 15:29:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[authentication_server_insert_log]
	-- Add the parameters for the stored procedure here
	@PublicIP						nchar(20),
	@PrivateIP						nchar(20),
	@Accept							tinyint,
	@AcceptComment					nchar(254),
	@Publisher						nchar(35),
	@Sender							nchar(30),
	@CurrentVersion					nchar(30),
	@LanguageType					int,
	@TestServer						tinyint,
	@ListenPort						int,
	@ExternalAuthentication			tinyint,
	@PreServerGroupCnts				int,
	@EnableGameServerGroupCnts		int
AS
	INSERT INTO db_authentication_server.dbo.log_aceonline(Date, PublicIP, PrivateIP, Accept, AcceptComment, Publisher, Sender, CurrentVersion, LanguageType, TestServer, ListeningPort, ExternalAuthentication, PreServerGroupCnts, EnableGameServerGroupCnts) 
		VALUES (GetDate(), @PublicIP, @PrivateIP, @Accept, @AcceptComment, @Publisher, @Sender, @CurrentVersion, @LanguageType, @TestServer, @ListenPort, @ExternalAuthentication, @PreServerGroupCnts, @EnableGameServerGroupCnts)

