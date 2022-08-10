
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Sunucu aktif edilmemi�."
	#define STRERR_S_ATUMEXE_0002 "Soket �n-Sunucu Taraf�ndan Kapat�ld�!"
	#define STRERR_S_ATUMEXE_0003 "Otomatik y�kseltim ba�ar�s�z. \r\n L�tfen oyunu tekrar y�kleyiniz. \r\n"
	#define STRERR_S_ATUMEXE_0004 "HATA %s(%#04X) al�nd��� yer %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Bilinmeyen Hata: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "�ndirme sunucusuna ba�lan�lamad�."
	#define STRERR_S_ATUMEXE_0007 "�ndirim dosyalar�n�n boyutu bilinmiyor."
	#define STRERR_S_ATUMEXE_0008 "Upgrade dosyas� indirilemiyor."
	#define STRERR_S_ATUMEXE_0009 "Sistem yeterli haf�za veya kayna�a sahip de�il."
	#define STRERR_S_ATUMEXE_0010 ".exe dosyas� ge�ersiz."
	#define STRERR_S_ATUMEXE_0011 "Dosya bulunamad�."
	#define STRERR_S_ATUMEXE_0012 "�lgili klas�r yolu bulunamad�."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "G�ncelleme tamamland�"
	#define STRMSG_S_ATUMLAUNCHER_0001 "L�tfen bir sunucu se�in."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Silinecek dosyalar listesi g�ncelleniyor v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Ge�ici dosyalar siliniyor"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Notlar g�ncelleniyor"
	#define STRMSG_S_ATUMLAUNCHER_0005 "G�ncelleme tamamland� (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "��lem dosyas�n� se�in"
	#define STRMSG_S_ATUMLAUNCHER_0007 "��lem yolunu se�in"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Y�klenme iptal edildi."
	#define STRMSG_S_ATUMLAUNCHER_0009 "Y�kleme bitti."
	#define STRMSG_S_ATUMLAUNCHER_0010 "G�ncelleniyor.. v %s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "%s dosyas� olu�turulamad�"
	#define STRMSG_S_ATUMLAUNCHER_0012 "G�ncelleniyor.. v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "%s dosya bilgilerine ula��l�yor"
    #define STRMSG_S_ATUMLAUNCHER_0014 "VTC koruyucu g�ncelleme"				// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Hata] Parametre Say�m Hatas�, Say�m(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Hata] Mutex Hatas�\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Hata] Y�r�tme Tipi Hatas�, Tip(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Hata] Koda�ma ID Hatas�, Koda�maID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "�n-Sunucuya ba�lanamad�."
	#define STRERR_S_ATUMLAUNCHER_0005 "Sunucuya ba�lan�lamad�."
	#define STRERR_S_ATUMLAUNCHER_0006 "Soket �n-Sunucu Taraf�ndan Kapat�ld�!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Bildirim Dosyas� Hatas�!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Otomatik upgrade ba�ar�s�z. \\r\\n L�tfen oyunu tekrar y�kleyiniz. \\r\\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "�u anda b�t�n sunucular kapal� durumda."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s sorgu alt�nda..."
	#define STRERR_S_ATUMLAUNCHER_0012 "B�t�n sunucular sorgulanmaktad�r. L�tfen daha sonra tekrar girmeyi deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0013 "HATA %s(%#04X) al�nd��� yer %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Ge�ersiz giri� IDsi veya �ifre girdiniz.   L�tfen kay�tl� giri� IDnizi ve �ifrenizi giriniz."
	#define STRERR_S_ATUMLAUNCHER_0015 "Giri� i�leminde hata"
	#define STRERR_S_ATUMLAUNCHER_0016 "Kullan�c� IDsi girilmemi�"
	#define STRERR_S_ATUMLAUNCHER_0017 "�ift giri�"
	#define STRERR_S_ATUMLAUNCHER_0018 "F sunucusu �u anda �al��m�yor."
	#define STRERR_S_ATUMLAUNCHER_0019 "I Sunucusu �u anda �al��m�yor."
	#define STRERR_S_ATUMLAUNCHER_0020 "Servis ge�ici olarak durduruldu. \n\n L�tfen daha sonra tekrar deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0021 "�ok fazla oyuncu �evrimi�i. \n\n L�tfen daha sonra tekrar giri� yapmay� deneyiniz."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Hesab�n�z �u anda bloke durumda. \n S�re : %s\n\nE-mail detaylar i�in www.airrivals.com"
	#define STRERR_S_ATUMLAUNCHER_0023 "�stemci versiyonu do�ru de�il. \n\n L�tfen oyunu tekrar indiriniz."
	#define STRERR_S_ATUMLAUNCHER_0024 "HATA: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "�ndirme sunucuna ba�lanamad�."
	#define STRERR_S_ATUMLAUNCHER_0026 "�ndirim dosyalar�n�n (%s) boyutu bilinemez."
	#define STRERR_S_ATUMLAUNCHER_0027 "�ndirim dosyalar�n�n boyutu bilinmiyor."
	#define STRERR_S_ATUMLAUNCHER_0028 "Upgrade dosyas� indirilemiyor."
	#define STRERR_S_ATUMLAUNCHER_0029 "Upgrade dosyas� bulunmamakta."
	#define STRERR_S_ATUMLAUNCHER_0030 "Se�ilen sunucu sorgu alt�ndad�r. L�tfen daha sonra tekrar giri� yapmay� deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0031 "Sistem yeterli haf�za veya kayna�a sahip de�il."
	#define STRERR_S_ATUMLAUNCHER_0032 ".exe dosyas� ge�ersiz."
	#define STRERR_S_ATUMLAUNCHER_0033 "Dosya bulunamad�."
	#define STRERR_S_ATUMLAUNCHER_0034 "�lgili klas�r yolu bulunamad�."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �� ���� ����� ���� ���� ���� ��, ���� ��� ���� ������ ������.\n\n�� ���� ������� ����� ������."		// 2012-07-11 by hskim, ������ ��


	#define STRMSG_S_050506		"\'%s\''s hesab� bloke edilmi�.\n sebep: %s\n s�re: %s~%s\n\nDetayl� bilgi i�in http://support.airrivals.org fadresini ziyaret edin."
	#define STRMSG_S_050930		"L�tfen oyunu yeniden y�kleyiniz. \nURL: %s\nson versiyon:"
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
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' eklendi ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'par�a, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'par�a'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' silindi ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'par�a, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'par�a'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Ekle ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'par�a, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'par�a'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Depozit ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'par�a, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'par�a'"
	#define STRMSG_S_SCADMINTOOL_0016 "'�yile�me ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'par�a, toplam' + CAST(l.CurrentCount AS VARCHAR(10)) + 'par�a'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'oyun zaman� \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', whole \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', oyun zaman�: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Mevcut de�il)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Hesap blok edildi."
	#define STRMSG_S_SCADMINTOOL_0030 "Sohbet yasakland�"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s sunucu"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s sunucu,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Hesap hacizli"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Bu hesab�n blo�unu kald�rmak istedi�inize emin misiniz?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d saniye)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d kazand� %d kaybetti"
	#define STRMSG_S_SCADMINTOOL_0042 "Hesaba oyundan ��karmak ve blok etmek istedi�inize emin misiniz?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s nesne"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Not: %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Kullan�c� say�s� : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] mesaj ald�: %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] kullan�c� say�s� : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] AlanSunucusu durumu : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Sunucu ile ba�lant� kesildi\nSoket Ad�: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "�lgili hesap bilgileri y�klenemedi."
	#define STRERR_S_SCADMINTOOL_0001 "Hesap bilgileri de�i�tirilemedi."
	#define STRERR_S_SCADMINTOOL_0002 "�ifrenizi girin"
	#define STRERR_S_SCADMINTOOL_0003 "�ifre do�rulanamad�"
	#define STRERR_S_SCADMINTOOL_0004 "Giri� ad�n�z� yaz�n"
	#define STRERR_S_SCADMINTOOL_0005 "�n sunucu ba�lat�lamad�."
	#define STRERR_S_SCADMINTOOL_0006 "�n sunucuya ba�lan�lamad�!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "HATA: �lgili protokol mevcut de�il."
	#define STRERR_S_SCADMINTOOL_0009 "Kullan�c� ad� girin"
	#define STRERR_S_SCADMINTOOL_0010 "Sebep girin"
	#define STRERR_S_SCADMINTOOL_0011 "Deneyim puan� ayarlama hatas�: Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Maksimum kay�t say�s� a��ld�. \r\n\r\n L�tfen maksimum kay�t say�s� veya arama ko�ullar�n� de�i�tirin."
	#define STRERR_S_SCADMINTOOL_0013 "Veritaban� ile ba�lant� kurulamad�."
	#define STRERR_S_SCADMINTOOL_0014 "Ba�l� de�il"
	#define STRERR_S_SCADMINTOOL_0015 "Ba�lan�ld�"
	#define STRERR_S_SCADMINTOOL_0016 "G�ncelleniyor"
	#define STRERR_S_SCADMINTOOL_0017 "Giri� yap�ld�"
	#define STRERR_S_SCADMINTOOL_0018 "Karakter se�iliyor"
	#define STRERR_S_SCADMINTOOL_0019 "Oyun oynuyor"
	#define STRERR_S_SCADMINTOOL_0020 "Bilinmiyor"
	#define STRERR_S_SCADMINTOOL_0021 "%s(%s:%d) veritaban�na ba�lan�lamad�."
	#define STRERR_S_SCADMINTOOL_0022 "Nesne ekleme ba�ar�s�z"
	#define STRERR_S_SCADMINTOOL_0023 "Bloke hesap bulunamad�."
	#define STRERR_S_SCADMINTOOL_0024 "�nce hesaptan ��k�n ve de�i�iklik i�in blok edin."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(para) eklenemez."
	#define STRERR_S_SCADMINTOOL_0026 "Se�ili nesne zaten mevcut, miktar� de�i�tirin."
	#define STRERR_S_SCADMINTOOL_0027 "Nesne bulmada hata"
	#define STRERR_S_SCADMINTOOL_0028 "Karakterin sahip oldu�u SPI(para) silinemez."
	#define STRERR_S_SCADMINTOOL_0029 "Bu nesneyi silmek istiyor musunuz?"
	#define STRERR_S_SCADMINTOOL_0030 "Nesne silme ba�ar�s�z."
	#define STRERR_S_SCADMINTOOL_0031 "Nesne modifikasyonu ba�ar�s�z."
	#define STRERR_S_SCADMINTOOL_0032 "Hesap ad� girin"
	#define STRERR_S_SCADMINTOOL_0033 "Hesap mevcut de�il. (Hesap muhtemelen bloke edilmi� olabilir)"
	#define STRERR_S_SCADMINTOOL_0034 "Hesap veya karakter mevcut de�il."
	#define STRERR_S_SCADMINTOOL_0035 "Karakter bilgi taramas�nda hata."
	#define STRERR_S_SCADMINTOOL_0036 "Uygun karakter mevcut de�il."
	#define STRERR_S_SCADMINTOOL_0037 "Karakter g�ncellemede hata."
	#define STRERR_S_SCADMINTOOL_0038 "Karakter bilgileri ba�ar�yla g�ncellendi."
	#define STRERR_S_SCADMINTOOL_0039 "Bir nesne se�in."
	#define STRERR_S_SCADMINTOOL_0040 "Nesne say�s�n� se�in."
	#define STRERR_S_SCADMINTOOL_0041 "�lgili nesne 5 par�a olarak olu�turulabilir."
	#define STRERR_S_SCADMINTOOL_0042 "Mesaj� yaz�n."
	#define STRERR_S_SCADMINTOOL_0043 "Not (mesaj) g�nderilemedi."
	#define STRERR_S_SCADMINTOOL_0044 "%s: server durumu (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Sunucusu ba�lat�lmad�.."
	#define STRERR_S_SCADMINTOOL_0046 "Alan Sunucusu �al���r durumda de�il."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer durumu : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, �� - ���� �� �� ��� ���� MSG
#define STRERR_S_SCADMINTOOL_0048 "Bu e�ya yuvas� �.E.D.'nde bulunuyor. Yuvay� \socket komutuyla silebilirsin."
#define STRERR_S_SCADMINTOOL_0049 "�.E.D.'deki de�i�iklik kayd� yap�lamad� (ancak de�i�iklik yap�ld�)."
#define STRERR_S_SCADMINTOOL_0050 "�.E.D. bilgileri y�klenemedi."
#define STRERR_S_SCADMINTOOL_0051 "Ku�an�lan e�ya yuvas� silinemedi."
#define STRERR_S_SCADMINTOOL_0052 "Ku�an�lan e�yalar�n gizli bonus uygulamas� ba�ar�s�z oldu."
#define STRERR_S_SCADMINTOOL_0053 "�.E.D.'nin e�ya yuvas� de�i�ikli�i ba�ar�s�z oldu."
#define STRERR_S_SCADMINTOOL_0054 "�.E.D.'nin bilgileri g�ncellenemedi."
#define STRERR_S_SCADMINTOOL_0055 "�.E.D. seviye bilgilerinin y�klenmesi ba�ar�s�z oldu."

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
	#define STRMSG_S_SCAT_COLNAME_0021 "Ekipman"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Ekipman yok"
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
	#define STRMSG_S_SCAT_COLNAME_0053 "Otomatik tip(1-1tipi)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Valkan Tipi (1-1 Tipi)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "�kili Tipi (1-1 Tipi)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Top Tipi (1-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0057 "T�fek Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Mitraly�z Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0059 "F�rlat�c� Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0060 "K�tle S�r�c� Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Roket Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0062 "F�ze Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Paket Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0064 "May�n Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Kalkan Tipi (2-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Kukla Tipi (2-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Toplay�c� Tipi (2-2 tipi)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Tuzak�� Tipi (2-2 tipi)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Defans Tipi"
	#define STRMSG_S_SCAT_COLNAME_0070 "Destep Ekipman Tipi"
	#define STRMSG_S_SCAT_COLNAME_0071 "Enerji Tipi"
	#define STRMSG_S_SCAT_COLNAME_0072 "Metal Tipi"
	#define STRMSG_S_SCAT_COLNAME_0073 "Kart Tipi"
	#define STRMSG_S_SCAT_COLNAME_0074 "Upgrade Tipi"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tank Tipi"
	#define STRMSG_S_SCAT_COLNAME_0076 "Mermi Tipi"
	#define STRMSG_S_SCAT_COLNAME_0077 "G�rev ��in"
	#define STRMSG_S_SCAT_COLNAME_0078 "Radar Tipi"
	#define STRMSG_S_SCAT_COLNAME_0079 "Bilgisayar Tipi"
	#define STRMSG_S_SCAT_COLNAME_0080 "�ans Kart� Tipi"
	#define STRMSG_S_SCAT_COLNAME_0081 "Upgrade Hasar �nleyici Tipi"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Barut�u Tipi"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail T�fek Tipi"				// 2005-08-02 by cmkwon
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
	#define STRMSG_S_SCAT_COLNAME_0094 "Y�netici"

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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), LogServer[%15s:%4d] e ba�lan�lamad�. Tekrar ba�lan\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Log Sunucusuna giri� yap�ld�.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Sunucusu [%15s:%4d] ile ba�lant� kesildi. Yeniden ba�lan�l�yor.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), [%15s:%4d] �n Sunucusuna ba�lan�lamad�. Tekrar ba�lan�l�yor\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "�n Sunucuya giri� yap�ld�. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X)  %s[%s] den al�nd�\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Bilinmeyen hata@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "[%15s:%4d] �n sunucusu ile ba�lant� kesildi. Tekrar ba�lan�l�yor. \r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Hata] WndProc(), IMServer[%15s:%4d] e ba�lan�lamad�. Tekrar ba�lan\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "IM Sunucusuna giri� yap�ld�.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Sunucusu [%15s:%4d] ile ba�lant� kesildi. Yeniden ba�lan�l�yor.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s[%s] den %s(%#04X) al�nd� \r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Bilinmeyen Hata@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Alan Sunucu Sorgular�nda b�yle bir veritaban� sorgusu yoktur%d\n"
	#define STRMSG_S_F2DBQUERY_0001 "�lgili nesne mevcut de�il."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' gitmek i�in ba�vurdu, nesne vaat edildi."
	#define STRMSG_S_F2DBQUERY_0003 "verildi. Sto�unuzu kontrol etmek i�in F5 e bas�n�z."
	#define STRMSG_S_F2DBQUERY_0004 "%s(%d) yetene�i eklendi."
	#define STRMSG_S_F2DBQUERY_0005 "�lgili nesne mevcut de�il."
	#define STRMSG_S_F2DBQUERY_0006 "Nesne sat�n al�namad�."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "�ehir i�gal sava�� ba�lama : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Tugaya kat�l�m : GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "�ehir i�gali sava�� yarat�k patlamas� : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Hasar toplam� ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "�ehir i�gali sava�� : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) �������ð�(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Hata] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d dakika sonra \"%s\" �ehir i�gali sava�� ba�layacakt�r."
	#define STRMSG_S_F2CITYWAR_0007 "%d dakika sonra \"%s\" �ehir i�gali sava�� sona erecektir."
	#define STRMSG_S_F2CITYWAR_0008 "Canavar �ehir i�gali sava�� (%s) i�in teslim olmaya �a�r�ld�: NPC i�gali"
	#define STRMSG_S_F2CITYWAR_0009 "Canavar �ehir i�gali sava�� (%s) i�in teslim olmaya �a�r�ld� : %s tugay i�gali"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" �u an \"%s\" i i�gal ediyor."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" tugay� �u an \"%s\" i i�gal ediyor."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "G�rev y�kleme ba�ar�s�z"
	#define STRMSG_S_F2QUEST_0001 "G�rev y�klenmedi. \r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Test sunucusu ayarland�! \r\n\r\nLoadFieldServerDataDebug() temizlenmeli!"
	#define STRMSG_S_F2NOTIFY_0000 "s��ratma %d: %d den %5.2f(%2.1f%%) e"
	#define STRMSG_S_F2NOTIFY_0001 "canavar s��ratma %d: %s den %5.2f e"
	#define STRMSG_S_F2NOTIFY_0002 "1. tip"
	#define STRMSG_S_F2NOTIFY_0003 "2. tip"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Hatal� silah t�r�! L�tfen y�neticiye bildirimde bulunun."
	#define STRMSG_S_F2NOTIFY_0007 "1-1tipi: %4.1f vs %4.1f -> Sald�r� �ans� %2.2f%% azald�"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s ba�ar�s�z, �ans(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s ba�ar�s�z, �ans(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s ba�ar�s�z, �ans(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2tipi: %4.1f vs %4.1f -> Hasar %2.2f%%(%4.1f->%4.1f) azald�"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, verdi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, ald� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), verdi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, ald� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Kukla ba�ar�s�z: �ans yetersiz > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Kalan kukla [%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Mermi bilgileri mevcut de�il. L�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0019 "Mermi kalibre bilgisi mevcut de�il. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Mermi bilgileridir %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Olay devam ederken ���nlamam�mk�n de�ildir."
	#define STRMSG_S_F2NOTIFY_0022 "�ld�r�lm�� durumdayken ���nlama m�mk�n de�ildir."
	#define STRMSG_S_F2NOTIFY_0023 "Birlik sava�� esnas�nda ���nlama m�mk�n de�ildir."
	#define STRMSG_S_F2NOTIFY_0024 "Harita olu�turmada hata! L�tfen y�neticiye bildiriniz."
	#define STRMSG_S_F2NOTIFY_0025 "Harita olu�turma hatas�! l�tfen y�neticiye bildirin! %d de, %d nolu ���nlama hedef indeksi mevcut de�il!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Birlik sava�� bitmeden ���nlama m�mk�n de�ildir."
	#define STRMSG_S_F2NOTIFY_0027 "I�INLAMA(%04d)  iyile�tirme m�mk�n de�il Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> %10s karakteri %5.2f hasar� ald�"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> %10s karakteri %5.2f hasar� verdi."
	#define STRMSG_S_F2NOTIFY_0030 "1 -> %10s karakteri %5.2f hasar� verdi."
	#define STRMSG_S_F2NOTIFY_0031 "1 -> %10s karakteri %5.2f hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> %10s karakteri %5.2f hasar� ald�"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> %10s karakteri %5.2f hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> %3d canavar�  %5.2f(%d) hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> %10s karakteri %5.2f hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> %10s karakteri %5.2f kukla hasar� verdi."
	#define STRMSG_S_F2NOTIFY_0037 "2 -> %3d canavar� %5.2f hasar� ald�"
	#define STRMSG_S_F2NOTIFY_0038 "TAHR�P-> %10s karakteri %5.2f hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0039 "TAHR�P-> %10s karakteri %5.2f kukla hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0040 "TAHR�P-> %10s canavar� %5.2f hasar� verdi"
	#define STRMSG_S_F2NOTIFY_0041 "Durum ba�latma ba�ar�l�"
	#define STRMSG_S_F2NOTIFY_0042 "�l� durumdayken bunu kullanamazs�n�z"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO mevcut de�il"
	#define STRMSG_S_F2NOTIFY_0044 "Upgrade \g ba�ar�l�\g."
	#define STRMSG_S_F2NOTIFY_0045 "Upgrade \r ba�ar�s�z\r."
	#define STRMSG_S_F2NOTIFY_0046 "Tugaya ait de�ildir."
	#define STRMSG_S_F2NOTIFY_0047 "Zaten istek i�in bekleme durumunda."
	#define STRMSG_S_F2NOTIFY_0048 "L�tfen daha sonra tekrar deneyin."
	#define STRMSG_S_F2NOTIFY_0049 "Siz veya di�er ki�i tugay lideridir."
	#define STRMSG_S_F2NOTIFY_0050 "Zaten bir tugay sava��nda."
	#define STRMSG_S_F2NOTIFY_0051 "Her iki tugay lideri de ayn� haritada de�il."
	#define STRMSG_S_F2NOTIFY_0052 "T�m birlik �yeleri ayn� haritada de�il."
	#define STRMSG_S_F2NOTIFY_0053 "T�m birlik �yeleri ayn� haritada de�il."
	#define STRMSG_S_F2NOTIFY_0054 "Siz bu tugaya ait de�ilsiniz."
	#define STRMSG_S_F2NOTIFY_0055 "Al�nan ba�vurunun sahibi farkl�d�r."
	#define STRMSG_S_F2NOTIFY_0056 "Siz veya di�er ki�i bir tugay lideri de�ilsiniz."
	#define STRMSG_S_F2NOTIFY_0057 "�ki tugay lideri de ayn� haritada de�il."
	#define STRMSG_S_F2NOTIFY_0058 "Siz bu tugaya ait de�ilsiniz."
	#define STRMSG_S_F2NOTIFY_0059 "Al�nan ba�vurunun sahibi farkl�d�r."
	#define STRMSG_S_F2NOTIFY_0060 "Siz veya di�er ki�i bir tugay lideri de�ilsiniz."
	#define STRMSG_S_F2NOTIFY_0061 "�ehir i�gali savunma sava�� ba�ar�l�"
	#define STRMSG_S_F2NOTIFY_0062 "G�rev ayarlar�nda hata. L�tfen y�netiye bildiriniz."
	#define STRMSG_S_F2NOTIFY_0063 "Bu nesne (%s) bu alanda kullan�lmaya uygun de�ildir."
	#define STRMSG_S_F2NOTIFY_0064 "Motor terk edilemedi."
	#define STRMSG_S_F2NOTIFY_0065 "Nesne ta��ma: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Yanl�� nesne hareketi: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "OLAY(%d) yerine getirilemedi Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Harita olay bilgileri anormal! L�tfen y�neticiye bildirin!"
	#define STRMSG_S_F2NOTIFY_0069 "�lgili ���nlama hedefi mevcut de�il"
	#define STRMSG_S_F2NOTIFY_0070 "Nesne sat�nalma hatas�. L�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0071 "Sat�n almak istedi�iniz yetenek �uanki seviyenizde veya daha d���k seviyededir."
	#define STRMSG_S_F2NOTIFY_0072 "Nesne hatas�. Nesne i�in yetenek sat�n almak gerekli."
	#define STRMSG_S_F2NOTIFY_0073 "Nesne satma hatas�. L�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0074 "Nesne sat�nalma hatas�. L�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0075 "\'Kredi nesnesi\' sat�n al�nd�."
	#define STRMSG_S_F2NOTIFY_0076 "Sat�nalma listesi : \'%s(%dpieces)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Zaten partiye kat�lm��t�n�z."
	#define STRMSG_S_F2NOTIFY_0078 "Parti lideri iseniz kat�lamazs�n�z."
	#define STRMSG_S_F2NOTIFY_0079 "Birlik sava�� devam ederken kat�lamazs�n."
	#define STRMSG_S_F2NOTIFY_0080 "T�m birlik personel bilgilerinin g�r�nt�lenmesi desteklenmemektedir!"
	#define STRMSG_S_F2NOTIFY_0081 "Harita olay bilgileri anormal! L�tfen y�neticiye bildirin!"
	#define STRMSG_S_F2NOTIFY_0082 "Bu hesap i�lem yapamaz."
	#define STRMSG_S_F2NOTIFY_0083 "%s in y�k� a��ld�."
	#define STRMSG_S_F2NOTIFY_0084 "Olas� hareket kordinat�: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Kullan�c�:"
	#define STRMSG_S_F2NOTIFY_0086 "Maksimum 20 ki�i g�r�nt�lenebilir."
	#define STRMSG_S_F2NOTIFY_0087 "�lgili kullan�c� (%s) mevcut de�il."
	#define STRMSG_S_F2NOTIFY_0088 "Partiye ait de�il."
	#define STRMSG_S_F2NOTIFY_0089 "�imdiki zaman: %d:%d, Artum zaman�: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "De�i�me zaman�: %d:%d, Artum zaman�: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "NPC sunucusuna ba�l� de�il"
	#define STRMSG_S_F2NOTIFY_0092 "�lgili nesne (%d) mevcut de�il"
	#define STRMSG_S_F2NOTIFY_0093 "Say�lamayan nesneler 10 par�a ile s�n�rl�d�r."
	#define STRMSG_S_F2NOTIFY_0094 "\'%s\' Haritas�na ba�lanan toplam ki�i say�s�: %dpeople"
	#define STRMSG_S_F2NOTIFY_0095 "%s %s haritas�na e�zamanl� ba�lant�: %d ki�i- '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "%s %s haritas�na e�zamanl� ba�lant�: %d ki�i - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "�uanki harita kanal�: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Mermi bilgileri mevcut de�il. l�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0099 "Mermi kalibre bilgileri mevcut de�il. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Mermi bilgileri mevcut de�il. l�tfen y�neticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0101 "Mermi kalibre bilgileri mevcut de�il. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "�lgili kullan�c� (%s) mevcut de�il."
	#define STRMSG_S_F2NOTIFY_0103 "�lgili kullan�c� (%s) �ld�."
	#define STRMSG_S_F2NOTIFY_0104 "�lgili kullan�c� (%s) mevcut de�il."
	#define STRMSG_S_F2NOTIFY_0105 "Standart Hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0106 "Standart Hesap iptal edildi."
	#define STRMSG_S_F2NOTIFY_0107 "Yenilmezlik aktif edildi."
	#define STRMSG_S_F2NOTIFY_0108 "Yenilmezlik modu kapat�ld�."
	#define STRMSG_S_F2NOTIFY_0109 "Silah hasar� %5.0f%% de�i�tirilecek."
	#define STRMSG_S_F2NOTIFY_0110 "Nesne yeniden y�klendi�inde ba�lat�lacak"
	#define STRMSG_S_F2NOTIFY_0111 "Nesne yeniden y�klendi�inde ba�lat�lacak"
	#define STRMSG_S_F2NOTIFY_0112 "�lgili kullan�c� (%s) mevcut de�il"
	#define STRMSG_S_F2NOTIFY_0113 "G�r�nmezlik modu kapat�ld�."
	#define STRMSG_S_F2NOTIFY_0114 "G�r�nmezlik modu aktif"
	#define STRMSG_S_F2NOTIFY_0115 "%s olay� devam etmemekte"
	#define STRMSG_S_F2NOTIFY_0116 "%s olay� ba�lat�ld� (b�y�tme:%4.2f, Olay zaman�:%3d minutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Standart premium Hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0118 "Premium hesap ayar� ba�ar�s�z"
	#define STRMSG_S_F2NOTIFY_0119 "S�per premium hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0120 "Bu �ehir i�gali sava��n�n oldu�u harita de�il"
	#define STRMSG_S_F2NOTIFY_0121 "�ehir i�gali sava�� ba�lat�lamad�"
	#define STRMSG_S_F2NOTIFY_0122 "�ehir i�gali sava�� bitirilemedi"
	#define STRMSG_S_F2NOTIFY_0123 "Gizlilik modu ba�lat�ld�"
	#define STRMSG_S_F2NOTIFY_0124 "Gizlilik modunda"
	#define STRMSG_S_F2NOTIFY_0125 "Harita ge�erli de�il."
	#define STRMSG_S_F2NOTIFY_0126 "Mutlu saatler olaylar� ba�lad�  [ge�en s�re: %4dminute)]"
	#define STRMSG_S_F2NOTIFY_0127 "Mutlu saatler olaylar� bitti"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> %3d canavar�ndan, %5.2f hasar� al�nd�"
	#define STRMSG_S_F2NOTIFY_0129 "1tip -> %3d canavar�ndan, %5.2f(kukla) hasar� al�nd�"
	#define STRMSG_S_F2NOTIFY_0130 "\r %s\r yetkisi ile giri� yap�ld�."
	#define STRMSG_S_F2NOTIFY_0131 "Tamamlama kaidesi i�lenemdi %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "HATA@CharacterGameEndRoutine(): Parti personelini eleme ba�ar�s�z! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Durduruldu!"
	#define STRMSG_S_F2NOTIFY_0136 "C�DD� HATA: L�tfen y�neticiye bildirin! Ma�aza de�i�keni tahsis hatas�!"
	#define STRMSG_S_F2NOTIFY_0137 "%s silindi."
	#define STRMSG_S_F2NOTIFY_0138 "Kulland���n�z kanal devre d��� oldu�undan canavarlar ve di�er fonksiyonlar kullan�lamaz."
	#define STRMSG_S_F2NOTIFY_0139 "Durduruldu. l�tfen ba�ka kanal kullan�n."
	#define STRMSG_S_F2NOTIFY_0140 "I��nlama Nesne.[%s,%2d par�a]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Hareket sayac� %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HP otomatik iyile�me durdu"
	#define STRMSG_S_F2NOTIFY_0143 "HP otomatik iyile�me durdu. Buras� ini� yapmaya m�sait de�il."
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f acil durum iyile�mesi"
	#define STRMSG_S_F2NOTIFY_0145 "Kademeli HP UP Durduruldu (kalan s�re: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Kademeli DP UP Durduruldu (kalan s�re: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Kademeli EP UP Durduruldu(kalan s�re: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s olay� tamamland�."
	#define STRMSG_S_F2NOTIFY_0149 "%s olay� devam etmektedir. (b�y�ltme %4.2f, kalan:%3dminute)"
	#define STRMSG_S_F2NOTIFY_0150 "Komut �al���lmad�"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Tecr�be puan� b�l�m hatas� (%s, %s(%d)): fToplamHasar(%d) < 0.0f or Bo� Vekt�r: %d, Mesafe(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Ge�erli Oyun Ba�lat�m Mesaji de�il hatas� �stemciDurumu[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Ge�erli Oyun Ba�lat�m Mesaji de�il hatas� �stemciDurumu[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "I�INLANMA(%04d) davran��� imkans�z. ��lemG�revSonucu(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Harita olay bilgisi normal de�il! L�tfen admine ba�vurunuz! G�ncel(%s, %s, %04d), Hedef(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) iyile�tirme m�mk�n de�il T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Harita olay bilgisi anormal! Y�neticiye bildiriniz. �u anki (%s, %s, %04d), Hedef (%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "I�INLAMA iyile�tirmesi m�mk�n de�il T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "OLAY(%d) iyile�tirme m�mk�n de�il (parti lideri) Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "I�INLAMA(%04d) iyile�tirme m�mk�n de�il Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "OLAY (%d)  iyile�tirme m�mk�n de�il  Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "I�INLAMA iyile�tirmesi m�mk�n de�il  T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Parti ���nlama ba�ar�s�z: %s -> mesafe: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "I�INLAMA(%04d)  iyile�tirme m�mk�n de�il  Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> OK d��mesine �oklu t�klama!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "G�rev y�klendi.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "I�INLAMA(%s)  iyile�tirme m�mk�n de�il  HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "I�INLAMA(%s)  iyile�tirme m�mk�n de�il  HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "C�DD� HATA: Bu mesaj �yelerin ait olmad��� alan sunucular�na g�nderilmemeli. Kontrol edin\r\n"
	#define STRERR_S_F2NOTIFY_0019 "I�INLAMA(%04d)  iyile�tirme m�mk�n de�il T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "I�INLAMA(%s)  iyile�tirme m�mk�n de�il T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Tecr�be puanlar�"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Tecr�be puanlar�n�n yenilenmesi"
	#define STRMSG_S_F2EVENTTYPE_0003 "Nesne d���rme"
	#define STRMSG_S_F2EVENTTYPE_0004 "Nadir nesne d���rme"
	#define STRMSG_S_F2EVENTTYPE_0005 "Bilinmeyen olay"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "�n sunucuya giri� yap�ld�. \n"
	#define STRMSG_S_I2PRECONNECT_0001 "[%15s:%4d] �n sunucusu ile ba�lant� kesildi. Yeniden ba�lanmaya �al���lyor. \r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' zaten mevcut"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' zaten bir tugayda."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' zaten mevcut bir tugay�n ad�d�r"
	#define STRMSG_S_I2NOTIFY_0003 "Tugay y�kleme ba�ar�s�z. L�tfen y�neticiye bildirin!"
	#define STRMSG_S_I2NOTIFY_0004 "Arkada��n '%s' giri� yapt�."
	#define STRMSG_S_I2NOTIFY_0005 "�nceki birli�i kontrol et"
	#define STRMSG_S_I2NOTIFY_0006 "�nceki birlik mevcut de�il"
	#define STRMSG_S_I2NOTIFY_0007 "Birli�e geri d�n"
	#define STRMSG_S_I2NOTIFY_0008 "�u an bir birliktesin"
	#define STRMSG_S_I2NOTIFY_0009 "C�DD� HATAr: ciddi parti hatas�! T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Birlik personelinin durumu ge�ersiz"
	#define STRMSG_S_I2NOTIFY_0011 "Birlik personeli zaten tugaya kat�lm��"
	#define STRMSG_S_I2NOTIFY_0012 "Bu ki�i zaten tugaya kat�lm��"
	#define STRMSG_S_I2NOTIFY_0013 "Kendi kendinizi davet edemesiniz"
	#define STRMSG_S_I2NOTIFY_0014 "Bir tugaya kat�lman�za izin verilmeyen bir konumdas�n�z"
	#define STRMSG_S_I2NOTIFY_0015 "Kat�labilece�in tugay personeli say�s�n� a�t�n"
	#define STRMSG_S_I2NOTIFY_0016 "Bir tugaya kat�lman�za engel olan bir konumdas�n"
	#define STRMSG_S_I2NOTIFY_0017 "Tugay lideri tugaydan ��kar�lamaz."
	#define STRMSG_S_I2NOTIFY_0018 "Bir tugay sava�� devam ederken tugaydan ��kar�lamaz."
	#define STRMSG_S_I2NOTIFY_0019 "Bir tugay sava�� devam ederken tugaydan ihra� yap�lamaz."
	#define STRMSG_S_I2NOTIFY_0020 "Tugay lideri tugaydan ihra� edilemez."
	#define STRMSG_S_I2NOTIFY_0021 "Bir tugay sava�� devam ederken tugay da��t�lamaz."
	#define STRMSG_S_I2NOTIFY_0022 "Ayn� isme de�i�iklik yap�lamaz"
	#define STRMSG_S_I2NOTIFY_0023 "Tugay isminin de�i�tirilemeyece�i bir durumdas�n�z."
	#define STRMSG_S_I2NOTIFY_0024 "Tugay i�aretinin de�i�tirilemeyece�i bir durumdas�n�z."
	#define STRMSG_S_I2NOTIFY_0025 "R�tbelerin de�i�tirilemeyece�i bir durumdas�n�z"
	#define STRMSG_S_I2NOTIFY_0026 "R�tbe zaten mevcut"
	#define STRMSG_S_I2NOTIFY_0027 "Alay lideri i�in r�tbe de�i�imi m�mk�n de�ildir."
	#define STRMSG_S_I2NOTIFY_0028 "Alay liderleri i�in r�tbe de�i�imi yap�lamaz."
	#define STRMSG_S_I2NOTIFY_0029 "Toplam kullan�c� say�s�: %d ki�i (%d ki�iye kadar ��kt�)"
	#define STRMSG_S_I2NOTIFY_0030 "Y�netici mesajlar� listesine eklendi."
	#define STRMSG_S_I2NOTIFY_0031 "Y�netici mesajlar� listesinden silindi"
	#define STRMSG_S_I2NOTIFY_0032 "Sunucu IPsi: %s"
	#define STRMSG_S_I2NOTIFY_0033 "\'%s\' sunucu grubugiri� yapan toplam ki�i say�s�: %d ki�i"
	#define STRMSG_S_I2NOTIFY_0034 "Sunucuyu (%s) kapatmak istedi�inize emin misiniz? ServerID: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' oyun oynam�yor"
	#define STRMSG_S_I2NOTIFY_0036 "Toplam kullan�c� say�s�: %d ki�i (%d ki�iye kadar ��kt�)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "�lgili alay mevcut de�il."
	#define STRMSG_S_I2NOTIFY_0039 "F�s�ldama blo�u kald�r�ld�"
	#define STRMSG_S_I2NOTIFY_0040 "F�s�ldama blokland�"
	#define STRMSG_S_I2NOTIFY_0041 "Tugaya kat�lmad�"
	#define STRMSG_S_I2NOTIFY_0042 "(%d) Tugay� mevcut de�il"
	#define STRMSG_S_I2NOTIFY_0043 "�lgili hava (%s) mevcut de�il."
	#define STRMSG_S_I2NOTIFY_0044 "Alan Sunucusu ge�ersiz"
	#define STRMSG_S_I2NOTIFY_0045 "�lgili harita (%s) mevcut de�il."
	#define STRMSG_S_I2NOTIFY_0046 "%d dakika boyunca sohbet edemezsin!"
	#define STRMSG_S_I2NOTIFY_0047 "Sohbet yasa�� ayarland�:  '%10s', %3d dakika"
	#define STRMSG_S_I2NOTIFY_0048 "Sohbet blo�u durumu iptal edildi."
	#define STRMSG_S_I2NOTIFY_0049 "Sohbet blo�u iptal edildi: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (hesap: %s, harita: %d(%d), seviye: %d) OYNUYOR"
	#define STRMSG_S_I2NOTIFY_0051 "Kendini teslim olmaya �a��ramazs�n"
	#define STRMSG_S_I2NOTIFY_0052 "�lgili tugay mevcut de�il."

	#define STRMSG_S_IMSERVER_050607_0001	"�lgili harita mevcut de�il."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Alan Sunucusuna giri� yap�ld�.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "[%15s:%4d] Alan Sunucusu ile ba�lant� kesildi. Yeniden ba�lan�lmaya �al���l�yor.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Canavar ve nesne aras�nda �arp��ma kontrol� mevcut de�il.\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "�ehir i�gal sava�� canavar (%10s) teslim olmaya �a�r�ld�\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%s hesab� (%s) ile giri� yap�ld�. IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Ba�ar�l�"
	#define STRMSG_S_P2PRENOTIFY_0002 "Ba�ar�s�z"
	#define STRMSG_S_P2PRENOTIFY_0003 "[HATA] Hesap bilgileri eklemede hata olu�tu, AccountName(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Merhaba. Bu AirRivals Y�neticisidir."
	#define STRMSG_SCAT_051115_0002		"10 dakikal���na d�zenli bak�m �al��mam�z yap�lacakt�r."
	#define STRMSG_SCAT_051115_0003		"L�tfen g�venli bir b�lgeye gidin ve oyundan ��k�n."
	#define STRMSG_SCAT_051115_0004		"�nce, NPC sunucusu kapat�lacakt�r."
	#define STRMSG_SCAT_051115_0005		"AirRivals d�zenli bak�m� ba�layacak."
	#define STRMSG_SCAT_051115_0006		"AirRivals ile g�n�n�ze e�lence kat�n."
	#define STRMSG_SCAT_051115_0007		"5 dakika i�inde sunucu bak�m� yap�lacakt�r." // 5     .
	#define STRMSG_SCAT_051115_0008		"Sunucu 60 dakikal���na �evrim d��� olacakt�r."	//  60   
	#define STRMSG_SCAT_051115_0009		"Sunucu onar�m� 30 dakika sonra ba�l�yor."
	#define STRMSG_SCAT_051115_0010		"Sunucu onar�m� 15 dakika sonra ba�l�yor."
	#define STRMSG_SCAT_051115_0011		"Sunucu onar�m� 10 dakika sonra ba�l�yor."
	#define STRMSG_SCAT_051115_0012		"Sunucu onar�m� 5 dakika sonra ba�l�yor."
	#define STRMSG_SCAT_051115_0013		"Sunucu onar�m� ba�lamak �zere."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"G�r�nmez Mode: Kullan�c�lar sizi g�remez ve silahlar kullan�lamaz."
	#define STRMSG_060509_0001			"Yenilmez Stat�s�: Hi�bir zarar almazs�n�z."
	#define STRMSG_060509_0002			"Gizlilik Modu: �lk sald�r� yarat�klardan gelmez."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"�ste�iniz oyun y�netilerine g�nderildi. Oyun y�neticilerinden biri en k�sa s�rede sizinle ileti�im kuracakt�r."
	#define	STRMSG_060526_0001			"Otomatik g�ncelleme yapamad�n�z.\r\n\r\n L�tfen (%s) adresinden yamay� y�kleyip yeniden ba�lan�n.\r\n\r\n	Hata: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Bu ID kay�tl� de�il veya ID ve �ifre bilgileri uyu�muyor."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Oyun sunucusu bak�m nedeniyle �u an �evrim d���d�r. L�tfen daha fazla bilgi i�in resmi internet sitemizi (www.airrivals.net) ziyaret edin."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Oyun istemci versiyonu ge�erli de�il. \r\n  L�tfen yama dosyas�n� tekrar indirin veya tekrar y�kleyin."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"%s taraf�ndan �ld�r�ld�n."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree server DB(atum2_db_20) s�f�rlanmas� jamboree server kapat�ld�ktan sonra y�r�t�lebilir."
	#define STRMSG_070410_0001   	"jamboree server DB(atum2_db_20) s�f�rlamak istedi�inize emin misiniz - [Onaylama numaras�:%d]"
	#define STRMSG_070410_0002   	"Jamboree server	DB(atum2_db_20) s�f�rland�."
	#define STRMSG_070410_0003   	"Jamboree server	DB(atum2_db_20) s�f�rlanmas� ba�ar�s�z !!"
	#define STRMSG_070410_0004   	"Jamboree server DB(atum2_db_20) e '%s' veri �o�altmas� tamamland�."
	#define STRMSG_070410_0005   	"Jamboree server DB(atum2_db_20) e '%s' veri �o�altmas� ba�ar�s�z - karakter mevcut de�il!"
	#define STRMSG_070410_0006   	"Jamboree server DB(atum2_db_20) %s' veri �o�altmas� ba�ar�s�z - �lgili hesap karakteri mevcut de�il!"
	#define STRMSG_070410_0007   	"Jamboree server DB(atum2_db_20) %s' veri �o�altmas� ba�ar�s�z - Veritaban� ekleme hatas�!"
	#define STRMSG_070410_0008   	"Jamboree server DB(atum2_db_20) %s veri �o�altmas� ba�ar�s�z - Bilinmeyen hata (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (d���k)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (orta)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (y�ksek)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (d���k-geni�)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (orta-geni�)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (y�ksek-geni�)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (d���k)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (orta)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (y�ksek)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (d���k)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (orta)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (y�ksek)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (d���k-geni�)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (orta-geni�)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (y�ksek-geni�)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (d���k)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (orta)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (y�ksek)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Gizlilik modunda oldu�unuzdan ba�layamaz."
#define STRMSG_070615_0001		"G�zleme ba�lat�lamad�."
#define STRMSG_070620_0000	"Kullan�c� g�zlemeyi ba�latamad�."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Sava�Noktas�"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"%d saattir bu oyunu oynuyorsunuz."
#define STRMSG_070628_0001				"%d saatir bu oyunu oynuyorsunuz. Biraz dinlenmek i�in gerekli ad�mlar� izleyin."
#define STRMSG_070628_0002				"�ok uzun zamand�r oynuyorsunuz. Bu sa�l���n�z i�in zararl�d�r. L�tfen sa�l���n�za dikkat edin ve oyunu kapat�p dinlenin. Bu sizin yarar�n�zad�r."
#define STRMSG_070628_0003				"Bu oyunu daha fazla oynaman�z art�k sa�l���n�z a��s�ndan kritik olacakt�r. �imdi oyunu kapat�p sa�l���n�za dikkat edin. Aksi taktirde sa�l���n�z etkilenebilir ve oyun geliriniz %0 olacak. Oyun geliriniz oyun kapat�ld�ktan 5 saat sonra normale d�necektir."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\ arenaya girmeye yasakl�d�r."
#define STRMSG_070711_0001 "\'%s\ arenaya girmeye yasakl�d�r (kalan s�re: %d dakika)"
#define STRMSG_070711_0002 "%d dakikal���na arenaya girmeniz yasaklanm��t�r."
#define STRMSG_070711_0003 "Arenaya girme ysa��n�z sona ermi�tir."
#define STRMSG_070711_0004 "\'%s\ i�in arenaya giri� yasaklanm��t�r."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (d���k-geni�)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (orta-geni�)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (y�ksek-geni�)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Bu komut ulus se�imi yap�ld�ktan sonra kullan�labilir."
#define STRMSG_070830_0002                                   "Se�ilen ulusun konferans odas� haritas� (%d) bulunamad�."
#define STRMSG_070830_0003                                   "Konferans odas�na girebilecek kullan�c� say�s�: %d"
#define STRMSG_070830_0004                                   "'%s' zaten giri� izni listesine eklenmi�."
#define STRMSG_070830_0005                                   "'%s' giri� iznine sahip de�il."
#define STRMSG_070830_0006                                   "'%s' ge�erli bir karakter de�il."
#define STRMSG_070830_0007                                 "'%s' konferans giri� izinlileri listesine eklenemedi. (Maksimum %d ki�i)"
#define STRMSG_070830_0008                                   "'%s' konferansa girmeye izinli olarak belirlendi."
#define STRMSG_070830_0009                                   "Konferans odas�na giri� isni verildi."
#define STRMSG_070830_0010                                   "Konferans odas�na giri� izni iptal edildi."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s sana hediye olarak %s g�nderdi."
#define STRMSG_071115_0002									"Hediye listesi: \'%s (%d par�a)\'"
#define STRMSG_071115_0003									"\\y%s send a present to %s.  Present is  %s. Please check the warehouse."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"�tiraz sistemi y�r�rl�kte de�il. M��teri merkezini kullan�n: http://support.airrivals.org"
#define STRMSG_071120_0002									"itiraz sistemi aktif edildi."
#define STRMSG_071120_0003									"�tiraz sistemi sonu�land�."
#define STRMSG_071120_0004									"�tiraz sistemi %s den %s e kadar ba�layacakt�r."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s sana hediye olarak %s(%d) g�nderdi. Sto�unuzdan kontrol edin."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"��z�n�rl�k ayarlar� ge�erli de�il. L�tfen tekrar kontrol edin."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'%s' blok ayar�nda hata var. Hata kodu (%d)"
#define STRMSG_080201_0002									"'%s' hesab� blok edildi. [Blok Biti� Tarihi: %s]"
#define STRMSG_080201_0003									"'%s' hesab� blok listesinde mevcut de�il. Hata Kodu (%d)"
#define STRMSG_080201_0004									"'%s' hesab�n�n bloklanmas�nda hata olu�tu. Hata Kodu (%d)"
#define STRMSG_080201_0005									"'%s' hesab� blok listesinden ��kar�ld�." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (d���k-geni�)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (orta-geni�)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (y�ksek-geni�)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), [%15s:%4d] Arena Sunucusuna ba�lan�lamad�. Yeniden ba�lan�l�yor\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Arena Sunucusuna ba�lan�ld�.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "[%15s:%4d] Arena Sunucusuna ba�lant� sonland�. Yeniden ba�lan�lmaya �al���l�yor.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X)  %s[%s] den al�nd�\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Bilinmeyen Hata@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "\\y%d Nolu Arena bekleme odas�na aktivite �zelli�i verildi."
#define STRMSG_ARENAEVENT_080310_0002                    "\\y%d Nolu Arena bekleme odas�ndan aktivite �zelli�i kald�r�ld�."
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Arena �zelli�i verme ba�ar�s�z.\r\n"
#define STRMSG_080428_0001					"%s kapat�ld�"          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ������ �� DB�� �(�� �� ���� ���� �� ������) - 
#define STRMSG_080430_0001					"Se�ilen sunucu yeni karakter olu�turulmas�na izin verilmeyen bir sunucudur."

// 2008-06-13 by dhjin, EP3 ���� �� ���� - 
#define STRMSG_080613_0001					"%s tugay�na giri� izni reddedildi."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Hatas�] B�yle bir (QP_xxx)DB  s�re� tarama fonksiyonu yok !! TaramaTipi(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRMSG_081230_0001					"\\y%s i�in %d dakikal���na sohbet k�s�tlamas� getirildi.\\y"
#define STRMSG_081230_0002					"\\yLider sana, %d dakikal���na sohbet k�s�tlamas� getirdi.\\y"
#define STRMSG_081230_0003					"\\ySohbet k�s�tlamas� kald�r�ld�.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D �� ����� ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - ������� ��, STRMSG_090831_0001�� �������� �
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Hackshield y�kle"
#define STRMSG_090831_0002					"nProtect y�kle"// 2015-03-11 by shchoi Gameforge4D nProtect ����â ����
#define STRMSG_090831_0003					"�ptal et"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - 
#define STRMSG_090902_0001					"http://tr.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �� �(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (d���k)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (orta)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (y�ksek)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (d���k)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (orta)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (y�ksek)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (d���k)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (orta)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (y�ksek)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ���� ������ �� ��� ��
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Kay�ts�z sunucu (yasad��� �zel bir sunucu olabilir.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Veri taban� ba�lant�s� kurulurken bir hata olu�tu."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Onay i�lemi ba�ar�yla tamamland�"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Sunucu IP kaydedildi fakat bir sonraki onay i�lemi reddedildi."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows sunucusunu kapatma komutu verildi."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ���� �����  ��

// 1�� 

#define STRMSG_120330_0001					"%s K�l Yolu'ndaki Sakl� Yer'e giden ���nlanma portal�n� etkinle�tirir."
#define STRMSG_120330_0002					"%s K�l Yolu'nda tecr�be puanlar�n�n %%%%100 art���n� (1 saatlik Happy Hour etkinli�i) etkinle�tirir."
#define STRMSG_120330_0003					"%s K�l Yolu'nda e�ya d���rme oran�n� %%%%100 art���n� (1 saatlik Happy Hour etkinli�i) etkinle�tirir."
#define STRMSG_120330_0004					"%s K�l Yolu'nda e�ya d���rme oran�n�n/ tecr�be puanlar�n�n / SPI'nin %%%%100 art���n� (1 saatlik Happy Hour etkinli�i) etkinle�tirir."
#define STRMSG_120330_0005					"%s K�l Yolu'ndaki silah d�kkan�n� etkinle�tirir."
#define STRMSG_120330_0006					"%s Hiper Kart D�kkan�'n� etkinle�tirir."
#define STRMSG_120330_0007					"%s K�l Yolu'ndaki Kit D�kkan�'n� etkinle�tirir."
#define STRMSG_120330_0008					"%s K�l Yolu'na devasa bir canavar �a��r�r."
#define STRMSG_120330_0009					"Kristal kayboldu."

// 2�� 

#define STRMSG_120508_0001					"%s %d karakterinin Bat�k Vaha'da elde etti�i sava� puan� kadar sava� puan� al�r."
#define STRMSG_120508_0002					"%s Bat�k Vaha'ya bir patron canavar �a��r�r."
#define STRMSG_120508_0003					"%s, Bat�k Vaha'da tecr�be puanlar�n� %%%%150 oran�nda (indirimli saat etkinli�i 1 saat s�rer) etkinle�tirir."
#define STRMSG_120508_0004					"%s, Bat�k Vaha'da nesne d��me oran�n�n %%%%150 (indirimli saat etkinli�i 1 saat s�rer) art���n� etkinle�tirir."
#define STRMSG_120508_0005					"%s Bat�k Vaha'da nesne d���rme oran�n�n/ tecr�be puanlar�n�n / SPI'nin %%%%150 art���n� (1 saatlik Happy Hour etkinli�i) etkinle�tirir."
#define STRMSG_120508_0006					"%s Bat�k Vaha'da antik buz elde eder."
#define STRMSG_120508_0007					"%s Bat�k Vaha'da geli�mi� E�ya D�kkan�'n� etkinle�tirir."
#define STRMSG_120508_0008					"%s Bat�k Vaha'da Kit D�kkan�'n� etkinle�tirir."
#define STRMSG_120508_0009					"%s Bat�k Vaha'da Hiper Kart D�kkan�'n� etkinle�tirir."
#define STRMSG_120508_0010					"%s Bat�k Vaha'da Silah D�kkan�'n� etkinle�tirir."
#define STRMSG_120508_0011					"%s Bat�k Vaha'daki Sakl� Yer'e giden ���nlanma portal�n� etkinle�tirir."

#define STRMSG_120712_0001					"18�� �� ���� ����� ���� ���� ���� ��, %d ��  ������ ���."		// 2012-07-11 by hskim, ������ ��

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ���� ���� %d�� ����."
#define STRMSG_121005_0002					"\\y��� �� PC�� ������ ���."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� ����� ������ - ����� ���� ��������(����)
#define STRMSG_121126_0001					"\\yKomut: Do�rudan kristallerle ilgili olan t�m giri�imler sava� esnas�nda yasakt�r.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX �� ������
#define STRMSG_121129_0001					"\\y� �� �� �� ���� ��.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC �������� ���� �����
#define STRMSG_130121_0001					"\\c Sistem NGC birlikleri taraf�ndan ele ge�irildi. Tasfiye ba�lad�."
#define STRMSG_130121_0002					"\\cKe�if Erleri:\\c \\rNGC Kontrol Birimi\\r g��lendirildi."
#define STRMSG_130121_0003					"\\cKe�if Erleri:\\c \\rNGC Kontrol Birimi\\r yok edildi."
#define STRMSG_130121_0004					"\\cEmir:\\c \\rGomora'n�n\\r kalkanlar� devrede. Kalkanlar� devre d��� b�rakmak i�in \\rNGC Kontrol Birimleri'ni\\r yok et."
#define STRMSG_130121_0005					"\\cEmir:\\c \\rGomora'n�n\\r kalkanlar� indi! �imdi sald�r�n!"
#define STRMSG_130121_0006					"\\cEmir:\\c \\rGomora\\r yok edildi! �leri!"
#define STRMSG_130121_0007					"\\cEmir:\\c \\rGomora\\r imha edilmeli."
#define STRMSG_130121_0008					"\\c\\rNGC Kontrol Birimi'ne\\r fazla y�kleme yap�larak \\c[%s] etkinle�tirildi."
#define STRMSG_130121_0009					"\\y[NGC Karakol �ss� Sistemi]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������  - ������ ᱸ ����� ����
#define STRMSG_130422_0001					"\\y%s %d Arena'da kullan�lamaz. E�ya depoya geri g�nderildi.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �� ����� - STRMSG �
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gG�r�n�m kart�, g�r�n�m kart� koleksiyonuna eklendi.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gG�r�n�m kart�n [%2d] kez kullan�ld�.\\g"
#define STRMSG_130531_0003					"\\g[%s] G�r�n�m kart�n maksimum uygulamaya ula�t�. [\\c%s\\c] alacaks�n.\\g"
#define STRMSG_130531_0004					"G�r�n�m kart�n�n s�resi doldu ve ilgili de�erler silindi. Art�k motorun ku�anm�� durumda de�il."
#define STRMSG_130531_0005					"\\yMotor ku�an�lmam��. �ehre geri ���nlanacaks�n.\\y"
#define STRMSG_130531_0006					"\\gZ�rh�na uygulanm�� olan g�r�n�m kartlar�n� kullanamazs�n.\\g"
#define STRMSG_130531_0007					"\\gG�r�n�m de�i�ti.\\g"
#define STRMSG_130531_0008					"\\r[%s] g�r�n�m kart� s�resi doldu.\\r"
#define STRMSG_130531_0009					"\\yG�r�n�m kartl� z�rhlar sat�lamaz.\\y"
#define STRMSG_130531_0010					"\\yGear t�rleri farkl�.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ���� ����� �� - STRMSG �
#define STRMSG_130708_0001					"\\cEmir:\\c  NGC kalkanlar� etkinle�tirildi. \\rGomora'n�n\\r kalkanlar�n� etkisiz hale getirmek i�in \\rNGC Kontrol Birimi'ni\\r, imha et."
#define STRMSG_130708_0002					"\\cEmir:\\c NGC askeri �ss�n savunmas� durduruldu. �imdi sald�r�n!"
#define STRMSG_130708_0003					"\\cKe�if erleri:\\c\\rNGC Kalkan olu�turucu\\r tespit edildi."
#define STRMSG_130708_0004					"\\cKe�if erleri:\\c\\rNGC Kalkan olu�turucu\\r imha edildi."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, � �� �������
#define STRMSG_130726_0001					"Karakter zaten bu ulusa ait."
#define STRMSG_130726_0002					"Karakter lider veya lider yard�mc�s�, bu nedenle ulus de�i�tirilemiyor."
#define STRMSG_130726_0003					"Karakter bir tugayda, ulus de�i�tirilemiyor."
#define STRMSG_130726_0004					"Ulus de�i�tirebilecek bir karakterin yok."
#define STRMSG_130726_0005					"Ulus de�i�tirilemedi [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Ulus ba�ar�yla de�i�tirildi AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"B�yle bir hesap yok."
#define STRMSG_130726_0008					"Oturumun a��k, ulus de�i�tirilemiyor."


// 2013-08-30 by bckim, �����������
#define STRMSG_130830_0001					"\\y%s oyuncusunun u�u� ayr�cal�klar� ulus liderinden al�nd�.\\y"
#define STRMSG_130830_0002					"\\yU�u� ayr�cal�klar� ulus liderinden al�nd�.\\y"
#define STRMSG_130830_0003					"\\yU�u� ayr�cal�klar� ulus lideri taraf�ndan %s oyuncusundan al�nd�.\\y"
// End. 2013-08-30 by bckim, �����������

// 2013-08-28 by bckim, �������� ����
#define STRMSG_130828_0001					"\\y[%s \\y%s\\y oyuncusunun yok edilmesine kat�ld�.]\\y"
#define STRMSG_130828_0002					"\\y[%s \\y%s\\y kar��s�nda ilk sald�r�y� ger�ekle�tirdi.]\\y"
#define STRMSG_130828_0003					"\\y[%s toplamda \\y%s\\y oyuncusuna kar�� en fazla sald�r� ger�ekle�tirdi.]\\y"
#define STRMSG_130828_0004					"\\y[%s \\y%s\\y oyuncusuna kar�� belirleyici darbeyi vurdu.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n yenildi."
// End. 2013-08-28 by bckim, �������� ����

// 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����
#define STRMSG_130814_0001					"\\y[%s] NGC Strateji Puan� Sava��'n� kazand�.\\y"
// end 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����

// 2014-03-12 by bckim, ���ן��(��������)
#define STRMSG_130318_0001					"%s patronu kapat�lm�� bir b�lgeye �a��rd�."
#define STRMSG_130318_0002					"%s patronu harabelere �a��rd�."
// End. 2014-03-12 by bckim, ���ן��(��������)

// 2014-03-18 by bckim, ���� ON/OFF
#define STRMSG_130318_0003					"\\y�u an m�zayede evini kullanamazs�n.\\y"
// End. 2014-03-18 by bckim, ���� ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
