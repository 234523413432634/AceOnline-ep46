// 2005-04-28 by cmkwon

#include "Contents.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer���� ó���ϴ� ��ɾ�
	#define STRCMD_CS_COMMAND_MENT_0					"/��Ʈ"
	#define STRCMD_CS_COMMAND_MENT_1					"/��Ʈ"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /��Ʈ [|String] - ĳ���� ��Ʈ ����"
	#define STRCMD_CS_COMMAND_MOVE						"/�̵�"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /�̵� [MapIndex] [|ChannelIndex] - �ش� ��ä�η� �̵���"
	#define STRCMD_CS_COMMAND_COORDINATE				"/��ǥ"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /��ǥ [X] [Y] - ���� ���� �ش� �·�� �̵�"
	#define STRCMD_CS_COMMAND_LIST						"/����Ʈ"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /����Ʈ - ���� ���� ����� ����Ʈ ���(�ִ�20��)"
	#define STRCMD_CS_COMMAND_USERSEND					"/������"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /������ [character name] [map name] - �ش� ĳ���͸� ��õ� ������ �̵�"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/����"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /���� [monster name|item name] - �̸��� �ش� ��Ʈ���� ���ԵǴ� ���ͳ� �������� ������ ���"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/����Ʈ"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /����Ʈ - ĳ������ ����Ʈ ���� ���"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/����Ʈ�����"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /����Ʈ����� [����Ʈ��ȣ]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/����"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /���� [|item kind(0~53)] - �ش� ������ �������� ���"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/��������"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /�������� [item kind(0~53)] - �ش� ������ �������� �߰�"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/��������"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /�������� [from itemnum] ~ [to itemnum] - �ش� �������� �߰�"
	#define STRCMD_CS_COMMAND_STATINIT					"/�����ʱ�ȭ"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/�����ʱ�ȭ"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /�����ʱ�ȭ [|CharacterName]- ��ü�����ʱ�ȭ"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/��Ƽ"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /��Ƽ - ��Ƽ ������ ���"
	#define STRCMD_CS_COMMAND_GAMETIME					"/�ð�"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /�ð� [|���� �ð���(0~23)] - ���� �ð��� ����(�ڱ� �ڽ��� �ð��� �ٲ�)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/��Ʈ��"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/��������"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /��Ʈ�� [0~5] - ����� �޼����� ����ϴ� level�� ����"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/��ȯ"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /��ȯ [monster number|monster name] [# of monsters] - ���͸� ��ȯ(���� �̸��� ������ �ִ� ��� ��� '_'�� ����ϸ� ��)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/��罺ų"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /��罺ų [level] - �ش�Ǵ� ��� ��ų�� ����"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/������"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /������ - �ش�Ǵ� ��� �������� ����, ��ų �� Countable������ ����"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/��繫��"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /��繫�� - �� �´� ��� ���� �߰�"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/�����۹�����"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/�����������"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /�����۹����� - �ش�Ǵ� ��� ������ ������ ����(��ų ����)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/����"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /���� [item number] [# of items] - �������� ������, [# of items]�� ������ 1���� ��޵�"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/���"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /��� [item number] [|# of items] - �������� �ʵ忡 ���"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/����"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /���� - ������ ������ �����"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/������"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /������ - ��� ���� ������ �����"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/ä��"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /ä�� - ����� ä�� ������ �����"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/�����"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /����� - �׽�Ʈ��"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/�Ѿ�"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /�Ѿ� [|1�� �Ѿ� ��] [|2�� �Ѿ� ��] - �Ѿ� �����ϱ�"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/����"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /���� [|character name] - HP, UTC, FUEL�� 100% ä��, [character name]�� ������ �ڱ� �ڽ�"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/����"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /���� [|���� ��%] [|character name] - HP, UTC, FUEL�� [���� ��%]���� ��, [���� ��%]�� ������ 50%, [character name]�� ������ �ڱ� �ڽ�"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/�Ϲ�"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /�Ϲ� - ��ڳ� ���� ������ ������ ���, �Ϲ� �������� �ٲ�"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/Ư��"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /Ư�� - ��ڳ� ���� ������ ������ ���, �Ϲ� �������� �ٽ� Ư�� �������� �ٲ�"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/����"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /���� - ��ڳ� ���� ������ ������ ���, �������� ���� ����"
	#define STRCMD_CS_COMMAND_POWERUP					"/���"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /��� [���ݷ� ������(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/����"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /���� [������] - (�Ϲ�)���� ����"
	#define STRCMD_CS_COMMAND_LEVELSET					"/����"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /���� [|level] [|percentage of exp] [|character name] - ������ ������"
	/////////////////////////////////////////////////
	// start 2011-09-05 by hskim, ��Ʈ�� �ý��� 2��
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/��Ʈ�ʷ���"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /��Ʈ�ʷ��� [|level] [|percentage of exp] - ��Ʈ�� ������ ������"
	// end 2011-09-05 by hskim, ��Ʈ�� �ý��� 2��
	/////////////////////////////////////////////////
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/����"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /���� - �ڽ��� �ٸ� ĳ���Ϳ��� ������ �ʴ´�"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - �׽�Ʈ��"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/�̺�Ʈ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"��ġ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"��ġ����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"�������"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /�̺�Ʈ [��ġ|����|��ġ����|����|�������|��������Ʈ] [|���(%%f)|����] [�ð�(����:��)] [|����(255:ALL,1:Normal,2:VCN,4:ANI)]- �̺�Ʈ ����,����"
	#define STRCMD_CS_COMMAND_PREMEUM					"/�����̾�"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"�Ϲ�"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"����"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"���׷��̵�"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"����"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /�����̾� [�Ϲ�|����|���׷��̵�|����]"
// 2008-02-14 by cmkwon, ���������� ��ɾ� ����
// 	#define STRCMD_CS_COMMAND_CITYWAR					"/����������"
// 	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"����"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"����"
// 	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /���������� [����|����]"
	#define STRCMD_CS_COMMAND_STEALTH					"/���ڽ�"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /���ڽ� - ������ ���Ͱ� ���� �������� �ʴ´�"
	#define STRCMD_CS_COMMAND_RETURNALL					"/��α�ȯ"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /��α�ȯ - �ش� ���º� ���ø����� �̵���"
// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
	#define STRCMD_CS_COMMAND_RESETTRIGGER				"/����Ʈ����"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /����Ʈ���� [Ʈ���Ź�ȣ] - ����ǰ� �ִ� Ʈ���Ÿ� �����Ű�� �ʱ�ȭ �Ѵ�."
// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���


// start 2011-06-22 by hskim, �缳 ���� ����
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ���� ���� ����
// end 2011-06-22 by hskim, �缳 ���� ����

// start 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/�׽�Ʈ���͵��"		// ���� ���� ����
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /�׽�Ʈ���͵�� [monster number] [test numbers : (1~100000)] - ���� ��ɽ� ����Ǵ� �������� �ùķ��̼��ؼ� �����ش�. (������ �ſ� ū ���ϸ� �ݴϴ�. ���� ���������� ������� ������)"
// end 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ��ɾ� ���� ������ �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/���Ǿƿ��̺�Ʈ"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"����"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"����"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /���Ǿƿ��̺�Ʈ [����|����] [����ð�(����:��)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer���� ó���ϴ� ��ɾ�, �Ϻδ� ������ ����� ��ɾ �״�� �����
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer ����׿�"
	#define STRCMD_CS_COMMAND_WHO						"/��������"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /�������� [|# of users] - ���� ������ �ִ� �����(�� ����)�� ��� ���"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/����"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /���� - ��ڿ��� ���� �̺�Ʈ �߻� �� ���� �޼����� �޵��� ������ �����"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - Ŭ���̾�Ʈ�� IM ������ �ְ� �޴� ���������� ��� �����"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/�����ٿ�"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /�����ٿ� [��������] - ������ �����Ŵ"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/����"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /���� [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/����"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /���� [character name] - �ش� ĳ���Ͱ� �ִ� ������ �̵���"
	#define STRCMD_CS_COMMAND_COMEON					"/����"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /���� [character name] - �ش� ĳ���͸� �ҷ���"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/���ܿ���"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /���ܿ��� [���ܸ�] - �ش� ���ܿ��� ��� �ҷ���"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/���ܺ�����"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /���ܺ����� [���ܸ�] [map name] - �ش� ���ܿ��� ������ �̵�"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/�Ӹ�"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /�Ӹ� - �Ӹ��� ���� Ȥ�� ����, toggle��"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/���"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /��� - ��� ���� ���"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/����"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"�⺻"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"����"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"�帲"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"�Ȱ�"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"��ü"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /���� [�⺻|����|��|��|�帲|�Ȱ�] [��ü|���̸�] [on|off] - ���� ����"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/ä��"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /ä�� [character name] [�ð�(��)] - ä�� ���� ��Ŵ"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/ä������"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /ä������ [character name] - ä�� ���� ������"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/��ɾ�"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - ��ɾ� ����Ʈ�� �����"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/���ʽ�����"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/���ʽ�����"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - ���ʽ� ���� ����"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor���� ó���ϴ� ��ɾ�, �Ϻδ� ������ ����� ��ɾ �״�� �����
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/��ȣ����"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /��ȣ���� [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/��ȣ����"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /��ȣ���� [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/��ȣ���"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /��ȣ���"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/��ȣȭ"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /��ȣȭ [��ȣȭ�� ��Ʈ��]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/��������"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /�������� [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/����Ǯ��"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /����Ǯ�� [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/��������"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /��������"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "���� ����!!! ������ �������� �ش�!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "���� �α��� �̸��� �Է��ϼ���"
	#define STRCMD_CS_COMMON_DB_0002 "���� �α��� ��ȣ�� �Է��ϼ���"
	#define STRCMD_CS_COMMON_DB_0003 "DB �α��� �̸��� �Է��ϼ���"
	#define STRCMD_CS_COMMON_DB_0004 "DB �α��� ��ȣ�� �Է��ϼ���"

	#define STRCMD_CS_COMMON_MAP_0000 "�ϵ��ڵ��� �κ�: 0101�ʿ��� 1�� ���� Ÿ���� �����ϱ�, �ʿ����Ϳ��� ���� ������ �� �ִ� ��� ã�Ƽ� �����ؾ� ��!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "�ϵ��ڵ��� �κ�: 0101�ʿ��� 1�� ���� Ÿ���� �����ϱ�, �ʿ����Ϳ��� ���� ������ �� �ִ� ��� ã�Ƽ� �����ؾ� ��!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] ��ȯ����[%8d] ��ȯ�ð�[%6d��], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index �ߺ� Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] ��ȯ ����[%8d] ��ȯ�ð�[%6d��], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== ������Ʈ ���� ����\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "�ٿ�ε� ������ ã�� �� �����ϴ�."
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "���� ���� �����Դϴ�"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "�ٿ�ε� ���� �б� �����Դϴ�"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d��%d�ð�%d��%d��"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"�Ϲ�"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"��Ż����"
	#define STRCMD_CS_COMMON_RACE_DECA			"��ī"
	#define STRCMD_CS_COMMON_RACE_PHILON		"�ʷ�"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"����"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"����"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"����"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"������"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"���Ӹ�����"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"�����"
	#define STRCMD_CS_COMMON_RACE_GUEST			"�Խ�Ʈ"
	#define STRCMD_CS_COMMON_RACE_DEMO			"�ÿ�(����)��"
	#define STRCMD_CS_COMMON_RACE_ALL			"��� ����"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"�� �� ���� ����"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"�̸� ����"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"�Ʒ� �����"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd �����"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd �����"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st �����"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd ����"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd ����"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st ����"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rd ����"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2nd ����"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1st ����"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd ���̽�"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd ���̽�"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st ���̽�"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"���强"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"���强"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"���强"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"���强"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"�����ƽ��"
	#define STRCMD_CS_ITEMKIND_VULCAN				"��ĭ��"
	#define STRCMD_CS_ITEMKIND_DUALIST				"��󸮽�Ʈ��"		// 2005-08-01 by hblee : GRENADE -> DUALIST ���� ����.
	#define STRCMD_CS_ITEMKIND_CANNON				"ĳ���"
	#define STRCMD_CS_ITEMKIND_RIFLE				"�����÷�"
	#define STRCMD_CS_ITEMKIND_GATLING				"��Ʋ����"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"��ó��"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"�޽�����̺��"
	#define STRCMD_CS_ITEMKIND_ROCKET				"���Ϸ�"
	#define STRCMD_CS_ITEMKIND_MISSILE				"�̻��Ϸ�"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"�����"

	#define STRCMD_CS_ITEMKIND_MINE					"���η�"
	#define STRCMD_CS_ITEMKIND_SHIELD				"�����"
	#define STRCMD_CS_ITEMKIND_DUMMY				"���̷�"			
	#define STRCMD_CS_ITEMKIND_FIXER				"�ȼ���"
	#define STRCMD_CS_ITEMKIND_DECOY				"�����̷�"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"�Ƹӷ�"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"������"
	#define STRCMD_CS_ITEMKIND_ENERGY				"��������"
	#define STRCMD_CS_ITEMKIND_INGOT				"������"
	#define STRCMD_CS_ITEMKIND_CARD					"�Ϲ�ī���"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"��æƮī���"
	#define STRCMD_CS_ITEMKIND_TANK					"��ũ��"
	#define STRCMD_CS_ITEMKIND_BULLET				"ź�˷�"
	#define STRCMD_CS_ITEMKIND_QUEST				"����Ʈ�����۷�"
	#define STRCMD_CS_ITEMKIND_RADAR				"���̴���"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"��ǻ�ͷ�"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"����ī���"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"��æƮ��������ī���"
	#define STRCMD_CS_ITEMKIND_BLASTER				"�����ͷ�"	// 2005-08-01 by hblee : �����ͷ� �߰�.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"���ϰǷ�"		// 2005-08-01 by hblee : ���ϰǷ� �߰�.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"�����Ѿ׼�����"		// 2006-03-17 by cmkwon, ���ð��� <����>�� �׼����� ������
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"�ð����Ѿ׼�����"		// 2006-03-17 by cmkwon, ���ð��� �ð� ������ �ִ� �׼����� ������
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"��繫��"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"�⺻����"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"�Ѿ��� �⺻����"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"������ �⺻����"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"��޹���"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"ź���� ��޹���"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"����� ��޹���"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"���� ��ų"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"��� ��ų"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"���� ��ų"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"�Ӽ� ��ų"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1�� ���Ϳ� ������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"���� �������(1-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"���� ����(1-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"���� ��ü ����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2�� ���Ϳ� ������"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"���� ����(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"���� �̻��Ϸ�(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"���� �����(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"���� ���η�(2-1��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"���� �����(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"���� ���̷�(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"���� �ȼ���(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"���� �����̷�(2-2��)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"���� ���̾��"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"���� �浹���� ����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"���� ���� ��ź��"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"�� �� ���� ������"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"�� �� ���� ��ü"

	#define STRCMD_CS_STAT_ATTACK_PART				"����"
	#define STRCMD_CS_STAT_DEFENSE_PART				"���"
	#define STRCMD_CS_STAT_FUEL_PART				"����"
	#define STRCMD_CS_STAT_SOUL_PART				"����"
	#define STRCMD_CS_STAT_SHIELD_PART				"����"
	#define STRCMD_CS_STAT_DODGE_PART				"ȸ��"
	#define STRCMD_CS_STAT_BONUS					"���ʽ� ����"
	#define STRCMD_CS_STAT_ALL_PART					"��� ����"
	#define STRCMD_CS_STAT_UNKNOWN					"�𸣴� ����"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"��Ƽ��"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"ȸ����"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"�����"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"������"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"���������� �Ϲݱ�"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"���������� ���Ա�"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"�˸��� ���Ա�"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"��Ż���� ���決"

	#define STRCMD_CS_POS_PROW						"���̴� ��ġ(���� ���)"
	#define STRCMD_CS_POS_PROWIN					"��ǻ��(�߾� ����)"
	#define STRCMD_CS_POS_PROWOUT					"1�� ����(���� ����)"
	#define STRCMD_CS_POS_WINGIN					"������(�߾� ����)"
	#define STRCMD_CS_POS_WINGOUT					"2�� ����(���� ����)"
	#define STRCMD_CS_POS_CENTER					"�Ƹ�(�߾� ���)"
	#define STRCMD_CS_POS_REAR						"����(�Ĺ� ���)"

	// 2010-06-15 by shcho&hslee ��ý���
	#define STRCMD_CS_POS_ATTACHMENT				"������(�Ĺ� ����-������ũ|�����̳ʰ迭)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"������(�Ĺ� ����-������ũ|�����̳ʰ迭)"

	// 2010-06-15 by shcho&hslee ��ý���
	//#define STRCMD_CS_POS_PET						"������(�Ĺ� ����)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"������(�Ĺ� ����)"

	#define STRCMD_CS_POS_PET						"��Ʈ��"

	#define STRCMD_CS_HIDDEN_ITEM					"������ ��ġ"		// 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - ������ ������

	#define STRCMD_CS_POS_INVALID_POSITION			"��Ȯ�� ��ġ"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"�κ��丮 ��ġ"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/����Ʈ�Ϸ�"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /����Ʈ�Ϸ� [|QuesIndex] - ����������Ʈ Ȥ�� ������ ����Ʈ�� �Ϸ�ó���ȴ�."

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/���º���"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /���º���"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/���º���"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /���º��� [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/�����"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /����� [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - �ּ� ó�� ������ �̵�
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"���"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"���࿩����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5����"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/������"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /������ [|���ӽð�(����:��)] [���� ���� ����] - �����ڸ� ��� ����, �����ǿ� ���������� �߰��ϰų� ����Ʈ�� ����"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/�����ǻ���"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /�����ǻ��� [���� �� �������� �ε���] - �����ڸ� ��� ����, �����ǿ� Ư�� ���������� �����Ѵ�."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"������ ����"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"������ ��������"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"���� ����"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"���� �̺�Ʈ"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/�⿩��"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /�⿩�� [����(2:BCU, 4:ANI)] [������] - Ư�� ������ �⿩���� ������Ų��"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/�����"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/����"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /����� [��㳻��] - GM�� ����� ��û�Ѵ�."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/����̺���"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/���򸻺���"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /����̺��� [|����(1~10)] - GM ��� ��û ����Ʈ�� ������ ���� ��ŭ ���캻��"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/����̰�������"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/���򸻰�������"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /����̰������� [|����(1~10)] - GM ��� ��û ����Ʈ�� ������ ���� ��ŭ �����´�(�������� ������)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/���¿���"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/���¼�ȯ"
// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [�ִ��ο�] [0|�ּҷ���] [0|�ִ뷹��] [�������� ������ �޽���] - ������ ������ ����, ������ ������ �����鿡�� �̺�Ʈ������ �̵��� ��û�Ѵ�"

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/�����۸�"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/�������߰���"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(VCN)|4(ANI)|255(All)] [Item Number] [# of items] - ������� ������ ���� �������� ������ �������� �����Ѵ�"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ���� ��¥ ǥ�� ����� �ٸ���
	// �ѱ�(Korea):		YYYY-MM-DD HH:MM:SS
	// �̱�(English):	MM-DD-YYYY HH:MM:SS
	// ��Ʈ��(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/��������"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /�������� - ���ӿ� ������ �ִ� ������ ���� ������ �����ش�"	// 2006-08-08 by dhjin


	// 2014-03-18 by bckim, ���� ON/OFF
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_0		"/market"
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_1		"/����"	
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_HELP	"format: /���� - �ŷ��� ON OFF. "
	// End. 2014-03-18 by bckim, ���� ON/OFF

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"����� ����"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"��ũ"

///////////////////////////////////////////////////////////////////////////////
// 2006-08-24 by cmkwon
// Ŭ���̾�Ʈ������ ����ϴ� ��ɾ�(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/��ȭ"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /��ȭ [CharacterName] - ������ ĳ���Ϳ��� 1:1 ������ȭ�� ��û�Ѵ�."
	#define STRCMD_C_COMMAND_PARTYCALL					"/�����ȭ"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /�����ȭ - ����常 ��� ����, �����鰣 ���� ��ȭ�� �����Ѵ�."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/�����ȭ����"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /�����ȭ���� - ����常 ��� ����, �����鰣 ���� ��ȭ�� �����Ѵ�."
	#define STRCMD_C_COMMAND_GUILDCALL					"/������ȭ"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /������ȭ - �����常 ��� ����, ���ܿ��鰣 ���� ��ȭ�� �����Ѵ�."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/������ȭ����"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /������ȭ���� - �����常 ��� ����, ���ܿ��鰣 ���� ��ȭ�� �����Ѵ�."
	#define STRCMD_C_COMMAND_CALLEND					"/��ȭ����"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /��ȭ���� - 1:1 ������ȭ Ȥ�� �����ȭ Ȥ�� ������ȭ�� �����Ѵ�."
	#define STRCMD_C_COMMAND_COMBAT						"/���"
	#define STRCMD_C_COMMAND_BATTLE						"/����"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /���� [CharacterName] - ������ ĳ���Ϳ��� 1:1 ������ ��û�Ѵ�."
	#define STRCMD_C_COMMAND_SURRENDER					"/�׺�"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /�׺� [CharacterName] - ������ ĳ���Ϳ� 1:1 ������ �ڽ��� �׺��� ��û�Ѵ�."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/������"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /������ [CharacterName] - ����常 ��� ����, ������ ĳ����(�����)���� ��� ������ ��û�Ѵ�."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/�����"
	#define STRCMD_C_COMMAND_PARTYWAR					"/�������"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/��������"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/���ܴ��"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /���ܴ�� [CharacterName] - �����常 ��� ����, ������ ĳ����(������)���� ���� ����� ��û�Ѵ�."
	#define STRCMD_C_COMMAND_GUILDWAR					"/��������"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/�������׺�"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /�������׺� - �����常 ��� ����, ���ܴ�� ����� �׺��� �Ѵ�"
	#define STRCMD_C_COMMAND_NAME						"/ȣĪ"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /ȣĪ [CharacterName] [���(2 ~ 11)] - �����常 ��� ����, ������ ĳ���͸� ������ ������� �����Ѵ�."
	#define STRCMD_C_COMMAND_WARP						"/����"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/��ų���"
	#define STRCMD_C_COMMAND_INITCHAT					"/ä��â�ʱ�ȭ"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /ä��â�ʱ�ȭ - ä��â�� �ʱ�ȭ �Ѵ�"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/�����ź�"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /�����ź� - 1:1 �����ź� ������ On/Off �Ѵ�."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/�ŷ��ź�"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /�ŷ��ź� - �ŷ��ź� ������ On/Off �Ѵ�."
	#define STRMSG_C_050810_0001						"/â����"
	#define STRMSG_C_050810_0001_HELP					"format: /â���� - Ư�� �޽��� �ڽ��� ���� �ʵ��� �Ѵ�. �ڵ� ��ҵ�"
	#define STRMSG_C_050810_0002						"/â�ѱ�"
	#define STRMSG_C_050810_0002_HELP					"format: /â�ѱ� - ��� �޽��� �ڽ��� ���ȴ�."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"������ų������"

// 2010-06-15 by shcho&hslee ��ý��� - �� ������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"��Ʈ�ʾ�����"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"��Ʈ�� ���� ������"		// 2011-09-01 by hskim, ��Ʈ�� �ý��� 2��

// 2006-11-17 by cmkwon, ��Ʈ�� �Ϸ� ���� �ð� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/�ð����ѽý���"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /�ð����ѽý��� [on|off] - �ð����ѽý��� on/off�� �����Ѵ�."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/�̿�ð�"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /�̿�ð� - ���� �Ϸ� ���� ���� �ð��� �����ش�"

// 2007-10-06 by cmkwon, �������� 2���� ȣĪ�� �ٸ��� ���� - �Ʒ��� ���º��� �ٸ��� ������
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"������"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"��������"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/���ʽ���������Ʈ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/���ʽ���������Ʈ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint�� DB�� UPDATE"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PC��"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - ���� ������ �ִ� PC�� �������� �����ش�"

// 2007-10-06 by dhjin, �������� ���� ��� �������� ����
// 2007-02-13 by dhjin, ��������
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/��������"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /�������� [CharacterName] - �������� ����"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"�������� ������ ��� �Ǿ����ϴ�."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"�������ڸ� �� �̻� ���� �� �� �����ϴ�."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s��(��) ù��° �������ڷ� ���� �Ͽ����ϴ�."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s��(��) �ι�° �������ڷ� ���� �Ͽ����ϴ�."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s�� �̸��� �������� �ʽ��ϴ�."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s��(��) �������ڷ� ���� �Ǿ� �ֽ��ϴ�."

// 2007-02-23 by dhjin, ��������
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/��������"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /�������� - ���� ���� ���� ������ �����ش�."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"�������� �������� �����ϴ�."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"�������� �������Դϴ�."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"���� ����"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"���� �ð�"

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

// 2007-03-30 by dhjin, ������ ��� ���� ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0		"/Observerstart"		// 2007-03-30 by dhjin, Ŭ���̾�Ʈ������ ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1		"/����������"			// 2007-03-30 by dhjin, Ŭ���̾�Ʈ������ ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0		"/Observerend"			// 2007-03-30 by dhjin, Ŭ���̾�Ʈ������ ���	
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1		"/����������"			// 2007-03-30 by dhjin, Ŭ���̾�Ʈ������ ���
#define STRCMD_CS_COMMAND_OBSERVER_REG_0			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1			"/������"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP			"format: /������ [n] [CharacterName] - CharacterName������ n�̶�� ��ȣ�� �����Ѵ�"

// 2007-04-10 by cmkwon, ��ȸ������ ����
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0			"/InitJamboree"			
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/��ȸ�����ʱ�ȭ"		
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [��������] - ��ȸ������ DB(atum2_db_20)�� �ʱ�ȭ �Ѵ�."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0		"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/��ȸ����������"		
// 2008-04-15 by cmkwon, ��ȸ����(JamboreeServer)�� �ý��� ���� - �Ʒ��� ���� ���� ������
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] - ������ ĳ������ �����͸� ��ȸ������ DB(atum2_db_20)���� �����Ѵ�."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] - ������ ĳ������ �����͸� ��ȸ������ DB(atum2_db_20)�� �ش� �������� �����Ѵ�."
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_1		"1_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_2		"2_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_3		"3_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_4		"4_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_5		"5_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_6		"6_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_7		"7_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_8		"8_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_9		"9_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_10		"10_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_11		"11_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_12		"12_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_13		"13_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_14		"14_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_15		"15_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_16		"16_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_17		"17_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_18		"18_"
#define STRCMD_CS_JAMBOREE_PREADD_CHARACTER_NAME_19		"19_"

// 2007-04-17 by dhjin, ���� ��ũ�� ���� ���
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"�Ʒû�"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"�ִϾ�"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"�����"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"����"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"���̽�"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"���׶�"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"ž��"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"��Ŀ�Ǵ�"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"�����"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, �������� ��� ��� �߰� -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ��Ʈ��
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"�Ʒ��� ���� ã�� �� �����ϴ�."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0			"/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/�Ʒ���"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /�Ʒ��� [2(BCU)|4(ANI)]- ���� �Ʒ��� ���� ������ �����ش�."

// 2010. 06. 04 by hsLee ARENA ���Ǵ�Ƽ ����. - 
// 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/��������"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /�������� - ������ �����Ѵ�."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/��������"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /�������� - ������ �����Ѵ�."

// 2007-06-22 by dhjin, WarPoint �߰�
#define STRMSG_CS_COMMAND_WARPOINT_0				"/��������Ʈ"
#define STRMSG_CS_COMMAND_WARPOINT_1				"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /��������Ʈ [���� 1~1000000] [|�����̸�] - ��������Ʈ�� �߰��Ѵ�."

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"��������Ʈ"

// 2007-07-11 by cmkwon, �Ʒ����� �ý��� ���� - ��ɾ� �߰�(/�Ʒ�������, /�Ʒ�����������)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/�Ʒ�������"
#define STRCMD_CS_COMMAND_ARENAFORBID_1				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /�Ʒ������� [character name] [|�ð�(��)] - Arena ���� ��Ŵ"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/�Ʒ�����������"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /�Ʒ����������� [character name] - Arena ���� ���� ��Ŵ"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, ���� ��ũ �ɻ� �ý��� ���� - �߰��� ��Ʈ��
#define STRMSG_070802_0001				"���� ��ũ ��� ��û�� �Ϸ� �Ǿ����ϴ�."
#define STRMSG_070802_0002				"�ɻ縦 ��ģ �� ����� �Ϸ� �˴ϴ�."
#define STRMSG_070802_0003				"�����Ͻ� %d���� ���� ��ũ�� ��� �Ͻðڽ��ϱ�?"
#define STRMSG_070802_0004				"���ܸ�ũ ���� ����"
#define STRMSG_070802_0005				"���ܸ�ũ ��� ����"
#define STRMSG_070802_0006				"���ܸ�ũ ���� ����"
#define STRMSG_070802_0007				"���ܸ�ũ ���� ����"

// 2007-08-24 by cmkwon, ����Ŀ������ ��� ����/���� ���� ��� �߰� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/����Ŀ���"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"����"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"����"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[����Ŀ���|UseSpeaker|UseSpeaker] [����|����] - ����Ŀ������ ����� ����/���� ��Ŵ"

// 2007-08-27 by cmkwon, �����ٿ��غ� ��ɾ� �߰�(SCAdminTool���� SCMonitor�� PrepareShutdown�� ���� �� �� �ְ�)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/�����ٿ��غ�"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[�����ٿ��غ�|PrepareShutdown|PrepareShutdown] [Start|Release] - ���� ���� �غ�, ��� ���� ���� ���� �����"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/�����㰡"
#define STRCMD_CS_COMMAND_EntrancePermission_1				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[�����㰡] [|CharacterName] - �����ڸ� ��� ����, �ش� ĳ���͸� ȸ�Ƿ� ���� �㰡 ����Ʈ�� �߰� �Ѵ�."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/����Ұ�"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[����Ұ�] [CharacterName] - �����ڸ� ��� ����, �ش� ĳ���͸� ȸ�Ƿ� ���� �㰡 ����Ʈ���� ���� �Ѵ�."

// 2007-10-05 by cmkwon, �������� ���󺰷� �ٸ����ϱ� ����
#define STRCMD_071005_0000					"%d��%d�ð�%d��%d��", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d��%d��%d��", Year, Month, Day
#define STRCMD_071005_0002					"%d��%d��", Year, Month
#define STRCMD_071005_0003					"%d��%d��", Month, Day


// 2007-10-06 by cmkwon, �������� 2���� ȣĪ�� �ٸ��� ���� -
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"������ �������� 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"������ �������� 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"�ѻ�ɰ�"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"�λ�ɰ�"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"��������"
#define STRCMD_ANI_INFLUENCE_LEADER						"����"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"������"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"����������"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s ����"

// 2007-10-06 by dhjin, �������� ���� ��� �������� ����
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/�����ο�1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /�����ο�1 [CharacterName] - BCU : �λ�ɰ�, ANI : ������ ����"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/�����ο�2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /�����ο�2 [CharacterName] - BCU : ��������, ANI : ���������� ����"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ��ɾ� ���� ������ �Ʒ��� ���� �ٽ� ���� ��
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/���Ǿƿ��̺�Ʈ"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"����"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"����"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /���Ǿƿ��̺�Ʈ [1(Normal)|2(BCU)|4(ANI)|255(All)] [����|����] [����ð�(����:��)]"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - ���� ���� ������ ��
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"�Ϲݼ���"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"��������������"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"�˸��ϼ���"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"��ü���"			// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �߰��� ��

// 2007-11-05 by cmkwon, WP ���� ��ɾ� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP�߰���"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/������Ʈ�߰���"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP�߰��� [1(Normal)|2(BCU)|4(ANI)|255(All)] [AddWarPoint(1~)] - ������� ������ ���� �������� WarPoint�� �����Ѵ�."

// 2007-11-19 by cmkwon, �����ý��� ������Ʈ - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/����̽���"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/���򸻽���"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /����̽��� [|�ð�(����:��)] - ���� �ý��� ����"
#define STRCMD_CS_COMMAND_ENDCALLGM_0			"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/���������"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/��������"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /��������� - ���� �ý��� ����"

// 2007-12-27 by cmkwon, �������� ��� ��� �߰� - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �߰�
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, �������� ���� �����ϱ� - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/��"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/������"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ��ɾ� �߰�(���� ���� ���� ��ο��� ������ ���� - 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/�����۸��"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/�������߰����"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] - ������ �������߿� ������ ���� �������� ������ �������� �����Ѵ�"

// 2008-02-21 by dhjin, �Ʒ��� ���� - �Ʒ��� �߰� ��ɾ�
#define STRCMD_CS_COMMAND_ARENAMOVE_0						"/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/�Ʒ����̵�"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0					"/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/����������"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP				"format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0				"/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/��󼭹�����"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP				"format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0						"/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/�Ʒ����̺�Ʈ"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/�Ʒ����̹�Ʈ"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP					"format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0				"/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/�Ʒ����̺�Ʈ����"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/�Ʒ����̹�Ʈ����"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP			"format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ �˻��� �޺��ڽ����� �˻� ��� �߰�(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"��� �����۷�"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� ���� ����	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"���"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"���࿩����"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"�ο�����"				// 2008-05-20 by dhjin, EP3 - ���� ���� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5����"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ��������
#define STRCMD_COMMAND_WAR_OPTION_0					"/���������ɼ�"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, ���¸�ũ�̺�Ʈ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/���¸�ũ�̺�Ʈ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/���¸�ũ�̹�Ʈ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [���� 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/���¸�ũ�̺�Ʈ����"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/���¸�ũ�̹�Ʈ����"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, �±� PC�� IP���� �ε�
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/�ǽù渮�ε�Ÿ��"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, �Ϲ�, Ư�� ������ �������� �Ӹ� ����
#define STRMSG_080821_0001				"������ ĳ���Ϳ��� ����� �Ӹ��� �� �����ϴ�."


// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [�ִ��ο�] [0|�ּҷ���] [0|�ִ뷹��] [1(B)|16(M)|256(A)|4096(I)] [�������� ������ �޽���] - ������ ������ ����, ������ ������ �����鿡�� �̺�Ʈ������ �̵��� ��û�Ѵ�"

// 2008-09-09 by cmkwon, "/kick" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/ű"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - �ش� ĳ���͸� ���ӿ��� ���� ��Ų��."


// 2008-09-12 by cmkwon, "/��" ��ɾ� �߰� - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/��"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /�� [���θ�] [���ܸ�] - ���� ĳ������ ��, ĳ���� ���� ���� �÷��ش�."

// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/������ä������"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /������ä������ [CharacterName] - ������ ä�� ������ �����ȴ�."

// 2009-10-12 by cmkwon, ������ī ���� ��� ���� - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0			"/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1			"/���۵��ø�"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP			"format: /���۵��ø� [2001|2002] [|CharacterName] - �ش� ĳ������ �Ϲݼ��½� ���۵��ø��� �ش� ��(2001|2002)���� �����Ѵ�."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �ִ� ���� ���⿡ ���� �߰� ����(������ ���) - ��޶�(�����, ���, �屺, �ѵ�, ������, ��ȣ��, ��������)
#define	STRCMD_CS_CHARACTER_96_LEVEL_RANK		"��Ʃ����"
#define	STRCMD_CS_CHARACTER_100_LEVEL_RANK		"�ݷγ�"
#define	STRCMD_CS_CHARACTER_104_LEVEL_RANK		"���ʷ�"
#define	STRCMD_CS_CHARACTER_108_LEVEL_RANK		"�Ź���"
#define	STRCMD_CS_CHARACTER_112_LEVEL_RANK		"������"
#define	STRCMD_CS_CHARACTER_116_LEVEL_RANK		"�����"
#define	STRCMD_CS_CHARACTER_120_LEVEL_RANK		"��������"
#define	STRCMD_CS_CHARACTER_XX_LEVEL_RANK		"�⺻"

#define STRCMD_CS_COMMAND_ENDARENA					"/�Ʒ�������"			// 2012-09-24 by jhseol, �Ʒ��� ���� ��ɾ� ����

// 2014-05-16 by bckim, ���� ��ɾ� �߰�
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/�����Ǳ�ȸ�ð�����"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/�����Ǳ�ȸ����"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/�����Ǳ�ȸ����"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/�����Ǳ�ȸ����"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/������"
// End. 2014-05-16 by bckim, ���� ��ɾ� �߰�

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/���̵�����"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /���̵����� [MapIndex] - �ش� ���� ���� ������ ������"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]�� ������� �ʴ� �ʹ�ȣ�Դϴ�."
// end 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ��ɾ� �߰�

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ ���� ���º���
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/�������º���"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountInflChange"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /�������º��� [����UID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ��Ƽ�� ���� ���� ��ɾ� �߰�
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/��������"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /�������� [CharacterName] - �ش������� �����ִ� ��������(�ش��ɸ��ʹ� �������̿�����)"
// End. 2013-11-19 by bckim, ��Ƽ�� ���� ���� ��ɾ� �߰�

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





