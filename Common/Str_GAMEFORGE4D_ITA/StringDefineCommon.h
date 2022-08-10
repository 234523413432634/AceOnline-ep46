// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"formato: /ment [|String] - Setta il ment del personaggio"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"formato: /move [IndiceMappa] [|IndiceCanale] - Ti sposta nel canale della mappa specifica"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"formato: /coordinate [X] [Y] - Muove nel punto specifico della mappa"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"formato: /list - Elenco dei giocatori presenti nella mappa (massimo 20 utenti)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"formato: /senduser [nome personaggio] [nome mappa] -  Sposta il personaggio nella mappa specifica"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"formato: /info [nome mostro|nome oggetto] - Mostra le info riguardo i mostri od oggetti insulsi nella stringa"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"formato: /quest - Mostra le ifno delle quest dei personaggi"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"formato: /delQuest [quest n.]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"formato: /itemKind [|tipo di oggetto(0-53)] - Mostra uno specifico tipo di oggetto"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"formato: /insertItemKind [tipo di oggetto(0~53)] - Aggiunge alcuni specifici oggetti"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"formato: /insertItemNumRange [da itemnum] ~ [a itemnum] - Aggiunge oggetti specifici"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"formato: /initStatus - Avvia l'intero stato"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"formato: /partyInfo - Mostra le info del gruppo"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"formato: /Time [tempo addizionale(0~23)] - Cambia il tempo attuale"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"formato: /string [0~5] - Decidi i livelli mostrati dal messaggio di debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"formato: /summon [numero mostro|nome mostro] [# di mostri] - Richiama mostri ('_' è usato se il nome dei mostri include degli spazi)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"formato: /allSkill [livello] - Inserisci tutte le abilità di livello"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"formato: /allItem - Inserisce tutti gli oggetti specifici escludendo abilità ed oggetti contabili"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"formato: /allWeapon - Aggiunge le armi per il tuo Equipaggiamento"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"formato: /delAllItem - Elimina tutti gli oggetti equipaggiati (escluso le abilità)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"formato: /item [numero oggetto] [# di oggetti] - Acquisisci oggetti, appare 1 solo oggetto quando [# di oggetti] non è determinato"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"formato: /dropItem [numero oggetto] [|# di oggetti] - Drop degli oggetti in campo"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"formato: /server - Lista delle Info dei Server"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"formato: /serverMap - Mostra le info di tutte le mappe"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"formato: /channelInfo - Mostra le informazioni delle mappe in quella presente"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"formato: /dbg - Solo per test"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"formato: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"formato: /chargeBullet [|no. di Pallottola di Primo tipo] [|no. di Pallottola di Secondo tipo] - Ricariche Pallottole"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"formato: /repairAll [|nomepersonaggio] - Ripara HP, UTC, Carburante al 100%, Ripristinarti [nome personaggio]"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|character name] - HP, UTC, and FUEL accounts for [decreasing quantity %], 50% if [decreasing quantity %] is not inputted, and if [character name] is not present it stands for the individual's character"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"formato: /normale - Cambia l'account da Admin o GameMaster a utente normale"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"formato: /specialize - Cambia un normale account in Admin o GameMaster"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"formato: /invincible - Come un game master o modalità manager, nessun danno subìto"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"formato: /powerUp [Incrementa potenza offensiva(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"formato: /setVariable [variable] - aggiusta le variabili (normali)"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"formato: /level [|livello] [|percentuale di esperienza] [|nome personaggio] - Aggiusta il livello e la percent. di esperienza del personaggio"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invinsible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"formato: /invisible - Invisibile dagli altri personaggi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"formato: /msgf - Solo per test"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"exppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"oggeto raro"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"finito"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"formato: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finito] [tempo(minuto)] - stabilisci evento, cancella"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"aggiornato"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finito"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"formato: /premium [standard|super|upgrade|finish]"
// 2008-02-14 by cmkwon,   
//	#define STRCMD_CS_COMMAND_CITYWAR					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"start"
//	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finish"
//	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /citywar [start|finish]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"formato: /stealth"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Tutti i membri della gilda sono portati nella specifica mappa"
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"formato: /testi - IMServer per il debug"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"formato: /who [|# of users] - Elenca tutti gli utenti presenti nel server (relativi alla mappa)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"formato: /registerAdmin - Registra il server per inviare un messaggio all'Amministratore durante un evento"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"formato: /msgi - Mostra tutti i protocolli che un client e il IM server manda e riceve."
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"formato: /serverDown [certified no.] - Server shutdown"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [Nome Personaggio]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"formato: /go [nome personaggio] - Ti sposta nella posizione specifica del personaggio"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"formato: /comeon [nome personaggio] - Richiama un personaggio specifico"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"formato: /comeonGuild [nome gilda] - Richiama l'intera gilda"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"formato: /sendGuild [nome gilda] [nome mappa] - Manda la gilda in una specifica mappa"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"formato: /whisperChat - Alterna tra il blocco e il permesso di sussurrare"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"formato: /guildInfo - Mostra le info della gilda"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"chiaro"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"pioggia"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"neve"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"nuvoloso"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"nebbioso"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"intero"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Controls the weather"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"formato: /forbidChat [nome personaggio] [tempo(min.)] - Proibisci chat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"formato: /releaseChat [tempo(min.)] - Annullamento divieto chat"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"formato: /? - Mostra la lista dei comandi"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"formato: /BonusStat [Conta di Bonus] [|nome personaggio] - Incrementa Statistiche Bonus"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"formato: /setPassword [NomeAccount] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"formato: /rollbackPassword [NomeAccount]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"formato: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [stringa che verrà codificata]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"formato: /blockAccount [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"formato: /releaseAccount [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"formato: /blockedList"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Relativo solo al server Mgame!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Inserisci il nome di login del server"
	#define STRCMD_CS_COMMON_DB_0002 "Inserisci la password di login del server"
	#define STRCMD_CS_COMMON_DB_0003 "Per piacere insierisci DB log nel nome"
	#define STRCMD_CS_COMMON_DB_0004 "Per piacere inserisci DB log nella password"

	#define STRCMD_CS_COMMON_MAP_0000 "Hard coded part: Ignore number 1 warp target at 0101 map, easy way to delete from map editor need to be found and needs to be deleted!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAPPA: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Hard coded part: Ignore number 1 warp target at 0101 map, easy way to delete from map editor need to be found and needs to be deleted!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAPPA: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Total Monster Count : [%4d] <== Including object monster\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Errore file Download"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Errore creazione file"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Errore di lettura file download"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%dgiorno%dora%dminuto%dsecondo"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"normale"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Riserva"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Riserva"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Amministratore"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Gamemaster"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Visitatore"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Per demo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Tutte Razze"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Razza Sconosicuta"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Nessun nome"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Cadetto"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3° Uomo d'Aria"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2° Uomo d'Aria"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1° Uomo d'Aria"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3° Uomo d'Ala"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2° Uomo d'Ala"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1° Uomo d'Ala"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3° Capo"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2° Capo"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1° Capo"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3° Asso"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. As"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1° Asso"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Commodoro-Aria"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vice-Maresciallo d'Aria"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Tenente Generale"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Generale Assoluto"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Tipo Automatico"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Tipo di Valkan"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Tipo Dualista"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Tipo di Cannone"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Tipo di Fucile"
	#define STRCMD_CS_ITEMKIND_GATLING				"Gatling type"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Tipo di Lanciagranate"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Mass drive type"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Tipo di Razzo"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Tipo di Missile"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Tipo Fascio"

	#define STRCMD_CS_ITEMKIND_MINE					"Mine type"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Tipo di Scudo"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Tipo Manichino"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Tipo Fissatore"
	#define STRCMD_CS_ITEMKIND_DECOY				"Tipo Richiamo"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Tipo di equipaggiamento difensivo"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Tipo di Equipaggiamento di Supporto"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Tipo di Energia"
	#define STRCMD_CS_ITEMKIND_INGOT				"Tipo di Minerale"
	#define STRCMD_CS_ITEMKIND_CARD					"Tipo di Card Standard"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Tipo di Card Incanto"
	#define STRCMD_CS_ITEMKIND_TANK					"Tipo di Serbatoio"
	#define STRCMD_CS_ITEMKIND_BULLET				"Tipo di Pallottola"
	#define STRCMD_CS_ITEMKIND_QUEST				"Tipo di Oggetto Quest"
	#define STRCMD_CS_ITEMKIND_RADAR				"Tipo di Radar"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Tipo di Computer"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Gamble card type"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Enchant Delete Prevention Card type"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Tipo Blaster"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Rail gun type"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Accessorio Illimitato"		// 2006-03-17 by cmkwon, »ç¿ë½ð£ÀÌ <¿µ¿ø>ÀÎ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Accessorio Tempo Limite"		// 2006-03-17 by cmkwon, »ç¿ë½ ½ð£ ÇÑÀÌ ÀÂ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Tutte le Armi"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Arma Standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Bullet type Standard Weapon"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Fuel type Standard Weapon"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Arma Avanzata"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Tipo di proiettile per arma avanzata"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Shield type Advanced Weapon"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Abilità di Attacco"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Abilità di Difesa"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Abilità di Supporto"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Abilità di Attributo"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item for 1 type monster"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Monster machine gun type(1-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Monster beam type(1-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Attacca tutti i mostri"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item for 2 type monster"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Monster rocket (2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Monster Missile type(2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Monster Bundle type(2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Monster Mine type(2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Monster shield type(2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Monster dummy type (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Monster Fixer type(2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Monster Decoy type(2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Monster Fire type"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Monster crash possible beam type"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Monster straight bomb type"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Oggetto Sconosciuto"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Cellula Sconosciuta"

	#define STRCMD_CS_STAT_ATTACK_PART				"Attacco"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Difesa"
	#define STRCMD_CS_STAT_FUEL_PART				"Carburante"
	#define STRCMD_CS_STAT_SOUL_PART				"Spirito"
	#define STRCMD_CS_STAT_SHIELD_PART				"Scudo"
	#define STRCMD_CS_STAT_DODGE_PART				"Evasione"
	#define STRCMD_CS_STAT_BONUS					"Bonus stat"
	#define STRCMD_CS_STAT_ALL_PART					"Tutte Stat"
	#define STRCMD_CS_STAT_UNKNOWN					"Stat sconosciute"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Tipo Libero"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Tipo di Attacco"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-tipo"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Tipo di Attacco"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Tipo di Agilità"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Tipo di Attacco"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Tipo di Scudo"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Tipo di Difesa"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Tipo di Supporto"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¼¼·º° ÇØÇö  ±¸Çö - ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Esercito della Federazione Vattallus"

	#define STRCMD_CS_POS_PROW						"Radar location(Top center)"
	#define STRCMD_CS_POS_PROWIN					"Computer(Center left)"
	#define STRCMD_CS_POS_PROWOUT					"Standard Weapon(Top left)"
	#define STRCMD_CS_POS_WINGIN					"Not being used(Center right)"
	#define STRCMD_CS_POS_WINGOUT					"Advanced Weapon(Top right)"
	#define STRCMD_CS_POS_CENTER					"Armor(Center middle)"
	#define STRCMD_CS_POS_REAR						"Engine(Bottom middle)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_ATTACHMENT				"ºÎÂø¹°(ÈÌ ¿ìÃø-¿¬·áÅÊ|ÄÁÅ×À)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessorio (lato destro posteriore - tanica per carburante | container)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_PET						"»ç¿ë¾ÈÇÔ(ÈÌ ÁÂÃø)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Inutilizzabile (lato sinistro posteriore)"

	#define STRCMD_CS_POS_PET						"Compagno"

    #define STRCMD_CS_HIDDEN_ITEM					"Posizione nascosta"		// 2011-09-20 by hskim, ÆÊ ½ýºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

	#define STRCMD_CS_POS_INVALID_POSITION			"In attesa di posizionamento"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Inventory location"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/QuestComplete"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /QuestComplete [|IndiceQuest]"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/NationRatio"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"formato: /NationRatio"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/ChangeNation"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"formato: /ChangeNation [|1(Normale)|2(BCU)|A(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMon"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"formato: /GoMonster [Nome Mostro|Numero Mostri]"

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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"formato: /Noticeboard [|Durata(unit:min) [Dettagli Avviso] - Aggiungi un avviso alla board avviso elettronica per una data durata."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"formato: /DeleteNoticeboard [indice di preavviso per essere cancellato] - Cancella un determinato avviso dalla board elettronica di avviso."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Influence Leader"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Vice influsso"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Influence Buff"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Evento Influsso"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"formato: /ContributionPoint [Influenza(2:BCU, 4:ANI)] [Incrementa] - Incrementa il contributo di una certa nazione"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"formato: /CallGM [Dettagli della richiesta] - Richiede una consultazione con un GM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"formato: /ViewCallGM   [|Number(1~10)] - Controlla il numero di consultazione della lista richieste ai GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"formato: /BringCallGM [|Numero(1-10)] - Portare il numero richiesto della lista di cosultazione richiesta al GM (Cancellato dal server)"

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
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"formato: /SendItem [1(Normale)|2(VCN)|4(ANI)|3|5|6|7] [Numero Oggetto] [# di oggetti] - Dà uno specifico oggetto a tutti i giocatori della nazione nella mappa corrente"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Oggetto del Colore"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯¥ Çö ¹æ½ÄÀÌ ´£´Ù
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ¹¹(English):	MM-DD-YYYY HH:MM:SS
	// º£³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"formato: /LevelDistribution - Mostra la distribuzione del livello degli utenti concorrenti"	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Oggetto della Possibilità"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Marchio"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// ¶ó¸¸ »ç¿ëÇÂ ¸í·î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"formato: /call [NomePersonaggio] - Richiesta 1:1 chat vocale per uno specifico personaggio"
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Start voice chat between formation members. Only usable by the formation leader."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - End voice chat between formation members. Only usable by the formation leader."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"formato: /brigcall - Inizia una chat vocal tra i membri della brigata. Può essere usato solo dal capo di brigata"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"/formato: brigcallend - Termina la chat vocale tra i membri della brigata. Può essere usato solo dal Capo della Brigata"
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"formato: /endcall - Termina la chat vocale di brigata, formazione o normale"
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"formato: /fight [Nome Personaggio] - Richiesta di PvP per uno specifico personaggio"
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [CharacterName] -  Surrenders a PvP battle with the specified character."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [CharacterName] - Request formation PvP to specific character(formation leader). Only usable by the formation leader."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"formato: /brigconfront [Nome Personaggio] - Richiesta di PvP di brigata per uno specifico personaggio (capo di brigata). Può usarlo solo il capo di brigata."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"formato: /brigsurrender - Rinuncia di una battaglia PvP di Brigata. Può usarlo solo il capo di brigata."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [CharacterName] [class(2 ~ 11)] - Change appointment class of specific character. Only usable by the brigade leader."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"formato: /initchat - Risistema la finestra della chat"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - On/Off  Toggles PvP denial setting"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  On/Off Toggles trading denial setting"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"formato: /Closewindow - Previene messaggi popup. I Messaggi sono cancellati automaticati."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"formato: /Openwindow - Mostra messaggi popup"

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Oggetto dell'Abilità di Supporto"

// 2010-06-15 by shcho&hslee Æê½ýºÅÛ - Æê ¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Item compagno"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Item slot del tuo compagno"		// 2011-09-01 by hskim, ÆÊ ½ýºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£³² Çç °ÔÀÓ ½ð£ °ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"formato: /TimeLimitSystem [on|off] - Questo comando è a sua volta del sistema del tempo limite on/off."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"formato: /PlayTime - Questo comando mostra il tempo di gioco del giorno"

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ  ´£°Ô ¼³ - ¾¡¿¡ ¼¼·º°·Î ´£°Ô ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"formato: /BonusStatPoint [Conta BonusStatPoint] [|nome personaggio] - BonusStatPoint migliorati al DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"formato: /PCBang - PCBang user counts"

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
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"formato: /StrategyPointInfo - Questo mostra lo stato corrente riguardo il punto strategico."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"Non vi è alcun punto strategico di guerra in corso."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Punto strategico di guerra in corso."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Località in Progresso"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Tempo d'Inizio"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear Tutto"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear Tutto"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear Tutto"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear Tutto"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear Tutto"

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"formato: /Observer [n] [NomePersonaggio] - NomePersonaggio salva l'utente per n numero"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·Ã
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"formato: /InitJamboree [numero di validazione] - Inizializzazione jamboree server DB(atum2_db_20)"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"formato: /EntratJamboree [Nome personaggio] - Personaggio designato che sarà duplicato al server jamboree DB(atum2_db_20)."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Apprendista"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Uomo d'Aria"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Uomo d'Ala"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "Asso"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Veterano"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Comandante dell'Ala"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Eroe"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"VersioneClient"
// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"NomeAccount"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA ÆÀ Ãâ·Â °ü·Ã ½º¸µ
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Non può essere trovato il team arena."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "formato: /arena [2(VCN)|4(ANI)]- Mostra il progresso dell'arena."

// 2010. 06. 04 by hsLee ARENA ÀÎÇÏ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-Start the watch."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Ends the watch."

// 2007-06-22 by dhjin, WarPoint á
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "formato: /WarPoint [Number 1~1000000] [|Username] ? Aggiungi Punti Guerra"

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎ  °ü·Ã á
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Punti Guerra"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "formato: /forbidArena [nome personaggio] [| Tempo(minuti)] - Vietato entrare in Arena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "formato: /releaseArena [character name] - Divieto di lasciare l'Arena"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Il Marchio della Brigata è stato registrato con successo."
#define STRMSG_070802_0002    "La registrazione sarà completata dopo il processo di screening."
#define STRMSG_070802_0003    "Will you accept %d selected brigade mark?"
#define STRMSG_070802_0004    "No brigade mark status"
#define STRMSG_070802_0005    "Brigade mark in waiting status"
#define STRMSG_070802_0006    "Brigade mark in normal status"
#define STRMSG_070802_0007    "Brigade mark error status"

// 2007-08-24 by cmkwon, ½ºÇÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³ ±â´É á - ¸í·î á
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Consenti"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Proibisci"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Enable/Forbid use Speaker item"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Inizio"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Rilascia"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"formato: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] -  Prepara il server alla disconnessione, disconnetti tutti gli utenti."

// 2007-08-30 by cmkwon, Àë ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "formato: /EntrancePermission [nome personaggio] - Può essere usato solo dal Capo. Il giocatore può essere inserito nella lista per l'entrata alla sala delle conferenze."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "formato: /EntrancePermissionDeny [nome personaggio] - Può essere usato solo dal Capo. Questo nega un giocatore di far parte della lista della stanza delle conferenze."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d giorni %d ore %d minuti %d secondi", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d anno %d mese %d giorno", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d anno %d mese", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d mese %d giorno", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Sub Capo 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Sub Capo 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Comandante Generale"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Vice Comandante"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Capo dello Staff"
#define STRCMD_ANI_INFLUENCE_LEADER						"Presidente"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vice-Presidente"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Direttore Strategico"
#define STRCMD_OUTPOST_GUILD_MASTER						"Cpt. %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [CharacterName] - BCU : set BCU Nation 1st sub-leader name, ANI : set ANI Nation 1st sub-leader name"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"formato: /appointement2 [NomePersonaggio] - BCU : setta BCU 2° nome del sub-Capo della Nazione, ANI : setta ANI 2° nome del sub-Capo della Nazione"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Inizio"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Fine"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"formato: /HappyEvent [255(TutteNazioni)|0(NazioneNormale)|2(VCN)|4(ANI)] [Inizio|Fine] [Tempo di Progresso(Unità:Minuto)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Nazione Normale"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"TuttaNazione"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Users of selected nation of present map will be awarded WarPoint."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"formato: /StartHelper [|tempo(Unit: Minuto)] - Inizia sistema di appello"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"formato: /EndHelper - Finisce il sistema di appello"

// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW á
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, µµ¿ì¸ðµå »óÅÂ ÀúÀåÇâ - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"ModoFinestra"

// 2008-01-31 by cmkwon, °è º/ÇØ ¸í·î·Î °¡´ÉÇÑ ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"formato: /Block [NomeAccount] [TipoBlocco(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Chat Related|6:Related GameBug)] [Periodo:Giorni] [Ragione Blocco per l'Utente] / [Ragione Blocco per l'Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"formato: /Unblock [NomeAccount]"

// 2008-02-20 by cmkwon, ¸í·îá(¼ÓÁßÀÎÀú¸ÆÀÌÅÛÁö±Þ- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normale)|2(BCU)|4(ANI)|255(Tutti)] [Numero Oggetto] [# di oggetti] - I giocatori loggati della nazione selezionata riceveranno l'oggeto designato"

// 2008-02-21 by dhjin, ¾¹³ªÅëÇÕ- ¾¹³ªá¸í·î
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "formato: /TeamArenaLeave [2(BLU)|4(ROSSO)|6(BLU E ROSSO)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "formato: /TargetArenaLeave [Nome Personaggio]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "formato: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "formato: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °ö½Ã ¹º¿¡¼­ °ö ±â´É á(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Tutti Tipi"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Membro"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Comandante di brigata di volo"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Co-Capo Brigata"				// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"Comandante del 1° Battaglione"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"Membro del 1° Battaglione"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"Comandante del 2° Battaglione"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"Membro del 2° Battaglione"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"Comandante del 3° Battaglione"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"Membro del 3° Battaglione"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"Comandante del 4° Battaglione"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"Membro del 4° Battaglione"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"Comandante del 5° Battaglione"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"Membro del 5° Battaglione"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ÀüÀ
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ¼¼·¸¶ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [nation 2(BCU)|4(ANI)]"
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
#define STRMSG_080821_0001				"Non può essere assegnato il grado al personaggio selezionato."


// 2008-09-09 by cmkwon, /¼¼·¼Ò ¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀÔ á - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [maximum people] [0|minimum level] [0|maximum level] [1(B)|16(M)|256(A)|4096(I)] [Message to user] - Request to certain nation, level users to move to event map"

// 2008-09-09 by cmkwon, "/kick" ¸í·î á - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Terminate designated character from the game."


// 2008-09-12 by cmkwon, "/¸" ¸í·î á - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"formato: /fame [fama personale] [fama brigata] - Aumenta la fama personale e della brigata del personaggio."

// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"Formato: /ReleaseLeaderChatBlock [Nome personaggio] - Il capo ha revocato il divieto di chattare."

// 2009-10-12 by cmkwon, ½º °Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/Inizia Mappa Città"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "Città Iniziale"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "formato: /StartCity [2001|2002][|Charaktername] - Scegli la città di partenza del tuo personaggio tra 2001 e 2002, in base a quale nazione è stata impostata."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, Ãë ·¹º§ »óÇ µû¸¥ á »çÇ×(·¹º§º° °è±Þ) - °è±æ(¹éºÎÀå, ´ë·É, À, ö, º¹ÀÚ, ¼öÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurione"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Colonnello"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "Generale"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Generale di Divisione"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conquistatore"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardiano"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Leggenda"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Base"

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
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Informazioni sui membri della formazione del giocatore (i membri devono aver effettuato il login al gioco)"
// End. 2013-11-19 by bckim, ÆÄ¿ø º¸ º¸±â ¸í·î Ã¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





