-------------------------------------------------------------------------------
-- 2005-11-09 by cmkwon

	-- 
	TRUNCATE TABLE td_Character
	TRUNCATE TABLE td_CharacterQuest
	TRUNCATE TABLE td_CharacterQuestMonsterCount

	UPDATE td_CityLeaderInfo	SET Influence= 0, CharacterUID= 0, ExpediencyFundCumulative= 0, ExpediencyFund = 10, ExpediencyFundRate = 0, Notice= NULL
	WHERE MapIndex <> 2001 AND MapIndex <> 2002
	UPDATE td_CityLeaderInfo	SET CharacterUID= 0, ExpediencyFundCumulative= 0, ExpediencyFund = 10, ExpediencyFundRate = 0, Notice= NULL
	WHERE MapIndex = 2001 OR MapIndex = 2002

	TRUNCATE TABLE td_Enchant
	TRUNCATE TABLE td_FriendList
	TRUNCATE TABLE td_Guild
	TRUNCATE TABLE td_GuildMember

	UPDATE td_InfluenceWarData	SET WartimeStage= 0, ContributionPoint= 0, InflLeaderCharacterUID= 0, OwnerOfConflictArea = 0, InflSub1LeaderCharacterUID = 0, InflSub2LeaderCharacterUID = 0

	TRUNCATE TABLE td_LeaderCandidate
	TRUNCATE TABLE td_NotifyMsg
	
	UPDATE td_OutPostInfo	SET OutPostGetInfl= 0, OutPostGuildUID= 0

	TRUNCATE TABLE td_QuickSlot
	TRUNCATE TABLE td_Store
	TRUNCATE TABLE td_StoreSkill
	TRUNCATE TABLE td_TutorialComplete
	TRUNCATE TABLE td_user_list_warpable_to_map
	TRUNCATE TABLE td_VoterList

	TRUNCATE TABLE atum_log_user_level_stat
	TRUNCATE TABLE atum_log_user_exp
	TRUNCATE TABLE atum_log_user_game_start_end
	TRUNCATE TABLE atum_log_user_quest_pk_dead
	TRUNCATE TABLE atum_log_user_warp
	TRUNCATE TABLE atum_log_user_speed_hack
	TRUNCATE TABLE atum_log_item_charac_use
	TRUNCATE TABLE atum_log_item_get_throw
	TRUNCATE TABLE atum_log_item_buy_sell
	TRUNCATE TABLE atum_log_item_trade
	TRUNCATE TABLE atum_log_server_map
	TRUNCATE TABLE atum_log_monster_boss
	TRUNCATE TABLE atum_backup_log_user_level_stat	
	TRUNCATE TABLE atum_backup_log_user_exp			
	TRUNCATE TABLE atum_backup_log_user_game_start_end
	TRUNCATE TABLE atum_backup_log_user_quest_pk_dead 
	TRUNCATE TABLE atum_backup_log_user_warp			
	TRUNCATE TABLE atum_backup_log_user_speed_hack	
	TRUNCATE TABLE atum_backup_log_item_charac_use	
	TRUNCATE TABLE atum_backup_log_item_get_throw	    
	TRUNCATE TABLE atum_backup_log_item_buy_sell		
	TRUNCATE TABLE atum_backup_log_item_trade		    
	TRUNCATE TABLE atum_backup_log_server_map		    
	TRUNCATE TABLE atum_backup_log_monster_boss
--
-------------------------------------------------------------------------------
    