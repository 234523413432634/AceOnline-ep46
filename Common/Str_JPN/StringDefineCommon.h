// 2005-04-28 by cmkwon


#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer?? ???? –½—ßŒê
	#define STRCMD_CS_COMMAND_MENT_0					"/ƒRƒƒ“ƒg"
	#define STRCMD_CS_COMMAND_MENT_1					"/ƒRƒƒ“ƒg"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ƒRƒƒ“ƒg [|String] - ·¬×¸À-ºÒÝÄÝ’è"
	#define STRCMD_CS_COMMAND_MOVE						"/ˆÚ“®"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /ˆÚ“® [MapIndex] [|ChannelIndex] - ŠY“– Ï¯ÌßÁ¬ÝÈÙ‚ÉˆÚ“®"
	#define STRCMD_CS_COMMAND_COORDINATE				"/À•W"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /À•W [X] [Y] - Œ»ÝÏ¯Ìß‚ÌŠY“–À•W‚ÉˆÚ“®"
	#define STRCMD_CS_COMMAND_LIST						"/ƒŠƒXƒg"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /ƒŠƒXƒg - Œ»ÝÏ¯Ìß‚ÌÌßÚ²Ô-Ø½Ä‚ðo—Í (Å‘å20l)"
	#define STRCMD_CS_COMMAND_USERSEND					"/ƒLƒƒƒ‰ˆÚ“®"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /ƒLƒƒƒ‰ˆÚ“® [character name] [map name] - ŠY“–·¬×¸À-‚ðŽw’è‚µ‚½Ï¯Ìß‚ÉˆÚ“®"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/î•ñ"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /î•ñ [monster name|item name] - –¼‘O‚ÉŠY“–•¶Žš‚ªŠÜ‚Ü‚ê‚Ä‚¢‚éÓÝ½À-‚â±²ÃÑ‚Ìî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/Ð¯¼®Ý"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /Ð¯¼®Ý - ·¬×¸À-‚ÌÐ¯¼®Ýî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/Ð¯¼®ÝÁ‹Ž"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /Ð¯¼®ÝÁ‹Ž [Ð¯¼®Ý”Ô†]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/Ží—Þ"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /Ží—Þ [|item kind(0`53)] - ŠY“–Ží—Þ‚Ì±²ÃÑ‚ðo—Í"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/Ží—Þ±²ÃÑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /Ží—Þ±²ÃÑ[item kind(0`53)] - ŠY“–Ží—Þ‚Ì±²ÃÑ‚ð’Ç‰Á"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/”ÍˆÍ±²ÃÑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /”ÍˆÍ±²ÃÑ[from itemnum] ` [to itemnum] - ŠY“–±²ÃÑ‚ð’Ç‰Á"
	#define STRCMD_CS_COMMAND_STATINIT					"/½Ã-À½‰Šú‰»"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/½Ã-À½‰Šú‰»"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /½Ã-À½‰Šú‰» [|CharacterName]- ‘S‘Ì½Ã-À½‰Šú‰»"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/•Ò‘à"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /•Ò‘à - •Ò‘àî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_GAMETIME					"/ŽžŠÔ"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /ŽžŠÔ [|‰ÁŽZŽžŠÔ(0`23)] - Œ»ÝŽžŠÔ‚ð•ÏX(Ž©•ª‚ÌŽžŠÔ‚Ì‚Ý•ÏX‚³‚ê‚é)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/ƒXƒgƒŠƒ“ƒO"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/ƒXƒgƒŠƒ“ƒO"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /ƒXƒgƒŠƒ“ƒO [0`5] - ÃÞÊÞ¯¸Ò¯¾-¼Þ‚ðo—Í‚·‚élevel‚ðŒˆ’è"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/¢Š«"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /¢Š« [monster number|monster name] [# of monsters] - ÓÝ½À-‚ð ¢Š«(ÓÝ½À-‚Ì–¼‘O‚É½Íß-½‚ª‚ ‚éê‡‚Í½Íß-½‚Ì‘ã‚í‚è‚Éu_v(±ÝÀÞ-ÊÞ-)‚ð“ü—Í)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/‘SƒXƒLƒ‹"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /‘SƒXƒLƒ‹ [level] - ŠY“–‚Ì‘S‚Ä‚ÌƒXƒLƒ‹‚ð‘}“ü"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/‘S±²ÃÑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allIte"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /‘S±²ÃÑ - ŠY“–‚·‚é‘S‚Ä‚Ì±²ÃÑ‚ð‘}“üAƒXƒLƒ‹‚ÆCountable±²ÃÑ‚ðœŠO"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/‘S•Ší"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /‘S•Ší - ŠY“–ƒMƒA‚Ì‘S‚Ä‚Ì•Ší‚ð’Ç‰Á"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/‘S±²ÃÑ‚ðŽÌ‚Ä‚é"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/‘S±²ÃÑ‚ðŽÌ‚Ä‚é"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /‘S±²ÃÑ‚ðŽÌ‚Ä‚é- ŠY“–‚Ì‘S‚Ä‚Ì‘•”õ•s‰Â±²ÃÑ‚ðŽÌ‚Ä‚éB (ƒXƒLƒ‹œŠO)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/±²ÃÑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /±²ÃÑ [item number] [# of items] - ±²ÃÑ‚ðŽæ“¾‚·‚éBŽæ“¾”[# of items]‚ð“ü—Í‚µ‚È‚¢ê‡A1ŒÂ‚¾‚¯Žæ“¾B"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/ƒhƒƒbƒv"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /ƒhƒƒbƒv [item number] [|# of items] - ±²ÃÑ‚ðƒhƒƒbƒv"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/»-ÊÞ"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /»-ÊÞ - »-ÊÞ‚Ìî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/»-ÊÞÏ¯Ìß"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /»-ÊÞÏ¯Ìß - ‘S‚Ä‚ÌÏ¯Ìß‚Ìî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/Á¬ÝÈÙ"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /Á¬ÝÈÙ - Œ»ÝÏ¯Ìß‚ÌÁ¬ÝÈÙî•ñ‚ðo—Í"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/DBG"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /DBG - ƒeƒXƒg—p"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/e’e"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /e’e [|1Œ^e’e”] [|2Œ^e’e”] - e’e‚ð•â‹‹"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/‘S‰ñ•œ"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /‘S‰ñ•œ [|character name] - HP, UTC, FUEL‚ð 100% ‰ñ•œ‚·‚éA[character name]‚ª“ü—Í‚³‚ê‚Ä‚¢‚È‚¢ê‡AŽ©•ª‚ð‰ñ•œ"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/ŠeŽíŒ¸­"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /ŠeŽíŒ¸­ [|Œ¸­’l%] [|character name] - HP, UTC, FUEL‚ð [Œ¸­’l%]‚É‚·‚éA[Œ¸­’l%]‚Ì“ü—Í‚ª‚È‚¢ê‡‚Í50%A [character name]‚ª“ü—Í‚³‚ê‚Ä‚¢‚È‚¢ê‡‚ÍŽ©•ªŽ©g‚ðŒ¸­B"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/ˆê”Ê"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /ˆê”Ê -‰^‰cŽÒ¹Þ-ÑÏ½À-±¶³ÝÄ‚ÅƒƒOƒCƒ“‚µ‚½ê‡Aˆê”ÊƒAƒJƒEƒ“ƒg‚Åˆø‚«‘Ö‚¦i‹@ŠB–|–ój"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/“ÁŒ "
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /“ÁŒ  -‰^‰cŽÒ‚â¹Þ-ÑÏ½À-±¶³ÝÄ‚ÅƒƒOƒCƒ“‚µ‚½ê‡Aˆê”ÊƒAƒJƒEƒ“ƒg‚Ü‚½‚Í“ÁŽêƒAƒJƒEƒ“ƒg‚Åˆø‚«‘Ö‚¦i‹@ŠB–|–ój"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/–³“G"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /–³“G- ‰^‰cŽÒ‚â¹Þ-ÑÏ½À-±¶³ÝÄ‚Ìê‡AÀÞÒ-¼Þ‚ðŽó‚¯‚È‚¢"
	#define STRCMD_CS_COMMAND_POWERUP					"/Žm‹C"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /Žm‹C [UŒ‚—Í ‘‰Á—Ê(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/•Ï”"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /•Ï” [•Ï”’l] - (ˆê”Ê)•Ï” ’²®"
	#define STRCMD_CS_COMMAND_LEVELSET					"/ƒŒƒxƒ‹"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /ƒŒƒxƒ‹ [|level] [|percentage of exp] [|character name] - ƒŒƒxƒ‹‚ð’²®‚·‚é"


    #define STRCMD_CS_COMMAND_PARTNERLEVELSET		"/Êß-ÄÅ-ƒŒƒxƒ‹"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_1		"/partnerlevel"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /Êß-ÄÅ-ƒŒƒxƒ‹ [|level] [|percentage of exp] - Êß-ÄÅ-‚ÌƒŒƒxƒ‹’²®"


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/“§–¾"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /“§–¾ - Ž©•ª‚ª‚Ù‚©‚Ì·¬×¸À-‚ÉŒ©‚¦‚È‚¢"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - ƒeƒXƒg—p"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/ƒCƒxƒ“ƒg"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"ŒoŒ±’l"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"ŒoŒ±’l•œ‹Œ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"±²ÃÑ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Ú±±²ÃÑ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"I—¹"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /ƒCƒxƒ“ƒg [ŒoŒ±’lbSPIbŒoŒ±’l•œ‹Œb±²ÃÑbÚ±±²ÃÑbí‘ˆÎß²ÝÄiWPj] [|”{”(%%f)|I—¹] [ŽžŠÔ(’PˆÊ:•ª)] [|¨—Í(255:ALL,1:Normal,2:VCN,4:ANI)]- ƒCƒxƒ“ƒg Ý’è,‰ðœ"
	#define STRCMD_CS_COMMAND_PREMEUM					"/ÌßÚÐ±Ñ"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"ˆê”Ê"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"½-Êß-"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"±¯Ìß¸ÞÚ-ÄÞ"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"I—¹"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /ÌßÚÐ±Ñ [ˆê”Ê|½-Êß-|±¯Ìß¸ÞÚ-ÄÞ|I—¹]"
// 2008-02-14 by cmkwon, “sŽsè—Ìí –½—ßŒê ??
// 	#define STRCMD_CS_COMMAND_CITYWAR					"/“sŽsè—Ìí"
// 	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"ŠJŽn"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"I—¹"
// 	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /“sŽsè—Ìí [ŠJŽn|I—¹]"
	#define STRCMD_CS_COMMAND_STEALTH					"/ƒXƒeƒ‹ƒX"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /ƒXƒeƒ‹ƒX - æ§UŒ‚ÓÝ½À-‚ªæU‚µ‚È‚¢"
	#define STRCMD_CS_COMMAND_RETURNALL					"/‘S‚Ä‹AŠÒ"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /‘S‚Ä‹AŠÒ - ŠY“– ¨—Í•Ê “sŽsÏ¯Ìß‚ÉˆÚ“®‚·‚é"
// start 2011-10-28 by hskim, EP4 [Æ®¸®°Å ½Ã½ºÅÛ] - Å©¸®½ºÅ» ½Ã½ºÅÛ
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [Æ®¸®°Å ½Ã½ºÅÛ] - Å©¸®½ºÅ» ½Ã½ºÅÛ


// start 2011-06-22 by hskim, »ç¼³ ¼­¹E¹æÁE
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ¼­¹EÁ¤º¸ º¸±E
// end 2011-06-22 by hskim, »ç¼³ ¼­¹E¹æÁE
			   
// start 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶EÅ×½ºÆ® ¸úÓÉ¾E
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ¼­¹EÁ¤º¸ º¸±E
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶EÅ×½ºÆ® ¸úÓÉ¾E

// 2007-10-30 by cmkwon, ¼¼·Âº° ÇØÇÇ¾Æ¿EÀÌº¥Æ® ±¸?E- ¸úÓÉ¾E?E?¼öÁ¤µÊ ¾Æ·¡¿¡¼­ ´Ù½Ã Á¤ÀÇ ÇÔ
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHourƒCƒxƒ“ƒg"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"ŠJŽn"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"I—¹"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHourƒCƒxƒ“ƒg [ŠJŽn|I—¹] [isŽžŠÔ(’PˆÊ:•ª)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer?? ???? –½—ßŒê, ??? ??? ??? –½—ßŒê? ??? ???
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer ????"
	#define STRCMD_CS_COMMAND_WHO						"/’N"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /’N [|# of users] - Œ»Ý »-ÊÞ‚É‚ ‚éÕ-»Þ-‚ð‘S‚Äo—Í (Ï¯Ìß‚ÆŠÖŒW‚È‚¢)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/‰^‰c“o˜^"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /‰^‰c“o˜^ - ‰^‰cŽÒ‚É“Á’èƒCƒxƒ“ƒg”­¶Žž‚ÌÒ¯¾-¼Þ‚ðŽó‚¯‚é‚æ‚¤‚É»-ÊÞ‚É“o˜^‚·‚é"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - ƒNƒ‰ƒCƒAƒ“ƒg‚ÆIM »-ÊÞ‚Æ‚ÌŠÔ‚ÌƒvƒƒgƒRƒ‹‚ð‘S‚Äo—Í‚·‚é"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/»-ÊÞ-ÀÞ³Ý"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /»-ÊÞ-ÀÞ³Ý [”FØ”Žš] - »-ÊÞ‚ð I—¹‚³‚¹‚é"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/’N2"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /’N2 [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/s‚­"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /s‚­ [character name] - ŠY“– ·¬×¸À-‚ÌêŠ‚ÉˆÚ“®‚·‚é"
	#define STRCMD_CS_COMMAND_COMEON					"/ŒÄ‚Ô"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /ŒÄ‚Ô [character name] - ŠY“–·¬×¸À-‚ðŒÄ‚Ô"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/—·’cŒÄ‚Ô"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /—·’cŒÄ‚Ô [—·’c–¼] - ŠY“– —·’cÒÝÊÞ-‚ð‘S‚ÄŒÄ‚Ô"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/—·’c‘—‚é"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /—·’c‘—‚é [—·’c–¼] [map name] - ŠY“– —·’cÒÝÊÞ-‚ð Ï¯Ìß‚ÉˆÚ“®‚³‚¹‚é"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/‚³‚³‚â‚«"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /‚³‚³‚â‚« - ‚³‚³‚â‚«‚ðƒuƒƒbƒN‚â‰ðœ‚·‚éiOn/Offj"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/—·’c"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /—·’c - —·’c î•ñ o—Í"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/“V‹C"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"Šî–{"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"°‚ê"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"‰J"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"á"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"“Ü‚è"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"–¶"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"‘S‘Ì"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /“V‹C [Šî?|°‚ê|‰J|á|“Ü‚è|–¶] [‘S‘Ì|Ï¯Ìß–¼] [on|off] - “V‹C’²®"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/Á¬¯ÄÌÞÛ¯¸"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /Á¬¯ÄÌÞÛ¯¸ [character name] [ŽžŠÔ(•ª)] - Á¬¯Ä‚ðÌÞÛ¯¸‚·‚é"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/Á¬¯ÄÌÞÛ¯¸‰ðœ"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /Á¬¯ÄÌÞÛ¯¸‰ðœ [character name] - Á¬¯ÄÌÞÛ¯¸‚ð‰ðœ‚·‚é"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/–½—ßŒê"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - –½—ßŒêƒŠƒXƒg‚ðo—Í"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/ÎÞ-Å½½Ã-À½"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/ÎÞ-Å½½Ã-À½"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - ÎÞ°Å½½Ã°À½±¯Ìß"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor?? ???? –½—ßŒê, ??? ??? ??? –½—ßŒê? ??? ???
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/Êß½Ü-ÄÞÝ’è"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /Êß½Ü-ÄÞÝ’è [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/Êß½Ü-ÄÞ•œ‹Œ"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /Êß½Ü-ÄÞ•œ‹Œ [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/Êß½Ü-ÄÞØ½Ä"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /Êß½Ü-ÄÞØ½Ä"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/Êß½Ü-ÄÞ‰»"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /Êß½Ü-ÄÞ‰» [Êß½Ü-ÄÞ‰»‚·‚éƒXƒgƒŠƒ“ƒO]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/ƒAƒJƒEƒ“ƒgƒuƒƒbƒN"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /ƒAƒJƒEƒ“ƒgƒuƒƒbƒN [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/ƒAƒJƒEƒ“ƒgƒuƒƒbƒN‰ðœ"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /ƒAƒJƒEƒ“ƒgƒuƒƒbƒN‰ðœ [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/ƒuƒƒbƒN‚³‚ê‚½ƒAƒJƒEƒ“ƒg"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /ƒuƒƒbƒN‚³‚ê‚½ƒAƒJƒEƒ“ƒg"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "M¹Þ-Ñ»-ÊÞê—p!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "»-ÊÞÛ¸Þ²ÝID‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢"
	#define STRCMD_CS_COMMON_DB_0002 "»-ÊÞÛ¸Þ²ÝPW‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢"
	#define STRCMD_CS_COMMON_DB_0003 "DBƒƒOƒCƒ“ID‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRCMD_CS_COMMON_DB_0004 "DBƒƒOƒCƒ“PW‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"

	#define STRCMD_CS_COMMON_MAP_0000 "Ê-ÄÞº-ÃÞ¨Ý¸Þ•”•ª: 0101Ï¯Ìß‚Å1”ÔÜ-ÌßÀ-¹Þ¯Ä‚ð–³Ž‹AÏ¯Ìß´ÃÞ¨À‚©œ‹Ž\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Ê-ÄÞº-ÃÞ¨Ý¸Þ•”•ª: 0101Ï¯Ìß‚Å1”ÔÜ-ÌßÀ-¹Þ¯Ä‚ð–³Ž‹AÏ¯Ìß´ÃÞ¨À‚©œ‹Ž\r\n "
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] ¢Š«ÓÝ½À-[%8d] ¢Š«ŽžŠÔ[%6d•b]A Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index d•¡ Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] ¢Š« ÓÝ½À-[%8d] ¢Š«ŽžŠÔ[%6d•b], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Tatal Monster Count:[%4d]<==µÌÞ¼Þª¸ÄÓÝ½À-‚ðŠÜ‚Þ\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "ÀÞ³ÝÛ-ÄÞÌ§²Ù‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Ì§²Ùì¬´×-‚Å‚·B"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "ÀÞ³ÝÛ-ÄÞÌ§²Ù‚Ì“Ç‚Ýž‚Ý´×-‚Å‚·B"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d“ú%dŽžŠÔ%d•ª%d•b"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"ˆê”Ê"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"ÊÞÀ×½"
	#define STRCMD_CS_COMMON_RACE_DECA			"ƒfƒJ"
	#define STRCMD_CS_COMMON_RACE_PHILON		"ƒpƒCƒƒ“"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"ƒVƒ…ƒŠƒ“"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"—\”õ"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"—\”õ"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"ŠÇ—ŽÒ"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"GM"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"ÓÆÀ-"
	#define STRCMD_CS_COMMON_RACE_GUEST			"ƒQƒXƒg"
	#define STRCMD_CS_COMMON_RACE_DEMO			"ƒfƒ‚—p"
	#define STRCMD_CS_COMMON_RACE_ALL			"‘SŽí‘°"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"•s–¾‚ÈŽí‘°"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"–¼‘O‚È‚µ"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"ÄÚ-ÆÝ¸Þ´±-ÏÝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd´±-ÏÝ"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd´±-ÏÝ"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st´±-ÏÝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd³²Ý¸ÞÏÝ"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd³²Ý¸ÞÏÝ"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st³²Ý¸ÞÏÝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rdØ-ÀÞ-"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2ndØ-ÀÞ-"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1stØ-ÀÞ-"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd´-½"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd´-½"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st´-½"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"y«"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"­«"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"’†«"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"‘å«"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"µ-ÄÏÁ¯¸—Þ"
	#define STRCMD_CS_ITEMKIND_VULCAN				"ƒoƒ‹ƒJƒ“—Þ"
	#define STRCMD_CS_ITEMKIND_DUALIST				"ƒfƒ…ƒAƒ‹ƒŠƒXƒg—Þ"		// 2005-08-01 by hblee : GRENADE -> DUALIST ‚É •ÏX.
	#define STRCMD_CS_ITEMKIND_CANNON				"ƒLƒƒƒmƒ“—Þ"
	#define STRCMD_CS_ITEMKIND_RIFLE				"ƒ‰ƒCƒtƒ‹—Þ"
	#define STRCMD_CS_ITEMKIND_GATLING				"ƒKƒgƒŠƒ“ƒO—Þ"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"×ÝÁ¬-—Þ"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Ï½ÄÞ×²ÌÞ—Þ"
	#define STRCMD_CS_ITEMKIND_ROCKET				"ƒƒPƒbƒg—Þ"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Ð»²Ù—Þ"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"ƒoƒ“ƒhƒ‹—Þ"

	#define STRCMD_CS_ITEMKIND_MINE					"Ï²Ý—Þ"
	#define STRCMD_CS_ITEMKIND_SHIELD				"¼-ÙÄÞ—Þ"
	#define STRCMD_CS_ITEMKIND_DUMMY				"ÀÞÐ-—Þ"
	#define STRCMD_CS_ITEMKIND_FIXER				"Ëß¸»-—Þ"
	#define STRCMD_CS_ITEMKIND_DECOY				"ƒfƒRƒC—Þ"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"±-Ï-—Þ"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"ƒGƒ“ƒWƒ“—Þ"
	#define STRCMD_CS_ITEMKIND_ENERGY				"´ÈÙ·Þ-—Þ"
	#define STRCMD_CS_ITEMKIND_INGOT				"zÎ—Þ"
	#define STRCMD_CS_ITEMKIND_CARD					"ˆê”Ê¶-ÄÞ—Þ"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"´ÝÁ¬ÝÄ¶-ÄÞ—Þ"
	#define STRCMD_CS_ITEMKIND_TANK					"ÀÝ¸—Þ"
	#define STRCMD_CS_ITEMKIND_BULLET				"’eŠÛ—Þ"
	#define STRCMD_CS_ITEMKIND_QUEST				"Ð¯¼®Ý±²ÃÑ—Þ"
	#define STRCMD_CS_ITEMKIND_RADAR				"Ú-ÀÞ-—Þ"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"ºÝËß­-À-—Þ"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"·Þ¬ÝÌÞÙ¶-ÄÞ—Þ"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"´ÝÁ¬ÝÄ”j‰ó–hŽ~¶-ÄÞ—Þ"
	#define STRCMD_CS_ITEMKIND_BLASTER				"ÌÞ×½À-—Þ"	// 2005-08-01 by hblee : ÌÞ×½À-—Þ’Ç‰Á.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Ú-Ù¶ÞÝ—Þ"		// 2005-08-01 by hblee : Ú-Ù¶ÞÝ—Þ’Ç‰Á.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"–³§ŒÀƒAƒNƒZƒTƒŠ"		// 2006-03-17 by cmkwon, Žg—pŽžŠÔ‚ª <‰i‹v>‚Ì ±¸¾»Ø ±²ÃÑ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"ŽžŠÔ§ŒÀƒAƒNƒZƒTƒŠ"		// 2006-03-17 by cmkwon, ŽžŠÔ§ŒÀ‚Ì‚ ‚é±¸¾»Ø±²ÃÑ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"‘S•Ší‘S•Ší"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"ƒƒCƒ“•Ší"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"e’eŒ^ƒƒCƒ“•Ší"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"”R—¿Œ^ƒƒCƒ“•Ší"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"ƒTƒu•Ší"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"’e“ªŒ^ƒTƒu•Ší"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"–hŒäŒ^ƒTƒu•Ší"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"UŒ‚ƒXƒLƒ‹"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"–hŒäƒXƒLƒ‹"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"•â•ƒXƒLƒ‹"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"‘®«ƒXƒLƒ‹"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1Œ^ÓÝ½À-—pƒAƒCƒe?"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"ÓÝ½À-Ï¼Ý¶ÞÝ(1-1Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"ÓÝ½À-ƒr??—Þ(1-2Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"ÓÝ½À-‘S‘ÌUŒ‚"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2Œ^ÓÝ½À-—p±²ÃÑ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"ÓÝ½À-Û¹¯Ä(2-1Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"ÓÝ½À-Ð»²Ù—Þ(2-1Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"ÓÝ½À-ÊÞÝÄÞÙ—Þ(2-1Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"ÓÝ½À-Ï²Ý—Þ(2-1Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"ÓÝ½À-¼-ÙÄÞ—Þ(2-2Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"ÓÝ½À-ÀÞÐ-—Þ(2-2Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"ÓÝ½À-ƒsƒNƒT?—Þ(2-2Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"ÓÝ½À-ÃÞº²—Þ(2-2Œ^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"ÓÝ½À-Ì§²Ô-—Þ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"ÓÝ½À-Õ“Ë‰Â”\ËÞ-Ñ—Þ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"ÓÝ½À-’¼i”š’e—Þ"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"•s–¾‚È±²ÃÑ"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"•s–¾‚È‹@‘Ì"

	#define STRCMD_CS_STAT_ATTACK_PART				"UŒ‚"
	#define STRCMD_CS_STAT_DEFENSE_PART				"–hŒä"
	#define STRCMD_CS_STAT_FUEL_PART				"”R—¿"
	#define STRCMD_CS_STAT_SOUL_PART				"¸_"
	#define STRCMD_CS_STAT_SHIELD_PART				"¼-ÙÄÞ"
	#define STRCMD_CS_STAT_DODGE_PART				"‰ñ”ð"
	#define STRCMD_CS_STAT_BONUS					"ÎÞ-Å½½Ã-À½"
	#define STRCMD_CS_STAT_ALL_PART					"‘S½Ã-À½"
	#define STRCMD_CS_STAT_UNKNOWN					"•s–¾‚È½Ã-À½"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Ž©—RŒ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"UŒ‚Œ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"ÏÙÁŒ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"UŒ‚Œ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"‰ñ”ðŒ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"UŒ‚Œ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"¼-ÙÄÞŒ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"–hŒäŒ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Žx‰‡Œ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¨—Í? HappyHour ƒCƒxƒ“ƒg ?? - ???? ?? ?? ?
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"ÊÞ²¼ÞªÆ­-ˆê”ÊŒR"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"ÊÞ²¼ÞªÆ­-³‹KŒR"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"±-ØÝÄÝ³‹KŒR"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"ÊÞÀ×½˜A–MŒR"

	#define STRCMD_CS_POS_PROW						"Ú-ÀÞ-ˆÊ’u(æ“ª‚Ì’†‰›)"
	#define STRCMD_CS_POS_PROWIN					"ºÝËß­-À-(’†‰›‚Ì¶)"
	#define STRCMD_CS_POS_PROWOUT					"ƒƒCƒ“•Ší(æ“ª‚Ì¶)"
	#define STRCMD_CS_POS_WINGIN					"Žg—p‚µ‚È‚¢(’†‰›‚Ì‰E)"
	#define STRCMD_CS_POS_WINGOUT					"ƒTƒu•Ší(æ“ª‚Ì‰E)"
	#define STRCMD_CS_POS_CENTER					"±-Ï-(’†‰›‚Ì’†‰›)"
	#define STRCMD_CS_POS_REAR						"ƒGƒ“ƒWƒ“(Œã”ö‚Ì’†‰›)"
	    
	// 2010-06-15 by shcho&hslee ?EÃ½ºÅ?
    //#define STRCMD_CS_POS_ATTACHMENT				"•t’…•¨(Œã”ö‚Ì‰E-”R—¿ÀÝ¸|ÄÞ×²ÊÞ-Œn—ñ)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"•t’…•¨(Œã”ö‚Ì‰E-”R—¿ÀÝ¸|ÄÞ×²ÊÞ-Œn—ñ)"

	// 2010-06-15 by shcho&hslee ?EÃ½ºÅ?
	//#define STRCMD_CS_POS_PET						"Žg—p‚µ‚È‚¢(Œã”ö‚Ì¶)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Žg—p‚µ‚È‚¢(Œã”ö‚Ì¶)"

	#define STRCMD_CS_POS_PET						"Êß-ÄÅ"

    #define STRCMD_CS_HIDDEN_ITEM				"‰B‚³‚ê‚½êŠ"	
	
	#define STRCMD_CS_POS_INVALID_POSITION			"–¢Šm’èˆÊ’u"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"ƒCƒ“ƒxƒ“ƒgƒŠˆÊ’u"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/Ð¯¼®ÝŠ®—¹"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /Ð¯¼®ÝŠ®—¹[|QuesIndex] - is’†Ð¯¼®Ý‚âŽw’è‚µ‚½Ð¯¼®Ý‚ªŠ®—¹ˆ—"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/¨—Í•ª•z"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /¨—Í•ª•z"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/¨—Í•ÏX"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format:/¨—Í•ÏX [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/ÓÝ½À-‚És‚­"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format:/ÓÝ½À-‚És‚­ [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - —·’c ?? ?? - ?? ?? ??? ˆÚ“®
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"‘àˆõ"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"—·’c’·"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1‘å‘à’·"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1‘å‘àˆõ"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2‘å‘à’·"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2‘å‘àˆõ"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3‘å‘à’·"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3‘å‘àˆõ"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4‘å‘à’·"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4‘å‘àˆõ"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5‘å‘à’·"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5‘å‘àˆõ"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/“dŒõ”Â"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format:/“dŒõ”Â[|Ž‘±ŽžŠÔ(’PˆÊ:•ª)] [‚¨’m‚ç‚¹“à—e] - Žw“±ŽÒ‚Ì‚ÝŽg—p‰Â”\A“dŒõ”Â‚É‚¨’m‚ç‚¹‚ð’Ç‰Á‚·‚é‚©ƒŠƒXƒg‚ðŒ©‚é"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/“dŒõ”Âíœ"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /“dŒõ”Âíœ[íœ‚·‚é‚¨’m‚ç‚¹‚ÌƒCƒ“ƒfƒbƒNƒX] - Žw“±ŽÒ‚Ì‚ÝŽg—p‰Â”\A“dŒõ”Â‚ÌŽw’è‚µ‚½‚¨’m‚ç‚¹‚ðíœ‚·‚é"

	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"¨—ÍíØ-ÀÞ-"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"¨—Íí•›Ø-ÀÞ-"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"¨—ÍŽx‰‡Œø‰Ê"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"¨—ÍƒCƒxƒ“ƒg"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/Šñ—^“x"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /Šñ—^“x [¨—Í(2:BCU, 4:ANI)] [‘‰Á•ª] ? Žw’è‚µ‚½¨—Í‚ÌŠñ—^“x‚ð‘‰Á‚³‚¹‚é"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/ƒwƒ‹ƒv"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/ƒwƒ‹ƒv"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /ƒwƒ‹ƒv [‘Š’k“à—e] - GM‚É‘Š’k‚ð\‚µž‚Ý‚·‚éB"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ƒwƒ‹ƒv‚ðŒ©‚é"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ƒwƒ‹ƒv‚ðŒ©‚é"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ƒwƒ‹ƒv‚ðŒ©‚é[|Œ”(1`10)] - GM‘Š’k\‚µž‚ÝƒŠƒXƒg‚ðŽw’è‚µ‚½Œ”‚ðo—Í‚·‚é"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/ƒwƒ‹ƒv‚ð“Ç‚Ýž‚Þ"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/ƒwƒ‹ƒv‚ð“Ç‚Ýž‚Þ"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /ƒwƒ‹ƒv‚ð“Ç‚Ýž‚Þ[|Œ”(1`10)] - GM‘Š’k\‚µž‚ÝƒŠƒXƒg‚ðŽw’è‚µ‚½Œ”“Ç‚Ýž‚Þ (»-ÊÞ‚©‚çíœ‚³‚ê‚é)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/¨—Í¢Š«"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/¨—Í¢Š«"
// 2008-09-09 by cmkwon, /¨—Í¢Š« –½—ßŒê ?? ƒŠƒXƒg? ??À²Ìß ’Ç‰Á - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [Å‘ålˆõ] [0|Å¬ƒŒƒxƒ‹] [0|Å‘åƒŒƒxƒ‹] [Õ-»Þ-‚É‘—‚éÒ¯¾-¼Þ] ? ”CˆÓ‚ÉŽw’è‚µ‚½¨—ÍAŽw’è‚µ‚½ƒŒƒxƒ‹‚ÌÕ-»Þ-‚É²ÍÞÝÄÏ¯Ìß‚Ö‚ÌˆÚ“®‚ð—v¿‚·‚é"

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/±²ÃÑÏ¯Ìß"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/±²ÃÑ’Ç‰ÁÏ¯Ìß"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(VCN)|4(ANI)|255(All)] [Item Number] [# of items] - Œ»ÝÏ¯Ìß‚ÌŽw’è‚µ‚½¨—Í‚ÌÕ-»Þ-‚ÉŽw’è‚µ‚½±²ÃÑ‚ðŽx‹‹‚·‚é"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ??? ?? ?? ??? ???
	// ??(Korea):		YYYY-MM-DD HH:MM:SS
	// ??(English):	MM-DD-YYYY HH:MM:SS
	// ???(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, ƒŒƒxƒ‹•ª•z
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/ƒŒƒxƒ‹•ª•z"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /ƒŒƒxƒ‹•ª•z - ¹Þ-Ñ‚ÉÚ‘±‚µ‚Ä‚¢‚éÕ-»Þ-‚ÌƒŒƒxƒ‹•ª•z‚ð‚Ý‚é"	// 2006-08-08 by dhjin


	// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_0		"/Žsê"
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_1		"/Žsê"	
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_HELP	"format: /Žsê - ƒgƒŒ[ƒhƒVƒ‡ƒbƒv ON OFF. "
	// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"K‰^‚Ì” "

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Ï-¸"

///////////////////////////////////////////////////////////////////////////////
// 2006-08-24 by cmkwon
// ƒNƒ‰ƒCƒAƒ“ƒg??? ???? –½—ßŒê(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/ÎÞ²½Á¬¯Ä"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /ÎÞ²½Á¬¯Ä [CharacterName] - Žw’è‚µ‚½·¬×¸À-‚É 1:1 ÎÞ²½Á¬¯Ä‚ð —v¿‚·‚é"
	#define STRCMD_C_COMMAND_PARTYCALL					"/•Ò‘àÎÞ²½Á¬¯Ä"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /•Ò‘àÎÞ²½Á¬¯Ä - •Ò‘à’·‚Ì‚ÝŽg—p‰Â”\B•Ò‘àÎÞ²½Á¬¯Ä‚ðŠJŽn‚·‚é"
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/•Ò‘àÎÞ²½Á¬¯ÄI—¹"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /•Ò‘àÎÞ²½Á¬¯ÄI—¹ - •Ò‘à’·‚Ì‚ÝŽg—p‰Â”\B•Ò‘àÎÞ²½Á¬¯Ä‚ðI—¹‚·‚é"
	#define STRCMD_C_COMMAND_GUILDCALL					"/—·’cÎÞ²½Á¬¯Ä"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /—·’cÎÞ²½Á¬¯Ä - —·’c’·‚Ì‚ÝŽg—p‰Â”\A—·’cÎÞ²½Á¬¯Ä‚ðŠJŽn‚·‚éB"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/—·’cÎÞ²½Á¬¯ÄI—¹"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /—·’cÎÞ²½Á¬¯ÄI—¹ - —·’c’·‚Ì‚ÝŽg—p‰Â?A—·’cÎÞ²½Á¬¯Ä‚ðI—¹‚·‚éB"
	#define STRCMD_C_COMMAND_CALLEND					"/ÎÞ²½Á¬¯ÄI—¹"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /ÎÞ²½Á¬¯ÄI—¹ - 1:1 ƒ{ƒCƒXƒ`ƒƒƒbƒg‚â•Ò‘àƒ{ƒCƒXƒ`ƒƒƒbƒg‚â—·’cƒ{ƒCƒXƒ`ƒƒƒbƒg‚ðI—¹‚·‚éB"
	#define STRCMD_C_COMMAND_COMBAT						"/‘ÎŒˆ"
	#define STRCMD_C_COMMAND_BATTLE						"/Œˆ“¬"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /Œˆ“¬ [CharacterName] - Žw’è‚µ‚½·¬×¸À-‚É1:1 Œˆ“¬‚ð\‚µž‚Ý‚·‚éB"
	#define STRCMD_C_COMMAND_SURRENDER					"/ƒMƒuƒAƒbƒv"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /ƒMƒuƒAƒbƒv [CharacterName] - Žw’è‚µ‚½·¬×¸À-‚Æ1:1 Œˆ“¬Žž‚ÉŽ©•ª‚ªƒMƒuƒAƒbƒv‚ð\‚µž‚Ý‚·‚éB"
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/•Ò‘àŒˆ“¬"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /•Ò‘àŒˆ“¬ [CharacterName] - •Ò‘à’·‚Ì‚ÝŽg—p‰Â”\BŽw’è‚µ‚½·¬×¸À- (•Ò‘à’·)‚É•Ò‘àŒˆ“¬‚ð\‚µž‚Ý‚·‚éB"
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/•Ò‘à‘ÎŒˆ"
	#define STRCMD_C_COMMAND_PARTYWAR					"/•Ò‘àí“¬"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/—·’cí“¬"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/—·’c‘ÎŒˆ"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /—·’c‘ÎŒˆ [CharacterName]  -—·’c’·‚Ì‚ÝŽg—p‰Â”\BŽw’è‚µ‚½·¬×¸À- (—·’c’·)‚É—·’cŒˆ“¬‚ð\‚µž‚Ý‚·‚éB"
	#define STRCMD_C_COMMAND_GUILDWAR					"/—·’cí‘ˆ"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/—·’cíƒMƒuƒAƒbƒv"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /—·’cíƒMƒuƒAƒbƒv - —·’c’·‚Ì‚ÝŽg—p‰Â”\B—·’c‘ÎŒˆisŽžAƒMƒuƒAƒbƒv‚·‚éB"
	#define STRCMD_C_COMMAND_NAME						"/ŒÄÌ"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /ŒÄÌ [CharacterName] [ŠK‹‰(2 ? 11)] - —·’c’·‚Ì‚ÝŽg—p‰Â”\BŽw’è‚µ‚½·¬×¸À-‚ðŽw’è‚µ‚½ŠK‹‰‚É•ÏX‚·‚é"
	#define STRCMD_C_COMMAND_WARP						"/Ü-Ìß"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/ƒXƒLƒ‹ƒLƒƒƒ“ƒZƒ‹"
	#define STRCMD_C_COMMAND_INITCHAT					"/Á¬¯Ä³¨ÝÄÞ³‰Šú‰»"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /Á¬¯Ä³¨ÝÄÞ³‰Šú‰» - Á¬¯Ä³¨ÝÄÞ³‚ð ‰Šú‰» ‚·‚é"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/Œˆ“¬ƒuƒƒbƒN"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /Œˆ“¬ƒuƒƒbƒN - 1:1 Œˆ“¬ƒuƒƒbƒN Ý’è‚ð On/Off ‚·‚éB"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/Žæ‚èˆø‚«ƒuƒƒbƒN"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /Žæ‚èˆø‚«ƒuƒƒbƒN - Žæ‚èˆø‚«ƒuƒƒbƒN Ý’è‚ð On/Off ‚·‚éB"
	#define STRMSG_C_050810_0001						"/windowclose"
	#define STRMSG_C_050810_0001_HELP					"format: /windowclose - “Á’è Ò¯¾-¼ÞÎÞ¯¸½‚ðŠJ‚©‚È‚¢‚æ‚¤‚É‚·‚éBŽ©“®ƒLƒƒƒ“ƒZƒ‹‚³‚ê‚éB"
	#define STRMSG_C_050810_0002						"/windowopen"
	#define STRMSG_C_050810_0002_HELP					"format: /windowopen - ‘SÒ¯¾-¼ÞÎÞ¯¸½‚ªŽg—p‚Å‚«‚éB"

// 2006-09-29 by cmkwon	
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"•â•½·Ù±²ÃÑ"

// 2010-06-15 by shcho&hslee ?EÃ½ºÅ?- ?E¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Êß-ÄÅ-±²ÃÑ"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM		"Êß-ÄÅ-¿¹¯Ä±²ÃÑ"

// 2006-11-17 by cmkwon, ??? ?? ƒQ?? ?? ??
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSyste"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/ŽžŠÔ§ŒÀ¼½ÃÑ"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /ŽžŠÔ§ŒÀ¼½ÃÑ [on|off] - ŽžŠÔ§ŒÀ¼½ÃÑ on/off‚ð Ý’è‚·‚éB"
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/—˜—pŽžŠÔ"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /—˜—pŽžŠÔ - ¡“úˆê“ú‚Ì¹Þ-ÑÚ‘±ŽžŠÔ‚ð•\Ž¦‚·‚é"

// 2007-10-06 by cmkwon, •›Žw“±ŽÒ 2?? ??‚ð ??? Ý’è - ??? ¨—Í?? ??? ???
//// 2006-12-13 by cmkwon	
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Žw“±ŽÒ"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"•›Žw“±ŽÒ"

// 2007-01-08 by dhjin	
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/ÎÞ-Å½½Ã-À½Îß²ÝÄ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/ÎÞ-Å½½Ã-À½Îß²ÝÄ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint‚ð DB‚É UPDATE"

// 2007-01-25 by dhjin	
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/ƒlƒbƒgƒJƒtƒF"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/ƒlƒbƒgƒJƒtƒF"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /ƒlƒbƒgƒJƒtƒF - Œ»ÝÚ‘±‚µ‚Ä‚¢‚éƒlƒbƒgƒJƒtƒF‚ÌÕ-»Þ-”‚ð•\Ž¦‚·‚é"

// 2007-10-06 by dhjin, •›Žw“±ŽÒ ?? ?? •ÏX?? ??
// 2007-02-13 by dhjin, •›Žw“±ŽÒ
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/•›Žw“±ŽÒ"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /•›Žw“±ŽÒ [CharacterName] - •›Žw“±ŽÒ Ý’è"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"•›Žw“±ŽÒ Ý’è‚ª ƒLƒƒƒ“ƒZƒ‹ ‚³‚ê‚Ü‚µ‚½B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"•›Žw“±ŽÒ‚ð ‚±‚êˆÈãÝ’è‚·‚é‚±‚Æ‚ª‚Å‚«‚Ü‚¹‚ñB"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s‚ð 1”Ô–Ú‚Ì•›Žw“±ŽÒ‚É Ý’è‚µ‚Ü‚µ‚½B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s‚ð 2”Ô–Ú‚Ì•›Žw“±ŽÒ‚ÉÝ’è‚µ‚Ü‚µ‚½B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s‚Ì–¼‘O‚Í‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s‚Í•›Žw“±ŽÒ‚É Ý’è ‚³‚ê‚Ä‚¢‚Ü‚·B"

// 2007-02-23 by dhjin, ??î•ñ	
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/‹’“_î•ñ"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /‹’“_î•ñ - Œ»Ý ‹’“_isî•ñ‚ð•\Ž¦‚·‚éB"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"is’†‚Ì‹’“_í‚ª‚ ‚è‚Ü‚¹‚ñB"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"‹’“_í‚ªis’†‚Å‚·B"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"is’nˆæ"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"ŠJŽnŽžŠÔ"

// 2007-03-29 by cmkwon	
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear All"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear All"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear All"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear All"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear All"

// 2007-03-30 by dhjin, µÌÞ»Þ-ÊÞ- Ó-ÄÞ Õ-»Þ- “o˜^
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0		"/Observerstart"		// 2007-03-30 by dhjin, ƒNƒ‰ƒCƒAƒ“ƒg??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1		"/µÌÞ»Þ-ÊÞ-ŠJŽn"			// 2007-03-30 by dhjin, ƒNƒ‰ƒCƒAƒ“ƒg??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0		"/Observerend"			// 2007-03-30 by dhjin, ƒNƒ‰ƒCƒAƒ“ƒg??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1		"/µÌÞ»Þ-ÊÞ-I—¹"			// 2007-03-30 by dhjin, ƒNƒ‰ƒCƒAƒ“ƒg??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_0			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1			"/µÌÞ»Þ-ÊÞ-"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP			"format: /µÌÞ»Þ-ÊÞ- [n] [CharacterName] ? CharacterNameÕ-»Þ-‚ð n‚Æ‚¢‚¤”Ô†‚É¾-ÌÞ‚·‚é"

// 2007-04-10 by cmkwon, ‘å‰ï»-ÊÞ? ??
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0			"/InitJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/‘å‰ï»-ÊÞ‰Šú‰»"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [”FØ”Žš] - ‘å‰ï»-ÊÞŒQ DB(atum2_db_20)‚ð ‰Šú‰» ‚·‚éB"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0		"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/‘å‰ï»-ÊÞŽQ‰ÁŽÒ"
// 2008-04-15 by cmkwon, ‘å‰ï»-ÊÞ(JamboreeServer)? ¼½ÃÑ ?? - ??? ?? ?? ???
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] ? Žw’è‚µ‚½·¬×¸À-‚ÌÃÞ-À‚ð ‘å‰ï»-ÊÞŒQ DB(atum2_db_20)‚ÉºËß-‚·‚éB"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] ? Žw’è‚µ‚½·¬×¸À-‚ÌÃÞ-À‚ð‘å‰ï»-ÊÞŒQ DB(atum2_db_20)‚Ì ŠY“– ¨—ÍºËß-‚·‚éB"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_1		"1_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_2		"2_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_3		"3_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_4		"4_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_5		"5_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_6		"6_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_7		"7_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_8		"8_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_9		"9_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_10		"10_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_11		"11_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_12		"12_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_13		"13_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_14		"14_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_15		"15_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_16		"16_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_17		"17_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_18		"18_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_19		"19_"

// 2007-04-17 by dhjin, ƒŒƒxƒ‹ƒ‰ƒ“ƒN? ?? ??
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"ŒP—û¶"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"ƒWƒ…ƒjƒA"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"´±-ÏÝ"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"³²Ý¸ÞÏÝ"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"´-½"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"ƒxƒeƒ‰ƒ“"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"ƒgƒbƒvƒKƒ“"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"³²Ý¸ÞºÏÝÄÞ"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"Ë-Û-"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ³¨ÝÄÞ³Ó-ÄÞ‹@”\’Ç‰Á -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA ? o—Í ?? ???
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"±Ø-Å Á-Ñ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0			"/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/±Ø-Å"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /±Ø-Å [2(BCU)|4(ANI)]- Œ»Ý ±Ø-Å is î•ñ‚ð •\Ž¦‚·‚éB"

// 2010. 06. 04 by hsLee ARENA ÀÎÇÇ´ÏÆ¼ °E? - 
// 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµE2ÂE³­ÀÌµµ Á¶Àý. (GM ¸úÓÉ¾EÃß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£ÃE) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµE2ÂE³­ÀÌµµ Á¶Àý. (GM ¸úÓÉ¾EÃß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£ÃE) )

// 2007-06-15 by dhjin, ŠÏí
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/ŠÏíŠJŽn"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /ŠÏíŠJŽn - ŠÏí‚ð ŠJŽn‚·‚éB"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/ŠÏíI—¹"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /ŠÏíI—¹ - ŠÏí‚ð I—¹‚·‚éB"

// 2007-06-22 by dhjin, WarPoint ’Ç‰Á
#define STRMSG_CS_COMMAND_WARPOINT_0				"/í‘ˆÎß²ÝÄiWPj"
#define STRMSG_CS_COMMAND_WARPOINT_1				"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /í‘ˆÎß²ÝÄiWPj [”’l 1`1000000] [|Õ-»Þ-È-Ñ] - í‘ˆÎß²ÝÄiWPj‚ð ’Ç‰Á‚·‚éB"

// 2007-06-26 by dhjin, ?Îß²ÝÄ ƒCƒxƒ“ƒg ?? ’Ç‰Á
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"í‘ˆÎß²ÝÄiWPj"

// 2007-07-11 by cmkwon, ±Ø-ÅÌÞÛ¯¸¼½ÃÑ ?? - –½—ßŒê ’Ç‰Á(/±Ø-ÅÌÞÛ¯¸, /±Ø-ÅÌÞÛ¯¸‰ðœ)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/±Ø-ÅÌÞÛ¯¸"
#define STRCMD_CS_COMMAND_ARENAFORBID_1				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /±Ø-ÅÌÞÛ¯¸ [character name] [|ŽžŠÔ(•ª)] - Arena ƒuƒƒbƒN ‚·‚é"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/±Ø-ÅÌÞÛ¯¸‰ðœ"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /±Ø-ÅÌÞÛ¯¸‰ðœ [character name] - Arena ƒuƒƒbƒN ‰ðœ ‚·‚é"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, —·’c Ï-¸ ?? ¼½ÃÑ ?? - ’Ç‰Á? ???
#define STRMSG_070802_0001				"—·’cÏ-¸“o˜^\‚µž‚Ý‚ªŠ®—¹‚µ‚Ü‚µ‚½B"
#define STRMSG_070802_0002				"R¸‚ÌŒãA“o˜^‚ªŠ®—¹‚µ‚Ü‚·B"
#define STRMSG_070802_0003				"‘I‘ð‚µ‚½%dŒÂ‚Ì—·’cÏ-¸‚ð‹–‰Â‚µ‚Ü‚·‚©H"
#define STRMSG_070802_0004				"—·’cÏ-¸‚È‚µ"
#define STRMSG_070802_0005				"—·’cÏ-¸‘Ò‹@"
#define STRMSG_070802_0006				"—·’cÏ-¸³í"
#define STRMSG_070802_0007				"—·’cÏ-¸´×-"

// 2007-08-24 by cmkwon, ½Ëß-¶-±²ÃÑ Žg—p‰Â”\/ƒuƒƒbƒN Ý’è ?? ’Ç‰Á - –½—ßŒê ’Ç‰Á
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/½Ëß-¶-Žg—p"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"‰Â”\"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"‹ÖŽ~"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format:/[½Ëß-¶-Žg—p|UseSpeaker|UseSpeaker][‰Â”\|‹ÖŽ~]-½Ëß-¶-±²ÃÑ Žg—p‚ð ƒuƒƒbƒN/‰ðœ ‚·‚é"

// 2007-08-27 by cmkwon, »-ÊÞ???? –½—ßŒê ’Ç‰Á(SCAdminTool?? SCMonitor? PrepareShutdown‚ð ?? ? ? ??)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/»-ÊÞÀÞ³Ý€”õ"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[»-ÊÞÀÞ³Ý€”õ|PrepareShutdown|PrepareShutdown] [Start|Release] - »-ÊÞ I—¹ €”õA‘S‚Ä‚ÌÕ-»Þ-‚ÌÚ‘±‚ð‹­§I—¹‚·‚é"

// 2007-08-30 by cmkwon, ‰ï‹cŽº ¼½ÃÑ ?? - –½—ßŒê ’Ç‰Á
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/“üê‹–‰Â"
#define STRCMD_CS_COMMAND_EntrancePermission_1				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[“üê‹–‰Â] [|CharacterName] - Žw“±ŽÒ‚Ì‚ÝŽg—p‰Â”\BŠY“– ·¬×¸À-‚ð“üê‹–‰Â ƒŠƒXƒg‚É’Ç‰Á‚·‚éB"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/“üê•s‰Â"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[“üê•s‰Â] [CharacterName] - Žw“±ŽÒ‚Ì‚ÝŽg—p‰Â?AŠY“– ·¬×¸À-‚ð ‰ï‹cŽº “üê‹–‰Â ƒŠƒXƒg‚©‚çíœ‚·‚éB"

// 2007-10-05 by cmkwon, ???‚ð ???? ????? ??
#define STRCMD_071005_0000					"%d“ú%dŽžŠÔ%d•ª%d•b", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d”N%dŒŽ%d“ú", Year, Month, Day
#define STRCMD_071005_0002					"%d”N%dŒŽ", Year, Month
#define STRCMD_071005_0003					"%dŒŽ%d“ú", Month, Day


// 2007-10-06 by cmkwon, •›Žw“±ŽÒ 2?? ??‚ð ??? Ý’è -
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"¨—Íí •›Žw“±ŽÒ 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"¨—Íí •›Žw“±ŽÒ 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"‘Ži—ßŠ¯"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"•›Ži—ßŠ¯"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"ŽQ–d‘’·"
#define STRCMD_ANI_INFLUENCE_LEADER						"‹c’·"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"•›‹c’·"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"ìí–{•”’·"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s ŠÍ’·"

// 2007-10-06 by dhjin, •›Žw“±ŽÒ ?? ?? •ÏX?? ??
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/EˆÊ•t—^1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /EˆÊ•t—^1 [CharacterName] - BCU : •›Ži—ßŠ¯A ANI : •›‹c’· Ý’è"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/EˆÊ•t—^2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /EˆÊ•t—^2 [CharacterName] - BCU : ŽQ–d‘’·AANI : ìí–{•”’·Ý’è"

// 2007-10-30 by cmkwon, ¨—Í? HappyHour ƒCƒxƒ“ƒg ?? - –½—ßŒê ?? ??? ??? ?? ?? ?? ?
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHour"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"ŠJŽn"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"I—¹"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHourƒCƒxƒ“ƒg [1(Normal)|2(BCU)|4(ANI)|255(All)] [ŠJŽn|I—¹] [isŽžŠÔ(’PˆÊ:•ª)]"

// 2007-10-30 by cmkwon, ¨—Í? HappyHour ƒCƒxƒ“ƒg ?? - ?? ?‚ð ??? ?
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"ˆê”Ê¨—Í"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"ÊÞ²¼ÞªÆ­-¨—Í"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"±-ØÝÄÝ¨—Í"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"‘S‘Ì‘ÎÛ"			// 2007-10-30 by cmkwon, ¨—Í? HappyHour ƒCƒxƒ“ƒg ?? - ’Ç‰Á? ?

// 2007-11-05 by cmkwon, WP ?? –½—ßŒê ?? - –½—ßŒê ’Ç‰Á
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP’Ç‰ÁÏ¯Ìß"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/í‘ˆÎß²ÝÄiWPj’Ç‰ÁÏ¯Ìß"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP’Ç‰ÁÏ¯Ìß [1(Normal)|2(BCU)|4(ANI)|255(All)] [AddWarPoint(1`)] - Œ»ÝÏ¯Ìß‚ÌŽw’è‚µ‚½¨—Í‚ÌÕ-»Þ-‚Éí‘ˆÎß²ÝÄiWPj‚ðŽx‹‹‚·‚éB"

// 2007-11-19 by cmkwon, ??¼½ÃÑ ±¯ÌßÃÞ-Ä - –½—ßŒê ’Ç‰Á
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/ƒwƒ‹ƒvŠJŽn"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/ƒwƒ‹ƒvŠJŽn"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /ƒwƒ‹ƒvŠJŽn [|ŽžŠÔ(’PˆÊ:•ª)] - ’ÁÃ ƒVƒXƒe? ŠJŽn"
#define STRCMD_CS_COMMAND_ENDCALLGM_0			"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/ƒwƒ‹ƒvI—¹"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/ƒwƒ‹ƒvI—¹"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /ƒwƒ‹ƒvI—¹ - ’ÁÃ ¼½ÃÑ I—¹"

// 2007-12-27 by cmkwon, ³²ÝÄÞ³Ó-ÄÞ‹@”\’Ç‰Á- STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW ’Ç‰Á
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, ???Ó-ÄÞ ?? ???? -
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, ƒAƒJƒEƒ“ƒgƒuƒƒbƒN/‰ðœ –½—ßŒê? ??? ¼½ÃÑ ?? - –½—ßŒê ’Ç‰Á
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/ƒuƒƒbƒN"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/ƒuƒƒbƒN‰ðœ"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, –½—ßŒê ’Ç‰Á(?? ?? ?? ???? ±²ÃÑ ?? -
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/±²ÃÑ‘S•”"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/±²ÃÑ’Ç‰Á‘S•”"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] ? Ú‘±‚µ‚½Õ-»Þ-‚Ì‚È‚©‚ÅŽw’è‚µ‚½¨—Í‚ÌÕ-»Þ-‚ÉŽw’è‚µ‚½±²ÃÑ‚ðŽx‹‹‚·‚éB"

// 2008-02-21 by dhjin, ±Ø-Å ?? - ±Ø-Å ’Ç‰Á –½—ßŒê
#define STRCMD_CS_COMMAND_ARENAMOVE_0						"/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/±Ø-ÅˆÚ“®"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0					"/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/‘ÎÛ»-ÊÞ•œ‹A"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP				"format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0				"/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/‘ÎÛ»-ÊÞ•œ‹A"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP				"format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0						"/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/±Ø-Å²ÍÞÝÄ"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/±Ø-Å²ÍÞÝÄ"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP					"format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0				"/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/±Ø-Å²ÍÞÝÄ‰ðœ"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/±Ø-Å²ÍÞÝÄ‰ðœ"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP			"format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ??? ±²ÃÑ ŒŸõ? ?????? ŒŸõ ?? ’Ç‰Á(K0000143) -
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"‘S±²ÃÑ—Þ"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - —·’c ?? ??	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"‘àˆõ"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"—·’c’·"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"•›—·’c’·"				// 2008-05-20 by dhjin, EP3 - —·’c ?? ??
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1‘å‘à’·"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1‘å‘àˆõ"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2‘å‘à’·"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2‘å‘àˆõ"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3‘å‘à’·"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3‘å‘àˆõ"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4‘å‘à’·"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4‘å‘àˆõ"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5‘å‘à’·"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5‘å‘àˆõ"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ??î•ñ
#define STRCMD_COMMAND_WAR_OPTION_0					"/•ê‘Díî•ñƒIƒvƒVƒ‡ƒ“"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ¨—ÍÏ-¸²ÍÞÝÄ
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/¨—ÍÏ°¸²ÍÞÝÄ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/¨—ÍÏ°¸²ÍÞÝÄ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [¨—Í 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/¨—ÍÏ°¸²ÍÞÝÄI—¹"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/¨—ÍÏ°¸²ÍÞÝÄI—¹"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ?? PC? IPî•ñ ??
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/È¯Ä¶ÌªØÛ-ÄÞÀ²Ñ"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ? 1440 Min"


// 2008-08-21 by dhjin, ˆê”Ê, ?? ƒAƒJƒEƒ“ƒg? •›Žw“±ŽÒ ?? ??
#define STRMSG_080821_0001				"‘I‘ð‚µ‚½·¬×¸À-‚ÉŠK‹‰‚ð”C–½‚Å‚«‚Ü‚¹‚ñB"


// 2008-09-09 by cmkwon, /¨—Í¢Š« –½—ßŒê ?? ƒŠƒXƒg? ??À²Ìß ’Ç‰Á -
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [Å‘ålˆõ] [0|Å¬ƒŒƒxƒ‹] [0|Å‘åƒŒƒxƒ‹] [1(B)|16(M)|256(A)|4096(I)] [ƒ†?ƒU?‚É‘—‚éƒƒbƒZ?ƒW] ? ”CˆÓ‚ÌŽw’è‚µ‚½¨—ÍAŽw’è‚µ‚½ƒŒƒxƒ‹‚Ìƒ†?ƒU?‚ÉƒCƒxƒ“ƒg?ƒbƒv‚Ö‚ÌˆÚ“®‚ð—v¿‚·‚é"

// 2008-09-09 by cmkwon, "/kick" –½—ßŒê ’Ç‰Á - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/ƒLƒbƒN"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - ŠY“– ·¬×¸À-‚ð ¹Þ-Ñ I—¹‚³‚¹‚éB"


// 2008-09-12 by cmkwon, "/–¼º" –½—ßŒê ’Ç‰Á -
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/–¼º"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /–¼º [ŒÂl–¼º] [—·’c–¼º] - Ú‘± ·¬×¸À-‚Ì–¼ºA·¬×¸À- —·’c –¼º‚ð ã‚°‚éB"

// 2008-12-30 by cmkwon, Žw“±ŽÒÁ­¯Ä§ŒÀ¶-ÄÞ -
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/Žw“±ŽÒ?ƒƒƒbƒg§ŒÀ‰ðœ"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /Žw“±ŽÒÁ¬¯Ä§ŒÀ‰ðœ[CharacterName]-Žw“±ŽÒÁ¬¯Ä§ŒÀ‚Ì‰ðœB"

// 2009-10-12 by cmkwon, ÌØ-½¶‚ÌíœˆÄ“K—p - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                       "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                       "/½À-Ä“sŽsÏ¯Ìß"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                              "format: /½À-Ä“sŽsÏ¯Ìß [2001|2002] [|CharacterName] - ŠY“–·¬×¸À-‚Ìˆê”Ê¨—ÍŽžA½À-Ä‚·‚é“sŽs‚ÌÏ¯Ìß‚ðŠY“–Ï¯Ìß(2001|2002)‚É•ÏX‚·‚éB"


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, ÃÖ´E·¹º§ »óÇâ¿¡ µû¸¥ Ãß°¡ »çÇ×(·¹º§º° °è±Þ) - °è±Þ¶E¹éºÎÀE ´E? Àå±º, ÃÑµ¶, Á¤º¹ÀÚ, ¼öÈ£ÀÚ, ÀE³ÀûÀ?
#define STRCMD_CS_CHARACTER_96_LEVEL_RANK "¾ÝÁ­Ø±Ý"
#define STRCMD_CS_CHARACTER_100_LEVEL_RANK "¶-ÈÙ"
#define STRCMD_CS_CHARACTER_104_LEVEL_RANK "ƒWƒFƒlƒ‰ƒ‹"
#define STRCMD_CS_CHARACTER_108_LEVEL_RANK "¶ÞÊÞÅ-"
#define STRCMD_CS_CHARACTER_112_LEVEL_RANK "ºÝ¸´½À"
#define STRCMD_CS_CHARACTER_116_LEVEL_RANK "¶Þ-ÃÞ¨±Ý"
#define STRCMD_CS_CHARACTER_120_LEVEL_RANK "Ú¼ÞªÝÀÞØ-"
#define STRCMD_CS_CHARACTER_XX_LEVEL_RANK "Šî–{"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, ¾Æ·¹³ª Á¾·E¸úÓÉ¾E¼öÁ¤

// 2014-05-16 by bckim, ¿µ¹® ¸úÓÉ¾EÃß°¡
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ¿µ¹® ¸úÓÉ¾EÃß°¡

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸úÓÉ¾EÃß°¡
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/¸ÊÀÌµ¿Á¦ÇÑ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /¸ÊÀÌµ¿Á¦ÇÑ [MapIndex] - ÇØ´E¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀ» ¼³Á¤ÇÔ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ¼³Á¤ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ÇØÁ¦ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]´Â Çã¿EÏÁE¾Ê´Â ¸Ê¹øÈ£ÀÔ´Ï´Ù."
// end 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸úÓÉ¾EÃß°¡

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Å¸ °èÁ¤ ¼¼·Âº¯°E
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/¨—Í•ÏX"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/¨—Í•ÏX"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /¨—Í•ÏX[ƒAƒJƒEƒ“ƒgUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ÆÄÆ¼¿EÁ¤º¸ º¸±E¸úÓÉ¾EÃß°¡
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/ƒtƒH-ƒ-ƒVƒ‡ƒ“ƒCƒ“ƒtƒHƒ-ƒVƒ‡ƒ“"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/ƒtƒH-ƒ-ƒVƒ‡ƒ“ƒCƒ“ƒtƒHƒ-ƒVƒ‡ƒ“"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /ƒtƒH-ƒ-ƒVƒ‡ƒ“ƒCƒ“ƒtƒHƒ-ƒVƒ‡ƒ“ [·¬×¸À-–¼] - ƒtƒH-ƒ-ƒVƒ‡ƒ“ƒCƒ“ƒtƒHƒ-ƒVƒ‡ƒ“ƒƒ“ƒo-ƒvƒŒƒCƒ„-‚Ìî•ñ  (ƒƒ“ƒo-‚ª¹Þ-Ñ‚ÉƒƒOƒCƒ“‚µ‚Ä‚¢‚é•K—v‚ª‚ ‚è‚Ü‚·)"
// End. 2013-11-19 by bckim, ÆÄÆ¼¿EÁ¤º¸ º¸±E¸úÓÉ¾EÃß°¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





