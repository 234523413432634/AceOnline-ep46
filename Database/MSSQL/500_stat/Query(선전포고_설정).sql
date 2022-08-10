TRUNCATE TABLE dbo.td_DeclarationOfWar
DECLARE @StepStartTime DATETIME
DECLARE @StepEndTime DATETIME
DECLARE @WarStartTime DATETIME
DECLARE @TermMinutesForStep INT
DECLARE @TermMinutesForWarStart INT

-- 설정 해줘야 할 사항 
SET @StepStartTime			= '20090701 20:00:00'	-- 처음 스텝 시작 시간
SET @TermMinutesForStep		= 150					-- 각 스텝 소요 시간(분)
SET @TermMinutesForWarStart	= 20					-- 스텝 시작 후 전쟁 시작 시간(보스몬스터 소환 준비 시작 시간)
-- BCU 설정
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 1, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 2, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 3, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 4, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 5, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (2, 99, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)


-- 설정 해줘야 할 사항 
SET @StepStartTime			= '20090701 21:00:00'	-- 처음 스텝 시작 시간
SET @TermMinutesForStep		= 150					-- 각 스텝 소요 시간(분)
SET @TermMinutesForWarStart	= 20					-- 스텝 시작 후 전쟁 시작 시간(보스몬스터 소환 준비 시작 시간)
-- ANI 설정
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 1, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 2, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 3, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 4, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 5, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)
SET @StepStartTime	= @StepEndTime;
SET @StepEndTime	= DATEADD(minute, @TermMinutesForStep, @StepStartTime);
SET @WarStartTime	= DATEADD(minute, @TermMinutesForWarStart, @StepStartTime);
INSERT INTO dbo.td_DeclarationOfWar	VALUES (4, 99, 0, 0, 0, @StepStartTime, @StepEndTime, @WarStartTime, NULL, 3, 0, 0)


-- 설정된 사항 확인
SELECT *
FROM td_DeclarationOfWar WITH(NOLOCK)
GO