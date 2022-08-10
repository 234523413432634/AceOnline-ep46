// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - Konfiguriert das ment des Charakters"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [MapIndex] [|ChannelIndex] - Geht zu einem bestimmten Karten Channel"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Springt zu den angegebenenen Koordinaten der Karte"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Listet alle Benutzer un der aktuellen Karte (Maximal 20 Benutzer)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [character name] [map name] - Bewegt einen Charakter in eine gewählte Karte"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [monster name|item name] - Zeigt die Informationen über Monster oder Items in der Kette"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - Zeigt Questinformationen für Charakter"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [Quest Nummer]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [|item kind(0~53)] - Zeigt die ausgewählten Typen des Items"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [item kind(0~53)] -  Zusätzliche spezielle Itemtypen"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [from itemnum] ~ [to itemnum] - Zusätzliche besondere Items"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - Initialisiert den gesamten Status"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo - Zeigt Parteiinformationen"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /Time [|additional time(0~23)] - Verändert die aktuelle Zeit (nur die individuelle Zeit wird verändert)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Entscheidet welche Level in der Debugnachricht gezeigt werden."
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [monster number|monster name] [# of monsters] - Bringt Monster ('_'wird verwendet wenn ein Monstername ein Leerzeichen besitzt)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [level] - Fügt alle passenden Skills ein"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem - Fügt alle ausgewählten Items ein, ohne Skills und zählbare Items"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - Zusätzlich alle Waffen für den Gear ausrüstbar"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Entfernt alle nicht ausgerüsteten Items (ohne Skills)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [item number] [# of items] - Erworbene Items werden wie 1 Item behandelt, wenn [# of items] nicht eingefügt ist."
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [item number] [|# of items] - Lässt Items auf das Feld fallen."
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - Auflistung der Serverinformationen"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - Zeigt die Informationen der gesamten Karte"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Zeigt Informationen über die Karte der Channel auf der aktuellen Karte an"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - Nur für Tests"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [|Nummer der Standardmunition] [|Nummer der Sekundärmunition] - Munition nachladen"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [|character name] - Heilt HP, UTC, TANK aus 100%, Heile dich selbst ohne [character name]"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|character name] - HP, TUC, und TANK accounts für [decreasing quantity %], 50% wenn [decreasing quantity %] nicht eingefügt und der [Charaktername] nicht verfügbar ist steht es für den individuellen Charakter."
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - Wechselt zu einem normalen Account von einem Admin oder Game Master Mode"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Verändert von einem normalen Account zu einem speziellen Admin oder Game Master account"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible - Im Gamemaster oder Manager Mode kann kein Schaden genommen werden"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [Erhöht die Angriffskraft(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [variable] - Stellt (normale) Variable ein"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [|level] [|percentage of exp] [|character name] - Ändert das Level und den Prozentsatz der Exp. des Charakters"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible -  Unsichtbar für andere Charaktere"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - Nur für Tests"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Erfahrungspunkt"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"SeltenesItem"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"Ziel"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(minute)] - Event Set, Abbruch"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"Standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"Super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"Upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"Ziel"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [Standard|Super|Upgrade|Ziel]"
// 2008-02-14 by cmkwon,   
//	#define STRCMD_CS_COMMAND_CITYWAR					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"start"
//	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finish"
//	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /citywar [start|finish]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /stealth"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Alle Mitglieder der Gilde werden in eine gewählte Karte versetzt"
// start 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅÛ] - ¸®½º ½ýºÅÛ
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅÛ] - ¸®½º ½ýºÅÛ


// start 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ¼­¹ö Á¤º¸ º¸±â
// end 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö
			   
// start 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ¼­¹ö º¸ º¸±â
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î

// 2007-10-30 by cmkwon, ¼¼·º° ÇØÇö  ±¸Çö - ¸í·î Çü½Ä ¼öµÊ ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"start"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"end"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /happyEvent [start|end] [progress time(unit:min.)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - Command used in IMServer, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer für debugging"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - Auflistung aller Benutzer auf dem Server (unabhängig von der Karte)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - Registriert den Server um eine Nachricht an den Admin im Verlauf eines Events zu schreiben"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - Zeigt das gesagte Protokoll, welches der Client und der IM Server sendet und empfängt.*"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - Server shutdown"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - Geht auf eine ausgewählte Position des Charakters."
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [character name] - Ruft den ausgewählten Charakter"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [guild name] - Ruft die gesamte Gilde"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /comeonGuild [guild name] [map name]- Schickt die Gilde in eine gewählte Karte"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Wechselt zwischen Flüstern erlauben und nicht erlauben"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Zeigt Informationen über die Gilde an"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"clear"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"rain"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"snow"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"cloudy"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"foggy"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"whole"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Kontrolliert das Wetter"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [Spielername] [Zeit(min.)] - Chat verbieten"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [time(min.)] - Beendet den verbotenen Chat"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - Liste der möglichen Befehle werden angezeigt"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - BonusStat erhöhen"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /setPassword [AccountName] [Passwort]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /rollbackPassword [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [Kette wird verschlüsselt]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /blockAccount [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /releaseAccount [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /blockedList"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Nur gehörig zum Mgame Server!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Bitte gib den Server-Login-Namen ein"
	#define STRCMD_CS_COMMON_DB_0002 "Bitte gib das Server-Login-Passwort ein"
	#define STRCMD_CS_COMMON_DB_0003 "Bitte gib den DB-Login-Namen ein"
	#define STRCMD_CS_COMMON_DB_0004 "Bitte gib das Server-Login-Passwort ein"

	#define STRCMD_CS_COMMON_MAP_0000 "Fest programmiertes Teil: Ignoriere Nummer 1 Warpziel in der 0101 Karte, einfacher Weg zum Löschen von Karteneditor muss gefunden und entfernt werden!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "KARTE: %04d, m_DefaultWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Fest programmiertes Stück: Ignoriere Warp Ziel Nummer 1 in der 0101 Karte, einfacher Weg zum Löschen vom Karteneditor muss gefunden und entfernt werden!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "KARTE: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] Ruf Monster[%8d] Ruf Zeit[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] Ruf Monster[%8d] Ruf Zeut[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Gesamt Monster Zahl : [%4d] <== Einschließlich Objekt Monster\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Download Datei Fehler"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Dateierstellungsfehler"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Download-Datei-Lesefehler"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%dTag%dStunde%dMinute%dSekunde"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Schrein"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Reserve"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Reserve"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrator"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Gast"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Zur Demo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Alle Rassen"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Unbekannte Rasse"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Kein Name"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Kadett"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3. Flieger"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2. Flieger"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1. Flieger"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3. Wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2. Wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1. Wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3. Anführer"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2. Anführer"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1. Anführer"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3. As"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. As"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1. As"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Luft-Kommodore"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vize-Luftmarschall"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"General Leutnant"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Voller General"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Automatischer Typ"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Valkan-Typ"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Dualisten-Typ"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Kanonen-Typ"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Gewehr-Typ"
	#define STRCMD_CS_ITEMKIND_GATLING				"Gatling-Typ"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Raketenwerfer-Typ"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Massenantriebs-Typ"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Raketen-Typ"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Raketen-Typ"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Bündel-Typ"

	#define STRCMD_CS_ITEMKIND_MINE					"Minen-Typ"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Schild-Typ"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Dummy-Typ"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Reparatur-Typ"
	#define STRCMD_CS_ITEMKIND_DECOY				"Köder-Typ"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Verteidigungs-Ausrüstungs-Typ"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Ausrüstungs-Unterstützungs-Item"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Energie-Typ"
	#define STRCMD_CS_ITEMKIND_INGOT				"Mineral-Typ"
	#define STRCMD_CS_ITEMKIND_CARD					"Standard Karten-Typ"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Upgradekarten-Typ"
	#define STRCMD_CS_ITEMKIND_TANK					"Panzer-Typ"
	#define STRCMD_CS_ITEMKIND_BULLET				"Kugel-Typ"
	#define STRCMD_CS_ITEMKIND_QUEST				"Quest Item-Typ"
	#define STRCMD_CS_ITEMKIND_RADAR				"Radar-Typ"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Computer-Typ"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Glücksspielkarten-Typ"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Upgrade-Löschungs-Verhinderungskarten-Typ"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Blaster-Typ"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Railgun-Typ"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Unbegrenzer Zusatz"		// 2006-03-17 by cmkwon, »ç¿ë½ð£ÀÌ <¿µ¿ø>ÀÎ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Zeitlimit-Zusatz"		// 2006-03-17 by cmkwon, »ç¿ë½ ½ð£ ÇÑÀÌ ÀÂ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Alle Waffen"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Standardwaffe"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Kugel-Typ Standardwaffe"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Tank-Typ Standardwaffe"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Sekundärwaffe"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Kugel-Typ Sekundärwaffe"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Schild-Typ Sekundärwaffe"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Angriffs Skill"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Verteidigungs Skill"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Unterstützungs Skill"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Attributs Skill"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item für Typ 1 Monster"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Monster Maschinengewehr-Typ (1-1Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Monster Strahl-Typ (1-2-Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Attackiere alle Monster"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item für Typ 2 Monster"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Monster Rakete (2-1Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Monster Raketen-Typ (2-1Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Monster Bündel-Typ (2-1Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Monster Minen-Typ (2-1Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Monster Schild-Typ (2-2Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Monster Dummy-Typ(2-2Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Monster Reparatur-Typ (2-2Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Monster Fallen-Typ (2-2Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Monster Feuer-Typ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Monster Crash Strahlen Möglichkeits-Typ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Monster gerade Bomben-Typ"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Unbekanntes Item"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Unbekannte Flugzelle"

	#define STRCMD_CS_STAT_ATTACK_PART				"Angriff"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Verteidigung"
	#define STRCMD_CS_STAT_FUEL_PART				"Treibstoff"
	#define STRCMD_CS_STAT_SOUL_PART				"Skill"
	#define STRCMD_CS_STAT_SHIELD_PART				"Schild"
	#define STRCMD_CS_STAT_DODGE_PART				"Ausweichen"
	#define STRCMD_CS_STAT_BONUS					"Bonus Stats"
	#define STRCMD_CS_STAT_ALL_PART					"Alle Stats"
	#define STRCMD_CS_STAT_UNKNOWN					"Unbekannter Stat"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Freier Typ"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Angriffstyp"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-type"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Angriffsart"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Bewegungsart"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Angriffstyp"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Schildtyp"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Verteidigungsart"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Unterstützungs Typ"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¼¼·º° ÇØÇö  ±¸Çö - ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Vatallus Föderationsarmee"

	#define STRCMD_CS_POS_PROW						"Radar Ort (Oben mitte)"
	#define STRCMD_CS_POS_PROWIN					"Computer (Mitte links)"
	#define STRCMD_CS_POS_PROWOUT					"Standardwaffe (Oben links)"
	#define STRCMD_CS_POS_WINGIN					"Nicht verwendet (Mitte rechts)"
	#define STRCMD_CS_POS_WINGOUT					"Fortgeschrittene Waffe (Oben Rechts)"
	#define STRCMD_CS_POS_CENTER					"Panzerung (Mitte)"
	#define STRCMD_CS_POS_REAR						"Motor (Unten Mitte)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_ATTACHMENT				"ºÎÂø¹°(ÈÌ ¿ìÃø-¿¬·áÅÊ|ÄÁÅ×À)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Anbauteil (Rechte Heckseite - Treibstofftank | Container)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_PET						"»ç¿ë¾ÈÇÔ(ÈÌ ÁÂÃø)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Nicht nutzbar (Linke Heckseite)"

	#define STRCMD_CS_POS_PET						"Partner"

    #define STRCMD_CS_HIDDEN_ITEM					"Versteckte Position"		// 2011-09-20 by hskim, ÆÊ ½ýºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

	#define STRCMD_CS_POS_INVALID_POSITION			"Schwebender Ort"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Inventar-Ort"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/QuestComplete"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /QuestComplete [|QuestIndex]"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/NationRatio"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /NationRatio"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/ChangeNation"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /ChangeNation [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMon"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [Monstername|Monsternummer]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ× -  ó¸® ¹Î 
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Member"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"Flight brigade commander"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1st battalion commander"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1st battalion member"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2nd battalion commander"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2nd battalion member"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3rd battalion commander"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3rd battalion member"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4th battalion commander"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4th battalion member"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5th battalion commander"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5th battalion member"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /Noticeboard [|Duration(unit:min) [Notice details] - Fügt eine Nachricht zu dem öffenltlichen elektronischen Notizboard für eine bestimmte Zeit hinzu."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - Entfernt eine bestimmte Nachricht vom elektronischen Notizboard."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Einfluss Anführer"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Einfluss Stellvertreter"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Einfluss Leder"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Einfluss Event"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Erhöht die Abgabe einer bestimmten Nation"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [Details der Supportanfrage] - Supportanfrage an GM absenden"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [|Number(1~10)] - Prüfe die Nummer der Support Anfragen Liste durch den GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Numner(1~10)] - Bringt die Supportanfrage mit der angegebenen Nummer zum GM (und wird vom Server gelöscht)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"
// 2008-09-09 by cmkwon, /¼¼·¼Ò ¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀÔ á - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnNation [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [MAX_USER] [0|Min-level] [0|Max-level] [message to users] - Summons all specified level users in nation with a message."

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Gibt ein Item an alle Mitglieder einer Nation in der aktuellen Karte."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Farb Item"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯¥ Çö ¹æ½ÄÀÌ ´£´Ù
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ¹¹(English):	MM-DD-YYYY HH:MM:SS
	// º£³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - Zeigt gleiche Userlevel Verteillungen"	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Chancen-Item"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Markierung"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// ¶óÀ­¸¸ »ç¿ëÇÂ ¸í·î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [CharacterName] - Anfrage an einen ausgewählten Charakter zum 1:1 Chatting."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Startet Sprachchat zwischen Formationsmitgliedern. Nur vom Formationsführer verwendbar."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - Beendet Sprachchat zwischen Formationsmitgliedern. Nur vom Formationsführer verwendbar."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Beginne Sprachchat zwischen Brigademitgliedern, Nur vom Birgadeführer verwendbar."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcall - Starte Sprach Chatt zwischen Brigademitgliedern. Nur vom Brigadeführer verwendbar."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Beendet Brigade Formation, oder normales Chatting."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [CharacterName] - Anfrage für PvP für einen gewählten Charakter."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [CharacterName] -  Gibt einen PvP Kampf mit dem ausgewählten Charakter auf."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [CharacterName] - Anfrage an einen ausgewählten Charakter(Formationsanführer) zum Formations PvP. Nur vom Formationsführer verwendbar."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [CharacterName] -  Anfrage an einen ausgewählten Charakter(Brigade Führer) zum Brigade PvP. Nur vom Brigade Führer verwendbar."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  Aufgabe bei einem Brigaden-PvP-Kampf. Nur vom Brigadenführer verwendbar."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [CharacterName] [class(2 ~ 11)] - Beendet die Stellung eines gewählten Charkters. Nur vom Brigadenführer verwendbar."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  Lädt das Chat Fenster neu"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - An/Aus Stellt die PvP-Absage-Einstellungen ein"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  An/Aus Stellt die Handels-Absage-Einstellungen ein"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Verhindert Nachrichten-Popups. Nachrichten werden automatisch beendet."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Erlaube Nachrichten-Popups."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Unterstützungs-Skill-Item"

// 2010-06-15 by shcho&hslee Æê½ýºÅÛ - Æê ¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Partner-Item"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner-Slot-Item"		// 2011-09-01 by hskim, ÆÊ ½ýºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£³² Çç °ÔÀÓ ½ð£ °ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"Ein"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"Aus"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - Dieser Befehl wird verwendet um das Zeit Limit an oder aus zu schalten."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Dieser Befehl zeigt die heute gespielte Zeit."

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ  ´£°Ô ¼³ - ¾¡¿¡ ¼¼·º°·Î ´£°Ô ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint update zur DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang Benutzer Zählungen"

// 2007-10-06 by dhjin, ºÎÁöµµÀÚ ¼±Ãâ ¹æ¹ý º¯°æ·Î ¼ö
// 2007-02-13 by dhjin, ºÎÁöµµÀÚ
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /Subleader [CharacterName] - Setting subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR		"Subleader setting has been cancelled."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0			"No more subleaders can be set."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1			"%s has become the first subleader."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2			"%s has become the second subleader."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10			"%s does not exist."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20			"%s is already a subleader."

// 2007-02-23 by dhjin, °¸
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - Dies zeigt den Status des momentanen Fortschritts an Strategiepunkten."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"Es ist momentan kein Strategiepunkte-Krieg im Gange."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Strategiepunkt Krieg aktiv."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Fortschritts Ort"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Start Zeit"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear gesamt"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear gesamt"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear gesamt"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear gesamt"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear gesamt"

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [CharacterName] - Charaktername speichere Benutzer bei Index n"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·Ã
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Initialisiere Jamboree Server DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Der ausgewählte Charakter wird auf die Jamboree Server DB dupliziert(atum2_db_20)."
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_1  "1_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_2  "2_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_3  "3_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_4  "4_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_5  "5_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_6  "6_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_7  "7_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_8  "8_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_9  "9_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_10  "10_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_11  "11_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_12  "12_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_13  "13_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_14  "14_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_15  "15_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_16  "16_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_17  "17_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_18  "18_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_19  "19_"

// 2007-04-17 by dhjin, ·¹º§ ·©¿¡ °üÇÑ µî±Þ
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Lehrling"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Pilot"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Wingman"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Veteran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Wing Commander"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Held"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGruppenName"

// 2007-05-23 by dhjin, ARENA ÆÀ Ãâ·Â °ü·Ã ½º¸µ
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Kann das Arenateam nicht finden."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)]- Zeigt den momentanen Fortschritt in der Arena."

// 2010. 06. 04 by hsLee ARENA ÀÎÇÏ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-Beginnt das Zusehen."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Beendet das Zusehen."

// 2007-06-22 by dhjin, WarPoint á
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Fügt Kriegspunkte hinzu."

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎ  °ü·Ã á
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"KriegsPunkt"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [character name] [|Time(minutes)] - Arena betreten verbieten"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [character name] - Arenaverbot aufheben"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Brigadenzeichen wurde erfolgreich registriert."
#define STRMSG_070802_0002    "Registrierung ist nach dem Sortierprozess abgeschlossen."
#define STRMSG_070802_0003    "Akzeptierst du %d das ausgewählte Zeichen?"
#define STRMSG_070802_0004    "Kein Brigade-Zeichen-Status"
#define STRMSG_070802_0005    "Brigadenzeichen im Wartestatus"
#define STRMSG_070802_0006    "Brigadenzeichen im normalen Status"
#define STRMSG_070802_0007    "Brigadenzeichen Statusfehler"

// 2007-08-24 by cmkwon, ½ºÇÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³ ±â´É á - ¸í·î á
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Einschalten"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Verbieten"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Erlaube/Verbiete die Verwendung des Lautsprecher-Items"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Veröffentlichung"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - Bereite Server-Shutdown vor, trenne alle Benutzer."

// 2007-08-30 by cmkwon, Àë ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [Spielername]? Kann nur von Leitern genutzt werden. Fügt den angegebenen Spieler zur Eintrittsliste des Konferenzraumes hinzu."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[EntrancePermissionDeny] [Spielername] ? Kann nur von Leitern genutzt werden. Dies löscht den angegebenen User von der Eintrittsliste des Konferenzraumes."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d Tag(e) %d Stunde(n) %d Minute(n) %d Sekunde(n)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d Jahr %d Monat %d Tag", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d Jahr %d Monat", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d Monat %d Tag", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Unteranführer 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Unteranführer 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Major General"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Stellvertretender Kommandeur"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Stabsanführer"
#define STRCMD_ANI_INFLUENCE_LEADER						"Anführer"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vize-Präsident"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Strategischer Direktor"
#define STRCMD_OUTPOST_GUILD_MASTER						"Cpt. %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [CharacterName] - BCU : set BCU Nation 1st sub-leader name, ANI : set ANI Nation 1st sub-leader name"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [CharacterName] - BCU : setze BCU Nation 2nd sub-leader name, ANI : setze ANI Nation 2nd sub-leader name"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Start"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Ende"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyEvent [255(AllNation)|0(NormalNation)|2(VCN)|4(ANI)] [Start|End] [Fortschritszeit(Unit:Minute)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Normale Nation"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"AllNation"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Die Benutzer der ausgewählten Nation in der aktuellen Karte erhalten alle einen Kriegspunkt"

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - Starte Anfragesystem"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Beendet das Anrufsystem"

// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW á
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, µµ¿ì¸ðµå »óÅÂ ÀúÀåÇâ - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, °è º/ÇØ ¸í·î·Î °¡´ÉÇÑ ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ¸í·îá(¼ÓÁßÀÎÀú¸ÆÀÌÅÛÁö±Þ- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Nummer] [# der Items] - Eingeloggte User der gewählten Nation erhalten das vorgesehene Item"

// 2008-02-21 by dhjin, ¾¹³ªÅëÇÕ- ¾¹³ªá¸í·î
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLAU)|4(ROT)|6(BLAU UND ROT)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [RaumNummer]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [RaumNummer]"

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °ö½Ã ¹º¿¡¼­ °ö ±â´É á(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Alle Sorten"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Mitglied"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Flugbrigadenanführer"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Co-Brigadenanführer"				// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"Kommandant des 1. Bataillons"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1. Battaillon Mitglied"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"Kommandant des 2. Bataillons"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2. Battaillon Mitglied"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"Kommandant des 3. Bataillons"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3. Battaillon Anführer"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"Kommandant des 4. Bataillons"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4. Battaillon Mitglied"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"Kommandant des 5. Bataillons"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5. Battaillon Mitglied"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ÀüÀ
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ¼¼·¸¶ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [Nation 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ¹ PC¹æ IPº¸ ·ù
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ÀÝ, ¼ö °èÀÇ ºÎÁöµµÀÚ Àí ÇÑ
#define STRMSG_080821_0001				"Der Rang kann nicht an den ausgewählten Spieler vergeben werden."


// 2008-09-09 by cmkwon, /¼¼·¼Ò ¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀÔ á - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [Maximale Anzahl der Personen] [0|Minumales Level] [0|Maximales Level] [1(B)|16(M)|256(A)|4096(I)] [Nachricht an den User] - Auftrag an die Nation, User des Levels sollen sich zur Eventmap begeben."

// 2008-09-09 by cmkwon, "/kick" ¸í·î á - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Beseitige den angegebene Charakter aus dem Spiel."


// 2008-09-12 by cmkwon, "/¸" ¸í·î á - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Ruhm"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Ruhm"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"Format:  /Ruhm [Persönlicher Ruhm] [Ruhm der Brigade] - Vergrößert den Ruhm des Charakters und seiner Brigade."

// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"Format: /ReleaseLeaderChatBlock [Charactername] - Die Chatbeschränkung des Anführers wird aufgehoben."

// 2009-10-12 by cmkwon, ½º °Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|Charaktername] - Wähle die Heimatstadt deines Charakters auf 2001 oder 2002, wenn die Nation eingestellt wurde."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, Ãë ·¹º§ »óÇ µû¸¥ á »çÇ×(·¹º§º° °è±Þ) - °è±æ(¹éºÎÀå, ´ë·É, À, ö, º¹ÀÚ, ¼öÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Hauptgefreiter"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Oberstleutnant"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "Generalleutnant"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Generalmajor"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Eroberer"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Hüter"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legende"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Standard"

#define       STRCMD_CS_COMMAND_ENDARENA					"/endarena"				// 2012-09-24 by jhseol, ¾¹³ª ·á ¸í·î ¼ö

// 2014-05-16 by bckim, ¿µ¹® ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ¿µ¹® ¸í·É¾î Ãß°¡

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀ¥ ¸Ê ¿öÇÁÇÑ - ¸í·î Ã¡
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/¸ÊÀ¿ÇÑ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /¸ÊÀ¿ÇÑ [MapIndex] - Çç ¸ÊÀÇ ¿öÇÁ ÇÑ ¼³ÇÔ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]¸ÊÀÇ ¿öÇÁ ÇÑÀÌ ¼³ µú½Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]¸ÊÀÇ ¿öÇÁ ÇÑÀÌ ÇØ µú½Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]´Â Çã¿ëÇÏÁö ¾Â ¸øÀÙ."
// end 2012-11-29 by jhseol, OXÀ¥ ¸Ê ¿öÇÁÇÑ - ¸í·î Ã¡

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ÆÄ¿ø º¸ º¸±â ¸í·î Ã¡
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] -Informationen über die Mitglieder der Formation des Spielers (Mitglieder müssen im Spiel eingeloggt sein)"
// End. 2013-11-19 by bckim, ÆÄ¿ø º¸ º¸±â ¸í·î Ã¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





