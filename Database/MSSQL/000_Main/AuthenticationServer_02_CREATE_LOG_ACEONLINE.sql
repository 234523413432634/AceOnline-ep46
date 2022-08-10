USE [db_authentication_server]
GO
/****** 개체:  Table [dbo].[log_aceonline]    스크립트 날짜: 01/25/2011 15:26:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[log_aceonline](
	[UniqueNumber] [int] IDENTITY(1,1) NOT NULL,
	[Date] [datetime] NOT NULL,
	[PublicIP] [nchar](20) NULL,
	[PrivateIP] [nchar](20) NULL,
	[Accept] [tinyint] NULL,
	[AcceptComment] [nchar](254) NULL,
	[Publisher] [nchar](35) NULL,
	[Sender] [nchar](30) NULL,
	[CurrentVersion] [nchar](30) NULL,
	[LanguageType] [int] NULL,
	[TestServer] [tinyint] NULL,
	[ListeningPort] [int] NULL,
	[ExternalAuthentication] [tinyint] NULL,
	[PreServerGroupCnts] [int] NULL,
	[EnableGameServerGroupCnts] [int] NULL,
 CONSTRAINT [PK_log_access] PRIMARY KEY CLUSTERED 
(
	[UniqueNumber] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
