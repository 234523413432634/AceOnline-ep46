// 2005-04-28 by cmkwon


#ifndef _STRING_DEFINE_COMMON_H_
#define _STRING_DEFINE_COMMON_H_

///////////////////////////////////////////////////////////////////////////////
// 1 - FieldServer?? ???? 命令語
	#define STRCMD_CS_COMMAND_MENT_0					"/コメント"
	#define STRCMD_CS_COMMAND_MENT_1					"/コメント"
	#define STRCMD_CS_COMMAND_MENT_2					"/ment"
	#define STRCMD_CS_COMMAND_MENT_HELP					"format: /コメント [|String] - ｷｬﾗｸﾀ-ｺﾒﾝﾄ設定"
	#define STRCMD_CS_COMMAND_MOVE						"/移動"
	#define STRCMD_CS_COMMAND_MOVE_1					"/move"
	#define STRCMD_CS_COMMAND_MOVE_HELP					"format: /移動 [MapIndex] [|ChannelIndex] - 該当 ﾏｯﾌﾟﾁｬﾝﾈﾙに移動"
	#define STRCMD_CS_COMMAND_COORDINATE				"/座標"
	#define STRCMD_CS_COMMAND_COORDINATE_1				"/coordinate"
	#define STRCMD_CS_COMMAND_COORDINATE_HELP			"format: /座標 [X] [Y] - 現在ﾏｯﾌﾟの該当座標に移動"
	#define STRCMD_CS_COMMAND_LIST						"/リスト"
	#define STRCMD_CS_COMMAND_LIST_1					"/list"
	#define STRCMD_CS_COMMAND_LIST_HELP					"format: /リスト - 現在ﾏｯﾌﾟのﾌﾟﾚｲﾔ-ﾘｽﾄを出力 (最大20人)"
	#define STRCMD_CS_COMMAND_USERSEND					"/キャラ移動"
	#define STRCMD_CS_COMMAND_USERSEND_1				"/senduser"
	#define STRCMD_CS_COMMAND_USERSEND_HELP				"format: /キャラ移動 [character name] [map name] - 該当ｷｬﾗｸﾀ-を指定したﾏｯﾌﾟに移動"
	#define STRCMD_CS_COMMAND_INFObyNAME				"/情報"
	#define STRCMD_CS_COMMAND_INFObyNAME_1				"/info"
	#define STRCMD_CS_COMMAND_INFObyNAME_HELP			"format: /情報 [monster name|item name] - 名前に該当文字が含まれているﾓﾝｽﾀ-やｱｲﾃﾑの情報を出力"
	#define STRCMD_CS_COMMAND_QUESTINFO					"/ﾐｯｼｮﾝ"
	#define STRCMD_CS_COMMAND_QUESTINFO_1				"/quest"
	#define STRCMD_CS_COMMAND_QUESTINFO_HELP			"format: /ﾐｯｼｮﾝ - ｷｬﾗｸﾀ-のﾐｯｼｮﾝ情報を出力"
	#define STRCMD_CS_COMMAND_QUESTDEL					"/ﾐｯｼｮﾝ消去"
	#define STRCMD_CS_COMMAND_QUESTDEL_1				"/delQuest"
	#define STRCMD_CS_COMMAND_QUESTDEL_HELP				"format: /ﾐｯｼｮﾝ消去 [ﾐｯｼｮﾝ番号]"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND			"/種類"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_1			"/itemKind"
	#define STRCMD_CS_COMMAND_ITEMINFObyKIND_HELP		"format: /種類 [|item kind(0〜53)] - 該当種類のｱｲﾃﾑを出力"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND			"/種類ｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_1		"/insertItemKind"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyKIND_HELP		"format: /種類ｱｲﾃﾑ[item kind(0〜53)] - 該当種類のｱｲﾃﾑを追加"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE		"/範囲ｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_1	"/insertItemNumRange"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUMRANGE_HELP	"format: /範囲ｱｲﾃﾑ[from itemnum] 〜 [to itemnum] - 該当ｱｲﾃﾑを追加"
	#define STRCMD_CS_COMMAND_STATINIT					"/ｽﾃ-ﾀｽ初期化"
	#define STRCMD_CS_COMMAND_STATINIT_1				"/ｽﾃ-ﾀｽ初期化"
	#define STRCMD_CS_COMMAND_STATINIT_2				"/initStatus"
	#define STRCMD_CS_COMMAND_STATINIT_HELP				"format: /ｽﾃ-ﾀｽ初期化 [|CharacterName]- 全体ｽﾃ-ﾀｽ初期化"
	#define STRCMD_CS_COMMAND_PARTYINFO					"/編隊"
	#define STRCMD_CS_COMMAND_PARTYINFO_1				"/partyInfo"
	#define STRCMD_CS_COMMAND_PARTYINFO_HELP			"format: /編隊 - 編隊情報を出力"
	#define STRCMD_CS_COMMAND_GAMETIME					"/時間"
	#define STRCMD_CS_COMMAND_GAMETIME_1				"/Time"
	#define STRCMD_CS_COMMAND_GAMETIME_HELP				"format: /時間 [|加算時間(0〜23)] - 現在時間を変更(自分の時間のみ変更される)"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_0				"/ストリング"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_1				"/ストリング"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_2				"/string"
	#define STRCMD_CS_COMMAND_STRINGLEVEL_HELP			"format: /ストリング [0〜5] - ﾃﾞﾊﾞｯｸﾒｯｾ-ｼﾞを出力するlevelを決定"
	#define STRCMD_CS_COMMAND_MONSUMMON					"/召喚"
	#define STRCMD_CS_COMMAND_MONSUMMON_1				"/summon"
	#define STRCMD_CS_COMMAND_MONSUMMON_HELP			"format: /召喚 [monster number|monster name] [# of monsters] - ﾓﾝｽﾀ-を 召喚(ﾓﾝｽﾀ-の名前にｽﾍﾟ-ｽがある場合はｽﾍﾟ-ｽの代わりに「_」(ｱﾝﾀﾞ-ﾊﾞ-)を入力)"
	#define STRCMD_CS_COMMAND_SKILLALL					"/全スキル"
	#define STRCMD_CS_COMMAND_SKILLALL_1				"/allSkill"
	#define STRCMD_CS_COMMAND_SKILLALL_HELP				"format: /全スキル [level] - 該当の全てのスキルを挿入"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL				"/全ｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_1			"/allIte"
	#define STRCMD_CS_COMMAND_ITEMINSERTALL_HELP		"format: /全ｱｲﾃﾑ - 該当する全てのｱｲﾃﾑを挿入、スキルとCountableｱｲﾃﾑを除外"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON			"/全武器"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_1		"/allWeapon"
	#define STRCMD_CS_COMMAND_ITEMINSERTWEAPON_HELP		"format: /全武器 - 該当ギアの全ての武器を追加"
	#define STRCMD_CS_COMMAND_ITEMDELALL_0				"/全ｱｲﾃﾑを捨てる"
	#define STRCMD_CS_COMMAND_ITEMDELALL_1				"/全ｱｲﾃﾑを捨てる"
	#define STRCMD_CS_COMMAND_ITEMDELALL_2				"/delAllItem"
	#define STRCMD_CS_COMMAND_ITEMDELALL_HELP			"format: /全ｱｲﾃﾑを捨てる- 該当の全ての装備不可ｱｲﾃﾑを捨てる。 (スキル除外)"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM		"/ｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_1		"/item"
	#define STRCMD_CS_COMMAND_ITEMINSERTbyITEMNUM_HELP	"format: /ｱｲﾃﾑ [item number] [# of items] - ｱｲﾃﾑを取得する。取得数[# of items]を入力しない場合、1個だけ取得。"
	#define STRCMD_CS_COMMAND_ITEMDROP					"/ドロップ"
	#define STRCMD_CS_COMMAND_ITEMDROP_1				"/dropItem"
	#define STRCMD_CS_COMMAND_ITEMDROP_HELP				"format: /ドロップ [item number] [|# of items] - ｱｲﾃﾑをドロップ"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL			"/ｻ-ﾊﾞ"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_1			"/server"
	#define STRCMD_CS_COMMAND_USERSINFOTOTAL_HELP		"format: /ｻ-ﾊﾞ - ｻ-ﾊﾞの情報を出力"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP			"/ｻ-ﾊﾞﾏｯﾌﾟ"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_1			"/serverMap"
	#define STRCMD_CS_COMMAND_USERSINFOperMAP_HELP		"format: /ｻ-ﾊﾞﾏｯﾌﾟ - 全てのﾏｯﾌﾟの情報を出力"
	#define STRCMD_CS_COMMAND_CHANNELINFO				"/ﾁｬﾝﾈﾙ"
	#define STRCMD_CS_COMMAND_CHANNELINFO_1				"/channelInfo"
	#define STRCMD_CS_COMMAND_CHANNELINFO_HELP			"format: /ﾁｬﾝﾈﾙ - 現在ﾏｯﾌﾟのﾁｬﾝﾈﾙ情報を出力"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG				"/DBG"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_1			"/dbg"
	#define STRCMD_CS_COMMAND_DEBUGPRINTDBG_HELP		"format: /DBG - テスト用"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF			"/testf"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMF_HELP		"format: /testf [Param1] [Param2] [Param3]"
	#define STRCMD_CS_COMMAND_BULLETCHARGE				"/銃弾"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_1			"/chargeBullet"
	#define STRCMD_CS_COMMAND_BULLETCHARGE_HELP			"format: /銃弾 [|1型銃弾数] [|2型銃弾数] - 銃弾を補給"
	#define STRCMD_CS_COMMAND_REPAIRALL					"/全回復"
	#define STRCMD_CS_COMMAND_REPAIRALL_1				"/repairAll"
	#define STRCMD_CS_COMMAND_REPAIRALL_HELP			"format: /全回復 [|character name] - HP, UTC, FUELを 100% 回復する、[character name]が入力されていない場合、自分を回復"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM				"/各種減少"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_1			"/repairParam"
	#define STRCMD_CS_COMMAND_REPAIRbyPARAM_HELP		"format: /各種減少 [|減少値%] [|character name] - HP, UTC, FUELを [減少値%]にする、[減少値%]の入力がない場合は50%、 [character name]が入力されていない場合は自分自身を減少。"
	#define STRCMD_CS_COMMAND_USERNORMALIZE				"/一般"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_1			"/normal"
	#define STRCMD_CS_COMMAND_USERNORMALIZE_HELP		"format: /一般 -運営者ｹﾞ-ﾑﾏｽﾀ-ｱｶｳﾝﾄでログインした場合、一般アカウントで引き替え（機械翻訳）"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE			"/特権"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_1			"/specialize"
	#define STRCMD_CS_COMMAND_USERSPECIALIZE_HELP		"format: /特権 -運営者やｹﾞ-ﾑﾏｽﾀ-ｱｶｳﾝﾄでログインした場合、一般アカウントまたは特殊アカウントで引き替え（機械翻訳）"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY			"/無敵"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_1		"/invincible"
	#define STRCMD_CS_COMMAND_USERINVINCIBILITY_HELP	"format: /無敵- 運営者やｹﾞ-ﾑﾏｽﾀ-ｱｶｳﾝﾄの場合、ﾀﾞﾒ-ｼﾞを受けない"
	#define STRCMD_CS_COMMAND_POWERUP					"/士気"
	#define STRCMD_CS_COMMAND_POWERUP_1					"/powerUp"
	#define STRCMD_CS_COMMAND_POWERUP_HELP				"format: /士気 [攻撃力 増加量(%%)]"
	#define STRCMD_CS_COMMAND_VARIABLESET				"/変数"
	#define STRCMD_CS_COMMAND_VARIABLESET_1				"/setVariable"
	#define STRCMD_CS_COMMAND_VARIABLESET_HELP			"format: /変数 [変数値] - (一般)変数 調整"
	#define STRCMD_CS_COMMAND_LEVELSET					"/レベル"
	#define STRCMD_CS_COMMAND_LEVELSET_1				"/level"
	#define STRCMD_CS_COMMAND_LEVELSET_HELP				"format: /レベル [|level] [|percentage of exp] [|character name] - レベルを調整する"


    #define STRCMD_CS_COMMAND_PARTNERLEVELSET		"/ﾊﾟ-ﾄﾅ-レベル"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_1		"/partnerlevel"
    #define STRCMD_CS_COMMAND_PARTNERLEVELSET_HELP		"format: /ﾊﾟ-ﾄﾅ-レベル [|level] [|percentage of exp] - ﾊﾟ-ﾄﾅ-のレベル調整"


	#define STRCMD_CS_COMMAND_USERINVISIABLE			"/透明"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_1			"/invisible"
	#define STRCMD_CS_COMMAND_USERINVISIABLE_HELP		"format: /透明 - 自分がほかのｷｬﾗｸﾀ-に見えない"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_0			"/messagef"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_1			"/msgf"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGF_HELP		"format: /msgf - テスト用"
	#define STRCMD_CS_COMMAND_GAMEEVENT					"/イベント"
	#define STRCMD_CS_COMMAND_GAMEEVENT_1				"/event"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXP			"経験値"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1SPI			"SPI"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1EXPR			"経験値復旧"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1ITEM			"ｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P1RARE			"ﾚｱｱｲﾃﾑ"
	#define STRCMD_CS_COMMAND_GAMEEVENT_P2END			"終了"
	#define STRCMD_CS_COMMAND_GAMEEVENT_HELP			"format: /イベント [経験値｜SPI｜経験値復旧｜ｱｲﾃﾑ｜ﾚｱｱｲﾃﾑ｜戦争ﾎﾟｲﾝﾄ（WP）] [|倍数(%%f)|終了] [時間(単位:分)] [|勢力(255:ALL,1:Normal,2:VCN,4:ANI)]- イベント 設定,解除"
	#define STRCMD_CS_COMMAND_PREMEUM					"/ﾌﾟﾚﾐｱﾑ"
	#define STRCMD_CS_COMMAND_PREMEUM_1					"/premium"
	#define STRCMD_CS_COMMAND_PREMEUM_PNORMAL			"一般"
	#define STRCMD_CS_COMMAND_PREMEUM_PSUPER			"ｽ-ﾊﾟ-"
	#define STRCMD_CS_COMMAND_PREMEUM_PUPGRADE			"ｱｯﾌﾟｸﾞﾚ-ﾄﾞ"
	#define STRCMD_CS_COMMAND_PREMEUM_PEND				"終了"
	#define STRCMD_CS_COMMAND_PREMEUM_HELP				"format: /ﾌﾟﾚﾐｱﾑ [一般|ｽ-ﾊﾟ-|ｱｯﾌﾟｸﾞﾚ-ﾄﾞ|終了]"
// 2008-02-14 by cmkwon, 都市占領戦 命令語 ??
// 	#define STRCMD_CS_COMMAND_CITYWAR					"/都市占領戦"
// 	#define STRCMD_CS_COMMAND_CITYWAR_1					"/citywar"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PSTART			"開始"
// 	#define STRCMD_CS_COMMAND_CITYWAR_PEND				"終了"
// 	#define STRCMD_CS_COMMAND_CITYWAR_HELP				"format: /都市占領戦 [開始|終了]"
	#define STRCMD_CS_COMMAND_STEALTH					"/ステルス"
	#define STRCMD_CS_COMMAND_STEALTH_1					"/stealth"
	#define STRCMD_CS_COMMAND_STEALTH_HELP				"format: /ステルス - 先制攻撃ﾓﾝｽﾀ-が先攻しない"
	#define STRCMD_CS_COMMAND_RETURNALL					"/全て帰還"
	#define STRCMD_CS_COMMAND_RETURNALL_1				"/returnAll"
	#define STRCMD_CS_COMMAND_RETURNALL_HELP			"format: /全て帰還 - 該当 勢力別 都市ﾏｯﾌﾟに移動する"
// start 2011-10-28 by hskim, EP4 [ﾆｮｸｮｰﾅ ｽﾃｽｺﾅﾛ] - ﾅｩｸｮｽｺﾅｻ ｽﾃｽｺﾅﾛ
#define STRCMD_CS_COMMAND_RESETTRIGGER				"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_1			"/resetTrigger"
#define STRCMD_CS_COMMAND_RESETTRIGGER_HELP			"format: /resetTrigger [TriggerNumber] - Off the trigger and default the event."
// end 2011-10-28 by hskim, EP4 [ﾆｮｸｮｰﾅ ｽﾃｽｺﾅﾛ] - ﾅｩｸｮｽｺﾅｻ ｽﾃｽｺﾅﾛ


// start 2011-06-22 by hskim, ｻ郛ｳ ｼｭｹ・ｹ戝・
	#define STRCMD_CS_COMMAND_SERVERINFO				"/getserverinfo"		// ｼｭｹ・ﾁ､ｺｸ ｺｸｱ・
// end 2011-06-22 by hskim, ｻ郛ｳ ｼｭｹ・ｹ戝・
			   
// start 2012-02-13 by hskim, ｸ?ｽｺﾅﾍ ｾﾆﾀﾌﾅﾛ ｵ蠍・ﾅﾗｽｺﾆｮ ｸ?ﾓﾉｾ・
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM			"/testmonsterdrop"		// ｼｭｹ・ﾁ､ｺｸ ｺｸｱ・
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_1		"/testmonsterdrop"
#define STRCMD_CS_COMMAND_TEST_MONSTER_DROPITEM_HELP	"format: /testmonsterdrop [monster number] [test numbers : (1~100000)] - Monsters that drop items at the show simulation. (A very large load on the server gives an absolute Sacred Shield Do not use)"
// end 2012-02-13 by hskim, ｸ?ｽｺﾅﾍ ｾﾆﾀﾌﾅﾛ ｵ蠍・ﾅﾗｽｺﾆｮ ｸ?ﾓﾉｾ・

// 2007-10-30 by cmkwon, ｼｼｷﾂｺｰ ﾇﾘﾇﾇｾﾆｿ・ﾀﾌｺ･ﾆｮ ｱｸ?E- ｸ?ﾓﾉｾ・?E?ｼ?ﾁ､ｵﾊ ｾﾆｷ｡ｿ｡ｼｭ ｴﾙｽﾃ ﾁ､ﾀﾇ ﾇﾔ
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHourイベント"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"開始"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"終了"
//	#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHourイベント [開始|終了] [進行時間(単位:分)]"

// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - IMServer?? ???? 命令語, ??? ??? ??? 命令語? ??? ???
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI			"/testi"
	#define STRCMD_CS_COMMAND_DEBUGSETPARAMI_HELP		"format: /testi - IMServer ????"
	#define STRCMD_CS_COMMAND_WHO						"/誰"
	#define STRCMD_CS_COMMAND_WHO_1						"/who"
	#define STRCMD_CS_COMMAND_WHO_HELP					"format: /誰 [|# of users] - 現在 ｻ-ﾊﾞにあるﾕ-ｻﾞ-を全て出力 (ﾏｯﾌﾟと関係ない)"
	#define STRCMD_CS_COMMAND_REGISTERADMIN				"/運営登録"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_1			"/registerAdmin"
	#define STRCMD_CS_COMMAND_REGISTERADMIN_HELP		"format: /運営登録 - 運営者に特定イベント発生時のﾒｯｾ-ｼﾞを受けるようにｻ-ﾊﾞに登録する"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_0			"/messagei"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_1			"/msgi"
	#define STRCMD_CS_COMMAND_DEBUGPRINTMSGI_HELP		"format: /msgi - クライアントとIM ｻ-ﾊﾞとの間のプロトコルを全て出力する"
	#define STRCMD_CS_COMMAND_SERVERDOWN				"/ｻ-ﾊﾞ-ﾀﾞｳﾝ"
	#define STRCMD_CS_COMMAND_SERVERDOWN_1				"/serverDown"
	#define STRCMD_CS_COMMAND_SERVERDOWN_HELP			"format: /ｻ-ﾊﾞ-ﾀﾞｳﾝ [認証数字] - ｻ-ﾊﾞを 終了させる"
	#define STRCMD_CS_COMMAND_WHOAREYOU					"/誰2"
	#define STRCMD_CS_COMMAND_WHOAREYOU_1				"/whoareYou"
	#define STRCMD_CS_COMMAND_WHOAREYOU_HELP			"format: /誰2 [character name]"
	#define STRCMD_CS_COMMAND_GOUSER					"/行く"
	#define STRCMD_CS_COMMAND_GOUSER_1					"/go"
	#define STRCMD_CS_COMMAND_GOUSER_HELP				"format: /行く [character name] - 該当 ｷｬﾗｸﾀ-の場所に移動する"
	#define STRCMD_CS_COMMAND_COMEON					"/呼ぶ"
	#define STRCMD_CS_COMMAND_COMEON_1					"/comeon"
	#define STRCMD_CS_COMMAND_COMEON_HELP				"format: /呼ぶ [character name] - 該当ｷｬﾗｸﾀ-を呼ぶ"
	#define STRCMD_CS_COMMAND_GUILDCOMEON				"/旅団呼ぶ"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_1				"/comeonGuild"
	#define STRCMD_CS_COMMAND_GUILDCOMEON_HELP			"format: /旅団呼ぶ [旅団名] - 該当 旅団ﾒﾝﾊﾞ-を全て呼ぶ"
	#define STRCMD_CS_COMMAND_GUILDSEND					"/旅団送る"
	#define STRCMD_CS_COMMAND_GUILDSEND_1				"/sendGuild"
	#define STRCMD_CS_COMMAND_GUILDSEND_HELP			"format: /旅団送る [旅団名] [map name] - 該当 旅団ﾒﾝﾊﾞ-を ﾏｯﾌﾟに移動させる"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG				"/ささやき"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_1			"/whisperChat"
	#define STRCMD_CS_COMMAND_CHATPTOPFLAG_HELP			"format: /ささやき - ささやきをブロックや解除する（On/Off）"
	#define STRCMD_CS_COMMAND_GUILDINFO					"/旅団"
	#define STRCMD_CS_COMMAND_GUILDINFO_1				"/guildInfo"
	#define STRCMD_CS_COMMAND_GUILDINFO_HELP			"format: /旅団 - 旅団 情報 出力"
	#define STRCMD_CS_COMMAND_WEATHERSET				"/天気"
	#define STRCMD_CS_COMMAND_WEATHERSET_1				"/weather"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1NORMAL		"基本"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FINE			"晴れ"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1RAIN			"雨"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1SNOW			"雪"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1CLOUDY		"曇り"
	#define STRCMD_CS_COMMAND_WEATHERSET_P1FOG			"霧"
	#define STRCMD_CS_COMMAND_WEATHERSET_P2ALL			"全体"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3ON			"on"
	#define STRCMD_CS_COMMAND_WEATHERSET_P3OFF			"off"
	#define STRCMD_CS_COMMAND_WEATHERSET_HELP			"format: /天気 [基?|晴れ|雨|雪|曇り|霧] [全体|ﾏｯﾌﾟ名] [on|off] - 天気調整"
	#define STRCMD_CS_COMMAND_CHATFORBID				"/ﾁｬｯﾄﾌﾞﾛｯｸ"
	#define STRCMD_CS_COMMAND_CHATFORBID_1				"/forbidChat"
	#define STRCMD_CS_COMMAND_CHATFORBID_HELP			"format: /ﾁｬｯﾄﾌﾞﾛｯｸ [character name] [時間(分)] - ﾁｬｯﾄをﾌﾞﾛｯｸする"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE			"/ﾁｬｯﾄﾌﾞﾛｯｸ解除"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_1		"/releaseChat"
	#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_HELP	"format: /ﾁｬｯﾄﾌﾞﾛｯｸ解除 [character name] - ﾁｬｯﾄﾌﾞﾛｯｸを解除する"
	#define STRCMD_CS_COMMAND_COMMANDLIST_0				"/?"
	#define STRCMD_CS_COMMAND_COMMANDLIST_1				"/help"
	#define STRCMD_CS_COMMAND_COMMANDLIST_2				"/命令語"
	#define STRCMD_CS_COMMAND_COMMANDLIST_HELP			"format: /? - 命令語リストを出力"

	// 2005-07-20 by cmkwon
	#define STRCMD_CS_COMMAND_BONUSSTAT_0				"/BonusStat"
	#define STRCMD_CS_COMMAND_BONUSSTAT_1				"/ﾎﾞ-ﾅｽｽﾃ-ﾀｽ"
	#define STRCMD_CS_COMMAND_BONUSSTAT_2				"/ﾎﾞ-ﾅｽｽﾃ-ﾀｽ"
	#define STRCMD_CS_COMMAND_BONUSSTAT_HELP			"format: /BonusStat [Bonus Counts] [|character name] - ﾎﾞｰﾅｽｽﾃｰﾀｽｱｯﾌﾟ"

// 2_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 3 - AtumMonitor?? ???? 命令語, ??? ??? ??? 命令語? ??? ???
	#define STRCMD_CS_COMMAND_PASSWORDSET				"/ﾊﾟｽﾜ-ﾄﾞ設定"
	#define STRCMD_CS_COMMAND_PASSWORDSET_1				"/setPassword"
	#define STRCMD_CS_COMMAND_PASSWORDSET_HELP			"format: /ﾊﾟｽﾜ-ﾄﾞ設定 [AccountName] [Password]"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK			"/ﾊﾟｽﾜ-ﾄﾞ復旧"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_1		"/rollbackPassword"
	#define STRCMD_CS_COMMAND_PASSWORDROLLBACK_HELP		"format: /ﾊﾟｽﾜ-ﾄﾞ復旧 [AccountName]"
	#define STRCMD_CS_COMMAND_PASSWORDLIST				"/ﾊﾟｽﾜ-ﾄﾞﾘｽﾄ"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_1			"/passwordList"
	#define STRCMD_CS_COMMAND_PASSWORDLIST_HELP			"format: /ﾊﾟｽﾜ-ﾄﾞﾘｽﾄ"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT			"/ﾊﾟｽﾜ-ﾄﾞ化"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_1			"/encrypt"
	#define STRCMD_CS_COMMAND_PASSWORDENCRYPT_HELP		"format: /ﾊﾟｽﾜ-ﾄﾞ化 [ﾊﾟｽﾜ-ﾄﾞ化するストリング]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK				"/アカウントブロック"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCK_1			"/blockAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKT_HELP		"format: /アカウントブロック [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE		"/アカウントブロック解除"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_1		"/releaseAccount"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKRELEASE_HELP	"format: /アカウントブロック解除 [AccountName]"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST			"/ブロックされたアカウント"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_1		"/blockedList"
	#define STRCMD_CS_COMMAND_ACCOUNTBLOCKLIST_HELP		"format: /ブロックされたアカウント"
// 3_end
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 4 - CommonGameServer
	#define STRCMD_CS_COMMON_DB_0000 "Mｹﾞ-ﾑｻ-ﾊﾞ専用!!!!\r\n"
	#define STRCMD_CS_COMMON_DB_0001 "ｻ-ﾊﾞﾛｸﾞｲﾝIDを入力してください"
	#define STRCMD_CS_COMMON_DB_0002 "ｻ-ﾊﾞﾛｸﾞｲﾝPWを入力してください"
	#define STRCMD_CS_COMMON_DB_0003 "DBログインIDを入力してください。"
	#define STRCMD_CS_COMMON_DB_0004 "DBログインPWを入力してください。"

	#define STRCMD_CS_COMMON_MAP_0000 "ﾊ-ﾄﾞｺ-ﾃﾞｨﾝｸﾞ部分: 0101ﾏｯﾌﾟで1番ﾜ-ﾌﾟﾀ-ｹﾞｯﾄを無視、ﾏｯﾌﾟｴﾃﾞｨﾀか除去\r\n"
	#define STRCMD_CS_COMMON_MAP_0001 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0002 "ﾊ-ﾄﾞｺ-ﾃﾞｨﾝｸﾞ部分: 0101ﾏｯﾌﾟで1番ﾜ-ﾌﾟﾀ-ｹﾞｯﾄを無視、ﾏｯﾌﾟｴﾃﾞｨﾀか除去\r\n "
	#define STRCMD_CS_COMMON_MAP_0003 "MAP: %04d, m_DefaltWarpTargetIndex: %d\r\n"
	#define STRCMD_CS_COMMON_MAP_0004 "    ObjMon ==> ObjNum[%8d] EvType[%d] EvIndex[%3d] 召喚ﾓﾝｽﾀ-[%8d] 召喚時間[%6d秒]、 Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0005 "[ERROR] ObjectMonster EventParam1 Index 重複 Error ==> ObjectNum[%8d] EventType[%d] EventIndex[%3d] 召喚 ﾓﾝｽﾀ-[%8d] 召喚時間[%6d秒], Pos(%4d, %4d, %4d)\r\n"
	#define STRCMD_CS_COMMON_MAP_0006 "Tatal Monster Count:[%4d]<==ｵﾌﾞｼﾞｪｸﾄﾓﾝｽﾀ-を含む\r\n"

	#define STRCMD_CS_COMMON_DOWNLOAD_0000 "ﾀﾞｳﾝﾛ-ﾄﾞﾌｧｲﾙが見つかりません。"
	#define STRCMD_CS_COMMON_DOWNLOAD_0001 "ﾌｧｲﾙ作成ｴﾗ-です。"
	#define STRCMD_CS_COMMON_DOWNLOAD_0002 "ﾀﾞｳﾝﾛ-ﾄﾞﾌｧｲﾙの読み込みｴﾗ-です。"

	#define STRCMD_CS_COMMON_DATETIME_0000 "%d日%d時間%d分%d秒"

	#define STRCMD_CS_COMMON_RACE_NORMAL		"一般"
	#define STRCMD_CS_COMMON_RACE_BATTALUS		"ﾊﾞﾀﾗｽ"
	#define STRCMD_CS_COMMON_RACE_DECA			"デカ"
	#define STRCMD_CS_COMMON_RACE_PHILON		"パイロン"
	#define STRCMD_CS_COMMON_RACE_SHARRINE		"シュリン"
	#define STRCMD_CS_COMMON_RACE_MONSTER1		"予備"
	#define STRCMD_CS_COMMON_RACE_MONSTER2		"予備"
	#define STRCMD_CS_COMMON_RACE_NPC			"NPC"
	#define STRCMD_CS_COMMON_RACE_OPERATION		"管理者"
	#define STRCMD_CS_COMMON_RACE_GAMEMASTER	"GM"
	#define STRCMD_CS_COMMON_RACE_MONITOR		"ﾓﾆﾀ-"
	#define STRCMD_CS_COMMON_RACE_GUEST			"ゲスト"
	#define STRCMD_CS_COMMON_RACE_DEMO			"デモ用"
	#define STRCMD_CS_COMMON_RACE_ALL			"全種族"
	#define STRCMD_CS_COMMON_RACE_UNKNOWN		"不明な種族"

	#define STRCMD_CS_COMMON_MAPNAME_UNKNOWN	"名前なし"

	#define STRCMD_CS_STATUS_BEGINNER_AIRMAN		"ﾄﾚ-ﾆﾝｸﾞｴｱ-ﾏﾝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_AIRMAN		"3rdｴｱ-ﾏﾝ"
	#define STRCMD_CS_STATUS_2ND_CLASS_AIRMAN		"2ndｴｱ-ﾏﾝ"
	#define STRCMD_CS_STATUS_1ST_CLASS_AIRMAN		"1stｴｱ-ﾏﾝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_WINGMAN		"3rdｳｲﾝｸﾞﾏﾝ"
	#define STRCMD_CS_STATUS_2ND_CLASS_WINGMAN		"2ndｳｲﾝｸﾞﾏﾝ"
	#define STRCMD_CS_STATUS_1ST_CLASS_WINGMAN		"1stｳｲﾝｸﾞﾏﾝ"
	#define STRCMD_CS_STATUS_3RD_CLASS_LEADER		"3rdﾘ-ﾀﾞ-"
	#define STRCMD_CS_STATUS_2ND_CLASS_LEADER		"2ndﾘ-ﾀﾞ-"
	#define STRCMD_CS_STATUS_1ST_CLASS_LEADER		"1stﾘ-ﾀﾞ-"
	#define STRCMD_CS_STATUS_3RD_CLASS_ACE			"3rdｴ-ｽ"
	#define STRCMD_CS_STATUS_2ND_CLASS_ACE			"2ndｴ-ｽ"
	#define STRCMD_CS_STATUS_1ST_CLASS_ACE			"1stｴ-ｽ"
	#define STRCMD_CS_STATUS_COPPER_CLASS_GENERAL	"准将"
	#define STRCMD_CS_STATUS_SILVER_CLASS_GENERAL	"少将"
	#define STRCMD_CS_STATUS_GOLD_CLASS_GENERAL		"中将"
	#define STRCMD_CS_STATUS_MASTER_GENERAL			"大将"

	#define STRCMD_CS_ITEMKIND_AUTOMATIC			"ｵ-ﾄﾏﾁｯｸ類"
	#define STRCMD_CS_ITEMKIND_VULCAN				"バルカン類"
	#define STRCMD_CS_ITEMKIND_DUALIST				"デュアルリスト類"		// 2005-08-01 by hblee : GRENADE -> DUALIST に 変更.
	#define STRCMD_CS_ITEMKIND_CANNON				"キャノン類"
	#define STRCMD_CS_ITEMKIND_RIFLE				"ライフル類"
	#define STRCMD_CS_ITEMKIND_GATLING				"ガトリング類"
	#define STRCMD_CS_ITEMKIND_LAUNCHER				"ﾗﾝﾁｬ-類"
	#define STRCMD_CS_ITEMKIND_MASSDRIVE			"ﾏｽﾄﾞﾗｲﾌﾞ類"
	#define STRCMD_CS_ITEMKIND_ROCKET				"ロケット類"
	#define STRCMD_CS_ITEMKIND_MISSILE				"ﾐｻｲﾙ類"
	#define STRCMD_CS_ITEMKIND_BUNDLE				"バンドル類"

	#define STRCMD_CS_ITEMKIND_MINE					"ﾏｲﾝ類"
	#define STRCMD_CS_ITEMKIND_SHIELD				"ｼ-ﾙﾄﾞ類"
	#define STRCMD_CS_ITEMKIND_DUMMY				"ﾀﾞﾐ-類"
	#define STRCMD_CS_ITEMKIND_FIXER				"ﾋﾟｸｻ-類"
	#define STRCMD_CS_ITEMKIND_DECOY				"デコイ類"
	#define STRCMD_CS_ITEMKIND_DEFENSE				"ｱ-ﾏ-類"
	#define STRCMD_CS_ITEMKIND_SUPPORT				"エンジン類"
	#define STRCMD_CS_ITEMKIND_ENERGY				"ｴﾈﾙｷﾞ-類"
	#define STRCMD_CS_ITEMKIND_INGOT				"鉱石類"
	#define STRCMD_CS_ITEMKIND_CARD					"一般ｶ-ﾄﾞ類"
	#define STRCMD_CS_ITEMKIND_ENCHANT				"ｴﾝﾁｬﾝﾄｶ-ﾄﾞ類"
	#define STRCMD_CS_ITEMKIND_TANK					"ﾀﾝｸ類"
	#define STRCMD_CS_ITEMKIND_BULLET				"弾丸類"
	#define STRCMD_CS_ITEMKIND_QUEST				"ﾐｯｼｮﾝｱｲﾃﾑ類"
	#define STRCMD_CS_ITEMKIND_RADAR				"ﾚ-ﾀﾞ-類"
	#define STRCMD_CS_ITEMKIND_COMPUTER				"ｺﾝﾋﾟｭ-ﾀ-類"
	#define STRCMD_CS_ITEMKIND_GAMBLE				"ｷﾞｬﾝﾌﾞﾙｶ-ﾄﾞ類"
	#define STRCMD_CS_ITEMKIND_PREVENTION_DELETE_ITEM	"ｴﾝﾁｬﾝﾄ破壊防止ｶ-ﾄﾞ類"
	#define STRCMD_CS_ITEMKIND_BLASTER				"ﾌﾞﾗｽﾀ-類"	// 2005-08-01 by hblee : ﾌﾞﾗｽﾀ-類追加.
	#define STRCMD_CS_ITEMKIND_RAILGUN				"ﾚ-ﾙｶﾞﾝ類"		// 2005-08-01 by hblee : ﾚ-ﾙｶﾞﾝ類追加.
	#define STRCMD_CS_ITEMKIND_ACCESSORY_UNLIMITED	"無制限アクセサリ"		// 2006-03-17 by cmkwon, 使用時間が <永久>の ｱｸｾｻﾘ ｱｲﾃﾑ
	#define STRCMD_CS_ITEMKIND_ACCESSORY_TIMELIMIT	"時間制限アクセサリ"		// 2006-03-17 by cmkwon, 時間制限のあるｱｸｾｻﾘｱｲﾃﾑ
	#define STRCMD_CS_ITEMKIND_ALL_WEAPON			"全武器全武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_ALL	"メイン武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_1		"銃弾型メイン武器"
	#define STRCMD_CS_ITEMKIND_PRIMARY_WEAPON_2		"燃料型メイン武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_ALL	"サブ武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_1	"弾頭型サブ武器"
	#define STRCMD_CS_ITEMKIND_SECONDARY_WEAPON_2	"防御型サブ武器"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTACK			"攻撃スキル"
	#define STRCMD_CS_ITEMKIND_SKILL_DEFENSE		"防御スキル"
	#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT		"補助スキル"
	#define STRCMD_CS_ITEMKIND_SKILL_ATTRIBUTE		"属性スキル"
	#define STRCMD_CS_ITEMKIND_FOR_MON_PRIMARY		"1型ﾓﾝｽﾀ-用アイテ?"
	#define STRCMD_CS_ITEMKIND_FOR_MON_GUN			"ﾓﾝｽﾀ-ﾏｼﾝｶﾞﾝ(1-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BEAM			"ﾓﾝｽﾀ-ビ??類(1-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ALLATTACK	"ﾓﾝｽﾀ-全体攻撃"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SECONDARY	"2型ﾓﾝｽﾀ-用ｱｲﾃﾑ"
	#define STRCMD_CS_ITEMKIND_FOR_MON_ROCKET		"ﾓﾝｽﾀ-ﾛｹｯﾄ(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MISSILE		"ﾓﾝｽﾀ-ﾐｻｲﾙ類(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_BUNDLE		"ﾓﾝｽﾀ-ﾊﾞﾝﾄﾞﾙ類(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_MINE			"ﾓﾝｽﾀ-ﾏｲﾝ類(2-1型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_SHIELD		"ﾓﾝｽﾀ-ｼ-ﾙﾄﾞ類(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DUMMY		"ﾓﾝｽﾀ-ﾀﾞﾐ-類(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIXER		"ﾓﾝｽﾀ-ピクサ?類(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_DECOY		"ﾓﾝｽﾀ-ﾃﾞｺｲ類(2-2型)"
	#define STRCMD_CS_ITEMKIND_FOR_MON_FIRE			"ﾓﾝｽﾀ-ﾌｧｲﾔ-類"
	#define STRCMD_CS_ITEMKIND_FOR_MON_OBJBEAM		"ﾓﾝｽﾀ-衝突可能ﾋﾞ-ﾑ類"
	#define STRCMD_CS_ITEMKIND_FOR_MON_STRAIGHTBOOM	"ﾓﾝｽﾀ-直進爆弾類"
	#define STRCMD_CS_ITEMKIND_UNKNOWN				"不明なｱｲﾃﾑ"

	#define STRCMD_CS_UNITKIND_UNKNOWN				"不明な機体"

	#define STRCMD_CS_STAT_ATTACK_PART				"攻撃"
	#define STRCMD_CS_STAT_DEFENSE_PART				"防御"
	#define STRCMD_CS_STAT_FUEL_PART				"燃料"
	#define STRCMD_CS_STAT_SOUL_PART				"精神"
	#define STRCMD_CS_STAT_SHIELD_PART				"ｼ-ﾙﾄﾞ"
	#define STRCMD_CS_STAT_DODGE_PART				"回避"
	#define STRCMD_CS_STAT_BONUS					"ﾎﾞ-ﾅｽｽﾃ-ﾀｽ"
	#define STRCMD_CS_STAT_ALL_PART					"全ｽﾃ-ﾀｽ"
	#define STRCMD_CS_STAT_UNKNOWN					"不明なｽﾃ-ﾀｽ"

	#define STRCMD_CS_AUTOSTAT_TYPE_FREESTYLE		"自由型"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_ATTACK	"攻撃型"
	#define STRCMD_CS_AUTOSTAT_TYPE_BGEAR_MULTI		"ﾏﾙﾁ型"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_ATTACK	"攻撃型"
	#define STRCMD_CS_AUTOSTAT_TYPE_IGEAR_DODGE		"回避型"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_ATTACK	"攻撃型"
	#define STRCMD_CS_AUTOSTAT_TYPE_AGEAR_SHIELD	"ｼ-ﾙﾄﾞ型"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_DEFENSE	"防御型"
	#define STRCMD_CS_AUTOSTAT_TYPE_MGEAR_SUPPORT	"支援型"
	#define STRCMD_CS_AUTOSTAT_TYPE_UNKNOWN			"UNKNOWN_AUTOSTAT_TYPE"

// 2007-10-30 by cmkwon, 勢力? HappyHour イベント ?? - ???? ?? ?? ?
//	#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"ﾊﾞｲｼﾞｪﾆｭ-一般軍"			// 2005-12-20 by cmkwon
//	#define STRCMD_CS_INFLUENCE_TYPE_VCN			"ﾊﾞｲｼﾞｪﾆｭ-正規軍"
//	#define STRCMD_CS_INFLUENCE_TYPE_ANI			"ｱ-ﾘﾝﾄﾝ正規軍"
	#define STRCMD_CS_INFLUENCE_TYPE_RRP			"ﾊﾞﾀﾗｽ連邦軍"

	#define STRCMD_CS_POS_PROW						"ﾚ-ﾀﾞ-位置(先頭の中央)"
	#define STRCMD_CS_POS_PROWIN					"ｺﾝﾋﾟｭ-ﾀ-(中央の左)"
	#define STRCMD_CS_POS_PROWOUT					"メイン武器(先頭の左)"
	#define STRCMD_CS_POS_WINGIN					"使用しない(中央の右)"
	#define STRCMD_CS_POS_WINGOUT					"サブ武器(先頭の右)"
	#define STRCMD_CS_POS_CENTER					"ｱ-ﾏ-(中央の中央)"
	#define STRCMD_CS_POS_REAR						"エンジン(後尾の中央)"
	    
	// 2010-06-15 by shcho&hslee ?Eﾃｽｺﾅ?
    //#define STRCMD_CS_POS_ATTACHMENT				"付着物(後尾の右-燃料ﾀﾝｸ|ﾄﾞﾗｲﾊﾞ-系列)"
	#define STRCMD_CS_POS_ACCESSORY_UNLIMITED		"付着物(後尾の右-燃料ﾀﾝｸ|ﾄﾞﾗｲﾊﾞ-系列)"

	// 2010-06-15 by shcho&hslee ?Eﾃｽｺﾅ?
	//#define STRCMD_CS_POS_PET						"使用しない(後尾の左)"
	#define STRCMD_CS_POS_ACCESSORY_TIME_LIMIT		"使用しない(後尾の左)"

	#define STRCMD_CS_POS_PET						"ﾊﾟ-ﾄﾅ"

    #define STRCMD_CS_HIDDEN_ITEM				"隠された場所"	
	
	#define STRCMD_CS_POS_INVALID_POSITION			"未確定位置"
	#define STRCMD_CS_POS_ITEMWINDOW_OFFSET			"インベントリ位置"

	// 2005-12-07 by cmkwon
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_0		"/ﾐｯｼｮﾝ完了"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_1		"/QuestCom"
	#define STRCMD_CS_COMMAND_QUESTCOMPLETION_HELP	"format: /ﾐｯｼｮﾝ完了[|QuesIndex] - 進行中ﾐｯｼｮﾝや指定したﾐｯｼｮﾝが完了処理"

	// 2006-02-08 by cmkwon
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_0		"/勢力分布"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_1		"/InflDist"
	#define STRCMD_CS_COMMAND_INFLDITRIBUTION_HELP	"format: /勢力分布"
	#define STRCMD_CS_COMMAND_CHANGEINFL_0			"/勢力変更"
	#define STRCMD_CS_COMMAND_CHANGEINFL_1			"/InflChange"
	#define STRCMD_CS_COMMAND_CHANGEINFL_HELP		"format:/勢力変更 [|1(Normal)|2(BCU)|4(ANI)]"

	// 2006-03-02 by cmkwon
	#define STRCMD_CS_COMMAND_GOMONSTER_0			"/ﾓﾝｽﾀ-に行く"
	#define STRCMD_CS_COMMAND_GOMONSTER_1			"/GoMonster"
	#define STRCMD_CS_COMMAND_GOMONSTER_HELP		"format:/ﾓﾝｽﾀ-に行く [MonsterName|MonsterNumber]"

	//////////////////////////////////////////////////////////////////////////
	// 2008-05-20 by dhjin, EP3 - 旅団 ?? ?? - ?? ?? ??? 移動
	// 2006-03-07 by cmkwon
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"隊員"
//	#define STRCMD_CS_GUILD_RANK_COMMANDER			"旅団長"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1大隊長"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1大隊員"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2大隊長"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2大隊員"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3大隊長"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3大隊員"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4大隊長"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4大隊員"
//	#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5大隊長"
//	#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5大隊員"

	// 2006-04-17 by cmkwon
	#define STRCMD_CS_COMMAND_SIGNBOARD_0			"/電光板"
	#define STRCMD_CS_COMMAND_SIGNBOARD_1			"/Noticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_HELP		"format:/電光板[|持続時間(単位:分)] [お知らせ内容] - 指導者のみ使用可能、電光板にお知らせを追加するかリストを見る"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_0		"/電光板削除"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_1		"/DeleteNoticeboard"
	#define STRCMD_CS_COMMAND_SIGNBOARD_DEL_HELP	"format: /電光板削除[削除するお知らせのインデックス] - 指導者のみ使用可能、電光板の指定したお知らせを削除する"

	// 2006-04-20 by cmkwon
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_LEADER	"勢力戦ﾘ-ﾀﾞ-"
	#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER	"勢力戦副ﾘ-ﾀﾞ-"
	// 2006-04-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_INFLUENCE_BUFF		"勢力支援効果"
	#define STRCMD_CS_ITEMKIND_INFLUENCE_GAMEEVENT	"勢力イベント"

	// 2006-04-24 by cmkwon
	#define STRCMD_CS_COMMAND_CONPOINT_0			"/寄与度"
	#define STRCMD_CS_COMMAND_CONPOINT_1			"/ContributionPoint"
	#define STRCMD_CS_COMMAND_CONPOINT_HELP			"format: /寄与度 [勢力(2:BCU, 4:ANI)] [増加分] ? 指定した勢力の寄与度を増加させる"

	// 2006-05-08 by cmkwon
	#define STRCMD_CS_COMMAND_CALLGM_0				"/CallGM"
	#define STRCMD_CS_COMMAND_CALLGM_1				"/ヘルプ"
	#define STRCMD_CS_COMMAND_CALLGM_2				"/ヘルプ"
	#define STRCMD_CS_COMMAND_CALLGM_HELP			"format: /ヘルプ [相談内容] - GMに相談を申し込みする。"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_0			"/ViewCallGM"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_1			"/ヘルプを見る"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_2			"/ヘルプを見る"
	#define STRCMD_CS_COMMAND_VIEWCALLGM_HELP		"format: /ヘルプを見る[|件数(1〜10)] - GM相談申し込みリストを指定した件数を出力する"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_0			"/BringCallGM"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_1			"/ヘルプを読み込む"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_2			"/ヘルプを読み込む"
	#define STRCMD_CS_COMMAND_BRINGCALLGM_HELP		"format: /ヘルプを読み込む[|件数(1〜10)] - GM相談申し込みリストを指定した件数読み込む (ｻ-ﾊﾞから削除される)"

	// 2006-07-18 by cmkwon
	#define STRCMD_CS_COMMAND_COMEONINFL_0			"/ComeOnInfl"
	#define STRCMD_CS_COMMAND_COMEONINFL_1			"/勢力召喚"
	#define STRCMD_CS_COMMAND_COMEONINFL_2			"/勢力召喚"
// 2008-09-09 by cmkwon, /勢力召喚 命令語 ?? リスト? ??ﾀｲﾌﾟ 追加 - commented
//	#define STRCMD_CS_COMMAND_COMEONINFL_HELP		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [最大人員] [0|最小レベル] [0|最大レベル] [ﾕ-ｻﾞ-に送るﾒｯｾ-ｼﾞ] ? 任意に指定した勢力、指定したレベルのﾕ-ｻﾞ-にｲﾍﾞﾝﾄﾏｯﾌﾟへの移動を要請する"

	// 2006-07-24 by cmkwon
	#define STRCMD_CS_COMMAND_ITEMINMAP_0			"/InsertItemInMap"
	#define STRCMD_CS_COMMAND_ITEMINMAP_1			"/ｱｲﾃﾑﾏｯﾌﾟ"
	#define STRCMD_CS_COMMAND_ITEMINMAP_2			"/ｱｲﾃﾑ追加ﾏｯﾌﾟ"
	#define STRCMD_CS_COMMAND_ITEMINMAP_HELP		"format: /InsertItemInMap [1(Normal)|2(VCN)|4(ANI)|255(All)] [Item Number] [# of items] - 現在ﾏｯﾌﾟの指定した勢力のﾕ-ｻﾞ-に指定したｱｲﾃﾑを支給する"

	// 2006-07-28 by cmkwon
	#define STRCMD_CS_ITEMKIND_COLOR_ITEM			"Color Item"

	// 2006-08-03 by cmkwon, ??? ?? ?? ??? ???
	// ??(Korea):		YYYY-MM-DD HH:MM:SS
	// ??(English):	MM-DD-YYYY HH:MM:SS
	// ???(Vietnam):	DD-MM-YYYY HH:MM:SS
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT(Y, M, D, h, m, s)				"%04d-%02d-%02d %02d:%02d:%02d", Y, M, D, h, m, s
	#define NATIONAL_ATUM_DATE_TIME_STRING_FORMAT_EXCLUDE_SECOND(Y, M, D, h, m)	"%04d-%02d-%02d %02d:%02d", Y, M, D, h, m

	// 2006-08-08 by dhjin, レベル分布
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_0		"/LevelDistribution"		// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_1		"/レベル分布"					// 2006-08-08 by dhjin
	#define STRCMD_CS_COMMAND_DISTRIBUTIONLEVEL_HELP	"format: /レベル分布 - ｹﾞ-ﾑに接続しているﾕ-ｻﾞ-のレベル分布をみる"	// 2006-08-08 by dhjin


	// 2014-03-18 by bckim, ｸｶﾄﾏ ON/OFF
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_0		"/市場"
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_1		"/市場"	
	#define STRCMD_CS_COMMAND_MARKET_ACTIVATION_HELP	"format: /市場 - トレードショップ ON OFF. "
	// End. 2014-03-18 by bckim, ｸｶﾄﾏ ON/OFF

	// 2006-08-10 by cmkwon
	#define STRCMD_CS_ITEMKIND_RANDOMBOX				"幸運の箱"

	// 2006-08-21 by cmkwon
	#define STRCMD_CS_ITEMKIND_MARK						"ﾏ-ｸ"

///////////////////////////////////////////////////////////////////////////////
// 2006-08-24 by cmkwon
// クライアント??? ???? 命令語(Just command for client)
	#define STRCMD_C_COMMAND_CALL						"/ﾎﾞｲｽﾁｬｯﾄ"
	#define STRCMD_C_COMMAND_CALL_HELP					"format: /ﾎﾞｲｽﾁｬｯﾄ [CharacterName] - 指定したｷｬﾗｸﾀ-に 1:1 ﾎﾞｲｽﾁｬｯﾄを 要請する"
	#define STRCMD_C_COMMAND_PARTYCALL					"/編隊ﾎﾞｲｽﾁｬｯﾄ"
	#define STRCMD_C_COMMAND_PARTYCALL_HELP				"format: /編隊ﾎﾞｲｽﾁｬｯﾄ - 編隊長のみ使用可能。編隊ﾎﾞｲｽﾁｬｯﾄを開始する"
	#define STRCMD_C_COMMAND_PARTYCALLEND				"/編隊ﾎﾞｲｽﾁｬｯﾄ終了"
	#define STRCMD_C_COMMAND_PARTYCALLEND_HELP			"foramt: /編隊ﾎﾞｲｽﾁｬｯﾄ終了 - 編隊長のみ使用可能。編隊ﾎﾞｲｽﾁｬｯﾄを終了する"
	#define STRCMD_C_COMMAND_GUILDCALL					"/旅団ﾎﾞｲｽﾁｬｯﾄ"
	#define STRCMD_C_COMMAND_GUILDCALL_HELP				"format: /旅団ﾎﾞｲｽﾁｬｯﾄ - 旅団長のみ使用可能、旅団ﾎﾞｲｽﾁｬｯﾄを開始する。"
	#define STRCMD_C_COMMAND_GUILDCALLEND				"/旅団ﾎﾞｲｽﾁｬｯﾄ終了"
	#define STRCMD_C_COMMAND_GUILDCALLEND_HELP			"format: /旅団ﾎﾞｲｽﾁｬｯﾄ終了 - 旅団長のみ使用可?、旅団ﾎﾞｲｽﾁｬｯﾄを終了する。"
	#define STRCMD_C_COMMAND_CALLEND					"/ﾎﾞｲｽﾁｬｯﾄ終了"
	#define STRCMD_C_COMMAND_CALLEND_HELP				"format: /ﾎﾞｲｽﾁｬｯﾄ終了 - 1:1 ボイスチャットや編隊ボイスチャットや旅団ボイスチャットを終了する。"
	#define STRCMD_C_COMMAND_COMBAT						"/対決"
	#define STRCMD_C_COMMAND_BATTLE						"/決闘"
	#define STRCMD_C_COMMAND_BATTLE_HELP				"format: /決闘 [CharacterName] - 指定したｷｬﾗｸﾀ-に1:1 決闘を申し込みする。"
	#define STRCMD_C_COMMAND_SURRENDER					"/ギブアップ"
	#define STRCMD_C_COMMAND_SURRENDER_HELP				"format: /ギブアップ [CharacterName] - 指定したｷｬﾗｸﾀ-と1:1 決闘時に自分がギブアップを申し込みする。"
	#define STRCMD_C_COMMAND_PARTYBATTLE				"/編隊決闘"
	#define STRCMD_C_COMMAND_PARTYBATTLE_HELP			"format: /編隊決闘 [CharacterName] - 編隊長のみ使用可能。指定したｷｬﾗｸﾀ- (編隊長)に編隊決闘を申し込みする。"
	#define STRCMD_C_COMMAND_PARTYCOMBAT				"/編隊対決"
	#define STRCMD_C_COMMAND_PARTYWAR					"/編隊戦闘"
	#define STRCMD_C_COMMAND_GUILDBATTLE				"/旅団戦闘"
	#define STRCMD_C_COMMAND_GUILDCOMBAT				"/旅団対決"
	#define STRCMD_C_COMMAND_GUILDCOMBAT_HELP			"format: /旅団対決 [CharacterName]  -旅団長のみ使用可能。指定したｷｬﾗｸﾀ- (旅団長)に旅団決闘を申し込みする。"
	#define STRCMD_C_COMMAND_GUILDWAR					"/旅団戦争"
	#define STRCMD_C_COMMAND_GUILDSURRENDER				"/旅団戦ギブアップ"
	#define STRCMD_C_COMMAND_GUILDSURRENDER_HELP		"format: /旅団戦ギブアップ - 旅団長のみ使用可能。旅団対決進行時、ギブアップする。"
	#define STRCMD_C_COMMAND_NAME						"/呼称"
	#define STRCMD_C_COMMAND_NAME_HELP					"format: /呼称 [CharacterName] [階級(2 ? 11)] - 旅団長のみ使用可能。指定したｷｬﾗｸﾀ-を指定した階級に変更する"
	#define STRCMD_C_COMMAND_WARP						"/ﾜ-ﾌﾟ"
	#define STRCMD_C_COMMAND_CANCELSKILL				"/スキルキャンセル"
	#define STRCMD_C_COMMAND_INITCHAT					"/ﾁｬｯﾄｳｨﾝﾄﾞｳ初期化"
	#define STRCMD_C_COMMAND_INITCHAT_HELP				"format: /ﾁｬｯﾄｳｨﾝﾄﾞｳ初期化 - ﾁｬｯﾄｳｨﾝﾄﾞｳを 初期化 する"
	#define STRCMD_C_COMMAND_REFUSEBATTLE				"/決闘ブロック"
	#define STRCMD_C_COMMAND_REFUSEBATTLE_HELP			"format: /決闘ブロック - 1:1 決闘ブロック 設定を On/Off する。"
	#define STRCMD_C_COMMAND_REFUSETRADE				"/取り引きブロック"
	#define STRCMD_C_COMMAND_REFUSETRADE_HELP			"format: /取り引きブロック - 取り引きブロック 設定を On/Off する。"
	#define STRMSG_C_050810_0001						"/windowclose"
	#define STRMSG_C_050810_0001_HELP					"format: /windowclose - 特定 ﾒｯｾ-ｼﾞﾎﾞｯｸｽを開かないようにする。自動キャンセルされる。"
	#define STRMSG_C_050810_0002						"/windowopen"
	#define STRMSG_C_050810_0002_HELP					"format: /windowopen - 全ﾒｯｾ-ｼﾞﾎﾞｯｸｽが使用できる。"

// 2006-09-29 by cmkwon	
#define STRCMD_CS_ITEMKIND_SKILL_SUPPORT_ITEM			"補助ｽｷﾙｱｲﾃﾑ"

// 2010-06-15 by shcho&hslee ?Eﾃｽｺﾅ?- ?Eｾﾆﾀﾌﾅﾛ.
#define STRCMD_CS_ITEMKIND_PET_ITEM						"ﾊﾟ-ﾄﾅ-ｱｲﾃﾑ"
#define STRCMD_CS_ITEMKIND_PET_SOCKET_ITEM		"ﾊﾟ-ﾄﾅ-ｿｹｯﾄｱｲﾃﾑ"

// 2006-11-17 by cmkwon, ??? ?? ゲ?? ?? ??
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_0			"/TimeLimitSyste"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_1			"/時間制限ｼｽﾃﾑ"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2ON		"on"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_P2OFF		"off"
#define STRCMD_CS_COMMAND_TIMELIMITSYSTEM_HELP		"format: /時間制限ｼｽﾃﾑ [on|off] - 時間制限ｼｽﾃﾑ on/offを 設定する。"
#define STRCMD_CS_COMMAND_PLAYTIME_0				"/PlayTime"
#define STRCMD_CS_COMMAND_PLAYTIME_1				"/利用時間"
#define STRCMD_CS_COMMAND_PLAYTIME_HELP				"format: /利用時間 - 今日一日のｹﾞ-ﾑ接続時間を表示する"

// 2007-10-06 by cmkwon, 副指導者 2?? ??を ??? 設定 - ??? 勢力?? ??? ???
//// 2006-12-13 by cmkwon	
//#define STRCMD_CS_COMMON_INFLUENCE_LEADER			"指導者"
//#define STRCMD_CS_COMMON_INFLUENCE_SUBLEADER		"副指導者"

// 2007-01-08 by dhjin	
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_0			"/BonusStatPoint"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_1			"/ﾎﾞ-ﾅｽｽﾃ-ﾀｽﾎﾟｲﾝﾄ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_2			"/ﾎﾞ-ﾅｽｽﾃ-ﾀｽﾎﾟｲﾝﾄ"
#define STRCMD_CS_COMMAND_BONUSSTAT_POINT_HELP		"format: /BonusStatPoint [BonusStatPoint Counts] [|character name] - BonusStatPointを DBに UPDATE"

// 2007-01-25 by dhjin	
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_0			"/ネットカフェ"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_1			"/ネットカフェ"
#define STRCMD_CS_COMMAND_PCBANGUSERCOUNT_HELP		"format: /ネットカフェ - 現在接続しているネットカフェのﾕ-ｻﾞ-数を表示する"

// 2007-10-06 by dhjin, 副指導者 ?? ?? 変更?? ??
// 2007-02-13 by dhjin, 副指導者
//#define STRCMD_CS_COMMAND_SUBLEADER_0				"/Subleader"
//#define STRCMD_CS_COMMAND_SUBLEADER_1				"/副指導者"
//#define STRCMD_CS_COMMAND_SUBLEADER_HELP			"format: /副指導者 [CharacterName] - 副指導者 設定"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_ERROR	"副指導者 設定が キャンセル されました。"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_0		"副指導者を これ以上設定することができません。"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_1		"%sを 1番目の副指導者に 設定しました。"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_2		"%sを 2番目の副指導者に設定しました。"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_10		"%sの名前は存在していません。"
//#define STRCMD_CS_COMMAND_SUBLEADER_RESULT_20		"%sは副指導者に 設定 されています。"

// 2007-02-23 by dhjin, ??情報	
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_0		"/StrategyPointInfo"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_1		"/拠点情報"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_HELP	"format: /拠点情報 - 現在 拠点進行情報を表示する。"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EMPTY	"進行中の拠点戦がありません。"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_EXIST	"拠点戦が進行中です。"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_ZONE	"進行地域"
#define STRCMD_CS_COMMAND_STRATEGYPOINTINFO_STARTTIME	"開始時間"

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

// 2007-03-30 by dhjin, ｵﾌﾞｻﾞ-ﾊﾞ- ﾓ-ﾄﾞ ﾕ-ｻﾞ- 登録
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_0		"/Observerstart"		// 2007-03-30 by dhjin, クライアント??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_START_1		"/ｵﾌﾞｻﾞ-ﾊﾞ-開始"			// 2007-03-30 by dhjin, クライアント??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_0		"/Observerend"			// 2007-03-30 by dhjin, クライアント??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_END_1		"/ｵﾌﾞｻﾞ-ﾊﾞ-終了"			// 2007-03-30 by dhjin, クライアント??? ??
#define STRCMD_CS_COMMAND_OBSERVER_REG_0			"/Observer"
#define STRCMD_CS_COMMAND_OBSERVER_REG_1			"/ｵﾌﾞｻﾞ-ﾊﾞ-"
#define STRCMD_CS_COMMAND_OBSERVER_REG_HELP			"format: /ｵﾌﾞｻﾞ-ﾊﾞ- [n] [CharacterName] ? CharacterNameﾕ-ｻﾞ-を nという番号にｾ-ﾌﾞする"

// 2007-04-10 by cmkwon, 大会ｻ-ﾊﾞ? ??
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_0			"/InitJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_1			"/大会ｻ-ﾊﾞ初期化"
#define STRCMD_CS_COMMAND_JAMBOREE_INIT_HELP		"format: /InitJamboree [認証数字] - 大会ｻ-ﾊﾞ群 DB(atum2_db_20)を 初期化 する。"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_0		"/EntrantJamboree"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_1		"/大会ｻ-ﾊﾞ参加者"
// 2008-04-15 by cmkwon, 大会ｻ-ﾊﾞ(JamboreeServer)? ｼｽﾃﾑ ?? - ??? ?? ?? ???
//#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] ? 指定したｷｬﾗｸﾀ-のﾃﾞ-ﾀを 大会ｻ-ﾊﾞ群 DB(atum2_db_20)にｺﾋﾟ-する。"
#define STRCMD_CS_COMMAND_JAMBOREE_ENTRANTS_HELP	"format: /EntrantJamboree [CharacterName] [1(Normal)|2(BCU)|4(ANI)] ? 指定したｷｬﾗｸﾀ-のﾃﾞ-ﾀを大会ｻ-ﾊﾞ群 DB(atum2_db_20)の 該当 勢力ｺﾋﾟ-する。"
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

// 2007-04-17 by dhjin, レベルランク? ?? ??
#define	STRCMD_CS_CHARACTER_12_LEVEL_RANK		"訓練生"
#define	STRCMD_CS_CHARACTER_22_LEVEL_RANK		"ジュニア"
#define	STRCMD_CS_CHARACTER_32_LEVEL_RANK		"ｴｱ-ﾏﾝ"
#define	STRCMD_CS_CHARACTER_42_LEVEL_RANK		"ｳｲﾝｸﾞﾏﾝ"
#define	STRCMD_CS_CHARACTER_52_LEVEL_RANK		"ｴ-ｽ"
#define	STRCMD_CS_CHARACTER_62_LEVEL_RANK		"ベテラン"
#define	STRCMD_CS_CHARACTER_72_LEVEL_RANK		"トップガン"
#define	STRCMD_CS_CHARACTER_82_LEVEL_RANK		"ｳｲﾝｸﾞｺﾏﾝﾄﾞ"
#define	STRCMD_CS_CHARACTER_92_LEVEL_RANK		"ﾋ-ﾛ-"

// 2007-05-09 by cmkwon, 
#define STRMSG_VERSION_INFO_FILE_NAME				"VersionInfo.ver"
#define STRMSG_REG_KEY_NAME_LAUNCHER_VERSION		"LauncherVersion"
#define STRMSG_REG_KEY_NAME_CLIENT_VERSION			"ClientVersion"
// 2007-12-27 by cmkwon, ｳｨﾝﾄﾞｳﾓ-ﾄﾞ機能追加 -
//#define STRMSG_REG_KEY_NAME_WINDOWDEGREE			"WindowDegree"
#define STRMSG_REG_KEY_NAME_ACCOUNT_NAME			"AccountName"
#define STRMSG_REG_KEY_NAME_SERVER_GROUP_NAME		"ServerGroupName"

// 2007-05-23 by dhjin, ARENA ? 出力 ?? ???
#define STRMSG_CS_STRING_ARENA_NOT_SEARCH			"ｱﾘ-ﾅ ﾁ-ﾑが見つかりません。"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_0			"/ARENA"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_1			"/ｱﾘ-ﾅ"
#define STRMSG_CS_COMMAND_ARENA_TEAM_INFO_HELP		"format: /ｱﾘ-ﾅ [2(BCU)|4(ANI)]- 現在 ｱﾘ-ﾅ 進行 情報を 表示する。"

// 2010. 06. 04 by hsLee ARENA ﾀﾎﾇﾇｴﾏﾆｼ ｰ・? - 
// 2010. 06. 04 by hsLee ﾀﾎﾆｼﾇﾇｴﾏ ﾇﾊｵ・2ﾂ・ｳｭﾀﾌｵｵ ﾁｶﾀ?. (GM ｸ?ﾓﾉｾ・ﾃﾟｰ｡. /nextscene(ｴﾙﾀｽ ｽﾃｳﾗｸｶ ｾﾀ ﾈ｣ﾃ・) )
#define STRCMD_CS_COMMAND_INFINITY_NEXT_SCENE		"/nextscene"
// End 2010. 06. 04 by hsLee ﾀﾎﾆｼﾇﾇｴﾏ ﾇﾊｵ・2ﾂ・ｳｭﾀﾌｵｵ ﾁｶﾀ?. (GM ｸ?ﾓﾉｾ・ﾃﾟｰ｡. /nextscene(ｴﾙﾀｽ ｽﾃｳﾗｸｶ ｾﾀ ﾈ｣ﾃ・) )

// 2007-06-15 by dhjin, 観戦
#define STRMSG_CS_COMMAND_WATCH_START_INFO_0		"/観戦開始"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_1		"/WatchStart"
#define STRMSG_CS_COMMAND_WATCH_START_INFO_HELP		"format: /観戦開始 - 観戦を 開始する。"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_0			"/観戦終了"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_1			"/WatchEnd"
#define STRMSG_CS_COMMAND_WATCH_END_INFO_HELP		"format: /観戦終了 - 観戦を 終了する。"

// 2007-06-22 by dhjin, WarPoint 追加
#define STRMSG_CS_COMMAND_WARPOINT_0				"/戦争ﾎﾟｲﾝﾄ（WP）"
#define STRMSG_CS_COMMAND_WARPOINT_1				"/WarPoint"
#define STRMSG_CS_COMMAND_WARPOINT_HELP				"format: /戦争ﾎﾟｲﾝﾄ（WP） [数値 1〜1000000] [|ﾕ-ｻﾞ-ﾈ-ﾑ] - 戦争ﾎﾟｲﾝﾄ（WP）を 追加する。"

// 2007-06-26 by dhjin, ?ﾎﾟｲﾝﾄ イベント ?? 追加
#define STRCMD_CS_COMMAND_GAMEEVENT_P1WARPOINT		"戦争ﾎﾟｲﾝﾄ（WP）"

// 2007-07-11 by cmkwon, ｱﾘ-ﾅﾌﾞﾛｯｸｼｽﾃﾑ ?? - 命令語 追加(/ｱﾘ-ﾅﾌﾞﾛｯｸ, /ｱﾘ-ﾅﾌﾞﾛｯｸ解除)
#define STRCMD_CS_COMMAND_ARENAFORBID_0				"/ｱﾘ-ﾅﾌﾞﾛｯｸ"
#define STRCMD_CS_COMMAND_ARENAFORBID_1				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_2				"/forbidArena"
#define STRCMD_CS_COMMAND_ARENAFORBID_HELP			"format: /ｱﾘ-ﾅﾌﾞﾛｯｸ [character name] [|時間(分)] - Arena ブロック する"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_0		"/ｱﾘ-ﾅﾌﾞﾛｯｸ解除"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_1		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_2		"/releaseArena"
#define STRCMD_CS_COMMAND_ARENAFORBIDRelease_HELP	"format: /ｱﾘ-ﾅﾌﾞﾛｯｸ解除 [character name] - Arena ブロック 解除 する"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-02 by cmkwon, 旅団 ﾏ-ｸ ?? ｼｽﾃﾑ ?? - 追加? ???
#define STRMSG_070802_0001				"旅団ﾏ-ｸ登録申し込みが完了しました。"
#define STRMSG_070802_0002				"審査の後、登録が完了します。"
#define STRMSG_070802_0003				"選択した%d個の旅団ﾏ-ｸを許可しますか？"
#define STRMSG_070802_0004				"旅団ﾏ-ｸなし"
#define STRMSG_070802_0005				"旅団ﾏ-ｸ待機"
#define STRMSG_070802_0006				"旅団ﾏ-ｸ正常"
#define STRMSG_070802_0007				"旅団ﾏ-ｸｴﾗ-"

// 2007-08-24 by cmkwon, ｽﾋﾟ-ｶ-ｱｲﾃﾑ 使用可能/ブロック 設定 ?? 追加 - 命令語 追加
#define STRCMD_CS_COMMAND_UsableSpeakerItem_0			"/ｽﾋﾟ-ｶ-使用"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_1			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_2			"/UseSpeaker"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Able		"可能"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_P1Forbid	"禁止"
#define STRCMD_CS_COMMAND_UsableSpeakerItem_HELP		"format:/[ｽﾋﾟ-ｶ-使用|UseSpeaker|UseSpeaker][可能|禁止]-ｽﾋﾟ-ｶ-ｱｲﾃﾑ 使用を ブロック/解除 する"

// 2007-08-27 by cmkwon, ｻ-ﾊﾞ???? 命令語 追加(SCAdminTool?? SCMonitor? PrepareShutdownを ?? ? ? ??)
#define STRCMD_CS_COMMAND_PrepareShutdown_0				"/ｻ-ﾊﾞﾀﾞｳﾝ準備"
#define STRCMD_CS_COMMAND_PrepareShutdown_1				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_2				"/PrepareShutdown"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Start		"Start"
#define STRCMD_CS_COMMAND_PrepareShutdown_P1Release		"Release"
#define STRCMD_CS_COMMAND_PrepareShutdown_HELP			"format: /[ｻ-ﾊﾞﾀﾞｳﾝ準備|PrepareShutdown|PrepareShutdown] [Start|Release] - ｻ-ﾊﾞ 終了 準備、全てのﾕ-ｻﾞ-の接続を強制終了する"

// 2007-08-30 by cmkwon, 会議室 ｼｽﾃﾑ ?? - 命令語 追加
#define STRCMD_CS_COMMAND_EntrancePermission_0				"/入場許可"
#define STRCMD_CS_COMMAND_EntrancePermission_1				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_2				"/EntrancePermission"
#define STRCMD_CS_COMMAND_EntrancePermission_HELP			"format: /[入場許可] [|CharacterName] - 指導者のみ使用可能。該当 ｷｬﾗｸﾀ-を入場許可 リストに追加する。"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_0			"/入場不可"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_1			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_2			"/EntrancePermissionDeny"
#define STRCMD_CS_COMMAND_EntrancePermissionDeny_HELP		"format: /[入場不可] [CharacterName] - 指導者のみ使用可?、該当 ｷｬﾗｸﾀ-を 会議室 入場許可 リストから削除する。"

// 2007-10-05 by cmkwon, ???を ???? ????? ??
#define STRCMD_071005_0000					"%d日%d時間%d分%d秒", Day, Hour, Minute, Second
#define STRCMD_071005_0001					"%d年%d月%d日", Year, Month, Day
#define STRCMD_071005_0002					"%d年%d月", Year, Month
#define STRCMD_071005_0003					"%d月%d日", Month, Day


// 2007-10-06 by cmkwon, 副指導者 2?? ??を ??? 設定 -
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_1		"勢力戦 副指導者 1"
#define STRCMD_CS_COMMON_RACE_INFLUENCE_SUBLEADER_2		"勢力戦 副指導者 2"
#define STRCMD_VCN_INFLUENCE_LEADER						"総司令官"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_1				"副司令官"
#define STRCMD_VCN_INFLUENCE_SUBLEADER_2				"参謀総長"
#define STRCMD_ANI_INFLUENCE_LEADER						"議長"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_1				"副議長"
#define STRCMD_ANI_INFLUENCE_SUBLEADER_2				"作戦本部長"
#define STRCMD_OUTPOST_GUILD_MASTER						"%s 艦長"

// 2007-10-06 by dhjin, 副指導者 ?? ?? 変更?? ??
#define STRCMD_CS_COMMAND_SUBLEADER1_0				"/appointment1"
#define STRCMD_CS_COMMAND_SUBLEADER1_1				"/職位付与1"
#define STRCMD_CS_COMMAND_SUBLEADER1_HELP			"format: /職位付与1 [CharacterName] - BCU : 副司令官、 ANI : 副議長 設定"
#define STRCMD_CS_COMMAND_SUBLEADER2_0				"/appointment2"
#define STRCMD_CS_COMMAND_SUBLEADER2_1				"/職位付与2"
#define STRCMD_CS_COMMAND_SUBLEADER2_HELP			"format: /職位付与2 [CharacterName] - BCU : 参謀総長、ANI : 作戦本部長設定"

// 2007-10-30 by cmkwon, 勢力? HappyHour イベント ?? - 命令語 ?? ??? ??? ?? ?? ?? ?
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT			"/HappyHour"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_1			"/happyEvent"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PSTART		"開始"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_PEND		"終了"
#define STRCMD_CS_COMMAND_HAPPYHOUREVENT_HELP		"format: /HappyHourイベント [1(Normal)|2(BCU)|4(ANI)|255(All)] [開始|終了] [進行時間(単位:分)]"

// 2007-10-30 by cmkwon, 勢力? HappyHour イベント ?? - ?? ?を ??? ?
#define STRCMD_CS_INFLUENCE_TYPE_NORMAL			"一般勢力"
#define STRCMD_CS_INFLUENCE_TYPE_VCN			"ﾊﾞｲｼﾞｪﾆｭ-勢力"
#define STRCMD_CS_INFLUENCE_TYPE_ANI			"ｱ-ﾘﾝﾄﾝ勢力"
#define STRCMD_CS_INFLUENCE_TYPE_ALL_MASK		"全体対象"			// 2007-10-30 by cmkwon, 勢力? HappyHour イベント ?? - 追加? ?

// 2007-11-05 by cmkwon, WP ?? 命令語 ?? - 命令語 追加
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_0			"/AddWarPointInMap"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_1			"/WP追加ﾏｯﾌﾟ"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_2			"/戦争ﾎﾟｲﾝﾄ（WP）追加ﾏｯﾌﾟ"
#define STRCMD_CS_COMMAND_WAPPOINTINMAP_HELP		"format: /WP追加ﾏｯﾌﾟ [1(Normal)|2(BCU)|4(ANI)|255(All)] [AddWarPoint(1〜)] - 現在ﾏｯﾌﾟの指定した勢力のﾕ-ｻﾞ-に戦争ﾎﾟｲﾝﾄ（WP）を支給する。"

// 2007-11-19 by cmkwon, ??ｼｽﾃﾑ ｱｯﾌﾟﾃﾞ-ﾄ - 命令語 追加
#define STRCMD_CS_COMMAND_STARTCALLGM_0			"/StartCallGM"
#define STRCMD_CS_COMMAND_STARTCALLGM_1			"/ヘルプ開始"
#define STRCMD_CS_COMMAND_STARTCALLGM_2			"/ヘルプ開始"
#define STRCMD_CS_COMMAND_STARTCALLGM_HELP		"format: /ヘルプ開始 [|時間(単位:分)] - 鎮静 システ? 開始"
#define STRCMD_CS_COMMAND_ENDCALLGM_0			"/EndCallGM"
#define STRCMD_CS_COMMAND_ENDCALLGM_1			"/ヘルプ終了"
#define STRCMD_CS_COMMAND_ENDCALLGM_2			"/ヘルプ終了"
#define STRCMD_CS_COMMAND_ENDCALLGM_HELP		"format: /ヘルプ終了 - 鎮静 ｼｽﾃﾑ 終了"

// 2007-12-27 by cmkwon, ｳｲﾝﾄﾞｳﾓ-ﾄﾞ機能追加- STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW 追加
#define STRMSG_REG_KEY_NAME_WINDOWDEGREE_NEW		"WindowDegreeNew"

// 2008-01-03 by cmkwon, ???ﾓ-ﾄﾞ ?? ???? -
#define STRMSG_REG_KEY_NAME_WINDOWMODE				"WindowMode"

// 2008-01-31 by cmkwon, アカウントブロック/解除 命令語? ??? ｼｽﾃﾑ ?? - 命令語 追加
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_0					"/Block"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_1					"/BlockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_2					"/ブロック"
#define STRCMD_CS_COMMAND_NEWACCOUNTBLOCK_HELP				"format: /Block [AccountName] [BlockType(1:Normal|2:Related Money|3:Related Item|4:Related SpeedHack|5:Related Chatting|6:Related GameBug)] [Period:Days] [Block Reason for User] / [Block Reason for only Admin]"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_0				"/Unblock"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_1				"/UnblockAccount"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_2				"/ブロック解除"
#define STRCMD_CS_COMMAND_NEWACCOUNTUNBLOCK_HELP			"format: /Unblock [AccountName]"

// 2008-02-20 by cmkwon, 命令語 追加(?? ?? ?? ???? ｱｲﾃﾑ ?? -
#define STRCMD_CS_COMMAND_ITEMALLUSER_0				"/ItemAllUser"
#define STRCMD_CS_COMMAND_ITEMALLUSER_1				"/ｱｲﾃﾑ全部"
#define STRCMD_CS_COMMAND_ITEMALLUSER_2				"/ｱｲﾃﾑ追加全部"
#define STRCMD_CS_COMMAND_ITEMALLUSER_HELP			"format: /ItemAllUser [1(Normal)|2(BCU)|4(ANI)|255(All)] [Item Number] [# of items] ? 接続したﾕ-ｻﾞ-のなかで指定した勢力のﾕ-ｻﾞ-に指定したｱｲﾃﾑを支給する。"

// 2008-02-21 by dhjin, ｱﾘ-ﾅ ?? - ｱﾘ-ﾅ 追加 命令語
#define STRCMD_CS_COMMAND_ARENAMOVE_0						"/ArenaMove"
#define STRCMD_CS_COMMAND_ARENAMOVE_1						"/ｱﾘ-ﾅ移動"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_0					"/TeamArenaLeave"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_1					"/対象ｻ-ﾊﾞ復帰"
#define STRCMD_CS_COMMAND_TEAMARENALEAVE_HELP				"format: /TeamArenaLeave [2(BLUE)|4(RED)|6(BLUE AND RED)]"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_0				"/TargetArenaLeave"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_1				"/対象ｻ-ﾊﾞ復帰"
#define STRCMD_CS_COMMAND_TARGETARENALEAVE_HELP				"format: /TargetArenaLeave [Charactername]"
#define STRCMD_CS_COMMAND_ARENAEVENT_0						"/ArenaEvent"
#define STRCMD_CS_COMMAND_ARENAEVENT_1						"/ｱﾘ-ﾅｲﾍﾞﾝﾄ"
#define STRCMD_CS_COMMAND_ARENAEVENT_2						"/ｱﾘ-ﾅｲﾍﾞﾝﾄ"
#define STRCMD_CS_COMMAND_ARENAEVENT_HELP					"format: /ArenaEvent [RoomNumber]"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_0				"/ArenaEventRelease"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_1				"/ｱﾘ-ﾅｲﾍﾞﾝﾄ解除"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_2				"/ｱﾘ-ﾅｲﾍﾞﾝﾄ解除"
#define STRCMD_CS_COMMAND_ARENAEVENTRELEASE_HELP			"format: /ArenaEventRelease [RoomNumber]"

// 2008-06-03 by cmkwon, AdminTool, DBTool ??? ｱｲﾃﾑ 検索? ?????? 検索 ?? 追加(K0000143) -
#define STRCMD_CS_ITEMKIND_ALL_ITEM							"全ｱｲﾃﾑ類"

//////////////////////////////////////////////////////////////////////////
// 2008-05-20 by dhjin, EP3 - 旅団 ?? ??	// 2006-03-07 by cmkwon
#define STRCMD_CS_GUILD_RANK_PRIVATE_NULL		"隊員"
#define STRCMD_CS_GUILD_RANK_COMMANDER			"旅団長"
#define STRCMD_CS_GUILD_RANK_SUBCOMMANDER		"副旅団長"				// 2008-05-20 by dhjin, EP3 - 旅団 ?? ??
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_1		"1大隊長"
#define STRCMD_CS_GUILD_RANK_PRIVATE_1			"1大隊員"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_2		"2大隊長"
#define STRCMD_CS_GUILD_RANK_PRIVATE_2			"2大隊員"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_3		"3大隊長"
#define STRCMD_CS_GUILD_RANK_PRIVATE_3			"3大隊員"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_4		"4大隊長"
#define STRCMD_CS_GUILD_RANK_PRIVATE_4			"4大隊員"
#define STRCMD_CS_GUILD_RANK_SQUAD_LEADER_5		"5大隊長"
#define STRCMD_CS_GUILD_RANK_PRIVATE_5			"5大隊員"

//////////////////////////////////////////////////////////////////////////
// 2008-06-19 by dhjin, EP3 - ??情報
#define STRCMD_COMMAND_WAR_OPTION_0					"/母船戦情報オプション"
#define STRCMD_COMMAND_WAR_OPTION_1					"/MotherShipInfoOption"

// 2008-08-18 by dhjin, 勢力ﾏ-ｸｲﾍﾞﾝﾄ
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_0				"/influencemarkevent"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_1				"/勢力ﾏｰｸｲﾍﾞﾝﾄ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_2				"/勢力ﾏｰｸｲﾍﾞﾝﾄ"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENT_HELP			"format: /influencemarkevent [勢力 2(BCU)|4(ANI)]"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_0			"/influencemarkeventend"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_1			"/勢力ﾏｰｸｲﾍﾞﾝﾄ終了"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_2			"/勢力ﾏｰｸｲﾍﾞﾝﾄ終了"
#define STRCMD_CS_COMMAND_INFLUENCEMARKEVENTEND_HELP		"format: /influencemarkeventend"

//////////////////////////////////////////////////////////////////////////
// 2008-08-25 by dhjin, ?? PC? IP情報 ??
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_0				"/PCBangReloadTime"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_1				"/ﾈｯﾄｶﾌｪﾘﾛ-ﾄﾞﾀｲﾑ"
#define STRCMD_CS_COMMAND_PCBANGRELOADTIME_HELP				"format: /PCBangreloadtime [Minute] - 10 Min ? 1440 Min"


// 2008-08-21 by dhjin, 一般, ?? アカウント? 副指導者 ?? ??
#define STRMSG_080821_0001				"選択したｷｬﾗｸﾀ-に階級を任命できません。"


// 2008-09-09 by cmkwon, /勢力召喚 命令語 ?? リスト? ??ﾀｲﾌﾟ 追加 -
#define STRCMD_CS_COMMAND_COMEONINFL_HELP2		"format: /ComeOnInfl [1(Normal)|2(VCN)|4(ANI)|255(All)] [最大人員] [0|最小レベル] [0|最大レベル] [1(B)|16(M)|256(A)|4096(I)] [ユ?ザ?に送るメッセ?ジ] ? 任意の指定した勢力、指定したレベルのユ?ザ?にイベント?ップへの移動を要請する"

// 2008-09-09 by cmkwon, "/kick" 命令語 追加 - 
#define STRCMD_CS_COMMAND_KICK_0							"/Kick"
#define STRCMD_CS_COMMAND_KICK_1							"/キック"
#define STRCMD_CS_COMMAND_KICK_HELP							"format: /Kick [CharacterName] - 該当 ｷｬﾗｸﾀ-を ｹﾞ-ﾑ 終了させる。"


// 2008-09-12 by cmkwon, "/名声" 命令語 追加 -
#define STRCMD_CS_COMMAND_ADD_FAME_0							"/Fame"
#define STRCMD_CS_COMMAND_ADD_FAME_1							"/名声"
#define STRCMD_CS_COMMAND_ADD_FAME_HELP							"format: /名声 [個人名声] [旅団名声] - 接続 ｷｬﾗｸﾀ-の名声、ｷｬﾗｸﾀ- 旅団 名声を 上げる。"

// 2008-12-30 by cmkwon, 指導者ﾁｭｯﾄ制限ｶ-ﾄﾞ -
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_0			"/ReleaseLeaderChatBlock"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_1			"/指導者?ャット制限解除"
#define STRCMD_CS_COMMAND_CHATFORBIDRELEASE_LEADER_HELP			"format: /指導者ﾁｬｯﾄ制限解除[CharacterName]-指導者ﾁｬｯﾄ制限の解除。"

// 2009-10-12 by cmkwon, ﾌﾘ-ｽｶの削除案適用 - 
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_0                       "/StartCityMap"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_1                       "/ｽﾀ-ﾄ都市ﾏｯﾌﾟ"
#define STRCMD_CS_COMMAND_CHANGE_StartCityMapIndex_HELP                              "format: /ｽﾀ-ﾄ都市ﾏｯﾌﾟ [2001|2002] [|CharacterName] - 該当ｷｬﾗｸﾀ-の一般勢力時、ｽﾀ-ﾄする都市のﾏｯﾌﾟを該当ﾏｯﾌﾟ(2001|2002)に変更する。"


///////////////////////////////////////////////////////////////////////////////
// 2010-01-08 by cmkwon, ﾃﾖｴ・ｷｹｺｧ ｻ?ﾇ篩｡ ｵ?ｸ･ ﾃﾟｰ｡ ｻ酩ﾗ(ｷｹｺｧｺｰ ｰ雎ﾞ) - ｰ雎ﾞｶ・ｹ鮗ﾎﾀ・ ｴ・? ﾀ螻ｺ, ﾃﾑｵｶ, ﾁ､ｺｹﾀﾚ, ｼ?ﾈ｣ﾀﾚ, ﾀ・ｳﾀ?ﾀ?
#define STRCMD_CS_CHARACTER_96_LEVEL_RANK "ｾﾝﾁｭﾘｱﾝ"
#define STRCMD_CS_CHARACTER_100_LEVEL_RANK "ｶ-ﾈﾙ"
#define STRCMD_CS_CHARACTER_104_LEVEL_RANK "ジェネラル"
#define STRCMD_CS_CHARACTER_108_LEVEL_RANK "ｶﾞﾊﾞﾅ-"
#define STRCMD_CS_CHARACTER_112_LEVEL_RANK "ｺﾝｸｴｽﾀ"
#define STRCMD_CS_CHARACTER_116_LEVEL_RANK "ｶﾞ-ﾃﾞｨｱﾝ"
#define STRCMD_CS_CHARACTER_120_LEVEL_RANK "ﾚｼﾞｪﾝﾀﾞﾘ-"
#define STRCMD_CS_CHARACTER_XX_LEVEL_RANK "基本"

#define STRCMD_CS_COMMAND_ENDARENA				"/endarena"				// 2012-09-24 by jhseol, ｾﾆｷｹｳｪ ﾁｾｷ・ｸ?ﾓﾉｾ・ｼ?ﾁ､

// 2014-05-16 by bckim, ｿｵｹｮ ｸ?ﾓﾉｾ・ﾃﾟｰ｡
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_TIME		"/resetreversalbufftime"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_STATE		"/resetreversalbuffstate"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_EXECUTE	"/resetreversalbuffexecute"
#define STRCMD_CS_COMMAND_RESET_REVERSAL_BUFF_END		"/resetreversalbuffend"
#define STRCMD_CS_COMMAND_COMPAT_POWER					"/compatpower"
// End. 2014-05-16 by bckim, ｿｵｹｮ ｸ?ﾓﾉｾ・ﾃﾟｰ｡

///////////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXﾀﾌｺ･ﾆｮ ｸﾊ ｿ?ﾇﾁﾁｦﾇﾑ - ｸ?ﾓﾉｾ・ﾃﾟｰ｡
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_0			"/MapWarpRestrict"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_1			"/ｸﾊﾀﾌｵｿﾁｦﾇﾑ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_HELP		"format: /ｸﾊﾀﾌｵｿﾁｦﾇﾑ [MapIndex] - ﾇﾘｴ・ｸﾊﾀﾇ ｿ?ﾇﾁ ﾁｦﾇﾑﾀｻ ｼｳﾁ､ﾇﾔ"
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_0	"[%d]ｸﾊﾀﾇ ｿ?ﾇﾁ ﾁｦﾇﾑﾀﾌ ｼｳﾁ､ ｵﾇｾ?ｽﾀｴﾏｴﾙ."
#define STRCMD_CS_COMMAND_MAP_WARP_RESTRICT_RESULT_1	"[%d]ｸﾊﾀﾇ ｿ?ﾇﾁ ﾁｦﾇﾑﾀﾌ ﾇﾘﾁｦ ｵﾇｾ?ｽﾀｴﾏｴﾙ."
#define STRCMD_CS_COMMAND_MAP_WARP_ERROR				"[%d]ｴﾂ ﾇ譱・ﾏﾁ・ｾﾊｴﾂ ｸﾊｹ?ﾈ｣ﾀﾔｴﾏｴﾙ."
// end 2012-11-29 by jhseol, OXﾀﾌｺ･ﾆｮ ｸﾊ ｿ?ﾇﾁﾁｦﾇﾑ - ｸ?ﾓﾉｾ・ﾃﾟｰ｡

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, ﾅｸ ｰ霖､ ｼｼｷﾂｺｯｰ・
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_0			"/勢力変更"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_1			"/勢力変更"
#define STRCMD_CS_COMMAND_ACCOUNT_CHANGEINFL_HELP		"format: /勢力変更[アカウントUID] [2(BCU)|4(ANI)]"

// 2013-11-19 by bckim, ﾆﾄﾆｼｿ・ﾁ､ｺｸ ｺｸｱ・ｸ?ﾓﾉｾ・ﾃﾟｰ｡
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_0			"/フォ-メ-ションインフォメ-ション"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_1			"/フォ-メ-ションインフォメ-ション"
#define STRCMD_CS_COMMAND_PARTYMEMBER_INFO_HELP			"format: /フォ-メ-ションインフォメ-ション [ｷｬﾗｸﾀ-名] - フォ-メ-ションインフォメ-ションメンバ-プレイヤ-の情報  (メンバ-がｹﾞ-ﾑにログインしている必要があります)"
// End. 2013-11-19 by bckim, ﾆﾄﾆｼｿ・ﾁ､ｺｸ ｺｸｱ・ｸ?ﾓﾉｾ・ﾃﾟｰ｡

#endif // end_#ifndef _STRING_DEFINE_COMMON_H_





