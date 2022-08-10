// 2005-04-28 by cmkwon

#include "Contents.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer에서 처리하는 명령어
	#define STRCMD_CS_COMMAND_MENT_0					"/멘트"
	#define STRCMD_CS_COMMAND_MENT_1					"/맨트"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /멘트 [|String] - 캐릭터 멘트 설정"
	#define STRCMD_CS_COMMAND_MOVE						"/이동"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /이동 [MapIndex] [|ChannelIndex] - 해당 맵채널로 이동함"
	#define STRCMD_CS_COMMAND_COORDINATE				"/좌표"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /좌표 [X] [Y] - 현재 맵의 해당 좌료로 이동"
	#define STRCMD_CS_COMMAND_LIST						"/리스트"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /리스트 - 현재 맵의 사용자 리스트 출력(최대20명)"
	#define STRCMD_CS_COMMAND_USERSEND					"/보내기"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /보내기 [character name] [map name] - 해당 캐릭터를 명시된 맵으로 이동"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/정보"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /정보 [monster name|item name] - 이름에 해당 스트링이 포함되는 몬스터나 아이템의 정보를 출력"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/퀘스트"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /퀘스트 - 캐릭터의 퀘스트 정보 출력"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/퀘스트지우기"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /퀘스트지우기 [퀘스트번호]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/종류"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /종류 [|item kind(0~53)] - 해당 종류의 아이템을 출력"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/종류아템"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /종류아템 [item kind(0~53)] - 해당 종류의 아이템을 추가"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/범위아템"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /범위아템 [from itemnum] ~ [to itemnum] - 해당 아이템을 추가"
	#define STRCMD_CS_COMMAND_STATINIT					"/스탯초기화"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/스텟초기화"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /스탯초기화 [|CharacterName]- 전체스탯초기화"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/파티"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /파티 - 파티 정보를 출력"
	#define STRCMD_CS_COMMAND_GAMETIME					"/시간"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /시간 [|더할 시간량(0~23)] - 현재 시간을 변경(자기 자신의 시간만 바뀜)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/스트링"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/스투링구"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /스트링 [0~5] - 디버그 메세지를 출력하는 level을 결정"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/소환"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /소환 [monster number|monster name] [# of monsters] - 몬스터를 소환(몬스터 이름에 공백이 있는 경우 대신 '_'를 사용하면 됨)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/모든스킬"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /모든스킬 [level] - 해당되는 모든 스킬을 삽입"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/모든아템"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /모든아템 - 해당되는 모든 아이템을 삽입, 스킬 및 Countable아이템 제외"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/모든무기"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /모든무기 - 기어에 맞는 모든 무기 추가"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/모든아템버리기"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/모든아템지우기"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /모든아템버리기 - 해당되는 모든 비장착 아템을 버림(스킬 제외)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/아템"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /아템 [item number] [# of items] - 아이템을 습득함, [# of items]가 없으면 1개로 취급됨"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/드랍"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /드랍 [item number] [|# of items] - 아이템을 필드에 드랍"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/서버"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /서버 - 서버의 정보를 출력함"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/서버맵"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /서버맵 - 모든 맵의 정보를 출력함"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/채널"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /채널 - 현재맵 채널 정보를 출력함"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/디비지"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /디비지 - 테스트용"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/총알"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /총알 [|1형 총알 수] [|2형 총알 수] - 총알 충전하기"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/만피"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /만피 [|character name] - HP, UTC, FUEL을 100% 채움, [character name]이 없으면 자기 자신"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/반피"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /반피 [|줄일 양%] [|character name] - HP, UTC, FUEL을 [줄일 얄%]으로 함, [줄일 양%]이 없으면 50%, [character name]이 없으면 자기 자신"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/일반"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /일반 - 운영자나 게임 마스터 계정인 경우, 일반 계정으로 바꿈"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/특권"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /특권 - 운영자나 게임 마스터 계정인 경우, 일반 계정에서 다시 특수 계정으로 바꿈"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/무적"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /무적 - 운영자나 게임 마스터 계정인 경우, 데미지를 입지 않음"
	#define STRCMD_CS_COMMAND_POWERUP					"/사기"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /사기 [공격력 증가량(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/변수"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /변수 [변수값] - (일반)변수 조정"
	#define STRCMD_CS_COMMAND_LEVELSET					"/레벨"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /레벨 [|level] [|percentage of exp] [|character name] - 레벨을 조정함"
	/////////////////////////////////////////////////
	// start 2011-09-05 by hskim, 파트너 시스템 2차
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/파트너레벨"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /파트너레벨 [|level] [|percentage of exp] - 파트너 레벨을 조정함"
	// end 2011-09-05 by hskim, 파트너 시스템 2차
	/////////////////////////////////////////////////
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/투명"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /투명 - 자신이 다른 캐릭터에게 보이지 않는다"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - 테스트용"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/이벤트"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"경치"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"스피"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"경치복구"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"아템"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"레어아템"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"종료"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /이벤트 [경치|스피|경치복구|아템|레어아템|전쟁포인트] [|배수(%%f)|종료] [시간(단위:분)] [|세력(255:ALL,1:Normal,2:VCN,4:ANI)]- 이벤트 설정,해제"
	#define STRCMD_CS_COMMAND_PREMEUM					"/프리미엄"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"일반"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"슈퍼"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"업그레이드"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"종료"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /프리미엄 [일반|슈퍼|업그레이드|종료]"
// 2008-02-14 by cmkwon, 도시점령전 명령어 제거
// 	#define STRCMD_CS_COMMAND_CITYWAR					"/도시점령전"
// 	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"시작"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"종료"
// 	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /도시점령전 [시작|종료]"
	#define STRCMD_CS_COMMAND_STEALTH					"/스텔스"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /스텔스 - 선공형 몬스터가 먼저 공격하지 않는다"
	#define STRCMD_CS_COMMAND_RETURNALL					"/모두귀환"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /모두귀환 - 해당 세력별 도시맵으로 이동됨"
// start 2011-10-28 by hskim, EP4 [트리거 시스템] - 크리스탈 시스템
	#define STRCMD_CS_COMMAND_RESETTRIGGER				"/리셋트리거"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
	#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /리셋트리거 [트리거번호] - 진행되고 있는 트리거를 종료시키고 초기화 한다."
// end 2011-10-28 by hskim, EP4 [트리거 시스템] - 크리스탈 시스템


// start 2011-06-22 by hskim, 사설 서버 방지
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// 서버 정보 보기
// end 2011-06-22 by hskim, 사설 서버 방지

// start 2012-02-13 by hskim, 몬스터 아이템 드랍 테스트 명령어
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/테스트몬스터드랍"		// 서버 정보 보기
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
	#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /테스트몬스터드랍 [monster number] [test numbers : (1~100000)] - 몬스터 사냥시 드랍되는 아이템을 시뮬레이션해서 보여준다. (서버에 매우 큰 부하를 줍니다. 절대 본섭에서는 사용하지 마세요)"
// end 2012-02-13 by hskim, 몬스터 아이템 드랍 테스트 명령어

// 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 명령어 형식 수정됨 아래에서 다시 정의 함
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/해피아워이벤트"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"시작"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"종료"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /해피아워이벤트 [시작|종료] [진행시간(단위:분)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer에서 처리하는 명령어, 일부는 위에서 사용한 명령어를 그대로 사용함
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer 디버그용"
	#define STRCMD_CS_COMMAND_WHO						"/누구있지"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /누구있지 [|# of users] - 현재 서버에 있는 사용자(맵 무관)를 모두 출력"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/운영등록"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /운영등록 - 운영자에게 일정 이벤트 발생 시 오는 메세지를 받도록 서버에 등록함"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - 클라이언트와 IM 서버가 주고 받는 프로토콜을 모두 출력함"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/서버다운"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /서버다운 [인증숫자] - 서버를 종료시킴"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/누구"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /누구 [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/가기"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /가기 [character name] - 해당 캐릭터가 있는 곳으로 이동함"
	#define STRCMD_CS_COMMAND_COMEON					"/오기"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /오기 [character name] - 해당 캐릭터를 불러옴"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/여단오기"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /여단오기 [여단명] - 해당 여단원을 모두 불러옴"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/여단보내기"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /여단보내기 [여단명] [map name] - 해당 여단원을 맵으로 이동"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/귓말"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /귓말 - 귓말을 막음 혹은 해제, toggle됨"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/길드"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /길드 - 길드 정보 출력"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/날씨"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"기본"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"맑음"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"비"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"눈"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"흐림"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"안개"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"전체"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /날씨 [기본|맑음|비|눈|흐림|안개] [전체|맵이름] [on|off] - 날씨 조정"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/채금"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /채금 [character name] [시간(분)] - 채팅 금지 시킴"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/채금해제"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /채금해제 [character name] - 채팅 금지 해제함"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/명령어"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - 명령어 리스트를 출력함"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/보너스스탯"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/보너스스텟"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - 보너스 스탯 증가"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor에서 처리하는 명령어, 일부는 위에서 사용한 명령어를 그대로 사용함
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/암호설정"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /암호설정 [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/암호복구"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /암호복구 [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/암호목록"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /암호목록"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/암호화"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /암호화 [암호화할 스트링]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/계정막기"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /계정막기 [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/계정풀기"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /계정풀기 [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/막힌계정"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /막힌계정"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "없음 말구!!! 엠게임 서버에만 해당!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "서버 로그인 이름을 입력하세요"
	#define STRCMD_CS_COMMON_DB_0002 "서버 로그인 암호를 입력하세요"
	#define STRCMD_CS_COMMON_DB_0003 "DB 로그인 이름을 입력하세요"
	#define STRCMD_CS_COMMON_DB_0004 "DB 로그인 암호를 입력하세요"

	#define STRCMD_CS_COMMON_MAP_0000 "하드코딩된 부분: 0101맵에서 1번 워프 타겟을 무시하기, 맵에디터에서 쉽게 제거할 수 있는 방법 찾아서 제거해야 함!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "하드코딩된 부분: 0101맵에서 1번 워프 타겟을 무시하기, 맵에디터에서 쉽게 제거할 수 있는 방법 찾아서 제거해야 함!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] 소환몬스터[%8d] 소환시간[%6d초], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index 중복 Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] 소환 몬스터[%8d] 소환시간[%6d초], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== 오브젝트 몬스터 포함\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "다운로드 파일을 찾을 수 없습니다."
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "파일 생성 오류입니다"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "다운로드 파일 읽기 오류입니다"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d일%d시간%d분%d초"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"일반"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"바탈러스"
	#define STRCMD_CS_COMMON_RACE_DECA			"데카"
	#define STRCMD_CS_COMMON_RACE_PHILON		"필론"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"샤린"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"예비"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"예비"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"관리자"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"게임마스터"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"모니터"
	#define STRCMD_CS_COMMON_RACE_GUEST			"게스트"
	#define STRCMD_CS_COMMON_RACE_DEMO			"시연(데모)용"
	#define STRCMD_CS_COMMON_RACE_ALL			"모든 종족"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"알 수 없는 종족"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"이름 없음"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"훈련 에어맨"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd 에어맨"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd 에어맨"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st 에어맨"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd 윙맨"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd 윙맨"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st 윙맨"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rd 리더"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2nd 리더"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1st 리더"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd 에이스"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd 에이스"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st 에이스"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"준장성"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"소장성"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"중장성"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"대장성"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"오토매틱류"
	#define STRCMD_CS_ITEMKIND_VULCAN				"발칸류"
	#define STRCMD_CS_ITEMKIND_DUALIST				"듀얼리스트류"		// 2005-08-01 by hblee : GRENADE -> DUALIST 으로 변경.
	#define STRCMD_CS_ITEMKIND_CANNON				"캐논류"
	#define STRCMD_CS_ITEMKIND_RIFLE				"라이플류"
	#define STRCMD_CS_ITEMKIND_GATLING				"개틀링류"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"런처류"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"메스드라이브류"
	#define STRCMD_CS_ITEMKIND_ROCKET				"로켓류"
	#define STRCMD_CS_ITEMKIND_MISSILE				"미사일류"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"번들류"

	#define STRCMD_CS_ITEMKIND_MINE					"마인류"
	#define STRCMD_CS_ITEMKIND_SHIELD				"쉴드류"
	#define STRCMD_CS_ITEMKIND_DUMMY				"더미류"			
	#define STRCMD_CS_ITEMKIND_FIXER				"픽서류"
	#define STRCMD_CS_ITEMKIND_DECOY				"디코이류"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"아머류"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"엔진류"
	#define STRCMD_CS_ITEMKIND_ENERGY				"에너지류"
	#define STRCMD_CS_ITEMKIND_INGOT				"광석류"
	#define STRCMD_CS_ITEMKIND_CARD					"일반카드류"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"인챈트카드류"
	#define STRCMD_CS_ITEMKIND_TANK					"탱크류"
	#define STRCMD_CS_ITEMKIND_BULLET				"탄알류"
	#define STRCMD_CS_ITEMKIND_QUEST				"퀘스트아이템류"
	#define STRCMD_CS_ITEMKIND_RADAR				"레이더류"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"컴퓨터류"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"갬블카드류"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"인챈트삭제방지카드류"
	#define STRCMD_CS_ITEMKIND_BLASTER				"블래스터류"	// 2005-08-01 by hblee : 블래스터류 추가.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"레일건류"		// 2005-08-01 by hblee : 레일건류 추가.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"무제한액세서리"		// 2006-03-17 by cmkwon, 사용시간이 <영원>인 액세서리 아이템
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"시간제한액세서리"		// 2006-03-17 by cmkwon, 사용시간에 시간 제한이 있는 액세서리 아이템
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"모든무기"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"기본무기"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"총알형 기본무기"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"연료형 기본무기"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"고급무기"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"탄두형 고급무기"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"방어형 고급무기"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"공격 스킬"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"방어 스킬"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"보조 스킬"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"속성 스킬"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1형 몬스터용 아이템"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"몬스터 기관포류(1-1형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"몬스터 빔류(1-2형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"몬스터 전체 공격"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2형 몬스터용 아이템"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"몬스터 로켓(2-1형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"몬스터 미사일류(2-1형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"몬스터 번들류(2-1형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"몬스터 마인류(2-1형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"몬스터 쉴드류(2-2형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"몬스터 더미류(2-2형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"몬스터 픽서류(2-2형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"몬스터 디코이류(2-2형)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"몬스터 파이어류"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"몬스터 충돌가능 빔류"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"몬스터 직진 폭탄류"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"알 수 없는 아이템"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"알 수 없는 기체"

	#define STRCMD_CS_STAT_ATTACK_PART				"공격"
	#define STRCMD_CS_STAT_DEFENSE_PART				"방어"
	#define STRCMD_CS_STAT_FUEL_PART				"연료"
	#define STRCMD_CS_STAT_SOUL_PART				"정신"
	#define STRCMD_CS_STAT_SHIELD_PART				"쉴드"
	#define STRCMD_CS_STAT_DODGE_PART				"회피"
	#define STRCMD_CS_STAT_BONUS					"보너스 스탯"
	#define STRCMD_CS_STAT_ALL_PART					"모든 스탯"
	#define STRCMD_CS_STAT_UNKNOWN					"모르는 스탯"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"자유형"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"공격형"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"멀티형"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"공격형"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"회피형"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"공격형"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"쉴드형"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"방어형"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"지원형"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 아래에서 다시 정의 함
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"바이제니유 일반군"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"바이제니유 정규군"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"알링턴 정규군"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"바탈러스 연방군"

	#define STRCMD_CS_POS_PROW						"레이더 위치(선두 가운데)"
	#define STRCMD_CS_POS_PROWIN					"컴퓨터(중앙 좌측)"
	#define STRCMD_CS_POS_PROWOUT					"1형 무기(선두 좌측)"
	#define STRCMD_CS_POS_WINGIN					"사용안함(중앙 우측)"
	#define STRCMD_CS_POS_WINGOUT					"2형 무기(선두 우측)"
	#define STRCMD_CS_POS_CENTER					"아머(중앙 가운데)"
	#define STRCMD_CS_POS_REAR						"엔진(후미 가운데)"

	// 2010-06-15 by shcho&hslee 펫시스템
	#define STRCMD_CS_POS_ATTACHMENT				"부착물(후미 우측-연료탱크|컨테이너계열)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"부착물(후미 우측-연료탱크|컨테이너계열)"

	// 2010-06-15 by shcho&hslee 펫시스템
	//#define STRCMD_CS_POS_PET						"사용안함(후미 좌측)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"사용안함(후미 좌측)"

	#define STRCMD_CS_POS_PET						"파트너"

	#define STRCMD_CS_HIDDEN_ITEM					"숨겨진 위치"		// 2011-09-20 by hskim, 파트너 시스템 2차 - 숨겨진 아이템

	#define STRCMD_CS_POS_INVALID_POSITION			"미확정 위치"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"인벤토리 위치"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/퀘스트완료"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /퀘스트완료 [|QuesIndex] - 진행중퀘스트 혹은 지정한 퀘스트가 완료처리된다."

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/세력분포"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /세력분포"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/세력변경"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /세력변경 [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/가기몹"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /가기몹 [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - 여단 수정 사항 - 주석 처리 밑으로 이동
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"대원"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"비행여단장"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1대대장"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1대대원"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2대대장"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2대대원"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3대대장"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3대대원"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4대대장"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4대대원"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5대대장"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5대대원"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/전광판"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /전광판 [|지속시간(단위:분)] [공지 사항 내용] - 지도자만 사용 가능, 전광판에 공지사항을 추가하거나 리스트를 본다"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/전광판삭제"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /전광판삭제 [삭제 할 공지시항 인덱스] - 지도자만 사용 가능, 전광판에 특정 공지사항을 삭제한다."
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"세력전 리더"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"세력전 부지도자"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"세력 버프"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"세력 이벤트"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/기여도"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /기여도 [세력(2:BCU, 4:ANI)] [증가분] - 특정 세력의 기여도를 증가시킨다"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/도우미"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/도움말"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /도우미 [상담내용] - GM과 상담을 신청한다."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/도우미보기"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/도움말보기"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /도우미보기 [|개수(1~10)] - GM 상담 요청 리스트를 지정한 개수 만큼 살펴본다"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/도우미가져오기"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/도움말가져오기"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /도우미가져오기 [|개수(1~10)] - GM 상담 요청 리스트를 지정한 개수 만큼 가져온다(서버에서 삭제됨)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/세력오기"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/세력소환"
// 2008-09-09 by cmkwon, /세력소환 명령어 인자 리스트에 기어타입 추가 - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [최대인원] [0|최소레벨] [0|최대레벨] [유저에게 보내는 메시지] - 임의의 지정한 세력, 지정한 레벨의 유저들에게 이벤트맵으로 이동을 요청한다"

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/아이템맵"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/아이템추가맵"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(VCN)|4(ANI)|255(All)] [Item Number] [# of items] - 현재맵의 지정한 세력 유저에게 지정한 아이템을 지급한다"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, 나라별 날짜 표현 방식이 다르다
	// 한국(Korea):		YYYY-MM-DD HH:MM:SS
	// 미국(English):	MM-DD-YYYY HH:MM:SS
	// 베트남(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, 레벨분포
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/레벨분포"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /레벨분포 - 게임에 접속해 있는 유저의 레벨 분포를 보여준다"	// 2006-08-08 by dhjin

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"행운의 상자"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"마크"

///////////////////////////////////////////////////////////////////////////////
// 2006-08-24 by cmkwon
// 클라이언트에서만 사용하는 명령어(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/통화"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /통화 [CharacterName] - 지정한 캐릭터에게 1:1 음성통화를 요청한다."
	#define STRCMD_C_COMMAND_PARTYCALL					"/편대통화"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /편대통화 - 편대장만 사용 가능, 편대원들간 음성 통화를 시작한다."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/편대통화종료"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /편대통화종료 - 편대장만 사용 가능, 편대원들간 음성 통화를 종료한다."
	#define STRCMD_C_COMMAND_GUILDCALL					"/여단통화"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /여단통화 - 여단장만 사용 가능, 여단원들간 음성 통화를 시작한다."
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/여단통화종료"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /여단통화종료 - 여단장만 사용 가능, 여단원들간 음성 통화를 종료한다."
	#define STRCMD_C_COMMAND_CALLEND					"/통화종료"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /통화종료 - 1:1 음성통화 혹은 편대통화 혹은 여단통화를 종료한다."
	#define STRCMD_C_COMMAND_COMBAT						"/대결"
	#define STRCMD_C_COMMAND_BATTLE						"/결투"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /결투 [CharacterName] - 지정한 캐릭터에게 1:1 결투을 요청한다."
	#define STRCMD_C_COMMAND_SURRENDER					"/항복"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /항복 [CharacterName] - 지정한 캐릭터와 1:1 결투시 자신이 항복을 요청한다."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/편대결투"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /편대결투 [CharacterName] - 편대장만 사용 가능, 지정한 캐릭터(편대장)에게 편대 결투를 요청한다."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/편대대결"
	#define STRCMD_C_COMMAND_PARTYWAR					"/편대전투"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/여단전투"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/여단대결"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /여단대결 [CharacterName] - 여단장만 사용 가능, 지정한 캐릭터(여단장)에게 여단 대결을 요청한다."
	#define STRCMD_C_COMMAND_GUILDWAR					"/여단전쟁"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/여단전항복"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /여단전항복 - 여단장만 사용 가능, 여단대결 진행시 항복을 한다"
	#define STRCMD_C_COMMAND_NAME						"/호칭"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /호칭 [CharacterName] [계급(2 ~ 11)] - 여단장만 사용 가능, 지정한 캐릭터를 지정한 계급으로 변경한다."
	#define STRCMD_C_COMMAND_WARP						"/워프"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/스킬취소"
	#define STRCMD_C_COMMAND_INITCHAT					"/채팅창초기화"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /채팅창초기화 - 채팅창을 초기화 한다"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/결투거부"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /결투거부 - 1:1 결투거부 설정을 On/Off 한다."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/거래거부"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /거래거부 - 거래거부 설정을 On/Off 한다."
	#define STRMSG_C_050810_0001						"/창끄기"
	#define STRMSG_C_050810_0001_HELP					"format: /창끄기 - 특정 메시지 박스가 뜨지 않도록 한다. 자동 취소됨"
	#define STRMSG_C_050810_0002						"/창켜기"
	#define STRMSG_C_050810_0002_HELP					"format: /창켜기 - 모든 메시지 박스가 사용된다."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"보조스킬아이템"

// 2010-06-15 by shcho&hslee 펫시스템 - 펫 아이템.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"파트너아이템"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"파트너 소켓 아이템"		// 2011-09-01 by hskim, 파트너 시스템 2차

// 2006-11-17 by cmkwon, 베트남 하루 게임 시간 관련
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/시간제한시스템"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /시간제한시스템 [on|off] - 시간제한시스템 on/off를 설정한다."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/이용시간"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /이용시간 - 오늘 하루 게임 접속 시간을 보여준다"

// 2007-10-06 by cmkwon, 부지도자 2명의 호칭을 다르게 설정 - 아래에 세력별로 다르게 정의함
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"지도자"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"부지도자"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/보너스스탯포인트"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/보너스스텟포인트"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPoint를 DB에 UPDATE"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/PC방"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - 현재 접속해 있는 PC방 유저수를 보여준다"

// 2007-10-06 by dhjin, 부지도자 선출 방법 변경으로 수정
// 2007-02-13 by dhjin, 부지도자
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/부지도자"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /부지도자 [CharacterName] - 부지도자 설정"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"부지도자 설정이 취소 되었습니다."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"부지도자를 더 이상 설정 할 수 없습니다."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s를(을) 첫번째 부지도자로 설정 하였습니다."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s를(을) 두번째 부지도자로 설정 하였습니다."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s의 이름은 존재하지 않습니다."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s는(은) 부지도자로 설정 되어 있습니다."

// 2007-02-23 by dhjin, 거점정보
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/거점정보"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /거점정보 - 현재 거점 진행 정보를 보여준다."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"진행중인 거점전이 없습니다."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"거점전이 진행중입니다."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"진행 지역"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"시작 시간"

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

// 2007-03-30 by dhjin, 옵저버 모드 유저 등록
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0		"/Observerstart"		// 2007-03-30 by dhjin, 클라이언트에서만 사용
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1		"/옵저버시작"			// 2007-03-30 by dhjin, 클라이언트에서만 사용
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0		"/Observerend"			// 2007-03-30 by dhjin, 클라이언트에서만 사용	
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1		"/옵저버종료"			// 2007-03-30 by dhjin, 클라이언트에서만 사용
#define STRCMD_CS_COMMAND_OBSERVER_REG_0			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1			"/옵저버"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP			"format: /옵저버 [n] [CharacterName] - CharacterName유저를 n이라는 번호에 저장한다"

// 2007-04-10 by cmkwon, 대회서버군 관련
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0			"/InitJamboree"			
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/대회서버초기화"		
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [인증숫자] - 대회서버군 DB(atum2_db_20)를 초기화 한다."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0		"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/대회서버참가자"		
// 2008-04-15 by cmkwon, 대회서버(JamboreeServer)는 시스템 수정 - 아래와 같이 형식 수정함
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] - 지정한 캐릭터의 데이터를 대회서버군 DB(atum2_db_20)으로 복사한다."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] - 지정한 캐릭터의 데이터를 대회서버군 DB(atum2_db_20)의 해당 세력으로 복사한다."
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

// 2007-04-17 by dhjin, 레벨 랭크에 관한 등급
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"훈련생"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"주니어"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"에어맨"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"윙맨"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"에이스"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"베테랑"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"탑건"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"윙커맨더"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"히어로"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, 윈도우즈 모드 기능 추가 -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA 팀 출력 관련 스트링
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"아레나 팀을 찾을 수 없습니다."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0			"/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/아레나"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /아레나 [2(BCU)|4(ANI)]- 현재 아레나 진행 정보를 보여준다."

// 2010. 06. 04 by hsLee ARENA 인피니티 관련. - 
// 2010. 06. 04 by hsLee 인티피니 필드 2차 난이도 조절. (GM 명령어 추가. /nextscene(다음 시네마 씬 호출.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee 인티피니 필드 2차 난이도 조절. (GM 명령어 추가. /nextscene(다음 시네마 씬 호출.) )

// 2007-06-15 by dhjin, 관전
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/관전시작"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /관전시작 - 관전을 시작한다."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/관전종료"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /관전종료 - 관전을 종료한다."

// 2007-06-22 by dhjin, WarPoint 추가
#define STRMSG_CS_COMMAND_WARPOINT_0				"/전쟁포인트"
#define STRMSG_CS_COMMAND_WARPOINT_1				"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /전쟁포인트 [개수 1~1000000] [|유저이름] - 전쟁포인트를 추가한다."

// 2007-06-26 by dhjin, 워포인트 이벤트 관련 추가
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"전쟁포인트"

// 2007-07-11 by cmkwon, 아레나블럭 시스템 구현 - 명령어 추가(/아레나금지, /아레나금지해제)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/아레나금지"
#define STRCMD_CS_COMMAND_ARENAFORBID_1				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /아레나금지 [character name] [|시간(분)] - Arena 금지 시킴"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/아레나금지해제"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /아레나금지해제 [character name] - Arena 금지 해제 시킴"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, 여단 마크 심사 시스템 구현 - 추가된 스트링
#define STRMSG_070802_0001				"여단 마크 등록 신청이 완료 되었습니다."
#define STRMSG_070802_0002				"심사를 거친 후 등록이 완료 됩니다."
#define STRMSG_070802_0003				"선택하신 %d개의 여단 마크를 허용 하시겠습니까?"
#define STRMSG_070802_0004				"여단마크 없음 상태"
#define STRMSG_070802_0005				"여단마크 대기 상태"
#define STRMSG_070802_0006				"여단마크 정상 상태"
#define STRMSG_070802_0007				"여단마크 오류 상태"

// 2007-08-24 by cmkwon, 스피커아이템 사용 가능/금지 설정 기능 추가 - 명령어 추가
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/스피커사용"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"가능"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"금지"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format: /[스피커사용|UseSpeaker|UseSpeaker] [가능|금지] - 스피커아이템 사용을 금지/해제 시킴"

// 2007-08-27 by cmkwon, 서버다운준비 명령어 추가(SCAdminTool에서 SCMonitor의 PrepareShutdown을 진행 할 수 있게)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/서버다운준비"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[서버다운준비|PrepareShutdown|PrepareShutdown] [Start|Release] - 서버 종료 준비, 모든 유저 연결 강제 종료됨"

// 2007-08-30 by cmkwon, 회의룸 시스템 구현 - 명령어 추가
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/입장허가"
#define STRCMD_CS_COMMAND_EntrancePermission_1				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[입장허가] [|CharacterName] - 지도자만 사용 가능, 해당 캐릭터를 회의룸 입장 허가 리스트에 추가 한다."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/입장불가"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[입장불가] [CharacterName] - 지도자만 사용 가능, 해당 캐릭터를 회의룸 입장 허가 리스트에서 삭제 한다."

// 2007-10-05 by cmkwon, 연월일을 나라별로 다르게하기 위해
#define STRCMD_071005_0000					"%d일%d시간%d분%d초", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d년%d월%d일", Year, Month, Day
#define STRCMD_071005_0002					"%d년%d월", Year, Month
#define STRCMD_071005_0003					"%d월%d일", Month, Day


// 2007-10-06 by cmkwon, 부지도자 2명의 호칭을 다르게 설정 -
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"세력전 부지도자 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"세력전 부지도자 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"총사령관"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"부사령관"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"참모총장"
#define STRCMD_ANI_INFLUENCE_LEADER						"의장"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"부의장"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"작전본부장"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s 함장"

// 2007-10-06 by dhjin, 부지도자 선출 방법 변경으로 수정
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/직위부여1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /직위부여1 [CharacterName] - BCU : 부사령관, ANI : 부의장 설정"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/직위부여2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /직위부여2 [CharacterName] - BCU : 참모총장, ANI : 작전본부장 설정"

// 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 명령어 형식 수정됨 아래와 같이 다시 정의 함
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/해피아워이벤트"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"시작"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"종료"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /해피아워이벤트 [1(Normal)|2(BCU)|4(ANI)|255(All)] [시작|종료] [진행시간(단위:분)]"

// 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 기존 것을 수정한 것
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"일반세력"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"바이제니유세력"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"알링턴세력"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"전체대상"			// 2007-10-30 by cmkwon, 세력별 해피아워 이벤트 구현 - 추가한 것

// 2007-11-05 by cmkwon, WP 지급 명령어 구현 - 명령어 추가
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP추가맵"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/워포인트추가맵"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP추가맵 [1(Normal)|2(BCU)|4(ANI)|255(All)] [AddWarPoint(1~)] - 현재맵의 지정한 세력 유저에게 WarPoint를 지급한다."

// 2007-11-19 by cmkwon, 진정시스템 업데이트 - 명령어 추가
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/도우미시작"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/도움말시작"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /도우미시작 [|시간(단위:분)] - 진정 시스템 시작"
#define STRCMD_CS_COMMAND_ENDCALLGM_0			"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/도우미종료"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/도움말종료"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /도우미종료 - 진정 시스템 종료"

// 2007-12-27 by cmkwon, 윈도우즈 모드 기능 추가 - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW 추가
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, 윈도우모드 상태 저장하기 - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, 계정 블럭/해제 명령어로 가능한 시스템 구현 - 명령어 추가
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/블럭"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/블럭해제"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, 명령어 추가(접속 중인 유저 모두에게 아이템 지급 - 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/아이템모두"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/아이템추가모두"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] - 접속한 유저들중에 지정한 세력 유저에게 지정한 아이템을 지급한다"

// 2008-02-21 by dhjin, 아레나 통합 - 아레나 추가 명령어
#define STRCMD_CS_COMMAND_ARENAMOVE_0						"/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/아레나이동"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0					"/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/팀서버복귀"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP				"format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0				"/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/대상서버복귀"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP				"format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0						"/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/아레나이벤트"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/아레나이밴트"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP					"format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0				"/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/아레나이벤트해제"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/아레나이밴트해제"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP			"format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool 사용시 아이템 검색시 콤보박스에서 검색 기능 추가(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"모든 아이템류"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - 여단 수정 사항	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"대원"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"비행여단장"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"부여단장"				// 2008-05-20 by dhjin, EP3 - 여단 수정 사항
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1대대장"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1대대원"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2대대장"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2대대원"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3대대장"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3대대원"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4대대장"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4대대원"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5대대장"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5대대원"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - 전장정보
#define STRCMD_COMMAND_WAR_OPTION_0					"/모선전정보옵션"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, 세력마크이벤트 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/세력마크이벤트"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/세력마크이밴트"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [세력 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/세력마크이벤트종료"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/세력마크이밴트종료"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, 태국 PC방 IP정보 로딩
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/피시방리로드타임"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, 일반, 특수 계정의 부지도자 임명 제한
#define STRMSG_080821_0001				"선택한 캐릭터에게 계급을 임명할 수 없습니다."


// 2008-09-09 by cmkwon, /세력소환 명령어 인자 리스트에 기어타입 추가 - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [최대인원] [0|최소레벨] [0|최대레벨] [1(B)|16(M)|256(A)|4096(I)] [유저에게 보내는 메시지] - 임의의 지정한 세력, 지정한 레벨의 유저들에게 이벤트맵으로 이동을 요청한다"

// 2008-09-09 by cmkwon, "/kick" 명령어 추가 - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/킥"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - 해당 캐릭터를 게임에서 종료 시킨다."


// 2008-09-12 by cmkwon, "/명성" 명령어 추가 - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/명성"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /명성 [개인명성] [여단명성] - 접속 캐릭터의 명성, 캐릭터 여단 명성을 올려준다."

// 2008-12-30 by cmkwon, 지도자 채팅 제한 카드 구현 - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/지도자채금해제"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /지도자채금해제 [CharacterName] - 지도자 채금 설정이 해제된다."

// 2009-10-12 by cmkwon, 프리스카 제거 방안 적용 - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0			"/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1			"/시작도시맵"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP			"format: /시작도시맵 [2001|2002] [|CharacterName] - 해당 캐릭터의 일반세력시 시작도시맵을 해당 맵(2001|2002)으로 변경한다."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, 최대 레벨 상향에 따른 추가 사항(레벨별 계급) - 계급뜻(백부장, 대령, 장군, 총독, 정복자, 수호자, 전설적인)
#define	STRCMD_CS_CHARACTER_96_LEVEL_RANK		"센튜리언"
#define	STRCMD_CS_CHARACTER_100_LEVEL_RANK		"콜로넬"
#define	STRCMD_CS_CHARACTER_104_LEVEL_RANK		"제너럴"
#define	STRCMD_CS_CHARACTER_108_LEVEL_RANK		"거버너"
#define	STRCMD_CS_CHARACTER_112_LEVEL_RANK		"컨쿼러"
#define	STRCMD_CS_CHARACTER_116_LEVEL_RANK		"가디언"
#define	STRCMD_CS_CHARACTER_120_LEVEL_RANK		"레전더리"
#define	STRCMD_CS_CHARACTER_XX_LEVEL_RANK		"기본"

#define STRCMD_CS_COMMAND_ENDARENA					"/아레나종료"			// 2012-09-24 by jhseol, 아레나 종료 명령어 수정

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX이벤트 맵 워프제한 - 명령어 추가
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/맵이동제한"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /맵이동제한 [MapIndex] - 해당 맵의 워프 제한을 설정함"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]맵의 워프 제한이 설정 되었습니다."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]맵의 워프 제한이 해제 되었습니다."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]는 허용하지 않는 맵번호입니다."
// end 2012-11-29 by jhseol, OX이벤트 맵 워프제한 - 명령어 추가

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, 타 계정 세력변경
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/계정세력변경"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/AccountInflChange"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /계정세력변경 [계정UID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, 파티원 정보 보기 명령어 추가
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/formationinfo"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /formationinfo [CharacterName] - Information on players formation member's (member's must log inside the game)"
// End. 2013-11-19 by bckim, 파티원 정보 보기 명령어 추가

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





