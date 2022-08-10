--------------------------------------------------------------------------------
-- TABLE NAME: td_wrkR_allServiceInfo
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_wrkR_allServiceInfo 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrkR_allServiceInfo(
	ServiceUID			INT,
	ServiceName			VARCHAR(20),
	ServiceSymbolImage	BINARY(2000),		-- 48x28x
	SymbolImageSize		INT
)
CREATE UNIQUE CLUSTERED INDEX idx_ServiUID_on_td_wrkR_allServiceInfo ON td_wrkR_allServiceInfo(ServiceUID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrkR_level
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_wrkR_level 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrkR_level(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	Experience				FLOAT,
	LevelUpTime				DATETIME
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrkR_level ON td_wrkR_level(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrkR_level ON td_wrkR_level(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrkR_level ON td_wrkR_level(ServerGroupID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrkR_frame
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - td_wrkR_frame 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrkR_fame(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	Fame					INT
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrkR_fame ON td_wrkR_fame(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrkR_fame ON td_wrkR_fame(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrkR_fame ON td_wrkR_fame(ServerGroupID)
GO

--------------------------------------------------------------------------------
-- TABLE NAME: td_wrkR_pvp
-- DESC      : // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - dbo.td_wrkR_pvp 테이블 추가
--------------------------------------------------------------------------------
CREATE TABLE dbo.td_wrkR_pvp(
	ServiceUID				INT,
	RankingScope			TINYINT,
	ServerGroupID			INT,
	ServerGroupNameforRK	VARCHAR(20),
	CharacterUID			INT,
	NameforRK				VARCHAR(20),
	UnitKind				INT,
	InfluenceType			TINYINT,
	Level					TINYINT,
	WinPoint				INT,
	LossPoint				INT,
	Score					INT
)
CREATE CLUSTERED INDEX idx_ServiUID8Scope8ServGID_on_td_wrkR_pvp ON td_wrkR_pvp(ServiceUID, RankingScope, ServerGroupID)
CREATE INDEX idx_Scope_on_td_wrkR_pvp ON td_wrkR_pvp(RankingScope)
CREATE INDEX idx_ServGID_on_td_wrkR_pvp ON td_wrkR_pvp(ServerGroupID)
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_updateService_to_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_updateService_to_WRankingServer
	@i_ServiUID					INT,
	@i_ServiName				VARChAR(20),
	@i_SymbolImage				BINARY(2000),
	@i_SymbolImageSize			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DECLARE @ServUID INT;
	SET @ServUID = (SELECT ServiceUID FROM dbo.td_wrkR_allServiceInfo WITH(NOLOCK) WHERE ServiceUID = @i_ServiUID);

	IF (@ServUID IS NULL)
	BEGIN
		INSERT INTO dbo.td_wrkR_allServiceInfo(ServiceUID,ServiceName,ServiceSymbolImage,SymbolImageSize)
		VALUES(@i_ServiUID, @i_ServiName, @i_SymbolImage, @i_SymbolImageSize);
	END
	ELSE
	BEGIN
		UPDATE dbo.td_wrkR_allServiceInfo
		SET ServiceName= @i_ServiName, ServiceSymbolImage= @i_SymbolImage, SymbolImageSize= @i_SymbolImageSize
		WHERE ServiceUID = @i_ServiUID;		
	END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_deleteService_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_deleteService_from_WRankingServer
	@i_ServiUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DELETE FROM dbo.td_wrkR_allServiceInfo WHERE ServiceUID = @i_ServiUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_loadAllService_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_loadAllService_from_WRankingServer
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT ServiceUID, ServiceName, ServiceSymbolImage, SymbolImageSize
	FROM td_wrkR_allServiceInfo WITH(NOLOCK);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_delete_LevelRankingList_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_delete_LevelRankingList_from_WRankingServer
	@i_ServiUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DELETE FROM dbo.td_wrkR_level 
	WHERE ServiceUID = @i_ServiUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_delete_FameRankingList_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_delete_FameRankingList_from_WRankingServer
	@i_ServiUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DELETE FROM dbo.td_wrkR_fame 
	WHERE ServiceUID = @i_ServiUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_delete_PVPRankingList_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_delete_PVPRankingList_from_WRankingServer
	@i_ServiUID					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	DELETE FROM dbo.td_wrkR_pvp
	WHERE ServiceUID = @i_ServiUID;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_insert_LevelRanker_to_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_insert_LevelRanker_to_WRankingServer
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_Experience				FLOAT,
	@i_LevelUpTime				DATETIME
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	INSERT INTO dbo.td_wrkR_level(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,Experience,LevelUpTime)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_Experience,@i_LevelUpTime);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_FameRanker
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_insert_FameRanker_to_WRankingServer
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_Fame						INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	INSERT INTO dbo.td_wrkR_fame(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,Fame)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_Fame);
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrk_insert_PVPRanker
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_insert_PVPRanker_to_WRankingServer
	@i_ServiceUID				INT,
	@i_RankingScope				TINYINT,
	@i_ServerGroupID			INT,
	@i_ServerGroupNameforRK		VARCHAR(20),
	@i_CharacterUID				INT,
	@i_NameforRK				VARCHAR(20),
	@i_UnitKind					INT,
	@i_InfluenceType			TINYINT,
	@i_Level					TINYINT,
	@i_WinPoint					INT,
	@i_LossPoint				INT,
	@i_Score					INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	INSERT INTO dbo.td_wrkR_pvp(ServiceUID,RankingScope,ServerGroupID,ServerGroupNameforRK,CharacterUID,NameforRK,UnitKind,InfluenceType,Level,WinPoint,LossPoint,Score)
	VALUES(@i_ServiceUID,@i_RankingScope,@i_ServerGroupID,@i_ServerGroupNameforRK,@i_CharacterUID,@i_NameforRK,@i_UnitKind,@i_InfluenceType,@i_Level,@i_WinPoint,@i_LossPoint,@i_Score);
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_get_LevelRanking_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_get_LevelRanking_from_WRankingServer
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
	FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
					FROM dbo.td_wrkR_level WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 15)
					ORDER BY Experience DESC, LevelUpTime) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
					FROM dbo.td_wrkR_level WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 240)
					ORDER BY Experience DESC, LevelUpTime) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
					FROM dbo.td_wrkR_level WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 3840)
					ORDER BY Experience DESC, LevelUpTime) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Experience, t.LevelUpTime
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Experience, LevelUpTime
					FROM dbo.td_wrkR_level WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 61440)
					ORDER BY Experience DESC, LevelUpTime) t) t
	ORDER BY t.Experience DESC, t.LevelUpTime;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_get_FameRanking_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_get_FameRanking_from_WRankingServer
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
	FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
					FROM dbo.td_wrkR_fame WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 15)
					ORDER BY Fame DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
					FROM dbo.td_wrkR_fame WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 240)
					ORDER BY Fame DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
					FROM dbo.td_wrkR_fame WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 3840)
					ORDER BY Fame DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.Fame
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, Fame
					FROM dbo.td_wrkR_fame WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 61440)
					ORDER BY Fame DESC) t) t
	ORDER BY t.Fame DESC;
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_get_PVPRanking_from_WRankingServer
-- DESC				: // 2009-02-12 by cmkwon, EP3-3 월드랭킹시스템 구현 - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_get_PVPRanking_from_WRankingServer
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
	FROM (SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
					FROM dbo.td_wrkR_pvp WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 15)
					ORDER BY Score DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
					FROM dbo.td_wrkR_pvp WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 240)
					ORDER BY Score DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
					FROM dbo.td_wrkR_pvp WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 3840)
					ORDER BY Score DESC) t
			UNION 
			SELECT t.ServiceUID, t.RankingScope, t.ServerGroupID, t.ServerGroupNameforRK, t.CharacterUID, t.NameforRK, t.UnitKind, t.InfluenceType, t.Level, t.WinPoint, t.LossPoint, t.Score
			FROM (SELECT TOP 100 ServiceUID, RankingScope, ServerGroupID, ServerGroupNameforRK, CharacterUID, NameforRK, UnitKind, InfluenceType, Level, WinPoint, LossPoint, Score
					FROM dbo.td_wrkR_pvp WITH(NOLOCK)
					WHERE 0 <> (UnitKind & 61440)
					ORDER BY Score DESC) t) t
	ORDER BY Score DESC; 
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_wrkR_delete_AllRankingList_from_WRankingServer
-- DESC				: // 2010-01-14 by cmkwon, 월드랭킹시스템 버그 수정(서비스삭제,서버그룹삭제) - 
--						
--------------------------------------------------------------------------------
CREATE PROCEDURE dbo.atum_wrkR_delete_AllRankingList_from_WRankingServer
	@i_ServiceUID				INT,
	@i_ServerGroupID			INT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
	IF (@i_ServerGroupID <= 0)
	BEGIN
		DELETE dbo.td_wrkR_level	WHERE ServiceUID = @i_ServiceUID;
		DELETE dbo.td_wrkR_fame		WHERE ServiceUID = @i_ServiceUID;
		DELETE dbo.td_wrkR_pvp		WHERE ServiceUID = @i_ServiceUID;
	END
	ELSE
	BEGIN
		DELETE dbo.td_wrkR_level	WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServerGroupID;
		DELETE dbo.td_wrkR_fame		WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServerGroupID;
		DELETE dbo.td_wrkR_pvp		WHERE ServiceUID = @i_ServiceUID AND ServerGroupID = @i_ServerGroupID;
	END
GO
