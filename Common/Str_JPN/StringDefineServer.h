
// 2005-04-28 by cmkwon

#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_




///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "ｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre Server！"
	#define STRERR_S_ATUMEXE_0003 "自動ｱｯﾌﾟﾃﾞ-ﾄに失敗しました。\r\nｹﾞ-ﾑを再ｲﾝｽﾄ-ﾙしてください。\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error:%s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "ﾀﾞｳﾝﾛ-ﾄﾞｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMEXE_0007 "ﾀﾞｳﾝﾛ-ﾄﾞﾌｧｲﾙのサイズが不明です。"
	#define STRERR_S_ATUMEXE_0008 "ｱｯﾌﾟﾃﾞ-ﾄﾌｧｲﾙをﾀﾞｳﾝﾛ-ﾄﾞできません。"
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "ﾌｧｲﾙが見つかりません。"
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "update completed"
	#define STRMSG_S_ATUMLAUNCHER_0001 "ｻ-ﾊﾞ-を選択してください。"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "deleting files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "update completed(%s->%s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "実行ﾌｧｲﾙ選択"
	#define STRMSG_S_ATUMLAUNCHER_0007 "実行ル-ト選択"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading is canceled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Getting File Information %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, ｺ｣ﾆｮｳｲ X-Trap -> VTC ｰ｡ｵ蟾ﾎ ｺｯｰ・
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, ｺ｣ﾆｮｳｲ X-Trap -> VTC ｰ｡ｵ蟾ﾎ ｺｯｰ・
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "認証ｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMLAUNCHER_0005 "ｻ-ﾊﾞ-接続に失敗しました。"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "クライアントを再度ﾀﾞｳﾝﾛ-ﾄﾞしてください。\nURL: http://space.mgame.com/\n最新ﾊﾞ-ｼﾞｮﾝ:"
	#define STRERR_S_ATUMLAUNCHER_0009 "自動ｱｯﾌﾟﾃﾞ-ﾄに失敗しました。\r\nクライアントを再ｲﾝｽﾄ-ﾙをしてください。\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "全てのｻ-ﾊﾞ-が非活性状態です。"
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%sメンテナンス中…"
	#define STRERR_S_ATUMLAUNCHER_0012 "全てのサ-バがメンテナンス中です。しばらく後に接続してください。"
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from%s[%s]\r\n"
// 2006-08-24 by cmkwon, Change to STRMSG_060824_0000
//	#define STRERR_S_ATUMLAUNCHER_0014 "間違っているIDです、ﾊﾟｽﾜ-ﾄﾞｴﾗ-\n\n* 現在はﾍﾞ-ﾀﾃｽﾄ?アカウントを所有しているｻ-ﾊﾞ-のみがログインできます。"
	#define STRERR_S_ATUMLAUNCHER_0015 "ﾛｸﾞｲﾝｴﾗ-"
	#define STRERR_S_ATUMLAUNCHER_0016 "ID未入力"
	#define STRERR_S_ATUMLAUNCHER_0017 "重複ログイン"
	#define STRERR_S_ATUMLAUNCHER_0018 "ｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMLAUNCHER_0019 "ｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMLAUNCHER_0020 "ｻ-ﾋﾞｽが一時的に中断されいます。\n\nしばらく後に接続してください。"
	#define STRERR_S_ATUMLAUNCHER_0021 "混雑しているためログインできません。\n\nしばらく後に接続してください。"

	
	#define STRERR_S_ATUMLAUNCHER_0022 "このアカウントはブロックされています。\n期間:%s\n\n不明な場合、ｶｽﾀﾏ-ｾﾝﾀ-に問い合わせてください。"
	#define STRERR_S_ATUMLAUNCHER_0023 "ｸﾗｲｱﾝﾄﾊﾞ-ｼﾞｮﾝが異なります。\n\nクライアントを再度ﾀﾞｳﾝﾛ-ﾄﾞしてください。"
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR:%s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "ﾀﾞｳﾝﾛ-ﾄﾞｻ-ﾊﾞ-に接続できません。"
	#define STRERR_S_ATUMLAUNCHER_0026 "ﾀﾞｳﾝﾛ-ﾄﾞﾌｧｲﾙ(%s)のサイズが不明です。"
	#define STRERR_S_ATUMLAUNCHER_0027 "ﾀﾞｳﾝﾛ-ﾄﾞﾌｧｲﾙのサイズが不明です。"
	#define STRERR_S_ATUMLAUNCHER_0028 "ｱｯﾌﾟﾃﾞ-ﾄﾌｧｲﾙをﾀﾞｳﾝﾛ-ﾄﾞできません。"
	#define STRERR_S_ATUMLAUNCHER_0029 "ｱｯﾌﾟﾃﾞ-ﾄﾌｧｲﾙが存在しません。"
	#define STRERR_S_ATUMLAUNCHER_0030 "ｻ-ﾊﾞ-ﾒﾝﾃﾅﾝｽ中です。しばらく後に接続してください。"
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "ﾌｧｲﾙが見つかりません。"
	#define STRERR_S_ATUMLAUNCHER_0034 "ル-トが見つかりません。"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type:%s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18ｼｼ ｹﾌｸｸ ﾃｻｼﾒｳ篩｡ｰﾔ ﾀ?ｿ・ﾇｴ?ｰﾔﾀﾓｽﾃｰ｣ ｼｱﾅﾃﾁｦ ｼｳﾁ､ﾀｸｷﾎ ﾀﾎﾇﾏｿｩ, ﾇ?ﾀ・ｽﾃｰ｣ｿ｡ｴﾂ ｰﾔﾀﾓ ﾁ?ﾇ狢ﾌ ｺﾒｰ｡ｴﾉﾇﾕｴﾏｴﾙ.\n\nﾀﾚｼｼﾇﾑ ｻ酩ﾗﾀｺ ｿ｡ﾀﾌｽｺｿﾂｶ?ﾀﾎ ｰ?ﾌｴｼｾﾅﾍｷﾎ ｹｮﾀﾇｹﾙｶ?ｴﾏｴﾙ."		// 2012-07-11 by hskim, ｼｱﾅﾃﾀ・ｼﾋｴﾙｿ・
	#define STRMSG_S_ATUMLAUNCHER_0038 "ｰﾔﾀﾓﾀｻ ｴﾙｽﾃ ｽﾃﾀﾛﾇﾘ ﾁﾖｽﾊｽﾃｿ・\r\n\r\nｹｮﾁｦｰ｡ ﾁ?ｼﾓﾀ?ﾀｸｷﾎ ｹﾟｻ?ｵﾇｸ・ｿ｡ﾀﾌｽｺｿﾂｶ?ﾀﾎ ｰ?ﾌｴｼｾﾅﾍｷﾎ ｹｮﾀﾇｹﾙｶ?ｴﾏｴﾙ."		// 2012-07-11 by hskim, ｼｱﾅﾃﾀ・ｼﾋｴﾙｿ・


	#define STRMSG_S_050506		"\'%s\'様は現在アカウントブロックされています。\n理由:%s\n期間:%s?%s\n\n不明な場合は、ｶｽﾀﾏ-ｾﾝﾀ-に問い合わせてください。"
	#define STRMSG_S_050930		"クライアントを再度ﾀﾞｳﾝﾛ-ﾄﾞしてください。\nURL:%s\n最新ﾊﾞ-ｼﾞｮﾝ"
// 2_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "男"
//	#define STRMSG_S_SCADMINTOOL_0001 "女"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d年、%d歳"
//	#define STRMSG_S_SCADMINTOOL_0003 "本当にアカウント情報を変更しますか？ "
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10))+'個'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) +'個取得、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
//	#define STRMSG_S_SCADMINTOOL_0006 "''''+l.PeerCharacterName+'''に'+ CAST(l.ChangeCount AS VARCHAR(10))+'個渡す、'+CAST(l.CurrentCount AS VARCHAR(10)) +'個'"
//	#define STRMSG_S_SCADMINTOOL_0007 "''''+l.PeerCharacterName+'''から'+CAST(l.ChangeCount AS VARCHAR(10))+'個もらう、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10))+'個捨てる、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10))+'個購入、残りSPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10))+'個販売、残りSPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0012 "''''+l.PeerCharacterName+'''が'+CAST(l.ChangeCount AS VARCHAR(10))+'個追加する、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0013 "''''+l.PeerCharacterName+'''が'+CAST(l.ChangeCount AS VARCHAR(10))+'個削除する、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0014 "CAST(l.ChangeCount AS VARCHAR(10))+'個追加、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0015 "CAST(l.ChangeCount AS VARCHAR(10))+'個預ける、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0016 "CAST(l.ChangeCount AS VARCHAR(10))+'個引き出す、'+CAST(l.CurrentCount AS VARCHAR(10))+'個'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'ｹﾞ-ﾑ時間\'+dbo.atum_GetHMSFromS(l.PlayTime)+\'、総\'+dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10))+'->'+CAST(l.Param2 AS VARCHAR(10))+',ｹﾞ-ﾑ時間:'+dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15))+\'増減、総\'+CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "衝突"
//	#define STRMSG_S_SCADMINTOOL_0021 "ﾓﾝｽﾀ-"
//	#define STRMSG_S_SCADMINTOOL_0022 "ギア"
//	#define STRMSG_S_SCADMINTOOL_0023 "原因不明"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s、残りｽﾃ-ﾀｽ:%s"
	#define STRMSG_S_SCADMINTOOL_0025 "(なし)"
//	#define STRMSG_S_SCADMINTOOL_0026 "私"
//	#define STRMSG_S_SCADMINTOOL_0027 "なし"
//	#define STRMSG_S_SCADMINTOOL_0028 "バグ使用ﾕ-ｻﾞ-"
	#define STRMSG_S_SCADMINTOOL_0029 "アカウントブロック"
	#define STRMSG_S_SCADMINTOOL_0030 "ﾁｬｯﾄﾌﾞﾛｯｸ"
//	#define STRMSG_S_SCADMINTOOL_0031 "接続ログ"
//	#define STRMSG_S_SCADMINTOOL_0032 "ﾕ-ｻﾞ-ﾛｸﾞ"
//	#define STRMSG_S_SCADMINTOOL_0033 "ｱｲﾃﾑﾛｸﾞ"
	#define STRMSG_S_SCADMINTOOL_0034 "%s-%sｻ-ﾊﾞ-"
	#define STRMSG_S_SCADMINTOOL_0035 "%s-%sｻ-ﾊﾞ-、%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "アカウントブロック"
//	#define STRMSG_S_SCADMINTOOL_0037 "分類"
//	#define STRMSG_S_SCADMINTOOL_0038 "値"
	#define STRMSG_S_SCADMINTOOL_0039 "アカウントブロックを解除しますか？"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d秒)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d勝 %d敗"
	#define STRMSG_S_SCADMINTOOL_0042 "このアカウントの接続を切断してブロックしますか？"
	#define STRMSG_S_SCADMINTOOL_0043 "%sｱｲﾃﾑ"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s%15s]お知らせ:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "ﾕ-ｻﾞ-数:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s%15s]受信したﾒｯｾ-ｼﾞ:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s%15s]ユ-ザ-数:%4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s%15s]FieldServer state:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "ｻ-ﾊﾞ-との接続が終了しました。\nSocket Name:%s\nIP:%s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "該当アカウント情報を読み込めません。"
	#define STRERR_S_SCADMINTOOL_0001 "アカウント情報の変更に失敗しました。"
	#define STRERR_S_SCADMINTOOL_0002 "ﾊﾟｽﾜ-ﾄﾞを入力してください。"
	#define STRERR_S_SCADMINTOOL_0003 "ﾊﾟｽﾜ-ﾄﾞが間違っています。"
	#define STRERR_S_SCADMINTOOL_0004 "IDを入力してください。"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Serverが実行していません。"
	#define STRERR_S_SCADMINTOOL_0006 "Can not connect to PreServer !!"
//	#define STRERR_S_SCADMINTOOL_0007 "認証に失敗しました。"			// 2006-04-11 by cmkwon, ?????
	#define STRERR_S_SCADMINTOOL_0008 "ERROR:該当プロトコルが存在しません。"
	#define STRERR_S_SCADMINTOOL_0009 "IDを入力してください。"
	#define STRERR_S_SCADMINTOOL_0010 "理由を入力してください。"
	#define STRERR_S_SCADMINTOOL_0011 "経験値設定ｴﾗ-:Level%2d==>Exp(%.1I64f?%.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "最大ログ数を超過しました。\r\n\r\n最大ログ数や検索条件を修正してください。"
	#define STRERR_S_SCADMINTOOL_0013 "Databaseに接続できません。"
	#define STRERR_S_SCADMINTOOL_0014 "接続失敗"
	#define STRERR_S_SCADMINTOOL_0015 "接続成功"
	#define STRERR_S_SCADMINTOOL_0016 "ｱｯﾌﾟﾃﾞ-ﾄ中"
	#define STRERR_S_SCADMINTOOL_0017 "ログイン成功"
	#define STRERR_S_SCADMINTOOL_0018 "ｷｬﾗｸﾀ-選択中"
	#define STRERR_S_SCADMINTOOL_0019 "ｹﾞ-ﾑ中"
	#define STRERR_S_SCADMINTOOL_0020 "不明"
	#define STRERR_S_SCADMINTOOL_0021 "Database%s(%s:%d)に接続できません。"
	#define STRERR_S_SCADMINTOOL_0022 "ｱｲﾃﾑ追加失敗"
	#define STRERR_S_SCADMINTOOL_0023 "ブロックアカウントが見つかりませんでした。"
	#define STRERR_S_SCADMINTOOL_0024 "修正のため該当アカウントの接続を切断し、アカウントをブロックしてください！"
	#define STRERR_S_SCADMINTOOL_0025 "SPIは追加できません。"
	#define STRERR_S_SCADMINTOOL_0026 "選択したｱｲﾃﾑは既に存在しています。個数を修正してください。"
	#define STRERR_S_SCADMINTOOL_0027 "ｱｲﾃﾑ検索ｴﾗ-"
	#define STRERR_S_SCADMINTOOL_0028 "ｷｬﾗｸﾀ-が所有しているSPIは削除できません。"
	#define STRERR_S_SCADMINTOOL_0029 "ｱｲﾃﾑを削除しますか？"
	#define STRERR_S_SCADMINTOOL_0030 "ｱｲﾃﾑの削除に失敗しました。"
	#define STRERR_S_SCADMINTOOL_0031 "ｱｲﾃﾑの修正に失敗しました。"
	#define STRERR_S_SCADMINTOOL_0032 "アカウントを入力してください。"
	#define STRERR_S_SCADMINTOOL_0033 "アカウントが存在しません。(アカウントブロック設定は可?)"
	#define STRERR_S_SCADMINTOOL_0034 "アカウントまたはｷｬﾗｸﾀ-が存在していません。"
	#define STRERR_S_SCADMINTOOL_0035 "ｷｬﾗｸﾀ-情報照会ｴﾗ-です。"
	#define STRERR_S_SCADMINTOOL_0036 "該当ｷｬﾗｸﾀ-存在していません。"
	#define STRERR_S_SCADMINTOOL_0037 "ｷｬﾗｸﾀ-ｱｯﾌﾟﾃﾞ-ﾄｴﾗ-です。"
	#define STRERR_S_SCADMINTOOL_0038 "ｷｬﾗｸﾀ-情報のｱｯﾌﾟﾃﾞ-ﾄに成功しました。"
	#define STRERR_S_SCADMINTOOL_0039 "ｱｲﾃﾑを選択してください。"
	#define STRERR_S_SCADMINTOOL_0040 "ｱｲﾃﾑ個数を選択してください。"
	#define STRERR_S_SCADMINTOOL_0041 "該当ｱｲﾃﾑは5個以下のみ作成できます。"
	#define STRERR_S_SCADMINTOOL_0042 "ﾒｯｾ-ｼﾞを入力してください。"
	#define STRERR_S_SCADMINTOOL_0043 "お知らせを送信できません。"
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Serverが実行されていません。"
	#define STRERR_S_SCADMINTOOL_0046 "Field Serverが実行されていません。"
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ﾆﾄﾆｮｳﾊ - ｾ?ﾑ蟷ﾎ ﾅ・ﾆﾄﾆｮｳﾊ ｱ箒ﾉｿ｡ｼｭ ｻ鄙・ﾇｴﾂ MSG
	#define STRERR_S_SCADMINTOOL_0048 "ﾆﾄﾆｮｳﾊｿ｡ ﾀ蠶?ｵﾈ ｼﾒﾄﾏ ｾﾆﾀﾌﾅﾛ ﾀﾔｴﾏｴﾙ.\nｼﾒﾄﾏﾀﾌ ﾀ蠶?ｵﾈ ﾆﾄﾆｮｳﾊ ｼﾓｼｺﾃ｢ｿ｡ｼｭ ｻ霖ｦｰ｡ ｰ｡ｴﾉﾇﾕｴﾏｴﾙ."
	#define STRERR_S_SCADMINTOOL_0049 "ﾆﾄﾆｮｳﾊｼﾓｼｺ ｺｯｰ貊酩ﾗ Logﾀ?ﾀ蠡ﾌ ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ.\r\n(ﾆﾄﾆｮｳﾊ ｼﾓｼｺ ｺｯｰ貘ｺ ｿﾏｷ盞ﾊ, Logｸｸ ﾀ?ﾀ・ｽﾇﾆﾐ.)"
	#define STRERR_S_SCADMINTOOL_0050 "ﾆﾄﾆｮｳﾊ ﾁ､ｺｸ ｷﾎｵ?ﾀﾌ ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ"
	#define STRERR_S_SCADMINTOOL_0051 "ﾀ蠶?ﾁﾟﾀﾎ ｼﾒﾄﾏ ｾﾆﾀﾌﾅﾛ ｻ霖ｦｰ｡ ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ."
	#define STRERR_S_SCADMINTOOL_0052 "ﾀ蠶?ﾇﾒ ｼﾒﾄﾏ ｾﾆﾀﾌﾅﾛﾀﾇ ﾇﾏﾀﾌｵ・ｿﾉｼﾇ ﾀ?ｿ・?ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ."
	#define STRERR_S_SCADMINTOOL_0053 "ﾆﾄﾆｮｳﾊ ｼﾒﾄﾏ ｾﾆﾀﾌﾅﾛﾀﾇ ｼ?ﾁ､ﾀﾌ ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ."
	#define STRERR_S_SCADMINTOOL_0054 "ﾆﾄﾆｮｳﾊ ﾁ､ｺｸ ｾ?ｵ･ﾀﾌﾆｮｰ｡ ｽﾇﾆﾐ ｵﾇｾ?ｽﾀｴﾏｴﾙ"
	#define STRERR_S_SCADMINTOOL_0055 "ﾆﾄﾆｮｳﾊｷｹｺｧ ﾁ､ｺｸ ｷﾎｵ?ﾀﾌ ｽﾇﾆﾐｵﾇｾ?ｽﾀｴﾏｴﾙ"

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ｿ?ﾛｵﾅ?ｱ箒ﾉﾃﾟｰ｡, ﾀﾎﾃｦﾆｮｾﾆﾀﾌﾅﾛﾁｦｰﾅｱ箒ﾉ
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ｿ?ﾛｵﾅ?ｱ箒ﾉﾃﾟｰ｡, ﾀﾎﾃｦﾆｮｾﾆﾀﾌﾅﾛﾁｦｰﾅｱ箒ﾉ. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "アカウントID"
//	#define STRMSG_S_SCAT_COLNAME_0001 "ﾀｲﾌﾟ"
//	#define STRMSG_S_SCAT_COLNAME_0002 "前科"
//	#define STRMSG_S_SCAT_COLNAME_0003 "開始日"
//	#define STRMSG_S_SCAT_COLNAME_0004 "終了日"
//	#define STRMSG_S_SCAT_COLNAME_0005 "処理者"
//	#define STRMSG_S_SCAT_COLNAME_0006 "処理理由"
//	#define STRMSG_S_SCAT_COLNAME_0007 "日時"
//	#define STRMSG_S_SCAT_COLNAME_0008 "ﾛｸﾞﾀｲﾌﾟ"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "ｻ-ﾊﾞ-名"
//	#define STRMSG_S_SCAT_COLNAME_0011 "ｷｬﾗｸﾀ-ﾈ-ﾑ"
//	#define STRMSG_S_SCAT_COLNAME_0012 "位置"
//	#define STRMSG_S_SCAT_COLNAME_0013 "内容"
//	#define STRMSG_S_SCAT_COLNAME_0014 "ｱｲﾃﾑ"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "固有番号"
//	#define STRMSG_S_SCAT_COLNAME_0017 "名前"
//	#define STRMSG_S_SCAT_COLNAME_0018 "ｱｲﾃﾑ番号"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "装備"
//	#define STRMSG_S_SCAT_COLNAME_0022 "個数"
//	#define STRMSG_S_SCAT_COLNAME_0023 "耐久度"
//	#define STRMSG_S_SCAT_COLNAME_0024 "作成時間"
	#define STRMSG_S_SCAT_COLNAME_0025 "未装備"
//	#define STRMSG_S_SCAT_COLNAME_0026 "倉庫"
//	#define STRMSG_S_SCAT_COLNAME_0027 "オ-クション"
//	#define STRMSG_S_SCAT_COLNAME_0028 "ﾏｯﾌﾟ"
//	#define STRMSG_S_SCAT_COLNAME_0029 "座標"
//	#define STRMSG_S_SCAT_COLNAME_0030 "性別"
//	#define STRMSG_S_SCAT_COLNAME_0031 "種族"
//	#define STRMSG_S_SCAT_COLNAME_0032 "権限"
//	#define STRMSG_S_SCAT_COLNAME_0033 "ユニット種類"
//	#define STRMSG_S_SCAT_COLNAME_0034 "レベル"
//	#define STRMSG_S_SCAT_COLNAME_0035 "最高レベル"
//	#define STRMSG_S_SCAT_COLNAME_0036 "経験値"
//	#define STRMSG_S_SCAT_COLNAME_0037 "減少した経験値"
//	#define STRMSG_S_SCAT_COLNAME_0038 "自動分配ｽﾃ-ﾀｽﾀｲﾌﾟ"
//	#define STRMSG_S_SCAT_COLNAME_0039 "攻撃パ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0040 "防御パ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0041 "燃料パ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0042 "精神パ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0043 "シ-ルドパ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0044 "回避パ-ト"
//	#define STRMSG_S_SCAT_COLNAME_0045 "所属旅団"
//	#define STRMSG_S_SCAT_COLNAME_0046 "性向"
//	#define STRMSG_S_SCAT_COLNAME_0047 "身分"
//	#define STRMSG_S_SCAT_COLNAME_0048 "総接続時間"
//	#define STRMSG_S_SCAT_COLNAME_0049 "作成時間"
//	#define STRMSG_S_SCAT_COLNAME_0050 "最終接続時間"
//	#define STRMSG_S_SCAT_COLNAME_0051 "種類"
//	#define STRMSG_S_SCAT_COLNAME_0052 "全体"
	#define STRMSG_S_SCAT_COLNAME_0053 "ｵ-ﾄﾏﾁｯｸ類(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0054 "バルカン類(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0055 "デュアルリスト類(1-1?)" // 2005-08-01 by hblee : ????? -> ??リスト? 変更.
	#define STRMSG_S_SCAT_COLNAME_0056 "キャノン類(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0057 "ライフル類(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0058 "ガトリング類(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0059 "ﾗﾝﾁｬ-類(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0060 "ﾏｽﾄﾞﾗｲﾌ類(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0061 "ロケット類(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0062 "ﾐｻｲﾙ類(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0063 "バンドル類(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0064 "ﾏｲﾝ類(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0065 "ｼ-ﾙﾄﾞ類(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0066 "ﾀﾞﾐ-類(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0067 "ﾋﾟｸｻ-類(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0068 "デコイ類(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0069 "防御類"
	#define STRMSG_S_SCAT_COLNAME_0070 "補助装備類"
	#define STRMSG_S_SCAT_COLNAME_0071 "ｴﾈﾙｷﾞ-類"
	#define STRMSG_S_SCAT_COLNAME_0072 "金属類"
	#define STRMSG_S_SCAT_COLNAME_0073 "ｶ-ﾄﾞ類"
	#define STRMSG_S_SCAT_COLNAME_0074 "ｴﾝﾁｬﾝﾄ類"
	#define STRMSG_S_SCAT_COLNAME_0075 "ﾀﾝｸ類"
	#define STRMSG_S_SCAT_COLNAME_0076 "弾丸類"
	#define STRMSG_S_SCAT_COLNAME_0077 "ﾐｯｼｮﾝ用"
	#define STRMSG_S_SCAT_COLNAME_0078 "ﾚ-ﾀﾞ-類"
	#define STRMSG_S_SCAT_COLNAME_0079 "ｺﾝﾋﾟｭ-ﾀ-類"
	#define STRMSG_S_SCAT_COLNAME_0080 "ｷﾞｬﾝﾌﾞﾙｶ-ﾄﾞ類"
	#define STRMSG_S_SCAT_COLNAME_0081 "ｴﾝﾁｬﾝﾄ破壊防止類"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "ﾌﾞﾗｽﾀ-類"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "ﾚ-ﾙｶﾞﾝ類"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "全体ｱｲﾃﾑ"
//	#define STRMSG_S_SCAT_COLNAME_0082 "全体ｻ-ﾊﾞ-"
//	#define STRMSG_S_SCAT_COLNAME_0083 "ｻ-ﾊﾞ-名"
//	#define STRMSG_S_SCAT_COLNAME_0084 "ｻ-ﾊﾞ-種類"
//	#define STRMSG_S_SCAT_COLNAME_0085 "ｻ-ﾊﾞ-IP、Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "現在ﾕ-ｻﾞ-数"
//	#define STRMSG_S_SCAT_COLNAME_0087 "ｻ-ﾊﾞ-状態"
//	#define STRMSG_S_SCAT_COLNAME_0088 "ｸﾞﾙ-ﾌﾟｻ-ﾊﾞ-"
//	#define STRMSG_S_SCAT_COLNAME_0089 "ﾌｨ-ﾙﾄﾞｻ-ﾊﾞ-"
//	#define STRMSG_S_SCAT_COLNAME_0090 "不明"
//	#define STRMSG_S_SCAT_COLNAME_0091 "実行失敗"
//	#define STRMSG_S_SCAT_COLNAME_0092 "正常"
//	#define STRMSG_S_SCAT_COLNAME_0093 "非正常"
	#define STRMSG_S_SCAT_COLNAME_0094 "運営者"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10))+'個, Param1:'+CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////	
	
	
///////////////////////////////////////////////////////////////////////////////	
// 4	
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "命令語リスト\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "-----バックアップしたアカウントリスト ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "アカウント:\'%s\'、設定PW:\'%s\'、臨時PW:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "アカウント:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0004 "ｱｯﾌﾟﾃﾞ-ﾄ用Versionが入っているﾌｫﾙﾀﾞを選択してください"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "ﾌｧｲﾙの作成に成功しました。\r\n\r\nDB 情報:%s(%d)、%s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d-活性)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d-非活性)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "サ-バデ-タのリロ-ドに成功しました。"
//	#define STRMSG_S_SCMONITOR_0011 "サ-ビス状態の反映に成功しました。"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d-活性)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d-非活性)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "フリ-サ-バサ-ビスが中?しました。"
//	#define STRMSG_S_SCMONITOR_0017 "フリ-サ-バサ-ビスが開始しました。"
//	#define STRMSG_S_SCMONITOR_0018 "ﾌｨ-ﾙﾄﾞｻ-ﾊﾞ-が実行されていません。"
//	#define STRMSG_S_SCMONITOR_0019 "本当にField Serverを終了しますか？"
//	#define STRMSG_S_SCMONITOR_0020 "ｱｯﾌﾟﾃﾞ-ﾄﾊﾞ-ｼﾞｮﾝﾘｽﾄ情報(最大1492 Bytes)\r\n\r\nﾊﾞ-ｼﾞｮﾝﾘｽﾄ個数[%3d]、ﾃﾞ-ﾀｻｲｽﾞ [%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "本当にPre Serverを終了しますか？"
//	#define STRMSG_S_SCMONITOR_0022 "本当にIM Serverを終了しますか？"
//	#define STRMSG_S_SCMONITOR_0023 "本当にNPC Serverを終了しますか？"
//	#define STRMSG_S_SCMONITOR_0024 "%Y年%m月%d日%H時%M分%S秒"
//	#define STRMSG_S_SCMONITOR_0025 "イベントなし(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "オ-プンベ-タ出席イベント(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "イベント不明(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "次の占領戦設定時間"
//	#define STRMSG_S_SCMONITOR_0029 "次の占領戦基?時間"
//	#define STRMSG_S_SCMONITOR_0030 "占領旅団"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "==>命令語が成功しました。\r\n"
//	#define STRERR_S_SCMONITOR_0001 "==>命令語が失敗しました。\r\n"
//	#define STRERR_S_SCMONITOR_0002 "DBに接続できません。"
//	#define STRERR_S_SCMONITOR_0003 "該当Versionが存在していません。"
//	#define STRERR_S_SCMONITOR_0004 "圧縮するﾌｫﾙﾀﾞ名を入力してください"
//	#define STRERR_S_SCMONITOR_0005 "出力するﾌｫﾙﾀﾞ名を入力してください"
//	#define STRERR_S_SCMONITOR_0006 "開始ﾊﾞ-ｼﾞｮﾝを入力してください。"
//	#define STRERR_S_SCMONITOR_0007 "最後のﾊﾞ-ｼﾞｮﾝを入力してください。"
//	#define STRERR_S_SCMONITOR_0008 "ｱｯﾌﾟﾃﾞ-ﾄ用Zipﾌｧｲﾙを出力するﾌｫﾙﾀﾞを選択してください"
//	#define STRERR_S_SCMONITOR_0009 "ﾌｧｲﾙを連結できません"
//	#define STRERR_S_SCMONITOR_0010 "ｻ-ﾊﾞ-を選択してください！"
//	#define STRERR_S_SCMONITOR_0011 "DBに連結できません"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type:%s(%#04x)in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "ｱｯﾌﾟﾃﾞ-ﾄﾊﾞ-ｼﾞｮﾝﾘｽﾄが長すぎます。(ﾊﾞ-ｼﾞｮﾝﾘｽﾄ個数[%3d]、ﾃﾞ-ﾀｻｲｽﾞ[%4dBytes])\r\n\r\nﾊﾞ-ｼﾞｮﾝﾘｽﾄを整理しなくてはなりません。"
//	#define STRERR_S_SCMONITOR_0014 "除去された??です。\r\n管理ﾂ-ﾙを利用してください。"
//	#define STRERR_S_SCMONITOR_0015 "都市占領戦ﾏｯﾌﾟではありません"
//	#define STRERR_S_SCMONITOR_0016 "EDITｺﾝﾄﾛ-ﾙを作成できません。"
//	#define STRERR_S_SCMONITOR_0017 "既に存在するﾌｧｲﾙを登録しました。"

// 4_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Log Serverに接続しました。\r\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error]WndProc(),Can't connect to PreServer[%15s:%4d]Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Pre Serverに接続しました。\r\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY:%s(%#04x)\r\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Pre Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(),Can't connect to  IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "IM Serverに接続しました。\r\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY:%s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries!%d\r\n"
	#define STRMSG_S_F2DBQUERY_0001 "該当ｱｲﾃﾑが存在していません。"
	#define STRMSG_S_F2DBQUERY_0002 "'%s'様は出席申し込みをしたため、約束したｱｲﾃﾑを"
	#define STRMSG_S_F2DBQUERY_0003 "支給します。インベントリを確認してください"
	#define STRMSG_S_F2DBQUERY_0004 "スキル%s(%d)が追加されました。"
	#define STRMSG_S_F2DBQUERY_0005 "該当ｱｲﾃﾑが存在していません。"
	#define STRMSG_S_F2DBQUERY_0006 "ｱｲﾃﾑ購入に失敗しました。"

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  都市占領戦開始:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  参加旅団:GuildUID(%4d) GuildName(%10s)GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  都市占領戦ﾓﾝｽﾀ-爆発:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		 ﾀﾞﾒ-ｼﾞﾄ-ﾀﾙ==>GuildName(%10s)SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  都市占領戦:%d(%10s)CityMapIndex(%d)QuestIndex(%d)OccGuildID(%d)OccGuildName(%s) OccGuildMasterUID(%d)占領戦時間(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d分後\"%s\"都市占領戦が開始します。"
	#define STRMSG_S_F2CITYWAR_0007 "%d分後\"%s\"都市占領戦が終了します。"
	#define STRMSG_S_F2CITYWAR_0008 "都市占領戦(%s)ﾓﾝｽﾀ-召喚:NPC占領"
	#define STRMSG_S_F2CITYWAR_0009 "都市占領戦(%s)ﾓﾝｽﾀ-召喚:%s旅団占領"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"が\"%s\"を占領しました。"
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"旅団が\"%s\"を占領しました。"

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "ﾐｯｼｮﾝロ-ディング失敗"
	#define STRMSG_S_F2QUEST_0001 "ﾐｯｼｮﾝのロ-ディングに失敗しました。\r\n"
//	#define STRMSG_S_F2QUEST_0002 "ﾐｯｼｮﾝ\'%30s\'番号%d->OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "テスト用サ-バセッティング完了！ \r\n\r\nLoadFieldServerDataDebug()除去をお願い！"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d:%dに%5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d:%sに%5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "基?"
	#define STRMSG_S_F2NOTIFY_0003 "特殊"
	#define STRMSG_S_F2NOTIFY_0004 "ﾓﾝｽﾀ-1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "ﾓﾝｽﾀ-2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "武器の種類が間違いました。管理者に問い合わせをしてください。"
	#define STRMSG_S_F2NOTIFY_0007 "1-1?:%4.1f vs %4.1f->命中率 %2.2f%% 減少"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s失敗、確率(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s失敗、確率(%d>%5.2f)-%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s失敗、確率(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2?:%4.1f vs %4.1f->?メ?ジ%2.2f%%減少(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%sに%5.2f(%5.2f-%d/255)渡す(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%sから%5.2f(%5.2f-%d/255) もらう。(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d,HP:%5.2f)に%5.2f(%5.2f-%d/255)渡す(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%sから%5.2f(%5.2f-%d/255)もらう(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "???失敗:確率不足>%d"
	#define STRMSG_S_F2NOTIFY_0017 "残り???[%#08x]:%5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "銃弾情報がありません。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0019 "銃弾の口径情報が存在していません。%s%d"
	#define STRMSG_S_F2NOTIFY_0020 "銃弾の情報です。%s%d"
	#define STRMSG_S_F2NOTIFY_0021 "既にイベントが処理中のため、ワ-プできません。"
	#define STRMSG_S_F2NOTIFY_0022 "死亡しているためワ-プできません。"
	#define STRMSG_S_F2NOTIFY_0023 "編隊戦中のためワ-プできません。"
	#define STRMSG_S_F2NOTIFY_0024 "ﾏｯﾌﾟ制作エラ-！管理者にお問い合わせください！"
	#define STRMSG_S_F2NOTIFY_0025 "ﾏｯﾌﾟ制作エラ-！管理者にお問い合わせください！%dに%dのウィ?フ??ゲットインデックスがない！\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "編隊戦中のためワ-プできません。"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d)処理不可at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1->ｷｬﾗｸﾀ-%10sからﾀﾞﾒ-ｼﾞ%5.2fを受けました"
	#define STRMSG_S_F2NOTIFY_0029 "1->ｷｬﾗｸﾀ-%10sにﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0030 "1->ｷｬﾗｸﾀ-%10sにﾀﾞﾒ-ｼﾞ %5.2fを ?えました"
	#define STRMSG_S_F2NOTIFY_0031 "1->ｷｬﾗｸﾀ-%10sに???ﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0032 "2->ｷｬﾗｸﾀ-%10sからﾀﾞﾒ-ｼﾞ%5.2fを受けました"
	#define STRMSG_S_F2NOTIFY_0033 "2->ｷｬﾗｸﾀ-%10sにﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0034 "2->ﾓﾝｽﾀ-%3dにﾀﾞﾒ-ｼﾞ%5.2f(%d)を?えました"
	#define STRMSG_S_F2NOTIFY_0035 "2->ｷｬﾗｸﾀ-%10sにﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0036 "2->ｷｬﾗｸﾀ-%10sに???ﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0037 "2->ﾓﾝｽﾀ-%3dからﾀﾞﾒ-ｼﾞ%5.2fを受けました"
	#define STRMSG_S_F2NOTIFY_0038 "MINE->ｷｬﾗｸﾀ-%10sにﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0039 "MINE->ｷｬﾗｸﾀ-%10sに???ﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0040 "MINE->ﾓﾝｽﾀ-%10sにﾀﾞﾒ-ｼﾞ%5.2fを?えました"
	#define STRMSG_S_F2NOTIFY_0041 "ｽﾃ-ﾀｽ初期化に成功しました。"
	#define STRMSG_S_F2NOTIFY_0042 "死亡したときには使用できません"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFOなし"
	#define STRMSG_S_F2NOTIFY_0044 "ｴﾝﾁｬﾝﾄに成功しました"
	#define STRMSG_S_F2NOTIFY_0045 "ｴﾝﾁｬﾝﾄに失敗しました"
	#define STRMSG_S_F2NOTIFY_0046 "旅団に所属していません。"
	#define STRMSG_S_F2NOTIFY_0047 "既に申し込み待機中です。"
	#define STRMSG_S_F2NOTIFY_0048 "しばらく後で再実行してください。"
	#define STRMSG_S_F2NOTIFY_0049 "自分か相手が旅団長ではありません。"
	#define STRMSG_S_F2NOTIFY_0050 "既に旅団戦中です。"
	#define STRMSG_S_F2NOTIFY_0051 "両方の旅団長が同じﾏｯﾌﾟに存在していません。"
	#define STRMSG_S_F2NOTIFY_0052 "全編隊メンバ-が同じﾏｯﾌﾟに入っていません。"
	#define STRMSG_S_F2NOTIFY_0053 "全編隊メンバ-が同じﾏｯﾌﾟに入っていません。"
	#define STRMSG_S_F2NOTIFY_0054 "旅団に所属していません。"
	#define STRMSG_S_F2NOTIFY_0055 "申し込み者と被?し込み者が違います。"
	#define STRMSG_S_F2NOTIFY_0056 "自分か相手が旅団長ではありません。"
	#define STRMSG_S_F2NOTIFY_0057 "両方の旅団長が同じﾏｯﾌﾟに存在していません。"
	#define STRMSG_S_F2NOTIFY_0058 "旅団に所属していません。"
	#define STRMSG_S_F2NOTIFY_0059 "申し込み者と被申し込み者が違います。"
	#define STRMSG_S_F2NOTIFY_0060 "自分か相手が旅団長ではありません。"
	#define STRMSG_S_F2NOTIFY_0061 "都市占領戦防御に成功しました。"
	#define STRMSG_S_F2NOTIFY_0062 "ﾐｯｼｮﾝ設定エラ-です。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0063 "この位置では該当ｱｲﾃﾑ(%s)を装備できません"
	#define STRMSG_S_F2NOTIFY_0064 "エンジンのスロットは空けることができません。"
	#define STRMSG_S_F2NOTIFY_0065 "ｱｲﾃﾑ移動:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0066 "間違っているｱｲﾃﾑ移動:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d)処理不可at Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "ﾏｯﾌﾟｲﾍﾞﾝﾄ情報異常！管理者にお問い合わせください！！"
	#define STRMSG_S_F2NOTIFY_0069 "該当ワ-プ??ゲットがない"
	#define STRMSG_S_F2NOTIFY_0070 "ｱｲﾃﾑ購入エラ-です。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0071 "購入するスキルレベルが既存スキルのレベルより低いか同じです。"
	#define STRMSG_S_F2NOTIFY_0072 "スキル購入のためにはｱｲﾃﾑが必要です。"
	#define STRMSG_S_F2NOTIFY_0073 "ｱｲﾃﾑ販売ｴﾗ-です。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0074 "ｱｲﾃﾑ購入ｴﾗ-です。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0075 "\'ﾘｵｺｲﾝｱｲﾃﾑ\'を購入しました。"
	#define STRMSG_S_F2NOTIFY_0076 "購入リスト:\'%s(%d個)\'"
	#define STRMSG_S_F2NOTIFY_0077 "既に編隊に加入しています。"
	#define STRMSG_S_F2NOTIFY_0078 "あなたは編隊長なのできません"
	#define STRMSG_S_F2NOTIFY_0079 "編隊戦が進行中のため加入できません。"
	#define STRMSG_S_F2NOTIFY_0080 "全編隊メンバ-の情報を受け取ることはできません！"
	#define STRMSG_S_F2NOTIFY_0081 "ﾏｯﾌﾟｲﾍﾞﾝﾄ情報異常！管理者にお問い合わせください！！"
	#define STRMSG_S_F2NOTIFY_0082 "取り引きできないアカウントです。"
	#define STRMSG_S_F2NOTIFY_0083 "%s様は積載量超過です。"
	#define STRMSG_S_F2NOTIFY_0084 "移動可?座標:(5, 5)->(%d,%d)"
	#define STRMSG_S_F2NOTIFY_0085 "ﾌﾟﾚｲﾔ-:"
	#define STRMSG_S_F2NOTIFY_0086 "最大20人まで見ることができます"
	#define STRMSG_S_F2NOTIFY_0087 "該当ﾌﾟﾚｲﾔ-(%s)がいません"
	#define STRMSG_S_F2NOTIFY_0088 "編隊に所属していません"
	#define STRMSG_S_F2NOTIFY_0089 "現在時間:%d:%d、アト?時間:%d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "変更時間:%d:%d、アト?時間:%d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "NPCｻ-ﾊﾞ-に接続していません"
	#define STRMSG_S_F2NOTIFY_0092 "該当ｱｲﾃﾑ(%d)が存在していません"
	#define STRMSG_S_F2NOTIFY_0093 "Countable Itemじゃない場合は10個に制限されます"
	#define STRMSG_S_F2NOTIFY_0094 "ﾏｯﾌﾟ\'%s\'の全体接続者:%d人"
	#define STRMSG_S_F2NOTIFY_0095 "ﾏｯﾌﾟ%s%s同時接続者:%d人-'%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "ﾏｯﾌﾟ%s%s同時接続者:%d人-'%s'"
	#define STRMSG_S_F2NOTIFY_0097 "現在ﾏｯﾌﾟﾁｬﾝﾈﾙ:%s、%d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "銃弾情報がありません。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0099 "銃弾の口径情報が存在しません。%s%d"
	#define STRMSG_S_F2NOTIFY_0100 "銃弾情報がありません。管理者にお問い合わせください。"
	#define STRMSG_S_F2NOTIFY_0101 "銃弾の口径情報が存在していません。%s%d"
	#define STRMSG_S_F2NOTIFY_0102 "該当ﾌﾟﾚｲﾔ-(%s)がいません"
	#define STRMSG_S_F2NOTIFY_0103 "該当ﾌﾟﾚｲﾔ-(%s)は?んでいます"
	#define STRMSG_S_F2NOTIFY_0104 "該当ﾌﾟﾚｲﾔ-(%s)がいません"
	#define STRMSG_S_F2NOTIFY_0105 "一般アカウントに設定しました"
	#define STRMSG_S_F2NOTIFY_0106 "一般アカウントが解除されました"
	#define STRMSG_S_F2NOTIFY_0107 "無敵(ﾀﾞﾒ-ｼﾞを受けない)ユニットに設定しました"
	#define STRMSG_S_F2NOTIFY_0108 "無敵(ﾀﾞﾒ-ｼﾞを受けない)ユニット設定が解除されました"
	#define STRMSG_S_F2NOTIFY_0109 "武器が%5.0f%%のあり得ない性能を持ちました"
	#define STRMSG_S_F2NOTIFY_0110 "ｱｲﾃﾑ再装填時初期化されます"
	#define STRMSG_S_F2NOTIFY_0111 "ｱｲﾃﾑ再装填時初期化されます"
	#define STRMSG_S_F2NOTIFY_0112 "該当ﾌﾟﾚｲﾔ-(%s)がいません"
	#define STRMSG_S_F2NOTIFY_0113 "透明状態が解除されました"
	#define STRMSG_S_F2NOTIFY_0114 "透明状態が活性化しました"
	#define STRMSG_S_F2NOTIFY_0115 "%sイベントが進行中ではありません"
	#define STRMSG_S_F2NOTIFY_0116 "%sイベントが開始(?率:%4.2f、イベント時間:%3d分)"
	#define STRMSG_S_F2NOTIFY_0117 "一般ﾌﾟﾚﾐｱﾑｱｶｳﾝﾄに設定されました"
	#define STRMSG_S_F2NOTIFY_0118 "ﾌﾟﾚﾐｱﾑｱｶｳﾝﾄ設定に失敗しました"
	#define STRMSG_S_F2NOTIFY_0119 "ｽ-ﾊﾟ-ﾌﾟﾚﾐｱﾑｱｶｳﾝﾄに設定されました"
	#define STRMSG_S_F2NOTIFY_0120 "都市占領戦ﾏｯﾌﾟではありません"
	#define STRMSG_S_F2NOTIFY_0121 "都市占領戦を開始できません"
	#define STRMSG_S_F2NOTIFY_0122 "都市占領戦を終了できません"
	#define STRMSG_S_F2NOTIFY_0123 "透明状態が初期化されました"
	#define STRMSG_S_F2NOTIFY_0124 "透明状態になりました"
	#define STRMSG_S_F2NOTIFY_0125 "ﾏｯﾌﾟが無効です。"
	#define STRMSG_S_F2NOTIFY_0126 "HappyHourに設定[進行時間:%4d分)]"
	#define STRMSG_S_F2NOTIFY_0127 "HappyHour終了"
	#define STRMSG_S_F2NOTIFY_0128 "基?->ﾓﾝｽﾀ-%3dからﾀﾞﾒ-ｼﾞ%5.2fを受けました"
	#define STRMSG_S_F2NOTIFY_0129 "基?->ﾓﾝｽﾀ-%3dからﾀﾞﾒ-ｼﾞ%5.2fを受けました(???)"
	#define STRMSG_S_F2NOTIFY_0130 "%s権限として接続しました"
	#define STRMSG_S_F2NOTIFY_0131 "終了ル-ティンを処理しない?%s:CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine():編隊メンバ-除去失敗！%s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix\'%s\'成功:%d<=%d<=%d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix\'%s\'成功:%d<=%d<=%d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s:中?！"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR:管理者にお問い合わせください！ショップ変数割り当てエラ-?！"
	#define STRMSG_S_F2NOTIFY_0137 "%sが削除されました。"
	#define STRMSG_S_F2NOTIFY_0138 "現在の?ャンネルは非活性化のためモﾓﾝｽﾀ-およびその他??が"
	#define STRMSG_S_F2NOTIFY_0139 "停?します。ほかのﾁｬﾝﾈﾙを利用してください。"
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2d個]:%04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "?イ??動作%s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HP自動回復を中?します"
	#define STRMSG_S_F2NOTIFY_0143 "着陸可能地域ではないため、HP自動回復を中?します"
	#define STRMSG_S_F2NOTIFY_0144 "応?によるHP5.2f回復"
	#define STRMSG_S_F2NOTIFY_0145 "Gradual HP UP 中?(残り時間:%d)"
	#define STRMSG_S_F2NOTIFY_0146 "Gradual DP UP 中?(残り時間:%d)"
	#define STRMSG_S_F2NOTIFY_0147 "Gradual EP UP 中?(残り時間:%d)"
	#define STRMSG_S_F2NOTIFY_0148 "%sイベントが終了しました。"
	#define STRMSG_S_F2NOTIFY_0149 "%sイベント進行中(?率:%4.2f,残り時間:%3d分)"
	#define STRMSG_S_F2NOTIFY_0150 "命令後が実行されていません"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	経験値分配エラ-(%s,%s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "無効Game Startﾒｯｾ-ｼﾞｴﾗ-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "無効Game Start ﾒｯｾ-ｼﾞｴﾗ-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d)処理不可at ProcessQuestResult(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "ﾏｯﾌﾟｲﾍﾞﾝﾄ情報異常！管理者にお問い合わせください！！Current(%s,%s,%04d),Target(%04d,%d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d)処理不可at T_FC_PARTY_REQUEST_PARTY_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "ﾏｯﾌﾟｲﾍﾞﾝﾄ情報異常！管理者にお問い合わせください！！Current(%s,%s,%04d),Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP処理不可at T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d)処理不可(編隊長)at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) 処理不可at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) 処理不可at Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP 処理不可at T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "編隊ワ-プ失敗:%s->距離:%5.2f, bodycon: %d,%d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) 処理不可at Process_FC_CHARACTER_DEAD_GAMESTART(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s->OK??ンクリック重複！\r\n"
	#define STRERR_S_F2NOTIFY_0015 "ﾐｯｼｮﾝがロ-ディングされていません。\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s)処理不可 at HandleAdminCommands(),/移動,%s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s)処理不可 at HandleAdminCommands(),/送信,%s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATAL ERROR:該当メンバ-が入っていないﾌｨ-ﾙﾄﾞｻ-ﾊﾞ-には、このメッセ-ジが送信されてはいけません。check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d)処理不可at T_FI_ADMIN_CALL_CHARACTER,%s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s)処理不可at T_FI_ADMIN_MOVETO_CHARACTER,%s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "経験値"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "経験値復旧"
	#define STRMSG_S_F2EVENTTYPE_0003 "ｱｲﾃﾑﾄﾞﾛｯﾌﾟ"
	#define STRMSG_S_F2EVENTTYPE_0004 "ﾚｱｱｲﾃﾑﾄﾞﾛｯﾌﾟ"
	#define STRMSG_S_F2EVENTTYPE_0005 "イベント不明"
// 5_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Pre Serverに接続しました。\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Pre Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'は既に存在している旅団名です。"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'は既に旅団に加入しています。"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'は既に存在する旅団名です。"
	#define STRMSG_S_I2NOTIFY_0003 "旅団ロ-ディング失敗-管理者にお問い合わせください！"
	#define STRMSG_S_I2NOTIFY_0004 "友達'%s'様がログインしました。"
	#define STRMSG_S_I2NOTIFY_0005 "以前の編隊を確認します"
	#define STRMSG_S_I2NOTIFY_0006 "既存の編隊が存在していません"
	#define STRMSG_S_I2NOTIFY_0007 "編隊に再加入しました"
	#define STRMSG_S_I2NOTIFY_0008 "既に加入している編隊があります。"
	#define STRMSG_S_I2NOTIFY_0009 "Fatal Error:?刻な編隊エラ-！at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "編隊メンバ-の状態が不正です"
	#define STRMSG_S_I2NOTIFY_0011 "編隊メンバ-が既に旅団に加入しています"
	#define STRMSG_S_I2NOTIFY_0012 "対象が既に旅団に加入しています"
	#define STRMSG_S_I2NOTIFY_0013 "自分を招待することはできません"
	#define STRMSG_S_I2NOTIFY_0014 "旅団加入が許可されていません"
	#define STRMSG_S_I2NOTIFY_0015 "加入可能な旅団メンバ-数を超過しました"
	#define STRMSG_S_I2NOTIFY_0016 "旅団加入が許可されていません"
	#define STRMSG_S_I2NOTIFY_0017 "旅団長は脱退できません"
	#define STRMSG_S_I2NOTIFY_0018 "旅団戦中のため、旅団から脱退できません"
	#define STRMSG_S_I2NOTIFY_0019 "旅団戦中のため、旅団メンバ-を追放できません"
	#define STRMSG_S_I2NOTIFY_0020 "旅団長は追放できません"
	#define STRMSG_S_I2NOTIFY_0021 "旅団戦中のため、旅団を解散できません"
	#define STRMSG_S_I2NOTIFY_0022 "同じ名前に変更できません"
	#define STRMSG_S_I2NOTIFY_0023 "旅団名を変更できない状態です"
	#define STRMSG_S_I2NOTIFY_0024 "旅団ﾏ-ｸを変更できない状態です"
	#define STRMSG_S_I2NOTIFY_0025 "階級を変更できない状態です"
	#define STRMSG_S_I2NOTIFY_0026 "階級が重複されました"
	#define STRMSG_S_I2NOTIFY_0027 "旅団長への階級変更はできません。"
	#define STRMSG_S_I2NOTIFY_0028 "旅団長の階級変更はできません。"
	#define STRMSG_S_I2NOTIFY_0029 "全体ﾌﾟﾚｲﾔ-数:%d人(%人まで出力)"
	#define STRMSG_S_I2NOTIFY_0030 "運営者メッセ-ジリストに追加しました"
	#define STRMSG_S_I2NOTIFY_0031 "運営者メッセ-ジリストから削除されました"
	#define STRMSG_S_I2NOTIFY_0032 "ｻ-ﾊﾞ-IP:%s"
	#define STRMSG_S_I2NOTIFY_0033 "ｻ-ﾊﾞ-ｸﾞﾙ-ﾌﾟ \'%s\'の全体接続者:%d人"
	#define STRMSG_S_I2NOTIFY_0034 "本当にｻ-ﾊﾞ-(%s)を終了しますか？数字:%d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'はｹﾞ-ﾑをしていません"
	#define STRMSG_S_I2NOTIFY_0036 "全体ﾌﾟﾚｲﾔ-数:%d人(%d人まで出力)"
	#define STRMSG_S_I2NOTIFY_0037 "/送信%s%s"
	#define STRMSG_S_I2NOTIFY_0038 "該当旅団がありません。"
	#define STRMSG_S_I2NOTIFY_0039 "ささやきブロックが解除されました！"
	#define STRMSG_S_I2NOTIFY_0040 "ささやきをブロックしました！"
	#define STRMSG_S_I2NOTIFY_0041 "旅団に加入していません"
	#define STRMSG_S_I2NOTIFY_0042 "旅団(%d)が無効です"
	#define STRMSG_S_I2NOTIFY_0043 "該当天気(%s)が存在していません"
	#define STRMSG_S_I2NOTIFY_0044 "Field Serverが無効です"
	#define STRMSG_S_I2NOTIFY_0045 "該当ﾏｯﾌﾟ(%s)が存在していません"
	#define STRMSG_S_I2NOTIFY_0046 "あなたは%d分間ﾁｬｯﾄ禁止です！"
	#define STRMSG_S_I2NOTIFY_0047 "ﾁｬｯﾄﾌﾞﾛｯｸ設定:'%10s',%3d分"
	#define STRMSG_S_I2NOTIFY_0048 "ﾁｬｯﾄﾌﾞﾛｯｸが解除されました"
	#define STRMSG_S_I2NOTIFY_0049 "ﾁｬｯﾄﾌﾞﾛｯｸ解除:'%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(アカウント:%s,?ップ:%d(%d),レベル: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "自分を呼ぶことができません"
	#define STRMSG_S_I2NOTIFY_0052 "該当旅団がありません。"

	#define STRMSG_S_IMSERVER_050607_0001	"該当ﾏｯﾌﾟがありません。"
// 6_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Field Serverに接続しました。\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Field Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							ﾓﾝｽﾀ-とオブジェクトの衝突のﾁｪｯｸがない\r\n"		
	#define STRMSG_S_N2NOTIFY_0001 "都市占領戦ﾓﾝｽﾀ-(%10s)召喚\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "石田耕太郎"
// 7_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 8 - PreServer	
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%sアカウント(%s)に接続しました。 IP:%s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "成功"
	#define STRMSG_S_P2PRENOTIFY_0002 "失敗"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]アカウント情報追加エラ-、 AccountName(%s)privateIP(%15s)\n"
	
	
	#define STRMSG_SCAT_051115_0001		"おはようございます。ｴ-ｽｵﾝﾗｲﾝ運営ﾁ-ﾑです。"
	#define STRMSG_SCAT_051115_0002		"?日、10時から14時まで定期メンテナンスを実?します。"
	#define STRMSG_SCAT_051115_0003		"安全な場所に移動して、接続を終了してください。"
	#define STRMSG_SCAT_051115_0004		"まずNPCｻ-ﾊﾞ-から終了します。"
	#define STRMSG_SCAT_051115_0005		"これからｴ-ｽｵﾝﾗｲﾝ定期メンテナンスを開始します。"
	#define STRMSG_SCAT_051115_0006		"ｴ-ｽｵﾝﾗｲﾝと楽しい一日を過ごしてください。"
	#define STRMSG_SCAT_051115_0007		"まもなく緊急メンテナンスのためｻ-ﾊﾞ-を終了します。"
	#define STRMSG_SCAT_051115_0008		"メンテナンスの時間は2時間です。"







///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"透明状態:ﾌﾟﾚｲﾔ-が見ることができない、全武器使用不可"
	#define STRMSG_060509_0001			"無敵状態:ﾀﾞﾒ-ｼﾞを受けない"
	#define STRMSG_060509_0002			"ｽﾃﾙｽﾓ-ﾄﾞ:ﾓﾝｽﾀ-から先制攻撃を受けない"

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you momentarily."
	#define	STRMSG_060526_0001			"自動ｱｯﾌﾟﾃﾞ-ﾄ実行できません。\r\n\r\n公式サイト(%s)ﾀﾞｳﾝﾛ-ﾄﾞﾍﾟ-ｼﾞからﾊﾟｯﾁを受けてｲﾝｽﾄ-ﾙしてください。\r\n\r\n    Error:%s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"現在IDが登録されていないか、\r\n IDやPWが間違っています。"
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"現在ｻ-ﾋﾞｽﾒﾝﾃﾅﾝｽ中です。詳細な説明は公式サイトをご確認ください。"

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"ｸﾗｲｱﾝﾄﾊﾞ-ｼﾞｮﾝが異なります。\r\n公式サイト(%s)ﾀﾞｳﾝﾛ-ﾄﾞﾍﾟ-ｼﾞからﾊﾟｯﾁを受けてｲﾝｽﾄ-ﾙしてください。"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"%sに撃墜されました。"			  			

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000			"大会ｻ-ﾊﾞ- DB(atum2_db_20) 初期化は大会ｻ-ﾊﾞ-群を終了後にしてください。"
	#define STRMSG_070410_0001			"本当に大会ｻ-ﾊﾞ- DB(atum2_db_20)を初期化しますか？ [認証ナンバ-:%d]"
	#define STRMSG_070410_0002			"大会ｻ-ﾊﾞ- DB(atum2_db_20)が初期化されました。"
	#define STRMSG_070410_0003			"大会ｻ-ﾊﾞ- DB(atum2_db_20)初期化失敗！"
	#define STRMSG_070410_0004			"大会ｻ-ﾊﾞ- DB(atum2_db_20)に'%s'の情報ｺﾋﾟ-完了"
	#define STRMSG_070410_0005			"大会ｻ-ﾊﾞ- DB(atum2_db_20)に'%s'の情報ｺﾋﾟ-失敗-ｷｬﾗｸﾀ-が存在しません！"
	#define STRMSG_070410_0006			"大会ｻ-ﾊﾞ- DB(atum2_db_20)に'%s'の情報ｺﾋﾟ-失敗-大会ｻ-ﾊﾞ-に該当アカウントのｷｬﾗｸﾀ-があります！"
	#define STRMSG_070410_0007			"大会ｻ-ﾊﾞ-DB(atum2_db_20)に'%s'の情報ｺﾋﾟ-失敗-DB追加ｴﾗ-です！"
	#define STRMSG_070410_0008			"大会ｻ-ﾊﾞ-DB(atum2_db_20)に'%s'の情報ｺﾋﾟ-失敗-不明(%d)！"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, ??? 文字?
	// 2007-07-24 by cmkwon, ???? 800*600 ??? ?? - ???? ??? ?? ??
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (low)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (medium)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (high)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (high-wide)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (low)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (medium)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (high)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (low)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (medium)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (high)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (high-wide)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (low)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (medium)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (high)"

// 2007-06-15 by dhjin, 観戦関連ストリング
#define STRMSG_070615_0000				"透明状態ではないため観戦を開始できません。"
#define STRMSG_070615_0001				"観戦を開始できません。"
#define STRMSG_070620_0000				"一般勢力は観戦できません。"

// 2007-06-26 by dhjin, 戦争?イント（WP） イベント 関連 追加
#define STRMSG_S_F2EVENTTYPE_0006		"戦争ﾎﾟｲﾝﾄ（WP）"

// 2007-06-28 by cmkwon, ?? ?????(ゲ?? ?? ?? ??) - ??? 追加
#define STRMSG_070628_0000				"??? ?? ゲ????? ?? %d??? ?????."
#define STRMSG_070628_0001				"??? ?? ゲ????? ?? %d??? ?????. ゲ??終了??? ??? ??? ??? ??を ???."
#define STRMSG_070628_0002				"??? ?? ??? ゲ????? ??????. ??? ゲ????? 50%%?? ?????. ??? ??を ??? ゲ?? 終了??? ??? ??を ??? ???? ????を ?????"
#define STRMSG_070628_0003				"??? ?? ???? ゲ????? ??????. ??? ??を ??? 即時? ゲ?? 終了???. ??? ??? ??? ??? ??? ??? ??? ゲ????? 0%%?? ?????. ゲ?? 終了 ? 5???? ?? ??? ???? ?????."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, ｱﾘ-ﾅブロック ｼｽﾃﾑ 具現 - 追加したストリング
#define STRMSG_070711_0000				"\'%s\'様はｱﾘ-ﾅの利用ブロック状態ではありません。"
#define STRMSG_070711_0001				"\'%s\'様はｱﾘ-ﾅの利用ブロック状態です。(残り時間:%d分)"
#define STRMSG_070711_0002				"あなたは%d分間ｱﾘ-ﾅの利用ブロック状態です！"
#define STRMSG_070711_0003				"ｱﾘ-ﾅの利用ブロックが解除されました。"
#define STRMSG_070711_0004				"\'%s\'様のｱﾘ-ﾅの利用ブロックが解除されました。"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide ??? 1280x720(16:9) 追加 - ??? 追加
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon, 会議室 システ? ?? - ??? 追加
#define STRMSG_070830_0001				"勢力選択後、使用できる命令語です"
#define STRMSG_070830_0002				"該当勢力の会議室ﾏｯﾌﾟ(%d)が無効です"
#define STRMSG_070830_0003				"現在会議室に入場できる人数:%d人"
#define STRMSG_070830_0004				"'%s'様は既に会議室入場権限を持っています。"
#define STRMSG_070830_0005				"'%s'様は会議室入場権限がありません。"
#define STRMSG_070830_0006				"'%s'は無効なキャラク??です。"
#define STRMSG_070830_0007				"'%s'を会議室入場権限リストに追加できません。(最大%d人)"
#define STRMSG_070830_0008				"'%s'様に会議室入場権限が付与されました。"
#define STRMSG_070830_0009				"会議室入場権限が付与されました。"
#define STRMSG_070830_0010				"会議室入場権限が解除されました。"
#define STRMSG_070830_0011				"'%s'"

// 2007-11-13 by cmkwon, ???? ?? 追加 - 
#define STRMSG_071115_0001				"\\y%s様に%sｱｲﾃﾑを ﾌﾟﾚｾﾞﾝﾄしました。"
#define STRMSG_071115_0002				"ﾌﾟﾚｾﾞﾝﾄﾘｽﾄ:\'%s(%d個)\'"
#define STRMSG_071115_0003				"\\y%s様が%s様に%sｱｲﾃﾑをﾌﾟﾚｾﾞﾝﾄしました。倉庫を確認してください。"

// 2007-11-19 by cmkwon, 進呈ｼｽﾃﾑ ｱｯﾌﾟﾃﾞ-ﾄ -
#define STRMSG_071120_0001				"進呈ｼｽﾃﾑ利用時間ではありません。ｶｽﾀﾏ-ｾﾝﾀ-にお問い合わせください。"
#define STRMSG_071120_0002				"進呈ｼｽﾃﾑが活性化されました。"
#define STRMSG_071120_0003				"進呈ｼｽﾃﾑが終了しました。"
#define STRMSG_071120_0004				"%sから%sまで進呈ｼｽﾃﾑを実行します。"

// 2007-11-28 by cmkwon, 告知ｼｽﾃﾑ具現 - 
#define STRMSG_071128_0001				"%s様が%sｱｲﾃﾑ%d個をﾌﾟﾚｾﾞﾝﾄしました。倉庫を確認してください。"

// 2007-12-27 by cmkwon, ウインドウﾓ-ﾄﾞ??追加 -
#define STRMSG_071228_0001				"解像度設定が無効です。もう一度確認してください。"

// 2008-01-31 by cmkwon, アカウントブロック/解除命令後で可能なｼｽﾃﾑ具現-
#define STRMSG_080201_0001				"'%s'様ブロック設定にｴﾗ-があります。 ErrorCode(%d)"
#define STRMSG_080201_0002				"'%s'アカウントをブロック処理しました。[Block End Date:%s]"
#define STRMSG_080201_0003				"'%s'アカウントがブロックリストにありません。ErrorCode(%d)"
#define STRMSG_080201_0004				"'%s'アカウントブロック 解除処理にｴﾗ-があります。ErrorCode(%d)"
#define STRMSG_080201_0005				"'%s'アカウントをブロック解除処理しました。"

// 2008-02-11 by cmkwon, ??? 追加(1440x900) -
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin,  ??ｱﾘ-ﾅ - ｱﾘ-ﾅ ｻ-ﾊﾞ- ?? ?? ??
#define STRMSG_S_MF2AFCONNECT_0000 "[Error]WndProc(),Can't connect to  ArenaServer[%15s:%4d]Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001 "Arena Serverに接続しました。\r\n"
#define STRMSG_S_MF2AFCONNECT_0002 "Arena Server[%15s:%4d]との接続が終了しました。再接続します。\r\n"
#define STRMSG_S_MF2AFCONNECT_0003 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004 "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001		"\\y%d番アリ-ナwaiting roomにイベント属性を追加しました。\r\n"
#define STRMSG_ARENAEVENT_080310_0002		"\\y%d番アリ-ナRoomのイベント属性を解除しました。\r\n"
#define STRMSG_ARENAEVENT_080310_0003		"\\yアリ-ナイベント属性の追加に失敗しました。\r\n"
#define STRMSG_080428_0001					"%s様を撃墜しました。"		// 2008-04-28 by dhjin, ｱﾘ-ﾅ ?? - 相手 撃墜 ? ??? 追加, ｱﾘ-ﾅ ﾏｯﾌﾟ???

// 2008-04-29 by cmkwon, ｻ-ﾊﾞ- 情報 DB? 追加(?? アカウント ｷｬﾗｸﾀ- 作成 ?? ｼｽﾃﾑ追加) - 
#define STRMSG_080430_0001					"選択したサ-バは新規ｷｬﾗｸﾀ-作成が制限されているサ-バ-です。"

// 2008-06-13 by dhjin, EP3 旅団 ?? ?? - 
#define STRMSG_080613_0001					"%s旅団への加入申し込みがブロックされました。"

// 2008-09-04 by cmkwon, don't need translation, サ?バ? SystemLog ??? ?? ?? ??	
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, 指導者ﾁｬｯﾄ制限カ-ド
#define STRMSG_081230_0001					"\\y%sのﾁｬｯﾄ使用を%d分間制限します。\\y"
#define STRMSG_081230_0002					"\\y指導者の権限によりあなたのﾁｬｯﾄ使用が%d分間制限されました。\\y"
#define STRMSG_081230_0003					"\\y指導者ﾁｬｯﾄ制限が解除されました。\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D ｰﾔﾀﾓｰ｡ｵ・ｵｿﾀﾇﾃ｢ ｶ鄙・・- 
// 2009-09-02 by cmkwon, Gameforge4D ｰﾔﾀﾓ ｰ｡ｵ・ｵｿﾀﾇﾃ｢ WebPageｷﾎ ﾃｳｸｮ - STRMSG_090831_0001ｴﾂ ﾀ･ﾆ菎ﾌﾁ?ｷﾎ ﾃｳｸｮ
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ｰﾔﾀﾓ ｰ｡ｵ・ｵｿﾀﾇﾃ｢ WebPageｷﾎ ﾃｳｸｮ - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ﾁ?ｿ・ﾇﾘｻ?ｵｵ ﾃﾟｰ｡(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (low)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (medium)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (high)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (low)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (medium)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (high)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (low)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (medium)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (high)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ﾀﾎﾁ・ｼｭｹ?ﾀﾇ ﾁ｢ｼﾓ ﾇ譱・ｻ?ﾈｲ
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"登録されていないサ-バ-です。（プライベ-トサ-バである可能性があります）"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				" DB連動時にエラ-が発生しました。"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"サ-バ-認証に成功しました。"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"該当サ-バ-にIPが登録されていますが、認証拒否処理がされました。"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"サ-バ-に強制終了ｺﾏﾝﾄﾞを送信しました。"






#define STRMSG_120330_0001	"%s様がアッシュレ-ンで、隠された空間へのワ-プゲ-トを発動しました。"
#define STRMSG_120330_0002	"%s様がアッシュレ-ンで、ﾓﾝｽﾀ-経験分100%%%%増加のバ-ストイベント(1時間)を発動しました。"
#define STRMSG_120330_0003	"%s様がアッシュレ-ンで、ｱｲﾃﾑﾄﾞﾛｯﾌﾟ率100%%%%増加のバ-ストイベント（1時間）を発動しました。"
#define STRMSG_120330_0004	"%s様がアッシュレ-ンで、ｱｲﾃﾑﾄﾞﾛｯﾌﾟ率100%%%%/Monster経験値100%%%%/ SPI獲得率100%%%%増加のバ-ストイベント（1時間）を発動しました。"
#define STRMSG_120330_0005	"%s様がアッシュレ-ンでWeapon shopを召喚しました。"
#define STRMSG_120330_0006	"%s様がアッシュレ-ンでハイパ-カ-ドショップを召喚しました。"
#define STRMSG_120330_0007	"%s様がアッシュレ-ンでキットショップを召喚しました。"
#define STRMSG_120330_0008	"%s様がアッシュレ-ンでBoss Monsterを召還しました。"
#define STRMSG_120330_0009	"CRYSTALが消滅しました。"



#define STRMSG_120508_0001					"%様がロストオアシスから%WPを取得しました。"
#define STRMSG_120508_0002					"%様がロストオアシスでBoss monstersを召喚しました。"
#define STRMSG_120508_0003					"%様がバ-ストイベント(1時間)を発動しました。ﾓﾝｽﾀ-経験値が150%%%%増加します。"
#define STRMSG_120508_0004					"%様がバ-ストイベント(1時間)を発動しました。ｱｲﾃﾑﾄﾞﾛｯﾌﾟ率が150%%%%増加します。"
#define STRMSG_120508_0005					"%様がバ-ストイベント(1時間)を発動しました。ﾓﾝｽﾀ-経験値/ｱｲﾃﾑﾄﾞﾛｯﾌﾟ率/SPI獲得率が150%%%%増加します。"
#define STRMSG_120508_0006					"%様がロストオアシスで古代の氷を取得しました。"
#define STRMSG_120508_0007					"%様がロストオアシスでItem shopを召喚しました。"
#define STRMSG_120508_0008					"%様がロストオアシスでキットショップを召喚しました。"
#define STRMSG_120508_0009					"%様がロストオアシスでハイパ-カ-ドショップを召喚しました。"
#define STRMSG_120508_0010					"%様がロストオアシスでWeapon shopを召喚しました。"
#define STRMSG_120508_0011					"%様がロストオアシスで隠された空間へのワ-プゲ-トを召喚しました。"

#define STRMSG_120712_0001					"18ｼｼ ｹﾌｸｸ ﾃｻｼﾒｳ篩｡ｰﾔ ﾀ?ｿ・ﾇｴ?ｰﾔﾀﾓｽﾃｰ｣ ｼｱﾅﾃﾁｦ ｼｳﾁ､ﾀｸｷﾎ ﾀﾎﾇﾏｿｩ, %d ｺﾐ ﾈﾄｿ｡ ｰﾔﾀﾓﾀﾌ ﾁｾｷ盞ﾋｴﾏｴﾙ."		// 2012-07-11 by hskim, ｼｱﾅﾃﾀ・ｼﾋｴﾙｿ・

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pcｹ・ｸ?ｵ・
#define STRMSG_121005_0001					"\\yPCｹ・ｰ｡ｸﾍﾁ｡ ｽﾃｰ｣ﾀﾌ %dｺﾐ ｳｲｾﾒｽﾀｴﾏｴﾙ."
#define STRMSG_121005_0002					"\\yﾀ眇ﾃ ﾈﾄ PCｹ・ｰ｡ｸﾍﾁ｡ﾀﾌ ﾁｾｷ盞ﾋｴﾏｴﾙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ﾀ・・ｽﾃｽｺﾅﾛ ｸｮｴｺｾ・- ﾀ・・?ﾆｮｸｮｰﾅ ｹｫﾀ?ｻ?ﾅﾂ(ﾀﾏｽﾃﾁ､ﾁ・
#define STRMSG_121126_0001					"\\yCommand : 戦争時はｸﾘｽﾀﾙの破壊は出来ません。\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXﾀﾌｺ･ﾆｮ ｸﾊ ｿ?ﾇﾁﾁｦﾇﾑ
#define STRMSG_121129_0001					"\\yこのエリアはGM以外進入できません。\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ﾀ・・簔・ﾆｮｸｮｰﾅ ｽﾃｽｺﾅﾛ
#define STRMSG_130121_0001					"\\cシステムはNGC軍によって捕えられました。即時撤退が開始されました。"
#define STRMSG_130121_0002					"\\c偵察兵:\\c NGC制御機が確認されました。"
#define STRMSG_130121_0003					"\\c偵察兵:\\c NGC制御機が破壊されました。"
#define STRMSG_130121_0004					"\\c指令:\\c NGCゴモラのバリアが展開されました！バリアを無効化する為に制御機を破壊してください！"
#define STRMSG_130121_0005					"\\c指令:\\c ゴモラのバリアが破壊されました！総攻撃を開始してください！"
#define STRMSG_130121_0006					"\\c指令:\\c ゴモラが破壊されました！各機は前方へ移動を開始してください！"
#define STRMSG_130121_0007					"\\c指令:\\c ゴモラは最初に破壊しなければなりません。"
#define STRMSG_130121_0008					"\\c[%s]の効果はNGC制御機の稼働が原因です。"
#define STRMSG_130121_0009					"\\y[NGCアドバンスベース基地システム]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ｾﾆﾀﾌﾅﾛ ﾀﾌｺ･ﾆｮ - ｼｭｺ・ｸﾀﾔ ﾃﾟｰ｡ｱｸﾁｶ ｽﾃｽｺﾅﾛ ｺｸｾﾈ
#define STRMSG_130422_0001					"\\y%s %dはアリーナから制限されています。アイテムは倉庫に送られました。\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ｾﾆｸﾓ ﾄﾃｷｺｼﾇ - STRMSG ﾃﾟｰ｡
#define STRMSG_130531_0001					"\\g[%s] 外装はアーマーコレクションに追加されました。\\g"
#define STRMSG_130531_0002					"\\g[%s] 外装は[%2d]回適用されました。\\g"
#define STRMSG_130531_0003					"\\g[%s] 外装は適用可能回数に達しました。［%s］へ変更されます。\\g"
#define STRMSG_130531_0004					"外装の適用期限が過ぎた為、ステータスが削除されました。エンジンが装備されていません。"
#define STRMSG_130531_0005					"\\yエンジンが装備されていません。都市に帰還してください。\\y"
#define STRMSG_130531_0006					"\\g現在アーマーに適用されている外装を使用することはできません。\\g"
#define STRMSG_130531_0007					"\\g外装が変更されました。\\g"
#define STRMSG_130531_0008					"\\r［%s］外装は期限切れになりました。\\r"
#define STRMSG_130531_0009					"\\y外装を適用したアーマーを売却することはできません。\\y"
#define STRMSG_130531_0010					"\\yギアタイプが一致しません。\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ﾆｮｸｮｰﾅ ｽﾃｽｺﾅﾛ ﾈｮﾀ・- STRMSG ﾃﾟｰ｡
#define STRMSG_130708_0001					"\\c指令:\\c NGC軍のシールドが展開されました。シールドを無効化するにはNGCコントローラーを破壊してください！"
#define STRMSG_130708_0002					"\\c指令:\\c NGC軍事基地シールドがダウンしています。攻撃を開始してください！"
#define STRMSG_130708_0003					"\\c偵察兵:\\c NGCシールドジェネレーターが確認されました。"
#define STRMSG_130708_0004					"\\c偵察兵:\\c NGCシールドジェネレーターが破壊されました。"

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, ﾅｸ ｰ霖､ ｼｼｷﾂｺｯｰ・
#define STRMSG_130726_0001					"キャラクターはすでにその勢力です。"
#define STRMSG_130726_0002					"キャラクターはリーダーまたはサブリーダーです。そのため勢力を変更することはできません。"
#define STRMSG_130726_0003					"キャラクターは旅団に入団している為、勢力を変更することはできません。"
#define STRMSG_130726_0004					"勢力変更可能なキャラクターがいません。"
#define STRMSG_130726_0005					"勢力変更に失敗しました。[AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"勢力変更に成功しました。 [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"アカウントが存在しません。"
#define STRMSG_130726_0008					"アカウントがログインしている為、勢力変更ができません。"


// 2013-08-30 by bckim, ﾇﾊｵ蠡ﾌｵｿｱﾝﾁ?ｾﾆﾀﾌﾅﾛ
#define STRMSG_130830_0001					"\\\y%s様が指導者権限でMAPへの移動が制限されました。\\y"
#define STRMSG_130830_0002					"\\y現在指導者権限によってMAPへの移動が制限された状態です。\\y"
#define STRMSG_130830_0003					"\\y%該当ﾕ-ｻﾞ-は指導者権限によってMAPへの移動が制限された状態です。\\y"
// End. 2013-08-30 by bckim, ﾇﾊｵ蠡ﾌｵｿｱﾝﾁ?ｾﾆﾀﾌﾅﾛ

// 2013-08-28 by bckim, ｺｸｽｺｸ?ｽｺﾅﾍ ｺｸｻ?ｰｭﾈｭ
#define STRMSG_130828_0001					"\\y[%s]様 標的の撃破に貢献しました。\\y"
#define STRMSG_130828_0002					"\\y[%s]様 標的に対する先制攻撃を行いました。\\y"
#define STRMSG_130828_0003					"\\y[%s]様 標的に対して一定のダメージを与えました。 \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s]様 標的に対するラストアタックになりました。\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\nの撃破に成功しました。次も頑張ってください。"
// End. 2013-08-28 by bckim, ｺｸｽｺｸ?ｽｺﾅﾍ ｺｸｻ?ｰｭﾈｭ

// 2013-08-14 by jhseol, ｰﾅﾁ｡ﾀ・ｸｮｴｺｾ・- ｽﾂｸｮｼｼｷﾂ GM ｸﾞｼｼﾁ・ｻﾑｸｮｱ・
#define STRMSG_130814_0001					"\\y[%s] NGC拠点戦に勝利しました。\\y"
// end 2013-08-14 by jhseol, ｰﾅﾁ｡ﾀ・ｸｮｴｺｾ・- ｽﾂｸｮｼｼｷﾂ GM ｸﾞｼｼﾁ・ｻﾑｸｮｱ・

// 2014-03-12 by bckim, ｹ?ｴﾗﾅｸﾀﾓ(ﾀ・・?ｿｪ)
#define STRMSG_130318_0001					"%s 制限区域内のボスモンスターを召喚しています。"
#define STRMSG_130318_0002					"%s 廃墟の都市のボスモンスターを召喚しています。"
// End. 2014-03-12 by bckim, ｹ?ｴﾗﾅｸﾀﾓ(ﾀ・・?ｿｪ)

// 2014-03-18 by bckim, ｸｶﾄﾏ ON/OFF
#define STRMSG_130318_0003					"\\y現時点ではトレードショップを利用する事が出来ません。\\y"
// End. 2014-03-18 by bckim, ｸｶﾄﾏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
