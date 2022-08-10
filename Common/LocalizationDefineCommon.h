// 2006-09-05 by cmkwon
// #include "LocalizationDefineCommon.h"
#include "Contents.h"

#ifndef _LOCALIZATION_DEFINE_COMMON_H_
#define _LOCALIZATION_DEFINE_COMMON_H_


///////////////////////////////////////////////////////////////////////////////
// 2006-09-04 by cmkwon, ľđľî°Ł ´Ů¸Ą Define ¸®˝şĆ®

///////////////////////////////////////////////////////////////////////////////
// 2008-01-08 by cmkwon, ľđľî Ľ­şń˝ş °ü·Ă Á¤ŔÇ¸¦ ÇĎłŞ·Î ĹëŔĎÇÔ - SERVICE_TYPE_XXX ·Î ĹëŔĎÇÔ, Preprocessor definitions Ŕş »çżëÇĎÁö ľĘŔ˝
// 2008-04-25 by cmkwon, Áöżř ľđľî/Ľ­şń˝ş Ăß°ˇ˝Ă ˛Ŕ Ăß°ˇ µÇľîľß ÇĎ´Â »çÇ× - [Ľ­şń˝ş-ÇĘĽö]Ľ­şń˝ş Ĺ¸ŔÔ(SERVICE_TYPE_XXX) Á¤ŔÇ ÇĎ±â
//  SERVICE_TYPE_KOREAN_SERVER_1		==> ÇŃ±ą	Masangsoft		- Kor	100
//  SERVICE_TYPE_KOREAN_SERVER_2		==>	ÇŃ±ą	Yedang			- Kor	1000
//  SERVICE_TYPE_ENGLISH_SERVER_1		==>	ÄłłŞ´Ů	Wikigames		- Eng	2000
//  SERVICE_TYPE_ENGLISH_SERVER_2		==>	żµ±ą	Gameforge4D		- Eng	5000	
//  SERVICE_TYPE_GERMAN_SERVER_1		==>	µ¶ŔĎ	Gameforge4D		- Deu	5100	// 2008-04-11 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ - Gameforge4D µ¶ŔĎľî 
//  SERVICE_TYPE_CHINESE_SERVER_1		==>	Áß±ą	Yetime			- Chn	3000
//  SERVICE_TYPE_VIETNAMESE_SERVER_1	==>	şŁĆ®ł˛	VTC-Intecom		- Viet	4000
//  SERVICE_TYPE_THAI_SERVER_1			==>	ĹÂ±ą	WinnerOnline	- Tha	6000	// 2008-04-11 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ - WinnerOnline ĹÂ±ąľî
//	SERVICE_TYPE_SINGAPORE_1			==> żµľî		 WinnerOnline- Sgp	6100	// 2010-12-07 by shcho,	 Áöżř Ľ­şń˝ş Ăß°ˇ(WinnerOnline żµľî) - 
//	SERVICE_TYPE_INDONESIA_SERVER_1		==> ŔÎµµł×˝ĂľĆľî WinnerOnline- IND	6200	// 2010-01-11 by shcho,	 Áöżř Ľ­şń˝ş Ăß°ˇ(WinnerOnline ŔÎµµł×˝ĂľĆľî) - 
//  SERVICE_TYPE_RUSSIAN_SERVER_1		==>	·Ż˝ĂľĆ	Innova			- Rus	7000	// 2008-05-29 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Innova_Rus ·Ż˝ĂľĆľî Ăß°ˇ) - 
//  SERVICE_TYPE_TAIWANESE_SERVER_1		==>	´ë¸¸	Newpower		- Tpe	8000	// 2008-09-23 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(´ë¸¸ Netpower_Tpe) - 
//  SERVICE_TYPE_JAPANESE_SERVER_1		==> ŔĎş»	Arario			- Jpn	10000	// 2008-12-03 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(ŔĎş» Arario_Jpn) - 
//  SERVICE_TYPE_TURKISH_SERVER_1		==> ĹÍĹ°	Gameforge4D		- Tur	5200	// 2008-12-22 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D ĹÍĹ°ľĆ, şŇľî, ŔĚĹ»¸®ľĆľî) - 
//  SERVICE_TYPE_ITALIAN_SERVER_1		==> ŔĚĹ»¸®ľĆľî	Gameforge4D	- Ita	5400	// 2008-12-22 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D ĹÍĹ°ľĆ, şŇľî, ŔĚĹ»¸®ľĆľî) - 
//  SERVICE_TYPE_FRENCH_SERVER_1		==> ÇÁ¶ű˝şľî	Gameforge4D	- Fra	5500	// 2008-12-22 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D ĹÍĹ°ľĆ, şŇľî, ŔĚĹ»¸®ľĆľî) - 
//  SERVICE_TYPE_POLISH_SERVER_1		==> Ćú¶őµĺľî	Gameforge4D	- Pol	5600	// 2009-06-04 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D Ćú¶őµĺľî, ˝şĆäŔÎľî) - 
//  SERVICE_TYPE_SPANISH_SERVER_1		==> ˝şĆäŔÎľî	Gameforge4D	- Esp	5700	// 2009-06-04 by cmkwon, Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D Ćú¶őµĺľî, ˝şĆäŔÎľî) - 
//	SERVICE_TYPE_ARGENTINA_SERVER_1		==> ľĆ¸ŁÇîĆĽłŞ	LIN			- Arg	11000	// 2010-11-01 by shcho,	 Áöżř Ľ­şń˝ş Ăß°ˇ(Gameforge4D ˝şĆäŔÎľî, ľĆ¸ŁÇîĆĽłŞľî) -  

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 01

#ifdef S_CAN_SERVER_SETTING_HSSON
#define SERVICE_TYPE_ENGLISH_SERVER_1
#define SERVICE_UID_FOR_WORLD_RANKING		2000			// 2009-02-12 by cmkwon, EP3-3 żůµĺ·©Ĺ·˝Ă˝şĹŰ ±¸Çö - 
#endif

///////////////////////////////////////////////////////////////////////////////
// 2008-05-09 by cmkwon, CodePage Á¤ŔÇ Ăß°ˇ - 
//		Korean Extended Wansung			==> 949			: Korean(Masangsoft_Kor, Yedang_Kor)
//		Latin 1							==> 1252		: English(Yedang-Global_Eng, Gameforge4D_Eng), German(Gameforge4D_Deu), French(Gameforge4D_Fra), Italian(Gameforge4D_Ita), Spanish(Gameforge4D_Esp)
//		Japanese (Shift-JIS)			==> 932			
//		Chinese (PRC)					==> 936			: Chinese(Yetime_Chn)
//		Chinese (Taiwan, Hong Kong)		==> 950			: Taiwnaese(Netpower_Tpe)
//		Viet Nam						==> 1258		: Vietnamnese(VTC-Intecom_Viet)
//		Thai							==> 874			: Thai(WinnerOnline_Tha)
//		Cyrillic, Russian (Russia)		==> 1251		: Russian(Innova_Rus)
//		Turkish							==> 1254		: Turkish(Gameforge4D_Tur)
//		Central European, Eastern European	==> 1250	: Polish(Gameforge4D_Pol)

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 02

#if defined(S_CAN_SERVER_SETTING_HSSON) || defined(S_DEU_SERVER_SETTING_JHAHN) || defined(S_ENG_SERVER_SETTING_JHAHN) || defined(S_ITA_SERVER_SETTING_JHAHN) || defined(S_FRA_SERVER_SETTING_JHAHN) || defined(S_POL_SERVER_SETTING_JHAHN) \
 || defined(S_ESP_SERVER_SETTING_JHAHN) || defined(S_TUR_SERVER_SETTING_JHAHN) || defined(S_GLOBAL_SERVER_SETTING_JHSEOL)	// 2013-09-04 by jhseol, ±Ű·Îąú Ľ­ąö şôµĺżÉĽÇ Ăß°ˇ
#define CODE_PAGE							1252
#endif

///////////////////////////////////////////////////////////////////////////////
// 2009-04-20 by cmkwon, Gameforge4D "/´©±¸" ¸í·Éľî Á¦°ĹÇĎ±â - 
#if defined(SERVICE_TYPE_ENGLISH_SERVER_2) || defined(SERVICE_TYPE_GERMAN_SERVER_1) || defined(SERVICE_TYPE_TURKISH_SERVER_1) || defined(SERVICE_TYPE_ITALIAN_SERVER_1) || defined(SERVICE_TYPE_FRENCH_SERVER_1) || defined(SERVICE_TYPE_POLISH_SERVER_1) || defined(SERVICE_TYPE_SPANISH_SERVER_1)
	#define _DEFINED_GAMEFORGE4D_		// 2009-04-21 by cmkwon, ˝şĆç¸µ ĽöÁ¤ÇÔ.
#endif

///////////////////////////////////////////////////////////////////////////////
#if defined(SERVICE_TYPE_KOREAN_SERVER_1) || defined(SERVICE_TYPE_KOREAN_SERVER_2) /*|| defined(SERVICE_TYPE_ENGLISH_SERVER_1)*/ || defined(_DEFINED_GAMEFORGE4D_)


#ifdef GAMEGUARD_NOT_EXECUTE_HSSON	

#else
	 	#define _USING_HACKSHIELD_			// 2009-04-29 by cmkwon, ÇŮ˝Żµĺ »çżë ż©şÎ #define Ŕ¸·Î Ăł¸® - ÇŮ˝Żµĺ »çżë ż©şÎ Á¤ŔÇ
#endif

	#if defined(_ATUM_FIELD_SERVER)
		#pragma comment(lib, "AntiCpXSvr.lib")
	#endif // END - #if defined(_ATUM_FIELD_SERVER)
#endif 

#ifdef S_CAN_SERVER_SETTING_HSSON
#define SIZE_MAX_INITIAL_GUILD_CAPACITY				30		// ĂĘ±â ±ćµĺ »ýĽş ˝Ă °ˇ´É ±ćµĺżř Ľö, // 2006-09-06 by cmkwon, ÇŃ±ą Ľ­ąö¸¸ şŻ°ć (40-->30)
#define SIZE_MAX_GUILD_CAPACITY						300		// 2008-05-28 by dhjin, EP3 ż©´Ü ĽöÁ¤ »çÇ× - ĂÖ´ë ±ćµĺżř Ľö
#define SIZE_MAX_ITEM_GENERAL						61		// Äł¸ŻĹÍŔÇ ŔÎşĄĹä¸®żˇ ĽŇŔŻÇŇ Ľö ŔÖ´Â ľĆŔĚĹŰŔÇ ĂÖ´ë °łĽö(1°ł´Â SPI ľĆŔĚĹŰŔÇ Ä«żîĆ®ŔĚ´Ů, Ĺ¬¶óŔĚľđĆ®´Â 60Ŕ» »çżëÇŃ´Ů.), // 2006-09-06 by cmkwon, ÇŃ±ą Ľ­ąö¸¸ şŻ°ć(61-->41)
#define SIZE_MAX_ITEM_GENERAL_IN_STORE				101		// Ă˘°íżˇ ĽŇŔŻÇŇ Ľö ŔÖ´Â ľĆŔĚĹŰŔÇ ĂÖ´ë °łĽö, // 2006-09-06 by cmkwon, ÇŃ±ą Ľ­ąö¸¸ şŻ°ć(101-->51)
#define CHARACTER_MAX_LEVEL							120
#define COUNT_IN_MEMBERSHIP_ADDED_INVENTORY			40
#define COUNT_IN_MEMBERSHIP_ADDED_STORE				50
#define COUNT_IN_MEMBERSHIP_ADDED_GUILD_CAPACITY	30
#endif

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 04

#ifdef S_CAN_SERVER_SETTING_HSSON
#define STAT_BGEAR_ATTACK_PART						3
#define STAT_BGEAR_DEFENSE_PART						3
#define STAT_BGEAR_FUEL_PART						3
#define STAT_BGEAR_SOUL_PART						3
#define STAT_BGEAR_SHIELD_PART						3
#define STAT_BGEAR_DODGE_PART						3

#define STAT_MGEAR_ATTACK_PART						2
#define STAT_MGEAR_DEFENSE_PART						4
#define STAT_MGEAR_FUEL_PART						3
#define STAT_MGEAR_SOUL_PART						4
#define STAT_MGEAR_SHIELD_PART						3
#define STAT_MGEAR_DODGE_PART						2

#define STAT_AGEAR_ATTACK_PART						4
#define STAT_AGEAR_DEFENSE_PART						3
#define STAT_AGEAR_FUEL_PART						3
#define STAT_AGEAR_SOUL_PART						3
#define STAT_AGEAR_SHIELD_PART						4
#define STAT_AGEAR_DODGE_PART						1

#define STAT_IGEAR_ATTACK_PART						4
#define STAT_IGEAR_DEFENSE_PART						2
#define STAT_IGEAR_FUEL_PART						3
#define STAT_IGEAR_SOUL_PART						3
#define STAT_IGEAR_SHIELD_PART						2
#define STAT_IGEAR_DODGE_PART						4
#endif

///////////////////////////////////////////////////////////////////////////////
// 2006-09-15 by cmkwon, 
// Kor_Masang140	==> 121.134.114.140:9979	// 2007-01-03 by cmkwon, ¸¶»ó ŔĚŔü
// Kor_Yedang		==> 192.168.10.40:9979		// 2007-01-03 by cmkwon, Yedang »çĽł IP
// Eng_Gala-Net		==> »ó°ü ľřŔ˝
// Viet_VTC-Intecom	==> »ó°ü ľřŔ˝
// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 05

#ifdef S_CAN_SERVER_SETTING_HSSON
#define MSBILLING_DB_SERVER_IP						"127.0.0.1"
#endif

#define MSBILLING_DB_SERVER_PORT					9979

// Kor_Masang51		==> 1
// Kor_ETRI			==> 1
// Eng_Gala-Net		==> »ó°ü ľřŔ˝
// Viet_VTC-Intecom	==> »ó°ü ľřŔ˝
#define MSBILLING_GAMEUID							1

// 2006-09-22 by dhjin

#define COUNT_IN_MEMBERSHIP_GUILDSTORE				201		// 2006-09-22 by dhjin, ¸âąö˝± Ľ­şń˝ş˝Ă ż©´Ü Ă˘°í Ä«żîĆ®

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// 2007-02-13 by cmkwon

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 06

#ifdef S_CAN_SERVER_SETTING_HSSON
#define STRMSG_S_GAMEHOMEPAGE_DOMAIN			"http://ace.subagames.com"		// 2008-08-05 by cmkwon, WikiGames_Eng °ÔŔÓ Á¤ş¸ ĽöÁ¤ - ,"http://www.ace-onlines.com"
#endif

///////////////////////////////////////////////////////////////////////////////
// 2006-05-22 by cmkwon, şńąř MD5·Î ŔÎÄÚµů˝Ăżˇ żř·ˇ şńąř ľŐżˇ Ăß°ˇµÉ ˝şĆ®¸µ - 
#define MD5_PASSWORD_ADDITIONAL_STRING			""

#define EXT_AUTH_GAME_NAME						"SCO"		// 2006-05-22 by cmkwon

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 07

#ifdef S_CAN_SERVER_SETTING_HSSON
// 2008-06-05 by cmkwon, AdminTool, Monitor Á˘±Ů °ˇ´É IP¸¦ server config file żˇ ĽłÁ¤ÇĎ±â - MS140ąř Ľ­ąö¸¸ Ĺ×˝şĆ®¸¦ Ŕ§ÇŘ IP ¸¦ Ć˛¸®°Ô(121.134.11.) ĽłÁ¤ ÇÔ
// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP1		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP2		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP3		"127.0.0."		// 2008-08-05 by cmkwon, WikiGames_Eng °ÔŔÓ Á¤ş¸ ĽöÁ¤ - ş»Ľ· Private IP
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP4		"127.0.0."		// 2008-08-05 by cmkwon, WikiGames_Eng °ÔŔÓ Á¤ş¸ ĽöÁ¤ - ş»Ľ· Public IP
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP5		"127.0.0."		// 2008-08-05 by cmkwon, WikiGames_Eng °ÔŔÓ Á¤ş¸ ĽöÁ¤ - Ĺ×Ľ· Public IP
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP6		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP7		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP8		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP9		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define SCADMINTOOL_CONNECTABLE_PREFIX_IP10		"127.0.0."		// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define IS_SCADMINTOOL_CONNECTABLE_IP(ip)		( 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP1,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP1)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP2,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP2)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP3,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP3)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP4,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP4)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP5,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP5)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP6,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP6)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP7,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP7)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP8,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP8)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP9,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP9)) \
												|| 0 == strncmp((ip),SCADMINTOOL_CONNECTABLE_PREFIX_IP10,strlen(SCADMINTOOL_CONNECTABLE_PREFIX_IP10)) )

///////////////////////////////////////////////////////////////////////////////
// 2006-05-02 by cmkwon, Launcher URL
#define LAUNCHER_WEB_URL						"http://ace.subagames.com/launcher.aspx"
#define TESTSERVER_LAUNCHER_WEB_URL				"http://ace.subagames.com/launcher.aspx"


///////////////////////////////////////////////////////////////////////////////
// 2007-02-13 by cmkwon
#define BILLING_DBSERVER_DATABASE_NAME			"MS_Billing"
#define BILLING_DBSERVER_USER_ID				"atum"
#define BILLING_DBSERVER_USER_PWD				"callweb"
#endif // S_CAN_SERVER_SETTING_HSSON

///////////////////////////////////////////////////////////////////////////////
// 2007-02-13 by cmkwon

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 08

#ifdef S_CAN_SERVER_SETTING_HSSON
#define	SG_BOX_FONT_FACENAME						"Tahoma"					// 2007-02-12 by cmkwon, ±ŰľľĂĽ
#define	SG_BOX_FONT_CHARSET							ANSI_CHARSET			// 2007-02-12 by cmkwon, Äł¸ŻĹÍĽÂ
#define	SG_BOX_FONT_WEIGHT							FW_BOLD					// 2007-02-12 by cmkwon, ±ŰľľĂĽ µÎ±ú
#endif

// #define STR_XOR_KEY_STRING_PRE_SERVER_ADDRESS	"+-faNsf(^fP{)3>fnao??_+|23kdasf*^@`d{]s*&DS"

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 09

#if defined(S_CAN_SERVER_SETTING_HSSON) && defined(S_ACCESS_INTERNAL_SERVER_HSSON)
//XOR KEY: +-faNsf(^fP{)3>fnao??_+|23kdasf*^@`d{]s*&DS

#ifdef S_EP4_TEST_SERVER_HSKIM
	#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"1A1F514F7E5D56066F"	 //	IP 127.0.0.1 //2021 by Inet
#else
	#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"5F4815153D16145E3B147E0940455F0A1D4C0A4950335E085B5C054A0F1612"	// 2013-11-06 by jekim, 68.179.106.27 ÄłłŞ´Ů Ĺ×Ľ· ľĆŔĚÇÇ şŻ°ć // IP 66.207.198.252 - ÄłłŞ´Ů ł»şÎ Ĺ×Ľ·
	//#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"1A1C534F7F4752066D537E4A1D01"	// IP 115.144.35.142 - ¸¶»ó ł»şÎ ÄłłŞ´Ů Ĺ×Ľ·
#endif

#define REGISTRY_BASE_PATH						"NewRivalsEvolution"
#define EXE_1_FILE_NAME							"46.exe"
#define LAUNCHER_FILE_NAME						"Updater.exe"
#ifdef _WIN_XP
#define CLIENT_EXEUTE_FILE_NAME					"EngineXP.atm"
#else
#define CLIENT_EXEUTE_FILE_NAME					"Engine.exe"
#endif
#define URL_REGISTER_PAGE						"reg.asp"				// 2006-04-05 by cmkwon, 수정함

#define WEB_START_REGISTRY_VALUE_NAME			"InstallPath"
#elif defined(S_CAN_SERVER_SETTING_HSSON)

#ifdef S_EP4_TEST_SERVER_HSKIM
#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"1A1F514F7E5D56066F"	//	IP 127.0.0.1 //2021 by Inet
#else
#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"5F4815153D16145E3B147E0940455F0A1D4C0A4950335E085B5C054A0F1612"	// 2013-11-06 by jekim, 68.179.106.27 ÄłłŞ´Ů Ĺ×Ľ· ľĆŔĚÇÇ şŻ°ć // IP 66.207.198.252 - ÄłłŞ´Ů ł»şÎ Ĺ×Ľ·
//#define CHOICE_PRE_SERVER_IP_OR_DOMAIN_IN_XOR	"1A1C534F7F4752066D537E4A1D01"	// IP 115.144.35.142 - ¸¶»ó ł»şÎ ÄłłŞ´Ů Ĺ×Ľ·
#endif

#define REGISTRY_BASE_PATH						"NewRivalsEvolution"
#define EXE_1_FILE_NAME							"46.exe"
#define LAUNCHER_FILE_NAME						"Updater.exe"
#ifdef _WIN_XP
#define CLIENT_EXEUTE_FILE_NAME					"EngineXP.atm"
#else
#define CLIENT_EXEUTE_FILE_NAME					"Engine.exe"
#endif
#define URL_REGISTER_PAGE						"reg.asp"				// 2006-04-05 by cmkwon, 수정함

#define WEB_START_REGISTRY_VALUE_NAME			"InstallPath"
#endif

///////////////////////////////////////////////////////////////////////////////
// 2006-12-22 by cmkwon, °ÔŔÓŔĚ¸§ şŻ°ćÇĎ¸éĽ­ 

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 10

#ifdef S_CAN_SERVER_SETTING_HSSON
#define STRMSG_WINDOW_TEXT							"ACEonline"
#define STRMSG_REG_STRING_CLIENT_VERSION			"ACEonlineVersion"
#define STRMSG_REG_STRING_REGISTRYKEY_NAME			"Wikigames"				// 2008-07-31 by cmkwon, Yedang-Global_Eng ¸¦ Wikigames_Eng ·Î şŻ°ć ÇÔ - 
#endif

///////////////////////////////////////////////////////////////////////////////
// 2007-06-27 by cmkwon, Áß±ą ąć˝ÉĂë ˝Ă˝şĹŰ ĽöÁ¤ - ąĚĽşłâŔÚ °ü·Ă
// Kor		- ¸¸ 20ĽĽ
// China	- ¸¸ 18ĽĽ
#define ADULT_YEARS									20			// 2007-06-29 by cmkwon,

///////////////////////////////////////////////////////////////////////////////
// 2007-07-06 by cmkwon, SCAdminToolżˇĽ­ OnlyServerAdmin°ü·Ă ĽöÁ¤ - °čÁ¤ Á¤ş¸
#define SCADMINTOOL_ONLY_SERVER_ADMIN_ACCOUNT_NAME		"SC_moniter"
#define SCADMINTOOL_ONLY_SERVER_ADMIN_PASSWORD			"cowboyWkd"

///////////////////////////////////////////////////////////////////////////////
// 2007-09-05 by cmkwon, EXE_1żˇ ·Î±×ŔÎ Ľ­ąö Ľ±ĹĂ ŔÎĹÍĆäŔĚ˝ş ĽöÁ¤ - »óŔ§ URL, żěĂř ÇĎ´Ü URL
#define EXE1_URL_1										"http://notice.aceonline.com.cn/ace2.htm"
#define EXE1_URL_2										"http://notice.aceonline.com.cn/ace1.htm"

///////////////////////////////////////////////////////////////////////////////
// 2008-12-19 by cmkwon, ÇŃ±ą Yedang ÇŮ˝Żµĺ ¸đ´ĎĹÍ¸µ Ľ­ąö ĽłÁ¤ Ăß°ˇ - IP°ˇ ""·Î ĽłÁ¤µÇ¸é ¸đ´ĎĹÍ¸µ Ľ­ąö¸¦ »çżëÇĎÁö ľĘ´Â °ÍŔÓ, ÇöŔç´Â Masang140°ú Yedang¸¸ »çżë ÇŇ °ÍŔÓ

// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 11

#ifdef S_CAN_SERVER_SETTING_HSSON
#define GAME_GUARD_MONITORING_SERVER_IP					""
#endif

///////////////////////////////////////////////////////////////////////////////
// 2009-02-12 by cmkwon, EP3-3 żůµĺ·©Ĺ·˝Ă˝şĹŰ ±¸Çö - żůµĺ·©Ĺ· DB Ľ­ąö Á¤ş¸
// 2009-06-01 by cmkwon, żůµĺ ·©Ĺ· ˝Ă˝şĹŰ Ĺ×˝şĆ® ±â´É ±¸Çö(for Ĺ×Ľ·) - 
// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 12

#ifdef S_CAN_SERVER_SETTING_HSSON
#define WRK_DBSERVER_IP							"127.0.0.1"				// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)
#define WRK_DBSERVER_PORT						1433
#define WRK_DBSERVER_DATABASE_NAME				"atum2_db_WorldRanking"
#define WRK_DBSERVER_ID							"atum"
#define WRK_DBSERVER_PWD						"callweb"
#define WRK_DBSERVER_IP_FOR_TEST_SERVER			"127.0.0.1"				// 2009-12-28 by cmkwon, ¸¶»óČ¸»ç IP şŻ°ć - ±âÁ¸(121.134.114.)// 2009-06-01 by cmkwon, żůµĺ ·©Ĺ· ˝Ă˝şĹŰ Ĺ×˝şĆ® ±â´É ±¸Çö(for Ĺ×Ľ·) - 
#define WRK_DBSERVER_PORT_FOR_TEST_SERVER		9979					// 2009-06-01 by cmkwon, żůµĺ ·©Ĺ· ˝Ă˝şĹŰ Ĺ×˝şĆ® ±â´É ±¸Çö(for Ĺ×Ľ·) - 
#endif

///////////////////////////////////////////////////////////////////////////////
// 2009-03-31 by cmkwon, ĽĽ·ÂĂĘ±âČ­ ˝Ă˝şĹŰ ±¸Çö - 
#define MAX_INFLUENCE_PERCENT			53		// ĂÖ´ë 5% Â÷ŔĚ±îÁö¸¸ ĽĽ·Â Ľ±ĹĂŔĚ °ˇ´ÉÇŃ´Ů.

///////////////////////////////////////////////////////////////////////////////
// 2009-05-12 by cmkwon, (ŔĎş»żäĂ») ŔĎş»¸¸ ŔüÁř ±âÁöŔü ÁÖ±â 7ŔĎ·Î ĽöÁ¤ - ŔüÁř±âÁöŔü ÁÖ±â Ľ­şń˝şş°·Î ´Ů¸Ł°Ô ĽłÁ¤
// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 13

#ifdef S_CAN_SERVER_SETTING_HSSON
#define	OUTPOST_NEXTWARGAP				5
#endif

///////////////////////////////////////////////////////////////////////////////
// 2009-07-08 by cmkwon, ŔüŔď °ü·Ă Á¤ŔÇ Ŕ§Äˇ ŔĚµż(LocalizationDefineCommon.h) - 
// ±ą°ˇ ĽŇ˝şĹëÇŐ ¶§ Ăß°ˇ µÇľîľß ÇŇ şÎşĐ ĽřĽ­ 14

#ifdef S_CAN_SERVER_SETTING_HSSON
// 2013-09-03 ÄłłŞ´Ů Ăß°ˇ : EP4-3 ŔüÁř±âÁöŔü ˝Ă°Ł 2˝Ă°ŁżˇĽ­ 1˝Ă°ŁŔ¸·Î şŻ°ć 
#define	OUTPOST_WARTIME					60			// ŔüÁř±âÁöŔü ÁřÇŕ ˝Ă°Ł			==> ¸¶»ó 10şĐ, łŞ¸ÓÁö´Â 120şĐ
#define OUTPOST_WARTIME_FOR_TESTSERVER	60			// Ĺ×Ľ·Ŕş ŔüÁř±âÁöŔü ÁřÇŕ ˝Ă°Ł	==> ¸¶»ó 10şĐ, łŞ¸ÓÁö´Â 60şĐ
#define PAY_MINIMUN_COUNT				10			// ¸đĽ±Ŕü,ŔüÁř±âÁöŔü,°ĹÁˇŔü °łŔÎ ş¸»óŔ» Ŕ§ÇŃ ĂÖĽŇ ŔÎżřĽö ==> ¸¶»ó 1¸í, łŞ¸ÓÁö´Â 10¸í
#endif

///////////////////////////////////////////////////////////////////////////////
// 2009-11-02 by cmkwon, Äł˝¬(ŔÎşĄ/Ă˘°í Č®Ŕĺ) ľĆŔĚĹŰ Ăß°ˇ ±¸Çö - 
#define SIZE_MAX_ADDABLE_INVENTORY_COUNT		50		// ±âş»°ú ÇÁ¸®ąĚľöŔ» Á¦żÜÇŃ Ăß°ˇ·Î °ˇ´ÉÇŃ ĂÖ´ë ŔÎşĄ Ăß°ˇ °łĽö
#define SIZE_MAX_ADDABLE_STORE_COUNT			50		// ±âş»°ú ÇÁ¸®ąĚľöŔ» Á¦żÜÇŃ Ăß°ˇ·Î °ˇ´ÉÇŃ ĂÖ´ë Ă˘°í Ăß°ˇ °łĽö

////////////////////////////////////////////////////////////////////////////////
// ÄÁĹŮĂ÷ ąöÁŻ °ü¸®żë µđĆÄŔÎ. by hsLee. 
#define __CONTENTS_SHOW_INFINITY_DIFFICULTY_EDIT_WND__		// ŔÎÇÇ´ĎĆĽ ł­ŔĚµµ Á¶Á¤ UI ş¸ŔĚ±â.	2010. 07. 27. by hsLee.
////////////////////////////////////////////////////////////////////////////////

#endif // end_#ifndef _LOCALIZATION_DEFINE_COMMON_H_
