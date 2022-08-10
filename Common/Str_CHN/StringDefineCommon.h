// 2005-04-28 by cmkwon
// #include "StringDefineCommon.h"
#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - Command handled at the FieldServer
	#define STRCMD_CS_COMMAND_MENT_0					"/ment"
	#define STRCMD_CS_COMMAND_MENT_1					"/ment"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /ment [|String] - 角色ment设置"
	#define STRCMD_CS_COMMAND_MOVE						"/移动"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /移动 [MapIndex] [|ChannelIndex] - 移动到相关地图频道"
	#define STRCMD_CS_COMMAND_COORDINATE				"/坐标"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /坐标 [X] [Y] - 移动到目前地图的相关坐标"
	#define STRCMD_CS_COMMAND_LIST						"/list"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /list - 现在当前地图的使用着表单(最多20名)"
	#define STRCMD_CS_COMMAND_USERSEND					"/发送"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /发送 [character name] [map name] - 相关角色移动到表明的地图"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/信息"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /信息 [monster name|item name] - 显示包含相关名字一行的怪物或道具的信息"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /quest - 显示角色的任务信息"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/删除任务"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /删除任务 [任务编号]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/种类"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /种类 [|item kind(0~53)] - 显示相关种类的道具"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/道具种类"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /道具种类 [item kind(0~53)] - 添加相关种类的道具"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/范围道具"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /范围道具 [from itemnum] ~ [to itemnum] - 添加相关道具"
	#define STRCMD_CS_COMMAND_STATINIT					"/属性点初始化"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/属性点初始化"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /属性点初始化 - 全部属性点初始化"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/party"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /party - 显示编队信息"
	#define STRCMD_CS_COMMAND_GAMETIME					"/时间"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /时间 [|要加的时间(0~23)] - 变更当前的时间(只变更自己的时间)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /string [0~5] - 决定显示DEBUG信息的等级"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/召唤"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /召唤 [monster number|monster name] [# of monsters] - 召唤怪物(怪物名字有空白时'_'使用)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/所有技能"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /所有技能 [level] - 插入相关的所有技能"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/所有道具"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allItem"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /所有武器 - 插入相关的所有道具,技能及时间限制道具除外"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/所有武器"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /所有武器 - 添加战机可以配对的所有武器"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/丢弃所有道具"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/删除所有道具"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /丢弃所有道具 - 丢弃相关的所有未安装的道具(技能除外)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/道具"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /道具 [item number] [# of items] - 拾取道具, [# of items]没有拾取一个"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/掉落"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /掉落 [item number] [|# of items] - 道具掉落在地图"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /server - 显示服务器的信息"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /serverMap - 现在所有地图的信息"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/频道"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /频道 - 显示当前地图频道的信息"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /dbg - 测试用"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/子弹"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /子弹 [|1型 子弹数] [|2型子弹数 ] - 补充子弹"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/满血"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /满血 [|character name] - HP, UTC, FUEL加到 100% , [character name]如果没有,就自己"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/半血"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /半血 [|要减少的量%] [|character name] - HP, UTC, FUEL 设置为[要减少的量%], 如果没有[要减少的量%]时 50%, [character name]没有时自己"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/一般"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /一般 - GM帐号时,更换一般帐号"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/特权"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /特权 - GM帐号时,从一般帐号更换特殊帐号."
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/无敌"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /无敌 - GM帐号时,不会受伤害"
	#define STRCMD_CS_COMMAND_POWERUP					"/士气"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /士气 [攻击力增加量(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/变量"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /变量 [变量值] - (一般)调整变量"
	#define STRCMD_CS_COMMAND_LEVELSET					"/等级"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /等级 [|level] [|percentage of exp] [|character name] - 调整等级"

	#define STRCMD_CS_COMMAND_PARTNERLEVELSET			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_1			"/partnerlevel"
	#define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /partnerlevel [|level] [|percentage of exp] "
	
	
	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/透明"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /透明 - 别的角色看不见自己"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - 测试用"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/活动"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"经验值"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"restoreexppoint"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"道具"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"稀有道具"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"终止"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /活动 [经验值|SPI|恢复经验值|道具|稀有道具|战争点数] [|倍数(%%f)|终止] [时间(单位:分)] [|势力(255:ALL,1:Normal,2:VCN,4:ANI)]- 活动设置,解除"
	#define STRCMD_CS_COMMAND_PREMEUM					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"一般"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"super"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"升级"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"终止"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /奖金 [一般|超级|升级|终止]"
// 2008-02-14 by cmkwon, 档矫痢飞傈 疙飞绢 力芭
//	#define STRCMD_CS_COMMAND_CITYWAR					"/城市占领战"
//	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
//	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"开始"
//	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"结束"
//	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /城市占领战 [开始|结束]"
	#define STRCMD_CS_COMMAND_STEALTH					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /stealth - 主动攻击型怪物不会先攻击"
	#define STRCMD_CS_COMMAND_RETURNALL					"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /returnAll - Happy Our Event"

// start 2011-10-28 by hskim, EP4 [飘府芭 矫胶袍] - 农府胶呕 矫胶袍
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [飘府芭 矫胶袍] - 农府胶呕 矫胶袍

// start 2012-02-13 by hskim, 阁胶磐 酒捞袍 靛而 抛胶飘 疙飞绢
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// 辑滚 沥焊 焊扁
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, 阁胶磐 酒捞袍 靛而 抛胶飘 疙飞绢

// start 2011-06-22 by hskim, 荤汲 辑滚 规瘤
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// 辑滚 沥焊 焊扁
// end 2011-06-22 by hskim, 荤汲 辑滚 规瘤
			   
// 2007-10-30 by cmkwon, 技仿喊 秦乔酒况 捞亥飘 备泅 - 疙飞绢 屈侥 荐沥凳 酒贰俊辑 促矫 沥狼 窃
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/Happy Our Event"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"开始"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"结束"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /Happy Our Event [开始|结束] [进行时间(单位:分)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - Command used in IMServer, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer Debug用"
	#define STRCMD_CS_COMMAND_WHO						"/who"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /who [|# of users] - 显示目前服务器的所有玩家(和地图无关)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /registerAdmin - GM进行日程活动时登陆服务器接收信息"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - 显示客户端和IM服务器交换的所有协议"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /serverDown [认证数字] - 终止服务器"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /whoareYou [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /go [character name] - 移动到有相关角色的地方"
	#define STRCMD_CS_COMMAND_COMEON					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /comeon [character name] - 传唤相关角色"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /comeonGuild [军团名称] - 传唤相关的所有军团团员"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /sendGuild [军团名] [map name] - 相关军团员移动到地图"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/悄悄话"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /悄悄话 - 阻止悄悄话或解除, toggle"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /guildInfo - 显示军团信息"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/天气"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"基本"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"晴"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"雨"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"雪"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"阴"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"雾"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"全体"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /天气 [基本|晴|雨|雪|阴|雾] [全体|地图名称] [on|off] - 调整天气"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/禁止聊天"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /禁止聊天 [character name] [时间(分)] - 禁止聊天"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/解除禁止聊天"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /解除禁止聊天 [character name] - 解除禁止聊天"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/命令"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - 显示命令表单"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/奖励属性点"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/奖励属性点"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - 增加奖励属性点"
// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - Command used in AtumMonitor, some are used with the same command as the above
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/设置密码"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /设置密码 [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/恢复密码"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /恢复密码 [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/密码目录"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /密码目录"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/加密"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /加密 [要加密的String]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/封停帐号"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /封停帐号 [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/解除帐号"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /解除帐号 [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/已封停的帐号"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /已封停的帐号"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "没有就算了!!! 只适用在Mgame服务器!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "请输入Login名称"
	#define STRCMD_CS_COMMON_DB_0002 "请输入Login密码"
	#define STRCMD_CS_COMMON_DB_0003 "请输入DB Login名称"
	#define STRCMD_CS_COMMON_DB_0004 "请输入DB Login密码"

	#define STRCMD_CS_COMMON_MAP_0000 "hard coding部分: 在0101地图忽略1号传送目标,map edit找到容易除去的方法才可以除去!\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "hard coding部分: 在0101地图忽略1号传送目标,map edit找到容易除去的方法才可以除去!\r\n"
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] 召唤怪物[%8d] 召唤时间[%6d秒], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index 重复 Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] 召唤怪物[%8d] 召唤时间[%6d秒], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "  Tatal Monster Count : [%4d] <== 包含目标怪物\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "找不到下载文件"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "文件生成错误"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "读取下载文件错误"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d日%d时%d分%d秒"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"一般"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"塔伦斯"
	#define STRCMD_CS_COMMON_RACE_DECA			"迪卡"
	#define STRCMD_CS_COMMON_RACE_PHILON		"菲仑"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"沙林"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"预备"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"预备"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"管理员"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"游戏管理员"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"监视"
	#define STRCMD_CS_COMMON_RACE_GUEST			"GUEST"
	#define STRCMD_CS_COMMON_RACE_DEMO			"演示(demo)用"
	#define STRCMD_CS_COMMON_RACE_ALL			"所有种族"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"未知的种族"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"没有名字"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"训练飞行员"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rd 飞行员"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2nd 飞行员"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1st 飞行员"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rd 僚机驾驶员"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2nd 僚机驾驶员"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1st 僚机驾驶员"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rd 舰队指挥官"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2nd 舰队指挥官"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1st 舰队指挥官"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rd 王牌飞行员"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2nd 王牌飞行员"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1st 王牌飞行员"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"准将"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"少将"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"中将"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"上将"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"自动类"
	#define STRCMD_CS_ITEMKIND_VULCAN				"转轮机枪类"
	#define STRCMD_CS_ITEMKIND_DUALIST				"双管类"		// 2005-08-01 by hblee : GRENADE -> DUALIST 栏肺 函版.
	#define STRCMD_CS_ITEMKIND_CANNON				"加农类"
	#define STRCMD_CS_ITEMKIND_RIFLE				"膛线炮类"
	#define STRCMD_CS_ITEMKIND_GATLING				"机关枪类"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"榴弹类"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"突击类"
	#define STRCMD_CS_ITEMKIND_ROCKET				"火箭类"
	#define STRCMD_CS_ITEMKIND_MISSILE				"导弹类"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"集束类"

	#define STRCMD_CS_ITEMKIND_MINE					"钻地类"
	#define STRCMD_CS_ITEMKIND_SHIELD				"护盾类"
	#define STRCMD_CS_ITEMKIND_DUMMY				"伪装类"			
	#define STRCMD_CS_ITEMKIND_FIXER				"固定类"
	#define STRCMD_CS_ITEMKIND_DECOY				"诱惑类"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"防御类"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"引擎类"
	#define STRCMD_CS_ITEMKIND_ENERGY				"能量类"
	#define STRCMD_CS_ITEMKIND_INGOT				"矿石类"
	#define STRCMD_CS_ITEMKIND_CARD					"普通卡片类"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"锻造卡片类"
	#define STRCMD_CS_ITEMKIND_TANK					"坦克类"
	#define STRCMD_CS_ITEMKIND_BULLET				"子弹类"
	#define STRCMD_CS_ITEMKIND_QUEST				"任务道具类"
	#define STRCMD_CS_ITEMKIND_RADAR				"雷达类"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"电脑类"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"属性随机类"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"锻造类"
	#define STRCMD_CS_ITEMKIND_BLASTER				"爆破类"	// 2005-08-01 by hblee : 添加爆破类.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"高射机枪类"		// 2005-08-01 by hblee : 添加高射机枪类.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"无限制附件"		// 2006-03-17 by cmkwon, 使用时间<永远>附件道具
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"限制时间附件"		// 2006-03-17 by cmkwon, 使用时间有限制的附件道具
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"所有武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"轻型武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"子弹型轻型武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"炮弹型轻型武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"重型武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"攻击型重型武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"防御型重型武器"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"攻击技能"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"防御技能"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"补助技能"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"属性技能"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1型 怪物用道具"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"怪物机关炮类(1-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"怪物电子类(1-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"怪物全体攻击"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2型怪物用道具"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"怪物导弹类(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"怪物导弹类(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"怪物束类(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"怪物钻地类(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"怪物护盾类(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"怪物伪装类(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"怪物固定类(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"怪物诱惑类(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"怪物燃烧类"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"怪物目标电子类"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"怪物直射类"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"未知的道具"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"未知的机体"

	#define STRCMD_CS_STAT_ATTACK_PART				"攻击"
	#define STRCMD_CS_STAT_DEFENSE_PART				"防御"
	#define STRCMD_CS_STAT_FUEL_PART				"燃料"
	#define STRCMD_CS_STAT_SOUL_PART				"精神"
	#define STRCMD_CS_STAT_SHIELD_PART				"护盾"
	#define STRCMD_CS_STAT_DODGE_PART				"回避"
	#define STRCMD_CS_STAT_BONUS					"奖励属性点"
	#define STRCMD_CS_STAT_ALL_PART					"所有属性点"
	#define STRCMD_CS_STAT_UNKNOWN					"未知的属性点"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"自由型"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"攻击型"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"多目标型"	
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"攻击型"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"回避型"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"攻击型"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"护盾型"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"防御型"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"支援型"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, 技仿喊 秦乔酒况 捞亥飘 备泅 - 酒贰俊辑 促矫 沥狼 窃
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"本杰明一般军"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"本杰明正规军"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"艾林顿正规军"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"塔伦斯联邦军"

	#define STRCMD_CS_POS_PROW						"雷达位置(船头中间)"
	#define STRCMD_CS_POS_PROWIN					"电脑(中央左侧)"
	#define STRCMD_CS_POS_PROWOUT					"1型武器(船头左侧)"
	#define STRCMD_CS_POS_WINGIN					"不使用(中央右侧)"
	#define STRCMD_CS_POS_WINGOUT					"2型武器(船头右侧)"
	#define STRCMD_CS_POS_CENTER					"装甲(中间)"
	#define STRCMD_CS_POS_REAR						"引擎(后尾中间)"

	// 2010-06-15 by shcho&hslee 脐矫胶袍
	#define STRCMD_CS_POS_ATTACHMENT				"附加装备(后尾右侧- 燃料|集装箱系列)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"Accessory(Right side of rear-Fueltank|container type)"

	// 2010-06-15 by shcho&hslee 脐矫胶袍
	//#define STRCMD_CS_POS_PET						"荤侩救窃(饶固 谅螟)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"Not to use(Left side of rear)"

	#define STRCMD_CS_POS_PET						"不使用(后尾左侧)"

    #define STRCMD_CS_HIDDEN_ITEM					"Hidden Position"		// 2011-09-20 by hskim, 颇飘呈 矫胶袍 2瞒 - 见败柳 酒捞袍
	#define STRCMD_CS_POS_INVALID_POSITION			"未确定位置"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"道具栏位置"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/完成任务"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /完成任务 [|QuesIndex] - 任务进行中或者指定的任务即将完成"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/势力分布"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /势力分布"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/势力变更"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format: /势力变更 [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format: /GoMonster [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - 咯窜 荐沥 荤亲 - 林籍 贸府 关栏肺 捞悼
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"队员"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"飞行军团长"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1队队长"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1队队员"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2队队长"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2队队员"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3队队长"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3队队员"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4队队长"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4队队员"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5队队长"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5队队员"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/电光板"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format: /电光板 [|持续时间(单位:分)] [公告事项内容] - 只有舰队指挥官才可以使用, 可以添加公告事项或者查看表单"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/删除电光板"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /删除电光板 [要删除的公告事项INDEX] - 只有舰队指挥官才可以使用,可以删除电光板的指定公告事项"
	
	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"势力战舰队指挥官"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"势力战舰队领航员"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"势力战技能状态"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"势力战活动"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/贡献度"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /贡献度 [势力(2:VCN, 4:ANI)] [增加分] - 可以增加势力的贡献度"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/向导"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/帮助"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /向导 [内容] - 请和GM申请交谈."
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/查看向导"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/查看帮助"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /查看向导 [|数量(1~10)] - 查看GM邀请交谈表格的指定数量 "
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/提出向导"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/提出帮助"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /提出向导 [|数量(1~10)] - 提出GM邀请交谈表格的指定数量(服务器会删除)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/到达势力"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/召唤势力"
// 2008-09-09 by cmkwon, /技仿家券 疙飞绢 牢磊 府胶飘俊 扁绢鸥涝 眠啊 - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [最大人数] [0|最小等级] [0|最高等级] [发给玩家的信息] - 邀请任意指定的势力,指定等级的玩家移动到活动地图"
	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/道具地图"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/道具添加地图"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(BCU)|4(ANI)|3|5|6|7] [Item Number] [# of items] - 支付当前地图的指定势力玩家指定的道具"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, 各国的日期显示方式不一样
	// 韩国(Korea):		YYYY-MM-DD HH:MM:SS
	// 美国(English):	MM-DD-YYYY HH:MM:SS
	// 越南(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, 饭骇盒器
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/等级分布"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /等级分布 - 显示在线玩家的等级分布"	// 2006-08-08 by dhjin

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"幸运箱"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"徽章类"

	///////////////////////////////////////////////////////////////////////////////
	// 2006-08-24 by cmkwon
	// 努扼捞攫飘俊辑父 荤侩窍绰 疙飞绢(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/通话"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /通话 [CharacterName] - 邀请指定的角色 1:1语音通话"
	#define STRCMD_C_COMMAND_PARTYCALL					"/编队通话"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /编队通话 - 只有编队队长可以使用,开始编队员之间的语音通话."
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/结束编队通话"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /结束编队通话 - 只有编队队长可以使用.结束编队员之间的语音通话"
	#define STRCMD_C_COMMAND_GUILDCALL					"/军团通话"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /军团通话 - 只有军团长可以使用,开始军团员之间的语音通话"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/结束军团通话"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /结束军团通话 - 只有军团长可以使用,结束军团员之间的通话"
	#define STRCMD_C_COMMAND_CALLEND					"/结束通话"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /结束通话 - 结束1:1军团通话或者编队通话或者军团通话."
	#define STRCMD_C_COMMAND_COMBAT						"/对决"
	#define STRCMD_C_COMMAND_BATTLE						"/决斗"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /决斗 [CharacterName] - 和指定的角色邀请 1:1决斗."
	#define STRCMD_C_COMMAND_SURRENDER					"/投降"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /投降 [CharacterName] - 和指定的角色1:1 决斗时可以申请投降."
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/编队决斗"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /编队决斗 [CharacterName] - 只有编队队长可以使用, 申请指定的角色(编队队长)编队决斗."
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/编队对决"
	#define STRCMD_C_COMMAND_PARTYWAR					"/编队战斗"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/军团战斗"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/军团对决"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /军团对决 [CharacterName] - 只有军团长可以使用, 申请和指定角色(军团长)军团决斗"
	#define STRCMD_C_COMMAND_GUILDWAR					"/军团战争"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/军团战投降"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /军团战投降 - 只有军团长可以使用,军团对战时投降"
	#define STRCMD_C_COMMAND_NAME						"/称号"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /称号 [CharacterName] [阶级(2 ~ 11)] - 只有军团长可以使用,为指定角色变更指定阶级."
	#define STRCMD_C_COMMAND_WARP						"/传送"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/取消技能"
	#define STRCMD_C_COMMAND_INITCHAT					"/初始化聊天窗口"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /初始化聊天窗口 - 初始化聊天窗口."
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/拒绝决斗"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /拒绝决斗 - 设置1:1 拒绝决斗On/Off."
	#define STRCMD_C_COMMAND_REFUSETRADE				"/拒绝交易"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /拒绝交易 - 设置拒绝交易On/Off."
	#define STRMSG_C_050810_0001						"/关闭窗口"
	#define STRMSG_C_050810_0001_HELP					"format: /关闭窗口 - 不显示特定的信息栏.会自动取消"
	#define STRMSG_C_050810_0002						"/打开窗口"
	#define STRMSG_C_050810_0002_HELP					"format: /打开窗口 - 所有的信息栏都会使用."

// 2006-09-29 by cmkwon
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"补助技能道具"

// 2010-06-15 by shcho&hslee 脐矫胶袍 - 脐 酒捞袍.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"Partner Item"	 
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM				"Partner Socket Item"		// 2011-09-01 by hskim, 颇飘呈 矫胶袍 2瞒

// 2006-11-17 by cmkwon, 海飘巢 窍风 霸烙 矫埃 包访
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSystem"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/限制时间系统"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /限制时间系统 [on|off] - 设置时间限制系统 on/off."
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/利用时间"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /利用时间 - 显示一天游戏在线时间"

// 2007-10-06 by cmkwon, 何瘤档磊 2疙狼 龋莫阑 促福霸 汲沥 - 酒贰俊 技仿喊肺 促福霸 沥狼窃
//// 2006-12-13 by cmkwon
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"舰队指挥官"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"舰队领航员"

// 2007-01-08 by dhjin
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/奖励属性点"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/奖励属性点"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] -  DB更新BonusStatPoint"

// 2007-01-25 by dhjin
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/PCBang"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/网吧"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /PCBang - 显示目前登陆的网吧玩家"

// 2007-10-06 by dhjin, 何瘤档磊 急免 规过 函版栏肺 荐沥
// 2007-02-13 by dhjin, 何瘤档磊
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/舰队领航员"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /舰队领航员 [CharacterName] - 设置舰队领航员"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"已取消设置舰队领航员."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"不能再设置舰队领航员."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%s设置为第一个舰队领航员."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%s设置为第二个舰队领航员."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%s不存在."
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%s已设置为舰队领航员."

// 2007-02-23 by dhjin, 芭痢沥焊
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0			"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/据点信息"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /据点信息 - 显示目前据点的进行情况."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"没有正在进行的据点战."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"据点战正在进行."
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"进行区域"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"开始时间"

// 2007-03-29 by cmkwon
#define STRCMD_CS_UNITKIND_BGEAR					"B型战机"
#define STRCMD_CS_UNITKIND_MGEAR					"M型战机"
#define STRCMD_CS_UNITKIND_AGEAR					"A型战机"
#define STRCMD_CS_UNITKIND_IGEAR					"I型战机"
#define STRCMD_CS_UNITKIND_BGEAR_ALL				"所有B型战机"
#define STRCMD_CS_UNITKIND_MGEAR_ALL				"所有M型战机"
#define STRCMD_CS_UNITKIND_AGEAR_ALL				"所有A型战机"
#define STRCMD_CS_UNITKIND_IGEAR_ALL				"所有I型战机"
#define STRCMD_CS_UNITKIND_GEAR_ALL					"所有战机"

// 2007-03-30 by dhjin, 可历滚 葛靛 蜡历 殿废
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0  "/Observerstart"  // 2007-03-30 by dhjin, 只适用于客户端
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1  "/启动观察员模式"   // 2007-03-30 by dhjin, 只适用于客户端
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0  "/Observerend"   // 2007-03-30 by dhjin, 只适用于客户端
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1  "/结束观察员模式"   // 2007-03-30 by dhjin, 只适用于客户端
#define STRCMD_CS_COMMAND_OBSERVER_REG_0   			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1   "/观察员"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP   "format: /观察员 [n] [CharacterName] - 角色名称保存在编号n"

// 2007-04-10 by cmkwon, Jamboree server 焙 包访
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0   			"/InitJamboree"   
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/初始化活动服务器"		
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [认证数字] - 初始化大会服务器群 DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0  			"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/活动服务器参赛人员"		
// 2008-04-15 by cmkwon, 措雀辑滚(JamboreeServer)绰 矫胶袍 荐沥 - 酒贰客 鞍捞 屈侥 荐沥窃
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] - 复制制定角色的数据到活动服务器群 DB(atum2_db_20)."
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] - 复制制定角色的数据到活动服务器群 DB(atum2_db_20)."

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

// 2007-04-17 by dhjin, 饭骇 珐农俊 包茄 殿鞭
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"下士"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"中士"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"上士"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"少尉"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"中尉"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"上尉"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"少校"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"中校"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"上校"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, 扩档快令 葛靛 扁瓷 眠啊 -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA 评 免仿 包访 胶飘傅
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"没有找到阿雷纳队伍."
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0   "/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/阿雷纳"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /阿雷纳[2(BCU)|4(ANI)]- 显示目前阿雷纳的进行状况."

// 2010. 06. 04 by hsLee ARENA 牢乔聪萍 包访. - 
// 2010. 06. 04 by hsLee 牢萍乔聪 鞘靛 2瞒 抄捞档 炼例. (GM 疙飞绢 眠啊. /nextscene(促澜 矫匙付 纠 龋免.) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee 牢萍乔聪 鞘靛 2瞒 抄捞档 炼例. (GM 疙飞绢 眠啊. /nextscene(促澜 矫匙付 纠 龋免.) )

// 2007-06-15 by dhjin, 包傈
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/开始观战"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /开始观战 – 已开始观战."
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/结束观战"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /结束观战 – 已结束观战."

// 2007-06-22 by dhjin, WarPoint 眠啊
#define STRMSG_CS_COMMAND_WARPOINT_0					"/战争点数"
#define STRMSG_CS_COMMAND_WARPOINT_1					"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /战争点数 [数量 1~1000000] [|用户名称] - 添加战争点数."

// 2007-06-26 by dhjin, 况器牢飘 捞亥飘 包访 眠啊
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"战争点数"

// 2007-07-11 by cmkwon, Arena block system materialization - Add command(/forbidAreana, /releaseArena)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/禁止阿雷纳"
#define STRCMD_CS_COMMAND_ARENAFORBID_1    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2    "/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /禁止阿雷纳 [character name] [|时间(分)] - 禁止Arena "
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/解除禁止阿雷纳"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2  "/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /解除禁止阿雷 [character name] - 解除禁止Arena "

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, Brigade mark screening system materialization - added string
#define STRMSG_070802_0001				"军团标志申请已完成."
#define STRMSG_070802_0002				"审核通过以后生效."
#define STRMSG_070802_0003				"允许所选的%d个军团标志吗?"
#define STRMSG_070802_0004				"目前没有军团标志"
#define STRMSG_070802_0005				"军团标志等待状态"
#define STRMSG_070802_0006				"军团标志正常状态"
#define STRMSG_070802_0007				"军团标志出错"

// 2007-08-24 by cmkwon, 胶乔目酒捞袍 荤侩 啊瓷/陛瘤 汲沥 扁瓷 眠啊 - 疙飞绢 眠啊
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/使用扩音器"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"可用"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"禁止"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP				"format: /使用扩音器 [可用|禁止] – 禁止/解除使用扩音器"

// 2007-08-27 by cmkwon, PrepareShutdown command(GM can shutdown game server in SCAdminTool)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/准备关闭服务器"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[准备关闭服务器|PrepareShutdown|PrepareShutdown] [Start|Release] – 准备关闭服务器, 所有玩家强制结束游戏"

// 2007-08-30 by cmkwon, 雀狼冯 矫胶袍 备泅 - 疙飞绢 眠啊
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/允许进入"
#define STRCMD_CS_COMMAND_EntrancePermission_1                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2                                     "/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[允许进入] [|CharacterName] – 只有领导人才能使用，将相关角色添加到进入会场许可列表里."
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/取消进入"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2                               "/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[取消进入] [CharacterName] – 只有领导人才能使用,将相关角色从会场许可列表里删除."

// 2007-10-05 by cmkwon, different each nations.
#define STRCMD_071005_0000					"%d日%d时%d分%d秒", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d年%d月%d日", Year, Month, Day
#define STRCMD_071005_0002					"%d年%d月", Year, Month
#define STRCMD_071005_0003					"%d月%d日", Month, Day


// 2007-10-06 by cmkwon, Set name 2 sub-leader each nations
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"国战副领袖 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"国战副领袖 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"元帅"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"上将"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"参谋长"
#define STRCMD_ANI_INFLUENCE_LEADER						"元帅"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"上将"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"参谋长"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s基地司令"

// 2007-10-06 by dhjin, command to set 2 sub-leader
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/赋予职位1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /赋予职位1 [CharacterName] - VCN : 上将, ANI : 上将"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/赋予职位2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /赋予职位2 [CharacterName] - VCN : 参谋长, ANI : 参谋长"

// 2007-10-30 by cmkwon, each nation happy hour event system - Command system is changed.
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/欢乐时光"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"开始"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"结束"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /欢乐时光 [255(所有国家)|0(一般玩家)|2(VCN)|4(ANI)] [开始|结束] [进行时间(单位:分)]"
 
// 2007-10-30 by cmkwon, each nation happy hour event system - Changed with old system.
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"一般玩家"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"本杰明"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"艾林顿"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"所有对象"			// 2007-10-30 by cmkwon, 进行国家欢乐时光活动- 添加
 
// 2007-11-05 by cmkwon, WP award command - added
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP奖励"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/WP奖励"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP奖励 [1(Normal)|2(VCN)|4(ANI)|3|5|6|7] [AddWarPoint(1~)] – 给当前地图的指定国家的玩家奖励WP。"

// 2007-11-19 by cmkwon, CallGM system - new command
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/开放亲情系统"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/开始提示"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /开放亲情系统 [|时间(单位:分钟)] – 开放亲情系统"
#define STRCMD_CS_COMMAND_ENDCALLGM_0				"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/关闭亲情系统"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/结束提示"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /关闭亲情系统 – 关闭亲情系统"

// 2007-12-27 by cmkwon, 扩档快令 葛靛 扁瓷 眠啊 - STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW 眠啊
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, 扩档快葛靛 惑怕 历厘窍扁 - 
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, 拌沥 喉钒/秦力 疙飞绢肺 啊瓷茄 矫胶袍 备泅 - 疙飞绢 眠啊
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/封停"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/解封"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, 疙飞绢眠啊(立加吝牢蜡历葛滴俊霸酒捞袍瘤鞭- 
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/所有道具"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/添加所有道具"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] – 给已登陆的指定势力的玩家奖励指定道具"

// 2008-02-21 by dhjin, 酒饭唱烹钦- 酒饭唱眠啊疙飞绢
#define STRCMD_CS_COMMAND_ARENAMOVE_0                                                         "/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/阿雷纳移动"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0                                                  "/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/离开战队服务器"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP                                   "format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0                                     "/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/离开目标服务器"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP                                 "format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0                                                         "/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/阿雷纳活动"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/阿雷纳活动"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP                                                    "format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0                                    "/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/取消阿雷纳活动"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/取消阿雷纳活动"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP                                "format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool 荤侩矫 酒捞袍 八祸矫 霓焊冠胶俊辑 八祸 扁瓷 眠啊(K0000143) - 
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"道具类"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - 咯窜 荐沥 荤亲	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"队员"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"军团长"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"副军团长"				// 2008-05-20 by dhjin, EP3 - 军团修改事项
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1队队长"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1队队员"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2队队长"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2队队员"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3队队长"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3队队员"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4队队长"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4队队员"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5队队长"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5队队员"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - 傈厘沥焊
#define STRCMD_COMMAND_WAR_OPTION_0					"/战场选项"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, 技仿付农捞亥飘 
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/徽章活动"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/徽章活动"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [国家2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/结束徽章活动"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/结束徽章活动"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, 怕惫 PC规 IP沥焊 肺爹
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/网吧载入时间"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ~ 1440 Min"


// 2008-08-21 by dhjin, 老馆, 漂荐 拌沥狼 何瘤档磊 烙疙 力茄
#define STRMSG_080821_0001				"无法任命选择的角色。"


// 2008-09-09 by cmkwon, /技仿家券 疙飞绢 牢磊 府胶飘俊 扁绢鸥涝 眠啊 - 
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(BCU)|4(ANI)|255(All)] [最大人数] [0|最低等级] [0|最低等级] [1(B)|16(M)|256(A)|4096(I)] [向玩家发送的信息] – 邀请移动指定势力，指定等级的玩家到活动地图。"

// 2008-09-09 by cmkwon, "/kick" 疙飞绢 眠啊 - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/踢出"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] – 结束相关角色的游戏"


// 2008-09-12 by cmkwon, "/疙己" 疙飞绢 眠啊 - 
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/声望"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /声望 [个人声望] [军团声望] – 增加登陆角色的声望，军团声望。"

// 2008-12-30 by cmkwon, 瘤档磊 盲泼 力茄 墨靛 备泅 - 
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1 "/解除禁言"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP "format: /解除禁言 [CharacterName] – 解除该玩家禁言"

// 2009-10-12 by cmkwon, 橇府胶墨 力芭 规救 利侩 - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                               "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                               "/StartCity"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                           "format: /StartCity [2001|2002] [|CharacterName] - Set the character`s beginning city to 2001 or 2002 when their nation is initialized."


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, 弥措 饭骇 惑氢俊 蝶弗 眠啊 荤亲(饭骇喊 拌鞭) - 拌鞭舵(归何厘, 措飞, 厘焙, 醚刀, 沥汗磊, 荐龋磊, 傈汲利牢)
#define       STRCMD_CS_CHARACTER_96_LEVEL_RANK             "Centurion"
#define       STRCMD_CS_CHARACTER_100_LEVEL_RANK            "Colonel"
#define       STRCMD_CS_CHARACTER_104_LEVEL_RANK            "General"
#define       STRCMD_CS_CHARACTER_108_LEVEL_RANK            "Governer"
#define       STRCMD_CS_CHARACTER_112_LEVEL_RANK            "Conqueror"
#define       STRCMD_CS_CHARACTER_116_LEVEL_RANK            "Guardian"
#define       STRCMD_CS_CHARACTER_120_LEVEL_RANK            "Legendary"
#define       STRCMD_CS_CHARACTER_XX_LEVEL_RANK             "Basic"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, 酒饭唱 辆丰 疙飞绢 荐沥

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX捞亥飘 甘 况橇力茄 - 疙飞绢 眠啊
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/甘捞悼力茄"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /甘捞悼力茄 [MapIndex] - 秦寸 甘狼 况橇 力茄阑 汲沥窃"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]甘狼 况橇 力茄捞 汲沥 登菌嚼聪促."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]甘狼 况橇 力茄捞 秦力 登菌嚼聪促."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]绰 倾侩窍瘤 臼绰 甘锅龋涝聪促."
// end 2012-11-29 by jhseol, OX捞亥飘 甘 况橇力茄 - 疙飞绢 眠啊

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





