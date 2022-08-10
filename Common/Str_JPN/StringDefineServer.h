
// 2005-04-28 by cmkwon

#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_




///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre ServerI"
	#define STRERR_S_ATUMEXE_0003 "Ž©“®±¯ÌßÃÞ-Ä‚ÉŽ¸”s‚µ‚Ü‚µ‚½B\r\n¹Þ-Ñ‚ðÄ²Ý½Ä-Ù‚µ‚Ä‚­‚¾‚³‚¢B\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error:%s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "ÀÞ³ÝÛ-ÄÞ»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMEXE_0007 "ÀÞ³ÝÛ-ÄÞÌ§²Ù‚ÌƒTƒCƒY‚ª•s–¾‚Å‚·B"
	#define STRERR_S_ATUMEXE_0008 "±¯ÌßÃÞ-ÄÌ§²Ù‚ðÀÞ³ÝÛ-ÄÞ‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "Ì§²Ù‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "update completed"
	#define STRMSG_S_ATUMLAUNCHER_0001 "»-ÊÞ-‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "deleting files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "update completed(%s->%s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "ŽÀsÌ§²Ù‘I‘ð"
	#define STRMSG_S_ATUMLAUNCHER_0007 "ŽÀsƒ‹-ƒg‘I‘ð"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading is canceled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Getting File Information %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°E
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°E
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "”FØ»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0005 "»-ÊÞ-Ú‘±‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "ƒNƒ‰ƒCƒAƒ“ƒg‚ðÄ“xÀÞ³ÝÛ-ÄÞ‚µ‚Ä‚­‚¾‚³‚¢B\nURL: http://space.mgame.com/\nÅVÊÞ-¼Þ®Ý:"
	#define STRERR_S_ATUMLAUNCHER_0009 "Ž©“®±¯ÌßÃÞ-Ä‚ÉŽ¸”s‚µ‚Ü‚µ‚½B\r\nƒNƒ‰ƒCƒAƒ“ƒg‚ðÄ²Ý½Ä-Ù‚ð‚µ‚Ä‚­‚¾‚³‚¢B\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "‘S‚Ä‚Ì»-ÊÞ-‚ª”ñŠˆ«ó‘Ô‚Å‚·B"
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%sƒƒ“ƒeƒiƒ“ƒX’†c"
	#define STRERR_S_ATUMLAUNCHER_0012 "‘S‚Ä‚ÌƒT-ƒo‚ªƒƒ“ƒeƒiƒ“ƒX’†‚Å‚·B‚µ‚Î‚ç‚­Œã‚ÉÚ‘±‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from%s[%s]\r\n"
// 2006-08-24 by cmkwon, Change to STRMSG_060824_0000
//	#define STRERR_S_ATUMLAUNCHER_0014 "ŠÔˆá‚Á‚Ä‚¢‚éID‚Å‚·AÊß½Ü-ÄÞ´×-\n\n* Œ»Ý‚ÍÍÞ-ÀÃ½Ä?ƒAƒJƒEƒ“ƒg‚ðŠ—L‚µ‚Ä‚¢‚é»-ÊÞ-‚Ì‚Ý‚ªƒƒOƒCƒ“‚Å‚«‚Ü‚·B"
	#define STRERR_S_ATUMLAUNCHER_0015 "Û¸Þ²Ý´×-"
	#define STRERR_S_ATUMLAUNCHER_0016 "ID–¢“ü—Í"
	#define STRERR_S_ATUMLAUNCHER_0017 "d•¡ƒƒOƒCƒ“"
	#define STRERR_S_ATUMLAUNCHER_0018 "»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0019 "»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0020 "»-ËÞ½‚ªˆêŽž“I‚É’†’f‚³‚ê‚¢‚Ü‚·B\n\n‚µ‚Î‚ç‚­Œã‚ÉÚ‘±‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_ATUMLAUNCHER_0021 "¬ŽG‚µ‚Ä‚¢‚é‚½‚ßƒƒOƒCƒ“‚Å‚«‚Ü‚¹‚ñB\n\n‚µ‚Î‚ç‚­Œã‚ÉÚ‘±‚µ‚Ä‚­‚¾‚³‚¢B"

	
	#define STRERR_S_ATUMLAUNCHER_0022 "‚±‚ÌƒAƒJƒEƒ“ƒg‚ÍƒuƒƒbƒN‚³‚ê‚Ä‚¢‚Ü‚·B\nŠúŠÔ:%s\n\n•s–¾‚Èê‡A¶½ÀÏ-¾ÝÀ-‚É–â‚¢‡‚í‚¹‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_ATUMLAUNCHER_0023 "¸×²±ÝÄÊÞ-¼Þ®Ý‚ªˆÙ‚È‚è‚Ü‚·B\n\nƒNƒ‰ƒCƒAƒ“ƒg‚ðÄ“xÀÞ³ÝÛ-ÄÞ‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR:%s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "ÀÞ³ÝÛ-ÄÞ»-ÊÞ-‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0026 "ÀÞ³ÝÛ-ÄÞÌ§²Ù(%s)‚ÌƒTƒCƒY‚ª•s–¾‚Å‚·B"
	#define STRERR_S_ATUMLAUNCHER_0027 "ÀÞ³ÝÛ-ÄÞÌ§²Ù‚ÌƒTƒCƒY‚ª•s–¾‚Å‚·B"
	#define STRERR_S_ATUMLAUNCHER_0028 "±¯ÌßÃÞ-ÄÌ§²Ù‚ðÀÞ³ÝÛ-ÄÞ‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0029 "±¯ÌßÃÞ-ÄÌ§²Ù‚ª‘¶Ý‚µ‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0030 "»-ÊÞ-ÒÝÃÅÝ½’†‚Å‚·B‚µ‚Î‚ç‚­Œã‚ÉÚ‘±‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "Ì§²Ù‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB"
	#define STRERR_S_ATUMLAUNCHER_0034 "ƒ‹-ƒg‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñB"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type:%s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹Ì¸¸ Ã»¼Ò³â¿¡°Ô Àû¿EÇ´?°ÔÀÓ½Ã°£ ¼±ÅÃÁ¦ ¼³Á¤À¸·Î ÀÎÇÏ¿©, ÇöÀE½Ã°£¿¡´Â °ÔÀÓ ÁøÇàÀÌ ºÒ°¡´ÉÇÕ´Ï´Ù.\n\nÀÚ¼¼ÇÑ »çÇ×Àº ¿¡ÀÌ½º¿Â¶óÀÎ °úÌ´¼¾ÅÍ·Î ¹®ÀÇ¹Ù¶ø´Ï´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀE¼Ë´Ù¿E
	#define STRMSG_S_ATUMLAUNCHER_0038 "°ÔÀÓÀ» ´Ù½Ã ½ÃÀÛÇØ ÁÖ½Ê½Ã¿E\r\n\r\n¹®Á¦°¡ Áö¼ÓÀûÀ¸·Î ¹ß»ýµÇ¸E¿¡ÀÌ½º¿Â¶óÀÎ °úÌ´¼¾ÅÍ·Î ¹®ÀÇ¹Ù¶ø´Ï´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀE¼Ë´Ù¿E


	#define STRMSG_S_050506		"\'%s\'—l‚ÍŒ»ÝƒAƒJƒEƒ“ƒgƒuƒƒbƒN‚³‚ê‚Ä‚¢‚Ü‚·B\n——R:%s\nŠúŠÔ:%s?%s\n\n•s–¾‚Èê‡‚ÍA¶½ÀÏ-¾ÝÀ-‚É–â‚¢‡‚í‚¹‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_S_050930		"ƒNƒ‰ƒCƒAƒ“ƒg‚ðÄ“xÀÞ³ÝÛ-ÄÞ‚µ‚Ä‚­‚¾‚³‚¢B\nURL:%s\nÅVÊÞ-¼Þ®Ý"
// 2_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "’j"
//	#define STRMSG_S_SCADMINTOOL_0001 "—"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d”NA%dÎ"
//	#define STRMSG_S_SCADMINTOOL_0003 "–{“–‚ÉƒAƒJƒEƒ“ƒgî•ñ‚ð•ÏX‚µ‚Ü‚·‚©H "
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) +'ŒÂŽæ“¾A'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
//	#define STRMSG_S_SCADMINTOOL_0006 "''''+l.PeerCharacterName+'''‚É'+ CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ“n‚·A'+CAST(l.CurrentCount AS VARCHAR(10)) +'ŒÂ'"
//	#define STRMSG_S_SCADMINTOOL_0007 "''''+l.PeerCharacterName+'''‚©‚ç'+CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ‚à‚ç‚¤A'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂŽÌ‚Ä‚éA'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂw“üAŽc‚èSPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ”Ì”„AŽc‚èSPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0012 "''''+l.PeerCharacterName+'''‚ª'+CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ’Ç‰Á‚·‚éA'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0013 "''''+l.PeerCharacterName+'''‚ª'+CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂíœ‚·‚éA'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0014 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ’Ç‰ÁA'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0015 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂ—a‚¯‚éA'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0016 "CAST(l.ChangeCount AS VARCHAR(10))+'ŒÂˆø‚«o‚·A'+CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'¹Þ-ÑŽžŠÔ\'+dbo.atum_GetHMSFromS(l.PlayTime)+\'A‘\'+dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10))+'->'+CAST(l.Param2 AS VARCHAR(10))+',¹Þ-ÑŽžŠÔ:'+dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15))+\'‘Œ¸A‘\'+CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Õ“Ë"
//	#define STRMSG_S_SCADMINTOOL_0021 "ÓÝ½À-"
//	#define STRMSG_S_SCADMINTOOL_0022 "ƒMƒA"
//	#define STRMSG_S_SCADMINTOOL_0023 "Œ´ˆö•s–¾"
//	#define STRMSG_S_SCADMINTOOL_0024 "%sAŽc‚è½Ã-À½:%s"
	#define STRMSG_S_SCADMINTOOL_0025 "(‚È‚µ)"
//	#define STRMSG_S_SCADMINTOOL_0026 "Ž„"
//	#define STRMSG_S_SCADMINTOOL_0027 "‚È‚µ"
//	#define STRMSG_S_SCADMINTOOL_0028 "ƒoƒOŽg—pÕ-»Þ-"
	#define STRMSG_S_SCADMINTOOL_0029 "ƒAƒJƒEƒ“ƒgƒuƒƒbƒN"
	#define STRMSG_S_SCADMINTOOL_0030 "Á¬¯ÄÌÞÛ¯¸"
//	#define STRMSG_S_SCADMINTOOL_0031 "Ú‘±ƒƒO"
//	#define STRMSG_S_SCADMINTOOL_0032 "Õ-»Þ-Û¸Þ"
//	#define STRMSG_S_SCADMINTOOL_0033 "±²ÃÑÛ¸Þ"
	#define STRMSG_S_SCADMINTOOL_0034 "%s-%s»-ÊÞ-"
	#define STRMSG_S_SCADMINTOOL_0035 "%s-%s»-ÊÞ-A%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "ƒAƒJƒEƒ“ƒgƒuƒƒbƒN"
//	#define STRMSG_S_SCADMINTOOL_0037 "•ª—Þ"
//	#define STRMSG_S_SCADMINTOOL_0038 "’l"
	#define STRMSG_S_SCADMINTOOL_0039 "ƒAƒJƒEƒ“ƒgƒuƒƒbƒN‚ð‰ðœ‚µ‚Ü‚·‚©H"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d•b)"
	#define STRMSG_S_SCADMINTOOL_0041 "%dŸ %d”s"
	#define STRMSG_S_SCADMINTOOL_0042 "‚±‚ÌƒAƒJƒEƒ“ƒg‚ÌÚ‘±‚ðØ’f‚µ‚ÄƒuƒƒbƒN‚µ‚Ü‚·‚©H"
	#define STRMSG_S_SCADMINTOOL_0043 "%s±²ÃÑ"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s%15s]‚¨’m‚ç‚¹:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Õ-»Þ-”:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s%15s]ŽóM‚µ‚½Ò¯¾-¼Þ:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s%15s]ƒ†-ƒU-”:%4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s%15s]FieldServer state:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "»-ÊÞ-‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½B\nSocket Name:%s\nIP:%s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "ŠY“–ƒAƒJƒEƒ“ƒgî•ñ‚ð“Ç‚Ýž‚ß‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0001 "ƒAƒJƒEƒ“ƒgî•ñ‚Ì•ÏX‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"
	#define STRERR_S_SCADMINTOOL_0002 "Êß½Ü-ÄÞ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0003 "Êß½Ü-ÄÞ‚ªŠÔˆá‚Á‚Ä‚¢‚Ü‚·B"
	#define STRERR_S_SCADMINTOOL_0004 "ID‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server‚ªŽÀs‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0006 "Can not connect to PreServer !!"
//	#define STRERR_S_SCADMINTOOL_0007 "”FØ‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"			// 2006-04-11 by cmkwon, ?????
	#define STRERR_S_SCADMINTOOL_0008 "ERROR:ŠY“–ƒvƒƒgƒRƒ‹‚ª‘¶Ý‚µ‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0009 "ID‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0010 "——R‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0011 "ŒoŒ±’lÝ’è´×-:Level%2d==>Exp(%.1I64f?%.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Å‘åƒƒO”‚ð’´‰ß‚µ‚Ü‚µ‚½B\r\n\r\nÅ‘åƒƒO”‚âŒŸõðŒ‚ðC³‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0013 "Database‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0014 "Ú‘±Ž¸”s"
	#define STRERR_S_SCADMINTOOL_0015 "Ú‘±¬Œ÷"
	#define STRERR_S_SCADMINTOOL_0016 "±¯ÌßÃÞ-Ä’†"
	#define STRERR_S_SCADMINTOOL_0017 "ƒƒOƒCƒ“¬Œ÷"
	#define STRERR_S_SCADMINTOOL_0018 "·¬×¸À-‘I‘ð’†"
	#define STRERR_S_SCADMINTOOL_0019 "¹Þ-Ñ’†"
	#define STRERR_S_SCADMINTOOL_0020 "•s–¾"
	#define STRERR_S_SCADMINTOOL_0021 "Database%s(%s:%d)‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0022 "±²ÃÑ’Ç‰ÁŽ¸”s"
	#define STRERR_S_SCADMINTOOL_0023 "ƒuƒƒbƒNƒAƒJƒEƒ“ƒg‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B"
	#define STRERR_S_SCADMINTOOL_0024 "C³‚Ì‚½‚ßŠY“–ƒAƒJƒEƒ“ƒg‚ÌÚ‘±‚ðØ’f‚µAƒAƒJƒEƒ“ƒg‚ðƒuƒƒbƒN‚µ‚Ä‚­‚¾‚³‚¢I"
	#define STRERR_S_SCADMINTOOL_0025 "SPI‚Í’Ç‰Á‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0026 "‘I‘ð‚µ‚½±²ÃÑ‚ÍŠù‚É‘¶Ý‚µ‚Ä‚¢‚Ü‚·BŒÂ”‚ðC³‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0027 "±²ÃÑŒŸõ´×-"
	#define STRERR_S_SCADMINTOOL_0028 "·¬×¸À-‚ªŠ—L‚µ‚Ä‚¢‚éSPI‚Ííœ‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0029 "±²ÃÑ‚ðíœ‚µ‚Ü‚·‚©H"
	#define STRERR_S_SCADMINTOOL_0030 "±²ÃÑ‚Ìíœ‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"
	#define STRERR_S_SCADMINTOOL_0031 "±²ÃÑ‚ÌC³‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"
	#define STRERR_S_SCADMINTOOL_0032 "ƒAƒJƒEƒ“ƒg‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0033 "ƒAƒJƒEƒ“ƒg‚ª‘¶Ý‚µ‚Ü‚¹‚ñB(ƒAƒJƒEƒ“ƒgƒuƒƒbƒNÝ’è‚Í‰Â?)"
	#define STRERR_S_SCADMINTOOL_0034 "ƒAƒJƒEƒ“ƒg‚Ü‚½‚Í·¬×¸À-‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0035 "·¬×¸À-î•ñÆ‰ï´×-‚Å‚·B"
	#define STRERR_S_SCADMINTOOL_0036 "ŠY“–·¬×¸À-‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0037 "·¬×¸À-±¯ÌßÃÞ-Ä´×-‚Å‚·B"
	#define STRERR_S_SCADMINTOOL_0038 "·¬×¸À-î•ñ‚Ì±¯ÌßÃÞ-Ä‚É¬Œ÷‚µ‚Ü‚µ‚½B"
	#define STRERR_S_SCADMINTOOL_0039 "±²ÃÑ‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0040 "±²ÃÑŒÂ”‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0041 "ŠY“–±²ÃÑ‚Í5ŒÂˆÈ‰º‚Ì‚Ýì¬‚Å‚«‚Ü‚·B"
	#define STRERR_S_SCADMINTOOL_0042 "Ò¯¾-¼Þ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRERR_S_SCADMINTOOL_0043 "‚¨’m‚ç‚¹‚ð‘—M‚Å‚«‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server‚ªŽÀs‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0046 "Field Server‚ªŽÀs‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÄÆ®³Ê - ¾ûÑå¹Î ÅEÆÄÆ®³Ê ±â´É¿¡¼­ »ç¿EÇ´Â MSG
	#define STRERR_S_SCADMINTOOL_0048 "ÆÄÆ®³Ê¿¡ ÀåÂøµÈ ¼ÒÄÏ ¾ÆÀÌÅÛ ÀÔ´Ï´Ù.\n¼ÒÄÏÀÌ ÀåÂøµÈ ÆÄÆ®³Ê ¼Ó¼ºÃ¢¿¡¼­ »èÁ¦°¡ °¡´ÉÇÕ´Ï´Ù."
	#define STRERR_S_SCADMINTOOL_0049 "ÆÄÆ®³Ê¼Ó¼º º¯°æ»çÇ× LogÀúÀåÀÌ ½ÇÆÐ µÇ¾ú½À´Ï´Ù.\r\n(ÆÄÆ®³Ê ¼Ó¼º º¯°æÀº ¿Ï·áµÊ, Log¸¸ ÀúÀE½ÇÆÐ.)"
	#define STRERR_S_SCADMINTOOL_0050 "ÆÄÆ®³Ê Á¤º¸ ·ÎµùÀÌ ½ÇÆÐ µÇ¾ú½À´Ï´Ù"
	#define STRERR_S_SCADMINTOOL_0051 "ÀåÂøÁßÀÎ ¼ÒÄÏ ¾ÆÀÌÅÛ »èÁ¦°¡ ½ÇÆÐ µÇ¾ú½À´Ï´Ù."
	#define STRERR_S_SCADMINTOOL_0052 "ÀåÂøÇÒ ¼ÒÄÏ ¾ÆÀÌÅÛÀÇ ÇÏÀÌµE¿É¼Ç Àû¿E?½ÇÆÐ µÇ¾ú½À´Ï´Ù."
	#define STRERR_S_SCADMINTOOL_0053 "ÆÄÆ®³Ê ¼ÒÄÏ ¾ÆÀÌÅÛÀÇ ¼öÁ¤ÀÌ ½ÇÆÐ µÇ¾ú½À´Ï´Ù."
	#define STRERR_S_SCADMINTOOL_0054 "ÆÄÆ®³Ê Á¤º¸ ¾÷µ¥ÀÌÆ®°¡ ½ÇÆÐ µÇ¾ú½À´Ï´Ù"
	#define STRERR_S_SCADMINTOOL_0055 "ÆÄÆ®³Ê·¹º§ Á¤º¸ ·ÎµùÀÌ ½ÇÆÐµÇ¾ú½À´Ï´Ù"

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿ûÛµÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿ûÛµÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "ƒAƒJƒEƒ“ƒgID"
//	#define STRMSG_S_SCAT_COLNAME_0001 "À²Ìß"
//	#define STRMSG_S_SCAT_COLNAME_0002 "‘O‰È"
//	#define STRMSG_S_SCAT_COLNAME_0003 "ŠJŽn“ú"
//	#define STRMSG_S_SCAT_COLNAME_0004 "I—¹“ú"
//	#define STRMSG_S_SCAT_COLNAME_0005 "ˆ—ŽÒ"
//	#define STRMSG_S_SCAT_COLNAME_0006 "ˆ———R"
//	#define STRMSG_S_SCAT_COLNAME_0007 "“úŽž"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Û¸ÞÀ²Ìß"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "»-ÊÞ-–¼"
//	#define STRMSG_S_SCAT_COLNAME_0011 "·¬×¸À-È-Ñ"
//	#define STRMSG_S_SCAT_COLNAME_0012 "ˆÊ’u"
//	#define STRMSG_S_SCAT_COLNAME_0013 "“à—e"
//	#define STRMSG_S_SCAT_COLNAME_0014 "±²ÃÑ"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "ŒÅ—L”Ô†"
//	#define STRMSG_S_SCAT_COLNAME_0017 "–¼‘O"
//	#define STRMSG_S_SCAT_COLNAME_0018 "±²ÃÑ”Ô†"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "‘•”õ"
//	#define STRMSG_S_SCAT_COLNAME_0022 "ŒÂ”"
//	#define STRMSG_S_SCAT_COLNAME_0023 "‘Ï‹v“x"
//	#define STRMSG_S_SCAT_COLNAME_0024 "ì¬ŽžŠÔ"
	#define STRMSG_S_SCAT_COLNAME_0025 "–¢‘•”õ"
//	#define STRMSG_S_SCAT_COLNAME_0026 "‘qŒÉ"
//	#define STRMSG_S_SCAT_COLNAME_0027 "ƒI-ƒNƒVƒ‡ƒ“"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Ï¯Ìß"
//	#define STRMSG_S_SCAT_COLNAME_0029 "À•W"
//	#define STRMSG_S_SCAT_COLNAME_0030 "«•Ê"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Ží‘°"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Œ ŒÀ"
//	#define STRMSG_S_SCAT_COLNAME_0033 "ƒ†ƒjƒbƒgŽí—Þ"
//	#define STRMSG_S_SCAT_COLNAME_0034 "ƒŒƒxƒ‹"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Å‚ƒŒƒxƒ‹"
//	#define STRMSG_S_SCAT_COLNAME_0036 "ŒoŒ±’l"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Œ¸­‚µ‚½ŒoŒ±’l"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Ž©“®•ª”z½Ã-À½À²Ìß"
//	#define STRMSG_S_SCAT_COLNAME_0039 "UŒ‚ƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0040 "–hŒäƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0041 "”R—¿ƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0042 "¸_ƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0043 "ƒV-ƒ‹ƒhƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0044 "‰ñ”ðƒp-ƒg"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Š‘®—·’c"
//	#define STRMSG_S_SCAT_COLNAME_0046 "«Œü"
//	#define STRMSG_S_SCAT_COLNAME_0047 "g•ª"
//	#define STRMSG_S_SCAT_COLNAME_0048 "‘Ú‘±ŽžŠÔ"
//	#define STRMSG_S_SCAT_COLNAME_0049 "ì¬ŽžŠÔ"
//	#define STRMSG_S_SCAT_COLNAME_0050 "ÅIÚ‘±ŽžŠÔ"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Ží—Þ"
//	#define STRMSG_S_SCAT_COLNAME_0052 "‘S‘Ì"
	#define STRMSG_S_SCAT_COLNAME_0053 "µ-ÄÏÁ¯¸—Þ(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0054 "ƒoƒ‹ƒJƒ“—Þ(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0055 "ƒfƒ…ƒAƒ‹ƒŠƒXƒg—Þ(1-1?)" // 2005-08-01 by hblee : ????? -> ??ƒŠƒXƒg? •ÏX.
	#define STRMSG_S_SCAT_COLNAME_0056 "ƒLƒƒƒmƒ“—Þ(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0057 "ƒ‰ƒCƒtƒ‹—Þ(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0058 "ƒKƒgƒŠƒ“ƒO—Þ(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0059 "×ÝÁ¬-—Þ(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Ï½ÄÞ×²Ì—Þ(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0061 "ƒƒPƒbƒg—Þ(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Ð»²Ù—Þ(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0063 "ƒoƒ“ƒhƒ‹—Þ(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Ï²Ý—Þ(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0065 "¼-ÙÄÞ—Þ(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0066 "ÀÞÐ-—Þ(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Ëß¸»-—Þ(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0068 "ƒfƒRƒC—Þ(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0069 "–hŒä—Þ"
	#define STRMSG_S_SCAT_COLNAME_0070 "•â•‘•”õ—Þ"
	#define STRMSG_S_SCAT_COLNAME_0071 "´ÈÙ·Þ-—Þ"
	#define STRMSG_S_SCAT_COLNAME_0072 "‹à‘®—Þ"
	#define STRMSG_S_SCAT_COLNAME_0073 "¶-ÄÞ—Þ"
	#define STRMSG_S_SCAT_COLNAME_0074 "´ÝÁ¬ÝÄ—Þ"
	#define STRMSG_S_SCAT_COLNAME_0075 "ÀÝ¸—Þ"
	#define STRMSG_S_SCAT_COLNAME_0076 "’eŠÛ—Þ"
	#define STRMSG_S_SCAT_COLNAME_0077 "Ð¯¼®Ý—p"
	#define STRMSG_S_SCAT_COLNAME_0078 "Ú-ÀÞ-—Þ"
	#define STRMSG_S_SCAT_COLNAME_0079 "ºÝËß­-À-—Þ"
	#define STRMSG_S_SCAT_COLNAME_0080 "·Þ¬ÝÌÞÙ¶-ÄÞ—Þ"
	#define STRMSG_S_SCAT_COLNAME_0081 "´ÝÁ¬ÝÄ”j‰ó–hŽ~—Þ"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "ÌÞ×½À-—Þ"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Ú-Ù¶ÞÝ—Þ"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "‘S‘Ì±²ÃÑ"
//	#define STRMSG_S_SCAT_COLNAME_0082 "‘S‘Ì»-ÊÞ-"
//	#define STRMSG_S_SCAT_COLNAME_0083 "»-ÊÞ-–¼"
//	#define STRMSG_S_SCAT_COLNAME_0084 "»-ÊÞ-Ží—Þ"
//	#define STRMSG_S_SCAT_COLNAME_0085 "»-ÊÞ-IPAPort"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Œ»ÝÕ-»Þ-”"
//	#define STRMSG_S_SCAT_COLNAME_0087 "»-ÊÞ-ó‘Ô"
//	#define STRMSG_S_SCAT_COLNAME_0088 "¸ÞÙ-Ìß»-ÊÞ-"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Ì¨-ÙÄÞ»-ÊÞ-"
//	#define STRMSG_S_SCAT_COLNAME_0090 "•s–¾"
//	#define STRMSG_S_SCAT_COLNAME_0091 "ŽÀsŽ¸”s"
//	#define STRMSG_S_SCAT_COLNAME_0092 "³í"
//	#define STRMSG_S_SCAT_COLNAME_0093 "”ñ³í"
	#define STRMSG_S_SCAT_COLNAME_0094 "‰^‰cŽÒ"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10))+'ŒÂ, Param1:'+CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////	
	
	
///////////////////////////////////////////////////////////////////////////////	
// 4	
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "–½—ßŒêƒŠƒXƒg\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "-----ƒoƒbƒNƒAƒbƒv‚µ‚½ƒAƒJƒEƒ“ƒgƒŠƒXƒg ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "ƒAƒJƒEƒ“ƒg:\'%s\'AÝ’èPW:\'%s\'A—ÕŽžPW:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "ƒAƒJƒEƒ“ƒg:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0004 "±¯ÌßÃÞ-Ä—pVersion‚ª“ü‚Á‚Ä‚¢‚éÌ«ÙÀÞ‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "Ì§²Ù‚Ìì¬‚É¬Œ÷‚µ‚Ü‚µ‚½B\r\n\r\nDB î•ñ:%s(%d)A%s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d-Šˆ«)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d-”ñŠˆ«)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "ƒT-ƒoƒf-ƒ^‚ÌƒŠƒ-ƒh‚É¬Œ÷‚µ‚Ü‚µ‚½B"
//	#define STRMSG_S_SCMONITOR_0011 "ƒT-ƒrƒXó‘Ô‚Ì”½‰f‚É¬Œ÷‚µ‚Ü‚µ‚½B"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d-Šˆ«)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d-”ñŠˆ«)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "ƒtƒŠ-ƒT-ƒoƒT-ƒrƒX‚ª’†?‚µ‚Ü‚µ‚½B"
//	#define STRMSG_S_SCMONITOR_0017 "ƒtƒŠ-ƒT-ƒoƒT-ƒrƒX‚ªŠJŽn‚µ‚Ü‚µ‚½B"
//	#define STRMSG_S_SCMONITOR_0018 "Ì¨-ÙÄÞ»-ÊÞ-‚ªŽÀs‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB"
//	#define STRMSG_S_SCMONITOR_0019 "–{“–‚ÉField Server‚ðI—¹‚µ‚Ü‚·‚©H"
//	#define STRMSG_S_SCMONITOR_0020 "±¯ÌßÃÞ-ÄÊÞ-¼Þ®ÝØ½Äî•ñ(Å‘å1492 Bytes)\r\n\r\nÊÞ-¼Þ®ÝØ½ÄŒÂ”[%3d]AÃÞ-À»²½Þ [%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "–{“–‚ÉPre Server‚ðI—¹‚µ‚Ü‚·‚©H"
//	#define STRMSG_S_SCMONITOR_0022 "–{“–‚ÉIM Server‚ðI—¹‚µ‚Ü‚·‚©H"
//	#define STRMSG_S_SCMONITOR_0023 "–{“–‚ÉNPC Server‚ðI—¹‚µ‚Ü‚·‚©H"
//	#define STRMSG_S_SCMONITOR_0024 "%Y”N%mŒŽ%d“ú%HŽž%M•ª%S•b"
//	#define STRMSG_S_SCMONITOR_0025 "ƒCƒxƒ“ƒg‚È‚µ(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "ƒI-ƒvƒ“ƒx-ƒ^oÈƒCƒxƒ“ƒg(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "ƒCƒxƒ“ƒg•s–¾(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "ŽŸ‚Ìè—ÌíÝ’èŽžŠÔ"
//	#define STRMSG_S_SCMONITOR_0029 "ŽŸ‚Ìè—ÌíŠî?ŽžŠÔ"
//	#define STRMSG_S_SCMONITOR_0030 "è—Ì—·’c"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "==>–½—ßŒê‚ª¬Œ÷‚µ‚Ü‚µ‚½B\r\n"
//	#define STRERR_S_SCMONITOR_0001 "==>–½—ßŒê‚ªŽ¸”s‚µ‚Ü‚µ‚½B\r\n"
//	#define STRERR_S_SCMONITOR_0002 "DB‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñB"
//	#define STRERR_S_SCMONITOR_0003 "ŠY“–Version‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
//	#define STRERR_S_SCMONITOR_0004 "ˆ³k‚·‚éÌ«ÙÀÞ–¼‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢"
//	#define STRERR_S_SCMONITOR_0005 "o—Í‚·‚éÌ«ÙÀÞ–¼‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢"
//	#define STRERR_S_SCMONITOR_0006 "ŠJŽnÊÞ-¼Þ®Ý‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
//	#define STRERR_S_SCMONITOR_0007 "ÅŒã‚ÌÊÞ-¼Þ®Ý‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B"
//	#define STRERR_S_SCMONITOR_0008 "±¯ÌßÃÞ-Ä—pZipÌ§²Ù‚ðo—Í‚·‚éÌ«ÙÀÞ‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢"
//	#define STRERR_S_SCMONITOR_0009 "Ì§²Ù‚ð˜AŒ‹‚Å‚«‚Ü‚¹‚ñ"
//	#define STRERR_S_SCMONITOR_0010 "»-ÊÞ-‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢I"
//	#define STRERR_S_SCMONITOR_0011 "DB‚É˜AŒ‹‚Å‚«‚Ü‚¹‚ñ"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type:%s(%#04x)in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "±¯ÌßÃÞ-ÄÊÞ-¼Þ®ÝØ½Ä‚ª’·‚·‚¬‚Ü‚·B(ÊÞ-¼Þ®ÝØ½ÄŒÂ”[%3d]AÃÞ-À»²½Þ[%4dBytes])\r\n\r\nÊÞ-¼Þ®ÝØ½Ä‚ð®—‚µ‚È‚­‚Ä‚Í‚È‚è‚Ü‚¹‚ñB"
//	#define STRERR_S_SCMONITOR_0014 "œ‹Ž‚³‚ê‚½??‚Å‚·B\r\nŠÇ—Â-Ù‚ð—˜—p‚µ‚Ä‚­‚¾‚³‚¢B"
//	#define STRERR_S_SCMONITOR_0015 "“sŽsè—ÌíÏ¯Ìß‚Å‚Í‚ ‚è‚Ü‚¹‚ñ"
//	#define STRERR_S_SCMONITOR_0016 "EDITºÝÄÛ-Ù‚ðì¬‚Å‚«‚Ü‚¹‚ñB"
//	#define STRERR_S_SCMONITOR_0017 "Šù‚É‘¶Ý‚·‚éÌ§²Ù‚ð“o˜^‚µ‚Ü‚µ‚½B"

// 4_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Log Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\r\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error]WndProc(),Can't connect to PreServer[%15s:%4d]Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Pre Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\r\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY:%s(%#04x)\r\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Pre Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(),Can't connect to  IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "IM Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\r\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY:%s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries!%d\r\n"
	#define STRMSG_S_F2DBQUERY_0001 "ŠY“–±²ÃÑ‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2DBQUERY_0002 "'%s'—l‚ÍoÈ\‚µž‚Ý‚ð‚µ‚½‚½‚ßA–ñ‘©‚µ‚½±²ÃÑ‚ð"
	#define STRMSG_S_F2DBQUERY_0003 "Žx‹‹‚µ‚Ü‚·BƒCƒ“ƒxƒ“ƒgƒŠ‚ðŠm”F‚µ‚Ä‚­‚¾‚³‚¢"
	#define STRMSG_S_F2DBQUERY_0004 "ƒXƒLƒ‹%s(%d)‚ª’Ç‰Á‚³‚ê‚Ü‚µ‚½B"
	#define STRMSG_S_F2DBQUERY_0005 "ŠY“–±²ÃÑ‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2DBQUERY_0006 "±²ÃÑw“ü‚ÉŽ¸”s‚µ‚Ü‚µ‚½B"

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  “sŽsè—ÌíŠJŽn:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  ŽQ‰Á—·’c:GuildUID(%4d) GuildName(%10s)GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  “sŽsè—ÌíÓÝ½À-”š”­:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		 ÀÞÒ-¼ÞÄ-ÀÙ==>GuildName(%10s)SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  “sŽsè—Ìí:%d(%10s)CityMapIndex(%d)QuestIndex(%d)OccGuildID(%d)OccGuildName(%s) OccGuildMasterUID(%d)è—ÌíŽžŠÔ(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d•ªŒã\"%s\"“sŽsè—Ìí‚ªŠJŽn‚µ‚Ü‚·B"
	#define STRMSG_S_F2CITYWAR_0007 "%d•ªŒã\"%s\"“sŽsè—Ìí‚ªI—¹‚µ‚Ü‚·B"
	#define STRMSG_S_F2CITYWAR_0008 "“sŽsè—Ìí(%s)ÓÝ½À-¢Š«:NPCè—Ì"
	#define STRMSG_S_F2CITYWAR_0009 "“sŽsè—Ìí(%s)ÓÝ½À-¢Š«:%s—·’cè—Ì"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"‚ª\"%s\"‚ðè—Ì‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"—·’c‚ª\"%s\"‚ðè—Ì‚µ‚Ü‚µ‚½B"

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Ð¯¼®Ýƒ-ƒfƒBƒ“ƒOŽ¸”s"
	#define STRMSG_S_F2QUEST_0001 "Ð¯¼®Ý‚Ìƒ-ƒfƒBƒ“ƒO‚ÉŽ¸”s‚µ‚Ü‚µ‚½B\r\n"
//	#define STRMSG_S_F2QUEST_0002 "Ð¯¼®Ý\'%30s\'”Ô†%d->OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "ƒeƒXƒg—pƒT-ƒoƒZƒbƒeƒBƒ“ƒOŠ®—¹I \r\n\r\nLoadFieldServerDataDebug()œ‹Ž‚ð‚¨Šè‚¢I"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d:%d‚É%5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d:%s‚É%5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "Šî?"
	#define STRMSG_S_F2NOTIFY_0003 "“ÁŽê"
	#define STRMSG_S_F2NOTIFY_0004 "ÓÝ½À-1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "ÓÝ½À-2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "•Ší‚ÌŽí—Þ‚ªŠÔˆá‚¢‚Ü‚µ‚½BŠÇ—ŽÒ‚É–â‚¢‡‚í‚¹‚ð‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0007 "1-1?:%4.1f vs %4.1f->–½’†—¦ %2.2f%% Œ¸­"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%sŽ¸”sAŠm—¦(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%sŽ¸”sAŠm—¦(%d>%5.2f)-%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%sŽ¸”sAŠm—¦(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2?:%4.1f vs %4.1f->?ƒ?ƒW%2.2f%%Œ¸­(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s‚É%5.2f(%5.2f-%d/255)“n‚·(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s‚©‚ç%5.2f(%5.2f-%d/255) ‚à‚ç‚¤B(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d,HP:%5.2f)‚É%5.2f(%5.2f-%d/255)“n‚·(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s‚©‚ç%5.2f(%5.2f-%d/255)‚à‚ç‚¤(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "???Ž¸”s:Šm—¦•s‘«>%d"
	#define STRMSG_S_F2NOTIFY_0017 "Žc‚è???[%#08x]:%5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "e’eî•ñ‚ª‚ ‚è‚Ü‚¹‚ñBŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0019 "e’e‚ÌŒûŒaî•ñ‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB%s%d"
	#define STRMSG_S_F2NOTIFY_0020 "e’e‚Ìî•ñ‚Å‚·B%s%d"
	#define STRMSG_S_F2NOTIFY_0021 "Šù‚ÉƒCƒxƒ“ƒg‚ªˆ—’†‚Ì‚½‚ßAƒ-ƒv‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0022 "Ž€–S‚µ‚Ä‚¢‚é‚½‚ßƒ-ƒv‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0023 "•Ò‘àí’†‚Ì‚½‚ßƒ-ƒv‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0024 "Ï¯Ìß§ìƒGƒ‰-IŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢I"
	#define STRMSG_S_F2NOTIFY_0025 "Ï¯Ìß§ìƒGƒ‰-IŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢I%d‚É%d‚ÌƒEƒB?ƒt??ƒQƒbƒgƒCƒ“ƒfƒbƒNƒX‚ª‚È‚¢I\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "•Ò‘àí’†‚Ì‚½‚ßƒ-ƒv‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d)ˆ—•s‰Âat Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1->·¬×¸À-%10s‚©‚çÀÞÒ-¼Þ%5.2f‚ðŽó‚¯‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0029 "1->·¬×¸À-%10s‚ÉÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0030 "1->·¬×¸À-%10s‚ÉÀÞÒ-¼Þ %5.2f‚ð ?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0031 "1->·¬×¸À-%10s‚É???ÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0032 "2->·¬×¸À-%10s‚©‚çÀÞÒ-¼Þ%5.2f‚ðŽó‚¯‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0033 "2->·¬×¸À-%10s‚ÉÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0034 "2->ÓÝ½À-%3d‚ÉÀÞÒ-¼Þ%5.2f(%d)‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0035 "2->·¬×¸À-%10s‚ÉÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0036 "2->·¬×¸À-%10s‚É???ÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0037 "2->ÓÝ½À-%3d‚©‚çÀÞÒ-¼Þ%5.2f‚ðŽó‚¯‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0038 "MINE->·¬×¸À-%10s‚ÉÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0039 "MINE->·¬×¸À-%10s‚É???ÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0040 "MINE->ÓÝ½À-%10s‚ÉÀÞÒ-¼Þ%5.2f‚ð?‚¦‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0041 "½Ã-À½‰Šú‰»‚É¬Œ÷‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_F2NOTIFY_0042 "Ž€–S‚µ‚½‚Æ‚«‚É‚ÍŽg—p‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO‚È‚µ"
	#define STRMSG_S_F2NOTIFY_0044 "´ÝÁ¬ÝÄ‚É¬Œ÷‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0045 "´ÝÁ¬ÝÄ‚ÉŽ¸”s‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0046 "—·’c‚ÉŠ‘®‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0047 "Šù‚É\‚µž‚Ý‘Ò‹@’†‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0048 "‚µ‚Î‚ç‚­Œã‚ÅÄŽÀs‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0049 "Ž©•ª‚©‘ŠŽè‚ª—·’c’·‚Å‚Í‚ ‚è‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0050 "Šù‚É—·’cí’†‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0051 "—¼•û‚Ì—·’c’·‚ª“¯‚¶Ï¯Ìß‚É‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0052 "‘S•Ò‘àƒƒ“ƒo-‚ª“¯‚¶Ï¯Ìß‚É“ü‚Á‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0053 "‘S•Ò‘àƒƒ“ƒo-‚ª“¯‚¶Ï¯Ìß‚É“ü‚Á‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0054 "—·’c‚ÉŠ‘®‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0055 "\‚µž‚ÝŽÒ‚Æ”í?‚µž‚ÝŽÒ‚ªˆá‚¢‚Ü‚·B"
	#define STRMSG_S_F2NOTIFY_0056 "Ž©•ª‚©‘ŠŽè‚ª—·’c’·‚Å‚Í‚ ‚è‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0057 "—¼•û‚Ì—·’c’·‚ª“¯‚¶Ï¯Ìß‚É‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0058 "—·’c‚ÉŠ‘®‚µ‚Ä‚¢‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0059 "\‚µž‚ÝŽÒ‚Æ”í\‚µž‚ÝŽÒ‚ªˆá‚¢‚Ü‚·B"
	#define STRMSG_S_F2NOTIFY_0060 "Ž©•ª‚©‘ŠŽè‚ª—·’c’·‚Å‚Í‚ ‚è‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0061 "“sŽsè—Ìí–hŒä‚É¬Œ÷‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_F2NOTIFY_0062 "Ð¯¼®ÝÝ’èƒGƒ‰-‚Å‚·BŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0063 "‚±‚ÌˆÊ’u‚Å‚ÍŠY“–±²ÃÑ(%s)‚ð‘•”õ‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0064 "ƒGƒ“ƒWƒ“‚ÌƒXƒƒbƒg‚Í‹ó‚¯‚é‚±‚Æ‚ª‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0065 "±²ÃÑˆÚ“®:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0066 "ŠÔˆá‚Á‚Ä‚¢‚é±²ÃÑˆÚ“®:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d)ˆ—•s‰Âat Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Ï¯Ìß²ÍÞÝÄî•ñˆÙíIŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢II"
	#define STRMSG_S_F2NOTIFY_0069 "ŠY“–ƒ-ƒv??ƒQƒbƒg‚ª‚È‚¢"
	#define STRMSG_S_F2NOTIFY_0070 "±²ÃÑw“üƒGƒ‰-‚Å‚·BŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0071 "w“ü‚·‚éƒXƒLƒ‹ƒŒƒxƒ‹‚ªŠù‘¶ƒXƒLƒ‹‚ÌƒŒƒxƒ‹‚æ‚è’á‚¢‚©“¯‚¶‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0072 "ƒXƒLƒ‹w“ü‚Ì‚½‚ß‚É‚Í±²ÃÑ‚ª•K—v‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0073 "±²ÃÑ”Ì”„´×-‚Å‚·BŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0074 "±²ÃÑw“ü´×-‚Å‚·BŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0075 "\'Øµº²Ý±²ÃÑ\'‚ðw“ü‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_F2NOTIFY_0076 "w“üƒŠƒXƒg:\'%s(%dŒÂ)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Šù‚É•Ò‘à‚É‰Á“ü‚µ‚Ä‚¢‚Ü‚·B"
	#define STRMSG_S_F2NOTIFY_0078 "‚ ‚È‚½‚Í•Ò‘à’·‚È‚Ì‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0079 "•Ò‘àí‚ªis’†‚Ì‚½‚ß‰Á“ü‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_F2NOTIFY_0080 "‘S•Ò‘àƒƒ“ƒo-‚Ìî•ñ‚ðŽó‚¯Žæ‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñI"
	#define STRMSG_S_F2NOTIFY_0081 "Ï¯Ìß²ÍÞÝÄî•ñˆÙíIŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢II"
	#define STRMSG_S_F2NOTIFY_0082 "Žæ‚èˆø‚«‚Å‚«‚È‚¢ƒAƒJƒEƒ“ƒg‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0083 "%s—l‚ÍÏÚ—Ê’´‰ß‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0084 "ˆÚ“®‰Â?À•W:(5, 5)->(%d,%d)"
	#define STRMSG_S_F2NOTIFY_0085 "ÌßÚ²Ô-:"
	#define STRMSG_S_F2NOTIFY_0086 "Å‘å20l‚Ü‚ÅŒ©‚é‚±‚Æ‚ª‚Å‚«‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0087 "ŠY“–ÌßÚ²Ô-(%s)‚ª‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0088 "•Ò‘à‚ÉŠ‘®‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0089 "Œ»ÝŽžŠÔ:%d:%dAƒAƒg?ŽžŠÔ:%d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "•ÏXŽžŠÔ:%d:%dAƒAƒg?ŽžŠÔ:%d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "NPC»-ÊÞ-‚ÉÚ‘±‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0092 "ŠY“–±²ÃÑ(%d)‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0093 "Countable Item‚¶‚á‚È‚¢ê‡‚Í10ŒÂ‚É§ŒÀ‚³‚ê‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0094 "Ï¯Ìß\'%s\'‚Ì‘S‘ÌÚ‘±ŽÒ:%dl"
	#define STRMSG_S_F2NOTIFY_0095 "Ï¯Ìß%s%s“¯ŽžÚ‘±ŽÒ:%dl-'%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Ï¯Ìß%s%s“¯ŽžÚ‘±ŽÒ:%dl-'%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Œ»ÝÏ¯ÌßÁ¬ÝÈÙ:%sA%d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "e’eî•ñ‚ª‚ ‚è‚Ü‚¹‚ñBŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0099 "e’e‚ÌŒûŒaî•ñ‚ª‘¶Ý‚µ‚Ü‚¹‚ñB%s%d"
	#define STRMSG_S_F2NOTIFY_0100 "e’eî•ñ‚ª‚ ‚è‚Ü‚¹‚ñBŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0101 "e’e‚ÌŒûŒaî•ñ‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñB%s%d"
	#define STRMSG_S_F2NOTIFY_0102 "ŠY“–ÌßÚ²Ô-(%s)‚ª‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0103 "ŠY“–ÌßÚ²Ô-(%s)‚Í?‚ñ‚Å‚¢‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0104 "ŠY“–ÌßÚ²Ô-(%s)‚ª‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0105 "ˆê”ÊƒAƒJƒEƒ“ƒg‚ÉÝ’è‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0106 "ˆê”ÊƒAƒJƒEƒ“ƒg‚ª‰ðœ‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0107 "–³“G(ÀÞÒ-¼Þ‚ðŽó‚¯‚È‚¢)ƒ†ƒjƒbƒg‚ÉÝ’è‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0108 "–³“G(ÀÞÒ-¼Þ‚ðŽó‚¯‚È‚¢)ƒ†ƒjƒbƒgÝ’è‚ª‰ðœ‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0109 "•Ší‚ª%5.0f%%‚Ì‚ ‚è“¾‚È‚¢«”\‚ðŽ‚¿‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0110 "±²ÃÑÄ‘•“UŽž‰Šú‰»‚³‚ê‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0111 "±²ÃÑÄ‘•“UŽž‰Šú‰»‚³‚ê‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0112 "ŠY“–ÌßÚ²Ô-(%s)‚ª‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0113 "“§–¾ó‘Ô‚ª‰ðœ‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0114 "“§–¾ó‘Ô‚ªŠˆ«‰»‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0115 "%sƒCƒxƒ“ƒg‚ªis’†‚Å‚Í‚ ‚è‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0116 "%sƒCƒxƒ“ƒg‚ªŠJŽn(?—¦:%4.2fAƒCƒxƒ“ƒgŽžŠÔ:%3d•ª)"
	#define STRMSG_S_F2NOTIFY_0117 "ˆê”ÊÌßÚÐ±Ñ±¶³ÝÄ‚ÉÝ’è‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0118 "ÌßÚÐ±Ñ±¶³ÝÄÝ’è‚ÉŽ¸”s‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0119 "½-Êß-ÌßÚÐ±Ñ±¶³ÝÄ‚ÉÝ’è‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0120 "“sŽsè—ÌíÏ¯Ìß‚Å‚Í‚ ‚è‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0121 "“sŽsè—Ìí‚ðŠJŽn‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0122 "“sŽsè—Ìí‚ðI—¹‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_F2NOTIFY_0123 "“§–¾ó‘Ô‚ª‰Šú‰»‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0124 "“§–¾ó‘Ô‚É‚È‚è‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0125 "Ï¯Ìß‚ª–³Œø‚Å‚·B"
	#define STRMSG_S_F2NOTIFY_0126 "HappyHour‚ÉÝ’è[isŽžŠÔ:%4d•ª)]"
	#define STRMSG_S_F2NOTIFY_0127 "HappyHourI—¹"
	#define STRMSG_S_F2NOTIFY_0128 "Šî?->ÓÝ½À-%3d‚©‚çÀÞÒ-¼Þ%5.2f‚ðŽó‚¯‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0129 "Šî?->ÓÝ½À-%3d‚©‚çÀÞÒ-¼Þ%5.2f‚ðŽó‚¯‚Ü‚µ‚½(???)"
	#define STRMSG_S_F2NOTIFY_0130 "%sŒ ŒÀ‚Æ‚µ‚ÄÚ‘±‚µ‚Ü‚µ‚½"
	#define STRMSG_S_F2NOTIFY_0131 "I—¹ƒ‹-ƒeƒBƒ“‚ðˆ—‚µ‚È‚¢?%s:CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine():•Ò‘àƒƒ“ƒo-œ‹ŽŽ¸”sI%s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix\'%s\'¬Œ÷:%d<=%d<=%d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix\'%s\'¬Œ÷:%d<=%d<=%d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s:’†?I"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR:ŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢IƒVƒ‡ƒbƒv•Ï”Š„‚è“–‚ÄƒGƒ‰-?I"
	#define STRMSG_S_F2NOTIFY_0137 "%s‚ªíœ‚³‚ê‚Ü‚µ‚½B"
	#define STRMSG_S_F2NOTIFY_0138 "Œ»Ý‚Ì?ƒƒƒ“ƒlƒ‹‚Í”ñŠˆ«‰»‚Ì‚½‚ßƒ‚ÓÝ½À-‚¨‚æ‚Ñ‚»‚Ì‘¼??‚ª"
	#define STRMSG_S_F2NOTIFY_0139 "’â?‚µ‚Ü‚·B‚Ù‚©‚ÌÁ¬ÝÈÙ‚ð—˜—p‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2dŒÂ]:%04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "?ƒC??“®ì%s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HPŽ©“®‰ñ•œ‚ð’†?‚µ‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0143 "’…—¤‰Â”\’nˆæ‚Å‚Í‚È‚¢‚½‚ßAHPŽ©“®‰ñ•œ‚ð’†?‚µ‚Ü‚·"
	#define STRMSG_S_F2NOTIFY_0144 "‰ž?‚É‚æ‚éHP5.2f‰ñ•œ"
	#define STRMSG_S_F2NOTIFY_0145 "Gradual HP UP ’†?(Žc‚èŽžŠÔ:%d)"
	#define STRMSG_S_F2NOTIFY_0146 "Gradual DP UP ’†?(Žc‚èŽžŠÔ:%d)"
	#define STRMSG_S_F2NOTIFY_0147 "Gradual EP UP ’†?(Žc‚èŽžŠÔ:%d)"
	#define STRMSG_S_F2NOTIFY_0148 "%sƒCƒxƒ“ƒg‚ªI—¹‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_F2NOTIFY_0149 "%sƒCƒxƒ“ƒgis’†(?—¦:%4.2f,Žc‚èŽžŠÔ:%3d•ª)"
	#define STRMSG_S_F2NOTIFY_0150 "–½—ßŒã‚ªŽÀs‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	ŒoŒ±’l•ª”zƒGƒ‰-(%s,%s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "–³ŒøGame StartÒ¯¾-¼Þ´×-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "–³ŒøGame Start Ò¯¾-¼Þ´×-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d)ˆ—•s‰Âat ProcessQuestResult(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Ï¯Ìß²ÍÞÝÄî•ñˆÙíIŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢IICurrent(%s,%s,%04d),Target(%04d,%d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d)ˆ—•s‰Âat T_FC_PARTY_REQUEST_PARTY_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Ï¯Ìß²ÍÞÝÄî•ñˆÙíIŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢IICurrent(%s,%s,%04d),Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARPˆ—•s‰Âat T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d)ˆ—•s‰Â(•Ò‘à’·)at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) ˆ—•s‰Âat Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) ˆ—•s‰Âat Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP ˆ—•s‰Âat T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "•Ò‘àƒ-ƒvŽ¸”s:%s->‹——£:%5.2f, bodycon: %d,%d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) ˆ—•s‰Âat Process_FC_CHARACTER_DEAD_GAMESTART(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s->OK??ƒ“ƒNƒŠƒbƒNd•¡I\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Ð¯¼®Ý‚ªƒ-ƒfƒBƒ“ƒO‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s)ˆ—•s‰Â at HandleAdminCommands(),/ˆÚ“®,%s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s)ˆ—•s‰Â at HandleAdminCommands(),/‘—M,%s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATAL ERROR:ŠY“–ƒƒ“ƒo-‚ª“ü‚Á‚Ä‚¢‚È‚¢Ì¨-ÙÄÞ»-ÊÞ-‚É‚ÍA‚±‚ÌƒƒbƒZ-ƒW‚ª‘—M‚³‚ê‚Ä‚Í‚¢‚¯‚Ü‚¹‚ñBcheck it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d)ˆ—•s‰Âat T_FI_ADMIN_CALL_CHARACTER,%s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s)ˆ—•s‰Âat T_FI_ADMIN_MOVETO_CHARACTER,%s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "ŒoŒ±’l"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "ŒoŒ±’l•œ‹Œ"
	#define STRMSG_S_F2EVENTTYPE_0003 "±²ÃÑÄÞÛ¯Ìß"
	#define STRMSG_S_F2EVENTTYPE_0004 "Ú±±²ÃÑÄÞÛ¯Ìß"
	#define STRMSG_S_F2EVENTTYPE_0005 "ƒCƒxƒ“ƒg•s–¾"
// 5_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Pre Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Pre Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'‚ÍŠù‚É‘¶Ý‚µ‚Ä‚¢‚é—·’c–¼‚Å‚·B"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'‚ÍŠù‚É—·’c‚É‰Á“ü‚µ‚Ä‚¢‚Ü‚·B"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'‚ÍŠù‚É‘¶Ý‚·‚é—·’c–¼‚Å‚·B"
	#define STRMSG_S_I2NOTIFY_0003 "—·’cƒ-ƒfƒBƒ“ƒOŽ¸”s-ŠÇ—ŽÒ‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢I"
	#define STRMSG_S_I2NOTIFY_0004 "—F’B'%s'—l‚ªƒƒOƒCƒ“‚µ‚Ü‚µ‚½B"
	#define STRMSG_S_I2NOTIFY_0005 "ˆÈ‘O‚Ì•Ò‘à‚ðŠm”F‚µ‚Ü‚·"
	#define STRMSG_S_I2NOTIFY_0006 "Šù‘¶‚Ì•Ò‘à‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0007 "•Ò‘à‚ÉÄ‰Á“ü‚µ‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0008 "Šù‚É‰Á“ü‚µ‚Ä‚¢‚é•Ò‘à‚ª‚ ‚è‚Ü‚·B"
	#define STRMSG_S_I2NOTIFY_0009 "Fatal Error:?‚È•Ò‘àƒGƒ‰-Iat T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "•Ò‘àƒƒ“ƒo-‚Ìó‘Ô‚ª•s³‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0011 "•Ò‘àƒƒ“ƒo-‚ªŠù‚É—·’c‚É‰Á“ü‚µ‚Ä‚¢‚Ü‚·"
	#define STRMSG_S_I2NOTIFY_0012 "‘ÎÛ‚ªŠù‚É—·’c‚É‰Á“ü‚µ‚Ä‚¢‚Ü‚·"
	#define STRMSG_S_I2NOTIFY_0013 "Ž©•ª‚ðµ‘Ò‚·‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0014 "—·’c‰Á“ü‚ª‹–‰Â‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0015 "‰Á“ü‰Â”\‚È—·’cƒƒ“ƒo-”‚ð’´‰ß‚µ‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0016 "—·’c‰Á“ü‚ª‹–‰Â‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0017 "—·’c’·‚Í’E‘Þ‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0018 "—·’cí’†‚Ì‚½‚ßA—·’c‚©‚ç’E‘Þ‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0019 "—·’cí’†‚Ì‚½‚ßA—·’cƒƒ“ƒo-‚ð’Ç•ú‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0020 "—·’c’·‚Í’Ç•ú‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0021 "—·’cí’†‚Ì‚½‚ßA—·’c‚ð‰ðŽU‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0022 "“¯‚¶–¼‘O‚É•ÏX‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0023 "—·’c–¼‚ð•ÏX‚Å‚«‚È‚¢ó‘Ô‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0024 "—·’cÏ-¸‚ð•ÏX‚Å‚«‚È‚¢ó‘Ô‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0025 "ŠK‹‰‚ð•ÏX‚Å‚«‚È‚¢ó‘Ô‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0026 "ŠK‹‰‚ªd•¡‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0027 "—·’c’·‚Ö‚ÌŠK‹‰•ÏX‚Í‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_I2NOTIFY_0028 "—·’c’·‚ÌŠK‹‰•ÏX‚Í‚Å‚«‚Ü‚¹‚ñB"
	#define STRMSG_S_I2NOTIFY_0029 "‘S‘ÌÌßÚ²Ô-”:%dl(%l‚Ü‚Åo—Í)"
	#define STRMSG_S_I2NOTIFY_0030 "‰^‰cŽÒƒƒbƒZ-ƒWƒŠƒXƒg‚É’Ç‰Á‚µ‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0031 "‰^‰cŽÒƒƒbƒZ-ƒWƒŠƒXƒg‚©‚çíœ‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0032 "»-ÊÞ-IP:%s"
	#define STRMSG_S_I2NOTIFY_0033 "»-ÊÞ-¸ÞÙ-Ìß \'%s\'‚Ì‘S‘ÌÚ‘±ŽÒ:%dl"
	#define STRMSG_S_I2NOTIFY_0034 "–{“–‚É»-ÊÞ-(%s)‚ðI—¹‚µ‚Ü‚·‚©H”Žš:%d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'‚Í¹Þ-Ñ‚ð‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0036 "‘S‘ÌÌßÚ²Ô-”:%dl(%dl‚Ü‚Åo—Í)"
	#define STRMSG_S_I2NOTIFY_0037 "/‘—M%s%s"
	#define STRMSG_S_I2NOTIFY_0038 "ŠY“–—·’c‚ª‚ ‚è‚Ü‚¹‚ñB"
	#define STRMSG_S_I2NOTIFY_0039 "‚³‚³‚â‚«ƒuƒƒbƒN‚ª‰ðœ‚³‚ê‚Ü‚µ‚½I"
	#define STRMSG_S_I2NOTIFY_0040 "‚³‚³‚â‚«‚ðƒuƒƒbƒN‚µ‚Ü‚µ‚½I"
	#define STRMSG_S_I2NOTIFY_0041 "—·’c‚É‰Á“ü‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0042 "—·’c(%d)‚ª–³Œø‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0043 "ŠY“–“V‹C(%s)‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0044 "Field Server‚ª–³Œø‚Å‚·"
	#define STRMSG_S_I2NOTIFY_0045 "ŠY“–Ï¯Ìß(%s)‚ª‘¶Ý‚µ‚Ä‚¢‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0046 "‚ ‚È‚½‚Í%d•ªŠÔÁ¬¯Ä‹ÖŽ~‚Å‚·I"
	#define STRMSG_S_I2NOTIFY_0047 "Á¬¯ÄÌÞÛ¯¸Ý’è:'%10s',%3d•ª"
	#define STRMSG_S_I2NOTIFY_0048 "Á¬¯ÄÌÞÛ¯¸‚ª‰ðœ‚³‚ê‚Ü‚µ‚½"
	#define STRMSG_S_I2NOTIFY_0049 "Á¬¯ÄÌÞÛ¯¸‰ðœ:'%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(ƒAƒJƒEƒ“ƒg:%s,?ƒbƒv:%d(%d),ƒŒƒxƒ‹: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "Ž©•ª‚ðŒÄ‚Ô‚±‚Æ‚ª‚Å‚«‚Ü‚¹‚ñ"
	#define STRMSG_S_I2NOTIFY_0052 "ŠY“–—·’c‚ª‚ ‚è‚Ü‚¹‚ñB"

	#define STRMSG_S_IMSERVER_050607_0001	"ŠY“–Ï¯Ìß‚ª‚ ‚è‚Ü‚¹‚ñB"
// 6_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Field Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Field Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							ÓÝ½À-‚ÆƒIƒuƒWƒFƒNƒg‚ÌÕ“Ë‚ÌÁª¯¸‚ª‚È‚¢\r\n"		
	#define STRMSG_S_N2NOTIFY_0001 "“sŽsè—ÌíÓÝ½À-(%10s)¢Š«\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Î“ck‘¾˜Y"
// 7_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 8 - PreServer	
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%sƒAƒJƒEƒ“ƒg(%s)‚ÉÚ‘±‚µ‚Ü‚µ‚½B IP:%s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "¬Œ÷"
	#define STRMSG_S_P2PRENOTIFY_0002 "Ž¸”s"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]ƒAƒJƒEƒ“ƒgî•ñ’Ç‰ÁƒGƒ‰-A AccountName(%s)privateIP(%15s)\n"
	
	
	#define STRMSG_SCAT_051115_0001		"‚¨‚Í‚æ‚¤‚²‚´‚¢‚Ü‚·B´-½µÝ×²Ý‰^‰cÁ-Ñ‚Å‚·B"
	#define STRMSG_SCAT_051115_0002		"?“úA10Žž‚©‚ç14Žž‚Ü‚Å’èŠúƒƒ“ƒeƒiƒ“ƒX‚ðŽÀ?‚µ‚Ü‚·B"
	#define STRMSG_SCAT_051115_0003		"ˆÀ‘S‚ÈêŠ‚ÉˆÚ“®‚µ‚ÄAÚ‘±‚ðI—¹‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_SCAT_051115_0004		"‚Ü‚¸NPC»-ÊÞ-‚©‚çI—¹‚µ‚Ü‚·B"
	#define STRMSG_SCAT_051115_0005		"‚±‚ê‚©‚ç´-½µÝ×²Ý’èŠúƒƒ“ƒeƒiƒ“ƒX‚ðŠJŽn‚µ‚Ü‚·B"
	#define STRMSG_SCAT_051115_0006		"´-½µÝ×²Ý‚ÆŠy‚µ‚¢ˆê“ú‚ð‰ß‚²‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_SCAT_051115_0007		"‚Ü‚à‚È‚­‹Ù‹}ƒƒ“ƒeƒiƒ“ƒX‚Ì‚½‚ß»-ÊÞ-‚ðI—¹‚µ‚Ü‚·B"
	#define STRMSG_SCAT_051115_0008		"ƒƒ“ƒeƒiƒ“ƒX‚ÌŽžŠÔ‚Í2ŽžŠÔ‚Å‚·B"







///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"“§–¾ó‘Ô:ÌßÚ²Ô-‚ªŒ©‚é‚±‚Æ‚ª‚Å‚«‚È‚¢A‘S•ŠíŽg—p•s‰Â"
	#define STRMSG_060509_0001			"–³“Gó‘Ô:ÀÞÒ-¼Þ‚ðŽó‚¯‚È‚¢"
	#define STRMSG_060509_0002			"½ÃÙ½Ó-ÄÞ:ÓÝ½À-‚©‚çæ§UŒ‚‚ðŽó‚¯‚È‚¢"

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you momentarily."
	#define	STRMSG_060526_0001			"Ž©“®±¯ÌßÃÞ-ÄŽÀs‚Å‚«‚Ü‚¹‚ñB\r\n\r\nŒöŽ®ƒTƒCƒg(%s)ÀÞ³ÝÛ-ÄÞÍß-¼Þ‚©‚çÊß¯Á‚ðŽó‚¯‚Ä²Ý½Ä-Ù‚µ‚Ä‚­‚¾‚³‚¢B\r\n\r\n    Error:%s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Œ»ÝID‚ª“o˜^‚³‚ê‚Ä‚¢‚È‚¢‚©A\r\n ID‚âPW‚ªŠÔˆá‚Á‚Ä‚¢‚Ü‚·B"
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Œ»Ý»-ËÞ½ÒÝÃÅÝ½’†‚Å‚·BÚ×‚Èà–¾‚ÍŒöŽ®ƒTƒCƒg‚ð‚²Šm”F‚­‚¾‚³‚¢B"

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"¸×²±ÝÄÊÞ-¼Þ®Ý‚ªˆÙ‚È‚è‚Ü‚·B\r\nŒöŽ®ƒTƒCƒg(%s)ÀÞ³ÝÛ-ÄÞÍß-¼Þ‚©‚çÊß¯Á‚ðŽó‚¯‚Ä²Ý½Ä-Ù‚µ‚Ä‚­‚¾‚³‚¢B"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"%s‚ÉŒ‚’Ä‚³‚ê‚Ü‚µ‚½B"			  			

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000			"‘å‰ï»-ÊÞ- DB(atum2_db_20) ‰Šú‰»‚Í‘å‰ï»-ÊÞ-ŒQ‚ðI—¹Œã‚É‚µ‚Ä‚­‚¾‚³‚¢B"
	#define STRMSG_070410_0001			"–{“–‚É‘å‰ï»-ÊÞ- DB(atum2_db_20)‚ð‰Šú‰»‚µ‚Ü‚·‚©H [”FØƒiƒ“ƒo-:%d]"
	#define STRMSG_070410_0002			"‘å‰ï»-ÊÞ- DB(atum2_db_20)‚ª‰Šú‰»‚³‚ê‚Ü‚µ‚½B"
	#define STRMSG_070410_0003			"‘å‰ï»-ÊÞ- DB(atum2_db_20)‰Šú‰»Ž¸”sI"
	#define STRMSG_070410_0004			"‘å‰ï»-ÊÞ- DB(atum2_db_20)‚É'%s'‚Ìî•ñºËß-Š®—¹"
	#define STRMSG_070410_0005			"‘å‰ï»-ÊÞ- DB(atum2_db_20)‚É'%s'‚Ìî•ñºËß-Ž¸”s-·¬×¸À-‚ª‘¶Ý‚µ‚Ü‚¹‚ñI"
	#define STRMSG_070410_0006			"‘å‰ï»-ÊÞ- DB(atum2_db_20)‚É'%s'‚Ìî•ñºËß-Ž¸”s-‘å‰ï»-ÊÞ-‚ÉŠY“–ƒAƒJƒEƒ“ƒg‚Ì·¬×¸À-‚ª‚ ‚è‚Ü‚·I"
	#define STRMSG_070410_0007			"‘å‰ï»-ÊÞ-DB(atum2_db_20)‚É'%s'‚Ìî•ñºËß-Ž¸”s-DB’Ç‰Á´×-‚Å‚·I"
	#define STRMSG_070410_0008			"‘å‰ï»-ÊÞ-DB(atum2_db_20)‚É'%s'‚Ìî•ñºËß-Ž¸”s-•s–¾(%d)I"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, ??? •¶Žš?
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

// 2007-06-15 by dhjin, ŠÏíŠÖ˜AƒXƒgƒŠƒ“ƒO
#define STRMSG_070615_0000				"“§–¾ó‘Ô‚Å‚Í‚È‚¢‚½‚ßŠÏí‚ðŠJŽn‚Å‚«‚Ü‚¹‚ñB"
#define STRMSG_070615_0001				"ŠÏí‚ðŠJŽn‚Å‚«‚Ü‚¹‚ñB"
#define STRMSG_070620_0000				"ˆê”Ê¨—Í‚ÍŠÏí‚Å‚«‚Ü‚¹‚ñB"

// 2007-06-26 by dhjin, í‘ˆ?ƒCƒ“ƒgiWPj ƒCƒxƒ“ƒg ŠÖ˜A ’Ç‰Á
#define STRMSG_S_F2EVENTTYPE_0006		"í‘ˆÎß²ÝÄiWPj"

// 2007-06-28 by cmkwon, ?? ?????(ƒQ?? ?? ?? ??) - ??? ’Ç‰Á
#define STRMSG_070628_0000				"??? ?? ƒQ????? ?? %d??? ?????."
#define STRMSG_070628_0001				"??? ?? ƒQ????? ?? %d??? ?????. ƒQ??I—¹??? ??? ??? ??? ??‚ð ???."
#define STRMSG_070628_0002				"??? ?? ??? ƒQ????? ??????. ??? ƒQ????? 50%%?? ?????. ??? ??‚ð ??? ƒQ?? I—¹??? ??? ??‚ð ??? ???? ????‚ð ?????"
#define STRMSG_070628_0003				"??? ?? ???? ƒQ????? ??????. ??? ??‚ð ??? ‘¦Žž? ƒQ?? I—¹???. ??? ??? ??? ??? ??? ??? ??? ƒQ????? 0%%?? ?????. ƒQ?? I—¹ ? 5???? ?? ??? ???? ?????."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, ±Ø-ÅƒuƒƒbƒN ¼½ÃÑ ‹ïŒ» - ’Ç‰Á‚µ‚½ƒXƒgƒŠƒ“ƒO
#define STRMSG_070711_0000				"\'%s\'—l‚Í±Ø-Å‚Ì—˜—pƒuƒƒbƒNó‘Ô‚Å‚Í‚ ‚è‚Ü‚¹‚ñB"
#define STRMSG_070711_0001				"\'%s\'—l‚Í±Ø-Å‚Ì—˜—pƒuƒƒbƒNó‘Ô‚Å‚·B(Žc‚èŽžŠÔ:%d•ª)"
#define STRMSG_070711_0002				"‚ ‚È‚½‚Í%d•ªŠÔ±Ø-Å‚Ì—˜—pƒuƒƒbƒNó‘Ô‚Å‚·I"
#define STRMSG_070711_0003				"±Ø-Å‚Ì—˜—pƒuƒƒbƒN‚ª‰ðœ‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_070711_0004				"\'%s\'—l‚Ì±Ø-Å‚Ì—˜—pƒuƒƒbƒN‚ª‰ðœ‚³‚ê‚Ü‚µ‚½B"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide ??? 1280x720(16:9) ’Ç‰Á - ??? ’Ç‰Á
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon, ‰ï‹cŽº ƒVƒXƒe? ?? - ??? ’Ç‰Á
#define STRMSG_070830_0001				"¨—Í‘I‘ðŒãAŽg—p‚Å‚«‚é–½—ßŒê‚Å‚·"
#define STRMSG_070830_0002				"ŠY“–¨—Í‚Ì‰ï‹cŽºÏ¯Ìß(%d)‚ª–³Œø‚Å‚·"
#define STRMSG_070830_0003				"Œ»Ý‰ï‹cŽº‚É“üê‚Å‚«‚él”:%dl"
#define STRMSG_070830_0004				"'%s'—l‚ÍŠù‚É‰ï‹cŽº“üêŒ ŒÀ‚ðŽ‚Á‚Ä‚¢‚Ü‚·B"
#define STRMSG_070830_0005				"'%s'—l‚Í‰ï‹cŽº“üêŒ ŒÀ‚ª‚ ‚è‚Ü‚¹‚ñB"
#define STRMSG_070830_0006				"'%s'‚Í–³Œø‚ÈƒLƒƒƒ‰ƒN??‚Å‚·B"
#define STRMSG_070830_0007				"'%s'‚ð‰ï‹cŽº“üêŒ ŒÀƒŠƒXƒg‚É’Ç‰Á‚Å‚«‚Ü‚¹‚ñB(Å‘å%dl)"
#define STRMSG_070830_0008				"'%s'—l‚É‰ï‹cŽº“üêŒ ŒÀ‚ª•t—^‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_070830_0009				"‰ï‹cŽº“üêŒ ŒÀ‚ª•t—^‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_070830_0010				"‰ï‹cŽº“üêŒ ŒÀ‚ª‰ðœ‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_070830_0011				"'%s'"

// 2007-11-13 by cmkwon, ???? ?? ’Ç‰Á - 
#define STRMSG_071115_0001				"\\y%s—l‚É%s±²ÃÑ‚ð ÌßÚ¾ÞÝÄ‚µ‚Ü‚µ‚½B"
#define STRMSG_071115_0002				"ÌßÚ¾ÞÝÄØ½Ä:\'%s(%dŒÂ)\'"
#define STRMSG_071115_0003				"\\y%s—l‚ª%s—l‚É%s±²ÃÑ‚ðÌßÚ¾ÞÝÄ‚µ‚Ü‚µ‚½B‘qŒÉ‚ðŠm”F‚µ‚Ä‚­‚¾‚³‚¢B"

// 2007-11-19 by cmkwon, i’æ¼½ÃÑ ±¯ÌßÃÞ-Ä -
#define STRMSG_071120_0001				"i’æ¼½ÃÑ—˜—pŽžŠÔ‚Å‚Í‚ ‚è‚Ü‚¹‚ñB¶½ÀÏ-¾ÝÀ-‚É‚¨–â‚¢‡‚í‚¹‚­‚¾‚³‚¢B"
#define STRMSG_071120_0002				"i’æ¼½ÃÑ‚ªŠˆ«‰»‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_071120_0003				"i’æ¼½ÃÑ‚ªI—¹‚µ‚Ü‚µ‚½B"
#define STRMSG_071120_0004				"%s‚©‚ç%s‚Ü‚Åi’æ¼½ÃÑ‚ðŽÀs‚µ‚Ü‚·B"

// 2007-11-28 by cmkwon, ’m¼½ÃÑ‹ïŒ» - 
#define STRMSG_071128_0001				"%s—l‚ª%s±²ÃÑ%dŒÂ‚ðÌßÚ¾ÞÝÄ‚µ‚Ü‚µ‚½B‘qŒÉ‚ðŠm”F‚µ‚Ä‚­‚¾‚³‚¢B"

// 2007-12-27 by cmkwon, ƒEƒCƒ“ƒhƒEÓ-ÄÞ??’Ç‰Á -
#define STRMSG_071228_0001				"‰ð‘œ“xÝ’è‚ª–³Œø‚Å‚·B‚à‚¤ˆê“xŠm”F‚µ‚Ä‚­‚¾‚³‚¢B"

// 2008-01-31 by cmkwon, ƒAƒJƒEƒ“ƒgƒuƒƒbƒN/‰ðœ–½—ßŒã‚Å‰Â”\‚È¼½ÃÑ‹ïŒ»-
#define STRMSG_080201_0001				"'%s'—lƒuƒƒbƒNÝ’è‚É´×-‚ª‚ ‚è‚Ü‚·B ErrorCode(%d)"
#define STRMSG_080201_0002				"'%s'ƒAƒJƒEƒ“ƒg‚ðƒuƒƒbƒNˆ—‚µ‚Ü‚µ‚½B[Block End Date:%s]"
#define STRMSG_080201_0003				"'%s'ƒAƒJƒEƒ“ƒg‚ªƒuƒƒbƒNƒŠƒXƒg‚É‚ ‚è‚Ü‚¹‚ñBErrorCode(%d)"
#define STRMSG_080201_0004				"'%s'ƒAƒJƒEƒ“ƒgƒuƒƒbƒN ‰ðœˆ—‚É´×-‚ª‚ ‚è‚Ü‚·BErrorCode(%d)"
#define STRMSG_080201_0005				"'%s'ƒAƒJƒEƒ“ƒg‚ðƒuƒƒbƒN‰ðœˆ—‚µ‚Ü‚µ‚½B"

// 2008-02-11 by cmkwon, ??? ’Ç‰Á(1440x900) -
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin,  ??±Ø-Å - ±Ø-Å »-ÊÞ- ?? ?? ??
#define STRMSG_S_MF2AFCONNECT_0000 "[Error]WndProc(),Can't connect to  ArenaServer[%15s:%4d]Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001 "Arena Server‚ÉÚ‘±‚µ‚Ü‚µ‚½B\r\n"
#define STRMSG_S_MF2AFCONNECT_0002 "Arena Server[%15s:%4d]‚Æ‚ÌÚ‘±‚ªI—¹‚µ‚Ü‚µ‚½BÄÚ‘±‚µ‚Ü‚·B\r\n"
#define STRMSG_S_MF2AFCONNECT_0003 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004 "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001		"\\y%d”ÔƒAƒŠ-ƒiwaiting room‚ÉƒCƒxƒ“ƒg‘®«‚ð’Ç‰Á‚µ‚Ü‚µ‚½B\r\n"
#define STRMSG_ARENAEVENT_080310_0002		"\\y%d”ÔƒAƒŠ-ƒiRoom‚ÌƒCƒxƒ“ƒg‘®«‚ð‰ðœ‚µ‚Ü‚µ‚½B\r\n"
#define STRMSG_ARENAEVENT_080310_0003		"\\yƒAƒŠ-ƒiƒCƒxƒ“ƒg‘®«‚Ì’Ç‰Á‚ÉŽ¸”s‚µ‚Ü‚µ‚½B\r\n"
#define STRMSG_080428_0001					"%s—l‚ðŒ‚’Ä‚µ‚Ü‚µ‚½B"		// 2008-04-28 by dhjin, ±Ø-Å ?? - ‘ŠŽè Œ‚’Ä ? ??? ’Ç‰Á, ±Ø-Å Ï¯Ìß???

// 2008-04-29 by cmkwon, »-ÊÞ- î•ñ DB? ’Ç‰Á(?? ƒAƒJƒEƒ“ƒg ·¬×¸À- ì¬ ?? ¼½ÃÑ’Ç‰Á) - 
#define STRMSG_080430_0001					"‘I‘ð‚µ‚½ƒT-ƒo‚ÍV‹K·¬×¸À-ì¬‚ª§ŒÀ‚³‚ê‚Ä‚¢‚éƒT-ƒo-‚Å‚·B"

// 2008-06-13 by dhjin, EP3 —·’c ?? ?? - 
#define STRMSG_080613_0001					"%s—·’c‚Ö‚Ì‰Á“ü\‚µž‚Ý‚ªƒuƒƒbƒN‚³‚ê‚Ü‚µ‚½B"

// 2008-09-04 by cmkwon, don't need translation, ƒT?ƒo? SystemLog ??? ?? ?? ??	
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, Žw“±ŽÒÁ¬¯Ä§ŒÀƒJ-ƒh
#define STRMSG_081230_0001					"\\y%s‚ÌÁ¬¯ÄŽg—p‚ð%d•ªŠÔ§ŒÀ‚µ‚Ü‚·B\\y"
#define STRMSG_081230_0002					"\\yŽw“±ŽÒ‚ÌŒ ŒÀ‚É‚æ‚è‚ ‚È‚½‚ÌÁ¬¯ÄŽg—p‚ª%d•ªŠÔ§ŒÀ‚³‚ê‚Ü‚µ‚½B\\y"
#define STRMSG_081230_0003					"\\yŽw“±ŽÒÁ¬¯Ä§ŒÀ‚ª‰ðœ‚³‚ê‚Ü‚µ‚½B\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °ÔÀÓ°¡µEµ¿ÀÇÃ¢ ¶ç¿EE- 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µEµ¿ÀÇÃ¢ WebPage·Î Ã³¸® - STRMSG_090831_0001´Â À¥ÆäÀÌÁö·Î Ã³¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µEµ¿ÀÇÃ¢ WebPage·Î Ã³¸® - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿EÇØ»óµµ Ãß°¡(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ÀÎÁE¼­¹öÀÇ Á¢¼Ó Çã¿E»óÈ²
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"“o˜^‚³‚ê‚Ä‚¢‚È‚¢ƒT-ƒo-‚Å‚·Biƒvƒ‰ƒCƒx-ƒgƒT-ƒo‚Å‚ ‚é‰Â”\«‚ª‚ ‚è‚Ü‚·j"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				" DB˜A“®Žž‚ÉƒGƒ‰-‚ª”­¶‚µ‚Ü‚µ‚½B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"ƒT-ƒo-”FØ‚É¬Œ÷‚µ‚Ü‚µ‚½B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"ŠY“–ƒT-ƒo-‚ÉIP‚ª“o˜^‚³‚ê‚Ä‚¢‚Ü‚·‚ªA”FØ‹‘”Ûˆ—‚ª‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"ƒT-ƒo-‚É‹­§I—¹ºÏÝÄÞ‚ð‘—M‚µ‚Ü‚µ‚½B"






#define STRMSG_120330_0001	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅA‰B‚³‚ê‚½‹óŠÔ‚Ö‚Ìƒ-ƒvƒQ-ƒg‚ð”­“®‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0002	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅAÓÝ½À-ŒoŒ±•ª100%%%%‘‰Á‚Ìƒo-ƒXƒgƒCƒxƒ“ƒg(1ŽžŠÔ)‚ð”­“®‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0003	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅA±²ÃÑÄÞÛ¯Ìß—¦100%%%%‘‰Á‚Ìƒo-ƒXƒgƒCƒxƒ“ƒgi1ŽžŠÔj‚ð”­“®‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0004	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅA±²ÃÑÄÞÛ¯Ìß—¦100%%%%/MonsterŒoŒ±’l100%%%%/ SPIŠl“¾—¦100%%%%‘‰Á‚Ìƒo-ƒXƒgƒCƒxƒ“ƒgi1ŽžŠÔj‚ð”­“®‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0005	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅWeapon shop‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0006	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅƒnƒCƒp-ƒJ-ƒhƒVƒ‡ƒbƒv‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0007	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅƒLƒbƒgƒVƒ‡ƒbƒv‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0008	"%s—l‚ªƒAƒbƒVƒ…ƒŒ-ƒ“‚ÅBoss Monster‚ð¢ŠÒ‚µ‚Ü‚µ‚½B"
#define STRMSG_120330_0009	"CRYSTAL‚ªÁ–Å‚µ‚Ü‚µ‚½B"



#define STRMSG_120508_0001					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚©‚ç%WP‚ðŽæ“¾‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0002					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅBoss monsters‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0003					"%—l‚ªƒo-ƒXƒgƒCƒxƒ“ƒg(1ŽžŠÔ)‚ð”­“®‚µ‚Ü‚µ‚½BÓÝ½À-ŒoŒ±’l‚ª150%%%%‘‰Á‚µ‚Ü‚·B"
#define STRMSG_120508_0004					"%—l‚ªƒo-ƒXƒgƒCƒxƒ“ƒg(1ŽžŠÔ)‚ð”­“®‚µ‚Ü‚µ‚½B±²ÃÑÄÞÛ¯Ìß—¦‚ª150%%%%‘‰Á‚µ‚Ü‚·B"
#define STRMSG_120508_0005					"%—l‚ªƒo-ƒXƒgƒCƒxƒ“ƒg(1ŽžŠÔ)‚ð”­“®‚µ‚Ü‚µ‚½BÓÝ½À-ŒoŒ±’l/±²ÃÑÄÞÛ¯Ìß—¦/SPIŠl“¾—¦‚ª150%%%%‘‰Á‚µ‚Ü‚·B"
#define STRMSG_120508_0006					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅŒÃ‘ã‚Ì•X‚ðŽæ“¾‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0007					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅItem shop‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0008					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅƒLƒbƒgƒVƒ‡ƒbƒv‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0009					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅƒnƒCƒp-ƒJ-ƒhƒVƒ‡ƒbƒv‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0010					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚ÅWeapon shop‚ð¢Š«‚µ‚Ü‚µ‚½B"
#define STRMSG_120508_0011					"%—l‚ªƒƒXƒgƒIƒAƒVƒX‚Å‰B‚³‚ê‚½‹óŠÔ‚Ö‚Ìƒ-ƒvƒQ-ƒg‚ð¢Š«‚µ‚Ü‚µ‚½B"

#define STRMSG_120712_0001					"18¼¼ ¹Ì¸¸ Ã»¼Ò³â¿¡°Ô Àû¿EÇ´?°ÔÀÓ½Ã°£ ¼±ÅÃÁ¦ ¼³Á¤À¸·Î ÀÎÇÏ¿©, %d ºÐ ÈÄ¿¡ °ÔÀÓÀÌ Á¾·áµË´Ï´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀE¼Ë´Ù¿E

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹E¸ðµE
#define STRMSG_121005_0001					"\\yPC¹E°¡¸ÍÁ¡ ½Ã°£ÀÌ %dºÐ ³²¾Ò½À´Ï´Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹E°¡¸ÍÁ¡ÀÌ Á¾·áµË´Ï´Ù."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀEE½Ã½ºÅÛ ¸®´º¾E- ÀEE?Æ®¸®°Å ¹«Àû»óÅÂ(ÀÏ½ÃÁ¤ÁE
#define STRMSG_121126_0001					"\\yCommand : í‘ˆŽž‚Í¸Ø½ÀÙ‚Ì”j‰ó‚Ío—ˆ‚Ü‚¹‚ñB\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ
#define STRMSG_121129_0001					"\\y‚±‚ÌƒGƒŠƒA‚ÍGMˆÈŠOi“ü‚Å‚«‚Ü‚¹‚ñB\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀEEâÁEÆ®¸®°Å ½Ã½ºÅÛ
#define STRMSG_130121_0001					"\\cƒVƒXƒeƒ€‚ÍNGCŒR‚É‚æ‚Á‚Ä•ß‚¦‚ç‚ê‚Ü‚µ‚½B‘¦Žž“P‘Þ‚ªŠJŽn‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_130121_0002					"\\c’ãŽ@•º:\\c NGC§Œä‹@‚ªŠm”F‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_130121_0003					"\\c’ãŽ@•º:\\c NGC§Œä‹@‚ª”j‰ó‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_130121_0004					"\\cŽw—ß:\\c NGCƒSƒ‚ƒ‰‚ÌƒoƒŠƒA‚ª“WŠJ‚³‚ê‚Ü‚µ‚½IƒoƒŠƒA‚ð–³Œø‰»‚·‚éˆ×‚É§Œä‹@‚ð”j‰ó‚µ‚Ä‚­‚¾‚³‚¢I"
#define STRMSG_130121_0005					"\\cŽw—ß:\\c ƒSƒ‚ƒ‰‚ÌƒoƒŠƒA‚ª”j‰ó‚³‚ê‚Ü‚µ‚½I‘UŒ‚‚ðŠJŽn‚µ‚Ä‚­‚¾‚³‚¢I"
#define STRMSG_130121_0006					"\\cŽw—ß:\\c ƒSƒ‚ƒ‰‚ª”j‰ó‚³‚ê‚Ü‚µ‚½IŠe‹@‚Í‘O•û‚ÖˆÚ“®‚ðŠJŽn‚µ‚Ä‚­‚¾‚³‚¢I"
#define STRMSG_130121_0007					"\\cŽw—ß:\\c ƒSƒ‚ƒ‰‚ÍÅ‰‚É”j‰ó‚µ‚È‚¯‚ê‚Î‚È‚è‚Ü‚¹‚ñB"
#define STRMSG_130121_0008					"\\c[%s]‚ÌŒø‰Ê‚ÍNGC§Œä‹@‚Ì‰Ò“­‚ªŒ´ˆö‚Å‚·B"
#define STRMSG_130121_0009					"\\y[NGCƒAƒhƒoƒ“ƒXƒx[ƒXŠî’nƒVƒXƒeƒ€]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ ÀÌº¥Æ® - ¼­ºE¸ÀÔ Ãß°¡±¸Á¶ ½Ã½ºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d‚ÍƒAƒŠ[ƒi‚©‚ç§ŒÀ‚³‚ê‚Ä‚¢‚Ü‚·BƒAƒCƒeƒ€‚Í‘qŒÉ‚É‘—‚ç‚ê‚Ü‚µ‚½B\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Æ¸Ó ÄÃ·º¼Ç - STRMSG Ãß°¡
#define STRMSG_130531_0001					"\\g[%s] ŠO‘•‚ÍƒA[ƒ}[ƒRƒŒƒNƒVƒ‡ƒ“‚É’Ç‰Á‚³‚ê‚Ü‚µ‚½B\\g"
#define STRMSG_130531_0002					"\\g[%s] ŠO‘•‚Í[%2d]‰ñ“K—p‚³‚ê‚Ü‚µ‚½B\\g"
#define STRMSG_130531_0003					"\\g[%s] ŠO‘•‚Í“K—p‰Â”\‰ñ”‚É’B‚µ‚Ü‚µ‚½Bm%sn‚Ö•ÏX‚³‚ê‚Ü‚·B\\g"
#define STRMSG_130531_0004					"ŠO‘•‚Ì“K—pŠúŒÀ‚ª‰ß‚¬‚½ˆ×AƒXƒe[ƒ^ƒX‚ªíœ‚³‚ê‚Ü‚µ‚½BƒGƒ“ƒWƒ“‚ª‘•”õ‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB"
#define STRMSG_130531_0005					"\\yƒGƒ“ƒWƒ“‚ª‘•”õ‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB“sŽs‚É‹AŠÒ‚µ‚Ä‚­‚¾‚³‚¢B\\y"
#define STRMSG_130531_0006					"\\gŒ»ÝƒA[ƒ}[‚É“K—p‚³‚ê‚Ä‚¢‚éŠO‘•‚ðŽg—p‚·‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñB\\g"
#define STRMSG_130531_0007					"\\gŠO‘•‚ª•ÏX‚³‚ê‚Ü‚µ‚½B\\g"
#define STRMSG_130531_0008					"\\rm%snŠO‘•‚ÍŠúŒÀØ‚ê‚É‚È‚è‚Ü‚µ‚½B\\r"
#define STRMSG_130531_0009					"\\yŠO‘•‚ð“K—p‚µ‚½ƒA[ƒ}[‚ð”„‹p‚·‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñB\\y"
#define STRMSG_130531_0010					"\\yƒMƒAƒ^ƒCƒv‚ªˆê’v‚µ‚Ü‚¹‚ñB\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, Æ®¸®°Å ½Ã½ºÅÛ È®ÀE- STRMSG Ãß°¡
#define STRMSG_130708_0001					"\\cŽw—ß:\\c NGCŒR‚ÌƒV[ƒ‹ƒh‚ª“WŠJ‚³‚ê‚Ü‚µ‚½BƒV[ƒ‹ƒh‚ð–³Œø‰»‚·‚é‚É‚ÍNGCƒRƒ“ƒgƒ[ƒ‰[‚ð”j‰ó‚µ‚Ä‚­‚¾‚³‚¢I"
#define STRMSG_130708_0002					"\\cŽw—ß:\\c NGCŒRŽ–Šî’nƒV[ƒ‹ƒh‚ªƒ_ƒEƒ“‚µ‚Ä‚¢‚Ü‚·BUŒ‚‚ðŠJŽn‚µ‚Ä‚­‚¾‚³‚¢I"
#define STRMSG_130708_0003					"\\c’ãŽ@•º:\\c NGCƒV[ƒ‹ƒhƒWƒFƒlƒŒ[ƒ^[‚ªŠm”F‚³‚ê‚Ü‚µ‚½B"
#define STRMSG_130708_0004					"\\c’ãŽ@•º:\\c NGCƒV[ƒ‹ƒhƒWƒFƒlƒŒ[ƒ^[‚ª”j‰ó‚³‚ê‚Ü‚µ‚½B"

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Å¸ °èÁ¤ ¼¼·Âº¯°E
#define STRMSG_130726_0001					"ƒLƒƒƒ‰ƒNƒ^[‚Í‚·‚Å‚É‚»‚Ì¨—Í‚Å‚·B"
#define STRMSG_130726_0002					"ƒLƒƒƒ‰ƒNƒ^[‚ÍƒŠ[ƒ_[‚Ü‚½‚ÍƒTƒuƒŠ[ƒ_[‚Å‚·B‚»‚Ì‚½‚ß¨—Í‚ð•ÏX‚·‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñB"
#define STRMSG_130726_0003					"ƒLƒƒƒ‰ƒNƒ^[‚Í—·’c‚É“ü’c‚µ‚Ä‚¢‚éˆ×A¨—Í‚ð•ÏX‚·‚é‚±‚Æ‚Í‚Å‚«‚Ü‚¹‚ñB"
#define STRMSG_130726_0004					"¨—Í•ÏX‰Â”\‚ÈƒLƒƒƒ‰ƒNƒ^[‚ª‚¢‚Ü‚¹‚ñB"
#define STRMSG_130726_0005					"¨—Í•ÏX‚ÉŽ¸”s‚µ‚Ü‚µ‚½B[AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"¨—Í•ÏX‚É¬Œ÷‚µ‚Ü‚µ‚½B [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"ƒAƒJƒEƒ“ƒg‚ª‘¶Ý‚µ‚Ü‚¹‚ñB"
#define STRMSG_130726_0008					"ƒAƒJƒEƒ“ƒg‚ªƒƒOƒCƒ“‚µ‚Ä‚¢‚éˆ×A¨—Í•ÏX‚ª‚Å‚«‚Ü‚¹‚ñB"


// 2013-08-30 by bckim, ÇÊµåÀÌµ¿±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\\y%s—l‚ªŽw“±ŽÒŒ ŒÀ‚ÅMAP‚Ö‚ÌˆÚ“®‚ª§ŒÀ‚³‚ê‚Ü‚µ‚½B\\y"
#define STRMSG_130830_0002					"\\yŒ»ÝŽw“±ŽÒŒ ŒÀ‚É‚æ‚Á‚ÄMAP‚Ö‚ÌˆÚ“®‚ª§ŒÀ‚³‚ê‚½ó‘Ô‚Å‚·B\\y"
#define STRMSG_130830_0003					"\\y%ŠY“–Õ-»Þ-‚ÍŽw“±ŽÒŒ ŒÀ‚É‚æ‚Á‚ÄMAP‚Ö‚ÌˆÚ“®‚ª§ŒÀ‚³‚ê‚½ó‘Ô‚Å‚·B\\y"
// End. 2013-08-30 by bckim, ÇÊµåÀÌµ¿±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­È­
#define STRMSG_130828_0001					"\\y[%s]—l •W“I‚ÌŒ‚”j‚ÉvŒ£‚µ‚Ü‚µ‚½B\\y"
#define STRMSG_130828_0002					"\\y[%s]—l •W“I‚É‘Î‚·‚éæ§UŒ‚‚ðs‚¢‚Ü‚µ‚½B\\y"
#define STRMSG_130828_0003					"\\y[%s]—l •W“I‚É‘Î‚µ‚Äˆê’è‚Ìƒ_ƒ[ƒW‚ð—^‚¦‚Ü‚µ‚½B \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s]—l •W“I‚É‘Î‚·‚éƒ‰ƒXƒgƒAƒ^ƒbƒN‚É‚È‚è‚Ü‚µ‚½B\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n‚ÌŒ‚”j‚É¬Œ÷‚µ‚Ü‚µ‚½BŽŸ‚àŠæ’£‚Á‚Ä‚­‚¾‚³‚¢B"
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­È­

// 2013-08-14 by jhseol, °ÅÁ¡ÀE¸®´º¾E- ½Â¸®¼¼·Â GM ¸Þ¼¼ÁE»Ñ¸®±E
#define STRMSG_130814_0001					"\\y[%s] NGC‹’“_í‚ÉŸ—˜‚µ‚Ü‚µ‚½B\\y"
// end 2013-08-14 by jhseol, °ÅÁ¡ÀE¸®´º¾E- ½Â¸®¼¼·Â GM ¸Þ¼¼ÁE»Ñ¸®±E

// 2014-03-12 by bckim, ¹ö´×Å¸ÀÓ(ÀEEö¿ª)
#define STRMSG_130318_0001					"%s §ŒÀ‹æˆæ“à‚Ìƒ{ƒXƒ‚ƒ“ƒXƒ^[‚ð¢Š«‚µ‚Ä‚¢‚Ü‚·B"
#define STRMSG_130318_0002					"%s ”pšÐ‚Ì“sŽs‚Ìƒ{ƒXƒ‚ƒ“ƒXƒ^[‚ð¢Š«‚µ‚Ä‚¢‚Ü‚·B"
// End. 2014-03-12 by bckim, ¹ö´×Å¸ÀÓ(ÀEEö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yŒ»Žž“_‚Å‚ÍƒgƒŒ[ƒhƒVƒ‡ƒbƒv‚ð—˜—p‚·‚éŽ–‚ªo—ˆ‚Ü‚¹‚ñB\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
