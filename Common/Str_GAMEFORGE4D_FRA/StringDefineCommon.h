// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - Configuration ment du personnage"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [MapIndex] [|ChannelIndex] - Aller dans une carte sp�cifi�e dans le canal"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Permet de se d�placer dans la carte aux coordonn�es sp�cifi�es"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Listes des utilisateurs dans la pr�sente carte (maximum de 20 utilisateurs)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [character name] [map name] - D�place le personnage dans la carte sp�cifi�e"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [monster name|item name] - Montre des informations sur les montres ou items compris dans la cha�ne"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - Montre les informations de la qu�te du personnage"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [quest no.]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [|item kind(0~53)] - Affiche les types d'items s�lectionn�s"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [item kind(0~53)] - Ajoute les types d'items sp�cifi�s"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [from itemnum] ~ [to itemnum] - Items sp�cifiques suppl�mentaires"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - Initialise l'ensemble des statuts"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo - Montre les informations de la f�te"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /Time [|additional time(0~23)] - Change le temps actuel (uniquement le temps personnel chang�)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Annonce les niveaux indiqu�s par un message de debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [monster number|monster name] [# of monsters] - Am�ne un monstre ('_'est utilis� si un monstre comporte un espace dans son nom)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [level] - Ajoute toutes les comp�tences du niveau correspondant"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem - Ajouter des items sp�cifiques,  sans comp�tence et items d�nombrables"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - Armes suppl�mentaires pour l'�quipement du vaisseau"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Supprime tous les items non �quip�s (sans comp�tences)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [item number] [# of items] - L'acquisition des items est trait�e comme 1 item lorsque [# d'items] n'est pas sp�cifi�s"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [item number] [|# of items] - Pour laisser tomber dans la zone les objets choisis"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - Liste d'information serveur"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - Montre les informations de toutes les cartes"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Montre les informations canal des cartes dans la pr�sente carte"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - Uniquement pour test"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [|no. du 1er type de munition] [|no. du 2�me type de munition] - Chargement des munitions"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [|character name] - Gu�rir PV, UTC, CARBURANT � 100%, Gu�ris-toi toi-m�me sans [character name]"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|character name] - PV, UTC, et CARBURANT comptes pour [decreasing quantity %], 50% si [decreasing quantity %] n'est pas entr� et si [character name] n'est pas pr�sent il est pour personnage individuel"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - Change un compte Admin ou un compte Game Master en compte normal"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Change un compte normal en un compte Admin ou compte Game Master"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible - En Game Master ou en Mode Manager aucun dommage pris en compte"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [Augmente la puissance d'attaque(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [variable] - Ajuste les variables normales"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [|level] [|percentage of exp] [|character name] - Ajuste le niveau et le pourcentage d'exp�rience pour un personnage"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible -  Invisible pour les autres personnages"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - Uniquement pour test"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Point d'exp�rience"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Objet Rare"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"termin�"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(minute)] - event set, annuler"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"Super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"termin�"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [standard|super|upgrade|termin�]"
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
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Tous les membres de la guilde sont d�plac�s dans la carte sp�cifi�e"
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer pour debugging"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - Liste tous les joueurs pr�sents dans le serveur (ind�pendamment de la carte)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - Message enregistr� sur le serveur envoy� par un admin au cours d'un Event"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - Montre tous les protocoles qu'un client et le serveur de MI envoient et re�oivent."
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - Serveur hors Service"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - Se d�placer vers la position sp�cifi�e d'un personnage"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [character name] - Faire venir un personnage sp�cifi�"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [guild name] - Appelle l'ensemble de la guilde"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [guild name] [map name] - Envoie une guilde dans une carte sp�cifique"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Pour basculer entre les chuchotements bloqu�s et autoris�s"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Montre les informations de la guilde"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"Standard"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"Clair"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"Pluie"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"Neige"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"Couvert"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"Brumeux"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"Tout"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Pour contr�ler le temps"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [nom du joueur] [temps(min.)] - Chat interdit"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [time(min.)] - Annule l'interdiction de parler sur le chat"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - Affiche la liste des commandes possibles"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - BonusStat augment�"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /setPassword [AccountName] [Mot de Passe]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /rollbackPassword [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [cha�ne qui sera crypt�e]"
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
	#define STRCMD_CS_COMMON_DB_0000 "Uniquement li� au Serveur Mgame!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Merci de saisir votre nom d'utilisateur serveur"
	#define STRCMD_CS_COMMON_DB_0002 "Merci de saisir le mot de passe serveur"
	#define STRCMD_CS_COMMON_DB_0003 "Merci de saisir le nom d'utilisateur serveur"
	#define STRCMD_CS_COMMON_DB_0004 "Merci de saisir le mot de passe serveur"

	#define STRCMD_CS_COMMON_MAP_0000 "Partie Cod�e: Ignore le num�ro 1 de la cha�ne cible de la carte 0101, moyen facile de supprimer de l'�diteur de carte. Doit �tre trouv� et doit �tre supprim�!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "CARTE: %04d, m_DefaultWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Partie Cod�e: Ignore le num�ro 1 de la cha�ne cible de la carte 0101, moyen facile de supprimer de l'�diteur de carte. Doit �tre trouv� et doit �tre supprim�!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "CARTE: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Nombre total de monstres : [%4d] <== Y compris monstre objet\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Erreur de t�l�chargement du fichier"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Erreur de cr�ation fichier"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Erreur de lecteur du fichier t�l�charg�"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%djour%dheure%dminute%dseconde"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"R�serve"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"R�serve"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrateur"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Moniteur"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Invit�"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Pour d�mo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Toutes les Races"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Race Inconnue"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Pas de nom"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"�l�ve Officier"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3�me Pilote"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2�me Pilote"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1er Pilote"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3�me Wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2�me Wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1er Wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3�me Pr�sident"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2�me Pr�sident"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1er Pr�sident"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3�me As"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. Ace"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1er As"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Air-Commodore"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vice-mar�chal de l'air"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Lieutenant G�n�ral"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Maitre G�n�ral"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Type Automatique"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Type Vulcain"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Type Dualiste"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Type de Canon"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Type Fusil"
	#define STRCMD_CS_ITEMKIND_GATLING				"Type Gatling"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Type lance-roquettes"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Type Entrainement de masse"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Type Roquette"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Type Missile"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Type de Paquet"

	#define STRCMD_CS_ITEMKIND_MINE					"Type de Mine"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Type Bouclier"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Type Dummy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Type R�paration"
	#define STRCMD_CS_ITEMKIND_DECOY				"Type d'app�t"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Type d'�quipement de D�fense"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Type d'Equipement Support"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Type Energie"
	#define STRCMD_CS_ITEMKIND_INGOT				"Type Min�ral"
	#define STRCMD_CS_ITEMKIND_CARD					"Type Carte Standard"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Type de Carte d'Enchantement"
	#define STRCMD_CS_ITEMKIND_TANK					"Type de Char"
	#define STRCMD_CS_ITEMKIND_BULLET				"Type de Munition"
	#define STRCMD_CS_ITEMKIND_QUEST				"Type d'item de qu�te"
	#define STRCMD_CS_ITEMKIND_RADAR				"Type radar"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Type Ordinateur"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Type de Carte pour parier"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Type Carte Pr�vention Suppression Enchantement"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Type Blaster"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Type Railgun"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Temps additionnel illimit�"		// 2006-03-17 by cmkwon, ������ <����>�� ������ ������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Limite de temps additionnel"		// 2006-03-17 by cmkwon, ��� �� ���� �� ������ ������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Toutes les armes"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Arme Standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Type d'arme de munition standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Carburant Type Arme Standard"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Arme secondaire"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Type Munition Arme Avanc�e"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Type Bouclier Arme Avanc�e"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Comp�tence d'Attaque"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Comp�tence de D�fense"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Comp�tence Support"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Attributs Comp�tence"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item pour Type 1 Monstre"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Type de Monstre Mitrailleur (1-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Type Monstre Rayon (1-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Attaquer tous les monstres"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item pour Type 2 Monstre"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Type Monstre Roquette (2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Type Monstre Missile (2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Type Monstre Paquet (2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Type Monstre Mine (2-1type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Type Monstre Bouclier (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Type Monstre Dummy (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Type Monstre de R�paration (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Type Monstre App�t (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Type Monstre de Feu"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Crash Monstre possible Type Rayon"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Type Monstre Bombe"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Objet Inconnu"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Zone de vol inconnue"

	#define STRCMD_CS_STAT_ATTACK_PART				"Attaque"
	#define STRCMD_CS_STAT_DEFENSE_PART				"D�fense"
	#define STRCMD_CS_STAT_FUEL_PART				"Carburant"
	#define STRCMD_CS_STAT_SOUL_PART				"Esprit"
	#define STRCMD_CS_STAT_SHIELD_PART				"Bouclier"
	#define STRCMD_CS_STAT_DODGE_PART				"�vasion"
	#define STRCMD_CS_STAT_BONUS					"Statistiques Bonus"
	#define STRCMD_CS_STAT_ALL_PART					"Toutes les statistiques"
	#define STRCMD_CS_STAT_UNKNOWN					"Statistique Inconnue"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Type libre"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-type"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Type d'agilit�"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Type de bouclier"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Type de d�fense"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Type de support"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ����� ����  ���� - ������ �� �� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Arm�e F�d�rale Vattalus"

	#define STRCMD_CS_POS_PROW						"Lieu de Radar (au centre en haut)"
	#define STRCMD_CS_POS_PROWIN					"Ordinateur (centre gauche)"
	#define STRCMD_CS_POS_PROWOUT					"Arme Standard (en haut � gauche)"
	#define STRCMD_CS_POS_WINGIN					"Ne sont pas utilis�s (centre droit)"
	#define STRCMD_CS_POS_WINGOUT					"Arme Avanc� (en haut � droite)"
	#define STRCMD_CS_POS_CENTER					"Armure (centre milieu)"
	#define STRCMD_CS_POS_REAR						"Moteur (en bas au milieu)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_ATTACHMENT				"������(�� ����-������|�����)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Pi�ce annexe (arri�re droite - r�servoir de carburant | Container)"

	// 2010-06-15 by shcho&hslee ������
	//#define STRCMD_CS_POS_PET						"������(�� ����)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Inutilisable (arri�re gauche)"

	#define STRCMD_CS_POS_PET						"Partenaire"

    #define STRCMD_CS_HIDDEN_ITEM					"Position cach�e"		// 2011-09-20 by hskim, �� ����� 2�� - ������ ������

	#define STRCMD_CS_POS_INVALID_POSITION			"En attente d'emplacement"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Lieu d'Inventaire"

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
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [MonstreNom|MonstreNum�ro]"

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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /DeleteNoticeboard [index of notice to be deleted] - Ajoute un message publique sur le support �lectronique de message pendant un certain temps."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - Supprime un message du support �lectronique de message."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Influence Pr�sident"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Influence Vice-Pr�sident"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Influence Buff"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Event Influence"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Augmente la contribution d'une certaine Nation"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [D�tails de la demande] - Demande de consultation avec un GM."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM [|Number(1~10)] - Pour contr�ler la liste du nombre de consultation demand�e pour un GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Number(1~10)] - Montre la liste du nombre de requ�tes en consultation demand�es par GM (supprim�e par le serveur)"

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
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Donne des items sp�cifiques � tous les joueurs d'une nation dans la pr�sente carte."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Couleur Item"

	// 2006-08-03 by cmkwon, ���� ��� �� ����� ����
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ��(English):	MM-DD-YYYY HH:MM:SS
	// ����(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - Montre les utilisateurs de m�me niveau de distribution."	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Item Chance"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Marque"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// �� ����� ���(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [CharacterName] - Demande 1:1 conversation chat � un personnage sp�cifique."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - D�bute une conversation chat entre les membre d'une formation. Uniquement utilisable par le Pr�sident de la formation."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - Met fin � la conversation chat entre les membres d'une formation. Uniquement utilisable par le Pr�sident de la Formation."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - D�bute une conversation chat entre les membres de la brigade. Uniquement utilisable par le Pr�sident de la brigade."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - Met fin � la conversation chat entre les membres de la brigade. Uniquement utilisable par le Pr�sident de la brigade."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Met fin aux conversations chat brigade, formation, normal."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [CharacterName] - Demande de combat PvP avec le personnage s�lectionn�."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [CharacterName] -  Capitulation du combat PvP avec le personnage s�lectionn�."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [CharacterName] - Demande une formation en mode PvP � un personnage s�lectionn� (Pr�sident Formation). Uniquement utilisable par le Pr�sident de la Formation."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [CharacterName] - Demande un combat Brigade PvP � un personnage sp�cifi� (Pr�sident Brigade). Uniquement utilisable par le Pr�sident de la brigade."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  Capitulation de la brigade en mode PvP. Uniquement utilisable par le Pr�sident de la brigade."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [CharacterName] [class(2 ~ 11)] - Change la position d'un personnage choisi. Seulement utilisable par le Pr�sident des brigades."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  R�initialise la fen�tre du chat"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - On/Off Pour basculer dans le mode PvP"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  On/Off Bascule dans le mode du commerce"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Bloque les fen�tres popups. Les messages seront automatiquement stopp�s."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Autorise les fen�tres popups."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Item Comp�tence Support"

// 2010-06-15 by shcho&hslee ������ - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Objet-partenaire"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Objet de case partenaire"		// 2011-09-01 by hskim, �� ����� 2��

// 2006-11-17 by cmkwon, ���� �� ���� �� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - Commande utilis�e pour mettre en route ou �teindre le syst�me de temps limit�."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Cette commande affiche le temps de jeu du jour."

// 2007-10-06 by cmkwon, �������� 2����  ���� �� - ���� ������� ���� ����
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint mise � jour de la DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang Utilisateurs compt�s"

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
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - Ceci montre l'�tat actuel de l'avanc�e sur le point strat�gique."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"Il n'y a pas de point strat�gique de guerre en cours."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Point strat�gique de Guerre en progression."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Progression en cours"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"D�part"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-GEAR"
#define STRCMD_CS_UNITKIND_MGEAR					"M-GEAR"
#define STRCMD_CS_UNITKIND_AGEAR					"A-GEAR"
#define STRCMD_CS_UNITKIND_IGEAR					"I-GEAR"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"Tous les B-GEAR"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"Tous les M-GEAR"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"Tous les A-GEAR"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-GEAR total"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Tous les GEAR"

// 2007-03-30 by dhjin, ������ ��� �� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [CharacterName] - Sauvegarde l'utilisateur � l'index n"

// 2007-04-10 by cmkwon, Jamboree server �� ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Initialise la DB du serveur Jamboree (atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Le personnage d�sign� sera dupliqu� dans la DB du serveur Jamboree (atum2_db_20)."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Apprenti"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Pilote"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Equipier"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "V�t�ran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Commandant �quipier"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "H�ros"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ������ ��� ��� � -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"Nom du serveur groupe"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ����
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "L'Ar�ne d'�quipe ne peut pas �tre trouv�e."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)] - Montre la progression actuelle dans l'Ar�ne."

// 2010. 06. 04 by hsLee ARENA ���� ����. - 
// 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ���� �� 2�� �� ��. (GM ��� �. /nextscene(�� �� �� ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format: /WatchStart - Pour d�buter � visionner."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Arr�te l'action de visionner."

// 2007-06-22 by dhjin, WarPoint �
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Ajoute des points de guerre."

// 2007-06-26 by dhjin, ������  ���� �
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Point de Guerre"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [character name] [|Time(minutes)] - Interdiction d'entrer dans l'ar�ne"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [character name] - Interdiction de sortir de l'Ar�ne"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "M�daille de Brigade enregistr�e avec succ�s."
#define STRMSG_070802_0002    "Inscription compl�t�e apr�s processus de contr�le."
#define STRMSG_070802_0003    "Acceptez vous %d  m�dailles de Brigade s�lectionn�es ?"
#define STRMSG_070802_0004    "Pas de m�daille pour le statut de la brigade"
#define STRMSG_070802_0005    "Statut de m�daille de la brigade en attente"
#define STRMSG_070802_0006    "Statut de m�daille de la brigade normal"
#define STRMSG_070802_0007    "Erreur dans le statut de m�daille de la brigade"

// 2007-08-24 by cmkwon, �������� ��� ����/���� �� ��� � - ��� �
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Autoriser"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Interdire"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Autorise/Interdit d'utiliser les objets haut-parleur"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Version"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - Pr�pare l'arr�t du serveur, d�connecte tous les utilisateurs."

// 2007-08-30 by cmkwon, �� ����� ���� - ��� �
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [|CharacterName] ? Peut uniquement �tre utilis� par un Pr�sident. Autorise le joueur choisi � entrer dans la salle de conf�rence."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[ EntrancePermissionDeny] [CharacterName] ? Peut uniquement �tre utilis� par un Pr�sident. Supprime le joueur choisi de la liste de la salle de conf�rence."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d jour(s) %d heure(s) %d minute(s) %d seconde(s)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d ann�e %d mois %d jour", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d ann�e %d mois", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d mois %d jour", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Vice-Pr�sident 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Vice-Pr�sident 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Commandant G�n�ral"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Commandeur adjoint"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Chef de l'Equipe"
#define STRCMD_ANI_INFLUENCE_LEADER						"Pr�sident"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vice-pr�sident"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Directeur Strat�gique"
#define STRCMD_OUTPOST_GUILD_MASTER						"Cne %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [CharacterName] - BCU : set BCU Nation 1st sub-leader name, ANI : set ANI Nation 1st sub-leader name"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [CharacterName] - BCU : set BCU Nation 2nd sub-leader name, ANI : set ANI Nation 2nd sub-leader name"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"D�marrer"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Fin"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyEvent [255(AllNation)|0(NormalNation)|2(VCN)|4(ANI)] [Start|End] [Progression temps(Unit:Minute)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Nation Normale"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"Toutes les Nations"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Un point de guerre sera accord� dans la pr�sente carte pour les utilisateurs de la Nation s�lectionn�e."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - D�but du syst�me d'appel"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Quitte le syst�me d'appel"

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
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Num�ro Item] [# d'items] - L'utilisateur loggu� de la nation s�lectionn�e recevra l'objet d�sign�"

// 2008-02-21 by dhjin, ��������- �������
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLEU)|4(ROUGE)|6(BLEU ET ROUGE)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ ���� ������ �� ��� �(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Tous les types"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� �� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Membre"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Commandant de la brigade de vol"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Co-Brigade Pr�sident"				// 2008-05-20 by dhjin, EP3 - ���� �� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1er Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1er Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�me Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2�me Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�me Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�me Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�me Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�me Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�me Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5�me Bataillon Membre"

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
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ��, �� ���� �������� �� ��
#define STRMSG_080821_0001				"Le rang ne peut pas �tre attribu� au joueur s�lectionn�."


// 2008-09-09 by cmkwon, /����� ��� ���� ������ ����� � - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [nombre de personne maximum] [0|niveau minimum] [0|niveau maximum] [1(B)|16(M)|256(A)|4096(I)] [Message au joueur] - Demander � une nation et aux joueurs d'un certain niveau de se d�placer dans la carte d'�vent."

// 2008-09-09 by cmkwon, "/kick" ��� � - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Ejecte le personnage sp�cifi� du jeu."


// 2008-09-12 by cmkwon, "/�" ��� � - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Gloire"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Gloire"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"Format:  /Gloire [Gloire personnelle] [Gloire de la Brigade] - Augmente la gloire du personnage et de sa brigade."

// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format : /ReleaseLeaderChatBlock [NomduPerso] - Suppression de la restriction chat du Leader."

// 2009-10-12 by cmkwon, �� �� ��� ���� - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|Charaktername] - Choisissez votre ville d'origine, 2001 ou 2002, si vous avez d�j� choisi votre nation"


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �� ���� ��� ���� � ����(������ ���) - ���(�����, ���, �, �, ����, ����, ��������)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Brigadier"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Lieutenant-colonel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "G�n�ral de division"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "G�n�ral de brigade"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conqu�rant"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Gardien"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "L�gende"
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
// 2013-07-26 by jhseol, � �� �������
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, �Ŀ� �� ���� ��� á
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Informations sur les membres de la formation du joueur (les membres doivent �tre connect�s au jeu)"
// End. 2013-11-19 by bckim, �Ŀ� �� ���� ��� á

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





