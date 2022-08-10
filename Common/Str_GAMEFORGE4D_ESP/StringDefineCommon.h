// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"formato: /ment [|String] - Configura el ment del personaje"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"formato: /move [MapIndex] [|ChannelIndex] - Va al canal del mapa indicado"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"formato: /coordinate [X] [Y] - Lleva a la coordenada indicada en el mapa"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"formato: /list - Muestra todos los usuarios del mapa actual  (Máximo 20 usuarios)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"formato: /senduser [personaje] [mapa] - Mueve un personaje al mapa deseado"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"formato: /info [monstruo|item] - Muestra información acerca de los monstrus o items en la cadena"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"formato: /quest - Muestra informacion de la mision al personaje"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"formato: /delQuest [Número quest]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"formato: /itemKind [|item kind(0~53)] - Muestra los tipos de item seleccionados"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"formato: /insertItemKind [item kind(0~53)] -  Tipos de item especiales adicionales"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"formato: /insertItemNumRange [de num item] ~ [a num. item] - Items especiales adicionales"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"formato: /initStatus - Inicializa todo el status"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"formato: /partyInfo - Muestra información de partidos"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"formato: /Time [|additional time(0~23)] - Cambia la hora actual (solo se modifica la hora individual)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"formato: /string [0~5] - Decide que nivel se muestra en el mensaje debug."
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"formato: /summon [num monstruo|nombre monstruo] [# of monsters] - Trae monstruos ('_' se usa cuando el nombre del monstruo tenga un espacio)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"formato: /allSkill [nivel] - Añade todos los skills"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"formato: /allItem - Introduce todos los items, sin skills ni items contables"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"formato: /allWeapon - Todas las armas equipables para el Gear"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"formato: /delAllItem - Elimina todos los items no equipados (sin skill)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"formato: /item [num. item] [# of items] - Los items conseguidos se tratan como 1 item cuando  [# of items] no se haya introducido."
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"formato: /dropItem [num. item] [|# de los items] - Deja caer items en el campo."
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"formato: /server - Listado de información del servidor"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"formato: /serverMap - Muestra informacion del mapa"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"formato: /channelInfo - Muestra información acerca del mapa de los canales en el mapa actual"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"formato: /dbg - Sólo para pruebas"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"formato: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"formato: /chargeBullet [|Número munición estándar] [|Número munición secundaria] - Recargar munición"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/manpi"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"formato: /repairAll [|personaje] - Cura HP, UTC, Deposit de 100%, te cura a ti mismo sin poner el personaje"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/banpi"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"formato: /repairParam [|decreasing quantity %] [|personaje] - HP, TUC, y cuentas COMBUSTIBLE para [decreasing quantity %], 50% cuando [decreasing quantity %] no indicado y el  [nombre personaje] no disponible, para personaje individual."
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"formato: /normal - Cambia a una cuenta normal de una cuenta Admin o GameMaster"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Cambiar de una cuenta normal a una cuenta de Admin o Game Master"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"formato: /invincible - En el modo GameMaster o Manager no se puede recibir daño."
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"formato: /powerUp [Aumenta el poder de ataque(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"formato: /setVariable [variable] - Establece una variable"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"formato: /level [|level] [|porcentaje de exp] [|personaje] - Cambia el nivel y el porcentaje de experiencia del personaje"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"formato: /invisible -  Invisible para otros personajes"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"formato: /msgf - Sólo para pruebas"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Punto experiencia"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Itemraro"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"Objetivo"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"formato: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|rate %f|finish] [time(minute)] - Event Set, Cancelar"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"Estándar"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"Super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"Upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"Objetivo"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"formato: /premium [Standard|Super|Upgrade|Objetivo]"
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
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"formato: /returnAll [MapIndex] - Todos los miembros de la alianza son llevados al mapa"
// start 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅ? - ¸®½º ½ýºÅ?
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅ? - ¸®½º ½ýºÅ?


// start 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ¼­¹ö Á¤º¸ º¸±â
// end 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö

// start 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ¼­¹ö º¸ º¸±â
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î

// 2007-10-30 by cmkwon, ¼¼·º?ÇØÇö  ±¸Çö - ¸í·î Çü½Ä ¼öµÊ ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
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
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"formato: /testi - Servidor IM para debug"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"formato: /who [|# of users] - Listado de todos los usuarios del servidor (con independencia del mapa)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"formato: /registerAdmin - Registra el servidor para enviar un mensaje al admin durante el evento"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"formato: /msgi - Muestra el protocolo que envía y recibe el cliente y el servidor IM.*"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"formato: /serverDown [certified no.] - Server shutdown"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"formato: /whoareYou [personaje]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"formato: /go [nombre personaje] - Va a la posición del personaje"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"formato: /comeon [nombre personaje] - Llama al personaje seleccionado"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"formato: /comeonGuild [nombre alianza] - Llama a toda la alianza"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"formato: /comeonGuild [nombre alianza] [mapa]- Envia a la alianza al mapa deseado"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"formato: /whisperChat - Cambia entre susurrar permitido y no permitido"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"formato: /guildInfo - Muestra información acerca de la alianza"
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
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"formato: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - Controla el tiempo"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"formato: /forbidChat [Nombre jugador] [Tiempo(min.)] - Prohibir chat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"formato: /releaseChat [tiempo(min.)] - Termina el chat prohibido."
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"formato: /? - Listar los comandos disponibles"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"formato: /BonusStat [Bonus Counts] [|nombre personaje] - Aumentar BonusStat"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"formato: /setPassword [cuenta] [contraseña]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"formato: /rollbackPassword [cuenta]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"formato: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"formato: /encrypt [Cadena es encriptada]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"formato: /blockAccount [Nombre cuenta]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"formato: /releaseAccount [Nombre cuenta]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"formato: /blockedList"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "¡Solo perteneciente al Mgame Server!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Introduce el Login del servidor"
	#define STRCMD_CS_COMMON_DB_0002 "Introduce la contraseña del servidor"
	#define STRCMD_CS_COMMON_DB_0003 "Introduce el login de la BD"
	#define STRCMD_CS_COMMON_DB_0004 "Introduce la contraseña del Servidor"

	#define STRCMD_CS_COMMON_MAP_0000 "Parte programada: Ignora número 1 objetivo warp en el mapa 0101, se debe buscar una forma más facil para borrar del editor de mapa!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAPA: %04d, m_DefaultWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Parte programada: Ignora objetivo warp numero 1 en el mapa 0101, sebe buscar y eliminar un camino facil para borrar del editor de mapa."
	#define STRCMD_CS_COMMON_MAP_0003 "MAPA: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] Llamar monstruo[%8d] Ruf Zeit[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] Llamar monstruo[%8d] Ruf Zeut[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Cantidad total monstruos : [%4d] <== Incl. objeto monstruo\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Error descarga archivo"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Error crear archivo"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Error lectura archivo"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%ddía%dhora%dminuto%dsegundo"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Relicario"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Reserva"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Reserva"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrador"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Invitado"
	#define STRCMD_CS_COMMON_RACE_DEMO			"A la Demo"
	#define STRCMD_CS_COMMON_RACE_ALL			"Todas las razas"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Raza desconocida"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Sin nombre"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Cadete"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3. Piloto"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2. Piloto"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1. Piloto"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3. Wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2. Wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1. Wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3. Líder"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2. Líder"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1. Líder"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3. As"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2. As"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1. As"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Comodoro del aire"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Vice-Mariscal del aire"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Teniente General"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"General completo"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Tipo automático"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Tipo Volcán"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Tipo dualista"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Tipo cañon"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Tipo fusil"
	#define STRCMD_CS_ITEMKIND_GATLING				"Tipo Gatling"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Tipo lanzamisiles"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Tipo impulso en masa"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Tipo misiles"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Tipo misiles"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Tipo bulto"

	#define STRCMD_CS_ITEMKIND_MINE					"Tipo minas"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Tipo escudo"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Tipo Dummy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Tipo reparación"
	#define STRCMD_CS_ITEMKIND_DECOY				"Tipo anzuelo"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Tipo defensa-equipamiento"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Item de apoyo-equipamiento"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Tipo energía"
	#define STRCMD_CS_ITEMKIND_INGOT				"Tipo Mineral"
	#define STRCMD_CS_ITEMKIND_CARD					"Tipo mapa estándar"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Tipo carta de encantamiento"
	#define STRCMD_CS_ITEMKIND_TANK					"Tipo Panzer"
	#define STRCMD_CS_ITEMKIND_BULLET				"Tipo bala"
	#define STRCMD_CS_ITEMKIND_QUEST				"Tipo item misión"
	#define STRCMD_CS_ITEMKIND_RADAR				"Tipo Radar"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Tipo ordenador"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Tipo tarjeta de la suerte"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Tipo Upgrade-tarjeta-evitar-borrado"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Tipo Blaster"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Tipo Railgun"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Adición ilimitada"		// 2006-03-17 by cmkwon, »ç¿ë½ð£ÀÌ <¿µ¿ø>ÀÎ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Tiempo limite-adición"		// 2006-03-17 by cmkwon, »ç¿ë½ ½ð£ ÇÑÀÌ ÀÂ ¾¼¼­¸® ¾ÆÀÌÅÛ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Todas las armas"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Arma estándar"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Tipo bala arma estándar"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Tipo tanque arma estándar"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Arma secundaria"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Tipo bala arma secundaria"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Tipo escudo arma secundaria"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Skill ataque"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Skill defensa"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Skill apoyo"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Skill atributo"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item para monstruos tipo 1"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Tipo monstruo ametralladora (tipo 1-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Tipo monstruo rayo (Tipo 1-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Ataca todos los monstruos"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item para monstruo tipo 2"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Misil monstruo (tipo 2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Tipo monstruo misiles (tipo 2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Tipo monstruo bulto (Tipo 2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Tipo monstruo mina (tipo 2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Tipo monstruo escudo (tipo 2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Tipo dummy monstruo (tipo 2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Tipo monstruo reparación (Tipo 2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Tipo trampa monstruo (tipo 2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Tipo monstruo fuego"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Tipo posible monstruo rayos Crash"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Monstruo bombas rectas tipo"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Item desconocido"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Célula de vuelo desconocida"

	#define STRCMD_CS_STAT_ATTACK_PART				"Ataque"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Defensa"
	#define STRCMD_CS_STAT_FUEL_PART				"Combustible"
	#define STRCMD_CS_STAT_SOUL_PART				"Skill"
	#define STRCMD_CS_STAT_SHIELD_PART				"Escudo"
	#define STRCMD_CS_STAT_DODGE_PART				"Evasión"
	#define STRCMD_CS_STAT_BONUS					"Bonus Stats"
	#define STRCMD_CS_STAT_ALL_PART					"Todos los stats"
	#define STRCMD_CS_STAT_UNKNOWN					"Stat desconocido"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Tipo libre"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Tipo ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Tipo multi"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Tipo ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Tipo movimiento"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Tipo ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Tipo escudo"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Tipo defensa"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Tipo apoyo"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¼¼·º° ÇØÇö  ±¸Çö - ¾¡¿¡¼­ ´Ã ÀÇ ÇÔ
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Ejército de federación Vattalus"

	#define STRCMD_CS_POS_PROW						"Lugar Radar (arriba en medio)"
	#define STRCMD_CS_POS_PROWIN					"Ordenador (en medio izquierda)"
	#define STRCMD_CS_POS_PROWOUT					"Arma estándar (arriba izquierda)"
	#define STRCMD_CS_POS_WINGIN					"No usado (medio derecha)"
	#define STRCMD_CS_POS_WINGOUT					"Arma avanzada (arriba derecha)"
	#define STRCMD_CS_POS_CENTER					"Blindaje (medio)"
	#define STRCMD_CS_POS_REAR						"Motor (abajo medio)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅ?
	//#define STRCMD_CS_POS_ATTACHMENT				"ºÎÂø¹°(ÈÌ ¿ìÃø-¿¬·áÅÊ|ÄÁÅ×À)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accesorio (lado derecho trasero - depósito | contenedor)"

	// 2010-06-15 by shcho&hslee Æê½ýºÅ?
	//#define STRCMD_CS_POS_PET						"»ç¿ë¾ÈÇÔ(ÈÌ ÁÂÃø)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"No utilizable (lado izquierdo trasero)"

	#define STRCMD_CS_POS_PET						"Compañero"

    #define STRCMD_CS_HIDDEN_ITEM					"Posición oculta"		// 2011-09-20 by hskim, ÆÊ ½ýºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

	#define STRCMD_CS_POS_INVALID_POSITION			"Lugar flotante"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Lugar inventario"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/QuestComplete"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"formato: /QuestComplete [|QuestIndex]"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/NationRatio"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"formato: /NationRatio"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/ChangeNation"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"formato: /ChangeNation [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMon"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"formato: /GoMonster [Nombre monstruo|Num. monstruo]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ× -  ó¸?¹Î 
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
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"formato: /Noticeboard [|Duración(unit:min) [Notice details] - Añade un mensaje al tablón de notas electrónico durante un tiempo."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"formato: /DeleteNoticeboard [index of notice to be deleted] - Elimina una nota del tablón de notas electrónico."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Influencia líder"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Influencia vice-líder"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Influencia líder"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Influencia evento"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"formato: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Aumenta la aportación de una nación"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"formato: /CallGM  [Detalle de la solicitud] - Enviar solicitud al GM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"formato: /ViewCallGM   [|Número(1~10)] - Verifica el numero de la solicitud de support por el GM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"formato: /BringCallGM [|Número(1~10)] - Lleva la solicitud de soporte al GM con el número indicado (y se borra en el servidor)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"
// 2008-09-09 by cmkwon, /¼¼·¼?¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀ??- commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnNation [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [MAX_USER] [0|Min-level] [0|Max-level] [message to users] - Summons all specified level users in nation with a message."

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"formato: /SendItem [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [Num item] [# of items] - Da un item a todos los miembros de la nación en el mapa actual"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Item color"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯?Çö ¹æ½ÄÀÌ ´£´Ù
	// (Korea):		YYYY-MM-DD HH:MM:SS
	// ¹¹(English):	MM-DD-YYYY HH:MM:SS
	// º£³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"formato: /LevelDistribution - Muestra niveles de usuario similares"	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Tipo posibilidades"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Marcaje"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// ¶óÀ­¸¸ »ç¿ëÇÂ ¸í·î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"formato: /call [personaje] - Solicitud al personaje para un chat 1:1."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"formato: /formcall - Inicia chat de voz entre miembros formación. Sólo lo puede usar el líder de la formación."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramto: /formcallend - Finaliza chat entre miembros de formación. Solo lo puede usar el líder de la formación."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"formato: /brigcall - Iniciar chat de voz entre miembros de brigada. Solo lo puede usar líder de brigada."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"formato: /brigcall - Iniciar chat de voz entre miembros brigada. Solo lo puede usar líder de brigada."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"formato: /endcall - Finaliza formación Brigada o chat normal."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"formato: /fight [personaje] - Solicitud batalla PvP al personaje"
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"formato: /surrender [personaje] -  Se rinde en una batalla PvP con el personaje seleccionado."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"formato: /formfight [personaje] - Solicitud a un personaje (Líder de formación) para PvP de formación. Solo lo puede usar el líder de formación."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"formato: /brigconfront [personaje] -  Solicitud a un personaje (Líder Brigada) para PvP de Brigada. Solo lo puede usar líder de brigada."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"formato: /brigsurrender -  Mision en una batalla de brigada PvP. Solo lo puede usar el líder de brigada."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"formato: /name [personaje] [class(2 ~ 11)] - Finaliza el puesto de un personaje. Sólo lo puede usar el líder de brigada."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"formato: /initchat -  Recarga la ventana de chat"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"formato: /refusefight - on/off Pone las opciones de rechazo PvP"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"formato: /refusetrade -  on/off indica las opciones de rechazo de comercio"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"formato: /Closewindow -  Evita Popups de mensajes. Los mensajes son finalizados automáticamente."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"formato: /Openwindow -  Permitir mensajes Popup"

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Item skill de apoyo"

// 2010-06-15 by shcho&hslee Æê½ýºÅÛ - Æê ¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Ítem de compañero"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Ítem de slot de compañero"		// 2011-09-01 by hskim, ÆÊ ½ýºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£³² Çç °ÔÀÓ ½ð?°ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"On"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"Off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"formato: /TimeLimitSystem [on|off] - Se usa para activar o desactivar el limite de tiempo."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"formato: /PlayTime - Este comando muestra el tiempo jugado de hoy."

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ  ´£°Ô ¼³ - ¾¡¿¡ ¼¼·º°·?´£°Ô ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"formato: /BonusStatPoint [BonusStatPoint Counts] [|nombre personaje] - BonusStatPoint update a la BD"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"formato: /PCBang - PCBang contador usuario"

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
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"formato: /StrategyPointInfo - Muestra el estado de los puntos estratégicos actuales."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"No hay una guerra de puntos estratégicos en marcha."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Guerra de puntos estratégicos activa."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Lugar de desarrollo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Hora comienzo"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear total"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear total"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear total"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear total"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear total"

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"formato: /Observer [n] [personaje] - Nombre personaje se guarda usuario en Index n"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·Ã
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"formato: /InitJamboree [validation number] - Inicia servidor Jamboree DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"formato: /EntrantJamboree [Personaje] - El personaje es duplicado en el servidor Jamboree DB (atum2_db_20)."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Aprendiz"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Piloto"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Wingman"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "As"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Veterano"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Comandante de escuadrón"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Héroe"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"Version Launcher"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"Versión Cliente"
// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"Nombre cuenta"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"Nombre grupo servidor"

// 2007-05-23 by dhjin, ARENA ÆÀ Ãâ·Â °ü·Ã ½º¸µ
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "No se puede encontrar el equipo de Arena."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "formato: /arena [2(VCN)|4(ANI)]- Muestra el estado actual de la Arena"

// 2010. 06. 04 by hsLee ARENA ÀÎÇÏ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÇÏ Çå 2Â÷ ³­ Àý. (GM ¸í·î á. /nextscene(´Ù ½ó¶ ¾À Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"formato:/WatchStart-Comienza el contemplar"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"formato: /WatchEnd ? Finaliza la visión"

// 2007-06-22 by dhjin, WarPoint á
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "formato: /WarPoint [Number 1~1000000] [|Username] ? Añade puntos de guerra"

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎ  °ü·Ã á
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"Punto guerra"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "formato: /forbidArena [nombre personaje] [|tiempo(minutos)] - Prohibir entrada Arena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "formato: /releaseArena [nombre personaje] - Retirar prohibición Arena"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "Signo de brigada registrado correctamente."
#define STRMSG_070802_0002    "El registro finaliza tras el procesado de ordenación."
#define STRMSG_070802_0003    "¿Aceptas %d el signo elegido?"
#define STRMSG_070802_0004    "No hay status de signos de brigada"
#define STRMSG_070802_0005    "Signo brigada en status de espera"
#define STRMSG_070802_0006    "Signo de brigada en status normal"
#define STRMSG_070802_0007    "Error status signo de brigada"

// 2007-08-24 by cmkwon, ½ºÇÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³ ±â´É á - ¸í·î á
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Activar"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Prohibir"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"formato: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Permite/deniega el uso del item de altavoz"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Comenzar"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Publicación"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"formato: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - Prepara apagado servidor, desconecta todos los usuarios."

// 2007-08-30 by cmkwon, Àë ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "formato: /[EntrancePermission] [Nombre jugador]? Sólo puede ser usado por líderes. Añade al jugador a la lista de entrada del canal de conferencia."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "formato: /[EntrancePermissionDeny] [Nombre jugador] ? Sólo puede ser usado por líderes. Borra al usuario de la lista de entrada del canal de conferencia."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d día(s) %d hora(s) %d minuto(s) %d segundo(s)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d año %d mes %d días", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d año %d mes", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d mes %d día", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Líder inferior 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Líder inferior 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"Comandante General"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Comandante adjunto"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Líder Estado mayor"
#define STRCMD_ANI_INFLUENCE_LEADER						"Líder"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vice-Presidente"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Director estratégico"
#define STRCMD_OUTPOST_GUILD_MASTER						"Cap. %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"formato: /appointment1 [Personaje] - BCU : Pone el nombre del primer sub-líder BCU, ANI: Pone el nombre del primer sublider"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"formato: /appointment2 [personaje] - BCU : Fija a la nación BCU el nombre del segundo líder, ANI : Fija al segundo lider"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Comienzo"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"Fin"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"formato: /HappyEvent [255(AllNation)|0(NormalNation)|2(VCN)|4(ANI)] [Start|End] [tiempo(Unit:Minute)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Nación normal"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"Todanación"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"formato: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Los usuarios de la nacion deseada reciben un punto de guerra en el mapa deseado"

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"formato: /StartHelper [|time(Unit: Minute)] - Comienza solicitud"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"formato: /EndHelper - Finaliza el sistema de llamada"

// 2007-12-27 by cmkwon, µµ¿ìÁî ¸ðµå ±â´É á - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW á
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, µµ¿ì¸ðµå »óÅÂ ÀúÀåÇâ - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"Modo ventana"

// 2008-01-31 by cmkwon, °è º/ÇØ ¸í·î·Î °¡´ÉÇÑ ½ýºÅÛ ±¸Çö - ¸í·î á
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"formato: /Block [Cuenta] [Tipo(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"formato: /Unblock [cuenta]"

// 2008-02-20 by cmkwon, ¸í·îá(¼ÓÁßÀÎÀú¸ÆÀÌÅÛÁö±Þ- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "formato: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Num. item] [# de los items] - Los usuarios conectados de la nación reciben el item seleccionado."

// 2008-02-21 by dhjin, ¾¹³ªÅëÇÕ- ¾¹³ªá¸í·î
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "formato: /TeamArenaLeave [2(Azul)|4(Rojo)|6(Azul y Rojo)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "formato: /TargetArenaLeave [Personaje]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "formato: /ArenaEvent [número canal]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "formato: /ArenaEventRelease [número canal]"

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °ö½Ã ¹º¿¡¼­ °ö ±â´É á(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Todas las clases"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Miembro"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Líder brigada de vuelo"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Colíder Brigada"				// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼ö »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1. Comandante Batallón"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1. Miembro Batallón"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2. Comandante Batallón"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2. Miembro Batallón"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3. Comandante Batallón"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3. Líder Batallón"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4. Comandante Batallón"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4. Miembro Batallón"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5. Comandante Batallón"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5. Miembro Batallón"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ÀüÀ
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ¼¼·¸¶ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"formato: /influencemarkevent [Nación 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"formato: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ¹ PC¹æ IPº¸ ·ù
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ÀÝ, ¼ö °èÀÇ ºÎÁöµµÀÚ Àí ÇÑ
#define STRMSG_080821_0001				"El rango no puede darse al jugador seleccionado."


// 2008-09-09 by cmkwon, /¼¼·¼Ò ¸í·î ÀÎÀÚ ¸®½º¿¡ ±â¾îŸÀÔ á - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"formato: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [cantidad máx. personas] [0|Nivel mínimo] [0|Nivel máximo] [1(B)|16(M)|256(A)|4096(I)] [Mensaje al usuario] - Encargo a la nación, usuarios del nivel deben ir al mapa de eventos."

// 2008-09-09 by cmkwon, "/kick" ¸í·î á - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"formato: /Kick [personaje] - Expulsa al personaje del juego."


// 2008-09-12 by cmkwon, "/¸" ¸í·î á - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fama"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fama"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"Formato:  /Fama [fama personal] [fama de la brigada] - Aumenta la fama del personaje y de su brigada."

// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"Formato: /ReleaseLeaderChatBlock [personaje] - La restricción de chat del líder es suprimida."

// 2009-10-12 by cmkwon, ½º °Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "Formato: //StartCity [2001|2002] [|Nombre del personaje] - Una vez seleccionada una nación, puedes seleccionar la ciudad de tu personaje en los servidos 2001 o 2002."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, Ãë ·¹º§ »óÇ µû¸¥ á »çÇ×(·¹º§º° °è±Þ) - °è±æ(¹éºÎÀå, ´ë·É, À, ö, º¹ÀÚ, ¼öÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurión"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Teniente Coronel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "Teniente General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "General Mayor"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conquistador"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardián"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Leyenda"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Estándar"

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
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] -información sobre los miembros de la formación del jugador (los miembros deben estar conectados)"
// End. 2013-11-19 by bckim, ÆÄ¿ø º¸ º¸±â ¸í·î Ã¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





