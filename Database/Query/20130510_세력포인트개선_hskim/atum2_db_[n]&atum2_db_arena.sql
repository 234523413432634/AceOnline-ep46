ALTER TABLE [dbo].[td_InfluenceWarData] ADD [ConsecutiveVictories] SMALLINT NOT NULL DEFAULT 0
GO

--!!!!
-- Name: atum_UpdateInfluenceConsecutiveVictorites
-- Desc: // 2013-05-09 by hskim, ���� ����Ʈ ����
--====
CREATE PROCEDURE atum_UpdateInfluenceConsecutiveVictorites
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,	
	@i_ConsecutiveVictories		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	UPDATE td_InfluenceWarData
		SET ConsecutiveVictories = @i_ConsecutiveVictories
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0075
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_PROCEDURE_080827_0075]
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	SELECT wd.InfluenceType, wd.MGameServerID, wd.WartimeStage, wd.ContributionPoint, wd.InflLeaderCharacterUID, c.CharacterName, wd.OwnerOfConflictArea, wd.InflSub1LeaderCharacterUID, c1.CharacterName, wd.InflSub2LeaderCharacterUID, c2.CharacterName, wd.MSWarOptionType, wd.ConsecutiveVictories
									FROM td_influencewardata wd  LEFT OUTER JOIN td_character c
									ON wd.InflLeaderCharacterUID = c.uniquenumber
									LEFT OUTER JOIN td_character c1
									ON wd.InflSub1LeaderCharacterUID = c1.uniquenumber
									LEFT OUTER JOIN td_character c2
									ON wd.InflSub2LeaderCharacterUID = c2.uniquenumber;
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: atum_Init_InfluenceType_AllCharacter
-- DESC				: // 2009-03-31 by cmkwon, �����ʱ�ȭ �ý��� ���� - 
--						// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
--						
--						#define QUEST_STATE_NONE			(BYTE)0		// �������� ���� ����
--						#define QUEST_STATE_IN_PROGRESS		(BYTE)1		// ������
--						#define QUEST_STATE_COMPLETED		(BYTE)2		// �Ϸ�
--
--						#define QUEST_INDEX_OF_SELECT_INFLUENCE				112
--						 // 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
--						 // 2013-05-09 by hskim, ���� ����Ʈ ����
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_Init_InfluenceType_AllCharacter]
--WITH EXECUTE AS 'proexe'	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, ���� ���Ȱ��� ���� ���� ���� �ϱ�(SQL Server 2005�̻� �����ϴ� ���) - 
AS
BEGIN
	-- �����ʱ�ȭ�� �����忡�� �Ű����� ������ �α׸� ���� ������ ���
	-- // 2012-12-20 by bckim, �����ʱ�ȭ�� ���â��������� ����忡�� �Ű����� ������ �α�
	INSERT [atum_Temporary_Initialized_Guild_List] 
	(AccountUniqueNumber,AccountName,CharacterUniqueNumber,CharacterName,ItemUniqueNumber,ItemNum,Kind,CurrentCount,GuildUniqueNumber,GuildName )	
	SELECT c.AccountUniqueNumber, c.AccountName, c.UniqueNumber, c.CharacterName, s.UniqueNumber, s.ItemNum, i.Kind, s.CurrentCount, g.GuildUniqueNumber, g.GuildName
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g 
	ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c 
	ON g.GuildCommanderUniqueNumber = c.UniqueNumber INNER JOIN [atum2_db_account].[dbo].[ti_ItemInfo] i
	ON i.[ItemNum] = s.ItemNum
	WHERE s.ItemStorage = 2

	-- ���� â���� �������� �ش� ������ �������� â��� �̵�
	UPDATE dbo.td_Store
		SET AccountUniqueNumber = c.AccountUniqueNumber, Possess = c.UniqueNumber, ItemStorage = 1
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c ON g.GuildCommanderUniqueNumber = c.UniqueNumber
	WHERE s.ItemStorage = 2



	-- BCU,ANI ���� ĳ������ �������� �̼��� �����Ѵ�.
	-- ���� ������ ĳ���͵� ���� ó���Ѵ�.
	-- // 2009-04-30 by cmkwon, ���� �ʱ�ȭ ���� ���� - ������ �̼��� ���� ��� ī��Ʈ���� �����Ѵ�.
	DELETE dbo.td_CharacterQuestMonsterCount
	FROM dbo.td_Character c INNER JOIN dbo.td_CharacterQuest cq ON c.UniqueNumber = cq.CharacterUniqueNumber INNER JOIN dbo.td_CharacterQuestMonsterCount cqm ON cq.QuestIndex = cqm.QuestIndex
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1
	DELETE dbo.td_CharacterQuest
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1


	-- BCU,ANI ���� ĳ������ ���� ���� �̼��� ���������� �����Ѵ�.
	UPDATE dbo.td_CharacterQuest
		SET QuestState = 1
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestIndex = 112


	-- BCU,ANI ���� ĳ���Ϳ� ���� ���� �̼��� ���ٸ� ���� ���·� �߰��Ѵ�.
	INSERT INTO dbo.td_CharacterQuest
		SELECT UniqueNumber, 112, 1, 0, GetDate(), 0
		FROM  dbo.td_Character
		WHERE (InfluenceType = 2 OR InfluenceType = 4) AND UniqueNumber NOT IN(SELECT CharacterUniqueNumber FROM dbo.td_CharacterQuest WITH(NOLOCK) WHERE QuestIndex = 112)


	-- ��� ĳ������ ���°� ���ð����� ������ �ش� ������ �����Ѵ�.
	-- // 2009-10-12 by cmkwon, ������ī ���� ��� ���� - �Ϲݼ��� ���ø� ���� ����
	UPDATE dbo.td_Character
		SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode= 1, GuildName='', GuildUniqueNumber = 0, MapIndex = Material, ChannelIndex = 0, Position_X = 9290 , Position_Y = 673 , Position_Z = 4993

	-- ��� ����, ���ܸ��, ģ�� ����Ʈ�� �����Ѵ�.
	DELETE dbo.td_Guild;
	DELETE dbo.td_GuildMember;
	DELETE dbo.td_FriendList;

	-- �����ʱ�ȭ�ÿ� ���� ���� ������ ����
	UPDATE dbo.td_InfluenceWarData SET ConsecutiveVictories = 0
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0007
-- DESC				: -- // 2008-08-27 by cmkwon, �������� Procedure�� ���� - 
--				: -- // 2013-05-09 by hskim, ���� ����Ʈ ����
--------------------------------------------------------------------------------
ALTER PROCEDURE dbo.atum_PROCEDURE_080827_0007
AS
	SELECT wd.InfluenceType, wd.MGameServerID, wd.WartimeStage, wd.ContributionPoint, wd.InflLeaderCharacterUID, c.CharacterName, wd.InflSub1LeaderCharacterUID, c1.CharacterName, wd.InflSub2LeaderCharacterUID, c2.CharacterName, wd.ConsecutiveVictories
	FROM td_influencewardata wd  LEFT OUTER JOIN td_character c ON wd.InflLeaderCharacterUID = c.uniquenumber
		LEFT OUTER JOIN td_character c1	ON wd.InflSub1LeaderCharacterUID = c1.uniquenumber 
			LEFT OUTER JOIN td_character c2 ON wd.InflSub2LeaderCharacterUID = c2.uniquenumber;
GO