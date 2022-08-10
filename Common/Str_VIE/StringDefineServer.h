
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Maìy chuÒ không hoaòt ğôòng"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre server!"
	#define STRERR_S_ATUMEXE_0003 "Viêòc câòp nhâòt tıò ğôòng không thành công.\r\nBaòn haŞy caÌi ğãòt laòi troÌ chõi.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "LôŞi không xaìc ğiònh: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Không kêìt nôìi ğıõòc Server download"
	#define STRERR_S_ATUMEXE_0007 "Không nhâòn biêìt ğıõòc dung lıõòng file taÒi vêÌ."
	#define STRERR_S_ATUMEXE_0008 "Không taÒi ğıõòc file ğaŞ câòp nhâòt ."
	#define STRERR_S_ATUMEXE_0009 "Hêò thôìng thiêìu bôò nhõì hoãòc taÌi nguyên."
	#define STRERR_S_ATUMEXE_0010 "LôŞi file chaòy."
	#define STRERR_S_ATUMEXE_0011 "Không tiÌm ğıõòc file."
	#define STRERR_S_ATUMEXE_0012 "Không tiÌm thâìy ğıõÌng dâŞn chiÒ ğiònh."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Cap nhat hoan tat."
	#define STRMSG_S_ATUMLAUNCHER_0001 "Chon may chu."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Dang cap nhat danh sach file can xoa v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Dang xoa file."
	#define STRMSG_S_ATUMLAUNCHER_0004 "Dang cap nhat thong bao"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Cap nhat hoan tat (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Chon file tien hanh"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Chon cach thuc hien"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Huy viec tai file"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Tai file ket thuc"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Cap nhat voi v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Khong the tao file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Cap nhat toi v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Dang nhan thong tin file %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°æ
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, º£Æ®³² X-Trap -> VTC °¡µå·Î º¯°æ
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Khong ket noi duoc toi May chu Certificate."
	#define STRERR_S_ATUMLAUNCHER_0005 "Khong ket noi duoc toi Server."
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket bi dong boi Pre server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Loi tep Thong bao!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Ban hay tai lai tro choi.\nURL: http://phidoi.vtc.vn/\nphien ban moi nhat: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Khong the tu dong cap nhat.\r\nBan hay cai dat lai tro choi.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Tat ca may chu dang o trang thai chua kich hoat."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%sDang kiem tra..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Dang tien hanh kiem tra server. Ban vui long truy cap lai lan khac."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from %s[%s]\r\n"
// 2006-08-24 by cmkwon, Change to STRMSG_060824_0000
//	#define STRERR_S_ATUMLAUNCHER_0014 "ID hoac Mat khau khong chinh xac. Vui long nhap lai."
	#define STRERR_S_ATUMLAUNCHER_0015 "Dang nhap that bai."
	#define STRERR_S_ATUMLAUNCHER_0016 "Vui long nhap ID."
	#define STRERR_S_ATUMLAUNCHER_0017 "Dang nhap trung lap."
	#define STRERR_S_ATUMLAUNCHER_0018 "F server khong hoat dong."
	#define STRERR_S_ATUMLAUNCHER_0019 "I server khong hoat dong."
	#define STRERR_S_ATUMLAUNCHER_0020 "Dich vu dang tam ngung hoat dong.\n\nXin ban vui long truy cap lan sau."
	#define STRERR_S_ATUMLAUNCHER_0021 "Hien dang co qua dong nguoi truy cap.\n\nXin ban vui long truy cap luc khac."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Tai khoan cua ban dang bi Khoa.\n Thoi gian : %s\n\nThong tin chi tiet vui long lien he qua email ho tro: support.phidoi@vtc.vn."
	#define STRERR_S_ATUMLAUNCHER_0023 "Sai phien ban client.\n\nBan hay tai lai game."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Khong ket noi duoc den may chu download."
	#define STRERR_S_ATUMLAUNCHER_0026 "Khong xac dinh duoc do lon cua file tai ve (%s)."
	#define STRERR_S_ATUMLAUNCHER_0027 "Khong xac dinh duoc do lon cua file tai ve."
	#define STRERR_S_ATUMLAUNCHER_0028 "Khong tai duoc file cap nhat."
	#define STRERR_S_ATUMLAUNCHER_0029 "File cap nhat khong ton tai."
	#define STRERR_S_ATUMLAUNCHER_0030 "May chu nay dang duoc kiem tra. Ban vui long truy cap lai lan sau."
	#define STRERR_S_ATUMLAUNCHER_0031 "Tran bo nho / tai nguyen he thong!"
	#define STRERR_S_ATUMLAUNCHER_0032 "File .exe khong hop le."
	#define STRERR_S_ATUMLAUNCHER_0033 "Khong tim duoc file."
	#define STRERR_S_ATUMLAUNCHER_0034 "Khong tim duoc loi."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹Ì¸¸ Ã»¼Ò³â¿¡°Ô Àû¿ëµÇ´Â °ÔÀÓ½Ã°£ ¼±ÅÃÁ¦ ¼³Á¤À¸·Î ÀÎÇÏ¿©, ÇöÀç ½Ã°£¿¡´Â °ÔÀÓ ÁøÇàÀÌ ºÒ°¡´ÉÇÕ´Ï´Ù.\n\nÀÚ¼¼ÇÑ »çÇ×Àº ¿¡ÀÌ½º¿Â¶óÀÎ °í°´¼¾ÅÍ·Î ¹®ÀÇ¹Ù¶ø´Ï´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼Ë´Ù¿î



	#define STRMSG_S_050506		"Tai khoan \'%s\' dang bi khoa.\n  Ly do: %s\n  Thoi gian: %s~%s\n\nThong tin chi tiet vui long lien he qua email: support.phidoi@vtc.vn."
	#define STRMSG_S_050930		"Ban hay tai lai tro choi.\nURL: %s\n phien ban moi nhat."
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Nam"
//	#define STRMSG_S_SCADMINTOOL_0001 "NıŞ"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d Nãm, %d TuôÒi"
//	#define STRMSG_S_SCADMINTOOL_0003 "Baòn thıòc sıò muôìn sıÒa taÌi khoaÒn?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'Cái'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'nhâòn cái, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'cái'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''' + l.PeerCharacterName + '''?? ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'cái cho, ' + CAST(l.CurrentCount AS VARCHAR(10)) + ‘cái'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''' + l.PeerCharacterName + '''from ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi ğaŞ nhâòn, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'cái'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10)) + 'cái boÒ, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'cái'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'cái mua, coÌn laòi Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'cái bán, coÌn laòi Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'cái'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' ğaŞ thêm ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi, tôÒng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'caìi'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' xoaì ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi, tôÒng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'caìi'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Thêm ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'caìi'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Xoaì ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi, tôÒng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'caìi'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Recover ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'caìi, tôÒng' + CAST(l.CurrentCount AS VARCHAR(10)) + 'caìi'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'thõÌi gian chõi \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', toaÌn bôò \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', thõÌi gian chõi: ' + dbo.atum_GetHMSFromS(l.Param3)"	
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' tãng giaÒm, tãng \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "ğâm"
//	#define STRMSG_S_SCADMINTOOL_0021 "quaìi vâòt"
//	#define STRMSG_S_SCADMINTOOL_0022 "phi cõ"
//	#define STRMSG_S_SCADMINTOOL_0023 "Nguyên nhân không xaìc ğiònh"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Stat coÌn laòi: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Không có)"
//	#define STRMSG_S_SCADMINTOOL_0026 "baÒn thân"
//	#define STRMSG_S_SCADMINTOOL_0027 "Không có"
//	#define STRMSG_S_SCADMINTOOL_0028 "NgıõÌi sıÒ duòng bug"
	#define STRMSG_S_SCADMINTOOL_0029 "taÌi khoaÒn block"
	#define STRMSG_S_SCADMINTOOL_0030 "Câìm chat"
//	#define STRMSG_S_SCADMINTOOL_0031 "Log truy câòp"
//	#define STRMSG_S_SCADMINTOOL_0032 "Log ngıõÌi chõi"
//	#define STRMSG_S_SCADMINTOOL_0033 "Log Item "
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s server"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s server,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 " Khóa nick"
//	#define STRMSG_S_SCADMINTOOL_0037 "Phân loaòi"
//	#define STRMSG_S_SCADMINTOOL_0038 "ğõn viò"
	#define STRMSG_S_SCADMINTOOL_0039 "Baòn có muôìn mõÒ taÌi khoaÒn biò khoá?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d giây)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d thãìng %d baòi"
	#define STRMSG_S_SCADMINTOOL_0042 "Baòn thıòc sıò muôìn ngıÌng kêìt nôìi và chãòn?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s Item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] thông báo : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Sôì ngıõÌi sıÒ duòng: %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] tin nhãìn ğıõòc nhâòn : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Sôì ngıõÌi chõi : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Field server state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "NgıÌng kêìt nôìi server\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Không ğoòc ğıõòc thông tin vêÌ tài khoaÒn."
	#define STRERR_S_SCADMINTOOL_0001 "Viêòc sıÒa taÌi khoaÒn không thành công."
	#define STRERR_S_SCADMINTOOL_0002 "Baòn haŞy ğiêÌn mâòt khâÒu"
	#define STRERR_S_SCADMINTOOL_0003 "Sai mâòt khâÒu"
	#define STRERR_S_SCADMINTOOL_0004 "Baòn haŞy ğiêÌn ID"
	#define STRERR_S_SCADMINTOOL_0005 "Pre server không hoaòt ğôòng."
	#define STRERR_S_SCADMINTOOL_0006 "Không thêÒ truy câòp ğêìn Preserver !!"
	#define STRERR_S_SCADMINTOOL_0007 "viêòc xác nhâòn không thành công"
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: Không tôÌn taòi Protocol tıõng thích."
	#define STRERR_S_SCADMINTOOL_0009 "Baòn haŞy ğiêÌn tên ngıõÌi sıÒ duòng"
	#define STRERR_S_SCADMINTOOL_0010 "Baòn haŞy ğiêÌn lyì do"
	#define STRERR_S_SCADMINTOOL_0011 "LôŞi vêÌ viêòc lâòp chiÒ sôì kinh nghiêòm : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Sôì lıõòng log ğaŞ quá taÒi.\r\n\r\nXin baòn vui loÌng sıÒa laòi sôì log hoãòc ğiêÌu kiêòn tiÌm."
	#define STRERR_S_SCADMINTOOL_0013 "Không truy câòp ğıõòc cõ sõÒ dıŞ liêòu."
	#define STRERR_S_SCADMINTOOL_0014 "Không truy câòp ğıõòc"
	#define STRERR_S_SCADMINTOOL_0015 "Truy câòp"
	#define STRERR_S_SCADMINTOOL_0016 "Ğang nâng câìp"
	#define STRERR_S_SCADMINTOOL_0017 "Ğãng nhâòp"
	#define STRERR_S_SCADMINTOOL_0018 "Ğang lıòa choòn nhân vâòt "
	#define STRERR_S_SCADMINTOOL_0019 "Ğang chõi"
	#define STRERR_S_SCADMINTOOL_0020 "Không xaìc ğiònh"
	#define STRERR_S_SCADMINTOOL_0021 "Không truy câòp ğıõòc cõ sõÒ dıŞ liêòu %s(%s:%d)."
	#define STRERR_S_SCADMINTOOL_0022 "Viêòc tãng thêm Item không thành công"
	#define STRERR_S_SCADMINTOOL_0023 "Viêòc tiÌm nick biò khóa không thành công."
	#define STRERR_S_SCADMINTOOL_0024 "ĞêÒ sıÒa, Baòn haŞy ngıÌng viêòc kêìt nôìi taÌi khoaÒn và khóa taÌi khoaÒn!"
	#define STRERR_S_SCADMINTOOL_0025 "Baòn không thêÒ tãng thêm SPI(TiêÌn)."
	#define STRERR_S_SCADMINTOOL_0026 "Item baòn choòn ğaŞ có, Baòn haŞy sıÒa laòi sôì lıõòng"
	#define STRERR_S_SCADMINTOOL_0027 "LôŞi vêÌ tiÌm Item"
	#define STRERR_S_SCADMINTOOL_0028 "Baòn không thêÒ xóa SPI(TiêÌn) mà nhân vâòt sõÒ hıŞu."
	#define STRERR_S_SCADMINTOOL_0029 "Baòn muôìn xóa Item?"
	#define STRERR_S_SCADMINTOOL_0030 "viêòc xóa Item không thành công."
	#define STRERR_S_SCADMINTOOL_0031 "viêòc sıÒa Item không thành công."
	#define STRERR_S_SCADMINTOOL_0032 "Baòn haŞy ğiêÌn taÌi khoaÒn"
	#define STRERR_S_SCADMINTOOL_0033 "taÌi khoaÒn này không tôÌn taòi.( Có thêÒ cài block taÌi khoaÒn)"
	#define STRERR_S_SCADMINTOOL_0034 "Không tôÌn taòi taÌi khoaÒn hoãòc nhân vâòt."
	#define STRERR_S_SCADMINTOOL_0035 "LôŞi xem thông tin nhân vâòt."
	#define STRERR_S_SCADMINTOOL_0036 "Không tôÌn taòi nhân vâòt tıõng ıìng"
	#define STRERR_S_SCADMINTOOL_0037 "LôŞi nâng câìp nhân vâòt"
	#define STRERR_S_SCADMINTOOL_0038 "Viêòc câòp nhâòt thông tin nhân vâòt ğaŞ thành công "
	#define STRERR_S_SCADMINTOOL_0039 "Baòn haŞy choòn Item."
	#define STRERR_S_SCADMINTOOL_0040 "Baòn haŞy choòn sôì lıõòng Item."
	#define STRERR_S_SCADMINTOOL_0041 "Baòn chiÒ ğıõòc taòo dıõìi 5cái."
	#define STRERR_S_SCADMINTOOL_0042 "Baòn haŞy nhâòp tin nhãìn."
	#define STRERR_S_SCADMINTOOL_0043 "Không thêÒ truyêÌn thông tin."
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM server không hoaòt ğôòng."
	#define STRERR_S_SCADMINTOOL_0046 "Field server không hoaòt ğôòng."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMserver state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÄÆ®³Ê - ¾îµå¹Î Åø ÆÄÆ®³Ê ±â´É¿¡¼­ »ç¿ëµÇ´Â MSG
#define STRERR_S_SCADMINTOOL_0048 "Không thêÒ thaìo kyŞ nãng khi ğaŞ trang biò cho Partner."
#define STRERR_S_SCADMINTOOL_0049 "Ğang lıu log vêÌ lôŞi trong quaì triÌnh thay ğôÒi Partner.\r\n(ChiÒ lıu nhıŞng log vêÌ lôŞi)"
#define STRERR_S_SCADMINTOOL_0050 "Viêòc taÒi thông tin vêÌ Partner biò lôŞi."
#define STRERR_S_SCADMINTOOL_0051 "KyŞ nãng ğıõòc trang biò lôŞi ğaŞ biò xoìa."
#define STRERR_S_SCADMINTOOL_0052 "The applying hidden option for equipped item is failed."
#define STRERR_S_SCADMINTOOL_0053 "The revision for the Partner¡¯s socket item is failed."
#define STRERR_S_SCADMINTOOL_0054 "LôŞi câòp nhâòt thông tin cuÒa Partner."
#define STRERR_S_SCADMINTOOL_0055 "LôŞi taÒi thông tin vêÌ câìp ğôò cuÒa Partner."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿î¿µÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿î¿µÅø±â´ÉÃß°¡, ÀÎÃ¦Æ®¾ÆÀÌÅÛÁ¦°Å±â´É. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "Tên taÌi khoaÒn"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Loaòi"
//	#define STRMSG_S_SCAT_COLNAME_0002 "ToaÌn bôò"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Viêòc bãìt ğâÌu"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Viêòc kêìt thúc"
//	#define STRMSG_S_SCAT_COLNAME_0005 "NgıõÌi giaÒi quyêìt"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Lyì do"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Ngày"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Loaòi log"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IP Address"
//	#define STRMSG_S_SCAT_COLNAME_0010 "Tên server"
//	#define STRMSG_S_SCAT_COLNAME_0011 "Tên nhân vâòt"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Viò trí"
//	#define STRMSG_S_SCAT_COLNAME_0013 "Nôòi dung"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Item"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "Sôì côì ğiònh"
//	#define STRMSG_S_SCAT_COLNAME_0017 "Tên"
//	#define STRMSG_S_SCAT_COLNAME_0018 "Sôì Item"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "Lâòp"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Sôì lıõòng"
//	#define STRMSG_S_SCAT_COLNAME_0023 "ğôò bêÌn"
//	#define STRMSG_S_SCAT_COLNAME_0024 "ThõÌi gian taòo"
	#define STRMSG_S_SCAT_COLNAME_0025 "Không lãìp"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Kho chıìa"
//	#define STRMSG_S_SCAT_COLNAME_0027 "Ğâìu giá"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Map"
//	#define STRMSG_S_SCAT_COLNAME_0029 "Toòa ğôò"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Giõìi tính"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Dân tôòc"
//	#define STRMSG_S_SCAT_COLNAME_0032 "QuyêÌn haòn"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Loaòi Unit"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Level"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Level hàng ğâÌu"
//	#define STRMSG_S_SCAT_COLNAME_0036 "ChiÒ sôì kinh nghiêòm"
//	#define STRMSG_S_SCAT_COLNAME_0037 "ChiÒ sôì kinh nghiêòm biò giaÒm"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Loaòi phân bôì Stat tıò ğôòng"
//	#define STRMSG_S_SCAT_COLNAME_0039 "Công kích"
//	#define STRMSG_S_SCAT_COLNAME_0040 "PhoÌng ngıò"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Nhiên liêòu"
//	#define STRMSG_S_SCAT_COLNAME_0042 "CaÒm ıìng"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Giaìp"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Tránh"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Binh ğoàn"
//	#define STRMSG_S_SCAT_COLNAME_0046 "Tính cách"
//	#define STRMSG_S_SCAT_COLNAME_0047 "Thân phâòn"
//	#define STRMSG_S_SCAT_COLNAME_0048 "TôÒng côòng thõÌi gian kêìt nôìi"
//	#define STRMSG_S_SCAT_COLNAME_0049 "ThõÌi gian taòo"
//	#define STRMSG_S_SCAT_COLNAME_0050 "ThõÌi gian kêìt nôìi lâÌn gâÌn ğây nhâìt"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Loaòi"
//	#define STRMSG_S_SCAT_COLNAME_0052 "Toàn bôò"
	#define STRMSG_S_SCAT_COLNAME_0053 "Tıò ğôòng(Loaòi1-1)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Súng tiêÒu liên (Loaòi1-1)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Súng 2 noÌngi(Loaòi1-1)" // 2005-08-01 by hblee : lıòu ğaòn -> Loaòi súng bãìn ğôi.
	#define STRMSG_S_SCAT_COLNAME_0056 "Ğaòi pháo(Loaòi1-1)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Súng trıõÌng (Loaòi1-2)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Bêò phóng(Loaòi1-2)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Bêò phóng(Loaòi1-2)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Massdriver(Loaòi1-2)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Rôckét(Loaòi2-1)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Tên lıÒa(Loaòi2-1)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Bãìn chùm(Loaòi2-1)"
	#define STRMSG_S_SCAT_COLNAME_0064 "MiÌn(Loaòi2-1)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Shield(Loaòi2-2)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Dummy(Loaòi 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Gãìn(Loaòi2-2)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Gây nhiêŞu(Loaòi2-2)"
	#define STRMSG_S_SCAT_COLNAME_0069 "PhoÌng ngıò"
	#define STRMSG_S_SCAT_COLNAME_0070 "Thiêìt biò hôŞ trõò"
	#define STRMSG_S_SCAT_COLNAME_0071 "Nãng lıõòng"
	#define STRMSG_S_SCAT_COLNAME_0072 "Kim Loaòi"
	#define STRMSG_S_SCAT_COLNAME_0073 "TheÒ"
	#define STRMSG_S_SCAT_COLNAME_0074 "Nâng câìp"
	#define STRMSG_S_SCAT_COLNAME_0075 "Xe tãng"
	#define STRMSG_S_SCAT_COLNAME_0076 "Ğaòn"
	#define STRMSG_S_SCAT_COLNAME_0077 "Nhiêòm vuò"
	#define STRMSG_S_SCAT_COLNAME_0078 "Rağa"
	#define STRMSG_S_SCAT_COLNAME_0079 "Máy tính"
	#define STRMSG_S_SCAT_COLNAME_0080 "TheÒ ğãòc biêòt"
	#define STRMSG_S_SCAT_COLNAME_0081 "Chôìng phá huÒy khi nâng câìp"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail-gun"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "ToaÌn bôò Item"
//	#define STRMSG_S_SCAT_COLNAME_0082 "ToaÌn bôò server"
//	#define STRMSG_S_SCAT_COLNAME_0083 "Tên server"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Loaòi server"
//	#define STRMSG_S_SCAT_COLNAME_0085 "IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Sôì ngıõÌi chõi Hiêòn taòi"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Traòng thaìi server"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Group server"
//	#define STRMSG_S_SCAT_COLNAME_0089 "server haòm ğôòi"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Không xaìc ğiònh"
//	#define STRMSG_S_SCAT_COLNAME_0091 "Không thıòc hiêòn ğıõòc"
//	#define STRMSG_S_SCAT_COLNAME_0092 "BiÌnh thıõÌng"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Không biÌnh thıõÌng"
	#define STRMSG_S_SCAT_COLNAME_0094 "NgıõÌi ğiêÌu hành"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + 'cái, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Danh sách mêònh lêònh\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- Danh sách taÌi khoaÒn backup---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  taÌi khoaÒn: \'%s\', mâòt khâÒu côì ğiònh: \'%s\', mâòt khâÒu nhâìt thõÌi: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  : \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Baòn haŞy Choòn folder có phiên baÒn câòp nhâòt"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename server Group"
//	#define STRMSG_S_SCMONITOR_0007 "Viêòc taòo file ğaŞ thành công.\r\n\r\nDB Thông tin: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  kiìch hoaòt) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d –Không kiìch hoaòt) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Viêòc tái loading dıŞ liêòu cuÒa server ğaŞ thành công."
//	#define STRMSG_S_SCMONITOR_0011 "TiÌnh traòng server ğaŞ ğıõòc thêÒ hiêòn."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  Kiìch hoaòt)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d –Không kiìch hoaòt)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "Diòch vuò server miêŞn phiì ğaŞ kêìt thúc."
//	#define STRMSG_S_SCMONITOR_0017 "Diòch vuò server miêŞn phiì bãìt ğâÌu."
//	#define STRMSG_S_SCMONITOR_0018 "server haòm ğôòi chıa ğıõòc bãìt ğâÌu "
//	#define STRMSG_S_SCMONITOR_0019 "Baòn thıòc sıò muôìn ngıÌng server haòm ğôòi?"
//	#define STRMSG_S_SCMONITOR_0020 "Thông tin danh muòc phiên baÒn câòp nhâòt (tôìi ğa 1492 Bytes)\r\n\r\n    Sôì lıõòng danh muòc phiên baÒn[%3d], dung lıõòng[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "Baòn thıòc sıò muôìn ngıÌng Pre server?"
//	#define STRMSG_S_SCMONITOR_0022 "Baòn thıòc sıò muôìn ngıÌng IM server?"
//	#define STRMSG_S_SCMONITOR_0023 "Baòn thıòc sıò muôìn ngıÌng NPC server?"
//	#define STRMSG_S_SCMONITOR_0024 "%Ynãm %mtháng %dngày %HgiõÌ %Mphút %Sgiây"
//	#define STRMSG_S_SCMONITOR_0025 "Không có event(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "event tham gia open beta(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "Không biêìt event(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "ThõÌi gian lâòp cuôòc chiêìn chiêìm thaÌnh phôì "
//	#define STRMSG_S_SCMONITOR_0029 "ThõÌi gian côì ğiònh cuôòc chiêìn chiêìm thành phôì "
//	#define STRMSG_S_SCMONITOR_0030 "Binh ğoàn chiêìm liŞnh"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> Lêònh ğaŞ thành công.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> Lêònh ğaŞ thâìt baòi.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "Không kêìt nôìi ğıõòc võìi DB."
//	#define STRERR_S_SCMONITOR_0003 "Không tôÌn taòi phiên baÒn tıõng ıìng"
//	#define STRERR_S_SCMONITOR_0004 "Baòn haŞy nhâòp tên folder ğıõòc nén"
//	#define STRERR_S_SCMONITOR_0005 "Baòn haŞy nhâòp tên folder ğıõòc mõÒ"
//	#define STRERR_S_SCMONITOR_0006 "Baòn haŞy âìn nuìt bãìt ğâÌu"
//	#define STRERR_S_SCMONITOR_0007 "Baòn haŞy nhâòp phiên baÒn cuôìi "
//	#define STRERR_S_SCMONITOR_0008 "Baòn haŞy Choòn folder có file zip dùng ğêÒ câòp nhâòt"
//	#define STRERR_S_SCMONITOR_0009 "Không nôìi ğıõòc võìi file"
//	#define STRERR_S_SCMONITOR_0010 "Baòn haŞy choòn server!"
//	#define STRERR_S_SCMONITOR_0011 "Không kêìt nôìi ğıõòc võìi DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "Quaì nhiêÌu danh muòc phiên baÒn câòp nhâòt.(Sôì lıõòng[%3d], dung lıõòng[%4dBytes])\r\n\r\n    Baòn phaÒi sãìp xêìp laòi danh muòc Phiên baÒn."
//	#define STRERR_S_SCMONITOR_0014 "KyŞ nãng biò loaòi.\r\nBaòn haŞy sıÒ duòng thanh ğiêÌu chiÒnh."
//	#define STRERR_S_SCMONITOR_0015 "Ğây không phaÒi là map cuôòc chiêìn chiêìm thành phôì"
//	#define STRERR_S_SCMONITOR_0016 "Baòn không thêÒ lâòp Edit control."
//	#define STRERR_S_SCMONITOR_0017 "Baòn ğãng kyì file ğaŞ có sãŞn. "

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - Fieldserver
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to Logserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Baòn ğaŞ kêìt nôìi võìi Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "NgıÌng kêìt nôìi võìi Log Server[%15s:%4d]. Máy thıÒ kêìt nôìi laòi.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to Preserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Baòn ğaŞ kêìt nôìi Pre server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "viêòc kêìt nôìi võìi Pre server[%15s:%4d] ğaŞ biò ngıÌng. Máy thıÒ kêìt nôìi laòi.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to  IMserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Baòn ğaŞ kêìt nôìi IM server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Viêòc kêìt nôìi võìi IM server[%15s:%4d]ğaŞ biò ngıÌng. Máy thıÒ kêìt nôìi laòi.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Không tôÌn taòi Item tıõng ıìng."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' ğaŞ tõìi ğiêÒm danh nên ğıõòc nhâòn Item nhı ğaŞ hıìa "
	#define STRMSG_S_F2DBQUERY_0003 "Baòn haŞy âìn F5 ğêÒ xem kho vuŞ khí cuÒa baòn "
	#define STRMSG_S_F2DBQUERY_0004 "Skill ğaŞ tãng %s(%d) "
	#define STRMSG_S_F2DBQUERY_0005 "Không tôÌn taòi Item tıõng ıìng."
	#define STRMSG_S_F2DBQUERY_0006 "Viêòc mua Item không thành công."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  Bãìt ğâÌu cuôòc chiêìn chiêìm thaÌnh phôì : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  Binh ğoàn tham gia: GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 " Quaìi vâòt biò nôÒ taòi cuôòc chiêìn chiêìm thành phôì : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		  Sát thıõng ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  Cuôòc chiêìn chiêìm thaÌnh phôì : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) ThõÌi gian(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d? ? \"%s\" Cuôòc chiêìn chiêìm thaÌnh phôì bãìt ğâÌu."
	#define STRMSG_S_F2CITYWAR_0007 "Sau %dphuìt, \"%s\" Cuôòc chiêìn chiêìm thaÌnh phôì kêìt thúc."
	#define STRMSG_S_F2CITYWAR_0008 "Taòi cuôòc chiêìn chiêìm thaÌnh phôì(%s)quaìi vâòt ğıõòc triêòu tâòp : NPC chiêìm liŞnh"
	#define STRMSG_S_F2CITYWAR_0009 " Taòi cuôòc chiêìn chiêìm thaÌnh phôì(%s)quaìi vâòt ğıõòc triêòu tâòp: %s Binh ğoàn chiêìm liŞnh"
	#define STRMSG_S_F2CITYWAR_0010 "Hiêòn taòi \"NPC\" ğaŞ chiêìm liŞnh \"%s\" ."
	#define STRMSG_S_F2CITYWAR_0011 "Hiêòn taòi haòm ğôòi \"%s\" ğaŞ chiêìm liŞnh \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Viêòc loading quest thâìt baòi"
	#define STRMSG_S_F2QUEST_0001 "Viêòc loading quest không thành công.\r\n"
//	#define STRMSG_S_F2QUEST_0002 "quest \'%30s\' ?? %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "server dùng ğêÒ thıÒ ğaŞ setting! \r\n\r\nLoadFieldserverDataDebug() ĞêÌ nghiò loaòi! "
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1 hiÌnh"
	#define STRMSG_S_F2NOTIFY_0003 "2 hiÌnh"
	#define STRMSG_S_F2NOTIFY_0004 "mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Loaòi vuŞ khí sai! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!"
	#define STRMSG_S_F2NOTIFY_0007 "Loaòi1-1: %4.1f vs %4.1f -> xaìc suâìt công kích giaÒm %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s thâìt baòi, xaìc suâìt(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s thâìt baòi, xaìc suâìt(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s thâìt baòi, xaìc suâìt(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "loaòi1-2: %4.1f vs %4.1f -> Ğôò sát thıõng giaÒm %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s %5.2f(%5.2f-%d/255) cho (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "TıÌ%s->%s, nhâòn %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "TıÌ %s->%s(%d, HP:%5.2f), ğıa %5.2f(%5.2f-%d/255) ?(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "TıÌ%s->%s, nhâòn %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy thâìt baòi: xaìc suâìt thiêìu > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Dummy coÌn laòi[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Không có thông tin vêÌ ğaòn. Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì."
	#define STRMSG_S_F2NOTIFY_0019 "Không tôÌn taòi thông tin vêÌ cõŞ ğaòn. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Thông tin vêÌ ğaòn. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Ğang xıÒ lyì sıÒ kiêòn nên baòn không thêÒ thông qua cıÒa"
	#define STRMSG_S_F2NOTIFY_0022 "Baòn không thêÒ thông qua cıÒa viÌ ğaŞ chêìt"
	#define STRMSG_S_F2NOTIFY_0023 "Baòn không thêÒ thông qua cıÒa viÌ ğang trong trong trâòn chiêìn giıŞa các nhóm"
	#define STRMSG_S_F2NOTIFY_0024 "LôŞi vêÌ taòo map! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!"
	#define STRMSG_S_F2NOTIFY_0025 "LôŞi vêÌ taòo map! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!Không có Index muòc tiêu sôì %d taòi %d !\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Baòn không thêÒ thông qua cıÒa viÌ chıa kêìt thúc trâòn chiêìn"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d) Không thêÒ thıòc hiêòn at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "  1 -> Nhân vâòt %10s ğaŞ biò sát thıõng %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Nhân vâòt %10s ğaŞ biò sát thıõng%5.2f" 
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Nhân vâòt %10s ğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Nhân vâòt %10s ğaŞ biò sát thıõng %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "  2 -> Baòn ğaŞ biò nhân vâòt %10 sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Nhân vâòt %10s ğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Quaìi vâòt %3s ğaŞ biò sát thıõng%5.2f(%d) "
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Nhân vâòt %10sğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Nhân vâòt %10sğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> Baòn ğaŞ biò quaìi vâòt %3d sát thıõng %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "  MINE -> nhân vâòt %10s ğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "  MINE -> nhân vâòt %10sğaŞ biò sát thıõng%5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "  MINE -> quaìi vâòt %10sğaŞ biò sát thıõng %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Quay trõÒ vêÌ Stat ban ğâÌu ğaŞ thành công"
	#define STRMSG_S_F2NOTIFY_0042 "Không thêÒ sıÒ duòng khi chêìt"
	#define STRMSG_S_F2NOTIFY_0043 "Không có thông tin nâng câìp "
	#define STRMSG_S_F2NOTIFY_0044 "Nâng câìp thành công"
	#define STRMSG_S_F2NOTIFY_0045 "Nâng câìp thâìt baòi"
	#define STRMSG_S_F2NOTIFY_0046 "Baòn không thuôòc haòm ğôòi."
	#define STRMSG_S_F2NOTIFY_0047 "Baòn ğaŞ ğang õÒ traòng thaìi chõÌ."
	#define STRMSG_S_F2NOTIFY_0048 "Xin baòn vui loÌng thıÒ laòi lúc khác."
	#define STRMSG_S_F2NOTIFY_0049 "Baòn hoãòc ğôìi phıõng không phaÒi là haòm ğôòi trıõÒng."
	#define STRMSG_S_F2NOTIFY_0050 "Baòn ğang tham gia cuôòc chiêìn haòm ğôòi."
	#define STRMSG_S_F2NOTIFY_0051 "Hai haòm ğôòi trıõÒng không cùng map."
	#define STRMSG_S_F2NOTIFY_0052 "ToaÌn bôò thành viên nhóm không cùng map"
	#define STRMSG_S_F2NOTIFY_0053 "ToaÌn bôò thành viên nhóm không cùng map"
	#define STRMSG_S_F2NOTIFY_0054 "Baòn không thuôòc haòm ğôòi."
	#define STRMSG_S_F2NOTIFY_0055 "NgıõÌi ğãng kyì khaìc ngıõÌi biò ğãng kyì."
	#define STRMSG_S_F2NOTIFY_0056 "Baòn hoãòc ğôìi phıõng không phaÒi là haòm ğôòi trıõÒng."
	#define STRMSG_S_F2NOTIFY_0057 " Hai haòm ğôòi trıõÒng không cùng map"
	#define STRMSG_S_F2NOTIFY_0058 "Baòn không thuôòc haòm ğôòi."
	#define STRMSG_S_F2NOTIFY_0059 "NgıõÌi ğãng kyì khaìc ngıõÌi biò ğãng kyì."
	#define STRMSG_S_F2NOTIFY_0060 "Baòn hoãòc ğôìi phıõng không phaÒi là haòm ğôòi trıõÒng."
	#define STRMSG_S_F2NOTIFY_0061 "Thành công trong viêòc phoÌng ngıò taòi cuôòc chiêìn chiêìm thành phôì"
	#define STRMSG_S_F2NOTIFY_0062 "LôŞi vêÌ viêòc lâòp nhiêòm vuò. Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì."
	#define STRMSG_S_F2NOTIFY_0063 "Baòn không thêÒ gãìn Item(%s)vào viò trí này"
	#define STRMSG_S_F2NOTIFY_0064 "Baòn không thêÒ boÒ trôìng ğôòng cõ."
	#define STRMSG_S_F2NOTIFY_0065 "Di ğôòng Item : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Di ğôòng Item sai : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d) Không thêÒ thıòc hiêòn at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "LôŞi vêÌ thông tin map event!!! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!!!"
	#define STRMSG_S_F2NOTIFY_0069 "Không có muòc tiêu tıõng ıìng "
	#define STRMSG_S_F2NOTIFY_0070 "LôŞi vêÌ mua Item . Xin baòn vui loÌng liên hêò nhaÌ quaÒn triò."
	#define STRMSG_S_F2NOTIFY_0071 " Level skill baòn ğiònh mua bãÌng hoãòc kém hõn level cıÒa skill hiêòn có"
	#define STRMSG_S_F2NOTIFY_0072 "LôŞi vêÌ Item câÌn khi mua Skill."
	#define STRMSG_S_F2NOTIFY_0073 "LôŞi vêÌ bán Item. Xin baòn vui loÌng liên hêò nhaÌ quaÒn triò."
	#define STRMSG_S_F2NOTIFY_0074 "LôŞi vêÌ mua Item . Xin baòn vui loÌng liên hêò nhaÌ quaÒn triò."
	#define STRMSG_S_F2NOTIFY_0075 "Baòn ğaŞ mua \'Item Vcoin\' theÒ tiêÌn."
	#define STRMSG_S_F2NOTIFY_0076 "  Danh muòc các ğôÌ baòn mua : \'%s(%dcái)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Baòn ğaŞ gia nhâòp nhóm."
	#define STRMSG_S_F2NOTIFY_0078 "Baòn là nhóm trıõÒng thiÌ làm sao gia nhâòp nhóm ğıõòc nıŞa?"
	#define STRMSG_S_F2NOTIFY_0079 "cuôòc chiêìn ğâìu giıŞa các nhóm ğang tiêìn hành nên baòn không thêÒ tham gia."
	#define STRMSG_S_F2NOTIFY_0080 "Không chi viêòn viêòc hiêÒn thiò thông tin toaÌn bôò thành viên trong nhóm!"
	#define STRMSG_S_F2NOTIFY_0081 "LôŞi vêÌ thông tin map event!!! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!!!"
	#define STRMSG_S_F2NOTIFY_0082 "Ğây là taÌi khoaÒn không thêÒ giao diòch"
	#define STRMSG_S_F2NOTIFY_0083 "%sğaŞ quá taÒi."
	#define STRMSG_S_F2NOTIFY_0084 "toòa ğôò có thêÒ di ğôòng: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "NgıõÌi sıÒ duòng: "
	#define STRMSG_S_F2NOTIFY_0086 "Tôìi ğa 20 ngıõÌi có thêÒ xem."
	#define STRMSG_S_F2NOTIFY_0087 "Không có ngıõÌi sıÒ duòng(%s)tıõng ıìng"
	#define STRMSG_S_F2NOTIFY_0088 "Baòn không thuôòc nhóm"
	#define STRMSG_S_F2NOTIFY_0089 "ThõÌi gian hiêòn taòi: %d:%d, ThõÌi gian Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "ThõÌi gian biêìn ğôÒi: %d:%d, ThõÌi gian Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Viêòc kêìt nôìi võìi NPC server không thành công"
	#define STRMSG_S_F2NOTIFY_0092 "Không tôÌn taòi Item(%d)tıõng ıìng"
	#define STRMSG_S_F2NOTIFY_0093 "Giõìi haòn tôìi ğa laÌ 10 cái trong trıõÌng hõòp không phaÒi là Countable Item "
	#define STRMSG_S_F2NOTIFY_0094 "Tãng sôì ngıõÌi truy câòp map \'%s\': %dngıõÌi"
	#define STRMSG_S_F2NOTIFY_0095 "Cùng truy câòp map %s %s : %dngıõÌi - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Cùng truy câòp map %s %s : %dngıõÌi - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Kênh map hiêòn taòi: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Không có thông tin vêÌ ğaòn. Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì."
	#define STRMSG_S_F2NOTIFY_0099 "Không có thông tin vêÌ cõŞ ğaòn. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Không có thông tin vêÌ ğaòn. Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì."
	#define STRMSG_S_F2NOTIFY_0101 " Không có thông tin vêÌ cõŞ ğaòn. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Không có thông tin vêÌ ngıõÌi sıÒ duòng(%s)tıõng ıìng"
	#define STRMSG_S_F2NOTIFY_0103 "NgıõÌi sıÒ duòng tıõng ıìng(%s)ğang õÒ traòng thái chêìt"
	#define STRMSG_S_F2NOTIFY_0104 "Không có ngıõÌi sıÒ duòng(%s)tıõng ıìng"
	#define STRMSG_S_F2NOTIFY_0105 "Baòn ğaŞ ğãòt õÒ chêì ğôò taÌi khoaÒn thông thıõÌng"
	#define STRMSG_S_F2NOTIFY_0106 "GiaÒi chêì ğôò taÌi khoaÒn thông thıõÌng"
	#define STRMSG_S_F2NOTIFY_0107 "Baòn ğaŞ caÌi ğãòt unit vô ğiòch(không biò thıõng tích)"
	#define STRMSG_S_F2NOTIFY_0108 "Baòn ğaŞ giaÒi viêòc caÌi ğãòt unit vô ğiòch (không biò thıõng tích)"
	#define STRMSG_S_F2NOTIFY_0109 "VuŞ  khí ğaŞ ğıõòc tãng %5.0f%% tính hoaòt ğôòng"
	#define STRMSG_S_F2NOTIFY_0110 "TrõÒ vêÌ traòng thaìi ban ğâÌu khi lãìp ğãòt laòi Item"
	#define STRMSG_S_F2NOTIFY_0111 "TrõÒ vêÌ traòng thaìi ban ğâÌu khi lãìp ğãòt laòi Item"
	#define STRMSG_S_F2NOTIFY_0112 "Không có ngıõÌi sıÒ duòng(%s)tıõng ıìng"
	#define STRMSG_S_F2NOTIFY_0113 "KyŞ nãng âÒn ğaŞ ğıõòc giaÒi"
	#define STRMSG_S_F2NOTIFY_0114 "KyŞ nãng âÒn ğaŞ ğıõòc khõÒi ğôòng"
	#define STRMSG_S_F2NOTIFY_0115 "Không phaÒi thõÌi gian tiêìn haÌnh %s event"
	#define STRMSG_S_F2NOTIFY_0116 "Bãìt ğâÌu event%s (tyÒ lêò:%4.2f, thõÌi gian:%3dphút)"
	#define STRMSG_S_F2NOTIFY_0117 "TaÌi khoaÒn ğaŞ traÒ phiì haÌng thaìng"
	#define STRMSG_S_F2NOTIFY_0118 "LôŞi khi traÒ phiì haÌng thaìng"
	#define STRMSG_S_F2NOTIFY_0119 "Baòn ğaŞ caÌi ğãòt õÒ chêì ğôò taÌi khoaÒn super premium"
	#define STRMSG_S_F2NOTIFY_0120 "Không phaÒi map cuôòc chiêìn chiêìm thaÌnh phôì"
	#define STRMSG_S_F2NOTIFY_0121 "Baòn không thêÒ bãìt ğâÌu cuôòc chiêìn chiêìm thành phôì"
	#define STRMSG_S_F2NOTIFY_0122 "Baòn không thêÒ kêìt thúc cuôòc chiêìn chiêìm thành phôì"
	#define STRMSG_S_F2NOTIFY_0123 " ĞaŞ trõÒ vêÌ traòng thaìi âÒn ban ğâÌu "
	#define STRMSG_S_F2NOTIFY_0124 "Bãìt ğâÌu traòng thaìi âÒn"
	#define STRMSG_S_F2NOTIFY_0125 "Map không coÌn ğıõòc sıÒ duòng."
	#define STRMSG_S_F2NOTIFY_0126 "Bãìt ğâÌu thõÌi gian ‘Haònh phúc’ [thõÌi gian:%4dphút)]"
	#define STRMSG_S_F2NOTIFY_0127 "ThõÌi gian ‘Haònh phúc’ ğaŞ  kêìt thúc"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> Baòn ğaŞ biò thıõng %5.2f bõÒi quái vâòt%3d"
	#define STRMSG_S_F2NOTIFY_0129 "  Loaòi 1 -> Baòn ğaŞ biò thıõng %5.2f  bõÒi quaìi vâòt %3d (dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Baòn ğaŞ truy câòp võìi tı cách %s"
	#define STRMSG_S_F2NOTIFY_0131 "Không tiêìn haÌnh viêòc ngıÌng routine%s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "  ERROR@CharacterGameEndRoutine(): viêòc khai trıÌ thành viên trong nhóm không thành công! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' Thành công: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' Thành công: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: NgıÌng!"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR: Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì! LôŞi phân phôìi chiÒ sôì cıÒa hàng!"
	#define STRMSG_S_F2NOTIFY_0137 "%sğaŞ biò xoìa."
	#define STRMSG_S_F2NOTIFY_0138 "Hiêòn taòi kênh baòn ğang sıÒ duòng không ğıõòc kiìch hoaòt nên quaìi vâòt và các kyŞ nãng khác"
	#define STRMSG_S_F2NOTIFY_0139 "ğaŞ biò ngıÌng. Xin baòn vui loÌng sıÒ duòng kênh khác."
	#define STRMSG_S_F2NOTIFY_0140 "  Warp Obj.[%s,%2dcái]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Ğôòng tác timer %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "NgıÌng viêòc hôÌi phuòc HP tıò ğôòng"
	#define STRMSG_S_F2NOTIFY_0143 "NgıÌng viêòc hôÌi phuòc HP tıò ğôòng do ğây không phaÒi là khu vıòc có thêÒ haò cánh"
	#define STRMSG_S_F2NOTIFY_0144 "HôÌi phuòc HP 5.2f nhõÌ câìp cıìu "
	#define STRMSG_S_F2NOTIFY_0145 "DıÌng Gradual HP UP (ThõÌi gian coÌn laòi: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "DıÌng Gradual DP UP (ThõÌi gian coÌn laòi: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "DıÌng Gradual EP UP (ThõÌi gian coÌn laòi: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "Kêìt thúc sıò kiêòn %s ."
	#define STRMSG_S_F2NOTIFY_0149 "Sıò kiêòn %s ğang tiêìn haÌnh(TiÒ lêò %4.2f, ThõÌi gian coÌn laòi:%3d phút)"
	#define STRMSG_S_F2NOTIFY_0150 "Mêònh lêònh không ğıõòc thıòc hiêòn"

	
	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	LôŞi vêÌ phân phôìi chiÒ sôì kinh nghiêòm(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "  LôŞi vêÌ Game Start không tôÌn taòi ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 " LôŞi vêÌ Game Start không tôÌn taòiClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "  WARP(%04d) Không thêÒ tiêìn haÌnh at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "LôŞi thông tin map event!!! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "  EVENT(%d)Không thêÒ tiêìn haÌnh at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "LôŞi thông tin map event!!! Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "  WARP Không thêÒ tiêìn haÌnh at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "  EVENT(%d) Không thêÒ tiêìn haÌnh (TrıõÒng nhóm) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "  WARP(%04d) Không thêÒ thıòc hiêòn at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "  EVENT(%d) Không thêÒ thıòc hiêòn at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "  WARP Không thêÒ thıòc hiêòn at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "viêòc warp nhóm thâìt baòi : %s -> KhoaÒng cách: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "  WARP(%04d) Không thêÒ thıòc hiêòn at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "  %s -> Âìn OK trùng lãòp!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Quest không loading ğıõòc.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "  WARP(%s) Không thêÒ thıòc hiêòn at HandleAdminCommands(), /di chuyêÒn, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "  WARP(%s) Không thêÒ thıòc hiêòn at HandleAdminCommands(), /GıÒi, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "  FATAL ERROR: Taòi server haòm ğôòi thành viên không gia nhâòp, tin nhãìn không ğıõòc gıÒi ğêìn. check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "  WARP(%04d) Không thêÒ thıòc hiêòn at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "  WARP(%s) Không thêÒ thıòc hiêòn at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Tãng ğiêÒm kinh nghiêòm"
	#define STRMSG_S_F2EVENTTYPE_0001 "Tãng lıõòng SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Tãng khaÒ nãng hôÌi phuòc"
	#define STRMSG_S_F2EVENTTYPE_0003 "Tãng tiÒ lêò rõi ğôÌ"
	#define STRMSG_S_F2EVENTTYPE_0004 "Tãng tiÒ lêò rõi ğôÌ hiêìm"
	#define STRMSG_S_F2EVENTTYPE_0005 "Không xaìc nhâòn ğıõòc sıò kiêòn"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMserver
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Baòn ğaŞ truy câòp vào Pre server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Viêòc kêìt nôìi võìi Pre server[%15s:%4d]ğaŞ biò ngıÌng. Máy thıÒ kêìt nôìi laòi.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'là tên haòm ğôòi ğaŞ tôÌn taòi"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'ğaŞ gia nhâòp haòm ğôòi."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'là tên haòm ğôòi ğaŞ tôÌn taòi"
	#define STRMSG_S_I2NOTIFY_0003 "viêòc loading haòm ğôòi không thành công - Xin baòn vui loÌng hoÒi ngıõÌi quaÒn lyì!"
	#define STRMSG_S_I2NOTIFY_0004 "'%s'ğang truy câòp"
	#define STRMSG_S_I2NOTIFY_0005 "kiêÒm tra nhóm trıõìc"
	#define STRMSG_S_I2NOTIFY_0006 "Không tôÌn taòi nhóm hiêòn taòi"
	#define STRMSG_S_I2NOTIFY_0007 "ğãng kyì laòi nhóm  "
	#define STRMSG_S_I2NOTIFY_0008 "Baòn ğaŞ ğãng kyì nhóm."
	#define STRMSG_S_I2NOTIFY_0009 "  Fatal Error: LôŞi nghiêm troòng vêÌ nhóm! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Traòng thaìi cuÒa thành viên trong nhóm không ğúng"
	#define STRMSG_S_I2NOTIFY_0011 "Thành viên trong nhóm ğaŞ gia nhâòp haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0012 "Ğôìi tıõòng ğaŞ gia nhâòp haòm ğôòi "
	#define STRMSG_S_I2NOTIFY_0013 "Baòn không thêÒ mõÌi laòi miÌnh"
	#define STRMSG_S_I2NOTIFY_0014 "TiÌnh traòng không cho phép gia nhâòp haòm ğôòi "
	#define STRMSG_S_I2NOTIFY_0015 "Binh ğoàn ğaŞ ğuÒ ngıõÌi"
	#define STRMSG_S_I2NOTIFY_0016 "TiÌnh traòng không cho phép gia nhâòp haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0017 "Binh ğoàn trıõÒng không thêÒ rõÌi haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0018 "Ğang trong trâòn chiêìn haòm ğôòi nên baòn không thêÒ rõÌi khoÒi haòm ğôòi "
	#define STRMSG_S_I2NOTIFY_0019 "Ğang trong trâòn chiêìn haòm ğôòi nên baòn không thêÒ khai trıÌ thành viên"
	#define STRMSG_S_I2NOTIFY_0020 "Không thêÒ khai trıÌ haòm ğôòi trıõÒng"
	#define STRMSG_S_I2NOTIFY_0021 "Ğang trong trâòn chiêìn haòm ğôòi nên baòn không thêÒ giaÒi tán haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0022 "Baòn không thêÒ thay ğôÒi tên haòm ğôòi vêÌ tên cuŞ?"
	#define STRMSG_S_I2NOTIFY_0023 "Baòn không thêÒ thay ğôÒi tên haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0024 "Baòn không thêÒ thay ğôÒi dâìu hiêòu haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0025 "Baòn không thêÒ thay ğôÒi câìp ğôò"
	#define STRMSG_S_I2NOTIFY_0026 "Trùng câìp ğôò"
	#define STRMSG_S_I2NOTIFY_0027 "Baòn không thêÒ ğôÒi lên câìp haòm ğôòi trıõÒng."
	#define STRMSG_S_I2NOTIFY_0028 "Baòn không thêÒ thay ğôÒi câìp ğôò haòm ğôòi trıõÒng."
	#define STRMSG_S_I2NOTIFY_0029 "TôÒng sôì ngıõÌi sıÒ duòng: %dngıõÌi (tôìi ğa %d ngıõÌi)."
	#define STRMSG_S_I2NOTIFY_0030 "Tin nhãìn cuÒa ngıõÌi ğiêÌu hành ğaŞ ğıõòc bôÒ sung vào danh muòc."
	#define STRMSG_S_I2NOTIFY_0031 "Tin nhãìn cuÒa ngıõÌi ğiêÌu hành ğaŞ ğıõòc loaòi khoÒi danh muòc."
	#define STRMSG_S_I2NOTIFY_0032 "server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "TôÒng sôì ngıõÌi\'%s\' truy câòp server Group: %d NgıõÌi."
	#define STRMSG_S_I2NOTIFY_0034 "Baòn thıòc sıò muôìn tãìt server (%s)? Sôì: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' ğang không chõi."
	#define STRMSG_S_I2NOTIFY_0036 "TôÒng sôì ngıõÌi sıÒ duòng: %d ngıõÌi (Tôìi ğa %d ngıõÌi)"
	#define STRMSG_S_I2NOTIFY_0037 "/gıÒi ği %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Không có haòm ğôòi tıõng ıìng."
	#define STRMSG_S_I2NOTIFY_0039 "GiaÒi viêòc choòn chıìc nãng  ThiÌ thâÌm!"
	#define STRMSG_S_I2NOTIFY_0040 "Choòn chıìc nãng ThiÌ thâÌm!"
	#define STRMSG_S_I2NOTIFY_0041 "Baòn chıa gia nhâòp haòm ğôòi"
	#define STRMSG_S_I2NOTIFY_0042 "Binh ğoàn(%d)không coÌn ğıõòc sıÒ duòng"
	#define STRMSG_S_I2NOTIFY_0043 "Không tôÌn taòi thõÌi tiêìt tıõng ıìng(%s)"
	#define STRMSG_S_I2NOTIFY_0044 "Field server không hıŞu hiêòu"
	#define STRMSG_S_I2NOTIFY_0045 "Không tôÌn taòi map(%s)tıõng ıìng"
	#define STRMSG_S_I2NOTIFY_0046 "Baòn ğang trong ğiêÌu kiêòn câìm chát trong voÌng %d phút!!"
	#define STRMSG_S_I2NOTIFY_0047 "Ğãòt kyŞ nãng câìm chat: '%10s', %3d phút"
	#define STRMSG_S_I2NOTIFY_0048 "Tãìt kyŞ nãng câìm chat."
	#define STRMSG_S_I2NOTIFY_0049 "Tãìt kyŞ nãng câìm chat : '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (TaÌi khoaÒn: %s, Map: %d(%d), Level: %d) ĞANG CHÕI"
	#define STRMSG_S_I2NOTIFY_0051 "Baòn không thêÒ goòi chiình baÒn thân."
	#define STRMSG_S_I2NOTIFY_0052 "Không tôÌn taòi haòm ğôòi tıõng ıìng."

	#define STRMSG_S_IMSERVER_050607_0001	"Không tôÌn taòi map tıõng ıìng."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCserver
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Baòn ğaŞ truy câòp Field server.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Viêòc kêìt nôìi võìi Field server[%15s:%4d] ğaŞ biò ngıÌng. Máy thıÒ kêìt nôìi laòi.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							Không có sıò va chaòm võìi quaìi vâòt\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Taòi cuôòc chiêìn chiêìm thaÌnh phôì quái vâòt(%10s)ğaŞ ğıõòc triêòu hôÌi\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chol Min Ho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - Preserver
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 " %s ğaŞ truy câòp vào taÌi khoaÒn (%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Thành công"
	#define STRMSG_S_P2PRENOTIFY_0002 "Thâìt baòi"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]LôŞi khi thêm thông tin tài khoaÒn, Tên taÌi khoaÒn (%s)  IP caì nhân (%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Cao BôÌi Không Gian gıÒi lõÌi chào ğêìn các baòn."
	#define STRMSG_SCAT_051115_0002		"Cao BôÌi Không Gian seŞ tiêìn haÌnh kiêÒm tra ğiònh kyÌ tıÌ 9h ğêìn 11h trong ngày."
	#define STRMSG_SCAT_051115_0003		"Xin baòn vui loÌng di chuyêÒn ğêìn môòt nõi an toàn rôÌi ngıÌng truy câòp."
	#define STRMSG_SCAT_051115_0004		"ĞâÌu tiên NPC server seŞ tãìt."
	#define STRMSG_SCAT_051115_0005		"Cao BôÌi Không Gian bãìt ğâÌu tiêìn hành kiêÒm tra ğiònh kyÌ."
	#define STRMSG_SCAT_051115_0006		"Chúc baòn có môòt ngày vui veÒ võìi Cao BôÌi Không Gian."
	#define STRMSG_SCAT_051115_0007		"Vài phút sau server seŞ ngıÌng hoaòt ğôòng ğêÒ kiêÒm tra khâÒn câìp."
	#define STRMSG_SCAT_051115_0008		"Qúa triÌnh kiêÒm tra tiêìn haÌnh trong voÌng 120 phút."







///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Chêì ğôò âÒn: NgıõÌi chõi không thêÒ nhiÌn thâìy, không thêÒ sıÒ duòng vuŞ khiì."
	#define STRMSG_060509_0001			"Chêì ğôò bâìt tıÒ: Không bao giõÌ biò tôÒn thıõng."
	#define STRMSG_060509_0002			"Chêì ğôò taÌng hiÌnh: Quaìi vâòt seŞ không tâìn công."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"ĞêÌ nghiò cuÒa baòn ğaŞ ğıõòc gıÒi tõìi GM."
	#define	STRMSG_060526_0001			"Không thêÒ tıò ğôòng câòp nhâòt.\r\n\r\n HaŞy taÒi baÒn patch tıÌ trang chuÒ cuÒa game (%s) vaÌ truy câòp laòi.\r\n\r\n Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"TaÌi khoaÒn naÌy chıa ğıõòc ğãng kyì hoãòc nhâòp sai tên taÌi khoaÒn/mâòt khâÒu."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Hêò thôìng maìy chuÒ ğang ğıõòc ğoìng ğêÒ baÒo triÌ. HaŞy truy câòp trang chuÒ cuÒa game http://phidoi.vtc.vn ğêÒ coì thông tin chi tiêìt."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Phiên baÒn (version) caÌi ğãòt không phuÌ hõòp.\r\n  HaŞy tiêìn haÌnh caÌi ğãòt laòi hoãòc chaòy baÒn nâng câìp (patch) taÒi tıÌ trang chuÒ cuÒa game."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Baòn ğaŞ biò %s haò."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Viêòc khõÒi taòo dıŞ liêòu cho maìy chuÒ Jamboree(atum2_db_20) chiÒ ğıõòc thıòc hiêòn sau khi ğaŞ ngıÌng maìy chuÒ."
	#define STRMSG_070410_0001   	"Baòn muôìn khõÒi taòo dıŞ liêòu cho maìy chuÒ Jamboree(atum2_db_20)- [Sôì xaìc nhâòn:%d]"
	#define STRMSG_070410_0002   	"ĞaŞ khõÒi taòo thaÌnh công dıŞ liêòu cho maìy chuÒ Jamboree(atum2_db_20)."
	#define STRMSG_070410_0003   	"Thâìt baòi khi khõÒi taòo dıŞ liêòu cho maìy chuÒ Jamboree(atum2_db_20) !!"
	#define STRMSG_070410_0004   	"'%s' dıŞ liêòu ğaŞ ğıõòc copy tõìi maìy chuÒ Jamboree(atum2_db_20)."
	#define STRMSG_070410_0005   	"'%s' chuyêÒn thông tin tõìi maìy chuÒ Jamboree(atum2_db_20) thâìt baòi - Nhân vâòt không tôÌn taòi!!"
	#define STRMSG_070410_0006   	" %s' chuyêÒn thông tin tõìi maìy chuÒ Jamboree(atum2_db_20) thâìt baòi - ĞaŞ coì nhân vâòt tıõng ğıõng!!"
	#define STRMSG_070410_0007   	" %s' chuyêÒn thông tin tõìi maìy chuÒ Jamboree(atum2_db_20) thâìt baòi - LôŞi khi thêm dıŞ liêòu!!"
	#define STRMSG_070410_0008   	" %s' chuyêÒn thông tin tõìi maìy chuÒ Jamboree(atum2_db_20) thâìt baòi - Không xaìc ğiònh (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, ÇØ»óµµ ¹®ÀÚ¿­ 
	// 2007-07-24 by cmkwon, ·±Ã³¿¡¼­ 800*600 ÇØ»óµµ »èÁ¦ - ÄŞº¸¹Ú½º ½ºÆ®¸µ ÇÊ¿ä ¾øÀ½
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

// 2007-06-15 by dhjin, °üÀü °ü·Ã ½ºÆ®¸µ
	#define STRMSG_070615_0000		"Không thêÒ khõÒi ğôòng do không õÒ traòng thaìi âÒn."
	#define STRMSG_070615_0001		"Không thêÒ khõÒi ğôòng chêì ğôò quan saìt."
	#define STRMSG_070620_0000	"NgıõÌi chõi không thêÒ sıÒ duòng chıìc nãng quan saìt."

// 2007-06-26 by dhjin, ¿öÆ÷ÀÎÆ® ÀÌº¥Æ® °ü·Ã Ãß°¡
#define STRMSG_S_F2EVENTTYPE_0006		"ĞiêÒm danh voòng"

// 2007-06-28 by cmkwon, Áß±¹ ¹æ½É?ë°ü·?(°ÔÀÓ ½?°£ ¾Ë¸² ±¸Çö) - ½ºÆ®¸µ ?ß°¡
#define STRMSG_070628_0000				"Baòn ğaŞ chõi ğıõòc %d giõÌ."
#define STRMSG_070628_0001				"Baòn ğaŞ chõi ğıõòc %d giõÌ rôÌi ğâìy. HaŞy nghiÒ ngõi môòt chuìt."
#define STRMSG_070628_0002				"Baòn ğaŞ chõi quaì 3 giõÌ. TiÒ lêò ğiêÒm kinh nghiêòm, SPI, rõi ğôÌ hiêòn taòi cuÒa baòn coÌn 50%"
#define STRMSG_070628_0003				"Baòn ğaŞ chõi quaì 5 giõÌ. TiÒ lêò ğiêÒm kinh nghiêòm, SPI, rõi ğôÌ hiêòn taòi cuÒa baòn coÌn 0%."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' biò câìm truy câòp vaÌo Arena."
#define STRMSG_070711_0001 "\'%s\' biò câìm truy câòp vaÌo Arena (ThõÌi gian coÌn laòi: %d phuìt)"
#define STRMSG_070711_0002 "Baòn biò câìm truy câòp vaÌo Arena trong voÌng %d phuìt nıŞa."
#define STRMSG_070711_0003 "Baòn ğaŞ ğıõòc pheìp truy câòp vaÌo Arena."
#define STRMSG_070711_0004 "Nhân vâòt \'%s\' ğaŞ ğıõòc pheìp truy câòp vaÌo Arena."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide ÇØ»óµµ 1280x720(16:9) Ãß°¡ - ½ºÆ®¸µ Ãß°¡
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon, È¸ÀÇ·ë ½Ã½ºÅÛ ±¸Çö - ½ºÆ®¸µ Ãß°¡
#define STRMSG_070830_0001                                   "Lêònh naÌy chiÒ coì thêÒ sıÒ duòng sau khi ğaŞ choòn quôìc gia."
#define STRMSG_070830_0002                                   "PhoÌng hôòi nghiò (%d) cuÒa quôìc gia tıõng ıìng hiêòn chıa thêÒ sıÒ duòng"
#define STRMSG_070830_0003                                   "Sôì ngıõÌi ğıõòc pheìp vaÌo phoÌng hôòi nghiò : %d ngıõÌi"
#define STRMSG_070830_0004                                   "Baòn ğaŞ cho pheìp nhân vâòt '%s' vaÌo phoÌng hôòi nghiò."
#define STRMSG_070830_0005                                   "'%s' không ğıõòc pheìp vaÌo phoÌng hôòi nghiò."
#define STRMSG_070830_0006                                   "Sai tên nhân vâòt '%s'."
#define STRMSG_070830_0007                                 "Không thêÒ cho pheìp '%s' truy câòp phoÌng hôòi nghiò (Tôìi ğa %d ngıõÌi)"
#define STRMSG_070830_0008                                   "'%s' ğaŞ coì thêÒ vaÌo phoÌng hôòi nghiò."
#define STRMSG_070830_0009                                   "Baòn ğaŞ ğıõòc pheìp truy câòp phoÌng hôòi nghiò."
#define STRMSG_070830_0010                                   "Baòn không ğıõòc pheìp truy câòp phoÌng hôòi nghiò."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s gıÒi tãòng baòn %s."
#define STRMSG_071115_0002									"Danh saìch quaÌ tãòng : \'%s(%d caìi)\'"
#define STRMSG_071115_0003									"\\y%s ğaŞ tãòng quaÌ cho %s.  Moìn quaÌ laÌ  %s. Vui loÌng kiêÒm tra trong kho chıìa ğôÌ."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Không thêÒ sıÒ duòng lêònh naÌy trong thõÌi ğiêÒm hiêòn taòi. Vui loÌng liên laòc trung tâm chãm soìc khaìch haÌng."
#define STRMSG_071120_0002									"ĞaŞ kiìch hoaòt lêònh CallGM."
#define STRMSG_071120_0003									"ĞaŞ ngıÌng viêòc sıÒ duòng lêònh CallGM."
#define STRMSG_071120_0004									"Lêònh CallGM coì thêÒ sıÒ duòng tıÌ %s ğêìn %s."

// 2007-11-28 by cmkwon, ÅëÁö½?½ºÅÛ ±¸Çö - 
#define STRMSG_071128_0001									"%s ğaŞ gıÒi tãòng baòn %s(%d). HaŞy kiêÒm tra taòi kho chıìa ğôÌ."

// 2007-12-27 by cmkwon, À©µµ¿?Áî ¸?µå ±â´É ?ß°¡ - 
#define STRMSG_071228_0001				"Ğôò phân giaÒi maÌn hiÌnh không phuÌ hõòp. HaŞy kiêÒm tra laòi."

// 2008-01-31 by cmkwon, °èÁ¤ ºí·°/ÇØÁ¦ ¸í·É¾î·Î °¡´ÉÇÑ ½?½ºÅÛ ±¸Çö - 
#define STRMSG_080201_0001									"'Error exists in %s' block setting. ErrorCode(%d)"
#define STRMSG_080201_0002									"TaÌi khoaÒn '%s' ğaŞ biò khoìa. [NgaÌy hêìt haòn: %s]"
#define STRMSG_080201_0003									"Không tôÌn taòi taÌi khoaÒn '%s' trong danh saìch nhıŞng taÌi khoaÒn biò khoìa. ErrorCode(%d)"
#define STRMSG_080201_0004									"LôŞi phaÒi sinh trong khi khoìa taÌi khoaÒn '%s'. ErrorCode(%d)"
#define STRMSG_080201_0005									"ĞaŞ xoìa taÌi khoaÒn '%s' trong danh saìch nhıŞng taÌi khoaÒn biò khoìa." 

// 2008-02-11 by cmkwon, ÇØ»óµµ Ãß°¡(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin, ¾Æ·¹³ªÅëÇÕ- ¾Æ·¹³ª¼­¹ö¿¬°á°ü·Ã¿À·ù
#define STRMSG_S_MF2AFCONNECT_0000                       "[LôŞi] WndProc(), Không thêÒ kêìt nôìi tõìi maìy chuÒ Arena[%15s:%4d] HaŞy thıÒ laòi\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "ĞaŞ kêìt nôìi tõìi maìy chuÒ Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Kêìt nôìi tõìi maìy chuÒ Arena[%15s:%4d] biò giaìn ğoaòn. Ğang kêìt nôìi laòi.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "PhoÌng sôì \\y%d ğaŞ ğıõòc chuyêÒn tıÌ phoÌng thıõÌng thaÌnh phoÌng sıò kiêòn.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "PhoÌng sôì \\y%d ğaŞ ğıõòc chuyêÒn tıÌ phoÌng sıò kiêòn trõÌ vêÌ phoÌng thıõÌng.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Không thêÒ thiêìt lâòp cho Arena.\r\n"
#define STRMSG_080428_0001					"%s ğaŞ biò bãìn haò."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º Á¤º¸ DB¿¡ Ãß°¡(½Å±Ô °èÁ¤ Ä³¸¯ÅÍ »ı¼º Á¦ÇÑ ½Ã½ºÅÛÃß°¡) - 
#define STRMSG_080430_0001					"Không thêÒ taòo nhân vâòt mõìi trên maìy chuÒ hiêòn taòi."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼öÁ¤ »çÇ× - 
#define STRMSG_080613_0001					"Haòm ğôòi %s ğaŞ tıÌ chôìi ğõn gia nhâòp."

// 2008-09-04 by cmkwon, don't need translation, ¼­¹ö¿ë SystemLog ÀÌ¹Ç·Î ¹ø¿ª ÇÊ¿ä ¾øÀ½
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ Ã¤ÆÃ Á¦ÇÑ Ä«µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s seŞ biò câìm chat trong %d phuìt.\\y"
#define STRMSG_081230_0002					"\\yThuÒ liŞnh ğaŞ kiìch hoaòt ngıng sıÒ duòng hêò thôìng chat trong %d phuìt.\\y"
#define STRMSG_081230_0003					"\\yThuÒ liŞnh ğaŞ cho pheìp sıÒ duòng hêò thôìng chat.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °ÔÀÓ°¡µå µ¿ÀÇÃ¢ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇÃ¢ WebPage·Î Ã³¸® - »ç¿ëÇÏÁö ¾ÊÀ½, STRMSG_090831_0001´Â À¥ÆäÀÌÁö·Î Ã³¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0002					"Install nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇÃ¢ WebPage·Î Ã³¸® - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø ÇØ»óµµ Ãß°¡(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ÀÎÁ? ¼­¹öÀÇ Á¢¼Ó Ç?¿ë »óÈ²
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Not Registered Server (It can be Illegal Private Server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"LôŞi xuâìt hiêòn trong khi kêìt nôìi tõìi DB"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Authentication succeed"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Registered Server IP But proceed Authentication Denied"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows Shut Down command is sent to the server."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 Æ®¸®°Å ½Ã½ºÅÛ ÀÌº¥Æ® ¾Ë¸²

// 1Â÷ ÀÌº¥Æ®

#define STRMSG_120330_0001					"%s Kiìch hoaòt côÒng diòch chuyêÒn biì mâòt taòi Ashlane."
#define STRMSG_120330_0002					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 100%%%% kinh nghiêòm trong 1h taòi Ashlane."
#define STRMSG_120330_0003					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 100%%%% tyÒ lêò rõi ğôÌ trong 1h taòi Ashlane."
#define STRMSG_120330_0004					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 100%%%% tyÒ lêò rõi ğôÌ/ SPI/ ğiêÒm kinh nghiêòm trong 1h taòi Ashlane."
#define STRMSG_120330_0005					"%s Kiìch hoaòt cıÒa haÌng vuŞ khiì taòi Ashlane."
#define STRMSG_120330_0006					"%s Kiìch hoaòt cuÒa haÌng theÒ ğãòc biêòt taòi Ashlane."
#define STRMSG_120330_0007					"%s Kiìch hoaòt cıÒa haÌng thiêìt biò taòi Ashlane."
#define STRMSG_120330_0008					"%s Quaìi vâòt khôÒng lôÌ ğaŞ ğıõòc triêÌu hôÌi taòi Ashlane."
#define STRMSG_120330_0009					"Crystal ğaŞ biêìn mâìt."

// 2Â÷ ÀÌº¥Æ®

#define STRMSG_120508_0001					"%s Thu ğıõòc ğiêÒm danh voòng nhiêÌu nhı %d WP taòi Lost Oasis."
#define STRMSG_120508_0002					"%s Siêu boss ğaŞ xuâìt hiêòn taòi Lost Oasis."
#define STRMSG_120508_0003					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 150%%%% kinh nghiêòm trong 1h Lost Oasis."
#define STRMSG_120508_0004					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 150%%%% tyÒ lêò rõi ğôÌ trong 1h taòi Lost Oasis."
#define STRMSG_120508_0005					"%s Kiìch hoaòt giõÌ vaÌng gia tãng 150%%%% tyÒ lêò rõi ğôÌ/ kinh nghiêòm/ SPI/ trong 1h taòi Lost Oasis."
#define STRMSG_120508_0006					"%s Thu ğıõòc Ancient Ice taòi Lost Oasis."
#define STRMSG_120508_0007					"%s Kiìch hoaòt cıÒa haÌng vuŞ khiì cao câìp taòi Lost Oasis."
#define STRMSG_120508_0008					"%s Kiìch hoaòt cıÒa haÌng thiêìt biò taòi Lost Oasis."
#define STRMSG_120508_0009					"%s Kiìch hoaòt cıÒa haÌng theÒ ğãòc biêòt taòi Lost Oasis."
#define STRMSG_120508_0010					"%s Kiìch hoaòt cıÒa haÌng vuŞ khiì taòi Lost Oasis."
#define STRMSG_120508_0011					"%s Kiìch hoaòt côÒng diòch chuyêÒn biì mâòt taòi Lost Oasis."

#define STRMSG_120712_0001					"18¼¼ ¹Ì¸¸ Ã»¼Ò³â¿¡°Ô Àû¿ëµÇ´Â °ÔÀÓ½Ã°£ ¼±ÅÃÁ¦ ¼³Á¤À¸·Î ÀÎÇÏ¿©, %d ºĞ ÈÄ¿¡ °ÔÀÓÀÌ Á¾·áµË´Ï´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼Ë´Ù¿î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ğµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸ÍÁ¡ ½Ã°£ÀÌ %dºĞ ³²¾Ò½À´Ï´Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÁ¡ÀÌ Á¾·áµË´Ï´Ù."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½Ã½ºÅÛ ¸®´º¾ó - ÀüÀï½Ã Æ®¸®°Å ¹«Àû»óÅÂ(ÀÏ½ÃÁ¤Áö)
#define STRMSG_121126_0001					"\\yLêònh: Bãìt ğâÌu tıÌ thõÌi ğiêÒm coì caìc trâòn ğaình giıŞa 02 quôìc gia, ngıõÌi chõi ngay lâòp tıìc seŞ không thıòc hiêòn ğıõòc caìc hoaòt ğôòng liên quan ğêìn pha lê\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OXÀÌº¥Æ® ¸Ê ¿öÇÁÁ¦ÇÑ
#define STRMSG_121129_0001					"\\y¿î¿µÀÚ¿¡ ÀÇÇÏ¿© ÀÌµ¿ÀÌ Á¦ÇÑµÈ Áö¿ª ÀÔ´Ï´Ù.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ???? ??? ???
#define STRMSG_130121_0001					"\\cHêò thôìng ğaŞ biò chiêìm giıŞ bõÒi lıòc lıõòng NGC. Viêòc sõ taìn seŞ ğıõòc thıòc hiêòn ngay lâòp tıìc."
#define STRMSG_130121_0002					"\\cDo thaìm:\\c \\rNGC Controller\\r ğaŞ xaìc nhâòn."
#define STRMSG_130121_0003					"\\cDo thaìm:\\c \\rNGC Controller\\r ğaŞ biò phaì huÒy."
#define STRMSG_130121_0004					"\\cChiÒ huy:\\c \\rGomora's\\r Giaìp nãng lıõòng ğaŞ kiìch hoaòt. Tiêu diêòt \\rNGC Controllers\\r ğêÒ vô hiêòu hoìa noì!"
#define STRMSG_130121_0005					"\\cChiÒ huy:\\c \\rGomora's\\r Giaìp nãng lıõòng ğaŞ mâìt! Tâìn công ngay!"
#define STRMSG_130121_0006					"\\cChiÒ huy:\\c \\rGomora\\r ğaŞ biò phaì huÒy! Tâìt caÒ tiêìn lên!"
#define STRMSG_130121_0007					"\\cChiÒ huy:\\c \\rGomora\\r phaÒi biò tiêu diêòt ğâÌu tiên."
#define STRMSG_130121_0008					"\\c[%s] kiìch hoaòt bõÒi \\c\\rNGC Controller\\r quaì taÒi."
#define STRMSG_130121_0009					"\\y[Hêò thôìng cãn cıì tiêÌn ğôÌn NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ??? ??? - ???? ???? ??? ??
#define STRMSG_130422_0001					"\\y%s %d biò giõìi haòn tıÌ Ğâìu TrıõÌng. Vâòt phâÒm ğaŞ ğıõòc gıÒi laòi vaÌo kho cuÒa baòn.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ?? ??? - STRMSG ??
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gTheÒ chuyêÒn daòng giaìp ğaŞ ğıõòc thêm vaÌo Bôò sıu tâòp theÒ chuyêÒn daòng giaìp cuÒa baòn.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gTheÒ chuyêÒn daòng giaìp ğaŞ ğıõòc kiìch hoaòt [%2d] lâÌn.\\g"
#define STRMSG_130531_0003					"\\g[\\g%s\\g]\\g \\gTheÒ chuyêÒn daòng giaìp ğaŞ ğaòt giõìi haòn sıÒ duòng tôìi ğa. Noì seŞ chuyêÒn thaÌnh [%s].\\g"
#define STRMSG_130531_0004					"TheÒ chuyêÒn daòng giaìp cuÒa baòn ğaŞ hêìt haòn vaÌ caìc chiÒ sôì seŞ biò loaòi boÒ. Ğôòng cõ seŞ biò thaìo ra."
#define STRMSG_130531_0005					"\\yKhông coì ğôòng cõ ğıõòc sıÒ duòng. Diòch chuyêÒn tıìc thõÌi vêÌ thaÌnh phôì.\\y"
#define STRMSG_130531_0006					"\\gBaòn không thêÒ sıÒ duòng theÒ chuyêÒn daòng giaìp ğang ğıõòc kiìch hoaòt.\\g"
#define STRMSG_130531_0007					"\\gTheÒ chuyêÒn daòng giaìp ğaŞ biò thay ğôÒi.\\g"
#define STRMSG_130531_0008					"\\r[%s] TheÒ chuyêÒn daòng giaìp ğaŞ hêìt haòn.\\r"
#define STRMSG_130531_0009					"\\yGiaìp võìi theÒ chuyêÒn daòng giaìp ğaŞ kiìch hoaòt không thêÒ baìn.\\y"
#define STRMSG_130531_0010					"\\yLoaòi phi cõ không phuÌ hõòp.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ??? ??? ?? - STRMSG ??
#define STRMSG_130708_0001					"\\cChiÒ huy:\\c Giaìp nãng lıõòng NGC ğaŞ ğıõòc kiìch hoaòt. Tiêu diêòt \\rNGC Controllers\\r ğêÒ vô hiêòu hoìa giaìp nãng lıõòng cuÒa \\rGomora\\r !"
#define STRMSG_130708_0002					"\\cChiÒ huy:\\c Cãn cıì phoÌng ngıò quân sıò NGC ğaŞ biò haò. Bãìt ğâÌu tâìn công!"
#define STRMSG_130708_0003					"\\cDo thaìm:\\c \\rNGC Shield Generator\\r ğaŞ trong tâÌm ngãìm."
#define STRMSG_130708_0004					"\\cDo thaìm:\\c \\rNGC Shield Generator\\r ğaŞ biò tiêu diêòt."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, ? ?? ????
#define STRMSG_130726_0001					"Nhân vâòt ğaŞ õÒ trong quôìc gia."
#define STRMSG_130726_0002					"Nhân vâòt laÌ TôÒng thôìng hoãòc phoì TôÒng thôìng, viÌ vâòy không thêÒ chuyêÒn quôìc gia."
#define STRMSG_130726_0003					"Nhân vâòt õÒ trong haòm ğôòi, quôìc gia không thêÒ biò thay ğôÒi."
#define STRMSG_130726_0004					"Không coì nhân vâòt naÌo rõÌi khoÒi ğêÒ chuyêÒn quôìc gia."
#define STRMSG_130726_0005					"ChuyêÒn quôìc gia thâìt baòi [AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"ChuyêÒn quôìc gia thaÌnh công [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"TaÌi khoaÒn không tôÌn taòi."
#define STRMSG_130726_0008					"TaÌi khoaÒn ğaŞ ğãng nhâòp, không thêÒ chuyêÒn quôìc gia."


// 2013-08-30 by bckim, ?????????
#define STRMSG_130830_0001					"\\y%s Biò câìm bay viÌ ğãòc quyêÌn cuÒa laŞnh ğaòo quôìc gia.\\y"
#define STRMSG_130830_0002					"\\yBiò câìm bay viÌ ğãòc quyêÌn cuÒa laŞnh ğaòo quôìc gia.\\y"
#define STRMSG_130830_0003					"\\y%s Biò câìm bay viÌ ğãòc quyêÌn cuÒa laŞnh ğaòo quôìc gia.\\y"
// End. 2013-08-30 by bckim, ?????????

// 2013-08-28 by bckim, ????? ????
#define STRMSG_130828_0001					"\\y[%s ğaŞ goìp phâÌn trong viêòc phaì huÒy \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s ğaŞ khõÒi xıõìng lâÌn tâìn công ğâÌu tiên chôìng laòi \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s ğaŞ thıòc hiêòn caìc cuôòc tâìn công tôÒng lıòc chôìng laòi \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s ğaŞ thıòc hiêòn ğõòt tâìn công cuôìi cuÌng võìi \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n ğaŞ biò ğaình baòi."
// End. 2013-08-28 by bckim, ????? ????

// 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???
#define STRMSG_130814_0001					"\\y[%s] ğaŞ chiêìn thãìng cuôòc chiêìn taòi cıì ğiêÒm chiêìn lıõòc NGC.\\y"
// end 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
