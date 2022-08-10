// 2005-04-28 by cmkwon


#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer?? ???? ���ߌ�
	#define STRCMD_CS_COMMAND_MENT_0					"/�R�����g"
	#define STRCMD_CS_COMMAND_MENT_1					"/�R�����g"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /�R�����g [|String] - ��׸�-���Đݒ�"
	#define STRCMD_CS_COMMAND_MOVE						"/�ړ�"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /�ړ� [MapIndex] [|ChannelIndex] - �Y�� ϯ������قɈړ�"
	#define STRCMD_CS_COMMAND_COORDINATE				"/���W"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /���W [X] [Y] - ����ϯ�߂̊Y�����W�Ɉړ�"
	#define STRCMD_CS_COMMAND_LIST						"/���X�g"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /���X�g - ����ϯ�߂���ڲ�-ؽĂ��o�� (�ő�20�l)"
	#define STRCMD_CS_COMMAND_USERSEND					"/�L�����ړ�"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /�L�����ړ� [character name] [map name] - �Y����׸�-���w�肵��ϯ�߂Ɉړ�"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/���"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /��� [monster name|item name] - ���O�ɊY���������܂܂�Ă����ݽ�-�Ⱳ�т̏����o��"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/Я���"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /Я��� - ��׸�-��Я��ݏ����o��"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/Я��ݏ���"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /Я��ݏ��� [Я��ݔԍ�]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/���"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /��� [|item kind(0�`53)] - �Y����ނ̱��т��o��"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/��ޱ���"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /��ޱ���[item kind(0�`53)] - �Y����ނ̱��т�ǉ�"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/�͈ͱ���"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /�͈ͱ���[from itemnum] �` [to itemnum] - �Y�����т�ǉ�"
	#define STRCMD_CS_COMMAND_STATINIT					"/��-��������"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/��-��������"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /��-�������� [|CharacterName]- �S�̽�-��������"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/�ґ�"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /�ґ� - �ґ������o��"
	#define STRCMD_CS_COMMAND_GAMETIME					"/����"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /���� [|���Z����(0�`23)] - ���ݎ��Ԃ�ύX(�����̎��Ԃ̂ݕύX�����)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/�X�g�����O"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/�X�g�����O"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /�X�g�����O [0�`5] - ���ޯ�ү�-�ނ��o�͂���level������"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/����"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /���� [monster number|monster name] [# of monsters] - �ݽ�-�� ����(�ݽ�-�̖��O�ɽ��-�������ꍇ�ͽ��-��̑���Ɂu_�v(����-��-)�����)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/�S�X�L��"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /�S�X�L�� [level] - �Y���̑S�ẴX�L����}��"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/�S����"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allIte"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /�S���� - �Y������S�Ă̱��т�}���A�X�L����Countable���т����O"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/�S����"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /�S���� - �Y���M�A�̑S�Ă̕����ǉ�"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/�S���т��̂Ă�"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/�S���т��̂Ă�"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /�S���т��̂Ă�- �Y���̑S�Ă̑����s�±��т��̂Ă�B (�X�L�����O)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/����"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /���� [item number] [# of items] - ���т��擾����B�擾��[# of items]����͂��Ȃ��ꍇ�A1�����擾�B"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/�h���b�v"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /�h���b�v [item number] [|# of items] - ���т��h���b�v"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/�-��"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /�-�� - �-�ނ̏����o��"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/�-��ϯ��"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /�-��ϯ�� - �S�Ă�ϯ�߂̏����o��"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/�����"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /����� - ����ϯ�߂�����ُ����o��"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/DBG"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /DBG - �e�X�g�p"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/�e�e"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /�e�e [|1�^�e�e��] [|2�^�e�e��] - �e�e��⋋"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/�S��"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /�S�� [|character name] - HP, UTC, FUEL�� 100% �񕜂���A[character name]�����͂���Ă��Ȃ��ꍇ�A��������"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/�e�팸��"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /�e�팸�� [|�����l%] [|character name] - HP, UTC, FUEL�� [�����l%]�ɂ���A[�����l%]�̓��͂��Ȃ��ꍇ��50%�A [character name]�����͂���Ă��Ȃ��ꍇ�͎������g�������B"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/���"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /��� -�^�c�ҹ�-�Ͻ�-����ĂŃ��O�C�������ꍇ�A��ʃA�J�E���g�ň����ւ��i�@�B�|��j"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/����"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /���� -�^�c�҂��-�Ͻ�-����ĂŃ��O�C�������ꍇ�A��ʃA�J�E���g�܂��͓���A�J�E���g�ň����ւ��i�@�B�|��j"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/���G"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /���G- �^�c�҂��-�Ͻ�-����Ă̏ꍇ�A���-�ނ��󂯂Ȃ�"
	#define STRCMD_CS_COMMAND_POWERUP					"/�m�C"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /�m�C [�U���� ������(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/�ϐ�"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /�ϐ� [�ϐ��l] - (���)�ϐ� ����"
	#define STRCMD_CS_COMMAND_LEVELSET					"/���x��"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /���x�� [|level] [|percentage of exp] [|character name] - ���x���𒲐�����"


    #define STRCMD_CS_COMMAND_PARTNERLEVELSET		"/��-��-���x��"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_1		"/partnerlevel"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /��-��-���x�� [|level] [|percentage of exp] - ��-��-�̃��x������"


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/����"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /���� - �������ق��̷�׸�-�Ɍ����Ȃ�"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - �e�X�g�p"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/�C�x���g"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"�o���l"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"�o���l����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"ڱ����"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"�I��"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /�C�x���g [�o���l�bSPI�b�o���l�����b���сbڱ���сb�푈�߲�āiWP�j] [|�{��(%%f)|�I��] [����(�P��:��)] [|����(255:ALL,1:Normal,2:VCN,4:ANI)]- �C�x���g �ݒ�,����"
	#define STRCMD_CS_COMMAND_PREMEUM					"/���б�"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"���"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"�-��-"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"���߸��-��"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"�I��"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /���б� [���|�-��-|���߸��-��|�I��]"
// 2008-02-14 by cmkwon, �s�s��̐� ���ߌ� ??
// 	#define STRCMD_CS_COMMAND_CITYWAR					"/�s�s��̐�"
// 	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"�J�n"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"�I��"
// 	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /�s�s��̐� [�J�n|�I��]"
	#define STRCMD_CS_COMMAND_STEALTH					"/�X�e���X"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /�X�e���X - �搧�U���ݽ�-����U���Ȃ�"
	#define STRCMD_CS_COMMAND_RETURNALL					"/�S�ċA��"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /�S�ċA�� - �Y�� ���͕� �s�sϯ�߂Ɉړ�����"
// start 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���


// start 2011-06-22 by hskim, �缳 ����E����E
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ����E���� ����E
// end 2011-06-22 by hskim, �缳 ����E����E
			   
// start 2012-02-13 by hskim, ���� ������ �嶁E�׽�Ʈ ���ɾ�E
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ����E���� ����E
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ���� ������ �嶁E�׽�Ʈ ���ɾ�E

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ�E�̺�Ʈ ��?E- ���ɾ�E?E?������ �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHour�C�x���g"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"�J�n"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"�I��"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHour�C�x���g [�J�n|�I��] [�i�s����(�P��:��)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer?? ???? ���ߌ�, ??? ??? ??? ���ߌ�? ??? ???
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer ????"
	#define STRCMD_CS_COMMAND_WHO						"/�N"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /�N [|# of users] - ���� �-�ނɂ����-��-��S�ďo�� (ϯ�߂Ɗ֌W�Ȃ�)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/�^�c�o�^"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /�^�c�o�^ - �^�c�҂ɓ���C�x���g��������ү�-�ނ��󂯂�悤�ɻ-�ނɓo�^����"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - �N���C�A���g��IM �-�ނƂ̊Ԃ̃v���g�R����S�ďo�͂���"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/�-��-�޳�"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /�-��-�޳� [�F�ؐ���] - �-�ނ� �I��������"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/�N2"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /�N2 [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/�s��"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /�s�� [character name] - �Y�� ��׸�-�̏ꏊ�Ɉړ�����"
	#define STRCMD_CS_COMMAND_COMEON					"/�Ă�"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /�Ă� [character name] - �Y����׸�-���Ă�"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/���c�Ă�"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /���c�Ă� [���c��] - �Y�� ���c����-��S�ČĂ�"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/���c����"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /���c���� [���c��] [map name] - �Y�� ���c����-�� ϯ�߂Ɉړ�������"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/�����₫"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /�����₫ - �����₫���u���b�N���������iOn/Off�j"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/���c"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /���c - ���c ��� �o��"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/�V�C"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"��{"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"����"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"�J"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"�܂�"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"�S��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /�V�C [��?|����|�J|��|�܂�|��] [�S��|ϯ�ߖ�] [on|off] - �V�C����"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/������ۯ�"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /������ۯ� [character name] [����(��)] - ���Ă���ۯ�����"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/������ۯ�����"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /������ۯ����� [character name] - ������ۯ�����������"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/���ߌ�"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - ���ߌꃊ�X�g���o��"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/��-Ž��-��"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/��-Ž��-��"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - �ްŽ�ð������"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor?? ???? ���ߌ�, ??? ??? ??? ���ߌ�? ??? ???
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/�߽�-�ސݒ�"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /�߽�-�ސݒ� [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/�߽�-�ޕ���"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /�߽�-�ޕ��� [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/�߽�-��ؽ�"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /�߽�-��ؽ�"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/�߽�-�މ�"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /�߽�-�މ� [�߽�-�މ�����X�g�����O]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/�A�J�E���g�u���b�N"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /�A�J�E���g�u���b�N [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/�A�J�E���g�u���b�N����"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /�A�J�E���g�u���b�N���� [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/�u���b�N���ꂽ�A�J�E���g"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /�u���b�N���ꂽ�A�J�E���g"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "M��-ѻ-�ސ�p!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "�-��۸޲�ID����͂��Ă�������"
	#define STRCMD_CS_COMMON_DB_0002 "�-��۸޲�PW����͂��Ă�������"
	#define STRCMD_CS_COMMON_DB_0003 "DB���O�C��ID����͂��Ă��������B"
	#define STRCMD_CS_COMMON_DB_0004 "DB���O�C��PW����͂��Ă��������B"

	#define STRCMD_CS_COMMON_MAP_0000 "�-�޺-�ިݸޕ���: 0101ϯ�߂�1���-���-�ޯĂ𖳎��Aϯ�ߴ�ި�������\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "�-�޺-�ިݸޕ���: 0101ϯ�߂�1���-���-�ޯĂ𖳎��Aϯ�ߴ�ި�������\r\n "
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] �����ݽ�-[%8d] ��������[%6d�b]�A Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index �d�� Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] ���� �ݽ�-[%8d] ��������[%6d�b], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Tatal Monster Count:[%4d]<==��޼ު���ݽ�-���܂�\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "�޳��-��̧�ق�������܂���B"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "̧�ٍ쐬��-�ł��B"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "�޳��-��̧�ق̓ǂݍ��ݴ�-�ł��B"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d��%d����%d��%d�b"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"���"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"���׽"
	#define STRCMD_CS_COMMON_RACE_DECA			"�f�J"
	#define STRCMD_CS_COMMON_RACE_PHILON		"�p�C����"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"�V������"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"�\��"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"�\��"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"�Ǘ���"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"GM"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"���-"
	#define STRCMD_CS_COMMON_RACE_GUEST			"�Q�X�g"
	#define STRCMD_CS_COMMON_RACE_DEMO			"�f���p"
	#define STRCMD_CS_COMMON_RACE_ALL			"�S�푰"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"�s���Ȏ푰"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"���O�Ȃ�"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"��-�ݸ޴�-��"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd��-��"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd��-��"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st��-��"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd��ݸ���"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd��ݸ���"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st��ݸ���"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rd�-��-"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2nd�-��-"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1st�-��-"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd�-�"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd�-�"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st�-�"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"�y��"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"����"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"����"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"�叫"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"�-�������"
	#define STRCMD_CS_ITEMKIND_VULCAN				"�o���J����"
	#define STRCMD_CS_ITEMKIND_DUALIST				"�f���A�����X�g��"		// 2005-08-01 by hblee : GRENADE -> DUALIST �� �ύX.
	#define STRCMD_CS_ITEMKIND_CANNON				"�L���m����"
	#define STRCMD_CS_ITEMKIND_RIFLE				"���C�t����"
	#define STRCMD_CS_ITEMKIND_GATLING				"�K�g�����O��"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"����-��"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Ͻ��ײ�ޗ�"
	#define STRCMD_CS_ITEMKIND_ROCKET				"���P�b�g��"
	#define STRCMD_CS_ITEMKIND_MISSILE				"л�ٗ�"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"�o���h����"

	#define STRCMD_CS_ITEMKIND_MINE					"ϲݗ�"
	#define STRCMD_CS_ITEMKIND_SHIELD				"�-��ޗ�"
	#define STRCMD_CS_ITEMKIND_DUMMY				"���-��"
	#define STRCMD_CS_ITEMKIND_FIXER				"�߸�-��"
	#define STRCMD_CS_ITEMKIND_DECOY				"�f�R�C��"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"�-�-��"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"�G���W����"
	#define STRCMD_CS_ITEMKIND_ENERGY				"��ٷ�-��"
	#define STRCMD_CS_ITEMKIND_INGOT				"�z�Η�"
	#define STRCMD_CS_ITEMKIND_CARD					"��ʶ-�ޗ�"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"�����Ķ-�ޗ�"
	#define STRCMD_CS_ITEMKIND_TANK					"�ݸ��"
	#define STRCMD_CS_ITEMKIND_BULLET				"�e�ۗ�"
	#define STRCMD_CS_ITEMKIND_QUEST				"Я��ݱ��ї�"
	#define STRCMD_CS_ITEMKIND_RADAR				"�-��-��"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"���߭-�-��"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"�ެ���ٶ-�ޗ�"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"�����Ĕj��h�~�-�ޗ�"
	#define STRCMD_CS_ITEMKIND_BLASTER				"��׽�-��"	// 2005-08-01 by hblee : ��׽�-�ޒǉ�.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"�-ٶ�ݗ�"		// 2005-08-01 by hblee : �-ٶ�ݗޒǉ�.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"�������A�N�Z�T��"		// 2006-03-17 by cmkwon, �g�p���Ԃ� <�i�v>�� ����� ����
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"���Ԑ����A�N�Z�T��"		// 2006-03-17 by cmkwon, ���Ԑ����̂��鱸��ر���
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"�S����S����"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"���C������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"�e�e�^���C������"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"�R���^���C������"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"�T�u����"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"�e���^�T�u����"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"�h��^�T�u����"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"�U���X�L��"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"�h��X�L��"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"�⏕�X�L��"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"�����X�L��"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1�^�ݽ�-�p�A�C�e?"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"�ݽ�-ϼݶ��(1-1�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"�ݽ�-�r??��(1-2�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"�ݽ�-�S�̍U��"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2�^�ݽ�-�p����"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"�ݽ�-۹��(2-1�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"�ݽ�-л�ٗ�(2-1�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"�ݽ�-�����ٗ�(2-1�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"�ݽ�-ϲݗ�(2-1�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"�ݽ�-�-��ޗ�(2-2�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"�ݽ�-���-��(2-2�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"�ݽ�-�s�N�T?��(2-2�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"�ݽ�-�޺���(2-2�^)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"�ݽ�-̧��-��"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"�ݽ�-�Փˉ\��-ї�"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"�ݽ�-���i���e��"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"�s���ȱ���"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"�s���ȋ@��"

	#define STRCMD_CS_STAT_ATTACK_PART				"�U��"
	#define STRCMD_CS_STAT_DEFENSE_PART				"�h��"
	#define STRCMD_CS_STAT_FUEL_PART				"�R��"
	#define STRCMD_CS_STAT_SOUL_PART				"���_"
	#define STRCMD_CS_STAT_SHIELD_PART				"�-���"
	#define STRCMD_CS_STAT_DODGE_PART				"���"
	#define STRCMD_CS_STAT_BONUS					"��-Ž��-��"
	#define STRCMD_CS_STAT_ALL_PART					"�S��-��"
	#define STRCMD_CS_STAT_UNKNOWN					"�s���Ƚ�-��"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"���R�^"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"�U���^"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"����^"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"�U���^"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"����^"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"�U���^"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"�-��ތ^"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"�h��^"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"�x���^"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ����? HappyHour �C�x���g ?? - ???? ?? ?? ?
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"�޲�ުƭ-��ʌR"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"�޲�ުƭ-���K�R"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"�-���ݐ��K�R"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"���׽�A�M�R"

	#define STRCMD_CS_POS_PROW						"�-��-�ʒu(�擪�̒���)"
	#define STRCMD_CS_POS_PROWIN					"���߭-�-(�����̍�)"
	#define STRCMD_CS_POS_PROWOUT					"���C������(�擪�̍�)"
	#define STRCMD_CS_POS_WINGIN					"�g�p���Ȃ�(�����̉E)"
	#define STRCMD_CS_POS_WINGOUT					"�T�u����(�擪�̉E)"
	#define STRCMD_CS_POS_CENTER					"�-�-(�����̒���)"
	#define STRCMD_CS_POS_REAR						"�G���W��(����̒���)"
	    
	// 2010-06-15 by shcho&hslee ?Eý��?
    //#define STRCMD_CS_POS_ATTACHMENT				"�t����(����̉E-�R���ݸ|��ײ��-�n��)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"�t����(����̉E-�R���ݸ|��ײ��-�n��)"

	// 2010-06-15 by shcho&hslee ?Eý��?
	//#define STRCMD_CS_POS_PET						"�g�p���Ȃ�(����̍�)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"�g�p���Ȃ�(����̍�)"

	#define STRCMD_CS_POS_PET						"��-��"

    #define STRCMD_CS_HIDDEN_ITEM				"�B���ꂽ�ꏊ"	
	
	#define STRCMD_CS_POS_INVALID_POSITION			"���m��ʒu"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"�C���x���g���ʒu"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/Я��݊���"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /Я��݊���[|QuesIndex] - �i�s��Я��݂�w�肵��Я��݂���������"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/���͕��z"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /���͕��z"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/���͕ύX"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format:/���͕ύX [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/�ݽ�-�ɍs��"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format:/�ݽ�-�ɍs�� [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���c ?? ?? - ?? ?? ??? �ړ�
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"����"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"���c��"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1�����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2�����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�����"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�����"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5�����"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/�d����"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format:/�d����[|��������(�P��:��)] [���m�点���e] - �w���҂̂ݎg�p�\�A�d���ɂ��m�点��ǉ����邩���X�g������"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/�d���폜"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /�d���폜[�폜���邨�m�点�̃C���f�b�N�X] - �w���҂̂ݎg�p�\�A�d���̎w�肵�����m�点���폜����"

	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"���͐��-��-"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"���͐핛�-��-"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"���͎x������"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"���̓C�x���g"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/��^�x"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /��^�x [����(2:BCU, 4:ANI)] [������] ? �w�肵�����͂̊�^�x�𑝉�������"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/�w���v"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/�w���v"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /�w���v [���k���e] - GM�ɑ��k��\�����݂���B"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/�w���v������"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/�w���v������"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /�w���v������[|����(1�`10)] - GM���k�\�����݃��X�g���w�肵���������o�͂���"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/�w���v��ǂݍ���"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/�w���v��ǂݍ���"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /�w���v��ǂݍ���[|����(1�`10)] - GM���k�\�����݃��X�g���w�肵�������ǂݍ��� (�-�ނ���폜�����)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/���͏���"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/���͏���"
// 2008-09-09 by cmkwon, /���͏��� ���ߌ� ?? ���X�g? ??���� �ǉ� - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [�ő�l��] [0|�ŏ����x��] [0|�ő僌�x��] [�-��-�ɑ���ү�-��] ? �C�ӂɎw�肵�����́A�w�肵�����x�����-��-�ɲ����ϯ�߂ւ̈ړ���v������"

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/����ϯ��"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/���ђǉ�ϯ��"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(VCN)|4(ANI)|255(All)] [Item Number] [# of items] - ����ϯ�߂̎w�肵�����͂��-��-�Ɏw�肵�����т��x������"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ??? ?? ?? ??? ???
	// ??(Korea):		YYYY-MM-DD HH:MM:SS
	// ??(English):	MM-DD-YYYY HH:MM:SS
	// ???(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, ���x�����z
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/���x�����z"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /���x�����z - ��-тɐڑ����Ă����-��-�̃��x�����z���݂�"	// 2006-08-08 by dhjin


	// 2014-03-18 by bckim, ���� ON/OFF
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_0		"/�s��"
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_1		"/�s��"	
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_HELP	"format: /�s�� - �g���[�h�V���b�v ON OFF. "
	// End. 2014-03-18 by bckim, ���� ON/OFF

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"�K�^�̔�"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"�-�"

///////////////////////////////////////////////////////////////////////////////
// 2006-08-24 by cmkwon
// �N���C�A���g??? ???? ���ߌ�(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/�޲�����"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /�޲����� [CharacterName] - �w�肵����׸�-�� 1:1 �޲����Ă� �v������"
	#define STRCMD_C_COMMAND_PARTYCALL					"/�ґ��޲�����"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /�ґ��޲����� - �ґ����̂ݎg�p�\�B�ґ��޲����Ă��J�n����"
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/�ґ��޲����ďI��"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /�ґ��޲����ďI�� - �ґ����̂ݎg�p�\�B�ґ��޲����Ă��I������"
	#define STRCMD_C_COMMAND_GUILDCALL					"/���c�޲�����"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /���c�޲����� - ���c���̂ݎg�p�\�A���c�޲����Ă��J�n����B"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/���c�޲����ďI��"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /���c�޲����ďI�� - ���c���̂ݎg�p��?�A���c�޲����Ă��I������B"
	#define STRCMD_C_COMMAND_CALLEND					"/�޲����ďI��"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /�޲����ďI�� - 1:1 �{�C�X�`���b�g��ґ��{�C�X�`���b�g�◷�c�{�C�X�`���b�g���I������B"
	#define STRCMD_C_COMMAND_COMBAT						"/�Ό�"
	#define STRCMD_C_COMMAND_BATTLE						"/����"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /���� [CharacterName] - �w�肵����׸�-��1:1 ������\�����݂���B"
	#define STRCMD_C_COMMAND_SURRENDER					"/�M�u�A�b�v"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /�M�u�A�b�v [CharacterName] - �w�肵����׸�-��1:1 �������Ɏ������M�u�A�b�v��\�����݂���B"
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/�ґ�����"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /�ґ����� [CharacterName] - �ґ����̂ݎg�p�\�B�w�肵����׸�- (�ґ���)�ɕґ�������\�����݂���B"
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/�ґ��Ό�"
	#define STRCMD_C_COMMAND_PARTYWAR					"/�ґ��퓬"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/���c�퓬"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/���c�Ό�"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /���c�Ό� [CharacterName]  -���c���̂ݎg�p�\�B�w�肵����׸�- (���c��)�ɗ��c������\�����݂���B"
	#define STRCMD_C_COMMAND_GUILDWAR					"/���c�푈"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/���c��M�u�A�b�v"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /���c��M�u�A�b�v - ���c���̂ݎg�p�\�B���c�Ό��i�s���A�M�u�A�b�v����B"
	#define STRCMD_C_COMMAND_NAME						"/�ď�"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /�ď� [CharacterName] [�K��(2 ? 11)] - ���c���̂ݎg�p�\�B�w�肵����׸�-���w�肵���K���ɕύX����"
	#define STRCMD_C_COMMAND_WARP						"/�-��"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/�X�L���L�����Z��"
	#define STRCMD_C_COMMAND_INITCHAT					"/���ĳ���޳������"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /���ĳ���޳������ - ���ĳ���޳�� ������ ����"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/�����u���b�N"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /�����u���b�N - 1:1 �����u���b�N �ݒ�� On/Off ����B"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/�������u���b�N"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /�������u���b�N - �������u���b�N �ݒ�� On/Off ����B"
	#define STRMSG_C_050810_0001						"/windowclose"
	#define STRMSG_C_050810_0001_HELP					"format: /windowclose - ���� ү�-���ޯ�����J���Ȃ��悤�ɂ���B�����L�����Z�������B"
	#define STRMSG_C_050810_0002						"/windowopen"
	#define STRMSG_C_050810_0002_HELP					"format: /windowopen - �Sү�-���ޯ�����g�p�ł���B"

// 2006-09-29 by cmkwon	
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"�⏕��ٱ���"

// 2010-06-15 by shcho&hslee ?Eý��?- ?E������.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"��-��-����"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM		"��-��-���ı���"

// 2006-11-17 by cmkwon, ??? ?? �Q?? ?? ??
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSyste"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/���Ԑ�������"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /���Ԑ������� [on|off] - ���Ԑ������� on/off�� �ݒ肷��B"
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/���p����"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /���p���� - ��������̹�-ѐڑ����Ԃ�\������"

// 2007-10-06 by cmkwon, ���w���� 2?? ??�� ??? �ݒ� - ??? ����?? ??? ???
//// 2006-12-13 by cmkwon	
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"�w����"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"���w����"

// 2007-01-08 by dhjin	
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/��-Ž��-���߲��"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/��-Ž��-���߲��"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint�� DB�� UPDATE"

// 2007-01-25 by dhjin	
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/�l�b�g�J�t�F"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/�l�b�g�J�t�F"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /�l�b�g�J�t�F - ���ݐڑ����Ă���l�b�g�J�t�F���-��-����\������"

// 2007-10-06 by dhjin, ���w���� ?? ?? �ύX?? ??
// 2007-02-13 by dhjin, ���w����
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/���w����"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /���w���� [CharacterName] - ���w���� �ݒ�"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"���w���� �ݒ肪 �L�����Z�� ����܂����B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"���w���҂� ����ȏ�ݒ肷�邱�Ƃ��ł��܂���B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s�� 1�Ԗڂ̕��w���҂� �ݒ肵�܂����B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s�� 2�Ԗڂ̕��w���҂ɐݒ肵�܂����B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s�̖��O�͑��݂��Ă��܂���B"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s�͕��w���҂� �ݒ� ����Ă��܂��B"

// 2007-02-23 by dhjin, ??���	
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/���_���"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /���_��� - ���� ���_�i�s����\������B"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"�i�s���̋��_�킪����܂���B"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"���_�킪�i�s���ł��B"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"�i�s�n��"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"�J�n����"

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

// 2007-03-30 by dhjin, ��޻�-��- �-�� �-��- �o�^
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0		"/Observerstart"		// 2007-03-30 by dhjin, �N���C�A���g??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1		"/��޻�-��-�J�n"			// 2007-03-30 by dhjin, �N���C�A���g??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0		"/Observerend"			// 2007-03-30 by dhjin, �N���C�A���g??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1		"/��޻�-��-�I��"			// 2007-03-30 by dhjin, �N���C�A���g??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_0			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1			"/��޻�-��-"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP			"format: /��޻�-��- [n] [CharacterName] ? CharacterName�-��-�� n�Ƃ����ԍ��ɾ-�ނ���"

// 2007-04-10 by cmkwon, ���-��? ??
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0			"/InitJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/���-�ޏ�����"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [�F�ؐ���] - ���-�ތQ DB(atum2_db_20)�� ������ ����B"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0		"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/���-�ގQ����"
// 2008-04-15 by cmkwon, ���-��(JamboreeServer)? ���� ?? - ??? ?? ?? ???
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] ? �w�肵����׸�-����-��� ���-�ތQ DB(atum2_db_20)�ɺ��-����B"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] ? �w�肵����׸�-����-�����-�ތQ DB(atum2_db_20)�� �Y�� ���ͺ��-����B"
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

// 2007-04-17 by dhjin, ���x�������N? ?? ??
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"�P����"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"�W���j�A"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"��-��"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"��ݸ���"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"�-�"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"�x�e����"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"�g�b�v�K��"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"��ݸ޺����"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"�-�-"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ����޳�-�ދ@�\�ǉ� -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA ? �o�� ?? ???
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"��-� �-т�������܂���B"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0			"/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/��-�"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /��-� [2(BCU)|4(ANI)]- ���� ��-� �i�s ���� �\������B"

// 2010. 06. 04 by hsLee ARENA ���Ǵ�Ƽ ��E? - 
// 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ�E2E���̵� ����. (GM ���ɾ�E�߰�. /nextscene(���� �ó׸� �� ȣÁE) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ�E2E���̵� ����. (GM ���ɾ�E�߰�. /nextscene(���� �ó׸� �� ȣÁE) )

// 2007-06-15 by dhjin, �ϐ�
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/�ϐ�J�n"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /�ϐ�J�n - �ϐ�� �J�n����B"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/�ϐ�I��"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /�ϐ�I�� - �ϐ�� �I������B"

// 2007-06-22 by dhjin, WarPoint �ǉ�
#define STRMSG_CS_COMMAND_WARPOINT_0				"/�푈�߲�āiWP�j"
#define STRMSG_CS_COMMAND_WARPOINT_1				"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /�푈�߲�āiWP�j [���l 1�`1000000] [|�-��-�-�] - �푈�߲�āiWP�j�� �ǉ�����B"

// 2007-06-26 by dhjin, ?�߲�� �C�x���g ?? �ǉ�
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"�푈�߲�āiWP�j"

// 2007-07-11 by cmkwon, ��-���ۯ����� ?? - ���ߌ� �ǉ�(/��-���ۯ�, /��-���ۯ�����)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/��-���ۯ�"
#define STRCMD_CS_COMMAND_ARENAFORBID_1				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /��-���ۯ� [character name] [|����(��)] - Arena �u���b�N ����"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/��-���ۯ�����"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /��-���ۯ����� [character name] - Arena �u���b�N ���� ����"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, ���c �-� ?? ���� ?? - �ǉ�? ???
#define STRMSG_070802_0001				"���c�-��o�^�\�����݂��������܂����B"
#define STRMSG_070802_0002				"�R���̌�A�o�^���������܂��B"
#define STRMSG_070802_0003				"�I������%d�̗��c�-��������܂����H"
#define STRMSG_070802_0004				"���c�-��Ȃ�"
#define STRMSG_070802_0005				"���c�-��ҋ@"
#define STRMSG_070802_0006				"���c�-�����"
#define STRMSG_070802_0007				"���c�-���-"

// 2007-08-24 by cmkwon, ���-�-���� �g�p�\/�u���b�N �ݒ� ?? �ǉ� - ���ߌ� �ǉ�
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/���-�-�g�p"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"�\"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"�֎~"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format:/[���-�-�g�p|UseSpeaker|UseSpeaker][�\|�֎~]-���-�-���� �g�p�� �u���b�N/���� ����"

// 2007-08-27 by cmkwon, �-��???? ���ߌ� �ǉ�(SCAdminTool?? SCMonitor? PrepareShutdown�� ?? ? ? ??)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/�-���޳ݏ���"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[�-���޳ݏ���|PrepareShutdown|PrepareShutdown] [Start|Release] - �-�� �I�� �����A�S�Ă��-��-�̐ڑ��������I������"

// 2007-08-30 by cmkwon, ��c�� ���� ?? - ���ߌ� �ǉ�
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/���ꋖ��"
#define STRCMD_CS_COMMAND_EntrancePermission_1				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[���ꋖ��] [|CharacterName] - �w���҂̂ݎg�p�\�B�Y�� ��׸�-����ꋖ�� ���X�g�ɒǉ�����B"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/����s��"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[����s��] [CharacterName] - �w���҂̂ݎg�p��?�A�Y�� ��׸�-�� ��c�� ���ꋖ�� ���X�g����폜����B"

// 2007-10-05 by cmkwon, ???�� ???? ????? ??
#define STRCMD_071005_0000					"%d��%d����%d��%d�b", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d�N%d��%d��", Year, Month, Day
#define STRCMD_071005_0002					"%d�N%d��", Year, Month
#define STRCMD_071005_0003					"%d��%d��", Month, Day


// 2007-10-06 by cmkwon, ���w���� 2?? ??�� ??? �ݒ� -
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"���͐� ���w���� 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"���͐� ���w���� 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"���i�ߊ�"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"���i�ߊ�"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"�Q�d����"
#define STRCMD_ANI_INFLUENCE_LEADER						"�c��"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"���c��"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"���{����"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s �͒�"

// 2007-10-06 by dhjin, ���w���� ?? ?? �ύX?? ??
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/�E�ʕt�^1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /�E�ʕt�^1 [CharacterName] - BCU : ���i�ߊ��A ANI : ���c�� �ݒ�"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/�E�ʕt�^2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /�E�ʕt�^2 [CharacterName] - BCU : �Q�d�����AANI : ���{�����ݒ�"

// 2007-10-30 by cmkwon, ����? HappyHour �C�x���g ?? - ���ߌ� ?? ??? ??? ?? ?? ?? ?
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHour"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"�J�n"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"�I��"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHour�C�x���g [1(Normal)|2(BCU)|4(ANI)|255(All)] [�J�n|�I��] [�i�s����(�P��:��)]"

// 2007-10-30 by cmkwon, ����? HappyHour �C�x���g ?? - ?? ?�� ??? ?
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"��ʐ���"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"�޲�ުƭ-����"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"�-���ݐ���"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"�S�̑Ώ�"			// 2007-10-30 by cmkwon, ����? HappyHour �C�x���g ?? - �ǉ�? ?

// 2007-11-05 by cmkwon, WP ?? ���ߌ� ?? - ���ߌ� �ǉ�
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP�ǉ�ϯ��"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/�푈�߲�āiWP�j�ǉ�ϯ��"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP�ǉ�ϯ�� [1(Normal)|2(BCU)|4(ANI)|255(All)] [AddWarPoint(1�`)] - ����ϯ�߂̎w�肵�����͂��-��-�ɐ푈�߲�āiWP�j���x������B"

// 2007-11-19 by cmkwon, ??���� ������-� - ���ߌ� �ǉ�
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/�w���v�J�n"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/�w���v�J�n"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /�w���v�J�n [|����(�P��:��)] - ���� �V�X�e? �J�n"
#define STRCMD_CS_COMMAND_ENDCALLGM_0			"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/�w���v�I��"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/�w���v�I��"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /�w���v�I�� - ���� ���� �I��"

// 2007-12-27 by cmkwon, ����޳�-�ދ@�\�ǉ�- STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW �ǉ�
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, ???�-�� ?? ???? -
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, �A�J�E���g�u���b�N/���� ���ߌ�? ??? ���� ?? - ���ߌ� �ǉ�
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/�u���b�N"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/�u���b�N����"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, ���ߌ� �ǉ�(?? ?? ?? ???? ���� ?? -
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/���ёS��"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/���ђǉ��S��"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] ? �ڑ������-��-�̂Ȃ��Ŏw�肵�����͂��-��-�Ɏw�肵�����т��x������B"

// 2008-02-21 by dhjin, ��-� ?? - ��-� �ǉ� ���ߌ�
#define STRCMD_CS_COMMAND_ARENAMOVE_0						"/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/��-ňړ�"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0					"/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/�Ώۻ-�ޕ��A"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP				"format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0				"/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/�Ώۻ-�ޕ��A"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP				"format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0						"/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/��-Ų����"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/��-Ų����"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP					"format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0				"/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/��-Ų���ĉ���"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/��-Ų���ĉ���"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP			"format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ??? ���� ����? ?????? ���� ?? �ǉ�(K0000143) -
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"�S���ї�"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���c ?? ??	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"����"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"���c��"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"�����c��"				// 2008-05-20 by dhjin, EP3 - ���c ?? ??
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1�����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2�����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3�����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4�����"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5�����"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5�����"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ??���
#define STRCMD_COMMAND_WAR_OPTION_0					"/��D����I�v�V����"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, �����-������
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/����ϰ������"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/����ϰ������"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [���� 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/����ϰ�����ďI��"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/����ϰ�����ďI��"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ?? PC? IP��� ??
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/ȯĶ̪��-�����"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ? 1440 Min"


// 2008-08-21 by dhjin, ���, ?? �A�J�E���g? ���w���� ?? ??
#define STRMSG_080821_0001				"�I��������׸�-�ɊK����C���ł��܂���B"


// 2008-09-09 by cmkwon, /���͏��� ���ߌ� ?? ���X�g? ??���� �ǉ� -
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [�ő�l��] [0|�ŏ����x��] [0|�ő僌�x��] [1(B)|16(M)|256(A)|4096(I)] [��?�U?�ɑ��郁�b�Z?�W] ? �C�ӂ̎w�肵�����́A�w�肵�����x���̃�?�U?�ɃC�x���g?�b�v�ւ̈ړ���v������"

// 2008-09-09 by cmkwon, "/kick" ���ߌ� �ǉ� - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/�L�b�N"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - �Y�� ��׸�-�� ��-� �I��������B"


// 2008-09-12 by cmkwon, "/����" ���ߌ� �ǉ� -
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/����"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /���� [�l����] [���c����] - �ڑ� ��׸�-�̖����A��׸�- ���c ������ �グ��B"

// 2008-12-30 by cmkwon, �w�������Đ����-�� -
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/�w����?���b�g��������"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /�w�������Đ�������[CharacterName]-�w�������Đ����̉����B"

// 2009-10-12 by cmkwon, ��-���̍폜�ēK�p - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                       "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                       "/��-ēs�sϯ��"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                              "format: /��-ēs�sϯ�� [2001|2002] [|CharacterName] - �Y����׸�-�̈�ʐ��͎��A��-Ă���s�s��ϯ�߂��Y��ϯ��(2001|2002)�ɕύX����B"


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, �ִ�E���� ���⿡ ���� �߰� ����(������ ���) - ��޶�E�����E ��E? �屺, �ѵ�, ������, ��ȣ��, ��E����?
#define STRCMD_CS_CHARACTER_96_LEVEL_RANK "����ر�"
#define STRCMD_CS_CHARACTER_100_LEVEL_RANK "�-��"
#define STRCMD_CS_CHARACTER_104_LEVEL_RANK "�W�F�l����"
#define STRCMD_CS_CHARACTER_108_LEVEL_RANK "�����-"
#define STRCMD_CS_CHARACTER_112_LEVEL_RANK "�ݸ���"
#define STRCMD_CS_CHARACTER_116_LEVEL_RANK "��-�ި��"
#define STRCMD_CS_CHARACTER_120_LEVEL_RANK "ڼު����-"
#define STRCMD_CS_CHARACTER_XX_LEVEL_RANK "��{"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, �Ʒ��� ����E���ɾ�E����

// 2014-05-16 by bckim, ���� ���ɾ�E�߰�
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ���� ���ɾ�E�߰�

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ���ɾ�E�߰�
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/���̵�����"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /���̵����� [MapIndex] - �ش�E���� ���� ������ ������"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]���� ���� ������ ���� �Ǿ����ϴ�."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]�� �㿁E���E�ʴ� �ʹ�ȣ�Դϴ�."
// end 2012-11-29 by jhseol, OX�̺�Ʈ �� �������� - ���ɾ�E�߰�

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ ���� ���º���E
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/���͕ύX"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/���͕ύX"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /���͕ύX[�A�J�E���gUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ��Ƽ��E���� ����E���ɾ�E�߰�
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/�t�H-��-�V�����C���t�H��-�V����"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/�t�H-��-�V�����C���t�H��-�V����"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /�t�H-��-�V�����C���t�H��-�V���� [��׸�-��] - �t�H-��-�V�����C���t�H��-�V���������o-�v���C��-�̏��  (�����o-����-тɃ��O�C�����Ă���K�v������܂�)"
// End. 2013-11-19 by bckim, ��Ƽ��E���� ����E���ɾ�E�߰�

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





