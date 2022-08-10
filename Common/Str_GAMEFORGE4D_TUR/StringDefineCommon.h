// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - Karakterin zihnini ayarlar"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [MapIndex] [|ChannelIndex] - Belirlenen harita kanal�na gider"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Haritan�n belirli bir koordinat�na do�ru hareket eder"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - g�ncel haritadaki kullan�c�lar�n listesi (maksimum 20 kullan�c�)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [Karakter ismi] [Harita �smi] - Karakter belirli bir haritaya hareket ettirilir"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [monster name|item name] - Giri�teki kelimeyi i�eren canavarlar veya nesneler hakk�ndaki bilgileri g�sterir"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - Karakterin g�rev bilgilerini g�sterir"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [quest no.]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [|item kind(0~53)] - Nesnenin belirli tiplerini g�sterir"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [item kind(0~53)] -  Ek belirli tipte nesneler"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [from itemnum] ~ [to itemnum] - Ek belirli nesneler"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - B�t�n durumlar� s�f�rlar"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo - Parti bilgilerini g�sterir"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /Time [|additional time(0~23)] - G�ncel zaman� de�i�tirir(sadece ki�isel zaman de�i�ir)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Hata ay�klama mesaj� ile g�sterilen levellere karar verir."
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [monster number|monster name] [# of monsters] - canavar getirir. (E�er canavar isminde bo�luk var ise '_' kullan�lmal�d�r.)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [level] - B�t�n uygun yetenekleri ekler"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem - B�t�n belirlenen nesneleri yetenekler dahil, ve say�labilen nesneleri ekler."
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - geare uygun t�m silahlar� ekler"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - B�t�n donan�lmam�� nesneleri siler (Yetenekler dahil)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [item number] [# of items] - Nesne elde eder, [# of items] girilmedi�inde b�t�n nesnelere tek nesne gibi davran�r"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [item number] [|# of items] - Nesneleri alana d���r�r"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - Sunucu bilgileri listesi"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - B�t�n haritalar�n bilgilerini g�sterir"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - G�ncel haritadaki harita kanallar� bilgilerini g�sterir"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - Sadece test i�in"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [|1inci tip mermi say�s�] [|2inci tip mermi say�s�] - mermileri doldurur"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [|character name] - HP, UTC, Yak�t� %100e tamamlar, Kendinizi tamamlatmak i�in [karakter ismi] k�sm�n� yazmadan sadece /repairAll diyebilirsiniz."
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|character name] - HP, UTC, and FUEL accounts for [decreasing quantity %], 50% if [decreasing quantity %] is not inputted, and if [character name] is not present it stands for the individual's character"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - OY veya admin modundan normal oyun hesab� moduna d�ner."
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Normal bir hesab�, �zel admin veya OY hesab�na �evirir."
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible - OY veya y�netici modu ile, hasar al�nmaz."
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [Increased offensive power(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [variable] - (normal) de�i�kenleri ayarlar"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [|level] [|percentage of exp] [|character name] - Karakterin levelini ve tecr�be y�zdesini ayarlar"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible -  Di�er karakterlere g�r�nmez olursun"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - Sadece test i�in"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"exppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"nesne"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"nadirnesne"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"bitirmek"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(dk)] - olay ayarlar, iptal eder"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finish"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [standard|super|upgrade|finish]"
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
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Topluluktaki b�t�n �yeler belirlenen haritaya giderler"
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMSunucu hata ay�klamas� i�in"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - Haritadan ba��ms�z olarak sunucudaki b�t�n kullan�c�lar� listeler"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - olay devam ederken sunucudan admine mesajlar� kay�t eder"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - �stemcinin b�t�n protokollerini g�sterir ve IM sunucusunun ald��� ve g�nderdi�i b�t�n protokolleri g�sterir"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - sunucu kapat�m�"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [Karakter ismi]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [karakter ismi] - Belirli bir karakterin konumuna hareket eder"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [karakter ismi] - Belirli bir karakteri �a��r�r"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [klan ad�] - T�m klan� �a��r�r"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [topluluk ad�] [Harita ismi] - Toplulu�u belirli bir haritaya g�nderir"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - F�s�ldamay� bloklamak ve blo�unu kald�rmak i�in kullan�l�r"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Klan bilgilerini g�sterir"
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
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Hava durumunu kontrol eder"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [karakter ismi] [zaman(dk.)] - Sohbeti yasaklar"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [zaman(dk.)] - Yasaklanm�� sohbeti iptal eder"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - komut listesi g�r�n�r"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"Kullan�m: /BonusStat [Prim say�s�] [|Karakter ismi] - PrimStat� artar"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /setPassword [Hesap�smi] [�ifre]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /rollbackPassword [Hesap�smi]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [giri� �ifrelenir]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"Kullan�m: /blockAccount [Hesap�smi]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"kullan�m: /releaseAccount [Hesap�smi]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"kullan�m: /blockedList"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Sadece Moyun sunucusu ile ilgili!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "L�tfen sunucu giri� isminizini tekrar giriniz"
	#define STRCMD_CS_COMMON_DB_0002 "L�tfen sunucu giri� �ifrenizi giriniz"
	#define STRCMD_CS_COMMON_DB_0003 "L�tfen DB giri� isminizi giriniz"
	#define STRCMD_CS_COMMON_DB_0004 "L�tfen DB kay�d�ndaki �ifrenizi giriniz"

	#define STRCMD_CS_COMMON_MAP_0000 "Zor kodlu b�l�m: 0101 haritas�ndaki 1 numaral� ���nlanma hedefini yoksay, harita edit�r�nden silmek i�in gerekli olan bulunmal� ve gerekli olanlar silinmeli!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "HAR�TA: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Zor kodlu b�l�m: 0101 haritas�ndaki 1 numaral� ���nlanma hedefini yoksay, harita edit�r�nden silmek i�in gerekli olan bulunmal� ve gerekli olanlar silinmeli!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "HAR�TA: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[HATA] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Toplam Canavar Say�s� : [%4d] <== Konu cavavar� dahil\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "�ndirme dosyas� hatas�"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Dosya olu�turma hatas�"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "�ndirme dosyas� okuma hatas�"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%dg�n%dsaat%ddakika%dsaniye"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DEKA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"saklanma"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"saklama"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Y�netici"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Oyuny�neticisi"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"�zleyici"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Konuk"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Demo i�in"
	#define STRCMD_CS_COMMON_RACE_ALL			"B�t�n �rklar"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Bilinmeyen �rk"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"�simsiz"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Askeri ��renci"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3�nc� havac�"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2inci havac�"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1inci havac�"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3�nc� kanatadam�"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2inci kanatadam�"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1inci kanatadam�"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3�nc� lider"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2inci lider"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1inci lider"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3�nc� Y�ld�z"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. As"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1inci Y�ld�z"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Tu�general"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"T�mgeneral"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Korgeneral"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Orgeneral"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Otomatik tip"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Valkan Tipi"
	#define STRCMD_CS_ITEMKIND_DUALIST				"D�ellocu  tipi"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Top tipi"
	#define STRCMD_CS_ITEMKIND_RIFLE				"T�fek tipi"
	#define STRCMD_CS_ITEMKIND_GATLING				"Mitraly�z tipi"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"F�rlat�c� tipi"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"K�tle binek tipi"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Roket tipi"
	#define STRCMD_CS_ITEMKIND_MISSILE				"F�ze tipi"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"K�me tipi"

	#define STRCMD_CS_ITEMKIND_MINE					"May�n tipi"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Kalkan tipi"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Model tipi"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Tamirci tipi"
	#define STRCMD_CS_ITEMKIND_DECOY				"Kopya tipi"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Savunma ekipman� tipi"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Destek ekipman tipi"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Enerji tipi"
	#define STRCMD_CS_ITEMKIND_INGOT				"Mineral tipi"
	#define STRCMD_CS_ITEMKIND_CARD					"Standart Kart tipi"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Upgrade Kartlar�-Tip"
	#define STRCMD_CS_ITEMKIND_TANK					"Tanker tipi"
	#define STRCMD_CS_ITEMKIND_BULLET				"Mermi tipi"
	#define STRCMD_CS_ITEMKIND_QUEST				"G�rev nesnesi tipi"
	#define STRCMD_CS_ITEMKIND_RADAR				"Radar tipi"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Bilgisayar tipi"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"�ans oyunu kart tipi"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"B�y�l� Koruma Silme Kart� tipi"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Barut�u tipi"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Demir silah tipi"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Limitsiz Tak�"		// 2006-03-17 by cmkwon, ������ <����>�� ������ ������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Zaman k�s�tlamas� Tak�s�"		// 2006-03-17 by cmkwon, ��� �� ���� �� ������ ������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"B�t�n silahlar"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Standart Silah"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Mermi tipi Standart Silah"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Yak�t tipi Standart Silah"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Geli�mi� Silah"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Mermi tipi Geli�mi� Silah"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Kalkan tipi Geli�mi� Silah"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Sald�r� yetene�i"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Savunma yetene�i"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Destek yetene�i"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Nitelik yetene�i"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1 tip canavar i�in nesne"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Canavar makineli t�fek tipi(1-1tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Canavar ���n tipi(1-2tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"B�t�n canavarlara sald�r"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2 tipi canavar i�in nesne"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Canavar Roket (2-1tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Canavar F�ze tipi(2-1tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Canavar K�me tipi(2-1tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Canavar May�n tipi(2-1tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Canavar kalkan tipi(2-2tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Canavar Model tipi(2-2tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Canavar Tamirci tipi(2-2tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Canavar Kopya tipi(2-2tipi)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Canavar Ate� tipi"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Canavar d��mesi muhtemel ���n tipi"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Canavar do�rudan bomba tipi"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Bilinmeye nesne"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Bilinmeyen u�ak"

	#define STRCMD_CS_STAT_ATTACK_PART				"Sald�r�"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Savunma"
	#define STRCMD_CS_STAT_FUEL_PART				"Yak�t"
	#define STRCMD_CS_STAT_SOUL_PART				"Ruh"
	#define STRCMD_CS_STAT_SHIELD_PART				"Kalkan"
	#define STRCMD_CS_STAT_DODGE_PART				"S�yr�lma"
	#define STRCMD_CS_STAT_BONUS					"Prim stat�"
	#define STRCMD_CS_STAT_ALL_PART					"B�t�n statlar"
	#define STRCMD_CS_STAT_UNKNOWN					"Bilinmeyen stat"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Serbest tip"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Atak tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-tip"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Atak tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Hareket Tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Atak tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Kalkan tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Defans tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Destek tipi"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ����� ����  ���� - ������ �� �� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Vattalus federasyon ordusu"

	#define STRCMD_CS_POS_PROW						"Radar konumu(Yukar� merkez)"
	#define STRCMD_CS_POS_PROWIN					"Bilgisayar(Merkez sol)"
	#define STRCMD_CS_POS_PROWOUT					"Standart Silah(Yukar� sol)"
	#define STRCMD_CS_POS_WINGIN					"Kullan�lm�yor(Orta sa�)"
	#define STRCMD_CS_POS_WINGOUT					"Geli�mi� Silah(Yukar� sa�)"
	#define STRCMD_CS_POS_CENTER					"Z�rh (Merkez orta)"
	#define STRCMD_CS_POS_REAR						"Motor(Alt orta)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_ATTACHMENT				"������(�� ����-������|�����)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Ek par�a (sa� arka taraf - yak�t tank� | konteyner)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_PET						"������(�� ����)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Kullanmaya elveri�siz (sol arka k�s�m)"

	#define STRCMD_CS_POS_PET						"Partner"

    #define STRCMD_CS_HIDDEN_ITEM					"Gizli Konum"		// 2011-09-20 by hskim, �� ����� 2�� - ������ ������

	#define STRCMD_CS_POS_INVALID_POSITION			"Bekleme konumu"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Envanter konumu"

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
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [MonsterName|MonsterNumber]"

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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /Noticeboard [|Duration(unit:min) [Notice details] - Genel elektronik bildirim panosuna girilen s�re boyunca bir bildirim ekler."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - elektronik bildirim panosundaki belirli bir bildirimi siler."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Etki Lideri"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Etki vekil-lideri"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Etki Tutkunu"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Etki Olay�"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Belirli bir ulusun kat�l�m�n� artt�r�r."

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [istek detay�] - OYsine dan��ma iste�i yollar."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [|Number(1~10)] - �stek listesindeki numaralar� kontrol eder"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Say�(1~10)] - �stenilen numaradaki OYsini dan��man istek listesine ekler. (Sunucu taraf�ndan silinir)"

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
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Belirlenen nesneyi g�ncel haritadaki b�t�n ulusun kullan�c�lar�na verir."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Renkli Nesne"

	// 2006-08-03 by cmkwon, ���� ��� �� ����� ����
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ��(English):	MM-DD-YYYY HH:MM:SS
	// ����(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - E� zamanl� kullan�c�lar�n level da��l�m�n� g�sterir"	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"�ans Nesnesi"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"��aret"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// �� ����� ���(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [Karakter�smi] - Belirtilen karaktere 1e1 sesli sohbet iste�i g�nderir"
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Birlik �yeleri aras�nda sesli sohbet ba�lat�r. Sadece birlik lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"format: /formcallend - Birlik �yeleri aras�ndaki sesli sohbeti bitirir. Sadece birlik lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Tugay �yeleri aras�nda sesli sohbet ba�lat�r. Sadece tugay lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - Tugay �yeleri aras�ndaki sesli sohbeti sonland�r�r. Sadece tugay lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Tugay, birlik veya normal sesli sohbeti bitirir."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [Karakter�smi] - Belirtilen karaktere 1e1 sava�ma iste�i g�ndermek"
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [Karakter�smi] - 1e1 sava�ta belirtilen kullan�c�ya teslim olmak i�in kullan�l�r."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [Karakter�smi] - Se�ilen karaktere(birlik lideri) birlik PvP'si daveti. Sadece birlik lideri taraf�ndan kullan�l�r."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [Karakter�smi] - Belirtilen karakterin(tugay lideri) tugay�na 1e1 sava� iste�i g�nderir. Sadece tugay lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  1e1 tugay sava��nda teslim olmak. Sadece tugay lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [Karakter�smi] [class(2 ~ 11)] - Belirli karakterin klas�n� de�i�tirir. Sadece tugay lideri taraf�ndan kullan�labilir."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  sohbet penceresini ba�tan ba�lat�r"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight  1e1 reddetmeyi a��p-kapama ayar�"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  Ticaret reddetme ayar�n� a��p/kapar"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Mesaj pop-uplar�n� engeller. Mesajlar otomatik olarak reddedilir."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Mesaj pop-uplar�na izin verir."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Destek Yetenek Nesnesi"

// 2010-06-15 by shcho&hslee ������ - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Partner E�yas�"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner yuva e�yas�"		// 2011-09-01 by hskim, �� ����� 2��

// 2006-11-17 by cmkwon, ���� �� ���� �� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - bu komut zaman s�n�rlamas� sistemini a��p/kapar."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Bu komut bug�n oyunu oynuyan ki�i say�s�n� g�sterir."

// 2007-10-06 by cmkwon, �������� 2����  ���� �� - ���� ������� ���� ����
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"Kullan�m: /BonusStatPoint [PrimStatPuan� Say�s�] [|Karakter ismi] - PrimStatPuan� DB ile g�ncenlenir"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang kullan�c� say�m�"

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
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - Bu komut stratejik nokta �zerindeki g�ncel ilerleyen durumu g�sterir."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"There is no strategic point war in progress."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Strategic point war is in progress."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Progress location"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Starting time"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear T�m�"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear T�m�"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear T�m�"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear T�m�"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear T�m�"

// 2007-03-30 by dhjin, ������ ��� �� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [Karakter�smi] - Karakter�smi n numara olarak saklan�r"

// 2007-04-10 by cmkwon, Jamboree server �� ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Jamboree sunucusunu DB(atum2_db_20) �al��t�r�r."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Dizayn edilen karakter jamboree sunucusuna DB(atum2_db_20) kopyalan�r."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "��rak"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Gen�"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Havac�"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Kanatadam�"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Gazi"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Kanat kumandan�"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Kahraman"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ������ ��� ��� � -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ����
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Arena tak�m� bulunamad�."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)]- Arenan�n g�ncel i�leyi�ini g�sterir."

// 2010. 06. 04 by hsLee ARENA ���� ����. - 
// 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart- g�zlemi ba�lat�r."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? G�zlemeyi iptal eder."

// 2007-06-22 by dhjin, WarPoint �
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Sava� puan� ekler."

// 2007-06-26 by dhjin, ������  ���� �
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Sava�Puan�"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "kullan�m: /forbidArena [Karakter ismi] [|Zaman:dakika)] - Arenaya giri�i yasaklar"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "Kullan�m: /releaseArena [Karakter ismi] - Arena yasaklar�n� kald�r�r"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Tugay i�aretlemeleri ba�ar� ile kay�t edildi."
#define STRMSG_070802_0002    "G�r�nt�leme i�lemi bittikten sonra kay�t i�lemi tamamlanacakt�r."
#define STRMSG_070802_0003    "Tugay i�aret�isi olarak %s i se�meyi kabul ediyor musun?"
#define STRMSG_070802_0004    "Tugay i�aret durumu yok"
#define STRMSG_070802_0005    "Tugay i�aretlemesi bekleme durumunda"
#define STRMSG_070802_0006    "Tugay i�aretlemesi normal durumunda"
#define STRMSG_070802_0007    "Tugay i�aretlemesi hata durumunda"

// 2007-08-24 by cmkwon, �������� ��� ����/���� �� ��� � - ��� �
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Enable"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Forbid"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Hoparl�r nesnesinin uygun/yasakl� kullan�m�"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - sunucunun kapat�lmas�na haz�r olun, b�t�n kullan�c�lar�n ba�lant�lar� kesilecektir."

// 2007-08-30 by cmkwon, �� ����� ���� - ��� �
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [|Karakter�smi] ? Sadece lider taraf�ndan kullan�labilir. Bu komut ilgili ki�iyi konferans odas� giri� listesine ekler."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[ EntrancePermissionDeny] [Karakter �smi] ? Sadece lider taraf�ndan kullan�labilir. Bu komut ilgili ki�iyi konferans odas� giri� listesinden siler."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d g�n %d saat %d dakika %d saniye", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d Y�l %d ay %d g�n", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d Y�l %d ay", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d Ay %d g�n", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Lider yard�mc�s� 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Lider yard�mc�s� 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Genel kumandan"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Vekil Kumandan"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Kurmay ba�kan"
#define STRCMD_ANI_INFLUENCE_LEADER						"Ba�kan"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Ba�kan Yard�mc�s�"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Strateji y�neticisi"
#define STRCMD_OUTPOST_GUILD_MASTER						"Kpt. %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [Karakter�smi] - BCU : BCU Ulusu birinci yedek lider ismini ayarlar, ANI : set ANI Ulusu birinci yedek lider ismini ayarlar."
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [Karakter�smi] - BCU : BCU Ulusu 2inci yedek lider ismini ayarlar, ANI : set ANI Ulusu 2inci yedek lider ismini ayarlar."

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Ba�lang��"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Son"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyEvent [255(AllNation)|0(NormalNation)|2(VCN)|4(ANI)] [Start|End] [Progress time(Unit:Minute)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Normal ulus"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"B�t�nUluslar"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - g�ncel haritadaki se�ilen ulusun kullan�c�lar� Sava�Puan� ile �d�llendirilirler."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - M�racaat sistemini ba�lat�r"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - M�racaat sistemini sonland�r�r"

// 2007-12-27 by cmkwon, ������ ��� ��� � - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, ������ ���� ������ - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, �� �/�� ���� ������ ����� ���� - ��� �
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Chat Related|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [Hesap�smi]"

// 2008-02-20 by cmkwon, ����(������������������- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] - Se�ilen ulusun giri� yapan �yesi, dizayn edilen nesneye sahip olur"

// 2008-02-21 by dhjin, ��������- �������
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Karakter�smi]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "Kullan�m: /ArenaEvent [OdaNumaras�]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "kullan�m: /ArenaEventRelease [OdaNumaras�]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ ���� ������ �� ��� �(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"B�t�n t�rler"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� �� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"�ye"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"U�u� tugay� kumandan�"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Tugay lideri yard�mc�s�"				// 2008-05-20 by dhjin, EP3 - ���� �� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1inci tabur kumandan�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1inci tabur �yesi"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2inci tabur kumandan�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2inci tabur �yesi"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�nc� tabur kumandan�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�nc� tabur �yesi"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�nc� tabur kumandan�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�nc� tabur �yesi"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5inci tabur kumandan�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5inci tabur �yesi"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ���
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ����� 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [nation 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, � PC�� IP�� ��
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ��, �� ���� �������� �� ��
#define STRMSG_080821_0001				"Se�ilen karaktere belirtilen r�tbe verilemedi."


// 2008-09-09 by cmkwon, /����� ��� ���� ������ ����� � - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [maximum people] [0|minimum level] [0|maximum level] [1(B)|16(M)|256(A)|4096(I)] [kullan�c� mesaj�] - Belirli ulustaki, belirli leveldeki kullan�c�lara olay haritas�na gitmek �zere istek yollar"

// 2008-09-09 by cmkwon, "/kick" ��� � - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [Karakter�smi] - Belirlenen karakteri oyundan atar"


// 2008-09-12 by cmkwon, "/�" ��� � - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"kullan�m: /fame [ki�isel �n] [tugay �n�] - Karakterin ki�isel ve tugay �n�n� artt�r�r."

// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/Liderin Sohbet Engelini Kald�r"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/Liderin Sohbet Engelini Kald�r"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"Format: /Liderin Sohbet Engelini Kald�r [Karakter ismi] - Liderin sohbet k�s�tlamas� kald�r�ld�."

// 2009-10-12 by cmkwon, �� �� ��� ���� - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/Memleket Haritas�"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "Memleket"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /Memleket [2001|2002] [|Karakter Ad�] - Ulus ayar� yap�ld�ktan sonra, 2001 veya 2002'den karakterinin memleketini se�."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �� ���� ��� ���� � ����(������ ���) - ���(�����, ���, �, �, ����, ����, ��������)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurion"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Albay"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "T�mgeneral"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Fatih"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Gardiyan"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Efsanevi"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Temel"

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
// 2013-07-26 by jhseol, � �� �������
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, �Ŀ� �� ���� ��� á
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] -Oyuncunun formasyon �yeleri hakk�nda bilgiler (�yelerin oyunda oturum a�m�� olmalar� gerekiyor)"
// End. 2013-11-19 by bckim, �Ŀ� �� ���� ��� á

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





