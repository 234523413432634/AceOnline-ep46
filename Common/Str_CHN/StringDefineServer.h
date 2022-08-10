
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "������û������"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMEXE_0003 "�Զ�����ʧ��.\r\n������������Ϸ.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "���ط���������ʧ��"
	#define STRERR_S_ATUMEXE_0007 "�޷���ȡ�����ļ��Ĵ�С"
	#define STRERR_S_ATUMEXE_0008 "�������ظ����ļ�"
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "�޷��ҵ��ļ�"
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found. "
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "update completed"
	#define STRMSG_S_ATUMLAUNCHER_0001 "��ѡ�������"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "deleting files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "update completed(%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "ѡ�������ļ�"
	#define STRMSG_S_ATUMLAUNCHER_0007 "ѡ������·��"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading is canceled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "updating to v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "updating to v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Getting File Information %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "����������֤������"
	#define STRERR_S_ATUMLAUNCHER_0005 "����������ʧ��"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "������������Ϸ.\nURL: http://space.mgame.com/\n���°汾: "
	#define STRERR_S_ATUMLAUNCHER_0009 "�Զ�����ʧ��.\r\n������������Ϸ.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "���з������ǻ���״̬."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%sά����..."
	#define STRERR_S_ATUMLAUNCHER_0012 "���з���������ά��.���Ժ��ٵ�½."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
//	#define STRERR_S_ATUMLAUNCHER_0014 "ID, �������\n\n* ������beta���ԣ�ֻ����֤����Ҳſ��Ե�½"
	#define STRERR_S_ATUMLAUNCHER_0015 "��½���̴���"
	#define STRERR_S_ATUMLAUNCHER_0016 "δ�����û�ID"
	#define STRERR_S_ATUMLAUNCHER_0017 "���ʺ��ѵ�½"
	#define STRERR_S_ATUMLAUNCHER_0018 "F������û������"
	#define STRERR_S_ATUMLAUNCHER_0019 "I������û������"
	#define STRERR_S_ATUMLAUNCHER_0020 "����һʱ�ж�.\n\n���Ժ�����"
	#define STRERR_S_ATUMLAUNCHER_0021 "Ŀǰ�û�̫��.\n\n���Ժ��ٵ�½"
// 2013-05-22 by bckim, ĳ���� �޼����ڽ� ��Ÿ ���� �� ��� ���� 
	//#define STRERR_S_ATUMLAUNCHER_0022 "Your account is currently blocked.\nPeriod : %s\n\nConatact Customer Support at [ace.subagames.com/support_contact.aspx] for further details."
	#define STRERR_S_ATUMLAUNCHER_0022 "�ʺ��ѷ�ͣ.\n ʱ�� : %s\n\n����ѯACE online�ͻ�����"
	#define STRERR_S_ATUMLAUNCHER_0023 "�ͻ��˰汾��ͬ.\n\n������������Ϸ"
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "�޷��������ط�����"
	#define STRERR_S_ATUMLAUNCHER_0026 "�޷���ȡ�����ļ�(%s)�Ĵ�С"
	#define STRERR_S_ATUMLAUNCHER_0027 "�޷���ȡ�����ļ��Ĵ�С"
	#define STRERR_S_ATUMLAUNCHER_0028 "�޷����ظ����ļ�"
	#define STRERR_S_ATUMLAUNCHER_0029 "�����ļ�������"
	#define STRERR_S_ATUMLAUNCHER_0030 "ѡ��ķ���������ά��.���Ժ�����"
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "�޷��ҵ��ļ�."
	#define STRERR_S_ATUMLAUNCHER_0034 "�޷��ҵ�·��."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �̸� û�ҳ⿡�� ����Ǵ� ���ӽð� ������ �������� ���Ͽ�, ���� �ð����� ���� ������ �Ұ����մϴ�.\n\n�ڼ��� ������ ���̽��¶��� �����ͷ� ���ǹٶ��ϴ�."		// 2012-07-11 by hskim, ������ �˴ٿ�

// 2013-05-22 by bckim, ĳ���� �޼����ڽ� ��Ÿ ���� �� ��� ���� 
// 	#define STRMSG_S_050506		"\'%s\'s account is blocked presently.\n  Reason: %s\n  Period: %s~%s\n\nConatact Customer Support at [ace.subagames.com/support_contact.aspx] for further details."
	#define STRMSG_S_050506		"\'%s\'�ʺ��ѷ�ͣ.(����: %s, ʱ��: %s~%s) \n\n��ϸ�������ѯACE online�ͷ�����"
	#define STRMSG_S_050930		"������������Ϸ.\nURL: %s\n���°汾: "
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "��"
//	#define STRMSG_S_SCADMINTOOL_0001 "Ů"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d��, %d��"
//	#define STRMSG_S_SCADMINTOOL_0003 "ȷ��Ҫ�޸��ʺ���Ϣ��?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + '�� ʰȡ, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''' + l.PeerCharacterName + '''��� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '�� , ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''' + l.PeerCharacterName + '''�յ� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '�� , ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10)) + '���Ѷ���, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + ���ѹ���, ��ʣ Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + '���ѳ���, ��ʣ Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + '''��ɾ�� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '��, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + '''��ɾ�� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '��, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0014 "CAST(l.ChangeCount AS VARCHAR(10)) + '�������, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0015 "CAST(l.ChangeCount AS VARCHAR(10)) + '����ί��, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0016 "CAST(l.ChangeCount AS VARCHAR(10)) + '�����ҵ�, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '��'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'��Ϸʱ�� \' + atum.atum_GetHMSFromS(l.PlayTime) + \', �� \' + atum.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', ��Ϸʱ��: ' + atum.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' ����, �� \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "��ͻ"
//	#define STRMSG_S_SCADMINTOOL_0021 "����"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "ԭ����"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, ���Ե㻹ʣ: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(û��)"
//	#define STRMSG_S_SCADMINTOOL_0026 "��"
//	#define STRMSG_S_SCADMINTOOL_0027 "û��"
//	#define STRMSG_S_SCADMINTOOL_0028 "BUGʹ�����"
	#define STRMSG_S_SCADMINTOOL_0029 "�ʺŷ�ͣ"
	#define STRMSG_S_SCADMINTOOL_0030 "��ֹ����"
//	#define STRMSG_S_SCADMINTOOL_0031 "��½LOG"
//	#define STRMSG_S_SCADMINTOOL_0032 "���LOG"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item LOG"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s ������"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s ������,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "�ʺŷ�ͣ"
//	#define STRMSG_S_SCADMINTOOL_0037 "����    "
//	#define STRMSG_S_SCADMINTOOL_0038 "ֵ"
	#define STRMSG_S_SCADMINTOOL_0039 "Ҫ�����ͣ״̬��?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d��)"
	#define STRMSG_S_SCADMINTOOL_0041 "%dʤ %d��"
	#define STRMSG_S_SCADMINTOOL_0042 "ȷ��Ҫ�ж������Ժ�������?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s ����"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] �������� : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "�û���: %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] �յ�����Ϣ : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] ����� : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] FieldServer state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "��������������ֹ\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "�޷���ȡ�ʺ���Ϣ"
	#define STRERR_S_SCADMINTOOL_0001 "�ʺ���Ϣ�޸�ʧ��"
	#define STRERR_S_SCADMINTOOL_0002 "����������"
	#define STRERR_S_SCADMINTOOL_0003 "�������"
	#define STRERR_S_SCADMINTOOL_0004 "�������½��"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Serverû������"
	#define STRERR_S_SCADMINTOOL_0006 "Can not connect to PreServer !!"
//	#define STRERR_S_SCADMINTOOL_0007 "��֤ʧ��"			// 2006-04-11 by cmkwon, ע�ʹ���
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: ���������Э��."
	#define STRERR_S_SCADMINTOOL_0009 "�������û���"
	#define STRERR_S_SCADMINTOOL_0010 "����������"
	#define STRERR_S_SCADMINTOOL_0011 "����ֵ���ô��� : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "�ѳ�������½����\r\n\r\n���޸�����½���������������"
	#define STRERR_S_SCADMINTOOL_0013 "�޷�����Database"
	#define STRERR_S_SCADMINTOOL_0014 "�޷�����"
	#define STRERR_S_SCADMINTOOL_0015 "������"
	#define STRERR_S_SCADMINTOOL_0016 "���ڸ���"
	#define STRERR_S_SCADMINTOOL_0017 "�ѵ�½"
	#define STRERR_S_SCADMINTOOL_0018 "����ѡ���ɫ"
	#define STRERR_S_SCADMINTOOL_0019 "��Ϸ��"
	#define STRERR_S_SCADMINTOOL_0020 "�޷���ȡ"
	#define STRERR_S_SCADMINTOOL_0021 "�޷�����Database %s(%s:%d)"
	#define STRERR_S_SCADMINTOOL_0022 "��ӵ���ʧ��"
	#define STRERR_S_SCADMINTOOL_0023 "Ѱ�ҷ�ͣ�ʺ�ʧ��"
	#define STRERR_S_SCADMINTOOL_0024 "Ϊ���޸������ж�����!"
	#define STRERR_S_SCADMINTOOL_0025 "�������SPI(Ǯ)"
	#define STRERR_S_SCADMINTOOL_0026 "ѡ��ĵ����Ѵ��ڣ����޸�����"
	#define STRERR_S_SCADMINTOOL_0027 "Ѱ�ҵ��ߴ���"
	#define STRERR_S_SCADMINTOOL_0028 "��ɫ���е� SPI(Ǯ)����ɾ��"
	#define STRERR_S_SCADMINTOOL_0029 "Ҫɾ��������?"
	#define STRERR_S_SCADMINTOOL_0030 "ɾ������ʧ��"
	#define STRERR_S_SCADMINTOOL_0031 "�޸ĵ���ʧ��"
	#define STRERR_S_SCADMINTOOL_0032 "�������ʺ�"
	#define STRERR_S_SCADMINTOOL_0033 "�ʺŲ�����(���������ʺŷ�ͣ)"
	#define STRERR_S_SCADMINTOOL_0034 "�ʺŻ��߽�ɫ������"
	#define STRERR_S_SCADMINTOOL_0035 "��ɫ��Ϣ���մ���"
	#define STRERR_S_SCADMINTOOL_0036 "��������ؽ�ɫ"
	#define STRERR_S_SCADMINTOOL_0037 "��ɫ���´���"
	#define STRERR_S_SCADMINTOOL_0038 "��ɫ��Ϣ�ɹ�����"
	#define STRERR_S_SCADMINTOOL_0039 "��ѡ�����"
	#define STRERR_S_SCADMINTOOL_0040 "��ѡ���������"
	#define STRERR_S_SCADMINTOOL_0041 "��ص��߿�������5������"
	#define STRERR_S_SCADMINTOOL_0042 "��������Ϣ"
	#define STRERR_S_SCADMINTOOL_0043 "�޷����͹���"
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Serverû������"
	#define STRERR_S_SCADMINTOOL_0046 "Field Serverû������"
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"

	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "�ʺ���"
//	#define STRMSG_S_SCAT_COLNAME_0001 "����"
//	#define STRMSG_S_SCAT_COLNAME_0002 "ǰ��"
//	#define STRMSG_S_SCAT_COLNAME_0003 "��ʼ����"
//	#define STRMSG_S_SCAT_COLNAME_0004 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0005 "������"
//	#define STRMSG_S_SCAT_COLNAME_0006 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0007 "����"
//	#define STRMSG_S_SCAT_COLNAME_0008 "LOG����"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0011 "��ɫ��"
//	#define STRMSG_S_SCAT_COLNAME_0012 "λ��"
//	#define STRMSG_S_SCAT_COLNAME_0013 "����"
//	#define STRMSG_S_SCAT_COLNAME_0014 "����"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "���б��"
//	#define STRMSG_S_SCAT_COLNAME_0017 "����"
//	#define STRMSG_S_SCAT_COLNAME_0018 "���߱��"
//	#define STRMSG_S_SCAT_COLNAME_0019 "ǰ׺"
//	#define STRMSG_S_SCAT_COLNAME_0020 "��׺"
	#define STRMSG_S_SCAT_COLNAME_0021 "��װ"
//	#define STRMSG_S_SCAT_COLNAME_0022 "����"
//	#define STRMSG_S_SCAT_COLNAME_0023 "�;ö�"
//	#define STRMSG_S_SCAT_COLNAME_0024 "����ʱ��"
	#define STRMSG_S_SCAT_COLNAME_0025 "δ��װ"
//	#define STRMSG_S_SCAT_COLNAME_0026 "�ֿ�"
//	#define STRMSG_S_SCAT_COLNAME_0027 "����"
//	#define STRMSG_S_SCAT_COLNAME_0028 "��ͼ"
//	#define STRMSG_S_SCAT_COLNAME_0029 "����"
//	#define STRMSG_S_SCAT_COLNAME_0030 "�Ա�"
//	#define STRMSG_S_SCAT_COLNAME_0031 "����"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Ȩ��"
//	#define STRMSG_S_SCAT_COLNAME_0033 "ս������"
//	#define STRMSG_S_SCAT_COLNAME_0034 "�ȼ�"
//	#define STRMSG_S_SCAT_COLNAME_0035 "��ߵȼ�"
//	#define STRMSG_S_SCAT_COLNAME_0036 "����ֵ"
//	#define STRMSG_S_SCAT_COLNAME_0037 "���ٵļ���ֵ"
//	#define STRMSG_S_SCAT_COLNAME_0038 "�Զ��������Ե�����"
//	#define STRMSG_S_SCAT_COLNAME_0039 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0040 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0041 "ȼ�ϲ���"
//	#define STRMSG_S_SCAT_COLNAME_0042 "��Ӧ����"
//	#define STRMSG_S_SCAT_COLNAME_0043 "���ܲ���"
//	#define STRMSG_S_SCAT_COLNAME_0044 "�رܲ���"
//	#define STRMSG_S_SCAT_COLNAME_0045 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0046 "����"
//	#define STRMSG_S_SCAT_COLNAME_0047 "���"
//	#define STRMSG_S_SCAT_COLNAME_0048 "�ܵ�½ʱ��"
//	#define STRMSG_S_SCAT_COLNAME_0049 "����ʱ��"
//	#define STRMSG_S_SCAT_COLNAME_0050 "���յ�½ʱ��"
//	#define STRMSG_S_SCAT_COLNAME_0051 "����"
//	#define STRMSG_S_SCAT_COLNAME_0052 "ȫ��"
	#define STRMSG_S_SCAT_COLNAME_0053 "�Զ���(1-1��)"
	#define STRMSG_S_SCAT_COLNAME_0054 "ת�ֻ�ǹ��(1-1��)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "˫����(1-1��)" // 2005-08-01 by hblee : grenade -> ���ΪDuelist.
	#define STRMSG_S_SCAT_COLNAME_0056 "������(1-1��)"
	#define STRMSG_S_SCAT_COLNAME_0057 "��ǹ��(1-2��)"
	#define STRMSG_S_SCAT_COLNAME_0058 "����ǹ��(1-2��)"
	#define STRMSG_S_SCAT_COLNAME_0059 "������(1-2��)"
	#define STRMSG_S_SCAT_COLNAME_0060 "ͻ����(1-2��)"
	#define STRMSG_S_SCAT_COLNAME_0061 "�����(2-1��)"
	#define STRMSG_S_SCAT_COLNAME_0062 "������(2-1��)"
	#define STRMSG_S_SCAT_COLNAME_0063 "������(2-1��)"
	#define STRMSG_S_SCAT_COLNAME_0064 "�����(2-1��)"
	#define STRMSG_S_SCAT_COLNAME_0065 "������(2-2��)"
	#define STRMSG_S_SCAT_COLNAME_0066 "αװ��(2-2��)"
	#define STRMSG_S_SCAT_COLNAME_0067 "�̶���(2-2��)"
	#define STRMSG_S_SCAT_COLNAME_0068 "�ջ���(2-2��)"
	#define STRMSG_S_SCAT_COLNAME_0069 "������"
	#define STRMSG_S_SCAT_COLNAME_0070 "����װ����"
	#define STRMSG_S_SCAT_COLNAME_0071 "������"
	#define STRMSG_S_SCAT_COLNAME_0072 "������"
	#define STRMSG_S_SCAT_COLNAME_0073 "��Ƭ��"
	#define STRMSG_S_SCAT_COLNAME_0074 "������"
	#define STRMSG_S_SCAT_COLNAME_0075 "̹����"
	#define STRMSG_S_SCAT_COLNAME_0076 "�ӵ���"
	#define STRMSG_S_SCAT_COLNAME_0077 "������"
	#define STRMSG_S_SCAT_COLNAME_0078 "�״���"
	#define STRMSG_S_SCAT_COLNAME_0079 "������"
	#define STRMSG_S_SCAT_COLNAME_0080 "����ǹ��"
	#define STRMSG_S_SCAT_COLNAME_0081 "�����ƻ���ֹ��"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "������"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "�����ǹ��"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "ȫ������"
//	#define STRMSG_S_SCAT_COLNAME_0082 "ȫ��������"
//	#define STRMSG_S_SCAT_COLNAME_0083 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0084 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0085 "������ IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "��ǰ�����"
//	#define STRMSG_S_SCAT_COLNAME_0087 "������״̬"
//	#define STRMSG_S_SCAT_COLNAME_0088 "group������"
//	#define STRMSG_S_SCAT_COLNAME_0089 "field������"
//	#define STRMSG_S_SCAT_COLNAME_0090 "�޷���ȡ"
//	#define STRMSG_S_SCAT_COLNAME_0091 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0092 "����"
//	#define STRMSG_S_SCAT_COLNAME_0093 "������"
	#define STRMSG_S_SCAT_COLNAME_0094 "GM"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '��, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "����list\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- ���ݵ��ʺ�list ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  �ʺ�: \'%s\', ԭ������: \'%s\', ��ʱ����: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  �ʺ�: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "��ѡ������� Version���ļ���"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "�ļ��ɹ�����.\r\n\r\nDB ��Ϣ: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  ����) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -�ǻ���) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "�����������ݳɹ�����"
//	#define STRMSG_S_SCMONITOR_0011 "����״̬�ɹ���Ӧ"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  ����)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -�ǻ���)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "��ѷ�����������ֹͣ"
//	#define STRMSG_S_SCMONITOR_0017 "��ѷ����������ѿ�ʼ"
//	#define STRMSG_S_SCMONITOR_0018 "field������û������"
//	#define STRMSG_S_SCMONITOR_0019 "��Ľ��� Field Server��?"
//	#define STRMSG_S_SCMONITOR_0020 "���°汾list��Ϣ(��� 1492 Bytes)\r\n\r\n    �汾list����[%3d], ���ݴ�С[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "��Ľ��� Pre Server��?"
//	#define STRMSG_S_SCMONITOR_0022 "���Ҫ����IM Server��?"
//	#define STRMSG_S_SCMONITOR_0023 "���Ҫ����NPC Server��?"
//	#define STRMSG_S_SCMONITOR_0024 "%Y�� %m�� %d�� %Hʱ %M�� %S��"
//	#define STRMSG_S_SCMONITOR_0025 "û�л(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "����(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "��֪���(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "�´�ռ��ս����ʱ��"
//	#define STRMSG_S_SCMONITOR_0029 "�´�ռ��ս����ʱ��"
//	#define STRMSG_S_SCMONITOR_0030 "ռ�����"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> ����ɹ�\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> ����ʧ��\r\n"
//	#define STRERR_S_SCMONITOR_0002 "DB�޷�����"
//	#define STRERR_S_SCMONITOR_0003 "���������Version "
//	#define STRERR_S_SCMONITOR_0004 "������Ҫѹ�����ļ�������"
//	#define STRERR_S_SCMONITOR_0005 "������Ҫ��ʾ���ļ�������"
//	#define STRERR_S_SCMONITOR_0006 "�����뿪ʼ�汾"
//	#define STRERR_S_SCMONITOR_0007 "����������汾"
//	#define STRERR_S_SCMONITOR_0008 "��ѡ��Ҫ��ʾ������ Zip�ļ���"
//	#define STRERR_S_SCMONITOR_0009 "�޷����ӷ�����"
//	#define STRERR_S_SCMONITOR_0010 "��ѡ�������!"
//	#define STRERR_S_SCMONITOR_0011 "�޷�����DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "���°汾list̫��.(�汾list����[%3d], ���ݴ�С[%4dBytes])\r\n\r\n    ������汾list."
//	#define STRERR_S_SCMONITOR_0014 "�Գ�ȥ�Ĺ���.\r\n���ù�����."
//	#define STRERR_S_SCMONITOR_0015 "���ǳ���ռ��ս��ͼ"
//	#define STRERR_S_SCMONITOR_0016 "��������EDIT����"
//	#define STRERR_S_SCMONITOR_0017 "�ϴ����Ѵ��ڵ��ļ�"

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "�ѵ�½Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Server[%15s:%4d]��ֹ����. ��������\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to PreServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "�ѵ�½Pre Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Pre Server[%15s:%4d]��ֹ����. ��������\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to  IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "�ѵ�½IM Server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Server[%15s:%4d]��ֹ����. ��������\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "��ص��߲�����"
	#define STRMSG_S_F2DBQUERY_0002 "'%s'�������ϯ,���õĵ���"
	#define STRMSG_S_F2DBQUERY_0003 "��֧��. F5�򿪵�����ȷ��"
	#define STRMSG_S_F2DBQUERY_0004 "�����%s(%d)����"
	#define STRMSG_S_F2DBQUERY_0005 "��������ص���."
	#define STRMSG_S_F2DBQUERY_0006 "���߹���ʧ��"

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  ����ռ��ս��ʼ : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  �μӾ��� : GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  ����ռ��ս���ﱬ�� : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		  �˺��� ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  ����ռ��ս : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) ռ��սʱ��(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d���Ӻ� \"%s\" ��ʼ����ռ��ս."
	#define STRMSG_S_F2CITYWAR_0007 "%d���Ӻ� \"%s\" ��������ռ��ս."
	#define STRMSG_S_F2CITYWAR_0008 "����ռ��ս(%s) �ٻ����� : NPC ռ��"
	#define STRMSG_S_F2CITYWAR_0009 "����ռ��ս(%s) �ٻ��� : %s ����ռ��"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"Ŀǰռ�� \"%s\""
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"Ŀǰռ�� \"%s\""

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "��������ʧ��"
	#define STRMSG_S_F2QUEST_0001 "����û������\r\n"
//	#define STRMSG_S_F2QUEST_0002 "���� \'%30s\' ��� %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "���ò����÷�����! \r\n\r\nLoadFieldServerDataDebug() ϣ����ȥ! "
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: ��%d %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: ��%s %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1��"
	#define STRMSG_S_F2NOTIFY_0003 "2��"
	#define STRMSG_S_F2NOTIFY_0004 "��1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "��2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "�������������! ����ѯ����Ա!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1��: %4.1f vs %4.1f -> ���ٹ��������� %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s ʧ��, ������(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s ʧ��, ������(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s ʧ��, ������(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2��: %4.1f vs %4.1f -> �˺�%2.2f%%����(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "��%s->%s %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "��%s->%s �յ�%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "��%s->%s(%d, HP:%5.2f) %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "��%s->%s �յ�%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "αװʧ��: �����ʲ��� > %d"
	#define STRMSG_S_F2NOTIFY_0017 "��ʣαװ[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "û���ӵ���Ϣ. ����ѯ����Ա."
	#define STRMSG_S_F2NOTIFY_0019 "�������ӵ��Ŀھ���Ϣ. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "�ӵ�����Ϣ. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "���ڴ���,�޷�����"
	#define STRMSG_S_F2NOTIFY_0022 "������,�޷�����"
	#define STRMSG_S_F2NOTIFY_0023 "�����,�޷�����"
	#define STRMSG_S_F2NOTIFY_0024 "��ͼ��������! ����ѯ����Ա!"
	#define STRMSG_S_F2NOTIFY_0025 "��ͼ��������! ����ѯ����Ա! %d %d��û��Ŀ��INDEX !\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "���ս��û�н���,�޷�����"
	#define STRMSG_S_F2NOTIFY_0027 "����(%04d) ���ܴ��� at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "  1 -> ��ɫ %10s�ܵ� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> ��ɫ %10s�� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> ��ɫ %10s�� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> ��ɫ %10s�� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0032 "  2 -> ��ɫ %10s�ܵ� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> ��ɫ %10s�� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> ���� %3d�� %5.2f(%d)�˺�"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> ��ɫ %10s �ܵ�%5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> ��ɫ %10s�ܵ� %5.2f dummy�˺�"
	#define STRMSG_S_F2NOTIFY_0037 "  2 -> ���� %3d�� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0038 "  MINE -> ��ɫ %10s�ܵ� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0039 "  MINE -> ��ɫ %10s�ܵ� %5.2fdummy�˺�"
	#define STRMSG_S_F2NOTIFY_0040 "  MINE -> ���� %10s�ܵ� %5.2f�˺�"
	#define STRMSG_S_F2NOTIFY_0041 "�ѳɹ���ʼ�����Ե�"
	#define STRMSG_S_F2NOTIFY_0042 "������ʱ��,�޷�ʹ��"
	#define STRMSG_S_F2NOTIFY_0043 "û��ENCHANT_INFO "
	#define STRMSG_S_F2NOTIFY_0044 "���������ѳɹ�"
	#define STRMSG_S_F2NOTIFY_0045 "����������ʧ��"
	#define STRMSG_S_F2NOTIFY_0046 "û����������"
	#define STRMSG_S_F2NOTIFY_0047 "�ȴ�������"
	#define STRMSG_S_F2NOTIFY_0048 "���Ժ�����"
	#define STRMSG_S_F2NOTIFY_0049 "�Լ����߶Է����Ǿ��ų�."
	#define STRMSG_S_F2NOTIFY_0050 "���ھ���ս����"
	#define STRMSG_S_F2NOTIFY_0051 "�������ų�����ͬһ����ͼ��"
	#define STRMSG_S_F2NOTIFY_0052 "���ж�Ա����ͬһ����ͼ��"
	#define STRMSG_S_F2NOTIFY_0053 "���ж�Ա����ͬһ����ͼ��"
	#define STRMSG_S_F2NOTIFY_0054 "�����ھ���"
	#define STRMSG_S_F2NOTIFY_0055 "�����˺ͱ������˲�ͬ"
	#define STRMSG_S_F2NOTIFY_0056 "�Լ���Է����Ǿ��ų�"
	#define STRMSG_S_F2NOTIFY_0057 "�������ų�����ͬһ����ͼ��"
	#define STRMSG_S_F2NOTIFY_0058 "�����ھ���"
	#define STRMSG_S_F2NOTIFY_0059 "�����˺ͱ������˲�ͬ"
	#define STRMSG_S_F2NOTIFY_0060 "�Լ���Է����Ǿ��ų�"
	#define STRMSG_S_F2NOTIFY_0061 "����ռ��ս���سɹ�"
	#define STRMSG_S_F2NOTIFY_0062 "�������ô���. ����ѯ����Ա."
	#define STRMSG_S_F2NOTIFY_0063 "���λ�ò��ܰ�װ����(%s)"
	#define STRMSG_S_F2NOTIFY_0064 "���治�ܿ�"
	#define STRMSG_S_F2NOTIFY_0065 "�ƶ�����: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "����ĵ���: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d) ���ɴ��� at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "��ͼ��Ϣ�쳣!!!����ѯ����Ա!!!"
	#define STRMSG_S_F2NOTIFY_0069 "û����ش���Ŀ��"
	#define STRMSG_S_F2NOTIFY_0070 "���߹������.����ѯ����Ա"
	#define STRMSG_S_F2NOTIFY_0071 "Ҫ����ļ��ܱȵ�ǰ�ļ��ܵȼ��ͻ�һ��"
	#define STRMSG_S_F2NOTIFY_0072 "���ܹ��������ߴ���"
	#define STRMSG_S_F2NOTIFY_0073 "���۵��ߴ���.����ѯ����Ա"
	#define STRMSG_S_F2NOTIFY_0074 "������ߴ���.����ѯ����Ա"
	#define STRMSG_S_F2NOTIFY_0075 "\'�շѵ���\'�ѹ���."
	#define STRMSG_S_F2NOTIFY_0076 "  ����Ŀ¼ : \'%s(%d��)\'"
	#define STRMSG_S_F2NOTIFY_0077 "�Ѽ������."
	#define STRMSG_S_F2NOTIFY_0078 "���Ƕӳ�,��ô����?"
	#define STRMSG_S_F2NOTIFY_0079 "���ڽ��б��ս,�޷�����"
	#define STRMSG_S_F2NOTIFY_0080 "��֧���ռ����ж�Ա��Ϣ!"
	#define STRMSG_S_F2NOTIFY_0081 "��ͼ���Ϣ�쳣!!! ����ѯ����Ա!!!"
	#define STRMSG_S_F2NOTIFY_0082 "���ܽ��׵��ʺ�"
	#define STRMSG_S_F2NOTIFY_0083 "%s����װ����."
	#define STRMSG_S_F2NOTIFY_0084 "���ƶ�����: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "�û�: "
	#define STRMSG_S_F2NOTIFY_0086 "���ɲ鿴20��."
	#define STRMSG_S_F2NOTIFY_0087 "û������û�(%s)."
	#define STRMSG_S_F2NOTIFY_0088 "û�м������"
	#define STRMSG_S_F2NOTIFY_0089 "Ŀǰʱ��: %d:%d, ��Ϸ���ʱ��: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "���ʱ��: %d:%d, ���� �ð�: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "�޷�����NPC������"
	#define STRMSG_S_F2NOTIFY_0092 "(%d)���߲�����"
	#define STRMSG_S_F2NOTIFY_0093 "����Countable Item����Ϊ10��"
	#define STRMSG_S_F2NOTIFY_0094 "��ͼ \'%s\'��ȫ����������: %d��"
	#define STRMSG_S_F2NOTIFY_0095 "��ͼ%s %s ͬʱ��������: %d�� - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "��ͼ%s %s ͬʱ��������: %d�� - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "��ǰ��ͼƵ��: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "û���ӵ���Ϣ. ����ѯ����Ա."
	#define STRMSG_S_F2NOTIFY_0099 "�ӵ��ھ���Ϣ������. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "û���ӵ���Ϣ. ����ѯ����Ա."
	#define STRMSG_S_F2NOTIFY_0101 "�ӵ��ھ���Ϣ������. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "û������û�(%s)"
	#define STRMSG_S_F2NOTIFY_0103 "����û�(%s)������״̬"
	#define STRMSG_S_F2NOTIFY_0104 "û�����(%s)�û�"
	#define STRMSG_S_F2NOTIFY_0105 "������Ϊһ���ʺ�"
	#define STRMSG_S_F2NOTIFY_0106 "һ���ʺ��ѽ��"
	#define STRMSG_S_F2NOTIFY_0107 "������Ϊ�޵�(�������˺�)"
	#define STRMSG_S_F2NOTIFY_0108 "�ѽ���޵�(�������˺�)"
	#define STRMSG_S_F2NOTIFY_0109 "�������� %5.0f%% ʿ����"
	#define STRMSG_S_F2NOTIFY_0110 "�������°�װʱ��ʼ��"
	#define STRMSG_S_F2NOTIFY_0111 "�������°�װʱ��ʼ��"
	#define STRMSG_S_F2NOTIFY_0112 "û������û�(%s)"
	#define STRMSG_S_F2NOTIFY_0113 "�ѽ��͸������"
	#define STRMSG_S_F2NOTIFY_0114 "�Ѽ���͸������"
	#define STRMSG_S_F2NOTIFY_0115 "%s û�н��л"
	#define STRMSG_S_F2NOTIFY_0116 "%s ���ʼ(����:%4.2f, �ʱ��:%3d����)"
	#define STRMSG_S_F2NOTIFY_0117 "������Ϊһ��premium�ʺ�"
	#define STRMSG_S_F2NOTIFY_0118 "����premium�ʺ�ʧ��"
	#define STRMSG_S_F2NOTIFY_0119 "����premium�ʺ�"
	#define STRMSG_S_F2NOTIFY_0120 "���ǳ���ռ��ս��ͼ"
	#define STRMSG_S_F2NOTIFY_0121 "�޷���ʼ����ռ��ս"
	#define STRMSG_S_F2NOTIFY_0122 "�޷���������ռ��ս"
	#define STRMSG_S_F2NOTIFY_0123 "�ѳ�ʼ��Ǳ��״̬"
	#define STRMSG_S_F2NOTIFY_0124 "Ǳ��״̬"
	#define STRMSG_S_F2NOTIFY_0125 "��Ч�ĵ�ͼ"
	#define STRMSG_S_F2NOTIFY_0126 "������Happy Our� [�ʱ��:%4d����)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Our�����"
	#define STRMSG_S_F2NOTIFY_0128 "  1 -> ������ %3d�ܵ� %5.2f��stealth��"
	#define STRMSG_S_F2NOTIFY_0129 "  1�� -> ������ %3d�ܵ� %5.2f�˺�(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "��½%s Ȩ��"
	#define STRMSG_S_F2NOTIFY_0131 "  ����������ֹ %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "  ERROR@CharacterGameEndRoutine(): �����Աʧ��! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' �ɹ�: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' �ɹ�: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: ��ֹͣ!"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR: ����ѯ����Ա! �̵���۱�������!"
	#define STRMSG_S_F2NOTIFY_0137 "%s��ɾ��"
	#define STRMSG_S_F2NOTIFY_0138 "��ǰƵ��û�м���,�������������"
	#define STRMSG_S_F2NOTIFY_0139 "ֹͣ. ��ʹ������Ƶ��"
	#define STRMSG_S_F2NOTIFY_0140 "  Warp Obj.[%s,%2d��]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "��ʱ %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "ֹͣ�Զ��ָ�HP "
	#define STRMSG_S_F2NOTIFY_0143 "���ǿ�����½�ĵ��� HP�Զ��ָ�ֹͣ"
	#define STRMSG_S_F2NOTIFY_0144 "Ӧ�� HP 5.2f �ָ�"
	#define STRMSG_S_F2NOTIFY_0145 "�Զ��ָ�HP����ֹ(ʣ��ʱ��: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "�Զ��ָ���������ֹ(ʣ��ʱ��: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "�Զ��ָ�ȼ������ֹ(ʣ��ʱ��: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s ��ѽ���."
	#define STRMSG_S_F2NOTIFY_0149 "%s ������� (����:%4.2f, ʣ��ʱ��:%3d����)"
	#define STRMSG_S_F2NOTIFY_0150 "û����������"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	����ֵ�������(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "  ��Ч��Game Start��Ϣ���� ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "  ��Ч��Game Start��Ϣ���� ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "  WARP(%04d) ���ɴ��� at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "��ͼ���Ϣ�쳣!!! ����ѯ����Ա!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "  EVENT(%d) ���ɴ��� at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "��ͼ���Ϣ�쳣!!! ����ѯ����Ա!!! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "  WARP ���ɴ��� at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "  EVENT(%d) ���ɴ���(�ӳ�) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "  WARP(%04d) ���ɴ��� at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "  EVENT(%d) ���ɴ��� at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "  WARP ���ɴ��� at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "���鴫��ʧ��: %s -> ����: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "  WARP(%04d) ���ɴ��� at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "  %s -> ����ظ� OK��!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "����û������.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "  WARP(%s) ���ɴ��� at HandleAdminCommands(), /�ƶ�, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "  WARP(%s) ���ɴ��� at HandleAdminCommands(), /����, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "  FATAL ERROR: �����ڻ�Ա��field�����������Խ��մ���Ϣ. check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "  WARP(%04d) ���ɴ��� at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "  WARP(%s) �����Դ��� at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "����ֵ"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "����ֵ�ָ�"
	#define STRMSG_S_F2EVENTTYPE_0003 "ʰȡ����"
	#define STRMSG_S_F2EVENTTYPE_0004 "ʰȡϡ�е���"
	#define STRMSG_S_F2EVENTTYPE_0005 "δ֪�"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "������Pre Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Pre Server[%15s:%4d]��������ֹ.������.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'�Ѵ��ڵľ�������"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'�Ѽ������"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'�Ѵ��ڵ��þ�������"
	#define STRMSG_S_I2NOTIFY_0003 "�������ʧ�� - ����ѯ����Ա!"
	#define STRMSG_S_I2NOTIFY_0004 "���� '%s'�ѵ�½"
	#define STRMSG_S_I2NOTIFY_0005 "������ǰ�Ķ���"
	#define STRMSG_S_I2NOTIFY_0006 "�������鲻����"
	#define STRMSG_S_I2NOTIFY_0007 "�����¼������"
	#define STRMSG_S_I2NOTIFY_0008 "�Ѽ���Ķ���."
	#define STRMSG_S_I2NOTIFY_0009 "  Fatal Error: ��̵Ķ������! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "��Ա״̬����"
	#define STRMSG_S_I2NOTIFY_0011 "��Ա�Ѽ������"
	#define STRMSG_S_I2NOTIFY_0012 "�Է��Ѽ������"
	#define STRMSG_S_I2NOTIFY_0013 "�޷������Լ�"
	#define STRMSG_S_I2NOTIFY_0014 "����������״̬"
	#define STRMSG_S_I2NOTIFY_0015 "�ѳ�����������"
	#define STRMSG_S_I2NOTIFY_0016 "������������״̬"
	#define STRMSG_S_I2NOTIFY_0017 "���ų��������˳�"
	#define STRMSG_S_I2NOTIFY_0018 "���ڽ��о���ս,�޷��˳�����"
	#define STRMSG_S_I2NOTIFY_0019 "���ڽ��о���ս,�޷�������Ŷ�Ա"
	#define STRMSG_S_I2NOTIFY_0020 "���ų��޷����"
	#define STRMSG_S_I2NOTIFY_0021 "���ڽ��о���ս"
	#define STRMSG_S_I2NOTIFY_0022 "���ܸ���Ϊͬһ������"
	#define STRMSG_S_I2NOTIFY_0023 "���ܸ������ֵ�״̬"
	#define STRMSG_S_I2NOTIFY_0024 "���ܸ�����־��״̬"
	#define STRMSG_S_I2NOTIFY_0025 "���ܱ���׼���״̬"
	#define STRMSG_S_I2NOTIFY_0026 "�׼��ظ�"
	#define STRMSG_S_I2NOTIFY_0027 "�����Ա�����ų��׼�"
	#define STRMSG_S_I2NOTIFY_0028 "�����Ա�����ų��Ľ׼�"
	#define STRMSG_S_I2NOTIFY_0029 "ȫ���û�: %d�� (��ʾ��%d��)"
	#define STRMSG_S_I2NOTIFY_0030 "��Ӫ����Ϣ�б������"
	#define STRMSG_S_I2NOTIFY_0031 "��Ӫ����Ϣ�б��ѳ�ȥ"
	#define STRMSG_S_I2NOTIFY_0032 "������ IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "������Ⱥ \'%s\'��ȫ����������: %d��"
	#define STRMSG_S_I2NOTIFY_0034 "���Ҫ����������(%s)��? ����: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'û�н�����Ϸ "
	#define STRMSG_S_I2NOTIFY_0036 "ȫ���û���: %d�� (ֻ��ʾ%d��)"
	#define STRMSG_S_I2NOTIFY_0037 "/���� %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "û����ؾ���"
	#define STRMSG_S_I2NOTIFY_0039 "����ж����Ļ�!"
	#define STRMSG_S_I2NOTIFY_0040 "���Ļ����ж�!"
	#define STRMSG_S_I2NOTIFY_0041 "û�м������"
	#define STRMSG_S_I2NOTIFY_0042 "����(%d)��Ч"
	#define STRMSG_S_I2NOTIFY_0043 "�������������(%s)"
	#define STRMSG_S_I2NOTIFY_0044 "Field Server��Ч"
	#define STRMSG_S_I2NOTIFY_0045 "��������ص�ͼ(%s)"
	#define STRMSG_S_I2NOTIFY_0046 "������ %d���ӽ�ֹ����״̬!!"
	#define STRMSG_S_I2NOTIFY_0047 "���ý�ֹ���� : '%10s', %3d����"
	#define STRMSG_S_I2NOTIFY_0048 "�����ֹ����״̬"
	#define STRMSG_S_I2NOTIFY_0049 "�����ֹ���� : '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(�ʺ�: %s, ��ͼ: %d(%d), �ȼ�: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "����"
	#define STRMSG_S_I2NOTIFY_0052 "û����ع���."

	#define STRMSG_S_IMSERVER_050607_0001	"û����ص�ͼ."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Field Server������.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Field Server[%15s:%4d]��������ֹ. ������.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							�����Ŀ��û�г�ͻ\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "�ٻ�����ռ��ս����(%10s) \r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "�����"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%s �ʺ�(%s)�ѵ�½. IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "�ɹ�"
	#define STRMSG_S_P2PRENOTIFY_0002 "ʧ��"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR] �ʺ���Ϣ��Ӵ���, AccountName(%s)  privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"����,���ǿͷ�����"
	#define STRMSG_SCAT_051115_0002		"����9�㵽11��ACE onlineͣ��ά��"
	#define STRMSG_SCAT_051115_0003		"���ƶ�����ȫ�ĵط��������Ϸ."
	#define STRMSG_SCAT_051115_0004		"���ȴ�NPC��������ʼ��ֹ"
	#define STRMSG_SCAT_051115_0005		"���ڿ�ʼACE onlineͣ��ά��"
	#define STRMSG_SCAT_051115_0006		"ACE onlineף�����"
	#define STRMSG_SCAT_051115_0007		"�Ժ����ͣ��ά��"
	#define STRMSG_SCAT_051115_0008		"ά��ʱ����120����."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"͸��״̬: ��ҿ�����, ������������ʹ��"
	#define STRMSG_060509_0001			"�޵�״̬: �����˺�"
	#define STRMSG_060509_0002			"Ǳ��ģʽ: ���ᱻ�ȹ��͹��﹥��"

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you momentarily."
	#define	STRMSG_060526_0001			"�޷������Զ�����.\r\n\r\n��ҳ(%s) ������ҳ���ֶ����ز��������½.\r\n\r\n    Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"��ǰ�����IDû�е�½\r\n ID���������������."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"��ǰ��������ά��. ����������ο���ҳ."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"�ͻ��˰汾��ͬ.\r\n  ����ҳ�ֶ����ز������������°�װ�ͻ���."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"��%s����."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000			"��ʼ���������Ⱥ DB(atum2_db_20) ��Ҫ�����������Ⱥ."
	#define STRMSG_070410_0001			"ȷ��Ҫ��ʼ��������� DB(atum2_db_20)��? [��֤����:%d]"
	#define STRMSG_070410_0002			"�ѳ�ʼ��������� DB(atum2_db_20)."
	#define STRMSG_070410_0003			"��ʼ��������� DB(atum2_db_20)ʧ��!!"
	#define STRMSG_070410_0004			"��ɸ���'%s'����Ϣ��������� DB(atum2_db_20)."
	#define STRMSG_070410_0005			"'%s'����Ϣ���Ƶ�������� DB(atum2_db_20)ʧ�� - ��ɫ������ !!"
	#define STRMSG_070410_0006			"'%s'����Ϣ���Ƶ�������� DB(atum2_db_20)ʧ�� - ���������Ѵ����ʺŵĽ�ɫ !!"
	#define STRMSG_070410_0007			"'%s'����Ϣ���Ƶ�������� DB(atum2_db_20)ʧ�� - ���DB���� !!"
	#define STRMSG_070410_0008			"'%s'����Ϣ���Ƶ�������� DB(atum2_db_20)ʧ�� - δ֪(%d)!!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, �ػ� ���ڿ� 
	// 2007-07-24 by cmkwon, ��ó���� 800*600 �ػ� ���� - �޺��ڽ� ��Ʈ�� �ʿ� ����
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (��)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (��)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (��)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (��)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (��)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (��)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 ����(��)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (��)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (��)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (��)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (��)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (��)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (��)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 ����(��)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (��)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (��)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (��)"

// 2007-06-15 by dhjin, ���� ���� ��Ʈ��
#define STRMSG_070615_0000				"��͸��״̬���޷���ս."
#define STRMSG_070615_0001				"�޷���ս."
#define STRMSG_070620_0000				"һ�������޷���ս."

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRMSG_S_F2EVENTTYPE_0006		"ս������"

// 2007-06-28 by cmkwon, �߱� ��������(���� �ð� �˸� ����) - ��Ʈ�� �߰�
#define STRMSG_070628_0000				"���ۼ�����ʱ������%dСʱ."
#define STRMSG_070628_0001				"���ۼ�����ʱ������%dСʱ.����������Ϣ,���ʵ�����."
#define STRMSG_070628_0002				"���Ѿ�����ƣ����Ϸʱ��.������Ϸ���潫��Ϊ����ֵ��50%%.Ϊ�����Ľ���,�뾡��������Ϣ,�ʵ��˶�,������ѧϰ����."
#define STRMSG_070628_0003				"���ѽ��벻������Ϸʱ��.Ϊ�����Ľ���,��������������Ϣ.�粻����,�������彫�ܵ���.������Ϸ�����ѽ�Ϊ��.ֱ�������ۼ�����ʱ����5Сʱ��,���ָܻ�����."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000				"\'%s\'���ǽ�ֹ���밢����״̬."
#define STRMSG_070711_0001				"\'%s\'�ǽ�ֹ���밢����״̬.(ʣ��ʱ��:%d����)"
#define STRMSG_070711_0002				"����%d����֮�ڽ�ֹ���밢����ϵͳ!!"
#define STRMSG_070711_0003				"���Ľ�ֹ���밢����״̬�ѽ��."
#define STRMSG_070711_0004				"\'%s\'�Ľ�ֹ���밢����״̬�ѽ��."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide �ػ� 1280x720(16:9) �߰� - ��Ʈ�� �߰�
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 ����(��)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 ����(��)"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��Ʈ�� �߰�
#define STRMSG_070830_0001				"ѡ������֮�����ʹ�ø�����."
#define STRMSG_070830_0002				"��������Ļ��鷿�� (%d)����Ч��"
#define STRMSG_070830_0003				"��ǰ���Խ���᳡������: %d��"
#define STRMSG_070830_0004				"'%s'ӵ�л��鷿���볡Ȩ��."
#define STRMSG_070830_0005				"'%s'û�л��鷿���볡Ȩ��."
#define STRMSG_070830_0006				"'%s'������Ч�Ľ�ɫ."
#define STRMSG_070830_0007				"�޷���'%s'��ӵ����鷿���볡Ȩ���б���.(��� %d��)"
#define STRMSG_070830_0008				"��'%s'�����˻��鷿���볡Ȩ��."
#define STRMSG_070830_0009				"������鷿���볡Ȩ��."
#define STRMSG_070830_0010				"������鷿���볡Ȩ��."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001				"\\y������%s %s����"
#define STRMSG_071115_0002				"��ƷĿ¼ : \'%s(%d��)\'"
#define STRMSG_071115_0003				"\\y%s���� %s %s���ߡ��뵽�ֿ�ȷ�ϡ�"
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001				"Ŀǰ��������ϵͳ����ʱ�䡣����ѯ�ͻ����������ġ�"
#define STRMSG_071120_0002				"����ϵͳ�ѿ��š�"
#define STRMSG_071120_0003				"����ϵͳ�ѹرա�"
#define STRMSG_071120_0004				"����ϵͳ����ʱ����%s��%s ��"

// 2007-11-28 by cmkwon, �����ý��� ���� - 
#define STRMSG_071128_0001				"%s����%s����%d�����뵽�ֿ�ȷ�ϡ�"

// 2007-12-27 by cmkwon, �������� ��� ��� �߰� - 
#define STRMSG_071228_0001				"�ֱ���������Ч�����������á�"

// 2008-01-31 by cmkwon, ���� ��/���� ��ɾ�� ������ �ý��� ���� - 
#define STRMSG_080201_0001				"��ͣ'%s'��������ErrorCode(%d)"
#define STRMSG_080201_0002				"�ɹ���ͣ'%s'��[Block End Date: %s]"
#define STRMSG_080201_0003				"'%s'�ʺŲ��ڷ�ͣ�б��У�ErrorCode(%d)"
#define STRMSG_080201_0004				"���'%s'�ʺŷ�������ErrorCode(%d)"
#define STRMSG_080201_0005				"�ɹ����'%s'�ʺ�"

// 2008-02-11 by cmkwon, �ػ� �߰�(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (��)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (��)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (��)"

// 2007-12-27 by dhjin, �Ʒ�������- �Ʒ�������������ÿ���
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), Can't connect to  ArenaServer[%15s:%4d] Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001 "�����Ӱ����ȷ�����.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002 "�밢���ȷ�����[%15s:%4d]�����жϣ����������ӡ�\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001		"\\y%d�ŵȴ������ѿ��������ɻ��\r\n"
#define STRMSG_ARENAEVENT_080310_0002		"\\y%d�ŷ�����ȡ�������ɻ��\r\n"
#define STRMSG_ARENAEVENT_080310_0003		"\\y���������ɻʧ�ܡ�\r\n"
#define STRMSG_080428_0001					"�ѻ���%s��"		// 2008-04-28 by dhjin, ��������� - ���ӻ���Է���ʾ�����ڰ����ɵ�ͼ��Ч

// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
#define STRMSG_080430_0001					"��ѡ��ķ��������ܴ����½�ɫ��"

// 2008-06-13 by dhjin, EP3 ���� ���� ���� - 
#define STRMSG_080613_0001					"%s���žܾ��������롣"

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRMSG_081230_0001 "\\y%s����%d�����ڱ����ԡ�\\y"
#define STRMSG_081230_0002 "\\y���������%d���ӡ�\\y"
#define STRMSG_081230_0003 "\\y���������ԡ�\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D ���Ӱ��� ����â ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - STRMSG_090831_0001�� ���������� ó��
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �ػ� �߰�(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 ����(��)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 ����(��)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 ����(��)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 ����(��)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ���� ������ ���� ��� ��Ȳ
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Not Registered Server (It can be Illegal Private Server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Error occurs during linkage with DB"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"Authentication succeed"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Registered Server IP But proceed Authentication Denied"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"Windows Shut Down command is sent to the server."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ��Ʈ�� - ���� �� ��Ʈ�� ��ɿ��� ���Ǵ� MSG
#define STRERR_S_SCADMINTOOL_0048 "This socket item is equiped with Partner. You can remove it from the property of partner equipped with \n socket."
#define STRERR_S_SCADMINTOOL_0049 "Saving the log about the changes of the property of partner is failed.\r\n(Change of the property of partner is complete, only log failed to be saved.)"
#define STRERR_S_SCADMINTOOL_0050 "The loading for partner information is failed."
#define STRERR_S_SCADMINTOOL_0051 "The equipped socket item is failed to be deleted."
#define STRERR_S_SCADMINTOOL_0052 "The applying hidden option for equipped item is failed."
#define STRERR_S_SCADMINTOOL_0053 "The revision for the Partner��s socket item is failed."
#define STRERR_S_SCADMINTOOL_0054 "The update information of partner is failed."
#define STRERR_S_SCADMINTOOL_0055 "The information loading for partner lever is failed."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, �������߰�, ��æƮ���������ű��
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, �������߰�, ��æƮ���������ű��. End

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 Ʈ���� �ý��� �̺�Ʈ �˸�

// 1�� �̺�Ʈ

#define STRMSG_120330_0001					"%s activates the warp gate to Hidden Place in Ash Lane."
#define STRMSG_120330_0002					"%s activates 100%%%% increase for monster EXP (1 hour) in Ash Lane."
#define STRMSG_120330_0003					"%s activates 100%%%% increase for item drop rate (1 hour) in Ash Lane."
#define STRMSG_120330_0004					"%s activates 100%%%% increase for item drop rate/monster EXP/SPI (1 hour) in Ash Lane."
#define STRMSG_120330_0005					"%s activates Weapon Shop in Ash Lane."
#define STRMSG_120330_0006					"%s activates Hyper Card shop in Ash Lane."
#define STRMSG_120330_0007					"%s activates Kit Shop in Ash Lane."
#define STRMSG_120330_0008					"%s summons a boss monster in Ash Lane!"
#define STRMSG_120330_0009					"Crystals have disappeared."

// 2�� �̺�Ʈ

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

#define STRMSG_120712_0001					"18�� �̸� û�ҳ⿡�� ����Ǵ� ���ӽð� ������ �������� ���Ͽ�, %d �� �Ŀ� ������ ����˴ϴ�."		// 2012-07-11 by hskim, ������ �˴ٿ�

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ������ �ð��� %d�� ���ҽ��ϴ�."
#define STRMSG_121005_0002					"\\y��� �� PC�� �������� ����˴ϴ�."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� �ý��� ������ - ����� Ʈ���� ��������(�Ͻ�����)
#define STRMSG_121126_0001					"\\yWar is in progress. Crystal Trigger system has been taken offline for the duration.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� ��������
#define STRMSG_121129_0001					"\\y��ڿ� ���Ͽ� �̵��� ���ѵ� ���� �Դϴ�.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC �������� Ʈ���� �ý���
#define STRMSG_130121_0001					"\\cNGC ���¿� ���� �ý����� ���� ���߽��ϴ�. ��� ��ȯ �ý����� ���� �մϴ�."
#define STRMSG_130121_0002					"\\c������ : ����� ���� Ȯ��."
#define STRMSG_130121_0003					"\\c������ : ����� �ı� Ȯ��."
#define STRMSG_130121_0004					"\\c��� : ���� �� ���α׷��� �����Ͽ��� ! ����⸦ �ı��Ͽ� �� ���α׷��� ��ȿȭ ���Ѷ� !"
#define STRMSG_130121_0005					"\\c��� : ������ ���� �ı��Ǿ���. ���� ���� !"
#define STRMSG_130121_0006					"\\c��� : ���� �ı��Ǿ���! ���� ���� !"
#define STRMSG_130121_0007					"\\c��� : ���� ���� �ı��ؾ� �Ѵ�."
#define STRMSG_130121_0008					"\\c������� �������� [%s\\c] ȿ���� �ߵ� �˴ϴ�."
#define STRMSG_130121_0009					"\\y[NGC �������� �ý���]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������ �̺�Ʈ - ����Ÿ�� �߰����� �ý��� ����
#define STRMSG_130422_0001					"\\y�Ʒ��� ������ �̿� �� �̹Ƿ� �̺�Ʈ ������ %s %d���� â��� ���޵Ǿ����ϴ�.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - STRMSG �߰�
#define STRMSG_130531_0001					"\\g[%s] ������ �Ƹ��÷��ǿ� ��� �Ǿ����ϴ�."
#define STRMSG_130531_0002					"\\g[%s] ������ [%2d]ȸ ���� �Ǿ����ϴ�."
#define STRMSG_130531_0003					"\\g[%s] ������ ���� Ƚ���� �ִ�ġ �̹Ƿ� [%s] ���������� ���� �Ǿ����ϴ�."
#define STRMSG_130531_0004					"���� ���� ���� ������ �Ⱓ�� ����Ǿ� ������ ���� �����Ǿ����ϴ�."
#define STRMSG_130531_0005					"\\y���� ���������� ���� ���÷� ��� ��ȯ �Ǿ����ϴ�."
#define STRMSG_130531_0006					"\\g�������� ������ �÷��� �������� ����Ҽ� �����ϴ�."
#define STRMSG_130531_0007					"\\g������ ���� �Ǿ����ϴ�."
#define STRMSG_130531_0008					"\\g[%s] ������ �Ⱓ�� ���� �Ǿ����ϴ�."
#define STRMSG_130531_0009					"\\y�÷¼��� ����� �������� ���Ż����� �Ǹ��� �� �����ϴ�."
#define STRMSG_130531_0010					"\\y��� Ÿ���� ���� �ʽ��ϴ�."

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
