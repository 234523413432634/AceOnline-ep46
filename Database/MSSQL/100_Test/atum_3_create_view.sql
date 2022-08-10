--------------------------------------------------------------------------------
-- �׼������� - TestServer
--------------------------------------------------------------------------------
--
-- VIEWs
--
-- td_Account
-- td_BlockedAccounts		- 2006-04-24 by cmkwon, �߰���
-- atum_log_connection
--
-- 2006-01-09 by cmkwon, EP2������ atum_db_account_test --> atum2_db_account_test �� ����
-- 2006-04-12 by cmkwon, ti_InfluenceWar �߰���
--------------------------------------------------------------------------------
CREATE VIEW dbo.td_Account
AS
	SELECT * FROM atum2_db_account_test.dbo.td_Account
GO

CREATE VIEW dbo.td_AccountCashStore
AS
	SELECT * FROM atum2_db_account_test.dbo.td_AccountCashStore
GO

CREATE VIEW dbo.td_CouponList
AS
	SELECT * FROM atum2_db_account_test.dbo.td_CouponList
GO

CREATE VIEW dbo.td_BlockedAccounts
AS
	SELECT * FROM atum2_db_account_test.dbo.td_BlockedAccounts
GO

CREATE VIEW dbo.atum_log_connection
AS
	SELECT * FROM atum2_db_account_test.dbo.atum_log_connection
GO

CREATE VIEW dbo.atum_backup_log_connection
AS
	SELECT * FROM atum2_db_account_test.dbo.atum_backup_log_connection
GO
--------------------------------------------------------------------------------
--
-- VIEWs
--
--------------------------------------------------------------------------------
CREATE VIEW dbo.ti_BuildingNPC
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_BuildingNPC
GO

CREATE VIEW dbo.ti_CityTargetWarpMap
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_CityTargetWarpMap
GO

CREATE VIEW dbo.ti_EnchantInfo
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_EnchantInfo
GO

CREATE VIEW dbo.ti_Item
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_Item
GO

CREATE VIEW dbo.ti_ItemMixingInfo
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_ItemMixingInfo
GO

CREATE VIEW dbo.ti_MapInfo
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_MapInfo
GO

CREATE VIEW dbo.ti_MapObject
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_MapObject
GO

CREATE VIEW dbo.ti_Monster
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_Monster
GO

CREATE VIEW dbo.ti_MonsterItem
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_MonsterItem
GO

CREATE VIEW dbo.ti_RareItemInfo
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_RareItemInfo
GO

CREATE VIEW dbo.ti_Shop
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_Shop
GO

CREATE VIEW dbo.ti_HappyHourEvent
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_HappyHourEvent
GO

CREATE VIEW dbo.ti_InfluenceWar			-- 2006-04-12 by cmkwon
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_InfluenceWar
GO

CREATE VIEW dbo.atum_Log_ItemEvent		-- 2006-08-24 by dhjin
AS
	SELECT * FROM atum2_db_account_test.dbo.atum_Log_ItemEvent
GO


CREATE VIEW dbo.ti_ItemEvent			-- 2006-08-24 by dhjin
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_ItemEvent
GO

CREATE VIEW dbo.td_PCBang
AS										-- 2007-01-24 by dhjin
	SELECT * FROM atum2_db_account_test.dbo.td_PCBang
GO

CREATE VIEW dbo.ti_MysteryItemDrop			-- 2007-05-11 by cmkwon
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_MysteryItemDrop
GO

-- // 2008-01-29 by cmkwon, ���� ��/���� �α� �ý��� �߰� - VIEW �߰�
CREATE VIEW dbo.atum_log_blockedAccount
AS
	SELECT * FROM atum2_db_account_test.dbo.atum_log_blockedAccount
GO

-- // 2008-04-16 by cmkwon, ���� ��� �� ���� ��ȯ �̺�Ʈ �ý��� ���� - VIEW �߰�
CREATE VIEW dbo.ti_EventMonster
AS
	SELECT * FROM atum2_db_account_test.dbo.ti_EventMonster
GO

-- // 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - VIEW �߰�
CREATE VIEW dbo.td_serverGroup
AS
	SELECT * FROM atum2_db_account_test.dbo.td_serverGroup
GO

