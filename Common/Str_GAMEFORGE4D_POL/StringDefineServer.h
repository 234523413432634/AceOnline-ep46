
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Serwer jest nieaktywny."
	#define STRERR_S_ATUMEXE_0002 "Socket z serwera Login zamkniêty!"
	#define STRERR_S_ATUMEXE_0003 "Automatyczna aktualizacja nie powiod³a siê.\r\n Proszê zainstalowaæ grê ponownie.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) zg³oszony przez %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Nieznany b³¹d: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Po³¹czenie z serwerem Download nie mo¿e zostaæ nawi¹zane."
	#define STRERR_S_ATUMEXE_0007 "Rozmiar pobieranego pliku jest nieznany."
	#define STRERR_S_ATUMEXE_0008 "Aktualizacja nie mo¿e zostaæ pobrana"
	#define STRERR_S_ATUMEXE_0009 "System posiada za ma³o pamiêci/zasobów."
	#define STRERR_S_ATUMEXE_0010 "Plik .exe jest niewa¿ny."
	#define STRERR_S_ATUMEXE_0011 "Nie znaleziono pliku."
	#define STRERR_S_ATUMEXE_0012 "Nie znaleziono podanej œcie¿ki."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Aktualizacja zakoñczona"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Proszê wybraæ inny serwer"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Aktualizacja listy usuniêtych plików v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Usuñ pliki tymczasowe"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Aktualizacja wiadomoœci"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Aktualizacja zakoñczona (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Wybierz plik wykonawczy"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Wybierz œcie¿kê wykonawcz¹"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Pobieranie zosta³o przerwane"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Pobieranie przerwane"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Aktualizacja na c%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Nie mo¿na utworzyæ pliku %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Aktualizacja na v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Odbiera informacjê o pliku %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Zaktualizuj VTC Guard"				// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[B³¹d] B³¹d w parametrze liczenia, Liczba(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[B³¹d] B³¹d Mutex\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[B³¹d] Run-time error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[B³¹d] B³¹d dekodowania ID, dekodowane ID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Nie mo¿na po³¹czyæ siê z serwerem Login."
	#define STRERR_S_ATUMLAUNCHER_0005 "B³¹d po³¹czenia z serwerem"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket z serwera Login zamkniêty!"
	#define STRERR_S_ATUMLAUNCHER_0007 "B³¹d pliku wskazówek!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Automatyczna aktualizacja nie powiod³a siê.\r\n Proszê zainstalowaæ grê ponownie.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Wszystkie serwery s¹ obecnie nieaktywne."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s jest sprawdzany..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Wszystkie serwery s¹ sprawdzane. Spróbuj ponownie póŸniej."
	#define STRERR_S_ATUMLAUNCHER_0013 "B£¥D %s(%#04X) zg³oszony przez %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "B³êdne ID lub has³o. Proszê wprowadziæ poprawne ID i has³o."
	#define STRERR_S_ATUMLAUNCHER_0015 "B³¹d logowania"
	#define STRERR_S_ATUMLAUNCHER_0016 "Nie podano ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "Podwójny login"
	#define STRERR_S_ATUMLAUNCHER_0018 "Serwer F nie dzia³a"
	#define STRERR_S_ATUMLAUNCHER_0019 "Serwer I nie dzia³a."
	#define STRERR_S_ATUMLAUNCHER_0020 "Serwis chwilowo zatrzymany. \n\nSpróbuj ponownie póŸniej."
	#define STRERR_S_ATUMLAUNCHER_0021 "Zbyt wielu u¿ytkowników online. \n\nSpróbuj ponownie póŸniej."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Twoje konto jest chwilowo zablokowane.\n period : %s\n\nW celu uzyskania dalszych informacji wyœlij e-mail, który znajdziesz na stronie www.airrivals.pl"
	#define STRERR_S_ATUMLAUNCHER_0023 "Twoja wersja Client nie jest poprawna. \n\nProszê pobraæ grê ponownie."
	#define STRERR_S_ATUMLAUNCHER_0024 "B£¥D: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Nie mo¿na zalogowaæ siê do serwera Download."
	#define STRERR_S_ATUMLAUNCHER_0026 "Rozmiar pobieranego pliku (%s) jest nieznany."
	#define STRERR_S_ATUMLAUNCHER_0027 "Rozmiar pobieranego pliku jest nieznany."
	#define STRERR_S_ATUMLAUNCHER_0028 "Nie mo¿na pobraæ aktualizacji."
	#define STRERR_S_ATUMLAUNCHER_0029 "Zaktualizowany plik nie istnieje."
	#define STRERR_S_ATUMLAUNCHER_0030 "Wybrany serwer jest konserwowany. Proszê spróbowaæ zalogowaæ siê ponownie póŸniej."
	#define STRERR_S_ATUMLAUNCHER_0031 "System posiada za ma³o pamiêci/zasobów."
	#define STRERR_S_ATUMLAUNCHER_0032 "Plik .exe jest niewa¿ny."
	#define STRERR_S_ATUMLAUNCHER_0033 "Nie mo¿na znaleŸæ pliku."
	#define STRERR_S_ATUMLAUNCHER_0034 "Nie mo¿na znaleŸæ œcie¿ki."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, ÇöÀç ½´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÇÑ »çÇ× ¿¡¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î


	#define STRMSG_S_050506		"\'%s\''s Konto jest tymczasowo zablokowane.\n Powód: %s\n Czas trwania: %s~%s\n\nW celu uzyskania dalszych informacji wejdŸ na http://support.airrivals.pl"
	#define STRMSG_S_050930		"Proszê pobraæ grê ponownie.\nURL: %s\nNajnowsza wersja:"
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
	#define STRMSG_S_SCADMINTOOL_0017 "\'Czas Gry \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', ³¹czny \' + dbo.atum_GetHMSFromS(l.£¹czny czas gry)"
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
	#define STRMSG_S_SCADMINTOOL_0039 "Czy chcesz odblokowaæ to konto?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dSekunda)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d zwyciêstw %d pora¿ek"
	#define STRMSG_S_SCADMINTOOL_0042 "Jesteœ pewien, ¿e chcesz oddzieliæ i zablokowaæ konto?"
	#define STRMSG_S_SCADMINTOOL_0043 "Przedmiot %s"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Wiadomoœæ : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Liczba u¿ytkowników : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Odebrana wiadomoœæ : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Liczba u¿ytkowników: %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Status serwera Field : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Po³¹czenie z serwerem zosta³o utracone\n Socket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Nie mo¿na za³adowaæ odpowiednich informacji o koncie."
	#define STRERR_S_SCADMINTOOL_0001 "Zmiana informacji o koncie nie powiod³a siê."
	#define STRERR_S_SCADMINTOOL_0002 "WprowadŸ has³o"
	#define STRERR_S_SCADMINTOOL_0003 "Potwierdzenie has³a nie powiod³o siê"
	#define STRERR_S_SCADMINTOOL_0004 "WprowadŸ swój login"
	#define STRERR_S_SCADMINTOOL_0005 "Serwer Login nie dzia³a."
	#define STRERR_S_SCADMINTOOL_0006 "Nie mo¿na po³¹czyæ siê z serwerem Login!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "B£¥D: Wybrany protokó³ nie istnieje."
	#define STRERR_S_SCADMINTOOL_0009 "WprowadŸ swoj¹ nazwê u¿ytkownika"
	#define STRERR_S_SCADMINTOOL_0010 "WprowadŸ powód"
	#define STRERR_S_SCADMINTOOL_0011 "B³¹d ustawieñ punktów doœwiadczenia : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Zosta³a osi¹gniêta maksymalna iloœæ logów.\r\n\r\Proszê zmieniæ iloœæ maksymalnych logów w ustawieniach wyszukiwania."
	#define STRERR_S_SCADMINTOOL_0013 "Nie mo¿na po³¹czyæ siê z baz¹ danych."
	#define STRERR_S_SCADMINTOOL_0014 "Niepo³¹czony"
	#define STRERR_S_SCADMINTOOL_0015 "Po³¹czony"
	#define STRERR_S_SCADMINTOOL_0016 "Aktualizuje"
	#define STRERR_S_SCADMINTOOL_0017 "Zalogowany"
	#define STRERR_S_SCADMINTOOL_0018 "Wybór postaci"
	#define STRERR_S_SCADMINTOOL_0019 "Gra aktywna"
	#define STRERR_S_SCADMINTOOL_0020 "Nieznany"
	#define STRERR_S_SCADMINTOOL_0021 "Nie mo¿na po³¹czyæ bazy danych %s(%s:%d)."
	#define STRERR_S_SCADMINTOOL_0022 "B³¹d przy dodawaniu przedmiotu"
	#define STRERR_S_SCADMINTOOL_0023 "B³¹d przy szukaniu zablokowanego konta."
	#define STRERR_S_SCADMINTOOL_0024 "Aby zmieniæ konto, wyloguj siê i zablokuj konto."
	#define STRERR_S_SCADMINTOOL_0025 "Nie mo¿na dodaæ SPI (pieniêdzy)."
	#define STRERR_S_SCADMINTOOL_0026 "Wybrany przedmiot ju¿ istnieje, wiêc zmieñ iloœæ."
	#define STRERR_S_SCADMINTOOL_0027 "B³¹d przy szukaniu przedmiotu"
	#define STRERR_S_SCADMINTOOL_0028 "Nie mo¿na usun¹æ SPI (pieniêdzy) postaci."
	#define STRERR_S_SCADMINTOOL_0029 "Chcesz usun¹æ ten przedmiot?"
	#define STRERR_S_SCADMINTOOL_0030 "Usuwanie przedmiotu nie powiod³o siê."
	#define STRERR_S_SCADMINTOOL_0031 "Zmiana przedmiotu nie powiod³a siê."
	#define STRERR_S_SCADMINTOOL_0032 "WprowadŸ konto"
	#define STRERR_S_SCADMINTOOL_0033 "Konto nie istnieje. (Konto mo¿e byæ zablokowane)"
	#define STRERR_S_SCADMINTOOL_0034 "Konto lub postaæ nie istnieje."
	#define STRERR_S_SCADMINTOOL_0035 "B³¹d przy wyszukiwaniu informacji o postaci."
	#define STRERR_S_SCADMINTOOL_0036 "Wybrana postaæ nie istnieje"
	#define STRERR_S_SCADMINTOOL_0037 "B³¹d przy aktualizacji postaci."
	#define STRERR_S_SCADMINTOOL_0038 "Informacje o postaci zosta³y zaktualizowane z powodzeniem."
	#define STRERR_S_SCADMINTOOL_0039 "Wybierz przedmiot."
	#define STRERR_S_SCADMINTOOL_0040 "Wybierz iloœæ przedmiotów."
	#define STRERR_S_SCADMINTOOL_0041 "Wybrany przedmiot mo¿na stworzyæ przy iloœci mniejszej ni¿ 5 sztuk."
	#define STRERR_S_SCADMINTOOL_0042 "WprowadŸ wiadomoœæ."
	#define STRERR_S_SCADMINTOOL_0043 "Nie mo¿na wys³aæ wiadomoœci."
	#define STRERR_S_SCADMINTOOL_0044 "%s: Status serwera (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "Serwer IM nie dzia³a."
	#define STRERR_S_SCADMINTOOL_0046 "Serwer Field nie istnieje."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] Status serwera IM : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÊ - ¾îµå¹Î Åø ÆÊ ±¼­ »ç¿ëµÂ MSG
#define STRERR_S_SCADMINTOOL_0048 "Ten slot przedmiotu znajduje siê na O.E.D. Mo¿esz usun¹æ slot za pomoc¹ polecenia \socket."
#define STRERR_S_SCADMINTOOL_0049 "Zapis zmiany O.E.D. nie powiód³ siê (ale zmiana zosta³a dokonana)."
#define STRERR_S_SCADMINTOOL_0050 "£adowanie informacji O.E.D. nie powiod³o siê."
#define STRERR_S_SCADMINTOOL_0051 "Wyposa¿ony slot przedmiotu nie zosta³ usuniêty."
#define STRERR_S_SCADMINTOOL_0052 "U¿ycie ukrytego bonusu do przedmiotów znajduj¹cych siê w twoim wyposa¿eniu."
#define STRERR_S_SCADMINTOOL_0053 "Zmiana slotu przedmiotu O.E.D. nie powiod³a siê."
#define STRERR_S_SCADMINTOOL_0054 "Informacje O.E.D. nie zosta³y zaktualizowane."
#define STRERR_S_SCADMINTOOL_0055 "£adowanie informacji o poziomie O.E.D. nie powiod³o siê."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎ¾ÆÀÌÅÛ°ûâ´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎ¾ÆÀÌÅÛ°ûâ´É. End



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
	#define STRMSG_S_SCAT_COLNAME_0021 "Utwórz"
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
	#define STRMSG_S_SCAT_COLNAME_0056 "Typ dzia³a (Typ 1-1)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Typ broni (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Typ Gatling (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Typ wyrzutni rakiet (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Typ napêdu masy (Typ 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Typ rakiet (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Typ broni zdalnie kierowanych (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Typ wi¹zki (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Typ min (Typ 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Typ os³ony (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Typ atrapy (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Typ Pixer (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Typ przynêty (Typ 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Typ obrony"
	#define STRMSG_S_SCAT_COLNAME_0070 "Typ wyposa¿enia wspomagaj¹cego"
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

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '°, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Po³¹czenie z serwerem Log nie mo¿e zostaæ nawi¹zane[%15s:%4d] Nowe po³¹czenie\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Zalogowany na serwerze Log.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Po³¹czenie z serwerem Log[%15s:%4d]zosta³o przerwane. Spróbuj po³¹czyæ siê ponownie.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Nie mo¿e po³¹czyæ siê z serwerem Login[%15s:%4d] nowe po³¹czenie\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Zalogowany na serwerze Login. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) zg³oszony przez %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Nieznany b³¹d@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Po³¹czenie z serwerem Login[%15s:%4d] zosta³o zerwane. Spróbuj po³¹czyæ siê ponownie.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), nie mo¿na nawi¹zaæ po³¹czenia z IMServer[%15s:%4d] nowe po³¹czenie\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Zalogowany na serwerze IM.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Po³¹czenie z serwerem IM[%15s:%4d] zosta³o przerwane. Spróbuj po³¹czyæ siê ponownie.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) zg³oszony przez %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Nieznany b³¹d@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Brak takiego zapytania DB w zapytaniach serwera Field! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Wybrany przedmiot nie istnieje."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' ubiega³ siê o towarzystwo i obieca³ przedmiot"
	#define STRMSG_S_F2DBQUERY_0003 "jest przydzielony. Naciœnij F5 aby sprawdziæ swój ekwipunek"
	#define STRMSG_S_F2DBQUERY_0004 "Umiejêtnoœæ %s(%d) zosta³a dodana"
	#define STRMSG_S_F2DBQUERY_0005 "Wybrany przedmiot nie istnieje."
	#define STRMSG_S_F2DBQUERY_0006 "Zakup przedmiotu nie powiód³ siê."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Rozpoczêcie wojny o zajêcie miasta : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Uczestnicz¹ca brygada: UIDGildii(%4d) NazwaGildii(%10s) MistrzGildii(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Wojna o zajêcie miasta eksplozja potworów : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Szkody ca³kowite ==> Nazwa gildii(%10s) Szkody ca³kowite(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Wojna o zajêcie miasta: %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) Á·Éü°(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Po %d minutach \"%s\" rozpocznie wojnê o zajêcie miasta."
	#define STRMSG_S_F2CITYWAR_0007 "Po %d minutach zakoñczy siê wojna o zajêcie miasta \"%s\"."
	#define STRMSG_S_F2CITYWAR_0008 "Potwory przywo³ane na wojnê o zajêcie miasta(%s) : Zajmij NPC."
	#define STRMSG_S_F2CITYWAR_0009 "Potwory przywo³ane na wojnê o zajêcie miasta(%s) : %s zajmuj¹ca brygada"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" zajmuje obecnie \"%s\"."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" Brygada zajmuje obecnie \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "£adowanie misji nie powiod³o siê"
	#define STRMSG_S_F2QUEST_0001 "Misja nie zosta³a za³adowana.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Serwer testowy zosta³ ustawiony! \r\n\r\nLoadFieldServerDataDebug() musi zostaæ zakoñczony!"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1. Typ"
	#define STRMSG_S_F2NOTIFY_0003 "2. Typ"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Niew³aœciwy typ broni! Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Prawdopodobieñstwo ataku zredukowane o %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s nie powiod³o siê, prawdopodobieñstwo(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s nie powiod³o siê, prawdopodobieñstwo(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s nie powiod³o siê, prawdopodobieñstwo(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Obra¿enia zredukowane o %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, daje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, otrzymuje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, P¯:%5.2f), daje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, otrzymuje %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Atrapa nie powiod³a siê: mo¿liwe, ¿e wadliwa > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Pozosta³a atrapa[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Brak informacji o kulach. Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0019 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "To jest informacja o pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Teleportacja nie jest mo¿liwa podczas turnieju"
	#define STRMSG_S_F2NOTIFY_0022 "Teleportacja nie jest mo¿liwa po twojej œmierci."
	#define STRMSG_S_F2NOTIFY_0023 "Teleportacja nie jest mo¿liwa gdy walczysz w formacji"
	#define STRMSG_S_F2NOTIFY_0024 "B³¹d produkcji map! Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0025 "B³¹d produkcji map! Proszê skontaktowaæ siê z Administratorem!\rW przypadku %d, %d indeks celów teleportacji nie istnieje!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Teleportacja niemo¿liwa, poniewa¿ walka w formacji nie zosta³a zakoñczona"
	#define STRMSG_S_F2NOTIFY_0027 "WARP(%04d) Niemo¿liwe usuniêcie Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Postaæ %10s, odnosi obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Postaæ %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Postaæ %10s, odnosi obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Postaæ %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Postaæ %10s, odnosi obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Postaæ %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Potwór %3d, zadaje obra¿enia %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Postaæ %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Postaæ %10s, zadaje obra¿enia atrapie%5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Potwór %3d, odnosi obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> Postaæ %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> Postaæ %10s, zadaje obra¿enia atrapie %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> Potwór %10s, zadaje obra¿enia %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Inicjalizacja statystyk powiod³a siê."
	#define STRMSG_S_F2NOTIFY_0042 "Nie mo¿esz tego u¿ywaæ, je¿eli umar³eœ."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO nie istnieje"
	#define STRMSG_S_F2NOTIFY_0044 "Udoskonalenie \g powiod³o siê\g."
	#define STRMSG_S_F2NOTIFY_0045 "Udoskonalenie \r nie powiod³o siê\r."
	#define STRMSG_S_F2NOTIFY_0046 "Nie nale¿y do brygady."
	#define STRMSG_S_F2NOTIFY_0047 "Ju¿ w statusie Standby dla zapytania."
	#define STRMSG_S_F2NOTIFY_0048 "Proszê spróbuj ponownie póŸniej."
	#define STRMSG_S_F2NOTIFY_0049 "Ty albo inna osoba jest dowódc¹ brygady."
	#define STRMSG_S_F2NOTIFY_0050 "Ju¿ w walce w brygadzie."
	#define STRMSG_S_F2NOTIFY_0051 "Obydwaj dowódcy brygady nie s¹ w tej samej mapie."
	#define STRMSG_S_F2NOTIFY_0052 "Nie wszyscy cz³onkowie formacji s¹ na tej samej mapie"
	#define STRMSG_S_F2NOTIFY_0053 "Nie wszyscy cz³onkowie formacji s¹ w tej samej mapie"
	#define STRMSG_S_F2NOTIFY_0054 "Nie nale¿ysz do brygady."
	#define STRMSG_S_F2NOTIFY_0055 "Otrzymuj¹cy kandydat jest inny."
	#define STRMSG_S_F2NOTIFY_0056 "Ty lub inna osoba nie jest dowódc¹ brygady."
	#define STRMSG_S_F2NOTIFY_0057 "Dwaj dowódcy brygady nie s¹ w tej samej mapie."
	#define STRMSG_S_F2NOTIFY_0058 "Nie nale¿ysz do brygady."
	#define STRMSG_S_F2NOTIFY_0059 "Otrzymuj¹cy kandydat jest inny."
	#define STRMSG_S_F2NOTIFY_0060 "Ty lub inna osoba nie jest dowódc¹ brygady."
	#define STRMSG_S_F2NOTIFY_0061 "Sukces w walce obronnej o zajmowane miasto"
	#define STRMSG_S_F2NOTIFY_0062 "B³¹d ustawieñ misji. Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0063 "Wybranego przedmiotu(%s) nie mo¿na wstawiæ w tym miejscu"
	#define STRMSG_S_F2NOTIFY_0064 "Nie mo¿na odrzuciæ silnika."
	#define STRMSG_S_F2NOTIFY_0065 "Przemieszczenie przedmiotu: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "B³êdne przeniesienie przedmiotu: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENT(%d) Niemo¿liwa edycja Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Niestandardowe informacje o evencie map! Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0069 "Wybrany cel teleportacji nie istnieje"
	#define STRMSG_S_F2NOTIFY_0070 "B³¹d przy zakupie przedmiotu. Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0071 "Poziom umiejêtnoœci, który chcia³byœ kupiæ, jest mniejszy od twojego obecnego poziomu."
	#define STRMSG_S_F2NOTIFY_0072 "B³¹d przedmiotu. Przedmiot wymaga zakupu umiejêtnoœci."
	#define STRMSG_S_F2NOTIFY_0073 "B³¹d przy sprzeda¿y przedmiotu. Proszê skontaktowaæ siê z Administratorem."
	#define STRMSG_S_F2NOTIFY_0074 "B³¹d przy zakupie przedmiotu. Proszê skontaktowaæ siê z Administratorem."
	#define STRMSG_S_F2NOTIFY_0075 "\'Przedmiot Credit\'zosta³ kupiony."
	#define STRMSG_S_F2NOTIFY_0076 "Lista zakupów : \'%s(%dSztuk)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Przy³¹czy³eœ siê ju¿ do brygady."
	#define STRMSG_S_F2NOTIFY_0078 "Nie mo¿esz do³¹czyæ je¿eli jesteœ dowódc¹."
	#define STRMSG_S_F2NOTIFY_0079 "Nie mo¿na do³¹czyæ w trakcie walki w formacji."
	#define STRMSG_S_F2NOTIFY_0080 "Przekazywanie wszystkich informacji za³odze formacji nie jest mo¿liwe!"
	#define STRMSG_S_F2NOTIFY_0081 "Niestandardowa informacja o evencie map! Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_F2NOTIFY_0082 "Z tego konta nie mo¿na przeprowadziæ transakcji"
	#define STRMSG_S_F2NOTIFY_0083 "£adunek przekroczony o %s's."
	#define STRMSG_S_F2NOTIFY_0084 "Mo¿liwa koordynacja ruchów: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "U¿ytkownik:"
	#define STRMSG_S_F2NOTIFY_0086 "Widocznych jest maksymalnie 20 osób."
	#define STRMSG_S_F2NOTIFY_0087 "Odnoœny u¿ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0088 "Nie nale¿y do brygady"
	#define STRMSG_S_F2NOTIFY_0089 "Czas rzeczywisty: %d:%d, czas Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Zmieniony czas: %d:%d, czas Atum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Nie pod³¹czony do serwera NPC"
	#define STRMSG_S_F2NOTIFY_0092 "Odnoœny przedmiot (%d) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0093 "Ograniczenie do 10 sztuk, jeœli nie jest to przedmiot policzalny"
	#define STRMSG_S_F2NOTIFY_0094 "Ca³kowita liczba pod³¹czonych osób mapy  \'%s\': %d osób"
	#define STRMSG_S_F2NOTIFY_0095 "Jednoczesne po³¹czenia mapy %s %s:  %d osób - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Mapa %s %s jednoczesne po³¹czenie: %d osób - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Kana³ aktualnej mapy: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Brak informacji o pociskach. Proszê skontaktowaæ siê z Administratorem."
	#define STRMSG_S_F2NOTIFY_0099 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Brak informacji o pociskach. Proszê skontaktowaæ siê z Administratorem."
	#define STRMSG_S_F2NOTIFY_0101 "Brak informacji o kalibrze pocisku. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Wybrany u¿ytkownik(%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0103 "Odnoœny u¿ytkownik (%s) nie ¿yje"
	#define STRMSG_S_F2NOTIFY_0104 "Odnoœny u¿ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0105 "Ustaw jako konto standardowe"
	#define STRMSG_S_F2NOTIFY_0106 "Konto standardowe zosta³o zawieszone"
	#define STRMSG_S_F2NOTIFY_0107 "Niezwyciê¿onoœæ zosta³a w³¹czona."
	#define STRMSG_S_F2NOTIFY_0108 "Niezwyciê¿onoœæ zosta³a wy³¹czona."
	#define STRMSG_S_F2NOTIFY_0109 "Szkody wyrz¹dzane przez broñ zostan¹ zmienione o %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Zostanie rozpoczête po ponownym za³adowaniu przedmiotu"
	#define STRMSG_S_F2NOTIFY_0111 "Zostanie rozpoczête po ponownym za³adowaniu przedmiotu."
	#define STRMSG_S_F2NOTIFY_0112 "Odnoœny u¿ytkownik (%s) nie istnieje"
	#define STRMSG_S_F2NOTIFY_0113 "Niewidzialnoœæ zosta³a wy³¹czona."
	#define STRMSG_S_F2NOTIFY_0114 "Niewidzialnoœæ zosta³a w³¹czona."
	#define STRMSG_S_F2NOTIFY_0115 "Event %s nie jest w toku"
	#define STRMSG_S_F2NOTIFY_0116 "Event %s rozpocz¹³ siê (Powiêkszenie:%4.2f, Czas eventu:%3d minut)"
	#define STRMSG_S_F2NOTIFY_0117 "Ustaw Standardowe Konto Premium"
	#define STRMSG_S_F2NOTIFY_0118 "Ustawienie jako Konto Premium nie powiod³o siê"
	#define STRMSG_S_F2NOTIFY_0119 "Ustaw jako Super Konto Premium"
	#define STRMSG_S_F2NOTIFY_0120 "To nie jest mapa na oblê¿enie miasta."
	#define STRMSG_S_F2NOTIFY_0121 "Nie mo¿na rozpocz¹æ oblê¿enia miasta"
	#define STRMSG_S_F2NOTIFY_0122 "Nie mo¿na zakoñczyæ oblê¿enia miasta"
	#define STRMSG_S_F2NOTIFY_0123 "Tryb ukryty zosta³ rozpoczêty"
	#define STRMSG_S_F2NOTIFY_0124 "W statusie ukrytym"
	#define STRMSG_S_F2NOTIFY_0125 "Mapa nie jest potwierdzona."
	#define STRMSG_S_F2NOTIFY_0126 "Happy Hour Event [Czas: %4d minut)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Hour Event zakoñczony"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> From monster %3d ,received damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "  1type -> From monster %3d ,received damage %5.2f(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Zalogowany z upowa¿nieniem \r %s\r"
	#define STRMSG_S_F2NOTIFY_0131 "Nie edytuj rutyny uzupe³niaj¹cej %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Oddalenie za³ogi brygady nie powiod³o siê! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Zatrzymano!"
	#define STRMSG_S_F2NOTIFY_0136 "FATALNY B£¥D: Proszê skontaktowaæ siê z Administratorem! B³¹d przy przydzielaniu atrybutu sklepu."
	#define STRMSG_S_F2NOTIFY_0137 "%s jest usuniêty."
	#define STRMSG_S_F2NOTIFY_0138 "Kana³, w którym siê obecnie znajdujesz jest nieaktywny, dlatego potwory i inne funkcje nie s¹ dostêpne."
	#define STRMSG_S_F2NOTIFY_0139 "Zatrzymano. Proszê u¿yæ innego kana³u."
	#define STRMSG_S_F2NOTIFY_0140 "Obj. teleport.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Ruch timera %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Automatyczna regeneracja P¯ zatrzymana"
	#define STRMSG_S_F2NOTIFY_0143 "Automatyczna regeneracja P¯ zosta³a zatrzymana, poniewa¿ to miejsce nie nadaje siê do l¹dowania"
	#define STRMSG_S_F2NOTIFY_0144 "P¯ 5.2f Regeneracja awaryjna"
	#define STRMSG_S_F2NOTIFY_0145 "Stopniowe P¯ UP zatrzymane(pozosta³y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Stopniowe DP UP zatrzymane (pozosta³y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Stopniowe PD UP zatrzymane(pozosta³y czas: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "Event %s zosta³ zakoñczony."
	#define STRMSG_S_F2NOTIFY_0149 "Event %s w toku (Powiêkszenie %4.2f, pozosta³o:%3d minut)"
	#define STRMSG_S_F2NOTIFY_0150 "Polecenie nie zosta³o wykonane"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "B³¹d przy rozdzielaniu punktów doœwiadczenia.(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "B³¹d: Brak wa¿nego komunikatu o rozpoczêciu gry ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "B³¹d: Brak wa¿nego komunikatu o rozpoczêciu gry ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) Usuniêcie niemo¿liwe jako wynik procesu zadania(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Niestandardowa informacja o evencie map! Proszê skontaktowaæ siê z Administratorem! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) Usuniêcie niemo¿liwe przy \rT_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Niestandardowa informacja o evencie map! Proszê skontaktowaæ siê z Administratorem! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP Usuniêcie niemo¿liwe przy T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) Usuniêcie niemo¿liwe (dowódca brygady) przy [Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) Usuniêcie niemo¿liwe przy Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) Usuniêcie niemo¿liwe przy \rProcess_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP Usuniêcie niemo¿liwe przy T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Teleportacja nie powiod³a siê: %s -> Odleg³oœæ: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) Usuniêcie niemo¿liwe przy Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> Kliknij na przykryty przycisk OK!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Zadanie nie zosta³o za³adowane.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) Usuniêcie niemo¿liwe od HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) Usuniêcie niemo¿liwe od HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATALNY B£¥D: Ta wiadomoœæ nie powinna zostaæ wys³ana do serwera Field, do którego nie nale¿¹ cz³onkowie. Spróbuj\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) Usuniêcie niemo¿liwe przy T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) Usuniêcie niemo¿liwe przy T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Punkty doœwiadczenia"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Regeneracja punktów doœwiadczenia"
	#define STRMSG_S_F2EVENTTYPE_0003 "Upuszczenie przedmiotu"
	#define STRMSG_S_F2EVENTTYPE_0004 "Upuszczenie rzadkiego przedmiotu"
	#define STRMSG_S_F2EVENTTYPE_0005 "Nieznany event"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Zalogowany na serwerze Login.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Po³¹czenie z serwerem Login[%15s:%4d] zosta³o utracone. Spróbuj po³¹czyæ siê ponownie.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' ju¿ istnieje"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' nale¿y ju¿ do brygady."
	#define STRMSG_S_I2NOTIFY_0002 "Brygada o nazwie \'%s\' ju¿ istnieje"
	#define STRMSG_S_I2NOTIFY_0003 "£adowanie brygady nie powiod³o siê - Proszê skontaktowaæ siê z Administratorem!"
	#define STRMSG_S_I2NOTIFY_0004 "Twój przyjaciel '%s' siê zalogowa³"
	#define STRMSG_S_I2NOTIFY_0005 "SprawdŸ poprzedni¹ formacjê"
	#define STRMSG_S_I2NOTIFY_0006 "Poprzednia formacja nie istnieje"
	#define STRMSG_S_I2NOTIFY_0007 "Powróæ do formacji"
	#define STRMSG_S_I2NOTIFY_0008 "Jesteœ aktualnie w formacji"
	#define STRMSG_S_I2NOTIFY_0009 "Fatalny b³¹d: Fatalny b³¹d grup! Przy T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Status za³ogi formacji jest nieaktualny"
	#define STRMSG_S_I2NOTIFY_0011 "Za³oga formacji przy³¹czy³a siê ju¿ do brygady"
	#define STRMSG_S_I2NOTIFY_0012 "Ta osoba do³¹czy³a do innej brygady"
	#define STRMSG_S_I2NOTIFY_0013 "Nie mo¿esz zaprosiæ samego siebie"
	#define STRMSG_S_I2NOTIFY_0014 "Twój obecny status nie pozwala na do³¹czenie do ¿adnej brygady"
	#define STRMSG_S_I2NOTIFY_0015 "Przekroczy³eœ liczbê cz³onków za³ogi brygady, która mo¿e siê do³¹czyæ"
	#define STRMSG_S_I2NOTIFY_0016 "Twój obecny status nie pozwala na do³¹czenie do brygady"
	#define STRMSG_S_I2NOTIFY_0017 "Dowódca brygady nie mo¿e opuœciæ brygady"
	#define STRMSG_S_I2NOTIFY_0018 "Nie mo¿esz opuœciæ brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0019 "Nie mo¿esz odrzuciæ za³ogi brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0020 "Nie mo¿na odrzuciæ dowódcy brygady"
	#define STRMSG_S_I2NOTIFY_0021 "Nie mo¿na rozdzieliæ brygady podczas walki w brygadzie"
	#define STRMSG_S_I2NOTIFY_0022 "Nie mo¿na zmieniæ na t¹ sam¹ nazwê"
	#define STRMSG_S_I2NOTIFY_0023 "Twój obecny status nie pozwala na zmianê nazwy brygady"
	#define STRMSG_S_I2NOTIFY_0024 "Twój obecny status nie pozwala na zmianê znaku brygady"
	#define STRMSG_S_I2NOTIFY_0025 "Twój obecny status nie pozwala na zmianê rangi"
	#define STRMSG_S_I2NOTIFY_0026 "Ranga jest przekroczona"
	#define STRMSG_S_I2NOTIFY_0027 "Zmiana rangi na dowódcê regimentu jest niemo¿liwa."
	#define STRMSG_S_I2NOTIFY_0028 "Zmiana w randze dowódcy regimentu jest niemo¿liwa."
	#define STRMSG_S_I2NOTIFY_0029 "Ca³kowita liczba u¿ytkowników: %d osób (wydanie %d osobom)"
	#define STRMSG_S_I2NOTIFY_0030 "Dodano do biuletynu Administratora"
	#define STRMSG_S_I2NOTIFY_0031 "Usuniêto z biuletynu Administratora"
	#define STRMSG_S_I2NOTIFY_0032 "IP serwera: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Grupa serwera \'%s\' ca³kowita liczba zalogowanych osób: %dOsób"
	#define STRMSG_S_I2NOTIFY_0034 "Czy naprawdê chcesz zamkn¹æ serwer(%s)? ID serwera: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' nie gra w grê"
	#define STRMSG_S_I2NOTIFY_0036 "Ca³kowita liczba u¿ytkowników: %d osób (wydanie %d osobom)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Wybrany regiment nie istnieje"
	#define STRMSG_S_I2NOTIFY_0039 "Blokada szeptania zosta³a wy³¹czona"
	#define STRMSG_S_I2NOTIFY_0040 "Szeptanie zosta³o zablokowane"
	#define STRMSG_S_I2NOTIFY_0041 "Nie wst¹pi³eœ do brygady"
	#define STRMSG_S_I2NOTIFY_0042 "Brygada (%d) jest niedostêpna"
	#define STRMSG_S_I2NOTIFY_0043 "Wybrana pogoda (%s) nie istnieje"
	#define STRMSG_S_I2NOTIFY_0044 "Serwer Field jest nieaktualny"
	#define STRMSG_S_I2NOTIFY_0045 "Wybrana mapa (%s) nie istnieje"
	#define STRMSG_S_I2NOTIFY_0046 "Przez %d minut nie mo¿esz czatowaæ!"
	#define STRMSG_S_I2NOTIFY_0047 "Zablokowano czat : '%10s', %3d Min"
	#define STRMSG_S_I2NOTIFY_0048 "Blokada czatu zosta³a zakoñczona"
	#define STRMSG_S_I2NOTIFY_0049 "Blokada czatu zakoñczona: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(Konto: %s, Mapa: %d(%d), Poziom: %d) GRA"
	#define STRMSG_S_I2NOTIFY_0051 "Nie mo¿esz sam siê zawo³aæ."
	#define STRMSG_S_I2NOTIFY_0052 "Wybrana brygada nie istnieje."

	#define STRMSG_S_IMSERVER_050607_0001	"Wybrana mapa nie istnieje."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Zalogowany na serwerze Field.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Po³¹czenie z serwerem Field[%15s:%4d] zosta³o utracone. Spróbuj po³¹czyæ siê ponownie.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Sprawdzanie kolizji pomiêdzy potworami a obiektami nie istnieje\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Przywo³ano potwory na wojnê o zajêcie miasta(%10s)\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Zalogowany na konto %s(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Sukces"
	#define STRMSG_S_P2PRENOTIFY_0002 "B³¹d"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]B³¹d przy dodawaniu informacji konta, Nazwa Konta(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Czeœæ. Tu administrator AirRivals."
	#define STRMSG_SCAT_051115_0002		"Za 10 minut przeprowadzimy standardowe prace konserwacyjne."
	#define STRMSG_SCAT_051115_0003		"Proszê udaæ siê w bezpieczne miejsce i wyjœæ z gry."
	#define STRMSG_SCAT_051115_0004		"Najpierw zostanie zakoñczony serwer NPC."
	#define STRMSG_SCAT_051115_0005		"Rozpoczynaj¹ siê standardowe prace konserwacyjne nad AirRivals."
	#define STRMSG_SCAT_051115_0006		"¯yczymy mi³ego dnia z AirRivals."
	#define STRMSG_SCAT_051115_0007		"Za 5 minut bêdzie mia³o miejsce sprawdzanie serwera." // 5     .
	#define STRMSG_SCAT_051115_0008		"Serwer bêdzie offline przez 60 minut."	//  60   
	#define STRMSG_SCAT_051115_0009		"Konserwacja serwera zaczyna siê za 30 minut."
	#define STRMSG_SCAT_051115_0010		"Konserwacja serwera zaczyna siê za 15 minut."
	#define STRMSG_SCAT_051115_0011		"Konserwacja serwera zaczyna siê za 10 minut."
	#define STRMSG_SCAT_051115_0012		"Konserwacja serwera zaczyna siê za 5 minut."
	#define STRMSG_SCAT_051115_0013		"Konserwacja serwera zaczyna siê za chwilê."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Tryb niewidzialny: U¿ytkownicy ciê nie widz¹ i nie mo¿na u¿yæ broni."
	#define STRMSG_060509_0001			"Status niezwyciê¿onego: Nie odnosisz ¿adnych obra¿eñ."
	#define STRMSG_060509_0002			"Tryb ukryty: Potwory ciê nie atakuj¹."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Twoje zapytanie zosta³o przes³ane do GM. Jeden z naszych GMów skontaktuje siê z tob¹ tak szybko, jak to mo¿liwe."
	#define	STRMSG_060526_0001			"Automatyczna aktualizacja by³a niemo¿liwa.\r\n\r\nPobierz proszê œcie¿kê ze strony(%s) i po³¹cz siê ponownie.\r\n\r\n B³¹d: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"To ID nie zosta³o zarejestrowane lub ID i has³o nie zgadzaj¹ siê."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Serwer gry jest aktualnie offline z powodu prac konserwacyjnych. Aby otrzymaæ dalsze informacje, wejdŸ na oficjaln¹ stronê g³ówn¹ (www.airrivals.pl)."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Wersja Client jest nieaktualna.\r\n"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Zosta³eœ zabity przez %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Serwer Jamboree DB(atum2_db_20) Po zamkniêciu serwera Jamboree musi zostaæ przeprowadzona inicjalizacja."
	#define STRMSG_070410_0001   	"Czy na pewno chcesz wyjœæ z serwera Jamboree DB(atum2_db_20)- [Validation number:%d] ?"
	#define STRMSG_070410_0002   	"Serwer Jamboree DB(atum2_db_20) zainicjalizowany."
	#define STRMSG_070410_0003   	"Inicjalizacja serwera Jamboree DB(atum2_db_20) nie powiod³a siê!"
	#define STRMSG_070410_0004   	"Duplikacja danych '%s' do serwera Jamboree DB(atum2_db_20) zakoñczona."
	#define STRMSG_070410_0005   	"Duplikacja danych '%s' do serwera Jamboree DB(atum2_db_20) nie powiod³a siê - postaæ nie istnieje!"
	#define STRMSG_070410_0006   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod³a siê - Wybrana postaæ konta istnieje!"
	#define STRMSG_070410_0007   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod³a siê - DB B³¹d dodawania!"
	#define STRMSG_070410_0008   	"'%s' Duplikacja danych do serwera Jamboree DB(atum2_db_20) nie powiod³a siê - nieznany (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (niska)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (wysoka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (œrednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (wysoka-szeroka)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (niska)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (niska)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (wysoka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (œrednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (wysoka-szeroka)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (niska)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (wysoka)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Nie mo¿esz wystartowaæ, poniewa¿ jesteœ w trybie ukrytym."
#define STRMSG_070615_0001		"Nie mo¿na rozpocz¹æ ogl¹dania."
#define STRMSG_070620_0000	"U¿ytkownik nie mo¿e rozpocz¹æ ogl¹dania."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Punkt Wojenny"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Grasz w AirRivals od %d godzin."
#define STRMSG_070628_0001				"Grasz od %d godzin. Podejmij niezbêdne kroki, aby móc zrobiæ przerwê."
#define STRMSG_070628_0002				"Grasz zbyt d³ugo. To niebezpieczne dla zdrowia. WeŸ pod uwagê swoje zdrowie i przerwij grê dla w³asnego dobra."
#define STRMSG_070628_0003				"Dalsza gra mo¿e byæ bardzo niebezpieczna dla twojego zdrowia. Uwa¿aj na swoje zdrowie i zakoñcz teraz grê. Jeœli tego nie zrobisz, wszystkie twoje zyski z gry spadn¹ do 0%. Twoje zyski z gry powróc¹ do normalnego poziomu 5 godzin po zakoñczeniu gry."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' nie jest zabronione w strefie wstêpu."
#define STRMSG_070711_0001 "\'%s\' jest zabronione w strefie wstêpu (pozosta³y czas: %d minut)"
#define STRMSG_070711_0002 "Wejœcie do strefy wstêpu jest zabronione przez %d minut!"
#define STRMSG_070711_0003 "Zakaz wejœcia do strefy wstêpu siê skoñczy³."
#define STRMSG_070711_0004 "Gracz \'%s\'  nie mo¿e korzystaæ z areny."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (œrednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (wysoka-szeroka)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "To polecenie mo¿na wybraæ dopiero po wybraniu nacji."
#define STRMSG_070830_0002                                   "Mapa sali konferencyjnej (%d) wybranej nacji jest niedostêpna."
#define STRMSG_070830_0003                                   "Liczba u¿ytkowników mog¹cych wejœæ do sali konferencyjnej: %d"
#define STRMSG_070830_0004                                   "'%s' znajduje siê ju¿ na liœcie osób upowa¿nionych do wejœcia."
#define STRMSG_070830_0005                                   "'%s' nie posiada pozwolenia na wejœcie"
#define STRMSG_070830_0006                                   "'%s' nie jest aktualn¹ postaci¹."
#define STRMSG_070830_0007                                 "'%s' nie mo¿e zostaæ dodany do listy osób uprawnionych do wejœcia do sali konferencyjnej. (maksymalnie %d osób)"
#define STRMSG_070830_0008                                   "'%s' otrzyma³ pozwolenie na wejœcie do sali konferencyjnej."
#define STRMSG_070830_0009                                   "Pozwolenie na wejœcie do sali konferencyjnej zosta³o udzielone."
#define STRMSG_070830_0010                                   "Pozwolenie na wejœcie do sali konferencyjnej zosta³o wycofane."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s przes³a³ ci %s w prezencie."
#define STRMSG_071115_0002									"Aktualna lista : \'%s(%d Sztuk)\'"
#define STRMSG_071115_0003									"\\y %s przesy³a %s prezent. Prezent to %s. SprawdŸ proszê magazyn."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"System Appeal jest nieaktywny. Proszê skorzystaæ z centrum obs³ugi klienta: http://support.airrivals.pl/"
#define STRMSG_071120_0002									"System Appeal jest aktywny."
#define STRMSG_071120_0003									"System Appeal nie jest w³¹czony."
#define STRMSG_071120_0004									"System Appeal bêdzie uruchomiony od %s do %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s wys³a³ %s(%d) w prezencie. SprawdŸ proszê swój magazyn."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Ustawienia rozdzielczoœci s¹ niew³aœciwe. Proszê sprawdziæ ponownie."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'B³¹d w %s' bloku ustawieñ. B³êdny kod (%d)"
#define STRMSG_080201_0002									"'%s' konto zosta³o zablokowane. [Blokada koñczy siê dnia: %s]"
#define STRMSG_080201_0003									"'%s' konto nie jest na liœcie zablokowanych kont. Kod b³êdu(%d)"
#define STRMSG_080201_0004									"'Przy blokowaniu konta %s wyst¹pi³ b³¹d' Kod b³êdu(%d)"
#define STRMSG_080201_0005									"Konto '%s' zosta³o usuniête z listy zablokowanych kont." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (niska-szeroka)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (œrednia-szeroka)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (wysoka-szeroka)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[B³¹d] WndProc(), Nie mo¿e po³¹czyæ siê z serwerem Arena[%15s:%4d] po³¹cz ponownie\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Po³¹cz siê z serwerem Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Po³¹czenie z serwerem Arena [%15s:%4d] zosta³o zakoñczone. Spróbuj po³¹czyæ siê ponownie.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) zg³oszony przez %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Nieznany b³¹d @WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Poczekalni areny nr \\y%d zosta³ przydzielony atrybut eventu.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "\\yPoczekalni areny %d zosta³ odebrany atrybut eventu.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y B³¹d przy przydzielaniu atrybutu Arena.\r\n"
#define STRMSG_080428_0001					"%s zosta³ pokonany."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º º¸ DB¿¡ á(½Ô °è ¸¯ÅÍ »ý¼º ÇÑ ½ýºÅÛá) - 
#define STRMSG_080430_0001					"Na wybranym serwerze nie mo¿na by³o utworzyæ ¿adnych nowych postaci."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼ö »çÇ× - 
#define STRMSG_080613_0001					"Wniosek o przyjêcie do brygady %s zosta³ odrzucony."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] Nie istnieje ¿adna (QP_xxx) DB funkcja wyszukiwania!! Typ wyszukiwania (%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s zostanie na %d minut wykluczony z czatu.\\y"
#define STRMSG_081230_0002					"\\yDowódca wykluczy³ ciê na %d minut z czatu.\\y"
#define STRMSG_081230_0003					"\\yWykluczenie z czatu zakoñczy³o siê.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °å µ¿ÀÇâ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - »ç¿ëÇÏÁö ¾Ê, STRMSG_090831_0001´Â ÆäÀÌÁö·Î ó¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Zainstaluj Hackshield"
#define STRMSG_090831_0002					"Zainstaluj nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"Anuluj"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - 
#define STRMSG_090902_0001					"http://pl.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø Çóµµ á(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (niska)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (niska)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (wysoka)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (niska)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (œrednia)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (wysoka)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ ¼Ó Çã¿ë »ó
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Serwer nierejestrowany (mo¿e byæ to nielegalny serwer prywatny.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Podczas ³¹czenia siê z baz¹ danych wyst¹pi³ b³¹d."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Potwierdzenie powiod³o siê"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Zarejestrowano IP serwera, ale odrzucono dalsze potwierdzenie."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Wys³ano polecenie \"Zamknij Windows Server\"."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ¸®°Å ½ýºÅÛ  ¾²

// 1Â÷ 

#define STRMSG_120330_0001					"%s aktywuje portal teleportacji do Ukrytego Miejsca przy Œcie¿ce Popio³u."
#define STRMSG_120330_0002					"%s aktywuje 100%%%% wzrostu punktów doœwiadczenia (event Happy Hour przez 1 godz.) przy Œcie¿ce Popio³u."
#define STRMSG_120330_0003					"%s aktywuje 100%%%% wzrostu iloœci dropów przedmiotów (event Happy Hour przez 1 godz.) przy Œcie¿ce Popio³u."
#define STRMSG_120330_0004					"%s aktywuje 100%%%% wzrostu iloœci dropów przedmiotów / punktów doœwiadczenia / SPI (event Happy Hour przez 1 godz.) przy Œcie¿ce Popio³u."
#define STRMSG_120330_0005					"%s aktywuje sklep z broni¹ na Œcie¿ce Popio³u."
#define STRMSG_120330_0006					"%s aktywuje Hyper Kartê Sklepu na Œcie¿ce Popio³u."
#define STRMSG_120330_0007					"%s aktywuje zestaw sklepowy na Œcie¿ce Popio³u."
#define STRMSG_120330_0008					"%s przywo³uje gigantycznego potwora do Œcie¿ki Popio³u."
#define STRMSG_120330_0009					"Zagin¹³ kryszta³."

// 2Â÷ 

#define STRMSG_120508_0001					"%s otrzymuje tak¹ sam¹ iloœæ punktów wojennych, jak¹ otrzyma³ %d w Wymar³ej Oazie."
#define STRMSG_120508_0002					"%s przywo³uje bossa potwora do Wymar³ej Oazy."
#define STRMSG_120508_0003					"%s aktywuje 150%%%% wzrostu punktów doœwiadczenia (event Happy Hour przez 1 godz.) w Wymar³ej Oazie."
#define STRMSG_120508_0004					"%s aktywuje 150%%%% wzrostu czêstotliwoœci dropu (event Happy Hour przez 1 godz.) w Wymar³ej Oazie."
#define STRMSG_120508_0005					"%s aktywuje 150%%%% wzrostu iloœci dropów przedmiotów / punktów doœwiadczenia / SPI  (event Happy Hour przez 1 godz.) w Wymar³ej Oazie."
#define STRMSG_120508_0006					"%s otrzymuje Stary Lód w Wymar³ej Oazie."
#define STRMSG_120508_0007					"%s aktywuje powiêkszony ItemShop w Wymar³ej Oazie."
#define STRMSG_120508_0008					"%s aktywuje zestaw sklepowy w Wymar³ej Oazie."
#define STRMSG_120508_0009					"%s aktywuje Hyper Kartê Sklepu w Wymar³ej Oazie."
#define STRMSG_120508_0010					"%s aktywuje sklep z broni¹ w Wymar³ej Oazie."
#define STRMSG_120508_0011					"%s aktywuje portal teleportacji do Ukrytego Miejsca w Wymar³ej Oazie."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, %d ºÐ  °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸Í ½ð£ÀÌ %dºÐ ³²¾Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÀÌ ·áµÙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½ýºÅÛ ¸®´º¾ó - ÀüÀï½Ã ¸®°Å ¹«Àû»óÅÂ(ÀÃÁö)
#define STRMSG_121126_0001					"\\yPolecenie: Podczas aktywnych walk wzbronione jest prowadzenie wszelkich akcji zwi¹zanych bezpoœrednio z kryszta³ami.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX ¸Ê ¿öÇÁÇÑ
#define STRMSG_121129_0001					"\\y¿ ÀÇ ÀÌ ÇÈ Áö¿ª ÀÙ.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀüÀü±âÁö ¸®°Å ½ýºÅÛ
#define STRMSG_130121_0001					"\\c System zosta³ przejêty przez oddzia³y NGC. Rozpoczê³a siê natychmiastowa ewakuacja."
#define STRMSG_130121_0002					"\\cZwiadowcy:\\c \\rJednostka steruj¹ca NGC\\r zosta³a wzmocniona."
#define STRMSG_130121_0003					"\\cZwiadowcy:\\c \\rJednostka steruj¹ca NGC\\r zosta³a zniszczona."
#define STRMSG_130121_0004					"\\cRozkaz:\\c  Os³ony \\rGomory\\r s¹ online. Zniszcz \\rJednostkê steruj¹c¹ NGC\\r, aby dezaktywowaæ os³ony."
#define STRMSG_130121_0005					"\\cRozkaz:\\c Os³ony \\rGomory\\r s¹ opuszczone! Do ataku! Teraz!"
#define STRMSG_130121_0006					"\\cRozkaz:\\c \\rGomora\\r zosta³a zniszczona! Wszyscy naprzód!"
#define STRMSG_130121_0007					"\\cRozkaz:\\c \\rGomora\\r musi zostaæ zniszczona."
#define STRMSG_130121_0008					"\\cPrze³adowanie \\c\\rjednostki steruj¹cej NGC\\r aktywowa³o: [%s]."
#define STRMSG_130121_0009					"\\y[System bazy posterunku NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ  - ¼­ºêŸÀÔ á±¸ ½ýºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d nie nadaje siê na arenê. Przedmiot zosta³ wys³any do twojego magazynu.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Ó Ä÷º¼Ç - STRMSG á
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gKartê wygl¹du dodano do twojej kolekcji kart wygl¹du.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gKarta wygl¹du zosta³a teraz wykorzystana [%2d] razy.\\g"
#define STRMSG_130531_0003					"\\g[%s] Karta wygl¹du osi¹gnê³a swoje maksymalne zastosowanie. Otrzymujesz [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"Twoja karta wygl¹du straci³a wa¿noœæ i odnoœne wartoœci zosta³y usuniête. Napêd nie jest ju¿ zastosowany."
#define STRMSG_130531_0005					"\\yNie jest zastosowany ¿aden napêd. Zostaniesz teleportowany z powrotem do miasta.\\y"
#define STRMSG_130531_0006					"\\gNie mo¿esz u¿yæ karty wygl¹du, która jest aktualnie zastosowana na twoim uzbrojeniu.\\g"
#define STRMSG_130531_0007					"\\gWygl¹d zosta³ zmieniony.\\g"
#define STRMSG_130531_0008					"\\rKarta wygl¹du [%s] straci³a wa¿noœæ.\\r"
#define STRMSG_130531_0009					"\\yUzbrojenia z zastosowan¹ kart¹ wygl¹du nie mo¿na sprzedaæ.\\y"
#define STRMSG_130531_0010					"\\yTypy gearów siê nie zgadzaj¹.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ¸®°Å ½ýºÅÛ Àå - STRMSG á
#define STRMSG_130708_0001					"\\cRozkaz:\\c  Os³ony NGC zosta³y aktywowane. Zniszcz \\rJednostkê steruj¹c¹ NGC\\r, aby wyeliminowaæ os³ony \\rGomory\\r."
#define STRMSG_130708_0002					"\\cRozkaz:\\c \\rObrona bazy militarnej NGC zosta³a wy³¹czona. Do ataku teraz!"
#define STRMSG_130708_0003					"\\cZwiadowcy:\\c \\rGenerator os³ony NGC\\r zosta³ zauwa¿ony."
#define STRMSG_130708_0004					"\\cZwiadowcy:\\c \\rGenerator os³ony NGC\\r zosta³ zniszczony."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRMSG_130726_0001					"Postaæ nale¿y ju¿ do tej nacji."
#define STRMSG_130726_0002					"Postaæ jest przywódc¹ lub przywódc¹ ni¿szej rangi, dlatego nie mo¿na zmieniæ nacji."
#define STRMSG_130726_0003					"Postaæ jest w brygadzie; nie mo¿na zmieniæ nacji."
#define STRMSG_130726_0004					"Nie ma postaci, która mog³aby zmieniæ nacjê."
#define STRMSG_130726_0005					"Zmiana nacji nie powiod³a siê [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Zmiana nacji powiod³a siê [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"To konto nie istnieje."
#define STRMSG_130726_0008					"Jesteœ zalogowany na swoim koncie, nie mo¿na zmieniæ nacji."


// 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\yPrzywileje lotu %s zosta³y odebrane przywódcy nacji.\\y"
#define STRMSG_130830_0002					"\\yPrzywileje lotu zosta³y odebrane przywódcy nacji.\\y"
#define STRMSG_130830_0003					"\\yPrzywileje lotu %s zosta³y odebrane przywódcy nacji.\\y"
// End. 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­
#define STRMSG_130828_0001					"\\y[%s bra³ udzia³ w zniszczeniu: \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s wykona³ pierwsze uderzenie przeciwko \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s przeprowadzi³ ³¹cznie najwiêcej ataku na \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s wykona³ decyduj¹ce uderzenie przeciwko \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n zosta³ pokonany."
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­

// 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â
#define STRMSG_130814_0001					"\\y[%s] wygra³ wojnê punktów strategicznych NGC.\\y"
// end 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â

// 2014-03-12 by bckim, ¹ö´×ÀÓ(ÀüÀïÁö¿ª)
#define STRMSG_130318_0001					"%s przywo³a³ bossa na zablokowanym obszarze."
#define STRMSG_130318_0002					"%s przywo³a³ bossa w ruinach."
// End. 2014-03-12 by bckim, ¹ö´×ÀÓ(ÀüÀïÁö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yNie mo¿esz teraz u¿yæ domu aukcyjnego.\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
