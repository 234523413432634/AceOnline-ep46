// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer?? ???? ???
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [Xâu chýÞ] - Ðãòt tin nhãìn caònh tên miÌnh"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [Map sôì] [Kênh sôì] - Di chuyêÒn tõìi kênh Map týõng ýìng"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Di chuyêÒn ðêìn toòa ðôò týõng ýìng õÒ Map hiêòn taòi"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Danh saìch thaÌnh viên ðang õÒ Map hiêòn taòi (tôìi ða 20 ngýõÌi)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [Tên nhân vâòt] [Tên map] - Di chuyêÒn nhân vâòt sang map xaìc ðiònh"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [Tên quaìi vâòt|Thiêìt biò] – Hiêòn thông tin vêÌ Quaìi vâòt hoãòc Trang biò coì tên týõng ýìng"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest – Hiêòn thông tin vêÌ Nhiêòm vuò cuÒa nhân vâòt"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [Nvuò sôì] - Xoìa nhiêòm vuò coì sôì týõng ýìng"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [Daòng thiêìt biò(0~53)] - Cho biêìt caìc daòng cuò thêÒ cuÒa thiêìt biò"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [Daòng thiêìt biò(0~53)] - Thêm vaÌo caìc daòng cuò thêÒ cuÒa caìc thiêìt biò"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [TýÌ Itemnum] ~ [Ðêìn Itemnum] – Thêm caìc Trang biò nãÌm trong khoaÒng maÞ týõng ýìng"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - KhõÒi taòo laòi toaÌn bôò traòng thaìi"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo – Hiêòn thông tin vêÌ Phi ðôòi"
	#define STRCMD_CS_COMMAND_GAMETIME					"/time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /time [ThõÌi gian(0~23)] – Thay ðôÒi thõÌi gian hiêòn taòi (ChiÒ ðôÒi thõÌi gian caì nhân)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Choòn câìp ðôò ðýõòc hiêÒn thiò bõÒi tin nhãìn debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [MaÞ quaìi vâòt|Sôì lýõòng] [# of monsters] – Triêòu tâòp quái vâòt (TrýõÌng hõòp coì khoaÒng trôìng õÒ tên cuÒa quaìi vâòt, baòn duÌng ‘_’)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [Câìp ðôò(1~9)] – Lâìy toaÌn bôò kyÞ nãng phuÌ hõòp võìi câìp ðôò ðaÞ nhâòp"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem – Lâìy toaÌn bôò caìc trang biò, ngoaòi trýÌ KyÞ nãng vaÌ Trang biò ðêìm ðýõòc"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - Lâìy toaÌn bôò vuÞ khiì phuÌ hõòp võìi phi cõ"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Xoìa toaÌn bôò Items không ðýõòc trang biò (trýÌ KyÞ nãng)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [MaÞ Item] [Sôì lýõòng] - Lâìy trang biò coì maÞ vaÌ sôì lýõòng týõng ýìng, trýõÌng hõòp không xaìc ðiònh 'sôì lýõòng' seÞ ðýõòc coi laÌ 1"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [MaÞ item] [Sôì lýõòng] – ThaÒ trang biò ra không gian, trýõÌng hõòp không xaìc ðiònh 'sôì lýõòng' seÞ ðýõòc coi laÌ 1"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server – Hiêòn thông tin Server"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - Hiêòn thông tin toaÌn bôò caìc Map"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Hiêòn thông tin vêÌ kênh cuÒa Map hiêòn taòi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg – ChiÒ duÌng ðêÒ kiêÒm tra"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [Sôì ðaòn VK Cõ baÒn] [Sôì ðaòn VK Cao câìp] - Naòp ðaòn võìi sôì lýõòng týõng ýìng"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [Tên nhân vâòt] – Phuòc hôÌi toaÌn bôò thông sôì (HP, SP,...) cuÒa phi cõ, trýõÌng hõòp không coì [Tên nvâòt] thiÌ naòp ðâÌy cho baÒn thân"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [% giaÒm] [Tên nhân vâòt] – GiaÒm toaÌn bôò thông sôì (HP, SP,...) theo % týõng ýìng, trýõÌng hõòp không nhâòp % thiÌ seÞ týò ðôòng laÌ 50%, không coì [Tên nhân vâòt] thiÌ seÞ giaÒm cuÒa baÒn thân"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - ChuyêÒn thaÌnh taÌi khoaÒn thông thýõÒng týÌ taÌi khoaÒn Admin hoãòc GM"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - ChuyêÒn týÌ taÌi khoaÒn thông thýõÌng sang taÌi khoaÒn cuÒa Admin hoãòc GM"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible – TrýõÌng hõòp taÌi khoaÒn cuÒa ngýõÌi ðiêÌu haÌnh hoãòc GM thiÌ seÞ không biò saìt thýõng"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [Sôì %] - Tãng lýòc tâìn công lên bao nhiêu %"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [biêìn sôì] – ÐiêÌu chiÒnh caìc biêìn sôì (thông thýõÌng)"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [Câìp ðôò] [% exp] [Tên nhân vâòt] - Thay ðôÒi câìp ðôò vaÌ phâÌn trãm exp cuÒa nhân vâòt coì tên týõng ýìng"
	/////////////////////////////////////////////////
	// start 2011-09-05 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] - ÆÄÆ®³Ê ·¹º§À» Á¶Á¤ÇÔ"
	// end 2011-09-05 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷
	/////////////////////////////////////////////////
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible - TaÌng hiÌnh võìi ngýõÌi khaìc"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf – ChiÒ dùng ðêÒ thýÒ"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"ChiÒ sôì kinh nghiêòm"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"TiêÌn" //"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"Khôi phuòc chiÒ sôì kinh nghiêòm"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"Trang biò" //"Item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Trang biò hiêìm" //"raceItem"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"Kêìt thuìc"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem|WarPoint] [|rate %f|finish] [time(minute)] - Lâòp, huÒy Event"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"  //"Thông thýõÌng" 
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"  //"Nâng câìp"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finish"// "kêìt thuìc" 
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [standard|super|upgrade|finish]"

	#define STRCMD_CS_COMMAND_CITYWAR					"//citywar"
	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"start"  //"Bãìt ðâÌu"
	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finish"  //"Kêìt thuìc"
	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /citywar [start|finish]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /stealth - TaÌng hiÌnh võìi quaìi vâòt"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll - – Ðýa toaÌn bôò user trong map vêÌ thaÌnh phôì"

// start 2011-10-28 by hskim, EP4 [Æ®¸®°Å ½Ã½ºÅÛ] - Å©¸®½ºÅ» ½Ã½ºÅÛ
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [Æ®¸®°Å ½Ã½ºÅÛ] - Å©¸®½ºÅ» ½Ã½ºÅÛ

// start 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø Å×½ºÆ® ¸í·É¾î
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ¼­¹ö Á¤º¸ º¸±â
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ¸ó½ºÅÍ ¾ÆÀÌÅÛ µå¶ø Å×½ºÆ® ¸í·É¾î

// start 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ¼­¹ö Á¤º¸ º¸±â
// end 2011-06-22 by hskim, »ç¼³ ¼­¹ö ¹æÁö
			   
// 2007-10-30 by cmkwon, ¼¼·Âº° ÇØÇÇ¾Æ¿ö ÀÌº¥Æ® ±¸Çö - ¸í·É¾î Çü½Ä ¼öÁ¤µÊ ¾Æ·¡¿¡¼­ ´Ù½Ã Á¤ÀÇ ÇÔ
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"start"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"end"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /happyEvent [start|end] [ThõÌi gian tiêìn haÌnh(Ðõn viò:Phuìt)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer?? ???? ???, ??? ??? ??? ???? ??? ???
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer duÌng ðêÒ debug"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [Sôì ngýõÌi chõi] - Hiêòn toaÌn bôò ngýõÌi chõi trên server (không phân biêòt map)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - Ðãng kyì võìi server ðêÒ gýÒi môòt tin nhãìn cho Admin khi có Event "
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi – Hiêòn toaÌn bôò Protocol trao ðôÒi giýÞa Client và IM server"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - Tãìt Maìy chuÒ"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [Tên nhân vâòt]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [Tên nhân vâòt] – di chuyêÒn ðêìn nõi coì nhân vâòt týõng ýìng "
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [Tên nhân vâòt] - Goòi nhân vâòt týõng ýìng ðêìn viò triì hiêòn taòi"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuildi"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [Tên Haòm ðôòi] - Goòi toaÌn bôò thaÌnh viên trong Haòm ðôòi týõng ýìng"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [Tên Haòm ðôòi] [Tên map] – Di chuyêÒn thành viên Haòm ðôòi tõìi map týõng ýìng"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Chãòn vaÌ BoÒ chãòn caìc tin nhãìn riêng (PM)"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Hiêòn thông tin Haòm ðôòi"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"  //"Cõ baÒn"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"clear"  //"Nãìng"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"rain"  //"Mýa"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"snow"  //"Tuyêìt"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"cloudy"  //"Âm u"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"foggy"  //"Sýõng mù"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"whole"  //"toaÌn bôò"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"  //"bâòt"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"  //"Tãìt"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - ÐiêÌu chiÒnh thõÌi tiêìt"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [Tên nhân vâòt] [ThõÌi gian(phuìt)] – Ðãòt chêì ðôò câìm Noìi chuyêòn võìi thaÌnh viên coì tên vaÌ thõÌi gian phaòt týõng ýìng"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [Tên nhân vâòt] – BoÒ chêì ðôò câìm chaìt"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command" //"lêònh"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - Danh saìch caìc lêònh coì thêÒ sýÒ duòng"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /bonusStat [Sôì ðiêÒm thýõÒng] [Tên nhân vâòt] – Tãng ðiêÒm thýõÒng võìi sôì lýõòng cho thaÌnh viên týõng ýìng"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor?? ???? ???, ??? ??? ??? ???? ??? ???
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /setPassword [Tên taÌi khoaÒn] [Mâòt khâÒu] - Ðãòt Mâòt khâÒu cho taÌi khoaÒn"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /rollbackPassword [Tên taÌi khoaÒn] - Phuòc hôÌi laòi mâòt khâÒu cuÒa taÌi khoaÒn"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /passwordList - Danh saìch mâòt khâÒu"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [Xâu seÞ maÞ hóa]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /blockAccount [Tên taÌi khoaÒn] - Khoìa taÌi khoaÒn"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /releaseAccount [Tên taÌi khoaÒn] - BoÒ khoìa taÌi khoaÒn"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /blockedList - Danh saìch caìc taÌi khoaÒn biò khoìa"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Không có thiÌ thôi!!! ChiÒ týõng ýìng võìi Cao bôÌi không gian !!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Baòn haÞy ðiêÌn tên ðãng nhâòp server"
	#define STRCMD_CS_COMMON_DB_0002 "Baòn haÞy ðiêÌn mâòt khâÒu "
	#define STRCMD_CS_COMMON_DB_0003 "Baòn haÞy ðiêÌn tên ðãng nhâòp DB"
	#define STRCMD_CS_COMMON_DB_0004 "Baòn haÞy ðiêÌn mâòt khâÒu "

	#define STRCMD_CS_COMMON_MAP_0000 "PhâÌn hard coding: BoÒ qua muòc tiêu 1 õÒ map 0101, câÌn tiÌm ra phýõng phaìp ðêÒ có thêÒ loaòi boÒ dêÞ dàng týÌ Map editor và câÌn thýòc hiêòn viêòc loaòi boÒ!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "PhâÌn hard coding: BoÒ qua muòc tiêu 1 õÒ map 0101, câÌn tiÌm ra phýõng phaìp ðêÒ có thêÒ loaòi boÒ dêÞ dàng týÌ Map editor và câÌn thýòc hiêòn viêòc loaòi boÒ!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] Quaìi vâòt xuâìt hiêòn[%8d] ThõÌi gian xuâìt hiêòn[%6dgiây], Viò triì(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index trùng Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] quái vâòt xuâìt hiêòn[%8d] ThõÌi gian xuâìt hiêòn[%6dgiây], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== Bao gôÌm quái vâòt \r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "LôÞi taÒi file"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "LôÞi taòo file"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "LôÞi ðoòc taÒi file"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d ngaÌy %d giõÌ %d phút %d giây"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"Normal"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"Vatallus"
	#define STRCMD_CS_COMMON_RACE_DECA			"DECA"
	#define STRCMD_CS_COMMON_RACE_PHILON		"Phillon"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"Shrine"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Reserve"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Reserve"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"Administrator"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"Game Master"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"Monitor"
	#define STRCMD_CS_COMMON_RACE_GUEST			"Guest"
	#define STRCMD_CS_COMMON_RACE_DEMO			"For demo"
	#define STRCMD_CS_COMMON_RACE_ALL			"All race"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"Unknown race"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Không có tên"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Phi công sõ câìp"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"Phi công câìp 3"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"Phi công câìp 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"Phi công câìp 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"Wingman câìp 3"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"Wingman câìp 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"Winman câìp 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"Týõìng câìp 3 "
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"Týõìng câìp 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"Týõìng câìp 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"Ace câìp 3 "
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"Ace câìp 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"Ace câìp 1"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Thiêìu týõìng"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Thýõòng týõìng"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Trung týõìng"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"Ðaòi týõìng"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"Týò ðôòng"
	#define STRCMD_CS_ITEMKIND_VULCAN				"Súng tiêÒu liên"
	#define STRCMD_CS_ITEMKIND_DUALIST				"Súng bãìn ðôi"		// 2005-08-01 by hblee : ChuyêÒn GRENADE -> DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"Ðaòi pháo"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Loaòi súng trýõÌng"
	#define STRCMD_CS_ITEMKIND_GATLING				"Gatling"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"Bêò phóng"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Massdriver"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Rocket"
	#define STRCMD_CS_ITEMKIND_MISSILE				"Tên lýÒa"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"Bãìn chùm"

	#define STRCMD_CS_ITEMKIND_MINE					"MiÌn"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Shield"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Dummy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"Gãìn"
	#define STRCMD_CS_ITEMKIND_DECOY				"Làm nhiêÞu raða"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Thiêìt biò phoÌng ngýò"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"Ðôòng cõ"
	#define STRCMD_CS_ITEMKIND_ENERGY				"Nãng lýõòng"
	#define STRCMD_CS_ITEMKIND_INGOT				"Kim loaòi"
	#define STRCMD_CS_ITEMKIND_CARD					"TheÒ thông thýõÌng"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"TheÒ nâng câìp"
	#define STRCMD_CS_ITEMKIND_TANK					"Xe tãng"
	#define STRCMD_CS_ITEMKIND_BULLET				"Ðaòn"
	#define STRCMD_CS_ITEMKIND_QUEST				"Quest"
	#define STRCMD_CS_ITEMKIND_RADAR				"Raða"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"Máy tính"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"TheÒ gamble"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"TheÒ chôìng xóa"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Blaster"	// 2005-08-01 by hblee : thêm Loaòi blaster.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Railgun"		// 2005-08-01 by hblee : thêm Loaòi railgun.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"ÐôÌ không giõìi haòn"		// 2006-03-17 by cmkwon, 
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"ÐôÌ biò giõìi haòn thõÌi gian"		// 2006-03-17 by cmkwon, 
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"Toàn bôò vuÞ khiì"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"VuÞ khiì cõ baÒn"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"VuÞ khiì cõ baÒn - Loaòi Bullet"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"VuÞ khiì cõ baÒn - Loaòi Fuel"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"VuÞ khiì cao câìp"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"VuÞ khiì cao câìp - Loaòi Bullet"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"VuÞ khiì cao câìp - Loaòi Shield"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"KyÞ nãng công kiìch"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"KyÞ nãng phoÌng ngýò"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"KyÞ nãng hôÞ trõò"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"KyÞ nãng riêng"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item duÌng cho  quái vâòt loaòi 1"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Loaòi suìng daÌnh cho quái vâòt (Loaòi 1-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Loaòi suìng bãìn tia daÌnh cho quaìi vâòt (Loaòi 1-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"Tâìn công toaÌn bôò quaìi vâòt"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item daÌnh cho quaìi vâòt loaòi 2"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Loaòi rocket daÌnh cho quaìi vâòt (Loaòi2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Loaòi tên lýÒa daÌnh cho quaìi vâòt (Loaòi2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Loaòi suìng bãìn chuÌm daÌnh cho quaìi vâòt (Loaòi2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Loaòi miÌn daÌnh cho quaìi vâòt (Loaòi2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Loaòi Shield daÌnh cho quaìi vâòt (Loaòi2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Loaòi dummy daÌnh cho quaìi vâòt (Loaòi2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Loaòi gãìn daÌnh cho quaìi vâòt (Loaòi2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Loaòi laÌm nhiêÞu raða daÌnh cho quaìi vâòt (Loaòi2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Loaòi fire daÌnh cho quaìi vâòt"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Loaòi suìng bãìn tia daÌnh cho quaìi vâòt"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Loaòi bom daÌnh cho quaìi vâòt"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Item không xaìc ðiònh "

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Loaòi phi cõ không xaìc ðiònh"

	#define STRCMD_CS_STAT_ATTACK_PART				"Công kiìch"
	#define STRCMD_CS_STAT_DEFENSE_PART				"PhoÌng ngýò"
	#define STRCMD_CS_STAT_FUEL_PART				"Nhiên liêòu"
	#define STRCMD_CS_STAT_SOUL_PART				"KyÞ nãng"
	#define STRCMD_CS_STAT_SHIELD_PART				"Giaìp"
	#define STRCMD_CS_STAT_DODGE_PART				"Linh hoaòt"
	#define STRCMD_CS_STAT_BONUS					"ChiÒ sôì"
	#define STRCMD_CS_STAT_ALL_PART					"Caìc chiÒ sôì"
	#define STRCMD_CS_STAT_UNKNOWN					"ChiÒ sôì không xaìc ðiònh"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Loaòi týò do"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Loaòi tâìn công"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Loaòi ða daòng"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Loaòi công kiìch"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Loaòi tránh"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Loaòi công kiìch"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Loaòi giaìp"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Loaòi phoÌng ngýò"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Loaòi chi viêòn"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ¼¼·Âº° ÇØÇÇ¾Æ¿ö ÀÌº¥Æ® ±¸Çö - ¾Æ·¡¿¡¼­ ´Ù½Ã Á¤ÀÇ ÇÔ
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Quân cõ baÒn Bygeniou"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Quân chính thýìc Bygeniou"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Quân chính thýìc Arlington "
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Quân liên bang Vatallus "

	#define STRCMD_CS_POS_PROW						"Viò triì raða (Trên cuÌng, õÒ giýÞa)"
	#define STRCMD_CS_POS_PROWIN					"Máy tính (ÕÒ giýÞa, bên traìi)"
	#define STRCMD_CS_POS_PROWOUT					"VuÞ khiì cõ baÒn (Trên cuÌng, bên trái)"
	#define STRCMD_CS_POS_WINGIN					"Chýa sýÒ duòng (ÕÒ giýÞa, bên phaÒi)"
	#define STRCMD_CS_POS_WINGOUT					"VuÞ khiì cao câìp (Trên cuÌng, bên phaÒi)"
	#define STRCMD_CS_POS_CENTER					"VoÒ phi cõ (ÕÒ giýÞa, trung tâm)"
	#define STRCMD_CS_POS_REAR						"Ðôòng cõ (Dýõìi cuÌng, õÒ giýÞa)"

	// 2010-06-15 by shcho&hslee Æê½Ã½ºÅÛ
	//#define STRCMD_CS_POS_ATTACHMENT				"ºÎÂø¹°(ÈÄ¹Ì ¿ìÃø-¿¬·áÅÊÅ©|ÄÁÅ×ÀÌ³Ê°è¿­)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessory(Right side of rear-Fueltank|container type)"

	// 2010-06-15 by shcho&hslee Æê½?½ºÅÛ
	//#define STRCMD_CS_POS_PET						"Chýa sýÒ duòng (phiìa dýõìi bên traìi)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Chýa sýÒ duòng (phiìa dýõìi bên traìi)"
	
	#define STRCMD_CS_POS_PET						"Partner"
	
    #define STRCMD_CS_HIDDEN_ITEM					"Hidden Position"		// 2011-09-20 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷ - ¼û°ÜÁø ¾ÆÀÌÅÛ

	#define STRCMD_CS_POS_INVALID_POSITION			"Viò trí chýa xác ðiònh"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Viò trí kho ðôÌ"
	
	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/questCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/questCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /questCom - HoaÌn thaÌnh nhiêòm vuò hiêòn thõÌi"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /InflDist - TyÒ lêò giýÞa hai quôìc gia"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/inflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/inflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /inflChange [|1(ThýõÌng)|2(BCU)|4(ANI)] - Thay ðôÒi quôìc gia. 1 laÌ trung lâòp, 2 laÌ BCU, 4 laÌ ANI"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/goMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/goMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /goMonster [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ× - ÁÖ¼® Ã³¸® ¹ØÀ¸·Î ÀÌµ¿
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Thành viên"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"Haòm ðôòi trýõÒng"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"ChiÒ huy phi ðoaÌn 1"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"Thành viên phi ðoaÌn 1 "
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"ChiÒ huy phi ðoaÌn 2"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"Thành viên phi ðoaÌn 2"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"ChiÒ huy phi ðoaÌn 3"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"Thành viên phi ðoaÌn 3"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"ChiÒ huy phi ðoaÌn 4"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"Thành viên phi ðoaÌn 4"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"ChiÒ huy phi ðoaÌn 5"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"Thành viên phi ðoaÌn 5"

// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /Noticeboard [|ThõÌi gian:phuìt] [Nôòi dung] - Hiêòn thông baìo võìi thõÌi gian týõng ýìng trên baÒng ðiêòn týÒ trong thaÌnh phôì."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [chiÒ sôì thông baìo câÌn xoìa] - Xoìa môòt thông baìo trên baÒng ðiêòn týÒ."	

	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"AÒnh hýõÒng cuÒa thuÒ liÞnh"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Phoì ThuÒ liÞnh"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"AÒnh hýõÒng cuÒa buff"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"Sýò kiêòn quôìc gia"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Quôìc gia(2:BCU|4:ANI)] [Sôì ðiêÒm] - Tãng ðiêÒm chiêìn công cuÒa 1 quôìc gia"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [Nôòi dung câu hoÒi] - Ðãòt câu hoÒi cho GM."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [Danh saìch sôì(1~10)] - KiêÒm tra danh saìch câu hoÒi tõìi GM "
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [Danh saìch sôì(1~10)] - ChuyêÒn danh saìch câu hoÒi tõìi GM (Xoìa khoÒi server)"

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
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(ThýõÌng)|2(BCU)|4(ANI)|3|5|6|7] [MAÞ item] [Sôì lýõòng] - Tãòng moìn ðôÌ võìi sôì lýõòng týõng ýìng ðêìn toaÌn bôò ngýõÌi chõi cuÒa quôìc gia týõng ýìng trong map hiêòn taòi."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ³ª¶óº° ³¯Â¥ Ç¥Çö ¹æ½ÄÀÌ ´Ù¸£´Ù
	// ÇÑ±¹(Korea):		YYYY-MM-DD HH:MM:SS
	// ¹Ì±¹(English):	MM-DD-YYYY HH:MM:SS
	// º£Æ®³²(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", D, M, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", D, M, Y, h, m

	// 2006-08-08 by dhjin, ·¹º§ºÐÆ÷
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - HiêÒn thiò tyÒ lêò phân bôì vêÌ câìp ðôò cuÒa ngýõÌi chõi hiêòn taòi."	// 2006-08-08 by dhjin

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"ÐôÌ ngâÞu nhiên"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"CõÌ"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// Å¬¶óÀÌ¾ðÆ®¿¡¼­¸¸ »ç¿ëÇÏ´Â ¸í·É¾î(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [Tên nhân vâòt] - ÐêÌ nghiò noìi chuyêòn 1:1."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - Bâòt chêì ðôò noìi chuyêòn giýÞa caìc thaÌnh viên trong phi ðôòi. ChiÒ Phi ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - Kêìt thuìc chêì ðôò noìi chuyêòn giýÞa caìc thaÌnh viên trong phi ðôòi. ChiÒ Phi ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - Bâòt chêì ðôò noìi chuyêòn giýÞa caìc thaÌnh viên trong Haòm ðôòi. ChiÒ Haòm ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - Kêìt thuìc chêì ðôò noìi chuyêòn giýÞa caìc thaÌnh viên trong Haòm ðôòi. ChiÒ Haòm ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - Kêìt thuìc chêì ðôò noìi chuyêòn trong phi ðôòi, haòm ðôòi hoãòc caì nhân."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [Tên nhân vâòt] - ÐêÌ nghiò ðâìu tay ðôi (PvP) võìi ngýõÌi chõi khaìc."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [Tên nhân vâòt] -  GýÒi lõÌi ðêÌ nghiò ðâÌu haÌng tõìi ðôìi thuÒ trong khi ðâìu PvP."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [Tên phi ðôòi trýõÒng] - ÐêÌ nghiò Ðâìu phi ðôòi võìi môòt phi ðôòi khaìc. ChiÒ Phi ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [Tên nhân vâòt] -  ÐêÌ nghiò Ðâìu haòm ðôòi võìi môòt Haòm ðôòi khaìc. ChiÒ Haòm ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  ÐâÌu haÌng trâòn ðâìu Haòm ðôòi. ChiÒ Haòm ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [Tên nhân vâòt] [Lõìp(2 ~ 11)] - Thay ðôÒi Lõìp ðaÞ ðýõòc bôÒ nhiêòm cho thaÌnh viên trong Haòm ðôòi. ChiÒ Haòm ðôòi trýõÒng mõìi coì quyêÌn sýÒ duòng."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  Xoìa cýÒa sôÒ chat."
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - Bâòt/Tãìt chêì ðôò týÌ chôìi PvP."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  Bâòt/Tãìt chêì ðôò týÌ chôìi Trao ðôÒi."
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Không hiêòn lên caìc cýÒa sôÒ hôòi thoaòi. CýÒa sôÒ seÞ týò ðoìng."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Cho pheìp sýÒ duòng moòi loaòi hôòp thoaòi."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Thiêìt biò kyÞ nãng hôÞ trõò"

// 2010-06-15 by shcho&hslee Æê½?½ºÅÛ - Æê ¾ÆÀ?ÅÛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Vâòt phâÒm Partner"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner Socket Item"		// 2011-09-01 by hskim, ÆÄÆ®³Ê ½Ã½ºÅÛ 2Â÷

// 2006-11-17 by cmkwon, º£Æ®³² ÇÏ·ç °ÔÀÓ ½Ã°£ °ü·Ã
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - Lêònh Bâòt/Tãìt hêò thôìng Giõìi haòn giõÌ chõi."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - DuÌng ðêÒ hiêÒn thiò tôÒng thõÌi gian ðaÞ chõi trong ngaÌy."

// 2007-10-06 by cmkwon, ºÎÁöµµÀÚ 2¸íÀÇ È£ÄªÀ» ´Ù¸£°Ô ¼³Á¤ - ¾Æ·¡¿¡ ¼¼·Âº°·Î ´Ù¸£°Ô Á¤ÀÇÇÔ
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"ThuÒ liÞnh"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Phoì ThuÒ liÞnh"

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
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: Subleader [CharacterName] - choòn phoì thuÒ liÞnh"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"HuyÒ boÒ choòn phoì thuÒ liÞnh."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"ÐaÞ coì ðuÒ phoì thuÒ liÞnh"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s¸ðýõòc choòn laÌm phoì thuÒ liÞnh thýì nhâìt."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s¸ðýõòc choòn laÌm phoì thuÒ liÞnh thýì hai."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"Không coì nhân vâòt %s ."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s´hiêòn ðang laÌm phoì thuÒ liÞnh."

// 2007-02-23 by dhjin, °ÅÁ¡Á¤º¸
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/StrategyPointInfo¸"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /StrategyPointInfo - thông baìo tiÌnh traòng cuÒa truò chiêìn thuâòt."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"Không coì truò chiêìn thuâòt naÌo."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"Truò chiêìn thuâòt ìðaÞ xuâìt hiêòn"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"VuÌng"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"ThõÌi gian bãìt ðâÌu"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-Gear"
#define STRCMD_CS_UNITKIND_MGEAR					"M-Gear"
#define STRCMD_CS_UNITKIND_AGEAR					"A-Gear"
#define STRCMD_CS_UNITKIND_IGEAR					"I-Gear"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"B-Gear All"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"M-Gear All"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"A-Gear All"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"I-Gear All"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"Gear All"

// 2007-03-30 by dhjin, ¿ÉÀú¹ö ¸ðµå À¯Àú µî·Ï
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  "/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  "/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  "/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  "/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   "/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   "/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   "format: /Observer [n] [Tên nhân vâòt] ? Gaìn tên nhân vâòt câÌn quan saìt cho phiìm sôì n"

// 2007-04-10 by cmkwon, Jamboree server ±º °ü·?
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [Sôì xaìc nhâòn] - KhõÒi taòo dýÞ liêòu cho maìy chuÒ Jamboree(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [Tên nhân vâòt] - Thông tin vêÌ nhân vâòt seÞ ðýõòc chuyêÒn tõìi maìy chuÒ Jamboree(atum2_db_20)."
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
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "Apprentice"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "Junior"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "Airman"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "Wingman"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "Ace"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "Veteran"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "Top gun"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "Wing commander"
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
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Không tiÌm thâìy nhoìm."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)]- HiêÒn thiò thông tin arena hiêòn taòi."

// 2010. 06. 04 by hsLee ARENA ÀÎÇÇ´ÏÆ¼ °ü·Ã. - 
// 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµå 2Â÷ ³­ÀÌµµ Á¶Àý. (GM ¸í·É¾î Ãß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£Ãâ.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ÀÎÆ¼ÇÇ´Ï ÇÊµå 2Â÷ ³­ÀÌµµ Á¶Àý. (GM ¸í·É¾î Ãß°¡. /nextscene(´ÙÀ½ ½Ã³×¸¶ ¾À È£Ãâ.) )

// 2007-06-15 by dhjin, °üÀü
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-KhõÒi ðôòng chêì ðôò quan saìt."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd – Kêìt thuìc chêì ðôò quan saìt."

// 2007-06-22 by dhjin, WarPoint Ãß°¡
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [sôì lýõòng 1~1000000] [|Tên nhân vâòt] – Tãng ðiêÒm danh voòng."
 
// 2007-06-26 by dhjin, ¿öÆ÷ÀÎÆ® ÀÌº¥Æ® °ü·Ã Ãß°¡
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT	 "WarPoint"	 

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena "
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [Tên nhân vâòt] [ThõÌi gian(phuìt)] - Không cho pheìp truy câòp Arena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena "
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [Tên nhân vâòt] - BoÒ chêì ðôò câìm truy câòp Arena"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "CõÌ haòm ðaÞ ðýõòc ðãng kyì thaÌnh công."
#define STRMSG_070802_0002    "CâÌn sýò cho pheìp trýõìc khi coì thêÒ sýÒ duòng cõÌ haòm."
#define STRMSG_070802_0003    "Baòn cho pheìp duÌng cõÌ haòm %d naÌy chýì?"
#define STRMSG_070802_0004    "Không coì ðãng kyì mõìi naÌo"
#define STRMSG_070802_0005    "Ðang trong traòng thaìi chõÌ"
#define STRMSG_070802_0006    "ÐaÞ ðýõòc cho pheìp"
#define STRMSG_070802_0007    "Coì lôÞi xaÒy ra"

// 2007-08-24 by cmkwon, ½ºÇÇÄ¿¾ÆÀÌÅÛ »ç¿ë °¡´É/±ÝÁö ¼³Á¤ ±â´É Ãß°¡ - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Enable"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Forbid"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Cho pheìp / Không cho pheìp sýÒ duòng Thiêìt biò truyêÌn tin"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] ChuâÒn biò dýÌng server."

// 2007-08-30 by cmkwon, È¸ÀÇ·ë ½Ã½ºÅÛ ±¸Çö - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/chophep"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[chophep | EntrancePermission] [|Tên nhân vâòt] – Cho pheìp nhân vâòt týõng ýìng vaÌo phoÌng hôòi nghiò. ChiÒ thuÒ liÞnh mõìi coì thêÒ sýÒ duòng"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/khongchophep"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[khongchophep | EntrancePermissionDeny] [Tên nhân vâòt] – Không cho pheìp nhân vâòt týõng ýìng vaÌo phoÌng hôòi nghiò. ChiÒ thuÒ liÞnh mõìi coì thêÒ sýÒ duòng."

// 2007-10-05 by cmkwon, ¿¬¿ùÀÏÀ» ³ª¶óº°·Î ´Ù¸£°ÔÇÏ±â À§ÇØ
#define STRCMD_071005_0000					"%d ngaÌy %d giõÌ %d phút %d giây", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d Thaìng %d Nãm %d", Day, Month, Year
#define STRCMD_071005_0002					"Thaìng %d Nãm %d",  Month, Year
#define STRCMD_071005_0003					"%d Thaìng %d", Day, Month


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Phoì ChiÒ huy trýõÒng" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Tham mýu trýõÒng" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"TôÒng tý lêònh"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Phoì TôÒng tý lêònh"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Tham mýu trýõÒng"
#define STRCMD_ANI_INFLUENCE_LEADER						"TôÒng thôìng"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Phoì TôÒng thôìng"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Tham mýu trýõÒng"
#define STRCMD_OUTPOST_GUILD_MASTER						"ThuyêÌn trýõÒng %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/subleader1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [tên nhân vâòt] - ChiÒ ðiònh nhân vâòt seÞ giýÞ chýìc vuò Phoì TôÒng tý lêònh hoãòc Phoì TôÒng Thôìng "
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/subleader2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [tên nhân vâòt] - ChiÒ ðiònh nhân vâòt seÞ giýÞ chýìc vuò Tham mýu trýõÒng"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT   "/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1   "/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART  "Start"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND  "End"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP  "format: /HappyEvent [255(Tâìt caÒ)|0(Normal nation)|2(BCU)|4(ANI)] [Start|End] [ThõÌi gian (phuìt)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL   "Normal nation"
#define STRCMD_CS_INFLUENCE_TYPE_VCN   "Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI   "Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK  "AllNation"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0   "/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1   "/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2   "/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP  "format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - Tãng ðiêÒm WP cho tâìt caÒ ngýõÌi chõi trong map."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|ThõÌi gian(ðõn viò: phuìt)] - Cho pheìp sýÒ duòng callGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Không cho sýÒ duòng lêònh CallGM"

// 2007-12-27 by cmkwon, À©µµ¿?Áî ¸?µå ±â´É ?ß°¡ - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW ?ß°¡
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, À©µµ¿?¸?µå »óÅÂ ÀúÀåÇÏ±â - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, °èÁ¤ ºí·°/ÇØÁ¦ ¸í·É¾î·Î °¡´ÉÇÑ ½?½ºÅÛ ±¸Çö - ¸í·É¾î ?ß°¡
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [Tên taÌi khoaÒn] [KiêÒu (1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [ThõÌi haòn: ngaÌy] [Lyì do cho ngýõÌi duÌng] / [Lyì do cho admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [Tên taÌi khoaÒn]"

// 2008-02-20 by cmkwon, ¸í·É¾îÃß°¡(Á¢¼ÓÁßÀÎÀ¯Àú¸ðµÎ¿¡°Ô¾ÆÀÌÅÛÁö±Þ- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [MaÞ Item] [Sôì lýõòng] - GýÒi item cho tâìt caÒ caìc nhân vâòt ðang online, không phân biêòt map."

// 2008-02-21 by dhjin, ¾Æ·¹³ªÅëÇÕ- ¾Æ·¹³ªÃß°¡¸í·É¾î
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(XANH)|4(ÐOÒ)|6(XANH vaÌ ÐOÒ)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Tên nhân vâòt]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [Sôì phoÌng]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [Sôì phoÌng]"

// 2008-06-03 by cmkwon, AdminTool, DBTool »ç¿ë½Ã ¾ÆÀÌÅÛ °Ë»ö½Ã ÄÞº¸¹Ú½º¿¡¼­ °Ë»ö ±â´É Ãß°¡(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"Tâìt caÒ"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ×          // 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"ThaÌnh viên"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Haòm trýõÒng"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Haòm phoì"		// 2008-05-20 by dhjin, EP3 - ¿©´Ü ¼öÁ¤ »çÇ×
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"ChiÒ huy phi haÌnh ðoaÌn 1"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"ThaÌnh viên phi haÌnh ðoaÌn 1"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"ChiÒ huy phi haÌnh ðoaÌn 2"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"ThaÌnh viên phi haÌnh ðoaÌn 2"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"ChiÒ huy phi haÌnh ðoaÌn 3"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"ThaÌnh viên phi haÌnh ðoaÌn 3"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"ChiÒ huy phi haÌnh ðoaÌn 4"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"ThaÌnh viên phi haÌnh ðoaÌn 4"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"ChiÒ huy phi haÌnh ðoaÌn 5"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"ThaÌnh viên phi haÌnh ðoaÌn 5"
 
//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ÀüÀåÁ¤º¸
#define STRCMD_COMMAND_WAR_OPTION_0					"/Mothershipinfooption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/Mothershipinfooption"

// 2008-08-18 by dhjin, ¼¼·Â¸¶Å©À?º¥Æ® 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [2(BCU) | 4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ÅÂ±¹ PC¹æ IPÁ¤º¸ ·Îµù
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Phuìt] - 10 phuìt ~ 1440 phuìt"


// 2008-08-21 by dhjin, ÀÏ¹?, Æ¯¼ö °èÁ¤ÀÇ ºÎÁöµµÀÚ ÀÓ¸í Á¦ÇÑ
#define STRMSG_080821_0001				"Không thêÒ bôÒ nhiêòm nhân vâòt ðaÞ choòn võìi viò triì naÌy."


// 2008-09-09 by cmkwon, /¼¼·Â¼?È¯ ¸í·É¾î ÀÎÀÚ ¸®½ºÆ®¿¡ ±â¾îÅ¸ÀÔ ?ß°¡ - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [Sôì lýõòng] [0|Level thâìp nhâìt] [0|Level lõìn nhâìt] [1(B-Gear)|16(M-Gear)|256(A-Gear)|4096(I-Gear)] [Tin nhãìn] - Goòi toaÌn bôò thaÌnh viên trong quôìc gia võìi câìp ðôò vaÌ loaòi gear týõng ýìng ðêìn viò triì hiêòn taòi - keÌm theo môòt tin nhãìn"

// 2008-09-09 by cmkwon, "/kick" ¸í·É¾î ?ß°¡ - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [Tên nhân vâòt] - Ngãìt kêìt nôìi cuÒa nhân vâòt týõng ýìng võìi server."


// 2008-09-12 by cmkwon, "/¸í¼º" ¸í·É¾î ?ß°¡ - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /fame [ðiêÒm chiêìn công caì nhân] [ðiêÒm chiêìn công haòm ðôòi] - Tãng ðiêÒm chiêìn công caì nhân vaÌ haòm ðôòi cuÒa nhân vâòt týõng ýìng."

// 2008-12-30 by cmkwon, ÁöµµÀÚ Ã¤ÆÃ Á¦ÇÑ Ä«µå ±¸Çö - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /ReleaseLeaderChatBlock [Tên nhân vâòt] - MõÒ câìm chaìn cuÒa Leader."

// 2009-10-12 by cmkwon, ÇÁ¸®½ºÄ« Á¦°Å ¹æ¾È Àû¿ë - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "/StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|CharacterName] - Set the character`s beginning city to 2001 or 2002 when their nation is initialized."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, ÃÖ´ë ·¹º§ »óÇâ¿¡ µû¸¥ Ãß°¡ »çÇ×(·¹º§º° °è±Þ) - °è±Þ¶æ(¹éºÎÀå, ´ë·É, Àå±º, ÃÑµ¶, Á¤º¹ÀÚ, ¼öÈ£ÀÚ, Àü¼³ÀûÀÎ)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurion"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Colonel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Governer"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conqueror"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardian"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legendary"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Basic"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, ¾Æ·¹³ª Á¾·á ¸í·É¾î ¼öÁ¤

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸í·É¾î Ãß°¡
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/¸ÊÀÌµ¿Á¦ÇÑ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /¸ÊÀÌµ¿Á¦ÇÑ [MapIndex] - ÇØ´ç ¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀ» ¼³Á¤ÇÔ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ¼³Á¤ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]¸ÊÀÇ ¿öÇÁ Á¦ÇÑÀÌ ÇØÁ¦ µÇ¾ú½À´Ï´Ù."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]´Â Çã¿ëÇÏÁö ¾Ê´Â ¸Ê¹øÈ£ÀÔ´Ï´Ù."
// end 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ - ¸í·É¾î Ãß°¡



#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"


#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Information on players formation member's (member's must log inside the game)"


#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





