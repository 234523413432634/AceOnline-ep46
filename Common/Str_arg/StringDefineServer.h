
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "El server no esta activado."
	#define STRERR_S_ATUMEXE_0002 "Se cerro el ingreso al servidor!"
	#define STRERR_S_ATUMEXE_0003 "La actualizacion ha fallado.\r\nPor Favor reinstale el juego.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) recibido de %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Error Desconocido: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "No se puede conectar con el servidor."
	#define STRERR_S_ATUMEXE_0007 "Se desconoce el tama? de los archivos."
	#define STRERR_S_ATUMEXE_0008 "El archivo de actualizacion no puede ser descargado."
	#define STRERR_S_ATUMEXE_0009 "El sistema no tiene suficiente memoria o recursos."
	#define STRERR_S_ATUMEXE_0010 "El archivo .exe es invalido."
	#define STRERR_S_ATUMEXE_0011 "Archivo no encontrado."
	#define STRERR_S_ATUMEXE_0012 "No se encontro la ruta especificada. "
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Tipo de Mensaje desconocido: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Actualizacion Completa"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Por favor, elija el servidor."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Eliminando la lista de archivos de actualizacion v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Eliminando Archivos Temporales"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Actualizando Anuncio"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Actualizacion Completa(%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Seleccione el archivo"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Seleccione la ruta"
	#define STRMSG_S_ATUMLAUNCHER_0008 "La descarga fue cancelada"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Descarga finalizada"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Actualizando a v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "No se puede crear el archivo %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Actualizando a v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Adquiriendo Informacion del Archivo %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°æ
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°æ
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parametro de Error, Cuenta(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Execute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "No se puede conectar al servidor."
	#define STRERR_S_ATUMLAUNCHER_0005 "La conexion con el server ha fallado."
	#define STRERR_S_ATUMLAUNCHER_0006 "Se cerro el ingreso al servidor!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Error del archivo de Anuncio!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Por favor, descargue nuevamente el juego.\nURL: http://www.axeso5.com version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Fallo la actualizacion.\r\nPor favor reinstale el juego.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Todos los servidores estan inactivos en este momento."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s bajo examinacion..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Todos los servidores estan bajo examinacion. Intenta conectarte despues."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) recibido desde %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
//	#define STRERR_S_ATUMLAUNCHER_0014 "El ID o Contrase? que acabas de ingresar son incorrectos.  Por favor, ingrese el ID y la Contrase? correcta para poder ingresar"
	#define STRERR_S_ATUMLAUNCHER_0015 "Error al conectarse"
	#define STRERR_S_ATUMLAUNCHER_0016 "No has ingresado el ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "Doble Ingreso"
	#define STRERR_S_ATUMLAUNCHER_0018 "F el servidor no esta ejecutado."
	#define STRERR_S_ATUMLAUNCHER_0019 "I el servidor no esta ejecutado."
	#define STRERR_S_ATUMLAUNCHER_0020 "El servicio se detuvo temporalmente.\n\nIntenta conectarte mas tarde."
	#define STRERR_S_ATUMLAUNCHER_0021 "Hay muchos usuarios conecados.\n\nIntenta conectarte mas tarde."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Tu cuenta esta actualmente bloqueada.\n Periodo : \n\nPuedes contactar al sistema de soporte [http://tkts.axeso5.com] para mas detalles."
	#define STRERR_S_ATUMLAUNCHER_0023 "La version del cliente es incorrecta.\n\nPor favor descarga el juego nuevamente."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "No se puede conectar para descargar el servidor."
	#define STRERR_S_ATUMLAUNCHER_0026 "Tama? de la descarga de archivos(%s)se desconoce."
	#define STRERR_S_ATUMLAUNCHER_0027 "El tama? de la descarga de archivos se desconoce."
	#define STRERR_S_ATUMLAUNCHER_0028 "No se puede descargar el archivo de actualizacion."
	#define STRERR_S_ATUMLAUNCHER_0029 "El archivo de actualizacion no existe."
	#define STRERR_S_ATUMLAUNCHER_0030 "El servidor seleccionado esta bajo examinacion. Intenta conectarte mas tarde."
	#define STRERR_S_ATUMLAUNCHER_0031 "El sistema no tiene memoria o recursos."
	#define STRERR_S_ATUMLAUNCHER_0032 "El archivo .exe es invalido."
	#define STRERR_S_ATUMLAUNCHER_0033 "El archivo no puede ser encontrado."
	#define STRERR_S_ATUMLAUNCHER_0034 "La ruta no puede ser encontrada."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎÇ©, ÇöÀç ½ð£¿¡´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÀ¼ÇÑ »çÇ× ¿¡Àº¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î



	#define STRMSG_S_050506		"\'%s\'s Cuenta Bloqueada Permanentemente.\n  Razon: %s\n  Periodo: %s~%s\n\nPuedes contactar al sistema de soporte [http://tkts.axeso5.com] para mas detalles."
	#define STRMSG_S_050930		"Por favor descarga el juego nuevamente.\nURL: [www.axeso5.com] %s\nNla mas reciente version: "
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Masculino"
//	#define STRMSG_S_SCADMINTOOL_0001 "Femenino"
//	#define STRMSG_S_SCADMINTOOL_0002 "A.D%d, A?s%d"
//	#define STRMSG_S_SCADMINTOOL_0003 "¿Realmente quieres modificar la informacion de tu cuenta?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'pieza'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas obtenidas, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieza'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''para ' + l.PeerCharacterName + ''', dan ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''para ' + l.PeerCharacterName + ''', recibes ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
//	#define STRMSG_S_SCADMINTOOL_0008 "'''Descartar ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'Piezas Compradas, SPI restante: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'Piezas Vendidas, SPI restante: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' agregado ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' borrado ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieza'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Agrega ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Depositar ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Recuperacion ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'piezas, total' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piezas'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'Tiempo de Juego \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', entero \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', Tiempo del Juego: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' Sube y Baja, todo \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monstruo"
//	#define STRMSG_S_SCADMINTOOL_0022 "GEAR"
//	#define STRMSG_S_SCADMINTOOL_0023 "Razon Desconocida"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Estatistica Restante: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(No existe)"
//	#define STRMSG_S_SCADMINTOOL_0026 "Yo mismo"
//	#define STRMSG_S_SCADMINTOOL_0027 "No existe"
//	#define STRMSG_S_SCADMINTOOL_0028 "Usuario usando Bug"
	#define STRMSG_S_SCADMINTOOL_0029 "Cuenta Bloqueada"
	#define STRMSG_S_SCADMINTOOL_0030 "Chat Bloqueado"
//	#define STRMSG_S_SCADMINTOOL_0031 "Conexion al registro"
//	#define STRMSG_S_SCADMINTOOL_0032 "Registro del usuario"
//	#define STRMSG_S_SCADMINTOOL_0033 "Registro de Objetos"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s servidor"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s servidor,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Cuenta Embargada"
//	#define STRMSG_S_SCADMINTOOL_0037 "Clasificacion    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Valor"
	#define STRMSG_S_SCADMINTOOL_0039 "¿Deseas desbloquear esta cuenta?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dsecond)"
	#define STRMSG_S_SCADMINTOOL_0041 "%dGano %dPerdio"
	#define STRMSG_S_SCADMINTOOL_0042 "¿Estas seguro de que quieres desconectar y bloquear la cuenta?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s objeto"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Noticia : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Numero de usuario : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Mensaje Recibido : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Numero de usuarios : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Estado del servidor : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Se ha perdido la conexion con el servidor\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "No se puede cargar la informacion de la cuenta correspondiente."
	#define STRERR_S_SCADMINTOOL_0001 "La modificacion de la informacion de la cuenta ha fallado."
	#define STRERR_S_SCADMINTOOL_0002 "Ingresa tu contraser?"
	#define STRERR_S_SCADMINTOOL_0003 "La validacion de la contrase? ha fallado"
	#define STRERR_S_SCADMINTOOL_0004 "Ingresa tu ID"
	#define STRERR_S_SCADMINTOOL_0005 "El pre Server no esta activo."
	#define STRERR_S_SCADMINTOOL_0006 "No se puede conectar al pre server !!"
//	#define STRERR_S_SCADMINTOOL_0007 "ÀÎÁõ ½ÇÆÐÇÏ¿´½À´Ï´Ù"			// 2006-04-11 by cmkwon, ÁÖ¼®Ã³¸®ÇÔ
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: el protocolo correspondiente no existe."
	#define STRERR_S_SCADMINTOOL_0009 "Ingresa el nombre de usuario"
	#define STRERR_S_SCADMINTOOL_0010 "Ingresa la razon"
	#define STRERR_S_SCADMINTOOL_0011 "Error de establecimiento de punto de estadistica : Nivel %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Cantidad maxima de logs superada.\r\n\r\nPor favor modifique el maximo de logs para seguir aportando a la busqueda."
	#define STRERR_S_SCADMINTOOL_0013 "No se puede conectar a la base de datos."
	#define STRERR_S_SCADMINTOOL_0014 "No Conectado"
	#define STRERR_S_SCADMINTOOL_0015 "Conectado"
	#define STRERR_S_SCADMINTOOL_0016 "Actualizando"
	#define STRERR_S_SCADMINTOOL_0017 "Se ha conectado"
	#define STRERR_S_SCADMINTOOL_0018 "Eligiendo Personaje"
	#define STRERR_S_SCADMINTOOL_0019 "Jugando"
	#define STRERR_S_SCADMINTOOL_0020 "Desconocido"
	#define STRERR_S_SCADMINTOOL_0021 "Base de Datos %s(%s:%d)no se puede conectar."
	#define STRERR_S_SCADMINTOOL_0022 "No se pudo agregar el item"
	#define STRERR_S_SCADMINTOOL_0023 "Fallo la busqueda de la cuenta bloqueada."
	#define STRERR_S_SCADMINTOOL_0024 "Primero, desconecta la cuenta y bloqueala para modificarla."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(dinero) no se puede agregar."
	#define STRERR_S_SCADMINTOOL_0026 "El item seleccionado ya existe, modifica la cantidad."
	#define STRERR_S_SCADMINTOOL_0027 "Error al encontrar el objeto"
	#define STRERR_S_SCADMINTOOL_0028 "SPI(dinero) que posee el personaje no puede ser borrado."
	#define STRERR_S_SCADMINTOOL_0029 "¿Deseas eliminar este objeto?"
	#define STRERR_S_SCADMINTOOL_0030 "Fallo la eliminacion del Objeto."
	#define STRERR_S_SCADMINTOOL_0031 "Fallo la modificacion del Objeto."
	#define STRERR_S_SCADMINTOOL_0032 "Ingresa la Cuenta"
	#define STRERR_S_SCADMINTOOL_0033 "La cuenta no existe.(la cuenta posiblemente este bloqueada)"
	#define STRERR_S_SCADMINTOOL_0034 "La cuenta o el personaje no existen."
	#define STRERR_S_SCADMINTOOL_0035 "Error al buscar la informacion del Personaje."
	#define STRERR_S_SCADMINTOOL_0036 "El personaje correspondiente no existe"
	#define STRERR_S_SCADMINTOOL_0037 "Error al actualizar el Personaje."
	#define STRERR_S_SCADMINTOOL_0038 "La informacion del personaje fue actualizada con exito."
	#define STRERR_S_SCADMINTOOL_0039 "Selecciona un objeto."
	#define STRERR_S_SCADMINTOOL_0040 "Selecciona el numero del objeto."
	#define STRERR_S_SCADMINTOOL_0041 "El objeto correspondiende puede ser creado con 5 piezas."
	#define STRERR_S_SCADMINTOOL_0042 "Ingresa el mensaje."
	#define STRERR_S_SCADMINTOOL_0043 "No se puede enviar el Anuncio."
	#define STRERR_S_SCADMINTOOL_0044 "%s: estado del server(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "Servidor IM no fue ejecutado."
	#define STRERR_S_SCADMINTOOL_0046 "Fallo, el server no fue ejecutado."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] Estado del servidor IM : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÄÆ®³Ê - ¾îµå¹Î Åø ÆÄÆ®³Ê ±â´É¿¡¼­ »ç¿ëµÇ´Â MSG
	#define STRERR_S_SCADMINTOOL_0048 "Esta ranura esta equipada con tu compañero. Puedes removerlo desde la opcion propiedades de compañero con \n socket."
	#define STRERR_S_SCADMINTOOL_0049 "Error al guardar el registro de los cambios de las propiedades del Compañero electronico.\r\n(Cambio en las propiedades del objeto se ha completado, Solo el registro debe ser guardado.)"
	#define STRERR_S_SCADMINTOOL_0050 "La carga de la informacion del compañero electronico ha fallado."
	#define STRERR_S_SCADMINTOOL_0051 "Fallo al eliminar el item equipado en la ranura."
	#define STRERR_S_SCADMINTOOL_0052 "La opcion de ocultar items equipados ha fallado."
	#define STRERR_S_SCADMINTOOL_0053 "La revision para el compañero¡¯s La ranura de objeto ha fallado."
	#define STRERR_S_SCADMINTOOL_0054 "La actualizacion de los datos del compañero ha fallado."
	#define STRERR_S_SCADMINTOOL_0055 "La informacion de carga para el nivel del compañero ha fallado."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿î¿µÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿î¿µÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "Nombre de la cuenta"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Tipo"
//	#define STRMSG_S_SCAT_COLNAME_0002 "Conviccion"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Fecha de Inicio"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Fecha de finalizacion"
//	#define STRMSG_S_SCAT_COLNAME_0005 "Encargado"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Razon del Pedido"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Fecha"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Tipo de Log"
//	#define STRMSG_S_SCAT_COLNAME_0009 "Direccion de IP"
//	#define STRMSG_S_SCAT_COLNAME_0010 "Nombre del server"
//	#define STRMSG_S_SCAT_COLNAME_0011 "Nombre del Personaje"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Ubicacion"
//	#define STRMSG_S_SCAT_COLNAME_0013 "Contenido"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Objeto"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "Numero Propio"
//	#define STRMSG_S_SCAT_COLNAME_0017 "Nombre"
//	#define STRMSG_S_SCAT_COLNAME_0018 "Numero del objeto"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefijo"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Sufijo"
	#define STRMSG_S_SCAT_COLNAME_0021 "Equipo"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Cantidad"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Resistencia"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Crear tiempo"
	#define STRMSG_S_SCAT_COLNAME_0025 "No equipado"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Deposito"
//	#define STRMSG_S_SCAT_COLNAME_0027 "Subasta"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Mapa"
//	#define STRMSG_S_SCAT_COLNAME_0029 "Coordenada"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Sexo"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Raza"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Autoridad"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Tipo de Unidad"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Nivel"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Nivel Maximo"
//	#define STRMSG_S_SCAT_COLNAME_0036 "Puntos de Experiencia"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Disminucion de Puntos de Experiencia"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Division automatica de puntos de estadistica"
//	#define STRMSG_S_SCAT_COLNAME_0039 "Ataque"
//	#define STRMSG_S_SCAT_COLNAME_0040 "Defensa"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Combustible"
//	#define STRMSG_S_SCAT_COLNAME_0042 "Espiritu"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Escudo"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Agilidad"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Regimen adjunto"
//	#define STRMSG_S_SCAT_COLNAME_0046 "Inclinacion"
//	#define STRMSG_S_SCAT_COLNAME_0047 "Posicion social"
//	#define STRMSG_S_SCAT_COLNAME_0048 "tiempo total de conexion"
//	#define STRMSG_S_SCAT_COLNAME_0049 "Tiempo generado"
//	#define STRMSG_S_SCAT_COLNAME_0050 "Registro final en el tiempo"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Tipo"
//	#define STRMSG_S_SCAT_COLNAME_0052 "Todo"
	#define STRMSG_S_SCAT_COLNAME_0053 "Tipo automatico(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Tipo Vulcan(1-1type)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Tipo Dualista(1-1type)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Tipo Ca?n(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Tipo Rifle(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Tipo Gatling(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Tipo Launcher(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Tipo Mass drive(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Tipo Cohete(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Tipo Misil(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Tipo Bundle(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Tipo Mina(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Tipo Escudo(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Tipe Dummy(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Tipo Pixer(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Tipo Decoy(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Tipo Defensa"
	#define STRMSG_S_SCAT_COLNAME_0070 "Equipo de Soporte"
	#define STRMSG_S_SCAT_COLNAME_0071 "Tipo Energia"
	#define STRMSG_S_SCAT_COLNAME_0072 "Tipo Metal"
	#define STRMSG_S_SCAT_COLNAME_0073 "Tipo Carta"
	#define STRMSG_S_SCAT_COLNAME_0074 "Tipo Encantamiento"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tipo Tanque"
	#define STRMSG_S_SCAT_COLNAME_0076 "Tipo Bala"
	#define STRMSG_S_SCAT_COLNAME_0077 "Para misiones"
	#define STRMSG_S_SCAT_COLNAME_0078 "Tipo Radar"
	#define STRMSG_S_SCAT_COLNAME_0079 "Tipo CPU"
	#define STRMSG_S_SCAT_COLNAME_0080 "Tipo carta de apuesta"
	#define STRMSG_S_SCAT_COLNAME_0081 "Tipo de Anti-Destruccion"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Tipo Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Tipo Rail gun"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "Todos los Objetos"
//	#define STRMSG_S_SCAT_COLNAME_0082 "Todo el servidor"
//	#define STRMSG_S_SCAT_COLNAME_0083 "Nombre del servidor"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Tipo de servidor"
//	#define STRMSG_S_SCAT_COLNAME_0085 "Puerto, IP del server"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Presentar numero de usuarios"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Condicion del servidor"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Grupo del servidor"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Campo del servidor"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Desconocido"
//	#define STRMSG_S_SCAT_COLNAME_0091 "No ejecutado"
//	#define STRMSG_S_SCAT_COLNAME_0092 "Normal"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Anormal"
	#define STRMSG_S_SCAT_COLNAME_0094 "Administrador"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '°³, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Lista de Comandos\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- Lista de cuentas de seguridad ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  Cuenta: \'%s\', Contrase? Original: \'%s\', Contrase? Temporal: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  Cuenta: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Por favor elige la carpeta donde se encuentra la version actualizada"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nCreando un nuevo archivo Zip desde %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Renombrar el grupo del server"
//	#define STRMSG_S_SCMONITOR_0007 "El archivo se ha creado con exito.\r\n\r\nDB informacion: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  active) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -inactive) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Los datos del servidor fueron cargados con exito."
//	#define STRMSG_S_SCMONITOR_0011 "Se ha confirmado que el servicio esta totalmente estable."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  active)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -inactive)"
//	#define STRMSG_S_SCMONITOR_0014 "Carga de la lista de informacion de la version HECHO!"
//	#define STRMSG_S_SCMONITOR_0015 "carga de la lista de cuentas bloqueadas HECHO!"
//	#define STRMSG_S_SCMONITOR_0016 "Se ha detenido el servicio del servidor."
//	#define STRMSG_S_SCMONITOR_0017 "El servicio del servidor ha iniciado."
//	#define STRMSG_S_SCMONITOR_0018 "El campo del servidor no fue ejecutado"
//	#define STRMSG_S_SCMONITOR_0019 "¿Realmente quieres cerrar el campo del servidor?"
//	#define STRMSG_S_SCMONITOR_0020 "Actualiza la lista de informacion del servidor(Maximum 1492 Bytes)\r\n\r\n    Numero de la version list[%3d], capacidad de datos[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "¿Realmente quieres cerrar el Pre-Servidor?"
//	#define STRMSG_S_SCMONITOR_0022 "¿Realmente quieres cerrar el servidor IM?"
//	#define STRMSG_S_SCMONITOR_0023 "¿Realmente quieres cerrar la NPC del servidor?"
//	#define STRMSG_S_SCMONITOR_0024 "%Ya? %mmonth %ddia %Hhora %Mminutos %Ssegundos"
//	#define STRMSG_S_SCMONITOR_0025 "Ningun evento(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "Asistencia de eventos de Open Beta(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "¿conoces el evento?(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "Establece el tiempo para la proxima batalla"
//	#define STRMSG_S_SCMONITOR_0029 "Tiempo estandar para la proxima batalla"
//	#define STRMSG_S_SCMONITOR_0030 "Brigada Ocupante"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> Comando Exitoso.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> Comando Fallido.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "No se puede conectar a la DB."
//	#define STRERR_S_SCMONITOR_0003 "La version correspondiente no existe"
//	#define STRERR_S_SCMONITOR_0004 "Por favor ingresa el nombre de la carpeta que deseas comprimir"
//	#define STRERR_S_SCMONITOR_0005 "Por favor ingresa el nombre de la carpeta que deseas sacar"
//	#define STRERR_S_SCMONITOR_0006 "Por favor ingresa la version inicial"
//	#define STRERR_S_SCMONITOR_0007 "Por favor ingresa la ultima version"
//	#define STRERR_S_SCMONITOR_0008 "Por favor elije la carpeta que vas a sacar del archivo Zip para actualizar"
//	#define STRERR_S_SCMONITOR_0009 "No se puede conectar al archivo"
//	#define STRERR_S_SCMONITOR_0010 "Por favor elije el server!"
//	#define STRERR_S_SCMONITOR_0011 "No se puede conectar a la DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]No se puede procesar el tipo de mensaje: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "Hay demasiadas actualizaciones en la lista.(Numero de las actualizaciones[%3d], Capacidad de Datos[%4dBytes])\r\n\r\n    Debes arreglar la lista de versiones."
//	#define STRERR_S_SCMONITOR_0014 "Funcion eliminada.\r\nPor favor usa la herramienta de gestion."
//	#define STRERR_S_SCMONITOR_0015 "Este no es un mapa de asedio de ciudad"
//	#define STRERR_S_SCMONITOR_0016 "No puedes editar los controles."
//	#define STRERR_S_SCMONITOR_0017 "Ya te has registrado, archivo existente."

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), No se puede conectar al LogServer[%15s:%4d] Reconectado\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Conectado al LogServer.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "La conexion al LogServer[%15s:%4d]se ha perdido. Intentando reconectar.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), No se puede conectar al Pre-Server[%15s:%4d] Reconectado\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Conectado al Pre-Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) recibido desde %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "La conexion al Pre-Server[%15s:%4d]se ha perdido. Intentando reconectar.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), No se puede conectar al servidor IM[%15s:%4d] Reconectado\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Conectado al servidor IM.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "La conexion con el servidor IM[%15s:%4d]se ha perdido. Intentando reconectar.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No existe tal pedido dentro de la base de datos! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "El objeto correspondiente no existe."
	#define STRMSG_S_F2DBQUERY_0002 "'%s'ha confirmado asistencia, recibiendo regalo."
	#define STRMSG_S_F2DBQUERY_0003 "es recibido. Presiona F5 para revisar el inventario."
	#define STRMSG_S_F2DBQUERY_0004 "Habilidad %s(%d)ha sido a?dida"
	#define STRMSG_S_F2DBQUERY_0005 "El objeto correspondiente no existe."
	#define STRMSG_S_F2DBQUERY_0006 "Ha fallado la compra del objeto."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  Batalla de Ocupacion de la ciudad : %d(%10s) occNombre Brigada(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  Brigada Participante : GuildUID(%4d) Nombre Brigada(%10s) Nombre Lider(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  Ocupacion de la ciudad - Explosion Monstruosa : %d(%10s) occNombre Brigada(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		  Suma Total de Da? ==> Nombre Brigada(%10s) SumDeDa?(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  Batalla Ocupacion de la ciudad : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) Á¡·ÉÀü½Ã°£(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Desp. de %dminutos, \"%s\" la batalla de ocupacion de la ciudad comenzara."
	#define STRMSG_S_F2CITYWAR_0007 "Desp. de %dminutos, \"%s\" la batalla de ocupacion de la ciudad finalizara."
	#define STRMSG_S_F2CITYWAR_0008 "Enemigos invocados para la ocupacion de la ciudad(%s) : NPC ocupante"
	#define STRMSG_S_F2CITYWAR_0009 "Enemigos invocados para la ocupacion de la ciudad(%s) : %s brigada ocupante"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"esta ocupando \"%s\" actualmente."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"brigada actualmente ocupa \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Falla al cargar la Mision"
	#define STRMSG_S_F2QUEST_0001 "La mision no fue cargada.\r\n"
//	#define STRMSG_S_F2QUEST_0002 "Äù½ºÆ® \'%30s\' ¹øÈ£ %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "El servidor para pruebas fue configurado! \r\n\r\nLoadFieldServerDataDebug() necesita ser eliminado! "
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1er Tipo"
	#define STRMSG_S_F2NOTIFY_0003 "2do Tipo"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Tipo de arma equivocada! Por favor informale a un Administrador!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> La probabilidad de ataque se reduce en un %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s falla, probabilidad(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s falla, probabilidad(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s falla, probabilidad(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> El da? se reduce en un %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, da %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, recibes %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), da%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, recibes %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "se?elo fallido: Probabilidad insuficiente > %d"
	#define STRMSG_S_F2NOTIFY_0017 "se?elo restante[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "La informacion de las balas no existe. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0019 "La informacion sobre el calibre de las balas no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Esta es la informacion de las balas. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "No se puede teletransportar mientras un evento esta en progreso"
	#define STRMSG_S_F2NOTIFY_0022 "No se puede teletransportar mientras estas muerto."
	#define STRMSG_S_F2NOTIFY_0023 "No se puede teletransportar mientras estas en una batalla de formaciones"
	#define STRMSG_S_F2NOTIFY_0024 "Se produjo un error en el mapa! Por favor informale a un Administrador!"
	#define STRMSG_S_F2NOTIFY_0025 "Se produjo un error en el mapa! Por favor informale a un Administrador! Al %d, %d el indice del numero de teletransportacion no existe\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "No se puede teletransportar mientras una pelea de formaciones esta en progreso"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d) treatment not possible at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Personaje %10s, recibe da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Personaje %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Personaje %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Personaje %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Personaje %10s, recibe da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Personaje %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Monstruo %3d ,da? %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Personaje %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Personaje %10s ,da? se?elo %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> Monster %3d ,recive da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "  MINA -> Personaje %10s , da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "  MINA -> Personaje %10s ,da? se?elo %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "  MINA -> Monstruo %10s ,da? %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "El reestablecimiento de las estadisticas se ha hecho satisfactoriamente."
	#define STRMSG_S_F2NOTIFY_0042 "No se puede utilizar mientras estas muerto"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO no existe"
	#define STRMSG_S_F2NOTIFY_0044 "Encantamiento Exitoso."
	#define STRMSG_S_F2NOTIFY_0045 "Encantamiento Fallido."
	#define STRMSG_S_F2NOTIFY_0046 "No pertenece a la brigada."
	#define STRMSG_S_F2NOTIFY_0047 "Ya estas esperando una respuesta a la solicitud"
	#define STRMSG_S_F2NOTIFY_0048 "Por favor intentalo mas tarde."
	#define STRMSG_S_F2NOTIFY_0049 "Tu o la otra persona es el lider de brigada."
	#define STRMSG_S_F2NOTIFY_0050 "Ya estas en una brigada."
	#define STRMSG_S_F2NOTIFY_0051 "Ambos lideres de brigada no estan en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0052 "Los miembros de la formacion no estan en el mismo mapa"
	#define STRMSG_S_F2NOTIFY_0053 "Los miembros de la formacion no estan en el mismo mapa"
	#define STRMSG_S_F2NOTIFY_0054 "Tu no perteneces a la brigada."
	#define STRMSG_S_F2NOTIFY_0055 "El receptor es diferente"
	#define STRMSG_S_F2NOTIFY_0056 "Tu o la otra persona no son el lider de brigada."
	#define STRMSG_S_F2NOTIFY_0057 "Los lideres de ambas brigadas no estan en el mismo mapa."
	#define STRMSG_S_F2NOTIFY_0058 "Tu no perteneces a la brigada."
	#define STRMSG_S_F2NOTIFY_0059 "Los receptores son diferentes."
	#define STRMSG_S_F2NOTIFY_0060 "Tu o la otra persona no son el lider de brigada."
	#define STRMSG_S_F2NOTIFY_0061 "Successful in city occupying battle defense"
	#define STRMSG_S_F2NOTIFY_0062 "Error en el ajuste de la mision. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0063 "El objeto correspondiente(%s) no se puede poner en este lugar"
	#define STRMSG_S_F2NOTIFY_0064 "El motor no puede ser removido."
	#define STRMSG_S_F2NOTIFY_0065 "Mover Objeto: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Equivocacion al mover objeto: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d) unable to handle at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "La informacion del mapa de evento es anormal!!! Por favor avisale a un Adminstrador!!!"
	#define STRMSG_S_F2NOTIFY_0069 "El teletransportador correspondiente no existe"
	#define STRMSG_S_F2NOTIFY_0070 "Error al comprar el objeto. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0071 "El nivel de la habilidad que deseas comprar es muy alto para tu nivel actual."
	#define STRMSG_S_F2NOTIFY_0072 "Error de objeto.  El objeto necesita la habilidad de compra."
	#define STRMSG_S_F2NOTIFY_0073 "Error al vender el objeto. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0074 "Error al comprar el objeto. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0075 "\'Objeto de AX$\'fue comprado."
	#define STRMSG_S_F2NOTIFY_0076 "  Lista de Compra : \'%s(%dunidades)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Ya estas en una formacion."
	#define STRMSG_S_F2NOTIFY_0078 "No puedes ingresar si eres el lider de la formacion"
	#define STRMSG_S_F2NOTIFY_0079 "No se puede entrar si la batalla de formaciones esta en progreso."
	#define STRMSG_S_F2NOTIFY_0080 "Requerir toda la informacion del personal no se puede hacer en este momento!"
	#define STRMSG_S_F2NOTIFY_0081 "La informacion del mapa de evento es anormal!!! Por favor informale a un Administrador!!!"
	#define STRMSG_S_F2NOTIFY_0082 "Esta cuenta no puede realizar transacciones"
	#define STRMSG_S_F2NOTIFY_0083 "%s's la capacidad ha sido excedida."
	#define STRMSG_S_F2NOTIFY_0084 "Es posible moverse a las coordenadas: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Usuario:"
	#define STRMSG_S_F2NOTIFY_0086 "Se pueden ver un maximo de 20 personas."
	#define STRMSG_S_F2NOTIFY_0087 "El usuario correspondiente(%s)no existe"
	#define STRMSG_S_F2NOTIFY_0088 "No perteneces a la formacion"
	#define STRMSG_S_F2NOTIFY_0089 "Tiempo actual: %d:%d, Tiempo Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "TIempo Modificado: %d:%d, Tiempo Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "No te encuentras conectado al NPC server"
	#define STRMSG_S_F2NOTIFY_0092 "El objeto correspondiente(%d)no existe"
	#define STRMSG_S_F2NOTIFY_0093 "Limitado a 10 unidades si el objeto no es acumulativo"
	#define STRMSG_S_F2NOTIFY_0094 "Mapa \'%s\' 's cantidad de gente conectada: %dusuarios"
	#define STRMSG_S_F2NOTIFY_0095 "Mapa %s %s conexiones simultaneas: %dusuarios - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Mapa %s %s conexiones simultaneas: %dusuarios - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Mapa canal actual: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "La informacion de las balas no existe. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0099 "La informacion sobre el calibre de las balas no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "La informacion de las balas no existe. Por favor informale a un Administrador."
	#define STRMSG_S_F2NOTIFY_0101 "La informacion sobre el calibre de las balas no existe. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "El usuario correspondiente(%s)no existe"
	#define STRMSG_S_F2NOTIFY_0103 "El usuario correspondiente(%s)esta muerto"
	#define STRMSG_S_F2NOTIFY_0104 "El usuario correspondiente(%s)no existe"
	#define STRMSG_S_F2NOTIFY_0105 "Establecer como cuenta estandar"
	#define STRMSG_S_F2NOTIFY_0106 "La cuenta estandar ha sido cancelada"
	#define STRMSG_S_F2NOTIFY_0107 "Invisibilidad ha sido activado."
	#define STRMSG_S_F2NOTIFY_0108 "Invisibilidad ha sido desactivado."
	#define STRMSG_S_F2NOTIFY_0109 "El da? del arma sera modificado a %5.0f%% "
	#define STRMSG_S_F2NOTIFY_0110 "Se restablecera al reiniciar el objeto"
	#define STRMSG_S_F2NOTIFY_0111 "se restablecera al reiniciar el objeto"
	#define STRMSG_S_F2NOTIFY_0112 "El usuario Correspondiente(%s)no existe"
	#define STRMSG_S_F2NOTIFY_0113 "Invisibilidad ha sido desactivado."
	#define STRMSG_S_F2NOTIFY_0114 "Invisibilidad ha sido activado."
	#define STRMSG_S_F2NOTIFY_0115 "%s no hay evento en progreso"
	#define STRMSG_S_F2NOTIFY_0116 "%s el evento ha comenzado(aumenta:%4.2f, tiempo de evento:%3dminutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Establecer como cuenta Standard premium."
	#define STRMSG_S_F2NOTIFY_0118 "Establecer como cuenta premium ha fallado."
	#define STRMSG_S_F2NOTIFY_0119 "Establecer como cuenta premium"
	#define STRMSG_S_F2NOTIFY_0120 "Este no es el mapa de asedio de ciudad"
	#define STRMSG_S_F2NOTIFY_0121 "La ocupacion de la ciudad no puede comenzar"
	#define STRMSG_S_F2NOTIFY_0122 "La ocupacion de la ciudad ha terminado"
	#define STRMSG_S_F2NOTIFY_0123 "El Modo Camuflaje ha sido activado"
	#define STRMSG_S_F2NOTIFY_0124 "En estado camuflado"
	#define STRMSG_S_F2NOTIFY_0125 "El mapa no es valido."
	#define STRMSG_S_F2NOTIFY_0126 "Evento Happy Hour [tiempo en progreso:%4dminute)]"
	#define STRMSG_S_F2NOTIFY_0127 "Evento de Happy Hour finalizado."
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> Del enemigo %3d ,da? recibido %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "  tipo1 -> Del enemigo %3d ,da? recibido %5.2f(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Conectado con %s autoridad"
	#define STRMSG_S_F2NOTIFY_0131 "  El proceso aun no se completa %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "  ERROR@CharacterGameEndRoutine(): No se pudo eliminar el personal de la form! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefijo \'%s\' success: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Sufijo \'%s\' success: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Detenido!"
	#define STRMSG_S_F2NOTIFY_0136 "ERROR FATAL: Por favor enviale un mensaje al Administrador! Shop variable allotment error!"
	#define STRMSG_S_F2NOTIFY_0137 "%s se detecto."
	#define STRMSG_S_F2NOTIFY_0138 "El mapa en el que estas esta desactivado, asi que los mostruos y otro tipo de funciones no estarn disponibles."
	#define STRMSG_S_F2NOTIFY_0139 "Detenido. Por favor, usa otro canal."
	#define STRMSG_S_F2NOTIFY_0140 "  Warp Obj.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Cronometro de Movimiento %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Auto regeneracion de HP fue detenida"
	#define STRMSG_S_F2NOTIFY_0143 "La auto regeneracion de HP fue detenida, no se permite mientras estas estacionado"
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f para recuperadion de HP de emergencia"
	#define STRMSG_S_F2NOTIFY_0145 "Incremeneto gradual de HP detenido(Tiempo Restante: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Incremeneto gradual de DP detenido(Tiempo Restante: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Incremeneto gradual de EP detenido(Tiempo Restante: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s Evento completado."
	#define STRMSG_S_F2NOTIFY_0149 "%s Evento en progreso (aumento %4.2f, restante:%3dminutos)"
	#define STRMSG_S_F2NOTIFY_0150 "El comando no se ejecuto"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	Error en la division de puntos de experiencia(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "  No es un error valido de cliente ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "  No es un error valido de cliente ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "  WARP(%04d) treatment impossible at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Error de Mapa de evento!!! Por favor comunicate con el administrador!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "  EVENT(%d) treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Error de Mapa de evento!!! Por favor comunicate con el administrador!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "  WARP treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "  EVENT(%d) treatment impossible(party leader) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "  WARP(%04d) treatment impossible at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "  EVENT(%d) treatment impossible at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "  WARP treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Fallo la teletransportacion de Party: %s -> distancia: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "  WARP(%04d) treatment impossible at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "  %s -> click overlapped OK button!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Quest has not been loaded.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "  WARP(%s) treatment impossible at HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "  WARP(%s) treatment impossible at HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "  FATAL ERROR: 	Este mensaje no deberia ser enviado a los jugadores en diferentes servidores de campo. Revisalo.\r\n"
	#define STRERR_S_F2NOTIFY_0019 "  WARP(%04d) treatment impossible at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "  WARP(%s) treatment impossible at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Puntos de Experiencia"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Restauracion de los puntos de Experiencia"
	#define STRMSG_S_F2EVENTTYPE_0003 "Drop de Objetos"
	#define STRMSG_S_F2EVENTTYPE_0004 "Drop de Objetos Raros"
	#define STRMSG_S_F2EVENTTYPE_0005 "Puntos de Guerra de evento"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Conectado al pre-server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Coneccion al preserver [%15s:%4d] interrumpida. intentando reconexion.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' ya existe"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' ya se encuentra en la brigada."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' es el nombre de una brigada ya existente"
	#define STRMSG_S_I2NOTIFY_0003 "La carga de la brigada fallo - Por favor comunicaselo a la administracion!"
	#define STRMSG_S_I2NOTIFY_0004 "Tu amigo '%s' se ha conectado"
	#define STRMSG_S_I2NOTIFY_0005 "Revisando informacion previa"
	#define STRMSG_S_I2NOTIFY_0006 "La informacion previa no existe"
	#define STRMSG_S_I2NOTIFY_0007 "Reingreso a la formacion"
	#define STRMSG_S_I2NOTIFY_0008 "Ya te encuentras en una formacion"
	#define STRMSG_S_I2NOTIFY_0009 "  Error Fatal: Error Fatal en la party! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Estado de la formacion personal es invalido"
	#define STRMSG_S_I2NOTIFY_0011 "La formacion personal ya ha ingresado a la brigada"
	#define STRMSG_S_I2NOTIFY_0012 "Esa persona ya se encuentra en la brigada"
	#define STRMSG_S_I2NOTIFY_0013 "No te puedes invitar a ti mismo"
	#define STRMSG_S_I2NOTIFY_0014 "Te encuentras en un estado donde no puedes ingresar a una brigada"
	#define STRMSG_S_I2NOTIFY_0015 "Haz excedido el numero maximo de miembros en una brigada"
	#define STRMSG_S_I2NOTIFY_0016 "Estas en un estado donde ingresar brigadas no esta permitido"
	#define STRMSG_S_I2NOTIFY_0017 "El lider de la brigada no puede abandonar la misma"
	#define STRMSG_S_I2NOTIFY_0018 "No puedes abandonar la brigada en medio de una batalla de brigada"
	#define STRMSG_S_I2NOTIFY_0019 "No puedes expulsar a miembros de la brigada durante una batalla de brigada"
	#define STRMSG_S_I2NOTIFY_0020 "El lider de la brigada no puede ser expulsado"
	#define STRMSG_S_I2NOTIFY_0021 "No puede dispersarse la brigada durante una batalla de brigada"
	#define STRMSG_S_I2NOTIFY_0022 "No se puede renombrar al mismo nombre"
	#define STRMSG_S_I2NOTIFY_0023 "Estas en un estado en el cual el nombre de la brigada no puede ser modificado"
	#define STRMSG_S_I2NOTIFY_0024 "Estas en un estado en el cual el logo de la brigada no puede ser modificado"
	#define STRMSG_S_I2NOTIFY_0025 "Estas en un estado en el cual el rank no puede ser modificado"
	#define STRMSG_S_I2NOTIFY_0026 "El rank se encuentra super puesto"
	#define STRMSG_S_I2NOTIFY_0027 "El cambio de rango a lider de regimiento no es posible."
	#define STRMSG_S_I2NOTIFY_0028 "El cambio de rango a lider de regimiento no es posible."
	#define STRMSG_S_I2NOTIFY_0029 "Numero total de usuarios: %dusuarios (output up to %dpeople)"
	#define STRMSG_S_I2NOTIFY_0030 "Se agrego a la lista de mensajes de administrador"
	#define STRMSG_S_I2NOTIFY_0031 "Eliminado de la lista de mensajes de administrador"
	#define STRMSG_S_I2NOTIFY_0032 "Server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Server group \'%s\' cantidad de gente conectada: %dusuarios"
	#define STRMSG_S_I2NOTIFY_0034 "De verdad deseas cerrar el servidor(%s)? numero: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'No se encuentra en el juego "
	#define STRMSG_S_I2NOTIFY_0036 "Numero total de usuarios: %djugadores (Salida total a %dusuarios)"
	#define STRMSG_S_I2NOTIFY_0037 "/enviar %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "El regimiento correspondiente no existe."
	#define STRMSG_S_I2NOTIFY_0039 "Los susurros han sido desbloqueados"
	#define STRMSG_S_I2NOTIFY_0040 "Los susurros han sido bloqueados"
	#define STRMSG_S_I2NOTIFY_0041 "No ingreso a la brigada"
	#define STRMSG_S_I2NOTIFY_0042 "Brigada(%d) no se encuentra disponible"
	#define STRMSG_S_I2NOTIFY_0043 "Clima correspondiente(%s)no existe"
	#define STRMSG_S_I2NOTIFY_0044 "Servidor de campo invalido"
	#define STRMSG_S_I2NOTIFY_0045 "Mapa correspondiente(%s) no existe"
	#define STRMSG_S_I2NOTIFY_0046 "No puedes chatear por %d!minutos!!"
	#define STRMSG_S_I2NOTIFY_0047 "Bloqueo de chat establecido : '%10s', %3dminutos"
	#define STRMSG_S_I2NOTIFY_0048 "El bloqueo de chat ha sido cancelado."
	#define STRMSG_S_I2NOTIFY_0049 "Bloqueo de chat cancelado: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(cuenta: %s, mapa: %d(%d), nivel: %d) JUGANDO"
	#define STRMSG_S_I2NOTIFY_0051 "No puedes invocarte a ti mismo."
	#define STRMSG_S_I2NOTIFY_0052 "La brigada correspondiente no existe."

	#define STRMSG_S_IMSERVER_050607_0001	"El mapa correspondiente no existe."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Conectado al servidor de campo.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Conexion al servidor de campo[%15s:%4d]interrumpida. Intentando reconectar.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							El choque entre enemigos y objetos no existe\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Enemigos de la ocupacion de la ciudad(%10s) invocados\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul min ho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Conectado con %s cuenta(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Satisfactorio"
	#define STRMSG_S_P2PRENOTIFY_0002 "Fallido"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR] Error agregando informacion de cuenta, NombreCuenta(%s)  IPPrivada(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Hola. Este es el administrador de Ace Online."
	#define STRMSG_SCAT_051115_0002		"Comenzaremos con nuestro mantenimiento regular en 10 minutos."
	#define STRMSG_SCAT_051115_0003		"Por favor deja tu personaje en un lugar seguro y desconectate del juego ."
	#define STRMSG_SCAT_051115_0004		"Primero, el servidor de NPCs sera desconectado."
	#define STRMSG_SCAT_051115_0005		"El mantenimiento regular de Ace Online comenzara."
	#define STRMSG_SCAT_051115_0006		"Disfruta de tu dia con Ace Online."
	#define STRMSG_SCAT_051115_0007		"Habra un chequeo del servidor en 5 minutos." // 5ºÐ ÈÄ ¼­¹ö Á¡°ËÀÌ ÀÖÀ» ¿¹Á¤ÀÔ´Ï´Ù.
	#define STRMSG_SCAT_051115_0008		"El servidor se encontrara offline por 60 minutos."	// ¼­¹ö´Â 60ºÐ µ¿¾È ³»·ÁÁú ¿¹Á¤ÀÔ´Ï´Ù
	#define STRMSG_SCAT_051115_0009		"El mantenimiento comenzara en 30 minutos."
	#define STRMSG_SCAT_051115_0010		"El mantenimiento comenzara en 15 minutos."
	#define STRMSG_SCAT_051115_0011		"El mantenimiento comenzara en 10 minutos."
	#define STRMSG_SCAT_051115_0012		"El mantenimiento comenzara en 5 minutos."
	#define STRMSG_SCAT_051115_0013		"El mantenimiento del servidor comenzara en cualquier momento."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Modo invisible: Los usuarios no podran verte pero no podras utilizar armas."
	#define STRMSG_060509_0001			"Modo Invencible: Nada te da?ra."
	#define STRMSG_060509_0002			"Modo Oculto: Los monstruos no te acaran primero."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Tu pedido fue enviado a nuestros GMs. Un GM se comunicara contigo en lo mas breve posible."
	#define	STRMSG_060526_0001			"Fallo la actualizacion automatica.\r\n\r\nPor favor descarga la actualizacion de manera manualy(%s) conectate nuevamente.\r\n\r\n    Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"ID o Contrase? incorrecta."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"El juego se encuentra actualmente en mantenimiento, checkea www.axeso5.com para mas novedades."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Version del cliente invalida.\r\n  Por favor reinstala o descarga las actualizaciones."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Haz sido eliminado por %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree server DB(atum2_db_20) initialization must be conducted after closing the jamboree server."
	#define STRMSG_070410_0001   	"Do you really want to initialize jamboree server DB(atum2_db_20)- [Validation number:%d]"
	#define STRMSG_070410_0002   	"Jamboree server  DB(atum2_db_20) is initialized."
	#define STRMSG_070410_0003   	"Jamboree server  DB(atum2_db_20) initialization failed !!"
	#define STRMSG_070410_0004   	"'%s' data duplication to Jamboree server  DB(atum2_db_20) completed."
	#define STRMSG_070410_0005   	"'%s' data duplication to Jamboree server  DB(atum2_db_20) failed - character do not exist!!"
	#define STRMSG_070410_0006   	" %s' data duplication to Jamboree server  DB(atum2_db_20) failed - Corresponding account character exists !!"
	#define STRMSG_070410_0007   	" %s' data duplication to Jamboree server  DB(atum2_db_20) failed - DB addition failure !!"
	#define STRMSG_070410_0008   	" %s' data duplication to Jamboree server  DB(atum2_db_20) failed - Unknown (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, ÇØ»óµµ ¹®ÀÚ¿­ 
	// 2007-07-24 by cmkwon, ·±Ã³¿¡¼­ 800*600 ÇØ»óµµ »èÁ¦ - ÄÞº¸¹Ú½º ½ºÆ®¸µ ÇÊ¿ä ¾øÀ½
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (bajo)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medio)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (alto)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (bajo)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (medio)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (alto)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (bajo)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (medio)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (alto)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (bajo)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (medio)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (alto)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (bajo)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (medio)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (alto)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (bajo)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (medio)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (alto)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (bajo)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (medio)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (alto)"

// 2007-06-15 by dhjin, °üÀü °ü·Ã ½ºÆ®¸µ
#define STRMSG_070615_0000		"No se puede comenzar ya que no te encuentras en modo oculto."
#define STRMSG_070615_0001		"No se puede iniciar el reloj."
#define STRMSG_070620_0000	"Los usuarios no pueden iniciar el reloj."

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎÆ® ÀÌº¥Æ® °ü·Ã Ãß°¡
#define STRMSG_S_F2EVENTTYPE_0006		"Punto de Guerra"

// 2007-06-28 by cmkwon, Áß±¹ ¹æ½ÉÃë°ü·Ã(°ÔÀÓ ½Ã°£ ¾Ë¸² ±¸Çö) - ½ºÆ®¸µ Ãß°¡
#define STRMSG_070628_0000				"Has estado jugando el juego por %d horas(s)."
#define STRMSG_070628_0001				"Has estado jugando el juego por %d horas(s). Por favor toma un descanso."
#define STRMSG_070628_0002				"Has estado jugando el juego por demasiado tiempo, se recomiendo tomar un descanso inmediatamente para evitar problemas de salud "
#define STRMSG_070628_0003				"Jugar el juego por tantas horas puede resultar critico para su salud, de no desconectarse un tiempo prudencial, el juego forzara su ganancia a 0% y volvera a la normalidad tras 5 horas de inactividad de su cuenta."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' No tiene prohibido el ingreso a la arena."
#define STRMSG_070711_0001 "\'%s\' tiene prohibido el ingreso a la area (tiempo restante: %d minutos)"
#define STRMSG_070711_0002 "No puedes ingresar a la arena por %d minutos!!"
#define STRMSG_070711_0003 "Tu prohibicion de entrar a la arena ha sido retirada."
#define STRMSG_070711_0004 "El uso de la arena esta prohibido para el usuario \'%s\'."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide ÇØ»óµµ 1280x720(16:9) Ãß°¡ - ½ºÆ®¸µ Ãß°¡
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (bajo)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medio)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (alto)"

// 2007-08-30 by cmkwon, È¸ÀÇ·ë ½Ã½ºÅÛ ±¸Çö - ½ºÆ®¸µ Ãß°¡
#define STRMSG_070830_0001                                   "Este comando solo puede ser utilizado una vez que la nacion ha sido seleccionada."
#define STRMSG_070830_0002                                   "Mapa de la sala de conferencias(%d) de la correspondiente nacion no se encuentra disponible"
#define STRMSG_070830_0003                                   "Numero de usuarios que pueden ingresar a la sala de conferencias : %dpersonas(s)"
#define STRMSG_070830_0004                                   "'%s' ya fue adherido a la lista de ingresos."
#define STRMSG_070830_0005                                   "'%s' No tienes el permiso de entrada."
#define STRMSG_070830_0006                                   "'%s' No es un personaje valido."
#define STRMSG_070830_0007                                 "'%s' no se puede agregar a la lista de entradas de la sala de conferencias.(Maximo %d usuarios)"
#define STRMSG_070830_0008                                   "'%s' Recibidio la autoridad para ingresar a la sala de conferencias."
#define STRMSG_070830_0009                                   "Se ha recibido el permiso de ingreso a la sala de conferencias."
#define STRMSG_070830_0010                                   "Se ha cancelado el permiso de ingreso de la sa de conferencias."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s te ha enviado %s como un regalo."
#define STRMSG_071115_0002									"Lista de regalos : \'%s(%d unidades)\'"
#define STRMSG_071115_0003									"\\y%s enviar un regalo a %s.  el regalo es  %s. Por favor revisa tu deposito."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Sistema de gustos no esta en efecto. Comunicate con soporte."
#define STRMSG_071120_0002									"Sistema de gusto activado."
#define STRMSG_071120_0003									"Sistema de gusto concluido."
#define STRMSG_071120_0004									"El sistema de gusto comenzara desde %s to %s."

// 2007-11-28 by cmkwon, ÅëÁö½Ã½ºÅÛ ±¸Çö - 
#define STRMSG_071128_0001									"%s te envio %s(%d) como regalo. Por favor revisa tu deposito."

// 2007-12-27 by cmkwon, À©µµ¿ìÁî ¸ðµå ±â´É Ãß°¡ - 
#define STRMSG_071228_0001				"La resolucion es invalida, por favor intenta nuevamente."

// 2008-01-31 by cmkwon, °èÁ¤ ºí·°/ÇØÁ¦ ¸í·É¾î·Î °¡´ÉÇÑ ½Ã½ºÅÛ ±¸Çö - 
#define STRMSG_080201_0001									"'Error exists in %s' block setting. ErrorCode(%d)"
#define STRMSG_080201_0002									"'%s' la cuenta ha sido bloqueada.[Finalizacion del Bloqueo: %s]"
#define STRMSG_080201_0003									"'%s' No existe en la lista de bloqueos. ErrorCode(%d)"
#define STRMSG_080201_0004									"'Error ocurrido en el proceso de bloqueo %s' cuenta. ErrorCode(%d)"
#define STRMSG_080201_0005									"'%s' ha sido removida de lista de bloqueos." 

// 2008-02-11 by cmkwon, ÇØ»óµµ Ãß°¡(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (bajo)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medio)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (alto)"

// 2007-12-27 by dhjin, ¾Æ·¹³ªÅëÇÕ- ¾Æ·¹³ª¼­¹ö¿¬°á°ü·Ã¿À·ù
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), No se puede conectar al servidor de arena[%15s:%4d] Reconectar\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Conectado al servidor de Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Conexion al servidor de arena[%15s:%4d] cerrada. Intentando reconexion.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Numero \\y%d la arena de pelea ha dado atributo bonus de evento.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "Numero \\y%d el efecto de bonus de la sala de espera retirado.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\yFallo el recibir atributo de arena.\r\n"
#define STRMSG_080428_0001					"\\y%s fue derribado.\\y"          // 2008-04-28 by dhjin

// 2008-04-29 by cmkwon, ¼­¹ö±º Á¤º¸ DB¿¡ Ãß°¡(½Å±Ô °èÁ¤ Ä³¸¯ÅÍ »ý¼º Á¦ÇÑ ½Ã½ºÅÛÃß°¡) - 
#define STRMSG_080430_0001					"El servidor seleccionado no permite la creacion de nuevos personajes."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼öÁ¤ »çÇ× - 
#define STRMSG_080613_0001					"La solicitud de ingreso a la brigada %s ha sido rechazada."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ Ã¤ÆÃ Á¦ÇÑ Ä«µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s Tendra el chat restringido por %d minutos.\\y"
#define STRMSG_081230_0002					"\\yEl chat fue restringido por el lider por %d minutos.\\y"
#define STRMSG_081230_0003					"\\yLa restriccion del chat establecida por el lider fue removida.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °ÔÀÓ°¡µå µ¿ÀÇÃ¢ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇÃ¢ WebPage·Î Ã³¸® - STRMSG_090831_0001´Â À¥ÆäÀÌÁö·Î Ã³¸®
//#define STRMSG_090831_0001					"Ace Online de Axeso5.com se encuentra protegido contra herramientas de hacking. http://www.axeso5.com."
#define STRMSG_090831_0002					"Instalar"
#define STRMSG_090831_0003					"cancelar"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇÃ¢ WebPage·Î Ã³¸® - 
#define STRMSG_090902_0001					"http://www.axeso5.com"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø ÇØ»óµµ Ãß°¡(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ Á¢¼Ó Çã¿ë »óÈ²
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Not Registered Server (It can be Illegal Private Server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Error occurs during linkage with DB"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Authentication succeed"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Registered Server IP But proceed Authentication Denied"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"The command to shut down the Windows server has been sent."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 Æ®¸®°Å ½Ã½ºÅÛ ÀÌº¥Æ® ¾Ë¸²

// 1Â÷ ÀÌº¥Æ®

#define STRMSG_120330_0001					"%s Activa el portal del lugar oculto en Camino de Cenizas."
#define STRMSG_120330_0002					"%s Activa 100%%%% de incremento en experiencia, Happy hour (1h) en Camino de Cenizas."
#define STRMSG_120330_0003					"%s Activa 100%%%% de incremento en drop / Happy hour (1h) en Camino de Cenizas."
#define STRMSG_120330_0004					"%s Activa 100%%%% de incremento en drop / monster EXP/ SPI/ Evento Happy hour (1h) en Camino de Cenizas."
#define STRMSG_120330_0005					"%s Activa la tienda de armas en Camino de Cenizas."
#define STRMSG_120330_0006					"%s Activa la tienda de hiper cartas en Camino de Cenizas."
#define STRMSG_120330_0007					"%s Activa la tienda de kits en Camino de Cenizas."
#define STRMSG_120330_0008					"%s Invoca un monstruo gigante en Camino de Cenizas."
#define STRMSG_120330_0009					"El cristal ha desaparecido."

// 2Â÷ ÀÌº¥Æ®

#define STRMSG_120508_0001					"%s Obtienes %d Puntos de guerra en Oasis perdido."
#define STRMSG_120508_0002					"%s Invoca un boss en Oasis Perdido."
#define STRMSG_120508_0003					"%s Activa 150%%%% de incremento en experiencia, Happy hour (1h) en Oasis Perdido."
#define STRMSG_120508_0004					"%s Activa 150%%%% de incremento en experiencia, Happy hour (1h) en Oasis Perdido."
#define STRMSG_120508_0005					"%s Activa 150%%%% de incremento en drop / EXP / SPI / Evento Happy hour (1h) en Oasis Perdido."
#define STRMSG_120508_0006					"%s Obtienes Hielo Ancestral en Oasis Perdido.."
#define STRMSG_120508_0007					"%s Activas la tienda de items avanzados en Oasis Perdido."
#define STRMSG_120508_0008					"%s Activa la tienda de kits en Oasis perdido."
#define STRMSG_120508_0009					"%s Activa la tienda de hiper cartas en Oasis Perdido."
#define STRMSG_120508_0010					"%s Activa la tienda de armas en Oasis Perdido."
#define STRMSG_120508_0011					"%s Activa el portal de lugar oculto en Oasis Perdido."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð?¼±ÅÃ ¼³·Î ÀÎÇ©, %d ºÐ È¡ °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸ÍÁ¡ ½Ã°£ÀÌ %dºÐ ³²¾Ò½À´Ï´Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÁ¡ÀÌ Á¾·áµË´Ï´Ù."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½Ã½ºÅÛ ¸®´º¾ó - ÀüÀï½Ã Æ®¸®°Å ¹«Àû»óÅÂ(ÀÏ½ÃÁ¤Áö)
#define STRMSG_121126_0001					"\\yCommand: Debido al estallido de la guerra. Los miembros tienen prohibido investigar las actividades relacionadas con el cristal en este momento.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ
#define STRMSG_121129_0001					"\\y¿î¿µÀÚ¿¡ ÀÇÇÏ¿© ÀÌµ¿ÀÌ Á¦ÇÑµÈ Áö¿ª ÀÔ´Ï´Ù.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ???? ??? ???
#define STRMSG_130121_0001					"\\El sistema ha sido capturado por las fuerzas NGC. La Evacuación inmediata ha comenzado."
#define STRMSG_130121_0002					"\\cScouts:\\c \\rEl controlador NGC\\r ha sido confirmado."
#define STRMSG_130121_0003					"\\cScouts:\\c \\rEl controlador NGC\\r ha sido destruido."
#define STRMSG_130121_0004					"\\cCommand:\\c \\rLos escudos de Gomora estan activos\\r. Destruir \\rControlador NGC\\r para deshabilitar estos escudos"
#define STRMSG_130121_0005					"\\cCommand:\\c \\rLos escudos de gomora han caído\\r ¡Ataca ahora!"
#define STRMSG_130121_0006					"\\cCommand:\\c \\rGomora ha sido destruido\\r. ¡Todos hacia adelante!"
#define STRMSG_130121_0007					"\\cCommand:\\c \\rGomora debe ser destruída primero\\r"
#define STRMSG_130121_0008					"\\c[%s] Activada por \\c\\rControlador NGC\\r Sobrecargado."
#define STRMSG_130121_0009					"\\y[Sistema de base externa NGC]\\y."

///////////////////////////////////////////////////////////////////////////////

#define STRMSG_130422_0001					"\\y%s %d esta restringido de la arena. El objeto ha sido enviado a tu depósito.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Æ¸Ó ÄÃ·º¼Ç - STRMSG Ãß°¡
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gContour ha sido añadida a tu colección de Contour.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gContour ha sido aplicado [%2d] veces.\\g"
#define STRMSG_130531_0003					"\\g[\\g%s\\g]\\g \\gContour ha llegado a su máxima aplicación. Ha sido cambiado a [%s].\\g"
#define STRMSG_130531_0004					"Tu Contour ha expirado y las estadisticas han sido reiniciadas. Tu motor ha sido desequipado."
#define STRMSG_130531_0005					"\\ySin motor equipado. Teletransportandote a ciudad.\\y"
#define STRMSG_130531_0006					"\\gNo puedes usar el contour que tienes aplicado a tu armadura.\\g"
#define STRMSG_130531_0007					"\\gContour ha sido cambiado.\\g"
#define STRMSG_130531_0008					"\\r[%s] Contour ha expirado.\\r"
#define STRMSG_130531_0009					"\\yArmaduras con Contours aplicados no pueden ser vendidos.\\y"
#define STRMSG_130531_0010					"\\yEl tipo de GEAR no concuerda.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, Æ®¸®°Å ½Ã½ºÅÛ È®Àå - STRMSG Ãß°¡
#define STRMSG_130708_0001					"\\cCommand:\\c NGC Los escudos han sido activados. Destruye los\\rNGC controles\\r para inhabilitar los escudos de  \\rGomora's\\r"
#define STRMSG_130708_0002					"\\cCommand:\\c NGC Las defensas de la base militar estan bajas. Comienza el ataque!"
#define STRMSG_130708_0003					"\\cScouts:\\c \\rNGC El escudo generador\\r ha sido activado."
#define STRMSG_130708_0004					"\\cScouts:\\c \\rNGC El escudo generador\\r ha sido destruido."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Å¸ °èÁ¤ ¼¼·Âº¯°æ
#define STRMSG_130726_0001					"El personaje ya esta en la nación."
#define STRMSG_130726_0002					"El personaje es el lider o el sub-lider, por eso no puede cambiarse de nación."
#define STRMSG_130726_0003					"El personaje esta en una brigada; Por eso no puede cambiarse de nación."
#define STRMSG_130726_0004					"No se encuentra el personaje para cambiarse de nación."
#define STRMSG_130726_0005					"Cambio de nación fallido [AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"Cambio de nación correcto [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"La cuenta no existe."
#define STRMSG_130726_0008					"La cuenta esta conectada, no se puede cambiar de nación."


// 2013-08-30 by bckim, ÇÊµåÀÌµ¿±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\y%s Ha sido restringido la entrada al campo por orden del coronel.\\y"
#define STRMSG_130830_0002					"\\yTu has sido restringido la entrada al campo por orden del coronel.\\y"
#define STRMSG_130830_0003					"\\y%s Esta restringido la entrada al campo por orden del coronel.\\y"
// End. 2013-08-30 by bckim, ÇÊµåÀÌµ¿±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­È­
#define STRMSG_130828_0001					"\\y[%s ha contribuido destruyendo \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s ha iniciado el primer ataque contra\\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s ha echo la mayoria de los ataque contra\\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s ha echo el ataque final contra \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n ha sido derrotado"
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­È­

// 2013-08-14 by jhseol, °ÅÁ¡Àü ¸®´º¾ó - ½Â¸®¼¼·Â GM ¸Þ¼¼Áö »Ñ¸®±â
#define STRMSG_130814_0001					"\\y[%s] ha ganado el punto de guerra estratégico\\y"
// end 2013-08-14 by jhseol, °ÅÁ¡Àü ¸®´º¾ó - ½Â¸®¼¼·Â GM ¸Þ¼¼Áö »Ñ¸®±â










#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
