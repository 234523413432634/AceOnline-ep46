TRUNCATE TABLE dbo.td_DeclarationOfWar
DECLARE @StepStartTime DATETIME
DECLARE @StepEndTime DATETIME
DECLARE @WarStartTime DATETIME
DECLARE @TermMinutesForStep INT
DECLARE @TermMinutesForWarStart INT

-- ���� ����� �� ���� 
SET @StepStartTime			= '20090701 20:00:00'	-- ó�� ���� ���� �ð�
SET @TermMinutesForStep		= 150					-- �� ���� �ҿ� �ð�(��)
SET @TermMinutesForWarStart	= 20					-- ���� ���� �� ���� ���� �ð�(�������� ��ȯ �غ� ���� �ð�)
-- BCU ����
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


-- ���� ����� �� ���� 
SET @StepStartTime			= '20090701 21:00:00'	-- ó�� ���� ���� �ð�
SET @TermMinutesForStep		= 150					-- �� ���� �ҿ� �ð�(��)
SET @TermMinutesForWarStart	= 20					-- ���� ���� �� ���� ���� �ð�(�������� ��ȯ �غ� ���� �ð�)
-- ANI ����
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


-- ������ ���� Ȯ��
SELECT *
FROM td_DeclarationOfWar WITH(NOLOCK)
GO