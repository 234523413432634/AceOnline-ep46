-------------------------------------------------------------------------------
-- 2006-05-25 by cmkwon, delete data of user table in atum2_db_account DB
	-- 
	TRUNCATE TABLE td_Account
	TRUNCATE TABLE td_AccountCashStore
	TRUNCATE TABLE td_blockedaccounts
	TRUNCATE TABLE td_CouponList
	TRUNCATE TABLE td_PCBang
	
	TRUNCATE TABLE atum_backup_log_connection
	TRUNCATE TABLE atum_backup_log_total_user
	TRUNCATE TABLE atum_log_blockedAccount		-- // 2008-02-13 by cmkwon
	TRUNCATE TABLE atum_log_connection
	TRUNCATE TABLE atum_Log_ItemEvent			-- // 2008-02-13 by cmkwon
	TRUNCATE TABLE atum_log_total_user
--
-------------------------------------------------------------------------------
    