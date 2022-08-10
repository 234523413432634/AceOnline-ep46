
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Servidor no activo."
	#define STRERR_S_ATUMEXE_0002 "¡Socket del servidor login cerrado!"
	#define STRERR_S_ATUMEXE_0003 "Update automático fallado.\r\n Instala el juego de nuevo.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) recibido de %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Error desconocido: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "No se puede conectar con el servidor Download."
	#define STRERR_S_ATUMEXE_0007 "Tamaño de descarga del archivo desconocido."
	#define STRERR_S_ATUMEXE_0008 "No se puede descargar el fichero update."
	#define STRERR_S_ATUMEXE_0009 "El sistema no tiene más capacidad/recursos disponibles."
	#define STRERR_S_ATUMEXE_0010 "Archivo .exe inválido."
	#define STRERR_S_ATUMEXE_0011 "Archivo no encontrado."
	#define STRERR_S_ATUMEXE_0012 "La ruta introducida no se ha encontrado."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Actualización completada"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Selecciona otro servidor."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Actualización de la lista de borrado de archivos  v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Borrando archivos temporales"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Notificación de actualización"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Actualización completa (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Selecciona el archivo de ejecución"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Selecciona la ruta"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Descarga interrumpida"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Descarga completada"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Actualización a c%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Creación de archivo %s no posible"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Actualización a v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Recibiendo información %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Actualizar VTC Guard"				// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Error al contar parámetro, número (%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Error Mutex\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Tiempo transcurrido, Tipo(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Descodificación ID, ID descodificada (%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "No se puede conectar con el servidor Login."
	#define STRERR_S_ATUMLAUNCHER_0005 "Error al conectar con el servidor"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket del servidor Login cerrado."
	#define STRERR_S_ATUMLAUNCHER_0007 "Error-archivo-nota!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Update automático fallado.\r\n Instala el juego de nuevo.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Todos los servidores están en estos momentos inactivos."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s está siendo comprobado..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Todos los servidores están siendo comprobados. Inténtalo más tarde otra vez."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) recibido de %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Has introducido una ID o una contraseña inválida. Introduce una ID o una contraseña válida."
	#define STRERR_S_ATUMLAUNCHER_0015 "Error al Login"
	#define STRERR_S_ATUMLAUNCHER_0016 "No se ha indicado ninguna ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "Login doble"
	#define STRERR_S_ATUMLAUNCHER_0018 "El servidor F no es ejecutado"
	#define STRERR_S_ATUMLAUNCHER_0019 "El servidor I no es ejecutado"
	#define STRERR_S_ATUMLAUNCHER_0020 "Servicio parado en estos momentos. \n\n Vuelve a intentarlo más tarde."
	#define STRERR_S_ATUMLAUNCHER_0021 "Hay demasiados usuarios conectados.\n\nVuelve a intentarlo más tarde."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Tu cuenta está suspendida en estos momentos. \n periodo : \n\nEnvia un email para más detalles a www.airrivals.es"
	#define STRERR_S_ATUMLAUNCHER_0023 "La versión del cliente no es la correcta. \n\nVuelve a descargarte el juego otra vez."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "No se puede hacer un login en el servidor download."
	#define STRERR_S_ATUMLAUNCHER_0026 "Tamaño del archivo (%s) desconocido."
	#define STRERR_S_ATUMLAUNCHER_0027 "El tamaño del archivo es desconocido."
	#define STRERR_S_ATUMLAUNCHER_0028 "No se puede descargar el archivo update."
	#define STRERR_S_ATUMLAUNCHER_0029 "Archivo actualizado no existe."
	#define STRERR_S_ATUMLAUNCHER_0030 "El servidor está en modo mantenimiento. Inténtalo más tarde."
	#define STRERR_S_ATUMLAUNCHER_0031 "El sistema tiene insuficiente espacio o recursos."
	#define STRERR_S_ATUMLAUNCHER_0032 "El archivo .exe es inválido."
	#define STRERR_S_ATUMLAUNCHER_0033 "El archivo no puede ser encontrado."
	#define STRERR_S_ATUMLAUNCHER_0034 "Ruta no puede encontrarse."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, ÇöÀç ½´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÇÑ »çÇ× ¿¡¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î


	#define STRMSG_S_050506		"\'%s\''s cuenta actualmente bloqueada.\n Motivo: %s\n Duración: %s~%s\n\nVisita http://support.airrivals.es para más información."
	#define STRMSG_S_050930		"Vuelve a descargarte el juego.\nURL: %s\nUltima versión:"
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Male"
//	#define STRMSG_S_SCADMINTOOL_0001 "Female"
//	#define STRMSG_S_SCADMINTOOL_0002 "A.D%d, Age%d"
//	#define STRMSG_S_SCADMINTOOL_0003 "Do you really want to modify your account information?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces attained, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''To ' + l.PeerCharacterName + ''', give ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''To ' + l.PeerCharacterName + ''', receive ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0008 "'''Discard ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces bought, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces sold, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' added ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' deleted ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Add ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Deposit ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Recover ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'Tiempo juego \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', total \' + dbo.atum_GetHMSFromS(l.tiempo juego total)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', Tiempo juego: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(No existe)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Cuenta baneada"
	#define STRMSG_S_SCADMINTOOL_0030 "Prohibido chatear"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s Servidor"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s Servidor,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Cuenta confiscada"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "¿Quieres desbanear esta cuenta?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dsegundo)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d Victorias %d Derrotas"
	#define STRMSG_S_SCADMINTOOL_0042 "¿Estás seguro de querer separar y banear la cuenta?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s Item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Mensaje : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Cantidad de usuarios : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Mensaje recibido : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Cantidad de usuarios : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Fieldserver Status : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Conexión con el servidor interrumpida.\n Socket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "No se pueden cargar los datos de la cuenta."
	#define STRERR_S_SCADMINTOOL_0001 "Error al cambiar la información de la cuenta."
	#define STRERR_S_SCADMINTOOL_0002 "Introduce tu contraseña"
	#define STRERR_S_SCADMINTOOL_0003 "Confirmación de contraseña errónea"
	#define STRERR_S_SCADMINTOOL_0004 "Introduce tu login"
	#define STRERR_S_SCADMINTOOL_0005 "Servidor Login no disponible."
	#define STRERR_S_SCADMINTOOL_0006 "¡No se puede conectar con el servidor Login!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: Protocolo seleccionado no existe."
	#define STRERR_S_SCADMINTOOL_0009 "Introduce tu nombre de usuario"
	#define STRERR_S_SCADMINTOOL_0010 "Indica un motivo"
	#define STRERR_S_SCADMINTOOL_0011 "Error crear puntos de experiencia : Nivel %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Cantidad máxima de logs alcanzada.\r\n\r\nCambia la cantidad máxima de logs en las opciones de búsqueda."
	#define STRERR_S_SCADMINTOOL_0013 "No se puede conectar con la base de datos."
	#define STRERR_S_SCADMINTOOL_0014 "No conectado"
	#define STRERR_S_SCADMINTOOL_0015 "Conectado"
	#define STRERR_S_SCADMINTOOL_0016 "Updating"
	#define STRERR_S_SCADMINTOOL_0017 "Logueado"
	#define STRERR_S_SCADMINTOOL_0018 "Selección personaje"
	#define STRERR_S_SCADMINTOOL_0019 "Juego activo"
	#define STRERR_S_SCADMINTOOL_0020 "Desconocido"
	#define STRERR_S_SCADMINTOOL_0021 "Base de datos %s(%s:%d) no puede conectarse."
	#define STRERR_S_SCADMINTOOL_0022 "Error al añadir el item"
	#define STRERR_S_SCADMINTOOL_0023 "Error al buscar la cuenta suspendida."
	#define STRERR_S_SCADMINTOOL_0024 "Deslogueate y suspende la cuenta, para cambiarlo."
	#define STRERR_S_SCADMINTOOL_0025 "SPI (dinero) no puede añadirse."
	#define STRERR_S_SCADMINTOOL_0026 "Item seleccionado ya existe, cambia la cantidad."
	#define STRERR_S_SCADMINTOOL_0027 "Error al buscar el item"
	#define STRERR_S_SCADMINTOOL_0028 "SPI (dinero) del personaje no puede borrarse."
	#define STRERR_S_SCADMINTOOL_0029 "¿Quieres borrar este item?"
	#define STRERR_S_SCADMINTOOL_0030 "Error al borrar el item"
	#define STRERR_S_SCADMINTOOL_0031 "Cambio del item erróneo"
	#define STRERR_S_SCADMINTOOL_0032 "Introduce la cuenta"
	#define STRERR_S_SCADMINTOOL_0033 "Cuenta no existe. (Puede que esté suspendida)"
	#define STRERR_S_SCADMINTOOL_0034 "Cuenta o personaje no existen."
	#define STRERR_S_SCADMINTOOL_0035 "Error al buscar las informaciones de personaje."
	#define STRERR_S_SCADMINTOOL_0036 "Personaje seleccionado no existe."
	#define STRERR_S_SCADMINTOOL_0037 "Error en Update de personaje"
	#define STRERR_S_SCADMINTOOL_0038 "Información de personaje actualizada correctamente."
	#define STRERR_S_SCADMINTOOL_0039 "Selecciona un item."
	#define STRERR_S_SCADMINTOOL_0040 "Selecciona la cantidad de items."
	#define STRERR_S_SCADMINTOOL_0041 "Item seleccionado puede crearse con menos de 5 unidades."
	#define STRERR_S_SCADMINTOOL_0042 "Introduce el mensaje."
	#define STRERR_S_SCADMINTOOL_0043 "Nota no puede enviarse."
	#define STRERR_S_SCADMINTOOL_0044 "%s: Serverstatus (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM servidor no es ejecutado."
	#define STRERR_S_SCADMINTOOL_0046 "Servidor Field no existe."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServerstatus : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÊ - ¾îµå¹Î Åø ÆÊ ±¼­ »ç¿ëµÂ MSG
#define STRERR_S_SCADMINTOOL_0048 "Este espacio para objeto se ha añadido para tu V.A.A. Puedes eliminarlo mediante el comando \socket."
#define STRERR_S_SCADMINTOOL_0049 "Ha habido un error al guardar el cambio del V.A.A. (el cambio, sin embargo, se ha realizado)."
#define STRERR_S_SCADMINTOOL_0050 "Ha habido un error al cargar la información del V.A.A."
#define STRERR_S_SCADMINTOOL_0051 "No se ha podido eliminar el espacio para objeto que está en uso."
#define STRERR_S_SCADMINTOOL_0052 "Ha habido un fallo en la utilización del bonus oculto para los objetos en uso."
#define STRERR_S_SCADMINTOOL_0053 "Ha habido un error al aplicar el cambio del espacio de objeto del V.A.A."
#define STRERR_S_SCADMINTOOL_0054 "No se ha podido actualizar la información del V.A.A."
#define STRERR_S_SCADMINTOOL_0055 "Ha habido un error al cargar la información sobre el nivel del V.A.A."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎæ¾ÆÀÌÅÛ°â´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎæ¾ÆÀÌÅÛ°â´É. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "Account name"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0002 "Conviction"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Start date"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Finish date"
//	#define STRMSG_S_SCAT_COLNAME_0005 "Handling person"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Handling reason"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Date"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Log type"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0011 "Character name"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Location"
//	#define STRMSG_S_SCAT_COLNAME_0013 "Contents"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Item"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "Own number"
//	#define STRMSG_S_SCAT_COLNAME_0017 "Name"
//	#define STRMSG_S_SCAT_COLNAME_0018 "Item number"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "Colocar"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "No colocado"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Warehouse"
//	#define STRMSG_S_SCAT_COLNAME_0027 "Auction"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Map"
//	#define STRMSG_S_SCAT_COLNAME_0029 "Coordinate"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Sex"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Race"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Authority"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Unit kind"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Level"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Maximum level"
//	#define STRMSG_S_SCAT_COLNAME_0036 "Experience point"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Decreased experience point"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Auto stat division type"
//	#define STRMSG_S_SCAT_COLNAME_0039 "Attack"
//	#define STRMSG_S_SCAT_COLNAME_0040 "Defense"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Fuel"
//	#define STRMSG_S_SCAT_COLNAME_0042 "Spirit"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Shield"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Agility"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Attached regiment"
//	#define STRMSG_S_SCAT_COLNAME_0046 "Propensity"
//	#define STRMSG_S_SCAT_COLNAME_0047 "social position"
//	#define STRMSG_S_SCAT_COLNAME_0048 "Whole connection time"
//	#define STRMSG_S_SCAT_COLNAME_0049 "Generated time"
//	#define STRMSG_S_SCAT_COLNAME_0050 "Final log in time"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0052 "Whole"
	#define STRMSG_S_SCAT_COLNAME_0053 "Tipo automático (1-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Tipo Valkan (1-1-Tipo)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Tipo dualista (1-1-Tipo)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Tipo Cañón (1-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Tipo fusil (1-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Tipo Gatling (1-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Tipo lanzamisiles (1-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Tipo impulso masivo (1-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Tipo misil (2-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Tipo arma teledirigida (2-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Tipo bulto (2-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Tipo mina (2-1-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Tipo escudo (2-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Tipo Dummy (2-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Tipo Pixer (2-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Tipo anzuelo (2-2-Tipo)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Tipo defensa"
	#define STRMSG_S_SCAT_COLNAME_0070 "Tipo support equipamiento"
	#define STRMSG_S_SCAT_COLNAME_0071 "Tipo energía"
	#define STRMSG_S_SCAT_COLNAME_0072 "Tipo metal"
	#define STRMSG_S_SCAT_COLNAME_0073 "Tipo mapa"
	#define STRMSG_S_SCAT_COLNAME_0074 "Tipo encantamiento"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tipo Panzer"
	#define STRMSG_S_SCAT_COLNAME_0076 "Tipo bala"
	#define STRMSG_S_SCAT_COLNAME_0077 "Para misión"
	#define STRMSG_S_SCAT_COLNAME_0078 "Tipo radar"
	#define STRMSG_S_SCAT_COLNAME_0079 "Tipo Ordenador"
	#define STRMSG_S_SCAT_COLNAME_0080 "Tipo tarjeta de la suerte"
	#define STRMSG_S_SCAT_COLNAME_0081 "Tarjeta-antidestrucción-mejora"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Tipo Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Tipo Rail Gun"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "Whole item"
//	#define STRMSG_S_SCAT_COLNAME_0082 "Whole server"
//	#define STRMSG_S_SCAT_COLNAME_0083 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Server type"
//	#define STRMSG_S_SCAT_COLNAME_0085 "Server IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Present number of users"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Server condition"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Group server"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Field server"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Unknown"
//	#define STRMSG_S_SCAT_COLNAME_0091 "Not executed"
//	#define STRMSG_S_SCAT_COLNAME_0092 "Normal"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Abnormal"
	#define STRMSG_S_SCAT_COLNAME_0094 "Administrador"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '°³, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Command list\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- List of backup account ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  Account: \'%s\', Original password: \'%s\', Temporary password: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  Account: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Please choose the folder where Versions for update are located"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "File has been succesfully created.\r\n\r\nDB information: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  active) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -inactive) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Servers data has been succesfully reloaded."
//	#define STRMSG_S_SCMONITOR_0011 "Service condition has been succesfully reflected."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  active)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -inactive)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "Free server service has been stopped."
//	#define STRMSG_S_SCMONITOR_0017 "Free server service started."
//	#define STRMSG_S_SCMONITOR_0018 "Field server is not executed"
//	#define STRMSG_S_SCMONITOR_0019 "Do you really want to close Field Server?"
//	#define STRMSG_S_SCMONITOR_0020 "Update version list information(Maximum 1492 Bytes)\r\n\r\n    Number of version list[%3d], Data capacity[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "Do you really want to close Pre Server?"
//	#define STRMSG_S_SCMONITOR_0022 "Do you really want to close IM Server?"
//	#define STRMSG_S_SCMONITOR_0023 "Do you really want to close NPC Server?"
//	#define STRMSG_S_SCMONITOR_0024 "%Yyear %mmonth %dday %Hhour %Mminute %Ssecond"
//	#define STRMSG_S_SCMONITOR_0025 "No event(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "Open beta attendance event(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "Do not know event(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "Set up time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0029 "Standard time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0030 "Occupying brigade"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> Command succesful.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> Command failed.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "Cannot connect to the DB."
//	#define STRERR_S_SCMONITOR_0003 "Corresponding Version do not exist"
//	#define STRERR_S_SCMONITOR_0004 "Please enter name of the folder that you want to compress"
//	#define STRERR_S_SCMONITOR_0005 "Please enter name of the folder that you want to output"
//	#define STRERR_S_SCMONITOR_0006 "Please enter start version"
//	#define STRERR_S_SCMONITOR_0007 "Please enter last version"
//	#define STRERR_S_SCMONITOR_0008 "Please choose the folder that you are going to output Zip file for update"
//	#define STRERR_S_SCMONITOR_0009 "Cannot connect file"
//	#define STRERR_S_SCMONITOR_0010 "Please choose the server!"
//	#define STRERR_S_SCMONITOR_0011 "Cannot connect to the DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "There is too many update version list.(Version list number[%3d], Data capacity[%4dBytes])\r\n\r\n    You must arrange version list."
//	#define STRERR_S_SCMONITOR_0014 "Eliminated function.\r\nPlease use management tool."
//	#define STRERR_S_SCMONITOR_0015 "This is not a city occupying map"
//	#define STRERR_S_SCMONITOR_0016 "Cannot make EDIT control."
//	#define STRERR_S_SCMONITOR_0017 "You have already registered existing file."

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), No se puede conectar con el servidor Log[%15s:%4d] Nueva conexión\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Conectado con el servidor Log.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Conexión con el servidor Log[%15s:%4d interrumpida. Intentando volver a conectar.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), No se puede conectar con el servidor Login[%15s:%4d] Nueva conexión\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Conectado en el servidor Login. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) recibido de %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Error desconocido @WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Conexión con el servidor Login[%15s:%4d] interrumpida. Intentando volver a conectar. \r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), No se puede conectar con el servidor IM[%15s:%4d] Nueva conexión\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Conectado en el servidor IM.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Conexión con el servidor IM [%15s:%4d interrumpida. Intentando volver a conectar.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) recibido de %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Error desconocido@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Ninguna de estas consultas de BD en la consulta Fieldserver %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Item seleccionado no existe."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' pidió compañía, y prometió un item"
	#define STRMSG_S_F2DBQUERY_0003 "está concedido. Pulsa F5 para mirar tu inventario."
	#define STRMSG_S_F2DBQUERY_0004 "Skill %s(%d) ha sido añadido."
	#define STRMSG_S_F2DBQUERY_0005 "Item seleccionado no existe."
	#define STRMSG_S_F2DBQUERY_0006 "Compra de item fallada."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Comienza la guerra de ocupación de ciudad :  %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Brigada participante: UID(%4d) Nombre(%10s) Maestro(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Explosión monstruo guerra ocupación de ciudad:  %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Daño total==> Nombre alianza(%10s) Daño total(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Guerra ocupación de ciudad : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) Á¡·ÉÀü½Ã°£(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, KartenIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Después de %d minutos, \"%s\" comienza la guerra de ocupación de ciudad."
	#define STRMSG_S_F2CITYWAR_0007 "Después de %d minutos, \"%s\" finaliza la guerra de ocupación de ciudad."
	#define STRMSG_S_F2CITYWAR_0008 "Monstruo llamada para guerra de ocupación de ciudad(%s) : Ocupar NPC."
	#define STRMSG_S_F2CITYWAR_0009 "Monstruo llamado para guerra de ocupación de ciudad(%S) : %s brigada ocupante"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" ocupa momentáneamente \"%s\"."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" Brigada ocupa momentáneamente \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "No ha sido posible cargar la misión."
	#define STRMSG_S_F2QUEST_0001 "La misión no se ha cargado.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "¡Servidor configurado para pruebas!\r\n\r\nLoadFieldServerDataDebug() debe ser finalizado."
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monstruo splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1. Tipo"
	#define STRMSG_S_F2NOTIFY_0003 "2.- Tipo"
	#define STRMSG_S_F2NOTIFY_0004 "Mon 1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "¡Tipo de arma errónea! Contacta con el Administrador."
	#define STRMSG_S_F2NOTIFY_0007 "1-1tipo: %4.1f vs %4.1f -> Probabilidad de ataque reducido en %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s fallado, probabilidad(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s fallado, probabilidad(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s fallado, probabilidad(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2tipo: %4.1f vs %4.1f -> Daño reducido en %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, da %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, recibe %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), da%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, recibe %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy fallado: Seguramente defectuoso > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Dummy restante[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Información Bullet no existe. Contacta con el Administrador."
	#define STRMSG_S_F2NOTIFY_0019 "Información acerca del calibre del arma no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Está es la información acerca del proyectil. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "No es posible hacer Warp durante el torneo."
	#define STRMSG_S_F2NOTIFY_0022 "No es posible hacer Warp cuando estás muerto."
	#define STRMSG_S_F2NOTIFY_0023 "No es posible hacer Warp cuando estás en una batalla de formación."
	#define STRMSG_S_F2NOTIFY_0024 "¡Error producción mapa! Contacta con el administrador"
	#define STRMSG_S_F2NOTIFY_0025 "¡Error producción mapa! Contacta con el administrador. En %d, %d no existe el  Index de objetivo Warp\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Warp no posible dado que no ha finalizado la batalla de formación."
	#define STRMSG_S_F2NOTIFY_0027 "WARP(%04d) corrección imposible de Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Personaje %10s, recibe daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Personaje %10s, provoca daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Personaje %10s, recibe daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Personaje %10s, provoca daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Personaje %10s, recibe daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Personaje %10s, provoca daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> monstruo %3d, provoca daño %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Personaje %10s, provoca daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Personaje %10s, añade daño Dummy %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Monstruo %3d, recibe daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINA-> Personaje %10s, añade daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINA -> Personaje %10s, añade daño Dummy %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINA -> Monstruo %10s, añade daño %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Inicialización Stat correcta."
	#define STRMSG_S_F2NOTIFY_0042 "No puedes usar esto cuando estás muerto."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO no existe"
	#define STRMSG_S_F2NOTIFY_0044 "Upgrade \g realizado\g."
	#define STRMSG_S_F2NOTIFY_0045 "Upgrade \r fallido\r."
	#define STRMSG_S_F2NOTIFY_0046 "No pertenece a la Brigada."
	#define STRMSG_S_F2NOTIFY_0047 "Ya está en el status StandBy para la solicitud."
	#define STRMSG_S_F2NOTIFY_0048 "Vuelve a intentarlo más tarde."
	#define STRMSG_S_F2NOTIFY_0049 "Tu o la otra persona es el líder de brigada."
	#define STRMSG_S_F2NOTIFY_0050 "Ya estás en batalla de brigada."
	#define STRMSG_S_F2NOTIFY_0051 "Ambos líderes de brigada no están en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0052 "No todos los miembros de formación están en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0053 "No todos los miembros de fomación están en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0054 "No perteneces a la Brigada."
	#define STRMSG_S_F2NOTIFY_0055 "El aspirante receptor es diferente."
	#define STRMSG_S_F2NOTIFY_0056 "Tu o la otra persona no sois líder de brigada."
	#define STRMSG_S_F2NOTIFY_0057 "Dos líderes de brigada no están en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0058 "No perteneces a la Brigada."
	#define STRMSG_S_F2NOTIFY_0059 "El aspirante receptor es diferente."
	#define STRMSG_S_F2NOTIFY_0060 "Tu o la otra persona no sois el líder de brigada."
	#define STRMSG_S_F2NOTIFY_0061 "Con éxito en la defensa de la batalla de ocupación de ciudad."
	#define STRMSG_S_F2NOTIFY_0062 "Error Misión Setup. Contacta con el administrador."
	#define STRMSG_S_F2NOTIFY_0063 "Item(%s) seleccionado no puede introducirse en este lugar."
	#define STRMSG_S_F2NOTIFY_0064 "Motor no puede abandonarse."
	#define STRMSG_S_F2NOTIFY_0065 "Movimiento item: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Movimiento item erróneo: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENTO(%d) edición imposible de Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "¡Información evento mapa errónea! Contacta con el administrador."
	#define STRMSG_S_F2NOTIFY_0069 "Objetivo Warp no existe"
	#define STRMSG_S_F2NOTIFY_0070 "Error en compra de item. Contacta con el administrador."
	#define STRMSG_S_F2NOTIFY_0071 "El nivel de skill que quieres comprar es inferior a tu nivel actual."
	#define STRMSG_S_F2NOTIFY_0072 "Error item. Item necesita compra de skill."
	#define STRMSG_S_F2NOTIFY_0073 "Error en la venta de articulo. Pregunta un administrador."
	#define STRMSG_S_F2NOTIFY_0074 "Error en la compra de item. Contacta con el administrador."
	#define STRMSG_S_F2NOTIFY_0075 "\'Item crédito\'fue comprado."
	#define STRMSG_S_F2NOTIFY_0076 "Lista de compra : \'%s(%dunidades)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Ya formas parte del partido."
	#define STRMSG_S_F2NOTIFY_0078 "Si eres el líder no puedes entrar"
	#define STRMSG_S_F2NOTIFY_0079 "No es posible entrar mientras la batalla de formación esté en marcha."
	#define STRMSG_S_F2NOTIFY_0080 "El dirigir la palabra acerca de todas las informaciones del personal de formación no es soportado."
	#define STRMSG_S_F2NOTIFY_0081 "Información de evento de mapa errónea. Contacta con el administrador."
	#define STRMSG_S_F2NOTIFY_0082 "Esta es una cuenta que no puede ejecutar transacciones."
	#define STRMSG_S_F2NOTIFY_0083 "Carga sobrepasada en %"
	#define STRMSG_S_F2NOTIFY_0084 "Posibles coordinadas de movimiento: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Usuario:"
	#define STRMSG_S_F2NOTIFY_0086 "Un máximo de 20 personas puede ser visto."
	#define STRMSG_S_F2NOTIFY_0087 "El usuario correspondiente (%s) no existe"
	#define STRMSG_S_F2NOTIFY_0088 "No pertenece a la facción"
	#define STRMSG_S_F2NOTIFY_0089 "Tiempo actual: %d:%d, Tiempo-Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Tiempo cambiado: %d:%d, Tiempo-Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "No conectado al servidor NPC"
	#define STRMSG_S_F2NOTIFY_0092 "Artículo correspondiente (%d) no existe."
	#define STRMSG_S_F2NOTIFY_0093 "Limitado a 10 unidades, en caso de que no sea un artículo contable."
	#define STRMSG_S_F2NOTIFY_0094 "Cantidad total de las personas unidas del mapa  \'%s\': %d personas"
	#define STRMSG_S_F2NOTIFY_0095 "Conexiones simultáneas del mapa %s %s: %d personas - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Mapa %s %s conexiones simultáneas: %d personas - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Canal del mapa actual: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Información acerca de los cañones no existe. Pregunta al Administrador."
	#define STRMSG_S_F2NOTIFY_0099 "Información de calibre no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Información acerca de los cañones no existe. Pregunta al Administrador."
	#define STRMSG_S_F2NOTIFY_0101 "Información acerca del calibre no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Usuario seleccionado(%s) no existe"
	#define STRMSG_S_F2NOTIFY_0103 "Usuario (%s) está muerto"
	#define STRMSG_S_F2NOTIFY_0104 "Usuario correspondiente (%s) no existe"
	#define STRMSG_S_F2NOTIFY_0105 "Fijar como cuenta estándar"
	#define STRMSG_S_F2NOTIFY_0106 "Cuenta estándar levantada"
	#define STRMSG_S_F2NOTIFY_0107 "Invencibilidad activada"
	#define STRMSG_S_F2NOTIFY_0108 "Invencibilidad desactivada"
	#define STRMSG_S_F2NOTIFY_0109 "El daño de las armas es modificado en %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Es iniciado cuando se recargue el artículo"
	#define STRMSG_S_F2NOTIFY_0111 "Es iniciado cuando se cargue el item de nuevo."
	#define STRMSG_S_F2NOTIFY_0112 "Usuario correspondiente (%s) no existe"
	#define STRMSG_S_F2NOTIFY_0113 "Invisibilidad desactivada."
	#define STRMSG_S_F2NOTIFY_0114 "Invisibilidad activada."
	#define STRMSG_S_F2NOTIFY_0115 "El evento %s no está en marcha"
	#define STRMSG_S_F2NOTIFY_0116 "El evento %s ha comenzado. (Ampliación:%4.2f, Tiempo evento:%3d minutos)"
	#define STRMSG_S_F2NOTIFY_0117 "Create una cuenta premium estándar"
	#define STRMSG_S_F2NOTIFY_0118 "La creación de la cuenta premium ha fallado."
	#define STRMSG_S_F2NOTIFY_0119 "Crear como cuenta-premium"
	#define STRMSG_S_F2NOTIFY_0120 "Este no es el mapa para una batalla de ocupación de ciudad."
	#define STRMSG_S_F2NOTIFY_0121 "Batalla de ocupación de ciudad no puede comenzar."
	#define STRMSG_S_F2NOTIFY_0122 "Batalla de ocupación de ciudad no puede finalizar"
	#define STRMSG_S_F2NOTIFY_0123 "Modo oculto iniciado"
	#define STRMSG_S_F2NOTIFY_0124 "En modo oculto"
	#define STRMSG_S_F2NOTIFY_0125 "Mapa no confirmado."
	#define STRMSG_S_F2NOTIFY_0126 "Evento Happy Hour [Tiempo: %4d minutos)]"
	#define STRMSG_S_F2NOTIFY_0127 "Evento Happy Hour finalizado"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> de monstruo %3d, daño recibido %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "1Typ -> de monstruo %3d, daño recibido %5.2f(Dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Conectado con permiso \r %s\r"
	#define STRMSG_S_F2NOTIFY_0131 "Rutina de completado no editada %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Distancia personal partido fallida! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: ¡Parado!"
	#define STRMSG_S_F2NOTIFY_0136 "ERROR FATAL. Contacta con el Administrador. Error variable asignación tienda."
	#define STRMSG_S_F2NOTIFY_0137 "%s está borrado."
	#define STRMSG_S_F2NOTIFY_0138 "El canal en el que estás ahora mismo está desactivado, de ahi que no estén disponibles monstruos y otras funciones."
	#define STRMSG_S_F2NOTIFY_0139 "Parado. Utiliza otro canal."
	#define STRMSG_S_F2NOTIFY_0140 "Obj. Warp[%s,%2dunidades]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Movimiento-Timer %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Regeneración automática de HP detenida"
	#define STRMSG_S_F2NOTIFY_0143 "La regeneración automática de HP ha sido detenida porque este no es un lugar para aterrizar."
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f Regeneración de emergencia"
	#define STRMSG_S_F2NOTIFY_0145 "HP UP gradual parada(tiempo restante: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "DP UP gradual parada (tiempo restante: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "EP UP gradual parada (tiempo restante: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s evento finalizado."
	#define STRMSG_S_F2NOTIFY_0149 "%s evento en marcha (Ampliación %4.2f, restante:%3d minutos)"
	#define STRMSG_S_F2NOTIFY_0150 "Comando no ejecutado"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Error al dividir los puntos de experiencia.(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Error, comienzo de juego inválido ClientState [%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Error comienzo de juego inválido ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) Corrección imposible como resultado de proceso de misión(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "¡Información evento mapa erróneal! Pregunta al Administrador! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) Corección imposible en T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "¡Información evento mapa errónea! Contacta con el Administrador! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "Corrección WARP imposible para T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) Corrección imposible (party leader) en Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) Corrección imposible en Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) Corrección imposible en Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP Corrección imposible en T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Warp fallado: %s -> Distancia: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) Corrección imposible en Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> Haz clic en el botón OK!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Misión no cargada.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) Corrección imposible de HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) Corrección imposible de HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "ERROR FATAL: Este mensaje no se debería enviar al servidor Field, al que los miembros no pertenecen. Pruebalo\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) Corrección imposible en T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) Corrección imposible en T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Puntos experiencia"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Restauración de puntos de experiencia"
	#define STRMSG_S_F2EVENTTYPE_0003 "Item drop"
	#define STRMSG_S_F2EVENTTYPE_0004 "Item drop raro"
	#define STRMSG_S_F2EVENTTYPE_0005 "Evento desconocido"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Conectado en el login servidor.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Conexión con el servidor Login[%15s:%4d] interrumpida. Intentando volver a conectar.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' ya existe"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' ya está en una brigada."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' ya es el nombre de una brigada existente"
	#define STRMSG_S_I2NOTIFY_0003 "Error al cargar la Brigada - contacta con el administrador"
	#define STRMSG_S_I2NOTIFY_0004 "Tu amigo '%s' se ha conectado"
	#define STRMSG_S_I2NOTIFY_0005 "Comprobando información anterior"
	#define STRMSG_S_I2NOTIFY_0006 "Formación anterior no existe"
	#define STRMSG_S_I2NOTIFY_0007 "Regresa a la formación"
	#define STRMSG_S_I2NOTIFY_0008 "Estas ahora mismo en una formación"
	#define STRMSG_S_I2NOTIFY_0009 "ERROR FATAL: Error de grupo en T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Status del personal de formación inválido"
	#define STRMSG_S_I2NOTIFY_0011 "Personal de formación ya ha entrado en la Brigada."
	#define STRMSG_S_I2NOTIFY_0012 "Esta persona ya ha entrado en la Brigada"
	#define STRMSG_S_I2NOTIFY_0013 "No te puedes invitar a ti mismo"
	#define STRMSG_S_I2NOTIFY_0014 "Estas en un estado en el que no puedes entrar en ninguna brigada."
	#define STRMSG_S_I2NOTIFY_0015 "Has sobrepasado la cantidad de personal de brigada, que puede entrar"
	#define STRMSG_S_I2NOTIFY_0016 "Estas en un estado en el que no puedes entrar en la brigada."
	#define STRMSG_S_I2NOTIFY_0017 "El líder de la brigada no puede retirarse de la misma."
	#define STRMSG_S_I2NOTIFY_0018 "No te puedes retirar de la brigada mientras estés en una batalla de brigada."
	#define STRMSG_S_I2NOTIFY_0019 "No puedes expulsar a personal de brigada durante una batalla de brigada."
	#define STRMSG_S_I2NOTIFY_0020 "No se puede expulsar al líder de brigada."
	#define STRMSG_S_I2NOTIFY_0021 "No se puede separar la brigada durante una batalla de brigada."
	#define STRMSG_S_I2NOTIFY_0022 "No se puede cambiar al mismo nombre"
	#define STRMSG_S_I2NOTIFY_0023 "Estas en un estado en el que no se puede cambiar el nombre de la brigada."
	#define STRMSG_S_I2NOTIFY_0024 "Estas en un estado en el que no se puede cambiar el logo de la brigada."
	#define STRMSG_S_I2NOTIFY_0025 "Estas en un estado en el que no se puede cambiar el rango."
	#define STRMSG_S_I2NOTIFY_0026 "Rango solapado"
	#define STRMSG_S_I2NOTIFY_0027 "Cambio de rango a líder de regimento no posible."
	#define STRMSG_S_I2NOTIFY_0028 "Cambios en el rango de lider de regimento no son posibles."
	#define STRMSG_S_I2NOTIFY_0029 "Cantidad de usuarios: %d personas (salidas a %d personas)"
	#define STRMSG_S_I2NOTIFY_0030 "Añadido a la lista de mensajes de administrador"
	#define STRMSG_S_I2NOTIFY_0031 "Borrado de la lista de mensajes de administrador"
	#define STRMSG_S_I2NOTIFY_0032 "IP servidor: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Grupo servidor \'%s\' cantidad de personas logueadas: %s personas"
	#define STRMSG_S_I2NOTIFY_0034 "¿Estás seguro de querer cerrar el servidor (%s)? ID Servidor: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' no juega."
	#define STRMSG_S_I2NOTIFY_0036 "Cantidad de usuarios totales: %d personas (salidas a %d personas)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Regimiento seleccionado no existe"
	#define STRMSG_S_I2NOTIFY_0039 "Bloqueo de susurro desactivado"
	#define STRMSG_S_I2NOTIFY_0040 "Susurrar fue bloqueado"
	#define STRMSG_S_I2NOTIFY_0041 "No se ha entrado en la brigada"
	#define STRMSG_S_I2NOTIFY_0042 "Brigada (%d) no disponible"
	#define STRMSG_S_I2NOTIFY_0043 "Tiempo seleccionado (%s) no existe"
	#define STRMSG_S_I2NOTIFY_0044 "Servidor Field es inválido"
	#define STRMSG_S_I2NOTIFY_0045 "Mapa seleccionado (%s) no existe"
	#define STRMSG_S_I2NOTIFY_0046 "¡No puedes chatear durante %d minutos!"
	#define STRMSG_S_I2NOTIFY_0047 "Baneo chat puesto : '%10s', %3d Min"
	#define STRMSG_S_I2NOTIFY_0048 "Baneo de chat finalizado"
	#define STRMSG_S_I2NOTIFY_0049 "Baneo de chat finalizado: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(Cuenta: %s, Mapa: %d(%d), Nivel: %d) JUEGA"
	#define STRMSG_S_I2NOTIFY_0051 "No te puedes llamar a ti mismo."
	#define STRMSG_S_I2NOTIFY_0052 "Brigada seleccionada no existe."

	#define STRMSG_S_IMSERVER_050607_0001	"Mapa seleccionado no existe."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Conectado en el servidor Field.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Conexión con el servidor Field [%15s:%4d] interrumpida. Intentando volver a conectar.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Comprobación de colisión entre monstruo y objeto no existe \r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Monstruo batalla ocupación de ciudad (%10s) llamado\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Conectado con la %s cuenta(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Correcto"
	#define STRMSG_S_P2PRENOTIFY_0002 "Error"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]Error al añadir datos de cuenta, Cuenta(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Hola, este es el Administrador de AirRivals."
	#define STRMSG_SCAT_051115_0002		"Vamos a llevar a cabo las tareas de mantenimiento rutinarias en 10 minutos."
	#define STRMSG_SCAT_051115_0003		"Dirígete a un lugar seguro y abandona el juego."
	#define STRMSG_SCAT_051115_0004		"En primer lugar finaliza el servidor NPC."
	#define STRMSG_SCAT_051115_0005		"Comienzan las tareas de mantenimiento rutinarias de AirRivals."
	#define STRMSG_SCAT_051115_0006		"Disfruta de tu día con AirRivals."
	#define STRMSG_SCAT_051115_0007		"En 5 minutos habrá un Checkup del servidor." // 5     .
	#define STRMSG_SCAT_051115_0008		"El servidor estará durante 60 minutos fuera de servicio."	//  60   
	#define STRMSG_SCAT_051115_0009		"El mantenimiento del servidor comenzará en 30 minutos."
	#define STRMSG_SCAT_051115_0010		"El mantenimiento del servidor comenzará en 15 minutos."
	#define STRMSG_SCAT_051115_0011		"El mantenimiento del servidor comenzará en 10 minutos."
	#define STRMSG_SCAT_051115_0012		"El mantenimiento del servidor comenzará en 5 minutos."
	#define STRMSG_SCAT_051115_0013		"El mantenimiento del servidor comenzará enseguida."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Modo invisible: Los usuarios no pueden verte y no se pueden usar armas."
	#define STRMSG_060509_0001			"Status de invencible: No recibes daño."
	#define STRMSG_060509_0002			"Modo-oculto: Monstruos no te atacan."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Tu consulta se ha enviado al GM. Uno de nuestros GM se pondrá en contacto contigo lo antes posible."
	#define	STRMSG_060526_0001			"Update automático no fue posible.\r\n\r\nDescarga el Patch de la página de inicio(%s) y vuelve a conectar.\r\n\r\n	Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Esta ID no fue registrada o la ID y la contraseña no coinciden."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"El servidor de juego está offline debido a tareas de mantenimiento. Visita la página oficial (www.airrivals.de) para mayor información."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Versión de cliente inválida.\r\n"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Has sido matado por %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree Server DB(atum2_db_20) Se debe ejecutar la inicialización después de cerrar el servidor."
	#define STRMSG_070410_0001   	"Quieres la Jamboree Server DB(atum2_db_20)- [Validation number:%d]"
	#define STRMSG_070410_0002   	"Jamboree Server DB(atum2_db_20) está iniciado."
	#define STRMSG_070410_0003   	"Jamboree Server DB(atum2_db_20) Inicialización errónea."
	#define STRMSG_070410_0004   	"'%s' Duplicación de datos al Jamboree Server  DB(atum2_db_20) finalizada."
	#define STRMSG_070410_0005   	"'%s' Duplicación de datos al Jamboree Server       DB(atum2_db_20) fallida, personaje no existe."
	#define STRMSG_070410_0006   	"'%s' Duplicación de datos al Jamboree Server DB(atum2_db_20) fallida - cuenta de personaje no existe."
	#define STRMSG_070410_0007   	"'%s' Duplicación datos al Jamboree Server DB(atum2_db_20) fallida - error adicion BD"
	#define STRMSG_070410_0008   	"'%s' Duplicación datos al Jamboree Server DB(atum2_db_20) fallida - desconocido (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (bajo)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (medio)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (alto)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (bajo-ancho)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (medio-ancho)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (alto-ancho)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (bajo)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (medio)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (alto)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (bajo)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (medio)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (alto)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (bajo-ancho)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (medio-ancho)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (alto-ancho)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (bajo)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (medio)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (alto)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"No se puede despegar ya que estás en modo oculto."
#define STRMSG_070615_0001		"No se puede iniciar la observación."
#define STRMSG_070620_0000	"El usuario no puede comenzar la contemplación."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Punto de guerra"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Estás jugando desde hace %d hora(s)."
#define STRMSG_070628_0001				"Juegas desde hace %d hora(s). Porfavor tomate un descanso."
#define STRMSG_070628_0002				"Has jugado demasiado. Tu ritmo de juego puede ser perjudicial para la salud, asi que tomate un descanso. Es por tu propio bien."
#define STRMSG_070628_0003				"Seguir jugando ya es crítico para tu salud. Por favor cierra el juego. Si no lo haces tus ingresos se convertirán en 0%. Los ingresos volverán a ser normales 5 horas después de haber cerrado el juego"

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' no está prohibido en la zona de entrada."
#define STRMSG_070711_0001 "\'%s\' está prohibido en la zona de entrada (Tiempo restante: %d minutos)"
#define STRMSG_070711_0002 "¡Te es prohibido estar en la zona de entrada durante %d minutos!"
#define STRMSG_070711_0003 "Tu prohibición para la zona de entrada ha finalizado."
#define STRMSG_070711_0004 "El uso de la Arena está prohibido para jugadores  \'%s\'"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (bajo-lejos)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medio-ancho)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (alto-ancho)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Este comando solo puede usarse tras haber seleccionado una nación."
#define STRMSG_070830_0002                                   "Tarjeta de sala de conferencia (%d) de la nación seleccionada no está disponible."
#define STRMSG_070830_0003                                   "Cantidad de usuarios que pueden entrar a la sala de conferencias: %d"
#define STRMSG_070830_0004                                   "'%s' ya está en la lista de invitados."
#define STRMSG_070830_0005                                   "'%s' no tiene permiso."
#define STRMSG_070830_0006                                   "'%s' no es un personaje válido."
#define STRMSG_070830_0007                                 "'%s'  no puede añadirse a la lista de invitados de la sala de conferencia. (máximo %d personas)"
#define STRMSG_070830_0008                                   "'%s' ha recibido la autorización para entrar en la sala de conferencia."
#define STRMSG_070830_0009                                   "Permiso para entrar en la sala de conferencias concedido."
#define STRMSG_070830_0010                                   "Permiso para entrar a la sala de conferencias retirado."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s te ha enviado %s como regalo."
#define STRMSG_071115_0002									"Lista actual : \'%s(%d unidades)\'"
#define STRMSG_071115_0003									"\\y %s envia %s un regalo. El regalo es %s. Mira en el almacén."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Sistema Appeal no activo. Usa el center de clientes: http://support.airrivals.es/"
#define STRMSG_071120_0002									"Sistema Appeal activado."
#define STRMSG_071120_0003									"Sistema Appeal no está incluido."
#define STRMSG_071120_0004									"Sistema Appeal comienza desde %s hasta %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s te ha enviado %s(%d) como regalo. Mira tu almacén."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Configuración de resolución inválida. Vuelve a comprobarla."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'Error en %s' Bloque configuración. Código error (%d)"
#define STRMSG_080201_0002									"'%s' cuenta suspendida. [suspensión finaliza el: %s]"
#define STRMSG_080201_0003									"'%s' cuenta no está en lista de suspensión. Código error(%d)"
#define STRMSG_080201_0004									"'Al suspender la cuenta %s ha ocurrido un error' Código error(%d)"
#define STRMSG_080201_0005									"'%s' cuenta eliminada de la lista de suspensiones." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (bajo)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medio)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (alto)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), No se puede conectar con el servidor Arena[%15s:%4d] volver a conectar\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Conectar al servidor Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Conexión con el servidor Arena [%15s:%4d] interrumpida. Intentando volver a conectar.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) recibido de %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Error desconocido@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "A la sala de espera de Arena n.º \\y%d se le ha dado el atributo-evento.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "\\ySala de espera Arena %d se le ha quitado el evento-atributo.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Error al dar el atributo de Arena.\r\n"
#define STRMSG_080428_0001					"%s ha sido vencido."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º º¸ DB¿¡ á(½Ô °è ¸¯ÅÍ »ý¼º ÇÑ ½ýºÅÛá) - 
#define STRMSG_080430_0001					"No se pueden crear nuevos personajes en el servidor seleccionado."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼ö »çÇ× - 
#define STRMSG_080613_0001					"La solicitud para la brigada %s fue rechazada."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] ¡No hay ninguna función (QP_xxx) de la BD! Tipo consulta (%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s es excluido del chat durante %d minutos.\\y"
#define STRMSG_081230_0002					"\\yEl líder te ha excluido del chat durante %d minutos.\\y"
#define STRMSG_081230_0003					"\\yLa exclusión del chat ha sido quitada.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °å µ¿ÀÇâ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - »ç¿ëÇÏÁö ¾Ê, STRMSG_090831_0001´Â ÆäÀÌÁö·Î ó¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Instalar Hackshield"
#define STRMSG_090831_0002					"Instalar nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"Cancelar"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - 
#define STRMSG_090902_0001					"http://es.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø Çóµµ á(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (bajo)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (medio)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (alto)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (bajo)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (medio)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (alto)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (bajo)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (medio)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (alto)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ ¼Ó Çã¿ë »ó
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Servidor no registrado (podría tratarse de un servidor privado ilegal)."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Ha habido un error en la conexión con la base de datos."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"La confirmación se ha realizado con éxito."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Se ha registrado el servidor IP, pero no se han hecho más confirmaciones."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Se ha enviado la orden de apagar el servidor de Windows."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ¸®°Å ½ýºÅÛ  ¾²

// 1Â÷ 

#define STRMSG_120330_0001					"%s activa el portal Warp hacia el Sitio Escondido en el Camino de Ceniza."
#define STRMSG_120330_0002					"%s activa un aumento del 100%%%% de los puntos de experiencia (hora feliz) durante una hora en el Camino de Ceniza."
#define STRMSG_120330_0003					"%s activa un aumento del 100%%%% de la tasa de dropeo (hora feliz) durante una hora en el Camino de Ceniza."
#define STRMSG_120330_0004					"%s activa un aumento del 100%%%% de la tasa de dropeo / los puntos de experiencia / el SPI (hora feliz) durante una hora en el Camino de Ceniza."
#define STRMSG_120330_0005					"%s activa la tienda de armas en el Camino de Ceniza."
#define STRMSG_120330_0006					"%s activa la tienda de hipertarjetas en el Camino de Ceniza."
#define STRMSG_120330_0007					"%s activa la tienda de kits en el Camino de Ceniza."
#define STRMSG_120330_0008					"%s invoca un monstruo enorme en el Camino de Ceniza."
#define STRMSG_120330_0009					"El cristal ha desaparecido."

// 2Â÷ 

#define STRMSG_120508_0001					"%s recibe tantos puntos de guerra como haya recibido %d en el Oasis Hundido."
#define STRMSG_120508_0002					"%s invoca un jefe de los monstruos en el Oasis Hundido."
#define STRMSG_120508_0003					"%s activa un aumento del 150%%%% de los puntos de experiencia (hora feliz) durante 1 hora en el Oasis Hundido."
#define STRMSG_120508_0004					"%s activa un aumento del 150%%%% de la tasa de dropep (hora feliz) durante 1 hora en el Oasis Hundido."
#define STRMSG_120508_0005					"%s activa un aumento del 150%%%% de la tasa de dropeo / los puntos de experiencia / el SPI (hora feliz) durante 1 hora en el Oasis Hundido."
#define STRMSG_120508_0006					"%s recibe Hielo antiguo en el Oasis Hundido."
#define STRMSG_120508_0007					"%s activa la tienda de objetos expandida en el Oasis Hundido."
#define STRMSG_120508_0008					"%s activa la tienda de kits en el Oasis Hundido."
#define STRMSG_120508_0009					"%s activa la tienda de hipertarjetas en el Oasis Hundido."
#define STRMSG_120508_0010					"%s activa la tienda de armas en el Oasis Hundido."
#define STRMSG_120508_0011					"%s activa el Portal Warp al Sitio Escondido en el Oasis Hundido."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, %d ºÐ  °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸Í ½ð£ÀÌ %dºÐ ³²¾Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÀÌ ·áµÙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½ýºÅÛ ¸®´º¾ó - ÀüÀï½Ã ¸®°Å ¹«Àû»óÅÂ(ÀÃÁö)
#define STRMSG_121126_0001					"\\yOrden: durante las negociaciones de guerra se prohíben todas las acciones que afecten directamente a los Cristales.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX ¸Ê ¿öÇÁÇÑ
#define STRMSG_121129_0001					"\\y¿ ÀÇ ÀÌ ÇÈ Áö¿ª ÀÙ.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀüÀü±âÁö ¸®°Å ½ýºÅÛ
#define STRMSG_130121_0001					"\\cEl sistema ha sido capturado por las tropas de la NGC. Ya ha comenzado la evacuación inmediata."
#define STRMSG_130121_0002					"\\cExploradores:\\c El \\rcontrolador de la NGC\\r ha sido reforzado."
#define STRMSG_130121_0003					"\\cExploradores:\\c El \\rcontrolador de la NGC\\r ha sido destruido."
#define STRMSG_130121_0004					"\\cOrden:\\c Los escudos de \\rGomora\\r están en línea. Destruye el \\rcontrolador de la NGC\\r para desactivar los escudos."
#define STRMSG_130121_0005					"\\cOrden:\\c ¡Los escudos de \\rGomora\\r están desactivados! ¡Al ataque!"
#define STRMSG_130121_0006					"\\cOrdenl:\\c ¡Destrucción de \\rGomora\\r completada! ¡Todos avanzan!"
#define STRMSG_130121_0007					"\\cOrden:\\c Primero hay que destruir a \\rGomora\\r."
#define STRMSG_130121_0008					"\\cSe activó un [%s] al sobrecargar el \\c\\rcontrolador de la NGC\\r."
#define STRMSG_130121_0009					"\\y[Sistema de la base del puesto avanzado de la NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ  - ¼­ºêŸÀÔ á±¸ ½ýºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d no se permite en la arena. El objeto se envió a tu almacén.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Ó Ä÷º¼Ç - STRMSG á
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gSe añadió el perfil a tu colección.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gEl perfil se usó [%2d] veces.\\g"
#define STRMSG_130531_0003					"\\g[%s] Se alcanzó el límite de usos del perfil. Obtienes [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"El perfil expiró y se eliminaron las estadísticas. Tu motor ya no está equipado."
#define STRMSG_130531_0005					"\\yNinguno de los motores está equipado. Serás teletransportado a la ciudad.\\y"
#define STRMSG_130531_0006					"\\gNo se puede usar el perfil que está actualmente asignado a tu armadura.\\g"
#define STRMSG_130531_0007					"\\gSe cambió el perfil.\\g"
#define STRMSG_130531_0008					"\\rEl perfil [%s] ha expirado.\\r"
#define STRMSG_130531_0009					"\\yNo se pueden vender las armaduras equipadas con perfiles.\\y"
#define STRMSG_130531_0010					"\\yTipo de Gear incorrecto.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ¸®°Å ½ýºÅÛ Àå - STRMSG á
#define STRMSG_130708_0001					"\\cOrden:\\c Se activaron los escudos de la NGC. Destruye el \\rcontrolador de la NGC\\r para derribar los escudos de \\rGomora\\r."
#define STRMSG_130708_0002					"\\cOrden:\\c ¡La base militar de la NGC está indefensa! ¡Al ataque!"
#define STRMSG_130708_0003					"\\cExploradores:\\c El \\rgenerador de escudo de la NGC\\r ha sido avistado."
#define STRMSG_130708_0004					"\\cExploradores:\\c El \\rgenerador de escudo de la NGC\\r ha sido destruido."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRMSG_130726_0001					"El personaje ya es un miembro de esta nación."
#define STRMSG_130726_0002					"El personaje es un líder un subjefe, de modo que no puede cambiar de nación."
#define STRMSG_130726_0003					"El personaje forma parte de una brigada, de modo que no puede cambiar de nación."
#define STRMSG_130726_0004					"No hay ningún personaje disponible que pueda cambiar de nación."
#define STRMSG_130726_0005					"¡Error al cambiar de nación [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"¡Cambiaste de nación correctamente [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Esta cuenta no existe."
#define STRMSG_130726_0008					"Estás conectado a tu cuenta. No puedes cambiar de nación."


// 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\yEl líder de la nación revocó los privilegios de vuelo de %s.\\y"
#define STRMSG_130830_0002					"\\yEl líder de la nación revocó los privilegios de vuelo.\\y"
#define STRMSG_130830_0003					"\\yEl líder de la nación revocó los privilegios de vuelo de %s.\\y"
// End. 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­
#define STRMSG_130828_0001					"\\y[%s ayudó a destruir \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s asestó el primer golpe contra \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s realizó el mayor número de ataques contra \\y%s\\y en total.]\\y"
#define STRMSG_130828_0004					"\\y[%s asestó el último golpe a \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n fue derrotado."
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­

// 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â
#define STRMSG_130814_0001					"\\y[%s] ganó la guerra de puntos estratégicos de la NGC.\\y"
// end 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â

// 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)
#define STRMSG_130318_0001					"%s ha llamado al jefe en una zona bloqueada."
#define STRMSG_130318_0002					"%s ha llamado al jefe en las ruinas."
// End. 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yAhora mismo no puedes utilizar la casa de subastas.\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
