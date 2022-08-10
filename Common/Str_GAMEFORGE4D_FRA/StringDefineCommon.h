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
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [MapIndex] [|ChannelIndex] - Aller dans une carte spécifiée dans le canal"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Permet de se déplacer dans la carte aux coordonnées spécifiées"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Listes des utilisateurs dans la présente carte (maximum de 20 utilisateurs)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [character name] [map name] - Déplace le personnage dans la carte spécifiée"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [monster name|item name] - Montre des informations sur les montres ou items compris dans la chaîne"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - Montre les informations de la quête du personnage"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [quest no.]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [|item kind(0~53)] - Affiche les types d'items sélectionnés"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [item kind(0~53)] - Ajoute les types d'items spécifiés"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [from itemnum] ~ [to itemnum] - Items spécifiques supplémentaires"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - Initialise l'ensemble des statuts"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo - Montre les informations de la fête"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /Time [|additional time(0~23)] - Change le temps actuel (uniquement le temps personnel changé)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Annonce les niveaux indiqués par un message de debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [monster number|monster name] [# of monsters] - Amène un monstre ('_'est utilisé si un monstre comporte un espace dans son nom)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [level] - Ajoute toutes les compétences du niveau correspondant"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem - Ajouter des items spécifiques,  sans compétence et items dénombrables"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - Armes supplémentaires pour l'équipement du vaisseau"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Supprime tous les items non équipés (sans compétences)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [item number] [# of items] - L'acquisition des items est traitée comme 1 item lorsque [# d'items] n'est pas spécifiés"
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
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Montre les informations canal des cartes dans la présente carte"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - Uniquement pour test"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [|no. du 1er type de munition] [|no. du 2ème type de munition] - Chargement des munitions"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [|character name] - Guérir PV, UTC, CARBURANT à 100%, Guéris-toi toi-même sans [character name]"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [|decreasing quantity %] [|character name] - PV, UTC, et CARBURANT comptes pour [decreasing quantity %], 50% si [decreasing quantity %] n'est pas entré et si [character name] n'est pas présent il est pour personnage individuel"
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
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [|level] [|percentage of exp] [|character name] - Ajuste le niveau et le pourcentage d'expérience pour un personnage"


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
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Point d'expérience"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Objet Rare"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"terminé"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(minute)] - event set, annuler"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"Super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"terminé"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [standard|super|upgrade|terminé]"
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
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll [MapIndex] - Tous les membres de la guilde sont déplacés dans la carte spécifiée"
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer pour debugging"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - Liste tous les joueurs présents dans le serveur (indépendamment de la carte)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - Message enregistré sur le serveur envoyé par un admin au cours d'un Event"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - Montre tous les protocoles qu'un client et le serveur de MI envoient et reçoivent."
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - Serveur hors Service"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - Se déplacer vers la position spécifiée d'un personnage"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [character name] - Faire venir un personnage spécifié"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [guild name] - Appelle l'ensemble de la guilde"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [guild name] [map name] - Envoie une guilde dans une carte spécifique"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Pour basculer entre les chuchotements bloqués et autorisés"
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
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Pour contrôler le temps"
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
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - BonusStat augmenté"

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
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [chaîne qui sera cryptée]"
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
	#define STRCMD_CS_COMMON_DB_0000 "Uniquement lié au Serveur Mgame!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Merci de saisir votre nom d'utilisateur serveur"
	#define STRCMD_CS_COMMON_DB_0002 "Merci de saisir le mot de passe serveur"
	#define STRCMD_CS_COMMON_DB_0003 "Merci de saisir le nom d'utilisateur serveur"
	#define STRCMD_CS_COMMON_DB_0004 "Merci de saisir le mot de passe serveur"

	#define STRCMD_CS_COMMON_MAP_0000 "Partie Codée: Ignore le numéro 1 de la chaîne cible de la carte 0101, moyen facile de supprimer de l'éditeur de carte. Doit être trouvé et doit être supprimé!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "CARTE: %04d, m_DefaultWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Partie Codée: Ignore le numéro 1 de la chaîne cible de la carte 0101, moyen facile de supprimer de l'éditeur de carte. Doit être trouvé et doit être supprimé!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "CARTE: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Nombre total de monstres : [%4d] <== Y compris monstre objet\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Erreur de téléchargement du fichier"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Erreur de création fichier"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Erreur de lecteur du fichier téléchargé"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%djour%dheure%dminute%dseconde"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Réserve"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Réserve"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrateur"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Moniteur"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Invité"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Pour démo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Toutes les Races"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Race Inconnue"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Pas de nom"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Élève Officier"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3ème Pilote"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2ème Pilote"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1er Pilote"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3ème Wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2ème Wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1er Wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3ème Président"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2ème Président"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1er Président"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3ème As"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. Ace"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1er As"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Air-Commodore"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vice-maréchal de l'air"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Lieutenant Général"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Maitre Général"

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
	#define STRCMD_CS_ITEMKIND_FIXER				"Type Réparation"
	#define STRCMD_CS_ITEMKIND_DECOY				"Type d'appât"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Type d'équipement de Défense"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Type d'Equipement Support"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Type Energie"
	#define STRCMD_CS_ITEMKIND_INGOT				"Type Minéral"
	#define STRCMD_CS_ITEMKIND_CARD					"Type Carte Standard"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Type de Carte d'Enchantement"
	#define STRCMD_CS_ITEMKIND_TANK					"Type de Char"
	#define STRCMD_CS_ITEMKIND_BULLET				"Type de Munition"
	#define STRCMD_CS_ITEMKIND_QUEST				"Type d'item de quête"
	#define STRCMD_CS_ITEMKIND_RADAR				"Type radar"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Type Ordinateur"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Type de Carte pour parier"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Type Carte Prévention Suppression Enchantement"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Type Blaster"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Type Railgun"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Temps additionnel illimité"		// 2006-03-17 by cmkwon, »ç¿ë½ð£ÀÌ <¿µ¿ø>ÀÎ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Limite de temps additionnel"		// 2006-03-17 by cmkwon, »ç¿ë½ ½ð£ ÇÑÀÌ ÀÂ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Toutes les armes"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Arme Standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Type d'arme de munition standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Carburant Type Arme Standard"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Arme secondaire"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Type Munition Arme Avancée"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Type Bouclier Arme Avancée"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Compétence d'Attaque"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Compétence de Défense"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Compétence Support"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Attributs Compétence"
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
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Type Monstre de Réparation (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Type Monstre Appât (2-2type)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Type Monstre de Feu"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Crash Monstre possible Type Rayon"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Type Monstre Bombe"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Objet Inconnu"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Zone de vol inconnue"

	#define STRCMD_CS_STAT_ATTACK_PART				"Attaque"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Défense"
	#define STRCMD_CS_STAT_FUEL_PART				"Carburant"
	#define STRCMD_CS_STAT_SOUL_PART				"Esprit"
	#define STRCMD_CS_STAT_SHIELD_PART				"Bouclier"
	#define STRCMD_CS_STAT_DODGE_PART				"Évasion"
	#define STRCMD_CS_STAT_BONUS					"Statistiques Bonus"
	#define STRCMD_CS_STAT_ALL_PART					"Toutes les statistiques"
	#define STRCMD_CS_STAT_UNKNOWN					"Statistique Inconnue"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Type libre"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Multi-type"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Type d'agilité"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Type d'attaque"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Type de bouclier"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Type de défense"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Type de support"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¼¼·º° ÇØÇö  ±¸Çö - ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Armée Fédérale Vattalus"

	#define STRCMD_CS_POS_PROW						"Lieu de Radar (au centre en haut)"
	#define STRCMD_CS_POS_PROWIN					"Ordinateur (centre gauche)"
	#define STRCMD_CS_POS_PROWOUT					"Arme Standard (en haut à gauche)"
	#define STRCMD_CS_POS_WINGIN					"Ne sont pas utilisés (centre droit)"
	#define STRCMD_CS_POS_WINGOUT					"Arme Avancé (en haut à droite)"
	#define STRCMD_CS_POS_CENTER					"Armure (centre milieu)"
	#define STRCMD_CS_POS_REAR						"Moteur (en bas au milieu)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_ATTACHMENT				"ºÎÂø¹°(ÈÌ ¿ìÃø-¿¬·áÅÊ|ÄÁÅ×À)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Pièce annexe (arrière droite - réservoir de carburant | Container)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅÛ
	//#define STRCMD_CS_POS_PET						"»ç¿ë¾ÈÇÔ(ÈÌ ÁÂÃø)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Inutilisable (arrière gauche)"

	#define STRCMD_CS_POS_PET						"Partenaire"

    #define STRCMD_CS_HIDDEN_ITEM					"Position cachée"		// 2011-09-20 by hskim, ÆÊ ½ýºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

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
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [MonstreNom|MonstreNuméro]"

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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /DeleteNoticeboard [index of notice to be deleted] - Ajoute un message publique sur le support électronique de message pendant un certain temps."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - Supprime un message du support électronique de message."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Influence Président"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Influence Vice-Président"
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
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [Détails de la demande] - Demande de consultation avec un GM."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM [|Number(1~10)] - Pour contrôler la liste du nombre de consultation demandée pour un GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Number(1~10)] - Montre la liste du nombre de requêtes en consultation demandées par GM (supprimée par le serveur)"

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
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Donne des items spécifiques à tous les joueurs d'une nation dans la présente carte."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Couleur Item"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯¥ Çö ¹æ½ÄÀÌ ´£´Ù
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ¹¹(English):	MM-DD-YYYY HH:MM:SS
	// º£³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - Montre les utilisateurs de même niveau de distribution."	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Item Chance"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Marque"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// ¶ó¸¸ »ç¿ëÇÂ ¸í·î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [CharacterName] - Demande 1:1 conversation chat à un personnage spécifique."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Débute une conversation chat entre les membre d'une formation. Uniquement utilisable par le Président de la formation."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - Met fin à la conversation chat entre les membres d'une formation. Uniquement utilisable par le Président de la Formation."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Débute une conversation chat entre les membres de la brigade. Uniquement utilisable par le Président de la brigade."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - Met fin à la conversation chat entre les membres de la brigade. Uniquement utilisable par le Président de la brigade."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Met fin aux conversations chat brigade, formation, normal."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [CharacterName] - Demande de combat PvP avec le personnage sélectionné."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [CharacterName] -  Capitulation du combat PvP avec le personnage sélectionné."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [CharacterName] - Demande une formation en mode PvP à un personnage sélectionné (Président Formation). Uniquement utilisable par le Président de la Formation."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [CharacterName] - Demande un combat Brigade PvP à un personnage spécifié (Président Brigade). Uniquement utilisable par le Président de la brigade."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  Capitulation de la brigade en mode PvP. Uniquement utilisable par le Président de la brigade."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [CharacterName] [class(2 ~ 11)] - Change la position d'un personnage choisi. Seulement utilisable par le Président des brigades."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  Réinitialise la fenêtre du chat"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - On/Off Pour basculer dans le mode PvP"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  On/Off Bascule dans le mode du commerce"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Bloque les fenêtres popups. Les messages seront automatiquement stoppés."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Autorise les fenêtres popups."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Item Compétence Support"

// 2010-06-15 by shcho&hslee Æê½ýºÅÛ - Æê ¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Objet-partenaire"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Objet de case partenaire"		// 2011-09-01 by hskim, ÆÊ ½ýºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£³² Çç °ÔÀÓ ½ð£ °ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - Commande utilisée pour mettre en route ou éteindre le système de temps limité."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Cette commande affiche le temps de jeu du jour."

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ  ´£°Ô ¼³ - ¾¡¿¡ ¼¼·º°·Î ´£°Ô ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint mise à jour de la DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang Utilisateurs comptés"

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
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - Ceci montre l'état actuel de l'avancée sur le point stratégique."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"Il n'y a pas de point stratégique de guerre en cours."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Point stratégique de Guerre en progression."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Progression en cours"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Départ"

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

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [CharacterName] - Sauvegarde l'utilisateur à l'index n"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·Ã
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Initialise la DB du serveur Jamboree (atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Le personnage désigné sera dupliqué dans la DB du serveur Jamboree (atum2_db_20)."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Apprenti"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Pilote"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Equipier"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Vétéran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Commandant équipier"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Héros"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"Nom du serveur groupe"

// 2007-05-23 by dhjin, ARENA ÆÀ Ãâ·Â °ü·Ã ½º¸µ
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "L'Arène d'équipe ne peut pas être trouvée."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)] - Montre la progression actuelle dans l'Arène."

// 2010. 06. 04 by hsLee ARENA ÀÎÇÏ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format: /WatchStart - Pour débuter à visionner."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Arrête l'action de visionner."

// 2007-06-22 by dhjin, WarPoint á
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Ajoute des points de guerre."

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎ  °ü·Ã á
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Point de Guerre"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [character name] [|Time(minutes)] - Interdiction d'entrer dans l'arène"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [character name] - Interdiction de sortir de l'Arène"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Médaille de Brigade enregistrée avec succès."
#define STRMSG_070802_0002    "Inscription complétée après processus de contrôle."
#define STRMSG_070802_0003    "Acceptez vous %d  médailles de Brigade sélectionnées ?"
#define STRMSG_070802_0004    "Pas de médaille pour le statut de la brigade"
#define STRMSG_070802_0005    "Statut de médaille de la brigade en attente"
#define STRMSG_070802_0006    "Statut de médaille de la brigade normal"
#define STRMSG_070802_0007    "Erreur dans le statut de médaille de la brigade"

// 2007-08-24 by cmkwon, ½ºÇÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³ ±â´É á - ¸í·î á
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
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - Prépare l'arrêt du serveur, déconnecte tous les utilisateurs."

// 2007-08-30 by cmkwon, Àë ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [|CharacterName] ? Peut uniquement être utilisé par un Président. Autorise le joueur choisi à entrer dans la salle de conférence."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[ EntrancePermissionDeny] [CharacterName] ? Peut uniquement être utilisé par un Président. Supprime le joueur choisi de la liste de la salle de conférence."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d jour(s) %d heure(s) %d minute(s) %d seconde(s)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d année %d mois %d jour", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d année %d mois", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d mois %d jour", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Vice-Président 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Vice-Président 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Commandant Général"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Commandeur adjoint"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Chef de l'Equipe"
#define STRCMD_ANI_INFLUENCE_LEADER						"Président"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vice-président"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Directeur Stratégique"
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
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Démarrer"
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
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Un point de guerre sera accordé dans la présente carte pour les utilisateurs de la Nation sélectionnée."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - Début du système d'appel"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Quitte le système d'appel"

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
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Numéro Item] [# d'items] - L'utilisateur loggué de la nation sélectionnée recevra l'objet désigné"

// 2008-02-21 by dhjin, ¾¹³ªÅëÇÕ- ¾¹³ªá¸í·î
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

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °ö½Ã ¹º¿¡¼­ °ö ±â´É á(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Tous les types"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Membre"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Commandant de la brigade de vol"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Co-Brigade Président"				// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1er Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1er Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2ème Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2ème Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3ème Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3ème Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4ème Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4ème Bataillon Membre"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5ème Bataillon Commandant"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5ème Bataillon Membre"

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
#define STRMSG_080821_0001				"Le rang ne peut pas être attribué au joueur sélectionné."


// 2008-09-09 by cmkwon, /¼¼·¼Ò ¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀÔ á - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [nombre de personne maximum] [0|niveau minimum] [0|niveau maximum] [1(B)|16(M)|256(A)|4096(I)] [Message au joueur] - Demander à une nation et aux joueurs d'un certain niveau de se déplacer dans la carte d'évent."

// 2008-09-09 by cmkwon, "/kick" ¸í·î á - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Ejecte le personnage spécifié du jeu."


// 2008-09-12 by cmkwon, "/¸" ¸í·î á - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Gloire"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Gloire"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"Format:  /Gloire [Gloire personnelle] [Gloire de la Brigade] - Augmente la gloire du personnage et de sa brigade."

// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format : /ReleaseLeaderChatBlock [NomduPerso] - Suppression de la restriction chat du Leader."

// 2009-10-12 by cmkwon, ½º °Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|Charaktername] - Choisissez votre ville d'origine, 2001 ou 2002, si vous avez déjà choisi votre nation"


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, Ãë ·¹º§ »óÇ µû¸¥ á »çÇ×(·¹º§º° °è±Þ) - °è±æ(¹éºÎÀå, ´ë·É, À, ö, º¹ÀÚ, ¼öÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Brigadier"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Lieutenant-colonel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "Général de division"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Général de brigade"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conquérant"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Gardien"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Légende"
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
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Informations sur les membres de la formation du joueur (les membres doivent être connectés au jeu)"
// End. 2013-11-19 by bckim, ÆÄ¿ø º¸ º¸±â ¸í·î Ã¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





