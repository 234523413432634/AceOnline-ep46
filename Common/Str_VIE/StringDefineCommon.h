// 2005-04-28 by cmkwon

// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer?? ???? ???
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [X�u ch��] - ���t tin nh��n ca�nh t�n mi�nh"
	#define STRCMD_CS_COMMAND_MOVE						"/move"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /move [Map s��] [K�nh s��] - Di chuy��n t��i k�nh Map t��ng ��ng"
	#define STRCMD_CS_COMMAND_COORDINATE				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /coordinate [X] [Y] - Di chuy��n ���n to�a ��� t��ng ��ng �� Map hi��n ta�i"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - Danh sa�ch tha�nh vi�n �ang �� Map hi��n ta�i (t��i �a 20 ng���i)"
	#define STRCMD_CS_COMMAND_USERSEND					"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /senduser [T�n nh�n v��t] [T�n map] - Di chuy��n nh�n v��t sang map xa�c �i�nh"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /info [T�n qua�i v��t|Thi��t bi�] � Hi��n th�ng tin v�� Qua�i v��t ho��c Trang bi� co� t�n t��ng ��ng"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest � Hi��n th�ng tin v�� Nhi��m vu� cu�a nh�n v��t"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /delQuest [Nvu� s��] - Xo�a nhi��m vu� co� s�� t��ng ��ng"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /itemKind [Da�ng thi��t bi�(0~53)] - Cho bi��t ca�c da�ng cu� th�� cu�a thi��t bi�"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /insertItemKind [Da�ng thi��t bi�(0~53)] - Th�m va�o ca�c da�ng cu� th�� cu�a ca�c thi��t bi�"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /insertItemNumRange [T�� Itemnum] ~ [���n Itemnum] � Th�m ca�c Trang bi� n��m trong khoa�ng ma� t��ng ��ng"
	#define STRCMD_CS_COMMAND_STATINIT					"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /initStatus - Kh��i ta�o la�i toa�n b�� tra�ng tha�i"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /partyInfo � Hi��n th�ng tin v�� Phi ���i"
	#define STRCMD_CS_COMMAND_GAMETIME					"/time"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /time [Th��i gian(0~23)] � Thay ���i th��i gian hi��n ta�i (Chi� ���i th��i gian ca� nh�n)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - Cho�n c��p ��� ����c hi��n thi� b��i tin nh��n debug"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /summon [Ma� qua�i v��t|S�� l���ng] [# of monsters] � Tri��u t��p qu�i v��t (Tr���ng h��p co� khoa�ng tr��ng �� t�n cu�a qua�i v��t, ba�n du�ng �_�)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /allSkill [C��p ���(1~9)] � L��y toa�n b�� ky� n�ng phu� h��p v��i c��p ��� �a� nh��p"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /allItem � L��y toa�n b�� ca�c trang bi�, ngoa�i tr�� Ky� n�ng va� Trang bi� ���m ����c"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /allWeapon - L��y toa�n b�� vu� khi� phu� h��p v��i phi c�"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /delAllItem - Xo�a toa�n b�� Items kh�ng ����c trang bi� (tr�� Ky� n�ng)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /item [Ma� Item] [S�� l���ng] - L��y trang bi� co� ma� va� s�� l���ng t��ng ��ng, tr���ng h��p kh�ng xa�c �i�nh 's�� l���ng' se� ����c coi la� 1"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /dropItem [Ma� item] [S�� l���ng] � Tha� trang bi� ra kh�ng gian, tr���ng h��p kh�ng xa�c �i�nh 's�� l���ng' se� ����c coi la� 1"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server � Hi��n th�ng tin Server"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - Hi��n th�ng tin toa�n b�� ca�c Map"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /channelInfo - Hi��n th�ng tin v�� k�nh cu�a Map hi��n ta�i"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg � Chi� du�ng ��� ki��m tra"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /chargeBullet [S�� �a�n VK C� ba�n] [S�� �a�n VK Cao c��p] - Na�p �a�n v��i s�� l���ng t��ng ��ng"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /repairAll [T�n nh�n v��t] � Phu�c h��i toa�n b�� th�ng s�� (HP, SP,...) cu�a phi c�, tr���ng h��p kh�ng co� [T�n nv��t] thi� na�p ���y cho ba�n th�n"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /repairParam [% gia�m] [T�n nh�n v��t] � Gia�m toa�n b�� th�ng s�� (HP, SP,...) theo % t��ng ��ng, tr���ng h��p kh�ng nh��p % thi� se� t�� ���ng la� 50%, kh�ng co� [T�n nh�n v��t] thi� se� gia�m cu�a ba�n th�n"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /normal - Chuy��n tha�nh ta�i khoa�n th�ng th���ng t�� ta�i khoa�n Admin ho��c GM"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /specialize - Chuy��n t�� ta�i khoa�n th�ng th���ng sang ta�i khoa�n cu�a Admin ho��c GM"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /invincible � Tr���ng h��p ta�i khoa�n cu�a ng���i �i��u ha�nh ho��c GM thi� se� kh�ng bi� sa�t th��ng"
	#define STRCMD_CS_COMMAND_POWERUP					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /powerUp [S�� %] - T�ng l��c t��n c�ng l�n bao nhi�u %"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /setVariable [bi��n s��] � �i��u chi�nh ca�c bi��n s�� (th�ng th���ng)"
	#define STRCMD_CS_COMMAND_LEVELSET					"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /level [C��p ���] [% exp] [T�n nh�n v��t] - Thay ���i c��p ��� va� ph��n tr�m exp cu�a nh�n v��t co� t�n t��ng ��ng"
	/////////////////////////////////////////////////
	// start 2011-09-05 by hskim, ��Ʈ�� �ý��� 2��
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] - ��Ʈ�� ������ ������"
	// end 2011-09-05 by hskim, ��Ʈ�� �ý��� 2��
	/////////////////////////////////////////////////
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /invisible - Ta�ng hi�nh v��i ng���i kha�c"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf � Chi� d�ng ��� th��"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"Chi� s�� kinh nghi��m"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"Ti��n" //"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"Kh�i phu�c chi� s�� kinh nghi��m"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"Trang bi�" //"Item"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"Trang bi� hi��m" //"raceItem"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"K��t thu�c"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /event [exppoint|SPI|restoreexppoint|item|rareitem|WarPoint] [|rate %f|finish] [time(minute)] - L��p, hu�y Event"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"standard"  //"Th�ng th���ng" 
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"upgrade"  //"N�ng c��p"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"finish"// "k��t thu�c" 
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /premium [standard|super|upgrade|finish]"

	#define STRCMD_CS_COMMAND_CITYWAR					"//citywar"
	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"start"  //"B��t ���u"
	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"finish"  //"K��t thu�c"
	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /citywar [start|finish]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /stealth - Ta�ng hi�nh v��i qua�i v��t"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll - � ��a toa�n b�� user trong map v�� tha�nh ph��"

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
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /happyEvent [start|end] [Th��i gian ti��n ha�nh(��n vi�:Phu�t)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer?? ???? ???, ??? ??? ??? ???? ??? ???
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer du�ng ��� debug"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [S�� ng���i ch�i] - Hi��n toa�n b�� ng���i ch�i tr�n server (kh�ng ph�n bi��t map)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - ��ng ky� v��i server ��� g��i m��t tin nh��n cho Admin khi c� Event "
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi � Hi��n toa�n b�� Protocol trao ���i gi��a Client v� IM server"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [certified no.] - T��t Ma�y chu�"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [T�n nh�n v��t]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [T�n nh�n v��t] � di chuy��n ���n n�i co� nh�n v��t t��ng ��ng "
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [T�n nh�n v��t] - Go�i nh�n v��t t��ng ��ng ���n vi� tri� hi��n ta�i"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuildi"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [T�n Ha�m ���i] - Go�i toa�n b�� tha�nh vi�n trong Ha�m ���i t��ng ��ng"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [T�n Ha�m ���i] [T�n map] � Di chuy��n th�nh vi�n Ha�m ���i t��i map t��ng ��ng"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /whisperChat - Ch��n va� Bo� ch��n ca�c tin nh��n ri�ng (PM)"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - Hi��n th�ng tin Ha�m ���i"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"standard"  //"C� ba�n"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"clear"  //"N��ng"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"rain"  //"M�a"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"snow"  //"Tuy��t"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"cloudy"  //"�m u"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"foggy"  //"S��ng m�"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"whole"  //"toa�n b��"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"  //"b��t"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"  //"T��t"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /weather [standard|clear|rain|snow|cloudy|foggy] [whole|mapname] [on|off] - �i��u chi�nh th��i ti��t"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /forbidChat [T�n nh�n v��t] [Th��i gian(phu�t)] � ���t ch�� ��� c��m No�i chuy��n v��i tha�nh vi�n co� t�n va� th��i gian pha�t t��ng ��ng"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /releaseChat [T�n nh�n v��t] � Bo� ch�� ��� c��m cha�t"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/command" //"l��nh"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - Danh sa�ch ca�c l��nh co� th�� s�� du�ng"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/bonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /bonusStat [S�� �i��m th���ng] [T�n nh�n v��t] � T�ng �i��m th���ng v��i s�� l���ng cho tha�nh vi�n t��ng ��ng"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor?? ???? ???, ??? ??? ??? ???? ??? ???
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /setPassword [T�n ta�i khoa�n] [M��t kh��u] - ���t M��t kh��u cho ta�i khoa�n"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /rollbackPassword [T�n ta�i khoa�n] - Phu�c h��i la�i m��t kh��u cu�a ta�i khoa�n"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /passwordList - Danh sa�ch m��t kh��u"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /encrypt [X�u se� ma� h�a]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /blockAccount [T�n ta�i khoa�n] - Kho�a ta�i khoa�n"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /releaseAccount [T�n ta�i khoa�n] - Bo� kho�a ta�i khoa�n"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /blockedList - Danh sa�ch ca�c ta�i khoa�n bi� kho�a"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Kh�ng c� thi� th�i!!! Chi� t��ng ��ng v��i Cao b��i kh�ng gian !!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "Ba�n ha�y �i��n t�n ��ng nh��p server"
	#define STRCMD_CS_COMMON_DB_0002 "Ba�n ha�y �i��n m��t kh��u "
	#define STRCMD_CS_COMMON_DB_0003 "Ba�n ha�y �i��n t�n ��ng nh��p DB"
	#define STRCMD_CS_COMMON_DB_0004 "Ba�n ha�y �i��n m��t kh��u "

	#define STRCMD_CS_COMMON_MAP_0000 "Ph��n hard coding: Bo� qua mu�c ti�u 1 �� map 0101, c��n ti�m ra ph��ng pha�p ��� c� th�� loa�i bo� d�� d�ng t�� Map editor v� c��n th��c hi��n vi��c loa�i bo�!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "Ph��n hard coding: Bo� qua mu�c ti�u 1 �� map 0101, c��n ti�m ra ph��ng pha�p ��� c� th�� loa�i bo� d�� d�ng t�� Map editor v� c��n th��c hi��n vi��c loa�i bo�!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] Qua�i v��t xu��t hi��n[%8d] Th��i gian xu��t hi��n[%6dgi�y], Vi� tri�(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index tr�ng Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] qu�i v��t xu��t hi��n[%8d] Th��i gian xu��t hi��n[%6dgi�y], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== Bao g��m qu�i v��t \r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "L��i ta�i file"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "L��i ta�o file"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "L��i �o�c ta�i file"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d nga�y %d gi�� %d ph�t %d gi�y"

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

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"Kh�ng c� t�n"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"Phi c�ng s� c��p"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"Phi c�ng c��p 3"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"Phi c�ng c��p 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"Phi c�ng c��p 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"Wingman c��p 3"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"Wingman c��p 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"Winman c��p 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"T���ng c��p 3 "
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"T���ng c��p 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"T���ng c��p 1"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"Ace c��p 3 "
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"Ace c��p 2"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"Ace c��p 1"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"Thi��u t���ng"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"Th���ng t���ng"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"Trung t���ng"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"�a�i t���ng"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"T�� ���ng"
	#define STRCMD_CS_ITEMKIND_VULCAN				"S�ng ti��u li�n"
	#define STRCMD_CS_ITEMKIND_DUALIST				"S�ng b��n ��i"		// 2005-08-01 by hblee : Chuy��n GRENADE -> DUALIST.
	#define STRCMD_CS_ITEMKIND_CANNON				"�a�i ph�o"
	#define STRCMD_CS_ITEMKIND_RIFLE				"Loa�i s�ng tr���ng"
	#define STRCMD_CS_ITEMKIND_GATLING				"Gatling"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"B�� ph�ng"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"Massdriver"
	#define STRCMD_CS_ITEMKIND_ROCKET				"Rocket"
	#define STRCMD_CS_ITEMKIND_MISSILE				"T�n l��a"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"B��n ch�m"

	#define STRCMD_CS_ITEMKIND_MINE					"Mi�n"
	#define STRCMD_CS_ITEMKIND_SHIELD				"Shield"
	#define STRCMD_CS_ITEMKIND_DUMMY				"Dummy"			
	#define STRCMD_CS_ITEMKIND_FIXER				"G��n"
	#define STRCMD_CS_ITEMKIND_DECOY				"L�m nhi��u ra�a"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"Thi��t bi� pho�ng ng��"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"���ng c�"
	#define STRCMD_CS_ITEMKIND_ENERGY				"N�ng l���ng"
	#define STRCMD_CS_ITEMKIND_INGOT				"Kim loa�i"
	#define STRCMD_CS_ITEMKIND_CARD					"The� th�ng th���ng"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"The� n�ng c��p"
	#define STRCMD_CS_ITEMKIND_TANK					"Xe t�ng"
	#define STRCMD_CS_ITEMKIND_BULLET				"�a�n"
	#define STRCMD_CS_ITEMKIND_QUEST				"Quest"
	#define STRCMD_CS_ITEMKIND_RADAR				"Ra�a"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"M�y t�nh"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"The� gamble"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"The� ch��ng x�a"
	#define STRCMD_CS_ITEMKIND_BLASTER				"Blaster"	// 2005-08-01 by hblee : th�m Loa�i blaster.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"Railgun"		// 2005-08-01 by hblee : th�m Loa�i railgun.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"��� kh�ng gi��i ha�n"		// 2006-03-17 by cmkwon, 
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"��� bi� gi��i ha�n th��i gian"		// 2006-03-17 by cmkwon, 
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"To�n b�� vu� khi�"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"Vu� khi� c� ba�n"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"Vu� khi� c� ba�n - Loa�i Bullet"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"Vu� khi� c� ba�n - Loa�i Fuel"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"Vu� khi� cao c��p"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"Vu� khi� cao c��p - Loa�i Bullet"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"Vu� khi� cao c��p - Loa�i Shield"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"Ky� n�ng c�ng ki�ch"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"Ky� n�ng pho�ng ng��"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"Ky� n�ng h�� tr��"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"Ky� n�ng ri�ng"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"Item du�ng cho  qu�i v��t loa�i 1"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"Loa�i su�ng da�nh cho qu�i v��t (Loa�i 1-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"Loa�i su�ng b��n tia da�nh cho qua�i v��t (Loa�i 1-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"T��n c�ng toa�n b�� qua�i v��t"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"Item da�nh cho qua�i v��t loa�i 2"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"Loa�i rocket da�nh cho qua�i v��t (Loa�i2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"Loa�i t�n l��a da�nh cho qua�i v��t (Loa�i2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"Loa�i su�ng b��n chu�m da�nh cho qua�i v��t (Loa�i2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"Loa�i mi�n da�nh cho qua�i v��t (Loa�i2-1)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"Loa�i Shield da�nh cho qua�i v��t (Loa�i2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"Loa�i dummy da�nh cho qua�i v��t (Loa�i2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"Loa�i g��n da�nh cho qua�i v��t (Loa�i2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"Loa�i la�m nhi��u ra�a da�nh cho qua�i v��t (Loa�i2-2)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"Loa�i fire da�nh cho qua�i v��t"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"Loa�i su�ng b��n tia da�nh cho qua�i v��t"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"Loa�i bom da�nh cho qua�i v��t"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"Item kh�ng xa�c �i�nh "

	#define STRCMD_CS_UNITKIND_UNKNOWN				"Loa�i phi c� kh�ng xa�c �i�nh"

	#define STRCMD_CS_STAT_ATTACK_PART				"C�ng ki�ch"
	#define STRCMD_CS_STAT_DEFENSE_PART				"Pho�ng ng��"
	#define STRCMD_CS_STAT_FUEL_PART				"Nhi�n li��u"
	#define STRCMD_CS_STAT_SOUL_PART				"Ky� n�ng"
	#define STRCMD_CS_STAT_SHIELD_PART				"Gia�p"
	#define STRCMD_CS_STAT_DODGE_PART				"Linh hoa�t"
	#define STRCMD_CS_STAT_BONUS					"Chi� s��"
	#define STRCMD_CS_STAT_ALL_PART					"Ca�c chi� s��"
	#define STRCMD_CS_STAT_UNKNOWN					"Chi� s�� kh�ng xa�c �i�nh"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"Loa�i t�� do"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"Loa�i t��n c�ng"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"Loa�i �a da�ng"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"Loa�i c�ng ki�ch"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"Loa�i tr�nh"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"Loa�i c�ng ki�ch"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"Loa�i gia�p"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"Loa�i pho�ng ng��"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"Loa�i chi vi��n"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, ���º� ���Ǿƿ� �̺�Ʈ ���� - �Ʒ����� �ٽ� ���� ��
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"Qu�n c� ba�n Bygeniou"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"Qu�n ch�nh th��c Bygeniou"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"Qu�n ch�nh th��c Arlington "
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"Qu�n li�n bang Vatallus "

	#define STRCMD_CS_POS_PROW						"Vi� tri� ra�a (Tr�n cu�ng, �� gi��a)"
	#define STRCMD_CS_POS_PROWIN					"M�y t�nh (�� gi��a, b�n tra�i)"
	#define STRCMD_CS_POS_PROWOUT					"Vu� khi� c� ba�n (Tr�n cu�ng, b�n tr�i)"
	#define STRCMD_CS_POS_WINGIN					"Ch�a s�� du�ng (�� gi��a, b�n pha�i)"
	#define STRCMD_CS_POS_WINGOUT					"Vu� khi� cao c��p (Tr�n cu�ng, b�n pha�i)"
	#define STRCMD_CS_POS_CENTER					"Vo� phi c� (�� gi��a, trung t�m)"
	#define STRCMD_CS_POS_REAR						"���ng c� (D���i cu�ng, �� gi��a)"

	// 2010-06-15 by shcho&hslee ��ý���
	//#define STRCMD_CS_POS_ATTACHMENT				"������(�Ĺ� ����-������ũ|�����̳ʰ迭)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessory(Right side of rear-Fueltank|container type)"

	// 2010-06-15 by shcho&hslee ��?����
	//#define STRCMD_CS_POS_PET						"Ch�a s�� du�ng (phi�a d���i b�n tra�i)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Ch�a s�� du�ng (phi�a d���i b�n tra�i)"
	
	#define STRCMD_CS_POS_PET						"Partner"
	
    #define STRCMD_CS_HIDDEN_ITEM					"Hidden Position"		// 2011-09-20 by hskim, ��Ʈ�� �ý��� 2�� - ������ ������

	#define STRCMD_CS_POS_INVALID_POSITION			"Vi� tr� ch�a x�c �i�nh"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"Vi� tr� kho ���"
	
	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/questCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/questCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /questCom - Hoa�n tha�nh nhi��m vu� hi��n th��i"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /InflDist - Ty� l�� gi��a hai qu��c gia"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/inflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/inflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /inflChange [|1(Th���ng)|2(BCU)|4(ANI)] - Thay ���i qu��c gia. 1 la� trung l��p, 2 la� BCU, 4 la� ANI"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/goMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/goMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /goMonster [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - ���� ���� ���� - �ּ� ó�� ������ �̵�
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Th�nh vi�n"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"Ha�m ���i tr���ng"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"Chi� huy phi �oa�n 1"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"Th�nh vi�n phi �oa�n 1 "
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"Chi� huy phi �oa�n 2"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"Th�nh vi�n phi �oa�n 2"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"Chi� huy phi �oa�n 3"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"Th�nh vi�n phi �oa�n 3"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"Chi� huy phi �oa�n 4"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"Th�nh vi�n phi �oa�n 4"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"Chi� huy phi �oa�n 5"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"Th�nh vi�n phi �oa�n 5"

// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /Noticeboard [|Th��i gian:phu�t] [N��i dung] - Hi��n th�ng ba�o v��i th��i gian t��ng ��ng tr�n ba�ng �i��n t�� trong tha�nh ph��."
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /DeleteNoticeboard [chi� s�� th�ng ba�o c��n xo�a] - Xo�a m��t th�ng ba�o tr�n ba�ng �i��n t��."	

	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"A�nh h���ng cu�a thu� li�nh"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"Pho� Thu� li�nh"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"A�nh h���ng cu�a buff"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"S�� ki��n qu��c gia"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /ContributionPoint [Qu��c gia(2:BCU|4:ANI)] [S�� �i��m] - T�ng �i��m chi��n c�ng cu�a 1 qu��c gia"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/CallGM"  // Helper
	#define STRCMD_CS_COMMAND_CALLGM_2				"/CallGM"  // Help
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /CallGM  [N��i dung c�u ho�i] - ���t c�u ho�i cho GM."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ViewCallGM"   // See helper
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ViewCallGM"   // See help
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ViewCallGM   [Danh sa�ch s��(1~10)] - Ki��m tra danh sa�ch c�u ho�i t��i GM "
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/BringCallGM"   // Bring helper
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/BringCallGM"   // Bring help
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /BringCallGM [Danh sa�ch s��(1~10)] - Chuy��n danh sa�ch c�u ho�i t��i GM (Xo�a kho�i server)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/ComeOnNation"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/ComeOnNation"
// 2008-09-09 by cmkwon, /���¼�ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� �߰� - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnNation [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [MAX_USER] [0|Min-level] [0|Max-level] [message to users] - Summons all specified level users in nation with a message."

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/SendItem"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /SendItem [1(Th���ng)|2(BCU)|4(ANI)|3|5|6|7] [MA� item] [S�� l���ng] - T��ng mo�n ��� v��i s�� l���ng t��ng ��ng ���n toa�n b�� ng���i ch�i cu�a qu��c gia t��ng ��ng trong map hi��n ta�i."

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ���� ��¥ ǥ�� ����� �ٸ���
	// �ѱ�(Korea):		YYYY-MM-DD HH:MM:SS
	// �̱�(English):	MM-DD-YYYY HH:MM:SS
	// ��Ʈ��(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%02d-%02d-%04d %02d:%02d:%02d", D, M, Y, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%02d-%02d-%04d %02d:%02d", D, M, Y, h, m

	// 2006-08-08 by dhjin, ��������
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/LevelDist"				// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /LevelDistribution - Hi��n thi� ty� l�� ph�n b�� v�� c��p ��� cu�a ng���i ch�i hi��n ta�i."	// 2006-08-08 by dhjin

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"��� ng��u nhi�n"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"C��"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// Ŭ���̾�Ʈ������ ����ϴ� ��ɾ�(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/call"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /call [T�n nh�n v��t] - ��� nghi� no�i chuy��n 1:1."
	#define STRCMD_C_COMMAND_PARTYCALL					"/formcall"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /formcall - B��t ch�� ��� no�i chuy��n gi��a ca�c tha�nh vi�n trong phi ���i. Chi� Phi ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/formcallend"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /formcallend - K��t thu�c ch�� ��� no�i chuy��n gi��a ca�c tha�nh vi�n trong phi ���i. Chi� Phi ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_GUILDCALL					"/brigcall"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /brigcall - B��t ch�� ��� no�i chuy��n gi��a ca�c tha�nh vi�n trong Ha�m ���i. Chi� Ha�m ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/brigcallend"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /brigcallend - K��t thu�c ch�� ��� no�i chuy��n gi��a ca�c tha�nh vi�n trong Ha�m ���i. Chi� Ha�m ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_CALLEND					"/endcall"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /endcall - K��t thu�c ch�� ��� no�i chuy��n trong phi ���i, ha�m ���i ho��c ca� nh�n."
	#define STRCMD_C_COMMAND_COMBAT						"/confront"
	#define STRCMD_C_COMMAND_BATTLE						"/fight"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /fight [T�n nh�n v��t] - ��� nghi� ���u tay ��i (PvP) v��i ng���i ch�i kha�c."
	#define STRCMD_C_COMMAND_SURRENDER					"/surrender"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /surrender [T�n nh�n v��t] -  G��i l��i ��� nghi� ���u ha�ng t��i ���i thu� trong khi ���u PvP."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/formfight"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /formfight [T�n phi ���i tr���ng] - ��� nghi� ���u phi ���i v��i m��t phi ���i kha�c. Chi� Phi ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/formconfront"
	#define STRCMD_C_COMMAND_PARTYWAR					"/formbattle"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/brigfight"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/brigconfront"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /brigconfront [T�n nh�n v��t] -  ��� nghi� ���u ha�m ���i v��i m��t Ha�m ���i kha�c. Chi� Ha�m ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_GUILDWAR					"/brigbattle"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/brigsurrender"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /brigsurrender -  ���u ha�ng tr��n ���u Ha�m ���i. Chi� Ha�m ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_NAME						"/name"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /name [T�n nh�n v��t] [L��p(2 ~ 11)] - Thay ���i L��p �a� ����c b�� nhi��m cho tha�nh vi�n trong Ha�m ���i. Chi� Ha�m ���i tr���ng m��i co� quy��n s�� du�ng."
	#define STRCMD_C_COMMAND_WARP						"/warp"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/cancelskill"
	#define STRCMD_C_COMMAND_INITCHAT					"/initchat"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /initchat -  Xo�a c��a s�� chat."
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/refusefight"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /refusefight - B��t/T��t ch�� ��� t�� ch��i PvP."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/refusetrade"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /refusetrade -  B��t/T��t ch�� ��� t�� ch��i Trao ���i."
	#define STRMSG_C_050810_0001						"/CloseWindow"
	#define STRMSG_C_050810_0001_HELP					"format: /Closewindow -  Kh�ng hi��n l�n ca�c c��a s�� h��i thoa�i. C��a s�� se� t�� �o�ng."
	#define STRMSG_C_050810_0002						"/OpenWindow"
	#define STRMSG_C_050810_0002_HELP					"format: /Openwindow -  Cho phe�p s�� du�ng mo�i loa�i h��p thoa�i."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"Thi��t bi� ky� n�ng h�� tr��"

// 2010-06-15 by shcho&hslee ��?���� - �� ���?��.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"V��t ph��m Partner"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner Socket Item"		// 2011-09-01 by hskim, ��Ʈ�� �ý��� 2��

// 2006-11-17 by cmkwon, ��Ʈ�� �Ϸ� ���� �ð� ����
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /TimeLimitSystem [on|off] - L��nh B��t/T��t h�� th��ng Gi��i ha�n gi�� ch�i."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /PlayTime - Du�ng ��� hi��n thi� t��ng th��i gian �a� ch�i trong nga�y."

// 2007-10-06 by cmkwon, �������� 2���� ȣĪ�� �ٸ��� ���� - �Ʒ��� ���º��� �ٸ��� ������
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"Thu� li�nh"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"Pho� Thu� li�nh"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint update to DB"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - PCBang user counts"

// 2007-10-06 by dhjin, �������� ���� ��� �������� ����
// 2007-02-13 by dhjin, ��������
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: Subleader [CharacterName] - cho�n pho� thu� li�nh"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"Huy� bo� cho�n pho� thu� li�nh."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"�a� co� �u� pho� thu� li�nh"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s�����c cho�n la�m pho� thu� li�nh th�� nh��t."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s�����c cho�n la�m pho� thu� li�nh th�� hai."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"Kh�ng co� nh�n v��t %s ."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s�hi��n �ang la�m pho� thu� li�nh."

// 2007-02-23 by dhjin, ��������
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/StrategyPointInfo�"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /StrategyPointInfo - th�ng ba�o ti�nh tra�ng cu�a tru� chi��n thu��t."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"Kh�ng co� tru� chi��n thu��t na�o."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"Tru� chi��n thu��t ��a� xu��t hi��n"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"Vu�ng"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"Th��i gian b��t ���u"

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
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  "/Observerstart"  // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  "/Observerstart"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  "/Observerend"   // 2007-03-30 by dhjin, Client only 
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  "/Observerend"   // 2007-03-30 by dhjin, Client only
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   "/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   "/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   "format: /Observer [n] [T�n nh�n v��t] ? Ga�n t�n nh�n v��t c��n quan sa�t cho phi�m s�� n"

// 2007-04-10 by cmkwon, Jamboree server �� ���?
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1   			"/InitJamboree"  
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP  			"format: /InitJamboree [S�� xa�c nh��n] - Kh��i ta�o d�� li��u cho ma�y chu� Jamboree(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1  			"/EntrantJamboree"  


#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP 		"format: /EntrantJamboree [T�n nh�n v��t] - Th�ng tin v�� nh�n v��t se� ����c chuy��n t��i ma�y chu� Jamboree(atum2_db_20)."
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
// 2007-12-27 by cmkwon, �������� ��� ��� �߰� -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA �� ��� ���� ��Ʈ��
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH   "Kh�ng ti�m th��y nho�m."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP  "format: /arena [2(VCN)|4(ANI)]- Hi��n thi� th�ng tin arena hi��n ta�i."

// 2010. 06. 04 by hsLee ARENA ���Ǵ�Ƽ ����. - 
// 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ��Ƽ�Ǵ� �ʵ� 2�� ���̵� ����. (GM ��ɾ� �߰�. /nextscene(���� �ó׸� �� ȣ��.) )

// 2007-06-15 by dhjin, ����
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP	"format:/WatchStart-Kh��i ���ng ch�� ��� quan sa�t."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /WatchEnd � K��t thu�c ch�� ��� quan sa�t."

// 2007-06-22 by dhjin, WarPoint �߰�
#define STRMSG_CS_COMMAND_WARPOINT_0    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_1    "/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP    "format: /WarPoint [s�� l���ng 1~1000000] [|T�n nh�n v��t] � T�ng �i��m danh vo�ng."
 
// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT	 "WarPoint"	 

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0    "/forbidArena "
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP   "format: /forbidArena [T�n nh�n v��t] [Th��i gian(phu�t)] - Kh�ng cho phe�p truy c��p Arena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0  "/releaseArena "
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP "format: /releaseArena [T�n nh�n v��t] - Bo� ch�� ��� c��m truy c��p Arena"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001    "C�� ha�m �a� ����c ��ng ky� tha�nh c�ng."
#define STRMSG_070802_0002    "C��n s�� cho phe�p tr���c khi co� th�� s�� du�ng c�� ha�m."
#define STRMSG_070802_0003    "Ba�n cho phe�p du�ng c�� ha�m %d na�y ch��?"
#define STRMSG_070802_0004    "Kh�ng co� ��ng ky� m��i na�o"
#define STRMSG_070802_0005    "�ang trong tra�ng tha�i ch��"
#define STRMSG_070802_0006    "�a� ����c cho phe�p"
#define STRMSG_070802_0007    "Co� l��i xa�y ra"

// 2007-08-24 by cmkwon, ����Ŀ������ ��� ����/���� ���� ��� �߰� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"Enable"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"Forbid"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[UseSpeaker|UseSpeaker|UseSpeaker] [Enable|Forbid] - Cho phe�p / Kh�ng cho phe�p s�� du�ng Thi��t bi� truy��n tin"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[PrepareShutdown|PrepareShutdown|PrepareShutdown] [Start|Release] Chu��n bi� d��ng server."

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��ɾ� �߰�
#define STRCMD_CS_COMMAND_EntrancePermission_0                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/chophep"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP                      "format: /[chophep | EntrancePermission] [|T�n nh�n v��t] � Cho phe�p nh�n v��t t��ng ��ng va�o pho�ng h��i nghi�. Chi� thu� li�nh m��i co� th�� s�� du�ng"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/khongchophep"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP                "format: /[khongchophep | EntrancePermissionDeny] [T�n nh�n v��t] � Kh�ng cho phe�p nh�n v��t t��ng ��ng va�o pho�ng h��i nghi�. Chi� thu� li�nh m��i co� th�� s�� du�ng."

// 2007-10-05 by cmkwon, �������� ���󺰷� �ٸ����ϱ� ����
#define STRCMD_071005_0000					"%d nga�y %d gi�� %d ph�t %d gi�y", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d Tha�ng %d N�m %d", Day, Month, Year
#define STRCMD_071005_0002					"Tha�ng %d N�m %d",  Month, Year
#define STRCMD_071005_0003					"%d Tha�ng %d", Day, Month


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"Pho� Chi� huy tr���ng" // this is common both nations.
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"Tham m�u tr���ng" // this is common both nations.
#define STRCMD_VCN_INFLUENCE_LEADER						"T��ng t� l��nh"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"Pho� T��ng t� l��nh"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"Tham m�u tr���ng"
#define STRCMD_ANI_INFLUENCE_LEADER						"T��ng th��ng"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"Pho� T��ng th��ng"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"Tham m�u tr���ng"
#define STRCMD_OUTPOST_GUILD_MASTER						"Thuy��n tr���ng %s"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/subleader1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /appointment1 [t�n nh�n v��t] - Chi� �i�nh nh�n v��t se� gi�� ch��c vu� Pho� T��ng t� l��nh ho��c Pho� T��ng Th��ng "
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/subleader2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /appointment2 [t�n nh�n v��t] - Chi� �i�nh nh�n v��t se� gi�� ch��c vu� Tham m�u tr���ng"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT   "/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1   "/HappyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART  "Start"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND  "End"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP  "format: /HappyEvent [255(T��t ca�)|0(Normal nation)|2(BCU)|4(ANI)] [Start|End] [Th��i gian (phu�t)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL   "Normal nation"
#define STRCMD_CS_INFLUENCE_TYPE_VCN   "Bygeniou"
#define STRCMD_CS_INFLUENCE_TYPE_ANI   "Arlington"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK  "AllNation"   // 2007-10-30 by cmkwon, each nation happy hour event system - added
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0   "/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1   "/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2   "/WPAddedMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP  "format: /WPAddedMap [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] - T�ng �i��m WP cho t��t ca� ng���i ch�i trong map."

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/StartHelper"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/StartHelp"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /StartHelper [|Th��i gian(��n vi�: phu�t)] - Cho phe�p s�� du�ng callGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1				"/EndHelper"
#define STRCMD_CS_COMMAND_ENDCALLGM_2				"/EndHelp"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP			"format: /EndHelper - Kh�ng cho s�� du�ng l��nh CallGM"

// 2007-12-27 by cmkwon, �����?�� �?�� ��� ?߰� - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW ?߰�
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, �����?�?�� ���� �����ϱ� - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �?���� ���� - ��ɾ� ?߰�
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [T�n ta�i khoa�n] [Ki��u (1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Th��i ha�n: nga�y] [Ly� do cho ng���i du�ng] / [Ly� do cho admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [T�n ta�i khoa�n]"

// 2008-02-20 by cmkwon, ��ɾ��߰�(��������������ο��Ծ���������- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0                                    "/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1                                    "/ItemAll"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2                                    "/AddAllItem"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP                               "format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Ma� Item] [S�� l���ng] - G��i item cho t��t ca� ca�c nh�n v��t �ang online, kh�ng ph�n bi��t map."

// 2008-02-21 by dhjin, �Ʒ�������- �Ʒ����߰���ɾ�
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1                                                  "/TeamServerReturn"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(XANH)|4(�O�)|6(XANH va� �O�)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [T�n nh�n v��t]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_2                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [S�� pho�ng]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2                                    "/CancelArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [S�� pho�ng]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ���� ������ �˻��� �޺��ڽ����� �˻� ��� �߰�(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"T��t ca�"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - ���� ���� ����          // 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"Tha�nh vi�n"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"Ha�m tr���ng"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"Ha�m pho�"		// 2008-05-20 by dhjin, EP3 - ���� ���� ����
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"Chi� huy phi ha�nh �oa�n 1"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"Tha�nh vi�n phi ha�nh �oa�n 1"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"Chi� huy phi ha�nh �oa�n 2"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"Tha�nh vi�n phi ha�nh �oa�n 2"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"Chi� huy phi ha�nh �oa�n 3"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"Tha�nh vi�n phi ha�nh �oa�n 3"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"Chi� huy phi ha�nh �oa�n 4"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"Tha�nh vi�n phi ha�nh �oa�n 4"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"Chi� huy phi ha�nh �oa�n 5"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"Tha�nh vi�n phi ha�nh �oa�n 5"
 
//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ��������
#define STRCMD_COMMAND_WAR_OPTION_0					"/Mothershipinfooption"
#define STRCMD_COMMAND_WAR_OPTION_1					"/Mothershipinfooption"

// 2008-08-18 by dhjin, ���¸�ũ�?��Ʈ 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [2(BCU) | 4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, �±� PC�� IP���� �ε�
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Phu�t] - 10 phu�t ~ 1440 phu�t"


// 2008-08-21 by dhjin, �Ϲ?, Ư�� ������ �������� �Ӹ� ����
#define STRMSG_080821_0001				"Kh�ng th�� b�� nhi��m nh�n v��t �a� cho�n v��i vi� tri� na�y."


// 2008-09-09 by cmkwon, /���¼?ȯ ��ɾ� ���� ����Ʈ�� ���Ÿ�� ?߰� - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [S�� l���ng] [0|Level th��p nh��t] [0|Level l��n nh��t] [1(B-Gear)|16(M-Gear)|256(A-Gear)|4096(I-Gear)] [Tin nh��n] - Go�i toa�n b�� tha�nh vi�n trong qu��c gia v��i c��p ��� va� loa�i gear t��ng ��ng ���n vi� tri� hi��n ta�i - ke�m theo m��t tin nh��n"

// 2008-09-09 by cmkwon, "/kick" ��ɾ� ?߰� - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/Kick"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [T�n nh�n v��t] - Ng��t k��t n��i cu�a nh�n v��t t��ng ��ng v��i server."


// 2008-09-12 by cmkwon, "/��" ��ɾ� ?߰� - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /fame [�i��m chi��n c�ng ca� nh�n] [�i��m chi��n c�ng ha�m ���i] - T�ng �i��m chi��n c�ng ca� nh�n va� ha�m ���i cu�a nh�n v��t t��ng ��ng."

// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /ReleaseLeaderChatBlock [T�n nh�n v��t] - M�� c��m cha�n cu�a Leader."

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



#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountChangeNation"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /AccountChangeNation [accountUID] [2(BCU)|4(ANI)]"


#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Information on players formation member's (member's must log inside the game)"


#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





