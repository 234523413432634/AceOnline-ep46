
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Il Server non è attivo."
	#define STRERR_S_ATUMEXE_0002 "Cavità chiusa dal Pre Server"
	#define STRERR_S_ATUMEXE_0003 "Auto Aggiornamento fallito.\r\n Reinstalla il gioco.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERRORE %s(%#04X) ricevuto da %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Errore Sconosciuto: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Impossibile connettersi al server del download."
	#define STRERR_S_ATUMEXE_0007 "La dimensione dei file in download è sconosciuta."
	#define STRERR_S_ATUMEXE_0008 "L'aggiornamento del file non può essere scaricato."
	#define STRERR_S_ATUMEXE_0009 "Memoria o risorse insufficienti."
	#define STRERR_S_ATUMEXE_0010 "Il file .exe non è valido."
	#define STRERR_S_ATUMEXE_0011 "File non trovato."
	#define STRERR_S_ATUMEXE_0012 "La patch specificata non è stata trovata."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Aggiornamento Completato"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Scegli un server."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Aggiornamento della Lista del File Cancellati v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "File Temporanei Cancellati"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Avviso di Aggiornamento"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Aggiornamento completato (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Seleziona file di operazione"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Selezione percorso di operazione"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Il Download è stato cancellato"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download completato"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Aggiornamento a v %s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Impossibile creare il file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Aggiornamento a v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Acquisizione dell'Informazione del File %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Attualizza VTC Guard"				// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Errore Parametro del Calcolo, Calcolo(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Errore Mutex\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Errore di Tipo Excute, Tipo(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Impossibile connettersi al Pre Server."
	#define STRERR_S_ATUMLAUNCHER_0005 "Fallita la connessione al server"
	#define STRERR_S_ATUMLAUNCHER_0006 "Cavità Chiusa dal Pre Server"
	#define STRERR_S_ATUMLAUNCHER_0007 "Errore del File di Avviso!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Auto Aggiornamento fallito.\r\nReinstalla il gioco.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Tutti i server sono inattivi al momento."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s sotto esame..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Tutti i server sono sotto esame. Prova a loggare più tardi."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERRORE %s(%#04X) ricevuto da %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Hai inserito ID o password sbagliato. Entra con un ID e una password registrato."
	#define STRERR_S_ATUMLAUNCHER_0015 "Errore nel processo di login"
	#define STRERR_S_ATUMLAUNCHER_0016 "ID Utenete non iscritto"
	#define STRERR_S_ATUMLAUNCHER_0017 "Doppio login"
	#define STRERR_S_ATUMLAUNCHER_0018 "F server non funziona."
	#define STRERR_S_ATUMLAUNCHER_0019 "I server non funziona."
	#define STRERR_S_ATUMLAUNCHER_0020 "Il servizio è sospeso temporaneamente.\n\n Prova a loggarti più tardi."
	#define STRERR_S_ATUMLAUNCHER_0021 "Ci sono molti utenti online.\n\nProva a loggare più tardi."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Il tuo account è momentaneamente bloccato.\n Periodo : %s\n\nEmail www.airrivals.it per maggiori dettagli."
	#define STRERR_S_ATUMLAUNCHER_0023 "La versione del client non è corretta.\n\nScarica il gioco di nuovo."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERRORE: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Imposssibile loggare al server del download."
	#define STRERR_S_ATUMLAUNCHER_0026 "La dimensione del file di download(%s)non può essere conosciuta."
	#define STRERR_S_ATUMLAUNCHER_0027 "La dimensione del file di download è sconosciuta."
	#define STRERR_S_ATUMLAUNCHER_0028 "Non può essere scaricato l'aggiornamento del file."
	#define STRERR_S_ATUMLAUNCHER_0029 "L'Aggiornamento del file non esiste."
	#define STRERR_S_ATUMLAUNCHER_0030 "Il server selezionato e sotto esame. Prova a loggare più tardi."
	#define STRERR_S_ATUMLAUNCHER_0031 "Il sistema è senza memoria o risorse."
	#define STRERR_S_ATUMLAUNCHER_0032 "Il file .exe non è valido."
	#define STRERR_S_ATUMLAUNCHER_0033 "Il file non può essere trovato."
	#define STRERR_S_ATUMLAUNCHER_0034 "Il percorso non può essere trovato."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, ÇöÀç ½´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÇÑ »çÇ× ¿¡¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î


	#define STRMSG_S_050506		"\'%s\''s l'account è bloccato.\n ragione: %s\n periodo: %s~%s\n\nVisita http://support.airrivals.it per maggiori dettagli."
	#define STRMSG_S_050930		"Scarica il gioco di nuovo.\nURL: %s\nversione più nuova:"
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
	#define STRMSG_S_SCADMINTOOL_0017 "\'game time \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', whole \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', game time: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Do not exist)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Account blocked"
	#define STRMSG_S_SCADMINTOOL_0030 "Chatting prohibited"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s server"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s server,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Account seized"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Do you want to unblock this account?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dsecond)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d wins %d losses"
	#define STRMSG_S_SCADMINTOOL_0042 "Are you sure you want to disconnect and block the account?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Notice : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Number of users : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Received message : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] number of users : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] FieldServer state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Connection to the server has been lost\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Impossibile caricare la corrispondente informazione dell'account."
	#define STRERR_S_SCADMINTOOL_0001 "Impossibile modificare l'informazione dell'account."
	#define STRERR_S_SCADMINTOOL_0002 "Immetti la tua password."
	#define STRERR_S_SCADMINTOOL_0003 "Autenticazione della password fallita"
	#define STRERR_S_SCADMINTOOL_0004 "Immetti il tuo nome di login."
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server non è eseguito."
	#define STRERR_S_SCADMINTOOL_0006 "Impossibile conntersi al Pre Server!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "ERRORE: protocollo corrispondente non esistente."
	#define STRERR_S_SCADMINTOOL_0009 "Immetti il tuo Nome Utente"
	#define STRERR_S_SCADMINTOOL_0010 "Immetti il motivo"
	#define STRERR_S_SCADMINTOOL_0011 "Punto esperienza errore : Livello %2d ==> Esp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Numero massimo di log superato.\r\n\r\nModifica il numero massimo di log o la condizione di ricerca."
	#define STRERR_S_SCADMINTOOL_0013 "Non è possibile connettersi al database."
	#define STRERR_S_SCADMINTOOL_0014 "Non connesso"
	#define STRERR_S_SCADMINTOOL_0015 "Connesso"
	#define STRERR_S_SCADMINTOOL_0016 "Aggiornamento"
	#define STRERR_S_SCADMINTOOL_0017 "Effettuare l'accesso"
	#define STRERR_S_SCADMINTOOL_0018 "Scegli Personaggio"
	#define STRERR_S_SCADMINTOOL_0019 "Gioca"
	#define STRERR_S_SCADMINTOOL_0020 "Sconosciuto"
	#define STRERR_S_SCADMINTOOL_0021 "Database %s(%s:%d)impossibile connettere."
	#define STRERR_S_SCADMINTOOL_0022 "Impossibile aggiungere l'oggetto"
	#define STRERR_S_SCADMINTOOL_0023 "Impossibile trovare l'account bloccato."
	#define STRERR_S_SCADMINTOOL_0024 "Prima, disconnetti dall'account e bloccalo per la modifica."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(soldi) impossibile aggiungere."
	#define STRERR_S_SCADMINTOOL_0026 "Selezionato l'oggetto già esistente, modifica la quantità."
	#define STRERR_S_SCADMINTOOL_0027 "Errore nella ricerca dell'oggetto"
	#define STRERR_S_SCADMINTOOL_0028 "SPI(soldi) posseduto da un personaggio impossibile da cancellare."
	#define STRERR_S_SCADMINTOOL_0029 "Vuoi cancellare questo oggetto?"
	#define STRERR_S_SCADMINTOOL_0030 "Fallita l'eliminazione dell'oggetto."
	#define STRERR_S_SCADMINTOOL_0031 "Fallita la modifica dell'oggetto."
	#define STRERR_S_SCADMINTOOL_0032 "Inserisci l'acount"
	#define STRERR_S_SCADMINTOOL_0033 "Account non esistente. (L'account potrebbe essere bloccato)"
	#define STRERR_S_SCADMINTOOL_0034 "L'account o il personaggio non esiste."
	#define STRERR_S_SCADMINTOOL_0035 "Errore nella ricerca di informazione del personaggio."
	#define STRERR_S_SCADMINTOOL_0036 "Personaggio corrispondente non esiste."
	#define STRERR_S_SCADMINTOOL_0037 "Errore nell'aggiornamento del personaggio."
	#define STRERR_S_SCADMINTOOL_0038 "Informazione del personaggio aggiornata con successo."
	#define STRERR_S_SCADMINTOOL_0039 "Scegli un oggetto."
	#define STRERR_S_SCADMINTOOL_0040 "Scegli il numero degli oggetti."
	#define STRERR_S_SCADMINTOOL_0041 "L'Oggetto corrispondente può essere creato con massimo 5 pezzi."
	#define STRERR_S_SCADMINTOOL_0042 "Inserisci il messaggio."
	#define STRERR_S_SCADMINTOOL_0043 "L'avviso non può essere inviato."
	#define STRERR_S_SCADMINTOOL_0044 "%s: stato del server(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server non è eseguito."
	#define STRERR_S_SCADMINTOOL_0046 "Campo del Server non funziona."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] Stato del IMServer : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÊ - ¾îµå¹Î Åø ÆÊ ±¼­ »ç¿ëµÂ MSG
#define STRERR_S_SCADMINTOOL_0048 "Questo item slot è stato impostato sul tuo Drone elettronico personale. Potrai eliminare lo slot con il comando \socket."
#define STRERR_S_SCADMINTOOL_0049 "Il salvataggio della modifica del Drone elettronico personale non è riuscito (la modifica è stata comunque effettuata)."
#define STRERR_S_SCADMINTOOL_0050 "Impossibile scaricare le informazioni relative al Drone elettronico personale."
#define STRERR_S_SCADMINTOOL_0051 "L'item slot equipaggiato non può essere eliminato."
#define STRERR_S_SCADMINTOOL_0052 "L'utilizzo del bonus nascosto per l'item equipaggiato non è riuscito."
#define STRERR_S_SCADMINTOOL_0053 "La modifica dell'item slot Drone elettronico personale non è riuscita."
#define STRERR_S_SCADMINTOOL_0054 "Non è stato possibile aggiornare le informazioni sul Drone elettronico personale."
#define STRERR_S_SCADMINTOOL_0055 "Non è stato possibile scaricare le informazioni attraverso il livello del Drone elettronico personale."

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
	#define STRMSG_S_SCAT_COLNAME_0021 "Equip"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Not equipped"
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
	#define STRMSG_S_SCAT_COLNAME_0053 "Automatic type(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Valkan Type (1-1 Type)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Dualist Type (1-1 Type)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Cannon Type (1-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Rifle Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Gatling Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Launcher Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Mass Drive Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Rocket Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Missile Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Bundle Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Mine Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Shield Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Dummy Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Pixer Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Decoy Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Tipo di Difesa"
	#define STRMSG_S_SCAT_COLNAME_0070 "Tipo di Attrezzature di Supporto"
	#define STRMSG_S_SCAT_COLNAME_0071 "Tipo di Energia"
	#define STRMSG_S_SCAT_COLNAME_0072 "Tipo di Metallo"
	#define STRMSG_S_SCAT_COLNAME_0073 "Tipo di Card"
	#define STRMSG_S_SCAT_COLNAME_0074 "Enchant Type"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tipo di Serbatoio"
	#define STRMSG_S_SCAT_COLNAME_0076 "Tipo di Pallottola"
	#define STRMSG_S_SCAT_COLNAME_0077 "Per Missione"
	#define STRMSG_S_SCAT_COLNAME_0078 "Tipo di Radar"
	#define STRMSG_S_SCAT_COLNAME_0079 "Tipo di Computer"
	#define STRMSG_S_SCAT_COLNAME_0080 "Tipo carta scommessa"
	#define STRMSG_S_SCAT_COLNAME_0081 "Enchant Destruction Prevention Type"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Blaster Type"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail Gun Type"				// 2005-08-02 by cmkwon
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
	#define STRMSG_S_SCAT_COLNAME_0094 "Amministratore"

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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Logged into Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Connection to Log Server[%15s:%4d]has been lost. Riprova a connetterti.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to PreServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Loggato in Pre Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "La connessione al Pre Server[%15s:%4d]è stata persa. Prova a connetterti di nuovo.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to	IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Logged into IM Server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Connection to IM Server[%15s:%4d]has been lost. Trying reconnection.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Oggetto corrispondente non esistente."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' ha fatto richiesta per l'attesa, quindi l'oggetto è stato promesso."
	#define STRMSG_S_F2DBQUERY_0003 "è dato. Premi F5 per controllare l'inventario"
	#define STRMSG_S_F2DBQUERY_0004 "Abilità %s(%d)è stata aggiunta"
	#define STRMSG_S_F2DBQUERY_0005 "Oggetto corrispondente non esistente."
	#define STRMSG_S_F2DBQUERY_0006 "Impossibile acquistare l'oggetto."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Inizia Battaglia d'occupazione della Città: %d(%10s) occNomeGilda(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Partecipazione brigata : GildaUID(%4d) NomeGilda(%10s) MasterGilda(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Esplosione del Mostro della battaglia d'occupazione della città: %d(%10s) occNomeGilda(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Danni somma totale ==> NomeGlda (%10s) SommaDanni(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Battaglia d'Occupazione città: %d(%10s) MappaCittàIndex(%d) QuestIndex(%d) OccGildaID(%d) OccNomeGilda(%s) OccGildaMasterUID(%d) Á¡·ÉÀü½Ã°£(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Dopo %d minuti, \"%s\" inizierà battaglia d'occupazione città."
	#define STRMSG_S_F2CITYWAR_0007 "Dopo %d minuti, \"%s\" finirà battaglia d'occupazione città."
	#define STRMSG_S_F2CITYWAR_0008 "Mostri richiamati per la battaglia d'occupazione città(%s) : NPC occupazione"
	#define STRMSG_S_F2CITYWAR_0009 "Mostro richiamato per la battaglia d'occupazione città(%s) : %s occupazione di brigata"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" è occupato  \"%s\" attualmente."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" brigata è occupata \"%s\" attualmente."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Fallito caricamento missione"
	#define STRMSG_S_F2QUEST_0001 "Missione non è stata caricata.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Server per test è stato fissato! \r\n\r\nLoadFieldServerDataDebug() necessita di essere eliminato!"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "Primo tipo"
	#define STRMSG_S_F2NOTIFY_0003 "Secondo tipo"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Tipo di Arma sbagliata! Fai una inchiesta all'Amministratore!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Ridotta probabilità d'attacco del %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s fail, probability(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s fail, probability(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s fail, probability(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Danno ridotto del %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, dati %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, ricevi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), dai %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, ricevi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy non riuscito: Probabilità insufficiente>%d"
	#define STRMSG_S_F2NOTIFY_0017 "Remaining dummy[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Informazione pallottola non esistente. Fai una segnalazione all'amministratore."
	#define STRMSG_S_F2NOTIFY_0019 "Informazioni riguardo il calibro del proiettile non esistente. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Questa è l'informazione del proiettile. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Usare il portale non è possibile durante l'evento."
	#define STRMSG_S_F2NOTIFY_0022 "Non è possibile utilizzare il portale quando sei morto."
	#define STRMSG_S_F2NOTIFY_0023 "Non è possibile utilizzare il portale se sei in una formazione di battaglia"
	#define STRMSG_S_F2NOTIFY_0024 "Errore di produzione mappa! Segnala all'amministratore!"
	#define STRMSG_S_F2NOTIFY_0025 "Errore di produzione mappa! Avverti l'amministratore! Nel %d, %d numero del portale nell'indice non esiste!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Usare il portale non è possibile se non è finita la formazione di combattimento"
	#define STRMSG_S_F2NOTIFY_0027 "PORTALE(%04d) trattamento non possibile nel Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Personaggio %10s ,riceve danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Personaggio %10s ,attribuisce danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Personaggio %10s ,attribuisce danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Personaggio %10s ,attribuisce danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "1 -> Personaggio %10s ,riceve danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Personaggio %10s ,attribuisce danni %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Mostro %3d ,attribuisce danni %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Character %10s ,gives dummy damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> Monster %3d ,receives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINA -> Personaggio %10s , dà danno %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINA -> Personaggio %10s ,dà danno falso %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINA -> Mostro %10s ,infligge danno %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "L'inizializzazione delle stat è stata eseguita."
	#define STRMSG_S_F2NOTIFY_0042 "Non puoi usarlo quando sei morto."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO non esiste"
	#define STRMSG_S_F2NOTIFY_0044 "Aggiornamento avvenuto."
	#define STRMSG_S_F2NOTIFY_0045 "Aggiornamento fallito."
	#define STRMSG_S_F2NOTIFY_0046 "Non appartiene alla brigata."
	#define STRMSG_S_F2NOTIFY_0047 "E' già in stato di standby per la richiesta."
	#define STRMSG_S_F2NOTIFY_0048 "Riprova più tardi."
	#define STRMSG_S_F2NOTIFY_0049 "Tu o un'altra persona è il capo della brigata."
	#define STRMSG_S_F2NOTIFY_0050 "E' già nel combattimento della brigata."
	#define STRMSG_S_F2NOTIFY_0051 "Entrambi i capi di brigata non sono nella stessa mappa."
	#define STRMSG_S_F2NOTIFY_0052 "Non tutti i membri della formazione sono nella stessa mappa"
	#define STRMSG_S_F2NOTIFY_0053 "Non tutti i membri della formazione sono nella stessa mappa"
	#define STRMSG_S_F2NOTIFY_0054 "Non appartieni alla brigata."
	#define STRMSG_S_F2NOTIFY_0055 "Il richiedente è diverso."
	#define STRMSG_S_F2NOTIFY_0056 "Tu o un'altra persona non è il capo della brigata."
	#define STRMSG_S_F2NOTIFY_0057 "Due capi di brigata non esistono nella stessa mappa."
	#define STRMSG_S_F2NOTIFY_0058 "Non appartieni alla brigata."
	#define STRMSG_S_F2NOTIFY_0059 "Il richiedente è diverso."
	#define STRMSG_S_F2NOTIFY_0060 "Tu o un'altra persona non è il capo della brigata."
	#define STRMSG_S_F2NOTIFY_0061 "Successo in città con l'occupazione della battaglia difensiva"
	#define STRMSG_S_F2NOTIFY_0062 "Errore nella missione. Rivolgiti all'amministratore."
	#define STRMSG_S_F2NOTIFY_0063 "L'oggetto corrispondente (%s) non può essere montato in questo posto."
	#define STRMSG_S_F2NOTIFY_0064 "Il motore non può essere sgomberato"
	#define STRMSG_S_F2NOTIFY_0065 "Movimento oggetto: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Movimento oggetto sbagliato: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENTO(%d) Non sei capace di gestire Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Informazione della mappa dell'evento anormale! Informa l'Amministratore!"
	#define STRMSG_S_F2NOTIFY_0069 "Il bersaglio d'atterraggio corrispondente non esiste."
	#define STRMSG_S_F2NOTIFY_0070 "Errore nell'acquisto dell'oggetto. Rivolgiti all'amministratore."
	#define STRMSG_S_F2NOTIFY_0071 "Il livello dell'abilità che vuoi acquistare è del tuo livello attuale o inferiore."
	#define STRMSG_S_F2NOTIFY_0072 "Errore.	L'oggetto ha bisogno dell'acquisto dell'abilità."
	#define STRMSG_S_F2NOTIFY_0073 "Errore di vendita. Rivolgiti all'amministratore."
	#define STRMSG_S_F2NOTIFY_0074 "Errore d'acquisto. Rivolgiti all'amministratore."
	#define STRMSG_S_F2NOTIFY_0075 "\'L'oggetto di credito\' è stato acquistato."
	#define STRMSG_S_F2NOTIFY_0076 "Lista degli acquisti : \'%s(%d pezzi)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Già unito al gruppo."
	#define STRMSG_S_F2NOTIFY_0078 "Non puoi entrare se sei il leader del gruppo"
	#define STRMSG_S_F2NOTIFY_0079 "Non puoi entrare se la battaglia di formazione è in atto."
	#define STRMSG_S_F2NOTIFY_0080 "Avvicinare tutti formazione del personale informazione non è supportato!"
	#define STRMSG_S_F2NOTIFY_0081 "Info della mappa dell'evento anormale! Riporta all'Amministratore!"
	#define STRMSG_S_F2NOTIFY_0082 "Questo è un account che non può effettuare una transazione"
	#define STRMSG_S_F2NOTIFY_0083 "Eccesso di caricamento di %s."
	#define STRMSG_S_F2NOTIFY_0084 "Cordinate di un possibile movimento: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Utente:"
	#define STRMSG_S_F2NOTIFY_0086 "Possono essere viste massimo 20 persone."
	#define STRMSG_S_F2NOTIFY_0087 "L'utente corrispondente (%s) non esiste"
	#define STRMSG_S_F2NOTIFY_0088 "Non appartiene al gruppo."
	#define STRMSG_S_F2NOTIFY_0089 "Tempo presente: %d:%d, tempo Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Tempo cambiato: %d:%d, tempo Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Non connesso al server NPC"
	#define STRMSG_S_F2NOTIFY_0092 "l'oggetto corrispondente(%d) non esiste"
	#define STRMSG_S_F2NOTIFY_0093 "Limitato a 10 pezzi se non è un oggetto contabile."
	#define STRMSG_S_F2NOTIFY_0094 "Totale persone connesse nella mappa \'%s\' : %dpersone"
	#define STRMSG_S_F2NOTIFY_0095 "Mappa %s %s connessioni simultanee: %d persone - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Mappa %s %s connessioni simultanee: %d persone - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Canale della Mappa presente: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Info delle pallottole non esistente. Segnala all'Amministratore."
	#define STRMSG_S_F2NOTIFY_0099 "Info riguardo il calibro delle pallottole non eisstente. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Info riguardo le pallottole non esistente. Segnala all'Amministratore"
	#define STRMSG_S_F2NOTIFY_0101 "Info riguardo il calibro delle pallottole non esistente. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Utente corrispondente (%s) non esistente"
	#define STRMSG_S_F2NOTIFY_0103 "L'utente corrispondente (%s) è morto"
	#define STRMSG_S_F2NOTIFY_0104 "l'utente corrispondente (%s) non esistente"
	#define STRMSG_S_F2NOTIFY_0105 "Sistema come un Account Standard"
	#define STRMSG_S_F2NOTIFY_0106 "Standard Account è stato cancellato"
	#define STRMSG_S_F2NOTIFY_0107 "Invicibilità è stata attivata."
	#define STRMSG_S_F2NOTIFY_0108 "Invincibilità è stata disattivata."
	#define STRMSG_S_F2NOTIFY_0109 "Il danno dell'arma sarà modificato da %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Sarà inizializzato alla ricarica dell'oggetto"
	#define STRMSG_S_F2NOTIFY_0111 "Sarà inizializzato alla ricarica dell'oggetto"
	#define STRMSG_S_F2NOTIFY_0112 "L'utente corrispondente (%s) non esistente"
	#define STRMSG_S_F2NOTIFY_0113 "Invisibilità è stata disattivata"
	#define STRMSG_S_F2NOTIFY_0114 "Invisibilità è stata attivata."
	#define STRMSG_S_F2NOTIFY_0115 "%s evento non è in corso"
	#define STRMSG_S_F2NOTIFY_0116 "%s evento è iniziato. (ingrandimento:%4.2f, Tempo dell'Evento:%3d minuti)"
	#define STRMSG_S_F2NOTIFY_0117 "Sistema come un account premium standard"
	#define STRMSG_S_F2NOTIFY_0118 "Fallita la sistemazione come account premium"
	#define STRMSG_S_F2NOTIFY_0119 "Sistma come account premium super"
	#define STRMSG_S_F2NOTIFY_0120 "Questa non è la mappa della battaglia per l'occupazione della città."
	#define STRMSG_S_F2NOTIFY_0121 "La battaglia per l'occupazione della città non può iniziare"
	#define STRMSG_S_F2NOTIFY_0122 "La battaglia per l'occupazione della città non può finire"
	#define STRMSG_S_F2NOTIFY_0123 "La modalità furtiva è stata inizializzata."
	#define STRMSG_S_F2NOTIFY_0124 "In modalità furtiva"
	#define STRMSG_S_F2NOTIFY_0125 "La mappa non è valida"
	#define STRMSG_S_F2NOTIFY_0126 "Imposta l'Evento Happy Hour [tempo in progresso:%4d minuti)]"
	#define STRMSG_S_F2NOTIFY_0127 "L'evento Happy Hour è finito"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> Dal mostro %3d , danno ricevuto %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "1tipo -> Dal mostro %3d , danno ricevuto %5.2f(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Autenticato con accesso %s"
	#define STRMSG_S_F2NOTIFY_0131 "Non puoi processarela routine in completamento %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Fallito nel tentativo di eliminare un gruppo personale! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Fermato!"
	#define STRMSG_S_F2NOTIFY_0136 "ERRORE FATALE: Riportalo all'amministratore! Errore della variabile della bottega!"
	#define STRMSG_S_F2NOTIFY_0137 "%s è stato cancellato."
	#define STRMSG_S_F2NOTIFY_0138 "Il canale che stai usando è disattivato, così i mostri e le altre funzioni non sono disponibili."
	#define STRMSG_S_F2NOTIFY_0139 "Fermato. Usa un altro canale."
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Timer movimento %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Auto recupero Hp fermato"
	#define STRMSG_S_F2NOTIFY_0143 "Non è possibile effettuare l'auto recupero HP in questa mappa"
	#define STRMSG_S_F2NOTIFY_0144 "Recuperi 5.2 HP per emergenza"
	#define STRMSG_S_F2NOTIFY_0145 "UP HP gradualae fermato (tempo rimasto: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "UP Dp Graduale Fermato (tempo rimasto: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "UP EP Graduale Fermato (tempo rimasto: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "L'evento %s è stato completato."
	#define STRMSG_S_F2NOTIFY_0149 "%s event under progress (magnification %4.2f, remaining:%3dminute)"
	#define STRMSG_S_F2NOTIFY_0150 "Il comando non è stato esercitato"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Rorre divisione del punto espereienza(%s, %s(%d)): fDannoTotale(%d) < 0.0f or Vettore mancante: %d, Distanza(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Errore messaggio StatoClient non valido Inizio Game[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Errore messaggio StatoClient non valido Inizio Game[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) trattamento impossibile in ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Anormale informazione dellevento della mappa! Informa l'Amministratore!\rCorrente(%s, %s, %04d), Obiettivo(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) trattamento impossibile T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Anormale informazione dell'evento della mappa! Informa l'Amministratore! Corrente(%s, %s, %04d), Obiettivo(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP trattamento impossibile in T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) trattamento impossibile(capo gruppo) in Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) trattamento impossibile nel Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) trattamento impossibile in Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP trattamento impossibile in T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Party warp failed: %s -> distance: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) trattamento impossibile in Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> clicca il tasto OK!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "La missione non è stata caricata.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) trattamento impossibile in HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) trattamento impossibile in HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "Errore fatale: Questo messaggio non deve essere inviato al server del campo membri che non vi appartengono. Verificare\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) trattamento impossibile in T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) trattamento impossibile in T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Punti Esperienza"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Risanamento dei Punti Esperienza"
	#define STRMSG_S_F2EVENTTYPE_0003 "Drop Item"
	#define STRMSG_S_F2EVENTTYPE_0004 "Drop Item Rari"
	#define STRMSG_S_F2EVENTTYPE_0005 "Evento Sconosciuto"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Loggato nel Pre Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Connection to Pre Server [%15s:%4d]has been lost. Attempting reconnection.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' già esistente"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' è già in brigada."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' è già usato come nome da un'altra brigata"
	#define STRMSG_S_I2NOTIFY_0003 "Caricamento Brigata fallito - Segnala all'Amministratore!"
	#define STRMSG_S_I2NOTIFY_0004 "Il tuo amico '%s' si è loggato"
	#define STRMSG_S_I2NOTIFY_0005 "Controllo della formazione precedente"
	#define STRMSG_S_I2NOTIFY_0006 "Formazione precedente non esistente"
	#define STRMSG_S_I2NOTIFY_0007 "Riunita la formazione"
	#define STRMSG_S_I2NOTIFY_0008 "Sei attualmente in una formazione"
	#define STRMSG_S_I2NOTIFY_0009 "Fatal Error: Errore fatale gruppo! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Stato della formazione personale non valido."
	#define STRMSG_S_I2NOTIFY_0011 "formazione personale ha già unito la brigata"
	#define STRMSG_S_I2NOTIFY_0012 "Questa persona è già entrata nella brigata"
	#define STRMSG_S_I2NOTIFY_0013 "Non puoi invitare te stesso"
	#define STRMSG_S_I2NOTIFY_0014 "Sei in uno stato dove non è possibile fare adesioni delle brigate"
	#define STRMSG_S_I2NOTIFY_0015 "Hai raggiunto il limite massimo di brigate in cui puoi entrare"
	#define STRMSG_S_I2NOTIFY_0016 "Sei in uno Stato in cui l'adesione brigate non è consentito"
	#define STRMSG_S_I2NOTIFY_0017 "Il capo della brigata non può ritirarsi dalla brigata"
	#define STRMSG_S_I2NOTIFY_0018 "Non può recedere dal brigata mentre vi trovate in una brigata lotta"
	#define STRMSG_S_I2NOTIFY_0019 "Non è possibile espellere brigata personale, mentre in lotta brigata"
	#define STRMSG_S_I2NOTIFY_0020 "Il capo di brigata non può essere espulso"
	#define STRMSG_S_I2NOTIFY_0021 "Non può disperdere brigata mentre vi trovate in una brigata lotta"
	#define STRMSG_S_I2NOTIFY_0022 "Non può cambiare per lo stesso nome"
	#define STRMSG_S_I2NOTIFY_0023 "Sei in uno stato dove non è possibile cambiare il nome della brigata"
	#define STRMSG_S_I2NOTIFY_0024 "Sei in uno stato dove non è possibile cambiare il marchio della brigata"
	#define STRMSG_S_I2NOTIFY_0025 "Sei in uno Stato in cui rango non può essere modificato"
	#define STRMSG_S_I2NOTIFY_0026 "Rank è sovrapposta"
	#define STRMSG_S_I2NOTIFY_0027 "Rango di reggimento cambiare leader non è possibile."
	#define STRMSG_S_I2NOTIFY_0028 "Variazione del reggimento leader rango non è possibile."
	#define STRMSG_S_I2NOTIFY_0029 "Il numero totale di utenti:%d persone (uscita fino a%d persone)"
	#define STRMSG_S_I2NOTIFY_0030 "Aggiunto messaggio agli amministratori elenco"
	#define STRMSG_S_I2NOTIFY_0031 "Soppresso dagli amministratori del messaggio elenco"
	#define STRMSG_S_I2NOTIFY_0032 "Server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Numero totale di persone connesse al server \'%s\' : %d persone"
	#define STRMSG_S_I2NOTIFY_0034 "Vuoi veramente chiudere il server (%s)? ServerID:%d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' non sta giocando"
	#define STRMSG_S_I2NOTIFY_0036 "Numero di utenti di tutto:%d persone (in uscita fino a%d persone)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Reggimento corrispondente non esistente"
	#define STRMSG_S_I2NOTIFY_0039 "Whisper blocco è stato disattivato"
	#define STRMSG_S_I2NOTIFY_0040 "Le chat private sono state bloccate"
	#define STRMSG_S_I2NOTIFY_0041 "Non aderire alla brigata"
	#define STRMSG_S_I2NOTIFY_0042 "Brigata (%d) non disponibile"
	#define STRMSG_S_I2NOTIFY_0043 "Clima corrispondente (%s) non esistente"
	#define STRMSG_S_I2NOTIFY_0044 "Campo Server non è valido"
	#define STRMSG_S_I2NOTIFY_0045 "Mappa corrispondente (%s) non esistente"
	#define STRMSG_S_I2NOTIFY_0046 "Non puoi chattare per %d minuti!"
	#define STRMSG_S_I2NOTIFY_0047 "Chat blocco insieme: '%10s',%3d minuti"
	#define STRMSG_S_I2NOTIFY_0048 "Chat blocco condizione è stata annullata."
	#define STRMSG_S_I2NOTIFY_0049 "Chat blocco annullato: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (conto:%s, mappa:%d (%d), del livello:%d), DA GIOCO"
	#define STRMSG_S_I2NOTIFY_0051 "Non può convocare te."
	#define STRMSG_S_I2NOTIFY_0052 "Brigata corrispondente non esistente."

	#define STRMSG_S_IMSERVER_050607_0001	"Mappa corrispondente non esistente."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Logged into the Field Server.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Connection to Field Server[%15s:%4d] has been lost. Attempting reconnection.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Collision check between monster and object does not exist\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "City occupation battle monster (%10s) summoned\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Logged in with %s account(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Successo"
	#define STRMSG_S_P2PRENOTIFY_0002 "Fallito"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR] Error in adding account information, AccountName(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Ciao. Questo è l'Amministratore di AirRivals."
	#define STRMSG_SCAT_051115_0002		"Faremo la nostra consueta manutenzione in 10 minuti."
	#define STRMSG_SCAT_051115_0003		"Per favore spostati in un'arena sicura ed esci dal gioco."
	#define STRMSG_SCAT_051115_0004		"Prima di tutto, il server dei NPC sarà interrotto."
	#define STRMSG_SCAT_051115_0005		"Inizierà la regolare manutenzione di AirRivals."
	#define STRMSG_SCAT_051115_0006		"Godetevi la giornata su AirRivals."
	#define STRMSG_SCAT_051115_0007		"Ci sarà un checkup del server tra 5 minuti." // 5     .
	#define STRMSG_SCAT_051115_0008		"Il server sarà off per 60 minuti."	//  60   
	#define STRMSG_SCAT_051115_0009		"La manutenzione del server inizierà tra 30 minuti."
	#define STRMSG_SCAT_051115_0010		"La manutenzione del server inizierà tra 15 minuti."
	#define STRMSG_SCAT_051115_0011		"La manutenzione del server inizierà tra 10 minuti."
	#define STRMSG_SCAT_051115_0012		"La manutenzione del server inizierà tra 5 minuti."
	#define STRMSG_SCAT_051115_0013		"La manutenzione del server inizierà a momenti."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Modalità Invisibile: Gli utenti non possono vederti e non puoi usare le armi."
	#define STRMSG_060509_0001			"Stato Invincibile:Non riceverai alcun danno."
	#define STRMSG_060509_0002			"Modalità Silenziosa: I Mostri non ti attaccheranno per primo."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"La tua richiesta è stata inviata al GM. Uno di loro ti contatterà il più presto possibile."
	#define	STRMSG_060526_0001			"Sei in grado di aggiornare automaticamente.\r\n\r\n Esegui il download della patch dalla Hompage(%s) e riconnettiti.\r\n\r\n Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Questo ID non è registrato o il ID e la password non corrispondono."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Il server del gioco è momentaneamente off per manutenzione. Si prega di consultare la home page ufficiale (www.airrivals.it) per ulteriori informazioni."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"La versione del client non è valida.\r\n Reinstalla o scarica il file della patch."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Sei stato fatto fuori da %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree server DB(atum2_db_20) l'inizializzazione deve essere condotta dopo la chiusura del server Jamboree."
	#define STRMSG_070410_0001   	"Vuoi davvero inizializzare il server jamboree DB(atum2_db_20)-[Validation number:%d]"
	#define STRMSG_070410_0002   	"Jamboree server	DB(atum2_db_20) e inizializzato."
	#define STRMSG_070410_0003   	"Jamboree server	DB(atum2_db_20) inizializzazione fallita!!"
	#define STRMSG_070410_0004   	"'%s' duplicazione dati al Jamboree server DB(atum2_db_20) completata."
	#define STRMSG_070410_0005   	"'%s' duplicazione dati al Jamboree server DB(atum2_db_20) fallita, - il pergonaggio non esiste!"
	#define STRMSG_070410_0006   	"%s' duplicazione dati al Jamboree server DB(atum2_db_20) fallita - Esiste il personaggio dell'account corrispondente!"
	#define STRMSG_070410_0007   	"'%s' duplicazione dati al Jamboree server DB(atum2_db_20) fallita - in fallimento inoltre il DB!"
	#define STRMSG_070410_0008   	"'%s' duplicazione dati al Jamboree server DB(atum2_db_20) fallita - Sconosciuto (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (bassa)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (media)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (alta)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (bassissimo)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (medio livello)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (altissimo)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (bassa)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (media)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (alta)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (bassa)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (media)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (alta)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (bassissimo)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (medio livello)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (altissimo)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (bassa)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (media)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (alta)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Non puoi iniziare visto che non sei in modalità furtiva."
#define STRMSG_070615_0001		"Non puoi iniziare la guardia."
#define STRMSG_070620_0000	"L'utente non può iniziare la guardia."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Punti Guerra"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Hai giocato ad AirRivals per %d ore."
#define STRMSG_070628_0001				"Hai giocato ad AirRivals per %d ore. Esegui i passi necessari per fare il resto."
#define STRMSG_070628_0002				"Hai giocato a lungo. Sta diventando periocoloso per la salute. Per piacere stacca e prenditi cura di te chiudendo il gioco. E' per il tuo bene."
#define STRMSG_070628_0003				"Giocare a questo gioco sarà critico per la tua salute. Curati chiudendo il gioco in questo momento. Se no potresti ammalarti e la probabilità d'accesso al gioco sarà dello 0%. Torna a giocare dopo 5 ore da quando hai chiuso."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' non è proibito entrando in Arena."
#define STRMSG_070711_0001 "\'%s\' è proibito per entrare in arena (tempo rimanente: %d minuti)"
#define STRMSG_070711_0002 "Non puoi entrare in arena per %d minuti!"
#define STRMSG_070711_0003 "Il tuo divieto di entrare in arena è finito."
#define STRMSG_070711_0004 "Uso dell'Arena è proibito per \'%s\'."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (bassissimo)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (livello medio)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (altissimo)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Questo comando può essere usato solo dopo aver scelto la nazione."
#define STRMSG_070830_0002                                   "Mappa della Sala Conferenza (%d) della nazione corrispondente non è disponibile."
#define STRMSG_070830_0003                                   "Numero di persone che possono entrare nella Stanza della Conferenza: %d"
#define STRMSG_070830_0004                                   "'%s' è già aggiunto alla lista di entrata."
#define STRMSG_070830_0005                                   "'%s' non ha il permesso di entrare."
#define STRMSG_070830_0006                                   "'%s' non è un personaggio valido."
#define STRMSG_070830_0007                                 "'%s' non può essere aggiunto alla lista d'entrata. (Massimo %d persone)"
#define STRMSG_070830_0008                                   "'%s' ha un'auotizzazione per entrare nella Sala Conferenza"
#define STRMSG_070830_0009                                   "Permesso per entrare in Sala Conferenza dato."
#define STRMSG_070830_0010                                   "Permesso per entrare in Sala Conferenza cancellato."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s ti ha mandato %s come un regalo."
#define STRMSG_071115_0002									"Lista dei Presenti: \'%s (%d pezzi)\'"
#define STRMSG_071115_0003									"\\y%s send a present to %s.  Present is  %s. Please check the warehouse."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Il sistema di chiamata non è attivo. Contatta il supporto del gioco: http://support.airrivals.it"
#define STRMSG_071120_0002									"Il Sistema di Appello è attivato."
#define STRMSG_071120_0003									"Il Sistema di Appello è concluso."
#define STRMSG_071120_0004									"Il Sistema di Appello partirò da %s a %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s ti ha mandato %s(%d) come un regalo. Verifica nel tuo magazzino."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Impostazioni di Risoluzione invalidi. Controlla ancora."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'Errore esistente nella modifica di blocco di %s. ErrorCode(%d)"
#define STRMSG_080201_0002									"L'account '%s' è bloccato. [Blocco e Data: %s]"
#define STRMSG_080201_0003									"L'account '%s' non esiste nella lista del blocco. ErroCode(%d)"
#define STRMSG_080201_0004									"Si è verificato un errore nel processo di blocco dell'account di %s. ErrorCode(%d)"
#define STRMSG_080201_0005									"L'Account '%s' è stato rimosso dalla lista di blocco." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (bassissima)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medio livello)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (altissima)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), Can't connect to ArenaServer[%15s:%4d] Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Connesso al server Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Connection to Arena Server[%15s:%4d] is closed. Trying to re-connect.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Numero \\y%d Sala d'Attesa dell'Arena è stato dato l'attributo dell'evento.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "Numero \\y%d Sala d'Attesa dell'Arena è stato scaricato dall'attributo dell'evento.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Fallito la ricezione dell'Attributo dell'Arena.\r\n"
#define STRMSG_080428_0001					"%s è stato abbattuto."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º º¸ DB¿¡ á(½Ô °è ¸¯ÅÍ »ý¼º ÇÑ ½ýºÅÛá) - 
#define STRMSG_080430_0001					"Il server selezionato è quello dove non è possibile la creazione di nuovi personaggi."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼ö »çÇ× - 
#define STRMSG_080613_0001					"Ammissione alla brigata %s è stata rigettata."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] Nessuna funzione di richesta al DB(QP_xxx) !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s non parteciperà alla chat per %d minuti.\\y"
#define STRMSG_081230_0002					"\\yIl capo ti ha escluso dalla chat per %d minuti.\\y"
#define STRMSG_081230_0003					"\\yPuoi utilizzare di nuovo la chat.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °å µ¿ÀÇâ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - »ç¿ëÇÏÁö ¾Ê, STRMSG_090831_0001´Â ÆäÀÌÁö·Î ó¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
/*#define STRMSG_090831_0002					"Installa lo hack shield"*/
#define STRMSG_090831_0002					"Installa lo nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"Interrompi"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - 
#define STRMSG_090902_0001					"http://it.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø Çóµµ á(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (bassa)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (media)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (alta)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (bassa)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (media)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (alta)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (bassa)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (media)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (alta)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ ¼Ó Çã¿ë »ó
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Server non registrato (potrebbe trattarsi di un server privato illegale)."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Si è verificato un errore durante la connessione con la banca dati."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"La conferma è avvenuta con successo."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"L'IP del server è stato registrato ma le autorizzazioni successive sono state negate."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Il comando \"arresta Windows\" è stato inviato."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ¸®°Å ½ýºÅÛ  ¾²

// 1Â÷ 

#define STRMSG_120330_0001					"%s attiva il portale di salto per il Luogo Nascosto sul Sentiero delle Ceneri."
#define STRMSG_120330_0002					"%s attiva un 100%%%% di aumento dei punti esperienza (evento Happy Hour per 1 ora) sul Sentiero delle Ceneri."
#define STRMSG_120330_0003					"%s attiva un 100%%%% di aumento del tasso di drop degli item (evento Happy Hour per 1 ora) sul Sentiero delle Ceneri."
#define STRMSG_120330_0004					"%s attiva un 100%%%% di aumento del tasso di drop degli item/ dei punti esperienza/ degli SPI (evento Happy Hour per 1 ora) sul Sentiero delle Ceneri."
#define STRMSG_120330_0005					"%s attiva Negozio delle Armi sul Sentiero delle Ceneri."
#define STRMSG_120330_0006					"%s attiva lo Shop delle Ipercarte sul Sentiero delle Ceneri."
#define STRMSG_120330_0007					"%s attiva il Kit-Shop sul Sentiero delle Ceneri."
#define STRMSG_120330_0008					"%s chiama un mostro gigantesco sul Sentiero delle Ceneri."
#define STRMSG_120330_0009					"Il Cristallo è sparito."

// 2Â÷ 

#define STRMSG_120508_0001					"%s riceve tanti punti di guerra quanti %d quanti ne ha ricevuto nell'Oasi Sprofondata."
#define STRMSG_120508_0002					"%s chiama un mostro boss all'Oasi Sprofondata."
#define STRMSG_120508_0003					"%s attiva un 150%%%% di aumento dei punti esperienza (evento Happy Hour per 1 ora) nell'Oasi Sprofondata."
#define STRMSG_120508_0004					"%s attiva un 150%%%% di aumento del tasso di drop degli item (evento Happy Hour per 1 ora) nell'Oasi Sprofondata."
#define STRMSG_120508_0005					"%s attiva un 100%%%% di aumento del tasso di drop degli item/ dei punti esperienza/ degli SPI (evento Happy Hour per 1 ora) nell'Oasi sprofondata."
#define STRMSG_120508_0006					"%s riceve Ghiaccio antico nell'Oasi Sprofondata."
#define STRMSG_120508_0007					"%s attiva l'Item Shop ampliato nell'Oasi Sprofondata."
#define STRMSG_120508_0008					"%s attiva il Kit-Shop nell'Oasi Sprofondata."
#define STRMSG_120508_0009					"%s attiva lo Shop delle Ipercarte nell'Oasi Sprofondata."
#define STRMSG_120508_0010					"%s attiva Negozio delle Armi nell'Oasi Sprofondata."
#define STRMSG_120508_0011					"%s attiva il portale di salto per il Luogo Nascosto nell'Oasi Perduta."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, %d ºÐ  °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸Í ½ð£ÀÌ %dºÐ ³²¾Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÀÌ ·áµÙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½ýºÅÛ ¸®´º¾ó - ÀüÀï½Ã ¸®°Å ¹«Àû»óÅÂ(ÀÃÁö)
#define STRMSG_121126_0001					"\\yComando: con i combattimenti in corso tutte le attività direttamente legate ai Cristalli sono vietate.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX ¸Ê ¿öÇÁÇÑ
#define STRMSG_121129_0001					"\\y¿ ÀÇ ÀÌ ÇÈ Áö¿ª ÀÙ.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀüÀü±âÁö ¸®°Å ½ýºÅÛ
#define STRMSG_130121_0001					"\\c Le truppe NGC hanno conquistato il sistema. È iniziata l'evacuazione."
#define STRMSG_130121_0002					"\\Esploratori:\\c L' \\runità di controllo NGC\\r è stata rinforzata."
#define STRMSG_130121_0003					"\\Esploratori:\\c L' \\runità di controllo NGC\\r è stata distrutta."
#define STRMSG_130121_0004					"\\cComando:\\c Gli scudi di \\rGomora\\r sono attivi. Distruggi le \\runità di controllo NGC\\r per disattivare gli scudi."
#define STRMSG_130121_0005					"\\cComando:\\c Gli scudi di \\rGomora\\r sono disattivati! Attacca ora!"
#define STRMSG_130121_0006					"\\cComando:\\c \\rGomora\\r è stato distrutto! Avanti!"
#define STRMSG_130121_0007					"\\cComando:\\c Prima deve essere distrutto \\rGomora\\r."
#define STRMSG_130121_0008					"\\c[%s] è stato attivato attraverso il sovraccarico delle \\c\\runità di controllo NGC\\r."
#define STRMSG_130121_0009					"\\y[Sistema della base di avamposto della NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ  - ¼­ºêŸÀÔ á±¸ ½ýºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d non è ammesso nell'Arena. L'item è stato inviato al tuo Magazzino.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Ó Ä÷º¼Ç - STRMSG á
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gLa carta skin è stata aggiunta alla collezione delle tue carte skin.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gLa carta per la skin è stata utilizzata [%2d] volte.\\g"
#define STRMSG_130531_0003					"\\g[%s] La carta per la skin ha raggiunto il suo livello massimo di utilizzo. Ricevi [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"La tua carta per la skin attuale è scaduta e i valori corrispondenti sono stati eliminati. Il tuo propulsore non è più equipaggiato."
#define STRMSG_130531_0005					"\\yNessun propulsore è equipaggiato. Verrai teletrasporto alla città.\\y"
#define STRMSG_130531_0006					"\\gNon puoi servirti della carta per la skin in utilizzo sulla tua armatura.\\g"
#define STRMSG_130531_0007					"\\gLa skin è stata modificata.\\g"
#define STRMSG_130531_0008					"\\rLa carta per la skin di [%s] è scaduta.\\r"
#define STRMSG_130531_0009					"\\yLe armature con carte per la skin equipaggiate non possono essere vendute.\\y"
#define STRMSG_130531_0010					"\\yI tipi di Gear non corrispondono.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ¸®°Å ½ýºÅÛ Àå - STRMSG á
#define STRMSG_130708_0001					"\\cComando:\\c Gli scudi NGC sono stati attivati. Distruggi le \\runità di controllo NGC\\r per disattivare gli scudi di \\rGomora\\r."
#define STRMSG_130708_0002					"\\cComando:\\c La difesa della Base Militare NGC è caduta. Attacca ora!"
#define STRMSG_130708_0003					"\\cEsploratori:\\c Il \\Generatore scudo NGC\\r è stato avvistato."
#define STRMSG_130708_0004					"\\cEsploratori:\\c Il \\Generatore scudo NGC\\r è stato distrutto."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRMSG_130726_0001					"Il tuo personaggio è già membro di questa nazione."
#define STRMSG_130726_0002					"Il tuo personaggio è capo o vicecapo e per questo non può cambiare nazione."
#define STRMSG_130726_0003					"Il tuo personaggio è in una brigata e quindi non è possibile cambiare nazione."
#define STRMSG_130726_0004					"Nessun personaggio può effettuare il cambio di nazione."
#define STRMSG_130726_0005					"Il cambio di nazione è fallito [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Il cambio di nazione è avvenuto con successo [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Questo account non esiste."
#define STRMSG_130726_0008					"Sei connesso al tuo account e quindi la nazione non può essere cambiata."


// 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\yI privilegi di volo di %s sono stati revocati dal Capo Nazione.\\y"
#define STRMSG_130830_0002					"\\yI privilegi di volo sono stati revocati dal Capo Nazione.\\y"
#define STRMSG_130830_0003					"\\yI privilegi di volo di %s sono stati revocati dal Capo Nazione.\\y"
// End. 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­
#define STRMSG_130828_0001					"\\y[%s ha contribuito alla distruzione di \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s ha effettuato il primo colpo contro \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s ha effettuato la maggior parte degli attacchi contro \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s ha effettuato l'attacco decisivo contro \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n è stato sconfitto."
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­

// 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â
#define STRMSG_130814_0001					"\\y[%s] ha vinto la guerra NGC punti strategici.\\y"
// end 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â

// 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)
#define STRMSG_130318_0001					"%s ha chiamato il Boss in una zona bloccata."
#define STRMSG_130318_0002					"%s ha chiamato il Boss nelle rovine."
// End. 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yAl momento non puoi utilizzare il centro aste.\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
