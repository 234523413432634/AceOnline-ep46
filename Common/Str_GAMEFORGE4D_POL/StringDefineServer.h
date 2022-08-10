
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Serwer jest nieaktywny."
	#define STRERR_S_ATUMEXE_0002 "Socket z serwera Login zamkni�ty!"
	#define STRERR_S_ATUMEXE_0003 "Automatyczna aktualizacja nie powiod�a si�.\r\n Prosz� zainstalowa� gr� ponownie.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) zg�oszony przez %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Nieznany b��d: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Po��czenie z serwerem Download nie mo�e zosta� nawi�zane."
	#define STRERR_S_ATUMEXE_0007 "Rozmiar pobieranego pliku jest nieznany."
	#define STRERR_S_ATUMEXE_0008 "Aktualizacja nie mo�e zosta� pobrana"
	#define STRERR_S_ATUMEXE_0009 "System posiada za ma�o pami�ci/zasob�w."
	#define STRERR_S_ATUMEXE_0010 "Plik .exe jest niewa�ny."
	#define STRERR_S_ATUMEXE_0011 "Nie znaleziono pliku."
	#define STRERR_S_ATUMEXE_0012 "Nie znaleziono podanej �cie�ki."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Aktualizacja zako�czona"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Prosz� wybra� inny serwer"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Aktualizacja listy usuni�tych plik�w v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Usu� pliki tymczasowe"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Aktualizacja wiadomo�ci"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Aktualizacja zako�czona (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Wybierz plik wykonawczy"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Wybierz �cie�k� wykonawcz�"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Pobieranie zosta�o przerwane"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Pobieranie przerwane"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Aktualizacja na c%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Nie mo�na utworzy� pliku %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Aktualizacja na v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Odbiera informacj� o pliku %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Zaktualizuj VTC Guard"				// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[B��d] B��d w parametrze liczenia, Liczba(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[B��d] B��d Mutex\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[B��d] Run-time error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[B��d] B��d dekodowania ID, dekodowane ID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Nie mo�na po��czy� si� z serwerem Login."
	#define STRERR_S_ATUMLAUNCHER_0005 "B��d po��czenia z serwerem"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket z serwera Login zamkni�ty!"
	#define STRERR_S_ATUMLAUNCHER_0007 "B��d pliku wskaz�wek!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Automatyczna aktualizacja nie powiod�a si�.\r\n Prosz� zainstalowa� gr� ponownie.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Wszystkie serwery s� obecnie nieaktywne."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s jest sprawdzany..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Wszystkie serwery s� sprawdzane. Spr�buj ponownie p�niej."
	#define STRERR_S_ATUMLAUNCHER_0013 "B��D %s(%#04X) zg�oszony przez %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "B��dne ID lub has�o. Prosz� wprowadzi� poprawne ID i has�o."
	#define STRERR_S_ATUMLAUNCHER_0015 "B��d logowania"
	#define STRERR_S_ATUMLAUNCHER_0016 "Nie podano ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "Podw�jny login"
	#define STRERR_S_ATUMLAUNCHER_0018 "Serwer F nie dzia�a"
	#define STRERR_S_ATUMLAUNCHER_0019 "Serwer I nie dzia�a."
	#define STRERR_S_ATUMLAUNCHER_0020 "Serwis chwilowo zatrzymany. \n\nSpr�buj ponownie p�niej."
	#define STRERR_S_ATUMLAUNCHER_0021 "Zbyt wielu u�ytkownik�w online. \n\nSpr�buj ponownie p�niej."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Twoje konto jest chwilowo zablokowane.\n period : %s\n\nW celu uzyskania dalszych informacji wy�lij e-mail, kt�ry znajdziesz na stronie www.airrivals.pl"
	#define STRERR_S_ATUMLAUNCHER_0023 "Twoja wersja Client nie jest poprawna. \n\nProsz� pobra� gr� ponownie."
	#define STRERR_S_ATUMLAUNCHER_0024 "B��D: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Nie mo�na zalogowa� si� do serwera Download."
	#define STRERR_S_ATUMLAUNCHER_0026 "Rozmiar pobieranego pliku (%s) jest nieznany."
	#define STRERR_S_ATUMLAUNCHER_0027 "Rozmiar pobieranego pliku jest nieznany."
	#define STRERR_S_ATUMLAUNCHER_0028 "Nie mo�na pobra� aktualizacji."
	#define STRERR_S_ATUMLAUNCHER_0029 "Zaktualizowany plik nie istnieje."
	#define STRERR_S_ATUMLAUNCHER_0030 "Wybrany serwer jest konserwowany. Prosz� spr�bowa� zalogowa� si� ponownie p�niej."
	#define STRERR_S_ATUMLAUNCHER_0031 "System posiada za ma�o pami�ci/zasob�w."
	#define STRERR_S_ATUMLAUNCHER_0032 "Plik .exe jest niewa�ny."
	#define STRERR_S_ATUMLAUNCHER_0033 "Nie mo�na znale�� pliku."
	#define STRERR_S_ATUMLAUNCHER_0034 "Nie mo�na znale�� �cie�ki."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �� ���� ����� ���� ���� ���� ��, ���� ��� ���� ������ ������.\n\n�� ���� ������� ����� ������."		// 2012-07-11 by hskim, ������ ��


	#define STRMSG_S_050506		"\'%s\''s Konto jest tymczasowo zablokowane.\n Pow�d: %s\n Czas trwania: %s~%s\n\nW celu uzyskania dalszych informacji wejd� na http://support.airrivals.pl"
	#define STRMSG_S_050930		"Prosz� pobra� gr� ponownie.\nURL: %s\nNajnowsza wersja:"
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
	#define STRMSG_S_SCADMINTOOL_0017 "\'Czas Gry \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', ��czny \' + dbo.atum_GetHMSFromS(l.��czny czas gry)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', Czas Gry: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Nie istnieje)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Konto zablokowane"
	#define STRMSG_S_SCADMINTOOL_0030 "Czat zabroniony"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "Serwer %s - %s"
	#define STRMSG_S_SCADMINTOOL_0035 "Serwer %s - %s,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Konto zablokowane"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Czy chcesz odblokowa� to konto?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dSekunda)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d zwyci�stw %d pora�ek"
	#define STRMSG_S_SCADMINTOOL_0042 "Jeste� pewien, �e chcesz oddzieli� i zablokowa� konto?"
	#define STRMSG_S_SCADMINTOOL_0043 "Przedmiot %s"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Wiadomo�� : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Liczba u�ytkownik�w : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Odebrana wiadomo�� : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Liczba u�ytkownik�w: %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Status serwera Field : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Po��czenie z serwerem zosta�o utracone\n Socket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Nie mo�na za�adowa� odpowiednich informacji o koncie."
	#define STRERR_S_SCADMINTOOL_0001 "Zmiana informacji o koncie nie powiod�a si�."
	#define STRERR_S_SCADMINTOOL_0002 "Wprowad� has�o"
	#define STRERR_S_SCADMINTOOL_0003 "Potwierdzenie has�a nie powiod�o si�"
	#define STRERR_S_SCADMINTOOL_0004 "Wprowad� sw�j login"
	#define STRERR_S_SCADMINTOOL_0005 "Serwer Login nie dzia�a."
	#define STRERR_S_SCADMINTOOL_0006 "Nie mo�na po��czy� si� z serwerem Login!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "B��D: Wybrany protok� nie istnieje."
	#define STRERR_S_SCADMINTOOL_0009 "Wprowad� swoj� nazw� u�ytkownika"
	#define STRERR_S_SCADMINTOOL_0010 "Wprowad� pow�d"
	#define STRERR_S_SCADMINTOOL_0011 "B��d ustawie� punkt�w do�wiadczenia : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Zosta�a osi�gni�ta maksymalna ilo�� log�w.\r\n\r\Prosz� zmieni� ilo�� maksymalnych log�w w ustawieniach wyszukiwania."
	#define STRERR_S_SCADMINTOOL_0013 "Nie mo�na po��czy� si� z baz� danych."
	#define STRERR_S_SCADMINTOOL_0014 "Niepo��czony"
	#define STRERR_S_SCADMINTOOL_0015 "Po��czony"
	#define STRERR_S_SCADMINTOOL_0016 "Aktualizuje"
	#define STRERR_S_SCADMINTOOL_0017 "Zalogowany"
	#define STRERR_S_SCADMINTOOL_0018 "Wyb�r postaci"
	#define STRERR_S_SCADMINTOOL_0019 "Gra aktywna"
	#define STRERR_S_SCADMINTOOL_0020 "Nieznany"
	#define STRERR_S_SCADMINTOOL_0021 "Nie mo�na po��czy� bazy danych %s(%s:%d)."
	#define STRERR_S_SCADMINTOOL_0022 "B��d przy dodawaniu przedmiotu"
	#define STRERR_S_SCADMINTOOL_0023 "B��d przy szukaniu zablokowanego konta."
	#define STRERR_S_SCADMINTOOL_0024 "Aby zmieni� konto, wyloguj si� i zablokuj konto."
	#define STRERR_S_SCADMINTOOL_0025 "Nie mo�na doda� SPI (pieni�dzy)."
	#define STRERR_S_SCADMINTOOL_0026 "Wybrany przedmiot ju� istnieje, wi�c zmie� ilo��."
	#define STRERR_S_SCADMINTOOL_0027 "B��d przy szukaniu przedmiotu"
	#define STRERR_S_SCADMINTOOL_0028 "Nie mo�na usun�� SPI (pieni�dzy) postaci."
	#define STRERR_S_SCADMINTOOL_0029 "Chcesz usun�� ten przedmiot?"
	#define STRERR_S_SCADMINTOOL_0030 "Usuwanie przedmiotu nie powiod�o si�."
	#define STRERR_S_SCADMINTOOL_0031 "Zmiana przedmiotu nie powiod�a si�."
	#define STRERR_S_SCADMINTOOL_0032 "Wprowad� konto"
	#define STRERR_S_SCADMINTOOL_0033 "Konto nie istnieje. (Konto mo�e by� zablokowane)"
	#define STRERR_S_SCADMINTOOL_0034 "Konto lub posta� nie istnieje."
	#define STRERR_S_SCADMINTOOL_0035 "B��d przy wyszukiwaniu informacji o postaci."
	#define STRERR_S_SCADMINTOOL_0036 "Wybrana posta� nie istnieje"
	#define STRERR_S_SCADMINTOOL_0037 "B��d przy aktualizacji postaci."
	#define STRERR_S_SCADMINTOOL_0038 "Informacje o postaci zosta�y zaktualizowane z powodzeniem."
	#define STRERR_S_SCADMINTOOL_0039 "Wybierz przedmiot."
	#define STRERR_S_SCADMINTOOL_0040 "Wybierz ilo�� przedmiot�w."
	#define STRERR_S_SCADMINTOOL_0041 "Wybrany przedmiot mo�na stworzy� przy ilo�ci mniejszej ni� 5 sztuk."
	#define STRERR_S_SCADMINTOOL_0042 "Wprowad� wiadomo��."
	#define STRERR_S_SCADMINTOOL_0043 "Nie mo�na wys�a� wiadomo�ci."
	#define STRERR_S_SCADMINTOOL_0044 "%s: Status serwera (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "Serwer IM nie dzia�a."
	#define STRERR_S_SCADMINTOOL_0046 "Serwer Field nie istnieje."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] Status serwera IM : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, �� - ���� �� �� ��� ���� MSG
#define STRERR_S_SCADMINTOOL_0048 "Ten slot przedmiotu znajduje si� na O.E.D. Mo�esz usun�� slot za pomoc� polecenia \socket."
#define STRERR_S_SCADMINTOOL_0049 "Zapis zmiany O.E.D. nie powi�d� si� (ale zmiana zosta�a dokonana)."
#define STRERR_S_SCADMINTOOL_0050 "�adowanie informacji O.E.D. nie powiod�o si�."
#define STRERR_S_SCADMINTOOL_0051 "Wyposa�ony slot przedmiotu nie zosta� usuni�ty."
#define STRERR_S_SCADMINTOOL_0052 "U�ycie ukrytego bonusu do przedmiot�w znajduj�cych si� w twoim wyposa�eniu."
#define STRERR_S_SCADMINTOOL_0053 "Zmiana slotu przedmiotu O.E.D. nie powiod�a si�."
#define STRERR_S_SCADMINTOOL_0054 "Informacje O.E.D. nie zosta�y zaktualizowane."
#define STRERR_S_SCADMINTOOL_0055 "�adowanie informacji o poziomie O.E.D. nie powiod�o si�."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ������á, �ξ����۰���
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ������á, �ξ����۰���. End



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
	#define STRMSG_S_SCAT_COLNAME_0021 "Utw�rz"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Nie utworzono"
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
	#define STRMSG_S_SCAT_COLNAME_0053 "Automatyczny Typ (Typ 1-1)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Typ Valkan (Typ 1-1)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Typ Dualist (Typ 1-1)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Typ dzia�a (Typ 1-1)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Typ broni (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Typ Gatling (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Typ wyrzutni rakiet (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Typ nap�du masy (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Typ rakiet (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Typ broni zdalnie kierowanych (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Typ wi�zki (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Typ min (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Typ os�ony (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Typ atrapy (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Typ Pixer (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Typ przyn�ty (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Typ obrony"
	#define STRMSG_S_SCAT_COLNAME_0070 "Typ wyposa�enia wspomagaj�cego"
	#define STRMSG_S_SCAT_COLNAME_0071 "Typ energii"
	#define STRMSG_S_SCAT_COLNAME_0072 "Typ metalu"
	#define STRMSG_S_SCAT_COLNAME_0073 "Typ map"
	#define STRMSG_S_SCAT_COLNAME_0074 "Typ udoskonalenia"
	#define STRMSG_S_SCAT_COLNAME_0075 "Typ opancerzenia"
	#define STRMSG_S_SCAT_COLNAME_0076 "Typ kuli"
	#define STRMSG_S_SCAT_COLNAME_0077 "Dla misji"
	#define STRMSG_S_SCAT_COLNAME_0078 "Typ radaru"
	#define STRMSG_S_SCAT_COLNAME_0079 "Typ komputera"
	#define STRMSG_S_SCAT_COLNAME_0080 "Typ karty losowej"
	#define STRMSG_S_SCAT_COLNAME_0081 "Karta zapobiegania zniszczeniu udoskonalenia"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Typ Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Typ Rail Gun"				// 2005-08-02 by cmkwon
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

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '�, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Po��czenie z serwerem Log nie mo�e zosta� nawi�zane[%15s:%4d] Nowe po��czenie\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Zalogowany na serwerze Log.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Po��czenie z serwerem Log[%15s:%4d]zosta�o przerwane. Spr�buj po��czy� si� ponownie.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Nie mo�e po��czy� si� z serwerem Login[%15s:%4d] nowe po��czenie\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Zalogowany na serwerze Login. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) zg�oszony przez %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Nieznany b��d@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Po��czenie z serwerem Login[%15s:%4d] zosta�o zerwane. Spr�buj po��czy� si� ponownie.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), nie mo�na nawi�za� po��czenia z IMServer[%15s:%4d] nowe po��czenie\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Zalogowany na serwerze IM.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Po��czenie z serwerem IM[%15s:%4d] zosta�o przerwane. Spr�buj po��czy� si� ponownie.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) zg�oszony przez %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Nieznany b��d@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Brak takiego zapytania DB w zapytaniach serwera Field! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Wybrany przedmiot nie istnieje."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' ubiega� si� o towarzystwo i obieca� przedmiot"
	#define STRMSG_S_F2DBQUERY_0003 "jest przydzielony. Naci�nij F5 aby sprawdzi� sw�j ekwipunek"
	#define STRMSG_S_F2DBQUERY_0004 "Umiej�tno�� %s(%d) zosta�a dodana"
	#define STRMSG_S_F2DBQUERY_0005 "Wybrany przedmiot nie istnieje."
	#define STRMSG_S_F2DBQUERY_0006 "Zakup przedmiotu nie powi�d� si�."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Rozpocz�cie wojny o zaj�cie miasta : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Uczestnicz�ca brygada: UIDGildii(%4d) NazwaGildii(%10s) MistrzGildii(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Wojna o zaj�cie miasta eksplozja potwor�w : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Szkody ca�kowite ==> Nazwa gildii(%10s) Szkody ca�kowite(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Wojna o zaj�cie miasta: %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) �����(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Po %d minutach \"%s\" rozpocznie wojn� o zaj�cie miasta."
	#define STRMSG_S_F2CITYWAR_0007 "Po %d minutach zako�czy si� wojna o zaj�cie miasta \"%s\"."
	#define STRMSG_S_F2CITYWAR_0008 "Potwory przywo�ane na wojn� o zaj�cie miasta(%s) : Zajmij NPC."
	#define STRMSG_S_F2CITYWAR_0009 "Potwory przywo�ane na wojn� o zaj�cie miasta(%s) : %s zajmuj�ca brygada"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" zajmuje obecnie \"%s\"."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" Brygada zajmuje obecnie \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "�adowanie misji nie powiod�o si�"
	#define STRMSG_S_F2QUEST_0001 "Misja nie zosta�a za�adowana.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Serwer testowy zosta� ustawiony! \r\n\r\nLoadFieldServerDataDebug() musi zosta� zako�czony!"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1. Typ"
	#define STRMSG_S_F2NOTIFY_0003 "2. Typ"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Niew�a�ciwy typ broni! Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Prawdopodobie�stwo ataku zredukowane o %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s nie powiod�o si�, prawdopodobie�stwo(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s nie powiod�o si�, prawdopodobie�stwo(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s nie powiod�o si�, prawdopodobie�stwo(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Obra�enia zredukowane o %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, daje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, otrzymuje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, P�:%5.2f), daje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, otrzymuje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Atrapa nie powiod�a si�: mo�liwe, �e wadliwa > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Pozosta�a atrapa[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Brak informacji o kulach. Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0019 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "To jest informacja o pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Teleportacja nie jest mo�liwa podczas turnieju"
	#define STRMSG_S_F2NOTIFY_0022 "Teleportacja nie jest mo�liwa po twojej �mierci."
	#define STRMSG_S_F2NOTIFY_0023 "Teleportacja nie jest mo�liwa gdy walczysz w formacji"
	#define STRMSG_S_F2NOTIFY_0024 "B��d produkcji map! Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0025 "B��d produkcji map! Prosz� skontaktowa� si� z Administratorem!\rW przypadku %d, %d indeks cel�w teleportacji nie istnieje!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Teleportacja niemo�liwa, poniewa� walka w formacji nie zosta�a zako�czona"
	#define STRMSG_S_F2NOTIFY_0027 "WARP(%04d) Niemo�liwe usuni�cie Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Posta� %10s, odnosi obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Posta� %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Posta� %10s, odnosi obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Posta� %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Posta� %10s, odnosi obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Posta� %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Potw�r %3d, zadaje obra�enia %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Posta� %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Posta� %10s, zadaje obra�enia atrapie%5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Potw�r %3d, odnosi obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> Posta� %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> Posta� %10s, zadaje obra�enia atrapie %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> Potw�r %10s, zadaje obra�enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Inicjalizacja statystyk powiod�a si�."
	#define STRMSG_S_F2NOTIFY_0042 "Nie mo�esz tego u�ywa�, je�eli umar�e�."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO nie istnieje"
	#define STRMSG_S_F2NOTIFY_0044 "Udoskonalenie \g powiod�o si�\g."
	#define STRMSG_S_F2NOTIFY_0045 "Udoskonalenie \r nie powiod�o si�\r."
	#define STRMSG_S_F2NOTIFY_0046 "Nie nale�y do brygady."
	#define STRMSG_S_F2NOTIFY_0047 "Ju� w statusie Standby dla zapytania."
	#define STRMSG_S_F2NOTIFY_0048 "Prosz� spr�buj ponownie p�niej."
	#define STRMSG_S_F2NOTIFY_0049 "Ty albo inna osoba jest dow�dc� brygady."
	#define STRMSG_S_F2NOTIFY_0050 "Ju� w walce w brygadzie."
	#define STRMSG_S_F2NOTIFY_0051 "Obydwaj dow�dcy brygady nie s� w tej samej mapie."
	#define STRMSG_S_F2NOTIFY_0052 "Nie wszyscy cz�onkowie formacji s� na tej samej mapie"
	#define STRMSG_S_F2NOTIFY_0053 "Nie wszyscy cz�onkowie formacji s� w tej samej mapie"
	#define STRMSG_S_F2NOTIFY_0054 "Nie nale�ysz do brygady."
	#define STRMSG_S_F2NOTIFY_0055 "Otrzymuj�cy kandydat jest inny."
	#define STRMSG_S_F2NOTIFY_0056 "Ty lub inna osoba nie jest dow�dc� brygady."
	#define STRMSG_S_F2NOTIFY_0057 "Dwaj dow�dcy brygady nie s� w tej samej mapie."
	#define STRMSG_S_F2NOTIFY_0058 "Nie nale�ysz do brygady."
	#define STRMSG_S_F2NOTIFY_0059 "Otrzymuj�cy kandydat jest inny."
	#define STRMSG_S_F2NOTIFY_0060 "Ty lub inna osoba nie jest dow�dc� brygady."
	#define STRMSG_S_F2NOTIFY_0061 "Sukces w walce obronnej o zajmowane miasto"
	#define STRMSG_S_F2NOTIFY_0062 "B��d ustawie� misji. Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0063 "Wybranego przedmiotu(%s) nie mo�na wstawi� w tym miejscu"
	#define STRMSG_S_F2NOTIFY_0064 "Nie mo�na odrzuci� silnika."
	#define STRMSG_S_F2NOTIFY_0065 "Przemieszczenie przedmiotu: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "B��dne przeniesienie przedmiotu: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENT(%d) Niemo�liwa edycja Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Niestandardowe informacje o evencie map! Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0069 "Wybrany cel teleportacji nie istnieje"
	#define STRMSG_S_F2NOTIFY_0070 "B��d przy zakupie przedmiotu. Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0071 "Poziom umiej�tno�ci, kt�ry chcia�by� kupi�, jest mniejszy od twojego obecnego poziomu."
	#define STRMSG_S_F2NOTIFY_0072 "B��d przedmiotu. Przedmiot wymaga zakupu umiej�tno�ci."
	#define STRMSG_S_F2NOTIFY_0073 "B��d przy sprzeda�y przedmiotu. Prosz� skontaktowa� si� z Administratorem."
	#define STRMSG_S_F2NOTIFY_0074 "B��d przy zakupie przedmiotu. Prosz� skontaktowa� si� z Administratorem."
	#define STRMSG_S_F2NOTIFY_0075 "\'Przedmiot Credit\'zosta� kupiony."
	#define STRMSG_S_F2NOTIFY_0076 "Lista zakup�w : \'%s(%dSztuk)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Przy��czy�e� si� ju� do brygady."
	#define STRMSG_S_F2NOTIFY_0078 "Nie mo�esz do��czy� je�eli jeste� dow�dc�."
	#define STRMSG_S_F2NOTIFY_0079 "Nie mo�na do��czy� w trakcie walki w formacji."
	#define STRMSG_S_F2NOTIFY_0080 "Przekazywanie wszystkich informacji za�odze formacji nie jest mo�liwe!"
	#define STRMSG_S_F2NOTIFY_0081 "Niestandardowa informacja o evencie map! Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0082 "Z tego konta nie mo�na przeprowadzi� transakcji"
	#define STRMSG_S_F2NOTIFY_0083 "�adunek przekroczony o %s's."
	#define STRMSG_S_F2NOTIFY_0084 "Mo�liwa koordynacja ruch�w: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "U�ytkownik:"
	#define STRMSG_S_F2NOTIFY_0086 "Widocznych jest maksymalnie 20 os�b."
	#define STRMSG_S_F2NOTIFY_0087 "Odno�ny u�ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0088 "Nie nale�y do brygady"
	#define STRMSG_S_F2NOTIFY_0089 "Czas rzeczywisty: %d:%d, czas Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Zmieniony czas: %d:%d, czas Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Nie pod��czony do serwera NPC"
	#define STRMSG_S_F2NOTIFY_0092 "Odno�ny przedmiot (%d) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0093 "Ograniczenie do 10 sztuk, je�li nie jest to przedmiot policzalny"
	#define STRMSG_S_F2NOTIFY_0094 "Ca�kowita liczba pod��czonych os�b mapy  \'%s\': %d os�b"
	#define STRMSG_S_F2NOTIFY_0095 "Jednoczesne po��czenia mapy %s %s:  %d os�b - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Mapa %s %s jednoczesne po��czenie: %d os�b - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Kana� aktualnej mapy: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Brak informacji o pociskach. Prosz� skontaktowa� si� z Administratorem."
	#define STRMSG_S_F2NOTIFY_0099 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Brak informacji o pociskach. Prosz� skontaktowa� si� z Administratorem."
	#define STRMSG_S_F2NOTIFY_0101 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Wybrany u�ytkownik(%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0103 "Odno�ny u�ytkownik (%s) nie �yje"
	#define STRMSG_S_F2NOTIFY_0104 "Odno�ny u�ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0105 "Ustaw jako konto standardowe"
	#define STRMSG_S_F2NOTIFY_0106 "Konto standardowe zosta�o zawieszone"
	#define STRMSG_S_F2NOTIFY_0107 "Niezwyci�ono�� zosta�a w��czona."
	#define STRMSG_S_F2NOTIFY_0108 "Niezwyci�ono�� zosta�a wy��czona."
	#define STRMSG_S_F2NOTIFY_0109 "Szkody wyrz�dzane przez bro� zostan� zmienione o %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Zostanie rozpocz�te po ponownym za�adowaniu przedmiotu"
	#define STRMSG_S_F2NOTIFY_0111 "Zostanie rozpocz�te po ponownym za�adowaniu przedmiotu."
	#define STRMSG_S_F2NOTIFY_0112 "Odno�ny u�ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0113 "Niewidzialno�� zosta�a wy��czona."
	#define STRMSG_S_F2NOTIFY_0114 "Niewidzialno�� zosta�a w��czona."
	#define STRMSG_S_F2NOTIFY_0115 "Event %s nie jest w toku"
	#define STRMSG_S_F2NOTIFY_0116 "Event %s rozpocz�� si� (Powi�kszenie:%4.2f, Czas eventu:%3d minut)"
	#define STRMSG_S_F2NOTIFY_0117 "Ustaw Standardowe Konto Premium"
	#define STRMSG_S_F2NOTIFY_0118 "Ustawienie jako Konto Premium nie powiod�o si�"
	#define STRMSG_S_F2NOTIFY_0119 "Ustaw jako Super Konto Premium"
	#define STRMSG_S_F2NOTIFY_0120 "To nie jest mapa na obl�enie miasta."
	#define STRMSG_S_F2NOTIFY_0121 "Nie mo�na rozpocz�� obl�enia miasta"
	#define STRMSG_S_F2NOTIFY_0122 "Nie mo�na zako�czy� obl�enia miasta"
	#define STRMSG_S_F2NOTIFY_0123 "Tryb ukryty zosta� rozpocz�ty"
	#define STRMSG_S_F2NOTIFY_0124 "W statusie ukrytym"
	#define STRMSG_S_F2NOTIFY_0125 "Mapa nie jest potwierdzona."
	#define STRMSG_S_F2NOTIFY_0126 "Happy Hour Event [Czas: %4d minut)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Hour Event zako�czony"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> From monster %3d ,received damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "  1type -> From monster %3d ,received damage %5.2f(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Zalogowany z upowa�nieniem \r %s\r"
	#define STRMSG_S_F2NOTIFY_0131 "Nie edytuj rutyny uzupe�niaj�cej %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Oddalenie za�ogi brygady nie powiod�o si�! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Zatrzymano!"
	#define STRMSG_S_F2NOTIFY_0136 "FATALNY B��D: Prosz� skontaktowa� si� z Administratorem! B��d przy przydzielaniu atrybutu sklepu."
	#define STRMSG_S_F2NOTIFY_0137 "%s jest usuni�ty."
	#define STRMSG_S_F2NOTIFY_0138 "Kana�, w kt�rym si� obecnie znajdujesz jest nieaktywny, dlatego potwory i inne funkcje nie s� dost�pne."
	#define STRMSG_S_F2NOTIFY_0139 "Zatrzymano. Prosz� u�y� innego kana�u."
	#define STRMSG_S_F2NOTIFY_0140 "Obj. teleport.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Ruch timera %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Automatyczna regeneracja P� zatrzymana"
	#define STRMSG_S_F2NOTIFY_0143 "Automatyczna regeneracja P� zosta�a zatrzymana, poniewa� to miejsce nie nadaje si� do l�dowania"
	#define STRMSG_S_F2NOTIFY_0144 "P� 5.2f Regeneracja awaryjna"
	#define STRMSG_S_F2NOTIFY_0145 "Stopniowe P� UP zatrzymane(pozosta�y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Stopniowe DP UP zatrzymane (pozosta�y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Stopniowe PD UP zatrzymane(pozosta�y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "Event %s zosta� zako�czony."
	#define STRMSG_S_F2NOTIFY_0149 "Event %s w toku (Powi�kszenie %4.2f, pozosta�o:%3d minut)"
	#define STRMSG_S_F2NOTIFY_0150 "Polecenie nie zosta�o wykonane"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "B��d przy rozdzielaniu punkt�w do�wiadczenia.(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "B��d: Brak wa�nego komunikatu o rozpocz�ciu gry ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "B��d: Brak wa�nego komunikatu o rozpocz�ciu gry ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) Usuni�cie niemo�liwe jako wynik procesu zadania(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Niestandardowa informacja o evencie map! Prosz� skontaktowa� si� z Administratorem! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) Usuni�cie niemo�liwe przy \rT_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Niestandardowa informacja o evencie map! Prosz� skontaktowa� si� z Administratorem! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP Usuni�cie niemo�liwe przy T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) Usuni�cie niemo�liwe (dow�dca brygady) przy [Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) Usuni�cie niemo�liwe przy Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) Usuni�cie niemo�liwe przy \rProcess_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP Usuni�cie niemo�liwe przy T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Teleportacja nie powiod�a si�: %s -> Odleg�o��: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) Usuni�cie niemo�liwe przy Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> Kliknij na przykryty przycisk OK!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Zadanie nie zosta�o za�adowane.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) Usuni�cie niemo�liwe od HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) Usuni�cie niemo�liwe od HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATALNY B��D: Ta wiadomo�� nie powinna zosta� wys�ana do serwera Field, do kt�rego nie nale�� cz�onkowie. Spr�buj\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) Usuni�cie niemo�liwe przy T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) Usuni�cie niemo�liwe przy T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Punkty do�wiadczenia"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Regeneracja punkt�w do�wiadczenia"
	#define STRMSG_S_F2EVENTTYPE_0003 "Upuszczenie przedmiotu"
	#define STRMSG_S_F2EVENTTYPE_0004 "Upuszczenie rzadkiego przedmiotu"
	#define STRMSG_S_F2EVENTTYPE_0005 "Nieznany event"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Zalogowany na serwerze Login.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Po��czenie z serwerem Login[%15s:%4d] zosta�o utracone. Spr�buj po��czy� si� ponownie.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' ju� istnieje"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' nale�y ju� do brygady."
	#define STRMSG_S_I2NOTIFY_0002 "Brygada o nazwie \'%s\' ju� istnieje"
	#define STRMSG_S_I2NOTIFY_0003 "�adowanie brygady nie powiod�o si� - Prosz� skontaktowa� si� z Administratorem!"
	#define STRMSG_S_I2NOTIFY_0004 "Tw�j przyjaciel '%s' si� zalogowa�"
	#define STRMSG_S_I2NOTIFY_0005 "Sprawd� poprzedni� formacj�"
	#define STRMSG_S_I2NOTIFY_0006 "Poprzednia formacja nie istnieje"
	#define STRMSG_S_I2NOTIFY_0007 "Powr�� do formacji"
	#define STRMSG_S_I2NOTIFY_0008 "Jeste� aktualnie w formacji"
	#define STRMSG_S_I2NOTIFY_0009 "Fatalny b��d: Fatalny b��d grup! Przy T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Status za�ogi formacji jest nieaktualny"
	#define STRMSG_S_I2NOTIFY_0011 "Za�oga formacji przy��czy�a si� ju� do brygady"
	#define STRMSG_S_I2NOTIFY_0012 "Ta osoba do��czy�a do innej brygady"
	#define STRMSG_S_I2NOTIFY_0013 "Nie mo�esz zaprosi� samego siebie"
	#define STRMSG_S_I2NOTIFY_0014 "Tw�j obecny status nie pozwala na do��czenie do �adnej brygady"
	#define STRMSG_S_I2NOTIFY_0015 "Przekroczy�e� liczb� cz�onk�w za�ogi brygady, kt�ra mo�e si� do��czy�"
	#define STRMSG_S_I2NOTIFY_0016 "Tw�j obecny status nie pozwala na do��czenie do brygady"
	#define STRMSG_S_I2NOTIFY_0017 "Dow�dca brygady nie mo�e opu�ci� brygady"
	#define STRMSG_S_I2NOTIFY_0018 "Nie mo�esz opu�ci� brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0019 "Nie mo�esz odrzuci� za�ogi brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0020 "Nie mo�na odrzuci� dow�dcy brygady"
	#define STRMSG_S_I2NOTIFY_0021 "Nie mo�na rozdzieli� brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0022 "Nie mo�na zmieni� na t� sam� nazw�"
	#define STRMSG_S_I2NOTIFY_0023 "Tw�j obecny status nie pozwala na zmian� nazwy brygady"
	#define STRMSG_S_I2NOTIFY_0024 "Tw�j obecny status nie pozwala na zmian� znaku brygady"
	#define STRMSG_S_I2NOTIFY_0025 "Tw�j obecny status nie pozwala na zmian� rangi"
	#define STRMSG_S_I2NOTIFY_0026 "Ranga jest przekroczona"
	#define STRMSG_S_I2NOTIFY_0027 "Zmiana rangi na dow�dc� regimentu jest niemo�liwa."
	#define STRMSG_S_I2NOTIFY_0028 "Zmiana w randze dow�dcy regimentu jest niemo�liwa."
	#define STRMSG_S_I2NOTIFY_0029 "Ca�kowita liczba u�ytkownik�w: %d os�b (wydanie %d osobom)"
	#define STRMSG_S_I2NOTIFY_0030 "Dodano do biuletynu Administratora"
	#define STRMSG_S_I2NOTIFY_0031 "Usuni�to z biuletynu Administratora"
	#define STRMSG_S_I2NOTIFY_0032 "IP serwera: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Grupa serwera \'%s\' ca�kowita liczba zalogowanych os�b: %dOs�b"
	#define STRMSG_S_I2NOTIFY_0034 "Czy naprawd� chcesz zamkn�� serwer(%s)? ID serwera: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' nie gra w gr�"
	#define STRMSG_S_I2NOTIFY_0036 "Ca�kowita liczba u�ytkownik�w: %d os�b (wydanie %d osobom)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Wybrany regiment nie istnieje"
	#define STRMSG_S_I2NOTIFY_0039 "Blokada szeptania zosta�a wy��czona"
	#define STRMSG_S_I2NOTIFY_0040 "Szeptanie zosta�o zablokowane"
	#define STRMSG_S_I2NOTIFY_0041 "Nie wst�pi�e� do brygady"
	#define STRMSG_S_I2NOTIFY_0042 "Brygada (%d) jest niedost�pna"
	#define STRMSG_S_I2NOTIFY_0043 "Wybrana pogoda (%s) nie istnieje"
	#define STRMSG_S_I2NOTIFY_0044 "Serwer Field jest nieaktualny"
	#define STRMSG_S_I2NOTIFY_0045 "Wybrana mapa (%s) nie istnieje"
	#define STRMSG_S_I2NOTIFY_0046 "Przez %d minut nie mo�esz czatowa�!"
	#define STRMSG_S_I2NOTIFY_0047 "Zablokowano czat : '%10s', %3d Min"
	#define STRMSG_S_I2NOTIFY_0048 "Blokada czatu zosta�a zako�czona"
	#define STRMSG_S_I2NOTIFY_0049 "Blokada czatu zako�czona: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(Konto: %s, Mapa: %d(%d), Poziom: %d) GRA"
	#define STRMSG_S_I2NOTIFY_0051 "Nie mo�esz sam si� zawo�a�."
	#define STRMSG_S_I2NOTIFY_0052 "Wybrana brygada nie istnieje."

	#define STRMSG_S_IMSERVER_050607_0001	"Wybrana mapa nie istnieje."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Zalogowany na serwerze Field.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Po��czenie z serwerem Field[%15s:%4d] zosta�o utracone. Spr�buj po��czy� si� ponownie.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Sprawdzanie kolizji pomi�dzy potworami a obiektami nie istnieje\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Przywo�ano potwory na wojn� o zaj�cie miasta(%10s)\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Zalogowany na konto %s(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Sukces"
	#define STRMSG_S_P2PRENOTIFY_0002 "B��d"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]B��d przy dodawaniu informacji konta, Nazwa Konta(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Cze��. Tu administrator AirRivals."
	#define STRMSG_SCAT_051115_0002		"Za 10 minut przeprowadzimy standardowe prace konserwacyjne."
	#define STRMSG_SCAT_051115_0003		"Prosz� uda� si� w bezpieczne miejsce i wyj�� z gry."
	#define STRMSG_SCAT_051115_0004		"Najpierw zostanie zako�czony serwer NPC."
	#define STRMSG_SCAT_051115_0005		"Rozpoczynaj� si� standardowe prace konserwacyjne nad AirRivals."
	#define STRMSG_SCAT_051115_0006		"�yczymy mi�ego dnia z AirRivals."
	#define STRMSG_SCAT_051115_0007		"Za 5 minut b�dzie mia�o miejsce sprawdzanie serwera." // 5     .
	#define STRMSG_SCAT_051115_0008		"Serwer b�dzie offline przez 60 minut."	//  60   
	#define STRMSG_SCAT_051115_0009		"Konserwacja serwera zaczyna si� za 30 minut."
	#define STRMSG_SCAT_051115_0010		"Konserwacja serwera zaczyna si� za 15 minut."
	#define STRMSG_SCAT_051115_0011		"Konserwacja serwera zaczyna si� za 10 minut."
	#define STRMSG_SCAT_051115_0012		"Konserwacja serwera zaczyna si� za 5 minut."
	#define STRMSG_SCAT_051115_0013		"Konserwacja serwera zaczyna si� za chwil�."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Tryb niewidzialny: U�ytkownicy ci� nie widz� i nie mo�na u�y� broni."
	#define STRMSG_060509_0001			"Status niezwyci�onego: Nie odnosisz �adnych obra�e�."
	#define STRMSG_060509_0002			"Tryb ukryty: Potwory ci� nie atakuj�."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Twoje zapytanie zosta�o przes�ane do GM. Jeden z naszych GM�w skontaktuje si� z tob� tak szybko, jak to mo�liwe."
	#define	STRMSG_060526_0001			"Automatyczna aktualizacja by�a niemo�liwa.\r\n\r\nPobierz prosz� �cie�k� ze strony(%s) i po��cz si� ponownie.\r\n\r\n B��d: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"To ID nie zosta�o zarejestrowane lub ID i has�o nie zgadzaj� si�."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Serwer gry jest aktualnie offline z powodu prac konserwacyjnych. Aby otrzyma� dalsze informacje, wejd� na oficjaln� stron� g��wn� (www.airrivals.pl)."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Wersja Client jest nieaktualna.\r\n"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Zosta�e� zabity przez %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Serwer Jamboree DB(atum2_db_20) Po zamkni�ciu serwera Jamboree musi zosta� przeprowadzona inicjalizacja."
	#define STRMSG_070410_0001   	"Czy na pewno chcesz wyj�� z serwera Jamboree DB(atum2_db_20)- [Validation number:%d] ?"
	#define STRMSG_070410_0002   	"Serwer Jamboree DB(atum2_db_20) zainicjalizowany."
	#define STRMSG_070410_0003   	"Inicjalizacja serwera Jamboree DB(atum2_db_20) nie powiod�a si�!"
	#define STRMSG_070410_0004   	"Duplikacja danych '%s' do serwera Jamboree DB(atum2_db_20) zako�czona."
	#define STRMSG_070410_0005   	"Duplikacja danych '%s' do serwera Jamboree DB(atum2_db_20) nie powiod�a si� - posta� nie istnieje!"
	#define STRMSG_070410_0006   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod�a si� - Wybrana posta� konta istnieje!"
	#define STRMSG_070410_0007   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod�a si� - DB B��d dodawania!"
	#define STRMSG_070410_0008   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod�a si� - nieznany (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (niska)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (wysoka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (�rednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (wysoka-szeroka)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (niska)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (niska)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (wysoka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (�rednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (wysoka-szeroka)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (niska)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (wysoka)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Nie mo�esz wystartowa�, poniewa� jeste� w trybie ukrytym."
#define STRMSG_070615_0001		"Nie mo�na rozpocz�� ogl�dania."
#define STRMSG_070620_0000	"U�ytkownik nie mo�e rozpocz�� ogl�dania."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Punkt Wojenny"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Grasz w AirRivals od %d godzin."
#define STRMSG_070628_0001				"Grasz od %d godzin. Podejmij niezb�dne kroki, aby m�c zrobi� przerw�."
#define STRMSG_070628_0002				"Grasz zbyt d�ugo. To niebezpieczne dla zdrowia. We� pod uwag� swoje zdrowie i przerwij gr� dla w�asnego dobra."
#define STRMSG_070628_0003				"Dalsza gra mo�e by� bardzo niebezpieczna dla twojego zdrowia. Uwa�aj na swoje zdrowie i zako�cz teraz gr�. Je�li tego nie zrobisz, wszystkie twoje zyski z gry spadn� do 0%. Twoje zyski z gry powr�c� do normalnego poziomu 5 godzin po zako�czeniu gry."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' nie jest zabronione w strefie wst�pu."
#define STRMSG_070711_0001 "\'%s\' jest zabronione w strefie wst�pu (pozosta�y czas: %d minut)"
#define STRMSG_070711_0002 "Wej�cie do strefy wst�pu jest zabronione przez %d minut!"
#define STRMSG_070711_0003 "Zakaz wej�cia do strefy wst�pu si� sko�czy�."
#define STRMSG_070711_0004 "Gracz \'%s\'  nie mo�e korzysta� z areny."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (�rednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (wysoka-szeroka)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "To polecenie mo�na wybra� dopiero po wybraniu nacji."
#define STRMSG_070830_0002                                   "Mapa sali konferencyjnej (%d) wybranej nacji jest niedost�pna."
#define STRMSG_070830_0003                                   "Liczba u�ytkownik�w mog�cych wej�� do sali konferencyjnej: %d"
#define STRMSG_070830_0004                                   "'%s' znajduje si� ju� na li�cie os�b upowa�nionych do wej�cia."
#define STRMSG_070830_0005                                   "'%s' nie posiada pozwolenia na wej�cie"
#define STRMSG_070830_0006                                   "'%s' nie jest aktualn� postaci�."
#define STRMSG_070830_0007                                 "'%s' nie mo�e zosta� dodany do listy os�b uprawnionych do wej�cia do sali konferencyjnej. (maksymalnie %d os�b)"
#define STRMSG_070830_0008                                   "'%s' otrzyma� pozwolenie na wej�cie do sali konferencyjnej."
#define STRMSG_070830_0009                                   "Pozwolenie na wej�cie do sali konferencyjnej zosta�o udzielone."
#define STRMSG_070830_0010                                   "Pozwolenie na wej�cie do sali konferencyjnej zosta�o wycofane."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s przes�a� ci %s w prezencie."
#define STRMSG_071115_0002									"Aktualna lista : \'%s(%d Sztuk)\'"
#define STRMSG_071115_0003									"\\y %s przesy�a %s prezent. Prezent to %s. Sprawd� prosz� magazyn."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"System Appeal jest nieaktywny. Prosz� skorzysta� z centrum obs�ugi klienta: http://support.airrivals.pl/"
#define STRMSG_071120_0002									"System Appeal jest aktywny."
#define STRMSG_071120_0003									"System Appeal nie jest w��czony."
#define STRMSG_071120_0004									"System Appeal b�dzie uruchomiony od %s do %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s wys�a� %s(%d) w prezencie. Sprawd� prosz� sw�j magazyn."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Ustawienia rozdzielczo�ci s� niew�a�ciwe. Prosz� sprawdzi� ponownie."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'B��d w %s' bloku ustawie�. B��dny kod (%d)"
#define STRMSG_080201_0002									"'%s' konto zosta�o zablokowane. [Blokada ko�czy si� dnia: %s]"
#define STRMSG_080201_0003									"'%s' konto nie jest na li�cie zablokowanych kont. Kod b��du(%d)"
#define STRMSG_080201_0004									"'Przy blokowaniu konta %s wyst�pi� b��d' Kod b��du(%d)"
#define STRMSG_080201_0005									"Konto '%s' zosta�o usuni�te z listy zablokowanych kont." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (�rednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (wysoka-szeroka)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[B��d] WndProc(), Nie mo�e po��czy� si� z serwerem Arena[%15s:%4d] po��cz ponownie\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Po��cz si� z serwerem Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Po��czenie z serwerem Arena [%15s:%4d] zosta�o zako�czone. Spr�buj po��czy� si� ponownie.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) zg�oszony przez %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Nieznany b��d @WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Poczekalni areny nr \\y%d zosta� przydzielony atrybut eventu.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "\\yPoczekalni areny %d zosta� odebrany atrybut eventu.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y B��d przy przydzielaniu atrybutu Arena.\r\n"
#define STRMSG_080428_0001					"%s zosta� pokonany."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ������ �� DB�� �(�� �� ���� ���� �� ������) - 
#define STRMSG_080430_0001					"Na wybranym serwerze nie mo�na by�o utworzy� �adnych nowych postaci."

// 2008-06-13 by dhjin, EP3 ���� �� ���� - 
#define STRMSG_080613_0001					"Wniosek o przyj�cie do brygady %s zosta� odrzucony."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] Nie istnieje �adna (QP_xxx) DB funkcja wyszukiwania!! Typ wyszukiwania (%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRMSG_081230_0001					"\\y%s zostanie na %d minut wykluczony z czatu.\\y"
#define STRMSG_081230_0002					"\\yDow�dca wykluczy� ci� na %d minut z czatu.\\y"
#define STRMSG_081230_0003					"\\yWykluczenie z czatu zako�czy�o si�.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D �� ����� ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - ������� ��, STRMSG_090831_0001�� �������� �
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Zainstaluj Hackshield"
#define STRMSG_090831_0002					"Zainstaluj nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect ����â ����
#define STRMSG_090831_0003					"Anuluj"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - 
#define STRMSG_090902_0001					"http://pl.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �� �(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (niska)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (niska)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (niska)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (�rednia)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (wysoka)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ���� ������ �� ��� ��
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Serwer nierejestrowany (mo�e by� to nielegalny serwer prywatny.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Podczas ��czenia si� z baz� danych wyst�pi� b��d."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Potwierdzenie powiod�o si�"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Zarejestrowano IP serwera, ale odrzucono dalsze potwierdzenie."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Wys�ano polecenie \"Zamknij Windows Server\"."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ���� �����  ��

// 1�� 

#define STRMSG_120330_0001					"%s aktywuje portal teleportacji do Ukrytego Miejsca przy �cie�ce Popio�u."
#define STRMSG_120330_0002					"%s aktywuje 100%%%% wzrostu punkt�w do�wiadczenia (event Happy Hour przez 1 godz.) przy �cie�ce Popio�u."
#define STRMSG_120330_0003					"%s aktywuje 100%%%% wzrostu ilo�ci drop�w przedmiot�w (event Happy Hour przez 1 godz.) przy �cie�ce Popio�u."
#define STRMSG_120330_0004					"%s aktywuje 100%%%% wzrostu ilo�ci drop�w przedmiot�w / punkt�w do�wiadczenia / SPI (event Happy Hour przez 1 godz.) przy �cie�ce Popio�u."
#define STRMSG_120330_0005					"%s aktywuje sklep z broni� na �cie�ce Popio�u."
#define STRMSG_120330_0006					"%s aktywuje Hyper Kart� Sklepu na �cie�ce Popio�u."
#define STRMSG_120330_0007					"%s aktywuje zestaw sklepowy na �cie�ce Popio�u."
#define STRMSG_120330_0008					"%s przywo�uje gigantycznego potwora do �cie�ki Popio�u."
#define STRMSG_120330_0009					"Zagin�� kryszta�."

// 2�� 

#define STRMSG_120508_0001					"%s otrzymuje tak� sam� ilo�� punkt�w wojennych, jak� otrzyma� %d w Wymar�ej Oazie."
#define STRMSG_120508_0002					"%s przywo�uje bossa potwora do Wymar�ej Oazy."
#define STRMSG_120508_0003					"%s aktywuje 150%%%% wzrostu punkt�w do�wiadczenia (event Happy Hour przez 1 godz.) w Wymar�ej Oazie."
#define STRMSG_120508_0004					"%s aktywuje 150%%%% wzrostu cz�stotliwo�ci dropu (event Happy Hour przez 1 godz.) w Wymar�ej Oazie."
#define STRMSG_120508_0005					"%s aktywuje 150%%%% wzrostu ilo�ci drop�w przedmiot�w / punkt�w do�wiadczenia / SPI  (event Happy Hour przez 1 godz.) w Wymar�ej Oazie."
#define STRMSG_120508_0006					"%s otrzymuje Stary L�d w Wymar�ej Oazie."
#define STRMSG_120508_0007					"%s aktywuje powi�kszony ItemShop w Wymar�ej Oazie."
#define STRMSG_120508_0008					"%s aktywuje zestaw sklepowy w Wymar�ej Oazie."
#define STRMSG_120508_0009					"%s aktywuje Hyper Kart� Sklepu w Wymar�ej Oazie."
#define STRMSG_120508_0010					"%s aktywuje sklep z broni� w Wymar�ej Oazie."
#define STRMSG_120508_0011					"%s aktywuje portal teleportacji do Ukrytego Miejsca w Wymar�ej Oazie."

#define STRMSG_120712_0001					"18�� �� ���� ����� ���� ���� ���� ��, %d ��  ������ ���."		// 2012-07-11 by hskim, ������ ��

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ���� ���� %d�� ����."
#define STRMSG_121005_0002					"\\y��� �� PC�� ������ ���."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� ����� ������ - ����� ���� ��������(����)
#define STRMSG_121126_0001					"\\yPolecenie: Podczas aktywnych walk wzbronione jest prowadzenie wszelkich akcji zwi�zanych bezpo�rednio z kryszta�ami.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX �� ������
#define STRMSG_121129_0001					"\\y� �� �� �� ���� ��.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC �������� ���� �����
#define STRMSG_130121_0001					"\\c System zosta� przej�ty przez oddzia�y NGC. Rozpocz�a si� natychmiastowa ewakuacja."
#define STRMSG_130121_0002					"\\cZwiadowcy:\\c \\rJednostka steruj�ca NGC\\r zosta�a wzmocniona."
#define STRMSG_130121_0003					"\\cZwiadowcy:\\c \\rJednostka steruj�ca NGC\\r zosta�a zniszczona."
#define STRMSG_130121_0004					"\\cRozkaz:\\c  Os�ony \\rGomory\\r s� online. Zniszcz \\rJednostk� steruj�c� NGC\\r, aby dezaktywowa� os�ony."
#define STRMSG_130121_0005					"\\cRozkaz:\\c Os�ony \\rGomory\\r s� opuszczone! Do ataku! Teraz!"
#define STRMSG_130121_0006					"\\cRozkaz:\\c \\rGomora\\r zosta�a zniszczona! Wszyscy naprz�d!"
#define STRMSG_130121_0007					"\\cRozkaz:\\c \\rGomora\\r musi zosta� zniszczona."
#define STRMSG_130121_0008					"\\cPrze�adowanie \\c\\rjednostki steruj�cej NGC\\r aktywowa�o: [%s]."
#define STRMSG_130121_0009					"\\y[System bazy posterunku NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������  - ������ ᱸ ����� ����
#define STRMSG_130422_0001					"\\y%s %d nie nadaje si� na aren�. Przedmiot zosta� wys�any do twojego magazynu.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �� ����� - STRMSG �
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gKart� wygl�du dodano do twojej kolekcji kart wygl�du.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gKarta wygl�du zosta�a teraz wykorzystana [%2d] razy.\\g"
#define STRMSG_130531_0003					"\\g[%s] Karta wygl�du osi�gn�a swoje maksymalne zastosowanie. Otrzymujesz [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"Twoja karta wygl�du straci�a wa�no�� i odno�ne warto�ci zosta�y usuni�te. Nap�d nie jest ju� zastosowany."
#define STRMSG_130531_0005					"\\yNie jest zastosowany �aden nap�d. Zostaniesz teleportowany z powrotem do miasta.\\y"
#define STRMSG_130531_0006					"\\gNie mo�esz u�y� karty wygl�du, kt�ra jest aktualnie zastosowana na twoim uzbrojeniu.\\g"
#define STRMSG_130531_0007					"\\gWygl�d zosta� zmieniony.\\g"
#define STRMSG_130531_0008					"\\rKarta wygl�du [%s] straci�a wa�no��.\\r"
#define STRMSG_130531_0009					"\\yUzbrojenia z zastosowan� kart� wygl�du nie mo�na sprzeda�.\\y"
#define STRMSG_130531_0010					"\\yTypy gear�w si� nie zgadzaj�.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ���� ����� �� - STRMSG �
#define STRMSG_130708_0001					"\\cRozkaz:\\c  Os�ony NGC zosta�y aktywowane. Zniszcz \\rJednostk� steruj�c� NGC\\r, aby wyeliminowa� os�ony \\rGomory\\r."
#define STRMSG_130708_0002					"\\cRozkaz:\\c \\rObrona bazy militarnej NGC zosta�a wy��czona. Do ataku teraz!"
#define STRMSG_130708_0003					"\\cZwiadowcy:\\c \\rGenerator os�ony NGC\\r zosta� zauwa�ony."
#define STRMSG_130708_0004					"\\cZwiadowcy:\\c \\rGenerator os�ony NGC\\r zosta� zniszczony."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, � �� �������
#define STRMSG_130726_0001					"Posta� nale�y ju� do tej nacji."
#define STRMSG_130726_0002					"Posta� jest przyw�dc� lub przyw�dc� ni�szej rangi, dlatego nie mo�na zmieni� nacji."
#define STRMSG_130726_0003					"Posta� jest w brygadzie; nie mo�na zmieni� nacji."
#define STRMSG_130726_0004					"Nie ma postaci, kt�ra mog�aby zmieni� nacj�."
#define STRMSG_130726_0005					"Zmiana nacji nie powiod�a si� [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Zmiana nacji powiod�a si� [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"To konto nie istnieje."
#define STRMSG_130726_0008					"Jeste� zalogowany na swoim koncie, nie mo�na zmieni� nacji."


// 2013-08-30 by bckim, �����������
#define STRMSG_130830_0001					"\\yPrzywileje lotu %s zosta�y odebrane przyw�dcy nacji.\\y"
#define STRMSG_130830_0002					"\\yPrzywileje lotu zosta�y odebrane przyw�dcy nacji.\\y"
#define STRMSG_130830_0003					"\\yPrzywileje lotu %s zosta�y odebrane przyw�dcy nacji.\\y"
// End. 2013-08-30 by bckim, �����������

// 2013-08-28 by bckim, �������� ����
#define STRMSG_130828_0001					"\\y[%s bra� udzia� w zniszczeniu: \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s wykona� pierwsze uderzenie przeciwko \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s przeprowadzi� ��cznie najwi�cej ataku na \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s wykona� decyduj�ce uderzenie przeciwko \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n zosta� pokonany."
// End. 2013-08-28 by bckim, �������� ����

// 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����
#define STRMSG_130814_0001					"\\y[%s] wygra� wojn� punkt�w strategicznych NGC.\\y"
// end 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����

// 2014-03-12 by bckim, ������(��������)
#define STRMSG_130318_0001					"%s przywo�a� bossa na zablokowanym obszarze."
#define STRMSG_130318_0002					"%s przywo�a� bossa w ruinach."
// End. 2014-03-12 by bckim, ������(��������)

// 2014-03-18 by bckim, ���� ON/OFF
#define STRMSG_130318_0003					"\\yNie mo�esz teraz u�y� domu aukcyjnego.\\y"
// End. 2014-03-18 by bckim, ���� ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
