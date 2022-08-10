// 2005-04-28 by cmkwon
// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - ��ɫment����"
	#define STRCMD_CS_COMMAND_MOVE						"/�ƶ�"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /�ƶ� [MapIndex] [|ChannelIndex] - �ƶ�����ص�ͼƵ��"
	#define STRCMD_CS_COMMAND_COORDINATE				"/����"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /���� [X] [Y] - �ƶ���Ŀǰ��ͼ���������"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - ���ڵ�ǰ��ͼ��ʹ���ű�(���20��)"
	#define STRCMD_CS_COMMAND_USERSEND					"/����"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /���� [character name] [map name] - ��ؽ�ɫ�ƶ��������ĵ�ͼ"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/��Ϣ"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /��Ϣ [monster name|item name] - ��ʾ�����������һ�еĹ������ߵ���Ϣ"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - ��ʾ��ɫ��������Ϣ"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/ɾ������"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /ɾ������ [������]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/����"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /���� [|item kind(0~53)] - ��ʾ�������ĵ���"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/��������"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /�������� [item kind(0~53)] - ����������ĵ���"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/��Χ����"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /��Χ���� [from itemnum] ~ [to itemnum] - �����ص���"
	#define STRCMD_CS_COMMAND_STATINIT					"/���Ե��ʼ��"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/���Ե��ʼ��"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /���Ե��ʼ�� - ȫ�����Ե��ʼ��"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/party"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /party - ��ʾ�����Ϣ"
	#define STRCMD_CS_COMMAND_GAMETIME					"/ʱ��"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /ʱ�� [|Ҫ�ӵ�ʱ��(0~23)] - �����ǰ��ʱ��(ֻ����Լ���ʱ��)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - ������ʾDEBUG��Ϣ�ĵȼ�"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/�ٻ�"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /�ٻ� [monster number|monster name] [# of monsters] - �ٻ�����(���������пհ�ʱ'_'ʹ��)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/���м���"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /���м��� [level] - ������ص����м���"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/���е���"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /�������� - ������ص����е���,���ܼ�ʱ�����Ƶ��߳���"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/��������"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /�������� - ���ս��������Ե���������"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/�������е���"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/ɾ�����е���"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /�������е��� - ������ص�����δ��װ�ĵ���(���ܳ���)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/����"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /���� [item number] [# of items] - ʰȡ����, [# of items]û��ʰȡһ��"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/����"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /���� [item number] [|# of items] - ���ߵ����ڵ�ͼ"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - ��ʾ����������Ϣ"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - �������е�ͼ����Ϣ"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/Ƶ��"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /Ƶ�� - ��ʾ��ǰ��ͼƵ������Ϣ"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - ������"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/�ӵ�"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /�ӵ� [|1�� �ӵ���] [|2���ӵ��� ] - �����ӵ�"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/��Ѫ"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /��Ѫ [|character name] - HP, UTC, FUEL�ӵ� 100% , [character name]���û��,���Լ�"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/��Ѫ"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /��Ѫ [|Ҫ���ٵ���%] [|character name] - HP, UTC, FUEL ����Ϊ[Ҫ���ٵ���%], ���û��[Ҫ���ٵ���%]ʱ 50%, [character name]û��ʱ�Լ�"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/һ��"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /һ�� - GM�ʺ�ʱ,����һ���ʺ�"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/��Ȩ"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /��Ȩ - GM�ʺ�ʱ,��һ���ʺŸ��������ʺ�."
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/�޵�"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /�޵� - GM�ʺ�ʱ,�������˺�"
	#define STRCMD_CS_COMMAND_POWERUP					"/ʿ��"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /ʿ�� [������������(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/����"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /���� [����ֵ] - (һ��)��������"
	#define STRCMD_CS_COMMAND_LEVELSET					"/�ȼ�"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /�ȼ� [|level] [|percentage of exp] [|character name] - �����ȼ�"

	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "
	
	
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/͸��"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /͸�� - ��Ľ�ɫ�������Լ�"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - ������"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/�"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"����ֵ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"ϡ�е���"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"��ֹ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /� [����ֵ|SPI|�ָ�����ֵ|����|ϡ�е���|ս������] [|����(%%f)|��ֹ] [ʱ��(��λ:��)] [|����(255:ALL,1:Normal,2:VCN,4:ANI)]- �����,���"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"һ��"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"����"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"��ֹ"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /���� [һ��|����|����|��ֹ]"
// 2008-02-14 by cmkwon, ���������� ��ɾ� ����
//	#define STRCMD_CS_COMMAND_CITYWAR					"/����ռ��ս"
//	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"��ʼ"
//	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"����"
//	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /����ռ��ս [��ʼ|����]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /stealth - ���������͹��ﲻ���ȹ���"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll - Happy Our Event"

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
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/Happy Our Event"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"��ʼ"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"����"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /Happy Our Event [��ʼ|����] [����ʱ��(��λ:��)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - Command used in IMServer, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer Debug��"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - ��ʾĿǰ���������������(�͵�ͼ�޹�)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - GM�����ճ̻ʱ��½������������Ϣ"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - ��ʾ�ͻ��˺�IM����������������Э��"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [��֤����] - ��ֹ������"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - �ƶ�������ؽ�ɫ�ĵط�"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [character name] - ������ؽ�ɫ"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [��������] - ������ص����о�����Ա"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [������] [map name] - ��ؾ���Ա�ƶ�����ͼ"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/���Ļ�"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /���Ļ� - ��ֹ���Ļ�����, toggle"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - ��ʾ������Ϣ"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/����"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"����"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"ѩ"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"ȫ��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /���� [����|��|��|ѩ|��|��] [ȫ��|��ͼ����] [on|off] - ��������"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/��ֹ����"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /��ֹ���� [character name] [ʱ��(��)] - ��ֹ����"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/�����ֹ����"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /�����ֹ���� [character name] - �����ֹ����"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/����"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - ��ʾ�����"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/�������Ե�"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/�������Ե�"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - ���ӽ������Ե�"
// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/��������"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /�������� [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/�ָ�����"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /�ָ����� [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/����Ŀ¼"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /����Ŀ¼"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/����"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /���� [Ҫ���ܵ�String]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/��ͣ�ʺ�"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /��ͣ�ʺ� [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/����ʺ�"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /����ʺ� [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/�ѷ�ͣ���ʺ�"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /�ѷ�ͣ���ʺ�"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "û�о�����!!! ֻ������Mgame������!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "������Login����"
	#define STRCMD_CS_COMMON_DB_0002 "������Login����"
	#define STRCMD_CS_COMMON_DB_0003 "������DB Login����"
	#define STRCMD_CS_COMMON_DB_0004 "������DB Login����"

	#define STRCMD_CS_COMMON_MAP_0000 "hard coding����: ��0101��ͼ����1�Ŵ���Ŀ��,map edit�ҵ����׳�ȥ�ķ����ſ��Գ�ȥ!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "hard coding����: ��0101��ͼ����1�Ŵ���Ŀ��,map edit�ҵ����׳�ȥ�ķ����ſ��Գ�ȥ!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] �ٻ�����[%8d] �ٻ�ʱ��[%6d��], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index �ظ� Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] �ٻ�����[%8d] �ٻ�ʱ��[%6d��], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== ����Ŀ�����\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "�Ҳ��������ļ�"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "�ļ����ɴ���"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "��ȡ�����ļ�����"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d��%dʱ%d��%d��"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"һ��"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"����˹"
	#define STRCMD_CS_COMMON_RACE_DECA			"�Ͽ�"
	#define STRCMD_CS_COMMON_RACE_PHILON		"����"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"ɳ��"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"Ԥ��"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"Ԥ��"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"����Ա"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"��Ϸ����Ա"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"����"
	#define STRCMD_CS_COMMON_RACE_GUEST			"GUEST"
	#define STRCMD_CS_COMMON_RACE_DEMO			"��ʾ(demo)��"
	#define STRCMD_CS_COMMON_RACE_ALL			"��������"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"δ֪������"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"û������"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"ѵ������Ա"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd ����Ա"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd ����Ա"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st ����Ա"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd �Ż���ʻԱ"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd �Ż���ʻԱ"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st �Ż���ʻԱ"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rd ����ָ�ӹ�"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2nd ����ָ�ӹ�"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1st ����ָ�ӹ�"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd ���Ʒ���Ա"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd ���Ʒ���Ա"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st ���Ʒ���Ա"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"׼��"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"�ٽ�"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"�н�"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"�Ͻ�"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"�Զ���"
	#define STRCMD_CS_ITEMKIND_VULCAN				"ת�ֻ�ǹ��"
	#define STRCMD_CS_ITEMKIND_DUALIST				"˫����"		// 2005-08-01 by hblee : GRENADE -> DUALIST ���� ����.
	#define STRCMD_CS_ITEMKIND_CANNON				"��ũ��"
	#define STRCMD_CS_ITEMKIND_RIFLE				"��������"
	#define STRCMD_CS_ITEMKIND_GATLING				"����ǹ��"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"����"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"ͻ����"
	#define STRCMD_CS_ITEMKIND_ROCKET				"�����"
	#define STRCMD_CS_ITEMKIND_MISSILE				"������"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"������"

	#define STRCMD_CS_ITEMKIND_MINE					"�����"
	#define STRCMD_CS_ITEMKIND_SHIELD				"������"
	#define STRCMD_CS_ITEMKIND_DUMMY				"αװ��"			
	#define STRCMD_CS_ITEMKIND_FIXER				"�̶���"
	#define STRCMD_CS_ITEMKIND_DECOY				"�ջ���"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"������"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"������"
	#define STRCMD_CS_ITEMKIND_ENERGY				"������"
	#define STRCMD_CS_ITEMKIND_INGOT				"��ʯ��"
	#define STRCMD_CS_ITEMKIND_CARD					"��ͨ��Ƭ��"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"���쿨Ƭ��"
	#define STRCMD_CS_ITEMKIND_TANK					"̹����"
	#define STRCMD_CS_ITEMKIND_BULLET				"�ӵ���"
	#define STRCMD_CS_ITEMKIND_QUEST				"���������"
	#define STRCMD_CS_ITEMKIND_RADAR				"�״���"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"������"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"���������"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"������"
	#define STRCMD_CS_ITEMKIND_BLASTER				"������"	// 2005-08-01 by hblee : ��ӱ�����.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"�����ǹ��"		// 2005-08-01 by hblee : ��Ӹ����ǹ��.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"�����Ƹ���"		// 2006-03-17 by cmkwon, ʹ��ʱ��<��Զ>��������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"����ʱ�丽��"		// 2006-03-17 by cmkwon, ʹ��ʱ�������Ƶĸ�������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"��������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"��������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"�ӵ�����������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"�ڵ�����������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"��������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"��������������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"��������������"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"��������"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"��������"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"��������"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"���Լ���"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1�� �����õ���"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"�����������(1-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"���������(1-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"����ȫ�幥��"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2�͹����õ���"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"���ﵼ����(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"���ﵼ����(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"��������(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"���������(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"���ﻤ����(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"����αװ��(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"����̶���(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"�����ջ���(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"����ȼ����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"����Ŀ�������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"����ֱ����"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"δ֪�ĵ���"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"δ֪�Ļ���"

	#define STRCMD_CS_STAT_ATTACK_PART				"����"
	#define STRCMD_CS_STAT_DEFENSE_PART				"����"
	#define STRCMD_CS_STAT_FUEL_PART				"ȼ��"
	#define STRCMD_CS_STAT_SOUL_PART				"����"
	#define STRCMD_CS_STAT_SHIELD_PART				"����"
	#define STRCMD_CS_STAT_DODGE_PART				"�ر�"
	#define STRCMD_CS_STAT_BONUS					"�������Ե�"
	#define STRCMD_CS_STAT_ALL_PART					"�������Ե�"
	#define STRCMD_CS_STAT_UNKNOWN					"δ֪�����Ե�"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"��Ŀ����"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"�ر���"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"֧Ԯ��"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"������һ���"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"�����������"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"���ֶ������"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"����˹�����"

	#define STRCMD_CS_POS_PROW						"�״�λ��(��ͷ�м�)"
	#define STRCMD_CS_POS_PROWIN					"����(�������)"
	#define STRCMD_CS_POS_PROWOUT					"1������(��ͷ���)"
	#define STRCMD_CS_POS_WINGIN					"��ʹ��(�����Ҳ�)"
	#define STRCMD_CS_POS_WINGOUT					"2������(��ͷ�Ҳ�)"
	#define STRCMD_CS_POS_CENTER					"װ��(�м�)"
	#define STRCMD_CS_POS_REAR						"����(��β�м�)"

	// 2010-06-15 by shcho&hslee ��ý���
	#define STRCMD_CS_POS_ATTACHMENT				"����װ��(��β�Ҳ�- ȼ��|��װ��ϵ��)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessory(Right side of rear-Fueltank|container type)"

	// 2010-06-15 by shcho&hslee ��ý���
	//#define STRCMD_CS_POS_PET						"������(�Ĺ� ����)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Not to use(Left side of rear)"

	#define STRCMD_CS_POS_PET						"��ʹ��(��β���)"

    #define STRCMD_CS_HIDDEN_ITEM					"Hidden Position"		// 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - ������ ������
	#define STRCMD_CS_POS_INVALID_POSITION			"δȷ��λ��"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"������λ��"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/�������"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /������� [|QuesIndex] - ��������л���ָ�������񼴽����"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/�����ֲ�"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /�����ֲ�"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/�������"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /������� [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - �ּ� ó�� ������ �̵�
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"��Ա"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"���о��ų�"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�Ӷӳ�"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1�Ӷ�Ա"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�Ӷӳ�"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2�Ӷ�Ա"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�Ӷӳ�"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�Ӷ�Ա"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�Ӷӳ�"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�Ӷ�Ա"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�Ӷӳ�"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5�Ӷ�Ա"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/����"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /���� [|����ʱ��(��λ:��)] [������������] - ֻ�н���ָ�ӹٲſ���ʹ��, ������ӹ���������߲鿴��"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/ɾ������"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /ɾ������ [Ҫɾ���Ĺ�������INDEX] - ֻ�н���ָ�ӹٲſ���ʹ��,����ɾ�������ָ����������"
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"����ս����ָ�ӹ�"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"����ս�����캽Ա"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"����ս����״̬"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"����ս�"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/���׶�"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /���׶� [����(2:VCN, 4:ANI)] [���ӷ�] - �������������Ĺ��׶�"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/��"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/����"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /�� [����] - ���GM���뽻̸."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/�鿴��"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/�鿴����"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /�鿴�� [|����(1~10)] - �鿴GM���뽻̸����ָ������ "
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/�����"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/�������"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /����� [|����(1~10)] - ���GM���뽻̸����ָ������(��������ɾ��)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/��������"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/�ٻ�����"
// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [�������] [0|��С�ȼ�] [0|��ߵȼ�] [������ҵ���Ϣ] - ��������ָ��������,ָ���ȼ�������ƶ������ͼ"
	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/���ߵ�ͼ"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/������ӵ�ͼ"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [Item Number] [# of items] - ֧����ǰ��ͼ��ָ���������ָ���ĵ���"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ������������ʾ��ʽ��һ��
	// ����(Korea):		YYYY-MM-DD HH:MM:SS
	// ����(English):	MM-DD-YYYY HH:MM:SS
	// Խ��(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/�ȼ��ֲ�"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /�ȼ��ֲ� - ��ʾ������ҵĵȼ��ֲ�"	// 2006-08-08 by dhjin

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"������"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"������"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// Ŭ���̾�Ʈ������ ����ϴ� ��ɾ�(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/ͨ��"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /ͨ�� [CharacterName] - ����ָ���Ľ�ɫ 1:1����ͨ��"
	#define STRCMD_C_COMMAND_PARTYCALL					"/���ͨ��"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /���ͨ�� - ֻ�б�Ӷӳ�����ʹ��,��ʼ���Ա֮�������ͨ��."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/�������ͨ��"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /�������ͨ�� - ֻ�б�Ӷӳ�����ʹ��.�������Ա֮�������ͨ��"
	#define STRCMD_C_COMMAND_GUILDCALL					"/����ͨ��"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /����ͨ�� - ֻ�о��ų�����ʹ��,��ʼ����Ա֮�������ͨ��"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/��������ͨ��"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /��������ͨ�� - ֻ�о��ų�����ʹ��,��������Ա֮���ͨ��"
	#define STRCMD_C_COMMAND_CALLEND					"/����ͨ��"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /����ͨ�� - ����1:1����ͨ�����߱��ͨ�����߾���ͨ��."
	#define STRCMD_C_COMMAND_COMBAT						"/�Ծ�"
	#define STRCMD_C_COMMAND_BATTLE						"/����"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /���� [CharacterName] - ��ָ���Ľ�ɫ���� 1:1����."
	#define STRCMD_C_COMMAND_SURRENDER					"/Ͷ��"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /Ͷ�� [CharacterName] - ��ָ���Ľ�ɫ1:1 ����ʱ��������Ͷ��."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/��Ӿ���"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /��Ӿ��� [CharacterName] - ֻ�б�Ӷӳ�����ʹ��, ����ָ���Ľ�ɫ(��Ӷӳ�)��Ӿ���."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/��ӶԾ�"
	#define STRCMD_C_COMMAND_PARTYWAR					"/���ս��"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/����ս��"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/���ŶԾ�"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /���ŶԾ� [CharacterName] - ֻ�о��ų�����ʹ��, �����ָ����ɫ(���ų�)���ž���"
	#define STRCMD_C_COMMAND_GUILDWAR					"/����ս��"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/����սͶ��"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /����սͶ�� - ֻ�о��ų�����ʹ��,���Ŷ�սʱͶ��"
	#define STRCMD_C_COMMAND_NAME						"/�ƺ�"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /�ƺ� [CharacterName] [�׼�(2 ~ 11)] - ֻ�о��ų�����ʹ��,Ϊָ����ɫ���ָ���׼�."
	#define STRCMD_C_COMMAND_WARP						"/����"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/ȡ������"
	#define STRCMD_C_COMMAND_INITCHAT					"/��ʼ�����촰��"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /��ʼ�����촰�� - ��ʼ�����촰��."
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/�ܾ�����"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /�ܾ����� - ����1:1 �ܾ�����On/Off."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/�ܾ�����"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /�ܾ����� - ���þܾ�����On/Off."
	#define STRMSG_C_050810_0001						"/�رմ���"
	#define STRMSG_C_050810_0001_HELP					"format: /�رմ��� - ����ʾ�ض�����Ϣ��.���Զ�ȡ��"
	#define STRMSG_C_050810_0002						"/�򿪴���"
	#define STRMSG_C_050810_0002_HELP					"format: /�򿪴��� - ���е���Ϣ������ʹ��."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"�������ܵ���"

// 2010-06-15 by shcho&hslee ��ý��� - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Partner Item"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner Socket Item"		// 2011-09-01 by hskim, ��Ʈ�� �ý��� 2��

// 2006-11-17 by cmkwon, ��Ʈ�� �Ϸ� ���� �ð� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/����ʱ��ϵͳ"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /����ʱ��ϵͳ [on|off] - ����ʱ������ϵͳ on/off."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/����ʱ��"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /����ʱ�� - ��ʾһ����Ϸ����ʱ��"

// 2007-10-06 by cmkwon, �������� 2���� ȣĪ�� �ٸ��� ���� - �Ʒ��� ���º��� �ٸ��� ������
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"����ָ�ӹ�"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"�����캽Ա"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/�������Ե�"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/�������Ե�"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] -  DB����BonusStatPoint"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/����"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - ��ʾĿǰ��½���������"

// 2007-10-06 by dhjin, �������� ���� ��� �������� ����
// 2007-02-13 by dhjin, ��������
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/�����캽Ա"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /�����캽Ա [CharacterName] - ���ý����캽Ա"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"��ȡ�����ý����캽Ա."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"���������ý����캽Ա."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s����Ϊ��һ�������캽Ա."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s����Ϊ�ڶ��������캽Ա."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s������."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s������Ϊ�����캽Ա."

// 2007-02-23 by dhjin, ��������
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/�ݵ���Ϣ"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /�ݵ���Ϣ - ��ʾĿǰ�ݵ�Ľ������."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"û�����ڽ��еľݵ�ս."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"�ݵ�ս���ڽ���."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"��������"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"��ʼʱ��"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B��ս��"
#define STRCMD_CS_UNITKIND_MGEAR					"M��ս��"
#define STRCMD_CS_UNITKIND_AGEAR					"A��ս��"
#define STRCMD_CS_UNITKIND_IGEAR					"I��ս��"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"����B��ս��"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"����M��ս��"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"����A��ս��"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"����I��ս��"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"����ս��"

// 2007-03-30 by dhjin, ������ ��� ���� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  "/Observerstart"  // 2007-03-30 by dhjin, ֻ�����ڿͻ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  "/�����۲�Աģʽ"   // 2007-03-30 by dhjin, ֻ�����ڿͻ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  "/Observerend"   // 2007-03-30 by dhjin, ֻ�����ڿͻ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  "/�����۲�Աģʽ"   // 2007-03-30 by dhjin, ֻ�����ڿͻ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   "/�۲�Ա"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   "format: /�۲�Ա [n] [CharacterName] - ��ɫ���Ʊ����ڱ��n"

// 2007-04-10 by cmkwon, Jamboree server �� ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/��ʼ���������"		
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [��֤����] - ��ʼ����������Ⱥ DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/�������������Ա"		
// 2008-04-15 by cmkwon, ��ȸ����(JamboreeServer)�� �ý��� ���� - �Ʒ��� ���� ���� ������
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] - �����ƶ���ɫ�����ݵ��������Ⱥ DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] - �����ƶ���ɫ�����ݵ��������Ⱥ DB(atum2_db_20)."

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
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"��ʿ"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"��ʿ"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"��ʿ"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"��ξ"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"��ξ"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"��ξ"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"��У"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"��У"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"��У"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, �������� ��� ��� �߰� -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ��Ʈ��
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"û���ҵ������ɶ���."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/������"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /������[2(BCU)|4(ANI)]- ��ʾĿǰ�����ɵĽ���״��."

// 2010. 06. 04 by hsLee ARENA ���Ǵ�Ƽ ����. - 
// 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/��ʼ��ս"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /��ʼ��ս �C �ѿ�ʼ��ս."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/������ս"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /������ս �C �ѽ�����ս."

// 2007-06-22 by dhjin, WarPoint �߰�
#define STRMSG_CS_COMMAND_WARPOINT_0					"/ս������"
#define STRMSG_CS_COMMAND_WARPOINT_1					"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /ս������ [���� 1~1000000] [|�û�����] - ���ս������."

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"ս������"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/��ֹ������"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /��ֹ������ [character name] [|ʱ��(��)] - ��ֹArena "
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/�����ֹ������"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /�����ֹ���� [character name] - �����ֹArena "

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001				"���ű�־���������."
#define STRMSG_070802_0002				"���ͨ���Ժ���Ч."
#define STRMSG_070802_0003				"������ѡ��%d�����ű�־��?"
#define STRMSG_070802_0004				"Ŀǰû�о��ű�־"
#define STRMSG_070802_0005				"���ű�־�ȴ�״̬"
#define STRMSG_070802_0006				"���ű�־����״̬"
#define STRMSG_070802_0007				"���ű�־����"

// 2007-08-24 by cmkwon, ����Ŀ������ ��� ����/���� ���� ��� �߰� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/ʹ��������"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"����"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"��ֹ"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP				"format: /ʹ�������� [����|��ֹ] �C ��ֹ/���ʹ��������"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/׼���رշ�����"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[׼���رշ�����|PrepareShutdown|PrepareShutdown] [Start|Release] �C ׼���رշ�����, �������ǿ�ƽ�����Ϸ"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/�������"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[�������] [|CharacterName] �C ֻ���쵼�˲���ʹ�ã�����ؽ�ɫ��ӵ�����᳡����б���."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/ȡ������"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[ȡ������] [CharacterName] �C ֻ���쵼�˲���ʹ��,����ؽ�ɫ�ӻ᳡����б���ɾ��."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d��%dʱ%d��%d��", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d��%d��%d��", Year, Month, Day
#define STRCMD_071005_0002					"%d��%d��", Year, Month
#define STRCMD_071005_0003					"%d��%d��", Month, Day


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"��ս������ 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"��ս������ 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"Ԫ˧"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"�Ͻ�"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"��ı��"
#define STRCMD_ANI_INFLUENCE_LEADER						"Ԫ˧"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"�Ͻ�"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"��ı��"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s����˾��"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/����ְλ1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /����ְλ1 [CharacterName] - VCN : �Ͻ�, ANI : �Ͻ�"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/����ְλ2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /����ְλ2 [CharacterName] - VCN : ��ı��, ANI : ��ı��"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/����ʱ��"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"��ʼ"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"����"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /����ʱ�� [255(���й���)|0(һ�����)|2(VCN)|4(ANI)] [��ʼ|����] [����ʱ��(��λ:��)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"һ�����"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"������"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"���ֶ�"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"���ж���"			// 2007-10-30 by cmkwon, ���й��һ���ʱ��- ���
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP����"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WP����"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP���� [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] �C ����ǰ��ͼ��ָ�����ҵ���ҽ���WP��"

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/��������ϵͳ"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/��ʼ��ʾ"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /��������ϵͳ [|ʱ��(��λ:����)] �C ��������ϵͳ"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/�ر�����ϵͳ"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/������ʾ"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /�ر�����ϵͳ �C �ر�����ϵͳ"

// 2007-12-27 by cmkwon, �������� ��� ��� �߰� - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �߰�
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, �������� ���� �����ϱ� - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/��ͣ"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/���"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ��ɾ��߰�(��������������ο��Ծ���������- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/���е���"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/������е���"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] �C ���ѵ�½��ָ����������ҽ���ָ������"

// 2008-02-21 by dhjin, �Ʒ�������- �Ʒ����߰���ɾ�
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/�������ƶ�"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/�뿪ս�ӷ�����"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/�뿪Ŀ�������"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/�����ɻ"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/�����ɻ"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/ȡ�������ɻ"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/ȡ�������ɻ"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ �˻��� �޺��ڽ����� �˻� ��� �߰�(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"������"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� ���� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"��Ա"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"���ų�"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"�����ų�"				// 2008-05-20 by dhjin, EP3 - �����޸�����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�Ӷӳ�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1�Ӷ�Ա"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�Ӷӳ�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2�Ӷ�Ա"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�Ӷӳ�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�Ӷ�Ա"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�Ӷӳ�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�Ӷ�Ա"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�Ӷӳ�"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5�Ӷ�Ա"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ��������
#define STRCMD_COMMAND_WAR_OPTION_0					"/ս��ѡ��"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ���¸�ũ�̺�Ʈ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/���»"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/���»"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [����2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/�������»"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/�������»"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, �±� PC�� IP���� �ε�
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/��������ʱ��"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, �Ϲ�, Ư�� ������ �������� �Ӹ� ����
#define STRMSG_080821_0001				"�޷�����ѡ��Ľ�ɫ��"


// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(BCU)|4(ANI)|255(All)] [�������] [0|��͵ȼ�] [0|��͵ȼ�] [1(B)|16(M)|256(A)|4096(I)] [����ҷ��͵���Ϣ] �C �����ƶ�ָ��������ָ���ȼ�����ҵ����ͼ��"

// 2008-09-09 by cmkwon, "/kick" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/�߳�"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] �C ������ؽ�ɫ����Ϸ"


// 2008-09-12 by cmkwon, "/��" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/����"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /���� [��������] [��������] �C ���ӵ�½��ɫ������������������"

// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1 "/�������"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP "format: /������� [CharacterName] �C �������ҽ���"

// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "/StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|CharacterName] - Set the character`s beginning city to 2001 or 2002 when their nation is initialized."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �ִ� ���� ���⿡ ���� �߰� ����(������ ���) - ��޶�(�����, ���, �屺, �ѵ�, ������, ��ȣ��, ��������)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurion"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Colonel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Governer"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conqueror"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardian"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legendary"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Basic"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, �Ʒ��� ���� ��ɾ� ����

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/���̵�����"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /���̵����� [MapIndex] - �ش� ���� ���� ������ ������"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]�� ������� �ʴ� �ʹ�ȣ�Դϴ�."
// end 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ��ɾ� �߰�

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





