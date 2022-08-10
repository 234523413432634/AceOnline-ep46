
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Der Server ist nicht aktiv."
	#define STRERR_S_ATUMEXE_0002 "Socket vom Login-Server geschlossen!"
	#define STRERR_S_ATUMEXE_0003 "Automatisches Update fehlgeschlagen.\r\n Bitte installiere das Spiel neu.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) erhalten von %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unbekannter Fehler: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Kann nicht mit dem Download-Server verbinden."
	#define STRERR_S_ATUMEXE_0007 "Downloadgr��e des Files ist nicht bekannt."
	#define STRERR_S_ATUMEXE_0008 "Das Update-File kann nicht heruntergeladen werden"
	#define STRERR_S_ATUMEXE_0009 "Das System hat keinen weiteren Speicher/Ressourcen zur Verf�gung."
	#define STRERR_S_ATUMEXE_0010 "Das .exe File ist ung�ltig."
	#define STRERR_S_ATUMEXE_0011 "File nicht gefunden."
	#define STRERR_S_ATUMEXE_0012 "Der angegebene Pfad wurde nicht gefunden."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Update abgeschlossen"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Bitte w�hle einen anderen Server."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Update der Dateil�schungsliste v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "L�sche tempor�re Dateien"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Update Benachrichtigung"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Update vollst�ndig (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "W�hle die Ausf�hrungsdatei"
	#define STRMSG_S_ATUMLAUNCHER_0007 "W�hle den Ausf�hrungspfad"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Herunterladen wurde abgebrochen"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Herunterladen abgeschlossen"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Update auf c%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Erstellung von Datei %s nicht m�glich"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Update auf v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Empf�ngt Dateiinformation %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "VTC Guard aktualisieren"				// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����
    #define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard-Update abgeschlossen"		// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Fehler] Fehler beim Parameter z�hlen, Zahl(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Fehler] Mutex Fehler\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Fehler] Laufzeitfehler, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Fehler] ID Dekodierungsfehler, Dekodierte ID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Kann nicht mit dem Login-Server verbinden."
	#define STRERR_S_ATUMLAUNCHER_0005 "Fehler beim Verbinden zum Server"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket vom Login-Server geschlossen!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Hinweis-Datei-Fehler!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Automatisches Update fehlgeschlagen.\r\n Bitte installiere das Spiel neu.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Alle Server sind zur Zeit inaktiv."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s wird untersucht..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Alle Server werden untersucht. Versuch es sp�ter noch einmal."
	#define STRERR_S_ATUMLAUNCHER_0013 "FEHLER %s(%#04X) erhalten von %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Du hast eine falsche ID oder ein falsches Passwort eingegeben.	Bitte trage eine g�ltige ID und Passwort ein."
	#define STRERR_S_ATUMLAUNCHER_0015 "Fehler beim Login"
	#define STRERR_S_ATUMLAUNCHER_0016 "Keine ID angegeben"
	#define STRERR_S_ATUMLAUNCHER_0017 "Doppelter Login"
	#define STRERR_S_ATUMLAUNCHER_0018 "Der F Server wird nicht ausgef�hrt"
	#define STRERR_S_ATUMLAUNCHER_0019 "Der I Server wird nicht ausgef�hrt."
	#define STRERR_S_ATUMLAUNCHER_0020 "Service ist momentan gestopt. \n\nVersuche es sp�ter erneut."
	#define STRERR_S_ATUMLAUNCHER_0021 "Es sind zu viele User online.\n\nVersuch es sp�ter nochmal."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Dein Account ist momentan geblockt.\n period : %s\n\nSchicke eine E-Mail f�r weitere Details an www.airrivals.de"
	#define STRERR_S_ATUMLAUNCHER_0023 "Deine Clientversion ist nicht die richtige.\n\nDownloade das Spiel bitte nochmal."
	#define STRERR_S_ATUMLAUNCHER_0024 "FEHLER: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Kann keinen Login zum Download-Server durchf�hren."
	#define STRERR_S_ATUMLAUNCHER_0026 "Gr��e der Downloaddatei (%s) ist unbekannt."
	#define STRERR_S_ATUMLAUNCHER_0027 "Die gr��e der Downloaddatei ist unbekannt."
	#define STRERR_S_ATUMLAUNCHER_0028 "Kann die Updatedatei nicht runterladen."
	#define STRERR_S_ATUMLAUNCHER_0029 "Aktualisierte Datei existiert nicht."
	#define STRERR_S_ATUMLAUNCHER_0030 "Der ausgew�hlte Server befindet sich in der Wartung. Bitte versuche sp�ter erneut dich einzulogen."
	#define STRERR_S_ATUMLAUNCHER_0031 "Dieses System besitzt zu wenig Speicher oder Ressourcen."
	#define STRERR_S_ATUMLAUNCHER_0032 "Die .exe Datei ist ung�ltig."
	#define STRERR_S_ATUMLAUNCHER_0033 "Datei kann nicht gefunden werden."
	#define STRERR_S_ATUMLAUNCHER_0034 "Pfad kann nicht gefunden werden."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �� ���� ����� ���� ���� ���� ��, ���� ��� ���� ������ ������.\n\n�� ���� ������� ����� ������."		// 2012-07-11 by hskim, ������ ��


	#define STRMSG_S_050506		"\'%s\''s Account ist momentan geblockt.\n	Grund: %s\n	Dauer: %s~%s\n\nBesuche http://support.airrivals.de/ f�r weitere Informationen."
	#define STRMSG_S_050930		"Bitte lade das Spiel erneut herunter.\nURL: %s\nNeueste Version:"
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
	#define STRMSG_S_SCADMINTOOL_0017 "\'Spielzeit \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', gesamt \' + dbo.atum_GetHMSFromS(l.GesamtSpielZeit)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', Spielzeit: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Existiert nicht)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Account geblockt"
	#define STRMSG_S_SCADMINTOOL_0030 "Chatten verboten"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s Server"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s Server,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Account beschlagnahmt"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Willst du diesen Account entsperren?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dSekunde)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d Siege %d Niederlagen"
	#define STRMSG_S_SCADMINTOOL_0042 "Bist du dir sicher, dass du den Account trennen und sperren m�chtest?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s Item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Nachricht : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Zahl der Benutzer : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Empfangene Nachricht : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Zahl der Benutzer : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Fieldserver Status : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Verbindung zum Server wurde verloren\n Socket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Kann die entsprechenden Account-Informationen nicht laden."
	#define STRERR_S_SCADMINTOOL_0001 "Ver�nderung der Account-Informationen fehlgeschlagen."
	#define STRERR_S_SCADMINTOOL_0002 "Gib dein Passwort ein"
	#define STRERR_S_SCADMINTOOL_0003 "Passwort-Best�tigung fehlgeschlagen"
	#define STRERR_S_SCADMINTOOL_0004 "Gib deinen Loginnamen ein"
	#define STRERR_S_SCADMINTOOL_0005 "Login-Server l�uft nicht."
	#define STRERR_S_SCADMINTOOL_0006 "Kann nicht mit dem Login-Server verbinden!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "FEHLER: Gew�hltes Protokoll existiert nicht."
	#define STRERR_S_SCADMINTOOL_0009 "Gib deinen Benutzernamen ein"
	#define STRERR_S_SCADMINTOOL_0010 "Gib einen Grund ein"
	#define STRERR_S_SCADMINTOOL_0011 "Erfahrungspunkte Einrichtungs Fehler : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Maximale Log-Anzahl erreicht.\r\n\r\nBitte �ndere die Zahl der maximalen Logs in den Sucheinstellungen."
	#define STRERR_S_SCADMINTOOL_0013 "Kann nicht mit der Datenbank verbinden."
	#define STRERR_S_SCADMINTOOL_0014 "Nicht verbunden"
	#define STRERR_S_SCADMINTOOL_0015 "Verbunden"
	#define STRERR_S_SCADMINTOOL_0016 "Updating"
	#define STRERR_S_SCADMINTOOL_0017 "Eingeloggt"
	#define STRERR_S_SCADMINTOOL_0018 "Charakter Auswahl"
	#define STRERR_S_SCADMINTOOL_0019 "Spiel aktiv"
	#define STRERR_S_SCADMINTOOL_0020 "Unbekannt"
	#define STRERR_S_SCADMINTOOL_0021 "Datenbank %s(%s:%d) kann nicht verbunden werden."
	#define STRERR_S_SCADMINTOOL_0022 "Fehler beim Hinzuf�gen des Items"
	#define STRERR_S_SCADMINTOOL_0023 "Fehler beim Finden des gesperrten Accounts."
	#define STRERR_S_SCADMINTOOL_0024 "Zun�chst, logge dich aus und sperre den Account, um ihn zum �ndern."
	#define STRERR_S_SCADMINTOOL_0025 "SPI (Geld) kann nicht hinzugef�gt werden."
	#define STRERR_S_SCADMINTOOL_0026 "Ausgew�hltes Item existiert bereits, also ver�ndere die Menge."
	#define STRERR_S_SCADMINTOOL_0027 "Fehler beim finden des Items"
	#define STRERR_S_SCADMINTOOL_0028 "SPI (Geld) des Charakters kann nicht gel�scht werden."
	#define STRERR_S_SCADMINTOOL_0029 "Willst du dieses Item l�schen?"
	#define STRERR_S_SCADMINTOOL_0030 "L�schen des Items fehlgeschlagen."
	#define STRERR_S_SCADMINTOOL_0031 "�ndern des Items fehlgeschlagen."
	#define STRERR_S_SCADMINTOOL_0032 "Gib den Account ein"
	#define STRERR_S_SCADMINTOOL_0033 "Account existiert nicht. (Account ist m�glicherweise gesperrt)"
	#define STRERR_S_SCADMINTOOL_0034 "Account oder Charakter existiert nicht."
	#define STRERR_S_SCADMINTOOL_0035 "Fehler bei der Suche der Charakter Informationen."
	#define STRERR_S_SCADMINTOOL_0036 "Gew�hlter Charakter existiert nicht"
	#define STRERR_S_SCADMINTOOL_0037 "Fehler beim Charakterupdate."
	#define STRERR_S_SCADMINTOOL_0038 "Charakterinformationen wurden erfolgreich aktualtisiert."
	#define STRERR_S_SCADMINTOOL_0039 "W�hle ein Item."
	#define STRERR_S_SCADMINTOOL_0040 "W�hle die Anzahl an Items."
	#define STRERR_S_SCADMINTOOL_0041 "Ausgew�hltes Item kann mit weniger als 5 St�ck erstellt werden."
	#define STRERR_S_SCADMINTOOL_0042 "Gib die Nachricht ein."
	#define STRERR_S_SCADMINTOOL_0043 "Notiz kann nicht gesendet werden."
	#define STRERR_S_SCADMINTOOL_0044 "%s: Serverstatus (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server wird nicht ausgef�hrt."
	#define STRERR_S_SCADMINTOOL_0046 "Fieldserver existiert nicht."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServerstatus : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, �� - ���� �� �� ��� ���� MSG
#define STRERR_S_SCADMINTOOL_0048 "Dieser Itemslot ist auf deiner P.E.D. angelegt. Du kannst den Slot mit dem Befehl \socket entfernen."
#define STRERR_S_SCADMINTOOL_0049 "Das Speichern der �nderung der P.E.D. ist fehlgeschlagen (die �nderung wurde aber durchgef�hrt)."
#define STRERR_S_SCADMINTOOL_0050 "Das Laden der P.E.D.-Informationen ist fehlgeschlagen."
#define STRERR_S_SCADMINTOOL_0051 "Der ausger�stete Itemslot konnte nicht gel�scht werden."
#define STRERR_S_SCADMINTOOL_0052 "Die Anwendung des versteckten Bonus f�r die ausger�steten Items ist fehlgeschlagen."
#define STRERR_S_SCADMINTOOL_0053 "Die �nderung des P.E.D.-Itemslots ist fehlgeschlagen."
#define STRERR_S_SCADMINTOOL_0054 "Die Informationen der P.E.D. konnten nicht aktualisiert werden."
#define STRERR_S_SCADMINTOOL_0055 "Das Laden der Informationen �ber das P.E.D.-Level ist fehlgeschlagen."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ������á, �������۰��
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ������á, �������۰��. End



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
	#define STRMSG_S_SCAT_COLNAME_0021 "Anlegen"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Nicht angelegt"
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
	#define STRMSG_S_SCAT_COLNAME_0053 "Automatischer Typ (1-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Valkan-Typ (1-1-Typ)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Dualist-Typ (1-1-Typ)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Kanonen-Typ (1-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Gewehr-Typ (1-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Gatling-Typ (1-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Raketenwerfer-Typ (1-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Massen Antriebs-Typ (1-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Raketen-Typ (2-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Lenkwaffen-Typ (2-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0063 "B�ndel-Typ (2-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Minen-Typ (2-1-Typ)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Schild-Typ (2-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Dummy-Typ (2-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Pixer-Typ (2-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0068 "K�der-Typ (2-2Typ)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Verteidigungs-Typ"
	#define STRMSG_S_SCAT_COLNAME_0070 "Support Ausr�stungs-Typ"
	#define STRMSG_S_SCAT_COLNAME_0071 "Energie-Typ"
	#define STRMSG_S_SCAT_COLNAME_0072 "Metall-Typ"
	#define STRMSG_S_SCAT_COLNAME_0073 "Karten-Typ"
	#define STRMSG_S_SCAT_COLNAME_0074 "Upgrade-Typ"
	#define STRMSG_S_SCAT_COLNAME_0075 "Panzer-Typ"
	#define STRMSG_S_SCAT_COLNAME_0076 "Kugel-Typ"
	#define STRMSG_S_SCAT_COLNAME_0077 "F�r Mission"
	#define STRMSG_S_SCAT_COLNAME_0078 "Radar-Typ"
	#define STRMSG_S_SCAT_COLNAME_0079 "Computer-Typ"
	#define STRMSG_S_SCAT_COLNAME_0080 "Gl�cksspielkarten-Typ"
	#define STRMSG_S_SCAT_COLNAME_0081 "Upgrade-Zerst�rungs-Verhinderungs-Karte"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Blaster-Typ"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail Gun-Typ"				// 2005-08-02 by cmkwon
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
	#define STRMSG_S_SCAT_COLNAME_0094 "Administrator"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '��, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Kann nicht mit dem LogServer verbinden[%15s:%4d] Neue Verbindung\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Eingeloggt beim Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Verbindung zum Log Server[%15s:%4d]wurde verloren. Versuche Neuverbindung.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Kann nicht mit dem Login-Server verbinden[%15s:%4d] Neuverbindung\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Eingeloggt beim Login-Server. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) erhalten von %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unbekannter Fehler@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Verbindung zum Login-Server[%15s:%4d] wurde verloren. Versuche neu zu verbinden.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Kann nicht mit dem	IMServer[%15s:%4d] verbinden Neue Verbindung\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Eingeloggt beim IM Server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Verbindung mit dem IM[%15s:%4d] Server wurde verloren. Versuche neu zu verbinden.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) erhalten von %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unbekannter Fehler@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Keine solche DB-Abfrage in den Fieldserver-Abfragen! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Ausgew�hltes Item existiert nicht."
	#define STRMSG_S_F2DBQUERY_0002 "'%s'hat sich um Begleitung beworben, und versprach ein Item"
	#define STRMSG_S_F2DBQUERY_0003 "ist erteilt. Dr�ck F5 um dein Inventar zu �berpr�fen"
	#define STRMSG_S_F2DBQUERY_0004 "Skill %s(%d) wurde hinzugef�gt"
	#define STRMSG_S_F2DBQUERY_0005 "Ausgew�hltes Item existiert nicht."
	#define STRMSG_S_F2DBQUERY_0006 "Kauf des Items fehlgeschlagen."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Beginn des Stadtbesetzungskrieges : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Teilnehmende Brigade: GildenUID(%4d) GulidenName(%10s) GuildenMeister(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Stast Besetzungskrieg Monsterexplosion : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Gesamt Schaden ==> Gildenname(%10s) Gesamtschaden(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Stadtbesetzungskrieg : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) �������ð�(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, KartenIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Nach %d Minuten, \"%s\" wird der Stadtbesetzungskrieg starten."
	#define STRMSG_S_F2CITYWAR_0007 "Nach %d Minuten,  \"%s\" wird der Stadtbesetzungskrieg beendet sein."
	#define STRMSG_S_F2CITYWAR_0008 "Monster gerufen f�r Stadtbesetzungskampf(%s) : NPC besetzen."
	#define STRMSG_S_F2CITYWAR_0009 "Monster f�r den Stadtbesetzungskrieg gerufen(%s) : %s besetzende Brigade"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" besetzt \"%s\" momentan."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" Brigade besetzt \"%s\" momentan."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Laden der Mission fehlgeschlagen"
	#define STRMSG_S_F2QUEST_0001 "Mission wurde nicht geladen.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Server zum Testen wurde eingestellt! \r\n\r\nLoadFieldServerDataDebug() muss beendet werden!"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1. Typ"
	#define STRMSG_S_F2NOTIFY_0003 "2. Typ"
	#define STRMSG_S_F2NOTIFY_0004 "Mon 1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Falscher Waffentyp! Bitte starte eine Anfrage an den Administrator!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Angriffswahrscheinlichkeit reduziert um %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s fehlgeschlagen, Wahrscheinlichkeit(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s fehlgeschlagen, Wahrscheinichkeit(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s fehlgeschlagen, Wahrscheinlichkeit(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Schaden reduziert um %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, gibt %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, erh�lt %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), gibt %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, erh�lt %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy fehlgeschlagen: M�glicherweise mangelhaft > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Verbleibender Dummy[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Bullet Information existiert nicht. Bitte starte eine Anfrage an den Administrator."
	#define STRMSG_S_F2NOTIFY_0019 "Informationen �ber das Geschosskaliber existieren nicht. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Dies ist die Information �ber das Geschoss. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Warpen ist w�hrend des Turniers nicht m�glich"
	#define STRMSG_S_F2NOTIFY_0022 "Warpen ist nicht m�glich, wenn du tot bist."
	#define STRMSG_S_F2NOTIFY_0023 "Warpen ist nicht m�glich, wenn du im Formationskampf bist"
	#define STRMSG_S_F2NOTIFY_0024 "Karten-Produktionsfehler! Bitte starte eine Anfrage an den Administrator!"
	#define STRMSG_S_F2NOTIFY_0025 "Karten-Produktionsfehler! Bitte starte eine Anfrage an den Administrator! Bei %d, %d existiert der Warpziel Index nicht!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Warpen ist nicht m�glich, da der Formationskampf nicht beendet ist"
	#define STRMSG_S_F2NOTIFY_0027 "WARP(%04d) Behebung unm�glich von Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Charakter %10s, erh�lt Schaden %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Charakter %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Charakter %10s, erh�lt Schaden %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Character %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Charakter %10s, erh�lt Schaden %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Character %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Monster %3d, f�gt Schaden zu %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Charakter %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Charakter %10s, f�gt Dummy Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Monster %3d, erh�lt Schaden %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> Charakter %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> Charakter %10s, f�gt Dummyschaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> Monster %10s, f�gt Schaden zu %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Stat-Initialisierung war erfolgreich."
	#define STRMSG_S_F2NOTIFY_0042 "Du kannst dies nicht verwenden, wenn du tot bist."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO existiert nicht"
	#define STRMSG_S_F2NOTIFY_0044 "Upgrade \g erfolgreich\g."
	#define STRMSG_S_F2NOTIFY_0045 "Upgrade \r fehlgeschlagen\r."
	#define STRMSG_S_F2NOTIFY_0046 "Geh�rt nicht zur Brigade."
	#define STRMSG_S_F2NOTIFY_0047 "Bereits im Standby-Status f�r die Anfrage."
	#define STRMSG_S_F2NOTIFY_0048 "Bitte versuche es sp�ter erneut."
	#define STRMSG_S_F2NOTIFY_0049 "Du oder die andere Person ist der Brigadef�hrer."
	#define STRMSG_S_F2NOTIFY_0050 "Bereits im Brigadekampf."
	#define STRMSG_S_F2NOTIFY_0051 "Beide Brigadef�hrer sind nicht in der selben Karte."
	#define STRMSG_S_F2NOTIFY_0052 "Nicht alle Formationsmitglieder sind in der selben Karte"
	#define STRMSG_S_F2NOTIFY_0053 "Nicht alle Formationsmitglieder sind in der selben Karte"
	#define STRMSG_S_F2NOTIFY_0054 "Du geh�rst nicht zur Brigade."
	#define STRMSG_S_F2NOTIFY_0055 "Der empfangende Bewerber ist anders."
	#define STRMSG_S_F2NOTIFY_0056 "Du oder die andere Person ist kein Brigadef�hrer."
	#define STRMSG_S_F2NOTIFY_0057 "Zwei Brigadef�hrer sind nicht in der selben Karte."
	#define STRMSG_S_F2NOTIFY_0058 "Du geh�rst nicht zur Brigade."
	#define STRMSG_S_F2NOTIFY_0059 "Der empfangende Bewerber ist unterschiedlich."
	#define STRMSG_S_F2NOTIFY_0060 "Du oder die andere Person ist nicht der Brigadef�hrer."
	#define STRMSG_S_F2NOTIFY_0061 "Erfolgreich in der Verteidigung des Stadtbesetzungs-Kampfes"
	#define STRMSG_S_F2NOTIFY_0062 "Mission Setup Fehler. Bitte starte eine Anfrage an den Administrator."
	#define STRMSG_S_F2NOTIFY_0063 "Ausgew�hltes Item(%s) kann nicht an diesem Ort eingef�gt werden"
	#define STRMSG_S_F2NOTIFY_0064 "Motor kann nicht aufgegeben werden."
	#define STRMSG_S_F2NOTIFY_0065 "Item Bewegung: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Falsche Item Bewegung: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENT(%d) Bearbeitung unm�glich von Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Karten Event Informationen unnormal! Bitte starte eine Anfrage an den Administrator!"
	#define STRMSG_S_F2NOTIFY_0069 "Gew�hltes Warpziel existiert nicht"
	#define STRMSG_S_F2NOTIFY_0070 "Fehler beim Itemkauf. Bitte starte eine Anfrage an den Administrator."
	#define STRMSG_S_F2NOTIFY_0071 "Das Skilllevel, welches du kaufen m�chtest ist geringer als dein jetziges Level."
	#define STRMSG_S_F2NOTIFY_0072 "Item Fehler. Item ben�tigt einen Skill-Einkauf."
	#define STRMSG_S_F2NOTIFY_0073 "Fehler beim Artikelverkauf. Bitte frage einen Administrator."
	#define STRMSG_S_F2NOTIFY_0074 "Fehler beim Itemkauf. Bitte starte eine Anfrage an den Administrator."
	#define STRMSG_S_F2NOTIFY_0075 "\'Credit Item\'wurde gekauft."
	#define STRMSG_S_F2NOTIFY_0076 "Einkaufs Liste : \'%s(%dSt�ck)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Bereits der Partei beigetreten."
	#define STRMSG_S_F2NOTIFY_0078 "Wenn du der Anf�hrer bist kannst du nicht beitreten"
	#define STRMSG_S_F2NOTIFY_0079 "Ein Beitreten ist nicht m�glich solange der Formationskampf im Gang ist."
	#define STRMSG_S_F2NOTIFY_0080 "Das Ansprechen aller Informationen zum Formationspersonal wird nicht unterst�tzt!"
	#define STRMSG_S_F2NOTIFY_0081 "Information zum Kartenevent ist unnormal! Bitte beim Administrator melden!"
	#define STRMSG_S_F2NOTIFY_0082 "Dies ist ein Konto, welches keine Transaktionen durchf�hren kann"
	#define STRMSG_S_F2NOTIFY_0083 "%s Ladekapazit�t ist ausgesch�pft."
	#define STRMSG_S_F2NOTIFY_0084 "M�gliche Bewegungskoordination: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Nutzer:"
	#define STRMSG_S_F2NOTIFY_0086 "Ein Maximum von 20 Personen kann gesehen werden."
	#define STRMSG_S_F2NOTIFY_0087 "Der entsprechende Nutzer (%s) existiert nicht"
	#define STRMSG_S_F2NOTIFY_0088 "Geh�rt nicht zur Partei"
	#define STRMSG_S_F2NOTIFY_0089 "Jetztzeit: %d:%d, Atum-Zeit: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Ver�nderte Zeit: %d:%d, Atum-Zeit: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Nicht an dem NPC Server angeschlossen"
	#define STRMSG_S_F2NOTIFY_0092 "Entsprechender Artikel (%d) existiert nicht"
	#define STRMSG_S_F2NOTIFY_0093 "Begrenzt auf 10 St�ck, falls es kein z�hlbarer Artikel ist"
	#define STRMSG_S_F2NOTIFY_0094 "Gesamte Anzahl der angeschlossenen Personen der \'%s\' Karte: %d Personen"
	#define STRMSG_S_F2NOTIFY_0095 "Gleichzeitige Verbindungen der Karte %s %s:  %d Personen - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Karte %s %s simultane Verbindung: %d Personen - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Kanal der jetzigen Karte: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Information zu den Geschossen existiert nicht. Bitte beim Administrator erfragen."
	#define STRMSG_S_F2NOTIFY_0099 "Information zum Geschosskaliber existiert nicht. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Information zu den Geschossen existiert nicht. Bitte beim Administrator erfragen."
	#define STRMSG_S_F2NOTIFY_0101 "Information zu den Geschosskaliber existiert nicht. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Gew�hlter User(%s) existiert nicht"
	#define STRMSG_S_F2NOTIFY_0103 "Entsprechender Nutzer (%s) ist tot"
	#define STRMSG_S_F2NOTIFY_0104 "Entsprechender Nutzer (%s) existiert nicht"
	#define STRMSG_S_F2NOTIFY_0105 "Als Standardkonto festlegen"
	#define STRMSG_S_F2NOTIFY_0106 "Standardkonto wurde aufgehoben"
	#define STRMSG_S_F2NOTIFY_0107 "Unbesiegbarkeit wurde angeschaltet."
	#define STRMSG_S_F2NOTIFY_0108 "Unbesiegbarkeit wurde ausgeschaltet."
	#define STRMSG_S_F2NOTIFY_0109 "Der Waffenschaden wird um %5.0f%% ver�ndert"
	#define STRMSG_S_F2NOTIFY_0110 "Wird initiiert wenn der Artikel wiedergeladen wird"
	#define STRMSG_S_F2NOTIFY_0111 "Wird gestartet, wenn das Item neu geladen wird."
	#define STRMSG_S_F2NOTIFY_0112 "Entsprechender Nutzer (%s) existiert nicht"
	#define STRMSG_S_F2NOTIFY_0113 "Unsichtbarkeit wurde deaktiviert."
	#define STRMSG_S_F2NOTIFY_0114 "Unsichtbarkeit wurde aktiviert."
	#define STRMSG_S_F2NOTIFY_0115 "Das %s Event ist nicht im Gang"
	#define STRMSG_S_F2NOTIFY_0116 "Das %s Event hat begonnen (Vergr�sserung:%4.2f, Event Zeit:%3d minutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Lege ein Standard-Premium-Konto fest"
	#define STRMSG_S_F2NOTIFY_0118 "Das Festlegen als Premiumkonto ist missgl�ckt"
	#define STRMSG_S_F2NOTIFY_0119 "Als Super-Premium-Konto festlegen"
	#define STRMSG_S_F2NOTIFY_0120 "Dies ist nicht die Karte f�r einen Stadtbesetzungskampf."
	#define STRMSG_S_F2NOTIFY_0121 "Stadtbesetzungskampf kann nicht gestartet werden"
	#define STRMSG_S_F2NOTIFY_0122 "Stadtbesetzungskampf kann nicht beendet werden"
	#define STRMSG_S_F2NOTIFY_0123 "Verdeckter Modus wurde initialisiert"
	#define STRMSG_S_F2NOTIFY_0124 "Im verdeckten Status"
	#define STRMSG_S_F2NOTIFY_0125 "Karte ist nicht best�tigt."
	#define STRMSG_S_F2NOTIFY_0126 "Happy Hour Event [Zeit: %4d Minuten)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Hour Event beendet"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> Von Monster %3d, erhaltener Schaden %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "1Typ -> Von Monster %3d, erhaltener Schaden %5.2f(Dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Eingeloggt mit \r %s\r Befugnis"
	#define STRMSG_S_F2NOTIFY_0131 "Nicht die Vervollst�ndigungsroutine bearbeiten %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Partei Personal Entfernung fehlgeschlagen! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Gestoppt!"
	#define STRMSG_S_F2NOTIFY_0136 "FATALER FEHLER: Bitte starte eine Anfrage an den Administrator!  Shop Variable Zuteilungsfehler."
	#define STRMSG_S_F2NOTIFY_0137 "%s ist gel�scht."
	#define STRMSG_S_F2NOTIFY_0138 "Der Channel, in dem du momentan bist, ist deaktiviert, daher sind Monster und andere Funktionen nicht verf�gbar."
	#define STRMSG_S_F2NOTIFY_0139 "Angehalten. Bitte verwende einen anderen Channel."
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Timer-Bewegung %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Automatische HP Wiederherstellung angehalten"
	#define STRMSG_S_F2NOTIFY_0143 "Automatische HP Wiederherstellung wurde angehalten, da dies kein Ort f�r eine Landung ist"
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f Notfallwiederherstellung"
	#define STRMSG_S_F2NOTIFY_0145 "Allm�hliche HP UP angehalten(verbleibende Zeit: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Allm�hliche DP UP angehalten (verbleibende Zeit: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Allm�hliche EP UP angehalten/verbleibende Zeit: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s Event wurde abgeschlossen."
	#define STRMSG_S_F2NOTIFY_0149 "%s Event im Verlauf (Vergr��erung %4.2f, verbleibend:%3d Minuten)"
	#define STRMSG_S_F2NOTIFY_0150 "Befehl wurde nicht ausgef�hrt"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Fehler beim Teilen der Erfahrungspunkte.(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Fehler keine g�ltige Spielstart-Meldung ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Fehler keine g�ltige Spielstart-Meldung ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) Behebung unm�glich als ein QuestProzessErgebnis(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Karten-Event-Information unnormal! Bitte frage deinen Administrator! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) Behebung um�glich bei T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Karten Event Information unnormal! Bitte kontaktiere den Administrator! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP Behebung unm�glich um T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) Behebung unm�glich (party leader) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) Behebung unm�glich bei Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) Behebung unm�glich bei Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP Behebung unm�glich bei T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Warpen Fehlgeschlagen: %s -> Entfernung: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) Behebung unm�glich bei Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> Klicke den �berlagerten OK-Knopf!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Quest wurde nicht geladen.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) Behebung unm�glich von HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) Behebung unm�glich von HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATALER FEHLER: Diese Nachricht sollte nicht an den Fieldserver geschickt werden, zu dem die Mitglieder nicht geh�ren. Probiere es aus\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) Behebung unm�glich bei T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) Behebung unm�glich bei T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Erfahrungspunkte"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Wiederherstellung der Erfahrungspunkte"
	#define STRMSG_S_F2EVENTTYPE_0003 "Item drop"
	#define STRMSG_S_F2EVENTTYPE_0004 "Seltener Item drop"
	#define STRMSG_S_F2EVENTTYPE_0005 "Unbekanntes Event"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Eingloggt auf dem Login-Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Verbindung zum Login-Server[%15s:%4d] wurde verloren. Versuche Neuverbindung.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' existiert bereits"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' ist bereits in einer Brigade."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' ist bereits der Name einer bestehenden Brigade"
	#define STRMSG_S_I2NOTIFY_0003 "Laden der Brigade fehlgeschlagen - Bitte starte eine Anfrage an den Administrator!"
	#define STRMSG_S_I2NOTIFY_0004 "Dein Freund '%s' hat sich eingeloggt"
	#define STRMSG_S_I2NOTIFY_0005 "Pr�fe vorherige Formation"
	#define STRMSG_S_I2NOTIFY_0006 "Vorherige Formation existiert nicht"
	#define STRMSG_S_I2NOTIFY_0007 "Kehre in die Formation zur�ck"
	#define STRMSG_S_I2NOTIFY_0008 "Du bist momentan in einer Formation"
	#define STRMSG_S_I2NOTIFY_0009 "Fataler Fehler: Fataler Gruppen-Fehler! bei T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Status des Formationspersonals ist ung�ltig"
	#define STRMSG_S_I2NOTIFY_0011 "Formationspersonal ist bereits der Brigade beigetreten"
	#define STRMSG_S_I2NOTIFY_0012 "Diese Person ist bereits der Brigade beigetreten"
	#define STRMSG_S_I2NOTIFY_0013 "Du kannst dich nicht selbst einladen"
	#define STRMSG_S_I2NOTIFY_0014 "Du befindest sich in einem Status in dem du keiner Brigade beitreten darfst"
	#define STRMSG_S_I2NOTIFY_0015 "Du hast die Zahl des Brigadepersonals �berschritten, die beitreten kann"
	#define STRMSG_S_I2NOTIFY_0016 "Du befindest dich in einem Status, in dem du der Brigade nicht beitreten darfst"
	#define STRMSG_S_I2NOTIFY_0017 "Der Brigadef�hrer kann sich nicht von der Brigade zur�ckziehen"
	#define STRMSG_S_I2NOTIFY_0018 "Du kannst dich nicht aus der Brigade zur�ckziehen, w�hrend du in einem Brigadekampf bist"
	#define STRMSG_S_I2NOTIFY_0019 "Du kannst Brigadepersonal nicht w�hrend eines Brigadekampfes aussto�en"
	#define STRMSG_S_I2NOTIFY_0020 "Brigadef�hrer kann nicht ausgesto�en werden"
	#define STRMSG_S_I2NOTIFY_0021 "Kann die Brigade nicht w�hrend eines Brigadekampfes trennen"
	#define STRMSG_S_I2NOTIFY_0022 "Kann nicht zum selben Namen wechseln"
	#define STRMSG_S_I2NOTIFY_0023 "Du befindest dich in einem Status, in dem der Brigadenname nicht ge�ndert werden kann"
	#define STRMSG_S_I2NOTIFY_0024 "Du befindest dich in einem Status, in dem das Brigadezeichen nicht ge�ndert werden kann"
	#define STRMSG_S_I2NOTIFY_0025 "Du befindest dich in einem Status, in dem der Rang nicht ge�ndert werden kann"
	#define STRMSG_S_I2NOTIFY_0026 "Rang hat sich �berschnitten"
	#define STRMSG_S_I2NOTIFY_0027 "Rang�nderung zum Regimentsf�hrer ist nicht m�glich."
	#define STRMSG_S_I2NOTIFY_0028 "Ver�nderung im Regimentsf�hrerrang ist nicht m�glich."
	#define STRMSG_S_I2NOTIFY_0029 "Zahl der gesamten Benutzer: %d Personen (Ausgabe an %d Personen)"
	#define STRMSG_S_I2NOTIFY_0030 "Zur Administrator-Nachrichtenliste hinzugef�gt"
	#define STRMSG_S_I2NOTIFY_0031 "Gel�scht von der Administrator-Nachrichtenliste"
	#define STRMSG_S_I2NOTIFY_0032 "Server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Server Gruppe \'%s\' gesamte Zahl der eingeloggten Personen: %dPersonen"
	#define STRMSG_S_I2NOTIFY_0034 "Willst du wirklich den Server schlie�en(%s)? ServerID: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' spielt das Spiel nicht"
	#define STRMSG_S_I2NOTIFY_0036 "Zahl der gesamten Benutzer: %d Personen (Ausgabe an %d Personen)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Ausgew�hltes Regiment existiert nicht"
	#define STRMSG_S_I2NOTIFY_0039 "Fl�sterblock wurde ausgeschaltet"
	#define STRMSG_S_I2NOTIFY_0040 "Fl�stern wurde geblockt"
	#define STRMSG_S_I2NOTIFY_0041 "Nicht der Brigade beigetreten"
	#define STRMSG_S_I2NOTIFY_0042 "Brigade (%d) ist nicht verf�gbar"
	#define STRMSG_S_I2NOTIFY_0043 "Gew�hltes Wetter (%s) existiert nicht"
	#define STRMSG_S_I2NOTIFY_0044 "Fieldserver ist ung�ltig"
	#define STRMSG_S_I2NOTIFY_0045 "Gew�hlte Karte (%s) existiert nicht"
	#define STRMSG_S_I2NOTIFY_0046 "Du darfst f�r %d Minuten nicht chatten!"
	#define STRMSG_S_I2NOTIFY_0047 "Chat-Sperre gesetzt : '%10s', %3d Min"
	#define STRMSG_S_I2NOTIFY_0048 "Chat-Sperrzustand wurde beendet"
	#define STRMSG_S_I2NOTIFY_0049 "Chat-Sperre beendet: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(Account: %s, Karte: %d(%d), Level: %d) SPIELT"
	#define STRMSG_S_I2NOTIFY_0051 "Du kannst dich selbst nicht rufen."
	#define STRMSG_S_I2NOTIFY_0052 "Gew�hlte Brigade existiert nicht."

	#define STRMSG_S_IMSERVER_050607_0001	"Gew�hlte Karte existiert nicht."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Eingeloggt auf dem Fieldserver.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Verbindung zum Fieldserver[%15s:%4d] wurde verloren. versuche Neuverbindung.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Kollisions�berpr�fung zwischen Monster und Objekt existiert nicht\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Stadt Besetzungskampf Monster(%10s) gerufen\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Eingeloggt mit dem %s Account(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Erfolg"
	#define STRMSG_S_P2PRENOTIFY_0002 "Fehler"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]Fehler beim Zugf�gen von Account Informationen, AccountName(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Hallo. Dies ist der AirRivals Administrator."
	#define STRMSG_SCAT_051115_0002		"Wir werden unsere regelm��igen Wartungsarbeiten in 10 Minuten durchf�hren."
	#define STRMSG_SCAT_051115_0003		"Bitte begib dich an einen sicheren Ort und verlasse das Spiel."
	#define STRMSG_SCAT_051115_0004		"Als erstes wird der NPC Server beendet werden."
	#define STRMSG_SCAT_051115_0005		"Die regelm��igen Wartungsarbeiten von AirRivals beginnen."
	#define STRMSG_SCAT_051115_0006		"Genie�e deinen Tag mit AirRivals."
	#define STRMSG_SCAT_051115_0007		"Es wird in 5 Minuten einen Server Checkup geben." // 5     .
	#define STRMSG_SCAT_051115_0008		"Server wird f�r 60 Minuten offline sein."	//  60   
	#define STRMSG_SCAT_051115_0009		"Serverwartung beginnt in 30 Minuten."
	#define STRMSG_SCAT_051115_0010		"Serverwartung beginnt in 15 Minuten."
	#define STRMSG_SCAT_051115_0011		"Serverwartung beginnt in 10 Minuten."
	#define STRMSG_SCAT_051115_0012		"Serverwartung beginnt in 5 Minuten."
	#define STRMSG_SCAT_051115_0013		"Serverwartung wird jeden Moment beginnen."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Unsichtbar-Modus: Benutzer k�nnen dich nicht sehen und Waffen k�nnen nicht verwendet werden."
	#define STRMSG_060509_0001			"Unbesiegbar-Status: Du erh�ltst keinen Schaden."
	#define STRMSG_060509_0002			"Verdeckt-Modus: Monster attackieren dich nicht."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Deine Anfrage wurde an den GM gesendet. Einer unserer GMs wird dich so schnell wie m�glich kontaktieren."
	#define	STRMSG_060526_0001			"Automatisches Update war nicht m�glich.\r\n\r\nBitte lade den Patch von der Homepage(%s) herunter und verbinde erneut.\r\n\r\n	Fehler: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Diese ID wurde nicht registriert oder die ID und das Passwort stimmen nicht �berein."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Der Spielserver ist momentan wegen Wartungsarbeiten offline. Bitte gehe auf die offizielle Homepage (www.airrivals.de) f�r weitere Informationen."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Die Client-Version ist nicht g�ltig.\r\n"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Du wurdest von %s get�tet."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree Server DB(atum2_db_20) Initialisation muss, nach der Schlie�ung des Jamboree Servers, ausgef�hrt werden."
	#define STRMSG_070410_0001   	"Willst du wirklich die Jamboree Server DB(atum2_db_20)- [Validation number:%d]"
	#define STRMSG_070410_0002   	"Jamboree Server DB(atum2_db_20) ist initialisiert."
	#define STRMSG_070410_0003   	"Jamboree Server DB(atum2_db_20) Initialisation fehlgeschlagen!"
	#define STRMSG_070410_0004   	"'%s' Daten-Duplikation zum Jamboree Server  DB(atum2_db_20) abgeschlossen."
	#define STRMSG_070410_0005   	"'%s' Daten-Duplikations zum Jamboree Server       DB(atum2_db_20) fehlgeschlagen - Charakter existiert nicht!"
	#define STRMSG_070410_0006   	"'%s' Daten-Duplikation zur Jamboree Server DB(atum2_db_20) fehlgeschlagen - Gew�hlter Account Charakter existiert!"
	#define STRMSG_070410_0007   	"'%s' Daten-Duplikation zum Jamboree Server DB(atum2_db_20) fehlgeschlagen - DB Additionsfehler!"
	#define STRMSG_070410_0008   	"'%s' Daten-Duplikation zum Jamboree Server DB(atum2_db_20) fehlgeschlagen - Unbekannter (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (mittel)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (hoch)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (niedrig-breit)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (mittel-breit)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (hoch-breit)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (mittel)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (hoch)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (mittel)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (hoch)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (niedrig-breit)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (mittel-breit)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (hoch-breit)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (mittel)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (hoch)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Kann nicht starten, da du dich im verdeckten Mode befindest."
#define STRMSG_070615_0001		"Kann das Zuschauen nicht starten."
#define STRMSG_070620_0000	"Benutzer kann das Zuschauen nicht starten."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"KriegsPunkt"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Du spielst das Spiel seit %d Stunde(n)."
#define STRMSG_070628_0001				"Du spielst das Spiel seit %d Stunde(n). Bitte unternimm die notwendigen Schritte um eine Pause zu bekommen."
#define STRMSG_070628_0002				"Du hast zu lange gespielt. Es wird gesundeheitsgef�hrlich. Bitte nimm R�cksicht auf deine Gesundheit und beende das Spiel. Es dient deinem eigenen Nutzen."
#define STRMSG_070628_0003				"Das Spiel zu spielen wird kritisch f�r deine Gesundheit. Achte auf deine Gesundheit und schlie�e das Spiel jetzt. Wenn nicht, erreichen deine deine Spieleinnahmen 0%. Deine Spieleinnahmen werden 5 Stunden, nachdem das Spiel geschlossen wurde, wieder normal sein."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' ist nicht verboten in der Eingangszone."
#define STRMSG_070711_0001 "\'%s\' ist verboten in der Eingangszone (Zeit �brig: %d Minuten)"
#define STRMSG_070711_0002 "Dir ist es verboten, die Eingangszone f�r %d Minuten zu betreten!"
#define STRMSG_070711_0003 "Dein Verbot f�r die Eingangszone ist beendet."
#define STRMSG_070711_0004 "Verwendung der Arena ist f�r Spieler \'%s\' verboten."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (niedrig-weit)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (mittel-breit)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (hoch-breit)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Diese Befehl kann nur verwendet werden, nachdem eine Nation ausgew�hlt wurde."
#define STRMSG_070830_0002                                   "Konferenzraum-Karte (%d) der ausgew�hlten Nation ist nicht verf�gar."
#define STRMSG_070830_0003                                   "Anzahl Benutzer, die den Konferenzraum betreten k�nnen : %d"
#define STRMSG_070830_0004                                   "'%s' steht bereits auf der Eintrittsliste."
#define STRMSG_070830_0005                                   "'%s' besitzt keine Eintrittserlaubnis."
#define STRMSG_070830_0006                                   "'%s' ist kein g�ltiger Charakter."
#define STRMSG_070830_0007                                 "'%s' kann nicht auf die Konferenzraum-Eintrittsliste gesetzt werden.(Maximal %d Personen)"
#define STRMSG_070830_0008                                   "'%s' hat die Erlaubnis bekommen, den Konferenzraum zu betreten."
#define STRMSG_070830_0009                                   "Erlaubnis zum Betreten des Konferenzraums wurde erteilt."
#define STRMSG_070830_0010                                   "Erlaubnis zum Betreten des Konferenzraums wurde entzogen."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s hat dir %s als Geschenk geschickt."
#define STRMSG_071115_0002									"Aktuelle Liste : \'%s(%d St�ck)\'"
#define STRMSG_071115_0003									"\\y %s schickt %s ein Geschenk. Das Geschenk ist %s. Bitte schau im Lagerhaus nach."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Appeal-System ist nich aktiv. Bitte kontaktiere uns unter http://support.airrivals.de/."
#define STRMSG_071120_0002									"Appeal-System ist aktiviert."
#define STRMSG_071120_0003									"Appeal System ist nicht eingeschlossen."
#define STRMSG_071120_0004									"Appeal-System wird von %s bis %s gestartet."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s hat dir %s(%d) als ein Geschenk geschickt. Bitte kontrolliere dein Lager."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Aufl�sungseinstellungen sind ung�ltig. Bitte �berpr�fe sie noch einmal."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'Fehler in %s' Einstellungsblock. Fehlercode (%d)"
#define STRMSG_080201_0002									"'%s' Account wurde gesperrt. [Sperre endet am: %s]"
#define STRMSG_080201_0003									"'%s' Account ist nicht in Sperrliste. Errorcode(%d)"
#define STRMSG_080201_0004									"'Beim sperren von Account %s ist ein Fehler aufgetreten' Errorcode(%d)"
#define STRMSG_080201_0005									"'%s' Account wurde von Sperrliste entfernt." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Fehler] WndProc(), Kann nicht mit dem Arena Server verbinden[%15s:%4d] erneut verbinden\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Zum Arena-Server verbinden.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Verbindung zum Arena Server [%15s:%4d] wurde geschlossen. Versuche erneut zu verbinden.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) erhalten von %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unbekannter Fehler@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Dem Arena-Warteraum Nr. \\y%d wurde das Event-Attribut gegeben.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "\\yArena Warteraum %d wurde das Event-Attribut weggenommen.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Fehler beim vergeben des Arena-Attributs.\r\n"
#define STRMSG_080428_0001					"%s wurde besiegt."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ������ �� DB�� �(�� �� ���� ���� �� ������) - 
#define STRMSG_080430_0001					"Auf dem ausgew�hlten Server k�nnen keine neuen Charakter erstellt werden."

// 2008-06-13 by dhjin, EP3 ���� �� ���� - 
#define STRMSG_080613_0001					"Die Aufnahme in die Brigade %s wurde abgelehnt."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] Es gibt keine (QP_xxx) DB Abfragefunktion!! Abfrage Typ (%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRMSG_081230_0001					"\\y%s wird f�r %d Minuten vom Chat ausgeschlossen.\\y"
#define STRMSG_081230_0002					"\\yDer Anf�hrer hat dich f�r %d Minuten vom Chat ausgeschlossen.\\y"
#define STRMSG_081230_0003					"\\yDer Ausschluss aus dem Chat wurde aufgehoben.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D �� ����� ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - ������� ��, STRMSG_090831_0001�� �������� �
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
/*#define STRMSG_090831_0002					"Hackshield installieren"*/
#define STRMSG_090831_0002					"nProtect installieren" // 2015-03-11 by shchoi Gameforge4D nProtect ����â ����
#define STRMSG_090831_0003					"Abbrechen"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - 
#define STRMSG_090902_0001					"http://de.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �� �(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (mittel)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (hoch)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (mittel)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (hoch)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (niedrig)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (mittel)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (hoch)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ���� ������ �� ��� ��
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Nicht-registrierter Server (es k�nnte ein illegaler Privatserver sein.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"W�hrend der Verbindung mit Datenbank ist ein Fehler aufgetreten."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Die Best�tigung war erfolgreich"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Server-IP registriert, aber weiterf�hrende Best�tigung wurde verweigert."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Der Befehl, Windows-Server herunterzufahren, wurde gesendet."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ���� �����  ��

// 1�� 

#define STRMSG_120330_0001					"%s aktiviert das Warp-Portal zum Verborgenen Ort am Aschepfad."
#define STRMSG_120330_0002					"%s aktiviert eine 100%%%%-Steigerung der Erfahrungspunkte (Happy-Hour-Event f�r 1 Stunde) am Aschepfad."
#define STRMSG_120330_0003					"%s aktiviert eine 100%%%%-Steigerung der Itemdroprate (Happy-Hour-Event f�r 1 Stunde) am Aschepfad."
#define STRMSG_120330_0004					"%s aktiviert eine 100%%%%-Steigerung der Itemdroprate / Erfahrungspunkte / SPI (Happy-Hour-Event f�r 1 Stunde) am Aschepfad."
#define STRMSG_120330_0005					"%s aktiviert den Waffen-Shop im Aschepfad."
#define STRMSG_120330_0006					"%s aktiviert den Hyper-Karten-Shop im Aschepfad."
#define STRMSG_120330_0007					"%s aktiviert den Kit-Shop am Aschepfad."
#define STRMSG_120330_0008					"%s ruft ein gigantisches Monster zum Aschepfad."
#define STRMSG_120330_0009					"Der Kristall ist verschwunden."

// 2�� 

#define STRMSG_120508_0001					"%s erh�lt soviel Kriegspunkte, wie %d in der Versunkenen Oase erhalten hat."
#define STRMSG_120508_0002					"%s ruft ein Boss-Monster zur Versunkenen Oase."
#define STRMSG_120508_0003					"%s aktiviert eine 150%%%%-Steigerung der Erfahrungspunkte (Happy-Hour-Event  f�r 1 Stunde) in der Versunkene Oase."
#define STRMSG_120508_0004					"%s aktiviert eine 150%%%%-Steigerung deiner Itemdroprate (Happy-Hour-Event f�r 1 Stunde) in der Versunkene Oase."
#define STRMSG_120508_0005					"%s aktiviert eine 150%%%%-Steigerung der Itemdroprate / Erfahrungspunkte / SPI (Happy-Hour-Event  f�r 1 Stunde) in der Versunkene Oase."
#define STRMSG_120508_0006					"%s erh�lt Altes Eis in der Versunkenen Oase."
#define STRMSG_120508_0007					"%s aktiviert den erweiterten Itemshop in der Versunkenen Oase."
#define STRMSG_120508_0008					"%s aktiviert den Kit-Shop in der Versunkenen Oase."
#define STRMSG_120508_0009					"%s aktiviert den Hyper-Karten-Shop in der Versunkenen Oase."
#define STRMSG_120508_0010					"%s aktiviert den Waffen-Shop in der Versunkenen Oase."
#define STRMSG_120508_0011					"%s aktiviert das Warp-Portal zum Verborgenen Ort in der Versunkenen Oase."

#define STRMSG_120712_0001					"18�� �� ���� ����� ���� ���� ���� ��, %d ��  ������ ���."		// 2012-07-11 by hskim, ������ ��

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ���� ���� %d�� ����."
#define STRMSG_121005_0002					"\\y��� �� PC�� ������ ���."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� ����� ������ - ����� ���� ��������(����)
#define STRMSG_121126_0001					"\\yBefehl: W�hrend laufender Kampfhandlungen sind jegliche Aktionen verboten, die Kristalle direkt betreffen.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX �� ������
#define STRMSG_121129_0001					"\\y� �� �� �� ���� ��.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC �������� ���� �����
#define STRMSG_130121_0001					"\\c Das System wurde von NGC-Truppen eingenommen. Die sofortige Evakuierung hat begonnen."
#define STRMSG_130121_0002					"\\cScouts:\\c Die \\rNGC Steuereinheit\\r wurde verst�rkt."
#define STRMSG_130121_0003					"\\cScouts:\\c Die \\rNGC Steuereinheit\\r wurde zerst�rt."
#define STRMSG_130121_0004					"\\cBefehl:\\c \\rGomoras\\r Schilde sind online. Zerst�re die \\rNGC Steuereinheit\\r, um die Schilde zu deaktivieren."
#define STRMSG_130121_0005					"\\cBefehl:\\c \\rGomoras\\r Schilde sind unten! Jetzt angreifen!"
#define STRMSG_130121_0006					"\\cBefehl:\\c \\rGomora\\r wurde zerst�rt! Alle Mann vorw�rts!"
#define STRMSG_130121_0007					"\\cBefehl:\\c \\rGomora\\r muss zuerst zerst�rt werden."
#define STRMSG_130121_0008					"\\c[%s] wurde durch �berladen der \\c\\rNGC Steuereinheit\\r aktiviert."
#define STRMSG_130121_0009					"\\y[System der NGC-Au�enposten-Basis]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������  - ������ ᱸ ����� ����
#define STRMSG_130422_0001					"\\y%s %d ist in der Arena nicht zugelassen. Das Item wurde an dein Lagerhaus gesandt.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �� ����� - STRMSG �
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gDie Skinkarte ist deiner Skinkarten-Sammlung hinzugef�gt worden.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gDie Skinkarte ist nun [%2d]-mal verwendet worden.\\g"
#define STRMSG_130531_0003					"\\g[%s] Die Skinkarte hat ihre maximale Anwendung erreicht. Du erh�lst [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"Deine Skinkarte ist abgelaufen und entsprechende Werte wurden entfernt. Dein Antrieb ist nicht mehr ausger�stet."
#define STRMSG_130531_0005					"\\yEs ist kein Antrieb ausger�stet. Du wirst zur�ck in die Stadt teleportiert.\\y"
#define STRMSG_130531_0006					"\\gDu kannst die Skinkarte, die im Moment auf deine R�stung angewendet ist, nicht verwenden.\\g"
#define STRMSG_130531_0007					"\\gSkin wurde ver�ndert.\\g"
#define STRMSG_130531_0008					"\\r[%s]-Skinkarte ist abgelaufen.\\r"
#define STRMSG_130531_0009					"\\yR�stungen mit ausger�steten Skinkarten k�nnen nicht verkauft werden.\\y"
#define STRMSG_130531_0010					"\\yGear-Typen stimmen nicht �berein.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ���� ����� �� - STRMSG �
#define STRMSG_130708_0001					"\\cBefehl:\\c  Die NGC-Schilde sind aktiviert worden. Zerst�re die \\rNGC Steuereinheit\\r, um \\rGomoras\\r Schilde auszuschalten."
#define STRMSG_130708_0002					"\\cBefehl:\\c Die Verteidigung der NGC-Milit�rbasis wurde heruntergefahren. Jetzt angreifen!"
#define STRMSG_130708_0003					"\\cScouts:\\c Der \\rNGC Schildgenerator\\r wurde gesichtet."
#define STRMSG_130708_0004					"\\cScouts:\\c Der \\rNGC Schildgenerator\\r wurde zerst�rt."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, � �� �������
#define STRMSG_130726_0001					"Der Charakter ist bereits Angeh�riger dieser Nation."
#define STRMSG_130726_0002					"Der Charakter ist Anf�hrer oder Unteranf�hrer, daher kann die Nation nicht gewechselt werden."
#define STRMSG_130726_0003					"Der Charakter ist in einer Brigade; die Nation kann nicht gewechselt werden."
#define STRMSG_130726_0004					"Es ist kein Charakter vorhanden, der die Nation wechseln k�nnte."
#define STRMSG_130726_0005					"Wechsel der Nation ist fehlgeschlagen [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Wechsel der Nation war erfolgreich [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Dieser Account existiert nicht."
#define STRMSG_130726_0008					"Du bist in deinen Account eingeloggt, die Nation kann nicht gewechselt werden."


// 2013-08-30 by bckim, �����������
#define STRMSG_130830_0001					"\\yFlugprivilegien von %s wurden vom Nationen-Anf�hrer entzogen.\\y"
#define STRMSG_130830_0002					"\\yDie Flugprivilegien wurden vom Nationen-Anf�hrer entzogen.\\y"
#define STRMSG_130830_0003					"\\yFlugprivilegien von %s wurden vom Nationen-Anf�hrer entzogen.\\y"
// End. 2013-08-30 by bckim, �����������

// 2013-08-28 by bckim, �������� ����
#define STRMSG_130828_0001					"\\y[%s war an der Zerst�rung von \\y%s\\y beteiligt.]\\y"
#define STRMSG_130828_0002					"\\y[%s hat den ersten Schlag gegen \\y%s\\y ausgef�hrt.]\\y"
#define STRMSG_130828_0003					"\\y[%s hat im Gesamten die meisten Angriffe gegen \\y%s\\y ausgef�hrt.]\\y"
#define STRMSG_130828_0004					"\\y[%s hat den entscheidenden Schlag gegen \\y%s\\y ausgef�hrt.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n wurde besiegt."
// End. 2013-08-28 by bckim, �������� ����

// 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����
#define STRMSG_130814_0001					"\\y[%s] hat den NGC Strategiepunkte-Krieg gewonnen.\\y"
// end 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����

// 2014-03-12 by bckim, ���ן��(��������)
#define STRMSG_130318_0001					"%s hat den Boss in einem gesperrten Bereich gerufen."
#define STRMSG_130318_0002					"%s hat den Boss in den Ruinen gerufen."
// End. 2014-03-12 by bckim, ���ן��(��������)

// 2014-03-18 by bckim, ���� ON/OFF
#define STRMSG_130318_0003					"\\yDu kannst das Auktionshaus gerade nicht benutzen.\\y"
// End. 2014-03-18 by bckim, ���� ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
