USE [db_authentication_server]
GO
/****** 개체:  Table [dbo].[account]    스크립트 날짜: 01/25/2011 16:12:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[account](
	[UniqueNumber] [bigint] IDENTITY(1,1) NOT NULL,
	[GameName] [nchar](30) NOT NULL,
	[ServerIP] [nchar](20) NOT NULL,
	[ServerNetmask] [nchar](20) NOT NULL,
	[Publisher] [nchar](35) NOT NULL,
	[Allow] [tinyint] NOT NULL,
	[ResourceFileName] [nchar](254) NULL,
 CONSTRAINT [PK_account] PRIMARY KEY CLUSTERED 
(
	[UniqueNumber] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
