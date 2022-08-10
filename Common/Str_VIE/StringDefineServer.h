
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Ma�y chu� kh�ng hoa�t ���ng"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre server!"
	#define STRERR_S_ATUMEXE_0003 "Vi��c c��p nh��t t�� ���ng kh�ng th�nh c�ng.\r\nBa�n ha�y ca�i ���t la�i tro� ch�i.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "L��i kh�ng xa�c �i�nh: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Kh�ng k��t n��i ����c Server download"
	#define STRERR_S_ATUMEXE_0007 "Kh�ng nh��n bi��t ����c dung l���ng file ta�i v��."
	#define STRERR_S_ATUMEXE_0008 "Kh�ng ta�i ����c file �a� c��p nh��t ."
	#define STRERR_S_ATUMEXE_0009 "H�� th��ng thi��u b�� nh�� ho��c ta�i nguy�n."
	#define STRERR_S_ATUMEXE_0010 "L��i file cha�y."
	#define STRERR_S_ATUMEXE_0011 "Kh�ng ti�m ����c file."
	#define STRERR_S_ATUMEXE_0012 "Kh�ng ti�m th��y ����ng d��n chi� �i�nh."
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
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	
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
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �̸� û�ҳ⿡�� ����Ǵ� ���ӽð� ������ �������� ���Ͽ�, ���� �ð����� ���� ������ �Ұ����մϴ�.\n\n�ڼ��� ������ ���̽��¶��� �����ͷ� ���ǹٶ��ϴ�."		// 2012-07-11 by hskim, ������ �˴ٿ�



	#define STRMSG_S_050506		"Tai khoan \'%s\' dang bi khoa.\n  Ly do: %s\n  Thoi gian: %s~%s\n\nThong tin chi tiet vui long lien he qua email: support.phidoi@vtc.vn."
	#define STRMSG_S_050930		"Ban hay tai lai tro choi.\nURL: %s\n phien ban moi nhat."
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Nam"
//	#define STRMSG_S_SCADMINTOOL_0001 "N��"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d N�m, %d Tu��i"
//	#define STRMSG_S_SCADMINTOOL_0003 "Ba�n th��c s�� mu��n s��a ta�i khoa�n?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'C�i'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'nh��n c�i, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'c�i'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''' + l.PeerCharacterName + '''?? ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'c�i cho, ' + CAST(l.CurrentCount AS VARCHAR(10)) + �c�i'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''' + l.PeerCharacterName + '''from ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i �a� nh��n, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'c�i'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10)) + 'c�i bo�, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'c�i'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'c�i mua, co�n la�i Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'c�i b�n, co�n la�i Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'c�i'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' �a� th�m ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i, t��ng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'ca�i'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' xoa� ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i, t��ng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'ca�i'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Th�m ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'ca�i'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Xoa� ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i, t��ng ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'ca�i'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Recover ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'ca�i, t��ng' + CAST(l.CurrentCount AS VARCHAR(10)) + 'ca�i'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'th��i gian ch�i \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', toa�n b�� \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', th��i gian ch�i: ' + dbo.atum_GetHMSFromS(l.Param3)"	
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' t�ng gia�m, t�ng \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "��m"
//	#define STRMSG_S_SCADMINTOOL_0021 "qua�i v��t"
//	#define STRMSG_S_SCADMINTOOL_0022 "phi c�"
//	#define STRMSG_S_SCADMINTOOL_0023 "Nguy�n nh�n kh�ng xa�c �i�nh"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Stat co�n la�i: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Kh�ng c�)"
//	#define STRMSG_S_SCADMINTOOL_0026 "ba�n th�n"
//	#define STRMSG_S_SCADMINTOOL_0027 "Kh�ng c�"
//	#define STRMSG_S_SCADMINTOOL_0028 "Ng���i s�� du�ng bug"
	#define STRMSG_S_SCADMINTOOL_0029 "ta�i khoa�n block"
	#define STRMSG_S_SCADMINTOOL_0030 "C��m chat"
//	#define STRMSG_S_SCADMINTOOL_0031 "Log truy c��p"
//	#define STRMSG_S_SCADMINTOOL_0032 "Log ng���i ch�i"
//	#define STRMSG_S_SCADMINTOOL_0033 "Log Item "
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s server"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s server,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 " Kh�a nick"
//	#define STRMSG_S_SCADMINTOOL_0037 "Ph�n loa�i"
//	#define STRMSG_S_SCADMINTOOL_0038 "��n vi�"
	#define STRMSG_S_SCADMINTOOL_0039 "Ba�n c� mu��n m�� ta�i khoa�n bi� kho�?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d gi�y)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d th��ng %d ba�i"
	#define STRMSG_S_SCADMINTOOL_0042 "Ba�n th��c s�� mu��n ng��ng k��t n��i v� ch��n?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s Item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] th�ng b�o : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "S�� ng���i s�� du�ng: %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] tin nh��n ����c nh��n : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] S�� ng���i ch�i : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] Field server state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Ng��ng k��t n��i server\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Kh�ng �o�c ����c th�ng tin v�� t�i khoa�n."
	#define STRERR_S_SCADMINTOOL_0001 "Vi��c s��a ta�i khoa�n kh�ng th�nh c�ng."
	#define STRERR_S_SCADMINTOOL_0002 "Ba�n ha�y �i��n m��t kh��u"
	#define STRERR_S_SCADMINTOOL_0003 "Sai m��t kh��u"
	#define STRERR_S_SCADMINTOOL_0004 "Ba�n ha�y �i��n ID"
	#define STRERR_S_SCADMINTOOL_0005 "Pre server kh�ng hoa�t ���ng."
	#define STRERR_S_SCADMINTOOL_0006 "Kh�ng th�� truy c��p ���n Preserver !!"
	#define STRERR_S_SCADMINTOOL_0007 "vi��c x�c nh��n kh�ng th�nh c�ng"
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: Kh�ng t��n ta�i Protocol t��ng th�ch."
	#define STRERR_S_SCADMINTOOL_0009 "Ba�n ha�y �i��n t�n ng���i s�� du�ng"
	#define STRERR_S_SCADMINTOOL_0010 "Ba�n ha�y �i��n ly� do"
	#define STRERR_S_SCADMINTOOL_0011 "L��i v�� vi��c l��p chi� s�� kinh nghi��m : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "S�� l���ng log �a� qu� ta�i.\r\n\r\nXin ba�n vui lo�ng s��a la�i s�� log ho��c �i��u ki��n ti�m."
	#define STRERR_S_SCADMINTOOL_0013 "Kh�ng truy c��p ����c c� s�� d�� li��u."
	#define STRERR_S_SCADMINTOOL_0014 "Kh�ng truy c��p ����c"
	#define STRERR_S_SCADMINTOOL_0015 "Truy c��p"
	#define STRERR_S_SCADMINTOOL_0016 "�ang n�ng c��p"
	#define STRERR_S_SCADMINTOOL_0017 "��ng nh��p"
	#define STRERR_S_SCADMINTOOL_0018 "�ang l��a cho�n nh�n v��t "
	#define STRERR_S_SCADMINTOOL_0019 "�ang ch�i"
	#define STRERR_S_SCADMINTOOL_0020 "Kh�ng xa�c �i�nh"
	#define STRERR_S_SCADMINTOOL_0021 "Kh�ng truy c��p ����c c� s�� d�� li��u %s(%s:%d)."
	#define STRERR_S_SCADMINTOOL_0022 "Vi��c t�ng th�m Item kh�ng th�nh c�ng"
	#define STRERR_S_SCADMINTOOL_0023 "Vi��c ti�m nick bi� kh�a kh�ng th�nh c�ng."
	#define STRERR_S_SCADMINTOOL_0024 "��� s��a, Ba�n ha�y ng��ng vi��c k��t n��i ta�i khoa�n v� kh�a ta�i khoa�n!"
	#define STRERR_S_SCADMINTOOL_0025 "Ba�n kh�ng th�� t�ng th�m SPI(Ti��n)."
	#define STRERR_S_SCADMINTOOL_0026 "Item ba�n cho�n �a� c�, Ba�n ha�y s��a la�i s�� l���ng"
	#define STRERR_S_SCADMINTOOL_0027 "L��i v�� ti�m Item"
	#define STRERR_S_SCADMINTOOL_0028 "Ba�n kh�ng th�� x�a SPI(Ti��n) m� nh�n v��t s�� h��u."
	#define STRERR_S_SCADMINTOOL_0029 "Ba�n mu��n x�a Item?"
	#define STRERR_S_SCADMINTOOL_0030 "vi��c x�a Item kh�ng th�nh c�ng."
	#define STRERR_S_SCADMINTOOL_0031 "vi��c s��a Item kh�ng th�nh c�ng."
	#define STRERR_S_SCADMINTOOL_0032 "Ba�n ha�y �i��n ta�i khoa�n"
	#define STRERR_S_SCADMINTOOL_0033 "ta�i khoa�n n�y kh�ng t��n ta�i.( C� th�� c�i block ta�i khoa�n)"
	#define STRERR_S_SCADMINTOOL_0034 "Kh�ng t��n ta�i ta�i khoa�n ho��c nh�n v��t."
	#define STRERR_S_SCADMINTOOL_0035 "L��i xem th�ng tin nh�n v��t."
	#define STRERR_S_SCADMINTOOL_0036 "Kh�ng t��n ta�i nh�n v��t t��ng ��ng"
	#define STRERR_S_SCADMINTOOL_0037 "L��i n�ng c��p nh�n v��t"
	#define STRERR_S_SCADMINTOOL_0038 "Vi��c c��p nh��t th�ng tin nh�n v��t �a� th�nh c�ng "
	#define STRERR_S_SCADMINTOOL_0039 "Ba�n ha�y cho�n Item."
	#define STRERR_S_SCADMINTOOL_0040 "Ba�n ha�y cho�n s�� l���ng Item."
	#define STRERR_S_SCADMINTOOL_0041 "Ba�n chi� ����c ta�o d���i 5c�i."
	#define STRERR_S_SCADMINTOOL_0042 "Ba�n ha�y nh��p tin nh��n."
	#define STRERR_S_SCADMINTOOL_0043 "Kh�ng th�� truy��n th�ng tin."
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM server kh�ng hoa�t ���ng."
	#define STRERR_S_SCADMINTOOL_0046 "Field server kh�ng hoa�t ���ng."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMserver state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ��Ʈ�� - ���� �� ��Ʈ�� ��ɿ��� ���Ǵ� MSG
#define STRERR_S_SCADMINTOOL_0048 "Kh�ng th�� tha�o ky� n�ng khi �a� trang bi� cho Partner."
#define STRERR_S_SCADMINTOOL_0049 "�ang l�u log v�� l��i trong qua� tri�nh thay ���i Partner.\r\n(Chi� l�u nh��ng log v�� l��i)"
#define STRERR_S_SCADMINTOOL_0050 "Vi��c ta�i th�ng tin v�� Partner bi� l��i."
#define STRERR_S_SCADMINTOOL_0051 "Ky� n�ng ����c trang bi� l��i �a� bi� xo�a."
#define STRERR_S_SCADMINTOOL_0052 "The applying hidden option for equipped item is failed."
#define STRERR_S_SCADMINTOOL_0053 "The revision for the Partner��s socket item is failed."
#define STRERR_S_SCADMINTOOL_0054 "L��i c��p nh��t th�ng tin cu�a Partner."
#define STRERR_S_SCADMINTOOL_0055 "L��i ta�i th�ng tin v�� c��p ��� cu�a Partner."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, �������߰�, ��æƮ���������ű��
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, �������߰�, ��æƮ���������ű��. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "T�n ta�i khoa�n"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Loa�i"
//	#define STRMSG_S_SCAT_COLNAME_0002 "Toa�n b��"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Vi��c b��t ���u"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Vi��c k��t th�c"
//	#define STRMSG_S_SCAT_COLNAME_0005 "Ng���i gia�i quy��t"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Ly� do"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Ng�y"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Loa�i log"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IP Address"
//	#define STRMSG_S_SCAT_COLNAME_0010 "T�n server"
//	#define STRMSG_S_SCAT_COLNAME_0011 "T�n nh�n v��t"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Vi� tr�"
//	#define STRMSG_S_SCAT_COLNAME_0013 "N��i dung"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Item"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "S�� c�� �i�nh"
//	#define STRMSG_S_SCAT_COLNAME_0017 "T�n"
//	#define STRMSG_S_SCAT_COLNAME_0018 "S�� Item"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "L��p"
//	#define STRMSG_S_SCAT_COLNAME_0022 "S�� l���ng"
//	#define STRMSG_S_SCAT_COLNAME_0023 "��� b��n"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Th��i gian ta�o"
	#define STRMSG_S_SCAT_COLNAME_0025 "Kh�ng l��p"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Kho ch��a"
//	#define STRMSG_S_SCAT_COLNAME_0027 "���u gi�"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Map"
//	#define STRMSG_S_SCAT_COLNAME_0029 "To�a ���"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Gi��i t�nh"
//	#define STRMSG_S_SCAT_COLNAME_0031 "D�n t��c"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Quy��n ha�n"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Loa�i Unit"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Level"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Level h�ng ���u"
//	#define STRMSG_S_SCAT_COLNAME_0036 "Chi� s�� kinh nghi��m"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Chi� s�� kinh nghi��m bi� gia�m"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Loa�i ph�n b�� Stat t�� ���ng"
//	#define STRMSG_S_SCAT_COLNAME_0039 "C�ng k�ch"
//	#define STRMSG_S_SCAT_COLNAME_0040 "Pho�ng ng��"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Nhi�n li��u"
//	#define STRMSG_S_SCAT_COLNAME_0042 "Ca�m ��ng"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Gia�p"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Tr�nh"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Binh �o�n"
//	#define STRMSG_S_SCAT_COLNAME_0046 "T�nh c�ch"
//	#define STRMSG_S_SCAT_COLNAME_0047 "Th�n ph��n"
//	#define STRMSG_S_SCAT_COLNAME_0048 "T��ng c��ng th��i gian k��t n��i"
//	#define STRMSG_S_SCAT_COLNAME_0049 "Th��i gian ta�o"
//	#define STRMSG_S_SCAT_COLNAME_0050 "Th��i gian k��t n��i l��n g��n ��y nh��t"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Loa�i"
//	#define STRMSG_S_SCAT_COLNAME_0052 "To�n b��"
	#define STRMSG_S_SCAT_COLNAME_0053 "T�� ���ng(Loa�i1-1)"
	#define STRMSG_S_SCAT_COLNAME_0054 "S�ng ti��u li�n (Loa�i1-1)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "S�ng 2 no�ngi(Loa�i1-1)" // 2005-08-01 by hblee : l��u �a�n -> Loa�i s�ng b��n ��i.
	#define STRMSG_S_SCAT_COLNAME_0056 "�a�i ph�o(Loa�i1-1)"
	#define STRMSG_S_SCAT_COLNAME_0057 "S�ng tr���ng (Loa�i1-2)"
	#define STRMSG_S_SCAT_COLNAME_0058 "B�� ph�ng(Loa�i1-2)"
	#define STRMSG_S_SCAT_COLNAME_0059 "B�� ph�ng(Loa�i1-2)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Massdriver(Loa�i1-2)"
	#define STRMSG_S_SCAT_COLNAME_0061 "R�ck�t(Loa�i2-1)"
	#define STRMSG_S_SCAT_COLNAME_0062 "T�n l��a(Loa�i2-1)"
	#define STRMSG_S_SCAT_COLNAME_0063 "B��n ch�m(Loa�i2-1)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Mi�n(Loa�i2-1)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Shield(Loa�i2-2)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Dummy(Loa�i 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0067 "G��n(Loa�i2-2)"
	#define STRMSG_S_SCAT_COLNAME_0068 "G�y nhi��u(Loa�i2-2)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Pho�ng ng��"
	#define STRMSG_S_SCAT_COLNAME_0070 "Thi��t bi� h�� tr��"
	#define STRMSG_S_SCAT_COLNAME_0071 "N�ng l���ng"
	#define STRMSG_S_SCAT_COLNAME_0072 "Kim Loa�i"
	#define STRMSG_S_SCAT_COLNAME_0073 "The�"
	#define STRMSG_S_SCAT_COLNAME_0074 "N�ng c��p"
	#define STRMSG_S_SCAT_COLNAME_0075 "Xe t�ng"
	#define STRMSG_S_SCAT_COLNAME_0076 "�a�n"
	#define STRMSG_S_SCAT_COLNAME_0077 "Nhi��m vu�"
	#define STRMSG_S_SCAT_COLNAME_0078 "Ra�a"
	#define STRMSG_S_SCAT_COLNAME_0079 "M�y t�nh"
	#define STRMSG_S_SCAT_COLNAME_0080 "The� ���c bi��t"
	#define STRMSG_S_SCAT_COLNAME_0081 "Ch��ng ph� hu�y khi n�ng c��p"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail-gun"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "Toa�n b�� Item"
//	#define STRMSG_S_SCAT_COLNAME_0082 "Toa�n b�� server"
//	#define STRMSG_S_SCAT_COLNAME_0083 "T�n server"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Loa�i server"
//	#define STRMSG_S_SCAT_COLNAME_0085 "IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "S�� ng���i ch�i Hi��n ta�i"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Tra�ng tha�i server"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Group server"
//	#define STRMSG_S_SCAT_COLNAME_0089 "server ha�m ���i"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Kh�ng xa�c �i�nh"
//	#define STRMSG_S_SCAT_COLNAME_0091 "Kh�ng th��c hi��n ����c"
//	#define STRMSG_S_SCAT_COLNAME_0092 "Bi�nh th���ng"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Kh�ng bi�nh th���ng"
	#define STRMSG_S_SCAT_COLNAME_0094 "Ng���i �i��u h�nh"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + 'c�i, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Danh s�ch m��nh l��nh\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- Danh s�ch ta�i khoa�n backup---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  ta�i khoa�n: \'%s\', m��t kh��u c�� �i�nh: \'%s\', m��t kh��u nh��t th��i: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  : \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Ba�n ha�y Cho�n folder c� phi�n ba�n c��p nh��t"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename server Group"
//	#define STRMSG_S_SCMONITOR_0007 "Vi��c ta�o file �a� th�nh c�ng.\r\n\r\nDB Th�ng tin: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  ki�ch hoa�t) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d �Kh�ng ki�ch hoa�t) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Vi��c t�i loading d�� li��u cu�a server �a� th�nh c�ng."
//	#define STRMSG_S_SCMONITOR_0011 "Ti�nh tra�ng server �a� ����c th�� hi��n."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  Ki�ch hoa�t)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d �Kh�ng ki�ch hoa�t)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "Di�ch vu� server mi��n phi� �a� k��t th�c."
//	#define STRMSG_S_SCMONITOR_0017 "Di�ch vu� server mi��n phi� b��t ���u."
//	#define STRMSG_S_SCMONITOR_0018 "server ha�m ���i ch�a ����c b��t ���u "
//	#define STRMSG_S_SCMONITOR_0019 "Ba�n th��c s�� mu��n ng��ng server ha�m ���i?"
//	#define STRMSG_S_SCMONITOR_0020 "Th�ng tin danh mu�c phi�n ba�n c��p nh��t (t��i �a 1492 Bytes)\r\n\r\n    S�� l���ng danh mu�c phi�n ba�n[%3d], dung l���ng[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "Ba�n th��c s�� mu��n ng��ng Pre server?"
//	#define STRMSG_S_SCMONITOR_0022 "Ba�n th��c s�� mu��n ng��ng IM server?"
//	#define STRMSG_S_SCMONITOR_0023 "Ba�n th��c s�� mu��n ng��ng NPC server?"
//	#define STRMSG_S_SCMONITOR_0024 "%Yn�m %mth�ng %dng�y %Hgi�� %Mph�t %Sgi�y"
//	#define STRMSG_S_SCMONITOR_0025 "Kh�ng c� event(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "event tham gia open beta(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "Kh�ng bi��t event(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "Th��i gian l��p cu��c chi��n chi��m tha�nh ph�� "
//	#define STRMSG_S_SCMONITOR_0029 "Th��i gian c�� �i�nh cu��c chi��n chi��m th�nh ph�� "
//	#define STRMSG_S_SCMONITOR_0030 "Binh �o�n chi��m li�nh"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> L��nh �a� th�nh c�ng.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> L��nh �a� th��t ba�i.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "Kh�ng k��t n��i ����c v��i DB."
//	#define STRERR_S_SCMONITOR_0003 "Kh�ng t��n ta�i phi�n ba�n t��ng ��ng"
//	#define STRERR_S_SCMONITOR_0004 "Ba�n ha�y nh��p t�n folder ����c n�n"
//	#define STRERR_S_SCMONITOR_0005 "Ba�n ha�y nh��p t�n folder ����c m��"
//	#define STRERR_S_SCMONITOR_0006 "Ba�n ha�y ��n nu�t b��t ���u"
//	#define STRERR_S_SCMONITOR_0007 "Ba�n ha�y nh��p phi�n ba�n cu��i "
//	#define STRERR_S_SCMONITOR_0008 "Ba�n ha�y Cho�n folder c� file zip d�ng ��� c��p nh��t"
//	#define STRERR_S_SCMONITOR_0009 "Kh�ng n��i ����c v��i file"
//	#define STRERR_S_SCMONITOR_0010 "Ba�n ha�y cho�n server!"
//	#define STRERR_S_SCMONITOR_0011 "Kh�ng k��t n��i ����c v��i DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "Qua� nhi��u danh mu�c phi�n ba�n c��p nh��t.(S�� l���ng[%3d], dung l���ng[%4dBytes])\r\n\r\n    Ba�n pha�i s��p x��p la�i danh mu�c Phi�n ba�n."
//	#define STRERR_S_SCMONITOR_0014 "Ky� n�ng bi� loa�i.\r\nBa�n ha�y s�� du�ng thanh �i��u chi�nh."
//	#define STRERR_S_SCMONITOR_0015 "��y kh�ng pha�i l� map cu��c chi��n chi��m th�nh ph��"
//	#define STRERR_S_SCMONITOR_0016 "Ba�n kh�ng th�� l��p Edit control."
//	#define STRERR_S_SCMONITOR_0017 "Ba�n ��ng ky� file �a� c� s��n. "

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - Fieldserver
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to Logserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Ba�n �a� k��t n��i v��i Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Ng��ng k��t n��i v��i Log Server[%15s:%4d]. M�y th�� k��t n��i la�i.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to Preserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Ba�n �a� k��t n��i Pre server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "vi��c k��t n��i v��i Pre server[%15s:%4d] �a� bi� ng��ng. M�y th�� k��t n��i la�i.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to  IMserver[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Ba�n �a� k��t n��i IM server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Vi��c k��t n��i v��i IM server[%15s:%4d]�a� bi� ng��ng. M�y th�� k��t n��i la�i.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Kh�ng t��n ta�i Item t��ng ��ng."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' �a� t��i �i��m danh n�n ����c nh��n Item nh� �a� h��a "
	#define STRMSG_S_F2DBQUERY_0003 "Ba�n ha�y ��n F5 ��� xem kho vu� kh� cu�a ba�n "
	#define STRMSG_S_F2DBQUERY_0004 "Skill �a� t�ng %s(%d) "
	#define STRMSG_S_F2DBQUERY_0005 "Kh�ng t��n ta�i Item t��ng ��ng."
	#define STRMSG_S_F2DBQUERY_0006 "Vi��c mua Item kh�ng th�nh c�ng."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  B��t ���u cu��c chi��n chi��m tha�nh ph�� : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  Binh �o�n tham gia: GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 " Qua�i v��t bi� n�� ta�i cu��c chi��n chi��m th�nh ph�� : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		  S�t th��ng ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  Cu��c chi��n chi��m tha�nh ph�� : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) Th��i gian(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d? ? \"%s\" Cu��c chi��n chi��m tha�nh ph�� b��t ���u."
	#define STRMSG_S_F2CITYWAR_0007 "Sau %dphu�t, \"%s\" Cu��c chi��n chi��m tha�nh ph�� k��t th�c."
	#define STRMSG_S_F2CITYWAR_0008 "Ta�i cu��c chi��n chi��m tha�nh ph��(%s)qua�i v��t ����c tri��u t��p : NPC chi��m li�nh"
	#define STRMSG_S_F2CITYWAR_0009 " Ta�i cu��c chi��n chi��m tha�nh ph��(%s)qua�i v��t ����c tri��u t��p: %s Binh �o�n chi��m li�nh"
	#define STRMSG_S_F2CITYWAR_0010 "Hi��n ta�i \"NPC\" �a� chi��m li�nh \"%s\" ."
	#define STRMSG_S_F2CITYWAR_0011 "Hi��n ta�i ha�m ���i \"%s\" �a� chi��m li�nh \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Vi��c loading quest th��t ba�i"
	#define STRMSG_S_F2QUEST_0001 "Vi��c loading quest kh�ng th�nh c�ng.\r\n"
//	#define STRMSG_S_F2QUEST_0002 "quest \'%30s\' ?? %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "server d�ng ��� th�� �a� setting! \r\n\r\nLoadFieldserverDataDebug() ��� nghi� loa�i! "
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1 hi�nh"
	#define STRMSG_S_F2NOTIFY_0003 "2 hi�nh"
	#define STRMSG_S_F2NOTIFY_0004 "mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Loa�i vu� kh� sai! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!"
	#define STRMSG_S_F2NOTIFY_0007 "Loa�i1-1: %4.1f vs %4.1f -> xa�c su��t c�ng k�ch gia�m %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s th��t ba�i, xa�c su��t(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s th��t ba�i, xa�c su��t(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s th��t ba�i, xa�c su��t(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "loa�i1-2: %4.1f vs %4.1f -> ��� s�t th��ng gia�m %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s %5.2f(%5.2f-%d/255) cho (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "T��%s->%s, nh��n %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "T�� %s->%s(%d, HP:%5.2f), ��a %5.2f(%5.2f-%d/255) ?(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "T��%s->%s, nh��n %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy th��t ba�i: xa�c su��t thi��u > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Dummy co�n la�i[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Kh�ng c� th�ng tin v�� �a�n. Xin ba�n vui lo�ng ho�i ng���i qua�n ly�."
	#define STRMSG_S_F2NOTIFY_0019 "Kh�ng t��n ta�i th�ng tin v�� c�� �a�n. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "Th�ng tin v�� �a�n. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "�ang x�� ly� s�� ki��n n�n ba�n kh�ng th�� th�ng qua c��a"
	#define STRMSG_S_F2NOTIFY_0022 "Ba�n kh�ng th�� th�ng qua c��a vi� �a� ch��t"
	#define STRMSG_S_F2NOTIFY_0023 "Ba�n kh�ng th�� th�ng qua c��a vi� �ang trong trong tr��n chi��n gi��a c�c nh�m"
	#define STRMSG_S_F2NOTIFY_0024 "L��i v�� ta�o map! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!"
	#define STRMSG_S_F2NOTIFY_0025 "L��i v�� ta�o map! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!Kh�ng c� Index mu�c ti�u s�� %d ta�i %d !\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Ba�n kh�ng th�� th�ng qua c��a vi� ch�a k��t th�c tr��n chi��n"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d) Kh�ng th�� th��c hi��n at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "  1 -> Nh�n v��t %10s �a� bi� s�t th��ng %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Nh�n v��t %10s �a� bi� s�t th��ng%5.2f" 
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Nh�n v��t %10s �a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Nh�n v��t %10s �a� bi� s�t th��ng %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "  2 -> Ba�n �a� bi� nh�n v��t %10 s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Nh�n v��t %10s �a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Qua�i v��t %3s �a� bi� s�t th��ng%5.2f(%d) "
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Nh�n v��t %10s�a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Nh�n v��t %10s�a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> Ba�n �a� bi� qua�i v��t %3d s�t th��ng %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "  MINE -> nh�n v��t %10s �a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "  MINE -> nh�n v��t %10s�a� bi� s�t th��ng%5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "  MINE -> qua�i v��t %10s�a� bi� s�t th��ng %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Quay tr�� v�� Stat ban ���u �a� th�nh c�ng"
	#define STRMSG_S_F2NOTIFY_0042 "Kh�ng th�� s�� du�ng khi ch��t"
	#define STRMSG_S_F2NOTIFY_0043 "Kh�ng c� th�ng tin n�ng c��p "
	#define STRMSG_S_F2NOTIFY_0044 "N�ng c��p th�nh c�ng"
	#define STRMSG_S_F2NOTIFY_0045 "N�ng c��p th��t ba�i"
	#define STRMSG_S_F2NOTIFY_0046 "Ba�n kh�ng thu��c ha�m ���i."
	#define STRMSG_S_F2NOTIFY_0047 "Ba�n �a� �ang �� tra�ng tha�i ch��."
	#define STRMSG_S_F2NOTIFY_0048 "Xin ba�n vui lo�ng th�� la�i l�c kh�c."
	#define STRMSG_S_F2NOTIFY_0049 "Ba�n ho��c ���i ph��ng kh�ng pha�i l� ha�m ���i tr���ng."
	#define STRMSG_S_F2NOTIFY_0050 "Ba�n �ang tham gia cu��c chi��n ha�m ���i."
	#define STRMSG_S_F2NOTIFY_0051 "Hai ha�m ���i tr���ng kh�ng c�ng map."
	#define STRMSG_S_F2NOTIFY_0052 "Toa�n b�� th�nh vi�n nh�m kh�ng c�ng map"
	#define STRMSG_S_F2NOTIFY_0053 "Toa�n b�� th�nh vi�n nh�m kh�ng c�ng map"
	#define STRMSG_S_F2NOTIFY_0054 "Ba�n kh�ng thu��c ha�m ���i."
	#define STRMSG_S_F2NOTIFY_0055 "Ng���i ��ng ky� kha�c ng���i bi� ��ng ky�."
	#define STRMSG_S_F2NOTIFY_0056 "Ba�n ho��c ���i ph��ng kh�ng pha�i l� ha�m ���i tr���ng."
	#define STRMSG_S_F2NOTIFY_0057 " Hai ha�m ���i tr���ng kh�ng c�ng map"
	#define STRMSG_S_F2NOTIFY_0058 "Ba�n kh�ng thu��c ha�m ���i."
	#define STRMSG_S_F2NOTIFY_0059 "Ng���i ��ng ky� kha�c ng���i bi� ��ng ky�."
	#define STRMSG_S_F2NOTIFY_0060 "Ba�n ho��c ���i ph��ng kh�ng pha�i l� ha�m ���i tr���ng."
	#define STRMSG_S_F2NOTIFY_0061 "Th�nh c�ng trong vi��c pho�ng ng�� ta�i cu��c chi��n chi��m th�nh ph��"
	#define STRMSG_S_F2NOTIFY_0062 "L��i v�� vi��c l��p nhi��m vu�. Xin ba�n vui lo�ng ho�i ng���i qua�n ly�."
	#define STRMSG_S_F2NOTIFY_0063 "Ba�n kh�ng th�� g��n Item(%s)v�o vi� tr� n�y"
	#define STRMSG_S_F2NOTIFY_0064 "Ba�n kh�ng th�� bo� tr��ng ���ng c�."
	#define STRMSG_S_F2NOTIFY_0065 "Di ���ng Item : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Di ���ng Item sai : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d) Kh�ng th�� th��c hi��n at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "L��i v�� th�ng tin map event!!! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!!!"
	#define STRMSG_S_F2NOTIFY_0069 "Kh�ng c� mu�c ti�u t��ng ��ng "
	#define STRMSG_S_F2NOTIFY_0070 "L��i v�� mua Item . Xin ba�n vui lo�ng li�n h�� nha� qua�n tri�."
	#define STRMSG_S_F2NOTIFY_0071 " Level skill ba�n �i�nh mua b��ng ho��c k�m h�n level c��a skill hi��n c�"
	#define STRMSG_S_F2NOTIFY_0072 "L��i v�� Item c��n khi mua Skill."
	#define STRMSG_S_F2NOTIFY_0073 "L��i v�� b�n Item. Xin ba�n vui lo�ng li�n h�� nha� qua�n tri�."
	#define STRMSG_S_F2NOTIFY_0074 "L��i v�� mua Item . Xin ba�n vui lo�ng li�n h�� nha� qua�n tri�."
	#define STRMSG_S_F2NOTIFY_0075 "Ba�n �a� mua \'Item Vcoin\' the� ti��n."
	#define STRMSG_S_F2NOTIFY_0076 "  Danh mu�c c�c ��� ba�n mua : \'%s(%dc�i)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Ba�n �a� gia nh��p nh�m."
	#define STRMSG_S_F2NOTIFY_0078 "Ba�n l� nh�m tr���ng thi� l�m sao gia nh��p nh�m ����c n��a?"
	#define STRMSG_S_F2NOTIFY_0079 "cu��c chi��n ���u gi��a c�c nh�m �ang ti��n h�nh n�n ba�n kh�ng th�� tham gia."
	#define STRMSG_S_F2NOTIFY_0080 "Kh�ng chi vi��n vi��c hi��n thi� th�ng tin toa�n b�� th�nh vi�n trong nh�m!"
	#define STRMSG_S_F2NOTIFY_0081 "L��i v�� th�ng tin map event!!! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!!!"
	#define STRMSG_S_F2NOTIFY_0082 "��y l� ta�i khoa�n kh�ng th�� giao di�ch"
	#define STRMSG_S_F2NOTIFY_0083 "%s�a� qu� ta�i."
	#define STRMSG_S_F2NOTIFY_0084 "to�a ��� c� th�� di ���ng: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Ng���i s�� du�ng: "
	#define STRMSG_S_F2NOTIFY_0086 "T��i �a 20 ng���i c� th�� xem."
	#define STRMSG_S_F2NOTIFY_0087 "Kh�ng c� ng���i s�� du�ng(%s)t��ng ��ng"
	#define STRMSG_S_F2NOTIFY_0088 "Ba�n kh�ng thu��c nh�m"
	#define STRMSG_S_F2NOTIFY_0089 "Th��i gian hi��n ta�i: %d:%d, Th��i gian Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Th��i gian bi��n ���i: %d:%d, Th��i gian Artum: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Vi��c k��t n��i v��i NPC server kh�ng th�nh c�ng"
	#define STRMSG_S_F2NOTIFY_0092 "Kh�ng t��n ta�i Item(%d)t��ng ��ng"
	#define STRMSG_S_F2NOTIFY_0093 "Gi��i ha�n t��i �a la� 10 c�i trong tr���ng h��p kh�ng pha�i l� Countable Item "
	#define STRMSG_S_F2NOTIFY_0094 "T�ng s�� ng���i truy c��p map \'%s\': %dng���i"
	#define STRMSG_S_F2NOTIFY_0095 "C�ng truy c��p map %s %s : %dng���i - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "C�ng truy c��p map %s %s : %dng���i - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "K�nh map hi��n ta�i: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Kh�ng c� th�ng tin v�� �a�n. Xin ba�n vui lo�ng ho�i ng���i qua�n ly�."
	#define STRMSG_S_F2NOTIFY_0099 "Kh�ng c� th�ng tin v�� c�� �a�n. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Kh�ng c� th�ng tin v�� �a�n. Xin ba�n vui lo�ng ho�i ng���i qua�n ly�."
	#define STRMSG_S_F2NOTIFY_0101 " Kh�ng c� th�ng tin v�� c�� �a�n. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Kh�ng c� th�ng tin v�� ng���i s�� du�ng(%s)t��ng ��ng"
	#define STRMSG_S_F2NOTIFY_0103 "Ng���i s�� du�ng t��ng ��ng(%s)�ang �� tra�ng th�i ch��t"
	#define STRMSG_S_F2NOTIFY_0104 "Kh�ng c� ng���i s�� du�ng(%s)t��ng ��ng"
	#define STRMSG_S_F2NOTIFY_0105 "Ba�n �a� ���t �� ch�� ��� ta�i khoa�n th�ng th���ng"
	#define STRMSG_S_F2NOTIFY_0106 "Gia�i ch�� ��� ta�i khoa�n th�ng th���ng"
	#define STRMSG_S_F2NOTIFY_0107 "Ba�n �a� ca�i ���t unit v� �i�ch(kh�ng bi� th��ng t�ch)"
	#define STRMSG_S_F2NOTIFY_0108 "Ba�n �a� gia�i vi��c ca�i ���t unit v� �i�ch (kh�ng bi� th��ng t�ch)"
	#define STRMSG_S_F2NOTIFY_0109 "Vu�  kh� �a� ����c t�ng %5.0f%% t�nh hoa�t ���ng"
	#define STRMSG_S_F2NOTIFY_0110 "Tr�� v�� tra�ng tha�i ban ���u khi l��p ���t la�i Item"
	#define STRMSG_S_F2NOTIFY_0111 "Tr�� v�� tra�ng tha�i ban ���u khi l��p ���t la�i Item"
	#define STRMSG_S_F2NOTIFY_0112 "Kh�ng c� ng���i s�� du�ng(%s)t��ng ��ng"
	#define STRMSG_S_F2NOTIFY_0113 "Ky� n�ng ��n �a� ����c gia�i"
	#define STRMSG_S_F2NOTIFY_0114 "Ky� n�ng ��n �a� ����c kh��i ���ng"
	#define STRMSG_S_F2NOTIFY_0115 "Kh�ng pha�i th��i gian ti��n ha�nh %s event"
	#define STRMSG_S_F2NOTIFY_0116 "B��t ���u event%s (ty� l��:%4.2f, th��i gian:%3dph�t)"
	#define STRMSG_S_F2NOTIFY_0117 "Ta�i khoa�n �a� tra� phi� ha�ng tha�ng"
	#define STRMSG_S_F2NOTIFY_0118 "L��i khi tra� phi� ha�ng tha�ng"
	#define STRMSG_S_F2NOTIFY_0119 "Ba�n �a� ca�i ���t �� ch�� ��� ta�i khoa�n super premium"
	#define STRMSG_S_F2NOTIFY_0120 "Kh�ng pha�i map cu��c chi��n chi��m tha�nh ph��"
	#define STRMSG_S_F2NOTIFY_0121 "Ba�n kh�ng th�� b��t ���u cu��c chi��n chi��m th�nh ph��"
	#define STRMSG_S_F2NOTIFY_0122 "Ba�n kh�ng th�� k��t th�c cu��c chi��n chi��m th�nh ph��"
	#define STRMSG_S_F2NOTIFY_0123 " �a� tr�� v�� tra�ng tha�i ��n ban ���u "
	#define STRMSG_S_F2NOTIFY_0124 "B��t ���u tra�ng tha�i ��n"
	#define STRMSG_S_F2NOTIFY_0125 "Map kh�ng co�n ����c s�� du�ng."
	#define STRMSG_S_F2NOTIFY_0126 "B��t ���u th��i gian �Ha�nh ph�c� [th��i gian:%4dph�t)]"
	#define STRMSG_S_F2NOTIFY_0127 "Th��i gian �Ha�nh ph�c� �a�  k��t th�c"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> Ba�n �a� bi� th��ng %5.2f b��i qu�i v��t%3d"
	#define STRMSG_S_F2NOTIFY_0129 "  Loa�i 1 -> Ba�n �a� bi� th��ng %5.2f  b��i qua�i v��t %3d (dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Ba�n �a� truy c��p v��i t� c�ch %s"
	#define STRMSG_S_F2NOTIFY_0131 "Kh�ng ti��n ha�nh vi��c ng��ng routine%s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "  ERROR@CharacterGameEndRoutine(): vi��c khai tr�� th�nh vi�n trong nh�m kh�ng th�nh c�ng! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' Th�nh c�ng: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' Th�nh c�ng: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Ng��ng!"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR: Xin ba�n vui lo�ng ho�i ng���i qua�n ly�! L��i ph�n ph��i chi� s�� c��a h�ng!"
	#define STRMSG_S_F2NOTIFY_0137 "%s�a� bi� xo�a."
	#define STRMSG_S_F2NOTIFY_0138 "Hi��n ta�i k�nh ba�n �ang s�� du�ng kh�ng ����c ki�ch hoa�t n�n qua�i v��t v� c�c ky� n�ng kh�c"
	#define STRMSG_S_F2NOTIFY_0139 "�a� bi� ng��ng. Xin ba�n vui lo�ng s�� du�ng k�nh kh�c."
	#define STRMSG_S_F2NOTIFY_0140 "  Warp Obj.[%s,%2dc�i]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "���ng t�c timer %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Ng��ng vi��c h��i phu�c HP t�� ���ng"
	#define STRMSG_S_F2NOTIFY_0143 "Ng��ng vi��c h��i phu�c HP t�� ���ng do ��y kh�ng pha�i l� khu v��c c� th�� ha� c�nh"
	#define STRMSG_S_F2NOTIFY_0144 "H��i phu�c HP 5.2f nh�� c��p c��u "
	#define STRMSG_S_F2NOTIFY_0145 "D��ng Gradual HP UP (Th��i gian co�n la�i: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "D��ng Gradual DP UP (Th��i gian co�n la�i: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "D��ng Gradual EP UP (Th��i gian co�n la�i: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "K��t th�c s�� ki��n %s ."
	#define STRMSG_S_F2NOTIFY_0149 "S�� ki��n %s �ang ti��n ha�nh(Ti� l�� %4.2f, Th��i gian co�n la�i:%3d ph�t)"
	#define STRMSG_S_F2NOTIFY_0150 "M��nh l��nh kh�ng ����c th��c hi��n"

	
	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	L��i v�� ph�n ph��i chi� s�� kinh nghi��m(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "  L��i v�� Game Start kh�ng t��n ta�i ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 " L��i v�� Game Start kh�ng t��n ta�iClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "  WARP(%04d) Kh�ng th�� ti��n ha�nh at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "L��i th�ng tin map event!!! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "  EVENT(%d)Kh�ng th�� ti��n ha�nh at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "L��i th�ng tin map event!!! Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "  WARP Kh�ng th�� ti��n ha�nh at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "  EVENT(%d) Kh�ng th�� ti��n ha�nh (Tr���ng nh�m) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "  WARP(%04d) Kh�ng th�� th��c hi��n at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "  EVENT(%d) Kh�ng th�� th��c hi��n at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "  WARP Kh�ng th�� th��c hi��n at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "vi��c warp nh�m th��t ba�i : %s -> Khoa�ng c�ch: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "  WARP(%04d) Kh�ng th�� th��c hi��n at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "  %s -> ��n OK tr�ng l��p!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Quest kh�ng loading ����c.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "  WARP(%s) Kh�ng th�� th��c hi��n at HandleAdminCommands(), /di chuy��n, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "  WARP(%s) Kh�ng th�� th��c hi��n at HandleAdminCommands(), /G��i, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "  FATAL ERROR: Ta�i server ha�m ���i th�nh vi�n kh�ng gia nh��p, tin nh��n kh�ng ����c g��i ���n. check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "  WARP(%04d) Kh�ng th�� th��c hi��n at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "  WARP(%s) Kh�ng th�� th��c hi��n at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "T�ng �i��m kinh nghi��m"
	#define STRMSG_S_F2EVENTTYPE_0001 "T�ng l���ng SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "T�ng kha� n�ng h��i phu�c"
	#define STRMSG_S_F2EVENTTYPE_0003 "T�ng ti� l�� r�i ���"
	#define STRMSG_S_F2EVENTTYPE_0004 "T�ng ti� l�� r�i ��� hi��m"
	#define STRMSG_S_F2EVENTTYPE_0005 "Kh�ng xa�c nh��n ����c s�� ki��n"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMserver
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Ba�n �a� truy c��p v�o Pre server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Vi��c k��t n��i v��i Pre server[%15s:%4d]�a� bi� ng��ng. M�y th�� k��t n��i la�i.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'l� t�n ha�m ���i �a� t��n ta�i"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'�a� gia nh��p ha�m ���i."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'l� t�n ha�m ���i �a� t��n ta�i"
	#define STRMSG_S_I2NOTIFY_0003 "vi��c loading ha�m ���i kh�ng th�nh c�ng - Xin ba�n vui lo�ng ho�i ng���i qua�n ly�!"
	#define STRMSG_S_I2NOTIFY_0004 "'%s'�ang truy c��p"
	#define STRMSG_S_I2NOTIFY_0005 "ki��m tra nh�m tr���c"
	#define STRMSG_S_I2NOTIFY_0006 "Kh�ng t��n ta�i nh�m hi��n ta�i"
	#define STRMSG_S_I2NOTIFY_0007 "��ng ky� la�i nh�m  "
	#define STRMSG_S_I2NOTIFY_0008 "Ba�n �a� ��ng ky� nh�m."
	#define STRMSG_S_I2NOTIFY_0009 "  Fatal Error: L��i nghi�m tro�ng v�� nh�m! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "Tra�ng tha�i cu�a th�nh vi�n trong nh�m kh�ng ��ng"
	#define STRMSG_S_I2NOTIFY_0011 "Th�nh vi�n trong nh�m �a� gia nh��p ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0012 "���i t���ng �a� gia nh��p ha�m ���i "
	#define STRMSG_S_I2NOTIFY_0013 "Ba�n kh�ng th�� m��i la�i mi�nh"
	#define STRMSG_S_I2NOTIFY_0014 "Ti�nh tra�ng kh�ng cho ph�p gia nh��p ha�m ���i "
	#define STRMSG_S_I2NOTIFY_0015 "Binh �o�n �a� �u� ng���i"
	#define STRMSG_S_I2NOTIFY_0016 "Ti�nh tra�ng kh�ng cho ph�p gia nh��p ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0017 "Binh �o�n tr���ng kh�ng th�� r��i ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0018 "�ang trong tr��n chi��n ha�m ���i n�n ba�n kh�ng th�� r��i kho�i ha�m ���i "
	#define STRMSG_S_I2NOTIFY_0019 "�ang trong tr��n chi��n ha�m ���i n�n ba�n kh�ng th�� khai tr�� th�nh vi�n"
	#define STRMSG_S_I2NOTIFY_0020 "Kh�ng th�� khai tr�� ha�m ���i tr���ng"
	#define STRMSG_S_I2NOTIFY_0021 "�ang trong tr��n chi��n ha�m ���i n�n ba�n kh�ng th�� gia�i t�n ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0022 "Ba�n kh�ng th�� thay ���i t�n ha�m ���i v�� t�n cu�?"
	#define STRMSG_S_I2NOTIFY_0023 "Ba�n kh�ng th�� thay ���i t�n ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0024 "Ba�n kh�ng th�� thay ���i d��u hi��u ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0025 "Ba�n kh�ng th�� thay ���i c��p ���"
	#define STRMSG_S_I2NOTIFY_0026 "Tr�ng c��p ���"
	#define STRMSG_S_I2NOTIFY_0027 "Ba�n kh�ng th�� ���i l�n c��p ha�m ���i tr���ng."
	#define STRMSG_S_I2NOTIFY_0028 "Ba�n kh�ng th�� thay ���i c��p ��� ha�m ���i tr���ng."
	#define STRMSG_S_I2NOTIFY_0029 "T��ng s�� ng���i s�� du�ng: %dng���i (t��i �a %d ng���i)."
	#define STRMSG_S_I2NOTIFY_0030 "Tin nh��n cu�a ng���i �i��u h�nh �a� ����c b�� sung v�o danh mu�c."
	#define STRMSG_S_I2NOTIFY_0031 "Tin nh��n cu�a ng���i �i��u h�nh �a� ����c loa�i kho�i danh mu�c."
	#define STRMSG_S_I2NOTIFY_0032 "server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "T��ng s�� ng���i\'%s\' truy c��p server Group: %d Ng���i."
	#define STRMSG_S_I2NOTIFY_0034 "Ba�n th��c s�� mu��n t��t server (%s)? S��: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' �ang kh�ng ch�i."
	#define STRMSG_S_I2NOTIFY_0036 "T��ng s�� ng���i s�� du�ng: %d ng���i (T��i �a %d ng���i)"
	#define STRMSG_S_I2NOTIFY_0037 "/g��i �i %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Kh�ng c� ha�m ���i t��ng ��ng."
	#define STRMSG_S_I2NOTIFY_0039 "Gia�i vi��c cho�n ch��c n�ng  Thi� th��m!"
	#define STRMSG_S_I2NOTIFY_0040 "Cho�n ch��c n�ng Thi� th��m!"
	#define STRMSG_S_I2NOTIFY_0041 "Ba�n ch�a gia nh��p ha�m ���i"
	#define STRMSG_S_I2NOTIFY_0042 "Binh �o�n(%d)kh�ng co�n ����c s�� du�ng"
	#define STRMSG_S_I2NOTIFY_0043 "Kh�ng t��n ta�i th��i ti��t t��ng ��ng(%s)"
	#define STRMSG_S_I2NOTIFY_0044 "Field server kh�ng h��u hi��u"
	#define STRMSG_S_I2NOTIFY_0045 "Kh�ng t��n ta�i map(%s)t��ng ��ng"
	#define STRMSG_S_I2NOTIFY_0046 "Ba�n �ang trong �i��u ki��n c��m ch�t trong vo�ng %d ph�t!!"
	#define STRMSG_S_I2NOTIFY_0047 "���t ky� n�ng c��m chat: '%10s', %3d ph�t"
	#define STRMSG_S_I2NOTIFY_0048 "T��t ky� n�ng c��m chat."
	#define STRMSG_S_I2NOTIFY_0049 "T��t ky� n�ng c��m chat : '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (Ta�i khoa�n: %s, Map: %d(%d), Level: %d) �ANG CH�I"
	#define STRMSG_S_I2NOTIFY_0051 "Ba�n kh�ng th�� go�i chi�nh ba�n th�n."
	#define STRMSG_S_I2NOTIFY_0052 "Kh�ng t��n ta�i ha�m ���i t��ng ��ng."

	#define STRMSG_S_IMSERVER_050607_0001	"Kh�ng t��n ta�i map t��ng ��ng."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCserver
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Ba�n �a� truy c��p Field server.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Vi��c k��t n��i v��i Field server[%15s:%4d] �a� bi� ng��ng. M�y th�� k��t n��i la�i.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							Kh�ng c� s�� va cha�m v��i qua�i v��t\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Ta�i cu��c chi��n chi��m tha�nh ph�� qu�i v��t(%10s)�a� ����c tri��u h��i\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chol Min Ho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - Preserver
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 " %s �a� truy c��p v�o ta�i khoa�n (%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Th�nh c�ng"
	#define STRMSG_S_P2PRENOTIFY_0002 "Th��t ba�i"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]L��i khi th�m th�ng tin t�i khoa�n, T�n ta�i khoa�n (%s)  IP ca� nh�n (%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Cao B��i Kh�ng Gian g��i l��i ch�o ���n c�c ba�n."
	#define STRMSG_SCAT_051115_0002		"Cao B��i Kh�ng Gian se� ti��n ha�nh ki��m tra �i�nh ky� t�� 9h ���n 11h trong ng�y."
	#define STRMSG_SCAT_051115_0003		"Xin ba�n vui lo�ng di chuy��n ���n m��t n�i an to�n r��i ng��ng truy c��p."
	#define STRMSG_SCAT_051115_0004		"���u ti�n NPC server se� t��t."
	#define STRMSG_SCAT_051115_0005		"Cao B��i Kh�ng Gian b��t ���u ti��n h�nh ki��m tra �i�nh ky�."
	#define STRMSG_SCAT_051115_0006		"Ch�c ba�n c� m��t ng�y vui ve� v��i Cao B��i Kh�ng Gian."
	#define STRMSG_SCAT_051115_0007		"V�i ph�t sau server se� ng��ng hoa�t ���ng ��� ki��m tra kh��n c��p."
	#define STRMSG_SCAT_051115_0008		"Q�a tri�nh ki��m tra ti��n ha�nh trong vo�ng 120 ph�t."







///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Ch�� ��� ��n: Ng���i ch�i kh�ng th�� nhi�n th��y, kh�ng th�� s�� du�ng vu� khi�."
	#define STRMSG_060509_0001			"Ch�� ��� b��t t��: Kh�ng bao gi�� bi� t��n th��ng."
	#define STRMSG_060509_0002			"Ch�� ��� ta�ng hi�nh: Qua�i v��t se� kh�ng t��n c�ng."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"��� nghi� cu�a ba�n �a� ����c g��i t��i GM."
	#define	STRMSG_060526_0001			"Kh�ng th�� t�� ���ng c��p nh��t.\r\n\r\n Ha�y ta�i ba�n patch t�� trang chu� cu�a game (%s) va� truy c��p la�i.\r\n\r\n Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"Ta�i khoa�n na�y ch�a ����c ��ng ky� ho��c nh��p sai t�n ta�i khoa�n/m��t kh��u."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"H�� th��ng ma�y chu� �ang ����c �o�ng ��� ba�o tri�. Ha�y truy c��p trang chu� cu�a game http://phidoi.vtc.vn ��� co� th�ng tin chi ti��t."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Phi�n ba�n (version) ca�i ���t kh�ng phu� h��p.\r\n  Ha�y ti��n ha�nh ca�i ���t la�i ho��c cha�y ba�n n�ng c��p (patch) ta�i t�� trang chu� cu�a game."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Ba�n �a� bi� %s ha�."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Vi��c kh��i ta�o d�� li��u cho ma�y chu� Jamboree(atum2_db_20) chi� ����c th��c hi��n sau khi �a� ng��ng ma�y chu�."
	#define STRMSG_070410_0001   	"Ba�n mu��n kh��i ta�o d�� li��u cho ma�y chu� Jamboree(atum2_db_20)- [S�� xa�c nh��n:%d]"
	#define STRMSG_070410_0002   	"�a� kh��i ta�o tha�nh c�ng d�� li��u cho ma�y chu� Jamboree(atum2_db_20)."
	#define STRMSG_070410_0003   	"Th��t ba�i khi kh��i ta�o d�� li��u cho ma�y chu� Jamboree(atum2_db_20) !!"
	#define STRMSG_070410_0004   	"'%s' d�� li��u �a� ����c copy t��i ma�y chu� Jamboree(atum2_db_20)."
	#define STRMSG_070410_0005   	"'%s' chuy��n th�ng tin t��i ma�y chu� Jamboree(atum2_db_20) th��t ba�i - Nh�n v��t kh�ng t��n ta�i!!"
	#define STRMSG_070410_0006   	" %s' chuy��n th�ng tin t��i ma�y chu� Jamboree(atum2_db_20) th��t ba�i - �a� co� nh�n v��t t��ng ���ng!!"
	#define STRMSG_070410_0007   	" %s' chuy��n th�ng tin t��i ma�y chu� Jamboree(atum2_db_20) th��t ba�i - L��i khi th�m d�� li��u!!"
	#define STRMSG_070410_0008   	" %s' chuy��n th�ng tin t��i ma�y chu� Jamboree(atum2_db_20) th��t ba�i - Kh�ng xa�c �i�nh (%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, �ػ� ���ڿ� 
	// 2007-07-24 by cmkwon, ��ó���� 800*600 �ػ� ���� - �޺��ڽ� ��Ʈ�� �ʿ� ����
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

// 2007-06-15 by dhjin, ���� ���� ��Ʈ��
	#define STRMSG_070615_0000		"Kh�ng th�� kh��i ���ng do kh�ng �� tra�ng tha�i ��n."
	#define STRMSG_070615_0001		"Kh�ng th�� kh��i ���ng ch�� ��� quan sa�t."
	#define STRMSG_070620_0000	"Ng���i ch�i kh�ng th�� s�� du�ng ch��c n�ng quan sa�t."

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRMSG_S_F2EVENTTYPE_0006		"�i��m danh vo�ng"

// 2007-06-28 by cmkwon, �߱� ���?���?(���� �?�� �˸� ����) - ��Ʈ�� ?߰�
#define STRMSG_070628_0000				"Ba�n �a� ch�i ����c %d gi��."
#define STRMSG_070628_0001				"Ba�n �a� ch�i ����c %d gi�� r��i ���y. Ha�y nghi� ng�i m��t chu�t."
#define STRMSG_070628_0002				"Ba�n �a� ch�i qua� 3 gi��. Ti� l�� �i��m kinh nghi��m, SPI, r�i ��� hi��n ta�i cu�a ba�n co�n 50%"
#define STRMSG_070628_0003				"Ba�n �a� ch�i qua� 5 gi��. Ti� l�� �i��m kinh nghi��m, SPI, r�i ��� hi��n ta�i cu�a ba�n co�n 0%."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' bi� c��m truy c��p va�o Arena."
#define STRMSG_070711_0001 "\'%s\' bi� c��m truy c��p va�o Arena (Th��i gian co�n la�i: %d phu�t)"
#define STRMSG_070711_0002 "Ba�n bi� c��m truy c��p va�o Arena trong vo�ng %d phu�t n��a."
#define STRMSG_070711_0003 "Ba�n �a� ����c phe�p truy c��p va�o Arena."
#define STRMSG_070711_0004 "Nh�n v��t \'%s\' �a� ����c phe�p truy c��p va�o Arena."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide �ػ� 1280x720(16:9) �߰� - ��Ʈ�� �߰�
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��Ʈ�� �߰�
#define STRMSG_070830_0001                                   "L��nh na�y chi� co� th�� s�� du�ng sau khi �a� cho�n qu��c gia."
#define STRMSG_070830_0002                                   "Pho�ng h��i nghi� (%d) cu�a qu��c gia t��ng ��ng hi��n ch�a th�� s�� du�ng"
#define STRMSG_070830_0003                                   "S�� ng���i ����c phe�p va�o pho�ng h��i nghi� : %d ng���i"
#define STRMSG_070830_0004                                   "Ba�n �a� cho phe�p nh�n v��t '%s' va�o pho�ng h��i nghi�."
#define STRMSG_070830_0005                                   "'%s' kh�ng ����c phe�p va�o pho�ng h��i nghi�."
#define STRMSG_070830_0006                                   "Sai t�n nh�n v��t '%s'."
#define STRMSG_070830_0007                                 "Kh�ng th�� cho phe�p '%s' truy c��p pho�ng h��i nghi� (T��i �a %d ng���i)"
#define STRMSG_070830_0008                                   "'%s' �a� co� th�� va�o pho�ng h��i nghi�."
#define STRMSG_070830_0009                                   "Ba�n �a� ����c phe�p truy c��p pho�ng h��i nghi�."
#define STRMSG_070830_0010                                   "Ba�n kh�ng ����c phe�p truy c��p pho�ng h��i nghi�."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s g��i t��ng ba�n %s."
#define STRMSG_071115_0002									"Danh sa�ch qua� t��ng : \'%s(%d ca�i)\'"
#define STRMSG_071115_0003									"\\y%s �a� t��ng qua� cho %s.  Mo�n qua� la�  %s. Vui lo�ng ki��m tra trong kho ch��a ���."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Kh�ng th�� s�� du�ng l��nh na�y trong th��i �i��m hi��n ta�i. Vui lo�ng li�n la�c trung t�m ch�m so�c kha�ch ha�ng."
#define STRMSG_071120_0002									"�a� ki�ch hoa�t l��nh CallGM."
#define STRMSG_071120_0003									"�a� ng��ng vi��c s�� du�ng l��nh CallGM."
#define STRMSG_071120_0004									"L��nh CallGM co� th�� s�� du�ng t�� %s ���n %s."

// 2007-11-28 by cmkwon, �����?���� ���� - 
#define STRMSG_071128_0001									"%s �a� g��i t��ng ba�n %s(%d). Ha�y ki��m tra ta�i kho ch��a ���."

// 2007-12-27 by cmkwon, �����?�� �?�� ��� ?߰� - 
#define STRMSG_071228_0001				"��� ph�n gia�i ma�n hi�nh kh�ng phu� h��p. Ha�y ki��m tra la�i."

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �?���� ���� - 
#define STRMSG_080201_0001									"'Error exists in %s' block setting. ErrorCode(%d)"
#define STRMSG_080201_0002									"Ta�i khoa�n '%s' �a� bi� kho�a. [Nga�y h��t ha�n: %s]"
#define STRMSG_080201_0003									"Kh�ng t��n ta�i ta�i khoa�n '%s' trong danh sa�ch nh��ng ta�i khoa�n bi� kho�a. ErrorCode(%d)"
#define STRMSG_080201_0004									"L��i pha�i sinh trong khi kho�a ta�i khoa�n '%s'. ErrorCode(%d)"
#define STRMSG_080201_0005									"�a� xo�a ta�i khoa�n '%s' trong danh sa�ch nh��ng ta�i khoa�n bi� kho�a." 

// 2008-02-11 by cmkwon, �ػ� �߰�(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin, �Ʒ�������- �Ʒ�������������ÿ���
#define STRMSG_S_MF2AFCONNECT_0000                       "[L��i] WndProc(), Kh�ng th�� k��t n��i t��i ma�y chu� Arena[%15s:%4d] Ha�y th�� la�i\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "�a� k��t n��i t��i ma�y chu� Arena.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "K��t n��i t��i ma�y chu� Arena[%15s:%4d] bi� gia�n �oa�n. �ang k��t n��i la�i.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Pho�ng s�� \\y%d �a� ����c chuy��n t�� pho�ng th���ng tha�nh pho�ng s�� ki��n.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "Pho�ng s�� \\y%d �a� ����c chuy��n t�� pho�ng s�� ki��n tr�� v�� pho�ng th���ng.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Kh�ng th�� thi��t l��p cho Arena.\r\n"
#define STRMSG_080428_0001					"%s �a� bi� b��n ha�."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
#define STRMSG_080430_0001					"Kh�ng th�� ta�o nh�n v��t m��i tr�n ma�y chu� hi��n ta�i."

// 2008-06-13 by dhjin, EP3 ���� ���� ���� - 
#define STRMSG_080613_0001					"Ha�m ���i %s �a� t�� ch��i ��n gia nh��p."

// 2008-09-04 by cmkwon, don't need translation, ������ SystemLog �̹Ƿ� ���� �ʿ� ����
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRMSG_081230_0001					"\\y%s se� bi� c��m chat trong %d phu�t.\\y"
#define STRMSG_081230_0002					"\\yThu� li�nh �a� ki�ch hoa�t ng�ng s�� du�ng h�� th��ng chat trong %d phu�t.\\y"
#define STRMSG_081230_0003					"\\yThu� li�nh �a� cho phe�p s�� du�ng h�� th��ng chat.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D ���Ӱ��� ����â ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - ������� ����, STRMSG_090831_0001�� ���������� ó��
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0002					"Install nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect ����â ����
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �ػ� �߰�(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ���? ������ ���� �?�� ��Ȳ
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Not Registered Server (It can be Illegal Private Server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"L��i xu��t hi��n trong khi k��t n��i t��i DB"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Authentication succeed"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Registered Server IP But proceed Authentication Denied"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows Shut Down command is sent to the server."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 Ʈ���� �ý��� �̺�Ʈ �˸�

// 1�� �̺�Ʈ

#define STRMSG_120330_0001					"%s Ki�ch hoa�t c��ng di�ch chuy��n bi� m��t ta�i Ashlane."
#define STRMSG_120330_0002					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 100%%%% kinh nghi��m trong 1h ta�i Ashlane."
#define STRMSG_120330_0003					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 100%%%% ty� l�� r�i ��� trong 1h ta�i Ashlane."
#define STRMSG_120330_0004					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 100%%%% ty� l�� r�i ���/ SPI/ �i��m kinh nghi��m trong 1h ta�i Ashlane."
#define STRMSG_120330_0005					"%s Ki�ch hoa�t c��a ha�ng vu� khi� ta�i Ashlane."
#define STRMSG_120330_0006					"%s Ki�ch hoa�t cu�a ha�ng the� ���c bi��t ta�i Ashlane."
#define STRMSG_120330_0007					"%s Ki�ch hoa�t c��a ha�ng thi��t bi� ta�i Ashlane."
#define STRMSG_120330_0008					"%s Qua�i v��t kh��ng l�� �a� ����c tri��u h��i ta�i Ashlane."
#define STRMSG_120330_0009					"Crystal �a� bi��n m��t."

// 2�� �̺�Ʈ

#define STRMSG_120508_0001					"%s Thu ����c �i��m danh vo�ng nhi��u nh� %d WP ta�i Lost Oasis."
#define STRMSG_120508_0002					"%s Si�u boss �a� xu��t hi��n ta�i Lost Oasis."
#define STRMSG_120508_0003					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 150%%%% kinh nghi��m trong 1h Lost Oasis."
#define STRMSG_120508_0004					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 150%%%% ty� l�� r�i ��� trong 1h ta�i Lost Oasis."
#define STRMSG_120508_0005					"%s Ki�ch hoa�t gi�� va�ng gia t�ng 150%%%% ty� l�� r�i ���/ kinh nghi��m/ SPI/ trong 1h ta�i Lost Oasis."
#define STRMSG_120508_0006					"%s Thu ����c Ancient Ice ta�i Lost Oasis."
#define STRMSG_120508_0007					"%s Ki�ch hoa�t c��a ha�ng vu� khi� cao c��p ta�i Lost Oasis."
#define STRMSG_120508_0008					"%s Ki�ch hoa�t c��a ha�ng thi��t bi� ta�i Lost Oasis."
#define STRMSG_120508_0009					"%s Ki�ch hoa�t c��a ha�ng the� ���c bi��t ta�i Lost Oasis."
#define STRMSG_120508_0010					"%s Ki�ch hoa�t c��a ha�ng vu� khi� ta�i Lost Oasis."
#define STRMSG_120508_0011					"%s Ki�ch hoa�t c��ng di�ch chuy��n bi� m��t ta�i Lost Oasis."

#define STRMSG_120712_0001					"18�� �̸� û�ҳ⿡�� ����Ǵ� ���ӽð� ������ �������� ���Ͽ�, %d �� �Ŀ� ������ ����˴ϴ�."		// 2012-07-11 by hskim, ������ �˴ٿ�

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ������ �ð��� %d�� ���ҽ��ϴ�."
#define STRMSG_121005_0002					"\\y��� �� PC�� �������� ����˴ϴ�."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� �ý��� ������ - ����� Ʈ���� ��������(�Ͻ�����)
#define STRMSG_121126_0001					"\\yL��nh: B��t ���u t�� th��i �i��m co� ca�c tr��n �a�nh gi��a 02 qu��c gia, ng���i ch�i ngay l��p t��c se� kh�ng th��c hi��n ����c ca�c hoa�t ���ng li�n quan ���n pha l�\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� ��������
#define STRMSG_121129_0001					"\\y��ڿ� ���Ͽ� �̵��� ���ѵ� ���� �Դϴ�.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ???? ??? ???
#define STRMSG_130121_0001					"\\cH�� th��ng �a� bi� chi��m gi�� b��i l��c l���ng NGC. Vi��c s� ta�n se� ����c th��c hi��n ngay l��p t��c."
#define STRMSG_130121_0002					"\\cDo tha�m:\\c \\rNGC Controller\\r �a� xa�c nh��n."
#define STRMSG_130121_0003					"\\cDo tha�m:\\c \\rNGC Controller\\r �a� bi� pha� hu�y."
#define STRMSG_130121_0004					"\\cChi� huy:\\c \\rGomora's\\r Gia�p n�ng l���ng �a� ki�ch hoa�t. Ti�u di��t \\rNGC Controllers\\r ��� v� hi��u ho�a no�!"
#define STRMSG_130121_0005					"\\cChi� huy:\\c \\rGomora's\\r Gia�p n�ng l���ng �a� m��t! T��n c�ng ngay!"
#define STRMSG_130121_0006					"\\cChi� huy:\\c \\rGomora\\r �a� bi� pha� hu�y! T��t ca� ti��n l�n!"
#define STRMSG_130121_0007					"\\cChi� huy:\\c \\rGomora\\r pha�i bi� ti�u di��t ���u ti�n."
#define STRMSG_130121_0008					"\\c[%s] ki�ch hoa�t b��i \\c\\rNGC Controller\\r qua� ta�i."
#define STRMSG_130121_0009					"\\y[H�� th��ng c�n c�� ti��n ���n NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ??? ??? - ???? ???? ??? ??
#define STRMSG_130422_0001					"\\y%s %d bi� gi��i ha�n t�� ���u Tr���ng. V��t ph��m �a� ����c g��i la�i va�o kho cu�a ba�n.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ?? ??? - STRMSG ??
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gThe� chuy��n da�ng gia�p �a� ����c th�m va�o B�� s�u t��p the� chuy��n da�ng gia�p cu�a ba�n.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gThe� chuy��n da�ng gia�p �a� ����c ki�ch hoa�t [%2d] l��n.\\g"
#define STRMSG_130531_0003					"\\g[\\g%s\\g]\\g \\gThe� chuy��n da�ng gia�p �a� �a�t gi��i ha�n s�� du�ng t��i �a. No� se� chuy��n tha�nh [%s].\\g"
#define STRMSG_130531_0004					"The� chuy��n da�ng gia�p cu�a ba�n �a� h��t ha�n va� ca�c chi� s�� se� bi� loa�i bo�. ���ng c� se� bi� tha�o ra."
#define STRMSG_130531_0005					"\\yKh�ng co� ���ng c� ����c s�� du�ng. Di�ch chuy��n t��c th��i v�� tha�nh ph��.\\y"
#define STRMSG_130531_0006					"\\gBa�n kh�ng th�� s�� du�ng the� chuy��n da�ng gia�p �ang ����c ki�ch hoa�t.\\g"
#define STRMSG_130531_0007					"\\gThe� chuy��n da�ng gia�p �a� bi� thay ���i.\\g"
#define STRMSG_130531_0008					"\\r[%s] The� chuy��n da�ng gia�p �a� h��t ha�n.\\r"
#define STRMSG_130531_0009					"\\yGia�p v��i the� chuy��n da�ng gia�p �a� ki�ch hoa�t kh�ng th�� ba�n.\\y"
#define STRMSG_130531_0010					"\\yLoa�i phi c� kh�ng phu� h��p.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ??? ??? ?? - STRMSG ??
#define STRMSG_130708_0001					"\\cChi� huy:\\c Gia�p n�ng l���ng NGC �a� ����c ki�ch hoa�t. Ti�u di��t \\rNGC Controllers\\r ��� v� hi��u ho�a gia�p n�ng l���ng cu�a \\rGomora\\r !"
#define STRMSG_130708_0002					"\\cChi� huy:\\c C�n c�� pho�ng ng�� qu�n s�� NGC �a� bi� ha�. B��t ���u t��n c�ng!"
#define STRMSG_130708_0003					"\\cDo tha�m:\\c \\rNGC Shield Generator\\r �a� trong t��m ng��m."
#define STRMSG_130708_0004					"\\cDo tha�m:\\c \\rNGC Shield Generator\\r �a� bi� ti�u di��t."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, ? ?? ????
#define STRMSG_130726_0001					"Nh�n v��t �a� �� trong qu��c gia."
#define STRMSG_130726_0002					"Nh�n v��t la� T��ng th��ng ho��c pho� T��ng th��ng, vi� v��y kh�ng th�� chuy��n qu��c gia."
#define STRMSG_130726_0003					"Nh�n v��t �� trong ha�m ���i, qu��c gia kh�ng th�� bi� thay ���i."
#define STRMSG_130726_0004					"Kh�ng co� nh�n v��t na�o r��i kho�i ��� chuy��n qu��c gia."
#define STRMSG_130726_0005					"Chuy��n qu��c gia th��t ba�i [AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"Chuy��n qu��c gia tha�nh c�ng [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Ta�i khoa�n kh�ng t��n ta�i."
#define STRMSG_130726_0008					"Ta�i khoa�n �a� ��ng nh��p, kh�ng th�� chuy��n qu��c gia."


// 2013-08-30 by bckim, ?????????
#define STRMSG_130830_0001					"\\y%s Bi� c��m bay vi� ���c quy��n cu�a la�nh �a�o qu��c gia.\\y"
#define STRMSG_130830_0002					"\\yBi� c��m bay vi� ���c quy��n cu�a la�nh �a�o qu��c gia.\\y"
#define STRMSG_130830_0003					"\\y%s Bi� c��m bay vi� ���c quy��n cu�a la�nh �a�o qu��c gia.\\y"
// End. 2013-08-30 by bckim, ?????????

// 2013-08-28 by bckim, ????? ????
#define STRMSG_130828_0001					"\\y[%s �a� go�p ph��n trong vi��c pha� hu�y \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s �a� kh��i x���ng l��n t��n c�ng ���u ti�n ch��ng la�i \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s �a� th��c hi��n ca�c cu��c t��n c�ng t��ng l��c ch��ng la�i \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s �a� th��c hi��n ���t t��n c�ng cu��i cu�ng v��i \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n �a� bi� �a�nh ba�i."
// End. 2013-08-28 by bckim, ????? ????

// 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???
#define STRMSG_130814_0001					"\\y[%s] �a� chi��n th��ng cu��c chi��n ta�i c�� �i��m chi��n l���c NGC.\\y"
// end 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
