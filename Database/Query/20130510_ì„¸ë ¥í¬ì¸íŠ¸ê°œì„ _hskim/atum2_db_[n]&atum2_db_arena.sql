ALTER TABLE [dbo].[td_InfluenceWarData] ADD [ConsecutiveVictories] SMALLINT NOT NULL DEFAULT 0
GO

--!!!!
-- Name: atum_UpdateInfluenceConsecutiveVictorites
-- Desc: // 2013-05-09 by hskim, 세력 포인트 개선
--====
CREATE PROCEDURE atum_UpdateInfluenceConsecutiveVictorites
	@i_InfluenceType			TINYINT,
	@i_MGameServerID			INT,	
	@i_ConsecutiveVictories		SMALLINT
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
BEGIN
	UPDATE td_InfluenceWarData
		SET ConsecutiveVictories = @i_ConsecutiveVictories
		WHERE InfluenceType = @i_InfluenceType and MGameServerID = @i_MGameServerID
END
GO


--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0075
-- DESC				: -- // 2008-08-27 by cmkwon, 날쿼리를 Procedure로 수정 - 
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_PROCEDURE_080827_0075]
-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
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
-- DESC				: // 2009-03-31 by cmkwon, 세력초기화 시스템 구현 - 
--						// 2009-10-12 by cmkwon, 프리스카 제거 방안 적용 - 
--						
--						#define QUEST_STATE_NONE			(BYTE)0		// 시작하지 않은 상태
--						#define QUEST_STATE_IN_PROGRESS		(BYTE)1		// 진행중
--						#define QUEST_STATE_COMPLETED		(BYTE)2		// 완료
--
--						#define QUEST_INDEX_OF_SELECT_INFLUENCE				112
--						 // 2012-12-20 by bckim, 세력초기화시 길드창고아이템이 길드장에게 옮겨지는 아이템 로그
--						 // 2013-05-09 by hskim, 세력 포인트 개선
--------------------------------------------------------------------------------
ALTER PROCEDURE [dbo].[atum_Init_InfluenceType_AllCharacter]
--WITH EXECUTE AS 'proexe'	-- // 2009-02-17 by cmkwon, MARK for Yedang					-- // 2008-09-04 by cmkwon, 예당 보안관련 숨긴 계정 적용 하기(SQL Server 2005이상만 지원하는 기능) - 
AS
BEGIN
	-- 세력초기화시 여단장에세 옮겨지는 아이템 로그를 위한 데이터 기록
	-- // 2012-12-20 by bckim, 세력초기화시 길드창고아이템이 길드장에게 옮겨지는 아이템 로그
	INSERT [atum_Temporary_Initialized_Guild_List] 
	(AccountUniqueNumber,AccountName,CharacterUniqueNumber,CharacterName,ItemUniqueNumber,ItemNum,Kind,CurrentCount,GuildUniqueNumber,GuildName )	
	SELECT c.AccountUniqueNumber, c.AccountName, c.UniqueNumber, c.CharacterName, s.UniqueNumber, s.ItemNum, i.Kind, s.CurrentCount, g.GuildUniqueNumber, g.GuildName
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g 
	ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c 
	ON g.GuildCommanderUniqueNumber = c.UniqueNumber INNER JOIN [atum2_db_account].[dbo].[ti_ItemInfo] i
	ON i.[ItemNum] = s.ItemNum
	WHERE s.ItemStorage = 2

	-- 여단 창고의 아이템을 해당 여단의 여단장의 창고로 이동
	UPDATE dbo.td_Store
		SET AccountUniqueNumber = c.AccountUniqueNumber, Possess = c.UniqueNumber, ItemStorage = 1
	FROM dbo.td_Store s INNER JOIN dbo.td_Guild g ON s.Possess = g.GuildUniqueNumber INNER JOIN dbo.td_Character c ON g.GuildCommanderUniqueNumber = c.UniqueNumber
	WHERE s.ItemStorage = 2



	-- BCU,ANI 세력 캐릭터의 진행중인 미션을 삭제한다.
	-- 삭제 상태의 캐릭터도 같이 처리한다.
	-- // 2009-04-30 by cmkwon, 세력 초기화 버그 수정 - 삭제될 미션의 몬스터 사냥 카운트먼저 삭제한다.
	DELETE dbo.td_CharacterQuestMonsterCount
	FROM dbo.td_Character c INNER JOIN dbo.td_CharacterQuest cq ON c.UniqueNumber = cq.CharacterUniqueNumber INNER JOIN dbo.td_CharacterQuestMonsterCount cqm ON cq.QuestIndex = cqm.QuestIndex
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1
	DELETE dbo.td_CharacterQuest
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestState = 1


	-- BCU,ANI 세력 캐릭터의 세력 선택 미션을 진행중으로 설정한다.
	UPDATE dbo.td_CharacterQuest
		SET QuestState = 1
	FROM dbo.td_CharacterQuest cq INNER JOIN dbo.td_Character c ON c.UniqueNumber = cq.CharacterUniqueNumber
	WHERE (c.InfluenceType = 2 OR c.InfluenceType = 4) AND cq.QuestIndex = 112


	-- BCU,ANI 세력 캐릭터에 세력 선택 미션이 없다면 진행 상태로 추가한다.
	INSERT INTO dbo.td_CharacterQuest
		SELECT UniqueNumber, 112, 1, 0, GetDate(), 0
		FROM  dbo.td_Character
		WHERE (InfluenceType = 2 OR InfluenceType = 4) AND UniqueNumber NOT IN(SELECT CharacterUniqueNumber FROM dbo.td_CharacterQuest WITH(NOLOCK) WHERE QuestIndex = 112)


	-- 모든 캐릭터의 세력과 선택가능한 세력을 해당 값으로 설정한다.
	-- // 2009-10-12 by cmkwon, 프리스카 제거 방안 적용 - 일반세력 도시맵 설정 수정
	UPDATE dbo.td_Character
		SET InfluenceType = 1, SelectableInfluenceMask = 6, CharacterMode= 1, GuildName='', GuildUniqueNumber = 0, MapIndex = Material, ChannelIndex = 0, Position_X = 9290 , Position_Y = 673 , Position_Z = 4993

	-- 모든 여단, 여단멤버, 친구 리스트를 삭제한다.
	DELETE dbo.td_Guild;
	DELETE dbo.td_GuildMember;
	DELETE dbo.td_FriendList;

	-- 세력초기화시에 세력 연승 정보도 리셋
	UPDATE dbo.td_InfluenceWarData SET ConsecutiveVictories = 0
END
GO

--------------------------------------------------------------------------------
-- PROCEDURE NAME	: dbo.atum_PROCEDURE_080827_0007
-- DESC				: -- // 2008-08-27 by cmkwon, 날쿼리를 Procedure로 수정 - 
--				: -- // 2013-05-09 by hskim, 세력 포인트 개선
--------------------------------------------------------------------------------
ALTER PROCEDURE dbo.atum_PROCEDURE_080827_0007
AS
	SELECT wd.InfluenceType, wd.MGameServerID, wd.WartimeStage, wd.ContributionPoint, wd.InflLeaderCharacterUID, c.CharacterName, wd.InflSub1LeaderCharacterUID, c1.CharacterName, wd.InflSub2LeaderCharacterUID, c2.CharacterName, wd.ConsecutiveVictories
	FROM td_influencewardata wd  LEFT OUTER JOIN td_character c ON wd.InflLeaderCharacterUID = c.uniquenumber
		LEFT OUTER JOIN td_character c1	ON wd.InflSub1LeaderCharacterUID = c1.uniquenumber 
			LEFT OUTER JOIN td_character c2 ON wd.InflSub2LeaderCharacterUID = c2.uniquenumber;
GO