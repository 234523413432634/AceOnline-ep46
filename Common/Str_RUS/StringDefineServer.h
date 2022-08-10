
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "������ �� ��������"
	#define STRERR_S_ATUMEXE_0002 "���������� ������� ��������!"
	#define STRERR_S_ATUMEXE_0003 "������ ��������������� ����������.\r\n�������������� ����.\r\n"
	#define STRERR_S_ATUMEXE_0004 "������ %s(%#04X) �������� �� %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "����������� ������: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "���������� � �������� �������� ����������."
	#define STRERR_S_ATUMEXE_0007 "������ ������������ ����� ����������."
	#define STRERR_S_ATUMEXE_0008 "���� ���������� �� ����� ���� ������."
	#define STRERR_S_ATUMEXE_0009 "�� ������� ������."
	#define STRERR_S_ATUMEXE_0010 "��������� .exe ����."
	#define STRERR_S_ATUMEXE_0011 "���� �� ������."
	#define STRERR_S_ATUMEXE_0012 "��������� ���� �� ������. "
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[������]����������� ��� ���������: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "���������� ���������"
	#define STRMSG_S_ATUMLAUNCHER_0001 "�������� ������"
	#define STRMSG_S_ATUMLAUNCHER_0002 "���������� ������ ��������� ������ v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "��������� ��������� �����"
	#define STRMSG_S_ATUMLAUNCHER_0004 "������� ����������"
	#define STRMSG_S_ATUMLAUNCHER_0005 "���������� ��������� (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "�������� ����������� ����"
	#define STRMSG_S_ATUMLAUNCHER_0007 "�������� ���������� ����"
	#define STRMSG_S_ATUMLAUNCHER_0008 "�������� ��������"
	#define STRMSG_S_ATUMLAUNCHER_0009 "�������� ���������"
	#define STRMSG_S_ATUMLAUNCHER_0010 "���������� �� ������ v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "���������� ������� ���� %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "���������� �� ������ v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "��������� ���������� � ����� %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[������] Parameter Count Error, Count (%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[������] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[������] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[������] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "���������� ����������� � Pre ��������"
	#define STRERR_S_ATUMLAUNCHER_0005 "���������� � �������� ��������"
	#define STRERR_S_ATUMLAUNCHER_0006 "���������� �������� Pre ��������!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "�������� ���� ��� ���.\nURL: http://aceonline.ru "
	#define STRERR_S_ATUMLAUNCHER_0009 "�������������� ���������� ��������.\r\n����������, �������������� ����.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "��� ������� ����������"
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s �����������..."
	#define STRERR_S_ATUMLAUNCHER_0012 "������� ����������. ���������� ����� � ���� �������."
	#define STRERR_S_ATUMLAUNCHER_0013 "������ %s(%#04X) �������� �� %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "�������� ���, ������ ������\n\n* ������ ����, �� �������� ����-��������, �������� ����� � ���� � ��������� ������."
//	#define STRERR_S_ATUMLAUNCHER_0014 "�� ����� �������� ��� ��� ������. ������� ������������������ ��� � ������."
	#define STRERR_S_ATUMLAUNCHER_0015 "������ �����"
	#define STRERR_S_ATUMLAUNCHER_0016 "��� ������������ �� �������"
	#define STRERR_S_ATUMLAUNCHER_0017 "������� ����"
	#define STRERR_S_ATUMLAUNCHER_0018 "Field c����� �� �������."
	#define STRERR_S_ATUMLAUNCHER_0019 "IM c����� �� �������."
	#define STRERR_S_ATUMLAUNCHER_0020 "������ ������� �������� ��������������.\n\n���������� ����� �������."
	#define STRERR_S_ATUMLAUNCHER_0021 "������ ����������.\n\n���������� ����� �������."
	#define STRERR_S_ATUMLAUNCHER_0022 "��� ������� ������������.\n ����: %s\n\n���������� �� ������ support.4game.ru, ��� ��������� ����� ��������� ����������."
	#define STRERR_S_ATUMLAUNCHER_0023 "�������� ������ �������.\n\n����������, �������� ���� ��� ���."
	#define STRERR_S_ATUMLAUNCHER_0024 "������: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "�� ������� ������������ � ������� ��������"
	#define STRERR_S_ATUMLAUNCHER_0026 "������ ������������ ����� (%s) ����������"
	#define STRERR_S_ATUMLAUNCHER_0027 "������ ������������ ����� ����������"
	#define STRERR_S_ATUMLAUNCHER_0028 "���������� ������� ���� ����������"
	#define STRERR_S_ATUMLAUNCHER_0029 "����������� ������ �� ����������"
	#define STRERR_S_ATUMLAUNCHER_0030 "������� ����������� ������. ���������� ����� �������."
	#define STRERR_S_ATUMLAUNCHER_0031 "�� ������� ������ ��� ��������� ��������"
	#define STRERR_S_ATUMLAUNCHER_0032 "�������� ���� .exe"
	#define STRERR_S_ATUMLAUNCHER_0033 "���� �� ������"
	#define STRERR_S_ATUMLAUNCHER_0034 "���������� �� �������"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[������] ������������ ��� ���������: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[������] ������������ ��� ���������!\n"

	#define STRMSG_S_050506		"������� ������ \'%s\' ������������.\n  �������: %s\n ����: %s~%s\n\n ���������� �� ������ http://support.4game.ru/ ��� ��������� ����� ��������� ����������."
	#define STRMSG_S_050930		"����������, �������� ���� ��� ���.\nURL: %s\n��������� ������: "
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "�������"
//	#define STRMSG_S_SCADMINTOOL_0001 "�������"
//	#define STRMSG_S_SCADMINTOOL_0002 "A.D%d, �������%d"
//	#define STRMSG_S_SCADMINTOOL_0003 "�� ������������� ������ �������� ���������� � ����� ��������?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + '������ ��������, ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''����: ' + l.PeerCharacterName + ''', ������ ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''����: ' + l.PeerCharacterName + ''', �������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
//	#define STRMSG_S_SCADMINTOOL_0008 "'''������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + '������ �������, �������� SPI: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + '������ �������, �������� SPI: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' ��������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' ������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0014 "'�������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������ , ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0015 "'����� ��������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, ����� ' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0016 "'�������� �� ��������� ' + CAST(l.ChangeCount AS VARCHAR(10)) + '������, �����' + CAST(l.CurrentCount AS VARCHAR(10)) + '������'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'������� ����� \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', ����� \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', ������� �����: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' ������ � ������, ����� \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "�������"
//	#define STRMSG_S_SCADMINTOOL_0021 "������"
//	#define STRMSG_S_SCADMINTOOL_0022 "�������"
//	#define STRMSG_S_SCADMINTOOL_0023 "������� ����������"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, �������� ����� : %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(�� ����������)"
//	#define STRMSG_S_SCADMINTOOL_0026 "����"
//	#define STRMSG_S_SCADMINTOOL_0027 "�� ����������"
//	#define STRMSG_S_SCADMINTOOL_0028 "��������"
	#define STRMSG_S_SCADMINTOOL_0029 "������� ������������"
	#define STRMSG_S_SCADMINTOOL_0030 "������� ���������"
//	#define STRMSG_S_SCADMINTOOL_0031 "��� ����������"
//	#define STRMSG_S_SCADMINTOOL_0032 "��� ������������"
//	#define STRMSG_S_SCADMINTOOL_0033 "��� ���������"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s ������"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s ������,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "������������"
//	#define STRMSG_S_SCADMINTOOL_0037 "�������������"
//	#define STRMSG_S_SCADMINTOOL_0038 "��������"
	#define STRMSG_S_SCADMINTOOL_0039 "�� ������ �������������� ������ �������?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d���.)"
	#define STRMSG_S_SCADMINTOOL_0041 "%dwin %dlost"
	#define STRMSG_S_SCADMINTOOL_0042 "�� ������������� ������ ����� � ������������� �������?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s �������"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] ���������� : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "���-�� ������������� : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] �������� ��������� : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] ���-�� ������������� : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] ��������� FieldServer : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "����� � �������� �������\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "���������� ��������� ���������� �� ��������."
	#define STRERR_S_SCADMINTOOL_0001 "�� ������� �������� ���������� �� ��������."
	#define STRERR_S_SCADMINTOOL_0002 "������� ������"
	#define STRERR_S_SCADMINTOOL_0003 "������ �������"
	#define STRERR_S_SCADMINTOOL_0004 "������� �����"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server ����������"
	#define STRERR_S_SCADMINTOOL_0006 "���������� ����������� � PreServer!"
//	#define STRERR_S_SCADMINTOOL_0007 "������ �����������"			// 2006-04-11 by cmkwon, �ּ�ó����
	#define STRERR_S_SCADMINTOOL_0008 "������: ���������� �������� �� ������."
	#define STRERR_S_SCADMINTOOL_0009 "������� ��� ������������"
	#define STRERR_S_SCADMINTOOL_0010 "������� �������"
	#define STRERR_S_SCADMINTOOL_0011 "������ ������������� ����� : ������� %2d ==> ����(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "������������ ������ ���� ��������.\r\n\r\n�������� ������������ ������ ���� ��� ������� ������."
	#define STRERR_S_SCADMINTOOL_0013 "���������� ������������ � ���� ������"
	#define STRERR_S_SCADMINTOOL_0014 "��� ����������"
	#define STRERR_S_SCADMINTOOL_0015 "���� ����������"
	#define STRERR_S_SCADMINTOOL_0016 "���� ����������"
	#define STRERR_S_SCADMINTOOL_0017 "�����������"
	#define STRERR_S_SCADMINTOOL_0018 "����� ���������"
	#define STRERR_S_SCADMINTOOL_0019 "� ����"
	#define STRERR_S_SCADMINTOOL_0020 "����������"
	#define STRERR_S_SCADMINTOOL_0021 "���� ������ %s(%s:%d)�� ����� ���� ����������"
	#define STRERR_S_SCADMINTOOL_0022 "�� ������� �������� �������"
	#define STRERR_S_SCADMINTOOL_0023 "�� ������� ����� ��������������� �������"
	#define STRERR_S_SCADMINTOOL_0024 "���������� ������������� �������, ����� �������� ���!"
	#define STRERR_S_SCADMINTOOL_0025 "SPI(������) ���������� ��������."
	#define STRERR_S_SCADMINTOOL_0026 "��������� ������� ��� ����������, ������� ����������."
	#define STRERR_S_SCADMINTOOL_0027 "�� ������� ����� �������"
	#define STRERR_S_SCADMINTOOL_0028 "SPI(������), ������������ �������, ������ �������."
	#define STRERR_S_SCADMINTOOL_0029 "�� ������ ������� ���� �������?"
	#define STRERR_S_SCADMINTOOL_0030 "�� ������� ������� �������"
	#define STRERR_S_SCADMINTOOL_0031 "�� ������� �������������� �������"
	#define STRERR_S_SCADMINTOOL_0032 "������� �������"
	#define STRERR_S_SCADMINTOOL_0033 "������� �� ���������� (��������, �� ������������)"
	#define STRERR_S_SCADMINTOOL_0034 "������� ��� �������� �� ����������"
	#define STRERR_S_SCADMINTOOL_0035 "������ ��� ������ ���������� � ���������."
	#define STRERR_S_SCADMINTOOL_0036 "�������� �� ������"
	#define STRERR_S_SCADMINTOOL_0037 "������ ��� ���������� ���������"
	#define STRERR_S_SCADMINTOOL_0038 "���������� � ��������� ������� ���������"
	#define STRERR_S_SCADMINTOOL_0039 "�������� �������"
	#define STRERR_S_SCADMINTOOL_0040 "�������� ���-�� ���������"
	#define STRERR_S_SCADMINTOOL_0041 "����� ������� �� ����� 5 ��. ��������."
	#define STRERR_S_SCADMINTOOL_0042 "������� ���������"
	#define STRERR_S_SCADMINTOOL_0043 "���������� �� ����� ���� ����������"
	#define STRERR_S_SCADMINTOOL_0044 "%s: ��������� ������� (%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server �� ��������."
	#define STRERR_S_SCADMINTOOL_0046 "Field Server �� ��������."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] ��������� IMServer : %d\r\n"
	#define STRERR_S_SCADMINTOOL_0048 "��Ʈ�ʿ� ������ ���� ������ �Դϴ�.\n������ ������ ��Ʈ�� �Ӽ�â���� ������ �����մϴ�."
	#define STRERR_S_SCADMINTOOL_0049 "��Ʈ�ʼӼ� ������� Log������ ���� �Ǿ����ϴ�.\r\n(��Ʈ�� �Ӽ� ������ �Ϸ��, Log�� ���� ����.)"
	#define STRERR_S_SCADMINTOOL_0050 "��Ʈ�� ���� �ε��� ���� �Ǿ����ϴ�"
	#define STRERR_S_SCADMINTOOL_0051 "�������� ���� ������ ������ ���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0052 "������ ���� �������� ���̵� �ɼ� ������ ���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0053 "��Ʈ�� ���� �������� ������ ���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0054 "��Ʈ�� ���� ������Ʈ�� ���� �Ǿ����ϴ�"
	#define STRERR_S_SCADMINTOOL_0055 "��Ʈ�ʷ��� ���� �ε��� ���еǾ����ϴ�"

	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "��� ��������"
//	#define STRMSG_S_SCAT_COLNAME_0001 "���"
//	#define STRMSG_S_SCAT_COLNAME_0002 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0003 "���� ������"
//	#define STRMSG_S_SCAT_COLNAME_0004 "���� ���������"
//	#define STRMSG_S_SCAT_COLNAME_0005 "�������������"
//	#define STRMSG_S_SCAT_COLNAME_0006 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0007 "����"
//	#define STRMSG_S_SCAT_COLNAME_0008 "��� ����"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IP"
//	#define STRMSG_S_SCAT_COLNAME_0010 "��� �������"
//	#define STRMSG_S_SCAT_COLNAME_0011 "��� ���������"
//	#define STRMSG_S_SCAT_COLNAME_0012 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0013 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0014 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "������ �����"
//	#define STRMSG_S_SCAT_COLNAME_0017 "���"
//	#define STRMSG_S_SCAT_COLNAME_0018 "����� ��������"
//	#define STRMSG_S_SCAT_COLNAME_0019 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0020 "�������"
	#define STRMSG_S_SCAT_COLNAME_0021 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0022 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0023 "����� ��������"
//	#define STRMSG_S_SCAT_COLNAME_0024 "����� ��������"
	#define STRMSG_S_SCAT_COLNAME_0025 "�� ����������"
//	#define STRMSG_S_SCAT_COLNAME_0026 "�����"
//	#define STRMSG_S_SCAT_COLNAME_0027 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0028 "�����"
//	#define STRMSG_S_SCAT_COLNAME_0029 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0030 "���"
//	#define STRMSG_S_SCAT_COLNAME_0031 "����"
//	#define STRMSG_S_SCAT_COLNAME_0032 "���������"
//	#define STRMSG_S_SCAT_COLNAME_0033 "��� �������"
//	#define STRMSG_S_SCAT_COLNAME_0034 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0035 "������������ �������"
//	#define STRMSG_S_SCAT_COLNAME_0036 "����"
//	#define STRMSG_S_SCAT_COLNAME_0037 "���������� ���� �����"
//	#define STRMSG_S_SCAT_COLNAME_0038 "��� ����������������� ����������"
//	#define STRMSG_S_SCAT_COLNAME_0039 "�����"
//	#define STRMSG_S_SCAT_COLNAME_0040 "������"
//	#define STRMSG_S_SCAT_COLNAME_0041 "�������"
//	#define STRMSG_S_SCAT_COLNAME_0042 "���"
//	#define STRMSG_S_SCAT_COLNAME_0043 "���"
//	#define STRMSG_S_SCAT_COLNAME_0044 "��������"
//	#define STRMSG_S_SCAT_COLNAME_0045 "��������������"
//	#define STRMSG_S_SCAT_COLNAME_0046 "�����"
//	#define STRMSG_S_SCAT_COLNAME_0047 "���������� ���������"
//	#define STRMSG_S_SCAT_COLNAME_0048 "����� ����� ����������"
//	#define STRMSG_S_SCAT_COLNAME_0049 "����� ��������"
//	#define STRMSG_S_SCAT_COLNAME_0050 "��������� ���"
//	#define STRMSG_S_SCAT_COLNAME_0051 "���"
//	#define STRMSG_S_SCAT_COLNAME_0052 "�����"
	#define STRMSG_S_SCAT_COLNAME_0053 "����(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0054 "������(1-1type)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "�������(1-1type)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "�����(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0057 "��������(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0058 "�������(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0059 "�������� ���������(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0060 "��������������(1-2type)"
	#define STRMSG_S_SCAT_COLNAME_0061 "������(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0062 "���������� ������(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0063 "���������(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0064 "����(2-1type)"
	#define STRMSG_S_SCAT_COLNAME_0065 "���(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0066 "�������(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0067 "���������(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0068 "�������(2-2type)"
	#define STRMSG_S_SCAT_COLNAME_0069 "������"
	#define STRMSG_S_SCAT_COLNAME_0070 "���������"
	#define STRMSG_S_SCAT_COLNAME_0071 "�������"
	#define STRMSG_S_SCAT_COLNAME_0072 "������"
	#define STRMSG_S_SCAT_COLNAME_0073 "��������"
	#define STRMSG_S_SCAT_COLNAME_0074 "���������"
	#define STRMSG_S_SCAT_COLNAME_0075 "����"
	#define STRMSG_S_SCAT_COLNAME_0076 "����"
	#define STRMSG_S_SCAT_COLNAME_0077 "�����"
	#define STRMSG_S_SCAT_COLNAME_0078 "�����"
	#define STRMSG_S_SCAT_COLNAME_0079 "���������"
	#define STRMSG_S_SCAT_COLNAME_0080 "��������"
	#define STRMSG_S_SCAT_COLNAME_0081 "�������������� ����������"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "�������"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "���������"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "��� ����"
//	#define STRMSG_S_SCAT_COLNAME_0082 "���� ������"
//	#define STRMSG_S_SCAT_COLNAME_0083 "��� �������"
//	#define STRMSG_S_SCAT_COLNAME_0084 "��� �������"
//	#define STRMSG_S_SCAT_COLNAME_0085 "IP �������, ����"
//	#define STRMSG_S_SCAT_COLNAME_0086 "������� ���-�� �������������"
//	#define STRMSG_S_SCAT_COLNAME_0087 "��������� �������"
//	#define STRMSG_S_SCAT_COLNAME_0088 "������ ��������"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Field server"
//	#define STRMSG_S_SCAT_COLNAME_0090 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0091 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0092 "����������"
//	#define STRMSG_S_SCAT_COLNAME_0093 "������������"
	#define STRMSG_S_SCAT_COLNAME_0094 "�������������"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '������, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "������ ������\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- ������ �������� ��������� ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  �������: \'%s\', ��������� ������: \'%s\', ��������� ������: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  �������: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "������� ���������� � ������������."
//	#define STRMSG_S_SCMONITOR_0005 "\r\n�������� ������ �� %s � %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "������������� ������ ��������"
//	#define STRMSG_S_SCMONITOR_0007 "���� ������� ������.\r\n\r\nDB ����������: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  �������) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -���������) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "������ � ������� ������� ���������"
//	#define STRMSG_S_SCMONITOR_0011 "������� ���������� ��������� �����"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  �������)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -���������)"
//	#define STRMSG_S_SCMONITOR_0014 "���������� ������ ���������� ������ ������!"
//	#define STRMSG_S_SCMONITOR_0015 "���������� ������ ��������������� ��������� ������!"
//	#define STRMSG_S_SCMONITOR_0016 "������������ ���������� ������� �������� ��������������."
//	#define STRMSG_S_SCMONITOR_0017 "��������� ������ �������."
//	#define STRMSG_S_SCMONITOR_0018 "������� ������ ����������."
//	#define STRMSG_S_SCMONITOR_0019 "�� ������������� ������ ������� ������� ������?"
//	#define STRMSG_S_SCMONITOR_0020 "���������� � ������ ���������� (�������� 1492 ������)\r\n\r\n    ������ ������[%3d], ������������ ������[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "�� ������������� ������ ������� ������ Pre?"
//	#define STRMSG_S_SCMONITOR_0022 "�� ������������� ������ ������� ������ IM?"
//	#define STRMSG_S_SCMONITOR_0023 "�� ������������� ������ ������� ������ NPC?"
//	#define STRMSG_S_SCMONITOR_0024 "%Y��� %m����� %d���� %H��� %M������ %S�������"
//	#define STRMSG_S_SCMONITOR_0025 "��� �������(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "������� ������� ������� � ����(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "�� ����� �������(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "���������� ����� ��� ��������� ����� �� �������"
//	#define STRMSG_S_SCMONITOR_0029 "����������� ����� ��� ��������� ����� �� �������"
//	#define STRMSG_S_SCMONITOR_0030 "������� �������"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> �������� �������.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> ������� �� �������.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "���������� ���������� � ����� ������."
//	#define STRERR_S_SCMONITOR_0003 "������ �� ����������"
//	#define STRERR_S_SCMONITOR_0004 "������� ��� �����, ������� ������ ����������"
//	#define STRERR_S_SCMONITOR_0005 "������� ��� �����, ������� ������ �����������"
//	#define STRERR_S_SCMONITOR_0006 "������� ��������� ������"
//	#define STRERR_S_SCMONITOR_0007 "������� ��������� ������"
//	#define STRERR_S_SCMONITOR_0008 "�������� ����, ���� ����������� zip ����� � �����������"
//	#define STRERR_S_SCMONITOR_0009 "���� �� �����������"
//	#define STRERR_S_SCMONITOR_0010 "�������� ������!"
//	#define STRERR_S_SCMONITOR_0011 "���������� ����������� � ����� ������"
//	#define STRERR_S_SCMONITOR_0012 "[������]���������� ������� ��� ���������: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "������� ����� ���������� �� ����������.(����� ������[%3d], ������������� ������[%4dBytes])\r\n\r\n    ����� ����������� ������ ������."
//	#define STRERR_S_SCMONITOR_0014 "��������� �������.\r\n����������� ���������� ���������."
//	#define STRERR_S_SCMONITOR_0015 "��� �� ����� ������"
//	#define STRERR_S_SCMONITOR_0016 "�� �� ������ ������� ������ EDIT."
//	#define STRERR_S_SCMONITOR_0017 "�� ���������������� ��� ��������� ����."

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[������] WndProc(), ���������� ���������� ���������� � LogServer[%15s:%4d] ������� ���������� ����������.\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "����������� � Log Server ���������.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "���������� � Log Server[%15s:%4d] �������. ������� ���������� ����������.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[������] WndProc(),���������� ���������� ���������� � PreServer[%15s:%4d] ������� ���������� ����������.\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "����������� � Pre Server ���������.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) �������� �� %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "����������� Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "���������� � Pre Server[%15s:%4d] �������. ������� ���������� ����������.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[������] WndProc(),���������� ���������� ���������� � IMServer[%15s:%4d] ������� ���������� ����������.\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "����������� � IM Server ���������.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "���������� � IM Server[%15s:%4d] �������. ������� ���������� ����������.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) �������� �� %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "����������� Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "�������������� ������ � ���� ������ Field Server! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "������ ������� �� ����������."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' ����� ������. ��������� �������"
	#define STRMSG_S_F2DBQUERY_0003 "�����. �������, F5 ����� ��������� ���������."
	#define STRMSG_S_F2DBQUERY_0004 "����� %s(%d)��������"
	#define STRMSG_S_F2DBQUERY_0005 "������ ������� �� ����������."
	#define STRMSG_S_F2DBQUERY_0006 "�� ������� �������� �������."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "������ ����� �� �������� ��� �������: %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "��������� �������: GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "����� � ��������� �� �������� ��� �������: %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "����� ���� ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "����� �� �������� ��� �������: %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) ����� �����(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[������] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "����� %d���., \"%s\" �������� ����� �� �������� ��� �������."
	#define STRMSG_S_F2CITYWAR_0007 "����� %d���., \"%s\" ���������� ����� �� �������� ��� �������."
	#define STRMSG_S_F2CITYWAR_0008 "������ ������ ��� ����� �� �������� ��� �������(%s) : ��� ��������� NPC"
	#define STRMSG_S_F2CITYWAR_0009 "������ ������ ��� ����� �� �������� ��� �������(%s) : ��� ��������� ������� %s "
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"�� ������ ������ ������������ \"%s\"."
	#define STRMSG_S_F2CITYWAR_0011 "������� \"%s\" �� ������ ������ ��������� \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "�� �������� ��������� �������"
	#define STRMSG_S_F2QUEST_0001 "������� �� ���� ���������.\r\n"
//	#define STRMSG_S_F2QUEST_0002 "������� \'%30s\' ����� %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "������ ������� ��� ��������! \r\n\r\nLoadFieldServerDataDebug() ���������� ���������! "
	#define STRMSG_S_F2NOTIFY_0000 "����� �������� %d: %d �� %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "����� �������� �������� %d: %s �� %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1� ���"
	#define STRMSG_S_F2NOTIFY_0003 "2� ���"
	#define STRMSG_S_F2NOTIFY_0004 "���1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "���2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "�������� ��� ������! ���������� � ��������������!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1���: %4.1f vs %4.1f -> �������� ��������� �� %2.2f%% "
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s ������, ��������(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s ������, ��������(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s ������, ��������(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2���: %4.1f ������ %4.1f -> ���� �������� �� %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, ������� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, �������� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), ������� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, �������� %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "������: �������� ����� > %d"
	#define STRMSG_S_F2NOTIFY_0017 "��������: [%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "���������� � �������� �� ����������. ���������� � ��������������."
	#define STRMSG_S_F2NOTIFY_0019 "���������� � ������� �������� �� ����������. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "���������� � ��������. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "�� ����� ������ ����������� ����������."
	#define STRMSG_S_F2NOTIFY_0022 "�� ����� ������ ����������� ����������."
	#define STRMSG_S_F2NOTIFY_0023 "�� ����� ����� ����� �������� ����������� ����������."
	#define STRMSG_S_F2NOTIFY_0024 "������ �������� �����! ���������� � ��������������!"
	#define STRMSG_S_F2NOTIFY_0025 "������ �������� �����! ���������� � ��������������! ���������� ����������� %d, %d �������!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "�� ����� ����� ����� �������� ����������� ����������."
	#define STRMSG_S_F2NOTIFY_0027 "�����������(%04d) ����������: Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> �������� %10s ,�������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> ��������r %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> �������� %10s ,�������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> ������ %3d ,������� ���� %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> ������ %3d ,�������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> �������� %10s , ������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> �������� %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> ������ %10s ,������� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "������������� ���������� ������ �������"
	#define STRMSG_S_F2NOTIFY_0042 "���������� ������������, ����� �������� �����."
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO �� ����������"
	#define STRMSG_S_F2NOTIFY_0044 "��������� �������"
	#define STRMSG_S_F2NOTIFY_0045 "��������� �� �������"
	#define STRMSG_S_F2NOTIFY_0046 "�� ����������� �������"
	#define STRMSG_S_F2NOTIFY_0047 "��� � ������ ��������"
	#define STRMSG_S_F2NOTIFY_0048 "����������, ���������� �������."
	#define STRMSG_S_F2NOTIFY_0049 "�� ��� ���-�� ������ �������� ���������� �������"
	#define STRMSG_S_F2NOTIFY_0050 "��� � ����� ������"
	#define STRMSG_S_F2NOTIFY_0051 "�� ��� ��������� ������ ��������� �� ����� �����."
	#define STRMSG_S_F2NOTIFY_0052 "�� ��� ����� ����� ��������� �� ����� �����."
	#define STRMSG_S_F2NOTIFY_0053 "�� ��� ����� ����� ��������� �� ����� �����."
	#define STRMSG_S_F2NOTIFY_0054 "�� �� �������� � �������"
	#define STRMSG_S_F2NOTIFY_0055 "������ ������������� � �������"
	#define STRMSG_S_F2NOTIFY_0056 "�� ��, �� ������ �������� �� ��������� ����������� �������."
	#define STRMSG_S_F2NOTIFY_0057 "�� ��� ��������� ������ ��������� �� ����� �����."
	#define STRMSG_S_F2NOTIFY_0058 "�� �� �������� � �������"
	#define STRMSG_S_F2NOTIFY_0059 "���������� �� �������������"
	#define STRMSG_S_F2NOTIFY_0060 "�� ��, �� ������ �������� �� ��������� ����������� �������."
	#define STRMSG_S_F2NOTIFY_0061 "�������� ������ ������!"
	#define STRMSG_S_F2NOTIFY_0062 "������ ������. ����������, �������� ��������������."
	#define STRMSG_S_F2NOTIFY_0063 "������ ������� (%s) �� �������� ��� ���� �������."
	#define STRMSG_S_F2NOTIFY_0064 "��������� ������ ������"
	#define STRMSG_S_F2NOTIFY_0065 "����������� �������: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "������������ ����������� ��������: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "�����(%d) ������ � Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "���������� �� ������ �� ����� �����������! �������� ��������������!"
	#define STRMSG_S_F2NOTIFY_0069 "��������� ���� ����������� �� ����������"
	#define STRMSG_S_F2NOTIFY_0070 "������ ������������ ��������. ����������, ���������� � ��������������."
	#define STRMSG_S_F2NOTIFY_0071 "������� ������, ������� �� ������ ����������, ���� ������ ��� ����� ���."
	#define STRMSG_S_F2NOTIFY_0072 "������ ��������. ���������� ������."
	#define STRMSG_S_F2NOTIFY_0073 "������ ������� ��������. �������� ��������������."
	#define STRMSG_S_F2NOTIFY_0074 "������ ������� ��������. �������� ��������������."
	#define STRMSG_S_F2NOTIFY_0075 "\'4Game ������� \'������."
	#define STRMSG_S_F2NOTIFY_0076 "������ ������� : \'%s(%d��.)\'"
	#define STRMSG_S_F2NOTIFY_0077 "��� ������������� � �����."
	#define STRMSG_S_F2NOTIFY_0078 "���������� ��������������, ���� �� � �������� �����."
	#define STRMSG_S_F2NOTIFY_0079 "���������� �������������� �� ����� ����� ����� ��������"
	#define STRMSG_S_F2NOTIFY_0080 "�������� ���� ���������� � ������ ����� �� ������������!"
	#define STRMSG_S_F2NOTIFY_0081 "�������� ���������� �� ������ �����! �������� ��������������!!!"
	#define STRMSG_S_F2NOTIFY_0082 "� ������ ��������� ���������� �����������."
	#define STRMSG_S_F2NOTIFY_0083 "%s � ���������� ��������."
	#define STRMSG_S_F2NOTIFY_0084 "��������� ���������� ������������: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "������������: "
	#define STRMSG_S_F2NOTIFY_0086 "����� ������� �������� 20 �������."
	#define STRMSG_S_F2NOTIFY_0087 "������ ������������ (%s) �� ����������"
	#define STRMSG_S_F2NOTIFY_0088 "�� ����������� �����"
	#define STRMSG_S_F2NOTIFY_0089 "������� �����: %d:%d, ����� �����: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "����� �����: %d:%d, ����� �����: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "��� ���������� � NPC server"
	#define STRMSG_S_F2NOTIFY_0092 "������ ������� (%d) �� ����������!"
	#define STRMSG_S_F2NOTIFY_0093 "����� � 10 ��., ���� ������� �� �������� ��������������"
	#define STRMSG_S_F2NOTIFY_0094 "����� \'%s\' 's ����� ��������������: %d ���."
	#define STRMSG_S_F2NOTIFY_0095 "����� %s %s ������������ ����������: %d ���. - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "����� %s %s ������������ ����������: %d ���. - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "������� ����� �����: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "���������� � �������� �� ����������. �������� ��������������."
	#define STRMSG_S_F2NOTIFY_0099 "���������� � ������� �������� �� ����������. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "���������� � �������� �� ����������. �������� ��������������."
	#define STRMSG_S_F2NOTIFY_0101 "���������� � ������� �������� �� ����������. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "������������(%s)�� ����������"
	#define STRMSG_S_F2NOTIFY_0103 "������������(%s)�����"
	#define STRMSG_S_F2NOTIFY_0104 "������������(%s)�� ����������!"
	#define STRMSG_S_F2NOTIFY_0105 "������� ����������� ���������"
	#define STRMSG_S_F2NOTIFY_0106 "����������� ������� �������"
	#define STRMSG_S_F2NOTIFY_0107 "������������ ��������"
	#define STRMSG_S_F2NOTIFY_0108 "������������ ���������"
	#define STRMSG_S_F2NOTIFY_0109 "���� ������ ��������� �� %5.0f%% "
	#define STRMSG_S_F2NOTIFY_0110 "������ ��� ��������� ��������� ��������"
	#define STRMSG_S_F2NOTIFY_0111 "������ ��� ��������� ��������� ��������"
	#define STRMSG_S_F2NOTIFY_0112 "������ ������������(%s)�� ����������"
	#define STRMSG_S_F2NOTIFY_0113 "����������� ���������"
	#define STRMSG_S_F2NOTIFY_0114 "����������� ��������"
	#define STRMSG_S_F2NOTIFY_0115 "����� %s �� ����"
	#define STRMSG_S_F2NOTIFY_0116 "������� ����� %s (����������:%4.2f, ����� ������: %3d���.)"
	#define STRMSG_S_F2NOTIFY_0117 "������� ����������� ������� ���������"
	#define STRMSG_S_F2NOTIFY_0118 "�� ������� ������� ������� ���������"
	#define STRMSG_S_F2NOTIFY_0119 "������� ����� ������� ���������"
	#define STRMSG_S_F2NOTIFY_0120 "��� �� ����� ��� ����� �� �������� ��� �������"
	#define STRMSG_S_F2NOTIFY_0121 "���������� ������ ����� �� �������� ��� �������"
	#define STRMSG_S_F2NOTIFY_0122 "���������� ��������� ����� �� �������� ��� �������"
	#define STRMSG_S_F2NOTIFY_0123 "�����-����� ��������"
	#define STRMSG_S_F2NOTIFY_0124 "�����-����� �����������"
	#define STRMSG_S_F2NOTIFY_0125 "����� ����������"
	#define STRMSG_S_F2NOTIFY_0126 "���������� ����� \\a���������� ���\\a [�����:%4d���.)]"
	#define STRMSG_S_F2NOTIFY_0127 "����� \\a���������� ���\\a ��������"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> ������ %3d, ����� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "1type -> ������ %3d, ����� ���� %5.2f"
	#define STRMSG_S_F2NOTIFY_0130 "�������� ���� � ������������ %s"
	#define STRMSG_S_F2NOTIFY_0131 "�� ���������� ���������� ��������� %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "������@CharacterGameEndRoutine(): �� ������� ���������� ������ ������ �����! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "������� \'%s\' ����: %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "������� \'%s\' ����: %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: ����������!"
	#define STRMSG_S_F2NOTIFY_0136 "����������� ������: �������� ��������������! ������ ���������� ���������� �������!"
	#define STRMSG_S_F2NOTIFY_0137 "������� %s ��� ������."
	#define STRMSG_S_F2NOTIFY_0138 "�����, �� ������� �� ����������, � ������ ������ ��������, ������� ������� � ������ ������� ����������"
	#define STRMSG_S_F2NOTIFY_0139 "����������. �������������� ������ �������."
	#define STRMSG_S_F2NOTIFY_0140 "������ �����������.[%s,%2d��.]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "��������� ������� %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "������������������ HP �����������"
	#define STRMSG_S_F2NOTIFY_0143 "������������������ HP �����������, �.�. ��� ������������ ��� ������� ����."
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f ���������� ��������������."
	#define STRMSG_S_F2NOTIFY_0145 "����������� ���� HP ����������(��������: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "����������� ���� DP ����������(��������: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "����������� ���� EP ����������(��������: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s - ����� ��������."
	#define STRMSG_S_F2NOTIFY_0149 "%s - ����� �������� (���������� %4.2f, ��������:%3d���.)"
	#define STRMSG_S_F2NOTIFY_0150 "������� �� ���� ���������."
	#define STRMSG_S_F2NOTIFY_0151 "\\cYour last connection was at: \\c\\y%s\\y"
	#define STRMSG_S_F2NOTIFY_0152 "\\cYour gear was created on the: \\c\\y%s\\y"
	#define STRMSG_S_F2NOTIFY_0153 "\\cYou played \\y%u Day(s) %u Hour(s) %u Minute(s)\\y and \\y%u Seconds(s)\\y until now!\\c"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "������ ������������� ����� �����(%s, %s(%d)): f����� ����(%d) < 0.0f ��� ������ ������: %d, ���������(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "��������� �� ������ ��� ������ ���� ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "��������� �� ������ ��� ������ ���� ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "�����������(%04d) ���������� ��������� � ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "�������� ���������� �� ������ �����! �������� ��������������! ���������(%s, %s, %04d), ����(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "�����������(%d) ���������� ��������� � T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "�������� ���������� �� ������ �����! �������� ��������������! ���������(%s, %s, %04d), ����(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "����������� ���������� ��������� � T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "�����(%d) ��������� ����������(�������� �����) � Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "�����������(%04d) ���������� ��������� � Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "�����(%d) ���������� ��������� � Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "����������� ���������� ��������� � T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "������ ������ �� ������: %s -> ����������: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "�����������(%04d) ���������� ��������� � Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> ������ �� ������������� ������ ��!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "����� �� ��������.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "�����������(%s) ���������� ��������� � HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "�����������(%s) ���������� ��������� � HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "����������� ������: ��� ��������� ������ ���������� ������� �������� �������, � �������� ��� �� ���������. ���������\r\n"
	#define STRERR_S_F2NOTIFY_0019 "�����������(%04d) ���������� ��������� �  T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "�����������(%s) ���������� ��������� �  T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "����"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "�������������� �����"
	#define STRMSG_S_F2EVENTTYPE_0003 "��������� ���������"
	#define STRMSG_S_F2EVENTTYPE_0004 "��������� ������ ���������"
	#define STRMSG_S_F2EVENTTYPE_0005 "����������� �����"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "�������� ���� �� Pre Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "���������� � Pre Server[%15s:%4d]��������. ��������� ����������.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' ��� ����������."
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' ��� � �������."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' ��� ��� ������ ������ ��������."
	#define STRMSG_S_I2NOTIFY_0003 "������ �������� ������� - �������� ��������������!"
	#define STRMSG_S_I2NOTIFY_0004 "��� ���� '%s' ����� � ����"
	#define STRMSG_S_I2NOTIFY_0005 "�������� ����������� �����"
	#define STRMSG_S_I2NOTIFY_0006 "����������� ����� �� ����������"
	#define STRMSG_S_I2NOTIFY_0007 "����� ������������� � �����"
	#define STRMSG_S_I2NOTIFY_0008 "� ��� ��� ���� �����, � �������� �� ��������������."
	#define STRMSG_S_I2NOTIFY_0009 "����������� ������: ����������� ������ �����! � T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "�������� ��������� ������� �����"
	#define STRMSG_S_I2NOTIFY_0011 "����� ����� ��� �������� � �������"
	#define STRMSG_S_I2NOTIFY_0012 "��� ������� � �������"
	#define STRMSG_S_I2NOTIFY_0013 "�� �� ������ ���������� ������ ����"
	#define STRMSG_S_I2NOTIFY_0014 "�� ���������� � ���������, ����� ���������� �������� � �������."
	#define STRMSG_S_I2NOTIFY_0015 "�� ��������� ����� ������ �������, ������� ����� ��������������."
	#define STRMSG_S_I2NOTIFY_0016 "�� ���������� � ���������, ����� ���������� �������� � �������."
	#define STRMSG_S_I2NOTIFY_0017 "�������� ������ �� ����� �������� �������"
	#define STRMSG_S_I2NOTIFY_0018 "������ �������� ������� �� ����� ����� ����� ���������"
	#define STRMSG_S_I2NOTIFY_0019 "������ ��������� �� ������� �� ����� ����� ����� ���������"
	#define STRMSG_S_I2NOTIFY_0020 "��������� ������� ������ ���������"
	#define STRMSG_S_I2NOTIFY_0021 "�� ����� ����� ����� ��������� ������ �������������� �������"
	#define STRMSG_S_I2NOTIFY_0022 "������ �������� ��� �� ����� ��"
	#define STRMSG_S_I2NOTIFY_0023 "������ ������ �������� �������� �������"
	#define STRMSG_S_I2NOTIFY_0024 "������ ������ �������� ���� �������"
	#define STRMSG_S_I2NOTIFY_0025 "������ ������ �������� ����"
	#define STRMSG_S_I2NOTIFY_0026 "���������� �����"
	#define STRMSG_S_I2NOTIFY_0027 "���������� ��������� ����� ��������� �������"
	#define STRMSG_S_I2NOTIFY_0028 "��������� � ����� ��������� ������� ����������."
	#define STRMSG_S_I2NOTIFY_0029 "���-�� �������: %d���. (�������� �������� %d���.)"
	#define STRMSG_S_I2NOTIFY_0030 "�������� � ������ ��������� ��������������"
	#define STRMSG_S_I2NOTIFY_0031 "������ �� ������ ��������� �������������"
	#define STRMSG_S_I2NOTIFY_0032 "IP �������: %s"
	#define STRMSG_S_I2NOTIFY_0033 "������ ������� \'%s\' ����� ���������� �������: %d���."
	#define STRMSG_S_I2NOTIFY_0034 "�� ������������� ������ ������� ������(%s)? �����: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'�� � ����. "
	#define STRMSG_S_I2NOTIFY_0036 "����� �������: %d���. (�������� �������� %d���.)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "���������������� ������ �� ����������."
	#define STRMSG_S_I2NOTIFY_0039 "������������ ��������� ��������������!"
	#define STRMSG_S_I2NOTIFY_0040 "������������ ��������� �������������!"
	#define STRMSG_S_I2NOTIFY_0041 "�� ������� � �������"
	#define STRMSG_S_I2NOTIFY_0042 "�������(%d) ����������"
	#define STRMSG_S_I2NOTIFY_0043 "������(%s)�� ����������"
	#define STRMSG_S_I2NOTIFY_0044 "�������� Field Server"
	#define STRMSG_S_I2NOTIFY_0045 "�����(%s) �� ����������"
	#define STRMSG_S_I2NOTIFY_0046 "�� �� ������ ������������ ��� %d!���."
	#define STRMSG_S_I2NOTIFY_0047 "���������� ����: '%10s', %3d���."
	#define STRMSG_S_I2NOTIFY_0048 "������� ���������� ���� ��������"
	#define STRMSG_S_I2NOTIFY_0049 "���������� ���� ��������: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(�������: %s, �����: %d(%d), ��.: %d) ������"
	#define STRMSG_S_I2NOTIFY_0051 "������ �������� ������ ����"
	#define STRMSG_S_I2NOTIFY_0052 "������ ������� �� ����������"

	#define STRMSG_S_IMSERVER_050607_0001	"������ ����� �� ����������."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "����� �� field Server.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "���������� � field Server [%15s:%4d]�������. ��������� �����������.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "�������� �� �������� ����� ��������� � ��������� �� ����������\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "������(%10s) ������ � ����� �� �������� ��� �������\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "���������"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "�������� ���� � %s ��������(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "�������"
	#define STRMSG_S_P2PRENOTIFY_0002 "�� �������"
	#define STRMSG_S_P2PRENOTIFY_0003 "[������] ������ � ���������� ���������� �� ��������, AccountName(%s)  privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"������������! ��� ������������ ������������� ���� �ce Online."
	#define STRMSG_SCAT_051115_0002		"�������� ���� ��������� �� ��������� ����������."
	#define STRMSG_SCAT_051115_0003		"������ ��� �������� ����."
	#define STRMSG_SCAT_051115_0004		"��������� ������, ����� 30 ����� ����� ����������� ������������ �������."
	#define STRMSG_SCAT_051115_0005		"��������� ������, ����� 20 ����� ����� ����������� ������������ �������."
	#define STRMSG_SCAT_051115_0006		"��������� ������, ����� 10 ����� ����� ����������� ������������ �������."
	#define STRMSG_SCAT_051115_0007		"��������� ������, ����� 5 ����� ����� ����������� ������������ �������." // 5�� �� ���� ������ ���� �����Դϴ�.
	#define STRMSG_SCAT_051115_0008		"������������� � ���������� ���� ������������ � ������� �� ����. "	// ������ 60�� ���� ������ �����Դϴ�


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"����� �����������: ������ �� ����� ���, � �� �� ������ ������������ ������."
	#define STRMSG_060509_0001			"����� ������������: �� �� ��������� �����."
	#define STRMSG_060509_0002			"�����-�����: ������� �� ����� ��������� ��� �������."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"��� ������ ��������� ���� �������. ����� ��� ���������� ������� ���, �� �������� � ����."
	#define	STRMSG_060526_0001			"�� ������� ������������� �������� ����.\r\n\r\n�������������� ���� � ������������ ����� ����(%s) � ���������� �������� ��� ���.\r\n\r\n    ������: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"������ ��� �� ���������� ��� ��� � ������ �� ���������."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"�� ������ ������ ������ ��������. ������� ����������� ������. ���������� � ������������ ����� ���� aceonline.ru ��� ��������� ����� ��������� ����������."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"�������� ������ �������.\r\n  ����������, �������������� ����."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"��� ���� ����� %s."
	#define STRMSG_061107_0001			"\\rWarning!\\g Crossfeeding will result in a ban.\\g"


	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"������������� ���� ������ ������� atum2_db_20 ������ ����������� ����� ���������� �������."
	#define STRMSG_070410_0001   	"�� ������������� ������ ������������� ������ atum2_db_20- [����� �������:%d]"
	#define STRMSG_070410_0002   	"���� ������ ������� atum2_db_20 ���������."
	#define STRMSG_070410_0003   	"���� ������ ������� atum2_db_20 �� ������� ���������!"
	#define STRMSG_070410_0004   	"'%s' ����������� ������ � ���� ������ ������� atum2_db_20 ���������."
	#define STRMSG_070410_0005   	"'%s' ����������� ������ � ���� ������ ������� atum2_db_20 �� ��������� - �������� �� ����������!"
	#define STRMSG_070410_0006   	"'%s' ����������� ������ � ���� ������ ������� atum2_db_20 �� ��������� - ������� ��������� �� ����������!"
	#define STRMSG_070410_0007   	"'%s' ����������� ������ � ���� ������ ������� atum2_db_20 �� ��������� - ������ ���������� � ����!"
	#define STRMSG_070410_0008   	"'%s' ����������� ������ � ���� ������ ������� atum2_db_20 �� ��������� - ����������� ������ (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, �ػ� ���ڿ� 
	// 2007-07-24 by cmkwon, ��ó���� 800*600 �ػ� ���� - �޺��ڽ� ��Ʈ�� �ʿ� ����
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (������)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (�������)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (�������)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (������)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (�������)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (�������)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (������ - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (������� - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (������� - ������� �����)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (������)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (�������)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (�������)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (������)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (�������)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (�������)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (������ - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (������� - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (������� - ������� �����)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (������)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (�������)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (�������)"

// 2007-06-15 by dhjin, ���� ���� ��Ʈ��
#define STRMSG_070615_0000		"���������� ������, �� �� � �����-������."
#define STRMSG_070615_0001		"���������� ������ ��������."
#define STRMSG_070620_0000	"����� �� ����� ������ ��������."

// 2007-06-26 by dhjin, ������Ʈ �̺�Ʈ ���� �߰�
#define STRMSG_S_F2EVENTTYPE_0006		"���� �����"

// 2007-06-28 by cmkwon, �߱� ��������(���� �ð� �˸� ����) - ��Ʈ�� �߰�
#define STRMSG_070628_0000				"�� � ���� ��� � ������� %d �."
#define STRMSG_070628_0001				"�� � ���� ��� %d �. ��� ����� ���������."
#define STRMSG_070628_0002				"�� ������� ������� �����. ��� ������ ��� ������ ��������. ������� �� ���� � �������. ��� ������� ����� ����� ������ � 2 ����. "
#define STRMSG_070628_0003				"��� ����-����, � �� ������ ������� �� �������� ��� ������. ���������� �������� ���� � ���������. ���� �� �� ���������� ������ ������, ��� ������� ����� �������� �� 0. ��� ������� ����� �������� � �������� ����� 5 ����� ����� ����, ��� �� ������� �� ����."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' �������� ���� �� �����."
#define STRMSG_070711_0001 "\'%s\' �������� ���� �� ����� (�������� �������: %d ���.)"
#define STRMSG_070711_0002 "��� �������� ���� �� ����� �� %d ���."
#define STRMSG_070711_0003 "������ ����� �� ����� ����."
#define STRMSG_070711_0004 "������������� ����� ��������� ������ \'%s\'."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide �ػ� 1280x720(16:9) �߰� - ��Ʈ�� �߰�
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (������ - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (������� - ������� �����)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (������� - ������� �����)"

// 2007-08-30 by cmkwon, ȸ�Ƿ� �ý��� ���� - ��Ʈ�� �߰�
#define STRMSG_070830_0001                                   "��� ������� ����� ������������ ������ ����� ����, ��� ������� �������."
#define STRMSG_070830_0002                                   "����� ���� ���������(%d) ������ ������� ����������"
#define STRMSG_070830_0003                                   "���-�� �������, ������� ����� ����� � ��� ��������� : %d���."
#define STRMSG_070830_0004                                   "'%s' ��� �������� � ������ �����������."
#define STRMSG_070830_0005                                   "'%s' �� ����� ���������� �� ����."
#define STRMSG_070830_0006                                   "'%s' ������������ ��� ���������."
#define STRMSG_070830_0007                                 "'%s' �� ����� ���� �������� � ������ ����������� ���� ���������.(�������� %d ���.)"
#define STRMSG_070830_0008                                   "'%s' ������� ����� ����� � ��� ���������."
#define STRMSG_070830_0009                                   "���������� ����� � ��� ��������� ��������."
#define STRMSG_070830_0010                                   "���������� ����� � ��� ��������� ��������."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y����� %s �������� ��� ������� - %s."
#define STRMSG_071115_0002									"������ ��������: \'%s(%d ��.)\'"
#define STRMSG_071115_0003									"\\y����� %s �������� ������� ������ %s.  ������� - %s. ��������� �����."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"������� ��������� �� ��������. �������������� ������� ��������� \\ysupport.4game.ru\\y"
#define STRMSG_071120_0002									"������� ��������� �������."
#define STRMSG_071120_0003									"������������� ������� ��������� ���������."
#define STRMSG_071120_0004									"������� ��������� �������� � %s �� %s."

// 2007-11-28 by cmkwon, �����ý��� ���� - 
#define STRMSG_071128_0001									"����� %s �������� ��� %s(%d) � �������� �������. ��������� ��� �����."

// 2007-12-27 by cmkwon, �������� ��� ��� �߰� - 
#define STRMSG_071228_0001				"�������� ����������. ��������� ��������� ��� ���."

// 2008-01-31 by cmkwon, ���� ����/���� ���ɾ�� ������ �ý��� ���� - 
#define STRMSG_080201_0001									"'������ � ���������� ���������� %s'. ErrorCode(%d)"
#define STRMSG_080201_0002									"'%s' - ������� ��� ������������.[Block End Date: %s]"
#define STRMSG_080201_0003									"'%s' - �������� ��� � ������ ���������������. ErrorCode(%d)"
#define STRMSG_080201_0004									"'��������� ������ � �������� ������������ �������� %s'. ErrorCode(%d)"
#define STRMSG_080201_0005									"'%s' - ������� ��� ������ �� ������ ���������������." 

// 2008-02-11 by cmkwon, �ػ� �߰�(1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (������)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (�������)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (�������)"

// 2007-12-27 by dhjin, �Ʒ�������- �Ʒ�������������ÿ���
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), ���������� ������������ � ������� ����� [%15s:%4d] ��������� ����������\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "����������� � ������� ����� ���������.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "����������� � ������� �����[%15s:%4d] �������. ������� ���������� ����������.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "  T_ERROR %s(%#04X) �������� �� %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Number \\y%d ������� �������� ����� ��� ��� ������� ������.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "Number \\y%d ������� �������� ����� �������� �������� ������.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y���������� ������ ������� �����.\r\n"
#define STRMSG_080428_0001					"%s ��� ����."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 
#define STRERR_S_ATUMLAUNCHER_0037			"18���� ��I���� A����O��a������O Au��e��C��A ��OAO��A�ơ� ����AAA| ����A��A����I AICI����, CoAc ��A�ơ̢�����A ��OAO A��CaAI ��O�Ƣ���ECO��I��U.\n\nAU����CN ��cC��A�� ����AI������A��oAI ��i�Ƣ�����AI��I ����AC��U�ҩ���I��U."
#define STRMSG_120712_0001					"18���� ��I���� A����O��a������O Au��e��C��A ��OAO��A�ơ� ����AAA| ����A��A����I AICI����, %d ���� EA���� ��OAOAI A����a��E��I��U."
#define STRMSG_130726_0001					"Character is already on that nation."
#define STRMSG_130726_0002					"Character is a Leader or Sub-leader, therefore cannot change nation."
#define STRMSG_130726_0003					"Character is in a Brigade; nation cannot be changed."
#define STRMSG_130726_0004					"There is no character left to change the nation."
#define STRMSG_130726_0005					"Changing nation failed [AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"Changing nation succesful [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define	STRMSG_130726_0007					"Account does not exist."
#define STRMSG_130726_0008					"Account is logged in, cannot change nation."
#define STRMSG_121126_0001					"\\yWar is in progress. Crystal Trigger system has been taken offline for the duration.\\y"
#define STRMSG_121129_0001					"\\y��i����AU���� ACCI���� AI�좯AI A|CN��E Ao���� AO��I��U.\\y"
#define STRMSG_S_F2NOTIFY_0130_1			"\\cWelcome to\\c \\mDreamACE\\m: \\g%s\\g"	

// 2013-08-30 by bckim, ?????????
#define STRMSG_130830_0001					"\\y%s flight privileges revoked by nation leader.\\y"
#define STRMSG_130830_0002					"\\yFlight privileges revoked by nation leader.\\y"
#define STRMSG_130830_0003					"\\yField movement of the user has been limited by the authority of the chairman.\\y"
// End. 2013-08-30 by bckim, ?????????

// 2013-08-28 by bckim, ????? ????
#define STRMSG_130828_0001					"\\y[%s has contributed in destroying \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s has initiated first strike against the \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s has made most attacks overall against the \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s has made final strike against the \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n has been defeated."
// End. 2013-08-28 by bckim, ????? ????

// 2A�� AI���ͨ���

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

// 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???
#define STRMSG_130814_0001					"\\y[%s] has won the NGC Strategic Point war.\\y"
// end 2013-08-14 by jhseol, ??? ??? - ???? GM ??? ???

// 2014-03-12 by bckim, ????(????)
#define STRMSG_130318_0001					"%s has summoned the boss monster in restricted area."
#define STRMSG_130318_0002					"%s has summoned the boss monster in city of ruins."
// End. 2014-03-12 by bckim, ????(????)

// // 2013-07-08 by jhseol, ���碬���A ��A����AU E��Aa - STRMSG A���Ƣ�
#define STRMSG_130708_0001					"\\cCommand:\\c NGC shields have been activated. Destroy the \\rNGC Controllers\\r to disable \\rGomora's\\r shields!"
#define STRMSG_130708_0002					"\\cCommand:\\c NGC Military Base defenses are down. Begin the attack!"
#define STRMSG_130708_0003					"\\cScouts:\\c \\rNGC Shield Generator\\r has been sighted."
#define STRMSG_130708_0004					"\\cScouts:\\c \\rNGC Shield Generator\\r has been destroyed."

// 2013-05-31 by jhseol,bckim ������O AA������C - STRMSG A���Ƣ�
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gContour has been added to your Contour Collection.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gContour has been applied [%2d] times.\\g"
#define STRMSG_130531_0003					"\\g[\\g%s\\g]\\g \\gContour has reached its maximum application. It has been changed to [%s].\\g"
#define STRMSG_130531_0004					"Your Contour has expired and stats have been removed. Your engine has been unequipped."
#define STRMSG_130531_0005					"\\yNo engine is equipped. Teleporting back to city.\\y"
#define STRMSG_130531_0006					"\\gYou cannot use the Contour currently applied to your armor.\\g"
#define STRMSG_130531_0007					"\\gContour has been changed.\\g"
#define STRMSG_130531_0008					"\\r[%s] Contour has expired.\\r"
#define STRMSG_130531_0009					"\\yArmors with Contours applied cannot be sold.\\y"
#define STRMSG_130531_0010					"\\yGEAR types do not match.\\y"

// 2013-01-21 by jhseol, NGC AuAu��aAo ���碬���A ��A����AU
#define STRMSG_130121_0001					"\\cSystem has been captured by NGC forces. Immediate evacuation has begun."
#define STRMSG_130121_0002					"\\cScouts:\\c \\rNGC Controller\\r has been confirmed."
#define STRMSG_130121_0003					"\\cScouts:\\c \\rNGC Controller\\r has been destroyed."
#define STRMSG_130121_0004					"\\cCommand:\\c \\rGomora's\\r shields are online. Destroy \\rNGC Controllers\\r to disable its shields!"
#define STRMSG_130121_0005					"\\cCommand:\\c \\rGomora's\\r shields are down! Attack now!"
#define STRMSG_130121_0006					"\\cCommand:\\c \\rGomora\\r has been destroyed! Everyone move forward!"
#define STRMSG_130121_0007					"\\cCommand:\\c \\rGomora\\r must be destroyed first."
#define STRMSG_130121_0008					"\\c[%s] activated by \\c\\rNGC Controller\\r overload."
#define STRMSG_130121_0009					"\\y[NGC Outpost Base System]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ??? ??? - ???? ???? ??? ??
#define STRMSG_130422_0001					"\\y%s %d is restricted from the Arena. The item has been sent to your warehouse.\\y"

///////////////////////////////////////////////////////////////////////////////

// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - 
#define STRMSG_080430_0001					"�� ��������� ������� �������� ����� ���������� ����������."

// 2008-06-13 by dhjin, EP3 ���� ���� ���� - 
#define STRMSG_080613_0001					"������ �� ���������� � ������� %s ��� ��������."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] ����������� ������� ���������(QP_xxx) ������� �� !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ä�� ���� ī�� ���� - 
#define STRMSG_081230_0001					"\\y��� ��������� %s ��� ������������ �� %d �����.\\y"
#define STRMSG_081230_0002					"\\y��� ��� ������������ ������� �� %d �����.\\y" 
#define STRMSG_081230_0003					"\\y���������� ���� ������� �����.\\y"
#define STRMSG_081230_0004					"Not enough Money for chatting. You need at least %d SPI to use this chat!"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D ���Ӱ��� ����â ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - ������� ����, STRMSG_090831_0001�� ���������� ó��
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����â WebPage�� ó�� - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �ػ� �߰�(1680x1050,1920x1080,1920x1200) - 
#define	STRMSG_WINDOW_DEGREE_1920x1440_HIGH			"1920x1440 (high)"
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (low)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (medium)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (high)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (low)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (medium)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (high)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (low)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (medium)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (high)"
#define STRMSG_WINDOW_DEGREE_3440x1440_LOW			"3440x1440 (low)"
#define STRMSG_WINDOW_DEGREE_3440x1440_MEDIUM		"3440x1440 (medium)"
#define STRMSG_WINDOW_DEGREE_3440x1440_HIGH			"3440x1440 (high)"
#define	STRMSG_WINDOW_DEGREE_2560x1440_HIGH			"2560x1440 (high)"
#define	STRMSG_WINDOW_DEGREE_2560x1080_HIGH			"2560x1080 (high)"
#define	STRMSG_WINDOW_DEGREE_3840x2160_HIGH			"3840x2160 (high)"
#define	STRMSG_WINDOW_DEGREE_5120x2160_HIGH			"5120x2160 (high)"


// Rovenia update
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER "������ �� ��������������� (��������, ��� ��������� ������)."	
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR "������ ��� ����� � ����� ������."	
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK "�� ������������."	
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED "IP ������� ���������������, �� � ������� ��������."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"������� ���������� ������ Windows ���������� �� ������."

// 2014-03-18 by bckim, ����AI ON/OFF
#define STRMSG_130318_0003					"\\yYou can't use the trade shop at the moment.\\y"
// End. 2014-03-18 by bckim, ����AI ON/OFF

#define STRMSG_KILL_0001					"%s has been shot down. Reward %d SPI %d WP"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 Ʈ���� �ý��� �̺�Ʈ �˸�
#define STRMSG_120330_0001					"%s�� �ֽ����ο��� ������ ���� ���� ����Ʈ�� �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0002					"%s�� �ֽ����ο��� ���� ����ġ 100%%%% ���� ���Ǿƿ� �̺�Ʈ(1�ð�)�� �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0003					"%s�� �ֽ����ο��� ������ ����� 100%%%% ���� ���Ǿƿ� �̺�Ʈ(1�ð�)�� �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0004					"%s�� �ֽ����ο��� ������ ����� 100%%%% / ���� ����ġ 100%%%% ���� / SPI�� 100%%%% ���� ���Ǿƿ� �̺�Ʈ(1�ð�)�� �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0005					"%s���� �ֽ����ο��� ���� ������ �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0006					"%s���� �ֽ����ο��� ������ ī�� ������ �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0007					"%s���� �ֽ����ο��� ŰƮ ������ �ߵ� �Ͽ����ϴ�."
#define STRMSG_120330_0008					"%s���� �ֽ����ο��� ���� ���͸� ��ȯ�ϼ̽��ϴ�."
#define STRMSG_120330_0009					"ũ����Ż�� �Ҹ��Ͽ����ϴ�."

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
