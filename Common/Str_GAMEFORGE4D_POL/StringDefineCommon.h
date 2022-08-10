// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - Konfiguruje ment postaci"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [MapIndex] [|ChannelIndex] - Idzie do okre�lonego kana�u karty"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Przeskakuje do podanych wsp�rz�dnych karty"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Przedstawia list� wszystkich u�ytkownik�w na aktualnej karcie (maksymalnie 20 u�ytkownik�w)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [character name] [map name] - Porusza postaci� na wybranej mapie"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [nazwa potwora|nazwa przedmiotu] - Pokazuje uszeregowane informacje o potworach i przedmiotach"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - Pokazuje questinfo dla postaci"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [Quest Numer]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [|item kind(0~53)] - Pokazuje wybrany typ przedmiotu"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [item kind(0~53)] -  Dodatkowe specjalne rodzaje przedmiot�w"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [from itemnum] ~ [to itemnum] - Dodatkowe specjalne przedmioty"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - Inicjuje status ca�kowity"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo - Pokazuje partyinfo"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /Time [|additional time(0~23)] - Zmienia aktualny czas (tylko czas indywidualny b�dzie zmieniony)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Decyduje jaki poziom b�dzie pokazany w komunikacie debug."
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [monster number|monster name] [# of monsters] - Przynosi potwora ('_'b�dzie u�yty je�li nazwa potwora zawiera spacj�)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [level] - Wprowadza wszystkie pasuj�ce umiej�tno�ci"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem - Wstawia wszystkie wybrane przedmioty, bez umiej�tno�ci i p�atnych przedmiot�w"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - Dodatkowo wszystkie typy broni do uzbrojenia Gear"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Usuwa wszystkie niewyposa�one przedmioty (bez umiej�tno�ci)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [item number] [# of items] - Nabyte przedmioty b�d� traktowane jak 1 przedmiot , je�li [# of items] nie jest wprowadzony."
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [item number] [|# of items] - Pozwala spada� przedmiotom na pole."
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - Zestawienie informacji serwera"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - Pokazuje informacje ca�ej mapy"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Pokazuje informacje o karcie kana�u na aktualnej karcie."
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - tylko do test�w"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [|Numer amunicji standardowej] [|Numer amunicji dodatkowej] - Za�adowa� amunicj�"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [|imi� postaci] - leczy HP, UTC, TANK ze 100%, Wylecz si� sam bez [imi� postaci]"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|imi� postaci] - HP, TUC, i TANK konta dla [decreasing quantity %], 50% je�li [decreasing quantity %] nie wprowadzony i nie ma [imi� postaci] jest dla indywidualnej postaci."
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - Zmienia do normalnego konta Admina albo trybu Game Master"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Zmienia normalne konto admina na specjalne konto admina lub Game Mastera"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible - W Gamemaster albo w trybie Managera nie mo�na ponie�� �adnej szkody."
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [Podnosi si�� ataku(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [zmienne] - Ustaw (normalne) zmienne"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [|level] [|percentage of exp] [|character name] - Zmie� poziom i stop� procentow� do�wiadczenia postaci"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible - Niewidzialny dla innych postaci"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - tylko do test�w"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Punkt za do�wiadczenie"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"Przedmiot"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Rzadki przedmiot"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"Cel"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(minute)] - Event Set, Przerwanie"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"Standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"Super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"Udoskonalenie"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"Cel"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [Standard|Super|Udoskonalenie|Cel]"
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
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Wszyscy cz�onkowie bractwa b�d� przesuni�ci do wybranej karty"
// start 2011-10-28 by hskim, EP4 [���� �����] - ���� �����
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [���� �����] - ���� �����


// start 2011-06-22 by hskim, �缳 ���� ����
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ���� ���� ����
// end 2011-06-22 by hskim, �缳 ���� ����
			   
// start 2012-02-13 by hskim, ���� ������ ���  ���
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ���� �� ����
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ���� ������ ���  ���

// 2007-10-30 by cmkwon, ����� ����  ���� - ��� ���� ���� ������ �� �� ��
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - debug serwera IM"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - Zestawienie wszystkich u�ytkownik�w na serwerze (niezale�nie od karty)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - Rejestruje serwer, �eby napisa� wiadomo�� do admina w trakcie przebiegu eventu"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - Pokazuje powy�szy protok�, kt�ry wysy�a i odbiera klient oraz Serwer IM*"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - Server shutdown"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [imi� postaci]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - Idzie na wybran� pozycj� tej postaci."
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [nazwa postaci] - Wzywa wybran� posta�"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [guild name] - Wzywa ca�e bractwo"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /comeonGuild [guild name] [map name]- Wysy�a bractwo w wybran� kart�."
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Zmienia pomi�dzy \"szeptanie\" dozwolone i nie dozwolone"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Pokazuje informacje o bractwie"
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
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Kontroluje pogod�"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [Imi� gracza] [Czas(min.)] - Zabroni� czata"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [time(min.)] - Zamyka zabroniony czat"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - B�d� pokazane listy mo�liwych rozkaz�w"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|nazwa postaci] - podnie�� statystyczny bonus"

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
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [Szereg b�dzie zakodowany]"
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
	#define STRCMD_CS_COMMON_DB_0000 "Tylko nale��ce do serwera Mgame!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Prosz� poda� imi� loguj�ce do serwera"
	#define STRCMD_CS_COMMON_DB_0002 "Prosz� poda� has�o loguj�ce do serwera"
	#define STRCMD_CS_COMMON_DB_0003 "Prosz� poda� imi� DB-Login"
	#define STRCMD_CS_COMMON_DB_0004 "Prosz� poda� has�o loguj�ce do serwera"

	#define STRCMD_CS_COMMON_MAP_0000 "Sta�a cz�� oprogramowania: Zignoruj cel teleportacji numer 1 w karcie 0101, trzeba znale�� najprostsz� drog� do skasowania edytora kart i usun�� go!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "KARTA: %04d, m_DefaultWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Sta�a cz�� oprogramowania: Zignoruj cel teleportacji numer 1 w karcie 0101, trzeba znale�� najprostsz� drog� do skasowania edytora kart i usun�� go!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "KARTE: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] Wezwij potwora[%8d] Wezwij czas[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] Wezwij potwora[%8d] Wezwij czas[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Ca�kowita liczba potwor�w : [%4d] <== W��czaj�c obiekt potw�r\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "B��d podczas �ci�gania pliku"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "B��d podczas tworzenia pliku"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "B��d przy wczytywaniu �ci�ganego pliku"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%dDzie�%dGodzina%dMinuta%dSekunda"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normalny"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Relikwiarz"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Rezerwa"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Rezerwa"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrator"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Go��"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Do demo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Wszystkie rasy"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Nieznana rasa"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Brak nazwy"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Kadet"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3. Lotnik"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2.Lotnik"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1. Lotnik"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3. Wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2. Wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1. Wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3. Przyw�dca"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2. Przyw�dca"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1. Przyw�dca"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3. As"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. As"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1. As"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Komandor pu�ku powietrznego"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vice-marsza�ek si� powietrznych"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Genera� porucznik"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Genera�"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Typ automatyczny"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Typ Valkan"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Typ dualistyczny"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Typ dzia�a"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Typ karabinu"
	#define STRCMD_CS_ITEMKIND_GATLING				"Typ Gatlinga"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Typ wyrzutni rakietowej"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Typ masowego nap�du"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Typ rakiety"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Typ rakiet"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Typ wi�zania"

	#define STRCMD_CS_ITEMKIND_MINE					"Typ min"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Typ os�ony"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Typ atrapy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Typ naprawy"
	#define STRCMD_CS_ITEMKIND_DECOY				"Typ przyn�ty"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Typ wyposa�enia obronnego"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Przedmiot wyposa�eniowo-wspomagaj�cy"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Typ energii"
	#define STRCMD_CS_ITEMKIND_INGOT				"Typ minera�u"
	#define STRCMD_CS_ITEMKIND_CARD					"Typ kart standardowych"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Typ karty udoskonalenia"
	#define STRCMD_CS_ITEMKIND_TANK					"Typ opancerzenia"
	#define STRCMD_CS_ITEMKIND_BULLET				"Typ kuli"
	#define STRCMD_CS_ITEMKIND_QUEST				"Typ przedmiotu zadanie"
	#define STRCMD_CS_ITEMKIND_RADAR				"Typ radaru"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Typ komputera"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Typ kart do gry"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Typ karty zapobiegania skasowaniu udoskonalenia"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Typ blastera"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Typ Railgun"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Nieograniczony dodatek"		// 2006-03-17 by cmkwon, ������ <����>�� ������ ������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Dodatkowy limit czasowy"		// 2006-03-17 by cmkwon, ��� �� ���� �� ������ ������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Wszystkie rodzaje broni"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Bro� standardowa"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Typ kul broni standardowej"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Typ zbiornika broni standardowej"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Bro� dodatkowa"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Karta do broni dodatkowej"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Typ os�ony broni dodatkowej"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Umiej�tno�� ataku"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Umiej�tno�� obrony"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Umiej�tno�� wspomagaj�ca"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Umiej�tno�� wyr�niaj�ca"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Przedmiot dla potwora typ 1"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Typ karabinu maszynowego potwora (1-1 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Typ promieniowania potwor�w  (1-2-Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Atakuj wszystkie potwory"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Przedmiot dla potwora typu 2"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Rakieta potwora (2-1 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Typ rakiet potwora (2-1 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Typ wi�zania potwor�w (2-1 typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Typ min potwora (2-1 typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Typ os�ony potwora (2-2 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Typ atrapy potwora(2-2 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Typ naprawy potwora (2-2 Typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Typ pu�apki na potwory (2-2typ)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Typ ognia potwora"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Typy mo�liwo�ci katastrofalnego promieniowania potwora"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Typ bomb potwora"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Przedmiot nieznany"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Nieznana kabina lataj�ca"

	#define STRCMD_CS_STAT_ATTACK_PART				"Atak"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Obrona"
	#define STRCMD_CS_STAT_FUEL_PART				"Paliwo"
	#define STRCMD_CS_STAT_SOUL_PART				"Umiej�tno��"
	#define STRCMD_CS_STAT_SHIELD_PART				"Os�ona"
	#define STRCMD_CS_STAT_DODGE_PART				"Unik"
	#define STRCMD_CS_STAT_BONUS					"Statystyka bonusowa"
	#define STRCMD_CS_STAT_ALL_PART					"Wszystkie statystyki"
	#define STRCMD_CS_STAT_UNKNOWN					"Nieznana statystyka"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Dowolny typ"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Typ ataku"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-type"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Rodzaj ataku"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Rodzaj ruchu"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Typ ataku"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Typ os�ony"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Rodzaj obrony"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Typ wspomagania"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ����� ����  ���� - ������ �� �� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Federacyjna armia Vattalusa"

	#define STRCMD_CS_POS_PROW						"Miejsce radaru (na g�rze w �rodku)"
	#define STRCMD_CS_POS_PROWIN					"Komputer (�rodek po lewej)"
	#define STRCMD_CS_POS_PROWOUT					"Bro� standardowa (na g�rze po lewej)"
	#define STRCMD_CS_POS_WINGIN					"Nie u�ywany (�rodek po prawej)"
	#define STRCMD_CS_POS_WINGOUT					"Bro� zaawansowana (na g�rze po prawej)"
	#define STRCMD_CS_POS_CENTER					"Opancerzenie (�rodek)"
	#define STRCMD_CS_POS_REAR						"Silnik (na dole �rodek)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_ATTACHMENT				"������(�� ����-������|�����)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Cz�� dobudowy (prawa strona ogonu - zbiornik paliwa | kontener)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_PET						"������(�� ����)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Niemo�liwe do u�ycia (lewa strona ogona)"

	#define STRCMD_CS_POS_PET						"Partner"

    #define STRCMD_CS_HIDDEN_ITEM					"Ukryta pozycja"		// 2011-09-20 by hskim, �� ����� 2�� - ������ ������

	#define STRCMD_CS_POS_INVALID_POSITION			"Unosz�ce si� miejsce"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Miejsce ekwipunku"

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
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [imi� potwora|numer potwora]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���� �� ���� -  � �� 
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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /Noticeboard [|Duration(unit:min) [Notice details] - Na okre�lony czas dodaje wiadomo�� do publicznej elektronicznej tablicy og�osze�."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - Usuwa konkretn� wiadomo�� z elektronicznej tablicy og�osze�."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Wp�yw przyw�dca"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Wp�yw vice-przyw�dca"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Wp�yw sk�ra"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Wp�yw impreza"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Podnosi podatki konkretnego narodu"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [Szczeg�y pytania pomocniczego] - Wys�a� pytanie pomocnicze do GM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [|Number(1~10)] - Sprawd� numer listy pyta� pomocniczych przez GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Numner(1~10)] - Przynosi pytanie pomocnicze z podanym numerem do GM (i b�dzie skasowany z serwera)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"
// 2008-09-09 by cmkwon, /����� ��� ���� ������ ����� � - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnNation [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [MAX_USER] [0|Min-level] [0|Max-level] [message to users] - Summons all specified level users in nation with a message."

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Daje przedmiot wszystkim cz�onkom narodu w aktualnej karcie."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Przedmiot barwi�cy"

	// 2006-08-03 by cmkwon, ���� ��� �� ����� ����
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ��(English):	MM-DD-YYYY HH:MM:SS
	// ����(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - Pokazuje rozk�ad takich samych poziom�w u�ytkownik�w"	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Przedmiot-szansa"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Oznakowanie"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// �� ����� ���(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [imi� postaci] - Pytanie do wybranej postaci w sprawie czata 1:1."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Rozpocznij rozmow� na czacie mi�dzy cz�onkami formacji. Tylko do u�ytku  dow�dcy formacji."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - Zako�cz rozmow� na czacie mi�dzy cz�onakmi formacji. Tylko do u�ytku dow�dcy formacji."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Zacznij rozmow� na czacie mi�dzy cz�onkami brygady, tylko do u�ytku przez dow�dc� brygady."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcall - Zacznij rozmow� na czacie mi�dzy cz�onkami brygady. Do u�ytku tylko przez dow�dc� brygady."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - ko�czy czat brygady/formacji albo normalny."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [imi� postaci] - Pytanie dla  PvP w sprawie wybranej postaci."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [imi� postaci] -  Rezygnuje z walki PvP z wybran� postaci�."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [imi� postaci] - Pytanie do wybranej postaci (przyw�dca formacji) w sprawie formacji PvP. Tylko do u�ytku dow�dcy formacji."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [imi� postaci] -  Pytanie do wybranej postaci (dow�dca brygady) w sprawie brygady PvP.Tylko do u�ytku dow�dcy brygady"
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  Zadanie podczas walki brygad PvP. Tylko do u�ytku dow�dcy brygady."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [imi� postaci] [class(2 ~ 11)] - Zamyka pozycj� wybranej postaci. Tylko do u�ytku dow�dcy brygady."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  �aduje na nowo okno czatu"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - W��czy�/wy��czy� ustawienia odmowy PvP"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  W��czy�/wy��czy� ustawia ustawienia odmowy handlu"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Udaremnia wiadomo�ci Popups. Wiadomo�ci b�d� zako�czone automatycznie."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow - Umo�liwia wiadomo�ci Popups."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Przedmiot umiej�tno�ci wspomagaj�cej"

// 2010-06-15 by shcho&hslee ������ - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Przedmiot partnera"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Przedmiot slotu partnera"		// 2011-09-01 by hskim, �� ����� 2��

// 2006-11-17 by cmkwon, ���� �� ���� �� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"W��czony"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"Wy��czony"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - Ten rozkaz zostanie u�yty, �eby w��czy� lub wy��czy� limit czasowy."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Ten rozkaz pokazuje  czas dzisiejszej gry."

// 2007-10-06 by cmkwon, �������� 2����  ���� �� - ���� ������� ���� ����
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|nazwa postaci] - BonusStatPoint update do BD"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang p�atno�ci u�ytkownika"

// 2007-10-06 by dhjin, �������� ���� ��� ����� ��
// 2007-02-13 by dhjin, ��������
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /Subleader [CharacterName] - Setting subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR		"Subleader setting has been cancelled."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0			"No more subleaders can be set."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1			"%s has become the first subleader."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2			"%s has become the second subleader."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10			"%s does not exist."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20			"%s is already a subleader."

// 2007-02-23 by dhjin, ��
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - To pokazuje stan obecnych post�p�w na punktach strategicznych."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"Chwilowo nie toczy si� �adna wojna punkt�w strategicznych."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Wojna punkt�w strategicznych aktywowana."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Post�powe miejsce"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Czas startu"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear w ca�o�ci"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear w ca�o�ci"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear w ca�o�ci"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear w ca�o�ci"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear w ca�o�ci"

// 2007-03-30 by dhjin, ������ ��� �� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [CharacterName] - Nazw� postaci zapisze u�ytkownik przy indeksie n"

// 2007-04-10 by cmkwon, Jamboree server �� ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Inicjuj Jamboree Serwer DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Wybrana posta� zostanie podwojona na Jamboree Server DB (atum2_db_20)."
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

// 2007-04-17 by dhjin, ���� ���� ���� ���
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Praktykant"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Pilot"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Wingman"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Weteran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Wing Commander"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Bohater"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ������ ��� ��� � -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGruppenName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ����
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Nie mo�e znale�� dru�yny areny."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)]- Pokazuje aktualny post�p na arenie."

// 2010. 06. 04 by hsLee ARENA ���� ����. - 
// 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-Rozpocznie przygl�danie si�."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Zako�czy przygl�danie si�."

// 2007-06-22 by dhjin, WarPoint �
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Dodaje punkty wojenne."

// 2007-06-26 by dhjin, ������  ���� �
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Punkt wojenny"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [nazwa postaci] [|Czas (minuty)] - zakaz wst�pu na Aren�"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [nazwa postaci] - zakaz Areny uchylony"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Rejestracja oznaczenia brygady zosta�a zako�czona sukcesem."
#define STRMSG_070802_0002    "Rejestracja po procesie sortowania zosta�a zako�czona."
#define STRMSG_070802_0003    "Akceptujesz %d wybrane oznaczenia?"
#define STRMSG_070802_0004    "Brak statusu oznacze� brygady"
#define STRMSG_070802_0005    "Oznaczenia brygady w statusie oczekiwania"
#define STRMSG_070802_0006    "Oznaczenia brygady w statusie normalnym"
#define STRMSG_070802_0007    "B��d w statusie oznaczenia brygady"

// 2007-08-24 by cmkwon, �������� ��� ����/���� �� ��� � - ��� �
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"W��czony"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Zabro�"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Pozwalam/Zabraniam u�ycia przedmiot�w nag�a�niaj�cych"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Publikacja"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - przygotuj serwer- Shutdown, rozdziel wszystkich u�ytkownik�w."

// 2007-08-30 by cmkwon, �� ����� ���� - ��� �
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [Imi� gracza]? Mo�e by� u�yte tylko przez osob� kieruj�c�. Dodaje podanego gracza do listy wst�pu do sali konferencyjnej."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[EntrancePermissionDeny] [Imi� gracza] ? Mo�e by� u�yty tylko przez osob� kieruj�c�. Kasuje wskazanego u�ytkownika z listy wst�pu do sali konferencyjnej."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d dni(dzie�) %d godzin(a) %d minut(a) %d sekund(a)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d rok%d miesi�c%d dzie�", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d rok%d miesi�c", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d miesi�c%d dzie�", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Przyw�dca ni�szej rangi 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Przyw�dca ni�szej rangi 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Genera� Major"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Wiceprezydent"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Oficer Strategiczny BCU"
#define STRCMD_ANI_INFLUENCE_LEADER						"Prezydent"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Wiceprezydent"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Oficer Strategiczny"
#define STRCMD_OUTPOST_GUILD_MASTER						"Kpt. %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [CharacterName] - BCU : set BCU Nation 1st sub-leader name, ANI : set ANI Nation 1st sub-leader name"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [CharacterName] - BCU : wstaw BCU Nation 2nd sub-leader name, ANI : wstaw ANI Nation 2nd sub-leader name"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Start"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Koniec"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyEvent [255(AllNation)|0(NormalNation)|2(VCN)|4(ANI)] [Start|End] [Czas post�pu(Jednostka:Minuta)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Zwyczajny nar�d"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"AllNation"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Wszyscy u�ytkownicy wybranego narodu otrzymaj� w aktualnej karcie jeden punkt wojenny."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - Rozpocznij system pyta�"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Ko�czy system telefoniczny"

// 2007-12-27 by cmkwon, ������ ��� ��� � - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, ������ ���� ������ - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, �� �/�� ���� ������ ����� ���� - ��� �
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ����(������������������- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [numer przedmiotu] [# przedmiot�w] - Zalogowani u�ytkownicy wybranego narodu otrzymaj� przewidziane przedmioty"

// 2008-02-21 by dhjin, ��������- �������
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(NIEBIESKI)|4(CZERWONY)|6(NIEBIESKI I CZERWONY)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Imi� postaci]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [Numer pomieszczenia]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [Numer pomieszczenia]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ ���� ������ �� ��� �(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Wszystkie rodzaje"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� �� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Cz�onek"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Przyw�dca brygady lotniczej"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Co- przyw�dcy brygady"				// 2008-05-20 by dhjin, EP3 - ���� �� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"Komendant pierwszego batalionu"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1. Cz�onek batalionu"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2. Komendant batalionu"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2. Cz�onek batalionu"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3. Komendant batalionu"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3. Przyw�dca batalionu"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4. Komendant batalionu"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4. Cz�onek batalionu"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5. Komendant batalionu"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5. Cz�onek batalionu"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ���
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ����� 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [Nation 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, � PC�� IP�� ��
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minuta] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ��, �� ���� �������� �� ��
#define STRMSG_080821_0001				"Ten stopie� nie mo�e by� nadany wybranemu graczowi."


// 2008-09-09 by cmkwon, /����� ��� ���� ������ ����� � - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [Maksymalna liczba os�b] [0|Minumales Level] [0|Maximales Level] [1(B)|16(M)|256(A)|4096(I)] [Wiadomo�� do u�ytkownika] - Zadanie dla narodu, u�ytkownicy poziomu powinni uda� si� do planu imprez."

// 2008-09-09 by cmkwon, "/kick" ��� � - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Usu� podan� posta� z gry."


// 2008-09-12 by cmkwon, "/�" ��� � - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/S�awa"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/S�awa"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"Format: /S�awa [Osobista s�awa] [S�awa brygady] - Powi�ksza s�aw� postaci i jej brygady."

// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"Format: /ReleaseLeaderChatBlock [Charactername] - Ograniczenie postaci dow�dcy zostanie zniesione."

// 2009-10-12 by cmkwon, �� �� ��� ���� - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|Charaktername] - Wybierz miasto rodzinne dla postaci w 2001 lub 2002, je�li wybra�e� ju� nar�d."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �� ���� ��� ���� � ����(������ ���) - ���(�����, ���, �, �, ����, ����, ��������)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Starszy szeregowy"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Podpu�kownik"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "Genera� dywizji"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Genera� brygady"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Zdobywca"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Str�"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legenda"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Standard"

#define       STRCMD_CS_COMMAND_ENDARENA					"/endarena"				// 2012-09-24 by jhseol, ���� �� ��� ��

// 2014-05-16 by bckim, ���� ��ɾ� �߰�
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ���� ��ɾ� �߰�

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�� �� ������ - ��� á
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/������"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /������ [MapIndex] - �� ���� ���� �� ����"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]���� ���� ���� �� ����."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]���� ���� ���� �� ����."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]�� ������� �� ����."
// end 2012-11-29 by jhseol, OX�� �� ������ - ��� á

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol,  �� ������
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, �Ŀ� �� ���� ��� á
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Informacje o cz�onkach formacji gracza (cz�onkowie musz� by� zalogowani do gry)"
// End. 2013-11-19 by bckim, �Ŀ� �� ���� ��� á

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





