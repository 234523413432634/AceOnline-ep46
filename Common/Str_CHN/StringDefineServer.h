
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "服务器没有运行"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMEXE_0003 "自动更新失败.\r\n请重新设置游戏.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "下载服务器连接失败"
	#define STRERR_S_ATUMEXE_0007 "无法获取下载文件的大小"
	#define STRERR_S_ATUMEXE_0008 "不能下载更新文件"
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "无法找到文件"
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found. "
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "update completed"
	#define STRMSG_S_ATUMLAUNCHER_0001 "请选择服务器"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "deleting files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "update completed(%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "选择运行文件"
	#define STRMSG_S_ATUMLAUNCHER_0007 "选择运行路径"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading is canceled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "updating to v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "updating to v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Getting File Information %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, 海飘巢 X-Trap -> VTC 啊靛肺 函版
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, 海飘巢 X-Trap -> VTC 啊靛肺 函版
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "不能连接认证服务器"
	#define STRERR_S_ATUMLAUNCHER_0005 "服务器连接失败"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "请重新下载游戏.\nURL: http://space.mgame.com/\n最新版本: "
	#define STRERR_S_ATUMLAUNCHER_0009 "自动更新失败.\r\n请重新设置游戏.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "所有服务器非活性状态."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s维护中..."
	#define STRERR_S_ATUMLAUNCHER_0012 "所有服务器正在维护.请稍后再登陆."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
//	#define STRERR_S_ATUMLAUNCHER_0014 "ID, 密码错误\n\n* 现在是beta测试，只有认证的玩家才可以登陆"
	#define STRERR_S_ATUMLAUNCHER_0015 "登陆过程错误"
	#define STRERR_S_ATUMLAUNCHER_0016 "未输入用户ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "此帐号已登陆"
	#define STRERR_S_ATUMLAUNCHER_0018 "F服务器没有运行"
	#define STRERR_S_ATUMLAUNCHER_0019 "I服务器没有运行"
	#define STRERR_S_ATUMLAUNCHER_0020 "服务一时中断.\n\n请稍后再试"
	#define STRERR_S_ATUMLAUNCHER_0021 "目前用户太多.\n\n请稍后再登陆"
// 2013-05-22 by bckim, 某唱促 皋技瘤冠胶 坷鸥 荐沥 棺 版肺 函版 
	//#define STRERR_S_ATUMLAUNCHER_0022 "Your account is currently blocked.\nPeriod : %s\n\nConatact Customer Support at [ace.subagames.com/support_contact.aspx] for further details."
	#define STRERR_S_ATUMLAUNCHER_0022 "帐号已封停.\n 时间 : %s\n\n请咨询ACE online客户中心"
	#define STRERR_S_ATUMLAUNCHER_0023 "客户端版本不同.\n\n请重新下载游戏"
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "无法连接下载服务器"
	#define STRERR_S_ATUMLAUNCHER_0026 "无法获取下载文件(%s)的大小"
	#define STRERR_S_ATUMLAUNCHER_0027 "无法获取下载文件的大小"
	#define STRERR_S_ATUMLAUNCHER_0028 "无法下载更新文件"
	#define STRERR_S_ATUMLAUNCHER_0029 "更新文件不存在"
	#define STRERR_S_ATUMLAUNCHER_0030 "选择的服务器正在维护.请稍后再试"
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "无法找到文件."
	#define STRERR_S_ATUMLAUNCHER_0034 "无法找到路径."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18技 固父 没家斥俊霸 利侩登绰 霸烙矫埃 急琶力 汲沥栏肺 牢窍咯, 泅犁 矫埃俊绰 霸烙 柳青捞 阂啊瓷钦聪促.\n\n磊技茄 荤亲篮 俊捞胶柯扼牢 绊按季磐肺 巩狼官而聪促."		// 2012-07-11 by hskim, 急琶利 妓促款

// 2013-05-22 by bckim, 某唱促 皋技瘤冠胶 坷鸥 荐沥 棺 版肺 函版 
// 	#define STRMSG_S_050506		"\'%s\'s account is blocked presently.\n  Reason: %s\n  Period: %s~%s\n\nConatact Customer Support at [ace.subagames.com/support_contact.aspx] for further details."
	#define STRMSG_S_050506		"\'%s\'帐号已封停.(理由: %s, 时间: %s~%s) \n\n详细情况请咨询ACE online客服中心"
	#define STRMSG_S_050930		"请重新下载游戏.\nURL: %s\n最新版本: "
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "男"
//	#define STRMSG_S_SCADMINTOOL_0001 "女"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d年, %d岁"
//	#define STRMSG_S_SCADMINTOOL_0003 "确定要修改帐号信息吗?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + '个 拾取, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''' + l.PeerCharacterName + '''获得 ' + CAST(l.ChangeCount AS VARCHAR(10)) + '个 , ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''' + l.PeerCharacterName + '''收到 ' + CAST(l.ChangeCount AS VARCHAR(10)) + '个 , ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10)) + '个已丢弃, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 个已购买, 还剩 Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + '个已出售, 还剩 Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + '''已删除 ' + CAST(l.ChangeCount AS VARCHAR(10)) + '个, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + '''已删除 ' + CAST(l.ChangeCount AS VARCHAR(10)) + '个, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0014 "CAST(l.ChangeCount AS VARCHAR(10)) + '个已添加, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0015 "CAST(l.ChangeCount AS VARCHAR(10)) + '个已委托, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0016 "CAST(l.ChangeCount AS VARCHAR(10)) + '个已找到, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '个'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'游戏时间 \' + atum.atum_GetHMSFromS(l.PlayTime) + \', 总 \' + atum.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', 游戏时间: ' + atum.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' 增加, 总 \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "冲突"
//	#define STRMSG_S_SCADMINTOOL_0021 "怪物"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "原因不名"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, 属性点还剩: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(没有)"
//	#define STRMSG_S_SCADMINTOOL_0026 "唱"
//	#define STRMSG_S_SCADMINTOOL_0027 "没有"
//	#define STRMSG_S_SCADMINTOOL_0028 "BUG使用玩家"
	#define STRMSG_S_SCADMINTOOL_0029 "帐号封停"
	#define STRMSG_S_SCADMINTOOL_0030 "禁止聊天"
//	#define STRMSG_S_SCADMINTOOL_0031 "登陆LOG"
//	#define STRMSG_S_SCADMINTOOL_0032 "玩家LOG"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item LOG"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s 服务器"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s 服务器,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "帐号封停"
//	#define STRMSG_S_SCADMINTOOL_0037 "分类    "
//	#define STRMSG_S_SCADMINTOOL_0038 "值"
	#define STRMSG_S_SCADMINTOOL_0039 "要解除封停状态吗？?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d秒)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d胜 %d败"
	#define STRMSG_S_SCADMINTOOL_0042 "确认要中断连接以后限制吗?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s 道具"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] 公告事项 : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "用户数: %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] 收到的信息 : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] 玩家数 : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] FieldServer state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "服务器连接已终止\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "无法读取帐号信息"
	#define STRERR_S_SCADMINTOOL_0001 "帐号信息修改失败"
	#define STRERR_S_SCADMINTOOL_0002 "请输入密码"
	#define STRERR_S_SCADMINTOOL_0003 "密码错误"
	#define STRERR_S_SCADMINTOOL_0004 "请输入登陆名"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server没有运行"
	#define STRERR_S_SCADMINTOOL_0006 "Can not connect to PreServer !!"
//	#define STRERR_S_SCADMINTOOL_0007 "认证失败"			// 2006-04-11 by cmkwon, 注释处理
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: 不存在相关协议."
	#define STRERR_S_SCADMINTOOL_0009 "请输入用户名"
	#define STRERR_S_SCADMINTOOL_0010 "请输入事由"
	#define STRERR_S_SCADMINTOOL_0011 "经验值设置错误 : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "已超过最大登陆人数\r\n\r\n请修改最大登陆认输或者搜索条件"
	#define STRERR_S_SCADMINTOOL_0013 "无法连接Database"
	#define STRERR_S_SCADMINTOOL_0014 "无法连接"
	#define STRERR_S_SCADMINTOOL_0015 "已连接"
	#define STRERR_S_SCADMINTOOL_0016 "正在更新"
	#define STRERR_S_SCADMINTOOL_0017 "已登陆"
	#define STRERR_S_SCADMINTOOL_0018 "正在选择角色"
	#define STRERR_S_SCADMINTOOL_0019 "游戏中"
	#define STRERR_S_SCADMINTOOL_0020 "无法获取"
	#define STRERR_S_SCADMINTOOL_0021 "无法连接Database %s(%s:%d)"
	#define STRERR_S_SCADMINTOOL_0022 "添加道具失败"
	#define STRERR_S_SCADMINTOOL_0023 "寻找封停帐号失败"
	#define STRERR_S_SCADMINTOOL_0024 "为了修改请先中断连接!"
	#define STRERR_S_SCADMINTOOL_0025 "不能添加SPI(钱)"
	#define STRERR_S_SCADMINTOOL_0026 "选择的道具已存在，请修改数量"
	#define STRERR_S_SCADMINTOOL_0027 "寻找道具错误"
	#define STRERR_S_SCADMINTOOL_0028 "角色所有的 SPI(钱)不能删除"
	#define STRERR_S_SCADMINTOOL_0029 "要删除道具吗?"
	#define STRERR_S_SCADMINTOOL_0030 "删除道具失败"
	#define STRERR_S_SCADMINTOOL_0031 "修改道具失败"
	#define STRERR_S_SCADMINTOOL_0032 "请输入帐号"
	#define STRERR_S_SCADMINTOOL_0033 "帐号不存在(可以设置帐号封停)"
	#define STRERR_S_SCADMINTOOL_0034 "帐号或者角色不存在"
	#define STRERR_S_SCADMINTOOL_0035 "角色信息对照错误"
	#define STRERR_S_SCADMINTOOL_0036 "不存在相关角色"
	#define STRERR_S_SCADMINTOOL_0037 "角色更新错误"
	#define STRERR_S_SCADMINTOOL_0038 "角色信息成功更新"
	#define STRERR_S_SCADMINTOOL_0039 "请选择道具"
	#define STRERR_S_SCADMINTOOL_0040 "请选择道具数量"
	#define STRERR_S_SCADMINTOOL_0041 "相关道具可以生成5个以下"
	#define STRERR_S_SCADMINTOOL_0042 "请输入信息"
	#define STRERR_S_SCADMINTOOL_0043 "无法发送公告"
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server没有运行"
	#define STRERR_S_SCADMINTOOL_0046 "Field Server没有运行"
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"

	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "帐号名"
//	#define STRMSG_S_SCAT_COLNAME_0001 "类型"
//	#define STRMSG_S_SCAT_COLNAME_0002 "前科"
//	#define STRMSG_S_SCAT_COLNAME_0003 "开始日期"
//	#define STRMSG_S_SCAT_COLNAME_0004 "结束日期"
//	#define STRMSG_S_SCAT_COLNAME_0005 "处理人"
//	#define STRMSG_S_SCAT_COLNAME_0006 "处理事由"
//	#define STRMSG_S_SCAT_COLNAME_0007 "日期"
//	#define STRMSG_S_SCAT_COLNAME_0008 "LOG类型"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "服务器名"
//	#define STRMSG_S_SCAT_COLNAME_0011 "角色名"
//	#define STRMSG_S_SCAT_COLNAME_0012 "位置"
//	#define STRMSG_S_SCAT_COLNAME_0013 "内容"
//	#define STRMSG_S_SCAT_COLNAME_0014 "道具"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "固有编号"
//	#define STRMSG_S_SCAT_COLNAME_0017 "名字"
//	#define STRMSG_S_SCAT_COLNAME_0018 "道具编号"
//	#define STRMSG_S_SCAT_COLNAME_0019 "前缀"
//	#define STRMSG_S_SCAT_COLNAME_0020 "后缀"
	#define STRMSG_S_SCAT_COLNAME_0021 "安装"
//	#define STRMSG_S_SCAT_COLNAME_0022 "数量"
//	#define STRMSG_S_SCAT_COLNAME_0023 "耐久度"
//	#define STRMSG_S_SCAT_COLNAME_0024 "生成时间"
	#define STRMSG_S_SCAT_COLNAME_0025 "未安装"
//	#define STRMSG_S_SCAT_COLNAME_0026 "仓库"
//	#define STRMSG_S_SCAT_COLNAME_0027 "拍卖"
//	#define STRMSG_S_SCAT_COLNAME_0028 "地图"
//	#define STRMSG_S_SCAT_COLNAME_0029 "坐标"
//	#define STRMSG_S_SCAT_COLNAME_0030 "性别"
//	#define STRMSG_S_SCAT_COLNAME_0031 "种族"
//	#define STRMSG_S_SCAT_COLNAME_0032 "权限"
//	#define STRMSG_S_SCAT_COLNAME_0033 "战机种类"
//	#define STRMSG_S_SCAT_COLNAME_0034 "等级"
//	#define STRMSG_S_SCAT_COLNAME_0035 "最高等级"
//	#define STRMSG_S_SCAT_COLNAME_0036 "经验值"
//	#define STRMSG_S_SCAT_COLNAME_0037 "减少的减少值"
//	#define STRMSG_S_SCAT_COLNAME_0038 "自动分配属性点类型"
//	#define STRMSG_S_SCAT_COLNAME_0039 "攻击部分"
//	#define STRMSG_S_SCAT_COLNAME_0040 "防御部分"
//	#define STRMSG_S_SCAT_COLNAME_0041 "燃料部分"
//	#define STRMSG_S_SCAT_COLNAME_0042 "感应部分"
//	#define STRMSG_S_SCAT_COLNAME_0043 "护盾部分"
//	#define STRMSG_S_SCAT_COLNAME_0044 "回避部分"
//	#define STRMSG_S_SCAT_COLNAME_0045 "所属军团"
//	#define STRMSG_S_SCAT_COLNAME_0046 "倾向"
//	#define STRMSG_S_SCAT_COLNAME_0047 "身份"
//	#define STRMSG_S_SCAT_COLNAME_0048 "总登陆时间"
//	#define STRMSG_S_SCAT_COLNAME_0049 "生成时间"
//	#define STRMSG_S_SCAT_COLNAME_0050 "最终登陆时间"
//	#define STRMSG_S_SCAT_COLNAME_0051 "种类"
//	#define STRMSG_S_SCAT_COLNAME_0052 "全体"
	#define STRMSG_S_SCAT_COLNAME_0053 "自动类(1-1型)"
	#define STRMSG_S_SCAT_COLNAME_0054 "转轮机枪类(1-1型)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "双管类(1-1型)" // 2005-08-01 by hblee : grenade -> 变更为Duelist.
	#define STRMSG_S_SCAT_COLNAME_0056 "大炮类(1-1型)"
	#define STRMSG_S_SCAT_COLNAME_0057 "步枪类(1-2型)"
	#define STRMSG_S_SCAT_COLNAME_0058 "机关枪类(1-2型)"
	#define STRMSG_S_SCAT_COLNAME_0059 "发射类(1-2型)"
	#define STRMSG_S_SCAT_COLNAME_0060 "突击类(1-2型)"
	#define STRMSG_S_SCAT_COLNAME_0061 "火箭类(2-1型)"
	#define STRMSG_S_SCAT_COLNAME_0062 "导弹类(2-1型)"
	#define STRMSG_S_SCAT_COLNAME_0063 "集束类(2-1型)"
	#define STRMSG_S_SCAT_COLNAME_0064 "钻地类(2-1型)"
	#define STRMSG_S_SCAT_COLNAME_0065 "护盾类(2-2型)"
	#define STRMSG_S_SCAT_COLNAME_0066 "伪装类(2-2型)"
	#define STRMSG_S_SCAT_COLNAME_0067 "固定类(2-2型)"
	#define STRMSG_S_SCAT_COLNAME_0068 "诱惑类(2-2型)"
	#define STRMSG_S_SCAT_COLNAME_0069 "防御类"
	#define STRMSG_S_SCAT_COLNAME_0070 "补助装备类"
	#define STRMSG_S_SCAT_COLNAME_0071 "能量类"
	#define STRMSG_S_SCAT_COLNAME_0072 "金属类"
	#define STRMSG_S_SCAT_COLNAME_0073 "卡片类"
	#define STRMSG_S_SCAT_COLNAME_0074 "锻造类"
	#define STRMSG_S_SCAT_COLNAME_0075 "坦克类"
	#define STRMSG_S_SCAT_COLNAME_0076 "子弹类"
	#define STRMSG_S_SCAT_COLNAME_0077 "任务用"
	#define STRMSG_S_SCAT_COLNAME_0078 "雷达类"
	#define STRMSG_S_SCAT_COLNAME_0079 "电脑类"
	#define STRMSG_S_SCAT_COLNAME_0080 "机关枪类"
	#define STRMSG_S_SCAT_COLNAME_0081 "锻造破坏防止类"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "爆破类"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "高射机枪类"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "全部道具"
//	#define STRMSG_S_SCAT_COLNAME_0082 "全部服务器"
//	#define STRMSG_S_SCAT_COLNAME_0083 "服务器名"
//	#define STRMSG_S_SCAT_COLNAME_0084 "服务器种类"
//	#define STRMSG_S_SCAT_COLNAME_0085 "服务器 IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "当前玩家数"
//	#define STRMSG_S_SCAT_COLNAME_0087 "服务器状态"
//	#define STRMSG_S_SCAT_COLNAME_0088 "group服务器"
//	#define STRMSG_S_SCAT_COLNAME_0089 "field服务器"
//	#define STRMSG_S_SCAT_COLNAME_0090 "无法获取"
//	#define STRMSG_S_SCAT_COLNAME_0091 "不能运行"
//	#define STRMSG_S_SCAT_COLNAME_0092 "正常"
//	#define STRMSG_S_SCAT_COLNAME_0093 "非正常"
	#define STRMSG_S_SCAT_COLNAME_0094 "GM"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '俺, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "命令list\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- 备份的帐号list ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  帐号: \'%s\', 原来密码: \'%s\', 临时密码: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  帐号: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "请选择更新用 Version的文件夹"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "文件成功生成.\r\n\r\nDB 信息: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  活性) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -非活性) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "服务器的数据成功载入"
//	#define STRMSG_S_SCMONITOR_0011 "服务状态成功反应"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  活性)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -非活性)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "免费服务器服务已停止"
//	#define STRMSG_S_SCMONITOR_0017 "免费服务器服务已开始"
//	#define STRMSG_S_SCMONITOR_0018 "field服务器没有运行"
//	#define STRMSG_S_SCMONITOR_0019 "真的结束 Field Server吗?"
//	#define STRMSG_S_SCMONITOR_0020 "更新版本list信息(最大 1492 Bytes)\r\n\r\n    版本list数量[%3d], 数据大小[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "真的结束 Pre Server吗?"
//	#define STRMSG_S_SCMONITOR_0022 "真的要结束IM Server吗?"
//	#define STRMSG_S_SCMONITOR_0023 "真的要结束NPC Server吗?"
//	#define STRMSG_S_SCMONITOR_0024 "%Y年 %m月 %d日 %H时 %M分 %S秒"
//	#define STRMSG_S_SCMONITOR_0025 "没有活动(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "公测活动(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "不知道活动(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "下次占领战设置时间"
//	#define STRMSG_S_SCMONITOR_0029 "下次占领战基本时间"
//	#define STRMSG_S_SCMONITOR_0030 "占领军团"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> 命令成功\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> 命令失败\r\n"
//	#define STRERR_S_SCMONITOR_0002 "DB无法连接"
//	#define STRERR_S_SCMONITOR_0003 "不存在相关Version "
//	#define STRERR_S_SCMONITOR_0004 "请输入要压缩的文件夹名字"
//	#define STRERR_S_SCMONITOR_0005 "请输入要显示的文件夹名字"
//	#define STRERR_S_SCMONITOR_0006 "请输入开始版本"
//	#define STRERR_S_SCMONITOR_0007 "请输入结束版本"
//	#define STRERR_S_SCMONITOR_0008 "请选择要显示更新用 Zip文件夹"
//	#define STRERR_S_SCMONITOR_0009 "无法连接服务器"
//	#define STRERR_S_SCMONITOR_0010 "请选择服务器!"
//	#define STRERR_S_SCMONITOR_0011 "无法连接DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "更新版本list太多.(版本list数量[%3d], 数据大小[%4dBytes])\r\n\r\n    请整理版本list."
//	#define STRERR_S_SCMONITOR_0014 "以除去的功能.\r\n请用管理工具."
//	#define STRERR_S_SCMONITOR_0015 "不是城市占领战地图"
//	#define STRERR_S_SCMONITOR_0016 "不能制作EDIT控制"
//	#define STRERR_S_SCMONITOR_0017 "上传了已存在的文件"

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "已登陆Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Server[%15s:%4d]终止连接. 正在重试\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to PreServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "已登陆Pre Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Pre Server[%15s:%4d]终止连接. 正在重试\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to  IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "已登陆IM Server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Server[%15s:%4d]终止连接. 正在重试\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "相关道具不存在"
	#define STRMSG_S_F2DBQUERY_0002 "'%s'已申请出席,设置的道具"
	#define STRMSG_S_F2DBQUERY_0003 "已支付. F5打开道具栏确认"
	#define STRMSG_S_F2DBQUERY_0004 "已添加%s(%d)技能"
	#define STRMSG_S_F2DBQUERY_0005 "不存在相关道具."
	#define STRMSG_S_F2DBQUERY_0006 "道具购买失败"

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  城市占领战开始 : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  参加军团 : GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  城市占领战怪物爆发 : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		  伤害合 ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  城市占领战 : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) 占领战时间(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d分钟后 \"%s\" 开始城市占领战."
	#define STRMSG_S_F2CITYWAR_0007 "%d分钟后 \"%s\" 结束城市占领战."
	#define STRMSG_S_F2CITYWAR_0008 "城市占领战(%s) 召唤怪物 : NPC 占领"
	#define STRMSG_S_F2CITYWAR_0009 "城市占领战(%s) 召唤怪 : %s 军团占领"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"目前占领 \"%s\""
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"目前占领 \"%s\""

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "载入任务失败"
	#define STRMSG_S_F2QUEST_0001 "任务没有载入\r\n"
//	#define STRMSG_S_F2QUEST_0002 "任务 \'%30s\' 编号 %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "设置测试用服务器! \r\n\r\nLoadFieldServerDataDebug() 希望除去! "
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: 给%d %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: 给%s %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1型"
	#define STRMSG_S_F2NOTIFY_0003 "2型"
	#define STRMSG_S_F2NOTIFY_0004 "怪1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "怪2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "错误的武器种类! 请咨询管理员!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1型: %4.1f vs %4.1f -> 减少攻击命中率 %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s 失败, 命中率(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s 失败, 命中率(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s 失败, 命中率(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2型: %4.1f vs %4.1f -> 伤害%2.2f%%减少(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "给%s->%s %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "从%s->%s 收到%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "给%s->%s(%d, HP:%5.2f) %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "从%s->%s 收到%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "伪装失败: 命中率不足 > %d"
	#define STRMSG_S_F2NOTIFY_0017 "所剩伪装[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "没有子弹信息. 请咨询管理员."
	#define STRMSG_S_F2NOTIFY_0019 "不存在子弹的口径信息. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "子弹的信息. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "正在处理活动,无法传送"
	#define STRMSG_S_F2NOTIFY_0022 "已死亡,无法传送"
	#define STRMSG_S_F2NOTIFY_0023 "编队中,无法传送"
	#define STRMSG_S_F2NOTIFY_0024 "地图制作错误! 请咨询管理员!"
	#define STRMSG_S_F2NOTIFY_0025 "地图制作错误! 请咨询管理员! %d %d号没有目标INDEX !\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "编队战斗没有结束,无法传送"
	#define STRMSG_S_F2NOTIFY_0027 "传送(%04d) 不能处理 at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "  1 -> 角色 %10s受到 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> 角色 %10s给 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> 角色 %10s给 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> 角色 %10s给 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0032 "  2 -> 角色 %10s受到 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> 角色 %10s给 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> 怪物 %3d给 %5.2f(%d)伤害"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> 角色 %10s 受到%5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> 角色 %10s受到 %5.2f dummy伤害"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> 怪物 %3d给 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0038 "  MINE -> 角色 %10s受到 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0039 "  MINE -> 角色 %10s受到 %5.2fdummy伤害"
	#define STRMSG_S_F2NOTIFY_0040 "  MINE -> 怪物 %10s受到 %5.2f伤害"
	#define STRMSG_S_F2NOTIFY_0041 "已成功初始化属性点"
	#define STRMSG_S_F2NOTIFY_0042 "死亡的时候,无法使用"
	#define STRMSG_S_F2NOTIFY_0043 "没有ENCHANT_INFO "
	#define STRMSG_S_F2NOTIFY_0044 "锻造再炼已成功"
	#define STRMSG_S_F2NOTIFY_0045 "锻造再炼已失败"
	#define STRMSG_S_F2NOTIFY_0046 "没有所属军团"
	#define STRMSG_S_F2NOTIFY_0047 "等待邀请中"
	#define STRMSG_S_F2NOTIFY_0048 "请稍后再试"
	#define STRMSG_S_F2NOTIFY_0049 "自己或者对方不是军团长."
	#define STRMSG_S_F2NOTIFY_0050 "正在军团战争中"
	#define STRMSG_S_F2NOTIFY_0051 "两个军团长不在同一个地图上"
	#define STRMSG_S_F2NOTIFY_0052 "所有队员不在同一个地图上"
	#define STRMSG_S_F2NOTIFY_0053 "所有队员不在同一个地图上"
	#define STRMSG_S_F2NOTIFY_0054 "不属于军团"
	#define STRMSG_S_F2NOTIFY_0055 "申请人和被申请人不同"
	#define STRMSG_S_F2NOTIFY_0056 "自己或对方不是军团长"
	#define STRMSG_S_F2NOTIFY_0057 "两个军团长不在同一个地图上"
	#define STRMSG_S_F2NOTIFY_0058 "不属于军团"
	#define STRMSG_S_F2NOTIFY_0059 "申请人和被申请人不同"
	#define STRMSG_S_F2NOTIFY_0060 "自己或对方不是军团长"
	#define STRMSG_S_F2NOTIFY_0061 "城市占领战防守成功"
	#define STRMSG_S_F2NOTIFY_0062 "任务设置错误. 请咨询管理员."
	#define STRMSG_S_F2NOTIFY_0063 "这个位置不能安装道具(%s)"
	#define STRMSG_S_F2NOTIFY_0064 "引擎不能空"
	#define STRMSG_S_F2NOTIFY_0065 "移动道具: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "错误的道具: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d) 不可处理 at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "地图信息异常!!!请咨询管理员!!!"
	#define STRMSG_S_F2NOTIFY_0069 "没有相关传送目标"
	#define STRMSG_S_F2NOTIFY_0070 "道具购买错误.请咨询管理员"
	#define STRMSG_S_F2NOTIFY_0071 "要购买的技能比当前的技能等级低或一样"
	#define STRMSG_S_F2NOTIFY_0072 "技能购买必需道具错误"
	#define STRMSG_S_F2NOTIFY_0073 "出售道具错误.请咨询管理员"
	#define STRMSG_S_F2NOTIFY_0074 "购买道具错误.请咨询管理员"
	#define STRMSG_S_F2NOTIFY_0075 "\'收费道具\'已购买."
	#define STRMSG_S_F2NOTIFY_0076 "  购买目录 : \'%s(%d个)\'"
	#define STRMSG_S_F2NOTIFY_0077 "已加入队伍."
	#define STRMSG_S_F2NOTIFY_0078 "你是队长,怎么加入?"
	#define STRMSG_S_F2NOTIFY_0079 "正在进行编队战,无法加入"
	#define STRMSG_S_F2NOTIFY_0080 "不支持收集所有队员信息!"
	#define STRMSG_S_F2NOTIFY_0081 "地图活动信息异常!!! 请咨询管理员!!!"
	#define STRMSG_S_F2NOTIFY_0082 "不能交易的帐号"
	#define STRMSG_S_F2NOTIFY_0083 "%s超过装载量."
	#define STRMSG_S_F2NOTIFY_0084 "可移动坐标: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "用户: "
	#define STRMSG_S_F2NOTIFY_0086 "最多可查看20名."
	#define STRMSG_S_F2NOTIFY_0087 "没有相关用户(%s)."
	#define STRMSG_S_F2NOTIFY_0088 "没有加入队伍"
	#define STRMSG_S_F2NOTIFY_0089 "目前时间: %d:%d, 游戏里的时间: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "变更时间: %d:%d, 酒霹 矫埃: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "无法连接NPC服务器"
	#define STRMSG_S_F2NOTIFY_0092 "(%d)道具不存在"
	#define STRMSG_S_F2NOTIFY_0093 "不是Countable Item限制为10个"
	#define STRMSG_S_F2NOTIFY_0094 "地图 \'%s\'的全部在线人数: %d名"
	#define STRMSG_S_F2NOTIFY_0095 "地图%s %s 同时在线人数: %d名 - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "地图%s %s 同时在线人数: %d名 - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "当前地图频道: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "没有子弹信息. 请咨询管理员."
	#define STRMSG_S_F2NOTIFY_0099 "子弹口径信息不存在. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "没有子弹信息. 请咨询管理员."
	#define STRMSG_S_F2NOTIFY_0101 "子弹口径信息不存在. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "没有相关用户(%s)"
	#define STRMSG_S_F2NOTIFY_0103 "相关用户(%s)已死亡状态"
	#define STRMSG_S_F2NOTIFY_0104 "没有相关(%s)用户"
	#define STRMSG_S_F2NOTIFY_0105 "已设置为一般帐号"
	#define STRMSG_S_F2NOTIFY_0106 "一般帐号已解除"
	#define STRMSG_S_F2NOTIFY_0107 "已设置为无敌(不会受伤害)"
	#define STRMSG_S_F2NOTIFY_0108 "已解除无敌(不会受伤害)"
	#define STRMSG_S_F2NOTIFY_0109 "武器带有 %5.0f%% 士气性"
	#define STRMSG_S_F2NOTIFY_0110 "道具重新安装时初始化"
	#define STRMSG_S_F2NOTIFY_0111 "道具重新安装时初始化"
	#define STRMSG_S_F2NOTIFY_0112 "没有相关用户(%s)"
	#define STRMSG_S_F2NOTIFY_0113 "已解除透明技能"
	#define STRMSG_S_F2NOTIFY_0114 "已激活透明技能"
	#define STRMSG_S_F2NOTIFY_0115 "%s 没有进行活动"
	#define STRMSG_S_F2NOTIFY_0116 "%s 活动开始(倍率:%4.2f, 活动时间:%3d分钟)"
	#define STRMSG_S_F2NOTIFY_0117 "已设置为一般premium帐号"
	#define STRMSG_S_F2NOTIFY_0118 "设置premium帐号失败"
	#define STRMSG_S_F2NOTIFY_0119 "超级premium帐号"
	#define STRMSG_S_F2NOTIFY_0120 "不是城市占领战地图"
	#define STRMSG_S_F2NOTIFY_0121 "无法开始城市占领战"
	#define STRMSG_S_F2NOTIFY_0122 "无法结束城市占领战"
	#define STRMSG_S_F2NOTIFY_0123 "已初始化潜行状态"
	#define STRMSG_S_F2NOTIFY_0124 "潜行状态"
	#define STRMSG_S_F2NOTIFY_0125 "无效的地图"
	#define STRMSG_S_F2NOTIFY_0126 "已设置Happy Our活动 [活动时间:%4d分钟)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Our活动结束"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> 被怪物 %3d受到 %5.2f伤stealth害"
	#define STRMSG_S_F2NOTIFY_0129 "  1型 -> 被怪物 %3d受到 %5.2f伤害(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "登陆%s 权限"
	#define STRMSG_S_F2NOTIFY_0131 "  不处理常规终止 %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "  ERROR@CharacterGameEndRoutine(): 逐出队员失败! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' 成功: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' 成功: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: 已停止!"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR: 请咨询管理员! 商店打折变量错误!"
	#define STRMSG_S_F2NOTIFY_0137 "%s已删除"
	#define STRMSG_S_F2NOTIFY_0138 "当前频道没有激活,怪物或其他技能"
	#define STRMSG_S_F2NOTIFY_0139 "停止. 请使用其他频道"
	#define STRMSG_S_F2NOTIFY_0140 "  Warp Obj.[%s,%2d个]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "定时 %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "停止自动恢复HP "
	#define STRMSG_S_F2NOTIFY_0143 "不是可以着陆的地区 HP自动恢复停止"
	#define STRMSG_S_F2NOTIFY_0144 "应急 HP 5.2f 恢复"
	#define STRMSG_S_F2NOTIFY_0145 "自动恢复HP已终止(剩余时间: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "自动恢复护盾已终止(剩余时间: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "自动恢复燃料已终止(剩余时间: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s 活动已结束."
	#define STRMSG_S_F2NOTIFY_0149 "%s 活动进行中 (倍率:%4.2f, 剩余时间:%3d分钟)"
	#define STRMSG_S_F2NOTIFY_0150 "没有运行命令"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	经验值分配错误(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "  无效的Game Start信息错误 ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "  无效的Game Start信息错误 ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "  WARP(%04d) 不可处理 at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "地图活动信息异常!!! 请咨询管理员!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "  EVENT(%d) 不可处理 at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "地图活动信息异常!!! 请咨询管理员!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "  WARP 不可处理 at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "  EVENT(%d) 不可处理(队长) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "  WARP(%04d) 不可处理 at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "  EVENT(%d) 不可处理 at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "  WARP 不可处理 at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "队伍传送失败: %s -> 距离: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "  WARP(%04d) 不可处理 at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "  %s -> 点击重复 OK键!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "任务没有载入.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "  WARP(%s) 不可处理 at HandleAdminCommands(), /移动, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "  WARP(%s) 不可处理 at HandleAdminCommands(), /发送, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "  FATAL ERROR: 不属于会员的field服务器不可以接收此消息. check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "  WARP(%04d) 不可处理 at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "  WARP(%s) 不可以处理 at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "经验值"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "经验值恢复"
	#define STRMSG_S_F2EVENTTYPE_0003 "拾取道具"
	#define STRMSG_S_F2EVENTTYPE_0004 "拾取稀有道具"
	#define STRMSG_S_F2EVENTTYPE_0005 "未知活动"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "已连接Pre Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Pre Server[%15s:%4d]连接已终止.请重试.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'已存在的军团名字"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'已加入军团"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'已存在的旅军团名字"
	#define STRMSG_S_I2NOTIFY_0003 "载入军团失败 - 请咨询管理员!"
	#define STRMSG_S_I2NOTIFY_0004 "好友 '%s'已登陆"
	#define STRMSG_S_I2NOTIFY_0005 "请检查以前的队伍"
	#define STRMSG_S_I2NOTIFY_0006 "基本队伍不存在"
	#define STRMSG_S_I2NOTIFY_0007 "已重新加入队伍"
	#define STRMSG_S_I2NOTIFY_0008 "已加入的队伍."
	#define STRMSG_S_I2NOTIFY_0009 "  Fatal Error: 深刻的队伍错误! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "队员状态错误"
	#define STRMSG_S_I2NOTIFY_0011 "队员已加入军团"
	#define STRMSG_S_I2NOTIFY_0012 "对方已加入军团"
	#define STRMSG_S_I2NOTIFY_0013 "无法邀请自己"
	#define STRMSG_S_I2NOTIFY_0014 "不允许加入的状态"
	#define STRMSG_S_I2NOTIFY_0015 "已超过军团人数"
	#define STRMSG_S_I2NOTIFY_0016 "不允许加入军团状态"
	#define STRMSG_S_I2NOTIFY_0017 "军团长不可以退出"
	#define STRMSG_S_I2NOTIFY_0018 "正在进行军团战,无法退出军团"
	#define STRMSG_S_I2NOTIFY_0019 "正在进行军团战,无法逐出军团队员"
	#define STRMSG_S_I2NOTIFY_0020 "军团长无法逐出"
	#define STRMSG_S_I2NOTIFY_0021 "正在进行军团战"
	#define STRMSG_S_I2NOTIFY_0022 "不能更换为同一个名字"
	#define STRMSG_S_I2NOTIFY_0023 "不能更改名字的状态"
	#define STRMSG_S_I2NOTIFY_0024 "不能更换标志的状态"
	#define STRMSG_S_I2NOTIFY_0025 "不能变更阶级的状态"
	#define STRMSG_S_I2NOTIFY_0026 "阶级重复"
	#define STRMSG_S_I2NOTIFY_0027 "不可以变更军团长阶级"
	#define STRMSG_S_I2NOTIFY_0028 "不可以变更军团长的阶级"
	#define STRMSG_S_I2NOTIFY_0029 "全部用户: %d名 (显示到%d名)"
	#define STRMSG_S_I2NOTIFY_0030 "运营者信息列表已添加"
	#define STRMSG_S_I2NOTIFY_0031 "运营者信息列表已除去"
	#define STRMSG_S_I2NOTIFY_0032 "服务器 IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "服务器群 \'%s\'的全部在线人数: %d名"
	#define STRMSG_S_I2NOTIFY_0034 "真的要结束服务器(%s)吗? 数字: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'没有进行游戏 "
	#define STRMSG_S_I2NOTIFY_0036 "全部用户数: %d名 (只显示%d名)"
	#define STRMSG_S_I2NOTIFY_0037 "/发送 %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "没有相关军团"
	#define STRMSG_S_I2NOTIFY_0039 "解除中断悄悄话!"
	#define STRMSG_S_I2NOTIFY_0040 "悄悄话已中断!"
	#define STRMSG_S_I2NOTIFY_0041 "没有加入军团"
	#define STRMSG_S_I2NOTIFY_0042 "军团(%d)无效"
	#define STRMSG_S_I2NOTIFY_0043 "不存在相关天气(%s)"
	#define STRMSG_S_I2NOTIFY_0044 "Field Server无效"
	#define STRMSG_S_I2NOTIFY_0045 "不存在相关地图(%s)"
	#define STRMSG_S_I2NOTIFY_0046 "您处于 %d分钟禁止聊天状态!!"
	#define STRMSG_S_I2NOTIFY_0047 "设置禁止聊天 : '%10s', %3d分钟"
	#define STRMSG_S_I2NOTIFY_0048 "解除禁止聊天状态"
	#define STRMSG_S_I2NOTIFY_0049 "解除禁止聊天 : '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(帐号: %s, 地图: %d(%d), 等级: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "不能"
	#define STRMSG_S_I2NOTIFY_0052 "没有相关公会."

	#define STRMSG_S_IMSERVER_050607_0001	"没有相关地图."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Field Server已连接.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Field Server[%15s:%4d]连接已终止. 请重试.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							怪物和目标没有冲突\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "召唤城市占领战怪物(%10s) \r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "铁民号"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%s 帐号(%s)已登陆. IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "成功"
	#define STRMSG_S_P2PRENOTIFY_0002 "失败"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR] 帐号信息添加错误, AccountName(%s)  privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"您好,我是客服中心"
	#define STRMSG_SCAT_051115_0002		"今天9点到11点ACE online停机维护"
	#define STRMSG_SCAT_051115_0003		"请移动到安全的地方后结束游戏."
	#define STRMSG_SCAT_051115_0004		"首先从NPC服务器开始终止"
	#define STRMSG_SCAT_051115_0005		"现在开始ACE online停机维护"
	#define STRMSG_SCAT_051115_0006		"ACE online祝你愉快"
	#define STRMSG_SCAT_051115_0007		"稍后紧急停机维护"
	#define STRMSG_SCAT_051115_0008		"维护时间是120分钟."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"透明状态: 玩家看不见, 所有武器不能使用"
	#define STRMSG_060509_0001			"无敌状态: 不受伤害"
	#define STRMSG_060509_0002			"潜行模式: 不会被先攻型怪物攻击"

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you momentarily."
	#define	STRMSG_060526_0001			"无法运行自动更新.\r\n\r\n主页(%s) 从下载页面手动下载补丁包后登陆.\r\n\r\n    Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"当前输入的ID没有登陆\r\n ID或者密码输入错误."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"当前服务正在维护. 具体事项请参考主页."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"客户端版本不同.\r\n  从主页手动下载补丁包或请重新安装客户端."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"被%s击落."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000			"初始化活动服务器群 DB(atum2_db_20) 需要结束活动服务器群."
	#define STRMSG_070410_0001			"确定要初始化活动服务器 DB(atum2_db_20)吗? [认证数字:%d]"
	#define STRMSG_070410_0002			"已初始化活动服务器 DB(atum2_db_20)."
	#define STRMSG_070410_0003			"初始化活动服务器 DB(atum2_db_20)失败!!"
	#define STRMSG_070410_0004			"完成复制'%s'的信息到活动服务器 DB(atum2_db_20)."
	#define STRMSG_070410_0005			"'%s'的信息复制到活动服务器 DB(atum2_db_20)失败 - 角色不存在 !!"
	#define STRMSG_070410_0006			"'%s'的信息复制到活动服务器 DB(atum2_db_20)失败 - 大会服务器已存在帐号的角色 !!"
	#define STRMSG_070410_0007			"'%s'的信息复制到活动服务器 DB(atum2_db_20)失败 - 添加DB错误 !!"
	#define STRMSG_070410_0008			"'%s'的信息复制到活动服务器 DB(atum2_db_20)失败 - 未知(%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, 秦惑档 巩磊凯 
	// 2007-07-24 by cmkwon, 繁贸俊辑 800*600 秦惑档 昏力 - 霓焊冠胶 胶飘傅 鞘夸 绝澜
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (低)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (中)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (高)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (低)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (中)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (高)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 宽屏(高)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (低)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (中)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (高)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (低)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (中)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (高)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 宽屏(高)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (低)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (中)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (高)"

// 2007-06-15 by dhjin, 包傈 包访 胶飘傅
#define STRMSG_070615_0000				"非透明状态，无法观战."
#define STRMSG_070615_0001				"无法观战."
#define STRMSG_070620_0000				"一般势力无法观战."

// 2007-06-26 by dhjin, 况器牢飘 捞亥飘 包访 眠啊
#define STRMSG_S_F2EVENTTYPE_0006		"战争点数"

// 2007-06-28 by cmkwon, 吝惫 规缴秒包访(霸烙 矫埃 舅覆 备泅) - 胶飘傅 眠啊
#define STRMSG_070628_0000				"您累计在线时间已满%d小时."
#define STRMSG_070628_0001				"您累计在线时间已满%d小时.请您下线休息,做适当身体活动."
#define STRMSG_070628_0002				"您已经进入疲劳游戏时间.您的游戏收益将降为正常值的50%%.为了您的健康,请尽快下线休息,适当运动,合理安排学习生活."
#define STRMSG_070628_0003				"您已进入不健康游戏时间.为了您的健康,请您立即下线休息.如不下线,您的身体将受到损害.您的游戏收益已降为零.直到您的累计下线时间满5小时后,才能恢复正常."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000				"\'%s\'不是禁止进入阿雷纳状态."
#define STRMSG_070711_0001				"\'%s\'是禁止进入阿雷纳状态.(剩余时间:%d分钟)"
#define STRMSG_070711_0002				"您在%d分钟之内禁止进入阿雷纳系统!!"
#define STRMSG_070711_0003				"您的禁止进入阿雷纳状态已解除."
#define STRMSG_070711_0004				"\'%s\'的禁止进入阿雷纳状态已解除."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide 秦惑档 1280x720(16:9) 眠啊 - 胶飘傅 眠啊
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 宽屏(高)"

// 2007-08-30 by cmkwon, 雀狼冯 矫胶袍 备泅 - 胶飘傅 眠啊
#define STRMSG_070830_0001				"选择势力之后可以使用该命令."
#define STRMSG_070830_0002				"相关势力的会议房间 (%d)是无效的"
#define STRMSG_070830_0003				"当前可以进入会场的人数: %d人"
#define STRMSG_070830_0004				"'%s'拥有会议房间入场权限."
#define STRMSG_070830_0005				"'%s'没有会议房间入场权限."
#define STRMSG_070830_0006				"'%s'不是有效的角色."
#define STRMSG_070830_0007				"无法将'%s'添加到会议房间入场权限列表里.(最多 %d人)"
#define STRMSG_070830_0008				"给'%s'授予了会议房间入场权限."
#define STRMSG_070830_0009				"授予会议房间入场权限."
#define STRMSG_070830_0010				"解除会议房间入场权限."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001				"\\y已赠送%s %s道具"
#define STRMSG_071115_0002				"礼品目录 : \'%s(%d个)\'"
#define STRMSG_071115_0003				"\\y%s赠送 %s %s道具。请到仓库确认。"
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001				"目前不是亲情系统开放时间。请咨询客户服务器中心。"
#define STRMSG_071120_0002				"亲情系统已开放。"
#define STRMSG_071120_0003				"亲情系统已关闭。"
#define STRMSG_071120_0004				"亲情系统开放时间是%s到%s 。"

// 2007-11-28 by cmkwon, 烹瘤矫胶袍 备泅 - 
#define STRMSG_071128_0001				"%s赠送%s道具%d个。请到仓库确认。"

// 2007-12-27 by cmkwon, 扩档快令 葛靛 扁瓷 眠啊 - 
#define STRMSG_071228_0001				"分辨率设置无效，请重新设置。"

// 2008-01-31 by cmkwon, 拌沥 喉钒/秦力 疙飞绢肺 啊瓷茄 矫胶袍 备泅 - 
#define STRMSG_080201_0001				"封停'%s'发生错误，ErrorCode(%d)"
#define STRMSG_080201_0002				"成功封停'%s'，[Block End Date: %s]"
#define STRMSG_080201_0003				"'%s'帐号不在封停列表中，ErrorCode(%d)"
#define STRMSG_080201_0004				"解封'%s'帐号发生错误，ErrorCode(%d)"
#define STRMSG_080201_0005				"成功解封'%s'帐号"

// 2008-02-11 by cmkwon, 秦惑档 眠啊(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (低)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (中)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (高)"

// 2007-12-27 by dhjin, 酒饭唱烹钦- 酒饭唱辑滚楷搬包访坷幅
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), Can't connect to  ArenaServer[%15s:%4d] Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001 "已连接阿雷娜服务器.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002 "与阿雷娜服务器[%15s:%4d]连接中断，请重新连接。\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001		"\\y%d号等待房间已开启阿雷纳活动。\r\n"
#define STRMSG_ARENAEVENT_080310_0002		"\\y%d号房间已取消阿雷纳活动。\r\n"
#define STRMSG_ARENAEVENT_080310_0003		"\\y开启阿雷纳活动失败。\r\n"
#define STRMSG_080428_0001					"已击落%s。"		// 2008-04-28 by dhjin, 跨服阿雷纳 - 增加击落对方提示，仅在阿雷纳地图有效

// 2008-04-29 by cmkwon, 辑滚焙 沥焊 DB俊 眠啊(脚痹 拌沥 某腐磐 积己 力茄 矫胶袍眠啊) - 
#define STRMSG_080430_0001					"您选择的服务器不能创建新角色。"

// 2008-06-13 by dhjin, EP3 咯窜 荐沥 荤亲 - 
#define STRMSG_080613_0001					"%s军团拒绝您的申请。"

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, 瘤档磊 盲泼 力茄 墨靛 备泅 - 
#define STRMSG_081230_0001 "\\y%s将在%d分钟内被禁言。\\y"
#define STRMSG_081230_0002 "\\y被领袖禁言%d分钟。\\y"
#define STRMSG_081230_0003 "\\y领袖解除禁言。\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D 霸烙啊靛 悼狼芒 剁快扁 - 
// 2009-09-02 by cmkwon, Gameforge4D 霸烙 啊靛 悼狼芒 WebPage肺 贸府 - STRMSG_090831_0001绰 昆其捞瘤肺 贸府
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D 霸烙 啊靛 悼狼芒 WebPage肺 贸府 - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, 瘤盔 秦惑档 眠啊(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 宽屏(高)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 宽屏(高)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 宽屏(低)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 宽屏(中)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 宽屏(高)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, 牢刘 辑滚狼 立加 倾侩 惑炔
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Not Registered Server (It can be Illegal Private Server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Error occurs during linkage with DB"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Authentication succeed"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Registered Server IP But proceed Authentication Denied"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows Shut Down command is sent to the server."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, 颇飘呈 - 绢靛刮 砒 颇飘呈 扁瓷俊辑 荤侩登绰 MSG
#define STRERR_S_SCADMINTOOL_0048 "This socket item is equiped with Partner. You can remove it from the property of partner equipped with \n socket."
#define STRERR_S_SCADMINTOOL_0049 "Saving the log about the changes of the property of partner is failed.\r\n(Change of the property of partner is complete, only log failed to be saved.)"
#define STRERR_S_SCADMINTOOL_0050 "The loading for partner information is failed."
#define STRERR_S_SCADMINTOOL_0051 "The equipped socket item is failed to be deleted."
#define STRERR_S_SCADMINTOOL_0052 "The applying hidden option for equipped item is failed."
#define STRERR_S_SCADMINTOOL_0053 "The revision for the Partner’s socket item is failed."
#define STRERR_S_SCADMINTOOL_0054 "The update information of partner is failed."
#define STRERR_S_SCADMINTOOL_0055 "The information loading for partner lever is failed."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, 款康砒扁瓷眠啊, 牢忙飘酒捞袍力芭扁瓷
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, 款康砒扁瓷眠啊, 牢忙飘酒捞袍力芭扁瓷. End

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 飘府芭 矫胶袍 捞亥飘 舅覆

// 1瞒 捞亥飘

#define STRMSG_120330_0001					"%s activates the warp gate to Hidden Place in Ash Lane."
#define STRMSG_120330_0002					"%s activates 100%%%% increase for monster EXP (1 hour) in Ash Lane."
#define STRMSG_120330_0003					"%s activates 100%%%% increase for item drop rate (1 hour) in Ash Lane."
#define STRMSG_120330_0004					"%s activates 100%%%% increase for item drop rate/monster EXP/SPI (1 hour) in Ash Lane."
#define STRMSG_120330_0005					"%s activates Weapon Shop in Ash Lane."
#define STRMSG_120330_0006					"%s activates Hyper Card shop in Ash Lane."
#define STRMSG_120330_0007					"%s activates Kit Shop in Ash Lane."
#define STRMSG_120330_0008					"%s summons a boss monster in Ash Lane!"
#define STRMSG_120330_0009					"Crystals have disappeared."

// 2瞒 捞亥飘

#define STRMSG_120508_0001					"%s obtains %d War Points in Lost Oasis."
#define STRMSG_120508_0002					"%s summons a boss monster in Lost Oasis!"
#define STRMSG_120508_0003					"%s activates 150%%%% increase for monster EXP (1 hour) in Lost Oasis."
#define STRMSG_120508_0004					"%s activates 150%%%% increase for item drop rate (1 hour) in Lost Oasis."
#define STRMSG_120508_0005					"%s activates 150%%%% increase for item drop rate/monster EXP/SPI (1 hur) in Lost Oasis."
#define STRMSG_120508_0006					"%s obtains Ancient Ice in Lost Oasis."
#define STRMSG_120508_0007					"%s activates Advanced Item Shop in Lost Oasis."
#define STRMSG_120508_0008					"%s activates Kit Shop in Lost Oasis."
#define STRMSG_120508_0009					"%s activates Hyper Card Shop in Lost Oasis."
#define STRMSG_120508_0010					"%s activates Weapon Shop in Lost Oasis."
#define STRMSG_120508_0011					"%s activates the warp gate to Hidden Place in Lost Oasis."

#define STRMSG_120712_0001					"18技 固父 没家斥俊霸 利侩登绰 霸烙矫埃 急琶力 汲沥栏肺 牢窍咯, %d 盒 饶俊 霸烙捞 辆丰邓聪促."		// 2012-07-11 by hskim, 急琶利 妓促款

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc规 葛碘
#define STRMSG_121005_0001					"\\yPC规 啊竿痢 矫埃捞 %d盒 巢疽嚼聪促."
#define STRMSG_121005_0002					"\\y泪矫 饶 PC规 啊竿痢捞 辆丰邓聪促."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, 傈里 矫胶袍 府春倔 - 傈里矫 飘府芭 公利惑怕(老矫沥瘤)
#define STRMSG_121126_0001					"\\yWar is in progress. Crystal Trigger system has been taken offline for the duration.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX捞亥飘 甘 况橇力茄
#define STRMSG_121129_0001					"\\y款康磊俊 狼窍咯 捞悼捞 力茄等 瘤开 涝聪促.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC 傈傈扁瘤 飘府芭 矫胶袍
#define STRMSG_130121_0001					"\\cNGC 技仿俊 狼秦 矫胶袍捞 痢飞 寸沁嚼聪促. 变鞭 蓖券 矫胶袍阑 啊悼 钦聪促."
#define STRMSG_130121_0002					"\\c沥蔓措 : 力绢扁 积己 犬牢."
#define STRMSG_130121_0003					"\\c沥蔓措 : 力绢扁 颇鲍 犬牢."
#define STRMSG_130121_0004					"\\c疙飞 : 绊葛扼啊 规绢阜 橇肺弊伐阑 啊悼窍看促 ! 力绢扁甫 颇鲍窍咯 规绢阜 橇肺弊伐阑 公瓤拳 矫难扼 !"
#define STRMSG_130121_0005					"\\c疙飞 : 绊葛扼狼 规绢阜捞 颇鲍登菌促. 傈焙 傍拜 !"
#define STRMSG_130121_0006					"\\c疙飞 : 绊葛扼啊 颇鲍登菌促! 傈焙 柳拜 !"
#define STRMSG_130121_0007					"\\c疙飞 : 绊葛扼甫 刚历 颇鲍秦具 茄促."
#define STRMSG_130121_0008					"\\c力绢扁狼 康氢栏肺 [%s\\c] 瓤苞啊 惯悼 邓聪促."
#define STRMSG_130121_0009					"\\y[NGC 傈柳扁瘤 矫胶袍]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, 酒捞袍 捞亥飘 - 辑宏鸥涝 眠啊备炼 矫胶袍 焊救
#define STRMSG_130422_0001					"\\y酒饭唱 辑滚甫 捞侩 吝 捞骨肺 捞亥飘 酒捞袍 %s %d俺啊 芒绊肺 瘤鞭登菌嚼聪促.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim 酒赣 拿泛记 - STRMSG 眠啊
#define STRMSG_130531_0001					"\\g[%s] 寇屈捞 酒赣拿泛记俊 殿废 登菌嚼聪促."
#define STRMSG_130531_0002					"\\g[%s] 寇屈捞 [%2d]雀 内泼 登菌嚼聪促."
#define STRMSG_130531_0003					"\\g[%s] 寇屈狼 内泼 冉荐啊 弥措摹 捞骨肺 [%s] 酒捞袍栏肺 函版 登菌嚼聪促."
#define STRMSG_130531_0004					"泅犁 利侩 吝牢 寇屈狼 扁埃捞 父丰登绢 浚柳捞 馒侩 秦力登菌嚼聪促."
#define STRMSG_130531_0005					"\\y浚柳 固厘馒栏肺 牢秦 档矫肺 变鞭 蓖券 登菌嚼聪促."
#define STRMSG_130531_0006					"\\g厘馒吝牢 寇屈狼 拿泛记 酒捞袍篮 荤侩且荐 绝嚼聪促."
#define STRMSG_130531_0007					"\\g寇屈捞 函版 登菌嚼聪促."
#define STRMSG_130531_0008					"\\g[%s] 寇屈狼 扁埃捞 父丰 登菌嚼聪促."
#define STRMSG_130531_0009					"\\y拿仿记捞 利侩等 酒捞袍篮 备概惑痢俊 魄概且 荐 绝嚼聪促."
#define STRMSG_130531_0010					"\\y扁绢 鸥涝捞 嘎瘤 臼嚼聪促."

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
