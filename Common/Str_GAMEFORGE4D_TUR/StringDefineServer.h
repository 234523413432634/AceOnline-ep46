
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Sunucu aktif edilmemiþ."
	#define STRERR_S_ATUMEXE_0002 "Soket Ön-Sunucu Tarafýndan Kapatýldý!"
	#define STRERR_S_ATUMEXE_0003 "Otomatik yükseltim baþarýsýz. \r\n Lütfen oyunu tekrar yükleyiniz. \r\n"
	#define STRERR_S_ATUMEXE_0004 "HATA %s(%#04X) alýndýðý yer %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Bilinmeyen Hata: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Ýndirme sunucusuna baðlanýlamadý."
	#define STRERR_S_ATUMEXE_0007 "Ýndirim dosyalarýnýn boyutu bilinmiyor."
	#define STRERR_S_ATUMEXE_0008 "Upgrade dosyasý indirilemiyor."
	#define STRERR_S_ATUMEXE_0009 "Sistem yeterli hafýza veya kaynaða sahip deðil."
	#define STRERR_S_ATUMEXE_0010 ".exe dosyasý geçersiz."
	#define STRERR_S_ATUMEXE_0011 "Dosya bulunamadý."
	#define STRERR_S_ATUMEXE_0012 "Ýlgili klasör yolu bulunamadý."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Güncelleme tamamlandý"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Lütfen bir sunucu seçin."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Silinecek dosyalar listesi güncelleniyor v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Geçici dosyalar siliniyor"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Notlar güncelleniyor"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Güncelleme tamamlandý (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Ýþlem dosyasýný seçin"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Ýþlem yolunu seçin"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Yüklenme iptal edildi."
	#define STRMSG_S_ATUMLAUNCHER_0009 "Yükleme bitti."
	#define STRMSG_S_ATUMLAUNCHER_0010 "Güncelleniyor.. v %s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "%s dosyasý oluþturulamadý"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Güncelleniyor.. v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "%s dosya bilgilerine ulaþýlýyor"
    #define STRMSG_S_ATUMLAUNCHER_0014 "VTC koruyucu güncelleme"				// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Hata] Parametre Sayým Hatasý, Sayým(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Hata] Mutex Hatasý\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Hata] Yürütme Tipi Hatasý, Tip(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Hata] Kodaçma ID Hatasý, KodaçmaID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Ön-Sunucuya baðlanamadý."
	#define STRERR_S_ATUMLAUNCHER_0005 "Sunucuya baðlanýlamadý."
	#define STRERR_S_ATUMLAUNCHER_0006 "Soket Ön-Sunucu Tarafýndan Kapatýldý!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Bildirim Dosyasý Hatasý!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Otomatik upgrade baþarýsýz. \\r\\n Lütfen oyunu tekrar yükleyiniz. \\r\\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Þu anda bütün sunucular kapalý durumda."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s sorgu altýnda..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Bütün sunucular sorgulanmaktadýr. Lütfen daha sonra tekrar girmeyi deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0013 "HATA %s(%#04X) alýndýðý yer %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Geçersiz giriþ IDsi veya þifre girdiniz.   Lütfen kayýtlý giriþ IDnizi ve þifrenizi giriniz."
	#define STRERR_S_ATUMLAUNCHER_0015 "Giriþ iþleminde hata"
	#define STRERR_S_ATUMLAUNCHER_0016 "Kullanýcý IDsi girilmemiþ"
	#define STRERR_S_ATUMLAUNCHER_0017 "Çift giriþ"
	#define STRERR_S_ATUMLAUNCHER_0018 "F sunucusu þu anda çalýþmýyor."
	#define STRERR_S_ATUMLAUNCHER_0019 "I Sunucusu þu anda çalýþmýyor."
	#define STRERR_S_ATUMLAUNCHER_0020 "Servis geçici olarak durduruldu. \n\n Lütfen daha sonra tekrar deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0021 "Çok fazla oyuncu çevrimiçi. \n\n Lütfen daha sonra tekrar giriþ yapmayý deneyiniz."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Hesabýnýz þu anda bloke durumda. \n Süre : %s\n\nE-mail detaylar için www.airrivals.com"
	#define STRERR_S_ATUMLAUNCHER_0023 "Ýstemci versiyonu doðru deðil. \n\n Lütfen oyunu tekrar indiriniz."
	#define STRERR_S_ATUMLAUNCHER_0024 "HATA: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Ýndirme sunucuna baðlanamadý."
	#define STRERR_S_ATUMLAUNCHER_0026 "Ýndirim dosyalarýnýn (%s) boyutu bilinemez."
	#define STRERR_S_ATUMLAUNCHER_0027 "Ýndirim dosyalarýnýn boyutu bilinmiyor."
	#define STRERR_S_ATUMLAUNCHER_0028 "Upgrade dosyasý indirilemiyor."
	#define STRERR_S_ATUMLAUNCHER_0029 "Upgrade dosyasý bulunmamakta."
	#define STRERR_S_ATUMLAUNCHER_0030 "Seçilen sunucu sorgu altýndadýr. Lütfen daha sonra tekrar giriþ yapmayý deneyiniz."
	#define STRERR_S_ATUMLAUNCHER_0031 "Sistem yeterli hafýza veya kaynaða sahip deðil."
	#define STRERR_S_ATUMLAUNCHER_0032 ".exe dosyasý geçersiz."
	#define STRERR_S_ATUMLAUNCHER_0033 "Dosya bulunamadý."
	#define STRERR_S_ATUMLAUNCHER_0034 "Ýlgili klasör yolu bulunamadý."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, ÇöÀç ½´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÇÑ »çÇ× ¿¡¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î


	#define STRMSG_S_050506		"\'%s\''s hesabý bloke edilmiþ.\n sebep: %s\n süre: %s~%s\n\nDetaylý bilgi için http://support.airrivals.org fadresini ziyaret edin."
	#define STRMSG_S_050930		"Lütfen oyunu yeniden yükleyiniz. \nURL: %s\nson versiyon:"
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
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' eklendi ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'parça, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'parça'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' silindi ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'parça, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'parça'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Ekle ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'parça, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'parça'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Depozit ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'parça, toplam ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'parça'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Ýyileþme ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'parça, toplam' + CAST(l.CurrentCount AS VARCHAR(10)) + 'parça'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'oyun zamaný \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', whole \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', oyun zamaný: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Mevcut deðil)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Hesap blok edildi."
	#define STRMSG_S_SCADMINTOOL_0030 "Sohbet yasaklandý"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s sunucu"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s sunucu,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Hesap hacizli"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Bu hesabýn bloðunu kaldýrmak istediðinize emin misiniz?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d saniye)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d kazandý %d kaybetti"
	#define STRMSG_S_SCADMINTOOL_0042 "Hesaba oyundan çýkarmak ve blok etmek istediðinize emin misiniz?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s nesne"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Not: %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Kullanýcý sayýsý : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] mesaj aldý: %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] kullanýcý sayýsý : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] AlanSunucusu durumu : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Sunucu ile baðlantý kesildi\nSoket Adý: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Ýlgili hesap bilgileri yüklenemedi."
	#define STRERR_S_SCADMINTOOL_0001 "Hesap bilgileri deðiþtirilemedi."
	#define STRERR_S_SCADMINTOOL_0002 "Þifrenizi girin"
	#define STRERR_S_SCADMINTOOL_0003 "Þifre doðrulanamadý"
	#define STRERR_S_SCADMINTOOL_0004 "Giriþ adýnýzý yazýn"
	#define STRERR_S_SCADMINTOOL_0005 "Ön sunucu baþlatýlamadý."
	#define STRERR_S_SCADMINTOOL_0006 "Ön sunucuya baðlanýlamadý!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "HATA: Ýlgili protokol mevcut deðil."
	#define STRERR_S_SCADMINTOOL_0009 "Kullanýcý adý girin"
	#define STRERR_S_SCADMINTOOL_0010 "Sebep girin"
	#define STRERR_S_SCADMINTOOL_0011 "Deneyim puaný ayarlama hatasý: Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Maksimum kayýt sayýsý aþýldý. \r\n\r\n Lütfen maksimum kayýt sayýsý veya arama koþullarýný deðiþtirin."
	#define STRERR_S_SCADMINTOOL_0013 "Veritabaný ile baðlantý kurulamadý."
	#define STRERR_S_SCADMINTOOL_0014 "Baðlý deðil"
	#define STRERR_S_SCADMINTOOL_0015 "Baðlanýldý"
	#define STRERR_S_SCADMINTOOL_0016 "Güncelleniyor"
	#define STRERR_S_SCADMINTOOL_0017 "Giriþ yapýldý"
	#define STRERR_S_SCADMINTOOL_0018 "Karakter seçiliyor"
	#define STRERR_S_SCADMINTOOL_0019 "Oyun oynuyor"
	#define STRERR_S_SCADMINTOOL_0020 "Bilinmiyor"
	#define STRERR_S_SCADMINTOOL_0021 "%s(%s:%d) veritabanýna baðlanýlamadý."
	#define STRERR_S_SCADMINTOOL_0022 "Nesne ekleme baþarýsýz"
	#define STRERR_S_SCADMINTOOL_0023 "Bloke hesap bulunamadý."
	#define STRERR_S_SCADMINTOOL_0024 "Önce hesaptan çýkýn ve deðiþiklik için blok edin."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(para) eklenemez."
	#define STRERR_S_SCADMINTOOL_0026 "Seçili nesne zaten mevcut, miktarý deðiþtirin."
	#define STRERR_S_SCADMINTOOL_0027 "Nesne bulmada hata"
	#define STRERR_S_SCADMINTOOL_0028 "Karakterin sahip olduðu SPI(para) silinemez."
	#define STRERR_S_SCADMINTOOL_0029 "Bu nesneyi silmek istiyor musunuz?"
	#define STRERR_S_SCADMINTOOL_0030 "Nesne silme baþarýsýz."
	#define STRERR_S_SCADMINTOOL_0031 "Nesne modifikasyonu baþarýsýz."
	#define STRERR_S_SCADMINTOOL_0032 "Hesap adý girin"
	#define STRERR_S_SCADMINTOOL_0033 "Hesap mevcut deðil. (Hesap muhtemelen bloke edilmiþ olabilir)"
	#define STRERR_S_SCADMINTOOL_0034 "Hesap veya karakter mevcut deðil."
	#define STRERR_S_SCADMINTOOL_0035 "Karakter bilgi taramasýnda hata."
	#define STRERR_S_SCADMINTOOL_0036 "Uygun karakter mevcut deðil."
	#define STRERR_S_SCADMINTOOL_0037 "Karakter güncellemede hata."
	#define STRERR_S_SCADMINTOOL_0038 "Karakter bilgileri baþarýyla güncellendi."
	#define STRERR_S_SCADMINTOOL_0039 "Bir nesne seçin."
	#define STRERR_S_SCADMINTOOL_0040 "Nesne sayýsýný seçin."
	#define STRERR_S_SCADMINTOOL_0041 "Ýlgili nesne 5 parça olarak oluþturulabilir."
	#define STRERR_S_SCADMINTOOL_0042 "Mesajý yazýn."
	#define STRERR_S_SCADMINTOOL_0043 "Not (mesaj) gönderilemedi."
	#define STRERR_S_SCADMINTOOL_0044 "%s: server durumu (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Sunucusu baþlatýlmadý.."
	#define STRERR_S_SCADMINTOOL_0046 "Alan Sunucusu çalýþýr durumda deðil."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer durumu : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÊ - ¾îµå¹Î Åø ÆÊ ±¼­ »ç¿ëµÂ MSG
#define STRERR_S_SCADMINTOOL_0048 "Bu eþya yuvasý Ö.E.D.'nde bulunuyor. Yuvayý \socket komutuyla silebilirsin."
#define STRERR_S_SCADMINTOOL_0049 "Ö.E.D.'deki deðiþiklik kaydý yapýlamadý (ancak deðiþiklik yapýldý)."
#define STRERR_S_SCADMINTOOL_0050 "Ö.E.D. bilgileri yüklenemedi."
#define STRERR_S_SCADMINTOOL_0051 "Kuþanýlan eþya yuvasý silinemedi."
#define STRERR_S_SCADMINTOOL_0052 "Kuþanýlan eþyalarýn gizli bonus uygulamasý baþarýsýz oldu."
#define STRERR_S_SCADMINTOOL_0053 "Ö.E.D.'nin eþya yuvasý deðiþikliði baþarýsýz oldu."
#define STRERR_S_SCADMINTOOL_0054 "Ö.E.D.'nin bilgileri güncellenemedi."
#define STRERR_S_SCADMINTOOL_0055 "Ö.E.D. seviye bilgilerinin yüklenmesi baþarýsýz oldu."

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
	#define STRMSG_S_SCAT_COLNAME_0055 "Ýkili Tipi (1-1 Tipi)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Top Tipi (1-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Tüfek Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Mitralyöz Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Fýrlatýcý Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Kütle Sürücü Tipi (1-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Roket Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Füze Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Paket Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Mayýn Tipi (2-1 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Kalkan Tipi (2-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Kukla Tipi (2-2 Tipi)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Toplayýcý Tipi (2-2 tipi)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Tuzakçý Tipi (2-2 tipi)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Defans Tipi"
	#define STRMSG_S_SCAT_COLNAME_0070 "Destep Ekipman Tipi"
	#define STRMSG_S_SCAT_COLNAME_0071 "Enerji Tipi"
	#define STRMSG_S_SCAT_COLNAME_0072 "Metal Tipi"
	#define STRMSG_S_SCAT_COLNAME_0073 "Kart Tipi"
	#define STRMSG_S_SCAT_COLNAME_0074 "Upgrade Tipi"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tank Tipi"
	#define STRMSG_S_SCAT_COLNAME_0076 "Mermi Tipi"
	#define STRMSG_S_SCAT_COLNAME_0077 "Görev Ýçin"
	#define STRMSG_S_SCAT_COLNAME_0078 "Radar Tipi"
	#define STRMSG_S_SCAT_COLNAME_0079 "Bilgisayar Tipi"
	#define STRMSG_S_SCAT_COLNAME_0080 "Þans Kartý Tipi"
	#define STRMSG_S_SCAT_COLNAME_0081 "Upgrade Hasar Önleyici Tipi"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Barutçu Tipi"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail Tüfek Tipi"				// 2005-08-02 by cmkwon
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
	#define STRMSG_S_SCAT_COLNAME_0094 "Yönetici"

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
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), LogServer[%15s:%4d] e baðlanýlamadý. Tekrar baðlan\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Log Sunucusuna giriþ yapýldý.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Sunucusu [%15s:%4d] ile baðlantý kesildi. Yeniden baðlanýlýyor.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), [%15s:%4d] Ön Sunucusuna baðlanýlamadý. Tekrar baðlanýlýyor\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Ön Sunucuya giriþ yapýldý. \n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X)  %s[%s] den alýndý\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Bilinmeyen hata@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "[%15s:%4d] ön sunucusu ile baðlantý kesildi. Tekrar baðlanýlýyor. \r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Hata] WndProc(), IMServer[%15s:%4d] e baðlanýlamadý. Tekrar baðlan\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "IM Sunucusuna giriþ yapýldý.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Sunucusu [%15s:%4d] ile baðlantý kesildi. Yeniden baðlanýlýyor.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s[%s] den %s(%#04X) alýndý \r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Bilinmeyen Hata@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Alan Sunucu Sorgularýnda böyle bir veritabaný sorgusu yoktur%d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Ýlgili nesne mevcut deðil."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' gitmek için baþvurdu, nesne vaat edildi."
	#define STRMSG_S_F2DBQUERY_0003 "verildi. Stoðunuzu kontrol etmek için F5 e basýnýz."
	#define STRMSG_S_F2DBQUERY_0004 "%s(%d) yeteneði eklendi."
	#define STRMSG_S_F2DBQUERY_0005 "Ýlgili nesne mevcut deðil."
	#define STRMSG_S_F2DBQUERY_0006 "Nesne satýn alýnamadý."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Þehir iþgal savaþý baþlama : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Tugaya katýlým : GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Þehir iþgali savaþý yaratýk patlamasý : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Hasar toplamý ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Þehir iþgali savaþý : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) Á¡·ÉÀü½Ã°£(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Hata] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d dakika sonra \"%s\" þehir iþgali savaþý baþlayacaktýr."
	#define STRMSG_S_F2CITYWAR_0007 "%d dakika sonra \"%s\" þehir iþgali savaþý sona erecektir."
	#define STRMSG_S_F2CITYWAR_0008 "Canavar þehir iþgali savaþý (%s) için teslim olmaya çaðrýldý: NPC iþgali"
	#define STRMSG_S_F2CITYWAR_0009 "Canavar þehir iþgali savaþý (%s) için teslim olmaya çaðrýldý : %s tugay iþgali"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" þu an \"%s\" i iþgal ediyor."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" tugayý þu an \"%s\" i iþgal ediyor."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Görev yükleme baþarýsýz"
	#define STRMSG_S_F2QUEST_0001 "Görev yüklenmedi. \r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Test sunucusu ayarlandý! \r\n\r\nLoadFieldServerDataDebug() temizlenmeli!"
	#define STRMSG_S_F2NOTIFY_0000 "sýçratma %d: %d den %5.2f(%2.1f%%) e"
	#define STRMSG_S_F2NOTIFY_0001 "canavar sýçratma %d: %s den %5.2f e"
	#define STRMSG_S_F2NOTIFY_0002 "1. tip"
	#define STRMSG_S_F2NOTIFY_0003 "2. tip"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Hatalý silah türü! Lütfen yöneticiye bildirimde bulunun."
	#define STRMSG_S_F2NOTIFY_0007 "1-1tipi: %4.1f vs %4.1f -> Saldýrý þansý %2.2f%% azaldý"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s baþarýsýz, þans(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s baþarýsýz, þans(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s baþarýsýz, þans(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2tipi: %4.1f vs %4.1f -> Hasar %2.2f%%(%4.1f->%4.1f) azaldý"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, verdi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, aldý %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), verdi %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, aldý %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Kukla baþarýsýz: Þans yetersiz > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Kalan kukla [%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Mermi bilgileri mevcut deðil. Lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0019 "Mermi kalibre bilgisi mevcut deðil. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Mermi bilgileridir %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Olay devam ederken ýþýnlamamümkün deðildir."
	#define STRMSG_S_F2NOTIFY_0022 "Öldürülmüþ durumdayken ýþýnlama mümkün deðildir."
	#define STRMSG_S_F2NOTIFY_0023 "Birlik savaþý esnasýnda ýþýnlama mümkün deðildir."
	#define STRMSG_S_F2NOTIFY_0024 "Harita oluþturmada hata! Lütfen yöneticiye bildiriniz."
	#define STRMSG_S_F2NOTIFY_0025 "Harita oluþturma hatasý! lütfen yöneticiye bildirin! %d de, %d nolu ýþýnlama hedef indeksi mevcut deðil!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Birlik savaþý bitmeden ýþýnlama mümkün deðildir."
	#define STRMSG_S_F2NOTIFY_0027 "IÞINLAMA(%04d)  iyileþtirme mümkün deðil Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> %10s karakteri %5.2f hasarý aldý"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> %10s karakteri %5.2f hasarý verdi."
	#define STRMSG_S_F2NOTIFY_0030 "1 -> %10s karakteri %5.2f hasarý verdi."
	#define STRMSG_S_F2NOTIFY_0031 "1 -> %10s karakteri %5.2f hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> %10s karakteri %5.2f hasarý aldý"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> %10s karakteri %5.2f hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> %3d canavarý  %5.2f(%d) hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> %10s karakteri %5.2f hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> %10s karakteri %5.2f kukla hasarý verdi."
	#define STRMSG_S_F2NOTIFY_0037 "2 -> %3d canavarý %5.2f hasarý aldý"
	#define STRMSG_S_F2NOTIFY_0038 "TAHRÝP-> %10s karakteri %5.2f hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0039 "TAHRÝP-> %10s karakteri %5.2f kukla hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0040 "TAHRÝP-> %10s canavarý %5.2f hasarý verdi"
	#define STRMSG_S_F2NOTIFY_0041 "Durum baþlatma baþarýlý"
	#define STRMSG_S_F2NOTIFY_0042 "Ölü durumdayken bunu kullanamazsýnýz"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO mevcut deðil"
	#define STRMSG_S_F2NOTIFY_0044 "Upgrade \g baþarýlý\g."
	#define STRMSG_S_F2NOTIFY_0045 "Upgrade \r baþarýsýz\r."
	#define STRMSG_S_F2NOTIFY_0046 "Tugaya ait deðildir."
	#define STRMSG_S_F2NOTIFY_0047 "Zaten istek için bekleme durumunda."
	#define STRMSG_S_F2NOTIFY_0048 "Lütfen daha sonra tekrar deneyin."
	#define STRMSG_S_F2NOTIFY_0049 "Siz veya diðer kiþi tugay lideridir."
	#define STRMSG_S_F2NOTIFY_0050 "Zaten bir tugay savaþýnda."
	#define STRMSG_S_F2NOTIFY_0051 "Her iki tugay lideri de ayný haritada deðil."
	#define STRMSG_S_F2NOTIFY_0052 "Tüm birlik üyeleri ayný haritada deðil."
	#define STRMSG_S_F2NOTIFY_0053 "Tüm birlik üyeleri ayný haritada deðil."
	#define STRMSG_S_F2NOTIFY_0054 "Siz bu tugaya ait deðilsiniz."
	#define STRMSG_S_F2NOTIFY_0055 "Alýnan baþvurunun sahibi farklýdýr."
	#define STRMSG_S_F2NOTIFY_0056 "Siz veya diðer kiþi bir tugay lideri deðilsiniz."
	#define STRMSG_S_F2NOTIFY_0057 "Ýki tugay lideri de ayný haritada deðil."
	#define STRMSG_S_F2NOTIFY_0058 "Siz bu tugaya ait deðilsiniz."
	#define STRMSG_S_F2NOTIFY_0059 "Alýnan baþvurunun sahibi farklýdýr."
	#define STRMSG_S_F2NOTIFY_0060 "Siz veya diðer kiþi bir tugay lideri deðilsiniz."
	#define STRMSG_S_F2NOTIFY_0061 "Þehir iþgali savunma savaþý baþarýlý"
	#define STRMSG_S_F2NOTIFY_0062 "Görev ayarlarýnda hata. Lütfen yönetiye bildiriniz."
	#define STRMSG_S_F2NOTIFY_0063 "Bu nesne (%s) bu alanda kullanýlmaya uygun deðildir."
	#define STRMSG_S_F2NOTIFY_0064 "Motor terk edilemedi."
	#define STRMSG_S_F2NOTIFY_0065 "Nesne taþýma: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Yanlýþ nesne hareketi: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "OLAY(%d) yerine getirilemedi Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Harita olay bilgileri anormal! Lütfen yöneticiye bildirin!"
	#define STRMSG_S_F2NOTIFY_0069 "Ýlgili ýþýnlama hedefi mevcut deðil"
	#define STRMSG_S_F2NOTIFY_0070 "Nesne satýnalma hatasý. Lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0071 "Satýn almak istediðiniz yetenek þuanki seviyenizde veya daha düþük seviyededir."
	#define STRMSG_S_F2NOTIFY_0072 "Nesne hatasý. Nesne için yetenek satýn almak gerekli."
	#define STRMSG_S_F2NOTIFY_0073 "Nesne satma hatasý. Lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0074 "Nesne satýnalma hatasý. Lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0075 "\'Kredi nesnesi\' satýn alýndý."
	#define STRMSG_S_F2NOTIFY_0076 "Satýnalma listesi : \'%s(%dpieces)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Zaten partiye katýlmýþtýnýz."
	#define STRMSG_S_F2NOTIFY_0078 "Parti lideri iseniz katýlamazsýnýz."
	#define STRMSG_S_F2NOTIFY_0079 "Birlik savaþý devam ederken katýlamazsýn."
	#define STRMSG_S_F2NOTIFY_0080 "Tüm birlik personel bilgilerinin görüntülenmesi desteklenmemektedir!"
	#define STRMSG_S_F2NOTIFY_0081 "Harita olay bilgileri anormal! Lütfen yöneticiye bildirin!"
	#define STRMSG_S_F2NOTIFY_0082 "Bu hesap iþlem yapamaz."
	#define STRMSG_S_F2NOTIFY_0083 "%s in yükü aþýldý."
	#define STRMSG_S_F2NOTIFY_0084 "Olasý hareket kordinatý: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Kullanýcý:"
	#define STRMSG_S_F2NOTIFY_0086 "Maksimum 20 kiþi görüntülenebilir."
	#define STRMSG_S_F2NOTIFY_0087 "Ýlgili kullanýcý (%s) mevcut deðil."
	#define STRMSG_S_F2NOTIFY_0088 "Partiye ait deðil."
	#define STRMSG_S_F2NOTIFY_0089 "Þimdiki zaman: %d:%d, Artum zamaný: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Deðiþme zamaný: %d:%d, Artum zamaný: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "NPC sunucusuna baðlý deðil"
	#define STRMSG_S_F2NOTIFY_0092 "Ýlgili nesne (%d) mevcut deðil"
	#define STRMSG_S_F2NOTIFY_0093 "Sayýlamayan nesneler 10 parça ile sýnýrlýdýr."
	#define STRMSG_S_F2NOTIFY_0094 "\'%s\' Haritasýna baðlanan toplam kiþi sayýsý: %dpeople"
	#define STRMSG_S_F2NOTIFY_0095 "%s %s haritasýna eþzamanlý baðlantý: %d kiþi- '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "%s %s haritasýna eþzamanlý baðlantý: %d kiþi - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Þuanki harita kanalý: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Mermi bilgileri mevcut deðil. lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0099 "Mermi kalibre bilgileri mevcut deðil. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Mermi bilgileri mevcut deðil. lütfen yöneticiye bildirin."
	#define STRMSG_S_F2NOTIFY_0101 "Mermi kalibre bilgileri mevcut deðil. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Ýlgili kullanýcý (%s) mevcut deðil."
	#define STRMSG_S_F2NOTIFY_0103 "Ýlgili kullanýcý (%s) öldü."
	#define STRMSG_S_F2NOTIFY_0104 "Ýlgili kullanýcý (%s) mevcut deðil."
	#define STRMSG_S_F2NOTIFY_0105 "Standart Hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0106 "Standart Hesap iptal edildi."
	#define STRMSG_S_F2NOTIFY_0107 "Yenilmezlik aktif edildi."
	#define STRMSG_S_F2NOTIFY_0108 "Yenilmezlik modu kapatýldý."
	#define STRMSG_S_F2NOTIFY_0109 "Silah hasarý %5.0f%% deðiþtirilecek."
	#define STRMSG_S_F2NOTIFY_0110 "Nesne yeniden yüklendiðinde baþlatýlacak"
	#define STRMSG_S_F2NOTIFY_0111 "Nesne yeniden yüklendiðinde baþlatýlacak"
	#define STRMSG_S_F2NOTIFY_0112 "Ýlgili kullanýcý (%s) mevcut deðil"
	#define STRMSG_S_F2NOTIFY_0113 "Görünmezlik modu kapatýldý."
	#define STRMSG_S_F2NOTIFY_0114 "Görünmezlik modu aktif"
	#define STRMSG_S_F2NOTIFY_0115 "%s olayý devam etmemekte"
	#define STRMSG_S_F2NOTIFY_0116 "%s olayý baþlatýldý (büyütme:%4.2f, Olay zamaný:%3d minutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Standart premium Hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0118 "Premium hesap ayarý baþarýsýz"
	#define STRMSG_S_F2NOTIFY_0119 "Süper premium hesap olarak ayarla"
	#define STRMSG_S_F2NOTIFY_0120 "Bu þehir iþgali savaþýnýn olduðu harita deðil"
	#define STRMSG_S_F2NOTIFY_0121 "Þehir iþgali savaþý baþlatýlamadý"
	#define STRMSG_S_F2NOTIFY_0122 "Þehir iþgali savaþý bitirilemedi"
	#define STRMSG_S_F2NOTIFY_0123 "Gizlilik modu baþlatýldý"
	#define STRMSG_S_F2NOTIFY_0124 "Gizlilik modunda"
	#define STRMSG_S_F2NOTIFY_0125 "Harita geçerli deðil."
	#define STRMSG_S_F2NOTIFY_0126 "Mutlu saatler olaylarý baþladý  [geçen süre: %4dminute)]"
	#define STRMSG_S_F2NOTIFY_0127 "Mutlu saatler olaylarý bitti"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> %3d canavarýndan, %5.2f hasarý alýndý"
	#define STRMSG_S_F2NOTIFY_0129 "1tip -> %3d canavarýndan, %5.2f(kukla) hasarý alýndý"
	#define STRMSG_S_F2NOTIFY_0130 "\r %s\r yetkisi ile giriþ yapýldý."
	#define STRMSG_S_F2NOTIFY_0131 "Tamamlama kaidesi iþlenemdi %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "HATA@CharacterGameEndRoutine(): Parti personelini eleme baþarýsýz! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Durduruldu!"
	#define STRMSG_S_F2NOTIFY_0136 "CÝDDÝ HATA: Lütfen yöneticiye bildirin! Maðaza deðiþkeni tahsis hatasý!"
	#define STRMSG_S_F2NOTIFY_0137 "%s silindi."
	#define STRMSG_S_F2NOTIFY_0138 "Kullandýðýnýz kanal devre dýþý olduðundan canavarlar ve diðer fonksiyonlar kullanýlamaz."
	#define STRMSG_S_F2NOTIFY_0139 "Durduruldu. lütfen baþka kanal kullanýn."
	#define STRMSG_S_F2NOTIFY_0140 "Iþýnlama Nesne.[%s,%2d parça]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Hareket sayacý %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HP otomatik iyileþme durdu"
	#define STRMSG_S_F2NOTIFY_0143 "HP otomatik iyileþme durdu. Burasý iniþ yapmaya müsait deðil."
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f acil durum iyileþmesi"
	#define STRMSG_S_F2NOTIFY_0145 "Kademeli HP UP Durduruldu (kalan süre: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Kademeli DP UP Durduruldu (kalan süre: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Kademeli EP UP Durduruldu(kalan süre: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s olayý tamamlandý."
	#define STRMSG_S_F2NOTIFY_0149 "%s olayý devam etmektedir. (büyültme %4.2f, kalan:%3dminute)"
	#define STRMSG_S_F2NOTIFY_0150 "Komut çalýþýlmadý"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Tecrübe puaný bölüm hatasý (%s, %s(%d)): fToplamHasar(%d) < 0.0f or Boþ Vektör: %d, Mesafe(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Geçerli Oyun Baþlatým Mesaji deðil hatasý ÝstemciDurumu[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Geçerli Oyun Baþlatým Mesaji deðil hatasý ÝstemciDurumu[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "IÞINLANMA(%04d) davranýþý imkansýz. ÝþlemGörevSonucu(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Harita olay bilgisi normal deðil! Lütfen admine baþvurunuz! Güncel(%s, %s, %04d), Hedef(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) iyileþtirme mümkün deðil T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Harita olay bilgisi anormal! Yöneticiye bildiriniz. Þu anki (%s, %s, %04d), Hedef (%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "IÞINLAMA iyileþtirmesi mümkün deðil T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "OLAY(%d) iyileþtirme mümkün deðil (parti lideri) Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "IÞINLAMA(%04d) iyileþtirme mümkün deðil Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "OLAY (%d)  iyileþtirme mümkün deðil  Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "IÞINLAMA iyileþtirmesi mümkün deðil  T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Parti ýþýnlama baþarýsýz: %s -> mesafe: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "IÞINLAMA(%04d)  iyileþtirme mümkün deðil  Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> OK düðmesine çoklu týklama!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Görev yüklendi.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "IÞINLAMA(%s)  iyileþtirme mümkün deðil  HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "IÞINLAMA(%s)  iyileþtirme mümkün deðil  HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "CÝDDÝ HATA: Bu mesaj üyelerin ait olmadýðý alan sunucularýna gönderilmemeli. Kontrol edin\r\n"
	#define STRERR_S_F2NOTIFY_0019 "IÞINLAMA(%04d)  iyileþtirme mümkün deðil T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "IÞINLAMA(%s)  iyileþtirme mümkün deðil T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Tecrübe puanlarý"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Tecrübe puanlarýnýn yenilenmesi"
	#define STRMSG_S_F2EVENTTYPE_0003 "Nesne düþürme"
	#define STRMSG_S_F2EVENTTYPE_0004 "Nadir nesne düþürme"
	#define STRMSG_S_F2EVENTTYPE_0005 "Bilinmeyen olay"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Ön sunucuya giriþ yapýldý. \n"
	#define STRMSG_S_I2PRECONNECT_0001 "[%15s:%4d] ön sunucusu ile baðlantý kesildi. Yeniden baðlanmaya çalýþýlyor. \r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' zaten mevcut"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' zaten bir tugayda."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' zaten mevcut bir tugayýn adýdýr"
	#define STRMSG_S_I2NOTIFY_0003 "Tugay yükleme baþarýsýz. Lütfen yöneticiye bildirin!"
	#define STRMSG_S_I2NOTIFY_0004 "Arkadaþýn '%s' giriþ yaptý."
	#define STRMSG_S_I2NOTIFY_0005 "Önceki birliði kontrol et"
	#define STRMSG_S_I2NOTIFY_0006 "Önceki birlik mevcut deðil"
	#define STRMSG_S_I2NOTIFY_0007 "Birliðe geri dön"
	#define STRMSG_S_I2NOTIFY_0008 "Þu an bir birliktesin"
	#define STRMSG_S_I2NOTIFY_0009 "CÝDDÝ HATAr: ciddi parti hatasý! T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Birlik personelinin durumu geçersiz"
	#define STRMSG_S_I2NOTIFY_0011 "Birlik personeli zaten tugaya katýlmýþ"
	#define STRMSG_S_I2NOTIFY_0012 "Bu kiþi zaten tugaya katýlmýþ"
	#define STRMSG_S_I2NOTIFY_0013 "Kendi kendinizi davet edemesiniz"
	#define STRMSG_S_I2NOTIFY_0014 "Bir tugaya katýlmanýza izin verilmeyen bir konumdasýnýz"
	#define STRMSG_S_I2NOTIFY_0015 "Katýlabileceðin tugay personeli sayýsýný aþtýn"
	#define STRMSG_S_I2NOTIFY_0016 "Bir tugaya katýlmanýza engel olan bir konumdasýn"
	#define STRMSG_S_I2NOTIFY_0017 "Tugay lideri tugaydan çýkarýlamaz."
	#define STRMSG_S_I2NOTIFY_0018 "Bir tugay savaþý devam ederken tugaydan çýkarýlamaz."
	#define STRMSG_S_I2NOTIFY_0019 "Bir tugay savaþý devam ederken tugaydan ihraç yapýlamaz."
	#define STRMSG_S_I2NOTIFY_0020 "Tugay lideri tugaydan ihraç edilemez."
	#define STRMSG_S_I2NOTIFY_0021 "Bir tugay savaþý devam ederken tugay daðýtýlamaz."
	#define STRMSG_S_I2NOTIFY_0022 "Ayný isme deðiþiklik yapýlamaz"
	#define STRMSG_S_I2NOTIFY_0023 "Tugay isminin deðiþtirilemeyeceði bir durumdasýnýz."
	#define STRMSG_S_I2NOTIFY_0024 "Tugay iþaretinin deðiþtirilemeyeceði bir durumdasýnýz."
	#define STRMSG_S_I2NOTIFY_0025 "Rütbelerin deðiþtirilemeyeceði bir durumdasýnýz"
	#define STRMSG_S_I2NOTIFY_0026 "Rütbe zaten mevcut"
	#define STRMSG_S_I2NOTIFY_0027 "Alay lideri için rütbe deðiþimi mümkün deðildir."
	#define STRMSG_S_I2NOTIFY_0028 "Alay liderleri için rütbe deðiþimi yapýlamaz."
	#define STRMSG_S_I2NOTIFY_0029 "Toplam kullanýcý sayýsý: %d kiþi (%d kiþiye kadar çýktý)"
	#define STRMSG_S_I2NOTIFY_0030 "Yönetici mesajlarý listesine eklendi."
	#define STRMSG_S_I2NOTIFY_0031 "Yönetici mesajlarý listesinden silindi"
	#define STRMSG_S_I2NOTIFY_0032 "Sunucu IPsi: %s"
	#define STRMSG_S_I2NOTIFY_0033 "\'%s\' sunucu grubugiriþ yapan toplam kiþi sayýsý: %d kiþi"
	#define STRMSG_S_I2NOTIFY_0034 "Sunucuyu (%s) kapatmak istediðinize emin misiniz? ServerID: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' oyun oynamýyor"
	#define STRMSG_S_I2NOTIFY_0036 "Toplam kullanýcý sayýsý: %d kiþi (%d kiþiye kadar çýktý)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Ýlgili alay mevcut deðil."
	#define STRMSG_S_I2NOTIFY_0039 "Fýsýldama bloðu kaldýrýldý"
	#define STRMSG_S_I2NOTIFY_0040 "Fýsýldama bloklandý"
	#define STRMSG_S_I2NOTIFY_0041 "Tugaya katýlmadý"
	#define STRMSG_S_I2NOTIFY_0042 "(%d) Tugayý mevcut deðil"
	#define STRMSG_S_I2NOTIFY_0043 "Ýlgili hava (%s) mevcut deðil."
	#define STRMSG_S_I2NOTIFY_0044 "Alan Sunucusu geçersiz"
	#define STRMSG_S_I2NOTIFY_0045 "Ýlgili harita (%s) mevcut deðil."
	#define STRMSG_S_I2NOTIFY_0046 "%d dakika boyunca sohbet edemezsin!"
	#define STRMSG_S_I2NOTIFY_0047 "Sohbet yasaðý ayarlandý:  '%10s', %3d dakika"
	#define STRMSG_S_I2NOTIFY_0048 "Sohbet bloðu durumu iptal edildi."
	#define STRMSG_S_I2NOTIFY_0049 "Sohbet bloðu iptal edildi: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (hesap: %s, harita: %d(%d), seviye: %d) OYNUYOR"
	#define STRMSG_S_I2NOTIFY_0051 "Kendini teslim olmaya çaðýramazsýn"
	#define STRMSG_S_I2NOTIFY_0052 "Ýlgili tugay mevcut deðil."

	#define STRMSG_S_IMSERVER_050607_0001	"Ýlgili harita mevcut deðil."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Alan Sunucusuna giriþ yapýldý.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "[%15s:%4d] Alan Sunucusu ile baðlantý kesildi. Yeniden baðlanýlmaya çalýþýlýyor.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Canavar ve nesne arasýnda çarpýþma kontrolü mevcut deðil.\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Þehir iþgal savaþý canavar (%10s) teslim olmaya çaðrýldý\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%s hesabý (%s) ile giriþ yapýldý. IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Baþarýlý"
	#define STRMSG_S_P2PRENOTIFY_0002 "Baþarýsýz"
	#define STRMSG_S_P2PRENOTIFY_0003 "[HATA] Hesap bilgileri eklemede hata oluþtu, AccountName(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Merhaba. Bu AirRivals Yöneticisidir."
	#define STRMSG_SCAT_051115_0002		"10 dakikalýðýna düzenli bakým çalýþmamýz yapýlacaktýr."
	#define STRMSG_SCAT_051115_0003		"Lütfen güvenli bir bölgeye gidin ve oyundan çýkýn."
	#define STRMSG_SCAT_051115_0004		"Önce, NPC sunucusu kapatýlacaktýr."
	#define STRMSG_SCAT_051115_0005		"AirRivals düzenli bakýmý baþlayacak."
	#define STRMSG_SCAT_051115_0006		"AirRivals ile gününüze eðlence katýn."
	#define STRMSG_SCAT_051115_0007		"5 dakika içinde sunucu bakýmý yapýlacaktýr." // 5     .
	#define STRMSG_SCAT_051115_0008		"Sunucu 60 dakikalýðýna çevrim dýþý olacaktýr."	//  60   
	#define STRMSG_SCAT_051115_0009		"Sunucu onarýmý 30 dakika sonra baþlýyor."
	#define STRMSG_SCAT_051115_0010		"Sunucu onarýmý 15 dakika sonra baþlýyor."
	#define STRMSG_SCAT_051115_0011		"Sunucu onarýmý 10 dakika sonra baþlýyor."
	#define STRMSG_SCAT_051115_0012		"Sunucu onarýmý 5 dakika sonra baþlýyor."
	#define STRMSG_SCAT_051115_0013		"Sunucu onarýmý baþlamak üzere."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Görünmez Mode: Kullanýcýlar sizi göremez ve silahlar kullanýlamaz."
	#define STRMSG_060509_0001			"Yenilmez Statüsü: Hiçbir zarar almazsýnýz."
	#define STRMSG_060509_0002			"Gizlilik Modu: Ýlk saldýrý yaratýklardan gelmez."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Ýsteðiniz oyun yönetilerine gönderildi. Oyun yöneticilerinden biri en kýsa sürede sizinle iletiþim kuracaktýr."
	#define	STRMSG_060526_0001			"Otomatik güncelleme yapamadýnýz.\r\n\r\n Lütfen (%s) adresinden yamayý yükleyip yeniden baðlanýn.\r\n\r\n	Hata: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Bu ID kayýtlý deðil veya ID ve þifre bilgileri uyuþmuyor."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Oyun sunucusu bakým nedeniyle þu an çevrim dýþýdýr. Lütfen daha fazla bilgi için resmi internet sitemizi (www.airrivals.net) ziyaret edin."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Oyun istemci versiyonu geçerli deðil. \r\n  Lütfen yama dosyasýný tekrar indirin veya tekrar yükleyin."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"%s tarafýndan öldürüldün."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree server DB(atum2_db_20) sýfýrlanmasý jamboree server kapatýldýktan sonra yürütülebilir."
	#define STRMSG_070410_0001   	"jamboree server DB(atum2_db_20) sýfýrlamak istediðinize emin misiniz - [Onaylama numarasý:%d]"
	#define STRMSG_070410_0002   	"Jamboree server	DB(atum2_db_20) sýfýrlandý."
	#define STRMSG_070410_0003   	"Jamboree server	DB(atum2_db_20) sýfýrlanmasý baþarýsýz !!"
	#define STRMSG_070410_0004   	"Jamboree server DB(atum2_db_20) e '%s' veri çoðaltmasý tamamlandý."
	#define STRMSG_070410_0005   	"Jamboree server DB(atum2_db_20) e '%s' veri çoðaltmasý baþarýsýz - karakter mevcut deðil!"
	#define STRMSG_070410_0006   	"Jamboree server DB(atum2_db_20) %s' veri çoðaltmasý baþarýsýz - Ýlgili hesap karakteri mevcut deðil!"
	#define STRMSG_070410_0007   	"Jamboree server DB(atum2_db_20) %s' veri çoðaltmasý baþarýsýz - Veritabaný ekleme hatasý!"
	#define STRMSG_070410_0008   	"Jamboree server DB(atum2_db_20) %s veri çoðaltmasý baþarýsýz - Bilinmeyen hata (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (düþük)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (orta)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (yüksek)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (düþük-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (orta-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (yüksek-geniþ)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (düþük)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (orta)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (yüksek)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (düþük)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (orta)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (yüksek)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (düþük-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (orta-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (yüksek-geniþ)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (düþük)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (orta)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (yüksek)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Gizlilik modunda olduðunuzdan baþlayamaz."
#define STRMSG_070615_0001		"Gözleme baþlatýlamadý."
#define STRMSG_070620_0000	"Kullanýcý gözlemeyi baþlatamadý."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"SavaþNoktasý"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"%d saattir bu oyunu oynuyorsunuz."
#define STRMSG_070628_0001				"%d saatir bu oyunu oynuyorsunuz. Biraz dinlenmek için gerekli adýmlarý izleyin."
#define STRMSG_070628_0002				"Çok uzun zamandýr oynuyorsunuz. Bu saðlýðýnýz için zararlýdýr. Lütfen saðlýðýnýza dikkat edin ve oyunu kapatýp dinlenin. Bu sizin yararýnýzadýr."
#define STRMSG_070628_0003				"Bu oyunu daha fazla oynamanýz artýk saðlýðýnýz açýsýndan kritik olacaktýr. Þimdi oyunu kapatýp saðlýðýnýza dikkat edin. Aksi taktirde saðlýðýnýz etkilenebilir ve oyun geliriniz %0 olacak. Oyun geliriniz oyun kapatýldýktan 5 saat sonra normale dönecektir."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\ arenaya girmeye yasaklýdýr."
#define STRMSG_070711_0001 "\'%s\ arenaya girmeye yasaklýdýr (kalan süre: %d dakika)"
#define STRMSG_070711_0002 "%d dakikalýðýna arenaya girmeniz yasaklanmýþtýr."
#define STRMSG_070711_0003 "Arenaya girme ysaðýnýz sona ermiþtir."
#define STRMSG_070711_0004 "\'%s\ için arenaya giriþ yasaklanmýþtýr."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (düþük-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (orta-geniþ)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (yüksek-geniþ)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Bu komut ulus seçimi yapýldýktan sonra kullanýlabilir."
#define STRMSG_070830_0002                                   "Seçilen ulusun konferans odasý haritasý (%d) bulunamadý."
#define STRMSG_070830_0003                                   "Konferans odasýna girebilecek kullanýcý sayýsý: %d"
#define STRMSG_070830_0004                                   "'%s' zaten giriþ izni listesine eklenmiþ."
#define STRMSG_070830_0005                                   "'%s' giriþ iznine sahip deðil."
#define STRMSG_070830_0006                                   "'%s' geçerli bir karakter deðil."
#define STRMSG_070830_0007                                 "'%s' konferans giriþ izinlileri listesine eklenemedi. (Maksimum %d kiþi)"
#define STRMSG_070830_0008                                   "'%s' konferansa girmeye izinli olarak belirlendi."
#define STRMSG_070830_0009                                   "Konferans odasýna giriþ isni verildi."
#define STRMSG_070830_0010                                   "Konferans odasýna giriþ izni iptal edildi."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s sana hediye olarak %s gönderdi."
#define STRMSG_071115_0002									"Hediye listesi: \'%s (%d parça)\'"
#define STRMSG_071115_0003									"\\y%s send a present to %s.  Present is  %s. Please check the warehouse."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Ýtiraz sistemi yürürlükte deðil. Müþteri merkezini kullanýn: http://support.airrivals.org"
#define STRMSG_071120_0002									"itiraz sistemi aktif edildi."
#define STRMSG_071120_0003									"Ýtiraz sistemi sonuçlandý."
#define STRMSG_071120_0004									"Ýtiraz sistemi %s den %s e kadar baþlayacaktýr."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s sana hediye olarak %s(%d) gönderdi. Stoðunuzdan kontrol edin."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Çözünürlük ayarlarý geçerli deðil. Lütfen tekrar kontrol edin."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'%s' blok ayarýnda hata var. Hata kodu (%d)"
#define STRMSG_080201_0002									"'%s' hesabý blok edildi. [Blok Bitiþ Tarihi: %s]"
#define STRMSG_080201_0003									"'%s' hesabý blok listesinde mevcut deðil. Hata Kodu (%d)"
#define STRMSG_080201_0004									"'%s' hesabýnýn bloklanmasýnda hata oluþtu. Hata Kodu (%d)"
#define STRMSG_080201_0005									"'%s' hesabý blok listesinden çýkarýldý." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (düþük-geniþ)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (orta-geniþ)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (yüksek-geniþ)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), [%15s:%4d] Arena Sunucusuna baðlanýlamadý. Yeniden baðlanýlýyor\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Arena Sunucusuna baðlanýldý.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "[%15s:%4d] Arena Sunucusuna baðlantý sonlandý. Yeniden baðlanýlmaya çalýþýlýyor.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X)  %s[%s] den alýndý\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Bilinmeyen Hata@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "\\y%d Nolu Arena bekleme odasýna aktivite özelliði verildi."
#define STRMSG_ARENAEVENT_080310_0002                    "\\y%d Nolu Arena bekleme odasýndan aktivite özelliði kaldýrýldý."
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Arena özelliði verme baþarýsýz.\r\n"
#define STRMSG_080428_0001					"%s kapatýldý"          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º º¸ DB¿¡ á(½Ô °è ¸¯ÅÍ »ý¼º ÇÑ ½ýºÅÛá) - 
#define STRMSG_080430_0001					"Seçilen sunucu yeni karakter oluþturulmasýna izin verilmeyen bir sunucudur."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼ö »çÇ× - 
#define STRMSG_080613_0001					"%s tugayýna giriþ izni reddedildi."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Hatasý] Böyle bir (QP_xxx)DB  süreç tarama fonksiyonu yok !! TaramaTipi(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s için %d dakikalýðýna sohbet kýsýtlamasý getirildi.\\y"
#define STRMSG_081230_0002					"\\yLider sana, %d dakikalýðýna sohbet kýsýtlamasý getirdi.\\y"
#define STRMSG_081230_0003					"\\ySohbet kýsýtlamasý kaldýrýldý.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °å µ¿ÀÇâ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - »ç¿ëÇÏÁö ¾Ê, STRMSG_090831_0001´Â ÆäÀÌÁö·Î ó¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Hackshield yükle"
#define STRMSG_090831_0002					"nProtect yükle"// 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"Ýptal et"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - 
#define STRMSG_090902_0001					"http://tr.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø Çóµµ á(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (düþük)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (orta)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (yüksek)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (düþük)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (orta)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (yüksek)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (düþük)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (orta)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (yüksek)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ ¼Ó Çã¿ë »ó
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Kayýtsýz sunucu (yasadýþý özel bir sunucu olabilir.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Veri tabaný baðlantýsý kurulurken bir hata oluþtu."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Onay iþlemi baþarýyla tamamlandý"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Sunucu IP kaydedildi fakat bir sonraki onay iþlemi reddedildi."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows sunucusunu kapatma komutu verildi."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ¸®°Å ½ýºÅÛ  ¾²

// 1Â÷ 

#define STRMSG_120330_0001					"%s Kül Yolu'ndaki Saklý Yer'e giden ýþýnlanma portalýný etkinleþtirir."
#define STRMSG_120330_0002					"%s Kül Yolu'nda tecrübe puanlarýnýn %%%%100 artýþýný (1 saatlik Happy Hour etkinliði) etkinleþtirir."
#define STRMSG_120330_0003					"%s Kül Yolu'nda eþya düþürme oranýný %%%%100 artýþýný (1 saatlik Happy Hour etkinliði) etkinleþtirir."
#define STRMSG_120330_0004					"%s Kül Yolu'nda eþya düþürme oranýnýn/ tecrübe puanlarýnýn / SPI'nin %%%%100 artýþýný (1 saatlik Happy Hour etkinliði) etkinleþtirir."
#define STRMSG_120330_0005					"%s Kül Yolu'ndaki silah dükkanýný etkinleþtirir."
#define STRMSG_120330_0006					"%s Hiper Kart Dükkaný'ný etkinleþtirir."
#define STRMSG_120330_0007					"%s Kül Yolu'ndaki Kit Dükkaný'ný etkinleþtirir."
#define STRMSG_120330_0008					"%s Kül Yolu'na devasa bir canavar çaðýrýr."
#define STRMSG_120330_0009					"Kristal kayboldu."

// 2Â÷ 

#define STRMSG_120508_0001					"%s %d karakterinin Batýk Vaha'da elde ettiði savaþ puaný kadar savaþ puaný alýr."
#define STRMSG_120508_0002					"%s Batýk Vaha'ya bir patron canavar çaðýrýr."
#define STRMSG_120508_0003					"%s, Batýk Vaha'da tecrübe puanlarýný %%%%150 oranýnda (indirimli saat etkinliði 1 saat sürer) etkinleþtirir."
#define STRMSG_120508_0004					"%s, Batýk Vaha'da nesne düþme oranýnýn %%%%150 (indirimli saat etkinliði 1 saat sürer) artýþýný etkinleþtirir."
#define STRMSG_120508_0005					"%s Batýk Vaha'da nesne düþürme oranýnýn/ tecrübe puanlarýnýn / SPI'nin %%%%150 artýþýný (1 saatlik Happy Hour etkinliði) etkinleþtirir."
#define STRMSG_120508_0006					"%s Batýk Vaha'da antik buz elde eder."
#define STRMSG_120508_0007					"%s Batýk Vaha'da geliþmiþ Eþya Dükkaný'ný etkinleþtirir."
#define STRMSG_120508_0008					"%s Batýk Vaha'da Kit Dükkaný'ný etkinleþtirir."
#define STRMSG_120508_0009					"%s Batýk Vaha'da Hiper Kart Dükkaný'ný etkinleþtirir."
#define STRMSG_120508_0010					"%s Batýk Vaha'da Silah Dükkaný'ný etkinleþtirir."
#define STRMSG_120508_0011					"%s Batýk Vaha'daki Saklý Yer'e giden ýþýnlanma portalýný etkinleþtirir."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, %d ºÐ  °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸Í ½ð£ÀÌ %dºÐ ³²¾Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÀÌ ·áµÙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½ýºÅÛ ¸®´º¾ó - ÀüÀï½Ã ¸®°Å ¹«Àû»óÅÂ(ÀÃÁö)
#define STRMSG_121126_0001					"\\yKomut: Doðrudan kristallerle ilgili olan tüm giriþimler savaþ esnasýnda yasaktýr.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX ¸Ê ¿öÇÁÇÑ
#define STRMSG_121129_0001					"\\y¿ ÀÇ ÀÌ ÇÈ Áö¿ª ÀÙ.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀüÀü±âÁö ¸®°Å ½ýºÅÛ
#define STRMSG_130121_0001					"\\c Sistem NGC birlikleri tarafýndan ele geçirildi. Tasfiye baþladý."
#define STRMSG_130121_0002					"\\cKeþif Erleri:\\c \\rNGC Kontrol Birimi\\r güçlendirildi."
#define STRMSG_130121_0003					"\\cKeþif Erleri:\\c \\rNGC Kontrol Birimi\\r yok edildi."
#define STRMSG_130121_0004					"\\cEmir:\\c \\rGomora'nýn\\r kalkanlarý devrede. Kalkanlarý devre dýþý býrakmak için \\rNGC Kontrol Birimleri'ni\\r yok et."
#define STRMSG_130121_0005					"\\cEmir:\\c \\rGomora'nýn\\r kalkanlarý indi! Þimdi saldýrýn!"
#define STRMSG_130121_0006					"\\cEmir:\\c \\rGomora\\r yok edildi! Ýleri!"
#define STRMSG_130121_0007					"\\cEmir:\\c \\rGomora\\r imha edilmeli."
#define STRMSG_130121_0008					"\\c\\rNGC Kontrol Birimi'ne\\r fazla yükleme yapýlarak \\c[%s] etkinleþtirildi."
#define STRMSG_130121_0009					"\\y[NGC Karakol Üssü Sistemi]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ  - ¼­ºêŸÀÔ á±¸ ½ýºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d Arena'da kullanýlamaz. Eþya depoya geri gönderildi.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Ó Ä÷º¼Ç - STRMSG á
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gGörünüm kartý, görünüm kartý koleksiyonuna eklendi.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gGörünüm kartýn [%2d] kez kullanýldý.\\g"
#define STRMSG_130531_0003					"\\g[%s] Görünüm kartýn maksimum uygulamaya ulaþtý. [\\c%s\\c] alacaksýn.\\g"
#define STRMSG_130531_0004					"Görünüm kartýnýn süresi doldu ve ilgili deðerler silindi. Artýk motorun kuþanmýþ durumda deðil."
#define STRMSG_130531_0005					"\\yMotor kuþanýlmamýþ. Þehre geri ýþýnlanacaksýn.\\y"
#define STRMSG_130531_0006					"\\gZýrhýna uygulanmýþ olan görünüm kartlarýný kullanamazsýn.\\g"
#define STRMSG_130531_0007					"\\gGörünüm deðiþti.\\g"
#define STRMSG_130531_0008					"\\r[%s] görünüm kartý süresi doldu.\\r"
#define STRMSG_130531_0009					"\\yGörünüm kartlý zýrhlar satýlamaz.\\y"
#define STRMSG_130531_0010					"\\yGear türleri farklý.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ¸®°Å ½ýºÅÛ Àå - STRMSG á
#define STRMSG_130708_0001					"\\cEmir:\\c  NGC kalkanlarý etkinleþtirildi. \\rGomora'nýn\\r kalkanlarýný etkisiz hale getirmek için \\rNGC Kontrol Birimi'ni\\r, imha et."
#define STRMSG_130708_0002					"\\cEmir:\\c NGC askeri üssün savunmasý durduruldu. Þimdi saldýrýn!"
#define STRMSG_130708_0003					"\\cKeþif erleri:\\c\\rNGC Kalkan oluþturucu\\r tespit edildi."
#define STRMSG_130708_0004					"\\cKeþif erleri:\\c\\rNGC Kalkan oluþturucu\\r imha edildi."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRMSG_130726_0001					"Karakter zaten bu ulusa ait."
#define STRMSG_130726_0002					"Karakter lider veya lider yardýmcýsý, bu nedenle ulus deðiþtirilemiyor."
#define STRMSG_130726_0003					"Karakter bir tugayda, ulus deðiþtirilemiyor."
#define STRMSG_130726_0004					"Ulus deðiþtirebilecek bir karakterin yok."
#define STRMSG_130726_0005					"Ulus deðiþtirilemedi [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Ulus baþarýyla deðiþtirildi AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Böyle bir hesap yok."
#define STRMSG_130726_0008					"Oturumun açýk, ulus deðiþtirilemiyor."


// 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\y%s oyuncusunun uçuþ ayrýcalýklarý ulus liderinden alýndý.\\y"
#define STRMSG_130830_0002					"\\yUçuþ ayrýcalýklarý ulus liderinden alýndý.\\y"
#define STRMSG_130830_0003					"\\yUçuþ ayrýcalýklarý ulus lideri tarafýndan %s oyuncusundan alýndý.\\y"
// End. 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­
#define STRMSG_130828_0001					"\\y[%s \\y%s\\y oyuncusunun yok edilmesine katýldý.]\\y"
#define STRMSG_130828_0002					"\\y[%s \\y%s\\y karþýsýnda ilk saldýrýyý gerçekleþtirdi.]\\y"
#define STRMSG_130828_0003					"\\y[%s toplamda \\y%s\\y oyuncusuna karþý en fazla saldýrý gerçekleþtirdi.]\\y"
#define STRMSG_130828_0004					"\\y[%s \\y%s\\y oyuncusuna karþý belirleyici darbeyi vurdu.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n yenildi."
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­

// 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â
#define STRMSG_130814_0001					"\\y[%s] NGC Strateji Puaný Savaþý'ný kazandý.\\y"
// end 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â

// 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)
#define STRMSG_130318_0001					"%s patronu kapatýlmýþ bir bölgeye çaðýrdý."
#define STRMSG_130318_0002					"%s patronu harabelere çaðýrdý."
// End. 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yÞu an müzayede evini kullanamazsýn.\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
