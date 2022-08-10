// 2005-04-28 by cmkwon
// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - �������, �������������� �� FieldServer
	#define STRCMD_CS_COMMAND_GET_WARPOINT_ALL_USER		"/wpalluser"
	#define STRCMD_CS_COMMAND_GET_RND_DGA_TIMES			"/getrndtimes"
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/������"
	#define STRCMD_CS_COMMAND_MENT_2					"/�"
	#define STRCMD_CS_COMMAND_MENT_HELP					"������: /ment ��� /������ ��� /� [|�����] - ���������� ment ���������;"
	#define STRCMD_CS_COMMAND_MOVE					"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"������: /move [ID_�����] [|�_������] - ������� �� ������������ ����� �����;"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coor"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"������: /coordinate ��� /coor [X] [Y] - ������� � �������� �����������;"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"������: /list - ������ ������������� �� ����� (����. 20);"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"������: /senduser [���_������] [ID_�����] - ������� ��������� �� �������� �����;"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"������: /info [ID_���� ��� ID_��������] - ���� � ������� ��� ��������;"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"������: /quest - ������ �� �������;"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"������: /delQuest [�_������] � �������� �����;"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1		"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"������: /itemKind [|���_��������(0~53)] - �������� �������� ��������� ����;"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"������: /insertItemKind [���_��������(0~53)] -  Additional specific types of items;"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"������: /insertItemNumRange [��_��������]~[�_��������] - Additional specific items;"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStat"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"������: /initStatus ��� /initStat - ������������ ��� ���������;"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"������: /partyInfo - �������� ���������� � �����;"
	#define STRCMD_CS_COMMAND_GAMETIME					"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"������: /Time [|���������������_�����(0~23)] - �������� ������� ����� (�������� ���� ������ �����);"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"������: /string [0~5] - Decides levels shown by debug message;"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"������: /summon [ID_����|���_����] [���-��] - �������� ������� ('_'������������ ������ �������);"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"������: /allSkill [�������] - ������������ ��� ���������� ������;"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"������: /allItem - ������������ ��� ��������� ��������, ����� ������ � ����������� ���������;"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"������: /allWeapon - ��� ����������, ���������� ������� �������;"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAll"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"������: /delAllItem ��� /delAll - ���������� ��� ��������������� �������� (�������� ������);"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"������: /item [ID_��������] [���-��] - �������� ��������;"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"������: /dropItem [ID_��������] [|���-��] - �������� ������� �� ����;"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"������: /server - �������� ������ � �������;"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"������: /serverMap - �������� ������ ��� ���� ������;"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"������: /channelInfo - �������� ���������� � ������ ������� ����� �� ������� �����;"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"������: /dbg - ������ ��� ������������;"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"������: /testf [Param1] [Param2] [Param3];"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/bullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"������: /chargeBullet ��� /bullet [|���-��_���._�������] [|���-��_��._�������] � ��������� ��������;"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/heal"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"������: /repairAll ��� /heal [|���_������] - ������������ HP, UTC, ������� �� 100%;"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/healparam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"������: /repairParam ��� /healparam [|%_����������] [|���_������] - HP, UTC, � ������� �������� ���������� [%_����������];"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/user"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"������: /normal ��� /user - ������� ��� �������� � ������������������ ��� �� �� �������;"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/admin"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"������: /specialize ��� /admin - ������� ��� �������� � �������� �� ����������������� ��� ��;"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/god"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"������: /invincible ��� /god - ���������� � ������ �� ��� ��������������;"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"������: /powerUp [��������(%)];"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"������: /setVariable [variable] - adjusts (normal) variables;"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"������: /level [|�������] [|%_�����] [|���_������] - ������������� ������� � ������� ����� ���������;"
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/ghost"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"������: /invisible ��� /ghost - ����������� ��� ������ ����������;"
	#define STRCMD_CS_COMMAND_USERCOUNT					"/count"


    #define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "
	
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"������: /msgf - ������ ��� ������������;"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"exppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"rareitem"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"finish"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"������: /event [exppoint|SPI|restoreexppoint|item|rareitem] [|�����(%)|finish] [�����(������)] - ������ �����, ��������;"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finish"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"������: /premium [standard|super|upgrade|finish] - ���������� ��� ��������;"
// 2008-02-14 by cmkwon,   
//	#define STRCMD_CS_COMMAND_CITYWAR					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"start"
//	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finish"
//	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"������: /citywar [start|finish] - �����;"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"������: /stealth - ����������� ��� �����;"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"������: /returnAll [ID_�����] - ��� ����� ������� ����������� �� ��������� �����;"
// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���

// start 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ���� ���� ����
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�

// start 2011-06-22 by hskim, �缳 ���� ����
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ���� ���� ����
// end 2011-06-22 by hskim, �缳 ���� ����
			   
// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ��ɾ� ���� ������ �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"start"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"end"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"������: /happyEvent [start|end] [progress time(unit:min.)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - �������, ������������ �� IMServer. ��������� ������������ � ���� �� ���������, ��� � ����
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"������: /testi - IMServer for debug;"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"������: /who [|���-��_�������] - ������ ������������� �� ������� � ������ ������ (��� ����������� �� �����);"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"������: /registerAdmin - ���� ������� ������� �������� ��������� �������������� � ���� ������;"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"������: /msgi - �������� ������ ��������, ���������� � ���������� �������� � IM ��������;"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"������: /serverDown [certified_no.] - Server shutdown;"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"������: /whoareYou [���_������] - ���� �� ������;"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"������: /go [���_������] - ������������� � ������;"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"������: /comeon [���_������] - ������� ������;"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeongi"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"������: /comeonGuild ��� /comeongi [��������_�������] - ������� ��� �������;"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendgi"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"������: /sendGuild ��� /sendgi [��������_�������] [ID_�����] - ����������� ������� �� ��������� �����;"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"������: /whisperChat ��� /whChat - ���. � ����. ����;"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/giInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"������: /guildInfo ��� /giInfo - �������� ������ � �������;"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"clear"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"rain"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"snow"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"cloudy"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"foggy"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"whole"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"������: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|ID_�����] [on|off] - ���������� �������;"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/banChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"������: /forbidChat ��� /banChat [���_������] [����(������)] - ��������� ���;"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/unbanChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"������: /releaseChat ��� /unbanChat [���_������] - �������� ������ ����;"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"������: /? ��� /help - ������ ������;"
	#define	STRCMD_CS_COMMAND_XCHAT						"123"
	#define	STRMSG_S_GLOBALCHAT_0001					"123"	

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"������: /BonusStat [���-��] [|���_������] - ���������� ����� �������������;"
// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - �������, ������������ � AtumMonitor. ��������� ������������ � ���� �� ���������, ��� � ����
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"������: /setPassword [�����] [������];"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"������: /rollbackPassword [�����];"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"������: /passwordList;"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"������: /encrypt [string_that_will_be_encrypted];"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/accountblock"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/accountblock"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"������: /accountblock [�����] - ���� ��������;"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/unbanAcc"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"������: /releaseAccount ��� /banAcc [�����] - ����� ����;"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/banList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"������: /blockedList ��� /banList - ������ ������������;"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - ����� ������� ������ CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "������ ��� ������� Mgame!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "���������� ������� ���"
	#define STRCMD_CS_COMMON_DB_0002 "���������� ������� ������"
	#define STRCMD_CS_COMMON_DB_0003 "���������� ������� DB ���"
	#define STRCMD_CS_COMMON_DB_0004 "���������� ������� DB ������"

	#define STRCMD_CS_COMMON_MAP_0000 "����� �� ������� �����: ������������ ���� ����������� 1 �� ����� 0101, ���������� ����� ������ ������ �������� �� ��������� ����!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "����� �� ������� �����: ������������ ���� ����������� 1 �� ����� 0101, ���������� ����� ������ ������ �������� �� ��������� ����!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index overlap Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] summon monster[%8d] summon time[%6dsecond], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Total Monster Count : [%4d] <== Including object monster\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "������ ��� ������� �����"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "������ ��� �������� �����"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "������ ������ ����������� �����"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%dday%dhour%dminute%dsecond"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"�������"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"��������"
	#define STRCMD_CS_COMMON_RACE_DECA			"�������"
	#define STRCMD_CS_COMMON_RACE_PHILON		"������"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"�����"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"������"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"������"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"�����"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"��"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"�����������"
	#define STRCMD_CS_COMMON_RACE_GUEST			"�����"
	#define STRCMD_CS_COMMON_RACE_DEMO			"����"
	#define STRCMD_CS_COMMON_RACE_ALL			"��� ����"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"����������"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"��� �����"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"����������"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"�������"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"��������"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"�������"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"��������"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"������"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"���������"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"������"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"������"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"��������"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"�������"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"�������"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"���������"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"�����"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"�������"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"�������"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"������"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"��������������"
	#define STRCMD_CS_ITEMKIND_VULCAN				"������"
	#define STRCMD_CS_ITEMKIND_DUALIST				"���������"		// 2005-08-01 by hblee : changed from GRENADE to DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"��������"
	#define STRCMD_CS_ITEMKIND_RIFLE				"��������"
	#define STRCMD_CS_ITEMKIND_GATLING				"�������"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"�������� ���������"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"���������� �������"
	#define STRCMD_CS_ITEMKIND_ROCKET				"��������"
	#define STRCMD_CS_ITEMKIND_MISSILE				"����������"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"������� ��������� ����"

	#define STRCMD_CS_ITEMKIND_MINE				"������"
	#define STRCMD_CS_ITEMKIND_SHIELD				"����"
	#define STRCMD_CS_ITEMKIND_DUMMY				"�������"			
	#define STRCMD_CS_ITEMKIND_FIXER				"���������"
	#define STRCMD_CS_ITEMKIND_DECOY				"��������"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"������"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"���������"
	#define STRCMD_CS_ITEMKIND_ENERGY				"��������������"
	#define STRCMD_CS_ITEMKIND_INGOT				"�������"
	#define STRCMD_CS_ITEMKIND_CARD				"����������� �����"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"������ ���������"
	#define STRCMD_CS_ITEMKIND_TANK				"��������"
	#define STRCMD_CS_ITEMKIND_BULLET				"����������"
	#define STRCMD_CS_ITEMKIND_QUEST				"���������"
	#define STRCMD_CS_ITEMKIND_RADAR				"�����"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"���������"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"������ ����������"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"������ ������ �� ����������"
	#define STRCMD_CS_ITEMKIND_BLASTER				"����������"	// 2005-08-01 by hblee : Blaster type added.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"���������"		// 2005-08-01 by hblee : Rail gun type added.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"���������� ��������"		// 2006-03-17 by cmkwon, ���ð��� <����>�� �׼����� ������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"��������� ��������"		// 2006-03-17 by cmkwon, ���ð��� �ð� ������ �ִ� �׼����� ������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"��� ���� ������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"���������� ������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"���������� ������ ������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"���������� ������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"�������� ������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"�������� ���������� ������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"�������� ������"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"������ �����"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"������ ������"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"������ ���������"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"������ ����������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"������� ��� ������� 1 ����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"������� ������� (���1-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"������� ������ ������� (���1-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"��������� ���� ��������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"������� ��� ������� 2 ����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"������ ������� (���2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"���������� ������ ������� (���2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"������� ������ ������� (���2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"������ ������ ������� (���2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"������� ������ ������� (���2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"����������� ������ ������� (���2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"��������� ������ ������� (���2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"�������� ������� (���2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"�������� ������ �������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"��������� ������� ��������� �������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"�������� ��������� �������"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"����������� �������"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"����������� �������"

	#define STRCMD_CS_STAT_ATTACK_PART				"�����"
	#define STRCMD_CS_STAT_DEFENSE_PART				"������"
	#define STRCMD_CS_STAT_FUEL_PART				"�������"
	#define STRCMD_CS_STAT_SOUL_PART				"���"
	#define STRCMD_CS_STAT_SHIELD_PART				"���"
	#define STRCMD_CS_STAT_DODGE_PART				"��������"
	#define STRCMD_CS_STAT_BONUS					"�������� ��������"
	#define STRCMD_CS_STAT_ALL_PART					"��� ���������"
	#define STRCMD_CS_STAT_UNKNOWN					"����������� ��������"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"����� ���"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"��� �����"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"���������"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"��� �����"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"��� ��������"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"��� �����"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"��� ����"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"��� ������"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"��� ���������"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"������������ ����� ������ �������"
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"���������� ����� ������ �������"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"���������� ����� ������ ���������"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"����� ������������ ���������"

	#define STRCMD_CS_POS_PROW						"������������ ������(������ � ������)"
	#define STRCMD_CS_POS_PROWIN					"���������(������ �����)"
	#define STRCMD_CS_POS_PROWOUT					"���������� ������(������ �����)"
	#define STRCMD_CS_POS_WINGIN					"�� ������������(� ������ ������)"
	#define STRCMD_CS_POS_WINGOUT					"�������� ������(������ ������)"
	#define STRCMD_CS_POS_CENTER					"����� (� ������ ����������)"
	#define STRCMD_CS_POS_REAR						"���������(����� ����������)"


	// 2010-06-15 by shcho&hslee ��ý���
	//#define STRCMD_CS_POS_ATTACHMENT				"�������������(����� ������, ��������� ��� ��� ���������)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"�������������(����� ������, ��������� ��� ��� ���������)"

	// 2010-06-15 by shcho&hslee ��ý���
	//#define STRCMD_CS_POS_PET						"Not to use(Left rear side)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"�� ������������ (����� �����)"

	#define STRCMD_CS_POS_PET						"�������"

	#define STRCMD_CS_POS_INVALID_POSITION			"��������� ���������"
    #define STRCMD_CS_HIDDEN_ITEM					"Hidden Position"		// 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - ������ ������	
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"��������� ���������"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/QuestComplete"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"������: /QuestComplete ��� /QuestCom [|ID_������];"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/NationRatio"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"������: /NationRatio ��� /InflDist;"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/ChangeNation"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"������: /ChangeNation ��� /InflChange [|1(�������)|2(�������)|4(���������)];"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMon"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"������: /GoMonster ��� /GoMon [ID_����|���_����];"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - �ּ� ó�� ������ �̵�
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"�����"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"����� �������"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"����� ��. �1"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"����� ��. �1"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"����� ��. �2"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"����� ��. �2"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"����� ��. �3"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"����� ��. �3"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"����� ��. �4"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"����� ��. �4"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"����� ��. �5"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"����� ��. �5"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"������: /Noticeboard [|����(������)] [���������] - �������� ������� �� ����������� ����� ���������� �� �������� ���������� �������;"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"������: /DeleteNoticeboard [ID_���������] - ������� �������� ��������� � ����������� ����� ����������;"
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"����� �������"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"�������� �������"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"���� �������"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"����� �������"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"������: /ContributionPoint [�������(2:�������, 4:���������)] [���-��] - ��������� ���� ��������� �������;"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"������: /CallGM  [����_���������] - ���������� � �������������;"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/VCGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"������: /ViewCallGM ��� /VCGM [|�����(1~10)] - ���������� ������ �������� � ���;"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BCGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"������: /BringCallGM ��� /BCGM [|�����(1~10)] - ������� ������ �� ��������� (��������� � �������);"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"	 
// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"������: /ComeOnNation ��� /ComeOnInfl [1(�������)|2(�������)|4(���������)|3|5|6|7] [���-��_�������] [0|���_��.] [0|����_��.] [���������] - �������� ���� ���������� ���������� ������ �����-���� ������� ������������ � ��������� ���������;"
  // 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/AdditemOnMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"������: /SendItem ��� /InsertItemInMap ��� /AdditemOnMap [1(�������)|2(�������)|4(���������)|3|5|6|7] [ID_��������] [���-��] - ���� ������������ ������� ���� ������������� � ������� ������������� �� ������ �����;"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"���� ��������"

	// 2006-08-03 by cmkwon, ���� ��¥ ǥ�� ����� �ٸ���
	// �ѱ�(Korea):		YYYY-MM-DD HH:MM:SS
	// �̱�(English):	MM-DD-YYYY HH:MM:SS
	// ��Ʈ��(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", M, D, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", M, D, Y, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"������: /LevelDistribution ��� /LevelDist - ���������� ������� ������������� ������� �������������;"	// 2006-08-08 by dhjin

	// 2014-03-18 by bckim, ?? ON/OFF
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_0		"/market"
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_1		"/market"	
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_HELP	"format: /market - trade shop ON OFF. "
	// End. 2014-03-18 by bckim, ?? ON/OFF

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"��������� �������"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"��������"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// Ŭ���̾�Ʈ������ ����ϴ� ��ɾ�(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"������: /call [���_������] - ������ ���������� ������� � ������������ ����������;"
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"������: /formcall - ��������� ��� ����� ������� �����. ����� ���� ����������� ������ ������� �����;"
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"������: /formcallend - ���������� ��������� ��� ����� ������� �����. ����� ���� ����������� ������ ������� �����;"
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"������: /brigcall - ������ ��������� ��� ����� ������� �������. ����� ���� ����������� ������ ������� �������;"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"������: /brigcallend - ���������� ��������� ��� ����� ������� �������. ����� ���� ����������� ������ ������� �������;"
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"������: /endcall - ���������� ��������� ��� �������, ����� ��� �������� ����;"
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"������: /fight [���_������] - ���������� PvP ������������� ���������;"
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"������: /surrender [���_������] -  ������� � PvP � ������������ ����������;"
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"������: /formfight [���_������] - ���������� PvP ������ ������������� ��������� (��� ������ ������� �����). ����� ���� ������������ ������ ������� �����;"
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"������: /brigconfront [���_������] -  ���������� PvP �������� ������������� ��������� (��� ������ ������ �������). ����� ���� ������������ ������ ������� �������;"
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"������: /brigsurrender -  ������� � ��������� PvP. ����� ���� ������������ ������ ������� �������;"
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"������: /name [���_������] [�����(2~11)] - �������� ������ ���������. ����� ���� ������������ ������ ������� �������;"
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"������: /initchat -  ������������� ���� ����;"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"������: /refusefight - ���/���� ������������� ��������������� ������ �� ����������� PvP;"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"������: /refusetrade -  ���/���� ������������� ��������������� ������ �� ����������� ������;"
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"������: /Closewindow -  ��������� ����������� ���������;"
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"������: /Openwindow -  �������� ����������� ���������;"

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"������� ������ ���������"

// 2010-06-15 by shcho&hslee ��ý��� - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"������� ��������"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner Socket Item"		// 2011-09-01 by hskim, ��Ʈ�� �ý��� 2��

// 2006-11-17 by cmkwon, ��Ʈ�� �Ϸ� ���� �ð� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"������: /TimeLimitSystem [on|off] - ��������� � ���������� ������� ���������� �����������;"
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"������: /PlayTime - ���������� ����� � ���� �� ����;"

// 2007-10-06 by cmkwon, �������� 2���� ȣĪ�� �ٸ��� ���� - �Ʒ��� ���º��� �ٸ��� ������
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"�����"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER			"��������"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"������: /BonusStatPoint [���-��_�����] [|���_������] - ���������� ����� ���-��;"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"������: /PCBang -  ���� PC-����� ������������;"

// 2007-10-06 by dhjin, �������� ���� ��� �������� ����
// 2007-02-13 by dhjin, ��������
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"������: /Subleader [���_������] - ���������� ���������"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR		"��������� ��������� ��������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0			"���������� ���������� ������ ����������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1			"%s ���� ������ ����������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2			"%s ���� ������ ����������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10			"%s �� ����������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20			"%s ��� �������� ����������."

// 2007-02-23 by dhjin, ��������
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP		"������: /StrategyPointInfo - ���������� ������� �������� �� �������������� �����;"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY		"������ �� ���� ���� �� �������������� �����."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST		"���� ����� �� �������������� �����."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE		"�������� �� �������."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME		"����� ������."

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B-������"
#define STRCMD_CS_UNITKIND_MGEAR					"M-������"
#define STRCMD_CS_UNITKIND_AGEAR					"A-������"
#define STRCMD_CS_UNITKIND_IGEAR					"I-������"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"��� B-�������"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"��� M-�������"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"��� A-�������"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"��� I-�������"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"��� �������"

// 2007-03-30 by dhjin, ������ ��� ���� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  		"/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  		"/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  			"/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  			"/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   			"������: /Observer [n] [CharacterName] - CharacterName  save user at n number;"

// 2007-04-10 by cmkwon, Jamboree server �� ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"������: /InitJamboree [validation number] - Initialize jamboree server DB(atum2_db_20);"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"������: /EntrantJamboree [CharacterName] - Designated character will be duplicated to jamboree server DB(atum2_db_20);"
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

// 2007-04-17 by dhjin, ���� ��ũ�� ���� ���
#define STRCMD_CS_CHARACTER_12_LEVEL_RANK  "������"
#define STRCMD_CS_CHARACTER_22_LEVEL_RANK  "�����"
#define STRCMD_CS_CHARACTER_32_LEVEL_RANK  "�����"
#define STRCMD_CS_CHARACTER_42_LEVEL_RANK  "���������"
#define STRCMD_CS_CHARACTER_52_LEVEL_RANK  "��"
#define STRCMD_CS_CHARACTER_62_LEVEL_RANK  "�������"
#define STRCMD_CS_CHARACTER_72_LEVEL_RANK  "������ �������"
#define STRCMD_CS_CHARACTER_82_LEVEL_RANK  "����� �����"
#define STRCMD_CS_CHARACTER_92_LEVEL_RANK  "�����"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
#define STRMSG_REG_KEY_NAME_DELETE_VERSION			"DeleteVersion"
// 2007-12-27 by cmkwon, �������� ��� ��� �߰� -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_PWD						"Password"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ��Ʈ��
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "���������� ����� ������� �����."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "������: /arena [2(�������)|4(���������)] - ���������� ������� �������� �� �����;"

// 2010. 06. 04 by hsLee ARENA ���Ǵ�Ƽ ����. - 
// 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"������:/WatchStart - ������ �������;"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"������: /WatchEnd - ��������� �������;"

// 2007-06-22 by dhjin, WarPoint �߰�
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "������: /WarPoint [���-��(1~1000000)] [|���_������] - �������� ���� �����;"

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"WarPoint"

// 2007-07-11 by cmkwon, �������������� ����-������� ����� - �������� �������(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena "
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "������: /forbidArena [���_������] [|�����(������)] - ��������� ���� �� �����;"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena "
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "������: /releaseArena [���_������] - ��������� ���� �� �����;"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, ����� �������, ����������� �������������� ������� - ��������� ������������������.
#define STRMSG_070802_0001    "���� ������� ������� ���������������."
#define STRMSG_070802_0002    "����������� ����� ��������� �� ��������� �������� ������������."
#define STRMSG_070802_0003    "�� ���������� ��������� ������� %d ���� �������?"
#define STRMSG_070802_0004    "��� ������� ����� �������."
#define STRMSG_070802_0005    "���� ������� � ������� ��������."
#define STRMSG_070802_0006    "���� ������� � ���������� �������."
#define STRMSG_070802_0007    "���� ������� � ������� ������."

// 2007-08-24 by cmkwon, ����Ŀ������ ��� ����/���� ���� ��� �߰� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Enable"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid		"Forbid"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"������: /UseSpeaker [Enable|Forbid] - ������/���������� �� ������������� �������;"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"������: /PrepareShutdown [Start|Release] - ���������� ������� � ���������, ��������� ���� �������������;"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "������: /EntrancePermission [|���_������] - ����� ���� ������������ ������ �������, ��������� ��������� ���� ���������� � ������ �� ���� � ���������-���;"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "������: /EntrancePermissionDeny [���_������] - ����� ���� ������������ ������ �������, ������� ��������� �� ������ �� ���� � ���������-���;"

// 2007-10-05 by cmkwon, ������ ��� ������ �������.
#define STRCMD_071005_0000					"%ddyas %dhour(s) %dminute(s) %dsecond(s)", Day, Hour, Minute, Second  // Day, Hour, Minute, Second is parameter name. don't need to translate.
#define STRCMD_071005_0001					"%dYear %dmonth %dday", Year, Month, Day //Year, Month, Day is parameter name. don't need to translate.
#define STRCMD_071005_0002					"%dYear %dmonth", Year, Month // Year, Month is parameter name. don't need to translate.
#define STRCMD_071005_0003					"%dMonth %dday", Month, Day // Month, Day is parameter name. don't need to translate.


// 2007-10-06 by cmkwon, ���������� ����� ���� ���������� ������ �������
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"�������� 1" // ����� ��� ����� �������.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"�������� 2" // ����� ��� ����� �������.
#define STRCMD_VCN_INFLUENCE_LEADER						"�����������������"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"���. ������������"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"��������� �����"
#define STRCMD_ANI_INFLUENCE_LEADER					"������������"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"����-������������"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"�������"
#define STRCMD_OUTPOST_GUILD_MASTER					"�������� %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"������: /appointment1 [���_������] - BCU : ���������� ��� 1-�� ��������� ������� �������, ANI : ���������� ��� 1-�� ��������� ������� ���������;"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"������: /appointment2 [���_������] - BCU : ���������� ��� 2-�� ��������� ������� �������, ANI : ���������� ��� 2-�� ��������� ������� ���������;"

// 2007-10-30 by cmkwon, ����� "���������� ����" ��� ������ ������� - ������� ��������.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT				"/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyevent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART	"Start"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"End"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"������: /HappyEvent [255(���_�����)|0(�������)|2(�������)|4(���������)] [Start|End] [����(������)] - ���������� ���������� ���;"
 
// 2007-10-30 by cmkwon, ����� "���������� ����" ��� ������ ������� - �� ������ �������.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL					"�������"
#define STRCMD_CS_INFLUENCE_TYPE_VCN					"�������"
#define STRCMD_CS_INFLUENCE_TYPE_ANI					"���������"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK					"��� �������"  // 2007-10-30 by cmkwon, ����� "���������� ����" ��� ������ ������� - ����������
 
// 2007-11-05 by cmkwon, ���� ����� ������� - ������� ���������
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"������: /WPAddedMap ��� /WPAddedMap [1(�������)|2(�������)|4(���������)|3|5|6|7] [���-��_�����_�����(1~)] - ������ ��������� ������� �� ������ ����� �������� ���� �����;"

// 2007-11-19 by cmkwon, ������� ������ �� - ����� �������
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"������: /StartCallGM [|�����(������)] - ������ ������ ������� �������;"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"������: /EndCallGM - ���������� ������ ������� �������;"

// 2007-12-27 by cmkwon, �������� ��� ��� �߰� - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �߰�
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, �������� ���� �����ϱ� - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"
#define STRMSG_REG_KEY_NAME_VSYNC					"VSync"

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/ban"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"������: /Block ��� /BlockAccount [���_��������] [���_����(1:�������|2:������|3:��������|4:SpeedHack|5:���|6:������_����)] [������(���)] [�������_����������_���_������������] [�������_����������_���_�������������];"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/unban"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"������: /Unblock ��� /UnblockAccount [���_��������];"

// 2008-02-20 by cmkwon, ��ɾ��߰�(��������������ο��Ծ���������- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "������: /ItemAllUser ��� /ItemAll ��� /AddAllItem [1(�������)|2(�������)|4(���������)|255(���)] [ID_��������] [���-��] - ����������� � ���� ������������ ��������� ������� ������� ���������� �������;"

// 2008-02-21 by dhjin, �Ʒ�������- �Ʒ����߰���ɾ�
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "������: /TeamArenaLeave [2(�����)|4(�������)|6(�����_�_�������)];"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "������: /TargetArenaLeave [���_������];"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "������: /ArenaEvent [�����_�������];"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "������: /ArenaEventRelease [�����_�������];"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ �˻��� �޺��ڽ����� �˻� ��� �߰�(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"��� ��������"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� ���� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"�����"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"����� �������"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"����������� ������"				// 2008-05-20 by dhjin, EP3 - ���� ���� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"����� ������ �1"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"����� ������ �1"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"����� ������ �2"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"����� ������ �2"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"����� ������ �3"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"����� ������ �3"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"����� ������ �4"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"����� ������ �4"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"����� ������ �5"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"����� ������ �5"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ��������
#define STRCMD_COMMAND_WAR_OPTION_0					"/MotherShipInfoOption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ���¸�ũ�̺�Ʈ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"������: /influencemarkevent [������� 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"������: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, �±� PC�� IP���� �ε�
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"������: /PCBangreloadtime [������] - 10 ���. - 1440 ���."


// 2008-08-21 by dhjin, �Ϲ�, Ư�� ������ �������� �Ӹ� ����
#define STRMSG_080821_0001				"���������� ��������� ������ ���� ���������� ���������."


// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"������: /ComeOnInfl [1(�������)|2(���)|4(���)|255(���)] [����. �������] [0|���. �������] [0|����. �������] [1(B)|16(M)|256(A)|4096(I)] [���������] - ��������� ������� �� ��������� �����"

// 2008-09-09 by cmkwon, "/kick" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"������: /Kick [���] - ��������� ���������."


// 2008-09-12 by cmkwon, "/��" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"������: /fame [������ ��] [��������� ��] - ����������� ���� �����."

// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/RLChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /ReleaseLeaderChatBlock [���_������] - ������ ����������."

// 2009-10-12 by cmkwon, �t���[�X�J�̍폜�ēK�p - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                       "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                       "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                              "������: /StartCityMap [2001|2002] [|CharacterName] - ��������� ���������� ������ ��� ������."

#define STRCMD_CS_COMMAND_TOGGLE_CNC						"/cnc"
#define STRCMD_CS_COMMAND_TOGGLE_CNC_HELP						"format: /cnc - Toggle the CNC status (\\gEnabled\\g/\\rDisabled\\r)"

///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �������������� ����������, ���������� �� ������������ ������.)
#define STRCMD_CS_CHARACTER_96_LEVEL_RANK "���������"
#define STRCMD_CS_CHARACTER_100_LEVEL_RANK "���������"
#define STRCMD_CS_CHARACTER_104_LEVEL_RANK "�������"
#define STRCMD_CS_CHARACTER_108_LEVEL_RANK "���������"
#define STRCMD_CS_CHARACTER_112_LEVEL_RANK "�����������"
#define STRCMD_CS_CHARACTER_116_LEVEL_RANK "��������"
#define STRCMD_CS_CHARACTER_120_LEVEL_RANK "�������"
#define STRCMD_CS_CHARACTER_XX_LEVEL_RANK "�����"
#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, �Ʒ��� ���� ��ɾ� ����

// 2014-05-16 by bckim, ?? ??? ??
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ?? ??? ??

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX??? ? ???? - ??? ??
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/?????"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /????? [MapIndex] - ?? ?? ?? ??? ???"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]?? ?? ??? ?? ?????."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]?? ?? ??? ?? ?????."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]? ???? ?? ??????."
// end 2012-11-29 by jhseol, OX??? ? ???? - ??? ??

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, ? ?? ????
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ??? ?? ?? ??? ??
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Information on players formation member's (member's must log inside the game)"
// End. 2013-11-19 by bckim, ??? ?? ?? ??? ??

// 2015-11-25 Future, Multiple IP Restriction System
#define STRCMD_CS_COMMAND_MULTI_IP_RESTRICTION_0		"/IPUnique"
#define STRCMD_CS_COMMAND_MULTI_IP_RESTRICTION_1		"/IPBlock"
#define STRCMD_CS_COMMAND_MULTI_IP_RESTRICTION_HELP_0	"format: /IPUnique - Gets the current Multiple IP Restriction Status from the Server"
#define STRCMD_CS_COMMAND_MULTI_IP_RESTRICTION_HELP_1	"format: /IPUnique - [(TRUE|ENABLE|1)|(FALSE|DISABLE|0)]"
#define STRCMD_CS_COMMAND_MULTI_IP_RESTRICTION_HELP_2	"- Sets the current Multiple IP Restriction Status and kicks all double logged users"

// 2016-01-03 Future, leader warp restriction
#define STRCMD_CS_COMMAND_LEADER_FORBID_WARP_0			"/ForbidWarp"
#define STRCMD_CS_COMMAND_LEADER_FORBID_WARP_1			"/RestrictWarp"
#define STRCMD_CS_COMMAND_LEADER_FORBID_WARP_HELP		"format: /ForbidWarp [PlayerName] - Towns the given player and restricts his ability to warp for 30 minutes"
#define STRCMD_CS_COMMAND_LEADER_RELEASE_WARP			"/ReleaseWarp"
#define STRCMD_CS_COMMAND_LEADER_RELEASE_WARP_HELP		"format: /ReleaseWarp [PlayerName] - Releases the warping restriction from a restricted player"

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





