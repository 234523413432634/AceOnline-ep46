// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/mensaje"
	#define STRCMD_CS_COMMAND_MENT_HELP					"formato: /mensaje [|String] ?Establece el mensaje del personaje"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/mover"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"formato: /mover [MapIndex] [|ChannelIndex] ?Se dirige al mapa especificado"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordenada"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"formato: /coordenada [X] [Y] ?Transporta a la coordenada especifica del mapa"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/lista"
	#define STRCMD_CS_COMMAND_LIST_HELP					"formato: /lista ?Establece una lista de usuarios en el mapa (Hasta un maximo de veinte usuarios)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/enviarusuario"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"formato: /enviarusuario [Nombre personaje] [mapa] ?Transfiere al personaje a un mapa especifico"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"formato: /info [Monstruo|Objeto] ?Proporciona informacion detalla del monstruo u objeto"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/mision"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"formato: /mision ?Muestra la informacion de la mision del personaje"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delMision"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"formato: /delMision [mision n?"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/objetoTipo"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"formato: /objetoTipo [|tipo de objeto(0~53)] ?Muestra los tipos especificos de objetos"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/ingresarTipoObjeto"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"formato: /ingresarTipoObjeto [tipo de objeto(0~53)] -  Tipos adicionales de objetos"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/ingresarObjetoNumRango "
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"formato: /ingresarObjetoNumRango [del numero de obj] ~ [hacia numero objeto] ?Adicion de objetos especiales especificos"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initEstadisticas"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"formato: /initEstadisticas ?Reinicia las estadisticas completas"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"formato: /partyInfo ?Muestra la informacion de la party"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Tiempo"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"formato: /Tiempo [|tiempo adicional(0~23)] ?cambia el tiempo actual (solo el tiempo individual es modificado)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"formato: /string [0~5] ?Decide los niveles mostrados en el mensaje de Debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/Invocar"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"formato: /Invocar [numero de monstruo|nombre de monstruo] [# cantidad de monstruos] ?Invoca a los monstruos ('_' se utiliza si el monstruo cuenta con un espacio en su nombre)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/todasHabilidades"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"formato: /todasHabilidades [Nivel] ?Establece todas las habilidades existentes"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/todoslosObjetos"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"formato: /todoslosObjetos ?Ingresa todos los objetos especificos a excepcion de habilidad y consumibles"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/todaslasArmas"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"formato: /todaslasArmas ?Set completo de armas para el Gear"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/deltodoslosobjetos"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/deltodoslosobjetos"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /deltodoslosobjetos ?Elimina todos los objetos que no se encuentren equipados (excluyendo habilidades)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/objeto"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /objeto [numero de objeto] [# numero de objetos] ?Adquiere objetos, asumiendo por defecto una unidad si no se especfica el [# numero de objetos] "
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/arrojarObjeto"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"formato: /arrojarObjeto [numero de objeto] [|# cantidad de objetos] ?Arroja objetos en el campo"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server ?Lista la informacion del servidor"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"formato: /serverMap ?Muestra informacion de todo el mapa"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"formato: /channelInfo ?Muestra la informacion del mapa actual"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"formato: /dbg ?Para testeos UNICAMENTE"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"formato: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/CargarMunicion"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"formato: /CargarMunicion [|cantidad de primer arma] [|cantidad de segundo arma] ?recarga municiones"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/repararTodo"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"formato: /repararTodo [|nombre del personaje] ?Recarga todos los parametros (HP, da?, escudo). Se aplica sobre ti mismo si no se especifica nombre"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/ReparacionParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"formato: /ReparacionParam [|cantidad extraida %] [|nombre del personaje] ?HP, Escudo y Combustible [Cantidad que decrece  %], 50% si [el % de decrecimiento] no es establecido, y si el [nombre del personaje] no esta presente se asume un personaje individual"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"formato: /normal ?Cambia a una cuenta a normal en modo Game Master o Administrador"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/especializar"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"formato: /especializar ?Cambia una cuenta normal a formato Game Master o Administrador"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/musuk"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invensible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"formato: /invensible ?No se recibe da? como Game Master o Administrador"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"formato: /powerUp [Incrementa el poder ofensivo (%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"formato: /setVariable [variable] - ajuste (normal) de variables "
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/nivel"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"formato: /nivel [|nivel] [|porcentaje de experiencia] [|nombre del personaje] ?Ajusta los niveles de experiencia de los personajes"


	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/NivelCompanero"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/NivelCompanero"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"formato: /NivelCompanero [|Nivel] [|Porcentaje de Exp] "


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"formato: /invisible -  Invisible a los otros personajes"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"formato: /msgf ?Para test UNICAMENTE"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/evento"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"exppuntos"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restablecerexppuntos"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"objeto"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"objetoraro"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"finalizar"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"formato: /evento [Listado previo] [|porcentaje %f|finalizar] [tiempo(minutos)] - evento seteado, cancelar"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finalizar"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"formato: /premium [standard|super|upgrade|finalizar]"

	#define STRCMD_CS_COMMAND_CITYWAR					"/guerraciudad"
//	#define STRCMD_CS_COMMAND_CITYWAR					"/citywar"
	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"comenzar"
	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finalizar"
	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"formato: /guerraciudad [comenzar|finalizar]"
	#define STRCMD_CS_COMMAND_STEALTH					"/camuflaje"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"formato: /camuflaje"
	#define STRCMD_CS_COMMAND_RETURNALL					"/regresarTodos"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"formato: /regresarTodos [MapIndex] ?Todos los miembros en la brigada son movidos a este mapa"	

// start 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅÛ] - ¸®½º ½ýºÅÛ
	#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"formato: /resetTrigger [TriggerNumber] - Apaga el gatillo y el evento volvera por defecto."
// end 2011-10-28 by hskim, EP4 [¸®°Å ½ýºÅÛ] - ¸®½º ½ýºÅÛ

// start 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testdropmonstruo"		// ¼­¹ö Á¤º¸ º¸±â
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testdropmonstruo"
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"formato: /testdropmonstruo [Cantidad de monstruos] [numeros de prueba : (1~100000)] - Muestra los objetos que seran soltados por los monstruos. (Esta accion genera una gran carga en el servidor. No utilizarlo a menos que sea necesario)"
// end 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø  ¸í·î

// start 2011-06-22 by hskim, » ¼­¹ö ¹æÁö
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ¼­¹ö º¸ º¸±â
// end 2011-06-22 by hskim, » ¼­¹ö ¹æÁö


	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/happyEvent"
	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/felizEvento"
	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"comenzar"
	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"fin"
	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"formato: /felizEvento [comenzar|fin] [tiempo de progreso(unidad:min.)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - Command used in IMServer, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"formato: /testi - IMServer para debug"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/quien"
	#define STRCMD_CS_COMMAND_WHO_HELP					"formato: /quien [|# cantidad de usuarios] ?Lista todos los usuarios presentes sin importar el mapa"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registrarAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"formato: /registrarAdmin ?Registrar al servidor para enviarle un mensaje al administrador durante el progreso de un evento"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"formato: /msgi ?Muestra todo el protocolo que el  IM server y el cliente envian y reciben"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"formato: /serverDown [certified no.] - Server shutdown"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/quieneresTu"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"formato: /quieneresTu [nombre del personaje]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/ir"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"formato: /ir [nombre del personaje] ?Mueve a la posicion especifica del personaje"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"formato: /comeon [nombre del personaje] ?llama al personaje especificado"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"formato: /comeonGuild [nombre de brigada] ?invoca a la brigada entera"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"formato: /sendGuild [nombre briada] [nombre mapa] ?envia a la brigada a un mapa especifico"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/susurroChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"formato: /susurroChat ?bloquea o cancela los susurros, modificable."
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"formato: /guildInfo ?Muestra la informacion de la brigada"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/clima"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"despejado"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"lluvia"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"nieve"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"nublado"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"neblina"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"todo"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"formato: /weather [efecto climatico] [todo|nombre del mapa] [on|off] ?Controla el clima"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/MuteChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"formato: /MuteChat [nombre del personaje] [tiempo(min.)] ?Prohibe el chat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/liberarChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"formato: /liberarChat [tiempo(min.)] ?Cancela la prohibicion de chat"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/comando"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"formato: /? ?la lista de comandos es mostrado"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"formato: /BonusStat [Cantidad de bonus] [|nombre del personaje] ?incremento en las estaditicas a manera bonus"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"formato: /setPassword [Nombre de Cuenta] [Contrase?]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"formato: /rollbackPassword [Nombre de Cuenta]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"formato: /passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"formato: /encrypt [string que sera encriptada]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"formato: /blockAccount [Nombre de Cuenta]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /releaseAccount [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"formato: /blockedList"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Solo relacionado con el servidor de M-Game!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Por favor ingresar l Log-In de Acceso al servidor"
	#define STRCMD_CS_COMMON_DB_0002 "Por favor ingresa la clave de acceso"
	#define STRCMD_CS_COMMON_DB_0003 "Por favor ingresa el nombre de Log-In de la DB"
	#define STRCMD_CS_COMMON_DB_0004 "Por favor ingresa la clave de acceso"

	#define STRCMD_CS_COMMON_MAP_0000 "Hard coded part: Ignore number 1 warp target at 0101 map, easy way to delet from map editor need to be found and needs to be deleted!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Hard coded part: Ignore number 1 warp target at 0101 map, easy way to delet from map editor need to be found and needs to be deleted!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Total Monster Count : [%4d] <== Including object monster\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "Error en la descarga de archivos"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "Error en la creacion de archivos"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "Error en la lectura de archivos de Descarga"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%ddia%dhora%dminutos%dsegundos"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"reserva"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"reserva"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrador"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Gamemaster"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Invitado"
	#define STRCMD_CS_COMMON_RACE_DEMO			"Para demostracion"
	#define STRCMD_CS_COMMON_RACE_ALL			"Todas las razas"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Raza desconocida"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Sin nombre"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Airman de entrenamiento"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3er airman"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2do airman"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1er airman"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3do wingman"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2do wingman"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1er wingman"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3er lider"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2do lider"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1er lider"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3er Ace"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2do Ace"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1er Ace"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Air-commodore"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Air vice-marshal"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"General"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Comandante"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Tipo Automatico"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Tipo Valkan"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Tipo Dualist"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Tipo Cannon"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Tipo Rifle"
	#define STRCMD_CS_ITEMKIND_GATLING				"Tipo Ametralladora"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Tipo Launcher"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Tipo Mass drive"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Tipo Cohete"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Tipo Misil"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Tipo Bundle"

	#define STRCMD_CS_ITEMKIND_MINE					"Tipo Mina"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Tipo Escudo"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Tipo Dummy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Tipo Fixer"
	#define STRCMD_CS_ITEMKIND_DECOY				"Tipo Decoy"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Tipo Equipo defensivo"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Tipo Equipo Soporte"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Tipo Energia"
	#define STRCMD_CS_ITEMKIND_INGOT				"Tipo Mineral"
	#define STRCMD_CS_ITEMKIND_CARD					"Tipo Carta Standard"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"Tipo Carta Encantamiento"
	#define STRCMD_CS_ITEMKIND_TANK					"Tipo Tanque"
	#define STRCMD_CS_ITEMKIND_BULLET				"Tipo Municion"
	#define STRCMD_CS_ITEMKIND_QUEST				"Tipo Objeto Quest"
	#define STRCMD_CS_ITEMKIND_RADAR				"Tipo Radar"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Tipo Computadora"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"Tipo Carta Apuestas"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"Tipo Carta de Prevencion de Fallo de encantamiento"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Tipo Blaster"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Tipo Rail gun "		// 2005-08-01 by hblee : Rail gun type added.	 
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"Adici? ilimitada"		// 2006-03-17 by cmkwon,  <>  
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"Tiempo limite-adici?"		// 2006-03-17 by cmkwon,
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Todas las Armas"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Arma Standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Tipo de Municion Arma Standard"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Tipo de Combustile Standard"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Arma Avanzada"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Tipo de Municion Arma Avanzada"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Tipo Escudo Arma Avanzada"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Habilidad Ataque"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Habilidad Defensa"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Habilidad Soporte"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Habilidad Atributo"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Objeto para un tipo de monstruo"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Monster machine gun type(1-1tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Monster beam type(1-2tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Atacar todos los monstruos"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Objetos para Monstruos Tipo 2"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Monster rocket(2-1tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Monster Missile type(2-1tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Monster Bundle type(2-1tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Monster Mine type(2-1tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Monster shield type(2-2tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Monster dummy type(2-2tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Monster Fixer type(2-2tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Monster Decoy type(2-2tipo)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Tipo de Fuego de Monstruo"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Monster crash possible beam type"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Monstruo bombas rectas tipo"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Objeto Desconocido"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Airframe Desconocido"

	#define STRCMD_CS_STAT_ATTACK_PART				"Ataque"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Defensa"
	#define STRCMD_CS_STAT_FUEL_PART				"Gasolina"
	#define STRCMD_CS_STAT_SOUL_PART				"Espiritu"
	#define STRCMD_CS_STAT_SHIELD_PART				"Escudo"
	#define STRCMD_CS_STAT_DODGE_PART				"Agilidad"
	#define STRCMD_CS_STAT_BONUS					"Estadistica Bonus"
	#define STRCMD_CS_STAT_ALL_PART					"Todas las Estadisticas"
	#define STRCMD_CS_STAT_UNKNOWN					"Estadisticas Desconocidas"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Tipo Libre"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Tipo Ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Tipo Multi"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Tipo Ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Tipo Agilidad"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Tipo Ataque"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Tipo Escudo"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Tipo Defensa"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Tipo Soporte"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon,     -    
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Bygeniou city general army"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Bygeniou city regular army"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Arlington city regular army"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Ejercito de federacion Vattalus"

	#define STRCMD_CS_POS_PROW						"Localizacion radar(Arriba Centrado)"
	#define STRCMD_CS_POS_PROWIN					"Computadora(Centro-Izquierda)"
	#define STRCMD_CS_POS_PROWOUT					"Armada Standard(Superior Izquierda)"
	#define STRCMD_CS_POS_WINGIN					"No se encuentra en uso(Centro Derecha)"
	#define STRCMD_CS_POS_WINGOUT					"Arma Avanzada(Superior Derecha)"
	#define STRCMD_CS_POS_CENTER					"Armadura(Centro)"
	#define STRCMD_CS_POS_REAR						"Motor(Centro Inferior)"

	// 2010-06-15 by shcho&hslee Æê½Ã½ºÅÛ
	#define STRCMD_CS_POS_ATTACHMENT				"Attachment(Inferior Derecha Tanque|relacion con contenedor)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessory(Right side of rear-Fueltank|container type)"

	// 2010-06-15 by shcho&hslee Æê½Ã½ºÅÛ
	//#define STRCMD_CS_POS_PET						"No se encuentra en uso(Inferior Izquierdo)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Not to use(Left side of rear)"

	#define STRCMD_CS_POS_PET						"Partner"

	#define STRCMD_CS_HIDDEN_ITEM					"Ocultar Posicion"		// 2011-09-20 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

	#define STRCMD_CS_POS_INVALID_POSITION			"Localizacion pendiente"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Localizacion inventario"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/QuestCompleta"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"formato: /QuestCompleta [|QuestIndex]"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/NacionRatio"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /NacionRatio"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/ChangeNacion"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/Nacion"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"formato: /ChangeNacion [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMon"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"formato: /GoMonster [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ× - ÁÖ¼® Ã³¸® ¹ØÀ¸·Î ÀÌµ¿
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Miembro"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"Comandante de Brigadade Vuelo"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1er comandante de batallon"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1er miembro de batallon"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2do comandante de batallon"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2do miembro de batallon"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3er comandante de batallon"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3er miembro de batallon"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4to comandante de batallon"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4to miembro de batallon"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5to comandante de batallon"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5to miembro de batallon"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"formato: /Noticeboard [|Duracion(unid:min) [Detalles de la noticia] - agrega una noticia al board de noticias publico."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [index of notice to be deleted] - Deletes a certain notice on the electronic notice board."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"Influence Leader"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Influence Subleader"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"Influence Buff"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Influence Event"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Influence(2:BCU, 4:ANI)] [Increase] - Increase the contribution of a certain nation"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [Details of request] - Request of consultation with GM."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [|Number(1~10)] - Check number of consultation request list to GM "
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [|Number(1~10)] - Bring the requested number of consultation request list to GM (Deleted from the server)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"
// 2008-09-09 by cmkwon, /¼¼·Â¼ÒÈ¯ ¸í·É¾î ÀÎÀÚ ¸®½ºÆ®¿¡ ±â¾îÅ¸ÀÔ Ãß°¡ - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnNation [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [MAX_USER] [0|Min-level] [0|Max-level] [message to users] - Summons all specified level users in nation with a message."

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [Item Number] [# of items] - Gives specific item to all nation users at the current map."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯Â¥ Ç¥Çö ¹æ½ÄÀÌ ´Ù¸£´Ù
	// ÇÑ±¹(Korea):		YYYY-MM-DD HH:MM:SS
	// ¹Ì±¹(English):	MM-DD-YYYY HH:MM:SS
	// º£Æ®³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s) "%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m) "%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - It shows concurrent users level distribution."	// 2006-08-08 by dhjin


	
	
	
	
	

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"Chance Item"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"Mark"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// Å¬¶óÀÌ¾ðÆ®¿¡¼­¸¸ »ç¿ëÇÏ´Â ¸í·É¾î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [CharacterName] - Request 1:1 voice chatting to specific character."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Start voice chatting between formation members. Only usable by the formation leader."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - End voice chatting between formation members. Only usable by the formation leader."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Start voice chatting between brigade members. Only usable by the brigade leader."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - End voice chatting between brigade members. only usable by the brigade leader."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Ends brigade, formation, or normal voice chatting."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [CharacterName] - Request PvP to specific character."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [CharacterName] -  Surrenders a PvP battle with the specified character."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [CharacterName] - Request formation PvP to specific character(formation leader). Only usable by the formation leader."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [CharacterName] -  Request brigade PvP to specific character(brigade leader). Only usable by the brigade leader."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  Surrender a brigade PvP battle. Only usable by the brigade leader."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [CharacterName] [class(2 ~ 11)] - Change appointment class of specific character. Only usable by the brigade leader. "
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  Resets chatting window"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - On/Off - Toggles PvP denial setting"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade - On/Off - Toggles trading denial setting"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow - Prevents message popups. Popup messages are automatically cancelled."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Allows message popups."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Support Skill Item"

// 2010-06-15 by shcho&hslee Æê½Ã½ºÅÛ - Æê ¾ÆÀÌÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Partner Item"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Ranura para objeto de tu compañero"		// 2011-09-01 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£Æ®³² ÇÏ·ç °ÔÀÓ ½Ã°£ °ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - This command is to turn the time limit system turn on/off."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - This command shows todays played time."

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ È£ÄªÀ» ´Ù¸£°Ô ¼³Á¤ - ¾Æ·¡¿¡ ¼¼·Âº°·Î ´Ù¸£°Ô Á¤ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Leader"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Subleader"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint update to DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang user counts"

// 2007-10-06 by dhjin, ºÎÁöµµÀÚ ¼±Ãâ ¹æ¹ý º¯°æÀ¸·Î ¼öÁ¤
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

// 2007-02-23 by dhjin, °ÅÁ¡Á¤º¸
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"format: /StrategyPointInfo - This shows the status of current progress on strategypoint."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"There is no strategypoint war in progress."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"Strategypoint war is in progress."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"Progress location"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"Starting time"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-GEAR"
#define STRCMD_CS_UNITKIND_MGEAR					"M-GEAR"
#define STRCMD_CS_UNITKIND_AGEAR					"A-GEAR"
#define STRCMD_CS_UNITKIND_IGEAR					"I-GEAR"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-GEAR All"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-GEAR All"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-GEAR All"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-GEAR All"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"GEAR All"

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå À¯Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"format: /Observer [n] [CharacterName] - CharacterName  save user at n number"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·Ã
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [validation number] - Initialize jamboree server DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [CharacterName] - Designated character will be duplicated to jamboree server DB(atum2_db_20)."
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

// 2007-04-17 by dhjin, ·¹º§ ·©Å©¿¡ °üÇÑ µî±Þ
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Trainee"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Airman"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Wingman"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "Ace"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Veteran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top Gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Wing Cmdr"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "Hero"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, À©µµ¿ìÁî ¸ðµå ±â´É Ãß°¡ -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA ÆÀ Ãâ·Â °ü·Ã ½ºÆ®¸µ
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Cannot find arena team."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(BCU)|4(ANI)]- Shows the present progress of arena."

// 2010. 06. 04 by hsLee ARENA ÀÎÇÇ´ÏÆ¼ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµå 2Â÷ ³­ÀÌµµ Á¶Àý. (GM ¸í·É¾î Ãß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµå 2Â÷ ³­ÀÌµµ Á¶Àý. (GM ¸í·É¾î Ãß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-Start the watch."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd ? Ends the watch."

// 2007-06-22 by dhjin, WarPoint Ãß°¡
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [Number 1~1000000] [|Username] ? Adds war points."

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎÆ® ÀÌº¥Æ® °ü·Ã Ãß°¡
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"WarPoint"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [character name] [|Time(minutes)] - Forbid entering Arena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [character name] - Release prohibition of Arena"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "El logo de la Brigada ha sido registrado."
#define STRMSG_070802_0002    "La registracion sera completada una vez concluido el periodo de instalacion."
#define STRMSG_070802_0003    "¿Deseas aceptar %d como el logo de Brigada?"
#define STRMSG_070802_0004    "No hay logo de Brigada"
#define STRMSG_070802_0005    "Logo de Brigada en Espera"
#define STRMSG_070802_0006    "El Logo de la Brigada se encuentra normalizado"
#define STRMSG_070802_0007    "El Logo de la Brigada presenta un error"

// 2007-08-24 by cmkwon, ½ºÇÇÄ¿¾ÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³Á¤ ±â´É Ãß°¡ - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Enable"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Forbid"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Enable/Forbid use Speaker item"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] - Prepare server shut down, disconnect all users."

// 2007-08-30 by cmkwon, È¸ÀÇ·ë ½Ã½ºÅÛ ±¸Çö - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[EntrancePermission] [|CharacterName] ? Can only be used by leader. This allows corresponding character to be put on conference room entrance list."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[ EntrancePermissionDeny] [CharacterName] ? Can only be used by leader. This deletes the corresponding user from conference room entrance list."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d days %d hour(s) %d minute(s) %d second(s)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. No need to translate.
#define STRCMD_071005_0001					"%d Year %d month %d d ay", Year, Month, Day //Year, Month, Day is parameter name. No need to translate.
#define STRCMD_071005_0002					"%d Year %d month", Year, Month // Year, Month is parameter name. No need to translate.
#define STRCMD_071005_0003					"%d Month %d day", Month, Day // Month, Day is parameter name. No need to translate.


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Sub leader 1" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Sub leader 2" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"General Commander"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Deputy Commander"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Chief of Staff"
#define STRCMD_ANI_INFLUENCE_LEADER						"Chairman"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Vice-Chairman"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Strategy Director"
#define STRCMD_OUTPOST_GUILD_MASTER						"Captain %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [CharacterName] - BCU : set BCU Nation 1st sub-leader name, ANI : set ANI Nation 1st sub-leader name"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [CharacterName] - BCU : set BCU Nation 2nd sub-leader name, ANI : set ANI Nation 2nd sub-leader name"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
// #define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyEvent"
// #define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/HappyEvent"
// #define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Start"
// #define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"End"
// #define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyEvent [255(AllNation)|0(NormalNation)|2(BCU)|4(ANI)] [Start|End] [Progress time(Unit:Minute)]"
//  
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"Neutral"
#define STRCMD_CS_INFLUENCE_TYPE_VCN						"Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI							"Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"AllNation"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WPAddedMap [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Users of selected nation of present map will be awarded WarPoint."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|time(Unit: Minute)] - Start appeal system"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - End appeal system"

// 2007-12-27 by cmkwon, À©µµ¿ìÁî ¸ðµå ±â´É Ãß°¡ - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW Ãß°¡
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, À©µµ¿ì¸ðµå »óÅÂ ÀúÀåÇÏ±â - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, °èÁ¤ ºí·°/ÇØÁ¦ ¸í·É¾î·Î °¡´ÉÇÑ ½Ã½ºÅÛ ±¸Çö - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Ban"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unban"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ¸í·É¾îÃß°¡(Á¢¼ÓÁßÀÎÀ¯Àú¸ðµÎ¿¡°Ô¾ÆÀÌÅÛÁö±Þ- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] - Logged on user of selected nation will receive the designated item"

// 2008-02-21 by dhjin, ¾Æ·¹³ªÅëÇÕ- ¾Æ·¹³ªÃß°¡¸í·É¾î
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
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

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °Ë»ö½Ã ÄÞº¸¹Ú½º¿¡¼­ °Ë»ö ±â´É Ãß°¡(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"All Kind"
	 
//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ×	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Miembro"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Comandante de Brigada de Vuelo"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Subcomandante de Brigada de vuelo"				// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1er Comandante de batallon"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1er Miembro de batallon"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2do Comandante de batallon"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2do Miembro de batallon"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3er Comandante de batallon"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3er Miembro de batallon"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4to Comandante de batallon"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4to Miembro de batallon"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5to Comandante de batallon"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5to Miembro de batallon"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ÀüÀåÁ¤º¸
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ¼¼·Â¸¶Å©ÀÌº¥Æ® 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [nation 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ÅÂ±¹ PC¹æ IPÁ¤º¸ ·Îµù
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, ÀÏ¹Ý, Æ¯¼ö °èÁ¤ÀÇ ºÎÁöµµÀÚ ÀÓ¸í Á¦ÇÑ
#define STRMSG_080821_0001				"Cannot appoint selected character with the rank."


// 2008-09-09 by cmkwon, /¼¼·Â¼ÒÈ¯ ¸í·É¾î ÀÎÀÚ ¸®½ºÆ®¿¡ ±â¾îÅ¸ÀÔ Ãß°¡ - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(BCU)|4(ANI)|255(All)] [maximum people] [0|minimum level] [0|maximum level] [1(B)|16(M)|256(A)|4096(I)|4369(ALL)] [Message to user] - Request to certain nation, level users to move to your position."

// 2008-09-09 by cmkwon, "/kick" ¸í·É¾î Ãß°¡ - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - Terminate designated character from the game."


// 2008-09-12 by cmkwon, "/¸í¼º" ¸í·É¾î Ãß°¡ - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /fame [personal fame] [brigade fame] - Raises personal and brigade fame of character."

// 2008-12-30 by cmkwon, ÁöµµÀÚ Ã¤ÆÃ Á¦ÇÑ Ä«µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0                               "/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1                               "/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /ReleaseLeaderChatBlock [CharacterName] - Leader chat restriction is released."

// 2009-10-12 by cmkwon, ÇÁ¸®½ºÄ« Á¦°Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0            "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "/StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|CharacterName] - Set the character`s beginning city to 2001 or 2002 when their nation is initialized."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, ÃÖ´ë ·¹º§ »óÇâ¿¡ µû¸¥ Ãß°¡ »çÇ×(·¹º§º° °è±Þ) - °è±Þ¶æ(¹éºÎÀå, ´ë·É, Àå±º, ÃÑµ¶, Á¤º¹ÀÚ, ¼öÈ£ÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurion"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Coronel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Gobernador"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conquistador"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardian"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legendario"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Basico"

#define       STRCMD_CS_COMMAND_ENDARENA					"/endarena"				// 2012-09-24 by jhseol, ¾¹³ª ·á ¸í·î ¼ö

// 2014-05-16 by bckim, ¿µ¹® ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ¿µ¹® ¸í·É¾î Ãß°¡

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/¸ÊÀÌµ¿Á¦ÇÑ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /¸ÊÀÌµ¿Á¦ÇÑ [MapIndex] - ÇØ´ç ¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀ» ¼³Á¤ÇÔ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ¼³Á¤ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ÇØÁ¦ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]´Â Çã¿ëÇÏÁö ¾Ê´Â ¸Ê¹øÈ£ÀÔ´Ï´Ù."
// end 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸í·É¾î Ãß°¡

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Å¸ °èÁ¤ ¼¼·Âº¯°æ
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/Cuentacambiodenación"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /Cuentacambiodenación [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ÆÄÆ¼¿ø Á¤º¸ º¸±â ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"formato: /formationinfo [CharacterName] - Información sobre los miembros de la formación del jugador (Los miembros debe inicar sesión dentro del juego)"
// End. 2013-11-19 by bckim, ÆÄÆ¼¿ø Á¤º¸ º¸±â ¸í·É¾î Ãß°¡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





